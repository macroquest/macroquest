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

// This is a constant set of live server shortnames
const ci_unordered::map<int> ServerData = {
	{ "lockjaw",     160 },
	{ "ragefire",    159 },
	{ "vox",         158 },
	{ "trakanon",    155 },
	{ "fippy",       156 },
	{ "vulak",       157 },
	{ "mayong",      163 },
	{ "antonius",    100 },
	{ "brekt",       162 },
	{ "bertox",      102 },
	{ "bristle",     104 },
	{ "cazic",       105 },
	{ "drinal",      106 },
	{ "erollisi",    109 },
	{ "firiona",     111 },
	{ "luclin",      116 },
	{ "povar",       123 },
	{ "rathe",       127 },
	{ "tunare",      140 },
	{ "xegony",      144 },
	{ "zek",         147 },
	{ "beta",        2   },
	{ "test",        1   }
};

template <typename T = CXWnd>
inline T* GetWindow(const std::string& name)
{
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
	CXMLDataManager* pXmlMgr = pSidlMgr->GetParamManager();
	CXWnd* parentWnd = GetWindow<CXWnd>(parent);
	if (pXmlMgr && parentWnd)
		return static_cast<T*>(parentWnd->GetChildItem(pXmlMgr, CXStr{ child }));

	return nullptr;
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
inline T* GetActiveChildWindow(const std::string& parent, const std::string& child)
{
	CXMLDataManager* pXmlMgr = pSidlMgr->GetParamManager();
	CXWnd* pParent = GetActiveWindow(parent);
	if (pXmlMgr && pParent)
	{
		T* pChild = static_cast<T*>(pParent->GetChildItem(pXmlMgr, CXStr{ child }));

		if (pChild && pChild->IsVisible() && pChild->IsEnabled())
			return pChild;
	}

	return nullptr;
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

static struct LoginSettings
{
	bool KickActiveCharacter;
	bool EndAfterSelect;

	enum class ServerUpNotification {
		None = 0,
		Email = 1,
		Beeps = 2
	} NotifyOnServerUp;

	enum class Type {
		MQ2Login,
		StationNames,
		Sessions
	} LoginType;
} s_loginSettings;

// this event will notify states to change the server and character, as well as do any transitions that will be needed
struct SetLoginInformation : tinyfsm::Event
{
	std::string Server;
	std::string Character;

	SetLoginInformation(std::string_view Server, std::string_view Character) : Server(Server), Character(Character) {}
	SetLoginInformation(std::string_view Character) : Server(""), Character(Character) {}
	SetLoginInformation(const SetLoginInformation&) = delete;
};

// this event will notify a change in game state
struct LoginStateSensor : tinyfsm::Event
{
	LoginState State;
	CXWnd* Window;

	LoginStateSensor(LoginState State, CXWnd* Window) : State(State), Window(Window) {}
	LoginStateSensor(const LoginStateSensor&) = delete;
};

struct UnpauseLogin : tinyfsm::Event {};
struct PauseLogin : tinyfsm::Event {};

class Login : public tinyfsm::Fsm<Login>
{
protected:
	static std::string m_characterName;
	static std::string m_serverName;
	static CXWnd* m_currentWindow; // the current in focus window
	static bool m_paused;
	static bool m_offsetsLoaded;
	static uint64_t m_delayTime;
	static LoginState m_lastState;

public:
	// This must be defined in the implementation where the state classes are defined
	virtual void react(LoginStateSensor const&) {}

	virtual void react(SetLoginInformation const& e)
	{
		m_characterName = e.Character;
		if (!e.Server.empty()) m_serverName = e.Server;
	}

	virtual void react(UnpauseLogin const&)
	{
		if (m_paused)
			WriteChatf("\agHOME key pressed. AutoLogin Re-Enabled.");
		m_paused = false;

	}

	virtual void react(PauseLogin const&)
	{
		if (!m_paused)
			WriteChatf(fmt::format("END key pressed. Login of {} aborted.", m_characterName).c_str());
		m_paused = true;
	}

	virtual void entry() {}
	virtual void exit() {}

	// these are just some getters for ImGui
	static const std::string& character() { return m_characterName; }
	static const std::string& server() { return m_serverName; }
	static const CXWnd* current_window() { return m_currentWindow; }
	static const bool paused() { return m_paused; }
	static const bool offsets_loaded() { return m_offsetsLoaded; }
	static const uint64_t delay_time() { return m_delayTime; }
	static const LoginState last_state() { return m_lastState; }
};

void AutoLoginDebug(std::string_view svLogMessage, bool bDebugOn = AUTOLOGIN_DBG);

// Look up the long name for a server name stored in the configuration
inline std::string GetServerLongName(const std::string& serverName)
{
	return GetPrivateProfileString("Servers", serverName, "", INIFileName);
}

