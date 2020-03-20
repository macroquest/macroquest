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

enum class Int64Members
{
	Float = 1,
	Double,
	Hex,
	Reverse,
	LowPart,
	HighPart,
};

MQ2Int64Type::MQ2Int64Type() : MQ2Type("int64")
{
	ScopedTypeMember(Int64Members, Float);
	ScopedTypeMember(Int64Members, Double);
	ScopedTypeMember(Int64Members, Hex);
	ScopedTypeMember(Int64Members, Reverse);
	ScopedTypeMember(Int64Members, LowPart);
	ScopedTypeMember(Int64Members, HighPart);
}

bool MQ2Int64Type::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2Int64Type::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<Int64Members>(pMember->ID))
	{
	case Int64Members::Float:
		Dest.Float = (float)1.0f * (VarPtr.Int64);
		Dest.Type = pFloatType;
		return true;

	case Int64Members::Double:
		Dest.Double = (double)1.0f * (VarPtr.Int64);
		Dest.Type = pDoubleType;
		return true;

	case Int64Members::Hex:
		sprintf_s(DataTypeTemp, "0x%llX", VarPtr.Int64);
		Dest.Ptr = &DataTypeTemp[0],
			Dest.Type = pStringType;
		return true;

	case Int64Members::Reverse:
		Dest.Int64 = _byteswap_uint64(VarPtr.Int64);
		Dest.Type = pInt64Type;
		return true;

	case Int64Members::LowPart:
		Dest.DWord = VarPtr.LowPart;
		Dest.Type = pIntType;
		return true;

	case Int64Members::HighPart:
		Dest.DWord = VarPtr.HighPart;
		Dest.Type = pIntType;
		return true;

	default:
		return false;
	}
}

bool MQ2Int64Type::ToString(MQVarPtr VarPtr, char* Destination)
{
	strcpy_s(Destination, MAX_STRING, std::to_string(VarPtr.Int64).c_str());
	return true;
}

bool MQ2Int64Type::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	VarPtr.Int64 = Source.Int64;
	return true;
}

bool MQ2Int64Type::FromString(MQVarPtr& VarPtr, char* Source)
{
	VarPtr.Int64 = GetInt64FromString(Source, -1);
	return true;
}

