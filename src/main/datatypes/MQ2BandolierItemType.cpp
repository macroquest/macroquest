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

namespace mq::datatypes {

enum class BandolierItemTypeMembers
{
	Index = 1,
	ID ,
	IconID,
	Name,
};

MQ2BandolierItemType::MQ2BandolierItemType() : MQ2Type("bandolieritem")
{
	ScopedTypeMember(BandolierItemTypeMembers, Index);
	ScopedTypeMember(BandolierItemTypeMembers, ID);
	ScopedTypeMember(BandolierItemTypeMembers, IconID);
	ScopedTypeMember(BandolierItemTypeMembers, Name);
}

bool MQ2BandolierItemType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (BandolierItemInfo* ptr = (BandolierItemInfo*)VarPtr.Ptr)
	{
		MQTypeMember* pMember = MQ2BandolierItemType::FindMember(Member);
		if (pMember)
		{
			switch (static_cast<BandolierItemTypeMembers>(pMember->ID))
			{
			case BandolierItemTypeMembers::Index:
				Dest.DWord = VarPtr.HighPart;
				Dest.Type = pIntType;
				return true;

			case BandolierItemTypeMembers::IconID:
				Dest.DWord = ptr->IconID;
				Dest.Type = pIntType;
				return true;

			case BandolierItemTypeMembers::ID:
				Dest.DWord = ptr->ItemID;
				Dest.Type = pIntType;
				return true;

			case BandolierItemTypeMembers::Name:
				strcpy_s(DataTypeTemp, ptr->Name);
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;

			default: break;
			};

			return false;
		}
	}
	return false;
}

bool MQ2BandolierItemType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (BandolierItemInfo* ptr = reinterpret_cast<BandolierItemInfo*>(VarPtr.Ptr))
	{
		strcpy_s(Destination, MAX_STRING, ptr->Name);
		return true;
	}
	return false;
}

} // namespace mq::datatypes
