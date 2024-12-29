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
#include "MQ2DataTypes.h"

namespace mq::datatypes {

//============================================================================

enum class CursorAttachmentTypeMembers
{
	Index,
	IconID,
	ItemID,
	Type,
	Quantity,
	Item,
	Spell,
	ButtonText,
};

MQCursorAttachmentType::MQCursorAttachmentType() : MQ2Type("cursorattachment")
{
	ScopedTypeMember(CursorAttachmentTypeMembers, Index);
	ScopedTypeMember(CursorAttachmentTypeMembers, IconID);
	ScopedTypeMember(CursorAttachmentTypeMembers, ItemID);
	ScopedTypeMember(CursorAttachmentTypeMembers, Type);
	ScopedTypeMember(CursorAttachmentTypeMembers, Quantity);
	ScopedTypeMember(CursorAttachmentTypeMembers, Item);
	ScopedTypeMember(CursorAttachmentTypeMembers, Spell);
	ScopedTypeMember(CursorAttachmentTypeMembers, ButtonText);
}

bool MQCursorAttachmentType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pLocalPC || !pLocalPlayer)
		return false;

	if (!pCursorAttachment)
		return false;

	MQTypeMember* pMember = FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<CursorAttachmentTypeMembers>(pMember->ID))
	{
	case CursorAttachmentTypeMembers::Index:
		Dest.Type = pIntType;
		Dest.Int = pCursorAttachment->Index;
		return true;

	case CursorAttachmentTypeMembers::IconID:
		Dest.Type = pIntType;
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_TBL) // Rough approximation -- Added in 2018/06/19
		Dest.Int = pCursorAttachment->IconID;
#else
		Dest.Int = -1;
#endif
		return true;

	case CursorAttachmentTypeMembers::ItemID:
		Dest.Type = pIntType;
		Dest.Int = pCursorAttachment->ItemID;
		return true;
	
	case CursorAttachmentTypeMembers::Type:
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];

		switch (pCursorAttachment->Type)
		{
		case eCursorAttachment_MemorizeSpell: strcpy_s(DataTypeTemp, "MEMORIZE_SPELL"); return true;
		case eCursorAttachment_Item: strcpy_s(DataTypeTemp, "ITEM"); return true;
		case eCursorAttachment_Money: strcpy_s(DataTypeTemp, "MONEY"); return true;
		case eCursorAttachment_Social: strcpy_s(DataTypeTemp, "SOCIAL"); return true;
		case eCursorAttachment_MenuButton: strcpy_s(DataTypeTemp, "MENU_BUTTON"); return true;
		case eCursorAttachment_Ability: strcpy_s(DataTypeTemp, "ABILITY"); return true; //?
		case eCursorAttachment_Combat: strcpy_s(DataTypeTemp, "COMBAT"); return true; // ? 
		case eCursorAttachment_InvSlot: strcpy_s(DataTypeTemp, "INVSLOT"); return true;
		case eCursorAttachment_SpellGem: strcpy_s(DataTypeTemp, "SPELL_GEM"); return true;
		case eCursorAttachment_PetCommand: strcpy_s(DataTypeTemp, "PET_COMMAND"); return true;
		case eCursorAttachment_SkillID: strcpy_s(DataTypeTemp, "SKILL"); return true; // ?
		case eCursorAttachment_MeleeAbility: strcpy_s(DataTypeTemp, "MELEE_ABILITY"); return true; // ?
#if HAS_LEADERSHIP_EXPERIENCE
		case eCursorAttachment_LeadershipAbility: strcpy_s(DataTypeTemp, "LEADERSHIP_ABILITY"); return true;
#endif
		case eCursorAttachment_ItemLink: strcpy_s(DataTypeTemp, "ITEM_LINK"); return true;
		case eCursorAttachment_KronoSlot: strcpy_s(DataTypeTemp, "KRONO_SLOT"); return true;
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_TBM)
		case eCursorAttachment_Command: strcpy_s(DataTypeTemp, "COMMAND"); return true;
		case eCursorAttachment_CombatAbility: strcpy_s(DataTypeTemp, "COMBAT_ABILITY"); return true;
#endif
#if HAS_KEYRING_WINDOW
		case eCursorAttachment_MountKeyRingLink: strcpy_s(DataTypeTemp, "MOUNT_KEYRING"); return true;
		case eCursorAttachment_IllusionKeyRingLink: strcpy_s(DataTypeTemp, "ILLUSION_KEYRING"); return true;
		case eCursorAttachment_FamiliarKeyRingLink: strcpy_s(DataTypeTemp, "FAMILIAR_KEYRING"); return true;
