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

MQ2DoubleType::MQ2DoubleType() : MQ2Type("double")
{
	ScopedTypeMember(DoubleMembers, Deci);
	ScopedTypeMember(DoubleMembers, Centi);
	ScopedTypeMember(DoubleMembers, Milli);
	ScopedTypeMember(DoubleMembers, Int);
	ScopedTypeMember(DoubleMembers, Precision);
	ScopedTypeMember(DoubleMembers, Prettify);
}

bool MQ2DoubleType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2DoubleType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<DoubleMembers>(pMember->ID))
	{
	case DoubleMembers::Deci:
		sprintf_s(DataTypeTemp, "%.1f", VarPtr.Double);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case DoubleMembers::Centi:
		sprintf_s(DataTypeTemp, "%.2f", VarPtr.Double);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case DoubleMembers::Milli:
		sprintf_s(DataTypeTemp, "%.3f", VarPtr.Double);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case DoubleMembers::Int:
		Dest.Type = pIntType;
		Dest.Int = (int)(VarPtr.Double);
		return true;

	case DoubleMembers::Precision:
		Dest.Type = pStringType;
		if (IsNumber(Index))
		{
			sprintf_s(DataTypeTemp, "%.*f", GetIntFromString(Index, 3), VarPtr.Double);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case DoubleMembers::Prettify:
		sprintf_s(DataTypeTemp, "%lld", VarPtr.Int64);
		PrettifyNumber(DataTypeTemp, sizeof(DataTypeTemp), IsNumber(Index) ? atoi(Index) : 2);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2DoubleType::ToString(MQVarPtr VarPtr, char* Destination)
{
	sprintf_s(Destination, MAX_STRING, "%.2f", VarPtr.Double);
	return true;
}

bool MQ2DoubleType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	if (Source.Type != pDoubleType && Source.Type != (MQ2Type*)pHeadingType)
		VarPtr.Double = Source.Double;
	else
		VarPtr.Double = Source.Double;
	return true;
}

bool MQ2DoubleType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	VarPtr.Double = GetDoubleFromString(Source, 0);
	return true;
}

}} // namespace mq::datatypes
