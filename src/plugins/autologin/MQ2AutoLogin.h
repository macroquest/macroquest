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

#include <mq/Plugin.h>

#include <tinyfsm.hpp>
#include <variant>

static bool AUTOLOGIN_DBG = false;

template <typename T = CXWnd>
inline T* GetWindow(const std::string& name)
{
	if (GetGameState() == GAMESTATE_PRECHARSELECT)
		return static_cast<T*>(FindEQMainWindow(name.c_str()));

	return static_cast<T*>(FindMQ2Window(name.c_str()));
}

template <typename T = CXWnd>
inline T* GetChildWindow(CXWnd* parentWnd, const std::string& child)
{
	CXMLDataManager* pXmlMgr = pSidlMgr->GetParamManager();
	if (pXmlMgr && parentWnd)
		return static_cast<T*>(parentWnd->GetChildItem(pXmlMgr, CXStr{ child }));

	return nullptr;
}

template <typename T = CXWnd>
inline T* GetChildWindow(const std::string& parent, const std::string& child)
{
	return GetChildWindow<T>(GetWindow<CXWnd>(parent), child);
}

inline bool IsWindowActive(const std::string& name)
{
	CXWnd* pWnd = GetWindow(name);
	return pWnd != nullptr && pWnd->IsVisible() && pWnd->IsEnabled();
}

// Combine IsWindowActive and GetWindow into a single call
template <typename T = CXWnd>
inline T* GetActiveWindow(const std::string& name)
{
	auto pWindow = GetWindow<T>(name);
	if (pWindow != nullptr && pWindow->IsVisible() && pWindow->IsEnabled())
		return pWindow;

	return nullptr;
}

// Combine IsWindowActive and GetChildWindow
template <typename T = CXWnd>
inline T* GetActiveChildWindow(CXWnd* parentWnd, const std::string& child)
{
	CXMLDataManager* pXmlMgr = pSidlMgr->GetParamManager();
	if (pXmlMgr && parentWnd)
	{
		T* pChild = static_cast<T*>(parentWnd->GetChildItem(pXmlMgr, CXStr{ child }));

		if (pChild && pChild->IsVisible() && pChild->IsEnabled())
			return pChild;
	}

	return nullptr;
}

template <typename T = CXWnd>
inline T* GetActiveChildWindow(const std::string& parent, const std::string& child)
{
	return GetActiveChildWindow<T>(GetActiveWindow<CXWnd>(parent), child);
}

enum class LoginState
{
	SplashScreen,
	Connect,
	ConnectConfirm,
	ServerSelect,
	ServerSelectConfirm,
	ServerSelectKick,
	ServerSelectDown,
	CharacterSelect,
	InGame
};

// this event will notify a change in game state
struct LoginStateSensor : tinyfsm::Event
{
	LoginState State;
	CXWnd* Window;

	LoginStateSensor(LoginState State, CXWnd* Window) : State(State), Window(Window) {}

	LoginStateSensor(const LoginStateSensor&) = delete;
	LoginStateSensor& operator=(const LoginStateSensor&) = delete;
};

// this event will notify states to change the server and character, as well as do any transitions that will be needed
struct SetLoginInformation : tinyfsm::Event
{
	std::string Server;
	std::string Character;

	SetLoginInformation(std::string_view Server, std::string_view Character) : Server(Server), Character(Character) {}
	SetLoginInformation(std::string_view Character) : Server(), Character(Character) {}

	SetLoginInformation(const SetLoginInformation&) = delete;
	SetLoginInformation& operator=(const SetLoginInformation&) = delete;
};

struct SetLoginProfile : tinyfsm::Event
{
	ProfileRecord Record;

	SetLoginProfile(const ProfileRecord& Record) : Record(Record) {}

	SetLoginProfile(const SetLoginProfile&) = delete;
	SetLoginProfile& operator=(const SetLoginProfile&) = delete;
};

struct UnpauseLogin : tinyfsm::Event
{
	bool ShowMessage = false;

	UnpauseLogin() = default;
	UnpauseLogin(bool ShowMessage) : ShowMessage(ShowMessage) {}

	UnpauseLogin(const UnpauseLogin&) = delete;
	UnpauseLogin& operator=(const UnpauseLogin&) = delete;
};

struct PauseLogin : tinyfsm::Event
{
	bool ShowMessage = false;

	PauseLogin() = default;
	PauseLogin(bool ShowMessage) : ShowMessage(ShowMessage) {}

	PauseLogin(const PauseLogin&) = delete;
	PauseLogin& operator=(const PauseLogin&) = delete;
};

struct StopLogin : tinyfsm::Event {};

class Login : public tinyfsm::Fsm<Login>
{
protected:
	static std::optional<ProfileRecord> m_record;
	static std::vector<ProfileGroup> m_profiles;
	static CXWnd* m_currentWindow; // the current in focus window
	static bool m_paused;
	static uint64_t m_delayTime;
	static LoginState m_lastState;
	static unsigned char m_retries;

public:
	// This must be defined in the implementation where the state classes are defined
	virtual void react(const LoginStateSensor&) {}

	virtual void react(const SetLoginInformation& e)
	{
		if (m_record)
		{
			m_record->characterName = e.Character;
			if (!e.Server.empty()) m_record->serverName = e.Server;
		}
	}

	virtual void react(const SetLoginProfile& ev)
	{
		m_record = ev.Record;
		m_paused = false;
	}

	virtual void react(const UnpauseLogin& ev)
	{
		if (m_paused && ev.ShowMessage)
			WriteChatf("\agHOME key pressed. AutoLogin Re-Enabled.");
		m_paused = false;
		m_retries = 0;
	}

	virtual void react(const PauseLogin& ev)
	{
		if (!m_paused && ev.ShowMessage)
			WriteChatf("END key pressed. Login of %s aborted.", m_record ? m_record->characterName.c_str() : "");
		m_paused = true;
	}

	virtual void react(const StopLogin&)
	{
		m_paused = true;
		m_record.reset();
	}

	virtual void entry() {}
	virtual void exit() {}

	// these are just some getters for ImGui
	static std::string_view character() { return m_record ? m_record->characterName.c_str() : ""; }
	static std::string_view server() { return m_record ? m_record->serverName.c_str() : ""; }
	static std::string_view profile() { return m_record ? m_record->profileName.c_str() : ""; }
	static std::string_view account() { return m_record ? m_record->accountName.c_str() : ""; }
	static const CXWnd* current_window() { return m_currentWindow; }
	static const bool paused() { return m_paused; }
	static const uint64_t delay_time() { return m_delayTime; }
	static const LoginState last_state() { return m_lastState; }
	static const unsigned char retries() { return m_retries; }
	static std::vector<ProfileGroup>& profiles() { return m_profiles; }

	struct Settings
	{
		bool KickActiveCharacter;
		bool EndAfterSelect;
		unsigned char ConnectRetries;

		enum class ServerUpNotification {
			None = 0,
			Beeps = 1,
			Email = 2
		};
		ServerUpNotification NotifyOnServerUp;

		enum class Type {
			MQ2Login,
			StationNames,
			Sessions
		};
		Type LoginType;
	};
	static Settings m_settings;
};

void AutoLoginDebug(std::string_view svLogMessage, bool bDebugOn = AUTOLOGIN_DBG);

// Look up the long name for a server name stored in the configuration
inline std::string GetServerLongName(const std::string& serverName)
{
	return GetPrivateProfileString("Servers", serverName, "", INIFileName);
}

