### Serialized objects with thrift 2 ###

Serialized and trasmitted objects in YARP are called IDL these objects are declared into a trift file, and code is automatically generated to create classes out of it for c++, as explained [here](http://www.yarp.it/thrift_editor.html).

    yarp cmake && cmake . && make
    yarp server (t1)
    ./yarpy (t2)
    
You can set all data of an object (c++ struct) in one go in the Editor

    echo "1 sam (1 2 3)" | yarp write /write /settings  (t3)

Or you can set them one by one in the Editor

    echo 'set name "sam"' | yarp write /write /settings (t3)

Or you can set them via RPC

    yarp rpc /settings (t3)
    >> set id 12
    >> set name tony
    >> set ints (8 9 10 11)

