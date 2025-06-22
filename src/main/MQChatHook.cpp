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
#include "MQMain.h"

#include <fmt/chrono.h>

using namespace eqlib;

namespace mq {

#if HAS_CHAT_TIMESTAMPS
bool gbTimeStampChat = false;
#endif
static bool s_noFilterChat = false;

bool gbBeepOnTells = false;
bool gbFlashOnTells = true;
bool gbInChat = false;

static bool HandleChatMessage(eqlib::ChatMessageParams& params)
{
	if (s_noFilterChat)
		return true;

	gbInChat = true;

	bool filtered = false;
	MQFilter* filter = gpFilters;

	while (filter && !filtered)
	{
		if (!filter->pEnabled || *filter->pEnabled)
		{
			if (*filter->FilterText == '*')
			{
				if (strstr(params.message, filter->FilterText + 1))
					filtered = true;
			}
			else
			{
				if (!_strnicmp(params.message, filter->FilterText, filter->Length))
					filtered = true;
			}
		}
		filter = filter->pNext;
	}

	filtered = g_mq->HandleIncomingChat(params.message, params.color, false) || filtered;

#if HAS_CHAT_TIMESTAMPS
	if (gbTimeStampChat && !filtered)
	{
		time_t curr_time;
		time(&curr_time);

		std::tm local_tm;
		localtime_s(&local_tm, &curr_time);

		fmt::memory_buffer buffer;
		auto out = fmt::format_to(fmt::appender(buffer),
			"[{:02d}:{:02d}:{:02d}] {}\0", local_tm.tm_hour, local_tm.tm_min, local_tm.tm_sec, params.message);
		*out = 0;

		params.message = buffer.data();
		params.messageHandler(params);

		filtered = true; // not technically filtered, but we don't want to display it twice.
	}
#endif // HAS_CHAT_TIMESTAMPS

	// Call original chat handler here so we can close it off by resetting gbInChat.
	if (!filtered)
	{
		params.messageHandler(params);
	}

	gbInChat = false;
	return false;
}

static bool HandleTellWindowMessage(eqlib::TellWindowMessageParams& params)
{
	if (s_noFilterChat)
		return true;

	gbInChat = true;

	fmt::memory_buffer buffer;
	auto iter = fmt::format_to(fmt::appender(buffer), "{} tells you, '{}'", params.senderName, params.message);
	*iter = 0;

	// FIXME: Should we be applying the filters here?

	bool filtered = g_mq->HandleIncomingChat(buffer.data(), params.color, false);

#if HAS_CHAT_TIMESTAMPS
	if (gbTimeStampChat && !filtered)
	{
		time_t curr_time;
		time(&curr_time);

		std::tm local_tm;
		localtime_s(&local_tm, &curr_time);

		buffer.clear();
		auto out = fmt::format_to(fmt::appender(buffer),
			"[{:02d}:{:02d}:{:02d}] {}", local_tm.tm_hour, local_tm.tm_min, local_tm.tm_sec, params.message);
		*out = 0;

		params.message = buffer.data();
		params.messageHandler(params);

		filtered = true; // not technically filtered, but we don't want to display it twice.
	}
#endif // HAS_CHAT_TIMESTAMPS

	// Call original chat handler here so we can close it off by resetting gbInChat.
	if (!filtered)
	{
		params.messageHandler(params);
	}

	gbInChat = false;
	return filtered;
}

#if HAS_CHAT_TIMESTAMPS
DETOUR_TRAMPOLINE_DEF(void, OutputTextToLog_Trampoline, (const char*));
void OutputTextToLog_Detour(const char* szMsg)
{
	if (gbTimeStampChat && szMsg && *szMsg)
	{
		// if timestamp is on, skip past the ending bracket so that we don't double timestamp the
		// log file.
		if (const char* pDest = strchr(szMsg, ']'))
		{
			if (strlen(szMsg) > (size_t)(pDest - szMsg) + 2)
				szMsg = pDest + 2;
		}
	}

	OutputTextToLog_Trampoline(szMsg);
}
#endif // HAS_CHAT_TIMESTAMPS

void dsp_chat_no_events(const char* message, int color, bool allowLog, bool doPercentConvert)
{
	s_noFilterChat = true;

	if (pEverQuest)
		pEverQuest->dsp_chat(message, color, allowLog, doPercentConvert);

	s_noFilterChat = false;
}

static void Cmd_FlashOnTells(PlayerClient*, char* szLine)
{
	if (szLine[0] != '\0')
	{
		if (!_stricmp(szLine, "on"))
		{
			gbFlashOnTells = false;
		}
		else if (!_stricmp(szLine, "off"))
		{
			gbFlashOnTells = true;
		}
	}

	if (gbFlashOnTells)
	{
		gbFlashOnTells = false;
		WriteChatColor("Flash On Tells is OFF", CONCOLOR_LIGHTBLUE);
	}
	else
	{
		gbFlashOnTells = true;
		WriteChatColor("Flash On Tells is ON", CONCOLOR_YELLOW);
	}

	WritePrivateProfileBool("MacroQuest", "FlashOnTells", gbFlashOnTells, mq::internal_paths::MQini);
}

static void Cmd_BeepOnTells(PlayerClient*, char* szLine)
{
	if (szLine[0] != '\0')
	{
		if (!_stricmp(szLine, "on"))
		{
			gbBeepOnTells = false;
		}
		else if (!_stricmp(szLine, "off"))
		{
			gbBeepOnTells = true;
		}
	}

	if (gbBeepOnTells)
	{
		gbBeepOnTells = false;
		WriteChatColor("Beep On Tells is OFF", CONCOLOR_LIGHTBLUE);
	}
	else
	{
		gbBeepOnTells = true;
		WriteChatColor("Beep On Tells is ON", CONCOLOR_YELLOW);
	}

	WritePrivateProfileBool("MacroQuest", "BeepOnTells", gbBeepOnTells, mq::internal_paths::MQini);
}

#if HAS_CHAT_TIMESTAMPS
static void Cmd_TimestampChat(PlayerClient*, char* szLine)
{
	if (szLine[0] != '\0')
	{
		if (!_stricmp(szLine, "on"))
		{
			gbTimeStampChat = false;
		}
		else if (!_stricmp(szLine, "off"))
		{
			gbTimeStampChat = true;
		}
	}

	if (gbTimeStampChat)
	{
		gbTimeStampChat = false;
		WriteChatColor("Chat Time Stamping is OFF", CONCOLOR_LIGHTBLUE);
	}
	else
	{
		gbTimeStampChat = true;
		WriteChatColor("Chat Time Stamping is ON", CONCOLOR_YELLOW);
	}

	WritePrivateProfileBool("MacroQuest", "TimeStampChat", gbTimeStampChat, mq::internal_paths::MQini);
}

// TODO: When non-emu has settings, pull this out of the ifdef block
static void ChatSettingsPannel()
{
	if (ImGui::Checkbox("Show Timestamps in Chat", &gbTimeStampChat))
	{
		WritePrivateProfileBool("MacroQuest", "TimeStampChat", gbTimeStampChat, mq::internal_paths::MQini);
	}
}
#endif // HAS_CHAT_TIMESTAMPS

static DWORD CALLBACK BeepOnTellThread(void*)
{
	Beep(750, 200);
	return 0;
}

static void TellCheck(const char* szClean)
{
	if (!gbFlashOnTells && !gbBeepOnTells)
		return;

	if (!pLocalPlayer) return;

	char name[MAX_STRING] = { 0 };
	bool isTell = false;
	const char* pDest;

	if ((pDest = strstr(szClean, " tells you, ")))
	{
		strncpy_s(name, szClean, static_cast<int>(pDest - szClean));
		isTell = true;
	}
	else if ((pDest = strstr(szClean, " told you, ")))
	{
		strncpy_s(name, szClean, static_cast<int>(pDest - szClean));
		isTell = true;
	}

	if (!isTell || strlen(name) >= EQ_MAX_NAME)
		return;

	// don't perform action if it's us sending the message
	if (!_stricmp(pLocalPlayer->Name, name))
		return;

	// don't perform action if it's our pet
	if (pLocalPlayer->PetID != -1)
	{
		if (PlayerClient* pPet = GetSpawnByID(pLocalPlayer->PetID))
		{
			if (!_stricmp(pPet->DisplayedName, name))
				return;
		}
	}

	// only react to player tells
	PlayerClient* pNpc = GetSpawnByPartialName(name);
	if (!pNpc && pControlledPlayer != nullptr)
	{
		// try to use spawn search to find it.
		char szSearch[256] = { 0 };
		sprintf_s(szSearch, "npc %s", name);

		MQSpawnSearch ssSpawn;
		ClearSearchSpawn(&ssSpawn);
		ParseSearchSpawn(szSearch, &ssSpawn);

		pNpc = SearchThroughSpawns(&ssSpawn, pControlledPlayer);
	}

	if (pNpc)
	{
		// it's not a player
		if (pNpc->Type != SPAWN_PLAYER)
		{
			return;
		}

		// it's a merchantplayer...
		if (pNpc->Trader || pNpc->Buyer)
		{
			return;
		}
	}

	if (gbFlashOnTells)
	{
		HWND hEQWnd = GetEQWindowHandle();

		if (hEQWnd)
		{
			FLASHWINFO fwi = { sizeof(FLASHWINFO) };
			fwi.dwFlags = FLASHW_ALL;
			fwi.hwnd = hEQWnd;
			fwi.uCount = 3;
			fwi.dwTimeout = 0;
			FlashWindowEx(&fwi);
		}
	}

	if (gbBeepOnTells)
	{
		CreateThread(nullptr, 0, BeepOnTellThread, nullptr, 0, nullptr);
	}
}

//============================================================================

class ChatHookModule : public MQModule
{
public:
	ChatHookModule() : MQModule("ChatHook")
	{
	}

