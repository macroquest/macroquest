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
	MQTypeMember* pMember = MQ2CorpseType::FindMember(Member);
	if (!pMember)
	{
		return pSpawnType->GetMember(pActiveCorpse, Member, Index, Dest);
	}

	if (pMember && static_cast<CorpseMembers>(pMember->ID) == CorpseMembers::Open)
	{
		Dest.Set(pActiveCorpse != nullptr);
		Dest.Type = pBoolType;
		return true;
	}

	if (!pActiveCorpse || !pLootWnd)
		return false;

	switch (static_cast<CorpseMembers>(pMember->ID))
	{
	case CorpseMembers::Item:
		Dest.Type = pItemType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nIndex = GetIntFromString(Index, 0) - 1;
				if (nIndex < 0 || nIndex >= InvSlot_Max)
					return true;

				Dest = pItemType->MakeTypeVar(pLootWnd->GetLootItem(nIndex));
				return true;
			}

			// name
			char* pName1 = Index;
			bool bExact = (*pName1 == '=') && ++pName1;

			ItemIndex itemIndex = pLootWnd->GetLootItems().FindItem(0, FindItemByNamePred(pName1, bExact));
			if (itemIndex.IsValid())
			{
				Dest = pItemType->MakeTypeVar(pLootWnd->GetLootItems().GetItem(itemIndex));
				return true;
			}
		}

		return true;

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

bool MQ2CorpseType::Downcast(const MQVarPtr& fromVar, MQVarPtr& toVar, MQ2Type* toType)
{
	if (toType == pSpawnType)
	{
		toVar = pSpawnType->MakeTypeVar(pActiveCorpse);
		return true;
	}

	return false;
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
