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

// For list of changes, see CHANGELOG.md

#include <mq/Plugin.h>

#include "AutoLoginShared.h"

#include <map>
#include <tlhelp32.h>
#pragma comment(lib, "Crypt32.lib")

#include <filesystem>

namespace fs = std::filesystem;

PLUGIN_VERSION(3.0);

PreSetup("MQ2AutoLogin");

bool AUTOLOGIN_DBG = true;

struct {
	const char* Name;
	int ID;
} ServerData[] = {
	{"lockjaw",     160},
	{"ragefire",    159},
	{"vox",         158},
	{"trakanon",    155},
	{"fippy",       156},
	{"vulak",       157},
	{"mayong",      163},
	{"antonius",    100},
	{"beta",        2},
	{"brekt",       162},
	{"bertox",      102},
	{"bristle",     104},
	{"cazic",       105},
	{"drinal",      106},
	{"erollisi",    109},
	{"firiona",     111},
	{"luclin",      116},
	{"povar",       123},
	{"rathe",       127},
	{"tunare",      140},
	{"xegony",      144},
	{"zek",         147},
	{"test",        1},
	{0, 0},
};

struct DateStruct
{
/*0x18*/ char      Hours;
/*0x19*/ char      Minutes;
/*0x1a*/ char      Seconds;
/*0x1b*/ char      Month;
/*0x1c*/ char      Day;
/*0x1e*/ WORD      Year;
/*0x20*/ CXStr     Unknown0x08;
/*0x24*/ CXStr     Unknown0x0c;
/*0x28*/ CXStr     Unknown0x10;
/*0x30*/ int64_t   TimeStamp;
/*0x38*/
};

enum eServerStatus : uint32_t
{
	eServerStatus_Down = 1,
	eServerStatus_Locked = 4
};

// EQClientServerData
struct SERVERINFO
{
/*0x00*/ int           ID;
/*0x04*/ CXStr         ServerName;
/*0x08*/ CXStr         HostName;
/*0x0C*/ CXStr         ServerIP;
/*0x10*/ int           ExternalPort;
/*0x14*/ int           InternalPort;
/*0x18*/ DateStruct    DateCreated;
/*0x38*/ int           Flags;
/*0x3C*/ int           ServerType;
/*0x40*/ CXStr         LanguageCode;
/*0x44*/ CXStr         CountryCode;
/*0x48*/ eServerStatus StatusFlags;
/*0x4C*/ int           PopulationRanking;
/*0x50*/
};

struct SERVERLIST
{
/*0x00*/ SERVERINFO* Info;
/*0x04*/ SERVERLIST* Prev;
/*0x08*/ SERVERLIST* Next;
/*0x0C*/ DWORD     Unknown0x0C;
/*0x10*/ DWORD     Unknown0x10;
/*0x14*/ DWORD     Unknown0x14;
/*0x18*/
};

// LoginClient
struct SERVERSTUFF
{
/*0x000*/ BYTE     Unknown0x000[0x8];
/*0x008*/ void*    GFXENGINE;
/*0x00C*/ BYTE     Unknown0x00C[0x9C];
/*0x0A8*/ DWORD    CurrentServerID;
/*0x0AC*/ DWORD    Unknown0x0AC;
/*0x0B0*/ CXStr    LoginName;
/*0x0B4*/ CXStr    Password;
/*0x0B8*/ CXStr    LoginNameCopy;
/*0x0BC*/ CXStr    PasswordCopy;
/*0x0C0*/ CXStr    AccountKey;
/*0x0C4*/ BYTE     Unknown0x0C4[0x14];
/*0x0D8*/ SERVERINFO** FirstServer;
/*0x0DC*/ SERVERINFO** LastServer;
/*0x0E0*/ BYTE     Unknown0x0E0[0x8];
/*0x0E8*/ SERVERLIST* pServerList;
/*0x0EC*/ DWORD    ServerListSize;
/*0x0F0*/ BYTE     Unknown0x0F0[0x8];
/*0x0F8*/ DWORD    QuickConnectServerID;
/*0x0FC*/ CXStr    QuickConnectServerName;
/*0x100*/ CXStr    QuickConnectIPAddress;
/*0x104*/
};

struct HOST
{
	CXStr* Name;
	int Port;
};

struct EQDEVICE
{
	char Name[0x40];
};

struct EQLOGIN
{
	EQDEVICE  Devices[0x10];
	int       NumDevices;
	HWND      hEQWnd;
	int       ReturnCode; // -1 = failed login
	char      Login[0x80];
	char      PW[0x80];
	char      PW2[0x80];
	char      ServerLong[0x80];
	int       ServerPort;
	char      AccountKey[0x80];
	int       ActiveDeviceIndex;
	char      LastZoneEntered[0x20];
	char      StationName[0x20];
	char      ExeName[0x20];
	char      CommandLine[0x1c0];
	char      ServerShort[0x80];
	char      Session[0x40];
	char      Character[0x40];
	// more below I don't need atm
};

// work in progress to get short servername... -eqmule
class LoginClient// : public A_Callback?, public ChannelServerHandler?
{
public:
	void* A_Callback_vfTable;
	void* ChannelServerHandler_vfTable;
	EQLOGIN* pLoginData;
	DoublyLinkedList<HOST*> Hosts;
	HOST* pHost;
	bool      bRetryConnect;
	// more below don't need right now
};

bool bWait = false;
bool bServerWait = false;

class LoginServerAPI;
class CLoginViewManager;

bool bWeAreDown = false;
int NotifyOnServerUp = 0;
bool bLoginCheckDone = false;
bool bGotOffsets = false;
ULONGLONG ullerrorwait = 0;
ForeignPointer<SERVERSTUFF> pServerInfo;
CSidlManager* pSidlManager = nullptr;
CXWndManager* pWindowManager = nullptr;
CLoginViewManager* pLoginViewManager = nullptr;
DWORD dwEQMainBase = 0;
DWORD dwGetXMLDataAddr = 0;
DWORD dwSendLMouseClickAddr = 0;
DWORD dwEnterGameAddr = 0;
DWORD dwServerID = 0;
bool bKickActiveChar = true;
bool bUseMQ2Login = false;
bool bUseStationNamesInsteadOfSessions = false;
bool bReLoggin = false;
bool bEndAfterCharSelect = false;
bool bLogin = true;
bool bEnd = false;
bool bInGame = false;
bool bSwitchServer = false;
bool bSwitchChar = false;
bool bSwitchTime = false;
bool bInjectorUpdate = false;
char szCustomIni[64] = { 0 };
bool gbConsumedCommandLineArguments = false;

std::string gCurrentProfile;
std::string gCurrentAccountName;
std::string gCurrentPassword;
std::string gCurrentServerName;
std::string gCurrentCharacterName;
std::string gCurrentCharacterClass;
int         gCurrentCharacterLevel;

std::string gCurrentSelectCharacter;
std::string gNextCharacterName;

std::string gCommandLineArgs;

ULONGLONG dwTime = 0;
ULONGLONG switchTime = 0;
std::map<std::string, CXWnd*> WindowMap;

// this changes frequently so it needs to be done this way
ForeignPointer<LoginServerAPI> pLoginServerAPI;

void HandleWindows();
void LoginReset();
void SelectCharacter(const std::string& characterName, bool enterWorld);
DWORD GetProcessCount(char* exeName);
void AutoLoginDebug(std::string_view svLogMessage, bool bDebugOn = AUTOLOGIN_DBG);

// __LoadFrontEnd_x not used?
// ida style sig1 just mov     ecx, hLibModule : 8B 0D ? ? ? ? 68 ? ? ? ? 51 FF D6 A3 ? ? ? ? 85 C0 75 18
// ida style sig2 func start: 68 ? ? ? ? FF 15 ? ? ? ? A3 ? ? ? ? 85 C0
// 8B 0D ?? ?? ?? ?? 68 ?? ?? ?? ?? 51 FF D6 A3 ?? ?? ?? ?? 85 C0 75 ?? FF 15 ?? ?? ?? ?? 50 68 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 C4 ?? 33 C0 5E C3
// x   x  ?  ?  ?  ?  x  ?  ?  ?  ?  x  x  x  x  ?  ?  ?  ?  x  x  x  ?  x  x  ?  ?  ?  ?  x  x  ?  ?  ?  ?  x  ?  ?  ?  ?  x  x  ?  x  x  x  x

//----------------------------------------------------------------------------
// search in eqgame.exe
// Feb 16 2018 Test
// IDA Style Sig: FF 35 ? ? ? ? FF 15 ? ? ? ? A3

// HMODULE hEQMain
PBYTE eqmainPattern = (PBYTE)"\xFF\x35\x00\x00\x00\x00\xFF\x15\x00\x00\x00\x00\xA3";
char eqmainMask[] = "xx????xx????x";

