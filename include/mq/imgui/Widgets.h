/*
 * MacroQuest: The extension platform for EverQuest
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

#include <mq/base/Common.h>
#include "eqlib/Common.h"

namespace eqlib {
	class CTextureAnimation;
}

namespace mq::imgui {

// Draw a CTextureAnimation. Uses the provided size, if available. Otherwise, uses the
// internally specified size of the texture.
MQLIB_API bool DrawTextureAnimation(const eqlib::CTextureAnimation* textureAnimation, const eqlib::CXSize& size = eqlib::CXSize());

// Draws a text link styled like an item link. Returns true if the link has been clicked.
MQLIB_API bool ItemLinkText(const char* fmt, ...);
MQLIB_API bool ItemLinkTextV(const char* fmt, va_list);

} // namespace mq::imgui
