/*
 * Copyright: None
 * Author: Angelo Mastro
 * CopyPolicy: None
 */
#include <iostream>
#include <yarp/os/all.h>

using namespace yarp::os;

class DataProcessor : public PortReader {
    virtual bool read(ConnectionReader &connection) {
        Bottle b;
        // read the message
        if (!b.read(connection)) {
            std::cerr << "Failed to read message" << std::endl;
            return false;
        }
        std::cout << "Received " << b.toString() << std::endl;
          return true;
    }
};

int main(int argc, char *argv[]) {

    Network yarp; // this is just a placeholder, necessary for ports
                  // in this case, connect them your self from the terminal
                  // $ yarp connect /server /client

    Port port;
    if (!port.open("/client")) {
        std::cerr << "Failed to create ports." << std::endl;
        std::cerr << "Maybe you need to start a nameserver (run 'yarpserver')"
                  << std::endl;
        return 1;
    }

    DataProcessor cb;
    port.setReader(cb); // no need to call p.read() on port any more.

    Bottle b;
    while (true) {
        // callback will be used as long as server sends data
    }
    return 0;
}
