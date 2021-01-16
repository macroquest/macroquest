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

namespace mq::datatypes {

enum class ClassMembers
{
	Name = 1,
	ShortName,
	ID,
	PureCaster,
	CanCast,
	DruidType,
	NecromancerType,
	ShamanType,
	ClericType,
	PetClass,
	HealerType,
	MercType,
};

MQ2ClassType::MQ2ClassType() : MQ2Type("class")
{
	ScopedTypeMember(ClassMembers, Name);
	ScopedTypeMember(ClassMembers, ShortName);
	ScopedTypeMember(ClassMembers, ID);
	ScopedTypeMember(ClassMembers, PureCaster);
	ScopedTypeMember(ClassMembers, CanCast);
	ScopedTypeMember(ClassMembers, DruidType);
	ScopedTypeMember(ClassMembers, NecromancerType);
	ScopedTypeMember(ClassMembers, ShamanType);
	ScopedTypeMember(ClassMembers, ClericType);
	ScopedTypeMember(ClassMembers, PetClass);
	ScopedTypeMember(ClassMembers, HealerType);
	ScopedTypeMember(ClassMembers, MercType);
}

bool MQ2ClassType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2ClassType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ClassMembers>(pMember->ID))
	{
	case ClassMembers::ID:
		Dest.Set(VarPtr.Get<uint32_t>());
		Dest.Type = pIntType;
		return true;

	case ClassMembers::Name:
		strcpy_s(DataTypeTemp, GetClassDesc(VarPtr.DWord));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ClassMembers::ShortName:
		strcpy_s(DataTypeTemp, pEverQuest->GetClassThreeLetterCode(VarPtr.DWord));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ClassMembers::CanCast:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.Set(ClassInfo[VarPtr.DWord].CanCast);
			return true;
		}
		return false;

	case ClassMembers::PureCaster:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.Set(ClassInfo[VarPtr.DWord].PureCaster);
			return true;
		}
		return false;

	case ClassMembers::PetClass:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.Set(ClassInfo[VarPtr.DWord].PetClass);
			return true;
		}
		return false;

	case ClassMembers::DruidType:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.Set(ClassInfo[VarPtr.DWord].DruidType);
			return true;
		}
		return false;

	case ClassMembers::ShamanType:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.Set(ClassInfo[VarPtr.DWord].ShamanType);
			return true;
		}
		return false;

	case ClassMembers::NecromancerType:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.Set(ClassInfo[VarPtr.DWord].NecroType);
			return true;
		}
		return false;

	case ClassMembers::ClericType:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.Set(ClassInfo[VarPtr.DWord].ClericType);
			return true;
		}
		return false;

	case ClassMembers::HealerType:
		Dest.Set(VarPtr.DWord == 2 || VarPtr.DWord == 6 || VarPtr.DWord == 10);
		Dest.Type = pBoolType;
		return true;

	case ClassMembers::MercType:
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

bool MQ2ClassType::ToString(MQVarPtr VarPtr, char* Destination)
{
	const char* pDesc = GetClassDesc(VarPtr.DWord);
	strcpy_s(Destination, MAX_STRING, pDesc);

	return true;
}

bool MQ2ClassType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	VarPtr.DWord = Source.DWord;
	return true;
}

bool MQ2ClassType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	VarPtr.DWord = GetIntFromString(Source, 0);
	return true;
}

} // namespace mq::datatypes
