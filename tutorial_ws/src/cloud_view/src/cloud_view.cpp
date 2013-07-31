/*******************************************************************
* Copyright (c) 2013 Daiki Maekawa
*
* @file cloud_view.h
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

typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;

int main(int argc, char *argv[]){
    PointCloud cloud;
    cloud.width    = 100;  
    cloud.height   = 100;  
    cloud.is_dense = false;  
    cloud.points.resize (cloud.width * cloud.height);  

    for (size_t i = 0; i < cloud.points.size (); ++i)  
    {  
        cloud.points[i].x = 1024 * rand () / (RAND_MAX + 1.0);  
        cloud.points[i].y = 1024 * rand () / (RAND_MAX + 1.0);  
        cloud.points[i].z = 1024 * rand () / (RAND_MAX + 1.0);  
    }  
    
    pcl::visualization::CloudViewer viewer ("Simple Cloud Viewer");  
    viewer.showCloud (cloud.makeShared()); 
    while (!viewer.wasStopped ()) { }

    return 0;
}
