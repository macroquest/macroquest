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

enum class GroundMembers
{
	ID = 1,
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
	DisplayName,
	Distance3D,
	SubID,
	ZoneID,
	First,
	Last,
	Next,
	Prev,
	Search
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
	ScopedTypeMember(GroundMembers, Search);

	// methods
	ScopedTypeMethod(GroundMethods, Grab);
	ScopedTypeMethod(GroundMethods, DoTarget);
	ScopedTypeMethod(GroundMethods, DoFace);
	ScopedTypeMethod(GroundMethods, Reset);
}

bool MQ2GroundType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	auto pGroundSpawn = VarPtr.Get<MQGroundSpawn>();

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2GroundType::FindMethod(Member);
	if (pMethod)
	{
		if (pGroundSpawn == nullptr || pGroundSpawn->Type == MQGroundSpawnType::None)
			return false;

		switch (static_cast<GroundMethods>(pMethod->ID))
		{
		case GroundMethods::Grab:
			Dest.Set(ClickMouseItem(*pGroundSpawn, true));
			Dest.Type = pBoolType;
			return true;

		case GroundMethods::DoTarget:
			SetGroundSpawn(pGroundSpawn->Name());
			Dest.Set(CurrentGroundSpawn());
			Dest.Type = pGroundType;
			return true;

		case GroundMethods::DoFace:
			DoFace(pLocalPlayer, pGroundSpawn->Position());
			Dest.Set(pGroundSpawn);
			Dest.Type = pGroundType;
			return true;

		case GroundMethods::Reset:
			ClearGroundSpawn();
			Dest.Set(MQGroundSpawn());
			Dest.Type = pGroundType;
			return true;

		default:
			return false;
		}
	}

	//----------------------------------------------------------------------------
	// member

	MQTypeMember* pMember = MQ2GroundType::FindMember(Member);
	if (pMember)
	{
		GroundMembers id = static_cast<GroundMembers>(pMember->ID);
		if (
			(pGroundSpawn == nullptr || pGroundSpawn->Type == MQGroundSpawnType::None) &&
			id != GroundMembers::First &&
			id != GroundMembers::Last &&
			id != GroundMembers::Next &&
			id != GroundMembers::Prev &&
			id != GroundMembers::Search
		)
			return false;

		switch (id)
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
			Dest.Set(pGroundSpawn->Distance(pLocalPlayer));
			Dest.Type = pFloatType;
			return true;

		case GroundMembers::Distance3D:
			Dest.Set(pGroundSpawn->Distance3D(pLocalPlayer));
			Dest.Type = pFloatType;
			return true;

		case GroundMembers::HeadingTo:
		{
			auto pos = pGroundSpawn->Position();
			auto heading = atan2(pLocalPlayer->Y - pos.Y, pos.X - pLocalPlayer->X) * 180.f / PI + 90.f;
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
			Dest.Set(CastRay(pLocalPlayer, pos.Y, pos.X, pos.Z));
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

		case GroundMembers::Search:
			Dest.Type = pGroundType;

			if (Index[0])
			{
				auto id = GetIntFromString(Index, -1);
				if (id >= 0)
				{
					Dest.Set(GetGroundSpawnByID(id));
				}
				else
				{
					Dest.Set(GetGroundSpawnByName(Index));
				}
			}
			else
			{
				Dest.Set(GetNearestGroundSpawn());
			}

			return true;

		default:
			return false;
		}
	}

	return false;
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

bool MQ2GroundType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	MQGroundSpawn ground;
	if (Source == nullptr || Source[0] == 0)
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

bool MQ2GroundType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pGroundType)
		return false;

	VarPtr.Set(Source.Get<MQGroundSpawn>());
	return true;
}

bool MQ2GroundType::dataGroundItem(const char* szIndex, MQTypeVar& Ret)
{
	if (szIndex[0])
	{
		auto idx = GetIntFromString(szIndex, 0) - 1;
		if (idx >= 0)
		{
			Ret.Set(GetNthGroundSpawnFromMe(idx));
		}
		else
		{
			// this is deprecated -- we don't want to be implicitly searching as a side effect of accessing `${Ground}`
			if (gbGroundDeprecateCount < 1)
				WriteChatf("\ay[\agMQ2GroundType\ay] Searching directly from the Ground TLO is deprecated and will be removed in a future version. Use \ag${Ground.Search[%s]}\ay.\ax", szIndex);
			if (gbGroundDeprecateCount == 0)
				++gbGroundDeprecateCount;

			Ret.Set(GetGroundSpawnByName(szIndex));
		}
	}
	else if (HasCurrentGroundSpawn())
	{
		Ret.Set(CurrentGroundSpawn());
	}
	else
	{
		Ret.Set(GetNearestGroundSpawn());
	}

	Ret.Type = pGroundType;
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

bool MQ2GroundType::dataItemTarget(const char* szIndex, MQTypeVar& Ret)
{
	if (HasCurrentGroundSpawn())
	{
		Ret.Set(CurrentGroundSpawn());
	}

	Ret.Type = pGroundType;
	return true;
}

MQTypeVar MQ2GroundType::MakeTypeVar(MQGroundSpawn groundSpawn)
{
	MQTypeVar Dest;
	Dest.Type = pGroundType;
	Dest.Set(groundSpawn);
	return Dest;
}

} // namespace mq::datatypes
