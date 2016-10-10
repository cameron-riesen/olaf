include_directories (${OLAF_DDS_MSG_SRC_DIR}/cam/config)

add_executable (camera_process camera_main.cpp)

target_link_libraries (camera_process cam_config_msg)

set_target_properties (camera_process PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/proc")