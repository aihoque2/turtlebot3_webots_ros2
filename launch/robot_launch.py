import os
import launch
from launch import LaunchDescription
from ament_index_python.packages import get_package_share_directory
from webots_ros2_driver.webots_launcher import WebotsLauncher
from webots_ros2_driver.webots_controller import WebotsController

def generate_launch_description():
    package_dir = get_package_share_directory('turtlebot3_webots')
    robot_description_path = os.path.join(package_dir, 'urdf', 'my_robot.urdf')
    
    webots = WebotsLauncher(
        world = os.path.join(package_dir, 'worlds', 'my_world.wbt'),
        ros2_supervisor=True
    )

    robot_driver = WebotsController(
        robot_name = 'my_robot',
        parameters = [
            {'robot_description': robot_description_path,
             'set_robot_state_publisher': True},
        ],
        respawn=True
    )

    return LaunchDescription([
        webots,
        webots._supervisor,
        robot_driver,
        launch.actions.RegisterEventHandler(
            event_handler = launch.event_handlers.OnProcessExit(
                target_action=webots,
                on_exit=[launch.actions.EmitEvent(event=launch.events.Shutdown())]
            )
        )
    ])