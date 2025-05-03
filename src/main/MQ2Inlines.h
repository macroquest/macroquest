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

#pragma once

#include "mq/base/Config.h"
#include "mq/base/String.h"
#include "mq/base/Utility.h"

#include "mq/api/Spawns.h"
#include "mq/api/Abilities.h"

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

inline eqlib::PcClient* GetCharInfo()
{
	// FYI: pPCData and pCharData point to the same address as pLocalPC
	return eqlib::pLocalPC;
}

inline eqlib::PcProfile* GetPcProfile()
{
	return eqlib::pLocalPC ? eqlib::pLocalPC->GetCurrentPcProfile() : nullptr;
}

DEPRECATE("Use GetPcProfile instead of GetCharInfo2()")
inline eqlib::PcProfile* GetCharInfo2()
{
	return GetPcProfile();
}

inline eqlib::PlayerClient* GetSpawnByID(DWORD dwSpawnID)
{
	return eqlib::pSpawnManager->GetSpawnByID(dwSpawnID);
}

inline eqlib::PlayerClient* GetSpawnByName(const char* spawnName)
{
	return eqlib::pSpawnManager->GetSpawnByName(spawnName);
}

inline eqlib::PlayerClient* GetSpawnByPartialName(char const* spawnName, eqlib::PlayerBase* exclusion = nullptr)
{
	return eqlib::pSpawnManager->GetPlayerFromPartialName(spawnName, exclusion);
}

inline eqlib::EQ_Spell* GetSpellByID(int spellID)
{
	if (!eqlib::pSpellMgr || spellID <= 0 || spellID >= eqlib::pSpellMgr->GetMaxSpellID())
		return nullptr;

	return eqlib::pSpellMgr->GetSpellByID(spellID);
}

inline const char* GetBodyTypeDesc(uint32_t BodyTypeID)
{
	if (BodyTypeID < eqlib::CharacterProperty_Last && BodyTypeID >= eqlib::CharacterProperty_None)
		return szBodyType[BodyTypeID];

	return "*UNKNOWN BODYTYPE";
}

