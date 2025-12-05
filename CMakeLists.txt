cmake_minimum_required(VERSION 3.20)

# ============================================================================
# vcpkg Integration (MUST be set before project() call)
# ============================================================================
# Enable vcpkg integration if available via environment variable
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

# Use the local contrib/vcpkg installation
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/contrib/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

# TODO: move semver here?
project(MacroQuest
    VERSION 3.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# ============================================================================
# Dual-Purpose Build System
# ============================================================================
# This CMake configuration serves two purposes:
#
# 1. PROJECT FILE GENERATION
#    - Generates platform-specific Visual Studio solutions
#    - Solution: build/solution/MacroQuest.sln
#    - Auto-detects architecture from BuildType.h
#    - Regenerate with: .\gen_solution.ps1
#    - Useful when upstream changes occur or CMake files are modified
#
# 2. COMPLETE BUILD CHAIN
#    - Build directly via CMake without opening Visual Studio
#    - Command: cmake --build build/solution --config Release
#    - Ideal for CI/CD pipelines and automated builds
#
# CLEANING:
#    To clean CMake files only:  Remove-Item -Recurse build/solution
#    This preserves compiled binaries in build/bin/
#
# MANUAL GENERATION (if needed):
#    cmake -B build/solution -G "Visual Studio 17 2022" -A x64
# ============================================================================

# Match existing project configurations: Debug, Release, Debug-Static, Release-Static
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Debug-Static;Release-Static" CACHE STRING "Available build configurations" FORCE)

# Validate architecture is specified for Visual Studio generator
if(CMAKE_GENERATOR MATCHES "Visual Studio")
    if(NOT CMAKE_GENERATOR_PLATFORM)
        message(FATAL_ERROR
            "Architecture must be specified with -A flag:\n"
            "  Win32: cmake -B build_win32 -G \"Visual Studio 17 2022\" -A Win32\n"
            "  x64:   cmake -B build_x64 -G \"Visual Studio 17 2022\" -A x64\n"
        )
    endif()

    # Validate only Win32 or x64
    if(NOT CMAKE_GENERATOR_PLATFORM MATCHES "^(Win32|x64)$")
        message(FATAL_ERROR
            "Only Win32 and x64 platforms are supported. Got: ${CMAKE_GENERATOR_PLATFORM}"
        )
    endif()

    message(STATUS "Configuring for platform: ${CMAKE_GENERATOR_PLATFORM}")
endif()

# Build type (for single-configuration generators)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "Debug-Static" "Release-Static")
endif()

# Toolset selection
if(NOT CMAKE_GENERATOR_TOOLSET)
    set(CMAKE_GENERATOR_TOOLSET "v143" CACHE STRING "Choose MSVC toolset." FORCE)
endif()

# Options
option(MQ_BUILD_VCPKG "Build vcpkg deps" ON)
option(MQ_BUILD_PLUGINS "Build built-in plugins" ON)
option(MQ_BUILD_CUSTOM_PLUGINS "Build custom plugins from plugins directory" ON)
option(MQ_BUILD_LAUNCHER "Build MacroQuest loader" ON)
option(MQ_BUILD_TESTS "Build tests" OFF)
option(MQ_ADD_MQ2MAIN_DEPENDENCY "Add MQ2Main as dependency to custom plugins if not present" OFF)

# Global properties
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# vcpkg triplet setup based on platform
if(CMAKE_GENERATOR_PLATFORM STREQUAL "x64")
    set(VCPKG_ARCH "x64" CACHE STRING "")
elseif(CMAKE_GENERATOR_PLATFORM STREQUAL "Win32")
    set(VCPKG_ARCH "x86" CACHE STRING "")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
    # Fallback for non-VS generators
    set(VCPKG_ARCH "x64" CACHE STRING "")
else()
    # Fallback for non-VS generators
    set(VCPKG_ARCH "x86" CACHE STRING "")
endif()

set(VCPKG_TARGET_TRIPLET "${VCPKG_ARCH}-windows-static" CACHE STRING "")

# Initialize global properties to collect vcpkg manifest files
set_property(GLOBAL PROPERTY MQ_VCPKG_MQ_FILES "")
set_property(GLOBAL PROPERTY MQ_VCPKG_MQ_X86_FILES "")
set_property(GLOBAL PROPERTY MQ_VCPKG_MQ_X64_FILES "")

function(list_all_subdirs BASE_DIR FOUND_DIRS)
    file(GLOB_RECURSE FOUND_FILES LIST_DIRECTORIES true "${BASE_DIR}/*")

    set(DIR_LIST ${BASE_DIR})

    foreach(FILE ${FOUND_FILES})
        if(IS_DIRECTORY ${FILE})
            list(APPEND DIR_LIST ${FILE})
        endif()
    endforeach()

    set(${FOUND_DIRS} ${DIR_LIST} PARENT_SCOPE)
endfunction()

function(get_vcxproj_includes VCXPROJ_LOCATION VCXPROJ_INCLUDES)
    # Extract include directories from vcxproj file
    file(READ "${VCXPROJ_LOCATION}" VCXPROJ_CONTENT)
    get_filename_component(VCXPROJ_DIR "${VCXPROJ_LOCATION}" DIRECTORY)

    set(EXTRACTED_INCLUDES "")

    # Find all Include directives
    string(REGEX MATCHALL "<(ClCompile|ClInclude)[^>]*Include\\s*=\\s*\"([^\"]*)\"[^>]*>" INCLUDE_MATCHES "${VCXPROJ_CONTENT}")
    foreach(MATCH ${INCLUDE_MATCHES})
        # This assumes always a relative path without variable expansion, which is true in MQ (because that's how VS adds includes in the UI)
        string(REGEX REPLACE "^<(ClCompile|ClInclude)[^>]*Include\\s*=\\s*\"([^\"]*)\"[^>]*>$" "\\2" INCLUDE "${MATCH}")

        get_filename_component(INCLUDE "${INCLUDE}" ABSOLUTE BASE_DIR "${VCXPROJ_DIR}")

        # Normalize path separators
        string(REPLACE "\\" "/" INCLUDE "${INCLUDE}")

        # Add to list if not already present
        list(FIND EXTRACTED_INCLUDES "${INCLUDE}" INCLUDE_INDEX)
        if(INCLUDE_INDEX EQUAL -1)
            list(APPEND EXTRACTED_INCLUDES "${INCLUDE}")
        endif()
    endforeach ()

    if(EXTRACTED_INCLUDES)
        set(${VCXPROJ_INCLUDES} ${EXTRACTED_INCLUDES} PARENT_SCOPE)
    endif()
endfunction()

function(add_vcxproj PROJECT_LOCATION PROJECT_NAME PROJECT_PREFIX)
    # Optional 4th argument for dependencies
    set(DEPENDENCIES ${ARGN})

    find_file(VCXPROJ_LOCATION NAMES ${PROJECT_NAME}.vcxproj PATHS "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_LOCATION}" NO_DEFAULT_PATH REQUIRED)
    if(VCXPROJ_LOCATION)
        if(DEPENDENCIES)
            include_external_msproject(${PROJECT_NAME} ${VCXPROJ_LOCATION} ${DEPENDENCIES})
        else()
            include_external_msproject(${PROJECT_NAME} ${VCXPROJ_LOCATION})
        endif()

        # add dummy targets so IDEs will index the files
        get_vcxproj_includes(${VCXPROJ_LOCATION} VCXPROJ_SOURCES)
        message(STATUS "Adding ${PROJECT_NAME} from ${VCXPROJ_LOCATION}")

        add_library("VCXPROJ_DUMMY_${PROJECT_NAME}" EXCLUDE_FROM_ALL ${VCXPROJ_SOURCES})
        set_target_properties("VCXPROJ_DUMMY_${PROJECT_NAME}" PROPERTIES LINKER_LANGUAGE CXX)

        set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER ${PROJECT_PREFIX})
        unset(VCXPROJ_LOCATION CACHE)  # Clear cache to allow next call to search fresh


        # Collect vcpkg manifest files for later merging
        if(MQ_BUILD_VCPKG)
            set(PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_LOCATION}")

            # Check for vcpkg_mq.txt
            if(EXISTS "${PROJECT_DIR}/vcpkg_mq.txt")
                get_property(EXISTING_FILES GLOBAL PROPERTY MQ_VCPKG_MQ_FILES)
                list(APPEND EXISTING_FILES "${PROJECT_DIR}/vcpkg_mq.txt")
                set_property(GLOBAL PROPERTY MQ_VCPKG_MQ_FILES "${EXISTING_FILES}")
            endif()

            # Check for vcpkg_mq_x86.txt
            if(EXISTS "${PROJECT_DIR}/vcpkg_mq_x86.txt")
                get_property(EXISTING_FILES GLOBAL PROPERTY MQ_VCPKG_MQ_X86_FILES)
                list(APPEND EXISTING_FILES "${PROJECT_DIR}/vcpkg_mq_x86.txt")
                set_property(GLOBAL PROPERTY MQ_VCPKG_MQ_X86_FILES "${EXISTING_FILES}")
            endif()

            # Check for vcpkg_mq_x64.txt
            if(EXISTS "${PROJECT_DIR}/vcpkg_mq_x64.txt")
                get_property(EXISTING_FILES GLOBAL PROPERTY MQ_VCPKG_MQ_X64_FILES)
                list(APPEND EXISTING_FILES "${PROJECT_DIR}/vcpkg_mq_x64.txt")
                set_property(GLOBAL PROPERTY MQ_VCPKG_MQ_X64_FILES "${EXISTING_FILES}")
            endif()
        endif()
    else()
        MESSAGE(WARNING "Attempted to include non-existent vcxproj ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_LOCATION}/${PROJECT_NAME}.vcxproj")
    endif()
