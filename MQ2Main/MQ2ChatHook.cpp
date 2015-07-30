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


#include "MQ2Main.h"
DWORD __stdcall BeepOnTellThread(PVOID pData)
{
	Beep(750,200);
	return 0;
}
DWORD __stdcall FlashOnTellThread(PVOID pData)
{
	DWORD lReturn = GetCurrentProcessId();
	DWORD pid = lReturn;
	AllowSetForegroundWindow(pid);
	BOOL ret = EnumWindows(EnumWindowsProc,(LPARAM)&lReturn);
	if(lReturn!=pid) {
		//SetForegroundWindow((HWND)lReturn);
		FLASHWINFO fwi = {sizeof(FLASHWINFO)};
		fwi.dwFlags=FLASHW_ALL;
		fwi.hwnd = (HWND)lReturn;
		fwi.uCount = 3;
		fwi.dwTimeout = 0;
		FlashWindowEx(&fwi);
	}	
	return 0;
}
class CChatHook 
{ 
public: 
    VOID Trampoline(PCHAR szMsg, DWORD dwColor, bool EqLog, bool dopercentsubst); 
    VOID Detour(PCHAR szMsg, DWORD dwColor, bool EqLog, bool dopercentsubst) 
    { 
        //DebugSpew("CChatHook::Detour(%s)",szMsg); 
        gbInChat = TRUE; 


        CheckChatForEvent(szMsg);

        BOOL Filtered=FALSE; 
        PFILTER Filter = gpFilters; 
        while (Filter && !Filtered) { 
            if (!Filter->pEnabled || (*Filter->pEnabled)) { 
                if (*Filter->FilterText == '*') {
                    if (strstr(szMsg,Filter->FilterText+1)) 
                        Filtered = TRUE;
                } else { 
                    if (!strnicmp(szMsg,Filter->FilterText,Filter->Length)) 
                        Filtered = TRUE; 
                }
            } 
            Filter = Filter->pNext; 
        } 

        if (!Filtered) { 
            //if (gTelnetServer && gTelnetConnection && !gPauseTelnetOutput) TelnetServer_Write(szMsg); 
            BOOL SkipTrampoline;
            Benchmark(bmPluginsIncomingChat,SkipTrampoline=PluginsIncomingChat(szMsg,dwColor));
            if (!SkipTrampoline) {
				if (gbTimeStampChat) {
					CHAR tmpbuf[32] = {0};
					_strtime_s( tmpbuf, 32 );
					int len = strlen(szMsg);
					char *szTimeStamedMsg = (char *)LocalAlloc(LPTR,len+64);
					if(szTimeStamedMsg) {
						sprintf_s(szTimeStamedMsg,len+63,"[%s] %s",tmpbuf,szMsg);
						Trampoline(szTimeStamedMsg, dwColor, EqLog, dopercentsubst);
						LocalFree(szTimeStamedMsg);
					} else {
						Trampoline(szMsg, dwColor, EqLog, dopercentsubst);
					}
				} else {
					Trampoline(szMsg, dwColor, EqLog, dopercentsubst);
				}
			}
        } 
        gbInChat = FALSE; 
    } 

    VOID TellWnd_Trampoline(char *message,char *name,char *name2,void *unknown,int color,bool b);
    VOID TellWnd_Detour(char *message,char *name,char *name2,void *unknown,int color,bool b)
    {
		int len = strlen(message);
		char *szMsg = (char *)LocalAlloc(LPTR,len+64);
        BOOL SkipTrampoline = 0;
        gbInChat=true;
		if(szMsg) {
			sprintf_s(szMsg,len+63,"%s tells you, '%s'",name,message);
			CheckChatForEvent(szMsg);
			Benchmark(bmPluginsIncomingChat,SkipTrampoline=PluginsIncomingChat(szMsg,color));
		}

        if(!SkipTrampoline) {
			if(gbFlashOnTells) {
				if(PCHARINFO pChar = GetCharInfo()) {
					if(_stricmp(pChar->Name,name)) {//dont beep if its our own character doing the tell...
						DWORD nThreadId = 0;
						CreateThread(NULL,NULL,FlashOnTellThread,0,0,&nThreadId);
					}
				}
			}
			if(gbBeepOnTells) {
				if(PCHARINFO pChar = GetCharInfo()) {
					if(_stricmp(pChar->Name,name)) {//dont beep if its our own character doing the tell...
						DWORD nThreadId = 0;
						CreateThread(NULL,NULL,BeepOnTellThread,0,0,&nThreadId);
					}
				}
			}
			if (gbTimeStampChat && szMsg) {
				CHAR tmpbuf[32] = {0};
				_strtime_s( tmpbuf, 32 );
				sprintf_s(szMsg,len+63,"[%s] %s",tmpbuf,name);
				TellWnd_Trampoline(message,szMsg,name2,unknown,color,b);
			} else {
				TellWnd_Trampoline(message,name,name2,unknown,color,b);
			}
		}
		if(szMsg)
			LocalFree(szMsg);
        gbInChat=false;
    }

