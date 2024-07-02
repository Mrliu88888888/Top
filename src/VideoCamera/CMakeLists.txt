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

	RUNTIME DESTINATION ${PROJECT_NAME}
)
