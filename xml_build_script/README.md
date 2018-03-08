### Packages ###

How do we repliace the "Packages" concept from ROS to YARP ? 

1. we don't : just use CMake correctly to include libs, build dependencies etc ... -> assumes all can be build in CMake

2. make an XML file, an XML parser in python, command it to read in the
instructions and use catkin, which uses cmake eventually -> very boring

This is why I haven't developed anything eventually 
