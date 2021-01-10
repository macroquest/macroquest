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

enum class SwitchMembers
{
	ID,
	Distance,
	X,
	Y,
	Z,
	Heading,
	DefaultX,
	DefaultY,
	DefaultZ,
	DefaultHeading,
	Open,
	HeadingTo,
	Name,
	N,
	W,
	U,
	DefaultN,
	DefaultW,
	DefaultU,
	LineOfSight,
	Address,
	Distance3D
};

enum class SwitchMethods
{
	Toggle
};

MQ2SwitchType::MQ2SwitchType() : MQ2Type("switch")
{
	ScopedTypeMember(SwitchMembers, ID);
	ScopedTypeMember(SwitchMembers, Distance);
	ScopedTypeMember(SwitchMembers, X);
	ScopedTypeMember(SwitchMembers, Y);
	ScopedTypeMember(SwitchMembers, Z);
	ScopedTypeMember(SwitchMembers, Heading);
	ScopedTypeMember(SwitchMembers, DefaultX);
	ScopedTypeMember(SwitchMembers, DefaultY);
	ScopedTypeMember(SwitchMembers, DefaultZ);
	ScopedTypeMember(SwitchMembers, DefaultHeading);
	ScopedTypeMember(SwitchMembers, Open);
	ScopedTypeMember(SwitchMembers, HeadingTo);
	ScopedTypeMember(SwitchMembers, Name);
	ScopedTypeMember(SwitchMembers, LineOfSight);
	ScopedTypeMember(SwitchMembers, Address);
	ScopedTypeMember(SwitchMembers, Distance3D);

	ScopedTypeMethod(SwitchMethods, Toggle);
}

