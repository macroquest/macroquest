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
	Invited,
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
	Address,
	Inviter,
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
	IsBerserk,
	pTouchingSwitch,
	bShowHelm,
	CorpseDragCount,
	bBetaBuffed,
	CombatSkillTicks,
	FD,
	InPvPArea,
	bAlwaysShowAura,
	GMRank,
	WarCry,
	IsPassenger,
	LastCastTime,
	DragNames,
	DraggingPlayer,
	bStationary,
	BearingToTarget,
	bTempPet,
	HoldingAnimation,
	Blind,
	LastCastNum,
	CollisionCounter,
	CeilingHeightAtCurrLocation,
	AssistName,
	SeeInvis,
	SpawnStatus,
	bWaitingForPort,
	EQLoc,
	MQLoc,
	TimeBeenDead,
	FloorZ,
	IsSummoned,
	TargetOfTarget,
	ActorDef,
	CachedBuff,
	CachedBuffCount
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
		ScopedTypeMember(SpawnMembers, Invited);
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
		ScopedTypeMember(SpawnMembers, Address);
		ScopedTypeMember(SpawnMembers, Inviter);
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
		ScopedTypeMember(SpawnMembers, IsBerserk);
		ScopedTypeMember(SpawnMembers, pTouchingSwitch);
		ScopedTypeMember(SpawnMembers, bShowHelm);
		ScopedTypeMember(SpawnMembers, CorpseDragCount);
		ScopedTypeMember(SpawnMembers, bBetaBuffed);
		ScopedTypeMember(SpawnMembers, CombatSkillTicks);
		ScopedTypeMember(SpawnMembers, FD);
		ScopedTypeMember(SpawnMembers, InPvPArea);
		ScopedTypeMember(SpawnMembers, bAlwaysShowAura);
		ScopedTypeMember(SpawnMembers, GMRank);
		ScopedTypeMember(SpawnMembers, WarCry);
		ScopedTypeMember(SpawnMembers, IsPassenger);
		ScopedTypeMember(SpawnMembers, LastCastTime);
		ScopedTypeMember(SpawnMembers, DragNames);
		ScopedTypeMember(SpawnMembers, DraggingPlayer);
		ScopedTypeMember(SpawnMembers, bStationary);
		ScopedTypeMember(SpawnMembers, BearingToTarget);
		ScopedTypeMember(SpawnMembers, bTempPet);
		ScopedTypeMember(SpawnMembers, HoldingAnimation);
		ScopedTypeMember(SpawnMembers, Blind);
		ScopedTypeMember(SpawnMembers, LastCastNum);
		ScopedTypeMember(SpawnMembers, CollisionCounter);
		ScopedTypeMember(SpawnMembers, CeilingHeightAtCurrLocation);
		ScopedTypeMember(SpawnMembers, AssistName);
		ScopedTypeMember(SpawnMembers, SeeInvis);
		ScopedTypeMember(SpawnMembers, SpawnStatus);
		ScopedTypeMember(SpawnMembers, bWaitingForPort);
		ScopedTypeMember(SpawnMembers, EQLoc);
		ScopedTypeMember(SpawnMembers, MQLoc);
		ScopedTypeMember(SpawnMembers, TimeBeenDead);
		ScopedTypeMember(SpawnMembers, FloorZ);
		ScopedTypeMember(SpawnMembers, IsSummoned);
		ScopedTypeMember(SpawnMembers, TargetOfTarget);
		ScopedTypeMember(SpawnMembers, ActorDef);
		ScopedTypeMember(SpawnMembers, CachedBuff);
		ScopedTypeMember(SpawnMembers, CachedBuffCount);

		ScopedTypeMethod(SpawnMethods, DoTarget);
		ScopedTypeMethod(SpawnMethods, DoFace);
		ScopedTypeMethod(SpawnMethods, DoAssist);
		ScopedTypeMethod(SpawnMethods, LeftClick);
		ScopedTypeMethod(SpawnMethods, RightClick);
	}

