# ============================================================================
# vcpkg Overlay Manifest Generator for MacroQuest
# ============================================================================
# Creates vcpkg overlay ports from vcpkg_mq*.txt files, enabling proper
# dependency management with dynamic plugin discovery.
#
# This system:
# 1. Scans specified directories for vcpkg_mq*.txt files
# 2. Creates overlay ports for each directory with dependencies
# 3. Generates portfile.cmake for each overlay port (empty package)
# 4. Creates main vcpkg.json with overlay-ports configuration
# 5. Adds all overlay ports as dependencies
#
# Usage:
#   include(cmake/vcpkg_manifest.cmake)
#   create_vcpkg_overlays(
#       PORTS eqlib MQ2AASpend MQ2Nav lua loader
#       OUTPUT_DIR "${CMAKE_BINARY_DIR}"
#       FORCE_REBUILD OFF
#   )
# ============================================================================

cmake_minimum_required(VERSION 3.20)

# Format package entries as JSON dependencies array content
function(format_packages_as_json PACKAGE_ENTRIES OUT_JSON)
    set(FORMATTED_ENTRIES "")
    foreach(ENTRY ${PACKAGE_ENTRIES})
        string(REPLACE "," ";" PACKAGE_LIST ${ENTRY})
        list(LENGTH PACKAGE_LIST PACKAGE_COUNT)
        if(PACKAGE_COUNT GREATER 1)
            # there are features, need to create a json entry
            list(POP_FRONT PACKAGE_LIST PACKAGE_NAME)

            list(TRANSFORM PACKAGE_LIST PREPEND "\"")
            list(TRANSFORM PACKAGE_LIST APPEND "\"")
            list(JOIN PACKAGE_LIST ", " FEATURE_LIST)

            list(APPEND FORMATTED_ENTRIES "      { \"name\": \"${PACKAGE_NAME}\", \"features\": [ ${FEATURE_LIST} ] }")
        else()
            # no features, just add the entry directly
            list(APPEND FORMATTED_ENTRIES "      \"${ENTRY}\"")
        endif()
    endforeach()

    list(JOIN FORMATTED_ENTRIES ",\n" JSON_CONTENT)
    set(${OUT_JSON} "${JSON_CONTENT}" PARENT_SCOPE)
endfunction()

# Format discarded triplets as JSON array content
function(format_list_as_json LIST OUT_JSON)
    list(TRANSFORM LIST PREPEND "      \"")
    list(TRANSFORM LIST APPEND "\"")
    list(JOIN LIST ",\n" JSON_CONTENT)
    set(${OUT_JSON} "${JSON_CONTENT}" PARENT_SCOPE)
endfunction()

# Merge package entries with the same name, combining features
function(merge_package_entries PACKAGE_ENTRIES OUT_MERGED)
    set(PACKAGES, "")
    foreach(ENTRY ${PACKAGE_ENTRIES})
        string(REPLACE "," ";" PACKAGE_LIST ${ENTRY})
        list(POP_FRONT PACKAGE_LIST PACKAGE_NAME)
        if(NOT DEFINED PACKAGE_${PACKAGE_NAME})
            # haven't seen this package before, set it to an empty list since there are no features
            set(PACKAGE_${PACKAGE_NAME} "")
            list(APPEND PACKAGES ${PACKAGE_NAME})
        endif()

        list(REMOVE_ITEM PACKAGE_LIST "core")

        list(LENGTH PACKAGE_LIST PACKAGE_COUNT)
        if(PACKAGE_COUNT GREATER 0)
            # there are features, parse them and merge into list that is guaranteed to exist at this point
            list(APPEND PACKAGE_${PACKAGE_NAME} ${PACKAGE_LIST})
            list(REMOVE_DUPLICATES PACKAGE_${PACKAGE_NAME})
        endif()
    endforeach()

    set(MERGED_ENTRIES "")
    foreach(PACKAGE ${PACKAGES})
        list(LENGTH PACKAGE_${PACKAGE} PACKAGE_COUNT)
        if(PACKAGE_COUNT GREATER 0)
            list(JOIN PACKAGE_${PACKAGE} "," PACKAGE_LIST)
            string(APPEND PACKAGE ",${PACKAGE_LIST}")
        endif()
        list(APPEND MERGED_ENTRIES ${PACKAGE})
    endforeach()

    set(${OUT_MERGED} "${MERGED_ENTRIES}" PARENT_SCOPE)
endfunction()

