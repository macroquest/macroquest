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
CMQ2Alerts CAlerts;
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
  if (!cmdWho)
  {
     PCMDLIST pCmdListOrig = (PCMDLIST)EQADDR_CMDLIST;
     for (int i=0;pCmdListOrig[i].fAddress != 0;i++) {
        if (!strcmp(pCmdListOrig[i].szName,"/who")) {
           cmdWho = (fEQCommand)pCmdListOrig[i].fAddress;
        }
     }
  }
  if (!cmdWho) return -1;

	for (int i = 1 ; i < argc ; i++)
	{
		if (!stricmp(argv[i],"all"))
		{
                      CHAR szRest[MAX_STRING] = {0};
                      pISInterface->GetArgs(1,argc,argv,szRest,sizeof(szRest));
                      cmdWho((PSPAWNINFO)pLocalPlayer, szRest);
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
	pISInterface->GetArgs(1,argc,argv,szRest, sizeof(szRest));
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
    if (!ppSpawnManager) return 0;
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
    if (!ppSpawnManager) return 0;
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
      for (Index=0;Index<NUM_SPELL_GEMS;Index++) {
         if (GetCharInfo2()->MemorizedSpells[Index]==0xFFFFFFFF) { 
            WriteChatf("%d. <Empty>",Index+1); 
         } else { 
            WriteChatf("%d. %s",Index+1,GetSpellByID(GetCharInfo2()->MemorizedSpells[Index])); 
         } 
      } 
      return 0; 
   } 

   //   GetArg(szArg1,szLine,1); 
   //   GetArg(szArg2,szLine,2); 
   //   DebugSpew("Cast: szArg1 = %s szArg2 = %s",szArg1,szArg2); 
   if (!stricmp(argv[1],"item")) 
   { 
      BOOL FOUND = FALSE; 
      DWORD item = 0; 
      DWORD slot = 0; 
      DWORD SpawnFooter = NULL; 
      SpawnFooter = (DWORD)pLocalPlayer;
		PITEMINFO pItem=0;
      for (int i=0;i<NUM_INV_SLOTS;i++) { 
         if (GetCharInfo2()->pInventoryArray->InventoryArray[i]) 
            if (!_stricmp(argv[2],GetItemFromContents(GetCharInfo2()->pInventoryArray->InventoryArray[i])->Name)) { 
               DebugSpew("cast test slot %d = %s address is %x",i,GetItemFromContents(GetCharInfo2()->pInventoryArray->InventoryArray[i])->Name,&(GetCharInfo2()->pInventoryArray->InventoryArray[i])); 
               item = (DWORD)&GetCharInfo2()->pInventoryArray->InventoryArray[i];
					pItem=GetItemFromContents(GetCharInfo2()->pInventoryArray->InventoryArray[i]); 
               slot = (DWORD)i; 
               FOUND = TRUE; 
               break; 
            } 
      } 
      if (FOUND) { 
       if(CInvSlot *pSlot = pInvSlotMgr->FindInvSlot(slot))
       {
          CXPoint p; p.A=0; p.B=0;
          pSlot->HandleRButtonUp(&p);
       }
         return 0; 
      } 
   } 
   for (Index=0;Index<NUM_SPELL_GEMS;Index++) { 
      if (GetCharInfo2()->MemorizedSpells[Index]!=0xFFFFFFFF) { 
         PCHAR SpellName = GetSpellNameByID(GetCharInfo2()->MemorizedSpells[Index]); 
         if (!stricmp(argv[1],SpellName)) { 
            DebugSpew("SpellName = %s",SpellName); 

			char szBuffer[256];
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
   DWORD sp;
   WORD Gem = -1;
   PCHARINFO pCharInfo = NULL;
   if (!pSpellBookWnd) return -1;
   if (NULL == (pCharInfo = GetCharInfo())) return -1;

   Gem = atoi(argv[1]);
   if (Gem<1 || Gem>NUM_SPELL_GEMS) return -1;
   Gem--;

   GetCharInfo2()->SpellBook;
   PSPELL pSpell=0;
   for (DWORD N = 0 ; N < NUM_BOOK_SLOTS ; N++)
   if (PSPELL pTempSpell=GetSpellByID(GetCharInfo2()->SpellBook[N]))
   {
      if (!stricmp(argv[2],pTempSpell->Name))
      {
         pSpell=pTempSpell;
         break;
      }
   }

   if (!pSpell) return -1;
   if (pSpell->ClassLevel[GetCharInfo2()->Class]>GetCharInfo2()->Level) return -1;

   ZeroMemory(&MemSpellFavorite,sizeof(MemSpellFavorite));
   strcpy(MemSpellFavorite.Name,"Mem a Spell");
   MemSpellFavorite.inuse=1;
   for (sp=0;sp<NUM_SPELL_GEMS;sp++) MemSpellFavorite.SpellId[sp]=0xFFFFFFFF; 
   MemSpellFavorite.SpellId[Gem] = pSpell->ID;
   pSpellBookWnd->MemorizeSet((int*)Favorite,NUM_SPELL_GEMS); 
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
	if (argc<2)
	{
		printf("Syntax: %s list|<ability>",argv[0]);
		return 0;
	}

    DWORD Index, DoIndex = 0xFFFFFFFF;

    if (!stricmp(argv[1],"list") || !stricmp(argv[1], "-list")) 
	{
        WriteChatColor("Abilities:",USERCOLOR_DEFAULT);
        for (Index=4;Index<10;Index++) {
            if (EQADDR_DOABILITYLIST[Index]==0xFFFFFFFF)
			{
                WriteChatf("%d. <Empty>",Index-3);
            } 
			else if (szSkills[EQADDR_DOABILITYLIST[Index]]) 
			{
                WriteChatf("%d. %s",Index-3,szSkills[EQADDR_DOABILITYLIST[Index]]);
            } 
			else 
			{
                WriteChatf("%d. *Unknown%d",Index-3,EQADDR_DOABILITYLIST[Index]);
            }
        }
        WriteChatColor("Combat Skills:");
        for (Index=0;Index<4;Index++) 
		{
            if (EQADDR_DOABILITYLIST[Index]==0xFFFFFFFF) 
			{
                WriteChatf("%d. <Empty>",Index+7);
            } 
			else if (szSkills[EQADDR_DOABILITYLIST[Index]]) 
			{
                WriteChatf("%d. %s",Index+7,szSkills[EQADDR_DOABILITYLIST[Index]]);
            } 
			else 
			{
                WriteChatf("%d. *Unknown%d",Index+7,EQADDR_DOABILITYLIST[Index]);
            }
        }
        WriteChatColor("Combat Abiilities:",USERCOLOR_DEFAULT);
        for (Index=10;Index<18;Index++) 
		{
            if (EQADDR_DOABILITYLIST[Index]==0xFFFFFFFF) 
			{
                WriteChatf("%d. <Empty>",Index+1);
			} 
			else if (EQADDR_DOABILITYLIST[Index] > 132) 
			{ // highest number we have defined so far
				WriteChatf("%d. *Unknown%d",Index+1,EQADDR_DOABILITYLIST[Index]);
			} 
			else if (szSkills[EQADDR_DOABILITYLIST[Index]]) 
			{
				WriteChatf("%d. %s",Index+1,szSkills[EQADDR_DOABILITYLIST[Index]]);
			} 
			else 
			{
				WriteChatf("%d. *Unknown%d",Index+1,EQADDR_DOABILITYLIST[Index]);
			}
        }
        return 0;
    }

   UseAbility(argv[1]);

   return 0;
}
/*
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
/**/

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
	pISInterface->GetArgs(1,argc,argv,chCommand,sizeof(chCommand));
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
int CMD_EQDestroy(int argc, char *argv[])
{
   (pPCData)->DestroyHeldItemOrMoney();
   return 0;
}


int CMD_EQFace(int argc, char *argv[])
{
//VOID Face(PSPAWNINFO pChar, PCHAR szLine)
//{
    if (!ppSpawnManager) return 0;
    if (!pSpawnList) return 0;
    PSPAWNINFO pSpawnClosest = NULL;
    PSPAWNINFO psTarget = NULL;
    SPAWNINFO LocSpawn = {0};
   PSPAWNINFO pChar = (PSPAWNINFO)pLocalPlayer;
    SEARCHSPAWN SearchSpawn;
    ClearSearchSpawn(&SearchSpawn);
    CHAR szMsg[MAX_STRING] = {0};
    CHAR szName[MAX_STRING] = {0};
    CHAR szArg[MAX_STRING] = {0};
   PCHAR pszArg = NULL;
    BOOL bArg = TRUE;
    BOOL bOtherArgs = FALSE;
    BOOL Away = FALSE;
    BOOL Predict = FALSE;
    BOOL Fast = FALSE;
    BOOL Look = TRUE;
    BOOL Parsing = TRUE;
    DOUBLE Distance;

   for(int qq=1; qq<argc; qq++)
   {
      if (!strcmp(argv[qq],"predict")) {
         Predict=TRUE;
      } else if (!strcmp(argv[qq],"fast")) {
         Fast = TRUE;
      } else if (!strcmp(argv[qq],"away")) {
         Away = TRUE;
      } else if (!strcmp(argv[qq],"nolook")) {
         Look = FALSE;
      } else if (!strnicmp(argv[qq], "loc", 3)) {
         pSpawnClosest = &LocSpawn;
         strcpy(LocSpawn.Name,"location");
         if (((++qq)<argc) && strstr(argv[qq],","))
         {
             pSpawnClosest->Y = (FLOAT)atof(argv[qq]);
            pszArg = strstr(argv[qq],",")+1;
              pSpawnClosest->X = (FLOAT)atof(pszArg);
         }
      } else if (!stricmp(argv[qq], "item")) {
         if (EnviroTarget.Name[0]==0) {
            printf("%s: item specified but no item targetted.", argv[0]);
            return 0;
         }
         pSpawnClosest = &EnviroTarget;
      }
	  else if (!stricmp(argv[qq], "door")) {
		  if (DoorEnviroTarget.Name[0] == 0) {
			  printf("%s: door specified but no door targetted.", argv[0]);
			  return 0;
		  }
		  pSpawnClosest = &DoorEnviroTarget;
      } else if (!strcmp(szArg,"help")) {
         printf("Usage: %s [spawn] [item] [door] [id #] [heading <ang>] [loc <y>,<x>] [away] [alert #]",argv[0]);
         return 0;
      } else {
         bOtherArgs = TRUE;
         qq+=ParseSearchSpawnArg(qq,argc,argv,SearchSpawn);
//         szFilter = ParseSearchSpawnArgs(szArg,szFilter,&SearchSpawn);
      }
   }

   if (!pSpawnClosest) {
      if (!bOtherArgs) {
         if (ppTarget && pTarget) {
            pSpawnClosest = (PSPAWNINFO)pTarget;
         }
      } else {
         pSpawnClosest = SearchThroughSpawns(&SearchSpawn,pChar);
      }
   }

   szMsg[0]=0;

   if (!pSpawnClosest) {
      printf("There were no matches for: %s",FormatSearchSpawn(szArg,&SearchSpawn));
   } else {
      if (Predict) {
         Distance = DistanceToSpawn(pChar, pSpawnClosest);
         gFaceAngle = (
            atan2((pSpawnClosest->X + (pSpawnClosest->SpeedX * Distance)) - pChar->X,
            (pSpawnClosest->Y + (pSpawnClosest->SpeedY * Distance)) - pChar->Y)
            * 256.0f / PI);
      } else {
         gFaceAngle = (
            atan2(pSpawnClosest->X - pChar->X,
            pSpawnClosest->Y - pChar->Y)
            * 256.0f / PI);
      }
      if (Look) {
         Distance = DistanceToSpawn(pChar, pSpawnClosest);
         gLookAngle = (
            atan2(pSpawnClosest->Z + pSpawnClosest->AvatarHeight*StateHeightMultiplier(pSpawnClosest->StandState) - pChar->Z - pChar->AvatarHeight*StateHeightMultiplier(pChar->StandState),
            (FLOAT)Distance)
            * 256.0f / PI);
         if (Away) gLookAngle = -gLookAngle;
         if (Fast) {
            pChar->CameraAngle = (FLOAT)gLookAngle;
            gLookAngle=10000.0f;
         }
      }
      if (Away) {
         gFaceAngle += 256.0f;
      }
      if (gFaceAngle>=512.0f) gFaceAngle -= 512.0f;
      if (gFaceAngle<0.0f) gFaceAngle += 512.0f;
      if (Fast) {
         ((PSPAWNINFO)pCharSpawn)->Heading = (FLOAT)gFaceAngle;
         gFaceAngle=10000.0f;
      }
      sprintf(szMsg,"Facing %s'%s'...",(Away)?"away from ":"", CleanupName(strcpy(szName,pSpawnClosest->Name),FALSE));
   }
   if (ppTarget && pTarget) {
      psTarget = (PSPAWNINFO)pTarget;
   }
   if (szMsg[0] && ((pSpawnClosest != &LocSpawn) && ((Away) || (pSpawnClosest != psTarget)))) WriteChatColor(szMsg,USERCOLOR_WHO);
   DebugSpew("Face - %s",szMsg);
   return 0;
}


// ***************************************************************************
// Function:      Look
// Description:      Our /look command. Changes camera angle
// 2003-08-30      MacroFiend
// ***************************************************************************
int CMD_EQLook(int argc, char *argv[])
{
   FLOAT fLookAngle=0.0f;
   PSPAWNINFO pChar = (PSPAWNINFO)pLocalPlayer;
   if (argc < 2)
      return 0;
   fLookAngle = (FLOAT)atof(argv[1]);

   if (fLookAngle>128.0f || fLookAngle<-128.0f) {
      printf("%s -- Angle %f out of range.",argv[0],fLookAngle);
      return 0;
   }

   pChar->CameraAngle = fLookAngle;
   gLookAngle = 10000.0f;
   return 0;
}

int CMD_EQEcho(int argc, char *argv[])
{
	static map<utf8stringnocase,unsigned int> Filters;
	static bool FiltersInitialized=false;

	if (argc<2)
	{
		printf("Syntax: %s <-channelfilters>|[-<channelfilter>] <text ...>",argv[0]);
		return 0;
	}

	if (!FiltersInitialized)
	{
		FiltersInitialized=true;

Filters["say"]=USERCOLOR_SAY;
Filters["tell"]=USERCOLOR_TELL;
Filters["group"]=USERCOLOR_GROUP;
Filters["guild"]=USERCOLOR_GUILD;
Filters["ooc"]=USERCOLOR_OOC;
Filters["auction"]=USERCOLOR_AUCTION;
Filters["shout"]=USERCOLOR_SHOUT;
Filters["emote"]=USERCOLOR_EMOTE;
Filters["spells"]=USERCOLOR_SPELLS;
Filters["youhit"]=USERCOLOR_YOU_HIT_OTHER;
Filters["hityou"]=USERCOLOR_OTHER_HIT_YOU;
Filters["youmiss"]=USERCOLOR_YOU_MISS_OTHER;
Filters["missyou"]=USERCOLOR_OTHER_MISS_YOU;
Filters["duel"]=USERCOLOR_DUELS;
Filters["skill"]=USERCOLOR_SKILLS;
Filters["disc"]=USERCOLOR_DISCIPLINES;
Filters["unused1"]=USERCOLOR_UNUSED001;
Filters["default"]=USERCOLOR_DEFAULT;
Filters["unused2"]=USERCOLOR_UNUSED002;
Filters["merchantoffer"]=USERCOLOR_MERCHANT_OFFER;
Filters["merchantexchange"]=USERCOLOR_MERCHANT_EXCHANGE;
Filters["youdie"]=USERCOLOR_YOUR_DEATH;
Filters["theydie"]=USERCOLOR_OTHER_DEATH;
Filters["otherhit"]=USERCOLOR_OTHER_HIT_OTHER;
Filters["othermiss"]=USERCOLOR_OTHER_MISS_OTHER;
Filters["who"]=USERCOLOR_WHO;
Filters["yell"]=USERCOLOR_YELL;
Filters["nonmelee"]=USERCOLOR_NON_MELEE;
Filters["spellfade"]=USERCOLOR_SPELL_WORN_OFF;
Filters["split"]=USERCOLOR_MONEY_SPLIT;
Filters["loot"]=USERCOLOR_LOOT;
Filters["random"]=USERCOLOR_RANDOM;
Filters["otherspell"]=USERCOLOR_OTHERS_SPELLS;
Filters["spellfail"]=USERCOLOR_SPELL_FAILURE;
Filters["chatchannel"]=USERCOLOR_CHAT_CHANNEL;
Filters["chat1"]=USERCOLOR_CHAT_1;
Filters["chat2"]=USERCOLOR_CHAT_2;
Filters["chat3"]=USERCOLOR_CHAT_3;
Filters["chat4"]=USERCOLOR_CHAT_4;
Filters["chat5"]=USERCOLOR_CHAT_5;
Filters["chat6"]=USERCOLOR_CHAT_6;
Filters["chat7"]=USERCOLOR_CHAT_7;
Filters["chat8"]=USERCOLOR_CHAT_8;
Filters["chat9"]=USERCOLOR_CHAT_9;
Filters["chat10"]=USERCOLOR_CHAT_10;
Filters["meleecrit"]=USERCOLOR_MELEE_CRIT;
Filters["spellcrit"]=USERCOLOR_SPELL_CRIT;
Filters["toofar"]=USERCOLOR_TOO_FAR_AWAY;
Filters["rampage"]=USERCOLOR_NPC_RAMPAGE;
Filters["flurry"]=USERCOLOR_NPC_FLURRY;
Filters["enrage"]=USERCOLOR_NPC_ENRAGE;
Filters["sayecho"]=USERCOLOR_ECHO_SAY;
Filters["tellecho"]=USERCOLOR_ECHO_TELL;
Filters["groupecho"]=USERCOLOR_ECHO_GROUP;
Filters["guildecho"]=USERCOLOR_ECHO_GUILD;
Filters["oocecho"]=USERCOLOR_ECHO_OOC;
Filters["auctionecho"]=USERCOLOR_ECHO_AUCTION;
Filters["shoutecho"]=USERCOLOR_ECHO_SHOUT;
Filters["emoteecho"]=USERCOLOR_ECHO_EMOTE;
Filters["chat1echo"]=USERCOLOR_ECHO_CHAT_1;
Filters["chat2echo"]=USERCOLOR_ECHO_CHAT_2;
Filters["chat3echo"]=USERCOLOR_ECHO_CHAT_3;
Filters["chat4echo"]=USERCOLOR_ECHO_CHAT_4;
Filters["chat5echo"]=USERCOLOR_ECHO_CHAT_5;
Filters["chat6echo"]=USERCOLOR_ECHO_CHAT_6;
Filters["chat7echo"]=USERCOLOR_ECHO_CHAT_7;
Filters["chat8echo"]=USERCOLOR_ECHO_CHAT_8;
Filters["chat9echo"]=USERCOLOR_ECHO_CHAT_9;
Filters["chat10echo"]=USERCOLOR_ECHO_CHAT_10;
Filters["reserved"]=USERCOLOR_RESERVED;
Filters["link"]=USERCOLOR_LINK;
Filters["raid"]=USERCOLOR_RAID;
Filters["pet"]=USERCOLOR_PET;
Filters["damageshield"]=USERCOLOR_DAMAGESHIELD;
Filters["leader"]=USERCOLOR_LEADER;
Filters["petrampflurry"]=USERCOLOR_PETRAMPFLURRY;
Filters["petcrit"]=USERCOLOR_PETCRITS;
Filters["focus"]=USERCOLOR_FOCUS;
Filters["exp"]=USERCOLOR_XP;
Filters["system"]=USERCOLOR_SYSTEM;

	}


	unsigned int Color=USERCOLOR_DEFAULT;
	int arg=1;
	if (argv[arg][0]=='-')
	{
		if (!stricmp(argv[arg],"-channelfilters"))
		{
			CColumnRenderer CR;
			for (map<utf8stringnocase,unsigned int>::iterator i=Filters.begin() ;i!=Filters.end() ; i++)
			{
				CR.AddItem(i->first.c_str());
			}
			CR.Render(pISInterface);
			return 0;
		}
		map<utf8stringnocase,unsigned int>::iterator i=Filters.find(&argv[arg][1]);
		if (i!=Filters.end())
			Color=i->second;
		arg++;
	}

	if (argc<=arg)
	{
		printf("Syntax: %s [-<channelfilter>] <text ...>",argv[0]);
		return 0;
	}
	char FullText[8192];
	pISInterface->GetArgs(arg,argc,argv,FullText,sizeof(FullText));
	dsp_chat_no_events(FullText,Color,1);
	return 0;
}

int CMD_EQItems(int argc, char *argv[])
{
    if (!ppItemList) return 0;
    if (!pItemList) return 0;
   PSPAWNINFO pChar = (PSPAWNINFO)pLocalPlayer;
    PGROUNDITEM pItem = (PGROUNDITEM)pItemList;
    DWORD Count=0;
    CHAR szBuffer[MAX_STRING] = {0};
   CHAR szName[MAX_STRING]={0};
    WriteChatColor("Items on the ground:", USERCOLOR_DEFAULT);
    WriteChatColor("---------------------------", USERCOLOR_DEFAULT);
    while (pItem) {
        GetFriendlyNameForGroundItem(pItem,szName);

        if ((argc==1) || (!strnicmp(szName,argv[1],strlen(argv[1])))) {
            SPAWNINFO TempSpawn;
            FLOAT Distance;
            ZeroMemory(&TempSpawn,sizeof(TempSpawn));
            strcpy(TempSpawn.Name,szName);
            TempSpawn.Y=pItem->Y;
            TempSpawn.X=pItem->X;
            TempSpawn.Z=pItem->Z;
            Distance = DistanceToSpawn(pChar,&TempSpawn);
            INT Angle = (INT)((atan2f(pChar->X - pItem->X, pChar->Y - pItem->Y) * 180.0f / PI + 360.0f) / 22.5f + 0.5f) % 16;

            sprintf(szBuffer,"%s: %1.2f away to the %s",szName,Distance,szHeading[Angle]);
            WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
            Count++;
        }

        pItem = pItem->pNext;
    }
    if (Count==0) {
        WriteChatColor("No items found.",USERCOLOR_DEFAULT);
    } else {
        sprintf(szBuffer,"%d item%s found.",Count,(Count==1)?"":"s");
        WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
    }
   return 0;
} 

int CMD_DoorTarget(int argc, char *argv[])
{
 
   if (!ppSwitchMgr) return 0;
   if (!pSwitchMgr) return 0;
   PDOORTABLE pDoorTable = (PDOORTABLE)pSwitchMgr;
   DWORD Count;

   PSPAWNINFO pChar = (PSPAWNINFO)pLocalPlayer;
   CHAR szBuffer[MAX_STRING] = {0};
   CHAR szSearch[MAX_STRING] = {0};
   FLOAT cDistance = 100000.0f;
   BYTE ID = -1;
   ZeroMemory(&DoorEnviroTarget,sizeof(DoorEnviroTarget));
   pDoorTarget = NULL;

   if (argc > 1 && !stricmp(argv[1], "id")) {
      if (argc < 3) {
         WriteChatf("DoorTarget: id specified but no number provided.");
         return 0;
      }

      ID = atoi(argv[2]);
      for (Count=0; Count<pDoorTable->NumEntries; Count++) {
         if (pDoorTable->pDoor[Count]->ID == ID) {
            strcpy(DoorEnviroTarget.Name, pDoorTable->pDoor[Count]->Name);
            DoorEnviroTarget.Y = pDoorTable->pDoor[Count]->Y;
            DoorEnviroTarget.X = pDoorTable->pDoor[Count]->X;
            DoorEnviroTarget.Z = pDoorTable->pDoor[Count]->Z;
            DoorEnviroTarget.Heading = pDoorTable->pDoor[Count]->Heading;
			DoorEnviroTarget.Type = SPAWN_NPC;
			DoorEnviroTarget.HPCurrent = 1;
			DoorEnviroTarget.HPMax = 1;
            pDoorTarget = pDoorTable->pDoor[Count];
            break;
         }
      }
   } else {
		if (argc > 1)
			strcpy(szSearch, argv[1]);
		for (Count=0; Count<pDoorTable->NumEntries; Count++) {
			if (((szSearch[0]==0) ||
				(!strnicmp(pDoorTable->pDoor[Count]->Name,szSearch,strlen(szSearch)))) &&
				((gZFilter >=10000.0f) ||
				((pDoorTable->pDoor[Count]->Z <= pChar->Z + gZFilter) &&
				(pDoorTable->pDoor[Count]->Z >= pChar->Z - gZFilter)))) {
				SPAWNINFO tSpawn;
				ZeroMemory(&tSpawn,sizeof(tSpawn));
				strcpy(tSpawn.Name,pDoorTable->pDoor[Count]->Name);
				tSpawn.Y=pDoorTable->pDoor[Count]->Y;
				tSpawn.X=pDoorTable->pDoor[Count]->X;
				tSpawn.Z=pDoorTable->pDoor[Count]->Z;
				tSpawn.Type = SPAWN_NPC;
				tSpawn.HPCurrent = 1;
				tSpawn.HPMax = 1;
				tSpawn.Heading=pDoorTable->pDoor[Count]->Heading;
				FLOAT Distance = DistanceToSpawn(pChar,&tSpawn);
				if (Distance<cDistance) {
				   CopyMemory(&DoorEnviroTarget,&tSpawn,sizeof(DoorEnviroTarget));
				   pDoorTarget = pDoorTable->pDoor[Count];
				   cDistance=Distance;
				}
			}
		}
	}


   if (DoorEnviroTarget.Name[0]!=0) {
      sprintf(szBuffer,"Door %d '%s' targeted.", pDoorTarget->ID, DoorEnviroTarget.Name);
      WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
   } else {
      WriteChatf("Couldn't find door to target.");
   }
   return 0;
} 

BOOL CALLBACK EnumWindowsProc(HWND hwnd,LPARAM lParam)
{
   DWORD procid = 0;
   GetWindowThreadProcessId(hwnd,&procid);
   if(procid==*(LPARAM *)lParam) {
      CHAR szClass[256] = {0};
      GetClassName(hwnd,szClass,255);
      if(!_stricmp(szClass,"_EverQuestwndclass")) {
         *(LPARAM *)lParam = (LPARAM)hwnd;
         return FALSE;
      }
   }
   return TRUE;
}
DWORD __stdcall openpickzonewnd(PVOID pData)
{
	if(!cmdPickZone)
		return 0;
	lockit lk(ghLockPickZone);
	int nInst = (int)pData;
	CHAR szInst[32] = { 0 };
	itoa(nInst, szInst, 10);
	if (PCHARINFO pCharInfo = GetCharInfo()) {
		cmdPickZone(pCharInfo->pSpawn, NULL);
		Sleep(2000);//i need to make this hardcoded wait dynamic but im in a hurry ill do it later -eqmule
		if (CXWnd *krwnd = FindMQ2Window("MIZoneSelectWnd")) {
			if (krwnd->dShow) {
				if (CListWnd *clist = (CListWnd*)krwnd->GetChildItem("MIZ_ZoneList")) {
					if (DWORD numitems = ((CSidlScreenWnd*)clist)->Items) {
						if (CButtonWnd *cbutt = (CButtonWnd*)krwnd->GetChildItem("MIZ_SelectButton")) {
							CHAR szOut[255] = { 0 };
							CXStr Str;
							std::string s;
							bool itsmain = false;
							bool clickit = false;
							for (DWORD i = 0; i<numitems; i++) {
								clist->GetItemText(&Str, i, 0);
								GetCXStr(Str.Ptr, szOut, 254);
								if (szOut[0] != '\0') {
									s = szOut;
									if (std::string::npos == s.find_first_of("123456789")) {
										itsmain = true;
									}
									if (itsmain && nInst == 0) {
										clickit = true;
									}
									else if (nInst >= 1) {
										if (std::string::npos != s.find_first_of(szInst)) {
											clickit = true;
										}
									}
									if (clickit) {
										SendListSelect("MIZoneSelectWnd", "MIZ_ZoneList", i);
										Sleep(500);
										SendWndClick2((CXWnd*)cbutt, "leftmouseup");
										WriteChatf("%s selected.", szOut);
										return 0;
									}
								}
							}
							WriteChatf("%s instance %d NOT found in list", GetFullZone(pCharInfo->zoneId), nInst);
						}
					}
				}
			}
		}
	}
	return 0;
}
// ***************************************************************************
// Function:    PickZoneCmd
// Description: '/pickzone' command
//              Adds the ability to do /pickzone #
// Usage:       /pickzone 2 will switch zone to number 2 pickzone 0 will pick main instance
// ***************************************************************************
//VOID PickZoneCmd(PSPAWNINFO pChar, PCHAR szLine)
int CMD_PickZone(int argc, char *argv[])
{
	if (!cmdPickZone) { 
		PCMDLIST pCmdListOrig = (PCMDLIST)EQADDR_CMDLIST; 
		for (int i=0;pCmdListOrig[i].fAddress != 0;i++) { 
			if (!strcmp(pCmdListOrig[i].szName,"/pickzone")) { 
				cmdPickZone = (fEQCommand)pCmdListOrig[i].fAddress; 
			} 
		} 
	} 
	if (!cmdPickZone)
	   return -1; 
	PCHAR szLine = NULL;
    if (argc > 1)
        szLine = argv[1];
	if (!szLine || (szLine && szLine[0]=='\0')) {
		WriteChatColor("Usage: /pickzone # where # is the instance number you want to pick");
		if (PCHARINFO pCharInfo = GetCharInfo()) {
			cmdPickZone(pCharInfo->pSpawn, szLine);
		}
		return 0;
	}
	else {
		DWORD index = atoi(szLine);
		DWORD nThreadID = 0;
		CreateThread(NULL, 0, openpickzonewnd, (PVOID)index, 0, &nThreadID);
	}
	return 0;
}
