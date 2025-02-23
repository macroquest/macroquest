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
	Attunable,
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
	PctPower,
	Prestige,
	FirstFreeSlot,
	SlotsUsedByItem,
	Heirloom,
	Collectible,
	NoDestroy,
	Quest,
	Expendable,
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
	Blessing,
	CanUse,
	LoreEquipped,
	Luck,
	MinLuck,
	MaxLuck,
	IDFile,
	IDFile2,
	RefCount,
};

enum class ItemMethods
{
	Inspect,
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
	ScopedTypeMember(ItemMembers, Attunable);
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
	ScopedTypeMember(ItemMembers, PctPower);
	ScopedTypeMember(ItemMembers, Prestige);
	ScopedTypeMember(ItemMembers, FirstFreeSlot);
	ScopedTypeMember(ItemMembers, SlotsUsedByItem);
	ScopedTypeMember(ItemMembers, Heirloom);
	ScopedTypeMember(ItemMembers, Collectible);
	ScopedTypeMember(ItemMembers, NoDestroy);
	ScopedTypeMember(ItemMembers, Quest);
	ScopedTypeMember(ItemMembers, Expendable);
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
	ScopedTypeMember(ItemMembers, Blessing);
	ScopedTypeMember(ItemMembers, CanUse);
	ScopedTypeMember(ItemMembers, LoreEquipped);
	ScopedTypeMember(ItemMembers, Luck);
	ScopedTypeMember(ItemMembers, MinLuck);
	ScopedTypeMember(ItemMembers, MaxLuck);
	ScopedTypeMember(ItemMembers, IDFile);
	ScopedTypeMember(ItemMembers, IDFile2);
	ScopedTypeMember(ItemMembers, RefCount);

	ScopedTypeMethod(ItemMethods, Inspect);
}

