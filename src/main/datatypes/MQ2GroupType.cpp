/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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

enum class GroupMembers
{
	Member = 1,
	Members,
	Leader,
	GroupSize,
	MainTank,
	MainAssist,
	Puller,
	MarkNpc,
	MasterLooter,
	AnyoneMissing,
	Present,
	MercenaryCount,
	TankMercCount,
	HealerMercCount,
	MeleeMercCount,
	CasterMercCount,
	MouseOver,
	AvgHPs,
	Injured,
	Cleric,
};

MQ2GroupType::MQ2GroupType() : MQ2Type("group")
{
	ScopedTypeMember(GroupMembers, Member);
	ScopedTypeMember(GroupMembers, Members);
	ScopedTypeMember(GroupMembers, Leader);
	ScopedTypeMember(GroupMembers, GroupSize);
	ScopedTypeMember(GroupMembers, MainTank);
	ScopedTypeMember(GroupMembers, MainAssist);
	ScopedTypeMember(GroupMembers, Puller);
	ScopedTypeMember(GroupMembers, MarkNpc);
	ScopedTypeMember(GroupMembers, MasterLooter);
	ScopedTypeMember(GroupMembers, AnyoneMissing);
	ScopedTypeMember(GroupMembers, Present);
	ScopedTypeMember(GroupMembers, MercenaryCount);
	ScopedTypeMember(GroupMembers, TankMercCount);
	ScopedTypeMember(GroupMembers, HealerMercCount);
	ScopedTypeMember(GroupMembers, MeleeMercCount);
	ScopedTypeMember(GroupMembers, CasterMercCount);
	ScopedTypeMember(GroupMembers, MouseOver);
	ScopedTypeMember(GroupMembers, AvgHPs);
	ScopedTypeMember(GroupMembers, Injured);
	ScopedTypeMember(GroupMembers, Cleric);
}

bool MQ2GroupType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (!pCharData || !pCharData->Group) return false;

	int nMembers = pCharData->Group->GetNumberOfMembersExcludingSelf();

	_itoa_s(nMembers, Destination, MAX_STRING, 10);
	return true;
}