# Parse vcpkg_mq*.txt files from a directory and all subdirectories
function(parse_vcpkg_mq_files PORT_DIR MQ_FILES OUT_PACKAGES OUT_DIRS)
    foreach(MQ_FILE ${MQ_FILES})
        get_filename_component(MQ_DIR ${MQ_FILE} DIRECTORY)
        list(APPEND MQ_DIRS ${MQ_DIR})
    endforeach()

    list(REMOVE_DUPLICATES MQ_DIRS)

    foreach(MQ_DIR ${MQ_DIRS})
        file(RELATIVE_PATH PORT "${PORT_DIR}/.." ${MQ_DIR})
        string(REGEX REPLACE "[\\\\/]" "-" PORT ${PORT})
        string(TOLOWER ${PORT} PORT)

        set(ALL_PACKAGES "")
        set(ALL_DISCARDED "")

        file(GLOB MQ_FILES "${MQ_DIR}/vcpkg_mq*.txt")

        foreach(MQ_FILE ${MQ_FILES})
            file(STRINGS "${MQ_FILE}" FILE_LINES)
            foreach(LINE ${FILE_LINES})
                # Skip empty lines and comments
                string(STRIP "${LINE}" STRIPPED_LINE)
                if(STRIPPED_LINE AND NOT STRIPPED_LINE MATCHES "^#")
                    # Parse package format: package[feature1,feature2]:triplet
                    set(PACKAGE_NAME "")
                    set(FEATURES "")
                    set(TRIPLET "")

                    # Extract package name
                    if(STRIPPED_LINE MATCHES "^([^:\\[]+)")
                        set(PACKAGE_NAME "${CMAKE_MATCH_1}")
                        string(STRIP "${PACKAGE_NAME}" PACKAGE_NAME)
                    endif()

                    # Extract features (between [ and ])
                    if(STRIPPED_LINE MATCHES "\\[(.+)\\]")
                        set(FEATURES "${CMAKE_MATCH_1}")

                        # Features are split by comma, transform them into a list and trim the entries
                        string(REPLACE "," ";" FEATURE_LIST "${FEATURES}")
                        list(TRANSFORM FEATURE_LIST STRIP)
                        list(JOIN FEATURE_LIST "," FEATURES)
                    endif()

                    # Extract triplet (after :), for logging that it's discarded
                    if(STRIPPED_LINE MATCHES ":([^:]+)$")
                        set(TRIPLET "${CMAKE_MATCH_1}")
                        string(STRIP "${TRIPLET}" TRIPLET)
                    endif()

                    if(PACKAGE_NAME)
                        # Create package entry: name,feature1,feature2;...
                        set(PKG_ENTRY "${PACKAGE_NAME}")
                        if(FEATURES)
                            string(APPEND PKG_ENTRY ",${FEATURES}")
                        endif()
                        list(APPEND ALL_PACKAGES "${PKG_ENTRY}")

                        # Track discarded triplets
                        if(TRIPLET)
                            list(APPEND ALL_DISCARDED "${STRIPPED_LINE}")
                        endif()
                    endif()
                endif()
            endforeach()
        endforeach()
        # Write each vcpkg.json colocated with the vcxproj (same as vcpkg_mq.txt files)

        # create the package name for the template (we will always be producing a file)
        set(VCPKG_NAME ${PORT})

        if(ALL_PACKAGES)
            list(REMOVE_DUPLICATES ALL_PACKAGES)

            if(ALL_DISCARDED)
                list(REMOVE_DUPLICATES ALL_DISCARDED)
            endif()

            # Format as JSON for template
            format_packages_as_json("${ALL_PACKAGES}" VCPKG_DEPENDENCIES)
            format_list_as_json("${ALL_DISCARDED}" DISCARDED_TRIPLETS)

            # Write vcpkg.json for this port
            configure_file(
                    "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/vcpkg.json.in"
                    "${MQ_DIR}/vcpkg.json"
                    @ONLY
            )

            list(APPEND FINAL_PACKAGES ${PORT})
            list(APPEND FINAL_DIRS ${MQ_DIR})
        endif()
    endforeach()

    set(${OUT_PACKAGES} "${FINAL_PACKAGES}" PARENT_SCOPE)
    set(${OUT_DIRS} "${FINAL_DIRS}" PARENT_SCOPE)
endfunction()