bool MQ2SpawnType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (!VarPtr.Ptr)
		return false;

	SPAWNINFO* pSpawn = static_cast<SPAWNINFO*>(VarPtr.Ptr);
	SPAWNINFO* pMySpawn = pLocalPlayer;
	SPAWNINFO* pControlledSpawn = pCharSpawn;
	PlayerClient* pPlayerClient = reinterpret_cast<PlayerClient*>(pSpawn);

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2SpawnType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<SpawnMethods>(pMethod->ID))
		{
		case SpawnMethods::DoTarget:
			pTarget = pPlayerClient;
			return true;

		case SpawnMethods::DoFace: {
			char szOut[256] = { 0 };
			sprintf_s(szOut, "id %d", pSpawn->SpawnID);
			Face(pMySpawn, szOut);
			return true;
		}

		case SpawnMethods::LeftClick:
			pEverQuest->LeftClickedOnPlayer(pPlayerClient);
			WeDidStuff();
			return true;

		case SpawnMethods::RightClick:
			pEverQuest->RightClickedOnPlayer(pPlayerClient, 0);
			WeDidStuff();
			return true;

		case SpawnMethods::DoAssist: {
			char szOut[256] = { 0 };
			sprintf_s(szOut, "%s", pSpawn->DisplayedName);
			AssistCmd(pMySpawn, szOut);
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
	case SpawnMembers::Address:
		// This is for debugging purposes/correcting struct on patchday
		Dest.DWord = (DWORD)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

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
		CleanupName(DataTypeTemp, sizeof(DataTypeTemp), false, false);
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
		Dest.Type = pSpawnType;
		if (Dest.Ptr = pSpawn->pNext)
		{
			return true;
		}
		return false;

	case SpawnMembers::Prev:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = pSpawn->pPrev)
		{
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
		Dest.Type = pPetType;
		Dest.Ptr = GetSpawnByID(pSpawn->PetID);
		if (!Dest.Ptr)
		{
			// FIXME: Do not ZeroMemory a SPAWNINFO
			ZeroMemory(&PetSpawn, sizeof(PetSpawn));
			strcpy_s(PetSpawn.Name, "NO PET");
			Dest.Ptr = &PetSpawn;
		}
		return true;

	case SpawnMembers::Master:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = GetSpawnByID(pSpawn->MasterID))
		{
			return true;
		}
		return false;

	case SpawnMembers::Gender:
		strcpy_s(DataTypeTemp, szGender[pSpawn->mActorClient.Gender]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpawnMembers::Race:
		Dest.DWord = pSpawn->mActorClient.Race;
		Dest.Type = pRaceType;
		return true;

	case SpawnMembers::Class:
		Dest.DWord = 0;
		Dest.Type = pClassType;

		if (GetSpawnType(pSpawn) != AURA && GetSpawnType(pSpawn) != BANNER && GetSpawnType(pSpawn) != CAMPFIRE)
		{
			Dest.DWord = pSpawn->mActorClient.Class;
		}
		else
		{
			if (GetSpawnType(pSpawn) == AURA)
				Dest.DWord = 0xFF;
			else if (GetSpawnType(pSpawn) == BANNER)
				Dest.DWord = 0xFE;
			else
				Dest.DWord = 0xFD;
		}
		return true;

	case SpawnMembers::Body:
		Dest.DWord = GetBodyType(pSpawn);
		Dest.Type = pBodyType;
		return true;

	case SpawnMembers::GM:
		Dest.DWord = pSpawn->GM;
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Levitating:
		Dest.DWord = (pSpawn->mPlayerPhysicsClient.Levitate == 2);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Sneaking:
		Dest.DWord = pSpawn->Sneak;
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Invis:
		Dest.DWord = pSpawn->HideMode;
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Height:
		Dest.Float = pSpawn->AvatarHeight;
		Dest.Type = pFloatType;
		return true;

	case SpawnMembers::MaxRange:
		Dest.Float = 0;
		Dest.Type = pFloatType;
		if (GetSpawnType(pSpawn) != ITEM)
		{
			Dest.Float = get_melee_range((PlayerClient*)pSpawn, (PlayerClient*)pSpawn);
			return true;
		}
		return false;

	case SpawnMembers::MaxRangeTo:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (GetSpawnType(pSpawn) != ITEM)
		{
			Dest.Float = get_melee_range(pCharSpawn, (PlayerClient*)pSpawn);
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
		DataTypeTemp[0] = 0;
		Dest.Type = pStringType;

		switch (GetSpawnType(pSpawn))
		{
		case MOUNT:
			strcpy_s(DataTypeTemp, "Mount");
			break;
		case UNTARGETABLE:
			strcpy_s(DataTypeTemp, "Untargetable");
			break;
		case NPC:
			strcpy_s(DataTypeTemp, "NPC");
			break;
		case PC:
			strcpy_s(DataTypeTemp, "PC");
			break;
		case CHEST:
			strcpy_s(DataTypeTemp, "Chest");
			break;
		case TRAP:
			strcpy_s(DataTypeTemp, "Trap");
			break;
		case TRIGGER:
			strcpy_s(DataTypeTemp, "Trigger");
			break;
		case TIMER:
			strcpy_s(DataTypeTemp, "Timer");
			break;
		case PET:
			strcpy_s(DataTypeTemp, "Pet");
			break;
		case ITEM:
			strcpy_s(DataTypeTemp, "Item");
			break;
		case CORPSE:
			strcpy_s(DataTypeTemp, "Corpse");
			break;
		case AURA:
			strcpy_s(DataTypeTemp, "Aura");
			break;
		case OBJECT:
			strcpy_s(DataTypeTemp, "Object");
			break;
		case BANNER:
			strcpy_s(DataTypeTemp, "Banner");
			break;
		case CAMPFIRE:
			strcpy_s(DataTypeTemp, "Campfire");
			break;
		case MERCENARY:
			strcpy_s(DataTypeTemp, "Mercenary");
			break;
		case FLYER:
			strcpy_s(DataTypeTemp, "Flyer");
			break;
		}

		if (DataTypeTemp[0] != 0)
		{
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

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
		else if (pSpawn == (SPAWNINFO*)pLocalPlayer && pSpawn->RespawnTimer)
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
		Dest.DWord = pSpawn->StandState == STANDSTATE_STAND;
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Sitting:
		Dest.DWord = pSpawn->StandState == STANDSTATE_SIT;
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::TimeBeenDead:
		Dest.DWord = EQGetTime() - pSpawn->RespawnTimer;
		Dest.Type = pTimeStampType;
		return true;

	case SpawnMembers::IsSummoned: // if its a summoned being (pet for example)
		Dest.DWord = pSpawn->bSummoned;
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::TargetOfTarget:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = GetSpawnByID(pSpawn->TargetOfTarget))
		{
			return true;
		}
		return false;

	case SpawnMembers::Ducking:
		Dest.DWord = pSpawn->StandState == STANDSTATE_DUCK;
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Feigning:
		Dest.DWord = pSpawn->StandState == STANDSTATE_FEIGN;
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Binding:
		Dest.DWord = pSpawn->StandState == STANDSTATE_BIND;
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Dead:
		Dest.DWord = pSpawn->StandState == STANDSTATE_DEAD;
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Stunned:
		Dest.DWord = false;
		if (pSpawn->PlayerState & 0x20)
			Dest.DWord = true;
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Aggressive:
		Dest.DWord = false;
		if (pSpawn->PlayerState & 0x4 || pSpawn->PlayerState & 0x8)
			Dest.DWord = true;
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Hovering:
		Dest.DWord = (pSpawn->RespawnTimer);
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
		Dest.Float = DistanceToSpawn3D(pControlledSpawn, pSpawn);
		Dest.Type = pFloatType;
		return true;

	case SpawnMembers::DistancePredict:
		Dest.Float = EstimatedDistanceToSpawn(pControlledSpawn, pSpawn);
		Dest.Type = pFloatType;
		return true;

	case SpawnMembers::DistanceW:
	case SpawnMembers::DistanceX:
		Dest.Float = (float)fabs(pControlledSpawn->X - pSpawn->X);
		Dest.Type = pFloatType;
		return true;

	case SpawnMembers::DistanceN:
	case SpawnMembers::DistanceY:
		Dest.Float = (float)fabs(pControlledSpawn->Y - pSpawn->Y);
		Dest.Type = pFloatType;
		return true;

	case SpawnMembers::DistanceU:
	case SpawnMembers::DistanceZ:
		Dest.Float = (float)fabs(pControlledSpawn->Z - pSpawn->Z);
		Dest.Type = pFloatType;
		return true;

	case SpawnMembers::HeadingTo:
		Dest.Float = (float)(atan2f(pControlledSpawn->Y - pSpawn->Y, pSpawn->X - pControlledSpawn->X) * 180.0f / PI + 90.0f);
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
		Dest.Type = pSpawnType;
		if (Dest.Ptr = pSpawn->Mount)
		{
			return true;
		}
		return false;

	case SpawnMembers::Underwater:
		Dest.DWord = (pSpawn->UnderWater == 5);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::FeetWet:
		Dest.DWord = (pSpawn->FeetWet == 5);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::PlayerState:
		Dest.DWord = pSpawn->PlayerState;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::Stuck:
		Dest.DWord = pSpawn->PossiblyStuck;
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Animation:
		Dest.DWord = pSpawn->Animation;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::Holding:
		Dest.DWord = false;
		Dest.Type = pBoolType;
		if (pSpawn->LeftHolding || pSpawn->RightHolding)
		{
			Dest.DWord = true;
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

	case SpawnMembers::Invited:
		Dest.DWord = (pSpawn->InvitedToGroup);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Inviter:
		strcpy_s(DataTypeTemp, (char*)__Inviter);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpawnMembers::NearestSpawn:
		Dest.Type = pSpawnType;
		if (pSpawn == pControlledSpawn)
		{
			return (dataNearestSpawn(Index, Dest) != 0); // use top-level object if it's you
		}

		if (Index[0])
		{
			MQSpawnSearch ssSpawn;
			ClearSearchSpawn(&ssSpawn);
			ssSpawn.FRadius = 999999.0f;

			size_t nth = 0;

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

			if (Dest.Ptr = NthNearestSpawn(&ssSpawn, nth, pSpawn))
			{
				return true;
			}
		}
		return false;

	case SpawnMembers::Trader:
		Dest.DWord = pSpawn->Trader;
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::AFK:
		Dest.DWord = pSpawn->AFK;
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::LFG:
		Dest.DWord = pSpawn->LFG;
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Linkdead:
		Dest.DWord = pSpawn->Linkdead;
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::AATitle:  // Leaving this in for older macros/etc.."Title" should be used instead.
	case SpawnMembers::Title:
		strcpy_s(DataTypeTemp, pSpawn->Title);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp;
		return true;

	case SpawnMembers::Suffix:
		strcpy_s(DataTypeTemp, pSpawn->Suffix);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case SpawnMembers::GroupLeader:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (CHARINFO* pCharInfo = GetCharInfo())
		{
			if (pCharInfo->pGroupInfo && pCharInfo->pGroupInfo->pLeader)
			{
				Dest.DWord = pSpawn->Type == SPAWN_PLAYER
					&& !_stricmp(pCharInfo->pGroupInfo->pLeader->Name.c_str(), pSpawn->Name);
				return true;
			}
		}
		return false;

	case SpawnMembers::Assist:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (gGameState == GAMESTATE_INGAME && GetCharInfo()->pSpawn && pSpawn)
		{
			if (DWORD AssistID = GetGroupMainAssistTargetID())
			{
				if (AssistID == pSpawn->SpawnID)
				{
					Dest.DWord = 1;
					return true;
				}
			}

			for (int nAssist = 0; nAssist < 3; nAssist++)
			{
				if (DWORD AssistID = GetRaidMainAssistTargetID(nAssist))
				{
					if (AssistID == pSpawn->SpawnID) {
						Dest.DWord = 1;
						return true;
					}
				}
			}
		}
		return true;

	case SpawnMembers::Mark:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (gGameState == GAMESTATE_INGAME && GetCharInfo()->pSpawn && pSpawn)
		{
			for (int nMark = 0; nMark < 3; nMark++)
			{
				if (GetCharInfo()->pSpawn->RaidMarkNPC[nMark] == pSpawn->SpawnID)
				{
					Dest.DWord = nMark + 1;
					return true;
				}
			}

			for (int nMark = 0; nMark < 3; nMark++)
			{
				if (GetCharInfo()->pSpawn->GroupMarkNPC[nMark] == pSpawn->SpawnID)
				{
					Dest.DWord = nMark + 1;
					return true;
				}
			}
		}
		return false;

	case SpawnMembers::Anonymous:
		Dest.DWord = (pSpawn->Anon == 1);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Roleplaying:
		Dest.DWord = (pSpawn->Anon == 2);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::LineOfSight:
		Dest.DWord = pCharSpawn->CanSee(*pPlayerClient);
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
		Dest.DWord = IsMobFleeing(GetCharInfo()->pSpawn, pSpawn);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Named:
		Dest.DWord = IsNamed(pSpawn);
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Buyer:
		Dest.DWord = pSpawn->Buyer;
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::Moving:
		Dest.DWord = fabs(pSpawn->SpeedRun) > 0.0f;
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
		Dest.Type = pSpawnType;
		if (pSpawn->Mercenary)
		{
			size_t pos = strchr(pSpawn->Lastname, '\'') - &pSpawn->Lastname[0];
			strncpy_s(DataTypeTemp, pSpawn->Lastname, pos);

			DataTypeTemp[pos] = 0;

			if (SPAWNINFO* pOwner = (SPAWNINFO*)GetSpawnByName(DataTypeTemp))
			{
				Dest.Ptr = pOwner;
				return true;
			}
		}
		return false;

	case SpawnMembers::Following:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = pSpawn->WhoFollowing)
		{
			return true;
		}
		return false;

	case SpawnMembers::MercID:
		Dest.DWord = pSpawn->MercID;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::ContractorID:
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
		Dest.DWord = pSpawn->Targetable;
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::CanSplashLand: {
		CVector3 sv3;
		sv3.X = pSpawn->Y;
		sv3.Y = pSpawn->X;
		sv3.Z = pSpawn->Z;
		Dest.DWord = pCharSpawn->CanSee(sv3);
		Dest.Type = pBoolType;
		return true;
	}

	case SpawnMembers::IsBerserk:
		Dest.DWord = pSpawn->berserker;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::pTouchingSwitch:
		Dest.DWord = (DWORD)pSpawn->pTouchingSwitch;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::bShowHelm:
		Dest.DWord = pSpawn->bShowHelm;
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::CorpseDragCount:
		Dest.DWord = pSpawn->CorpseDragCount;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::bBetaBuffed:
		Dest.DWord = pSpawn->bBetaBuffed;
		Dest.Type = pBoolType;
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

	case SpawnMembers::FD:
		Dest.DWord = pSpawn->FD;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::InPvPArea:
		Dest.DWord = pSpawn->InPvPArea;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::bAlwaysShowAura:
		Dest.DWord = pSpawn->bAlwaysShowAura;
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::GMRank:
		Dest.DWord = pSpawn->GMRank;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::WarCry:
		Dest.DWord = pSpawn->WarCry;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::IsPassenger:
		Dest.DWord = pSpawn->IsPassenger;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::LastCastTime:
		Dest.DWord = pSpawn->LastCastTime;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::DragNames:
		Dest.Type = pStringType;

		if (IsNumber(Index))
		{
			int index = GetIntFromString(Index, 0);
			if (index < 0)
				index = 0;
			if (index > 1)
				index = 1;
			strcpy_s(DataTypeTemp, pSpawn->DragNames[index]);
			Dest.Ptr = DataTypeTemp;
			return true;
		}
		return false;

	case SpawnMembers::DraggingPlayer:
		strcpy_s(DataTypeTemp, pSpawn->DraggingPlayer);
		Dest.Ptr = DataTypeTemp;
		Dest.Type = pStringType;

	case SpawnMembers::bStationary:
		Dest.DWord = pSpawn->bStationary;
		Dest.Type = pBoolType;
		return true;

	case SpawnMembers::BearingToTarget:
		Dest.Float = pSpawn->BearingToTarget;
		Dest.Type = pFloatType;
		return true;

	case SpawnMembers::bTempPet:
		Dest.DWord = pSpawn->bTempPet;
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

	case SpawnMembers::LastCastNum:
		Dest.DWord = pSpawn->LastCastNum;
		Dest.Type = pIntType;
		return true;

	case SpawnMembers::CollisionCounter:
		Dest.DWord = pSpawn->CollisionCounter;
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
			int index = GetIntFromString(Index, 0);
			if (index < 0)
				index = 0;
			if (index > 2)
				index = 2;
			Dest.DWord = pSpawn->SeeInvis[index];
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

	case SpawnMembers::bWaitingForPort:
		Dest.DWord = pSpawn->bWaitingForPort;
		Dest.Type = pBoolType;
		return true;

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
				Dest.HighPart = GetCachedBuff(pSpawn, AllBuffs([&Index](CachedBuff buff) { return GetIntFromString(Index, 0) == buff.spellId; }));
			else
			{
				if (Index[0] == '#') // by buff slot
					Dest.HighPart = GetCachedBuff(pSpawn, AllBuffs([&Index](CachedBuff buff) { return GetIntFromString(&Index[1], 0) - 1 == buff.slot; }));
				else if (Index[0] == '*') // by buff index
					Dest.HighPart = GetCachedBuffAt(pSpawn, GetIntFromString(&Index[1], 0) - 1);
				else if (Index[0] == '^') // by keyword
				{
					if (ci_equals(&Index[1], "slowed"))
						Dest.HighPart = GetCachedBuff(pSpawn, AllBuffs(SpellAffect(SPA_HASTE, false)));
					else if (ci_equals(&Index[1], "rooted"))
						Dest.HighPart = GetCachedBuff(pSpawn, AllBuffs(SpellAffect(SPA_ROOT, false)));
					else if (ci_equals(&Index[1], "mezzed"))
						Dest.HighPart = GetCachedBuff(pSpawn, AllBuffs(SpellAffect(SPA_ENTHRALL, false)));
					else if (ci_equals(&Index[1], "crippled"))
						Dest.HighPart = GetCachedBuff(pSpawn, AllBuffs(SpellSubCat(SPELLCAT_DISEMPOWERING)));
					else if (ci_equals(&Index[1], "maloed"))
						Dest.HighPart = GetCachedBuff(pSpawn, AllBuffs(SpellSubCat(SPELLCAT_RESIST_DEBUFFS), SpellClassMask(Shaman, Mage)));
					else if (ci_equals(&Index[1], "tashed"))
						Dest.HighPart = GetCachedBuff(pSpawn, AllBuffs(SpellSubCat(SPELLCAT_RESIST_DEBUFFS), SpellClassMask(Enchanter)));
					else if (ci_equals(&Index[1], "snared"))
						Dest.HighPart = GetCachedBuff(pSpawn, AllBuffs(SpellAffect(SPA_MOVEMENT_RATE, false)));
					else if (ci_equals(&Index[1], "beneficial"))
						Dest.HighPart = GetCachedBuff(pSpawn, [](CachedBuff buff) -> bool
							{
								auto pSpell = GetSpellByID(buff.spellId);
								return pSpell && pSpell->SpellType != 0;
							});
				}
				else
					 Dest.HighPart = GetCachedBuff(pSpawn, [&Index](CachedBuff buff)
						{
							return ci_starts_with(GetSpellNameByID(buff.spellId), Index);
						});
			}
		}

		return Dest.HighPart >= 0;

	case SpawnMembers::CachedBuffCount:
		Dest.Type = pIntType;
		Dest.DWord =  GetCachedBuffCount(pSpawn);
		return true;

	default:
		return false;
	}
}

