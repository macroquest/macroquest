/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
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
#include "MQPluginHandler.h"

namespace mq {

const char* g_customCaption = "MacroQuest: Even when you're loading.";

class CDisplayHook
{
public:
	DETOUR_TRAMPOLINE_DEF(void, CleanUI_Trampoline, ())
	void CleanUI_Detour()
	{
		{
			MQScopedBenchmark bm(bmPluginsCleanUI);
			PluginsCleanUI();
		}

		CleanUI_Trampoline();
	}

	void ReloadUI_Hook()
	{
		InitializeInGameUI();

		{
			MQScopedBenchmark bm(bmPluginsReloadUI);
			PluginsReloadUI();
		}
	}

#if !IS_EXPANSION_LEVEL(EXPANSION_LEVEL_COTF)
	DETOUR_TRAMPOLINE_DEF(void, ReloadUI_Trampoline, (bool))
	void ReloadUI_Detour(bool UseINI)
	{
		ReloadUI_Trampoline(UseINI);
		ReloadUI_Hook();
	}
#else
	DETOUR_TRAMPOLINE_DEF(void, ReloadUI_Trampoline, (bool, bool))
	void ReloadUI_Detour(bool UseINI, bool bUnknown)
	{
		ReloadUI_Trampoline(UseINI, bUnknown);
		ReloadUI_Hook();
	}
#endif

	DETOUR_TRAMPOLINE_DEF(void, InitCharSelectUI_Trampoline, ())
	void InitCharSelectUI_Detour()
	{
		InitCharSelectUI_Trampoline();
		InitializeInGameUI();
	}
};

DETOUR_TRAMPOLINE_DEF(void, DrawNetStatus_Trampoline, (uint16_t x, uint16_t y, void* udpConnection, uint32_t bps))
void DrawNetStatus_Detour(uint16_t x, uint16_t y, void* udpConnection, uint32_t bps)
{
	DrawHUDParams[0] = x + gNetStatusXPos;
	DrawHUDParams[1] = y + gNetStatusYPos;
	DrawHUDParams[2] = (uintptr_t)udpConnection;
	DrawHUDParams[3] = bps;

	if (gbHUDUnderUI || gbAlwaysDrawMQHUD)
		return;

	DrawNetStatus_Trampoline(x, y, udpConnection, bps);
	Benchmark(bmPluginsDrawHUD, PluginsDrawHUD());
}

void DrawHUD()
{
	// no point in drawing hud anywhere else
	if (gGameState == GAMESTATE_INGAME || gGameState == GAMESTATE_CHARSELECT)
	{
		if (gbAlwaysDrawMQHUD || (gGameState == GAMESTATE_INGAME && gbHUDUnderUI && pEverQuestInfo->bNetstat))
		{
			if (DrawHUDParams[0] && gGameState == GAMESTATE_INGAME && pEverQuestInfo->bNetstat)
			{
				DrawNetStatus_Trampoline((uint16_t)DrawHUDParams[0], (uint16_t)DrawHUDParams[1], (void*)DrawHUDParams[2], (uint32_t)DrawHUDParams[3]);
				DrawHUDParams[0] = 0;
			}

			Benchmark(bmPluginsDrawHUD, PluginsDrawHUD());
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

	pFont->DrawWrappedText(Text, X, Y, sX - X, { X, Y, sX, sY }, Argb, 1, 0);
}

class EQ_LoadingSHook
{
public:
	DETOUR_TRAMPOLINE_DEF(void, SetProgressBar_Trampoline, (int, char const*))
	void SetProgressBar_Detour(int A, char const* B)
	{
		if (gbMQ2LoadingMsg)
			SetProgressBar_Trampoline(A, g_customCaption);
		else
			SetProgressBar_Trampoline(A, B);
	}
};

static void Cmd_NetStatusXPos(SPAWNINFO* pChar, char* szLine)
{
	if (szLine[0])
	{
		char szArg[MAX_STRING] = { 0 };
		gNetStatusXPos = GetIntFromString(GetArg(szArg, szLine, 1), gNetStatusXPos);
		WriteChatf("\ayNetStatus XPos is \ax\at%d\ax", gNetStatusXPos);

		WritePrivateProfileInt("MacroQuest", "NetStatusXPos", gNetStatusXPos, mq::internal_paths::MQini);
	}
}

static void Cmd_NetStatusYPos(SPAWNINFO* pChar, char* szLine)
{
	if (szLine[0])
	{
		char szArg[MAX_STRING] = { 0 };
		gNetStatusYPos = GetIntFromString(GetArg(szArg, szLine, 1), gNetStatusYPos);
		WriteChatf("\ayNetStatus YPos is \ax\at%d\ax", gNetStatusYPos);

		WritePrivateProfileInt("MacroQuest", "NetStatusYPos", gNetStatusYPos, mq::internal_paths::MQini);
	}
}

static std::vector<std::string> s_oldStrings;

void InitializeDisplayHook()
{
	DebugSpew("Initializing Display Hooks");

	// TODO: Fix custom loading screen strings
#if defined(EQ_LoadingS__Array_x) && IS_EXPANSION_LEVEL(EXPANSION_LEVEL_ROF)
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

	EzDetour(CDisplay__CleanGameUI, &CDisplayHook::CleanUI_Detour, &CDisplayHook::CleanUI_Trampoline);
	EzDetour(CDisplay__ReloadUI, &CDisplayHook::ReloadUI_Detour, &CDisplayHook::ReloadUI_Trampoline);
	EzDetour(CDisplay__InitCharSelectUI, &CDisplayHook::InitCharSelectUI_Detour, &CDisplayHook::InitCharSelectUI_Trampoline);
	EzDetour(DrawNetStatus, DrawNetStatus_Detour, DrawNetStatus_Trampoline);

	AddCommand("/netstatusxpos", Cmd_NetStatusXPos);
	AddCommand("/netstatusypos", Cmd_NetStatusYPos);

	if (GetGameState() == GAMESTATE_INGAME)
	{
		InitializeInGameUI();
	}
}

void ShutdownDisplayHook()
{
	DebugSpew("Shutting down Display Hooks");

	// TODO: Fix custom loading screen strings
#if defined(EQ_LoadingS__Array_x) && IS_EXPANSION_LEVEL(EXPANSION_LEVEL_ROF)
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
	RemoveDetour(CDisplay__InitCharSelectUI);
	RemoveDetour(DrawNetStatus);
}

} // namespace mq
