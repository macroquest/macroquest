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

#if !defined(CINTERFACE)
#error /DCINTERFACE
#endif

#define DBG_SPEW

#include "..\MQ2Main.h"

/*
// COMMANDS TO CONVERT
EQLIB_API VOID NoModKeyCmd(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID CaptionColorCmd(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID CaptionCmd(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID DropCmd(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID CombineCmd(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID ClearErrorsCmd(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID DoShiftCmd(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID DoCtrlCmd(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID DoAltCmd(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID DumpBindsCommand(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID LoadCfgCommand(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID Alert                               (PSPAWNINFO,PCHAR);
EQLIB_API VOID AltAbility						   (PSPAWNINFO,PCHAR);
EQLIB_API VOID BankList                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID BuyItem                             (PSPAWNINFO,PCHAR);
EQLIB_API VOID CharInfo                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID Cast                                (PSPAWNINFO,PCHAR);
EQLIB_API VOID Cleanup                             (PSPAWNINFO,PCHAR);
EQLIB_API VOID Click                               (PSPAWNINFO,PCHAR);
EQLIB_API VOID DebugSpewFile                       (PSPAWNINFO,PCHAR);
EQLIB_API VOID EQDestroyHeldItemOrMoney				(PSPAWNINFO,PCHAR);
EQLIB_API VOID DisplayLoginName						(PSPAWNINFO,PCHAR);
EQLIB_API VOID DoAbility                           (PSPAWNINFO,PCHAR);
EQLIB_API VOID DoEvents                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID DoSocial                           (PSPAWNINFO,PCHAR);
EQLIB_API VOID Doors                               (PSPAWNINFO,PCHAR);
EQLIB_API VOID DoorTarget                          (PSPAWNINFO,PCHAR);
EQLIB_API VOID Exec                                (PSPAWNINFO,PCHAR); 
EQLIB_API VOID Face                                (PSPAWNINFO,PCHAR);
EQLIB_API VOID Filter                              (PSPAWNINFO,PCHAR);
EQLIB_API VOID Help                                (PSPAWNINFO,PCHAR);
EQLIB_API VOID Hotkey                              (PSPAWNINFO,PCHAR);
EQLIB_API VOID Identify                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID IniOutput                           (PSPAWNINFO,PCHAR);
EQLIB_API VOID Items                               (PSPAWNINFO,PCHAR);
EQLIB_API VOID ItemTarget                          (PSPAWNINFO,PCHAR);
EQLIB_API VOID WindowState							(PSPAWNINFO,PCHAR);
EQLIB_API VOID LoadSpells                          (PSPAWNINFO,PCHAR);
EQLIB_API VOID Location                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID Look                                (PSPAWNINFO,PCHAR);
EQLIB_API VOID MacroLog                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID MemSpell                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID MouseTo                             (PSPAWNINFO,PCHAR);
EQLIB_API VOID MQMsgBox                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID SellItem                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID SetError                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID Skills                              (PSPAWNINFO,PCHAR);
EQLIB_API VOID Substitute						   (PSPAWNINFO,PCHAR);
EQLIB_API VOID SuperWhoTarget                      (PSPAWNINFO,PCHAR);
EQLIB_API VOID SWhoFilter							(PSPAWNINFO,PCHAR);
EQLIB_API VOID Target                              (PSPAWNINFO,PCHAR);
EQLIB_API VOID UpdateItemInfo                      (PSPAWNINFO,PCHAR);
/**/

