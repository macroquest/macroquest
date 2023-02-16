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

#include <mq/base/Common.h>

#include <random>
#include <filesystem>

namespace mq {

inline std::string GetRandomString(const int stringLength)
{
	static const char availableChars[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	std::string returnString;
	returnString.reserve(stringLength);

	std::uniform_int_distribution<uint32_t> dist(0, static_cast<uint8_t>((lengthof(availableChars) - 2)));

	static std::default_random_engine s_randomEngine(std::random_device{}());

	for (int i = 0; i < stringLength; ++i)
	{
		returnString += availableChars[dist(s_randomEngine)];
	}

	return returnString;
}

inline std::filesystem::path GetUniqueFileName(const std::filesystem::path& basePath, const std::string& extension)
{
	std::string fullExtension = ".";
	if (!extension.empty())
	{
		if (extension[0] != '.')
		{
			fullExtension += extension;
		}
		else
		{
			fullExtension = extension;
		}
	}

	std::filesystem::path returnPath = basePath;
	std::error_code ec;
	do
	{
		returnPath = basePath / (GetRandomString(8) + fullExtension);
	} while (exists(returnPath, ec));

	return returnPath;
}

inline bool file_equals(const std::filesystem::path fileOne, const std::filesystem::path fileTwo)
{
	std::error_code ec;
	return (file_size(fileOne, ec) == file_size(fileTwo, ec) && last_write_time(fileOne, ec) == last_write_time(fileTwo, ec));
}

} // namespace mq