endfunction()

function(finalize_vcpkg_installation)
    if(MQ_BUILD_VCPKG)
        # set up powershell availability to use the vcpkg_mq script
        find_program(POWERSHELL_PATH NAMES powershell powershell.exe)
        set(VCPKG_MQ_PATH "${CMAKE_CURRENT_SOURCE_DIR}/tools/build_scripts/vcpkg_mq.ps1")

        if(POWERSHELL_PATH)
            # Create build directory for merged manifest files
            set(VCPKG_MANIFEST_DIR "${CMAKE_CURRENT_BINARY_DIR}/vcpkg_manifests")
            file(MAKE_DIRECTORY "${VCPKG_MANIFEST_DIR}")

            # Helper function to merge manifest files
            function(merge_manifest_files FILE_LIST OUTPUT_FILE)
                if(FILE_LIST)
                    # Use indexed variables: PKG_KEY_N and PKG_FEATURES_N
                    set(PKG_COUNT 0)

                    foreach(MANIFEST_FILE ${FILE_LIST})
                        if(EXISTS "${MANIFEST_FILE}")
                            file(STRINGS "${MANIFEST_FILE}" FILE_LINES)
                            foreach(LINE ${FILE_LINES})
                                # Skip empty lines and comments
                                string(STRIP "${LINE}" STRIPPED_LINE)
                                if(STRIPPED_LINE AND NOT STRIPPED_LINE MATCHES "^#")
                                    # Parse package format: package[feature1,feature2]:triplet
                                    # Extract package name (before [ or :)
                                    string(REGEX REPLACE "([^:\\[]+).*" "\\1" PACKAGE_NAME "${STRIPPED_LINE}")

                                    # Extract features (between [ and ])
                                    set(FEATURES "")
                                    if(STRIPPED_LINE MATCHES "\\[(.+)\\]")
                                        string(REGEX REPLACE ".*\\[(.+)\\].*" "\\1" FEATURES "${STRIPPED_LINE}")
                                    endif()

                                    # Extract triplet (after :)
                                    set(TRIPLET "")
                                    if(STRIPPED_LINE MATCHES ":([^:]+)$")
                                        string(REGEX REPLACE ".*:([^:]+)$" "\\1" TRIPLET "${STRIPPED_LINE}")
                                    endif()

                                    # Create key
                                    if(TRIPLET)
                                        set(KEY "${PACKAGE_NAME}:${TRIPLET}")
                                    else()
                                        set(KEY "${PACKAGE_NAME}")
                                    endif()

                                    # Find existing entry
                                    set(FOUND_INDEX -1)
                                    if(PKG_COUNT GREATER 0)
                                        math(EXPR LAST_PKG "${PKG_COUNT} - 1")
                                        foreach(I RANGE ${LAST_PKG})
                                            if(PKG_KEY_${I} STREQUAL KEY)
                                                set(FOUND_INDEX ${I})
                                                break()
                                            endif()
                                        endforeach()
                                    endif()

                                    if(FOUND_INDEX EQUAL -1)
                                        # New entry
                                        set(PKG_KEY_${PKG_COUNT} "${KEY}")
                                        set(PKG_FEATURES_${PKG_COUNT} "${FEATURES}")
                                        math(EXPR PKG_COUNT "${PKG_COUNT} + 1")
                                    else()
                                        # Merge features
                                        if(FEATURES)
                                            set(EXISTING "${PKG_FEATURES_${FOUND_INDEX}}")
                                            # Split into lists for dedup
                                            if(EXISTING)
                                                string(REPLACE "," ";" EXISTING_LIST "${EXISTING}")
                                            else()
                                                set(EXISTING_LIST "")
                                            endif()
                                            string(REPLACE "," ";" NEW_LIST "${FEATURES}")
                                            # Add new features
                                            foreach(FEATURE ${NEW_LIST})
                                                string(STRIP "${FEATURE}" FCLEAN)
                                                list(FIND EXISTING_LIST "${FCLEAN}" FIDX)
                                                if(FIDX EQUAL -1)
                                                    list(APPEND EXISTING_LIST "${FCLEAN}")
                                                endif()
                                            endforeach()
                                            # Convert back
                                            list(JOIN EXISTING_LIST "," MERGED)
                                            set(PKG_FEATURES_${FOUND_INDEX} "${MERGED}")
                                        endif()
                                    endif()
                                endif()
                            endforeach()
                        endif()
                    endforeach()

                    # Build output
                    set(OUTPUT_LINES "")
                    if(PKG_COUNT GREATER 0)
                        math(EXPR LAST_PKG "${PKG_COUNT} - 1")
                        foreach(I RANGE ${LAST_PKG})
                            set(KEY "${PKG_KEY_${I}}")
                            set(FEATURES "${PKG_FEATURES_${I}}")

                            # Split key
                            if(KEY MATCHES "^([^:]+):(.+)$")
                                string(REGEX REPLACE "^([^:]+):(.+)$" "\\1" PKG "${KEY}")
                                string(REGEX REPLACE "^([^:]+):(.+)$" "\\2" TRP "${KEY}")
                                if(FEATURES)
                                    set(OUTPUT_LINE "${PKG}[${FEATURES}]:${TRP}")
                                else()
                                    set(OUTPUT_LINE "${PKG}:${TRP}")
                                endif()
                            else()
                                if(FEATURES)
                                    set(OUTPUT_LINE "${KEY}[${FEATURES}]")
                                else()
                                    set(OUTPUT_LINE "${KEY}")
                                endif()
                            endif()

                            list(APPEND OUTPUT_LINES "${OUTPUT_LINE}")
                        endforeach()
                    endif()

                    # Write output
                    if(OUTPUT_LINES)
                        list(JOIN OUTPUT_LINES "\n" MERGED_TEXT)
                        file(WRITE "${OUTPUT_FILE}" "${MERGED_TEXT}\n")
                        message(STATUS "Created merged manifest: ${OUTPUT_FILE}")
                    endif()
                endif()
            endfunction()

            # Merge each type of manifest file
            get_property(MQ_FILES GLOBAL PROPERTY MQ_VCPKG_MQ_FILES)
            get_property(X86_FILES GLOBAL PROPERTY MQ_VCPKG_MQ_X86_FILES)
            get_property(X64_FILES GLOBAL PROPERTY MQ_VCPKG_MQ_X64_FILES)

            merge_manifest_files("${MQ_FILES}" "${VCPKG_MANIFEST_DIR}/vcpkg_mq.txt")
            merge_manifest_files("${X86_FILES}" "${VCPKG_MANIFEST_DIR}/vcpkg_mq_x86.txt")
            merge_manifest_files("${X64_FILES}" "${VCPKG_MANIFEST_DIR}/vcpkg_mq_x64.txt")

            # Execute vcpkg once with merged manifests
            message(STATUS "")
            message(STATUS "Installing vcpkg packages for MacroQuest...")

            set(VCPKG_MQ_ARGS
                    -ProjectName "MacroQuest"
                    -ProjectDirectory "${VCPKG_MANIFEST_DIR}"
                    -MQRoot "${CMAKE_CURRENT_SOURCE_DIR}"
                    -Platform "${VCPKG_ARCH}"
                    -Toolchain "${CMAKE_GENERATOR_TOOLSET}"
            )

            execute_process(
                    COMMAND "${POWERSHELL_PATH}" -ExecutionPolicy Bypass -NoProfile -NonInteractive -File "${VCPKG_MQ_PATH}" ${VCPKG_MQ_ARGS}
                    COMMAND_ECHO STDOUT
                    RESULT_VARIABLE VCPKG_MQ_RESULT
                    OUTPUT_VARIABLE VCPKG_MQ_OUTPUT
                    ECHO_OUTPUT_VARIABLE
                    ERROR_VARIABLE VCPKG_MQ_ERROR
            )

            if(NOT VCPKG_MQ_RESULT EQUAL 0)
                message(FATAL_ERROR "Failed to install vcpkg packages with error: ${VCPKG_MQ_ERROR}")
            else()
                message(STATUS "Successfully installed all vcpkg packages")
            endif()
        else()
            message(WARNING "Could not find powershell, not running vcpkg_mq update")
        endif()
    endif()
