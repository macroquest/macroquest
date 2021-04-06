/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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

enum class MerchantMembers
{
	Markup = 1,
	Item,
	Items,
	Open,
	Full,
	ItemsReceived,
	SelectedItem,
};

enum MerchantMethods
{
	SelectItem = 1,
	Buy,
	Sell,
	OpenWindow,
	CloseWindow,
};

MQ2MerchantType::MQ2MerchantType() : MQ2Type("merchant")
{
	ScopedTypeMember(MerchantMembers, Markup);
	ScopedTypeMember(MerchantMembers, Item);
	ScopedTypeMember(MerchantMembers, Items);
	ScopedTypeMember(MerchantMembers, Open);
	ScopedTypeMember(MerchantMembers, Full);
	ScopedTypeMember(MerchantMembers, ItemsReceived);
	ScopedTypeMember(MerchantMembers, SelectedItem);

	ScopedTypeMethod(MerchantMethods, SelectItem);
	ScopedTypeMethod(MerchantMethods, Buy);
	ScopedTypeMethod(MerchantMethods, Sell);
	ScopedTypeMethod(MerchantMethods, OpenWindow);
	ScopedTypeMethod(MerchantMethods, CloseWindow);
}

bool MQ2MerchantType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pMerchantWnd)
		return false;

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2MerchantType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<MerchantMethods>(pMethod->ID))
		{
		case MerchantMethods::SelectItem: {
			if (pMerchantWnd->IsVisible())
			{
				bool bFound = false;
				int listIndex = 0;
				ItemPtr pItem;

				auto& itemContainer = pMerchantWnd->PageHandlers[RegularMerchantPage]->ItemContainer;
				for (int i = 0; i < itemContainer.GetSize(); i++)
				{
					if (itemContainer[i].pItem)
					{
						if (MaybeExactCompare(itemContainer[i].pItem->GetName(), Index))
						{
							listIndex = i;
							pItem = itemContainer[i].pItem;
							break;
						}
					}
				}

				if (pItem)
				{
					ItemGlobalIndex To(eItemContainerMerchant, pItem->GetItemLocation().GetTopSlot());

					for (int i = 0; i < pMerchantWnd->ItemsList->ItemsArray.GetLength(); i++)
					{
						CXStr Str = pMerchantWnd->ItemsList->GetItemText(i, 1);

						if (ci_equals(Str, pItem->GetName()))
						{
							pMerchantWnd->ItemsList->SetCurSel(i);
						}
					}

					pMerchantWnd->SelectBuySellSlot(To, listIndex);
					return true;
				}
			}
			return true;
		}

		case MerchantMethods::Buy: {
			if (pMerchantWnd->IsVisible())
			{
				int Qty = GetIntFromString(Index, 0);
				if (Qty < 1)
					return false;

				if (pMerchantWnd->pSelectedItem
					&& pMerchantWnd->pSelectedItem->GetItemLocation().GetLocation() == eItemContainerMerchant)
				{
					pMerchantWnd->PageHandlers[RegularMerchantPage]->RequestGetItem(Qty);
					return true;
				}
			}
			return true;
		}

		case MerchantMethods::Sell: {
			if (pMerchantWnd->IsVisible())
			{
				int Qty = GetIntFromString(Index, 0);
				if (Qty < 1)
					return false;

				if (pMerchantWnd->pSelectedItem
					&& pMerchantWnd->pSelectedItem->GetItemLocation().GetLocation() == eItemContainerPossessions)
				{
					pMerchantWnd->PageHandlers[RegularMerchantPage]->RequestPutItem(Qty);
					return true;
				}
			}
			return true;
		}

		case MerchantMethods::OpenWindow: {
			MQSpawnSearch SearchSpawn;
			ClearSearchSpawn(&SearchSpawn);
			SearchSpawn.FRadius = 999999.0f;
			SearchSpawn.bMerchant = true;

			if (pTarget && pTarget->GetClass() == Class_Merchant)
			{
				pEverQuest->RightClickedOnPlayer(pTarget, 0);
				return true;
			}
			else if (SPAWNINFO* pSpawn = SearchThroughSpawns(&SearchSpawn, pLocalPlayer))
			{
				pTarget = pSpawn;
				pEverQuest->RightClickedOnPlayer(pSpawn, 0);
				return true;
			}
			return true;
		}

		case MerchantMethods::CloseWindow:
			if (pMerchantWnd->IsVisible())
			{
				// Need to call deactivate here.
				WriteChatf("Not implemented yet");
				return true;
			}
			return true;

		default: break;
		}

		return false;
	}

	if (!pActiveMerchant)
		return false;

	MQTypeMember* pMember = MQ2MerchantType::FindMember(Member);
	if (!pMember)
	{
		return pSpawnType->GetMember(pActiveMerchant.get_as<SPAWNINFO>(), Member, Index, Dest);
	}

	switch (static_cast<MerchantMembers>(pMember->ID))
	{
	case MerchantMembers::Open:
		Dest.Set(pMerchantWnd->IsVisible());
		Dest.Type = pBoolType;
		return true;

	case MerchantMembers::ItemsReceived:
		Dest.Set(gItemsReceived);
		Dest.Type = pBoolType;
		return true;

	case MerchantMembers::Item:
		Dest.Type = pItemType;

		if (Index[0])
		{
			VePointer<MerchantPageHandler>& page = pMerchantWnd->PageHandlers[RegularMerchantPage];

			if (IsNumber(Index))
			{
				// by index
				int nIndex = GetIntFromString(Index, 0) - 1;
				if (nIndex < 0)
					return false;

				if (nIndex < page->ItemContainer.GetSize())
				{
					if (Dest.Ptr = page->ItemContainer[nIndex].pItem)
					{
						return true;
					}
				}
			}
			else
			{
				// by name
				for (int nIndex = 0; nIndex < page->ItemContainer.GetSize(); nIndex++)
				{
					if (ItemClient* pContents = page->ItemContainer[nIndex].pItem)
					{
						const char* itemName = GetItemFromContents(pContents)->Name;

						if (MaybeExactCompare(itemName, Index))
						{
							Dest.Ptr = pContents;
							return true;
						}
					}
				}
			}
		}
		return false;

	case MerchantMembers::Items:
		Dest.DWord = pMerchantWnd->PageHandlers[RegularMerchantPage]->ItemContainer.GetSize();
		Dest.Type = pIntType;
		return true;

	case MerchantMembers::SelectedItem:
		Dest.Ptr = pMerchantWnd->pSelectedItem.get();
		Dest.Type = pItemType;
		return true;

	case MerchantMembers::Markup:
		Dest.Float = pMerchantWnd->MerchantGreed;
		Dest.Type = pFloatType;
		return true;

	case MerchantMembers::Full: {
		Dest.Type = pBoolType;

		VePointer<MerchantPageHandler>& page = pMerchantWnd->PageHandlers[RegularMerchantPage];
		Dest.Set(page->ItemContainer.GetSize() >= page->MaxItems);
		return true;
	}

	default: break;
	}

	return false;
}

bool MQ2MerchantType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (pActiveMerchant && pMerchantWnd)
	{
		strcpy_s(Destination, MAX_STRING, "TRUE");
	}
	else
	{
		strcpy_s(Destination, MAX_STRING, "FALSE");
	}
	return true;
}

bool MQ2MerchantType::Downcast(const MQVarPtr& fromVar, MQVarPtr& toVar, MQ2Type* toType)
{
	if (toType == pSpawnType)
	{
		toVar = pSpawnType->MakeVarPtr(pActiveMerchant);
		return true;
	}

	return false;
}

bool MQ2MerchantType::dataMerchant(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Type = pMerchantType;
	return true;
}

} // namespace mq::datatypes
