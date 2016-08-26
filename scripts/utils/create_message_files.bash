if [ -z "$DDS_ROOT" ]; then
    echo "DDS_ROOT not set."
    exit 1
fi

if [ "$#" -ne 1 ]; then
    echo "Generates CMakeLists.txt and .gitignore for an idl file message."
    echo "Usage:"
    echo "  "$0" <file>"
fi

input_file_name="$1"
message_name=$(echo $input_file_name | cut  -f 1 -d '.')
lib_name=`echo "${message_name}" | tr '[:upper:]' '[:lower:]'`

# All the files generated, based off the input file name
messageC_source=${message_name}C.cpp
messageC_header=${message_name}C.h
messageC_inl=${message_name}C.inl
messageS_source=${message_name}S.cpp
messageS_header=${message_name}S.h
messageTypeSupport_idl=${message_name}TypeSupport.idl
messageTypeSupportC_source=${message_name}TypeSupportC.cpp
messageTypeSupportC_header=${message_name}TypeSupportC.h
messageTypeSupportC_inl=${message_name}TypeSupportC.inl
messageTypeSupportS_source=${message_name}TypeSupportS.cpp
messageTypeSupportS_header=${message_name}TypeSupportS.h
messageTypeSupportImpl_source=${message_name}TypeSupportImpl.cpp
messageTypeSupportImpl_header=${message_name}TypeSupportImpl.h

printf "set (OPENDDS_IDL_OUTPUT \${CMAKE_CURRENT_SOURCE_DIR}/${messageTypeSupport_idl} \${CMAKE_CURRENT_SOURCE_DIR}/${messageTypeSupportImpl_source} \${CMAKE_CURRENT_SOURCE_DIR}/${messageTypeSupportImpl_header})\n" >> CMakeLists.txt
printf "set (TAO_IDL_1_OUTPUT \${CMAKE_CURRENT_SOURCE_DIR}/${messageC_source} \${CMAKE_CURRENT_SOURCE_DIR}/${messageC_header} \${CMAKE_CURRENT_SOURCE_DIR}/${messageC_inl} \${CMAKE_CURRENT_SOURCE_DIR}/${messageS_source} \${CMAKE_CURRENT_SOURCE_DIR}/${messageS_header})\n" >> CMakeLists.txt
printf "set (TAO_IDL_2_OUTPUT \${CMAKE_CURRENT_SOURCE_DIR}/${messageTypeSupportC_source} \${CMAKE_CURRENT_SOURCE_DIR}/${messageTypeSupportC_header} \${CMAKE_CURRENT_SOURCE_DIR}/${messageTypeSupportC_inl} \${CMAKE_CURRENT_SOURCE_DIR}/${messageTypeSupportS_source} \${CMAKE_CURRENT_SOURCE_DIR}/${messageTypeSupportS_header})\n" >> CMakeLists.txt
printf "\n" >> CMakeLists.txt
printf "add_library (${lib_name} SHARED \${CMAKE_CURRENT_SOURCE_DIR}/${messageC_source} \${CMAKE_CURRENT_SOURCE_DIR}/${messageS_source} \${CMAKE_CURRENT_SOURCE_DIR}/${messageTypeSupportC_source} \${CMAKE_CURRENT_SOURCE_DIR}/${messageTypeSupportImpl_source} \${CMAKE_CURRENT_SOURCE_DIR}/${messageTypeSupportS_source})\n" >> CMakeLists.txt
printf "\n" >> CMakeLists.txt
printf "add_custom_command (OUTPUT \${OPENDDS_IDL_OUTPUT} COMMAND \$ENV{DDS_ROOT}/bin/opendds_idl \${CMAKE_CURRENT_SOURCE_DIR}/${input_file_name}                     WORKING_DIRECTORY \${CMAKE_CURRENT_SOURCE_DIR})\n" >> CMakeLists.txt
printf "add_custom_command (OUTPUT \${TAO_IDL_1_OUTPUT}   COMMAND tao_idl -I\$ENV{DDS_ROOT} -I\$ENV{TAO_ROOT}/orbsvcs \${CMAKE_CURRENT_SOURCE_DIR}/${input_file_name}            WORKING_DIRECTORY \${CMAKE_CURRENT_SOURCE_DIR})\n" >> CMakeLists.txt
printf "add_custom_command (OUTPUT \${TAO_IDL_2_OUTPUT}   COMMAND tao_idl -I\$ENV{DDS_ROOT} -I\$ENV{TAO_ROOT}/orbsvcs \${CMAKE_CURRENT_SOURCE_DIR}/${messageTypeSupport_idl} WORKING_DIRECTORY \${CMAKE_CURRENT_SOURCE_DIR})\n" >> CMakeLists.txt
printf "\n" >> CMakeLists.txt
printf "set_target_properties (${lib_name} PROPERTIES LIBRARY_OUTPUT_DIRECTORY \"\${CMAKE_BINARY_DIR}/lib/msg\")\n" >> CMakeLists.txt

printf "*\n!.gitignore\n!CMakeLists.txt\n!${input_file_name}" > .gitignore
