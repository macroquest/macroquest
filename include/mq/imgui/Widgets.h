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
#include "mq/base/Color.h"

#include "eqlib/Common.h"
#include "eqlib/game/UITypes.h"

namespace eqlib {
	class CScreenPieceTemplate;
	class CTextureAnimation;
	struct CUITextureInfo;
	class CUITexturePiece;
	class CSpellGemWnd;
}

using ImGuiSpellGemFlags = int;  // -> enum ImGuiSpellGemFlags_     // Flags: for mq::imgui::SpellGem

// Flags for SpellGem()
enum ImGuiSpellGemFlags_
{
	ImGuiSpellGemFlags_None = 0,
	ImGuiSpellGemFlags_AllowSpellCast    = 1 << 0,   // Allow casting spell with left click
	ImGuiSpellGemFlags_AllowUnmemorize   = 1 << 1,   // Allow unmemorizing spell with right click
	ImGuiSpellGemFlags_AllowSpellDrag    = 1 << 2,   // Allow dragging spell with left click and hold

	ImGuiSpellGemFlags_AllowAll          = ImGuiSpellGemFlags_AllowSpellCast | ImGuiSpellGemFlags_AllowUnmemorize | ImGuiSpellGemFlags_AllowSpellDrag,
};

namespace mq::imgui {

constexpr MQColor NoBorderColor = MQColor(0, 0, 0, 0); // No border
constexpr MQColor DefaultBorderColor = MQColor(255, 255, 255, 127); // Light white border
constexpr MQColor DefaultTintColor = MQColor(255, 255, 255, 255); // White/clear

// Draws a CTextureAnimation. This is the preferred method for drawing a UI texture to imgui.
// This function uses the provided size, if available. Otherwise, it uses the internally
// specified size of the texture.
MQLIB_OBJECT bool DrawTextureAnimation(
	const eqlib::CTextureAnimation* textureAnimation,
	const eqlib::CXSize& size = eqlib::CXSize(),
	const MQColor& tintColor = DefaultTintColor,
	const MQColor& borderColor = NoBorderColor);

inline bool DrawTextureAnimation(
	const eqlib::CTextureAnimation* textureAnimation,
	const eqlib::CXSize& size,
	bool drawBorder)
{
	return DrawTextureAnimation(textureAnimation, size, DefaultTintColor, drawBorder ? DefaultBorderColor : NoBorderColor);
}

// Draws a CUITextureInfo at the current cursor location. This is the lowest level of the UI texture hierarchy, and represents a full individual texture.
MQLIB_OBJECT bool DrawUITexture(
	const eqlib::CUITextureInfo& textureInfo,
	const eqlib::CXSize& size = eqlib::CXSize(),
	const eqlib::CXRect& sourceRect = eqlib::CXRect(0, 0, -1, -1),
	const MQColor& tintColor = DefaultTintColor,
	const MQColor& borderColor = NoBorderColor);

inline bool DrawUITexture(
	const eqlib::CUITextureInfo& textureInfo,
	const eqlib::CXSize& size,
	const eqlib::CXRect& sourceRect,
	bool drawBorder)
{
	return DrawUITexture(textureInfo, size, sourceRect, DefaultTintColor, drawBorder ? DefaultBorderColor : NoBorderColor);
}

// Draws a TexturePiece. srcRect can be used to draw only a subsection of the full texture.
MQLIB_OBJECT bool DrawTexturePiece(
	const eqlib::CUITexturePiece& texturePiece,
	const eqlib::CXSize& size,
	const eqlib::CXRect& sourceRect,
	const MQColor& tintColor = DefaultTintColor,
	const MQColor& borderColor = NoBorderColor);

inline bool DrawTexturePiece(
	const eqlib::CUITexturePiece& texturePiece,
	const eqlib::CXSize& imageSize,
	const eqlib::CXRect& sourceRect,
	bool drawBorder)
{
	return DrawTexturePiece(texturePiece, imageSize, sourceRect, DefaultTintColor, drawBorder ? DefaultBorderColor : NoBorderColor);
}

// Draw a TexturePiece
MQLIB_OBJECT bool DrawTexturePiece(
	const eqlib::CUITexturePiece& texturePiece,
	const eqlib::CXSize& imageSize,
	const MQColor& tintColor = DefaultTintColor,
	const MQColor& borderColor = NoBorderColor);

inline bool DrawTexturePiece(
	const eqlib::CUITexturePiece& texturePiece,
	const eqlib::CXSize& imageSize,
	bool drawBorder)
{
	return DrawTexturePiece(texturePiece, imageSize, DefaultTintColor, drawBorder ? DefaultBorderColor : NoBorderColor);
}


//
// Same as above drawing APIs, but allow drawing to a drawlist instead of the current window.
//

// Adds a TextureAnimation to the specified draw list. This is the preferred method for drawing a UI texture to imgui.
// This function uses the provided size, if available. Otherwise, it uses the internally
// specified size of the texture.
MQLIB_OBJECT bool DrawTextureAnimation(
	ImDrawList* drawList,
	const eqlib::CTextureAnimation* textureAnimation,
	const eqlib::CXPoint& pos,
	const eqlib::CXSize& size = eqlib::CXSize(),
	const MQColor& tintColor = DefaultTintColor,
	const MQColor& borderColor = NoBorderColor);

inline bool DrawTextureAnimation(
	ImDrawList* drawList,
	const eqlib::CTextureAnimation* textureAnimation,
	const eqlib::CXRect& rect,
	const MQColor& tintColor = DefaultTintColor,
	const MQColor& borderColor = NoBorderColor)
{
	return DrawTextureAnimation(drawList, textureAnimation, rect.TopLeft(), rect.GetSize(), tintColor, borderColor);
}

inline bool AddTextureAnimation(
	ImDrawList* drawList,
	const eqlib::CTextureAnimation* textureAnimation,
	const eqlib::CXPoint& pos,
	const eqlib::CXSize& size = eqlib::CXSize(),
	const MQColor& tintColor = DefaultTintColor,
	const MQColor& borderColor = NoBorderColor)
{
	return DrawTextureAnimation(drawList, textureAnimation, pos, size, tintColor, borderColor);
}

// Adds a CUITextureInfo to the specified draw list. This is thbe lowest level of the UI texture hierarchy, and represents a full individual texture.
MQLIB_OBJECT bool DrawUITexture(
	ImDrawList* drawList,
	const eqlib::CUITextureInfo& textureInfo,
	const eqlib::CXPoint& pos,
	const eqlib::CXSize& size = eqlib::CXSize(),
	const eqlib::CXRect& sourceRect = eqlib::CXRect(0, 0, -1, -1),
	const MQColor& tintColor = DefaultTintColor,
	const MQColor& borderColor = NoBorderColor);

// Draws a TexturePiece. srcRect can be used to draw only a subsection of the full texture.
MQLIB_OBJECT bool DrawTexturePiece(
	ImDrawList* drawList,
	const eqlib::CUITexturePiece& texturePiece,
	const eqlib::CXPoint& pos,
	const eqlib::CXSize& size,
	const eqlib::CXRect& sourceRect,
	const MQColor& tintColor = DefaultTintColor,
	const MQColor& borderColor = NoBorderColor);

MQLIB_OBJECT bool DrawTexturePiece(
	ImDrawList* drawList,
	const eqlib::CUITexturePiece& texturePiece,
	const eqlib::CXPoint& pos,
	const eqlib::CXSize& size,
	const MQColor& tintColor = DefaultTintColor,
	const MQColor& borderColor = NoBorderColor);


//
// Draw EQ UI Components with ImGui
//

MQLIB_OBJECT void DrawScreenPiece(
	ImDrawList* drawList,
	const eqlib::CScreenPieceTemplate* pTemplate,
	const eqlib::CXRect& rect);

// Draw a SpellGem
MQLIB_OBJECT bool SpellGem(const char* strId, eqlib::CSpellGemWnd* pSpellGem, ImGuiSpellGemFlags flags = ImGuiSpellGemFlags_None);

// Draw a SpellGem to a draw list
MQLIB_OBJECT void DrawSpellGem(ImDrawList* drawList,
	const eqlib::CSpellGemWnd* pSpellGem,
	const eqlib::CXPoint& position,
	bool hovered = false);

// Draw a SpellGem to a draw list
//MQLIB_OBJECT void DrawSpellGem(ImDrawList* drawList, int SpellID, const CXRect& rect, bool hovered);

//
// Misc
//


// Draw text in the style of an EQ font. Flags is a value of DrawTextFlags.
MQLIB_OBJECT void DrawEQText(ImDrawList* drawList, int fontStyle, const char* text, const eqlib::CXRect& rect,
	MQColor color = MQColor(255, 255, 255), uint16_t flags = 0);

//
// 
//

constexpr mq::MQColor DefaultLinkHoverColor = MQColor(0, 0, 255);

// Draws a text link styled like an item link. Returns true if the link has been clicked.
MQLIB_OBJECT bool ItemLinkText(std::string_view str, mq::MQColor color, mq::MQColor colorHovered = DefaultLinkHoverColor);

MQLIB_OBJECT bool ItemLinkTextV(const char* str_id, mq::MQColor color, const char* fmt, va_list args);
MQLIB_OBJECT bool ItemLinkText(const char* str_id, mq::MQColor color, const char* fmt, ...);

} // namespace mq::imgui
