# if [ -z "$DDS_ROOT" ]; then
#     echo "DDS_ROOT not set."
#     exit 1
# fi

if [ "$#" -ne 1 ]; then
    echo "Generates CMakeLists.txt and .gitignore for an idl file message."
    echo "Usage:"
    echo "  "$0" <file>"
fi

input_file_name="$1"
message_name=$(echo $input_file_name | cut  -f 1 -d '.')
lib_name=`echo "${message_name}" | tr '[:upper:]' '[:lower:]'`

# All the files generated, based off the input file name
test_message_source=${message_name}.cpp
test_message_header=${message_name}.h
test_message_dcps_source=${message_name}Dcps.cpp
test_message_dcps_header=${message_name}Dcps.h
test_message_dcps_impl_source=${message_name}Dcps_impl.cpp
test_message_dcps_impl_header=${message_name}Dcps_impl.h
test_message_spl_dcps_source=${message_name}SplDcps.cpp
test_message_spl_dcps_header=${message_name}SplDcps.h
test_message_dcps_main_header=${message_name}_DCPS.hpp

# CMakeLists.txt
printf "set (IDLPP_OUTPUT \${CMAKE_CURRENT_SOURCE_DIR}/${test_message_source}
                  \${CMAKE_CURRENT_SOURCE_DIR}/${test_message_header}
                  \${CMAKE_CURRENT_SOURCE_DIR}/${test_message_dcps_source}
                  \${CMAKE_CURRENT_SOURCE_DIR}/${test_message_dcps_header}
                  \${CMAKE_CURRENT_SOURCE_DIR}/${test_message_dcps_impl_source}
                  \${CMAKE_CURRENT_SOURCE_DIR}/${test_message_dcps_impl_header}
                  \${CMAKE_CURRENT_SOURCE_DIR}/${test_message_spl_dcps_source}
                  \${CMAKE_CURRENT_SOURCE_DIR}/${test_message_spl_dcps_header}
                  \${CMAKE_CURRENT_SOURCE_DIR}/${test_message_dcps_main_header})\n" >> CMakeLists.txt
printf "\n" >> CMakeLists.txt
printf "add_library (${lib_name} SHARED \${CMAKE_CURRENT_SOURCE_DIR}/${test_message_source}
                               \${CMAKE_CURRENT_SOURCE_DIR}/${test_message_dcps_source}
                               \${CMAKE_CURRENT_SOURCE_DIR}/${test_message_dcps_impl_source}
                               \${CMAKE_CURRENT_SOURCE_DIR}/${test_message_spl_dcps_source})\n" >> CMakeLists.txt
printf "\n" >> CMakeLists.txt
printf "add_custom_command (OUTPUT \${IDLPP_OUTPUT} COMMAND idlpp -l isocpp ${input_file_name} WORKING_DIRECTORY \${CMAKE_CURRENT_SOURCE_DIR} VERBATIM)\n" >> CMakeLists.txt
printf "\n" >> CMakeLists.txt
printf "set_target_properties (${lib_name} PROPERTIES LIBRARY_OUTPUT_DIRECTORY \"\${CMAKE_BINARY_DIR}/lib/msg\")\n" >> CMakeLists.txt

# .gitignore
printf "*\n!.gitignore\n!CMakeLists.txt\n!${input_file_name}" > .gitignore
