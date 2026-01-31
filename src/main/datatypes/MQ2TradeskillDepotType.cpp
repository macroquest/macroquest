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

#include <mq/api/Items.h>

namespace mq::datatypes {

enum class TradeskillDepotTypeMembers
{
	Count = 1,
	Capacity,
	Enabled,
	ItemsReceived,
	FindItem,
	FindItemCount,
	SelectedItem,
};

enum class TradeskillDepotTypeMethods
{
	SelectItem,
	WithdrawItem,
	WithdrawStack,
	DepositItem
};

#if HAS_TRADESKILL_DEPOT
static void SelectItemByName(std::string_view name)
{
#if HAS_HASHMAP_TRADESKILL_DEPOT
	for (const auto& [_, pItem] : pTradeskillDepotWnd->Items)
#else
	for (const ItemPtr& pItem : pTradeskillDepotWnd->Items)
#endif
	{
		if (MaybeExactCompare(pItem->GetName(), name))
		{
			CListWnd* pList = pTradeskillDepotWnd->pItemList;

			for (int i = 0; i < pList->GetItemCount(); ++i)
			{
				if (mq::string_equals(pList->ItemsArray[i].Cells[1].Text, pItem->GetName()))
				{
					pList->SetCurSel(i);
					pList->ParentWndNotification(pList, XWM_LCLICK, (void*)static_cast<intptr_t>(i));

					pTradeskillDepotWnd->pSelectedItem = pItem;
					pTradeskillDepotWnd->SelectedItemID = pItem->GetID();
					break;
				}
			}

			break;
		}
	}
}
#endif

MQ2TradeskillDepotType::MQ2TradeskillDepotType() : MQ2Type("tradeskilldepot")
{
	ScopedTypeMember(TradeskillDepotTypeMembers, Count);
	ScopedTypeMember(TradeskillDepotTypeMembers, Capacity);
	ScopedTypeMember(TradeskillDepotTypeMembers, Enabled);
	ScopedTypeMember(TradeskillDepotTypeMembers, ItemsReceived);
	ScopedTypeMember(TradeskillDepotTypeMembers, FindItem);
	ScopedTypeMember(TradeskillDepotTypeMembers, FindItemCount);
	ScopedTypeMember(TradeskillDepotTypeMembers, SelectedItem);

	ScopedTypeMethod(TradeskillDepotTypeMethods, SelectItem);
	ScopedTypeMethod(TradeskillDepotTypeMethods, WithdrawItem);
	ScopedTypeMethod(TradeskillDepotTypeMethods, WithdrawStack);
	ScopedTypeMethod(TradeskillDepotTypeMethods, DepositItem);
}

bool MQ2TradeskillDepotType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pLocalPC)
		return false;

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<TradeskillDepotTypeMethods>(pMethod->ID))
		{
		case TradeskillDepotTypeMethods::SelectItem:
		{
#if HAS_TRADESKILL_DEPOT
			if (pTradeskillDepotWnd->IsVisible() && Index[0])
			{
				SelectItemByName(Index);
			}
#endif
			return true;
		}

		case TradeskillDepotTypeMethods::WithdrawItem:
		case TradeskillDepotTypeMethods::WithdrawStack:
		{
#if HAS_TRADESKILL_DEPOT
			if (pTradeskillDepotWnd->IsVisible() && pActiveBanker)
			{
				// Withdraw by name
				if (Index[0])
				{
					SelectItemByName(Index);
				}

				bool stack = (static_cast<TradeskillDepotTypeMethods>(pMethod->ID) == TradeskillDepotTypeMethods::WithdrawStack);

				if (pTradeskillDepotWnd->pSelectedItem)
				{
					CXPoint pt = pTradeskillDepotWnd->pWithdrawButton->GetClientRect().CenterPoint();

					decltype(pWndMgr->KeyboardFlags) savedFlags;
					if (stack)
					{
						memcpy(&savedFlags, pWndMgr->KeyboardFlags, sizeof(savedFlags));
						memset(pWndMgr->KeyboardFlags, 0, sizeof(savedFlags));

						pWndMgr->KeyboardFlags[0] = true;
					}

					pTradeskillDepotWnd->pWithdrawButton->HandleLButtonDown(pt, 0);
					pTradeskillDepotWnd->pWithdrawButton->HandleLButtonUp(pt, 0);

					if (stack)
					{
						memcpy(pWndMgr->KeyboardFlags, &savedFlags, sizeof(savedFlags));
					}
				}
			}
#endif
			return true;
		}

		case TradeskillDepotTypeMethods::DepositItem:
		{
#if HAS_TRADESKILL_DEPOT
			if (pTradeskillDepotWnd->IsVisible() && pActiveBanker)
			{
				if (pCursorAttachment && pCursorAttachment->Type == eCursorAttachment_Item)
				{
					CXPoint pt = pTradeskillDepotWnd->pItemList->GetClientRect().CenterPoint();

					MoveMouse(pt.x, pt.y);
					ClickMouseButton(0);
				}
			}
#endif
			return true;
		}

		default: break;
		}
	}

	//----------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<TradeskillDepotTypeMembers>(pMember->ID))
	{
	case TradeskillDepotTypeMembers::Count:
		Dest.Type = pIntType;
#if HAS_TRADESKILL_DEPOT
		Dest.Int =  pTradeskillDepotWnd ? pTradeskillDepotWnd->Items.GetCount() : 0;
#else
		Dest.Int = 0;
#endif
		return true;

	case TradeskillDepotTypeMembers::Capacity:
		Dest.Type = pIntType;
		Dest.Int = pLocalPC->GetTradeskillDepotCapacity();
		return true;

	case TradeskillDepotTypeMembers::Enabled:
		Dest.Type = pBoolType;
		Dest.Set(pLocalPC->ConsumableFeatures.CanConsumeFeature(EQFeature_TradeskillDepot));
		return true;

	case TradeskillDepotTypeMembers::ItemsReceived:
		Dest.Type = pBoolType;
		Dest.Set(pLocalPC->GetTradeskillDepotPopulated());
		return true;

	case TradeskillDepotTypeMembers::FindItem: {
#if HAS_HASHMAP_TRADESKILL_DEPOT
		if (!pTradeskillDepotWnd || !Index[0])
			return false;

		const auto& items = pTradeskillDepotWnd->Items;

		// Find by ID
		if (IsNumber(Index))
		{
			int findID = GetIntFromString(Index, 0);
			auto foundItem = items.Find(findID);
			if (foundItem == nullptr || !*foundItem)
				return false;

			Dest = pItemType->MakeTypeVar(*foundItem);
			return true;
		}

		// Find by Name
		for (const auto& [_, item] : items)
		{
			if (MaybeExactCompare(item->GetName(), Index))
			{
				Dest = pItemType->MakeTypeVar(item);
				return true;
			}
		}

		return false;
#elif HAS_TRADESKILL_DEPOT
		ItemContainer* pItemContainer = GetItemContainerByType(eItemContainerTradeskillDepot);
		if (!pItemContainer || !Index[0])
			return false;

		// Find by ID
		if (IsNumber(Index))
		{
			int findID = GetIntFromString(Index, 0);
			ItemPtr foundItem;
			pItemContainer->FindItem(
				[findID, &foundItem](const ItemPtr& itemPtr, const ItemIndex&)
				{
					if (itemPtr->GetID() == findID)
					{
						foundItem = itemPtr;
						return true;
					}
			return false;
				});

			Dest = pItemType->MakeTypeVar(foundItem);
			return true;
		}

		// Find by Name
		ItemPtr foundItem;
		pItemContainer->FindItem(
			[Index, &foundItem](const ItemPtr& itemPtr, const ItemIndex&)
			{
				if (mq::MaybeExactCompare(itemPtr->GetName(), Index))
				{
					foundItem = itemPtr;
					return true;
				}
				return false;
			});

		Dest = pItemType->MakeTypeVar(foundItem);
		return true;
#endif
	}

	case TradeskillDepotTypeMembers::FindItemCount: {
#if HAS_HASHMAP_TRADESKILL_DEPOT
		if (!pTradeskillDepotWnd || !Index[0])
			return false;

		const auto& items = pTradeskillDepotWnd->Items;

		Dest.Type = pIntType;
		Dest.Int = 0;

		// Find by ID
		if (IsNumber(Index))
		{
			int ItemID = GetIntFromString(Index, 0);
			auto foundItem = items.Find(ItemID);
			if (foundItem == nullptr || !*foundItem)
				return false;

			Dest.Int = (*foundItem)->GetItemCount();
			return true;
		}

		for (const auto& [_, item] : items)
		{
			if (MaybeExactCompare(item->GetName(), Index))
			{
				Dest.Int = item->GetItemCount();
				return true;
			}
		}

		return false;
#elif HAS_TRADESKILL_DEPOT
		ItemContainer* pItemContainer = GetItemContainerByType(eItemContainerTradeskillDepot);
		if (!pItemContainer || !Index[0])
			return false;

		Dest.Type = pIntType;
		Dest.Int = 0;

		// Find by ID
		if (IsNumber(Index))
		{
			int ItemID = GetIntFromString(Index, 0);
			Dest.Int = CountContainerItems(*pItemContainer, -1, -1,
				[ItemID](const ItemPtr& pItem) { return pItem->GetID() == ItemID; });
			return true;
		}

		// Find by Name
		Dest.Int = CountContainerItems(*pItemContainer, -1, -1,
			[Index](const ItemPtr& pItem) { return MaybeExactCompare(pItem->GetName(), Index); });
		return true;
#endif
	}

	case TradeskillDepotTypeMembers::SelectedItem: {
		ItemPtr pItem;
#if HAS_TRADESKILL_DEPOT
		if (pTradeskillDepotWnd)
		{
			pItem = pTradeskillDepotWnd->pSelectedItem;
		}
#endif
		Dest = pItemType->MakeTypeVar(pItem);
		return true;
	}

	default: break;
	}

	return false;
}

bool MQ2TradeskillDepotType::dataTradeskillDepot(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Type = pTradeskillDepotType;
	return true;
}

} // namespace mq::datatypes
