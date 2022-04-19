/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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

enum class CurrentZoneMembers
{
	Name = 1,
	ShortName,
	Type,
	Gravity,
	SkyEnabled,
	SafeY,
	SafeX,
	SafeZ,
	MinClip,
	MaxClip,
	ID,
	SafeN,
	SafeW,
	SafeU,
	ZoneType,
	Dungeon,
	Indoor,
	Outdoor,
	NoBind,
};

MQ2CurrentZoneType::MQ2CurrentZoneType() : MQ2Type("currentzone")
{
	ScopedTypeMember(CurrentZoneMembers, Name);
	ScopedTypeMember(CurrentZoneMembers, ShortName);
	ScopedTypeMember(CurrentZoneMembers, Type);
	ScopedTypeMember(CurrentZoneMembers, Gravity);
	ScopedTypeMember(CurrentZoneMembers, SkyEnabled);
	ScopedTypeMember(CurrentZoneMembers, SafeY);
	ScopedTypeMember(CurrentZoneMembers, SafeX);
	ScopedTypeMember(CurrentZoneMembers, SafeZ);
	ScopedTypeMember(CurrentZoneMembers, MinClip);
	ScopedTypeMember(CurrentZoneMembers, MaxClip);
	ScopedTypeMember(CurrentZoneMembers, ID);
	ScopedTypeMember(CurrentZoneMembers, SafeN);
	ScopedTypeMember(CurrentZoneMembers, SafeW);
	ScopedTypeMember(CurrentZoneMembers, SafeU);
	ScopedTypeMember(CurrentZoneMembers, ZoneType);
	ScopedTypeMember(CurrentZoneMembers, Dungeon);
	ScopedTypeMember(CurrentZoneMembers, Indoor);
	ScopedTypeMember(CurrentZoneMembers, Outdoor);
	ScopedTypeMember(CurrentZoneMembers, NoBind);
}


bool MQ2CurrentZoneType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	ZONEINFO* pCurrentZone = pZoneInfo;

	MQTypeMember* pMember = MQ2CurrentZoneType::FindMember(Member);
	if (!pMember)
	{
		int zid = pCurrentZone->ZoneID & 0x7FFF;
		if (zid < MAX_ZONES)
		{
			if (EQZoneInfo* pZList = pWorldData->ZoneArray[zid])
			{
				MQVarPtr data;
				data.Ptr = &pZList;

				return pZoneType->GetMember(data, Member, Index, Dest);
			}
		}

		return false;
	}

	switch (static_cast<CurrentZoneMembers>(pMember->ID))
	{
	case CurrentZoneMembers::ID:
		Dest.Int = pLocalPC ? (pLocalPC->zoneId & 0x7FFF) : 0;
		Dest.Type = pIntType;
		return true;

	case CurrentZoneMembers::Name:
		strcpy_s(DataTypeTemp, pCurrentZone->LongName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case CurrentZoneMembers::ShortName:
		strcpy_s(DataTypeTemp, pCurrentZone->ShortName);
		Dest.Ptr = &DataTypeTemp;
		Dest.Type = pStringType;
		return true;

	case CurrentZoneMembers::Type:
		Dest.DWord = pCurrentZone->OutDoor;
		Dest.Type = pIntType;
		return true;

	case CurrentZoneMembers::Gravity:
		Dest.Float = pCurrentZone->ZoneGravity;
		Dest.Type = pFloatType;
		return true;

	case CurrentZoneMembers::SkyEnabled:
		Dest.DWord = pCurrentZone->SkyEnabled;
		Dest.Type = pIntType;
		return true;

	case CurrentZoneMembers::MinClip:
		Dest.Float = pCurrentZone->MinClip;
		Dest.Type = pFloatType;
		return true;

	case CurrentZoneMembers::MaxClip:
		Dest.Float = pCurrentZone->MaxClip;
		Dest.Type = pFloatType;
		return true;

	case CurrentZoneMembers::ZoneType:
		Dest.DWord = (*EQADDR_ZONETYPE);
		Dest.Type = pIntType;
		return true;

	case CurrentZoneMembers::Dungeon:
	case CurrentZoneMembers::Indoor:
		Dest.Set(indoor);
		Dest.Type = pBoolType;
		return true;

	case CurrentZoneMembers::Outdoor:
		Dest.Set(outdoor);
		Dest.Type = pBoolType;
		return true;

	case CurrentZoneMembers::NoBind:
		Dest.Set(!bindable);
		Dest.Type = pBoolType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2CurrentZoneType::ToString(MQVarPtr VarPtr, char* Destination)
{
	strcpy_s(Destination, MAX_STRING, pZoneInfo->LongName);
	return true;
}

bool MQ2CurrentZoneType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pCurrentZoneType)
		return false;
	VarPtr.Ptr = Source.Ptr;
	return true;
}

} // namespace mq::datatypes
