function(detect_custom_plugins OUT_PLUGIN_SUBDIRS PLUGINS_FILE)
    # Determine custom plugins: either from file or auto-detect
    if(PLUGINS_FILE AND EXISTS ${PLUGINS_FILE})
        # Parse the custom plugins file to extract directory paths
        file(STRINGS "${PLUGINS_FILE}" PLUGIN_FILE_LINES)
        foreach(LINE ${PLUGIN_FILE_LINES})
            # Look for add_subdirectory or add_custom_vcxproj calls
            # Pattern: add_subdirectory("path") or add_custom_vcxproj("path" ...
            if(LINE MATCHES "add_subdirectory *\\(\"?([^\"\\)]+)\"?\\)")
                set(PLUGIN_PATH "${CMAKE_MATCH_1}")
                # Truncate to plugins/<folder> format
                if(PLUGIN_PATH MATCHES "plugins/([^/]+)")
                    set(PLUGIN_DIR "plugins/${CMAKE_MATCH_1}")
                    list(APPEND ${OUT_PLUGIN_SUBDIRS} "${PLUGIN_DIR}")
                endif()
            endif()
        endforeach()
    else()
        # Auto-detect: glob for all directories in plugins/
        file(GLOB PLUGIN_DIRS "${CMAKE_SOURCE_DIR}/plugins/*/")
        foreach(PLUGIN_DIR ${PLUGIN_DIRS})
            if(IS_DIRECTORY "${PLUGIN_DIR}")
                # Get just the folder name
                get_filename_component(PLUGIN_NAME "${PLUGIN_DIR}" NAME)
                list(APPEND ${OUT_PLUGIN_SUBDIRS} "plugins/${PLUGIN_NAME}")
            endif()
        endforeach()
    endif()

    set(${OUT_PLUGIN_SUBDIRS} "${${OUT_PLUGIN_SUBDIRS}}" PARENT_SCOPE)
endfunction()

