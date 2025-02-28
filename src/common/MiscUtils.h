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

#include <tuple>
#include <optional>

namespace mq {

template <typename... Predicates>
auto All(Predicates&&... predicates)
{
    return [predicates = std::make_tuple(std::forward<Predicates>(predicates)...)](auto... args)
    {
        return std::apply(
            [&args...](auto&&... predicates)
            {
                return (predicates(std::forward<decltype(args)>(args)...) && ...);
            }, std::move(predicates)
        );
    };
}

template <typename... Predicates>
auto Any(Predicates&&... predicates)
{
    return [predicates = std::make_tuple(std::forward<Predicates>(predicates)...)](auto... args)
    {
        return std::apply(
            [&args...](auto&&... predicates)
            {
                return (predicates(std::forward<decltype(args)>(args)...) || ...);
            }, std::move(predicates)
        );
    };
}

template <typename T, typename U>
bool test_and_set(T& target, U&& value)
{
	if (target == value)
		return false;

	target = std::forward<U>(value);
	return true;
}

} // namespace mq