#endif
#if HAS_TELEPORTATION_KEYRING
		case eCursorAttachment_TeleportationKeyRingLink: strcpy_s(DataTypeTemp, "TELEPORT_KEYRING"); return true;
#endif
#if HAS_ACTIVATED_ITEM_KEYRING
		case eCursorAttachment_ActivatedKeyRingLink: strcpy_s(DataTypeTemp, "ACTIVATED_KEYRING"); return true;
#endif
		default:
		case eCursorAttachment_None: return false;
		}

	case CursorAttachmentTypeMembers::Quantity:
		Dest.Type = pIntType;
		Dest.Int = pCursorAttachment->Qty;
		return true;

	case CursorAttachmentTypeMembers::Item:
	{
		ItemPtr pItem;
		ItemIndex itemIndex;
	
		switch (pCursorAttachment->Type)
		{
		case eCursorAttachment_Item:
			pItem = pLocalPC->GetInventorySlot(InvSlot_Held);
			break;

		case eCursorAttachment_InvSlot:
			pItem = pLocalPC->GetInventorySlot(pCursorAttachment->Index);
			break;

		case eCursorAttachment_ItemLink:
			itemIndex = pLocalPC->FindItemByGuid(pCursorAttachment->ItemGuid);
			if (!itemIndex.IsValid())
			{
				itemIndex = pLocalPC->FindItemById(pCursorAttachment->ItemID);
			}

			pItem = pLocalPC->GetItemPossession(itemIndex);
			break;

#if HAS_KEYRING_WINDOW
		case eCursorAttachment_FamiliarKeyRingLink:
		case eCursorAttachment_MountKeyRingLink:
		case eCursorAttachment_IllusionKeyRingLink:
#if HAS_TELEPORTATION_KEYRING
		case eCursorAttachment_TeleportationKeyRingLink:
#endif
#if HAS_ACTIVATED_ITEM_KEYRING
		case eCursorAttachment_ActivatedKeyRingLink:
#endif
		{
			KeyRingType keyRingType;

			switch (pCursorAttachment->Type)
			{
			case eCursorAttachment_MountKeyRingLink: keyRingType = eMount; break;
			case eCursorAttachment_IllusionKeyRingLink: keyRingType = eIllusion; break;
			case eCursorAttachment_FamiliarKeyRingLink: keyRingType = eFamiliar; break;
#if HAS_TELEPORTATION_KEYRING
			case eCursorAttachment_TeleportationKeyRingLink: keyRingType = eTeleportationItem; break;
#endif
#if HAS_ACTIVATED_ITEM_KEYRING
			case eCursorAttachment_ActivatedKeyRingLink: keyRingType = eActivatedItem; break;
#endif
			default: return false;
			}

			itemIndex = pLocalPC->FindKeyRingItemByGuid(keyRingType, pCursorAttachment->ItemGuid);
			if (!itemIndex.IsValid())
			{
				itemIndex = pLocalPC->FindKeyRingItemById(keyRingType, pCursorAttachment->ItemID);
			}

			pItem = pLocalPC->GetKeyRingItem(keyRingType, itemIndex);
		}
#endif
		default: break;
		}

		if (pItem)
		{
			Dest.Type = pItemType;
			Dest.Item = pItem;
			return true;
		}

		return false;
	}

	case CursorAttachmentTypeMembers::Spell:
	{
		EQ_Spell* pSpell = nullptr;

		if (pCursorAttachment->Type == eCursorAttachment_SpellGem)
		{
			int SpellID = pLocalPC->GetMemorizedSpell(pCursorAttachment->Index);

			pSpell = GetSpellByID(SpellID);
		}

		else if (pCursorAttachment->Type == eCursorAttachment_MemorizeSpell)
		{
			int SpellID = pLocalPC->GetSpellBook(pCursorAttachment->Index);

			pSpell = GetSpellByID(SpellID);
		}

		if (pSpell)
		{
			Dest.Type = pSpellType;
			Dest.Ptr = pSpell;
			return true;
		}

		return false;
	}

	case CursorAttachmentTypeMembers::ButtonText:
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		strcpy_s(DataTypeTemp, pCursorAttachment->ButtonText.c_str());
		return true;

	default:
		break;
	}

	return false;
}

bool MQCursorAttachmentType::dataCursorAttachment(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Ptr = nullptr;
	Ret.Type = pCursorAttachmentType;
	return true;
}

} // namespace mq::datatypes