#ifndef GST_PIPELINE__GST_PIPES_PLUGIN_PAUSE_SRV_H_
#define GST_PIPELINE__GST_PIPES_PLUGIN_PAUSE_SRV_H_

#include <gst_pipes_plugin_base.h>

//#include <rclcpp/node_interfaces/node_interfaces.hpp>  //not in galactic
//#include <rclcpp/node_interfaces/node_base_interface.hpp>

#include <gst_bridge/gst_bridge.h>

#include "rclcpp/rclcpp.hpp"

namespace gst_pipes
{
/*

Play/Pause:
  provide a ROS service with a Gazebo style play/pause API

  This might be small enough and generally useful enough to load by default
  we'll leave it as a pluginlib plugin for now

*/

// a ros service that can pause and resume the pipeline
class gst_pipes_pause_srv : public gst_pipes_plugin
{
public:
  // during init, we need to
  //  create a ros service
  //  point the service callbacks to the pipeline
  void initialise(
    std::string name,  // the config-file name of the plugin (possibly unused)
    gst_bridge::node_interface_collection node_if, GstElement * pipeline);

  // handle the play/pause service requests
  void service_cb(/* Gazebo's play/pause message type */);

private:
};

}  // namespace gst_pipes

#endif  //GST_PIPELINE__GST_PIPES_PLUGIN_PAUSE_SRV_H_
