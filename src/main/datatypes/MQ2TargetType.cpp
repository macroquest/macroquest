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
	MQTypeMember* pMember = MQ2TargetType::FindMember(Member);
	if (!pMember)
	{
		return pSpawnType->GetMember(pTarget, Member, Index, Dest);
	}

	if (!pTarget)
	{
		return false;
	}

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
		if (pAggroInfo && pAggroInfo->AggroSecondaryID)
		{
			Dest = pSpawnType->MakeTypeVar(GetSpawnByID(pAggroInfo->AggroSecondaryID));
			return true;
		}
		return false;

	case TargetMembers::AggroHolder: {
		// who the Target has the MOST aggro on
		if (!g_labelCache)
			return false;

		char* targetAggroHolder = g_labelCache->AggroMostHatedNameNoLock;
		if (targetAggroHolder[0] != '\0')
		{
			if (SPAWNINFO* pAggroHolder = GetSpawnByName(targetAggroHolder))
			{
				Dest = pSpawnType->MakeTypeVar(pAggroHolder);
				return true;
			}

			// no spawn was found for the name given, this can only mean one thing... its a pet or a mercenary
			MQSpawnSearch SearchSpawn;
			ClearSearchSpawn(&SearchSpawn);
			SearchSpawn.FRadius = 999999.0f;
			strcpy_s(SearchSpawn.szName, targetAggroHolder);

			if (SPAWNINFO* pAggroHolder = SearchThroughSpawns(&SearchSpawn, pLocalPlayer))
			{
				Dest = pSpawnType->MakeTypeVar(pAggroHolder);
				return true;
			}
		}
		else if (pTarget)
		{
			// is it me?
			if (g_labelCache->AggroMyHatePct >= 100)
			{
				if (Dest.Ptr = GetSpawnByID(pLocalPlayer->TargetOfTarget))
				{
					return true;
				}
			}
		}

		return false;
	}

	case TargetMembers::Slowed:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellAffect(SPA_HASTE, false));
		return true;

	case TargetMembers::Rooted:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellAffect(SPA_ROOT, false));
		return true;

	case TargetMembers::Mezzed:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellAffect(SPA_ENTHRALL, false));
		return true;

	case TargetMembers::Crippled:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellSubCat(SPELLCAT_DISEMPOWERING));
		return true;

	case TargetMembers::Maloed:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellSubCat(SPELLCAT_RESIST_DEBUFFS) && SpellClassMask(Shaman, Mage));
		return true;

	case TargetMembers::Tashed:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellSubCat(SPELLCAT_RESIST_DEBUFFS) && SpellClassMask(Enchanter));
		return true;

	case TargetMembers::Snared:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellAffect(SPA_MOVEMENT_RATE, false));
		return true;

	case TargetMembers::Hasted:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellAffect(SPA_HASTE));
		return true;

	case TargetMembers::Beneficial:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, [](CachedBuff buff) {
			auto spell = GetSpellByID(buff.spellId);
			return spell && spell->SpellType != 0;});
		return true;

	case TargetMembers::DSed:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellAffect(SPA_DAMAGE_SHIELD));
		return true;

	case TargetMembers::RevDSed:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellAffect(SPA_IRONMAIDEN));
		return true;

	case TargetMembers::Charmed:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellAffect(SPA_CHARM, false));
		return true;

	case TargetMembers::Aego:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellAffect(SPA_AC, true) &&
			SpellCategory(SPELLCAT_HP_BUFFS) &&
			(SpellSubCat(SPELLCAT_AEGOLISM) || SpellSubCat(SPELLCAT_SYMBOL)) &&
			SpellClassMask(Cleric));
		return true;

	case TargetMembers::Skin:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellCategory(SPELLCAT_HP_BUFFS) &&
			SpellSubCat(SPELLCAT_HP_TYPE_ONE) &&
			SpellClassMask(Druid));
		return true;

	case TargetMembers::Focus:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellCategory(SPELLCAT_HP_BUFFS) &&
			SpellSubCat(SPELLCAT_SHIELDING) &&
			SpellClassMask(Shaman));
		return true;

	case TargetMembers::Regen:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellAffect(SPA_HP) && !SpellClassMask(Beastlord));
		return true;

	case TargetMembers::Diseased:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellAffect(SPA_DISEASE, false));
		return true;

	case TargetMembers::Poisoned:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellAffect(SPA_POISON, false));
		return true;

	case TargetMembers::Cursed:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellAffect(SPA_CURSE, false));
		return true;

	case TargetMembers::Corrupted:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellAffect(SPA_CORRUPTION, false));
		return true;

	case TargetMembers::Symbol:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellCategory(SPELLCAT_HP_BUFFS) &&
			SpellSubCat(SPELLCAT_SYMBOL) &&
			SpellClassMask(Cleric));
		return true;

	case TargetMembers::Clarity:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellAffect(SPA_MANA) && SpellClassMask(Enchanter));
		return true;

	case TargetMembers::Pred:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellCategory(SPELLCAT_STATISTIC_BUFFS) &&
			SpellSubCat(SPELLCAT_ATTACK) &&
			SpellClassMask(Ranger));
		return true;

	case TargetMembers::Strength:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellCategory(SPELLCAT_HP_BUFFS) &&
			SpellSubCat(SPELLCAT_HP_TYPE_TWO) &&
			SpellClassMask(Ranger));
		return true;

	case TargetMembers::Brells:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellCategory(SPELLCAT_HP_BUFFS) &&
			SpellSubCat(SPELLCAT_HP_TYPE_TWO) &&
			SpellClassMask(Paladin));
		return true;

	case TargetMembers::SV:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellCategory(SPELLCAT_REGEN) &&
			SpellSubCat(SPELLCAT_MANA) &&
			SpellClassMask(Beastlord));
		return true;

	case TargetMembers::SE:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellCategory(SPELLCAT_REGEN) &&
			SpellSubCat(SPELLCAT_HEALTH_MANA) &&
			SpellClassMask(Beastlord));
		return true;

	case TargetMembers::HybridHP:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellCategory(SPELLCAT_HP_BUFFS) &&
			SpellSubCat(SPELLCAT_HP_TYPE_ONE) &&
			SpellClassMask(Ranger));
		return true;

	case TargetMembers::Growth:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellCategory(SPELLCAT_HP_BUFFS) &&
			SpellSubCat(SPELLCAT_TEMPORARY) &&
			SpellClassMask(Druid));
		return true;

	case TargetMembers::Shining:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellCategory(SPELLCAT_UTILITY_BENEFICIAL) &&
			SpellSubCat(SPELLCAT_MELEE_GUARD) &&
			SpellClassMask(Cleric));
		return true;

	case TargetMembers::Feared:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellAffect(SPA_FEAR, false));
		return true;

	case TargetMembers::Silenced:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellAffect(SPA_SILENCE, false));
		return true;

	case TargetMembers::Invulnerable:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget, SpellAffect(SPA_INVULNERABILITY, false));
		return true;

	case TargetMembers::Dotted:
		Dest.Type = pCachedBuffType;
		Dest.Ptr = pTarget;
		Dest.HighPart = GetCachedBuff(pTarget,
			[](CachedBuff buff)
			{
				auto spell = GetSpellByID(buff.spellId);
				return SpellAffect(SPA_HP, false)(spell) && spell && spell->IsDetrimentalSpell() && spell->IsDoTSpell();
			});
		return true;

	case TargetMembers::MaxMeleeTo:
		Dest.Float = get_melee_range(pControlledPlayer, pTarget);
		Dest.Type = pFloatType;
		return true;

	default:
		return false;
	}
}

bool MQ2TargetType::ToString(MQVarPtr VarPtr, char* Destination)
{
	SPAWNINFO* pSpawn = MQ2SpawnType::GetSpawnPtr(VarPtr);
	if (!pSpawn)
		return false;
	strcpy_s(Destination, MAX_STRING, pSpawn->Name);
	return true;
}

bool MQ2TargetType::Downcast(const MQVarPtr& fromVar, MQVarPtr& toVar, MQ2Type* toType)
{
	if (toType == pSpawnType)
	{
		toVar = fromVar;
		return true;
	}

	return false;
}

bool MQ2TargetType::dataTarget(const char* szIndex, MQTypeVar& Ret)
{
	Ret = pSpawnType->MakeTypeVar(pTarget, pTargetType);
	return true;
}

} // namespace mq::datatypes
