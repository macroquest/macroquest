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

#pragma once

#include "WinTelnet.h"

#define TS_SENDLOGIN    0
#define TS_GETLOGIN     1
#define TS_SENDPASSWORD 2
#define TS_GETPASSWORD  3
#define TS_MAININPUT    4

extern bool LocalOnly;
extern bool ANSI;
extern char TelnetLoginPrompt[MAX_STRING];
extern char TelnetPasswordPrompt[MAX_STRING];
extern char TelnetWelcome[MAX_STRING];

struct TXTBUFFER
{
	char     szText[MAX_STRING];

	TXTBUFFER* pNext;
};

struct TELNET
{
	CWinTelnet* connection;
	int State;
	char Username[32];
	char Password[32];
	int PasswordTries;
	char Buffer[MAX_STRING];
	TXTBUFFER* Received;
	TELNET* pLast;
	TELNET* pNext;
};

class CTelnetServer
{
public:
	CTelnetServer();
	~CTelnetServer();

	void ShutdownListener();
	bool Listen(int Port);
	void Broadcast(char* String);
	void Shutdown();
	bool IsValidUser(char* user, char* pwdest);

	void ProcessIncoming();
};
