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

bool MQ2AdvLootType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pAdvancedLootWnd)
		return false;

	MQTypeMember* pMember = MQ2AdvLootType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<AdvLootTypeMembers>(pMember->ID))
	{
	case PCount:
		Dest.Int = pAdvancedLootWnd->pPLootList->Items.GetSize();
		Dest.Type = pIntType;
		return true;

	case PList:
		Dest.Type = pAdvLootItemType;
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
					AdvancedLootItem* pItem = &pAdvancedLootWnd->pPLootList->Items[listindex];
					Dest.Ptr = pItem;
					Dest.HighPart = listindex;
					return true;
				}
			}
		}
		return false;

	case SCount:
		Dest.Int = pAdvancedLootWnd->pCLootList->Items.GetSize();
		Dest.Type = pIntType;
		return true;

	case SList:
		Dest.Type = pAdvLootItemType;
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
					AdvancedLootItem* pItem = &pAdvancedLootWnd->pCLootList->Items[listindex];
					Dest.Ptr = pItem;
					Dest.HighPart = listindex;
					return true;
				}
			}
		}
		return false;

	case PWantCount:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (CListWnd* clist = (CListWnd*)pAdvancedLootWnd->GetChildItem("ADLW_PLLList"))
		{
			for (int i = 0; i < clist->ItemsArray.Count; i++)
			{
				int listindex = (int)clist->GetItemData(i);
				if (pAdvancedLootWnd->pPLootList && listindex != -1)
				{
					AdvancedLootItem& pItem = pAdvancedLootWnd->pPLootList->Items[listindex];
					if (pItem.AlwaysNeed || pItem.AlwaysGreed || pItem.Need || pItem.Greed)
					{
						Dest.DWord++;
					}
				}
			}
		}
		return true;

	case SWantCount:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (CListWnd* clist = (CListWnd*)pAdvancedLootWnd->GetChildItem("ADLW_CLLList"))
		{
			for (int i = 0; i < clist->ItemsArray.Count; i++)
			{
				int listindex = (int)clist->GetItemData(i);
				if (pAdvancedLootWnd->pCLootList && listindex != -1)
				{
					AdvancedLootItem& pItem = pAdvancedLootWnd->pCLootList->Items[listindex];
					if (pItem.AlwaysNeed || pItem.AlwaysGreed || pItem.Need || pItem.Greed)
					{
						Dest.DWord++;
					}
				}
			}
		}
		return true;

	case xLootInProgress:
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

	case Filter:
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

