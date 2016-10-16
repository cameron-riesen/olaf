set (IDLPP_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/init_config_msg.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/init_config_msg.h
                  ${CMAKE_CURRENT_SOURCE_DIR}/init_config_msgDcps.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/init_config_msgDcps.h
                  ${CMAKE_CURRENT_SOURCE_DIR}/init_config_msgDcps_impl.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/init_config_msgDcps_impl.h
                  ${CMAKE_CURRENT_SOURCE_DIR}/init_config_msgSplDcps.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/init_config_msgSplDcps.h
                  ${CMAKE_CURRENT_SOURCE_DIR}/init_config_msg_DCPS.hpp)

add_library (init_config_msg SHARED ${CMAKE_CURRENT_SOURCE_DIR}/init_config_msg.cpp
                               ${CMAKE_CURRENT_SOURCE_DIR}/init_config_msgDcps.cpp
                               ${CMAKE_CURRENT_SOURCE_DIR}/init_config_msgDcps_impl.cpp
                               ${CMAKE_CURRENT_SOURCE_DIR}/init_config_msgSplDcps.cpp)

add_custom_command (OUTPUT ${IDLPP_OUTPUT} COMMAND idlpp -l isocpp init_config_msg.idl WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} VERBATIM)

set_target_properties (init_config_msg PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/msg")
