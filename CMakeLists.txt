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
#    - Useful when upstream changes occur to the solution
#
# 2. COMPLETE BUILD CHAIN
#    - Build directly via CMake without opening Visual Studio
#    - Command: cmake --build build/solution --config Release
#    - Ideal for CI/CD pipelines and automated builds
#
# CLEANING:
#    To clean CMake files only:  Remove-Item -Recurse build
#    where build is the build directory.
#
# MANUAL GENERATION (if needed):
#    cmake -B build/solution -G "Visual Studio 17 2022" -A x64
# ============================================================================

# TODO: Fix the loader cmake

cmake_minimum_required(VERSION 3.30)

# ============================================================================
# Requirements checks
# ============================================================================
# Only Visual Studio generators make sense for MQ due to architecture restrictions
if(NOT CMAKE_GENERATOR MATCHES "Visual Studio")
    message(FATAL_ERROR "Only Visual Studio generators are viable for MacroQuest compilation")
endif()

# Validate architecture is specified for Visual Studio generator
# vcpkg triplet setup MUST be before project() call, do it here because it's convenient
# Determine architecture from CMAKE_GENERATOR_PLATFORM (set by -A flag)
if(CMAKE_GENERATOR_PLATFORM STREQUAL "x64")
    set(VCPKG_TARGET_TRIPLET "x64-windows-static" CACHE STRING "")
    set(VCPKG_ARCH "x64" CACHE STRING "")
elseif(CMAKE_GENERATOR_PLATFORM STREQUAL "Win32")
    set(VCPKG_TARGET_TRIPLET "x86-windows-static" CACHE STRING "")
    set(VCPKG_ARCH "x86" CACHE STRING "")
elseif(NOT CMAKE_GENERATOR_PLATFORM)
    message(FATAL_ERROR
            "Architecture must be specified with -A flag:\n"
            "  Win32: cmake -B build_win32 -G \"Visual Studio 17 2022\" -A Win32\n"
            "  x64:   cmake -B build_x64 -G \"Visual Studio 17 2022\" -A x64\n"
    )
else()
    message(FATAL_ERROR
            "Only Win32 and x64 platforms are supported. Got: ${CMAKE_GENERATOR_PLATFORM}"
    )
endif()

set(VCPKG_INSTALL_OPTIONS "--allow-unsupported")

message(STATUS "Configuring for platform: ${CMAKE_GENERATOR_PLATFORM}")

# ============================================================================
# Options
# ============================================================================
option(MQ_REGENERATE_SOLUTION "Just generate a macroquest solution file from vcxproj files" OFF)
option(MQ_BUILD_PLUGINS "Build built-in plugins" ON)
option(MQ_BUILD_CUSTOM_PLUGINS "Build custom plugins from plugins directory" OFF)
option(MQ_BUILD_LAUNCHER "Build MacroQuest loader" OFF)
option(MQ_STATIC_BUILD "Change build type for core libraries to static" OFF)
option(MQ_BUILD_TESTS "Build tests" OFF)
option(MQ_ADD_MQ2MAIN_DEPENDENCY "Add MQ2Main as dependency to custom plugins if not present" OFF)
option(MQ_FORCE_VCXPROJ_CONVERSION "Force reconversion of vcxproj files even if CMakeLists.txt exists" OFF)
option(MQ_FORCE_OVERLAY_REBUILD "Force rebuild of vcpkg.json files in projects that have legacy vcpkg manifests" OFF)

# Custom plugin configuration options
set(MQ_CUSTOM_PLUGINS_FILE "" CACHE FILEPATH "Path to a CMake file that adds custom plugins (overrides auto-detection)")
set(MQ_WRITE_PLUGINS_FILE "" CACHE FILEPATH "Write auto-detected plugins as a CMake file (generated from scan)")

# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Suppress developer warnings (occurs in some vcpkg configs)
if(NOT DEFINED CMAKE_SUPPRESS_DEVELOPER_WARNINGS)
    set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1 CACHE INTERNAL "No dev warnings")
endif()

# Solution-wide shared config
include(cmake/common.cmake)
include(cmake/plugins.cmake)

# ============================================================================
# Define all subdirectories to include in the build
# This list is used for both vcpkg overlay generation and add_subdirectory calls
# ============================================================================
set(MQ_CORE_SUBDIRS
    "src/eqlib"
    "src/imgui"
    "src/routing"
    "src/login"
    "src/main"
    "contrib/zep"
)

set(MQ_LAUNCHER_SUBDIRS
    "src/loader"
)

set(MQ_PLUGIN_SUBDIRS
    "src/plugins/pluginapi"
    "src/plugins/autobank"
    "src/plugins/autologin"
    "src/plugins/bzsrch"
    "src/plugins/chat"
    "src/plugins/chatwnd"
    "src/plugins/custombinds"
    "src/plugins/eqbugfix"
    "src/plugins/hud"
    "src/plugins/itemdisplay"
    "src/plugins/labels"
    "src/plugins/lua"
    "src/plugins/map"
    "src/plugins/targetinfo"
    "src/plugins/xtarinfo"
)

set(MQ_TEST_SUBDIRS
    "src/tests/Actors"
    "src/tests/NamedPipeClient"
)

set(MQ_ALL_SUBDIRS ${MQ_CORE_SUBDIRS})

if (MQ_BUILD_LAUNCHER)
    list(APPEND MQ_ALL_SUBDIRS ${MQ_LAUNCHER_SUBDIRS})
endif()

if (MQ_BUILD_PLUGINS)
    list(APPEND MQ_ALL_SUBDIRS ${MQ_PLUGIN_SUBDIRS})
