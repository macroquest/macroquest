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

#if !defined(CINTERFACE)
#error /DCINTERFACE
#endif

#define DBG_SPEW


#include "MQ2Main.h"

CRITICAL_SECTION gCommandCS;

typedef struct _TIMEDCOMMAND
{
	DWORD Time;
	CHAR Command[MAX_STRING];
	_TIMEDCOMMAND *pLast;
	_TIMEDCOMMAND *pNext;
} TIMEDCOMMAND, *PTIMEDCOMMAND;

PTIMEDCOMMAND pTimedCommands=0;

VOID HideDoCommand(PSPAWNINFO pChar, PCHAR szLine, BOOL delayed)
{
	if (delayed)
	{
		PCHATBUF pChat = (PCHATBUF)malloc(sizeof(CHATBUF));
		if (pChat) {
			strcpy(pChat->szText,szLine);
			pChat->pNext = NULL;
			if (!gDelayedCommands) {
				gDelayedCommands = pChat;
			} else {
				PCHATBUF pCurrent;
				for (pCurrent = gDelayedCommands;pCurrent->pNext;pCurrent=pCurrent->pNext);
				pCurrent->pNext = pChat;
			}
		}
		return;
	}
    CAutoLock DoCommandLock(&gCommandCS);
    CHAR szCmd[MAX_STRING] = {0};
    CHAR szParam[MAX_STRING] = {0};
    CHAR szOriginalLine[MAX_STRING] = {0};

    strcpy(szOriginalLine,szLine);
    GetArg(szCmd,szLine,1);
    PALIAS pLoop = pAliases;
    while (pLoop) {
        if (!stricmp(szCmd,pLoop->szName)) {
            sprintf(szLine,"%s%s",pLoop->szCommand,szOriginalLine+strlen(pLoop->szName));
			break;
        }
        pLoop = pLoop->pNext;
    }


	GetArg(szCmd,szLine,1);
    if (szCmd[0]==0) return;
    strcpy(szParam, GetNextArg(szLine));

    if ((szCmd[0]==':') || (szCmd[0]=='{')) {
        bRunNextCommand = TRUE;
        return;
    }

    if (szCmd[0]=='}') {
        if (strstr(szLine,"{")) {
			GetArg(szCmd,szLine,2);
			if (stricmp(szCmd,"else")) {
				FatalError("} and { seen on the same line without an else present");
			}
  //          DebugSpew("DoCommand - handing {} off to FailIf");
            FailIf(pChar,"{",gMacroBlock,TRUE);
        } else {
//            DebugSpew("DoCommand - } seen");
            bRunNextCommand = TRUE;
        }
        return;
    }
	if (szCmd[0]==';')
	{
		pEverQuest->InterpretCmd((EQPlayer*)pChar,szOriginalLine);
		return;
	}



	PMQCOMMAND pCommand=pCommands;
	while(pCommand)
	{
		if (pCommand->InGameOnly && gGameState!=GAMESTATE_INGAME)
		{
			pCommand=pCommand->pNext;
			continue;
		}
		int Pos=strnicmp(szCmd,pCommand->Command,strlen(szCmd));
		if (Pos<0)
		{// command not found
			break;
		}
		if (Pos==0)
		{
			if (pCommand->Parse)
			{
				pCommand->Function(pChar,ParseMacroParameter(pChar,szParam)); 
			}
			else
				pCommand->Function(pChar,szParam);
			strcpy(szLastCommand,szOriginalLine);
			return;
		}
		pCommand=pCommand->pNext;
	}
    if (!strnicmp(szOriginalLine,"sub ",4)) {
		FatalError("Flow ran into another subroutine.");
        return;
    }

	strcpy(szLastCommand,szOriginalLine);
    MacroError("DoCommand - Couldn't parse '%s'",szOriginalLine);
}


