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

enum class AugTypeMembers
{
	Slot = 1,
	Type,
	Visible,
	Infusable,
	Empty,
	Name,
	Item,
	Solvent
};

MQ2AugType::MQ2AugType() : MQ2Type("augtype")
{
	ScopedTypeMember(AugTypeMembers, Slot);
	ScopedTypeMember(AugTypeMembers, Type);
	ScopedTypeMember(AugTypeMembers, Visible);
	ScopedTypeMember(AugTypeMembers, Infusable);
	ScopedTypeMember(AugTypeMembers, Empty);
	ScopedTypeMember(AugTypeMembers, Name);
	ScopedTypeMember(AugTypeMembers, Item);
	ScopedTypeMember(AugTypeMembers, Solvent);
}

bool MQ2AugType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pLocalPC)
		return false;

	auto slotWithIdx = VarPtr.Get<MQSlotInItem>();
	if (!slotWithIdx)
		return false;

	auto globalIdx = slotWithIdx->GlobalIndex;
	auto pCont = pLocalPC->GetItemByGlobalIndex(globalIdx);
	if (!pCont)
		return false;

	auto pItem = pCont->GetItemDefinition();
	if (!pItem)
		return false;

	int index = slotWithIdx->Slot;

	MQTypeMember* pMember = MQ2AugType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<AugTypeMembers>(pMember->ID))
	{
	case AugTypeMembers::Slot:
		Dest.DWord = index + 1;
		Dest.Type = pIntType;
		return true;

	case AugTypeMembers::Type:
		Dest.DWord = pItem->AugData.Sockets[index].Type;
		Dest.Type = pIntType;
		return true;

	case AugTypeMembers::Visible:
		Dest.Set(pItem->AugData.Sockets[index].bVisible);
		Dest.Type = pBoolType;
		return true;

	case AugTypeMembers::Infusable:
		Dest.Set(pItem->AugData.Sockets[index].bInfusible);
		Dest.Type = pBoolType;
		return true;

	case AugTypeMembers::Empty:
		Dest.Set(pCont->GetContent(index) == nullptr);
		Dest.Type = pBoolType;
		return true;

	case AugTypeMembers::Name:
		Dest.Type = pStringType;
		if (ItemClient* pCret = pCont->GetContent(index))
		{
			strcpy_s(DataTypeTemp, pCret->GetName());
			Dest.Ptr = DataTypeTemp;
			return true;
		}
		return false;

	case AugTypeMembers::Item:
		Dest = pItemType->MakeTypeVar(pCont->GetHeldItem(index));
		return true;

	case AugTypeMembers::Solvent:
		Dest.DWord = 0;
		Dest.Type = pSolventType;
		if (ItemPtr pItem = pCont->GetHeldItem(index))
		{
			Dest.DWord = pItem->GetItemDefinition()->SolventItemID;
			return true;
		}
		return false;

	default:
		return false;
	};
}

bool MQ2AugType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (!pLocalPC)
		return false;

	auto slotWithIdx = VarPtr.Get<MQSlotInItem>();
	if (!slotWithIdx)
		return false;

	auto globalIdx = slotWithIdx->GlobalIndex;
	auto pCont = pLocalPC->GetItemByGlobalIndex(globalIdx);
	if (!pCont)
		return false;

	int index = slotWithIdx->Slot;
	auto pAugCont = pCont->GetContent(index);
	if (!pAugCont)
		return false;

	auto pAug = pAugCont->GetItemDefinition();
	if (!pAug)
		return false;

	strcpy_s(Destination, MAX_STRING, pAug->Name);
	return true;
}

} // namespace mq::datatypes
