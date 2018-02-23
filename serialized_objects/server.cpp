/*
 * Copyright: None
 * Author: Angelo Mastro
 * CopyPolicy: None
 */

#include <data.hpp>
#include <iostream>
#include <random>
#include <unistd.h>
#include <yarp/os/all.h>

using namespace yarp::os;

int main(int argc, char *argv[]) {

    Network yarp;   // this is just a placeholder, necessary for ports
                    // in this case, connect them your self from the terminal
                    // $ yarp connect /server /client
    
    BufferedPort<Target> port;
    if (!port.open("/server")) {
        std::cerr << "Failed to create ports." << std::endl;
        std::cerr << "Maybe you need to start a nameserver (run 'yarpserver')" << std::endl;
        return 1;
    }


    yarp.connect("/server","/client"); // otherwise connect statically 

    int i = 0;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,90);
    while(i < 100) {
        // prepare a message to send
        Target& t = port.prepare();
        t.x = distribution(generator);
        t.y = distribution(generator);
        port.write(true); // true = blocking, false = non blocking

        sleep(1);
    }
    return 0;
}
