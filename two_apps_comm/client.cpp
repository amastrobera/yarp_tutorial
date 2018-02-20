/*
 * Copyright: None
 * Author: Angelo Mastro
 * CopyPolicy: None
 */
#include <iostream>
#include <unistd.h>
#include <yarp/os/all.h>

using namespace yarp::os;

int main(int argc, char *argv[]) {

    Network yarp; // this is just a placeholder, necessary for ports
                    // in this case, connect them your self from the terminal
                    // $ yarp connect /server /client


    Port port;
    if (!port.open("/client")) {
        std::cerr << "Failed to create ports." << std::endl;
        std::cerr << "Maybe you need to start a nameserver (run 'yarpserver')" << std::endl;
        return 1;
    }
 
    Bottle b;
    while(true) {
        // read the message
        if (!port.read(b)) {
            std::cerr << "Failed to read message" << std::endl;
        }
        std::cout << "Received " << b.toString() << std::endl;
        sleep(1);
    }
    return 0;
}