//EQLIB_API VOID DoMappable(PSPAWNINFO pChar, PCHAR szLine)
int CMD_Keypress(int argc, char *argv[])
{
	if (argc<2)
	{
		WriteChatf("Syntax: %s <eqcommand|keycombo> [hold|chat]",argv[0]);
		return 0;
	}
	bool bHold=false;
	bool bChat=false;
	if (argc==3)
	{
		if (!stricmp(argv[2],"hold"))
		{
			bHold=true;
		}
		else if (!stricmp(argv[2],"chat"))
		{
			bChat=true;
		}
	}
	if (!PressMQ2KeyBind(argv[1],bHold))
	{
		int N=FindMappableCommand(argv[1]);
		if (N>=0)
		{
			ExecuteCmd(N,1,0);
			if (!bHold)
				ExecuteCmd(N,0,0);
			return 0;
		}
		KeyCombo Temp;
		if (ParseKeyCombo(argv[1],Temp))
		{
			if (bChat)
			{
				pWndMgr->HandleKeyboardMsg(Temp.Data[3],1);
				pWndMgr->HandleKeyboardMsg(Temp.Data[3],0);
			}
			else
			{
				MQ2HandleKeyDown(Temp);
				if (!bHold)
					MQ2HandleKeyUp(Temp);
			}
			return 0;
		}

		WriteChatf("Invalid mappable command or key combo '%s'",argv[1]);
		return -1;
	}
	return 0;
}

int CMD_Who(int argc, char *argv[])
{   
	for (int i = 1 ; i < argc ; i++)
	{
		if (!stricmp(argv[i],"all"))
		{
			cmdWho((PSPAWNINFO)pLocalPlayer, argv[1]);
			return 0;
		}
	}

	bool bConColor=false;
    SEARCHSPAWN SearchSpawn;
    
    ClearSearchSpawn(&SearchSpawn);
    SearchSpawn.SpawnType = PC;

	for (int i = 1 ; i < argc ; i++)
	{
		if (!stricmp(argv[i],"sort")) 
		{ 
			//  <name|level|distance|race|class|guild|id> 
			PCHAR szSortBy[] = { 
				"level",   // Default sort by 
				"name", 
				"race", 
				"class", 
				"distance", 
				"guild", 
				"id", 
				NULL }; 
			DWORD Command=0; 
			for (Command;szSortBy[Command];Command++) 
			{ 
				if (!stricmp(argv[i],szSortBy[Command])) 
				{ 
					SearchSpawn.SortBy = Command; 
					if (i<argc) 
						i++;
					break; 
				}
			}
		} 
		else if (!stricmp(argv[i],"concolor")) 
		{
			bConColor=1;
		}
		else 
		{
			i+=ParseSearchSpawnArg(i,argc,argv,SearchSpawn);
		}
	}
	SuperWhoDisplay((PSPAWNINFO)pLocalPlayer,&SearchSpawn,bConColor);
	return 0;
}


// /beep
int CMD_Beep(int argc, char *argv[])
{
	Beep(0x500,250);
	return 0;
}
// /ranged
int CMD_do_ranged(int argc, char *argv[])
{
	EQPlayer *pRangedTarget=pTarget;
	if (argc>1)
	{
		pRangedTarget=GetSpawnByID(atoi(argv[1]));
		if (!pRangedTarget)
		{
			printf("Invalid spawn ID.  Use /ranged with no parameters, or with a spawn ID");
			return 0;
		}
	}
	if (!pRangedTarget)
	{
		printf("No target for ranged attack");
		return 0;
	}
	if (gbRangedAttackReady)
	{
		pLocalPlayer->DoAttack(0x0B,0,pRangedTarget);
		gbRangedAttackReady=0;
	}
	return 0;
}
// /autorun
int CMD_SetAutoRun(int argc, char *argv[])
{
	if (argc<2)
	{
		WriteChatf("Syntax: %s on|off",argv[0]);
		return 0;
	}
#if 0
   if(!stricmp(argv[1],"on") || !stricmp(argv[1],"off"))
   {
		CHAR szServerAndName[MAX_STRING] = {0};
		sprintf(szServerAndName,"%s.%s",((PCHARINFO)pCharData)->Server,((PCHARINFO)pCharData)->Name);
		WritePrivateProfileString(szServerAndName,"AutoRun",argv[1],gszINIFilename);
		sprintf(szServerAndName,"Set autorun to: '%s'",argv[1]);
		WriteChatColor(szServerAndName,USERCOLOR_DEFAULT);
   }
#endif
   return 0;
}