    VOID UPCNotificationFlush_Trampoline();
    VOID UPCNotificationFlush_Detour()
    {
        PEVERQUEST eq = (PEVERQUEST)this;
        char szBuf[MAX_STRING] = {0};

        if(eq->ChannelQty > 0)
        {
            int len = 0;
            char *pTmp;

            if(eq->bJoinedChannel)
            {
                pTmp = "* %s has entered channel ";
            }
            else
            {
                pTmp = "* %s has left channel ";
            }

            sprintf(szBuf, pTmp, eq->ChannelPlayerName);

            for(DWORD i = 0; i < eq->ChannelQty; i++)
            {
                if(i)
                {
                    pTmp = ", %s:%d";
                }
                else
                {
                    pTmp = "%s:%d";
                }

                len = strlen(szBuf);
                sprintf(&szBuf[len], pTmp, eq->ChannelName[i], eq->ChannelNumber[i] + 1);
            }

            CheckChatForEvent(szBuf);
        }

        UPCNotificationFlush_Trampoline();
    }
}; 

DETOUR_TRAMPOLINE_EMPTY(VOID CChatHook::Trampoline(PCHAR szMsg, DWORD dwColor, bool EqLog, bool dopercentsubst)); 
DETOUR_TRAMPOLINE_EMPTY(VOID CChatHook::TellWnd_Trampoline(char *message,char *name,char *name2,void *unknown,int color,bool b)); 
DETOUR_TRAMPOLINE_EMPTY(VOID CChatHook::UPCNotificationFlush_Trampoline());

VOID dsp_chat_no_events(const char *Text,int Color,bool EqLog, bool dopercentsubst)
{
    ((CChatHook*)pEverQuest)->Trampoline((PCHAR)Text,Color,EqLog, dopercentsubst);
}