bool MQ2SpawnType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (!VarPtr.Ptr)
		return false;

	SPAWNINFO* pSpawn = static_cast<SPAWNINFO*>(VarPtr.Ptr);
	strcpy_s(Destination, MAX_STRING, pSpawn->Name);
	return true;
}

void MQ2SpawnType::InitVariable(MQVarPtr& VarPtr)
{
	// FIXME: Do not Allocate a SPAWNINFO
	VarPtr.Ptr = new SPAWNINFO();
	VarPtr.HighPart = 0;

	// FIXME: Do not ZeroMemory a SPAWNINFO
	ZeroMemory(VarPtr.Ptr, sizeof(SPAWNINFO));
}

void MQ2SpawnType::FreeVariable(MQVarPtr& VarPtr)
{
	// FIXME: Find way to not allocate SPAWNINFO
	SPAWNINFO* pSpawn = static_cast<SPAWNINFO*>(VarPtr.Ptr);
	delete pSpawn;
}

bool MQ2SpawnType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	if (Source.Type == pSpawnType)
	{
		memcpy(VarPtr.Ptr, Source.Ptr, sizeof(SPAWNINFO));
		return true;
	}
	else
	{
		if (SPAWNINFO* pOther = (SPAWNINFO*)GetSpawnByID(Source.DWord))
		{
			memcpy(VarPtr.Ptr, pOther, sizeof(SPAWNINFO));
			return true;
		}
	}
	return false;
}