bool MQ2SwitchType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	DOOR* pTheSwitch = static_cast<DOOR*>(VarPtr.Ptr);
	if (!VarPtr.Ptr)
		return false;

	PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return false;

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2SwitchType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<SwitchMethods>(pMethod->ID))
		{
		case SwitchMethods::Toggle: {
			int KeyID = 0;
			int Skill = 0;

			if (ItemPtr pItem = pProfile->GetInventorySlot(InvSlot_Cursor))
			{
				if (pItem->GetType() != ITEMTYPE_NORMAL)
				{
					switch (pItem->GetItemClass())
					{
					case ItemClass_Key:
						KeyID = pItem->GetID();
						Skill = 0;
						break;
					case ItemClass_LockPicks:
						KeyID = pItem->GetID();
						Skill = GetAdjustedSkill(SKILL_PICKLOCK);
						break;

					default:
						KeyID = pItem->GetID();
						Skill = 0;
						break;
					}
				}
			}

			((EQSwitch*)pTheSwitch->pSwitch)->UseSwitch(((SPAWNINFO*)pLocalPlayer)->SpawnID, KeyID, Skill);
			return true;
		}

		default: break;
		}
		return false;
	}

	//----------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = MQ2SwitchType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<SwitchMembers>(pMember->ID))
	{
	case SwitchMembers::Address:
		Dest.DWord = (uint32_t)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case SwitchMembers::ID:
		Dest.DWord = pTheSwitch->ID;
		Dest.Type = pIntType;
		return true;

	case SwitchMembers::W:
	case SwitchMembers::X:
		Dest.Float = pTheSwitch->X;
		Dest.Type = pFloatType;
		return true;

	case SwitchMembers::N:
	case SwitchMembers::Y:
		Dest.Float = pTheSwitch->Y;
		Dest.Type = pFloatType;
		return true;

	case SwitchMembers::U:
	case SwitchMembers::Z:
		Dest.Float = pTheSwitch->Z;
		Dest.Type = pFloatType;
		return true;

	case SwitchMembers::DefaultW:
	case SwitchMembers::DefaultX:
		Dest.Float = pTheSwitch->DefaultX;
		Dest.Type = pFloatType;
		return true;

	case SwitchMembers::DefaultN:
	case SwitchMembers::DefaultY:
		Dest.Float = pTheSwitch->DefaultY;
		Dest.Type = pFloatType;
		return true;

	case SwitchMembers::DefaultU:
	case SwitchMembers::DefaultZ:
		Dest.Float = pTheSwitch->DefaultZ;
		Dest.Type = pFloatType;
		return true;

	case SwitchMembers::Heading:
		Dest.Float = pTheSwitch->Heading * 0.703125f;
		Dest.Type = pHeadingType;
		return true;

	case SwitchMembers::DefaultHeading:
		Dest.Float = pTheSwitch->DefaultHeading * 0.703125f;
		Dest.Type = pHeadingType;
		return true;

	case SwitchMembers::Open:
		Dest.Set(pTheSwitch->State == 1);
		Dest.Type = pBoolType;
		return true;

	case SwitchMembers::HeadingTo:
		Dest.Float = (float)(atan2f(((SPAWNINFO*)pCharSpawn)->Y - pTheSwitch->Y, pTheSwitch->X - ((SPAWNINFO*)pCharSpawn)->X) * 180.0f / PI + 90.0f);
		if (Dest.Float < 0.0f)
			Dest.Float += 360.0f;
		else if (Dest.Float >= 360.0f)
			Dest.Float -= 360.0f;
		Dest.Type = pHeadingType;
		return true;

	case SwitchMembers::Name:
		Dest.Ptr = &pTheSwitch->Name[0];
		Dest.Type = pStringType;
		return true;

	case SwitchMembers::Distance: {
		float BoundingRadius = 0;
		if (ActorBase* pBase = (ActorBase*)pTheSwitch->pSwitch)
		{
			BoundingRadius = pBase->GetBoundingRadius();
		}
		else
		{
			BoundingRadius = pTheSwitch->ScaleFactor * 0.01f;
		}

		if (BoundingRadius)
		{
			float thedist = GetDistance(pTheSwitch->X, pTheSwitch->Y) - (BoundingRadius / 2);
			if (thedist < 0.0f)
				thedist = 0.0f;
			Dest.Float = thedist;
		}
		else
		{
			Dest.Float = GetDistance(pTheSwitch->X, pTheSwitch->Y);
		}
		Dest.Type = pFloatType;
		return true;
	}

	case SwitchMembers::Distance3D: {
		float X = ((SPAWNINFO*)pCharSpawn)->X - pTheSwitch->X;
		float Y = ((SPAWNINFO*)pCharSpawn)->Y - pTheSwitch->Y;
		float Z = ((SPAWNINFO*)pCharSpawn)->Z - pTheSwitch->Z;

		float BoundingRadius = 0;
		float thedist = 0;

		if (ActorBase* pBase = (ActorBase*)pTheSwitch->pSwitch)
		{
			BoundingRadius = pBase->GetBoundingRadius();
		}
		else
		{
			BoundingRadius = pTheSwitch->ScaleFactor * 0.01f;
		}

		if (BoundingRadius)
		{
			thedist = sqrtf(X * X + Y * Y + Z * Z) - (BoundingRadius / 2);
			if (thedist < 0.0f)
				thedist = 0.0f;
			Dest.Float = thedist;
		}
		else
		{
			Dest.Float = sqrtf(X * X + Y * Y + Z * Z);
		}
		Dest.Type = pFloatType;
		return true;
	}

	case SwitchMembers::LineOfSight:
		Dest.Set(CastRay(GetCharInfo()->pSpawn, pTheSwitch->Y, pTheSwitch->X, pTheSwitch->Z) != 0);
		Dest.Type = pBoolType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2SwitchType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (!VarPtr.Ptr)
		return false;

	DOOR* pDoor = static_cast<DOOR*>(VarPtr.Ptr);
	_itoa_s(pDoor->ID, Destination, MAX_STRING, 10);
	return true;
}


void MQ2SwitchType::InitVariable(MQVarPtr& VarPtr)
{
	// FIXME: Do not allocate a DOOR
	VarPtr.Ptr = new DOOR();
}

void MQ2SwitchType::FreeVariable(MQVarPtr& VarPtr)
{
	// FIXME: Do not allocate a DOOR
	DOOR* pDoor = static_cast<DOOR*>(VarPtr.Ptr);
	delete pDoor;
}

bool MQ2SwitchType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	if (Source.Type != pSwitchType)
		return false;

	memcpy(VarPtr.Ptr, Source.Ptr, sizeof(DOOR));
	return true;
}

