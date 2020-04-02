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

enum class MercenaryMembers
{
	AAPoints,
	Stance,
	State,
	StateID,
	Index
};

MQ2MercenaryType::MQ2MercenaryType() : MQ2Type("mercenary")
{
	ScopedTypeMember(MercenaryMembers, AAPoints);
	ScopedTypeMember(MercenaryMembers, Stance);
	ScopedTypeMember(MercenaryMembers, State);
	ScopedTypeMember(MercenaryMembers, StateID);
	ScopedTypeMember(MercenaryMembers, Index);
}

bool MQ2MercenaryType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	SPAWNINFO* pSpawn = reinterpret_cast<SPAWNINFO*>(VarPtr.Ptr);
	if (!pSpawn)
		return false;

	MQTypeMember* pMember = MQ2MercenaryType::FindMember(Member);
	if (!pMember)
	{
		if (!pSpawn->SpawnID)
			return false;

		return pSpawnType->GetMember(VarPtr, Member, Index, Dest);
	}

	switch (static_cast<MercenaryMembers>(pMember->ID))
	{
	case MercenaryMembers::AAPoints:
		Dest.DWord = GetCharInfo()->MercAAPoints;
		Dest.Type = pIntType;
		return true;

	case MercenaryMembers::Stance:
		strcpy_s(DataTypeTemp, "NULL");
		if (pMercInfo->HaveMerc)
		{
			for (int n = 0; n < pMercInfo->NumStances; n++)
			{
				if (pMercInfo->pMercStanceData[n]->nStance == pMercInfo->ActiveStance)
				{
					strcpy_s(DataTypeTemp, pCDBStr->GetString(pMercInfo->pMercStanceData[n]->nDbStance, eMercenaryStanceName));
					break;
				}
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case MercenaryMembers::State:
		switch (pMercInfo->MercState)
		{
		case 0:
			strcpy_s(DataTypeTemp, "DEAD");
			break;

		case 1:
			strcpy_s(DataTypeTemp, "SUSPENDED");
			break;

		case 5:
			if (pMercInfo->HaveMerc) {
				strcpy_s(DataTypeTemp, "ACTIVE");
			}
			else {
				strcpy_s(DataTypeTemp, "NOMERC");
			}
			break;

		default:
			strcpy_s(DataTypeTemp, "UNKNOWN");
			break;
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case MercenaryMembers::StateID:
		Dest.DWord = pMercInfo->MercState;
		Dest.Type = pIntType;
		return true;

	case MercenaryMembers::Index:
		Dest.DWord = pMercInfo->CurrentMercIndex + 1;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2MercenaryType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (!VarPtr.Ptr)
		return false;

	SPAWNINFO* pSpawn = static_cast<SPAWNINFO*>(VarPtr.Ptr);
	strcpy_s(Destination, MAX_STRING, pSpawn->Name);
	return true;
}

void MQ2MercenaryType::InitVariable(MQVarPtr& VarPtr)
{
	// FIXME: Do not Allocate a SPAWNINFO
	VarPtr.Ptr = new SPAWNINFO();

	// FIXME: Do not ZeroMemory a SPAWNINFO
	ZeroMemory(VarPtr.Ptr, sizeof(SPAWNINFO));
}

void MQ2MercenaryType::FreeVariable(MQVarPtr& VarPtr)
{
	// FIXME: Do not Allocate a SPAWNINFO
	SPAWNINFO* pSpawn = static_cast<SPAWNINFO*>(VarPtr.Ptr);
	delete pSpawn;
}

bool MQ2MercenaryType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	if (Source.Type == pSpawnType)
	{
		memcpy(VarPtr.Ptr, Source.Ptr, sizeof(SPAWNINFO));
		return true;
	}
	else
	{
		if (SPAWNINFO* pOther = (SPAWNINFO*)GetSpawnByID(Source.DWord))
		{
			memcpy(VarPtr.Ptr, pOther, sizeof(SPAWNINFO));
			return true;
		}
	}
	return false;
}

bool MQ2MercenaryType::FromString(MQVarPtr& VarPtr, char* Source)
{
	if (SPAWNINFO* pOther = (SPAWNINFO*)GetSpawnByID(GetIntFromString(Source, 0)))
	{
		memcpy(VarPtr.Ptr, pOther, sizeof(SPAWNINFO));
		return true;
	}
	return false;
}

