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

enum class ItemMembers
{
	ID = 1,
	Name,
	Lore,
	NoDrop,
	NoRent,
	Magic,
	Value,
	Size,
	Weight,
	Stack,
	Type,
	Charges,
	LDoNTheme,
	DMGBonusType,
	BuyPrice,
	Haste,
	Endurance,
	Attack,
	HPRegen,
	ManaRegen,
	DamShield,
	WeightReduction,
	SizeCapacity,
	Combinable,
	Skill,
	Avoidance,
	SpellShield,
	StrikeThrough,
	StunResist,
	Shielding,
	FocusID,
	ProcRate,
	Quality,
	LDoNCost,
	AugRestrictions,
	AugType,
	AugSlot1,
	AugSlot2,
	AugSlot3,
	AugSlot4,
	AugSlot5,
	AugSlot6,
	Damage,
	Range,
	DMGBonus,
	RecommendedLevel,
	RecommendedSkill,
	Delay,
	Light,
	Level,
	BaneDMG,
	SkillModValue,
	InstrumentType,
	InstrumentMod,
	RequiredLevel,
	BaneDMGType,
	AC,
	HP,
	Mana,
	STR,
	STA,
	AGI,
	DEX,
	CHA,
	INT,
	WIS,
	svCold,
	svFire,
	svMagic,
	svDisease,
	svPoison,
	Summoned,
	Artifact,
	PendingLore,
	LoreText,
	Items,
	Item,
	Container,
	Stackable,
	InvSlot,
	SellPrice,
	WornSlot,
	WornSlots,
	CastTime,
	Spell,
	EffectType,
	Tribute,
	Attuneable,
	Timer,
	ItemDelay,
	TimerReady,
	StackSize,
	Stacks,
	StackCount,
	FreeStack,
	MerchQuantity,
	Classes,
	Class,
	Races,
	Race,
	Deities,
	Deity,
	Evolving,
	svCorruption,
	Power,
	MaxPower,
	Purity,
	Accuracy,
	CombatEffects,
	DoTShielding,
	HeroicSTR,
	HeroicINT,
	HeroicWIS,
	HeroicAGI,
	HeroicDEX,
	HeroicSTA,
	HeroicCHA,
	HeroicSvMagic,
	HeroicSvFire,
	HeroicSvCold,
	HeroicSvDisease,
	HeroicSvPoison,
	HeroicSvCorruption,
	EnduranceRegen,
	HealAmount,
	Clairvoyance,
	DamageShieldMitigation,
	SpellDamage,
	Augs,
	Tradeskills,
	ItemSlot,
	ItemSlot2,
	Address,
	PctPower,
	Prestige,
	FirstFreeSlot,
	SlotsUsedByItem,
	Heirloom,
	Collectible,
	NoDestroy,
	Quest,
	Expendable,
	ContAddress,
	ItemLink,
	Icon,
	SkillModMax,
	OrnamentationIcon,
	ContentSize,
	Open,
	NoTrade,
	AugSlot,
	Clicky,
	Proc,
	Worn,
	Focus,
	Scroll,
	Focus2,
	Mount,
	Illusion,
	Familiar,
	CanUse,
	LoreEquipped,
	Luck,
	MinLuck,
	MaxLuck
};

enum class ItemMethods
{
};

