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


#include "MQ2Main.h"
DWORD __stdcall BeepOnTellThread(PVOID pData)
{
	Beep(750, 200);
	return 0;
}
DWORD __stdcall FlashOnTellThread(PVOID pData)
{
	DWORD lReturn = GetCurrentProcessId();
	DWORD pid = lReturn;
	AllowSetForegroundWindow(pid);
	BOOL ret = EnumWindows(EnumWindowsProc, (LPARAM)&lReturn);
	if (lReturn != pid) {
		//SetForegroundWindow((HWND)lReturn);
		FLASHWINFO fwi = { sizeof(FLASHWINFO) };
		fwi.dwFlags = FLASHW_ALL;
		fwi.hwnd = (HWND)lReturn;
		fwi.uCount = 3;
		fwi.dwTimeout = 0;
		FlashWindowEx(&fwi);
	}
	return 0;
}
#if defined(ROF2EMU) || defined(UFEMU)
VOID OutputTextToLog_Trampoline(char*);
VOID OutputTextToLog_Detour(char*szMsg)
{
	try {
		if (gbTimeStampChat) {
			if (szMsg && szMsg[0]) {
				if (char*pDest = strchr(szMsg, ']')) {
					if (strlen(szMsg) > (size_t)(pDest - szMsg) + 2) {
						szMsg = pDest + 2;
					}
				}
			}
		}
	}
	catch (...) {
		//nm...
	}
	OutputTextToLog_Trampoline(szMsg);
}
#endif
class CChatHook
{
public:
#if !defined(ROF2EMU) && !defined(UFEMU)
	VOID Trampoline(const char* szMsg, DWORD dwColor, bool, bool, char *SomeStr);
	VOID Detour(const char* szMsg, DWORD dwColor, bool EqLog, bool dopercentsubst, char *SomeStr)
#else
	VOID Trampoline(const char * szMsg, DWORD dwColor, bool EqLog, bool dopercentsubst);
	VOID Detour(const char * szMsg, DWORD dwColor, bool EqLog, bool dopercentsubst)
#endif
	{
		//DebugSpew("CChatHook::Detour(%s)",szMsg); 
		gbInChat = TRUE;
		if (dwColor != 269)
		{
			CheckChatForEvent((char*)szMsg);
		}

		BOOL Filtered = FALSE;
		PFILTER Filter = gpFilters;
		while (Filter && !Filtered) {
			if (!Filter->pEnabled || (*Filter->pEnabled)) {
				if (*Filter->FilterText == '*') {
					if (strstr(szMsg, Filter->FilterText + 1))
						Filtered = TRUE;
				}
				else {
					if (!_strnicmp(szMsg, Filter->FilterText, Filter->Length))
						Filtered = TRUE;
				}
			}
			Filter = Filter->pNext;
		}

		if (!Filtered) {
			//if (gTelnetServer && gTelnetConnection && !gPauseTelnetOutput) TelnetServer_Write(szMsg); 
			BOOL SkipTrampoline;
			Benchmark(bmPluginsIncomingChat, SkipTrampoline = PluginsIncomingChat((char*)szMsg, dwColor));
			if (!SkipTrampoline) {
				//WriteChatf("Color: %i Message: %s", dwColor, szMsg);
				if (gAnonymize && dwColor!=269 /*System messages don't need anon*/)
				{
					char *szAnonMsg = new char[MAX_STRING];
					strcpy_s(szAnonMsg,MAX_STRING, szMsg);
					int len = strlen(szAnonMsg);
					//Anonymize my name, and any other PC spawn in the zone.
					PSPAWNINFO pSpawn = (PSPAWNINFO)pSpawnList;
					char *word = new char[MAX_STRING];
					while (pSpawn)
					{
						if (pSpawn->Type != SPAWN_NPC || (pSpawn->Type == SPAWN_NPC && pSpawn->MasterID)) {
							while (strstr(szAnonMsg, pSpawn->DisplayedName)) {
								int EntEnd = (int)(strstr(szAnonMsg, pSpawn->DisplayedName) - szAnonMsg + strlen(pSpawn->DisplayedName));
								int EntStart = (int)(strstr(szAnonMsg, pSpawn->DisplayedName) - szAnonMsg);
								int namelen = EntEnd - EntStart;
								strncpy_s(word, MAX_STRING, &szAnonMsg[EntStart], EntEnd - EntStart);
								if (!Anonymize(word, MAX_STRING, 2)) {//try to anonymize word, if I fail, then replace the word with asterix.
									for (int i = EntStart + 1; i < EntEnd - 1; i++) {
										szAnonMsg[i] = '*';
									}
								}
								else
								{//if the word gets anonymized, lets build the new output string, nessesary for Anonymize where AnonymizeFlag=1
									char *firsthalf = new char[MAX_STRING];
									strncpy_s(firsthalf, MAX_STRING, &szAnonMsg[0], EntStart);//copy the first half of the string and store it here.
									char *secondhalf = new char[MAX_STRING];
									strncpy_s(secondhalf, MAX_STRING, &szAnonMsg[EntEnd], strlen(szAnonMsg));//copy the part after the word and store it here.
									strcat_s(firsthalf, MAX_STRING, word);//concatinate the word to the first half
									strcat_s(firsthalf, MAX_STRING, secondhalf);//concatinate the second half to the end of the firsthalf+word.
									strcpy_s(szAnonMsg, MAX_STRING, firsthalf);//store the newly built string as the szAnonMsg to output.
									delete[] firsthalf;
									delete[] secondhalf;
							}
						}
					}
						pSpawn = pSpawn->pNext;
					}
					delete[] word;
					switch (dwColor) {

					case 13://Color: 13 - Attack is on/off - Other invites to raid.
					case 256://Color: 256 - Other player /say messages	
					case 257://Color: 257 - Other /tell's you
					case 258://Color: 258 - Other tells /group
					case 259://Color: 259 - Guild Chat - Incoming
					case 279://Color: 279 - Others Hits Other
					case 280://Color: 280 - Other Misses Other	
					case 291://Color: 291 - Chat Channel 1 - Incoming
					case 292://Color: 292 - Chat Channel 2 - Incoming
					case 293://Color: 293 - Chat Channel 3 - Incoming
					case 294://Color: 294 - Chat Channel 4 - Incoming
					case 295://Color: 295 - Chat Channel 5 - Incoming
					case 296://Color: 296 - Chat Channel 6 - Incoming
					case 297://Color: 297 - Chat Channel 7 - Incoming
					case 298://Color: 298 - Chat Channel 8 - Incoming
					case 299://Color: 299 - Chat Channel 9 - Incoming
					case 300://Color: 300 - Chat Channel 10 - Incoming
					case 309://Color: 309 - Group conversation
					case 310://Color: 310 - Guild conversation - Outgoing
					case 327://Color: 327 - Any /rsay
					case 330://Color: 330 - Raid Role messages.
					case 342://Color: 342 - fellowship messages
					case 343://Color: 343 - corpse emote
					case 345://Color: 345 - Guild plants banner
						if (char* pDest = strchr(szAnonMsg, ' ')) {
							int len = strlen(szAnonMsg) - strlen(pDest);
							if (len >= 2) {
								if (szAnonMsg[0] == 0x12) {
									for (int i = 3; i < len - 2; i++) {
										szAnonMsg[i] = '*';
									}
								}
								
							}
						}
						break;
					case 273://Color: 273 - Charged mercenary upkeep/Group Invites/Joins/Banker tells you welcome to bank.
						//If you accept an invite from someone not current in the zone, make sure you catch the accept message
						if (strstr(szAnonMsg, " that you agree to join the group.") && strstr(szAnonMsg, "You notify ")) {
							int EntEnd = (int)(strstr(szAnonMsg, " that you agree to join the group.") - szAnonMsg);
							int EntStart = (int)(strstr(szAnonMsg, "You notify ") - szAnonMsg + strlen("You notify "));
							for (int i = EntStart + 1; i < EntEnd - 1; i++) {
											szAnonMsg[i] = '*';
										}
									}
						//PlayerName has left the group
						if (strstr(szAnonMsg, " has left the group.")) {
							int EntEnd = (int)(strstr(szAnonMsg, " has left the group.") - szAnonMsg);
							int EntStart = 0;
							for (int i = EntStart + 1; i < EntEnd - 1; i++) {
											szAnonMsg[i] = '*';
										}
									}
						//PlayerName has left the group
						if (strstr(szAnonMsg, "You invite ") && strstr(szAnonMsg, " to join your group.")) {
							int EntEnd = (int)(strstr(szAnonMsg, " to join your group.") - szAnonMsg);
							int EntStart = (int)(strstr(szAnonMsg, "You invite ") - szAnonMsg + strlen("You invite "));;
							for (int i = EntStart + 1; i < EntEnd - 1; i++) {
								szAnonMsg[i] = '*';
								}
							}
						break;
					case 349://Color: 349 - Achievement - Guildmate
						if (strstr(szAnonMsg, " has completed ") && strstr(szAnonMsg, "Your guildmate ")) {
							int EntEnd = (int)(strstr(szAnonMsg, " has completed ") - szAnonMsg);
							int EntStart = (int)(strstr(szAnonMsg, "Your guildmate ") - szAnonMsg + strlen("Your guildmate "));
							for (int i = EntStart + 1; i < EntEnd - 1; i++) {
								szAnonMsg[i] = '*';
							}
						}
						break;
					default:
						//WriteChatf("Color: %i Message: %s", dwColor, szMsg);
						break;
					}
					

					if (szAnonMsg) {
#if defined(ROF2EMU) || defined(UFEMU)
						if (gbTimeStampChat) {
							CHAR tmpbuf[32] = { 0 };
							_strtime_s(tmpbuf, 32);
							int len = strlen(szAnonMsg);
							char *szTimeStamedMsg = (char *)LocalAlloc(LPTR, len + 64);
							if (szTimeStamedMsg) {
								sprintf_s(szTimeStamedMsg, len + 64, "[%s] %s", tmpbuf, szAnonMsg);
								Trampoline(szTimeStamedMsg, dwColor, EqLog, dopercentsubst);
								LocalFree(szTimeStamedMsg);
								LocalFree(szAnonMsg);
							}
							else {
								Trampoline(szAnonMsg, dwColor, EqLog, dopercentsubst);
								LocalFree(szAnonMsg);
							}
						}
						else {
#endif
#if !defined(ROF2EMU) && !defined(UFEMU)
							Trampoline(szAnonMsg, dwColor, EqLog, dopercentsubst, SomeStr);
#else
							Trampoline(szAnonMsg, dwColor, EqLog, dopercentsubst);
#endif

#if defined(ROF2EMU) || defined(UFEMU)
						}
#endif
					}
					delete[] szAnonMsg;
				}
				else
				{
#if defined(ROF2EMU) || defined(UFEMU)
					if (gbTimeStampChat) {
						CHAR tmpbuf[32] = { 0 };
						_strtime_s(tmpbuf, 32);
						int len = strlen(szMsg);
						char *szTimeStamedMsg = (char *)LocalAlloc(LPTR, len + 64);
						if (szTimeStamedMsg) {
							sprintf_s(szTimeStamedMsg, len + 64, "[%s] %s", tmpbuf, szMsg);
							Trampoline(szTimeStamedMsg, dwColor, EqLog, dopercentsubst);
							LocalFree(szTimeStamedMsg);
						}
						else {
							Trampoline(szMsg, dwColor, EqLog, dopercentsubst);
						}
					}
					else {
#endif
#if !defined(ROF2EMU) && !defined(UFEMU)
						Trampoline(szMsg, dwColor, EqLog, dopercentsubst, SomeStr);
#else
						Trampoline(szMsg, dwColor, EqLog, dopercentsubst);
#endif
#if defined(ROF2EMU) || defined(UFEMU)
					}
#endif
				}
			}
		}
		gbInChat = FALSE;
	}

