cmake_minimum_required(VERSION 3.20)

# Set up paths as they would be in the real build
set(CMAKE_SOURCE_DIR "..")
set(CMAKE_BINARY_DIR "${CMAKE_CURRENT_LIST_DIR}/../build_test")

# Include the merger
include(vcpkg_manifest.cmake)

# Test with the specified ports
message(STATUS "Testing vcpkg overlay manifest generator...")
create_vcpkg_overlays(
    PORTS eqlib MQ2AASpend MQ2Nav lua loader
    OUTPUT_DIR "${CMAKE_BINARY_DIR}"
)

message(STATUS "Test complete. Check ${CMAKE_BINARY_DIR}/vcpkg.json for results.")
