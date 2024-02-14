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

	PlayerClass classVal = static_cast<PlayerClass>(VarPtr.DWord);

	switch (static_cast<ClassMembers>(pMember->ID))
	{
	case ClassMembers::ID:
		Dest.Set(VarPtr.Get<uint32_t>());
		Dest.Type = pIntType;
		return true;

	case ClassMembers::Name:
		strcpy_s(DataTypeTemp, GetClassDesc(classVal));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ClassMembers::ShortName:
		strcpy_s(DataTypeTemp, pEverQuest->GetClassThreeLetterCode(classVal));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ClassMembers::CanCast:
		Dest.Set(classVal <= TotalPlayerClasses && ClassInfo[classVal].CanCast);
		Dest.Type = pBoolType;
		return true;

	case ClassMembers::PureCaster:
		Dest.Set(classVal <= TotalPlayerClasses && ClassInfo[classVal].PureCaster);
		Dest.Type = pBoolType;
		return true;

	case ClassMembers::PetClass:
		Dest.Set(classVal <= TotalPlayerClasses && ClassInfo[classVal].PetClass);
		Dest.Type = pBoolType;
		return true;

	case ClassMembers::DruidType:
		Dest.Set(classVal <= TotalPlayerClasses && ClassInfo[classVal].DruidType);
		Dest.Type = pBoolType;
		return true;

	case ClassMembers::ShamanType:
		Dest.Set(classVal <= TotalPlayerClasses && ClassInfo[classVal].ShamanType);
		Dest.Type = pBoolType;
		return true;

	case ClassMembers::NecromancerType:
		Dest.Set(classVal <= TotalPlayerClasses && ClassInfo[classVal].NecroType);
		Dest.Type = pBoolType;
		return true;

	case ClassMembers::ClericType:
		Dest.Set(classVal <= TotalPlayerClasses && ClassInfo[classVal].ClericType);
		Dest.Type = pBoolType;
		return true;

	case ClassMembers::HealerType:
		Dest.Set(classVal == Cleric || classVal == Druid || classVal == Shaman);
		Dest.Type = pBoolType;
		return true;

	case ClassMembers::MercType:
		Dest.Set(classVal == Mercenary);
		Dest.Type = pBoolType;
		return true;

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

bool MQ2ClassType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
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
