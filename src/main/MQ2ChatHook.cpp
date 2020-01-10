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

class CChatHook
{
public:
	// ChatManagerClient::DisplaychatText(
	void Trampoline(const char* szMsg, DWORD dwColor, bool, bool, CXStr* SomeStr);
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
				// don't need to anonymize system messages
				if (gAnonymize && dwColor != 269)
				{
					// FIXME: These buffers really should be of reasonable sizes.
					auto pAnonMsg = std::make_unique<char[]>(MAX_STRING);

					char* szAnonMsg = pAnonMsg.get();
					strcpy_s(szAnonMsg, MAX_STRING, szMsg);
					int len = strlen(szAnonMsg);

					//Anonymize my name, and any other PC spawn in the zone.
					SPAWNINFO* pSpawn = (SPAWNINFO*)pSpawnList;

					auto pWord = std::make_unique<char[]>(MAX_STRING);
					char* word = pWord.get();

					while (pSpawn)
					{
						if (pSpawn->Type != SPAWN_NPC
							|| (pSpawn->Type == SPAWN_NPC && pSpawn->MasterID))
						{
							while (strstr(szAnonMsg, pSpawn->DisplayedName))
							{
								// FIXME: Dedupe with other blocks of the same code.
								int EntEnd = (int)(strstr(szAnonMsg, pSpawn->DisplayedName) - szAnonMsg + strlen(pSpawn->DisplayedName));
								int EntStart = (int)(strstr(szAnonMsg, pSpawn->DisplayedName) - szAnonMsg);
								int namelen = EntEnd - EntStart;
								strncpy_s(word, MAX_STRING, &szAnonMsg[EntStart], EntEnd - EntStart);

								// try to anonymize word, if I fail, then replace the word with asterisk.
								if (!Anonymize(word, MAX_STRING, 2))
								{
									for (int i = EntStart + 1; i < EntEnd - 1; i++)
									{
										szAnonMsg[i] = '*';
									}
								}
								else
								{
									// if the word gets anonymized, lets build the new output string, nessesary for Anonymize where AnonymizeFlag=1
									char* firsthalf = new char[MAX_STRING];
									char* secondhalf = new char[MAX_STRING];

									// copy the first half of the string and store it here.
									strncpy_s(firsthalf, MAX_STRING, &szAnonMsg[0], EntStart);

									// copy the part after the word and store it here.
									strncpy_s(secondhalf, MAX_STRING, &szAnonMsg[EntEnd], strlen(szAnonMsg));

									// concatenate the word to the first half
									strcat_s(firsthalf, MAX_STRING, word);

									// concatenate the second half to the end of the firsthalf+word.
									strcat_s(firsthalf, MAX_STRING, secondhalf);

									// store the newly built string as the szAnonMsg to output.
									strcpy_s(szAnonMsg, MAX_STRING, firsthalf);

									delete[] firsthalf;
									delete[] secondhalf;
								}
							}
						}
						pSpawn = pSpawn->pNext;
					}

					switch (dwColor)
					{
					case 13: // Color: 13 - Attack is on/off - Other invites to raid.
					case 256: // Color: 256 - Other player /say messages
					case 257: // Color: 257 - Other /tell's you
					case 258: // Color: 258 - Other tells /group
					case 259: // Color: 259 - Guild Chat - Incoming
					case 279: // Color: 279 - Others Hits Other
					case 280: // Color: 280 - Other Misses Other
					case 291: // Color: 291 - Chat Channel 1 - Incoming
					case 292: // Color: 292 - Chat Channel 2 - Incoming
					case 293: // Color: 293 - Chat Channel 3 - Incoming
					case 294: // Color: 294 - Chat Channel 4 - Incoming
					case 295: // Color: 295 - Chat Channel 5 - Incoming
					case 296: // Color: 296 - Chat Channel 6 - Incoming
					case 297: // Color: 297 - Chat Channel 7 - Incoming
					case 298: // Color: 298 - Chat Channel 8 - Incoming
					case 299: // Color: 299 - Chat Channel 9 - Incoming
					case 300: // Color: 300 - Chat Channel 10 - Incoming
					case 309: // Color: 309 - Group conversation
					case 310: // Color: 310 - Guild conversation - Outgoing
					case 327: // Color: 327 - Any /rsay
					case 330: // Color: 330 - Raid Role messages.
					case 342: // Color: 342 - fellowship messages
					case 343: // Color: 343 - corpse emote
					case 345: // Color: 345 - Guild plants banner
						if (char* pDest = strchr(szAnonMsg, ' '))
						{
							int len = strlen(szAnonMsg) - strlen(pDest);
							if (len >= 2)
							{
								if (szAnonMsg[0] == 0x12)
								{
									for (int i = 3; i < len - 2; i++)
									{
										szAnonMsg[i] = '*';
									}
								}

							}
						}
						break;

					case 273: // Color: 273 - Charged mercenary upkeep/Group Invites/Joins/Banker tells you welcome to bank.
						// If you accept an invite from someone not current in the zone, make sure you catch the accept message
						if (strstr(szAnonMsg, " that you agree to join the group.")
							&& strstr(szAnonMsg, "You notify "))
						{
							int EntEnd = (int)(strstr(szAnonMsg, " that you agree to join the group.") - szAnonMsg);
							int EntStart = (int)(strstr(szAnonMsg, "You notify ") - szAnonMsg + strlen("You notify "));

							for (int i = EntStart + 1; i < EntEnd - 1; i++)
							{
								szAnonMsg[i] = '*';
							}
						}

						// PlayerName has left the group
						if (strstr(szAnonMsg, " has left the group."))
						{
							int EntEnd = (int)(strstr(szAnonMsg, " has left the group.") - szAnonMsg);
							int EntStart = 0;

							for (int i = EntStart + 1; i < EntEnd - 1; i++)
							{
								szAnonMsg[i] = '*';
							}
						}

						// PlayerName has left the group
						if (strstr(szAnonMsg, "You invite ")
							&& strstr(szAnonMsg, " to join your group."))
						{
							int EntEnd = (int)(strstr(szAnonMsg, " to join your group.") - szAnonMsg);
							int EntStart = (int)(strstr(szAnonMsg, "You invite ") - szAnonMsg + strlen("You invite "));;

							for (int i = EntStart + 1; i < EntEnd - 1; i++)
							{
								szAnonMsg[i] = '*';
							}
						}
						break;

					case 349: // Color: 349 - Achievement - Guildmate
						if (strstr(szAnonMsg, " has completed ") && strstr(szAnonMsg, "Your guildmate "))
						{
							int EntEnd = (int)(strstr(szAnonMsg, " has completed ") - szAnonMsg);
							int EntStart = (int)(strstr(szAnonMsg, "Your guildmate ") - szAnonMsg + strlen("Your guildmate "));

							for (int i = EntStart + 1; i < EntEnd - 1; i++)
							{
								szAnonMsg[i] = '*';
							}
						}
						break;

					default:
						//WriteChatf("Color: %i Message: %s", dwColor, szMsg);
						break;
					}

					if (szAnonMsg)
					{
						Trampoline(szAnonMsg, dwColor, EqLog, dopercentsubst, SomeStr);
					}
				}
				else
				{
					Trampoline(szMsg, dwColor, EqLog, dopercentsubst, SomeStr);
				}
			}
		}

		gbInChat = false;
	}

	// ChatManagerClient::DisplayTellText
	void TellWnd_Trampoline(const char* message, const char* from, const char* windowtitle, const char* text, int color, bool bLogOk);
	void TellWnd_Detour(const char* message, const char* from, const char* windowtitle, const char* text, int color, bool bLogOk)
	{
		gbInChat = true;
		bool SkipTrampoline = false;

		int len = strlen(message) + 64;
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
			if (gAnonymize)
			{
				char szNameCopy[64];
				strcpy_s(szNameCopy, 64, from);
				if (!Anonymize(szNameCopy, 64))
				{
					for (int i = 1; i < (int)strlen(szNameCopy) - 1; ++i)
					{
						szNameCopy[i] = '*';
					}
				}

				TellWnd_Trampoline(message, szNameCopy, szNameCopy, text, color, bLogOk);
			}
			else
			{
				TellWnd_Trampoline(message, from, windowtitle, text, color, bLogOk);
			}
		}

		gbInChat = false;
	}

	// CEverQuest::UniversalChatProxyNotificationFlush
	void UPCNotificationFlush_Trampoline();
	void UPCNotificationFlush_Detour()
	{
		EVERQUEST* eq = (EVERQUEST*)this;

		char szBuf[128] = { 0 };

		if (eq->ChannelQty > 0)
		{
			sprintf_s(szBuf, "* %s has %s channel ", eq->ChannelPlayerName, eq->bJoinedChannel ? "entered" : "left");

			char szTemp[MAX_STRING] = { 0 };
			int max = std::min<int>(eq->ChannelQty, 9);

			for (int index = 0; index < max; index++)
			{
				if (index)
				{
					sprintf_s(szTemp, ", %s:%d", eq->ChannelName[index], eq->ChannelNumber[index] + 1);
				}
				else
				{
					sprintf_s(szTemp, "%s:%d", eq->ChannelName[index], eq->ChannelNumber[index] + 1);
				}

				strcat_s(szBuf, szTemp);
			}

			CheckChatForEvent(szBuf);
		}

		UPCNotificationFlush_Trampoline();
	}
};

DETOUR_TRAMPOLINE_EMPTY(void CChatHook::Trampoline(const char* szMsg, DWORD dwColor, bool EqLog, bool dopercentsubst, CXStr* outStr));
DETOUR_TRAMPOLINE_EMPTY(void CChatHook::TellWnd_Trampoline(const char* message, const char* from, const char* windowtitle, const char* text, int color, bool bLogOk));
DETOUR_TRAMPOLINE_EMPTY(void CChatHook::UPCNotificationFlush_Trampoline());

void dsp_chat_no_events(const char* Text, int Color, bool doLog, bool doPercentConvert)
{
	pEverQuest.get_as<CChatHook>()->Trampoline(Text, Color, doLog, doPercentConvert, nullptr);
}

unsigned int CALLBACK MQ2DataVariableLookup(char* VarName, char* Value, size_t ValueLen)
{
	strcpy_s(Value, ValueLen, VarName);

	if (CHARINFO* pChar = GetCharInfo())
	{
		return strlen(ParseMacroParameter(pChar->pSpawn, Value, ValueLen));
	}

	return strlen(Value);
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