// /loginname
int CMD_DisplayLoginName(int argc, char *argv[])
{
	PCHAR szLogin = GetLoginName();
	if (!szLogin) {
		printf("Unable to retrieve login name.");
	} else {
		WriteChatf("Login name: \ay%s\ax",szLogin);
		free(szLogin);
	}
	return 0;
}

// /popup
int CMD_PopupText(int argc, char *argv[])
{
	if (argc<2)
	{
		printf("Syntax: %s <text>",argv[0]);
		return 0;
	}

	CHAR szRest[MAX_STRING] = {0};
	pISInterface->GetArgs(1,argc,argv,szRest);
	DisplayOverlayText(szRest, CONCOLOR_LIGHTBLUE, 100, 500,500,3000);
	return 0;
}

int CMD_BuyItem(int argc, char *argv[])
{
	if (argc<2)
	{
		WriteChatf("Syntax: %s <quantity>",argv[0]);
		return 0;
	}
   if (!pMerchantWnd) 
   {
	   return 0;
   }
   PCHARINFO pCharInfo;
   if (NULL == (pCharInfo = GetCharInfo())) 
	   return 0;

   DWORD Qty=(DWORD)atoi(argv[1]);

   if (Qty > 20 || Qty < 1) return 0;
   pMerchantWnd->RequestBuyItem(Qty);
   return 0;
}
int CMD_SellItem(int argc, char *argv[])
{
	if (argc<2)
	{
		WriteChatf("Syntax: %s <quantity>",argv[0]);
		return 0;
	}
	if (!pMerchantWnd) 
		return 0;
	PCHARINFO pCharInfo;
    if (NULL == (pCharInfo = GetCharInfo())) return 0;

    DWORD Qty = (DWORD)atoi(argv[1]);
    if (Qty > 20 || Qty < 1) return 0;
    pMerchantWnd->RequestSellItem(Qty);
    return 0;
}

int CMD_Target(int argc, char* argv[])
{
    if (!ppSpawnList) return 0;
    if (!pSpawnList) return 0;
	if (argc<2)
	{
		WriteChatf("Syntax: %s myself|mycorpse|clear|<spawn search>",argv[0]);
		return 0;
	}

   PSPAWNINFO pChar = GetCharInfo()->pSpawn;
    PSPAWNINFO pSpawnClosest = NULL;
   
    SEARCHSPAWN SearchSpawn;
    ClearSearchSpawn(&SearchSpawn);
    CHAR szMsg[MAX_STRING] = {0};
    BOOL DidTarget = FALSE;
    BOOL bArg = TRUE;

    bRunNextCommand = TRUE;
    for(int i=1;i<argc;i++)
   {
      if (!stricmp(argv[i],"myself")) {
            if (pChar) {
                pSpawnClosest = pChar;
                DidTarget = TRUE;
            }
      } else if (!stricmp(argv[i],"mycorpse")) {
            if (pChar) {
             SearchSpawn.SpawnType = CORPSE;
            strcpy(SearchSpawn.szName,pChar->Name);
            }
        } else if (!stricmp(argv[i],"clear")) {
            pTarget = NULL;
            DebugSpew("Target cleared.");
            WriteChatColor("Target cleared.",USERCOLOR_WHO);
            return 0;
        } else {
           i+= ParseSearchSpawnArg(i,argc,argv,SearchSpawn);
        }
   }
   
    if (pTarget) SearchSpawn.FromSpawnID = ((PSPAWNINFO)pTarget)->SpawnID;

    if (!DidTarget) {
        pSpawnClosest = SearchThroughSpawns(&SearchSpawn,pChar);
    }

    if (!pSpawnClosest) {
        CHAR szTemp[MAX_STRING] = {0};
        sprintf(szMsg,"There are no spawns matching: %s",FormatSearchSpawn(szTemp,&SearchSpawn));
    } else {
        PSPAWNINFO *psTarget = NULL;
        if (ppTarget) {
            psTarget = (PSPAWNINFO*)ppTarget;
            *psTarget = pSpawnClosest;
            DebugSpew("Target - %s selected",pSpawnClosest->Name);
         szMsg[0]=0;
        } else {
            sprintf(szMsg,"Unable to target, address = 0");
        }
    }
   if (szMsg[0])
    if (!gFilterTarget) WriteChatColor(szMsg,USERCOLOR_WHO);
    return 0;
}

