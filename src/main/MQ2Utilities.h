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

#include "MQ2MainBase.h"

#include <mq/base/Color.h>

namespace mq {

// Format a number of bytes into a string with the appropriate unit.
MQLIB_API void FormatBytes(char* szBuffer, size_t bufferLength, uint64_t bytes);

template <size_t Size>
void FormatBytes(char(&szBuffer)[Size], uint64_t bytes) {
	FormatBytes(szBuffer, Size, bytes);
}

enum class GetMoneyFromStringFormat {
	Long = 0,       // e.g. pp, gp, sp, cp
	Short = 1,      // e.g. p, g, s, c
};

MQLIB_API uint64_t GetMoneyFromString(const char* string, GetMoneyFromStringFormat format = GetMoneyFromStringFormat::Long);

MQLIB_API void FormatMoneyString(char* szBuffer, size_t bufferLength, uint64_t moneyAmount, GetMoneyFromStringFormat format = GetMoneyFromStringFormat::Long);

template <size_t Size>
void FormatMoneyString(char(&szBuffer)[Size], uint64_t moneyAmount, GetMoneyFromStringFormat format = GetMoneyFromStringFormat::Long) {
	FormatMoneyString(szBuffer, Size, moneyAmount, format);
}

} // namespace mq