	VOID TellWnd_Trampoline(char* message, char*from, char*windowtitle, char*text, int color, bool bLogOk);
	VOID TellWnd_Detour(char* message, char*from, char*windowtitle, char*text, int color, bool bLogOk)
	{
		int len = strlen(message);
		char *szMsg = (char *)LocalAlloc(LPTR, len + 64);
		BOOL SkipTrampoline = 0;
		gbInChat = true;
		if (szMsg) {
			sprintf_s(szMsg, len + 64, "%s tells you, '%s'", from, message);
			CheckChatForEvent(szMsg);
			Benchmark(bmPluginsIncomingChat, SkipTrampoline = PluginsIncomingChat(szMsg, color));
		}

		if (!SkipTrampoline) {
#if defined(ROF2EMU) || defined(UFEMU)
			if (gbTimeStampChat && szMsg) {
				CHAR tmpbuf[32] = { 0 };
				_strtime_s(tmpbuf, 32);
				sprintf_s(szMsg, len + 63, "[%s] %s", tmpbuf, from);
				TellWnd_Trampoline(message, from, windowtitle, text, color, bLogOk);
			}
			else {
				TellWnd_Trampoline(message, from, windowtitle, text, color, bLogOk);
			}
#else
			if (gAnonymize) {
				CHAR *szName = new CHAR[64];
				strcpy_s(szName, 64, from);
				if (!Anonymize(szName, 64)) {
					for (int i = 1; i < (int)strlen(szName) - 1; i++) {
						szName[i] = '*';
					}
				}
				TellWnd_Trampoline(message, szName, szName, text, color, bLogOk);
				delete szName;
			}
			else
			{
				TellWnd_Trampoline(message, from, windowtitle, text, color, bLogOk);
			}
#endif
		}
		if (szMsg)
			LocalFree(szMsg);
		gbInChat = false;
	}

