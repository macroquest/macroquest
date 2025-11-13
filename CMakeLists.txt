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

# Global properties
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Suppress CMake predefined targets in Visual Studio solution
set(CMAKE_SUPPRESS_REGENERATION TRUE)  # Removes ZERO_CHECK target

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

# set up powershell availability to use the vcpkg_mq script
find_program(POWERSHELL_PATH NAMES powershell powershell.exe)
set(VCPKG_MQ_PATH "${CMAKE_CURRENT_SOURCE_DIR}/tools/build_scripts/vcpkg_mq.ps1")

if(NOT DEFINED POWERSHELL_PATH)
    message(WARNING "Could not find powershell, not running vcpkg_mq update")
endif()

function(add_vcxproj PROJECT_LOCATION PROJECT_NAME PROJECT_PREFIX)
    # Optional 4th argument for dependencies
    set(DEPENDENCIES ${ARGN})

    find_file(VCXPROJ_LOCATION NAMES ${PROJECT_NAME}.vcxproj PATHS ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_LOCATION} NO_DEFAULT_PATH REQUIRED)

    if(DEPENDENCIES)
        include_external_msproject(${PROJECT_NAME} ${VCXPROJ_LOCATION} ${DEPENDENCIES})
    else()
        include_external_msproject(${PROJECT_NAME} ${VCXPROJ_LOCATION})
    endif()

    set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER ${PROJECT_PREFIX})
    unset(VCXPROJ_LOCATION CACHE)  # Clear cache to allow next call to search fresh

    if (MQ_BUILD_VCPKG AND POWERSHELL_PATH)
        set(VCPKG_MQ_ARGS -ProjectName "${PROJECT_NAME}" -ProjectDirectory "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_LOCATION}" -MQRoot "${CMAKE_CURRENT_SOURCE_DIR}" -Platform "${VCPKG_ARCH}" -Toolchain "${CMAKE_GENERATOR_TOOLSET}")
        execute_process(
            COMMAND "${POWERSHELL_PATH}" -ExecutionPolicy Bypass -NoProfile -NonInteractive -File "${VCPKG_MQ_PATH}" ${VCPKG_MQ_ARGS}
            COMMAND_ECHO STDOUT
            RESULT_VARIABLE VCPKG_MQ_RESULT
            OUTPUT_VARIABLE VCPKG_MQ_OUTPUT
            ECHO_OUTPUT_VARIABLE
            ERROR_VARIABLE VCPKG_MQ_ERROR
        )

        if (NOT VCPKG_MQ_RESULT EQUAL 0)
            message(FATAL_ERROR "Failed to install vcpkg package with error: ${VCPKG_MQ_ERROR}")
        else()
            message(STATUS "installed vcpkg packages for ${PROJECT_NAME}")
        endif()

        unset(VCPKG_MQ_ARGS CACHE)
        unset(VCPKG_MQ_RESULT CACHE)
        unset(VCPKG_MQ_OUTPUT CACHE)
        unset(VCPKG_MQ_ERROR CACHE)
    endif()
endfunction()

# Add main components
add_vcxproj(src/eqlib eqlib "core")
add_vcxproj(src/main MQ2Main "core")

# Set MQ2Main as the default startup project in Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT MQ2Main)

add_vcxproj(src/imgui imgui "core/libraries")
add_vcxproj(src/routing routing "core/libraries")
add_vcxproj(src/login login "core/libraries")
add_vcxproj(contrib/zep zep "core/libraries")

if(MQ_BUILD_LAUNCHER)
    add_vcxproj(src/loader MacroQuest "core/applications")
endif()

# Add plugins
if(MQ_BUILD_PLUGINS)
    add_vcxproj(src/plugins/autobank MQ2AutoBank "core/plugins")
    add_vcxproj(src/plugins/autologin MQ2AutoLogin "core/plugins")
    add_vcxproj(src/plugins/bzsrch MQ2Bzsrch "core/plugins")
    add_vcxproj(src/plugins/chat MQ2Chat "core/plugins")
    add_vcxproj(src/plugins/chatwnd MQ2ChatWnd "core/plugins")
    add_vcxproj(src/plugins/custombinds MQ2CustomBinds "core/plugins")
    add_vcxproj(src/plugins/eqbugfix MQ2EQBugFix "core/plugins")
    add_vcxproj(src/plugins/hud MQ2HUD "core/plugins")
    add_vcxproj(src/plugins/itemdisplay MQ2ItemDisplay "core/plugins")
    add_vcxproj(src/plugins/labels MQ2Labels "core/plugins")
    add_vcxproj(src/plugins/lua MQ2Lua "core/plugins")
    add_vcxproj(src/plugins/map MQ2Map "core/plugins")
    add_vcxproj(src/plugins/pluginapi pluginapi "core/plugins")
    add_vcxproj(src/plugins/targetinfo MQ2TargetInfo "core/plugins")
    add_vcxproj(src/plugins/xtarinfo MQ2XTarInfo "core/plugins")
endif()

# Add custom plugins from root plugins directory
if(MQ_BUILD_CUSTOM_PLUGINS)
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

                # First pass: count compatible vcxprojs
                set(COMPATIBLE_COUNT 0)
                foreach(VCXPROJ_FILE ${PLUGIN_VCXPROJS})
                    file(READ "${VCXPROJ_FILE}" VCXPROJ_CONTENT)

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

                    if(PLATFORM_MATCH)
                        math(EXPR COMPATIBLE_COUNT "${COMPATIBLE_COUNT} + 1")
                    endif()
                endforeach()

                # Second pass: add projects with appropriate folder structure
                foreach(VCXPROJ_FILE ${PLUGIN_VCXPROJS})
                    # Read the vcxproj file to check if it supports the current architecture
                    file(READ "${VCXPROJ_FILE}" VCXPROJ_CONTENT)

                    # Check if the vcxproj contains the current platform
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

                    if(PLATFORM_MATCH)
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

                        message(STATUS "Adding custom plugin vcxproj: ${PROJECT_NAME} → ${PROJECT_PREFIX}")
                        add_vcxproj(${PROJECT_LOCATION} ${PROJECT_NAME} ${PROJECT_PREFIX} MQ2Main)
                    else()
                        get_filename_component(PROJECT_NAME ${VCXPROJ_FILE} NAME_WE)
                        message(STATUS "Skipping ${PROJECT_NAME} (incompatible architecture)")
                    endif()
                endforeach()
            endif()
        endif()
    endforeach()
endif()

# Add tests
if(MQ_BUILD_TESTS)
    add_vcxproj(src/tests/Actors Actors "core/applications/tests")
    add_vcxproj(src/tests/NamedPipeClient NamedPipeClient "core/applications/tests")
endif()

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