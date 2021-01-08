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
				const char* raName = rd.MainAssistNames[maIndex - 1];
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

} // namespace mq::datatypes
