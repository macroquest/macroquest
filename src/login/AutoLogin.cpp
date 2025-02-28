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

#include "login/AutoLogin.h"
#include "login/Login.h"
#include "mq/base/Color.h"
#include "mq/base/String.h"

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "imgui/fonts/IconsMaterialDesign.h"

#include <fmt/format.h>
#include <fmt/os.h>
#include <spdlog/spdlog.h>
#include <wil/resource.h>

#include <shellapi.h>
#include <TlHelp32.h>

namespace fs = std::filesystem;

static std::unordered_map<std::string, LoginInstance> s_loadedInstances;

std::vector<ImGuiTableColumnSortSpecs> CharacterInfo::s_sortSpecs;
bool CharacterInfo::s_contextMenuDirty = false;

std::function<void(const std::string&, bool)> LoadAllStarredCallback;
std::function<void(const ProfileRecord&, bool)> LoadCharacterCallback;
std::function<void(uint32_t, const std::string&)> UnregisterGlobalHotkeyCallback;
std::function<void(uint32_t, const std::string&)> RegisterGlobalHotkeyCallback;
std::string EQPathErrorMessage;

const std::unordered_map<std::string, LoginInstance>& GetLoadedInstances()
{
	return s_loadedInstances;
}

const LoginInstance* GetAccountInstance(std::string_view accountName, std::string_view serverType)
{
	for (const auto& [_, instance] : s_loadedInstances)
	{
		if (mq::ci_equals(instance.Account, accountName) && mq::ci_equals(instance.ServerType, serverType))
			return &instance;

	}

	return nullptr;
}

static std::string GetEQGameProcessPath(uint32_t processId)
{
	wil::unique_process_handle hProcess{
		OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, processId)
	};

	if (hProcess)
	{
		char szProcessName[MAX_PATH];
		DWORD nameSize = MAX_PATH;

		if (::QueryFullProcessImageNameA(hProcess.get(), 0, szProcessName, &nameSize))
		{
			std::string fileName = szProcessName;

			// Extract the filename from the full path
			size_t pos = fileName.find_last_of("\\/");
			if (pos != std::string::npos)
			{
				fileName = fileName.substr(0, pos);
			}

			return fileName;
		}
	}

	return {};
}

static bool IsEQGameProcessId(DWORD processId)
{
	wil::unique_process_handle hProcess{
		OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, processId)
	};

	if (hProcess)
	{
		char szProcessName[MAX_PATH];
		DWORD nameSize = MAX_PATH;

		if (::QueryFullProcessImageNameA(hProcess.get(), 0, szProcessName, &nameSize))
		{
			std::string fileName = szProcessName;

			// Extract the filename from the full path
			size_t pos = fileName.find_last_of("\\/");
			if (pos != std::string::npos)
			{
				fileName = fileName.substr(pos + 1);
			}

			if (mq::ci_equals(fileName, "eqgame.exe"))
				return true;

			SPDLOG_DEBUG("Process id is not eq: {} name={}", processId, fileName);
		}
	}

	SPDLOG_DEBUG("Process id not found: {}", processId);
	return false;
}

#pragma region LoginInstance

