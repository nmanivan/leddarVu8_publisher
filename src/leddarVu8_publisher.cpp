#include <ros/ros.h>
#include <ros/console.h>
#include <angles/angles.h>
#include "std_msgs/String.h"

#include <sstream>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>















int main(int argc, char **argv)
{

  // We must initialize ROS 
  ros::init(argc, argv, "leddar_publisher");
  
  // Initialize node.
  ros::NodeHandle nh("~");

  // Initialize publisher.
  ros::Publisher pub = nh.advertise<std_msgs::String>(std::string("publish_data"), 1);

  ros::Rate loop_rate(10.0);

  std::ifstream publish_file("/home/narayan/catkin_vu8_ws/src/leddarVu8_publisher/src/vu8_sensor_results.txt");
  std::string publish_txt;
  std::string line;
  std_msgs::String msg;

  // while(getline(publish_file, line))
  // {
  //   publish_txt.append(line);
  //   publish_txt.append("\n");
  // }

  while(getline(publish_file, line))
  {
    
    msg.data = line;

    ROS_INFO("%s", msg.data.c_str());
      
    /*
    * The publish() function is how you send messages. The parameter
    * is the message object. The type of this object must agree with the type
    * given as a template parameter to the advertise<>() call, as was done
    * in the constructor above.
    */

    pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();

  }

}



