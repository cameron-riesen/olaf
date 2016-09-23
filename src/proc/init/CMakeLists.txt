include_directories (${OLAF_UTIL_DIR}/ini_parser)

add_executable (initializer_process initializer_main.cpp)

target_link_libraries (initializer_process ini_parser)

set_target_properties (initializer_process PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/proc")