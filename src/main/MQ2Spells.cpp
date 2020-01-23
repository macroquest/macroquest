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
#include "MQ2Main.h"

namespace mq {

struct case_insensitive_comparer
{
	bool operator () (std::string_view a, std::string_view b) const
	{
		return ci_equals(a, b);
	}
};

struct case_insensitive_hasher
{
	unsigned long operator () (std::string_view a) const
	{
		// this is a re-implementation of the fnv1a hash that MSVC uses, but with tolower
		unsigned long hash = 2166136261U;
		for (unsigned char c : a)
		{
			hash ^= static_cast<unsigned long>(::tolower(c));
			hash *= 16777619U;
		}
		return hash;
	}
};

std::unordered_multimap<std::string_view, EQ_Spell*, case_insensitive_hasher, case_insensitive_comparer> s_spellNameMap;
std::map<int, int> s_triggeredSpells;
std::recursive_mutex s_initializeSpellsMutex;

EQ_Spell* GetHighestLearnedSpellByGroupID(int dwSpellGroupID)
{
	PcProfile* pProfile = GetPcProfile();
	if (!pProfile) return nullptr;

	EQ_Spell* result = nullptr;

	for (int nSpell : pProfile->SpellBook)
	{
		auto pFoundSpell = GetSpellByID(nSpell);
		if (!pFoundSpell || pFoundSpell->SpellGroup != dwSpellGroupID)
			continue;

		// Find the highest rank of the spell that matches this spell group
		if (!result || result->SpellRank < pFoundSpell->SpellRank)
			result = pFoundSpell;
	}

	return result;
}

const char* GetSpellNameBySpellGroupID(int dwSpellID)
{
	auto pSpell = GetHighestLearnedSpellByGroupID(dwSpellID);

	if (pSpell && pSpell->Name && pSpell->Name[0] != 0)
		return pSpell->Name;

	return "Unknown Spell";
}

const char* GetSpellNameByID(int dwSpellID)
{
	auto pSpell = GetSpellByID(dwSpellID);

	if (pSpell && pSpell->Name && pSpell->Name[0] != 0)
		return pSpell->Name;

	return "Unknown Spell";
}

static bool IsRecursiveEffect(int spa)
{
	switch (spa)
	{
	case SPA_CHANCE_SPELL:
	case SPA_CHANCE_BEST_IN_SPELL_GROUP:
	case SPA_TRIGGER_SPELL:
	case SPA_TRIGGER_SPELL_NON_ITEM:
	case SPA_TRIGGER_BEST_IN_SPELL_GROUP:
		return true;
	}

	return false;
}

static void PopulateTriggeredmap(EQ_Spell* pSpell)
{
	if (!pSpell || pSpell->CannotBeScribed)
		return;

	for (int i = 0; i < pSpell->NumEffects; i++)
	{
		if (!IsRecursiveEffect(GetSpellAttrib(pSpell, i)))
			continue;
		
		int triggeredSpellID = GetSpellBase2(pSpell, i);
		if (i > 0)
			s_triggeredSpells[triggeredSpellID] = pSpell->ID;
	}
}

EQ_Spell* GetSpellParent(int id)
{
	auto iter = s_triggeredSpells.find(id);
	if (iter != s_triggeredSpells.end())
		return GetSpellByID(iter->second);

	return nullptr;
}

void PopulateSpellMap()
{
	std::scoped_lock lock(s_initializeSpellsMutex);

	gbSpelldbLoaded = false;

	s_triggeredSpells.clear();
	s_spellNameMap.clear();

	for (auto pSpell : pSpellMgr->Spells)
	{
		if (!pSpell || !pSpell->Name[0])
			continue;

		PopulateTriggeredmap(pSpell);

		s_spellNameMap.emplace(pSpell->Name, pSpell);
	}

	gbSpelldbLoaded = true;
}

DWORD CALLBACK InitializeMQ2SpellDb(void* pData)
{
	int state = reinterpret_cast<int>(pData);

	bmSpellLoad = AddMQ2Benchmark("SpellLoad");
	bmSpellAccess = AddMQ2Benchmark("SpellAccess");

	switch (state)
	{
	case 1: WriteChatf("Initializing SpellMap from SetGameState."); break;
	case 2: WriteChatf("Initializing SpellMap from GetSpellByName."); break;
	default: WriteChatf("Initializing SpellMap. (%d)", state); break;
	}

	while (gGameState != GAMESTATE_CHARSELECT && gGameState != GAMESTATE_INGAME)
	{
		Sleep(10);
	}

	while (pSpellMgr && (!pSpellMgr->Spells || (pSpellMgr->Spells && !pSpellMgr->Spells[TOTAL_SPELL_COUNT - 1])))
	{
		Sleep(10);
	}

	// ok everything checks out lets fill our own map with spells
	Benchmark(bmSpellLoad, PopulateSpellMap());

	switch (state)
	{
	case 1: WriteChatf("SpellMap Initialized from SetGameState."); break;
	case 2: WriteChatf("SpellMap Initialized from GetSpellByName."); break;
	default: WriteChatf("SpellMap Initialized. (%d)", state); break;
	}

	ghInitializeSpellDbThread = nullptr;
	return 0;
}

bool IsSpellClassUsable(SPELL* pSpell)
{
	for (int index = Warrior; index <= Berserker; index++)
	{
		if (pSpell->ClassLevel[index] == 255 || pSpell->ClassLevel[index] == 127)
		{
			continue;
		}

		return true;
	}

	return false;
}

EQ_Spell* GetSpellFromMap(const char* szName)
{
	auto profile = GetPcProfile();
	if (!profile)
		return nullptr;

	auto range = s_spellNameMap.equal_range(szName);

	if (IsPlayerClass(profile->Class))
	{
		auto compare = [profile](int level, std::pair<std::string_view, EQ_Spell*> spell) -> bool {
			return level < spell.second->ClassLevel[profile->Class];
		};

		auto it = std::upper_bound(range.first, range.second, profile->Level, compare);
		if (it != range.first)
			return (--it)->second;

		// otherwise, I can't have this spell
	}

	// if we got here, the spell the user is after isnt one his character can cast, so
	// we will have to roll through it again and see if its usable by any other class
	auto is_usable = [](std::pair<std::string_view, EQ_Spell*> spell) -> bool {
		return IsSpellClassUsable(spell.second);
	};

	auto it = std::find_if(range.first, range.second, is_usable);
	if (it != range.second)
		return it->second;

	return nullptr;
}

SPELL* GetSpellByName(const char* szName)
{
	// SPELL* GetSpellByName(char* NameOrID)
	// This function now accepts SpellID as an argument as well as SpellName
	// /echo ${Spell[Concussive Burst].Level}
	// /echo ${Spell[Nature's Serenity].Level}

	if (!pSpellMgr) // no spellMgr?
		return nullptr;

	if (!szName[0])    // no spell name?
		return nullptr;

	if (gbSpelldbLoaded == false)
	{
		InitializeMQ2SpellDb((void*)2);

		if (gbSpelldbLoaded == false)
		{
			return nullptr;
		}
	}

	std::scoped_lock lock(s_initializeSpellsMutex);
	if (s_spellNameMap.empty())
		return nullptr;

	if (IsNumber(szName))
		return GetSpellByID(GetIntFromString(szName, -1));

	EnterMQ2Benchmark(bmSpellAccess);
	auto pSpell = GetSpellFromMap(szName);
	ExitMQ2Benchmark(bmSpellAccess);

	return pSpell;
}

int GetSpellDuration(SPELL* pSpell, SPAWNINFO* pSpawn)
{
	switch (pSpell->DurationType)
	{
	case 0:
		return 0;
	case 1:
	case 6:
		return std::min<unsigned int>((unsigned int)ceil(double(pSpawn->Level) / 2), pSpell->DurationCap);
	case 3:
	case 4:
	case 11:
	case 12:
	case 15:
		if (pSpell->DurationCap) {
			return (pSpell->DurationCap);
		}
		else {
			return (pSpell->DurationType * 10);
		}
	case 2:
		return std::min<unsigned int>((unsigned int)ceil(double(pSpawn->Level) * 0.6), pSpell->DurationCap);
	case 5:
		return 3;
	case 7:
		return std::min<unsigned int>(pSpawn->Level, pSpell->DurationCap ? pSpell->DurationCap : pSpawn->Level);
	case 8:
		return std::min<unsigned int>(pSpawn->Level + 10, pSpell->DurationCap);
	case 9:
		return std::min<unsigned int>(pSpawn->Level * 2 + 10, pSpell->DurationCap);
	case 10:
		return std::min<unsigned int>(pSpawn->Level * 3 + 10, pSpell->DurationCap);
	case 13:
		return pSpell->DurationCap * 6 / 10;
	case 50:
		return -1;
	case 3600:
		return 6000;
	default:
		return -2;
	}
}



// ***************************************************************************
// Function:    IsBardSong
// Description: Return true if the spell is a bard song
// ***************************************************************************
bool IsBardSong(SPELL* pSpell)
{
	return (((EQ_Spell*)pSpell)->GetSpellLevelNeeded(Bard) <= MAX_PC_LEVEL)
		&& !pSpell->DurationWindow;
}

// ***************************************************************************
// Function:    IsSPAEffect
// Description: Return true if the spell contains the SPAEffect
// ***************************************************************************
bool IsSPAEffect(SPELL* pSpell, int EffectID)
{
	for (int slot = 0; slot < GetSpellNumEffects(pSpell); slot++)
	{
		if (GetSpellAttrib(pSpell, slot) == EffectID)
			return true;
	}

	return false;
}

// ***************************************************************************
// Function:    GetClassesFromMask
// Description: Return a comma delimited list of player short class names
//              If ALL classes are in the mask it will return "ALL",
//              if 4 or less are missing it will return "ALL EXCEPT: " and the
//              comma delimited list of play short class names that are excluded
// ***************************************************************************
template <unsigned int Size>
char* GetClassesFromMask(int mask, char(&szBuffer)[Size])
{
	int matching = 0;
	int excluding = 0;
	int numofclasses = Berserker;

	for (int playerclass = Warrior; playerclass <= Berserker; playerclass++)
	{
		if (mask & (1 << playerclass)) {
			matching++;
		}
		else {
			excluding++;
		}
	}

	if (matching == numofclasses)
	{
		strcat_s(szBuffer, "ALL");
	}
	else if (excluding <= 4)
	{
		strcat_s(szBuffer, "ALL EXCEPT: ");

		for (int playerclass = Warrior; playerclass <= Berserker; playerclass++)
		{
			if (!(mask & (1 << playerclass)))
			{
				if (strlen(szBuffer) > 12)
					strcat_s(szBuffer, ",");
				strcat_s(szBuffer, ClassInfo[playerclass].UCShortName);
			}
		}
	}
	else
	{
		for (int playerclass = Warrior; playerclass <= Berserker; playerclass++)
		{
			if (mask & (1 << playerclass))
			{
				if (strlen(szBuffer) > 0)
					strcat_s(szBuffer, ",");
				strcat_s(szBuffer, ClassInfo[playerclass].UCShortName);
			}
		}
	}
	return szBuffer;
}

// ***************************************************************************
// Function:    GetSpellRestrictions
// Description: Return the restrictions for the spell slot
// ***************************************************************************
char* GetSpellRestrictions(SPELL* pSpell, unsigned int nIndex, char* szBuffer, size_t BufferSize)
{
	if (!szBuffer)
		return nullptr;

	if (!pSpell)
	{
		szBuffer[0] = '\0';
		return szBuffer;
	}

	switch (GetSpellBase2(pSpell, nIndex))
	{
	case 0:	strcat_s(szBuffer, BufferSize, "None"); break;
	case 100: strcat_s(szBuffer, BufferSize, "Only works on Animal or Humanoid"); break;
	case 101: strcat_s(szBuffer, BufferSize, "Only works on Dragon"); break;
	case 102: strcat_s(szBuffer, BufferSize, "Only works on Animal or Insect"); break;
	case 104: strcat_s(szBuffer, BufferSize, "Only works on Animal"); break;
	case 105: strcat_s(szBuffer, BufferSize, "Only works on Plant"); break;
	case 106: strcat_s(szBuffer, BufferSize, "Only works on Giant"); break;
	case 108: strcat_s(szBuffer, BufferSize, "Doesn't work on Animals or Humanoids"); break;
	case 109: strcat_s(szBuffer, BufferSize, "Only works on Bixie"); break;
	case 110: strcat_s(szBuffer, BufferSize, "Only works on Harpy"); break;
	case 111: strcat_s(szBuffer, BufferSize, "Only works on Gnoll"); break;
	case 112: strcat_s(szBuffer, BufferSize, "Only works on Sporali"); break;
	case 113: strcat_s(szBuffer, BufferSize, "Only works on Kobold"); break;
	case 114: strcat_s(szBuffer, BufferSize, "Only works on Shade"); break;
	case 115: strcat_s(szBuffer, BufferSize, "Only works on Drakkin"); break;
	case 117: strcat_s(szBuffer, BufferSize, "Only works on Animals or Plants"); break;
	case 118: strcat_s(szBuffer, BufferSize, "Only works on Summoned"); break;
	case 119: strcat_s(szBuffer, BufferSize, "Only works on Fire_Pet"); break;
	case 120: strcat_s(szBuffer, BufferSize, "Only works on Undead"); break;
	case 121: strcat_s(szBuffer, BufferSize, "Only works on Living"); break;
	case 122: strcat_s(szBuffer, BufferSize, "Only works on Fairy"); break;
	case 123: strcat_s(szBuffer, BufferSize, "Only works on Humanoid"); break;
	case 124: strcat_s(szBuffer, BufferSize, "Undead HP Less Than 10%"); break;
	case 125: strcat_s(szBuffer, BufferSize, "Clockwork HP Less Than 45%"); break;
	case 126: strcat_s(szBuffer, BufferSize, "Wisp HP Less Than 10%"); break;
	case 190: strcat_s(szBuffer, BufferSize, "Doesn't work on Raid Bosses"); break;
	case 191: strcat_s(szBuffer, BufferSize, "Only works on Raid Bosses"); break;
	case 201: strcat_s(szBuffer, BufferSize, "HP Above 75%"); break;
	case 203: strcat_s(szBuffer, BufferSize, "HP Less Than 20%"); break;
	case 204: strcat_s(szBuffer, BufferSize, "HP Less Than 50%"); break;
	case 216: strcat_s(szBuffer, BufferSize, "Not In Combat"); break;
	case 221: strcat_s(szBuffer, BufferSize, "At Least 1 Pet On Hatelist"); break;
	case 222: strcat_s(szBuffer, BufferSize, "At Least 2 Pets On Hatelist"); break;
	case 223: strcat_s(szBuffer, BufferSize, "At Least 3 Pets On Hatelist"); break;
	case 224: strcat_s(szBuffer, BufferSize, "At Least 4 Pets On Hatelist"); break;
	case 225: strcat_s(szBuffer, BufferSize, "At Least 5 Pets On Hatelist"); break;
	case 226: strcat_s(szBuffer, BufferSize, "At Least 6 Pets On Hatelist"); break;
	case 227: strcat_s(szBuffer, BufferSize, "At Least 7 Pets On Hatelist"); break;
	case 228: strcat_s(szBuffer, BufferSize, "At Least 8 Pets On Hatelist"); break;
	case 229: strcat_s(szBuffer, BufferSize, "At Least 9 Pets On Hatelist"); break;
	case 230: strcat_s(szBuffer, BufferSize, "At Least 10 Pets On Hatelist"); break;
	case 231: strcat_s(szBuffer, BufferSize, "At Least 11 Pets On Hatelist"); break;
	case 232: strcat_s(szBuffer, BufferSize, "At Least 12 Pets On Hatelist"); break;
	case 233: strcat_s(szBuffer, BufferSize, "At Least 13 Pets On Hatelist"); break;
	case 234: strcat_s(szBuffer, BufferSize, "At Least 14 Pets On Hatelist"); break;
	case 235: strcat_s(szBuffer, BufferSize, "At Least 15 Pets On Hatelist"); break;
	case 236: strcat_s(szBuffer, BufferSize, "At Least 16 Pets On Hatelist"); break;
	case 237: strcat_s(szBuffer, BufferSize, "At Least 17 Pets On Hatelist"); break;
	case 238: strcat_s(szBuffer, BufferSize, "At Least 18 Pets On Hatelist"); break;
	case 239: strcat_s(szBuffer, BufferSize, "At Least 19 Pets On Hatelist"); break;
	case 240: strcat_s(szBuffer, BufferSize, "At Least 20 Pets On Hatelist"); break;
	case 250: strcat_s(szBuffer, BufferSize, "HP Less Than 35%"); break;
	case 304: strcat_s(szBuffer, BufferSize, "Chain Plate Classes"); break;
	case 399: strcat_s(szBuffer, BufferSize, "HP Between 15 and 25%"); break;
	case 400: strcat_s(szBuffer, BufferSize, "HP Between 1 and 25%"); break;
	case 401: strcat_s(szBuffer, BufferSize, "HP Between 25 and 35%"); break;
	case 402: strcat_s(szBuffer, BufferSize, "HP Between 35 and 45%"); break;
	case 403: strcat_s(szBuffer, BufferSize, "HP Between 45 and 55%"); break;
	case 404: strcat_s(szBuffer, BufferSize, "HP Between 55 and 65%"); break;
	case 412: strcat_s(szBuffer, BufferSize, "HP Above 99%"); break;
	case 501: strcat_s(szBuffer, BufferSize, "HP Below 5%"); break;
	case 502: strcat_s(szBuffer, BufferSize, "HP Below 10%"); break;
	case 503: strcat_s(szBuffer, BufferSize, "HP Below 15%"); break;
	case 504: strcat_s(szBuffer, BufferSize, "HP Below 20%"); break;
	case 505: strcat_s(szBuffer, BufferSize, "HP Below 25%"); break;
	case 506: strcat_s(szBuffer, BufferSize, "HP Below 30%"); break;
	case 507: strcat_s(szBuffer, BufferSize, "HP Below 35%"); break;
	case 508: strcat_s(szBuffer, BufferSize, "HP Below 40%"); break;
	case 509: strcat_s(szBuffer, BufferSize, "HP Below 45%"); break;
	case 510: strcat_s(szBuffer, BufferSize, "HP Below 50%"); break;
	case 511: strcat_s(szBuffer, BufferSize, "HP Below 55%"); break;
	case 512: strcat_s(szBuffer, BufferSize, "HP Below 60%"); break;
	case 513: strcat_s(szBuffer, BufferSize, "HP Below 65%"); break;
	case 514: strcat_s(szBuffer, BufferSize, "HP Below 70%"); break;
	case 515: strcat_s(szBuffer, BufferSize, "HP Below 75%"); break;
	case 516: strcat_s(szBuffer, BufferSize, "HP Below 80%"); break;
	case 517: strcat_s(szBuffer, BufferSize, "HP Below 85%"); break;
	case 518: strcat_s(szBuffer, BufferSize, "HP Below 90%"); break;
	case 519: strcat_s(szBuffer, BufferSize, "HP Below 95%"); break;
	case 521: strcat_s(szBuffer, BufferSize, "Mana Below X%"); break;
	case 522: strcat_s(szBuffer, BufferSize, "End Below 40%"); break;
	case 523: strcat_s(szBuffer, BufferSize, "Mana Below 40%"); break;
	case 603: strcat_s(szBuffer, BufferSize, "Only works on Undead2"); break;
	case 608: strcat_s(szBuffer, BufferSize, "Only works on Undead3"); break;
	case 624: strcat_s(szBuffer, BufferSize, "Only works on Summoned2"); break;
	case 701: strcat_s(szBuffer, BufferSize, "Doesn't work on Pets"); break;
	case 818: strcat_s(szBuffer, BufferSize, "Only works on Undead4"); break;
	case 819: strcat_s(szBuffer, BufferSize, "Doesn't work on Undead4"); break;
	case 825: strcat_s(szBuffer, BufferSize, "End Below 21%"); break;
	case 826: strcat_s(szBuffer, BufferSize, "End Below 25%"); break;
	case 827: strcat_s(szBuffer, BufferSize, "End Below 29%"); break;
	case 836: strcat_s(szBuffer, BufferSize, "Only works on Regular Servers"); break;
	case 837: strcat_s(szBuffer, BufferSize, "Doesn't work on Progression Servers"); break;
	case 842: strcat_s(szBuffer, BufferSize, "Only works on Humanoid Level 84 Max"); break;
	case 843: strcat_s(szBuffer, BufferSize, "Only works on Humanoid Level 86 Max"); break;
	case 844: strcat_s(szBuffer, BufferSize, "Only works on Humanoid Level 88 Max"); break;
	case 1000: strcat_s(szBuffer, BufferSize, "Between Level 1 and 75"); break;
	case 1001: strcat_s(szBuffer, BufferSize, "Between Level 76 and 85"); break;
	case 1002: strcat_s(szBuffer, BufferSize, "Between Level 86 and 95"); break;
	case 1003: strcat_s(szBuffer, BufferSize, "Between Level 96 and 100"); break;
	case 1004: strcat_s(szBuffer, BufferSize, "HP Less Than 80%"); break;
	case 38311: strcat_s(szBuffer, BufferSize, "Mana Below 20%"); break;
	case 38312: strcat_s(szBuffer, BufferSize, "Mana Below 10%"); break;
	default: {
		char szTemp[MAX_STRING] = { 0 };
		sprintf_s(szTemp, "Unknown[%d]", GetSpellBase2(pSpell, nIndex));
		strcat_s(szBuffer, BufferSize, szTemp); break;
	}
	}
	return szBuffer;
}

// ***************************************************************************
// Function:    GetSpellEffectName, GetSpellEffectNameByID
// Description: Return spell effect string
// ***************************************************************************
char* GetSpellEffectNameByID(int EffectID, char* szBuffer, size_t BufferSize)
{
	return GetSpellEffectName(abs(EffectID), szBuffer, BufferSize);
}

char* GetSpellEffectName(int EffectID, char* szBuffer, size_t BufferSize)
{
	// we CAN do an abs here cause IF it is negative, it just means we should display is as "Exclude: "
	int absEffectID = abs(EffectID);

	if ((size_t)absEffectID < MAX_SPELLEFFECTS)
	{
		strcat_s(szBuffer, BufferSize, szSPATypes[absEffectID]);
	}
	else
	{
		char szTemp[MAX_STRING] = { 0 };
		sprintf_s(szTemp, "Unknown SPA[%03d]", absEffectID);
		strcat_s(szBuffer, BufferSize, szTemp);
	}

	return szBuffer;
}

template <unsigned int Size>
static char* GetResistTypeName(int ResistType, char(&szBuffer)[Size])
{
	char szTemp[32] = { 0 };
	switch (ResistType)
	{
	case ResistType_Magic: strcat_s(szBuffer, "Magic"); break;
	case ResistType_Fire: strcat_s(szBuffer, "Fire"); break;
	case ResistType_Cold: strcat_s(szBuffer, "Cold/Ice"); break;
	case ResistType_Poison: strcat_s(szBuffer, "Poison"); break;
	case ResistType_Disease: strcat_s(szBuffer, "Disease"); break;
	case ResistType_Chromatic: strcat_s(szBuffer, "Chromatic"); break;
	case ResistType_Prismatic: strcat_s(szBuffer, "Prismatic"); break;
	case ResistType_Physical: strcat_s(szBuffer, "Physical"); break;
	case ResistType_Corruption: strcat_s(szBuffer, "Corruption"); break;
	default:
		sprintf_s(szTemp, "Unknown[%d]", ResistType);
		strcat_s(szBuffer, szTemp); break;
	}
	return szBuffer;
}

template <unsigned int Size>
static char* GetSpellTypeName(int SpellType, char(&szBuffer)[Size])
{
	char szTemp[32] = { 0 };
	switch (SpellType)
	{
	case SpellType_Detrimental: strcat_s(szBuffer, "Detrimental only"); break;
	case SpellType_Beneficial: strcat_s(szBuffer, "Beneficial only"); break;
	case SpellType_BeneficialGroupOnly: strcat_s(szBuffer, "Beneficial - Group Only"); break;
	default:
		sprintf_s(szTemp, "Unknown[%d]", SpellType);
		strcat_s(szBuffer, szTemp); break;
	}
	return szBuffer;
}


template <unsigned int Size>
static char* GetTargetTypeLimitsName(int TargetLimitsType, char(&szBuffer)[Size])
{
	char szTemp[64] = { 0 };
	switch (abs(TargetLimitsType))
	{
	case 50: strcat_s(szBuffer, "Target AE No Players Pets"); break; // blanket of forgetfullness. beneficial, AE mem blur, with max targets
	case 52: strcpy_s(szBuffer, "Single Friendly (or Target's Target"); break; // Introduced in Torment of Velious. Spell affects target if friendly, or target's target if the target is an unfriendly.
	case 47: strcat_s(szBuffer, "Pet Owner"); break;
	case 46: strcat_s(szBuffer, "Target of Target"); break;
	case 45: strcat_s(szBuffer, "Free Target"); break;
	case 44: strcat_s(szBuffer, "Beam"); break;
	case 43: strcat_s(szBuffer, "Single in Group"); break;
	case 42: strcat_s(szBuffer, "Directional AE"); break;
	case 39: strcat_s(szBuffer, "No Pets"); break;
	case 38: strcat_s(szBuffer, "Pet2"); break;
	case 37: strcat_s(szBuffer, "Caster PB NPC"); break;
	case 36: strcat_s(szBuffer, "Caster PB PC"); break;
	case 35: strcat_s(szBuffer, "Special Muramites"); break;
	case 34: strcat_s(szBuffer, "Chest"); break;
	case 33: strcat_s(szBuffer, "Hatelist2"); break;
	case 32: strcat_s(szBuffer, "Hatelist"); break;
	case 41: strcat_s(szBuffer, "Group v2"); break;
	case 40: strcat_s(szBuffer, "AE PC v2"); break;
	case 25: strcat_s(szBuffer, "AE Summoned"); break;
	case 24: strcat_s(szBuffer, "AE Undead"); break;
	case 20: strcat_s(szBuffer, "Targeted AE Tap"); break;
	case 18: strcat_s(szBuffer, "Uber Dragons"); break;
	case 17: strcat_s(szBuffer, "Uber Giants"); break;
	case 16: strcat_s(szBuffer, "Plant"); break;
	case 15: strcat_s(szBuffer, "Corpse"); break;
	case 14: strcat_s(szBuffer, "Pet"); break;
	case 13: strcat_s(szBuffer, "LifeTap"); break;
	case 11: strcat_s(szBuffer, "Summoned"); break;
	case 10: strcat_s(szBuffer, "Undead"); break;
	case 9: strcat_s(szBuffer, "Animal"); break;
	case 8: strcat_s(szBuffer, "Targeted AE"); break;
	case 6: strcat_s(szBuffer, "Self"); break;
	case 5: strcat_s(szBuffer, "Single"); break;
	case 4: strcat_s(szBuffer, "PB AE"); break;
	case 3: strcat_s(szBuffer, "Group v1"); break;
	case 2: strcat_s(szBuffer, "AE PC v1"); break;
	case 1: strcat_s(szBuffer, "Line of Sight"); break;
	default:
		sprintf_s(szTemp, "Unknown[%d]", abs(TargetLimitsType));
		strcat_s(szBuffer, szTemp); break;
	}
	return szBuffer;
}

template <unsigned int Size>
static char* GetStatShortName(int StatType, char(&szBuffer)[Size])
{
	char szTemp[32] = { 0 };
	switch (StatType)
	{
	case 0: strcat_s(szBuffer, "STR"); break;
	case 1: strcat_s(szBuffer, "STA"); break;
	case 2: strcat_s(szBuffer, "AGI"); break;
	case 3: strcat_s(szBuffer, "DEX"); break;
	case 4: strcat_s(szBuffer, "WIS"); break;
	case 5: strcat_s(szBuffer, "INT"); break;
	case 6: strcat_s(szBuffer, "CHA"); break;
	case 7: strcat_s(szBuffer, "MR"); break;
	case 8: strcat_s(szBuffer, "CR"); break;
	case 9: strcat_s(szBuffer, "FR"); break;
	case 10: strcat_s(szBuffer, "PR"); break;  // either PR or DR
	case 11: strcat_s(szBuffer, "DR"); break;  // either DR or PR
	default:
		sprintf_s(szTemp, "Unknown[%d]", StatType);
		strcat_s(szBuffer, szTemp); break;
	}
	return szBuffer;
}

template <unsigned int Size>
static char* GetFactionName(int FactionID, char(&szBuffer)[Size])
{
	if ((size_t)FactionID < MAX_FACTIONNAMES)
	{
		strcat_s(szBuffer, Size, szFactionNames[FactionID]);
	}
	else
	{
		char szTemp[MAX_STRING] = { 0 };
		sprintf_s(szTemp, "Unknown Faction[%d]", FactionID);
		strcat_s(szBuffer, Size, szTemp);
	}

	return szBuffer;
}

// See also: GetSpellDuration
static int CalcDuration(int calc, int max, int level)
{
	int value = 0;

	switch (calc)
	{
	case 0:  value = 0; break;
	case 1:
	case 12:
		value = level / 2;
		if (value < 1)
			value = 1;
		break;
	case 2:
		value = (level / 2) + 5;
		if (value < 6)
			value = 6;
		break;
	case 3:  value = level * 30; break;
	case 4:  value = 50; break;
	case 5:  value = 2; break;
	case 6:  value = level / 2; break;
	case 7:  value = level; break;
	case 8:  value = level + 10; break;
	case 9:  value = level * 2 + 10; break;
	case 10: value = level * 30 + 10; break;
	case 11: value = (level + 3) * 30; break;
	case 13: value = level * 3 + 10; break;
	case 14: value = (level + 2) * 5; break;
	case 15: value = (level + 10) * 10; break;
	case 50: value = 72000; break;
	case 3600: value = 3600; break;
	default: value = max;
	}

	if (max > 0 && value > max)
		value = max;

	return value;
}

int CalcValue(int calc, int base, int max, int tick, int minlevel, int level)
{
	if (calc == 0)
		return base;

	if (calc == 100)
	{
		if (max > 0 && ((base > max) || (level > minlevel)))
			return max;
		return base;
	}

	int change = 0;
	int adjustment = 0;

	switch (calc)
	{
	case 100:
		break;
	case 101:
		change = level / 2;
		break;
	case 102:
		change = level;
		break;
	case 103:
		change = level * 2;
		break;
	case 104:
		change = level * 3;
		break;
	case 105:
		change = level * 4;
		break;
	case 106:
		change = level * 5;
		break;
	case 107:
		change = -1 * tick;
		break;
	case 108:
		change = -2 * tick;
		break;
	case 109:
		change = level / 4;
		break;
	case 110:
		change = level / 6;
		break;
	case 111:
		//if (level < 16) adjustment = (level - 16) * 6;
		if (level > 16) change = (level - 16) * 6;
		break;
	case 112:
		//if (level < 24) adjustment = (level - 24) * 8;
		if (level > 24) change = (level - 24) * 8;
		break;
	case 113:
		//if (level < 34) adjustment = (level - 34) * 10;
		if (level > 34) change = (level - 34) * 10;
		break;
	case 114:
		//if (level < 44) adjustment = (level - 44) * 15;
		if (level > 44) change = (level - 44) * 15;
		break;
	case 115:
		//if (level < 15) adjustment = (level - 15) * 7;
		if (level > 15) change = (level - 15) * 7;
		break;
	case 116:
		//if (level < 24) adjustment = (level - 24) * 10;
		if (level > 24) change = (level - 24) * 10;
		break;
	case 117:
		//if (level < 34) adjustment = (level - 34) * 13;
		if (level > 34) change = (level - 34) * 13;
		break;
	case 118:
		//if (level < 44) adjustment = (level - 44) * 20;
		if (level > 44) change = (level - 44) * 20;
		break;
	case 119:
		change = level / 8;
		break;
	case 120:
		change = -5 * tick;
		break;
	case 121:
		change = level / 3;
		break;
	case 122:
		change = -12 * tick;
		break;
	case 123: // random in range
		if (tick > 1) change = abs(max) - abs(base);
		//change = (abs(max) - abs(base)) / 2;
		break;
	case 124:
		//if (level < 50) adjustment = (level - 50);
		if (level > 50) change = (level - 50);
		break;
	case 125:
		//if (level < 50) adjustment = (level - 50) * 2;
		if (level > 50) change = (level - 50) * 2;
		break;
	case 126:
		//if (level < 50) adjustment = (level - 50) * 3;
		if (level > 50) change = (level - 50) * 3;
		break;
	case 127:
		//if (level < 50) adjustment = (level - 50) * 4;
		if (level > 50) change = (level - 50) * 4;
		break;
	case 128:
		//if (level < 50) adjustment = (level - 50) * 5;
		if (level > 50) change = (level - 50) * 5;
		break;
	case 129:
		//if (level < 50) adjustment = (level - 50) * 10;
		if (level > 50) change = (level - 50) * 10;
		break;
	case 130:
		//if (level < 50) adjustment = (level - 50) * 15;
		if (level > 50) change = (level - 50) * 15;
		break;
	case 131:
		//if (level < 50) adjustment = (level - 50) * 20;
		if (level > 50) change = (level - 50) * 20;
		break;
	case 132:
		//if (level < 50) adjustment = (level - 50) * 25;
		if (level > 50) change = (level - 50) * 25;
		break;
	case 139:
		//if (level < 30) adjustment = (level - 30) / 2;
		if (level > 30) change = (level - 30) / 2;
		break;
	case 140:
		//if (level < 30) adjustment = (level - 30);
		if (level > 30) change = (level - 30);
		break;
	case 141:
		//if (level < 30) adjustment = 3 * (level - 30) / 2;
		if (level > 30) change = 3 * (level - 30) / 2;
		break;
	case 142:
		//if (level < 30) adjustment = 2 * (level - 30);
		if (level > 30) change = 2 * (level - 30);
		break;
	case 143:
		change = 3 * level / 4;
		break;
	case 3000:
		return base;
	default:
		if (calc > 0 && calc < 1000)
			change = level * calc;
		if (calc >= 1000 && calc < 2000)
			change = tick * (calc - 1000) * -1;
		if (calc >= 2000)
			change = level * (calc - 2000);
	}

	int value = abs(base) + adjustment + change;

	if (max != 0 && value > abs(max))
		value = abs(max);

	if (base < 0)
		value = -value;

	return value;
}

static int CalcMaxSpellLevel(int calc, int base, int max, int tick, int minlevel, int level)
{
	if (abs(max) > 0)
	{
		for (int maxlevel = 1; maxlevel <= level; maxlevel++)
		{
			int value = CalcValue(calc, base, max, tick, minlevel, maxlevel);

			if (abs(CalcValue(calc, base, max, tick, minlevel, maxlevel)) >= abs(max))
				return maxlevel;
		}

		return level;
	}

	return MAX_PC_LEVEL;
}

static int CalcMinSpellLevel(SPELL* pSpell)
{
	int minspelllvl = ((EQ_Spell*)pSpell)->GetSpellLevelNeeded(Warrior);

	for (int j = Warrior; j <= Berserker; j++)
	{
		if (((EQ_Spell*)pSpell)->GetSpellLevelNeeded(j) < minspelllvl)
			minspelllvl = ((EQ_Spell*)pSpell)->GetSpellLevelNeeded(j);
	}

	if (minspelllvl > MAX_PC_LEVEL)
		minspelllvl = 1;

	return minspelllvl;
}

static char* CalcValueRange(int calc, int base, int max, int duration, int minlevel, int level, char* szBuffer, size_t BufferSize, char* szPercent)
{
	int start = CalcValue(calc, base, max, 1, minlevel, minlevel);
	int finish = CalcValue(calc, base, max, duration, minlevel, level);
	char type[MAX_STRING] = { 0 };

	sprintf_s(type, "%s", abs(start) < abs(finish) ? "Growing" : "Decaying");

	switch (calc)
	{
	case SpellValueRangeCalc_DecayTick1:
		sprintf_s(szBuffer, BufferSize, " (%s to %d @ 1/tick)", type, finish);
		break;
	case SpellValueRangeCalc_DecayTick2:
		sprintf_s(szBuffer, BufferSize, " (%s to %d @ 2/tick)", type, finish);
		break;
	case SpellValueRangeCalc_DecayTick5:
		sprintf_s(szBuffer, BufferSize, " (%s to %d @ 5/tick)", type, finish);
		break;
	case SpellValueRangeCalc_DecayTick12:
		sprintf_s(szBuffer, BufferSize, " (%s to %d @ 12/tick)", type, finish);
		break;
	case SpellValueRangeCalc_Random:
		sprintf_s(szBuffer, BufferSize, " (Random: %d to %d)", start, finish* ((start >= 0) ? 1 : -1));
		break;
	default:
		if (calc > 0 && calc < 1000)
			sprintf_s(szBuffer, BufferSize, " to %d%s", start, szPercent);
		if (calc >= 1000 && calc < 2000)
			sprintf_s(szBuffer, BufferSize, " (%s to %d @ %d/tick)", type, finish, calc - 1000);
	}
	return szBuffer;
}

static char* CalcExtendedRange(int calc, int start, int finish, int minlevel, int maxlevel, char* szBuffer, size_t BufferSize, char* szPercent, bool ACMod = false)
{
	switch (calc)
	{
	case SpellValueRangeCalc_Random:
		sprintf_s(szBuffer, BufferSize, " (Random: %d to %d)", start, finish* ((start >= 0) ? 1 : -1));
		break;

	default:
		if (abs(start) < abs(finish))
			sprintf_s(szBuffer, BufferSize, " by %d%s (L%d) to %d%s (L%d)", ACMod ? (int)(abs(start) / (10.0f / 3.0f)) : abs(start), szPercent, minlevel, ACMod ? (int)(abs(finish) / (10.0f / 3.0f)) : abs(finish), szPercent, maxlevel);
		else
			sprintf_s(szBuffer, BufferSize, " by %d%s", ACMod ? (int)(abs(finish) / (10.0f / 3.0f)) : abs(finish), szPercent);
	}

	return szBuffer;
}

template <unsigned int Size>
static char* FormatAT(char* szEffectName, int value, char(&szBuffer)[Size], char* preposition = "by", char* szPercent = "")
{
	sprintf_s(szBuffer, "%s %s %d%s", szEffectName, preposition, abs(value), szPercent);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatBase(char* szEffectName, int base, char(&szBuffer)[Size])
{
	sprintf_s(szBuffer, "%s (%d)", szEffectName, base);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatBase(char* szEffectName, int base, int max, char(&szBuffer)[Size])
{
	sprintf_s(szBuffer, "%s (%d,%d)", szEffectName, base, max);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatBase(char* szEffectName, int base, char* szOptional, char(&szBuffer)[Size])
{
	sprintf_s(szBuffer, "%s %s (%d)", szEffectName, szOptional, base);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatBasePercent(char* szEffectName, int base, char(&szBuffer)[Size])
{
	sprintf_s(szBuffer, "%s (%d%%)", szEffectName, base);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatMinMaxBase(char* szEffectName, int base, int spa, char(&szBuffer)[Size])
{
	sprintf_s(szBuffer, "%s (%d %s)", szEffectName, abs(base), szSPATypes[spa]);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatCount(char* szEffectName, int value, char(&szBuffer)[Size], char* preposition = "by", char* szPercent = "")
{
	sprintf_s(szBuffer, "%s %s %s %d%s", value < 0 ? "Decrease" : "Increase", szEffectName, preposition, abs(value), szPercent);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatExtra(const char* szEffectName, const char* extra, char(&szBuffer)[Size], const char* trigger = "", const char* colon = ":")
{
	sprintf_s(szBuffer, "%s%s %s%s", szEffectName, colon, extra, trigger);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatLimits(const char* szEffectName, int value, const char* extra, char(&szBuffer)[Size])
{
	sprintf_s(szBuffer, "%s (%s %s)", szEffectName, extra, value < 0 ? "excluded" : "allowed");
	return szBuffer;
}

template <unsigned int Size>
static char* FormatMax(char* szEffectName, int value, int max, char(&szBuffer)[Size])
{
	sprintf_s(szBuffer, "%s %s by %d (%d%% max)", max < 0 ? "Decrease" : "Increase", szEffectName, abs(max), value);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatPenaltyChance(char* szEffectName, int value, char(&szBuffer)[Size], char* szPercent, char* penaltychance)
{
	if (value < 100)
		sprintf_s(szBuffer, "%s (%d%s %s)", szEffectName, value, szPercent, penaltychance);
	else
		sprintf_s(szBuffer, "%s", szEffectName);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatPercent(char* szEffectName, int value, int max, char(&szBuffer)[Size], bool scaling = true, bool hundreds = false, bool usepercent = true)
{
	char szPercent[MAX_STRING] = { 0 };

	if (usepercent)
		strcat_s(szPercent, "%");

	if (hundreds)
	{
		if (value == max)
		{
			if (scaling)
				sprintf_s(szBuffer, "%s %s by %.2f%s", max < 0 ? "Decrease" : "Increase", szEffectName, abs(max / 100.0f), szPercent);
			else
				sprintf_s(szBuffer, "%s by %.2f%s", szEffectName, abs(max / 100.0f), szPercent);
		}
		else
		{
			if (scaling)
				sprintf_s(szBuffer, "%s %s by %.2f%s to %.2f%s", max < 0 ? "Decrease" : "Increase", szEffectName, abs(value / 100.0f), szPercent, abs(max / 100.0f), szPercent);
			else
				sprintf_s(szBuffer, "%s by %.2f%s to %.2f%s", szEffectName, abs(value / 100.0f), szPercent, abs(max / 100.0f), szPercent);
		}
	}
	else
	{
		if (value == max)
		{
			if (scaling)
				sprintf_s(szBuffer, "%s %s by %d%s", max < 0 ? "Decrease" : "Increase", szEffectName, abs(max), szPercent);
			else
				sprintf_s(szBuffer, "%s by %d%s", szEffectName, abs(max), szPercent);
		}
		else
		{
			if (scaling)
				sprintf_s(szBuffer, "%s %s by %d%s to %d%s", max < 0 ? "Decrease" : "Increase", szEffectName, abs(value), szPercent, abs(max), szPercent);
			else
				sprintf_s(szBuffer, "%s by %d%s to %d%s", szEffectName, abs(value), szPercent, abs(max), szPercent);
		}
	}

	return szBuffer;
}

template <unsigned int Size>
static char* FormatPercent(char* szEffectName, int value, char(&szBuffer)[Size], bool scaling = true, bool hundreds = false, bool usepercent = true)
{
	return FormatPercent(szEffectName, value, value, szBuffer, scaling, hundreds, usepercent);
}

template <unsigned int Size>
static char* FormatRange(char* szEffectName, int value, char* range, char(&szBuffer)[Size], char* extra = "")
{
	sprintf_s(szBuffer, "%s %s%s%s", value < 0 ? "Decrease" : "Increase", szEffectName, range, extra);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatRateMod(char* szEffectName, int value, int base, char(&szBuffer)[Size])
{
	if (base > 0)
		sprintf_s(szBuffer, "%s (rate mod %d)", GetSpellNameByID(value), base);
	else
		strcat_s(szBuffer, GetSpellNameByID(value));
	return szBuffer;
}

template <unsigned int Size>
static char* FormatRefreshTimer(char* szEffectName, int value, int max, int skill, char(&szBuffer)[Size], char* preposition = "with")
{
	if (value == max)
		sprintf_s(szBuffer, "%s %s by %d sec %s %s", max < 0 ? "Decrease" : "Increase", szEffectName, abs(max), preposition, skill >= 0 ? szSkills[skill] : "All Skills");
	else
		sprintf_s(szBuffer, "%s %s by %d sec to %d sec %s %s", max < 0 ? "Decrease" : "Increase", szEffectName, abs(value), abs(max), preposition, skill >= 0 ? szSkills[skill] : "All Skills");
	return szBuffer;
}

template <unsigned int Size>
static char* FormatRefreshTimer(char* szEffectName, int value, int skill, char(&szBuffer)[Size], char* preposition = "with")
{
	return FormatRefreshTimer(szEffectName, value, value, skill, szBuffer, preposition);
}

template <unsigned int Size>
static char* FormatResists(char* szEffectName, int value, int base, char(&szBuffer)[Size])
{
	if (value < 100)
	{
		char szTemp[MAX_STRING] = { 0 };
		sprintf_s(szBuffer, "%s (%d%% Chance)", GetSpellEffectNameByID(base, szTemp, MAX_STRING), value);
	}
	else
	{
		sprintf_s(szBuffer, "%s", szEffectName);
	}
	return szBuffer;
}

template <unsigned int Size>
static char* FormatSeconds(char* szEffectName, int value, char(&szBuffer)[Size], bool tens = false)
{
	if (tens)
		sprintf_s(szBuffer, "%s (%d0.00 sec)", szEffectName, value);
	else
		sprintf_s(szBuffer, "%s (%d sec)", szEffectName, value);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatSeconds(char* szEffectName, float value, char(&szBuffer)[Size])
{
	sprintf_s(szBuffer, "%s (%.2f sec)", szEffectName, value);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatSecondsCount(char* szEffectName, float value, char(&szBuffer)[Size], char* preposition = "by")
{
	sprintf_s(szBuffer, "%s %s %s %.2f sec", value < 0 ? "Decrease" : "Increase", szEffectName, preposition, abs(value));
	return szBuffer;
}

template <unsigned int Size>
static char* FormatSkillAttack(char* szEffectName, int value, int max, int base2, int skill, char(&szBuffer)[Size], char* preposition = "with")
{
	sprintf_s(szBuffer, "%s %s %s for %d damage", FormatPercent(szEffectName, value, max, szBuffer), preposition, skill >= 0 ? szSkills[skill] : "All Skills", base2);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatSkillAttack(char* szEffectName, int value, int base2, int skill, char(&szBuffer)[Size], char* preposition = "with")
{
	return FormatSkillAttack(szEffectName, base2, base2, value, skill, szBuffer, preposition);
}

template <unsigned int Size>
static char* FormatSkills(char* szEffectName, int value, int max, int skill, char(&szBuffer)[Size], bool usepercent = true, char* preposition = "with")
{
	sprintf_s(szBuffer, "%s %s %s", FormatPercent(szEffectName, value, max, szBuffer, true, false, usepercent), preposition, skill >= 0 ? szSkills[skill] : "All Skills");
	return szBuffer;
}

template <unsigned int Size>
static char* FormatSkills(char* szEffectName, int value, int skill, char(&szBuffer)[Size], bool percent = true, char* preposition = "with")
{
	return FormatSkills(szEffectName, value, value, skill, szBuffer, usepercent, preposition);
}

template <unsigned int Size>
static char* FormatSpellChance(char* szEffectName, int value, int base, char(&szBuffer)[Size])
{
	if (value < 100)
		sprintf_s(szBuffer, " (%d%% Chance, Spell: %s)", value, GetSpellNameByID(base));
	else
		sprintf_s(szBuffer, " (Spell: %s)", GetSpellNameByID(base));
	return szBuffer;
}

template <unsigned int Size>
static char* FormatSpellGroupChance(char* szEffectName, int value, int base, char(&szBuffer)[Size])
{
	if (value < 100)
		sprintf_s(szBuffer, " (%d%% Chance, Spell: %s)", value, GetSpellNameBySpellGroupID(base));
	else
		sprintf_s(szBuffer, " (Spell: %s)", GetSpellNameBySpellGroupID(base));
	return szBuffer;
}

template <unsigned int Size>
static char* FormatStacking(char* szEffectName, int slot, int value, int max, int spa, char* extra, char(&szBuffer)[Size])
{
	if (max > 0)
		sprintf_s(szBuffer, "%s %s spell if slot %d is effect '%s' and < %d", szEffectName, spa == 148 ? "new" : "existing", slot, extra, value);
	else
		sprintf_s(szBuffer, "%s %s spell if slot %d is effect '%s'", szEffectName, spa == 148 ? "new" : "existing", slot, extra);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatStatsCapRange(char* szEffectName, int value, char* stat, char* range, char(&szBuffer)[Size])
{
	sprintf_s(szBuffer, "%s %s %s%s", value < 0 ? "Decrease" : "Increase", stat, szEffectName, range);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatString(char* szEffectName, char* extra, char(&szBuffer)[Size], char* trigger = "")
{
	sprintf_s(szBuffer, "%s %s%s", szEffectName, extra, trigger);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatTimer(char* szEffectName, int value, char(&szBuffer)[Size])
{
	sprintf_s(szBuffer, "%s by %d.00 sec", szEffectName, value);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatTimer(char* szEffectName, float value, char(&szBuffer)[Size])
{
	sprintf_s(szBuffer, "%s by %.2f sec", szEffectName, value);
	return szBuffer;
}

int GetSpellAttrib(SPELL* pSpell, int index)
{
	if (index < 0)
		index = 0;

	if (pSpell && pSpellMgr)
	{
		int numeff = GetSpellNumEffects(pSpell);
		if (numeff == 0)
			return 0; // this is so stupid, it didnt use to do this prior to test on may 7 2018, what changed? we need to check that. -eqmule

		if (numeff > index)
		{
			if (PSPELLCALCINFO pCalcInfo = pSpellMgr->GetSpellAffect(pSpell->CalcIndex + index))
			{
				return pCalcInfo->Attrib;
			}
		}
		else
		{
			DebugSpewAlways("Bad usage of GetSpellAttrib: index=%d", index);
		}
	}
	return 0;
}

int GetSpellBase(SPELL* pSpell, int index)
{
	if (index < 0)
		index = 0;

	if (pSpell)
	{
		int numeff = GetSpellNumEffects(pSpell);
		if (numeff == 0)
			return 0;

		if (numeff > index)
		{
			if (ClientSpellManager* pSpellM = (ClientSpellManager*)pSpellMgr)
			{
				if (SPELLCALCINFO* pCalcInfo = pSpellM->GetSpellAffect(pSpell->CalcIndex + index))
				{
					return pCalcInfo->Base;
				}
			}
		}
	}

	return 0;
}

int GetSpellBase2(SPELL* pSpell, int index)
{
	if (index < 0)
		index = 0;

	if (pSpell)
	{
		int numeff = GetSpellNumEffects(pSpell);
		if (numeff == 0)
			return 0;

		if (numeff > index)
		{
			if (ClientSpellManager* pSpellM = (ClientSpellManager*)pSpellMgr)
			{
				if (SPELLCALCINFO* pCalcInfo = pSpellM->GetSpellAffect(pSpell->CalcIndex + index))
				{
					return pCalcInfo->Base2;
				}
			}
		}
	}

	return 0;
}

int GetSpellMax(SPELL* pSpell, int index)
{
	if (index < 0)
		index = 0;

	if (pSpell)
	{
		int numeff = GetSpellNumEffects(pSpell);
		if (numeff == 0)
			return 0;

		if (numeff > index)
		{
			if (ClientSpellManager* pSpellM = (ClientSpellManager*)pSpellMgr)
			{
				if (SPELLCALCINFO* pCalcInfo = pSpellM->GetSpellAffect(pSpell->CalcIndex + index))
				{
					return pCalcInfo->Max;
				}
			}
		}
	}

	return 0;
}

int GetSpellCalc(SPELL* pSpell, int index)
{
	if (index < 0)
		index = 0;

	if (pSpell)
	{
		int numeff = GetSpellNumEffects(pSpell);
		if (numeff == 0)
			return 0;

		if (numeff > index)
		{
			if (ClientSpellManager* pSpellM = (ClientSpellManager*)pSpellMgr)
			{
				if (SPELLCALCINFO* pCalcInfo = pSpellM->GetSpellAffect(pSpell->CalcIndex + index))
				{
					return pCalcInfo->Calc;
				}
			}
		}
	}

	return 0;
}

char* ParseSpellEffect(SPELL* pSpell, int i, char* szBuffer, size_t BufferSize, int level)
{
	char szBuff[MAX_STRING] = { 0 };
	char szTemp[MAX_STRING] = { 0 };
	char szTemp2[MAX_STRING] = { 0 };

	int id = pSpell->ID;
	int spa = GetSpellAttrib(pSpell, i);
	int base = GetSpellBase(pSpell, i);
	int base2 = GetSpellBase2(pSpell, i);
	int max = GetSpellMax(pSpell, i);
	int calc = GetSpellCalc(pSpell, i);
	int spellgroup = pSpell->SpellGroup;
	int ticks = pSpell->DurationCap;
	int targets = pSpell->MaxTargets;
	int targettype = pSpell->TargetType;
	int skill = pSpell->Skill;

	if (spa == SPA_NOSPELL)
		return szBuffer;

	if (spa == SPA_CHA && (base <= 1 || base > 255))
		return szBuffer;

	switch (spa)
	{
	case SPA_HASTE:
	case SPA_HEIGHT:
	case SPA_BARD_HASTE:                   // Adjust for Base=100
		base -= 100;
		max -= 100;
		break;
	case SPA_SUMMON_CORPSE:                // Adjust for base/max swapped
		max = base;
		base = 0;
		break;
	case SPA_FOCUS_DAMAGE_MOD:
	case SPA_FOCUS_HEAL_MOD:
	case SPA_FOCUS_MANACOST_MOD:           // Adjust for base2 used as max
		max = base2;
		break;
	case SPA_FOCUS_REAGENT_MOD:
	case SPA_FOCUS_DAMAGE_AMT_DETRIMENTAL: // Adjust for base2 used as base
		base = base2;
		break;
	}

	PITEMDB ItemDB = gItemDB;

	char extendedrange[MAX_STRING] = { 0 };
	char range[MAX_STRING] = { 0 };
	char repeating[MAX_STRING] = { 0 };
	char maxlevel[MAX_STRING] = { 0 };
	char spelleffectname[MAX_STRING] = { 0 };
	char extra[MAX_STRING] = { 0 };
	char maxtargets[MAX_STRING] = { 0 };
	char szPercent[MAX_STRING] = "%";

	GetSpellEffectName(spa, spelleffectname, sizeof(spelleffectname));
	strcpy_s(extra, pSpell->Extra);

	int minspelllvl = CalcMinSpellLevel(pSpell);
	int maxspelllvl = CalcMaxSpellLevel(calc, base, max, ticks, minspelllvl, level);
	int value = CalcValue(calc, (spa == SPA_STACKING_BLOCK) ? max : base, max, 1, minspelllvl, minspelllvl);
	int finish = CalcValue(calc, (spa == SPA_FOCUS_INCOMING_DMG_MOD) ? base2 : base, max, ticks, minspelllvl, level);

	bool usePercent =
		(spa == SPA_MOVEMENT_RATE
			|| spa == SPA_HASTE
			|| spa == SPA_BARD_HASTE
			|| spa == SPA_FOCUS_DAMAGE_MOD
			|| spa == SPA_FOCUS_HEAL_MOD
			|| spa == SPA_DOUBLE_ATTACK
			|| spa == SPA_STUN_RESIST
			|| spa == SPA_PROC_CHANCE
			|| spa == SPA_DIVINE_SAVE
			|| spa == SPA_METABOLISM
			|| spa == SPA_TRIPLE_BACKSTAB
			|| spa == SPA_DOTCRIT
			|| spa == SPA_HEALCRIT
			|| spa == SPA_MENDCRIT
			|| spa == SPA_FLURRY
			|| spa == SPA_PET_FLURRY
			|| spa == SPA_SPELL_CRIT_CHANCE
			|| spa == SPA_SHIELD_BLOCK_CHANCE
			|| spa == SPA_FOCUS_DAMAGE_MOD_CRIT
			|| spa == SPA_FOCUS_INCOMING_DMG_MOD);

	bool AEEffect =
		(targettype == TT_PBAE
			|| targettype == TT_TARGETED_AE
			|| targettype == TT_AE_PC_V2
			|| targettype == TT_DIRECTIONAL);

	strcat_s(range, CalcValueRange(calc, base, max, ticks, minspelllvl, level, szTemp2, sizeof(szTemp2), usePercent ? szPercent : ""));
	strcat_s(extendedrange, CalcExtendedRange(calc, value, finish, minspelllvl, maxspelllvl, szTemp2, sizeof(szTemp2), usePercent ? szPercent : "", (spa == SPA_AC || spa == SPA_AC2)));
	if (ticks) sprintf_s(repeating, " per tick ");
	if (max) sprintf_s(maxlevel, " up to level %d", max);
	if (targets && AEEffect) sprintf_s(maxtargets, " on up to %d enemies", targets);

#ifdef DEBUGSPELLS
	WriteChatf("SLOT:%d, SPA:%d, BASE:%d, BASE2:%d, MAX:%d, CALC:%d, TICKS:%d, VALUE:%d, FINISH:%d, MINSPELLLVL:%d, MAXSPELLLVL:%d, RANGE:%s, EXTENDEDRANGE:%s, USEPERCENT:%s, REPEATING:%s, MAXLEVEL:%s",
		i + 1, spa, base, base2, max, calc, ticks, value, finish, minspelllvl, maxspelllvl, range, extendedrange, usePercent ? "TRUE" : "FALSE", repeating, maxlevel);
#endif

	sprintf_s(szBuff, "Slot %d: ", i + 1);

	switch (spa)
	{
	case SPA_HP:                  // hp +/-: heals/regen/dd
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		if (strlen(repeating)) strcat_s(szBuff, repeating);

		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		if (base2) {
			GetSpellRestrictions(pSpell, i, szTemp, sizeof(szTemp));
			strcat_s(szBuff, " -- Restrictions: ");
			strcat_s(szBuff, szTemp);
		}
		break;
	case SPA_AC:                  // ac mod
	case SPA_ATTACK_POWER:        // attack mod
	case SPA_MOVEMENT_RATE:       // movement speed mod
	case SPA_STR:                 // str mod
	case SPA_DEX:                 // dex mod
	case SPA_AGI:                 // agi mod
	case SPA_STA:                 // sta mod
	case SPA_INT:                 // int mod
	case SPA_WIS:                 // wis mod
	case SPA_CHA:                 // cha mod
	case SPA_HASTE:               // haste mod
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case SPA_INVISIBILITY:        // Invisibility
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_SEE_INVIS:           // See Invisible(c)
	case SPA_ENDURING_BREATH:     // Water Breathing(c)
		strcat_s(szBuff, FormatBase(spelleffectname, value, szTemp2));
		break;
	case SPA_MANA:                // mana +/-
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		if (strlen(repeating)) strcat_s(szBuff, repeating);
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		if (base2) {
			GetSpellRestrictions(pSpell, i, szTemp, sizeof(szTemp));
			strcat_s(szBuff, " -- Restrictions: ");
			strcat_s(szBuff, szTemp);
		}
		break;
	case SPA_NPC_FRENZY:          // NPC Frenzy (no spells currently)
	case SPA_NPC_AWARENESS:       // NPC Awareness (no spells currently)
	case SPA_NPC_AGGRO:           // NPC Aggro
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_NPC_FACTION:         // NPC Faction
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case SPA_BLINDNESS:           // Blindness
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_STUN:                // stun  time = base in ms
		if (base2 != 0 && base != base2)
			sprintf_s(szTemp, " NPC for %1.fs (PC for %1.fs)%s", base / 1000.0f, base2 / 1000.0f, maxlevel);
		else
			sprintf_s(szTemp, " for %1.fs%s", base / 1000.0f, maxlevel);
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case SPA_CHARM:               // Charm(c/level)
	case SPA_FEAR:                // Fear(c/level)
		strcat_s(szBuff, FormatString(spelleffectname, maxlevel, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case SPA_FATIGUE:             // Fatigue
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case SPA_BIND_AFFINITY:       // Bind Affinity
		if (base == 2)
			strcat_s(szTemp, " (Secondary Bind Point)");
		if (base == 3)
			strcat_s(szTemp, " (Tertiary Bind Point)");
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_GATE:                // Gate
		if (base == 2)
			strcat_s(szTemp, " to Secondary Bind Point");
		if (base == 3)
			strcat_s(szTemp, " (Tertiary Bind Point)");
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_DISPEL_MAGIC:        // Cancel Magic(c)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_INVIS_VS_UNDEAD:     // Invisibility versus Undead
	case SPA_INVIS_VS_ANIMALS:    // Invisibility versus Animal
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_NPC_AGGRO_RADIUS:    // NPC Aggro Radius(c/level)
		                          // NPC Aggro Radius' use the reverse sign from normal base values
		strcat_s(szBuff, FormatCount(spelleffectname, -value, szTemp2));
		strcat_s(szBuff, maxlevel);
		break;
	case SPA_ENTHRALL:            // Mesmerize(c/level)
		strcat_s(szBuff, FormatString(spelleffectname, maxlevel, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case SPA_CREATE_ITEM:         // Create Item
		while ((ItemDB) && (base != ItemDB->ID)) {
			ItemDB = ItemDB->pNext;
		}
		if (ItemDB) {
			sprintf_s(szTemp, "%s (Qty:%d)", ItemDB->szName, (int)ItemDB->StackSize < calc ? ItemDB->StackSize : calc);
		}
		else {
			sprintf_s(szTemp, "[%5d] (Qty:%d)", base, calc);
		}
		strcat_s(szBuff, FormatExtra(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_SUMMON_PET:          // Summon Pet
		strcat_s(szBuff, FormatExtra(spelleffectname, extra, szTemp2));
		break;
	case SPA_CONFUSE:             // Confuse
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_DISEASE:             // disease counters
	case SPA_POISON:              // poison counters
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case SPA_DETECT_HOSTILE: //DetectHostile (no spells currently)
	case SPA_DETECT_MAGIC: //DetectMagic (no spells currently)
	case SPA_NO_TWINCAST: //No Twincast
	case SPA_INVULNERABILITY: //Invulnerability
	case SPA_BANISH: //Banish
	case SPA_SHADOW_STEP: //Shadow Step
	case SPA_BERSERK: //Berserk
	case SPA_LYCANTHROPY: //Lycanthropy
	case SPA_VAMPIRISM: //Vampirism
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_RESIST_FIRE: //fire resist
	case SPA_RESIST_COLD: //cold resist
	case SPA_RESIST_POISON: //poison resist
	case SPA_RESIST_DISEASE: //disease resist
	case SPA_RESIST_MAGIC: //magic resist
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case SPA_DETECT_TRAPS: //Detect Traps (no spells currently)
	case SPA_DETECT_UNDEAD: //Sense Undead
	case SPA_DETECT_SUMMONED: //Sense Summoned
	case SPA_DETECT_ANIMALS: //Sense Animals
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_STONESKIN: //most runes
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case SPA_TRUE_NORTH: //True North
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_LEVITATION:
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_CHANGE_FORM: //Illusion: Base=Race
		strcat_s(szBuff, FormatExtra(spelleffectname, pEverQuest->GetRaceDesc(base), szTemp2));
		break;
	case SPA_DAMAGE_SHIELD: //Damage Shield
		// Damage Shield's use the reverse sign from normal base values
		strcat_s(szBuff, FormatRange(spelleffectname, -value, extendedrange, szTemp2));
		break;
	case SPA_TRANSFER_ITEM: //Transfer Item (no spells currently)
	case SPA_ITEM_LORE: //Identify
	case SPA_ITEM_IDENTIFY: //Item ID (no spells currently)
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_NPC_WIPE_HATE_LIST: //Memblur e%
		strcat_s(szBuff, FormatPenaltyChance(spelleffectname, value + 40, szTemp2, szPercent, "Chance"));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case SPA_SPIN_STUN: //SpinStun
	case SPA_INFRAVISION: //Infravision
	case SPA_ULTRAVISION: //ultravision
	case SPA_EYE_OF_ZOMM: //Eye of Zomm
	case SPA_RECLAIM_ENERGY: //Reclaim Energy
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_MAX_HP: //max hp mod
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case SPA_CORPSE_BOMB: //CorpseBomb (no spells currently)
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_CREATE_UNDEAD: //Create Undead Pet
		strcat_s(szBuff, FormatExtra(spelleffectname, extra, szTemp2));
		break;
	case SPA_PRESERVE_CORPSE: //Preserve Corpse (no spells currently)
	case SPA_BIND_SIGHT: //Bind Sight
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_FEIGN_DEATH: //Feign Death
		strcat_s(szBuff, FormatPenaltyChance(spelleffectname, value, szTemp2, szPercent, "Chance"));
		break;
	case SPA_VENTRILOQUISM: //Voice Graft
	case SPA_SENTINEL: //Sentinel
	case SPA_LOCATE_CORPSE: //Locate Corpse
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_SPELL_SHIELD: //Absorb Magic Damage
	case SPA_INSTANT_HP: //+hp when cast (priest buffs that have heal component, DoTs with DDs)
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case SPA_ENCHANT_LIGHT: //Enchant:Light (no spells currently)
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_RESURRECT: //Resurrect
		sprintf_s(szTemp, " and restore %d%s experience", value, szPercent);
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case SPA_SUMMON_TARGET: //Summon Player
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_PORTAL: //zone portal spells
		if (targettype == 6) {
			sprintf_s(szTemp, " Self to %d, %d, %d in %s facing %s", GetSpellBase(pSpell, 0), GetSpellBase(pSpell, 1), GetSpellBase(pSpell, 2), GetFullZone(GetZoneID(extra)), szHeadingNormal[EQHeading(GetSpellBase(pSpell, 3))]);
		}
		else {
			sprintf_s(szTemp, " Group to %d, %d, %d in %s facing %s", GetSpellBase(pSpell, 0), GetSpellBase(pSpell, 1), GetSpellBase(pSpell, 2), GetFullZone(GetZoneID(extra)), szHeadingNormal[EQHeading(GetSpellBase(pSpell, 3))]);
		}
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_HP_NPC_ONLY: //Toss on Z axis (is this right??)
		strcat_s(szBuff, FormatBase(spelleffectname, abs(base), base >= 0 ? " Down" : " Up", szTemp2));
		break;
	case SPA_MELEE_PROC: //Add Proc
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname, base, base2, szTemp), szTemp2));
		break;
	case SPA_NPC_HELP_RADIUS: //Reaction Radius(c/level)
		// Reaction Radius' use the reverse sign from normal base values
		strcat_s(szBuff, FormatCount(spelleffectname, -value, szTemp2));
		strcat_s(szBuff, maxlevel);
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case SPA_MAGNIFICATION: //Perspective Magnification
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_EVACUATE: //evac portal spells
		sprintf_s(szTemp, " to %d, %d, %d in %s facing %s", GetSpellBase(pSpell, 0), GetSpellBase(pSpell, 1), GetSpellBase(pSpell, 2), extra, szHeadingNormal[EQHeading(GetSpellBase(pSpell, 3))]);
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_HEIGHT: //Player Size
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_IGNORE_PET: //Cloak
	case SPA_SUMMON_CORPSE: //Summon Corpse
		strcat_s(szBuff, FormatString(spelleffectname, maxlevel, szTemp2));
		break;
	case SPA_HATE: //hate mod
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case SPA_WEATHER_CONTROL: //Stop Rain
	case SPA_FRAGILE: //Make Fragile
	case SPA_SACRIFICE: //Sacrifice
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_SILENCE: //Silence (no PC spells currently)
		strcat_s(szBuff, spelleffectname);
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case SPA_MAX_MANA: //Mana Pool
	case SPA_BARD_HASTE: //Haste v2
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case SPA_ROOT: //Root
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_HEALDOT: //hp mod: pet heals/regen
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		strcat_s(szBuff, repeating);
		break;
	case SPA_COMPLETEHEAL: //Complete Heal (with duration)
	case SPA_PET_FEARLESS: //Fearless
	case SPA_CALL_PET: //Call Pet
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_TRANSLOCATE: //zone translocate spells
		if (extra[0])
			if (extra[0] == '0')
				strcat_s(szTemp, " to Bind Point");
			else
				sprintf_s(szTemp, " to %d, %d, %d in %s facing %s", GetSpellBase(pSpell, 0), GetSpellBase(pSpell, 1), GetSpellBase(pSpell, 2), GetFullZone(GetZoneID(extra)), szHeadingNormal[EQHeading(GetSpellBase(pSpell, 3))]);
		else
			strcat_s(szTemp, " to Bind Point");
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_NPC_ANTI_GATE: //Anti-Gate
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_BEASTLORD_PET: //Summon Warder
		strcat_s(szBuff, FormatExtra(spelleffectname, extra, szTemp2));
		break;
	case SPA_ALTER_PET_LEVEL: //Alter NPC Level (no spells currently)
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_FAMILIAR: //Summon Familiar
		strcat_s(szBuff, FormatExtra(spelleffectname, extra, szTemp2));
		break;
	case SPA_CREATE_ITEM_IN_BAG: //Summon Into Bag
		while ((ItemDB) && (base != ItemDB->ID)) {
			ItemDB = ItemDB->pNext;
		}
		if (ItemDB) {
			sprintf_s(szTemp, "%s", ItemDB->szName);
		}
		else {
			sprintf_s(szTemp, "[%5d]", base);
		}
		strcat_s(szBuff, FormatExtra(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_ARCHERY: //Increase Archery (no spells currently)
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case SPA_RESIST_ALL: //Resistances
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case SPA_FIZZLE_SKILL: //Casting Level
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case SPA_SUMMON_MOUNT: //Summon Mount
		strcat_s(szBuff, FormatExtra(spelleffectname, extra, szTemp2));
		break;
	case SPA_MODIFY_HATE: //aggro multiplier
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_CORNUCOPIA: //Food/Water
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_CURSE: //curse counters
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case SPA_HIT_MAGIC: //Make Weapons Magical
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_AMPLIFICATION: //Singing Skill
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case SPA_ATTACK_SPEED_MAX: //Bard Overhaste
	case SPA_HEALMOD: //Reduce Healing Effectiveness (%)
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_IRONMAIDEN: //Reverse Damage Shield
		strcat_s(szBuff, FormatBase(spelleffectname, -base, szTemp2));
		break;
	case SPA_REDUCESKILL: //Reduce Skill
		strcat_s(szBuff, FormatSkills(spelleffectname, value, finish, base2, szTemp2));
		break;
	case SPA_IMMUNITY: //Immunity
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_FOCUS_DAMAGE_MOD: //spell damage
	case SPA_FOCUS_HEAL_MOD: //healing
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_FOCUS_RESIST_MOD: //spell resist rate
	case SPA_FOCUS_CAST_TIME_MOD: //spell haste
		strcat_s(szBuff, FormatPercent(spelleffectname, -value, -finish, szTemp2));
		break;
	case SPA_FOCUS_DURATION_MOD: //spell duration
	case SPA_FOCUS_RANGE_MOD: //spell range
	case SPA_FOCUS_HATE_MOD: //spell/bash hate
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_FOCUS_REAGENT_MOD: //Decrease Chance of Using Reagent
	case SPA_FOCUS_MANACOST_MOD: //Spell Mana Cost
	case SPA_FOCUS_STUNTIME_MOD: //Spell Stun Duration (no spells currently)
		strcat_s(szBuff, FormatPercent(spelleffectname, -value, -finish, szTemp2));
		break;
	case SPA_FOCUS_LEVEL_MAX: //limit max level
		if (base2 > 0)
			sprintf_s(szTemp, "%s (%d) (lose %d%s per level over cap)", spelleffectname, base, base2, szPercent);
		else
			strcpy_s(szTemp, FormatBase(spelleffectname, base, szTemp2));
		strcat_s(szBuff, szTemp);
		break;
	case SPA_FOCUS_RESIST_TYPE: //Limit: Resist
		strcat_s(szBuff, FormatLimits(spelleffectname, value, GetResistTypeName(base, szTemp), szTemp2));
		break;
	case SPA_FOCUS_TARGET_TYPE: //limit target types this affects
		strcat_s(szBuff, FormatLimits(spelleffectname, value, GetTargetTypeLimitsName(base, szTemp), szTemp2));
		break;
	case SPA_FOCUS_WHICH_SPA: //limit effect types this affects
		strcat_s(szBuff, FormatLimits(spelleffectname, value, GetSpellEffectName(base, szTemp, sizeof(szTemp)), szTemp2));
		break;
	case SPA_FOCUS_BENEFICIAL: //limit spelltype this affects
		strcat_s(szBuff, FormatLimits(spelleffectname, value, GetSpellTypeName(base, szTemp), szTemp2));
		break;
	case SPA_FOCUS_WHICH_SPELL: //limit spell this affects
		strcat_s(szBuff, FormatLimits(spelleffectname, value, GetSpellNameByID(base), szTemp2));
		break;
	case SPA_FOCUS_DURATION_MIN: //limit min duration of spells this affects (base= #ticks)
		strcat_s(szBuff, FormatSeconds(spelleffectname, value * 6, szTemp2));
		break;
	case SPA_FOCUS_INSTANT_ONLY: //limit to instant spells only
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_FOCUS_LEVEL_MIN: //Limit: Min Level
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_FOCUS_CASTTIME_MIN: //limit min casting time of spells this affects (base= seconds in ms)
	case SPA_FOCUS_CASTTIME_MAX: //limit max casting time of spells this affects (base= seconds in ms)
		strcat_s(szBuff, FormatSeconds(spelleffectname, value / 1000.0f, szTemp2));
		break;
	case SPA_NPC_PORTAL_WARDER_BANISH: //Teleportv2
		sprintf_s(szTemp, " to %d, %d, %d in %s facing %s", GetSpellBase(pSpell, 0), GetSpellBase(pSpell, 1), GetSpellBase(pSpell, 2), GetFullZone(GetZoneID(extra)), szHeadingNormal[EQHeading(GetSpellBase(pSpell, 3))]);
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_PORTAL_LOCATIONS: //Resist Electricity
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_PERCENT_HEAL: //Hit Points (% Max)
		strcat_s(szBuff, FormatMax(spelleffectname, value, max, szTemp2));
		break;
	case SPA_STACKING_BLOCK: //Stacking: Block
		strcat_s(szBuff, FormatStacking(spelleffectname, base2, value, /*(max>1000 ? max - 1000 : max)*/ max, spa, GetSpellEffectName(base, szTemp, sizeof(szTemp)), szTemp2));
		break;
	case SPA_STRIP_VIRTUAL_SLOT: //Stacking: Overwrite
		strcat_s(szBuff, FormatStacking(spelleffectname, calc - 200, value, (max > 1000 ? max - 1000 : max), spa, GetSpellEffectName(base, szTemp, sizeof(szTemp)), szTemp2));
		break;
	case SPA_DIVINE_INTERVENTION: //Death Save - Restore Full Health
		sprintf_s(szTemp, "Restore %s Health", base == 1 ? "Partial" : base == 2 ? "Full" : "Unknown");
		strcat_s(szBuff, FormatExtra(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_POCKET_PET: //Suspended Minion (no current spells)
		sprintf_s(szTemp, "(%s)", base == 0 ? "Current HP Only" : base == 1 ? "Current HP, Buffs, Weapons" : "Unknown");
		strcat_s(szBuff, FormatExtra(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_PET_SWARM: //Summon Pets (swarm)
		sprintf_s(szTemp, "%s x%d for %dsec", extra, value, finish);
		strcat_s(szBuff, FormatExtra(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_HEALTH_BALANCE: //Balance Party Health
		strcat_s(szBuff, FormatPenaltyChance(spelleffectname, value, szTemp2, szPercent, "Penalty"));
		break;
	case SPA_CANCEL_NEGATIVE_MAGIC: //Remove Detrimental(c)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_POP_RESURRECT: //PoP Resurrect
	case SPA_MIRROR: //Illusion: Target
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_FEEDBACK: //Spell Damage Shield
		strcat_s(szBuff, FormatRange(spelleffectname, -value, extendedrange, szTemp2));
		break;
	case SPA_REFLECT: //Chance to Reflect Spell
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_MODIFY_ALL_STATS: //Stats
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case SPA_CHANGE_SOBRIETY: //Drunk effect
		strcat_s(szBuff, FormatAT(spelleffectname, value, szTemp2, "if Alcholol Tolerance is below"));
		break;
	case SPA_SPELL_GUARD: //Mitigate Spell Damage
	case SPA_MELEE_GUARD: //Mitigate Melee Damage
		strcat_s(szBuff, FormatPercent(spelleffectname, value, szTemp2, false));
		if (max > 0)
			sprintf_s(szTemp, " until %d absorbed", max);
		strcat_s(szBuff, szTemp);
		break;
	case SPA_ABSORB_HIT: //Absorb Damage
		sprintf_s(szTemp, " up to %d from the next %d melee strikes or direct damage spells", max, value);
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_OBJECT_SENSE_TRAP: //Attempt Sense (Cursed) Trap
	case SPA_OBJECT_DISARM_TRAP: //Attempt Disarm (Cursed) Trap
	case SPA_OBJECT_PICKLOCK: //Attempt Destroy (Cursed) Lock
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_FOCUS_PET: //Increase Pet Power
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_DEFENSIVE: //Mitigation
		strcat_s(szBuff, FormatPercent(spelleffectname, -value, -finish, szTemp2));
		break;
	case SPA_CRITICAL_MELEE: //Chance to Critical Hit
		strcat_s(szBuff, FormatSkills(spelleffectname, value, finish, base2, szTemp2, true, "for"));
		break;
	case SPA_CRITICAL_SPELL: //Chance to Critical Cast
	case SPA_CRIPPLING_BLOW: //Crippling Blow
	case SPA_EVASION: //Melee Avoidance
	case SPA_RIPOSTE: //Riposte
	case SPA_DODGE: //Dodge
	case SPA_PARRY: //Parry
	case SPA_DUAL_WIELD: //Dual Wield
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_DOUBLE_ATTACK: //Stat Cap Mod (how do they know which?)
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case SPA_MELEE_LIFETAP: //Lifetap Proc
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		strcat_s(szBuff, " heal");
		break;
	case SPA_PURETONE: //Puretone
	case SPA_SANCTIFICATION: //Spell Resist
	case SPA_FEARLESS: //Fearless
	case SPA_HUNDRED_HANDS: //Hundred Hands
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_SKILL_INCREASE_CHANCE: //Skill Chance Mod
	case SPA_ACCURACY: //Chance to hit with Backstab (or throwing/archery [http://lucy.allakhazam.com/spellraw.html?id=9616&source=Live])
	case SPA_SKILL_DAMAGE_MOD: //Damage Mod (how to tell which, rogues get a backstab only, others get an all skills)
	case SPA_MIN_DAMAGE_DONE_MOD: //Damage Mod (see above)
		strcat_s(szBuff, FormatSkills(spelleffectname, value, finish, base2, szTemp2));
		break;
	case SPA_MANA_BALANCE: //Mana Balance
		strcat_s(szBuff, FormatPenaltyChance(spelleffectname, value, szTemp2, szPercent, "Penalty"));
		break;
	case SPA_BLOCK: //Block
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_ENDURANCE: //Endurance DoT/Regen
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		strcat_s(szBuff, repeating);
		break;
	case SPA_INCREASE_MAX_ENDURANCE: //Max Endurance
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case SPA_AMNESIA: //Amnesia
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_HATE_OVER_TIME: //Discord Hate
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case SPA_SKILL_ATTACK: //Skill Attack
		strcat_s(szBuff, FormatSkillAttack(spelleffectname, value, base2, skill, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case SPA_FADE: //Fade
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_STUN_RESIST: //Stun Resist
	case SPA_STRIKETHROUGH1: //Strikethrough
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case SPA_SKILL_DAMAGE_TAKEN: //Skill Damage
		strcat_s(szBuff, FormatSkills(spelleffectname, value, finish, base2, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case SPA_INSTANT_ENDURANCE: //Endurance Heals
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case SPA_TAUNT: //Taunt
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_PROC_CHANCE: //Proc Mod
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case SPA_RANGE_ABILITY: //Ranged Proc
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname, base, base2, szTemp), szTemp2));
		break;
	case SPA_ILLUSION_OTHERS: //Illusion Other
	case SPA_MASS_GROUP_BUFF: //Mass Group Buff
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_GROUP_FEAR_IMMUNITY: //War Cry
		strcat_s(szBuff, FormatSeconds(spelleffectname, value, szTemp2, true));
		break;
	case SPA_RAMPAGE: //AE Rampage
	case SPA_AE_TAUNT: //AE Taunt
	case SPA_FLESH_TO_BONE: //Flesh to Bone
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_PURGE_POISON: //Purge Poison (no spells currently)
	case SPA_CANCEL_BENEFICIAL: //Disspell Beneficial Buffs
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_SHIELD_CASTER: //Pet Shield
		strcat_s(szBuff, FormatSeconds(spelleffectname, value * 1.0f, szTemp2));
		break;
	case SPA_DESTRUCTIVE_FORCE: //AE Melee
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_FOCUS_FRENZIED_DEVASTATION: //Frenzied Devastation (### come back and change ###)
		strcat_s(szBuff, FormatSeconds(spelleffectname, value, szTemp2, true));
		break;
	case SPA_PET_PCT_MAX_HP://Pet HP
	case SPA_HP_MAX_HP: //Change Max HP
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2, false, true));
		break;
	case SPA_PET_PCT_AVOIDANCE: //Pet Avoidance (no spells currently)
	case SPA_MELEE_ACCURACY: //Accuracy
	case SPA_HEADSHOT: //Headshot (no spells currently)
	case SPA_PET_CRIT_MELEE: //Pet Crit Melee (no spells currently)
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case SPA_SLAY_UNDEAD: //Slay undead (Holyforge)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_INCREASE_SKILL_DAMAGE: //Skill Damage Amt
		strcat_s(szBuff, FormatSkills(spelleffectname, value, finish, base2, szTemp2, false));
		break;
	case SPA_REDUCE_WEIGHT: //Reduce Weight
	case SPA_BLOCK_BEHIND: //Block Behind
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_DOUBLE_RIPOSTE: //Double Riposte (no spells currently)
	case SPA_ADD_RIPOSTE: //Additional Riposte
	case SPA_GIVE_DOUBLE_ATTACK: //Double Attack
	case SPA_2H_BASH: //2H Bash (no spells currently)
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_REDUCE_SKILL_TIMER: //Base Refresh Timer
		strcat_s(szBuff, FormatRefreshTimer(spelleffectname, -value, -finish, base2, szTemp2));
		break;
	case SPA_ACROBATICS: //Reduce Fall Dmg (no spells currently)
	case SPA_CAST_THROUGH_STUN: //Cast Through Stun (no spells currently)
	case SPA_EXTENDED_SHIELDING: //Increase Shield Dist (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_BASH_CHANCE: //Stun Bash Chance (no spells currently)
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_DIVINE_SAVE: //Divine Save
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case SPA_METABOLISM: //Metabolism
		strcat_s(szBuff, FormatRange(spelleffectname, -value, extendedrange, szTemp2));
		break;
	case SPA_POISON_MASTERY: //Poison Mastery (no spells currently)
	case SPA_FOCUS_CHANNELING: //Focus Channelling (no spells currently)
	case SPA_FREE_PET: //Free Pet (no spells currently)
	case SPA_PET_AFFINITY: //Pet Affinity (no spells currently)
	case SPA_PERM_ILLUSION: //Permanent Illusion (no spells currently)
	case SPA_STONEWALL: //Stonewall (no spells currently)
	case SPA_STRING_UNBREAKABLE: //String Unbreakable (no spells currently)
	case SPA_IMPROVE_RECLAIM_ENERGY: //Improve Reclaim Energy (no spells currently)
	case SPA_INCREASE_CHANGE_MEMWIPE: //Increase Chance Memwipe (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_ENHANCED_CHARM: //NoBreak Charm Chance
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_ENHANCED_ROOT: //Root Break Chance
	case SPA_TRAP_CIRCUMVENTION: //Trap Circumvention (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_INCREASE_AIR_SUPPLY: //Lung Capacity
		strcat_s(szBuff, FormatRange(spelleffectname, value, range, szTemp2));
		break;
	case SPA_INCREASE_MAX_SKILL: //Increase SkillCap (no spells currently)
	case SPA_EXTRA_SPECIALIZATION: //Extra Specialization (no spells currently)
	case SPA_OFFHAND_MIN_WEAPON_DAMAGE: //Offhand Min (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_INCREASE_PROC_CHANCE: //Spell Proc Chance
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_ENDLESS_QUIVER: //Endless Quiver (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_BACKSTAB_FRONT: //Backstab from Front
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_CHAOTIC_STAB: //Chaotic Stab (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_NOSPELL: //placeholder of some kind
		break;
	case SPA_SHIELDING_DURATION_MOD: //Shielding Duration (no spells currently)
		strcat_s(szBuff, FormatBasePercent(spelleffectname, base, szTemp2));
		break;
	case SPA_SHROUD_OF_STEALTH: //Shroud Of Stealth (no spells currently)
	case SPA_GIVE_PET_HOLD: //Give Pet Hold (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_TRIPLE_BACKSTAB: //Triple Backstab
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_AC_LIMIT_MOD: //AC Limit
	case SPA_ADD_INSTRUMENT_MOD: //Add Instrument
	case SPA_SONG_MOD_CAP: //Song Cap (no spells currently)
		strcat_s(szBuff, FormatBasePercent(spelleffectname, base, szTemp2));
		break;
	case SPA_INCREASE_STAT_CAP: //Stats Cap
		strcat_s(szBuff, FormatStatsCapRange(spelleffectname, value, GetStatShortName(base2, szTemp), extendedrange, szTemp2));
		break;
	case SPA_TRADESKILL_MASTERY: //Tradeskill Masteries (no spells currently)
	case SPA_REDUCE_AA_TIMER: //Reduce AATimer
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_NO_FIZZLE: //No Fizzle
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_ADD_2H_ATTACK_CHANCE: //Attack Chance
	case SPA_ADD_PET_COMMANDS: //Add Pet Commands (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_ALCHEMY_FAIL_RATE: //TS Fail Rate
		strcat_s(szBuff, FormatSkills(spelleffectname, -value, -finish, base2, szTemp2, true, "for"));
		break;
	case SPA_FIRST_AID: //Bandage Perc Limit (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_EXTEND_SONG_RANGE: //Bard Song Range
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2, "to"));
		break;
	case SPA_BASE_RUN_MOD: //Base Run Speed
		strcat_s(szBuff, FormatBasePercent(spelleffectname, base, szTemp2));
		break;
	case SPA_INCREASE_CASTING_LEVEL: //Casting Level
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case SPA_DOTCRIT: //DoT Crit
	case SPA_HEALCRIT: //Heal Crit
	case SPA_MENDCRIT: //Mend Crit (no spells currently)
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case SPA_DUAL_WIELD_AMT: //Dual Wield Amt (no spells currently)
	case SPA_EXTRA_DI_CHANCE: //Extra DI Chance (no spells currently)
	case SPA_FINISHING_BLOW: //Finishing Blow (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_FLURRY: //Flurry
	case SPA_PET_FLURRY: //Pet Flurry Chance
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case SPA_PET_FEIGN: //Give Pet Feign (no spells currently)
	case SPA_INCREASE_BANDAGE_AMT: //Increase Bandage Amt (no spells currently)
	case SPA_WU_ATTACK: //Special Attack Chain (no spells currently)
	case SPA_IMPROVE_LOH: //LoH Set Heal (no spells currently)
	case SPA_NIMBLE_EVASION: //NoMove Check Sneak (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_FOCUS_DAMAGE_AMT: //DD Bonus
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case SPA_FOCUS_DURATION_AMT: //Focus Combat Duration
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		strcat_s(szBuff, " tick(s)");
		break;
	case SPA_ADD_PROC_HIT: //Add Proc Hit (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_DOOM_EFFECT: //Trigger on Fade
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Fade"));
		break;
	case SPA_INCREASE_RUN_SPEED_CAP: //Increase Movement Cap (no spells currently)
	case SPA_PURIFY: //Purify
	case SPA_STRIKETHROUGH: //Strikethrough2
	case SPA_STUN_RESIST2: //StunResist2 (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_SPELL_CRIT_CHANCE: //Spell Crit Chance
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case SPA_REDUCE_SPECIAL_TIMER: //Reduce Timer Special (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_FOCUS_DAMAGE_MOD_DETRIMENTAL: //Incoming Spell Damage
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_FOCUS_DAMAGE_AMT_DETRIMENTAL: //Incoming Spell Damage Amt
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case SPA_TINY_COMPANION: //Tiny Companion
		strcat_s(szBuff, FormatPercent(spelleffectname, -value, -finish, szTemp2));
		break;
	case SPA_WAKE_DEAD: //Wake the Dead
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_DOPPELGANGER: //Doppleganger
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_INCREASE_RANGE_DMG: //Increase Range Damage (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_FOCUS_DAMAGE_MOD_CRIT: //Damage Crit
	case SPA_FOCUS_DAMAGE_AMT_CRIT: //Damage
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case SPA_SECONDARY_RIPOSTE_MOD: //Secondary Riposte Mod (no spells currently)
		strcat_s(szBuff, FormatBasePercent(spelleffectname, base, szTemp2));
		break;
	case SPA_DAMAGE_SHIELD_MOD: //Damage Shield Mitigation
		strcat_s(szBuff, FormatPercent(spelleffectname, -value, -finish, szTemp2));
		break;
	case SPA_WEAK_DEAD_2: //Army of Dead
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_APPRAISAL: //Appraisal
	case SPA_ZONE_SUSPEND_MINION: //Suspend Minion
	case SPA_TELEPORT_CASTERS_BINDPOINT: //Teleport Bind
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_FOCUS_REUSE_TIMER: //Reuse Timer
		strcat_s(szBuff, FormatTimer(spelleffectname, -base / 1000.0f, szTemp2));
		break;
	case SPA_FOCUS_COMBAT_SKILL: //No Combat Skills
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_OBSERVER: //Sanc
	case SPA_FORAGE_MASTER: //Forage Master (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_IMPROVED_INVIS: //Improved Invisibility
	case SPA_IMPROVED_INVIS_UNDEAD: //Improved Invisibility Vs Undead
	case SPA_IMPROVED_INVIS_ANIMALS: //Improved Invisibility Vs Animals (no spells currently)
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_INCREASE_WORN_HP_REGEN_CAP: //Worn Regen Cap
	case SPA_INCREASE_WORN_MANA_REGEN_CAP: //Worn Mana Cap
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_CRITICAL_HP_REGEN: //Critical HP Regen
	case SPA_SHIELD_BLOCK_CHANCE: //Shield Block Chance
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case SPA_REDUCE_TARGET_HATE: //Soothing
		strcat_s(szBuff, FormatBasePercent(spelleffectname, base, szTemp2));
		break;
	case SPA_GATE_STARTING_CITY: //Origin
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_DEFENSIVE_PROC: //Add Defensive Proc
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname, base, base2, szTemp), szTemp2));
		break;
	case SPA_HP_FOR_MANA: //Spirit Channel
		strcat_s(szBuff, FormatBasePercent(spelleffectname, base, szTemp2));
		break;
	case SPA_NO_BREAK_AE_SNEAK: //No Break AE Sneak (no spells currently)
	case SPA_ADD_SPELL_SLOTS: //Spell Slots (no spells currently)
	case SPA_ADD_BUFF_SLOTS: //Buff Slots (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_INCREASE_NEGATIVE_HP_LIMIT: //Negative HP Limit
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case SPA_MANA_ABSORB_PCT_DMG: //Mana Shield
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2, "up to", szPercent));
		break;
	case SPA_CRIT_ATTACK_MODIFIER: //Crit Damage
		strcat_s(szBuff, FormatSkills(spelleffectname, value, finish, base2, szTemp2));
		break;
	case SPA_FAIL_ALCHEMY_ITEM_RECOVERY: //Item Recovery
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_SUMMON_TO_CORPSE: //Summon to Corpse
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_DOOM_RUNE_EFFECT: //Trigger on fade
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Fade"));
		break;
	case SPA_NO_MOVE_HP: //Song DoT
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		strcat_s(szBuff, repeating);
		strcat_s(szBuff, " if target is not moving");
		break;
	case SPA_FOCUSED_IMMUNITY: //Fc_Immunity Focus
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_ILLUSIONARY_TARGET: //Illusionary Target (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_INCREASE_EXP_MOD: //Experience buff
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_EXPEDIENT_RECOVERY: //Expedient Recovery
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_FOCUS_CASTING_PROC: //Trigger DoT on cast
	case SPA_CHANCE_SPELL: //Trigger DD on cast
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatSpellChance(spelleffectname, base, base2, szTemp), szTemp2, " on Cast"));
		break;
	case SPA_WORN_ATTACK_CAP: //Worn Attack Cap
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case SPA_NO_PANIC: //Prevent Flee on Low Health
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_SPELL_INTERRUPT: //Spell Interrupt
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case SPA_ITEM_CHANNELING: //Item Channeling (no spells currently)
	case SPA_ASSASSINATE_MAX_LEVEL: //Assassinate Max (no spells currently)
	case SPA_HEADSHOT_MAX_LEVEL: //Headshot Max (no spells currently)
	case SPA_DOUBLE_RANGED_ATTACK: //Double Ranged Attack (no spells currently)
	case SPA_FOCUS_MANA_MIN: //Limit: Mana Min
	case SPA_INCREASE_SHIELD_DMG: //Increase Damage With Shield (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_MANABURN: //Manaburn
		strcat_s(szBuff, FormatCount(spelleffectname, value * 4, szTemp2, "for"));
		break;
	case SPA_SPAWN_INTERACTIVE_OBJECT: //Persistent Effect
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(id + (spellgroup ? 3 : 1)), szTemp2));
		break;
	case SPA_INCREASE_TRAP_COUNT: //Increase Trap Count
	case SPA_INCREASE_SOI_COUNT: //Increase SOI Count
	case SPA_DEACTIVATE_ALL_TRAPS: //Deactivate All Traps
	case SPA_LEARN_TRAP: //Learn Trap
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_CHANGE_TRIGGER_TYPE: //Change Trigger Type (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_FOCUS_MUTE: //Mute
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_INSTANT_MANA: //Mana/Max Mana
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case SPA_PASSIVE_SENSE_TRAP: //Passive Sense Trap
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_PROC_ON_KILL_SHOT: //Killshot Triggers
	case SPA_PROC_ON_DEATH: //Proc On Death
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatSpellChance(spelleffectname, base, base2, szTemp), szTemp2));
		break;
	case SPA_POTION_BELT: //Potion Belt (no spells currently)
	case SPA_BANDOLIER: //Bandolier (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_ADD_TRIPLE_ATTACK_CHANCE: //Triple Attack Chance
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_PROC_ON_SPELL_KILL_SHOT: //Trigger on Kill Shot
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatSpellChance(spelleffectname, base, base2, szTemp), szTemp2));
		break;
	case SPA_GROUP_SHIELDING: //Group Shielding
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_MODIFY_BODY_TYPE: //Change Body Type
		sprintf_s(szTemp, " to %s", base == 25 ? "Plant" : base == 21 ? "Animal" : base == 3 ? "Undead" : "Unknown");
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_MODIFY_FACTION: //Modify Faction
		strcat_s(szBuff, FormatExtra(spelleffectname, GetFactionName(base, szTemp), szTemp2));
		break;
	case SPA_CORRUPTION: //Corruption Counters
	case SPA_RESIST_CORRUPTION: //Corruption Resists
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case SPA_SLOW: //Slow
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_GRANT_FORAGING: //Grant Foraging (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_DOOM_ALWAYS: //Trigger Effect
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Fade"));
		break;
	case SPA_TRIGGER_SPELL: //Trigger Spell
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatSpellChance(spelleffectname, base, base2, szTemp), szTemp2));
		break;
	case SPA_CRIT_DOT_DMG_MOD: //Critical DoT Damage Mod
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_FLING: //Fling
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_DOOM_ENTITY: //Trigger Effect
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Fade"));
		break;
	case SPA_RESIST_OTHER_SPA: //Resist
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatResists(spelleffectname, base, base2, szTemp), szTemp2));
		break;
	case SPA_DIRECTIONAL_TELEPORT: //Directional Shadowstep
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case SPA_EXPLOSIVE_KNOCKBACK: //Knockback Explosive
		sprintf_s(szTemp, " (%d) and Toss Up (%d)", base, base2);
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_FLING_TOWARD: //Fling to Self
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_SUPPRESSION: //Negate: Effect
	{
		char szString[MAX_STRING] = { 0 };
		sprintf_s(szTemp, " %s Effect", GetSpellEffectNameByID(base2, szString, MAX_STRING));
		strcat_s(szBuff, FormatExtra(spelleffectname, szTemp, szTemp2));
		break;
	}
	case SPA_FOCUS_CASTING_PROC_NORMALIZED: //Trigger Spell
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatSpellChance(spelleffectname, base, base2, szTemp), szTemp2, " on Cast"));
		break;
	case SPA_FLING_AT: //Fling to Target
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_FOCUS_WHICH_GROUP: //Limit: SpellGroup
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameBySpellGroupID(base), szTemp2));
		break;
	case SPA_DOOM_DISPELLER: //Trigger Effect
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Curer"));
		break;
	case SPA_DOOM_DISPELLEE: //Trigger Effect
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Fade"));
		break;
	case SPA_SUMMON_ALL_CORPSES: //Summon All Corpses
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_REFRESH_SPELL_TIMER: //Spell Gem Refresh
		strcat_s(szBuff, FormatCount(spelleffectname, -value, szTemp2, "to"));
		break;
	case SPA_LOCKOUT_SPELL_TIMER: //Fc_Timer Lockout
	case SPA_FOCUS_MANA_MAX: //Limit: Mana Max
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_FOCUS_HEAL_AMT: //Heal Amt
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case SPA_FOCUS_HEAL_MOD_BENEFICIAL: //Incoming Healing Effectiveness
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_FOCUS_HEAL_AMT_BENEFICIAL: //Incoming Healing Amt
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case SPA_FOCUS_HEAL_MOD_CRIT: //Fc_Heal % Crit (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_FOCUS_HEAL_AMT_CRIT: //Heal Amt
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case SPA_ADD_PET_AC: //Pet Amt Mitigation (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_FOCUS_SWARM_PET_DURATION: //Swarm Pet Duration
		strcat_s(szBuff, FormatSecondsCount(spelleffectname, value / 1000.0f, szTemp2));
		break;
	case SPA_FOCUS_TWINCAST_CHANCE: //Twincast Chance
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_HEALBURN: //Healburn
		sprintf_s(szTemp, " use up to %d mana to heal your group", value);
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_MANA_IGNITE: //Mana/HP
	case SPA_ENDURANCE_IGNITE: //Endurance/HP
		strcat_s(szBuff, FormatCount(spelleffectname, -value, szTemp2, "by up to"));
		break;
	case SPA_FOCUS_SPELL_CLASS: //Limit: SpellClass
	case SPA_FOCUS_SPELL_SUBCLASS: //Limit: SpellSubclass
	case SPA_STAFF_BLOCK_CHANCE: //Staff Block Chance (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_DOOM_LIMIT_USE: //Trigger Effect
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Max Hits"));
		break;
	case SPA_DOOM_FOCUS_USED: //Trigger Effect
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Focus Used"));
		break;
	case SPA_LIMIT_HP: //Limit HP
	case SPA_LIMIT_MANA: //Limit Mana
	case SPA_LIMIT_ENDURANCE: //Limit Endurance
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2, "to"));
		break;
	case SPA_FOCUS_LIMIT_CLASS: //Limit: PlayerClass
		strcat_s(szBuff, FormatExtra(spelleffectname, GetClassesFromMask(base, szTemp), szTemp2));
		break;
	case SPA_FOCUS_LIMIT_RACE: //Limit: Race (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2)); // needs work (base2 bitmask of races)
		break;
	case SPA_FOCUS_BASE_EFFECTS: //Base Dmg
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2, "by", szPercent));
		break;
	case SPA_FOCUS_LIMIT_SKILL: //Limit: CastingSkill
	case SPA_FOCUS_LIMIT_ITEM_CLASS: //Limit: ItemClass (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_AC2: //AC2
	case SPA_MANA2: //Mana2
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case SPA_FOCUS_INCREASE_SKILL_DMG_2: //Increased Skill Damage2
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case SPA_PROC_EFFECT_2: //Add Proc
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname, base, base2, szTemp), szTemp2));
		break;
	case SPA_FOCUS_LIMIT_USE: //Fc_Limit Use (no spells currently)
	case SPA_FOCUS_LIMIT_USE_AMT: //Fc_Limit Use Amt (no spells currently)
	case SPA_FOCUS_LIMIT_USE_MIN: //Limit: Use Min (no spells currently)
	case SPA_FOCUS_LIMIT_USE_TYPE: //Limit: Use Type (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_GRAVITATE: //Gravitate
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case SPA_FLY: //Fly
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_ADD_EXTENDED_TARGET_SLOTS: //AddExtTargetSlots (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_SKILL_PROC: //Skill Proc
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname, base, base2, szTemp), szTemp2));
		break;
	case SPA_PROC_SKILL_MODIFIER: //Limit Skill
		strcat_s(szBuff, FormatExtra(spelleffectname, base >= 0 ? szSkills[base] : "All Skills", szTemp2));
		break;
	case SPA_SKILL_PROC_SUCCESS: //Skill Proc Success
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname, base, base2, szTemp), szTemp2));
		break;
	case SPA_POST_EFFECT: //PostEffect
	case SPA_POST_EFFECT_DATA: //PostEffectData
	case SPA_EXPAND_MAX_ACTIVE_TROPHY_BENEFITS: //ExpandMaxActiveTrophyBenefits (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_ADD_NORMALIZED_SKILL_MIN_DMG_AMT: //Skill Min Damage
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname, base, base2, szTemp), szTemp2));
		break;
	case SPA_ADD_NORMALIZED_SKILL_MIN_DMG_AMT_2: //Skill Min Damage
	case SPA_FRAGILE_DEFENSE: //Fragile Defense
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_FREEZE_BUFF_TIMER: //Beneficial Countdown Hold
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_TELEPORT_TO_ANCHOR: //Teleport to Anchor
	case SPA_TRANSLOCATE_TO_ANCHOR: //Translocate to Anchor
		sprintf_s(szTemp, " to %s Anchor", base == 50874 ? "Guild Hall" : base == 52584 ? "Primary" : base == 52585 ? "Secondary" : "Unknown");
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_ASSASSINATE: //Assassinate (no spells currently)
	case SPA_FINISHING_BLOW_MAX: //FinishingBlowMax (no spells currently)
	case SPA_DISTANCE_REMOVAL: //Distance Removal
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_REQUIRE_TARGET_DOOM: //Doom Req Target
	case SPA_REQUIRE_CASTER_DOOM: //Doom Req Caster
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2));
		if (base2) {
			GetSpellRestrictions(pSpell, i, szTemp, sizeof(szTemp));
			strcat_s(szBuff, " -- Restrictions: ");
			strcat_s(szBuff, szTemp);
		}
		break;
	case SPA_IMPROVED_TAUNT: //Improved Taunt
		sprintf_s(szTemp, " up to L%d and Reduce Ally Hate Generation by %d%s", base, base2, szPercent);
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_ADD_MERC_SLOT: //Add Merc Slot
	case SPA_STACKER_A: //A_Stacker
	case SPA_STACKER_B: //B_Stacker
	case SPA_STACKER_C: //C_Stacker
	case SPA_STACKER_D: //D_Stacker
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_DOT_GUARD: //DoT Guard
		sprintf_s(szTemp, " absorbing %d%s damage to a total of %d", value, szPercent, max);
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_MELEE_THRESHOLD_GUARD: //Melee Threshold Guard
	case SPA_SPELL_THRESHOLD_GUARD: //Spell Threshold Guard
		sprintf_s(szTemp, " absorbing %d%s of incoming %s damage in excess of %d to a total of %d", value, szPercent, spa == 451 ? "melee" : "spell", base2, max);
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_MELEE_THRESHOLD_DOOM: //Doom Melee Threshold
		sprintf_s(szTemp, " on %d Melee Damage Taken", base2);
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, szTemp));
		break;
	case SPA_SPELL_THRESHOLD_DOOM: //Doom Spell Threshold
		sprintf_s(szTemp, " on %d Spell Damage Taken", base2);
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, szTemp));
		break;
	case SPA_ADD_HATE_PCT: //Add Hate %
	case SPA_ADD_HATE_OVER_TIME_PCT: //Add Hate Over Time %
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_RESOURCE_TAP: //Resource Tap
		sprintf_s(szTemp, "Return %.2f%s of direct damage as %s", value / 10.0f, szPercent, base2 == 0 ? "hit points" : base2 == 1 ? "mana" : base2 == 2 ? "endurance" : "unknown");
		strcat_s(szBuff, szTemp);
		break;
	case SPA_FACTION_MOD: //Faction Mod %
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_SKILL_DAMAGE_MOD_2: //Damage Mod 2 (how to tell which, rogues get a backstab only, others get an all skills)
		strcat_s(szBuff, FormatSkills(spelleffectname, value, finish, base2, szTemp2));
		break;
	case SPA_OVERRIDE_NOT_FOCUSABLE: //Limit: Include Non-Focusable
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_FOCUS_DAMAGE_MOD_2: //Fc Damage % 2 (no spells currently)
	case SPA_FOCUS_DAMAGE_AMT_2: //Fc Damage Amt 2 (no spells currently)
	case SPA_SHIELD: //Shield Target (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_PC_PET_RAMPAGE: //PC Pet Rampage
	case SPA_PC_PET_AE_RAMPAGE: //PC Pet AE Rampage
	case SPA_PC_PET_FLURRY: //PC Pet Flurry Chance
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_DAMAGE_SHIELD_MITIGATION_AMT: //DS Mitigation Amt
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_DAMAGE_SHIELD_MITIGATION_PCT: //DS Mitigation Percentage
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_CHANCE_BEST_IN_SPELL_GROUP: //Chance Best in Spell Group
	case SPA_TRIGGER_BEST_IN_SPELL_GROUP: //Trigger Best in Spell Group
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatSpellGroupChance(spelleffectname, base, base2, szTemp), szTemp2, " on Cast"));
		break;
	case SPA_DOUBLE_MELEE_ATTACKS: //Double Melee Round (PC Only)
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_AA_BUY_NEXT_RANK: //Toggle Passive AA Rank
		strcat_s(szBuff, spelleffectname);
		break;
	case SPA_DOUBLE_BACKSTAB_FRONT: //Double Backstab From Front  (no spells currently)
	case SPA_PET_MELEE_CRIT_DMG_MOD: //Pet Crit Melee Damage% (Owner)  (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_TRIGGER_SPELL_NON_ITEM: //Trigger Spell Non-Item
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Cast"));
		break;
	case SPA_WEAPON_STANCE: //Weapon Stance (no spells currently)
	case SPA_HATELIST_TO_TOP: //Move to Top of Hatelist (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_HATELIST_TO_TAIL: //Move to Bottom of Hatelist
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Cast"));
		break;
	case SPA_FOCUS_LIMIT_MIN_VALUE: //Value Min
		sprintf_s(szTemp, "%s %s", spelleffectname, base < 0 ? "Max" : "Min");
		strcat_s(szBuff, FormatMinMaxBase(szTemp, base, base2, szTemp2));
		break;
	case SPA_FOCUS_LIMIT_MAX_VALUE: //Value Max
		sprintf_s(szTemp, "%s %s", spelleffectname, base < 0 ? "Min" : "Max");
		strcat_s(szBuff, FormatMinMaxBase(szTemp, base, base2, szTemp2));
		break;
	case SPA_FOCUS_CAST_SPELL_ON_LAND: //Cast Spell on Land
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base2), szTemp2, " on Land and conditions are met"));
		break;
	case SPA_SKILL_BASE_DAMAGE_MOD: //Skill Base Damage Mod
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_FOCUS_INCOMING_DMG_MOD: //Spell Damage Taken
	case SPA_FOCUS_INCOMING_DMG_AMT: //Spell Damage Taken
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2, " (after crit)"));
		break;
	case SPA_FOCUS_LIMIT_CASTER_CLASS: //CasterClass
		strcat_s(szBuff, FormatExtra(spelleffectname, GetClassesFromMask(base, szTemp), szTemp2));
		break;
	case SPA_FOCUS_LIMIT_SAME_CASTER: //Same Caster
		strcat_s(szBuff, FormatExtra(spelleffectname, base ? "(Same)" : "(Different)", szTemp2, "", ""));
		break;
	case SPA_EXTEND_TRADESKILL_CAP: //Extend Tradeskill Cap
		sprintf_s(szTemp, "%s (%d, %d, %d)", spelleffectname, base, base2, max);
		strcat_s(szBuff, szTemp);
		break;
	case SPA_DEFENDER_MELEE_FORCE_PCT: //Push Taken
		strcat_s(szBuff, FormatBase(spelleffectname, -base, szTemp2));
		break;
	case SPA_WORN_ENDURANCE_REGEN_CAP: //Worn Endurance Regen Cap
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case SPA_FOCUS_MIN_REUSE_TIME: //Limit: ReuseTime Min
	case SPA_FOCUS_MAX_REUSE_TIME: //Limit: ReuseTime Max
		strcat_s(szBuff, FormatSeconds(spelleffectname, value / 1000.0f, szTemp2));
		break;
	case SPA_FOCUS_ENDURANCE_MIN: //Limit: Endurance Min
	case SPA_FOCUS_ENDURANCE_MAX: //Limit: Endurance Max
	case SPA_PET_ADD_ATK: //Pet Add Attack
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case SPA_FOCUS_DURATION_MAX: //Limit: Duration Max
		strcat_s(szBuff, FormatSeconds(spelleffectname, value * 6, szTemp2));
		break;
	case SPA_CRIT_MELEE_DMG_MOD_MAX: //Critical Hit Damage (Non-stacking)
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		strcat_s(szBuff, " of Base Damage (Non Stacking)");
		break;
	case SPA_FOCUS_CAST_PROC_NO_BYPASS: //NoProc
		sprintf_s(szTemp, "%s (%d, %d, %d)", spelleffectname, base, base2, max);
		strcat_s(szBuff, szTemp);
		break;
	case SPA_ADD_EXTRA_PRIMARY_ATTACK_PCT: //Extra Attack % (1H Primary)
	case SPA_ADD_EXTRA_SECONDARY_ATTACK_PCT: //Extra Attack % (1H Secondary)
	case SPA_FOCUS_CAST_TIME_MOD2: //Spell Haste v2
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_FOCUS_CAST_TIME_AMT: //Spell Cast Time
	case SPA_FEARSTUN: //Stun and Fear
		strcat_s(szBuff, FormatSeconds(spelleffectname, value / 1000.0f, szTemp2));
		break;
	case SPA_MELEE_DMG_POSITION_MOD: //Rear Arc Melee Damage Mod
		strcat_s(szBuff, FormatSeconds(spelleffectname, value / 10.0f, szTemp2));
		break;
	case SPA_MELEE_DMG_POSITION_AMT: //Rear Arc Melee Damage
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case SPA_DMG_TAKEN_POSITION_MOD: //Rear Arc Damage Taken Mod
		strcat_s(szBuff, FormatSeconds(spelleffectname, value / 10.0f, szTemp2));
		break;
	case SPA_DMG_TAKEN_POSITION_AMT: //Rear Arc Damage Taken
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case SPA_AMPLIFY_MOD: //Spell Damage v4 Mod
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		strcat_s(szBuff, " (Before DoT Crit, After Nuke Crit)");
		break;
	case SPA_AMPLIFY_AMT: //Spell Damage v4
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case SPA_HEALTH_TRANSFER: //Health Transfer
		sprintf_s(szTemp, "%s (%d, %d, %d)", spelleffectname, base, base2, max);
		strcat_s(szBuff, szTemp);
		break;
	case SPA_FOCUS_RESIST_INCOMING: //Resist Incoming
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case SPA_ATTACK_ACCURACY_MAX: //Attack Accuracy Max Percent
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case SPA_FOCUS_TIMER_MIN: //Focus Timer Min
	case SPA_PROC_TIMER_MOD: //Proc Timer Modifier
	case SPA_MANA_MAX: //Mana Max Percent
	case SPA_ENDURANCE_MAX: //Endurance Max Percent
	case SPA_AC_AVOIDANCE_MAX: //AC Avoidance Max Percent
	case SPA_AC_MITIGATION_MAX: //AC Mitigation Max Percent
	case SPA_ATTACK_OFFENSE_MAX: //Attack Offense Max Percent
	case SPA_LUCK_AMT: //Luck Amt
	case SPA_LUCK_PCT: //Luck Percent
	default: //undefined effect
		sprintf_s(szTemp, "%s (base=%d, base2=%d, max=%d, calc=%d, value=%d)", spelleffectname, base, base2, max, calc, value);
		strcat_s(szBuff, szTemp);
		break;
	}

