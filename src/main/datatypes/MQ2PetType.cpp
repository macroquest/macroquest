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

enum class PetMembers
{
	Buff,
	Combat,
	GHold,
	Hold,
	ReGroup,
	Stance,
	Stop,
	Target,
	Taunt,
	BuffDuration
};

MQ2PetType::MQ2PetType() : MQ2Type("pet")
{
	ScopedTypeMember(PetMembers, Buff);
	ScopedTypeMember(PetMembers, Combat);
	ScopedTypeMember(PetMembers, GHold);
	ScopedTypeMember(PetMembers, Hold);
	ScopedTypeMember(PetMembers, ReGroup);
	ScopedTypeMember(PetMembers, Stance);
	ScopedTypeMember(PetMembers, Stop);
	ScopedTypeMember(PetMembers, Target);
	ScopedTypeMember(PetMembers, Taunt);
	ScopedTypeMember(PetMembers, BuffDuration);
}

bool MQ2PetType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	SPAWNINFO* pSpawn = reinterpret_cast<SPAWNINFO*>(VarPtr.Ptr);
	if (!pSpawn)
		return false;

	MQTypeMember* pMember = MQ2PetType::FindMember(Member);
	if (!pMember)
	{
		if (!pSpawn->SpawnID)
			return false;

		return pSpawnType->GetMember(VarPtr, Member, Index, Dest);
	}

	if (!pPetInfoWnd)
		return false;

	switch (static_cast<PetMembers>(pMember->ID))
	{
	case PetMembers::Buff:
		Dest.Type = pSpellType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nBuff = GetIntFromString(Index, 0) - 1;
			if (nBuff < 0)
				return false;

			if (nBuff >= NUM_BUFF_SLOTS)
				return false;

			if (pPetInfoWnd->Buff[nBuff] == -1 || pPetInfoWnd->Buff[nBuff] == 0)
				return false;

			if (Dest.Ptr = GetSpellByID(pPetInfoWnd->Buff[nBuff]))
			{
				Dest.Type = pSpellType;
				return true;
			}
		}
		else
		{
			for (int nBuff = 0; nBuff < NUM_BUFF_SLOTS; nBuff++)
			{
				if (SPELL* pSpell = GetSpellByID(pPetInfoWnd->Buff[nBuff]))
				{
					if (!_strnicmp(Index, pSpell->Name, strlen(Index)))
					{
						Dest.DWord = nBuff + 1;
						Dest.Type = pIntType;
						return true;
					}
				}
			}
		}
		return false;

	case PetMembers::BuffDuration:
		Dest.UInt64 = 0;
		Dest.Type = pTimeStampType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nBuff = GetIntFromString(Index, 0) - 1;
			if (nBuff < 0)
				return false;

			if (nBuff >= NUM_BUFF_SLOTS)
				return false;

			if (pPetInfoWnd->Buff[nBuff] == -1 || pPetInfoWnd->Buff[nBuff] == 0)
				return false;

			Dest.UInt64 = pPetInfoWnd->PetBuffTimer[nBuff];
			return true;
		}
		else
		{
			for (int nBuff = 0; nBuff < NUM_BUFF_SLOTS; nBuff++)
			{
				if (SPELL* pSpell = GetSpellByID(pPetInfoWnd->Buff[nBuff]))
				{
					if (!_strnicmp(Index, pSpell->Name, strlen(Index)))
					{
						Dest.UInt64 = pPetInfoWnd->PetBuffTimer[nBuff];
						return true;
					}
				}
			}
		}
		return false;

	case PetMembers::Combat:
		Dest.DWord = pSpawn->WhoFollowing != nullptr;
		Dest.Type = pBoolType;
		return true;

	case PetMembers::GHold:
		Dest.DWord = pPetInfoWnd->GHold;
		Dest.Type = pBoolType;
		return true;

	case PetMembers::Hold:
		Dest.DWord = pPetInfoWnd->Hold;
		Dest.Type = pBoolType;
		return true;

	case PetMembers::ReGroup:
		Dest.DWord = pPetInfoWnd->ReGroup;
		Dest.Type = pBoolType;
		return true;

	case PetMembers::Stance:
		if (pPetInfoWnd->Follow)
			strcpy_s(DataTypeTemp, "FOLLOW");
		else
			strcpy_s(DataTypeTemp, "GUARD");
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case PetMembers::Stop:
		Dest.DWord = pPetInfoWnd->Stop;
		Dest.Type = pBoolType;
		return true;

	case PetMembers::Target:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = pSpawn->WhoFollowing)
		{
			return true;
		}
		return false;

	case PetMembers::Taunt:
		Dest.DWord = pPetInfoWnd->Taunt;
		Dest.Type = pBoolType;
		return true;
	}

	return false;
}

bool MQ2PetType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (!VarPtr.Ptr)
		return false;

	SPAWNINFO* pSpawn = static_cast<SPAWNINFO*>(VarPtr.Ptr);
	strcpy_s(Destination, MAX_STRING, pSpawn->Name);
	return true;
}

void MQ2PetType::InitVariable(MQVarPtr& VarPtr)
{
	// FIXME: Do not allocate a SPAWNINFO
	VarPtr.Ptr = new SPAWNINFO();

	// FIXME: Do not ZeroMemory a SPAWNINFO
	ZeroMemory(VarPtr.Ptr, sizeof(SPAWNINFO));
}

void MQ2PetType::FreeVariable(MQVarPtr& VarPtr)
{
	// FIXME: Do not allocate a SPAWNINFO
	SPAWNINFO* pSpawn = static_cast<SPAWNINFO*>(VarPtr.Ptr);
	delete pSpawn;
}

bool MQ2PetType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
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

bool MQ2PetType::FromString(MQVarPtr& VarPtr, char* Source)
{
	if (SPAWNINFO* pOther = (SPAWNINFO*)GetSpawnByID(GetIntFromString(Source, 0)))
	{
		memcpy(VarPtr.Ptr, pOther, sizeof(SPAWNINFO));
		return true;
	}
	return false;
}

