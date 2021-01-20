/*
 * MacroQuest: The extension platform for EverQuest
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

bool MQ2ItemType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	ItemClient* pItem = static_cast<ItemClient*>(VarPtr.Ptr);
	if (!pItem)
		return false;

	MQTypeMember* pMember = MQ2ItemType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ItemMembers>(pMember->ID))
	{
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
		Dest.Set(!GetItemFromContents(pItem)->NoRent);
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::Magic:
		Dest.Set(((GetItemFromContents(pItem)->Type == ITEMTYPE_NORMAL) && (GetItemFromContents(pItem)->Magic)));
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
		if (pItem->IsContainer())
		{
			Dest.DWord = pItem->GetChildItemContainer()->GetCount();
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
		ItemDefinition* itemDef = pItem->GetItemDefinition();

		if (!IsNumber(Index))
			return false;

		if (itemDef->Type == ITEMTYPE_PACK
			|| itemDef->Type == ITEMTYPE_NORMAL)
		{
			int num = GetIntFromString(Index, 1) - 1;
			if (Dest.Ptr = pItem->GetChildItemContainer()->GetItem(num).get())
				return true;
		}
		return false;
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
					Dest.Set((GetItemFromContents(pItem)->EquipSlots & (1 << nInvSlot)) != 0);
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
		Dest.Set(GetItemFromContents(pItem)->Attuneable);
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
						Dest.DWord += pBagItem->GetItemCount();
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
		if (ItemDefinition* pII = GetItemFromContents(pItem))
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
	{
		Dest.Type = pAugType;
		int index = GetIntFromString(Index, -1);
		if (index >= 0 && index < MAX_AUG_SOCKETS
			&& GetItemFromContents(pItem)->Type == ITEMTYPE_NORMAL)
		{
			// FIXME: ItemIndex
			Dest.Set(MQSlotInItem(pItem->GetItemLocation(), index));
			return true;
		}
		return false;
	}

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
		if (ItemDefinition* pII = GetItemFromContents(pItem))
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
		if (ItemDefinition* pII = GetItemFromContents(pItem))
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
		if (ItemDefinition* pII = GetItemFromContents(pItem))
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
		if (ItemDefinition* pII = GetItemFromContents(pItem))
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
		if (ItemDefinition* pII = GetItemFromContents(pItem))
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
		if (ItemDefinition* pII = GetItemFromContents(pItem))
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
		if (ItemDefinition* pII = GetItemFromContents(pItem))
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
		if (ItemDefinition* pII = GetItemFromContents(pItem))
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
		if (ItemDefinition* pII = GetItemFromContents(pItem))
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
		if (ItemDefinition* pII = GetItemFromContents(pItem))
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
		Dest.Set(GetItemFromContents(pItem)->TradeSkills);
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
		Dest.Set(GetItemFromContents(pItem)->Prestige != 0);
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
		Dest.Set(GetItemFromContents(pItem)->Heirloom);
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::Collectible:
		Dest.Set(GetItemFromContents(pItem)->Collectible);
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::NoDestroy:
		Dest.Set(GetItemFromContents(pItem)->NoDestroy);
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::Quest:
		Dest.Set(GetItemFromContents(pItem)->QuestItem != 0);
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::Expendable:
		Dest.Set(GetItemFromContents(pItem)->Expendable != 0);
		Dest.Type = pBoolType;
		return true;

	case ItemMembers::ItemLink:
		Dest.Type = pStringType;
		if (GetItemLink(pItem, DataTypeTemp, Index != nullptr && ci_equals(Index, "CLICKABLE")))
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
		Dest.DWord = pItem->GetHeldItems().GetSize();
		Dest.Type = pIntType;
		return true;

	case ItemMembers::CanUse:
		Dest.Set(pCharData->CanUseItem(pItem, false, false));
		Dest.Type = pBoolType;
		return true;

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

	ItemClient* pItem = static_cast<ItemClient*>(VarPtr.Ptr);
	strcpy_s(Destination, MAX_STRING, pItem->GetName());
	return true;
}

void MQ2ItemType::InitVariable(MQVarPtr& VarPtr)
{
	ItemClient* pItem = eqNew<ItemClient>();

	// manually increment since we are not using a VePointer
	pItem->IncrementRefCount();
	VarPtr.Ptr = pItem;
}

void MQ2ItemType::FreeVariable(MQVarPtr& VarPtr)
{
	ItemClient* pItem = static_cast<ItemClient*>(VarPtr.Ptr);

	// Manually decrement since we are not using a VePointer. This should
	// delete the item if it is the last reference.
	pItem->DecrementRefCount();
	VarPtr.Ptr = nullptr;
}

bool MQ2ItemType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	if (Source.Type != pItemType)
		return false;

	// Increment new object reference count.
	ItemClient* pNewItem = static_cast<ItemClient*>(Source.Ptr);
	if (pNewItem)
		pNewItem->IncrementRefCount();

	// Decrement old object reference count.
	ItemClient* pOldItem = static_cast<ItemClient*>(VarPtr.Ptr);
	if (pOldItem)
		pOldItem->DecrementRefCount();

	VarPtr.Ptr = pNewItem;
	return true;
}

//----------------------------------------------------------------------------

bool MQ2ItemType::dataCursor(const char* szIndex, MQTypeVar& Ret)
{
	PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return false;

	if (Ret.Ptr = pProfile->GetInventorySlot(InvSlot_Cursor).get())
	{
		Ret.Type = pItemType;
		return true;
	}

	return false;
}

bool MQ2ItemType::dataSelectedItem(const char* szIndex, MQTypeVar& Ret)
{
	if (pInvSlotMgr->pSelectedItem)
	{
		if (ItemPtr pItem = pInvSlotMgr->pSelectedItem->GetItem())
		{
			Ret.Ptr = pItem.get();
			Ret.Type = pItemType;
			return true;
		}
	}

	return false;
}

bool MQ2ItemType::dataFindItemBank(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	ItemClient* pItem = nullptr;

	if (IsNumber(szIndex))
	{
		if ((pItem = FindBankItemByID(GetIntFromString(szIndex, 0))))
		{
			Ret.Ptr = pItem;
			Ret.Type = pItemType;
			return true;
		}

		return false;
	}

	const char* pName = szIndex;
	bool bExact = false;

	if (*pName == '=')
	{
		bExact = true;
		pName++;
	}

	if (pItem = FindBankItemByName(pName, bExact))
	{
		Ret.Ptr = pItem;
		Ret.Type = pItemType;
		return true;
	}
	return false;
}

bool MQ2ItemType::dataFindItem(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	if (IsNumber(szIndex))
	{
		if (ItemClient* pItem = FindItemByID(GetIntFromString(szIndex, 0)))
		{
			Ret.Ptr = pItem;
			Ret.Type = pItemType;
			return true;
		}
		return false;
	}

	const char* pName = szIndex;
	bool bExact = false;

	if (*pName == '=')
	{
		bExact = true;
		pName++;
	}

	if (ItemClient* pItem = FindItemByName(pName, bExact))
	{
		Ret.Ptr = pItem;
		Ret.Type = pItemType;
		return true;
	}

	return false;
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


} // namespace mq::datatypes
