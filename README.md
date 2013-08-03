ros_pcl_tutorial
================

ROS勉強会<入門編>に使用したPCLのチュートリアルです

　→　[ROS勉強会について](https://github.com/DaikiMaekawa/description/tree/master/ros_tutorial "ROS勉強会のPDF")

## ビルド

cd ros_pcl_tutorial/tutorial_ws

catkin_make

## 実行

roscore 

rosrun cloud_view xtion_cloud_view points:=/camera/depth_registered/points

rosbag play point_cloud.bag

##免責事項

このプログラムによって発生した、いかなる障害・損害も作成者は一切責任を負わないものとする。
