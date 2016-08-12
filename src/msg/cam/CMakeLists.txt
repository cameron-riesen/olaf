set (OPENDDS_IDL_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/CamTestMessageTypeSupport.idl ${CMAKE_CURRENT_SOURCE_DIR}/CamTestMessageTypeSupportImpl.cpp ${CMAKE_CURRENT_SOURCE_DIR}/CamTestMessageTypeSupportImpl.h)
set (TAO_IDL_1_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/CamTestMessageC.cpp ${CMAKE_CURRENT_SOURCE_DIR}/CamTestMessageC.h ${CMAKE_CURRENT_SOURCE_DIR}/CamTestMessageC.inl ${CMAKE_CURRENT_SOURCE_DIR}/CamTestMessageS.cpp ${CMAKE_CURRENT_SOURCE_DIR}/CamTestMessageS.h)
set (TAO_IDL_2_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/CamTestMessageTypeSupportC.cpp ${CMAKE_CURRENT_SOURCE_DIR}/CamTestMessageTypeSupportC.h ${CMAKE_CURRENT_SOURCE_DIR}/CamTestMessageTypeSupportC.inl ${CMAKE_CURRENT_SOURCE_DIR}/CamTestMessageTypeSupportS.cpp ${CMAKE_CURRENT_SOURCE_DIR}/CamTestMessageTypeSupportS.h)

add_library (camtestmessage SHARED ${CMAKE_CURRENT_SOURCE_DIR}/CamTestMessageC.cpp ${CMAKE_CURRENT_SOURCE_DIR}/CamTestMessageS.cpp ${CMAKE_CURRENT_SOURCE_DIR}/CamTestMessageTypeSupportC.cpp ${CMAKE_CURRENT_SOURCE_DIR}/CamTestMessageTypeSupportImpl.cpp ${CMAKE_CURRENT_SOURCE_DIR}/CamTestMessageTypeSupportS.cpp)

add_custom_command (OUTPUT ${OPENDDS_IDL_OUTPUT} COMMAND $ENV{DDS_ROOT}/bin/opendds_idl ${CMAKE_CURRENT_SOURCE_DIR}/CamTestMessage.idl                     WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command (OUTPUT ${TAO_IDL_1_OUTPUT}   COMMAND tao_idl -I$DDS_ROOT -I$TAO_ROOT/orbsvcs ${CMAKE_CURRENT_SOURCE_DIR}/CamTestMessage.idl            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command (OUTPUT ${TAO_IDL_2_OUTPUT}   COMMAND tao_idl -I$DDS_ROOT -I$TAO_ROOT/orbsvcs ${CMAKE_CURRENT_SOURCE_DIR}/CamTestMessageTypeSupport.idl WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
