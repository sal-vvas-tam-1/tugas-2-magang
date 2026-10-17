source ~/ros2_ws/install/setup.bash

ros2 service call /turtle1/set_pen turtlesim/srv/SetPen "{r: 69, g: 86, b: 255, width: 0}"

ros2 service call /turtle1/teleport_absolute turtlesim/srv/TeleportAbsolute "{x: 3.0, y: 7.0, theta: 3.14}"

ros2 service call /turtle1/set_pen turtlesim/srv/SetPen "{r: 255, g: 0, b: 0, width: 3}"


ros2 run buatgambar hurufkomplex