int CMD_WhoFilter(int argc, char* argv[])
{
   if (argc < 3)
   {
       WriteChatf("Syntax: %s <lastname|class|race|level|gm|guild|holding|ld|sneak|anon|lfg|npctag|spawnid|trader|afk|concolor|invisible> [on|off]",0);
       return 0;
   }
   
   if (!stricmp(argv[1],"Lastname")) {
      SetDisplaySWhoFilter(&gFilterSWho.Lastname,"Lastname",argv[2]);
   } else if (!stricmp(argv[1],"Class")) {
      SetDisplaySWhoFilter(&gFilterSWho.Class,"Class",argv[2]);
   } else if (!stricmp(argv[1],"Race")) {
      SetDisplaySWhoFilter(&gFilterSWho.Race,"Race",argv[2]);
   } else if (!stricmp(argv[1],"Body")) {
      SetDisplaySWhoFilter(&gFilterSWho.Body,"Body",argv[2]);
   } else if (!stricmp(argv[1],"Level")) {
      SetDisplaySWhoFilter(&gFilterSWho.Level,"Level",argv[2]);
   } else if (!stricmp(argv[1],"GM")) {
      SetDisplaySWhoFilter(&gFilterSWho.GM,"GM",argv[2]);
   } else if (!stricmp(argv[1],"Guild")) {
      SetDisplaySWhoFilter(&gFilterSWho.Guild,"Guild",argv[2]);
   } else if (!stricmp(argv[1],"LD")) {
      SetDisplaySWhoFilter(&gFilterSWho.LD,"LD",argv[2]);
    } else if (!stricmp(argv[1],"Sneak")) {
      SetDisplaySWhoFilter(&gFilterSWho.Sneak,"Sneak",argv[2]);   
   } else if (!stricmp(argv[1],"LFG")) {
      SetDisplaySWhoFilter(&gFilterSWho.LFG,"LFG",argv[2]);
   } else if (!stricmp(argv[1],"NPCTag")) {
      SetDisplaySWhoFilter(&gFilterSWho.NPCTag,"NPCTag",argv[2]);
   } else if (!stricmp(argv[1],"SpawnID")) {
      SetDisplaySWhoFilter(&gFilterSWho.SpawnID,"SpawnID",argv[2]);
   } else if (!stricmp(argv[1],"Trader")) {
      SetDisplaySWhoFilter(&gFilterSWho.Trader,"Trader",argv[2]);
   } else if (!stricmp(argv[1],"AFK")) {
      SetDisplaySWhoFilter(&gFilterSWho.AFK,"AFK",argv[2]);
   } else if (!stricmp(argv[1],"Anon")) {
      SetDisplaySWhoFilter(&gFilterSWho.Anon,"Anon",argv[2]);
   } else if (!stricmp(argv[1],"Distance")) {
      SetDisplaySWhoFilter(&gFilterSWho.Distance,"Distance",argv[2]);
   } else if (!stricmp(argv[1],"Light")) {
      SetDisplaySWhoFilter(&gFilterSWho.Light,"Light",argv[2]);
   } else if (!stricmp(argv[1],"Holding")) {
      SetDisplaySWhoFilter(&gFilterSWho.Holding,"Holding",argv[2]);
   } else if (!stricmp(argv[1],"ConColor")) {
        SetDisplaySWhoFilter(&gFilterSWho.ConColor,"ConColor",argv[2]);
   } else if (!stricmp(argv[1],"Invisible")) {
        SetDisplaySWhoFilter(&gFilterSWho.Invisible,"Invisible",argv[2]);
   } else {
       WriteChatf("Syntax: %s <lastname|class|race|level|gm|guild|holding|ld|sneak|anon|lfg|npctag|spawnid|trader|afk|concolor|invisible> [on|off]",0);
   }
   return 0;
}

