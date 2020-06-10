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

enum class GroundMembers
{
	ID,
	Distance,
	X,
	Y,
	Z,
	Heading,
	Name,
	HeadingTo,
	N,
	W,
	U,
	LineOfSight,
	Address,
	DisplayName,
	Distance3D,
	SubID,
	ZoneID,
	First,
	Last,
	Next,
	Prev
};

enum class GroundMethods
{
	Grab,
	DoTarget,
	DoFace,
	Reset
};

MQ2GroundType::MQ2GroundType() : MQ2Type("ground")
{
	ScopedTypeMember(GroundMembers, ID);
	ScopedTypeMember(GroundMembers, Distance);
	ScopedTypeMember(GroundMembers, X);
	ScopedTypeMember(GroundMembers, Y);
	ScopedTypeMember(GroundMembers, Z);
	ScopedTypeMember(GroundMembers, Heading);
	ScopedTypeMember(GroundMembers, Name);
	ScopedTypeMember(GroundMembers, HeadingTo);
	ScopedTypeMember(GroundMembers, LineOfSight);
	ScopedTypeMember(GroundMembers, DisplayName);
	ScopedTypeMember(GroundMembers, Distance3D);
	ScopedTypeMember(GroundMembers, SubID);
	ScopedTypeMember(GroundMembers, ZoneID);
	ScopedTypeMember(GroundMembers, First);
	ScopedTypeMember(GroundMembers, Last);
	ScopedTypeMember(GroundMembers, Next);
	ScopedTypeMember(GroundMembers, Prev);

	// methods
	ScopedTypeMethod(GroundMethods, Grab);
	ScopedTypeMethod(GroundMethods, DoTarget);
	ScopedTypeMethod(GroundMethods, DoFace);
	ScopedTypeMethod(GroundMethods, Reset);
}

bool MQ2GroundType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	auto pGroundSpawn = VarPtr.Get<MQGroundSpawn>();
	if (!pGroundSpawn)
		return false;

	if (pGroundSpawn->Type == MQGroundSpawnType::None)
		return false;

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2GroundType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<GroundMethods>(pMethod->ID))
		{
		case GroundMethods::Grab:
			Dest.DWord = ClickMouseItem(pCharSpawn, *pGroundSpawn, true);
			Dest.Type = pBoolType;
			return true;

		case GroundMethods::DoTarget:
			SetGroundSpawn(pGroundSpawn->Name());
			Dest.Set(CurrentGroundSpawn());
			Dest.Type = pGroundType;
			return true;

		case GroundMethods::DoFace:
			DoFace(pCharSpawn, pGroundSpawn->Position());
			Dest.Set(pGroundSpawn);
			Dest.Type = pGroundType;
			return true;

		case GroundMethods::Reset:
			ClearGroundSpawn();
			return true;

		default:
			return false;
		}
	}

	//----------------------------------------------------------------------------
	// member

	MQTypeMember* pMember = MQ2GroundType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<GroundMembers>(pMember->ID))
	{
	case GroundMembers::ID:
		Dest.Set(pGroundSpawn->ID());
		Dest.Type = pIntType;
		return true;

	case GroundMembers::SubID:
		Dest.Set(pGroundSpawn->SubID());
		Dest.Type = pIntType;
		return true;

	case GroundMembers::ZoneID:
		Dest.Set(pGroundSpawn->ZoneID());
		Dest.Type = pIntType;
		return true;

	case GroundMembers::W:
	case GroundMembers::X:
		Dest.Set(pGroundSpawn->Position().X);
		Dest.Type = pFloatType;
		return true;

	case GroundMembers::N:
	case GroundMembers::Y:
		Dest.Set(pGroundSpawn->Position().Y);
		Dest.Type = pFloatType;
		return true;

	case GroundMembers::U:
	case GroundMembers::Z:
		Dest.Set(pGroundSpawn->Position().Z);
		Dest.Type = pFloatType;
		return true;

	case GroundMembers::Name:
		strcpy_s(DataTypeTemp, pGroundSpawn->Name().c_str());
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case GroundMembers::DisplayName:
		strcpy_s(DataTypeTemp, pGroundSpawn->DisplayName().c_str());
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case GroundMembers::Heading:
		Dest.Set(pGroundSpawn->Heading());
		Dest.Type = pHeadingType;
		return true;

	case GroundMembers::Distance:
		Dest.Set(pGroundSpawn->Distance(pCharSpawn));
		Dest.Type = pFloatType;
		return true;

	case GroundMembers::Distance3D:
		Dest.Set(pGroundSpawn->Distance3D(pCharSpawn));
		Dest.Type = pFloatType;
		return true;

	case GroundMembers::HeadingTo:
	{
		auto pos = pGroundSpawn->Position();
		auto heading = atan2(pCharSpawn->Y - pos.Y, pos.X - pCharSpawn->X) * 180.f / PI + 90.f;
		if (heading < 0.f)
			heading += 360.f;
		else if (heading >= 360.f)
			heading -= 360.f;
		Dest.Set(heading);
		Dest.Type = pHeadingType;
		return true;
	}

	case GroundMembers::LineOfSight:
	{
		auto pos = pGroundSpawn->Position();
		Dest.Set(CastRay(pCharSpawn, pos.Y, pos.X, pos.Z));
		Dest.Type = pBoolType;
		return true;
	}

	case GroundMembers::First:
		Dest.Set(FirstGroundSpawn());
		Dest.Type = pGroundType;
		return true;

	case GroundMembers::Last:
		Dest.Set(LastGroundSpawn());
		Dest.Type = pGroundType;
		return true;

	case GroundMembers::Next:
		Dest.Set(NextGroundSpawn());
		Dest.Type = pGroundType;
		return true;

	case GroundMembers::Prev:
		Dest.Set(PrevGroundSpawn());
		Dest.Type = pGroundType;
		return true;

	default:
		return false;
	}
}

