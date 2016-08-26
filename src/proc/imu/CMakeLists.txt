add_executable (imu_process imu_main.cpp)

set_target_properties (imu_process PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/proc")