bool MQ2GroupType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2GroupType::FindMember(Member);
	CHARINFO* pChar = GetCharInfo();

	if (!pMember || !pCharData || !pChar->pSpawn || !pCharData->Group)
		return false;

	switch (static_cast<GroupMembers>(pMember->ID))
	{
	case GroupMembers::Member:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;
		if (!Index[0])
			return false;
		if (IsNumber(Index))
		{
			// by number
			Dest.DWord = GetIntFromString(Index, 0);
			return true;
		}

		// by name
		Dest.DWord = 0;
		if (ci_equals(pChar->pSpawn->Name, Index))
		{
			Dest.DWord = 0;
			return true;
		}

		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			if (CGroupMember* pMember = pCharData->Group->GetGroupMember(i))
			{
				Dest.DWord++;
				char Name[MAX_STRING] = { 0 };
				strcpy_s(Name, pMember->GetName());

				CleanupName(Name, sizeof(Name), false, false); // we do this to fix the mercenaryname bug

				if (Index[0] != 0 && ci_equals(Name, Index))
				{
					return true;
				}
			}
		}
		return false;

	case GroupMembers::Members:
		Dest.DWord = pCharData->Group->GetNumberOfMembersExcludingSelf();
		Dest.Type = pIntType;
		return true;

	case GroupMembers::Leader: {
		Dest.Type = pGroupMemberType;

		CGroupMember* pLeader = pCharData->Group->GetGroupLeader();
		if (!pLeader)
			return false;

		Dest.DWord = pCharData->Group->GetGroupMemberIndex(pLeader);
		return true;
	}

	case GroupMembers::GroupSize:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			if (pCharData->Group->GetGroupMember(i))
				Dest.DWord++;
		}

		if (Dest.DWord)
			Dest.DWord++;
		return true;

	case GroupMembers::MainTank:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;

		if (CGroupMember* pMember = pCharData->Group->GetGroupMemberByRole(GroupRoleTank))
		{
			Dest.DWord = pCharData->Group->GetGroupMemberIndex(pMember);
			return true;
		}
		return false;

	case GroupMembers::MainAssist:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;

		if (CGroupMember* pMember = pCharData->Group->GetGroupMemberByRole(GroupRoleAssist))
		{
			Dest.DWord = pCharData->Group->GetGroupMemberIndex(pMember);
			return true;
		}
		return false;

	case GroupMembers::Puller:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;

		if (CGroupMember* pMember = pCharData->Group->GetGroupMemberByRole(GroupRolePuller))
		{
			Dest.DWord = pCharData->Group->GetGroupMemberIndex(pMember);
			return true;
		}
		return false;

	case GroupMembers::MarkNpc:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;

		if (CGroupMember* pMember = pCharData->Group->GetGroupMemberByRole(GroupRoleMarkNPC))
		{
			Dest.DWord = pCharData->Group->GetGroupMemberIndex(pMember);
			return true;
		}
		return false;

	case GroupMembers::MasterLooter:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;

		if (CGroupMember* pMember = pCharData->Group->GetGroupMemberByRole(GroupRoleMasterLooter))
		{
			Dest.DWord = pCharData->Group->GetGroupMemberIndex(pMember);
			return true;
		}
		return false;

	case GroupMembers::AnyoneMissing:
		Dest.Set(false);
		Dest.Type = pBoolType;

		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			CGroupMember* pMember = pCharData->Group->GetGroupMember(i);

			if (pMember
				&& (pMember->IsOffline()
					|| (!pMember->IsOffline()
						&& pMember->GetPlayer() == nullptr)
					|| (pMember->GetPlayer()
						&& pMember->GetPlayer()->Type == SPAWN_CORPSE)))
			{
				Dest.Set(true);
				break;
			}
		}
		return true;

	case GroupMembers::Present:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			CGroupMember* pMember = pCharData->Group->GetGroupMember(i);

			// TODO: GroupMembers: pMember has a type field as well
			if (pMember
				&& pMember->GetPlayer()
				&& pMember->GetPlayer()->Type != SPAWN_CORPSE)
			{
				Dest.DWord++;
			}
		}
		return true;

	case GroupMembers::MercenaryCount:
		Dest.DWord = GetGroupMercenaryCount(AllClassesMASK);
		Dest.Type = pIntType;
		return true;

	case GroupMembers::TankMercCount:
		Dest.DWord = GetGroupMercenaryCount(WarriorMASK);
		Dest.Type = pIntType;
		return true;

	case GroupMembers::HealerMercCount:
		Dest.DWord = GetGroupMercenaryCount(ClericMASK);
		Dest.Type = pIntType;
		return true;

	case GroupMembers::MeleeMercCount:
		Dest.DWord = GetGroupMercenaryCount(RogueMASK);
		Dest.Type = pIntType;
		return true;

	case GroupMembers::CasterMercCount:
		Dest.DWord = GetGroupMercenaryCount(WizardMASK);
		Dest.Type = pIntType;
		return true;

	case GroupMembers::AvgHPs:
	{
		Dest.DWord = 100;
		Dest.Type = pIntType;

		int nummembers = 1;
		int64_t hps = 0;

		if (pChar->pSpawn && pChar->pSpawn->HPCurrent && pChar->pSpawn->HPMax)
		{
			hps = (pChar->pSpawn->HPCurrent / pChar->pSpawn->HPMax) * 100;
		}

		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			CGroupMember* pMember = pCharData->Group->GetGroupMember(i);

			if (pMember
				&& pMember->GetPlayer()
				&& pMember->GetPlayer()->Type != SPAWN_CORPSE)
			{
				hps += pMember->GetPlayer()->HPCurrent;
				nummembers++;
			}
		}

		if (hps != 0 && nummembers != 0)
		{
			Dest.Int64 = hps / nummembers;
		}
		return true;
	}

	case GroupMembers::Injured:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (int threshold = GetIntFromString(Index, 0))
		{
			int64_t hps = 0;
			for (int i = 0; i < MAX_GROUP_SIZE; i++)
			{
				CGroupMember* pMember = pCharData->Group->GetGroupMember(i);

				if (pMember
					&& pMember->GetPlayer()
					&& pMember->GetPlayer()->Type != SPAWN_CORPSE
					&& !pMember->IsOffline())
				{
					if (i == 0)
					{
						if (pMember->GetPlayer()->HPCurrent
							&& pMember->GetPlayer()->HPMax)
						{
							float fhpc = (float)pMember->GetPlayer()->HPCurrent;
							float fhpm = (float)pMember->GetPlayer()->HPMax;
							hps = (int64_t)(fhpc * 100 / fhpm);
						}
					}
					else
					{
						hps = pMember->GetPlayer()->HPCurrent;
					}

					if (hps > 0 && hps < threshold)
					{
						Dest.DWord++;
					}
				}
			}

		}
		return true;

	case GroupMembers::Cleric:
		for (auto& member : *pCharData->Group)
		{
			if (member
				&& member->Type == EQP_PC
				&& member->pSpawn
				&& member->pSpawn->GetClass() == Cleric)
			{
				Dest = pSpawnType->MakeTypeVar(member->pSpawn);
				return true;
			}
		}
		return false;

	case GroupMembers::MouseOver:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;

		if (pWndMgr)
		{
			if (CXWnd* pWnd = pWndMgr->LastMouseOver)
			{
				if (CXMLData* pXMLData = pWnd->GetXMLData())
				{
					CXStr Str = pXMLData->Name;
					if (ci_find_substr(pXMLData->Name, "GW_Gauge") == 0)
					{
						// ok they are actually hovering a groupmember, but which one?
						std::string_view digit{ pXMLData->Name };
						digit = digit.substr(8);

						if (digit.length() > 0)
						{
							// GW_Gauge1 -> GWGauge5
							int i = digit[0] - '0';
							if (i > 0 && i < MAX_GROUP_SIZE && pCharData->Group->GetGroupMember(i))
							{
								Dest.DWord = i;
								return true;
							}
						}
					}
					else if (ci_find_substr(pXMLData->Name, "Player_HP") == 0)
					{
						// ok they are actually hovering myself
						Dest.DWord = 0;
						return true;
					}
				}
			}
		}
		return false;
	}
	return false;
}

