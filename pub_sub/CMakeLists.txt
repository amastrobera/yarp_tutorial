cmake_minimum_required(VERSION 3.5)

set (CMAKE_CXX_STANDARD 11)

find_package(YARP REQUIRED)

# 1. autogenerate thrift cpp/h files
yarp_idl_to_dir(${CMAKE_CURRENT_SOURCE_DIR}/communication.thrift
                ${CMAKE_CURRENT_SOURCE_DIR}/build
                sources headers include_dirs)

# 2. build the server: generates points
include_directories(${include_dirs})
add_executable(publisher publisher.cpp ${sources} ${headers})
TARGET_LINK_LIBRARIES(publisher ${YARP_LIBRARIES})

# 3. build the client: uses points to calculate the best path
include_directories(${include_dirs})
add_executable(subscriber subscriber.cpp ${sources} ${headers})
TARGET_LINK_LIBRARIES(subscriber ${YARP_LIBRARIES})
