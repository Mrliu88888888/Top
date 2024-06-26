project(LiteRPC)

set(LITE_PROTO_PATH "${CMAKE_CURRENT_SOURCE_DIR}/proto")
set(LITE_PROTO_FILE "lite.proto")
set(LITE_PROTO_OUT_CPP_PATH "${CMAKE_BINARY_DIR}/lite/include")
set(LITE_PROTO_OUT_CPP_FILE "lite.pb.cc")
file(MAKE_DIRECTORY ${LITE_PROTO_OUT_CPP_PATH})
add_custom_command(
	OUTPUT ${LITE_PROTO_OUT_CPP_PATH}/${LITE_PROTO_OUT_CPP_FILE}
	COMMAND ${Protobuf_PROTOC_EXECUTABLE} --cpp_out=${LITE_PROTO_OUT_CPP_PATH} --proto_path=${LITE_PROTO_PATH} ${LITE_PROTO_FILE}
	DEPENDS ${LITE_PROTO_PATH}/${LITE_PROTO_FILE}
)
add_custom_target(LITE_PROTO_CPP ALL DEPENDS ${LITE_PROTO_OUT_CPP_PATH}/${LITE_PROTO_OUT_CPP_FILE})

add_library(${PROJECT_NAME}
	LiteRPC.cpp
)
add_dependencies(${PROJECT_NAME} LITE_PROTO_CPP)
target_compile_definitions(${PROJECT_NAME} PRIVATE SQLITERPC_EXPORTS)
target_include_directories(${PROJECT_NAME} PRIVATE ${LITE_PROTO_OUT_CPP_PATH})
target_link_libraries(${PROJECT_NAME} PRIVATE
	gRPC::grpc++ protobuf::libprotobuf
)
target_include_directories(${PROJECT_NAME} PUBLIC ..)
