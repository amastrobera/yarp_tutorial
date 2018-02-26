#include <Point3D.h>
#include <Path3D.h>
#include <InterfacePathGenerator.h>

#include <yarp/os/Property.h>
#include <yarp/os/Network.h>
#include <yarp/os/Port.h>
#include <yarp/os/Bottle.h>
#include <yarp/os/Time.h>

#include <cmath>
#include <iostream>
#include <random>
#include <sstream>

using namespace yarp::os;

int32_t calculate_path_cost(Path3D const& path)
{
    if (path.points.size() == 1)
        return 0;

    int32_t cost = 0;
    for (int i = 1; i < path.points.size(); ++i)
    {
        int32_t cost_x = path.points[i].x - path.points[i-1].x;
        int32_t cost_y = path.points[i].y - path.points[i-1].y;
        int32_t cost_z = path.points[i].z - path.points[i-1].z;
        cost += sqrt(pow(cost_x, 2) + pow(cost_y, 2) + pow(cost_z, 2));
    }
    return cost;
}

void print_msg(Path3D const& path, int32_t cost)
{
    std::cout << path.name << ": [";
    for (int i = 0; i < path.points.size(); ++i)
        std::cout << "(" << path.points[i].x << ", "
                  << path.points[i].y << ", " 
                  << path.points[i].z << ") ";
    std::cout << "]";
    std::cout << "\n--> cost: " << cost << std::endl;
}


int main(int argc, char* argv[]) 
{
    Network network;
    Port port;
    if (!port.open("/client"))
    {
        std::cerr << "Failed to start /client port" 
                  << "\n-> check if yarp server is running " << std::endl;
        return 1;
    }
    if (!network.connect("/client", "/server")) 
    {
        std::cerr << "failed to connect /client to /server" << std::endl;   
        return 1;
    }

    InterfacePathGenerator servint;
    servint.yarp().attachAsClient(port);
        
    while(true) 
    {
        std::cout << "request for path ... " << std::endl;
        Path3D path = servint.get_path();
        int32_t cost = calculate_path_cost(path);
        print_msg(path, cost);
        servint.set_path_cost(cost);
        Time::delay(2);
    }

    return 0;
}

