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
		Dest.Set(pRaidMember->GroupLeader);
		Dest.Type = pBoolType;
		return true;

	case RaidLeader:
		Dest.Set(pRaidMember->RaidLeader);
		Dest.Type = pBoolType;
		return true;

	case Looter:
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
			for (int index = 0; index < MAX_RAID_LOOTERS; index++)
			{
				if (ci_equals(pRaid->RaidLooters[index], pRaidMember->Name))
				{
					Dest.Set(true);
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
