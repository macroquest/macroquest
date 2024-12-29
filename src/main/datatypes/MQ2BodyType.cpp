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

enum class BodyMembers
{
	Name = 1,
	ID,
};

MQ2BodyType::MQ2BodyType() : MQ2Type("body")
{
	ScopedTypeMember(BodyMembers, Name);
	ScopedTypeMember(BodyMembers, ID);
}

bool MQ2BodyType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2BodyType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<BodyMembers>(pMember->ID))
	{
	case BodyMembers::ID:
		Dest.Set(VarPtr.Get<uint32_t>());
		Dest.Type = pIntType;
		return true;

	case BodyMembers::Name:
		strcpy_s(DataTypeTemp, GetBodyTypeDesc(VarPtr.DWord));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2BodyType::ToString(MQVarPtr VarPtr, char* Destination)
{
	const char* pDesc = GetBodyTypeDesc(VarPtr.DWord);
	strcpy_s(Destination, MAX_STRING, pDesc);
	return true;
}

bool MQ2BodyType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	VarPtr.DWord = Source.DWord;
	return true;
}

bool MQ2BodyType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	VarPtr.DWord = GetIntFromString(Source, 0);
	return true;
}

} // namespace mq::datatypes
