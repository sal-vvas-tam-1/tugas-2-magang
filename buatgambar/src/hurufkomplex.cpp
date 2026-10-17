#include <chrono>
#include <functional>
#include <memory>
#include <cmath>

#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

class hurufkomplex : public rclcpp::Node
{
public:
  hurufkomplex()
  : Node("Node_hurufkomplex")
  {
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
    timer_ = this->create_wall_timer(
      10ms, std::bind(&hurufkomplex::timer_callback, this));
  }

private:
  double t = 0;
  double beziertoturtlelinear(double X1,double X2, double Y1, double Y2, double T) {
    double x0,x1,x2,y0,y1,y2,xa,xb,ya,yb;
    int time;
    double Time;
    Time = T;
    time = T;
    Time -= time;
    x0 = 0;
    x1 = X1;
    x2 = X2;
    y0 = 0;
    y1 = Y1;
    y2 = Y2;
    xa = x1 - x0;
    xb = x2 - x1;
    ya = y1 - y0;
    yb = y2 - y1;
    double dx, dy;
    
    dx = 2 * (1 - Time) * xa + 2 * Time * xb;
    dy = 2 * (1 - Time) * ya + 2 * Time * yb;
    
    double speed;
    
    speed = sqrt((dx * dx) + (dy*dy));
    return speed;
  }
  double beziertoturtleang(double X1,double X2, double Y1, double Y2, double T) {
    double x0,x1,x2,y0,y1,y2,xa,xb,ya,yb;
    int time;
    double Time;
    Time = T;
    time = T;
    Time -= time;
    
    x0 = 0;
    x1 = X1;
    x2 = X2;
    y0 = 0;
    y1 = Y1;
    y2 = Y2;
    xa = x1 - x0;
    xb = x2 - x1;
    ya = y1 - y0;
    yb = y2 - y1;
    double dx, dy, ddx, ddy;
    
    dx = 2 * (1 - Time) * xa + 2 * Time * xb;
    dy = 2 * (1 - Time) * ya + 2 * Time * yb;
    ddx = 2 * (xb - xa);
    ddy = 2 * (yb - ya);
    double dtheta;
    dtheta = ((dx * ddy) - (dy * ddx)) / ((dx * dx) + (dy*dy));
    
    return dtheta;
  }
  void timer_callback()
  {
    geometry_msgs::msg::Twist msg;
    
    if(t < 1) {
    
    msg.linear.x = beziertoturtlelinear(1.5, 0, 0.5, 1.3, t);   // maju 2 unit/detik
    msg.angular.z = beziertoturtleang(1.5, 0, 0.5, 1.3, t); // putar kiri 1 rad/detik, radius = 2.0 / 1.0 = 2 unit
    publisher_->publish(msg);
    } else if(t < 2) {
     msg.linear.x = beziertoturtlelinear(1.9, 0, -1.3, -2, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(1.9, 0, -1.3, -2, t);
    publisher_->publish(msg);
    }else if(t < 3) {
     msg.linear.x = beziertoturtlelinear(0.4, 1, 2, 0.1, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(0.4, 1, 2, 0.1, t);
    publisher_->publish(msg);
    }else if(t < 4) {
     msg.linear.x = beziertoturtlelinear(1.3, 2, 0.3, 0.0, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(1.3, 2, 0.3, 0.0, t);
    publisher_->publish(msg);
    }else if(t < 6) {
    msg.linear.x = 0.8;   // maju 2 unit/detik
      msg.angular.z = 0.0 ;
      publisher_->publish(msg); 
    }else if(t < 7) {
     msg.linear.x = beziertoturtlelinear(0.2, 0.01, 0.1, 0.2, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(0.2, 0.01, 0.1, 0.2, t);
    publisher_->publish(msg);
    }else if(t < 8) {
     msg.linear.x = beziertoturtlelinear(-0.2, -0.4, 0.05, -0.3, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(-0.2, -0.4, 0.05, -0.3, t);
    publisher_->publish(msg);
    //}else if(t < 9) {
    // msg.linear.x = beziertoturtlelinear(0.3, 1.0, -0.7, -1.0, t);   // maju 2 unit/detik
    // msg.angular.z = beziertoturtleang(0.3, 1.0, -0.7, -1.0, t);
    //publisher_->publish(msg);
    
    
    }else if(t < 9) {
     msg.linear.x = beziertoturtlelinear(0.3, 1.0, -0.7, -1.0, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(0.3, 1.0, -0.7, -1.0, t);
    publisher_->publish(msg);
    }else if(t < 10) {
     msg.linear.x = beziertoturtlelinear(-0.7, -1.0, 0.55, 0.0, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(-0.7, -1.0, 0.55, 0.0, t);
    publisher_->publish(msg);
    }else if(t < 11) {
     msg.linear.x = beziertoturtlelinear(0.6, 0.4, 0.1, 1.8, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(0.6, 0.4, 0.1, 1.8, t);
    publisher_->publish(msg);
    }else if(t < 12) {
     msg.linear.x = beziertoturtlelinear(0.5, -0.4, 0.15, -0.4, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(0.5, -0.4, 0.15, -0.4, t);
    publisher_->publish(msg);
    }else if(t < 13) {
     msg.linear.x = beziertoturtlelinear(1.5, 0.0, 0.5, 1.0, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(1.5, 0.0, 0.5, 1.0, t);
    publisher_->publish(msg);
    }else if(t < 14) {
     msg.linear.x = beziertoturtlelinear(0.4, 1.4, -0.15, 0.0, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(0.4, 1.4, -0.15, 0.0, t);
    publisher_->publish(msg);
    }else if(t < 15) {
     msg.linear.x = beziertoturtlelinear(1.8, 1.4, -0.3, 0.0, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(1.8, 1.4, -0.3, 0.0, t);
    publisher_->publish(msg);
    }else if(t < 16) {
     msg.linear.x = beziertoturtlelinear(0.6, 2.6, -0.15, 1.2, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(0.6, 2.6, -0.15, 1.2, t);
    publisher_->publish(msg);
    }else if(t < 17) {
     msg.linear.x = beziertoturtlelinear(0.8, -1.0, 0.4, 1.0, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(0.8, -1.0, 0.4, 1.0, t);
    publisher_->publish(msg);
    }else if(t < 18) {
     msg.linear.x = beziertoturtlelinear(0.1, 0.0, 0.1, 0.2, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(0.1, 0.0, 0.1, 0.2, t);
    publisher_->publish(msg);
    }else if(t < 19) {
     msg.linear.x = beziertoturtlelinear(0.1, 0.0, 0.1, 0.2, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(0.1, 0.0, 0.1, 0.2, t);
    publisher_->publish(msg);
    }else if(t < 20) {
     msg.linear.x = beziertoturtlelinear(0.1, 0.0, 0.1, 0.2, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(0.1, 0.0, 0.1, 0.2, t);
    publisher_->publish(msg);
    }else if(t < 21) {
     msg.linear.x = beziertoturtlelinear(0.1, 0.2, 0.1, 1.0, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(0.1, 0.2, 0.1, 1.0, t);
    publisher_->publish(msg);
    }else if(t < 22) {
    msg.linear.x = 0.8;   // maju 2 unit/detik
      msg.angular.z = 0.0 ;
      publisher_->publish(msg); 
    }else if(t < 23) {
     msg.linear.x = beziertoturtlelinear(0.2, 0.01, 0.1, 0.2, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(0.2, 0.01, 0.1, 0.2, t);
    publisher_->publish(msg);
    }else if(t < 24) {
     msg.linear.x = beziertoturtlelinear(-0.2, -0.4, 0.05, -0.3, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(-0.2, -0.4, 0.05, -0.3, t);
    publisher_->publish(msg);
    //}else if(t < 9) {
    // msg.linear.x = beziertoturtlelinear(0.3, 1.0, -0.7, -1.0, t);   // maju 2 unit/detik
    // msg.angular.z = beziertoturtleang(0.3, 1.0, -0.7, -1.0, t);
    //publisher_->publish(msg);
    
    
    }else if(t < 25) {
     msg.linear.x = beziertoturtlelinear(0.3, 1.0, -0.7, -1.0, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(0.3, 1.0, -0.7, -1.0, t);
    publisher_->publish(msg);
    }else if(t < 26) {
     msg.linear.x = beziertoturtlelinear(-0.7, -1.0, 0.55, 0.0, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(-0.7, -1.0, 0.55, 0.0, t);
    publisher_->publish(msg);
    }else if(t < 27) {
     msg.linear.x = beziertoturtlelinear(0.6, 0.4, 0.1, 1.8, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(0.6, 0.4, 0.1, 1.8, t);
    publisher_->publish(msg);
    }else if(t < 28) {
     msg.linear.x = beziertoturtlelinear(0.5, -0.4, 0.15, -0.4, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(0.5, -0.4, 0.15, -0.4, t);
    publisher_->publish(msg);
    }else if(t < 29) {
     msg.linear.x = beziertoturtlelinear(1.5, 0.0, 0.5, 1.0, t);   // maju 2 unit/detik
     msg.angular.z = beziertoturtleang(1.5, 0.0, 0.5, 1.0, t);
    publisher_->publish(msg);
    } else {
    msg.linear.x = 0.0;   // maju 2 unit/detik
      msg.angular.z = 0.0 ;
      publisher_->publish(msg);
    }
    t += 0.01;
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<hurufkomplex>());
  rclcpp::shutdown();
  return 0;
}