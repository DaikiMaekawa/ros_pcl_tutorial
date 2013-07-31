cmake_minimum_required(VERSION 2.8.3)
project(cloud_view)

find_package(catkin REQUIRED COMPONENTS roscpp rospy)
find_package(Boost REQUIRED COMPONENTS system)
find_package(PCL REQUIRED)

include_directories(
    ${PCL_INCLUDE_DIRS}
    /opt/ros/groovy/include/pcl-1.6
    /usr/include/eigen3 
    ${catkin_INCLUDE_DIRS}
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES beginner_tutorials
  CATKIN_DEPENDS roscpp rospy
  DEPENDS system_lib
)


link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
add_executable(cloud_view src/cloud_view.cpp)

target_link_libraries(cloud_view
    ${PCL_LIBRARIES}
    ${catkin_LIBRARIES}
)

