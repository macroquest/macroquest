/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2004 Lax

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/

static inline EQPlayer *GetSpawnByID(DWORD dwSpawnID)
{
	if (dwSpawnID<3000)
		return ppEQP_IDArray[dwSpawnID];
	return 0;
}

static inline PSPELL GetSpellByID(DWORD dwSpellID)
{
	if (dwSpellID==0 || dwSpellID >= 0x1388)
		return 0;
	return &(*((PSPELLMGR)pSpellMgr)->Spells[dwSpellID]);
}

#define GetMaxMana() pCharData->Max_Mana()
#define GetMaxHPS() pCharData->Max_HP(0)
#define GetCurHPS() pCharData->Cur_HP(0)

static inline eSpawnType GetSpawnType(PSPAWNINFO pSpawn)
{
	switch(pSpawn->Type)
	{
	case SPAWN_PLAYER:
		{
			if (strstr(pSpawn->Name,"s_Mount"))
			{
				return MOUNT;
			}
			return PC;
		}
	case SPAWN_NPC:
		if (strstr(pSpawn->Name,"s_Mount"))
		{
			return MOUNT;
		}
		if (pSpawn->BodyType>0x40)
			return TRIGGER;
		else
		{
			if (pSpawn->MasterID)
				return PET;
			else
				return NPC;
		}
		return NPC;
	case SPAWN_CORPSE:
		return CORPSE;
	default:
		return ITEM;
	}
}

static inline PCHARINFO GetCharInfo(VOID) {
 //   if (!ppCharData) return NULL;
    return (PCHARINFO)pCharData;
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
