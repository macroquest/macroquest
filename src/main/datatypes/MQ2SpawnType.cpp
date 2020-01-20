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
		case DoTarget:
			pTarget = pPlayerClient;
			return true;

		case DoFace: {
			char szOut[256] = { 0 };
			sprintf_s(szOut, "id %d", pSpawn->SpawnID);
			Face(pMySpawn, szOut);
			return true;
		}

		case LeftClick:
			pEverQuest->LeftClickedOnPlayer(pPlayerClient);
			WeDidStuff();
			return true;

		case RightClick:
			pEverQuest->RightClickedOnPlayer(pPlayerClient, 0);
			WeDidStuff();
			return true;

		case DoAssist: {
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
	case Address:
		// This is for debugging purposes/correcting struct on patchday
		Dest.DWord = (DWORD)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case Level:
		Dest.DWord = pSpawn->Level;
		Dest.Type = pIntType;
		return true;

	case ID:
		Dest.Type = pIntType;
		Dest.DWord = pSpawn->SpawnID;
		return true;

	case Name:
		strcpy_s(DataTypeTemp, pSpawn->Name);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case Surname:
		strcpy_s(DataTypeTemp, pSpawn->Lastname);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case CleanName:
		strcpy_s(DataTypeTemp, pSpawn->Name);
		CleanupName(DataTypeTemp, sizeof(DataTypeTemp), false, false);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case DisplayName:
		strcpy_s(DataTypeTemp, pSpawn->DisplayedName);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case E:
		Dest.Type = pFloatType;
		Dest.Float = -pSpawn->X;
		return true;

	case W:
	case X:
		Dest.Type = pFloatType;
		Dest.Float = pSpawn->X;
		return true;

	case S:
		Dest.Type = pFloatType;
		Dest.Float = -pSpawn->Y;
		return true;

	case N:
	case Y:
		Dest.Type = pFloatType;
		Dest.Float = pSpawn->Y;
		return true;

	case D:
		Dest.Type = pFloatType;
		Dest.Float = -pSpawn->Z;
		return true;

	case U:
	case Z:
		Dest.Type = pFloatType;
		Dest.Float = pSpawn->Z;
		return true;

	case FloorZ:
		Dest.Type = pFloatType;
		Dest.Float = pSpawn->FloorHeight;
		return true;

	case Next:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = pSpawn->pNext)
		{
			return true;
		}
		return false;

	case Prev:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = pSpawn->pPrev)
		{
			return true;
		}
		return false;

	case CurrentHPs:
		Dest.Type = pInt64Type;
		Dest.Int64 = pSpawn->HPCurrent;
		return true;

	case MaxHPs:
		Dest.Type = pInt64Type;
		Dest.Int64 = pSpawn->HPMax;
		return true;

	case PctHPs:
		// avoid dividing by zero!
		Dest.Int64 = pSpawn->HPMax == 0 ? 0 : pSpawn->HPCurrent / pSpawn->HPMax * 100;
		Dest.Type = pInt64Type;
		return true;

	case AARank:
		Dest.Type = pIntType;
		Dest.Int = 0;
		if (pSpawn->AARank != 0xFF)
			Dest.Int = pSpawn->AARank;
		return true;

	case Speed:
		Dest.Float = FindSpeed(pSpawn);
		Dest.Type = pFloatType;
		return true;

	case Heading:
		Dest.Float = pSpawn->Heading * 0.703125f; // Convert from EQ heading to degrees (180 / 250)
		Dest.Type = pHeadingType;
		return true;

	case Pet:
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

	case Master:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = GetSpawnByID(pSpawn->MasterID))
		{
			return true;
		}
		return false;

	case Gender:
		strcpy_s(DataTypeTemp, szGender[pSpawn->mActorClient.Gender]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Race:
		Dest.DWord = pSpawn->mActorClient.Race;
		Dest.Type = pRaceType;
		return true;

	case Class:
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

	case Body:
		Dest.DWord = GetBodyType(pSpawn);
		Dest.Type = pBodyType;
		return true;

	case GM:
		Dest.DWord = pSpawn->GM;
		Dest.Type = pBoolType;
		return true;

	case Levitating:
		Dest.DWord = (pSpawn->mPlayerPhysicsClient.Levitate == 2);
		Dest.Type = pBoolType;
		return true;

	case Sneaking:
		Dest.DWord = pSpawn->Sneak;
		Dest.Type = pBoolType;
		return true;

	case Invis:
		Dest.DWord = pSpawn->HideMode;
		Dest.Type = pBoolType;
		return true;

	case Height:
		Dest.Float = pSpawn->AvatarHeight;
		Dest.Type = pFloatType;
		return true;

	case MaxRange:
		Dest.Float = 0;
		Dest.Type = pFloatType;
		if (GetSpawnType(pSpawn) != ITEM)
		{
			Dest.Float = get_melee_range((PlayerClient*)pSpawn, (PlayerClient*)pSpawn);
			return true;
		}
		return false;

	case MaxRangeTo:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (GetSpawnType(pSpawn) != ITEM)
		{
			Dest.Float = get_melee_range(pCharSpawn, (PlayerClient*)pSpawn);
			return true;
		}
		return false;

	case Guild:
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

	case Type:
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

	case Light:
		strcpy_s(DataTypeTemp, GetLightForSpawn(pSpawn));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case StandState:
		Dest.Int = pSpawn->StandState;
		Dest.Type = pIntType;
		return true;

	case State:
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

	case Standing:
		Dest.DWord = pSpawn->StandState == STANDSTATE_STAND;
		Dest.Type = pBoolType;
		return true;

	case Sitting:
		Dest.DWord = pSpawn->StandState == STANDSTATE_SIT;
		Dest.Type = pBoolType;
		return true;

	case TimeBeenDead:
		Dest.DWord = EQGetTime() - pSpawn->RespawnTimer;
		Dest.Type = pTimeStampType;
		return true;

	case IsSummoned: // if its a summoned being (pet for example)
		Dest.DWord = pSpawn->bSummoned;
		Dest.Type = pBoolType;
		return true;

	case TargetOfTarget:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = GetSpawnByID(pSpawn->TargetOfTarget))
		{
			return true;
		}
		return false;

	case Ducking:
		Dest.DWord = pSpawn->StandState == STANDSTATE_DUCK;
		Dest.Type = pBoolType;
		return true;

	case Feigning:
		Dest.DWord = pSpawn->StandState == STANDSTATE_FEIGN;
		Dest.Type = pBoolType;
		return true;

	case Binding:
		Dest.DWord = pSpawn->StandState == STANDSTATE_BIND;
		Dest.Type = pBoolType;
		return true;

	case Dead:
		Dest.DWord = pSpawn->StandState == STANDSTATE_DEAD;
		Dest.Type = pBoolType;
		return true;

	case Stunned:
		Dest.DWord = false;
		if (pSpawn->PlayerState & 0x20)
			Dest.DWord = true;
		Dest.Type = pBoolType;
		return true;

	case Aggressive:
		Dest.DWord = false;
		if (pSpawn->PlayerState & 0x4 || pSpawn->PlayerState & 0x8)
			Dest.DWord = true;
		Dest.Type = pBoolType;
		return true;

	case Hovering:
		Dest.DWord = (pSpawn->RespawnTimer);
		Dest.Type = pBoolType;
		return true;

	case Deity:
		Dest.DWord = pSpawn->Deity;
		Dest.Type = pDeityType;
		return true;

	case Distance:
		Dest.Float = GetDistance(pSpawn->X, pSpawn->Y);
		Dest.Type = pFloatType;
		return true;

	case Distance3D:
		Dest.Float = DistanceToSpawn3D(pControlledSpawn, pSpawn);
		Dest.Type = pFloatType;
		return true;

	case DistancePredict:
		Dest.Float = EstimatedDistanceToSpawn(pControlledSpawn, pSpawn);
		Dest.Type = pFloatType;
		return true;

	case DistanceW:
	case DistanceX:
		Dest.Float = (float)fabs(pControlledSpawn->X - pSpawn->X);
		Dest.Type = pFloatType;
		return true;

	case DistanceN:
	case DistanceY:
		Dest.Float = (float)fabs(pControlledSpawn->Y - pSpawn->Y);
		Dest.Type = pFloatType;
		return true;

	case DistanceU:
	case DistanceZ:
		Dest.Float = (float)fabs(pControlledSpawn->Z - pSpawn->Z);
		Dest.Type = pFloatType;
		return true;

	case HeadingTo:
		Dest.Float = (float)(atan2f(pControlledSpawn->Y - pSpawn->Y, pSpawn->X - pControlledSpawn->X) * 180.0f / PI + 90.0f);
		if (Dest.Float < 0.0f)
			Dest.Float += 360.0f;
		else if (Dest.Float >= 360.0f)
			Dest.Float -= 360.0f;
		Dest.Type = pHeadingType;
		return true;

	case Casting:
		Dest.Type = pSpellType;
		if (Dest.Ptr = GetSpellByID(pSpawn->CastingData.SpellID))
		{
			return true;
		}
		return false;

	case Mount:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = pSpawn->Mount)
		{
			return true;
		}
		return false;

	case Underwater:
		Dest.DWord = (pSpawn->UnderWater == 5);
		Dest.Type = pBoolType;
		return true;

	case FeetWet:
		Dest.DWord = (pSpawn->FeetWet == 5);
		Dest.Type = pBoolType;
		return true;

	case PlayerState:
		Dest.DWord = pSpawn->PlayerState;
		Dest.Type = pIntType;
		return true;

	case Stuck:
		Dest.DWord = pSpawn->PossiblyStuck;
		Dest.Type = pBoolType;
		return true;

	case Animation:
		Dest.DWord = pSpawn->Animation;
		Dest.Type = pIntType;
		return true;

	case Holding:
		Dest.DWord = false;
		Dest.Type = pBoolType;
		if (pSpawn->LeftHolding || pSpawn->RightHolding)
		{
			Dest.DWord = true;
		}
		return true;

	case Look:
		Dest.Float = pSpawn->CameraAngle;
		Dest.Type = pFloatType;
		return true;

	case xConColor:
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

	case Invited:
		Dest.DWord = (pSpawn->InvitedToGroup);
		Dest.Type = pBoolType;
		return true;

	case Inviter:
		strcpy_s(DataTypeTemp, (char*)__Inviter);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case NearestSpawn:
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

	case Trader:
		Dest.DWord = pSpawn->Trader;
		Dest.Type = pBoolType;
		return true;

	case AFK:
		Dest.DWord = pSpawn->AFK;
		Dest.Type = pBoolType;
		return true;

	case LFG:
		Dest.DWord = pSpawn->LFG;
		Dest.Type = pBoolType;
		return true;

	case Linkdead:
		Dest.DWord = pSpawn->Linkdead;
		Dest.Type = pBoolType;
		return true;

	case AATitle:  // Leaving this in for older macros/etc.."Title" should be used instead.
	case Title:
		strcpy_s(DataTypeTemp, pSpawn->Title);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp;
		return true;

	case Suffix:
		strcpy_s(DataTypeTemp, pSpawn->Suffix);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case xGroupLeader:
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

	case Assist:
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

	case Mark:
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

	case Anonymous:
		Dest.DWord = (pSpawn->Anon == 1);
		Dest.Type = pBoolType;
		return true;

	case Roleplaying:
		Dest.DWord = (pSpawn->Anon == 2);
		Dest.Type = pBoolType;
		return true;

	case xLineOfSight:
		Dest.DWord = pCharSpawn->CanSee(*pPlayerClient);
		Dest.Type = pBoolType;
		return true;

	case HeadingToLoc:
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

	case Fleeing:
		Dest.DWord = IsMobFleeing(GetCharInfo()->pSpawn, pSpawn);
		Dest.Type = pBoolType;
		return true;

	case Named:
		Dest.DWord = IsNamed(pSpawn);
		Dest.Type = pBoolType;
		return true;

	case Buyer:
		Dest.DWord = pSpawn->Buyer;
		Dest.Type = pBoolType;
		return true;

	case Moving:
		Dest.DWord = fabs(pSpawn->SpeedRun) > 0.0f;
		Dest.Type = pBoolType;
		return true;

	case CurrentMana:
		Dest.DWord = pSpawn->GetCurrentMana();
		Dest.Type = pIntType;
		return true;

	case MaxMana:
		Dest.DWord = pSpawn->GetMaxMana();
		Dest.Type = pIntType;
		return true;

	case PctMana:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (int maxmana = pSpawn->GetMaxMana())
			Dest.Int = pSpawn->GetCurrentMana() * 100 / maxmana;
		return true;

	case CurrentEndurance:
		Dest.DWord = pSpawn->GetCurrentEndurance();
		Dest.Type = pIntType;
		return true;

	case PctEndurance:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (int maxend = pSpawn->GetMaxEndurance())
			Dest.Int = pSpawn->GetCurrentEndurance() * 100 / maxend;
		return true;

	case MaxEndurance:
		Dest.DWord = pSpawn->GetMaxEndurance();
		Dest.Type = pIntType;
		return true;

	case Loc:
		sprintf_s(DataTypeTemp, "%.2f, %.2f", pSpawn->Y, pSpawn->X);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case LocYX:
		sprintf_s(DataTypeTemp, "%.0f, %.0f", pSpawn->Y, pSpawn->X);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case LocYXZ:
		sprintf_s(DataTypeTemp, "%.2f, %.2f, %.2f", pSpawn->Y, pSpawn->X, pSpawn->Z);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case EQLoc:
		sprintf_s(DataTypeTemp, "%.2f, %.2f, %.2f", pSpawn->X, pSpawn->Y, pSpawn->Z);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case MQLoc:
		sprintf_s(DataTypeTemp, "%.2f, %.2f, %.2f", pSpawn->Y, pSpawn->X, pSpawn->Z);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Owner:
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

	case Following:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = pSpawn->WhoFollowing)
		{
			return true;
		}
		return false;

	case MercID:
		Dest.DWord = pSpawn->MercID;
		Dest.Type = pIntType;
		return true;

	case ContractorID:
		Dest.DWord = pSpawn->ContractorID;
		Dest.Type = pIntType;
		return true;

	case Primary:
		Dest.DWord = pSpawn->Equipment.Primary.ID;
		Dest.Type = pIntType;
		return true;

	case Secondary:
		Dest.DWord = pSpawn->Equipment.Offhand.ID;
		Dest.Type = pIntType;
		return true;

	case Equipment:
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

	case xTargetable:
		Dest.DWord = pSpawn->Targetable;
		Dest.Type = pBoolType;
		return true;

	case CanSplashLand: {
		CVector3 sv3;
		sv3.X = pSpawn->Y;
		sv3.Y = pSpawn->X;
		sv3.Z = pSpawn->Z;
		Dest.DWord = pCharSpawn->CanSee(sv3);
		Dest.Type = pBoolType;
		return true;
	}

	case IsBerserk:
		Dest.DWord = pSpawn->berserker;
		Dest.Type = pIntType;
		return true;

	case pTouchingSwitch:
		Dest.DWord = (DWORD)pSpawn->pTouchingSwitch;
		Dest.Type = pIntType;
		return true;

	case bShowHelm:
		Dest.DWord = pSpawn->bShowHelm;
		Dest.Type = pBoolType;
		return true;

	case CorpseDragCount:
		Dest.DWord = pSpawn->CorpseDragCount;
		Dest.Type = pIntType;
		return true;

	case bBetaBuffed:
		Dest.DWord = pSpawn->bBetaBuffed;
		Dest.Type = pBoolType;
		return true;

	case CombatSkillTicks:
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

	case FD:
		Dest.DWord = pSpawn->FD;
		Dest.Type = pIntType;
		return true;

	case InPvPArea:
		Dest.DWord = pSpawn->InPvPArea;
		Dest.Type = pIntType;
		return true;

	case bAlwaysShowAura:
		Dest.DWord = pSpawn->bAlwaysShowAura;
		Dest.Type = pBoolType;
		return true;

	case GMRank:
		Dest.DWord = pSpawn->GMRank;
		Dest.Type = pIntType;
		return true;

	case WarCry:
		Dest.DWord = pSpawn->WarCry;
		Dest.Type = pIntType;
		return true;

	case IsPassenger:
		Dest.DWord = pSpawn->IsPassenger;
		Dest.Type = pIntType;
		return true;

	case LastCastTime:
		Dest.DWord = pSpawn->LastCastTime;
		Dest.Type = pIntType;
		return true;

	case DragNames:
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

	case DraggingPlayer:
		strcpy_s(DataTypeTemp, pSpawn->DraggingPlayer);
		Dest.Ptr = DataTypeTemp;
		Dest.Type = pStringType;

	case bStationary:
		Dest.DWord = pSpawn->bStationary;
		Dest.Type = pBoolType;
		return true;

	case BearingToTarget:
		Dest.Float = pSpawn->BearingToTarget;
		Dest.Type = pFloatType;
		return true;

	case bTempPet:
		Dest.DWord = pSpawn->bTempPet;
		Dest.Type = pBoolType;
		return true;

	case HoldingAnimation:
		Dest.DWord = pSpawn->HoldingAnimation;
		Dest.Type = pIntType;
		return true;

	case Blind:
		Dest.DWord = pSpawn->Blind;
		Dest.Type = pIntType;
		return true;

	case LastCastNum:
		Dest.DWord = pSpawn->LastCastNum;
		Dest.Type = pIntType;
		return true;

	case CollisionCounter:
		Dest.DWord = pSpawn->CollisionCounter;
		Dest.Type = pIntType;
		return true;

	case CeilingHeightAtCurrLocation:
		Dest.Float = pSpawn->CeilingHeightAtCurrLocation;
		Dest.Type = pFloatType;
		return true;

	case AssistName:
		strcpy_s(DataTypeTemp, pSpawn->AssistName);
		Dest.Ptr = DataTypeTemp;
		Dest.Type = pStringType;
		return true;

	case SeeInvis:
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

	case SpawnStatus:
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

	case bWaitingForPort:
		Dest.DWord = pSpawn->bWaitingForPort;
		Dest.Type = pBoolType;
		return true;

	case ActorDef:
		strcpy_s(DataTypeTemp, pSpawn->mActorClient.ActorDef);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case CachedBuff: {
		// TODO: Extract to a function
		Dest.Type = pCachedBuffType;

		if (CachedBuffsMap.empty())
			return false;

		int SpellID = 0;
		bool bBySlot = false;
		bool bByIndex = false;
		bool bByKeyword = false;
		char* pIndex = Index;

		if (pIndex[0])
		{
			if (IsNumber(Index))
			{
				// by spell ID
				SpellID = GetIntFromString(Index, SpellID);
			}
			else
			{
				bool bExact = false;
				if (*pIndex == '#')
				{
					// by buff slot
					bBySlot = true;
					pIndex++;
				}
				else if (*pIndex == '*')
				{
					// by buff index
					bByIndex = true;
					pIndex++;
				}
				else if (*pIndex == '^')
				{
					// by keyword
					bByKeyword = true;
					pIndex++;
				}
				else
				{
					// by spell name
					if (SPELL* pSpell = GetSpellByName(pIndex))
					{
						SpellID = pSpell->ID;
					}
				}
			}

			if (SpellID)
			{
				auto ps = CachedBuffsMap.find(pSpawn->SpawnID);
				if (ps != CachedBuffsMap.end())
				{
					for (auto& [buffSpellId, targetBuff] : ps->second)
					{
						if (buffSpellId == SpellID)
						{
							TargetBuffTemp = targetBuff;
							return true;
						}
					}
				}
			}
			else if (bBySlot)
			{
				int idx = GetIntFromString(pIndex, 0) - 1;

				auto ps = CachedBuffsMap.find(pSpawn->SpawnID);
				if (ps != CachedBuffsMap.end())
				{
					const auto& buffs = ps->second;
					idx = std::clamp(idx, 0, NUM_BUFF_SLOTS);

					for (auto& [buffSpellId, targetBuff] : buffs)
					{
						if (targetBuff.slot == idx)
						{
							TargetBuffTemp = targetBuff;
							Dest.Ptr = &TargetBuffTemp;
							return true;
						}
					}
				}
			}
			else if (bByIndex)
			{
				int idx = GetIntFromString(pIndex, 0) - 1;

				auto ps = CachedBuffsMap.find(pSpawn->SpawnID);
				if (ps != CachedBuffsMap.end())
				{
					if (idx < 0)
						idx = 0;

					if (idx >= (int)ps->second.size())
					{
						return false;
					}

					auto iter = ps->second.begin();
					std::advance(iter, idx);

					if (iter != ps->second.end())
					{
						TargetBuffTemp = iter->second;
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
				}
			}
			else if (bByKeyword)
			{
				int type = -1;
				if (!_stricmp(pIndex, "Slowed"))
				{
					Dest.Ptr = nullptr;
					Dest.Type = pCachedBuffType;

					if (HasCachedTargetBuffSPA(SPA_HASTE, false, pSpawn, &TargetBuffTemp))
					{
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
					return false;
				}

				if (!_stricmp(pIndex, "Rooted"))
				{
					Dest.Ptr = nullptr;
					Dest.Type = pCachedBuffType;
					if (HasCachedTargetBuffSPA(SPA_ROOT, false, pSpawn, &TargetBuffTemp))
					{
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
					return false;
				}

				if (!_stricmp(pIndex, "Mezzed"))
				{
					Dest.Ptr = nullptr;
					Dest.Type = pCachedBuffType;
					if (HasCachedTargetBuffSPA(SPA_ENTHRALL, false, pSpawn, &TargetBuffTemp))
					{
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
					return false;
				}

				if (!_stricmp(pIndex, "Crippled"))
				{
					Dest.Ptr = nullptr;
					Dest.Type = pCachedBuffType;
					if (HasCachedTargetBuffSubCat("Disempowering", pSpawn, &TargetBuffTemp))
					{
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
					return false;
				}

				if (!_stricmp(pIndex, "Maloed"))
				{
					Dest.Ptr = nullptr;
					Dest.Type = pCachedBuffType;
					//GetTargetBuffBySubCat("Resist Debuffs", (1 << Shaman) + (1 << Mage));
					if (HasCachedTargetBuffSubCat("Resist Debuffs", pSpawn, &TargetBuffTemp, (1 << Shaman) + (1 << Mage)))
					{
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
					return false;
				}

				if (!_stricmp(pIndex, "Tashed"))
				{
					Dest.Ptr = nullptr;
					Dest.Type = pCachedBuffType;
					if (HasCachedTargetBuffSubCat("Resist Debuffs", pSpawn, &TargetBuffTemp, 1 << Enchanter))
					{
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
					return false;
				}

				if (!_stricmp(pIndex, "Snared"))
				{
					Dest.Ptr = nullptr;
					Dest.Type = pCachedBuffType;
					if (HasCachedTargetBuffSPA(SPA_MOVEMENT_RATE, false, pSpawn, &TargetBuffTemp))
					{
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
					return false;
				}

				if (!_stricmp(pIndex, "Beneficial"))
				{
					Dest.Ptr = nullptr;
					Dest.Type = pCachedBuffType;

					auto ps = CachedBuffsMap.find(pSpawn->SpawnID);
					if (ps != CachedBuffsMap.end())
					{
						for (const auto& [spellId, buff] : ps->second)
						{
							if (SPELL* pSpell = GetSpellByID(spellId))
							{
								if (pSpell->SpellType != 0)
								{
									// targetwindow has a leak in it player buffs shows up in it
									// so we need to make sure its not a "leaked buff"
									if (SPAWNINFO* pPlayer = (SPAWNINFO*)GetSpawnByName(buff.casterName))
									{
										if (pPlayer->Type == SPAWN_PLAYER)
										{
											continue;
										}
									}

									TargetBuffTemp = buff;
									Dest.Ptr = &TargetBuffTemp;
									return true;
								}
							}
						}
					}
					return false;
				}
			}
		}
		return false;
	}

	case CachedBuffCount: {
		Dest.Type = pIntType;
		Dest.DWord = -1;
		auto ps = CachedBuffsMap.find(pSpawn->SpawnID);
		if (ps != CachedBuffsMap.end())
		{
			Dest.DWord = ps->second.size();
		}
		return true;
	}

	default: break;
	}

	return false;
}

