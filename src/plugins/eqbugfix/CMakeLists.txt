# Generated from MQ2EQBugFix.vcxproj
# This file is designed to work with add_subdirectory()

# ---------------------------------------------------------------------
# Props file includes
# ---------------------------------------------------------------------
include("../../Plugin.cmake")

# ---------------------------------------------------------------------
# vcpkg dependencies
# ---------------------------------------------------------------------
find_package(fmt REQUIRED)

# ---------------------------------------------------------------------
# Source files
# ---------------------------------------------------------------------
set(MQ2EQBugFix_SOURCES
    "MQ2EQBugFix.cpp"
)

source_groups("Source Files" ${MQ2EQBugFix_SOURCES})

# ---------------------------------------------------------------------
# Target definition
# ---------------------------------------------------------------------
add_library(MQ2EQBugFix SHARED
    ${MQ2EQBugFix_SOURCES}
)

set_target_properties(MQ2EQBugFix PROPERTIES FOLDER "core/plugins")

# ---------------------------------------------------------------------
# Apply props file configurations
# ---------------------------------------------------------------------
target_Plugin_props(MQ2EQBugFix)

# ---------------------------------------------------------------------
# Link vcpkg dependencies
# ---------------------------------------------------------------------
target_link_libraries(MQ2EQBugFix PRIVATE
    fmt::fmt
)

# ---------------------------------------------------------------------
# Project dependencies
# ---------------------------------------------------------------------
target_link_libraries(MQ2EQBugFix PRIVATE MQ2Main)

# ============================================================================
# MANUAL CONVERSION NOTES
# ============================================================================
#
# - Review and adjust as needed
