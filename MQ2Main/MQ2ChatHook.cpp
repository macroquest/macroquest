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
            if (!SkipTrampoline)
                Trampoline(szMsg, dwColor, EqLog, dopercentsubst); 
        } 
        gbInChat = FALSE; 
    } 

    VOID TellWnd_Trampoline(char *message,char *name,char *name2,void *unknown,int color,bool b);
    VOID TellWnd_Detour(char *message,char *name,char *name2,void *unknown,int color,bool b)
    {
        char szMsg[MAX_STRING];
        BOOL SkipTrampoline;
        gbInChat=true;

        sprintf(szMsg,"%s tells you, '%s'",name,message);

        CheckChatForEvent(szMsg);

        Benchmark(bmPluginsIncomingChat,SkipTrampoline=PluginsIncomingChat(szMsg,color));

        if(!SkipTrampoline)
            TellWnd_Trampoline(message,name,name2,unknown,color,b);

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
}

VOID ShutdownChatHook()
{
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
