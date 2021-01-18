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

#include "MQ2MainBase.h"

namespace mq {

struct MQColor
{
	// default is opaque black
	MQLIB_OBJECT constexpr MQColor()
		: Red(0)
		, Green(0)
		, Blue(0)
		, Alpha(255)
	{}

	MQLIB_OBJECT constexpr MQColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255)
		: Blue(blue)
		, Green(green)
		, Red(red)
		, Alpha(alpha)
	{}

	MQLIB_OBJECT constexpr MQColor(uint32_t argbcolor)
		: ARGB(argbcolor)
	{}

	MQLIB_OBJECT constexpr operator ARGBCOLOR() const
	{
		ARGBCOLOR color = { 0 };
		color.ARGB = ARGB;
		return color;
	}

	MQLIB_OBJECT constexpr operator COLORREF() const
	{
		return ARGB;
	}

	MQLIB_OBJECT constexpr operator uint32_t() const
	{
		return ARGB;
	}

	MQLIB_OBJECT constexpr uint32_t ToRGBA8() const
	{
		return (((uint32_t)(Alpha) << 24)
			| ((uint32_t)(Blue) << 16)
			| ((uint32_t)(Green) << 8)
			| ((uint32_t)(Red) << 0));
	}

	// Layout matches ARGBCOLOR
	union
	{
		struct
		{
			uint8_t Blue;
			uint8_t Green;
			uint8_t Red;
			uint8_t Alpha;
		};

		uint32_t ARGB = 0;
	};
};

// Get the MQColor for a given chat color. Respects user preference if
// it is available.
MQLIB_OBJECT MQColor GetColorForChatColor(uint32_t chatColor);

MQLIB_API uint32_t mqGetColorForChatColor(uint32_t chatColor);

} // namespace mq
