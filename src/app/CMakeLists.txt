project(App)

if(WIN32)
	set(PLATFORM_SOURCES "App_windows.cpp")
elseif(UNIX)
	set(PLATFORM_SOURCES "App_linux.cpp")
endif()
add_library(${PROJECT_NAME}
	${PLATFORM_SOURCES}
)
target_compile_definitions(${PROJECT_NAME} PRIVATE
	FULL_DUMP_INFO
)
if(${BUILD_SHARED_LIBS})
	target_compile_definitions(${PROJECT_NAME} PRIVATE TOP_APP_EXPORTS)
else()
	target_compile_definitions(${PROJECT_NAME} PRIVATE TOP_APP_STATIC)
endif()
target_include_directories(${PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${TOP_INCLUDE}/app>
	$<INSTALL_INTERFACE:include/app>

	$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
	$<INSTALL_INTERFACE:include>
)
