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

// ReSharper disable CppClangTidyClangDiagnosticFormatSecurity
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

namespace {
// set of loaded instances -- be careful to only read/write this from actors to ensure no race conditions
std::unordered_set<LoginInstance, LoginInstance> s_loadedInstances;
using LoginIterator = std::unordered_set<LoginInstance, LoginInstance>::const_iterator;

postoffice::Dropbox s_dropbox;
}

namespace internal_paths
{
	std::string s_autoLoginIni;
	std::string s_eqRoot;
}

// need a map of shortname to name (TODO: Use long names in the display)
// order matters here in the logic, so we need to make sure these are in the same order as MQ2
struct SClassInfo
{
	const char* Name;
	const char* UCShortName;
};

namespace {
SClassInfo s_classInfo[] =
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
}

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

namespace {
// TODO: hotkey/eqpath information is lost once we start the instance because the ack will unset them
LoginIterator StartOrUpdateInstance(const LoginInstance& instance_template, bool do_inject)
{
	auto login_it = s_loadedInstances.find(instance_template);
	if (login_it == s_loadedInstances.end() && IsEQGameProcessId(instance_template.PID))
	{
		// if we couldn't find by character and server, we need to check for PID
		// if we find it by PID, then we need to update the instance in the set
		login_it = std::find_if(s_loadedInstances.begin(), s_loadedInstances.end(),
			[pid = instance_template.PID](const LoginInstance& instance)
			{ return instance.PID == pid; });

		if (login_it != s_loadedInstances.end())
		{
			// found an instance with the same PID, update the entry to match the new loaded message
			// we need to drop this entry and add a new one, but keep the eq path from where it was launched
			auto eq_path = login_it->EQPath;
			login_it = s_loadedInstances.insert(s_loadedInstances.erase(login_it), instance_template);
			login_it->EQPath = eq_path;
		}
	}
	else if (login_it != s_loadedInstances.end())
	{
		// already mapped into our loaded instances
		if (IsEQGameProcessId(instance_template.PID) && instance_template.PID != login_it->PID)
		{
			// this is a failsafe case in case something external causes the eq instance
			// to reload, and we aren't catching that event
			login_it->PID = instance_template.PID;
		}

		if (!IsEQGameProcessId(login_it->PID))
		{
			// somehow we have a PID in our map that isn't EQ
			if (login_it->Hotkey) UnregisterGlobalHotkey(*login_it->Hotkey);
			s_loadedInstances.erase(login_it);
		}
		else
		{
			// trying to load an already loaded instance, update hotkey and profile
			// assume the provided hotkey is absolute truth to allow for clearing of hotkey
			if (login_it->Hotkey != instance_template.Hotkey)
			{
				if (login_it->Hotkey)
					UnregisterGlobalHotkey(*login_it->Hotkey);

				login_it->Hotkey = instance_template.Hotkey;

				if (login_it->Hotkey)
					RegisterGlobalHotkey(GetEQWindowHandleForProcessId(login_it->PID), *login_it->Hotkey);
			}

			if (login_it->ProfileGroup != instance_template.ProfileGroup)
				login_it->ProfileGroup = instance_template.ProfileGroup;

			// specifically do not update EQ path because we launched this instance with the existing value

			// reinject
			if (do_inject) Inject(login_it->PID);
		}
	}
	else
	{
		// character is not loaded, so load it -- we can assume that it's not already running (with MQ anyway)
		// because we got a list at startup of the current running instances
		ProfileRecord record;
		record.serverName = instance_template.Server;
		record.characterName = instance_template.Character;

		std::string eq_path;
		if (login::db::ReadAccount(record) && record.eqPath)
			eq_path = *record.eqPath;

		if (instance_template.EQPath)
			eq_path = *instance_template.EQPath;
		else if (instance_template.ProfileGroup)
			if (auto path =
				login::db::GetEQPath(
					*instance_template.ProfileGroup,
					instance_template.Server,
					instance_template.Character))
				eq_path = *path;

		if (!eq_path.empty())
		{
			SHELLEXECUTEINFOA sei;
			sei.cbSize = sizeof(SHELLEXECUTEINFOA);
			sei.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_WAITFORINPUTIDLE;
			sei.lpVerb = "open";
			sei.nShow = SW_SHOW;

			std::string arg;
			if (instance_template.ProfileGroup)
			{
				arg = fmt::format("{}_{}:{}",
					*instance_template.ProfileGroup,
					instance_template.Server,
					instance_template.Character);
			}
			else if (instance_template.AccountAndPassword)
			{
				if (instance_template.Server.empty())
				{
					arg = fmt::format("{}^{}",
						instance_template.AccountAndPassword->first,
						instance_template.AccountAndPassword->second);
				}
				else if (instance_template.Character.empty())
				{
					arg = fmt::format("{}^{}^{}",
						instance_template.Server,
						instance_template.AccountAndPassword->first,
						instance_template.AccountAndPassword->second);
				}
				else
				{
					arg = fmt::format("{}^{}^{}^{}",
						instance_template.Server,
						instance_template.AccountAndPassword->first,
						instance_template.Character,
						instance_template.AccountAndPassword->second);
				}
			}
			else
			{
				if (!record.accountPassword.empty())
				{
					// password was read successfully
					if (!instance_template.Character.empty())
					{
						arg = fmt::format("{}^{}^{}^{}",
							record.serverName, record.accountName,
							record.characterName, record.accountPassword);
					}
					else
					{
						arg = fmt::format("{}^{}^{}",
							record.serverName, record.accountName, record.accountPassword);
					}
				}
				else
				{
					arg = fmt::format("{}:{}", record.serverName, record.characterName);
				}
			}

			auto params = fmt::format("patchme /login:{}", arg);
			sei.lpParameters = params.c_str();
			sei.lpDirectory = eq_path.c_str();

			auto file = fmt::format("{}\\eqgame.exe", eq_path);
			sei.lpFile = file.c_str();

			if (ShellExecuteEx(&sei) && sei.hProcess != nullptr)
			{
				login_it = s_loadedInstances.insert(s_loadedInstances.end(), instance_template);
				login_it->PID = GetProcessId(sei.hProcess);
				login_it->EQPath = eq_path;
				if (do_inject) Inject(login_it->PID);
			}
			else
			{
				SPDLOG_ERROR("Failed to create new eqgame process");
			}
		}
		else
		{
			SPDLOG_ERROR("No eq_path found for {} : {} (profile group {})",
				instance_template.Server, instance_template.Character,
				instance_template.ProfileGroup ? *instance_template.ProfileGroup : "<None>");
		}
	}

	return login_it;
}
}

