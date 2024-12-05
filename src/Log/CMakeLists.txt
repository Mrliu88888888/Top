project(Log)

add_library(${PROJECT_NAME} "Log.cpp")
target_include_directories(${PROJECT_NAME} PRIVATE ${SIMPLEINI_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)
if(BUILD_SHARED_LIBS)
	target_compile_definitions(${PROJECT_NAME} PRIVATE TOP_EXPORTS)
	target_compile_definitions(${PROJECT_NAME} PUBLIC TOP_SHARED)
endif()
target_include_directories(${PROJECT_NAME} PUBLIC ${TOP_BINARY_INCLUDE} .)
target_link_libraries(${PROJECT_NAME} PUBLIC fmt::fmt)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
