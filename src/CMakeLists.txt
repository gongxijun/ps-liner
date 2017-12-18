
include_directories(../include)
aux_source_directory(.  DIR_LIB_SRCS)
set(LIBS ${pslite_LINKER_LIBS} gflags glog pslite zmq protobuf)
add_executable(train_liner ${DIR_LIB_SRCS})
target_link_libraries(train_liner ${LIBS})
#target_link_libraries(proto ${PROTOBUF_LIBRARIES})
add_subdirectory("data")