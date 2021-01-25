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

enum class TargetMembers
{
	PctAggro = 1,
	SecondaryPctAggro,
	SecondaryAggroPlayer,
	AggroHolder,
	Slowed,
	Rooted,
	Mezzed,
	Crippled,
	Maloed,
	Tashed,
	Snared,
	Hasted,
	Aego,
	Skin,
	Focus,
	Regen,
	Symbol,
	Clarity,
	Pred,
	Strength,
	Brells,
	SV,
	SE,
	HybridHP,
	Growth,
	Shining,
	Beneficial,
	DSed,
	RevDSed,
	Charmed,
	Diseased,
	Poisoned,
	Cursed,
	Corrupted,
	Feared,
	Silenced,
	Invulnerable,
	Dotted,
	MaxMeleeTo,
};

MQ2TargetType::MQ2TargetType() : MQ2Type("target")
{
	ScopedTypeMember(TargetMembers, PctAggro);
	ScopedTypeMember(TargetMembers, SecondaryPctAggro);
	ScopedTypeMember(TargetMembers, SecondaryAggroPlayer);
	ScopedTypeMember(TargetMembers, AggroHolder);
	ScopedTypeMember(TargetMembers, Slowed);
	ScopedTypeMember(TargetMembers, Rooted);
	ScopedTypeMember(TargetMembers, Mezzed);
	ScopedTypeMember(TargetMembers, Crippled);
	ScopedTypeMember(TargetMembers, Maloed);
	ScopedTypeMember(TargetMembers, Tashed);
	ScopedTypeMember(TargetMembers, Snared);
	ScopedTypeMember(TargetMembers, Hasted);
	ScopedTypeMember(TargetMembers, Aego);
	ScopedTypeMember(TargetMembers, Skin);
	ScopedTypeMember(TargetMembers, Focus);
	ScopedTypeMember(TargetMembers, Regen);
	ScopedTypeMember(TargetMembers, Symbol);
	ScopedTypeMember(TargetMembers, Clarity);
	ScopedTypeMember(TargetMembers, Pred);
	ScopedTypeMember(TargetMembers, Strength);
	ScopedTypeMember(TargetMembers, Brells);
	ScopedTypeMember(TargetMembers, SV);
	ScopedTypeMember(TargetMembers, SE);
	ScopedTypeMember(TargetMembers, HybridHP);
	ScopedTypeMember(TargetMembers, Growth);
	ScopedTypeMember(TargetMembers, Shining);
	ScopedTypeMember(TargetMembers, Beneficial);
	ScopedTypeMember(TargetMembers, DSed);
	ScopedTypeMember(TargetMembers, RevDSed);
	ScopedTypeMember(TargetMembers, Charmed);
	ScopedTypeMember(TargetMembers, Diseased);
	ScopedTypeMember(TargetMembers, Poisoned);
	ScopedTypeMember(TargetMembers, Cursed);
	ScopedTypeMember(TargetMembers, Corrupted);
	ScopedTypeMember(TargetMembers, Feared);
	ScopedTypeMember(TargetMembers, Silenced);
	ScopedTypeMember(TargetMembers, Invulnerable);
	ScopedTypeMember(TargetMembers, Dotted);
	ScopedTypeMember(TargetMembers, MaxMeleeTo);
}

