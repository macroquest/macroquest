# Generated from MQ2AutoLogin.vcxproj
# This file is designed to work with add_subdirectory()

# ---------------------------------------------------------------------
# Props file includes
# ---------------------------------------------------------------------
include("../../Plugin.cmake")

# ---------------------------------------------------------------------
# vcpkg dependencies
# ---------------------------------------------------------------------
find_package(fmt REQUIRED)
find_package(protobuf REQUIRED)

# ---------------------------------------------------------------------
# Header files
# ---------------------------------------------------------------------
set(MQ2AutoLogin_HEADERS
    "MQ2AutoLogin.h"
)

source_groups("Header Files" ${MQ2AutoLogin_HEADERS})

# ---------------------------------------------------------------------
# Source files
# ---------------------------------------------------------------------
set(MQ2AutoLogin_SOURCES
    "StateMachine.cpp"
    "MQ2AutoLogin.cpp"
)

source_groups("Source Files" ${MQ2AutoLogin_SOURCES})

# ---------------------------------------------------------------------
# Target definition
# ---------------------------------------------------------------------
add_library(MQ2AutoLogin SHARED
    ${MQ2AutoLogin_HEADERS}
    ${MQ2AutoLogin_SOURCES}
)

set_target_properties(MQ2AutoLogin PROPERTIES FOLDER "core/plugins")

# ---------------------------------------------------------------------
# Apply props file configurations
# ---------------------------------------------------------------------
target_Plugin_props(MQ2AutoLogin)

# ---------------------------------------------------------------------
# Link vcpkg dependencies
# ---------------------------------------------------------------------
target_link_libraries(MQ2AutoLogin PRIVATE
    fmt::fmt
    protobuf::libprotobuf
)

# ---------------------------------------------------------------------
# Project dependencies
# ---------------------------------------------------------------------
target_link_libraries(MQ2AutoLogin PRIVATE login MQ2Main)

# ============================================================================
# MANUAL CONVERSION NOTES
# ============================================================================
#
# - Review and adjust as needed
