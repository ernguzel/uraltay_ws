#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
# Custom servis: Permission
# string who
# ---
# bool granted
from interfaces.srv import Permission

class ManagerNode(Node):
    def __init__(self):
        super().__init__('manager_node')
        
        # Öncelikler: manuel > obstacle > lane
        self.priorities = {
            "manual": 3,
            "obstacle": 2,
            "lane": 1
        }
        
        # Şu an kontrolü hangi kaynak elinde?
        self.current_source = None
        self.current_priority = 0
        
        # Permission servis sunucusu
        self.permission_srv = self.create_service(
            Permission,
            'permission_service',
            self.permission_callback
        )
        
        self.get_logger().info("ManagerNode başlatıldı (sadece izin kontrolü yapıyor).")

    def permission_callback(self, request, response):
        """
        Farklı düğümlerden gelen istekleri değerlendirir.
        request.who -> "manual", "obstacle", "lane", "none"
        Eğer istek "none" ise, kontrolü serbest bırakır.
        """
        source = request.who

        # "none" isteği alındığında, kontrolü sıfırla.
        if source == "none":
            self.get_logger().info("[Manager] 'none' isteği alındı, kontrol serbest bırakılıyor.")
            self.current_source = None
            self.current_priority = 0
            response.granted = True
            return response
        
        # İstek yapanın önceliğini al
        priority = self.priorities.get(source, 0)
        
        # Yüksek veya eşit öncelikteyse kontrolü devral
        if priority >= self.current_priority:
            self.current_source = source
            self.current_priority = priority
            response.granted = True
            self.get_logger().info(
                f"[Manager] '{source}' (priority={priority}) kontrolü aldı."
            )
        else:
            # Daha düşük öncelikliyse reddet
            response.granted = False
            self.get_logger().info(
                f"[Manager] '{source}' (priority={priority}) isteği reddedildi. "
                f"Şu an '{self.current_source}' aktif (priority={self.current_priority})."
            )
        
        return response

def main(args=None):
    rclpy.init(args=args)
    node = ManagerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
