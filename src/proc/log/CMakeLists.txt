add_executable (log_process log_main.cpp)

set_target_properties (log_process PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/proc")