project(src)

add_subdirectory(main)
add_subdirectory(app)
add_subdirectory(log)

if(WIN32)
	set(TOP_LIB_SUFFIX "")
endif()
set(INSTALL_TARGET_LIST
	main
	${TOP_LIB_PREFIX}App${TOP_LIB_SUFFIX}
	${TOP_LIB_PREFIX}Log${TOP_LIB_SUFFIX}
)
install(TARGETS
	${INSTALL_TARGET_LIST}

	RUNTIME DESTINATION bin
	LIBRARY DESTINATION bin
)