const LoginInstance* UpdateInstance(const uint32_t pid, const ProfileRecord& profile, bool add /* = false */)
{
	auto login_it = s_loadedInstances.find(LoginInstance::Key(profile));
	if (login_it == s_loadedInstances.end() && IsEQGameProcessId(pid))
	{
		// if we couldn't find by character and server, we need to check for PID
		// if we find it by PID, then we need to update the instance in the set
		login_it = std::find_if(s_loadedInstances.begin(), s_loadedInstances.end(),
			[pid](const std::pair<std::string, LoginInstance>& instance)
			{ return instance.second.PID == pid; });

		std::string newKey = LoginInstance::Key(profile);

		if (login_it != s_loadedInstances.end())
		{
			if (newKey == login_it->first)
			{
				// found an instance with the same PID, update the entry to match the new loaded message
				// the assumption here is that this message will necessarily come from the instance that
				// is actually loaded at that pid (like if someone relogged without MQ and then injected)
				login_it->second.Update(pid, profile);
				return &login_it->second;
			}

			// This profile has switched characters. We need to change to the new profile by removing
			// and re-adding with the new key. Remove here, and we'll add below.
			if (login_it->second.Hotkey && UnregisterGlobalHotkeyCallback)
				UnregisterGlobalHotkeyCallback(login_it->second.PID, *login_it->second.Hotkey);

			s_loadedInstances.erase(login_it);
			add = true;
		}

		if (add)
		{
			auto [it, _] = s_loadedInstances.emplace(newKey, LoginInstance(pid, profile));
			it->second.Update(pid, profile);
			return &it->second;
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

		// If process no longer exists we can remove it.
		if (!IsEQGameProcessId(login_it->second.PID))
		{
			SPDLOG_INFO("Found invalid process, removing from instances. pid={}", login_it->second.PID);

			// somehow we have a PID in our map that isn't EQ
			if (login_it->second.Hotkey && UnregisterGlobalHotkeyCallback)
				UnregisterGlobalHotkeyCallback(login_it->second.PID, *login_it->second.Hotkey);

			s_loadedInstances.erase(login_it);
			return nullptr;
		}
		else
		{
			login_it->second.Update(pid, profile);
		}

		// else do nothing because we are just acknowledging a loaded instance
	}

	if (login_it != s_loadedInstances.end())
		return &login_it->second;

	return nullptr;
}

void RemoveInstance(uint32_t pid)
{
	const auto login_it = std::find_if(s_loadedInstances.begin(), s_loadedInstances.end(),
		[pid](const std::pair<std::string, LoginInstance>& instance)
		{ return instance.second.PID == pid; });

	if (login_it != s_loadedInstances.end())
	{
		if (login_it->second.Hotkey && UnregisterGlobalHotkeyCallback)
			UnregisterGlobalHotkeyCallback(pid, *login_it->second.Hotkey);

		s_loadedInstances.erase(login_it);
	}
}

LoginInstance::LoginInstance(uint32_t pid, const ProfileRecord& profile)
	: PID(pid)
	, Server(profile.serverName)
	, ServerType(profile.serverType)
	, Character(profile.characterName)
	, Account(profile.accountName)
	, EQPath(profile.eqPath.has_value() ? *profile.eqPath : GetEQGameProcessPath(pid))
	, ProfileGroup(profile.profileName)
{
	if (!profile.hotkey.empty()) Hotkey = profile.hotkey;
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
		if (Hotkey && UnregisterGlobalHotkeyCallback)
			UnregisterGlobalHotkeyCallback(pid, *Hotkey);

		if (!profile.hotkey.empty())
		{
			Hotkey = profile.hotkey;

			if (RegisterGlobalHotkeyCallback)
				RegisterGlobalHotkeyCallback(pid, *Hotkey);
		}
	}

	// Update the profile name.
	if (!profile.profileName.empty())
	{
		if (ProfileGroup != profile.profileName)
		{
			ProfileGroup = profile.profileName;
		}
	}
	else if (ProfileGroup.has_value())
	{
		ProfileGroup.reset();
	}
}

DWORD LaunchProcess(const std::string& process, const std::string& workingDir)
{
	// Find a suitable parent process for this process we are creating (and remember it for later)
	wil::unique_process_handle hParent;
	static DWORD dwParentProcessID = 0;

	// Try to reuse parent id from last time
	if (dwParentProcessID != 0)
	{
		hParent.reset(OpenProcess(PROCESS_CREATE_PROCESS, FALSE, dwParentProcessID));

		if (!hParent)
		{
			dwParentProcessID = 0;
		}
	}

	// Try to use shell to get parent id
	if (!hParent)
	{
		HWND hWnd = GetShellWindow();
		DWORD dwProcessID = 0;

		if (GetWindowThreadProcessId(hWnd, &dwProcessID))
		{
			hParent.reset(OpenProcess(PROCESS_CREATE_PROCESS, FALSE, dwProcessID));

			if (hParent)
			{
				dwParentProcessID = dwProcessID;
			}
		}
	}

	// Search for explorer.exe as a fallback
	if (!hParent)
	{
		wil::unique_tool_help_snapshot hSnapshot(::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0));

		PROCESSENTRY32 proc = { sizeof(PROCESSENTRY32) };
		if (::Process32First(hSnapshot.get(), &proc))
		{
			do
			{
				if (mq::ci_equals(proc.szExeFile, "explorer.exe"))
				{
					dwParentProcessID = proc.th32ProcessID;
					break;
				}
			} while (Process32Next(hSnapshot.get(), &proc));
		}

		hParent.reset(::OpenProcess(PROCESS_CREATE_PROCESS, FALSE, dwParentProcessID));
	}

	if (!hParent)
	{
		SPDLOG_ERROR("Failed to find parent process for new eqgame process");
		return 0;
	}

	STARTUPINFOEXA si = { sizeof(STARTUPINFOEXA) };
	si.StartupInfo.wShowWindow = SW_SHOWNORMAL;
	si.StartupInfo.dwFlags = STARTF_USESHOWWINDOW;
	SIZE_T sizeToAlloc;
	InitializeProcThreadAttributeList(NULL, 1, 0, &sizeToAlloc);
	std::unique_ptr<char[]> pProcThreadAttrListPtr = std::make_unique<char[]>(sizeToAlloc);
	PPROC_THREAD_ATTRIBUTE_LIST pProcThreadAttrList = (PPROC_THREAD_ATTRIBUTE_LIST)pProcThreadAttrListPtr.get();
	InitializeProcThreadAttributeList(pProcThreadAttrList, 1, 0, &sizeToAlloc);
	UpdateProcThreadAttribute(pProcThreadAttrList, 0, PROC_THREAD_ATTRIBUTE_PARENT_PROCESS, hParent.addressof(), sizeof(hParent.get()), nullptr, nullptr);
	si.lpAttributeList = pProcThreadAttrList;

	SetLastError(0);

	wil::unique_process_information pi;
	if (CreateProcessA(
		nullptr,
		(LPSTR)process.c_str(),
		nullptr,
		nullptr,
		FALSE,
		EXTENDED_STARTUPINFO_PRESENT,
		nullptr,
		workingDir.c_str(),
		(LPSTARTUPINFOA)&si,
		&pi) && pi.hProcess != nullptr)
	{
		return pi.dwProcessId;
	}

	SPDLOG_ERROR("{}",
		fmt::windows_error(GetLastError(), "Failed to create new eqgame process").what());
	return 0;
}