	VOID UPCNotificationFlush_Trampoline();
	VOID UPCNotificationFlush_Detour()
	{
		if (PEVERQUEST eq = (PEVERQUEST)this) {
			CHAR szBuf[MAX_STRING] = { 0 };
			if (eq->ChannelQty > 0) {
				int len = 0;
				sprintf_s(szBuf, "* %s has %s channel ", eq->ChannelPlayerName, eq->bJoinedChannel ? "entered" : "left");
				CHAR szTemp[MAX_STRING] = { 0 };
				int max = eq->ChannelQty;
				if (max > 9)
					max = 9;
				for (int i = 0; i < max; i++) {
					if (i) {
						sprintf_s(szTemp, ", %s:%d", eq->ChannelName[i], eq->ChannelNumber[i] + 1);
					}
					else {
						sprintf_s(szTemp, "%s:%d", eq->ChannelName[i], eq->ChannelNumber[i] + 1);
					}
					strcat_s(szBuf, szTemp);
				}
				CheckChatForEvent(szBuf);
			}
		}
		UPCNotificationFlush_Trampoline();
	}
};
#if !defined(ROF2EMU) && !defined(UFEMU)
DETOUR_TRAMPOLINE_EMPTY(VOID CChatHook::Trampoline(const char* szMsg, DWORD dwColor, bool EqLog, bool dopercentsubst, char *SomeStr));
#else
DETOUR_TRAMPOLINE_EMPTY(VOID CChatHook::Trampoline(const char* szMsg, DWORD dwColor, bool EqLog, bool dopercentsubst));
#endif
#if defined(ROF2EMU) || defined(UFEMU)
DETOUR_TRAMPOLINE_EMPTY(VOID OutputTextToLog_Trampoline(char *));
#endif
DETOUR_TRAMPOLINE_EMPTY(VOID CChatHook::TellWnd_Trampoline(char* message, char*from, char*windowtitle, char*text, int color, bool bLogOk));
DETOUR_TRAMPOLINE_EMPTY(VOID CChatHook::UPCNotificationFlush_Trampoline());

