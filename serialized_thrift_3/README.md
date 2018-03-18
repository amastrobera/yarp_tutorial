### Serialized objects with thrift ###

Serialized and trasmitted objects in YARP are called IDL. These objects are declared into a trift file, and code is automatically generated to create classes out of it for c++ as explained [here](http://www.yarp.it/thrift_editor.html)

#### version 1: command line client, running server ####

    mkdir build && cd build
    cmake ..
    yarp server (t1)
    ./server (t2)
    yarp rpc /server (t3)
        >> get_path
            Response: ((1 7 4) (5 2 0)) "path 1"
        >> set_path_cost 3 // the server window (t2) will display 3

#### version 2: running client and server ####

    mkdir build && cd build
    cmake ..
    yarp server (t1)
    ./server (t2)
    ./client (t3)