MQ2ItemType::MQ2ItemType() : MQ2Type("item")
{
	ScopedTypeMember(ItemMembers, ID);
	ScopedTypeMember(ItemMembers, Name);
	ScopedTypeMember(ItemMembers, Lore);
	ScopedTypeMember(ItemMembers, NoDrop);
	ScopedTypeMember(ItemMembers, NoRent);
	ScopedTypeMember(ItemMembers, Magic);
	ScopedTypeMember(ItemMembers, Value);
	ScopedTypeMember(ItemMembers, Size);
	ScopedTypeMember(ItemMembers, Weight);
	ScopedTypeMember(ItemMembers, Stack);
	ScopedTypeMember(ItemMembers, Type);
	ScopedTypeMember(ItemMembers, Charges);
	ScopedTypeMember(ItemMembers, LDoNTheme);
	ScopedTypeMember(ItemMembers, DMGBonusType);
	ScopedTypeMember(ItemMembers, BuyPrice);
	ScopedTypeMember(ItemMembers, Haste);
	ScopedTypeMember(ItemMembers, Endurance);
	ScopedTypeMember(ItemMembers, Attack);
	ScopedTypeMember(ItemMembers, HPRegen);
	ScopedTypeMember(ItemMembers, ManaRegen);
	ScopedTypeMember(ItemMembers, DamShield);
	ScopedTypeMember(ItemMembers, WeightReduction);
	ScopedTypeMember(ItemMembers, SizeCapacity);
	ScopedTypeMember(ItemMembers, Combinable);
	ScopedTypeMember(ItemMembers, Skill);
	ScopedTypeMember(ItemMembers, Avoidance);
	ScopedTypeMember(ItemMembers, SpellShield);
	ScopedTypeMember(ItemMembers, StrikeThrough);
	ScopedTypeMember(ItemMembers, StunResist);
	ScopedTypeMember(ItemMembers, Shielding);
	ScopedTypeMember(ItemMembers, FocusID);
	ScopedTypeMember(ItemMembers, ProcRate);
	ScopedTypeMember(ItemMembers, Quality);
	ScopedTypeMember(ItemMembers, LDoNCost);
	ScopedTypeMember(ItemMembers, AugRestrictions);
	ScopedTypeMember(ItemMembers, AugType);
	ScopedTypeMember(ItemMembers, AugSlot1);
	ScopedTypeMember(ItemMembers, AugSlot2);
	ScopedTypeMember(ItemMembers, AugSlot3);
	ScopedTypeMember(ItemMembers, AugSlot4);
	ScopedTypeMember(ItemMembers, AugSlot5);
	ScopedTypeMember(ItemMembers, AugSlot6);
	ScopedTypeMember(ItemMembers, Damage);
	ScopedTypeMember(ItemMembers, Range);
	ScopedTypeMember(ItemMembers, DMGBonus);
	ScopedTypeMember(ItemMembers, RecommendedLevel);
	ScopedTypeMember(ItemMembers, RecommendedSkill);
	ScopedTypeMember(ItemMembers, Delay);
	ScopedTypeMember(ItemMembers, Light);
	ScopedTypeMember(ItemMembers, Level);
	ScopedTypeMember(ItemMembers, BaneDMG);
	ScopedTypeMember(ItemMembers, SkillModValue);
	ScopedTypeMember(ItemMembers, InstrumentType);
	ScopedTypeMember(ItemMembers, InstrumentMod);
	ScopedTypeMember(ItemMembers, RequiredLevel);
	ScopedTypeMember(ItemMembers, BaneDMGType);
	ScopedTypeMember(ItemMembers, AC);
	ScopedTypeMember(ItemMembers, HP);
	ScopedTypeMember(ItemMembers, Mana);
	ScopedTypeMember(ItemMembers, STR);
	ScopedTypeMember(ItemMembers, STA);
	ScopedTypeMember(ItemMembers, AGI);
	ScopedTypeMember(ItemMembers, DEX);
	ScopedTypeMember(ItemMembers, CHA);
	ScopedTypeMember(ItemMembers, INT);
	ScopedTypeMember(ItemMembers, WIS);
	ScopedTypeMember(ItemMembers, svCold);
	ScopedTypeMember(ItemMembers, svFire);
	ScopedTypeMember(ItemMembers, svMagic);
	ScopedTypeMember(ItemMembers, svDisease);
	ScopedTypeMember(ItemMembers, svPoison);
	ScopedTypeMember(ItemMembers, Summoned);
	ScopedTypeMember(ItemMembers, Artifact);
	ScopedTypeMember(ItemMembers, PendingLore);
	ScopedTypeMember(ItemMembers, LoreText);
	ScopedTypeMember(ItemMembers, Items);
	ScopedTypeMember(ItemMembers, Item);
	ScopedTypeMember(ItemMembers, Container);
	ScopedTypeMember(ItemMembers, Stackable);
	ScopedTypeMember(ItemMembers, InvSlot);
	ScopedTypeMember(ItemMembers, SellPrice);
	ScopedTypeMember(ItemMembers, WornSlot);
	ScopedTypeMember(ItemMembers, WornSlots);
	ScopedTypeMember(ItemMembers, CastTime);
	ScopedTypeMember(ItemMembers, Spell);
	ScopedTypeMember(ItemMembers, EffectType);
	ScopedTypeMember(ItemMembers, Tribute);
	ScopedTypeMember(ItemMembers, Attuneable);
	ScopedTypeMember(ItemMembers, Timer);
	ScopedTypeMember(ItemMembers, ItemDelay);
	ScopedTypeMember(ItemMembers, TimerReady);
	ScopedTypeMember(ItemMembers, StackSize);
	ScopedTypeMember(ItemMembers, Stacks);
	ScopedTypeMember(ItemMembers, StackCount);
	ScopedTypeMember(ItemMembers, FreeStack);
	ScopedTypeMember(ItemMembers, MerchQuantity);
	ScopedTypeMember(ItemMembers, Classes);
	ScopedTypeMember(ItemMembers, Class);
	ScopedTypeMember(ItemMembers, Races);
	ScopedTypeMember(ItemMembers, Race);
	ScopedTypeMember(ItemMembers, Deities);
	ScopedTypeMember(ItemMembers, Deity);
	ScopedTypeMember(ItemMembers, Evolving);
	ScopedTypeMember(ItemMembers, svCorruption);
	ScopedTypeMember(ItemMembers, Power);
	ScopedTypeMember(ItemMembers, MaxPower);
	ScopedTypeMember(ItemMembers, Purity);
	ScopedTypeMember(ItemMembers, Accuracy);
	ScopedTypeMember(ItemMembers, CombatEffects);
	ScopedTypeMember(ItemMembers, DoTShielding);
	ScopedTypeMember(ItemMembers, HeroicSTR);
	ScopedTypeMember(ItemMembers, HeroicINT);
	ScopedTypeMember(ItemMembers, HeroicWIS);
	ScopedTypeMember(ItemMembers, HeroicAGI);
	ScopedTypeMember(ItemMembers, HeroicDEX);
	ScopedTypeMember(ItemMembers, HeroicSTA);
	ScopedTypeMember(ItemMembers, HeroicCHA);
	ScopedTypeMember(ItemMembers, HeroicSvMagic);
	ScopedTypeMember(ItemMembers, HeroicSvFire);
	ScopedTypeMember(ItemMembers, HeroicSvCold);
	ScopedTypeMember(ItemMembers, HeroicSvDisease);
	ScopedTypeMember(ItemMembers, HeroicSvPoison);
	ScopedTypeMember(ItemMembers, HeroicSvCorruption);
	ScopedTypeMember(ItemMembers, EnduranceRegen);
	ScopedTypeMember(ItemMembers, HealAmount);
	ScopedTypeMember(ItemMembers, Clairvoyance);
	ScopedTypeMember(ItemMembers, DamageShieldMitigation);
	ScopedTypeMember(ItemMembers, SpellDamage);
	ScopedTypeMember(ItemMembers, Augs);
	ScopedTypeMember(ItemMembers, Tradeskills);
	ScopedTypeMember(ItemMembers, ItemSlot);
	ScopedTypeMember(ItemMembers, ItemSlot2);
	ScopedTypeMember(ItemMembers, Address);
	ScopedTypeMember(ItemMembers, PctPower);
	ScopedTypeMember(ItemMembers, Prestige);
	ScopedTypeMember(ItemMembers, FirstFreeSlot);
	ScopedTypeMember(ItemMembers, SlotsUsedByItem);
	ScopedTypeMember(ItemMembers, Heirloom);
	ScopedTypeMember(ItemMembers, Collectible);
	ScopedTypeMember(ItemMembers, NoDestroy);
	ScopedTypeMember(ItemMembers, Quest);
	ScopedTypeMember(ItemMembers, Expendable);
	ScopedTypeMember(ItemMembers, ContAddress);
	ScopedTypeMember(ItemMembers, ItemLink);
	ScopedTypeMember(ItemMembers, Icon);
	ScopedTypeMember(ItemMembers, SkillModMax);
	ScopedTypeMember(ItemMembers, OrnamentationIcon);
	ScopedTypeMember(ItemMembers, ContentSize);
	ScopedTypeMember(ItemMembers, Open);
	ScopedTypeMember(ItemMembers, NoTrade);
	ScopedTypeMember(ItemMembers, AugSlot);
	ScopedTypeMember(ItemMembers, Clicky);
	ScopedTypeMember(ItemMembers, Proc);
	ScopedTypeMember(ItemMembers, Worn);
	ScopedTypeMember(ItemMembers, Focus);
	ScopedTypeMember(ItemMembers, Scroll);
	ScopedTypeMember(ItemMembers, Focus2);
	ScopedTypeMember(ItemMembers, Mount);
	ScopedTypeMember(ItemMembers, Illusion);
	ScopedTypeMember(ItemMembers, Familiar);
	ScopedTypeMember(ItemMembers, CanUse);
	ScopedTypeMember(ItemMembers, LoreEquipped);
	ScopedTypeMember(ItemMembers, Luck);
	ScopedTypeMember(ItemMembers, MinLuck);
	ScopedTypeMember(ItemMembers, MaxLuck);
}

