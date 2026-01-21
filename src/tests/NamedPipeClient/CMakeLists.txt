# Generated from NamedPipeClient.vcxproj
# This file is designed to work with add_subdirectory()

# ---------------------------------------------------------------------
# Props file includes
# ---------------------------------------------------------------------
include("../../Common.cmake")

# ---------------------------------------------------------------------
# Header files
# ---------------------------------------------------------------------
set(NamedPipeClient_HEADERS
    "../../routing/NamedPipes.h"
)

source_groups("Header Files" ${NamedPipeClient_HEADERS})

# ---------------------------------------------------------------------
# Source files
# ---------------------------------------------------------------------
set(NamedPipeClient_SOURCES
    "App.cpp"
)

source_groups("Source Files" ${NamedPipeClient_SOURCES})

# ---------------------------------------------------------------------
# Target definition
# ---------------------------------------------------------------------
add_executable(NamedPipeClient
    ${NamedPipeClient_HEADERS}
    ${NamedPipeClient_SOURCES}
)

set_target_properties(NamedPipeClient PROPERTIES FOLDER "core/applications/tests")

# ---------------------------------------------------------------------
# Apply props file configurations
# ---------------------------------------------------------------------
target_Common_props(NamedPipeClient)

# ---------------------------------------------------------------------
# Preprocessor definitions
# ---------------------------------------------------------------------
target_compile_definitions(NamedPipeClient PRIVATE
    "WIN32"
    "_CONSOLE"
    "$<$<CONFIG:Debug>:_DEBUG>"
    "$<$<CONFIG:Release>:NDEBUG>"
    "_CRT_SECURE_NO_WARNINGS"
)

# ---------------------------------------------------------------------
# Include directories
# ---------------------------------------------------------------------
target_include_directories(NamedPipeClient PRIVATE
    "${CMAKE_SOURCE_DIR}/src"
)

# ---------------------------------------------------------------------
# Compiler options
# ---------------------------------------------------------------------
target_compile_options(NamedPipeClient PRIVATE
    "/permissive-"
    "$<$<CONFIG:Release>:/Oi>"
    "/W3"
    "$<$<CONFIG:Release>:/Gy>"
)

# ---------------------------------------------------------------------
# Link libraries
# ---------------------------------------------------------------------
target_link_libraries(NamedPipeClient PRIVATE
    "$<$<CONFIG:Debug>:fmtd.lib>"
    "$<$<CONFIG:Release>:fmt.lib>"
)

# ---------------------------------------------------------------------
# Linker options
# ---------------------------------------------------------------------
target_link_options(NamedPipeClient PRIVATE
    "$<$<CONFIG:Release>:/OPT:ICF>"
    "/DEBUG"
    "$<$<CONFIG:Release>:/OPT:REF>"
    "/SUBSYSTEM:CONSOLE"
)

# ============================================================================
# MANUAL CONVERSION NOTES
# ============================================================================
#
# - Review and adjust as needed
