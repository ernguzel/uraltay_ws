#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from geometry_msgs.msg import Twist
from cv_bridge import CvBridge, CvBridgeError
import cv2
import numpy as np

# İzin servisi tanımı (interfaces/srv/Permission.srv)
# # Request
# string who
# ---
# # Response
# bool granted
from interfaces.srv import Permission


class LineFollower(Node):
    def __init__(self):
        super().__init__('line_follower')
        
        # Görüntü konusuna abone olma
        self.subscription = self.create_subscription(
            Image,
            '/camera/image_raw',
            self.image_callback,
            10)
        self.subscription  # unused variable uyarısını engellemek için
        
        # /cmd_vel konusuna Twist mesajlarını yayınlayacağımız publisher
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        
        # ROS2 ve OpenCV arasında dönüşüm için cv_bridge
        self.bridge = CvBridge()
        
        # Kontrol parametreleri
        self.kp = 0.005          # Hata için oransal kazanç
        self.linear_speed = 0.1  # Sabit doğrusal hız
        
        # Eşik değeri: siyah çizgiyi daha iyi algılamak için
        self.threshold_value = 90
        
        self.get_logger().info("Line Follower Node Başlatıldı!")
        
        # Permission service client (manager düğümünden izin alabilmek için)
        self.permission_client = self.create_client(Permission, 'permission_service')

    def request_permission(self, who, callback):
        """
        İzin almak için permission service'ine asenkron istek gönderir.
        callback, yanıt alındığında çalıştırılır.
        """
        if not self.permission_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().error("Permission service not available")
            callback(None)
            return
        req = Permission.Request()
        req.who = who
        future = self.permission_client.call_async(req)
        future.add_done_callback(lambda fut: callback(fut.result()))

    def image_callback(self, msg):
        try:
            # ROS2 görüntü mesajını OpenCV formatına çeviriyoruz
            cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        except CvBridgeError as e:
            self.get_logger().error("CvBridge Error: {}".format(e))
            return
        
        # Görüntüyü gri tonlamaya çevir
        gray = cv2.cvtColor(cv_image, cv2.COLOR_BGR2GRAY)
        
        # Siyah çizgi için eşikleme: THRESH_BINARY_INV ile, 
        # pixel değeri eşik değerden düşükse 255 (beyaz) olacak,
        # böylece siyah çizgi beyaz olur.
        ret, thresh = cv2.threshold(gray, self.threshold_value, 255, cv2.THRESH_BINARY_INV)
        
        # Görüntüdeki konturları bul
        contours, _ = cv2.findContours(thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        
        twist_msg = Twist()
        
        if contours:
            # En büyük konturu al (çizgi varsayımında)
            c = max(contours, key=cv2.contourArea)
            M = cv2.moments(c)
            if M['m00'] != 0:
                # Çizginin kütle merkezini hesapla
                cx = int(M['m10'] / M['m00'])
                cy = int(M['m01'] / M['m00'])
                
                height, width = thresh.shape
                error = cx - width // 2  # Görüntü merkezine göre yatay hata
                
                # Kontrol sinyalleri: sabit doğrusal hız ve hata oranında açısal hız
                twist_msg.linear.x = self.linear_speed
                twist_msg.angular.z = -self.kp * error  # Negatif işaret hata düzeltmesi için
                
                self.get_logger().info(
                    f"Centroid: ({cx}, {cy}), Hata: {error}, Cmd: lin={twist_msg.linear.x:.3f}, ang={twist_msg.angular.z:.3f}"
                )
                
                # Görselleştirme: çizgi ve merkez noktasını göster
                cv2.circle(cv_image, (cx, cy), 5, (0, 0, 255), -1)
                cv2.line(cv_image, (width // 2, height), (cx, cy), (255, 0, 0), 2)
            else:
                self.get_logger().info("Moment hesaplanamadı, durdum.")
        else:
            self.get_logger().info("Kontur bulunamadı, durdum.")
        
        # İzin isteği: "lane" modundan hesaplanan komut için izin alıyoruz
        self.request_permission('lane', lambda response: self.permission_callback(response, twist_msg))
        
        # Debug amaçlı görüntüleri göster (opsiyonel)
        cv2.imshow("Camera", cv_image)
        cv2.imshow("Thresh", thresh)
        cv2.waitKey(1)

    def permission_callback(self, response, twist_msg):
        """
        Permission service yanıtına göre /cmd_vel'e hız mesajı gönderilir.
        Eğer izin alınırsa, hesaplanan twist_msg yayınlanır.
        İzin alınamazsa, komut gönderilmez.
        """
        if response is not None and response.granted:
            self.cmd_vel_pub.publish(twist_msg)
            self.get_logger().info("Lane command granted, cmd_vel gönderildi.")
        else:
            self.get_logger().info("Lane command rejected, cmd_vel gönderilmedi.")

def main(args=None):
    rclpy.init(args=args)
    line_follower = LineFollower()
    try:
        rclpy.spin(line_follower)
    except KeyboardInterrupt:
        pass
    finally:
        cv2.destroyAllWindows()
        line_follower.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