bool MQ2SpawnType::FromString(MQVarPtr& VarPtr, char* Source)
{
	if (SPAWNINFO* pOther = (SPAWNINFO*)GetSpawnByID(GetIntFromString(Source, 0)))
	{
		memcpy(VarPtr.Ptr, pOther, sizeof(SPAWNINFO));
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
			if ((Ret.Ptr = GetSpawnByID(GetIntFromString(szIndex, 0))))
			{
				Ret.Type = pSpawnType;
				return true;
			}
		}
		else
		{
			// set up search spawn
			MQSpawnSearch ssSpawn;
			ClearSearchSpawn(&ssSpawn);
			ParseSearchSpawn(szIndex, &ssSpawn);
			if (Ret.Ptr = SearchThroughSpawns(&ssSpawn, (SPAWNINFO*)pCharSpawn))
			{
				Ret.Type = pSpawnType;
				return true;
			}
		}
	}
	// No spawn

	return false;
}

bool MQ2SpawnType::dataSpawnCount(const char* szIndex, MQTypeVar& Ret)
{
	if (szIndex[0])
	{
		MQSpawnSearch ssSpawn;
		ClearSearchSpawn(&ssSpawn);
		ParseSearchSpawn(szIndex, &ssSpawn);
		Ret.DWord = CountMatchingSpawns(&ssSpawn, GetCharInfo()->pSpawn, TRUE);
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
						return false;
					index--;
				}
				Ret.Ptr = pSpawn;
				Ret.Type = pSpawnType;
				return true;
			}
		}
	}
	else
	{
		Ret.Ptr = pSpawnList;
		Ret.Type = pSpawnType;
		return true;
	}
	return false;
}

