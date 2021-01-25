/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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

enum class CharSelectListMembers
{
	Name = 1,
	Level,
	ZoneID,
	Count,
	Class,
	Race,
};

MQ2CharSelectListType::MQ2CharSelectListType() : MQ2Type("charselectlist")
{
	ScopedTypeMember(CharSelectListMembers, Name);
	ScopedTypeMember(CharSelectListMembers, Level);
	ScopedTypeMember(CharSelectListMembers, ZoneID);
	ScopedTypeMember(CharSelectListMembers, Count);
	ScopedTypeMember(CharSelectListMembers, Class);
	ScopedTypeMember(CharSelectListMembers, Race);
}

bool MQ2CharSelectListType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2CharSelectListType::FindMember(Member);
	if (!pMember)
		return false;

	EVERQUEST* pEQ = pEverQuest;

	switch (static_cast<CharSelectListMembers>(pMember->ID))
	{
	case CharSelectListMembers::Name:
		Dest.Type = pStringType;
		if (pEQ && VarPtr.Int < pEQ->pCharSelectPlayerArray.Count)
		{
			strcpy_s(DataTypeTemp, pEQ->pCharSelectPlayerArray[VarPtr.Int].Name);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case CharSelectListMembers::Level:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pEQ && VarPtr.Int < pEQ->pCharSelectPlayerArray.Count)
		{
			Dest.DWord = pEQ->pCharSelectPlayerArray[VarPtr.Int].Level;
			return true;
		}
		return false;

	case CharSelectListMembers::Class:
		Dest.DWord = 0;
		Dest.Type = pStringType;

		if (pEQ && VarPtr.Int < pEQ->pCharSelectPlayerArray.Count)
		{
			strcpy_s(DataTypeTemp, GetClassDesc(pEQ->pCharSelectPlayerArray[VarPtr.Int].Class));
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case CharSelectListMembers::Race:
		Dest.DWord = 0;
		Dest.Type = pStringType;

		if (pEQ && VarPtr.Int < pEQ->pCharSelectPlayerArray.Count)
		{
			strcpy_s(DataTypeTemp, pEverQuest->GetRaceDesc(pEQ->pCharSelectPlayerArray[VarPtr.Int].Race));
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case CharSelectListMembers::ZoneID:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pEQ && VarPtr.Int < pEQ->pCharSelectPlayerArray.Count)
		{
			int zoneid = pEQ->pCharSelectPlayerArray[VarPtr.Int].CurZoneID;
			Dest.DWord = (zoneid & 0x7FFF);

			return true;
		}
		return false;

	case CharSelectListMembers::Count:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pEQ)
		{
			Dest.DWord = pEQ->pCharSelectPlayerArray.Count;
		}
		return true;

	default: break;
	}

	return false;
}

bool MQ2CharSelectListType::ToString(MQVarPtr VarPtr, char* Destination)
{
	return false;
}

} // namespace mq::datatypes
