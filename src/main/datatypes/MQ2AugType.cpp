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

enum class AugTypeMembers
{
	Slot,
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

bool MQ2AugType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	CONTENTS* pCont = (CONTENTS*)VarPtr.HighPart;
	if (!pCont)
		return false;

	PITEMINFO pItem = GetItemFromContents(pCont);
	if (!pItem)
		return false;

	MQTypeMember* pMember = MQ2AugType::FindMember(Member);
	if (!pMember)
		return false;

	DWORD index = VarPtr.DWord;

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
		Dest.DWord = pItem->AugData.Sockets[index].bVisible;
		Dest.Type = pBoolType;
		return true;

	case AugTypeMembers::Infusable:
		Dest.DWord = pItem->AugData.Sockets[index].bInfusible;
		Dest.Type = pBoolType;
		return true;

	case AugTypeMembers::Empty:
		Dest.DWord = true;
		Dest.Type = pBoolType;
		if (CONTENTS* pCret = pCont->GetContent(index))
			Dest.DWord = false;
		return true;

	case AugTypeMembers::Name:
		Dest.Type = pStringType;
		if (CONTENTS* pCret = pCont->GetContent(index))
		{
			if (ITEMINFO* pAug = GetItemFromContents(pCret))
			{
				strcpy_s(DataTypeTemp, pAug->Name);
				Dest.Ptr = DataTypeTemp;
				return true;
			}
		}
		return false;

	case AugTypeMembers::Item:
		Dest.Type = pItemType;
		if (CONTENTS* pCret = pCont->GetContent(index))
		{
			Dest.Ptr = pCret;
			return true;
		}
		return false;

	case AugTypeMembers::Solvent:
		Dest.DWord = 0;
		Dest.Type = pSolventType;
		if (CONTENTS* pCret = pCont->GetContent(index))
		{
			if (ITEMINFO* ptheAug = GetItemFromContents(pCret))
			{
				Dest.DWord = ptheAug->SolventItemID;
				return true;
			}
		}
		return false;

	default: break;
	};

	return false;
}

bool MQ2AugType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (CONTENTS* pCont = (CONTENTS*)VarPtr.HighPart)
	{
		if (CONTENTS* pAug = pCont->GetContent(VarPtr.DWord))
		{
			if (ITEMINFO* pAugItem = GetItemFromContents(pAug))
			{
				strcpy_s(Destination, MAX_STRING, pAugItem->Name);
				return true;
			}
		}
	}
	return false;
}

