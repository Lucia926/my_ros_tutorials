#include <iostream>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>

int count=0;

void callback(std_msgs::String msg)
{
    ROS_INFO("%s:%d",msg.data.c_str(),count);
}


int main(int argc,char** argv)
{
    ros::init(argc,argv,"listener");
    ros::NodeHandle n;
    ros::Subscriber chatter_sub=n.subscribe("lchatter",1,callback);

   // ros::spin();
   while(ros::ok())
   {
       ros::spinOnce();
       count+=1;
   }

}
