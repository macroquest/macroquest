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

 // string trim includes:
#include <algorithm>
#include <cctype>
#include <locale>

// For Conversions
#include <charconv>

EQLIB_API char* CleanupName(char* szName, size_t BufferSize, bool Article = true, bool ForWhoList = true);

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

inline SPELL* GetSpellByID(int dwSpellID)
{
	if (dwSpellID == 0 || dwSpellID == -1)
		return nullptr;

	int spellId = abs(dwSpellID);
	if (spellId >= TOTAL_SPELL_COUNT)
		return nullptr;

	return ((PSPELLMGR)pSpellMgr)->Spells[spellId];
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
		// ok so as far as i can tell RefCount gets increased by us calling this function
		// and its weird that it's no decremented properly afterwards
		// it's possible we don't understand this, but there is also a chance this
		// is a real serious eq bug, either way, decrementing it after the return
		// seems to work...
		// if they ever fix this, we must remove our decrement here...
		int ret = pCharData->GetFocusCastingTimeModifier(pSpell, pItemOut, bEvalOnly);

		// Need to decrement refcount because we aren't using it.
		if (pItemOut.pObject)
		{
			InterlockedDecrement((long volatile*)& pItemOut.pObject->RefCount);
		}
		return ret;
	}

	return 0;
}

inline int GetFocusRangeModifier(const EQ_Spell* pSpell, VePointer<CONTENTS>& pItemOut)
{
	if (pCharData)
	{
		int ret = pCharData->GetFocusRangeModifier(pSpell, pItemOut);

		if (pItemOut.pObject)
		{
			InterlockedDecrement((long volatile*)&pItemOut.pObject->RefCount);
		}
		return ret;
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

inline float DistanceToSpawn(SPAWNINFO* pChar, SPAWNINFO* pSpawn)
{
	return GetDistance(pChar, pSpawn);
}

template <typename T1, typename T2>
inline float Distance3DToSpawn(T1* pSpawn1, T2* pSpawn2)
{
	return Get3DDistance(((SPAWNINFO*)pSpawn1)->X, ((SPAWNINFO*)pSpawn1)->Y, ((SPAWNINFO*)pSpawn1)->Z,
		((SPAWNINFO*)pSpawn2)->X, ((SPAWNINFO*)pSpawn2)->Y, ((SPAWNINFO*)pSpawn2)->Z);
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

inline bool IsNumber(const char* String)
{
	if (*String == 0)
		return false;

	if (*String == '-')
		String++;

	while (*String)
	{
		if (!((*String >= '0' && *String <= '9') || *String == '.'))
			return false;

		++String;
	}

	return true;
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
	return ((nOffset - 0x400000) + EQGameBaseAddress);
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

inline int EQGetSpellDuration(SPELL* pSpell, unsigned char arg2, bool arg3)
{
	if (pCharData)
	{
		return pCharData->SpellDuration((EQ_Spell*)pSpell, arg2, arg3);
	}

	return 0;
}

inline int GetSpellNumEffects(SPELL* pSpell)
{
	if (pSpell)
	{
		return pSpell->NumEffects;
	}

	return 0xc;
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

// trim from start (in place)
inline void ltrim(std::string& s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(),
		[](int ch) { return !std::isspace(ch); }));
}

// trim from end (in place)
inline void rtrim(std::string& s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(),
		[](int ch) { return !std::isspace(ch); }).base(), s.end());
}

// trim from both ends (in place)
inline void trim(std::string& s)
{
	ltrim(s);
	rtrim(s);
}

// trim from start (copying)
inline std::string ltrim_copy(std::string s)
{
	ltrim(s);
	return s;
}

// trim from end (copying)
inline std::string rtrim_copy(std::string s)
{
	rtrim(s);
	return s;
}

// trim from both ends (copying)
inline std::string trim_copy(std::string s)
{
	trim(s);
	return s;
}

/**
 * @fn GetIntFromString
 *
 * @brief Gets the int value from a well formatted string
 *
 * Takes the input of a string and a value that should be returned if conversion fails.
 * Attempts to convert the string to an int and returns the converted value on success
 * or the failure value on fail.
 *
 * Suitable replacement for atoi (removing the undefined behavior) and faster than strtol.
 *
 * @param svString The string to convert to an integer
 * @param iReturnOnFail The integer that should be returned if conversion fails
 *
 * @return int The converted integer or the "failure" value
 **/
inline int GetIntFromString(const std::string_view svString, int iReturnOnFail)
{
	auto result = std::from_chars(svString.data(), svString.data() + svString.size(), iReturnOnFail);
	// Could error check here, but failures don't modify the value and we're not returning meaningful errors.
	return iReturnOnFail;
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

inline bool DataCompare(const uint8_t* pData, const uint8_t* bMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++bMask)
	{
		if (*szMask == 'x' && *pData != *bMask)
			return false;
	}

	return *szMask == 0;
}

// FIXME: Should maybe use uintptr_t for these
inline uint32_t FindPattern(uint32_t dwAddress, uint32_t dwLen, const uint8_t* bPattern, const char* szMask)
{
	for (unsigned int i = 0; i < dwLen; i++)
	{
		if (DataCompare((uint8_t*)(dwAddress + i), bPattern, szMask))
			return (uint32_t)(dwAddress + i);
	}

	return 0;
}

inline uint32_t GetDWordAt(uint32_t address, uint32_t numBytes)
{
	if (address)
	{
		address += numBytes;

		return *(uint32_t*)address;
	}

	return 0;
}


inline void MakeLower(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

struct ci_less
{
	struct nocase_compare
	{
		bool operator() (const unsigned char& c1, const unsigned char& c2) const noexcept
		{
			if (c1 == c2)
				return true;
			return ::tolower(c1) < ::tolower(c2);
		}
	};

	bool operator()(std::string_view s1, std::string_view s2) const noexcept
	{
		return std::lexicographical_compare(
			s1.begin(), s1.end(),
			s2.begin(), s2.end(),
			nocase_compare());
	}
};

inline int ci_find_substr(std::string_view haystack, std::string_view needle)
{
	auto iter = std::search(std::begin(haystack), std::end(haystack),
		std::begin(needle), std::end(needle), ci_less::nocase_compare());
	if (iter == std::end(haystack)) return -1;
	return iter - std::begin(haystack);
}

// todo implement a better ci_starts_with that doesn't search past needle.length chars
inline bool ci_starts_with(std::string_view haystack, std::string_view needle)
{
	return ci_find_substr(haystack, needle) == 0;
}

inline bool ci_equals(std::string_view sv1, std::string_view sv2)
{
	return sv1.size() == sv2.size()
		&& std::equal(sv1.begin(), sv1.end(), sv2.begin(), ci_less::nocase_compare());
}

inline bool ci_equals(std::string_view haystack, std::string_view needle, bool isExact)
{
	if (isExact)
		return ci_equals(haystack, needle);

	return ci_find_substr(haystack, needle) != -1;
}

inline bool string_equals(std::string_view sv1, std::string_view sv2)
{
	return sv1.size() == sv2.size()
		&& std::equal(sv1.begin(), sv1.end(), sv2.begin());
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