//----------------------------------------------------------------------------
// eqmain.dll

// A3 ? ? ? ? E8 ? ? ? ? 83 C4 ? 85 C0 74 ? 8B 96 ? ? ? ? 52 57 8B C8 E8 ? ? ? ? EB ?
// Feb 16 2018 Test
// A3 ? ? ? ? E8 ? ? ? ? 83 C4 04 85 C0
// LoginViewManager* pLoginViewManager
PBYTE lvmPattern = (PBYTE)"\xA3\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x83\xC4\x04\x85\xC0";
char lvmMask[] = "x????x????xxxxx";

// 8B 15 ? ? ? ? 89 82 ? ? ? ? A1 ? ? ? ? C6 80 ? ? ? ? ? 8B 0D ? ? ? ? 89 1D ? ? ? ? 8B 11 8B 42 ? FF D0 85 C0 74 ?
// Apr 10 2018 Test
// A1 ? ? ? ? 89 88 ? ? ? ?
PBYTE xwmPattern = (PBYTE)"\xA1\x00\x00\x00\x00\x89\x88\x00\x00\x00\x00";
char xwmMask[] = "x????xx????";

// A1 ? ? ? ? 80 B8 ? ? ? ? ? 0F 84 ? ? ? ? 8D 88 ? ? ? ? 8B 01 3B C3 74 ? 89 45 ? 33 DB 8B 45 ? F0 FF ? 0F 94 C3 89 5D ?
// Apr 10 2018 Test
// 8B 35 ? ? ? ? C6 45 FC 08
PBYTE swmPattern = (PBYTE)"\x8B\x35\x00\x00\x00\x00\xC6\x45\xFC\x08";
char swmMask[] = "xx????xxxx";

// 8B 54 24 ? 56 8B 74 24 ? 8B C1 85 D2 75 ? 85 F6 75 ? 33 C0 5E C2 ? ?
// Feb 16 2018 Test
// IDA Style Sig: 53 8B 5C 24 0C 8B C1 57
// Code Style Signature: \x53\x8B\x5C\x24\x0C\x8B\xC1\x57 xxxxxxxx
PBYTE xmldataPattern = (PBYTE)"\x53\x8B\x5C\x24\x0C\x8B\xC1\x57";
char xmldataMask[] = "xxxxxxxx";

// 55 8B EC 6A ? 68 ? ? ? ? 64 A1 ? ? ? ? 50 83 EC ? 53 56 57 A1 ? ? ? ? 33 C5 50 8D 45 ? 64 A3 ? ? ? ? 8B F1 83 7E ? ?
// Feb 16 2018 Test
// 55 8B EC 6A FF 68 ? ? ? ? 64 A1 ? ? ? ? 50 83 EC 08 53 56 57 A1 ? ? ? ? 33 C5 50 8D 45 F4 64 A3 ? ? ? ? 8B F1 83 7E 14 00 74 5D 51 8B CC 89 65 F0 68 ? ? ? ? E8 ? ? ? ? 51 8B CC 89 65 EC 68 ? ? ? ? C7 45 ? ? ? ? ? E8 ? ? ? ? 8B 4E 14 C6 45 FC 01 E8 ? ? ? ? 8B F8 51 8B DC 8B 0F 85 C9 74 09 51 E8 ? ? ? ? 83 C4 04 8B 07 8B CE 89 03 C7 45 ? ? ? ? ? E8 ? ? ? ? 84 C0 75 17 8B 4E 1C 8B 7D 08 85 C9 74 26 8B 01 57 FF 90 ? ? ? ? 85 C0 74 29 B8 ? ? ? ? 8B 4D F4 64 89 0D ? ? ? ? 59 5F 5E 5B 8B E5 5D C2 04 00 8B 4E 14 85 C9 74 09 8B 01 57 FF 90 ? ? ? ? 8B 0D ? ? ? ? 57 E8 ? ? ? ? 8B 4D F4 64 89 0D ? ? ? ? 59 5F 5E 5B 8B E5 5D C2 04 00
PBYTE lmousePattern = (PBYTE)"\x55\x8B\xEC\x6A\xFF\x68\x00\x00\x00\x00\x64\xA1\x00\x00\x00\x00\x50\x83\xEC\x08\x53\x56\x57\xA1\x00\x00\x00\x00\x33\xC5\x50\x8D\x45\xF4\x64\xA3\x00\x00\x00\x00\x8B\xF1\x83\x7E\x14\x00\x74\x5D\x51\x8B\xCC\x89\x65\xF0\x68\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x51\x8B\xCC\x89\x65\xEC\x68\x00\x00\x00\x00\xC7\x45\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x8B\x4E\x14\xC6\x45\xFC\x01\xE8\x00\x00\x00\x00\x8B\xF8\x51\x8B\xDC\x8B\x0F\x85\xC9\x74\x09\x51\xE8\x00\x00\x00\x00\x83\xC4\x04\x8B\x07\x8B\xCE\x89\x03\xC7\x45\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x84\xC0\x75\x17\x8B\x4E\x1C\x8B\x7D\x08\x85\xC9\x74\x26\x8B\x01\x57\xFF\x90\x00\x00\x00\x00\x85\xC0\x74\x29\xB8\x00\x00\x00\x00\x8B\x4D\xF4\x64\x89\x0D\x00\x00\x00\x00\x59\x5F\x5E\x5B\x8B\xE5\x5D\xC2\x04\x00\x8B\x4E\x14\x85\xC9\x74\x09\x8B\x01\x57\xFF\x90\x00\x00\x00\x00\x8B\x0D\x00\x00\x00\x00\x57\xE8\x00\x00\x00\x00\x8B\x4D\xF4\x64\x89\x0D\x00\x00\x00\x00\x59\x5F\x5E\x5B\x8B\xE5\x5D\xC2\x04\x00";
char lmouseMask[] = "xxxxxx????xx????xxxxxxxx????xxxxxxxx????xxxxxxxxxxxxxxx????x????xxxxxxx????xx?????x????xxxxxxxx????xxxxxxxxxxxxx????xxxxxxxxxxx?????x????xxxxxxxxxxxxxxxxxxx????xxxxx????xxxxxx????xxxxxxxxxxxxxxxxxxxxxx????xx????xx????xxxxxx????xxxxxxxxxx";

// A3 ? ? ? ? 8B 56 ? 8B 4A ? 6A ? 51 52 8B C8 C7 45 ? ? ? ? ? E8 ? ? ? ?
// Feb 16 2018 Test
// IDA Style Sig: 89 0D ? ? ? ? 8B 46 2C
// LoginServerAPI
const uint8_t* LoginServerAPI_Pattern = (PBYTE)"\x89\x0D\x00\x00\x00\x00\x8B\x46\x2C";
const char LoginServerAPI_Mask[] = "xx????xxx";

// 55 8B EC 6A FF 68 ? ? ? ? 64 A1 ? ? ? ? 50 83 EC 34 53 56 A1 ? ? ? ? 33 C5 50 8D 45 F4 64 A3 ? ? ? ? 8B F1 33 DB C7 45 ? ? ? ? ? C7 45 ? ? ? ? ? 89 5D EC 89 5D E8 8D 45 E0 50 89 5D FC E8 ? ? ? ? 8D 4D F0 51 E8 ? ? ? ? 83 C4 08 8D 4D C0 E8 ? ? ? ? 8B 45 E4 8B 55 08 50 8D 4D D8 C6 45 FC 01 89 55 D4 E8 ? ? ? ? 8B 4D F0 8B 55 10 8B 45 0C 52 89 4D DC 50 8D 4D C0 51 8B CE E8 ? ? ? ? 8D 4D C0 8B F0 88 5D FC E8 ? ? ? ? C7 45 ? ? ? ? ? C7 45 ? ? ? ? ? 39 5D EC 7E 20 8B 45 E4 83 C0 FC 8B D0 83 C9 FF F0 0F C1 0A 49 85 C9 7F 0C 8B 55 E0 50 8B 42 08 8D 4D E0 FF D0 8B C6 8B 4D F4 64 89 0D ? ? ? ? 59 5E 5B 8B E5 5D C2 0C ?
//55 8B EC 6A FF 68 ? ? ? ? 64 A1 ? ? ? ? 50 83 EC 34 53 56 A1
//Feb 16 2018 Test
//IDA Style Sig: 55 8B EC 6A FF 68 ? ? ? ? 64 A1 ? ? ? ? 50 83 EC 34 56
// 0x55 0x8B 0xEC 0x6A 0xFF 0x68 ? ? ? ? 0x64 0xA1 ? ? ? ? 0x50 0x83 0xEC 0x34 0x56
// 55 8B EC 6A FF 68 ?? ?? ?? ?? 64 A1 ?? ?? ?? ?? 50 83 EC 3C 56
PBYTE lcEGPattern = (PBYTE)"\x55\x8B\xEC\x6A\xFF\x68\x00\x00\x00\x00\x64\xA1\x00\x00\x00\x00\x50\x83\xEC\x3C\x56";
char lcEGMask[] = "xxxxxx????xx????xxxxx";

