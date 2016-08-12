cmake_minimum_required (VERSION 2.6)
project (Olaf)

#include_directories (${CMAKE_CURRENT_SOURCE_DIR}/messages/camera)

SET (CMAKE_CXX_FLAGS "-std=c++11 -g")

add_subdirectory (src)
add_subdirectory (test)
