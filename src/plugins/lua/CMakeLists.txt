# Generated from MQ2Lua.vcxproj
# This file is designed to work with add_subdirectory()

# ---------------------------------------------------------------------
# Props file includes
# ---------------------------------------------------------------------
include("../../Plugin.cmake")

# ---------------------------------------------------------------------
# vcpkg dependencies
# ---------------------------------------------------------------------
find_package(luajit REQUIRED)
find_package(sol2 REQUIRED)
find_package(protobuf REQUIRED)
find_package(yaml-cpp REQUIRED)

# ---------------------------------------------------------------------
# Header files
# ---------------------------------------------------------------------
set(MQ2Lua_HEADERS
    "bindings/lua_Bindings.h"
    "bindings/lua_MQBindings.h"
    "LuaActor.h"
    "LuaCommon.h"
    "LuaEvent.h"
    "LuaCoroutine.h"
    "LuaImGui.h"
    "LuaModuleRegistry.h"
    "LuaThread.h"
    "LuaInterface.h"
    "pch.h"
)

source_groups("Header Files" ${MQ2Lua_HEADERS})

# ---------------------------------------------------------------------
# Other files
# ---------------------------------------------------------------------
set(MQ2Lua_OTHERFILES
    "LuaJIT-x86.natvis"
    "LuaJIT.natvis"
)

source_group("Resource Files" FILES ${MQ2Lua_OTHERFILES})

# ---------------------------------------------------------------------
# Source files
# ---------------------------------------------------------------------
set(MQ2Lua_SOURCES
    "bindings/lua_Bit32.cpp"
    "bindings/lua_EQBindings.cpp"
    "bindings/lua_Globals.cpp"
    "bindings/lua_ImGuiCore.cpp"
    "bindings/lua_ImGuiCustom.cpp"
    "bindings/lua_ImGuiEnums.cpp"
    "bindings/lua_ImGuiWidgets.cpp"
    "bindings/lua_ImGuiUserTypes.cpp"
    "bindings/lua_ImPlot.cpp"
    "bindings/lua_MQBindings.cpp"
    "bindings/lua_MQMacroData.cpp"
    "bindings/lua_Zep.cpp"
    "LuaActor.cpp"
    "LuaCoroutine.cpp"
    "LuaEvent.cpp"
    "LuaImGui.cpp"
    "LuaModuleRegistry.cpp"
    "LuaThread.cpp"
    "MQ2Lua.cpp"
)

source_groups("Source Files" ${MQ2Lua_SOURCES})

# ---------------------------------------------------------------------
# Target definition
# ---------------------------------------------------------------------
add_library(MQ2Lua SHARED
    ${MQ2Lua_HEADERS}
    ${MQ2Lua_OTHERFILES}
    ${MQ2Lua_SOURCES}
)

set_target_properties(MQ2Lua PROPERTIES FOLDER "core/plugins")

# ---------------------------------------------------------------------
# Apply props file configurations
# ---------------------------------------------------------------------
target_Plugin_props(MQ2Lua)

# ---------------------------------------------------------------------
# Protobuf generation
# ---------------------------------------------------------------------
# Create object library for protobuf files
add_library(MQ2Lua-proto OBJECT
    "Actor.proto"
)

set_target_properties(MQ2Lua-proto PROPERTIES FOLDER "core/plugins/proto")

target_Plugin_props(MQ2Lua-proto)

target_link_libraries(MQ2Lua-proto PUBLIC
    protobuf::libprotobuf
)

target_include_directories(MQ2Lua-proto PUBLIC
    $<TARGET_PROPERTY:MQ2Lua-proto,BINARY_DIR>
)

# Generate protobuf sources (.pb.cc and .pb.h files)
# Note: Generated files are automatically added to the target
# Do not manually list .pb.cc or .pb.h files in source variables
protobuf_generate(
    TARGET MQ2Lua-proto
    LANGUAGE cpp
    PROTOC_OUT_DIR 
)

# Link the proto library to main project
target_link_libraries(MQ2Lua PUBLIC
    MQ2Lua-proto
)

# ---------------------------------------------------------------------
# Link vcpkg dependencies
# ---------------------------------------------------------------------
target_link_libraries(MQ2Lua PRIVATE
    luajit::luajit
    sol2
    protobuf::libprotobuf
    yaml-cpp::yaml-cpp
)

# ---------------------------------------------------------------------
# Project dependencies
# ---------------------------------------------------------------------
add_dependencies(MQ2Lua MQ2Main imgui)

target_link_libraries(MQ2Lua PRIVATE MQ2Main imgui)

# ---------------------------------------------------------------------
# Preprocessor definitions
# ---------------------------------------------------------------------
target_compile_definitions(MQ2Lua PRIVATE
    "SOL_LUAJIT=1"
)

# ---------------------------------------------------------------------
# Include directories
# ---------------------------------------------------------------------
target_include_directories(MQ2Lua PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/"
)

# ---------------------------------------------------------------------
# Compiler options
# ---------------------------------------------------------------------
target_compile_options(MQ2Lua PRIVATE
    "/EHa"
    "$<$<CONFIG:Debug>:/MTd>"
    "$<$<STREQUAL:${CMAKE_GENERATOR_PLATFORM},x64>:$<$<CONFIG:Release>:/Gy->>"
    "/bigobj"
)

# ---------------------------------------------------------------------
# Precompiled header
# ---------------------------------------------------------------------
target_precompile_headers(MQ2Lua PRIVATE "pch.h")

# ---------------------------------------------------------------------
# PRE_BUILD events
# ---------------------------------------------------------------------

add_custom_command(TARGET MQ2Lua PRE_BUILD
    COMMAND powershell.exe -ExecutionPolicy Bypass -NoProfile -NonInteractive -File "${CMAKE_SOURCE_DIR}/tools/build_scripts/Plugin_Versioning.ps1" -ProjectName "${PROJECT_NAME}" -ProjectDirectory "${CMAKE_CURRENT_SOURCE_DIR}/"
    COMMENT "Updating version resource for ${PROJECT_NAME}..."
    VERBATIM
)

# ============================================================================
# MANUAL CONVERSION NOTES
# ============================================================================
#
# - Review and adjust as needed
