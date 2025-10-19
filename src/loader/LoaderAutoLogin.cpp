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

#include "loader/LoaderAutoLogin.h"
#include "loader/MacroQuest.h"
#include "loader/ImGui.h"
#include "loader/PostOffice.h"
#include "imgui/ImGuiFileDialog.h"
#include "imgui/imgui_internal.h"
#include "login/Login.h"
#include "login/AutoLogin.h"
#include "routing/PostOffice.h"

#include "fmt/format.h"
#include "fmt/os.h"
#include "spdlog/spdlog.h"
#include "wil/resource.h"

#include <filesystem>
#include <shellapi.h>

namespace fs = std::filesystem;
using namespace std::chrono_literals;

// set of loaded instances -- be careful to only read/write this from actors to ensure no race conditions
static postoffice::Dropbox s_dropbox;
static std::queue<std::pair<ProfileRecord, bool>> s_pendingLogins;
static auto s_lastLoginTime = std::chrono::steady_clock::now();

DWORD LaunchProcess(const std::string& process, const std::string& workingDir);

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

void Post(uint32_t pid, const proto::login::MessageId& messageId, const std::string& data)
{
	proto::login::LoginMessage message;
	message.set_id(messageId);
	message.set_payload(data);

	proto::routing::Address address;
	if (pid != 0)
		address.mutable_process()->set_pid(pid);
	address.set_mailbox("autologin:autologin");

	s_dropbox.Post(address, message);
}

void Post(const std::string& name, const proto::login::MessageId& messageId, const std::string& data)
{
	proto::login::LoginMessage message;
	message.set_id(messageId);
	message.set_payload(data);

	proto::routing::Address address;
	address.set_name(name);
	address.set_mailbox("autologin");

	s_dropbox.Post(address, message);
}

void AutoLoginRemoveProcess(uint32_t process_id)
{
	proto::login::StopInstanceMissive stop;
	stop.set_pid(process_id);

	Post("launcher", proto::login::ProfileUnloaded, stop);
}

void LoadCharacter(const ProfileRecord& profile, bool force)
{
	s_pendingLogins.emplace(profile, force);
}

void LoadProfileGroup(std::string_view group, bool force)
{
	for (auto& profile : login::db::GetActiveProfiles(group))
	{
		LoadCharacter(profile, force);
	}
}

void LaunchCleanSession()
{
	const auto eqgame = fs::path{ GetEQRoot() } / "eqgame.exe";
	if (std::error_code ec; !fs::exists(eqgame, ec))
	{
		SPDLOG_ERROR("eqgame.exe does not exist at {}: {}", GetEQRoot(), ec.message());
	}
	else
	{
		// create command line arguments
		std::string parameters = fmt::format(R"("{}" patchme)", eqgame.string());

		if (!LaunchProcess(parameters, GetEQRoot()))
		{
			SPDLOG_ERROR("{}",
				fmt::windows_error(GetLastError(), "Failed to launch eqgame.exe").what());
		}
	}
}

void ProcessPendingLogins()
{
	const auto now = std::chrono::steady_clock::now();
	if (!s_pendingLogins.empty() && now >= s_lastLoginTime)
	{
		auto& [record, force] = s_pendingLogins.front();
		int applyProfilePID = 0;

		if (!force)
		{
			// Check for duplicate session
			const auto& loadedInstances = GetLoadedInstances();

			auto iter = loadedInstances.find(LoginInstance::Key(record));
			if (iter != loadedInstances.end())
			{
				const LoginInstance& instance = iter->second;

				if (!record.profileName.empty() && instance.ProfileGroup != record.profileName)
				{
					applyProfilePID = instance.PID;
				}
			}
		}

		int delay = 0;

		if (applyProfilePID != 0)
		{
			proto::login::ApplyProfileMissive missive;
			missive.set_do_login(false);

			if (!record.profileName.empty())
			{
				proto::login::ProfileMethod& profile = *missive.mutable_profile();
				SerializeProfile(record, profile);
			}
			else
			{
				proto::login::DirectMethod& direct = *missive.mutable_direct();
				SerializeProfile(record, direct);
			}

			Post(applyProfilePID, mq::proto::login::ApplyProfile, missive);
		}
		else
		{
			StartInstance(record);

			static auto launchDelay = login::db::CacheSetting<int>("client_launch_delay", 3, GetIntFromString);
			delay = launchDelay.Read();
		}

		s_lastLoginTime = now + std::chrono::seconds(delay);
		s_pendingLogins.pop();
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

static void ReceivedMessageHandler(postoffice::MessagePtr message)
{
	proto::login::LoginMessage login_message;
	if (login_message.ParseFromString(message->payload()))
	{
		switch (login_message.id())  // NOLINT(clang-diagnostic-switch-enum)
		{
		case proto::login::MessageId::ProfileLoaded:
			// this message needs to come from the client after it has injected,
			// this acts as an ack or an update
			if (login_message.has_payload())
			{
				proto::login::NotifyLoadedMissive loaded;
				loaded.ParseFromString(login_message.payload());

				// only set the hotkey if the instance reports successfully loaded
				ProfileRecord profile = ParseProfileFromMessage(loaded);
				const LoginInstance* login = UpdateInstance(loaded.pid(), profile, true);

				if (login != nullptr && login->Hotkey)
				{
					SPDLOG_DEBUG("Register Global Hotkey: pid={} hotkey={}", login->PID, *login->Hotkey);

					RegisterGlobalHotkey(GetEQWindowHandleForProcessId(login->PID), *login->Hotkey);
				}
			}

			break;

		case proto::login::MessageId::ProfileUnloaded:
			if (login_message.has_payload())
			{
				proto::login::StopInstanceMissive stop;
				stop.ParseFromString(login_message.payload());

				RemoveInstance(stop.pid());
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
				LoadCharacter(profile, true);
			}

			break;

		default: break;
		}
	}
	else
	{
		SPDLOG_ERROR("Failed to parse login message from routed proto");
	}
}

void InitializeAutoLogin()
{
	s_dropbox = GetPostOffice().RegisterAddress("autologin", ReceivedMessageHandler);

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

	login::db::ShutdownDatabase();
}
