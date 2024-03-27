/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#pragma once

#include "imgui.h"

#include "fonts/IconsFontAwesome.h"
#include "fonts/IconsMaterialDesign.h"

#include <functional>

struct ImFont;

namespace mq {
namespace imgui {

//----------------------------------------------------------------------------

// Creates a splitter that can be used to resize two panels.
IMGUI_API void DrawSplitter(bool split_vertically, float thickness, float* size0, float* size1,
	float min_size0, float min_size1);

// Draws a (?) marker with the provided text as its tooltip. Width defines the size of
// the tooltip box. The height will grow to fit.
IMGUI_API void HelpMarker(const char* text, float width = 450.0f, ImFont* tooltipFont = nullptr);
IMGUI_API void HelpMarker(const std::function<std::string()>& getText, float width = 450.0f, ImFont* tooltipFont = nullptr);

// Utilities for rendering text in an overlay (not tied to a window)
// Render floating text (not tied to a window)
IMGUI_API void RenderText(const ImVec2& pos, const ImVec4& color, const char* fmt, ...);
IMGUI_API void RenderText(int x, int y, const ImVec4& color, const char* fmt, ...);

IMGUI_API void RenderTextCentered(const ImVec2& pos, const ImVec4& color, const char* fmt, ...);
IMGUI_API void RenderTextCentered(int x, int y, const ImVec4& color, const char* fmt, ...);
IMGUI_API void RenderTextRight(const ImVec2& pos, const ImVec4& color, const char* fmt, ...);
IMGUI_API void RenderTextRight(int x, int y, const ImVec4& color, const char* fmt, ...);

// Like collapsing header, but styles to look like a sub-heading
IMGUI_API bool CollapsingSubHeader(const char* label, bool* p_open, ImGuiTreeNodeFlags flags = 0);
IMGUI_API bool CollapsingSubHeader(const char* label, ImGuiTreeNodeFlags flags = 0);

//----------------------------------------------------------------------------
// Font/Style configuration

// Configure fonts. Only needs to be called when imgui is initialized
IMGUI_API void ConfigureFonts(ImFontAtlas* atlas);

// Our fonts. You can push/pop fonts to change fonts.
IMGUI_API extern ImFont* DefaultFont;
IMGUI_API extern ImFont* ConsoleFont;
IMGUI_API extern ImFont* LargeTextFont;
IMGUI_API extern ImFont* LargeIconFont; // deprecated, duplicates LargeTextFont

// Configure style. Only needs to be called when imgui is initialized
IMGUI_API void ConfigureStyle();

//----------------------------------------------------------------------------
// ColumnHeaders
// This is deprecated with the new tables api. Only preserved here for backwards compatibility
// with MQ2Nav. Use tables instead!

struct ColumnHeader
{
	const char* label = nullptr;       // Label of the header
	float size        = -1.0f;         // Negative value will calculate the size to fit label
	float sizeMIN     = -1.0f;         // Negative value will calculate the size to fit label
	bool allowResize  = true;          // Allow user-resize
};

// Draw column headers
IMGUI_API void ColumnHeaders(const char* columnsId, ColumnHeader* headers, int count, bool border = true);

// Synchronize with column headers
IMGUI_API void BeginColumnHeadersSync(const char* columnsId, ColumnHeader* headers, int count, bool border = true);
IMGUI_API void EndColumnHeadersSync(ColumnHeader* headers, int count);


}} // namespace mq::imgui
