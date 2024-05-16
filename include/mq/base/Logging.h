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

#include <fmt/format.h>
#include <chrono>
#include <string_view>
#include <ctime>

namespace mq {

/**
 * CreateLogFilename
 *
 * @brief Create a filename that is suitable for use as a log file. A
 * timestamp will be appended, and it will have a .log extension.
 *
 * @param baseName The base name for the log file.
 * @param timestamp Timestamp to use in the filename.
 * 
 * @return The created filename
 */
inline std::string CreateLogFilename(std::string_view baseName,
	std::chrono::system_clock::time_point timestamp = std::chrono::system_clock::now())
{
	auto now_as_time_t = std::chrono::system_clock::to_time_t(timestamp);

	// Convert time_point to broken-down local time.
	std::tm local_tm;
	localtime_s(&local_tm, &now_as_time_t);

	// Calculate microseconds
	auto since_epoch = timestamp.time_since_epoch();
	auto seconds = std::chrono::duration_cast<std::chrono::seconds>(since_epoch);
	auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(since_epoch - seconds);

	fmt::memory_buffer buffer;
	fmt::format_to(fmt::appender(buffer),
		"{}-{:04d}{:02d}{:02d}T{:02d}{:02d}{:02d}.{:06}.log", baseName,
		local_tm.tm_year + 1900, local_tm.tm_mon + 1, local_tm.tm_mday,
		local_tm.tm_hour, local_tm.tm_min, local_tm.tm_sec, microseconds.count());

	return fmt::to_string(buffer);
}



} // namespace mq
