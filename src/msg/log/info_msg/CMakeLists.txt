set (OPENDDS_IDL_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/InfoMessageTypeSupport.idl ${CMAKE_CURRENT_SOURCE_DIR}/InfoMessageTypeSupportImpl.cpp ${CMAKE_CURRENT_SOURCE_DIR}/InfoMessageTypeSupportImpl.h)
set (TAO_IDL_1_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/InfoMessageC.cpp ${CMAKE_CURRENT_SOURCE_DIR}/InfoMessageC.h ${CMAKE_CURRENT_SOURCE_DIR}/InfoMessageC.inl ${CMAKE_CURRENT_SOURCE_DIR}/InfoMessageS.cpp ${CMAKE_CURRENT_SOURCE_DIR}/InfoMessageS.h)
set (TAO_IDL_2_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/InfoMessageTypeSupportC.cpp ${CMAKE_CURRENT_SOURCE_DIR}/InfoMessageTypeSupportC.h ${CMAKE_CURRENT_SOURCE_DIR}/InfoMessageTypeSupportC.inl ${CMAKE_CURRENT_SOURCE_DIR}/InfoMessageTypeSupportS.cpp ${CMAKE_CURRENT_SOURCE_DIR}/InfoMessageTypeSupportS.h)

add_library (infomessage SHARED ${CMAKE_CURRENT_SOURCE_DIR}/InfoMessageC.cpp ${CMAKE_CURRENT_SOURCE_DIR}/InfoMessageS.cpp ${CMAKE_CURRENT_SOURCE_DIR}/InfoMessageTypeSupportC.cpp ${CMAKE_CURRENT_SOURCE_DIR}/InfoMessageTypeSupportImpl.cpp ${CMAKE_CURRENT_SOURCE_DIR}/InfoMessageTypeSupportS.cpp)

add_custom_command (OUTPUT ${OPENDDS_IDL_OUTPUT} COMMAND $ENV{DDS_ROOT}/bin/opendds_idl ${CMAKE_CURRENT_SOURCE_DIR}/InfoMessage.idl                     WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command (OUTPUT ${TAO_IDL_1_OUTPUT}   COMMAND tao_idl -I$ENV{DDS_ROOT} -I$ENV{TAO_ROOT}/orbsvcs ${CMAKE_CURRENT_SOURCE_DIR}/InfoMessage.idl            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command (OUTPUT ${TAO_IDL_2_OUTPUT}   COMMAND tao_idl -I$ENV{DDS_ROOT} -I$ENV{TAO_ROOT}/orbsvcs ${CMAKE_CURRENT_SOURCE_DIR}/InfoMessageTypeSupport.idl WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties (infomessage PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/msg")
