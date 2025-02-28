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
	std::string Account;
	std::string Password;
	std::string ServerName;

	void reset()
	{
		Account.clear();
		Password.clear();
		ServerName.clear();
	}
};

void NotifyCharacterLoad(const char* Profile, const char* Account, const char* Server, const char* Character);
void NotifyCharacterLoad(const std::shared_ptr<ProfileRecord>& ptr);
void NotifyCharacterUnload();
void NotifyCharacterUpdate(int Class, int Level, const char* Server, const char* Character);
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
	InGame,
	InGameCamping,
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

// this event will notify state to change to the provided profile.
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
struct CampCanceled : tinyfsm::Event {};

struct ChangeGameState : tinyfsm::Event
{
	int GameState;

	ChangeGameState(int gameState) : GameState(gameState) {}

	ChangeGameState(const ChangeGameState&) = delete;
	ChangeGameState& operator=(const ChangeGameState&) = delete;
};

struct SetCampTimer : tinyfsm::Event
{
	int CampTimer;

	SetCampTimer(int campTimer) : CampTimer(campTimer) {}

	SetCampTimer(const SetCampTimer&) = delete;
	SetCampTimer& operator=(const SetCampTimer&) = delete;
};

class Login : public tinyfsm::Fsm<Login>
{
protected:
	// This what autologin is currently transitioning towards
	static inline std::shared_ptr<ProfileRecord> m_record;
	// This is what we're logged in as.
	static inline std::shared_ptr<ProfileRecord> m_currentRecord;
	static inline std::vector<ProfileGroup> m_profiles;
	static inline CXWnd* m_currentWindow = nullptr; // the current in focus window
	static inline bool m_paused = false;
	static inline uint64_t m_delayTime = 0;
	static inline LoginState m_lastState = LoginState::InGame;
	static inline uint8_t m_retries = 0;

	static void SetProfileRecord(const std::shared_ptr<ProfileRecord>& ptr, bool setCurrent = true);

public:
	virtual ~Login() {}

	// This must be defined in the implementation where the state classes are defined
	virtual void react(const LoginStateSensor&) {}

	virtual void react(const SetLoginInformation& e)
	{
		ProfileRecord record;
		record.serverName = e.Server;
		record.characterName = e.Character;
		dispatch(SetLoginProfile(record));
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
		m_retries = 0;
		m_record.reset();

		// Once Autologin has performed or failed, this is no longer relevant and will only break future commands.
		m_settings.EndAfterSelect = false;
	}

	virtual void react(const CampCanceled&) {}
	virtual void react(const ChangeGameState&) {}
	virtual void react(const SetCampTimer&) {}

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
	static bool has_entry() { return m_record != nullptr; }
	static const CXWnd* current_window() { return m_currentWindow; }
	static void clear_current_window() { m_currentWindow = nullptr; }
	static bool paused() { return m_paused; }
	static uint64_t delay_time() { return m_delayTime; }
	static LoginState last_state() { return m_lastState; }
	static unsigned char retries() { return m_retries; }
	static std::vector<ProfileGroup>& profiles() { return m_profiles; }
	static const std::string& last_account() { return m_lastAccount; }

	static std::shared_ptr<ProfileRecord> get_current_record() { return m_currentRecord; }
	static void clear_current_record()
	{
		m_currentRecord.reset();
		NotifyCharacterUnload();
	}

	static void set_current_record(const std::shared_ptr<ProfileRecord>& ptr)
	{
		if (!m_currentRecord || !m_currentRecord->IsEquivalent(*ptr))
		{
			NotifyCharacterLoad(ptr);
		}

		m_currentRecord = ptr;
	}

	using Settings = AutoLoginSettings;

	static inline Settings m_settings;
	static inline CurrentLogin m_currentLogin;
	static inline bool m_skipNextDelay = false;
	static inline int m_campTimer = 0;
	static inline std::string m_lastAccount;
};

void AutoLoginDebug(std::string_view svLogMessage, bool bDebugOn = AUTOLOGIN_DBG);

