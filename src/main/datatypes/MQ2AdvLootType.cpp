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
#include "MQ2DataTypes.h"

namespace mq::datatypes {

enum class ListType
{
	CList = 1,
	PList = 2,
};

enum class AdvLootTypeMembers
{
	PList = 1,
	PCount,
	SList,
	SCount,
	PWantCount,
	SWantCount,
	LootInProgress,
	Filter
};

MQ2AdvLootType::MQ2AdvLootType() : MQ2Type("advloot")
{
	ScopedTypeMember(AdvLootTypeMembers, PList);
	ScopedTypeMember(AdvLootTypeMembers, PCount);
	ScopedTypeMember(AdvLootTypeMembers, SList);
	ScopedTypeMember(AdvLootTypeMembers, SCount);
	ScopedTypeMember(AdvLootTypeMembers, PWantCount);
	ScopedTypeMember(AdvLootTypeMembers, SWantCount);
	ScopedTypeMember(AdvLootTypeMembers, LootInProgress);
	ScopedTypeMember(AdvLootTypeMembers, Filter);
}

bool MQ2AdvLootType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pAdvancedLootWnd)
		return false;

	MQTypeMember* pMember = MQ2AdvLootType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<AdvLootTypeMembers>(pMember->ID))
	{
	case AdvLootTypeMembers::PCount:
		Dest.Int = pAdvancedLootWnd->pPLootList->Items.GetSize();
		Dest.Type = pIntType;
		return true;

	case AdvLootTypeMembers::PList:
		if (int index = GetIntFromString(Index, 0))
		{
			index--;
			if (index < 0)
				index = 0;
			if (CListWnd* clist = (CListWnd*)pAdvancedLootWnd->GetChildItem("ADLW_PLLList"))
			{
				int listindex = (int)clist->GetItemData(index);
				if (pAdvancedLootWnd->pPLootList && listindex != -1)
				{
					Dest.Type = pAdvLootItemType;
					Dest.DWord = listindex;
					Dest.HighPart = static_cast<int>(ListType::PList);
					return true;
				}
			}
		}
		return false;

	case AdvLootTypeMembers::SCount:
		Dest.Int = pAdvancedLootWnd->pCLootList->Items.GetSize();
		Dest.Type = pIntType;
		return true;

	case AdvLootTypeMembers::SList:
		if (int index = GetIntFromString(Index, 0))
		{
			index--;
			if (index < 0)
				index = 0;

			if (CListWnd* clist = (CListWnd*)pAdvancedLootWnd->GetChildItem("ADLW_CLLList"))
			{
				int listindex = (int)clist->GetItemData(index);
				if (pAdvancedLootWnd->pCLootList && listindex != -1)
				{
					Dest.Type = pAdvLootItemType;
					Dest.DWord = listindex;
					Dest.HighPart = static_cast<int>(ListType::CList);
					return true;
				}
			}
		}
		return false;

	case AdvLootTypeMembers::PWantCount:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (CListWnd* clist = (CListWnd*)pAdvancedLootWnd->GetChildItem("ADLW_PLLList"))
		{
			// Access items in the order they appear in the list.
			for (int i = 0; i < clist->ItemsArray.Count; i++)
			{
				int listindex = (int)clist->GetItemData(i);
				if (pAdvancedLootWnd->pPLootList && listindex != -1)
				{
					const AdvancedLootItem& item = pAdvancedLootWnd->pPLootList->Items[listindex];
					if (item.AlwaysNeed || item.AlwaysGreed || item.Need || item.Greed)
					{
						Dest.DWord++;
					}
				}
			}
		}
		return true;

	case AdvLootTypeMembers::SWantCount:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (CListWnd* clist = (CListWnd*)pAdvancedLootWnd->GetChildItem("ADLW_CLLList"))
		{
			for (int i = 0; i < clist->ItemsArray.Count; i++)
			{
				int listindex = (int)clist->GetItemData(i);
				if (pAdvancedLootWnd->pCLootList && listindex != -1)
				{
					const AdvancedLootItem& item = pAdvancedLootWnd->pCLootList->Items[listindex];
					if (item.AlwaysNeed || item.AlwaysGreed || item.Need || item.Greed)
					{
						Dest.DWord++;
					}
				}
			}
		}
		return true;

	case AdvLootTypeMembers::LootInProgress:
		Dest.Set(false);
		Dest.Type = pBoolType;

		if (CListWnd* pPersonalList = (CListWnd*)pAdvancedLootWnd->GetChildItem("ADLW_PLLList"))
		{
			if (pAdvancedLootWnd->pCLootList)
			{
				CListWnd* pSharedList = (CListWnd*)pAdvancedLootWnd->pCLootList->SharedLootList;
				Dest.Set(LootInProgress(pAdvancedLootWnd, pPersonalList, pSharedList));
			}
		}
		return true;

	case AdvLootTypeMembers::Filter:
		Dest.Type = pItemFilterDataType;
		if (pLootFiltersManager)
		{
			if (int id = GetIntFromString(Index, 0))
			{
				if (const ItemFilterData* pifd = pLootFiltersManager->GetItemFilterData(id))
				{
					Dest.Ptr = (ItemFilterData*)pifd; // but its const ....
					return true;
				}
			}
		}
		return false;

	default: break;
	}

	return false;
}

