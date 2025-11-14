function(extract_guid VCXPROJ_PATH VCXPROJ_GUID)
    if(EXISTS "${VCXPROJ_PATH}")
        file(READ "${VCXPROJ_PATH}" VCXPROJ_CONTENT)
        if(VCXPROJ_CONTENT MATCHES "<ProjectGuid>\\{([^}]+)\\}</ProjectGuid>")
            set(${VCXPROJ_GUID} "${CMAKE_MATCH_1}" PARENT_SCOPE)
        else()
            message(WARNING "Could not extract GUID from ${VCXPROJ_PATH}")
        endif()
    else()
        message(WARNING "Could not find ${VCXPROJ_PATH}")
    endif()
endfunction()

set(MQ2MAIN_VCXPROJ "${CMAKE_SOURCE_DIR}/src/main/MQ2Main.vcxproj")
extract_guid("${MQ2MAIN_VCXPROJ}" MQ2MAIN_GUID)

set(PLUGINAPI_VCXPROJ "${CMAKE_SOURCE_DIR}/src/plugins/pluginapi/pluginapi.vcxproj")
extract_guid("${PLUGINAPI_VCXPROJ}" PLUGINAPI_GUID)

# Function to add MQ2Main dependency to custom plugin vcxproj files
function(add_mq2main_dependency_to_vcxproj VCXPROJ_FILE)
    function(amend_vcxproj TARGET_VCXPROJ DEP_VCXPROJ GUID)
        file(READ "${TARGET_VCXPROJ}" CONTENT)

        get_filename_component(DEP_PROJ_NAME "${DEP_VCXPROJ}" NAME_WE)
        if(NOT CONTENT MATCHES "${DEP_PROJ_NAME}\\.vcxproj")
            # Calculate relative path from plugin to Dep
            get_filename_component(DIR "${TARGET_VCXPROJ}" DIRECTORY)
            file(RELATIVE_PATH REL "${DIR}" "${DEP_VCXPROJ}")
            string(REPLACE "/" "\\" REL "${REL}")

            # Build ProjectReference XML with proper indentation
            set(REF "    <ProjectReference Include=\"${REL}\">\n      <Project>{${GUID}}</Project>\n    </ProjectReference>\n")

            # Insert reference into the vcxproj file
            if(CONTENT MATCHES "<ItemGroup>[^<]*<ProjectReference")
                # Has ItemGroup with ProjectReference - add after opening ProjectReference tag
                string(FIND "${CONTENT}" "    <ProjectReference" POS)
                string(SUBSTRING "${CONTENT}" 0 ${POS} BEFORE)
                string(SUBSTRING "${CONTENT}" ${POS} -1 AFTER)
                set(CONTENT "${BEFORE}${REF}${AFTER}")
            else()
                # No ProjectReference ItemGroup - create one before </Project>
                string(FIND "${CONTENT}" "</Project>" POS)
                string(SUBSTRING "${CONTENT}" 0 ${POS} BEFORE)
                string(SUBSTRING "${CONTENT}" ${POS} -1 AFTER)
                set(CONTENT "${BEFORE}  <ItemGroup>\n${REF}  </ItemGroup>\n${AFTER}")
            endif()

            get_filename_component(PROJ_NAME "${TARGET_VCXPROJ}" NAME_WE)
            message(STATUS "Added ${DEP_PROJ_NAME} dependency to ${PROJ_NAME}")
            file(WRITE "${TARGET_VCXPROJ}" "${CONTENT}")
        endif()
    endfunction()

    if(MQ_ADD_MQ2MAIN_DEPENDENCY)
        amend_vcxproj("${VCXPROJ_FILE}" "${MQ2MAIN_VCXPROJ}" "${MQ2MAIN_GUID}")
        amend_vcxproj("${VCXPROJ_FILE}" "${PLUGINAPI_VCXPROJ}" "${PLUGINAPI_GUID}")
    endif()
endfunction()

