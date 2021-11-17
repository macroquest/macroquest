/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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
	DetourClassDef(CleanUI, CDisplayHook, void)
	{
		{
			MQScopedBenchmark bm(bmPluginsCleanUI);
			PluginsCleanUI();
		}

		CleanUI_Trampoline();
	}

	DetourClassDef(ReloadUI, CDisplayHook, void, bool UseINI, bool bUnknown)
	{
		ReloadUI_Trampoline(UseINI, bUnknown);
		InitializeInGameUI();

		{
			MQScopedBenchmark bm(bmPluginsReloadUI);

			PluginsReloadUI();
		}
	}

	void InitCharSelectUI_Trampoline();
	void InitCharSelectUI_Detour()
	{
		InitCharSelectUI_Trampoline();
		InitializeInGameUI();
	}
};

DetourDef(DrawNetStatusOvr, void, uint16_t x, uint16_t y, void* udpConnection, uint32_t bps)
{
	DrawHUDParams[0] = x + gNetStatusXPos;
	DrawHUDParams[1] = y + gNetStatusYPos;
	DrawHUDParams[2] = (DWORD)udpConnection;
	DrawHUDParams[3] = bps;

	if (gbHUDUnderUI || gbAlwaysDrawMQHUD)
		return;

	DrawNetStatusOvr_Trampoline(x, y, udpConnection, bps);
	Benchmark(bmPluginsDrawHUD, PluginsDrawHUD());
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
				DrawNetStatusOvr_Trampoline((unsigned short)DrawHUDParams[0], (unsigned short)DrawHUDParams[1], (void*)DrawHUDParams[2], DrawHUDParams[3]);
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
	DetourClassDef(SetProgressBar, EQ_LoadingSHook, void, int A, char const* B)
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

	EasyClassDetour(CDisplay__CleanGameUI, CDisplayHook, CleanUI);
	EasyClassDetour(CDisplay__ReloadUI, CDisplayHook, ReloadUI);
	EasyDetour(DrawNetStatus, DrawNetStatusOvr);

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
	RemoveDetour(CDisplay__InitCharSelectUI);
	RemoveDetour(DrawNetStatus);
}

} // namespace mq
