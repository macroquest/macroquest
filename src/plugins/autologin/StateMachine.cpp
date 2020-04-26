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

#include "AutoLoginShared.h"
#include "MQ2AutoLogin.h"

#include <optional>
#include <regex>
#include <TlHelp32.h>

#pragma region client_data

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
	void*     A_Callback_vfTable;
	void*     ChannelServerHandler_vfTable;
	EQLOGIN*  pLoginData;
	DoublyLinkedList<HOST*> Hosts;
	HOST*     pHost;
	bool      bRetryConnect;
	// more below don't need right now
};

DWORD dwSendLMouseClickAddr = 0;
DWORD dwEnterGameAddr = 0;

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

CLoginViewManager* pLoginViewManager = nullptr;
ForeignPointer<SERVERSTUFF> pServerInfo;
ForeignPointer<LoginServerAPI> pLoginServerAPI;

//----------------------------------------------------------------------------
// eqmain.dll

// A3 ? ? ? ? E8 ? ? ? ? 83 C4 ? 85 C0 74 ? 8B 96 ? ? ? ? 52 57 8B C8 E8 ? ? ? ? EB ?
// Feb 16 2018 Test
// A3 ? ? ? ? E8 ? ? ? ? 83 C4 04 85 C0
// LoginViewManager* pLoginViewManager
PBYTE lvmPattern = (PBYTE)"\xA3\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x83\xC4\x04\x85\xC0";
char lvmMask[] = "x????x????xxxxx";

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

#pragma endregion

// TODO:
// - Crashes when going back sometimes due to CXWnd lookups, tighten this up some
// - Figure out how to tie this into the backend
// - Injecting while running doesn't load the config

static std::optional<ProfileRecord> UseMQ2Login(CEditWnd* pEditWnd)
{
	AutoLoginDebug("UseMQ2Login(): Using MQ2Login Method");

	// we expect this to be populated because we feed eqgame.exe with a `/login:` parameter
	if (pEditWnd && !pEditWnd->InputText.empty())
	{
		std::string input(pEditWnd->InputText);
		AutoLoginDebug(fmt::format("UseMQ2Login() input({})", input));

		// we can use regex here because this is not a time-critical process, and makes the
		// code easier to read

		// store our matches in here
		std::smatch matches;

		// the first method of username format is underscores
		// we expect here a format of `<profile>_<server>:<user>`
		std::regex blob_regex("(\\S+)_(\\w+):(\\S+)"); // TODO: do we need one of these for just server?
		std::regex plain_regex("(\\S+)\\^(\\S+)\\^(\\S+)\\^(\\S+)");
		std::regex plain2_regex("(\\S+)\\^(\\S+)\\^(\\S+)");
		std::regex special_regex("(\\S+);(\\S+):(\\S+);");

		if (std::regex_match(input, matches, blob_regex))
		{
			// <profile>_<server>:<character>
			auto profile = matches[1].str();
			auto server = matches[2].str();
			auto character = matches[3].str();

			auto blobKey = fmt::format("{}:{}_Blob", server, character);
			AutoLoginDebug(fmt::format("UseMQ2Login() blobKey({})", blobKey));

			std::string blob = GetPrivateProfileString(profile, blobKey, "", INIFileName);
			if (!blob.empty())
			{
				blob = split(blob, '=').at(0); // remove the "checked" status
				AutoLoginDebug(fmt::format("UseMQ2Login() blob({})", blob));

				ProfileRecord record;
				if (ParseBlob(blob, record))
				{
					record.profileName = profile;
					record.serverName = server;
					return record;
				}
			}
		}
		else if (std::regex_match(input, matches, plain_regex))
		{

			// <server>^<stationname>^<charname>^<pass>
			ProfileRecord record;
			record.profileName = "";
			record.serverName = matches[1].str();
			record.accountName = matches[2].str();
			record.characterName = matches[3].str();
			record.accountPassword = matches[4].str();

			return record;
		}
		else if (std::regex_match(input, matches, plain2_regex))
		{

			// <server>^<stationname>^<pass>
			ProfileRecord record;
			record.profileName = "";
			record.serverName = matches[1].str();
			record.accountName = matches[2].str();
			record.accountPassword = matches[3].str();

			return record;
		}
		else if (std::regex_match(input, matches, special_regex))
		{
			// unsure why we need this option when the first option is exactly equivalent
			// <server>;<profile>:<character>;
			auto server = matches[1].str();
			auto profile = matches[2].str();
			auto character = matches[3].str();

			auto blobKey = fmt::format("{}:{}_Blob", server, character);
			AutoLoginDebug(fmt::format("UseMQ2Login() blobKey({})", blobKey));

			std::string blob = GetPrivateProfileString(profile, blobKey, "", INIFileName);
			if (!blob.empty())
			{
				blob = split(blob, '=').at(0); // remove the "checked" status
				AutoLoginDebug(fmt::format("UseMQ2Login() blob({})", blob));

				ProfileRecord record;
				if (ParseBlob(blob, record))
				{
					record.profileName = profile;
					record.serverName = server;
					return record;
				}
			}
		}
	}

	return std::nullopt;
}

