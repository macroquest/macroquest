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
#include "eqlib/Events.h"

#include <fmt/chrono.h>

using namespace eqlib;

namespace mq {

#if HAS_CHAT_TIMESTAMPS
bool gbTimeStampChat = false;
#endif
static bool s_noFilterChat = false;

bool HandleChatMessage(eqlib::ChatMessageParams& params)
{
	if (s_noFilterChat)
		return true;

	gbInChat = true;

	if (params.color != USERCOLOR_BROADCAST)
	{
		CheckChatForEvent(params.message);
	}

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

	if (!filtered)
	{
		{
			MQScopedBenchmark bm(bmPluginsIncomingChat);
			filtered = PluginsIncomingChat(params.message, params.color);
		}

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
			params.handleMessage(params);

			filtered = true; // not technically filtered, but we don't want to display it twice.
		}
#endif // HAS_CHAT_TIMESTAMPS

		// Call original chat handler here so we can close it off by resetting gbInChat.
		if (!filtered)
		{
			params.handleMessage(params);
		}
	}

	gbInChat = false;
	return false;
}

bool HandleTellWindowMessage(eqlib::TellWindowMessageParams& params)
{
	if (s_noFilterChat)
		return true;

	gbInChat = true;

	fmt::memory_buffer buffer;
	auto iter = fmt::format_to(fmt::appender(buffer), "{} tells you, '{}'", params.senderName, params.message);
	*iter = 0;

	CheckChatForEvent(buffer.data());

	bool filtered;
	{
		MQScopedBenchmark bm(bmPluginsIncomingChat);
		filtered = PluginsIncomingChat(buffer.data(), params.color);
	}

#if HAS_CHAT_TIMESTAMPS
	if (gbTimeStampChat)
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
		params.handleMessage(params);

		filtered = true; // not technically filtered, but we don't want to display it twice.
	}
#endif // HAS_CHAT_TIMESTAMPS

	// Call original chat handler here so we can close it off by resetting gbInChat.
	if (!filtered)
	{
		params.handleMessage(params);
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

	pEverQuest->dsp_chat(message, color, allowLog, doPercentConvert);

	s_noFilterChat = false;
}

unsigned int CALLBACK MQ2DataVariableLookup(char* VarName, char* Value, size_t ValueLen)
{
	strcpy_s(Value, ValueLen, VarName);

	if (pLocalPlayer)
	{
		return static_cast<uint32_t>(strlen(ParseMacroParameter(Value, ValueLen)));
	}

	return static_cast<uint32_t>(strlen(Value));
}

void FlashOnTells(PlayerClient* pChar, char* szLine)
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

void BeepOnTells(PlayerClient* pChar, char* szLine)
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
void TimeStampChat(PlayerClient* pChar, char* szLine)
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
void ChatSettingsPannel()
{
	if (ImGui::Checkbox("Show Timestamps in Chat", &gbTimeStampChat))
	{
		WritePrivateProfileBool("MacroQuest", "TimeStampChat", gbTimeStampChat, mq::internal_paths::MQini);
	}
}
#endif // HAS_CHAT_TIMESTAMPS

void InitializeChatHook()
{
	// initialize Blech
	pEventBlech = new Blech('#', '|', MQ2DataVariableLookup);
	pMQ2Blech = new Blech('#', '|', MQ2DataVariableLookup);

	AddCommand("/beepontells", BeepOnTells);
	AddCommand("/flashontells", FlashOnTells);

#if HAS_CHAT_TIMESTAMPS
	AddCommand("/timestamp", TimeStampChat);
	EzDetour(CEverQuest__OutputTextToLog, OutputTextToLog_Detour, OutputTextToLog_Trampoline);

	AddSettingsPanel("Chat", ChatSettingsPannel);
#endif
}

void ShutdownChatHook()
{
	RemoveCommand("/flashontells");
	RemoveCommand("/beepontells");

#if HAS_CHAT_TIMESTAMPS
	RemoveCommand("/timestamp");
	RemoveDetour(CEverQuest__OutputTextToLog);

	RemoveSettingsPanel("Chat");
#endif

	delete pEventBlech;
	pEventBlech = nullptr;
	delete pMQ2Blech;
	pMQ2Blech = nullptr;
}

} // namespace mq
