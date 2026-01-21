# This file just includes common functions that can be used by any project
include_guard()

# This is not used, but keep it for reference if we need to go to the old pch methodology
function(use_pch SOURCE_FILES PCH_H PCH_CPP)
    foreach(src_file ${SOURCE_FILES})
        if(NOT "${src_file}" MATCHES "${PCH_CPP}$")
            # Configure all source files that aren't pch.cpp to USE the precompiled header
            set_source_files_properties(${src_file} PROPERTIES
                    COMPILE_FLAGS "/Yu${PCH_H}"
            )
        else()
            # Configure pch.cpp to CREATE the precompiled header
            set_source_files_properties(${src_file} PROPERTIES
                    COMPILE_FLAGS "/Yc${PCH_H}"
            )
        endif()
    endforeach()
endfunction()

function(source_groups BASE_GROUP)
    foreach (src ${ARGN})
        cmake_path(GET src PARENT_PATH relative_dir)
        if(IS_ABSOLUTE "${relative_dir}")
            file(RELATIVE_PATH relative_dir ${CMAKE_CURRENT_LIST_DIR} ${relative_dir})
        endif()
        string(REGEX REPLACE "(\\.\\./)+" "external/" relative_dir "${relative_dir}")
        string(REGEX REPLACE "\\.\\." "external" relative_dir "${relative_dir}")
        if (relative_dir)
            source_group("${BASE_GROUP}/${relative_dir}" FILES "${src}")
        endif()
    endforeach()
endfunction()

function(target_remove_properties TARGET_NAME PROPERTIES_LIST)
    get_target_property(target_properties ${TARGET_NAME} "${PROPERTIES_LIST}")
    if(target_properties)
        foreach(remove_property ${ARGN})
            string(REGEX REPLACE "([][+.*()^\\$])" "\\\\\\1" escaped_string "${remove_property}")
            # We want to remove explicit options only, not part of the conditions in a generator
            # expression. Therefore, we know that the option must be preceeded by nothing, colon,
            # or comma, and that it must be followed by nothing, comma, or right angle bracket
            list(FILTER target_properties EXCLUDE REGEX "(^|[:,])${escaped_string}($|[,\>])")
        endforeach ()

        set_target_properties(${TARGET_NAME} PROPERTIES "${PROPERTIES_LIST}" "${target_properties}")
    endif()
endfunction()

function(target_remove_compile_definitions TARGET_NAME)
    target_remove_properties(${TARGET_NAME} COMPILE_DEFINITIONS ${ARGN})
endfunction()

function(target_remove_include_directories TARGET_NAME)
    target_remove_properties(${TARGET_NAME} INCLUDE_DIRECTORIES ${ARGN})
endfunction()

function(target_remove_compile_options TARGET_NAME)
    target_remove_properties(${TARGET_NAME} COMPILE_OPTIONS ${ARGN})
endfunction()

function(target_remove_link_directories TARGET_NAME)
    target_remove_properties(${TARGET_NAME} LINK_DIRECTORIES ${ARGN})
endfunction()

function(target_remove_link_libraries TARGET_NAME)
    target_remove_properties(${TARGET_NAME} INTERFACE_LINK_LIBRARIES ${ARGN})
endfunction()

function(target_remove_link_options TARGET_NAME)
    target_remove_properties(${TARGET_NAME} LINK_OPTIONS ${ARGN})
endfunction()