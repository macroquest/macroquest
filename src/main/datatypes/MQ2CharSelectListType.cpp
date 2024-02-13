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
	if (!pMember || !pEverQuest)
		return false;

	if (static_cast<CharSelectListMembers>(pMember->ID) == CharSelectListMembers::Count)
	{
		Dest.Type = pIntType;
		Dest.DWord = pEverQuest->charSelectPlayerArray.GetCount();
		return true;
	}

	if (VarPtr.Int < 0 || VarPtr.Int >= pEverQuest->charSelectPlayerArray.GetCount())
		return false;

	CharSelectInfo& csInfo = pEverQuest->charSelectPlayerArray[VarPtr.Int];

	switch (static_cast<CharSelectListMembers>(pMember->ID))
	{
	case CharSelectListMembers::Name:
		Dest.Type = pStringType;
		strcpy_s(DataTypeTemp, csInfo.Name);
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case CharSelectListMembers::Level:
		Dest.Type = pIntType;
		Dest.DWord = csInfo.Level;
		return true;

	case CharSelectListMembers::Class:
		Dest.Type = pStringType;
		strcpy_s(DataTypeTemp, GetClassDesc(csInfo.Class));
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case CharSelectListMembers::Race:
		Dest.Type = pStringType;
		strcpy_s(DataTypeTemp, pEverQuest->GetRaceDesc(csInfo.Race));
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case CharSelectListMembers::ZoneID:
		Dest.Type = pIntType;
		Dest.DWord = (csInfo.CurZoneID & 0x7FFF);
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