const LoginInstance* StartInstance(ProfileRecord& profile)
{
	std::string instanceKey = LoginInstance::Key(profile);
	const auto login_it = s_loadedInstances.find(instanceKey);
	if (login_it != s_loadedInstances.end())
	{
		SPDLOG_WARN("Login instance for {} already exists as pid {}, not starting new instance",
			instanceKey, login_it->second.PID);

		login_it->second.Update(login_it->second.PID, profile);
		return UpdateInstance(login_it->second.PID, profile);
	}

	std::string eqPathSetLocation = "profile";

	// character is not loaded, so load it -- we can assume that it's not already running (with MQ anyway)
	// because we got a list at startup of the current running instances
	if (!profile.eqPath)
	{
		if (const auto path = login::db::GetEQPath(profile.profileName, profile.serverName, profile.characterName, &eqPathSetLocation))
		{
			profile.eqPath = *path;
		}
	}

	if (!profile.eqPath && !profile.serverType.empty())
	{
		profile.eqPath = login::db::GetPathFromServerType(profile.serverType);
		eqPathSetLocation = "eq installs";
	}

	if (!profile.eqPath)
	{
		std::string msg = fmt::format("No eq_path found for {} ({}) (profile group {})",
			profile.characterName, profile.serverName, profile.profileName);
		SPDLOG_ERROR("{}", msg);

		EQPathErrorMessage += fmt::format("{}\n", msg);
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
			std::string& eqPath = *profile.eqPath;
			const auto eqgame = fs::path{ eqPath } / "eqgame.exe";
			if (std::error_code ec; !fs::exists(eqgame, ec))
			{
				std::string msg = fmt::format("eqgame.exe does not exist at {} for {} ({}) (profile group {}), set from {}", *profile.eqPath,
					profile.characterName, profile.serverName, profile.profileName, eqPathSetLocation);
				SPDLOG_ERROR("{}", msg);

				EQPathErrorMessage += fmt::format("{}\n", msg);
			}
			else
			{
				std::string parameters = fmt::format(R"("{}" patchme "/login:{}")", eqgame.string(), arg);

				if (DWORD dwProcessID = LaunchProcess(parameters, eqPath))
				{
					auto [it, _] = s_loadedInstances.emplace(
						LoginInstance::Key(profile),
						LoginInstance(dwProcessID, profile));

					return &it->second;
				}
			}
		}
	}

	return nullptr;
}

#pragma endregion

#pragma region ServerName

void ServerNameInfo::List(const Action& select_action)
{
	fmt::memory_buffer buf;
	const auto buf_ins = std::back_inserter(buf);

	static auto server_names = CacheResults(login::db::ListServerNames);
	for (const auto& [short_name, long_name] : server_names.Read())
	{
		const bool is_selected = mq::ci_equals(short_name, ShortName) &&
			mq::ci_equals(long_name, LongName);

		format_to(buf_ins, "[{}] {}", short_name, long_name);
		buf.push_back(0);

		if (ImGui::Selectable(buf.data(), is_selected, ImGuiSelectableFlags_SpanAvailWidth))
		{
			ShortName = short_name;
			LongName = long_name;

			select_action();
		}

		if (is_selected)
			ImGui::SetItemDefaultFocus();

		buf.clear();
	}
}

std::string ServerNameInfo::Preview() const
{
	if (Valid())
		return fmt::format("[{}] {}", ShortName, LongName);

	return "";
}

void ServerNameInfo::Fill()
{
}

void ServerNameInfo::Update(const ServerNameInfo&) const
{
	if (Valid())
		login::db::CreateOrUpdateServer(ShortName, LongName);
}