endfunction()

# Specify any include directories here
list_all_subdirs("${CMAKE_CURRENT_SOURCE_DIR}/include" MQ_INCLUDE_DIRS)
include_directories(${MQ_INCLUDE_DIRS})

# These could all be in their respective subdirectories, but prefer in this case a single
# file to specify the entire core project since everything here is maintained with
# bespoke vcxproj and prop files without CMakeLists.txt to build projects.

# Add main components
add_vcxproj(src/eqlib eqlib "core")
add_vcxproj(src/imgui imgui "core/libraries")
add_vcxproj(src/routing routing "core/libraries")
add_vcxproj(src/login login "core/libraries")
add_vcxproj(contrib/zep zep "core/libraries")
add_vcxproj(src/main MQ2Main "core" eqlib imgui routing zep)

# Set MQ2Main as the default startup project in Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT MQ2Main)

if(MQ_BUILD_LAUNCHER)
    add_vcxproj(src/loader MacroQuest "core/applications" imgui login routing)
endif()

# Add plugins
if(MQ_BUILD_PLUGINS)
    add_vcxproj(src/plugins/pluginapi pluginapi "core/plugins" routing)
    add_vcxproj(src/plugins/autobank MQ2AutoBank "core/plugins" pluginapi MQ2Main)
    add_vcxproj(src/plugins/autologin MQ2AutoLogin "core/plugins" login pluginapi MQ2Main)
    add_vcxproj(src/plugins/bzsrch MQ2Bzsrch "core/plugins" pluginapi MQ2Main)
    add_vcxproj(src/plugins/chat MQ2Chat "core/plugins" pluginapi MQ2Main)
    add_vcxproj(src/plugins/chatwnd MQ2ChatWnd "core/plugins" pluginapi MQ2Main)
    add_vcxproj(src/plugins/custombinds MQ2CustomBinds "core/plugins" pluginapi MQ2Main)
    add_vcxproj(src/plugins/eqbugfix MQ2EQBugFix "core/plugins" pluginapi MQ2Main)
    add_vcxproj(src/plugins/hud MQ2HUD "core/plugins" pluginapi MQ2Main)
    add_vcxproj(src/plugins/itemdisplay MQ2ItemDisplay "core/plugins" pluginapi MQ2Main)
    add_vcxproj(src/plugins/labels MQ2Labels "core/plugins" pluginapi MQ2Main)
    add_vcxproj(src/plugins/lua MQ2Lua "core/plugins" imgui pluginapi MQ2Main)
    add_vcxproj(src/plugins/map MQ2Map "core/plugins" pluginapi MQ2Main)
    add_vcxproj(src/plugins/targetinfo MQ2TargetInfo "core/plugins" pluginapi MQ2Main)
    add_vcxproj(src/plugins/xtarinfo MQ2XTarInfo "core/plugins" pluginapi MQ2Main)
endif()

# Add custom plugins from root plugins directory
if(MQ_BUILD_CUSTOM_PLUGINS)
    include(plugins.cmake)
endif()

# Add tests
if(MQ_BUILD_TESTS)
    add_vcxproj(src/tests/Actors Actors "core/applications/tests")
    add_vcxproj(src/tests/NamedPipeClient NamedPipeClient "core/applications/tests")
endif()

# Finalize vcpkg installation - merge all manifests and install packages, must be called after all add_vcxproj
finalize_vcpkg_installation()

# Print configuration summary
message(STATUS "")
message(STATUS "MacroQuest Configuration Summary:")
message(STATUS "  Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "  MSVC Toolchain: ${CMAKE_GENERATOR_TOOLSET}")
message(STATUS "  C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "  Build Plugins: ${MQ_BUILD_PLUGINS}")
message(STATUS "  Build Custom Plugins: ${MQ_BUILD_CUSTOM_PLUGINS}")
message(STATUS "  Build Loader: ${MQ_BUILD_LAUNCHER}")
message(STATUS "  Build Tests: ${MQ_BUILD_TESTS}")
message(STATUS "")