bool MQ2ItemType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	ItemPtr pItem = GetItem(VarPtr);
	if (!pItem)
		return false;

	MQTypeMember* pMember = MQ2ItemType::FindMember(Member);
	if (!pMember)
	{
		MQTypeMember* pMethod = MQ2ItemType::FindMethod(Member);
		if (pMethod)
		{
			switch (static_cast<ItemMethods>(pMethod->ID))
			{
			case ItemMethods::Inspect:
				if (pItemDisplayManager)
					pItemDisplayManager->ShowItem(pItem);
				return true;

			default: break;
			}
		}
		return false;
	}

	switch (static_cast<ItemMembers>(pMember->ID))
	{
	case ItemMembers::RefCount:
		Dest.DWord = pItem.use_count();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::ID:
		Dest.DWord = pItem->GetID();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Name:
		strcpy_s(DataTypeTemp, pItem->GetName());
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ItemMembers::Lore:
		Dest.Set(pItem->IsLore(false));
		Dest.Type = pBoolType;
		return true;
	case ItemMembers::LoreEquipped:
		Dest.Set(pItem->IsLoreEquipped(false));
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::NoDrop:
	case ItemMembers::NoTrade:
		Dest.Set(!pItem->CanDrop(false, true));
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::NoRent:
		Dest.Set(!pItem->GetItemDefinition()->NoRent);
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::Magic:
		Dest.Set(pItem->GetType() == ITEMTYPE_NORMAL && pItem->GetItemDefinition()->IsMagic());
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::Value:
		Dest.DWord = pItem->GetItemDefinition()->Cost;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Size:
		Dest.DWord = pItem->GetItemDefinition()->Size;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::SizeCapacity:
		Dest.DWord = pItem->GetItemDefinition()->SizeCapacity;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Weight:
		Dest.DWord = pItem->GetItemDefinition()->Weight;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Stack:
		Dest.DWord = pItem->GetItemCount();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Type:
		DataTypeTemp[0] = '\0';
		if (pItem->GetType() == ITEMTYPE_NORMAL)
		{
			uint8_t itemClass = pItem->GetItemClass();

			if (itemClass < MAX_ITEMCLASSES && szItemClasses[itemClass] != nullptr)
			{
				strcpy_s(DataTypeTemp, szItemClasses[itemClass]);
			}
			else
			{
				sprintf_s(DataTypeTemp, "*UnknownItemClass%d", itemClass);
			}
		}
		else if (pItem->GetType() == ITEMTYPE_PACK)
		{
			uint8_t combine = pItem->GetItemDefinition()->Combine;

			if (combine < MAX_COMBINES && szCombineTypes[combine] != nullptr)
			{
				strcpy_s(DataTypeTemp, szCombineTypes[combine]);
			}
			else
			{
				sprintf_s(DataTypeTemp, "*UnknownCombine%d", combine);
			}
		}
		else if (pItem->GetType() == ITEMTYPE_BOOK)
		{
			strcpy_s(DataTypeTemp, "Book");
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ItemMembers::Charges:
		if (pItem->GetType() != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->Charges;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::LDoNTheme:
		strcpy_s(DataTypeTemp, GetLDoNTheme(pItem->GetItemDefinition()->LDTheme));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

		// we go to keep this for backward compatibility
		// but really it should be called case ItemMembers::ElementalFlag:
	case ItemMembers::DMGBonusType:
		strcpy_s(DataTypeTemp, szDmgBonusType[pItem->GetItemDefinition()->ElementalFlag]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ItemMembers::Container:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pItem->GetItemDefinition()->Type == ITEMTYPE_PACK)
		{
			Dest.DWord = pItem->GetItemDefinition()->Slots;
		}
		return true;

	case ItemMembers::Open:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pItem->GetItemDefinition()->Type == ITEMTYPE_PACK)
		{
			Dest.DWord = pItem->Open;
		}
		return true;

	case ItemMembers::Items:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pItem->IsContainer())
		{
			Dest.DWord = pItem->GetChildItemContainer()->GetCount();
			return true;
		}
		return false;

	case ItemMembers::Clicky:
		Dest = pItemSpellType->MakeTypeVar(pItem, ItemSpellType_Clicky);
		return true;

	case ItemMembers::Proc:
		Dest = pItemSpellType->MakeTypeVar(pItem, ItemSpellType_Proc);
		return true;

	case ItemMembers::Worn:
		Dest = pItemSpellType->MakeTypeVar(pItem, ItemSpellType_Worn);
		return true;

	case ItemMembers::Focus:
		Dest = pItemSpellType->MakeTypeVar(pItem, ItemSpellType_Focus);
		return true;

	case ItemMembers::Scroll:
		Dest = pItemSpellType->MakeTypeVar(pItem, ItemSpellType_Scroll);
		return true;

	case ItemMembers::Focus2:
		Dest = pItemSpellType->MakeTypeVar(pItem, ItemSpellType_Focus2);
		return true;

	case ItemMembers::Mount:
		Dest = pItemSpellType->MakeTypeVar(pItem, ItemSpellType_Mount);
		return true;

	case ItemMembers::Illusion:
		Dest = pItemSpellType->MakeTypeVar(pItem, ItemSpellType_Illusion);
		return true;

	case ItemMembers::Familiar:
		Dest = pItemSpellType->MakeTypeVar(pItem, ItemSpellType_Familiar);
		return true;

	case ItemMembers::Blessing:
		Dest = pItemSpellType->MakeTypeVar(pItem, ItemSpellType_Blessing);
		return true;

	case ItemMembers::Item: {
		ItemDefinition* itemDef = pItem->GetItemDefinition();

		if (!IsNumber(Index))
			return false;

		Dest.Type = pItemType;

		if (itemDef->Type == ITEMTYPE_PACK || itemDef->Type == ITEMTYPE_NORMAL)
		{
			int num = GetIntFromString(Index, 1) - 1;
			Dest = pItemType->MakeTypeVar(pItem->GetChildItemContainer()->GetItem(num));
		}

		return true;
	}
	case ItemMembers::Stackable:
		Dest.Set(pItem->IsStackable());
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
		Dest.Int = pItem->GetItemLocation().GetIndex().GetSlot(0);
		Dest.Type = pIntType;
		return true;

	case ItemMembers::ItemSlot2:
		Dest.Int = pItem->GetItemLocation().GetIndex().GetSlot(1);
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
				static_cast<float>(pItem->GetItemDefinition()->Cost)* (1.0f / pMerchantWnd->MerchantGreed));
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

				int cmp = pItem->GetItemDefinition()->EquipSlots;
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
					Dest.Set((pItem->GetItemDefinition()->EquipSlots & (1 << nInvSlot)) != 0);
					Dest.Type = pBoolType;
					return true;
				}
			}
		}
		return false;

	case ItemMembers::WornSlots: {
		Dest.DWord = 0;

		// count bits
		int cmp = pItem->GetItemDefinition()->EquipSlots;
		for (int num = 0; num < 32; num++)
		{
			if (cmp & (1 << num))
				Dest.DWord++;
		}
		Dest.Type = pIntType;
		return true;
	}

	case ItemMembers::CastTime:
		Dest.UInt64 = pItem->GetItemDefinition()->Clicky.CastTime;
		Dest.Type = pTimeStampType;
		return true;

	case ItemMembers::Spell:
		Dest.Type = pSpellType;
		if (Dest.Ptr = GetSpellByID(pItem->GetItemDefinition()->Clicky.SpellID))
			return true;
		if (Dest.Ptr = GetSpellByID(pItem->GetItemDefinition()->Scroll.SpellID))
			return true;
		if (Dest.Ptr = GetSpellByID(pItem->GetItemDefinition()->Proc.SpellID))
			return true;
		if (Dest.Ptr = GetSpellByID(pItem->GetItemDefinition()->Focus.SpellID))
			return true;
		if (Dest.Ptr = GetSpellByID(pItem->GetItemDefinition()->Worn.SpellID))
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
		if (!pItem->GetItemDefinition()->Clicky.SpellID)
		{
			return false;
		}

		if (pItem->GetItemDefinition()->Scroll.SpellID != -1)
		{
			strcpy_s(DataTypeTemp, "Spell Scroll");
		}
		else if (pItem->GetItemDefinition()->Clicky.SpellID != -1)
		{
			// code to detect must-be-worn etc here
			switch (pItem->GetItemDefinition()->Clicky.EffectType)
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
		else if (pItem->GetItemDefinition()->Focus.SpellID != -1 || pItem->GetItemDefinition()->Worn.SpellID != -1)
		{
			strcpy_s(DataTypeTemp, "Worn");
		}
		else if (pItem->GetItemDefinition()->Proc.SpellID != -1)
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
		Dest.Float = static_cast<float>(pItem->GetItemDefinition()->InstrumentMod) / 10.0f;
		Dest.Type = pFloatType;
		return true;

	case ItemMembers::Tribute:
		Dest.DWord = pItem->GetItemDefinition()->Favor;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Attunable:
	case ItemMembers::Attuneable:
		Dest.Set(pItem->GetItemDefinition()->Attuneable);
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::Timer:
		Dest.DWord = 0;
		Dest.Type = pTicksType;
		if (pItem->GetItemDefinition()->Clicky.TimerID != -1)
		{
			Dest.DWord = (GetItemTimer(pItem) + 5) / 6;
			return true;
		}
		if (pItem->GetItemDefinition()->Clicky.SpellID != -1)
		{
			Dest.DWord = 0; // insta-clicky
			return true;
		}
		return false;

	case ItemMembers::Damage:
		Dest.DWord = pItem->GetItemDefinition()->Damage;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::ItemDelay:
		Dest.DWord = pItem->GetItemDefinition()->Delay;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::TimerReady:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pItem->GetItemDefinition()->Clicky.TimerID != -1)
		{
			Dest.DWord = GetItemTimer(pItem);
			return true;
		}
		if (pItem->GetItemDefinition()->Clicky.SpellID != -1)
		{
			Dest.DWord = 0; // insta-click or instant recast
			return true;
		}
		return false;

	case ItemMembers::StackSize:
		// This returns the MAX size of a stack for the item
		// If this was properly named it should be called MaxStack.
		Dest.DWord = pItem->GetMaxItemCount();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Stacks: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		PcProfile* pProfile = GetPcProfile();
		if (!pProfile) return false;

		if (!pItem->IsStackable())
			return true;

		int itemToFind = pItem->GetID();

		// If we used ItemContainer::FindItem, we might count augs that are placed
		// within items in the bag slots (not in the bags).
		for (int slot = InvSlot_FirstBagSlot; slot <= GetHighestAvailableBagSlot(); slot++)
		{
			ItemPtr pBagItem = pProfile->InventoryContainer.GetItem(slot);
			if (!pBagItem) continue;

			if (pBagItem->GetID() == itemToFind)
			{
				Dest.DWord++;
			}
			else if (pBagItem->IsContainer())
			{
				for (const ItemPtr& item : pBagItem->GetHeldItems())
				{
					if (item && item->GetID() == itemToFind)
					{
						Dest.DWord++;
					}
				}
			}
		}

		return true;
	}

	case ItemMembers::StackCount: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		PcProfile* pProfile = GetPcProfile();
		if (!pProfile) return false;

		if (!pItem->IsStackable())
			return true;

		int itemToFind = pItem->GetID();

		for (int slot = InvSlot_FirstBagSlot; slot <= GetHighestAvailableBagSlot(); slot++)
		{
			ItemPtr pBagItem = pProfile->InventoryContainer.GetItem(slot);
			if (!pBagItem) continue;

			if (pBagItem->GetID() == itemToFind)
			{
				Dest.DWord += pBagItem->GetItemCount();
			}
			else if (pBagItem->IsContainer())
			{
				for (const ItemPtr& item : pBagItem->GetHeldItems())
				{
					if (item && item->GetID() == itemToFind)
					{
						Dest.DWord += item->GetItemCount();
					}
				}
			}
		}
		return true;
	}

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
		int cmp = pItem->GetItemDefinition()->Classes;
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

				int cmp = pItem->GetItemDefinition()->Classes;
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
				int cmp = pItem->GetItemDefinition()->Classes;
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
		int cmp = pItem->GetItemDefinition()->Races;
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

				int cmp = pItem->GetItemDefinition()->Races;
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
				int cmp = pItem->GetItemDefinition()->Races;
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
		int cmp = pItem->GetItemDefinition()->Deity;
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
				int cmp = pItem->GetItemDefinition()->Deity;
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
				int cmp = pItem->GetItemDefinition()->Deity;
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
		Dest.DWord = pItem->GetItemDefinition()->RequiredLevel;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::RecommendedLevel:
		Dest.DWord = pItem->GetItemDefinition()->RecommendedLevel;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::SkillModValue:
		Dest.DWord = pItem->GetItemDefinition()->SkillModValue;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::SkillModMax:
		Dest.DWord = pItem->GetItemDefinition()->SkillModMax;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Evolving:
		Dest.Item = pItem;
		Dest.Type = pEvolvingItemType;
		return true;

	case ItemMembers::AC:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->AC;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HP:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->HP;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::STR:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->STR;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::STA:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->STA;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::AGI:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->AGI;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::DEX:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->DEX;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::CHA:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->CHA;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::INT:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->INT;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::WIS:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->WIS;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Mana:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->Mana;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::ManaRegen:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->ManaRegen;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HPRegen:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->HPRegen;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Endurance:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->Endurance;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Attack:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->Attack;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::svCold:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->SvCold;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::svFire:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->SvFire;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::svMagic:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->SvMagic;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::svDisease:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->SvDisease;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::svPoison:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->SvPoison;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::svCorruption:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->SvCorruption;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Haste:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->Haste;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::DamShield:
		Dest.DWord = pItem->GetDamShield();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::AugType:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->AugType;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::AugRestrictions:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->AugRestrictions;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::AugSlot:
	{
		Dest.Type = pAugType;
		int index = GetIntFromString(Index, 0) - 1;
		if (index >= 0 && index < MAX_AUG_SOCKETS
			&& pItem->GetItemDefinition()->Type == ITEMTYPE_NORMAL)
		{
			// FIXME: ItemIndex
			Dest.Set(MQSlotInItem(pItem->GetItemLocation(), index));
			return true;
		}
		return false;
	}

	case ItemMembers::AugSlot1:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->AugData.Sockets[0].Type;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::AugSlot2:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->AugData.Sockets[1].Type;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::AugSlot3:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->AugData.Sockets[2].Type;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::AugSlot4:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->AugData.Sockets[3].Type;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::AugSlot5:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->AugData.Sockets[4].Type;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::AugSlot6:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->AugData.Sockets[5].Type;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Power:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->Power;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::PctPower:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
		{
			Dest.Float = 0;
		}
		else
		{
			if (int maxpower = pItem->GetItemDefinition()->MaxPower)
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
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL) {
			Dest.DWord = 0;
		}
		else {
			Dest.DWord = pItem->GetItemDefinition()->MaxPower;
		}
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Purity:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->Purity;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Range:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->Range;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Avoidance:
		Dest.DWord = pItem->GetAvoidance();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::SpellShield:
		Dest.DWord = pItem->GetSpellShield();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::StrikeThrough:
		Dest.DWord = pItem->GetStrikeThrough();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::StunResist:
		Dest.DWord = pItem->GetStunResist();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Shielding:
		Dest.DWord = pItem->GetShielding();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Accuracy:
		Dest.DWord = pItem->GetAccuracy();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::CombatEffects:
		Dest.DWord = pItem->GetCombatEffects();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::DoTShielding:
		Dest.DWord = pItem->GetDoTShielding();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HeroicSTR:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->HeroicSTR;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HeroicINT:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->HeroicINT;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HeroicWIS:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->HeroicWIS;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HeroicAGI:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->HeroicAGI;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HeroicDEX:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->HeroicDEX;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HeroicSTA:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->HeroicSTA;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HeroicCHA:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->HeroicCHA;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HeroicSvMagic:
		Dest.DWord = pItem->GetHeroicSvMagic();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HeroicSvFire:
		Dest.DWord = pItem->GetHeroicSvFire();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HeroicSvCold:
		Dest.DWord = pItem->GetHeroicSvCold();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HeroicSvDisease:
		Dest.DWord = pItem->GetHeroicSvDisease();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HeroicSvPoison:
		Dest.DWord = pItem->GetHeroicSvPoison();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HeroicSvCorruption:
		Dest.DWord = pItem->GetHeroicSvCorruption();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::EnduranceRegen:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->EnduranceRegen;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::HealAmount:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->HealAmount;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Clairvoyance:
		if (pItem->GetItemDefinition()->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->GetItemDefinition()->Clairvoyance;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::DamageShieldMitigation:
		Dest.DWord = pItem->GetDamageShieldMitigation();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::SpellDamage:
		Dest.DWord = 0;
		if (ItemDefinition* pII = pItem->GetItemDefinition())
		{
			if (pII->Type == ITEMTYPE_NORMAL)
			{
				Dest.DWord = pII->SpellDamage;
			}
		}
		Dest.Type = pIntType;
		return true;

	case ItemMembers::Augs: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		ItemDefinition* itemDef = pItem->GetItemDefinition();
		if (itemDef->Type == ITEMTYPE_NORMAL)
		{
			for (const auto& augInfo : itemDef->AugData.Sockets)
			{
				if (augInfo.Type != 0 && augInfo.bVisible)
					Dest.DWord++;
			}
		}

		return true;
	}

	case ItemMembers::Tradeskills:
		Dest.Set(pItem->GetItemDefinition()->TradeSkills);
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::Prestige:
		Dest.Set(pItem->GetItemDefinition()->Prestige != 0);
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::FirstFreeSlot: {
		Dest.DWord = -1;
		Dest.Type = pIntType;

		// FIXME: Check with world container

		for (int i = 0; i < pItem->GetHeldItems().GetSize(); ++i)
		{
			ItemPtr pInnerItem = pItem->GetHeldItem(i);

			if (!pInnerItem)
			{
				Dest.DWord = i;
				break;
			}
		}

		return true;
	}

	case ItemMembers::SlotsUsedByItem:
	{
		Dest.DWord = 0;
		Dest.Type = pIntType;

		for (const ItemPtr& pInnerItem : pItem->GetHeldItems())
		{
			if (pInnerItem && MaybeExactCompare(pInnerItem->GetName(), Index))
				Dest.DWord++;
		}

		return true;
	}

	case ItemMembers::Heirloom:
		Dest.Set(pItem->GetItemDefinition()->Heirloom);
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::Collectible:
		Dest.Set(pItem->GetItemDefinition()->Collectible);
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::NoDestroy:
		Dest.Set(pItem->GetItemDefinition()->NoDestroy);
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::Quest:
		Dest.Set(pItem->GetItemDefinition()->QuestItem != 0);
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::Expendable:
		Dest.Set(pItem->GetItemDefinition()->Expendable != 0);
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::ItemLink:
		Dest.Type = pStringType;
		if (GetItemLink(pItem, DataTypeTemp, DataTypeTemp.size(), Index != nullptr && ci_equals(Index, "CLICKABLE")))
		{
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case ItemMembers::Icon:
		Dest.DWord = pItem->GetItemDefinition()->IconNumber;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::OrnamentationIcon:
		Dest.DWord = pItem->OrnamentationIcon;
		Dest.Type = pIntType;
		return true;

	case ItemMembers::ContentSize:
		Dest.DWord = pItem->GetHeldItems().GetSize();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::CanUse:
		Dest.Set(pLocalPC->CanUseItem(pItem, false, false));
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::Luck:
		Dest.DWord = pItem->GetLuck();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::MinLuck:
		Dest.DWord = pItem->GetMinLuck();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::MaxLuck:
		Dest.DWord = pItem->GetMaxLuck();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::IDFile:
#if IS_CLIENT_DATE(20200413)
		Dest.DWord = pItem->GetItemDefinition()->IDFile;
		Dest.Type = pIntType;
#else
		Dest.Ptr = pItem->GetItemDefinition()->IDFile;
		Dest.Type = pStringType;
#endif
		return true;

	case ItemMembers::IDFile2:
#if IS_CLIENT_DATE(20200413)
		Dest.DWord = pItem->GetItemDefinition()->IDFile2;
		Dest.Type = pIntType;
#else
		Dest.Ptr = pItem->GetItemDefinition()->IDFile2;
		Dest.Type = pStringType;
#endif
		return true;

	default: break;
	}

	return false;
}

