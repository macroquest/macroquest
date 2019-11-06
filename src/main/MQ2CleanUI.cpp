/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "pch.h"
#include "MQ2Main.h"

namespace mq {

const char* g_customCaption = "MQ2: Think of it as evolution in action.";

class CDisplayHook
{
public:
	void CleanUI_Trampoline();
	void CleanUI_Detour()
	{
		Benchmark(bmPluginsCleanUI, DebugTry(PluginsCleanUI()));
		DebugTry(CleanUI_Trampoline());
	}

	void ReloadUI_Trampoline(bool);
	void ReloadUI_Detour(bool UseINI)
	{
		DebugTry(ReloadUI_Trampoline(UseINI));
		Benchmark(bmPluginsReloadUI, DebugTry(PluginsReloadUI()));
	}

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

void DrawHUD_Trampoline(unsigned short, unsigned short, void*, unsigned int);
void DrawHUD_Detour(unsigned short a, unsigned short b, void* c, unsigned int d)
{
	DrawHUDParams[0] = a + gNetStatusXPos;
	DrawHUDParams[1] = b + gNetStatusYPos;
	DrawHUDParams[2] = (DWORD)c;
	DrawHUDParams[3] = d;

	if (gbHUDUnderUI || gbAlwaysDrawMQHUD)
		return;
	DrawHUD_Trampoline(a, b, c, d);
	Benchmark(bmPluginsDrawHUD, PluginsDrawHUD());

	if (HMODULE hmEQPlayNice = GetModuleHandle("EQPlayNice.dll"))
	{
		if (fMQPulse pEQPlayNicePulse = (fMQPulse)GetProcAddress(hmEQPlayNice, "Compat_DrawIndicator"))
			pEQPlayNicePulse();
	}
}

void DrawHUD()
{
	// no point in drawing hud anywhere else
	if (gGameState == GAMESTATE_INGAME || gGameState == GAMESTATE_CHARSELECT)
	{
		if (gbAlwaysDrawMQHUD || (gGameState == GAMESTATE_INGAME && gbHUDUnderUI && gbShowNetStatus))
		{
			if (DrawHUDParams[0] && gGameState == GAMESTATE_INGAME && gbShowNetStatus)
			{
				DrawHUD_Trampoline((unsigned short)DrawHUDParams[0], (unsigned short)DrawHUDParams[1], (void*)DrawHUDParams[2], DrawHUDParams[3]);
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
		{
			DrawHUDParams[0] = 0;
		}
	}
}

void DrawHUDText(const char* Text, int X, int Y, unsigned int Argb, int Font)
{
	CTextureFont* pFont = pWndMgr->GetFont(Font);
	if (!pFont)
		return;

	int sX = pWndMgr->ScreenExtentX;
	int sY = pWndMgr->ScreenExtentY;

	// Add Anonymize logic here.
	if (gAnonymize)
	{
		if (CHARINFO* pChar = GetCharInfo())
		{
			SPAWNINFO* pSpawn = (SPAWNINFO*)pSpawnList;

			char word[MAX_STRING] = { 0 };
			char szText[MAX_STRING] = { 0 };

			strcpy_s(szText, Text);

			while (pSpawn)
			{
				if (pSpawn->Type != SPAWN_NPC
					|| (pSpawn->Type == SPAWN_NPC && pSpawn->MasterID))
				{
					// FIXME: Deduplicate this code

					while (strstr(szText, pSpawn->DisplayedName))
					{
						int EntEnd = (int)(strstr(szText, pSpawn->DisplayedName) - szText + strlen(pSpawn->DisplayedName));
						int EntStart = (int)(strstr(szText, pSpawn->DisplayedName) - szText);
						int namelen = EntEnd - EntStart;

						strncpy_s(word, &szText[EntStart], EntEnd - EntStart);

						if (!Anonymize(word, MAX_STRING, 2))
						{
							// try to anonymize word, if I fail, then replace the word with asterisk.
							for (int i = EntStart + 1; i < EntEnd - 1; i++)
							{
								szText[i] = '*';
							}
						}
						else
						{
							// if the word gets anonymized, lets build the new output string, nessesary for Anonymize where AnonymizeFlag=1
							char* firsthalf = new char[MAX_STRING];

							// copy the first half of the string and store it here.
							strncpy_s(firsthalf, MAX_STRING, &szText[0], EntStart);

							char* secondhalf = new char[MAX_STRING];

							// copy the part after the word and store it here.
							strncpy_s(secondhalf, MAX_STRING, &szText[EntEnd], strlen(szText));

							//concatinate the word to the first half
							strcat_s(firsthalf, MAX_STRING, word);

							// concatenate the second half to the end of the firsthalf+word.
							strcat_s(firsthalf, MAX_STRING, secondhalf);

							// store the newly built string as the szText to output.
							strcpy_s(szText, MAX_STRING, firsthalf);

							delete[] firsthalf;
							delete[] secondhalf;
						}
					}
				}
				pSpawn = pSpawn->pNext;
			}

			pFont->DrawWrappedText(szText, X, Y, sX - X, { X, Y, sX, sY }, Argb, 1, 0);
			return;
		}
	}

	pFont->DrawWrappedText(Text, X, Y, sX - X, { X, Y, sX, sY }, Argb, 1, 0);
}

class EQ_LoadingSHook
{
public:
	void SetProgressBar_Trampoline(int, char const*);
	void SetProgressBar_Detour(int A, char const* B)
	{
		if (gbMQ2LoadingMsg)
			SetProgressBar_Trampoline(A, g_customCaption);
		else
			SetProgressBar_Trampoline(A, B);
	}
};

//DETOUR_TRAMPOLINE_EMPTY(bool CDisplayHook::GetWorldFilePath_Trampoline(char *, char *));
DETOUR_TRAMPOLINE_EMPTY(void EQ_LoadingSHook::SetProgressBar_Trampoline(int, char const*));
DETOUR_TRAMPOLINE_EMPTY(void DrawHUD_Trampoline(unsigned short, unsigned short, void*, unsigned int));
DETOUR_TRAMPOLINE_EMPTY(void CDisplayHook::CleanUI_Trampoline());
DETOUR_TRAMPOLINE_EMPTY(void CDisplayHook::ReloadUI_Trampoline(bool));

static void Cmd_NetStatusXPos(SPAWNINFO* pChar, char* szLine)
{

	if (szLine[0])
	{
		char szArg[MAX_STRING] = { 0 };
		gNetStatusXPos = GetIntFromString(GetArg(szArg, szLine, 1), gNetStatusXPos);
		WriteChatf("\ayNetStatus XPos is \ax\at%d\ax", gNetStatusXPos);

		char szCmd[20] = { 0 };
		_itoa_s(gNetStatusXPos, szCmd, 10);
		WritePrivateProfileString("MacroQuest", "NetStatusXPos", szCmd, gszINIFilename);
	}
}

static void Cmd_NetStatusYPos(SPAWNINFO* pChar, char* szLine)
{

	if (szLine[0])
	{
		char szArg[MAX_STRING] = { 0 };
		gNetStatusYPos = GetIntFromString(GetArg(szArg, szLine, 1), gNetStatusYPos);
		WriteChatf("\ayNetStatus YPos is \ax\at%d\ax", gNetStatusYPos);

		char szCmd[20] = { 0 };
		_itoa_s(gNetStatusYPos, szCmd, 10);
		WritePrivateProfileString("MacroQuest", "NetStatusYPos", szCmd, gszINIFilename);
	}
}

static std::vector<std::string> s_oldStrings;

void InitializeDisplayHook()
{
	DebugSpew("Initializing Display Hooks");

	// TODO: Fix custom loading screen strings
#if defined(EQ_LoadingS__Array_x) && 0
	if (gbMQ2LoadingMsg)
	{
		s_oldStrings.clear();
		const char** ptr = (const char**)EQ_LoadingS__Array;

		for (int i = 0; i < EQ_LoadingS__ArraySize; i++)
		{
			s_oldStrings.emplace_back(ptr[i]);
			ptr[i] = g_customCaption;
		}
	}
#endif

	EzDetourwName(CDisplay__CleanGameUI, &CDisplayHook::CleanUI_Detour, &CDisplayHook::CleanUI_Trampoline, "CDisplay__CleanGameUI");
	EzDetourwName(CDisplay__ReloadUI, &CDisplayHook::ReloadUI_Detour, &CDisplayHook::ReloadUI_Trampoline, "CDisplay__ReloadUI");
	//EzDetourwName(CDisplay__GetWorldFilePath,&CDisplayHook::GetWorldFilePath_Detour,&CDisplayHook::GetWorldFilePath_Trampoline,"CDisplay__GetWorldFilePath");
	EzDetourwName(DrawNetStatus, DrawHUD_Detour, DrawHUD_Trampoline, "DrawNetStatus");
	//EzDetourwName(EQ_LoadingS__SetProgressBar,&EQ_LoadingSHook::SetProgressBar_Detour,&EQ_LoadingSHook::SetProgressBar_Trampoline,"EQ_LoadingS__SetProgressBar");

	AddCommand("/netstatusxpos", Cmd_NetStatusXPos);
	AddCommand("/netstatusypos", Cmd_NetStatusYPos);
}

void ShutdownDisplayHook()
{
	DebugSpew("Shutting down Display Hooks");

	// TODO: Fix custom loading screen strings
#if defined(EQ_LoadingS__Array_x) && 0
	if (gbMQ2LoadingMsg)
	{
		const char** ptr = (const char**)EQ_LoadingS__Array;
		int j = 0;

		for (const std::string& str : s_oldStrings)
		{
			ptr[j++] = str.c_str();
		}
	}
#endif

	PluginsCleanUI();

	RemoveCommand("/netstatusxpos");
	RemoveCommand("/netstatusypos");

	RemoveDetour(CDisplay__CleanGameUI);
	RemoveDetour(CDisplay__ReloadUI);
	RemoveDetour(DrawNetStatus);
	//RemoveDetour(EQ_LoadingS__SetProgressBar);
	//RemoveDetour(CDisplay__GetWorldFilePath);
}

} // namespace mq
