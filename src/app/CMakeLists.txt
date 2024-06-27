project(App)

add_library(${PROJECT_NAME}
	platform/${TOP_PLATFORM}/App.cpp
)
if(BUILD_SHARED_LIBS)
	target_compile_definitions(${PROJECT_NAME} PRIVATE TOP_EXPORTS)
	target_compile_definitions(${PROJECT_NAME} PUBLIC TOP_SHARED)
endif()
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_BINARY_DIR}/include")
target_include_directories(${PROJECT_NAME} PUBLIC .)
