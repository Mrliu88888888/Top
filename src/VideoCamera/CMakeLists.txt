project(VideoCamera)

add_executable(${PROJECT_NAME}
	"main.cpp"
)
target_include_directories(${PROJECT_NAME} PRIVATE
	${OpenCV_INCLUDE_DIRS}
)
target_link_directories(${PROJECT_NAME} PRIVATE
	${OpenCV_LIBS}
)

# opencv_calib3dopencv_coreopencv_dnnopencv_features2dopencv_flannopencv_highguiopencv_imgcodecs
# opencv_imgprocopencv_mlopencv_objdetectopencv_photoopencv_stitchingopencv_videoopencv_videoio
