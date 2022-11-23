/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2022 MacroQuest Authors
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
#include "eqlib/Common.h"

namespace eqlib {
	class CTextureAnimation;
	struct CUITextureInfo;
	class CUITexturePiece;
}

namespace mq::imgui {

// Draws a CTextureAnimation. This is the preferred method for drawing a UI texture to imgui.
// This function uses the provided size, if available. Otherwise, it uses the internally
// specified size of the texture.
MQLIB_OBJECT bool DrawTextureAnimation(const eqlib::CTextureAnimation* textureAnimation, const eqlib::CXSize& size = eqlib::CXSize(),
	bool drawBorder = false);

// Draws a CUITextureInfo. This is the lowest level of the UI texture hierarchy, and represents a full individual texture.
MQLIB_OBJECT bool DrawUITexture(const eqlib::CUITextureInfo& textureInfo, const eqlib::CXRect& rect = eqlib::CXRect(0, 0, -1, -1),
	const eqlib::CXSize& size = eqlib::CXSize(), bool drawBorder = false);

// Draws a TexturePiece. srcRect can be used to draw only a sub-section of the full texture.
MQLIB_OBJECT bool DrawTexturePiece(const eqlib::CUITexturePiece& texturePiece, const eqlib::CXRect& srcRect, const eqlib::CXSize& imageSize, bool drawBorder = false);
MQLIB_OBJECT bool DrawTexturePiece(const eqlib::CUITexturePiece& texturePiece, const eqlib::CXSize& imageSize, bool drawBorder = false);

MQLIB_VAR mq::MQColor DefaultLinkHoverColor;

// Draws a text link styled like an item link. Returns true if the link has been clicked.
MQLIB_OBJECT bool ItemLinkText(std::string_view str, mq::MQColor color, mq::MQColor colorHovered = DefaultLinkHoverColor);

MQLIB_OBJECT bool ItemLinkTextV(const char* str_id, mq::MQColor color, const char* fmt, va_list args);
MQLIB_OBJECT bool ItemLinkText(const char* str_id, mq::MQColor color, const char* fmt, ...);

} // namespace mq::imgui
