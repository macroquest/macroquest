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

#include <algorithm>
#include <charconv>
#include <string>
#include <string_view>
#include <sstream>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

namespace mq {

inline void to_lower(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

inline std::string to_lower_copy(const std::string& str)
{
	std::string tmp = str;
	to_lower(tmp);
	return tmp;
}

// Deprecated: MakeLower uses an older naming convention. Prefer to use one of the above functions instead.
inline void MakeLower(std::string& str)
{
	to_lower(str);
}

inline void to_upper(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

inline std::string to_upper_copy(const std::string& str)
{
	std::string tmp = str;
	to_upper(tmp);
	return tmp;
}

// Deprecated: MakeUpper uses an older naming convention. Prefer to use one of the above functions instead.
inline void MakeUpper(std::string& str)
{
	to_upper(str);
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

[[nodiscard]]
inline std::string_view ltrim(std::string_view s)
{
	s.remove_prefix(std::min(s.find_first_not_of(" \t\n"), s.size()));
	return s;
}

[[nodiscard]]
inline std::string_view rtrim(std::string_view s)
{
	s.remove_suffix(std::min(s.size() - s.find_last_not_of(" \t\n") - 1, s.size()));
	return s;
}

[[nodiscard]]
inline std::string_view trim(std::string_view s)
{
	return rtrim(ltrim(s));
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

inline std::vector<std::string_view> split_view(std::string_view s, char delim, bool skipAdjacent = false)
{
	std::vector<std::string_view> elems;

	size_t start_idx = 0;

	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] == delim)
		{
			std::string_view sv{ s.data() + start_idx, i - start_idx };
			if (!sv.empty() || !skipAdjacent)
			{
				elems.push_back(sv);
			}
			start_idx = i + 1;
		}
		else if (i == s.size() - 1)
		{
			// get the last element, which needs to include the ith character since it's not a delimiter
			std::string_view sv{ s.data() + start_idx, s.size() - start_idx };
			if (!sv.empty() || !skipAdjacent)
			{
				elems.emplace_back(sv);
			}
		}
	}

	return elems;
}

/**
 * @fn strip_quotes
 *
 * @brief Strips the quotes from a string_view if it is quoted
 *
 * @warning This function is only valid as long as line remains in scope.
 * Be sure to use the result of this function before line goes out of scope
 * or create a copy as necessary.
 *
 * @param line  The line to be stripped
 * @param quote Which quote character to search for
 *
 * @return string_view The string_view or substring after stripped quotes
*/
inline std::string_view strip_quotes(std::string_view line, const char quote)
{
	if (line[0] == quote && line.back() == quote)
	{
		return line.substr(1, line.length() - 2);
	}
	return line;
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
	if (line.empty())
		return args;

	auto b = std::begin(line); // "beginning" iterator
	auto d = b; // progress this iterator as we consume words
	std::string_view::size_type s = 0; // this will be the distance to the found character
	char quote = '\0';
	char lastquote = '\0';

	// fast-forward past any whitespace
	for (; s < line.length() && (*(b + s) == ' ' || *(b + s) == '\t'); ++s);
	if (s >= line.length())
		return args;

	d += s;

	while (s < line.length())
	{
		auto c = b + s;
		if ((*c == ' ' || *c == '\t') && quote == '\0' && (c == std::begin(line) || *(c - 1) != '\\'))
		{
			// hit a boundary, let's put it in the vector
			args.emplace_back(strip_quotes(std::string_view(&d[0], std::distance(d, c)), lastquote));

			lastquote = '\0';
			for (; s < line.length() && (*(b + s) == ' ' || *(b + s) == '\t'); ++s);
			d = b + s;
		}
		else if (((*c == '"' || *c == '\'') && (quote == *c || quote == '\0') && (c == std::begin(line) || *(c - 1) != '\\')))
		{
			if (quote == '\0')
			{
				quote = *c;
				lastquote = *c;
			}
			else
				quote = '\0';
			++s;
		}
		else if (*c == '{' && c != std::begin(line) && *(c - 1) == '$')
		{
			// This is MQ2 specific handling, we want to allow passing of ${} arguments without needing quotes
			int b_count = 1;
			bool b_quote = false;
			++s;
			for (; b_count > 0 && s < line.length(); ++s)
			{
				if (b_quote)
				{
					if (*(b + s) == '"' && s + 1 < line.length() && (*(b + s + 1) == ']' || *(b + s + 1) == ','))
						b_quote = false;
				}
				else if (*(b + s) == '}')
					--b_count;
				else if (*(b + s) == '{')
					++b_count;
				else if (s + 1 < line.length() && *(b + s + 1) == '"' && (*(b + s) == '[' || *(b + s) == ','))
					b_quote = true;
			}
		}
		else
			++s;
	}

	// hit the end of the string, assume this finishes off any current token
	// we explicitly only want to tokenize if we have an argument
	if (std::distance(d, std::end(line)) > 0)
		args.emplace_back(strip_quotes(std::string_view(&d[0], std::distance(d, std::end(line))), lastquote));

	return args;
}

inline std::vector<std::string> allocate_args(std::string_view line) {
	auto args = tokenize_args(line);
	return std::vector<std::string>(args.begin(), args.end());
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

inline std::string replace(std::string_view str, std::string_view search, std::string_view replacement)
{
	std::string s(str);

	std::string::size_type p = 0;
	while ((p = s.find(search, p)) != std::string::npos)
	{
		s.replace(p, search.length(), replacement);
		p += replacement.length();
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
	augmented_replace.emplace_back(std::make_pair(std::string({ escape, str[0] }), std::string({ str[0] })));
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

	struct nocase_equals_w
	{
		bool operator() (const wchar_t& c1, const wchar_t& c2) const noexcept
		{
			if (c1 == c2)
				return true;

			return ::towlower(c1) == ::towlower(c2);
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

inline int find_substr(std::string_view haystack, std::string_view needle)
{
	auto iter = std::search(std::begin(haystack), std::end(haystack),
		std::begin(needle), std::end(needle));
	if (iter == std::end(haystack)) return -1;
	return static_cast<int>(iter - std::begin(haystack));
}

inline int ci_find_substr(std::string_view haystack, std::string_view needle)
{
	auto iter = std::search(std::begin(haystack), std::end(haystack),
		std::begin(needle), std::end(needle), ci_less::nocase_equals());
	if (iter == std::end(haystack)) return -1;
	return static_cast<int>(iter - std::begin(haystack));
}

inline int ci_find_substr_w(std::wstring_view haystack, std::wstring_view needle)
{
	auto iter = std::search(std::begin(haystack), std::end(haystack),
		std::begin(needle), std::end(needle), ci_less::nocase_equals_w());
	if (iter == std::end(haystack)) return -1;
	return static_cast<int>(iter - std::begin(haystack));
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

inline bool ci_equals(std::wstring_view sv1, std::wstring_view sv2)
{
	return sv1.size() == sv2.size()
		&& std::equal(sv1.begin(), sv1.end(), sv2.begin(), ci_less::nocase_equals_w());
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

inline bool starts_with(std::string_view a, std::string_view b)
{
	if (a.length() < b.length())
		return false;

	return a.substr(0, b.length()).compare(b) == 0;
}

inline bool ci_starts_with(std::string_view a, std::string_view b)
{
	if (a.length() < b.length())
		return false;

	return ci_equals(a.substr(0, b.length()), b);
}

inline bool ends_with(std::string_view a, std::string_view b)
{
	if (a.length() < b.length())
		return false;

	return a.substr(a.length() - b.length()).compare(b) == 0;
}

inline bool ci_ends_with(std::string_view a, std::string_view b)
{
	if (a.length() < b.length())
		return false;

	return ci_equals(a.substr(a.length() - b.length()), b);
}

struct ci_unordered
{
private:
	struct ci_comparer
	{
		using is_transparent = void;

		template <typename T>
		bool operator()(const T& a, const T& b) const
		{
			return ci_equals(a, b);
		}
	};

	struct ci_hasher
	{
		using is_transparent = void;

		template <typename T>
		size_t operator()(const T& a) const
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
	template <typename StringType, typename T>
	using map = std::unordered_map<StringType, T, ci_hasher, ci_comparer>;

	template <typename StringType, typename T>
	using multimap = std::unordered_multimap<StringType, T, ci_hasher, ci_comparer>;

	template <typename StringType>
	using set = std::unordered_set<StringType, ci_hasher, ci_comparer>;

	template <typename StringType>
	using multiset = std::unordered_multiset<StringType, ci_hasher, ci_comparer>;
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
	auto trimmed = trim(svString);
	auto result = std::from_chars(trimmed.data(), trimmed.data() + trimmed.size(), iReturnOnFail);
	// Could error check here, but failures don't modify the value and we're not returning meaningful errors.
	return iReturnOnFail;
}

/**
 * @fn GetInt64FromString
 *
 * @brief Gets the int64 value from a well formatted string
 *
 * Takes the input of a string and a value that should be returned if conversion fails.
 * Attempts to convert the string to a int64 and returns the converted value on success
 * or the failure value on fail.
 *
 * Suitable replacement for atol (removing the undefined behavior) and faster than strtol.
 *
 * @see GetIntFromString
 * @see GetDoubleFromString
 * @see GetFloatFromString
 *
 * @param svString The string to convert to an int64
 * @param iReturnOnFail The int64 that should be returned if conversion fails
 *
 * @return int64_t The converted int64 or the "failure" value
 **/
inline int64_t GetInt64FromString(const std::string_view svString, int64_t lReturnOnFail)
{
	auto trimmed = trim(svString);
	auto result = std::from_chars(trimmed.data(), trimmed.data() + trimmed.size(), lReturnOnFail);
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
	auto trimmed = trim(svString);
	auto result = std::from_chars(trimmed.data(), trimmed.data() + trimmed.size(), fReturnOnFail);
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
	auto trimmed = trim(svString);
	auto result = std::from_chars(trimmed.data(), trimmed.data() + trimmed.size(), dReturnOnFail);
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
inline bool GetBoolFromString(const std::string_view svString, const bool defaultValue)
{
	bool returnValue = defaultValue;
	const auto trimmed = trim(svString);

	if (ci_equals(trimmed, "true"))
	{
		returnValue = true;
	}
	else if (ci_equals(trimmed, "false"))
	{
		returnValue = false;
	}
	else if (ci_equals(trimmed, "on"))
	{
		returnValue = true;
	}
	else if (ci_equals(trimmed, "off"))
	{
		returnValue = false;
	}
	else if (ci_equals(trimmed, "yes"))
	{
		returnValue = true;
	}
	else if (ci_equals(trimmed, "no"))
	{
		returnValue = false;
	}
	else
	{
		returnValue = static_cast<bool>(GetIntFromString(trimmed, static_cast<int>(defaultValue)));
	}

	return returnValue;
}

} // namespace mq
