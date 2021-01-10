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

enum class PointMerchantItemMembers
{
	Name = 1,
	ItemID,
	Price,
	ThemeID,
	IsStackable,
	IsLore,
	RaceMask,
	ClassMask,
	CanUse,
};

enum class PointMerchantMethods
{
};

MQ2PointMerchantItemType::MQ2PointMerchantItemType()
	: MQ2Type("pointmerchantitem")
{
	ScopedTypeMember(PointMerchantItemMembers, Name);
	ScopedTypeMember(PointMerchantItemMembers, ItemID);
	ScopedTypeMember(PointMerchantItemMembers, Price);
	ScopedTypeMember(PointMerchantItemMembers, ThemeID);
	ScopedTypeMember(PointMerchantItemMembers, IsStackable);
	ScopedTypeMember(PointMerchantItemMembers, IsLore);
	ScopedTypeMember(PointMerchantItemMembers, RaceMask);
	ScopedTypeMember(PointMerchantItemMembers, ClassMask);
	ScopedTypeMember(PointMerchantItemMembers, CanUse);
}

bool MQ2PointMerchantItemType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pMerchantWnd) return false;

	MQTypeMember* pMember = MQ2PointMerchantItemType::FindMember(Member);
	if (!pMember) return false;

	int index = VarPtr.Int;
	auto& itemContainer = pMerchantWnd->PageHandlers[RegularMerchantPage]->ItemContainer;

	if (index < 0 || index > itemContainer.GetSize())
		return false;

	ItemPtr pItem = itemContainer[index].pItem;
	if (!pItem)
		return false;

	switch (static_cast<PointMerchantItemMembers>(pMember->ID))
	{
	case PointMerchantItemMembers::Name:
		strcpy_s(DataTypeTemp, pItem->GetName());
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case PointMerchantItemMembers::ItemID:
		Dest.Int = pItem->GetID();
		Dest.Type = pIntType;
		return true;

	case PointMerchantItemMembers::Price:
		if (pItem->GetItemDefinition()->LDTheme)
			Dest.Int64 = pItem->GetItemDefinition()->LDCost;
		else
			Dest.Int64 = pItem->Price;
		Dest.Type = pInt64Type;
		return true;

	case PointMerchantItemMembers::ThemeID:
		Dest.Int = pItem->GetItemDefinition()->LDTheme;
		Dest.Type = pIntType;
		return true;

	case PointMerchantItemMembers::IsStackable:
		Dest.Set(pItem->IsStackable());
		Dest.Type = pBoolType;
		return true;

	case PointMerchantItemMembers::IsLore:
		Dest.Set(pItem->GetItemDefinition()->Lore != 0);
		Dest.Type = pBoolType;
		return true;

	case PointMerchantItemMembers::RaceMask:
		Dest.Int = pItem->GetItemDefinition()->Races;
		Dest.Type = pIntType;
		return true;

	case PointMerchantItemMembers::ClassMask:
		Dest.Int = pItem->GetItemDefinition()->Classes;
		Dest.Type = pIntType;
		return true;

	case PointMerchantItemMembers::CanUse:
		Dest.Set(pCharData->CanUseItem(pItem, false, false));
		Dest.Type = pBoolType;
		return true;
	}
	return false;
}

bool MQ2PointMerchantItemType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (pMerchantWnd)
	{
		auto& itemContainer = pMerchantWnd->PageHandlers[RegularMerchantPage]->ItemContainer;
		int index = VarPtr.Int;

		if (index >= 0 && index < itemContainer.GetSize())
		{
			strcpy_s(Destination, MAX_STRING, itemContainer[index].pCont->GetName());
			return true;
		}
	}

	return false;
}

} // namespace mq::datatypes