// This sends a message to self so that we ensure that all access of s_loadedInstances happens on the main thread
void LoadCharacter(const LoginInstance& instance_template)
{
	proto::login::StartInstanceMissive start;
	if (instance_template.ProfileGroup)
	{
		proto::login::ProfileMethod& method = *start.mutable_profile();
		method.set_profile(*instance_template.ProfileGroup);
		proto::login::LoginTarget& target = *method.mutable_target();
		target.set_server(instance_template.Server);
		target.set_character(instance_template.Character);
	}
	else if (instance_template.AccountAndPassword)
	{
		proto::login::DirectMethod& method = *start.mutable_direct();
		method.set_login(instance_template.AccountAndPassword->first);
		method.set_password(instance_template.AccountAndPassword->second);

		// server and character can technically be omitted here in this special case
		proto::login::LoginTarget& target = *method.mutable_target();
		if (!instance_template.Server.empty())
			target.set_server(instance_template.Server);
		if (!instance_template.Character.empty())
			target.set_character(instance_template.Character);
	}
	else
	{
		ProfileRecord profile;
		profile.serverName = instance_template.Server;
		profile.characterName = instance_template.Character;
		login::db::ReadAccount(profile);

		proto::login::DirectMethod& method = *start.mutable_direct();
		method.set_login(profile.accountName);
		method.set_password(profile.accountPassword);
		proto::login::LoginTarget& target = *method.mutable_target();
		target.set_server(instance_template.Server);
		target.set_character(instance_template.Character);
	}

	proto::login::LoginMessage message;
	message.set_id(proto::login::StartInstance);
	message.set_payload(start.SerializeAsString());

	proto::routing::Address address;
	address.set_name("launcher");
	address.set_mailbox("autologin");

	s_dropbox.Post(address, message);
}

void LoadProfileGroup(std::string_view group)
{
	// ReSharper disable once CppUseStructuredBinding
	for (const auto& profile : login::db::GetProfiles(group))
	{
		if (profile.checked)
		{
			LoginInstance instance;
			instance.ProfileGroup = group;
			instance.Server = profile.serverName;
			instance.Character = profile.characterName;
			if (!profile.hotkey.empty()) instance.Hotkey = profile.hotkey;

			LoadCharacter(instance);
		}
	}
}

void LaunchCleanSession()
{
	// Get path to the login server data file
	const fs::path eqls_player_data_ini = fs::path{ internal_paths::s_eqRoot } / "eqlsPlayerData.ini";

	// Get default username from eqlsPlayerData.ini
	std::string username = GetPrivateProfileString("PLAYER", "Username", "<>", eqls_player_data_ini.string());

	// create command line arguments
	std::string parameters = fmt::format("{}\\eqgame.exe patchme /login:{}", internal_paths::s_eqRoot, username);

	STARTUPINFOA si;
	si.cb = sizeof(STARTUPINFOA);
	si.wShowWindow = SW_SHOWNORMAL;
	si.dwFlags = STARTF_USESHOWWINDOW;

	wil::unique_process_information pi;
	CreateProcessA(nullptr, parameters.data(), nullptr, nullptr, FALSE, 0, nullptr, internal_paths::s_eqRoot.c_str(), &si, &pi);
}

