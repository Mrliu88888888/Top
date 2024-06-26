function(COPY_TARGET_DEPENDENCIES target)
	set(TARGET_LIST ${${target}})
	install(CODE
		"
		foreach(tag ${TARGET_LIST})
			execute_process(COMMAND
				\"${CMAKE_SOURCE_DIR}/script/linux/depend.sh\"
				\"${EXECUTABLE_OUTPUT_PATH}/\${tag}\"
				\"${CMAKE_INSTALL_PREFIX}/bin\"
			)
		endforeach()
		"
	)
endfunction()
