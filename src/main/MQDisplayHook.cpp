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

#include "ImGuiManager.h"
#include "MQ2Main.h"
#include "MQPluginHandler.h"

using namespace eqlib;

namespace mq {

const char* g_customCaption = "MacroQuest: Even when you're loading.";

struct DrawNetStatusParams
{
	bool valid;
	uint16_t x;
	uint16_t y;
	void* udpConnection;
	uint32_t bps;
};
static DrawNetStatusParams s_drawNetStatusParams = { false, 0, 0, nullptr, 0 };

DETOUR_TRAMPOLINE_DEF(void, DrawNetStatus_Trampoline, (uint16_t x, uint16_t y, void* udpConnection, uint32_t bps))
void DrawNetStatus_Detour(uint16_t x, uint16_t y, void* udpConnection, uint32_t bps)
{
	if (gbHUDUnderUI || gbAlwaysDrawMQHUD)
	{
		s_drawNetStatusParams.valid = true;
		s_drawNetStatusParams.x = x;
		s_drawNetStatusParams.y = y;
		s_drawNetStatusParams.udpConnection = udpConnection;
		s_drawNetStatusParams.bps = bps;
		return;
	}

	s_drawNetStatusParams.valid = false;

	DrawNetStatus_Trampoline(x + gNetStatusXPos, y + gNetStatusXPos, udpConnection, bps);

	{
		MQScopedBenchmark bm(bmPluginsDrawHUD);
		PluginsDrawHUD();
	}
}

void DrawHUD()
{
	// no point in drawing hud anywhere else
	if (gGameState == GAMESTATE_INGAME || gGameState == GAMESTATE_CHARSELECT)
	{
		if (gbAlwaysDrawMQHUD || (gGameState == GAMESTATE_INGAME && gbHUDUnderUI && pEverQuestInfo->bNetstat))
		{
			if (s_drawNetStatusParams.valid && gGameState == GAMESTATE_INGAME && pEverQuestInfo->bNetstat)
			{
				DrawNetStatus_Trampoline(s_drawNetStatusParams.x + gNetStatusXPos, s_drawNetStatusParams.y + gNetStatusYPos,
					s_drawNetStatusParams.udpConnection, s_drawNetStatusParams.bps);
				s_drawNetStatusParams.valid = false;
			}

			{
				MQScopedBenchmark bm(bmPluginsDrawHUD);
				PluginsDrawHUD();
			}
		}
		else
		{
			s_drawNetStatusParams.valid = false;
		}
	}
}

void ResetHUD()
{
	s_drawNetStatusParams.valid = false;
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

static void Cmd_NetStatusXPos(PlayerClient* pChar, char* szLine)
{
	if (szLine[0])
	{
		char szArg[MAX_STRING] = { 0 };
		gNetStatusXPos = GetIntFromString(GetArg(szArg, szLine, 1), gNetStatusXPos);
		WriteChatf("\ayNetStatus XPos is \ax\at%d\ax", gNetStatusXPos);

		WritePrivateProfileInt("MacroQuest", "NetStatusXPos", gNetStatusXPos, mq::internal_paths::MQini);
	}
}

static void Cmd_NetStatusYPos(PlayerClient* pChar, char* szLine)
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

	EzDetour(DrawNetStatus, DrawNetStatus_Detour, DrawNetStatus_Trampoline);

	AddCommand("/netstatusxpos", Cmd_NetStatusXPos);
	AddCommand("/netstatusypos", Cmd_NetStatusYPos);
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

	RemoveDetour(DrawNetStatus);
}

} // namespace mq
