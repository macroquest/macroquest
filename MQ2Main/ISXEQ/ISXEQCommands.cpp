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
EQLIB_API VOID Where                               (PSPAWNINFO,PCHAR);
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
   if(!stricmp(argv[1],"on") || !stricmp(argv[1],"off"))
   {
		CHAR szServerAndName[MAX_STRING] = {0};
		sprintf(szServerAndName,"%s.%s",((PCHARINFO)pCharData)->Server,((PCHARINFO)pCharData)->Name);
		WritePrivateProfileString(szServerAndName,"AutoRun",argv[1],gszINIFilename);
		sprintf(szServerAndName,"Set autorun to: '%s'",argv[1]);
		WriteChatColor(szServerAndName,USERCOLOR_DEFAULT);
   }
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