# Scan for custom plugins in the plugins directory
file(GLOB CUSTOM_PLUGIN_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/plugins/*/")
foreach(PLUGIN_DIR ${CUSTOM_PLUGIN_DIRS})
    if(IS_DIRECTORY ${PLUGIN_DIR})
        get_filename_component(PLUGIN_NAME ${PLUGIN_DIR} NAME)

        if(EXISTS "${PLUGIN_DIR}/CMakeLists.txt")
            # Priority 1: Check if the plugin has a top-level CMakeLists.txt TODO: this is completely untested
            message(STATUS "Found custom plugin with CMakeLists.txt: ${PLUGIN_NAME}")
            add_subdirectory(${PLUGIN_DIR})
            # Set folder for the target (assuming target name matches plugin name)
            if(TARGET ${PLUGIN_NAME})
                set_property(TARGET ${PLUGIN_NAME} PROPERTY FOLDER "external")
                # Add dependency on MQ2Main
                add_dependencies(${PLUGIN_NAME} MQ2Main)
            endif()
        else()
            # Priority 2: Find all vcxproj files recursively
            file(GLOB_RECURSE PLUGIN_VCXPROJS "${PLUGIN_DIR}/*.vcxproj")

            # Filter compatible vcxprojs and memoize results
            set(COMPATIBLE_VCXPROJS "")
            foreach(VCXPROJ_FILE ${PLUGIN_VCXPROJS})
                file(READ "${VCXPROJ_FILE}" VCXPROJ_CONTENT)

                # Check platform compatibility
                set(PLATFORM_MATCH FALSE)
                if(CMAKE_GENERATOR_PLATFORM STREQUAL "x64")
                    if(VCXPROJ_CONTENT MATCHES "ProjectConfiguration Include=\"[^\"]*\\|x64\"")
                        set(PLATFORM_MATCH TRUE)
                    endif()
                elseif(CMAKE_GENERATOR_PLATFORM STREQUAL "Win32")
                    if(VCXPROJ_CONTENT MATCHES "ProjectConfiguration Include=\"[^\"]*\\|Win32\"")
                        set(PLATFORM_MATCH TRUE)
                    endif()
                endif()

                # Check toolset compatibility (must explicitly match)
                set(TOOLSET_MATCH FALSE)
                set(VCXPROJ_TOOLSET "")
                if(VCXPROJ_CONTENT MATCHES "<PlatformToolset>([^<]+)</PlatformToolset>")
                    string(REGEX MATCH "<PlatformToolset>([^<]+)</PlatformToolset>" TOOLSET_TAG "${VCXPROJ_CONTENT}")
                    string(REGEX REPLACE "<PlatformToolset>([^<]+)</PlatformToolset>" "\\1" VCXPROJ_TOOLSET "${TOOLSET_TAG}")
                    if(VCXPROJ_TOOLSET STREQUAL CMAKE_GENERATOR_TOOLSET)
                        set(TOOLSET_MATCH TRUE)
                    endif()
                endif()

                # Add to compatible list or report skip reason
                if(PLATFORM_MATCH AND TOOLSET_MATCH)
                    list(APPEND COMPATIBLE_VCXPROJS "${VCXPROJ_FILE}")
                else()
                    get_filename_component(PROJECT_NAME ${VCXPROJ_FILE} NAME_WE)
                    if(NOT PLATFORM_MATCH)
                        message(STATUS "Skipping ${PROJECT_NAME} (incompatible platform)")
                    elseif(NOT TOOLSET_MATCH)
                        if(VCXPROJ_TOOLSET)
                            message(STATUS "Skipping ${PROJECT_NAME} (incompatible toolset: ${VCXPROJ_TOOLSET} != ${CMAKE_GENERATOR_TOOLSET})")
                        else()
                            message(STATUS "Skipping ${PROJECT_NAME} (no toolset specified, defaults to v100)")
                        endif()
                    endif()
                endif()
            endforeach()

            # Add compatible projects with appropriate folder structure
            list(LENGTH COMPATIBLE_VCXPROJS COMPATIBLE_COUNT)
            foreach(VCXPROJ_FILE ${COMPATIBLE_VCXPROJS})
                # Modify vcxproj to add MQ2Main dependency if requested
                add_mq2main_dependency_to_vcxproj("${VCXPROJ_FILE}")

                # Extract project name from vcxproj filename
                get_filename_component(PROJECT_NAME ${VCXPROJ_FILE} NAME_WE)

                # Get directory containing the vcxproj
                get_filename_component(VCXPROJ_DIR ${VCXPROJ_FILE} DIRECTORY)

                # Build the project location relative to CMAKE_CURRENT_SOURCE_DIR
                file(RELATIVE_PATH PROJECT_LOCATION ${CMAKE_CURRENT_SOURCE_DIR} ${VCXPROJ_DIR})

                # Determine folder structure based on number of compatible projects
                if(COMPATIBLE_COUNT EQUAL 1)
                    # Single project: place directly in external folder
                    set(PROJECT_PREFIX "external")
                else()
                    # Multiple projects: organize under external/PluginName/...
                    # Get relative path from PLUGIN_DIR to vcxproj directory
                    file(RELATIVE_PATH RELATIVE_PATH ${PLUGIN_DIR} ${VCXPROJ_DIR})

                    if(RELATIVE_PATH STREQUAL "" OR RELATIVE_PATH STREQUAL ".")
                        set(PROJECT_PREFIX "external/${PLUGIN_NAME}")
                    else()
                        # Replace backslashes with forward slashes for folder hierarchy
                        string(REPLACE "\\" "/" RELATIVE_PATH_CLEAN ${RELATIVE_PATH})
                        set(PROJECT_PREFIX "external/${PLUGIN_NAME}/${RELATIVE_PATH_CLEAN}")
                    endif()
                endif()

                add_vcxproj(${PROJECT_LOCATION} ${PROJECT_NAME} ${PROJECT_PREFIX} MQ2Main)
            endforeach()
        endif()
    endif()
endforeach()