void ServerNameInfo::Delete() const
{
	login::db::DeleteServer(ShortName, LongName);
}

#pragma endregion


#pragma region ServerType

void ServerTypeInfo::List(const Action& select_action)
{
	static auto server_types = CacheResults(login::db::ListServerTypes);
	for (const auto& server_type : server_types.Read())
	{
		const bool is_selected = mq::ci_equals(server_type, ServerType);
		if (ImGui::Selectable(server_type.c_str(), is_selected))
		{
			ServerType = server_type;
			select_action();
		}

		if (is_selected)
			ImGui::SetItemDefaultFocus();
	}
}

void ServerTypeInfo::Fill()
{
	if (const auto path = login::db::GetPathFromServerType(ServerType))
		EQPath = *path;
	else
		EQPath.clear();
}

std::string ServerTypeInfo::Preview() const
{
	return ServerType;
}

void ServerTypeInfo::Update(const ServerTypeInfo&) const
{
	if (Valid() && !EQPath.empty())
		login::db::CreateOrUpdateServerType(ServerType, EQPath);
}

void ServerTypeInfo::Delete() const
{
	login::db::DeleteServerType(ServerType);
}

#pragma endregion

#pragma region Account

void AccountInfo::List(const Action& select_action)
{
	static std::string search;
	static auto accounts = login::db::CacheResults([]
		{ return login::db::ListAccountMatches(search); });

	DefaultComboList<ProfileRecord>(
		search,
		[this, &select_action](const ProfileRecord& match)
		{
			Account = match.accountName;
			ServerType.ServerType = match.serverType;
			select_action();
		},
		accounts,
		[this](const ProfileRecord& match)
		{ return mq::ci_equals(match.accountName, Account) && mq::ci_equals(match.serverType, ServerType.ServerType); },
		[](fmt::memory_buffer& buf, const ProfileRecord& match)
		{ fmt::format_to(std::back_inserter(buf), "{} ({})", match.accountName, match.serverType); }
	);
}

void AccountInfo::Fill()
{
	if (const auto pass = login::db::ReadPassword(Account, ServerType.ServerType))
		Password = *pass;
	else
		Password.clear();
}

std::string AccountInfo::Preview() const
{
	if (Valid())
		return fmt::format("{} ({})", Account, ServerType.ServerType);

	return "";
}

void AccountInfo::Update(const AccountInfo& old) const
{
	if (Valid() && !Password.empty())
	{
		ProfileRecord profile;
		profile.accountName = Account;
		profile.accountPassword = Password;
		profile.serverType = ServerType.ServerType;

		if (old.Valid())
			login::db::UpdateAccount(old.Account, old.ServerType.ServerType, profile);
		else
			login::db::CreateAccount(profile);
	}
}

void AccountInfo::Delete() const
{
	login::db::DeleteAccount(Account, ServerType.ServerType);
}

bool AccountInfo::Compare(const ImGuiTableSortSpecs* specs, const ProfileRecord& l, const ProfileRecord& r)
{
	for (int n = 0; n < specs->SpecsCount; ++n)
	{
		const auto& spec = specs->Specs[n];
		const auto str_cmp = [&spec](std::string_view a, std::string_view b)
			{
				if (spec.SortDirection == ImGuiSortDirection_Ascending) return mq::ci_less()(a, b);

				return !mq::ci_less()(a, b);
			};

		switch (static_cast<SortID>(spec.ColumnUserID))
		{
		case SortID::Account:
			if (!mq::ci_equals(l.accountName, r.accountName))
				return str_cmp(l.accountName, r.accountName);
			break;
		case SortID::EQ_Install:
			if (!mq::ci_equals(l.serverType, r.serverType))
				return str_cmp(l.serverType, r.serverType);
			break;
		}
	}

	return false;
}

void AccountInfo::Sort(const ImGuiTableSortSpecs* sort_specs, std::vector<ProfileRecord>& items)
{
	if (items.size() > 1)
	{
		std::sort(items.begin(), items.end(),
			[sort_specs](const ProfileRecord& a, const ProfileRecord& b)
			{ return Compare(sort_specs, a, b); });
	}
}

#pragma endregion

#pragma region Character

void CharacterInfo::List(const Action& select_action)
{
	static std::string search;
	static auto characters = login::db::CacheResults([]
		{ return login::db::ListCharacterMatches(search); });

	DefaultComboList<ProfileRecord>(
		search,
		[this, &select_action](const ProfileRecord& match)
		{
			Character = match.characterName;
			Server = match.serverName;
			select_action();
		},
		characters,
		[this](const ProfileRecord& match)
		{ return mq::ci_equals(match.characterName, Character) && mq::ci_equals(match.serverName, Server); },
		[](fmt::memory_buffer& buf, const ProfileRecord& match)
		{ fmt::format_to(std::back_inserter(buf), "{} ({})", match.characterName, match.serverName); }
	);
}

