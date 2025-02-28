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

#include <algorithm>
#include <string>
#include <cwctype>

#ifndef CP_UTF8
#define CP_UTF8                   65001       // UTF-8 translation
#endif

__declspec(dllimport) int __stdcall MultiByteToWideChar(uint32_t CodePage, DWORD dwFlags, const char* lpMultiByteStr, int cbMultiByte, LPWSTR lpWideCharStr, int cchWideChar);

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
inline std::string wstring_to_utf8(std::wstring_view s)
{
	if (s.empty())
		return {};

	int sizeNeeded = ::WideCharToMultiByte(CP_UTF8, 0, &s[0], (int)s.size(), nullptr, 0, nullptr, nullptr);
	std::string r;
	r.resize(sizeNeeded, 0);
	::WideCharToMultiByte(CP_UTF8, 0, s.data(), (int)s.size(), &r[0], sizeNeeded, nullptr, nullptr);
	return r;
}

inline void to_lower(std::wstring& str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::towlower);
}

inline std::wstring to_lower_copy(std::wstring_view str)
{
	std::wstring tmp(str);
	to_lower(tmp);
	return tmp;
}

// Deprecated: MakeLower uses an older naming convention. Prefer to use one of the above functions instead.
inline void MakeLower(std::wstring& str)
{
	to_lower(str);
}

inline void to_upper(std::wstring& str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::towupper);
}

inline std::wstring to_upper_copy(const std::wstring& str)
{
	std::wstring tmp = str;
	to_upper(tmp);
	return tmp;
}

// Deprecated: MakeUpper uses an older naming convention. Prefer to use one of the above functions instead.
inline void MakeUpper(std::wstring& str)
{
	to_upper(str);
}

// trim from start (in place)
inline void ltrim(std::wstring& s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(),
		[](int ch) { return !std::isspace(ch); }));
}

// trim from end (in place)
inline void rtrim(std::wstring& s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(),
		[](int ch) { return !std::isspace(ch); }).base(), s.end());
}

// trim from both ends (in place)
inline void trim(std::wstring& s)
{
	ltrim(s);
	rtrim(s);
}

// trim from start (copying)
inline std::wstring ltrim_copy(std::wstring s)
{
	ltrim(s);
	return s;
}

// trim from end (copying)
inline std::wstring rtrim_copy(std::wstring s)
{
	rtrim(s);
	return s;
}

// trim from both ends (copying)
inline std::wstring trim_copy(std::wstring s)
{
	trim(s);
	return s;
}

[[nodiscard]]
inline std::wstring_view ltrim(std::wstring_view s)
{
	s.remove_prefix(std::min(s.find_first_not_of(L" \t\r\n"), s.size()));
	return s;
}

[[nodiscard]]
inline std::wstring_view rtrim(std::wstring_view s)
{
	s.remove_suffix(std::min(s.size() - s.find_last_not_of(L" \t\r\n") - 1, s.size()));
	return s;
}

[[nodiscard]]
inline std::wstring_view trim(std::wstring_view s)
{
	return rtrim(ltrim(s));
}


// String helpers for WStrings

struct ci_less_w
{
	struct nocase_compare
	{
		bool operator() (wchar_t c1, wchar_t c2) const noexcept
		{
			if (c1 == c2)
				return false;
			return ::towlower(c1) < ::towlower(c2);
		}
	};

	struct nocase_equals
	{
		bool operator() (wchar_t c1, wchar_t c2) const noexcept
		{
			if (c1 == c2)
				return true;

			return ::towlower(c1) == ::towlower(c2);
		}
	};

	bool operator()(std::wstring_view s1, std::wstring_view s2) const noexcept
	{
		return std::lexicographical_compare(
			s1.begin(), s1.end(),
			s2.begin(), s2.end(),
			nocase_compare());
	}

	using is_transparent = void;
};

inline bool ci_equals(std::wstring_view sv1, std::wstring_view sv2)
{
	return sv1.size() == sv2.size()
		&& std::equal(sv1.begin(), sv1.end(), sv2.begin(), ci_less_w::nocase_equals());
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

inline int ci_find_substr(std::wstring_view haystack, std::wstring_view needle)
{
	auto iter = std::search(std::begin(haystack), std::end(haystack),
		std::begin(needle), std::end(needle), ci_less_w::nocase_equals());
	if (iter == std::end(haystack)) return -1;
	return static_cast<int>(iter - std::begin(haystack));
}

} // namespace mq