// ***************************************************************************
// Function:    CMD_Where
// Description: Our '/where' command
//              Displays the direction and distance to the closest spawn
// Usage:       /where <spawn>
// ***************************************************************************
int CMD_Where(int argc, char* argv[])
{
   if (argc<2)
   {
      WriteChatf("Syntax: %s <spawn>",argv[0]);
      return 0;
   }
    if (!ppSpawnList) return 0;
    if (!pSpawnList) return 0;
   PSPAWNINFO pChar = GetCharInfo()->pSpawn;
    PSPAWNINFO pSpawnClosest = NULL;
    SEARCHSPAWN SearchSpawn;
    ClearSearchSpawn(&SearchSpawn);
    CHAR szMsg[MAX_STRING] = {0};
    CHAR szName[MAX_STRING] = {0};
    CHAR szArg[MAX_STRING] = {0};
   
    bRunNextCommand = TRUE;
   SearchSpawn.SpawnType= PC;

   ParseSearchSpawn(1,argc,argv,SearchSpawn);

    if (!(pSpawnClosest = SearchThroughSpawns(&SearchSpawn,pChar))) {
        sprintf(szMsg,"There were no matches for: %s",FormatSearchSpawn(szArg,&SearchSpawn));
    } else {
        INT Angle = (INT)((atan2f(pChar->X - pSpawnClosest->X, pChar->Y - pSpawnClosest->Y) * 180.0f / PI + 360.0f) / 22.5f + 0.5f) % 16;
        sprintf(szMsg,"The closest '%s' is a level %d %s %s and %1.2f away to the %s, Z difference = %1.2f",
            CleanupName(strcpy(szName,pSpawnClosest->Name),FALSE),
            pSpawnClosest->Level,
            pEverQuest->GetRaceDesc(pSpawnClosest->Race),
            GetClassDesc(pSpawnClosest->Class),
            DistanceToSpawn(pChar,pSpawnClosest),
            szHeading[Angle],
            pSpawnClosest->Z-pChar->Z);
        DebugSpew("Where - %s",szMsg);
    }
    WriteChatColor(szMsg,USERCOLOR_WHO);
   
    return 0;
}


