/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003 Lax

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
		DebugSpew("CChatHook::Detour(%s)",szMsg); 
		gbInChat = TRUE; 
		if ((!strncmp(szMsg,"You have entered ",17)) || (strstr(szMsg," saved."))) { 
			if (gZoning) { 
				//gDelayZoning += gZoneDelay; 
				gZoning=FALSE; 
			} 
		} else if (!strcmp(szMsg,"Welcome to EverQuest!")) {
			gbDoAutoRun=TRUE;
		} 

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
			Benchmark(bmPluginsIncomingChat,BOOL SkipTrampoline=PluginsIncomingChat(szMsg,dwColor));
			if (!SkipTrampoline)
				Trampoline(szMsg, dwColor, dwUnknown); 
		} 
		gbInChat = FALSE; 
	} 
}; 


DETOUR_TRAMPOLINE_EMPTY(VOID CChatHook::Trampoline(PCHAR szMsg, DWORD dwColor, DWORD dwUnknown)); 

VOID InitializeChatHook()
{
	DebugSpew("Initializing chat hook");

//	void (CChatHook::*pfDetour)(PCHAR szMsg, DWORD dwColor, DWORD dwUnknown) = CChatHook::Detour; 
//	void (CChatHook::*pfTrampoline)(PCHAR szMsg, DWORD dwColor, DWORD dwUnknown) = CChatHook::Trampoline; 
//	AddDetour((DWORD) CEverQuest__dsp_chat,*(PBYTE*)&pfDetour,*(PBYTE*)&pfTrampoline);

	EasyClassDetour(CEverQuest__dsp_chat,CChatHook,Detour,void,(PCHAR szMsg, DWORD dwColor, DWORD dwUnknown),Trampoline);

}

VOID ShutdownChatHook()
{
	RemoveDetour((DWORD)CEverQuest__dsp_chat);
}
