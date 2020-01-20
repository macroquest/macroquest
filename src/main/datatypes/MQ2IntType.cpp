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
//----------------------------------------------------------------------------
// MQ2IntType

bool MQ2IntType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2IntType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<IntMembers>(pMember->ID))
	{
	case Float:
		Dest.Float = (float)1.0f * (VarPtr.Int);
		Dest.Type = pFloatType;
		return true;

	case Double:
		Dest.Double = (double)1.0f * (VarPtr.Int);
		Dest.Type = pDoubleType;
		return true;

	case Hex:
		sprintf_s(DataTypeTemp, "0x%X", VarPtr.Int);
		Dest.Ptr = &DataTypeTemp[0],
			Dest.Type = pStringType;
		return true;

	case Reverse:
		Dest.Array[0] = VarPtr.Array[3];
		Dest.Array[1] = VarPtr.Array[2];
		Dest.Array[2] = VarPtr.Array[1];
		Dest.Array[3] = VarPtr.Array[0];
		Dest.Type = pIntType;
		return true;

	case LowPart:
		Dest.DWord = LOWORD(VarPtr.DWord);
		Dest.Type = pIntType;
		return true;

	case HighPart:
		Dest.DWord = HIWORD(VarPtr.DWord);
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

