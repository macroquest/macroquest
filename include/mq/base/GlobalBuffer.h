/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
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

#include <cstddef>
#include <cstring>
#include <stack>

// This allows us to swap out the underlying buffer for DataTypeTemp
struct SGlobalBuffer
{
	static constexpr size_t bufferSize = 2048;
	char buffer[bufferSize] = { 0 };

	SGlobalBuffer();
	~SGlobalBuffer();

	template <typename Index>
	char& operator[](Index index) { return ptr[static_cast<size_t>(index)]; }

	template <typename Index>
	char operator[](Index index) const { return ptr[static_cast<size_t>(index)]; }

	template <typename Index>
	char* operator& (Index index) const { return &ptr[static_cast<size_t>(index)]; }

	operator char* () const { return ptr; }

	operator std::string_view() const { return { ptr }; }

	[[nodiscard]] constexpr size_t size() const { return bufferSize; }
	[[nodiscard]] char* begin() const { return ptr; }
	[[nodiscard]] char* end() const { return ptr + strlen(ptr); }

	MQLIB_OBJECT void push_buffer(char* new_buffer);
	MQLIB_OBJECT void pop_buffer();

private:
	char* ptr = nullptr;
	std::stack<char*> m_stack;
};

// Provide helpers to go with SGlobalBuffer to allow for these operations without specifying a size

inline errno_t strcpy_s(SGlobalBuffer& dest, const char* src)
{
	return strcpy_s(dest, dest.size(), src);
}

inline errno_t strncpy_s(SGlobalBuffer& dest, const char* src, size_t count)
{
	return strncpy_s(dest, dest.size(), src, count);
}

inline void strcat_s(SGlobalBuffer& dest, const char* src)
{
	strcat_s(dest, dest.size(), src);
}

inline void _strupr_s(SGlobalBuffer& dest)
{
	_strupr_s(dest, dest.size());
}

inline void _strlwr_s(SGlobalBuffer& dest)
{
	_strlwr_s(dest, dest.size());
}

template <typename... Args>
int sprintf_s(SGlobalBuffer& dest, const char* format, Args... args)
{
	return sprintf_s(dest, dest.size(), format, args...);
}

// end helpers