class CCommandHook 
{ 
public: 
	VOID Detour(PSPAWNINFO pChar, PCHAR szFullLine) 
	{ 
		DebugSpew("CCommandHook::Detour(%s)",szFullLine);
		CHAR szFullCommand[MAX_STRING] = {0}; 
		CHAR szCommand[MAX_STRING] = {0}; 
		CHAR szArgs[MAX_STRING] = {0}; 

		PALIAS pLoop = pAliases; 
		if (szFullLine[0]!=0) { 
			strcpy(szFullCommand,szFullLine); 
			GetArg(szCommand,szFullCommand,1); 
			while (pLoop) { 
				if (!stricmp(szCommand,pLoop->szName)) { 
					sprintf(szCommand,"%s%s",pLoop->szCommand,szFullCommand+strlen(pLoop->szName)); 
					strncpy(szFullCommand,szCommand,MAX_STRING); 
					break;
				} 
				pLoop = pLoop->pNext; 
			} 
			GetArg(szCommand,szFullCommand,1); 
			strcpy(szArgs, GetNextArg(szFullCommand)); 


			PMQCOMMAND pCommand=pCommands;
			while(pCommand)
			{
				if (pCommand->InGameOnly && gGameState!=GAMESTATE_INGAME)
				{
					pCommand=pCommand->pNext;
					continue;
				}
				int Pos=strnicmp(szCommand,pCommand->Command,strlen(szCommand));
				if (Pos<0)
				{// command not found
					break;
				}
				if (Pos==0)
				{
					if (pCommand->Parse)
						ParseMacroParameter(pChar,szArgs); 
					if (pCommand->EQ)
					{
//						DebugSpew("pCommand->EQ");
						strcat(szCommand," "); 
						strcat(szCommand,szArgs); 
						Trampoline(pChar,szCommand); 
					}
					else
					{
						pCommand->Function(pChar,szArgs);
					}
					strcpy(szLastCommand,szFullCommand);
					return;
				}
				pCommand=pCommand->pNext;
			}
		}
		Trampoline(pChar,szFullLine); 
		strcpy(szLastCommand,szFullCommand);
	} 

	VOID Trampoline(PSPAWNINFO pChar, PCHAR szFullLine); 

}; 

DETOUR_TRAMPOLINE_EMPTY(VOID CCommandHook::Trampoline(PSPAWNINFO pChar, PCHAR szFullLine)); 


void AddCommand(PCHAR Command, fEQCommand Function, BOOL EQ, BOOL Parse, BOOL InGame)
{
	DebugSpew("AddCommand(%s,0x%X)",Command,Function);
	PMQCOMMAND pCommand=new MQCOMMAND;
	memset(pCommand,0,sizeof(MQCOMMAND));
	strncpy(pCommand->Command,Command,63);
	pCommand->EQ=EQ;
	pCommand->Parse=Parse;
	pCommand->Function=Function;
	pCommand->InGameOnly=InGame;
	
	// perform insertion sort
	if (!pCommands)
	{
		pCommands=pCommand;
		return;
	}
	PMQCOMMAND pInsert=pCommands;
	PMQCOMMAND pLast=0;
	while(pInsert)
	{
		if (stricmp(pCommand->Command,pInsert->Command)<=0)
		{
			// insert here.
			if (pLast)
				pLast->pNext=pCommand;
			else
				pCommands=pCommand;
			pCommand->pLast=pLast;
			pInsert->pLast=pCommand;
			pCommand->pNext=pInsert;
			return;
		}
		pLast=pInsert;
		pInsert=pInsert->pNext;
	}
	// End of list
	pLast->pNext=pCommand;
	pCommand->pLast=pLast;
}

BOOL RemoveCommand(PCHAR Command)
{
	PMQCOMMAND pCommand=pCommands;
	while(pCommand)
	{
		int Pos=strnicmp(Command,pCommand->Command,63);
		if (Pos<0)
		{
			DebugSpew("RemoveCommand: Command not found '%s'",Command);
			return 0;
		}
		if (Pos==0)
		{
			if (pCommand->pNext)
				pCommand->pNext->pLast=pCommand->pLast;
			if (pCommand->pLast)
				pCommand->pLast->pNext=pCommand->pNext;
			else
				pCommands=pCommand->pNext;
			delete pCommand;
			return 1;
		}
		pCommand=pCommand->pNext;
	}
	return 0;
}

