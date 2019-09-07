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

EQLIB_API char* CleanupName(char* szName, size_t BufferSize, bool Article = true, bool ForWhoList = true);

inline CHARINFO* GetCharInfo()
{
	// pPCData and pCharData points to same address
	return (CHARINFO*)pCharData;
}

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

	long absedspellid = abs(dwSpellID);
	if (absedspellid >= TOTAL_SPELL_COUNT)
		return nullptr;

	return &(*((PSPELLMGR)pSpellMgr)->Spells[absedspellid]);
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
	if (CHARINFO2* pChar2 = GetCharInfo2())
	{
		return pChar2->Endurance;
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
		//ok so as far as i can tell RefCount gets increased by us calling this function
		//and its weird that it's no decremented properly afterwards
		//it's possible we don't understand this, but there is also a chance this
		//is a real serious eq bug, either way, decrementing it after the return
		//seems to work...
		//if they ever fix this, we must remove our decrement here...
		int ret = pCharData->GetFocusCastingTimeModifier(pSpell, pItemOut, bEvalOnly);

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

// ***************************************************************************
// Function:    GetCharMaxBuffSlots
// Description: Returns the max number of buff slots available for a character
// ***************************************************************************
inline int GetCharMaxBuffSlots()
{
	int NumBuffs = 15;

	if (CHARINFO* pChar = GetCharInfo())
	{
		if (pChar->vtable2)
		{
			NumBuffs += pCharData->TotalEffect(327, 1, 0, 1, 1);
		}

		if (pChar->pSpawn && pChar->pSpawn->Level > 70)
			NumBuffs++;
		if (pChar->pSpawn && pChar->pSpawn->Level > 74)
			NumBuffs++;
	}

	return NumBuffs;
}

inline int GetBodyType(SPAWNINFO* pSpawn)
{
	for (int i = 0; i < 104; i++)
	{
		PlayerClient* pc = (PlayerClient*)pSpawn;

		if (pc->HasProperty(i, 0, 0))
		{
			if (i == 100)
			{
				if (pc->HasProperty(i, 101, 0))
					return 101;
				if (pc->HasProperty(i, 102, 0))
					return 102;
				if (pc->HasProperty(i, 103, 0))
					return 103;
			}
			return i;
		}
	}

	return 0;
}

inline eSpawnType GetSpawnType(SPAWNINFO* pSpawn)
{
	switch (pSpawn->Type)
	{
	case SPAWN_PLAYER:
		return PC;

	case SPAWN_NPC:
		if (pSpawn->Rider)
			return MOUNT;

		if (pSpawn->MasterID)
			return PET;
		if (pSpawn->Mercenary)
			return MERCENARY;

		// some type of controller spawn for flying mobs - locations, speed, heading, all NaN
		if (IsNaN(pSpawn->Y) && IsNaN(pSpawn->X) && IsNaN(pSpawn->Z))
			return FLYER;

		switch (GetBodyType(pSpawn))
		{
		case 0:
			if (pSpawn->mActorClient.Class == 62)
				return OBJECT;
			return NPC;

		case 1:
			if (pSpawn->mActorClient.Race == 567)
				return CAMPFIRE;
			if (pSpawn->mActorClient.Race == 500 || (pSpawn->mActorClient.Race >= 553 && pSpawn->mActorClient.Race <= 557) || pSpawn->mActorClient.Race == 586)
				return BANNER;
			return NPC;

		//case 3:
		//    return NPC;

		case 5:
			if (strstr(pSpawn->Name, "Idol") || strstr(pSpawn->Name, "Poison") || strstr(pSpawn->Name, "Rune"))
				return AURA;
			if (pSpawn->mActorClient.Class == 62)
				return OBJECT;
			return NPC;

		case 7:
			if (pSpawn->mActorClient.Class == 62)
				return OBJECT;
			return NPC;

		case 11:
			if (strstr(pSpawn->Name, "Aura") || strstr(pSpawn->Name, "Circle_of") || strstr(pSpawn->Name, "Guardian_Circle") || strstr(pSpawn->Name, "Earthen_Strength"))
				return AURA;
			return UNTARGETABLE;

		//case 21:
		//    return NPC;
		//case 23:
		//    return NPC;

		case 33:
			return CHEST;

		//case 34:
		//    return NPC;
		//case 65:
		//    return TRAP;
		//case 66:
		//    return TIMER;
		//case 67:
		//    return TRIGGER;

		case 100:
			return UNTARGETABLE
				;
		case 101:
			return TRAP;

		case 102:
			return TIMER;

		case 103:
			return TRIGGER;

		default: break;
		}
		return NPC;

	case SPAWN_CORPSE:
		return CORPSE;

	default: break;
	}

	return ITEM;
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

#define DistanceToSpawn(pChar, pSpawn) \
	GetDistance(pChar, pSpawn)
#define Distance3DToSpawn(pSpawn1, pSpawn2) \
	Get3DDistance(((SPAWNINFO*)pSpawn1)->X, ((SPAWNINFO*)pSpawn1)->Y, ((SPAWNINFO*)pSpawn1)->Z, \
	              ((SPAWNINFO*)pSpawn2)->X, ((SPAWNINFO*)pSpawn2)->Y, ((SPAWNINFO*)pSpawn2)->Z)

#define _FileExists(filename) ((_access( filename, 0 )) != -1)

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

inline bool IsRaidMember(const char* SpawnName)
{
	if (pRaid && pRaid->Invited == 4)
	{
		for (int index = 0; index < 72; index++)
		{
			if (pRaid->RaidMemberUsed[index] && !_stricmp(SpawnName, pRaid->RaidMember[index].Name))
				return true;
		}
	}

	return false;
}

inline int GetRaidMemberIndex(const char* SpawnName)
{
	if (pRaid && pRaid->Invited == 4)
	{
		for (int index = 0; index < 72; index++)
		{
			if (pRaid->RaidMemberUsed[index] && !_stricmp(SpawnName, pRaid->RaidMember[index].Name))
				return index;
		}
	}

	return -1;
}

inline bool IsRaidMember(SPAWNINFO* pSpawn)
{
	for (int index = 0; index < 72; index++)
	{
		if (pRaid->RaidMemberUsed[index] && !_stricmp(pSpawn->Name, pRaid->RaidMember[index].Name))
			return true;
	}

	return false;
}

inline int GetRaidMemberIndex(SPAWNINFO* pSpawn)
{
	for (int index = 0; index < 72; index++)
	{
		if (pRaid->RaidMemberUsed[index] && !_stricmp(pSpawn->Name, pRaid->RaidMember[index].Name))
			return index;
	}

	return -1;
}

inline bool IsGroupMember(const char* SpawnName)
{
	if (CHARINFO* pChar = GetCharInfo())
	{
		if (!pChar->pGroupInfo)
			return nullptr;

		for (int index = 1; index < 6; index++)
		{
			if (pChar->pGroupInfo->pMember[index])
			{
				char Name[MAX_STRING] = { 0 };
				strcpy_s(Name, pChar->pGroupInfo->pMember[index]->Name.c_str());

				CleanupName(Name, sizeof(Name), false, false);

				if (!_stricmp(SpawnName, Name))
					return true;
			}
		}
	}

	return false;
}

inline bool IsGroupMember(SPAWNINFO* pSpawn)
{
	if (CHARINFO* pChar = GetCharInfo())
	{
		if (!pChar->pGroupInfo)
			return false;

		for (int index = 1; index < 6; index++)
		{
			if (pChar->pGroupInfo->pMember[index])
			{
				char Name[MAX_STRING] = { 0 };
				strcpy_s(Name, pChar->pGroupInfo->pMember[index]->Name.c_str());

				//CleanupName(Name, sizeof(Name), false, false);

				if (!_stricmp(pSpawn->Name, Name))
					return true;
			}
		}
	}

	return false;
}

inline bool IsFellowshipMember(const char* SpawnName)
{
	if (CHARINFO* pChar = GetCharInfo())
	{
		if (!pChar->pFellowship)
			return false;

		for (int index = 0; index < pChar->pFellowship->Members; index++)
		{
			if (!_stricmp(SpawnName, pChar->pFellowship->FellowshipMember[index].Name))
				return true;
		}
	}

	return false;
}

inline bool IsGuildMember(const char* SpawnName)
{
	if (CHARINFO* pChar = GetCharInfo())
	{
		if (pChar->GuildID == 0)
			return false;

		if (pGuild)
		{
			if (GuildMember* mem = pGuild->FindMemberByName(SpawnName))
			{
				if (!_stricmp(SpawnName, mem->Name))
					return true;
			}
		}
	}

	return false;
}

inline int GetGroupMercenaryCount(uint32_t ClassMASK)
{
	int retValue = 0;

	if (CHARINFO* pChar = GetCharInfo())
	{
		if (!pChar->pGroupInfo)
			return 0;

		for (int index = 1; index < 6; index++)
		{
			if (pChar->pGroupInfo->pMember[index])
			{
				if (pChar->pGroupInfo->pMember[index]->Mercenary
					&& (ClassMASK & (1 << (pChar->pGroupInfo->pMember[index]->pSpawn->mActorClient.Class - 1))))
				{
					retValue++;
				}
			}
		}
	}

	return retValue;
}

inline SPAWNINFO* GetRaidMember(int index)
{
	if (index >= 72)
		return nullptr;

	PEQRAIDMEMBER pRaidMember = &pRaid->RaidMember[index];

	if (!pRaidMember)
		return nullptr;

	return (SPAWNINFO*)GetSpawnByName(pRaidMember->Name);
}

inline SPAWNINFO* GetGroupMember(int index)
{
	if (index > 5)
		return nullptr;

	CHARINFO* pChar = GetCharInfo();
	if (!pChar->pGroupInfo)
		return nullptr;

	for (int i = 1; i < 6; i++)
	{
		if (pChar->pGroupInfo->pMember[i])
		{
			index--;

			if (index == 0)
			{
				// FIXME: Why a copy?
				char Name[MAX_STRING] = { 0 };
				strcpy_s(Name, pChar->pGroupInfo->pMember[i]->Name.c_str());

				return (SPAWNINFO*)GetSpawnByName(Name);
			}
		}
	}

	return nullptr;
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

// Deprecated: Forwards to MQGetTickCount64()
inline [[deprecated("Use GetTickCount64() instead")]] uint64_t GetTickCount642()
{
	return MQGetTickCount64();
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

inline uint32_t GetGroupMainAssistTargetID()
{
	if (CHARINFO* pChar = GetCharInfo())
	{
		bool bMainAssist = false;

		if (GROUPINFO* pGroup = pChar->pGroupInfo)
		{
			if (GROUPMEMBER* pMember = pGroup->pMember[0])
			{
				for (int i = 0; i < 6; i++)
				{
					if (pGroup->pMember[i])
					{
						if (pGroup->pMember[i]->MainAssist)
						{
							bMainAssist = true;
							break;
						}
					}
				}
			}
		}

		if (bMainAssist && pChar->pSpawn)
		{
			return pChar->pSpawn->GroupAssistNPC[0];
		}
	}

	return 0;
}

inline uint32_t GetRaidMainAssistTargetID(int index)
{
	if (SPAWNINFO* pSpawn = (SPAWNINFO*)pLocalPlayer)
	{
		if (pRaid)
		{
			bool bMainAssist = false;

			for (int i = 0; i < 72; i++)
			{
				if (pRaid->RaidMemberUsed[i] && pRaid->RaidMember[i].RaidMainAssist)
				{
					bMainAssist = true;
					break;
				}
			}

			if (bMainAssist)
			{
				if (index < 0 || index > 3)
					index = 0;

				return pSpawn->RaidAssistNPC[index];
			}
		}
	}

	return 0;
}

inline bool IsAssistNPC(SPAWNINFO* pSpawn)
{
	if (pSpawn)
	{
		if (uint32_t AssistID = GetGroupMainAssistTargetID())
		{
			if (AssistID == pSpawn->SpawnID)
			{
				return true;
			}
		}

		for (int nAssist = 0; nAssist < 3; nAssist++)
		{
			if (uint32_t AssistID = GetRaidMainAssistTargetID(nAssist))
			{
				if (AssistID == pSpawn->SpawnID)
				{
					return true;
				}
			}
		}
	}

	return false;
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
