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

enum class CorpseMembers
{
	Open = 1,
	Item,
	Items,
};

MQ2CorpseType::MQ2CorpseType() : MQ2Type("corpse")
{
	ScopedTypeMember(CorpseMembers, Open);
	ScopedTypeMember(CorpseMembers, Item);
	ScopedTypeMember(CorpseMembers, Items);
}

bool MQ2CorpseType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pActiveCorpse || !pLootWnd)
		return false;

	MQTypeMember* pMember = MQ2CorpseType::FindMember(Member);
	if (!pMember)
	{
		MQVarPtr data;
		data.Ptr = pActiveCorpse;
		return pSpawnType->GetMember(data, Member, Index, Dest);
	}

	switch (static_cast<CorpseMembers>(pMember->ID))
	{
	case CorpseMembers::Open:
		Dest.Set(true); // obviously, since we're this far
		Dest.Type = pBoolType;
		return true;

	case CorpseMembers::Item:
		Dest.Type = pItemType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nIndex = GetIntFromString(Index, 0) - 1;
				if (nIndex < 0 || nIndex >= InvSlot_Max)
					return false;

				if (Dest.Ptr = pLootWnd->GetLootItem(nIndex).get())
					return true;
			}
			else
			{
				// name
				char* pName1 = Index;
				bool bExact = (*pName1 == '=') && ++pName1;

				ItemIndex itemIndex = pLootWnd->GetLootItems().FindItem(0, FindItemByNamePred(pName1, bExact));
				if (itemIndex.IsValid())
				{
					Dest.Ptr = pLootWnd->GetLootItems().GetItem(itemIndex).get();
					return true;
				}
			}
		}
		return false;

	case CorpseMembers::Items:
		Dest.DWord = pLootWnd->GetLootItems().GetCount();
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2CorpseType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (pActiveCorpse && pLootWnd)
	{
		strcpy_s(Destination, MAX_STRING, "TRUE");
	}
	else
	{
		strcpy_s(Destination, MAX_STRING, "FALSE");
	}
	return true;
}

bool MQ2CorpseType::dataCorpse(const char* szIndex, MQTypeVar& Ret)
{
	if (pLootWnd)
	{
		Ret.Ptr = pLootWnd;
		Ret.Type = pCorpseType;
		return true;
	}
	return false;
}

} // namespace mq::datatypes