bool MQ2GroupType::dataGroup(const char* szIndex, MQTypeVar& Ret)
{
	Ret.DWord = 1;
	Ret.Type = pGroupType;
	return true;
}

enum class GroupMemberMembers
{
	Name = 1,
	Leader,
	Spawn,
	Level,
	MainTank,
	MainAssist,
	Puller,
	MarkNpc,
	MasterLooter,
	Mercenary,
	PctAggro,
	Index,
	Offline,
	OtherZone,
	Present,
};

MQ2GroupMemberType::MQ2GroupMemberType() : MQ2Type("groupmember")
{
	ScopedTypeMember(GroupMemberMembers, Name);
	ScopedTypeMember(GroupMemberMembers, Leader);
	ScopedTypeMember(GroupMemberMembers, Spawn);
	ScopedTypeMember(GroupMemberMembers, Level);
	ScopedTypeMember(GroupMemberMembers, MainTank);
	ScopedTypeMember(GroupMemberMembers, MainAssist);
	ScopedTypeMember(GroupMemberMembers, Puller);
	ScopedTypeMember(GroupMemberMembers, MarkNpc);
	ScopedTypeMember(GroupMemberMembers, MasterLooter);
	ScopedTypeMember(GroupMemberMembers, Mercenary);
	ScopedTypeMember(GroupMemberMembers, PctAggro);
	ScopedTypeMember(GroupMemberMembers, Index);
	ScopedTypeMember(GroupMemberMembers, Offline);
	ScopedTypeMember(GroupMemberMembers, OtherZone);
	ScopedTypeMember(GroupMemberMembers, Present);
}

