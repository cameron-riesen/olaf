include_directories ($ENV{ACE_ROOT})
include_directories ($ENV{TAO_ROOT})
include_directories ($ENV{DDS_ROOT})
include_directories ($ENV{DDS_ROOT})

link_directories ($ENV{ACE_ROOT}/lib)
link_directories ($ENV{DDS_ROOT}/lib)

link_libraries (OpenDDS_Tcp)
link_libraries (OpenDDS_InfoRepoDiscovery)
link_libraries (OpenDDS_Dcps)
link_libraries (TAO_PortableServer)
link_libraries (TAO_AnyTypeCode)
link_libraries (TAO)
link_libraries (ACE)

add_subdirectory (msg)
add_subdirectory (dds_wrapper)
add_subdirectory (proc)