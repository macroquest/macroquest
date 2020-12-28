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
		Dest.DWord = !_stricmp(MemberName, LeaderName);
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
			Dest.DWord = pGroupMemberData->MainTank;
			return true;
		}
		return false;

	case MainAssist:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->MainAssist;
			return true;
		}
		return false;

	case MarkNpc:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->MarkNpc;
			return true;
		}
		return false;

	case MasterLooter:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->MasterLooter;
			return true;
		}
		return false;

	case Puller:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->Puller;
			return true;
		}
		return false;

	case Mercenary:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->Type == SPAWN_NPC;
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
			Dest.DWord = pGroupMemberData->Offline;
			return true;
		}
		return false;

	case Present:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->pSpawn ? 1 : 0;
			Dest.Type = pBoolType;
			return true;
		}
		return false;

	case OtherZone:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pGroupMemberData && pGroupMemberData->Offline == 0 && pGroupMemberData->pSpawn == 0)
			Dest.DWord = 1;
		return true;
	}
	return false;
}

//============================================================================
//============================================================================

enum class RaidMembers
{
	Member = 1,
	Members,
	Target,
	Leader,
	TotalLevels,
	AverageLevel,
	LootType,
	Looter,
	Looters,
	Locked,
	Invited,
	MainAssist,
	MasterLooter,
	MarkNPC,
};

enum class RaidMethods
{
};

MQ2RaidType::MQ2RaidType()
	: MQ2Type("raid")
{
	ScopedTypeMember(RaidMembers, Member);
	ScopedTypeMember(RaidMembers, Members);
	ScopedTypeMember(RaidMembers, Target);
	ScopedTypeMember(RaidMembers, Leader);
	ScopedTypeMember(RaidMembers, TotalLevels);
	ScopedTypeMember(RaidMembers, AverageLevel);
	ScopedTypeMember(RaidMembers, LootType);
	ScopedTypeMember(RaidMembers, Looter);
	ScopedTypeMember(RaidMembers, Looters);
	ScopedTypeMember(RaidMembers, Locked);
	ScopedTypeMember(RaidMembers, Invited);
	ScopedTypeMember(RaidMembers, MainAssist);
	ScopedTypeMember(RaidMembers, MasterLooter);
	ScopedTypeMember(RaidMembers, MarkNPC);
}

