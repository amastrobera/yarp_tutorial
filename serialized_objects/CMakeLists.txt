# Author: Angelo Mastro
cmake_minimum_required(VERSION 3.0)

# find YARP
find_package(YARP REQUIRED)

# set up our program and link with yarp
add_executable(client client.cpp ${CMAKE_CURRENT_SOURCE_DIR}/data.hpp)
target_include_directories(client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(client ${YARP_LIBRARIES})

add_executable(server server.cpp ${CMAKE_CURRENT_SOURCE_DIR}/data.hpp)
target_include_directories(server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(server ${YARP_LIBRARIES})

# note on launch/testing
# $ ./client
# $ ./server

# not necessary just for info
# yarp connect /server /client 