# Main function to parse vcpkg overlay ports and create the final manifest
function(create_vcpkg_overlays)
    cmake_parse_arguments(
        OVERLAY
        "FORCE_REBUILD"  # Boolean options
        "OUTPUT_DIR"  # Single-value options
        "PORTS"  # Multi-value options
        ${ARGN}
    )

    if(NOT OVERLAY_OUTPUT_DIR)
        message(FATAL_ERROR "create_vcpkg_overlays: OUTPUT_DIR is required")
    endif()

    if(NOT OVERLAY_PORTS)
        message(FATAL_ERROR "create_vcpkg_overlays: PORTS is required")
    endif()

    # overlays are a static value, but depend on CMAKE_SOURCE_DIR, so set them here
    # TODO: This could actually be passed, should it?
    set(VCPKG_OVERLAY_PORTS_PATH
            "${CMAKE_SOURCE_DIR}/src"
            "${CMAKE_SOURCE_DIR}/src/plugins"
            "${CMAKE_SOURCE_DIR}/src/tests"
            "${CMAKE_SOURCE_DIR}/contrib"
            "${CMAKE_SOURCE_DIR}/plugins"
    )

    # Track all created ports for final manifest
    # The initial ports list are the ports that are used solution-wide, so should be included in the solution
    set(ALL_PORTS spdlog fmt detours)
    set(PORTS_DIRS "")
    foreach(PORT ${OVERLAY_PORTS})
        foreach(PATH ${VCPKG_OVERLAY_PORTS_PATH})
            set(PORT_DIR "${PATH}/${PORT}")
            string(TOLOWER ${PORT} PORT_LOWER)
            if(IS_DIRECTORY ${PORT_DIR})
                if((OVERLAY_FORCE_REBUILD AND PATH STREQUAL "${CMAKE_SOURCE_DIR}/plugins") OR NOT EXISTS "${PORT_DIR}/vcpkg.json")
                    # first, grab all legacy mq manifests
                    file(GLOB_RECURSE MQ_FILES "${PORT_DIR}/*")
                    # this is a bit naive because we could filter by architecture, but that doesn't seem to be useful
                    list(FILTER MQ_FILES INCLUDE REGEX ".*vcpkg_mq.*\.txt$")

                    # finally, create the file from the template. add the port only if legacy files exist to process
                    if(MQ_FILES)
                        message(STATUS "  Processing vcpkg dependencies: ${PORT_DIR}")

                        # Parse all vcpkg_mq files found
                        parse_vcpkg_mq_files(${PORT_DIR} "${MQ_FILES}" OUT_PACKAGES OUT_DIRS)

                        list(APPEND ALL_PORTS ${OUT_PACKAGES})
                        list(APPEND PORT_DIRS ${OUT_DIRS})
                    elseif(EXISTS "${PORT_DIR}/vcpkg.json")
                        # force rebuild was specified, but there were no MQ_FILES and the manifest exists
                        message(STATUS "  Reusing vcpkg dependencies: ${PORT_DIR}")
                        list(APPEND ALL_PORTS ${PORT_LOWER})
                        list(APPEND PORT_DIRS ${PORT_DIR})
                    elseif(OVERLAY_FORCE_REBUILD)
                        # only display this message if a force was specified
                        message(STATUS "  Found empty vcpkg dependencies: ${PORT_DIR}")
                    endif()
                elseif(EXISTS "${PORT_DIR}/vcpkg.json")
                    list(APPEND ALL_PORTS ${PORT_LOWER})
                    list(APPEND PORT_DIRS ${PORT_DIR})
                endif()
            endif()
        endforeach()
    endforeach()

    foreach(PORT_DIR ${PORT_DIRS})
        if(EXISTS "${PORT_DIR}/vcpkg.json" AND NOT EXISTS "${PORT_DIR}/portfile.cmake")
            # Ensure portfile.cmake exists if the manifest does
            configure_file(
                    "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/portfile.cmake.in"
                    "${PORT_DIR}/portfile.cmake"
                    @ONLY
            )
        endif()
    endforeach()

    # Format final dependencies as JSON array (there are explicitly no features here, so just use a list)
    format_list_as_json("${ALL_PORTS}" VCPKG_DEPENDENCIES)
    configure_file(
            "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/vcpkg_final.json.in"
            "${OVERLAY_OUTPUT_DIR}/vcpkg.json"
            @ONLY
    )

    # Format overlay ports path as JSON array, always include our project-level custom ports
    list(APPEND PORT_DIRS "${CMAKE_SOURCE_DIR}/contrib/vcpkg-ports")
    format_list_as_json("${PORT_DIRS}" VCPKG_OVERLAY_PORTS_PATH)
    configure_file(
            "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/vcpkg-configuration.json.in"
            "${OVERLAY_OUTPUT_DIR}/vcpkg-configuration.json"
            @ONLY
    )

    list(LENGTH ALL_PORTS PORT_COUNT)
    message(STATUS "Created main vcpkg manifest with ${PORT_COUNT} overlay ports")

    # Set vcpkg manifest mode and directory (must be set in parent scope)
    set(VCPKG_MANIFEST_DIR "${OVERLAY_OUTPUT_DIR}" PARENT_SCOPE)
    set(VCPKG_MANIFEST_MODE ON PARENT_SCOPE)
endfunction()