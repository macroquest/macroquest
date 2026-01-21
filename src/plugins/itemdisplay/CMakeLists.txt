# Generated from MQ2ItemDisplay.vcxproj
# This file is designed to work with add_subdirectory()

# ---------------------------------------------------------------------
# Props file includes
# ---------------------------------------------------------------------
include("../../Plugin.cmake")

# ---------------------------------------------------------------------
# Header files
# ---------------------------------------------------------------------
set(MQ2ItemDisplay_HEADERS
    "resource.h"
)

source_groups("Header Files" ${MQ2ItemDisplay_HEADERS})

# ---------------------------------------------------------------------
# Other files
# ---------------------------------------------------------------------
set(MQ2ItemDisplay_OTHERFILES
    "MQ2ItemDisplay.rc"
)

source_group("Resource Files" FILES ${MQ2ItemDisplay_OTHERFILES})

# ---------------------------------------------------------------------
# Assembly files
# ---------------------------------------------------------------------
set(MQ2ItemDisplay_ASSEMBLY
    "AssemblyFunctions.asm"
)

source_groups("Assembly Files" ${MQ2ItemDisplay_ASSEMBLY})

# ---------------------------------------------------------------------
# Source files
# ---------------------------------------------------------------------
set(MQ2ItemDisplay_SOURCES
    "MQ2ItemDisplay.cpp"
)

source_groups("Source Files" ${MQ2ItemDisplay_SOURCES})

# ---------------------------------------------------------------------
# Target definition
# ---------------------------------------------------------------------
add_library(MQ2ItemDisplay SHARED
    ${MQ2ItemDisplay_HEADERS}
    ${MQ2ItemDisplay_OTHERFILES}
    ${MQ2ItemDisplay_ASSEMBLY}
    ${MQ2ItemDisplay_SOURCES}
)

set_target_properties(MQ2ItemDisplay PROPERTIES FOLDER "core/plugins")

# ---------------------------------------------------------------------
# Apply props file configurations
# ---------------------------------------------------------------------
target_Plugin_props(MQ2ItemDisplay)

# ---------------------------------------------------------------------
# Add NASM tool to ASM files
# ---------------------------------------------------------------------
add_nasm_sources(${MQ2ItemDisplay_ASSEMBLY})

# ---------------------------------------------------------------------
# Project dependencies
# ---------------------------------------------------------------------
target_link_libraries(MQ2ItemDisplay PRIVATE MQ2Main)

# ============================================================================
# MANUAL CONVERSION NOTES
# ============================================================================
#
# - Review and adjust as needed
