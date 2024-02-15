/*****************************************************/
/* Organization: Stuba Green Team
/* Authors: Patrik Knaperek
/*****************************************************/

#include "../include/visual_odometry.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "visual_odometry");
  ros::NodeHandle handle;

  VisualOdometry visual_odometry(handle);

  ros::spin();
}