bool MQ2SpawnType::dataNearestSpawn(const char* szIndex, MQTypeVar& Ret)
{
	if (szIndex[0])
	{
		MQSpawnSearch ssSpawn;
		ClearSearchSpawn(&ssSpawn);
		ssSpawn.FRadius = 999999.0f;

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

		for (int index = 0; index < gSpawnCount; index++)
		{
			if (EQP_DistArray[index].Value.Float > ssSpawn.FRadius && !ssSpawn.bKnownLocation)
				return false;

			if (SpawnMatchesSearch(&ssSpawn, (SPAWNINFO*)pCharSpawn, (SPAWNINFO*)EQP_DistArray[index].VarPtr.Ptr))
			{
				if (--nth == 0)
				{
					Ret.Ptr = EQP_DistArray[index].VarPtr.Ptr;
					Ret.Type = pSpawnType;
					return true;
				}
			}
		}
	}

	// No spawn
	return false;
}

bool MQ2SpawnType::dataDoorTarget(const char* szIndex, MQTypeVar& Ret)
{
	if (Ret.Ptr = &DoorEnviroTarget)
	{
		Ret.Type = pSpawnType;
		return true;
	}
	return false;
}

bool MQ2SpawnType::dataItemTarget(const char* szIndex, MQTypeVar& Ret)
{
	if (Ret.Ptr = &EnviroTarget)
	{
		Ret.Type = pSpawnType;
		return true;
	}
	return false;
}

