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

namespace mq::imgui {

//----------------------------------------------------------------------------

// Creates a splitter that can be used to resize two panels.
IMGUI_API void DrawSplitter(bool split_vertically, float thickness, float* size0, float* size1,
	float min_size0, float min_size1);

// Draws a (?) marker with the provided text as its tooltip. Width defines the size of
// the tooltip box. The height will grow to fit.
IMGUI_API void HelpMarker(const char* text, float width = 450.0f, ImFont* tooltipFont = nullptr);
IMGUI_API void HelpMarker(const std::function<void(char*, size_t)>& getText, float width = 450.0f, ImFont* tooltipFont = nullptr);

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

//----------------------------------------------------------------------------
// Nine-slice image drawing

// Params describing the souurce image being used for a nine-slice image operation. This doesn't
// need to change between draw calls for the same image and could be made static. Use the named
// constructors to construct this struct using either pixel coordinates or texture coordinates:
// - WithTextureCoords for drawing with texture coordinates
// - WithPixelCoords for drawing with pixel coordinates
struct NineSliceImageParams
{
	// Image size
	ImVec2 p_min;               // pixel coordinates of the upper left corner of the image
	ImVec2 p_max;               // pixel coordiantes of the upper right corner of the image
	ImVec2 uv_min;              // texture coordinates of the upper left corner of the image
	ImVec2 uv_max;              // texture coordinates of the lower right corner of the image

	// Margins:
	ImVec4 p_margins;           // pixel sizes of the margins for cutting the image (left, top, right, bottom)
	ImVec4 uv_margins;          // texel sizes of the margins for cutting the image

	ImVec2 texture_size;        // size of the texture containing the image

protected:
	struct init_with_uv_coords {};
	constexpr NineSliceImageParams(init_with_uv_coords, const ImVec2& texture_size_, const ImVec4& p_margins_,
		const ImVec2& uv_min_ = ImVec2(0.0f, 0.00f), const ImVec2& uv_max_ = ImVec2(1.0f, 1.0f))
		: p_min(uv_min_.x * texture_size_.x, uv_min_.y * texture_size_.y)
		, p_max(uv_max_.x * texture_size_.x, uv_max_.y * texture_size_.y)
		, uv_min(uv_min_)
		, uv_max(uv_max_)
		, p_margins(ClampMargins(p_margins_))
		, uv_margins(
			p_margins.x / (p_max.x - p_min.x),
			p_margins.y / (p_max.y - p_min.y),
			p_margins.z / (p_max.x - p_min.x),
			p_margins.w / (p_max.y - p_min.y))
		, texture_size(texture_size_)
	{
	}

	struct init_with_p_coords {};
	constexpr NineSliceImageParams(init_with_p_coords, const ImVec2& texture_size_, const ImVec4& p_margins_,
		const ImVec2& p_min_ = ImVec2(0.0f, 0.0f), const ImVec2& p_max_ = ImVec2(-1.0f, -1.0f))
		: p_min(p_min_)
		, p_max(p_max_.x < 0 ? texture_size_.x : p_max_.x, p_max_.y < 0.0f ? texture_size_.y : p_max_.y)
		, uv_min(p_min.x / texture_size_.x, p_min.y / texture_size_.y)
		, uv_max(p_max.x / texture_size_.x, p_max.y / texture_size_.y)
		, p_margins(ClampMargins(p_margins_))
		, uv_margins(
			p_margins.x / (p_max.x - p_min.x),
			p_margins.y / (p_max.y - p_min.y),
			p_margins.z / (p_max.x - p_min.x),
			p_margins.w / (p_max.y - p_min.y))
		, texture_size(texture_size_)
	{
	}

	constexpr ImVec4 ClampMargins(const ImVec4& p_margins_)
	{
		ImVec4 out_margins;
		out_margins.x = p_margins_.x < 0.0f ? 0.0f : p_margins_.x;
		out_margins.y = p_margins_.y < 0.0f ? 0.0f : p_margins_.y;
		out_margins.z = p_margins_.z < 0.0f ? 0.0f : p_margins_.z;
		out_margins.w = p_margins_.w < 0.0f ? 0.0f : p_margins_.w;

		float p_width = p_max.x - p_min.x;
		if (p_width > 0)
		{
			if (out_margins.x + out_margins.z > p_width)
			{
				float scale = p_width / (out_margins.x + out_margins.z);
				out_margins.x *= scale;
				out_margins.z *= scale;
			}
		}

		float p_height = p_max.y - p_min.y;
		if (p_height > 0)
		{
			if (out_margins.y + out_margins.w > p_height)
			{
				float scale = p_height / (out_margins.y + out_margins.w);
				out_margins.y *= scale;
				out_margins.w *= scale;
			}
		}

		return out_margins;
	}

public:
	// Named constructor used to disambiguate between constructing using texture coordinates and pixel coordinates
	static constexpr NineSliceImageParams WithTextureCoords(
		const ImVec2& texture_size_,                       // full size of texture that contains the image being drawn
		const ImVec4& p_margins_,                          // pixel sizes of the margins from each edge used to slice, left top right bottom.
		const ImVec2& uv_min_ = ImVec2(0.0f, 0.00f),       // the upper left corner of the image to draw in texture coordinates (defaults to upper left)
		const ImVec2& uv_max_ = ImVec2(1.0f, 1.0f))        // the lower right corner of the image to draw in texture coordinates (defaults to full texture)
	{
		return NineSliceImageParams(NineSliceImageParams::init_with_uv_coords{}, texture_size_, p_margins_, uv_min_, uv_max_);
	}

	// Named constructor used to disambiguate between constructing using texture coordinates and pixel coordinates
	static constexpr NineSliceImageParams WithPixelCoords(
		const ImVec2& texture_size_,                       // full size of texture that contains the image being drawn
		const ImVec4& p_margins_,                          // pixel sizes of the margins from each edge used to slice, left top right bottom.
		const ImVec2& p_min_ = ImVec2(0.0f, 0.0f),         // the upper left corner of the image to draw in pixels (defaults to upper left)
		const ImVec2& p_max_ = ImVec2(-1.0f, -1.0f))       // the lower right corner of the image to draw in pixels (defaults to full texture)
	{
		return NineSliceImageParams(NineSliceImageParams::init_with_p_coords{}, texture_size_, p_margins_, p_min_, p_max_);
	}
};

// Draws a texture using the nine-slice (9-patch) pattern onto draw_list.
// margins defines the size of the fixed corner/edge regions in screen-space pixels:
//   x = left, y = top, z = right, w = bottom
// UV slice positions are derived proportionally from the margins relative to the
// destination rect size. If margins.x + margins.z exceed the dest width (or
// margins.y + margins.w exceed the height), they are scaled down proportionally.
IMGUI_API void AddImageNineSlice(
	ImDrawList* draw_list,
	ImTextureRef tex_ref,                         // texture
	const NineSliceImageParams& image_params,     // description of the image
	const ImVec2& p_min,                          // min screen coordinate of where to draw
	const ImVec2& p_max,                          // max screen coordinate of where to draw
	ImU32 col = IM_COL32_WHITE);                  // color fill

IMGUI_API void ImageNineSlice(
	ImTextureRef tex_ref,                         // texture
	const NineSliceImageParams& image_params,     // description of the image
	const ImVec2& size,                           // size to draw the image
	ImU32 col = IM_COL32_WHITE
);

} // namespace mq::imgui