//----------------------------------------------------------------------------

class CLoginViewManager
{
public:
	int SendLMouseClick(CXPoint&);
};
FUNCTION_AT_VARIABLE_ADDRESS(int CLoginViewManager::SendLMouseClick(CXPoint&), dwSendLMouseClickAddr);

class LoginServerAPI
{
public:
	//see 100129F0 in eqmain.dll dated jul 13 2017 - eqmule
	unsigned int JoinServer(int serverID, void* userdata = 0, int timoutseconds = 10);
};
FUNCTION_AT_VARIABLE_ADDRESS(unsigned int LoginServerAPI::JoinServer(int, void*, int), dwEnterGameAddr);

template <typename T = CXWnd>
T* GetWindow(const std::string& name)
{
	auto iter = WindowMap.find(name);
	if (iter == WindowMap.end())
		return nullptr;

	return static_cast<T*>(iter->second);
}

template <typename T = CXWnd>
T* GetChildWindow(CXWnd* parentWnd, const std::string& child)
{
	CXMLDataManager* pXmlMgr = pSidlManager->GetParamManager();
	if (!pXmlMgr)
		return nullptr;

	if (parentWnd)
	{
		return static_cast<T*>(parentWnd->GetChildItem(pXmlMgr, CXStr{ child }));
	}

	return nullptr;
}

template <typename T = CXWnd>
T* GetChildWindow(const std::string& parent, const std::string& child)
{
	CXMLDataManager* pXmlMgr = pSidlManager->GetParamManager();
	if (!pXmlMgr)
		return nullptr;

	if (CXWnd* parentWnd = GetWindow<CXWnd>(parent))
	{
		return static_cast<T*>(parentWnd->GetChildItem(pXmlMgr, CXStr{ child }));
	}

	return nullptr;
}

bool IsWindowActive(const std::string& name)
{
	// FIXME: do we need this check?
	if (!dwEQMainBase)
		return false;

	if (CXWnd* pWnd = GetWindow(name))
	{
		return pWnd->IsVisible() && pWnd->IsEnabled();
	}

	return false;
}

// Combine IsWindowActive and GetWindow into a single call
template <typename T = CXWnd>
T* GetActiveWindow(const std::string& name)
{
	auto iter = WindowMap.find(name);
	if (iter == WindowMap.end())
		return nullptr;

	T* pWindow = static_cast<T*>(iter->second);
	if (pWindow && pWindow->IsVisible() && pWindow->IsEnabled())
	{
		return pWindow;
	}

	return nullptr;
}

// Combine IsWindowActive and GetChildWindow
template <typename T = CXWnd>
T* GetActiveChildWindow(const std::string& parent, const std::string& child)
{
	CXMLDataManager* pXmlMgr = pSidlManager->GetParamManager();
	if (!pXmlMgr)
		return nullptr;

	if (CXWnd* pParent = GetActiveWindow(parent))
	{
		T* pChild = static_cast<T*>(pParent->GetChildItem(pXmlMgr, CXStr{ child }));

		if (pChild && pChild->IsVisible() && pChild->IsEnabled())
		{
			return pChild;
		}
	}

	return nullptr;
}

std::string GetPassword()
{
	if (pServerInfo)
	{
		return std::string{ pServerInfo->Password };
	}

	return {};
}

std::string GetServerName()
{
	if (EQADDR_SERVERNAME)
	{
		return EQADDR_SERVERNAME;
	}

	return {};
}

bool CheckServerUp(int ID)
{
	if (CListWnd* serverList = GetWindow<CListWnd>("SERVERSELECT_ServerList"))
	{
		if (!serverList->ItemsArray.IsEmpty() && pServerInfo)
		{
			if (pServerInfo->pServerList && pServerInfo->pServerList->Info)
			{
				SERVERLIST* pList = pServerInfo->pServerList;
				while (pList)
				{
					if (pList->Info->ID == ID)
					{
						if (pList->Info->StatusFlags & eServerStatus_Locked || pList->Info->StatusFlags & eServerStatus_Down)
						{
							bWeAreDown = true;
							return false;
						}

						return true;
					}
					pList = pList->Next;
				}
			}
		}
	}

	return false;
}

// Look up the long name for a server name stored in the configuration
std::string GetServerLongName(const std::string& serverName)
{
	return GetPrivateProfileString("Servers", serverName, "", INIFileName);
}

// Look at CheckServerUp and factor out common parts
int GetServerIdFromName(const std::string& serverName)
{
	// We can only select server name while in this game state
	if (GetGameState() != GAMESTATE_PRECHARSELECT)
	{
		bGotOffsets = false;
		return 0;
	}

	std::string longName = GetServerLongName(serverName);
	if (longName.empty())
		return 0;

	if (CListWnd* serverList = GetWindow<CListWnd>("SERVERSELECT_ServerList"))
	{
		if (serverList->ItemsArray.Count && pServerInfo)
		{
			if (pServerInfo->pServerList && pServerInfo->pServerList->Info)
			{
				SERVERLIST* pList = pServerInfo->pServerList;
				while (pList)
				{
					if (pList->Info)
					{
						if (ci_equals(pList->Info->ServerName, longName))
						{
							return pList->Info->ID;
						}
					}
					pList = pList->Next;
				}
			}
			else
			{
				bGotOffsets = false;
			}
		}
	}

	return 0;
}

int GetServerID(const std::string& serverName)
{
	for (int n = 0; ServerData[n].ID; n++)
	{
		if (ci_equals(serverName, ServerData[n].Name))
		{
			return ServerData[n].ID;
		}
	}

	if (int id = GetServerIdFromName(serverName))
	{
		return id;
	}

	return 0;
}

void Cmd_SwitchServer(SPAWNINFO* pChar, char* szLine)
{
	char szServer[MAX_STRING] = { 0 };
	char szCharacter[MAX_STRING] = { 0 };

	GetArg(szServer, szLine, 1);
	GetArg(szCharacter, szLine, 2);

	if (!szServer[0] || !szCharacter[0])
	{
		WriteChatf("\ayUsage:\ax /switchserver <server short name> <character name>");
		return;
	}

	bool okToMoveOn = false;

	// check that we know what this server name is.
	if (!GetServerID(szServer))
	{
		// I guess we're just checking if we know the name because
		// maybe we'll need it later?
		std::string longName = GetServerLongName(szServer);
		if (longName.empty())
		{
			std::string serversMessage;

			WriteChatf("Invalid server name \ag%s\ax.  Valid server names are:", szServer);

			for (int n = 0; ServerData[n].ID; n++)
			{
				if (n > 0)
					serversMessage.append(", ");

				serversMessage.append(ServerData[n].Name);
			}

			serversMessage.append(" as well as any server you have defined in your MQ2AutoLogin.ini under the [Servers] section.");
			WriteChatColor(serversMessage.c_str());
			return;
		}
	}

	dwServerID = -1;
	gCurrentServerName = szServer;
	gCurrentCharacterName = szCharacter;
	bSwitchServer = true;

	if (pChar->StandState == STANDSTATE_FEIGN)
	{
		// using DoMappable here doesn't create enough of a delay for camp to work
		EzCommand("/stand");
	}

	EzCommand("/camp");
	bInGame = false;
	bInjectorUpdate = true;
	WriteChatf("Switching to \ag%s\ax on server \ag%s\ax", gCurrentCharacterName.c_str(), szServer);
}

void Cmd_SwitchCharacter(SPAWNINFO* pChar, char* szLine)
{
	char szArg1[MAX_STRING] = { 0 };

	if (!szLine[0])
	{
		WriteChatf("\ayUsage:\ax /switchchar <name>");
		return;
	}

	GetArg(szArg1, szLine, 1);

	if (GetGameState() == GAMESTATE_INGAME)
	{
		if (_stricmp(szArg1, pChar->DisplayedName))
		{
			gNextCharacterName = szArg1;

			if (pChar->StandState == STANDSTATE_FEIGN)
			{
				// using DoMappable here doesn't create enough of a delay for camp to work
				EzCommand("/stand");
			}

			EzCommand("/camp");
			bSwitchChar = true;
			bInjectorUpdate = true;
			WriteChatf("Switch to \ag%s\ax is now active and will commence at character select.", gNextCharacterName.c_str());
		}
		else
		{
			WriteChatf("\ayYou're already logged onto '%s'\ax", szArg1);
		}
	}
	else if (GetGameState() == GAMESTATE_CHARSELECT)
	{
		gNextCharacterName = szArg1;
		bSwitchChar = true;
	}
}

