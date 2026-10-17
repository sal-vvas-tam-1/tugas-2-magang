#include <chrono>
#include <functional>
#include <memory>
#include <cmath>

#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

class Bunga : public rclcpp::Node
{
public:
  Bunga()
  : Node("Node_Bunga")
  {
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
    timer_ = this->create_wall_timer(
      5000ms, std::bind(&Bunga::timer_callback, this));
  }

private:
  int c = 0;
  void timer_callback()
  {
    geometry_msgs::msg::Twist msg;
    if(c %  2==0) {
    msg.linear.x = 2.0;   // maju 2 unit/detik
    msg.angular.z = 1.0 ; // putar kiri 1 rad/detik, radius = 2.0 / 1.0 = 2 unit
    publisher_->publish(msg);
    } else {
      msg.linear.x = 1.0;   // maju 2 unit/detik
      msg.angular.z = 3.0 ;
      publisher_->publish(msg);
    }
    c++;
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Bunga>());
  rclcpp::shutdown();
  return 0;
}