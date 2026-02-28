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
#include "imanim/im_anim.h"
#include "imgui/imgui_internal.h"

// Helpers from imgui_draw.cpp
// 
// Normalize (x,y) if length > 0.0f; otherwise leave unchanged.
static inline void Normalize2fOverZero(float& x, float& y)
{
	const float d2 = x * x + y * y;
	if (d2 > 0.0f)
	{
		// ImRsqrt is provided by imgui_internal.h
		const float inv_len = ImRsqrt(d2);
		x *= inv_len;
		y *= inv_len;
	}
}

// Helper used by ImGui's AA fringe generation: scales by inv_len^2 and clamps
// to avoid extremely large normals on nearly-degenerate segments.
static inline void FixNormal2f(float& x, float& y)
{
	// This mirrors the intent in upstream imgui_draw.cpp (see ImGui issues #4053, #3366).
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



namespace mq {
namespace imgui {

//============================================================================

// AddRectFilledMultiColorRounded
// ------------------------------
// Draw a rounded rect filled with a 4-corner (bilinear) gradient.
//
// - We call PathRect() to generate the rounded outline points into draw_list._Path.
// - We fill the interior using a triangle fan over the "inner" vertices.
// - We generate an anti-aliased fringe ring around the shape (like ImDrawList::AddConvexPolyFilled),
//   computing per-vertex normals from the outline.
// - Each vertex color is computed by bilinear interpolation of the four corner colors based on its (u,v)
//   position within the rectangle.
void AddRectFilledMultiColorRounded(ImDrawList& draw_list, const ImVec2& p_min, const ImVec2& p_max, ImU32 col_upr_left, ImU32 col_upr_right, ImU32 col_bot_right, ImU32 col_bot_left, float rounding, ImDrawFlags flags)
{
	// All corners fully transparent => nothing to draw
	if (((col_upr_left | col_upr_right | col_bot_right | col_bot_left) & IM_COL32_A_MASK) == 0)
		return;

	// If no rounding requested, use built-in multicolor rect and exit.
	if (rounding <= 0.0f)
	{
		draw_list.AddRectFilledMultiColor(p_min, p_max, col_upr_left, col_upr_right, col_bot_right, col_bot_left);
		return;
	}

	// Build the rounded outline path.
	draw_list.PathRect(p_min, p_max, rounding, flags);
	const int points_count = draw_list._Path.Size;
	if (points_count < 3)
	{
		draw_list.PathClear();
		return;
	}

	// Corner colors as float4 for lerping
	const ImVec4 ul = ImGui::ColorConvertU32ToFloat4(col_upr_left);
	const ImVec4 ur = ImGui::ColorConvertU32ToFloat4(col_upr_right);
	const ImVec4 br = ImGui::ColorConvertU32ToFloat4(col_bot_right);
	const ImVec4 bl = ImGui::ColorConvertU32ToFloat4(col_bot_left);

	const float w = (p_max.x - p_min.x);
	const float h = (p_max.y - p_min.y);
	const float inv_w = (w != 0.0f) ? (1.0f / w) : 0.0f;
	const float inv_h = (h != 0.0f) ? (1.0f / h) : 0.0f;

	const ImVec2 uv = draw_list._Data->TexUvWhitePixel;

	// Reserve geometry:
	// - Inner fill uses (points_count - 2) triangles => (points_count - 2) * 3 indices
	// - AA fringe uses points_count quads => points_count * 6 indices
	// - For each outline point we emit 2 vertices (inner/outer)
	const float aa_size = draw_list._FringeScale;
	const int idx_count = (points_count - 2) * 3 + points_count * 6;
	const int vtx_count = points_count * 2;
	draw_list.PrimReserve(idx_count, vtx_count);

	const unsigned int vtx_inner_idx = draw_list._VtxCurrentIdx;
	const unsigned int vtx_outer_idx = draw_list._VtxCurrentIdx + 1;

	// 1) Fill interior (triangle fan using inner vertices)
	for (int i = 2; i < points_count; ++i)
	{
		draw_list._IdxWritePtr[0] = (ImDrawIdx)(vtx_inner_idx);
		draw_list._IdxWritePtr[1] = (ImDrawIdx)(vtx_inner_idx + (i - 1) * 2);
		draw_list._IdxWritePtr[2] = (ImDrawIdx)(vtx_inner_idx + i * 2);
		draw_list._IdxWritePtr += 3;
	}

	// 2) Compute normals per edge to create AA fringe.
	draw_list._Data->TempBuffer.reserve_discard(points_count);
	ImVec2* edge_normals = draw_list._Data->TempBuffer.Data;

	for (int i0 = points_count - 1, i1 = 0; i1 < points_count; i0 = i1++)
	{
		const ImVec2& p0 = draw_list._Path[i0];
		const ImVec2& p1 = draw_list._Path[i1];

		float dx = p1.x - p0.x;
		float dy = p1.y - p0.y;
		Normalize2fOverZero(dx, dy);

		// Per-edge normal (perpendicular to direction)
		edge_normals[i0].x = dy;
		edge_normals[i0].y = -dx;
	}

	// 3) Emit vertices + AA fringe indices
	for (int i0 = points_count - 1, i1 = 0; i1 < points_count; i0 = i1++)
	{
		const ImVec2& n0 = edge_normals[i0];
		const ImVec2& n1 = edge_normals[i1];

		// Average the adjacent edge normals to get a vertex normal.
		float nx = (n0.x + n1.x) * 0.5f;
		float ny = (n0.y + n1.y) * 0.5f;
		FixNormal2f(nx, ny);

		// Expand to inner/outer positions for AA fringe
		nx *= aa_size * 0.5f;
		ny *= aa_size * 0.5f;

		const ImVec2& p = draw_list._Path[i1];

		// Compute bilinear gradient coordinates
		const float u = (inv_w == 0.0f) ? 0.0f : (p.x - p_min.x) * inv_w;
		const float v = (inv_h == 0.0f) ? 0.0f : (p.y - p_min.y) * inv_h;

		const ImVec4 top = ImLerp(ul, ur, u);
		const ImVec4 bot = ImLerp(bl, br, u);
		const ImU32 col = ImGui::ColorConvertFloat4ToU32(ImLerp(top, bot, v));
		const ImU32 col_trans = col & ~IM_COL32_A_MASK;

		// Write inner + outer vertices
		ImDrawVert& vtx_inner = draw_list._VtxWritePtr[0];
		ImDrawVert& vtx_outer = draw_list._VtxWritePtr[1];

		vtx_inner.pos = ImVec2(p.x - nx, p.y - ny);
		vtx_inner.uv = uv;
		vtx_inner.col = col;

		vtx_outer.pos = ImVec2(p.x + nx, p.y + ny);
		vtx_outer.uv = uv;
		vtx_outer.col = col_trans;

		draw_list._VtxWritePtr += 2;

		// AA fringe quad indices (inner i0/i1 to outer i0/i1)
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

//============================================================================

// AddRectFilledMultiColorRoundedAnimated
// -------------------------------------
// Uses MQ's ImAnim to tween each corner color (UL/UR/BR/BL) and then draws using
// AddRectFilledMultiColorRounded. This keeps the base draw call deterministic
// and makes animation opt-in.
void AddRectFilledMultiColorRoundedAnimated(ImDrawList& draw_list, ImGuiID anim_id, const ImVec2& p_min, const ImVec2& p_max, ImU32 col_upr_left, ImU32 col_upr_right, ImU32 col_bot_right, ImU32 col_bot_left, float rounding, ImDrawFlags flags, float duration)
{
	// If no smoothing requested, draw directly.
	if (duration <= 0.0f)
	{
		AddRectFilledMultiColorRounded(draw_list, p_min, p_max, col_upr_left, col_upr_right, col_bot_right, col_bot_left, rounding, flags);
		return;
	}

	const float dt = ImGui::GetIO().DeltaTime;

	// Pick sensible defaults (can be expanded later if needed).
	const iam_ease_desc ease{ iam_ease_in_out_cubic, 0, 0, 0, 0 };
	const int policy = iam_policy_crossfade;
	const int color_space = iam_col_srgb;

	const ImVec4 tgt_ul = ImGui::ColorConvertU32ToFloat4(col_upr_left);
	const ImVec4 tgt_ur = ImGui::ColorConvertU32ToFloat4(col_upr_right);
	const ImVec4 tgt_br = ImGui::ColorConvertU32ToFloat4(col_bot_right);
	const ImVec4 tgt_bl = ImGui::ColorConvertU32ToFloat4(col_bot_left);

	// Stable per-corner channels (hashed once per call; fine for this scope)
	const ImGuiID ch_ul = ImHashStr("mq.imgui.rect_multicolor_rounded.ul");
	const ImGuiID ch_ur = ImHashStr("mq.imgui.rect_multicolor_rounded.ur");
	const ImGuiID ch_br = ImHashStr("mq.imgui.rect_multicolor_rounded.br");
	const ImGuiID ch_bl = ImHashStr("mq.imgui.rect_multicolor_rounded.bl");

	// Use target as init value so the first frame doesn't animate from default white.
	const ImVec4 cur_ul = iam_tween_color(anim_id, ch_ul, tgt_ul, duration, ease, policy, color_space, dt, tgt_ul);
	const ImVec4 cur_ur = iam_tween_color(anim_id, ch_ur, tgt_ur, duration, ease, policy, color_space, dt, tgt_ur);
	const ImVec4 cur_br = iam_tween_color(anim_id, ch_br, tgt_br, duration, ease, policy, color_space, dt, tgt_br);
	const ImVec4 cur_bl = iam_tween_color(anim_id, ch_bl, tgt_bl, duration, ease, policy, color_space, dt, tgt_bl);

	AddRectFilledMultiColorRounded(draw_list, p_min, p_max, ImGui::ColorConvertFloat4ToU32(cur_ul), ImGui::ColorConvertFloat4ToU32(cur_ur), ImGui::ColorConvertFloat4ToU32(cur_br), ImGui::ColorConvertFloat4ToU32(cur_bl), rounding, flags);
}

}} // namespace mq::imgui
