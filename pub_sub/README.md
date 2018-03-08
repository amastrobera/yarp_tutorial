### Publisher / Subscriber in YAR ###

The reference is (time time) only the doxygen of
[Subscriber](http://www.yarp.it/classyarp_1_1os_1_1Subscriber.html) and
[Publisher](http://www.yarp.it/classyarp_1_1os_1_1Publisher.html). The usual [thrift portable](http://www.yarp.it/thrift_tutorial_portable.html)
objects can help understand. 

#### build ####

    mkdir build && cd build
    cmake .. && make -j4

#### run ####

    yarp server (t1)
    ./publisher (t2)
    ./subscriber (t3)
