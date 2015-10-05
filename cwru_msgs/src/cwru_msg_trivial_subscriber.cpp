//example ROS subscriber, illustrating use of a variable-length vector message

#include <ros/ros.h>
#include <cwru_msgs/VecOfDoubles.h> //this is the message type we are testing

#include <iostream>
#include <string>
using namespace std;

//callback receives messages of our new type
void myCallback(const cwru_msgs::VecOfDoubles& message_holder) 
{ 
  // define a vector of doubles, then copy the contents of our received message into it
  vector <double> vec_of_doubles = message_holder.dbl_vec; 
  int nvals = vec_of_doubles.size(); //ask the vector how long it is
  ROS_INFO("received %d values, which are: ",nvals);
  for (int i=0;i<nvals;i++) {
    ROS_INFO("%f",vec_of_doubles[i]); //print out all the values
    // note: with corresponding publisher, this vector gets longer each publication
  }
} 

int main(int argc, char **argv)
{
  ros::init(argc, argv, "cwru_msg_trivial_subscriber");
  ros::NodeHandle n;
  ros::Subscriber my_subscriber_object= n.subscribe("cwru_msg_test_topic",1,myCallback); 

  ros::spin(); 
  return 0; 
} 
