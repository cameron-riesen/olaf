add_executable (gps_process gps_main.cpp)

set_target_properties (gps_process PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/proc")