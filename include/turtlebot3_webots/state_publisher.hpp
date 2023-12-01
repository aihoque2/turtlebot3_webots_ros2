#include <webots/Robot.hpp>
#include <webots/Supervisor.hpp>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>

class StatePublisher : public rclcpp::Node{
    public:
        StatePublisher(): Node("webots_state_pub_ammar"){
            supervisor = webots::Supervisor();
            my_robot_node = supervisor.getFromDef("my_robot");

        };
        
        /*
        this publisher is meant to publish the robot's state directly from webots
        */

        void publishPose(){
            if (my_robot_node){
                const double *position = my_robot_node->getPosition();
                const double *orientation = my_robot_node->getOrientation();
                // handle position and orientation

                int x = position[0];
                int y = position[1];
                int z = position[2];
                RCLCPP_INFO("here is position x: ", )
            }
        }

    private:
        bool is_publishing = false;
        webots::Supervisor supervisor;
        webots::Node *my_robot_node;
        rclcpp::Publisher<geometry_msgs::msg::Pose>::SharedPtr state_pub_; // TODO: change auto to the real message format we want
        rclcpp::TimerBase::SharedPtr timer_;
};