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

#include "MQ2Main.h"


static SPELL* GetSpellBySpellGroupID(int dwSpellGroupID)
{
	if (!ppSpellMgr) return nullptr;

	for (int dwSpellID = 0; dwSpellID < TOTAL_SPELL_COUNT; dwSpellID++)
	{
		if (SPELL* pSpell = GetSpellByID(dwSpellID))
		{
			if (pSpell->ID > 0 && pSpell->SpellGroup == dwSpellGroupID)
			{
				return pSpell;
			}
		}
	}

	return nullptr;
}

static const char* GetSpellNameBySpellGroupID(int dwSpellID)
{
	SPELL* pSpell = GetSpellBySpellGroupID(abs(dwSpellID));

	if (pSpell && pSpell->Name && pSpell->Name[0] != 0)
	{
		return pSpell->Name;
	}

	return "Unknown Spell";
}

const char* GetSpellNameByID(int dwSpellID)
{
	int absedspellid = abs(dwSpellID);

	if (ppSpellMgr && absedspellid != 0 && absedspellid != -1 && absedspellid < TOTAL_SPELL_COUNT)
	{
		SPELL* pSpell = GetSpellByID(absedspellid);

		if (pSpell && pSpell->Name && pSpell->Name[0] != 0)
		{
			return pSpell->Name;
		}
	}

	return "Unknown Spell";
}

struct SpellCompare
{
	std::map<int, SPELL*> Duplicates;
};

std::map<std::string, std::map<std::string, SpellCompare>> s_spellNameMap;
std::map<int, int> s_triggeredSpells;
std::mutex s_initializeSpellsMutex;

bool IsRecursiveEffect2(int spa)
{
	switch (spa)
	{
	case 374:
	case 475:
	case 340:
	case 470:
	case 469:
		return true;
	}
	return false;
}

static void PopulateTriggeredmap(SPELL* pSpell)
{
	if (pSpell->CannotBeScribed == 1)
		return;

	int slots = GetSpellNumEffects(pSpell);

	for (int i = 0; i < slots; i++)
	{
		int attrib = GetSpellAttrib(pSpell, i);

		if (IsRecursiveEffect2(attrib))
		{
			if (int triggeredSpellId = GetSpellBase2(pSpell, i))
			{
				s_triggeredSpells[triggeredSpellId] = pSpell->ID;
			}
		}
	}
}

SPELL* GetSpellParent(int id)
{
	auto iter = s_triggeredSpells.find(id);
	if (iter != s_triggeredSpells.end())
	{
		return GetSpellByID(iter->second);
	}

	return nullptr;
}

void PopulateSpellMap()
{
	std::scoped_lock lock(s_initializeSpellsMutex);

	gbSpelldbLoaded = false;
	s_triggeredSpells.clear();
	s_spellNameMap.clear();

	for (int dwSpellID = 0; dwSpellID < TOTAL_SPELL_COUNT; dwSpellID++)
	{
		if (SPELL* pSpell = pSpellMgr->Spells[dwSpellID])
		{
			if (pSpell->Name[0] != '\0')
			{
				PopulateTriggeredmap(pSpell);

				std::string lowname = pSpell->Name;
				MakeLower(lowname);

				std::string threelow = lowname;
				threelow.erase(3);

				s_spellNameMap[threelow][lowname].Duplicates[dwSpellID] = pSpell;
			}
		}
	}

	gbSpelldbLoaded = true;
}

