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
	OverrideName,
	OverrideDescription,
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
	ScopedTypeMember(ItemSpellMembers, OverrideName);
	ScopedTypeMember(ItemSpellMembers, OverrideDescription);
};

bool MQ2ItemSpellType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	ItemSpellData::SpellData* pItemSpell = GetItemSpellData(VarPtr);
	if (!pItemSpell)
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

	case ItemSpellMembers::OverrideName:
	case ItemSpellMembers::OtherName:
		strcpy_s(DataTypeTemp, pItemSpell->OverrideName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ItemSpellMembers::OtherID:
		Dest.DWord = pItemSpell->OverrideDesc;
		Dest.Type = pIntType;
		return true;

	case ItemSpellMembers::OverrideDescription:
		if (pItemSpell->OverrideDesc > 0)
		{
			if (const char* ptr = pDBStr->GetString(pItemSpell->OverrideDesc, eSpellDescription))
			{
				strcpy_s(DataTypeTemp, ptr);
			}
			else
			{
				sprintf_s(DataTypeTemp, "UnknownDescription(%d)", pItemSpell->OverrideDesc);
			}
		}
		else
		{
			DataTypeTemp[0] = 0;
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
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
	ItemSpellData::SpellData* data = GetItemSpellData(VarPtr);
	if (!data)
		return false;

	if (int spellid = data->SpellID)
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
	VarPtr.Set<Data>({});
}

bool MQ2ItemSpellType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pItemSpellType)
		return false;

	VarPtr.Set<Data>(Source.Get<Data>());
	return true;
}

} // namespace mq::datatypes
