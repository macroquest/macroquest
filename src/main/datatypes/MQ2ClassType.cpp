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

bool MQ2ClassType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2ClassType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ClassMembers>(pMember->ID))
	{
	case ID:
		Dest.Ptr = VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case Name:
		strcpy_s(DataTypeTemp, GetClassDesc(VarPtr.DWord));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ShortName:
		strcpy_s(DataTypeTemp, pEverQuest->GetClassThreeLetterCode(VarPtr.DWord));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case CanCast:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.Set(ClassInfo[VarPtr.DWord].CanCast);
			return true;
		}
		return false;

	case PureCaster:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.Set(ClassInfo[VarPtr.DWord].PureCaster);
			return true;
		}
		return false;

	case PetClass:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.Set(ClassInfo[VarPtr.DWord].PetClass);
			return true;
		}
		return false;

	case DruidType:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.Set(ClassInfo[VarPtr.DWord].DruidType);
			return true;
		}
		return false;

	case ShamanType:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.Set(ClassInfo[VarPtr.DWord].ShamanType);
			return true;
		}
		return false;

	case NecromancerType:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.Set(ClassInfo[VarPtr.DWord].NecroType);
			return true;
		}
		return false;

	case ClericType:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.Set(ClassInfo[VarPtr.DWord].ClericType);
			return true;
		}
		return false;

	case HealerType:
		Dest.Set(VarPtr.DWord == 2 || VarPtr.DWord == 6 || VarPtr.DWord == 10);
		Dest.Type = pBoolType;
		return true;

	case MercType:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 17)
		{
			Dest.Set(ClassInfo[VarPtr.DWord].MercType);
			return true;
		}
		return false;

	default: break;
	}

	return false;
}