	void LoadSettings()
	{
		gbBeepOnTells = GetPrivateProfileBool("MacroQuest", "BeepOnTells", gbBeepOnTells, mq::internal_paths::MQini);
		gbFlashOnTells = GetPrivateProfileBool("MacroQuest", "FlashOnTells", gbFlashOnTells, mq::internal_paths::MQini);

		if (gbWriteAllConfig)
		{
			WritePrivateProfileBool("MacroQuest", "BeepOnTells", gbBeepOnTells, mq::internal_paths::MQini);
			WritePrivateProfileBool("MacroQuest", "FlashOnTells", gbFlashOnTells, mq::internal_paths::MQini);
		}
	}

	virtual void Initialize() override
	{
		LoadSettings();



		AddCommand("/beepontells", Cmd_BeepOnTells);
		AddCommand("/flashontells", Cmd_FlashOnTells);

#if HAS_CHAT_TIMESTAMPS
		AddCommand("/timestamp", Cmd_TimestampChat);
		EzDetour(CEverQuest__OutputTextToLog, OutputTextToLog_Detour, OutputTextToLog_Trampoline);

		AddSettingsPanel("Chat", ChatSettingsPannel);
#endif
	}

	virtual void Shutdown() override
	{
		RemoveCommand("/flashontells");
		RemoveCommand("/beepontells");

#if HAS_CHAT_TIMESTAMPS
		RemoveCommand("/timestamp");
		RemoveDetour(CEverQuest__OutputTextToLog);

		RemoveSettingsPanel("Chat");
#endif
	}

	virtual bool OnChatMessage(eqlib::ChatMessageParams& params) override
	{
		return HandleChatMessage(params);
	}

	virtual bool OnTellWindowMessage(eqlib::TellWindowMessageParams& params) override
	{
		return HandleTellWindowMessage(params);
	}

	virtual bool OnIncomingChat(const IncomingChatParams& params) override
	{
		// don't know why we check for this.
		if (params.color != USERCOLOR_BROADCAST)
		{
			TellCheck(params.stripped);
		}

		return false;
	}
};

DECLARE_MODULE_FACTORY(ChatHookModule);

} // namespace mq
