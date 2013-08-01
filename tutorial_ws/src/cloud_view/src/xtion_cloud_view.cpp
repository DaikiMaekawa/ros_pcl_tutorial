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
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/cloud_viewer.h>
#include <boost/lambda/lambda.hpp>
#include <boost/bind.hpp>

class RosCloudViewer{
    pcl::visualization::CloudViewer m_viewer;
    ros::Subscriber m_pcSub;

public:
    typedef pcl::PointCloud<pcl::PointXYZRGB> PointCloud;
    RosCloudViewer(ros::NodeHandle &node) : 
        m_viewer("RGB-D Sensor Cloud Viewer"),
	m_pcSub(node.subscribe<PointCloud>("points", 1, 
	    boost::bind(&RosCloudViewer::receivePointCloudCb, this, boost::lambda::_1)))
    { 
    
    }

    void run(){
        ros::spin();
    }

private:
    void receivePointCloudCb(const PointCloud::ConstPtr &msg){
        m_viewer.showCloud(msg->makeShared());
    }
   
};


int main(int argc, char *argv[]){
    ros::init(argc, argv, "cloud_viewer");
    ros::NodeHandle node;
    RosCloudViewer rViewer(node);

    rViewer.run();

    return 0;
}
