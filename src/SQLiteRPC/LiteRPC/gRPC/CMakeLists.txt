project(LiteRPC)

set(LITE_PROTO "${CMAKE_CURRENT_SOURCE_DIR}/proto/lite.proto")
set(LITE_PROTO_CPP_DIR "${CMAKE_BINARY_DIR}/lite/proto")
add_custom_command(
	OUTPUT ${LITE_PROTO_CPP_DIR}
	COMMAND ${Protobuf_PROTOC_EXECUTABLE} --cpp_out=${LITE_PROTO_CPP_DIR} ${LITE_PROTO}
	DEPENDS ${LITE_PROTO}
)
add_custom_target(LITE_PROTO_CPP ALL DEPENDS ${LITE_PROTO_CPP_DIR})

add_library(${PROJECT_NAME}
	LiteRPC.cpp
)
add_dependencies(${PROJECT_NAME} LITE_PROTO_CPP)
