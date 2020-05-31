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

enum class KeyRingTypeMembers
{
	Index = 1,
	Name = 2,
	Item = 3,
};

MQ2KeyRingType::MQ2KeyRingType() : MQ2Type("keyring")
{
	ScopedTypeMember(KeyRingTypeMembers, Index);
	ScopedTypeMember(KeyRingTypeMembers, Name);
	ScopedTypeMember(KeyRingTypeMembers, Item);
}

bool MQ2KeyRingType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2KeyRingType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<KeyRingTypeMembers>(pMember->ID))
	{
	case KeyRingTypeMembers::Index:
		// We want the index of the item that is in the UI list, so we need to map back from the item
		// to the UI index.
		Dest.Type = pIntType;
		if (pCharData && pKeyRingWnd)
		{
			int16_t n = LOWORD(VarPtr.DWord);
			KeyRingType type = static_cast<KeyRingType>(HIWORD(VarPtr.DWord));

			RefreshKeyRingWindow();

			if (CListWnd* pListWnd = pKeyRingWnd->GetKeyRingList(type))
			{
				for (int i = 0; i < pListWnd->ItemsArray.GetCount(); ++i)
				{
					int slotNum = (int)pListWnd->GetItemData(i);
					if (slotNum == n)
					{
						Dest.DWord = i + 1;
						return true;
					}
				}
			}
		}
		return false;

	case KeyRingTypeMembers::Name:
		Dest.Type = pStringType;
		if (pCharData)
		{
			int16_t n = LOWORD(VarPtr.DWord);
			KeyRingType type = static_cast<KeyRingType>(HIWORD(VarPtr.DWord));

			VePointer<CONTENTS> item = pCharData->GetKeyRingItems(type).GetItem(n);
			if (item)
			{
				strcpy_s(DataTypeTemp, item->GetItemDefinition()->Name);
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
		}
		return false;

	case KeyRingTypeMembers::Item:
		Dest.Type = pItemType;
		if (pCharData)
		{
			int16_t n = LOWORD(VarPtr.DWord);
			KeyRingType type = static_cast<KeyRingType>(HIWORD(VarPtr.DWord));

			VePointer<CONTENTS> item = pCharData->GetKeyRingItems(type).GetItem(n);
			if (item)
			{
				Dest.Ptr = item.get();
				return true;
			}
		}
		return false;
	}

	return false;
}

bool MQ2KeyRingType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (!pCharData)
		return false;

	KeyRingType type = static_cast<KeyRingType>(HIWORD(VarPtr.DWord));
	int16_t n = LOWORD(VarPtr.DWord);

	VePointer<CONTENTS> item = pCharData->GetKeyRingItems(type).GetItem(n);
	if (item)
	{
		strcpy_s(Destination, MAX_STRING, item->GetItemDefinition()->Name);
		return true;
	}

	return false;
}

static bool dataGetKeyRing(KeyRingType keyRingType, const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	if (!pCharData)
		return false;

	if (IsNumber(szIndex))
	{
		int n = GetIntFromString(szIndex, 0) - 1;
		if (n < 0)
			return false;

		if (!pKeyRingWnd)
			return false;

		// We want to use order given by the keyrings window.
		RefreshKeyRingWindow();

		if (CListWnd* pListWnd = pKeyRingWnd->GetKeyRingList(keyRingType))
		{
			int itemIndex = (int)pListWnd->GetItemData(n);
			if (itemIndex >= 0)
			{
				Ret.DWord = MAKELPARAM((int)itemIndex, keyRingType);
				Ret.Type = pKeyRingType;
				return true;
			}
		}

		return false;
	}

	// handle string.
	const char* pName = szIndex;
	bool exact = pName[0] == '=' && pName++;

	ItemIndex index = pCharData->GetKeyRingItems(keyRingType).FindItem(FindItemByNamePred(pName, exact));
	if (index.IsValid())
	{
		Ret.DWord = MAKELPARAM(index.GetTopSlot(), keyRingType);
		Ret.Type = pKeyRingType;
		return true;
	}

	return false;
}

bool MQ2KeyRingType::dataMount(const char* szIndex, MQTypeVar& Ret)
{
	return dataGetKeyRing(eMount, szIndex, Ret);
}

bool MQ2KeyRingType::dataIllusion(const char* szIndex, MQTypeVar& Ret)
{
	return dataGetKeyRing(eIllusion, szIndex, Ret);
}

bool MQ2KeyRingType::dataFamiliar(const char* szIndex, MQTypeVar& Ret)
{
	return dataGetKeyRing(eFamiliar, szIndex, Ret);
}

} // namespace mq::datatypes
