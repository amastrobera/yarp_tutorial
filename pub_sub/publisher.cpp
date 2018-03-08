#include <Point3D.h>
#include <Path3D.h>

#include <yarp/os/Network.h>
#include <yarp/os/Publisher.h>
#include <yarp/os/Bottle.h>
#include <yarp/os/Time.h>

#include <iostream>
#include <random>
#include <sstream>

using namespace yarp::os;

namespace
{

Path3D generatePath()
{
    static size_t mPathID = 0;
    static std::default_random_engine generator;

    Path3D path;
    path.id = mPathID++;
    std::ostringstream os; os << "discrete 3D path " << mPathID;
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

}


int main(int argc, char* argv[])
{
    Network network;
    Publisher<Path3D> pub;

    // TOPIC: in YARP (but not in ROS) one Publisher is one Port
    // the "topic" function assigns the name of the topic to the name of the
    // one port underlying the Subscriber and tries to open it (hence it is a
    // bool). If you want a publisher with multiple topics you either override
    // the function "topic" with includeNodeInName(false) or create a
    // collection of Publishers<T> publishing different thrift types
    // on different ports.
    if (!pub.topic("/data"))
    {
        std::cerr << "Failed to start /data (publisher) port"
                  << "\n-> check if yarp server is running " << std::endl;
        return 1;
    }

    std::cout << "port /server on!" << std::endl;

    while(true)
    {
        //communicate generated path to the client
        Path3D path = generatePath();
        std::cout << "generating " << path.name << " ... " << std::endl;
        pub.write(path);
        Time::delay(2);
    }

    return 0;
}
