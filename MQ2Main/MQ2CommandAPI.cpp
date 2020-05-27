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


VOID HideDoCommand(PSPAWNINFO pChar, PCHAR szLine, BOOL delayed)
{
	if (!pChar)
		return;
    if (delayed)
    {
		lockit lk(ghLockDelayCommand,"HideDoCommand");
		CHAR szTheCmd[MAX_STRING];
		strcpy_s(szTheCmd, szLine);
		PCHATBUF pChat = 0;
		try {
			pChat = new CHATBUF;
			strcpy_s(pChat->szText,szTheCmd);
            pChat->pNext = 0;
            if (!gDelayedCommands) {
                gDelayedCommands = pChat;
            } else {
                PCHATBUF pCurrent = 0;
                for (pCurrent = gDelayedCommands;pCurrent->pNext;pCurrent=pCurrent->pNext);
                pCurrent->pNext = pChat;
            }
		}
		catch(std::bad_alloc& exc)
		{
			UNREFERENCED_PARAMETER(exc);
			MessageBox(NULL,"HideDoCommand failed to allocate memory for gDelayedCommands","Did we just discover a memory leak?",MB_SYSTEMMODAL|MB_OK);
		};
        return;
    }
    CAutoLock DoCommandLock(&gCommandCS);
	CHAR szTheCmd[MAX_STRING];
	strcpy_s(szTheCmd, szLine);
	WeDidStuff();
    CHAR szOriginalLine[MAX_STRING];
    strcpy_s(szOriginalLine,szTheCmd);
	CHAR szArg1[MAX_STRING];
	GetArg(szArg1,szTheCmd,1);
	std::string sName = szArg1;
	std::transform(sName.begin(), sName.end(), sName.begin(), tolower);
	if (mAliases.find(sName) != mAliases.end()) {
		sprintf_s(szTheCmd, "%s%s", mAliases[sName].c_str(), szOriginalLine + sName.size());
	}

    GetArg(szArg1,szTheCmd,1);
    if (szArg1[0]==0)
		return;
	CHAR szParam[MAX_STRING];
	strcpy_s(szParam, GetNextArg(szTheCmd));

    if ((szArg1[0]==':') || (szArg1[0]=='{')) {
        bRunNextCommand = TRUE;
        return;
    }

	PMACROBLOCK pBlock = GetCurrentMacroBlock();
	if (szArg1[0]=='}') {
		if (pBlock && pBlock->Line[pBlock->CurrIndex].LoopStart != 0) {
			pBlock->CurrIndex = pBlock->Line[pBlock->CurrIndex].LoopStart;
			extern void pop_loop();
			pop_loop();
			return;
		}
		if (strstr(szTheCmd,"{")) {
			GetArg(szArg1,szTheCmd,2);
			if (_stricmp(szArg1,"else")) {
				FatalError("} and { seen on the same line without an else present");
			}
			//          DebugSpew("DoCommand - handing {} off to FailIf");
			if(pBlock)
				FailIf(pChar,"{",pBlock->CurrIndex,TRUE);
		} else {
			// handle this: 
			//            /if () {
			//            } else /echo stuff
			GetArg(szArg1,szTheCmd,2);
			if (!_stricmp(szArg1,"else")) {
				// check here to fail this:
				//            /if () {
				//            } else 
				//                /echo stuff
				GetArg(szArg1,szTheCmd,3);
				if (!_stricmp(szArg1,"")) {
					FatalError("no command or { following else");
				}
				bRunNextCommand = TRUE;
			} else {
				bRunNextCommand = TRUE;
			}
		}
		return;
    }
    if (szArg1[0]==';' || szArg1[0]=='[')
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
        int Pos=_strnicmp(szArg1,pCommand->Command,strlen(szArg1));
        if (Pos<0)
        {// command not found
            break;
        }
        if (Pos==0)
        {
        	//                      the parser version is 2 or It's not version 2 and we're allowing command parses
			if (pCommand->Parse && (gdwParserEngineVer == 2 || (gdwParserEngineVer != 2 && bAllowCommandParse)))
            {
                pCommand->Function(pChar,ParseMacroParameter(pChar,szParam)); 
            }
			else {
                pCommand->Function(pChar,szParam);
			}
            strcpy_s(szLastCommand,szOriginalLine);
            return;
        }
        pCommand=pCommand->pNext;
    }
    PBINDLIST pBind = pBindList;
    while( pBind )
    {
        if( gGameState != GAMESTATE_INGAME )
        {
            // Macro Binds only supported in-game
            pBind = pBind->pNext;
            continue;
        }

        int Pos = _strnicmp( szArg1, pBind->szName, strlen( szArg1 ) );

        if( Pos == 0 )
        {
            // found it!
            if( pBind->szFuncName )
            {
                if( PCHARINFO pCharInfo = GetCharInfo() )
                {
                    std::string sCallFunc( pBind->szFuncName );
                    sCallFunc += " ";
                    sCallFunc += szParam;
					CHAR szCallFunc[MAX_STRING] = { 0 };
					strcpy_s(szCallFunc, sCallFunc.c_str());
					if (pBind->Parse)
					{
						ParseMacroData(szCallFunc, MAX_STRING);
					}

					// pBlock may have changed after executing commands
					pBlock = GetCurrentMacroBlock();
					if (pBlock && !pBlock->BindCmd.size()) {
						if (!gBindInProgress) {
							gBindInProgress = true;
							pBlock->BindCmd = szCallFunc;
						}
						else {
							Beep(1000, 100);
							WriteChatf("Can't execute bind while another bind is in progress");
						}
					}
                }
            }
            strcpy_s( szLastCommand, szOriginalLine );
            return;
        }

        pBind = pBind->pNext;
    }

    // skip this logic for Bind Commands.
    if( _strnicmp( szOriginalLine, "sub bind_", 9 ) != 0 ) {
        if( !_strnicmp( szOriginalLine, "sub ", 4 ) ) {
            FatalError( "Flow ran into another subroutine. (%s)", szOriginalLine );
            return;
        }

        strcpy_s( szLastCommand, szOriginalLine );
        MacroError( "DoCommand - Couldn't parse '%s'", szOriginalLine );
    }
}

