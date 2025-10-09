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

#ifdef MQ2PLUGIN
#define FromPlugin true
#else
#define FromPlugin false
#endif

#define STRINGIFY_IMPL(x) #x
#define STRINGIFY(x) STRINGIFY_IMPL(x)

#ifndef UNUSED
#define UNUSED(x) ((void)(x))
#endif

#if _M_AMD64
#define FORCE_SYMBOL_REFERENCE(x) __pragma(comment (linker, "/export:" #x))
#else
#define FORCE_SYMBOL_REFERENCE(x) __pragma(comment (linker, "/export:_" #x))
#endif

constexpr int MAX_STRING = 2048;

template <typename T, size_t N>
constexpr size_t lengthof(const T(&)[N])
{
	return N;
}
