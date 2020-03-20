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

enum class AdvLootItemMembers
{
	Address,
	Index,
	Name,
	ID,
	StackSize,
	Corpse,
	AutoRoll,
	Need,
	Greed,
	No,
	AlwaysNeed,
	AlwaysGreed,
	Never,
	IconID,
	NoDrop
};

MQ2AdvLootItemType::MQ2AdvLootItemType() : MQ2Type("advlootitem")
{
	ScopedTypeMember(AdvLootItemMembers, Address);
	ScopedTypeMember(AdvLootItemMembers, Index);
	ScopedTypeMember(AdvLootItemMembers, Name);
	ScopedTypeMember(AdvLootItemMembers, ID);
	ScopedTypeMember(AdvLootItemMembers, StackSize);
	ScopedTypeMember(AdvLootItemMembers, Corpse);
	ScopedTypeMember(AdvLootItemMembers, AutoRoll);
	ScopedTypeMember(AdvLootItemMembers, Need);
	ScopedTypeMember(AdvLootItemMembers, Greed);
	ScopedTypeMember(AdvLootItemMembers, No);
	ScopedTypeMember(AdvLootItemMembers, AlwaysNeed);
	ScopedTypeMember(AdvLootItemMembers, AlwaysGreed);
	ScopedTypeMember(AdvLootItemMembers, Never);
	ScopedTypeMember(AdvLootItemMembers, IconID);
	ScopedTypeMember(AdvLootItemMembers, NoDrop);
}

bool MQ2AdvLootItemType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pAdvancedLootWnd || !pAdvancedLootWnd->pCLootList)
		return false;

	AdvancedLootItem* pItem = &pAdvancedLootWnd->pCLootList->Items[VarPtr.DWord];
	if (!pItem)
		return false;

	MQTypeMember* pMember = MQ2AdvLootItemType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<AdvLootItemMembers>(pMember->ID))
	{
	case AdvLootItemMembers::Address:
		Dest.DWord = (DWORD)pItem;
		Dest.Type = pIntType;
		return true;

	case AdvLootItemMembers::Index:
		Dest.DWord = VarPtr.DWord;
		Dest.Type = pIntType;
		return true;

	case AdvLootItemMembers::Name:
		Dest.Type = pStringType;
		if (pItem && pItem->Name[0])
		{
			strcpy_s(DataTypeTemp, pItem->Name);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case AdvLootItemMembers::ID:
		Dest.Int64 = pItem->ItemID;
		Dest.Type = pInt64Type;
		return true;

	case AdvLootItemMembers::StackSize:
		Dest.DWord = 1;
		Dest.Type = pIntType;

		if (pItem && pItem->LootDetails.GetSize() && pItem->LootDetails[0].StackCount >= 1)
		{
			Dest.DWord = pItem->LootDetails[0].StackCount;
		}
		return true;

	case AdvLootItemMembers::Corpse:
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

	case AdvLootItemMembers::AutoRoll:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pItem)
		{
			Dest.DWord = pItem->AutoRoll;
		}
		return true;

	case AdvLootItemMembers::Need:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pItem)
		{
			Dest.DWord = pItem->Need;
		}
		return true;

	case AdvLootItemMembers::Greed:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pItem)
		{
			Dest.DWord = pItem->Greed;
		}
		return true;

	case AdvLootItemMembers::No:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pItem)
		{
			Dest.DWord = pItem->No;
		}
		return true;

	case AdvLootItemMembers::AlwaysNeed:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pItem)
		{
			Dest.DWord = pItem->AlwaysNeed;
		}
		return true;

	case AdvLootItemMembers::AlwaysGreed:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem)
		{
			Dest.DWord = pItem->AlwaysGreed;
		}
		return true;

	case AdvLootItemMembers::Never:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pItem)
		{
			Dest.DWord = pItem->Never;
		}
		return true;

	case AdvLootItemMembers::IconID:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pItem)
		{
			Dest.DWord = pItem->IconID;
			return true;
		}
		return false;

	case AdvLootItemMembers::NoDrop:
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

bool MQ2AdvLootItemType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (AdvancedLootItem* pitem = &pAdvancedLootWnd->pCLootList->Items[VarPtr.DWord])
	{
		strcpy_s(Destination, 64, pitem->Name);
		return true;
	}

	return false;
}

bool MQ2AdvLootItemType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	if (Source.Type != pAdvLootItemType)
		return false;

	VarPtr.DWord = Source.DWord;
	return true;
}

