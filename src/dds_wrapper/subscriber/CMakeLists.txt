add_executable (subscriber DataReaderListenerImpl.cpp Subscriber.cpp)
install (TARGETS subscriber DESTINATION ${CMAKE_BINARY_DIR}/bin)
