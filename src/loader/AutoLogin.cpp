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

#include "MacroQuest.h"
#include "AutoLogin.h"
#include "HotKeyControl.h"

#include "login/Login.h"
#include "routing/PostOffice.h"

#include "ImGui.h"

#include <shellapi.h>

#include <wil/resource.h>
#include <filesystem>
#include <spdlog/spdlog.h>

#include <fmt/format.h>

#include "imgui/ImGuiFileDialog.h"
#include "imgui_internal.h"

namespace fs = std::filesystem;

CHotKeyCtrl* s_hotKeyCtrl = nullptr;

// set of loaded instances -- be careful to only read/write this from actors to ensure no race conditions
static std::unordered_map<std::string, LoginInstance> s_loadedInstances;
static postoffice::Dropbox s_dropbox;

namespace internal_paths
{
	std::string s_autoLoginIni;
}

// need a map of shortname to name (TODO: Use long names in the display)
// order matters here in the logic, so we need to make sure these are in the same order as MQ2
struct SClassInfo
{
	const char* Name;
	const char* UCShortName;
};

static SClassInfo s_classInfo[] =
{
	{ "",             ""    },
	{ "Warrior",      "WAR" },
	{ "Cleric",       "CLR" },
	{ "Paladin",      "PAL" },
	{ "Ranger",       "RNG" },
	{ "Shadowknight", "SHD" },
	{ "Druid",        "DRU" },
	{ "Monk",         "MNK" },
	{ "Bard",         "BRD" },
	{ "Rogue",        "ROG" },
	{ "Shaman",       "SHM" },
	{ "Necromancer",  "NEC" },
	{ "Wizard",       "WIZ" },
	{ "Mage",         "MAG" },
	{ "Enchanter",    "ENC" },
	{ "Beastlord",    "BST" },
	{ "Berserker",    "BER" },
};

const char* GetClassShortName(const DWORD player_class)
{
	return s_classInfo[player_class].UCShortName;
}

void AutoLoginRemoveProcess(const DWORD process_id)
{
	proto::login::StopInstanceMissive stop;
	stop.set_pid(process_id);

	proto::login::LoginMessage message;
	message.set_id(proto::login::ProfileUnloaded);
	message.set_payload(stop.SerializeAsString());

	proto::routing::Address address;
	address.set_name("launcher");
	address.set_mailbox("autologin");

	s_dropbox.Post(address, message);
}

static const LoginInstance* StartOrUpdateInstance(const uint32_t pid, ProfileRecord& profile, bool do_update)
{
	auto login_it = s_loadedInstances.find(LoginInstance::Key(profile));
	if (login_it == s_loadedInstances.end() && IsEQGameProcessId(pid))
	{
		// if we couldn't find by character and server, we need to check for PID
		// if we find it by PID, then we need to update the instance in the set
		login_it = std::find_if(s_loadedInstances.begin(), s_loadedInstances.end(),
			[pid](const std::pair<std::string, LoginInstance>& instance)
			{ return instance.second.PID == pid; });

		if (login_it != s_loadedInstances.end())
		{
			// found an instance with the same PID, update the entry to match the new loaded message
			// the assumption here is that this message will necessarily come from the instance that
			// is actually loaded at that pid (like if someone relogged without MQ and then injected)
			login_it->second.Update(pid, profile);
		}
	}
	else if (login_it != s_loadedInstances.end())
	{
		// already mapped into our loaded instances
		if (IsEQGameProcessId(pid) && pid != login_it->second.PID)
		{
			// this is a failsafe case in case something external causes the eq instance
			// to reload, and we aren't catching that event
			login_it->second.PID = pid;
		}

		if (!IsEQGameProcessId(login_it->second.PID))
		{
			// somehow we have a PID in our map that isn't EQ
			if (login_it->second.Hotkey) UnregisterGlobalHotkey(*login_it->second.Hotkey);
			login_it = s_loadedInstances.erase(login_it);
		}
		else if (do_update)
		{
			login_it->second.Update(login_it->second.PID, profile);

			// reinject
			Inject(login_it->second.PID);
		}
		// else do nothing because we are just acknowledging a loaded instance
	}
	else
	{
		// character is not loaded, so load it -- we can assume that it's not already running (with MQ anyway)
		// because we got a list at startup of the current running instances
		if (!profile.eqPath)
			if (const auto path = login::db::GetEQPath(
				profile.profileName, profile.serverName, profile.characterName))
				profile.eqPath = *path;

		if (!profile.eqPath)
		{
			SPDLOG_ERROR("No eq_path found for {} : {} (profile group {})",
				profile.serverName, profile.characterName, profile.profileName);
		}
		else
		{
			std::string arg = profile.ToString();
			if (arg.empty())
			{
				SPDLOG_ERROR("Failed to generate profile string.");
			}
			else
			{
				const auto eqgame = fs::path{ *profile.eqPath } / "eqgame.exe";
				if (std::error_code ec; !fs::exists(eqgame, ec))
				{
					SPDLOG_ERROR("eqgame.exe does not exist at {} : {}", *profile.eqPath, ec.message());
				}
				else
				{
					std::string parameters = fmt::format(R"("{}" patchme /login:{})", eqgame.string(), arg);

					STARTUPINFOA si = { sizeof(STARTUPINFOA) };
					si.wShowWindow = SW_SHOWNORMAL;
					si.dwFlags = STARTF_USESHOWWINDOW;

					wil::unique_process_information pi;
					if (CreateProcessA(nullptr, parameters.data(), nullptr, nullptr, FALSE, 0, nullptr, profile.eqPath->c_str(), &si, &pi) && pi.hProcess != nullptr)
					{
						auto [it, _] = s_loadedInstances.emplace(
							LoginInstance::Key(profile),
							LoginInstance(pi.dwProcessId, profile));
						login_it = it;
						Inject(login_it->second.PID); // always inject when we load a new instance
					}
					else
					{
						SPDLOG_ERROR("Failed to create new eqgame process");
					}
				}
			}
		}
	}

	if (login_it != s_loadedInstances.end())
		return &login_it->second;

	return nullptr;
}

