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

enum class SpellMembers
{
	ID = 1,
	Name,
	Level,
	Skill,
	Mana,
	ResistAdj,
	Range,
	AERange,
	PushBack,
	CastTime,
	FizzleTime,
	MyCastTime,
	RecoveryTime,
	RecastTime,
	Duration,
	SpellType,
	TargetType,
	ResistType,
	CastOnYou,
	CastOnAnother,
	WearOff,
	CounterType,
	CounterNumber,
	Stacks,
	WillLand,
	StacksPet,
	WillLandPet,
	WillStack,
	MyRange,
	Address,
	EnduranceCost,
	MaxLevel,
	Category,
	Subcategory,
	Restrictions,
	Base,
	Base2,
	Max,
	Calc,
	Attrib,
	AutoCast,
	Extra,
	RecastTimerID,
	SPA,
	ReagentID,
	ReagentCount,
	CastByOther,
	TimeOfDay,
	DurationWindow,
	CanMGB,
	Deletable,
	BookIcon,
	ActorTagId,
	Description,
	StacksWith,
	Rank,
	RankName,
	SpellGroup,
	SubSpellGroup,
	Beneficial,
	IsActiveAA,
	CalcIndex,
	NumEffects,
	Location,
	IsSwarmSpell,
	IsSkill,
	DurationValue1,
	NewStacks,
	NewStacksWith,
	StacksTarget,
	StacksWithDiscs,
	IllusionOkWhenMounted,
	EQSpellDuration,
	CastByMe,
	HasSPA,
	Trigger,
	BaseName,
	NoExpendReagentID,
	StacksSpawn,
	SpellIcon,
	GemIcon,
	SlowPct,
	HastePct,
	MyDuration,
	BaseEffectsFocusCap,
};

enum class SpellMethods
{
};

MQ2SpellType::MQ2SpellType() : MQ2Type("spell")
{
	ScopedTypeMember(SpellMembers, ID);
	ScopedTypeMember(SpellMembers, Name);
	ScopedTypeMember(SpellMembers, Level);
	ScopedTypeMember(SpellMembers, Skill);
	ScopedTypeMember(SpellMembers, Mana);
	ScopedTypeMember(SpellMembers, ResistAdj);
	ScopedTypeMember(SpellMembers, Range);
	ScopedTypeMember(SpellMembers, AERange);
	ScopedTypeMember(SpellMembers, PushBack);
	ScopedTypeMember(SpellMembers, CastTime);
	ScopedTypeMember(SpellMembers, FizzleTime);
	ScopedTypeMember(SpellMembers, MyCastTime);
	ScopedTypeMember(SpellMembers, RecoveryTime);
	ScopedTypeMember(SpellMembers, RecastTime);
	ScopedTypeMember(SpellMembers, Duration);
	ScopedTypeMember(SpellMembers, SpellType);
	ScopedTypeMember(SpellMembers, TargetType);
	ScopedTypeMember(SpellMembers, ResistType);
	ScopedTypeMember(SpellMembers, CastOnYou);
	ScopedTypeMember(SpellMembers, CastOnAnother);
	ScopedTypeMember(SpellMembers, WearOff);
	ScopedTypeMember(SpellMembers, CounterType);
	ScopedTypeMember(SpellMembers, CounterNumber);
	ScopedTypeMember(SpellMembers, Stacks);
	ScopedTypeMember(SpellMembers, WillLand);
	ScopedTypeMember(SpellMembers, StacksPet);
	ScopedTypeMember(SpellMembers, WillLandPet);
	ScopedTypeMember(SpellMembers, WillStack);
	ScopedTypeMember(SpellMembers, MyRange);
	ScopedTypeMember(SpellMembers, Address);
	ScopedTypeMember(SpellMembers, EnduranceCost);
	ScopedTypeMember(SpellMembers, MaxLevel);
	ScopedTypeMember(SpellMembers, Category);
	ScopedTypeMember(SpellMembers, Subcategory);
	ScopedTypeMember(SpellMembers, Restrictions);
	ScopedTypeMember(SpellMembers, Base);
	ScopedTypeMember(SpellMembers, Base2);
	ScopedTypeMember(SpellMembers, Max);
	ScopedTypeMember(SpellMembers, Calc);
	ScopedTypeMember(SpellMembers, Attrib);
	ScopedTypeMember(SpellMembers, AutoCast);
	ScopedTypeMember(SpellMembers, Extra);
	ScopedTypeMember(SpellMembers, RecastTimerID);
	ScopedTypeMember(SpellMembers, SPA);
	ScopedTypeMember(SpellMembers, ReagentID);
	ScopedTypeMember(SpellMembers, ReagentCount);
	ScopedTypeMember(SpellMembers, CastByOther);
	ScopedTypeMember(SpellMembers, TimeOfDay);
	ScopedTypeMember(SpellMembers, DurationWindow);
	ScopedTypeMember(SpellMembers, CanMGB);
	ScopedTypeMember(SpellMembers, Deletable);
	ScopedTypeMember(SpellMembers, BookIcon);
	ScopedTypeMember(SpellMembers, ActorTagId);
	ScopedTypeMember(SpellMembers, Description);
	ScopedTypeMember(SpellMembers, StacksWith);
	ScopedTypeMember(SpellMembers, Rank);
	ScopedTypeMember(SpellMembers, RankName);
	ScopedTypeMember(SpellMembers, SpellGroup);
	ScopedTypeMember(SpellMembers, SubSpellGroup);
	ScopedTypeMember(SpellMembers, Beneficial);
	ScopedTypeMember(SpellMembers, IsActiveAA);
	ScopedTypeMember(SpellMembers, CalcIndex);
	ScopedTypeMember(SpellMembers, NumEffects);
	ScopedTypeMember(SpellMembers, Location);
	ScopedTypeMember(SpellMembers, IsSwarmSpell);
	ScopedTypeMember(SpellMembers, IsSkill);
	ScopedTypeMember(SpellMembers, DurationValue1);
	ScopedTypeMember(SpellMembers, NewStacks);
	ScopedTypeMember(SpellMembers, NewStacksWith);
	ScopedTypeMember(SpellMembers, StacksTarget);
	ScopedTypeMember(SpellMembers, StacksWithDiscs);
	ScopedTypeMember(SpellMembers, IllusionOkWhenMounted);
	ScopedTypeMember(SpellMembers, EQSpellDuration);
	ScopedTypeMember(SpellMembers, CastByMe);
	ScopedTypeMember(SpellMembers, HasSPA);
	ScopedTypeMember(SpellMembers, Trigger);
	ScopedTypeMember(SpellMembers, BaseName);
	ScopedTypeMember(SpellMembers, NoExpendReagentID);
	ScopedTypeMember(SpellMembers, StacksSpawn);
	ScopedTypeMember(SpellMembers, SpellIcon);
	ScopedTypeMember(SpellMembers, GemIcon);
	ScopedTypeMember(SpellMembers, SlowPct);
	ScopedTypeMember(SpellMembers, HastePct);
	ScopedTypeMember(SpellMembers, MyDuration);
	ScopedTypeMember(SpellMembers, BaseEffectsFocusCap);
	AddMember(static_cast<int>(SpellMembers::BaseEffectsFocusCap), "SongCap");
}

