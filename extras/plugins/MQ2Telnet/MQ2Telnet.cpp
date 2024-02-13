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

// Updates:
// 12/31/2016 - Added commands to turn on and off EQ Chat Spam - ctaylor22
// 01/13/2017 - Added the TelNet TLO for Ready, Port, and LoginInfo.

#include "../MQ2Plugin.h"
#include "WinTelnet.h"
#include "TelnetServer.h"

PreSetup("MQ2Telnet");

CTelnetServer* server = nullptr;

DWORD TelnetPort = 0;
BOOL FilterSpam = FALSE;
int PortUsed = 0;

class MQ2TelNetType : public MQ2Type
{
	char Tempos[MAX_STRING];

public:
	enum IfsMembers
	{
		Ready = 1,
		Port = 2,
		LoginInfo = 3,
	};

	MQ2TelNetType() : MQ2Type("TelNet")
	{
		TypeMember(Ready);
		TypeMember(Port);
		TypeMember(LoginInfo);
	};

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override
	{
		MQTypeMember* pMember = MQ2TelNetType::FindMember(Member);
		if (pMember)
		{
			switch ((IfsMembers)pMember->ID)
			{
			case Ready:
				if (server)
				{
					Dest.DWord = true;
				}
				else
				{
					Dest.DWord = false;
				}
				Dest.Type = pBoolType;
				return true;

			case Port:
				if (TelnetPort)
				{
					Dest.DWord = PortUsed;
				}
				else
				{
					Dest.DWord = 0;
				}
				Dest.Type = pIntType;
				return true;

			case LoginInfo:
				char FullList[MAX_STRING] = { 0 };
				char szBuffer[MAX_STRING] = { 0 };
				GetPrivateProfileString("Users", nullptr, "", FullList, MAX_STRING, INIFileName);

				if (FullList[0] != 0)
				{
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
		}

		strcpy_s(Tempos, "FALSE");
		Dest.Type = pStringType;
		Dest.Ptr = Tempos;
		return true;
	}
	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		strcpy_s(Destination, 4, "TRUE");
		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		return false;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		return false;
	}
};
MQ2TelNetType* pTelNetTypes = nullptr;

bool DataTelNet(const char* Index, MQTypeVar& Dest)
{
	Dest.Type = pTelNetTypes;
	Dest.DWord = 1;
	return true;
}

PLUGIN_API void SpamToggle(SPAWNINFO* pChar, char* szLine)
{
	FilterSpam = !FilterSpam;
	if (FilterSpam)
	{
		WriteChatColor("TELNET Spam Filtering Now ON.");
	}
	else
	{
		WriteChatColor("TELNET Spam Filtering Now OFF.");
	}
}

PLUGIN_API void SpamOn(SPAWNINFO* pChar, char* szLine)
{
	WriteChatColor("TELNET Spam Filtering Now OFF.");

	if (server && FilterSpam)
		server->Broadcast("TELNET Spam Filtering Now OFF.");

	FilterSpam = FALSE;
}

PLUGIN_API void SpamOff(SPAWNINFO* pChar, char* szLine)
{
	WriteChatColor("TELNET Spam Filtering Now ON.");

	if (server && FilterSpam)
		server->Broadcast("TELNET Spam Filtering Now ON.");

	FilterSpam = TRUE;
}

PLUGIN_API void InitializePlugin()
{
	TelnetPort = GetPrivateProfileInt("Telnet Server", "Port", 23, INIFileName);
	if (!TelnetPort)
	{
		DebugSpewAlways("SetupServer: Port 0 specified, disabling mq2telnet");
	}

	// ANSI not currently implemented
	//TelnetPort = GetPrivateProfileInt("Telnet Server","ANSI",1,INIFileName);
	LocalOnly = GetPrivateProfileInt("Telnet Server", "LocalOnly", 1, INIFileName);
	GetPrivateProfileString("Telnet Server", "LoginPrompt", "login: ", TelnetLoginPrompt, MAX_STRING, INIFileName);
	GetPrivateProfileString("Telnet Server", "PassPrompt", "password: ", TelnetPasswordPrompt, MAX_STRING, INIFileName);
	GetPrivateProfileString("Telnet Server", "Welcome", "Successful login.", TelnetWelcome, MAX_STRING, INIFileName);

	AddCommand("/tnverbose", SpamOn);
	AddCommand("/tnquiet", SpamOff);
	AddCommand("/tnfilteroff", SpamOn);
	AddCommand("/tnfilteron", SpamOff);
	pTelNetTypes = new MQ2TelNetType;
	AddMQ2Data("TelNet", DataTelNet);

	server = new CTelnetServer();
	server->Listen(TelnetPort);
}

PLUGIN_API void ShutdownPlugin()
{
	DebugSpewAlways("Shutting down mq2telnet");

	delete server;
	server = nullptr;

	RemoveCommand("/tnverbose");
	RemoveCommand("/tnquiet");
	RemoveCommand("/tnfilteroff");
	RemoveCommand("/tnfilteron");
	RemoveMQ2Data("TelNet");

	delete pTelNetTypes;
	pTelNetTypes = nullptr;
}

PLUGIN_API void OnPulse()
{
	if (server)
	{
		server->ProcessIncoming();
	}
}

PLUGIN_API DWORD OnWriteChatColor(char* Line, DWORD Color, DWORD Filter)
{
	char Stripped[MAX_STRING];

	if (server)
	{
		// ANSI not currently implemented
		//if (ANSI)
		//    MQToANSI(Line,Stripped);

		if (!FilterSpam || strstr(Line, " says, ") || strstr(Line, "You say, ") || strstr(Line, " tells you, "))
		{
			StripMQChat(Line, Stripped);
			server->Broadcast(Stripped);
		}
	}

	return 0;
}

PLUGIN_API DWORD OnIncomingChat(char* Line, DWORD Color)
{
	char Stripped[MAX_STRING];
	if (server)
	{
		// ANSI not currently implemented
		//if (ANSI)
		//    MQToANSI(Line,Stripped);

		if (!FilterSpam || strstr(Line, " says, ") || strstr(Line, "You say, ") || strstr(Line, " tells you, "))
		{
			StripMQChat(Line, Stripped);
			server->Broadcast(Stripped);
		}
	}
	return 0;
}