endif()

if (MQ_BUILD_TESTS)
    list(APPEND MQ_ALL_SUBDIRS ${MQ_TEST_SUBDIRS})
endif()

if (MQ_BUILD_CUSTOM_PLUGINS)
    if(MQ_CUSTOM_PLUGINS_FILE)
        get_filename_component(MQ_CUSTOM_PLUGINS_FILE ${MQ_CUSTOM_PLUGINS_FILE} ABSOLUTE)
    endif()

    detect_custom_plugins(MQ_CUSTOM_PLUGIN_SUBDIRS ${MQ_CUSTOM_PLUGINS_FILE})

    # Add custom plugin subdirs to the main list, after converting if needed
    if(MQ_CUSTOM_PLUGIN_SUBDIRS)
        build_custom_plugin_directories(MQ_CUSTOM_PLUGIN_SUBDIRS "${MQ_CUSTOM_PLUGIN_SUBDIRS}" ${MQ_FORCE_VCXPROJ_CONVERSION})
        list(APPEND MQ_ALL_SUBDIRS ${MQ_CUSTOM_PLUGIN_SUBDIRS})

        # Write the list if configured to do so
        if(MQ_WRITE_PLUGINS_FILE)
            write_custom_plugins_file("${CMAKE_SOURCE_DIR}/${MQ_WRITE_PLUGINS_FILE}" "add_subdirectory" "${MQ_CUSTOM_PLUGIN_SUBDIRS}")
        endif()
    endif()
endif()

# ============================================================================
# vcpkg Integration (MUST be set before project() call)
# ============================================================================
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

# Extract port names from subdirectories
# For plugins, extract the direct descendant of plugins/ (e.g., "src/plugins/lua" -> "lua")
# For others, extract the leaf directory (e.g., "src/eqlib" -> "eqlib")
set(MQ_VCPKG_PORTS "")
foreach(SUBDIR ${MQ_ALL_SUBDIRS})
    if(SUBDIR MATCHES "^plugins/([^/]+)")
        # For plugins, use the direct descendant of plugins/
        list(APPEND MQ_VCPKG_PORTS "${CMAKE_MATCH_1}")
    else()
        # For others, use the leaf directory
        get_filename_component(PORT_NAME "${SUBDIR}" NAME)
        list(APPEND MQ_VCPKG_PORTS "${PORT_NAME}")
    endif()
endforeach()

# Remove any duplicates
list(REMOVE_DUPLICATES MQ_VCPKG_PORTS)

if(NOT MQ_REGENERATE_SOLUTION)
    # if we are just regenerating the solution, don't build the manifests
    message(STATUS "Generating VCPKG manifest (FORCE OVERLAY REBUILD: ${MQ_FORCE_OVERLAY_REBUILD})")
    include(cmake/vcpkg_manifest.cmake)

    if(MQ_FORCE_OVERLAY_REBUILD)
        set(FORCE_REBUILD FORCE_REBUILD)
    else()
        set(FORCE_REBUILD "")
    endif()

    create_vcpkg_overlays(
            PORTS ${MQ_VCPKG_PORTS}
            OUTPUT_DIR ${CMAKE_BINARY_DIR}
            ${FORCE_REBUILD}
    )
endif()

# ============================================================================
# Global settings
# ============================================================================
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Available build configurations" FORCE)

# Toolset selection
if(NOT CMAKE_GENERATOR_TOOLSET)
    set(CMAKE_GENERATOR_TOOLSET "v143" CACHE STRING "Choose MSVC toolset." FORCE)
endif()

# Disable CMake's automatic MSVC runtime library handling
# Runtime library flags (/MT, /MTd) are set manually in Common.cmake
set(CMAKE_MSVC_RUNTIME_LIBRARY "" CACHE STRING "" FORCE)

# ============================================================================
# Begin project definition
# ============================================================================
# TODO: move semver here? They are technically already handled in the resource files, maybe they can be tied together
project(MacroQuest
    VERSION 3.0.0
    LANGUAGES CXX
)

# Universal packages and compile flags
find_package(detours REQUIRED)
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)
string(REPLACE "/D_WINDOWS" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
string(REPLACE "/DNDEBUG" "" CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE})
string(REPLACE "/DWIN32" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})

if(MQ_REGENERATE_SOLUTION)
    # just generate the solution, do nothing else
    message(STATUS "Regenerating macroquest solution file")
    include(cmake/vcxproj_sln.cmake)
else()
    list(REMOVE_DUPLICATES MQ_ALL_SUBDIRS)
    foreach(SUBDIR ${MQ_ALL_SUBDIRS})
        add_subdirectory(${SUBDIR})
    endforeach()
endif()

# Print configuration summary
message(STATUS "")
message(STATUS "MacroQuest Configuration Summary:")
message(STATUS "  Build Types: ${CMAKE_CONFIGURATION_TYPES}")
message(STATUS "  MSVC Toolchain: ${CMAKE_GENERATOR_TOOLSET}")
message(STATUS "  C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "  Only Regenerate Solution: ${MQ_REGENERATE_SOLUTION}")
message(STATUS "  Build Plugins: ${MQ_BUILD_PLUGINS}")
message(STATUS "  Build Custom Plugins: ${MQ_BUILD_CUSTOM_PLUGINS}")
message(STATUS "  Build Loader: ${MQ_BUILD_LAUNCHER}")
message(STATUS "  Build Tests: ${MQ_BUILD_TESTS}")
message(STATUS "  Force VCXProj Conversion: ${MQ_FORCE_VCXPROJ_CONVERSION}")
message(STATUS "")