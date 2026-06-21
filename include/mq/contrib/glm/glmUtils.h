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

#include <glm/glm.hpp>
#include "mq/base/Math.h"
#include "mq/base/String.h"

namespace mq {

/**
 * @brief Calculates and returns the 3D Euclidean distance between two glm::vec3 points in a 3D space.
 *
 * @note If you don't need the actual distance, but only need to compare distances, you should
 * use GetDistanceSquared instead.
 *
 * @param first The first glm::vec3 point.
 * @param second The second glm::vec3 point.
 * @return float The 3D Euclidean distance between the two glm::vec3 points.
 */
inline float GetDistance(const glm::vec3& first, const glm::vec3& second)
{
	return GetDistance(first.x, first.y, first.z, second.x, second.y, second.z);
}

/**
 * @brief [3D] Calculates and returns the squared Euclidean distance between two glm::vec3 points in a 3D space.
 *
 * @note This function is often used when comparing distances, as squaring is cheaper than taking the square root.
 * If you actually need the distance, use the GetDistance function instead.
 *
 * @param first The glm::vec3 coordinate of the first point.
 * @param second The glm::vec3 coordinate of the second point.
 * @return float The squared Euclidean distance between the two points.
 */
inline float GetDistanceSquared(const glm::vec3& first, const glm::vec3& second)
{
	return GetDistanceSquared(first.x, first.y, first.z, second.x, second.y, second.z);
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
 */
inline glm::vec3 GetVec3FromString(std::string_view s, glm::vec3 ReturnOnFail = {0.0f, 0.0f, 0.0f})
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

/**
 * @brief Parses a string to extract two glm::vec3 coordinates into an array.
 *
 * The string is expected to contain one or two glm::vec3 represented as strings, each set separated by a colon.
 * Each vector string should contain up to three float values separated by commas or spaces.
 *
 * @param s The input string to parse.
 * @param first_ReturnOnFail The glm::vec3 to return as the first element of the array if the first vector string in `s` cannot be parsed.
 * @param second_ReturnOnFail The glm::vec3 to return as the second element of the array if the second vector string in `s` cannot be parsed or is not present.
 * @return std::array<glm::vec3, 2> An array containing the two parsed glm::vec3. If a vector string cannot be parsed or is not present, the corresponding return-on-fail vector is used.
 */
inline std::array<glm::vec3, 2> GetVec3SetFromString(std::string_view s, const glm::vec3& first_ReturnOnFail = {0.0f, 0.0f, 0.0f}, const glm::vec3& second_ReturnOnFail = {0.0f, 0.0f, 0.0f})
{
	std::array<glm::vec3, 2> result = { first_ReturnOnFail, second_ReturnOnFail };
	const auto args = split_view(s, ':');

	if (!args.empty())
	{
		result[0] = GetVec3FromString(args[0], first_ReturnOnFail);

		if (args.size() > 1)
		{
			result[1] = GetVec3FromString(args[1], second_ReturnOnFail);
		}
	}

	return result;
}

} // namespace mq