#ifdef DEBUGSPELLS
	if (strlen(szBuff) > 0) WriteChatf("%s", szBuff);
#endif
	strcat_s(szBuffer, BufferSize, szBuff);
	return szBuffer;
}

char* ShowSpellSlotInfo(SPELL* pSpell, char* szBuffer, size_t BufferSize)
{
	char szTemp[MAX_STRING] = { 0 };
	char szBuff[MAX_STRING] = { 0 };
	int count = 0;
	for (int i = 0; i < GetSpellNumEffects(pSpell); i++)
	{
		szBuff[0] = szTemp[0] = '\0';
		strcat_s(szBuff, ParseSpellEffect(pSpell, i, szTemp, sizeof(szTemp)));
		size_t len = strlen(szBuff);
		if (len > 0 && count + len < BufferSize) {
			strcat_s(szBuffer, BufferSize, szBuff);
			strcat_s(szBuffer, BufferSize, "<br>");
		}
		count += len + 4;
	}
	return szBuffer;
}

void SlotValueCalculate(char* szBuff, SPELL* pSpell, int i, double mp)
{
	sprintf_s(szBuff, 12, "%d",
		CalcValue(GetSpellCalc(pSpell, i), GetSpellBase(pSpell, i), GetSpellMax(pSpell, i), pSpell->DurationCap));
}

