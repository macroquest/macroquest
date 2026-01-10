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

#include "fmt/format.h"

#include <string_view>

namespace mq {

namespace detail {
	
	struct uppercase_view
	{
		std::string_view str;

		constexpr uppercase_view(std::string_view s) : str(s) {}
	};

} // namespace detail

constexpr detail::uppercase_view fmt_uppercase(std::string_view s)
{
	return detail::uppercase_view(s);
}

} // namespace mq

namespace fmt {

	template <>
	struct fmt::formatter<mq::detail::uppercase_view>
	{
		template <typename ParseContext>
		constexpr auto parse(ParseContext& ctx) { return ctx.begin(); }

		template <typename FormatContext>
		auto format(const mq::detail::uppercase_view& uppercase, FormatContext& ctx) const
		{
			auto out = ctx.out();

			for (char c : uppercase.str)
			{
				*out++ = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
			}

			return out;
		}
	};

} // namespace fmt