#if !defined(ROF2EMU) && !defined(UFEMU)
VOID dsp_chat_no_events(const char *Text, int Color, bool EqLog, bool dopercentsubst, char *SomeStr)
#else
VOID dsp_chat_no_events(const char *Text, int Color, bool EqLog, bool dopercentsubst)
#endif
{
#if !defined(ROF2EMU) && !defined(UFEMU)
	((CChatHook*)pEverQuest)->Trampoline((PCHAR)Text, Color, EqLog, dopercentsubst, SomeStr);
#else
	((CChatHook*)pEverQuest)->Trampoline((PCHAR)Text, Color, EqLog, dopercentsubst);
#endif
}

unsigned int __stdcall MQ2DataVariableLookup(char * VarName, char * Value, size_t ValueLen)
{
	strcpy_s(Value, ValueLen, VarName);
	if (PCHARINFO pChar = GetCharInfo()) {
		return strlen(ParseMacroParameter(pChar->pSpawn, Value, ValueLen));
	}
	return strlen(Value);
}
#ifdef ISXEQ
int CMD_FlashOnTells(int argc, char *argv[])
{
	PSPAWNINFO pChar = (PSPAWNINFO)pLocalPlayer;
	CHAR szTemp[MAX_STRING] = { 0 };
	PCHAR szLine = ISXEQArgToMQ2Arg(argc, argv, szTemp, MAX_STRING);
#else
VOID FlashOnTells(PSPAWNINFO pChar, PCHAR szLine)
{
#endif
	if (szLine[0] != '\0') {
		if (!_stricmp(szLine, "on")) {
			gbFlashOnTells = 0;
		}
		else if (!_stricmp(szLine, "off")) {
			gbFlashOnTells = 1;
		}
	}
	if (gbFlashOnTells) {
		gbFlashOnTells = 0;
		WriteChatColor("Flash On Tells is OFF", CONCOLOR_LIGHTBLUE);
		WritePrivateProfileString("MacroQuest", "FlashOnTells", "0", gszINIFilename);
	}
	else {
		gbFlashOnTells = 1;
		WriteChatColor("Flash On Tells is ON", CONCOLOR_YELLOW);
		WritePrivateProfileString("MacroQuest", "FlashOnTells", "1", gszINIFilename);
	}
	RETURN(0);
}
#ifdef ISXEQ
int CMD_BeepOnTells(int argc, char *argv[])
{
	PSPAWNINFO pChar = (PSPAWNINFO)pLocalPlayer;
	CHAR szTemp[MAX_STRING] = { 0 };
	PCHAR szLine = ISXEQArgToMQ2Arg(argc, argv, szTemp, MAX_STRING);
#else
VOID BeepOnTells(PSPAWNINFO pChar, PCHAR szLine)
{
#endif
	if (szLine[0] != '\0') {
		if (!_stricmp(szLine, "on")) {
			gbBeepOnTells = 0;
		}
		else if (!_stricmp(szLine, "off")) {
			gbBeepOnTells = 1;
		}
	}
	if (gbBeepOnTells) {
		gbBeepOnTells = 0;
		WriteChatColor("Beep On Tells is OFF", CONCOLOR_LIGHTBLUE);
		WritePrivateProfileString("MacroQuest", "BeepOnTells", "0", gszINIFilename);
	}
	else {
		gbBeepOnTells = 1;
		WriteChatColor("Beep On Tells is ON", CONCOLOR_YELLOW);
		WritePrivateProfileString("MacroQuest", "BeepOnTells", "1", gszINIFilename);
	}
	RETURN(0);
}
#ifdef ISXEQ
int CMD_TimeStampChat(int argc, char *argv[])
{
	PSPAWNINFO pChar = (PSPAWNINFO)pLocalPlayer;
	CHAR szTemp[MAX_STRING] = { 0 };
	PCHAR szLine = ISXEQArgToMQ2Arg(argc, argv, szTemp, MAX_STRING);
#else
VOID TimeStampChat(PSPAWNINFO pChar, PCHAR szLine)
{
#endif
	if (szLine[0] != '\0') {
		if (!_stricmp(szLine, "on")) {
			gbTimeStampChat = 0;
		}
		else if (!_stricmp(szLine, "off")) {
			gbTimeStampChat = 1;
		}
	}
	if (gbTimeStampChat) {
		gbTimeStampChat = 0;
		WriteChatColor("Chat Time Stamping is OFF", CONCOLOR_LIGHTBLUE);
		WritePrivateProfileString("MacroQuest", "TimeStampChat", "0", gszINIFilename);
	}
	else
	{
		gbTimeStampChat = 1;
		WriteChatColor("Chat Time Stamping is ON", CONCOLOR_YELLOW);
		WritePrivateProfileString("MacroQuest", "TimeStampChat", "1", gszINIFilename);
	}
	RETURN(0);
}
VOID InitializeChatHook()
{
	DebugSpew("Initializing chat hook");

	// initialize Blech
#ifndef ISXEQ
#ifdef USEBLECHEVENTS
	pEventBlech = new Blech('#', '|', MQ2DataVariableLookup);
#endif
	pMQ2Blech = new Blech('#', '|', MQ2DataVariableLookup);
	DebugSpew("%s", pMQ2Blech->Version);
#endif
#if defined(ROF2EMU) || defined(UFEMU)
	EzDetourwName(CEverQuest__OutputTextToLog, OutputTextToLog_Detour, OutputTextToLog_Trampoline, "OutputTextToLog");
#endif
	EzDetourwName(CEverQuest__dsp_chat, &CChatHook::Detour, &CChatHook::Trampoline, "CEverQuest__dsp_chat");
	EzDetourwName(CEverQuest__DoTellWindow, &CChatHook::TellWnd_Detour, &CChatHook::TellWnd_Trampoline, "CEverQuest__DoTellWindow");
	EzDetourwName(CEverQuest__UPCNotificationFlush, &CChatHook::UPCNotificationFlush_Detour, &CChatHook::UPCNotificationFlush_Trampoline, "CEverQuest__UPCNotificationFlush");
#ifndef ISXEQ
	AddCommand("/timestamp", TimeStampChat);
	AddCommand("/beepontells", BeepOnTells);
	AddCommand("/flashontells", FlashOnTells);
#endif
}

VOID ShutdownChatHook()
{
#ifndef ISXEQ
	RemoveCommand("/flashontells");
	RemoveCommand("/beepontells");
	RemoveCommand("/timestamp");
#endif
	RemoveDetour(CEverQuest__dsp_chat);
#if defined(ROF2EMU) || defined(UFEMU)
	RemoveDetour(CEverQuest__OutputTextToLog);
#endif
	RemoveDetour(CEverQuest__DoTellWindow);
	RemoveDetour(CEverQuest__UPCNotificationFlush);
#ifndef ISXEQ
#ifdef USEBLECHEVENTS
	delete pEventBlech;
#endif
	delete pMQ2Blech;
	pMQ2Blech = 0;
#endif
}
