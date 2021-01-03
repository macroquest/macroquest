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

namespace mq::datatypes {

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

bool MQ2AdvLootItemType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pAdvancedLootWnd)
		return false;
	if (VarPtr.HighPart != CList && VarPtr.HighPart != PList)
		return false;

	AdvancedLootItemList* itemList = nullptr;
	if (VarPtr.HighPart == CList)
		itemList = pAdvancedLootWnd->pCLootList;
	else if (VarPtr.HighPart == PList)
		itemList = pAdvancedLootWnd->pPLootList;
	if (itemList == nullptr)
		return false;

	int lootIndex = VarPtr.DWord;
	if (lootIndex >= itemList->Items.GetSize())
		return false;
	const AdvancedLootItem& item = itemList->Items[lootIndex];

	MQTypeMember* pMember = MQ2AdvLootItemType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<AdvLootItemMembers>(pMember->ID))
	{
	case AdvLootItemMembers::Index:
		Dest.DWord = lootIndex;
		Dest.Type = pIntType;
		return true;

	case AdvLootItemMembers::Name:
		Dest.Type = pStringType;
		if (item.Name[0])
		{
			strcpy_s(DataTypeTemp, item.Name);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case AdvLootItemMembers::ID:
		Dest.Int64 = item.ItemID;
		Dest.Type = pInt64Type;
		return true;

	case AdvLootItemMembers::StackSize:
		Dest.DWord = 1;
		Dest.Type = pIntType;

		if (!item.LootDetails.IsEmpty() && item.LootDetails[0].StackCount >= 1)
		{
			Dest.DWord = item.LootDetails[0].StackCount;
		}
		return true;

	case AdvLootItemMembers::Corpse:
		Dest.Type = pSpawnType;
		if (!item.LootDetails.IsEmpty())
		{
			if (SPAWNINFO* pSpawn = (SPAWNINFO*)GetSpawnByID(item.LootDetails[0].CorpseID))
			{
				Dest.Ptr = pSpawn;
				return true;
			}
		}
		return false;

	case AdvLootItemMembers::AutoRoll:
		Dest.Set(item.AutoRoll);
		Dest.Type = pBoolType;
		return true;

	case AdvLootItemMembers::Need:
		Dest.Set(item.Need);
		Dest.Type = pBoolType;
		return true;

	case AdvLootItemMembers::Greed:
		Dest.Set(item.Greed);
		Dest.Type = pBoolType;
		return true;

	case AdvLootItemMembers::No:
		Dest.Set(item.No);
		Dest.Type = pBoolType;
		return true;

	case AdvLootItemMembers::AlwaysNeed:
		Dest.Set(item.AlwaysNeed);
		Dest.Type = pBoolType;
		return true;

	case AdvLootItemMembers::AlwaysGreed:
		Dest.Set(item.AlwaysGreed);
		Dest.Type = pBoolType;
		return true;

	case AdvLootItemMembers::Never:
		Dest.Set(item.Never);
		Dest.Type = pBoolType;
		return true;

	case AdvLootItemMembers::IconID:
		Dest.DWord = item.IconID;
		Dest.Type = pIntType;
		return true;

	case AdvLootItemMembers::NoDrop:
		Dest.Set(item.NoDrop);
		Dest.Type = pBoolType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2AdvLootItemType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (VarPtr.HighPart != CList && VarPtr.HighPart != PList)
		return false;

	AdvancedLootItemList* itemList = nullptr;
	if (VarPtr.HighPart == CList)
		itemList = pAdvancedLootWnd->pCLootList;
	else if (VarPtr.HighPart == PList)
		itemList = pAdvancedLootWnd->pPLootList;
	if (itemList == nullptr)
		return false;

	int lootIndex = VarPtr.DWord;
	if (lootIndex >= itemList->Items.GetSize())
		return false;

	const AdvancedLootItem& item = itemList->Items[lootIndex];
	strcpy_s(Destination, 64, item.Name);
	return true;
}

bool MQ2AdvLootItemType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	if (Source.Type != pAdvLootItemType)
		return false;

	VarPtr.DWord = Source.DWord;
	VarPtr.HighPart = Source.HighPart;
	return true;
}

} // namespace mq::datatypes
