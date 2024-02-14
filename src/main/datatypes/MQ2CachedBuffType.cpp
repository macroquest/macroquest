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

enum class CachedBuffMembers
{
	CasterName = 1, // deprecated
	Caster,
	Count,
	Slot,
	Spell,
	SpellID,
	OriginalDuration,
	Duration,
	Staleness
};

MQ2CachedBuffType::MQ2CachedBuffType() : MQ2Type("cachedbuff")
{
	ScopedTypeMember(CachedBuffMembers, CasterName);
	ScopedTypeMember(CachedBuffMembers, Caster);
	ScopedTypeMember(CachedBuffMembers, Count);
	ScopedTypeMember(CachedBuffMembers, Slot);
	ScopedTypeMember(CachedBuffMembers, Spell);
	ScopedTypeMember(CachedBuffMembers, SpellID);
	ScopedTypeMember(CachedBuffMembers, OriginalDuration);
	ScopedTypeMember(CachedBuffMembers, Duration);
	ScopedTypeMember(CachedBuffMembers, Staleness);
}

bool MQ2CachedBuffType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (static_cast<int>(VarPtr.HighPart) == -1)
		return false;

	auto pSpawn = static_cast<SPAWNINFO*>(VarPtr.Ptr);
	auto buff = GetCachedBuffAtSlot(pSpawn, VarPtr.HighPart);
	if (!buff || buff->spellId <= 0)
		return false;

	MQTypeMember* pMember = MQ2CachedBuffType::FindMember(Member);
	if (!pMember)
	{
		if (SPELL* pSpell = GetSpellByID(buff->spellId))
		{
			MQVarPtr spellVar;
			spellVar.Ptr = pSpell;

			return pSpellType->GetMember(spellVar, Member, Index, Dest);
		}
		return false;
	}

	switch (static_cast<CachedBuffMembers>(pMember->ID))
	{
	case CachedBuffMembers::CasterName:
	case CachedBuffMembers::Caster:
		strcpy_s(DataTypeTemp, buff->casterName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case CachedBuffMembers::Count:
		Dest.Int = buff->count;
		Dest.Type = pIntType;
		return true;

	case CachedBuffMembers::Slot:
		Dest.Int = buff->slot + 1;
		Dest.Type = pIntType;
		return true;

	case CachedBuffMembers::Spell:
		Dest.DWord = 0;
		Dest.Type = pSpellType;

		if (Dest.Ptr = GetSpellByID(buff->spellId))
			return true;

		return false;

	case CachedBuffMembers::SpellID:
		Dest.Int = buff->spellId;
		Dest.Type = pIntType;
		return true;

	case CachedBuffMembers::OriginalDuration:
		Dest.UInt64 = buff->duration;
		Dest.Type = pTimeStampType;
		return true;

	case CachedBuffMembers::Duration:
		Dest.UInt64 = buff->Duration();
		Dest.Type = pTimeStampType;
		return true;

	case CachedBuffMembers::Staleness:
		if (pSpawn == pTarget)
			Dest.Int = 0;
		else
			Dest.Int = buff->Staleness();
		Dest.Type = pTimeStampType;
		return true;

	default:
		return false;
	}
}

bool MQ2CachedBuffType::ToString(MQVarPtr VarPtr, char* Destination)
{
	auto pSpawn = static_cast<SPAWNINFO*>(VarPtr.Ptr);
	auto buff = GetCachedBuffAtSlot(pSpawn, VarPtr.HighPart);
	if (!buff || buff->spellId <= 0)
		return false;

	if (PSPELL pSpell = GetSpellByID(buff->spellId))
	{
		strcpy_s(Destination, MAX_STRING, pSpell->Name);
		return true;
	}
	return false;
}

bool MQ2CachedBuffType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	VarPtr.Ptr = Source.Ptr;
	VarPtr.HighPart = Source.HighPart;
	return true;
}

} // namespace mq::datatypes
