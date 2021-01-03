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

bool MQ2AltAbilityType::ToString(MQVarPtr VarPtr, char* Destination)
{
	ALTABILITY* pAbility = static_cast<ALTABILITY*>(VarPtr.Ptr);
	if (!pAbility)
		return false;

	_itoa_s(pAbility->ID, Destination, MAX_STRING, 10);
	return true;
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
	case Name:
		Dest.Type = pStringType;
		if (const char* ptr = pCDBStr->GetString(pAbility->nName, eAltAbilityName))
		{
			strcpy_s(DataTypeTemp, ptr);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case ShortName:
		// What is this even for? Need to check -eqmule
		Dest.Type = pStringType;
		if (const char* ptr = pCDBStr->GetString(pAbility->nName, eAltAbilityButton1))
		{
			strcpy_s(DataTypeTemp, ptr);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case Description:
		Dest.Type = pStringType;
		if (const char* ptr = pCDBStr->GetString(pAbility->nName, eAltAbilityDescription))
		{
			strcpy_s(DataTypeTemp, ptr);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case ID:
		Dest.DWord = pAbility->ID;
		Dest.Type = pIntType;
		return true;

	case ReuseTime:
		Dest.DWord = pAbility->ReuseTimer;
		Dest.Type = pIntType;
		return true;

	case MyReuseTime:
		Dest.DWord = pAltAdvManager->GetCalculatedTimer(pPCData, pAbility);
		Dest.Type = pIntType;
		return true;

	case MinLevel:
		Dest.DWord = pAbility->MinLevel;
		Dest.Type = pIntType;
		return true;

	case Cost:
		Dest.DWord = pAbility->Cost;
		Dest.Type = pIntType;
		return true;

	case Spell:
		Dest.Type = pSpellType;
		if (Dest.Ptr = GetSpellByID(pAbility->SpellID))
		{
			return true;
		}
		return false;

	case RequiresAbility:
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

	case RequiresAbilityPoints:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pAbility->RequiresAbilityPoints)
		{
			Dest.DWord = *pAbility->RequiresAbilityPoints;
			return true;
		}
		return false;

	case MaxRank:
		Dest.DWord = pAbility->MaxRank;
		Dest.Type = pIntType;
		return true;

	case Rank: // the current rank
	case AARankRequired: { // kept this for legacy reasons
		int CurrentRank = pAbility->CurrentRank - 1;
		if (pPCData->HasAlternateAbility(pAbility->Index))
		{
			CurrentRank++;
		}
		Dest.DWord = CurrentRank;
		Dest.Type = pIntType;
		return true;
	}

	case Type:
		Dest.DWord = pAbility->Type;
		Dest.Type = pIntType;
		return true;

	case Flags:
		Dest.DWord = pAbility->bShowInAbilityWindow;
		Dest.Type = pIntType;
		return true;

	case Expansion:
		Dest.DWord = pAbility->Expansion;
		Dest.Type = pIntType;
		return true;

	case Passive:
		Dest.Set(true);
		Dest.Type = pBoolType;
		if (pAbility->SpellID != -1)
			Dest.Set(false);
		return true;

	case PointsSpent:
		Dest.DWord = pAbility->TotalPoints;
		Dest.Type = pIntType;
		return true;

	case xIndex:
		Dest.DWord = pAbility->Index;
		Dest.Type = pIntType;
		return true;

	case CanTrain: {
		if (ALTABILITY* pNextAbility = GetAAByIdWrapper(pAbility->NextGroupAbilityId))
			pAbility = pNextAbility;

		Dest.Set(pAltAdvManager->CanTrainAbility((PcZoneClient*)pPCData, pAbility, 0, 0, 0));
		Dest.Type = pBoolType;
		return true;
	}

	case NextIndex:
		Dest.DWord = pAbility->NextGroupAbilityId;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

