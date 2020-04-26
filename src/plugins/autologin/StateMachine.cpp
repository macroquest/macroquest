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

// TODO:
// - Figure out how to tie this into the backend
// - Injecting while running doesn't load the config
// - END does not actually stop the login wait at character select -- likely need to handle it in a react in the charselectwait state

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
		if (GetGameState() == GAMESTATE_PRECHARSELECT && !g_pServerInfo)
		{
			// do nothing at precharselect if we don't have offsets
			transit<Wait>();
		}
		else if (!m_paused && (e.State != m_lastState || m_delayTime < MQGetTickCount64()))
		{
			// we only want to actually delay in this state if there is no transition
			m_currentWindow = e.Window;

			switch (e.State)
			{
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

class SplashScreen : public Login
{
public:
	void entry() override
	{
		g_pLoginViewManager->SendLMouseClick(CXPoint(1, 1));
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
		if (server_list && !server_list->ItemsArray.IsEmpty() && g_pServerInfo && g_pServerInfo->pServerList && g_pServerInfo->pServerList->Info)
		{
			auto pList = g_pServerInfo->pServerList;
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
				g_pLoginServerAPI->EnterGame(server->Info->ID);
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
LoginState Login::m_lastState = LoginState::InGame;

FSM_INITIAL_STATE(Login, Wait)

