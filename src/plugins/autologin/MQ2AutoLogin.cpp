/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
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

#include "login/Login.h"
#include "MQ2AutoLogin.h"

#include <imgui.h>
#include <imgui_stdlib.h>
#include <imgui_internal.h>
#include "imgui/ImGuiUtils.h"

#include <map>
#include <TlHelp32.h>
#pragma comment(lib, "Crypt32.lib")

#include <filesystem>

namespace fs = std::filesystem;

PLUGIN_VERSION(4.0);

PreSetup("MQ2AutoLogin");

constexpr int STEP_DELAY = 1000;

fs::path CustomIni;
uint64_t ReenableTime = 0;
postoffice::DropboxAPI s_autologinDropbox;

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
		Level
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
	}

	virtual bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override
	{
		MQTypeMember* pMember = FindMember(Member);
		if (!pMember)
			return false;

		std::shared_ptr<ProfileRecord> record = Login::get_last_record();
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
		}

		return false;
	}

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		std::shared_ptr<ProfileRecord> record = Login::get_last_record();
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

// Notify on load/unload _only_ happens with the profile method, so we can reuse that proto
// This can be revisited later when we think a little bit about autologin
void NotifyCharacterLoad(const char* Profile, const char* Account, const char* Server, const char* Character)
{
	proto::login::ProfileMethod profile;
	profile.set_profile(Profile);
	profile.set_account(Account);
	proto::login::LoginTarget& target = *profile.mutable_target();
	target.set_server(Server);
	target.set_character(Character);

	Post(proto::login::ProfileLoaded, profile);
}

void NotifyCharacterUnload(const char* Profile, const char* Account, const char* Server, const char* Character)
{
	proto::login::ProfileMethod profile;
	profile.set_profile(Profile);
	profile.set_account(Account);
	proto::login::LoginTarget& target = *profile.mutable_target();
	target.set_server(Server);
	target.set_character(Character);

	Post(proto::login::ProfileUnloaded, profile);
}

