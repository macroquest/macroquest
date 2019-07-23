/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
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

#include "Common.h"
#include "CXStr.h"

namespace eqlib {

enum ItemContainerInstance
{
	eItemContainerInvalid                        = -1,
	eItemContainerPossessions                    = 0,
	eItemContainerBank                           = 1,
	eItemContainerSharedBank                     = 2,
	eItemContainerTrade                          = 3,
	eItemContainerWorld                          = 4,
	eItemContainerLimbo                          = 5,
	eItemContainerTribute                        = 6,
	eItemContainerTrophyTribute                  = 7,
	eItemContainerGuildTribute                   = 8,
	eItemContainerMerchant                       = 9,
	eItemContainerDeleted                        = 10,
	eItemContainerCorpse                         = 11,
	eItemContainerBazaar                         = 12,
	eItemContainerInspect                        = 13,
	eItemContainerRealEstate                     = 14,
	eItemContainerViewModPC                      = 15,
	eItemContainerViewModBank                    = 16,
	eItemContainerViewModSharedBank              = 17,
	eItemContainerViewModLimbo                   = 18,
	eItemContainerAltStorage                     = 19,
	eItemContainerArchived                       = 20,
	eItemContainerMail                           = 21,
	eItemContainerGuildTrophyTribute             = 22,
	eItemContainerKrono                          = 23,
	eItemContainerOther                          = 24,
	eItemContainerMercenaryItems                 = 25,
    eItemContainerViewModMercenaryItems          = 26,
    eItemContainerMountKeyRingItems              = 27,
	eItemContainerViewModMountKeyRingItems       = 28,
	eItemContainerIllusionKeyRingItems           = 29,
	eItemContainerViewModIllusionKeyRingItems    = 30,
	eItemContainerFamiliarKeyRingItems           = 31,
	eItemContainerViewModFamiliarKeyRingItems    = 32,
	eItemContainerCursor                         = 33,

	eNumItemContainers                           = 34,
};

class ItemIndex
{
	enum { MAX_INVENTORY_DEPTH = 3 };

public:
	short m_slots[MAX_INVENTORY_DEPTH];

	EQLIB_OBJECT ItemIndex()
	{
		memset(m_slots, -1, sizeof(m_slots));
	}

	EQLIB_OBJECT explicit ItemIndex(short slot1, short slot2 = -1, short slot3 = -1)
	{
		m_slots[0] = slot1;
		m_slots[1] = slot2;
		m_slots[2] = slot3;
	}

	EQLIB_OBJECT bool operator==(const ItemIndex& other) const
	{
		return m_slots[0] == other.m_slots[0]
			&& m_slots[1] == other.m_slots[1]
			&& m_slots[2] == other.m_slots[2];
	}

	EQLIB_OBJECT short GetTopSlot() const { return m_slots[0]; }

	EQLIB_OBJECT void SetSlot(int depth, short value)
	{
		if (depth < MAX_INVENTORY_DEPTH)
			m_slots[depth] = value;
	}

	EQLIB_OBJECT short GetSlot(int depth) const
	{
		if (depth < MAX_INVENTORY_DEPTH)
			return m_slots[depth];

		return -1;
	} 

	EQLIB_OBJECT bool IsValid() const { return m_slots[0] != -1; }
	EQLIB_OBJECT bool IsBase() const { return m_slots[0] != -1 && m_slots[1] == -1; }
	EQLIB_OBJECT bool IsInContainer() const { return m_slots[0] != -1 && m_slots[1] != -1; }

	// Remote one depth to get index representing whatever the parent is.
	EQLIB_OBJECT ItemIndex GetParentIndex() const
	{
		ItemIndex copy = *this;

		for (int i = MAX_INVENTORY_DEPTH - 1; i >= 0; --i)
		{
			if (copy.m_slots[i] != -1)
			{
				copy.m_slots[i] = -1;
				return copy;
			}
		}

		return copy;
	}

	// alias for existing bad code
	__declspec(property(get = getSlot1)) int Slot1;
	__declspec(property(get = getSlot2)) int Slot2;
	__declspec(property(get = getSlot3)) int Slot3;
	
private:
	EQLIB_OBJECT int getSlot1() { return m_slots[0]; }
	EQLIB_OBJECT int getSlot2() { return m_slots[1]; }
	EQLIB_OBJECT int getSlot3() { return m_slots[2]; }
};

class ItemGlobalIndex
{
public:
	ItemContainerInstance Location = eItemContainerInvalid;
	ItemIndex Index;

	EQLIB_OBJECT ItemGlobalIndex() = default;
	EQLIB_OBJECT ItemGlobalIndex(const ItemGlobalIndex& other)
		: Location(other.Location)
		, Index(other.Index)
	{}

	EQLIB_OBJECT bool operator==(const ItemGlobalIndex& other)
	{
		return Location == other.Location && Index == other.Index;
	}

	EQLIB_OBJECT void SetLocation(ItemContainerInstance location) { Location = location; }
	EQLIB_OBJECT ItemContainerInstance GetLocation() const { return Location; }

	EQLIB_OBJECT void SetIndex(const ItemIndex& index) { Index = index; }
	EQLIB_OBJECT ItemIndex& GetIndex() { return Index; }
	EQLIB_OBJECT const ItemIndex& GetIndex() const { return Index; }

	EQLIB_OBJECT ItemGlobalIndex GetParent() const
	{
		ItemGlobalIndex copy = *this;

		copy.Index = copy.Index.GetParentIndex();
		return copy;
	}

	EQLIB_OBJECT bool IsKeyRingLocation() const
	{
		return Location == eItemContainerMountKeyRingItems
			|| Location == eItemContainerIllusionKeyRingItems
			|| Location == eItemContainerFamiliarKeyRingItems;
	}
	
	EQLIB_OBJECT bool IsEquippedLocation() const
	{
		return Location == eItemContainerPossessions
			&& Index.IsBase()
			&& Index.GetTopSlot() <= 22;
	}

	EQLIB_OBJECT bool IsValidIndex() const
	{
		return IsValidLocation() && Index.IsValid();
	}

	EQLIB_OBJECT bool IsValidLocation() const
	{
		return Location >= 0 && Location < eNumItemContainers;
	}
};

} // namespace eqlib

using namespace eqlib;