unsigned int __stdcall MQ2DataVariableLookup(char * VarName, char * Value)
{
    strcpy(Value,VarName);
    if (!GetCharInfo()) return strlen(Value);
    return strlen(ParseMacroParameter(GetCharInfo()->pSpawn,Value));
}
#ifndef ISXEQ
VOID FlashOnTells(PSPAWNINFO pChar, char *szLine)
{
#else
int FlashOnTells(int argc, char *argv[])
{
   PCHAR szLine = NULL;
    if (argc > 0)
        szLine = argv[1];
#endif
	if(szLine[0]!='\0') {
		if(!_stricmp(szLine,"on")) {
			gbFlashOnTells = 0;
		} else if(!_stricmp(szLine,"off")) {
			gbFlashOnTells = 1;
		}
	}
	if(gbFlashOnTells) {
		gbFlashOnTells=0;
		WriteChatColor("Flash On Tells is OFF",CONCOLOR_LIGHTBLUE);
		WritePrivateProfileString("MacroQuest","FlashOnTells","0",gszINIFilename);
	} else {
		gbFlashOnTells=1;
		WriteChatColor("Flash On Tells is ON",CONCOLOR_YELLOW);
		WritePrivateProfileString("MacroQuest","FlashOnTells","1",gszINIFilename);
	}
#ifdef ISXEQ
   return 0;
#endif
}
#ifndef ISXEQ
VOID BeepOnTells(PSPAWNINFO pChar, char *szLine)
{
#else
int BeepOnTells(int argc, char *argv[])
{
   PCHAR szLine = NULL;
    if (argc > 0)
        szLine = argv[1];
#endif
	if(szLine[0]!='\0') {
		if(!_stricmp(szLine,"on")) {
			gbBeepOnTells = 0;
		} else if(!_stricmp(szLine,"off")) {
			gbBeepOnTells = 1;
		}
	}
	if(gbBeepOnTells) {
		gbBeepOnTells=0;
		WriteChatColor("Beep On Tells is OFF",CONCOLOR_LIGHTBLUE);
		WritePrivateProfileString("MacroQuest","BeepOnTells","0",gszINIFilename);
	} else {
		gbBeepOnTells=1;
		WriteChatColor("Beep On Tells is ON",CONCOLOR_YELLOW);
		WritePrivateProfileString("MacroQuest","BeepOnTells","1",gszINIFilename);
	}
#ifdef ISXEQ
   return 0;
#endif
}
#ifndef ISXEQ
VOID TimeStampChat(PSPAWNINFO pChar, char *szLine)
{
#else
int TimeStampChat(int argc, char *argv[])
{
   PCHAR szLine = NULL;
    if (argc > 0)
        szLine = argv[1];
#endif
	if(szLine[0]!='\0') {
		if(!_stricmp(szLine,"on")) {
			gbTimeStampChat = 0;
		} else if(!_stricmp(szLine,"off")) {
			gbTimeStampChat = 1;
		}
	}
	if(gbTimeStampChat) {
		gbTimeStampChat=0;
		WriteChatColor("Chat Time Stamping is OFF",CONCOLOR_LIGHTBLUE);
		WritePrivateProfileString("MacroQuest","TimeStampChat","0",gszINIFilename);
	} else {
		gbTimeStampChat=1;
		WriteChatColor("Chat Time Stamping is ON",CONCOLOR_YELLOW);
		WritePrivateProfileString("MacroQuest","TimeStampChat","1",gszINIFilename);
	}
#ifdef ISXEQ
   return 0;
#endif
}
VOID InitializeChatHook()
{
    DebugSpew("Initializing chat hook");

    // initialize Blech
#ifndef ISXEQ
#ifdef USEBLECHEVENTS
    pEventBlech=new Blech('#','|',MQ2DataVariableLookup);
#endif
    pMQ2Blech=new Blech('#','|',MQ2DataVariableLookup);
    DebugSpew("%s",pMQ2Blech->Version);
#endif
    EzDetour(CEverQuest__dsp_chat,&CChatHook::Detour,&CChatHook::Trampoline);
    EzDetour(CEverQuest__DoTellWindow,&CChatHook::TellWnd_Detour,&CChatHook::TellWnd_Trampoline);
    EzDetour(CEverQuest__UPCNotificationFlush,&CChatHook::UPCNotificationFlush_Detour,&CChatHook::UPCNotificationFlush_Trampoline);
#ifndef ISXEQ
	AddCommand("/timestamp", TimeStampChat);
	AddCommand("/beepontells", BeepOnTells);
	AddCommand("/flashontells", FlashOnTells);
#else
   pISInterface->AddCommand("/timestamp", TimeStampChat,true,false);
   pISInterface->AddCommand("/beepontells", BeepOnTells,true,false);
   pISInterface->AddCommand("/flashontells", FlashOnTells,true,false);
#endif
}

VOID ShutdownChatHook()
{
#ifndef ISXEQ
	RemoveCommand("/flashontells");
	RemoveCommand("/beepontells");
	RemoveCommand("/timestamp");
#else
   pISInterface->RemoveCommand("/timestamp");
   pISInterface->RemoveCommand("/flashontells");
   pISInterface->RemoveCommand("/beepontells");
#endif
   RemoveDetour(CEverQuest__dsp_chat);
    RemoveDetour(CEverQuest__DoTellWindow);
    RemoveDetour(CEverQuest__UPCNotificationFlush);
#ifndef ISXEQ
#ifdef USEBLECHEVENTS
    delete pEventBlech;
#endif
    delete pMQ2Blech;
#endif
}