void NotifyCharacterUpdate(int Class, int Level)
{
	proto::login::CharacterInfoMissive info;
	info.set_class_(Class);
	info.set_level(Level);

	Post(proto::login::ProfileCharInfo, info);
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

void PerformSwitch(const std::string& ServerName, const std::string& CharacterName)
{
	NotifyCharacterUnload(Login::profile(), Login::account(), Login::server(), Login::character());

	if (GetGameState() == GAMESTATE_INGAME)
	{
		if (pLocalPlayer != nullptr && pLocalPlayer->StandState == STANDSTATE_FEIGN)
		{
			// using DoMappable here doesn't create enough of a delay for camp to work
			EzCommand("/stand");
		}

		EzCommand("/camp fast");
	}

	Login::dispatch(SetLoginInformation(ServerName, CharacterName));

	NotifyCharacterLoad(Login::profile(), Login::account(), Login::server(), Login::character());
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

	// this is just a validity check, that's the only reason we have that set of server names
	if (GetServerIDFromServerName(szServer) == ServerID::Invalid && GetPrivateProfileString("Servers", szServer, "", INIFileName).empty())
	{
		WriteChatf("Invalid server name \ag%s\ax.  Valid server names are:", szServer);

		std::vector<std::string_view> server_names;
		std::transform(std::begin(eqlib::ServerIDArray), std::end(eqlib::ServerIDArray),
			std::back_inserter(server_names), [](const ServerID id) { return GetServerNameFromServerID(id); });
		std::vector<std::string> custom_server_names = GetPrivateProfileKeys("Servers", INIFileName);

		server_names.insert(server_names.end(), custom_server_names.cbegin(), custom_server_names.cend());
		WriteChatColor(join(server_names, ", ").c_str());
	}
	else if (GetGameState() == GAMESTATE_INGAME && pChar
		&& ci_equals(GetServerShortName(), szServer)
		&& ci_equals(pChar->DisplayedName, szCharacter))
	{
		WriteChatf("\ayYou're already logged into '%s' on '%s'\ax", szCharacter, szServer);
	}
	else
	{
		PerformSwitch(szServer, szCharacter);
		WriteChatf("Switching to \ag%s\ax on server \ag%s\ax.", szCharacter, szServer);
	}
}

void Cmd_SwitchCharacter(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine[0])
	{
		WriteChatf("\ayUsage:\ax /switchchar <name>");
		return;
	}

	char szArg1[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);

	if (GetGameState() == GAMESTATE_INGAME && pChar && ci_equals(pChar->DisplayedName, szArg1))
	{
		WriteChatf("\ayYou're already logged onto '%s'\ax", szArg1);
	}
	else
	{
		PerformSwitch(GetServerShortName(), szArg1);
		WriteChatf("Switch to \ag%s\ax is now active and will commence at character select.", szArg1);
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
		ReenableTime = MQGetTickCount64() + n;
	}

	if (ReenableTime)
		ReenableTime += 30000; // add 30 seconds for camp time

	if (GetGameState() == GAMESTATE_INGAME && pLocalPlayer && GetServerShortName()[0] != 0)
	{
		PerformSwitch(GetServerShortName(), pLocalPlayer->DisplayedName);
		// TODO:  After std::chrono change, update this to actual time.  It will currently show whatever multiple arguments the user typed in.
		WriteChatf("Relog into \ag%s\ax on server \ag%s\ax will activate after %s.",
			pLocalPlayer->DisplayedName, GetServerShortName(), szLine);
	}
	else
	{
		WriteChatf("\arError:\ax /relog could not get your server or character name.");
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
		record = ProfileRecord::FromINI(
			record.profileName,
			fmt::format("{}:{}_Blob", record.serverName, record.characterName),
			INIFileName);

		LoginProfile(
			record.profileName.c_str(),
			record.serverName.c_str(),
			record.characterName.c_str());
	}
	else if (!record.serverName.empty() && !record.accountName.empty() && !record.accountPassword.empty())
	{
		if (record.characterName.empty())
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
		// we have a server and a character, we need to find the first entry in the ini where these match (regardless of profile)
		char buff[MAX_STRING] = { 0 };
		int buff_size = GetPrivateProfileSectionNames(buff, MAX_STRING, INIFileName);
		std::string buff_str = std::string(buff, buff_size);

		auto sections = split(buff_str, '\0');

		for (const auto& section : sections)
		{
			auto blobKey = fmt::format("{}:{}_Blob", record.serverName, record.characterName);
			std::string blob = GetPrivateProfileString(section.c_str(), blobKey, "", INIFileName);

			if (!blob.empty())
			{
				record = ProfileRecord::FromINI(section.c_str(), blobKey, INIFileName);
				break;
			}
		}

		if (!record.profileName.empty())
			LoginProfile(
				record.profileName.c_str(),
				record.serverName.c_str(),
				record.characterName.c_str());
		else
			WriteChatf("Could not find %s:%s in your autologin ini", record.serverName.c_str(), record.characterName.c_str());
	}
	else
	{
		WriteChatf("\ayUsage:\ax /loginchar [profile_server:character|server:character|server^login^character^password|server^login^password]");
	}
}

DETOUR_TRAMPOLINE_DEF(DWORD WINAPI, GetPrivateProfileStringA_Trampoline, (LPCSTR, LPCSTR, LPCSTR, LPSTR, DWORD, LPCSTR))

void SetupCustomIni()
{
	if (!CustomIni.empty())
		return;

	if (const char* pLogin = GetLoginName())
	{
		char CustomPath[MAX_STRING] = { 0 };
		GetPrivateProfileStringA_Trampoline(pLogin, "CustomClientIni", nullptr, CustomPath, MAX_STRING, INIFileName);

		// If a relative path is specified, need to prepend it with current path, which is the EQ directory
		CustomIni = fs::path{ CustomPath };
		if (CustomIni.is_relative())
			CustomIni = fs::current_path() / CustomIni;
	}
}

