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

// For list of changes, see CHANGELOG.md

#include <mq/Plugin.h>

#include "MQ2AutoLogin.h"
#include "login/Login.h"
#include "login/AutoLogin.h"

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "imgui/ImGuiUtils.h"

#include <map>
#include <TlHelp32.h>
#pragma comment(lib, "Crypt32.lib")

#include <filesystem>

namespace fs = std::filesystem;

PLUGIN_VERSION(4.0);

PreSetup("MQ2AutoLogin");

constexpr int STEP_DELAY = 1000;

static uint64_t s_reenableTime = 0;
static postoffice::DropboxAPI s_autologinDropbox;
static uintptr_t s_joinServer = 0;

class LoginProfileType : public MQ2Type
{
public:
	enum class LoginProfileMembers
	{
		HotKey,
		Server,
		Character,
		Profile,
		Account,
		Class,
		Level,
		CustomCharacterIni,
	};

	LoginProfileType() : MQ2Type("LoginProfile")
	{
		ScopedTypeMember(LoginProfileMembers, HotKey);
		ScopedTypeMember(LoginProfileMembers, Server);
		ScopedTypeMember(LoginProfileMembers, Character);
		ScopedTypeMember(LoginProfileMembers, Profile);
		ScopedTypeMember(LoginProfileMembers, Account);
		ScopedTypeMember(LoginProfileMembers, Class);
		ScopedTypeMember(LoginProfileMembers, Level);
		ScopedTypeMember(LoginProfileMembers, CustomCharacterIni);
	}

	virtual bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override
	{
		MQTypeMember* pMember = FindMember(Member);
		if (!pMember)
			return false;

		std::shared_ptr<ProfileRecord> record = Login::get_current_record();
		if (!record)
			return false;

		switch (static_cast<LoginProfileMembers>(pMember->ID))
		{
		case LoginProfileMembers::HotKey:
			strcpy_s(DataTypeTemp, record->hotkey.c_str());
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = mq::datatypes::pStringType;
			return true;
		case LoginProfileMembers::Server:
			strcpy_s(DataTypeTemp, record->serverName.c_str());
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = mq::datatypes::pStringType;
			return true;
		case LoginProfileMembers::Character:
			strcpy_s(DataTypeTemp, record->characterName.c_str());
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = mq::datatypes::pStringType;
			return true;
		case LoginProfileMembers::Profile:
			strcpy_s(DataTypeTemp, record->profileName.c_str());
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = mq::datatypes::pStringType;
			return true;
		case LoginProfileMembers::Account:
			strcpy_s(DataTypeTemp, record->accountName.c_str());
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = mq::datatypes::pStringType;
			return true;
		case LoginProfileMembers::Class: {
			// Probably better off storing this as enum type...
			int classIndex = 0;
			for (int i = 0; i < TotalPlayerClasses; ++i)
			{
				if (ci_equals(ClassInfo[i].UCShortName, record->characterClass))
				{
					classIndex = i;
				}
			}
			Dest.DWord = classIndex;
			Dest.Type = mq::datatypes::pClassType;
			return true;
		}
		case LoginProfileMembers::Level:
			Dest.Int = record->characterLevel;
			Dest.Type = mq::datatypes::pIntType;
			return true;
		case LoginProfileMembers::CustomCharacterIni:
			strcpy_s(DataTypeTemp, record->customClientIni ? record->customClientIni->c_str() : "");
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = mq::datatypes::pStringType;
			return true;
		}

		return false;
	}

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		std::shared_ptr<ProfileRecord> record = Login::get_current_record();
		if (!record)
			return false;

		record->FormatTo(Destination, MAX_STRING);
		return true;
	}
};

LoginProfileType* pLoginProfileType = nullptr;

class MQ2AutoLoginType : public MQ2Type
{
public:
	enum class AutoLoginMembers
	{
		Profile,
		Active,
	};

	MQ2AutoLoginType() : MQ2Type("AutoLogin")
	{
		ScopedTypeMember(AutoLoginMembers, Profile);
		ScopedTypeMember(AutoLoginMembers, Active);
	}

	virtual bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override
	{
		MQTypeMember* pMember = FindMember(Member);
		if (!pMember)
			return false;

		switch (static_cast<AutoLoginMembers>(pMember->ID))
		{
		case AutoLoginMembers::Profile:
			Dest.Type = pLoginProfileType;
			return true;

		case AutoLoginMembers::Active:
			Dest.Type = mq::datatypes::pBoolType;
			Dest.Set(Login::has_entry());
			return true;

		default:
			break;
		}

		return false;
	}

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		strcpy_s(Destination, MAX_STRING, "AutoLogin");
		return true;
	}

	static bool dataAutoLogin(const char* szName, MQTypeVar& Ret);
};

MQ2AutoLoginType* pAutoLoginType = nullptr;

bool MQ2AutoLoginType::dataAutoLogin(const char* szName, MQTypeVar& Ret)
{
	Ret.DWord = 1;
	Ret.Type = pAutoLoginType;
	return true;
}

template <typename T>
static void Post(const proto::login::MessageId& messageId, const T& data)
{
	Post(messageId, data.SerializeAsString());
}

static void Post(const proto::login::MessageId& messageId, const std::string& data)
{
	proto::login::LoginMessage message;
	message.set_id(messageId);
	message.set_payload(data);

	postoffice::Address address;
	address.Name = "launcher";
	address.Mailbox = "autologin";
	address.AbsoluteMailbox = true;

	s_autologinDropbox.Post(address, message);
}

void NotifyCharacterLoad(const std::shared_ptr<ProfileRecord>& ptr)
{
	auto& record = *ptr;

	// Fill in the profile first.
	if (!record.profileName.empty())
	{
		login::db::ReadProfile(record);
	}
	else if (!record.serverName.empty() && !record.characterName.empty())
	{
		login::db::ReadCharacter(record);
	}

	proto::login::NotifyLoadedMissive loaded;
	loaded.set_pid(GetCurrentProcessId());

	if (!record.profileName.empty())
	{
		proto::login::ProfileMethod& profile = *loaded.mutable_profile();

		SerializeProfile(record, profile);
	}
	else
	{
		proto::login::DirectMethod& direct = *loaded.mutable_direct();

		SerializeProfile(record, direct);
	}

	Post(proto::login::ProfileLoaded, loaded);
}

void NotifyCharacterUnload()
{
	proto::login::StopInstanceMissive stop;
	stop.set_pid(GetCurrentProcessId());

	Post(proto::login::ProfileUnloaded, stop);
}

void Login::SetProfileRecord(const std::shared_ptr<ProfileRecord>& ptr, bool setCurrent)
{
	if (m_record == ptr)
		return;

	m_record = ptr;

	// We don't remove the character info if this is cleared
	if (m_record)
	{
		// Don't set current record while we're camping, because it can be canceled.
		if (Login::last_state() != LoginState::InGame && Login::last_state() != LoginState::InGameCamping)
		{
			set_current_record(m_record);
		}
	}
}

