#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>
#include <sstream>

 int main(int argc,char **argv)
 {
    std::cout << argc << std::endl;
    for (int i=0; i<argc; i++) {
      std::cout << argv[i] << std::endl;
    }
    ros::init(argc,argv,"luciatalker");
    ros::NodeHandle n;
    ros::Publisher luciachatter_pub=n.advertise<std_msgs::String>("lchatter",1000);
    ros::Rate loop_rate(10);
    int count=0;
    while(ros::ok())
    {
        std_msgs::String msg;
        msg.data="Ros Ros Ros";
        ROS_INFO("%s",msg.data.c_str());
        luciachatter_pub.publish(msg);
        //ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }
    return 0;
 }