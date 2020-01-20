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

#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2AdvLootItemType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	AdvancedLootItem* pItem = (AdvancedLootItem*)VarPtr.Ptr;
	if (!pItem)
		return false;

	MQTypeMember* pMember = MQ2AdvLootItemType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<AdvLootItemMembers>(pMember->ID))
	{
	case Address:
		Dest.DWord = (DWORD)pItem;
		Dest.Type = pIntType;
		return true;

	case xIndex:
		Dest.DWord = VarPtr.HighPart;
		Dest.Type = pIntType;
		return true;

	case Name:
		Dest.Type = pStringType;
		if (pItem && pItem->Name[0])
		{
			strcpy_s(DataTypeTemp, pItem->Name);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case ID:
		Dest.Int64 = pItem->ItemID;
		Dest.Type = pInt64Type;
		return true;

	case StackSize:
		Dest.DWord = 1;
		Dest.Type = pIntType;

		if (pItem && pItem->LootDetails.GetSize() && pItem->LootDetails[0].StackCount >= 1)
		{
			Dest.DWord = pItem->LootDetails[0].StackCount;
		}
		return true;

	case Corpse:
		Dest.Type = pSpawnType;
		if (pItem && pItem->LootDetails.GetSize())
		{
			if (SPAWNINFO* pSpawn = (SPAWNINFO*)GetSpawnByID(pItem->LootDetails[0].CorpseID))
			{
				Dest.Ptr = pSpawn;
				return true;
			}
		}
		return false;

	case AutoRoll:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pItem)
		{
			Dest.DWord = pItem->AutoRoll;
		}
		return true;

	case Need:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pItem)
		{
			Dest.DWord = pItem->Need;
		}
		return true;

	case Greed:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pItem)
		{
			Dest.DWord = pItem->Greed;
		}
		return true;

	case No:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pItem)
		{
			Dest.DWord = pItem->No;
		}
		return true;

	case AlwaysNeed:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pItem)
		{
			Dest.DWord = pItem->AlwaysNeed;
		}
		return true;

	case AlwaysGreed:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem)
		{
			Dest.DWord = pItem->AlwaysGreed;
		}
		return true;

	case Never:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pItem)
		{
			Dest.DWord = pItem->Never;
		}
		return true;

	case IconID:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pItem)
		{
			Dest.DWord = pItem->IconID;
			return true;
		}
		return false;

	case xNoDrop:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pItem)
		{
			Dest.DWord = pItem->NoDrop;
		}
		return true;

	default: break;
	}
	return false;
}