void NotifyCharacterUpdate(int Class, int Level, const char* Server, const char* Character)
{
	proto::login::CharacterInfoMissive info;
	info.set_class_(Class);
	info.set_level(Level);
	info.set_server(Server);
	info.set_character(Character);

	Post(proto::login::ProfileCharInfo, info);
}

void LoginServerSelect(const char* Login, const char* Pass)
{
	proto::login::StartInstanceMissive start;
	proto::login::DirectMethod& method = *start.mutable_direct();
	method.set_login(Login);
	method.set_password(Pass);

	Post(proto::login::StartInstance, start);
}

void LoginServer(const char* Login, const char* Pass, const char* Server)
{
	proto::login::StartInstanceMissive start;
	proto::login::DirectMethod& method = *start.mutable_direct();
	method.set_login(Login);
	method.set_password(Pass);
	proto::login::LoginTarget& target = *method.mutable_target();
	target.set_server(Server);

	Post(proto::login::StartInstance, start);
}

void LoginCharacter(const char* Login, const char* Pass, const char* Server, const char* Character)
{
	proto::login::StartInstanceMissive start;
	proto::login::DirectMethod& method = *start.mutable_direct();
	method.set_login(Login);
	method.set_password(Pass);
	proto::login::LoginTarget& target = *method.mutable_target();
	target.set_server(Server);
	target.set_character(Character);

	Post(proto::login::StartInstance, start);
}

void LoginProfile(const char* Profile, const char* Server, const char* Character)
{
	proto::login::StartInstanceMissive start;
	proto::login::ProfileMethod& method = *start.mutable_profile();
	method.set_profile(Profile);
	proto::login::LoginTarget& target = *method.mutable_target();
	target.set_server(Server);
	target.set_character(Character);

	Post(proto::login::StartInstance, start);
}

ProfileRecord GetCharacterProfile(const char* serverName, const char* szCharacter)
{
	// Check if a profile exists matching this character name on the same server and profile.
	if (std::shared_ptr<ProfileRecord> record = Login::get_current_record())
	{
		auto profiles = login::db::GetProfiles(record->profileName);

		for (auto& profile : profiles)
		{
			if (ci_equals(profile.characterName, szCharacter)
				&& ci_equals(profile.serverName, serverName)
				&& ci_equals(profile.accountName, record->accountName))
			{
				return profile;
			}
		}
	}

	ProfileRecord record;
	record.serverName = to_lower_copy(serverName);
	record.characterName = to_lower_copy(szCharacter);

	return record;
}

// Returns the profile name if we found one.
std::string SwitchCharacterProfile(const char* serverName, const char* szCharacter)
{
	ProfileRecord rec = GetCharacterProfile(serverName, szCharacter);

	Login::dispatch(SetLoginProfile(rec));
	return rec.profileName;
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

#if IS_EMU_CLIENT
	auto server_names = login::db::ListServers().vector();

	// this is just a validity check, that's the only reason we have that set of server names
	if (std::find_if(begin(server_names), end(server_names), [&szServer](std::string_view s) { return ci_equals(s, szServer); }) == server_names.end())
	{
		WriteChatf("\ar[AutoLogin]\ax Invalid server name \ag%s\ax. Valid server names are:", szServer);
		WriteChatColor(join(server_names, ", ").c_str());
	}
#else
	// this is just a validity check, that's the only reason we have that set of server names
	if (GetServerIDFromServerName(szServer) == ServerID::Invalid)
	{
		WriteChatf("\ar[AutoLogin]\ax Invalid server name \ag%s\ax. Valid server names are:", szServer);

		std::vector<std::string_view> server_names;
		std::transform(std::begin(eqlib::ServerIDArray), std::end(eqlib::ServerIDArray),
			std::back_inserter(server_names), [](const ServerID id) { return GetServerNameFromServerID(id); });

		WriteChatColor(join(server_names, ", ").c_str());
	}
#endif
	else if (GetGameState() == GAMESTATE_INGAME && pChar
		&& ci_equals(GetServerShortName(), szServer)
		&& ci_equals(pChar->DisplayedName, szCharacter))
	{
		WriteChatf("\ay[AutoLogin]\ax You're already logged into '%s' on '%s'\ax", szCharacter, szServer);
	}
	else
	{
		if (std::string profileName = SwitchCharacterProfile(szServer, szCharacter); !profileName.empty())
		{
			WriteChatf("\ag[AutoLogin]\ax Switching to \ag%s\ax on server \ag%s\ax with profile \ay%s\ax.",
				szCharacter, szServer, profileName.c_str());
		}
		else
		{
			WriteChatf("\ag[AutoLogin]\ax Switching to \ag%s\ax on server \ag%s\ax.", szCharacter, szServer);
		}
	}
}

void Cmd_SwitchCharacter(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine[0])
	{
		WriteChatf("\ayUsage:\ax /switchchar <name>");
		return;
	}

	char szCharacter[MAX_STRING] = { 0 };
	GetArg(szCharacter, szLine, 1);

	if (GetGameState() == GAMESTATE_INGAME && pChar && ci_equals(pChar->DisplayedName, szCharacter))
	{
		WriteChatf("\ay[AutoLogin]\ax You're already logged onto '%s'\ax", szCharacter);
	}
	else
	{
		const char* szServer = GetServerShortName();
		if (std::string profileName = SwitchCharacterProfile(szServer, szCharacter); !profileName.empty())
		{
			WriteChatf("\ag[AutoLogin]\ax Switching to \ag%s\ax with profile \ay%s\ax.",
				szCharacter, profileName.c_str());
		}
		else
		{
			WriteChatf("\ag[AutoLogin]\ax Switching to \ag%s\ax.", szCharacter);
		}
	}
}

void Cmd_Relog(SPAWNINFO* pChar, char* szLine)
{
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
		s_reenableTime = MQGetTickCount64() + n;
	}

	if (s_reenableTime)
		s_reenableTime += 30000; // add 30 seconds for camp time

	if (GetGameState() == GAMESTATE_INGAME && pLocalPlayer && GetServerShortName()[0] != 0)
	{
		SwitchCharacterProfile(GetServerShortName(), pLocalPlayer->DisplayedName);

		// TODO:  After std::chrono change, update this to actual time.  It will currently show whatever multiple arguments the user typed in.
		WriteChatf("\ag[AutoLogin]\ax Relog into \ag%s\ax on server \ag%s\ax will activate after %s.",
			pLocalPlayer->DisplayedName, GetServerShortName(), szLine);
	}
}

