project(Log)

add_library(${PROJECT_NAME} "Log.cpp")
if (${BUILD_SHARED_LIBS})
	target_compile_definitions(${PROJECT_NAME} PRIVATE TOP_LOG_EXPORTS)
else ()
	target_compile_definitions(${PROJECT_NAME} PRIVATE TOP_LOG_STATIC)
endif ()
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt spdlog::spdlog)
target_include_directories(${PROJECT_NAME} PUBLIC
	${TOP_INCLUDE}
)