inline const char* GetClassDesc(int ClassID)
{
	using namespace eqlib;

	switch (ClassID)
	{
	case Class_Adventure:
		return "LDoN Recruiter";
	case Class_AdventureMerchant:
		return "LDoN Merchant";
	case Class_Object:
		return "Destructible Object";
	case Class_TributeMaster:
	case Class_TributeMaster2:
		return "Tribute Master";
	case Class_GuildTributeMaster:
		return "Guild Tribute Master";
	case Class_GuildBanker:
		return "Guild Banker";
	case Class_GoodPointMerchant:
		return "Good DoN Merchant";
	case Class_EvilPointMerchant:
		return "Evil DoN Merchant";
	case Class_FellowshipMaster:
		return "Fellowship Registrar";
	case Class_PointMerchant:
		return "Merchant";
	case Class_MercenaryMerchant:
		return "Mercenary Liaison";
	case Class_RealEstateMerchant:
		return "Real Estate Merchant";
	case Class_LoyaltyMerchant:
		return "Loyalty Merchant";

	// special mq-only magic values
	case MQClass_Aura:
		return "Aura";
	case MQClass_Banner:
		return "Banner";
	case MQClass_CampFire:
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

inline int GetEnduranceRegen()
{
	return eqlib::pLocalPC ? eqlib::pLocalPC->GetEnduranceRegen(true, false) : 0;
}

inline int GetHPRegen()
{
	// the client sets it to true on return if we are bleeding.
	bool bBleed = false;
	return eqlib::pLocalPC ? eqlib::pLocalPC->GetHPRegen(true, &bBleed, false) : 0;
}

inline int GetManaRegen()
{
	return eqlib::pLocalPC ? eqlib::pLocalPC->GetManaRegen(true, false) : 0;
}

inline int GetCurMana()
{
	return eqlib::pLocalPC ? eqlib::pLocalPC->Cur_Mana(true) : 0;
}

inline int GetCurHPS()
{
	return eqlib::pLocalPC ? eqlib::pLocalPC->Cur_HP(0) : 0;
}

inline int GetMaxHPS()
{
	return eqlib::pLocalPC ? eqlib::pLocalPC->Max_HP(0) : 0;
}

inline int GetMaxEndurance()
{
	return eqlib::pLocalPC ? eqlib::pLocalPC->Max_Endurance() : 0;
}

inline int GetCurEndurance()
{
	eqlib::PcProfile* pProfile = GetPcProfile();
	return pProfile ? pProfile->Endurance : 0;
}

inline int GetMaxMana()
{
	return eqlib::pLocalPC ? eqlib::pLocalPC->Max_Mana() : 0;
}

inline int GetModCap(int index, bool bToggle = false)
{
	return eqlib::pLocalPC ? eqlib::pLocalPC->GetModCap(index, bToggle) : 0;
}

inline int GetCastingTimeModifier(const eqlib::EQ_Spell* cSpell)
{
	return eqlib::pLocalPC ? eqlib::pLocalPC->GetCastingTimeModifier(cSpell) : 0;
}

inline int GetFocusCastingTimeModifier(const eqlib::EQ_Spell* pSpell, eqlib::ItemPtr& pItemOut, bool bEvalOnly)
{
	return eqlib::pLocalPC ? eqlib::pLocalPC->GetFocusCastingTimeModifier(pSpell, pItemOut, bEvalOnly) : 0;
}

inline int GetFocusRangeModifier(const eqlib::EQ_Spell* pSpell, eqlib::ItemPtr& pItemOut)
{
	return eqlib::pLocalPC ? eqlib::pLocalPC->GetFocusRangeModifier(pSpell, pItemOut) : 0;
}

inline float GetDistance(float X1, float Y1)
{
	float dX = X1 - eqlib::pControlledPlayer->X;
	float dY = Y1 - eqlib::pControlledPlayer->Y;
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
inline float GetDistance(eqlib::PlayerClient* pChar, eqlib::PlayerClient* pSpawn)
{
	float X = pChar->X - pSpawn->X;
	float Y = pChar->Y - pSpawn->Y;
	return sqrtf(X * X + Y * Y);
}

inline float GetDistanceSquared(eqlib::PlayerClient* pChar, eqlib::PlayerClient* pSpawn)
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

inline float DistanceToSpawn(eqlib::PlayerClient* pChar, eqlib::PlayerClient* pSpawn)
{
	return GetDistance(pChar, pSpawn);
}

template <typename T1, typename T2>
inline float Distance3DToSpawn(const T1& pSpawn1, const T2& pSpawn2)
{
	return Get3DDistance(
		pSpawn1->X, pSpawn1->Y, pSpawn1->Z,
		pSpawn2->X, pSpawn2->Y, pSpawn2->Z);
}

template <typename T1>
inline float Distance3DToSpawn(const T1& pSpawn1, const MQGameObject& gameObj)
{
	return  Get3DDistance(
		pSpawn1->X, pSpawn1->Y, pSpawn1->Z,
		gameObj.x, gameObj.y, gameObj.z);
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
// FindMount(PlayerClient*) - Used to find the mount of a spawn, if one
//                            exists. returns the spawn if one does not.
// ***************************************************************************
inline eqlib::PlayerClient* FindMount(eqlib::PlayerClient* pSpawn)
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

inline bool LineOfSight(eqlib::PlayerClient* Origin, const eqlib::CVector3& position)
{
	if (!Origin)
		return false;

	return Origin->CanSee(position);
}

inline bool LineOfSight(eqlib::PlayerClient* Origin, eqlib::PlayerClient* CanISeeThis)
{
	if (!Origin || !CanISeeThis)
		return false;

	return Origin->CanSee(*CanISeeThis);
}

inline bool IsMobFleeing(eqlib::PlayerClient* pChar, eqlib::PlayerClient* pSpawn)
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
	if (index < 0 || index > 15)
		return -1;

	return eqlib::pLocalPC ? eqlib::pLocalPC->GetMemorizedSpell(index) : -1;
}

inline int GetSpellDuration(eqlib::EQ_Spell* pSpell, unsigned char casterLevel, bool isItemEffect)
{
	return eqlib::pLocalPC ? eqlib::pLocalPC->SpellDuration(pSpell, casterLevel, isItemEffect) : 0;
}

inline int GetSpellDuration(eqlib::EQ_Spell* pSpell, eqlib::PlayerClient* pSpawn)
{
	return GetSpellDuration(pSpell, pSpawn ? pSpawn->Level : 0, false);
}

DEPRECATE("Use GetSpellDuration instead of EQGetSpellDuration")
inline int EQGetSpellDuration(eqlib::EQ_Spell* pSpell, unsigned char casterLevel, bool isItemEffect)
{
	return GetSpellDuration(pSpell, casterLevel, isItemEffect);
}

inline int GetMySpellDuration(eqlib::EQ_Spell* pSpell)
{
	if (!eqlib::pLocalPlayer)
		return 0;
	if (!pSpell)
		return 0;

	int origDuration = GetSpellDuration(pSpell, eqlib::pLocalPlayer->Level, false);

	int out1 = 0, out2 = 0;
	eqlib::ItemPtr pContents;

	int durationMod = eqlib::pLocalPC->GetFocusDurationMod(pSpell, pContents, eqlib::pLocalPlayer, origDuration, &out1, &out2);

	return origDuration + durationMod;
}

inline int GetSpellNumEffects(eqlib::EQ_Spell* pSpell)
{
	return pSpell ? pSpell->GetNumEffects() : 0;
}

inline bool IsPlayerClass(int Class)
{
	return Class >= eqlib::Warrior && Class <= eqlib::Berserker;
}

inline bool CanTank(int Class)
{
	switch (Class)
	{
	case eqlib::Warrior:
	case eqlib::Shadowknight:
	case eqlib::Paladin:
		return true;
	}

	return false;
}

inline const char* GetSpellString(int ID, int SpellIndex)
{
	// FIXME: emu - move this to eqlib
#if defined(pinstEQSpellStrings_x)
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
#else
	if (eqlib::EQ_Spell* pSpell = GetSpellByID(ID))
	{
		switch (SpellIndex)
		{
		case eqlib::SpellStringCastByMe:
		//	if (pSpell->CastByMe[0])
		//		return pSpell->CastByMe;
		//	break;
		//
		case eqlib::SpellStringCastByOther:
		//	if (pSpell->CastByOther[0])
		//		return pSpell->CastByOther;

		case eqlib::SpellStringCastOnYou:
		//	if (pSpell->CastOnYou[0])
		//		return pSpell->CastOnYou;
		//	break;
		case eqlib::SpellStringCastOnAnother:
		//	if (pSpell->CastOnAnother[0])
		//		return pSpell->CastOnAnother;
		//	break;
		case eqlib::SpellStringWearOff:
		//	if (pSpell->WearOff[0])
		//		return pSpell->WearOff;
		//	break;
		default:
			break;
		}
	}
#endif
	return nullptr;
}

inline bool MaybeExactCompare(std::string_view haystack, std::string_view needle)
{
	if (needle.empty())
		return haystack.empty();

	bool exact = false;

	if (needle[0] == '=')
	{
		needle = needle.substr(1);
		exact = true;
	}

	return ci_equals(haystack, needle, exact);
}

enum class StringMatchType {
	Exact,
	CaseInsensitive,
	CaseInsensitiveSubstring,
	CaseInsensitiveWithSentinel,        // treat as substring or match, based on presence of '='
};

inline bool StringCompare(std::string_view haystack, std::string_view needle,
	StringMatchType matchType = StringMatchType::CaseInsensitive)
{
	switch (matchType)
	{
	case StringMatchType::Exact:
		return haystack.size() == needle.size()
			&& std::equal(haystack.begin(), haystack.end(), needle.begin());
	case StringMatchType::CaseInsensitive:
		return ci_equals(haystack, needle);
	case StringMatchType::CaseInsensitiveSubstring:
		return ci_find_substr(haystack, needle);
	case StringMatchType::CaseInsensitiveWithSentinel:
		return MaybeExactCompare(haystack, needle);

	default: return false;
	}
}

DEPRECATE("GetCXStr: This function is no longer needed. CXStr can now be used like a std::string")
inline eqlib::CXStr::size_type GetCXStr(eqlib::CXStr* pCXStr, char* szBuffer, uint32_t length = MAX_STRING)
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

DEPRECATE("GetCXStr: This function is no longer needed. CXStr can now be used normally like a std::string")
inline eqlib::CXStr::size_type GetCXStr(eqlib::CXStr& str, char* szBuffer, uint32_t length = MAX_STRING)
{
#pragma warning(suppress: 4996)
	return GetCXStr(&str, szBuffer, length);
}

DEPRECATE("SetCXStr: This function is no longer needed. CXStr can now be used normally like a std::string")
inline void SetCXStr(eqlib::CXStr* pCXStr, const char* text)
{
	if (pCXStr)
	{
		*pCXStr = text;
	}
}

DEPRECATE("SetCXStr: This function is no longer needed. CXStr can now be used normally like a std::string")
inline void SetCXStr(eqlib::CXStr& str, const char* text)
{
#pragma warning(suppress: 4996)
	return SetCXStr(&str, text);
}

DEPRECATE("AppendCXStr: This function is no longer needed. CXStr can now be used normally like a std::string")
inline void AppendCXStr(eqlib::CXStr* pCXStr, const char* text)
{
	if (pCXStr)
	{
		*pCXStr += text;
	}
}

inline bool IsEvolvingItem(eqlib::ItemClient* pContents)
{
	return pContents->pEvolutionData != nullptr;
}

} // namespace mq