static std::optional<ProfileRecord> UseStationNames(CEditWnd* pEditWnd, std::string_view AccountName = "")
{
	std::string account(AccountName);
	if (pEditWnd && !pEditWnd->InputText.empty() && account.empty())
		account = pEditWnd->InputText;

	if (!account.empty())
	{
		ProfileRecord record;
		record.profileName = "";
		record.accountName = account;
		record.accountPassword = GetPrivateProfileString(account, "Password", "", INIFileName);
		record.serverName = GetPrivateProfileString(account, "Server", "", INIFileName);
		record.characterName = GetPrivateProfileString(account, "Character", "", INIFileName);

		return record;
	}

	return std::nullopt;
}

static std::optional<ProfileRecord> UseSessions(CEditWnd* pEditWnd)
{
	HANDLE hnd = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 proc;
	proc.dwSize = sizeof(PROCESSENTRY32);
	DWORD nProcs = 0;

	if (Process32First(hnd, &proc))
	{
		do
		{
			if (!_stricmp(proc.szExeFile, "eqgame.exe"))
				++nProcs;
		} while (Process32Next(hnd, &proc));
	}

	CloseHandle(hnd);

	std::string sessionName = fmt::format("Session{}", nProcs);
	ProfileRecord record;
	record.profileName = "";

	record.accountName = GetPrivateProfileString(sessionName, "StationName", "", INIFileName);
	record.accountPassword = GetPrivateProfileString(sessionName, "Password", "", INIFileName);
	record.serverName = GetPrivateProfileString(sessionName, "Server", "", INIFileName);
	record.characterName = GetPrivateProfileString(sessionName, "Character", "", INIFileName);

	return record;
}

class Wait;
class LoadOffsets;
class SplashScreen;
class Connect;
class ConnectConfirm;
class ServerSelect;
class ServerSelectConfirm;
class ServerSelectKick;
class ServerSelectDown;
class CharacterSelect;
class CharacterSelectWait;
class InGame;

class Wait : public Login 
{
public:
	void entry() override
	{
		auto new_delay = MQGetTickCount64() + 2000; // TODO: configure short delay
		m_delayTime = new_delay > m_delayTime ? new_delay : m_delayTime; // this allows us to specify longer waits if we need them
	}