void Cmd_Relog(SPAWNINFO* pChar, char* szLine)
{
	if (GetGameState() != GAMESTATE_INGAME)
		return;

	if (!szLine[0])
	{
		WriteChatf("\ayUsage:\ax /relog [#s|#m]");
		WriteChatf("Example: /relog 30m (logs character out for 30 minutes then logs back in)");
		return;
	}

	DWORD n = GetIntFromString(szLine, 0);

	switch (szLine[strlen(szLine) - 1])
	{
	case 's':
	case 'S':
		n *= 1000;
		break;
	case 'm':
	case 'M':
		n *= 60000;
		break;
	default:
		n *= 1000;
		break;
	}

	if (n)
	{
		dwTime = MQGetTickCount64() + n;
	}

	gNextCharacterName = pChar->DisplayedName;

	if (dwTime)
		dwTime += 30000; // add 30 seconds for camp time

	if (pChar->StandState == STANDSTATE_FEIGN)
	{
		// using DoMappable here doesn't create enough of a delay for camp to work
		EzCommand("/stand");
	}

	EzCommand("/camp");
	bInGame = false;
	bInjectorUpdate = true;
}

bool GetAllOffsets()
{
	if (!dwEQMainBase)
		return false;

	if (uint32_t dwLoginClient = offsets::FindPattern(dwEQMainBase, 0x100000, LoginServerAPI_Pattern, LoginServerAPI_Mask))
	{
		pLoginServerAPI = offsets::GetDWordAt(dwLoginClient, 2);
	}
	else
	{
		AutoLoginDebug("Error: Could not find pLoginServerAPI");
		return false;
	}

	if (!(dwEnterGameAddr = offsets::FindPattern(dwEQMainBase, 0x200000, lcEGPattern, lcEGMask)))
	{
		AutoLoginDebug("Error: !dwEnterGame");
		return false;
	}

	DWORD dwSidlMgr = 0, dwWndMgr = 0, dwLoginMgr = 0;

	if (!(dwGetXMLDataAddr = offsets::FindPattern(dwEQMainBase, 0x100000, xmldataPattern, xmldataMask)))
	{
		AutoLoginDebug("Error: !dwGetXMLDataAddr");
		return false;
	}

	if (!(dwSendLMouseClickAddr = offsets::FindPattern(dwEQMainBase, 0x100000, lmousePattern, lmouseMask)))
	{
		AutoLoginDebug("Error: !dwSendLMouseClickAddr");
		return false;
	}

	if (dwSidlMgr = offsets::FindPattern(dwEQMainBase, 0x100000, swmPattern, swmMask))
	{
		dwSidlMgr = offsets::GetDWordAt(dwSidlMgr, 2);
	}
	else
	{
		AutoLoginDebug("Error: !dwSidlMgr");
		return false;
	}

	if (dwWndMgr = offsets::FindPattern(dwEQMainBase, 0x200000, xwmPattern, xwmMask))
	{
		dwWndMgr = offsets::GetDWordAt(dwWndMgr, 1);
	}
	else
	{
		AutoLoginDebug("Error: !dwWndMgr");
		return false;
	}

	if (dwLoginMgr = offsets::FindPattern(dwEQMainBase, 0x200000, lvmPattern, lvmMask))
	{
		dwLoginMgr = offsets::GetDWordAt(dwLoginMgr, 1);
		pServerInfo = dwLoginMgr - 4;
	}
	else
	{
		AutoLoginDebug("Error: !dwLoginMgr");
		return false;
	}

	pSidlManager = nullptr;
	pWindowManager = nullptr;
	pLoginViewManager = nullptr;

	while (!pSidlManager || !pWindowManager || !pLoginViewManager)
	{
		pSidlManager = (CSidlManager*)*(DWORD*)dwSidlMgr;
		pWindowManager = (CXWndManager*)*(DWORD*)dwWndMgr;
		pLoginViewManager = (CLoginViewManager*)*(DWORD*)dwLoginMgr;
	}

	WindowMap.clear();
	char Name[MAX_STRING] = { 0 };

	CXMLDataManager* xmlDataManager = pSidlManager->GetParamManager();

	for (int i = 0; i < pWindowManager->pWindows.Count; i++)
	{
		if (CXWnd* pWnd = pWindowManager->pWindows[i])
		{
			if (CXMLData* pXMLData = pWnd->GetXMLData(xmlDataManager))
			{
				if (!pXMLData->Name.empty())
				{
					AutoLoginDebug("bLogin loop: adding window '" + pXMLData->Name + "'");
					WindowMap[pXMLData->Name.c_str()] = pWnd;
				}
			}
		}
	}

	bGotOffsets = true;
	return true;
}

void LoginPulse()
{
	if (ullerrorwait)
	{
		if (ullerrorwait > MQGetTickCount64())
		{
			Sleep(0);
			return;
		}
		else
		{
			ullerrorwait = 0;
		}
	}

	if (GetAsyncKeyState(VK_END) & 1)
	{
		bEnd = true;
		return;
	}

	if (GetAsyncKeyState(VK_HOME) & 1)
	{
		bLogin = true;
		bEnd = false;
		return;
	}

	if (!bGotOffsets)
	{
		GetAllOffsets();
	}
	else
	{
		if (!bEnd)
			HandleWindows();
	}
}

void AddOurPulse()
{
	if (*(DWORD*)__heqmain)
	{
		bEnd = false;
		if (dwEQMainBase = *(DWORD*)__heqmain)
		{
			if (LoginController__GiveTime)
			{
				bGotOffsets = false;
			}
		}

		if (!bInGame && !bSwitchServer && !dwTime)
		{
			if (bUseMQ2Login)
			{
				// then we don't need anything else
			}
			else if (!bUseStationNamesInsteadOfSessions)
			{
				DWORD nProcs = GetProcessCount("eqgame.exe");
				std::string sessionName = fmt::format("Session{}", nProcs);
				AutoLoginDebug(sessionName);

				gCurrentCharacterName = GetPrivateProfileString(sessionName, "StationName", "", INIFileName);
				gCurrentPassword = GetPrivateProfileString(sessionName, "Password", "", INIFileName);
				gCurrentServerName = GetPrivateProfileString(sessionName, "Server", "", INIFileName);
				gCurrentCharacterName = GetPrivateProfileString(sessionName, "Character", "", INIFileName);
				gCurrentSelectCharacter = GetPrivateProfileString(sessionName, "SelectCharacter", "", INIFileName);
			}
		}
	}
}

DETOUR_TRAMPOLINE_EMPTY(DWORD WINAPI GetPrivateProfileStringA_Trampoline(LPCSTR, LPCSTR, LPCSTR, LPSTR, DWORD, LPCSTR));

void SetupCustomIni()
{
	if (szCustomIni && szCustomIni[0] != '\0')
		return;

	if (const char* pLogin = GetLoginName())
	{
		gCurrentAccountName = pLogin;
		GetPrivateProfileStringA_Trampoline(gCurrentAccountName.c_str(), "CustomClientIni", 0, szCustomIni, 64, INIFileName);
	}
}

DWORD WINAPI GetPrivateProfileStringA_Detour(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpDefault, LPSTR lpReturnedString, DWORD nSize, LPCSTR lpFileName)
{
	if (lpFileName)
	{
		SetupCustomIni();

		if (szCustomIni[0] != 0 && ci_find_substr(lpFileName, "eqclient.ini") != -1)
		{
			fs::path path = fs::path{ lpFileName } / szCustomIni;

			return GetPrivateProfileStringA_Trampoline(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, path.string().c_str());
		}
	}

	return GetPrivateProfileStringA_Trampoline(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName);
}

BOOL WINAPI WritePrivateProfileStringA_Trampoline(LPCSTR, LPCSTR, LPCSTR, LPCSTR);
BOOL WINAPI WritePrivateProfileStringA_Detour(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpString, LPCSTR lpFileName)
{
	if (lpFileName)
	{
		SetupCustomIni();

		if (szCustomIni[0] != 0 && ci_find_substr(lpFileName, "eqclient.ini") != -1)
		{
			fs::path path = fs::path{ lpFileName } / szCustomIni;

			return WritePrivateProfileStringA_Trampoline(lpAppName, lpKeyName, lpString, path.string().c_str());
		}
	}

	return WritePrivateProfileStringA_Trampoline(lpAppName, lpKeyName, lpString, lpFileName);
}
DETOUR_TRAMPOLINE_EMPTY(BOOL WINAPI WritePrivateProfileStringA_Trampoline(LPCSTR, LPCSTR, LPCSTR, LPCSTR));

