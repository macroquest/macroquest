/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2022 MacroQuest Authors
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

class CChatHook
{
public:
	// ChatManagerClient::DisplaychatText(
	DETOUR_TRAMPOLINE_DEF(void, Trampoline, (const char* szMsg, DWORD dwColor, bool, bool, CXStr* SomeStr))
	void Detour(const char* szMsg, DWORD dwColor, bool EqLog, bool dopercentsubst, CXStr* SomeStr)
	{
		gbInChat = true;
		if (dwColor != 269)
		{
			CheckChatForEvent(szMsg);
		}

		bool Filtered = false;
		MQFilter* Filter = gpFilters;

		while (Filter && !Filtered)
		{
			if (!Filter->pEnabled || *Filter->pEnabled)
			{
				if (*Filter->FilterText == '*')
				{
					if (strstr(szMsg, Filter->FilterText + 1))
						Filtered = true;
				}
				else
				{
					if (!_strnicmp(szMsg, Filter->FilterText, Filter->Length))
						Filtered = true;
				}
			}
			Filter = Filter->pNext;
		}

		if (!Filtered)
		{
			bool SkipTrampoline = false;
			Benchmark(bmPluginsIncomingChat, SkipTrampoline = PluginsIncomingChat(szMsg, dwColor));

			if (!SkipTrampoline)
			{
				Trampoline(szMsg, dwColor, EqLog, dopercentsubst, SomeStr);
			}
		}

		gbInChat = false;
	}

	// ChatManagerClient::DisplayTellText
	DETOUR_TRAMPOLINE_DEF(void, TellWnd_Trampoline, (const char* message, const char* from, const char* windowtitle, const char* text, int color, bool bLogOk))
	void TellWnd_Detour(const char* message, const char* from, const char* windowtitle, const char* text, int color, bool bLogOk)
	{
		gbInChat = true;
		bool SkipTrampoline = false;

		size_t len = strlen(message) + 64;
		auto pBuffer = std::make_unique<char[]>(len);
		char* szMsg = pBuffer.get();

		if (szMsg)
		{
			sprintf_s(szMsg, len, "%s tells you, '%s'", from, message);
			CheckChatForEvent(szMsg);
			Benchmark(bmPluginsIncomingChat, SkipTrampoline = PluginsIncomingChat(szMsg, color));
		}

		if (!SkipTrampoline)
		{
			// TODO: do we need to filter `text`?
			TellWnd_Trampoline(message, from, windowtitle, text, color, bLogOk);
		}

		gbInChat = false;
	}

	// CEverQuest::UniversalChatProxyNotificationFlush
	DETOUR_TRAMPOLINE_DEF(void, UPCNotificationFlush_Trampoline, ())
	void UPCNotificationFlush_Detour()
	{
		CEverQuest* eq = (CEverQuest*)this;
		char szBuf[128] = { 0 };

		if (eq->ucNotificationCount > 0)
		{
			sprintf_s(szBuf, "* %s has %s channel ", eq->ucNotificationPlayerName, eq->ucNotificationEntering ? "entered" : "left");

			char szTemp[MAX_STRING] = { 0 };
			int max = std::min<int>(eq->ucNotificationCount, 9);

			for (int index = 0; index < max; index++)
			{
				if (index)
				{
					sprintf_s(szTemp, ", %s:%d", eq->ucNotificationChannelName[index], eq->ucNotificationChannelNumber[index] + 1);
				}
				else
				{
					sprintf_s(szTemp, "%s:%d", eq->ucNotificationChannelName[index], eq->ucNotificationChannelNumber[index] + 1);
				}

				strcat_s(szBuf, szTemp);
			}

			CheckChatForEvent(szBuf);
		}

		UPCNotificationFlush_Trampoline();
	}
};

void dsp_chat_no_events(const char* Text, int Color, bool doLog, bool doPercentConvert)
{
	pEverQuest.get_as<CChatHook>()->Trampoline(Text, Color, doLog, doPercentConvert, nullptr);
}

unsigned int CALLBACK MQ2DataVariableLookup(char* VarName, char* Value, size_t ValueLen)
{
	strcpy_s(Value, ValueLen, VarName);

	if (pLocalPlayer)
	{
		return static_cast<uint32_t>(strlen(ParseMacroParameter(pLocalPlayer, Value, ValueLen)));
	}

	return static_cast<uint32_t>(strlen(Value));
}

void FlashOnTells(SPAWNINFO* pChar, char* szLine)
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

void BeepOnTells(SPAWNINFO* pChar, char* szLine)
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

void InitializeChatHook()
{
	// initialize Blech
	pEventBlech = new Blech('#', '|', MQ2DataVariableLookup);
	pMQ2Blech = new Blech('#', '|', MQ2DataVariableLookup);

	EzDetour(CEverQuest__dsp_chat, &CChatHook::Detour, &CChatHook::Trampoline);
	EzDetour(CEverQuest__DoTellWindow, &CChatHook::TellWnd_Detour, &CChatHook::TellWnd_Trampoline);
	EzDetour(CEverQuest__UPCNotificationFlush, &CChatHook::UPCNotificationFlush_Detour, &CChatHook::UPCNotificationFlush_Trampoline);
	AddCommand("/beepontells", BeepOnTells);
	AddCommand("/flashontells", FlashOnTells);
}

void ShutdownChatHook()
{
	RemoveCommand("/flashontells");
	RemoveCommand("/beepontells");

	RemoveDetour(CEverQuest__dsp_chat);
	RemoveDetour(CEverQuest__DoTellWindow);
	RemoveDetour(CEverQuest__UPCNotificationFlush);

	delete pEventBlech;
	pEventBlech = nullptr;
	delete pMQ2Blech;
	pMQ2Blech = nullptr;
}

} // namespace mq
