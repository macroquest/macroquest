# Generated from imgui.vcxproj
# This file is designed to work with add_subdirectory()

# ---------------------------------------------------------------------
# Props file includes
# ---------------------------------------------------------------------
include("../Common.cmake")

# ---------------------------------------------------------------------
# vcpkg dependencies
# ---------------------------------------------------------------------
find_package(fmt REQUIRED)
find_package(freetype REQUIRED)

# ---------------------------------------------------------------------
# Header files
# ---------------------------------------------------------------------
set(imgui_HEADERS
    "../../contrib/imgui/imconfig.h"
    "../../contrib/imgui/imgui.h"
    "../../contrib/imgui/imgui_internal.h"
    "../../contrib/imgui/imgui_stacklayout.h"
    "../../contrib/imgui/imgui_stacklayout_internal.h"
    "../../contrib/imgui/imgui_user.h"
    "../../contrib/imgui/imstb_rectpack.h"
    "../../contrib/imgui/imstb_textedit.h"
    "../../contrib/imgui/imstb_truetype.h"
    "../../contrib/imgui/misc/cpp/imgui_stdlib.h"
    "../../contrib/imgui/misc/freetype/imgui_freetype.h"
    "dirent/dirent.h"
    "fonts/IconsFontAwesome.h"
    "fonts/IconsMaterialDesign.h"
    "framework.h"
    "ImGuiFileDialog.h"
    "ImGuiFileDialogConfig.h"
    "ImGuiMemoryEditor.h"
    "ImGuiTextEditor.h"
    "ImGuiTreePanelWindow.h"
    "ImGuiUtils.h"
    "implot/implot.h"
    "implot/implot_internal.h"
    "pch.h"
)

source_groups("Header Files" ${imgui_HEADERS})

# ---------------------------------------------------------------------
# Other files
# ---------------------------------------------------------------------
set(imgui_OTHERFILES
    "../../contrib/imgui/misc/debuggers/imgui.natvis"
    "../../contrib/imgui/misc/debuggers/imgui.natstepfilter"
)

source_group("Resource Files" FILES ${imgui_OTHERFILES})

# ---------------------------------------------------------------------
# Source files
# ---------------------------------------------------------------------
set(imgui_SOURCES
    "../../contrib/imgui/imgui.cpp"
    "../../contrib/imgui/imgui_demo.cpp"
    "../../contrib/imgui/imgui_draw.cpp"
    "../../contrib/imgui/imgui_stacklayout.cpp"
    "../../contrib/imgui/imgui_tables.cpp"
    "../../contrib/imgui/imgui_widgets.cpp"
    "../../contrib/imgui/misc/freetype/imgui_freetype.cpp"
    "dllmain.cpp"
    "fonts/font_fontawesome_ttf.cpp"
    "fonts/font_materialicons_ttf.cpp"
    "fonts/font_roboto_regular_ttf.cpp"
    "ImGuiFileDialog.cpp"
    "ImGuiTextEditor.cpp"
    "ImGuiUtils.cpp"
    "implot/implot.cpp"
    "implot/implot_demo.cpp"
    "implot/implot_items.cpp"
)

source_groups("Source Files" ${imgui_SOURCES})

# ---------------------------------------------------------------------
# Target definition
# ---------------------------------------------------------------------
# Library type depends on configuration
if(MQ_STATIC_BUILD)
    set(LIB_TYPE STATIC)
else()
    set(LIB_TYPE SHARED)
endif()

add_library(imgui ${LIB_TYPE}
    ${imgui_HEADERS}
    ${imgui_OTHERFILES}
    ${imgui_SOURCES}
)

set_target_properties(imgui PROPERTIES FOLDER "core/libraries")

# ---------------------------------------------------------------------
# Output name customization
# ---------------------------------------------------------------------
if(CMAKE_GENERATOR_PLATFORM STREQUAL "x64")
    if(MQ_STATIC_BUILD)
        set_target_properties(imgui PROPERTIES OUTPUT_NAME
            "$<IF:$<CONFIG:Debug>,imgui-static,imgui-static>"
        )
    else()
        set_target_properties(imgui PROPERTIES OUTPUT_NAME
            "$<IF:$<CONFIG:Debug>,imgui-64,imgui-64>"
        )
    endif()
elseif(CMAKE_GENERATOR_PLATFORM STREQUAL "Win32")
    if(MQ_STATIC_BUILD)
        set_target_properties(imgui PROPERTIES OUTPUT_NAME
            "$<IF:$<CONFIG:Debug>,imgui-static,imgui-static>"
        )
    endif()
endif()

# ---------------------------------------------------------------------
# Apply props file configurations
# ---------------------------------------------------------------------
target_Common_props(imgui)

# ---------------------------------------------------------------------
# Link vcpkg dependencies
# ---------------------------------------------------------------------
target_link_libraries(imgui PRIVATE
    fmt::fmt
    Freetype::Freetype
)

# ---------------------------------------------------------------------
# Preprocessor definitions
# ---------------------------------------------------------------------
target_compile_definitions(imgui PRIVATE
    "$<$<BOOL:${MQ_STATIC_BUILD}>:IMGUI_STATIC>"
    "$<$<STREQUAL:${CMAKE_GENERATOR_PLATFORM},x64>:MQ_BUILD_AS_X64>"
    "$<$<NOT:$<BOOL:${MQ_STATIC_BUILD}>>:IMGUI_EXPORTS>"
    "WIN32"
    "$<$<NOT:$<BOOL:${MQ_STATIC_BUILD}>>:_USRDLL>"
    "$<$<CONFIG:Debug>:_DEBUG>"
    "$<$<CONFIG:Release>:NDEBUG>"
    "_WINDOWS"
)

# ---------------------------------------------------------------------
# Compiler options
# ---------------------------------------------------------------------
target_compile_options(imgui PRIVATE
    "/W3"
    "$<$<CONFIG:Release>:/Oi>"
    "$<$<CONFIG:Release>:/Ot>"
    "$<$<CONFIG:Release>:/Ob2>"
    "/permissive-"
    "/FIpch.h"
)

# ---------------------------------------------------------------------
# Link libraries
# ---------------------------------------------------------------------
target_link_libraries(imgui PRIVATE
    "$<$<NOT:$<BOOL:${MQ_STATIC_BUILD}>>:${ImGuiLibs}>"
)

# ---------------------------------------------------------------------
# Linker options
# ---------------------------------------------------------------------
target_link_options(imgui PRIVATE
    "$<$<NOT:$<BOOL:${MQ_STATIC_BUILD}>>:/SUBSYSTEM:WINDOWS>"
    "$<$<NOT:$<BOOL:${MQ_STATIC_BUILD}>>:$<$<CONFIG:Release>:/OPT:ICF>>"
    "$<$<NOT:$<BOOL:${MQ_STATIC_BUILD}>>:$<$<CONFIG:Release>:/OPT:REF>>"
)

# ---------------------------------------------------------------------
# Character set defines
# ---------------------------------------------------------------------
target_compile_definitions(imgui PRIVATE
    "_UNICODE"
    "UNICODE"
)

# ---------------------------------------------------------------------
# Precompiled header
# ---------------------------------------------------------------------
target_precompile_headers(imgui PRIVATE "pch.h")

# ============================================================================
# MANUAL CONVERSION NOTES
# ============================================================================
#
# - Warnings:
#   - Project has mixed configuration types (DLL/Static)
# - Review and adjust as needed