void CharacterInfo::Fill()
{
	ProfileRecord profile;
	profile.serverName = Server;
	profile.characterName = Character;

	if (login::db::ReadCharacter(profile))
	{
		Account.Account = profile.accountName;
		Account.ServerType.ServerType = profile.serverType;
	}
	else
	{
		SPDLOG_ERROR("AutoLogin Error failed to load server {} and character {}", Server, Character);
	}

}

std::string CharacterInfo::Preview() const
{
	if (Valid())
		return fmt::format("{} ({})", Character, Server);

	return "";
}

void CharacterInfo::Update(const CharacterInfo& old) const
{
	if (Valid() && !Account.Account.empty() && !Account.ServerType.ServerType.empty())
	{
		ProfileRecord profile;
		profile.characterName = Character;
		profile.serverName = Server;
		profile.accountName = Account.Account;
		profile.serverType = Account.ServerType.ServerType;

		if (old.Valid())
			login::db::UpdateCharacter(old.Server, old.Character, profile);
		else
			login::db::CreateCharacter(profile);
	}
}

void CharacterInfo::Delete() const
{
	login::db::DeleteCharacter(Server, Character);
}

// TODO: persist the sort specs to share with the context menu
// persist the sort specs to sync sorting with the character context
ImGuiID CharacterInfo::GetID()
{
	static ImGuiID CharacterTableID =
		ImGui::GetIDWithSeed("Character Table", nullptr, ImGui::GetMainViewport()->ID);
	return CharacterTableID;
}

void CharacterInfo::SetupColumns()
{
	ImGui::TableSetupColumn(ICON_MD_VISIBILITY, ImGuiTableColumnFlags_NoSort | ImGuiTableColumnFlags_WidthFixed, ImGui::GetFrameHeight());
	ImGui::TableSetupColumn("Character", ImGuiTableColumnFlags_DefaultSort, 0.f, static_cast<ImGuiID>(SortID::Character));
	ImGui::TableSetupColumn("Server", ImGuiTableColumnFlags_None, 0.f, static_cast<ImGuiID>(SortID::Server));
	ImGui::TableSetupColumn("Class", ImGuiTableColumnFlags_None, 0.f, static_cast<ImGuiID>(SortID::Class));
	ImGui::TableSetupColumn("Level", ImGuiTableColumnFlags_None, 0.f, static_cast<ImGuiID>(SortID::Level));
	ImGui::TableSetupColumn("Account", ImGuiTableColumnFlags_None, 0.f, static_cast<ImGuiID>(SortID::Account));
	ImGui::TableSetupColumn("EQ Install", ImGuiTableColumnFlags_None, 0.f, static_cast<ImGuiID>(SortID::EQ_Install));
	ImGui::TableSetupColumn("Launch", ImGuiTableColumnFlags_NoSort);
	ImGui::TableSetupColumn(ICON_MD_POWER_SETTINGS_NEW, ImGuiTableColumnFlags_NoSort | ImGuiTableColumnFlags_WidthFixed);
}

void CharacterInfo::PersistSpecs(const ImGuiTableSortSpecs* specs)
{
	s_sortSpecs.clear();
	for (int n = 0; n < specs->SpecsCount; ++n)
		s_sortSpecs.push_back(specs->Specs[n]);

	s_contextMenuDirty = true;
}

bool CharacterInfo::Compare(const ProfileRecord& l, const ProfileRecord& r)
{
	for (const auto& spec : s_sortSpecs)
	{
		const auto str_cmp = [&spec](std::string_view a, std::string_view b)
			{
				if (spec.SortDirection == ImGuiSortDirection_Ascending) return mq::ci_less()(a, b);

				return !mq::ci_less()(a, b);
			};

		switch (static_cast<SortID>(spec.ColumnUserID))
		{
		case SortID::Account:
			if (!mq::ci_equals(l.accountName, r.accountName))
				return str_cmp(l.accountName, r.accountName);
			break;
		case SortID::EQ_Install:
			if (!mq::ci_equals(l.serverType, r.serverType))
				return str_cmp(l.serverType, r.serverType);
			break;
		case SortID::Server:
			if (!mq::ci_equals(l.serverName, r.serverName))
				return str_cmp(l.serverName, r.serverName);
			break;
		case SortID::Character:
			if (!mq::ci_equals(l.characterName, r.characterName))
				return str_cmp(l.characterName, r.characterName);
			break;
		case SortID::Class:
			if (!mq::ci_equals(l.characterClass, r.characterClass))
				return str_cmp(l.characterClass, r.characterClass);
			break;
		case SortID::Level:
			if (l.characterLevel != r.characterLevel)
			{
				if (spec.SortDirection == ImGuiSortDirection_Ascending)
					return l.characterLevel < r.characterLevel;

				return l.characterLevel > r.characterLevel;
			}
			break;
		}
	}

	return false;
}