DWORD WINAPI GetPrivateProfileStringA_Detour(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpDefault, LPSTR lpReturnedString, DWORD nSize, LPCSTR lpFileName)
{
	if (lpFileName)
	{
		SetupCustomIni();

		if (!CustomIni.empty() && ci_find_substr(lpFileName, "eqclient.ini") != -1)
		{
			return GetPrivateProfileStringA_Trampoline(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, CustomIni.string().c_str());
		}
	}

	return GetPrivateProfileStringA_Trampoline(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName);
}

DETOUR_TRAMPOLINE_DEF(BOOL WINAPI, WritePrivateProfileStringA_Trampoline, (LPCSTR, LPCSTR, LPCSTR, LPCSTR))
BOOL WINAPI WritePrivateProfileStringA_Detour(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpString, LPCSTR lpFileName)
{
	if (lpFileName)
	{
		SetupCustomIni();

		if (!CustomIni.empty() && ci_find_substr(lpFileName, "eqclient.ini") != -1)
		{
			return WritePrivateProfileStringA_Trampoline(lpAppName, lpKeyName, lpString, CustomIni.string().c_str());
		}
	}

	return WritePrivateProfileStringA_Trampoline(lpAppName, lpKeyName, lpString, lpFileName);
}

DETOUR_TRAMPOLINE_DEF(UINT WINAPI, GetPrivateProfileIntA_Tramp, (LPCSTR, LPCSTR, INT, LPCSTR))
UINT WINAPI GetPrivateProfileIntA_Detour(LPCSTR lpAppName, LPCSTR lpKeyName, INT nDefault, LPCSTR lpFileName)
{
	if (lpFileName)
	{
		SetupCustomIni();

		if (!CustomIni.empty() && ci_find_substr(lpFileName, "eqclient.ini") != -1)
		{
			return GetPrivateProfileIntA_Tramp(lpAppName, lpKeyName, nDefault, CustomIni.string().c_str());
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
		}
	}
}

void ReadINI()
{
	std::string path = GetPrivateProfileString("Settings", "IniLocation", "", INIFileName);
	if (!path.empty())
	{
		strcpy_s(INIFileName, path.c_str());
	}

	AUTOLOGIN_DBG = GetPrivateProfileBool("Settings", "Debug", AUTOLOGIN_DBG, INIFileName);

	Login::m_settings.NotifyOnServerUp = static_cast<Login::Settings::ServerUpNotification>(GetPrivateProfileInt("Settings", "NotifyOnServerUp", 0, INIFileName));
	Login::m_settings.KickActiveCharacter = GetPrivateProfileBool("Settings", "KickActiveCharacter", true, INIFileName);
	Login::m_settings.EndAfterSelect = GetPrivateProfileBool("Settings", "EndAfterCharSelect", false, INIFileName);
	Login::m_settings.CharSelectDelay = GetPrivateProfileInt("Settings", "CharSelectDelay", 3, INIFileName);
	Login::m_settings.ConnectRetries = GetPrivateProfileInt("Settings", "ConnectRetries", 0, INIFileName);

	if (gbWriteAllConfig)
	{
		WritePrivateProfileInt("Settings", "NotifyOnServerUp", static_cast<int>(Login::m_settings.NotifyOnServerUp), INIFileName);
		WritePrivateProfileBool("Settings", "KickActiveCharacter", Login::m_settings.KickActiveCharacter, INIFileName);
		WritePrivateProfileBool("Settings", "EndAfterSelect", Login::m_settings.EndAfterSelect, INIFileName);
		WritePrivateProfileInt("Settings", "CharSelectDelay", Login::m_settings.CharSelectDelay, INIFileName);
		WritePrivateProfileInt("Settings", "ConnectRetries", Login::m_settings.ConnectRetries, INIFileName);
	}

	bool bUseMQ2Login = GetPrivateProfileBool("Settings", "UseMQ2Login", false, INIFileName);
	bool bUseStationNamesInsteadOfSessions = GetPrivateProfileBool("Settings", "UseStationNamesInsteadOfSessions", false, INIFileName);
	if (bUseMQ2Login)
		Login::m_settings.LoginType = Login::Settings::Type::Profile;
	else if (bUseStationNamesInsteadOfSessions)
		Login::m_settings.LoginType = Login::Settings::Type::StationNames;
	else
		Login::m_settings.LoginType = Login::Settings::Type::Sessions;
}