	void react(LoginStateSensor const& e) override
	{
		if (!m_offsetsLoaded && GetModuleHandle("eqmain.dll"))
		{
			transit<LoadOffsets>();
		}
		else if (m_offsetsLoaded && !m_paused && (e.State != m_lastState || m_delayTime < MQGetTickCount64()))
		{
			// we only want to actually delay in this state if there is no transition
			m_currentWindow = e.Window;

			switch (e.State)
			{
			case LoginState::LoadOffsets:
				transit<LoadOffsets>();
				break;
			case LoginState::SplashScreen:
				transit<SplashScreen>();
				break;
			case LoginState::Connect:
			{
				CEditWnd* pEditWnd = GetChildWindow<CEditWnd>(m_currentWindow, "LOGIN_PasswordEdit");

				// If we have an empty password input field, transit to connect. Otherwise, wait.
				if (pEditWnd != nullptr && pEditWnd->InputText.empty())
					transit<Connect>();
				else
					transit<Wait>(); // this will reset the delay
				break;
			}
			case LoginState::ConnectConfirm:
				transit<ConnectConfirm>();
				break;
			case LoginState::ServerSelect:
				transit<ServerSelect>();
				break;
			case LoginState::ServerSelectConfirm:
				transit<ServerSelectConfirm>();
				break;
			case LoginState::ServerSelectKick:
				transit<ServerSelectKick>();
				break;
			case LoginState::ServerSelectDown:
				transit<ServerSelectDown>();
				break;
			case LoginState::CharacterSelect:
			{
				auto pWnd = GetWindow<CSidlScreenWnd>("ConfirmationDialogBox");
				auto pChild = GetChildWindow<CStmlWnd>(pWnd, "cd_textoutput");
				if (pWnd != nullptr && pWnd->IsVisible() == 1 && pChild && pChild->STMLText.find("Loading Characters") != CXStr::npos)
				{
					// fix for the stuck at char select "Loading Characters" bug
					// need to quit and re-enter the character select screen if we've already waited once
					// if the connection is slow, then the shrot wait time should be extended past 2 seconds
					if (pCharacterListWnd && m_lastState == e.State)
						pCharacterListWnd->Quit();

					transit<Wait>();
				}
				else
				{
					transit<CharacterSelect>();
				}

				break;
			}
			case LoginState::InGame:
				// check this here because InGame will be the longest waiting state, don't do transits into self because they aren't useful
				if (m_lastState != LoginState::InGame) transit<InGame>();
				break;
			default:
				break;
			}

			m_lastState = e.State;
		}
	}
};

class LoadOffsets : public Login
{
public:
	void entry() override
	{
		DWORD eqmain_base = *(DWORD*)__heqmain;
		if (!eqmain_base)
		{
			m_paused = true;
		}
		else
		{
			uint32_t login_client = FindPattern(eqmain_base, 0x100000, LoginServerAPI_Pattern, LoginServerAPI_Mask);
			uint32_t enter_game = FindPattern(eqmain_base, 0x200000, lcEGPattern, lcEGMask);
			uint32_t mouse_click = FindPattern(eqmain_base, 0x100000, lmousePattern, lmouseMask);
			uint32_t login_manager = FindPattern(eqmain_base, 0x200000, lvmPattern, lvmMask);

			if (login_client != 0 && enter_game != 0 && mouse_click != 0 && login_manager != 0)
			{
				pLoginServerAPI = GetDWordAt(login_client, 2);
				dwEnterGameAddr = enter_game;
				dwSendLMouseClickAddr = mouse_click;
				login_manager = GetDWordAt(login_manager, 1);
				pServerInfo = login_manager - 4;
				pLoginViewManager = reinterpret_cast<CLoginViewManager*>(*(DWORD*)login_manager);
				m_offsetsLoaded = true;
			}
			else
			{
				AutoLoginDebug(fmt::format("Could not find {}{}{}{}from pattern(s)",
					login_client == 0 ? "login_client " : "",
					enter_game == 0 ? "enter_game " : "",
					mouse_click == 0 ? "mouse_click " : "",
					login_manager == 0 ? "login_manager " : ""));

				m_paused = true;
			}
		}

		transit<Wait>();
	}
};

class SplashScreen : public Login
{
public:
	void entry() override
	{
		pLoginViewManager->SendLMouseClick(CXPoint(1, 1));
		transit<Wait>();
	}
};

