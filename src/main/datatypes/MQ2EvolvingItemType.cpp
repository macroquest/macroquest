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

bool MQ2EvolvingItemType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	ItemClient* pItem = reinterpret_cast<ItemClient*>(VarPtr.Ptr);
	if (!pItem)
		return false;

	MQTypeMember* pMember = MQ2EvolvingItemType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<EvolvingItemMembers>(pMember->ID))
	{
	case ExpOn:
		Dest.Set(true); // its always on after 2019-02-14 test patch
		Dest.Type = pBoolType;
		return true;

	case ExpPct:
		if (pItem->pEvolutionData)
		{
			Dest.Float = (float)pItem->pEvolutionData->EvolvingExpPct;
			Dest.Type = pFloatType;
			return true;
		}
		break;

	case Level:
		if (pItem->pEvolutionData)
		{
			Dest.Int = pItem->pEvolutionData->EvolvingCurrentLevel;
			Dest.Type = pIntType;
			return true;
		}
		break;

	case MaxLevel:
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

