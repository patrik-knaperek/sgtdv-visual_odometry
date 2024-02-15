/*****************************************************/
/* Organization: Stuba Green Team
/* Authors: Patrik Knaperek
/*****************************************************/

#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <tf/transform_datatypes.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

class VisualOdometry {
public:
  VisualOdometry();
  ~VisualOdometry();

  void broadcastTf(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr &msg);
  void setBaseFrameId(const std::string base_frame_id)
  {
    this->base_frame_id_ = base_frame_id;
  };

private:
    
  std::string base_frame_id_;
  tf::StampedTransform camera_to_base_tf_;
  tf::TransformBroadcaster tf_broadcaster_;
  tf::TransformListener tf_listener_;

};
