# Generated from MQ2XTarInfo.vcxproj
# This file is designed to work with add_subdirectory()

# ---------------------------------------------------------------------
# Props file includes
# ---------------------------------------------------------------------
include("../../Plugin.cmake")

# ---------------------------------------------------------------------
# Header files
# ---------------------------------------------------------------------
set(MQ2XTarInfo_HEADERS
    "resource.h"
)

source_groups("Header Files" ${MQ2XTarInfo_HEADERS})

# ---------------------------------------------------------------------
# Other files
# ---------------------------------------------------------------------
set(MQ2XTarInfo_OTHERFILES
    "MQ2XTarInfo.rc"
    "MQ2XTarInfo.ini"
)

source_group("Resource Files" FILES ${MQ2XTarInfo_OTHERFILES})

# ---------------------------------------------------------------------
# Source files
# ---------------------------------------------------------------------
set(MQ2XTarInfo_SOURCES
    "MQ2XTarInfo.cpp"
)

source_groups("Source Files" ${MQ2XTarInfo_SOURCES})

# ---------------------------------------------------------------------
# Target definition
# ---------------------------------------------------------------------
add_library(MQ2XTarInfo SHARED
    ${MQ2XTarInfo_HEADERS}
    ${MQ2XTarInfo_OTHERFILES}
    ${MQ2XTarInfo_SOURCES}
)

set_target_properties(MQ2XTarInfo PROPERTIES FOLDER "core/plugins")

# ---------------------------------------------------------------------
# Apply props file configurations
# ---------------------------------------------------------------------
target_Plugin_props(MQ2XTarInfo)

# ---------------------------------------------------------------------
# Project dependencies
# ---------------------------------------------------------------------
target_link_libraries(MQ2XTarInfo PRIVATE MQ2Main)

# ---------------------------------------------------------------------
# PRE_BUILD events
# ---------------------------------------------------------------------

add_custom_command(TARGET MQ2XTarInfo PRE_BUILD
    COMMAND powershell.exe -ExecutionPolicy Bypass -NoProfile -NonInteractive -File "${CMAKE_SOURCE_DIR}/tools/build_scripts/Plugin_Versioning.ps1" -ProjectName "${PROJECT_NAME}" -ProjectDirectory "${CMAKE_CURRENT_SOURCE_DIR}/"
    COMMENT "Updating version resource for ${PROJECT_NAME}..."
    VERBATIM
)

# ============================================================================
# MANUAL CONVERSION NOTES
# ============================================================================
#
# - Review and adjust as needed
