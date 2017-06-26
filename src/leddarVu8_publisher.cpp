#include <ros/ros.h>
#include <ros/console.h>
#include <angles/angles.h>
#include "std_msgs/String.h"

#include <sstream>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <vector>
using namespace std;















int main(int argc, char **argv)
{

  // We must initialize ROS 
  ros::init(argc, argv, "leddar_publisher");
  
  // Initialize node.
  ros::NodeHandle nh("~");

  // Initialize publisher.
  ros::Publisher pub = nh.advertise<std_msgs::String>(std::string("publish_data_vu8"), 1);

  ros::Rate loop_rate(60.0);

  std::ifstream publish_file("/home/dasc/catkin_vu8_ws/src/leddarVu8_publisher/src/vu8_sensor_results.txt");
  std::string publish_txt;
  std::string line;
  std_msgs::String msg;
  std::string data_block;
  vector<int> channels;
  int index;
  int peek_file_val;

  getline(publish_file, line);
  channels.push_back(line[0]);
  ++index;
  data_block = '\n' + line + '\n';	

  while(1)
  {
	peek_file_val = publish_file.peek();
    	if(peek_file_val != EOF)
    	{      
	    getline(publish_file, line);
	    channels.push_back(line[0]);
	    
            if(channels[index] > channels[index - 1])
	    {
	    
		    msg.data = data_block;

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
		    
		    data_block = '\n';
	    }
	    
            data_block += line + '\n';
            ++index;
            
    	}
	
	else
	{
	     publish_file.clear();
	}
  }

}