void Import()
{
	// set the eq path
	if (!login::db::GetPathFromServerType(GetServerType()))
		login::db::CreateOrUpdateServerType(GetServerType(), GetPrivateProfileString("Profiles", "DefaultEQPath", "", internal_paths::s_autoLoginIni));

	if (const auto eq_path = login::db::GetPathFromServerType(GetServerType()))
		internal_paths::s_eqRoot = *eq_path;

	login::db::WriteProfileGroups(LoadAutoLoginProfiles(internal_paths::s_autoLoginIni, GetServerType()), internal_paths::s_eqRoot);
}

const char* GetEQRoot()
{
	return internal_paths::s_eqRoot.c_str();
}

namespace {

LoginInstance ParseInstanceFromMessage(const proto::login::StartInstanceMissive& start)
{
	LoginInstance instance;

	switch (start.method_case())  // NOLINT(clang-diagnostic-switch-enum)
	{
	case proto::login::StartInstanceMissive::MethodCase::kDirect:
		if (start.direct().has_target())
		{
			if (start.has_pid())
				instance.PID = start.pid();

			if (start.direct().target().has_server())
				instance.Server = start.direct().target().server();

			if (start.direct().target().has_character())
				instance.Character = start.direct().target().character();

			instance.AccountAndPassword = std::make_pair(
				start.direct().login(),
				start.direct().password()
			);

			if (start.direct().has_hotkey())
				instance.Hotkey = start.direct().hotkey();

			if (start.direct().has_eq_path())
				instance.EQPath = start.direct().eq_path();
		}
		break;

	case proto::login::StartInstanceMissive::MethodCase::kProfile:
		if (start.profile().has_target() && start.profile().target().has_character() && start.profile().target().has_server())
		{
			if (start.has_pid())
				instance.PID = start.pid();

			instance.ProfileGroup = start.profile().profile();
			instance.Server = start.profile().target().server();
			instance.Character = start.profile().target().character();

			// get the remaining data from the db for the profile
			ProfileRecord profile;
			profile.profileName = *instance.ProfileGroup;
			profile.serverName = instance.Server;
			profile.characterName = instance.Character;
			login::db::ReadProfile(profile);

			if (!profile.hotkey.empty()) instance.Hotkey = profile.hotkey;
			instance.EQPath = profile.eqPath;
		}
		break;

	default:
		break;
	}

	return instance;
}

void ReceivedMessageHandler(ProtoMessagePtr&& message)  // NOLINT(cppcoreguidelines-rvalue-reference-param-not-moved)
{
	// TODO: This needs to handle identify messages (to fill loaded instance set)
	switch (const auto login_message = message->Parse<proto::login::LoginMessage>(); login_message.id()) // NOLINT(clang-diagnostic-switch-enum)
	{
	case proto::login::MessageId::ProfileLoaded:
		// this message needs to come from the client after it has injected,
		// this acts as an ack or an update
		if (login_message.has_payload())
		{
			proto::login::StartInstanceMissive start;
			start.ParseFromString(login_message.payload());

			// only set the hotkey if the instance reports successfully loaded
			if (const auto login_it = StartOrUpdateInstance(ParseInstanceFromMessage(start), false); login_it != s_loadedInstances.end() && login_it->Hotkey)
				RegisterGlobalHotkey(GetEQWindowHandleForProcessId(login_it->PID), *login_it->Hotkey);
		}

		break;

	case proto::login::MessageId::ProfileUnloaded:
		if (login_message.has_payload())
		{
			proto::login::StopInstanceMissive stop;
			stop.ParseFromString(login_message.payload());
			if (const auto login_it = std::find_if(s_loadedInstances.begin(), s_loadedInstances.end(),
			                                       [pid = stop.pid()](const LoginInstance& instance) { return instance.PID == pid; }); login_it != s_loadedInstances.end())
			{
				if (login_it->Hotkey)
					UnregisterGlobalHotkey(*login_it->Hotkey);

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
			login::db::UpdatePersona(GetClassShortName(charinfo.class_()), profile);
		}

		break;

	case proto::login::MessageId::StartInstance:
		if (login_message.has_payload())
		{
			proto::login::StartInstanceMissive start;
			start.ParseFromString(login_message.payload());
			StartOrUpdateInstance(ParseInstanceFromMessage(start), true);
		}

		break;

	default:
		break;
	}
}
}

void InitializeAutoLogin()
{
	s_dropbox = postoffice::GetPostOffice().RegisterAddress("autologin", ReceivedMessageHandler);
	// TODO: build list of logged in instances from the list of registered clients in the post office
	// TODO: figure out how to determine hotkeys from that list

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

	// Initialize path to EQ
	if (const auto eq_path = login::db::GetPathFromServerType(GetServerType()))
		internal_paths::s_eqRoot = *eq_path;

	if (internal_paths::s_eqRoot.empty())
	{
		SPDLOG_ERROR("AutoLogin Error no EQ path specified for server type {}, AutoLogin will not work correctly.", GetServerType());
	}

	InitializeAutoLoginImGui();
}

void ShutdownAutoLogin()
{
	s_dropbox.Remove();

	ShutdownAutoLoginImGui();
}