int GetSpellCounters(eEQSPA spellAffect, const SPELLBUFF* buff)
{
	if (!buff)
		return 0;

	int count = 0;

	SPELL* pSpell = GetSpellByID(buff->SpellID);
	if (!pSpell || pSpell->SpellType != SpellType_Detrimental)
		return 0;

	int slots = GetSpellNumEffects(pSpell);

	for (int i = 0; i < slots; i++)
	{
		int attrib = GetSpellAttrib(pSpell, i);

		if (attrib == spellAffect)
		{
			for (auto& slotData : buff->SlotData)
			{
				if (slotData.Slot == i)
				{
					count += slotData.Value;
				}
			}
		}
	}

	return count;
}

int GetMySpellCounters(eEQSPA spellAffect)
{
	const PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return 0;

	int count = 0;

	for (const auto& buff : pProfile->Buff)
	{
		count += GetSpellCounters(spellAffect, &buff);
	}

	for (const auto& buff : pProfile->ShortBuff)
	{
		count += GetSpellCounters(spellAffect, &buff);
	}

	return count;
}

int GetTotalSpellCounters(const SPELLBUFF* buff)
{
	if (!buff)
		return 0;

	int count = 0;

	SPELL* pSpell = GetSpellByID(buff->SpellID);
	if (!pSpell || pSpell->SpellType != SpellType_Detrimental)
		return 0;

	int slots = GetSpellNumEffects(pSpell);

	for (int i = 0; i < slots; i++)
	{
		int attrib = GetSpellAttrib(pSpell, i);

		if (IsSpellCountersSPA(attrib))
		{
			for (auto& slotData : buff->SlotData)
			{
				if (slotData.Slot == i)
				{
					count += slotData.Value;
				}
			}
		}
	}

	return count;
}


