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

#pragma once

#include <mq/Plugin.h>

#include "login/AutoLogin.h"

#include <tinyfsm.hpp>
#include <memory>

static bool AUTOLOGIN_DBG = false;

struct CurrentLogin
{
	std::optional<std::string> Account;
	std::optional<std::string> Password;
	std::optional<std::string> ServerName;

	void reset()
	{
		Account.reset();
		Password.reset();
		ServerName.reset();
	}
};

void NotifyCharacterLoad(const char* Profile, const char* Account, const char* Server, const char* Character);
void SendWndNotification(CXWnd* pWnd, CXWnd* sender, uint32_t msg, void* data = nullptr);
CXStr GetWindowText(CXWnd* pWnd);
CXStr GetEditWndText(CEditWnd* pWnd);
CXStr GetSTMLText(CStmlWnd* pWnd);
void SetEditWndText(CEditWnd* pWnd, std::string_view text);
ArrayClass<SListWndLine>* GetItemsArray(CListWnd* pWnd);
CXStr GetListItemText(CListWnd* pWnd, int row, int col);
int GetListCurSel(CListWnd* pWnd);

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
	return GetChildWindow<T>(GetWindow<CXWnd>(parent), child);
}

inline bool IsWindowActive(const std::string& name)
{
	const CXWnd* pWnd = GetWindow(name);
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
	static std::shared_ptr<ProfileRecord> m_record;
	static std::shared_ptr<ProfileRecord> m_lastRecord;
	static std::vector<ProfileGroup> m_profiles;
	static CXWnd* m_currentWindow; // the current in focus window
	static bool m_paused;
	static uint64_t m_delayTime;
	static LoginState m_lastState;
	static unsigned char m_retries;

	void SetProfileRecord(const std::shared_ptr<ProfileRecord>& ptr)
	{
		m_record = ptr;
		if (ptr != nullptr)
			m_lastRecord = ptr;
	}

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
		else
		{
			ProfileRecord record;
			record.serverName = e.Server;
			record.characterName = e.Character;
			dispatch(SetLoginProfile(record));
		}
	}

	virtual void react(const SetLoginProfile& ev)
	{
		SetProfileRecord(std::make_shared<ProfileRecord>(ev.Record));

		m_paused = false;
	}

	virtual void react(const UnpauseLogin& ev)
	{
		if (m_record)
		{
			if (m_paused && ev.ShowMessage)
				WriteChatf("\ag[AutoLogin]\ax \ayHOME\ax key pressed. AutoLogin Re-Enabled.");
			m_paused = false;
			m_retries = 0;
		}
	}

	virtual void react(const PauseLogin& ev)
	{
		if (m_record)
		{
			if (!m_paused && ev.ShowMessage)
				WriteChatf("\ag[AutoLogin]\ax \ayEND\ax key pressed. Login of \ag%s\ax paused.", m_record->characterName.c_str());
			m_paused = true;
		}
	}

	virtual void react(const StopLogin&)
	{
		m_paused = true;
		m_record.reset();
		// Once Autologin has performed or failed, this is no longer relevant and will only break future commands.
		m_settings.EndAfterSelect = false;
	}

	virtual void entry() {}
	virtual void exit() {}

	// these are just some getters for ImGui
	static const char* character() { return m_record ? m_record->characterName.c_str() : ""; }
	static const char* server() { return m_record ? m_record->serverName.c_str() : ""; }
	static const char* profile() { return m_record ? m_record->profileName.c_str() : ""; }
	static const char* account() { return m_record ? m_record->accountName.c_str() : ""; }

	static const char* hotkey() { return m_record ? m_record->hotkey.c_str() : ""; }
	static const char* character_class() { return m_record ? m_record->characterClass.c_str() : ""; }

	static std::optional<std::string> custom_ini() { return m_record ? m_record->customClientIni : std::nullopt; }

	static int character_level() { return m_record ? m_record->characterLevel : 0; }
	static std::shared_ptr<ProfileRecord> get_record() { return m_record; }
	static std::shared_ptr<ProfileRecord> get_last_record() { return m_lastRecord; }
	static bool has_entry() { return m_record != nullptr; }
	static const CXWnd* current_window() { return m_currentWindow; }
	static bool paused() { return m_paused; }
	static uint64_t delay_time() { return m_delayTime; }
	static LoginState last_state() { return m_lastState; }
	static unsigned char retries() { return m_retries; }
	static std::vector<ProfileGroup>& profiles() { return m_profiles; }

	struct Settings
	{
		bool KickActiveCharacter = true;
		bool EndAfterSelect = false;
		int CharSelectDelay = 3;
		int ConnectRetries = 0;
	};

	static Settings m_settings;
	static CurrentLogin m_currentLogin;
};

void AutoLoginDebug(std::string_view svLogMessage, bool bDebugOn = AUTOLOGIN_DBG);

