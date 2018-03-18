### Introduction ###

* Download and build the YarpJS repo https://github.com/robotology/yarp.js two levels above this one. I have used this path "../../yarp_js_angelo"

### launch from the terminal with interactive RPC client ###

The port /data will provide data to the Client, and will get a reply based on the content

    $ yarp server (t1)
    $ node server.js (t2)
    $ yarp rpc /data (t3)
    $ > coordinates //gives random 3D coordinates (in 0-10 units each)
    $ > path //gives random 3D coordinates path (max 10 points)


### launch from two apps (client/server), not interactive ###

The port /data will provide data to the Client, and will get a reply based on the content

    $ yarp server (t1)
    $ node server.js (t2)
    $ node client.js (t3)