// *************************************************************************** 
// Function:    CMD_CastSpell 
// Description: Our '/cast' command 
//              Displays the direction and distance to the closest spawn 
// Usage:       /cast [list|#|"name of spell"|item "name of item"] 
// *************************************************************************** 
int CMD_CastSpell(int argc, char* argv[]) 
{ 
   DWORD Index; 
   CHAR szBuffer[MAX_STRING] = {0}; 

   if (gGameState!=GAMESTATE_INGAME) 
      return -1; 

   if (!cmdCast) 
   { 
      PCMDLIST pCmdListOrig = (PCMDLIST)EQADDR_CMDLIST; 
      for (int i=0;pCmdListOrig[i].fAddress != 0;i++) { 
         if (!strcmp(pCmdListOrig[i].szName,"/cast")) { 
            cmdCast = (fEQCommand)pCmdListOrig[i].fAddress; 
         } 
      } 
   } 
   if (!cmdCast) return -1; 
   if (argc<2) 
   { 
      WriteChatf("Syntax: %s list|#|<name of spell>|item <name of item>",argv[0]); 
      return 0; 
   } 

   if ( !ppSpellMgr || !ppCharData || !pCharData) { 
      return -1; 
   } 
   PCHARINFO pCharInfo = GetCharInfo(); 
   if (NULL == pCharInfo) return -1; 
   if (argc == 2 && atoi(argv[1])){ 
      cmdCast((PSPAWNINFO)pLocalPlayer, argv[1]); 
      return 0; 
   } 
   //   CHAR szArg1[MAX_STRING] = {0}; 
   //   CHAR szArg2[MAX_STRING] = {0}; 
   if (!stricmp(argv[1],"list")) { 
      WriteChatColor("Spells:",USERCOLOR_DEFAULT); 
      for (Index=0;Index<9;Index++) { 
         if (GetCharInfo2()->MemorizedSpells[Index]==0xFFFFFFFF) { 
            sprintf(szBuffer,"%d. <Empty>",Index+1); 
         } else { 
            sprintf(szBuffer,"%d. %s",Index+1,GetSpellByID(GetCharInfo2()->MemorizedSpells[Index])); 
         } 
         WriteChatColor(szBuffer,USERCOLOR_DEFAULT); 
      } 
      return 0; 
   } 

   //   GetArg(szArg1,szLine,1); 
   //   GetArg(szArg2,szLine,2); 
   //   DebugSpew("Cast: szArg1 = %s szArg2 = %s",szArg1,szArg2); 
   if (!stricmp(argv[1],"item")) 
   { 
      CHAR szItemToCast[8192]; 
      pISInterface->GetArgs(2,argc,argv,szItemToCast); 
      BOOL FOUND = FALSE; 
      DWORD item = 0; 
      DWORD slot = 0; 
      DWORD SpawnFooter = NULL; 
      SpawnFooter = (DWORD)pLocalPlayer; 
      for (int i=0;i<30;i++) { 
         if (GetCharInfo2()->InventoryArray[i]) 
            if (!_stricmp(szItemToCast,GetCharInfo2()->InventoryArray[i]->Item->Name)) { 
               DebugSpew("cast test slot %d = %s address is %x",i,GetCharInfo2()->InventoryArray[i]->Item->Name,&(GetCharInfo2()->InventoryArray[i])); 
               item = (DWORD)&GetCharInfo2()->InventoryArray[i]; 
               slot = (DWORD)i; 
               FOUND = TRUE; 
               break; 
            } 
      } 
      if (FOUND) { 
         pCharData->CastSpell(10,0,(EQ_Item**)item,0,slot,-1,0,0); 
         return 0; 
      } 
   } 
   pISInterface->GetArgs(1,argc,argv,szBuffer); 
   //GetArg(szBuffer,szLine,1); 
   for (Index=0;Index<9;Index++) { 
      if (GetCharInfo2()->MemorizedSpells[Index]!=0xFFFFFFFF) { 
         PCHAR SpellName = GetSpellNameByID(GetCharInfo2()->MemorizedSpells[Index]); 
         if (!stricmp(szBuffer,SpellName)) { 
            DebugSpew("SpellName = %s",SpellName); 
            cmdCast((PSPAWNINFO)pLocalPlayer,itoa(Index+1,szBuffer,10)); 
            DebugSpew("pChar = %x SpellName = %s %d",pCharInfo,SpellName,Index+1); 
            return 0; 
         } 
      } 
   } 
   WriteChatColor("You do not seem to have that spell memorized.",USERCOLOR_DEFAULT); 
   return 0; 

} 

