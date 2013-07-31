/*******************************************************************
* Copyright (c) 2013 Daiki Maekawa
*
* @file xtion_cloud_view.h
* @brief To learn about the visualization of point cloud
* @author Daiki Maekawa
* @date 2013-07-31
*******************************************************************/

#include <ros/ros.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <boost/foreach.hpp>
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/cloud_viewer.h>

typedef pcl::PointCloud<pcl::PointXYZRGB> PointCloud;

pcl::visualization::CloudViewer viewer("RGB-D Sensor Cloud Viewer");

void receivePointCloudCb(const PointCloud::ConstPtr &msg){
    std::cout << "Cloud: width = " << msg->width << ", height = " << msg->height << std::endl;
    viewer.showCloud(msg->makeShared());
}

int main(int argc, char *argv[]){
    ros::init(argc, argv, "cloud_viewer");
    ros::NodeHandle node;
    ros::Subscriber sub = node.subscribe<PointCloud>("points", 1, receivePointCloudCb);

    ros::spin();

    return 0;
}