void AddAlias(PCHAR ShortCommand, PCHAR LongCommand)
{
	DebugSpew("AddAlias(%s,%s)",ShortCommand,LongCommand);
	// perform insertion sort
	if (!pAliases)
	{
		PALIAS pAlias=new ALIAS;
		memset(pAlias,0,sizeof(ALIAS));
		strcpy(pAlias->szName,ShortCommand);
		strcpy(pAlias->szCommand,LongCommand);
		pAliases=pAlias;
		return;
	}
	PALIAS pInsert=pAliases;
	PALIAS pLast=0;
	while(pInsert)
	{
		int Pos=stricmp(ShortCommand,pInsert->szName);
		if (Pos<0)
		{
			// insert here.
			PALIAS pAlias=new ALIAS;
			memset(pAlias,0,sizeof(ALIAS));
			strcpy(pAlias->szName,ShortCommand);
			strcpy(pAlias->szCommand,LongCommand);
			if (pLast)
				pLast->pNext=pAlias;
			else
				pAliases=pAlias;
			pAlias->pLast=pLast;
			pInsert->pLast=pAlias;
			pAlias->pNext=pInsert;
			return;
		}
		if (Pos==0)
		{
			strcpy(pInsert->szName,ShortCommand);
			strcpy(pInsert->szCommand,LongCommand);
			return;
		}
		pLast=pInsert;
		pInsert=pInsert->pNext;
	}
	// End of list
	PALIAS pAlias=new ALIAS;
	memset(pAlias,0,sizeof(ALIAS));
	strcpy(pAlias->szName,ShortCommand);
	strcpy(pAlias->szCommand,LongCommand);
	pLast->pNext=pAlias;
	pAlias->pLast=pLast;
}

BOOL RemoveAlias(PCHAR ShortCommand)
{
	PALIAS pAlias=pAliases;
	while(pAlias)
	{
		if (!stricmp(ShortCommand,pAlias->szName))
		{
			if (pAlias->pNext)
				pAlias->pNext->pLast=pAlias->pLast;
			if (pAlias->pLast)
				pAlias->pLast->pNext=pAlias->pNext;
			else
				pAliases=pAlias->pNext;
			delete pAlias;
			return 1;
		}
		pAlias=pAlias->pNext;
	}
	return 0;
}

