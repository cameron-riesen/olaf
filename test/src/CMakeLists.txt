add_executable (firstTest test.cpp)

set_target_properties (firstTest PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/test")