bool MQ2ItemType::ToString(MQVarPtr VarPtr, char* Destination)
{
	ItemPtr pItem = GetItem(VarPtr);
	if (!pItem)
		return false;

	strcpy_s(Destination, MAX_STRING, pItem->GetName());
	return true;
}

void MQ2ItemType::InitVariable(MQVarPtr& VarPtr)
{
	VarPtr = MakeVarPtr(ItemClient::Create());
}

void MQ2ItemType::FreeVariable(MQVarPtr& VarPtr)
{
}

bool MQ2ItemType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pItemType)
		return false;

	VarPtr = MakeTypeVar(GetItem(Source));
	return true;
}

//----------------------------------------------------------------------------

bool MQ2ItemType::dataCursor(const char* szIndex, MQTypeVar& Ret)
{
	PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return false;

	Ret = pItemType->MakeTypeVar(pProfile->GetInventorySlot(InvSlot_Cursor));
	return true;
}

bool MQ2ItemType::dataSelectedItem(const char* szIndex, MQTypeVar& Ret)
{
	Ret = pItemType->MakeTypeVar(pInvSlotMgr->pSelectedItem ? pInvSlotMgr->pSelectedItem->GetItem() : nullptr);
	return true;
}

bool MQ2ItemType::dataFindItemBank(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	ItemClient* pItem = nullptr;

	if (IsNumber(szIndex))
	{
		Ret = pItemType->MakeTypeVar(FindBankItemByID(GetIntFromString(szIndex, 0)));
		return true;
	}

	const char* pName = szIndex;
	bool bExact = false;

	if (*pName == '=')
	{
		bExact = true;
		pName++;
	}

	Ret = pItemType->MakeTypeVar(FindBankItemByName(pName, bExact));
	return true;
}

