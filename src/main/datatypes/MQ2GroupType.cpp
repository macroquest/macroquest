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

bool MQ2GroupType::ToString(MQVarPtr VarPtr, char* Destination)
{
	CHARINFO* pChar = GetCharInfo();
	if (!pChar || !pChar->pGroupInfo) return false;

	int nMembers = 0;
	for (int index = 1; index < MAX_GROUP_SIZE; index++)
	{
		if (pChar->pGroupInfo->pMember[index])
			nMembers++;
	}

	_itoa_s(nMembers, Destination, MAX_STRING, 10);
	return true;
}

bool MQ2GroupType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2GroupType::FindMember(Member);
	CHARINFO* pChar = GetCharInfo();

	if (!pMember || !pChar || !pChar->pGroupInfo)
		return false;

	switch (static_cast<GroupMembers>(pMember->ID))
	{
	case Address:
		Dest.DWord = (uint32_t)pChar->pGroupInfo;
		Dest.Type = pIntType;
		return true;

	case xMember:
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
		if (pChar->pSpawn)
		{
			Dest.DWord = 0;
			if (ci_equals(pChar->pSpawn->Name, Index))
			{
				Dest.DWord = 0;
				return true;
			}

			for (int i = 1; i < MAX_GROUP_SIZE; i++)
			{
				if (pChar->pGroupInfo->pMember[i])
				{
					Dest.DWord++;
					char Name[MAX_STRING] = { 0 };
					strcpy_s(Name, pChar->pGroupInfo->pMember[i]->Name.c_str());

					CleanupName(Name, sizeof(Name), false, false); // we do this to fix the mercenaryname bug

					if (Index[0] != 0 && ci_equals(Name, Index))
					{
						return true;
					}
				}
			}
		}
		return false;

	case Members:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
				Dest.DWord++;
		}
		return true;

	case Leader: {
		Dest.Type = pGroupMemberType;
		if (!pChar->pGroupInfo->pLeader || !pChar->pSpawn)
			return false;
		Dest.DWord = 0;

		if (ci_equals(pChar->pSpawn->Name, pChar->pGroupInfo->pLeader->Name))
		{
			return true;
		}

		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				Dest.DWord++;

				if (ci_equals(pChar->pGroupInfo->pMember[i]->Name, pChar->pGroupInfo->pLeader->Name))
				{
					return true;
				}
			}
		}

		if (!Dest.DWord)
		{
			// group has no members
			return true;
		}
		return false;
	}

	case GroupSize:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
				Dest.DWord++;
		}

		if (Dest.DWord)
			Dest.DWord++;
		return true;

	case MainTank:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;

		if (pChar->pGroupInfo->pMember[0]->MainTank)
		{
			return true;
		}

		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				Dest.DWord++;
				if (pChar->pGroupInfo->pMember[i]->MainTank)
				{
					return true;
				}
			}
		}
		return false;

	case MainAssist:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;

		if (pChar->pGroupInfo->pMember[0]->MainAssist)
		{
			return true;
		}

		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				Dest.DWord++;
				if (pChar->pGroupInfo->pMember[i]->MainAssist)
				{
					return true;
				}
			}
		}
		return false;

	case Puller:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;

		if (pChar->pGroupInfo->pMember[0]->Puller)
		{
			return true;
		}

		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				Dest.DWord++;
				if (pChar->pGroupInfo->pMember[i]->Puller)
				{
					return true;
				}
			}
		}
		return false;

	case MarkNpc:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;

		if (pChar->pGroupInfo->pMember[0]->MarkNpc)
		{
			return true;
		}

		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				Dest.DWord++;
				if (pChar->pGroupInfo->pMember[i]->MarkNpc)
				{
					return true;
				}
			}
		}
		return false;

	case MasterLooter:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;

		if (pChar->pGroupInfo->pMember[0]->MasterLooter)
		{
			return true;
		}

		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				Dest.DWord++;
				if (pChar->pGroupInfo->pMember[i]->MasterLooter)
				{
					return true;
				}
			}
		}
		return false;

	case AnyoneMissing:
		Dest.Set(false);
		Dest.Type = pBoolType;

		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			if (pChar->pGroupInfo->pMember[i]
				&& (pChar->pGroupInfo->pMember[i]->Offline
					|| (pChar->pGroupInfo->pMember[i]->Offline == 0
						&& pChar->pGroupInfo->pMember[i]->pSpawn == nullptr)
					|| (pChar->pGroupInfo->pMember[i]->pSpawn
						&& pChar->pGroupInfo->pMember[i]->pSpawn->Type == SPAWN_CORPSE)))
			{
				Dest.Set(true);
				break;
			}
		}
		return true;

	case Present:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			if (pChar->pGroupInfo->pMember[i]
				&& pChar->pGroupInfo->pMember[i]->pSpawn
				&& pChar->pGroupInfo->pMember[i]->pSpawn->Type != SPAWN_CORPSE)
			{
				Dest.DWord++;
			}
		}
		return true;

	case MercenaryCount:
		Dest.DWord = GetGroupMercenaryCount(AllClassesMASK);
		Dest.Type = pIntType;
		return true;

	case TankMercCount:
		Dest.DWord = GetGroupMercenaryCount(WarriorMASK);
		Dest.Type = pIntType;
		return true;

	case HealerMercCount:
		Dest.DWord = GetGroupMercenaryCount(ClericMASK);
		Dest.Type = pIntType;
		return true;

	case MeleeMercCount:
		Dest.DWord = GetGroupMercenaryCount(RogueMASK);
		Dest.Type = pIntType;
		return true;

	case CasterMercCount:
		Dest.DWord = GetGroupMercenaryCount(WizardMASK);
		Dest.Type = pIntType;
		return true;

	case AvgHPs:
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
			if (pChar->pGroupInfo->pMember[i]
				&& pChar->pGroupInfo->pMember[i]->pSpawn
				&& pChar->pGroupInfo->pMember[i]->pSpawn->Type != SPAWN_CORPSE)
			{
				hps += pChar->pGroupInfo->pMember[i]->pSpawn->HPCurrent;
				nummembers++;
			}
		}

		if (hps != 0 && nummembers != 0)
		{
			Dest.Int64 = hps / nummembers;
		}
		return true;
	}

	case Injured:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (int threshold = GetIntFromString(Index, 0))
		{
			int64_t hps = 0;
			for (int i = 0; i < MAX_GROUP_SIZE; i++)
			{
				if (pChar->pGroupInfo->pMember[i]
					&& pChar->pGroupInfo->pMember[i]->pSpawn
					&& pChar->pGroupInfo->pMember[i]->pSpawn->Type != SPAWN_CORPSE
					&& pChar->pGroupInfo->pMember[i]->Offline == 0)
				{
					if (i == 0)
					{
						if (pChar->pGroupInfo->pMember[i]->pSpawn->HPCurrent
							&& pChar->pGroupInfo->pMember[i]->pSpawn->HPMax)
						{
							float fhpc = (float)pChar->pGroupInfo->pMember[i]->pSpawn->HPCurrent;
							float fhpm = (float)pChar->pGroupInfo->pMember[i]->pSpawn->HPMax;
							hps = (int64_t)(fhpc * 100 / fhpm);
						}
					}
					else
					{
						hps = pChar->pGroupInfo->pMember[i]->pSpawn->HPCurrent;
					}

					if (hps > 0 && hps < threshold)
					{
						Dest.DWord++;
					}
				}
			}

		}
		return true;

	case XCleric:
		Dest.Ptr = nullptr;
		Dest.Type = pSpawnType;

		for (auto& member : pChar->pGroupInfo->pMember)
		{
			if (member
				&& member->Type == EQP_PC
				&& member->pSpawn
				&& member->pSpawn->GetClass() == Cleric)
			{
				Dest.Ptr = member->pSpawn;
				return true;
			}
		}
		return false;

	case MouseOver:
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
							if (i > 0 && i < MAX_GROUP_SIZE && pChar->pGroupInfo->pMember[i])
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