UINT WINAPI GetPrivateProfileIntA_Tramp(LPCSTR, LPCSTR, INT, LPCSTR);
UINT WINAPI GetPrivateProfileIntA_Detour(LPCSTR lpAppName, LPCSTR lpKeyName, INT nDefault, LPCSTR lpFileName)
{
	if (lpFileName)
	{
		SetupCustomIni();

		if (szCustomIni[0] != '\0' && ci_find_substr(lpFileName, "eqclient.ini") != -1)
		{
			fs::path path = fs::path{ lpFileName } / szCustomIni;

			return GetPrivateProfileIntA_Tramp(lpAppName, lpKeyName, nDefault, path.string().c_str());
		}
	}

	return GetPrivateProfileIntA_Tramp(lpAppName, lpKeyName, nDefault, lpFileName);
}
DETOUR_TRAMPOLINE_EMPTY(UINT WINAPI GetPrivateProfileIntA_Tramp(LPCSTR, LPCSTR, INT, LPCSTR));

PLUGIN_API void InitializePlugin()
{
	DebugSpewAlways("MQ2AutoLogin: InitializePlugin()");

	// Check the command line for a /login parameter
	std::string commandLineArgs = ::GetCommandLineA();

	// Capture /login:<stuff> into gCommandLineArgs
	size_t loginPos = gCommandLineArgs.find("/login:");
	if (loginPos != std::string::npos)
	{
		gCommandLineArgs = commandLineArgs.substr(loginPos + 7);

		// trim stuff off the right
		loginPos = gCommandLineArgs.find(" ");
		if (loginPos != std::string::npos)
		{
			gCommandLineArgs = gCommandLineArgs.substr(0, loginPos);
		}
	}

	std::string path = GetPrivateProfileString("Settings", "IniLocation", "", INIFileName);
	if (!path.empty())
	{
		strcpy_s(INIFileName, path.c_str());
	}

	AUTOLOGIN_DBG = GetPrivateProfileBool("Settings", "Debug", AUTOLOGIN_DBG, INIFileName);
	AutoLoginDebug("MQ2AutoLogin: InitializePlugin()");

	NotifyOnServerUp = GetPrivateProfileInt("Settings", "NotifyOnServerUp", -1, INIFileName);
	if (NotifyOnServerUp == -1)
	{
		WritePrivateProfileString("Settings", "NotifyOnServerUp", "0", INIFileName);
		NotifyOnServerUp = 0;
	}

	bKickActiveChar = GetPrivateProfileBool("Settings", "KickActiveCharacter", true, INIFileName);
	bUseMQ2Login = GetPrivateProfileBool("Settings", "UseMQ2Login", false, INIFileName);
	bUseStationNamesInsteadOfSessions = GetPrivateProfileBool("Settings", "UseStationNamesInsteadOfSessions", false, INIFileName);
	bReLoggin = GetPrivateProfileBool("Settings", "LoginOnReLoadAtCharSelect", false, INIFileName);
	bEndAfterCharSelect = GetPrivateProfileBool("Settings", "EndAfterCharSelect", false, INIFileName);
	bool bUseCustomClientIni = GetPrivateProfileBool("Settings", "EnableCustomClientIni", false, INIFileName);

	AddCommand("/switchserver", Cmd_SwitchServer);
	AddCommand("/switchcharacter", Cmd_SwitchCharacter);
	AddCommand("/relog", Cmd_Relog);

	if (bUseCustomClientIni)
	{
		if (bUseStationNamesInsteadOfSessions && !bUseMQ2Login)
		{
			SetupCustomIni();
		}

		DWORD pfnGetPrivateProfileIntA = (DWORD)&::GetPrivateProfileIntA;
		EzDetour(pfnGetPrivateProfileIntA, GetPrivateProfileIntA_Detour, GetPrivateProfileIntA_Tramp);

		DWORD pfnGetPrivateProfileStringA = (DWORD)&::GetPrivateProfileStringA;
		EzDetour(pfnGetPrivateProfileStringA, GetPrivateProfileStringA_Detour, GetPrivateProfileStringA_Trampoline);

		DWORD pfnWritePrivateProfileStringA = (DWORD) &::WritePrivateProfileStringA;
		EzDetour(pfnWritePrivateProfileStringA, WritePrivateProfileStringA_Detour, WritePrivateProfileStringA_Trampoline);
	}

	// is eqmain.dll loaded
	if (GetModuleHandle("eqmain.dll"))
	{
		// if the eqmain.dll is loaded, we're in the login portion of the client and we missed
		// any events which told us it was loading. Start pulsing from the login frontend.
		AddOurPulse();
	}


	// force a check if user loads us at charselect
	if (GetGameState() == GAMESTATE_CHARSELECT && bReLoggin)
	{
		DWORD nProcs = GetProcessCount("eqgame.exe");
		if (bUseMQ2Login)
		{
			// i dont think we need to load anything here
		}
		else if (!bUseStationNamesInsteadOfSessions)
		{
			std::string sessionName = fmt::format("Session{}", nProcs);
			AutoLoginDebug(sessionName);

			gCurrentAccountName = GetPrivateProfileString(sessionName, "StationName", "", INIFileName);
			gCurrentPassword = GetPrivateProfileString(sessionName, "Password", "", INIFileName);
			gCurrentServerName = GetPrivateProfileString(sessionName, "Server", "", INIFileName);
			gCurrentCharacterName = GetPrivateProfileString(sessionName, "Character", "", INIFileName);
			gCurrentSelectCharacter = GetPrivateProfileString(sessionName, "SelectCharacter", "", INIFileName);
		}
		else if (const char* pLogin = GetLoginName())
		{
			gCurrentAccountName = pLogin;
			gCurrentPassword = GetPrivateProfileString(gCurrentAccountName, "Password", "", INIFileName);
			gCurrentServerName = GetPrivateProfileString(gCurrentAccountName, "Server", "", INIFileName);
			gCurrentCharacterName = GetPrivateProfileString(gCurrentAccountName, "Character", "", INIFileName);
			gCurrentSelectCharacter = GetPrivateProfileString(gCurrentAccountName, "SelectCharacter", "", INIFileName);
		}

		if (!dwServerID || dwServerID == -1 && EQADDR_SERVERNAME[0])
		{
			char szServTemp[MAX_STRING] = { 0 };
			strcpy_s(szServTemp, EQADDR_SERVERNAME);
			DWORD lserver = 0;
			dwServerID = GetServerID(szServTemp);

			if (!gCurrentServerName.empty())
			{
				lserver = GetServerID(gCurrentServerName);
			}

			if (lserver != dwServerID)
			{
				dwServerID = lserver;
				bSwitchServer = true;
			}

			SPAWNINFO* pSpawnInfo = (SPAWNINFO*)pCharSpawn;

			if (gCurrentCharacterName.empty() && pSpawnInfo && pSpawnInfo->Name[0])
			{
				gCurrentCharacterName = pSpawnInfo->Name;
			}
		}
	}
}

PLUGIN_API void ShutdownPlugin()
{
	RemoveCommand("/switchserver");
	RemoveCommand("/switchcharacter");
	RemoveCommand("/relog");

	DWORD pfnGetPrivateProfileIntA = (DWORD)&::GetPrivateProfileIntA;
	RemoveDetour(pfnGetPrivateProfileIntA);

	DWORD pfnGetPrivateProfileStringA = (DWORD)&::GetPrivateProfileStringA;
	RemoveDetour(pfnGetPrivateProfileStringA);

	DWORD pfnWritePrivateProfileStringA = (DWORD)&::WritePrivateProfileStringA;
	RemoveDetour(pfnWritePrivateProfileStringA);

	LoginReset();
}

void RemovePulse()
{
	if (dwEQMainBase)
		dwEQMainBase = 0;
	if (bGotOffsets)
		bGotOffsets = false;
}

PLUGIN_API void SetGameState(DWORD GameState)
{
	bEndAfterCharSelect = GetPrivateProfileInt("Settings", "EndAfterCharSelect", 0, INIFileName) == 1;

	if (GameState == GAMESTATE_PRECHARSELECT)
	{
		if (GetModuleHandle("eqmain.dll"))
		{
			// well well well... what do u know... it's loaded...
			// ok fine that means we wont get any frontload notification, so lets fake it
			if (!LoginController__GiveTime)
				AddOurPulse();
		}
	}
	else if (GameState == GAMESTATE_POSTFRONTLOAD)
	{
		// we know eqmain.dll is loaded now...
		if (!LoginController__GiveTime)
			AddOurPulse();
	}
	else if (GameState == GAMESTATE_CHARSELECT)
	{
		RemovePulse();

		if (dwServerID)
		{
			dwServerID = 0;
			if (!bSwitchChar)
			{
				gNextCharacterName = gCurrentCharacterName;
				bSwitchChar = true;
			}
		}
	}
	else if (GameState == GAMESTATE_INGAME)
	{
		bInGame = true;
	}
}

