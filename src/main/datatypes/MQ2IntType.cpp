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
enum class IntMembers
{
	Float = 1,
	Double,
	Hex,
	Reverse,
	LowPart,
	HighPart
};

MQ2IntType::MQ2IntType() : MQ2Type("int")
{
	ScopedTypeMember(IntMembers, Float);
	ScopedTypeMember(IntMembers, Double);
	ScopedTypeMember(IntMembers, Hex);
	ScopedTypeMember(IntMembers, Reverse);
	ScopedTypeMember(IntMembers, LowPart);
	ScopedTypeMember(IntMembers, HighPart);
}

bool MQ2IntType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2IntType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<IntMembers>(pMember->ID))
	{
	case IntMembers::Float:
		Dest.Float = static_cast<float>(VarPtr.Int);
		Dest.Type = pFloatType;
		return true;

	case IntMembers::Double:
		Dest.Double = static_cast<double>(VarPtr.Int);
		Dest.Type = pDoubleType;
		return true;

	case IntMembers::Hex:
		sprintf_s(DataTypeTemp, "0x%X", VarPtr.Int);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case IntMembers::Reverse:
		Dest.Array[0] = VarPtr.Array[3];
		Dest.Array[1] = VarPtr.Array[2];
		Dest.Array[2] = VarPtr.Array[1];
		Dest.Array[3] = VarPtr.Array[0];
		Dest.Type = pIntType;
		return true;

	case IntMembers::LowPart:
		Dest.DWord = LOWORD(VarPtr.DWord);
		Dest.Type = pIntType;
		return true;

	case IntMembers::HighPart:
		Dest.DWord = HIWORD(VarPtr.DWord);
		Dest.Type = pIntType;
		return true;

	default:
		return false;
	}
}

bool MQ2IntType::ToString(MQVarPtr VarPtr, char* Destination)
{
	strcpy_s(Destination, MAX_STRING, std::to_string(VarPtr.Int).c_str());
	return true;
}

bool MQ2IntType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	VarPtr.Int = Source.Int;
	return true;
}

bool MQ2IntType::FromString(MQVarPtr& VarPtr, char* Source)
{
	VarPtr.Int = GetIntFromString(Source, -1);
	return true;
}

bool MQ2IntType::dataInt(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	Ret.DWord = GetIntFromString(szIndex, 0);
	Ret.Type = pIntType;
	return true;
}

