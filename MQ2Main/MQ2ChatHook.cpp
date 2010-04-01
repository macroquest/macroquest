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
	VOID Trampoline(PCHAR szMsg, DWORD dwColor, DWORD dwUnknown); 
	VOID Detour(PCHAR szMsg, DWORD dwColor, DWORD dwUnknown) 
	{ 
		//DebugSpew("CChatHook::Detour(%s)",szMsg); 
		gbInChat = TRUE; 


		CheckChatForEvent(szMsg);
 
 		BOOL Filtered=FALSE; 
		PFILTER Filter = gpFilters; 
		while (Filter && !Filtered) { 
			if (!Filter->pEnabled || (*Filter->pEnabled)) { 
				if (!strnicmp(szMsg,Filter->FilterText,Filter->Length)) Filtered = TRUE; 
			} 
			Filter = Filter->pNext; 
		} 

		if (!Filtered) { 
//			if (gTelnetServer && gTelnetConnection && !gPauseTelnetOutput) TelnetServer_Write(szMsg); 
			BOOL SkipTrampoline;
			Benchmark(bmPluginsIncomingChat,SkipTrampoline=PluginsIncomingChat(szMsg,dwColor));
			if (!SkipTrampoline)
				Trampoline(szMsg, dwColor, dwUnknown); 
		} 
		gbInChat = FALSE; 
	} 
}; 

DETOUR_TRAMPOLINE_EMPTY(VOID CChatHook::Trampoline(PCHAR szMsg, DWORD dwColor, DWORD dwUnknown)); 

VOID dsp_chat_no_events(const char *Text,int Color,bool Something)
{
	((CChatHook*)pEverQuest)->Trampoline((PCHAR)Text,Color,Something);
}

unsigned long __stdcall MQ2DataVariableLookup(char * VarName, char * Value)
{
	strcpy(Value,VarName);
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
	EzDetour(CEverQuest__dsp_chat,CChatHook::Detour,CChatHook::Trampoline);
}

VOID ShutdownChatHook()
{
	RemoveDetour((DWORD)CEverQuest__dsp_chat);
#ifndef ISXEQ
#ifdef USEBLECHEVENTS
	delete pEventBlech;
#endif
	delete pMQ2Blech;
#endif
}
