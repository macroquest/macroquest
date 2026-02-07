# Generated from login.vcxproj
# This file is designed to work with add_subdirectory()

# ---------------------------------------------------------------------
# Props file includes
# ---------------------------------------------------------------------
include("../Common.cmake")

# ---------------------------------------------------------------------
# vcpkg dependencies
# ---------------------------------------------------------------------
find_package(protobuf REQUIRED)
find_package(unofficial-sqlite3 REQUIRED)
find_package(unofficial-argon2 REQUIRED)

# ---------------------------------------------------------------------
# Header files
# ---------------------------------------------------------------------
set(login_HEADERS
    "AutoLogin.h"
    "Companies.h"
    "Login.h"
)

source_groups("Header Files" ${login_HEADERS})

# ---------------------------------------------------------------------
# Source files
# ---------------------------------------------------------------------
set(login_SOURCES
    "AutoLogin.cpp"
    "Login.cpp"
)

source_groups("Source Files" ${login_SOURCES})

# ---------------------------------------------------------------------
# Target definition
# ---------------------------------------------------------------------
add_library(login STATIC
    ${login_HEADERS}
    ${login_SOURCES}
)

set_target_properties(login PROPERTIES FOLDER "core/libraries")

# ---------------------------------------------------------------------
# Apply props file configurations
# ---------------------------------------------------------------------
target_Common_props(login)

# ---------------------------------------------------------------------
# Protobuf generation
# ---------------------------------------------------------------------
# Create object library for protobuf files
add_library(login-proto OBJECT
    "Login.proto"
)

set_target_properties(login-proto PROPERTIES FOLDER "core/libraries/proto")

target_Common_props(login-proto)

target_link_libraries(login-proto PUBLIC
    protobuf::libprotobuf
)

target_include_directories(login-proto PUBLIC
    $<TARGET_PROPERTY:login-proto,BINARY_DIR>
)

# Generate protobuf sources (.pb.cc and .pb.h files)
# Note: Generated files are automatically added to the target
# Do not manually list .pb.cc or .pb.h files in source variables
protobuf_generate(
    TARGET login-proto
    LANGUAGE cpp
    PROTOC_OUT_DIR 
)

# Link the proto library to main project
target_link_libraries(login PUBLIC
    login-proto
)

# ---------------------------------------------------------------------
# Link vcpkg dependencies
# ---------------------------------------------------------------------
target_link_libraries(login PRIVATE
    protobuf::libprotobuf
    unofficial::sqlite3::sqlite3
    unofficial::argon2::libargon2
)

# ============================================================================
# MANUAL CONVERSION NOTES
# ============================================================================
#
# - Review and adjust as needed