std::string LoginInstance::Key(std::string_view Server, std::string_view Character)
{
	return fmt::format("{}:{}", Server, Character);
}

std::string LoginInstance::Key(const ProfileRecord& profile)
{
	return Key(profile.serverName, profile.characterName);
}

void LoginInstance::Update(uint32_t pid, const ProfileRecord& profile)
{
	// update hotkey and profile group, but not path
	if (Hotkey != profile.hotkey)
	{
		if (Hotkey) UnregisterGlobalHotkey(*Hotkey);

		if (!profile.hotkey.empty())
		{
			Hotkey = profile.hotkey;
			RegisterGlobalHotkey(GetEQWindowHandleForProcessId(pid), *Hotkey);
		}
	}

	if (ProfileGroup != profile.profileName && !profile.profileName.empty())
	{
		ProfileGroup = profile.profileName;
	}
	else if (ProfileGroup && profile.profileName.empty())
	{
		ProfileGroup.reset();
	}
}

LoginInstance::LoginInstance(uint32_t pid, const ProfileRecord& profile)
	: PID(pid)
	, Server(profile.serverName)
	, Character(profile.characterName)
	, EQPath(*profile.eqPath)
	, ProfileGroup(profile.profileName)
{
	if (!profile.hotkey.empty()) Hotkey = profile.hotkey;
}

void LoadCharacter(ProfileRecord& profile)
{
	StartOrUpdateInstance(0, profile, true);
}

void LoadProfileGroup(std::string_view group)
{
	for (auto& profile : login::db::GetProfiles(group).vector())
	{
		if (profile.checked)
			LoadCharacter(profile);
	}
}

void LaunchCleanSession()
{
	const auto eqgame = fs::path{ GetEQRoot() } / "eqgame.exe";
	if (std::error_code ec; !fs::exists(eqgame, ec))
	{
		SPDLOG_ERROR("eqgame.exe does not exist at {} : {}", GetEQRoot(), ec.message());
	}
	else
	{
		// create command line arguments
		std::string parameters = fmt::format(R"("{}" patchme)", eqgame.string());

		STARTUPINFOA si = { sizeof(STARTUPINFOA) };
		si.wShowWindow = SW_SHOWNORMAL;
		si.dwFlags = STARTF_USESHOWWINDOW;

		wil::unique_process_information pi;
		if (CreateProcessA(nullptr, parameters.data(), nullptr, nullptr, FALSE, 0, nullptr, GetEQRoot().c_str(), &si, &pi) && pi.hProcess != nullptr)
		{
			Inject(pi.dwProcessId); // always inject when we load a new instance
		}
		else
		{
			SPDLOG_ERROR("Failed to create new eqgame process");
		}
	}
}

void Import()
{
	// set the eq path
	if (!login::db::GetPathFromServerType(GetServerType()))
		login::db::CreateOrUpdateServerType(GetServerType(), GetPrivateProfileString("Profiles", "DefaultEQPath", "", internal_paths::s_autoLoginIni));

	login::db::WriteProfileGroups(LoadAutoLoginProfiles(internal_paths::s_autoLoginIni, GetServerType()), GetEQRoot());
}

std::string GetEQRoot()
{
	static auto eq_path = login::db::Cache([]
		{ return login::db::GetPathFromServerType(GetServerType()); });

	if (eq_path.Read())
		return *eq_path.Updated();

	return "";
}