void Cmd_Loginchar(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine[0])
	{
		WriteChatf("\ayUsage:\ax /loginchar [profile_server:character|server:character|server^login^character^password|server^login^password]");
		return;
	}

	auto record = ProfileRecord::FromString(szLine);
	if (!record.profileName.empty() && !record.serverName.empty() && !record.characterName.empty())
	{
		LoginProfile(
			record.profileName.c_str(),
			record.serverName.c_str(),
			record.characterName.c_str());
	}
	else if (!record.accountName.empty() && !record.accountPassword.empty())
	{
		if (record.serverName.empty())
			LoginServerSelect(
				record.accountName.c_str(),
				record.accountPassword.c_str());
		else if (record.characterName.empty())
			LoginServer(
				record.accountName.c_str(),
				record.accountPassword.c_str(),
				record.serverName.c_str());
		else
			LoginCharacter(
				record.accountName.c_str(),
				record.accountPassword.c_str(),
				record.serverName.c_str(),
				record.characterName.c_str());
	}
	else if (!record.serverName.empty() && !record.characterName.empty())
	{
		login::db::ReadAccount(record);

		if (!record.accountName.empty() && !record.accountPassword.empty())
			LoginCharacter(
				record.accountName.c_str(),
				record.accountPassword.c_str(),
				record.serverName.c_str(),
				record.characterName.c_str());
		else
			WriteChatf("Could not find %s:%s in your autologin db", record.serverName.c_str(), record.characterName.c_str());
	}
	else if (!record.profileName.empty())
	{
		login::db::ReadFirstProfile(record);
		LoginProfile(
			record.profileName.c_str(),
			record.serverName.c_str(),
			record.characterName.c_str());
	}
	else
	{
		WriteChatf("\ayUsage:\ax /loginchar [profile|profile_server:character|server:character|server^login^character^password|server^login^password]");
	}
}

DETOUR_TRAMPOLINE_DEF(DWORD WINAPI, GetPrivateProfileStringA_Trampoline, (LPCSTR, LPCSTR, LPCSTR, LPSTR, DWORD, LPCSTR))

DWORD WINAPI GetPrivateProfileStringA_Detour(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpDefault, LPSTR lpReturnedString, DWORD nSize, LPCSTR lpFileName)
{
	if (lpFileName)
	{
		const auto& CustomIni = Login::custom_ini();

		if (CustomIni && !CustomIni->empty() && ci_find_substr(lpFileName, "eqclient.ini") != -1)
		{
			return GetPrivateProfileStringA_Trampoline(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, CustomIni->c_str());
		}
	}

	return GetPrivateProfileStringA_Trampoline(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName);
}

DETOUR_TRAMPOLINE_DEF(BOOL WINAPI, WritePrivateProfileStringA_Trampoline, (LPCSTR, LPCSTR, LPCSTR, LPCSTR))
BOOL WINAPI WritePrivateProfileStringA_Detour(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpString, LPCSTR lpFileName)
{
	if (lpFileName)
	{
		const auto& CustomIni = Login::custom_ini();

		if (CustomIni && !CustomIni->empty() && ci_find_substr(lpFileName, "eqclient.ini") != -1)
		{
			return WritePrivateProfileStringA_Trampoline(lpAppName, lpKeyName, lpString, CustomIni->c_str());
		}
	}

	return WritePrivateProfileStringA_Trampoline(lpAppName, lpKeyName, lpString, lpFileName);
}

DETOUR_TRAMPOLINE_DEF(UINT WINAPI, GetPrivateProfileIntA_Tramp, (LPCSTR, LPCSTR, INT, LPCSTR))
UINT WINAPI GetPrivateProfileIntA_Detour(LPCSTR lpAppName, LPCSTR lpKeyName, INT nDefault, LPCSTR lpFileName)
{
	if (lpFileName)
	{
		const auto& CustomIni = Login::custom_ini();

		if (CustomIni && !CustomIni->empty() && ci_find_substr(lpFileName, "eqclient.ini") != -1)
		{
			return GetPrivateProfileIntA_Tramp(lpAppName, lpKeyName, nDefault, CustomIni->c_str());
		}
	}

	return GetPrivateProfileIntA_Tramp(lpAppName, lpKeyName, nDefault, lpFileName);
}

