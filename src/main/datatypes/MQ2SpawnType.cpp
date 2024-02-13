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

#include "MQ2SpellSearch.h"

namespace mq::datatypes {

enum class SpawnMembers
{
	ID = 1,
	Name,
	Level,
	X,
	Y,
	Z,
	DistanceX,
	DistanceY,
	DistanceZ,
	Distance,
	Distance3D,
	DistancePredict,
	Next,
	Prev,
	Heading,
	Speed,
	Levitating,
	Sneaking,
	HeadingTo,
	Light,
	Body,
	State,
	CurrentHPs,
	MaxHPs,
	PctHPs,
	Deity,
	Type,
	CleanName,
	Surname,
	Guild,
	GuildStatus,
	Master,
	Pet,
	Race,
	Class,
	Gender,
	GM,
	Height,
	MaxRange,
	AARank,
	Casting,
	Mount,
	FeetWet,
	BodyWet,
	HeadWet,
	Underwater,
	Animation,
	Holding,
	Look,
	N,
	W,
	U,
	S,
	E,
	D,
	DistanceN,
	DistanceW,
	DistanceU,
	Invis,
	Linkdead,
	LFG,
	Trader,
	AFK,
	ConColor,
	Standing,
	Sitting,
	Ducking,
	Feigning,
	Binding,
	NearestSpawn,
	MaxRangeTo,
	DisplayName,
	AATitle,
	GroupLeader,
	Mark,
	Assist,
	Anonymous,
	Roleplaying,
	LineOfSight,
	HeadingToLoc,
	Title,
	Suffix,
	Fleeing,
	Named,
	Buyer,
	Moving,
	StandState,
	Dead,
	Stunned,
	Hovering,
	CurrentMana,
	MaxMana,
	CurrentEndurance,
	PctEndurance,
	MaxEndurance,
	Loc,
	LocYX,
	LocYXZ,
	Owner,
	Following,
	MercID,
	ContractorID,
	PctMana,
	Primary,
	Secondary,
	Equipment,
	Targetable,
	PlayerState,
	Stuck,
	Aggressive,
	CanSplashLand,
	IsTouchingSwitch,
	bShowHelm,
	CorpseDragCount,
	CombatSkillTicks,
	InPvPArea,
	GMRank,
	TemporaryPet,
	HoldingAnimation,
	Blind,
	CeilingHeightAtCurrLocation,
	AssistName,
	SeeInvis,
	SpawnStatus,
	EQLoc,
	MQLoc,
	TimeBeenDead,
	FloorZ,
	IsSummoned,
	TargetOfTarget,
	ActorDef,
	CachedBuff,
	CachedBuffCount,
	Buff,
	BuffCount,
	BuffDuration,
	BuffsPopulated,
	FindBuff,
	MyBuff,
	MyBuffCount,
	MyBuffDuration,
};

enum class SpawnMethods
{
	DoTarget = 1,
	DoFace,
	DoAssist,
	LeftClick,
	RightClick
};

MQ2SpawnType::MQ2SpawnType() : MQ2Type("spawn")
{
	ScopedTypeMember(SpawnMembers, ID);
	ScopedTypeMember(SpawnMembers, Name);
	ScopedTypeMember(SpawnMembers, Level);
	ScopedTypeMember(SpawnMembers, X);
	ScopedTypeMember(SpawnMembers, Y);
	ScopedTypeMember(SpawnMembers, Z);
	ScopedTypeMember(SpawnMembers, DistanceX);
	ScopedTypeMember(SpawnMembers, DistanceY);
	ScopedTypeMember(SpawnMembers, DistanceZ);
	ScopedTypeMember(SpawnMembers, Distance);
	ScopedTypeMember(SpawnMembers, Distance3D);
	ScopedTypeMember(SpawnMembers, DistancePredict);
	ScopedTypeMember(SpawnMembers, Next);
	ScopedTypeMember(SpawnMembers, Prev);
	ScopedTypeMember(SpawnMembers, Heading);
	ScopedTypeMember(SpawnMembers, Speed);
	ScopedTypeMember(SpawnMembers, Levitating);
	ScopedTypeMember(SpawnMembers, Sneaking);
	ScopedTypeMember(SpawnMembers, HeadingTo);
	ScopedTypeMember(SpawnMembers, Light);
	ScopedTypeMember(SpawnMembers, Body);
	ScopedTypeMember(SpawnMembers, State);
	ScopedTypeMember(SpawnMembers, CurrentHPs);
	ScopedTypeMember(SpawnMembers, MaxHPs);
	ScopedTypeMember(SpawnMembers, PctHPs);
	ScopedTypeMember(SpawnMembers, Deity);
	ScopedTypeMember(SpawnMembers, Type);
	ScopedTypeMember(SpawnMembers, CleanName);
	ScopedTypeMember(SpawnMembers, Surname);
	ScopedTypeMember(SpawnMembers, Guild);
	ScopedTypeMember(SpawnMembers, GuildStatus);
	ScopedTypeMember(SpawnMembers, Master);
	ScopedTypeMember(SpawnMembers, Pet);
	ScopedTypeMember(SpawnMembers, Race);
	ScopedTypeMember(SpawnMembers, Class);
	ScopedTypeMember(SpawnMembers, Gender);
	ScopedTypeMember(SpawnMembers, GM);
	ScopedTypeMember(SpawnMembers, Height);
	ScopedTypeMember(SpawnMembers, MaxRange);
	ScopedTypeMember(SpawnMembers, AARank);
	ScopedTypeMember(SpawnMembers, Casting);
	ScopedTypeMember(SpawnMembers, Mount);
	ScopedTypeMember(SpawnMembers, FeetWet);
	ScopedTypeMember(SpawnMembers, BodyWet);
	ScopedTypeMember(SpawnMembers, HeadWet);
	ScopedTypeMember(SpawnMembers, Underwater);
	ScopedTypeMember(SpawnMembers, Animation);
	ScopedTypeMember(SpawnMembers, Holding);
	ScopedTypeMember(SpawnMembers, Look);
	ScopedTypeMember(SpawnMembers, N);
	ScopedTypeMember(SpawnMembers, W);
	ScopedTypeMember(SpawnMembers, U);
	ScopedTypeMember(SpawnMembers, S);
	ScopedTypeMember(SpawnMembers, E);
	ScopedTypeMember(SpawnMembers, D);
	ScopedTypeMember(SpawnMembers, DistanceN);
	ScopedTypeMember(SpawnMembers, DistanceW);
	ScopedTypeMember(SpawnMembers, DistanceU);
	ScopedTypeMember(SpawnMembers, Invis);
	ScopedTypeMember(SpawnMembers, Linkdead);
	ScopedTypeMember(SpawnMembers, LFG);
	ScopedTypeMember(SpawnMembers, Trader);
	ScopedTypeMember(SpawnMembers, AFK);
	ScopedTypeMember(SpawnMembers, ConColor);
	ScopedTypeMember(SpawnMembers, Standing);
	ScopedTypeMember(SpawnMembers, Sitting);
	ScopedTypeMember(SpawnMembers, Ducking);
	ScopedTypeMember(SpawnMembers, Feigning);
	ScopedTypeMember(SpawnMembers, Binding);
	ScopedTypeMember(SpawnMembers, NearestSpawn);
	ScopedTypeMember(SpawnMembers, MaxRangeTo);
	ScopedTypeMember(SpawnMembers, DisplayName);
	ScopedTypeMember(SpawnMembers, AATitle);
	ScopedTypeMember(SpawnMembers, GroupLeader);
	ScopedTypeMember(SpawnMembers, Assist);
	ScopedTypeMember(SpawnMembers, Mark);
	ScopedTypeMember(SpawnMembers, Anonymous);
	ScopedTypeMember(SpawnMembers, Roleplaying);
	ScopedTypeMember(SpawnMembers, LineOfSight);
	ScopedTypeMember(SpawnMembers, HeadingToLoc);
	ScopedTypeMember(SpawnMembers, Title);
	ScopedTypeMember(SpawnMembers, Suffix);
	ScopedTypeMember(SpawnMembers, Fleeing);
	ScopedTypeMember(SpawnMembers, Named);
	ScopedTypeMember(SpawnMembers, Buyer);
	ScopedTypeMember(SpawnMembers, Moving);
	ScopedTypeMember(SpawnMembers, StandState);
	ScopedTypeMember(SpawnMembers, Dead);
	ScopedTypeMember(SpawnMembers, Stunned);
	ScopedTypeMember(SpawnMembers, Hovering);
	ScopedTypeMember(SpawnMembers, CurrentMana);
	ScopedTypeMember(SpawnMembers, MaxMana);
	ScopedTypeMember(SpawnMembers, CurrentEndurance);
	ScopedTypeMember(SpawnMembers, PctEndurance);
	ScopedTypeMember(SpawnMembers, MaxEndurance);
	ScopedTypeMember(SpawnMembers, Loc);
	ScopedTypeMember(SpawnMembers, LocYX);
	ScopedTypeMember(SpawnMembers, LocYXZ);
	ScopedTypeMember(SpawnMembers, Owner);
	ScopedTypeMember(SpawnMembers, Following);
	ScopedTypeMember(SpawnMembers, MercID);
	ScopedTypeMember(SpawnMembers, ContractorID);
	ScopedTypeMember(SpawnMembers, PctMana);
	ScopedTypeMember(SpawnMembers, Primary);
	ScopedTypeMember(SpawnMembers, Secondary);
	ScopedTypeMember(SpawnMembers, Equipment);
	ScopedTypeMember(SpawnMembers, Targetable);
	ScopedTypeMember(SpawnMembers, PlayerState);
	ScopedTypeMember(SpawnMembers, Stuck);
	ScopedTypeMember(SpawnMembers, Aggressive);
	ScopedTypeMember(SpawnMembers, CanSplashLand);
	ScopedTypeMember(SpawnMembers, IsTouchingSwitch);
	ScopedTypeMember(SpawnMembers, bShowHelm);
	ScopedTypeMember(SpawnMembers, CorpseDragCount);
	ScopedTypeMember(SpawnMembers, CombatSkillTicks);
	ScopedTypeMember(SpawnMembers, InPvPArea);
	ScopedTypeMember(SpawnMembers, GMRank);
	ScopedTypeMember(SpawnMembers, TemporaryPet);
	ScopedTypeMember(SpawnMembers, HoldingAnimation);
	ScopedTypeMember(SpawnMembers, Blind);
	ScopedTypeMember(SpawnMembers, CeilingHeightAtCurrLocation);
	ScopedTypeMember(SpawnMembers, AssistName);
	ScopedTypeMember(SpawnMembers, SeeInvis);
	ScopedTypeMember(SpawnMembers, SpawnStatus);
	ScopedTypeMember(SpawnMembers, EQLoc);
	ScopedTypeMember(SpawnMembers, MQLoc);
	ScopedTypeMember(SpawnMembers, TimeBeenDead);
	ScopedTypeMember(SpawnMembers, FloorZ);
	ScopedTypeMember(SpawnMembers, IsSummoned);
	ScopedTypeMember(SpawnMembers, TargetOfTarget);
	ScopedTypeMember(SpawnMembers, ActorDef);
	ScopedTypeMember(SpawnMembers, CachedBuff);
	ScopedTypeMember(SpawnMembers, CachedBuffCount);
	ScopedTypeMember(SpawnMembers, Buff);
	ScopedTypeMember(SpawnMembers, BuffCount);
	ScopedTypeMember(SpawnMembers, BuffDuration);
	ScopedTypeMember(SpawnMembers, BuffsPopulated);
	ScopedTypeMember(SpawnMembers, FindBuff);
	ScopedTypeMember(SpawnMembers, MyBuff);
	ScopedTypeMember(SpawnMembers, MyBuffCount);
	ScopedTypeMember(SpawnMembers, MyBuffDuration);

	ScopedTypeMethod(SpawnMethods, DoTarget);
	ScopedTypeMethod(SpawnMethods, DoFace);
	ScopedTypeMethod(SpawnMethods, DoAssist);
	ScopedTypeMethod(SpawnMethods, LeftClick);
	ScopedTypeMethod(SpawnMethods, RightClick);
}

bool MQ2SpawnType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	return GetMember(GetSpawnPtr(VarPtr), Member, Index, Dest);
}

