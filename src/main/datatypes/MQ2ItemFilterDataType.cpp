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

enum class ItemFilterDataMembers
{
	Name = 1,
	ID,
	IconID,
	AutoRoll,
	Need,
	Greed,
	Never,
	Types,
};

MQ2ItemFilterDataType::MQ2ItemFilterDataType() : MQ2Type("itemfilterdata")
{
	ScopedTypeMember(ItemFilterDataMembers, Name);
	ScopedTypeMember(ItemFilterDataMembers, ID);
	ScopedTypeMember(ItemFilterDataMembers, IconID);
	ScopedTypeMember(ItemFilterDataMembers, AutoRoll);
	ScopedTypeMember(ItemFilterDataMembers, Need);
	ScopedTypeMember(ItemFilterDataMembers, Greed);
	ScopedTypeMember(ItemFilterDataMembers, Never);
	ScopedTypeMember(ItemFilterDataMembers, Types);
}

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
	case ItemFilterDataMembers::Name:
		Dest.Type = pStringType;
		if (pItem && pItem->Name[0])
		{
			strcpy_s(DataTypeTemp, pItem->Name);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case ItemFilterDataMembers::ID:
		Dest.DWord = pItem->ID;
		Dest.Type = pIntType;
		return true;

	case ItemFilterDataMembers::AutoRoll:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (pItem)
		{
			bool bAutoRoll = (pItem->Types & (1 << 0)) != 0;
			Dest.Set(bAutoRoll);
		}
		return true;

	case ItemFilterDataMembers::Need:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (pItem)
		{
			bool bNeed = (pItem->Types & (1 << 1)) != 0;
			Dest.Set(bNeed);
		}
		return true;

	case ItemFilterDataMembers::Greed:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (pItem)
		{
			bool bGreed = (pItem->Types & (1 << 2)) != 0;
			Dest.Set(bGreed);
		}
		return true;

	case ItemFilterDataMembers::Never:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (pItem)
		{
			bool bNever = (pItem->Types & (1 << 3)) != 0;
			Dest.Set(bNever);
		}
		return true;

	case ItemFilterDataMembers::IconID:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pItem)
		{
			Dest.DWord = pItem->Icon;
			return true;
		}
		return false;

	case ItemFilterDataMembers::Types:
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

bool MQ2ItemFilterDataType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (ItemFilterData* pitem = (ItemFilterData*)VarPtr.Ptr)
	{
		strcpy_s(Destination, 64, pitem->Name);
		return true;
	}
	return false;
}

bool MQ2ItemFilterDataType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pItemFilterDataType)
		return false;
	VarPtr.Ptr = Source.Ptr;
	return true;
}

} // namespace mq::datatypes
