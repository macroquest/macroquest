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

#include <login/Login.h>
#include "MQ2AutoLogin.h"

#include <optional>
#include <TlHelp32.h>

// TODO:
// - Injecting while running doesn't load the config
// - fix /relog -- it seems to timeout just as it tries to log back in?

// State Class forward declarations
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
class InGameCamping;

static std::shared_ptr<ProfileRecord> GetInitialLoginProfile(CEditWnd* pEditWnd)
{
	if (Login::is_in_state<Connect>() || Login::is_in_state<ConnectConfirm>())
	{
		// initialize input to empty, we will try to populate it from the command line first
		std::string input;

		// we expect this to be populated because we feed eqgame.exe with a `/login:` parameter
		// the reason to do it this way is because the autopopulation of the login field is limited to 31 characters by eqgame
		std::string cmdline(::GetCommandLineA());

		// find the login argument if it exists, otherwise input will remain empty
		const std::vector<std::string_view> args_tokens = tokenize_args(cmdline);
		for (auto token: args_tokens)
		{
			const size_t loc = token.find("/login:");
			if (loc != std::string_view::npos && token.length() > 7)
			{
				input = strip_quotes(token.substr(loc + 7), '"');
				break;
			}
		}

		// fallback method, the only case where we would hit this is if we manually entered the login string after eqgame started.
		CXStr inputText = GetEditWndText(pEditWnd);
		if (input.empty() && !inputText.empty())
			input = inputText;

		AutoLoginDebug(fmt::format("GetInitialLoginProfile() input({})", input));

		auto record = ProfileRecord::FromString(input);
		if (!record.profileName.empty() && !record.serverName.empty() && !record.characterName.empty())
			login::db::ReadProfile(record);

		if (!record.serverName.empty() && !record.characterName.empty())
			login::db::ReadAccount(record);

		if (record.serverName.empty() && record.characterName.empty())
			login::db::ReadFirstProfile(record);

		if (record.customClientIni)
			record.customClientIni = (std::filesystem::current_path() / *record.customClientIni).string();

		return std::make_shared<ProfileRecord>(record);
	}

	return nullptr;
}

static bool IsWrongAccount(const std::string& lastAccount, const std::shared_ptr<ProfileRecord>& record)
{
	// This happens if we switch profiles. Check against the account stored on the profile
	// to determine if we need to back out.

	// If we don't have login name, we can't tell.

	if (lastAccount.empty())
		return false;

	if (record)
	{
		// If the account isn't provided we assume it is a character on the current account.
		if (record->accountName.empty())
			return false;

		if (!ci_equals(lastAccount, record->accountName))
			return true;
	}

	return false;
}

class Wait : public Login
{
protected:
	bool transit_condition(const LoginStateSensor& e)
	{
		if (GetGameState() == GAMESTATE_PRECHARSELECT && !g_pLoginClient)
			return false; // do nothing at precharselect if we don't have offsets

		if (e.State == m_lastState && m_delayTime > MQGetTickCount64())
			return false; // do nothing if state hasn't changed and delay is still active

		if (e.State == LoginState::SplashScreen)
			return true; // always skip these splash screens

		if (m_paused)
			return false; // do not continue if we're paused

		return m_record != nullptr || e.State == LoginState::Connect;
	}

public:
	void entry() override
	{
		// TODO: configure short delay
		uint64_t new_delay = MQGetTickCount64() + 2000;

		// this allows us to specify longer waits if we need them
		m_delayTime = new_delay > m_delayTime ? new_delay : m_delayTime;
	}

