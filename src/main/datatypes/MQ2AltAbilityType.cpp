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

enum class AltAbilityMembers
{
	Name = 1,
	ShortName,
	Description,
	MinLevel,
	Cost,
	RequiresAbility,
	RequiresAbilityPoints,
	MaxRank,
	AARankRequired,
	Spell,
	Type,
	ReuseTime,
	ID,
	MyReuseTime,
	Flags,
	Expansion,
	Passive,
	PointsSpent,
	Rank,
	Index,
	CanTrain,
	NextIndex,
};

MQ2AltAbilityType::MQ2AltAbilityType() : MQ2Type("altability")
{
	ScopedTypeMember(AltAbilityMembers, Name);
	ScopedTypeMember(AltAbilityMembers, ShortName);
	ScopedTypeMember(AltAbilityMembers, Description);
	ScopedTypeMember(AltAbilityMembers, MinLevel);
	ScopedTypeMember(AltAbilityMembers, Cost);
	ScopedTypeMember(AltAbilityMembers, RequiresAbility);
	ScopedTypeMember(AltAbilityMembers, RequiresAbilityPoints);
	ScopedTypeMember(AltAbilityMembers, MaxRank);
	ScopedTypeMember(AltAbilityMembers, AARankRequired);
	ScopedTypeMember(AltAbilityMembers, Spell);
	ScopedTypeMember(AltAbilityMembers, Type);
	ScopedTypeMember(AltAbilityMembers, ReuseTime);
	ScopedTypeMember(AltAbilityMembers, ID);
	ScopedTypeMember(AltAbilityMembers, MyReuseTime);
	ScopedTypeMember(AltAbilityMembers, Flags);
	ScopedTypeMember(AltAbilityMembers, Expansion);
	ScopedTypeMember(AltAbilityMembers, Passive);
	ScopedTypeMember(AltAbilityMembers, PointsSpent);
	ScopedTypeMember(AltAbilityMembers, Rank);
	ScopedTypeMember(AltAbilityMembers, Index);
	ScopedTypeMember(AltAbilityMembers, CanTrain);
	ScopedTypeMember(AltAbilityMembers, NextIndex);
}

