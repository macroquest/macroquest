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

#include "eqlib/Items.h"

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

} // namespace mq
