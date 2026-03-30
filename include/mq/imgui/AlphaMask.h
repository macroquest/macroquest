/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
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

#include "mq/base/Common.h"

#include <cstdint>

struct ImDrawList;
struct ImVec2;

namespace mq::imgui {

//============================================================================
// Stencil-based alpha masking for ImDrawList
//
// A mask is built from one or more image layers whose alpha channel defines
// the visible region. After the layers are defined, BeginMaskedDraw / EndMaskedDraw
// scope the draw calls that are clipped to the combined mask.
//
// Usage - single layer:
//   mq::imgui::CreateMaskLayer(draw_list);
//     mq::imgui::AddImageNineSlice(...);   // texture alpha defines the visible region
//   mq::imgui::BeginMaskedDraw(draw_list);
//     draw_list->AddImage(...);            // clipped to the mask shape
//   mq::imgui::EndMaskedDraw(draw_list);
//
// Usage - multiple layers combined with an op:
//   mq::imgui::CreateMaskLayer(draw_list);   // layer 0
//     mq::imgui::AddImageNineSlice(..., octagonMask);
//   mq::imgui::CreateMaskLayer(draw_list);   // layer 1
//     mq::imgui::AddImageNineSlice(..., roundRectMask);
//   mq::imgui::BeginMaskedDraw(draw_list, mq::imgui::AlphaMaskOp::Union);
//     draw_list->AddImage(...);   // visible inside octagon OR round-rect
//   mq::imgui::EndMaskedDraw(draw_list);
//
// Notes:
//   - Only texels with alpha >= 0.5 write to the stencil; transparent texels are
//     discarded. Mask boundaries are therefore hard-edged.
//   - Up to 8 independent layers can be combined.
//   - All stencil bits are cleared automatically at EndMaskedDraw and at the start
//     of each rendered frame.
//============================================================================

// Hardware test applied at render time: (stencil & ReadMask) FUNC Ref
// C = the bit assigned to the most recent CreateAlphaMaskLayer call
// A = all active bits combined (all layer calls so far in this session)
enum class AlphaMaskOp : uint8_t
{
	Intersect  = 0,  // Visible inside ALL layers          - ReadMask=A, EQUAL,     Ref=A
	Union      = 1,  // Visible inside ANY layer           - ReadMask=A, NOT_EQUAL, Ref=0        [default]
	Subtract   = 2,  // Inside previous layers, NOT this   - ReadMask=A, EQUAL,     Ref=A&~C
	Complement = 3,  // Outside ALL layers                 - ReadMask=A, EQUAL,     Ref=0
};

// Begins a new mask layer. Each call auto-assigns the next available stencil bit
// (up to 8 per session). Draw mask image(s) after this call using AddImage or
// AddImageNineSlice - only texels with alpha >= 0.5 write to the stencil.
// Call up to 8 times before BeginMaskedDraw.
MQLIB_OBJECT void CreateMaskLayer(ImDrawList* draw_list);

// Commits all mask layers and begins the masked drawing scope. The given op controls
// how multiple layers are combined. All draw calls between here and EndMaskedDraw are
// clipped to the combined mask shape.
MQLIB_OBJECT void BeginMaskedDraw(ImDrawList* draw_list, AlphaMaskOp op = AlphaMaskOp::Union);

// Ends the masked drawing scope and restores default render state.
// Stencil bits are reclaimed automatically at the next frame start.
MQLIB_OBJECT void EndMaskedDraw(ImDrawList* draw_list);


//============================================================================
// Framebuffer-alpha masking for ImDrawList
//
// A mask texture's alpha channel is composited into the framebuffer's own
// alpha, which is then used as per-pixel coverage when drawing content. This
// produces feathered / anti-aliased edges wherever the mask is semi-transparent,
// unlike the hard-edged stencil variant above.
//
// Usage:
//   mq::imgui::CreateCoverageMaskLayer(draw_list, pos_min, pos_max);
//     draw_list->AddImage(...);       // write to fb alpha
//   mq::imgui::BeginCoverageMaskedDraw(draw_list);
//     draw_list->AddRectFilled(...);  // blended by fb alpha coverage
//     draw_list->AddText(...);
//   mq::imgui::EndCoverageMaskedDraw(draw_list);
//
// Notes:
//   - CreateCoverageMaskLayer pushes a clip rect to p_min/p_max and clears
//     the framebuffer alpha in that region to exactly 0 before mask drawing begins.
//   - EndAlphaBlendedDraw pops that clip rect and restores the default blend state.
//   - Only one coverage-mask session should be open at a time.
//============================================================================

// Begins a coverage mask for the given screen region. Pushes a clip rect,
// clears framebuffer alpha to 0 inside the region, and switches to alpha-write
// mode. Draw the mask texture(s) after this call.
MQLIB_OBJECT void CreateCoverageMaskLayer(ImDrawList* draw_list, const ImVec2& p_min, const ImVec2& p_max);

// Commits the mask and begins the coverage-masked drawing scope. Draw calls issued
// between here and EndAlphaBlendedDraw are blended using the framebuffer alpha
// written by the mask textures as per-pixel coverage.
MQLIB_OBJECT void BeginCoverageMaskedDraw(ImDrawList* draw_list);

// Ends the coverage-masked drawing scope, restores the default blend state, and
// pops the clip rect pushed by CreateCoverageMaskLayer.
MQLIB_OBJECT void EndCoverageMaskedDraw(ImDrawList* draw_list);

} // namespace mq::imgui