bool MQ2SpawnType::GetMember(SPAWNINFO* pSpawn, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pLocalPlayer || !pLocalPC || !pSpawn)
	{
		MQTypeMember* pMember = MQ2SpawnType::FindMember(Member);

		// Special case for easily handling Ids on null spawns
		if (pMember && static_cast<SpawnMembers>(pMember->ID) == SpawnMembers::ID)
		{
			Dest.Type = pIntType;
			Dest.DWord = 0;
			return true;
		}

		return false;
	}

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2SpawnType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<SpawnMethods>(pMethod->ID))
		{
		case SpawnMethods::DoTarget:
			pTarget = pSpawn;
			return true;

		case SpawnMethods::DoFace: {
			char szOut[256] = { 0 };
			sprintf_s(szOut, "id %d", pSpawn->SpawnID);
			Face(pLocalPlayer, szOut);
			return true;
		}

		case SpawnMethods::LeftClick:
			pEverQuest->LeftClickedOnPlayer(pSpawn);
			WeDidStuff();
			return true;

		case SpawnMethods::RightClick:
			pEverQuest->RightClickedOnPlayer(pSpawn, 0);
			WeDidStuff();
			return true;

		case SpawnMethods::DoAssist: {
			char szOut[256] = { 0 };
			sprintf_s(szOut, "%s", pSpawn->DisplayedName);
			AssistCmd(pLocalPlayer, szOut);
			return true;
		}

		default: return false;
		}
	}

	//----------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = MQ2SpawnType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<SpawnMembers>(pMember->ID))
	{
	case SpawnMembers::Level:
		Dest.DWord = pSpawn->Level;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::ID:
		Dest.Type = pIntType;
		Dest.DWord = pSpawn->SpawnID;
		return true;

	case SpawnMembers::Name:
		strcpy_s(DataTypeTemp, pSpawn->Name);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case SpawnMembers::Surname:
		strcpy_s(DataTypeTemp, pSpawn->Lastname);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case SpawnMembers::CleanName:
		strcpy_s(DataTypeTemp, pSpawn->Name);
		CleanupName(DataTypeTemp, DataTypeTemp.size(), false, false);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case SpawnMembers::DisplayName:
		strcpy_s(DataTypeTemp, pSpawn->DisplayedName);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case SpawnMembers::E:
		Dest.Type = pFloatType;
		Dest.Float = -pSpawn->X;
		return true;

	case SpawnMembers::W:
	case SpawnMembers::X:
		Dest.Type = pFloatType;
		Dest.Float = pSpawn->X;
		return true;

	case SpawnMembers::S:
		Dest.Type = pFloatType;
		Dest.Float = -pSpawn->Y;
		return true;

	case SpawnMembers::N:
	case SpawnMembers::Y:
		Dest.Type = pFloatType;
		Dest.Float = pSpawn->Y;
		return true;

	case SpawnMembers::D:
		Dest.Type = pFloatType;
		Dest.Float = -pSpawn->Z;
		return true;

	case SpawnMembers::U:
	case SpawnMembers::Z:
		Dest.Type = pFloatType;
		Dest.Float = pSpawn->Z;
		return true;

	case SpawnMembers::FloorZ:
		Dest.Type = pFloatType;
		Dest.Float = pSpawn->FloorHeight;
		return true;

	case SpawnMembers::Next:
		if (PlayerClient* pNext = pSpawn->GetNext())
		{
			Dest = MakeTypeVar(pNext);
			return true;
		}
		return false;

	case SpawnMembers::Prev:
		if (PlayerClient* pPrev = pSpawn->GetPrevious())
		{
			Dest = MakeTypeVar(pPrev);
			return true;
		}
		return false;

	case SpawnMembers::CurrentHPs:
		Dest.Type = pInt64Type;
		Dest.Int64 = pSpawn->HPCurrent;
		return true;

	case SpawnMembers::MaxHPs:
		Dest.Type = pInt64Type;
		Dest.Int64 = pSpawn->HPMax;
		return true;

	case SpawnMembers::PctHPs:
		// avoid dividing by zero!
		Dest.Int64 = pSpawn->HPMax == 0 ? 0 : pSpawn->HPCurrent * 100 / pSpawn->HPMax;
		Dest.Type = pInt64Type;
		return true;

	case SpawnMembers::AARank:
		Dest.Type = pIntType;
		Dest.Int = 0;
		if (pSpawn->AARank != 0xFF)
			Dest.Int = pSpawn->AARank;
		return true;

	case SpawnMembers::Speed:
		Dest.Float = FindSpeed(pSpawn);
		Dest.Type = pFloatType;
		return true;

	case SpawnMembers::Heading:
		Dest.Float = pSpawn->Heading * 0.703125f; // Convert from EQ heading to degrees (180 / 250)
		Dest.Type = pHeadingType;
		return true;

	case SpawnMembers::Pet:
		Dest = pSpawnType->MakeTypeVar(pSpawn->PetID != -1 ? GetSpawnByID(pSpawn->PetID) : nullptr);
		Dest.Type = pPetType;
		return true;

	case SpawnMembers::Master:
		Dest = MakeTypeVar(GetSpawnByID(pSpawn->MasterID));
		return true;

	case SpawnMembers::Gender:
		strcpy_s(DataTypeTemp, szGender[pSpawn->GetGender()]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpawnMembers::Race:
		Dest.DWord = pSpawn->GetRace();
		Dest.Type = pRaceType;
		return true;

	case SpawnMembers::Class:
		Dest.DWord = 0;
		Dest.Type = pClassType;

		if (GetSpawnType(pSpawn) != AURA && GetSpawnType(pSpawn) != BANNER && GetSpawnType(pSpawn) != CAMPFIRE)
		{
			Dest.DWord = pSpawn->GetClass();
		}
		else
		{
			if (GetSpawnType(pSpawn) == AURA)
				Dest.DWord = MQClass_Aura;
			else if (GetSpawnType(pSpawn) == BANNER)
				Dest.DWord = MQClass_Banner;
			else
				Dest.DWord = MQClass_CampFire;
		}
		return true;

	case SpawnMembers::Body:
		Dest.DWord = GetBodyType(pSpawn);
		Dest.Type = pBodyType;
		return true;

	case SpawnMembers::GM:
		Dest.Set(pSpawn->GM != 0);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Levitating:
		Dest.Set(pSpawn->mPlayerPhysicsClient.Levitate == 2);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Sneaking:
		Dest.Set(pSpawn->Sneak);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Invis: {
		Dest.Type = pBoolType;
		Dest.Set(false);

		if (!Index[0])
		{
			Dest.Set(pSpawn->HideMode != 0);
			return true;
		}

		enum class InvisModes {
			Any = 0,
			Regular = 1,
			Undead = 2,
			Animal = 3,
			SoS = 4,
		};
		InvisModes mode = InvisModes::Any;

		if (IsNumber(Index))
		{
			mode = static_cast<InvisModes>(GetIntFromString(Index, -1));
			if (mode < InvisModes::Any || mode > InvisModes::SoS)
				return true;
		}
		else
		{
			if (ci_equals(Index, "ANY"))
				mode = InvisModes::Any;
			else if (ci_equals(Index, "NORMAL"))
				mode = InvisModes::Regular;
			else if (ci_equals(Index, "UNDEAD"))
				mode = InvisModes::Undead;
			else if (ci_equals(Index, "ANIMAL"))
				mode = InvisModes::Animal;
			else if (ci_equals(Index, "SOS"))
				mode = InvisModes::SoS;
			else
				return true;
		}

		switch (mode)
		{
		case InvisModes::Any:
			Dest.Set(pSpawn->HideMode != 0);
			break;
		case InvisModes::Regular:
			Dest.Set(pLocalPC->CalculateInvisLevel(eAll) != 0);
			break;
		case InvisModes::Undead:
			Dest.Set(pLocalPC->CalculateInvisLevel(eUndead) != 0);
			break;
		case InvisModes::Animal:
			Dest.Set(pLocalPC->CalculateInvisLevel(eAnimal) != 0);
			break;
		case InvisModes::SoS:
			if (PcProfile* pProfile = GetPcProfile())
			{
				int skill = pLocalPC->GetAdjustedSkill(EQSKILL_HIDE);
				// SOS has additional ranks that add additional effects.  Level 105 would return 2 total effects.
				if (pProfile->bHide && pLocalPC->TotalEffect(SPA_SHROUD_OF_STEALTH) > 0 && skill >= 100)
					Dest.Set(true);
			}
			break;
		}

		return true;
	}

	case SpawnMembers::Height:
		Dest.Float = pSpawn->AvatarHeight;
		Dest.Type = pFloatType;
		return true;

	case SpawnMembers::MaxRange:
		Dest.Float = 0;
		Dest.Type = pFloatType;
		if (GetSpawnType(pSpawn) != ITEM)
		{
			Dest.Float = get_melee_range(pSpawn, pControlledPlayer);
			return true;
		}
		return false;

	case SpawnMembers::MaxRangeTo:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (GetSpawnType(pSpawn) != ITEM)
		{
			Dest.Float = get_melee_range(pControlledPlayer, pSpawn);
			return true;
		}
		return false;

	case SpawnMembers::Guild:
		Dest.Type = pStringType;
		if (pSpawn->GuildID != -1 && pSpawn->GuildID != 0)
		{
			const char* szGuild = GetGuildByID(pSpawn->GuildID);
			if (szGuild)
			{
				strcpy_s(DataTypeTemp, szGuild);
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
		}
		return false;

	case SpawnMembers::Type:
		Dest.Type = pStringType;
		strcpy_s(DataTypeTemp, GetTypeDesc(GetSpawnType(pSpawn)));
		if (!strncmp(DataTypeTemp, "Unk", 3))
			return false;

		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case SpawnMembers::Light:
		strcpy_s(DataTypeTemp, GetLightForSpawn(pSpawn));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpawnMembers::StandState:
		Dest.Int = pSpawn->StandState;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::State:
		DataTypeTemp[0] = '\0';
		Dest.Type = pStringType;

		if (pSpawn->PlayerState & 0x20)
		{
			strcpy_s(DataTypeTemp, "STUN");
		}
		else if (pSpawn == pLocalPlayer && pSpawn->RespawnTimer)
		{
			strcpy_s(DataTypeTemp, "HOVER");
		}
		else if (pSpawn->Mount)
		{
			strcpy_s(DataTypeTemp, "MOUNT");
		}
		else
		{
			switch (pSpawn->StandState)
			{
			case STANDSTATE_STAND:
				strcpy_s(DataTypeTemp, "STAND");
				break;
			case STANDSTATE_SIT:
				strcpy_s(DataTypeTemp, "SIT");
				break;
			case STANDSTATE_DUCK:
				strcpy_s(DataTypeTemp, "DUCK");
				break;
			case STANDSTATE_BIND:
				strcpy_s(DataTypeTemp, "BIND");
				break;
			case STANDSTATE_FEIGN:
				strcpy_s(DataTypeTemp, "FEIGN");
				break;
			case STANDSTATE_DEAD:
				strcpy_s(DataTypeTemp, "DEAD");
				break;
			default:
				strcpy_s(DataTypeTemp, "UNKNOWN");
				break;
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case SpawnMembers::Standing:
		Dest.Set(pSpawn->StandState == STANDSTATE_STAND);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Sitting:
		Dest.Set(pSpawn->StandState == STANDSTATE_SIT);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::TimeBeenDead:
		Dest.DWord = EQGetTime() - pSpawn->RespawnTimer;
		Dest.Type = pTimeStampType;
		return true;

	case SpawnMembers::IsSummoned: // if its a summoned being (pet for example)
		Dest.Set(pSpawn->bSummoned);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::TargetOfTarget:
		Dest = MakeTypeVar(GetSpawnByID(pSpawn->TargetOfTarget));
		return true;

	case SpawnMembers::Ducking:
		Dest.Set(pSpawn->StandState == STANDSTATE_DUCK);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Feigning:
		Dest.Set(pSpawn->StandState == STANDSTATE_FEIGN);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Binding:
		Dest.Set(pSpawn->StandState == STANDSTATE_BIND);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Dead:
		Dest.Set(pSpawn->StandState == STANDSTATE_DEAD);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Stunned:
		Dest.Set(false);
		if (pSpawn->PlayerState & 0x20)
			Dest.Set(true);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Aggressive:
		Dest.Set(false);
		if (pSpawn->PlayerState & 0x4 || pSpawn->PlayerState & 0x8)
			Dest.Set(true);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Hovering:
		Dest.Set(pSpawn->RespawnTimer != 0);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Deity:
		Dest.DWord = pSpawn->Deity;
		Dest.Type = pDeityType;
		return true;

	case SpawnMembers::Distance:
		Dest.Float = GetDistance(pSpawn->X, pSpawn->Y);
		Dest.Type = pFloatType;
		return true;

	case SpawnMembers::Distance3D:
		Dest.Float = DistanceToSpawn3D(pControlledPlayer, pSpawn);
		Dest.Type = pFloatType;
		return true;

	case SpawnMembers::DistancePredict:
		Dest.Float = EstimatedDistanceToSpawn(pControlledPlayer, pSpawn);
		Dest.Type = pFloatType;
		return true;

	case SpawnMembers::DistanceW:
	case SpawnMembers::DistanceX:
		Dest.Float = (float)fabs(pControlledPlayer->X - pSpawn->X);
		Dest.Type = pFloatType;
		return true;

	case SpawnMembers::DistanceN:
	case SpawnMembers::DistanceY:
		Dest.Float = (float)fabs(pControlledPlayer->Y - pSpawn->Y);
		Dest.Type = pFloatType;
		return true;

	case SpawnMembers::DistanceU:
	case SpawnMembers::DistanceZ:
		Dest.Float = (float)fabs(pControlledPlayer->Z - pSpawn->Z);
		Dest.Type = pFloatType;
		return true;

	case SpawnMembers::HeadingTo:
		Dest.Float = (float)(atan2f(pControlledPlayer->Y - pSpawn->Y, pSpawn->X - pControlledPlayer->X) * 180.0f / PI + 90.0f);
		if (Dest.Float < 0.0f)
			Dest.Float += 360.0f;
		else if (Dest.Float >= 360.0f)
			Dest.Float -= 360.0f;
		Dest.Type = pHeadingType;
		return true;

	case SpawnMembers::Casting:
		Dest.Type = pSpellType;
		if (Dest.Ptr = GetSpellByID(pSpawn->CastingData.SpellID))
		{
			return true;
		}
		return false;

	case SpawnMembers::Mount:
		if (pSpawn->Mount)
		{
			Dest = MakeTypeVar(pSpawn->Mount);
			return true;
		}
		return false;

	case SpawnMembers::Underwater:
		Dest.Set(pSpawn->UnderWater == LiquidType_Water);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::FeetWet:
		Dest.Set(pSpawn->FeetWet != LiquidType_None);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::BodyWet:
		Dest.Set(pSpawn->BodyWet != LiquidType_None);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::HeadWet:
		Dest.Set(pSpawn->HeadWet != LiquidType_None);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::PlayerState:
		Dest.DWord = pSpawn->PlayerState;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::Stuck:
		Dest.Set(pSpawn->PossiblyStuck != 0);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Animation:
		Dest.DWord = pSpawn->Animation;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::Holding:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (pSpawn->LeftHolding || pSpawn->RightHolding)
		{
			Dest.Set(true);
		}
		return true;

	case SpawnMembers::Look:
		Dest.Float = pSpawn->CameraAngle;
		Dest.Type = pFloatType;
		return true;

	case SpawnMembers::ConColor:
		Dest.Type = pStringType;

		switch (ConColor(pSpawn))
		{
		case CONCOLOR_GREY:
			strcpy_s(DataTypeTemp, "GREY");
			break;
		case CONCOLOR_GREEN:
			strcpy_s(DataTypeTemp, "GREEN");
			break;
		case CONCOLOR_LIGHTBLUE:
			strcpy_s(DataTypeTemp, "LIGHT BLUE");
			break;
		case CONCOLOR_BLUE:
			strcpy_s(DataTypeTemp, "BLUE");
			break;
		case CONCOLOR_WHITE:
			strcpy_s(DataTypeTemp, "WHITE");
			break;
		case CONCOLOR_YELLOW:
			strcpy_s(DataTypeTemp, "YELLOW");
			break;
		case CONCOLOR_RED:

		default:
			strcpy_s(DataTypeTemp, "RED");
			break;
		}

		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case SpawnMembers::NearestSpawn:
		if (pSpawn == pControlledPlayer)
		{
			return (dataNearestSpawn(Index, Dest) != 0); // use top-level object if it's you
		}

		if (Index[0])
		{
			MQSpawnSearch ssSpawn;
			ClearSearchSpawn(&ssSpawn);
			ssSpawn.FRadius = 999999.0f;

			int nth = 0;

			if (char* pSearch = strchr(Index, ','))
			{
				*pSearch = 0;
				++pSearch;
				ParseSearchSpawn(pSearch, &ssSpawn);

				nth = GetIntFromString(Index, nth);
			}
			else
			{
				if (IsNumber(Index))
				{
					nth = GetIntFromString(Index, nth);
				}
				else
				{
					nth = 1;
					ParseSearchSpawn(Index, &ssSpawn);
				}
			}

			if (SPAWNINFO* pNearest = NthNearestSpawn(&ssSpawn, nth, pSpawn))
			{
				Dest = MakeTypeVar(pNearest);
				return true;
			}
		}
		return false;

	case SpawnMembers::Trader:
		Dest.Set(pSpawn->Trader != 0);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::AFK:
		Dest.Set(pSpawn->AFK != 0);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::LFG:
		Dest.Set(pSpawn->LFG);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Linkdead:
		Dest.Set(pSpawn->Linkdead);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::AATitle:  // Leaving this in for older macros/etc.."Title" should be used instead.
	case SpawnMembers::Title:
		strcpy_s(DataTypeTemp, pSpawn->Title);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case SpawnMembers::Suffix:
		strcpy_s(DataTypeTemp, pSpawn->Suffix);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case SpawnMembers::GroupLeader:
		Dest.Set(false);
		Dest.Type = pBoolType;

		if (pLocalPC->Group && pLocalPC->Group->GetGroupLeader())
		{
			// TODO: GroupMembers: use IsLeader
			Dest.Set(pSpawn->Type == SPAWN_PLAYER
				&& !_stricmp(pLocalPC->Group->GetGroupLeader()->GetName(), pSpawn->Name));
		}
		return true;

	case SpawnMembers::Assist:
		Dest.Set(gGameState == GAMESTATE_INGAME && IsAssistNPC(pSpawn));
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Mark:
		if (gGameState == GAMESTATE_INGAME)
		{
			Dest.DWord = GetNPCMarkNumber(pSpawn);
			Dest.Type = pIntType;
			return true;
		}
		return false;

	case SpawnMembers::Anonymous:
		Dest.Set(pSpawn->Anon == 1);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Roleplaying:
		Dest.Set(pSpawn->Anon == 2);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::LineOfSight:
		Dest.Set(pControlledPlayer->CanSee(*pSpawn));
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::HeadingToLoc:
		Dest.Float = 0.0;
		Dest.Type = pHeadingType;

		if (!Index[0])
			return false;

		if (char* pComma = strchr(Index, ','))
		{
			*pComma = 0;
			float Y = GetFloatFromString(Index, 0);

			*pComma = ',';
			float X = GetFloatFromString(&pComma[1], 0);

			Dest.Float = (float)(atan2f(pSpawn->Y - Y, X - pSpawn->X) * 180.0f / PI + 90.0f);

			if (Dest.Float < 0.0f)
				Dest.Float += 360.0f;
			else if (Dest.Float >= 360.0f)
				Dest.Float -= 360.0f;
			return true;
		}
		return false;

	case SpawnMembers::Fleeing:
		Dest.Set(IsMobFleeing(pLocalPlayer, pSpawn));
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Named:
		Dest.Set(IsNamed(pSpawn));
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Buyer:
		Dest.Set(pSpawn->Buyer != 0);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Moving:
		Dest.Set(fabs(pSpawn->SpeedRun) > 0.0f);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::CurrentMana:
		Dest.DWord = pSpawn->GetCurrentMana();
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::MaxMana:
		Dest.DWord = pSpawn->GetMaxMana();
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::PctMana:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (int maxmana = pSpawn->GetMaxMana())
			Dest.Int = pSpawn->GetCurrentMana() * 100 / maxmana;
		return true;

	case SpawnMembers::CurrentEndurance:
		Dest.DWord = pSpawn->GetCurrentEndurance();
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::PctEndurance:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (int maxend = pSpawn->GetMaxEndurance())
			Dest.Int = pSpawn->GetCurrentEndurance() * 100 / maxend;
		return true;

	case SpawnMembers::MaxEndurance:
		Dest.DWord = pSpawn->GetMaxEndurance();
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::Loc:
		sprintf_s(DataTypeTemp, "%.2f, %.2f", pSpawn->Y, pSpawn->X);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpawnMembers::LocYX:
		sprintf_s(DataTypeTemp, "%.0f, %.0f", pSpawn->Y, pSpawn->X);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpawnMembers::LocYXZ:
		sprintf_s(DataTypeTemp, "%.2f, %.2f, %.2f", pSpawn->Y, pSpawn->X, pSpawn->Z);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpawnMembers::EQLoc:
		sprintf_s(DataTypeTemp, "%.2f, %.2f, %.2f", pSpawn->X, pSpawn->Y, pSpawn->Z);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpawnMembers::MQLoc:
		sprintf_s(DataTypeTemp, "%.2f, %.2f, %.2f", pSpawn->Y, pSpawn->X, pSpawn->Z);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpawnMembers::Owner:
		if (pSpawn->Mercenary)
		{
			size_t pos = strchr(pSpawn->Lastname, '\'') - &pSpawn->Lastname[0];
			strncpy_s(DataTypeTemp, pSpawn->Lastname, pos);

			DataTypeTemp[pos] = 0;

			if (SPAWNINFO* pOwner = GetSpawnByName(DataTypeTemp))
			{
				Dest = MakeTypeVar(pOwner);
				return true;
			}
		}
		return false;

	case SpawnMembers::Following:
		if (pSpawn->WhoFollowing)
		{
			Dest = MakeTypeVar(pSpawn->WhoFollowing);
			return true;
		}
		return false;

	case SpawnMembers::MercID:
		// FIXME: ROF2 emu does not have MercID
		Dest.DWord = pSpawn->MercID;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::ContractorID:
		// FIXME: ROF2 emu does not have ContractorID
		Dest.DWord = pSpawn->ContractorID;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::Primary:
		Dest.DWord = pSpawn->Equipment.Primary.ID;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::Secondary:
		Dest.DWord = pSpawn->Equipment.Offhand.ID;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::Equipment:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nSlot = GetIntFromString(Index, 0);
				int size = sizeof(EQUIPMENT) / 4;

				if (nSlot < 9)
				{
					Dest.DWord = pSpawn->Equipment.Item[nSlot].ID;
					return true;
				}
			}
			else
			{
				for (int nSlot = 0; szEquipmentSlot[nSlot]; nSlot++)
				{
					if (!_stricmp(Index, szEquipmentSlot[nSlot]))
					{
						Dest.DWord = pSpawn->Equipment.Item[nSlot].ID;
						return true;
					}
				}
			}
		}
		return false;

	case SpawnMembers::Targetable:
		Dest.Set(pSpawn->Targetable);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::CanSplashLand: {
		CVector3 sv3;
		sv3.X = pSpawn->Y;
		sv3.Y = pSpawn->X;
		sv3.Z = pSpawn->Z;
		Dest.Set(pControlledPlayer->CanSee(sv3));
		Dest.Type = pBoolType;
		return true;
	}

	case SpawnMembers::IsTouchingSwitch:
		Dest.Set(pSpawn->pTouchingSwitch != nullptr);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::bShowHelm:
		Dest.Set(pSpawn->GetShowHelm());
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::CorpseDragCount:
		Dest.DWord = pSpawn->CorpseDragCount;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::CombatSkillTicks:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (IsNumber(Index))
		{
			int index = GetIntFromString(Index, 0);
			if (index < 0)
				index = 0;
			if (index > 1)
				index = 1;
			Dest.DWord = pSpawn->CombatSkillTicks[index];
			return true;
		}
		return false;

	case SpawnMembers::InPvPArea:
		Dest.DWord = pSpawn->InPvPArea;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::GMRank:
		Dest.DWord = pSpawn->GMRank;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::TemporaryPet:
		Dest.Set(pSpawn->bTempPet);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::HoldingAnimation:
		Dest.DWord = pSpawn->HoldingAnimation;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::Blind:
		Dest.DWord = pSpawn->Blind;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::CeilingHeightAtCurrLocation:
		Dest.Float = pSpawn->CeilingHeightAtCurrLocation;
		Dest.Type = pFloatType;
		return true;

	case SpawnMembers::AssistName:
		strcpy_s(DataTypeTemp, pSpawn->AssistName);
		Dest.Ptr = DataTypeTemp;
		Dest.Type = pStringType;
		return true;

	case SpawnMembers::SeeInvis:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (IsNumber(Index))
		{
			int index = std::clamp(GetIntFromString(Index, 0), 0, SeeInvisLevels_Count - 1);
			Dest.DWord = pSpawn->GetSeeInvisLevel(index);
			return true;
		}
		return false;

	case SpawnMembers::SpawnStatus:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (IsNumber(Index))
		{
			int index = GetIntFromString(Index, 0);
			if (index < 0)
				index = 0;
			if (index > 5)
				index = 5;
			Dest.DWord = pSpawn->SpawnStatus[index];
			return true;
		}
		return false;

	case SpawnMembers::ActorDef:
		strcpy_s(DataTypeTemp, pSpawn->mActorClient.ActorDef);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpawnMembers::CachedBuff:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pSpawn;
		Dest.HighPart = -1;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				Dest.HighPart = GetCachedBuff(pSpawn,
					[&Index](const CachedBuff& buff) { return GetIntFromString(Index, 0) == buff.spellId; });
			}
			else
			{
				if (Index[0] == '#') // by buff slot
					Dest.HighPart = GetCachedBuff(pSpawn, [&Index](const CachedBuff& buff) { return GetIntFromString(&Index[1], 0) - 1 == buff.slot; });
				else if (Index[0] == '*') // by buff index
					Dest.HighPart = GetCachedBuffAt(pSpawn, GetIntFromString(&Index[1], 0) - 1);
				else if (Index[0] == '^') // by keyword
				{
					if (ci_equals(&Index[1], "slowed"))
						Dest.HighPart = GetCachedBuff(pSpawn, SpellAffect(SPA_HASTE, false));
					else if (ci_equals(&Index[1], "rooted"))
						Dest.HighPart = GetCachedBuff(pSpawn, SpellAffect(SPA_ROOT, false));
					else if (ci_equals(&Index[1], "mezzed"))
						Dest.HighPart = GetCachedBuff(pSpawn, SpellAffect(SPA_ENTHRALL, false));
					else if (ci_equals(&Index[1], "crippled"))
						Dest.HighPart = GetCachedBuff(pSpawn, SpellSubCat(SPELLCAT_DISEMPOWERING));
					else if (ci_equals(&Index[1], "maloed"))
						Dest.HighPart = GetCachedBuff(pSpawn, SpellSubCat(SPELLCAT_RESIST_DEBUFFS) && SpellClassMask(Shaman, Mage));
					else if (ci_equals(&Index[1], "tashed"))
						Dest.HighPart = GetCachedBuff(pSpawn, SpellSubCat(SPELLCAT_RESIST_DEBUFFS) && SpellClassMask(Enchanter));
					else if (ci_equals(&Index[1], "snared"))
						Dest.HighPart = GetCachedBuff(pSpawn, SpellAffect(SPA_MOVEMENT_RATE, false));
					else if (ci_equals(&Index[1], "beneficial"))
					{
						Dest.HighPart = GetCachedBuff(pSpawn, [](const CachedBuff& buff) -> bool
							{
								auto pSpell = GetSpellByID(buff.spellId);
								return pSpell && pSpell->SpellType != 0;
							});
					}
				}
				else
				{
					Dest.HighPart = GetCachedBuff(pSpawn, [&Index](const CachedBuff& buff)
						{
							return MaybeExactCompare(GetSpellNameByID(buff.spellId), Index);
						});
				}
			}
		}

		return true;

	case SpawnMembers::CachedBuffCount:
		Dest.Type = pIntType;
		Dest.DWord =  GetCachedBuffCount(pSpawn);
		return true;

	case SpawnMembers::BuffsPopulated:
		Dest.Set(gTargetbuffs && pSpawn != nullptr);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Buff:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pSpawn;

		if (!Index[0] || (Index[0] && IsNumber(Index)))
		{
			Dest.HighPart = GetCachedBuffAt(pSpawn, Index[0] ? GetIntFromString(Index, 0) - 1 : 0);
		}
		else
		{
			Dest.HighPart = GetCachedBuff(pSpawn,
				[&Index](const CachedBuff& buff)
				{
					return MaybeExactCompare(GetSpellNameByID(buff.spellId), Index);
				});
		}

		return true;

	case SpawnMembers::FindBuff:
	{
		if (!Index[0])
			return false;

		Dest.Type = pCachedBuffType;
		Dest.Ptr = pSpawn;

		auto attrib = EvaluateCachedBuffPredicate(Index);
		Dest.HighPart = GetCachedBuff(pSpawn,
			[&attrib](const CachedBuff& buff)
			{
				return attrib(buff);
			});

		return true;
	}

	case SpawnMembers::MyBuff:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pSpawn;

		if (!Index[0] || (Index[0] && IsNumber(Index)))
		{
			Dest.HighPart = GetCachedBuffAt(pSpawn, Index[0] ? GetIntFromString(Index, 0) - 1 : 0,
				[](const CachedBuff& buff) { return ci_equals(pLocalPC->Name, buff.casterName); });
		}
		else
		{
			Dest.HighPart = GetCachedBuff(pSpawn,
				[&Index](const CachedBuff& buff)
				{
					return ci_equals(pLocalPC->Name, buff.casterName)
						&& ci_starts_with(GetSpellNameByID(buff.spellId), Index);
				});
		}

		return true;

	case SpawnMembers::BuffCount:
		Dest.Type = pIntType;
		Dest.DWord = GetCachedBuffCount(pSpawn);
		return true;

	case SpawnMembers::MyBuffCount:
		Dest.Type = pIntType;
		Dest.DWord = GetCachedBuffCount(pSpawn, [](const CachedBuff& buff)
			{
				return ci_equals(pLocalPC->Name, buff.casterName);
			});
		return true;

	case SpawnMembers::BuffDuration:
		Dest.Type = pTimeStampType;
		if (!Index[0] || (Index[0] && IsNumber(Index)))
		{
			auto slot = GetCachedBuffAt(pSpawn, Index[0] ? GetIntFromString(Index, 0) - 1 : 0);
			if (slot < 0)
				return false;

			auto buff = GetCachedBuffAtSlot(pSpawn, slot);
			if (!buff)
				return false;

			Dest.UInt64 = buff->Duration();
			return true;
		}
		else
		{
			auto buffs = FilterCachedBuffs(pSpawn,
				[&Index](const CachedBuff& buff)
				{
					return ci_starts_with(GetSpellNameByID(buff.spellId), Index);
				});

			auto buff_it = std::max_element(std::cbegin(buffs), std::cend(buffs),
				[](const CachedBuff& a, const CachedBuff& b) { return a.Duration() < b.Duration(); });
			if (buff_it != std::cend(buffs))
			{
				Dest.UInt64 = buff_it->Duration();
				return true;
			}
		}

		return false;

	case SpawnMembers::MyBuffDuration:
		Dest.Type = pTimeStampType;
		if (!Index[0] || (Index[0] && IsNumber(Index)))
		{
			auto slot = GetCachedBuffAt(pSpawn, Index[0] ? GetIntFromString(Index, 0) - 1 : 0,
				[](const CachedBuff& buff) { return ci_equals(pLocalPC->Name, buff.casterName); });

			if (slot < 0)
				return false;

			auto buff = GetCachedBuffAtSlot(pSpawn, slot);
			if (!buff)
				return false;

			Dest.UInt64 = buff->Duration();
			return true;
		}
		else
		{
			auto buffs = FilterCachedBuffs(pSpawn,
				[&Index](const CachedBuff& buff)
				{
					return ci_equals(pLocalPC->Name, buff.casterName)
						&& ci_starts_with(GetSpellNameByID(buff.spellId), Index);
				});

			auto buff_it = std::max_element(std::cbegin(buffs), std::cend(buffs),
				[](const CachedBuff& a, const CachedBuff& b) { return a.Duration() < b.Duration(); });
			if (buff_it != std::cend(buffs))
			{
				Dest.UInt64 = buff_it->Duration();
				return true;
			}
		}
		return false;

	default:
		return false;
	}
}

