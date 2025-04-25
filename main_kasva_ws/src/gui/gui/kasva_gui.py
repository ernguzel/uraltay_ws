#!/usr/bin/env python3

import sys
import rclpy
from rclpy.node import Node

from sensor_msgs.msg import Image
from geometry_msgs.msg import Twist

from cv_bridge import CvBridge
import cv2
import os
import subprocess

from PyQt5.QtWidgets import (
    QApplication, QWidget, QLabel, QTextEdit, QPushButton,
    QGridLayout, QVBoxLayout, QHBoxLayout
)
from PyQt5.QtCore import Qt, QTimer, QPointF
from PyQt5.QtGui import (
    QPixmap, QImage, QPainter, QPainterPath,
    QColor
)

# İzin servisi tanımı
# Custom servis: Permission
# string who
# ---
# bool granted
from interfaces.srv import Permission


# --------------------------------------------
# Özel Buton Sınıfları
# --------------------------------------------
class TriangleButton(QPushButton):
    """
    Üçgen şeklinde bir buton çizer.
    direction: 'up', 'down', 'left', 'right'
    """
    def __init__(self, direction='up', parent=None):
        super().__init__(parent)
        self.direction = direction
        self.setFixedSize(60, 60)
        self.setStyleSheet("background-color: transparent; border: none;")

    def paintEvent(self, event):
        super().paintEvent(event)
        painter = QPainter(self)
        painter.setRenderHint(QPainter.Antialiasing)
        painter.setPen(Qt.NoPen)
        painter.setBrush(QColor(200, 200, 200))
        w = self.width()
        h = self.height()
        path = QPainterPath()
        if self.direction == 'up':
            path.moveTo(w / 2, 0)
            path.lineTo(0, h)
            path.lineTo(w, h)
        elif self.direction == 'down':
            path.moveTo(0, 0)
            path.lineTo(w, 0)
            path.lineTo(w / 2, h)
        elif self.direction == 'left':
            path.moveTo(0, h / 2)
            path.lineTo(w, 0)
            path.lineTo(w, h)
        elif self.direction == 'right':
            path.moveTo(0, 0)
            path.lineTo(w, h / 2)
            path.lineTo(0, h)
        path.closeSubpath()
        painter.drawPath(path)


class CircleButton(QPushButton):
    """
    Dairesel buton (örneğin Dur butonu).
    """
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setFixedSize(60, 60)
        self.setStyleSheet("background-color: transparent; border: none;")
    
    def paintEvent(self, event):
        super().paintEvent(event)
        painter = QPainter(self)
        painter.setRenderHint(QPainter.Antialiasing)
        painter.setPen(Qt.NoPen)
        painter.setBrush(QColor(255, 0, 0))
        w = self.width()
        h = self.height()
        r = min(w, h) / 2.0
        painter.drawEllipse(QPointF(w/2, h/2), r, r)


# --------------------------------------------
# ROS Node (GUI ile birlikte çalışan)
# --------------------------------------------
class RosNode(Node):
    """
    ROS2 Node: Kamera görüntüsünü alır, /cmd_vel yayınlar ve permission servisine istek gönderir.
    """
    def __init__(self):
        super().__init__('pyqt_ros_node')
        self.image_sub = self.create_subscription(
            Image,
            '/camera/image_raw',
            self.camera_callback,
            10
        )
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.bridge = CvBridge()
        self.latest_qimage = None
        self.log_messages = []
        self.get_logger().info("ROS Node Başlatıldı.")
        self.permission_client = self.create_client(Permission, 'permission_service')
    
    def camera_callback(self, msg):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        except Exception as e:
            self.get_logger().error(f"CvBridge Error: {e}")
            return
        height, width, channel = cv_image.shape
        bytes_per_line = channel * width
        qt_image = QImage(cv_image.data, width, height, bytes_per_line, QImage.Format_BGR888)
        self.latest_qimage = qt_image

    def publish_cmd_vel(self, linear, angular):
        twist = Twist()
        twist.linear.x = float(linear)
        twist.angular.z = float(angular)
        self.cmd_vel_pub.publish(twist)
        self.add_log_message(f"Publish: linear={linear:.2f}, angular={angular:.2f}")

    def add_log_message(self, text):
        self.log_messages.append(text)
        self.get_logger().info(text)

    def request_permission(self, who, callback):
        if not self.permission_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().error("Permission service not available")
            return
        req = Permission.Request()
        req.who = who
        future = self.permission_client.call_async(req)
        future.add_done_callback(lambda fut: callback(fut.result()))