// ***************************************************************************
// Function:    MemSpell
// Description: Our '/MemSpell' command
// Usage:       /MemSpell gem# "spell name"
// ***************************************************************************
SPELLFAVORITE MemSpellFavorite;
int CMD_MemSpell(int argc, char *argv[])
{
   if (argc < 3)
   {
      WriteChatf("Syntax: %s <gem #> <spellname>",argv[0]);
      return 0;
   }
    if (!ppSpellBookWnd) return -1;
    DWORD Favorite = (DWORD)&MemSpellFavorite;
   CHAR szGem[MAX_STRING] = {0};
    DWORD sp;
   WORD Gem = -1;
   CHAR SpellName[MAX_STRING] = {0};
   PCHARINFO pCharInfo = NULL;
    if (!pSpellBookWnd) return -1;
   if (NULL == (pCharInfo = GetCharInfo())) return -1;

//   GetArg(szGem,szLine,1);
//   GetArg(SpellName,szLine,2);
   pISInterface->GetArgs(2,argc,argv,SpellName);
   Gem = atoi(argv[1]);
   if (Gem<1 || Gem>9) return -1;
   Gem--;

   GetCharInfo2()->SpellBook;
   PSPELL pSpell=0;
   for (DWORD N = 0 ; N < NUM_BOOK_SLOTS ; N++)
   if (PSPELL pTempSpell=GetSpellByID(GetCharInfo2()->SpellBook[N]))
   {
      if (!stricmp(SpellName,pTempSpell->Name))
      {
         pSpell=pTempSpell;
         break;
      }
   }

    if (!pSpell) return -1;
    if (pSpell->Level[GetCharInfo2()->Class-1]>GetCharInfo2()->Level) return -1;

    ZeroMemory(&MemSpellFavorite,sizeof(MemSpellFavorite));
    strcpy(MemSpellFavorite.Name,"Mem a Spell");
    MemSpellFavorite.Byte_3e=1;
    for (sp=0;sp<9;sp++) MemSpellFavorite.SpellId[sp]=0xFFFFFFFF;
    MemSpellFavorite.SpellId[Gem] = pSpell->ID;
   pSpellBookWnd->MemorizeSet((int*)Favorite,9);
   return 0;
} 