bool MQ2SpawnType::ToString(MQVarPtr VarPtr, char* Destination)
{
	SPAWNINFO* pSpawn = GetSpawnPtr(VarPtr);
	if (!pSpawn)
		return false;

	strcpy_s(Destination, MAX_STRING, pSpawn->Name);
	return true;
}

bool MQ2SpawnType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type == pSpawnType)
	{
		VarPtr = Source;
		return true;
	}

	if (Source.IsType(MQVarPtr::VariantIdx::UInt64))
	{
		VarPtr = MakeVarPtr(GetSpawnByID(Source.Get<int>()));
		return true;
	}

	return false;
}

bool MQ2SpawnType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	int spawnID = GetIntFromString(Source, -1);
	if (spawnID >= 0)
	{
		SPAWNINFO* pOther = GetSpawnByID(spawnID);
		VarPtr = MakeVarPtr(pOther);
		return true;
	}

	return false;
}

bool MQ2SpawnType::dataSpawn(const char* szIndex, MQTypeVar& Ret)
{
	if (szIndex[0])
	{
		if (IsNumber(szIndex))
		{
			Ret = pSpawnType->MakeTypeVar(GetSpawnByID(GetIntFromString(szIndex, 0)));
			return true;
		}

		// set up search spawn
		MQSpawnSearch ssSpawn;
		ClearSearchSpawn(&ssSpawn);
		ParseSearchSpawn(szIndex, &ssSpawn);

		SPAWNINFO* pSearchSpawn = SearchThroughSpawns(&ssSpawn, pControlledPlayer);
		Ret = pSpawnType->MakeTypeVar(pSearchSpawn);
		return true;
	}

	// No spawn
	Ret = pSpawnType->MakeTypeVar();
	return true;
}

