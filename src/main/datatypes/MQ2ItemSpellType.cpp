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

enum class ItemSpellMembers
{
	SpellID = 1,
	RequiredLevel,
	EffectType,
	EffectiveCasterLevel,
	MaxCharges,
	CastTime,
	TimerID,
	RecastType,
	ProcRate,
	OtherName,
	OtherID,
	Spell,
};

MQ2ItemSpellType::MQ2ItemSpellType() : MQ2Type("itemspell")
{
	ScopedTypeMember(ItemSpellMembers, SpellID);
	ScopedTypeMember(ItemSpellMembers, RequiredLevel);
	ScopedTypeMember(ItemSpellMembers, EffectType);
	ScopedTypeMember(ItemSpellMembers, EffectiveCasterLevel);
	ScopedTypeMember(ItemSpellMembers, MaxCharges);
	ScopedTypeMember(ItemSpellMembers, CastTime);
	ScopedTypeMember(ItemSpellMembers, TimerID);
	ScopedTypeMember(ItemSpellMembers, RecastType);
	ScopedTypeMember(ItemSpellMembers, ProcRate);
	ScopedTypeMember(ItemSpellMembers, OtherName);
	ScopedTypeMember(ItemSpellMembers, OtherID);
	ScopedTypeMember(ItemSpellMembers, Spell);
};

bool MQ2ItemSpellType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	ITEMSPELLS* pItemSpell = static_cast<ITEMSPELLS*>(VarPtr.Ptr);
	if (!VarPtr.Ptr)
		return false;

	MQTypeMember* pMember = MQ2ItemSpellType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ItemSpellMembers>(pMember->ID))
	{
	case ItemSpellMembers::SpellID:
		Dest.DWord = pItemSpell->SpellID;
		Dest.Type = pIntType;
		return true;

	case ItemSpellMembers::RequiredLevel:
		Dest.DWord = pItemSpell->RequiredLevel;
		Dest.Type = pIntType;
		return true;

	case ItemSpellMembers::EffectType:
		Dest.DWord = pItemSpell->EffectType;
		Dest.Type = pIntType;
		return true;

	case ItemSpellMembers::EffectiveCasterLevel:
		Dest.DWord = pItemSpell->EffectiveCasterLevel;
		Dest.Type = pIntType;
		return true;

	case ItemSpellMembers::MaxCharges:
		Dest.DWord = pItemSpell->MaxCharges;
		Dest.Type = pIntType;
		return true;

	case ItemSpellMembers::CastTime:
		Dest.DWord = pItemSpell->CastTime;
		Dest.Type = pIntType;
		return true;

	case ItemSpellMembers::TimerID:
		Dest.DWord = pItemSpell->TimerID;
		Dest.Type = pIntType;
		return true;

	case ItemSpellMembers::RecastType:
		Dest.DWord = pItemSpell->RecastType;
		Dest.Type = pIntType;
		return true;

	case ItemSpellMembers::ProcRate:
		Dest.DWord = pItemSpell->ProcRate;
		Dest.Type = pIntType;
		return true;

	case ItemSpellMembers::OtherName:
		strcpy_s(DataTypeTemp, pItemSpell->OtherName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ItemSpellMembers::OtherID:
		Dest.DWord = pItemSpell->OtherID;
		Dest.Type = pIntType;
		return true;

	case ItemSpellMembers::Spell:
		Dest.Ptr = GetSpellByID(pItemSpell->SpellID);
		Dest.Type = pSpellType;
		return true;
	}

	return false;
}

bool MQ2ItemSpellType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (!VarPtr.Ptr)
		return false;

	ITEMSPELLS* pItemSpells = static_cast<ITEMSPELLS*>(VarPtr.Ptr);
	if (int spellid = pItemSpells->SpellID)
	{
		if (SPELL* pSpell = GetSpellByID(spellid))
		{
			strcpy_s(Destination, MAX_STRING, pSpell->Name);
			return true;
		}
	}
	return false;
}

void MQ2ItemSpellType::InitVariable(MQVarPtr& VarPtr)
{
	// FIXME: Do not allocate an ITEMSPELLS
	VarPtr.Ptr = new ITEMSPELLS();
}

void MQ2ItemSpellType::FreeVariable(MQVarPtr& VarPtr)
{
	// FIXME: Do not allocate an ITEMSPELLS
	ITEMSPELLS* pItemSpells = static_cast<ITEMSPELLS*>(VarPtr.Ptr);
	delete pItemSpells;
}

bool MQ2ItemSpellType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	if (Source.Type != pItemSpellType)
		return false;

	memcpy(VarPtr.Ptr, Source.Ptr, sizeof(ITEMSPELLS));
	return true;
}

} // namespace mq::datatypes