void CharacterInfo::Sort(const ImGuiTableSortSpecs* sort_specs, std::vector<ProfileRecord>& items)
{
	PersistSpecs(sort_specs);

	Sort(items);
}

void CharacterInfo::Sort(std::vector<ProfileRecord>& items)
{
	if (items.size() > 1)
		std::sort(items.begin(), items.end(), Compare);
}

#pragma endregion

#pragma region Profile

void ProfileInfo::Fill()
{
	characterName = Character.Character;
	serverName = Character.Server;
	login::db::ReadProfile(*this);
}

std::string ProfileInfo::Preview() const
{
	if (Valid())
		return fmt::format("[{}] {}", profileName, Character.Preview());

	return "";
}

ProfileInfo& ProfileInfo::operator=(const ProfileRecord& record)
{
	ProfileRecord::operator=(record);
	Character = {};
	return *this;
}

#pragma endregion

#pragma region ProfileGroupInfo

void ProfileGroupInfo::List(const Action& select_action)
{
	static std::string search;
	static auto profile_groups = login::db::CacheResults([]
		{ return login::db::ListProfileGroupMatches(search); });

	DefaultComboList<std::string>(
		search,
		[this, &select_action](const std::string& match)
		{
			profileName = match;
			login::db::TouchProfileGroup(match);
			select_action();
		},
		profile_groups,
		[this](const std::string& match) { return mq::ci_equals(match, profileName); },
		[](fmt::memory_buffer& buf, const std::string& match)
		{ fmt::format_to(std::back_inserter(buf), match); }
	);
}

void ProfileGroupInfo::Fill()
{
	login::db::ReadProfileGroup(*this);
}

std::string ProfileGroupInfo::Preview() const
{
	return profileName;
}

void ProfileGroupInfo::Update(const ProfileGroupInfo& old) const
{
	if (!profileName.empty())
	{
		if (old.Valid())
			login::db::UpdateProfileGroup(old.profileName, *this);
		else
			login::db::CreateProfileGroup(*this);
	}
}

void ProfileGroupInfo::Delete() const
{
	login::db::DeleteProfileGroup(profileName);
}

#pragma endregion

void DrawStatusIcon(const ProfileRecord& profile)
{
	auto iter = s_loadedInstances.find(LoginInstance::Key(profile));
	if (iter != s_loadedInstances.end())
	{
		const LoginInstance& instance = iter->second;

		if (profile.profileName.empty()
			|| instance.ProfileGroup == profile.profileName)
		{
			ImGui::PushStyleColor(ImGuiCol_Text, { 0.f, 1.f, 0.f, 1.f });
			ImGui::TextUnformatted(ICON_MD_POWER_SETTINGS_NEW);
			ImGui::PopStyleColor();
		}
		else
		{
			ImGui::PushStyleColor(ImGuiCol_Text, mq::MQColor(0, 148, 255).ToImU32());
			ImGui::TextUnformatted(ICON_MD_SETTINGS_POWER);
			ImGui::PopStyleColor();

			ImGui::SetItemTooltip("This character is already logged in, but not with this profile.\n"
				"Launching will instead apply this profile. (Hold SHIFT to force a new login)");
		}
	}
	else if (const LoginInstance* accountInstance = GetAccountInstance(profile.accountName, profile.serverType))
	{
		ImGui::PushStyleColor(ImGuiCol_Text, { 1.0f, 1.0f, 0, 1.0f });
		ImGui::TextUnformatted(ICON_MD_DO_NOT_DISTURB);
		ImGui::PopStyleColor();

		ImGui::SetItemTooltip("This account is logged in on another character: %s (%s)",
			accountInstance->Character.c_str(), accountInstance->Server.c_str());
	}
}

