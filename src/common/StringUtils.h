/*
 * MacroQuest2: The extension platform for EverQuest
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

#include <cstdint>
#include <algorithm>
#include <charconv>
#include <string>
#include <string_view>
#include <sstream>
#include <vector>
#include <numeric>

constexpr int MAX_STRING = 2048;

template <typename T, size_t N>
constexpr size_t lengthof(const T(&)[N])
{
	return N;
}

namespace mq {

inline void MakeLower(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

// trim from start (in place)
inline void ltrim(std::string& s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(),
		[](int ch) { return !std::isspace(ch); }));
}

// trim from end (in place)
inline void rtrim(std::string& s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(),
		[](int ch) { return !std::isspace(ch); }).base(), s.end());
}

// trim from both ends (in place)
inline void trim(std::string& s)
{
	ltrim(s);
	rtrim(s);
}

// trim from start (copying)
inline std::string ltrim_copy(std::string s)
{
	ltrim(s);
	return s;
}

// trim from end (copying)
inline std::string rtrim_copy(std::string s)
{
	rtrim(s);
	return s;
}

// trim from both ends (copying)
inline std::string trim_copy(std::string s)
{
	trim(s);
	return s;
}


inline std::vector<std::string> split(const std::string& s, char delim)
{
	std::stringstream ss(s);
	std::string item;
	std::vector<std::string> elems;

	while (std::getline(ss, item, delim))
	{
		elems.push_back(std::move(item));
	}

	return elems;
}

inline std::string join(const std::vector<std::string>& vec, const std::string& delim)
{
	return std::accumulate(
		std::next(vec.cbegin()), vec.cend(), vec.front(),
		[&delim](std::string& a, const std::string& b) {
			return a + delim + b;
		});
}

struct ci_less
{
	struct nocase_compare
	{
		bool operator() (const unsigned char& c1, const unsigned char& c2) const noexcept
		{
			if (c1 == c2)
				return false;
			return ::tolower(c1) < ::tolower(c2);
		}
	};

	struct nocase_equals
	{
		bool operator() (const unsigned char& c1, const unsigned char& c2) const noexcept
		{
			if (c1 == c2)
				return true;

			return ::tolower(c1) == ::tolower(c2);
		}
	};

	bool operator()(std::string_view s1, std::string_view s2) const noexcept
	{
		return std::lexicographical_compare(
			s1.begin(), s1.end(),
			s2.begin(), s2.end(),
			nocase_compare());
	}

	using is_transparent = void;
};

inline int ci_find_substr(std::string_view haystack, std::string_view needle)
{
	auto iter = std::search(std::begin(haystack), std::end(haystack),
		std::begin(needle), std::end(needle), ci_less::nocase_equals());
	if (iter == std::end(haystack)) return -1;
	return iter - std::begin(haystack);
}

// todo implement a better ci_starts_with that doesn't search past needle.length chars
inline bool ci_starts_with(std::string_view haystack, std::string_view needle)
{
	return ci_find_substr(haystack, needle) == 0;
}

/**
 * @fn ci_equals
 *
 * @brief Case Insensitive Compare for two strings
 *
 * Determines if two strings are the same without regard to case.
 *
 * First makes sure the strings are the same size, then sends each character
 * through the equal function passing them to the @ref nocase_compare function.
 *
 * @param sv1 The first string to Compare
 * @param sv2 The second string to Compare
 *
 * @return bool The result of the comparison
 *
 **/
inline bool ci_equals(std::string_view sv1, std::string_view sv2)
{
	return sv1.size() == sv2.size()
		&& std::equal(sv1.begin(), sv1.end(), sv2.begin(), ci_less::nocase_equals());
}

inline bool ci_equals(std::string_view haystack, std::string_view needle, bool isExact)
{
	if (isExact)
		return ci_equals(haystack, needle);

	return ci_find_substr(haystack, needle) != -1;
}

