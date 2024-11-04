cmake_minimum_required(VERSION 3.0.2)
project(visual_odometry)

add_compile_options(-std=c++14)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  std_msgs
  tf
  tf_conversions
)

###################################
## catkin specific configuration ##
###################################
catkin_package(
)

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} src/visual_odometry_node.cpp src/visual_odometry.cpp)

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
)
