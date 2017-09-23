// Updates:
// 12/31/2016 - Added commands to turn on and off EQ Chat Spam - ctaylor22
// 01/13/2017 - Added the TelNet TLO for Ready, Port, and LoginInfo.
// mq2telnet.cpp
//#define DEBUG_TRY
#include "../MQ2Plugin.h"
#include "WinTelnet.h"
#include "TelnetServer.h"

PreSetup("MQ2Telnet");

CTelnetServer *server=0;

DWORD TelnetPort=0;
BOOL FilterSpam = FALSE;
int PortUsed = 0;
//TLO
class MQ2TelNetType *pTelNetTypes = nullptr;
class MQ2TelNetType : public MQ2Type {
private:
	char Tempos[MAX_STRING];
public:
	enum IfsMembers {
		Ready = 1,
		Port = 2,
		LoginInfo = 3,
	};
	MQ2TelNetType() :MQ2Type("TelNet") {
		TypeMember(Ready);
		TypeMember(Port);
		TypeMember(LoginInfo);
	};
	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest) {
		PMQ2TYPEMEMBER pMember = MQ2TelNetType::FindMember(Member);
		if (pMember)
			switch ((IfsMembers)pMember->ID) {
			case Ready:
				if (server) {
					Dest.DWord = true;
				}
				else 
				{
					Dest.DWord = false;
				}
				Dest.Type = pBoolType;
				return true;
			case Port:
				if (TelnetPort) {
					Dest.DWord = PortUsed;
				}
				else 
				{
					Dest.DWord = 0;
				}
				Dest.Type = pIntType;
				return true;
			case LoginInfo:
				CHAR FullList[MAX_STRING] = { 0 };
				CHAR szBuffer[MAX_STRING] = { 0 };
				GetPrivateProfileString("Users", NULL, "", FullList, MAX_STRING, INIFileName);
				//PCHAR pFullList = FullList;
				if (FullList[0] != 0) {
					GetPrivateProfileString("Users", FullList, "", szBuffer, MAX_STRING, INIFileName);
					if (szBuffer[0] != 0) {
						sprintf_s(Tempos, "User Name: %s Password: %s", FullList, szBuffer);
					}
					else
					{
						strcpy_s(Tempos, "No User Name and Password Found");
					}
				} 
				else
				{
					strcpy_s(Tempos, "No User Name and Password Found");
				}
				Dest.Ptr = Tempos;
				Dest.Type = pStringType;
				return true;
			}
		strcpy_s(Tempos, "FALSE");
		Dest.Type = pStringType;
		Dest.Ptr = Tempos;
		return true;
	}
	bool ToString(MQ2VARPTR VarPtr, PCHAR Destination) {
		strcpy_s(Destination, 4, "TRUE");
		return true;
	}
	bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source) {
		return false;
	}
	bool FromString(MQ2VARPTR &VarPtr, PCHAR Source) {
		return false;
	}
	~MQ2TelNetType()
	{
	}
};
BOOL DataTelNet(PCHAR Index, MQ2TYPEVAR &Dest)
{
	Dest.Type = pTelNetTypes;
	Dest.DWord = 1;
	return true;
}
PLUGIN_API VOID SpamToggle(PSPAWNINFO pChar, PCHAR szLine)
{
	FilterSpam = !FilterSpam;
	if (FilterSpam) {
		//DebugSpewAlways("Spam Filtering Now ON.");
		WriteChatColor("TELNET Spam Filtering Now ON.");
	}
	else {
		//DebugSpewAlways("Spam Filtering Now OFF.");
		WriteChatColor("TELNET Spam Filtering Now OFF.");
	}
}
PLUGIN_API VOID SpamOn(PSPAWNINFO pChar, PCHAR szLine)
{
	//DebugSpewAlways("Spam Filtering Now OFF.");
	WriteChatColor("TELNET Spam Filtering Now OFF.");
	if (server && FilterSpam)
		server->Broadcast("TELNET Spam Filtering Now OFF.");
	FilterSpam = FALSE;
}
PLUGIN_API VOID SpamOff(PSPAWNINFO pChar, PCHAR szLine)
{
	//DebugSpewAlways("Spam Filtering Now ON.");
	WriteChatColor("TELNET Spam Filtering Now ON.");
	if (server && FilterSpam)
		server->Broadcast("TELNET Spam Filtering Now ON.");
	FilterSpam = TRUE;
}

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

	AddCommand("/tnverbose", SpamOn);
	AddCommand("/tnquiet", SpamOff);
	AddCommand("/tnfilteroff", SpamOn);
	AddCommand("/tnfilteron", SpamOff);
	pTelNetTypes = new MQ2TelNetType;
	AddMQ2Data("TelNet", DataTelNet);

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
	RemoveCommand("/tnverbose");
	RemoveCommand("/tnquiet");
	RemoveCommand("/tnfilteroff");
	RemoveCommand("/tnfilteron");
	RemoveMQ2Data("TelNet");
	delete pTelNetTypes;
	pTelNetTypes = nullptr;
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
		if (!FilterSpam || strstr(Line, " says, ") || strstr(Line, "You say, ") || strstr(Line, " tells you, "))
		{
			StripMQChat(Line, Stripped);
			server->Broadcast(Stripped);
		}
		//StripMQChat(Line,Stripped);
        //server->Broadcast(Stripped);
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
		if (!FilterSpam || strstr(Line, " says, ") || strstr(Line, "You say, ") || strstr(Line, " tells you, "))
		{
		   StripMQChat(Line, Stripped);
		   server->Broadcast(Stripped);
	    }
    }
    return 0;
}