// *************************************************************************** 
// Function:    DoAbility 
// Description: Our '/doability' command 
//              Does (or lists) your abilities 
// Usage:       /doability [list|ability|#] 
// *************************************************************************** 
int CMD_DoAbility(int argc, char *argv[]) 
{ 
   if (!cmdDoAbility) 
   { 
      PCMDLIST pCmdListOrig = (PCMDLIST)EQADDR_CMDLIST; 
      for (int i=0;pCmdListOrig[i].fAddress != 0;i++) { 
         if (!strcmp(pCmdListOrig[i].szName,"/doability")) { 
            cmdDoAbility = (fEQCommand)pCmdListOrig[i].fAddress; 
         } 
      } 
   } 
    if (!cmdDoAbility) return -1; 

    if (argc<2 || atoi(argv[1]) || !EQADDR_DOABILITYLIST) { 
        cmdDoAbility((PSPAWNINFO)pLocalPlayer,argv[1]); 
        return 0; 
    } 

    DWORD Index, DoIndex = 0xFFFFFFFF; 
    CHAR szBuffer[MAX_STRING] = {0}; 

    if (!stricmp(argv[1],"list") || !stricmp(argv[1], "-list")) { 
        WriteChatColor("Abilities:",USERCOLOR_DEFAULT); 
        for (Index=4;Index<10;Index++) { 
            if (EQADDR_DOABILITYLIST[Index]==0xFFFFFFFF) { 
                sprintf(szBuffer,"%d. <Empty>",Index-3); 
            } else if (szSkills[EQADDR_DOABILITYLIST[Index]]) { 
                sprintf(szBuffer,"%d. %s",Index-3,szSkills[EQADDR_DOABILITYLIST[Index]]); 
            } else { 
                sprintf(szBuffer,"%d. *Unknown%d",Index-3,EQADDR_DOABILITYLIST[Index]); 
            } 
            WriteChatColor(szBuffer,USERCOLOR_DEFAULT); 
        } 
        WriteChatColor("Combat Skills:",USERCOLOR_DEFAULT); 
        for (Index=0;Index<4;Index++) { 
            if (EQADDR_DOABILITYLIST[Index]==0xFFFFFFFF) { 
                sprintf(szBuffer,"%d. <Empty>",Index+7); 
            } else if (szSkills[EQADDR_DOABILITYLIST[Index]]) { 
                sprintf(szBuffer,"%d. %s",Index+7,szSkills[EQADDR_DOABILITYLIST[Index]]); 
            } else { 
                sprintf(szBuffer,"%d. *Unknown%d",Index+7,EQADDR_DOABILITYLIST[Index]); 
            } 
            WriteChatColor(szBuffer,USERCOLOR_DEFAULT); 
        } 
        WriteChatColor("Combat Abiilities:",USERCOLOR_DEFAULT); 
        for (Index=10;Index<18;Index++) { 
            if (EQADDR_DOABILITYLIST[Index]==0xFFFFFFFF) { 
                sprintf(szBuffer,"%d. <Empty>",Index+1); 
         } else if (EQADDR_DOABILITYLIST[Index] > 132) { // highest number we have defined so far 
            sprintf(szBuffer,"%d. *Unknown%d",Index+1,EQADDR_DOABILITYLIST[Index]); 
            } else if (szSkills[EQADDR_DOABILITYLIST[Index]]) { 
                sprintf(szBuffer,"%d. %s",Index+1,szSkills[EQADDR_DOABILITYLIST[Index]]); 
            } else { 
                sprintf(szBuffer,"%d. *Unknown%d",Index+1,EQADDR_DOABILITYLIST[Index]); 
            } 
            WriteChatColor(szBuffer,USERCOLOR_DEFAULT); 
        } 
        return 0; 
    } 

   pISInterface->GetArgs(1,argc,argv,szBuffer); 

    for (Index=0;Index<10;Index++) { 
        if (EQADDR_DOABILITYLIST[Index]!= 0xFFFFFFFF) { 
            if (!strnicmp(szBuffer,szSkills[EQADDR_DOABILITYLIST[Index]],strlen(szSkills[EQADDR_DOABILITYLIST[Index]]))) { 
                if (Index<4) { 
                    DoIndex = Index+7; // 0-3 = Combat abilities (7-10) 
                } else { 
                    DoIndex = Index-3; // 4-9 = Abilities (1-6) 
                } 
            } 
        } 
    } 
    if (DoIndex!=0xFFFFFFFF) { 
        cmdDoAbility((PSPAWNINFO)pLocalPlayer,itoa(DoIndex,szBuffer,10)); 
    } else { 
        WriteChatColor("You do not seem to have that ability on a /doability button",USERCOLOR_DEFAULT); 
    } 
   return 0; 
} 


// CMD_EQModKey
int CMD_EQModKey(int argc, char *argv[])
{
	CHAR chCommand[2048] = {0};
	bool KeyboardFlags[4] = {false,false,false,false};

	if (argc<1)
	{
			WriteChatf("Usage: %s <command>", argv[0]);
			return 0;
	}
	pISInterface->GetArgs(1,argc,argv,chCommand);
	*(DWORD*)&KeyboardFlags=*(DWORD*)&((PCXWNDMGR)pWndMgr)->KeyboardFlags;
	if (!stricmp(argv[0],"nomodkey"))
			*(DWORD*)&((PCXWNDMGR)pWndMgr)->KeyboardFlags=0;
	else if (!stricmp(argv[0],"shift"))
			((PCXWNDMGR)pWndMgr)->KeyboardFlags[0]=1;
	else if (!stricmp(argv[0],"ctrl"))
			((PCXWNDMGR)pWndMgr)->KeyboardFlags[1]=1;
	else if (!stricmp(argv[0],"alt"))
			((PCXWNDMGR)pWndMgr)->KeyboardFlags[2]=1;
	DebugSpew("CMD_EQModKey Executing %s", chCommand);
	pISInterface->ExecuteCommand(chCommand);
	*(DWORD*)&((PCXWNDMGR)pWndMgr)->KeyboardFlags=*(DWORD*)&KeyboardFlags;
	return 0;
} 