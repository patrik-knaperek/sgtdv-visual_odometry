# **VisualOdometry package**

___

© **SGT Driverless**

**Authors:** Patrik Knaperek

**Objective:** -- *Deprecated* -- Broadcast TF messages from `camera_pose` topic.
___


The `visual_odometry` node subscribes to the visual odometry topic from camera and broadcasts its data to the `/tf` topic via `tf::TransformBroadcaster` object as a `base_link` → `odom` TF.

Use of this package is no longer needed since the [`robot_localization` package](../robot_localization/README.md) fuses all odometry sources using EKF and broadcasts the `base_link` → `odom` TF. However, it still can be useful in for test purposes to examine the camera visual odometry performance independently, without filtering.

### Related packages
* [`camera_driver`](../camera_driver/README.md)


## Compilation
```sh
$ cd ${SGT_ROOT}/ros_implementation
$ catkin build visual_odometry
```

## Launch
*Note: never launch alongside `robot_localization` node - that would mean having duplicate odometry sources active*
### Source the environment
```sh
$ cd ${SGT_ROOT}/ros_implementation
$ source ./devel/setup.bash
```
### Launch the node
* standalone
```sh
$ rosrun visual_odometry visual_odometry
```
* along with other nodes
  * add/uncomment this line in the related launchfile
```xml
<node pkg="visual_odometry" type="visual_odometry" name="base_link_to_odom" output="screen"/>
```
