include_directories (${CMAKE_SOURCE_DIR}/src/util/ini_parser)

add_executable (ini_parser_tests ini_parser_tests.cpp)

target_link_libraries (ini_parser_tests ini_parser)

set_target_properties (ini_parser_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test/src/util/ini_parser")

file (COPY test_input DESTINATION "${CMAKE_BINARY_DIR}/test/src/util/ini_parser")