void AutoLoginDebug(std::string_view svLogMessage, const bool bDebugOn /* = AUTOLOGIN_DBG */)
{
	if (bDebugOn)
	{
		std::filesystem::path pathToDebugLog = gPathLogs;
		pathToDebugLog /= "MQ2AutoLogin_DBG.log";

		FILE* fLog = _fsopen(pathToDebugLog.string().c_str(), "a", _SH_DENYWR);

		if (!fLog)
		{
			DebugSpewAlways("Could not open MQ2Autologin Debug log for appending.");
		}
		else
		{
			SYSTEMTIME t;
			GetLocalTime(&t);

			const std::string strLogMessage = fmt::format("[{Year:04d}-{Month:02d}-{Day:02d} {Hour:02d}:{Minute:02d}:{Second:02d}] {LogMessage}",
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

			WriteChatf("\ay[AutoLogin]\ax %.*s", svLogMessage.size(), svLogMessage.data());
		}
	}
}

void ReadSettings()
{
	AUTOLOGIN_DBG = GetPrivateProfileBool("Settings", "Debug", AUTOLOGIN_DBG, INIFileName);
	if (const auto debug = login::db::ReadSetting("debug"))
		AUTOLOGIN_DBG = GetBoolFromString(*debug, AUTOLOGIN_DBG);

	if (const auto kick_active = login::db::ReadSetting("kick_active"))
		Login::m_settings.KickActiveCharacter = GetBoolFromString(*kick_active, Login::m_settings.KickActiveCharacter);

	if (const auto end_after_select = login::db::ReadSetting("end_after_select"))
		Login::m_settings.EndAfterSelect = GetBoolFromString(*end_after_select, Login::m_settings.EndAfterSelect);

	if (const auto char_select_delay = login::db::ReadSetting("char_select_delay"))
		Login::m_settings.CharSelectDelay = GetIntFromString(*char_select_delay, Login::m_settings.CharSelectDelay);

	if (const auto connect_retries = login::db::ReadSetting("login_connect_retries"))
		Login::m_settings.ConnectRetries = GetIntFromString(*connect_retries, Login::m_settings.ConnectRetries);
}

void LoginReset()
{
	AutoLoginDebug("LoginReset()");
	ReadSettings();
}

class LoginServer_Hook
{
public:
	DETOUR_TRAMPOLINE_DEF(unsigned int, JoinServer_Trampoline, (int, void*, int))
	unsigned int JoinServer_Detour(int serverID, void* userdata, int timeoutseconds)
	{
		// if someone uses the everquest patcher instead of launching with the patchme option,
		// Account isn't correct and Password is empty, so make sure to test for an empty
		// Password downstream
		Login::m_currentLogin.Account = g_pLoginClient->LoginName;
		Login::m_currentLogin.Password = g_pLoginClient->Password;

		Login::m_currentLogin.ServerName =
			[serverID = static_cast<ServerID>(serverID)]() -> std::string
			{
				for (const auto server : g_pLoginClient->ServerList)
					if (server->ID == serverID)
						return server->ServerName.c_str();

				return {};
			}();

		return JoinServer_Trampoline(serverID, userdata, timeoutseconds);
	}
};

static bool DoesProfileMatchCurrentSession(const ProfileRecord& record)
{
	return ci_equals(record.characterName, pLocalPlayer->DisplayedName)
		&& ci_equals(record.serverName, GetServerShortName())
		&& (record.accountName.empty() || ci_equals(record.accountName, GetLoginName()));
}

PLUGIN_API void SetGameState(int GameState)
{
	// this works because we will always have a gamestate change after loading or unloading eqmain
	// GAMESTATE_PRECHARSELECT when transitioning from character select to server select, and
	// GAMESTATE_CHARSELECT when transitioning to character select from server select
	if (s_joinServer != EQMain__LoginServerAPI__JoinServer)
	{
		if (s_joinServer != 0)
			RemoveDetour(s_joinServer);

		s_joinServer = EQMain__LoginServerAPI__JoinServer;

		if (s_joinServer != 0)
			EzDetour(s_joinServer, &LoginServer_Hook::JoinServer_Detour, &LoginServer_Hook::JoinServer_Trampoline);
	}

	if (GameState == GAMESTATE_CHARSELECT)
	{
		Login::clear_current_window();

		// at character select now, if we have a memoized long name let's update the db for the server name pairing
		if (!Login::m_currentLogin.ServerName.empty())
			login::db::CreateOrUpdateServer(GetServerShortName(), Login::m_currentLogin.ServerName);

		// grab the option to automatically create entries
		static auto do_detect = login::db::CacheSetting<bool>("detect_info", true, GetBoolFromString);

		// if we don't have a password it means our account is not reliable.
		if (do_detect.Read() && !Login::m_currentLogin.Account.empty() && !Login::m_currentLogin.Password.empty())
		{
			ProfileRecord profile;
			profile.accountName = Login::m_currentLogin.Account;
			to_lower(profile.accountName);
			profile.accountPassword = Login::m_currentLogin.Password;

			if (Login::m_lastAccount.empty())
			{
				Login::m_lastAccount = Login::m_currentLogin.Account;
			}

			char path[MAX_PATH] = { 0 };
			GetModuleFileName(nullptr, path, MAX_PATH);
			const std::filesystem::path fs_path(path);

			if (const auto server_type = login::db::GetServerTypeFromPath(fs_path.parent_path().string()))
				profile.serverType = *server_type;
			else
				profile.serverType = GetBuildTargetName(static_cast<BuildTarget>(gBuild));

			to_lower(profile.serverType);

			login::db::CreateAccount(profile);

			profile.serverName = GetServerShortName();
			for (const auto& char_info : pEverQuest->charSelectPlayerArray)
			{
				profile.characterName = char_info.Name;
				to_lower(profile.characterName);

				// we don't want to completely overwrite an existing character (mostly for the visibility flag)
				// so ensure that we are only updating the things that we actually detected
				ProfileRecord existing;
				existing.characterName = profile.characterName;
				existing.serverName = profile.serverName;
				if (login::db::ReadCharacter(existing))
				{
					if (!ci_equals(existing.accountName, profile.accountName) || !ci_equals(existing.serverType, profile.serverType))
					{
						existing.accountName = profile.accountName;
						existing.serverType = profile.serverType;
						login::db::UpdateCharacter(existing.serverName, existing.characterName, existing);
					}
				}
				else
				{
					login::db::CreateCharacter(profile);
				}

				// ClassInfo[0] is empty, don't persist that or any non-class
				if (char_info.Class > 0 && char_info.Class <= MAX_PLAYER_CLASSES)
				{
					profile.characterClass = ClassInfo[char_info.Class].UCShortName;
					to_upper(profile.characterClass);
					profile.characterLevel = static_cast<int>(char_info.Level);
					login::db::CreatePersona(profile);
				}
			}
		}

		Login::m_currentLogin.reset();
	}

	if (GameState == GAMESTATE_INGAME )
	{
		if (const std::shared_ptr<ProfileRecord>& currentRecord = Login::get_current_record())
		{
			// If we manage to get into the game on a different character than what we had started our profile
			// with, switch profiles.
			if (!DoesProfileMatchCurrentSession(*currentRecord))
			{
				Login::set_current_record(
					std::make_shared<ProfileRecord>(GetCharacterProfile(GetServerShortName(), pLocalPlayer->DisplayedName)));
			}
			else
			{
				NotifyCharacterLoad(currentRecord);
			}
		}
		else
		{
			Login::set_current_record(
				std::make_shared<ProfileRecord>(GetCharacterProfile(GetServerShortName(), pLocalPlayer->DisplayedName)));
		}
	}

	Login::dispatch(ChangeGameState(GameState));
}

static void HandleMessage(const std::shared_ptr<postoffice::Message>& message)
{
	if (message->Payload)
	{
		proto::login::LoginMessage loginMessage;
		loginMessage.ParseFromString(*message->Payload);

		switch (loginMessage.id())
		{
		case proto::login::Identify:
			// We don't actually care about the payload here, we just want to send our data.
			if (auto profile = Login::get_current_record())
				NotifyCharacterLoad(profile);
			break;

		case proto::login::ApplyProfile:
			if (loginMessage.has_payload())
			{
				proto::login::ApplyProfileMissive payload;
				payload.ParseFromString(loginMessage.payload());

				ProfileRecord record = ParseProfileFromMessage(payload);

				char profileStr[256] = { 0 };
				if (!record.profileName.empty())
					sprintf_s(profileStr, "%s: %s (%s)", record.profileName.c_str(), record.characterName.c_str(), record.serverName.c_str());
				else
					sprintf_s(profileStr, "%s (%s)", record.characterName.c_str(), record.serverName.c_str());

				if (!record.hotkey.empty())
				{
					strcat_s(profileStr, " hotkey: ");
					strcat_s(profileStr, record.hotkey.c_str());
				}

				if (payload.do_login())
				{
					WriteChatf("\ag[AutoLogin]\ax Received command to begin loading character: %s", profileStr);

					Login::dispatch(SetLoginProfile(record));
				}
				else
				{
					// Not performing a login, so just check that the character/server match and
					// apply the rest.
					if (!pLocalPlayer || DoesProfileMatchCurrentSession(record))
					{
						WriteChatf("\ag[AutoLogin]\ax Received new profile assignment: %s", profileStr);

						Login::set_current_record(std::make_shared<ProfileRecord>(record));
					}
					else
					{
						WriteChatf("\ar[AutoLogin]\ax Received new profile assignment that doesn't match current character: %s", profileStr);
					}
				}
			}
			break;

		default: break;
		}
	}
}

PLUGIN_API void InitializePlugin()
{
	pAutoLoginType = new MQ2AutoLoginType;
	pLoginProfileType = new LoginProfileType;
	AddTopLevelObject("AutoLogin", MQ2AutoLoginType::dataAutoLogin);

	if (!login::db::InitDatabase((fs::path(gPathConfig) / "login.db").string()))
	{
		WriteChatf("\ar[AutoLogin]\ax Could not load autologin database, Autologin functionality will be disabled");
	}

	Login::set_initial_state();
	ReadSettings();

	AddCommand("/switchserver", Cmd_SwitchServer);
	AddCommand("/switchcharacter", Cmd_SwitchCharacter);
	AddCommand("/relog", Cmd_Relog, false, true, true);
	AddCommand("/loginchar", Cmd_Loginchar);

	if (EQMain__LoginServerAPI__JoinServer != 0)
	{
		// we have eqmain offset, save the offset because it gets cleared before we can unset the detour
		s_joinServer = EQMain__LoginServerAPI__JoinServer;
		EzDetour(s_joinServer, &LoginServer_Hook::JoinServer_Detour, &LoginServer_Hook::JoinServer_Trampoline);
	}

	if (const auto custom_client_ini = login::db::ReadSetting("custom_client_ini");
		custom_client_ini && GetBoolFromString(*custom_client_ini, false))
	{
		uintptr_t pfnGetPrivateProfileIntA = (uintptr_t)&::GetPrivateProfileIntA;
		EzDetour(pfnGetPrivateProfileIntA, GetPrivateProfileIntA_Detour, GetPrivateProfileIntA_Tramp);

		uintptr_t pfnGetPrivateProfileStringA = (uintptr_t)&::GetPrivateProfileStringA;
		EzDetour(pfnGetPrivateProfileStringA, GetPrivateProfileStringA_Detour, GetPrivateProfileStringA_Trampoline);

		uintptr_t pfnWritePrivateProfileStringA = (uintptr_t)&::WritePrivateProfileStringA;
		EzDetour(pfnWritePrivateProfileStringA, WritePrivateProfileStringA_Detour, WritePrivateProfileStringA_Trampoline);
	}

	s_reenableTime = MQGetTickCount64() + STEP_DELAY;

	// create a server type for this build if it doesn't already exist (to ensure that automatic character creation works)
	std::string server_type = GetBuildTargetName(static_cast<BuildTarget>(gBuild));
	to_lower(server_type);
	if (!login::db::GetPathFromServerType(server_type))
	{
		char path[MAX_PATH] = { 0 };
		GetModuleFileName(nullptr, path, MAX_PATH);
		const std::filesystem::path fs_path(path);

		login::db::CreateOrUpdateServerType(server_type, fs_path.parent_path().string());
	}

	s_autologinDropbox = postoffice::AddActor("autologin", HandleMessage);

	LoadCharacterCallback = [](const ProfileRecord& record, bool)
		{
			ProfileRecord copy(record);
			copy.accountPassword = login::db::ReadPassword(record.accountName, record.serverType).value_or("");

			Login::dispatch(SetLoginProfile(copy));
		};
}

PLUGIN_API void ShutdownPlugin()
{
	NotifyCharacterUnload();

	RemoveCommand("/switchserver");
	RemoveCommand("/switchcharacter");
	RemoveCommand("/relog");
	RemoveCommand("/loginchar");

	if (s_joinServer != 0)
	{
		// if this is set, then we have the detour set
		RemoveDetour(s_joinServer);
		s_joinServer = 0;
	}

	uintptr_t pfnGetPrivateProfileIntA = (uintptr_t) & ::GetPrivateProfileIntA;
	RemoveDetour(pfnGetPrivateProfileIntA);

	uintptr_t pfnGetPrivateProfileStringA = (uintptr_t) & ::GetPrivateProfileStringA;
	RemoveDetour(pfnGetPrivateProfileStringA);

	uintptr_t pfnWritePrivateProfileStringA = (uintptr_t) & ::WritePrivateProfileStringA;
	RemoveDetour(pfnWritePrivateProfileStringA);

	LoginReset();
	RemoveTopLevelObject("AutoLogin");
	delete pAutoLoginType;
	delete pLoginProfileType;

	s_autologinDropbox.Remove();

	login::db::ShutdownDatabase();
}

void SendWndNotification(CXWnd* pWnd, CXWnd* sender, uint32_t msg, void* data)
{
#if HAS_GAMEFACE_UI
	if (GetGameState() == GAMESTATE_PRECHARSELECT)
		reinterpret_cast<eqlib::eqmain::CXWnd*>(pWnd)->WndNotification(
			reinterpret_cast<eqlib::eqmain::CXWnd*>(sender), msg, data);
	else
#endif
		pWnd->WndNotification(sender, msg, data);
}

CXStr GetWindowText(CXWnd* pWnd)
{
	if (!pWnd) return CXStr();

	CXMLDataManager* pXmlMgr = pSidlMgr->GetParamManager();
	auto type = pXmlMgr->GetWindowType(pWnd);

#if HAS_GAMEFACE_UI
	if (GetGameState() == GAMESTATE_PRECHARSELECT)
	{
		return type == UI_STMLBox
			? reinterpret_cast<eqlib::eqmain::CStmlWnd*>(pWnd)->STMLText
			: reinterpret_cast<eqlib::eqmain::CXWnd*>(pWnd)->GetWindowText();
	}
#endif

	return type == UI_STMLBox
		? static_cast<CStmlWnd*>(pWnd)->STMLText
		: pWnd->GetWindowText();
}

CXStr GetEditWndText(CEditWnd* pWnd)
{
	if (!pWnd) return CXStr();

#if HAS_GAMEFACE_UI
	if (GetGameState() == GAMESTATE_PRECHARSELECT)
	{
		return reinterpret_cast<eqlib::eqmain::CEditBaseWnd*>(pWnd)->InputText;
	}
#endif

	return pWnd->InputText;
}

void SetEditWndText(CEditWnd* pWnd, std::string_view text)
{
#if HAS_GAMEFACE_UI
	if (GetGameState() == GAMESTATE_PRECHARSELECT)
	{
		reinterpret_cast<eqlib::eqmain::CEditBaseWnd*>(pWnd)->InputText = text;
	}
	else
#endif
	{
		pWnd->InputText = text;
	}
}

CXStr GetSTMLText(CStmlWnd* pWnd)
{
	if (!pWnd) return CXStr();

#if HAS_GAMEFACE_UI
	if (GetGameState() == GAMESTATE_PRECHARSELECT)
	{
		return reinterpret_cast<eqlib::eqmain::CStmlWnd*>(pWnd)->STMLText;
	}
#endif

	return pWnd->STMLText;
}

ArrayClass<SListWndLine>* GetItemsArray(CListWnd* pWnd)
{
	if (!pWnd) return nullptr;

#if HAS_GAMEFACE_UI
	if (GetGameState() == GAMESTATE_PRECHARSELECT)
	{
		return &reinterpret_cast<eqlib::eqmain::CListWnd*>(pWnd)->ItemsArray;
	}
#endif

	return &pWnd->ItemsArray;
}

CXStr GetListItemText(CListWnd* pWnd, int row, int col)
{
	if (!pWnd) return CXStr();

#if HAS_GAMEFACE_UI
	if (GetGameState() == GAMESTATE_PRECHARSELECT)
	{
		return reinterpret_cast<eqlib::eqmain::CListWnd*>(pWnd)->GetItemText(row, col);
	}
#endif

	return pWnd->GetItemText(row, col);
}

int GetListCurSel(CListWnd* pWnd)
{
#if HAS_GAMEFACE_UI
	if (GetGameState() == GAMESTATE_PRECHARSELECT)
	{
		return reinterpret_cast<eqlib::eqmain::CListWnd*>(pWnd)->CurSel;
	}
#endif

	return pWnd->GetCurSel();
}

// save off class and level so we know when to push updates
int s_lastCharacterLevel = -1;
int s_lastCharacterClass = -1;

PLUGIN_API void OnPulse()
{
	if (pLocalPlayer && (pLocalPlayer->GetClass() != s_lastCharacterClass || pLocalPlayer->Level != s_lastCharacterLevel))
	{
		s_lastCharacterClass = pLocalPlayer->GetClass();
		s_lastCharacterLevel = pLocalPlayer->Level;
		NotifyCharacterUpdate(s_lastCharacterClass, s_lastCharacterLevel, GetServerShortName(), pLocalPlayer->DisplayedName);
	}

	if (gbInForeground && GetAsyncKeyState(VK_HOME) & 1)
		Login::dispatch(UnpauseLogin(true));
	else if (gbInForeground && GetAsyncKeyState(VK_END) & 1)
		Login::dispatch(PauseLogin(true));
	else if (GetGameState() == GAMESTATE_INGAME)
	{
		if (pEverQuestInfo->ExitCounter != Login::m_campTimer)
		{
			Login::dispatch(SetCampTimer(pEverQuestInfo->ExitCounter));
		}
	}
	else if (GetGameState() == GAMESTATE_CHARSELECT && MQGetTickCount64() > s_reenableTime)
	{
		CSidlScreenWnd* pConfirmationWnd = GetWindow<CSidlScreenWnd>("ConfirmationDialogBox");
		if (pConfirmationWnd != nullptr && pConfirmationWnd->IsVisible())
		{
			if (CStmlWnd* pStmlWnd = GetChildWindow<CStmlWnd>(pConfirmationWnd, "CD_TextOutput"))
			{
				static const std::vector<std::pair<const char*, const char*>> PromptWindows = {
					// Greetings Norrathian, by creating a new character and playing on Rizlona you agree to
					// abide by the server specific rules and regulations in addition to the previously
					// agreed upon terms of service and EULA. (everquest.com/TLP2020) Do you accept these rules?
					{ "Do you accept these rules?",
					  "CD_Yes_Button", },

					// It took %1 seconds to load your characters, it is possible one or more failed to load.
					// Please contact Customer Service if one of your characters is missing.
					{ "Please contact Customer Service if one of your characters is missing.",
					  "CD_OK_Button", },
				};

				CXStr messageText = GetSTMLText(pStmlWnd);

				for (auto [message, buttonName] : PromptWindows)
				{
					if (ci_find_substr(messageText, message) != -1)
					{
						if (CButtonWnd* pButton = GetChildWindow<CButtonWnd>(pConfirmationWnd, buttonName))
						{
							SendWndNotification(pButton, pButton, XWM_LCLICK);
						}
					}
				}
			}
		}
		else if (CXWnd* pCharsWnd = GetWindow("CLW_CharactersScreen"))
			Login::dispatch(LoginStateSensor(LoginState::CharacterSelect, pCharsWnd));

		s_reenableTime = MQGetTickCount64() + STEP_DELAY;
	}
	else if (GetGameState() == GAMESTATE_PRECHARSELECT && g_pLoginClient && (MQGetTickCount64() > s_reenableTime || Login::m_skipNextDelay))
	{
		Login::m_skipNextDelay = false;
		// pair of WindowNames / ButtonNames
		static const std::vector<std::pair<const char*, const char*>> PromptWindows = {
			{ "OrderWindow",          "Order_DeclineButton" },
			{ "EulaWindow",           "EULA_AcceptButton" },
			{ "seizurewarning",       "HELP_OKButton"},
			{ "OrderExpansionWindow", "OrderExp_DeclineButton" },
			{ "main",                 "MAIN_ConnectButton" },
			{ "news",                 "NEWS_OKButton"}
		};

		// Click through any dialogs, don't need a whole state for this
		for (const auto& [windowName, buttonName] : PromptWindows)
		{
			if (CButtonWnd* pButton = GetActiveChildWindow<CButtonWnd>(windowName, buttonName))
			{
				SendWndNotification(pButton, pButton, XWM_LCLICK);
				return;
			}
		}

		if (IsWindowActive("dbgsplash") || IsWindowActive("soesplash"))
		{
			Login::dispatch(LoginStateSensor(LoginState::SplashScreen, nullptr));
		}
		else if (CXWnd* pConnectWnd = GetActiveWindow("connect"))
		{
			if (CXWnd* pOkDialog = GetActiveWindow("okdialog"))
				Login::dispatch(LoginStateSensor(LoginState::ConnectConfirm, pOkDialog));
			else
				Login::dispatch(LoginStateSensor(LoginState::Connect, pConnectWnd));
		}
		else if (CXWnd* pServerWnd = GetActiveWindow("serverselect"))
		{
			if (CXWnd* pOkDialog = GetActiveWindow("okdialog"))
				Login::dispatch(LoginStateSensor(LoginState::ServerSelectConfirm, pOkDialog));
			else if (CXWnd* pYesNoDialog = GetActiveWindow("yesnodialog"))
				Login::dispatch(LoginStateSensor(LoginState::ServerSelectKick, pYesNoDialog));
			else
				Login::dispatch(LoginStateSensor(LoginState::ServerSelect, pServerWnd));
		}

		s_reenableTime = MQGetTickCount64() + STEP_DELAY;
	}
}

static bool s_showAutoLoginOverlay = true;
static bool s_showOverlayDebugInfo = false;
static bool s_showServerList = false;

static bool InputInt(const char* label, int* v, int step = 1, int step_fast = 10, ImGuiInputTextFlags flags = 0)
{
	return ImGui::InputScalar(label, ImGuiDataType_U32, (void*)v, (void*)(step>0 ? &step : NULL), (void*)(step_fast>0 ? &step_fast : NULL), "%d", flags);
}

static void DisplayProfileInfo(const std::shared_ptr<ProfileRecord>& profile, bool allowClear)
{
	if (profile)
	{
		float width = ImGui::GetContentRegionAvail().x - (ImGui::GetStyle().FramePadding.x * 2);

		auto show_buttons = [allowClear, &profile]()
			{
				bool hovered = false;
				if (allowClear)
				{
					ImGui::SameLine();

					if (ImGui::SmallButton(ICON_MD_CLEAR))
					{
						Login::clear_current_record();
					}

					if (ImGui::IsItemHovered(ImGuiHoveredFlags_ForTooltip))
					{
						ImGui::SetTooltip(
							"Clear the currently loaded profile. This will\n"
							"also detach the session from the current hotkey (if any)."
						);
						hovered = true;
					}

					ImGui::SameLine();

					if (ImGui::SmallButton(ICON_MD_REDO))
					{
						Login::dispatch(SetLoginProfile(*profile));
					}

					if (ImGui::IsItemHovered(ImGuiHoveredFlags_ForTooltip | ImGuiHoveredFlags_DelayNone))
					{
						ImGui::SetTooltip(
							"Re-run autologin on this profile"
						);
						hovered = true;
					}
				}

				return hovered;
			};

		bool hovered = false;

		ImVec2 posMin = ImGui::GetCursorScreenPos();

		if (!profile->profileName.empty())
		{
			ImGui::TextUnformatted("Profile: ");
			ImGui::SameLine(0, 0);
			ImGui::TextColored(MQColor(255, 255, 0).ToImColor(), "%s", profile->profileName.c_str());
			hovered = show_buttons();

			ImGui::TextUnformatted("Character: ");
			ImGui::SameLine(0, 0);
			ImGui::TextColored(MQColor(0, 255, 0).ToImColor(), "%s (%s)", profile->characterName.c_str(), profile->serverName.c_str());
		}
		else if (!profile->characterName.empty())
		{
			ImGui::TextUnformatted("Character: ");
			ImGui::SameLine(0, 0);
			ImGui::TextColored(MQColor(0, 255, 0).ToImColor(), "%s (%s)", profile->characterName.c_str(), profile->serverName.c_str());
			hovered = show_buttons();
		}
		else if (!profile->serverName.empty() || !profile->accountName.empty())
		{
			if (!profile->serverName.empty())
			{
				ImGui::TextUnformatted("Server: ");
				ImGui::SameLine(0, 0);
				ImGui::TextColored(MQColor(0, 255, 0).ToImColor(), "%s", profile->serverName.c_str());
				hovered = show_buttons();
			}

			ImGui::TextUnformatted("Account: ");
			ImGui::SameLine(0, 0);
			ImGui::TextColored(MQColor(0, 255, 0).ToImColor(), "%s", profile->accountName.c_str());

			if (profile->serverName.empty())
				hovered = show_buttons();
		}

		ImVec2 posMax = ImGui::GetCursorScreenPos();
		posMax.x = ImGui::GetCurrentWindow()->DC.CursorPosPrevLine.x;

		if (!hovered && ImGui::IsMouseHoveringRect(posMin, posMax))
		{
			if (ImGui::BeginTooltip())
			{
				if (!profile->profileName.empty())
				{
					ImGui::TextUnformatted("Profile: ");
					ImGui::SameLine(0, 0);
					ImGui::TextColored(MQColor(255, 255, 0).ToImColor(), "%s", profile->profileName.c_str());
				}

				if (!profile->characterName.empty())
				{
					ImGui::TextUnformatted("Character: ");
					ImGui::SameLine(0, 0);
					ImGui::TextColored(MQColor(0, 255, 0).ToImColor(), "%s", profile->characterName.c_str());
				}

				if (!profile->serverName.empty())
				{
					ImGui::TextUnformatted("Server: ");
					ImGui::SameLine(0, 0);
					ImGui::TextColored(MQColor(0, 255, 0).ToImColor(), "%s", profile->serverName.c_str());
				}

				if (!profile->accountName.empty())
				{
					ImGui::TextUnformatted("Account: ");
					ImGui::SameLine(0, 0);
					ImGui::TextColored(MQColor(0, 255, 0).ToImColor(), "%s", profile->accountName.c_str());
				}

				ImGui::EndTooltip();
			}
		}

		if (!profile->hotkey.empty())
		{
			ImGui::TextUnformatted("HotKey: ");
			ImGui::SameLine(0, 0);
			ImGui::TextColored(MQColor(255, 255, 0).ToImColor(), "%s", profile->hotkey.c_str());
		}

		ImGui::Spacing();
	}
}

static void ShowAutoLoginOverlay(bool* p_open)
{
	const float DISTANCE = 10.0f;

	int gameState = GetGameState();
	int corner = (gameState == GAMESTATE_CHARSELECT ? 1 : 0); // 0 = top left, 1 = top right, 2 = bottom left, 3 = bottom right
	if (gameState == GAMESTATE_INGAME)
		corner = -1;
	ImGuiIO& io = ImGui::GetIO();

	if (corner != -1)
	{
		ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImVec2 window_pos = ImVec2((corner & 1) ? (viewport->Pos.x + viewport->Size.x - DISTANCE) : (viewport->Pos.x + DISTANCE), (corner & 2) ? (viewport->Pos.y + viewport->Size.y - DISTANCE) : (viewport->Pos.y + DISTANCE));
		ImVec2 window_pos_pivot = ImVec2((corner & 1) ? 1.0f : 0.0f, (corner & 2) ? 1.0f : 0.0f);
		ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always, window_pos_pivot);
		ImGui::SetNextWindowViewport(viewport->ID);
	}

	ImGui::SetNextWindowSizeConstraints(ImVec2(250, 0), ImVec2(FLT_MAX, FLT_MAX));
	ImGui::SetNextWindowBgAlpha(gameState == GAMESTATE_CHARSELECT || gameState == GAMESTATE_INGAME ? .85f : .35f); // Transparent background
	if (ImGui::Begin("AutoLogin Status", p_open, (corner != -1 ? ImGuiWindowFlags_NoMove : 0) | ImGuiWindowFlags_NoBringToFrontOnFocus  | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav))
	{
		ImGui::PushFont(imgui::LargeTextFont);
		ImGui::TextColored(ImColor(52, 152, 219), "AutoLogin Status");
		ImGui::PopFont();
		ImGui::Separator();

		bool bAutoLoginEnabled = !Login::paused();
		bool bAutoLoginRunning = Login::has_entry();

		if (bAutoLoginRunning)
		{
			ImGui::Text("AutoLogin is");
			ImGui::SameLine(0, 4.0f);
			if (bAutoLoginEnabled)
				ImGui::TextColored(ImColor(0, 255, 0), "running");
			else
				ImGui::TextColored(ImColor(255, 255, 0), "paused");

			DisplayProfileInfo(Login::get_record(), false);

			if (!Login::get_record() || Login::get_record()->accountPassword.empty() && Login::last_state() == LoginState::Connect)
			{
				float green = (50 - abs(50 - (ImGui::GetFrameCount() % 100))) / 100.0f;

				ImGui::TextColored(ImVec4(1.0f, green, 0.0f, 1.0f), "Missing Password (login manually to fix)");
			}

			if (bAutoLoginEnabled)
			{
				if (ImGui::Button(ICON_MD_PAUSE " Pause", ImVec2(85.0f, 0.0f)))
					Login::dispatch(PauseLogin());
			}
			else
			{
				if (ImGui::Button(ICON_MD_PLAY_ARROW " Resume", ImVec2(85.0f, 0.0f)))
					Login::dispatch(UnpauseLogin());
			}

			ImGui::SameLine();

			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.f, 0.6f, 0.6f));
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.f, 0.7f, 0.7f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.f, 0.8f, 0.8f));

			if (ImGui::Button(ICON_MD_CANCEL " Cancel", ImVec2(85.0f, 0.0f)))
				Login::dispatch(StopLogin());

			ImGui::PopStyleColor(3);
		}
		else
		{
			ImGui::Text("AutoLogin is");
			ImGui::SameLine(0, 4.0f);
			ImGui::TextColored(ImColor(255, 0, 0), "inactive");

			DisplayProfileInfo(Login::get_current_record(), true);

			if (ImGui::Button("Select Profile"))
			{
				ImGui::OpenPopup("ProfileSelector");
			}

			ImGui::SameLine();

			if (ImGui::Button("Select Character"))
			{
				ImGui::OpenPopup("CharacterSelector");
			}

			ImGui::SetNextWindowSizeConstraints(ImVec2(120, 0), ImVec2(FLT_MAX, FLT_MAX));
			if (ImGui::BeginPopup("ProfileSelector"))
			{
				ShowProfilesMenu(false);

				ImGui::EndPopup();
			}

			ImGui::SetNextWindowSizeConstraints(ImVec2(120, 0), ImVec2(FLT_MAX, FLT_MAX));
			if (ImGui::BeginPopup("CharacterSelector"))
			{
				ShowCharactersMenu();

				ImGui::EndPopup();
			}
		}

		switch (Login::last_state())
		{
		case LoginState::Connect:
		case LoginState::ConnectConfirm:
			if (Login::m_settings.ConnectRetries > 0 && Login::retries() > 0)
			{
				ImGui::Text("Attempts: %d/%d", Login::retries(), Login::m_settings.ConnectRetries);
			}
			break;

		case LoginState::InGameCamping:
			if (pEverQuestInfo->ExitCounter != 0 && Login::get_record())
			{
				int counter = static_cast<int>(pEverQuestInfo->ExitCounter - EQGetTime());
				if (counter > 0)
				{
					std::chrono::milliseconds ms{ counter };

					ImGui::Text("Waiting to camp in %d seconds...", std::chrono::duration_cast<std::chrono::seconds>(ms).count());
				}
			}
			break;

		default: break;
		}

		ImGui::Spacing();

		if (ImGui::CollapsingHeader("Settings"))
		{
			ImGui::Checkbox("Kick Active Character", &Login::m_settings.KickActiveCharacter);
			ImGui::Checkbox("End After Character Select", &Login::m_settings.EndAfterSelect);

			ImGui::SetNextItemWidth(100.f);
			if (InputInt("Connect Retries", &Login::m_settings.ConnectRetries))
			{
				login::db::WriteSetting("login_connect_retries", std::to_string(Login::m_settings.ConnectRetries), "Number of times to attempt to reconnect, 0 for infinite");
			}

			ImGui::Separator();
			ImGui::Text("State Variables:");
			ImGui::Text("Delay Time: %llu", Login::delay_time() > MQGetTickCount64() ? Login::delay_time() - MQGetTickCount64() : 0ULL);
			ImGui::Text("Last Account: %s", Login::last_account().c_str());
			ImGui::Text("Last State:"); ImGui::SameLine();
			switch (Login::last_state())
			{
				case LoginState::SplashScreen: ImGui::Text("SplashScreen"); break;
				case LoginState::Connect: ImGui::Text("Connect"); break;
				case LoginState::ConnectConfirm: ImGui::Text("ConnectConfirm"); break;
				case LoginState::ServerSelect: ImGui::Text("ServerSelect"); break;
				case LoginState::ServerSelectConfirm: ImGui::Text("ServerSelectConfirm"); break;
				case LoginState::ServerSelectKick: ImGui::Text("ServerSelectKick"); break;
				case LoginState::ServerSelectDown: ImGui::Text("ServerSelectDown"); break;
				case LoginState::CharacterSelect: ImGui::Text("CharacterSelect"); break;
				case LoginState::InGame: ImGui::Text("InGame"); break;
				case LoginState::InGameCamping: ImGui::Text("InGameCamping"); break;
				default: ImGui::Text(""); break;
			}

			if (Login::current_window() != nullptr && Login::current_window()->GetXMLData() != nullptr)
			{
				ImGui::Text("Window: %s", Login::current_window()->GetXMLData()->Name.c_str());
			}

			ImGui::Separator();
			ImGui::Checkbox("Enable Debug Logging", &AUTOLOGIN_DBG);
		}

		if (ImGui::BeginPopupContextWindow())
		{
			ImGui::MenuItem("Show Debug Info", nullptr, &s_showOverlayDebugInfo);
			ImGui::MenuItem("Show Server List", nullptr, &s_showServerList);
			ImGui::Separator();
			if (p_open && ImGui::MenuItem("Close")) *p_open = false;
			ImGui::EndPopup();
		}
	}
	ImGui::End();
}

