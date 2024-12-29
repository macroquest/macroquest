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

enum class FellowshipTypeMembers
{
	ID = 1,
	Leader,
	MotD,
	Members,
	Member,
	CampfireDuration,
	CampfireY,
	CampfireX,
	CampfireZ,
	CampfireZone,
	Campfire,
	Sharing,
	Exists,
};

MQ2FellowshipType::MQ2FellowshipType()
	: MQ2Type("fellowship")
{
	ScopedTypeMember(FellowshipTypeMembers, ID);
	ScopedTypeMember(FellowshipTypeMembers, Leader);
	ScopedTypeMember(FellowshipTypeMembers, MotD);
	ScopedTypeMember(FellowshipTypeMembers, Members);
	ScopedTypeMember(FellowshipTypeMembers, Member);
	ScopedTypeMember(FellowshipTypeMembers, CampfireDuration);
	ScopedTypeMember(FellowshipTypeMembers, CampfireY);
	ScopedTypeMember(FellowshipTypeMembers, CampfireX);
	ScopedTypeMember(FellowshipTypeMembers, CampfireZ);
	ScopedTypeMember(FellowshipTypeMembers, CampfireZone);
	ScopedTypeMember(FellowshipTypeMembers, Campfire);
	ScopedTypeMember(FellowshipTypeMembers, Sharing);
	ScopedTypeMember(FellowshipTypeMembers, Exists);
}

bool MQ2FellowshipType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2FellowshipType::FindMember(Member);
	if (!pMember)
		return false;

	if (static_cast<FellowshipTypeMembers>(pMember->ID) == FellowshipTypeMembers::Exists)
	{
		Dest.Set(VarPtr.Ptr && static_cast<SFellowship*>(VarPtr.Ptr)->FellowshipID != 0);
		Dest.Type = pBoolType;
		return true;
	}

	SFellowship* pFellowship = reinterpret_cast<SFellowship*>(VarPtr.Ptr);
	if (!VarPtr.Ptr)
		return false;

	SPAWNINFO* pMySpawn = pLocalPlayer;

	switch (static_cast<FellowshipTypeMembers>(pMember->ID))
	{
	case FellowshipTypeMembers::ID:
		Dest.DWord = pFellowship->FellowshipID;
		Dest.Type = pIntType;
		return true;

	case FellowshipTypeMembers::Leader:
		strcpy_s(DataTypeTemp, pFellowship->Leader);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case FellowshipTypeMembers::MotD:
		strcpy_s(DataTypeTemp, pFellowship->MotD);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case FellowshipTypeMembers::Members:
		Dest.DWord = pFellowship->Members;
		Dest.Type = pIntType;
		return true;

	case FellowshipTypeMembers::Member:
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

	case FellowshipTypeMembers::CampfireDuration:
		Dest.DWord = 0;
		Dest.Type = pTicksType;
		if (pMySpawn->CampfireTimestamp)
		{
			Dest.DWord = (pMySpawn->CampfireTimestamp - GetFastTime()) / 6;
			return true;
		}
		return false;

	case FellowshipTypeMembers::CampfireY:
		Dest.Float = pMySpawn->CampfireY;
		Dest.Type = pFloatType;
		return true;
	case FellowshipTypeMembers::CampfireX:
		Dest.Float = pMySpawn->CampfireX;
		Dest.Type = pFloatType;
		return true;

	case FellowshipTypeMembers::CampfireZ:
		Dest.Float = pMySpawn->CampfireZ;
		Dest.Type = pFloatType;
		return true;

	case FellowshipTypeMembers::CampfireZone:
		Dest.Type = pZoneType;
		if (int zoneID = (pMySpawn->CampfireZoneID & 0x7FFF))
		{
			if (zoneID < MAX_ZONES && pWorldData)
			{
				Dest.Ptr = pWorldData->ZoneArray[zoneID];
				return true;
			}
		}
		return false;

	case FellowshipTypeMembers::Campfire:
		Dest.Set(pMySpawn->Campfire);
		Dest.Type = pBoolType;
		return true;

	case FellowshipTypeMembers::Sharing:
		if (Index[0] && IsNumber(Index))
		{
			int nMember = GetIntFromString(Index, 0) - 1;
			if (nMember < 0) nMember = 0;

			if (nMember > pFellowship->Members)
				return false;

			Dest.Set(pFellowship->bExpSharingEnabled[nMember]);
			Dest.Type = pBoolType;
			return true;
		}
		return false;

	default: break;
	}

	return false;
}

