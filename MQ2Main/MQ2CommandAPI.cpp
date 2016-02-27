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
#ifndef ISXEQ


#include "MQ2Main.h"

CRITICAL_SECTION gCommandCS;

typedef struct _TIMEDCOMMAND
{
    ULONGLONG Time;
    CHAR Command[MAX_STRING];
    _TIMEDCOMMAND *pLast;
    _TIMEDCOMMAND *pNext;
} TIMEDCOMMAND, *PTIMEDCOMMAND;

PTIMEDCOMMAND pTimedCommands=0;

PMACROBLOCK GetWhileBlock(DWORD line)
{
	
	BOOL bFound = 0;
	PMACROBLOCK pblock = gMacroBlock;
	while(pblock && pblock->pPrev) {
		if (pblock->LineNumber==line) {
			bFound = 1;
			break;
		}
		pblock=pblock->pPrev;
	}
	if(line==1 && pblock && pblock->LineNumber==1) {
		return pblock;
	}
	if(!bFound) {
		FatalError("Bad while block pairing");
		return NULL;
	}
	return pblock->pPrev;
}
VOID HideDoCommand(PSPAWNINFO pChar, PCHAR szLine, BOOL delayed)
{
    if (delayed)
    {
		lockit lk(ghLockDelayCommand);
		PCHATBUF pChat = (PCHATBUF)LocalAlloc(LPTR,sizeof(CHATBUF));
        if (pChat) {
            strcpy_s(pChat->szText,szLine);
            pChat->pNext = NULL;
            if (!gDelayedCommands) {
                gDelayedCommands = pChat;
            } else {
                PCHATBUF pCurrent = 0;
                for (pCurrent = gDelayedCommands;pCurrent->pNext;pCurrent=pCurrent->pNext);
                pCurrent->pNext = pChat;
            }
        }
        return;
    }
    CAutoLock DoCommandLock(&gCommandCS);
	WeDidStuff();
    CHAR szCmd[MAX_STRING] = {0};
    CHAR szParam[MAX_STRING] = {0};
    CHAR szOriginalLine[MAX_STRING] = {0};

    strcpy_s(szOriginalLine,szLine);
    GetArg(szCmd,szLine,1);
    PALIAS pLoop = pAliases;
    while (pLoop) {
        if (!_stricmp(szCmd,pLoop->szName)) {
            sprintf(szLine,"%s%s",pLoop->szCommand,szOriginalLine+strlen(pLoop->szName));
            break;
        }
        pLoop = pLoop->pNext;
    }


    GetArg(szCmd,szLine,1);
    if (szCmd[0]==0)
		return;
    strcpy(szParam, GetNextArg(szLine));

    if ((szCmd[0]==':') || (szCmd[0]=='{')) {
        bRunNextCommand = TRUE;
        return;
    }
	if(gMacroBlock && gMacroBlock->LoopLine!=0) {
		//this is a command thats inside a while loop
		//so its time to loop back
		gMacroBlock = GetWhileBlock(gMacroBlock->LoopLine);
		if (szCmd[0]=='}') {
			bRunNextCommand = TRUE;
			return;
		}
	} else if (szCmd[0]=='}') {
		if (strstr(szLine,"{")) {
			GetArg(szCmd,szLine,2);
			if (stricmp(szCmd,"else")) {
				FatalError("} and { seen on the same line without an else present");
			}
			//          DebugSpew("DoCommand - handing {} off to FailIf");
			FailIf(pChar,"{",gMacroBlock,TRUE);
		} else {
			// handle this: 
			//            /if () {
			//            } else /echo stuff
			GetArg(szCmd,szLine,2);
			if (!_stricmp(szCmd,"else")) {
				// check here to fail this:
				//            /if () {
				//            } else 
				//                /echo stuff
				GetArg(szCmd,szLine,3);
				if (!_stricmp(szCmd,"")) {
					FatalError("no command or { following else");
				}
				bRunNextCommand = TRUE;
			} else {
				bRunNextCommand = TRUE;
			}
		}
		return;
    }
    if (szCmd[0]==';' || szCmd[0]=='[')
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
            if (pCommand->Parse && bAllowCommandParse)
            {
                pCommand->Function(pChar,ParseMacroParameter(pChar,szParam)); 
            } else {
                pCommand->Function(pChar,szParam);
			}
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
        CHAR szOrig[MAX_STRING] = {0};
        CHAR szSub[MAX_STRING] = {0};
        string szSubFullCommand = "";
        unsigned int k=0;
        bool OneCharacterSub = false;
        PALIAS pLoop = pAliases; 
        PSUB pSubLoop = pSubs;

        if (szFullLine[0]!=0) { 
            strcpy(szFullCommand,szFullLine); 
            GetArg(szCommand,szFullCommand,1); 

            if (!_stricmp(szCommand,"/camp"))
            {
                if (gMacroBlock)
                {
                    WriteChatColor("A macro is currently running.  You may wish to /endmacro before you finish camping.", CONCOLOR_YELLOW );
                }
            }

            szSubFullCommand = szFullCommand;
            for (unsigned int i=0; i < sizeof(szFullCommand); i++ ) 
            {
                if (szFullCommand[i] == '%') 
                {
                    if (szFullCommand[i+2] == ' ' || szFullCommand[i+2] == '\0' ||
                        !isalnum(szFullCommand[i+2]) ) {
                            if (szFullCommand[i+1] == 'm' || szFullCommand[i+1] == 'M' ||
                                szFullCommand[i+1] == 'o' || szFullCommand[i+1] == 'O' ||
                                szFullCommand[i+1] == 'p' || szFullCommand[i+1] == 'P' ||
                                szFullCommand[i+1] == 'r' || szFullCommand[i+1] == 'R' ||
                                szFullCommand[i+1] == 's' || szFullCommand[i+1] == 'S' ||
                                szFullCommand[i+1] == 't' || szFullCommand[i+1] == 'T' )
                                continue;
                            else { 
                                szOrig[0] = szFullCommand[i+1];
                                szOrig[1] = '\0';
                                k = 1;
                                OneCharacterSub = true;
                            }
                    }

                    if (!OneCharacterSub) {
                        for (unsigned int j=i+1; j < sizeof(szFullCommand); j++ )
                        {
                            if (szFullCommand[j] == ' ' || szFullCommand[j] == '\0' ) 
                                break;
                            else if (!isalnum(szFullCommand[j]))
                                break;
                            szOrig[k] = szFullCommand[j];
                            k++;
                        }
                    }
                    while (pSubLoop)
                    {
                        if (!_stricmp(szOrig, pSubLoop->szOrig)) 
                        {
                            sprintf( szSub, "%s", pSubLoop->szSub );
                            break;
                        }
                        pSubLoop = pSubLoop->pNext;
                    }
                    if (szSub[0] != '\0' ) {
                        szSubFullCommand.replace(i,k+1,szSub);
                        sprintf( szFullCommand, "%s",szSubFullCommand.c_str() ); 
                    }
                    szOrig[0] = '\0';
                    szSub[0] = '\0';
                    k=0;
                    OneCharacterSub = false;
                    pSubLoop = pSubs;
                }
            }
            sprintf(szFullCommand, "%s", szSubFullCommand.c_str() );

            while (pLoop) { 
                if (!_stricmp(szCommand,pLoop->szName)) { 
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
                    if (pCommand->Parse && bAllowCommandParse)
                        ParseMacroParameter(pChar,szArgs); 
                    if (pCommand->EQ)
                    {
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
        if (!_stricmp(ShortCommand,pAlias->szName))
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

void AddSubstitute(PCHAR Original, PCHAR Substitution)
{
    DebugSpew("AddSubstitute(%s,%s)",Original,Substitution);
    // perform insertion sort
    if (!pSubs)
    {
        PSUB pSub=new SUB;
        memset(pSub,0,sizeof(SUB));
        strcpy(pSub->szOrig,Original);
        strcpy(pSub->szSub,Substitution);
        pSubs=pSub;
        return;
    }
    PSUB pInsert=pSubs;
    PSUB pLast=0;
    while(pInsert)
    {
        int Pos=stricmp(Original,pInsert->szOrig);
        if (Pos<0)
        {
            // insert here.
            PSUB pSub=new SUB;
            memset(pSub,0,sizeof(SUB));
            strcpy(pSub->szOrig,Original);
            strcpy(pSub->szSub,Substitution);
            if (pLast)
                pLast->pNext=pSub;
            else
                pSubs=pSub;
            pSub->pLast=pLast;
            pInsert->pLast=pSub;
            pSub->pNext=pInsert;
            return;
        }
        if (Pos==0)
        {
            strcpy(pInsert->szOrig,Original);
            strcpy(pInsert->szSub,Substitution);
            return;
        }
        pLast=pInsert;
        pInsert=pInsert->pNext;
    }
    // End of list
    PSUB pSub=new SUB;
    memset(pSub,0,sizeof(SUB));
    strcpy(pSub->szOrig,Original);
    strcpy(pSub->szSub,Substitution);
    pLast->pNext=pSub;
    pSub->pLast=pLast;
}

BOOL RemoveSubstitute(PCHAR Original)
{
    PSUB pSub=pSubs;
    while(pSub)
    {
        if (!_stricmp(Original,pSub->szOrig))
        {
            if (pSub->pNext)
                pSub->pNext->pLast=pSub->pLast;
            if (pSub->pLast)
                pSub->pLast->pNext=pSub->pNext;
            else
                pSubs=pSub->pNext;
            delete pSub;
            return 1;
        }
        pSub=pSub->pNext;
    }
    return 0;
}

void InitializeMQ2Commands()
{
    int i;
    DebugSpew("Initializing Commands");
    InitializeCriticalSection(&gCommandCS);
    EzDetour(CEverQuest__InterpretCmd,&CCommandHook::Detour,&CCommandHook::Trampoline);

    // Import EQ commands
    PCMDLIST pCmdListOrig = (PCMDLIST)EQADDR_CMDLIST;
    for (i=0;pCmdListOrig[i].fAddress != 0;i++) {
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
        } else if (!strcmp(pCmdListOrig[i].szName,"/useitem")) {
            cmdUseItem = (fEQCommand)pCmdListOrig[i].fAddress;
        } else if (!strcmp(pCmdListOrig[i].szName,"/pet")) {
            cmdPet = (fEQCommand)pCmdListOrig[i].fAddress;
        } else if (!strcmp(pCmdListOrig[i].szName,"/mercswitch")) {
            cmdMercSwitch = (fEQCommand)pCmdListOrig[i].fAddress;
        } else if (!strcmp(pCmdListOrig[i].szName,"/advloot")) {
            cmdAdvLoot = (fEQCommand)pCmdListOrig[i].fAddress;
        } else if (!strcmp(pCmdListOrig[i].szName,"/pickzone")) {
            cmdPickZone = (fEQCommand)pCmdListOrig[i].fAddress;
        }
        AddCommand(pCmdListOrig[i].szName,pCmdListOrig[i].fAddress,TRUE,1,1);
    }    



    // Add MQ commands...
    struct _NEWCOMMANDLIST { PCHAR szCommand; fEQCommand pFunc; BOOL Parse; BOOL InGame;} NewCommands[] = {
        {"/who",        SuperWho,1,1},
        {"/whotarget",  SuperWhoTarget,1,1},
        {"/location",   Location,1,1},
        {"/help",       Help,1,0},
        {"/target",     Target,1,1},
        {"/alias",      Alias,0,0},
        {"/aa",         AltAbility,0,1},
        {"/substitute", Substitute,0,0},
        {"/filter",     Filter,1,0},
        {"/whofilter",  SWhoFilter,1,1},
        {"/spewfile",   DebugSpewFile,1,0},
        {"/char",       CharInfo,1,1},
        {"/face",       Face,1,1},
        {"/identify",   Identify,1,1},
        {"/where",      Where,1,1},
        {"/skills",     Skills,1,1},
        {"/unload",     Unload,1,0},
        {"/macro",      Macro,1,0},
        {"/buyitem",    BuyItem,1,1},
        {"/sellitem",   SellItem,1,1},
        {"/memspell",   MemSpell,1,1},
        {"/loadspells", LoadSpells,1,1},
        {"/loginname",  DisplayLoginName,1,0},
        {"/endmacro",   EndMacro,1,0},
        {"/listmacros", ListMacros,1,0},
        {"/echo",       Echo,1,0},
        {"/msgbox",     MQMsgBox,1,0},
        {"/lootall",    LootAll,1,0},
        {"/alert",      Alert,1,1},
        {"/click",      Click,1,0},
		{"/mouseto",    MouseTo,1,0},
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
        {"/declare",    NewDeclareVar,1,0},
        {"/deletevar",  NewDeleteVarCmd,1,0},
        {"/varcalc",    NewVarcalc,1,0},
        {"/varset",     NewVarset,1,0},
        {"/vardata",    NewVardata,1,0},
        {"/delay",      Delay,0,0}, // do not parse
        {"/cleanup",    Cleanup,1,0},
        {"/doevents",   DoEvents,1,0},
        {"/goto",       Goto,1,0},
        {"/for",        For,1,0},
        {"/next",       Next,1,0},
        {"/call",       Call,1,0},
        {"/return",     Return,1,0},
        {"/updateitems",UpdateItemInfo,1,1},
        {"/ini",        IniOutput,1,0},
        {"/dumpstack",  DumpStack,1,0},
        {"/setautorun", SetAutoRun,0,1},
        {"/banklist",   BankList,1,1},
        {"/look",       Look,1,1},
        {"/keepkeys",   KeepKeys,1,0},
        {"/windowstate",WindowState,1,0},
#ifndef ISXEQ_LEGACY
        {"/plugin",     PluginCommand,1,0},
#endif
        {"/destroy",    EQDestroyHeldItemOrMoney,1,1},
        {"/exec",       Exec,1,0}, 
        {"/keypress",   DoMappable,1,0},
        {"/popup",      PopupText,1,1},
		{"/popcustom",	PopupTextCustom,1,1},
		{"/popupecho",	PopupTextEcho,1,1},
        {"/multiline",  MultilineCommand,0,0},
#ifndef ISXEQ_LEGACY
        {"/bind",       MQ2KeyBindCommand,1,0},
#endif
        {"/ranged",     do_ranged,1,1},
        {"/loadcfg",    LoadCfgCommand,1,0},
        {"/dumpbinds",  DumpBindsCommand,1,0},
        {"/squelch",    SquelchCommand,1,0},
        {"/dosocial",   DoSocial,1,1},
        {"/docommand",  DoCommandCmd,1,0},
        {"/ctrlkey",    DoCtrlCmd,0,0},
        {"/altkey",     DoAltCmd,0,0},
        {"/shiftkey",   DoShiftCmd,0,0},
        {"/timed",      DoTimedCmd,0,0},
        {"/if",         NewIf,1,0},
        {"/while",      WhileCmd,1,0},
        {"/combine",    CombineCmd,1,1},
        {"/clearerrors",ClearErrorsCmd,1,0},
        {"/drop",       DropCmd,1,0},
        {"/hud",        HudCmd,1,0},
        {"/caption",    CaptionCmd,0,0},
        {"/captioncolor",CaptionColorCmd,1,0},
        {"/noparse",    NoParseCmd,0,0},
        {"/nomodkey",   NoModKeyCmd,0,0},
        {"/useitem",    UseItemCmd,1,1},
		{"/spellslotinfo",SpellSlotInfo,1,1},
		{"/getwintitle",GetWinTitle,1,0},
		{"/setwintitle",SetWinTitle,1,0},
		{"/removebuff", RemoveBuff,1,1},
		{"/removepetbuff", RemovePetBuff,1,1},
		{"/makemevisible",MakeMeVisible,0,1},
		{"/pet",        PetCmd,1,1},
		{"/mercswitch", MercSwitchCmd,1,1},
		{"/break",      Break,1,0},
		{"/continue",   Continue,1,0},
		{"/removeaura", RemoveAura,0,1},
		{"/advloot",    AdvLootCmd,1,1},
		{"/pickzone",   PickZoneCmd,1,1},
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
    AddAlias("/r","/reply");

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

    // Here is where you can add in permanent Substitutions
    AddSubstitute("omg","Oh My God");

    //Importing the User's Substitution List from .ini file
    CHAR SubsList[MAX_STRING*10] = {0};
    CHAR szBuffer2[MAX_STRING] = {0};
    sprintf(MainINI,"%s\\macroquest.ini",gszINIPath);
    GetPrivateProfileString("Substitutions",NULL,"",SubsList,MAX_STRING*10,MainINI);
    PCHAR pSubsList = SubsList;
    while (pSubsList[0]!=0) {
        GetPrivateProfileString("Substitutions",pSubsList,"",szBuffer2,MAX_STRING,MainINI);
        if (szBuffer[0]!=0) {
            AddSubstitute(pSubsList,szBuffer2);
        }
        pSubsList+=strlen(pSubsList)+1;
    }
}

void ShutdownMQ2Commands()
{
    EnterCriticalSection(&gCommandCS);
	lockit lk(ghLockDelayCommand);
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
        LocalFree(gDelayedCommands);
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
    while(pSubs)
    {
        PSUB pNext=pSubs->pNext;
        delete pSubs;
        pSubs=pNext;
    }

    LeaveCriticalSection(&gCommandCS);
    DeleteCriticalSection(&gCommandCS);
}

VOID DoTimedCommands()
{
	lockit lk(ghLockDelayCommand);
    ULONGLONG Now=MQGetTickCount64();
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
	lockit lk(ghLockDelayCommand);
    PTIMEDCOMMAND pNew= new TIMEDCOMMAND;
    pNew->Time=msDelay+MQGetTickCount64();
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
            break;
        }
        pLast=pNode;
        pNode=pNode->pNext;
    }
    pLast->pNext=pNew;
    pNew->pLast=pLast;
    pNew->pNext=pNode;
}

#endif