static ProfileRecord ParseProfileFromMessage(const proto::login::StartInstanceMissive& start)
{
	ProfileRecord profile;

	switch (start.method_case())
	{
	case proto::login::StartInstanceMissive::MethodCase::kDirect:
		if (start.direct().has_target())
		{
			if (start.direct().target().has_server())
				profile.serverName = start.direct().target().server();

			if (start.direct().target().has_character())
				profile.characterName = start.direct().target().character();

			profile.accountName = start.direct().login();
			profile.accountPassword = start.direct().password();

			if (start.direct().has_hotkey())
				profile.hotkey = start.direct().hotkey();

			if (start.direct().has_eq_path())
				profile.eqPath = start.direct().eq_path();
		}
		break;

	case proto::login::StartInstanceMissive::MethodCase::kProfile:
		if (start.profile().has_target() && start.profile().target().has_character() && start.profile().target().has_server())
		{
			profile.profileName = start.profile().profile();
			profile.serverName = start.profile().target().server();
			profile.characterName = start.profile().target().character();

			// get the remaining data from the db for the profile
			login::db::ReadProfile(profile);
		}
		break;

	default:
		break;
	}

	return profile;
}

static void ReceivedMessageHandler(ProtoMessagePtr&& message)
{
	const auto login_message = message->Parse<proto::login::LoginMessage>();
	switch (login_message.id())
	{
	case proto::login::MessageId::ProfileLoaded:
		// this message needs to come from the client after it has injected,
		// this acts as an ack or an update
		if (login_message.has_payload())
		{
			proto::login::StartInstanceMissive start;
			start.ParseFromString(login_message.payload());

			// only set the hotkey if the instance reports successfully loaded
			ProfileRecord profile = ParseProfileFromMessage(start);
			const auto login = StartOrUpdateInstance(
				start.has_pid() ? start.pid() : 0, profile, false);

			if (login != nullptr && login->Hotkey)
				RegisterGlobalHotkey(GetEQWindowHandleForProcessId(login->PID), *login->Hotkey);
		}

		break;

	case proto::login::MessageId::ProfileUnloaded:
		if (login_message.has_payload())
		{
			proto::login::StopInstanceMissive stop;
			stop.ParseFromString(login_message.payload());
			const auto login_it = std::find_if(s_loadedInstances.begin(), s_loadedInstances.end(),
				[pid = stop.pid()](const std::pair<std::string, LoginInstance>& instance)
				{ return instance.second.PID == pid; });

			if (login_it != s_loadedInstances.end())
			{
				if (login_it->second.Hotkey)
					UnregisterGlobalHotkey(*login_it->second.Hotkey);

				s_loadedInstances.erase(login_it);
			}
		}

		break;

	case proto::login::MessageId::ProfileCharInfo:
		if (login_message.has_payload())
		{
			proto::login::CharacterInfoMissive charinfo;
			charinfo.ParseFromString(login_message.payload());

			ProfileRecord profile;
			profile.serverName = charinfo.server();
			profile.characterName = charinfo.character();
			profile.characterClass = GetClassShortName(charinfo.class_());
			profile.characterLevel = static_cast<int>(charinfo.level());
			login::db::CreatePersona(profile);
		}

		break;

	case proto::login::MessageId::StartInstance:
		if (login_message.has_payload())
		{
			proto::login::StartInstanceMissive start;
			start.ParseFromString(login_message.payload());
			ProfileRecord profile = ParseProfileFromMessage(start);
			StartOrUpdateInstance(0, profile, true);
		}

		break;

	default:
		break;
	}
}

void InitializeAutoLogin()
{
	s_dropbox = postoffice::GetPostOffice().RegisterAddress("autologin", ReceivedMessageHandler);

	// Get path to mq2autologin.ini
	internal_paths::s_autoLoginIni = (fs::path{ internal_paths::Config }  / "MQ2AutoLogin.ini").string();
	if (!login::db::InitDatabase((fs::path(internal_paths::Config) / "login.db").string()))
	{
		SPDLOG_ERROR("Could not load autologin database, Autologin functionality will be disabled");
		return;
	}

	// test reading the password. if it's not correct, prompt to enter it
	if (login::db::ReadSetting("master_pass") && !login::db::ReadMasterPass())
		LauncherImGui::OpenWindow(&ShowPasswordWindow, "Enter Master Password");
	else if (const auto load_ini = login::db::ReadSetting("load_ini"); !load_ini || GetBoolFromString(*load_ini, false))
	{
		// load_ini implies a first load situation -- let's ensure we have a master pass or prompt for one
		// this will specifically happen if master_pass is not set, so prompt to enter one
		if (!login::db::ReadMasterPass())
			LauncherImGui::OpenWindow(&ShowPasswordWindow, "Enter Master Password");
		else
		{
			Import();
			login::db::WriteSetting("load_ini", "false", "Import data from autologin ini file one time");
		}
	}

	InitializeAutoLoginImGui();
}

void ShutdownAutoLogin()
{
	s_dropbox.Remove();

	ShutdownAutoLoginImGui();
}