	void react(const LoginStateSensor& e) override
	{
		m_currentWindow = e.Window;

		if (transit_condition(e))
		{
			// we only want to actually delay in this state if there is no transition

			switch (e.State)
			{
			case LoginState::SplashScreen:
				transit<SplashScreen>();
				break;
			case LoginState::Connect:
			{
				CEditWnd* pEditWnd = GetChildWindow<CEditWnd>(m_currentWindow, "LOGIN_PasswordEdit");

				// If we have an empty password input field, transit to connect. Otherwise, wait.
				if (GetEditWndText(pEditWnd).empty())
					transit<Connect>();
				else
					transit<Wait>(); // this will reset the delay
				break;
			}
			case LoginState::ConnectConfirm:
				transit<ConnectConfirm>();
				break;
			case LoginState::ServerSelect:
				m_retries = 0;
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

				if (pWnd != nullptr && pWnd->IsVisible() == 1
					&&  GetSTMLText(pChild).find("Loading Characters") != CXStr::npos)
				{
					// fix for the stuck at char select "Loading Characters" bug
					// need to quit and re-enter the character select screen if we've already waited once
					// if the connection is slow, then the short wait time should be extended past 2 seconds
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

			default: break;
			}

			m_lastState = e.State;
		}
	}

	virtual void react(const ChangeGameState& event)
	{
		if (event.GameState == GAMESTATE_INGAME)
		{
			transit<InGame>();
		}
		else
		{
			transit<Wait>();
		}
	}
};

class SplashScreen : public Login
{
public:
	void entry() override
	{
		CXPoint point(1, 1);
		g_pLoginViewManager->HandleLButtonUp(point);

		transit<Wait>();
	}
};

class Connect : public Login
{
public:
	void entry() override
	{
		// enter the username into the field
		if (auto pUsernameEditWnd = GetChildWindow<CEditWnd>(m_currentWindow, "LOGIN_UsernameEdit"))
		{
			std::shared_ptr<ProfileRecord> record = nullptr;

			if (m_record)
			{
				// this only matters during connect. Once we have connected, the client
				// will exit rather than go back to the connection screen, and that is the
				// only place where we can enter account/pass
				record = m_record;
			}
			else if (std::shared_ptr<ProfileRecord> tempProfile = GetInitialLoginProfile(pUsernameEditWnd))
			{
				record = tempProfile;
			}

			if (record
				&& !record->accountName.empty()
				&& !record->accountPassword.empty())
			{
				SetProfileRecord(record);

				DWORD oldscreenmode = std::exchange(ScreenMode, 3);
				SetEditWndText(pUsernameEditWnd, m_record->accountName);

				// Update the last account. This won't be updated by the client until we reach character select.
				m_lastAccount = m_record->accountName;

				if (CEditWnd* pPasswordEditWnd = GetChildWindow<CEditWnd>(m_currentWindow, "LOGIN_PasswordEdit"))
				{
					SetEditWndText(pPasswordEditWnd, m_record->accountPassword);

					if (CButtonWnd* pConnectButton = GetChildWindow<CButtonWnd>(m_currentWindow, "LOGIN_ConnectButton"))
						SendWndNotification(pConnectButton, pConnectButton, XWM_LCLICK);
				}

				ScreenMode = oldscreenmode;
			}
		}

		if (!m_record)
		{
			dispatch(StopLogin());
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
			CXStr str = GetWindowText(pWnd);

			enum MessageAction
			{
				Action_Success,
				Action_Stop,
				Action_ClickYes,
				Action_None,
			};

			static std::vector<std::pair<MessageAction, const char*>> Messages = {
				{ Action_Success,  "Logging in to the server.  Please wait...." },
				{ Action_Stop,     "password were not valid" },
				{ Action_Stop,     "This login requires that the account be activated.  Please make sure your account is active in order to login." },
				{ Action_Stop,     "You need to enter a username and password to login." },
				{ Action_Stop,     "Invalid Password" },
				{ Action_ClickYes, "You have a character logged into a world server as an OFFLINE TRADER from this account" },
			};

			MessageAction msgAction = Action_None;

			for (auto [action, message] : Messages)
			{
				if (ci_find_substr(str, message) != -1)
				{
					msgAction = action;
					break;
				}
			}

			if (msgAction == Action_Success)
			{
				// successful log in, transit
			}
			else if (msgAction == Action_Stop)
			{
				// we can't recover from these, so stop autologin
				WriteChatf("\ar[AutoLogin]\ax Stopping login because the following message was encountered: %s", str.c_str());
				dispatch(StopLogin());
			}
			else if (msgAction == Action_ClickYes)
			{
				if (CXWnd* pButton = GetChildWindow(m_currentWindow, "YESNO_YesButton"))
					SendWndNotification(pButton, pWnd, XWM_LCLICK);
			}
			else if (m_settings.ConnectRetries > 0 && m_retries >= m_settings.ConnectRetries)
			{
				WriteChatf("\ar[AutoLogin]\ax Failed to connect %d times, giving up.", m_retries);
				dispatch(StopLogin());
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
					SendWndNotification(pButton, pButton, XWM_LCLICK);

				++m_retries;
				m_delayTime = MQGetTickCount64() + 2000; // TODO: configure reconnect delay
			}
		}

		transit<Wait>();
	}
};

class ServerSelect : public Login
{
public:
	static EQLS::EQClientServerData* GetServer(std::string& serverName)
	{
		if (GetGameState() != GAMESTATE_PRECHARSELECT)
			return nullptr;
		if (!g_pLoginClient)
			return nullptr;

		// we want the long server name or the server ID here because that's what's available at server select
		ServerID serverId = GetServerIDFromServerName(serverName.c_str());

		// server ID is always highest priority
		auto server_it = g_pLoginClient->ServerList.end();
		if (serverId != ServerID::Invalid)
			server_it = std::find_if(g_pLoginClient->ServerList.begin(), g_pLoginClient->ServerList.end(),
				[serverId](EQLS::EQClientServerData* s) { return s->ID == serverId; });

		// otherwise we need to search through our lists
		if (server_it == g_pLoginClient->ServerList.end())
		{
			// get all the possible names that could show up in the server list
			// starting with the direct argument
			std::vector server_names = { serverName };
			for (const auto& name : login::db::ReadLongServer(serverName))
				server_names.emplace_back(name);

			server_it = std::find_if(g_pLoginClient->ServerList.begin(), g_pLoginClient->ServerList.end(),
				[&server_names](EQLS::EQClientServerData* s)
				{ return std::find_if(
					server_names.begin(),
					server_names.end(),
					[&name = s->ServerName](const std::string& long_name)
					{ return ci_equals(name, long_name); }) != server_names.end();
				});
		}

		if (server_it != g_pLoginClient->ServerList.end())
			return *server_it;

		return nullptr;
	}

