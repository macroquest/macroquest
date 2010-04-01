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
	if (dwSpawnID<3000)
		return ppEQP_IDArray[dwSpawnID];
	return 0;
}

static inline PSPELL GetSpellByID(DWORD dwSpellID)
{
	if (dwSpellID==0 || dwSpellID >= TOTAL_SPELL_COUNT)
		return 0;
	return &(*((PSPELLMGR)pSpellMgr)->Spells[dwSpellID]);
}

static inline PCHAR GetBodyTypeDesc(DWORD BodyTypeID)
{
	if (BodyTypeID<70)
		return szBodyType[BodyTypeID];
	return "*UNKNOWN BODYTYPE";
}

static inline PCHAR GetClassDesc(DWORD ClassID)
{
	if (ClassID==60)
		return "LDoN Recruiter";
	if (ClassID==61)
		return "LDoN Merchant";
    if (ClassID==63)
        return "Tribute Master";
    if (ClassID==64)
        return "Guild Tribute Master";
    if (ClassID==66)
        return "Guild Banker"; 
	return pEverQuest->GetClassDesc(ClassID);
}

static inline BOOL IsAssistNPC(PSPAWNINFO pSpawn)
{
	if (GetCharInfo()->pSpawn)
	{
		DWORD nAssist;
		PACTORINFO pCharActor=GetCharInfo()->pSpawn->pActorInfo;
//			for (nAssist=0 ; nAssist < 1 ; nAssist++)
		{
			if (pCharActor->pGroupAssistNPC[0]==pSpawn)
			{
				return true;
			}
		}
		for (nAssist=0 ; nAssist < 3 ; nAssist++)
		{
			if (pCharActor->pRaidAssistNPC[nAssist]==pSpawn)
			{
				return true;
			}
		}
	}
	return false;
}

static inline BOOL IsMarkedNPC(PSPAWNINFO pSpawn)
{
	if (GetCharInfo()->pSpawn)
	{
		DWORD nMark;
		PACTORINFO pCharActor=GetCharInfo()->pSpawn->pActorInfo;
		for (nMark=0 ; nMark < 3 ; nMark++)
		{
			if (pCharActor->pRaidMarkNPC[nMark]==pSpawn)
			{
				return true;
			}
		}
		for (nMark=0 ; nMark < 3 ; nMark++)
		{
			if (pCharActor->pGroupMarkNPC[nMark]==pSpawn)
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

static inline eSpawnType GetSpawnType(PSPAWNINFO pSpawn)
{
	switch(pSpawn->Type)
	{
	case SPAWN_PLAYER:
		{
			return PC;
		}
	case SPAWN_NPC:
		if (strstr(pSpawn->Name,"s_Mount"))
		{
			return MOUNT;
		}
		if (pSpawn->MasterID)
			return PET;

		switch(pSpawn->BodyType)
		{
		case 3:
			return NPC;
		case 11:
			return UNTARGETABLE;
		case 21:
			return NPC; 
		case 23:
			return NPC;
		case 33:
			return CHEST;
		case 34:
			return NPC;
		case 65:
			return TRAP;
		case 66:
			return TIMER;
		case 67:
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
#define SuccorFunc 0
// ***************************************************************************
// FindMount(PSPAWNINFO) - Used to find the mount of a spawn, if one
//                         exists. returns the spawn if one does not.
// ***************************************************************************
static inline PSPAWNINFO FindMount(PSPAWNINFO pSpawn)
{
   if (!pSpawn->pActorInfo || !pSpawn->pActorInfo->Mount) return pSpawn;
   return pSpawn->pActorInfo->Mount; 
}


// ***************************************************************************
// Function:    ConColorToRGB
// Description: Returns the RGB color for a con color
// ***************************************************************************
static inline DWORD ConColorToARGB(DWORD ConColor)
{
    switch (ConColor) {
        case CONCOLOR_GREEN:
            return 0xFF00FF00;
        case CONCOLOR_LIGHTBLUE:
            return 0xFF00FFFF;
        case CONCOLOR_BLUE:
            return 0xFF0000FF;
        case CONCOLOR_BLACK:
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
	for (DWORD N = 0 ; N < 5 ; N++)
	{
		if (pSpawn==(PSPAWNINFO)pGroup->pMember[N])
			return 1;
	}
	return 0;
}

#ifndef ISXEQ
static inline BOOL IsNumber(PCHAR String)
{
	if (*String==0)
		return FALSE;
	while(*String)
	{
		if (!((*String>='0' && *String<='9') || *String=='.'))
			return FALSE;
		++String;
	}
	return TRUE;
}
#endif
#define Warp				 0

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
	return CastRay(Origin,CanISeeThis->Y,CanISeeThis->X,CanISeeThis->Z);
}