# Directories should be relative to CMAKE_SOURCE_DIR
function(build_custom_plugin_directories OUT_CONVERTED_DIRS PLUGIN_DIRS FORCE_VCXPROJ_CONVERSION)
    foreach(PLUGIN_DIR_REL ${PLUGIN_DIRS})
        # Convert relative path to absolute
        set(PLUGIN_DIR "${CMAKE_SOURCE_DIR}/${PLUGIN_DIR_REL}")

        if(NOT IS_DIRECTORY "${PLUGIN_DIR}")
            message(WARNING "Plugin directory does not exist: ${PLUGIN_DIR}")
        elseif(NOT FORCE_VCXPROJ_CONVERSION AND EXISTS "${PLUGIN_DIR}/CMakeLists.txt")
            list(APPEND ${OUT_CONVERTED_DIRS} "${PLUGIN_DIR_REL}")
        else()
            get_filename_component(PLUGIN_NAME "${PLUGIN_DIR}" NAME)
            message(STATUS "Processing plugin directory: ${PLUGIN_NAME}")

            file(GLOB_RECURSE VCXPROJ_FILES "${PLUGIN_DIR}/*.vcxproj")

            # Filter vcxproj files by platform
            set(COMPATIBLE_VCXPROJS "")
            set(CONVERTED_CMAKES "")
            foreach(VCXPROJ_FILE ${VCXPROJ_FILES})
                # Hack this in here
                if(VCXPROJ_FILE MATCHES "ZLib.vcxproj$")
                    message(STATUS "Skipping ZLib")
                else()
                    file(READ "${VCXPROJ_FILE}" VCXPROJ_CONTENT)

                    if(
                    (CMAKE_GENERATOR_PLATFORM STREQUAL "x64" AND VCXPROJ_CONTENT MATCHES "ProjectConfiguration Include=\"[^\"]*\\|x64\"") OR
                    (CMAKE_GENERATOR_PLATFORM STREQUAL "Win32" AND VCXPROJ_CONTENT MATCHES "ProjectConfiguration Include=\"[^\"]*\\|Win32\"")
                    )
                        list(APPEND COMPATIBLE_VCXPROJS "${VCXPROJ_FILE}")
                    else()
                        get_filename_component(PROJECT_NAME "${VCXPROJ_FILE}" NAME_WE)
                        message(STATUS "  Skipping ${PROJECT_NAME} (incompatible platform)")
                    endif()
                endif()
            endforeach()

            if(NOT VCXPROJ_FILES)
                message(STATUS "  No vcxproj files or CMakeLists.txt found in ${PLUGIN_NAME}")
            elseif(NOT COMPATIBLE_VCXPROJS)
                message(STATUS "  No compatible vcxproj files found in ${PLUGIN_NAME}")
            else()
                foreach(VCXPROJ_FILE ${COMPATIBLE_VCXPROJS})
                    get_filename_component(VCXPROJ_DIR "${VCXPROJ_FILE}" DIRECTORY)
                    if(FORCE_VCXPROJ_CONVERSION OR NOT EXISTS "${VCXPROJ_DIR}/CMakeLists.txt")
                        get_filename_component(PROJECT_NAME "${VCXPROJ_FILE}" NAME_WE)
                        message(STATUS "  Converting ${PROJECT_NAME}.vcxproj to CMakeLists.txt...")

                        set(PS_ARGS "-ExecutionPolicy" "Bypass" "-File" "${CMAKE_SOURCE_DIR}/tools/conversions/Convert-VcxprojToCMake.ps1")
                        list(APPEND PS_ARGS "-VcxprojPath" "${VCXPROJ_FILE}" "-GenerateAnalysis" "-SolutionFolder" "external" "-ConvertPropsFiles")

                        if(FORCE_VCXPROJ_CONVERSION)
                            list(APPEND PS_ARGS "-Force")
                        endif()

                        execute_process(
                                COMMAND powershell.exe ${PS_ARGS}
                                WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
                                RESULT_VARIABLE CONVERSION_RESULT
                                OUTPUT_VARIABLE CONVERSION_OUTPUT
                                ERROR_VARIABLE CONVERSION_ERROR
                                OUTPUT_STRIP_TRAILING_WHITESPACE
                                ERROR_STRIP_TRAILING_WHITESPACE
                        )

                        if(NOT CONVERSION_RESULT EQUAL 0)
                            message(WARNING "")
                            message(WARNING "========================================")
                            message(WARNING "VCXPROJ CONVERSION FAILED!")
                            message(WARNING "Project: ${PROJECT_NAME}")
                            message(WARNING "File: ${VCXPROJ_FILE}")
                            message(WARNING "========================================")
                            if(CONVERSION_OUTPUT)
                                message(WARNING "Output: ${CONVERSION_OUTPUT}")
                            endif()
                            if(CONVERSION_ERROR)
                                message(WARNING "Error: ${CONVERSION_ERROR}")
                            endif()
                            message(WARNING "========================================")
                            message(WARNING "")
                        else()
                            message(STATUS "  Successfully converted ${PROJECT_NAME}")
                        endif()
                    endif()

                    if(EXISTS "${VCXPROJ_DIR}/CMakeLists.txt")
                        list(APPEND CONVERTED_CMAKES ${VCXPROJ_DIR})
                    else()
                        message(WARNING "Expected CMakeLists.txt not found after conversion: ${VCXPROJ_DIR}/CMakeLists.txt")
                    endif()
                endforeach()

                if(CONVERTED_CMAKES)
                    if("${PLUGIN_DIR}" IN_LIST CONVERTED_CMAKES)
                        list(REMOVE_ITEM CONVERTED_CMAKES "${PLUGIN_DIR}")
                    elseif(FORCE_VCXPROJ_CONVERSION AND EXISTS "${PLUGIN_DIR}/CMakeLists.txt" AND CONVERTED_CMAKES)
                        file(REMOVE "${PLUGIN_DIR}/CMakeLists.txt")
                    endif()

                    if((FORCE_VCXPROJ_CONVERSION OR NOT EXISTS "${PLUGIN_DIR}/CMakeLists.txt") AND CONVERTED_CMAKES)
                        # Create a master CMakeLists.txt that adds subdirectories
                        message(STATUS "  Adding subdirectories to main CMakeLists.txt for ${PLUGIN_NAME}")

                        set(MASTER_CONTENT "\n# Auto-generated master CMakeLists.txt for ${PLUGIN_NAME}\n")
                        set(MASTER_CONTENT "${MASTER_CONTENT}# This file adds all subdirectories containing CMakeLists.txt\n\n")

                        foreach(DIR ${CONVERTED_CMAKES})
                            file(RELATIVE_PATH REL_PATH ${PLUGIN_DIR} ${DIR})
                            if(NOT REL_PATH STREQUAL "")
                                set(MASTER_CONTENT "${MASTER_CONTENT}add_subdirectory(\"${REL_PATH}\")\n")
                            endif()
                        endforeach()

                        file(APPEND "${PLUGIN_DIR}/CMakeLists.txt" "${MASTER_CONTENT}\n")
                    endif()
                endif()

                if(EXISTS "${PLUGIN_DIR}/CMakeLists.txt")
                    list(APPEND ${OUT_CONVERTED_DIRS} "${PLUGIN_DIR_REL}")
                else()
                    message(WARNING "Expected CMakeLists.txt not found after conversion: ${PLUGIN_DIR}/CMakeLists.txt")
                endif()
            endif()
        endif()
    endforeach()

    set(${OUT_CONVERTED_DIRS} "${${OUT_CONVERTED_DIRS}}" PARENT_SCOPE)
endfunction()

function(write_custom_plugins_file OUTPUT_FILE PLUGIN_FUNCTION PLUGIN_DIRS)
    foreach(SUBDIR ${PLUGIN_DIRS})
        list(APPEND CUSTOM_PLUGIN_COMMANDS "${PLUGIN_FUNCTION} (${SUBDIR})")
    endforeach()

    list(JOIN CUSTOM_PLUGIN_COMMANDS "\n" CUSTOM_PLUGIN_COMMANDS)

    configure_file(
            "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/custom_plugins.cmake.in"
            "${OUTPUT_FILE}"
            @ONLY
    )
endfunction()
