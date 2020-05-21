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

enum class TypeMembers
{
	Name = 1,
	Member = 2,
};

MQ2TypeType::MQ2TypeType() : MQ2Type("type")
{
	ScopedTypeMember(TypeMembers, Name);
	ScopedTypeMember(TypeMembers, Member);
}

bool MQ2TypeType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQ2Type* pType = static_cast<MQ2Type*>(VarPtr.Ptr);
	if (!pType)
		return false;

	MQTypeMember* pMember = MQ2TypeType::FindMember(Member);
	if (!pMember)
		return false;


	switch (static_cast<TypeMembers>(pMember->ID))
	{
	case TypeMembers::Name:
		strcpy_s(DataTypeTemp, pType->GetName());
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case TypeMembers::Member:
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			// name by number
			if (Dest.Ptr = (void*)pType->GetMemberName(GetIntFromString(Index, 0)))
			{
				Dest.Type = pStringType;
				return true;
			}
		}
		else
		{
			// number by name
			int memberID;
			if (pType->GetMemberID(Index, memberID))
			{
				Dest.Type = pIntType;
				Dest.Int = memberID;
				return true;
			}
		}

		return false;

	default: break;
	}

	return false;
}

bool MQ2TypeType::ToString(MQVarPtr VarPtr, char* Destination)
{
	strcpy_s(Destination, MAX_STRING, ((MQ2Type*)VarPtr.Ptr)->GetName());
	return true;
}
bool MQ2TypeType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	VarPtr.Ptr = Source.Type;
	return true;
}

bool MQ2TypeType::FromString(MQVarPtr& VarPtr, char* Source)
{
	if (VarPtr.Ptr = FindMQ2DataType(Source))
		return true;

	return false;
}