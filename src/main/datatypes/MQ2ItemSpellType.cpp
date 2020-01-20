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

bool MQ2ItemSpellType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	ITEMSPELLS* pItemSpell = static_cast<ITEMSPELLS*>(VarPtr.Ptr);
	if (!VarPtr.Ptr)
		return false;

	MQTypeMember* pMember = MQ2ItemSpellType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ItemSpellMembers>(pMember->ID))
	{
	case SpellID:
		Dest.DWord = pItemSpell->SpellID;
		Dest.Type = pIntType;
		return true;

	case RequiredLevel:
		Dest.DWord = pItemSpell->RequiredLevel;
		Dest.Type = pIntType;
		return true;

	case EffectType:
		Dest.DWord = pItemSpell->EffectType;
		Dest.Type = pIntType;
		return true;

	case EffectiveCasterLevel:
		Dest.DWord = pItemSpell->EffectiveCasterLevel;
		Dest.Type = pIntType;
		return true;

	case MaxCharges:
		Dest.DWord = pItemSpell->MaxCharges;
		Dest.Type = pIntType;
		return true;

	case CastTime:
		Dest.DWord = pItemSpell->CastTime;
		Dest.Type = pIntType;
		return true;

	case TimerID:
		Dest.DWord = pItemSpell->TimerID;
		Dest.Type = pIntType;
		return true;

	case RecastType:
		Dest.DWord = pItemSpell->RecastType;
		Dest.Type = pIntType;
		return true;

	case ProcRate:
		Dest.DWord = pItemSpell->ProcRate;
		Dest.Type = pIntType;
		return true;

	case OtherName:
		strcpy_s(DataTypeTemp, pItemSpell->OtherName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case OtherID:
		Dest.DWord = pItemSpell->OtherID;
		Dest.Type = pIntType;
		return true;

	case Spell:
		Dest.Ptr = GetSpellByID(pItemSpell->SpellID);
		Dest.Type = pSpellType;
		return true;
	}

	return false;
}