bool MQ2AltAbilityType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar & Dest)
{
	ALTABILITY* pAbility = static_cast<ALTABILITY*>(VarPtr.Ptr);
	if (!pAbility)
		return false;

	MQTypeMember* pMember = MQ2AltAbilityType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<AltAbilityMembers>(pMember->ID))
	{
	case AltAbilityMembers::Name:
		Dest.Type = pStringType;
		if (const char* ptr = pCDBStr->GetString(pAbility->nName, eAltAbilityName))
		{
			strcpy_s(DataTypeTemp, ptr);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case AltAbilityMembers::ShortName:
		// What is this even for? Need to check -eqmule
		Dest.Type = pStringType;
		if (const char* ptr = pCDBStr->GetString(pAbility->nName, eAltAbilityButton1))
		{
			strcpy_s(DataTypeTemp, ptr);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case AltAbilityMembers::Description:
		Dest.Type = pStringType;
		if (const char* ptr = pCDBStr->GetString(pAbility->nName, eAltAbilityDescription))
		{
			strcpy_s(DataTypeTemp, ptr);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case AltAbilityMembers::ID:
		Dest.DWord = pAbility->ID;
		Dest.Type = pIntType;
		return true;

	case AltAbilityMembers::ReuseTime:
		Dest.DWord = pAbility->ReuseTimer;
		Dest.Type = pIntType;
		return true;

	case AltAbilityMembers::MyReuseTime:
		Dest.DWord = pAltAdvManager->GetCalculatedTimer(pPCData, pAbility);
		Dest.Type = pIntType;
		return true;

	case AltAbilityMembers::MinLevel:
		Dest.DWord = pAbility->MinLevel;
		Dest.Type = pIntType;
		return true;

	case AltAbilityMembers::Cost:
		Dest.DWord = pAbility->Cost;
		Dest.Type = pIntType;
		return true;

	case AltAbilityMembers::Spell:
		Dest.Type = pSpellType;
		if (Dest.Ptr = GetSpellByID(pAbility->SpellID))
		{
			return true;
		}
		return false;

	case AltAbilityMembers::RequiresAbility:
		Dest.Type = pAltAbilityType;
		if (pAbility->RequiredGroupLevels && *pAbility->RequiredGroupLevels > 0)
		{
			for (int nAbility = 0; nAbility < NUM_ALT_ABILITIES; nAbility++)
			{
				if (ALTABILITY* tmppAbility = GetAAByIdWrapper(nAbility))
				{
					if (tmppAbility->ID == *pAbility->RequiredGroupLevels)
					{
						Dest.Ptr = tmppAbility;
						return true;
					}
				}
			}
		}

		if (pAbility)
			DebugSpew("ability %d not found\n", pAbility->RequiredGroupLevels);
		return false;

	case AltAbilityMembers::RequiresAbilityPoints:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pAbility->RequiresAbilityPoints)
		{
			Dest.DWord = *pAbility->RequiresAbilityPoints;
			return true;
		}
		return false;

	case AltAbilityMembers::MaxRank:
		Dest.DWord = pAbility->MaxRank;
		Dest.Type = pIntType;
		return true;

	case AltAbilityMembers::Rank: // the current rank
	case AltAbilityMembers::AARankRequired: { // kept this for legacy reasons
		int CurrentRank = pAbility->CurrentRank - 1;
		if (pPCData->HasAlternateAbility(pAbility->Index))
		{
			CurrentRank++;
		}
		Dest.DWord = CurrentRank;
		Dest.Type = pIntType;
		return true;
	}

	case AltAbilityMembers::Type:
		Dest.DWord = pAbility->Type;
		Dest.Type = pIntType;
		return true;

	case AltAbilityMembers::Flags:
		Dest.DWord = pAbility->bShowInAbilityWindow;
		Dest.Type = pIntType;
		return true;

	case AltAbilityMembers::Expansion:
		Dest.DWord = pAbility->Expansion;
		Dest.Type = pIntType;
		return true;

	case AltAbilityMembers::Passive:
		Dest.Set(true);
		Dest.Type = pBoolType;
		if (pAbility->SpellID != -1)
			Dest.Set(false);
		return true;

	case AltAbilityMembers::PointsSpent:
		Dest.DWord = pAbility->TotalPoints;
		Dest.Type = pIntType;
		return true;

	case AltAbilityMembers::Index:
		Dest.DWord = pAbility->Index;
		Dest.Type = pIntType;
		return true;

	case AltAbilityMembers::CanTrain: {
		if (ALTABILITY* pNextAbility = GetAAByIdWrapper(pAbility->NextGroupAbilityId))
			pAbility = pNextAbility;

		Dest.Set(pAltAdvManager->CanTrainAbility((PcZoneClient*)pPCData, pAbility, false, false, false));
		Dest.Type = pBoolType;
		return true;
	}

	case AltAbilityMembers::NextIndex:
		Dest.DWord = pAbility->NextGroupAbilityId;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2AltAbilityType::ToString(MQVarPtr VarPtr, char* Destination)
{
	ALTABILITY* pAbility = static_cast<ALTABILITY*>(VarPtr.Ptr);
	if (!pAbility)
		return false;

	_itoa_s(pAbility->ID, Destination, MAX_STRING, 10);
	return true;
}

bool MQ2AltAbilityType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pAltAbilityType)
		return false;
	VarPtr.Ptr = Source.Ptr;
	return true;
}

bool MQ2AltAbilityType::dataAltAbility(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	if (IsNumber(szIndex))
	{
		for (int nAbility = 0; nAbility < NUM_ALT_ABILITIES; nAbility++)
		{
			if (ALTABILITY* pAbility = GetAAByIdWrapper(nAbility))
			{
				if (pAbility->ID == GetIntFromString(szIndex, 0))
				{
					Ret.Ptr = pAbility;
					Ret.Type = pAltAbilityType;
					return true;
				}
			}
		}
	}
	else
	{
		// we need to get the level appropriate one if they just supplied a name
		int level = -1;
		if (SPAWNINFO* pMe = (SPAWNINFO*)pLocalPlayer)
		{
			level = pMe->Level;
		}

		for (int nAbility = 0; nAbility < NUM_ALT_ABILITIES; nAbility++)
		{
			if (PALTABILITY pAbility = GetAAByIdWrapper(nAbility, level))
			{
				if (const char* pName = pCDBStr->GetString(pAbility->nName, eAltAbilityName))
				{
					if (!_stricmp(szIndex, pName))
					{
						Ret.Ptr = pAbility;
						Ret.Type = pAltAbilityType;
						return true;
					}
				}
			}
		}
	}

	return false;
}

} // namespace mq::datatypes
