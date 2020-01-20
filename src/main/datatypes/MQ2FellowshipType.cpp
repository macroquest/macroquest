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

bool MQ2FellowshipType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	FELLOWSHIPINFO* pFellowship = reinterpret_cast<FELLOWSHIPINFO*>(VarPtr.Ptr);
	if (!VarPtr.Ptr)
		return false;

	MQTypeMember* pMember = MQ2FellowshipType::FindMember(Member);
	if (!pMember)
		return false;

	SPAWNINFO* pMySpawn = pLocalPlayer;

	switch (static_cast<FellowshipTypeMembers>(pMember->ID))
	{
	case ID:
		Dest.DWord = pFellowship->FellowshipID;
		Dest.Type = pIntType;
		return true;

	case Leader:
		strcpy_s(DataTypeTemp, pFellowship->Leader);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case MotD:
		strcpy_s(DataTypeTemp, pFellowship->MotD);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Members:
		Dest.DWord = pFellowship->Members;
		Dest.Type = pIntType;
		return true;

	case xMember:
		Dest.Type = pFellowshipMemberType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int i = GetIntFromString(Index, 0) - 1;
				if (i < 0 || i >= pFellowship->Members)
					return false;

				Dest.Ptr = &pFellowship->FellowshipMember[i];
				return true;
			}
			else
			{
				for (int i = 0; i < pFellowship->Members; i++)
				{
					if (ci_equals(pFellowship->FellowshipMember[i].Name, Index))
					{
						Dest.Ptr = &pFellowship->FellowshipMember[i];
						return true;
					}
				}
			}
		}
		return false;

	case CampfireDuration:
		Dest.DWord = 0;
		Dest.Type = pTicksType;
		if (pMySpawn->CampfireTimestamp)
		{
			Dest.DWord = (pMySpawn->CampfireTimestamp - GetFastTime()) / 6;
			return true;
		}
		return false;

	case CampfireY:
		Dest.Float = pMySpawn->CampfireY;
		Dest.Type = pFloatType;
		return true;
	case CampfireX:
		Dest.Float = pMySpawn->CampfireX;
		Dest.Type = pFloatType;
		return true;

	case CampfireZ:
		Dest.Float = pMySpawn->CampfireZ;
		Dest.Type = pFloatType;
		return true;

	case CampfireZone:
		Dest.Type = pZoneType;
		if (int zoneID = (pMySpawn->CampfireZoneID & 0x7FFF))
		{
			if (zoneID < MAX_ZONES && pWorldData)
			{
				Dest.Ptr = ((PWORLDDATA)pWorldData)->ZoneArray[zoneID];
				return true;
			}
		}
		return false;

	case Campfire:
		Dest.Int = pMySpawn->Campfire;
		Dest.Type = pBoolType;
		return true;

	default: break;
	}

	return false;
}

