project(clever_name)
cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)
# Set build type if not set.
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
# Set additional flags.
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
# Tell cmake to output binaries here:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
# Tell cmake where to look for *.h files.
include_directories(${PROJECT_SOURCE_DIR}/src)
# Outsource the actual processing to folders.
add_subdirectory(src)
# Must be in the top-most CMakeLists.txt file.
enable_testing()
# Outsource tests to another folder.
add_subdirectory(tests)
