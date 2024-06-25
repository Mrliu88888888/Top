project(VideoCamera)

add_executable(${PROJECT_NAME}
	"main.cpp"
)
target_include_directories(${PROJECT_NAME} PRIVATE
	${OpenCV_INCLUDE_DIRS}
)
target_link_libraries(${PROJECT_NAME} PRIVATE
	opencv_core opencv_highgui opencv_videoio opencv_imgcodecs opencv_imgproc
)

install(TARGETS
	${PROJECT_NAME}

	RUNTIME
	LIBRARY
	ARCHIVE
)

FIND_TARGET_DEPENDENCIES(TARGET_DEPENDENCIES
	${PROJECT_NAME}
)
FIND_TARGET_LIBRARIES(TARGET_DEPENDENCIES TARGET_LIBRARIES)
if(WIN32)
	set(DEPEND_DLL
		"${EXECUTABLE_OUTPUT_PATH}/libpng16${TOP_DEBUG_LIB_SUFFIX}.dll"
		"${EXECUTABLE_OUTPUT_PATH}/tiff${TOP_DEBUG_LIB_SUFFIX}.dll"
		"${EXECUTABLE_OUTPUT_PATH}/libpng16${TOP_DEBUG_LIB_SUFFIX}.dll"
		"${EXECUTABLE_OUTPUT_PATH}/zlib${TOP_DEBUG_LIB_SUFFIX}1.dll"
		"${EXECUTABLE_OUTPUT_PATH}/libwebpdecoder.dll"
		"${EXECUTABLE_OUTPUT_PATH}/jpeg62.dll"
		"${EXECUTABLE_OUTPUT_PATH}/libwebp.dll"
		"${EXECUTABLE_OUTPUT_PATH}/libsharpyuv.dll"
		"${EXECUTABLE_OUTPUT_PATH}/liblzma.dll"
	)
endif()
install(FILES
	${TARGET_LIBRARIES}
	${DEPEND_DLL}

	DESTINATION bin
)