# --------------------------------------------
# PyQt Ana Pencere
# --------------------------------------------
class MainWindow(QWidget):
    """
    GUI:
      - Sol Üst: Kamera
      - Sağ Üst: Log
      - Sol Alt: Manuel kontrol (üçgen/daire şeklinde)
      - Sağ Alt: Yalnızca Otonom Başla butonu
    """
    def __init__(self, node: RosNode):
        super().__init__()
        self.node = node
        self.setWindowTitle("Kasva GUI - PyQt5 & ROS2")
        main_layout = QGridLayout()
        self.setLayout(main_layout)
        
        # Sol Üst: Kamera Görüntüsü
        self.camera_label = QLabel("Kamera Görüntüsü")
        self.camera_label.setFixedSize(640, 360)
        self.camera_label.setStyleSheet("background-color: #808080;")
        main_layout.addWidget(self.camera_label, 0, 0)
        
        # Sağ Üst: Log Ekranı
        self.log_text = QTextEdit()
        self.log_text.setReadOnly(True)
        main_layout.addWidget(self.log_text, 0, 1)
        
        # Sol Alt: Manuel Kontrol Butonları (üçgen/daire şeklinde)
        manual_control_widget = self.create_manual_control_widget()
        main_layout.addWidget(manual_control_widget, 1, 0)
        
        # Sağ Alt: Yalnızca Otonom Başla Butonu
        autonomy_widget = self.create_autonomy_widget()
        main_layout.addWidget(autonomy_widget, 1, 1)
        
        self.update_timer = QTimer()
        self.update_timer.timeout.connect(self.update_gui)
        self.update_timer.start(100)
        
        # Otonom mod sürecinin kontrolü için değişken
        self.autonomy_process = None

    def create_manual_control_widget(self):
        layout = QGridLayout()
        self.up_button = TriangleButton('up')
        self.up_button.clicked.connect(lambda: self.send_manual_cmd(0.2, 0.0))
        layout.addWidget(self.up_button, 0, 1)
        self.down_button = TriangleButton('down')
        self.down_button.clicked.connect(lambda: self.send_manual_cmd(-0.2, 0.0))
        layout.addWidget(self.down_button, 2, 1)
        self.left_button = TriangleButton('left')
        self.left_button.clicked.connect(lambda: self.send_manual_cmd(0.0, 0.5))
        layout.addWidget(self.left_button, 1, 0)
        self.right_button = TriangleButton('right')
        self.right_button.clicked.connect(lambda: self.send_manual_cmd(0.0, -0.5))
        layout.addWidget(self.right_button, 1, 2)
        self.stop_button = CircleButton()
        self.stop_button.clicked.connect(lambda: self.send_manual_cmd(0.0, 0.0))
        layout.addWidget(self.stop_button, 1, 1)
        widget = QWidget()
        widget.setLayout(layout)
        return widget

    def create_autonomy_widget(self):
        layout = QVBoxLayout()
        self.autonomy_start_button = QPushButton("Otonom Başla")
        self.autonomy_start_button.clicked.connect(self.on_autonomy_start)
        layout.addWidget(self.autonomy_start_button)
        widget = QWidget()
        widget.setLayout(layout)
        return widget

    def send_manual_cmd(self, linear, angular):
        self.node.request_permission(
            'manual',
            lambda response: self.handle_manual_response(response, linear, angular)
        )

    def handle_manual_response(self, response, linear, angular):
        if response is not None and response.granted:
            self.node.publish_cmd_vel(linear, angular)
            self.node.add_log_message(f"Manual command granted: {linear}, {angular}")
        else:
            self.node.add_log_message("Manual command rejected by manager.")

    # Otonom Başla: Sadece lane takibi çalıştırılır.
    def on_autonomy_start(self):
        if self.autonomy_process is None:
            try:
                self.autonomy_process = subprocess.Popen(
                    ["ros2", "run", "img_pro", "line_folower"]
                )
                self.node.add_log_message("Otonom mod başladı: line_follower process başlatıldı.")
            except Exception as e:
                self.node.add_log_message(f"Otonom mod başlatılamadı: {e}")
        else:
            self.node.add_log_message("Otonom mod zaten çalışıyor.")

    def update_gui(self):
        if self.node.latest_qimage is not None:
            pixmap = QPixmap.fromImage(self.node.latest_qimage)
            self.camera_label.setPixmap(pixmap.scaled(
                self.camera_label.width(),
                self.camera_label.height(),
                Qt.KeepAspectRatio
            ))
        while self.node.log_messages:
            msg = self.node.log_messages.pop(0)
            self.log_text.append(msg)


def main(args=None):
    rclpy.init(args=args)
    ros_node = RosNode()
    app = QApplication(sys.argv)
    main_window = MainWindow(ros_node)
    main_window.show()
    ros_spin_timer = QTimer()
    ros_spin_timer.timeout.connect(lambda: rclpy.spin_once(ros_node, timeout_sec=0.001))
    ros_spin_timer.start(50)
    try:
        app.exec_()
    finally:
        ros_node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
