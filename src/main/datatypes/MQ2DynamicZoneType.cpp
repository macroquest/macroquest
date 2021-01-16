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

bool MQ2DynamicZoneType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2DynamicZoneType::FindMember(Member);
	if (!pMember)
		return false;

	DynamicZoneMembers dataMember = static_cast<DynamicZoneMembers>(pMember->ID);
	if (!pDZMember && dataMember != LeaderFlagged)
		return false;

	switch (dataMember)
	{
	case Name:
		strcpy_s(DataTypeTemp, pDynamicZone->ExpeditionName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Members: {
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

	case LeaderFlagged:
		Dest.Set(pDynamicZone && pDynamicZone->pFirstMember && pDynamicZone->pFirstMember->bFlagged);
		Dest.Type = pBoolType;

	case MaxMembers:
		Dest.DWord = pDynamicZone->MaxPlayers;
		Dest.Type = pIntType;
		return true;

	case xMember:
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

	case Leader: {
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

	case InRaid:
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


bool MQ2DynamicZoneType::dataDynamicZone(const char* szIndex, MQTypeVar& Ret)
{
	Ret.DWord = 0;
	Ret.Type = pDynamicZoneType;
	return true;
}
