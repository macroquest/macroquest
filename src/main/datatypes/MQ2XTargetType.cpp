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

enum class XTargetMembers
{
	TargetType = 1,
	ID,
	Name,
	PctAggro
};

MQ2XTargetType::MQ2XTargetType() : MQ2Type("xtarget")
{
	ScopedTypeMember(XTargetMembers, TargetType);
	ScopedTypeMember(XTargetMembers, ID);
	ScopedTypeMember(XTargetMembers, Name);
	ScopedTypeMember(XTargetMembers, PctAggro);
}

bool MQ2XTargetType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pLocalPC)
		return false;

	int index = VarPtr.DWord;
	ExtendedTargetSlot* xts = pLocalPC->pExtendedTargetList->GetSlot(index);
	if (!xts) return false;

	MQTypeMember* pMember = MQ2XTargetType::FindMember(Member);
	if (!pMember)
	{
		return pSpawnType->GetMember(GetSpawnByID(xts->SpawnID), Member, Index, Dest);
	}

	switch (static_cast<XTargetMembers>(pMember->ID))
	{
	case XTargetMembers::TargetType:
		if (const char* ptr = pLocalPC->pExtendedTargetList->ExtendedTargetRoleName(xts->xTargetType))
			strcpy_s(DataTypeTemp, ptr);
		else
			strcpy_s(DataTypeTemp, "UNKNOWN");
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case XTargetMembers::ID:
		Dest.DWord = xts->SpawnID;
		Dest.Type = pIntType;
		return true;

	case XTargetMembers::Name:
		if (xts->Name[0] != 0)
			strcpy_s(DataTypeTemp, xts->Name);
		else
			strcpy_s(DataTypeTemp, "NULL");
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case XTargetMembers::PctAggro:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pAggroInfo)
		{
			uint32_t aggroIndex = AD_xTarget1 + index;
			if (aggroIndex >= MAX_AGGRO_METER_SIZE)
				return false;

			Dest.DWord = pAggroInfo->aggroData[aggroIndex].AggroPct;
			return true;
		}
		return false;

	default: break;
	}

	return false;
};

bool MQ2XTargetType::ToString(MQVarPtr VarPtr, char* Destination)
{
	int index = VarPtr.DWord;
	ExtendedTargetSlot* xts = nullptr;

	if (pLocalPC
		&& (xts = pLocalPC->pExtendedTargetList->GetSlot(index)))
	{
		strcpy_s(Destination, MAX_STRING, xts->Name);
	}
	else
	{
		strcpy_s(Destination, MAX_STRING, "NULL");
	}

	return true;
}

bool MQ2XTargetType::Downcast(const MQVarPtr& fromVar, MQVarPtr& toVar, MQ2Type* toType)
{
	if (toType == pSpawnType)
	{
		SPAWNINFO* pSpawn = nullptr;

		if (pLocalPC)
		{
			int index = fromVar.Int;
			if (ExtendedTargetSlot* xts = pLocalPC->pExtendedTargetList->GetSlot(index))
			{
				pSpawn = GetSpawnByID(xts->SpawnID);
			}
		}

		toVar = pSpawnType->MakeVarPtr(pSpawn);
		return true;
	}

	return false;
}

} // namespace mq::datatypes