bool MQ2GroundType::ToString(MQVarPtr VarPtr, char* Destination)
{
	auto pGroundSpawn = VarPtr.Get<MQGroundSpawn>();
	if (!pGroundSpawn)
		return false;

	if (pGroundSpawn->Type == MQGroundSpawnType::None)
		return false;

	strcpy_s(Destination, MAX_STRING, pGroundSpawn->DisplayName().c_str());
	return true;
}

bool MQ2GroundType::FromString(MQVarPtr& VarPtr, char* Source)
{
	MQGroundSpawn ground;
	if (strnlen_s(Source, MAX_STRING) == 0)
	{
		ground = CurrentGroundSpawn();
	}
	else if (IsNumber(Source))
	{
		ground = GetGroundSpawnByID(GetIntFromString(Source, 0));
	}
	else
	{
		ground = GetGroundSpawnByName(Source);
	}

	if (ground)
	{
		VarPtr.Set(ground);
		return true;
	}

	return false;
}

bool MQ2GroundType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	if (Source.Type != pGroundType)
		return false;

	VarPtr.Set(Source.Get<MQGroundSpawn>());
	return true;
}

bool MQ2GroundType::dataGroundItem(const char* szIndex, MQTypeVar& Ret)
{
	SPAWNINFO* pSpawn = (SPAWNINFO*)pCharSpawn;

	// if they did ${Ground[name]}
	if (szIndex[0])
	{
		if (IsNumber(szIndex))
		{
			int index = GetIntFromString(szIndex, 0) - 1;
			if (index >= 0)
			{
				auto ground = GetNthGroundSpawnFromMe(index);
				if (ground)
				{
					Ret.Set(ground);
					Ret.Type = pGroundType;
					return true;
				}
			}
		}
		else
		{
			auto ground = GetGroundSpawnByName(szIndex);
			if (ground)
			{
				Ret.Set(ground);
				Ret.Type = pGroundType;
				return true;
			}
		}

		return false;
	}
	else if (HasCurrentGroundSpawn()) // they already did /itemtarget so return that (this can potentially be NULL).
	{
		Ret.Set(CurrentGroundSpawn());
		Ret.Type = pGroundType;
	}
	else
	{
		// this importantly resets the search as a side effect
		// they didn't specify a name and they have not done /itemtarget
		// so we just return first closest entry found
		Ret.Set(GetNearestGroundSpawn());
		Ret.Type = pGroundType;
	}

	return true;
}

bool MQ2GroundType::dataGroundItemCount(const char* szIndex, MQTypeVar& Ret)
{
	if (szIndex[0] == 0)
	{
		Ret.Set(GetGroundSpawnCount());
	}
	else
	{
		Ret.Set(GetGroundSpawnCountByName(szIndex));
	}

	Ret.Type = pIntType;
	return true;
}

