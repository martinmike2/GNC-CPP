cmake_minimum_required(VERSION 3.13)
project(GNC)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_modules/")

#INCLUDE(FindProtobuf)
#
#FIND_PACKAGE(Protobuf REQUIRED)
FIND_PACKAGE(KRPC REQUIRED)

#INCLUDE_DIRECTORIES(${PROTOBUF_INCLUDE_DIR})
#PROTOBUF_GENERATE_CPP(PROTO_SRC PROTO_HEADER message.proto)
#ADD_LIBRARY(proto ${PROTO_HEADER} ${PROTO_SRC})


set(CMAKE_CXX_STANDARD 14)

add_executable(GNC main.cpp Vector3.cpp Vector3.hpp CSER.cpp CSER.hpp events/Event.hpp events/EventManager.cpp events/EventManager.hpp events/TestEvent.hpp)

target_link_libraries(GNC "-lkrpc -lprotobuf -lpthread")

#target_include_directories(GNC PUBLIC ${Protobuf_INCLUDE_DIRS})
#
#target_link_libraries(GNC ${Protobuf_LIBRARIES})