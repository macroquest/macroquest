// mq2telnet.cpp
//#define DEBUG_TRY
#include "../MQ2Plugin.h"
#include "WinTelnet.h"
#include "TelnetServer.h"

PreSetup("MQ2Telnet");

CTelnetServer *server=0;

DWORD TelnetPort=0;

PLUGIN_API VOID InitializePlugin(VOID)
{
    DebugSpewAlways("Initializing mq2telnet");
    TelnetPort = GetPrivateProfileInt("Telnet Server","Port",23,INIFileName);
    if (!TelnetPort)
    {
        DebugSpewAlways("SetupServer: Port 0 specified, disabling mq2telnet");
    }
    // ANSI not currently implemented
    //TelnetPort = GetPrivateProfileInt("Telnet Server","ANSI",1,INIFileName);
    LocalOnly = GetPrivateProfileInt("Telnet Server","LocalOnly",1,INIFileName);
    GetPrivateProfileString("Telnet Server","LoginPrompt","login: ",TelnetLoginPrompt,MAX_STRING,INIFileName);
    GetPrivateProfileString("Telnet Server","PassPrompt","password: ",TelnetPasswordPrompt,MAX_STRING,INIFileName);
    GetPrivateProfileString("Telnet Server","Welcome","Successful login.",TelnetWelcome,MAX_STRING,INIFileName);


    server=new CTelnetServer();
    server->Listen(TelnetPort);

}

PLUGIN_API VOID ShutdownPlugin(VOID)
{
    DebugSpewAlways("Shutting down mq2telnet");
    CTelnetServer *pServer=server;
    server=0;
    if (pServer)
    {
        DebugTry(delete pServer);
    }
}

PLUGIN_API VOID OnPulse(VOID)
{
    if (server)
        server->ProcessIncoming();
}

PLUGIN_API DWORD OnWriteChatColor(PCHAR Line, DWORD Color, DWORD Filter)
{
    CHAR Stripped[MAX_STRING];
    //if (gFilterMacro == FILTERMACRO_NONE) return 0;
    if (server)
    {
        // ANSI not currently implemented
        //if (ANSI)
        //    MQToANSI(Line,Stripped);
        //else
        StripMQChat(Line,Stripped);
        server->Broadcast(Stripped);
    }

    return 0;
}

PLUGIN_API DWORD OnIncomingChat(PCHAR Line, DWORD Color)
{
    CHAR Stripped[MAX_STRING];
    if (server)
    {
        // ANSI not currently implemented
        //if (ANSI)
        //    MQToANSI(Line,Stripped);
        //else
        StripMQChat(Line,Stripped);
        server->Broadcast(Stripped);
    }
    return 0;
}