int GetMyTotalSpellCounters()
{
	const PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return 0;

	int total = 0;

	for (const auto& buff : pProfile->Buff)
	{
		total += GetTotalSpellCounters(&buff);
	}

	for (const auto& buff : pProfile->ShortBuff)
	{
		total += GetTotalSpellCounters(&buff);
	}

	return total;
}

int GetTriggerSPA(SPELL* pSpell)
{
	eEQSPA SPAtoCheck[] = {
		SPA_TRIGGER_BEST_IN_SPELL_GROUP,
		SPA_TRIGGER_SPELL
	};

	for (eEQSPA spa : SPAtoCheck)
	{
		if (IsSPAEffect(pSpell, spa))
			return spa;
	}

	return 0;
}

int GetMeleeSpeedFromTriggers(SPELL* pSpell, bool bIncrease)
{
	int triggerSPA = GetTriggerSPA(pSpell);
	if (triggerSPA == 0)
		return 0;

	int result = 0;

	int numEffects = GetSpellNumEffects(pSpell);
	for (int index = 0; index < numEffects; index++)
	{
		if (int groupId = GetSpellBase2(pSpell, index))
		{
			SPELL* pTrigger = nullptr;

			switch (triggerSPA)
			{
			case SPA_TRIGGER_BEST_IN_SPELL_GROUP:
				pTrigger = GetHighestLearnedSpellByGroupID(groupId);
				if (!pTrigger)
				{
					pTrigger = GetHighestLearnedSpellByGroupID(groupId);
				}
				break;

			case SPA_TRIGGER_SPELL:
				pTrigger = pSpellMgr->GetSpellByID(groupId);
				break;

			default:
				break; // should not be reachable if we handled everything GetTriggerSPA returns
			}

			if (pTrigger
				&& !ci_equals(pTrigger->Name, "Unknown Spell")
				&& !ci_equals(pTrigger->Name, pSpell->Name))
			{
				result = std::max(GetMeleeSpeedPctFromSpell(pTrigger, bIncrease), result);
			}
		}
	}

	return result;
}

int GetMeleeSpeedPctFromSpell(SPELL* pSpell, bool bIncrease)
{
	if (GetTriggerSPA(pSpell) != 0)
	{
		return GetMeleeSpeedFromTriggers(pSpell, bIncrease);
	}

	if (!pLocalPlayer)
		return 0;
	SPAWNINFO* pSpawn = pLocalPlayer;

	int numEffects = pSpell->NumEffects;
	for (int index = 0; index < numEffects; index++)
	{
		int spa = GetSpellAttrib(pSpell, index);
		if (spa == SPA_HASTE)
		{
			int base = GetSpellBase(pSpell, index) - 100;
			if ((!bIncrease && base < 0) || (bIncrease && base > 0))
			{
				int max = GetSpellMax(pSpell, index) - 100;
				int calc = GetSpellCalc(pSpell, index);
				int minSpellLevel = CalcMinSpellLevel(pSpell);

				int finish = CalcValue(calc, base, max, 0, minSpellLevel, pSpawn->Level);
				return abs(finish);
			}
		}
	}

	return 0;
}

} // namespace mq
