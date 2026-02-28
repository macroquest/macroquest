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

#include "imgui/imgui.h"
#include "imanim/im_anim.h"

namespace mq {
namespace imgui {

// MQ extension: rounded + multicolor version of AddRectFilledMultiColor

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
IMGUI_API void AddRectFilledMultiColorRounded(ImDrawList& draw_list, const ImVec2& p_min, const ImVec2& p_max, ImU32 col_upr_left, ImU32 col_upr_right, ImU32 col_bot_right, ImU32 col_bot_left, float rounding = 0.0f, ImDrawFlags flags = 0);

// Animated variant using MQ ImAnim (smoothly tweens the 4 corner colors over time).
// anim_id should be stable across frames (e.g. ImGui::GetID("some key")).
IMGUI_API void AddRectFilledMultiColorRoundedAnimated(ImDrawList& draw_list, ImGuiID anim_id, const ImVec2& p_min, const ImVec2& p_max, ImU32 col_upr_left, ImU32 col_upr_right, ImU32 col_bot_right, ImU32 col_bot_left, float rounding = 0.0f, ImDrawFlags flags = 0, float duration = 0.10f);

}} // namespace mq::imgui
