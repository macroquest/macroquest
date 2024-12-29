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

enum class MercenaryMembers
{
	AAPoints = 1,
	Stance,
	State,
	StateID,
	Index,
	Name,
};

static const char* GetMercenaryStateString()
{
	if (!pMercManager->HasMercenary())
	{
		if (pMercManager->currMercenaryIndex != -1)
			return "SUSPENDED";

		return "NONE";
	}

	switch (pMercManager->GetMercenaryState())
	{
	case MercenaryState_Dead:
		return "DEAD";
	case MercenaryState_Active:
		return "ACTIVE";

	default:
		return "SUSPENDED";
	}
}

MQ2MercenaryType::MQ2MercenaryType() : MQ2Type("mercenary")
{
	ScopedTypeMember(MercenaryMembers, AAPoints);
	ScopedTypeMember(MercenaryMembers, Stance);
	ScopedTypeMember(MercenaryMembers, State);
	ScopedTypeMember(MercenaryMembers, StateID);
	ScopedTypeMember(MercenaryMembers, Index);
	ScopedTypeMember(MercenaryMembers, Name);
}

bool MQ2MercenaryType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	// MercInfo is constructed before we get in game. We don't need to do anything before it exists
	if (!pMercManager)
		return false;

	SPAWNINFO* pMercenary = nullptr;
	if (pMercManager->mercenarySpawnId)
	{
		pMercenary = GetSpawnByID(pMercManager->mercenarySpawnId);
	}

	MQTypeMember* pMember = MQ2MercenaryType::FindMember(Member);
	if (!pMember)
	{
		if (pMercenary)
		{
			// We fall back to spawn type if we found a mercenary.
			return pSpawnType->GetMember(pMercenary, Member, Index, Dest);
		}

		return false;
	}

	switch (static_cast<MercenaryMembers>(pMember->ID))
	{
	case MercenaryMembers::AAPoints:
		Dest.DWord = pLocalPC->GetMercAAPoints();
		Dest.Type = pIntType;
		return true;

	case MercenaryMembers::Stance:
		if (const MercenaryStanceInfo* pStance = pMercManager->GetActiveMercenaryStance())
		{
			strcpy_s(DataTypeTemp, pCDBStr->GetString(pStance->stanceStringId, eMercenaryStanceName));
		}
		else
		{
			strcpy_s(DataTypeTemp, "NULL");
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case MercenaryMembers::State:
		strcpy_s(DataTypeTemp, GetMercenaryStateString());
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case MercenaryMembers::StateID:
		Dest.DWord = static_cast<int>(pMercManager->GetMercenaryState());
		Dest.Type = pIntType;
		return true;

	case MercenaryMembers::Index:
		Dest.DWord = pMercManager->currMercenaryIndex + 1;
		Dest.Type = pIntType;
		return true;

	case MercenaryMembers::Name:
		if (!pMercenary)
			strcpy_s(DataTypeTemp, GetMercenaryStateString());
		else
			strcpy_s(DataTypeTemp, pMercenary->Name);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	default: break;
	}

	return false;
}

bool MQ2MercenaryType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (!pMercManager)
		return false;

	strcpy_s(Destination, MAX_STRING, GetMercenaryStateString());
	return true;
}

bool MQ2MercenaryType::Downcast(const MQVarPtr& fromVar, MQVarPtr& toVar, MQ2Type* toType)
{
	if (toType == pSpawnType)
	{
		SPAWNINFO* pMercenary = pMercManager->mercenarySpawnId ? GetSpawnByID(pMercManager->mercenarySpawnId) : nullptr;
		toVar = pSpawnType->MakeVarPtr(pMercenary);
		return true;
	}

	return false;
}

bool MQ2MercenaryType::dataMercenary(const char* szIndex, MQTypeVar& Ret)
{
	// Mercenary is a global, do not need a pointer to it stored.
	Ret.Ptr = nullptr;
	Ret.Type = pMercenaryType;
	return true;
}

} // namespace mq::datatypes
