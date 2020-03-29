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

namespace mq {
namespace datatypes {

MQ2FloatType::MQ2FloatType() : MQ2Type("float")
{
	ScopedTypeMember(FloatMembers, Deci);
	ScopedTypeMember(FloatMembers, Centi);
	ScopedTypeMember(FloatMembers, Milli);
	ScopedTypeMember(FloatMembers, Int);
	ScopedTypeMember(FloatMembers, Precision);
	ScopedTypeMember(FloatMembers, Raw);
	ScopedTypeMember(FloatMembers, Prettify);
}

bool MQ2FloatType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2FloatType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<FloatMembers>(pMember->ID))
	{
	case FloatMembers::Deci:
		sprintf_s(DataTypeTemp, "%.1f", VarPtr.Float);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case FloatMembers::Centi:
		sprintf_s(DataTypeTemp, "%.2f", VarPtr.Float);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case FloatMembers::Milli:
		sprintf_s(DataTypeTemp, "%.3f", VarPtr.Float);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case FloatMembers::Int:
		Dest.Type = pIntType;
		Dest.Int = (int)(VarPtr.Float);
		return true;

	case FloatMembers::Precision:
		Dest.Type = pStringType;
		if (IsNumber(Index))
		{
			sprintf_s(DataTypeTemp, "%.*f", GetIntFromString(Index, 3), VarPtr.Float);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case FloatMembers::Raw:
		Dest.Type = pIntType;
		Dest.DWord = VarPtr.DWord;
		return true;

	case FloatMembers::Prettify:
		sprintf_s(DataTypeTemp, "%lld", VarPtr.Int64);
		PrettifyNumber(DataTypeTemp, sizeof(DataTypeTemp), IsNumber(Index) ? atoi(Index) : 2);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2FloatType::ToString(MQVarPtr VarPtr, char* Destination)
{
	sprintf_s(Destination, MAX_STRING, "%.2f", VarPtr.Float);
	return true;
}

bool MQ2FloatType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	if (Source.Type != pFloatType && Source.Type != (MQ2Type*)pHeadingType)
		VarPtr.Float = (float)Source.DWord;
	else
		VarPtr.Float = Source.Float;
	return true;
}

bool MQ2FloatType::FromString(MQVarPtr& VarPtr, char* Source)
{
	VarPtr.Float = GetFloatFromString(Source, 0);
	return true;
}

bool MQ2FloatType::dataFloat(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	Ret.DWord = GetIntFromString(szIndex, 0);
	Ret.Type = pIntType;
	return true;
}

}} // namespace mq::datatypes
