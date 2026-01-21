# Generated from protobuf.props
# This file should be included in CMakeLists.txt files that need these settings
# NOTE: Import order preserved from original .props file

include_guard()

set(PATH_TO_protobuf_DIR ${CMAKE_CURRENT_LIST_DIR})

macro(target_protobuf_props TARGET_NAME)

    # ---------------------------------------------------------------------
    # PropertyGroup settings
    # ---------------------------------------------------------------------
    set(ProtocolBufferBeforeTargets "ClCompile")
    
    if(NOT "${ConfigurationType}" STREQUAL "Makefile")
        set(ProtocolBufferDependsOn "_SelectedFiles;${ProtocolBufferDependsOn}")
    endif()
    
    if("${Platform}" STREQUAL "Win32")
        set(ProtoImportPath "${CMAKE_SOURCE_DIR}/contrib/vcpkg/installed/x86-windows/include")
    elseif("${Platform}" STREQUAL "x64")
        set(ProtoImportPath "${CMAKE_SOURCE_DIR}/contrib/vcpkg/installed/x64-windows/include")
    endif()
    
    if(EXISTS "${CMAKE_SOURCE_DIR}/contrib/vcpkg/installed/x64-windows/tools/protobuf/protoc.exe")
        set(ProtocPath "${CMAKE_SOURCE_DIR}/contrib/vcpkg/installed/x64-windows/tools/protobuf/protoc.exe")
    elseif(EXISTS "${CMAKE_SOURCE_DIR}/contrib/vcpkg/installed/x64-windows-static/tools/protobuf/protoc.exe")
        set(ProtocPath "${CMAKE_SOURCE_DIR}/contrib/vcpkg/installed/x64-windows-static/tools/protobuf/protoc.exe")
    elseif(EXISTS "${CMAKE_SOURCE_DIR}/contrib/vcpkg/installed/x86-windows-static/tools/protobuf/protoc.exe")
        set(ProtocPath "${CMAKE_SOURCE_DIR}/contrib/vcpkg/installed/x86-windows-static/tools/protobuf/protoc.exe")
    # TODO: Convert condition: '$(Platform)'=='Win32' and '$(ProtocPath)' == ''
if(TRUE)
        set(ProtocPath "${CMAKE_SOURCE_DIR}/contrib/vcpkg/installed/x86-windows-static/tools/protobuf/protoc.exe")
    # TODO: Convert condition: '$(Platform)'=='x64' and '$(ProtocPath)' == ''
if(TRUE)
        set(ProtocPath "${CMAKE_SOURCE_DIR}/contrib/vcpkg/installed/x64-windows/tools/protobuf/protoc.exe")
    endif()
    
    
endmacro()
