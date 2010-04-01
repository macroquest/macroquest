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

/* This function is still in the client; however, it was phased out as of 
   the Omens of War Expansion

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
*/
}; 

#ifndef ISXEQ

DWORD __cdecl DrawHUD_Trampoline(DWORD,DWORD,DWORD,DWORD); 
DWORD __cdecl DrawHUD_Detour(DWORD a,DWORD b,DWORD c,DWORD d) 
{ 
	DrawHUDParams[0]=a;
	DrawHUDParams[1]=b;
	DrawHUDParams[2]=c;
	DrawHUDParams[3]=d;
	if (gbHUDUnderUI || gbAlwaysDrawMQHUD)
		return 0;
	int Ret= DrawHUD_Trampoline(a,b,c,d);
	Benchmark(bmPluginsDrawHUD,PluginsDrawHUD());
	if (HMODULE hmEQPlayNice=GetModuleHandle("EQPlayNice.dll"))
	{
		if (fMQPulse pEQPlayNicePulse=(fMQPulse)GetProcAddress(hmEQPlayNice,"Compat_DrawIndicator"))
			pEQPlayNicePulse();
	}
	return Ret;
} 

void DrawHUD()
{
	if (gbAlwaysDrawMQHUD || (gGameState==GAMESTATE_INGAME && gbHUDUnderUI && gbShowNetStatus))
	{
		if (DrawHUDParams[0] && gGameState==GAMESTATE_INGAME && gbShowNetStatus)
		{
			DrawHUD_Trampoline(DrawHUDParams[0],DrawHUDParams[1],DrawHUDParams[2],DrawHUDParams[3]);
			DrawHUDParams[0]=0;
		}
		Benchmark(bmPluginsDrawHUD,PluginsDrawHUD());
		if (HMODULE hmEQPlayNice=GetModuleHandle("EQPlayNice.dll"))
		{
			if (fMQPulse pEQPlayNicePulse=(fMQPulse)GetProcAddress(hmEQPlayNice,"Compat_DrawIndicator"))
				pEQPlayNicePulse();
		}

	}
	else
		DrawHUDParams[0]=0;
}


VOID DrawHUDText(PCHAR Text, DWORD X, DWORD Y, DWORD Argb)
{

	DWORD sX=((PCXWNDMGR)pWndMgr)->ScreenExtentX;
	DWORD sY=((PCXWNDMGR)pWndMgr)->ScreenExtentY;

	CTextureFont* pFont=0;
	DWORD* ppDWord=(DWORD*)((PCXWNDMGR)pWndMgr)->font_list_ptr;
	if (ppDWord[1]<=2)
	{
		pFont=(CTextureFont*)ppDWord[0];
	}
	else
	{
		pFont=(CTextureFont*)ppDWord[2];
	}
	pFont->DrawWrappedText(&CXStr((char*)Text),X,Y,sX-X,&CXRect(X,Y,sX,sY),Argb,1,0);
}
#endif

class EQ_LoadingSHook
{
public:

	VOID WriteTextHD_Trampoline(char *,int,int,int);
	VOID WriteTextHD_Detour(char *A,int B,int C,int D)
	{
		WriteTextHD_Trampoline("MQ2: Think of it as evolution in action.",B,C,D);
	}
};

//DETOUR_TRAMPOLINE_EMPTY(bool CDisplayHook::GetWorldFilePath_Trampoline(char *, char *)); 
DETOUR_TRAMPOLINE_EMPTY(VOID EQ_LoadingSHook::WriteTextHD_Trampoline(char *,int,int,int)); 
DETOUR_TRAMPOLINE_EMPTY(DWORD DrawHUD_Trampoline(DWORD,DWORD,DWORD,DWORD)); 
DETOUR_TRAMPOLINE_EMPTY(VOID CDisplayHook::CleanUI_Trampoline(VOID)); 
DETOUR_TRAMPOLINE_EMPTY(VOID CDisplayHook::ReloadUI_Trampoline(BOOL)); 

VOID InitializeDisplayHook()
{
	DebugSpew("Initializing Display Hooks");

	EzDetour(CDisplay__CleanGameUI,CDisplayHook::CleanUI_Detour,CDisplayHook::CleanUI_Trampoline);
	EzDetour(CDisplay__ReloadUI,CDisplayHook::ReloadUI_Detour,CDisplayHook::ReloadUI_Trampoline);
//	EzDetour(CDisplay__GetWorldFilePath,CDisplayHook::GetWorldFilePath_Detour,CDisplayHook::GetWorldFilePath_Trampoline);
#ifndef ISXEQ
	EzDetour(DrawNetStatus,DrawHUD_Detour,DrawHUD_Trampoline);
#endif
	EzDetour(EQ_LoadingS__WriteTextHD,EQ_LoadingSHook::WriteTextHD_Detour,EQ_LoadingSHook::WriteTextHD_Trampoline);
}

VOID ShutdownDisplayHook()
{
	PluginsCleanUI();
	DebugSpew("Shutting down Display Hooks");

	RemoveDetour(CDisplay__CleanGameUI);
	RemoveDetour(CDisplay__ReloadUI);
#ifndef ISXEQ
	RemoveDetour(DrawNetStatus);
#endif
	RemoveDetour(EQ_LoadingS__WriteTextHD);
//	RemoveDetour(CDisplay__GetWorldFilePath);
}
