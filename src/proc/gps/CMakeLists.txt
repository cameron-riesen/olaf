include_directories (${OLAF_DDS_MSG_SRC_DIR}/cam/config)

add_executable (gps_process gps_main.cpp)

target_link_libraries (gps_process cam_config_msg)

set_target_properties (gps_process PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/proc")