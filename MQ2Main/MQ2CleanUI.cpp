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

	bool GetWorldFilePath_Trampoline(char *, char *);
	bool GetWorldFilePath_Detour(char *Filename, char *FullPath)
	{
		if (!stricmp(FullPath,"bmpwad8.s3d"))
		{
			sprintf(Filename,"%s\\bmpwad8.s3d",gszINIPath);
			if (_access(Filename,0)!=-1)
			{

				return 1;
			}
		}
		
		bool Ret=GetWorldFilePath_Trampoline(Filename,FullPath);
		return Ret;
	}

}; 

DWORD __cdecl DrawHUD_Trampoline(DWORD,DWORD,DWORD,DWORD); 
DWORD __cdecl DrawHUD_Detour(DWORD a,DWORD b,DWORD c,DWORD d) 
{ 
	int Ret = DrawHUD_Trampoline(a,b,c,d);
	Benchmark(bmPluginsDrawHUD,PluginsDrawHUD());
	return Ret;
} 

class EQ_LoadingSHook
{
public:

	VOID WriteTextHD_Trampoline(char *,int,int,int);
	VOID WriteTextHD_Detour(char *A,int B,int C,int D)
	{
		WriteTextHD_Trampoline("MQ2: Think of it as evolution in action.",B,C,D);
	}
};

DETOUR_TRAMPOLINE_EMPTY(bool CDisplayHook::GetWorldFilePath_Trampoline(char *, char *)); 
DETOUR_TRAMPOLINE_EMPTY(VOID EQ_LoadingSHook::WriteTextHD_Trampoline(char *,int,int,int)); 
DETOUR_TRAMPOLINE_EMPTY(DWORD DrawHUD_Trampoline(DWORD,DWORD,DWORD,DWORD)); 
DETOUR_TRAMPOLINE_EMPTY(VOID CDisplayHook::CleanUI_Trampoline(VOID)); 
DETOUR_TRAMPOLINE_EMPTY(VOID CDisplayHook::ReloadUI_Trampoline(BOOL)); 

VOID InitializeDisplayHook()
{
	DebugSpew("Initializing Display Hooks");

	EasyClassDetour(CDisplay__CleanGameUI,CDisplayHook,CleanUI_Detour,VOID,(VOID),CleanUI_Trampoline);
	EasyClassDetour(CDisplay__ReloadUI,CDisplayHook,ReloadUI_Detour,VOID,(BOOL),ReloadUI_Trampoline);
	EasyClassDetour(CDisplay__GetWorldFilePath,CDisplayHook,GetWorldFilePath_Detour,bool,(char*,char*),GetWorldFilePath_Trampoline);
	EasyDetour(DrawNetStatus,DrawHUD_Detour,DWORD,(DWORD,DWORD,DWORD,DWORD),DrawHUD_Trampoline);
	EasyClassDetour(EQ_LoadingS__WriteTextHD,EQ_LoadingSHook,WriteTextHD_Detour,VOID,(char *,int,int,int),WriteTextHD_Trampoline);

}

VOID ShutdownDisplayHook()
{
	PluginsCleanUI();
	DebugSpew("Shutting down Display Hooks");
	RemoveDetour(CDisplay__CleanGameUI);
	RemoveDetour(CDisplay__ReloadUI);
	RemoveDetour(DrawNetStatus);
	RemoveDetour(EQ_LoadingS__WriteTextHD);
	RemoveDetour(CDisplay__GetWorldFilePath);
}
