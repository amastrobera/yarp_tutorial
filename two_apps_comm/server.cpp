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

    Network yarp;   // this is just a placeholder, necessary for ports
                    // in this case, connect them your self from the terminal
                    // $ yarp connect /server /client
    
    Port port;
    if (!port.open("/server")) {
        std::cerr << "Failed to create ports." << std::endl;
        std::cerr << "Maybe you need to start a nameserver (run 'yarpserver')" << std::endl;
        return 1;
    }


    yarp.connect("/server","/client"); // otherwise connect statically 

    int i = 0;
    while(i < 100) {
        // prepare a message to send
        Bottle b;
        b.addString("Hello");
        b.addInt(i++);
        std::cout << "Sending " << b.toString() << std::endl;
        if (!port.write(b)) {
            std::cerr << "Failed to send msg " << b.toString() << std::endl;
        }

        sleep(1);
    }
    return 0;
}