bool MQ2AdvLootType::dataAdvLoot(const char* szIndex, MQTypeVar& Ret)
{
	Ret.DWord = 0;
	Ret.Type = pAdvLootType;
	return true;
}

//============================================================================

enum class AdvLootItemMembers
{
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
	NoDrop,
	FreeGrab,
	Status,
};

MQ2AdvLootItemType::MQ2AdvLootItemType() : MQ2Type("advlootitem")
{
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
	ScopedTypeMember(AdvLootItemMembers, FreeGrab);
	ScopedTypeMember(AdvLootItemMembers, Status);
}

bool MQ2AdvLootItemType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pAdvancedLootWnd)
		return false;
	if (VarPtr.HighPart != static_cast<int>(ListType::CList)
		&& VarPtr.HighPart != static_cast<int>(ListType::PList))
		return false;

	AdvancedLootItemList* itemList = nullptr;
	ListType listType = static_cast<ListType>(VarPtr.HighPart);
	if (listType == ListType::CList)
		itemList = pAdvancedLootWnd->pCLootList;
	else if (listType == ListType::PList)
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
		Dest = pSpawnType->MakeTypeVar(item.LootDetails.IsEmpty() ? nullptr : GetSpawnByID(item.LootDetails[0].CorpseID));
		return true;

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

	case AdvLootItemMembers::FreeGrab:
		Dest.DWord = item.FG;
		Dest.Type = pBoolType;
		return true;

	case AdvLootItemMembers::Status:
		if (listType == ListType::PList)
			return false;

		Dest.Type = pStringType;
		switch (item.Status)
		{
		case eAdvLootStatusWaiting:
			strcpy_s(DataTypeTemp, "WAITING");
			break;
		case eAdvLootStatusAsking:
			strcpy_s(DataTypeTemp, "ASKING");
			break;
		case eAdvLootStatusRolling:
			strcpy_s(DataTypeTemp, "ROLLING");
			break;
		case eAdvLootStatusStopped:
			strcpy_s(DataTypeTemp, "STOPPED");
			break;
		case eAdvLootStatusClickRoll:
			strcpy_s(DataTypeTemp, "CLICKROLL");
			break;
		case eAdvLootStatusFreeGrab:
			strcpy_s(DataTypeTemp, "FREEGRAB");
			break;
		default:
			sprintf_s(DataTypeTemp, "UNKNOWN(%d)", item.Status);
			break;
		}
		Dest.Ptr = &DataTypeTemp[0];
		return true;


	default: break;
	}

	return false;
}

bool MQ2AdvLootItemType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (VarPtr.HighPart != static_cast<int>(ListType::CList)
		&& VarPtr.HighPart != static_cast<int>(ListType::PList))
		return false;

	AdvancedLootItemList* itemList = nullptr;
	if (VarPtr.HighPart == static_cast<int>(ListType::CList))
		itemList = pAdvancedLootWnd->pCLootList;
	else if (VarPtr.HighPart == static_cast<int>(ListType::PList))
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

bool MQ2AdvLootItemType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pAdvLootItemType)
		return false;

	VarPtr.DWord = Source.DWord;
	VarPtr.HighPart = Source.HighPart;
	return true;
}

} // namespace mq::datatypes
