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

enum class EvolvingItemMembers
{
	ExpPct = 1,
	ExpOn,
	Level,
	MaxLevel,
};

MQ2EvolvingItemType::MQ2EvolvingItemType() : MQ2Type("Evolving")
{
	ScopedTypeMember(EvolvingItemMembers, ExpPct);
	ScopedTypeMember(EvolvingItemMembers, ExpOn);
	ScopedTypeMember(EvolvingItemMembers, Level);
	ScopedTypeMember(EvolvingItemMembers, MaxLevel);
}

bool MQ2EvolvingItemType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	ItemPtr pItem = VarPtr.Item;
	if (!pItem)
		return false;

	MQTypeMember* pMember = MQ2EvolvingItemType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<EvolvingItemMembers>(pMember->ID))
	{
	case EvolvingItemMembers::ExpOn:
		Dest.Set(pItem->IsEvolvingExpOn());
		Dest.Type = pBoolType;
		return true;

	case EvolvingItemMembers::ExpPct:
		if (pItem->pEvolutionData)
		{
			Dest.Float = (float)pItem->pEvolutionData->EvolvingExpPct;
			Dest.Type = pFloatType;
			return true;
		}
		break;

	case EvolvingItemMembers::Level:
		if (pItem->pEvolutionData)
		{
			Dest.Int = pItem->pEvolutionData->EvolvingCurrentLevel;
			Dest.Type = pIntType;
			return true;
		}
		break;

	case EvolvingItemMembers::MaxLevel:
		if (pItem->pEvolutionData)
		{
			Dest.Int = pItem->pEvolutionData->EvolvingMaxLevel;
			Dest.Type = pIntType;
			return true;
		}
		break;

	default: break;
	}

	return false;
}

bool MQ2EvolvingItemType::ToString(MQVarPtr VarPtr, char* Destination)
{
	ItemPtr pItem = VarPtr.Item;

	strcpy_s(Destination, MAX_STRING, (pItem && IsEvolvingItem(pItem)) ? "TRUE" : "FALSE");
	return true;
}

} // namespace mq::datatypes
