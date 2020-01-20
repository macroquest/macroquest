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

bool MQ2CurrentZoneType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	ZONEINFO* pCurrentZone = reinterpret_cast<ZONEINFO*>(pZoneInfo);

	MQTypeMember* pMember = MQ2CurrentZoneType::FindMember(Member);
	if (!pMember)
	{
		int zid = pCurrentZone->ZoneID & 0x7FFF;
		if (zid < MAX_ZONES)
		{
			if (ZONELIST* pZList = ((PWORLDDATA)pWorldData)->ZoneArray[zid])
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
	case Address:
		Dest.DWord = (uint32_t)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case ID:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (CHARINFO* pChar = GetCharInfo())
		{
			Dest.Int = (pChar->zoneId & 0x7FFF);
			Dest.Type = pIntType;
			return true;
		}
		return false;

	case Name:
		strcpy_s(DataTypeTemp, pCurrentZone->LongName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ShortName:
		strcpy_s(DataTypeTemp, pCurrentZone->ShortName);
		Dest.Ptr = &DataTypeTemp;
		Dest.Type = pStringType;
		return true;

	case Type:
		Dest.DWord = pCurrentZone->OutDoor;
		Dest.Type = pIntType;
		return true;

	case Gravity:
		Dest.Float = pCurrentZone->ZoneGravity;
		Dest.Type = pFloatType;
		return true;

	case SkyType:
		Dest.DWord = pCurrentZone->SkyType;
		Dest.Type = pIntType;
		return true;

	case MinClip:
		Dest.Float = pCurrentZone->MinClip;
		Dest.Type = pFloatType;
		return true;

	case MaxClip:
		Dest.Float = pCurrentZone->MaxClip;
		Dest.Type = pFloatType;
		return true;

	case ZoneType:
		Dest.DWord = (*EQADDR_ZONETYPE);
		Dest.Type = pIntType;
		return true;

	case Dungeon:
	case Indoor:
		Dest.DWord = indoor;
		Dest.Type = pBoolType;
		return true;

	case Outdoor:
		Dest.DWord = outdoor;
		Dest.Type = pBoolType;
		return true;

	case NoBind:
		Dest.DWord = !bindable;
		Dest.Type = pBoolType;
		return true;

	default: break;
	}

	return false;
}

