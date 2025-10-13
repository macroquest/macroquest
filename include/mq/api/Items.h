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

#include "eqlib/game/Items.h"

namespace mq {

template <typename T>
static int CountContainerItems(ItemContainer& container, int fromSlot, int toSlot, T& checkItem)
{
	int count = 0;
	auto predicatedCountVisitor = [&](const ItemPtr& pItem, const ItemIndex& index)
	{
		if (checkItem(pItem))
			count += pItem->GetItemCount();
	};

	container.VisitItems(fromSlot, toSlot, -1, predicatedCountVisitor);
	return count;
}

/**
 * Convert a string representation of item size to its corresponding integer value.
 *
 * This function maps size descriptors to their integer representations.
 * If the input string doesn't match any known descriptors, it returns -1.
 *
 * @param String A std::string_view representing the descriptor of the item's size.
 *               Expected values are: "tiny", "small", "medium", "large", "giant".
 *
 * @return Integer value representing the item's size. Returns -1 for unrecognized descriptors.
 */
inline int GetItemSizeFromDesc(std::string_view String)
{
	if (ci_equals(String, "tiny"))
		return ItemSize_Tiny;

	if (ci_equals(String, "small"))
		return ItemSize_Small;

	if (ci_equals(String, "medium"))
		return ItemSize_Medium;

	if (ci_equals(String, "large"))
		return ItemSize_Large;

	if (ci_equals(String, "giant"))
		return ItemSize_Giant;

	return -1;
}

} // namespace mq
