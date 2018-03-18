### YARP serialized objects with thrift 1 ###

Serialized and trasmitted objects in YARP are called IDL these objects are declared into a trift file, and code is automatically generated to create classes out of it for c++, like in this [example](http://www.yarp.it/thrift_tutorial_portable.html)

Once defined your structure in the .trift file build it, and then build the project.

    yarpidl_thrift --gen yarp --out ./ SharedData.trift (to do once)
    cd build && cmake .. && make
    
The run 

    yarp server (t1)
    ./client (t2)
    ./server (t3)