bool MQ2RaidType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pRaid)
		return false;

	MQTypeMember* pMember = MQ2RaidType::FindMember(Member);
	if (!pMember)
		return false;

	CHARINFO* pCharInfo = GetCharInfo();
	if (!pCharInfo)
		return false;

	switch (static_cast<RaidMembers>(pMember->ID))
	{
	case RaidMembers::Locked:
		Dest.DWord = pRaid->Locked;
		Dest.Type = pBoolType;
		return true;

	case RaidMembers::Invited:
		Dest.DWord = pRaid->Invited == 2;
		Dest.Type = pBoolType;
		return true;

	case RaidMembers::Member:
		Dest.DWord = 0;
		Dest.Type = pRaidMemberType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int Count = GetIntFromString(Index, 0);
				if (!Count || Count > pRaid->RaidMemberCount)
					return false;

				for (int nMember = 0; nMember < MAX_RAID_SIZE; nMember++)
				{
					if (pRaid->RaidMemberUsed[nMember])
					{
						Count--;
						if (!Count)
						{
							Dest.DWord = nMember + 1;
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				for (int nMember = 0; nMember < MAX_RAID_SIZE; nMember++)
				{
					if (pRaid->RaidMemberUsed[nMember] && ci_equals(pRaid->RaidMember[nMember].Name, Index))
					{
						Dest.DWord = nMember + 1;
						return true;
					}
				}
			}
		}
		return false;

	case RaidMembers::Members:
		Dest.DWord = pRaid->RaidMemberCount;
		Dest.Type = pIntType;
		return true;

	case RaidMembers::Target:
		Dest.DWord = pRaid->RaidTarget + 1;
		Dest.Type = pRaidMemberType;
		return true;

	case RaidMembers::Leader:
		Dest.DWord = 0;
		Dest.Type = pRaidMemberType;
		for (int nMember = 0; nMember < MAX_RAID_SIZE; nMember++)
		{
			if (pRaid->RaidMemberUsed[nMember] && ci_equals(pRaid->RaidMember[nMember].Name, pRaid->RaidLeaderName))
			{
				Dest.DWord = nMember + 1;
				return true;
			}
		}
		return false;

	case RaidMembers::TotalLevels:
		Dest.DWord = pRaid->TotalRaidMemberLevels;
		Dest.Type = pIntType;
		return true;

	case RaidMembers::AverageLevel:
		Dest.Float = (float)pRaid->TotalRaidMemberLevels / (float)pRaid->RaidMemberCount;
		Dest.Type = pFloatType;
		return true;

	case RaidMembers::LootType:
		Dest.DWord = pRaid->LootType;
		Dest.Type = pIntType;
		return true;

	case RaidMembers::Looters:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		for (auto& looter : pRaid->RaidLooters)
		{
			if (looter[0])
				Dest.DWord++;
		}
		return true;

	case RaidMembers::Looter:
		Dest.Type = pStringType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int Count = GetIntFromString(Index, 0);
				if (Count <= 0)
					return false;

				for (int nLooter = 0; nLooter < MAX_RAID_LOOTERS; nLooter++)
				{
					if (pRaid->RaidLooters[nLooter][0])
					{
						Count--;
						if (Count == 0)
						{
							strcpy_s(DataTypeTemp, pRaid->RaidLooters[nLooter]);
							Dest.Ptr = &DataTypeTemp[0];
							return true;
						}
					}
				}
			}
			// by name?
		}
		return false;

	case RaidMembers::MainAssist:
		Dest.DWord = 0;
		Dest.Type = pRaidMemberType;

		if (Index[0])
		{
			RaidData& rd = pCharInfo->raidData;

			if (IsNumber(Index))
			{
				// Look up Nth raid assist
				int maIndex = GetIntFromString(Index, 0);
				if (maIndex <= 0 || maIndex > MAX_RAID_ASSISTS)
					return false;

				// This matches what EQ says the RA at this index is.
				const char* raName = rd.MainAssistNames[maIndex];
				if (raName[0] == 0)
					return false;

				for (int nMember = 0; nMember < MAX_RAID_SIZE; ++nMember)
				{
					if (!pRaid->RaidMemberUsed[nMember])
						continue;
					if (pRaid->RaidMember[nMember].RaidMainAssist)
					{
						if (strcmp(raName, pRaid->RaidMember[nMember].Name) == 0)
						{
							Dest.DWord = nMember + 1;
							return true;
						}
					}
				}
			}
			else
			{
				// Return raid member index if the specified name is a raid assist.
				for (int nMember = 0; nMember < MAX_RAID_SIZE; ++nMember)
				{
					if (!pRaid->RaidMemberUsed[nMember])
						continue;
					if (!pRaid->RaidMember[nMember].RaidMainAssist)
						continue;
					if (ci_equals(pRaid->RaidMember[nMember].Name, Index))
					{
						Dest.DWord = nMember + 1;
						return true;
					}
				}
			}
		}

		// just return the first raid assist that is found.
		for (int nMember = 0; nMember < MAX_RAID_SIZE; ++nMember)
		{
			if (!pRaid->RaidMemberUsed[nMember])
				continue;
			if (pRaid->RaidMember[nMember].RaidMainAssist)
			{
				Dest.DWord = nMember + 1;
				return true;
			}
		}
		return false;

	case RaidMembers::MasterLooter:
		Dest.DWord = 0;
		Dest.Type = pRaidMemberType;
		for (int i = 0; i < 72; i++)
		{
			if (pRaid->RaidMemberUsed[i] && pRaid->RaidMember[i].MasterLooter)
			{
				Dest.DWord = i + 1;
				return true;
			}
		}
		return false;

	case RaidMembers::MarkNPC:
		Dest.DWord = 0;
		Dest.Type = pRaidMemberType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// Look up Nth raid marker
				int count = GetIntFromString(Index, 0);

				if (count <= 0 || count > MAX_RAID_MARKERS)
					return false;

				for (int nMember = 0; nMember < MAX_RAID_SIZE; ++nMember)
				{
					if (!pRaid->RaidMemberUsed[nMember])
						continue;
					if (pRaid->RaidMember[nMember].RaidMarker)
					{
						if (--count == 0)
						{
							Dest.DWord = nMember + 1;
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				for (int nMember = 0; nMember < MAX_RAID_SIZE; nMember++)
				{
					if (!pRaid->RaidMemberUsed[nMember])
						continue;
					if (pRaid->RaidMember[nMember].RaidMarker)
					{
						if (ci_equals(pRaid->RaidMember[nMember].Name, Index))
						{
							Dest.DWord = nMember + 1;
							return true;
						}
					}
				}
			}
		}
		else
		{
			// just return the first raid marker that is found.
			for (int nMember = 0; nMember < MAX_RAID_SIZE; ++nMember)
			{
				if (!pRaid->RaidMemberUsed[nMember])
					continue;
				if (pRaid->RaidMember[nMember].RaidMarker)
				{
					Dest.DWord = nMember + 1;
					return true;
				}
			}
		}

		return false;
	}
	return false;
}

