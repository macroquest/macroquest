/*
 * MacroQuest: The extension platform for EverQuest
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

namespace mq::datatypes {

enum class DynamicZoneMembers
{
	Name = 1,
	Members,
	MaxMembers,
	Member,
	Leader,
	InRaid,
	LeaderFlagged,
};

MQ2DynamicZoneType::MQ2DynamicZoneType() : MQ2Type("dynamiczone")
{
	ScopedTypeMember(DynamicZoneMembers, Name);
	ScopedTypeMember(DynamicZoneMembers, Members);
	ScopedTypeMember(DynamicZoneMembers, MaxMembers);
	ScopedTypeMember(DynamicZoneMembers, Member);
	ScopedTypeMember(DynamicZoneMembers, Leader);
	ScopedTypeMember(DynamicZoneMembers, InRaid);
	ScopedTypeMember(DynamicZoneMembers, LeaderFlagged);
}


bool MQ2DynamicZoneType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2DynamicZoneType::FindMember(Member);
	if (!pMember)
		return false;

	DynamicZoneMembers dataMember = static_cast<DynamicZoneMembers>(pMember->ID);
	if (!pDZMember && dataMember != DynamicZoneMembers::LeaderFlagged)
		return false;

	switch (dataMember)
	{
	case DynamicZoneMembers::Name:
		strcpy_s(DataTypeTemp, pDynamicZone->ExpeditionName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case DynamicZoneMembers::Members: {
		Dest.DWord = 0;
		Dest.Type = pIntType;
		DynamicZonePlayerInfo* pDynamicZoneMember = pDynamicZone->pFirstMember;

		while (pDynamicZoneMember)
		{
			Dest.DWord++;
			pDynamicZoneMember = pDynamicZoneMember->pNext;
		}
		return true;
	}

	case DynamicZoneMembers::LeaderFlagged:
		Dest.Set(pDynamicZone && pDynamicZone->pFirstMember && pDynamicZone->pFirstMember->bFlagged);
		Dest.Type = pBoolType;

	case DynamicZoneMembers::MaxMembers:
		Dest.DWord = pDynamicZone->MaxPlayers;
		Dest.Type = pIntType;
		return true;

	case DynamicZoneMembers::Member:
		Dest.Type = pDZMemberType;
		if (Index[0])
		{
			DynamicZonePlayerInfo* pDynamicZoneMember = pDynamicZone->pFirstMember;
			if (IsNumber(Index))
			{
				int Count = GetIntFromString(Index, 0) - 1;
				if (Count < 0 || Count >= pDynamicZone->MaxPlayers)
					return false;

				for (int i = 0; pDynamicZoneMember != nullptr; i++)
				{
					if (i == Count)
					{
						Dest.Ptr = pDynamicZoneMember;
						return true;
					}
					pDynamicZoneMember = pDynamicZoneMember->pNext;
				}
			}
			else
			{
				while (pDynamicZoneMember)
				{
					if (ci_equals(pDynamicZoneMember->Name, Index))
					{
						Dest.Ptr = pDynamicZoneMember;
						return true;
					}
					pDynamicZoneMember = pDynamicZoneMember->pNext;
				}
			}
		}
		return false;

	case DynamicZoneMembers::Leader: {
		Dest.Type = pDZMemberType;
		DynamicZonePlayerInfo* pDynamicZoneMember = pDynamicZone->pMemberList;

		for (int i = 0; i < pDynamicZone->MaxPlayers && pDynamicZoneMember; i++)
		{
			if (!strcmp(pDynamicZoneMember->Name, (char*)instExpeditionLeader))
			{
				Dest.Ptr = pDynamicZoneMember;
				return true;
			}
			pDynamicZoneMember = pDynamicZoneMember->pNext;
		}
		return false;
	}

	case DynamicZoneMembers::InRaid:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (pDynamicZone && pDynamicZone->LeaderName[0])
		{
			Dest.Set(true);
		}
		return true;

	default: break;
	}

	return false;
}

bool MQ2DynamicZoneType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (pDZMember)
	{
		strcpy_s(Destination, MAX_STRING, pDynamicZone->DZName);
		return true;
	}
	return false;
}

bool MQ2DynamicZoneType::dataDynamicZone(const char* szIndex, MQTypeVar& Ret)
{
	Ret.DWord = 0;
	Ret.Type = pDynamicZoneType;
	return true;
}

enum class DZMemberTypeMembers
{
	Name = 1,
	Status,
	Flagged,
};

MQ2DZMemberType::MQ2DZMemberType() : MQ2Type("dzmember")
{
	ScopedTypeMember(DZMemberTypeMembers, Name);
	ScopedTypeMember(DZMemberTypeMembers, Status);
	ScopedTypeMember(DZMemberTypeMembers, Flagged);
}

bool MQ2DZMemberType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	auto* pDynamicZoneMember = reinterpret_cast<DynamicZonePlayerInfo*>(VarPtr.Ptr);
	if (pDynamicZoneMember)
		return false;

	MQTypeMember* pMember = MQ2DZMemberType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<DZMemberTypeMembers>(pMember->ID))
	{
	case DZMemberTypeMembers::Name:
		strcpy_s(DataTypeTemp, pDynamicZoneMember->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case DZMemberTypeMembers::Flagged:
		Dest.Set(pDynamicZoneMember->bFlagged);
		Dest.Type = pBoolType;

	case DZMemberTypeMembers::Status:
		strcpy_s(DataTypeTemp, "Unknown");
		switch (pDynamicZoneMember->Status)
		{
		case 0:
			strcpy_s(DataTypeTemp, "Unknown");
			break;
		case 1:
			strcpy_s(DataTypeTemp, "Online");
			break;
		case 2:
			strcpy_s(DataTypeTemp, "Offline");
			break;
		case 3:
			strcpy_s(DataTypeTemp, "In Dynamic Zone");
			break;
		case 4:
			strcpy_s(DataTypeTemp, "Link Dead");
			break;
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2DZMemberType::ToString(MQVarPtr VarPtr, char* Destination)
{
	strcpy_s(Destination, MAX_STRING, reinterpret_cast<DynamicZonePlayerInfo*>(VarPtr.Ptr)->Name);
	return true;
}

} // namespace mq::datatypes
