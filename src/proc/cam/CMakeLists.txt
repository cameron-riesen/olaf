add_executable (camera_process camera_main.cpp)

target_link_libraries (camera_process runtime_logger infomessage)

set_target_properties (camera_process PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/proc")