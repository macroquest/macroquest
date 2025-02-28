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

enum class BandolierTypeMembers
{
	Index = 1,
	Active,
	Name,
	Item,
};

enum class BandolierTypeMethods
{
	Activate = 1,
};

MQ2BandolierType::MQ2BandolierType() : MQ2Type("bandolier")
{
	ScopedTypeMember(BandolierTypeMembers, Index);
	ScopedTypeMember(BandolierTypeMembers, Active);
	ScopedTypeMember(BandolierTypeMembers, Name);
	ScopedTypeMember(BandolierTypeMembers, Item);

	ScopedTypeMethod(BandolierTypeMethods, Activate);
}

bool MQ2BandolierType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
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
		case BandolierTypeMembers::Active: {
			Dest.Set(false);
			Dest.Type = pBoolType;

			struct CheckSlots {
				eBandolierSlot bandolierSlot;
				eInventorySlot inventorySlot;
			};
			static constexpr CheckSlots checkSlots[BandolierSlot_Max] = {
				{ BandolierSlot_Primary,   InvSlot_Primary },
				{ BandolierSlot_Secondary, InvSlot_Secondary },
				{ BandolierSlot_Ranged,    InvSlot_Range },
				{ BandolierSlot_Ammo,      InvSlot_Ammo },
			};

			for (const CheckSlots& slotInfo : checkSlots)
			{
				ItemPtr pItem = pcProfile->GetInventorySlot(slotInfo.inventorySlot);
				int slotItem = pItem ? pItem->GetID() : 0;
				int bandolierItem = pBand->Items[slotInfo.bandolierSlot].ItemID;

				// If they don't match then the set isn't active.
				if (bandolierItem != slotItem)
					return true;
			}

			Dest.Set(true);
			return true;
		}

		case BandolierTypeMembers::Index:
			Dest.DWord = index + 1;
			Dest.Type = pIntType;
			return true;

		case BandolierTypeMembers::Item: {
			Dest.Type = pBandolierItemType;
			if (!Index[0])
				return false;

			const int indexItem = std::clamp(GetIntFromString(Index, 0) - 1, 0, MAX_BANDOLIER_SLOTS - 1);
			Dest.Ptr = (void*)&pBand->Items[indexItem];
			return true;
		}

		case BandolierTypeMembers::Name:
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
		case BandolierTypeMethods::Activate:
			pLocalPC->BandolierSwap(index);

			if (pBandolierWnd)
			{
				if (pBandolierWnd->pWeaponSetList)
				{
					pBandolierWnd->pWeaponSetList->SetCurSel(index);
				}
			}

			Dest.Set(true);
			Dest.Type = pBoolType;
			return true;
		}
		return false;
	}

	return false;
}

bool MQ2BandolierType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (PcProfile* pProfile = GetPcProfile())
	{
		int index = std::clamp(VarPtr.Int, 0, MAX_BANDOLIER_ITEMS - 1);
		strcpy_s(Destination, MAX_STRING, pProfile->Bandolier[index].Name);
		return true;
	}
	return false;
}

enum class BandolierItemTypeMembers
{
	ID = 1,
	IconID,
	Name,
};

MQ2BandolierItemType::MQ2BandolierItemType() : MQ2Type("bandolieritem")
{
	ScopedTypeMember(BandolierItemTypeMembers, ID);
	ScopedTypeMember(BandolierItemTypeMembers, IconID);
	ScopedTypeMember(BandolierItemTypeMembers, Name);
}

bool MQ2BandolierItemType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (BandolierItemInfo* ptr = (BandolierItemInfo*)VarPtr.Ptr)
	{
		MQTypeMember* pMember = MQ2BandolierItemType::FindMember(Member);
		if (pMember)
		{
			switch (static_cast<BandolierItemTypeMembers>(pMember->ID))
			{
			case BandolierItemTypeMembers::IconID:
				Dest.DWord = ptr->IconID;
				Dest.Type = pIntType;
				return true;

			case BandolierItemTypeMembers::ID:
				Dest.DWord = ptr->ItemID;
				Dest.Type = pIntType;
				return true;

			case BandolierItemTypeMembers::Name:
				strcpy_s(DataTypeTemp, ptr->Name);
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;

			default: break;
			};

			return false;
		}
	}
	return false;
}

bool MQ2BandolierItemType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (BandolierItemInfo* ptr = reinterpret_cast<BandolierItemInfo*>(VarPtr.Ptr))
	{
		strcpy_s(Destination, MAX_STRING, ptr->Name);
		return true;
	}
	return false;
}

} // namespace mq::datatypes
