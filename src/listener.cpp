#include <iostream>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int8.h>
#include <string>

int count = 0;

void callback(std_msgs::String msg) {
    ROS_INFO("%s: %d", msg.data.c_str(), count);
    //ROS_INFO("%d", msg.data);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "listener");
    ros::NodeHandle n;
    ros::Subscriber chatter_sub = n.subscribe("lchatter", 1, callback);

    // ros::spin();
    while (ros::ok()) 
    {
        ros::spinOnce();
        count += 2;
    }

}



