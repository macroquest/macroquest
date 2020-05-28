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

#pragma once

#include "../common/Common.h"

 // string trim includes:
#include <algorithm>
#include <cctype>
#include <locale>

// for _access
#include <io.h>

// For Conversions
#include <charconv>

namespace mq {

MQLIB_API char* CleanupName(char* szName, size_t BufferSize, bool Article = true, bool ForWhoList = true);

inline CHARINFO* GetCharInfo()
{
	// pPCData and pCharData points to same address
	return (CHARINFO*)pCharData;
}

[[deprecated("Use GetPcProfile instead")]]
inline CHARINFO2* GetCharInfo2()
{
	if (CHARINFO* pChar = (CHARINFO*)pCharData)
	{
		if (pChar->ProfileManager.pFirst)
		{
			return (CHARINFO2*)pChar->ProfileManager.GetCurrentProfile();
		}
	}

	return nullptr;
}

inline PcProfile* GetPcProfile()
{
	if (pCharData)
	{
		return pCharData->GetCurrentPcProfile();
	}

	return nullptr;
}

inline PlayerClient* GetSpawnByID(DWORD dwSpawnID)
{
	//    if (dwSpawnID<3000)
	//        return ppEQP_IDArray[dwSpawnID];
	return pSpawnManager->GetSpawnByID(dwSpawnID);
}

inline PlayerClient* GetSpawnByName(const char* spawnName)
{
	return pSpawnManager->GetSpawnByName(spawnName);
}

inline PlayerClient* GetSpawnByPartialName(char const* spawnName, PlayerBase* exclusion = nullptr)
{
	return pSpawnManager->GetPlayerFromPartialName(spawnName, exclusion);
}

inline EQ_Spell* GetSpellByID(int spellID)
{
	if (!pSpellMgr || spellID <= 0 || spellID >= TOTAL_SPELL_COUNT)
		return nullptr;

	return pSpellMgr->GetSpellByID(spellID);
}

inline const char* GetBodyTypeDesc(uint32_t BodyTypeID)
{
	if (BodyTypeID < 104 && BodyTypeID >= 0)
		return szBodyType[BodyTypeID];

	return "*UNKNOWN BODYTYPE";
}

inline const char* GetClassDesc(DWORD ClassID)
{
	switch (ClassID)
	{
	case 60:
		return "LDoN Recruiter";
	case 61:
		return "LDoN Merchant";
	case 62:
		return "Destructible Object";
	case 63:
		return "Tribute Master";
	case 64:
		return "Guild Tribute Master";
	case 66:
		return "Guild Banker";
	case 67:
		return "Good DoN Merchant";
	case 68:
		return "Evil DoN Merchant";
	case 69:
		return "Fellowship Registrar";
	case 70:
		return "Merchant";
	case 71:
		return "Mercenary Liaison";
	case 72:
		return "Real Estate Merchant";
	case 73:
		return "Loyalty Merchant";
	case 74:
		return "Tribute Master";
	case 0xFF:
		return "Aura";
	case 0xFE:
		return "Banner";
	case 0xFD:
		return "Campfire";
	default:
		return pEverQuest->GetClassDesc(ClassID);
	}
}

inline const char* GetTypeDesc(eSpawnType TypeID)
{
	switch (TypeID)
	{
	case MOUNT:
		return "Mount";
	case UNTARGETABLE:
		return "Untargetable";
	case NPC:
		return "NPC";
	case PC:
		return "PC";
	case CHEST:
		return "Chest";
	case TRAP:
		return "Trap";
	case TRIGGER:
		return "Trigger";
	case TIMER:
		return "Timer";
	case PET:
		return "Pet";
	case ITEM:
		return "Item";
	case CORPSE:
		return "Corpse";
	case AURA:
		return "Aura";
	case OBJECT:
		return "Object";
	case BANNER:
		return "Banner";
	case CAMPFIRE:
		return "Campfire";
	case MERCENARY:
		return "Mercenary";
	case FLYER:
		return "Flyer";
	default:
		return "Unknown Type";
	}
}

inline bool IsMarkedNPC(SPAWNINFO* pSpawn)
{
	if (GetCharInfo() && GetCharInfo()->pSpawn && pSpawn)
	{
		for (int nMark = 0; nMark < 3; nMark++)
		{
			if (GetCharInfo()->pSpawn->RaidMarkNPC[nMark] == pSpawn->SpawnID)
			{
				return true;
			}
		}

		for (int nMark = 0; nMark < 3; nMark++)
		{
			if (GetCharInfo()->pSpawn->GroupMarkNPC[nMark] == pSpawn->SpawnID)
			{
				return true;
			}
		}
	}

	return false;
}

inline int GetEnduranceRegen()
{
	if (pCharData)
	{
		return pCharData->GetEnduranceRegen(true, false);
	}

	return 0;
}

inline int GetHPRegen()
{
	if (pCharData)
	{
		// the client sets it to true on return if we are bleeding.
		bool bBleed = false;
		return pCharData->GetHPRegen(true, &bBleed, false);
	}

	return 0;
}

inline int GetManaRegen()
{
	if (pCharData)
	{
		return pCharData->GetManaRegen(true, false);
	}

	return 0;
}

inline int GetCurMana()
{
	if (pCharData)
	{
		return pCharData->Cur_Mana(true);
	}

	return 0;
}

inline int GetCurHPS()
{
	if (pCharData)
	{
		return pCharData->Cur_HP(0);
	}

	return 0;
}

inline int GetMaxHPS()
{
	if (pCharData)
	{
		return pCharData->Max_HP(0);
	}

	return 0;
}

inline int GetMaxEndurance()
{
	if (pCharData)
	{
		return pCharData->Max_Endurance();
	}

	return 0;
}

inline int GetCurEndurance()
{
	if (PcProfile* pProfile = GetPcProfile())
	{
		return pProfile->Endurance;
	}

	return 0;
}

inline int GetMaxMana()
{
	if (pCharData)
	{
		return pCharData->Max_Mana();
	}

	return 0;
}

inline int GetAdjustedSkill(int nSkill)
{
	if (pCharData)
	{
		return pCharData->GetAdjustedSkill(nSkill);
	}

	return 0;
}

inline int GetBaseSkill(int nSkill)
{
	if (pCharData)
	{
		return pCharData->GetBaseSkill(nSkill);
	}

	return 0;
}

inline int GetModCap(int index, bool bToggle = false)
{
	if (pCharData)
	{
		return pCharData->GetModCap(index, bToggle);
	}

	return 0;
}

inline const int GetCastingTimeModifier(const EQ_Spell* cSpell)
{
	if (pCharData)
	{
		return pCharData->GetCastingTimeModifier(cSpell);
	}

	return 0;
}

inline int GetFocusCastingTimeModifier(const EQ_Spell* pSpell, VePointer<CONTENTS>& pItemOut, bool bEvalOnly)
{
	if (pCharData)
	{
		return pCharData->GetFocusCastingTimeModifier(pSpell, pItemOut, bEvalOnly);
	}

	return 0;
}

inline int GetFocusRangeModifier(const EQ_Spell* pSpell, VePointer<CONTENTS>& pItemOut)
{
	if (pCharData)
	{
		return pCharData->GetFocusRangeModifier(pSpell, pItemOut);
	}

	return 0;
}

inline bool HasSkill(int nSkill)
{
	if (pCharData)
	{
		return pCharData->HasSkill(nSkill);
	}

	return false;
}

inline float GetDistance(float X1, float Y1)
{
	float dX = X1 - ((SPAWNINFO*)pCharSpawn)->X;
	float dY = Y1 - ((SPAWNINFO*)pCharSpawn)->Y;
	return sqrtf(dX * dX + dY * dY);
}

inline float GetDistance(float X1, float Y1, float X2, float Y2)
{
	float dX = X1 - X2;
	float dY = Y1 - Y2;
	return sqrtf(dX * dX + dY * dY);
}

inline float GetDistanceSquared(float X1, float Y1, float X2, float Y2)
{
	float dX = X1 - X2;
	float dY = Y1 - Y2;
	return dX * dX + dY * dY;
}

inline float GetDistance3D(float X1, float Y1, float Z1, float X2, float Y2, float Z2)
{
	float dX = X1 - X2;
	float dY = Y1 - Y2;
	float dZ = Z1 - Z2;
	return sqrtf(dX * dX + dY * dY + dZ * dZ);
}

// ***************************************************************************
// Function:    DistanceToSpawn
// Description: Return the distance between two spawns
// ***************************************************************************
inline float GetDistance(SPAWNINFO* pChar, SPAWNINFO* pSpawn)
{
	float X = pChar->X - pSpawn->X;
	float Y = pChar->Y - pSpawn->Y;
	return sqrtf(X * X + Y * Y);
}

inline float GetDistanceSquared(SPAWNINFO* pChar, SPAWNINFO* pSpawn)
{
	float X = pChar->X - pSpawn->X;
	float Y = pChar->Y - pSpawn->Y;
	return X * X + Y * Y;
}

inline float Get3DDistance(float X1, float Y1, float Z1, float X2, float Y2, float Z2)
{
	float dX = X1 - X2;
	float dY = Y1 - Y2;
	float dZ = Z1 - Z2;
	return sqrtf(dX * dX + dY * dY + dZ * dZ);
}

inline float Get3DDistanceSquared(float X1, float Y1, float Z1, float X2, float Y2, float Z2)
{
	float dX = X1 - X2;
	float dY = Y1 - Y2;
	float dZ = Z1 - Z2;
	return dX * dX + dY * dY + dZ * dZ;
}

inline float DistanceToSpawn(SPAWNINFO* pChar, SPAWNINFO* pSpawn)
{
	return GetDistance(pChar, pSpawn);
}

template <typename T1, typename T2>
inline float Distance3DToSpawn(const T1& pSpawn1, const T2& pSpawn2)
{
	return Get3DDistance(((SPAWNINFO*)pSpawn1)->X, ((SPAWNINFO*)pSpawn1)->Y, ((SPAWNINFO*)pSpawn1)->Z,
		((SPAWNINFO*)pSpawn2)->X, ((SPAWNINFO*)pSpawn2)->Y, ((SPAWNINFO*)pSpawn2)->Z);
}

template <typename Reference, typename T, typename Func>
void DistanceSort(const Reference& Ref, std::vector<T>& Vector, Func Distance)
{
	// std::sort is guaranteed max complexity of O(nlogn)
	std::sort(Vector.begin(), Vector.end(),
		[&Ref, &Distance](const T& a, const T& b)
		{
			return Distance(Ref, a) < Distance(Ref, b);
		});
}

inline bool _FileExists(const char* filename)
{
	return _access(filename, 0) != -1;
}

// ***************************************************************************
// FindMount(SPAWNINFO*) - Used to find the mount of a spawn, if one
//                         exists. returns the spawn if one does not.
// ***************************************************************************
inline SPAWNINFO* FindMount(SPAWNINFO* pSpawn)
{
	return (pSpawn->Mount ? pSpawn->Mount : pSpawn);
}

// ***************************************************************************
// Function:    ConColorToRGB
// Description: Returns the RGB color for a con color
// ***************************************************************************
inline uint32_t ConColorToARGB(int ConColor)
{
	switch (ConColor)
	{
	case CONCOLOR_GREY:
		return 0xFF505050;
	case CONCOLOR_GREEN:
		return 0xFF00FF00;
	case CONCOLOR_LIGHTBLUE:
		return 0xFF00FFFF;
	case CONCOLOR_BLUE:
		return 0xFF0000FF;
	case CONCOLOR_WHITE:
		return 0xFFFFFFFF;
	case CONCOLOR_YELLOW:
		return 0xFFFFFF00;
	case CONCOLOR_RED:
	default:
		return 0xFFFF0000;
	}
}

inline bool IsNumber(std::string_view String)
{
	if (String.empty())
		return false;

	int test_int;
	auto result = std::from_chars(String.data(), String.data() + String.size(), test_int);

	return result.ec != std::errc::invalid_argument;
}

inline bool IsNumberToComma(const char* String)
{
	if (*String == 0)
		return false;

	const char* Temp = String;
	while (*String)
	{
		if (!((*String >= '0' && *String <= '9') || *String == '.'))
		{
			if (*String == ',' && Temp != String)
				return true;
			return false;
		}
		++String;
	}

	return true;
}

inline bool LineOfSight(SPAWNINFO* Origin, SPAWNINFO* CanISeeThis)
{
	if (!Origin || !CanISeeThis)
		return false;

	return ((PlayerClient*)Origin)->CanSee(*(PlayerClient*)CanISeeThis);
}

inline bool IsMobFleeing(SPAWNINFO* pChar, SPAWNINFO* pSpawn)
{
	float HeadingTo = (float)(atan2f(pChar->Y - pSpawn->Y, pSpawn->X - pChar->X) * 180.0f / PI + 90.0f);
	float Heading = pSpawn->Heading * 0.703125f;

	if (HeadingTo < 0.0f)
		HeadingTo += 360.0f;
	else if (HeadingTo >= 360.0f)
		HeadingTo -= 360.0f;

	float UB = HeadingTo + 120.0f;
	float LB = HeadingTo - 120.0f;

	if (LB < UB) return ((Heading < UB) && (Heading > LB));
	else return ((Heading < LB) && (Heading > UB));
}

// TODO: Move this elsewhere
inline DWORD FixOffset(DWORD nOffset)
{
	return ((nOffset - 0x400000) + eqlib::EQGameBaseAddress);
}

inline bool endsWith(const char* base, const char* str)
{
	if (!base || !str)
		return false;
	int blen = strlen(base);
	int slen = strlen(str);
	return (blen >= slen) && (0 == strcmp(base + blen - slen, str));
}

// ***************************************************************************
// Function:    MQGetTickCount64
// Description: Returns Uptime in milliseconds. Minimum Resolution is 15ms
// ***************************************************************************
inline uint64_t MQGetTickCount64()
{
	return ::GetTickCount64();
}

inline int GetMemorizedSpell(int index)
{
	if (index < 0 || index > 0xF)
		return -1;

	if (CHARINFO* pCharInfo = GetCharInfo())
	{
		// FIXME: Don't take the address of the vtable, just let compiler do typecast.
		CharacterBase* cb = (CharacterBase*)&pCharInfo->CharacterBase_vftable;
		return cb->GetMemorizedSpell(index);
	}

	return -1;
}

inline int EQGetSpellDuration(EQ_Spell* pSpell, unsigned char casterLevel, bool isItemEffect)
{
	if (pCharData)
	{
		return pCharData->SpellDuration(pSpell, casterLevel, isItemEffect);
	}

	return 0;
}

inline int EQGetMySpellDuration(EQ_Spell* pSpell)
{
	if (!pLocalPlayer)
		return 0;
	if (!pCharData)
		return 0;
	if (!pSpell)
		return 0;

	SPAWNINFO* pSpawnInfo = pLocalPlayer.get_as<SPAWNINFO>();

	int origDuration = EQGetSpellDuration(pSpell, pSpawnInfo->Level, false);

	int out1 = 0, out2 = 0;
	VePointer<CONTENTS> pContents;

	int durationMod = pCharData->GetFocusDurationMod(pSpell, pContents, pLocalPlayer, origDuration, &out1, &out2);

	return origDuration + durationMod;
}

inline int GetSpellNumEffects(SPELL* pSpell)
{
	if (pSpell)
	{
		return pSpell->NumEffects;
	}

	return 0;
}

inline bool IsPlayerClass(int Class)
{
	return Class >= Warrior && Class <= Berserker;
}

inline bool CanTank(int Class)
{
	switch (Class)
	{
	case Warrior:
	case Shadowknight:
	case Paladin:
		return true;
	}

	return false;
}

inline const char* GetSpellString(int ID, int SpellIndex)
{
	if (pEQSpellStrings)
	{
		if (const char* str = pEQSpellStrings->GetString(ID, SpellIndex))
		{
			if (str[0])
			{
				return str;
			}
		}
	}

	return nullptr;
}

inline bool MaybeExactCompare(std::string_view haystack, std::string_view needle)
{
	if (needle.empty())
		return haystack.empty();

	bool exact = false;

	if (needle[0] == '=')
		needle = needle.substr(1);

	return ci_equals(haystack, needle, exact);
}

[[deprecated("Access CXStr directly instead of calling GetCXStr")]]
inline DWORD GetCXStr(CXStr* pCXStr, char* szBuffer, uint32_t length = MAX_STRING)
{
	if (!szBuffer)
		return 0;

	szBuffer[0] = 0;

	if (!pCXStr || length == 0)
		return 0;

	if (length > pCXStr->length())
	{
		strcpy_s(szBuffer, length, pCXStr->data());
		return pCXStr->length();
	}

	strncpy_s(szBuffer, length, pCXStr->data(), _TRUNCATE);
	szBuffer[length - 1] = 0;
	return length;
}

[[deprecated("Set CXStr directly instead of using SetCXStr")]]
inline void SetCXStr(CXStr* pCXStr, const char* text)
{
	if (pCXStr)
	{
		*pCXStr = text;
	}
}

[[deprecated("modify CXStr directly instead of using AppendCXStr")]]
inline void AppendCXStr(CXStr* pCXStr, const char* text)
{
	if (pCXStr)
	{
		*pCXStr += text;
	}
}

inline bool IsEvolvingItem(CONTENTS* pContents)
{
	return pContents->pEvolutionData != nullptr;
}

} // namespace mq
