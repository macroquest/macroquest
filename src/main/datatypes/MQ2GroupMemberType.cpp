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

namespace mq::datatypes {

bool MQ2GroupMemberType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (int index = VarPtr.Int)
	{
		if (index > 5)
			return false;

		CHARINFO* pChar = GetCharInfo();
		if (!pChar->pGroupInfo) return false;

		// members 1 to 5. Count to the nth member.
		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			GROUPMEMBER* pMember = pChar->pGroupInfo->pMember[i];
			if (pMember)
			{
				index--;
				if (index == 0)
				{
					char Name[MAX_STRING] = { 0 };
					strcpy_s(Name, pMember->Name.c_str());

					strcpy_s(Destination, MAX_STRING, CleanupName(Name, MAX_STRING, false, false));
					return true;
				}
			}
		}
	}
	else
	{
		strcpy_s(Destination, MAX_STRING, GetCharInfo()->pSpawn->DisplayedName);
		return true;
	}

	return false;
}

bool MQ2GroupMemberType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	CHARINFO* pChar = GetCharInfo();
	if (!pChar || !pChar->pGroupInfo)
		return false;

	SPAWNINFO* pGroupMember = nullptr;
	GROUPMEMBER* pGroupMemberData = nullptr;

	char MemberName[MAX_STRING] = { 0 };
	char LeaderName[MAX_STRING] = { 0 };

	int nMember = VarPtr.Int;

	if (int index = nMember)
	{
		if (index >= MAX_GROUP_SIZE)
			return false;

		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			GROUPMEMBER* pMember = pChar->pGroupInfo->pMember[i];

			if (pMember)
			{
				index--;
				if (index == 0)
				{
					strcpy_s(MemberName, pMember->Name.c_str());

					if (pMember->pSpawn)
					{
						pGroupMember = pMember->pSpawn;
					}

					pGroupMemberData = pMember;
					break;
				}
			}
		}
		if (!MemberName)
			return false;
	}
	else
	{
		if (pGroupMember = pChar->pSpawn)
		{
			strcpy_s(MemberName, pGroupMember->Name);
		}

		pGroupMemberData = pChar->pGroupInfo->pMember[0];
	}

	MQTypeMember* pMember = MQ2GroupMemberType::FindMember(Member);
	if (!pMember)
	{
		if (!pGroupMember)
			return false;

		MQVarPtr data;
		data.Ptr = pGroupMember;

		return pSpawnType->GetMember(data, Member, Index, Dest);
	}

	switch (static_cast<GroupMemberMembers>(pMember->ID))
	{
	case Address:
		Dest.DWord = (DWORD)pGroupMemberData;
		Dest.Type = pIntType;
		return true;

	case Name:
		strcpy_s(DataTypeTemp, CleanupName(MemberName, sizeof(MemberName), FALSE, FALSE));
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case Leader:
		Dest.Type = pBoolType;
		if (!pChar->pGroupInfo->pLeader)
			return false;

		strcpy_s(LeaderName, pChar->pGroupInfo->pLeader->Name.c_str());
		Dest.Set(!_stricmp(MemberName, LeaderName));
		return true;

	case Spawn:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = pGroupMember)
		{
			return true;
		}
		return false;

	case Level:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pGroupMember)
		{
			Dest.DWord = pGroupMember->Level;
			return true;
		}
		else if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->Level;
			return true;
		}
		return false;

	case MainTank:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.Set(pGroupMemberData->MainTank != 0);
			return true;
		}
		return false;

	case MainAssist:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.Set(pGroupMemberData->MainAssist != 0);
			return true;
		}
		return false;

	case MarkNpc:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.Set(pGroupMemberData->MarkNpc != 0);
			return true;
		}
		return false;

	case MasterLooter:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.Set(pGroupMemberData->MasterLooter != 0);
			return true;
		}
		return false;

	case Puller:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.Set(pGroupMemberData->Puller != 0);
			return true;
		}
		return false;

	case Mercenary:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.Set(pGroupMemberData->Type == SPAWN_NPC);
			return true;
		}
		return false;

	case PctAggro:
		Dest.Type = pIntType;
		if (GROUPAGGRO* pAggrp = (GROUPAGGRO*)EQADDR_GROUPAGGRO)
		{
			if (nMember == 0) // Player is always nMember 0 but in the GroupMemberAggro struct its always 5..
				Dest.DWord = pAggrp->GroupMemberAggro[5];
			else
				Dest.DWord = pAggrp->GroupMemberAggro[nMember - 1];
			return true;
		}
		return false;

	case xIndex:
		Dest.DWord = nMember;
		Dest.Type = pIntType;
		return true;

	case Offline:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.Set(pGroupMemberData->Offline != 0);
			return true;
		}
		return false;

	case Present:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.Set(pGroupMemberData->pSpawn != nullptr);
			Dest.Type = pBoolType;
			return true;
		}
		return false;

	case OtherZone:
		Dest.Type = pBoolType;
		Dest.Set(pGroupMemberData && pGroupMemberData->Offline == 0 && pGroupMemberData->pSpawn == 0);
		return true;
	}
	return false;
}

} // namespace mq::datatypes
