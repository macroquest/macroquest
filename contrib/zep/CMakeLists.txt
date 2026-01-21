# Generated from zep.vcxproj
# This file is designed to work with add_subdirectory()

# ---------------------------------------------------------------------
# Props file includes
# ---------------------------------------------------------------------
include("../../src/Common.cmake")

# ---------------------------------------------------------------------
# vcpkg dependencies
# ---------------------------------------------------------------------
find_package(fmt REQUIRED)

# ---------------------------------------------------------------------
# Header files
# ---------------------------------------------------------------------
set(zep_HEADERS
    "../../include/mq/zep/ImGuiZepConsole.h"
    "../../include/mq/zep/ImGuiZepEditor.h"
    "include/zep.h"
    "include/zep/buffer.h"
    "include/zep/commands.h"
    "include/zep/display.h"
    "include/zep/editor.h"
    "include/zep/filesystem.h"
    "include/zep/gap_buffer.h"
    "include/zep/glyph_iterator.h"
    "include/zep/indexer.h"
    "include/zep/keymap.h"
    "include/zep/line_widgets.h"
    "include/zep/mcommon/animation/timer.h"
    "include/zep/mcommon/callback.h"
    "include/zep/mcommon/file/cpptoml.h"
    "include/zep/mcommon/file/fnmatch.h"
    "include/zep/mcommon/file/path.h"
    "include/zep/mcommon/gsl-lite.hpp"
    "include/zep/mcommon/logger.h"
    "include/zep/mcommon/math/color.h"
    "include/zep/mcommon/math/math.h"
    "include/zep/mcommon/platform.h"
    "include/zep/mcommon/registrar.h"
    "include/zep/mcommon/signals.h"
    "include/zep/mcommon/string/stringutils.h"
    "include/zep/mcommon/threadpool.h"
    "include/zep/mcommon/threadutils.h"
    "include/zep/mcommon/utf8.h"
    "include/zep/mcommon/utf8/checked.h"
    "include/zep/mcommon/utf8/core.h"
    "include/zep/mcommon/utf8/cpp11.h"
    "include/zep/mcommon/utf8/unchecked.h"
    "include/zep/mode.h"
    "include/zep/mode_search.h"
    "include/zep/mode_standard.h"
    "include/zep/mode_tree.h"
    "include/zep/mode_vim.h"
    "include/zep/range_markers.h"
    "include/zep/regress.h"
    "include/zep/scroller.h"
    "include/zep/splits.h"
    "include/zep/syntax.h"
    "include/zep/syntax_markdown.h"
    "include/zep/syntax_providers.h"
    "include/zep/syntax_rainbow_brackets.h"
    "include/zep/syntax_tree.h"
    "include/zep/tab_window.h"
    "include/zep/theme.h"
    "include/zep/window.h"
    "include/zep/zep_config.h"
    "pch.h"
)

source_groups("Header Files" ${zep_HEADERS})

# ---------------------------------------------------------------------
# Other files
# ---------------------------------------------------------------------
set(zep_OTHERFILES
    "zep.natvis"
)

source_group("Resource Files" FILES ${zep_OTHERFILES})

# ---------------------------------------------------------------------
# Source files
# ---------------------------------------------------------------------
set(zep_SOURCES
    "../../src/zep/ImGuiZepConsole.cpp"
    "../../src/zep/ImGuiZepEditor.cpp"
    "src/buffer.cpp"
    "src/commands.cpp"
    "src/display.cpp"
    "src/editor.cpp"
    "src/filesystem.cpp"
    "src/glyph_iterator.cpp"
    "src/indexer.cpp"
    "src/keymap.cpp"
    "src/line_widgets.cpp"
    "src/mcommon/animation/timer.cpp"
    "src/mcommon/file/path.cpp"
    "src/mcommon/string/stringutils.cpp"
    "src/mode.cpp"
    "src/mode_search.cpp"
    "src/mode_standard.cpp"
    "src/mode_tree.cpp"
    "src/mode_vim.cpp"
    "src/range_markers.cpp"
    "src/regress.cpp"
    "src/scroller.cpp"
    "src/splits.cpp"
    "src/syntax.cpp"
    "src/syntax_markdown.cpp"
    "src/syntax_providers.cpp"
    "src/syntax_rainbow_brackets.cpp"
    "src/syntax_tree.cpp"
    "src/tab_window.cpp"
    "src/theme.cpp"
    "src/window.cpp"
)

source_groups("Source Files" ${zep_SOURCES})

# ---------------------------------------------------------------------
# Target definition
# ---------------------------------------------------------------------
add_library(zep STATIC
    ${zep_HEADERS}
    ${zep_OTHERFILES}
    ${zep_SOURCES}
)

set_target_properties(zep PROPERTIES FOLDER "core/libraries")

# ---------------------------------------------------------------------
# Apply props file configurations
# ---------------------------------------------------------------------
target_Common_props(zep)

# ---------------------------------------------------------------------
# Link vcpkg dependencies
# ---------------------------------------------------------------------
target_link_libraries(zep PRIVATE
    fmt::fmt
)

# ---------------------------------------------------------------------
# Preprocessor definitions
# ---------------------------------------------------------------------
target_compile_definitions(zep PRIVATE
    "_CRT_SECURE_NO_WARNINGS"
    "ZEP_FEATURE_CPP_FILE_SYSTEM"
    "NOGDI"
)

# ---------------------------------------------------------------------
# Character set defines
# ---------------------------------------------------------------------
target_compile_definitions(zep PRIVATE
    "_UNICODE"
    "UNICODE"
)

# ---------------------------------------------------------------------
# Precompiled header
# ---------------------------------------------------------------------
target_precompile_headers(zep PRIVATE "pch.h")

# ============================================================================
# MANUAL CONVERSION NOTES
# ============================================================================
#
# - Review and adjust as needed
