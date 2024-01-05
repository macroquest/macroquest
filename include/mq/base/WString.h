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

#include <string>
#include <Windows.h>

namespace mq {

// convert UTF-8 string to wstring
inline std::wstring utf8_to_wstring(std::string_view s)
{
	if (s.empty()) return {};

	int slength = (int)s.length();
	int len = ::MultiByteToWideChar(CP_UTF8, 0, s.data(), slength, nullptr, 0);
	std::wstring r;
	r.resize(len);
	::MultiByteToWideChar(CP_UTF8, 0, s.data(), slength, r.data(), len);
	return r;
}

// convert UTF16 wstring to string
inline std::string wstring_to_utf8(const std::wstring& s)
{
	if (s.empty())
		return {};

	int sizeNeeded = ::WideCharToMultiByte(CP_UTF8, 0, &s[0], (int)s.size(), nullptr, 0, nullptr, nullptr);
	std::string r;
	r.resize(sizeNeeded, 0);
	::WideCharToMultiByte(CP_UTF8, 0, s.c_str(), (int)s.size(), &r[0], sizeNeeded, nullptr, nullptr);
	return r;
}

} // namespace mq