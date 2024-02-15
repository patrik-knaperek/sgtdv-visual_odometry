/*****************************************************/
/* Organization: Stuba Green Team
/* Authors: Patrik Knaperek
/*****************************************************/

#include "../include/visual_odometry.h"

VisualOdometry::VisualOdometry(ros::NodeHandle& nh) :
  /* ROS interface init */
  camera_pose_sub_(nh.subscribe("camera_pose", 1, &VisualOdometry::broadcastTf, this))
{
  /* Load parameters */
  Utils::loadParam(nh,"/base_frame_id", std::string("camera_center"), &base_frame_id_);
  
  /* Get static TF from camera refernece frame to base frame */
  try
  {
    tf_listener_.lookupTransform(base_frame_id_, "camera_left", ros::Time(0), camera_to_base_tf_);
  }
  catch(const std::exception& e)
  {
    std::cout << e.what();
  }

}

void VisualOdometry::broadcastTf(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr &msg)
{
  tf::Transform base_to_odom_tf;
  
  tf::Vector3 camera_pos_odom_frame(msg->pose.pose.position.x - camera_to_base_tf_.getOrigin().getX(),
                                      msg->pose.pose.position.y - camera_to_base_tf_.getOrigin().getY(),
                                      msg->pose.pose.position.z - camera_to_base_tf_.getOrigin().getZ());
  tf::Quaternion camera_rot_odom_frame(msg->pose.pose.orientation.x,
                                      msg->pose.pose.orientation.y,
                                      msg->pose.pose.orientation.z,
                                      msg->pose.pose.orientation.w);
  
  base_to_odom_tf.setOrigin(camera_pos_odom_frame);
  base_to_odom_tf.setRotation(camera_rot_odom_frame);

  tf_broadcaster_.sendTransform(tf::StampedTransform(base_to_odom_tf, msg->header.stamp, msg->header.frame_id, base_frame_id_));
}
