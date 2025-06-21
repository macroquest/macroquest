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

#include "MacroQuest.h"
#include "ModuleSystem.h"
#include "MQ2Main.h"

using namespace eqlib;

namespace mq {

//=================================================================================================
//=================================================================================================
// HUD/DrawNetStatus Hook

bool gbHUDUnderUI = true;
bool gbAlwaysDrawMQHUD = false;
int gNetStatusXPos = 0;
int gNetStatusYPos = 0;

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

	g_mq->OnDrawHUD();
}

static void DrawHUD()
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

			g_mq->OnDrawHUD();
		}
		else
		{
			s_drawNetStatusParams.valid = false;
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

static void Cmd_NetStatusXPos(PlayerClient*, char* szLine)
{
	if (szLine[0])
	{
		char szArg[MAX_STRING] = { 0 };
		gNetStatusXPos = GetIntFromString(GetArg(szArg, szLine, 1), gNetStatusXPos);
		WriteChatf("\ayNetStatus XPos is \ax\at%d\ax", gNetStatusXPos);

		WritePrivateProfileInt("MacroQuest", "NetStatusXPos", gNetStatusXPos, mq::internal_paths::MQini);
	}
}

static void Cmd_NetStatusYPos(PlayerClient*, char* szLine)
{
	if (szLine[0])
	{
		char szArg[MAX_STRING] = { 0 };
		gNetStatusYPos = GetIntFromString(GetArg(szArg, szLine, 1), gNetStatusYPos);
		WriteChatf("\ayNetStatus YPos is \ax\at%d\ax", gNetStatusYPos);

		WritePrivateProfileInt("MacroQuest", "NetStatusYPos", gNetStatusYPos, mq::internal_paths::MQini);
	}
}

static void Cmd_Hud(PlayerClient*, const char* szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /hud <normal|underui|always>");
		WriteChatColor("Note: 'always' forces 'underui' also. The Network Status indicator is not 'always' drawn and is toggled with F11.");
		return;
	}

	if (!_stricmp(szLine, "normal"))
	{
		WritePrivateProfileString("MacroQuest", "HUDMode", "Normal", mq::internal_paths::MQini);
		gbAlwaysDrawMQHUD = false;
		gbHUDUnderUI = false;
	}
	else if (!_stricmp(szLine, "underui"))
	{
		WritePrivateProfileString("MacroQuest", "HUDMode", "UnderUI", mq::internal_paths::MQini);
		gbHUDUnderUI = true;
		gbAlwaysDrawMQHUD = false;
	}
	else if (!_stricmp(szLine, "always"))
	{
		WritePrivateProfileString("MacroQuest", "HUDMode", "Always", mq::internal_paths::MQini);
		gbHUDUnderUI = true;
		gbAlwaysDrawMQHUD = true;
	}
}

class DisplayHookModule : public MQModule
{
public:
	DisplayHookModule() : MQModule("DisplayHook", static_cast<int>(ModulePriority::HUD), ModuleFlags::CanUnload)
	{
	}

	void LoadSettings()
	{
		gNetStatusXPos = GetPrivateProfileInt("MacroQuest", "NetStatusXPos", gNetStatusXPos, mq::internal_paths::MQini);
		gNetStatusYPos = GetPrivateProfileInt("MacroQuest", "NetStatusYPos", gNetStatusYPos, mq::internal_paths::MQini);

		std::string hudMode = GetPrivateProfileString("MacroQuest", "HUDMode", "UnderUI", mq::internal_paths::MQini);

		if (ci_equals(hudMode, "normal"))
		{
			gbAlwaysDrawMQHUD = false;
			gbHUDUnderUI = false;
		}
		else if (ci_equals(hudMode, "always"))
		{
			gbAlwaysDrawMQHUD = true;
			gbHUDUnderUI = true;
		}
		else
		{
			hudMode = "UnderUI";
			gbAlwaysDrawMQHUD = false;
			gbHUDUnderUI = true;
		}

		if (gbWriteAllConfig)
		{
			WritePrivateProfileString("MacroQuest", "HUDMode", hudMode, mq::internal_paths::MQini);
			WritePrivateProfileInt("MacroQuest", "NetStatusXPos", gNetStatusXPos, mq::internal_paths::MQini);
			WritePrivateProfileInt("MacroQuest", "NetStatusYPos", gNetStatusYPos, mq::internal_paths::MQini);
		}
	}