class Connect : public Login
{
public:
	void entry() override
	{
		// enter the username into the field
		if (auto pEditWnd = GetChildWindow<CEditWnd>(m_currentWindow, "LOGIN_UsernameEdit"))
		{
			std::optional<ProfileRecord> record = std::nullopt;
			switch (s_loginSettings.LoginType)
			{
			case LoginSettings::Type::MQ2Login:
				record = UseMQ2Login(pEditWnd);
				break;
			case LoginSettings::Type::StationNames:
				record = UseStationNames(pEditWnd);
				break;
			case LoginSettings::Type::Sessions:
				record = UseSessions(pEditWnd);
				break;
			default:
				break;
			}

			if (record)
			{
				m_serverName = record->serverName;
				m_characterName = record->characterName;

				DWORD oldscreenmode = std::exchange(ScreenMode, 3);
				pEditWnd->InputText = record->accountName;

				if (CEditWnd* pPasswordEdit = GetChildWindow<CEditWnd>(m_currentWindow, "LOGIN_PasswordEdit"))
				{
					pPasswordEdit->InputText = record->accountPassword;
					if (CButtonWnd* pConnectButton = GetChildWindow<CButtonWnd>(m_currentWindow, "LOGIN_ConnectButton"))
						pConnectButton->WndNotification(pConnectButton, XWM_LCLICK);
				}

				ScreenMode = oldscreenmode;
			}
		}

		transit<Wait>();
	}
};

class ConnectConfirm : public Login
{
public:
	void entry() override
	{
		if (CXWnd* pWnd = GetChildWindow(m_currentWindow, "OK_Display"))
		{
			CXMLDataManager* pXmlMgr = pSidlMgr->GetParamManager();
			CXStr str = pXmlMgr->GetWindowType(pWnd) == UI_STMLBox ?
				static_cast<CStmlWnd*>(pWnd)->STMLText :
				pWnd->GetWindowText();

			if (str.find("Logging in to the server.  Please wait....") != CXStr::npos)
			{
				// successful log in, transit
			}
			else if (str.find("password were not valid") != CXStr::npos
				|| str.find("This login requires that the account be activated.  Please make sure your account is active in order to login.") != CXStr::npos)
			{
				AutoLoginDebug(fmt::format("ConnectConfirm: {}", str));
				m_paused = true; // we can't recover from these, so pause autologin
			}
			else if (str.find("You have a character logged into a world server as an OFFLINE TRADER from this account") != CXStr::npos)
			{
				// kick off our offline trader
				if (CXWnd* pButton = GetChildWindow(m_currentWindow, "YESNO_YesButton"))
					pButton->WndNotification(pWnd, XWM_LCLICK);
			}
			else
			{
				// potential error messages, just click through if we find an ok button
				//std::vector<const char*> ErrorMessages = {
				//	"The server requires that you logout and log back in before proceeding.  Please do so.",
				//	"failed login attempts on your account since the last time you logged in",
				//	"The Login Server is currently unavailable.  Please try again later.",
				//	"Cannot login to the EverQuest server",
				//	"This login requires a valid",
				//	"A timeout occurred",
				//	"A connection to the server could not be reached.",
				//	"An unknown login error occurred",
				//	"Invalid Session"
				//};

				if (CXWnd* pButton = GetChildWindow(m_currentWindow, "OK_OKButton"))
					pButton->WndNotification(pButton, XWM_LCLICK);

			}
		}

		transit<Wait>();
	}
};

class ServerSelect : public Login
{
public:
	template<typename Predicate>
	static SERVERLIST* GetServer(Predicate predicate)
	{
		if (GetGameState() != GAMESTATE_PRECHARSELECT)
			return nullptr;

		auto server_list = GetChildWindow<CListWnd>("serverselect", "SERVERSELECT_ServerList");
		if (server_list && !server_list->ItemsArray.IsEmpty() && pServerInfo && pServerInfo->pServerList && pServerInfo->pServerList->Info)
		{
			auto pList = pServerInfo->pServerList;
			while (pList)
			{
				if (predicate(pList))
					return pList;

				pList = pList->Next;
			}
		}

		return nullptr;
	}