void LoginReset()
{
	AutoLoginDebug("LoginReset()");
	ReadINI();
}

PLUGIN_API void InitializePlugin()
{
	pAutoLoginType = new MQ2AutoLoginType;
	pLoginProfileType = new LoginProfileType;
	AddMQ2Data("AutoLogin", MQ2AutoLoginType::dataAutoLogin);

	Login::set_initial_state();
	ReadINI();

	AddCommand("/switchserver", Cmd_SwitchServer);
	AddCommand("/switchcharacter", Cmd_SwitchCharacter);
	AddCommand("/relog", Cmd_Relog, false, true, true);
	AddCommand("/loginchar", Cmd_Loginchar);

	if (GetPrivateProfileBool("Settings", "EnableCustomClientIni", false, INIFileName))
	{
		uintptr_t pfnGetPrivateProfileIntA = (uintptr_t) & ::GetPrivateProfileIntA;
		EzDetour(pfnGetPrivateProfileIntA, GetPrivateProfileIntA_Detour, GetPrivateProfileIntA_Tramp);

		uintptr_t pfnGetPrivateProfileStringA = (uintptr_t) & ::GetPrivateProfileStringA;
		EzDetour(pfnGetPrivateProfileStringA, GetPrivateProfileStringA_Detour, GetPrivateProfileStringA_Trampoline);

		uintptr_t pfnWritePrivateProfileStringA = (uintptr_t) & ::WritePrivateProfileStringA;
		EzDetour(pfnWritePrivateProfileStringA, WritePrivateProfileStringA_Detour, WritePrivateProfileStringA_Trampoline);

		if (Login::m_settings.LoginType == Login::Settings::Type::StationNames)
		{
			SetupCustomIni();
		}
	}

	ReenableTime = MQGetTickCount64() + STEP_DELAY;

	s_autologinDropbox = postoffice::AddActor("autologin",
		[](const std::shared_ptr<postoffice::Message>& message)
		{
			// autologin doesn't actually take message inputs yet...
		});
}

PLUGIN_API void ShutdownPlugin()
{
	NotifyCharacterUnload(Login::profile(), Login::account(), Login::server(), Login::character());

	RemoveCommand("/switchserver");
	RemoveCommand("/switchcharacter");
	RemoveCommand("/relog");
	RemoveCommand("/loginchar");

	uintptr_t pfnGetPrivateProfileIntA = (uintptr_t) & ::GetPrivateProfileIntA;
	RemoveDetour(pfnGetPrivateProfileIntA);

	uintptr_t pfnGetPrivateProfileStringA = (uintptr_t) & ::GetPrivateProfileStringA;
	RemoveDetour(pfnGetPrivateProfileStringA);

	uintptr_t pfnWritePrivateProfileStringA = (uintptr_t) & ::WritePrivateProfileStringA;
	RemoveDetour(pfnWritePrivateProfileStringA);

	LoginReset();
	RemoveMQ2Data("AutoLogin");
	delete pAutoLoginType;
	delete pLoginProfileType;

	s_autologinDropbox.Remove();
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
		NotifyCharacterUpdate(s_lastCharacterClass, s_lastCharacterLevel);
	}

	if (gbInForeground && GetAsyncKeyState(VK_HOME) & 1)
		Login::dispatch(UnpauseLogin(true));
	else if (gbInForeground && GetAsyncKeyState(VK_END) & 1)
		Login::dispatch(PauseLogin(true));
	else if (GetGameState() == GAMESTATE_INGAME && MQGetTickCount64() > ReenableTime)
	{
		Login::dispatch(LoginStateSensor(LoginState::InGame, nullptr));
		ReenableTime = MQGetTickCount64() + STEP_DELAY;
	}
	else if (GetGameState() == GAMESTATE_CHARSELECT && MQGetTickCount64() > ReenableTime)
	{
		auto pWnd = GetWindow<CSidlScreenWnd>("ConfirmationDialogBox");
		if (pWnd != nullptr && pWnd->IsVisible() == 1)
		{
			auto pStmlWnd = GetChildWindow<CStmlWnd>(pWnd, "cd_textoutput");

			if (pStmlWnd && GetSTMLText(pStmlWnd).find("Do you accept these rules?") != CXStr::npos)
			{
				if (auto pYes = GetChildWindow<CButtonWnd>(pWnd, "cd_yes_button"))
					SendWndNotification(pYes, pYes, XWM_LCLICK);
			}
		}
		else if (CXWnd* pWnd = GetWindow("CLW_CharactersScreen"))
			Login::dispatch(LoginStateSensor(LoginState::CharacterSelect, pWnd));

		ReenableTime = MQGetTickCount64() + STEP_DELAY;
	}
	else if (GetGameState() == GAMESTATE_PRECHARSELECT && g_pLoginClient && MQGetTickCount64() > ReenableTime)
	{
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

		ReenableTime = MQGetTickCount64() + STEP_DELAY;
	}
}