std::string CurrentCharacter()
{
	if (CListWnd* pCharList = GetChildWindow<CListWnd>("CLW_CharactersScreen", "Character_List"))
	{
		if (pCharList->ItemsArray.Count)
		{
			CXStr str = pCharList->GetItemText(pCharList->CurSel, 2);

			if (!str.empty())
			{
				return std::string{ str };
			}
		}
	}

	return {};
}

int BugTimer = 0;
int retrylogincounter = 0;

PLUGIN_API void OnPulse()
{
	// since in game pulse starts at charselect we can use that for charswitching and serverswithcing as well as relog...
	if (!bLogin && GetAsyncKeyState(VK_HOME) & 1)
	{
		WriteChatf("\agHOME key pressed. AutoLogin Re-Enabled.");
		bEndAfterCharSelect = false;
		bLogin = true;
		return;
	}

	if (GetGameState() == GAMESTATE_INGAME)
	{
		if (retrylogincounter)
			retrylogincounter = 0;
	}

	else if (GetGameState() == GAMESTATE_CHARSELECT)
	{
		// fix for the stuck at char select "Loading Characters" bug.
		BugTimer++;
		if (BugTimer > 100 && retrylogincounter == 0)
		{
			BugTimer = 0;

			if (CSidlScreenWnd* pWnd = (CSidlScreenWnd*)FindMQ2Window("ConfirmationDialogBox"))
			{
				if (pWnd->IsVisible() == 1)
				{
					if (CStmlWnd* Child = (CStmlWnd*)pWnd->GetChildItem("cd_textoutput"))
					{
						if (strstr(Child->STMLText.c_str(), "Loading Characters"))
						{
							// TODO: FIXME
							if (CCharacterListWnd* pCharSelect = *(CCharacterListWnd**)pinstCCharacterListWnd)
							{
								retrylogincounter = 1;
								bLogin = true;

								if (gCurrentServerName.empty())
								{
									gCurrentServerName = GetServerName();
								}

								if (gNextCharacterName.empty())
								{
									gNextCharacterName = CurrentCharacter();
								}
								switchTime = MQGetTickCount64() + 3000;

								pCharSelect->Quit();
								AutoLoginDebug("Quit() called due to charselect list being empty");
							}
						}
					}
				}
			}
		}

		if (dwTime && !gNextCharacterName.empty() && GetAsyncKeyState(VK_END) & 1)
		{
			WriteChatf("END key pressed. Login of %s aborted.", gNextCharacterName.c_str());
			gNextCharacterName.clear();
			dwTime = 0;
			switchTime = 0;
			return;
		}

		if (bSwitchServer)
		{
			// world -> char select
			AutoLoginDebug("SetGameState(GAMESTATE_CHARSELECT): bSwitchServer = true");

			ForeignPointer<CCharacterListWnd> pCharSelect = pinstCCharacterListWnd;
			if (pCharSelect)
			{
				pCharSelect->Quit();
			}

			if (bInjectorUpdate)
			{
				IC_LoaderClearLoaded(gCurrentProfile.c_str(), gCurrentAccountName.c_str(),
					gCurrentServerName.c_str(), gCurrentCharacterName.c_str(), GetCurrentProcessId());
			}
			bInjectorUpdate = false;
			return;
		}

		if (bSwitchChar)
		{
			// we have to give the chatwindow time to show up at char select... so we wait a couple seconds...
			switchTime = MQGetTickCount64() + 2000;
			bSwitchChar = false;

			if (bInjectorUpdate)
			{
				IC_LoaderClearLoaded(gCurrentProfile.c_str(), gCurrentAccountName.c_str(),
					gCurrentServerName.c_str(), gCurrentCharacterName.c_str(), GetCurrentProcessId());
			}
			bInjectorUpdate = false;
			return;
		}

		if (switchTime && switchTime <= MQGetTickCount64() && !gNextCharacterName.empty())
		{
			// at this point the user has 3 seconds to read the message and abort.
			WriteChatf("Selecting \ag%s\ax in 3 seconds. Please wait... or press the END key to abort", gNextCharacterName.c_str());
			switchTime = 0;
			dwTime = MQGetTickCount64() + 3000;
			SelectCharacter(gNextCharacterName, false);

			IC_LoaderSetLoaded(gCurrentProfile.c_str(), gCurrentAccountName.c_str(),
				gCurrentServerName.c_str(), gNextCharacterName.c_str(), GetCurrentProcessId());
			return;
		}

		if (switchTime && switchTime <= MQGetTickCount64() && !gCurrentSelectCharacter.empty())
		{
			// at this point the user has 3 seconds to read the message and abort.
			WriteChatf("Selecting \ag%s\ax in 3 seconds. Please Wait... or press the END key to abort", gCurrentSelectCharacter.c_str());
			switchTime = 0;
			SelectCharacter(gCurrentSelectCharacter, false);

			IC_LoaderSetLoaded(gCurrentProfile.c_str(), gCurrentAccountName.c_str(),
				gCurrentServerName.c_str(), gCurrentCharacterName.c_str(), GetCurrentProcessId());
			return;
		}

		if (!gNextCharacterName.empty() && dwTime && dwTime <= MQGetTickCount64())
		{
			SelectCharacter(gNextCharacterName, true);
			gNextCharacterName.clear();
			dwTime = 0;
		}

		if (gNextCharacterName.empty() && bEndAfterCharSelect && bLogin)
		{
			bLogin = false;
			WriteChatf("\ayAutologin now ended... press HOME to Re-Enable.");
		}
	}
	else if (GetGameState() == GAMESTATE_PRECHARSELECT)
	{
		dwEQMainBase = *(DWORD*)__heqmain;
		LoginPulse();
	}
}

void SelectCharacter(const std::string& characterName, bool enterWorld)
{
	if (characterName.empty())
	{
		AutoLoginDebug("SwitchCharacter failed");

		// should this even be here?
		WriteChatf("\arUsage\ax /switchcharacter \ay<name>\ax");
		return;
	}

	if (CXWnd* pWnd = FindMQ2Window("CLW_CharactersScreen"))
	{
		if (CListWnd* pCharList = (CListWnd*)pWnd->GetChildItem("Character_List"))
		{
			for (int i = 0; i < pCharList->ItemsArray.Count; i++)
			{
				if (ci_equals(characterName, pCharList->GetItemText(i, 2)))
				{
					ForeignPointer<CCharacterListWnd> pCharSelect = pinstCCharacterListWnd;
					if (pCharSelect)
					{
						pCharSelect->SelectCharacter(i);
						if (enterWorld)
						{
							pCharSelect->EnterWorld();
						}
					}

					return;
				}
			}
		}
	}
}

