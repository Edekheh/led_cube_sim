# Led cube visualization
1. Requirements : 
    - ROS Noetic : http://wiki.ros.org/noetic/Installation/Ubuntu
We are using Rviz and visualization_msgs.
2. Clone this repo into src folder of ros(catkin) workspace
    - You can init workspace by :
    ```sh
    mkdir workspace_name
    cd workspace_name
    mkdir src
    catkin init
    ```
3. Build and launch :
```sh
catkin build
source devel/setup.bash
roslaunch led_cube_sim visualization.launch
```