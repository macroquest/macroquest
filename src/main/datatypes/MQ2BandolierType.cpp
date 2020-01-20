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

bool MQ2BandolierType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	PcProfile* pcProfile = GetPcProfile();
	if (!pcProfile)
		return false;

	const int index = std::clamp<int>(VarPtr.DWord, 0, MAX_BANDOLIER_ITEMS - 1);

	BandolierSet* pBand = &pcProfile->Bandolier[index];
	if (!pBand)
		return false;

	if (!pBand->Name[0])
		return false;

	//----------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = MQ2BandolierType::FindMember(Member);
	if (pMember)
	{
		switch (static_cast<BandolierTypeMembers>(pMember->ID))
		{
		case Active:
			Dest.DWord = 0;
			Dest.Type = pBoolType;

			// TODO: Fix duplication
			if (pcProfile->pInventoryArray && pcProfile->pInventoryArray->InventoryArray[0])
			{
				if (pBand->Items[0].ItemID)
				{
					if (!pcProfile->pInventoryArray->Inventory.Primary)
						return true;

					if (pcProfile->pInventoryArray->Inventory.Primary->ID != pBand->Items[0].ItemID)
						return true;
				}
				else if (pcProfile->pInventoryArray->Inventory.Primary)
				{
					return true;
				}

				if (pBand->Items[1].ItemID)
				{
					if (!pcProfile->pInventoryArray->Inventory.Secondary)
						return true;

					if (pcProfile->pInventoryArray->Inventory.Secondary->ID != pBand->Items[1].ItemID)
						return true;
				}
				else if (pcProfile->pInventoryArray->Inventory.Secondary)
				{
					return true;
				}

				if (pBand->Items[2].ItemID)
				{
					if (!pcProfile->pInventoryArray->Inventory.Range)
						return true;

					if (pcProfile->pInventoryArray->Inventory.Range->ID != pBand->Items[2].ItemID)
						return true;
				}
				else if (pcProfile->pInventoryArray->Inventory.Range)
				{
					return true;
				}

				if (pBand->Items[3].ItemID)
				{
					if (!pcProfile->pInventoryArray->Inventory.Ammo)
						return true;

					if (pcProfile->pInventoryArray->Inventory.Ammo->ID != pBand->Items[3].ItemID)
						return true;
				}
				else if (pcProfile->pInventoryArray->Inventory.Ammo)
				{
					return true;
				}

				Dest.DWord = 1;
			}
			return true;

		case xIndex:
			Dest.DWord = index + 1;
			Dest.Type = pIntType;
			return true;

		case Item: {
			Dest.Type = pBandolierItemType;
			if (!Index[0])
				return false;

			const int indexItem = std::clamp(GetIntFromString(Index, 0) - 1, 0, MAX_BANDOLIER_SLOTS - 1);
			Dest.HighPart = indexItem;
			Dest.Ptr = (void*)&pBand->Items[indexItem];
			return true;
		}

		case Name:
			strcpy_s(DataTypeTemp, pBand->Name);
			Dest.Ptr = DataTypeTemp;
			Dest.Type = pStringType;
			return true;

		default: break;
		};

		return false;
	}

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2BandolierType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<BandolierTypeMethods>(pMethod->ID))
		{
		case Activate:
			pPCData->BandolierSwap(index);

			if (pBandolierWnd)
			{
				if (pBandolierWnd->pWeaponSetList)
				{
					pBandolierWnd->pWeaponSetList->SetCurSel(index);
				}
			}

			Dest.DWord = 1;
			Dest.Type = pBoolType;
			return true;
		}
		return false;
	}

	return false;
}
