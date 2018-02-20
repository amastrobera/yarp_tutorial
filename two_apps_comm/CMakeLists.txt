# Author: Angelo Mastro
cmake_minimum_required(VERSION 3.0)

# find YARP
find_package(YARP REQUIRED)

# set up our program and link with yarp
add_executable(client client.cpp)
target_link_libraries(client ${YARP_LIBRARIES})

add_executable(server server.cpp)
target_link_libraries(server ${YARP_LIBRARIES})

# note on launch/testing
# $ ./client
# $ ./server

# not necessary just for info
# yarp connect /server /client 
