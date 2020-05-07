/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#include "imconfig.h"
#include "imgui.h"

#include "fonts/IconsFontAwesome.h"
#include "fonts/IconsMaterialDesign.h"

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
IMGUI_API void ConfigureFonts();

// Our fonts. You can push/pop fonts to change fonts.
IMGUI_API extern ImFont* DefaultFont;
IMGUI_API extern ImFont* LargeTextFont;
IMGUI_API extern ImFont* LargeIconFont;
IMGUI_API extern ImFont* ConsoleFont;

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
