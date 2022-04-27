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

#include <cstdint>

#ifdef MQ2MAIN_EXPORTS
#define MQLIB_API extern "C" __declspec(dllexport)
#define MQLIB_VAR extern "C" __declspec(dllexport)
#define MQLIB_OBJECT __declspec(dllexport)
#else
#define MQLIB_API extern "C" __declspec(dllimport)
#define MQLIB_VAR extern "C" __declspec(dllimport)
#define MQLIB_OBJECT __declspec(dllimport)
#endif

#ifdef MQ2PLUGIN
#define FromPlugin true
#else
#define FromPlugin false
#endif

#define STRINGIFY_IMPL(x) #x
#define STRINGIFY(x) STRINGIFY_IMPL(x)

#define UNUSED(x) ((void)(x))

#define LODWORD(_qw)          ((uint32_t)(_qw))
#define HIDWORD(_qw)          ((uint32_t)(((_qw) >> 32) & 0xffffffff))

constexpr int MAX_STRING = 2048;

template <typename T, size_t N>
constexpr size_t lengthof(const T(&)[N])
{
	return N;
}