void ShowProfilesMenu(bool showLoadAll)
{
	fmt::memory_buffer buf;
	const auto buf_ins = std::back_inserter(buf);

	static auto profile_groups = CacheResults(login::db::ListProfileGroups);
	const auto& loaded = GetLoadedInstances();
	for (const auto& group : profile_groups.Read())
	{
		ImGui::SetNextWindowSizeConstraints(ImVec2(300, 0), ImVec2(FLT_MAX, FLT_MAX));
		if (ImGui::BeginMenu(group.c_str()))
		{
			static auto last_group = group;
			static auto profiles = login::db::CacheResults([]
				{
					return login::db::GetProfiles(last_group);
				});

			const bool force_profiles_update = !mq::ci_equals(last_group, group);
			if (force_profiles_update)
				last_group = group;

			if (profiles.Read(force_profiles_update).empty())
			{
				ImGui::Text("No available profiles");
			}
			else
			{
				if (showLoadAll && LoadAllStarredCallback)
				{
					if (ImGui::Selectable("Launch All Starred", false, ImGuiSelectableFlags_SpanAllColumns))
					{
						LoadAllStarredCallback(group, ImGui::IsKeyPressed(ImGuiMod_Shift));
					}

					ImGui::Separator();
				}

				if (ImGui::BeginTable("##Profiles", 6, ImGuiTableFlags_None))
				{
					ImGui::TableSetupColumn("##Loadable", ImGuiTableColumnFlags_WidthFixed, ImGui::GetFrameHeight());
					ImGui::TableSetupColumn("Character Name", ImGuiTableColumnFlags_WidthStretch);
					ImGui::TableSetupColumn("Level", ImGuiTableColumnFlags_WidthFixed, ImGui::CalcTextSize("0000").x);
					ImGui::TableSetupColumn("Class", ImGuiTableColumnFlags_WidthFixed);
					ImGui::TableSetupColumn("Hotkey", ImGuiTableColumnFlags_WidthStretch);
					ImGui::TableSetupColumn("##Loaded", ImGuiTableColumnFlags_WidthFixed, ImGui::GetFrameHeight());

					ImGui::TableNextRow(ImGuiTableRowFlags_None);
					ImGui::TableNextColumn();

					ImGui::PushItemFlag(ImGuiItemFlags_AutoClosePopups, false);

					for (auto& profile : profiles.Updated())
					{
						ImGui::TableNextRow(ImGuiTableRowFlags_None);
						ImGui::TableNextColumn();
						if (profile.willLoad)
						{
							ImGui::PushStyleColor(ImGuiCol_Text, { .75f, .75f, 0.f, 1.f });
							ImGui::TextUnformatted(ICON_MD_STAR);
							ImGui::PopStyleColor();
						}

						ImGui::TableNextColumn();
						if (ImGui::Selectable(profile.characterName.c_str(), false, ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_DontClosePopups))
						{
							if (!ImGui::IsKeyDown(ImGuiMod_Ctrl))
							{
								LoadCharacterCallback(profile, ImGui::IsKeyPressed(ImGuiMod_Shift));

								ImGui::CloseCurrentPopup();
							}
						}

						if (ImGui::IsItemClicked(ImGuiMouseButton_Left) && ImGui::IsKeyDown(ImGuiMod_Ctrl))
						{
							profile.willLoad = !profile.willLoad;
							login::db::UpdateProfile(profile);
						}

						ImGui::TableNextColumn();
						fmt::format_to(buf_ins, "{}", profile.characterLevel);
						buf.push_back(0);
						ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetContentRegionAvail().x - ImGui::CalcTextSize(buf.data()).x);
						ImGui::TextUnformatted(buf.data());
						buf.clear();

						ImGui::TableNextColumn();
						ImGui::TextUnformatted(profile.characterClass.c_str());

						ImGui::TableNextColumn();
						ImGui::TextUnformatted(profile.hotkey.c_str());
							
						ImGui::TableNextColumn();
						DrawStatusIcon(profile);
					}

					ImGui::PopItemFlag();
					ImGui::EndTable();
				}
			}

			ImGui::EndMenu();
		}
	}
}

