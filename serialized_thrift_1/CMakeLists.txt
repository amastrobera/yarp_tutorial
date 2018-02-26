# Author: Angelo Mastro
cmake_minimum_required(VERSION 3.0)

# find YARP
find_package(YARP REQUIRED)

#cleaning up gitignored files
file(REMOVE_RECURSE ${CMAKE_CURRENT_SOURCE_DIR}/src)
file(REMOVE_RECURSE ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB IndexFiles "${CMAKE_CURRENT_SOURCE_DIR}/*_index*") # workaroud
if(IndexFiles)
    message("removing index files ${IndexFiles}")
    file(REMOVE ${IndexFiles})
endif()
file(GLOB CMakeFiles "${CMAKE_CURRENT_SOURCE_DIR}/*.cmake") 
if(CMakeFiles)
    message("removing cmake files ${CMakeFiles}")
    file(REMOVE ${CMakeFiles})
endif()

set(generated_libs_dir "${CMAKE_CURRENT_SOURCE_DIR}")
yarp_idl_to_dir(SharedData.thrift ${generated_libs_dir} sources headers include_dirs)
include_directories(${include_dirs})

# create the sender
add_executable(server server.cpp ${headers} ${sources})
TARGET_LINK_LIBRARIES(server ${YARP_LIBRARIES})

# create the receiver
add_executable(client client.cpp ${headers} ${sources})
TARGET_LINK_LIBRARIES(client ${YARP_LIBRARIES})



# note on launch/testing
# $ ./client
# $ ./server

# not necessary just for info
# yarp connect /server /client 
