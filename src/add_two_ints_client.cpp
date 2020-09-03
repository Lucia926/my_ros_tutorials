#include <ros/ros.h>
#include <my_tutorials/AddTwoInts.h>
#include <cstdlib>

int main(int argc, char **argv)
{
  // 初始化ros节点
  ros::init(argc, argv, "add_two_ints_client");
  // 接受来自控制台的参数 x y
  if (argc != 3)
  {
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }
	// 生成节点句柄
  ros::NodeHandle n;
	// 生成一个客户端
	// 这个客户端需要与名为add_two_ints的服务端链接
  ros::ServiceClient client = n.serviceClient<my_tutorials::AddTwoInts>("add_two_ints");
	// 生成一个服务端的数据对象srv，srv中包含请求reqeust和应答response
  my_tutorials::AddTwoInts srv;
	// 在客户端中，我们对srv中的请求赋值，并发送给服务端
	// 将控制台传进来的参数赋值给request
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
	// 通过client.call函数将srv发送给服务端
	// 在服务端的serviceRequestAndResponse函数中处理接收到的srv
	// 实际上客户端会在此处等待服务端的执行结果
  if (client.call(srv))
  {
		// 请求完成后，服务端将结果返回至srv中的response中
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}