bool MQ2SpellType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	auto pSpell = static_cast<EQ_Spell*>(VarPtr.Ptr);
	if (!pSpell)
		return false;

	MQTypeMember* pMember = MQ2SpellType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<SpellMembers>(pMember->ID))
	{
	case SpellMembers::ID:
		Dest.DWord = pSpell->ID;
		Dest.Type = pIntType;
		return true;

	case SpellMembers::Name:
		strcpy_s(DataTypeTemp, pSpell->Name);
		Dest.Ptr = &DataTypeTemp;
		Dest.Type = pStringType;
		return true;

	case SpellMembers::Level:
	{
		Dest.Type = pIntType;

		if (!Index[0] && pLocalPlayer)
		{
			Dest.DWord = pSpell->ClassLevel[pLocalPlayer->GetClass()];
			return true;
		}

		int classIdx = GetIntFromString(Index, -1);
		if (classIdx >= 0 && classIdx <= MAX_CLASSES) // array defined with size of MAX_CLASSES + 1
		{
			Dest.DWord = pSpell->ClassLevel[classIdx];
			return true;
		}

		return false;
	}

	case SpellMembers::Mana:
		Dest.DWord = pSpell->ManaCost;
		Dest.Type = pIntType;
		return true;

	case SpellMembers::ResistAdj:
		Dest.DWord = pSpell->ResistAdj;
		Dest.Type = pIntType;
		return true;

	case SpellMembers::Range:
		Dest.Float = pSpell->Range;
		Dest.Type = pFloatType;
		return true;

	case SpellMembers::AERange:
		Dest.Float = pSpell->AERange;
		Dest.Type = pFloatType;
		return true;

	case SpellMembers::PushBack:
		Dest.Float = pSpell->PushBack;
		Dest.Type = pFloatType;
		return true;

	case SpellMembers::CastTime:
		Dest.UInt64 = pSpell->CastTime;
		Dest.Type = pTimeStampType;
		return true;

	case SpellMembers::RecoveryTime:
	case SpellMembers::FizzleTime:
		Dest.UInt64 = pSpell->RecoveryTime;
		Dest.Type = pTimeStampType;
		return true;

	case SpellMembers::RecastTime:
		Dest.UInt64 = pSpell->RecastTime;
		Dest.Type = pTimeStampType;
		return true;

	case SpellMembers::ResistType:
		switch (pSpell->Resist)
		{
		case ResistType_Corruption:
			strcpy_s(DataTypeTemp, "Corruption");
			break;
		case ResistType_Physical:
			strcpy_s(DataTypeTemp, "Physical");
			break;
		case ResistType_Prismatic:
			strcpy_s(DataTypeTemp, "Prismatic");
			break;
		case ResistType_Chromatic:
			strcpy_s(DataTypeTemp, "Chromatic");
			break;
		case ResistType_Disease:
			strcpy_s(DataTypeTemp, "Disease");
			break;
		case ResistType_Poison:
			strcpy_s(DataTypeTemp, "Poison");
			break;
		case ResistType_Cold:
			strcpy_s(DataTypeTemp, "Cold");
			break;
		case ResistType_Fire:
			strcpy_s(DataTypeTemp, "Fire");
			break;
		case ResistType_Magic:
			strcpy_s(DataTypeTemp, "Magic");
			break;
		case ResistType_None:
			strcpy_s(DataTypeTemp, "Unresistable");
			break;
		default:
			strcpy_s(DataTypeTemp, "Unknown");
			break;
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpellMembers::SpellType:
		switch (pSpell->SpellType)
		{
		case SpellType_BeneficialGroupOnly:
			strcpy_s(DataTypeTemp, "Beneficial(Group)");
			break;
		case SpellType_Beneficial:
			strcpy_s(DataTypeTemp, "Beneficial");
			break;
		case SpellType_Detrimental:
			strcpy_s(DataTypeTemp, "Detrimental");
			break;
		default:
			strcpy_s(DataTypeTemp, "Unknown");
			break;
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpellMembers::TargetType:
		// TODO: Turn these into an enum class
		switch (pSpell->TargetType)
		{
		case 50:
			strcpy_s(DataTypeTemp, "Target_AE_No_Players_Pets");
			break; // blanket of forgetfullness. beneficial, AE mem blur, with max targets
		case 52:
			strcpy_s(DataTypeTemp, "Single Friendly (or Target's Target");
			break; // Introduced in Torment of Velious. Spell affects target if friendly, or target's target if the target is an unfriendly.
		case 47:
			strcpy_s(DataTypeTemp, "Pet Owner");
			break;
		case 46:
			strcpy_s(DataTypeTemp, "Target of Target");
			break;
		case 45:
			strcpy_s(DataTypeTemp, "Free Target");
			break;
		case 44:
			strcpy_s(DataTypeTemp, "Beam");
			break;
		case 43:
			strcpy_s(DataTypeTemp, "Single in Group");
			break;
		case 42:
			strcpy_s(DataTypeTemp, "Directional AE");
			break;
		case 41:
			strcpy_s(DataTypeTemp, "Group v2");
			break;
		case 40:
			strcpy_s(DataTypeTemp, "AE PC v2");
			break;
		case 39:
			strcpy_s(DataTypeTemp, "No Pets");
			break;
		case 38:
			strcpy_s(DataTypeTemp, "Pet2");
			break;
		case 37:
			strcpy_s(DataTypeTemp, "Caster PB NPC");
			break;
		case 36:
			strcpy_s(DataTypeTemp, "Caster PB PC");
			break;
		case 35:
			strcpy_s(DataTypeTemp, "Special Muramites");
			break;
		case 34:
			strcpy_s(DataTypeTemp, "Chest");
			break;
		case 33:
			strcpy_s(DataTypeTemp, "Hatelist2");
			break;
		case 32:
			strcpy_s(DataTypeTemp, "Hatelist");
			break;
		case 25:
			strcpy_s(DataTypeTemp, "AE Summoned");
			break;
		case 24:
			strcpy_s(DataTypeTemp, "AE Undead");
			break;
		case 20:
			strcpy_s(DataTypeTemp, "Targeted AE Tap");
			break;
		case 18:
			strcpy_s(DataTypeTemp, "Uber Dragons");
			break;
		case 17:
			strcpy_s(DataTypeTemp, "Uber Giants");
			break;
		case 16:
			strcpy_s(DataTypeTemp, "Plant");
			break;
		case 15:
			strcpy_s(DataTypeTemp, "Corpse");
			break;
		case 14:
			strcpy_s(DataTypeTemp, "Pet");
			break;
		case 13:
			strcpy_s(DataTypeTemp, "LifeTap");
			break;
		case 11:
			strcpy_s(DataTypeTemp, "Summoned");
			break;
		case 10:
			strcpy_s(DataTypeTemp, "Undead");
			break;
		case  9:
			strcpy_s(DataTypeTemp, "Animal");
			break;
		case  8:
			strcpy_s(DataTypeTemp, "Targeted AE");
			break;
		case  6:
			strcpy_s(DataTypeTemp, "Self");
			break;
		case  5:
			strcpy_s(DataTypeTemp, "Single");
			break;
		case  4:
			strcpy_s(DataTypeTemp, "PB AE");
			break;
		case  3:
			strcpy_s(DataTypeTemp, "Group v1");
			break;
		case  2:
			strcpy_s(DataTypeTemp, "AE PC v1");
			break;
		case  1:
			strcpy_s(DataTypeTemp, "Line of Sight");
			break;
		default:
			strcpy_s(DataTypeTemp, "Unknown");
			break;
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpellMembers::Skill:
		strcpy_s(DataTypeTemp, szSkills[pSpell->Skill]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpellMembers::MyCastTime:
	{
		ItemPtr pc;
		uint64_t mct = (uint64_t)GetCastingTimeModifier(pSpell) +
			GetFocusCastingTimeModifier(pSpell, pc, false) +
			pSpell->CastTime;

		Dest.UInt64 = std::max((uint64_t)pSpell->CastTime / 2, mct);

		Dest.Type = pTimeStampType;
		return true;
	}

	case SpellMembers::Duration:
		Dest.DWord = GetSpellDuration(pSpell, pLocalPlayer);
		Dest.Type = pTicksType;
		return true;

	case SpellMembers::MyDuration:
		Dest.DWord = EQGetMySpellDuration(pSpell);
		Dest.Type = pTicksType;
		return true;

	case SpellMembers::EQSpellDuration:
		Dest.DWord = EQGetSpellDuration(pSpell, pLocalPlayer ? pLocalPlayer->Level : 0, false);
		Dest.Type = pTicksType;
		return true;

	case SpellMembers::CastByMe:
		strcpy_s(DataTypeTemp, " casts Unknown Spell.");
		if (const char* str = GetSpellString(pSpell->ID, SpellStringCastByMe))
			strcpy_s(DataTypeTemp, str);

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpellMembers::CastByOther:
		strcpy_s(DataTypeTemp, " casts Unknown Spell.");
		if (const char* str = GetSpellString(pSpell->ID, SpellStringCastByOther))
			strcpy_s(DataTypeTemp, str);

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpellMembers::CastOnYou:
		strcpy_s(DataTypeTemp, "You feel bogus as an unknown spell accosts you.");
		if (const char* str = GetSpellString(pSpell->ID, SpellStringCastOnYou))
			strcpy_s(DataTypeTemp, str);

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpellMembers::CastOnAnother:
		strcpy_s(DataTypeTemp, " is the victim of an unknown spell.");
		if (const char* str = GetSpellString(pSpell->ID, SpellStringCastOnAnother))
			strcpy_s(DataTypeTemp, str);

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpellMembers::WearOff:
		strcpy_s(DataTypeTemp, "An unknown spell is gone.");
		if (const char* str = GetSpellString(pSpell->ID, SpellStringWearOff))
			strcpy_s(DataTypeTemp, str);

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpellMembers::CounterType:
		strcpy_s(DataTypeTemp, "None");
		for (int i = 0; i < GetSpellNumEffects(pSpell); i++)
		{
			switch (GetSpellAttrib(pSpell, i))
			{
			case SPA_DISEASE:
				strcpy_s(DataTypeTemp, "Disease");
				break;
			case SPA_POISON:
				strcpy_s(DataTypeTemp, "Poison");
				break;
			case SPA_CURSE:
				strcpy_s(DataTypeTemp, "Curse");
				break;
			case SPA_CORRUPTION:
				strcpy_s(DataTypeTemp, "Corruption");
				break;
			}
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpellMembers::CounterNumber:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		for (int i = 0; i < GetSpellNumEffects(pSpell); i++)
		{
			if (IsSpellCountersSPA(GetSpellAttrib(pSpell, i)))
			{
				Dest.DWord = GetSpellBase(pSpell, i);
				return true;
			}
		}

		return true;

	case SpellMembers::Stacks:
	case SpellMembers::NewStacks: // stacks on self
	{
		Dest.Set(false);
		Dest.Type = pBoolType;

		if (!pLocalPlayer)
			return false;

		auto pPc = pLocalPlayer->GetPcClient();

		int SlotIndex = -1;
		EQ_Affect* ret = pPc->FindAffectSlot(pSpell->ID, pLocalPlayer, &SlotIndex, true, pLocalPlayer->Level);

		Dest.Set(ret &&
			SlotIndex != -1 &&
			GetSpellDuration(pSpell, pLocalPlayer) >= -1 &&
			ret->Duration <= GetIntFromString(Index, 0));

		return true;
	}

	case SpellMembers::WillLand:
	{
		// this extra member is exactly like stacks but without a duration check. The duration
		// check on stacks implies that we _don't_ want overwrites, but that means that any
		// spell that will land but overwrites something will fail that check. So provide the
		// raw "this will land on your target" check as well
		if (!pLocalPlayer) return false;

		auto pPc = pLocalPlayer->GetPcClient();

		int SlotIndex = -1;
		EQ_Affect* ret = pPc->FindAffectSlot(pSpell->ID, pLocalPlayer, &SlotIndex, true, pLocalPlayer->Level);

		Dest.Type = pIntType;
		Dest.Set(SlotIndex + 1); // + 1 here because everything in macro land is 1-indexed and this allows someone to test as a BOOL (0 is falsey)
		return true;
	}

	case SpellMembers::StacksPet: {
		Dest.Set(true);
		Dest.Type = pBoolType;

		if (!pPetInfoWnd || !pLocalPlayer)
			return false;

		for (int nBuff = 0; nBuff < MAX_TOTAL_BUFFS; nBuff++)
		{
			auto pBuffSpell = GetSpellByID(pPetInfoWnd->Buff[nBuff]);
			if (!pBuffSpell)
				continue;

			// if we have less duration than the duration argument, then this "will stack" so we need to keep checking
			if (!WillStackWith(pSpell, pBuffSpell) && (
				GetSpellDuration(pBuffSpell, pLocalPlayer) < -1 ||
				ceil(pPetInfoWnd->PetBuffTimer[nBuff] / 6000) > GetIntFromString(Index, 0)))
			{
				Dest.Set(false);
				return true;
			}
		}

		return true;
	}

	case SpellMembers::WillLandPet:
	{
		// This is the same as `WillLand`, but for pets
		if (!pPetInfoWnd || !pLocalPlayer)
			return false;

		Dest.Set(0);
		Dest.Type = pIntType;

		for (int nBuff = 0; nBuff < MAX_TOTAL_BUFFS; nBuff++)
		{
			auto pBuffSpell = GetSpellByID(pPetInfoWnd->Buff[nBuff]);
			if (pBuffSpell && !WillStackWith(pSpell, pBuffSpell))
			{
				Dest.Set(nBuff + 1);
				return true;
			}
		}

		return true;
	}

	case SpellMembers::WillStack:
	case SpellMembers::StacksWith:
	case SpellMembers::NewStacksWith: // if a spell stack with another spell
	{
		Dest.Set(false);
		Dest.Type = pBoolType;

		if (!Index[0] || !pLocalPlayer)
			return false;

		SPELL* tmpSpell = GetSpellByName(Index);

		if (!tmpSpell)
			return false;

		Dest.Set(WillStackWith(pSpell, tmpSpell));
		return true;
	}

	case SpellMembers::StacksSpawn:
	{
		if (!Index[0])
			return false;

		int spawnID = GetIntFromString(Index, -1);
		auto pSpawn = spawnID >= 0 ? GetSpawnByID(spawnID) : GetSpawnByName(Index);
		if (!pSpawn)
			return false;

		Dest.Type = pBoolType;
		Dest.Set(!IsSpellTooPowerful(pLocalPlayer, pSpawn, pSpell) && GetCachedBuff(pSpawn, [&pSpell](CachedBuff buff) -> bool {
			auto pBuff = GetSpellByID(buff.spellId);
			return pBuff && !WillStackWith(pSpell, pBuff);
		}) < 0);

		return true;
	}

	case SpellMembers::StacksTarget:
		if (!pTarget)
			return false;

		Dest.Type = pBoolType;
		Dest.Set(!IsSpellTooPowerful(pLocalPlayer, pTarget, pSpell) && GetCachedBuff(pTarget, [&pSpell](CachedBuff buff) -> bool {
			auto pBuff = GetSpellByID(buff.spellId);
			return pBuff && !WillStackWith(pSpell, pBuff);
		}) < 0);

		return true;

	case SpellMembers::MyRange:
	{
		ItemPtr n;
		Dest.Float = pSpell->Range + (float)GetFocusRangeModifier(pSpell, n);
		Dest.Type = pFloatType;
		return true;
	}

	case SpellMembers::Address:
		Dest.DWord = (DWORD)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case SpellMembers::EnduranceCost:
		Dest.DWord = pSpell->EnduranceCost;
		Dest.Type = pIntType;
		return true;

	case SpellMembers::MaxLevel:
		Dest.DWord = GetSpellMax(pSpell, 0);
		Dest.Type = pIntType;
		return true;

	case SpellMembers::Category:
		strcpy_s(DataTypeTemp, "Unknown");
		if (int cat = GetSpellCategory(pSpell))
		{
			if (const char* ptr = pCDBStr->GetString(cat, eSpellCategory))
			{
				strcpy_s(DataTypeTemp, ptr);
			}
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpellMembers::Subcategory:
		strcpy_s(DataTypeTemp, "Unknown");
		if (int cat = GetSpellSubcategory(pSpell))
		{
			if (const char* ptr = pCDBStr->GetString(cat, eSpellCategory))
			{
				strcpy_s(DataTypeTemp, ptr);
			}
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpellMembers::Restrictions:
	{
		Dest.Type = pStringType;
		if (!Index[0])
			return false;

		int nIndex = GetIntFromString(Index, 0) - 1;
		if (nIndex < 0)
			return false;

		memset(DataTypeTemp, 0, sizeof(DataTypeTemp));
		const char* ptr = GetSpellRestrictions(pSpell, nIndex, DataTypeTemp, sizeof(DataTypeTemp));
		if (!ptr)
			strcpy_s(DataTypeTemp, "Unknown");

		Dest.Ptr = &DataTypeTemp[0];
		return true;
	}

	case SpellMembers::Base:
	{
		Dest.Type = pIntType;

		if (!Index[0])
			return false;

		int nIndex = GetIntFromString(Index, 0) - 1;
		if (nIndex < 0)
			return false;

		Dest.Int = GetSpellBase(pSpell, nIndex);

		return true;
	}

	case SpellMembers::Base2:
	{
		Dest.Type = pIntType;

		if (!Index[0])
			return false;

		int nIndex = GetIntFromString(Index, 0) - 1;
		if (nIndex < 0)
			return false;

		Dest.Int = GetSpellBase2(pSpell, nIndex);

		return true;
	}

	case SpellMembers::Max:
	{
		Dest.Type = pIntType;

		if (!Index[0])
			return false;

		int nIndex = GetIntFromString(Index, 0) - 1;
		if (nIndex < 0)
			return false;

		Dest.Int = GetSpellMax(pSpell, nIndex);

		return true;
	}

	case SpellMembers::Calc:
	{
		Dest.Type = pIntType;

		if (!Index[0])
			return false;

		int nIndex = GetIntFromString(Index, 0) - 1;
		if (nIndex < 0)
			return false;

		Dest.Int = GetSpellCalc(pSpell, nIndex);

		return true;
	}

	case SpellMembers::Attrib:
	{
		Dest.Type = pIntType;

		if (!Index[0])
			return false;

		int nIndex = GetIntFromString(Index, 0) - 1;
		if (nIndex < 0)
			return false;

		Dest.Int = GetSpellAttrib(pSpell, nIndex);

		return true;
	}

	case SpellMembers::CalcIndex:
		Dest.Int = pSpell->CalcIndex;
		Dest.Type = pIntType;
		return true;

	case SpellMembers::NumEffects:
		Dest.Int = GetSpellNumEffects(pSpell);
		Dest.Type = pIntType;
		return true;

	case SpellMembers::AutoCast:
		Dest.DWord = pSpell->Autocast;
		Dest.Type = pIntType;
		return true;

	case SpellMembers::Extra:
		strcpy_s(DataTypeTemp, pSpell->Extra);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpellMembers::RecastTimerID:
		Dest.DWord = pSpell->ReuseTimerIndex;
		Dest.Type = pIntType;
		return true;

	case SpellMembers::SPA:
		Dest.DWord = pSpell->spaindex;
		Dest.Type = pIntType;
		return true;

	case SpellMembers::ReagentID:
	{
		Dest.Type = pIntType;

		if (!Index[0])
			return false;

		int nIndex = GetIntFromString(Index, 0) - 1;
		if (nIndex < 0)
			return false;

		Dest.DWord = pSpell->ReagentID[nIndex];

		return true;
	}

	case SpellMembers::NoExpendReagentID:
	{
		Dest.Type = pIntType;

		if (!Index[0])
			return false;

		int nIndex = GetIntFromString(Index, 0) - 1;
		if (nIndex < 0)
			return false;

		Dest.DWord = pSpell->NoExpendReagent[nIndex];

		return true;
	}

	case SpellMembers::ReagentCount:
	{
		Dest.Type = pIntType;

		if (!Index[0])
			return false;

		int nIndex = GetIntFromString(Index, 0) - 1;
		if (nIndex < 0)
			return false;

		Dest.DWord = pSpell->ReagentCount[nIndex];

		return true;
	}

	case SpellMembers::TimeOfDay:
		Dest.DWord = pSpell->TimeOfDay;
		Dest.Type = pIntType;
		return true;

	case SpellMembers::DurationWindow:
		Dest.DWord = pSpell->DurationWindow;
		Dest.Type = pIntType;
		return true;

	case SpellMembers::CanMGB:
		Dest.Set(pSpell->CanMGB);
		Dest.Type = pBoolType;
		return true;

	case SpellMembers::IsSkill:
		Dest.Set(pSpell->IsSkill);
		Dest.Type = pBoolType;
		return true;

	case SpellMembers::Deletable:
		Dest.Set(pSpell->Deletable);
		Dest.Type = pBoolType;
		return true;

	case SpellMembers::BookIcon:
	case SpellMembers::SpellIcon:
	case SpellMembers::GemIcon:
		Dest.DWord = pSpell->SpellIcon;
		Dest.Type = pIntType;
		return true;

	case SpellMembers::ActorTagId:
		Dest.Int = pSpell->ActorTagId;
		Dest.Type = pIntType;
		return true;

	case SpellMembers::Description:
		Dest.Type = pStringType;
		if (const char* ptr = pCDBStr->GetString(pSpell->DescriptionIndex, eSpellDescription))
		{
			strcpy_s(DataTypeTemp, ptr);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case SpellMembers::BaseName:
	{
		strcpy_s(DataTypeTemp, pSpell->Name);

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;

		int SpellRank = pSpell->SpellRank;

		switch (pSpell->SpellRank)
		{
		case 1: // Original
			SpellRank = 1;
			break;
		case 5: // Rk. II
			SpellRank = 2;
			break;
		case 10: // Rk. III
			SpellRank = 3;
			break;
		}

		if (!SpellRank)
			SpellRank = GetSpellRankByName(pSpell->Name);

		if (SpellRank > 1)
			TruncateSpellRankName(DataTypeTemp);

		return true;
	}

	case SpellMembers::Rank:
		// well I haven't checked all spells, but im pretty sure if it's 0 its not a spell a
		// player can scribe/or not intentional, i.e a eq bug, time will tell - eqmule

		Dest.DWord = pSpell->SpellRank;
		Dest.Type = pIntType;

		switch (pSpell->SpellRank)
		{
		case 1: // Original
			Dest.DWord = 1;
			break;
		case 5: // Rk. II
			Dest.DWord = 2;
			break;
		case 10: // Rk. III
			Dest.DWord = 3;
			break;
		}

		if (Dest.DWord == 0)
		{
			// didn't have a rank, lets see if we can get it from the name
			Dest.DWord = GetSpellRankByName(pSpell->Name);
		}

		return true;

	case SpellMembers::RankName:
	{
		Dest.Ptr = pSpell;
		Dest.Type = pSpellType;

		int level = pLocalPlayer ? pLocalPlayer->Level : -1;

		// alt ability
		for (int i = 0; i < NUM_ALT_ABILITIES; ++i)
		{
			auto pAbility = GetAAById(i, level);
			if (!pAbility)
				continue;

			const char* pName = pAbility->GetNameString();
			if (!pName || _strnicmp(pSpell->Name, pName, strlen(pSpell->Name)) || pAbility->SpellID == -1)
				continue;

			auto pFoundSpell = GetSpellByID(pAbility->SpellID);
			if (pFoundSpell && pFoundSpell->SpellGroup == pSpell->SpellGroup)
			{
				Dest.Ptr = pFoundSpell;
				return true;
			}
		}

		// combat ability
		for (int i = 0; i < NUM_COMBAT_ABILITIES; ++i)
		{
			if (!pCombatSkillsSelectWnd || !pCombatSkillsSelectWnd->ShouldDisplayThisSkill(i))
				continue;

			auto pFoundSpell = GetSpellByID(pLocalPC->GetCombatAbility(i));
			if (pFoundSpell && pFoundSpell->SpellGroup == pSpell->SpellGroup &&
				!_strnicmp(pSpell->Name, pFoundSpell->Name, strlen(pSpell->Name)))
			{
				Dest.Ptr = pFoundSpell;
				return true;
			}
		}

		// spell
		auto pPC = GetPcProfile();
		if (!pPC)
			return true; // just return this spell here

		for (int spellID : pPC->SpellBook)
		{
			auto pFoundSpell = GetSpellByID(spellID);
			if (!pFoundSpell)
				continue;

			if (pFoundSpell->ID == pSpell->ID
				|| (pSpell->SpellGroup != 0 && pFoundSpell->SpellGroup == pSpell->SpellGroup
					&& starts_with(pFoundSpell->Name, pSpell->Name)))
			{
				Dest.Ptr = pFoundSpell;
				return true;
			}
		}

		return true;
	}

	case SpellMembers::SpellGroup:
		Dest.DWord = pSpell->SpellGroup;
		Dest.Type = pIntType;
		return true;

	case SpellMembers::SubSpellGroup:
		Dest.DWord = pSpell->SpellSubGroup;
		Dest.Type = pIntType;
		return true;

	case SpellMembers::Beneficial:
		Dest.Set(pSpell->SpellType != 0);
		Dest.Type = pBoolType;
		return true;

	case SpellMembers::IsActiveAA:
		Dest.Set(IsActiveAA(pSpell->Name));
		Dest.Type = pBoolType;
		return true;

	case SpellMembers::Location:
		Dest.DWord = pSpell->ZoneType;
		Dest.Type = pIntType;
		return true;

	case SpellMembers::IsSwarmSpell:
	{
		Dest.Set(false);
		Dest.Type = pBoolType;

		for (int i = 0; i < pSpell->NumEffects; ++i)
		{
			int attrib = GetSpellAttrib(pSpell, i);
			if (attrib == SPA_PET_SWARM || attrib == SPA_DOPPELGANGER)
			{
				Dest.Set(true);
				break;
			}
		}
		return true;
	}

	case SpellMembers::DurationValue1:
		Dest.DWord = pSpell->DurationCap;
		Dest.Type = pIntType;
		return true;

	case SpellMembers::StacksWithDiscs:
		Dest.Set(pSpell->bStacksWithDiscs);
		Dest.Type = pBoolType;
		return true;

	case SpellMembers::IllusionOkWhenMounted:
	{
		Dest.Type = pBoolType;

		if (!pLocalPlayer || !pLocalPC ||
			pSpell->SpellAffects(SPA_CHANGE_FORM) == 0 ||
			!pLocalPC->GetPCSpellAffect(SPA_SUMMON_MOUNT, nullptr))
			return false;

		auto pSpellAffect = pSpell->GetSpellAffectByIndex(pSpell->SpellAffects(SPA_CHANGE_FORM));
		if (!pSpellAffect)
			return false;

		Dest.Set(pLocalPlayer->LegalPlayerRace(pSpellAffect->Base) ||
			pSpellAffect->Base == EQR_SKELETON ||
			pSpellAffect->Base == EQR_SKELETON_NEW ||
			pSpellAffect->Base == EQR_OEQ_SKELETON ||
			pSpellAffect->Base == EQR_SOL_SKELETON);

		return true;
	}

	case SpellMembers::HasSPA:
	{
		if (!Index[0])
			return false;

		int effectIndex = GetIntFromString(Index, -1);
		if (effectIndex < 0)
			return false;

		Dest.Type = pBoolType;
		Dest.Set(IsSPAEffect(pSpell, effectIndex));

		return true;
	}

	case SpellMembers::Trigger:
	{
		Dest.Type = pSpellType;

		int spaFound = GetTriggerSPA(pSpell);
		int autoCast = pSpell->Autocast;
		int index = GetIntFromString(Index, 0) - 1;

		if (spaFound == 0 && autoCast == 0)
			return false;

		if (spaFound == 0 || index < 0 || index >= pSpell->NumEffects)
		{
			Dest.Ptr = GetSpellByID(autoCast);
			return Dest.Ptr != nullptr;
		}

		int base2 = GetSpellBase2(pSpell, index);
		if (base2 == 0)
			return false;

		switch (spaFound)
		{
		case SPA_TRIGGER_BEST_IN_SPELL_GROUP:
		case SPA_CHANCE_BEST_IN_SPELL_GROUP:
			Dest.Ptr = GetHighestLearnedSpellByGroupID(base2);
			return Dest.Ptr != nullptr;
		case SPA_TRIGGER_SPELL:
		case SPA_CHANCE_SPELL:
			Dest.Ptr = GetSpellByID(base2);
			return Dest.Ptr != nullptr;
		default:
			return false;
		}
	}

	case SpellMembers::SlowPct:
		Dest.Int = GetMeleeSpeedPctFromSpell(pSpell, false);
		Dest.Type = pIntType;
		return true;

	case SpellMembers::HastePct:
		Dest.Int = GetMeleeSpeedPctFromSpell(pSpell, true);
		Dest.Type = pIntType;
		return true;

	case SpellMembers::BaseEffectsFocusCap:
		Dest.Type = pIntType;
		Dest.Set(pSpell->BaseEffectsFocusCap);
		return true;
	}

	return false;
}

bool MQ2SpellType::ToString(MQVarPtr VarPtr, char* Destination)
{
	auto pSpell = static_cast<EQ_Spell*>(VarPtr.Ptr);
	if (!pSpell)
		return false;

	strcpy_s(Destination, MAX_STRING, pSpell->Name);
	return true;
}

void MQ2SpellType::InitVariable(MQVarPtr& VarPtr)
{
	// FIXME: Do not allocate a SPELL
	VarPtr.Ptr = new SPELL();
}

void MQ2SpellType::FreeVariable(MQVarPtr& VarPtr)
{
	// FIXME: Do not allocate a SPELL
	SPELL* pSpell = static_cast<SPELL*>(VarPtr.Ptr);
	delete pSpell;
}

bool MQ2SpellType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pSpellType)
		return false;

	memcpy(VarPtr.Ptr, Source.Ptr, sizeof(SPELL));
	return true;
}

bool MQ2SpellType::dataSpell(const char* szIndex, MQTypeVar& Ret)
{
	if (szIndex[0])
	{
		int spellID = GetIntFromString(szIndex, -1);
		if (spellID >= 0)
		{
			if ((Ret.Ptr = GetSpellByID(spellID)))
			{
				Ret.Type = pSpellType;
				return true;
			}
		}
		else
		{
			if (Ret.Ptr = GetSpellByName(szIndex))
			{
				Ret.Type = pSpellType;
				return true;
			}

			//is it an AA?
			if (Ret.Ptr = GetSpellByAAName(szIndex))
			{
				Ret.Type = pSpellType;
				return true;
			}
		}
	}

	return false;
}

} // namespace mq::datatypes
