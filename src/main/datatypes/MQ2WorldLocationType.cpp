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

enum class WorldLocationTypeMembers
{
	ID = 1,
	Y,
	X,
	Z,
	Heading,
	Zone,
};

MQ2WorldLocationType::MQ2WorldLocationType() : MQ2Type("worldlocation")
{
	ScopedTypeMember(WorldLocationTypeMembers, ID);
	ScopedTypeMember(WorldLocationTypeMembers, Y);
	ScopedTypeMember(WorldLocationTypeMembers, X);
	ScopedTypeMember(WorldLocationTypeMembers, Z);
	ScopedTypeMember(WorldLocationTypeMembers, Heading);
	ScopedTypeMember(WorldLocationTypeMembers, Zone);
}

bool MQ2WorldLocationType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2WorldLocationType::FindMember(Member);
	if (!pMember)
		return false;

	PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return false;

	uint32_t index = VarPtr.DWord;

	switch (static_cast<WorldLocationTypeMembers>(pMember->ID))
	{
	case WorldLocationTypeMembers::ID: {
		int zindex = pProfile->BoundLocations[index].ZoneBoundID;
		Dest.DWord = zindex;
		Dest.Type = pIntType;
		return true;
	}

	case WorldLocationTypeMembers::Zone: {
		Dest.Type = pZoneType;

		int zindex = pProfile->BoundLocations[index].ZoneBoundID & 0x7FFF;
		if (zindex < MAX_ZONES)
		{
			Dest.Ptr = pWorldData->ZoneArray[zindex];
		}

		if (!Dest.Ptr)
			return false;
		return true;
	}

	case WorldLocationTypeMembers::Y:
		Dest.Float = pProfile->BoundLocations[index].ZoneBoundY;
		Dest.Type = pFloatType;
		return true;

	case WorldLocationTypeMembers::X:
		Dest.Float = pProfile->BoundLocations[index].ZoneBoundX;
		Dest.Type = pFloatType;
		return true;

	case WorldLocationTypeMembers::Z:
		Dest.Float = pProfile->BoundLocations[index].ZoneBoundZ;
		Dest.Type = pFloatType;
		return true;

	case WorldLocationTypeMembers::Heading:
		Dest.Float = pProfile->BoundLocations[index].ZoneBoundHeading * 0.703125f;
		Dest.Type = pHeadingType;
		return true;

	default: break;
	};

	return false;
}

bool MQ2WorldLocationType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (PcProfile* pProfile = GetPcProfile())
	{
		int index = std::clamp(VarPtr.Int, 0, 4);

		int zindex = pProfile->BoundLocations[index].ZoneBoundID & 0x7FFF;
		if (zindex < MAX_ZONES)
		{
			if (EQZoneInfo* pList = pWorldData->ZoneArray[zindex])
			{
				strcpy_s(Destination, MAX_STRING, pList->ShortName);
				return true;
			}
		}
	}
	return false;
}

} // namespace mq::datatypes
