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

bool MQ2ItemFilterDataType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	ItemFilterData* pItem = (ItemFilterData*)VarPtr.Ptr;
	if (!pItem)
		return false;

	MQTypeMember* pMember = MQ2ItemFilterDataType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ItemFilterDataMembers>(pMember->ID))
	{
	case Name:
		Dest.Type = pStringType;
		if (pItem && pItem->Name[0])
		{
			strcpy_s(DataTypeTemp, pItem->Name);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case ID:
		Dest.DWord = pItem->ID;
		Dest.Type = pIntType;
		return true;

	case AutoRoll:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (pItem)
		{
			bool bAutoRoll = (pItem->Types & (1 << 0)) != 0;
			Dest.Set(bAutoRoll);
		}
		return true;

	case Need:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (pItem)
		{
			bool bNeed = (pItem->Types & (1 << 1)) != 0;
			Dest.Set(bNeed);
		}
		return true;

	case Greed:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (pItem)
		{
			bool bGreed = (pItem->Types & (1 << 2)) != 0;
			Dest.Set(bGreed);
		}
		return true;

	case Never:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (pItem)
		{
			bool bNever = (pItem->Types & (1 << 3)) != 0;
			Dest.Set(bNever);
		}
		return true;

	case IconID:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pItem)
		{
			Dest.DWord = pItem->Icon;
			return true;
		}
		return false;

	case Types:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pItem)
		{
			Dest.DWord = pItem->Types;
			return true;
		}
		return false;

	default: break;
	}
	return false;
}

