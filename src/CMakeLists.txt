project(src)

add_subdirectory(Log)
if(USE_QT_GUI)
	add_subdirectory(Top)
	DEPLOYQT(Top) 
endif()
 
install(DIRECTORY
	${EXECUTABLE_OUTPUT_PATH}/

	DESTINATION bin
	FILES_MATCHING
	PATTERN "*"
	PATTERN "*.exp" EXCLUDE
	PATTERN "*.ilk" EXCLUDE
	PATTERN "*.lib" EXCLUDE
	PATTERN "*.pdb" EXCLUDE
	PATTERN "*.a" EXCLUDE
	PATTERN "test_*" EXCLUDE
	PATTERN "gtest*" EXCLUDE

	PATTERN "*.log" EXCLUDE
	PATTERN "*.autosave" EXCLUDE
	PATTERN "*.cache" EXCLUDE
	PATTERN "*.pid" EXCLUDE
	PATTERN "*.lock" EXCLUDE
	PATTERN "vc_redist.x64.exe" EXCLUDE
)

if(UNIX)
	find_library(LIBSTDCXX libstdc++.so HINTS ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})
	if(LIBSTDCXX)
		get_filename_component(LIBSTDCXX_REALPATH ${LIBSTDCXX} REALPATH)
		get_filename_component(LIBSTDCXX_NAME ${LIBSTDCXX_REALPATH} NAME)
		string(REGEX REPLACE "(\\.so\\.[0-9]+).*" "\\1" LIBSTDCXX_LINK_NAME ${LIBSTDCXX_NAME})
		if(LIBSTDCXX_REALPATH)
			install(FILES ${LIBSTDCXX_REALPATH} DESTINATION bin)
			if(NOT EXISTS ${LIBRARY_OUTPUT_PATH}/${LIBSTDCXX_LINK_NAME})
				execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink
					${LIBSTDCXX_NAME} ${LIBSTDCXX_LINK_NAME}
					WORKING_DIRECTORY ${LIBRARY_OUTPUT_PATH}
				)
			endif()
		else()
			message(FATAL_ERROR "libstdc++ realpath not found!")
		endif()
	else()
		message(FATAL_ERROR "libstdc++ not found!")
	endif()
	 
	if(USE_QT_GUI)
		install(TARGETS Top)
	endif()
endif()
