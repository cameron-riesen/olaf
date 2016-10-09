link_libraries (log4cplus)

include_directories (${DDS_INC_DIRS})
link_directories (${DDS_LIB_DIRS})
link_libraries (${DDS_LIBS})

add_subdirectory (cam)
add_subdirectory (gps)
add_subdirectory (hw_if)
add_subdirectory (imu)
add_subdirectory (init)