class CCommandHook 
{ 
public: 
    VOID Detour(PSPAWNINFO pChar, PCHAR szFullLine) 
    {
		lockit lk(ghCCommandLock,"CCommandHook::Detour");
        DebugSpew("CCommandHook::Detour(%s)",szFullLine);
        CHAR szFullCommand[MAX_STRING] = {0}; 
        CHAR szCommand[MAX_STRING] = {0}; 
        CHAR szArgs[MAX_STRING] = {0}; 
        CHAR szOrig[MAX_STRING] = {0};
        CHAR szSub[MAX_STRING] = {0};
        std::string szSubFullCommand = "";
        unsigned int k=0;
        bool OneCharacterSub = false;
        PSUB pSubLoop = pSubs;
        if (szFullLine[0]!=0) { 
			strcpy_s(szFullCommand,szFullLine);
            GetArg(szCommand,szFullCommand,1); 

            if (!_stricmp(szCommand,"/camp"))
            {
                if (GetMacroBlockCount())
                {
                    WriteChatColor("A macro is currently running.  You may wish to /endmacro before you finish camping.", CONCOLOR_YELLOW );
                }
            }

            szSubFullCommand = szFullCommand;
            size_t len = strnlen_s(szFullCommand, MAX_STRING);
			for (unsigned int i=0; i < sizeof(szFullCommand); i++ ) 
            {
                if (szFullCommand[i] == '%' && ((i+2)<len))
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
                            sprintf_s( szSub, "%s", pSubLoop->szSub );
                            break;
                        }
                        pSubLoop = pSubLoop->pNext;
                    }
                    if (szSub[0] != '\0' ) {
                        szSubFullCommand.replace(i,k+1,szSub);
						sprintf_s( szFullCommand, "%s",szSubFullCommand.c_str() );
                    }
                    szOrig[0] = '\0';
                    szSub[0] = '\0';
                    k=0;
                    OneCharacterSub = false;
                    pSubLoop = pSubs;
                }
            }
			sprintf_s(szFullCommand, "%s", szSubFullCommand.c_str() );
			std::string sName = szCommand;
			std::transform(sName.begin(), sName.end(), sName.begin(), tolower);
			if (mAliases.find(sName) != mAliases.end()) {
				sprintf_s(szCommand,"%s%s",mAliases[sName].c_str(),szFullCommand+sName.size());
                strcpy_s(szFullCommand,szCommand); 
			}

            GetArg(szCommand,szFullCommand,1); 
            strcpy_s(szArgs, GetNextArg(szFullCommand)); 

            PMQCOMMAND pCommand=pCommands;
            while(pCommand)
            {
                if (pCommand->InGameOnly && gGameState!=GAMESTATE_INGAME)
                {
                    pCommand=pCommand->pNext;
                    continue;
                }
                int Pos=_strnicmp(szCommand,pCommand->Command,strlen(szCommand));
                if (Pos<0)
                {// command not found
                    break;
                }
                if (Pos==0)
                {
       	        	//                      the parser version is 2 or It's not version 2 and we're allowing command parses
					if (pCommand->Parse && (gdwParserEngineVer == 2 || (gdwParserEngineVer != 2 && bAllowCommandParse))) 
					{
						ParseMacroParameter(pChar, szArgs);
					}
                    if (pCommand->EQ)
                    {
                        strcat_s(szCommand," "); 
						strcat_s(szCommand,szArgs);
                        Trampoline(pChar,szCommand); 
                    }
                    else
                    {
                        pCommand->Function(pChar,szArgs);
                    }
                    strcpy_s(szLastCommand,szFullCommand);
                    return;
                }
                pCommand=pCommand->pNext;
            }

            PBINDLIST pBind = pBindList;
			PMACROBLOCK pBlock = GetCurrentMacroBlock();
            while( pBind )
            {
                if( gGameState != GAMESTATE_INGAME )
                {
                    // Macro Binds only supported in-game
                    pBind = pBind->pNext;
                    continue;
                }

                int Pos = _strnicmp( szCommand, pBind->szName, strlen( szCommand ) );

                if( Pos == 0 )
                {
                    // found it!
                    if( pBind->szFuncName )
                    {
                        if( PCHARINFO pCharInfo = GetCharInfo() )
                        {
                            std::string sCallFunc( pBind->szFuncName );
                            sCallFunc += " ";
                            sCallFunc += szArgs;
							CHAR szCallFunc[MAX_STRING] = { 0 };
							strcpy_s(szCallFunc, sCallFunc.c_str());
							if (pBind->Parse)
							{
								ParseMacroData(szCallFunc, MAX_STRING);
							}
							if (pBlock && !pBlock->BindCmd.size()) {
								if (!gBindInProgress) {
									gBindInProgress = true;
									pBlock->BindCmd = szCallFunc;
								}
								else {
									Beep(1000, 100);
									WriteChatf("Can't execute bind while another bind is in progress");
								}
							}
							//CHAR szOrg[MAX_STRING] = {"${Time}"};
							//ParseMacroData(szOrg, MAX_STRING);
							//WriteChatf("[%s] %s called",szOrg, szCallFunc.c_str());
							//Beep(1000, 100);
                        }
                    }
                    strcpy_s( szLastCommand, szFullCommand );
                    return;
                }

                pBind = pBind->pNext;
            }
        }
        Trampoline(pChar,szFullLine); 
		strcpy_s(szLastCommand,szFullCommand);
    } 

    VOID Trampoline(PSPAWNINFO pChar, PCHAR szFullLine); 

}; 

