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

bool MQ2AlertListType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2AlertListType::FindMember(Member);
	if (!pMember)
		return false;

	uint16_t theindex = LOWORD(VarPtr.DWord);
	uint16_t itemIndex = HIWORD(VarPtr.DWord);

	std::vector<MQSpawnSearch> ss;
	if (CAlerts.GetAlert(theindex, ss))
	{
		if (itemIndex < ss.size())
		{
			MQSpawnSearch& search = ss[itemIndex];

			switch (static_cast<AlertListTypeMembers>(pMember->ID))
			{
			case MinLevel:
				Dest.DWord = search.MinLevel;
				Dest.Type = pIntType;
				return true;

			case MaxLevel:
				Dest.DWord = search.MaxLevel;
				Dest.Type = pIntType;
				return true;

			case SpawnType:
				Dest.DWord = search.SpawnType;
				Dest.Type = pIntType;
				return true;

			case SpawnID:
				Dest.DWord = search.SpawnID;
				Dest.Type = pIntType;
				return true;

			case FromSpawnID:
				Dest.DWord = search.FromSpawnID;
				Dest.Type = pIntType;
				return true;

			case Radius:
				Dest.Float = search.Radius;
				Dest.Type = pFloatType;
				return true;

			case Name:
				Dest.Type = pStringType;
				strcpy_s(DataTypeTemp, search.szName);
				if (DataTypeTemp[0])
				{
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
				return false;

			case BodyType:
				Dest.Type = pStringType;
				strcpy_s(DataTypeTemp, search.szBodyType);
				if (DataTypeTemp[0]) {
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
				return false;

			case Race:
				Dest.Type = pStringType;
				strcpy_s(DataTypeTemp, search.szRace);
				if (DataTypeTemp[0]) {
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
				return false;

			case Class:
				Dest.Type = pStringType;
				strcpy_s(DataTypeTemp, search.szClass);
				if (DataTypeTemp[0]) {
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
				return false;

			case Light:
				Dest.Type = pStringType;
				strcpy_s(DataTypeTemp, search.szLight);
				if (DataTypeTemp[0])
				{
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
				return false;

			case GuildID:
				Dest.UInt64 = search.GuildID;
				Dest.Type = pInt64Type;
				return true;

			case bSpawnID:
				Dest.DWord = search.bSpawnID;
				Dest.Type = pBoolType;
				return true;

			case bNotNearAlert:
				Dest.DWord = search.bNotNearAlert;
				Dest.Type = pBoolType;
				return true;

			case bNearAlert:
				Dest.DWord = search.bNearAlert;
				Dest.Type = pBoolType;
				return true;

			case bNoAlert:
				Dest.DWord = search.bNoAlert;
				Dest.Type = pBoolType;
				return true;

			case bAlert:
				Dest.DWord = search.bAlert;
				Dest.Type = pBoolType;
				return true;

			case bLFG:
				Dest.DWord = search.bLFG;
				Dest.Type = pBoolType;
				return true;

			case bTrader:
				Dest.DWord = search.bTrader;
				Dest.Type = pBoolType;
				return true;

			case bLight:
				Dest.DWord = search.bLight;
				Dest.Type = pBoolType;
				return true;

			case bTargNext:
				Dest.DWord = search.bTargNext;
				Dest.Type = pBoolType;
				return true;

			case bTargPrev:
				Dest.DWord = search.bTargPrev;
				Dest.Type = pBoolType;
				return true;

			case bGroup:
				Dest.DWord = search.bGroup;
				Dest.Type = pBoolType;
				return true;

			case bFellowship:
				Dest.DWord = search.bFellowship;
				Dest.Type = pBoolType;
				return true;

			case bNoGroup:
				Dest.DWord = search.bNoGroup;
				Dest.Type = pBoolType;
				return true;

			case bRaid:
				Dest.DWord = search.bRaid;
				Dest.Type = pBoolType;
				return true;

			case bGM:
				Dest.DWord = search.bGM;
				Dest.Type = pBoolType;
				return true;

			case bNamed:
				Dest.DWord = search.bNamed;
				Dest.Type = pBoolType;
				return true;

			case bMerchant:
				Dest.DWord = search.bMerchant;
				Dest.Type = pBoolType;
				return true;

			case bBanker:
				Dest.DWord = search.bBanker;
				Dest.Type = pBoolType;
				return true;

			case bTributeMaster:
				Dest.DWord = search.bTributeMaster;
				Dest.Type = pBoolType;
				return true;

			case bKnight:
				Dest.DWord = search.bKnight;
				Dest.Type = pBoolType;
				return true;

			case bTank:
				Dest.DWord = search.bTank;
				Dest.Type = pBoolType;
				return true;

			case bHealer:
				Dest.DWord = search.bHealer;
				Dest.Type = pBoolType;
				return true;

			case bDps:
				Dest.DWord = search.bDps;
				Dest.Type = pBoolType;
				return true;

			case bSlower:
				Dest.DWord = search.bSlower;
				Dest.Type = pBoolType;
				return true;

			case bAura:
				Dest.DWord = search.bAura;
				Dest.Type = pBoolType;
				return true;

			case bBanner:
				Dest.DWord = search.bBanner;
				Dest.Type = pBoolType;
				return true;

			case bCampfire:
				Dest.DWord = search.bCampfire;
				Dest.Type = pBoolType;
				return true;

			case NotID:
				Dest.DWord = search.NotID;
				Dest.Type = pIntType;
				return true;

			case NotNearAlertList:
				Dest.DWord = search.NotNearAlertList;
				Dest.Type = pIntType;
				return true;

			case NearAlertList:
				Dest.DWord = search.NearAlertList;
				Dest.Type = pIntType;
				return true;

			case NoAlertList:
				Dest.DWord = search.NoAlertList;
				Dest.Type = pIntType;
				return true;

			case AlertList:
				Dest.DWord = search.AlertList;
				Dest.Type = pIntType;
				return true;

			case ZRadius:
				Dest.Double = search.ZRadius;
				Dest.Type = pDoubleType;
				return true;

			case FRadius:
				Dest.Double = search.FRadius;
				Dest.Type = pDoubleType;
				return true;

			case xLoc:
				Dest.Float = search.xLoc;
				Dest.Type = pFloatType;
				return true;

			case yLoc:
				Dest.Float = search.yLoc;
				Dest.Type = pFloatType;
				return true;

			case bKnownLocation:
				Dest.DWord = search.bKnownLocation;
				Dest.Type = pBoolType;
				return true;

			case bNoPet:
				Dest.DWord = search.bNoPet;
				Dest.Type = pBoolType;
				return true;

			case SortBy:
				Dest.DWord = static_cast<unsigned int>(search.SortBy);
				Dest.Type = pIntType;
				return true;

			case bNoGuild:
				Dest.DWord = search.bNoGuild;
				Dest.Type = pBoolType;
				return true;

			case bLoS:
				Dest.DWord = search.bLoS;
				Dest.Type = pBoolType;
				return true;

			case bExactName:
				Dest.DWord = search.bExactName;
				Dest.Type = pBoolType;
				return true;

			case bTargetable:
				Dest.DWord = search.bTargetable;
				Dest.Type = pBoolType;
				return true;

			case PlayerState:
				Dest.DWord = search.PlayerState;
				Dest.Type = pIntType;
				return true;

			case Spawn:
				Dest.Type = pSpawnType;
				if (uint32_t spawnid = search.SpawnID)
				{
					if (SPAWNINFO* psp = (SPAWNINFO*)GetSpawnByID(spawnid))
					{
						Dest.Ptr = psp;
						return true;
					}
				}

				if (search.szName[0])
				{
					if (SPAWNINFO* psp = (SPAWNINFO*)GetSpawnByName(search.szName))
					{
						Dest.Ptr = psp;
						return true;
					}
				}
				return false;
			}
		}
	}
	return false;
}

