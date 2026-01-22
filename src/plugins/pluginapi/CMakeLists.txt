# Generated from pluginapi.vcxproj
# This file is designed to work with add_subdirectory()

# ---------------------------------------------------------------------
# Props file includes
# ---------------------------------------------------------------------
include("../../Common.cmake")

# ---------------------------------------------------------------------
# vcpkg dependencies
# ---------------------------------------------------------------------
find_package(spdlog REQUIRED)

# ---------------------------------------------------------------------
# Header files
# ---------------------------------------------------------------------
set(pluginapi_HEADERS
    "../../../include/mq/plugin/pluginapi.h"
)

source_groups("Header Files" ${pluginapi_HEADERS})

# ---------------------------------------------------------------------
# Source files
# ---------------------------------------------------------------------
set(pluginapi_SOURCES
    "pluginapi.cpp"
)

source_groups("Source Files" ${pluginapi_SOURCES})

# ---------------------------------------------------------------------
# Target definition
# ---------------------------------------------------------------------
add_library(pluginapi STATIC
    ${pluginapi_HEADERS}
    ${pluginapi_SOURCES}
)

set_target_properties(pluginapi PROPERTIES FOLDER "core/plugins")

# ---------------------------------------------------------------------
# Apply props file configurations
# ---------------------------------------------------------------------
target_Common_props(pluginapi)

# ---------------------------------------------------------------------
# Link vcpkg dependencies
# ---------------------------------------------------------------------
target_link_libraries(pluginapi PRIVATE
    spdlog::spdlog
)

# ---------------------------------------------------------------------
# Project dependencies
# ---------------------------------------------------------------------
target_link_libraries(pluginapi PRIVATE routing)

# ============================================================================
# MANUAL CONVERSION NOTES
# ============================================================================
#
# - Review and adjust as needed