bool MQ2GroupMemberType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	CHARINFO* pChar = GetCharInfo();
	if (!pChar || !pCharData->Group)
		return false;

	SPAWNINFO* pGroupMember = nullptr;
	CGroupMember* pGroupMemberData = nullptr;

	char MemberName[MAX_STRING] = { 0 };
	char LeaderName[MAX_STRING] = { 0 };

	int nMember = VarPtr.Int;

	if (int index = nMember)
	{
		if (index >= MAX_GROUP_SIZE)
			return false;

		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			if (CGroupMember* pMember = pCharData->Group->GetGroupMember(i))
			{
				index--;

				if (index == 0)
				{
					strcpy_s(MemberName, pMember->GetName());

					if (pMember->pSpawn)
					{
						pGroupMember = pMember->pSpawn;
					}

					pGroupMemberData = pMember;
					break;
				}
			}
		}
		if (MemberName[0] == '\0')
			return false;
	}
	else
	{
		if (pGroupMember = pChar->pSpawn)
		{
			strcpy_s(MemberName, pGroupMember->Name);
		}

		pGroupMemberData = pCharData->Group->GetGroupMember(0);
	}

	MQTypeMember* pMember = MQ2GroupMemberType::FindMember(Member);
	if (!pMember)
	{
		return pSpawnType->GetMember(pGroupMember, Member, Index, Dest);
	}

	switch (static_cast<GroupMemberMembers>(pMember->ID))
	{
	case GroupMemberMembers::Name:
		strcpy_s(DataTypeTemp, CleanupName(MemberName, sizeof(MemberName), false, false));
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case GroupMemberMembers::Leader:
		Dest.Type = pBoolType;
		if (!pCharData->Group->GetGroupLeader())
			return false;

		// TODO: GroupMembers: use IsGroupLeader
		strcpy_s(LeaderName, pCharData->Group->GetGroupLeader()->GetName());
		Dest.Set(!_stricmp(MemberName, LeaderName));
		return true;

	case GroupMemberMembers::Spawn:
		if (pGroupMember)
		{
			Dest = pSpawnType->MakeTypeVar(pGroupMember);
			return true;
		}
		return false;

	case GroupMemberMembers::Level:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pGroupMember)
		{
			Dest.DWord = pGroupMember->Level;
			return true;
		}

		if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->Level;
			return true;
		}

		return false;

	case GroupMemberMembers::MainTank:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.Set(pGroupMemberData->IsMainTank());
			return true;
		}
		return false;

	case GroupMemberMembers::MainAssist:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.Set(pGroupMemberData->IsMainAssist());
			return true;
		}
		return false;

	case GroupMemberMembers::MarkNpc:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.Set(pGroupMemberData->IsMarkNPC());
			return true;
		}
		return false;

	case GroupMemberMembers::MasterLooter:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.Set(pGroupMemberData->IsMasterLooter());
			return true;
		}
		return false;

	case GroupMemberMembers::Puller:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.Set(pGroupMemberData->IsPuller());
			return true;
		}
		return false;

	case GroupMemberMembers::Mercenary:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.Set(pGroupMemberData->Type == SPAWN_NPC);
			return true;
		}
		return false;

	case GroupMemberMembers::PctAggro:
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

	case GroupMemberMembers::Index:
		Dest.DWord = nMember;
		Dest.Type = pIntType;
		return true;

	case GroupMemberMembers::Offline:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.Set(pGroupMemberData->IsOffline());
			return true;
		}
		return false;

	case GroupMemberMembers::Present:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.Set(pGroupMemberData->GetPlayer() != nullptr);
			Dest.Type = pBoolType;
			return true;
		}
		return false;

	case GroupMemberMembers::OtherZone:
		Dest.Type = pBoolType;
		Dest.Set(pGroupMemberData && !pGroupMemberData->IsOffline() && !pGroupMemberData->GetPlayer());
		return true;
	}
	return false;
}

bool MQ2GroupMemberType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (int index = VarPtr.Int)
	{
		if (index > 5)
			return false;

		CHARINFO* pChar = GetCharInfo();
		if (!pCharData->Group) return false;

		// members 1 to 5. Count to the nth member.
		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			CGroupMember* pMember = pCharData->Group->GetGroupMember(i);
			if (pMember)
			{
				index--;
				if (index == 0)
				{
					char Name[MAX_STRING] = { 0 };
					strcpy_s(Name, pMember->GetName());

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

bool MQ2GroupMemberType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pGroupMemberType)
		return false;
	VarPtr.Ptr = Source.Ptr;
	return true;
}

} // namespace mq::datatypes
