project(src)

add_subdirectory(main)
add_subdirectory(qmain)
add_subdirectory(app)
add_subdirectory(conv)
add_subdirectory(log)

install(TARGETS
	main
	qmain

	RUNTIME
	LIBRARY
	ARCHIVE
)
install(TARGETS
	App
	Conv
	Log

	EXPORT TopConfig
	RUNTIME
	LIBRARY
	ARCHIVE
)
install(DIRECTORY
	${TOP_INCLUDE}

	DESTINATION .
)
install(EXPORT TopConfig
    FILE TopConfig.cmake
    NAMESPACE Top::
    DESTINATION share/Top
)

function (deploy target output)
	get_target_property(LINK_LIBS ${target} LINK_LIBRARIES)

	foreach (LINK_LIB IN LISTS LINK_LIBS)
		if (TARGET ${LINK_LIB})
			list(APPEND ${output} ${LINK_LIB})
			deploy(${LINK_LIB} ${output})
		endif ()
	endforeach ()

	set(${output} ${${output}} PARENT_SCOPE)
endfunction ()

deploy(main LIBS)
deploy(qmain LIBS)
deploy(App LIBS)
deploy(Conv LIBS)
deploy(Log LIBS)
list(REMOVE_DUPLICATES LIBS)
message(-----------${LIBS})

foreach(lib IN LISTS LIBS)
    if (TARGET ${lib})
        if (TOP_DEBUG)
            get_target_property(dll_path ${lib} IMPORTED_LOCATION_DEBUG)
        else ()
            get_target_property(dll_path ${lib} IMPORTED_LOCATION_RELEASE)
        endif ()
        if (dll_path)
            install(FILES ${dll_path} DESTINATION bin)
        endif()
    endif()
endforeach()
