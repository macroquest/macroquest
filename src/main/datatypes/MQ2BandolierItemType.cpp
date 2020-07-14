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

bool MQ2BandolierItemType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (BandolierItemInfo* ptr = (BandolierItemInfo*)VarPtr.Ptr)
	{
		MQTypeMember* pMember = MQ2BandolierItemType::FindMember(Member);
		if (pMember)
		{
			switch (static_cast<BandolierItemTypeMembers>(pMember->ID))
			{
			case xIndex:
				Dest.DWord = VarPtr.HighPart;
				Dest.Type = pIntType;
				return true;

			case IconID:
				Dest.DWord = ptr->IconID;
				Dest.Type = pIntType;
				return true;

			case ID:
				Dest.DWord = ptr->ItemID;
				Dest.Type = pIntType;
				return true;

			case Name:
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

