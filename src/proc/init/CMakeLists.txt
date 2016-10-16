include_directories (${OLAF_UTIL_DIR}/ini_parser)
include_directories (${OLAF_DDS_MSG_SRC_DIR}/init/config)

add_executable (initializer_process initializer_main.cpp)

target_link_libraries (initializer_process ini_parser)
target_link_libraries (initializer_process init_config_msg)

set_target_properties (initializer_process PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/proc")