void HandleWindows()
{
	CXMLDataManager* pXmlMgr = pSidlManager->GetParamManager();

	if (!bLogin)
	{
		// we have to check this even when bLogin is false because we could be stuck at charselect in a timeout...
		if (IsWindowActive("serverselect"))
		{
			if (CXWnd* pWnd = GetActiveChildWindow("okdialog", "OK_Display"))
			{
				CXStr str;

				if (pXmlMgr->GetWindowType(pWnd) == UI_STMLBox)
				{
					CStmlWnd* cstm = (CStmlWnd*)pWnd;
					str = cstm->STMLText;
				}
				else
				{
					CSidlScreenWnd* cwnd = (CSidlScreenWnd*)pWnd;
					str = cwnd->GetWindowText();
				}

				if (ci_find_substr(str, "A timeout occurred") != -1)
				{
					bLogin = true;
				}
			}
		}

		return;
	}

	// pair of WindowNames / ButtonNames
	std::vector<std::pair<const char*, const char*>> PromptWindows = {
		{ "OrderWindow", "Order_DeclineButton" },
		{ "EulaWindow", "EULA_AcceptButton" },
		{ "seizurewarning", "HELP_OKButton"},
		{ "OrderExpansionWindow", "OrderExp_DeclineButton" }
	};

	// Click through any dialogs
	for (const auto& [windowName, buttonName] : PromptWindows)
	{
		if (CButtonWnd* pButton = GetActiveChildWindow<CButtonWnd>(windowName, buttonName))
		{
			pButton->WndNotification(pButton, XWM_LCLICK);
			return;
		}
	}

	// click through the splash screen
	if (IsWindowActive("dbgsplash"))
	{
		pLoginViewManager->SendLMouseClick(CXPoint{ 1, 1 }); // WndNotification doesn't work on this
		return;
	}

	if (CButtonWnd* pButton = GetActiveChildWindow<CButtonWnd>("main", "MAIN_ConnectButton"))
	{
		// this clicks the Login Button on the main page so we get the username and password page
		pButton->WndNotification(pButton, XWM_LCLICK);
		return;
	}

	if (CXWnd* pConnectWnd = GetActiveWindow("connect"))
	{
		if (CXWnd* pOkDialog = GetActiveWindow("okdialog"))
		{
			bServerWait = false;
			if (CXWnd* pWnd = GetChildWindow(pOkDialog, "OK_Display"))
			{
				CXStr str;

				if (pXmlMgr->GetWindowType(pWnd) == UI_STMLBox)
				{
					CStmlWnd* pStmlWnd = (CStmlWnd*)pWnd;
					str = pStmlWnd->STMLText;
				}
				else
				{
					str = pWnd->GetWindowText();
				}

				if (str.find("Logging in to the server.  Please wait....") != CXStr::npos)
				{
					return;
				}

				bGotOffsets = false;
				ullerrorwait = MQGetTickCount64() + 2000; // we give the server 5 seconds to catch its breath...

				std::vector<const char*> ErrorMessages = {
					"The server requires that you logout and log back in before proceeding.  Please do so.",
					"failed login attempts on your account since the last time you logged in",
					"The Login Server is currently unavailable.  Please try again later.",
					"Cannot login to the EverQuest server",
					"This login requires a valid",
					"A timeout occurred",
					"A connection to the server could not be reached.",
					"An unknown login error occurred",
					"Invalid Session"
				};

				for (const char* msg : ErrorMessages)
				{
					if (str.find(msg) != CXStr::npos)
					{
						if (CXWnd* pButton = GetChildWindow(pOkDialog, "OK_OKButton"))
							pButton->WndNotification(pButton, XWM_LCLICK);

						return;
					}
				}

				if (str.find("password were not valid") != CXStr::npos
					|| str.find("This login requires that the account be activated.  Please make sure your account is active in order to login.") != CXStr::npos)
				{
					AutoLoginDebug(str);
					bLogin = false;
					return;
				}

				if (str.find("You have a character logged into a world server as an OFFLINE TRADER from this account") != CXStr::npos)
				{
					if (CXWnd* pButton = GetChildWindow(pOkDialog, "YESNO_YesButton"))
						pButton->WndNotification(pWnd, XWM_LCLICK);

					return;
				}
			}

			return;
		}

		if (CEditWnd* pEditWnd = GetChildWindow<CEditWnd>(pConnectWnd, "LOGIN_PasswordEdit"))
		{
			if (pEditWnd->InputText.empty())
				bWait = false;
		}

		if (bWait)
			return;

		if (CEditWnd* pEditWnd = GetChildWindow<CEditWnd>(pConnectWnd, "LOGIN_UsernameEdit"))
		{
			if (bUseMQ2Login)
			{
				AutoLoginDebug("HandleWindows(): Using MQ2Login Method");

				if (!pEditWnd->InputText.empty())
				{
					std::string userName{ pEditWnd->InputText };
					gCurrentProfile = userName;
					AutoLoginDebug(fmt::format("HandleWindows() userName({})", userName));

					size_t pos = gCurrentProfile.find("_");
					if (pos != std::string::npos)
					{
						std::string blobKey = fmt::format("{}_Blob", gCurrentProfile.substr(pos + 1));
						gCurrentProfile = gCurrentProfile.substr(0, pos);
						std::string characterName = blobKey;

						AutoLoginDebug(fmt::format("HandleWindows() gCurrentProfile({}), characterName({})", gCurrentProfile, characterName));

						size_t colPos = characterName.find(":");
						if (colPos != std::string::npos)
						{
							gCurrentServerName = characterName.substr(0, colPos);
						}
						else
						{
							gCurrentServerName = userName;
						}

						AutoLoginDebug(fmt::format("HandleWindows() gCurrentProfile({}), blobKey({}), gCurrentServerName({})",
							gCurrentProfile, blobKey, gCurrentServerName));

						// now that we have the server and the charname, we can figure out the stationname and password from the blob
						std::string blob = GetPrivateProfileString(gCurrentProfile, blobKey, "", INIFileName);
						if (!blob.empty())
						{
							size_t stripPos = blob.rfind("=");
							if (stripPos != std::string::npos)
							{
								blob = blob.substr(0, stripPos);
							}

							AutoLoginDebug(fmt::format("HandleWindows() szBlob({})", blob));

							ProfileRecord record;

							if (ParseBlob(blob, record))
							{
								gCurrentAccountName = record.accountName;
								gCurrentPassword = record.accountPassword;
								gCurrentCharacterName = record.characterName;
								gCurrentCharacterClass = record.characterClass;
								gCurrentCharacterLevel = record.characterLevel;

								IC_LoaderSetLoaded(gCurrentProfile.c_str(), gCurrentAccountName.c_str(),
									gCurrentServerName.c_str(), gCurrentCharacterName.c_str(), GetCurrentProcessId());
							}
						}

						DWORD oldscreenmode = std::exchange(ScreenMode, 3);
						ScreenMode = 3;

						pEditWnd->InputText.clear(); // ???
						pEditWnd->InputText = gCurrentAccountName;

						ScreenMode = oldscreenmode;
					}
					else if (userName.find("^") != std::string::npos)
					{
						// special login no profile just plaintext login

						// server^stationname^charname^pass
						// if charname is empty we just stop at charselect.

						std::vector<std::string> parts = split(userName, '^');

						switch (parts.size())
						{
						case 4:
							gCurrentPassword = parts[3];
							gCurrentCharacterName = parts[2];
							gCurrentAccountName = parts[1];
							gCurrentServerName = parts[0];
							break;

						case 3:
							gCurrentPassword = parts[2];
							gCurrentAccountName = parts[1];
							gCurrentServerName = parts[0];
							break;
						}

						// FIXME: Error handling

						DWORD oldscreenmode = std::exchange(ScreenMode, 3);

						pEditWnd->InputText.clear();
						pEditWnd->InputText = gCurrentAccountName;

						ScreenMode = oldscreenmode;
					}
					else if (userName.find(";") != std::string::npos)
					{
						// special login:
						// basically this allows for a piped login where password, server, and name
						// are sent directly. Should not be used under normal circumstances but its
						// handy when u want a quick way to login a char(s) that is not a regular
						// from your profile(s).
						// format is: Server;Profile:Character;

						// FIXME: this code makes no sense. It needs some fixing.
						std::size_t pos = userName.find(';');

						gCurrentServerName = userName.substr(0, pos);
						gCurrentCharacterName = userName.substr(pos + 1);
						gCurrentProfile = gCurrentCharacterName;

						pos = gCurrentProfile.find(":");
						if (pos != std::string::npos)
						{
							gCurrentServerName = gCurrentProfile.substr(0, pos);
						}

						// now that we have the server and the charname, we can figure out the stationname and password from the blob
						std::string blob = GetPrivateProfileString(gCurrentServerName, gCurrentCharacterName, "", INIFileName);

						if (!blob.empty())
						{
							size_t stripPos = blob.rfind("=");
							if (stripPos != std::string::npos)
							{
								blob = blob.substr(0, stripPos);
							}

							ProfileRecord record;

							if (ParseBlob(blob, record))
							{
								gCurrentAccountName = record.accountName;
								gCurrentPassword = record.accountPassword;
								gCurrentCharacterName = record.characterName;
								gCurrentCharacterClass = record.characterClass;
								gCurrentCharacterLevel = record.characterLevel;

								IC_LoaderSetLoaded(gCurrentProfile.c_str(), gCurrentAccountName.c_str(),
									gCurrentServerName.c_str(), gCurrentCharacterName.c_str(), GetCurrentProcessId());
							}
						}

						DWORD oldscreenmode = std::exchange(ScreenMode, 3);

						pEditWnd->InputText.clear();
						pEditWnd->InputText = gCurrentAccountName;

						ScreenMode = oldscreenmode;
					}
				}
			}
			else if (bUseStationNamesInsteadOfSessions)
			{
				AutoLoginDebug("HandleWindows(): Using station name instead of session number");
				bLoginCheckDone = true;

				// If the user used /login then we already have a login name and it may not yet be set
				if (!pEditWnd->InputText.empty() && gCurrentAccountName.empty())
				{
					gCurrentAccountName = pEditWnd->InputText;
				}

				pEditWnd->InputText = gCurrentAccountName;

				if (!gCurrentAccountName.empty())
				{
					gCurrentPassword =GetPrivateProfileString(gCurrentAccountName, "Password", "", INIFileName);
					gCurrentServerName = GetPrivateProfileString(gCurrentAccountName, "Server", "", INIFileName);
					gCurrentCharacterName = GetPrivateProfileString(gCurrentAccountName, "Character", "", INIFileName);
					gCurrentSelectCharacter = GetPrivateProfileString(gCurrentAccountName, "SelectCharacter", "", INIFileName);
				}
				else
				{
					AutoLoginDebug("HandleWindows(): No station name found in LOGIN_UsernameEdit");
					bLogin = false;
					return;
				}
			}

			if (gCurrentAccountName.empty() || gCurrentPassword.empty() || gCurrentServerName.empty())
			{
				AutoLoginDebug("*** Login data couldn't be retrieved.  Please check your ini file.");
				bLogin = false;
				return;
			}

			if (bUseMQ2Login)
			{
				// dont need to do anything, we already done this.
			}
			else if (!bUseStationNamesInsteadOfSessions)
			{
				pEditWnd->InputText.clear();
				pEditWnd->InputText = gCurrentAccountName;
			}

			if (CEditWnd* pPasswordEdit = GetChildWindow<CEditWnd>(pConnectWnd, "LOGIN_PasswordEdit"))
			{
				pPasswordEdit->InputText = gCurrentPassword;

				if (CButtonWnd* pConnectButton = GetChildWindow<CButtonWnd>(pConnectWnd, "LOGIN_ConnectButton"))
				{
					DWORD oldscreenmode = std::exchange(ScreenMode, 3);

					pConnectButton->WndNotification(pConnectButton, XWM_LCLICK);

					ScreenMode = oldscreenmode;
					bWait = true;
					return;
				}
			}
		}

		return;
	}

	if (IsWindowActive("serverselect"))
	{
		if (bInGame)
			return;

		bWait = false;

		if (gCurrentPassword.empty())
		{
			gCurrentPassword = GetPassword();
		}

		if (IsWindowActive("okdialog"))
		{
			CXWnd* pOkDialog = WindowMap["okdialog"];
			if (CXWnd* pWnd = pOkDialog->GetChildItem(pXmlMgr, "OK_Display"))
			{
				CXStr str;

				if (pXmlMgr->GetWindowType(pWnd) == UI_STMLBox)
				{
					CStmlWnd* pStmlWnd = (CStmlWnd*)pWnd;
					str = pStmlWnd->STMLText;
				}
				else
				{
					str = pWnd->GetWindowText();
				}

				bGotOffsets = false;
				ullerrorwait = MQGetTickCount64() + 2000; // we give the server 5 seconds to catch its breath...

				CButtonWnd* pOkButton = (CButtonWnd*)pOkDialog->GetChildItem(pXmlMgr, "OK_OKButton");

				if (strstr(str.c_str(), "The world server is currently at maximum capacity. You are still in the login queue for this server")
					|| strstr(str.c_str(), "The world server is currently at maximum capacity. You have been added to the login queue for this server"))
				{
					if (pOkButton)
						pOkButton->WndNotification(pOkButton, XWM_LCLICK);

					// 3 mins 5 seconds... no need to click login again and again when this message has been shown...
					ullerrorwait = MQGetTickCount64() + 185000;
					bServerWait = false;
					return;
				}

				std::vector<const char*> ErrorMessages = {
					"The world server is currently at maximum capacity and not allowing further logins until the number of players online decreases.  Please try again later.",
					"That server is currently unavailable",
					"An unknown error occurred while trying to join the server.",
					"The connection has been terminated by the server.  Most likely you have been inactive",
					"A timeout occurred"
				};

				for (const char* msg : ErrorMessages)
				{
					if (strstr(str.c_str(), msg))
					{
						if (pOkButton)
							pOkButton->WndNotification(pOkButton, XWM_LCLICK);
					}
				}
			}

			bServerWait = false;
			return;
		}

		if (IsWindowActive("yesnodialog"))
		{
			CXWnd* pDialog = WindowMap["yesnodialog"];

			if (CXWnd* pWnd = pDialog->GetChildItem(pXmlMgr, "YESNO_Display"))
			{
				CXStr str;

				if (pXmlMgr->GetWindowType(pWnd) == UI_STMLBox)
				{
					CStmlWnd* pStmlWnd = (CStmlWnd*)pWnd;
					str = pStmlWnd->STMLText;
				}
				else
				{
					str = pWnd->GetWindowText();
				}

				// kick active character?
				if (strstr(str.c_str(), "You already have a character logged into a world server from this account."))
				{
					CButtonWnd* pButton = (CButtonWnd*)pDialog->GetChildItem(pXmlMgr,
						bKickActiveChar ? "YESNO_YesButton" : "YESNO_NoButton");

					if (pButton)
					{
						pButton->WndNotification(pButton, XWM_LCLICK);
					}

					bLogin = false;
				}
				else if (strstr(str.c_str(), "You have a character logged into a world server as an OFFLINE TRADER from this account."))
				{
					if (CButtonWnd* pButton = (CButtonWnd*)pDialog->GetChildItem(pXmlMgr, "YESNO_YesButton"))
					{
						pButton->WndNotification(pButton, XWM_LCLICK);
					}

					bLogin = false;
				}
			}

			bWait = false;
			bServerWait = false;
			return;
		}

		if (gCurrentServerName.empty())
		{
			AutoLoginDebug("HandleWindows(): szServerName is empty at serverselect. Ending Login");

			bLogin = false;
			bEnd = true;
			return;
		}

		if (bServerWait)
			return;

		if (dwServerID = GetServerID(gCurrentServerName))
		{
			if (CheckServerUp(dwServerID))
			{
				if (bWeAreDown)
				{
					bWeAreDown = false;

					if (NotifyOnServerUp == 2)
					{
						if (IsCommand("/gmail"))
						{
							DoCommand(nullptr, R"(/gmail "Server is up" "Time to login!")");
						}

						NotifyOnServerUp = 0;
					}
					else if (NotifyOnServerUp == 1)
					{
						Beep(1000, 1000);
						Beep(500, 2000);
						Beep(1000, 1000);
						NotifyOnServerUp = 0;
					}
				}

				pLoginServerAPI->JoinServer(dwServerID);
				bSwitchServer = false;
				bServerWait = true;
			}
			else
			{
				ullerrorwait = MQGetTickCount64() + 2000;
			}
		}
		else
		{
			AutoLoginDebug(fmt::format("HandleWindows(): GetServerId({}) returned 0 at serverselect", gCurrentServerName));
		}
		return;
	}

	if (CXWnd* pNewsWnd = GetActiveWindow("news"))
	{
		if (CXWnd* pWnd = pNewsWnd->GetChildItem(pXmlMgr, "NEWS_WndLabel"))
		{
			CXStr str;

			if (pXmlMgr->GetWindowType(pWnd) == UI_STMLBox)
			{
				CStmlWnd* pStmlWnd = (CStmlWnd*)pWnd;
				str = pStmlWnd->STMLText;
			}
			else
			{
				str = pWnd->GetWindowText();
			}

			// click OK button if news window is open
			if (ci_find_substr(str, "NEWS"))
			{
				if (CXWnd* pButton = pNewsWnd->GetChildItem(pXmlMgr, "NEWS_OKButton"))
				{
					pButton->WndNotification(pButton, XWM_LCLICK);
				}
			}
		}
	}
}

