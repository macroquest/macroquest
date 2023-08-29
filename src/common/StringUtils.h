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

namespace mq {

template<typename T>
inline std::string join(const std::vector<T>& vec, std::string_view delim)
{
	return fmt::format("{}", fmt::join(vec, delim));
}

} // namespace mq