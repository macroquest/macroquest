/*****************************************************************************
    eqlib.dll: MacroQuest's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic

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

PALIAS pAliases=0;
PMQCOMMAND pCommands=0;
CRITICAL_SECTION gCommandCS;



VOID DoCommand(PSPAWNINFO pChar, PCHAR szLine)
{
    CAutoLock DoCommandLock(&gCommandCS);
    CHAR szCmd[MAX_STRING] = {0};
    CHAR szParam[MAX_STRING] = {0};
    CHAR szOriginalLine[MAX_STRING] = {0};

    strcpy(szOriginalLine,szLine);
    GetArg(szCmd,szLine,1);
    PALIAS pLoop = pAliases;
    while (pLoop) {
        if (!strnicmp(szCmd,pLoop->szName,strlen(pLoop->szName)+1)) {
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
				GracefullyEndBadMacro(pChar,gMacroBlock,"} and { seen on the same line without an else present");
			}
            DebugSpew("DoCommand - handing {} off to FailIf");
            FailIf(pChar,"{",gMacroBlock,TRUE);
        } else {
            DebugSpew("DoCommand - } seen");
            bRunNextCommand = TRUE;
        }
        return;
    }



	PMQCOMMAND pCommand=pCommands;
	while(pCommand)
	{
		int Pos=strnicmp(szCmd,pCommand->Command,strlen(szCmd));
		if (Pos<0)
		{// command not found
			break;
		}
		if (Pos==0)
		{
			if (pCommand->Parse)
				pCommand->Function(pChar,ParseMacroParameter(pChar,szParam)); 
			else
				pCommand->Function(pChar,szParam);
			return;
		}
		pCommand=pCommand->pNext;
	}
    if (!strnicmp(szOriginalLine,"sub ",4)) {
        GracefullyEndBadMacro(pChar,gMacroBlock,"Flow ran into another subroutine.");
        return;
    }

    sprintf(szCmd,"Couldn't parse '%s'",szOriginalLine);
    DebugSpew("DoCommand - Bad command: %s",szCmd);
    WriteChatColor(szCmd,CONCOLOR_RED);
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
				if (!strnicmp(szCommand,pLoop->szName,strlen(pLoop->szName)+1)) { 
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
					return;
				}
				pCommand=pCommand->pNext;
			}
		}
		Trampoline(pChar,szFullLine); 
	} 

	VOID Trampoline(PSPAWNINFO pChar, PCHAR szFullLine); 

}; 

DETOUR_TRAMPOLINE_EMPTY(VOID CCommandHook::Trampoline(PSPAWNINFO pChar, PCHAR szFullLine)); 


void AddCommand(PCHAR Command, fEQCommand Function, BOOL EQ, BOOL Parse)
{
	DebugSpew("AddCommand(%s,0x%X)",Command,Function);
	PMQCOMMAND pCommand=new MQCOMMAND;
	memset(pCommand,0,sizeof(MQCOMMAND));
	strncpy(pCommand->Command,Command,63);
	pCommand->EQ=EQ;
	pCommand->Parse=Parse;
	pCommand->Function=Function;
	
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

	VOID (CCommandHook::*pfDetour)(PSPAWNINFO pChar, PCHAR szFullLine)=CCommandHook::Detour;
	VOID (CCommandHook::*pfTrampoline)(PSPAWNINFO pChar, PCHAR szFullLine)=CCommandHook::Trampoline;

	AddDetour(CEverQuest__InterpretCmd,*(PBYTE*)&pfDetour,*(PBYTE*)&pfTrampoline);

	// Import EQ commands
    PCMDLIST pCmdListOrig = (PCMDLIST)EQADDR_CMDLIST;
    for (int i=0;pCmdListOrig[i].fAddress != 0;i++) {
        if (!strcmp(pCmdListOrig[i].szName,"/who")) {
            cmdWho  = (fEQCommand)pCmdListOrig[i].fAddress;
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
        } else if (!strcmp(pCmdListOrig[i].szName,"/who")) {
			AddCommand("/",pCmdListOrig[i].fAddress,TRUE); // make sure / does EQ who by default
        }
		AddCommand(pCmdListOrig[i].szName,pCmdListOrig[i].fAddress,TRUE);
	}	

	

	// Add MQ commands...
    struct _NEWCOMMANDLIST { PCHAR szCommand; fEQCommand pFunc; BOOL Parse;} NewCommands[] = {
        {"/who",        SuperWho,		1},
        {"/whotarget",  SuperWhoTarget,	1},
        {"/location",   Location,1},
        {"/help",       Help,1},
        {"/target",     Target,1},
        {"/alias",      Alias,0},
        {"/hotkey",     Hotkey,0},
        {"/filter",     Filter,1},
		{"/whofilter",	SWhoFilter,1},
        {"/spewfile",   DebugSpewFile,1},
        {"/charinfo",   CharInfo,1},
        {"/face",       Face,1},
        {"/identify",   Identify,1},
        {"/where",      Where,1},
        {"/skills",     Skills,1},
        {"/unload",     Unload,1},
        {"/macro",      Macro,1},
        {"/selectitem", SelectItem,1},
        {"/buyitem",    BuyItem,1},
        {"/sellitem",   SellItem,1},
        {"/memspell",   MemSpell,1},
        {"/loadspells", LoadSpells,1},
		{"/loginname",  DisplayLoginName,1},
        {"/endmacro",   EndMacro,1},
        {"/listmacros", ListMacros,1},
        {"/echo",       Echo,1},
        {"/varset",     VarSet,1},
        {"/msgbox",     MQMsgBox,1},
        {"/alert",      Alert,1},
        {"/click",      Click,1},
        {"/mouseto",    MouseTo,1},
        {"/finditem",   FindItem,1},
        {"/mqpause",    MacroPause,1},
        {"/items",      Items,1},
        {"/itemtarget", ItemTarget,1},
        {"/doability",  DoAbility,1},
        {"/doors",      Doors,1},
        {"/doortarget", DoorTarget,1},
        {"/beep",       MacroBeep,1},
        {"/cast",       Cast,1},
        {"/mqlog",      MacroLog,1},
        {"/seterror",   SetError,1},
        {"/varcalc",    VarCalc,1},
        {"/varadd",     MyVarAdd,1},
        {"/varcat",     MyVarCat,1},
        {"/varsub",     MyVarSub,1},
        {"/varand",     MyVarAnd,1},
        {"/varor",      MyVarOr,1},
        {"/varrshift",  VarRShift,1},
        {"/varlshift",  VarLShift,1},
        {"/press",      Press,1},
        {"/sendkey",    SendKey,1},
        {"/delay",      Delay,1},
        {"/cleanup",    Cleanup,1},
        {"/doevents",   DoEvents,1},
        {"/zapvars",    ZapVars,1},
        {"/declare",    DeclareVar,1},
        {"/if",         If,1},
        {"/goto",       Goto,1},
        {"/for",        For,1},
        {"/next",       Next,1},
        {"/call",       Call,1},
        {"/return",     Return,1},
        {"/updateitems",UpdateItemInfo,1},
		{"/ini",        IniOutput,1},
		{"/dumpstack",    DumpStack,1},
		{"/zem",      DisplayZem,1},                  //2003-05-17 anOrcPawn00
        {"/setautorun", SetAutoRun,0},
        {"/mouseclickl",    MouseClickL,1},
        {"/mouseclickr",    MouseClickR,1},
        {"/banklist",   BankList,1},
        {"/look",       Look,1},
        {"/keepkeys",   KeepKeys,1},
		{"/windowstate", WindowState,1},
        {"/editmacro",  EditMacro,1},
		{"/plugin",     PluginCommand,1},
		{"/destroy",     EQDestroyHeldItemOrMoney,1},
        {NULL,          NULL,0}
    };

	// Remove replaced commands first
	for (i = 0 ; NewCommands[i].szCommand && NewCommands[i].pFunc ; i++)
	{
		RemoveCommand(NewCommands[i].szCommand);
		AddCommand(NewCommands[i].szCommand,NewCommands[i].pFunc,0,NewCommands[i].Parse);
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
	while(pAliases)
	{
		PALIAS pNext=pAliases->pNext;
		delete pAliases;
		pAliases=pNext;
	}

	LeaveCriticalSection(&gCommandCS);
	DeleteCriticalSection(&gCommandCS);
}

