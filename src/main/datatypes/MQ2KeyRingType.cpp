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

enum class KeyRingTypeMembers
{
	Count = 1,
	Stat = 2,
};

MQ2KeyRingType::MQ2KeyRingType() : MQ2Type("keyring")
{
	ScopedTypeMember(KeyRingTypeMembers, Count);
	ScopedTypeMember(KeyRingTypeMembers, Stat);
}

bool MQ2KeyRingType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pLocalPC)
		return false;
	MQTypeMember* pMember = FindMember(Member);
	if (!pMember)
		return false;

	KeyRingType type = static_cast<KeyRingType>(VarPtr.DWord);

	switch (static_cast<KeyRingTypeMembers>(pMember->ID))
	{
	case KeyRingTypeMembers::Count: {
		ItemContainer& keyRingContainer = pLocalPC->GetKeyRingItems(type);
		Dest.DWord = keyRingContainer.GetCount();
		Dest.Type = pIntType;
		return true;
	}

	case KeyRingTypeMembers::Stat:
		if (pLocalPC->GetStatKeyRingItemIndex(type).IsValid())
		{
			Dest = pKeyRingItemType->MakeTypeVar(type, pLocalPC->GetStatKeyRingItemIndex(type).GetTopSlot());
			return true;
		}
		break;
	}

	return false;
}

MQTypeVar MQ2KeyRingType::MakeTypeVar(int keyRingType)
{
	MQTypeVar Ret;

	Ret.DWord = keyRingType;
	Ret.Type = pKeyRingType;
	return Ret;
}

static bool dataGetKeyRing(KeyRingType keyRingType, const char* szIndex, MQTypeVar& Ret)
{
	if (!pLocalPC)
		return false;

	// If an index is provided, we immediately convert into a KeyRingItem type
	if (szIndex[0])
	{
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
					Ret = pKeyRingItemType->MakeTypeVar(keyRingType, (int)itemIndex);
					return true;
				}
			}
		}
		else
		{
			// handle string.
			const char* pName = szIndex;
			bool exact = pName[0] == '=' && pName++;

			ItemIndex index = pLocalPC->GetKeyRingItems(keyRingType).FindItem(0, FindItemByNamePred(pName, exact));
			if (index.IsValid())
			{
				Ret = pKeyRingItemType->MakeTypeVar(keyRingType, index.GetTopSlot());
				return true;
			}
		}
	}
	else
	{
		Ret = pKeyRingType->MakeTypeVar(keyRingType);
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

#if HAS_TELEPORTATION_KEYRING
bool MQ2KeyRingType::dataTeleportationItem(const char* szIndex, MQTypeVar& Ret)
{
	return dataGetKeyRing(eTeleportationItem, szIndex, Ret);
}
#endif

#if HAS_ACTIVATED_ITEM_KEYRING
bool MQ2KeyRingType::dataActivatedItem(const char* szIndex, MQTypeVar& Ret)
{
	return dataGetKeyRing(eActivatedItem, szIndex, Ret);
}
#endif

#if HAS_EQUIPMENT_KEYRING
bool MQ2KeyRingType::dataEquipmentItem(const char* szIndex, MQTypeVar& Ret)
{
	return dataGetKeyRing(eEquipmentKeyRing, szIndex, Ret);
}
#endif

//============================================================================
// MQ2KeyRingItemType

enum class KeyRingItemTypeMembers
{
	Index = 1,
	Name,
	Item,
};

MQ2KeyRingItemType::MQ2KeyRingItemType() : MQ2Type("keyringitem")
{
	ScopedTypeMember(KeyRingItemTypeMembers, Index);
	ScopedTypeMember(KeyRingItemTypeMembers, Name);
	ScopedTypeMember(KeyRingItemTypeMembers, Item);
}

bool MQ2KeyRingItemType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pLocalPC)
		return false;
	MQTypeMember* pMember = MQ2KeyRingItemType::FindMember(Member);
	if (!pMember)
		return false;

	int16_t n = LOWORD(VarPtr.DWord);
	KeyRingType type = static_cast<KeyRingType>(HIWORD(VarPtr.DWord));

	switch (static_cast<KeyRingItemTypeMembers>(pMember->ID))
	{
	case KeyRingItemTypeMembers::Index:
		// We want the index of the item that is in the UI list, so we need to map back from the item
		// to the UI index.
		Dest.Type = pIntType;

		if (pKeyRingWnd)
		{
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

	case KeyRingItemTypeMembers::Name:
		Dest.Type = pStringType;
		if (ItemPtr item = pLocalPC->GetKeyRingItems(type).GetItem(n))
		{
			strcpy_s(DataTypeTemp, item->GetItemDefinition()->Name);
			Dest.Ptr = &DataTypeTemp[0];
		}
		return true;

	case KeyRingItemTypeMembers::Item:
		Dest = pItemType->MakeTypeVar(pLocalPC->GetKeyRingItems(type).GetItem(n));
		return true;
	}

	return false;
}

bool MQ2KeyRingItemType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (!pLocalPC)
		return false;

	KeyRingType type = static_cast<KeyRingType>(HIWORD(VarPtr.DWord));
	int16_t n = LOWORD(VarPtr.DWord);

	if (ItemPtr item = pLocalPC->GetKeyRingItems(type).GetItem(n))
	{
		strcpy_s(Destination, MAX_STRING, item->GetItemDefinition()->Name);
		return true;
	}

	return false;
}

MQTypeVar MQ2KeyRingItemType::MakeTypeVar(int keyRingType, int itemIndex)
{
	MQTypeVar Ret;

	Ret.DWord = MAKELPARAM(itemIndex, keyRingType);
	Ret.Type = pKeyRingItemType;
	return Ret;
}

} // namespace mq::datatypes
