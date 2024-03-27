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

enum class DynamicZoneMembers
{
	Name = 1,
	Members,
	MaxMembers,
	MinMembers,
	Member,
	Leader,
	InRaid,
	LeaderFlagged,
	MaxTimers,
	Timer,
};

MQ2DynamicZoneType::MQ2DynamicZoneType() : MQ2Type("dynamiczone")
{
	ScopedTypeMember(DynamicZoneMembers, Name);
	ScopedTypeMember(DynamicZoneMembers, Members);
	ScopedTypeMember(DynamicZoneMembers, MaxMembers);
	ScopedTypeMember(DynamicZoneMembers, MinMembers);
	ScopedTypeMember(DynamicZoneMembers, Member);
	ScopedTypeMember(DynamicZoneMembers, Leader);
	ScopedTypeMember(DynamicZoneMembers, InRaid);
	ScopedTypeMember(DynamicZoneMembers, LeaderFlagged);
	ScopedTypeMember(DynamicZoneMembers, MaxTimers);
	ScopedTypeMember(DynamicZoneMembers, Timer);
}


bool MQ2DynamicZoneType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2DynamicZoneType::FindMember(Member);
	if (!pMember)
		return false;
	if (!pDynamicZone)
		return false;

	DynamicZoneMembers dataMember = static_cast<DynamicZoneMembers>(pMember->ID);
	switch (dataMember)
	{
	case DynamicZoneMembers::LeaderFlagged:
		Dest.Set(pDynamicZone->pFirstMember && pDynamicZone->pFirstMember->bFlagged);
		Dest.Type = pBoolType;
		return true;

	case DynamicZoneMembers::MaxTimers: {
		Dest.DWord = 0;
		Dest.Type = pIntType;
		DynamicZoneClientTimerData* pTimer = pDynamicZone->pFirstTimer;
		while (pTimer)
		{
			++Dest.DWord;
			pTimer = pTimer->pNext;
		}
		return true;
	}

	case DynamicZoneMembers::Timer:
		if (Index[0])
		{
			DynamicZoneClientTimerData* pTimer = pDynamicZone->pFirstTimer;
			if (IsNumber(Index))
			{
				int Count = GetIntFromString(Index, 0) - 1;
				if (Count < 0)
					return false;

				Dest.Type = pDZTimerType;
				Dest.Ptr = nullptr;

				while (pTimer)
				{
					if (Count == 0)
					{
						Dest.Ptr = pTimer;
						return true;
					}

					pTimer = pTimer->pNext;
					--Count;
				}
			}
			else
			{
				std::string_view svExpedition = Index;
				std::string_view svEvent;

				auto pos = svExpedition.find("|");
				if (pos != std::string_view::npos)
				{
					svEvent = svExpedition.substr(pos + 1);
					svExpedition = svExpedition.substr(0, pos);
				}

				// In the event of multiple matches we'll take the one that is unlocking next.
				eqtime_t bestTime = INT_MAX;
				DynamicZoneClientTimerData* pBestTimer = nullptr;

				while (pTimer)
				{
					if (ci_equals(pTimer->ExpeditionName, svExpedition)
						&& (svEvent.empty() || ci_equals(svEvent, pTimer->EventName)))
					{
						if (pTimer->TimeStamp < bestTime)
						{
							pBestTimer = pTimer;
							bestTime = pTimer->TimeStamp;
						}
					}
					pTimer = pTimer->pNext;
				}

				Dest.Type = pDZTimerType;
				Dest.Ptr = pBestTimer;
				return true;
			}
		}
		return false;

	default:
		break;
	}

	if (!pDZMember)
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

	case DynamicZoneMembers::MaxMembers:
		Dest.DWord = pDynamicZone->MaxPlayers;
		Dest.Type = pIntType;
		return true;

	case DynamicZoneMembers::MinMembers:
		Dest.DWord = pDynamicZone->MinPlayers;
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

//============================================================================

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
	if (!pDynamicZoneMember)
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

//============================================================================

enum class DZTimerTypeMembers
{
	ExpeditionName,
	EventName,
	Timer,
	EventID,
};

MQ2DZTimerType::MQ2DZTimerType() : MQ2Type("dztimer")
{
	ScopedTypeMember(DZTimerTypeMembers, ExpeditionName);
	ScopedTypeMember(DZTimerTypeMembers, EventName);
	ScopedTypeMember(DZTimerTypeMembers, Timer);
	ScopedTypeMember(DZTimerTypeMembers, EventID);
}

bool MQ2DZTimerType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	auto* pTimerData = reinterpret_cast<DynamicZoneClientTimerData*>(VarPtr.Ptr);
	if (!pTimerData)
		return false;

	MQTypeMember* pMember = MQ2DZTimerType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<DZTimerTypeMembers>(pMember->ID))
	{
	case DZTimerTypeMembers::ExpeditionName:
		Dest.Type = pStringType;
		strcpy_s(&DataTypeTemp[0], MAX_STRING, pTimerData->ExpeditionName);
		Dest.Ptr = DataTypeTemp;
		return true;

	case DZTimerTypeMembers::EventName:
		Dest.Type = pStringType;
		strcpy_s(&DataTypeTemp[0], MAX_STRING, pTimerData->EventName);
		Dest.Ptr = DataTypeTemp;
		return true;

	case DZTimerTypeMembers::Timer:
		Dest.Type = pTimeStampType;
		Dest.Int64 = std::max<int64_t>(0, (pTimerData->TimeStamp - (int64_t)GetFastTime()) * 1000); // seconds to ms
		return true;

	case DZTimerTypeMembers::EventID:
		Dest.Type = pIntType;
		Dest.Int = pTimerData->TimerID;
		return true;
	};

	return false;
}

bool MQ2DZTimerType::ToString(MQVarPtr VarPtr, char* destination)
{
	auto* pTimerData = reinterpret_cast<DynamicZoneClientTimerData*>(VarPtr.Ptr);
	if (!pTimerData)
		return false;

	sprintf_s(destination, MAX_STRING, "%s|%s", pTimerData->ExpeditionName, pTimerData->EventName);
	return true;
}

} // namespace mq::datatypes
