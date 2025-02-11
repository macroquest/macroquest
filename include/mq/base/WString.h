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

#include <string>
#include <cwctype>
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

// String helpers for WStrings

inline bool ci_equals(std::wstring_view sv1, std::wstring_view sv2)
{
	return sv1.size() == sv2.size()
		&& std::equal(sv1.begin(), sv1.end(), sv2.begin(), ci_less::nocase_equals_w());
}


inline bool string_equals(std::wstring_view sv1, std::wstring_view sv2)
{
	return sv1.size() == sv2.size()
		&& std::equal(sv1.begin(), sv1.end(), sv2.begin());
}

inline bool starts_with(std::wstring_view a, std::wstring_view b)
{
	if (a.length() < b.length())
		return false;

	return a.substr(0, b.length()).compare(b) == 0;
}

inline bool ci_starts_with(std::wstring_view a, std::wstring_view b)
{
	if (a.length() < b.length())
		return false;

	return ci_equals(a.substr(0, b.length()), b);
}

inline bool ends_with(std::wstring_view a, std::wstring_view b)
{
	if (a.length() < b.length())
		return false;

	return a.substr(a.length() - b.length()).compare(b) == 0;
}

inline bool ci_ends_with(std::wstring_view a, std::wstring_view b)
{
	if (a.length() < b.length())
		return false;

	return ci_equals(a.substr(a.length() - b.length()), b);
}

inline int ci_char_compare(wchar_t a, wchar_t b)
{
	return std::towlower(static_cast<unsigned char>(a)) - std::tolower(static_cast<unsigned char>(b));
}

inline int ci_string_compare(std::wstring_view s1, std::wstring_view s2)
{
	size_t size = std::min(s1.size(), s2.size());

	for (size_t i = 0; i < size; ++i)
	{
		if (int result = ci_char_compare(s1[i], s2[i]); result != 0)
			return result < 0 ? -1 : 1;
	}

	if (s1.size() < s2.size())
		return -1;
	if (s1.size() > s2.size())
		return 1;
	return 0;
}

} // namespace mq
