#include <ros/ros.h>
#include <my_tutorials/AddTwoInts.h>
 
// service回调函数，输入参数req，输出参数res

/* service回调函数和topic通信方式回调函数的最大区别在于：
   topic通信方式中，回调函数在接收到指定话题的消息后开始进行工作
   service回调函数的形参包含一个请求和一个应答
   在接收到请求后，进入到service回调函数中，并且完成请求
   在这之后，会将请求的结果记录在应答中，并反馈给客户端
 */
bool serviceRequestAndResponse(my_tutorials::AddTwoInts::Request  &req,
                               my_tutorials::AddTwoInts::Response &res)
{
  // 将输入参数中的请求数据相加，结果放到应答变量中
  res.sum = req.a + req.b;
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);
  sleep(5);
  return true;
}
 
int main(int argc, char **argv)
{
  // ROS节点初始化
  ros::init(argc, argv, "add_two_ints_server");
  
  // 创建节点句柄
  ros::NodeHandle n;
 
  // 创建一个名为add_two_ints的server，注册回调函数serviceRequestAndResponse()
  ros::ServiceServer service = n.advertiseService("add_two_ints", serviceRequestAndResponse);
  
  // 循环等待客户端的request触发回调函数
  ROS_INFO("Ready to add two ints.");
  ros::spin();
 
  return 0;
}