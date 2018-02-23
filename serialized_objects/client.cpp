/*
 * Copyright: None
 * Author: Angelo Mastro
 * CopyPolicy: None
 */

#include <data.hpp>
#include <iostream>
#include <unistd.h>
#include <yarp/os/all.h>

using namespace yarp::os;

int main(int argc, char *argv[]) {

    Network yarp; // this is just a placeholder, necessary for ports
                    // in this case, connect them your self from the terminal
                    // $ yarp connect /server /client


    BufferedPort<Target> port;
    if (!port.open("/client")) {
        std::cerr << "Failed to create ports." << std::endl;
        std::cerr << "Maybe you need to start a nameserver (run 'yarpserver')" << std::endl;
        return 1;
    }
 
    while(true) {
        // read the message
        Target* t = port.read(true); // true = blocking, false=non blocking
        if (!t) {
            std::cerr << "Failed to read message" << std::endl;
        }
        sleep(1);
    }
    return 0;
}