void InitializeMQ2Commands()
{
	DebugSpew("Initializing Commands");
	InitializeCriticalSection(&gCommandCS);
//	EasyClassDetour(CEverQuest__InterpretCmd,CCommandHook,Detour,VOID,(PSPAWNINFO pChar, PCHAR szFullLine),Trampoline);
	EzDetour(CEverQuest__InterpretCmd,CCommandHook::Detour,CCommandHook::Trampoline);

	// Import EQ commands
    PCMDLIST pCmdListOrig = (PCMDLIST)EQADDR_CMDLIST;
    for (int i=0;pCmdListOrig[i].fAddress != 0;i++) {
        if (!strcmp(pCmdListOrig[i].szName,"/who")) {
            cmdWho  = (fEQCommand)pCmdListOrig[i].fAddress;
			AddCommand("/",pCmdListOrig[i].fAddress,TRUE,1,1); // make sure / does EQ who by default
        } else if (!strcmp(pCmdListOrig[i].szName,"/whotarget")) {
            cmdWhoTarget  = (fEQCommand)pCmdListOrig[i].fAddress;
        } else if (!strcmp(pCmdListOrig[i].szName,"/location")) {
            cmdLocation  = (fEQCommand)pCmdListOrig[i].fAddress;
        } else if (!strcmp(pCmdListOrig[i].szName,"/help")) {
            cmdHelp = (fEQCommand)pCmdListOrig[i].fAddress;
        } else if (!strcmp(pCmdListOrig[i].szName,"/target")) {
            cmdTarget = (fEQCommand)pCmdListOrig[i].fAddress;
        } else if (!strcmp(pCmdListOrig[i].szName,"/charinfo")) {
            cmdCharInfo = (fEQCommand)pCmdListOrig[i].fAddress;
        } else if (!strcmp(pCmdListOrig[i].szName,"/filter")) {
            cmdFilter = (fEQCommand)pCmdListOrig[i].fAddress;
        } else if (!strcmp(pCmdListOrig[i].szName,"/doability")) {
            cmdDoAbility = (fEQCommand)pCmdListOrig[i].fAddress;
        } else if (!strcmp(pCmdListOrig[i].szName,"/cast")) {
            cmdCast = (fEQCommand)pCmdListOrig[i].fAddress;
        }
		AddCommand(pCmdListOrig[i].szName,pCmdListOrig[i].fAddress,TRUE,1,1);
	}	

	

	// Add MQ commands...
    struct _NEWCOMMANDLIST { PCHAR szCommand; fEQCommand pFunc; BOOL Parse; BOOL InGame;} NewCommands[] = {
        {"/who",        SuperWho,		1,	1},
        {"/whotarget",  SuperWhoTarget,	1,	1},
        {"/location",   Location,1,1},
        {"/help",       Help,1,0},
        {"/target",     Target,1,1},
        {"/alias",      Alias,0,0},
        {"/filter",     Filter,1,0},
		{"/whofilter",	SWhoFilter,1,1},
        {"/spewfile",   DebugSpewFile,1,0},
        {"/charinfo",   CharInfo,1,1},
        {"/face",       Face,1,1},
        {"/identify",   Identify,1,1},
        {"/where",      Where,1,1},
        {"/skills",     Skills,1,1},
        {"/unload",     Unload,1,0},
        {"/macro",      Macro,1,0},
//        {"/selectitem", SelectItem,1,1},
        {"/buyitem",    BuyItem,1,1},
        {"/sellitem",   SellItem,1,1},
        {"/memspell",   MemSpell,1,1},
        {"/loadspells", LoadSpells,1,1},
		{"/loginname",  DisplayLoginName,1,0},
        {"/endmacro",   EndMacro,1,0},
        {"/listmacros", ListMacros,1,0},
        {"/echo",       Echo,1,0},
        {"/msgbox",     MQMsgBox,1,0},
        {"/alert",      Alert,1,1},
        {"/click",      Click,1,0},
        {"/mouseto",    MouseTo,1,0},
//        {"/finditem",   FindItem,1,1},
        {"/mqpause",    MacroPause,1,0},
        {"/items",      Items,1,1},
        {"/itemtarget", ItemTarget,1,1},
        {"/doability",  DoAbility,1,1},
        {"/doors",      Doors,1,1},
        {"/doortarget", DoorTarget,1,1},
        {"/beep",       MacroBeep,1,0},
        {"/cast",       Cast,1,1},
        {"/mqlog",      MacroLog,1,0},
        {"/seterror",   SetError,1,0},
#ifndef USEMQ2DATAVARS
		{"/varset",     VarSet,1,0},
        {"/varcalc",    VarCalc,1,0},
        {"/varadd",     MyVarAdd,1,0},
        {"/varcat",     MyVarCat,1,0},
        {"/varsub",     MyVarSub,1,0},
        {"/varand",     MyVarAnd,1,0},
        {"/varor",      MyVarOr,1,0},
        {"/varrshift",  VarRShift,1,0},
        {"/varlshift",  VarLShift,1,0},
		{"/deletevar",  DeleteVarCmd,1,0},
        {"/declare",    DeclareVar,1,0},
        {"/zapvars",    ZapVars,1,0},
#else
		{"/declare",    NewDeclareVar,1,0},
		{"/deletevar",  NewDeleteVarCmd,1,0},
		{"/varcalc",	NewVarcalc,1,0},
		{"/varset",     NewVarset,1,0},
		{"/vardata",	NewVardata,1,0},
#endif
//        {"/press",      Press,1,0},
//        {"/sendkey",    SendKey,1,0},
        {"/delay",      Delay,1,0},
        {"/cleanup",    Cleanup,1,0},
        {"/doevents",   DoEvents,1,0},
        {"/goto",       Goto,1,0},
        {"/for",        For,1,0},
        {"/next",       Next,1,0},
        {"/call",       Call,1,0},
        {"/return",     Return,1,0},
        {"/updateitems",UpdateItemInfo,1,1},
		{"/ini",        IniOutput,1,0},
		{"/dumpstack",    DumpStack,1,0},
        {"/setautorun", SetAutoRun,0,1},
        {"/banklist",   BankList,1,1},
        {"/look",       Look,1,1},
        {"/keepkeys",   KeepKeys,1,0},
		{"/windowstate", WindowState,1,0},
		{"/plugin",     PluginCommand,1,0},
		{"/destroy",     EQDestroyHeldItemOrMoney,1,1},
		{"/exec",      Exec,1,0}, 
		{"/keypress",   DoMappable,1,0},
        {"/popup",      PopupText,1,1},
		{"/multiline",  MultilineCommand,0,0},
		{"/bind",       MQ2KeyBindCommand,1,0},
		{"/ranged",		do_ranged,1,1},
		{"/loadcfg",	LoadCfgCommand,1,0},
		{"/dumpbinds",	DumpBindsCommand,1,0},
		{"/squelch",	SquelchCommand,1,0},
		{"/dosocial",   DoSocial,1,1},
		{"/docommand",  DoCommandCmd,1,0},
		{"/ctrlkey",	DoCtrlCmd,0,0},
		{"/altkey",		DoAltCmd,0,0},
		{"/shiftkey",   DoShiftCmd,0,0},
		{"/timed",		DoTimedCmd,0,0},
		{"/if",			NewIf,1,0},
		{"/combine",    CombineCmd,1,1},
		{"/clearerrors", ClearErrorsCmd,1,0},
		{"/drop",		DropCmd,1,0},
		{NULL,          NULL,0,1},
    };

	// Remove replaced commands first
	for (i = 0 ; NewCommands[i].szCommand && NewCommands[i].pFunc ; i++)
	{
		RemoveCommand(NewCommands[i].szCommand);
		AddCommand(NewCommands[i].szCommand,NewCommands[i].pFunc,0,NewCommands[i].Parse,NewCommands[i].InGame);
	}

	/* ALIASES FOR OUT OF ORDER SHORTHAND COMMANDS */
	AddAlias("/d","/duel");
	AddAlias("/t","/tell");
	AddAlias("/w","/who");
	AddAlias("/a","/anonymous");
	AddAlias("/ta","/tap");
	AddAlias("/c","/consider");
	AddAlias("/cha","/channel");
	AddAlias("/f","/feedback");
	AddAlias("/fa","/fastdrop");
	AddAlias("/m","/msg");
	AddAlias("/load","/loadspells");
	AddAlias("/b","/bazaar");
	AddAlias("/ba","/bazaar");
	AddAlias("/g","/gsay");
	AddAlias("/gu","/guildsay");
	AddAlias("/key","/keys");

	AddAlias("/newif","/if");
	/* NOW IMPORT THE USER'S ALIAS LIST, THEIR MODIFICATIONS OVERRIDE EXISTING. */

	CHAR AliasList[MAX_STRING*10] = {0};
    CHAR szBuffer[MAX_STRING] = {0};
    CHAR MainINI[MAX_STRING] = {0};
    sprintf(MainINI,"%s\\macroquest.ini",gszINIPath);
	GetPrivateProfileString("Aliases",NULL,"",AliasList,MAX_STRING*10,MainINI);
    PCHAR pAliasList = AliasList;
    while (pAliasList[0]!=0) {
        GetPrivateProfileString("Aliases",pAliasList,"",szBuffer,MAX_STRING,MainINI);
        if (szBuffer[0]!=0) {
			AddAlias(pAliasList,szBuffer);
        }
        pAliasList+=strlen(pAliasList)+1;
    }
}