bool MQ2TargetType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!VarPtr.Ptr)
		return false;

	MQTypeMember* pMember = MQ2TargetType::FindMember(Member);
	if (!pMember)
	{
		return pSpawnType->GetMember(VarPtr, Member, Index, Dest);
	}

	if (!GetCharInfo())
		return false;

	switch (static_cast<TargetMembers>(pMember->ID))
	{
	case TargetMembers::PctAggro:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pAggroInfo)
		{
			Dest.DWord = pAggroInfo->aggroData[AD_Player].AggroPct;
			return true;
		}
		return false;

	case TargetMembers::SecondaryPctAggro:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pAggroInfo)
		{
			Dest.DWord = pAggroInfo->aggroData[AD_Secondary].AggroPct;
			return true;
		}
		return false;

	case TargetMembers::SecondaryAggroPlayer:
		Dest.Type = pSpawnType;

		if (pAggroInfo && pAggroInfo->AggroSecondaryID)
		{
			Dest.Ptr = GetSpawnByID(pAggroInfo->AggroSecondaryID);
			return true;
		}
		return false;

	case TargetMembers::AggroHolder: {
		Dest.Type = pSpawnType;
		// who the Target has the MOST aggro on
		char* pTargetAggroHolder = EQADDR_TARGETAGGROHOLDER;
		if (pTargetAggroHolder[0] != '\0')
		{
			SPAWNINFO* pAggroHolder = (SPAWNINFO*)GetSpawnByName(pTargetAggroHolder);
			if (pAggroHolder)
			{
				Dest.Ptr = pAggroHolder;
				return true;
			}
			else
			{
				// ok no spawn was found for the name given, this can only mean one thing... its a pet or a mercenary
				MQSpawnSearch SearchSpawn;
				ClearSearchSpawn(&SearchSpawn);
				SearchSpawn.FRadius = 999999.0f;
				strcpy_s(SearchSpawn.szName, pTargetAggroHolder);
				pAggroHolder = SearchThroughSpawns(&SearchSpawn, (SPAWNINFO*)pLocalPlayer);
				if (pAggroHolder)
				{
					Dest.Ptr = pAggroHolder;
					return true;
				}
			}
		}
		else
		{
			// it could be me...
			// lets check
			if (pTarget && EQADDR_GROUPAGGRO)
			{
				if (*(DWORD*)(EQADDR_GROUPAGGRO + 0x78) >= 100)
				{
					if (Dest.Ptr = GetSpawnByID(((SPAWNINFO*)pLocalPlayer)->TargetOfTarget))
					{
						return true;
					}
				}
			}
		}
		return false;
	}

	case TargetMembers::Slowed:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(SpellAffect(SPA_HASTE, false)));
		return Dest.HighPart >= 0;

	case TargetMembers::Rooted:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(SpellAffect(SPA_ROOT, false)));
		return Dest.HighPart >= 0;

	case TargetMembers::Mezzed:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(SpellAffect(SPA_ENTHRALL, false)));
		return Dest.HighPart >= 0;

	case TargetMembers::Crippled:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(SpellSubCat(SPELLCAT_DISEMPOWERING)));
		return Dest.HighPart >= 0;

	case TargetMembers::Maloed:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(SpellSubCat(SPELLCAT_RESIST_DEBUFFS), SpellClassMask(Shaman, Mage)));
		return Dest.HighPart >= 0;

	case TargetMembers::Tashed:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(SpellSubCat(SPELLCAT_RESIST_DEBUFFS), SpellClassMask(Enchanter)));
		return Dest.HighPart >= 0;

	case TargetMembers::Snared:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(SpellAffect(SPA_MOVEMENT_RATE, false)));
		return Dest.HighPart >= 0;

	case TargetMembers::Hasted:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(SpellAffect(SPA_HASTE, true)));
		return Dest.HighPart >= 0;

	case TargetMembers::Beneficial:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs( [](CachedBuff buff) {
			auto spell = GetSpellByID(buff.spellId);
			return spell && spell->SpellType != 0;}));
		return Dest.HighPart >= 0;

	case TargetMembers::DSed:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(SpellAffect(SPA_DAMAGE_SHIELD, true)));
		return Dest.HighPart >= 0;

	case TargetMembers::RevDSed:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(SpellAffect(SPA_IRONMAIDEN, true)));
		return Dest.HighPart >= 0;

	case TargetMembers::Charmed:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(SpellAffect(SPA_CHARM, false)));
		return Dest.HighPart >= 0;

	case TargetMembers::Aego:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(
			SpellAffect(SPA_AC, true),
			SpellCategory(SPELLCAT_HP_BUFFS),
			AnyBuffs(SpellSubCat(SPELLCAT_AEGOLISM), SpellSubCat(SPELLCAT_SYMBOL)),
			SpellClassMask(Cleric)));
		return Dest.HighPart >= 0;

	case TargetMembers::Skin:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(
			SpellCategory(SPELLCAT_HP_BUFFS),
			SpellSubCat(SPELLCAT_HP_TYPE_ONE),
			SpellClassMask(Druid)));
		return Dest.HighPart >= 0;

	case TargetMembers::Focus:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(
			SpellCategory(SPELLCAT_HP_BUFFS),
			SpellSubCat(SPELLCAT_SHIELDING),
			SpellClassMask(Shaman)));
		return Dest.HighPart >= 0;

	case TargetMembers::Regen:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(
			SpellAffect(SPA_HP, true),
			!SpellClassMask(Beastlord)));
		return Dest.HighPart >= 0;

	case TargetMembers::Diseased:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(SpellAffect(SPA_DISEASE, false)));
		return Dest.HighPart >= 0;

	case TargetMembers::Poisoned:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(SpellAffect(SPA_POISON, false)));
		return Dest.HighPart >= 0;

	case TargetMembers::Cursed:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(SpellAffect(SPA_CURSE, false)));
		return Dest.HighPart >= 0;

	case TargetMembers::Corrupted:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(SpellAffect(SPA_CORRUPTION, false)));
		return Dest.HighPart >= 0;

	case TargetMembers::Symbol:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(
			SpellCategory(SPELLCAT_HP_BUFFS),
			SpellSubCat(SPELLCAT_SYMBOL),
			SpellClassMask(Cleric)));
		return Dest.HighPart >= 0;

	case TargetMembers::Clarity:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(
			SpellAffect(SPA_MANA, true),
			SpellClassMask(Enchanter)));
		return Dest.HighPart >= 0;

	case TargetMembers::Pred:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(
			SpellCategory(SPELLCAT_STATISTIC_BUFFS),
			SpellSubCat(SPELLCAT_ATTACK),
			SpellClassMask(Ranger)));
		return Dest.HighPart >= 0;

	case TargetMembers::Strength:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(
			SpellCategory(SPELLCAT_HP_BUFFS),
			SpellSubCat(SPELLCAT_HP_TYPE_TWO),
			SpellClassMask(Ranger)));
		return Dest.HighPart >= 0;

	case TargetMembers::Brells:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(
			SpellCategory(SPELLCAT_HP_BUFFS),
			SpellSubCat(SPELLCAT_HP_TYPE_TWO),
			SpellClassMask(Paladin)));
		return Dest.HighPart >= 0;

	case TargetMembers::SV:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(
			SpellCategory(SPELLCAT_REGEN),
			SpellSubCat(SPELLCAT_MANA),
			SpellClassMask(Beastlord)));
		return Dest.HighPart >= 0;

	case TargetMembers::SE:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(
			SpellCategory(SPELLCAT_REGEN),
			SpellSubCat(SPELLCAT_HEALTH_MANA),
			SpellClassMask(Beastlord)));
		return Dest.HighPart >= 0;

	case TargetMembers::HybridHP:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(
			SpellCategory(SPELLCAT_HP_BUFFS),
			SpellSubCat(SPELLCAT_HP_TYPE_ONE),
			SpellClassMask(Ranger)));
		return Dest.HighPart >= 0;

	case TargetMembers::Growth:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(
			SpellCategory(SPELLCAT_HP_BUFFS),
			SpellSubCat(SPELLCAT_TEMPORARY),
			SpellClassMask(Druid)));
		return Dest.HighPart >= 0;

	case TargetMembers::Shining:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(
			SpellCategory(SPELLCAT_UTILITY_BENEFICIAL),
			SpellSubCat(SPELLCAT_MELEE_GUARD),
			SpellClassMask(Cleric)));
		return Dest.HighPart >= 0;

	case TargetMembers::Feared:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(SpellAffect(SPA_FEAR, false)));
		return Dest.HighPart >= 0;

	case TargetMembers::Silenced:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(SpellAffect(SPA_SILENCE, false)));
		return Dest.HighPart >= 0;

	case TargetMembers::Invulnerable:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs(SpellAffect(SPA_INVULNERABILITY, false)));
		return Dest.HighPart >= 0;

	case TargetMembers::Dotted:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, AllBuffs( SpellAffect(SPA_HP, false),
			[](CachedBuff buff)
			{
				auto spell = GetSpellByID(buff.spellId);
				return spell && spell->IsDetrimentalSpell() && spell->IsDoTSpell();
			}));
		return Dest.HighPart >= 0;

	case TargetMembers::MaxMeleeTo: {
		Dest.Float = get_melee_range(pCharSpawn, pTarget);
		Dest.Type = pFloatType;
		return true;
	}

	default:
		return false;
	}
}