bool MQ2FellowshipType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (VarPtr.Ptr && static_cast<SFellowship*>(VarPtr.Ptr)->FellowshipID != 0)
		strcpy_s(Destination, MAX_STRING, "TRUE");
	else
		strcpy_s(Destination, MAX_STRING, "FALSE");
	return true;
}

enum class FMTypeMembers
{
	Zone = 1,
	Level,
	Class,
	LastOn,
	Name,
	Sharing,
};

MQ2FellowshipMemberType::MQ2FellowshipMemberType()
	: MQ2Type("fellowshipmember")
{
	ScopedTypeMember(FMTypeMembers, Zone);
	ScopedTypeMember(FMTypeMembers, Level);
	ScopedTypeMember(FMTypeMembers, Class);
	ScopedTypeMember(FMTypeMembers, LastOn);
	ScopedTypeMember(FMTypeMembers, Name);
	ScopedTypeMember(FMTypeMembers, Sharing);
}

bool MQ2FellowshipMemberType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	SFellowshipMember* pFellowshipMember = reinterpret_cast<SFellowshipMember*>(VarPtr.Ptr);
	if (!pFellowshipMember)
		return false;

	if (!pLocalPlayer)
		return false;

	MQTypeMember* pMember = MQ2FellowshipMemberType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<FMTypeMembers>(pMember->ID))
	{
	case FMTypeMembers::Zone:
		if (int zoneID = (pFellowshipMember->ZoneID & 0x7FFF))
		{
			if (zoneID < MAX_ZONES && pWorldData)
			{
				Dest.Ptr = pWorldData->ZoneArray[zoneID];
				Dest.Type = pZoneType;
				return true;
			}
		}
		return false;

	case FMTypeMembers::Level:
		Dest.DWord = pFellowshipMember->Level;
		Dest.Type = pIntType;
		return true;

	case FMTypeMembers::Class:
		Dest.DWord = pFellowshipMember->Class;
		Dest.Type = pClassType;
		return true;

	case FMTypeMembers::LastOn:
		Dest.DWord = 0;
		Dest.Type = pTicksType;
		if (pFellowshipMember->LastOn)
		{
			Dest.DWord = (GetFastTime() - pFellowshipMember->LastOn) / 6;
			return true;
		}
		return false;

	case FMTypeMembers::Name:
		strcpy_s(DataTypeTemp, pFellowshipMember->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case FMTypeMembers::Sharing: {
		Dest.Set(false);
		Dest.Type = pBoolType;

		for (int i = 0; i < pLocalPlayer->Fellowship.Members; ++i)
		{
			if (pFellowshipMember->UniqueEntityID == pLocalPlayer->Fellowship.FellowshipMember[i].UniqueEntityID)
			{
				Dest.Set(pLocalPlayer->Fellowship.bExpSharingEnabled[i]);
				break;
			}
		}
		return true;
	}

	default: break;
	}

	return false;
}

bool MQ2FellowshipMemberType::ToString(MQVarPtr VarPtr, char* Destination)
{
	SFellowshipMember* pFellowshipMember = reinterpret_cast<SFellowshipMember*>(VarPtr.Ptr);
	if (!pFellowshipMember)
		return false;

	strcpy_s(Destination, MAX_STRING, pFellowshipMember->Name);
	return true;
}

} // namespace mq::datatypes
