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
	case AAPoints:
		Dest.DWord = GetCharInfo()->MercAAPoints;
		Dest.Type = pIntType;
		return true;

	case Stance:
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

	case State:
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

	case StateID:
		Dest.DWord = pMercInfo->MercState;
		Dest.Type = pIntType;
		return true;

	case xIndex:
		Dest.DWord = pMercInfo->CurrentMercIndex + 1;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

