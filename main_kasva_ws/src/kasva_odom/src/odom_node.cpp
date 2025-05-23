#include "kasva_odom/odom_node.hpp"
#include <tf2/LinearMath/Quaternion.h>

using std::placeholders::_1;

OdomNode::OdomNode(const rclcpp::NodeOptions& options)
  : Node("odom_node", options)
  , left_wheel_prev_pos_(0.0)
  , right_wheel_prev_pos_(0.0)
  , x_(0.0)
  , y_(0.0)
  , theta_(0.0)
{

  // this->set_parameter(rclcpp::Parameter("use_sim_time", true));

  RCLCPP_INFO(this->get_logger(), "OdomNode constructor is called!");
  wheel_radius_ = 0.033;
  wheel_separation_ = 0.297;
  prev_time_ = get_clock()->now();
  joint_sub_ = create_subscription<sensor_msgs::msg::JointState>("/joint_states",10,std::bind(&OdomNode::jointCallback,this,_1));
  odom_pub_ = create_publisher<nav_msgs::msg::Odometry>("/odom",10);
  
  odom_msg_.header.frame_id = "odom";
  odom_msg_.child_frame_id = "base_link";
  odom_msg_.pose.pose.orientation.x = 0.0;
  odom_msg_.pose.pose.orientation.y = 0.0;
  odom_msg_.pose.pose.orientation.z = 0.0;
  odom_msg_.pose.pose.orientation.w = 1.0;

  transform_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(this);
  transform_stamped_.header.frame_id = "odom";
  transform_stamped_.child_frame_id = "base_link";

}

void OdomNode::jointCallback(const sensor_msgs::msg::JointState & msg)
{
  double dp_left = msg.position.at(0) - left_wheel_prev_pos_;
  double dp_right = msg.position.at(1) - right_wheel_prev_pos_;
  
  rclcpp::Time msg_time = msg.header.stamp;
  rclcpp::Duration dt = msg_time - prev_time_;

  left_wheel_prev_pos_ = msg.position.at(0);
  right_wheel_prev_pos_ = msg.position.at(1);
  prev_time_ = msg_time;

  double fi_left = dp_left / dt.seconds();
  double fi_right = dp_right / dt.seconds();

  double linear = (wheel_radius_ * fi_right + wheel_radius_ * fi_left) / 2;
  double angular = (wheel_radius_ * fi_right - wheel_radius_ * fi_left) / wheel_separation_;

  double d_s = (wheel_radius_ * dp_right + wheel_radius_ * dp_left) / 2;
  double d_theta = (wheel_radius_ * dp_right - wheel_radius_ * dp_left) / wheel_separation_;

  theta_ += d_theta;
  x_ += d_s * cos(theta_);
  y_ += d_s * sin(theta_);

  tf2::Quaternion q;
  q.setRPY(0,0,theta_);
  odom_msg_.pose.pose.orientation.x = q.x();
  odom_msg_.pose.pose.orientation.y = q.y();
  odom_msg_.pose.pose.orientation.z = q.z();
  odom_msg_.pose.pose.orientation.w = q.w();
  odom_msg_.header.stamp = get_clock()->now();
  odom_msg_.pose.pose.position.x = x_;
  odom_msg_.pose.pose.position.y = y_;
  odom_msg_.twist.twist.linear.x = linear;
  odom_msg_.twist.twist.angular.z = angular;

  transform_stamped_.transform.translation.x = x_;
  transform_stamped_.transform.translation.y = y_;
  transform_stamped_.transform.rotation.x = q.x();
  transform_stamped_.transform.rotation.y = q.y();
  transform_stamped_.transform.rotation.z = q.z();
  transform_stamped_.transform.rotation.w = q.w();
  transform_stamped_.header.stamp = get_clock()->now();


  odom_pub_->publish(odom_msg_);
  transform_broadcaster_->sendTransform(transform_stamped_);


}


// main fonksiyonu
int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<OdomNode>());
  rclcpp::shutdown();
  return 0;
}
