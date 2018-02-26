#include <Point3D.h>
#include <Path3D.h>
#include <InterfacePathGenerator.h>

#include <yarp/os/Network.h>
#include <yarp/os/Port.h>
#include <yarp/os/Bottle.h>
#include <yarp/os/Time.h>

#include <iostream>
#include <random>
#include <sstream>

using namespace yarp::os;

class PathGenerator : public InterfacePathGenerator 
{
public:
    PathGenerator() : mPathID(0) {}
    virtual Path3D get_path() override;
    virtual void set_path_cost(const int32_t cost) override;
private:
    int mPathID; 
    std::default_random_engine generator;
};

Path3D PathGenerator::get_path()
{
    Path3D path;
    std::ostringstream os; os << "path " << mPathID++;
    path.name = os.str();

    std::uniform_int_distribution<int> n(2, 4), x(0,9), y(0,9), z(0,9);
    int len = n(generator);
    for (int i = 0; i < len; ++i)
    {
        Point3D p;
        p.x = x(generator);
        p.y = y(generator);
        p.z = z(generator);
        path.points.push_back(p);
    }
    return path;
}

void PathGenerator::set_path_cost(int cost)
{
    std::cout << "the cost is " << cost << std::endl;
}


int main(int argc, char* argv[]) 
{
    Network network;
    PathGenerator generator;
    Port port;
    generator.yarp().attachAsServer(port);

    if (!port.open("/server"))
    {
        std::cerr << "Failed to start /server port" 
                  << "\n-> check if yarp server is running " << std::endl;
        return 1;
    }
    
    //network.connect("/server","/client"); // otherwise connect statically 
        
    while(true) 
    {                  
        //communicate generated path to the client
        std::cout << "port /server on!\ngenerating discrete points ... " 
                  << std::endl;
        Time::delay(2);
    }
    
    port.close();

    return 0;
}

