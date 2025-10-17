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

#include "pch.h"

// TODO: Move other inventory related functions here and remove MQ2Main.h include
#include "MQ2Main.h"
#include "mq/api/Inventory.h"

#include "eqlib/game/Items.h"

namespace mq {

/**
 * Get the number of bank slots based on the given size and whether it is empty (free).
 * @param nSize Minimum size capacity of a container item to be considered.
 * @param bEmptyOnly If true, count only empty (free) slots. Defaults to false if no parameter is passed.
 * @return Number of slots that meet the criteria.
 */
int GetBankSlotCount(int nSize, bool bEmptyOnly /* = false */)
{
	if (!eqlib::pLocalPC || !eqlib::pLocalPlayer)
		return 0;

	int numSlots = 0;
	const int availableSlots = GetAvailableBankSlots();

	// Bind the size to a valid range.
	nSize = std::clamp(nSize, static_cast<int>(ItemSize_Tiny), static_cast<int>(ItemSize_Giant));

	for (int slot = 0; slot < availableSlots; ++slot)
	{
		if (const eqlib::ItemPtr pItem = pLocalPC->BankItems.GetItem(slot))
		{
			if (pItem->IsContainer()
				&& (nSize == 0 || pItem->GetItemDefinition()->SizeCapacity >= nSize))
			{
				// Add the container size
				numSlots += pItem->GetHeldItems().GetSize();
				// If only empty slots are considered, deduct the occupied slots.
				if (bEmptyOnly)
				{
					numSlots -= static_cast<int>(pItem->GetHeldItems().GetCount());
				}
			}
			// Not a container, so only count it if we're not looking for empty slots.
			else if (!bEmptyOnly)
			{
				numSlots++;
			}
		}
		// No item in slot, increment
		else
		{
			numSlots++;
		}
	}

	return numSlots;
}

} // namespace mq