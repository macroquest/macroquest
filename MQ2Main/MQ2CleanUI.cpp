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

#include "stdafx.h"
#include "MQ2Main.h"

class CCleanUI 
{ 
public: 
	VOID Trampoline(VOID); 
	VOID Detour(VOID) 
	{ 
		PluginsCleanUI();
		Trampoline();
	} 
}; 


DETOUR_TRAMPOLINE_EMPTY(VOID CCleanUI::Trampoline(VOID)); 

VOID InitializeCleanUI()
{
	DebugSpew("Initializing Clean UI");
	VOID (CCleanUI::*pfDetour)(VOID) = CCleanUI::Detour; 
	VOID (CCleanUI::*pfTrampoline)(VOID) = CCleanUI::Trampoline; 

	AddDetour((DWORD) CDisplay__CleanGameUI,*(PBYTE*)&pfDetour,*(PBYTE*)&pfTrampoline);

}

VOID ShutdownCleanUI()
{
	PluginsCleanUI();
	DebugSpew("Shutting down Clean UI");
	RemoveDetour((DWORD)CDisplay__CleanGameUI);
}
