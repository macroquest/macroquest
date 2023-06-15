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

// The functions that are here, and not in mq/base/String.h depend on third
// party libraries.

#include <mq/base/String.h>

#include <fmt/format.h>
#include <glm/glm.hpp>

namespace mq {

template<typename T>
inline std::string join(const std::vector<T>& vec, std::string_view delim)
{
	return fmt::format("{}", fmt::join(vec, delim));
}

/**
 * @brief Converts a string to a glm::vec3.
 *
 * Takes a string of comma or space-separated floats and converts it to a glm::vec3.
 * If the input string is invalid, the function returns the glm::vec from ReturnOnFail.
 *
 * If any individual conversion is invalid, it returns the coordinate specified in that position of ReturnOnFail.
 *
 * @param s The input string to be converted. The string should contain up to three floats separated by either spaces or commas.
 * @param ReturnOnFail The value to return if the conversion fails (defaults to glm::vec3(0.0f, 0.0f, 0.0f)).
 *
 * @return The glm::vec3 representation of the input string. If the conversion fails, returns ReturnOnFail.
 */inline glm::vec3 GetVec3FromString(std::string_view s, glm::vec3 ReturnOnFail = {0.0f, 0.0f, 0.0f})
{
	glm::vec3 result = ReturnOnFail;
	s = trim(s);

	size_t start_pos = 0;
	int coord_count = 0;

	auto extract_coordinate = [&](size_t end) {
		const std::string_view coordinate = trim(s.substr(start_pos, end - start_pos));
		if (coordinate.empty())
			return false;
		result[coord_count] = GetFloatFromString(coordinate, ReturnOnFail[coord_count]);
		++coord_count;
		return true;
	};

	char delim = ',';
	size_t end_pos = s.find(delim);

	if (end_pos == std::string::npos)
	{
		delim = ' ';
		end_pos = s.find(delim);
	}

	while (end_pos != std::string_view::npos && coord_count < 3)
	{
		if (!extract_coordinate(end_pos))
			return ReturnOnFail;

		start_pos = s.find_first_not_of(' ', end_pos + 1);
		end_pos = s.find(delim, start_pos);
	}

	// Pick up the last coordinate
	if (start_pos != std::string_view::npos && coord_count < 3)
	{
		if (!extract_coordinate(s.length()))
			return ReturnOnFail;
	}

	return result;
}

} // namespace mq