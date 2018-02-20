# Author: Angelo Mastro
cmake_minimum_required(VERSION 3.0)

# find YARP
find_package(YARP REQUIRED)

# set up our program and link with yarp
add_executable(summer summer.cpp)
target_link_libraries(summer ${YARP_LIBRARIES})

# note on launch/testing
# $ yarp server
# $ yarp write /write /read
# $ yarp read /read
# $ ./summer
# $ yarp connect /write /summer 
# $ yarp connect /summer /read
