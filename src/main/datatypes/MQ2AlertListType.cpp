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

enum class AlertListTypeMembers
{
	MinLevel = 1,
	MaxLevel,
	SpawnType,
	SpawnID,
	FromSpawnID,
	Radius,
	Name,
	BodyType,
	Race,
	Class,
	Light,
	GuildID,
	bSpawnID,
	bNotNearAlert,
	bNearAlert,
	bNoAlert,
	bAlert,
	bLFG,
	bTrader,
	bLight,
	bTargNext,
	bTargPrev,
	bGroup,
	bNoGroup,
	bRaid,
	bGM,
	bNamed,
	bMerchant,
	bTributeMaster,
	bKnight,
	bTank,
	bHealer,
	bDps,
	bSlower,
	bAura,
	bBanner,
	bCampfire,
	NotID,
	NotNearAlertList,
	NearAlertList,
	NoAlertList,
	AlertList,
	ZRadius,
	FRadius,
	xLoc,
	yLoc,
	bKnownLocation,
	bNoPet,
	SortBy,
	bNoGuild,
	bLoS,
	bExactName,
	bTargetable,
	PlayerState,
	Spawn,
	bFellowship,
	bBanker,
};

MQ2AlertListType::MQ2AlertListType() : MQ2Type("alertlist")
{
	ScopedTypeMember(AlertListTypeMembers, MinLevel);
	ScopedTypeMember(AlertListTypeMembers, MaxLevel);
	ScopedTypeMember(AlertListTypeMembers, SpawnType);
	ScopedTypeMember(AlertListTypeMembers, SpawnID);
	ScopedTypeMember(AlertListTypeMembers, FromSpawnID);
	ScopedTypeMember(AlertListTypeMembers, Radius);
	ScopedTypeMember(AlertListTypeMembers, Name);
	ScopedTypeMember(AlertListTypeMembers, BodyType);
	ScopedTypeMember(AlertListTypeMembers, Race);
	ScopedTypeMember(AlertListTypeMembers, Class);
	ScopedTypeMember(AlertListTypeMembers, Light);
	ScopedTypeMember(AlertListTypeMembers, GuildID);
	ScopedTypeMember(AlertListTypeMembers, bSpawnID);
	ScopedTypeMember(AlertListTypeMembers, bNotNearAlert);
	ScopedTypeMember(AlertListTypeMembers, bNearAlert);
	ScopedTypeMember(AlertListTypeMembers, bNoAlert);
	ScopedTypeMember(AlertListTypeMembers, bAlert);
	ScopedTypeMember(AlertListTypeMembers, bLFG);
	ScopedTypeMember(AlertListTypeMembers, bTrader);
	ScopedTypeMember(AlertListTypeMembers, bLight);
	ScopedTypeMember(AlertListTypeMembers, bTargNext);
	ScopedTypeMember(AlertListTypeMembers, bTargPrev);
	ScopedTypeMember(AlertListTypeMembers, bGroup);
	ScopedTypeMember(AlertListTypeMembers, bNoGroup);
	ScopedTypeMember(AlertListTypeMembers, bRaid);
	ScopedTypeMember(AlertListTypeMembers, bGM);
	ScopedTypeMember(AlertListTypeMembers, bNamed);
	ScopedTypeMember(AlertListTypeMembers, bMerchant);
	ScopedTypeMember(AlertListTypeMembers, bTributeMaster);
	ScopedTypeMember(AlertListTypeMembers, bKnight);
	ScopedTypeMember(AlertListTypeMembers, bTank);
	ScopedTypeMember(AlertListTypeMembers, bHealer);
	ScopedTypeMember(AlertListTypeMembers, bDps);
	ScopedTypeMember(AlertListTypeMembers, bSlower);
	ScopedTypeMember(AlertListTypeMembers, bAura);
	ScopedTypeMember(AlertListTypeMembers, bBanner);
	ScopedTypeMember(AlertListTypeMembers, bCampfire);
	ScopedTypeMember(AlertListTypeMembers, NotID);
	ScopedTypeMember(AlertListTypeMembers, NotNearAlertList);
	ScopedTypeMember(AlertListTypeMembers, NearAlertList);
	ScopedTypeMember(AlertListTypeMembers, NoAlertList);
	ScopedTypeMember(AlertListTypeMembers, AlertList);
	ScopedTypeMember(AlertListTypeMembers, ZRadius);
	ScopedTypeMember(AlertListTypeMembers, FRadius);
	ScopedTypeMember(AlertListTypeMembers, xLoc);
	ScopedTypeMember(AlertListTypeMembers, yLoc);
	ScopedTypeMember(AlertListTypeMembers, bKnownLocation);
	ScopedTypeMember(AlertListTypeMembers, bNoPet);
	ScopedTypeMember(AlertListTypeMembers, SortBy);
	ScopedTypeMember(AlertListTypeMembers, bNoGuild);
	ScopedTypeMember(AlertListTypeMembers, bLoS);
	ScopedTypeMember(AlertListTypeMembers, bExactName);
	ScopedTypeMember(AlertListTypeMembers, bTargetable);
	ScopedTypeMember(AlertListTypeMembers, PlayerState);
	ScopedTypeMember(AlertListTypeMembers, Spawn);
	ScopedTypeMember(AlertListTypeMembers, bFellowship);
	ScopedTypeMember(AlertListTypeMembers, bBanker);
}

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
			case AlertListTypeMembers::MinLevel:
				Dest.DWord = search.MinLevel;
				Dest.Type = pIntType;
				return true;

			case AlertListTypeMembers::MaxLevel:
				Dest.DWord = search.MaxLevel;
				Dest.Type = pIntType;
				return true;

			case AlertListTypeMembers::SpawnType:
				Dest.DWord = search.SpawnType;
				Dest.Type = pIntType;
				return true;

			case AlertListTypeMembers::SpawnID:
				Dest.DWord = search.SpawnID;
				Dest.Type = pIntType;
				return true;

			case AlertListTypeMembers::FromSpawnID:
				Dest.DWord = search.FromSpawnID;
				Dest.Type = pIntType;
				return true;

			case AlertListTypeMembers::Radius:
				Dest.Float = search.Radius;
				Dest.Type = pFloatType;
				return true;

			case AlertListTypeMembers::Name:
				Dest.Type = pStringType;
				strcpy_s(DataTypeTemp, search.szName);
				if (DataTypeTemp[0])
				{
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
				return false;

			case AlertListTypeMembers::BodyType:
				Dest.Type = pStringType;
				strcpy_s(DataTypeTemp, search.szBodyType);
				if (DataTypeTemp[0]) {
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
				return false;

			case AlertListTypeMembers::Race:
				Dest.Type = pStringType;
				strcpy_s(DataTypeTemp, search.szRace);
				if (DataTypeTemp[0]) {
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
				return false;

			case AlertListTypeMembers::Class:
				Dest.Type = pStringType;
				strcpy_s(DataTypeTemp, search.szClass);
				if (DataTypeTemp[0]) {
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
				return false;

			case AlertListTypeMembers::Light:
				Dest.Type = pStringType;
				strcpy_s(DataTypeTemp, search.szLight);
				if (DataTypeTemp[0])
				{
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
				return false;

			case AlertListTypeMembers::GuildID:
				Dest.UInt64 = search.GuildID;
				Dest.Type = pInt64Type;
				return true;

			case AlertListTypeMembers::bSpawnID:
				Dest.Set(search.bSpawnID);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bNotNearAlert:
				Dest.Set(search.bNotNearAlert);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bNearAlert:
				Dest.Set(search.bNearAlert);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bNoAlert:
				Dest.Set(search.bNoAlert);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bAlert:
				Dest.Set(search.bAlert);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bLFG:
				Dest.Set(search.bLFG);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bTrader:
				Dest.Set(search.bTrader);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bLight:
				Dest.Set(search.bLight);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bTargNext:
				Dest.Set(search.bTargNext);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bTargPrev:
				Dest.Set(search.bTargPrev);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bGroup:
				Dest.Set(search.bGroup);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bFellowship:
				Dest.Set(search.bFellowship);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bNoGroup:
				Dest.Set(search.bNoGroup);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bRaid:
				Dest.Set(search.bRaid);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bGM:
				Dest.Set(search.bGM);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bNamed:
				Dest.Set(search.bNamed);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bMerchant:
				Dest.Set(search.bMerchant);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bBanker:
				Dest.Set(search.bBanker);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bTributeMaster:
				Dest.Set(search.bTributeMaster);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bKnight:
				Dest.Set(search.bKnight);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bTank:
				Dest.Set(search.bTank);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bHealer:
				Dest.Set(search.bHealer);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bDps:
				Dest.Set(search.bDps);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bSlower:
				Dest.Set(search.bSlower);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bAura:
				Dest.Set(search.bAura);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bBanner:
				Dest.Set(search.bBanner);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bCampfire:
				Dest.Set(search.bCampfire);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::NotID:
				Dest.DWord = search.NotID;
				Dest.Type = pIntType;
				return true;

			case AlertListTypeMembers::NotNearAlertList:
				Dest.DWord = search.NotNearAlertList;
				Dest.Type = pIntType;
				return true;

			case AlertListTypeMembers::NearAlertList:
				Dest.DWord = search.NearAlertList;
				Dest.Type = pIntType;
				return true;

			case AlertListTypeMembers::NoAlertList:
				Dest.DWord = search.NoAlertList;
				Dest.Type = pIntType;
				return true;

			case AlertListTypeMembers::AlertList:
				Dest.DWord = search.AlertList;
				Dest.Type = pIntType;
				return true;

			case AlertListTypeMembers::ZRadius:
				Dest.Double = search.ZRadius;
				Dest.Type = pDoubleType;
				return true;

			case AlertListTypeMembers::FRadius:
				Dest.Double = search.FRadius;
				Dest.Type = pDoubleType;
				return true;

			case AlertListTypeMembers::xLoc:
				Dest.Float = search.xLoc;
				Dest.Type = pFloatType;
				return true;

			case AlertListTypeMembers::yLoc:
				Dest.Float = search.yLoc;
				Dest.Type = pFloatType;
				return true;

			case AlertListTypeMembers::bKnownLocation:
				Dest.Set(search.bKnownLocation);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bNoPet:
				Dest.Set(search.bNoPet);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::SortBy:
				Dest.DWord = static_cast<unsigned int>(search.SortBy);
				Dest.Type = pIntType;
				return true;

			case AlertListTypeMembers::bNoGuild:
				Dest.Set(search.bNoGuild);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bLoS:
				Dest.Set(search.bLoS);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bExactName:
				Dest.Set(search.bExactName);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::bTargetable:
				Dest.Set(search.bTargetable);
				Dest.Type = pBoolType;
				return true;

			case AlertListTypeMembers::PlayerState:
				Dest.DWord = search.PlayerState;
				Dest.Type = pIntType;
				return true;

			case AlertListTypeMembers::Spawn:
				if (uint32_t spawnid = search.SpawnID)
				{
					if (SPAWNINFO* psp = GetSpawnByID(spawnid))
					{
						Dest = pSpawnType->MakeTypeVar(psp);
						return true;
					}
				}

				if (search.szName[0])
				{
					if (SPAWNINFO* psp = GetSpawnByName(search.szName))
					{
						Dest = pSpawnType->MakeTypeVar(psp);
						return true;
					}
				}

				Dest = pSpawnType->MakeTypeVar();
				return true;
			}
		}
	}
	return false;
}

bool MQ2AlertListType::ToString(MQVarPtr VarPtr, char* Destination)
{
	DWORD theindex = LOWORD(VarPtr.DWord);
	DWORD theitem = HIWORD(VarPtr.DWord);
	sprintf_s(Destination, 128, "${Alert[%d].List[%d].Name}", (int)theindex, (int)theitem);
	return true;
}

} // namespace mq::datatypes
