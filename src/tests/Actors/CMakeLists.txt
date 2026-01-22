# Generated from Actors.vcxproj
# This file is designed to work with add_subdirectory()

# ---------------------------------------------------------------------
# Props file includes
# ---------------------------------------------------------------------
include("../../Common.cmake")

# ---------------------------------------------------------------------
# Source files
# ---------------------------------------------------------------------
set(Actors_SOURCES
    "Main.cpp"
)

source_groups("Source Files" ${Actors_SOURCES})

# ---------------------------------------------------------------------
# Target definition
# ---------------------------------------------------------------------
add_executable(Actors
    ${Actors_SOURCES}
)

set_target_properties(Actors PROPERTIES FOLDER "core/applications/tests")

# ---------------------------------------------------------------------
# Apply props file configurations
# ---------------------------------------------------------------------
target_Common_props(Actors)

# ---------------------------------------------------------------------
# Project dependencies
# ---------------------------------------------------------------------
add_dependencies(Actors routing)

target_link_libraries(Actors PRIVATE routing)

# ---------------------------------------------------------------------
# Preprocessor definitions
# ---------------------------------------------------------------------
target_compile_definitions(Actors PRIVATE
    "$<$<CONFIG:Debug>:_DEBUG>"
    "$<$<STREQUAL:${CMAKE_GENERATOR_PLATFORM},Win32>:WIN32>"
    "MQ2MAIN_IMPL"
    "$<$<CONFIG:Release>:NDEBUG>"
    "_CONSOLE"
)

# ---------------------------------------------------------------------
# Include directories
# ---------------------------------------------------------------------
target_include_directories(Actors PRIVATE
    "${VCPKG_IncludeStatic}/crashpad-backtrace"
    "${CMAKE_SOURCE_DIR}/src"
    "${CMAKE_SOURCE_DIR}/include"
)

# ---------------------------------------------------------------------
# Compiler options
# ---------------------------------------------------------------------
target_compile_options(Actors PRIVATE
    "/W3"
    "$<$<CONFIG:Release>:/Oi>"
    "$<$<CONFIG:Release>:/Gy>"
    "/permissive-"
    "/std:c++17"
)

# ---------------------------------------------------------------------
# Library directories
# ---------------------------------------------------------------------
target_link_directories(Actors PRIVATE
    "${PlatformLibraryDirectories}"
    "${VCPKG_LibraryDirs}"
    "${MQLibDir}"
    "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/"
)

# ---------------------------------------------------------------------
# Link libraries
# ---------------------------------------------------------------------
target_link_libraries(Actors PRIVATE
    "$<$<CONFIG:Debug>:fmtd.lib>"
    "$<$<STREQUAL:${CMAKE_GENERATOR_PLATFORM},Win32>:d3d11.lib>"
    "$<$<CONFIG:Release>:fmt.lib>"
)

# ---------------------------------------------------------------------
# Linker options
# ---------------------------------------------------------------------
target_link_options(Actors PRIVATE
    "$<$<CONFIG:Release>:/OPT:ICF>"
    "/DEBUG"
    "$<$<CONFIG:Release>:/OPT:REF>"
    "/SUBSYSTEM:CONSOLE"
)

# ---------------------------------------------------------------------
# Character set defines
# ---------------------------------------------------------------------
target_compile_definitions(Actors PRIVATE
    "_UNICODE"
    "UNICODE"
)

# ============================================================================
# MANUAL CONVERSION NOTES
# ============================================================================
#
# - Review and adjust as needed