DETOUR_TRAMPOLINE_EMPTY(VOID CCommandHook::Trampoline(PSPAWNINFO pChar, PCHAR szFullLine)); 


void AddCommand(PCHAR Command, fEQCommand Function, BOOL EQ, BOOL Parse, BOOL InGame)
{
    DebugSpew("AddCommand(%s,0x%X)",Command,Function);
    PMQCOMMAND pCommand=new MQCOMMAND;
    memset(pCommand,0,sizeof(MQCOMMAND));
    strcpy_s(pCommand->Command,Command);
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
        if (_stricmp(pCommand->Command,pInsert->Command)<=0)
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
        int Pos=_strnicmp(Command,pCommand->Command,63);
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
	std::string sName = ShortCommand;
	std::transform(sName.begin(), sName.end(), sName.begin(), tolower);
    DebugSpew("AddAlias(%s,%s)",sName.c_str(),LongCommand);
	mAliases[sName] = LongCommand;
}

BOOL RemoveAlias(PCHAR ShortCommand)
{
	std::string sName = ShortCommand;
	std::transform(sName.begin(), sName.end(), sName.begin(), tolower);
	WritePrivateProfileString("Aliases", sName.c_str(),NULL, gszINIFilename);
	if (mAliases.find(sName) != mAliases.end()) {
		mAliases.erase(sName);
		return 1;
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
		strcpy_s(pSub->szOrig,Original);
		strcpy_s(pSub->szSub,Substitution);
        pSubs=pSub;
        return;
    }
    PSUB pInsert=pSubs;
    PSUB pLast=0;
    while(pInsert)
    {
        int Pos= _stricmp(Original,pInsert->szOrig);
        if (Pos<0)
        {
            // insert here.
            PSUB pSub=new SUB;
            memset(pSub,0,sizeof(SUB));
			strcpy_s(pSub->szOrig,Original);
			strcpy_s(pSub->szSub,Substitution);
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
			strcpy_s(pInsert->szOrig,Original);
			strcpy_s(pInsert->szSub,Substitution);
            return;
        }
        pLast=pInsert;
        pInsert=pInsert->pNext;
    }
    // End of list
    PSUB pSub=new SUB;
    memset(pSub,0,sizeof(SUB));
	strcpy_s(pSub->szOrig,Original);
	strcpy_s(pSub->szSub,Substitution);
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
    int i = 0;
    DebugSpew("Initializing Commands");
    InitializeCriticalSection(&gCommandCS);
	if (!ghCCommandLock)
		ghCCommandLock = CreateMutex(NULL, FALSE, NULL);
    EzDetourwName(CEverQuest__InterpretCmd,&CCommandHook::Detour,&CCommandHook::Trampoline,"CEverQuest__InterpretCmd");

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
        } else if (!strcmp(pCmdListOrig[i].szName,"/hotbutton")) {
            cmdHotbutton = (fEQCommand)pCmdListOrig[i].fAddress;
        } else if (!strcmp(pCmdListOrig[i].szName,"/useitem")) {
            cmdUseItem = (fEQCommand)pCmdListOrig[i].fAddress;
        } else if (!strcmp(pCmdListOrig[i].szName,"/taskquit")) {
            cmdTaskQuit = (fEQCommand)pCmdListOrig[i].fAddress;
        } else if (!strcmp(pCmdListOrig[i].szName,"/pet")) {
            cmdPet = (fEQCommand)pCmdListOrig[i].fAddress;
        } else if (!strcmp(pCmdListOrig[i].szName,"/mercswitch")) {
            cmdMercSwitch = (fEQCommand)pCmdListOrig[i].fAddress;
        } else if (!strcmp(pCmdListOrig[i].szName,"/advloot")) {
            cmdAdvLoot = (fEQCommand)pCmdListOrig[i].fAddress;
        } else if (!strcmp(pCmdListOrig[i].szName,"/pickzone")) {
            cmdPickZone = (fEQCommand)pCmdListOrig[i].fAddress;
		} else if (!strcmp(pCmdListOrig[i].szName,"/assist")) {
			cmdAssist = (fEQCommand)pCmdListOrig[i].fAddress;
        } else if (!strcmp(pCmdListOrig[i].szName,"/quit")) {
			cmdQuit = (fEQCommand)pCmdListOrig[i].fAddress;
        }
        AddCommand(pCmdListOrig[i].szName,pCmdListOrig[i].fAddress,TRUE,1,1);
    }



    // Add MQ commands...
    struct _NEWCOMMANDLIST { PCHAR szCommand; fEQCommand pFunc; BOOL Parse; BOOL InGame;} NewCommands[] = {
        {"/whotarget",  SuperWhoTarget,1,1},
        {"/location",   Location,1,1},
        {"/help",       Help,1,0},
        {"/target",     Target,1,1},
        {"/alias",      Alias,0,0},
        {"/aa",         AltAbility,1,1},
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
		{"/selectitem", SelectItem,1,1},
        {"/buyitem",    BuyItem,1,1},
        {"/sellitem",   SellItem,1,1},
        {"/memspell",   MemSpell,1,1},
        {"/loadspells", LoadSpells,1,1},
        {"/loginname",  DisplayLoginName,1,0},
        {"/echo",       Echo,1,0},
        {"/msgbox",     MQMsgBox,1,0},
        {"/lootall",    LootAll,1,0},
        {"/alert",      Alert,1,1},
        {"/click",      Click,1,0},
		{"/mouseto",    MouseTo,1,0},
        {"/items",      Items,1,1},
        {"/itemtarget", ItemTarget,1,1},
        {"/doability",  DoAbility,1,1},
        {"/doors",      Doors,1,1},
        {"/doortarget", DoorTarget,1,1},
        {"/beep",       MacroBeep,1,0},
        {"/cast",       Cast,1,1},
        {"/mqlog",      MacroLog,1,0},
		{"/updateitems",UpdateItemInfo,1,1},
        {"/ini",        IniOutput,1,0},
        {"/setautorun", SetAutoRun,0,1},
        {"/banklist",   BankList,1,1},
        {"/look",       Look,1,1},
        {"/windowstate",WindowState,1,0},
        {"/destroy",    EQDestroyHeldItemOrMoney,1,1},
        {"/popup",      PopupText,1,1},
		{"/popcustom",	PopupTextCustom,1,1},
		{"/popupecho",	PopupTextEcho,1,1},
		{"/exec",       Exec,1,0},
		{"/keypress",   DoMappable,1,0},
		{"/multiline",  MultilineCommand,0,0},
		{"/ranged",     do_ranged,1,1},
		{"/loadcfg",    LoadCfgCommand,1,0},
		{"/squelch",    SquelchCommand,1,0},
		{"/docommand",  DoCommandCmd,1,0},
		{"/ctrlkey",    DoCtrlCmd,0,0},
		{"/altkey",     DoAltCmd,0,0},
		{"/shiftkey",   DoShiftCmd,0,0},
		{"/timed",      DoTimedCmd,0,0},
#ifndef ISXEQ_LEGACY
        {"/bind",       MQ2KeyBindCommand,1,0},
#endif
		{"/noparse",    NoParseCmd,0,0},
		{"/nomodkey",   NoModKeyCmd,0,0},
        {"/dumpbinds",  DumpBindsCommand,1,0},
        {"/dosocial",   DoSocial,1,1},
		{"/combine",    CombineCmd,1,1},
        {"/drop",       DropCmd,1,0},
		{"/delay",      Delay,0,0}, // do not parse
        {"/hud",        HudCmd,1,0},
        {"/caption",    CaptionCmd,0,0},
        {"/captioncolor",CaptionColorCmd,1,0},
        {"/useitem",    UseItemCmd,1,1},
        {"/hotbutton",    DoHotbutton,1,1},
        {"/taskquit",    TaskQuitCmd,1,1},
		{"/spellslotinfo",SpellSlotInfo,1,1},
		{"/getwintitle",GetWinTitle,1,0},
		{"/setwintitle",SetWinTitle,1,0},
		{"/removebuff", RemoveBuff,1,1},
		{"/removepetbuff", RemovePetBuff,1,1},
		{"/makemevisible",MakeMeVisible,0,1},
		{"/pet",        PetCmd,1,1},
		{"/mercswitch", MercSwitchCmd,1,1},
		{"/removeaura", RemoveAura,0,1},
		{"/advloot",    AdvLootCmd,1,1},
		{"/pickzone",   PickZoneCmd,1,1},
		{"/assist",     AssistCmd,1,1},
		{"/setprio",    SetProcessPriority,1,0},
		{"/screenmode", ScreenModeCmd,1,0},
		{"/usercamera", UserCameraCmd,1,0},
		{"/mapzoom",    MapZoomCmd,1,0},
		{"/foreground", ForeGroundCmd,1,0},
		{"/quit",		QuitCmd,1,0},
		{"/removelev", RemoveLev,1,0},
		{"/mqcopylayout", MQCopyLayout,1,0},
		
    	// The below needs to match ENGINE_SWITCH_CMD in MQ2Globals.h (adding a slash)
		{static_cast<char*>("/engine"),		EngineCommand,1,0},
		
        {NULL,          NULL,0,1},
    };
    // Remove replaced commands first
    for (i = 0 ; NewCommands[i].szCommand && NewCommands[i].pFunc ; i++)
    {
        RemoveCommand(NewCommands[i].szCommand);
        AddCommand(NewCommands[i].szCommand,NewCommands[i].pFunc,0,NewCommands[i].Parse,NewCommands[i].InGame);
    }
	//truebox builds are not supported anymore.
	//This code is here to make sure we are NOT run on truebox.
	//(bypassing these calls will severly cripple your mq2) -eqmule
	typedef DWORD(__cdecl *fAuthenticateTrueBox)(DWORD);
	fAuthenticateTrueBox AuthenticateTrueBox = 0;
	typedef DWORD(__cdecl *fGetTrueBoxKey)(DWORD);
	fGetTrueBoxKey GetTrueBoxKey = 0;
	if (ghmq2ic) {
		AuthenticateTrueBox = (fAuthenticateTrueBox)GetProcAddress(ghmq2ic, "AuthenticateTrueBox");
		GetTrueBoxKey = (fGetTrueBoxKey)GetProcAddress(ghmq2ic, "GetTrueBoxKey");
		DWORD tbkey = GetTrueBoxKey(1);
		if (AuthenticateTrueBox) {
			AuthenticateTrueBox(tbkey);
		}
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
    sprintf_s(MainINI,"%s\\macroquest.ini",gszINIPath);
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
	sprintf_s(MainINI,"%s\\macroquest.ini",gszINIPath);
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
	lockit lk(ghLockDelayCommand,"ShutdownMQ2Commands");
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
        //LocalFree(gDelayedCommands);
        delete gDelayedCommands;
        gDelayedCommands=pNext;
    }
    while(pTimedCommands)
    {
        PTIMEDCOMMAND pNext=pTimedCommands->pNext;
        delete pTimedCommands;
        pTimedCommands=pNext;
    }
	mAliases.clear();
    while(pSubs)
    {
        PSUB pNext=pSubs->pNext;
        delete pSubs;
        pSubs=pNext;
    }

    LeaveCriticalSection(&gCommandCS);
    DeleteCriticalSection(&gCommandCS);
	if (ghCCommandLock) {
		ReleaseMutex(ghCCommandLock);
		CloseHandle(ghCCommandLock);
		ghCCommandLock = 0;
	}
}

VOID DoTimedCommands()
{
	lockit lk(ghLockDelayCommand,"DoTimedCommands");
    ULONGLONG Now=MQGetTickCount64();
    while(pTimedCommands && pTimedCommands->Time<=Now)
    {
        PTIMEDCOMMAND pNext=pTimedCommands->pNext;
        DoCommand((PSPAWNINFO)pLocalPlayer,pTimedCommands->Command);
        delete pTimedCommands;
        pTimedCommands=pNext;
    }
}

VOID TimedCommand(PCHAR Command, DWORD msDelay)
{
	lockit lk(ghLockDelayCommand,"TimedCommand");
    PTIMEDCOMMAND pNew= new TIMEDCOMMAND;
    pNew->Time=msDelay+MQGetTickCount64();
	strcpy_s(pNew->Command,Command);

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