bool MQ2SpawnType::dataSpawnCount(const char* szIndex, MQTypeVar& Ret)
{
	if (szIndex[0])
	{
		MQSpawnSearch ssSpawn;
		ClearSearchSpawn(&ssSpawn);
		ParseSearchSpawn(szIndex, &ssSpawn);
		Ret.DWord = CountMatchingSpawns(&ssSpawn, pLocalPlayer, true);
		Ret.Type = pIntType;
		return true;
	}
	else
	{
		Ret.DWord = gSpawnCount;
		Ret.Type = pIntType;
		return true;
	}
}

bool MQ2SpawnType::dataLastSpawn(const char* szIndex, MQTypeVar& Ret)
{
	Ret = pSpawnType->MakeTypeVar();

	if (szIndex[0])
	{
		if (IsNumber(szIndex))
		{
			bool bPosIndex = true;
			int index = GetIntFromString(szIndex, 0);
			if (index < 0)
			{
				bPosIndex = false;
				index *= -1;
			}
			else if (index == 0)
			{
				index = 1;
			}
			index--;

			if (SPAWNINFO* pSpawn = bPosIndex ? pSpawnManager->FirstSpawn : pLocalPlayer)
			{
				while (index)
				{
					pSpawn = bPosIndex ? pSpawn->pNext : pSpawn->pPrev;
					if (!pSpawn)
						return true;
					index--;
				}

				Ret = pSpawnType->MakeTypeVar(pSpawn);
				return true;
			}
		}
	}
	else if (SPAWNINFO* pSpawn = pSpawnList)
	{
		Ret = pSpawnType->MakeTypeVar(pSpawn);
		return true;
	}

	return true;
}

