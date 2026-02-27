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

 // Needs internals because we use draw_list._Data->TempBuffer and IM_FIXNORMAL2F, etc.
#include "imgui/imgui_internal.h"

#include "ImGuiDrawListExtensions.h"

#define IM_NORMALIZE2F_OVER_ZERO(VX,VY)     { float d2 = VX*VX + VY*VY; if (d2 > 0.0f) { float inv_len = ImRsqrt(d2); VX *= inv_len; VY *= inv_len; } } (void)0
#define IM_FIXNORMAL2F_MAX_INVLEN2          100.0f // 500.0f (see #4053, #3366)
#define IM_FIXNORMAL2F(VX,VY)               { float d2 = VX*VX + VY*VY; if (d2 > 0.000001f) { float inv_len2 = 1.0f / d2; if (inv_len2 > IM_FIXNORMAL2F_MAX_INVLEN2) inv_len2 = IM_FIXNORMAL2F_MAX_INVLEN2; VX *= inv_len2; VY *= inv_len2; } } (void)0

namespace mq::imgui
{
	//tatic void AddRectFilledMultiColorRounded(const ImVec2& p_min, const ImVec2& p_max, ImU32 col_upr_left, ImU32 col_upr_right, ImU32 col_bot_right, ImU32 col_bot_left, float rounding, ImDrawFlags flags)

	void AddRectFilledMultiColorRounded(ImDrawList& draw_list, const ImVec2& p_min, const ImVec2& p_max, ImU32 col_upr_left, ImU32 col_upr_right, ImU32 col_bot_right, ImU32 col_bot_left, float rounding, ImDrawFlags flags)
	{
		if (((col_upr_left | col_upr_right | col_bot_right | col_bot_left) & IM_COL32_A_MASK) == 0)
			return;

		if (rounding <= 0.0f)
		{
			draw_list.AddRectFilledMultiColor(p_min, p_max, col_upr_left, col_upr_right, col_bot_right, col_bot_left);
			return;
		}

		draw_list.PathRect(p_min, p_max, rounding, flags);
		const int points_count = draw_list._Path.Size;
		if (points_count < 3)
		{
			draw_list.PathClear();
			return;
		}

		const ImVec4 ul = ImGui::ColorConvertU32ToFloat4(col_upr_left);
		const ImVec4 ur = ImGui::ColorConvertU32ToFloat4(col_upr_right);
		const ImVec4 br = ImGui::ColorConvertU32ToFloat4(col_bot_right);
		const ImVec4 bl = ImGui::ColorConvertU32ToFloat4(col_bot_left);

		const float w = (p_max.x - p_min.x);
		const float h = (p_max.y - p_min.y);
		const float inv_w = (w != 0.0f) ? (1.0f / w) : 0.0f;
		const float inv_h = (h != 0.0f) ? (1.0f / h) : 0.0f;
		const ImVec2 uv = draw_list._Data->TexUvWhitePixel;

		const float AA_SIZE = draw_list._FringeScale;
		const int idx_count = (points_count - 2) * 3 + points_count * 6;
		const int vtx_count = points_count * 2;
		draw_list.PrimReserve(idx_count, vtx_count);

		unsigned int vtx_inner_idx = draw_list._VtxCurrentIdx;
		unsigned int vtx_outer_idx = draw_list._VtxCurrentIdx + 1;
		for (int i = 2; i < points_count; i++)
		{
			draw_list._IdxWritePtr[0] = (ImDrawIdx)(vtx_inner_idx);
			draw_list._IdxWritePtr[1] = (ImDrawIdx)(vtx_inner_idx + ((i - 1) << 1));
			draw_list._IdxWritePtr[2] = (ImDrawIdx)(vtx_inner_idx + (i << 1));
			draw_list._IdxWritePtr += 3;
		}

		draw_list._Data->TempBuffer.reserve_discard(points_count);
		ImVec2* temp_normals = draw_list._Data->TempBuffer.Data;
		for (int i0 = points_count - 1, i1 = 0; i1 < points_count; i0 = i1++)
		{
			const ImVec2& p0 = draw_list._Path[i0];
			const ImVec2& p1 = draw_list._Path[i1];
			float dx = p1.x - p0.x;
			float dy = p1.y - p0.y;
			IM_NORMALIZE2F_OVER_ZERO(dx, dy);
			temp_normals[i0].x = dy;
			temp_normals[i0].y = -dx;
		}

		for (int i0 = points_count - 1, i1 = 0; i1 < points_count; i0 = i1++)
		{
			const ImVec2& n0 = temp_normals[i0];
			const ImVec2& n1 = temp_normals[i1];
			float dm_x = (n0.x + n1.x) * 0.5f;
			float dm_y = (n0.y + n1.y) * 0.5f;
			IM_FIXNORMAL2F(dm_x, dm_y);
			dm_x *= AA_SIZE * 0.5f;
			dm_y *= AA_SIZE * 0.5f;

			const ImVec2& p = draw_list._Path[i1];
			const float u = (inv_w == 0.0f) ? 0.0f : (p.x - p_min.x) * inv_w;
			const float v = (inv_h == 0.0f) ? 0.0f : (p.y - p_min.y) * inv_h;
			const ImVec4 top = ImLerp(ul, ur, u);
			const ImVec4 bot = ImLerp(bl, br, u);
			const ImU32  col = ImGui::ColorConvertFloat4ToU32(ImLerp(top, bot, v));
			const ImU32 col_trans = col & ~IM_COL32_A_MASK;

			draw_list._VtxWritePtr[0].pos.x = (p.x - dm_x); draw_list._VtxWritePtr[0].pos.y = (p.y - dm_y); draw_list._VtxWritePtr[0].uv = uv; draw_list._VtxWritePtr[0].col = col;
			draw_list._VtxWritePtr[1].pos.x = (p.x + dm_x); draw_list._VtxWritePtr[1].pos.y = (p.y + dm_y); draw_list._VtxWritePtr[1].uv = uv; draw_list._VtxWritePtr[1].col = col_trans;
			draw_list._VtxWritePtr += 2;

			draw_list._IdxWritePtr[0] = (ImDrawIdx)(vtx_inner_idx + (i1 << 1));
			draw_list._IdxWritePtr[1] = (ImDrawIdx)(vtx_inner_idx + (i0 << 1));
			draw_list._IdxWritePtr[2] = (ImDrawIdx)(vtx_outer_idx + (i0 << 1));
			draw_list._IdxWritePtr[3] = (ImDrawIdx)(vtx_outer_idx + (i0 << 1));
			draw_list._IdxWritePtr[4] = (ImDrawIdx)(vtx_outer_idx + (i1 << 1));
			draw_list._IdxWritePtr[5] = (ImDrawIdx)(vtx_inner_idx + (i1 << 1));
			draw_list._IdxWritePtr += 6;
		}

		draw_list._VtxCurrentIdx += (ImDrawIdx)vtx_count;
		draw_list.PathClear();
		return;
	}
}