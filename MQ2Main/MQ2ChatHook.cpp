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
	VOID Trampoline(PCHAR szMsg, DWORD dwColor, bool, bool, int);
	VOID Detour(PCHAR szMsg, DWORD dwColor, bool EqLog, bool dopercentsubst, int something)
#else
	VOID Trampoline(PCHAR szMsg, DWORD dwColor, bool EqLog, bool dopercentsubst);
	VOID Detour(PCHAR szMsg, DWORD dwColor, bool EqLog, bool dopercentsubst)
#endif
	{
		//DebugSpew("CChatHook::Detour(%s)",szMsg); 
		gbInChat = TRUE;

		CheckChatForEvent(szMsg);

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
			Benchmark(bmPluginsIncomingChat, SkipTrampoline = PluginsIncomingChat(szMsg, dwColor));
			if (!SkipTrampoline) {
				if (gAnonymize) {
					int len = strlen(szMsg);
					char myName[MAX_STRING] = "*";
					int namelen = 0;
					char *szAnonMsg = (char *)LocalAlloc(LPTR, len + 64);
					if (pLocalPlayer) {
						strcpy_s(myName, MAX_STRING, ((PSPAWNINFO)pLocalPlayer)->Name);
						namelen = strlen(myName);
						if (szAnonMsg) {
							strcpy_s(szAnonMsg, len + 64, szMsg);
							while (strstr(szAnonMsg, myName)) {
								if (char *p = strstr(szAnonMsg, myName)) {
									for (int i = 1; i < namelen - 1; i++) {
										p[i] = '*';
									}
								}
							}
						}
					}
					if (szAnonMsg) {
						if (char *pDest = strchr(szAnonMsg, ' ')) {
							int len = strlen(szAnonMsg) - strlen(pDest);
							if (len >= 2) {
								if (szAnonMsg[0] == 0x12) {
									for (int i = 3; i < len - 2; i++) {
										szAnonMsg[i] = '*';
									}
								}
								else {
									if (strstr(szAnonMsg, "You have healed ")) {
										for (int i = 17; i < 17 + namelen - 1; i++) {
											szAnonMsg[i] = '*';
										}
									}
									else if (_strnicmp(szAnonMsg, "you ", 4) && _strnicmp(szAnonMsg, "your ", 5)) {
										for (int i = 1; i < len - 1; i++) {
											szAnonMsg[i] = '*';
										}
									}
								}
							}
						}
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
							Trampoline(szAnonMsg, dwColor, EqLog, dopercentsubst, something);
#else
							Trampoline(szAnonMsg, dwColor, EqLog, dopercentsubst);
#endif
							LocalFree(szAnonMsg);
#if defined(ROF2EMU) || defined(UFEMU)
						}
#endif
					}
				}
				else {
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
						Trampoline(szMsg, dwColor, EqLog, dopercentsubst, something);
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

	VOID TellWnd_Trampoline(char *message, char *name, char *name2, void *unknown, int color, bool b);
	VOID TellWnd_Detour(char *message, char *name, char *name2, void *unknown, int color, bool b)
	{
		int len = strlen(message);
		char *szMsg = (char *)LocalAlloc(LPTR, len + 64);
		BOOL SkipTrampoline = 0;
		gbInChat = true;
		if (szMsg) {
			sprintf_s(szMsg, len + 63, "%s tells you, '%s'", name, message);
			CheckChatForEvent(szMsg);
			Benchmark(bmPluginsIncomingChat, SkipTrampoline = PluginsIncomingChat(szMsg, color));
		}

		if (!SkipTrampoline) {
#if defined(ROF2EMU) || defined(UFEMU)
			if (gbTimeStampChat && szMsg) {
				CHAR tmpbuf[32] = { 0 };
				_strtime_s(tmpbuf, 32);
				sprintf_s(szMsg, len + 63, "[%s] %s", tmpbuf, name);
				TellWnd_Trampoline(message, szMsg, name2, unknown, color, b);
			}
			else {
				TellWnd_Trampoline(message, name, name2, unknown, color, b);
			}
#else
			TellWnd_Trampoline(message, name, name2, unknown, color, b);
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
DETOUR_TRAMPOLINE_EMPTY(VOID CChatHook::Trampoline(PCHAR szMsg, DWORD dwColor, bool EqLog, bool dopercentsubst, int something));
#else
DETOUR_TRAMPOLINE_EMPTY(VOID CChatHook::Trampoline(PCHAR szMsg, DWORD dwColor, bool EqLog, bool dopercentsubst));
#endif
#if defined(ROF2EMU) || defined(UFEMU)
DETOUR_TRAMPOLINE_EMPTY(VOID OutputTextToLog_Trampoline(char *));
#endif
DETOUR_TRAMPOLINE_EMPTY(VOID CChatHook::TellWnd_Trampoline(char *message, char *name, char *name2, void *unknown, int color, bool b));
DETOUR_TRAMPOLINE_EMPTY(VOID CChatHook::UPCNotificationFlush_Trampoline());

#if !defined(ROF2EMU) && !defined(UFEMU)
VOID dsp_chat_no_events(const char *Text, int Color, bool EqLog, bool dopercentsubst, int something)
#else
VOID dsp_chat_no_events(const char *Text, int Color, bool EqLog, bool dopercentsubst)
#endif
{
#if !defined(ROF2EMU) && !defined(UFEMU)
	((CChatHook*)pEverQuest)->Trampoline((PCHAR)Text, Color, EqLog, dopercentsubst, something);
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
	RemoveDetour(CEverQuest__OutputTextToLog);
#if defined(ROF2EMU) || defined(UFEMU)
	RemoveDetour(CEverQuest__DoTellWindow);
#endif
	RemoveDetour(CEverQuest__UPCNotificationFlush);
#ifndef ISXEQ
#ifdef USEBLECHEVENTS
	delete pEventBlech;
#endif
	delete pMQ2Blech;
	pMQ2Blech = 0;
#endif
}
