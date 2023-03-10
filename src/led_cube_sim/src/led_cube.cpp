#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/Point.h>
#include <std_msgs/ColorRGBA.h>
#include<iostream>
#include<cstdlib>

visualization_msgs::Marker cube;

void updateCube(std_msgs::ColorRGBA color, int position)   {
    cube.colors.at(position) = color;
}
std_msgs::ColorRGBA randColor() {
    std_msgs::ColorRGBA color;
    color.a = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    color.b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    color.g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    color.r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    return color;
}
int randPosition()  {
    return std::rand()%512;
}
int main(int argc, char** argv) {
    ros::init(argc, argv, "led_cube");
    cube.action = visualization_msgs::Marker::ADD;
    cube.header.frame_id = "map";
    cube.scale.x = 3.0;
    cube.scale.y = 3.0;
    cube.scale.z = 3.0;
    cube.type = visualization_msgs::Marker::SPHERE_LIST;
    cube.id = 0;
    cube.ns = "spheres";
    cube.pose.orientation.w = 1.0;
    ros::NodeHandle nh;
    ros::Rate loop_rate(300);
    ros::Publisher led_cube_pub = nh.advertise<visualization_msgs::Marker>
        ("led_cube_vis", 10);
    geometry_msgs::Point p;
    p.x = 0;
    p.y = 0;
    p.z = 0;
    std_msgs::ColorRGBA c;
    c.a = 1.0;
    c.b = 1.0;
    for(int i=0; i<8; i++)  {
            for(int j=0; j<8; j++)    {
                for(int m=0;m<8;m++)    {
                    p.x = m*10;
                    cube.points.push_back(p);
                    cube.colors.push_back(c);
                }
            p.y = j*10;
            }
        p.z = i*10;
    }
    led_cube_pub.publish(cube);
    while(ros::ok())    {
        updateCube(randColor(),randPosition());
        led_cube_pub.publish(cube);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}