	template <typename Action>
	static bool CheckServerDown(Action action)
	{
		if (m_serverName.empty())
		{
			AutoLoginDebug(fmt::format("ServerSelect: server name is empty"));
			m_paused = true; // no server to select, pause
			return false;
		}
		else
		{
			// get server
			const auto& live_server = ServerData.find(m_serverName);
			const auto& server_name = live_server == std::cend(ServerData) ? GetServerLongName(m_serverName) : std::string(live_server->first);
			int server_id = live_server == std::cend(ServerData) ? -1 : live_server->second;

			// note that this predicate ensures that a server has a non-null Info member
			auto server = GetServer([&server_name, &server_id](SERVERLIST* s)
				{
					return s->Info && (s->Info->ID == server_id || ci_equals(s->Info->ServerName, server_name));
				});

			if (!server)
			{
				// no server found, wait
				AutoLoginDebug(fmt::format("ServerSelect: Could not find server {}", m_serverName));
				return false;
			}
			else if (server->Info->StatusFlags & (eServerStatus_Down | eServerStatus_Locked))
			{
				return true;
			}
			else
			{
				action();
				// join server (both server and Info are already guaranteed to be non-null)
				pLoginServerAPI->JoinServer(server->Info->ID);
				return false;
			}
		}
	}

	void entry() override
	{
		if (CheckServerDown([]() {}))
			transit<ServerSelectDown>();
		else
			transit<Wait>();
	}
};

class ServerSelectConfirm : public Login
{
public:
	void entry() override
	{
		if (CXWnd* pWnd = GetChildWindow(m_currentWindow, "OK_Display"))
		{
			CXMLDataManager* pXmlMgr = pSidlMgr->GetParamManager();
			CXStr str = pXmlMgr->GetWindowType(pWnd) == UI_STMLBox ?
				static_cast<CStmlWnd*>(pWnd)->STMLText :
				pWnd->GetWindowText();

			if (str.find("The world server is currently at maximum capacity") != CXStr::npos)
			{
				// this is the longwait condition, so add a delay
				m_delayTime = MQGetTickCount64() + 185000; // TODO: configure longwait
			}

			// some potential error messages -- (no need to check for the text, we are just going to click)
			//std::vector<const char*> ErrorMessages = {
			//	"The world server is currently at maximum capacity and not allowing further logins until the number of players online decreases.  Please try again later.",
			//	"That server is currently unavailable",
			//	"An unknown error occurred while trying to join the server.",
			//	"The connection has been terminated by the server.  Most likely you have been inactive",
			//	"A timeout occurred"
			//};

			if (CXWnd* pButton = GetChildWindow(m_currentWindow, "OK_OKButton"))
				pButton->WndNotification(pButton, XWM_LCLICK);
		}

		transit<Wait>();
	}
};

class ServerSelectKick : public Login
{
public:
	void entry() override
	{
		if (CXWnd* pWnd = GetChildWindow(m_currentWindow, "YESNO_Display"))
		{
			CXMLDataManager* pXmlMgr = pSidlMgr->GetParamManager();
			CXStr str = pXmlMgr->GetWindowType(pWnd) == UI_STMLBox ?
				static_cast<CStmlWnd*>(pWnd)->STMLText :
				pWnd->GetWindowText();

			if (str.find("You already have a character logged into a world server from this account.") != CXStr::npos)
			{
				auto pButton = GetChildWindow<CButtonWnd>(m_currentWindow,
					s_loginSettings.KickActiveCharacter ? "YESNO_YesButton" : "YESNO_NoButton");

				if (!pButton || !s_loginSettings.KickActiveCharacter)
					m_paused = true;

				if (pButton)
					pButton->WndNotification(pButton, XWM_LCLICK);
			}
			else if (str.find("You have a character logged into a world server as an OFFLINE TRADER from this account.") != CXStr::npos)
			{
				auto pButton = GetChildWindow<CButtonWnd>(m_currentWindow, "YESNO_YesButton");
				if (pButton)
					pButton->WndNotification(pButton, XWM_LCLICK);
				else
					m_paused = true;
			}
		}

		transit<Wait>();
	}
};

