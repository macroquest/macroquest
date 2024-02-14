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

enum class DeityMembers
{
	Name = 1,
	Team,
	ID,
};

MQ2DeityType::MQ2DeityType() : MQ2Type("Deity")
{
	ScopedTypeMember(DeityMembers, Name);
	ScopedTypeMember(DeityMembers, Team);
	ScopedTypeMember(DeityMembers, ID);
}

bool MQ2DeityType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2DeityType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<DeityMembers>(pMember->ID))
	{
	case DeityMembers::ID:
		Dest.Set(VarPtr.Get<uint32_t>());
		Dest.Type = pIntType;
		return true;

	case DeityMembers::Name:
		strcpy_s(DataTypeTemp, pEverQuest->GetDeityDesc(VarPtr.DWord));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case DeityMembers::Team:
		strcpy_s(DataTypeTemp, szDeityTeam[GetDeityTeamByID(VarPtr.DWord)]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2DeityType::ToString(MQVarPtr VarPtr, char* Destination)
{
	char* pDesc = pEverQuest->GetDeityDesc(VarPtr.DWord);
	strcpy_s(Destination, MAX_STRING, pDesc);
	return true;
}

bool MQ2DeityType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	VarPtr.DWord = Source.DWord;
	return true;
}

bool MQ2DeityType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	VarPtr.DWord = GetIntFromString(Source, 0);
	return true;
}

} // namespace mq::datatypes
