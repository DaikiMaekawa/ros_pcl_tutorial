/*******************************************************************
* Copyright (c) 2013 Daiki Maekawa
*
* @file .h
* @brief
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

typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;
//typedef pcl::PointCloud<pcl::PointXYZRGB> PointCloud;


void receivePointCloudCb(const PointCloud::ConstPtr &msg){
    std::cout << "Cloud: width = " << msg->width << ", height = " << msg->height << std::endl;
    //viewer.showCloud(msg->makeShared());  
    //BOOST_FOREACH(const pcl::PointXYZ& pt, msg->points)
    //    std::cout << "\t(" << pt.x << ", " << pt.y << ", " << pt.z << ")" << std::endl;
}

int main(int argc, char *argv[]){
    PointCloud cloud;
    cloud.width    = 5;  
    cloud.height   = 1;  
    cloud.is_dense = false;  
    cloud.points.resize (cloud.width * cloud.height);  

    for (size_t i = 0; i < cloud.points.size (); ++i)  
    {  
        cloud.points[i].x = 1024 * rand () / (RAND_MAX + 1.0);  
        cloud.points[i].y = 1024 * rand () / (RAND_MAX + 1.0);  
        cloud.points[i].z = 1024 * rand () / (RAND_MAX + 1.0);  
    }  
    // 追加  
    pcl::visualization::CloudViewer viewer ("Simple Cloud Viewer");  
    viewer.showCloud (cloud.makeShared()); 
    while (!viewer.wasStopped ()) { }

    /*
    ros::init(argc, argv, "sub_pcl");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe<PointCloud>("points", 1, receivePointCloudCb);
    
    pcl::visualization::CloudViewer viewer("Simple Cloud Viewer"); 
    viewer.showCloud(msg->makeShared());  
    ros::spin();
    
    while (!viewer.wasStopped()){
        ros::spinOnce();
        ros::sleep(1);
    }
    */

    return 0;
}
