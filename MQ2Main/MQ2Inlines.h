/*****************************************************************************
MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License, version 2, as published by
the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
******************************************************************************/
//string trim includes:
#include <algorithm> 
#include <cctype>
#include <locale>

EQLIB_API PCHAR       CleanupName(PCHAR szName, SIZE_T BufferSize, BOOL Article = TRUE, BOOL ForWhoList = TRUE);

static inline PCHARINFO GetCharInfo(VOID) {
	//   if (!ppCharData) return NULL;
	//pPCData and pCharData points to same address
	return (PCHARINFO)pCharData;
}

static inline PCHARINFO2 GetCharInfo2(VOID) {
	if (PCHARINFO pChar = (PCHARINFO)pCharData) {
		if (pChar->ProfileManager.pFirst) {
		return (PCHARINFO2)pChar->ProfileManager.GetCurrentProfile();
		}
	}
	return NULL;
}

static inline EQPlayer *GetSpawnByID(DWORD dwSpawnID)
{
	//    if (dwSpawnID<3000)
	//        return ppEQP_IDArray[dwSpawnID];
	return pSpawnManager->GetSpawnByID(dwSpawnID);
}

static inline EQPlayer *GetSpawnByName(char *spawnName)
{
	return pSpawnManager->GetSpawnByName(spawnName);
}

static inline EQPlayer *GetSpawnByPartialName(char const *spawnName, class PlayerBase *pbase = 0)
{
	return pSpawnManager->GetPlayerFromPartialName(spawnName, pbase);
}

static inline PSPELL GetSpellByID(LONG dwSpellID)
{
	if (dwSpellID == 0 || dwSpellID == -1)
		return NULL;
	long absedspellid = abs(dwSpellID);
	if (absedspellid >= TOTAL_SPELL_COUNT)
		return NULL;
	return &(*((PSPELLMGR)pSpellMgr)->Spells[absedspellid]);
}

static inline PCHAR GetBodyTypeDesc(DWORD BodyTypeID)
{
	if (BodyTypeID<104 && BodyTypeID >= 0)
		return szBodyType[BodyTypeID];
	return "*UNKNOWN BODYTYPE";
}