DWORD GetProcessCount(char* exeName)
{
	HANDLE hnd = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 proc;
	proc.dwSize = sizeof(PROCESSENTRY32);
	DWORD n = 0;

	if (Process32First(hnd, &proc))
	{
		do
		{
			if (!_stricmp(proc.szExeFile, exeName))
				n++;
		} while (Process32Next(hnd, &proc));
	}

	CloseHandle(hnd);

	return n;
}

void LoginReset()
{
	AutoLoginDebug("LoginReset()");

	bLogin = false;
	bInGame = true;
	pSidlManager = 0;
	pWindowManager = 0;
	pLoginViewManager = 0;
	WindowMap.clear();
}

void AutoLoginDebug(std::string_view svLogMessage, const bool bDebugOn /* = AUTOLOGIN_DBG */)
{
	if (bDebugOn)
	{
		std::filesystem::path pathToDebugLog = gPathLogs;
		pathToDebugLog /= "MQ2AutoLogin_DBG.log";

		FILE* fLog = nullptr;
		const errno_t err = fopen_s(&fLog, pathToDebugLog.string().c_str(), "a");

		if (err || !fLog)
		{
			DebugSpewAlways("Could not open MQ2Autologin Debug log for appending.");
		}
		else
		{
			SYSTEMTIME t;
			GetLocalTime(&t);

			const std::string strLogMessage = fmt::format("[{Year:0=4d}-{Month:0=2d}-{Day:0=2d} {Hour:0=2d}:{Minute:0=2d}:{Second:0=2d}] {LogMessage}",
			                            fmt::arg("Year", t.wYear),
			                                  fmt::arg("Month", t.wMonth),
			                                  fmt::arg("Day", t.wDay),
			                                  fmt::arg("Hour", t.wHour),
			                                  fmt::arg("Minute", t.wMinute),
			                                  fmt::arg("Second", t.wSecond),
			                                  fmt::arg("LogMessage", svLogMessage));

			DebugSpewAlways(strLogMessage.c_str());
			fprintf(fLog, "%s\n", strLogMessage.c_str());
			fclose(fLog);
		}
	}
}
