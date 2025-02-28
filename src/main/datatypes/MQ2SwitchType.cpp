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

enum class SwitchMembers
{
	ID = 1,
	Distance,
	Distance3D,
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
	LineOfSight,
	IsTargeted,
	State,
};

enum class SwitchMethods
{
	Toggle,
	Target,
	Use,
};

MQ2SwitchType::MQ2SwitchType() : MQ2Type("switch")
{
	ScopedTypeMember(SwitchMembers, ID);
	ScopedTypeMember(SwitchMembers, Distance);
	ScopedTypeMember(SwitchMembers, Distance3D);
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
	ScopedTypeMember(SwitchMembers, IsTargeted);
	ScopedTypeMember(SwitchMembers, State);

	ScopedTypeMethod(SwitchMethods, Toggle);
	ScopedTypeMethod(SwitchMethods, Target);
	ScopedTypeMethod(SwitchMethods, Use);
}

bool MQ2SwitchType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	EQSwitch* pTheSwitch = static_cast<EQSwitch*>(VarPtr.Ptr);
	if (!pTheSwitch)
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
		case SwitchMethods::Toggle:
		case SwitchMethods::Use: {
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

			pTheSwitch->UseSwitch(pLocalPlayer->SpawnID, KeyID, Skill);
			return true;
		}

		case SwitchMethods::Target:
			SetSwitchTarget(pTheSwitch);
			return true;

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
	case SwitchMembers::ID:
		Dest.DWord = pTheSwitch->ID;
		Dest.Type = pIntType;
		return true;

	case SwitchMembers::X:
		Dest.Float = pTheSwitch->X;
		Dest.Type = pFloatType;
		return true;

	case SwitchMembers::Y:
		Dest.Float = pTheSwitch->Y;
		Dest.Type = pFloatType;
		return true;

	case SwitchMembers::Z:
		Dest.Float = pTheSwitch->Z;
		Dest.Type = pFloatType;
		return true;

	case SwitchMembers::DefaultX:
		Dest.Float = pTheSwitch->DefaultX;
		Dest.Type = pFloatType;
		return true;

	case SwitchMembers::DefaultY:
		Dest.Float = pTheSwitch->DefaultY;
		Dest.Type = pFloatType;
		return true;

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
		Dest.Float = (float)(atan2f(pControlledPlayer->Y - pTheSwitch->Y, pTheSwitch->X - pControlledPlayer->X) * 180.0f / PI + 90.0f);
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
		if (pTheSwitch->pActor)
		{
			BoundingRadius = pTheSwitch->pActor->GetBoundingRadius();
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
		float X = pControlledPlayer->X - pTheSwitch->X;
		float Y = pControlledPlayer->Y - pTheSwitch->Y;
		float Z = pControlledPlayer->Z - pTheSwitch->Z;

		float BoundingRadius = 0;
		float thedist = 0;

		if (pTheSwitch->pActor)
		{
			BoundingRadius = pTheSwitch->pActor->GetBoundingRadius();
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
		Dest.Set(CastRay(pControlledPlayer, pTheSwitch->Y, pTheSwitch->X, pTheSwitch->Z) != 0);
		Dest.Type = pBoolType;
		return true;

	case SwitchMembers::IsTargeted:
		Dest.Set(pTheSwitch == pSwitchTarget);
		Dest.Type = pBoolType;
		return true;

	case SwitchMembers::State:
		Dest.Type = pIntType;
		Dest.DWord = pTheSwitch->State;
		return true;

	default: break;
	}

	return false;
}

bool MQ2SwitchType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (!VarPtr.Ptr)
		return false;

	EQSwitch* pSwitch = static_cast<EQSwitch*>(VarPtr.Ptr);
	_itoa_s(pSwitch->ID, Destination, MAX_STRING, 10);
	return true;
}

bool MQ2SwitchType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type == pSwitchType)
	{
		VarPtr.Ptr = Source.Ptr;
	}
	else if (Source.Type == pStringType)
	{
		const char* switchName = static_cast<const char*>(Source.Ptr);
		VarPtr.Ptr = FindSwitchByName(switchName);
	}
	else if (Source.Type == pIntType)
	{
		VarPtr.Ptr = GetSwitchByID(Source.Int);
	}

	return VarPtr.Ptr != nullptr;
}

static EQSwitch* GetSwitchFromIndex(const char* szIndex, bool noneIsTarget)
{
	if (szIndex[0] == 0)
	{
		return noneIsTarget ? pSwitchTarget : nullptr;
	}

	int ID = GetIntFromString(szIndex, -1);

	// Check if the string is a number.
	if (ID >= 0)
	{
		return GetSwitchByID(ID);
	}

	// Check if its the word "target", return targeted switch.
	if (ci_equals(szIndex, "target"))
	{
		return pSwitchTarget;
	}

	// Check if its the word "nearest", return nearest switch.
	if (ci_equals(szIndex, "nearest"))
	{
		return FindSwitchByName();
	}

	// Do a nearest search by name.
	return FindSwitchByName(szIndex);
}

bool MQ2SwitchType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	VarPtr.Ptr = GetSwitchFromIndex(Source, false);

	return VarPtr.Ptr != nullptr;
}

bool MQ2SwitchType::dataSwitch(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Type = pSwitchType;
	Ret.Ptr = GetSwitchFromIndex(szIndex, true);

	return Ret.Ptr != nullptr;
}

bool MQ2SwitchType::dataSwitchTarget(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Type = pSwitchType;
	Ret.Ptr = pSwitchTarget;

	return Ret.Ptr != nullptr;
}

} // namespace mq::datatypes