static bool bShowAutoLoginOverlay = true;
static bool bShowOverlayDebugInfo = false;

template <typename T>
static bool RadioButton(const char* label, T* v, T v_button)
{
	const bool pressed = ImGui::RadioButton(label, *v == v_button);
	if (pressed)
		*v = v_button;
	return pressed;
}

static bool InputInt(const char* label, int* v, int step = 1, int step_fast = 10, ImGuiInputTextFlags flags = 0)
{
    return ImGui::InputScalar(label, ImGuiDataType_U32, (void*)v, (void*)(step>0 ? &step : NULL), (void*)(step_fast>0 ? &step_fast : NULL), "%d", flags);
}


static void ShowAutoLoginOverlay(bool* p_open)
{
	const float DISTANCE = 10.0f;

	int gameState = GetGameState();
	int corner = (gameState == GAMESTATE_CHARSELECT ? 1 : 0); // 0 = top left, 1 = top right, 2 = bottom left, 3 = bottom right
	ImGuiIO& io = ImGui::GetIO();

	if (corner != -1)
	{
		ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImVec2 window_pos = ImVec2((corner & 1) ? (viewport->Pos.x + viewport->Size.x - DISTANCE) : (viewport->Pos.x + DISTANCE), (corner & 2) ? (viewport->Pos.y + viewport->Size.y - DISTANCE) : (viewport->Pos.y + DISTANCE));
		ImVec2 window_pos_pivot = ImVec2((corner & 1) ? 1.0f : 0.0f, (corner & 2) ? 1.0f : 0.0f);
		ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always, window_pos_pivot);
		ImGui::SetNextWindowViewport(viewport->ID);
	}
	ImGui::SetNextWindowBgAlpha(gameState == GAMESTATE_CHARSELECT ? .85f : .35f); // Transparent background
	if (ImGui::Begin("AutoLogin Status", p_open, (corner != -1 ? ImGuiWindowFlags_NoMove : 0) | ImGuiWindowFlags_NoBringToFrontOnFocus  | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav))
	{
		ImGui::PushFont(imgui::LargeTextFont);
		ImGui::TextColored(ImColor(52, 152, 219), "AutoLogin Status");
		ImGui::PopFont();
		ImGui::Separator();

		ImGui::Text("Login Method:");
		ImGui::SameLine(0, 4.0f);
		if (Login::m_settings.LoginType == Login::Settings::Type::Profile)
			ImGui::Text("Login Profiles");
		else if (Login::m_settings.LoginType == Login::Settings::Type::StationNames)
			ImGui::Text("Station Names");
		else if (Login::m_settings.LoginType == Login::Settings::Type::Sessions)
			ImGui::Text("Sessions");

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

			ImGui::Text("Server: %s", Login::server());
			ImGui::Text("Character: %s", Login::character());

			if (Login::m_settings.LoginType == Login::Settings::Type::Profile)
				ImGui::Text("Profile: %s", Login::profile());

			if (strlen(Login::hotkey()) > 0)
				ImGui::Text("HotKey: %s", Login::hotkey());

			if (bAutoLoginEnabled)
			{
				if (ImGui::Button("Pause"))
					Login::dispatch(PauseLogin());
			}
			else
			{
				if (ImGui::Button("Resume"))
					Login::dispatch(UnpauseLogin());
			}

			ImGui::SameLine();
			if (ImGui::Button("Cancel"))
				Login::dispatch(StopLogin());
		}
		else
		{
			ImGui::Text("AutoLogin is");
			ImGui::SameLine(0, 4.0f);
			ImGui::TextColored(ImColor(255, 0, 0), "inactive");

			if (ImGui::Button("Select Profile"))
			{
				Login::profiles() = LoadAutoLoginProfiles(INIFileName);
				ImGui::OpenPopup("ProfileSelector");
			}

			if (ImGui::BeginPopup("ProfileSelector"))
			{
#if 0
				if (ImGui::MenuItem("Manual Login..."))
				{
					// TODO: Display a prompt to enter the info directly.
				}

				if (ImGui::MenuItem("Create New Profile..."))
				{
					// TODO: Display a prompt to create a new profile
				}

				ImGui::Separator();
#endif

				if (Login::profiles().empty())
				{
					ImGui::MenuItem("No Profiles (go create one!)", nullptr, false, false);
				}
				else
				{
					for (const ProfileGroup& pg : Login::profiles())
					{
						if (ImGui::BeginMenu(pg.profileName.c_str()))
						{
							for (const ProfileRecord& record : pg.records)
							{
								char buffer[256] = { 0 };
								record.FormatTo(buffer, 256);

								if (ImGui::MenuItem(buffer))
								{
									Login::m_settings.LoginType = Login::Settings::Type::Profile;
									Login::dispatch(SetLoginProfile(record));
								}
							}

							ImGui::EndMenu();
						}
					}
				}


				ImGui::EndPopup();
			}
		}

		if (Login::m_settings.ConnectRetries > 0)
		{
			ImGui::Text("Retries: %d/%d", Login::retries(), Login::m_settings.ConnectRetries);
		}

		ImGui::Spacing();
		if (ImGui::CollapsingHeader("Settings"))
		{
			ImGui::Checkbox("Kick Active Character", &Login::m_settings.KickActiveCharacter);
			ImGui::Checkbox("End After Select", &Login::m_settings.EndAfterSelect);
			InputInt("Connect Retries", &Login::m_settings.ConnectRetries);

			ImGui::Separator();
			ImGui::Text("Server Up Notification:");
			RadioButton("None", &Login::m_settings.NotifyOnServerUp, Login::Settings::ServerUpNotification::None); ImGui::SameLine();
			RadioButton("Email", &Login::m_settings.NotifyOnServerUp, Login::Settings::ServerUpNotification::Email); ImGui::SameLine();
			RadioButton("Beeps", &Login::m_settings.NotifyOnServerUp, Login::Settings::ServerUpNotification::Beeps);

			ImGui::Separator();
			ImGui::Text("State Variables:");
			ImGui::Text("Delay Time: %llu", Login::delay_time() > MQGetTickCount64() ? Login::delay_time() - MQGetTickCount64() : 0ULL);
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
				default: ImGui::Text(""); break;
			}
			if (Login::current_window() != nullptr && Login::current_window()->GetXMLData() != nullptr)
			{
				ImGui::Text("Current Window: %s", Login::current_window()->GetXMLData()->Name.c_str());
			}

			ImGui::Separator();
			ImGui::Checkbox("Enable Debug Logging", &AUTOLOGIN_DBG);
		}

		if (ImGui::BeginPopupContextWindow())
		{
			ImGui::MenuItem("Show Debug Info", nullptr, &bShowOverlayDebugInfo);
			ImGui::Separator();
			if (p_open && ImGui::MenuItem("Close")) *p_open = false;
			ImGui::EndPopup();
		}
	}
	ImGui::End();
}

PLUGIN_API void OnUpdateImGui()
{
	int gameState = GetGameState();

	// Only show autologin overlay during character select or login
	if (gameState == GAMESTATE_CHARSELECT || gameState == GAMESTATE_PRECHARSELECT)
	{
		ShowAutoLoginOverlay(&bShowAutoLoginOverlay);
	}
}