	virtual void Initialize() override
	{
		LoadSettings();

		EzDetour(DrawNetStatus, DrawNetStatus_Detour, DrawNetStatus_Trampoline);

		AddCommand("/hud", Cmd_Hud);
		AddCommand("/netstatusxpos", Cmd_NetStatusXPos);
		AddCommand("/netstatusypos", Cmd_NetStatusYPos);
	}

	virtual void Shutdown() override
	{
		RemoveCommand("/hud");
		RemoveCommand("/netstatusxpos");
		RemoveCommand("/netstatusypos");

		RemoveDetour(DrawNetStatus);
	}

	virtual void OnGameStateChanged(int gameState) override
	{
		UNUSED(gameState);
	
		s_drawNetStatusParams.valid = false;
	}

	virtual void OnProcessFrame() override
	{
		DrawHUD();
	}
};

DECLARE_MODULE_FACTORY(DisplayHookModule);

//=================================================================================================
//=================================================================================================

// LoadingScreen Hook

static const char* s_customCaption = "MacroQuest: Even when you're loading.";
static bool s_customLoadingMsg = true;

class EQ_LoadingSHook
{
public:
	DETOUR_TRAMPOLINE_DEF(void, SetProgressBar_Trampoline, (int, char const*))
		void SetProgressBar_Detour(int A, char const* B)
	{
		if (s_customLoadingMsg)
			SetProgressBar_Trampoline(A, s_customCaption);
		else
			SetProgressBar_Trampoline(A, B);
	}
};

class LoadingScreenModule : public MQModule
{
public:
	LoadingScreenModule() : MQModule("LoadingScreen", static_cast<int>(ModulePriority::Default), ModuleFlags::CanUnload)
	{
	}

	void LoadSettings()
	{
		s_customLoadingMsg = GetPrivateProfileBool("MacroQuest", "MQ2LoadingMsg", s_customLoadingMsg, mq::internal_paths::MQini);

		if (gbWriteAllConfig)
		{
			WritePrivateProfileBool("MacroQuest", "MQ2LoadingMsg", s_customLoadingMsg, mq::internal_paths::MQini);
		}
	}

	virtual void Initialize() override
	{
		LoadSettings();

		// TODO: Fix/improve custom loading screen strings
#if defined(EQ_LoadingS__Array_x) && IS_EXPANSION_LEVEL(EXPANSION_LEVEL_ROF)
		if (s_customLoadingMsg)
		{
			m_oldStrings.clear();
			const char** ptr = (const char**)EQ_LoadingS__Array;

			for (int i = 0; i < EQ_LoadingS__ArraySize; i++)
			{
				m_oldStrings.emplace_back(ptr[i]);
				ptr[i] = s_customCaption;
			}
		}
#endif
	}

	virtual void Shutdown() override
	{
		// TODO: Fix/improve custom loading screen strings
#if defined(EQ_LoadingS__Array_x) && IS_EXPANSION_LEVEL(EXPANSION_LEVEL_ROF)
		if (s_customLoadingMsg)
		{
			const char** ptr = (const char**)EQ_LoadingS__Array;
			int j = 0;

			for (const std::string& str : m_oldStrings)
			{
				ptr[j++] = str.c_str();
			}
		}
#endif
	}

private:
	std::vector<std::string> m_oldStrings;
};

DECLARE_MODULE_FACTORY(LoadingScreenModule);

} // namespace mq
