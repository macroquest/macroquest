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
	if (dwSpawnID>0 && dwSpawnID<3000)
		return ppEQP_IDArray[dwSpawnID];
	return 0;
}

static inline PSPELL GetSpellByID(DWORD dwSpellID)
{
	if (dwSpellID < 0 || dwSpellID > 0x1388)
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

#define _FileExists(filename) ( (_access( filename, 0 )) != -1 )
