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

enum class AltAbilityMembers
{
	Name = 1,
	Description,
	Category,
	ShortName,
	ShortName2,
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
	GroupID,
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
	ScopedTypeMember(AltAbilityMembers, Description);
	ScopedTypeMember(AltAbilityMembers, Category);
	ScopedTypeMember(AltAbilityMembers, ShortName);
	ScopedTypeMember(AltAbilityMembers, ShortName2);
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
	ScopedTypeMember(AltAbilityMembers, GroupID);
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
	CAltAbilityData* pAbility = static_cast<CAltAbilityData*>(VarPtr.Ptr);
	if (!pAbility)
		return false;

	MQTypeMember* pMember = MQ2AltAbilityType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<AltAbilityMembers>(pMember->ID))
	{
	case AltAbilityMembers::Name:
		Dest.Type = pStringType;
		strcpy_s(DataTypeTemp, pAbility->GetNameString());
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case AltAbilityMembers::Description:
		Dest.Type = pStringType;
		strcpy_s(DataTypeTemp, pAbility->GetDescriptionString());
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case AltAbilityMembers::Category:
		Dest.Type = pStringType;
		strcpy_s(DataTypeTemp, pAbility->GetCategoryString());
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case AltAbilityMembers::ShortName:
		Dest.Type = pStringType;
		strcpy_s(DataTypeTemp, pAbility->GetShortName1());
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case AltAbilityMembers::ShortName2:
		Dest.Type = pStringType;
		strcpy_s(DataTypeTemp, pAbility->GetShortName2());
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case AltAbilityMembers::ID:
	case AltAbilityMembers::GroupID:
		Dest.DWord = pAbility->GroupID;
		Dest.Type = pIntType;
		return true;

	case AltAbilityMembers::ReuseTime:
		Dest.DWord = pAbility->ReuseTimer;
		Dest.Type = pIntType;
		return true;

	case AltAbilityMembers::MyReuseTime:
		Dest.DWord = pAltAdvManager->GetCalculatedTimer(pLocalPC, pAbility);
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
		if (!pAbility->RequiredGroups.empty() && !pAbility->RequiredGroupLevels.empty())
		{
			int requiredGroup = pAbility->RequiredGroups[0];
			int requiredGroupRank = pAbility->RequiredGroupLevels[0];

			if (requiredGroup > 0 && requiredGroupRank > 0)
			{
				for (int nAbility = 0; nAbility < NUM_ALT_ABILITIES; nAbility++)
				{
					CAltAbilityData* tmpAbility = GetAAById(nAbility);
					if (tmpAbility && tmpAbility->GroupID == requiredGroup)
					{
						Dest.Ptr = tmpAbility;
						return true;
					}
				}
			}
		}
		return false;

	case AltAbilityMembers::RequiresAbilityPoints:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!pAbility->RequiredGroups.empty() && !pAbility->RequiredGroupLevels.empty())
		{
			Dest.DWord = pAbility->RequiredGroupLevels[0];
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
		if (pLocalPC->HasAlternateAbility(pAbility->Index))
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

	case AltAbilityMembers::CanTrain:
		if (CAltAbilityData* pNextAbility = GetAAById(pAbility->NextGroupAbilityId))
			pAbility = pNextAbility;

		Dest.Set(pAltAdvManager->CanTrainAbility(pLocalPC, pAbility, false, false, false));
		Dest.Type = pBoolType;
		return true;

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
	CAltAbilityData* pAbility = static_cast<CAltAbilityData*>(VarPtr.Ptr);
	if (!pAbility)
		return false;

	_itoa_s(pAbility->GroupID, Destination, MAX_STRING, 10);
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
			if (CAltAbilityData* pAbility = GetAAById(nAbility))
			{
				if (pAbility->GroupID == GetIntFromString(szIndex, 0))
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
		int level = pLocalPlayer ? pLocalPlayer->Level : -1;

		for (int nAbility = 0; nAbility < NUM_ALT_ABILITIES; nAbility++)
		{
			if (CAltAbilityData* pAbility = GetAAById(nAbility, level))
			{
				const char* pName = pAbility->GetNameString();
				if (!_stricmp(szIndex, pName))
				{
					Ret.Ptr = pAbility;
					Ret.Type = pAltAbilityType;
					return true;
				}
			}
		}
	}

	return false;
}

} // namespace mq::datatypes
