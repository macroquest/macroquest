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

bool MQ2SwitchType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	DOOR* pTheSwitch = static_cast<DOOR*>(VarPtr.Ptr);
	if (!VarPtr.Ptr)
		return false;

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2SwitchType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<SwitchMethods>(pMethod->ID))
		{
		case Toggle: {
			int KeyID = 0;
			int Skill = 0;

			if (PcProfile* pProfile = GetPcProfile())
			{
				if (pProfile->pInventoryArray && pProfile->pInventoryArray->Inventory.Cursor)
				{
					if (ITEMINFO* pItem = GetItemFromContents(pProfile->pInventoryArray->Inventory.Cursor))
					{
						if (pItem->Type != ITEMTYPE_NORMAL)
						{
							switch (pItem->Type)
							{
							case 33: // EQIC_KEY
								KeyID = pItem->ItemNumber;
								Skill = 0;
								break;
							case 35: // EQIC_LOCKPICK
								KeyID = pItem->ItemNumber;
								Skill = GetAdjustedSkill(SKILL_PICKLOCK);
								break;

							default:
								KeyID = pItem->ItemNumber;
								Skill = 0;
								break;
							}
						}
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
	case Address:
		Dest.DWord = (uint32_t)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case ID:
		Dest.DWord = pTheSwitch->ID;
		Dest.Type = pIntType;
		return true;

	case W:
	case X:
		Dest.Float = pTheSwitch->X;
		Dest.Type = pFloatType;
		return true;

	case N:
	case Y:
		Dest.Float = pTheSwitch->Y;
		Dest.Type = pFloatType;
		return true;

	case U:
	case Z:
		Dest.Float = pTheSwitch->Z;
		Dest.Type = pFloatType;
		return true;

	case DefaultW:
	case DefaultX:
		Dest.Float = pTheSwitch->DefaultX;
		Dest.Type = pFloatType;
		return true;

	case DefaultN:
	case DefaultY:
		Dest.Float = pTheSwitch->DefaultY;
		Dest.Type = pFloatType;
		return true;

	case DefaultU:
	case DefaultZ:
		Dest.Float = pTheSwitch->DefaultZ;
		Dest.Type = pFloatType;
		return true;

	case Heading:
		Dest.Float = pTheSwitch->Heading * 0.703125f;
		Dest.Type = pHeadingType;
		return true;

	case DefaultHeading:
		Dest.Float = pTheSwitch->DefaultHeading * 0.703125f;
		Dest.Type = pHeadingType;
		return true;

	case Open:
		Dest.DWord = (pTheSwitch->State == 1);
		Dest.Type = pBoolType;
		return true;

	case HeadingTo:
		Dest.Float = (float)(atan2f(((SPAWNINFO*)pCharSpawn)->Y - pTheSwitch->Y, pTheSwitch->X - ((SPAWNINFO*)pCharSpawn)->X) * 180.0f / PI + 90.0f);
		if (Dest.Float < 0.0f)
			Dest.Float += 360.0f;
		else if (Dest.Float >= 360.0f)
			Dest.Float -= 360.0f;
		Dest.Type = pHeadingType;
		return true;

	case Name:
		Dest.Ptr = &pTheSwitch->Name[0];
		Dest.Type = pStringType;
		return true;

	case Distance: {
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

	case Distance3D: {
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

	case xLineOfSight:
		Dest.DWord = CastRay(GetCharInfo()->pSpawn, pTheSwitch->Y, pTheSwitch->X, pTheSwitch->Z);
		Dest.Type = pBoolType;
		return true;

	default: break;
	}

	return false;
}

