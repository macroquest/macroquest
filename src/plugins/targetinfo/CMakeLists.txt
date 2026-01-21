# Generated from MQ2TargetInfo.vcxproj
# This file is designed to work with add_subdirectory()

# ---------------------------------------------------------------------
# Props file includes
# ---------------------------------------------------------------------
include("../../Plugin.cmake")

# ---------------------------------------------------------------------
# Header files
# ---------------------------------------------------------------------
set(MQ2TargetInfo_HEADERS
    "resource.h"
)

source_groups("Header Files" ${MQ2TargetInfo_HEADERS})

# ---------------------------------------------------------------------
# Other files
# ---------------------------------------------------------------------
set(MQ2TargetInfo_OTHERFILES
    "MQ2TargetInfo.rc"
    "MQ2TargetInfoPHs.txt"
    "MQ2TargetInfo.ini"
)

source_group("Resource Files" FILES ${MQ2TargetInfo_OTHERFILES})

# ---------------------------------------------------------------------
# Source files
# ---------------------------------------------------------------------
set(MQ2TargetInfo_SOURCES
    "MQ2TargetInfo.cpp"
)

source_groups("Source Files" ${MQ2TargetInfo_SOURCES})

# ---------------------------------------------------------------------
# Target definition
# ---------------------------------------------------------------------
add_library(MQ2TargetInfo SHARED
    ${MQ2TargetInfo_HEADERS}
    ${MQ2TargetInfo_OTHERFILES}
    ${MQ2TargetInfo_SOURCES}
)

set_target_properties(MQ2TargetInfo PROPERTIES FOLDER "core/plugins")

# ---------------------------------------------------------------------
# Apply props file configurations
# ---------------------------------------------------------------------
target_Plugin_props(MQ2TargetInfo)

# ---------------------------------------------------------------------
# Project dependencies
# ---------------------------------------------------------------------
target_link_libraries(MQ2TargetInfo PRIVATE MQ2Main)

# ============================================================================
# MANUAL CONVERSION NOTES
# ============================================================================
#
# - Review and adjust as needed
