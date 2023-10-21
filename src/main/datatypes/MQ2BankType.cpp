/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
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


//============================================================================

enum class BankTypeMembers
{
	FreeSlots,
	TotalSlots,
	Platinum,
	Gold,
	Silver,
	Copper,
};

int GetNumFreeBankSlots(int nSize)
{
	if (!pLocalPC || !pLocalPlayer)
		return 0;

	int freeSlots = 0;
	for (int slot = 0; slot < GetAvailableBankSlots(); slot++)
	{
		if (ItemPtr pItem = pLocalPC->BankItems.GetItem(slot))
		{
			if (pItem->IsContainer()
				&& (nSize == 0 || pItem->GetItemDefinition()->SizeCapacity >= nSize))
			{
				freeSlots += pItem->GetHeldItems().GetSize() - pItem->GetHeldItems().GetCount();
			}
		}
		else
		{
			freeSlots++;
		}
	}

	return freeSlots;
}

MQ2BankType::MQ2BankType() : MQ2Type("bank")
{
	ScopedTypeMember(BankTypeMembers, FreeSlots);
	ScopedTypeMember(BankTypeMembers, TotalSlots);
	ScopedTypeMember(BankTypeMembers, Platinum);
	ScopedTypeMember(BankTypeMembers, Gold);
	ScopedTypeMember(BankTypeMembers, Silver);
	ScopedTypeMember(BankTypeMembers, Copper);
}

bool MQ2BankType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pLocalPC || !pLocalPlayer)
		return false;

	PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return false;

	MQTypeMember* pMember = FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<BankTypeMembers>(pMember->ID))
	{
	case BankTypeMembers::FreeSlots:
	{
		int nSize = 0;
		if (Index[0])
		{
			nSize = GetIntFromString(Index, 0);
			if (nSize > ItemSize_Giant)
				nSize = ItemSize_Giant;
		}

		Dest.DWord = GetNumFreeBankSlots(nSize);
		Dest.Type = pIntType;
		return true;
	}

	case BankTypeMembers::TotalSlots:
		Dest.Type = pIntType;
		Dest.Set<int>(GetAvailableBankSlots());
		return true;

	case BankTypeMembers::Platinum:
		Dest.DWord = pLocalPC->BankPlat;
		Dest.Type = pIntType;
		return true;

	case BankTypeMembers::Gold:
		Dest.DWord = pLocalPC->BankGold;
		Dest.Type = pIntType;
		return true;

	case BankTypeMembers::Silver:
		Dest.DWord = pLocalPC->BankSilver;
		Dest.Type = pIntType;
		return true;

	case BankTypeMembers::Copper:
		Dest.DWord = pLocalPC->BankCopper;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2BankType::ToString(MQVarPtr VarPtr, char* Destination)
{
	strcpy_s(Destination, MAX_STRING, "Bank");
	return true;
}

bool MQ2BankType::dataBank(const char* szIndex, MQTypeVar& Ret)
{
	if (szIndex[0])
	{
		Ret.Type = pItemType;
		// If an index is provided we are looking up an itemtype by slot index.
		if (IsNumber(szIndex))
		{
			int nSlot = GetIntFromString(szIndex, 0) - 1;
			if (nSlot < 0)
				return true;

			if (nSlot < GetAvailableBankSlots())
			{
				Ret = pItemType->MakeTypeVar(pLocalPC->BankItems.GetItem(nSlot));
				return true;
			}
		}
	}

	// If no index is provided then we're utilizing the bank type
	Ret.Type = pBankType;
	return true;
}

} // namespace mq::datatypes
