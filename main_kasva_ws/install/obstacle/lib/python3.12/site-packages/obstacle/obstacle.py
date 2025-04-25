#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist
import time
import math

# İzin servisi tanımı
# interfaces/srv/Permission.srv içeriği:
#   # Request
#   string who
#   ---
#   # Response
#   bool granted
from interfaces.srv import Permission


class ObstacleAvoidance(Node):
    def __init__(self):
        super().__init__('obstacle_avoidance')
        
        # Lidar verilerini dinlemek için /scan topic aboneliği
        self.subscription = self.create_subscription(
            LaserScan,
            'scan',
            self.scan_callback,
            10)
        
        # Hareket komutlarını göndermek için /cmd_vel topic publisher'ı
        self.publisher = self.create_publisher(Twist, 'cmd_vel', 10)
        
        # Engel tespitini kontrol etmek için değişkenler
        self.obstacle_detected = False
        self.threshold = 0.8  # Engel algılama mesafe eşiği (metre)
        
        # Engel yokken bu düğüm hiçbir Twist mesajı yayınlamayacak,
        # düz gitme (lane takip) başka modül tarafından gönderilecek.
        self.forward_speed = 0.2
        
        # Engel etrafından dönerken kullanılacak parametreler
        self.arc_radius = 1.2          # Yarıçap (metre)
        self.arc_linear_speed = 0.2     # İleri hız (m/s)
        self.arc_angle_deg = 180        # Dönüş açısı (180° = yarım daire)
        
        # Kaçış moduna girdiğimizi takip etmek için flag
        self.in_avoidance = False
        # Kaçış manevrası tamamlandığında bu flag True olacak,
        # ardından bir kere "none" isteği gönderilecek.
        self.avoidance_completed = False
        
        self.get_logger().info("Engelden kaçış düğümü başlatıldı")
        
        # Permission service client
        self.permission_client = self.create_client(Permission, 'permission_service')

    def scan_callback(self, msg):
        """
        Lidar verilerinin ön bölgesini kontrol eder;
        eğer mesafe eşikten düşükse, engel tespiti yapar.
        """
        front_angles = msg.ranges[len(msg.ranges)//3 : 2*len(msg.ranges)//3]
        if min(front_angles) < self.threshold:
            if not self.in_avoidance:  # Zaten kaçış modunda değilse tespit et
                self.obstacle_detected = True

    def request_permission(self, who, callback):
        """
        İzin almak için permission servisine asenkron istek gönderir.
        Servis çağrısı varsa, isteğin sonucunu callback fonksiyonu ile iletir.
        """
        if not self.permission_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().error("Permission service not available")
            callback(None)
            return
        req = Permission.Request()
        req.who = who
        future = self.permission_client.call_async(req)
        future.add_done_callback(lambda fut: callback(fut.result()))

    def publish_twist(self, linear_x, angular_z, duration):
        """
        Belirtilen süre boyunca lineer ve açısal hızları yayınlar,
        ardından robotu durdurur.
        """
        twist = Twist()
        twist.linear.x = linear_x
        twist.angular.z = angular_z
        end_time = time.time() + duration
        while time.time() < end_time and rclpy.ok():
            self.publisher.publish(twist)
            time.sleep(0.05)
        # Hareket tamamlandıktan sonra robotu durdur
        stop_twist = Twist()
        self.publisher.publish(stop_twist)

    def turn_in_place(self, angular_speed, angle_deg):
        """
        Robotu, bulunduğu yerde istenen açıda döndürür.
        Pozitif angular_speed sola, negatif ise sağa döndürür.
        """
        angle_rad = math.radians(angle_deg)
        duration = abs(angle_rad / angular_speed)
        self.publish_twist(0.0, angular_speed, duration)

    def arc_motion(self, radius, linear_speed, angle_deg, turn_left=True):
        """
        Belirtilen yarıçap ve açıyla robotu yay şeklinde hareket ettirir.
        """
        angle_rad = math.radians(angle_deg)
        arc_length = radius * angle_rad
        duration = arc_length / linear_speed
        angular_speed = linear_speed / radius
        if not turn_left:
            angular_speed = -angular_speed
        self.publish_twist(linear_speed, angular_speed, duration)

    def avoidance_sequence(self):
        """
        Engel tespit edilince çalışacak kaçış manevrası:
          1) Kısa süre dur
          2) 90° sağa dön
          3) 180°'lik yarıçaplı yay çiz (sola dönüş)
          4) 90° sağa dönerek orijinal yöne paralel hale gel
        """
        self.in_avoidance = True
        self.get_logger().info("Engel tespit edildi, kaçış manevrası başlatılıyor.")
        # 1) Kısa süre dur
        self.publish_twist(0.0, 0.0, 0.5)
        # 2) 90° sağa dön
        self.turn_in_place(-0.5, 90)
        # 3) 180°'lik yay çiz (sola dönüş)
        self.arc_motion(self.arc_radius, self.arc_linear_speed, self.arc_angle_deg, turn_left=True)
        # 4) Tekrar 90° sağa dön
        self.turn_in_place(-0.5, 90)
        self.get_logger().info("Kaçış manevrası tamamlandı.")
        # Kaçış tamamlandığında engel bayrağını sıfırla ve lane'e devret
        self.obstacle_detected = False
        self.in_avoidance = False
        # Kaçış tamamlandıktan sonra "none" isteği gönderilmeli
        self.avoidance_completed = True


def main(args=None):
    rclpy.init(args=args)
    node = ObstacleAvoidance()
    
    try:
        while rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.1)
            # Engel tespit edildiyse ve kaçış modunda değilse, obstacle isteği gönder.
            if node.obstacle_detected and not node.in_avoidance:
                node.get_logger().info("Engel tespit edildi, izin isteği gönderiliyor...")
                node.request_permission("obstacle", 
                    lambda response: node.avoidance_sequence() 
                        if response is not None and response.granted 
                        else node.get_logger().info("Permission rejected, lane takip devam ediyor.")
                )
            # Engel algılanmadı ama kaçış manevrası tamamlanmışsa,
            # yalnızca bir kere "none" isteği gönder.
            elif node.avoidance_completed:
                node.request_permission("none", 
                    lambda response: node.get_logger().info("No obstacle: control yielded to lane.")
                )
                node.avoidance_completed = False
            time.sleep(0.1)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