DWORD CALLBACK InitializeMQ2SpellDb(void* pData)
{
	int state = reinterpret_cast<int>(pData);

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
	PopulateSpellMap();

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

SPELL* GetSpellByName(const char* szName)
{
	// SPELL* GetSpellByName(char* NameOrID)
	// This function now accepts SpellID as an argument as well as SpellName
	// /echo ${Spell[Concussive Burst].Level}
	// /echo ${Spell[Nature's Serenity].Level}

	if (ppSpellMgr == nullptr) // no spellMgr offset?
		return nullptr;
	if (szName == nullptr)     // no spell name?
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

	if (szName[0] >= '0' && szName[0] <= '9')
	{
		return GetSpellByID(abs(atoi(szName)));
	}

	// is this even necessary?
	CHARINFO2* profile = GetCharInfo2();
	if (!profile)
		return nullptr;

	std::string lowname = szName;
	if (lowname.size() < 3 || s_spellNameMap.empty())
		return nullptr;

	MakeLower(lowname);

	std::string threelow = lowname;
	threelow.erase(3);

	// look up threelow
	auto iter = s_spellNameMap.find(threelow);
	if (iter == s_spellNameMap.end())
		return nullptr;

	// look up lowname
	std::map<std::string, SpellCompare>& spellLookup = iter->second;
	auto iter2 = spellLookup.find(lowname);
	if (iter2 == spellLookup.end())
		return nullptr;

	SpellCompare& comp = iter2->second;
	if (comp.Duplicates.empty())
		return nullptr;

	SPELL* pSpell = comp.Duplicates.begin()->second;
	if (comp.Duplicates.size() == 1)
	{
		return pSpell;
	}

	int highestclasslevel = 0;
	int classlevel = 0;
	int playerclass = profile->Class;
	int currlevel = profile->Level;

	if (playerclass && playerclass >= Warrior && playerclass <= Berserker)
	{
		for (auto& duplicate : iter2->second.Duplicates)
		{
			if (SPELL* dupeSpell = duplicate.second)
			{
				classlevel = dupeSpell->ClassLevel[playerclass];

				if (classlevel <= currlevel && highestclasslevel < classlevel)
				{
					highestclasslevel = classlevel;
					pSpell = dupeSpell;
				}
			}
		}
	}

	if (highestclasslevel == 0)
	{
		// if we got here, the spell the user is after isnt one his character can cast, so
		// we will have to roll through it again and see if its usable by any other class

		for (auto& duplicate : iter2->second.Duplicates)
		{
			SPELL* dupeSpell = duplicate.second;
			if (dupeSpell && IsSpellClassUsable(dupeSpell))
			{
				pSpell = dupeSpell;
			}
		}
	}

	return nullptr;
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
	case 1: strcat_s(szBuffer, "Magic"); break;
	case 2: strcat_s(szBuffer, "Fire"); break;
	case 3: strcat_s(szBuffer, "Cold/Ice"); break;
	case 4: strcat_s(szBuffer, "Poison"); break;
	case 5: strcat_s(szBuffer, "Disease"); break;
	case 6: strcat_s(szBuffer, "Chromatic"); break;
	case 7: strcat_s(szBuffer, "Prismatic"); break;
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
	case 0: strcat_s(szBuffer, "Detrimental only"); break;
	case 1: strcat_s(szBuffer, "Beneficial only"); break;
	case 2: strcat_s(szBuffer, "Beneficial - Group Only"); break;
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
	case CALC_1TICK:
		sprintf_s(szBuffer, BufferSize, " (%s to %d @ 1/tick)", type, finish);
		break;
	case CALC_2TICK:
		sprintf_s(szBuffer, BufferSize, " (%s to %d @ 2/tick)", type, finish);
		break;
	case CALC_5TICK:
		sprintf_s(szBuffer, BufferSize, " (%s to %d @ 5/tick)", type, finish);
		break;
	case CALC_12TICK:
		sprintf_s(szBuffer, BufferSize, " (%s to %d @ 12/tick)", type, finish);
		break;
	case CALC_RANDOM:
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
	case CALC_RANDOM:
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
	case SPA_PLAYERSIZE:
	case SPA_BARDOVERHASTE: //Adjust for Base=100
		base -= 100;
		max -= 100;
		break;
	case SPA_SUMMONCORPSE: //Adjust for base/max swapped
		max = base;
		base = 0;
		break;
	case SPA_SPELLDAMAGE:
	case SPA_HEALING:
	case SPA_SPELLMANACOST: //Adjust for base2 used as max
		max = base2;
		break;
	case SPA_REAGENTCHANCE:
	case SPA_INCSPELLDMG: //Adjust for base2 used as base
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
	int finish = CalcValue(calc, (spa == SPA_SPELLDAMAGETAKEN) ? base2 : base, max, ticks, minspelllvl, level);

	bool usePercent = (spa == SPA_MOVEMENTRATE || spa == SPA_HASTE || spa == SPA_BARDOVERHASTE || spa == SPA_SPELLDAMAGE || spa == SPA_HEALING || spa == SPA_DOUBLEATTACK || spa == SPA_STUNRESIST || spa == SPA_PROCMOD ||
		spa == SPA_DIVINEREZ || spa == SPA_METABOLISM || spa == SPA_TRIPLEBACKSTAB || spa == SPA_DOTCRIT || spa == SPA_HEALCRIT || spa == SPA_MENDCRIT || spa == SPA_FLURRY || spa == SPA_PETFLURRY ||
		spa == SPA_SPELLCRITCHANCE || spa == SPA_SHIELDBLOCKCHANCE || spa == SPA_DAMAGECRITMOD || spa == SPA_SPELLDAMAGETAKEN);
	bool AEEffect = (targettype == TT_PBAE || targettype == TT_TARGETED_AE || targettype == TT_AE_PC_V2 || targettype == TT_DIRECTIONAL);

	strcat_s(range, CalcValueRange(calc, base, max, ticks, minspelllvl, level, szTemp2, sizeof(szTemp2), usePercent ? szPercent : ""));
	strcat_s(extendedrange, CalcExtendedRange(calc, value, finish, minspelllvl, maxspelllvl, szTemp2, sizeof(szTemp2), usePercent ? szPercent : "", (spa == SPA_AC || spa == SPA_AC2)));
	if (ticks) sprintf_s(repeating, " per tick ");
	if (max) sprintf_s(maxlevel, " up to level %d", max);
	if (targets && AEEffect) sprintf_s(maxtargets, " on up to %d enemies", targets);

#ifdef DEBUGSPELLS
	WriteChatf("SLOT:%d, SPA:%d, BASE:%d, BASE2:%d, MAX:%d, CALC:%d, TICKS:%d, VALUE:%d, FINISH:%d, MINSPELLLVL:%d, MAXSPELLLVL:%d, RANGE:%s, EXTENDEDRANGE:%s, USEPERCENT:%s, REPEATING:%s, MAXLEVEL:%s",
		i + 1, spa, base, base2, max, calc, ticks, value, finish, minspelllvl, maxspelllvl, range, extendedrange, usePercent ? "true" : "false", repeating, maxlevel);
#endif

	sprintf_s(szBuff, "Slot %d: ", i + 1);
	switch (spa)
	{
	case 0: //hp +/-: heals/regen/dd
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		if (strlen(repeating)) strcat_s(szBuff, repeating);

		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		if (base2) {
			GetSpellRestrictions(pSpell, i, szTemp, sizeof(szTemp));
			strcat_s(szBuff, " -- Restrictions: ");
			strcat_s(szBuff, szTemp);
		}
		break;
	case 1: //ac mod
	case 2: //attack mod
	case 3: //movement speed mod
	case 4: //str mod
	case 5: //dex mod
	case 6: //agi mod
	case 7: //sta mod
	case 8: //int mod
	case 9: //wis mod
	case 10: //cha mod
	case 11: //haste mod
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case 12: //Invisibility
		strcat_s(szBuff, spelleffectname);
		break;
	case 13: //See Invisible(c)
	case 14: //Water Breathing(c)
		strcat_s(szBuff, FormatBase(spelleffectname, value, szTemp2));
		break;
	case 15: //mana +/-
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		if (strlen(repeating)) strcat_s(szBuff, repeating);
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		if (base2) {
			GetSpellRestrictions(pSpell, i, szTemp, sizeof(szTemp));
			strcat_s(szBuff, " -- Restrictions: ");
			strcat_s(szBuff, szTemp);
		}
		break;
	case 16: //NPC Frenzy (no spells currently)
	case 17: //NPC Awareness (no spells currently)
	case 18: //NPC Aggro
		strcat_s(szBuff, spelleffectname);
		break;
	case 19: //NPC Faction
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case 20: //Blindness
		strcat_s(szBuff, spelleffectname);
		break;
	case 21: //stun  time = base in ms
		if (base2 != 0 && base != base2)
			sprintf_s(szTemp, " NPC for %1.fs (PC for %1.fs)%s", base / 1000.0f, base2 / 1000.0f, maxlevel);
		else
			sprintf_s(szTemp, " for %1.fs%s", base / 1000.0f, maxlevel);
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case 22: //Charm(c/level)
	case 23: //Fear(c/level)
		strcat_s(szBuff, FormatString(spelleffectname, maxlevel, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case 24: //Fatigue
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case 25: //Bind Affinity
		if (base == 2)
			strcat_s(szTemp, " (Secondary Bind Point)");
		if (base == 3)
			strcat_s(szTemp, " (Tertiary Bind Point)");
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case 26: //Gate
		if (base == 2)
			strcat_s(szTemp, " to Secondary Bind Point");
		if (base == 3)
			strcat_s(szTemp, " (Tertiary Bind Point)");
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case 27: //Cancel Magic(c)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 28: //Invisibility versus Undead
	case 29: //Invisibility versus Animal
		strcat_s(szBuff, spelleffectname);
		break;
	case 30: //NPC Aggro Radius(c/level)
			 // NPC Aggro Radius' use the reverse sign from normal base values
		strcat_s(szBuff, FormatCount(spelleffectname, -value, szTemp2));
		strcat_s(szBuff, maxlevel);
		break;
	case 31: //Mesmerize(c/level)
		strcat_s(szBuff, FormatString(spelleffectname, maxlevel, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case 32: //Create Item
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
	case 33: //Summon Pet
		strcat_s(szBuff, FormatExtra(spelleffectname, extra, szTemp2));
		break;
	case 34: //Confuse
		strcat_s(szBuff, spelleffectname);
		break;
	case 35: //disease counters
	case 36: //poison counters
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case 37: //DetectHostile (no spells currently)
	case 38: //DetectMagic (no spells currently)
	case 39: //No Twincast
	case 40: //Invulnerability
	case 41: //Banish
	case 42: //Shadow Step
	case 43: //Berserk
	case 44: //Lycanthropy
	case 45: //Vampirism
		strcat_s(szBuff, spelleffectname);
		break;
	case 46: //fire resist
	case 47: //cold resist
	case 48: //poison resist
	case 49: //disease resist
	case 50: //magic resist
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case 51: //Detect Traps (no spells currently)
	case 52: //Sense Undead
	case 53: //Sense Summoned
	case 54: //Sense Animals
		strcat_s(szBuff, spelleffectname);
		break;
	case 55: //most runes
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case 56: //True North
		strcat_s(szBuff, spelleffectname);
		break;
	case 57: //Levitate(c)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 58: //Illusion: Base=Race
		strcat_s(szBuff, FormatExtra(spelleffectname, pEverQuest->GetRaceDesc(base), szTemp2));
		break;
	case 59: //Damage Shield
			 // Damage Shield's use the reverse sign from normal base values
		strcat_s(szBuff, FormatRange(spelleffectname, -value, extendedrange, szTemp2));
		break;
	case 60: //Transfer Item (no spells currently)
	case 61: //Identify
	case 62: //Item ID (no spells currently)
		strcat_s(szBuff, spelleffectname);
		break;
	case 63: //Memblur e%
		strcat_s(szBuff, FormatPenaltyChance(spelleffectname, value + 40, szTemp2, szPercent, "Chance"));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case 64: //SpinStun
	case 65: //Infravision
	case 66: //ultravision
	case 67: //Eye of Zomm
	case 68: //Reclaim Energy
		strcat_s(szBuff, spelleffectname);
		break;
	case 69: //max hp mod
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case 70: //CorpseBomb (no spells currently)
		strcat_s(szBuff, spelleffectname);
		break;
	case 71: //Create Undead Pet
		strcat_s(szBuff, FormatExtra(spelleffectname, extra, szTemp2));
		break;
	case 72: //Preserve Corpse (no spells currently)
	case 73: //Bind Sight
		strcat_s(szBuff, spelleffectname);
		break;
	case 74: //Feign Death
		strcat_s(szBuff, FormatPenaltyChance(spelleffectname, value, szTemp2, szPercent, "Chance"));
		break;
	case 75: //Voice Graft
	case 76: //Sentinel
	case 77: //Locate Corpse
		strcat_s(szBuff, spelleffectname);
		break;
	case 78: //Absorb Magic Damage
	case 79: //+hp when cast (priest buffs that have heal component, DoTs with DDs)
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case 80: //Enchant:Light (no spells currently)
		strcat_s(szBuff, spelleffectname);
		break;
	case 81: //Resurrect
		sprintf_s(szTemp, " and restore %d%s experience", value, szPercent);
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case 82: //Summon Player
		strcat_s(szBuff, spelleffectname);
		break;
	case 83: //zone portal spells
		if (targettype == 6) {
			sprintf_s(szTemp, " Self to %d, %d, %d in %s facing %s", GetSpellBase(pSpell, 0), GetSpellBase(pSpell, 1), GetSpellBase(pSpell, 2), GetFullZone(GetZoneID(extra)), szHeadingNormal[EQHeading(GetSpellBase(pSpell, 3))]);
		}
		else {
			sprintf_s(szTemp, " Group to %d, %d, %d in %s facing %s", GetSpellBase(pSpell, 0), GetSpellBase(pSpell, 1), GetSpellBase(pSpell, 2), GetFullZone(GetZoneID(extra)), szHeadingNormal[EQHeading(GetSpellBase(pSpell, 3))]);
		}
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case 84: //Toss on Z axis
		strcat_s(szBuff, FormatBase(spelleffectname, abs(base), base >= 0 ? " Down" : " Up", szTemp2));
		break;
	case 85: //Add Proc
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname, base, base2, szTemp), szTemp2));
		break;
	case 86: //Reaction Radius(c/level)
			 // Reaction Radius' use the reverse sign from normal base values
		strcat_s(szBuff, FormatCount(spelleffectname, -value, szTemp2));
		strcat_s(szBuff, maxlevel);
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case 87: //Perspective Magnification
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 88: //evac portal spells
		sprintf_s(szTemp, " to %d, %d, %d in %s facing %s", GetSpellBase(pSpell, 0), GetSpellBase(pSpell, 1), GetSpellBase(pSpell, 2), extra, szHeadingNormal[EQHeading(GetSpellBase(pSpell, 3))]);
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case 89: //Player Size
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 90: //Cloak
	case 91: //Summon Corpse
		strcat_s(szBuff, FormatString(spelleffectname, maxlevel, szTemp2));
		break;
	case 92: //hate mod
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case 93: //Stop Rain
	case 94: //Make Fragile
	case 95: //Sacrifice
		strcat_s(szBuff, spelleffectname);
		break;
	case 96: //Silence (no PC spells currently)
		strcat_s(szBuff, spelleffectname);
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case 97: //Mana Pool
	case 98: //Haste v2
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case 99: //Root
		strcat_s(szBuff, spelleffectname);
		break;
	case 100: //hp mod: pet heals/regen
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		strcat_s(szBuff, repeating);
		break;
	case 101: //Complete Heal (with duration)
	case 102: //Fearless
	case 103: //Call Pet
		strcat_s(szBuff, spelleffectname);
		break;
	case 104: //zone translocate spells
		if (extra[0])
			if (extra[0] == '0')
				strcat_s(szTemp, " to Bind Point");
			else
				sprintf_s(szTemp, " to %d, %d, %d in %s facing %s", GetSpellBase(pSpell, 0), GetSpellBase(pSpell, 1), GetSpellBase(pSpell, 2), GetFullZone(GetZoneID(extra)), szHeadingNormal[EQHeading(GetSpellBase(pSpell, 3))]);
		else
			strcat_s(szTemp, " to Bind Point");
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case 105: //Anti-Gate
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 106: //Summon Warder
		strcat_s(szBuff, FormatExtra(spelleffectname, extra, szTemp2));
		break;
	case 107: //Alter NPC Level (no spells currently)
		strcat_s(szBuff, spelleffectname);
		break;
	case 108: //Summon Familiar
		strcat_s(szBuff, FormatExtra(spelleffectname, extra, szTemp2));
		break;
	case 109: //Summon Into Bag
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
	case 110: //Increase Archery (no spells currently)
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case 111: //Resistances
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case 112: //Casting Level
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case 113: //Summon Mount
		strcat_s(szBuff, FormatExtra(spelleffectname, extra, szTemp2));
		break;
	case 114: //aggro multiplier
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 115: //Food/Water
		strcat_s(szBuff, spelleffectname);
		break;
	case 116: //curse counters
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case 117: //Make Weapons Magical
		strcat_s(szBuff, spelleffectname);
		break;
	case 118: //Singing Skill
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case 119: //Bard Overhaste
	case 120: //Reduce Healing Effectiveness (%)
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 121: //Reverse Damage Shield
		strcat_s(szBuff, FormatBase(spelleffectname, -base, szTemp2));
		break;
	case 122: //Reduce Skill
		strcat_s(szBuff, FormatSkills(spelleffectname, value, finish, base2, szTemp2));
		break;
	case 123: //Immunity
		strcat_s(szBuff, spelleffectname);
		break;
	case 124: //spell damage
	case 125: //healing
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 126: //spell resist rate
	case 127: //spell haste
		strcat_s(szBuff, FormatPercent(spelleffectname, -value, -finish, szTemp2));
		break;
	case 128: //spell duration
	case 129: //spell range
	case 130: //spell/bash hate
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 131: //Decrease Chance of Using Reagent
	case 132: //Spell Mana Cost
	case 133: //Spell Stun Duration (no spells currently)
		strcat_s(szBuff, FormatPercent(spelleffectname, -value, -finish, szTemp2));
		break;
	case 134: //limit max level
		if (base2 > 0)
			sprintf_s(szTemp, "%s (%d) (lose %d%s per level over cap)", spelleffectname, base, base2, szPercent);
		else
			strcpy_s(szTemp, FormatBase(spelleffectname, base, szTemp2));
		strcat_s(szBuff, szTemp);
		break;
	case 135: //Limit: Resist
		strcat_s(szBuff, FormatLimits(spelleffectname, value, GetResistTypeName(base, szTemp), szTemp2));
		break;
	case 136: //limit target types this affects
		strcat_s(szBuff, FormatLimits(spelleffectname, value, GetTargetTypeLimitsName(base, szTemp), szTemp2));
		break;
	case 137: //limit effect types this affects
		strcat_s(szBuff, FormatLimits(spelleffectname, value, GetSpellEffectName(base, szTemp, sizeof(szTemp)), szTemp2));
		break;
	case 138: //limit spelltype this affects
		strcat_s(szBuff, FormatLimits(spelleffectname, value, GetSpellTypeName(base, szTemp), szTemp2));
		break;
	case 139: //limit spell this affects
		strcat_s(szBuff, FormatLimits(spelleffectname, value, GetSpellNameByID(base), szTemp2));
		break;
	case 140: //limit min duration of spells this affects (base= #ticks)
		strcat_s(szBuff, FormatSeconds(spelleffectname, value * 6, szTemp2));
		break;
	case 141: //limit to instant spells only
		strcat_s(szBuff, spelleffectname);
		break;
	case 142: //Limit: Min Level
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 143: //limit min casting time of spells this affects (base= seconds in ms)
	case 144: //limit max casting time of spells this affects (base= seconds in ms)
		strcat_s(szBuff, FormatSeconds(spelleffectname, value / 1000.0f, szTemp2));
		break;
	case 145: //Teleportv2
		sprintf_s(szTemp, " to %d, %d, %d in %s facing %s", GetSpellBase(pSpell, 0), GetSpellBase(pSpell, 1), GetSpellBase(pSpell, 2), GetFullZone(GetZoneID(extra)), szHeadingNormal[EQHeading(GetSpellBase(pSpell, 3))]);
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case 146: //Resist Electricity
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 147: //Hit Points (% Max)
		strcat_s(szBuff, FormatMax(spelleffectname, value, max, szTemp2));
		break;
	case 148: //Stacking: Block
		strcat_s(szBuff, FormatStacking(spelleffectname, base2, value, /*(max>1000 ? max - 1000 : max)*/ max, spa, GetSpellEffectName(base, szTemp, sizeof(szTemp)), szTemp2));
		break;
	case 149: //Stacking: Overwrite
		strcat_s(szBuff, FormatStacking(spelleffectname, calc - 200, value, (max > 1000 ? max - 1000 : max), spa, GetSpellEffectName(base, szTemp, sizeof(szTemp)), szTemp2));
		break;
	case 150: //Death Save - Restore Full Health
		sprintf_s(szTemp, "Restore %s Health", base == 1 ? "Partial" : base == 2 ? "Full" : "Unknown");
		strcat_s(szBuff, FormatExtra(spelleffectname, szTemp, szTemp2));
		break;
	case 151: //Suspended Minion (no current spells)
		sprintf_s(szTemp, "(%s)", base == 0 ? "Current HP Only" : base == 1 ? "Current HP, Buffs, Weapons" : "Unknown");
		strcat_s(szBuff, FormatExtra(spelleffectname, szTemp, szTemp2));
		break;
	case 152: //Summon Pets (swarm)
		sprintf_s(szTemp, "%s x%d for %dsec", extra, value, finish);
		strcat_s(szBuff, FormatExtra(spelleffectname, szTemp, szTemp2));
		break;
	case 153: //Balance Party Health
		strcat_s(szBuff, FormatPenaltyChance(spelleffectname, value, szTemp2, szPercent, "Penalty"));
		break;
	case 154: //Remove Detrimental(c)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 155: //PoP Resurrect
	case 156: //Illusion: Target
		strcat_s(szBuff, spelleffectname);
		break;
	case 157: //Spell Damage Shield
		strcat_s(szBuff, FormatRange(spelleffectname, -value, extendedrange, szTemp2));
		break;
	case 158: //Chance to Reflect Spell
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 159: //Stats
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case 160: //Drunk effect
		strcat_s(szBuff, FormatAT(spelleffectname, value, szTemp2, "if Alcholol Tolerance is below"));
		break;
	case 161: //Mitigate Spell Damage
	case 162: //Mitigate Melee Damage
		strcat_s(szBuff, FormatPercent(spelleffectname, value, szTemp2, false));
		if (max > 0)
			sprintf_s(szTemp, " until %d absorbed", max);
		strcat_s(szBuff, szTemp);
		break;
	case 163: //Absorb Damage
		sprintf_s(szTemp, " up to %d from the next %d melee strikes or direct damage spells", max, value);
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case 164: //Attempt Sense (Cursed) Trap
	case 165: //Attempt Disarm (Cursed) Trap
	case 166: //Attempt Destroy (Cursed) Lock
		strcat_s(szBuff, spelleffectname);
		break;
	case 167: //Increase Pet Power
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 168: //Mitigation
		strcat_s(szBuff, FormatPercent(spelleffectname, -value, -finish, szTemp2));
		break;
	case 169: //Chance to Critical Hit
		strcat_s(szBuff, FormatSkills(spelleffectname, value, finish, base2, szTemp2, true, "for"));
		break;
	case 170: //Chance to Critical Cast
	case 171: //Crippling Blow
	case 172: //Melee Avoidance
	case 173: //Riposte
	case 174: //Dodge
	case 175: //Parry
	case 176: //Dual Wield
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 177: //Stat Cap Mod (how do they know which?)
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case 178: //Lifetap Proc
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		strcat_s(szBuff, " heal");
		break;
	case 179: //Puretone
	case 180: //Spell Resist
	case 181: //Fearless
	case 182: //Hundred Hands
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 183: //Skill Chance Mod
	case 184: //Chance to hit with Backstab (or throwing/archery [http://lucy.allakhazam.com/spellraw.html?id=9616&source=Live])
	case 185: //Damage Mod (how to tell which, rogues get a backstab only, others get an all skills)
	case 186: //Damage Mod (see above)
		strcat_s(szBuff, FormatSkills(spelleffectname, value, finish, base2, szTemp2));
		break;
	case 187: //Mana Balance
		strcat_s(szBuff, FormatPenaltyChance(spelleffectname, value, szTemp2, szPercent, "Penalty"));
		break;
	case 188: //Block
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 189: //Endurance DoT/Regen
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		strcat_s(szBuff, repeating);
		break;
	case 190: //Max Endurance
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case 191: //Amnesia
		strcat_s(szBuff, spelleffectname);
		break;
	case 192: //Discord Hate
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case 193: //Skill Attack
		strcat_s(szBuff, FormatSkillAttack(spelleffectname, value, base2, skill, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case 194: //Fade
		strcat_s(szBuff, spelleffectname);
		break;
	case 195: //Stun Resist
	case 196: //Strikethrough
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case 197: //Skill Damage
		strcat_s(szBuff, FormatSkills(spelleffectname, value, finish, base2, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case 198: //Endurance Heals
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case 199: //Taunt
		strcat_s(szBuff, spelleffectname);
		break;
	case 200: //Proc Mod
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case 201: //Ranged Proc
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname, base, base2, szTemp), szTemp2));
		break;
	case 202: //Illusion Other
	case 203: //Mass Group Buff
		strcat_s(szBuff, spelleffectname);
		break;
	case 204: //War Cry
		strcat_s(szBuff, FormatSeconds(spelleffectname, value, szTemp2, true));
		break;
	case 205: //AE Rampage
	case 206: //AE Taunt
	case 207: //Flesh to Bone
		strcat_s(szBuff, spelleffectname);
		break;
	case 208: //Purge Poison (no spells currently)
	case 209: //Disspell Beneficial Buffs
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 210: //Pet Shield
		strcat_s(szBuff, FormatSeconds(spelleffectname, value * 1.0f, szTemp2));
		break;
	case 211: //AE Melee
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 212: //Frenzied Devastation (### come back and change ###)
		strcat_s(szBuff, FormatSeconds(spelleffectname, value, szTemp2, true));
		break;
	case 213://Pet HP
	case 214: //Change Max HP
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2, false, true));
		break;
	case 215: //Pet Avoidance (no spells currently)
	case 216: //Accuracy
	case 217: //Headshot (no spells currently)
	case 218: //Pet Crit Melee (no spells currently)
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case 219: //Slay undead (Holyforge)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 220: //Skill Damage Amt
		strcat_s(szBuff, FormatSkills(spelleffectname, value, finish, base2, szTemp2, false));
		break;
	case 221: //Reduce Weight
	case 222: //Block Behind
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 223: //Double Riposte (no spells currently)
	case 224: //Additional Riposte
	case 225: //Double Attack
	case 226: //2H Bash (no spells currently)
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 227: //Base Refresh Timer
		strcat_s(szBuff, FormatRefreshTimer(spelleffectname, -value, -finish, base2, szTemp2));
		break;
	case 228: //Reduce Fall Dmg (no spells currently)
	case 229: //Cast Through Stun (no spells currently)
	case 230: //Increase Shield Dist (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 231: //Stun Bash Chance (no spells currently)
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 232: //Divine Save
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case 233: //Metabolism
		strcat_s(szBuff, FormatRange(spelleffectname, -value, extendedrange, szTemp2));
		break;
	case 234: //Poison Mastery (no spells currently)
	case 235: //Focus Channelling (no spells currently)
	case 236: //Free Pet (no spells currently)
	case 237: //Pet Affinity (no spells currently)
	case 238: //Permanent Illusion (no spells currently)
	case 239: //Stonewall (no spells currently)
	case 240: //String Unbreakable (no spells currently)
	case 241: //Improve Reclaim Energy (no spells currently)
	case 242: //Increase Chance Memwipe (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 243: //NoBreak Charm Chance
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 244: //Root Break Chance
	case 245: //Trap Circumvention (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 246: //Lung Capacity
		strcat_s(szBuff, FormatRange(spelleffectname, value, range, szTemp2));
		break;
	case 247: //Increase SkillCap (no spells currently)
	case 248: //Extra Specialization (no spells currently)
	case 249: //Offhand Min (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 250: //Spell Proc Chance
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 251: //Endless Quiver (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 252: //Backstab from Front
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 253: //Chaotic Stab (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 254: //placeholder of some kind
		break;
	case 255: //Shielding Duration (no spells currently)
		strcat_s(szBuff, FormatBasePercent(spelleffectname, base, szTemp2));
		break;
	case 256: //Shroud Of Stealth (no spells currently)
	case 257: //Give Pet Hold (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 258: //Triple Backstab
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 259: //AC Limit
	case 260: //Add Instrument
	case 261: //Song Cap (no spells currently)
		strcat_s(szBuff, FormatBasePercent(spelleffectname, base, szTemp2));
		break;
	case 262: //Stats Cap
		strcat_s(szBuff, FormatStatsCapRange(spelleffectname, value, GetStatShortName(base2, szTemp), extendedrange, szTemp2));
		break;
	case 263: //Tradeskill Masteries (no spells currently)
	case 264: //Reduce AATimer
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 265: //No Fizzle
		strcat_s(szBuff, spelleffectname);
		break;
	case 266: //Attack Chance
	case 267: //Add Pet Commands (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 268: //TS Fail Rate
		strcat_s(szBuff, FormatSkills(spelleffectname, -value, -finish, base2, szTemp2, true, "for"));
		break;
	case 269: //Bandage Perc Limit (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 270: //Bard Song Range
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2, "to"));
		break;
	case 271: //Base Run Speed
		strcat_s(szBuff, FormatBasePercent(spelleffectname, base, szTemp2));
		break;
	case 272: //Casting Level
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case 273: //DoT Crit
	case 274: //Heal Crit
	case 275: //Mend Crit (no spells currently)
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case 276: //Dual Wield Amt (no spells currently)
	case 277: //Extra DI Chance (no spells currently)
	case 278: //Finishing Blow (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 279: //Flurry
	case 280: //Pet Flurry Chance
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case 281: //Give Pet Feign (no spells currently)
	case 282: //Increase Bandage Amt (no spells currently)
	case 283: //Special Attack Chain (no spells currently)
	case 284: //LoH Set Heal (no spells currently)
	case 285: //NoMove Check Sneak (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 286: //DD Bonus
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case 287: //Focus Combat Duration
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		strcat_s(szBuff, " tick(s)");
		break;
	case 288: //Add Proc Hit (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 289: //Trigger on Fade
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Fade"));
		break;
	case 290: //Increase Movement Cap (no spells currently)
	case 291: //Purify
	case 292: //Strikethrough2
	case 293: //StunResist2 (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 294: //Spell Crit Chance
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case 295: //Reduce Timer Special (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 296: //Incoming Spell Damage
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 297: //Incoming Spell Damage Amt
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case 298: //Tiny Companion
		strcat_s(szBuff, FormatPercent(spelleffectname, -value, -finish, szTemp2));
		break;
	case 299: //Wake the Dead
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 300: //Doppleganger
		strcat_s(szBuff, spelleffectname);
		break;
	case 301: //Increase Range Damage (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 302: //Damage Crit
	case 303: //Damage
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case 304: //Secondary Riposte Mod (no spells currently)
		strcat_s(szBuff, FormatBasePercent(spelleffectname, base, szTemp2));
		break;
	case 305: //Damage Shield Mitigation
		strcat_s(szBuff, FormatPercent(spelleffectname, -value, -finish, szTemp2));
		break;
	case 306: //Army of Dead
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 307: //Appraisal
	case 308: //Suspend Minion
	case 309: //Teleport Bind
		strcat_s(szBuff, spelleffectname);
		break;
	case 310: //Reuse Timer
		strcat_s(szBuff, FormatTimer(spelleffectname, -base / 1000.0f, szTemp2));
		break;
	case 311: //No Combat Skills
		strcat_s(szBuff, spelleffectname);
		break;
	case 312: //Sanc
	case 313: //Forage Master (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 314: //Improved Invisibility
	case 315: //Improved Invisibility Vs Undead
	case 316: //Improved Invisibility Vs Animals (no spells currently)
		strcat_s(szBuff, spelleffectname);
		break;
	case 317: //Worn Regen Cap
	case 318: //Worn Mana Cap
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 319: //Critical HP Regen
	case 320: //Shield Block Chance
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case 321: //Soothing
		strcat_s(szBuff, FormatBasePercent(spelleffectname, base, szTemp2));
		break;
	case 322: //Origin
		strcat_s(szBuff, spelleffectname);
		break;
	case 323: //Add Defensive Proc
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname, base, base2, szTemp), szTemp2));
		break;
	case 324: //Spirit Channel
		strcat_s(szBuff, FormatBasePercent(spelleffectname, base, szTemp2));
		break;
	case 325: //No Break AE Sneak (no spells currently)
	case 326: //Spell Slots (no spells currently)
	case 327: //Buff Slots (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 328: //Negative HP Limit
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case 329: //Mana Shield
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2, "up to", szPercent));
		break;
	case 330: //Crit Damage
		strcat_s(szBuff, FormatSkills(spelleffectname, value, finish, base2, szTemp2));
		break;
	case 331: //Item Recovery
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 332: //Summon to Corpse
		strcat_s(szBuff, spelleffectname);
		break;
	case 333: //Trigger on fade
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Fade"));
		break;
	case 334: //Song DoT
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		strcat_s(szBuff, repeating);
		strcat_s(szBuff, " if target is not moving");
		break;
	case 335: //Fc_Immunity Focus
		strcat_s(szBuff, spelleffectname);
		break;
	case 336: //Illusionary Target (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 337: //Experience buff
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 338: //Expedient Recovery
		strcat_s(szBuff, spelleffectname);
		break;
	case 339: //Trigger DoT on cast
	case 340: //Trigger DD on cast
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatSpellChance(spelleffectname, base, base2, szTemp), szTemp2, " on Cast"));
		break;
	case 341: //Worn Attack Cap
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case 342: //Prevent Flee on Low Health
		strcat_s(szBuff, spelleffectname);
		break;
	case 343: //Spell Interrupt
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case 344: //Item Channeling (no spells currently)
	case 345: //Assassinate Max (no spells currently)
	case 346: //Headshot Max (no spells currently)
	case 347: //Double Ranged Attack (no spells currently)
	case 348: //Limit: Mana Min
	case 349: //Increase Damage With Shield (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 350: //Manaburn
		strcat_s(szBuff, FormatCount(spelleffectname, value * 4, szTemp2, "for"));
		break;
	case 351: //Persistent Effect
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(id + (spellgroup ? 3 : 1)), szTemp2));
		break;
	case 352: //Increase Trap Count
	case 353: //Increase SOI Count
	case 354: //Deactivate All Traps
	case 355: //Learn Trap
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 356: //Change Trigger Type (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 357: //Mute
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 358: //Mana/Max Mana
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case 359: //Passive Sense Trap
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 360: //Killshot Triggers
	case 361: //Proc On Death
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatSpellChance(spelleffectname, base, base2, szTemp), szTemp2));
		break;
	case 362: //Potion Belt (no spells currently)
	case 363: //Bandolier (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 364: //Triple Attack Chance
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 365: //Trigger on Kill Shot
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatSpellChance(spelleffectname, base, base2, szTemp), szTemp2));
		break;
	case 366: //Group Shielding
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 367: //Change Body Type
		sprintf_s(szTemp, " to %s", base == 25 ? "Plant" : base == 21 ? "Animal" : base == 3 ? "Undead" : "Unknown");
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case 368: //Modify Faction
		strcat_s(szBuff, FormatExtra(spelleffectname, GetFactionName(base, szTemp), szTemp2));
		break;
	case 369: //Corruption Counters
	case 370: //Corruption Resists
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case 371: //Slow
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 372: //Grant Foraging (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 373: //Trigger Effect
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Fade"));
		break;
	case 374: //Trigger Spell
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatSpellChance(spelleffectname, base, base2, szTemp), szTemp2));
		break;
	case 375: //Critical DoT Damage Mod
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 376: //Fling
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 377: //Trigger Effect
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Fade"));
		break;
	case 378: //Resist
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatResists(spelleffectname, base, base2, szTemp), szTemp2));
		break;
	case 379: //Directional Shadowstep
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case 380: //Knockback Explosive
		sprintf_s(szTemp, " (%d) and Toss Up (%d)", base, base2);
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case 381: //Fling to Self
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 382: //Negate: Effect
	{
		char szString[MAX_STRING] = { 0 };
		sprintf_s(szTemp, " %s Effect", GetSpellEffectNameByID(base2, szString, MAX_STRING));
		strcat_s(szBuff, FormatExtra(spelleffectname, szTemp, szTemp2));
		break;
	}
	case 383: //Trigger Spell
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatSpellChance(spelleffectname, base, base2, szTemp), szTemp2, " on Cast"));
		break;
	case 384: //Fling to Target
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 385: //Limit: SpellGroup
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameBySpellGroupID(base), szTemp2));
		break;
	case 386: //Trigger Effect
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Curer"));
		break;
	case 387: //Trigger Effect
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Fade"));
		break;
	case 388: //Summon All Corpses
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 389: //Spell Gem Refresh
		strcat_s(szBuff, FormatCount(spelleffectname, -value, szTemp2, "to"));
		break;
	case 390: //Fc_Timer Lockout
	case 391: //Limit: Mana Max
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 392: //Heal Amt
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case 393: //Incoming Healing Effectiveness
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 394: //Incoming Healing Amt
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case 395: //Fc_Heal % Crit (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 396: //Heal Amt
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case 397: //Pet Amt Mitigation (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 398: //Swarm Pet Duration
		strcat_s(szBuff, FormatSecondsCount(spelleffectname, value / 1000.0f, szTemp2));
		break;
	case 399: //Twincast Chance
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 400: //Healburn
		sprintf_s(szTemp, " use up to %d mana to heal your group", value);
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case 401: //Mana/HP
	case 402: //Endurance/HP
		strcat_s(szBuff, FormatCount(spelleffectname, -value, szTemp2, "by up to"));
		break;
	case 403: //Limit: SpellClass
	case 404: //Limit: SpellSubclass
	case 405: //Staff Block Chance (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 406: //Trigger Effect
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Max Hits"));
		break;
	case 407: //Trigger Effect
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Focus Used"));
		break;
	case 408: //Limit HP
	case 409: //Limit Mana
	case 410: //Limit Endurance
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2, "to"));
		break;
	case 411: //Limit: PlayerClass
		strcat_s(szBuff, FormatExtra(spelleffectname, GetClassesFromMask(base, szTemp), szTemp2));
		break;
	case 412: //Limit: Race (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2)); // needs work (base2 bitmask of races)
		break;
	case 413: //Base Dmg
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2, "by", szPercent));
		break;
	case 414: //Limit: CastingSkill
	case 415: //Limit: ItemClass (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 416: //AC2
	case 417: //Mana2
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
	case 418: //Increased Skill Damage2
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case 419: //Add Proc
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname, base, base2, szTemp), szTemp2));
		break;
	case 420: //Fc_Limit Use (no spells currently)
	case 421: //Fc_Limit Use Amt (no spells currently)
	case 422: //Limit: Use Min (no spells currently)
	case 423: //Limit: Use Type (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 424: //Gravitate
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		if (strlen(maxtargets)) strcat_s(szBuff, maxtargets);
		break;
	case 425: //Fly
		strcat_s(szBuff, spelleffectname);
		break;
	case 426: //AddExtTargetSlots (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 427: //Skill Proc
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname, base, base2, szTemp), szTemp2));
		break;
	case 428: //Limit Skill
		strcat_s(szBuff, FormatExtra(spelleffectname, base >= 0 ? szSkills[base] : "All Skills", szTemp2));
		break;
	case 429: //Skill Proc Success
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname, base, base2, szTemp), szTemp2));
		break;
	case 430: //PostEffect
	case 431: //PostEffectData
	case 432: //ExpandMaxActiveTrophyBenefits (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 433: //Skill Min Damage
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname, base, base2, szTemp), szTemp2));
		break;
	case 434: //Skill Min Damage
	case 435: //Fragile Defense
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 436: //Beneficial Countdown Hold
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 437: //Teleport to Anchor
	case 438: //Translocate to Anchor
		sprintf_s(szTemp, " to %s Anchor", base == 50874 ? "Guild Hall" : base == 52584 ? "Primary" : base == 52585 ? "Secondary" : "Unknown");
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case 439: //Assassinate (no spells currently)
	case 440: //FinishingBlowMax (no spells currently)
	case 441: //Distance Removal
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 442: //Doom Req Target
	case 443: //Doom Req Caster
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2));
		if (base2) {
			GetSpellRestrictions(pSpell, i, szTemp, sizeof(szTemp));
			strcat_s(szBuff, " -- Restrictions: ");
			strcat_s(szBuff, szTemp);
		}
		break;
	case 444: //Improved Taunt
		sprintf_s(szTemp, " up to L%d and Reduce Ally Hate Generation by %d%s", base, base2, szPercent);
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case 445: //Add Merc Slot
	case 446: //A_Stacker
	case 447: //B_Stacker
	case 448: //C_Stacker
	case 449: //D_Stacker
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 450: //DoT Guard
		sprintf_s(szTemp, " absorbing %d%s damage to a total of %d", value, szPercent, max);
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case 451: //Melee Threshold Guard
	case 452: //Spell Threshold Guard
		sprintf_s(szTemp, " absorbing %d%s of incoming %s damage in excess of %d to a total of %d", value, szPercent, spa == 451 ? "melee" : "spell", base2, max);
		strcat_s(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
	case 453: //Doom Melee Threshold
		sprintf_s(szTemp, " on %d Melee Damage Taken", base2);
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, szTemp));
		break;
	case 454: //Doom Spell Threshold
		sprintf_s(szTemp, " on %d Spell Damage Taken", base2);
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, szTemp));
		break;
	case 455: //Add Hate %
	case 456: //Add Hate Over Time %
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 457: //Resource Tap
		sprintf_s(szTemp, "Return %.2f%s of direct damage as %s", value / 10.0f, szPercent, base2 == 0 ? "hit points" : base2 == 1 ? "mana" : base2 == 2 ? "endurance" : "unknown");
		strcat_s(szBuff, szTemp);
		break;
	case 458: //Faction Mod %
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 459: //Damage Mod 2 (how to tell which, rogues get a backstab only, others get an all skills)
		strcat_s(szBuff, FormatSkills(spelleffectname, value, finish, base2, szTemp2));
		break;
	case 460: //Limit: Include Non-Focusable
		strcat_s(szBuff, spelleffectname);
		break;
	case 461: //Fc Damage % 2 (no spells currently)
	case 462: //Fc Damage Amt 2 (no spells currently)
	case 463: //Shield Target (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 464: //PC Pet Rampage
	case 465: //PC Pet AE Rampage
	case 466: //PC Pet Flurry Chance
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 467: //DS Mitigation Amt
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 468: //DS Mitigation Percentage
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 469: //Chance Best in Spell Group
	case 470: //Trigger Best in Spell Group
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatSpellGroupChance(spelleffectname, base, base2, szTemp), szTemp2, " on Cast"));
		break;
	case 471: //Double Melee Round (PC Only)
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 472: //Toggle Passive AA Rank
		strcat_s(szBuff, spelleffectname);
		break;
	case 473: //Double Backstab From Front  (no spells currently)
	case 474: //Pet Crit Melee Damage% (Owner)  (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 475: //Trigger Spell Non-Item
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Cast"));
		break;
	case 476: //Weapon Stance (no spells currently)
	case 477: //Move to Top of Hatelist (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 478: //Move to Bottom of Hatelist
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Cast"));
		break;
	case 479: //Value Min
		sprintf_s(szTemp, "%s %s", spelleffectname, base < 0 ? "Max" : "Min");
		strcat_s(szBuff, FormatMinMaxBase(szTemp, base, base2, szTemp2));
		break;
	case 480: //Value Max
		sprintf_s(szTemp, "%s %s", spelleffectname, base < 0 ? "Min" : "Max");
		strcat_s(szBuff, FormatMinMaxBase(szTemp, base, base2, szTemp2));
		break;
	case 481: //Cast Spell on Land
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base2), szTemp2, " on Land and conditions are met"));
		break;
	case 482: //Skill Base Damage Mod
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 483: //Spell Damage Taken
	case 484: //Spell Damage Taken
		strcat_s(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2, " (after crit)"));
		break;
	case 485: //CasterClass
		strcat_s(szBuff, FormatExtra(spelleffectname, GetClassesFromMask(base, szTemp), szTemp2));
		break;
	case 486: //Same Caster
		strcat_s(szBuff, FormatExtra(spelleffectname, base ? "(Same)" : "(Different)", szTemp2, "", ""));
		break;
	case 487: //Extend Tradeskill Cap
		sprintf_s(szTemp, "%s (%d, %d, %d)", spelleffectname, base, base2, max);
		strcat_s(szBuff, szTemp);
		break;
	case 488: //Push Taken
		strcat_s(szBuff, FormatBase(spelleffectname, -base, szTemp2));
		break;
	case 489: //Worn Endurance Regen Cap
		strcat_s(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
	case 490: //Limit: ReuseTime Min
	case 491: //Limit: ReuseTime Max
		strcat_s(szBuff, FormatSeconds(spelleffectname, value / 1000.0f, szTemp2));
		break;
	case 492: //Limit: Endurance Min
	case 493: //Limit: Endurance Max
	case 494: //Pet Add Attack
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case 495: //Limit: Duration Max
		strcat_s(szBuff, FormatSeconds(spelleffectname, value * 6, szTemp2));
		break;
	case 496: //Critical Hit Damage (Non-stacking)
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		strcat_s(szBuff, " of Base Damage (Non Stacking)");
		break;
	case 497: //NoProc
		sprintf_s(szTemp, "%s (%d, %d, %d)", spelleffectname, base, base2, max);
		strcat_s(szBuff, szTemp);
		break;
	case 498: //Extra Attack % (1H Primary)
	case 499: //Extra Attack % (1H Secondary)
	case 500: //Spell Haste v2
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
	case 501: //Spell Cast Time
	case 502: //Stun and Fear
		strcat_s(szBuff, FormatSeconds(spelleffectname, value / 1000.0f, szTemp2));
		break;
	case 503: //Rear Arc Melee Damage Mod
		strcat_s(szBuff, FormatSeconds(spelleffectname, value / 10.0f, szTemp2));
		break;
	case 504: //Rear Arc Melee Damage
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case 505: //Rear Arc Damage Taken Mod
		strcat_s(szBuff, FormatSeconds(spelleffectname, value / 10.0f, szTemp2));
		break;
	case 506: //Rear Arc Damage Taken
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case 507: //Spell Damage v4 Mod
		strcat_s(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		strcat_s(szBuff, " (Before DoT Crit, After Nuke Crit)");
		break;
	case 508: //Spell Damage v4
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
	case 509: //Health Transfer
		sprintf_s(szTemp, "%s (%d, %d, %d)", spelleffectname, base, base2, max);
		strcat_s(szBuff, szTemp);
		break;
	case 510: //Resist Incoming
		strcat_s(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
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
	sprintf_s(szBuff, 12, "%d", CalcValue(GetSpellCalc(pSpell, i), GetSpellBase(pSpell, i), GetSpellMax(pSpell, i), pSpell->DurationCap));
	return;
}
