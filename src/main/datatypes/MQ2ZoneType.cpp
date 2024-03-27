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

enum class ZoneMembers
{
	Name = 1,
	ShortName,
	ID,
	ZoneFlags,
};

MQ2ZoneType::MQ2ZoneType() : MQ2Type("zone")
{
	ScopedTypeMember(ZoneMembers, Name);
	ScopedTypeMember(ZoneMembers, ShortName);
	ScopedTypeMember(ZoneMembers, ID);
	ScopedTypeMember(ZoneMembers, ZoneFlags);
}

bool MQ2ZoneType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	EQZoneInfo* pZone = static_cast<EQZoneInfo*>(VarPtr.Ptr);
	if (!VarPtr.Ptr)
		return false;

	MQTypeMember* pMember = MQ2ZoneType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ZoneMembers>(pMember->ID))
	{
	case ZoneMembers::Name:
		strcpy_s(DataTypeTemp, pZone->LongName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ZoneMembers::ShortName:
		strcpy_s(DataTypeTemp, pZone->ShortName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ZoneMembers::ID:
		Dest.Int = pZone->Id & 0x7FFF;
		Dest.Type = pIntType;
		return true;

	case ZoneMembers::ZoneFlags:
		Dest.UInt64 = pZone->ZoneFlags;
		Dest.Type = pInt64Type;
		return true;

	default: break;
	}

	return false;
}

bool MQ2ZoneType::ToString(MQVarPtr VarPtr, char* Destination)
{
	EQZoneInfo* pZoneInfo = static_cast<EQZoneInfo*>(VarPtr.Ptr);

	strcpy_s(Destination, MAX_STRING, pZoneInfo->LongName);
	return true;
}

bool MQ2ZoneType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type == pZoneType)
	{
		VarPtr.Ptr = Source.Ptr;
		return true;
	}

	if (Source.Type == pCurrentZoneType)
	{
		if (pLocalPC)
		{
			int zoneid = (pLocalPC->zoneId & 0x7FFF);
			if (zoneid <= MAX_ZONES)
			{
				VarPtr.Ptr = &pWorldData->ZoneArray[zoneid];
				return true;
			}
		}
	}

	return false;
}

bool MQ2ZoneType::dataZone(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
	{
		Ret.Type = pCurrentZoneType;
		return true;
	}

	if (IsNumber(szIndex))
	{
		EQZoneInfo* pZone = nullptr;

		if (int nIndex = (GetIntFromString(szIndex, 0) & 0x7FFF))
		{
			if (pLocalPC)
			{
				if ((pLocalPC->zoneId & 0x7FFF) == nIndex)
				{
					Ret.Type = pCurrentZoneType;
					return true;
				}

				if (nIndex < MAX_ZONES)
				{
					pZone = pWorldData->ZoneArray[nIndex];
					Ret.Type = pZoneType;
				}

				if (!pZone)
					return false;

				Ret.Ptr = pZone;
				return true;
			}
		}

		return false;
	}

	int nIndex = GetZoneID(szIndex);

	if (nIndex != -1)
	{
		if (pLocalPC)
		{
			if ((pLocalPC->zoneId & 0x7FFF) == nIndex)
			{
				Ret.Type = pCurrentZoneType;
			}
			else if (nIndex < MAX_ZONES)
			{
				Ret.Ptr = pWorldData->ZoneArray[nIndex];
				Ret.Type = pZoneType;
			}

			return true;
		}
	}

	return false;
}

} // namespace mq::datatypes