void ShowCharactersMenu()
{
	fmt::memory_buffer buf;
	const auto buf_ins = std::back_inserter(buf);

	static auto servers = CacheResults(login::db::ListServers);
	const auto& loaded = GetLoadedInstances();
	for (const auto& server : servers.Read())
	{
		if (server.empty())
			continue;

		ImGui::SetNextWindowSizeConstraints(ImVec2(300, 0), ImVec2(FLT_MAX, FLT_MAX));
		if (ImGui::BeginMenu(server.c_str()))
		{
			static auto last_server = server;
			static auto server_characters = login::db::CacheResults([]
				{
					return login::db::ListCharactersOnServer(last_server);
				});

			static std::vector<ProfileRecord>& characters = *[]
				{
					// this is to force the initial settings read if the main table hasn't been opened
					// and then also do an initial sort based on these settings
					const auto window = ImGui::GetCurrentWindow();
					const auto win_flags = window->RootWindow->Flags;
					window->RootWindow->Flags &= ~ImGuiWindowFlags_NoSavedSettings;

					ImGui::PushOverrideID(CharacterInfo::GetID());
					if (ImGui::BeginTable("Main List", 9, ImGuiTableFlags_Sortable | ImGuiTableFlags_SortMulti))
					{
						CharacterInfo::SetupColumns();
						CharacterInfo::Sort(ImGui::TableGetSortSpecs(), server_characters.Updated());
						ImGui::EndTable();
					}
					ImGui::PopID();

					window->RootWindow->Flags = win_flags;

					return &server_characters.Updated();
				}();

			const bool force_characters_update = !mq::ci_equals(last_server, server);
			if (force_characters_update)
				last_server = server;

			if (server_characters.ReadHasChanged(force_characters_update) || CharacterInfo::s_contextMenuDirty)
			{
				CharacterInfo::Sort(characters);
				CharacterInfo::s_contextMenuDirty = false;
			}

			if (characters.empty())
			{
				ImGui::Text("No available characters");
			}
			else if (ImGui::BeginTable("##Characters", 5, ImGuiTableFlags_None))
			{
				ImGui::TableSetupColumn("Character Name", ImGuiTableColumnFlags_WidthStretch, 0.f, static_cast<ImGuiID>(CharacterInfo::SortID::Character));
				ImGui::TableSetupColumn("Level", ImGuiTableColumnFlags_WidthFixed, ImGui::CalcTextSize("0000").x, static_cast<ImGuiID>(CharacterInfo::SortID::Level));
				ImGui::TableSetupColumn("Class", ImGuiTableColumnFlags_WidthFixed, 0.f, static_cast<ImGuiID>(CharacterInfo::SortID::Class));
				ImGui::TableSetupColumn("Account", ImGuiTableColumnFlags_WidthFixed, 0.f, static_cast<ImGuiID>(CharacterInfo::SortID::Account));
				ImGui::TableSetupColumn("Loaded", ImGuiTableColumnFlags_WidthFixed, ImGui::GetFrameHeight());

				for (auto& profile : characters)
				{
					ImGui::PushID(&profile);

					ImGui::TableNextRow(ImGuiTableRowFlags_None);

					ImGui::TableNextColumn();
					if (ImGui::Selectable(profile.characterName.c_str(), false, ImGuiSelectableFlags_SpanAllColumns))
						LoadCharacterCallback(profile, true);

					ImGui::TableNextColumn();
					fmt::format_to(buf_ins, "{}", profile.characterLevel);
					buf.push_back(0);
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetContentRegionAvail().x - ImGui::CalcTextSize(buf.data()).x);
					ImGui::TextUnformatted(buf.data());
					buf.clear();

					ImGui::TableNextColumn();
					ImGui::Selectable(profile.characterClass.c_str(), false);

					ImGui::TableNextColumn();
					ImGui::PushStyleVar(ImGuiStyleVar_Alpha, ImGui::GetStyle().Alpha * 0.25f);
					ImGui::Selectable(profile.accountName.c_str(), false);
					ImGui::PopStyleVar();

					ImGui::TableNextColumn();
					DrawStatusIcon(profile);

					ImGui::PopID();
				}

				ImGui::EndTable();
			}

			ImGui::EndMenu();
		}
	}
}

void SerializeProfile(const ProfileRecord& record, mq::proto::login::ProfileMethod& profile)
{
	profile.set_profile(record.profileName);
	profile.set_account(record.accountName);

	mq::proto::login::LoginTarget& target = *profile.mutable_target();
	target.set_server(record.serverName);
	target.set_character(record.characterName);
	target.set_server_type(record.serverType);
}

void SerializeProfile(const ProfileRecord& record, mq::proto::login::DirectMethod& direct)
{
	direct.set_login(record.accountName);

	mq::proto::login::LoginTarget& target = *direct.mutable_target();
	target.set_server(record.serverName);
	target.set_character(record.characterName);
	target.set_server_type(record.serverType);

	if (!record.hotkey.empty())
		direct.set_hotkey(record.hotkey);
}

ProfileRecord ParseProfileFromMessage(const mq::proto::login::DirectMethod& direct)
{
	ProfileRecord profile;
	if (direct.has_target())
	{
		if (direct.target().has_server())
			profile.serverName = direct.target().server();

		if (direct.target().has_character())
			profile.characterName = direct.target().character();

		if (direct.target().has_server_type())
			profile.serverType = direct.target().server_type();
	}

	profile.accountName = direct.login();
	profile.accountPassword = direct.password();

	if (direct.has_hotkey())
		profile.hotkey = direct.hotkey();

	if (direct.has_eq_path())
		profile.eqPath = direct.eq_path();

	return profile;
}

ProfileRecord ParseProfileFromMessage(const mq::proto::login::ProfileMethod& profile)
{
	ProfileRecord record;
	record.profileName = profile.profile();
	record.accountName = profile.account();

	if (profile.has_target() && profile.target().has_character() && profile.target().has_server())
	{
		record.serverName = profile.target().server();
		record.characterName = profile.target().character();
		record.serverType = profile.target().server_type();

		// get the remaining data from the db for the profile
		login::db::ReadProfile(record);
	}
	else
	{
		// only profile -- get the first record
		login::db::ReadFirstProfile(record);
	}

	return record;
}
