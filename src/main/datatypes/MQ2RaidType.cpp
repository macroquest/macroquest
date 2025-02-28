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
	if (!pLocalPC)
		return false;

	MQTypeMember* pMember = MQ2RaidType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<RaidMembers>(pMember->ID))
	{
	case RaidMembers::Locked:
		Dest.Set(pRaid->Locked);
		Dest.Type = pBoolType;
		return true;

	case RaidMembers::Invited:
		Dest.Set(pRaid->Invited == 2);
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
					if (pRaid->locations[nMember])
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
					if (pRaid->locations[nMember] && ci_equals(pRaid->raidMembers[nMember].Name, Index))
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
			if (pRaid->locations[nMember] && ci_equals(pRaid->raidMembers[nMember].Name, pRaid->RaidLeaderName))
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
			if (IsNumber(Index))
			{
				// Look up Nth raid assist
				int maIndex = GetIntFromString(Index, 0);
				if (maIndex <= 0 || maIndex > MAX_RAID_ASSISTS)
					return false;

#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_COTF)
				// This matches what EQ says the RA at this index is.
				const char* raName = pLocalPC->raidData.MainAssistNames[maIndex - 1];
		
				if (raName[0] == 0)
					return false;

				for (int nMember = 0; nMember < MAX_RAID_SIZE; ++nMember)
				{
					if (!pRaid->locations[nMember])
						continue;
					if (pRaid->raidMembers[nMember].RaidMainAssist)
					{
						if (strcmp(raName, pRaid->raidMembers[nMember].Name) == 0)
						{
							Dest.DWord = nMember + 1;
							return true;
						}
					}
				}
#endif
			}
			else
			{
				// Return raid member index if the specified name is a raid assist.
				for (int nMember = 0; nMember < MAX_RAID_SIZE; ++nMember)
				{
					if (!pRaid->locations[nMember])
						continue;
					if (!pRaid->raidMembers[nMember].RaidMainAssist)
						continue;
					if (ci_equals(pRaid->raidMembers[nMember].Name, Index))
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
			if (!pRaid->locations[nMember])
				continue;
			if (pRaid->raidMembers[nMember].RaidMainAssist)
			{
				Dest.DWord = nMember + 1;
				return true;
			}
		}
		return false;

	case RaidMembers::MasterLooter:
		Dest.DWord = 0;
		Dest.Type = pRaidMemberType;
		for (int i = 0; i < MAX_RAID_SIZE; i++)
		{
			if (pRaid->locations[i] && pRaid->raidMembers[i].MasterLooter)
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
					if (!pRaid->locations[nMember])
						continue;
					if (pRaid->raidMembers[nMember].RaidMarker)
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
					if (!pRaid->locations[nMember])
						continue;
					if (pRaid->raidMembers[nMember].RaidMarker)
					{
						if (ci_equals(pRaid->raidMembers[nMember].Name, Index))
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
				if (!pRaid->locations[nMember])
					continue;
				if (pRaid->raidMembers[nMember].RaidMarker)
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

bool MQ2RaidType::dataRaid(const char* szIndex, MQTypeVar& Ret)
{
	Ret.DWord = 0;
	Ret.Type = pRaidType;
	return true;
}

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

	if (!pRaid->locations[nRaidMember])
		return false;

	RaidMember& raidMember = pRaid->raidMembers[nRaidMember];
	MQTypeMember* pMember = MQ2RaidMemberType::FindMember(Member);

	if (!pMember)
	{
		return pSpawnType->GetMember(GetSpawnByName(raidMember.Name), Member, Index, Dest);
	}

	switch (static_cast<RaidMemberMembers>(pMember->ID))
	{
	case RaidMemberMembers::Name:
		strcpy_s(DataTypeTemp, raidMember.Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case RaidMemberMembers::Group:
		Dest.DWord = raidMember.GroupNumber + 1;
		Dest.Type = pIntType;
		return true;

	case RaidMemberMembers::GroupLeader:
		Dest.Set(raidMember.GroupLeader);
		Dest.Type = pBoolType;
		return true;

	case RaidMemberMembers::RaidLeader:
		Dest.Set(raidMember.RaidLeader);
		Dest.Type = pBoolType;
		return true;

	case RaidMemberMembers::Looter:
		Dest.Set(false);
		Dest.Type = pBoolType;

		if (raidMember.RaidLeader)
		{
			Dest.Set(true);
			return true;
		}

		if (pRaid->LootType == RaidLootLeaderAndGroupLeader)
		{
			Dest.Set(raidMember.GroupLeader);
			return true;
		}

		if (pRaid->LootType == RaidLootAssignments)
		{
			for (auto& RaidLooter : pRaid->RaidLooters)
			{
				if (ci_equals(RaidLooter, raidMember.Name))
				{
					Dest.Set(true);
					return true;
				}
			}
		}
		return true;

	case RaidMemberMembers::Spawn:
		Dest = pSpawnType->MakeTypeVar(GetSpawnByName(raidMember.Name));
		return true;

	case RaidMemberMembers::Level:
		Dest.DWord = raidMember.nLevel;
		Dest.Type = pIntType;
		return true;

	case RaidMemberMembers::Class:
		Dest.DWord = raidMember.nClass;
		Dest.Type = pClassType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2RaidMemberType::ToString(MQVarPtr VarPtr, char* Destination)
{
	int nRaidMember = VarPtr.Int - 1;
	if (nRaidMember >= MAX_RAID_SIZE || nRaidMember < 0)
		return false;
	if (!pRaid->locations[nRaidMember])
		return false;

	strcpy_s(Destination, MAX_STRING, pRaid->raidMembers[nRaidMember].Name);
	return true;
}

bool MQ2RaidMemberType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pRaidMemberType)
		return false;

	VarPtr = Source;
	return true;
}

bool MQ2RaidMemberType::Downcast(const MQVarPtr& fromVar, MQVarPtr& toVar, MQ2Type* toType)
{
	if (toType == pSpawnType)
	{
		int nRaidMember = fromVar.Int - 1;
		if (nRaidMember >= MAX_RAID_SIZE || nRaidMember < 0)
			return false;

		if (!pRaid->locations[nRaidMember])
			return false;

		toVar = pSpawnType->MakeVarPtr(GetSpawnByName(pRaid->raidMembers[nRaidMember].Name));
		return true;
	}

	return false;
}

} // namespace mq::datatypes