inline bool string_equals(std::string_view sv1, std::string_view sv2)
{
	return sv1.size() == sv2.size()
		&& std::equal(sv1.begin(), sv1.end(), sv2.begin());
}

/**
 * @fn GetIntFromString
 *
 * @brief Gets the int value from a well formatted string
 *
 * Takes the input of a string and a value that should be returned if conversion fails.
 * Attempts to convert the string to an int and returns the converted value on success
 * or the failure value on fail.
 *
 * Suitable replacement for atoi (removing the undefined behavior) and faster than strtol.
 *
 * @see GetDoubleFromString
 * @see GetFloatFromString
 *
 * @param svString The string to convert to an integer
 * @param iReturnOnFail The integer that should be returned if conversion fails
 *
 * @return int The converted integer or the "failure" value
 **/
inline int GetIntFromString(const std::string_view svString, int iReturnOnFail)
{
	auto result = std::from_chars(svString.data(), svString.data() + svString.size(), iReturnOnFail);
	// Could error check here, but failures don't modify the value and we're not returning meaningful errors.
	return iReturnOnFail;
}

/**
 * @fn GetFloatFromString
 *
 * @brief Gets the float value from a well formatted string
 *
 * Takes the input of a string and a value that should be returned if conversion fails.
 * Attempts to convert the string to a float and returns the converted value on success
 * or the failure value on fail.
 *
 * Suitable replacement for atof (removing the undefined behavior) with a cast.
 *
 * @see GetDoubleFromString
 * @see GetIntFromString
 *
 * @param svString The string to convert to a float
 * @param fReturnOnFail The float that should be returned if conversion fails
 *
 * @return float The converted float or the "failure" value
 **/
inline float GetFloatFromString(const std::string_view svString, float fReturnOnFail)
{
	auto result = std::from_chars(svString.data(), svString.data() + svString.size(), fReturnOnFail);
	// Could error check here, but failures don't modify the value and we're not returning meaningful errors.
	return fReturnOnFail;
}

/**
 * @fn GetDoubleFromString
 *
 * @brief Gets the double value from a well formatted string
 *
 * Takes the input of a string and a value that should be returned if conversion fails.
 * Attempts to convert the string to a double and returns the converted value on success
 * or the failure value on fail.
 *
 * Suitable replacement for atof (removing the undefined behavior) and strtod.
 *
 * @see GetFloatFromString
 * @see GetIntFromString
 *
 * @param svString The string to convert to a double
 * @param dReturnOnFail The double that should be returned if conversion fails
 *
 * @return float The converted double or the "failure" value
 **/
inline double GetDoubleFromString(const std::string_view svString, double dReturnOnFail)
{
	auto result = std::from_chars(svString.data(), svString.data() + svString.size(), dReturnOnFail);
	// Could error check here, but failures don't modify the value and we're not returning meaningful errors.
	return dReturnOnFail;
}

/**
 * @fn GetBoolFromString
 *
 * @brief Gets the bool value from a well formatted string
 *
 * Takes the input of a string and a value that should be returned if conversion fails.
 * Attempts to convert the string to a bool and returns the converted value on success
 * or the failure value on fail.
 *
 * @see GetIntFromString
 * @see CaseInsCompare
 *
 * @param svString The string to convert to an integer
 * @param bReturnOnFail The bool that should be returned if conversion fails
 *
 * @return int The converted integer or the "failure" value
 **/
inline bool GetBoolFromString(const std::string_view svString, bool bReturnOnFail)
{
	if (ci_equals(svString, "True"))
	{
		bReturnOnFail = true;
	}
	else if (ci_equals(svString, "False"))
	{
		bReturnOnFail = false;
	}
	else
	{
		bReturnOnFail = static_cast<bool>(GetIntFromString(svString, static_cast<int>(bReturnOnFail)));
	}
	return bReturnOnFail;
}

} // namespace mq