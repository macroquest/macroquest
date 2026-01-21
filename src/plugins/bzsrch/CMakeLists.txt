# Generated from MQ2Bzsrch.vcxproj
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
set(MQ2Bzsrch_SOURCES
    "MQ2Bzsrch.cpp"
)

source_groups("Source Files" ${MQ2Bzsrch_SOURCES})

# ---------------------------------------------------------------------
# Target definition
# ---------------------------------------------------------------------
add_library(MQ2Bzsrch SHARED
    ${MQ2Bzsrch_SOURCES}
)

set_target_properties(MQ2Bzsrch PROPERTIES FOLDER "core/plugins")

# ---------------------------------------------------------------------
# Apply props file configurations
# ---------------------------------------------------------------------
target_Plugin_props(MQ2Bzsrch)

# ---------------------------------------------------------------------
# Link vcpkg dependencies
# ---------------------------------------------------------------------
target_link_libraries(MQ2Bzsrch PRIVATE
    fmt::fmt
)

# ---------------------------------------------------------------------
# Project dependencies
# ---------------------------------------------------------------------
target_link_libraries(MQ2Bzsrch PRIVATE MQ2Main)

# ============================================================================
# MANUAL CONVERSION NOTES
# ============================================================================
#
# - Review and adjust as needed
