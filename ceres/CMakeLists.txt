cmake_minimum_required(VERSION 3.0)

project(ceres_tutorial)

find_package(Ceres REQUIRED)

include_directories(${CERES_INCLUDE_DIRS})
message("CERES_LIBRARIES = ${CERES_LIBRARIES}")


# hello world
add_executable(helloworld helloworld.cc)
target_link_libraries(helloworld ${CERES_LIBRARIES})
add_executable(helloworld_anlytic helloworld_anlytic.cc)
target_link_libraries(helloworld_anlytic ${CERES_LIBRARIES})

# powell 
add_executable(powell powell.cc)
target_link_libraries(powell ${CERES_LIBRARIES})