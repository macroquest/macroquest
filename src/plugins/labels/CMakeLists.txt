# Generated from MQ2Labels.vcxproj
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
set(MQ2Labels_SOURCES
    "MQ2Labels.cpp"
)

source_groups("Source Files" ${MQ2Labels_SOURCES})

# ---------------------------------------------------------------------
# Target definition
# ---------------------------------------------------------------------
add_library(MQ2Labels SHARED
    ${MQ2Labels_SOURCES}
)

set_target_properties(MQ2Labels PROPERTIES FOLDER "core/plugins")

# ---------------------------------------------------------------------
# Apply props file configurations
# ---------------------------------------------------------------------
target_Plugin_props(MQ2Labels)

# ---------------------------------------------------------------------
# Link vcpkg dependencies
# ---------------------------------------------------------------------
target_link_libraries(MQ2Labels PRIVATE
    fmt::fmt
)

# ---------------------------------------------------------------------
# Project dependencies
# ---------------------------------------------------------------------
target_link_libraries(MQ2Labels PRIVATE MQ2Main)

# ============================================================================
# MANUAL CONVERSION NOTES
# ============================================================================
#
# - Review and adjust as needed
