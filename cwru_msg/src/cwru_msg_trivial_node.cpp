//example ROS service:
#include <ros/ros.h>
// put this here to to test that cwru_srv messages get made... 

#include <cwru_msg/vec_of_doubles.h>

#include <iostream>
#include <string>
using namespace std;


int main(int argc, char **argv)
{
  ros::init(argc, argv, "cwru_msg_trivial_node");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<cwru_msg::vec_of_doubles>("cwru_msg_test_topic", 1);

  ROS_INFO("starting cwru_msg_trivial_node");
  cwru_msg::vec_of_doubles vec_msg;
  vec_msg.dvec.resize(3);
  vec_msg.dvec[0]=0;
  vec_msg.dvec[1]=1;
  vec_msg.dvec[2]=3.1416;

  ROS_INFO("going into loop...");
  while(ros::ok()) {
    pub.publish(vec_msg);
    ros::Duration(1.0).sleep();
    ros::spinOnce();
  }

  return 0;
}
