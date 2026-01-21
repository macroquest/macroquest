# Generated from MQ2Map.vcxproj
# This file is designed to work with add_subdirectory()

# ---------------------------------------------------------------------
# Props file includes
# ---------------------------------------------------------------------
include("../../Plugin.cmake")

# ---------------------------------------------------------------------
# Header files
# ---------------------------------------------------------------------
set(MQ2Map_HEADERS
    "MapObject.h"
    "MQ2Map.h"
)

source_groups("Header Files" ${MQ2Map_HEADERS})

# ---------------------------------------------------------------------
# Assembly files
# ---------------------------------------------------------------------
set(MQ2Map_ASSEMBLY
    "AssemblyFunctions.asm"
)

source_groups("Assembly Files" ${MQ2Map_ASSEMBLY})

# ---------------------------------------------------------------------
# Source files
# ---------------------------------------------------------------------
set(MQ2Map_SOURCES
    "MapObject.cpp"
    "MQ2Map.cpp"
    "MQ2MapAPI.cpp"
    "MQ2MapCommands.cpp"
)

source_groups("Source Files" ${MQ2Map_SOURCES})

# ---------------------------------------------------------------------
# Target definition
# ---------------------------------------------------------------------
add_library(MQ2Map SHARED
    ${MQ2Map_HEADERS}
    ${MQ2Map_ASSEMBLY}
    ${MQ2Map_SOURCES}
)

set_target_properties(MQ2Map PROPERTIES FOLDER "core/plugins")

# ---------------------------------------------------------------------
# Apply props file configurations
# ---------------------------------------------------------------------
target_Plugin_props(MQ2Map)

# ---------------------------------------------------------------------
# Add NASM tool to ASM files
# ---------------------------------------------------------------------
add_nasm_sources(${MQ2Map_ASSEMBLY})

# ---------------------------------------------------------------------
# Project dependencies
# ---------------------------------------------------------------------
target_link_libraries(MQ2Map PRIVATE MQ2Main)

# ============================================================================
# MANUAL CONVERSION NOTES
# ============================================================================
#
# - Review and adjust as needed
