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

enum class AdvLootTypeMembers
{
	PList,
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
					Dest.HighPart = MQ2AdvLootItemType::PList;
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
					Dest.HighPart = MQ2AdvLootItemType::CList;
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
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (CListWnd* pPersonalList = (CListWnd*)pAdvancedLootWnd->GetChildItem("ADLW_PLLList"))
		{
			if (pAdvancedLootWnd->pCLootList)
			{
				CListWnd* pSharedList = (CListWnd*)pAdvancedLootWnd->pCLootList->SharedLootList;
				Dest.DWord = LootInProgress(pAdvancedLootWnd, pPersonalList, pSharedList);
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

} // namespace mq::datatypes
