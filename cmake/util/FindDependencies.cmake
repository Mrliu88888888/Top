function(_FIND_TARGET_DEPENDENCIES target output)
	get_target_property(link_libs ${target} LINK_LIBRARIES)
	foreach(link_lib ${link_libs})
		if(link_lib)
			list(APPEND ${output} ${link_lib})
			_FIND_TARGET_DEPENDENCIES(${link_lib} ${output})
		endif()
	endforeach()
	set(${output} ${${output}} PARENT_SCOPE)
endfunction()

function(FIND_TARGET_DEPENDENCIES output)
	foreach(target ${ARGN})
		_FIND_TARGET_DEPENDENCIES(${target} target_dependencies)
	endforeach()
	list(REMOVE_DUPLICATES target_dependencies)
	set(${output} ${target_dependencies} PARENT_SCOPE)
endfunction()

function(FIND_TARGET_LIBRARIES target output)
	foreach(depend_target ${${target}})
		if(TOP_DEBUG)
			get_target_property(depend_location ${depend_target} IMPORTED_LOCATION_DEBUG)
		else()
			get_target_property(depend_location ${depend_target} IMPORTED_LOCATION_RELEASE)
		endif()
		if(depend_location)
			list(APPEND output ${depend_location})
		endif()
	endforeach()
	list(FILTER output EXCLUDE REGEX ".*\\.lib$")
	list(FILTER output EXCLUDE REGEX ".*\\.a$")
	set(${output} ${${output}} PARENT_SCOPE)
endfunction()
