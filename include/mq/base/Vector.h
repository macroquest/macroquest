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

#include <vector>

namespace mq {

template <typename t> void move_element(std::vector<t>& v, size_t oldIndex, size_t newIndex)
{
	if (oldIndex > newIndex)
		std::rotate(v.rend() - oldIndex - 1, v.rend() - oldIndex, v.rend() - newIndex);
	else
		std::rotate(v.begin() + oldIndex, v.begin() + oldIndex + 1, v.begin() + newIndex + 1);
}

template <typename T, typename U>
auto insert_sorted(std::vector<T>& vec, const U& item)
{
	return vec.insert(
		std::upper_bound(begin(vec), end(vec), item),
		item
	);
}

template <typename T, typename U>
bool sorted_contains(const std::vector<T>& vec, const U& v)
{
	auto it = std::lower_bound(
		begin(vec),
		end(vec),
		v,
		[](const T& l, const U& r) { return l < r; });
	return it != end(vec) && *it == v;
}

template <typename T, typename U>
auto insert_unique_sorted(std::vector<T>& vec, const U& item)
{
	auto it = std::lower_bound(begin(vec), end(vec), item);

	if (it == end(vec) || *it != item) {
		return vec.insert(it, item);
	}

	return it;
}

template <typename T, typename U>
bool remove_sorted(std::vector<T>& vec, const U& item)
{
	auto it = std::lower_bound(begin(vec), end(vec), item);

	if (it != end(vec) && *it == item) {
		vec.erase(it);
		return true;
	}

	return false;
}


} // namespace mq