bool MQ2ItemType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	CONTENTS* pItem = static_cast<CONTENTS*>(VarPtr.Ptr);
	if (!pItem)
		return false;

	PITEMINFO pItemInfo = GetItemFromContents(pItem);
	if (!pItemInfo)
		return false;

	MQTypeMember* pMember = MQ2ItemType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ItemMembers>(pMember->ID))
	{
	case ItemMembers::ID:
		Dest.DWord = GetItemFromContents(pItem)->ItemNumber;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Name:
		strcpy_s(DataTypeTemp, GetItemFromContents(pItem)->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ItemMembers::Lore:
		Dest.DWord = ((ItemBase*)pItem)->IsLore(false);
		Dest.Type = pBoolType;
		return true;
	case ItemMembers::LoreEquipped:
		Dest.DWord = ((ItemBase*)pItem)->IsLoreEquipped(false);
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::NoDrop:
	case ItemMembers::NoTrade:
		Dest.DWord = !((EQ_Item*)pItem)->CanDrop(0, 1);
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::NoRent:
		Dest.DWord = !GetItemFromContents(pItem)->NoRent;
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::Magic:
		Dest.DWord = ((GetItemFromContents(pItem)->Type == ITEMTYPE_NORMAL) && (GetItemFromContents(pItem)->Magic));
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::Value:
		Dest.DWord = GetItemFromContents(pItem)->Cost;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Size:
		Dest.DWord = GetItemFromContents(pItem)->Size;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::SizeCapacity:
		Dest.DWord = GetItemFromContents(pItem)->SizeCapacity;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Weight:
		Dest.DWord = GetItemFromContents(pItem)->Weight;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Stack:
		if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) || (((EQ_Item*)pItem)->IsStackable() != 1))
			Dest.DWord = 1;
		else
			Dest.DWord = pItem->StackCount;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Type:
		DataTypeTemp[0] = '\0';
		if (GetItemFromContents(pItem)->Type == ITEMTYPE_NORMAL)
		{
			if ((GetItemFromContents(pItem)->ItemType < MAX_ITEMTYPES) && (szItemTypes[GetItemFromContents(pItem)->ItemType] != nullptr))
			{
				strcpy_s(DataTypeTemp, szItemTypes[GetItemFromContents(pItem)->ItemType]);
			}
			else
			{
				sprintf_s(DataTypeTemp, "*UnknownType%d", GetItemFromContents(pItem)->ItemType);
			}
		}
		else if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK)
		{
			if ((GetItemFromContents(pItem)->Combine < MAX_COMBINES) && (szCombineTypes[GetItemFromContents(pItem)->Combine] != nullptr))
			{
				strcpy_s(DataTypeTemp, szCombineTypes[GetItemFromContents(pItem)->Combine]);
			}
			else
			{
				sprintf_s(DataTypeTemp, "*UnknownCombine%d", GetItemFromContents(pItem)->Combine);
			}
		}
		else if (GetItemFromContents(pItem)->Type == ITEMTYPE_BOOK)
		{
			strcpy_s(DataTypeTemp, "Book");
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ItemMembers::Charges:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->Charges;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::LDoNTheme:
		strcpy_s(DataTypeTemp, GetLDoNTheme(GetItemFromContents(pItem)->LDTheme));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

		// we go to keep this for backward compatibility
		// but really it should be called case ItemMembers::ElementalFlag:
	case ItemMembers::DMGBonusType:
		strcpy_s(DataTypeTemp, szDmgBonusType[GetItemFromContents(pItem)->ElementalFlag]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ItemMembers::Container:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK)
		{
			Dest.DWord = GetItemFromContents(pItem)->Slots;
		}
		return true;

	case ItemMembers::Open:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK)
		{
			Dest.DWord = pItem->Open;
		}
		return true;

	case ItemMembers::Items:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK)
		{
			if (pItem->Contents.ContainedItems.pItems) {
				for (unsigned long N = 0; N < GetItemFromContents(pItem)->Slots; N++) {
					if (pItem->GetContent(N))
						Dest.DWord++;
				}
			}
			return true;
		}
		return false;

	case ItemMembers::Clicky:
		Dest.Ptr = &GetItemFromContents(pItem)->Clicky;
		Dest.Type = pItemSpellType;
		return true;

	case ItemMembers::Proc:
		Dest.Ptr = &GetItemFromContents(pItem)->Proc;
		Dest.Type = pItemSpellType;
		return true;

	case ItemMembers::Worn:
		Dest.Ptr = &GetItemFromContents(pItem)->Worn;
		Dest.Type = pItemSpellType;
		return true;

	case ItemMembers::Focus:
		Dest.Ptr = &GetItemFromContents(pItem)->Focus;
		Dest.Type = pItemSpellType;
		return true;

	case ItemMembers::Scroll:
		Dest.Ptr = &GetItemFromContents(pItem)->Scroll;
		Dest.Type = pItemSpellType;
		return true;

	case ItemMembers::Focus2:
		Dest.Ptr = &GetItemFromContents(pItem)->Focus2;
		Dest.Type = pItemSpellType;
		return true;

	case ItemMembers::Mount:
		Dest.Ptr = &GetItemFromContents(pItem)->Mount;
		Dest.Type = pItemSpellType;
		return true;

	case ItemMembers::Illusion:
		Dest.Ptr = &GetItemFromContents(pItem)->Illusion;
		Dest.Type = pItemSpellType;
		return true;

	case ItemMembers::Familiar:
		Dest.Ptr = &GetItemFromContents(pItem)->Familiar;
		Dest.Type = pItemSpellType;
		return true;

	case ItemMembers::Item: {
		Dest.Type = pItemType;
		CONTENTS* pCont = (CONTENTS*)pItem;

		if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK && IsNumber(Index))
		{
			// FIXME:  Add some safety checks here for bad conversion
			int num = GetIntFromString(Index, 1) - 1;
			if (num < GetItemFromContents(pItem)->Slots)
			{
				if (pItem->Contents.ContainedItems.pItems)
				{
					if (Dest.Ptr = pItem->GetContent(num))
					{
						return true;
					}
				}
			}
		}
		else if (GetItemFromContents(pItem)->Type == ITEMTYPE_NORMAL && IsNumber(Index))
		{
			// FIXME:  Add some safety checks here for bad conversion
			int num = GetIntFromString(Index, 1) - 1;
			Dest.Ptr = nullptr;

			if (pItem->Contents.ContainedItems.pItems)
			{
				if (GetItemFromContents(pItem)->AugData.Sockets[num].Type)
					Dest.Ptr = pItem->Contents.ContainedItems.pItems->Item[num];
			}

			if (Dest.Ptr)
				return true;
		}
		return false;
	}
	case ItemMembers::Stackable:
		Dest.DWord = ((EQ_Item*)pItem)->IsStackable();
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::InvSlot:
		Dest.Int = FindInvSlotForContents(pItem);
		if (Dest.Int >= 0)
		{
			Dest.Type = pInvSlotType;
			return true;
		}
		return false;

	case ItemMembers::ItemSlot:
		Dest.Int = pItem->GetGlobalIndex().GetIndex().GetSlot(0);
		Dest.Type = pIntType;
		return true;

	case ItemMembers::ItemSlot2:
		Dest.Int = pItem->GetGlobalIndex().GetIndex().GetSlot(1);
		Dest.Type = pIntType;
		return true;

	case ItemMembers::BuyPrice:
		Dest.Int64 = 0;
		Dest.Type = pInt64Type;
		if (pActiveMerchant && pItem->MerchantSlot)
		{
			Dest.Int64 = pItem->Price;
			return true;
		}
		return false;

	case ItemMembers::SellPrice:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pActiveMerchant)
		{
			Dest.DWord = static_cast<int>(
				static_cast<float>(GetItemFromContents(pItem)->Cost)* (1.0f / pMerchantWnd->MerchantGreed));
			return true;
		}
		return false;

	case ItemMembers::WornSlot:
		Dest.DWord = 0;
		Dest.Type = pInvSlotType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int Count = GetIntFromString(Index, 0);
				if (!Count)
					return false;

				int cmp = GetItemFromContents(pItem)->EquipSlots;
				for (int num = 0; num < 32; num++)
				{
					if (cmp & (1 << num))
					{
						Count--;
						if (Count == 0)
						{
							Dest.DWord = num;
							Dest.Type = pInvSlotType;
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				uint32_t nInvSlot = ItemSlotMap[Index];
				if ((nInvSlot || !_stricmp(Index, "charm")) && nInvSlot < 32)
				{
					Dest.DWord = (GetItemFromContents(pItem)->EquipSlots & (1 << nInvSlot));
					Dest.Type = pBoolType;
					return true;
				}
			}
		}
		return false;

	case ItemMembers::WornSlots: {
		Dest.DWord = 0;

		// count bits
		int cmp = GetItemFromContents(pItem)->EquipSlots;
		for (int num = 0; num < 32; num++)
		{
			if (cmp & (1 << num))
				Dest.DWord++;
		}
		Dest.Type = pIntType;
		return true;
	}

	case ItemMembers::CastTime:
		Dest.UInt64 = GetItemFromContents(pItem)->Clicky.CastTime;
		Dest.Type = pTimeStampType;
		return true;

	case ItemMembers::Spell:
		Dest.Type = pSpellType;
		if (Dest.Ptr = GetSpellByID(GetItemFromContents(pItem)->Clicky.SpellID))
			return true;
		if (Dest.Ptr = GetSpellByID(GetItemFromContents(pItem)->Scroll.SpellID))
			return true;
		if (Dest.Ptr = GetSpellByID(GetItemFromContents(pItem)->Proc.SpellID))
			return true;
		if (Dest.Ptr = GetSpellByID(GetItemFromContents(pItem)->Focus.SpellID))
			return true;
		if (Dest.Ptr = GetSpellByID(GetItemFromContents(pItem)->Worn.SpellID))
			return true;
		return false;

	case ItemMembers::EffectType:
		Dest.Type = pStringType;
		// 0 Proc
		// 1 Clickable from inventory (any class)
		// 2 Worn effect (haste, cleave)
		// 3 Unknown
		// 4 Clickable must be worn
		// 5 Clickable from inventory (class restricted)
		// 6 Focus effect
		// 7 Memmable spell scroll

		// This used to return an int type with a case statment, items could have
		// only one effect. For backwards compatibility we return based on a hierarchy.
		// A zero in any field indicates no effect (others will also be zero)
		if (!GetItemFromContents(pItem)->Clicky.SpellID)
		{
			return false;
		}
		else if (GetItemFromContents(pItem)->Scroll.SpellID != -1)
		{
			strcpy_s(DataTypeTemp, "Spell Scroll");
		}
		else if (GetItemFromContents(pItem)->Clicky.SpellID != -1)
		{
			// code to detect must-be-worn etc here
			switch (GetItemFromContents(pItem)->Clicky.EffectType)
			{
			case ItemEffectClickyWorn:
				strcpy_s(DataTypeTemp, "Click Worn");
				break;
			case ItemEffectClicky:
			case ItemEffectClickyRestricted:
				strcpy_s(DataTypeTemp, "Click Inventory");
				break;
			default:
				strcpy_s(DataTypeTemp, "Click Unknown");
				break;
			}
		}
		else if (GetItemFromContents(pItem)->Focus.SpellID != -1 || GetItemFromContents(pItem)->Worn.SpellID != -1)
		{
			strcpy_s(DataTypeTemp, "Worn");
		}
		else if (GetItemFromContents(pItem)->Proc.SpellID != -1)
		{
			strcpy_s(DataTypeTemp, "Combat");
		}
		else
		{
			return false;
		}
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case ItemMembers::InstrumentMod:
		Dest.Float = ((float)GetItemFromContents(pItem)->InstrumentMod) / 10.0f;
		Dest.Type = pFloatType;
		return true;

	case ItemMembers::Tribute:
		Dest.DWord = GetItemFromContents(pItem)->Favor;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Attuneable:
		Dest.DWord = GetItemFromContents(pItem)->Attuneable;
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::Timer:
		Dest.DWord = 0;
		Dest.Type = pTicksType;
		if (GetItemFromContents(pItem)->Clicky.TimerID != -1)
		{
			Dest.DWord = (GetItemTimer(pItem) + 5) / 6;
			return true;
		}
		if (GetItemFromContents(pItem)->Clicky.SpellID != -1)
		{
			Dest.DWord = 0; // insta-clicky
			return true;
		}
		return false;

	case ItemMembers::Damage:
		Dest.DWord = GetItemFromContents(pItem)->Damage;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::ItemDelay:
		Dest.DWord = GetItemFromContents(pItem)->Delay;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::TimerReady:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (GetItemFromContents(pItem)->Clicky.TimerID != -1)
		{
			Dest.DWord = GetItemTimer(pItem);
			return true;
		}
		if (GetItemFromContents(pItem)->Clicky.SpellID != -1)
		{
			Dest.DWord = 0; // insta-click or instant recast
			return true;
		}
		return false;

	case ItemMembers::StackSize:
		// This returns the MAX size of a stack for the item
		// If this was properly named it should be called MaxStack.
		Dest.DWord = 1; //we know its at least 1
		Dest.Type = pIntType;

		if (pItem)
		{
			if ((pItem->GetItemDefinition()->Type == ITEMTYPE_NORMAL) && (((EQ_Item*)pItem)->IsStackable()))
			{
				Dest.DWord = pItem->GetItemDefinition()->StackSize;
			}
		}
		return true;

	case ItemMembers::Stacks:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (PcProfile* pProfile = GetPcProfile())
		{
			if (!((EQ_Item*)pItem)->IsStackable())
				return true;

			for (int slot = BAG_SLOT_START; slot < NUM_INV_SLOTS; slot++)
			{
				if (pProfile->pInventoryArray && pProfile->pInventoryArray->InventoryArray[slot])
				{
					if (CONTENTS* pTempItem = pProfile->pInventoryArray->InventoryArray[slot])
					{
						if (GetItemFromContents(pTempItem)->Type == ITEMTYPE_PACK && pTempItem->Contents.ContainedItems.pItems)
						{
							for (int pslot = 0; pslot < (GetItemFromContents(pTempItem)->Slots); pslot++)
							{
								if (pTempItem->Contents.ContainedItems.pItems->Item[pslot])
								{
									if (CONTENTS* pSlotItem = pTempItem->Contents.ContainedItems.pItems->Item[pslot])
									{
										if (GetItemFromContents(pSlotItem)->ItemNumber == GetItemFromContents(pItem)->ItemNumber)
										{
											Dest.DWord++;
										}
									}
								}
							}
						}
						else
						{
							if (GetItemFromContents(pTempItem)->ItemNumber == GetItemFromContents(pItem)->ItemNumber)
							{
								Dest.DWord++;
							}
						}
					}
				}
			}
		}
		return true;

	case ItemMembers::StackCount:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (PcProfile* pProfile = GetPcProfile())
		{
			if (!((EQ_Item*)pItem)->IsStackable())
				return true;

			for (int slot = BAG_SLOT_START; slot < NUM_INV_SLOTS; slot++)
			{
				if (pProfile->pInventoryArray && pProfile->pInventoryArray->InventoryArray[slot])
				{
					if (CONTENTS* pTempItem = pProfile->pInventoryArray->InventoryArray[slot])
					{
						if (GetItemFromContents(pTempItem)->Type == ITEMTYPE_PACK && pTempItem->Contents.ContainedItems.pItems)
						{
							for (int pslot = 0; pslot < (GetItemFromContents(pTempItem)->Slots); pslot++)
							{
								if (pTempItem->Contents.ContainedItems.pItems->Item[pslot])
								{
									if (CONTENTS* pSlotItem = pTempItem->Contents.ContainedItems.pItems->Item[pslot])
									{
										if (GetItemFromContents(pSlotItem)->ItemNumber == GetItemFromContents(pItem)->ItemNumber)
										{
											Dest.DWord += pSlotItem->StackCount;
										}
									}
								}
							}
						}
						else
						{
							if (GetItemFromContents(pTempItem)->ItemNumber == GetItemFromContents(pItem)->ItemNumber)
							{
								Dest.DWord += pTempItem->StackCount;
							}
						}
					}
				}
			}
		}
		return true;

	case ItemMembers::FreeStack:
		Dest.DWord = GetFreeStack(pItem);
		Dest.Type = pIntType;
		return true;

	case ItemMembers::MerchQuantity:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pActiveMerchant && pItem->MerchantSlot)
		{
			Dest.DWord = pItem->MerchantQuantity;
			return true;
		}
		return false;

	case ItemMembers::Classes: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		// count bits
		int cmp = GetItemFromContents(pItem)->Classes;
		for (int num = 0; num < TotalPlayerClasses; num++)
		{
			if (cmp & (1 << num))
				Dest.DWord++;
		}
		return true;
	}

	case ItemMembers::Class:
		Dest.DWord = 0;
		Dest.Type = pClassType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int Count = GetIntFromString(Index, 0);
				if (!Count)
					return false;

				int cmp = GetItemFromContents(pItem)->Classes;
				for (int num = 0; num < TotalPlayerClasses; num++)
				{
					if (cmp & (1 << num))
					{
						Count--;
						if (Count == 0)
						{
							Dest.DWord = num + 1;
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				int cmp = GetItemFromContents(pItem)->Classes;
				for (int num = 0; num < TotalPlayerClasses; num++)
				{
					if (cmp & (1 << num))
					{
						if (!_stricmp(Index, GetClassDesc(num + 1))
							|| !_stricmp(Index, pEverQuest->GetClassThreeLetterCode(num + 1)))
						{
							Dest.DWord = num + 1;
							return true;
						}
					}
				}
				return false;
			}
		}
		return false;

	case ItemMembers::Races: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		// count bits
		int cmp = GetItemFromContents(pItem)->Races;
		for (int num = 0; num < NUM_RACES; num++)
		{
			if (cmp & (1 << num))
				Dest.DWord++;
		}
		return true;
	}

	case ItemMembers::Race:
		Dest.DWord = 0;
		Dest.Type = pRaceType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int Count = GetIntFromString(Index, 0);
				if (!Count)
					return false;

				int cmp = GetItemFromContents(pItem)->Races;
				for (int num = 0; num < NUM_RACES; num++)
				{
					if (cmp & (1 << num))
					{
						Count--;
						if (Count == 0)
						{
							Dest.DWord = num + 1;
							switch (num)
							{
							case 12:
								Dest.DWord = 128;   // IKS
								break;
							case 13:
								Dest.DWord = 130;   // VAH
								break;
							case 14:
								Dest.DWord = 330;   // FRG
								break;
							case 15:
								Dest.DWord = 522;   // DRK
								break;
							}
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				int cmp = GetItemFromContents(pItem)->Races;
				for (int num = 0; num < NUM_RACES; num++)
				{
					if (cmp & (1 << num))
					{
						int tmp = num + 1;
						switch (num)
						{
						case 12:
							tmp = 128;   // IKS
							break;
						case 13:
							tmp = 130;   // VAH
							break;
						case 14:
							tmp = 330;   // FRG
							break;
						case 15:
							tmp = 522;   // DRK
							break;
						}

						if (!_stricmp(Index, pEverQuest->GetRaceDesc(tmp)))
						{
							Dest.DWord = tmp;
							return true;
						}
					}
				}
				return false;
			}
		}
		return false;

	case ItemMembers::Deities: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		// count bits
		int cmp = GetItemFromContents(pItem)->Diety;
		for (int num = 0; num < NUM_DEITIES; num++)
		{
			if (cmp & (1 << num))
				Dest.DWord++;
		}
		return true;
	}

	case ItemMembers::Deity:
		Dest.DWord = 0;
		Dest.Type = pDeityType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int Count = GetIntFromString(Index, 0);
				if (!Count)
					return false;
				int cmp = GetItemFromContents(pItem)->Diety;
				for (int num = 0; num < NUM_DEITIES; num++)
				{
					if (cmp & (1 << num))
					{
						Count--;
						if (Count == 0)
						{
							Dest.DWord = num + 200;
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				int cmp = GetItemFromContents(pItem)->Diety;
				for (int num = 0; num < NUM_DEITIES; num++)
				{
					if (cmp & (1 << num))
					{
						if (!_stricmp(Index, pEverQuest->GetDeityDesc(num + 200)))
						{
							Dest.DWord = num + 200;
							return true;
						}
					}
				}
				return false;
			}
		}
		return false;

	case ItemMembers::RequiredLevel:
		Dest.DWord = GetItemFromContents(pItem)->RequiredLevel;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::SkillModValue:
		Dest.DWord = GetItemFromContents(pItem)->SkillModValue;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::SkillModMax:
		Dest.DWord = GetItemFromContents(pItem)->SkillModMax;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Evolving:
		Dest.Ptr = pItem;
		Dest.Type = pEvolvingItemType;
		return true;

	case ItemMembers::AC:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AC;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HP:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HP;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::STR:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->STR;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::STA:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->STA;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::AGI:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AGI;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::DEX:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->DEX;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::CHA:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->CHA;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::INT:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->INT;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::WIS:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->WIS;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Mana:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Mana;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::ManaRegen:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->ManaRegen;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HPRegen:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HPRegen;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Endurance:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Endurance;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Attack:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Attack;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::svCold:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->SvCold;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::svFire:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->SvFire;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::svMagic:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->SvMagic;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::svDisease:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->SvDisease;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::svPoison:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->SvPoison;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::svCorruption:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->SvCorruption;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Haste:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Haste;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::DamShield:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case ItemMembers::AugType:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugType;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::AugRestrictions:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugRestrictions;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::AugSlot:
		Dest.DWord = 0;
		Dest.Type = pAugType;
		if (IsNumber(Index))
		{
			if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			{
				Dest.DWord = 0;
			}
			else
			{
				int index = std::clamp(GetIntFromString(Index, 0), 0, 5);
				Dest.DWord = index;
				Dest.HighPart = (LONG)pItem;
			}
			return true;
		}
		return false;

	case ItemMembers::AugSlot1:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[0].Type;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::AugSlot2:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[1].Type;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::AugSlot3:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[2].Type;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::AugSlot4:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[3].Type;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::AugSlot5:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[4].Type;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::AugSlot6:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[5].Type;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Power:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->Power;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::PctPower:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
		{
			Dest.Float = 0;
		}
		else
		{
			if (int maxpower = GetItemFromContents(pItem)->MaxPower)
			{
				Dest.Float = (float)((pItem->Power * 100) / maxpower);
			}
			else
			{
				Dest.Float = 0;
			}
		}
		Dest.Type = pFloatType;
		return true;

	case ItemMembers::MaxPower:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) {
			Dest.DWord = 0;
		}
		else {
			Dest.DWord = GetItemFromContents(pItem)->MaxPower;
		}
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Purity:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Purity;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Range:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Range;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Avoidance:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case ItemMembers::SpellShield:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case ItemMembers::StrikeThrough:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case ItemMembers::StunResist:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Shielding:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Accuracy:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case ItemMembers::CombatEffects:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case ItemMembers::DoTShielding:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HeroicSTR:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicSTR;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HeroicINT:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicINT;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HeroicWIS:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicWIS;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HeroicAGI:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicAGI;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HeroicDEX:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicDEX;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HeroicSTA:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicSTA;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HeroicCHA:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicCHA;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::EnduranceRegen:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->EnduranceRegen;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HealAmount:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HealAmount;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Clairvoyance:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Clairvoyance;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::DamageShieldMitigation:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				// TODO: Fix this
				Dest.DWord = 0;
			}
		}
		Dest.Type = pIntType;
		return true;

	case ItemMembers::SpellDamage:
		Dest.DWord = 0;
		if (ITEMINFO* pII = GetItemFromContents(pItem))
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				Dest.DWord = pII->SpellDamage;
			}
		}
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Augs:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (ITEMINFO* pitem = GetItemFromContents(pItem))
		{
			if (pitem->Type == ITEMTYPE_NORMAL)
			{
				for (int i = 0; i < MAX_AUG_SOCKETS; ++i)
				{
					if (pitem->AugData.Sockets[i].Type > 0 && pitem->AugData.Sockets[i].Type < 20 && pitem->AugData.Sockets[i].bVisible)
						Dest.DWord++;
				}

				Dest.Type = pIntType;
			}
		}
		return true;

	case ItemMembers::Tradeskills:
		Dest.DWord = GetItemFromContents(pItem)->TradeSkills;
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::Address:
		Dest.DWord = (DWORD)GetItemFromContents(pItem);
		Dest.Type = pIntType;
		return true;

	case ItemMembers::ContAddress:
		Dest.DWord = (DWORD)pItem;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Prestige:
		Dest.DWord = GetItemFromContents(pItem)->Prestige;
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::FirstFreeSlot: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		CONTENTS* pTheCont = pItem;
		if (ITEMINFO* pTheItem = GetItemFromContents(pItem))
		{
			if (pTheItem->Type == ITEMTYPE_PACK || (pTheItem->Type == ITEMTYPE_NORMAL && pTheCont->Item1)) //a worldcontainer has its item in Item1
			{
				Dest.DWord = -1;
				if (pTheCont->Contents.ContainedItems.pItems)
				{
					for (int num = 0; num < pTheItem->Slots; num++)
					{
						if (!pTheCont->Contents.ContainedItems.pItems->Item[num])
						{
							Dest.DWord = num;
							break;
						}
					}
				}
				return true;
			}
		}
		return false;
	}

	case ItemMembers::SlotsUsedByItem:
	{
		Dest.DWord = 0;
		Dest.Type = pIntType;
		CONTENTS* pTheCont = pItem;
		if (ITEMINFO* pTheItem = GetItemFromContents(pItem))
		{
			if (pTheItem->Type == ITEMTYPE_PACK || (pTheItem->Type == ITEMTYPE_NORMAL && pTheCont->Item1))
			{
				Dest.DWord = 0;
				bool bExact = false;
				char* pName1 = Index;
				if (*pName1 == '=')
				{
					bExact = true;
					pName1++;
				}

				if (pTheCont->Contents.ContainedItems.pItems)
				{
					for (int nSlot = 0; nSlot < pTheItem->Slots; nSlot++)
					{
						if (pTheCont->Contents.ContainedItems.pItems->Item[nSlot])
						{
							if (ITEMINFO* bagitem = GetItemFromContents(pTheCont->Contents.ContainedItems.pItems->Item[nSlot]))
							{
								if (bExact)
								{
									if (ci_equals(bagitem->Name, pName1))
									{
										Dest.DWord++;
									}
								}
								else
								{
									if (ci_find_substr(bagitem->Name, pName1) != -1)
									{
										Dest.DWord++;
									}
								}
							}
						}
					}
					return true;
				}
			}
		}
		return false;
	}

	case ItemMembers::Heirloom:
		Dest.DWord = GetItemFromContents(pItem)->Heirloom;
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::Collectible:
		Dest.DWord = GetItemFromContents(pItem)->Collectible;
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::NoDestroy:
		Dest.DWord = GetItemFromContents(pItem)->NoDestroy;
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::Quest:
		Dest.DWord = GetItemFromContents(pItem)->QuestItem;
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::Expendable:
		Dest.DWord = GetItemFromContents(pItem)->Expendable;
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::ItemLink:
		Dest.Type = pStringType;
		if (GetItemLink(pItem, DataTypeTemp, false))
		{
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case ItemMembers::Icon:
		Dest.DWord = GetItemFromContents(pItem)->IconNumber;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::OrnamentationIcon:
		Dest.DWord = pItem->OrnamentationIcon;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::ContentSize:
		Dest.DWord = pItem->Contents.ContentSize;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::CanUse:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (CONTENTS* pCont = pItem)
		{
			Dest.DWord = pCharData->CanUseItem(&pCont, false, false);
			return true;
		}
		return false;

	case ItemMembers::Luck:
		Dest.DWord = pItem->Luck;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::MinLuck:
		Dest.DWord = GetItemFromContents(pItem)->MinLuck;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::MaxLuck:
		Dest.DWord = GetItemFromContents(pItem)->MaxLuck;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

bool MQ2ItemType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (!VarPtr.Ptr)
		return false;

	CONTENTS* pContents = static_cast<CONTENTS*>(VarPtr.Ptr);
	strcpy_s(Destination, MAX_STRING, GetItemFromContents(pContents)->Name);
	return true;
}

void MQ2ItemType::InitVariable(MQVarPtr& VarPtr)
{
	CONTENTS* pContents = eqNew<CONTENTS>();
	pContents->IncrementRefCount();

	VarPtr.Ptr = pContents;
	VarPtr.HighPart = 0;
}

void MQ2ItemType::FreeVariable(MQVarPtr& VarPtr)
{
	CONTENTS* pContents = static_cast<CONTENTS*>(VarPtr.Ptr);
	pContents->DecrementRefCount();
}

bool MQ2ItemType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	if (Source.Type != pItemType)
		return false;

	CONTENTS* pNewContents = static_cast<CONTENTS*>(Source.Ptr);
	if (pNewContents)
		pNewContents->IncrementRefCount();

	CONTENTS* pOldContents = static_cast<CONTENTS*>(VarPtr.Ptr);
	if (pOldContents)
		pOldContents->DecrementRefCount();

	VarPtr.Ptr = pNewContents;
	return true;
}