bool MQ2RaidType::ToString(MQVarPtr VarPtr, char* Destination)
{
	return false;
}

//============================================================================
//============================================================================


bool MQ2RaidMemberType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	int nRaidMember = VarPtr.Int - 1;
	if (nRaidMember < 0 || nRaidMember >= MAX_RAID_SIZE)
		return false;

	if (!pRaid->RaidMemberUsed[nRaidMember])
		return false;

	EQRAIDMEMBER* pRaidMember = &pRaid->RaidMember[nRaidMember];
	MQTypeMember* pMember = MQ2RaidMemberType::FindMember(Member);

	if (!pMember)
	{
		SPAWNINFO* pSpawn = (SPAWNINFO*)GetSpawnByName(pRaidMember->Name);
		if (!pSpawn)
			return false;

		MQVarPtr data;
		data.Ptr = pSpawn;
		return pSpawnType->GetMember(data, Member, Index, Dest);
	}

	switch (static_cast<RaidMemberMembers>(pMember->ID))
	{
	case Name:
		strcpy_s(DataTypeTemp, pRaidMember->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Group:
		Dest.DWord = pRaidMember->GroupNumber + 1;
		Dest.Type = pIntType;
		return true;

	case GroupLeader:
		Dest.DWord = pRaidMember->GroupLeader;
		Dest.Type = pBoolType;
		return true;

	case RaidLeader:
		Dest.DWord = pRaidMember->RaidLeader;
		Dest.Type = pBoolType;
		return true;

	case Looter:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (pRaidMember->RaidLeader)
		{
			Dest.DWord = 1;
			return true;
		}

		if (pRaid->LootType == RaidLootLeaderAndGroupLeader)
		{
			Dest.DWord = pRaidMember->GroupLeader;
			return true;
		}

		if (pRaid->LootType == RaidLootAssignments)
		{
			for (int index = 0; index < MAX_RAID_LOOTERS; index++)
			{
				if (ci_equals(pRaid->RaidLooters[index], pRaidMember->Name))
				{
					Dest.DWord = 1;
					return true;
				}
			}
		}
		return true;

	case Spawn:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = (SPAWNINFO*)GetSpawnByName(pRaidMember->Name))
		{
			return true;
		}
		return false;

	case Level:
		Dest.DWord = pRaidMember->nLevel;
		Dest.Type = pIntType;
		return true;

	case Class:
		Dest.DWord = pRaidMember->nClass;
		Dest.Type = pClassType;
		return true;

	default: break;
	}

	return false;
}

} // namespace mq::datatypes
