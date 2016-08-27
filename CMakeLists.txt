cmake_minimum_required (VERSION 2.6)
project (Olaf)

SET (CMAKE_CXX_FLAGS "-std=c++11 -Wno-deprecated-declarations")

add_subdirectory (src)
add_subdirectory (test)
add_subdirectory (scripts)
