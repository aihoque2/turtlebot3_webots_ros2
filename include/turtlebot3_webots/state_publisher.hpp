#include <webots/Supervisor.hpp>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>

class StatePublisher : public rclcpp::Node{
    public:
        StatePublisher();
    
    private:
        bool is_publishing = false;
};