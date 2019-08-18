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

#pragma once
#include "WinTelnet.h"

#define TS_SENDLOGIN    0
#define TS_GETLOGIN     1
#define TS_SENDPASSWORD 2
#define TS_GETPASSWORD  3
#define TS_MAININPUT    4

extern BOOL LocalOnly;
extern BOOL ANSI;
extern CHAR TelnetLoginPrompt[MAX_STRING];
extern CHAR TelnetPasswordPrompt[MAX_STRING];
extern CHAR TelnetWelcome[MAX_STRING];

struct _TELNET {
    CWinTelnet *connection;
    int State;
    char Username[32];
    char Password[32];
    int PasswordTries;
    char Buffer[MAX_STRING];
    PCHATBUF Received;
    _TELNET *pLast;
    _TELNET *pNext;
};

//typedef VOID   (__stdcall *TelnetDataCallback)(_TELNET *, PCHAR);

class CTelnetServer
{
public:
    CTelnetServer(void);
    ~CTelnetServer(void);

    void ShutdownListener();
    bool Listen(int Port);
    void Broadcast(char *String);
    void Shutdown();
    bool IsValidUser(char *user, char *pwdest);

    void ProcessIncoming();

};
