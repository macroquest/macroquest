# Generated from MQ2AutoBank.vcxproj
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
# Header files
# ---------------------------------------------------------------------
set(MQ2AutoBank_HEADERS
    "resource.h"
)

source_groups("Header Files" ${MQ2AutoBank_HEADERS})

# ---------------------------------------------------------------------
# Other files
# ---------------------------------------------------------------------
set(MQ2AutoBank_OTHERFILES
    "MQ2AutoBank.rc"
    "README.md"
)

source_group("Resource Files" FILES ${MQ2AutoBank_OTHERFILES})

# ---------------------------------------------------------------------
# Source files
# ---------------------------------------------------------------------
set(MQ2AutoBank_SOURCES
    "MQ2AutoBank.cpp"
)

source_groups("Source Files" ${MQ2AutoBank_SOURCES})

# ---------------------------------------------------------------------
# Target definition
# ---------------------------------------------------------------------
add_library(MQ2AutoBank SHARED
    ${MQ2AutoBank_HEADERS}
    ${MQ2AutoBank_OTHERFILES}
    ${MQ2AutoBank_SOURCES}
)

set_target_properties(MQ2AutoBank PROPERTIES FOLDER "core/plugins")

# ---------------------------------------------------------------------
# Apply props file configurations
# ---------------------------------------------------------------------
target_Plugin_props(MQ2AutoBank)

# ---------------------------------------------------------------------
# Link vcpkg dependencies
# ---------------------------------------------------------------------
target_link_libraries(MQ2AutoBank PRIVATE
    fmt::fmt
)

# ---------------------------------------------------------------------
# Project dependencies
# ---------------------------------------------------------------------
target_link_libraries(MQ2AutoBank PRIVATE MQ2Main)

# ---------------------------------------------------------------------
# PRE_BUILD events
# ---------------------------------------------------------------------

add_custom_command(TARGET MQ2AutoBank PRE_BUILD
    COMMAND powershell.exe -ExecutionPolicy Bypass -NoProfile -NonInteractive -File "${CMAKE_SOURCE_DIR}/tools/build_scripts/Plugin_Versioning.ps1" -ProjectName "${PROJECT_NAME}" -ProjectDirectory "${CMAKE_CURRENT_SOURCE_DIR}/"
    COMMENT "Updating version resource for ${PROJECT_NAME}..."
    VERBATIM
)

# ============================================================================
# MANUAL CONVERSION NOTES
# ============================================================================
#
# - Review and adjust as needed
