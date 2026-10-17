cmake_minimum_required(VERSION 3.8)
project(buatgambar)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(turtlesim REQUIRED)

add_executable(bunga src/bunga.cpp)
add_executable(hurufkomplex src/hurufkomplex.cpp)
ament_target_dependencies(bunga rclcpp geometry_msgs)
ament_target_dependencies(hurufkomplex rclcpp geometry_msgs)
install(TARGETS
  bunga
  hurufkomplex
  DESTINATION lib/${PROJECT_NAME})
  
ament_package()