static inline PCHAR GetClassDesc(DWORD ClassID)
{
	switch (ClassID) {
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

static inline BOOL IsMarkedNPC(PSPAWNINFO pSpawn)
{
	if (GetCharInfo() && GetCharInfo()->pSpawn && pSpawn)
	{
		DWORD nMark;
		for (nMark = 0; nMark < 3; nMark++)
		{
			if (GetCharInfo()->pSpawn->RaidMarkNPC[nMark] == pSpawn->SpawnID)
			{
				return true;
			}
		}
		for (nMark = 0; nMark < 3; nMark++)
		{
			if (GetCharInfo()->pSpawn->GroupMarkNPC[nMark] == pSpawn->SpawnID)
			{
				return true;
			}
		}
	}
	return false;
}

static inline int GetEnduranceRegen() {
	if (PCHARINFO pChar = GetCharInfo()) {
#ifdef NEWCHARINFO
		if (pChar->PcClient_CharacterZoneClient_vfTable) {
#else
		if (pChar->vtable2) {
#endif
			return pCharData1->GetEnduranceRegen(true, false);
		}
	}
	return 0;
}
static inline int GetHPRegen() {
	if (PCHARINFO pChar = GetCharInfo()) {
#ifdef NEWCHARINFO
		if (pChar->PcClient_CharacterZoneClient_vfTable) {
#else
		if (pChar->vtable2) {
#endif
			bool bBleed = false;//yes this is correct it should be false initially, the client sets it to true on return if we are indeed bleeding.
			return pCharData1->GetHPRegen(true, &bBleed, false);
		}
	}
	return 0;
}
static inline int GetManaRegen() {
	if (PCHARINFO pChar = GetCharInfo()) {
#ifdef NEWCHARINFO
		if (pChar->PcClient_CharacterZoneClient_vfTable) {
#else
		if (pChar->vtable2) {
#endif
			return pCharData1->GetManaRegen(true, false);
		}
	}
	return 0;
}
static inline int GetCurMana() {
	if (PCHARINFO pChar = GetCharInfo()) {
#ifdef NEWCHARINFO
		if (pChar->PcClient_CharacterZoneClient_vfTable) {
#else
		if (pChar->vtable2) {
#endif
			return ((EQ_Character*)pCharData1)->Cur_Mana(true);
		}
	}
	return 0;
}
static inline int GetCurHPS() {
	if (PCHARINFO pChar = GetCharInfo()) {
#ifdef NEWCHARINFO
		if (pChar->PcClient_CharacterZoneClient_vfTable) {
#else
		if (pChar->vtable2) {
#endif
			return pCharData1->Cur_HP(0);
		}
	}
	return 0;
}
static inline LONG GetMaxHPS() {
	if (PCHARINFO pChar = GetCharInfo()) {
#ifdef NEWCHARINFO
		if (pChar->PcClient_CharacterZoneClient_vfTable) {
#else
		if (pChar->vtable2) {
#endif
			return pCharData1->Max_HP(0);
		}
	}
	return 0;
}
static inline LONG GetMaxEndurance() {
	if (PCHARINFO pChar = GetCharInfo()) {
#ifdef NEWCHARINFO
		if (pChar->PcClient_CharacterZoneClient_vfTable) {
#else
		if (pChar->vtable2) {
#endif
			return pCharData1->Max_Endurance();
		}
	}
	return 0;
}
static inline LONG GetCurEndurance() {
	if (PCHARINFO2 pChar2 = GetCharInfo2()) {
		return pChar2->Endurance;
	}
	return 0;
}
static inline LONG GetMaxMana() {
	if (PCHARINFO pChar = GetCharInfo()) {
#ifdef NEWCHARINFO
		if (pChar->PcClient_CharacterZoneClient_vfTable) {
#else
		if (pChar->vtable2) {
#endif
			return pCharData1->Max_Mana();
		}
	}
	return 0;
}
static inline int GetAdjustedSkill(int nSkill) {
	if (PCHARINFO pChar = GetCharInfo()) {
#ifdef NEWCHARINFO
		if (pChar->PcClient_CharacterZoneClient_vfTable) {
#else
		if (pChar->vtable2) {
#endif
			return pCharData1->GetAdjustedSkill(nSkill);
		}
	}
	return 0;
}
static inline int GetBaseSkill(int nSkill) {
	if (PCHARINFO pChar = GetCharInfo()) {
#ifdef NEWCHARINFO
		if (pChar->PcClient_CharacterZoneClient_vfTable) {
#else
		if (pChar->vtable2) {
#endif
			return pCharData1->GetBaseSkill(nSkill);
		}
	}
	return 0;
}
static inline int GetModCap(int index, bool bToggle = false) {
	if (PCHARINFO pChar = GetCharInfo()) {
#ifdef NEWCHARINFO
		if (pChar->PcClient_CharacterZoneClient_vfTable) {
#else
		if (pChar->vtable2) {
#endif
			#if !defined(ROF2EMU) && !defined(UFEMU)
			return ((PcZoneClient*)pCharData1)->GetModCap(index, bToggle);
			#else
			return ((PcZoneClient*)pCharData1)->GetModCap(index);
			#endif
		}
	}
	return 0;
}
static inline const int GetCastingTimeModifier(const EQ_Spell  * cSpell) {
	if (PCHARINFO pChar = GetCharInfo()) {
#ifdef NEWCHARINFO
		if (pChar->PcClient_CharacterZoneClient_vfTable) {
#else
		if (pChar->vtable2) {
#endif
			return pCharData1->GetCastingTimeModifier(cSpell);
		}
	}
	return 0;
}
//const int EQ_Character1::GetFocusCastingTimeModifier(const EQ_Spell*pSpell, VePointer<ItemBase>&pItemOut, bool bEvalOnly = false);
static inline const int GetFocusCastingTimeModifier(const EQ_Spell* pSpell, VePointer<CONTENTS>& pItemOut, bool bEvalOnly) {
	if (PCHARINFO pChar = GetCharInfo()) {
		//ok so as far as i can tell RefCount gets increased by us calling this function
		//and its weird that it's no decremented properly afterwards
		//it's possible we don't understand this, but there is also a chance this
		//is a real serious eq bug, either way, decrementing it after the return
		//seems to work...
		//if they ever fix this, we must remove our decrement here...
#ifdef NEWCHARINFO
		if (pChar->PcClient_CharacterZoneClient_vfTable) {
			int ret = ((EQ_Character1*)&pChar->PcClient_CharacterZoneClient_vfTable)->GetFocusCastingTimeModifier(pSpell, pItemOut, bEvalOnly);
#else
		if (pChar->vtable2) {
			int ret = ((EQ_Character1*)&pChar->vtable2)->GetFocusCastingTimeModifier(pSpell, pItemOut, bEvalOnly);
#endif
			if (pItemOut.pObject)
			{
				InterlockedDecrement((long volatile*)&pItemOut.pObject->RefCount);
			}
			return ret;
		}
	}
	return 0;
}
static inline const int GetFocusRangeModifier(const EQ_Spell *pSpell, VePointer<CONTENTS>& pItemOut) {
	if (PCHARINFO pChar = GetCharInfo()) {
#ifdef NEWCHARINFO
		if (pChar->PcClient_CharacterZoneClient_vfTable) {
			int ret = ((EQ_Character1*)&pChar->PcClient_CharacterZoneClient_vfTable)->GetFocusRangeModifier(pSpell, pItemOut);
#else
		if (pChar->vtable2) {
			int ret = ((EQ_Character1*)&pChar->vtable2)->GetFocusRangeModifier(pSpell, pItemOut);
#endif
			if (pItemOut.pObject)
			{
				InterlockedDecrement((long volatile*)&((PCONTENTS)pItemOut.pObject)->RefCount);
			}
			return ret;
		}
	}
	return 0;
}
static inline bool HasSkill(int nSkill) {
	if (PCHARINFO pChar = GetCharInfo()) {
#ifdef NEWCHARINFO
		if (pChar->PcClient_CharacterZoneClient_vfTable) {
#else
		if (pChar->vtable2) {
#endif
			return ((CharacterZoneClient*)pCharData1)->HasSkill(nSkill);
		}
	}
	return false;
}

// ***************************************************************************
// Function:    GetCharMaxBuffSlots
// Description: Returns the max number of buff slots available for a character
// ***************************************************************************
static inline DWORD GetCharMaxBuffSlots()
{
	DWORD NumBuffs = 15;

	if (PCHARINFO pChar = GetCharInfo()) {
#ifdef NEWCHARINFO
		if (pChar->PcClient_CharacterZoneClient_vfTable) {
#else
		if (pChar->vtable2) {
#endif
			NumBuffs += pCharData1->TotalEffect(327, 1, 0, 1, 1);
		}
		if (pChar->pSpawn && pChar->pSpawn->Level > 70) NumBuffs++;
		if (pChar->pSpawn && pChar->pSpawn->Level > 74) NumBuffs++;
	}
	return NumBuffs;
}

static inline DWORD GetBodyType(PSPAWNINFO pSpawn)
{
	for (int i = 0; i<104; i++)
	{
		if (((EQPlayer*)pSpawn)->HasProperty(i, 0, 0))
		{
			if (i == 100)
			{
				if (((EQPlayer*)pSpawn)->HasProperty(i, 101, 0))
					return 101;
				if (((EQPlayer*)pSpawn)->HasProperty(i, 102, 0))
					return 102;
				if (((EQPlayer*)pSpawn)->HasProperty(i, 103, 0))
					return 103;
			}
			return i;
		}
	}
	return 0;
}

static inline eSpawnType GetSpawnType(PSPAWNINFO pSpawn)
{
	switch (pSpawn->Type)
	{
	case SPAWN_PLAYER:
	{
		return PC;
	}
	case SPAWN_NPC:
		if (pSpawn->Rider)
		{
			return MOUNT;
		}
		if (pSpawn->MasterID) {
			return PET;
		}
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
			return UNTARGETABLE;
		case 101:
			return TRAP;
		case 102:
			return TIMER;
		case 103:
			return TRIGGER;
		default:
			return NPC;
		}
		return NPC;
	case SPAWN_CORPSE:
		return CORPSE;
	default:
		return ITEM;
	}
}

static inline FLOAT GetDistance(FLOAT X1, FLOAT Y1)
{
	FLOAT dX = X1 - ((PSPAWNINFO)pCharSpawn)->X;
	FLOAT dY = Y1 - ((PSPAWNINFO)pCharSpawn)->Y;
	return sqrtf(dX*dX + dY*dY);
}

static inline FLOAT GetDistance(FLOAT X1, FLOAT Y1, FLOAT X2, FLOAT Y2)
{
	FLOAT dX = X1 - X2;
	FLOAT dY = Y1 - Y2;
	return sqrtf(dX*dX + dY*dY);
}

#ifndef ISXEQ
static inline FLOAT GetDistance3D(FLOAT X1, FLOAT Y1, FLOAT Z1, FLOAT X2, FLOAT Y2, FLOAT Z2)
{
	FLOAT dX = X1 - X2;
	FLOAT dY = Y1 - Y2;
	FLOAT dZ = Z1 - Z2;
	return sqrtf(dX*dX + dY*dY + dZ*dZ);
}
#endif


// ***************************************************************************
// Function:    DistanceToSpawn
// Description: Return the distance between two spawns
// ***************************************************************************
static inline FLOAT GetDistance(PSPAWNINFO pChar, PSPAWNINFO pSpawn)
{
	FLOAT X = pChar->X - pSpawn->X;
	FLOAT Y = pChar->Y - pSpawn->Y;
	//FLOAT Z = pChar->Z - pSpawn->Z;
	return sqrtf(X*X + Y*Y);// + Z*Z);
}
static inline FLOAT Get3DDistance(FLOAT X1, FLOAT Y1, FLOAT Z1, FLOAT X2, FLOAT Y2, FLOAT Z2)
{
	FLOAT dX = X1 - X2;
	FLOAT dY = Y1 - Y2;
	FLOAT dZ = Z1 - Z2;
	return sqrtf(dX*dX + dY*dY + dZ*dZ);
}
#define DistanceToSpawn(pChar,pSpawn) GetDistance(pChar,pSpawn)
#define Distance3DToSpawn(pChar,pSpawn) Get3DDistance(((PSPAWNINFO)pChar)->X,((PSPAWNINFO)pChar)->Y,((PSPAWNINFO)pChar)->Z,((PSPAWNINFO)pSpawn)->X,((PSPAWNINFO)pSpawn)->Y,((PSPAWNINFO)pSpawn)->Z)

#define _FileExists(filename) ( (_access( filename, 0 )) != -1 )
// ***************************************************************************
// FindMount(PSPAWNINFO) - Used to find the mount of a spawn, if one
//                         exists. returns the spawn if one does not.
// ***************************************************************************
static inline PSPAWNINFO FindMount(PSPAWNINFO pSpawn)
{
	return (pSpawn->Mount ? pSpawn->Mount : pSpawn);
}

// ***************************************************************************
// Function:    ConColorToRGB
// Description: Returns the RGB color for a con color
// ***************************************************************************
static inline DWORD ConColorToARGB(DWORD ConColor)
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
static inline int IsRaidMember(char * SpawnName)
{
	if (pRaid && pRaid->Invited == 4) {
		for (DWORD N = 0; N < 72; N++)
		{
			if (pRaid->RaidMemberUsed[N] && !_stricmp(SpawnName, pRaid->RaidMember[N].Name))
				return N;
		}
	}
	return -1;
}
static inline int IsRaidMember(PSPAWNINFO pSpawn)
{
	for (DWORD N = 0; N < 72; N++)
	{
		if (pRaid->RaidMemberUsed[N] && !_stricmp(pSpawn->Name, pRaid->RaidMember[N].Name))
			return N;
	}
	return -1;
}
static inline BOOL IsGroupMember(char * SpawnName)
{
	if (PCHARINFO pChar = GetCharInfo()) {
		if (!pChar->pGroupInfo)
			return 0;
		for (DWORD N = 1; N < 6; N++)
		{
			if (pChar->pGroupInfo->pMember[N])
			{
				CHAR Name[MAX_STRING] = { 0 };
				GetCXStr(pChar->pGroupInfo->pMember[N]->pName, Name, MAX_STRING);
				CleanupName(Name,sizeof(Name), FALSE, FALSE);
				if (!_stricmp(SpawnName, Name))
					return N;
			}
		}
	}
	return 0;
}
inline int IsFellowshipMember(const char* SpawnName)
{
	PSPAWNINFO pSpawn = (PSPAWNINFO)pLocalPlayer;
	if (!pSpawn)
		return 0;

	if (PFELLOWSHIPINFO pFellowship = &pSpawn->Fellowship)
	{

		for (int i = 0; i < pFellowship->Members; i++)
		{
			if (!_stricmp(SpawnName, pFellowship->FellowshipMember[i].Name))
				return 1;
		}
	}
	return 0;
}
static inline BOOL IsGuildMember(char * SpawnName)
{
	if (PCHARINFO pChar = GetCharInfo()) {
#ifdef NEWCHARINFO
		if (pChar->GuildID.GUID == 0)
#else
		if (pChar->GuildID == 0)
#endif
			return 0;
		if (pGuild) {
			if (PGUILDMEMBERCLIENT mem = (PGUILDMEMBERCLIENT)pGuild->FindMemberByName(SpawnName)) {
				if (!_stricmp(SpawnName, mem->Name))
					return 1;
			}
		}
	}
	return 0;
}

static inline BOOL IsGroupMember(PSPAWNINFO pSpawn)
{
	if (PCHARINFO pChar = GetCharInfo()) {
		if (!pChar->pGroupInfo)
			return 0;
		for (DWORD N = 1; N < 6; N++)
		{
			if (pChar->pGroupInfo->pMember[N])
			{
				CHAR Name[MAX_STRING] = { 0 };
				GetCXStr(pChar->pGroupInfo->pMember[N]->pName, Name, MAX_STRING);
				if (!_stricmp(pSpawn->Name, Name))
					return 1;
			}
		}
	}
	return 0;
}

static inline DWORD GetGroupMercenaryCount(DWORD ClassMASK)
{
	DWORD retValue = 0;
	if (PCHARINFO pChar = GetCharInfo()) {
		if (!pChar->pGroupInfo) return 0;
		for (DWORD N = 1; N<6; N++) {
			if (pChar->pGroupInfo->pMember[N]) {
				if (pChar->pGroupInfo->pMember[N]->Mercenary && (ClassMASK & (1 << (pChar->pGroupInfo->pMember[N]->pSpawn->mActorClient.Class - 1))))
					retValue++;
			}
		}
	}
	return retValue;
}


static inline PSPAWNINFO GetRaidMember(unsigned long N)
{
	if (N >= 72)
		return 0;
	PEQRAIDMEMBER pRaidMember = &pRaid->RaidMember[N];

	if (!pRaidMember)

		return 0;

	return (PSPAWNINFO)GetSpawnByName(pRaidMember->Name);

}

static inline PSPAWNINFO GetGroupMember(unsigned long N)
{
	if (N>5)
		return false;
	PCHARINFO pChar = GetCharInfo();
	if (!pChar->pGroupInfo) return 0;
	for (unsigned long i = 1; i<6; i++)
	{
		if (pChar->pGroupInfo->pMember[i])
		{
			N--;
			if (N == 0)
			{
				CHAR Name[MAX_STRING] = { 0 };
				GetCXStr(pChar->pGroupInfo->pMember[i]->pName, Name, MAX_STRING);
				return (PSPAWNINFO)GetSpawnByName(Name);
			}
		}
	}
	return 0;
}

#ifndef ISXEQ
static inline BOOL IsNumber(PCHAR String)
{
	if (*String == 0)
		return FALSE;
	if (*String == '-')
		String++;
	while (*String)
	{
		if (!((*String >= '0' && *String <= '9') || *String == '.'))
			return FALSE;
		++String;
	}
	return TRUE;
}
#endif
#define Warp                 0

static inline BOOL IsNumberToComma(PCHAR String)
{
	if (*String == 0)
		return FALSE;
	PCHAR Temp = String;
	while (*String)
	{
		if (!((*String >= '0' && *String <= '9') || *String == '.'))
		{
			if (*String == ',' && Temp != String)
				return TRUE;
			return FALSE;
		}
		++String;
	}
	return TRUE;
}

static inline BOOL LineOfSight(PSPAWNINFO Origin, PSPAWNINFO CanISeeThis)
{
	if (!Origin || !CanISeeThis)
		return 0;
	return ((EQPlayer*)Origin)->CanSee((EQPlayer*)CanISeeThis);
}

static inline BOOL IsMobFleeing(PSPAWNINFO pChar, PSPAWNINFO pSpawn)
{
	FLOAT HeadingTo = (FLOAT)(atan2f(pChar->Y - pSpawn->Y, pSpawn->X - pChar->X) * 180.0f / PI + 90.0f);
	FLOAT Heading = pSpawn->Heading*0.703125f;

	if (HeadingTo<0.0f)
		HeadingTo += 360.0f;
	else if (HeadingTo >= 360.0f)
		HeadingTo -= 360.0f;

	FLOAT UB = HeadingTo + 120.0f;
	FLOAT LB = HeadingTo - 120.0f;

	if (LB < UB) return ((Heading < UB) && (Heading > LB));
	else return ((Heading < LB) && (Heading > UB));
}

static inline DWORD FixOffset(DWORD nOffset)
{
	return ((nOffset - 0x400000) + baseAddress);
}

static inline bool endsWith(char* base, char* str) {
	if (!base || !str)
		return false;
	int blen = strlen(base);
	int slen = strlen(str);
	return (blen >= slen) && (0 == strcmp(base + blen - slen, str));
}

// ***************************************************************************
// Function:    MQGetTickCount64
// Description: Returns Uptime in milliseconds. Minimum Resolution is 15ms
// If the user is on Windows XP this function will call GetTickCount()
// instead of GetTickCount64() (which doesn't exist on that platform.)
// ***************************************************************************
inline unsigned __int64 MQGetTickCount64(void)
{
	typedef unsigned long long (WINAPI *fGetTickCount64)(VOID);
	static fGetTickCount64 pGetTickCount64 = 0;

	if (!pGetTickCount64)
	{
		if (HMODULE h = GetModuleHandleA("kernel32.dll")) {
			if (pGetTickCount64 = (fGetTickCount64)GetProcAddress(h, "GetTickCount64")) {
				// Set address to this function for use as a canary value, rather than storing another global
				pGetTickCount64 = reinterpret_cast<fGetTickCount64>(&MQGetTickCount64);
			}
		}
	}
	if (pGetTickCount64 && pGetTickCount64 != reinterpret_cast<fGetTickCount64>(&MQGetTickCount64))
	{
		return pGetTickCount64();
	}
	return ::GetTickCount(); // Fall back to GetTickCount which always exists
}
// Deprecated: Forwards to MQGetTickCount64()
inline unsigned __int64 GetTickCount642(void)
{
	return MQGetTickCount64();
}
inline LONG GetMemorizedSpell(LONG index)
{
	if (index < 0 || index>0xF)
		return -1;
	if (PCHARINFO pCharInfo = GetCharInfo()) {
		if (pCharInfo->CharacterBase_vftable) {
			if (CharacterBase *cb = (CharacterBase *)&pCharInfo->CharacterBase_vftable) {
				return cb->GetMemorizedSpell(index);
			}
		}
	}
	return -1;
}
inline LONG EQGetSpellDuration(PSPELL pSpell, unsigned char casterlevel, bool isitemeffect)
{
	if (PCHARINFO pCharInfo = GetCharInfo()) {
#ifdef NEWCHARINFO
		if (pCharInfo->PcClient_CharacterZoneClient_vfTable) {
#else
		if (pCharInfo->vtable2) {
#endif
			if (EQ_Character *cb = (EQ_Character *)pCharData1) {
				return (LONG)cb->SpellDuration((EQ_Spell*)pSpell, casterlevel, isitemeffect);
			}
		}
	}
	return 0;
}
inline int EQGetMySpellDuration(PSPELL pSpell, PCONTENTS *pContOut, PSPAWNINFO pCaster, int OrgDuration, int *pOut1, int *pOut2)
{
	if (PCHARINFO pCharInfo = GetCharInfo()) {
#ifdef NEWCHARINFO
		if (pCharInfo->PcClient_CharacterZoneClient_vfTable) {
#else
		if (pCharInfo->vtable2) {
#endif
			if (EQ_Character *cb = (EQ_Character *)pCharData1) {
				return cb->MySpellDuration(pSpell, pContOut, pCaster, OrgDuration, pOut1,pOut2);
			}
		}
	}
	return 0;
}
/*
need to figure out why this fails in xp and the above doesn't - eqmule
static inline ULONGLONG GetTickCount64(void)
{
static int once = 1;
static ULONGLONG (WINAPI *pGetTickCount64)(void);
if (once) {
//we dont want to call this one over and over thats just stupid, so once is enough - eqmule
pGetTickCount64 = (ULONGLONG (WINAPI *)(void))GetProcAddress(GetModuleHandle("KERNEL32.DLL"), "GetTickCount64");
if (!pGetTickCount64)
pGetTickCount64 = (ULONGLONG (WINAPI *)(void))GetProcAddress(GetModuleHandle("KERNEL32.DLL"), "GetTickCount");
if (!pGetTickCount64) {
//MessageBox(NULL,"CRAP","What kind of OS are you running anyway?",MB_OK);
return (ULONGLONG)GetTickCount();
}
once = 0;
}
return pGetTickCount64();
}
*/

static inline LONG GetSpellNumEffects(PSPELL pSpell)
{
#if !defined(ROF2EMU) && !defined(UFEMU)
	if (pSpell) {
		return pSpell->NumEffects;
	}
#endif
	return 0xc;
}
static inline DWORD GetGroupMainAssistTargetID()
{
	if (PCHARINFO pChar = GetCharInfo()) {
		if (pChar->pGroupInfo && pLocalPlayer) {
			return ((PSPAWNINFO)pLocalPlayer)->GroupAssistNPC[0];
		}
	}
	return 0;
}
static inline DWORD GetRaidMainAssistTargetID(int index)
{
	if (pRaid)
	{
		if (PSPAWNINFO pSpawn = (PSPAWNINFO)pLocalPlayer) {
			if (index < 0)
				index = 0;
			if (index > 2)
				index = 2;
			return pSpawn->RaidAssistNPC[index];
		}
	}
	return 0;
}
static inline BOOL IsAssistNPC(PSPAWNINFO pSpawn)
{
	if (pSpawn) {
		if (DWORD AssistID = GetGroupMainAssistTargetID()) {
			if (AssistID == pSpawn->SpawnID) {
				return true;
			}
		}
		for (int nAssist = 0; nAssist < 3; nAssist++) {
			if (DWORD AssistID = GetRaidMainAssistTargetID(nAssist)) {
				if (AssistID == pSpawn->SpawnID) {
					return true;
				}
			}
		}
	}
	return false;
}
static inline bool CanTank(DWORD Class)
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
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

// trim from start (copying)
static inline std::string ltrim_copy(std::string s) {
    ltrim(s);
    return s;
}

// trim from end (copying)
static inline std::string rtrim_copy(std::string s) {
    rtrim(s);
    return s;
}

// trim from both ends (copying)
static inline std::string trim_copy(std::string s) {
    trim(s);
    return s;
}
static inline char* GetSpellString(int ID, int SpellIndex)
{
#if !defined(ROF2EMU) && !defined(UFEMU)
	if (pEQSpellStrings) {
		if(char*str = pEQSpellStrings->GetString(ID, SpellIndex)) {
			if (str[0])
				return str;
		}
	}
#else
	if (PSPELL pSpell = GetSpellByID(ID)) {
		switch (SpellIndex)
		{
			case 0:
				if (pSpell->CastByMe[0])
					return pSpell->CastByMe;
				break;
			case 1:
				if (pSpell->CastByOther[0])
					return pSpell->CastByOther;
				break;
			case 2:
				if (pSpell->CastOnYou[0])
					return pSpell->CastOnYou;
				break;
			case 3:
				if (pSpell->CastOnAnother[0])
					return pSpell->CastOnAnother;
				break;
			case 4:
				if (pSpell->WearOff[0])
					return pSpell->WearOff;
				break;
			default:
				break;
		};
	}
#endif
	return NULL;
}
//inlines by ieatacid for pattern finding
static inline bool DataCompare(const unsigned char *pData, const unsigned char *bMask, const char *szMask)
{
    for(;*szMask;++szMask,++pData,++bMask)
        if(*szMask=='x' && *pData!=*bMask )
            return false;
    return (*szMask) == 0;
}

static inline unsigned long FindPattern(unsigned long dwAddress,unsigned long dwLen,const unsigned char *bPattern,const char *szMask)
{
    for(unsigned long i=0; i < dwLen; i++)
        if(DataCompare( (unsigned char *)( dwAddress+i ),bPattern,szMask) )
            return (unsigned long)(dwAddress+i);
   
    return 0;
}

static inline unsigned long GetDWordAt(unsigned long address, unsigned long numBytes)
{
    if(address)
    {
        address += numBytes;
        if(*(unsigned long*)address)
            return *(unsigned long*)address;
    }
    return 0;
}