bool MQ2TargetType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (!VarPtr.Ptr)
		return false;

	SPAWNINFO* pSpawn = static_cast<SPAWNINFO*>(VarPtr.Ptr);
	strcpy_s(Destination, MAX_STRING, pSpawn->Name);
	return true;
}

void MQ2TargetType::InitVariable(MQVarPtr& VarPtr)
{
	// FIXME: Do not allocate a SPAWNINFO
	VarPtr.Ptr = new SPAWNINFO();
	VarPtr.HighPart = 0;

	// FIXME: Do not ZeroMemory a SPAWNINFO
	ZeroMemory(VarPtr.Ptr, sizeof(SPAWNINFO));
}

void MQ2TargetType::FreeVariable(MQVarPtr& VarPtr)
{
	// FIXME: Do not allocate a SPAWNINFO
	SPAWNINFO* pSpawn = static_cast<SPAWNINFO*>(VarPtr.Ptr);
	delete pSpawn;
}

bool MQ2TargetType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	if (Source.Type == pSpawnType)
	{
		memcpy(VarPtr.Ptr, Source.Ptr, sizeof(SPAWNINFO));
		return true;
	}
	else
	{
		if (SPAWNINFO* pOther = (SPAWNINFO*)GetSpawnByID(Source.DWord))
		{
			memcpy(VarPtr.Ptr, pOther, sizeof(SPAWNINFO));
			return true;
		}
	}
	return false;
}

bool MQ2TargetType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	if (SPAWNINFO* pOther = (SPAWNINFO*)GetSpawnByID(GetIntFromString(Source, 0)))
	{
		memcpy(VarPtr.Ptr, pOther, sizeof(SPAWNINFO));
		return true;
	}
	return false;
}

bool MQ2TargetType::dataTarget(const char* szIndex, MQTypeVar& Ret)
{
	if (pTarget)
	{
		Ret.Ptr = pTarget;
		Ret.Type = pTargetType;
		return true;
	}
	return false;
}

} // namespace mq::datatypes
