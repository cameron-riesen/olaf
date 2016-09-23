cmake_minimum_required (VERSION 2.6)
project (Olaf)

set (CMAKE_CXX_FLAGS "-pthread -Wno-deprecated-declarations -g")

set (OLAF_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set (OLAF_CONFIG_DIR ${OLAF_ROOT_DIR}/config)
set (OLAF_SRC_DIR ${OLAF_ROOT_DIR}/src)
set (OLAF_DDS_WRAPPER_DIR ${OLAF_ROOT_DIR}/src/dds_wrapper)
set (OLAF_MSG_SRC_DIR ${OLAF_ROOT_DIR}/src/msg)
set (OLAF_PROC_SRC_DIR ${OLAF_ROOT_DIR}/src/proc)
set (OLAF_UTIL_DIR ${OLAF_ROOT_DIR}/src/util)
set (OLAF_TEST_DIR ${OLAF_ROOT_DIR}/test)
set (OLAF_TEST_SRC_DIR ${OLAF_ROOT_DIR}/test/src)

add_subdirectory (src)
add_subdirectory (test)
add_subdirectory (scripts)