void ShutdownMQ2Commands()
{
	EnterCriticalSection(&gCommandCS);
	RemoveDetour(CEverQuest__InterpretCmd);
	while(pCommands)
	{
		PMQCOMMAND pNext=pCommands->pNext;
		delete pCommands;
		pCommands=pNext;
	}
	while(gDelayedCommands)
	{
		PCHATBUF pNext=gDelayedCommands->pNext;
		free(gDelayedCommands);
		gDelayedCommands=pNext;
	}
	while(pTimedCommands)
	{
		PTIMEDCOMMAND pNext=pTimedCommands->pNext;
		delete pTimedCommands;
		pTimedCommands=pNext;
	}
	while(pAliases)
	{
		PALIAS pNext=pAliases->pNext;
		delete pAliases;
		pAliases=pNext;
	}

	LeaveCriticalSection(&gCommandCS);
	DeleteCriticalSection(&gCommandCS);
}

VOID DoTimedCommands()
{
	DWORD Now=GetTickCount();
	while(pTimedCommands && pTimedCommands->Time<=Now)
	{
		PTIMEDCOMMAND pNext=pTimedCommands->pNext;
		DoCommand(((PCHARINFO)pCharData)->pSpawn,pTimedCommands->Command);
		delete pTimedCommands;
		pTimedCommands=pNext;
	}
}

VOID TimedCommand(PCHAR Command, DWORD msDelay)
{
	PTIMEDCOMMAND pNew= new TIMEDCOMMAND;
	pNew->Time=msDelay+GetTickCount();
	strcpy(pNew->Command,Command);
	
	// insert into list

	if (!pTimedCommands || pTimedCommands->Time>=pNew->Time)
	{
		pNew->pNext=pTimedCommands;
		pNew->pLast=0;
		pTimedCommands=pNew;
		return;
	}

	PTIMEDCOMMAND pLast=pTimedCommands;
	PTIMEDCOMMAND pNode=pTimedCommands->pNext;
	while(pNode)
	{
		if (pNew->Time<=pNode->Time)
		{
			pNode->pLast=pNew;
			break;
		}
		pLast=pNode;
		pNode=pNode->pNext;
	}
	pLast->pNext=pNew;
	pNew->pLast=pLast;
	pNew->pNext=pNode;
}

