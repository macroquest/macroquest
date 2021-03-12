/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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

enum class BuffMembers
{
	Address = 1,
	ID,
	Level,
	Spell,
	Mod,
	Duration,
	Dar,
	TotalCounters,
	HitCount,
	CountersDisease,
	CountersPoison,
	CountersCurse,
	CountersCorruption,
	Caster,
};

enum class BuffMethods
{
	Remove = 1
};

MQ2BuffType::MQ2BuffType() : MQ2Type("buff")
{
	ScopedTypeMember(BuffMembers, Address);
	ScopedTypeMember(BuffMembers, ID);
	ScopedTypeMember(BuffMembers, Level);
	ScopedTypeMember(BuffMembers, Spell);
	ScopedTypeMember(BuffMembers, Mod);
	ScopedTypeMember(BuffMembers, Duration);
	ScopedTypeMember(BuffMembers, Dar);
	ScopedTypeMember(BuffMembers, TotalCounters);
	ScopedTypeMember(BuffMembers, HitCount);
	ScopedTypeMember(BuffMembers, CountersDisease);
	ScopedTypeMember(BuffMembers, CountersPoison);
	ScopedTypeMember(BuffMembers, CountersCurse);
	ScopedTypeMember(BuffMembers, CountersCorruption);
	ScopedTypeMember(BuffMembers, Caster);

	ScopedTypeMethod(BuffMethods, Remove);
}

bool MQ2BuffType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (VarPtr.Int < 0 || VarPtr.Int >= NUM_LONG_BUFFS + NUM_SHORT_BUFFS)
		return false;

	auto pPCProfile = GetPcProfile();
	if (!pPCProfile)
		return false;

	EQ_Affect* buff = nullptr;
	if (VarPtr.Int < NUM_LONG_BUFFS)
		buff = &pPCProfile->Buff[VarPtr.Int];
	else if (VarPtr.Int < NUM_LONG_BUFFS + NUM_SHORT_BUFFS)
		buff = &pPCProfile->ShortBuff[VarPtr.Int - NUM_LONG_BUFFS];

	// this is how we tell if there is a buff in that slot
	if (buff == nullptr || buff->SpellID <= 0)
		return false;

	//----------------------------------------------------------------------------
	// methods

	if (MQTypeMember* pMethod = MQ2BuffType::FindMethod(Member))
	{
		switch (static_cast<BuffMethods>(pMethod->ID))
		{
		case BuffMethods::Remove:
		{
			RemoveBuff(buff, VarPtr.Int);
			return true;
		}

		default:
			return false;
		}
	}

	//----------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = MQ2BuffType::FindMember(Member);
	if (!pMember)
	{
		if (EQ_Spell* pSpell = GetSpellByID(buff->SpellID))
		{
			MQVarPtr data;
			data.Ptr = pSpell;

			return pSpellType->GetMember(data, Member, Index, Dest);
		}

		return false;
	}

	switch (static_cast<BuffMembers>(pMember->ID))
	{
	case BuffMembers::Address:
		Dest.DWord = (DWORD)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case BuffMembers::ID:
		Dest.Type = pIntType;
		Dest.Int = 0;
		if (VarPtr.Int < NUM_LONG_BUFFS)
			Dest.Int = VarPtr.Int + 1;
		else if (VarPtr.Int < NUM_LONG_BUFFS + NUM_SHORT_BUFFS)
			Dest.Int = VarPtr.Int - NUM_LONG_BUFFS + 1;
		else
			return false;
		return true;

	case BuffMembers::Level:
		Dest.DWord = buff->Level;
		Dest.Type = pIntType;
		return true;

	case BuffMembers::Spell:
		Dest.DWord = 0;
		Dest.Type = pSpellType;

		if (Dest.Ptr = GetSpellByID(buff->SpellID))
			return true;

		return false;

	case BuffMembers::Mod:
		Dest.Float = buff->Modifier;
		Dest.Type = pFloatType;

		if (Dest.Float != 1.0f)
			return true;

		return false;

	case BuffMembers::Duration:
		Dest.UInt64 = GetSpellBuffTimer(buff->SpellID);
		Dest.Type = pTimeStampType;
		return true;

	case BuffMembers::Dar:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (SPELL* pSpell = GetSpellByID(buff->SpellID))
		{
			if (pSpell->SpellType != 0)
			{
				int slots = GetSpellNumEffects(pSpell);
				for (int i = 0; i < slots; i++)
				{
					int attrib = GetSpellAttrib(pSpell, i);
					if (IsDamageAbsorbSPA(attrib))
					{
						for (auto& slotData : buff->SlotData)
						{
							if (slotData.Slot == i)
							{
								Dest.DWord += slotData.Value;
							}
						}
					}
				}
				return true;
			}
		}
		return false;

	case BuffMembers::TotalCounters:
		Dest.DWord = GetTotalSpellCounters(*buff);
		Dest.Type = pIntType;
		return true;

	case BuffMembers::CountersDisease:
		Dest.DWord = GetSpellCounters(SPA_DISEASE, *buff);
		Dest.Type = pIntType;
		return true;

	case BuffMembers::CountersPoison:
		Dest.DWord = GetSpellCounters(SPA_POISON, *buff);
		Dest.Type = pIntType;
		return true;

	case BuffMembers::CountersCurse:
		Dest.DWord = GetSpellCounters(SPA_CURSE, *buff);
		Dest.Type = pIntType;
		return true;

	case BuffMembers::CountersCorruption:
		Dest.DWord = GetSpellCounters(SPA_CURSE, *buff);
		Dest.Type = pIntType;
		return true;

	case BuffMembers::HitCount:
		Dest.DWord = buff->HitCount;
		Dest.Type = pIntType;
		return true;

	case BuffMembers::Caster:
		Dest.Type = pStringType;
		if (VarPtr.HighPart == SpellDisplayType_BuffWnd && pBuffWnd)
		{
			if (CXStr* pName = pBuffWnd->WhoCast.FindFirst(buff->SpellID))
			{
				strcpy_s(DataTypeTemp, pName->c_str());
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
		}
		return false;

	default:
		return false;
	}
}

bool MQ2BuffType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (VarPtr.Int < 0)
		return false;

	auto pPCProfile = GetPcProfile();
	if (!pPCProfile)
		return false;

	EQ_Affect* buff = nullptr;
	if (VarPtr.Int < NUM_LONG_BUFFS)
		buff = &pPCProfile->Buff[VarPtr.Int];
	else if (VarPtr.Int < NUM_LONG_BUFFS + NUM_SHORT_BUFFS)
		buff = &pPCProfile->ShortBuff[VarPtr.Int - NUM_LONG_BUFFS];
	if (!buff)
		return false;

	if (EQ_Spell* pSpell = GetSpellByID(buff->SpellID))
	{
		strcpy_s(Destination, MAX_STRING, pSpell->Name);
		return true;
	}

	return false;
}

bool MQ2BuffType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pBuffType)
		return false;

	VarPtr.Int = Source.Int;
	return true;
}

} // namespace mq::datatypes
