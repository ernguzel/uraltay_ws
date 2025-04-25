#ifndef ODOM_NODE_HPP
#define ODOM_NODE_HPP

#include <rclcpp/rclcpp.hpp>
#include <rclcpp/rclcpp.hpp>
#include "std_msgs/msg/float64_multi_array.hpp"
#include "rclcpp/subscription.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "tf2_ros/transform_broadcaster.h"
#include <sensor_msgs/msg/joint_state.hpp>


class OdomNode : public rclcpp::Node
{
public:
  // ROS 2'de NodeOptions kullanmak iyi bir pratiktir
  explicit OdomNode(const rclcpp::NodeOptions& options = rclcpp::NodeOptions());

private:
  void odomCallback(const nav_msgs::msg::Odometry::SharedPtr & msg);

  void jointCallback(const sensor_msgs::msg::JointState & msg);

  rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_sub_;
  rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub_;

  double wheel_radius_;
  double wheel_separation_;
  double left_wheel_prev_pos_;
  double right_wheel_prev_pos_;
  rclcpp::Time prev_time_;

  double x_;
  double y_;
  double theta_;

  nav_msgs::msg::Odometry odom_msg_;

  std::unique_ptr<tf2_ros::TransformBroadcaster> transform_broadcaster_;
  geometry_msgs::msg::TransformStamped transform_stamped_;

};

#endif // ODOM_NODE_HPP
