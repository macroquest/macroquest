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

#ifdef ISBOXER_COMPAT
TOPLEVELOBJECT("EQTarget",dataTarget);
TOPLEVELOBJECT("EQWindow",dataWindow);
#else
TOPLEVELOBJECT("Target",dataTarget);
TOPLEVELOBJECT("Window",dataWindow);
#endif
TOPLEVELOBJECT("Spawn",dataSpawn);
TOPLEVELOBJECT("Me",dataCharacter);
TOPLEVELOBJECT("Spell",dataSpell);
TOPLEVELOBJECT("Switch",dataSwitch);
TOPLEVELOBJECT("GroundItem",dataGroundItem);
TOPLEVELOBJECT("Merchant",dataMerchant);
TOPLEVELOBJECT("EverQuest",dataEverQuest);
TOPLEVELOBJECT("MacroQuest",dataMacroQuest);
TOPLEVELOBJECT("Zone",dataZone);
TOPLEVELOBJECT("Group",dataGroup);
TOPLEVELOBJECT("Corpse",dataCorpse);
TOPLEVELOBJECT("Cursor",dataCursor);
TOPLEVELOBJECT("NearestSpawn",dataNearestSpawn);
TOPLEVELOBJECT("GameTime",dataGameTime);
TOPLEVELOBJECT("Time",dataTime);
TOPLEVELOBJECT("Ini",dataIni);
TOPLEVELOBJECT("Heading",dataHeading);
TOPLEVELOBJECT("LastSpawn",dataLastSpawn);
TOPLEVELOBJECT("InvSlot",dataInvSlot);
TOPLEVELOBJECT("FindItem",dataFindItem);
TOPLEVELOBJECT("SelectedItem",dataSelectedItem);
TOPLEVELOBJECT("FindItemBank",dataFindItemBank);
TOPLEVELOBJECT("FindItemCount",dataFindItemCount);
TOPLEVELOBJECT("FindItemBankCount",dataFindItemBankCount);
//TOPLEVELOBJECT("GroupLeader",dataGroupLeader);
//TOPLEVELOBJECT("GroupLeaderName",dataGroupLeaderName);
TOPLEVELOBJECT("Skill",dataSkill);
TOPLEVELOBJECT("AltAbility",dataAltAbility);
TOPLEVELOBJECT("Raid",dataRaid);
TOPLEVELOBJECT("NamingSpawn",dataNamingSpawn);
TOPLEVELOBJECT("SpawnCount",dataSpawnCount);
TOPLEVELOBJECT("LineOfSight",dataLineOfSight);
TOPLEVELOBJECT("DoorTarget",dataDoorTarget);
TOPLEVELOBJECT("ItemTarget",dataItemTarget);
TOPLEVELOBJECT("NearestDoor",dataNearestDoor); 
TOPLEVELOBJECT("Friends",dataFriends); 

/**/
