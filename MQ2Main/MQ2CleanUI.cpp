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

//#define DEBUG_TRY 1
#include "MQ2Main.h"

class CDisplayHook 
{ 
public: 
	VOID CleanUI_Trampoline(VOID); 
	VOID CleanUI_Detour(VOID) 
	{ 
		Benchmark(bmPluginsCleanUI,DebugTry(PluginsCleanUI()));
		DebugTry(CleanUI_Trampoline());
	} 

	VOID ReloadUI_Trampoline(BOOL);
	VOID ReloadUI_Detour(BOOL UseINI)
	{
		DebugTry(ReloadUI_Trampoline(UseINI));
		Benchmark(bmPluginsReloadUI,DebugTry(PluginsReloadUI()));
	}

}; 

DWORD __cdecl DrawHUD_Trampoline(DWORD,DWORD,DWORD,DWORD); 
DWORD __cdecl DrawHUD_Detour(DWORD a,DWORD b,DWORD c,DWORD d) 
{ 
	int Ret = DrawHUD_Trampoline(a,b,c,d);
	Benchmark(bmPluginsDrawHUD,PluginsDrawHUD());
	return Ret;
} 

DETOUR_TRAMPOLINE_EMPTY(DWORD DrawHUD_Trampoline(DWORD,DWORD,DWORD,DWORD)); 
DETOUR_TRAMPOLINE_EMPTY(VOID CDisplayHook::CleanUI_Trampoline(VOID)); 
DETOUR_TRAMPOLINE_EMPTY(VOID CDisplayHook::ReloadUI_Trampoline(BOOL)); 

VOID InitializeDisplayHook()
{
	DebugSpew("Initializing Display Hooks");
/*
	VOID (CDisplayHook::*pfDetour)(VOID) = CDisplayHook::CleanUI_Detour; 
	VOID (CDisplayHook::*pfTrampoline)(VOID) = CDisplayHook::CleanUI_Trampoline; 
	AddDetour((DWORD) CDisplay__CleanGameUI,*(PBYTE*)&pfDetour,*(PBYTE*)&pfTrampoline);
/**/

	EasyClassDetour(CDisplay__CleanGameUI,CDisplayHook,CleanUI_Detour,VOID,(VOID),CleanUI_Trampoline);
	EasyClassDetour(CDisplay__ReloadUI,CDisplayHook,ReloadUI_Detour,VOID,(BOOL),ReloadUI_Trampoline);

	DWORD (__cdecl *pfHUDDetour)(DWORD,DWORD,DWORD,DWORD) = DrawHUD_Detour; 
	DWORD (__cdecl *pfHUDTrampoline)(DWORD,DWORD,DWORD,DWORD) = DrawHUD_Trampoline; 

	AddDetour((DWORD) DrawNetStatus,*(PBYTE*)&pfHUDDetour,*(PBYTE*)&pfHUDTrampoline);
}

VOID ShutdownDisplayHook()
{
	PluginsCleanUI();
	DebugSpew("Shutting down Display Hooks");
	RemoveDetour((DWORD)CDisplay__CleanGameUI);
	RemoveDetour((DWORD)CDisplay__ReloadUI);
	RemoveDetour((DWORD)DrawNetStatus);
}
