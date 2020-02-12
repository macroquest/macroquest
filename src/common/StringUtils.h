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
#include <unordered_map>
#include <unordered_set>

#include <fmt/format.h>

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

template<typename T>
inline std::string join(const std::vector<T>& vec, std::string_view delim)
{
	return fmt::format("{}", fmt::join(vec, delim));
}

// returns a vector of arguments as string_views. This has the advantage
// of not allocating any strings, but the result of this function will
// only be valid inside the lifetime of the original line passed as an
// argument to this function. Be sure to allocate any values as strings
// that you care about _before_ the original line goes out of scope 
// (or is otherwise destroyed)!
inline std::vector<std::string_view> tokenize_args(std::string_view line)
{
	std::vector<std::string_view> args;
	auto b = std::begin(line); // "beginning" iterator
	auto d = b; // progress this iterator as we consume words
	std::string_view::size_type s = 0; // this will be the distance to the found character
    char quote = '\0';

    // fast-forward past any whitespace
    for (; *(b + s) == ' ' || *(b + s) == '\t'; ++s);
	if (s == std::string_view::npos)
		return args;

	d += s;

    while (s < line.length())
	{
		auto c = b + s;
		if ((*c == ' ' || *c == '\t') && quote == '\0' && *(c - 1) != '\\')
		{
			// hit a boundary, let's put it in the vector
			args.emplace_back(std::string_view(&d[0], std::distance(d, c)));
            for (; *(b + s) == ' ' || *(b + s) == '\t'; ++s);
			d = b + s;
		}
		else if (((*c == '"' || *c == '\'') && (quote == *c || quote == '\0') && *(c - 1) != '\\'))
		{
            if (quote == '\0')
                quote = *c;
            else
                quote = '\0';
            ++s;
		}
        else if (*c == '{' && *(c - 1) == '$')
        {
            // This is MQ2 specific handling, we want to allow passing of ${} arguments without needing quotes
            int b_count = 1;
            bool b_quote = false;
            ++s;
            for (; b_count > 0 && s < line.length(); ++s)
            {
                if (b_quote)
                {
                    if (*(b + s) == '"' && s + 1 < line.length() &&
                        (*(b + s + 1) == ']' || *(b + s + 1) == ','))
                        b_quote = false;
                }
                else if (*(b + s) == '}')
                    --b_count;
                else if (*(b + s) == '{')
                    ++b_count;
                else if (s + 1 < line.length() && *(b + s + 1) == '"' &&
                    (*(b + s) == '[' || *(b + s) == ','))
                    b_quote = true;
            }
        }
		else
			++s;
	}

	// hit the end of the string, assume this finishes off any current token
	// we explicitly only want to tokenize if we have an argument
	if (std::distance(d, std::end(line)) > 0)
		args.emplace_back(std::string_view(&d[0], std::distance(d, std::end(line))));

	return args;
}

// allocates a string from a string_view, replaces all occurrences of each
// entry in `to_replace` and returns this string
inline std::string replace(std::string_view str, std::vector<std::pair<std::string_view, std::string_view>> to_replace)
{
	std::string s(str);
	for (auto r : to_replace)
	{
		std::string::size_type p = 0;
		while ((p = s.find(r.first, p)) != std::string::npos)
		{
			s.replace(p, r.first.length(), r.second);
			p += r.second.length();
		}
	}

	return s;
}

// helper function that calls replace with the normal command line argument
// escape sequences
inline std::string unescape_args(std::string_view str) {
	return replace(str, { {R"(\\)", R"(\)"}, {R"(\")", R"(")"}, {R"(\')", R"(')"} });
}

template<char escape = '\\'>
inline std::string unescape(std::string_view str, std::string_view quotes)
{
    if (str.empty())
        return std::string();

    static std::vector<std::pair<std::string_view, std::string_view>> to_replace = {
        {std::string({escape, escape}), std::string({escape})},
        {std::string({escape, ' '}), std::string({' '})}
    };

    if (str.back() != str.front() || str.find_first_of(quotes) != 0)
        return replace(str, to_replace);

    auto augmented_replace = to_replace;
    augmented_replace.emplace_back(std::make_pair(std::string({escape, str[0]}), std::string({str[0]})));
    return replace(std::string_view(&str[1], str.length() - 2), augmented_replace);
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

struct ci_unordered
{
private:
	struct ci_comparer
	{
		bool operator () (std::string_view a, std::string_view b) const
		{
			return ci_equals(a, b);
		}
	};

	struct ci_hasher
	{
		unsigned long operator () (std::string_view a) const
		{
			// this is a re-implementation of the fnv1a hash that MSVC uses, but with tolower
			unsigned long hash = 2166136261U;
			for (unsigned char c : a)
			{
				hash ^= static_cast<unsigned long>(::tolower(c));
				hash *= 16777619U;
			}
			return hash;
		}
	};

public:
	template <typename T>
	using map = std::unordered_map<std::string_view, T, ci_hasher, ci_comparer>;

	template <typename T>
	using multimap = std::unordered_multimap<std::string_view, T, ci_hasher, ci_comparer>;

	using set = std::unordered_set<std::string_view, ci_hasher, ci_comparer>;

	using multiset = std::unordered_multiset<std::string_view, ci_hasher, ci_comparer>;
};

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
 * @see GetInt64FromString
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
 * @fn GetInt64FromString
 *
 * @brief Gets the long value from a well formatted string
 *
 * Takes the input of a string and a value that should be returned if conversion fails.
 * Attempts to convert the string to a long and returns the converted value on success
 * or the failure value on fail.
 *
 * Suitable replacement for atol (removing the undefined behavior) and faster than strtol.
 *
 * @see GetIntFromString
 * @see GetDoubleFromString
 * @see GetFloatFromString
 *
 * @param svString The string to convert to a long
 * @param iReturnOnFail The long that should be returned if conversion fails
 *
 * @return long The converted long or the "failure" value
 **/
inline int64_t GetInt64FromString(const std::string_view svString, int64_t lReturnOnFail)
{
	auto result = std::from_chars(svString.data(), svString.data() + svString.size(), lReturnOnFail);
	// Could error check here, but failures don't modify the value and we're not returning meaningful errors.
	return lReturnOnFail;
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
 * @see GetInt64FromString
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
 * @see GetInt64FromString
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
 * @see ci_equals
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