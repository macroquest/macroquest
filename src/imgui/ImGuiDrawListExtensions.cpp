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

#include "imgui/imgui_internal.h"

namespace mq {
namespace imgui {

	// helpers
	static inline void Normalize2fOverZero(float& x, float& y)
	{
		const float d2 = x * x + y * y;
		if (d2 > 0.0f)
		{
			const float inv_len = ImRsqrt(d2);
			x *= inv_len;
			y *= inv_len;
		}
	}

	static inline void FixNormal2f(float& x, float& y)
	{
		// Mirrors upstream intent (see ImGui issues #4053, #3366).
		constexpr float FixNormalMaxInvLen2 = 100.0f;

		const float d2 = x * x + y * y;
		if (d2 > 0.000001f)
		{
			float inv_len2 = 1.0f / d2;
			if (inv_len2 > FixNormalMaxInvLen2)
				inv_len2 = FixNormalMaxInvLen2;

			x *= inv_len2;
			y *= inv_len2;
		}
	}

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
	// If you want a gradient between more than 2 colors then you should use `AddRectFilledMultiColor`, but it doesn't support rounding or gradient direction options.
	//
	// - We use PathRect() to generate rounded outline points into draw_list._Path.
	// - Interior fill is a triangle fan of the inner vertices.
	// - Anti-aliased fringe is generated like AddConvexPolyFilled (inner/outer ring).
	// - Gradient Directions are (Horizontal, Vertical, Diagonal TL-BR, Diagonal TR-BL)
	// -- default is horizontal if not supplied.
	void AddRectGradientFilled(
		ImDrawList& draw_list,
		const ImVec2& p_min,
		const ImVec2& p_max,
		ImU32 col_start,
		ImU32 col_end,
		ImGradientDir dir,
		float rounding,
		ImDrawFlags flags)
	{
		// Fully transparent => nothing to draw
		if (((col_start | col_end) & IM_COL32_A_MASK) == 0)
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
			const float max_rounding = ImMin(p_max.x - p_min.x, p_max.y - p_min.y) * 0.5f;
			rounding = ImMin(rounding, max_rounding);
		}

		draw_list.PathRect(p_min, p_max, rounding, flags);
		const int points_count = draw_list._Path.Size;
		if (points_count < 3)
		{
			draw_list.PathClear();
			return;
		}

		const ImVec4 c0 = ImGui::ColorConvertU32ToFloat4(col_start);
		const ImVec4 c1 = ImGui::ColorConvertU32ToFloat4(col_end);

		const ImVec2 uv = draw_list._Data->TexUvWhitePixel;

		const float aa_size = draw_list._FringeScale;
		const int idx_count = (points_count - 2) * 3 + points_count * 6;
		const int vtx_count = points_count * 2;

		draw_list.PrimReserve(idx_count, vtx_count);

		const unsigned int vtx_inner_idx = draw_list._VtxCurrentIdx;
		const unsigned int vtx_outer_idx = draw_list._VtxCurrentIdx + 1;

		// 1) Interior fill (triangle fan)
		for (int i = 2; i < points_count; ++i)
		{
			draw_list._IdxWritePtr[0] = (ImDrawIdx)(vtx_inner_idx);
			draw_list._IdxWritePtr[1] = (ImDrawIdx)(vtx_inner_idx + (i - 1) * 2);
			draw_list._IdxWritePtr[2] = (ImDrawIdx)(vtx_inner_idx + i * 2);
			draw_list._IdxWritePtr += 3;
		}

		// 2) Edge normals for AA fringe
		draw_list._Data->TempBuffer.reserve_discard(points_count);
		ImVec2* edge_normals = draw_list._Data->TempBuffer.Data;

		for (int i0 = points_count - 1, i1 = 0; i1 < points_count; i0 = i1++)
		{
			const ImVec2& p0 = draw_list._Path[i0];
			const ImVec2& p1 = draw_list._Path[i1];

			float dx = p1.x - p0.x;
			float dy = p1.y - p0.y;
			Normalize2fOverZero(dx, dy);

			edge_normals[i0].x = dy;
			edge_normals[i0].y = -dx;
		}

		// 3) Emit vertices + fringe indices
		for (int i0 = points_count - 1, i1 = 0; i1 < points_count; i0 = i1++)
		{
			const ImVec2& n0 = edge_normals[i0];
			const ImVec2& n1 = edge_normals[i1];

			float nx = (n0.x + n1.x) * 0.5f;
			float ny = (n0.y + n1.y) * 0.5f;
			FixNormal2f(nx, ny);

			nx *= aa_size * 0.5f;
			ny *= aa_size * 0.5f;

			const ImVec2& p = draw_list._Path[i1];

			// Sample at inner vertex position to keep gradient aligned with shaded geometry.
			const ImVec2 inner_pos(p.x - nx, p.y - ny);

			float t = ComputeGradientT(inner_pos, p_min, p_max, dir);
			t = ImClamp(t, 0.0f, 1.0f);

			const ImU32 col = ImGui::ColorConvertFloat4ToU32(ImLerp(c0, c1, t));
			const ImU32 col_trans = col & ~IM_COL32_A_MASK;

			ImDrawVert& vtx_inner = draw_list._VtxWritePtr[0];
			ImDrawVert& vtx_outer = draw_list._VtxWritePtr[1];

			vtx_inner.pos = inner_pos;
			vtx_inner.uv = uv;
			vtx_inner.col = col;

			vtx_outer.pos = ImVec2(p.x + nx, p.y + ny);
			vtx_outer.uv = uv;
			vtx_outer.col = col_trans;

			draw_list._VtxWritePtr += 2;

			draw_list._IdxWritePtr[0] = (ImDrawIdx)(vtx_inner_idx + i1 * 2);
			draw_list._IdxWritePtr[1] = (ImDrawIdx)(vtx_inner_idx + i0 * 2);
			draw_list._IdxWritePtr[2] = (ImDrawIdx)(vtx_outer_idx + i0 * 2);

			draw_list._IdxWritePtr[3] = (ImDrawIdx)(vtx_outer_idx + i0 * 2);
			draw_list._IdxWritePtr[4] = (ImDrawIdx)(vtx_outer_idx + i1 * 2);
			draw_list._IdxWritePtr[5] = (ImDrawIdx)(vtx_inner_idx + i1 * 2);

			draw_list._IdxWritePtr += 6;
		}

		draw_list._VtxCurrentIdx += (ImDrawIdx)vtx_count;
		draw_list.PathClear();
	}

}} // namespace mq::imgui