	static bool CheckServerDown()
	{
		if (!m_record || m_record->serverName.empty())
		{
			AutoLoginDebug("ServerSelect: server name is empty");
			dispatch(StopLogin()); // no server to select, stop
			return false;
		}

		if (g_pLoginClient != nullptr && !ci_equals(g_pLoginClient->LoginName, m_record->accountName))
		{
			AutoLoginDebug("ServerSelect: incorrect account");
			dispatch(StopLogin());
			return false;
		}

		auto server = GetServer(m_record->serverName);
		if (!server)
		{
			// no server found, wait
			AutoLoginDebug(fmt::format("ServerSelect: Could not find server {}", m_record->serverName));
			return false;
		}

		if (server->StatusFlags & (EQLS::eServerStatus_Down | EQLS::eServerStatus_Locked))
		{
			return true;
		}

		// join server (both server and Info are already guaranteed to be non-null)
		g_pLoginServerAPI->JoinServer((int)server->ID);
		return false;
	}

	void entry() override
	{
		if (m_lastAccount.empty())
		{
			if (const char* loginName = GetLoginName())
				m_lastAccount = loginName;
		}

		if (IsWrongAccount(m_lastAccount, m_record))
		{
			g_pLoginClient->OnBoot("Leaving Server Select");
			m_skipNextDelay = true;

			transit<Connect>();
		}
		else if (CheckServerDown())
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
			CXStr str = GetWindowText(pWnd);

			if (str.find("The world server is currently at maximum capacity") != CXStr::npos)
			{
				// this is the longwait condition, so add a delay
				m_delayTime = MQGetTickCount64() + 185000; // TODO: configure longwait
			}
			else if (str.find("this server is not a free-play server.") != CXStr::npos
				|| str.find("The request to remove the player was denied because a player is still actively playing.") != CXStr::npos)
			{
				WriteChatf("\ag[AutoLogin]\ax Stopping at server select due to message: %s", str.c_str());
				dispatch(StopLogin());
			}
			else
			{
				// slow things down a little bit
				m_delayTime = MQGetTickCount64() + 1000;

				// some potential error messages -- (no need to check for the text, we are just going to click)
				//std::vector<const char*> ErrorMessages = {
				//	"The world server is currently at maximum capacity and not allowing further logins until the number of players online decreases.  Please try again later.",
				//	"That server is currently unavailable",
				//	"An unknown error occurred while trying to join the server.",
				//	"The connection has been terminated by the server.  Most likely you have been inactive",
				//	"A timeout occurred"
				//};

				if (auto pButton = GetActiveChildWindow<CButtonWnd>(m_currentWindow, "OK_OKButton"))
					SendWndNotification(pButton, pButton, XWM_LCLICK);
			}
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
			CXStr str = GetWindowText(pWnd);

			if (str.find("You already have a character logged into a world server from this account.") != CXStr::npos)
			{
				auto pButton = GetActiveChildWindow<CButtonWnd>(m_currentWindow,
					m_settings.KickActiveCharacter ? "YESNO_YesButton" : "YESNO_NoButton");

				if (!m_settings.KickActiveCharacter)
					dispatch(StopLogin());

				if (pButton)
					SendWndNotification(pButton, pButton, XWM_LCLICK);
			}
			else if (str.find("You have a character logged into a world server as an OFFLINE TRADER from this account.") != CXStr::npos)
			{
				auto pButton = GetChildWindow<CButtonWnd>(m_currentWindow, "YESNO_YesButton");
				if (pButton)
					SendWndNotification(pButton, pButton, XWM_LCLICK);
				else
					dispatch(StopLogin());
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
	void react(const LoginStateSensor& e) override
	{
		// we only want to actually delay in this state if there is no transition
		if (transit_condition(e))
		{
			m_lastState = e.State;
			m_currentWindow = e.Window;

			switch (e.State)
			{
			case LoginState::ServerSelect:
				if (ServerSelect::CheckServerDown())
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
	static bool IsInvalidServer()
	{
		// trivial cases: if the server shortname is empty or there is no record
		if (GetServerShortName()[0] == 0 || !m_record || m_record->serverName.empty())
			return true;

		// valid if server short name is what is in the record
		if (ci_equals(GetServerShortName(), m_record->serverName))
			return false;

		// valid if server long name is what is in the record
		if (auto shortname = login::db::ReadShortServer(m_record->serverName))
		{
			if (ci_equals(GetServerShortName(), *shortname))
				return false;
		}

		// no matches, not a valid server
		return true;
	}

	void entry() override
	{
		if (const char* loginName = GetLoginName())
			m_lastAccount = GetLoginName();

		if (auto pCharList = GetChildWindow<CListWnd>(m_currentWindow, "Character_List"))
		{
			if (IsInvalidServer() || IsWrongAccount(m_lastAccount, m_record))
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
					auto itemsArray = GetItemsArray(pCharList);

					for (int i = 0; i < itemsArray->Count; ++i)
					{
						if (m_record && ci_equals(m_record->characterName, GetListItemText(pCharList, i, 2)))
							return i;
					}

					return -1;
				}();

				if (index < 0)
				{
					WriteChatf("\ag[AutoLogin]\ax No character named \"%s\" found! Stopping...", m_record->characterName.c_str());

					dispatch(StopLogin());
					transit<Wait>();
				}
				else
				{
					if (pCharacterListWnd != nullptr)
						pCharacterListWnd->SelectCharacter(index);

					m_delayTime = MQGetTickCount64() + m_settings.CharSelectDelay * 1000;
					WriteChatf(fmt::format("\ag[AutoLogin]\ax Selecting \ag{}\ax in {} seconds. Press the \ayEND\ax key to pause.", pCharList->GetItemText(index, 2), m_settings.CharSelectDelay).c_str());
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
	void react(const UnpauseLogin& e) override
	{
		if (m_paused)
		{
			// we need to restart the login timer here
			m_delayTime = MQGetTickCount64() + m_settings.CharSelectDelay * 1000;
			WriteChatf(fmt::format("\ag[AutoLogin]\ax Login Resumed. Selecting \ag{}\ax in {} seconds. Press the \ayEND\ax key to abort.", m_record ? m_record->characterName : "character", m_settings.CharSelectDelay).c_str());
		}

		// and set the correct pause value, don't call the base because we don't want to repeat messaging
		m_paused = false;
	}

	void react(const LoginStateSensor& e) override
	{
		// we only want to actually delay in this state if there is no transition
		if (transit_condition(e))
		{
			m_lastState = e.State;
			m_currentWindow = e.Window;

			switch (e.State)
			{
			case LoginState::CharacterSelect:
				if (auto pCharList = GetChildWindow<CListWnd>(m_currentWindow, "Character_List"))
				{
					if (m_record && ci_equals(m_record->characterName, GetListItemText(pCharList, GetListCurSel(pCharList), 2)))
					{
						// we've waited our 3 seconds, so enter world
						if (pCharacterListWnd != nullptr)
							pCharacterListWnd->EnterWorld();

						if (m_settings.EndAfterSelect)
							dispatch(StopLogin());
					}
				}

				transit<Wait>();
				[[fallthrough]];
			default:
				Wait::react(e);
				break;
			}
		}
	}

	void react(const SetLoginProfile& e) override
	{
		if (pCharacterListWnd != nullptr && (m_record == nullptr
				|| !ci_equals(e.Record.accountName, m_record->accountName) || !ci_equals(e.Record.serverName, m_record->serverName)))
		{
			pCharacterListWnd->Quit();
		}

		Login::react(e);

		transit<Wait>(); // wait to allow server select to come back and the login client to be valid
	}
};

class InGame : public Wait
{
public:
	void entry() override
	{
		// State machine stops when we get in game, but state machine only got us here if the last state was char select.
		if (m_lastState == LoginState::CharacterSelect)
		{
			dispatch(StopLogin());
		}

		m_lastState = LoginState::InGame;
		m_campTimer = 0;
	}

	void react(const LoginStateSensor& e) override
	{
		// We only want to transition out of InGame/InGameCamping.
		if (transit_condition(e))
		{
			switch (e.State)
			{
			case LoginState::InGame:
			case LoginState::InGameCamping:
				break;

			default:
				Wait::react(e);
				break;
			}
		}
	}

	void react(const SetLoginProfile& e) override
	{
		Login::react(e);

		if (m_campTimer == 0)
		{
			// Stand up so we can initiate a camp.
			if (pLocalPlayer != nullptr && pLocalPlayer->StandState == STANDSTATE_FEIGN)
			{
				EzCommand("/stand");
			}

			// Perform the camp.
			EzCommand("/camp");
		}
		else
		{
			CheckForFastCamp();
		}
	}

	void react(const SetCampTimer& e) override
	{
		m_campTimer = e.CampTimer;

		if (m_campTimer)
			Login::transit<InGameCamping>();
	}

	static void CheckForFastCamp()
	{
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_COTF) // A guess
		CSidlScreenWnd* pConfirmationWnd = GetWindow<CSidlScreenWnd>("ConfirmationDialogBox");
		if (pConfirmationWnd != nullptr && pConfirmationWnd->IsVisible())
		{
			if (CStmlWnd* pStmlWnd = GetChildWindow<CStmlWnd>(pEverQuest->CampDialog, "CD_TextOutput"))
			{
				CXStr messageText = GetSTMLText(pStmlWnd);

				if (ci_find_substr(messageText, "Fast camp now?") != -1)
				{
					if (CButtonWnd* pButton = GetChildWindow<CButtonWnd>(pConfirmationWnd, "CD_Yes_Button"))
					{
						SendWndNotification(pButton, pButton, XWM_LCLICK);
					}
				}
			}
		}
#endif
	}
};

class InGameCamping : public InGame
{
public:
	void entry() override
	{
		m_lastState = LoginState::InGameCamping;

		if (m_record)
			CheckForFastCamp();
	}

	void exit() override
	{
		if (m_record)
		{
			// If we left the state and still have a record, set the current record.
			set_current_record(m_record);
		}
	}

	void react(const SetCampTimer& e) override
	{
		m_campTimer = e.CampTimer;

		if (m_campTimer == 0)
		{
			if (m_record)
			{
				WriteChatf("\ag[AutoLogin]\ax Attempt to camp out has been canceled.");
				dispatch(StopLogin{});
			}
			else
			{
				Login::transit<InGame>();
			}
		}
	}

	void react(const StopLogin& e) override
	{
		Login::react(e);
		Login::transit<InGame>();
	}
};

FSM_INITIAL_STATE(Login, Wait)
