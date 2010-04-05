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
    char Buffer[2048];
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
