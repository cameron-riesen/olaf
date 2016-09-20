include_directories (${CMAKE_SOURCE_DIR}/src/util/ini_parser)

add_executable (ini_parser_tests ini_parser_tests.cpp)
add_executable (timestamp_tests timestamp_tests.cpp)
add_executable (datestamp_tests datestamp_tests.cpp)

target_link_libraries (ini_parser_tests ini_parser)
target_link_libraries (timestamp_tests ini_parser)
target_link_libraries (datestamp_tests ini_parser)

set_target_properties (ini_parser_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test/src/util/ini_parser")
set_target_properties (timestamp_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test/src/util/ini_parser")
set_target_properties (datestamp_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test/src/util/ini_parser")

file (COPY test_input DESTINATION "${CMAKE_BINARY_DIR}/test/src/util/ini_parser")
