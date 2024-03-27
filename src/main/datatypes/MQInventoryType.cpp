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
#include "mq/api/Inventory.h"

namespace mq::datatypes {


//============================================================================

enum class BankTypeMembers
{
	BagSlots,
	FreeSlots,
	TotalSlots,
	Platinum,
	Gold,
	Silver,
	Copper,
};

MQBankType::MQBankType() : MQ2Type("bank")
{
	ScopedTypeMember(BankTypeMembers, BagSlots);
	ScopedTypeMember(BankTypeMembers, FreeSlots);
	ScopedTypeMember(BankTypeMembers, TotalSlots);
	ScopedTypeMember(BankTypeMembers, Platinum);
	ScopedTypeMember(BankTypeMembers, Gold);
	ScopedTypeMember(BankTypeMembers, Silver);
	ScopedTypeMember(BankTypeMembers, Copper);
}

bool MQBankType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
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
		Dest.Type = pIntType;
		if (IsNumber(Index))
		{
			Dest.Set<int>(GetBankSlotCount(GetIntFromString(Index,0), true));
		}
		else
		{
			const int sizeEnum = GetItemSizeFromDesc(Index);
			if (sizeEnum == -1)
				return false;
			Dest.Set<int>(GetBankSlotCount(sizeEnum, true));
		}
		return true;

	case BankTypeMembers::BagSlots:
		Dest.Type = pIntType;
		Dest.Set<int>(GetAvailableBankSlots());
		return true;

	case BankTypeMembers::TotalSlots:
		Dest.Type = pIntType;
		if (IsNumber(Index))
		{
			Dest.Set<int>(GetBankSlotCount(GetIntFromString(Index, 0)));
		}
		else
		{
			const int sizeEnum = GetItemSizeFromDesc(Index);
			if (sizeEnum == -1)
				return false;
			Dest.Set<int>(GetBankSlotCount(sizeEnum));
		}
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

	default:
		break;
	}

	return false;
}

bool MQBankType::dataBank(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Ptr = nullptr;
	Ret.Type = pBankType;
	return true;
}

enum class InventoryTypeMembers
{
	Bank,
};

MQInventoryType::MQInventoryType() : MQ2Type("inventory")
{
	ScopedTypeMember(InventoryTypeMembers, Bank);
}

bool MQInventoryType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	const MQTypeMember* pMember = FindMember(Member);

	if (!pMember)
		return false;

	switch (static_cast<InventoryTypeMembers>(pMember->ID))
	{
	case InventoryTypeMembers::Bank:
		Dest.Type = pBankType;
		return true;
	}

	return false;
}

bool MQInventoryType::dataInventory(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Ptr = nullptr;
	Ret.Type = pInventoryType;
	return true;
}

} // namespace mq::datatypes