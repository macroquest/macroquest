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

#include "pch.h"
#include "ImGuiDrawListExtensions.h"

static inline float Clamp01(float v)
{
	if (v < 0.0f) return 0.0f;
	if (v > 1.0f) return 1.0f;
	return v;
}

static inline ImVec4 LerpColor(const ImVec4& a, const ImVec4& b, float t)
{
	t = Clamp01(t);
	return ImVec4(
		a.x + (b.x - a.x) * t,
		a.y + (b.y - a.y) * t,
		a.z + (b.z - a.z) * t,
		a.w + (b.w - a.w) * t);
}

namespace mq {
namespace imgui {

//helpers
static inline float ComputeGradientT(const ImVec2& p, const ImVec2& p_min, const ImVec2& p_max, ImGradientDir dir)
{
	const float w = (p_max.x - p_min.x);
	const float h = (p_max.y - p_min.y);

	switch (dir)
	{
	case ImGradientDir::Horizontal:
		return (w != 0.0f) ? (p.x - p_min.x) / w : 0.0f;

	case ImGradientDir::Vertical:
		return (h != 0.0f) ? (p.y - p_min.y) / h : 0.0f;

	case ImGradientDir::DiagTopLeftBottomRight:
		return ((w + h) != 0.0f) ? ((p.x - p_min.x) + (p.y - p_min.y)) / (w + h) : 0.0f;

	case ImGradientDir::DiagTopRightBottomLeft:
		return ((w + h) != 0.0f) ? ((p_max.x - p.x) + (p.y - p_min.y)) / (w + h) : 0.0f;
	}

	return 0.0f;
}

// AddRectGradientFilled
// ----------------------------
// Draw a rect filled with a gradient between 2 colors, with options for rounding and gradient direction.
// If you want a gradient between more than 2 colors then you should use `AddRectFilledMultiColor`
// but it doesn't support rounding or gradient direction options.
//
// This is not anti-aliased using this approach, instead the gradient is drawn in slices.
// 
// - Gradient Directions are (Horizontal, Vertical, Diagonal TL-BR, Diagonal TR-BL)
// -- default is horizontal if not supplied.
void AddRectGradientFilled(ImDrawList& draw_list, const ImVec2& p_min, const ImVec2& p_max, ImU32 col_start, ImU32 col_end, ImGradientDir dir, float rounding, ImDrawFlags flags)
{
	if (((col_start | col_end) & IM_COL32_A_MASK) == 0)
		return;

	const float width = p_max.x - p_min.x;
	const float height = p_max.y - p_min.y;
	if (width <= 0.0f || height <= 0.0f)
		return;

	// if not rounding and not a diagonal gradient we can just pass this to AddRectFilledMultiColor
	if (rounding <= 0.0f)
	{
		if (dir == ImGradientDir::Horizontal)
		{
			draw_list.AddRectFilledMultiColor(p_min, p_max, col_start, col_end, col_end, col_start);
			return;
		}
		if (dir == ImGradientDir::Vertical)
		{
			draw_list.AddRectFilledMultiColor(p_min, p_max, col_start, col_start, col_end, col_end);
			return;
		}
	}
	else
	{
		// ensure the rounding radius is not larger than half the smallest side
		const float max_rounding = (width < height ? width : height) * 0.5f;
		if (rounding > max_rounding)
			rounding = max_rounding;
	}

	const ImVec4 c0 = ImGui::ColorConvertU32ToFloat4(col_start);
	const ImVec4 c1 = ImGui::ColorConvertU32ToFloat4(col_end);

	// use slices for diagonal gradients or when rounding.
	// without imgui_internals we can't access draw_list._Data
	// instead we will build the gradient by drawing the rectange in slices
	constexpr float slice_target_size = 2.0f;

	if (dir == ImGradientDir::Horizontal)
	{
		const int slices = (int)(width / slice_target_size) + 1;
		const float dx = width / (float)slices;

		for (int i = 0; i < slices; ++i)
		{
			const float x0 = p_min.x + dx * i;
			const float x1 = (i == slices - 1) ? p_max.x : (x0 + dx);
			const float cx = (x0 + x1) * 0.5f;

			const float t = ComputeGradientT(ImVec2(cx, (p_min.y + p_max.y) * 0.5f), p_min, p_max, dir);
			const ImU32 col = ImGui::ColorConvertFloat4ToU32(LerpColor(c0, c1, t));

			draw_list.PushClipRect(ImVec2(x0, p_min.y), ImVec2(x1, p_max.y), true);
			draw_list.AddRectFilled(p_min, p_max, col, rounding, flags);
			draw_list.PopClipRect();
		}
		return;
	}

	if (dir == ImGradientDir::Vertical)
	{
		const int slices = (int)(height / slice_target_size) + 1;
		const float dy = height / (float)slices;

		for (int i = 0; i < slices; ++i)
		{
			const float y0 = p_min.y + dy * i;
			const float y1 = (i == slices - 1) ? p_max.y : (y0 + dy);
			const float cy = (y0 + y1) * 0.5f;

			const float t = ComputeGradientT(ImVec2((p_min.x + p_max.x) * 0.5f, cy), p_min, p_max, dir);
			const ImU32 col = ImGui::ColorConvertFloat4ToU32(LerpColor(c0, c1, t));

			draw_list.PushClipRect(ImVec2(p_min.x, y0), ImVec2(p_max.x, y1), true);
			draw_list.AddRectFilled(p_min, p_max, col, rounding, flags);
			draw_list.PopClipRect();
		}
		return;
	}

	// Diagonal gradients draw in a grid of slices
	const int cols = (int)(width / slice_target_size) + 1;
	const int rows = (int)(height / slice_target_size) + 1;
	const float dx = width / (float)cols;
	const float dy = height / (float)rows;

	for (int row = 0; row < rows; ++row)
	{
		const float y0 = p_min.y + dy * row;
		const float y1 = (row == rows - 1) ? p_max.y : (y0 + dy);

		for (int col = 0; col < cols; ++col)
		{
			const float x0 = p_min.x + dx * col;
			const float x1 = (col == cols - 1) ? p_max.x : (x0 + dx);

			const ImVec2 center((x0 + x1) * 0.5f, (y0 + y1) * 0.5f);
			const float t = ComputeGradientT(center, p_min, p_max, dir);
			const ImU32 col_u32 = ImGui::ColorConvertFloat4ToU32(LerpColor(c0, c1, t));

			draw_list.PushClipRect(ImVec2(x0, y0), ImVec2(x1, y1), true);
			draw_list.AddRectFilled(p_min, p_max, col_u32, rounding, flags);
			draw_list.PopClipRect();
		}
	}
}

}} // namespace mq::imgui