bool MQ2ItemType::dataFindItem(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	if (IsNumber(szIndex))
	{
		Ret = pItemType->MakeTypeVar(FindItemByID(GetIntFromString(szIndex, 0)));
		return true;
	}

	const char* pName = szIndex;
	bool bExact = false;

	if (*pName == '=')
	{
		bExact = true;
		pName++;
	}

	Ret = pItemType->MakeTypeVar(FindItemByName(pName, bExact));
	return true;
}

bool MQ2ItemType::dataFindItemCount(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	if (IsNumber(szIndex))
	{
		Ret.DWord = FindItemCountByID(GetIntFromString(szIndex, 0));
	}
	else
	{
		Ret.DWord = FindItemCountByName(szIndex);
	}

	Ret.Type = pIntType;
	return true;
}

bool MQ2ItemType::dataFindItemBankCount(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	if (IsNumber(szIndex))
	{
		Ret.DWord = FindBankItemCountByID(GetIntFromString(szIndex, 0));
		Ret.Type = pIntType;
		return true;
	}

	const char* pName = szIndex;
	bool bExact = false;

	if (*pName == '=')
	{
		bExact = true;
		pName++;
	}

	Ret.DWord = FindBankItemCountByName(pName, bExact);
	Ret.Type = pIntType;
	return true;
}

//----------------------------------------------------------------------------

MQVarPtr MQ2ItemType::MakeVarPtr(const ItemPtr& pItem)
{
	MQVarPtr VarPtr;
	VarPtr.Item = pItem;

	return VarPtr;
}

MQTypeVar MQ2ItemType::MakeTypeVar(const ItemPtr& pItem)
{
	MQTypeVar Dest;

	Dest.Type = this;
	Dest.Item = pItem;

	return Dest;
}

ItemPtr MQ2ItemType::GetItem(const MQVarPtr& VarPtr) const
{
	if (!VarPtr.IsType(MQVarPtr::VariantIdx::Item))
		return ItemPtr();

	ItemPtr pItem = VarPtr.Item;
	return pItem;
}

} // namespace mq::datatypes