// this inherits Wait so that we can transition to other action states while we are waiting for the server to come up
// doing so will stop the server down logic.
class ServerSelectDown : public Wait
{
public:
	void react(LoginStateSensor const& e) override
	{
		// we only want to actually delay in this state if there is no transition
		if (e.State != m_lastState || m_delayTime < MQGetTickCount64())
		{
			m_lastState = e.State;
			m_currentWindow = e.Window;

			switch (e.State)
			{
			case LoginState::ServerSelect:
				if (ServerSelect::CheckServerDown([]()
					{
						switch (s_loginSettings.NotifyOnServerUp)
						{
						case LoginSettings::ServerUpNotification::Email:
							if (IsCommand("/gmail"))
								DoCommand(nullptr, R"(/gmail "Server is up" "Time to login!")");
							break;
						case LoginSettings::ServerUpNotification::Beeps:
							Beep(1000, 1000);
							Beep(500, 2000);
							Beep(1000, 1000);
							break;
						default:
							break;
						}
					}))
					transit<ServerSelectDown>();
				else
					transit<Wait>();
				break;
			default:
				Wait::react(e);
				break;
			}
		}
	}
};

class CharacterSelect : public Login
{
public:
	void entry() override
	{
		if (auto pCharList = GetChildWindow<CListWnd>(m_currentWindow, "Character_List"))
		{
			if (!EQADDR_SERVERNAME || !ci_equals(EQADDR_SERVERNAME, m_serverName))
			{
				// wrong server, need to quit character select to get to the server select window
				if (pCharacterListWnd)
					pCharacterListWnd->Quit();

				transit<Wait>();
			}
			else
			{
				// no selection has been made yet, so make the selection and enter world
				auto index = [&pCharList]()
				{
					for (int i = 0; i < pCharList->ItemsArray.Count; ++i)
					{
						if (ci_equals(m_characterName, pCharList->GetItemText(i, 2)))
							return i;
					}

					return -1;
				}();

				if (index < 0)
				{
					m_paused = true;
					transit<Wait>();
				}
				else
				{
					if (pCharacterListWnd != nullptr)
						pCharacterListWnd->SelectCharacter(index);

					m_delayTime = MQGetTickCount64() + 3000;
					WriteChatf(fmt::format("Selecting \ag{}\ax in 3 seconds. Please Wait... or press the END key to abort", pCharList->GetItemText(index, 2)).c_str());
					transit<CharacterSelectWait>();
				}
			}
		}
		else {
			transit<Wait>();
		}
	}
};

class CharacterSelectWait : public Wait
{
public:
	void react(LoginStateSensor const& e) override
	{
		// we only want to actually delay in this state if there is no transition
		if (e.State != m_lastState || m_delayTime < MQGetTickCount64())
		{
			m_lastState = e.State;
			m_currentWindow = e.Window;

			switch (e.State)
			{
			case LoginState::CharacterSelect:
				if (auto pCharList = GetChildWindow<CListWnd>(m_currentWindow, "Character_List"))
				{
					if (ci_equals(m_characterName, pCharList->GetItemText(pCharList->GetCurSel(), 2)))
					{
						// we've waited our 3 seconds, so enter world
						if (pCharacterListWnd != nullptr)
							pCharacterListWnd->EnterWorld();

						if (s_loginSettings.EndAfterSelect)
							m_paused = true;
					}
				}

				transit<Wait>();
			default:
				Wait::react(e);
				break;
			}
		}
	}
};

class InGame : public Wait
{
public:
	// override these events to do nothing in game
	void react(HomePressed const&) override {}
	void react(EndPressed const&) override {}
};

std::string Login::m_characterName = "";
std::string Login::m_serverName = "";
CXWnd* Login::m_currentWindow = nullptr;
bool Login::m_paused = false;
bool Login::m_offsetsLoaded = false;
uint64_t Login::m_delayTime = 0;
LoginState Login::m_lastState = LoginState::LoadOffsets;

FSM_INITIAL_STATE(Login, Wait)

