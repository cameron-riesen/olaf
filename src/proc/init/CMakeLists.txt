add_executable (initializer_process initializer_main.cpp)

set_target_properties (initializer_process PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/proc")