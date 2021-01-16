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

enum class RaidMemberMembers
{
	Name = 1,
	Group,
	GroupLeader,
	RaidLeader,
	Spawn,
	Looter,
	Class,
	Level,
};

MQ2RaidMemberType::MQ2RaidMemberType() : MQ2Type("raidmember")
{
	ScopedTypeMember(RaidMemberMembers, Name);
	ScopedTypeMember(RaidMemberMembers, Group);
	ScopedTypeMember(RaidMemberMembers, GroupLeader);
	ScopedTypeMember(RaidMemberMembers, RaidLeader);
	ScopedTypeMember(RaidMemberMembers, Spawn);
	ScopedTypeMember(RaidMemberMembers, Looter);
	ScopedTypeMember(RaidMemberMembers, Class);
	ScopedTypeMember(RaidMemberMembers, Level);
}

bool MQ2RaidMemberType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	int nRaidMember = VarPtr.Int - 1;
	if (nRaidMember < 0 || nRaidMember >= MAX_RAID_SIZE)
		return false;

	if (!pRaid->RaidMemberUsed[nRaidMember])
		return false;

	RaidPlayer* pRaidMember = &pRaid->RaidMember[nRaidMember];
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
	case RaidMemberMembers::Name:
		strcpy_s(DataTypeTemp, pRaidMember->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case RaidMemberMembers::Group:
		Dest.DWord = pRaidMember->GroupNumber + 1;
		Dest.Type = pIntType;
		return true;

	case RaidMemberMembers::GroupLeader:
		Dest.Set(pRaidMember->GroupLeader);
		Dest.Type = pBoolType;
		return true;

	case RaidMemberMembers::RaidLeader:
		Dest.Set(pRaidMember->RaidLeader);
		Dest.Type = pBoolType;
		return true;

	case RaidMemberMembers::Looter:
		Dest.Set(false);
		Dest.Type = pBoolType;

		if (pRaidMember->RaidLeader)
		{
			Dest.Set(true);
			return true;
		}

		if (pRaid->LootType == RaidLootLeaderAndGroupLeader)
		{
			Dest.Set(pRaidMember->GroupLeader);
			return true;
		}

		if (pRaid->LootType == RaidLootAssignments)
		{
			for (auto& RaidLooter : pRaid->RaidLooters)
			{
				if (ci_equals(RaidLooter, pRaidMember->Name))
				{
					Dest.Set(true);
					return true;
				}
			}
		}
		return true;

	case RaidMemberMembers::Spawn:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = (SPAWNINFO*)GetSpawnByName(pRaidMember->Name))
		{
			return true;
		}
		return false;

	case RaidMemberMembers::Level:
		Dest.DWord = pRaidMember->nLevel;
		Dest.Type = pIntType;
		return true;

	case RaidMemberMembers::Class:
		Dest.DWord = pRaidMember->nClass;
		Dest.Type = pClassType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2RaidMemberType::ToString(MQVarPtr VarPtr, char* Destination)
{
	DWORD nRaidMember = VarPtr.DWord - 1;
	if (VarPtr.DWord >= 72)
		return false;
	if (!pRaid->RaidMemberUsed[nRaidMember])
		return false;
	RaidPlayer* pRaidMember = &pRaid->RaidMember[nRaidMember];
	strcpy_s(Destination, MAX_STRING, pRaidMember->Name);
	return true;
}

bool MQ2RaidMemberType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	if (Source.Type != pRaidMemberType)
		return false;
	VarPtr.Ptr = Source.Ptr;
	return true;
}

} // namespace mq::datatypes
