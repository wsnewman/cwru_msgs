//cwru_msg_trivial_publisher: run this node together with cwru_msg_trivial_subscriber
#include <ros/ros.h>
// put this here to to test that cwru_msg messages get made... 

#include <cwru_msgs/VecOfDoubles.h> // header for the new message type to be illustrated

#include <iostream>
#include <string>
using namespace std;


int main(int argc, char **argv)
{
  ros::init(argc, argv, "cwru_msg_trivial_publisher");
  ros::NodeHandle n;
  // note that we will publish using this new message type: cwru_msgs::VecOfDoubles
  ros::Publisher pub = n.advertise<cwru_msgs::VecOfDoubles>("cwru_msg_test_topic", 1);

  ROS_INFO("starting cwru_msg_trivial_publisher");
  cwru_msgs::VecOfDoubles vec_msg; //create an instance of this message type
  vec_msg.dbl_vec.resize(3); //manually resize it to hold 3 doubles
  vec_msg.dbl_vec[0]=0;  //populate with values, indexing like a normal array
  vec_msg.dbl_vec[1]=1;
  vec_msg.dbl_vec[2]=3.1416;

  ROS_INFO("going into loop...");
  double counter = 0.0; // used to illustrate extending the vector length
  while(ros::ok()) {
    ROS_INFO("publishing...");
    counter+=1.0; // add 1
    // here is an alternative way to put data in the vector: push_back()
    vec_msg.dbl_vec.push_back(counter); // this makes the vector longer, to hold additional data
    pub.publish(vec_msg);  // this vector is longer every time we publish; in general, be careful of limits
    ros::Duration(1.0).sleep();
    ros::spinOnce();
  }

  return 0;
}
