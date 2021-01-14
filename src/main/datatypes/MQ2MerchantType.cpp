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
		case SelectItem: {
			if (pMerchantWnd->IsVisible())
			{
				bool bFound = false;
				int listIndex = 0;
				ItemClient* pItem = nullptr;

				for (int i = 0; i < pMerchantWnd->PageHandlers[RegularMerchantPage]->ItemContainer.GetSize(); i++)
				{
					if (pItem = pMerchantWnd->PageHandlers[RegularMerchantPage]->ItemContainer[i].pCont)
					{
						if (MaybeExactCompare(pItem->GetName(), Index))
						{
							listIndex = i;
							bFound = true;
							break;
						}
					}
				}

				if (bFound)
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

		case Buy: {
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

		case Sell: {
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

		case OpenWindow: {
			MQSpawnSearch SearchSpawn;
			ClearSearchSpawn(&SearchSpawn);
			SearchSpawn.FRadius = 999999.0f;
			SearchSpawn.bMerchant = true;

			if (pTarget && ((SPAWNINFO*)pTarget)->mActorClient.Class == 41)
			{
				pEverQuest->RightClickedOnPlayer(pTarget, 0);
				return true;
			}
			else if (SPAWNINFO* pSpawn = SearchThroughSpawns(&SearchSpawn, (SPAWNINFO*)pLocalPlayer))
			{
				pTarget = pSpawn;
				pEverQuest->RightClickedOnPlayer((PlayerClient*)pSpawn, 0);
				return true;
			}
			return true;
		}

		case CloseWindow:
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
		MQVarPtr data;
		data.Ptr = pActiveMerchant;

		return pSpawnType->GetMember(data, Member, Index, Dest);
	}

	switch (static_cast<MerchantMembers>(pMember->ID))
	{
	case Open:
		Dest.Set(pMerchantWnd->IsVisible());
		Dest.Type = pBoolType;
		return true;

	case ItemsReceived:
		Dest.Set(gItemsReceived);
		Dest.Type = pBoolType;
		return true;

	case Item:
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
					if (Dest.Ptr = page->ItemContainer[nIndex].pCont)
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
					if (ItemClient* pContents = page->ItemContainer[nIndex].pCont)
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

	case Items:
		Dest.DWord = pMerchantWnd->PageHandlers[RegularMerchantPage]->ItemContainer.GetSize();
		Dest.Type = pIntType;
		return true;

	case SelectedItem:
		Dest.Ptr = pMerchantWnd->pSelectedItem.get();
		Dest.Type = pItemType;
		return true;

	case Markup:
		Dest.Float = pMerchantWnd->MerchantGreed;
		Dest.Type = pFloatType;
		return true;

	case Full: {
		Dest.Type = pBoolType;

		VePointer<MerchantPageHandler>& page = pMerchantWnd->PageHandlers[RegularMerchantPage];
		Dest.Set(page->ItemContainer.GetSize() >= page->MaxItems);
		return true;
	}

	default: break;
	}

	return false;
}

