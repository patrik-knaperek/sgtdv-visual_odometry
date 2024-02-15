/*****************************************************/
/* Organization: Stuba Green Team
/* Authors: Patrik Knaperek
/*****************************************************/

#include "../include/visual_odometry.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "visual_odometry");
  ros::NodeHandle handle;

  VisualOdometry visual_odometry;

  std::string base_frame;
  if(!handle.param("/base_frame", base_frame, std::string("camera_center")))
      ROS_INFO("Failed to get parameter \"/base_frame\" from server. Setting default value.\n");
  visual_odometry.setBaseFrameId(base_frame);

  ros::Subscriber subscriber = handle.subscribe("/camera_pose", 1, &VisualOdometry::broadcastTf, &visual_odometry);

  ros::spin();
}
