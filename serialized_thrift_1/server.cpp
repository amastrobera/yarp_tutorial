/*
 * Copyright: None
 * Author: Angelo Mastro
 * CopyPolicy: None
 */

#include <iostream>
#include <random>
#include <SharedData.h>
#include <sstream>
#include <unistd.h>
#include <yarp/os/all.h>

using namespace yarp::os;

SharedData prepareMsg(int i)
{
    static std::default_random_engine generator;
    static std::uniform_real_distribution<double> distribution(0,10);
    std::ostringstream os;
    os << "Pos " << i;
    SharedData d;
    d.text = os.str();
    d.content.push_back(distribution(generator));
    d.content.push_back(distribution(generator));
    return d;
}


int main(int argc, char *argv[]) {

    Network yarp;   // this is just a placeholder, necessary for ports
                    // in this case, connect them your self from the terminal
                    // $ yarp connect /server /client
    
    Port port;
    if (!port.open("/server"))
    {
        std::cerr << "Failed to create ports." << std::endl;
        std::cerr << "Maybe you need to start a nameserver (run 'yarpserver')" << std::endl;
        return 1;
    }

    yarp.connect("/server","/client"); // otherwise connect statically 

    int i = 0;
    while(i < 100) {
        // prepare a message to send
        SharedData d = prepareMsg(i++);
        std::cout << "sending " << d.text << " (" << d.content.at(0) << ", " 
          << d.content.at(1) << ")" << std::endl;
        if (!port.write(d)) 
        {
            std::cerr << "Failed to send msg " << i << std::endl;
        }
        sleep(1);
    }
    return 0;
}