static void ShowServerList(bool* p_open)
{
	if (!g_pLoginClient )
		return;

	if (ImGui::Begin("Server List", p_open, 0))
	{
		auto& serverList = g_pLoginClient->ServerList;

		if (ImGui::BeginTable("##ServerList", 7, ImGuiTableFlags_ScrollY | ImGuiTableFlags_Resizable))
		{
			ImGui::TableSetupColumn("Name");
			ImGui::TableSetupColumn("Flags");
			ImGui::TableSetupColumn("RuleSet");
			ImGui::TableSetupColumn("Desc");
			ImGui::TableSetupColumn("Status");
			ImGui::TableSetupColumn("Expansion");
			ImGui::TableSetupColumn("TrueBox");
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableHeadersRow();

			for (EQLS::EQClientServerData* server : serverList)
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn();
				ImGui::Text("%s", server->ServerName.c_str());

				ImGui::TableNextColumn();
				ImGui::Text("%08x", server->Flags);

				ImGui::TableNextColumn();
				ImGui::Text("%s", server->RuleSet.c_str());

				ImGui::TableNextColumn();
				ImGui::Text("%s", server->Description.c_str());

				ImGui::TableNextColumn();
				ImGui::Text("%08x", server->StatusFlags);

				ImGui::TableNextColumn();
				ImGui::Text("%s", server->Expansion > 0 && server->Expansion <= NUM_EXPANSIONS ? szExpansions[server->Expansion - 1] : "");

				ImGui::TableNextColumn();
				if (server->TrueBoxStatus == 0)
					ImGui::TextUnformatted("No");
				else if (server->TrueBoxStatus == 1)
					ImGui::TextUnformatted("Yes");
				else if (server->TrueBoxStatus >= 2)
					ImGui::Text("Relaxed (%d)", server->TrueBoxStatus);
			}

			ImGui::EndTable();
		}
	}

	ImGui::End();
}

PLUGIN_API void OnUpdateImGui()
{
	int gameState = GetGameState();

	// Only show autologin overlay during character select or login
	if (gameState == GAMESTATE_CHARSELECT || gameState == GAMESTATE_PRECHARSELECT
		|| (gameState == GAMESTATE_INGAME && Login::get_record() != nullptr))
	{
		ShowAutoLoginOverlay(&s_showAutoLoginOverlay);
	}

	if (gameState == GAMESTATE_PRECHARSELECT && s_showServerList)
	{
		ShowServerList(&s_showServerList);
	}
}

PLUGIN_API void OnCleanUI()
{
	Login::clear_current_window();
}
