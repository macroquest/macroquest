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

static inline PCHARINFO GetCharInfo(VOID) {
    //   if (!ppCharData) return NULL;
    return (PCHARINFO)pCharData;
}

static inline PCHARINFO2 GetCharInfo2(VOID) {
    //   if (!ppCharData) return NULL;
    return ((PCHARINFO)pCharData)->pCI2->pCharInfo2;
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

static inline PSPELL GetSpellByID(LONG dwSpellID)
{
    if (dwSpellID==0 || dwSpellID==-1)
        return NULL;
	long absedspellid = abs(dwSpellID);
    if (absedspellid >= TOTAL_SPELL_COUNT)
        return NULL;
    return &(*((PSPELLMGR)pSpellMgr)->Spells[absedspellid]);
}

static inline PCHAR GetBodyTypeDesc(DWORD BodyTypeID)
{
    if (BodyTypeID<104 && BodyTypeID>=0)
        return szBodyType[BodyTypeID];
    return "*UNKNOWN BODYTYPE";
}

static inline PCHAR GetClassDesc(DWORD ClassID)
{
    if (ClassID==60)
        return "LDoN Recruiter";
    if (ClassID==61)
        return "LDoN Merchant";
    if (ClassID==62)
        return "Destructible Object";
    if (ClassID==63)
        return "Tribute Master";
    if (ClassID==64)
        return "Guild Tribute Master";
    if (ClassID==66)
        return "Guild Banker";
    if (ClassID==67 || ClassID==68)
        return "DoN Merchant";
    if (ClassID==69)
        return "Fellowship Registrar";
    if (ClassID==70)
        return "Merchant";
    if (ClassID==71)
        return "Mercenary Liaison";
    if (ClassID==0xFF)
        return "Aura";
    if (ClassID==0xFE)
        return "Banner";
    if (ClassID==0xFD)
        return "Campfire";
    return pEverQuest->GetClassDesc(ClassID);
}

static inline BOOL IsAssistNPC(PSPAWNINFO pSpawn)
{
    if (GetCharInfo()->pSpawn && pSpawn)
    {
        DWORD nAssist;
        {
            if (GetCharInfo()->pSpawn->GroupAssistNPC[0]==pSpawn->SpawnID)
            {
                return true;
            }
        }
        for (nAssist=0 ; nAssist < 3 ; nAssist++)
        {
            if (GetCharInfo()->pSpawn->RaidAssistNPC[nAssist]==pSpawn->SpawnID)
            {
                return true;
            }
        }
    }
    return false;
}

static inline BOOL IsMarkedNPC(PSPAWNINFO pSpawn)
{
    if (GetCharInfo()->pSpawn && pSpawn)
    {
        DWORD nMark;
        for (nMark=0 ; nMark < 3 ; nMark++)
        {
            if (GetCharInfo()->pSpawn->RaidMarkNPC[nMark]==pSpawn->SpawnID)
            {
                return true;
            }
        }
        for (nMark=0 ; nMark < 3 ; nMark++)
        {
            if (GetCharInfo()->pSpawn->GroupMarkNPC[nMark]==pSpawn->SpawnID)
            {
                return true;
            }
        }
    }
    return false;
}

#define GetCurHPS() pCharData1->Cur_HP(0)
#define GetMaxHPS() pCharData1->Max_HP(0)
#define GetMaxEndurance() pCharData1->Max_Endurance()
#define GetMaxMana() pCharData1->Max_Mana() 

// ***************************************************************************
// Function:    GetCharMaxBuffSlots
// Description: Returns the max number of buff slots available for a character
// ***************************************************************************
static inline DWORD GetCharMaxBuffSlots()
{
	DWORD NumBuffs = 15;
	NumBuffs += pCharData1->TotalEffect(327, 1, 0, 1, 1);

	if(PCHARINFO pChar = GetCharInfo()) {
		if(pChar->pSpawn->Level > 70) NumBuffs++;
		if(pChar->pSpawn->Level > 74) NumBuffs++;
	}
	return NumBuffs;
}

static inline DWORD GetBodyType(PSPAWNINFO pSpawn)
{
    for(int i=0; i<104; i++)
    {
        if(((EQPlayer*)pSpawn)->IsBodyType(i,0,0))
        {
            if(i==100)
            {
                if(((EQPlayer*)pSpawn)->IsBodyType(i,101,0))
                    return 101;
                if(((EQPlayer*)pSpawn)->IsBodyType(i,102,0))
                    return 102;
                if(((EQPlayer*)pSpawn)->IsBodyType(i,103,0))
                    return 103;
            }
            return i;
        }
    }
    return 0;
}

static inline eSpawnType GetSpawnType(PSPAWNINFO pSpawn)
{
    switch(pSpawn->Type)
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
		if(pSpawn->MasterID) {
			return PET;
		}
        if (pSpawn->Mercenary)
            return MERCENARY;

        // some type of controller spawn for flying mobs - locations, speed, heading, all NaN
        if (IsNaN(pSpawn->Y) && IsNaN(pSpawn->X) && IsNaN(pSpawn->Z))
            return FLYER;

        switch(GetBodyType(pSpawn))
        {
        case 0:
            if (pSpawn->Class==62)
                return OBJECT;
            return NPC;
        case 1:
            if (pSpawn->Race == 567)
                return CAMPFIRE;
            if (pSpawn->Race == 500 || (pSpawn->Race >= 553 && pSpawn->Race <= 557) || pSpawn->Race == 586)
                return BANNER;
            return NPC;
        //case 3:
        //    return NPC;
        case 5:
            if (strstr(pSpawn->Name,"Idol") || strstr(pSpawn->Name,"Poison") || strstr(pSpawn->Name,"Rune"))
                return AURA;
            if (pSpawn->Class==62)
                return OBJECT;
            return NPC; 
        case 7:
			if (pSpawn->Class==62)
                return OBJECT;
			return NPC;
        case 11:
            if (strstr(pSpawn->Name,"Aura") || strstr(pSpawn->Name,"Circle_of") || strstr(pSpawn->Name,"Guardian_Circle") || strstr(pSpawn->Name,"Earthen_Strength"))
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

static inline FLOAT GetDistance(FLOAT X1,FLOAT Y1)
{
    FLOAT dX=X1-((PSPAWNINFO)pCharSpawn)->X;
    FLOAT dY=Y1-((PSPAWNINFO)pCharSpawn)->Y;
    return sqrtf(dX*dX + dY*dY);
}

static inline FLOAT GetDistance(FLOAT X1,FLOAT Y1,FLOAT X2,FLOAT Y2)
{
    FLOAT dX=X1-X2;
    FLOAT dY=Y1-Y2;
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

#define DistanceToSpawn(pChar,pSpawn) GetDistance(pChar,pSpawn)

#define _FileExists(filename) ( (_access( filename, 0 )) != -1 )
// ***************************************************************************
// FindMount(PSPAWNINFO) - Used to find the mount of a spawn, if one
//                         exists. returns the spawn if one does not.
// ***************************************************************************
static inline PSPAWNINFO FindMount(PSPAWNINFO pSpawn)
{
    return (pSpawn->Mount?pSpawn->Mount:pSpawn); 
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

static inline BOOL IsRaidMember(PSPAWNINFO pSpawn)
{
    for (DWORD N = 0 ; N < 72 ; N++)
    {
        if (pRaid->RaidMemberUsed[N] && !stricmp(pSpawn->Name,pRaid->RaidMember[N].Name))
            return 1;
    }
    return 0;
}

static inline BOOL IsGroupMember(PSPAWNINFO pSpawn)
{
    PCHARINFO pChar=GetCharInfo();
    if (!pChar->pGroupInfo) return 0;
    for (DWORD N=1; N<6; N++)
    {
        if (pChar->pGroupInfo->pMember[N])
        {
            CHAR Name[MAX_STRING]={0};
            GetCXStr(pChar->pGroupInfo->pMember[N]->pName,Name,MAX_STRING);
            if (!stricmp(pSpawn->Name,Name))
                return 1;
        }
    }
    return 0;
}

static inline DWORD GetGroupMercenaryCount(DWORD ClassMASK)
{
	DWORD retValue = 0;
    if(PCHARINFO pChar=GetCharInfo()) {
		if (!pChar->pGroupInfo) return 0;
		for (DWORD N=1; N<6; N++) {
			if (pChar->pGroupInfo->pMember[N]) {
				if (pChar->pGroupInfo->pMember[N]->Mercenary && (ClassMASK & (1 << (pChar->pGroupInfo->pMember[N]->pSpawn->Class-1))))
					retValue++;
			}
		}
	}
    return retValue;
}


static inline PSPAWNINFO GetRaidMember(unsigned long N)
{
    if (N>=72)
        return 0;
    PEQRAIDMEMBER pRaidMember=&pRaid->RaidMember[N];

    if (!pRaidMember)

        return 0;

    return (PSPAWNINFO)GetSpawnByName(pRaidMember->Name);

}

static inline PSPAWNINFO GetGroupMember(unsigned long N)
{
    if (N>5)
        return false;
    PCHARINFO pChar=GetCharInfo();
    if (!pChar->pGroupInfo) return 0;
    for (unsigned long i=1; i<6; i++)
    {
        if (pChar->pGroupInfo->pMember[i])
        {
            N--;
            if (N==0)
            {
                CHAR Name[MAX_STRING]={0};
                GetCXStr(pChar->pGroupInfo->pMember[i]->pName,Name,MAX_STRING);
                return (PSPAWNINFO)GetSpawnByName(Name);
            }
        }
    }
    return 0;
}

#ifndef ISXEQ
static inline BOOL IsNumber(PCHAR String)
{
    if (*String==0)
        return FALSE;
    if (*String=='-')
        String++;
    while(*String)
    {
        if (!((*String>='0' && *String<='9') || *String=='.'))
            return FALSE;
        ++String;
    }
    return TRUE;
}
#endif
#define Warp                 0

static inline BOOL IsNumberToComma(PCHAR String)
{
    if (*String==0)
        return FALSE;
    PCHAR Temp=String;
    while(*String)
    {
        if (!((*String>='0' && *String<='9') || *String=='.'))
        {
            if (*String==',' && Temp!=String)
                return TRUE;
            return FALSE;
        }
        ++String;
    }
    return TRUE;
}

static inline BOOL LineOfSight(PSPAWNINFO Origin, PSPAWNINFO CanISeeThis)
{
	return ((EQPlayer*)Origin)->CanSee((EQPlayer*)CanISeeThis);
}

static inline BOOL IsMobFleeing(PSPAWNINFO pChar, PSPAWNINFO pSpawn)
{
    FLOAT HeadingTo = (FLOAT)(atan2f(pChar->Y - pSpawn->Y, pSpawn->X - pChar->X) * 180.0f / PI + 90.0f);
    FLOAT Heading   = pSpawn->Heading*0.703125f;

    if (HeadingTo<0.0f)
        HeadingTo += 360.0f;
    else if (HeadingTo>=360.0f)
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

static inline bool endsWith (char* base, char* str) {
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
    static fGetTickCount64 pGetTickCount64 = NULL;


    if (pGetTickCount64 == NULL)
    {
        if ((pGetTickCount64 = reinterpret_cast<fGetTickCount64>(::GetProcAddress(::GetModuleHandleA("kernel32.dll"), "GetTickCount64"))) == NULL)
        {
            // Set address to this function for use as a canary value, rather than storing another global
            pGetTickCount64 = reinterpret_cast<fGetTickCount64>(&MQGetTickCount64);
        }
    }
    if (pGetTickCount64 != reinterpret_cast<fGetTickCount64>(&MQGetTickCount64))
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
