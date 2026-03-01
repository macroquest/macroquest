# Generated from routing.vcxproj
# This file is designed to work with add_subdirectory()

# ---------------------------------------------------------------------
# Props file includes
# ---------------------------------------------------------------------
include("../Common.cmake")

# ---------------------------------------------------------------------
# vcpkg dependencies
# ---------------------------------------------------------------------
find_package(asio REQUIRED)
find_package(fmt REQUIRED)
find_package(protobuf REQUIRED)
find_package(spdlog REQUIRED)
find_package(wil REQUIRED)

# ---------------------------------------------------------------------
# Header files
# ---------------------------------------------------------------------
set(routing_HEADERS
    "ClientPostOffice.h"
    "NamedPipes.h"
    "NamedPipesProtocol.h"
    "Network.h"
    "PostOffice.h"
    "ProtoPipes.h"
    "Routing.h"
    "ServerPostOffice.h"
)

source_groups("Header Files" ${routing_HEADERS})

# ---------------------------------------------------------------------
# Source files
# ---------------------------------------------------------------------
set(routing_SOURCES
    "ClientPostOffice.cpp"
    "Connection.cpp"
    "NamedPipes.cpp"
    "Network.cpp"
    "PostOffice.cpp"
    "ServerPostOffice.cpp"
)

source_groups("Source Files" ${routing_SOURCES})

# ---------------------------------------------------------------------
# Target definition
# ---------------------------------------------------------------------
add_library(routing STATIC
    ${routing_HEADERS}
    ${routing_SOURCES}
)

set_target_properties(routing PROPERTIES FOLDER "core/libraries")

# ---------------------------------------------------------------------
# Apply props file configurations
# ---------------------------------------------------------------------
target_Common_props(routing)

# ---------------------------------------------------------------------
# Protobuf generation
# ---------------------------------------------------------------------
# Create object library for protobuf files
add_library(routing-proto OBJECT
    "Network.proto"
    "Routing.proto"
)

set_target_properties(routing-proto PROPERTIES FOLDER "core/libraries/proto")

target_Common_props(routing-proto)

target_link_libraries(routing-proto PUBLIC
    protobuf::libprotobuf
)

target_include_directories(routing-proto PUBLIC
    $<TARGET_PROPERTY:routing-proto,BINARY_DIR>
)

# Generate protobuf sources (.pb.cc and .pb.h files)
# Note: Generated files are automatically added to the target
# Do not manually list .pb.cc or .pb.h files in source variables
protobuf_generate(
    TARGET routing-proto
    LANGUAGE cpp
    PROTOC_OUT_DIR 
)

# Link the proto library to main project
target_link_libraries(routing PUBLIC
    routing-proto
)

# ---------------------------------------------------------------------
# Link vcpkg dependencies
# ---------------------------------------------------------------------
target_link_libraries(routing PRIVATE
    asio::asio
    fmt::fmt
    protobuf::libprotobuf
    spdlog::spdlog
    WIL::WIL
)

# ============================================================================
# MANUAL CONVERSION NOTES
# ============================================================================
#
# - Review and adjust as needed
