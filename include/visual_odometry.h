/*****************************************************/
/* Organization: Stuba Green Team
/* Authors: Patrik Knaperek
/*****************************************************/

#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <tf/transform_datatypes.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include "../../SGT_Utils.h"

class VisualOdometry {
public:
  VisualOdometry(ros::NodeHandle& nh);
  ~VisualOdometry() = default;

  void broadcastTf(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr &msg);
  
private:
    
  ros::Subscriber camera_pose_sub_;
  
  std::string base_frame_id_;
  tf::StampedTransform camera_to_base_tf_;
  tf::TransformBroadcaster tf_broadcaster_;
  tf::TransformListener tf_listener_;

};
