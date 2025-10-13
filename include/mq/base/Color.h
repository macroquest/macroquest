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
#include "eqlib/game/Color.h"

#include <imgui/imgui.h>

namespace mq {

namespace detail
{
	struct InvalidHexChar {};

	constexpr int hexToDec(const char c)
	{
		return (c >= '0' && c <= '9') ? c - '0' : ((c >= 'a' && c <= 'f') ? c - 'a' + 10 : (c >= 'A' && c <= 'F') ? c - 'A' + 10
			: throw InvalidHexChar{});
	}
}

// MQColor is a color type that appears like a uint32_t but represents internally
// an ARGB color format. This is a color format commonly used by EQ.
// uint32 constants share a similar structure to the common rgb hex encoding:
// 0x00ff0000 would be red (0 alpha, 255 red, 0 green, 0 blue)

class MQColor
{
public:
	// default is opaque black
	constexpr MQColor()
		: Red(0)
		, Green(0)
		, Blue(0)
		, Alpha(255)
	{}

	constexpr MQColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255)
		: Blue(blue)
		, Green(green)
		, Red(red)
		, Alpha(alpha)
	{}

	constexpr MQColor(const MQColor& other)
		: ARGB(other.ARGB)
	{}

	struct bgr_t {};
	static const inline bgr_t format_bgr;

	struct abgr_t {};
	static const inline abgr_t format_abgr;

	struct argb_t {};
	static const inline argb_t format_argb;

	constexpr MQColor(bgr_t, uint32_t bgrcolor)
		: Blue((bgrcolor >> 16) & 0xff)
		, Green((bgrcolor >> 8) & 0xff)
		, Red((bgrcolor >> 0) & 0xff)
		, Alpha(255)
	{
	}

	constexpr MQColor(abgr_t, uint32_t bgracolor)
		: Blue((bgracolor >> 16) & 0xff)
		, Green((bgracolor >> 8) & 0xff)
		, Red((bgracolor >> 0) & 0xff)
		, Alpha((bgracolor >> 24) & 0xff)
	{
	}

	constexpr MQColor(argb_t, uint32_t argbcolor)
		: ARGB(argbcolor)
	{
	}

	constexpr MQColor(uint32_t argbcolor)
		: ARGB(argbcolor)
	{
	}

	constexpr MQColor(const char* str)
		: Blue(static_cast<uint8_t>(detail::hexToDec(str[5]) << 4 | detail::hexToDec(str[6])) & 0xff)
		, Green(static_cast<uint8_t>(detail::hexToDec(str[3]) << 4 | detail::hexToDec(str[4])) & 0xff)
		, Red(static_cast<uint8_t>(detail::hexToDec(str[1]) << 4 | detail::hexToDec(str[2])) & 0xff)
		, Alpha(255)
	{
		if (str[0] != '#') throw detail::InvalidHexChar();
	}

	constexpr MQColor(const ImColor& imColor)
		: Blue(static_cast<uint8_t>(imColor.Value.z * 255))
		, Green(static_cast<uint8_t>(imColor.Value.y * 255))
		, Red(static_cast<uint8_t>(imColor.Value.x * 255))
		, Alpha(static_cast<uint8_t>(imColor.Value.w * 255))
	{
	}

	constexpr MQColor(const ImVec4& imColor)
		: Blue(static_cast<uint8_t>(imColor.z * 255))
		, Green(static_cast<uint8_t>(imColor.y * 255))
		, Red(static_cast<uint8_t>(imColor.x * 255))
		, Alpha(static_cast<uint8_t>(imColor.w * 255))
	{
	}

	constexpr MQColor& operator=(uint32_t argbcolor)
	{
		ARGB = argbcolor;
		return *this;
	}

	constexpr MQColor& operator=(const MQColor& other)
	{
		ARGB = other.ARGB;
		return *this;
	}

	constexpr operator eqlib::ARGBCOLOR() const
	{
		eqlib::ARGBCOLOR color = {};
		color.ARGB = ARGB;
		return color;
	}

	// Explict because COLORREF is a typedef for unsigned long.
	constexpr explicit operator COLORREF() const
	{
		return ToARGB();
	}

	constexpr explicit operator uint32_t() const
	{
		return ToARGB();
	}

	constexpr uint32_t ToABGR() const
	{
		return (((uint32_t)(Alpha) << 24)
			| ((uint32_t)(Blue) << 16)
			| ((uint32_t)(Green) << 8)
			| ((uint32_t)(Red) << 0));
	}

	constexpr ImU32 ToImU32() const
	{
		return ToABGR();
	}

	ImColor ToImColor() const
	{
		return ImColor(Red, Green, Blue, Alpha);
	}

	constexpr uint32_t ToARGB() const
	{
		return ARGB;
	}

	constexpr void SetARGB(uint32_t value)
	{
		ARGB = value;
	}

	constexpr uint32_t ToRGB() const
	{
		return ARGB & 0xffffff;
	}

	constexpr uint32_t ToRGBA() const
	{
		return (ARGB & 0xffffff) << 8 | (ARGB & 0xff000000) >> 24;
	}

	constexpr void Invert()
	{
		ARGB = (0xFFFFFF - (ARGB & 0xFFFFFF)) | (ARGB & 0xFF000000);
	}

	constexpr MQColor GetInverted() const
	{
		return MQColor((0xFFFFFF - (ARGB & 0xFFFFFF)) | (ARGB & 0xFF000000));
	}

	constexpr MQColor operator+(MQColor other) const
	{
		return MQColor(
			static_cast<uint8_t>(std::min(std::max(Red + other.Red, 0), 255)),
			static_cast<uint8_t>(std::min(std::max(Green + other.Green, 0), 255)),
			static_cast<uint8_t>(std::min(std::max(Blue + other.Blue, 0), 255)),
			static_cast<uint8_t>(std::min(std::max(Alpha + other.Alpha, 0), 255))
		);
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

inline MQColor constexpr operator ""_color(const char* str)
{
	return MQColor(str);
}

inline bool operator==(const MQColor& left, const MQColor& right)
{
	return left.ARGB == right.ARGB;
}

inline bool operator!=(const MQColor& left, const MQColor& right)
{
	return left.ARGB != right.ARGB;
}

MQLIB_OBJECT std::string to_string(MQColor color);

// Get the MQColor for a given chat color. Respects user preference if
// it is available.
MQLIB_OBJECT MQColor GetColorForChatColor(uint32_t chatColor);

MQLIB_API uint32_t mqGetColorForChatColor(uint32_t chatColor);

} // namespace mq