constexpr float MAX_SEARCH_RADIUS = 999999.0f;

bool MQ2SpawnType::dataNearestSpawn(const char* szIndex, MQTypeVar& Ret)
{
	if (szIndex[0])
	{
		MQSpawnSearch ssSpawn;
		ClearSearchSpawn(&ssSpawn);
		ssSpawn.FRadius = MAX_SEARCH_RADIUS;

		int nth = 0;

		if (strchr(szIndex, ',') != nullptr)
		{
			char szTemp[MAX_STRING];
			strcpy_s(szTemp, szIndex);

			char* pSearch = strchr(szTemp, ',');
			*pSearch = 0;
			++pSearch;

			ParseSearchSpawn(pSearch, &ssSpawn);
			nth = GetIntFromString(szIndex, nth);
		}
		else
		{
			if (IsNumberToComma(szIndex))
			{
				nth = GetIntFromString(szIndex, nth);
			}
			else
			{
				nth = 1;
				ParseSearchSpawn(szIndex, &ssSpawn);
			}
		}

		float FRadiusSq = 0.0f;
		bool checkDistance = ssSpawn.FRadius != MAX_SEARCH_RADIUS;
		if (checkDistance)
		{
			FRadiusSq = static_cast<float>(ssSpawn.FRadius * ssSpawn.FRadius);
		}

		for (const MQSpawnArrayItem& spawnItem : gSpawnsArray)
		{
			if (checkDistance && spawnItem.GetDistanceSquared() > FRadiusSq)
			{
				if (!ssSpawn.bKnownLocation)
					return false;
			}

			if (SpawnMatchesSearch(&ssSpawn, pControlledPlayer, spawnItem.GetSpawn()))
			{
				if (--nth == 0)
				{
					Ret = pSpawnType->MakeTypeVar(spawnItem.GetSpawn());
					return true;
				}
			}
		}
	}

	// No spawn
	return false;
}

/*static*/ SPAWNINFO* MQ2SpawnType::GetSpawnPtr(const MQVarPtr& VarPtr)
{
	SPAWNINFO* pSpawn = nullptr;

	if (VarPtr.IsType(MQVarPtr::VariantIdx::ComplexObject))
	{
		const auto& observedSpawn = VarPtr.Get<ObservedSpawnPtr>();
		if (observedSpawn)
		{
			pSpawn = observedSpawn->Ptr();
		}
	}
	else if (VarPtr.IsType(MQVarPtr::VariantIdx::Ptr))
	{
		pSpawn = static_cast<SPAWNINFO*>(VarPtr.Ptr);
	}

	return pSpawn;
}

} // namespace mq::datatypes
