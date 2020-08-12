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

char *OurCaption = "MQ2: Think of it as evolution in action.";

class CDisplayHook 
{ 
public: 
    VOID CleanUI_Trampoline(VOID); 
    VOID CleanUI_Detour(VOID) 
    { 
        Benchmark(bmPluginsCleanUI,DebugTry(PluginsCleanUI()));
        DebugTry(CleanUI_Trampoline());
    } 
	#if !defined(ROF2EMU) && !defined(UFEMU)
    VOID ReloadUI_Trampoline(bool, bool);
    VOID ReloadUI_Detour(bool UseINI, bool bUnknown)
    {
        DebugTry(ReloadUI_Trampoline(UseINI, bUnknown));
        Benchmark(bmPluginsReloadUI,DebugTry(PluginsReloadUI()));
    }
	#else
    VOID ReloadUI_Trampoline(bool);
    VOID ReloadUI_Detour(bool UseINI)
    {
        DebugTry(ReloadUI_Trampoline(UseINI));
        Benchmark(bmPluginsReloadUI,DebugTry(PluginsReloadUI()));
    }
	#endif

    /* This function is still in the client; however, it was phased out as of 
    the Omens of War Expansion

    bool GetWorldFilePath_Trampoline(char *, char *);
    bool GetWorldFilePath_Detour(char *Filename, char *FullPath)
    {
        if (!_stricmp(FullPath,"bmpwad8.s3d"))
        {
            sprintf_s(Filename,"%s\\bmpwad8.s3d",gszINIPath);
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

void __cdecl DrawHUD_Trampoline(unsigned short, unsigned short, PVOID, unsigned int); 
void __cdecl DrawHUD_Detour(unsigned short a,unsigned short b,PVOID c,unsigned int d) 
{ 
    DrawHUDParams[0]=a+gNetStatusXPos;
    DrawHUDParams[1]=b+gNetStatusYPos;
    DrawHUDParams[2]=(DWORD)c;
    DrawHUDParams[3]=d;
    if (gbHUDUnderUI || gbAlwaysDrawMQHUD)
        return;
    DrawHUD_Trampoline(a,b,c,d);
    Benchmark(bmPluginsDrawHUD,PluginsDrawHUD());
    if (HMODULE hmEQPlayNice=GetModuleHandle("EQPlayNice.dll"))
    {
        if (fMQPulse pEQPlayNicePulse=(fMQPulse)GetProcAddress(hmEQPlayNice,"Compat_DrawIndicator"))
            pEQPlayNicePulse();
    }
    return;
} 

void DrawHUD()
{
	if (gGameState == GAMESTATE_INGAME || gGameState == GAMESTATE_CHARSELECT) {//no point in drawing hud anywhere else
		if (gbAlwaysDrawMQHUD || (gGameState == GAMESTATE_INGAME && gbHUDUnderUI && gbShowNetStatus))
		{
			if (DrawHUDParams[0] && gGameState == GAMESTATE_INGAME && gbShowNetStatus)
			{
				DrawHUD_Trampoline((unsigned short)DrawHUDParams[0], (unsigned short)DrawHUDParams[1], (PVOID)DrawHUDParams[2], DrawHUDParams[3]);
				DrawHUDParams[0] = 0;
			}
			Benchmark(bmPluginsDrawHUD, PluginsDrawHUD());
			if (HMODULE hmEQPlayNice = GetModuleHandle("EQPlayNice.dll"))
			{
				if (fMQPulse pEQPlayNicePulse = (fMQPulse)GetProcAddress(hmEQPlayNice, "Compat_DrawIndicator"))
					pEQPlayNicePulse();
			}

		}
		else
			DrawHUDParams[0] = 0;
	}
}

VOID DrawHUDText(PCHAR Text, DWORD X, DWORD Y, DWORD Argb, DWORD Font)
{
	//Add Anonymize logic here.
	if (gAnonymize) {
		if (PCHARINFO pChar = GetCharInfo()) {
			PSPAWNINFO pSpawn = (PSPAWNINFO)pSpawnList;
			char word[MAX_STRING] = "";
			while (pSpawn) {
				if (pSpawn->Type != SPAWN_NPC || (pSpawn->Type == SPAWN_NPC && pSpawn->MasterID)) {
					while (strstr(Text, pSpawn->DisplayedName)) {
						int EntEnd = (int)(strstr(Text, pSpawn->DisplayedName) - Text + strlen(pSpawn->DisplayedName));
						int EntStart = (int)(strstr(Text, pSpawn->DisplayedName) - Text);
						int namelen = EntEnd - EntStart;
						strncpy_s(word, &Text[EntStart], EntEnd - EntStart);
						if (!Anonymize(word, MAX_STRING, 2)) {//try to anonymize word, if I fail, then replace the word with asterix.
							for (int i = EntStart + 1; i < EntEnd - 1; i++) {
								Text[i] = '*';
							}
						}
						else {//if the word gets anonymized, lets build the new output string, nessesary for Anonymize where AnonymizeFlag=1
							char *firsthalf = new char[MAX_STRING];
							strncpy_s(firsthalf, MAX_STRING, &Text[0], EntStart);//copy the first half of the string and store it here.
							char *secondhalf = new char[MAX_STRING];
							strncpy_s(secondhalf, MAX_STRING, &Text[EntEnd], strlen(Text));//copy the part after the word and store it here.
							strcat_s(firsthalf, MAX_STRING, word);//concatinate the word to the first half
							strcat_s(firsthalf, MAX_STRING, secondhalf);//concatinate the second half to the end of the firsthalf+word.
							strcpy_s(Text, MAX_STRING, firsthalf);//store the newly built string as the Text to output.
							delete[] firsthalf;
							delete[] secondhalf;
						}
					}
				}
				pSpawn = pSpawn->pNext;
			}
		}
	}
    DWORD sX=((PCXWNDMGR)pWndMgr)->ScreenExtentX;
    DWORD sY=((PCXWNDMGR)pWndMgr)->ScreenExtentY;

	if (CTextureFont* pFont = pWndMgr->GetFont(Font)) {
		//if (Font != 2 && Font < 12)
			//pFont->FontStyle = Font;

		pFont->DrawWrappedText(CXStr(Text), X, Y, sX - X, CXRect(X, Y, sX, sY), Argb, 1, 0);
		//pFont->DrawWrappedText(&CXStr((char*)Text), X, Y, sX - X, &CXRect(X, Y, sX, sY), Argb, 1, 0);
		//pFont->FontStyle = 2; // reset back to 2 or it screws up other HUD sizes
	}
}
#endif

class EQ_LoadingSHook
{
public:

    VOID SetProgressBar_Trampoline(int,char const *);
    VOID SetProgressBar_Detour(int A,char const *B)
    {
        if (gbMQ2LoadingMsg)
            SetProgressBar_Trampoline(A, OurCaption);
        else
            SetProgressBar_Trampoline(A,B);
    }
};

//DETOUR_TRAMPOLINE_EMPTY(bool CDisplayHook::GetWorldFilePath_Trampoline(char *, char *)); 
DETOUR_TRAMPOLINE_EMPTY(VOID EQ_LoadingSHook::SetProgressBar_Trampoline(int, char const *)); 
DETOUR_TRAMPOLINE_EMPTY(void DrawHUD_Trampoline(unsigned short,unsigned short,PVOID,unsigned int)); 
DETOUR_TRAMPOLINE_EMPTY(VOID CDisplayHook::CleanUI_Trampoline(VOID)); 
#if !defined(ROF2EMU) && !defined(UFEMU)
DETOUR_TRAMPOLINE_EMPTY(VOID CDisplayHook::ReloadUI_Trampoline(bool, bool)); 
#else
DETOUR_TRAMPOLINE_EMPTY(VOID CDisplayHook::ReloadUI_Trampoline(bool)); 
#endif
std::list<std::string>oldstrings;

#ifdef ISXEQ
int CMD_NetStatusXPos(int argc, char *argv[])
{
	PSPAWNINFO pChar = (PSPAWNINFO)pLocalPlayer;
	CHAR szTemp[MAX_STRING] = { 0 };
	PCHAR szLine = ISXEQArgToMQ2Arg(argc, argv, szTemp, MAX_STRING);
#else
VOID NetStatusXPos(PSPAWNINFO pChar, char *szLine)
{
#endif
	CHAR szArg[MAX_STRING] = { 0 };
	CHAR szCmd[MAX_STRING] = { 0 };

	if (szLine[0] != '\0') {
		gNetStatusXPos = strtol(GetArg(szArg, szLine, 1), 0, 0);
		WriteChatf("\ayNetStatus XPos is \ax\at%d\ax", gNetStatusXPos);
		_itoa_s(gNetStatusXPos, szCmd, 10); WritePrivateProfileString("MacroQuest", "NetStatusXPos", szCmd, gszINIFilename);
	}
	RETURN(0);
}
#ifdef ISXEQ
int CMD_NetStatusYPos(int argc, char *argv[])
{
	PSPAWNINFO pChar = (PSPAWNINFO)pLocalPlayer;
	CHAR szTemp[MAX_STRING] = { 0 };
	PCHAR szLine = ISXEQArgToMQ2Arg(argc, argv, szTemp, MAX_STRING);
#else
VOID NetStatusYPos(PSPAWNINFO pChar, char *szLine)
{
#endif
	CHAR szArg[MAX_STRING] = { 0 };
	CHAR szCmd[MAX_STRING] = { 0 };

	if (szLine[0] != '\0') {
		gNetStatusYPos = strtol(GetArg(szArg, szLine, 1), 0, 0);
		WriteChatf("\ayNetStatus YPos is \ax\at%d\ax", gNetStatusYPos);
		_itoa_s(gNetStatusYPos, szCmd, 10);
		WritePrivateProfileString("MacroQuest", "NetStatusYPos", szCmd, gszINIFilename);
	}
	RETURN(0);
}

VOID InitializeDisplayHook()
{
	//this needs further investigation - eqmule
#if 0
#ifdef EQ_LoadingS__Array_x
    if (gbMQ2LoadingMsg)
    {
		oldstrings.clear();
        char **ptr = (char **) EQ_LoadingS__Array;
        int i;

		for (i = 0; i < EQ_LoadingS__ArraySize; i++) {
			oldstrings.push_back(ptr[i]);
			ptr[i] = OurCaption;
		}
    }
#endif
#endif
    DebugSpew("Initializing Display Hooks");

    EzDetourwName(CDisplay__CleanGameUI,&CDisplayHook::CleanUI_Detour,&CDisplayHook::CleanUI_Trampoline,"CDisplay__CleanGameUI");
	EzDetourwName(CDisplay__ReloadUI,&CDisplayHook::ReloadUI_Detour,&CDisplayHook::ReloadUI_Trampoline,"CDisplay__ReloadUI");
	//EzDetourwName(CDisplay__GetWorldFilePath,&CDisplayHook::GetWorldFilePath_Detour,&CDisplayHook::GetWorldFilePath_Trampoline,"CDisplay__GetWorldFilePath");
#ifndef ISXEQ
    EzDetourwName(DrawNetStatus,DrawHUD_Detour,DrawHUD_Trampoline,"DrawNetStatus");
#endif
    //EzDetourwName(EQ_LoadingS__SetProgressBar,&EQ_LoadingSHook::SetProgressBar_Detour,&EQ_LoadingSHook::SetProgressBar_Trampoline,"EQ_LoadingS__SetProgressBar");
#ifndef ISXEQ
	AddCommand("/netstatusxpos", NetStatusXPos);
	AddCommand("/netstatusypos", NetStatusYPos);
#endif
}

VOID ShutdownDisplayHook()
{
#if 0
#ifdef EQ_LoadingS__Array_x
    if (gbMQ2LoadingMsg)
    {
        char **ptr = (char **) EQ_LoadingS__Array;
		int j = 0;
		for(std::list<std::string>::iterator i = oldstrings.begin();i!=oldstrings.end();i++) {
		//for (i = 0; i < EQ_LoadingS__ArraySize; i++) {
			std::string stuff = *i;
			ptr[j++] = (char*)stuff.c_str();
		}
    }
#endif
#endif
    PluginsCleanUI();
    DebugSpew("Shutting down Display Hooks");

#ifndef ISXEQ
	RemoveCommand("/netstatusxpos");
	RemoveCommand("/netstatusypos");
#endif

    RemoveDetour(CDisplay__CleanGameUI);
    RemoveDetour(CDisplay__ReloadUI);
#ifndef ISXEQ
    RemoveDetour(DrawNetStatus);
#endif
    //RemoveDetour(EQ_LoadingS__SetProgressBar);
    //RemoveDetour(CDisplay__GetWorldFilePath);
}
