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
#include "HotKeyControl.h"

#include "login/Login.h"
#include "routing/PostOffice.h"

#include "ImGui.h"

#include <shellapi.h>

#include <wil/resource.h>
#include <filesystem>
#include <spdlog/spdlog.h>

#include <fmt/format.h>
#include <fmt/compile.h>

#include "imgui/ImGuiFileDialog.h"
#include "imgui/misc/cpp/imgui_stdlib.h"
#include "imgui_internal.h"

namespace fs = std::filesystem;

CHotKeyCtrl* s_hotKeyCtrl = nullptr;

struct LoginInstance
{
	mutable unsigned long PID = 0;

	std::string Server;
	std::string Character;

	std::optional<std::pair<std::string, std::string>> AccountAndPassword;

	mutable std::optional<std::string> ProfileGroup;
	mutable std::optional<std::string> EQPath;
	mutable std::optional<std::string> Hotkey;

	bool operator==(const LoginInstance& other) const
	{
		return ci_equals(Server, other.Server) && ci_equals(Character, other.Character);
	}

	// hash function, based on server and character
	size_t operator()(const LoginInstance& instance) const
	{
		return std::hash<std::string>()(instance.Server) ^ std::hash<std::string>()(instance.Character);
	}
};

namespace {
// set of loaded instances -- be careful to only read/write this from actors to ensure no race conditions
std::unordered_set<LoginInstance, LoginInstance> s_loadedInstances;
using LoginIterator = std::unordered_set<LoginInstance, LoginInstance>::const_iterator;

postoffice::Dropbox s_dropbox;

ImGuiFileDialog* s_eqDirDialog = nullptr;
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

namespace {
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
			SPDLOG_ERROR("No eq_path found for %s : %s (profile group %s)",
				instance_template.Server, instance_template.Character,
				instance_template.ProfileGroup ? *instance_template.ProfileGroup : "<None>");
		}
	}

	return login_it;
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

}

#pragma region ImGui

namespace {
#pragma region Helpers

using Action = const std::function<void()>&;

void DefaultModalButtons(Action ok_action, const char* cancel = "Cancel", const char* ok = "OK")
{
	const auto cancel_size = ImGui::CalcTextSize(cancel);
	const auto ok_size = ImGui::CalcTextSize(ok);
	const auto size = ImVec2(
		std::max(cancel_size.x, ok_size.x),
		std::max(cancel_size.y, ok_size.y)) +
		ImGui::GetStyle().FramePadding * 2;

	ImGui::Separator();

	ImGui::SetItemDefaultFocus();
	if (ImGui::Button(cancel, size))
	{
		LauncherImGui::CloseModal();
	}

	ImGui::SameLine();
	ImGui::SetCursorPosX(std::max(
		ImGui::GetContentRegionMax().x - size.x,
		size.x + ImGui::GetStyle().ItemSpacing.x + ImGui::GetStyle().FramePadding.x * 2));
	if (ImGui::Button(ok, size))
	{
		ok_action();
		LauncherImGui::CloseModal();
	}
}

void DeleteModal(const std::string& name, const std::string_view message, Action yes_action)
{
	ImGui::SetNextWindowSizeConstraints({ 200.f, 0.f }, { FLT_MAX, FLT_MAX });
	if (LauncherImGui::BeginModal(name, nullptr, ImGuiWindowFlags_None))
	{
		ImGui::TextWrapped("%.*s", static_cast<int>(message.length()), message.data());
		ImGui::Spacing();

		DefaultModalButtons(yes_action, "No", "Yes");

		LauncherImGui::EndModal();
	}
}

template <std::string_view const&... Strings>
struct JoinLabels
{
	static constexpr auto Impl() noexcept
	{
		constexpr size_t len = (Strings.size() + ... + 0);
		std::array<char, len + 1> arr{};
		auto append = [i = 0, &arr](auto const& s) mutable
			{
				for (auto c : s) arr[i++] = c;
			};
		(append(Strings), ...);
		arr[len] = 0;
		return arr;
	}

	static constexpr auto char_arr = Impl();
	static constexpr std::string_view view{ char_arr.data(), char_arr.size() - 1 };
	static constexpr const char* literal = view.data();
};

template <typename, typename = std::string_view>
struct HasLabelOverride : std::false_type {};

template <typename T>
struct HasLabelOverride<T, decltype((void)T::label_override, std::string_view())> : std::true_type {};

struct ServerTypeInfo
{
	std::string ServerType;
	std::string EQPath;

	void List(Action);
	void Fill();
	[[nodiscard]] std::string Preview() const;
	void Edit(const char*, Action);
	void Combo(std::string&, Action);
	void ListBox();

	static constexpr std::string_view label = "Server Type";

	explicit operator bool() const { return !ServerType.empty(); }
};

struct AccountInfo
{
	std::string Account;
	std::string Password;
	ServerTypeInfo ServerType;

	void List(Action);
	void Fill();
	[[nodiscard]] std::string Preview() const;
	void Edit(const char*, Action);
	void Combo(std::string&, Action);
	void ListBox();

	static constexpr std::string_view label = "Account";

	explicit operator bool() const { return !Account.empty() && ServerType; }
};

struct CharacterInfo
{
	AccountInfo Account;
	std::string Server;
	std::string Character;

	void List(Action);
	void Fill();
	[[nodiscard]] std::string Preview() const;
	void Edit(const char*, Action);
	void Combo(std::string&, Action);
	void ListBox();

	static constexpr std::string_view label = "Character";

	explicit operator bool() const { return !Server.empty() && !Character.empty(); }
};

struct ProfileInfo : ProfileRecord
{
	CharacterInfo Character;

	void Fill();
	[[nodiscard]] std::string Preview() const;
	void Edit(const char*, Action);

	static constexpr std::string_view label = "Profile";

	explicit operator bool() const { return !profileName.empty() && Character; }
};

struct ProfileGroupInfo : ProfileGroup
{
	void List(Action);
	void Fill();
	[[nodiscard]] std::string Preview() const;
	void Edit(const char*, Action);
	void Combo(std::string&, Action);
	void ListBox();

	static constexpr std::string_view label = "Profile Group";
	static constexpr std::string_view label_override;

	explicit operator bool() const { return !profileName.empty(); }
};

template <typename Info>
void DefaultCombo(std::string& preview, Info& info, Action select_action, Action edit_action)
{
	static constexpr std::string_view hidden_prefix = "##";
	const auto width = ImGui::CalcItemWidth() - ImGui::CalcTextSize("...").x - ImGui::GetStyle().FramePadding.x * 2;
	ImGui::SetNextItemWidth(width);
	if (ImGui::BeginCombo(JoinLabels<hidden_prefix, Info::label>::literal, preview.c_str(), ImGuiComboFlags_NoArrowButton))
	{
		info.List([&preview, &info, &select_action]
		{
				select_action();
				preview = info.Preview();
			});
		ImGui::EndCombo();
	}

	static constexpr std::string_view modal_suffix = " Select";
	static constexpr const char* modal_name = JoinLabels<Info::label, modal_suffix>::literal;
	ImGui::SameLine(0.f, 0.f);
	if (ImGui::Button("..."))
	{
		LauncherImGui::OpenModal(modal_name);
	}

	if constexpr (HasLabelOverride<Info>::value)
	{
		if constexpr (!Info::label_override.empty())
		{
			ImGui::SameLine(0.f, ImGui::GetStyle().ItemInnerSpacing.x);
			ImGui::Text(JoinLabels<Info::label_override>::literal);
		}
	}
	else
	{
		ImGui::SameLine(0.f, ImGui::GetStyle().ItemInnerSpacing.x);
		ImGui::Text(JoinLabels<Info::label>::literal);
	}

	if (LauncherImGui::BeginModal(modal_name, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		info.ListBox();

		DefaultModalButtons([&preview, &info, &edit_action]
			{
				edit_action();
				preview = info.Preview();
			});

		LauncherImGui::EndModal();
	}
}

template <typename Info>
void DefaultListBox(Info& selected, Info& info, Action create_action, Action edit_action, Action remove_action)
{
	static constexpr std::string_view hidden_prefix = "##";
	ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
	if (ImGui::BeginListBox(JoinLabels<hidden_prefix, Info::label>::literal))
	{
		selected.List([] {});
		ImGui::EndListBox();
	}

	if (ImGui::IsKeyPressed(ImGuiKey_Escape))
		selected = {};

	static constexpr std::string_view add_prefix = "Add ";
	static constexpr const char* add_name = JoinLabels<add_prefix, Info::label>::literal;
	if (ImGui::Button(add_name))
	{
		info = selected;
		LauncherImGui::OpenModal(add_name);
	}
	info.Edit(add_name, [&selected, &info, &create_action]
	{
			create_action();
			selected = info;
		});

	static constexpr std::string_view edit_prefix = "Edit ";
	static constexpr const char* edit_name = JoinLabels<edit_prefix, Info::label>::literal;
	ImGui::SameLine();
	if (ImGui::Button(edit_name) || ImGui::IsKeyPressed(ImGuiKey_Enter))
	{
		if (selected)
		{
			info = selected;
			info.Fill();

			LauncherImGui::OpenModal(edit_name);
		}
	}
	info.Edit(edit_name, [&selected, &info, &edit_action]
	{
			edit_action();
			selected = info;
		});

	static constexpr std::string_view remove_prefix = "Remove ";
	static constexpr const char* remove_name = JoinLabels<remove_prefix, Info::label>::literal;
	static std::string remove_message;
	ImGui::SameLine();
	if (ImGui::Button(remove_name) || ImGui::IsKeyPressed(ImGuiKey_Delete))
	{
		if (selected)
		{
			remove_message = fmt::format("Are you sure you want to remove {} '{}'? All dependent data will also be removed.", Info::label, selected.Preview());
			LauncherImGui::OpenModal(remove_name);
		}
	}

	DeleteModal(remove_name, remove_message, [&selected, &remove_action]
	{
			remove_action();
			selected = {};
		});
}

void SetEQDirModal(std::optional<std::string>& eq_path, Action ok_action)
{
	if (LauncherImGui::BeginModal("Input EQ Path", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		if (eq_path)
			ImGui::Text(eq_path->c_str());
		else
			ImGui::Text(internal_paths::s_eqRoot.c_str());

		if (!s_eqDirDialog)
			s_eqDirDialog = IGFD_Create();

		if (ImGui::Button("Choose"))
		{
			IGFD_OpenDialog2(s_eqDirDialog, "ChooseEQDirKey", "Choose Default EverQuest Directory",
				nullptr, (internal_paths::s_eqRoot + "/").c_str(), 1, nullptr, ImGuiFileDialogFlags_None);
		}

		if (IGFD_DisplayDialog(s_eqDirDialog, "ChooseEQDirKey", ImGuiFileDialogFlags_None, ImVec2(350, 350), ImVec2(FLT_MAX, FLT_MAX)))
		{
			if (IGFD_IsOk(s_eqDirDialog))
			{
				const std::shared_ptr<char> selected_path(IGFD_GetCurrentPath(s_eqDirDialog), IGFD_DestroyString);
				if (std::error_code ec; selected_path && std::filesystem::exists(selected_path.get(), ec))
				{
					eq_path = canonical(std::filesystem::path(selected_path.get()), ec).string();
				}
			}

			IGFD_CloseDialog(s_eqDirDialog);
		}

		DefaultModalButtons(ok_action);

		LauncherImGui::EndModal();
	}
}

#pragma endregion

#pragma region Hotkey

const std::unordered_map<ImGuiKey, std::string> s_hotkeyMap = {
	{ ImGuiKey_LeftArrow, "LEFT" },
	{ ImGuiKey_RightArrow, "RIGHT" },
	{ ImGuiKey_UpArrow, "UP" },
	{ ImGuiKey_DownArrow, "DOWN" },
	{ ImGuiKey_PageUp, "PAGEUP" },
	{ ImGuiKey_PageDown, "PAGEDOWN" },
	{ ImGuiKey_Home, "HOME" },
	{ ImGuiKey_End, "END" },
	{ ImGuiKey_Insert, "INSERT" },
	{ ImGuiKey_Delete, "DELETE" },
	{ ImGuiKey_Space, "SPACE" },
	{ ImGuiKey_Enter, "RETURN" },
	{ ImGuiKey_Escape, "ESCAPE" },
	{ ImGuiKey_0, "0" }, { ImGuiKey_1, "1" }, { ImGuiKey_2, "2" }, { ImGuiKey_3, "3" }, { ImGuiKey_4, "4" }, { ImGuiKey_5, "5" }, { ImGuiKey_6, "6" }, { ImGuiKey_7, "7" }, { ImGuiKey_8, "8" }, { ImGuiKey_9, "9" },
	{ ImGuiKey_A, "A" }, { ImGuiKey_B, "B" }, { ImGuiKey_C, "C" }, { ImGuiKey_D, "D" }, { ImGuiKey_E, "E" }, { ImGuiKey_F, "F" }, { ImGuiKey_G, "G" }, { ImGuiKey_H, "H" }, { ImGuiKey_I, "I" }, { ImGuiKey_J, "J" },
	{ ImGuiKey_K, "K" }, { ImGuiKey_L, "L" }, { ImGuiKey_M, "M" }, { ImGuiKey_N, "N" }, { ImGuiKey_O, "O" }, { ImGuiKey_P, "P" }, { ImGuiKey_Q, "Q" }, { ImGuiKey_R, "R" }, { ImGuiKey_S, "S" }, { ImGuiKey_T, "T" },
	{ ImGuiKey_U, "U" }, { ImGuiKey_V, "V" }, { ImGuiKey_W, "W" }, { ImGuiKey_X, "X" }, { ImGuiKey_Y, "Y" }, { ImGuiKey_Z, "Z" },
	{ ImGuiKey_F1, "F1" }, { ImGuiKey_F2, "F2" }, { ImGuiKey_F3, "F3" }, { ImGuiKey_F4, "F4" }, { ImGuiKey_F5, "F5" }, { ImGuiKey_F6, "F6" },
	{ ImGuiKey_F7, "F7" }, { ImGuiKey_F8, "F8" }, { ImGuiKey_F9, "F9" }, { ImGuiKey_F10, "F10" }, { ImGuiKey_F11, "F11" }, { ImGuiKey_F12, "F12" },
	{ ImGuiKey_F13, "F13" }, { ImGuiKey_F14, "F14" }, { ImGuiKey_F15, "F15" }, { ImGuiKey_F16, "F16" }, { ImGuiKey_F17, "F17" }, { ImGuiKey_F18, "F18" },
	{ ImGuiKey_F19, "F19" }, { ImGuiKey_F20, "F20" }, { ImGuiKey_F21, "F21" }, { ImGuiKey_F22, "F22" }, { ImGuiKey_F23, "F23" }, { ImGuiKey_F24, "F24" },
	{ ImGuiKey_Apostrophe, "'" },
	{ ImGuiKey_Comma, "," },
	{ ImGuiKey_Minus, "-" },
	{ ImGuiKey_Period, "." },
	{ ImGuiKey_Slash, "/" },
	{ ImGuiKey_Semicolon, ";" },
	{ ImGuiKey_Equal, "=" },
	{ ImGuiKey_LeftBracket, "[" },
	{ ImGuiKey_Backslash, "\\" },
	{ ImGuiKey_RightBracket, "]" },
	{ ImGuiKey_GraveAccent, "`" },
	{ ImGuiKey_NumLock, "NUMLOCK" },
	{ ImGuiKey_Keypad0, "NUMPAD0" }, { ImGuiKey_Keypad1, "NUMPAD1" }, { ImGuiKey_Keypad2, "NUMPAD2" }, { ImGuiKey_Keypad3, "NUMPAD3" }, { ImGuiKey_Keypad4, "NUMPAD4" },
	{ ImGuiKey_Keypad5, "NUMPAD5" }, { ImGuiKey_Keypad6, "NUMPAD6" }, { ImGuiKey_Keypad7, "NUMPAD7" }, { ImGuiKey_Keypad8, "NUMPAD8" }, { ImGuiKey_Keypad9, "NUMPAD9" },
	{ ImGuiKey_KeypadDecimal, "NUMPAD." },
	{ ImGuiKey_KeypadDivide, "NUMPAD/" },
	{ ImGuiKey_KeypadMultiply, "NUMPAD*" },
	{ ImGuiKey_KeypadSubtract, "NUMPAD-" },
	{ ImGuiKey_KeypadAdd, "NUMPAD+" },
	{ ImGuiKey_KeypadEqual, "NUMPAD=" },
};

void ShowHotkeyWindow(const std::string& name, std::string& hotkey)
{
	if (LauncherImGui::BeginModal(name, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		fmt::memory_buffer buf;
		const auto buf_ins = std::back_inserter(buf);

		if (ImGui::IsKeyDown(ImGuiMod_Ctrl))
			format_to(buf_ins, "CTRL+");

		if (ImGui::IsKeyDown(ImGuiMod_Shift))
			format_to(buf_ins, "SHIFT+");

		if (ImGui::IsKeyDown(ImGuiMod_Alt))
			format_to(buf_ins, "ALT+");

		if (ImGui::IsKeyDown(ImGuiMod_Super))
			format_to(buf_ins, "WIN+");

		for (const auto& [key, text] : s_hotkeyMap)
		{
			if (ImGui::IsKeyDown(key))
			{
				format_to(buf_ins, text);
				hotkey = fmt::to_string(buf);
				break;
			}
		}

		ImGui::Text("Pressed: %.*s", static_cast<int>(buf.size()), buf.data());
		ImGui::Text("Current: %s", !hotkey.empty() ? hotkey.c_str() : "<None>");

		DefaultModalButtons([] {});

		LauncherImGui::EndModal();
	}
}

#pragma endregion

#pragma region ServerType

void ServerTypeInfo::List(Action select_action)
{
	for (const auto& server_type : login::db::ListServerTypes())
	{
		ImGui::PushID(server_type.c_str());

		const bool is_selected = ci_equals(server_type, ServerType);
		if (ImGui::Selectable(server_type.c_str(), is_selected))
		{
			ServerType = server_type;
			select_action();
		}

		if (is_selected)
			ImGui::SetItemDefaultFocus();

		ImGui::PopID();
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

void ServerTypeInfo::Edit(const char* name, Action ok_action)
{
	// we need an optional copy of the eqpath for the modal to get a flow that makes sense
	static std::optional<std::string> eq_path;

	if (LauncherImGui::BeginModal(name, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::InputText("Type", &ServerType);
		ImGui::Spacing();

		if (ImGui::Button("EQ Path"))
		{
			if (!EQPath.empty())
				eq_path = EQPath;
			else
				eq_path = {};

			LauncherImGui::OpenModal("Input EQ Path");
		}

		SetEQDirModal(eq_path, [this]
		{
				if (eq_path) EQPath = *eq_path;
			});

		ImGui::SameLine();
		ImGui::Text("%.*s", static_cast<int>(EQPath.size()), EQPath.data());

		DefaultModalButtons(ok_action);

		LauncherImGui::EndModal();
	}
}

void ServerTypeInfo::Combo(std::string& preview, Action select_action)
{
	DefaultCombo(preview, *this,
		select_action,
		[this]
		{
			if (!ServerType.empty() && EQPath.empty())
				login::db::CreateOrUpdateServerType(ServerType, EQPath);
		});
}

void ServerTypeInfo::ListBox()
{
	static ServerTypeInfo info;
	DefaultListBox(*this, info,
		[]
		{
			if (!info.ServerType.empty() && !info.EQPath.empty())
				login::db::CreateOrUpdateServerType(info.ServerType, info.EQPath);
		},
		[]
		{
			if (!info.ServerType.empty() && !info.EQPath.empty())
				login::db::CreateOrUpdateServerType(info.ServerType, info.EQPath);
		},
		[this]
		{
			login::db::DeleteServerType(ServerType);
		});
}

#pragma endregion

#pragma region Account

void AccountInfo::List(Action select_action)
{
	fmt::memory_buffer buf;
	const auto buf_ins = std::back_inserter(buf);

	for (const auto& [account, server_type] : login::db::ListAccounts())
	{
		ImGui::PushID(account.c_str());
		ImGui::PushID(server_type.c_str());

		const bool is_selected = ci_equals(account, Account) &&
			ci_equals(server_type, ServerType.ServerType);

		format_to(buf_ins, "{} ({})", account, server_type);

		if (ImGui::Selectable("", is_selected, ImGuiSelectableFlags_SpanAvailWidth))
		{
			Account = account;
			ServerType.ServerType = server_type;

			select_action();
		}

		if (is_selected)
			ImGui::SetItemDefaultFocus();

		ImGui::SameLine();
		ImGui::Text("%.*s", static_cast<int>(buf.size()), buf.data());

		buf.clear();

		ImGui::PopID();
		ImGui::PopID();
	}
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
	return fmt::format("{} ({})", Account, ServerType.ServerType);
}

void AccountInfo::Edit(const char* name, Action ok_action)
{
	static bool show_password = false;
	static std::string server_type_preview;

	if (LauncherImGui::BeginModal(name, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::TextWrapped("Editing Account %s", Preview().c_str());
		ImGui::Spacing();

		ImGui::InputText("Account Name", &Account);
		ImGui::Spacing();

		ServerType.Combo(server_type_preview, [this]
		{
				Account.clear();
				Password.clear();
			});

		ImGui::Spacing();

		ImGuiInputTextFlags flags = ImGuiInputTextFlags_None;
		if (!show_password) flags |= ImGuiInputTextFlags_Password;
		ImGui::InputText("Password", &Password, flags);
		ImGui::Spacing();

		ImGui::Checkbox("Show password", &show_password);
		ImGui::Spacing();

		DefaultModalButtons(ok_action);

		LauncherImGui::EndModal();
	}
}

void AccountInfo::Combo(std::string& preview, Action select_action)
{
	DefaultCombo(preview, *this,
		select_action,
		[this]
		{
			if (!Account.empty() && !Password.empty() && !ServerType.ServerType.empty())
			{
				ProfileRecord profile;
				profile.accountName = Account;
				profile.accountPassword = Password;
				profile.serverType = ServerType.ServerType;

				login::db::CreateAccount(profile);
			}
		});
}

void AccountInfo::ListBox()
{
	static AccountInfo info;
	DefaultListBox(*this, info,
		[]
		{
			ProfileRecord record;
			record.accountName = info.Account;
			record.serverType = info.ServerType.ServerType;
			record.accountPassword = info.Password;
			login::db::CreateAccount(record);
		},
		[this]
		{
			ProfileRecord record;
			record.accountName = info.Account;
			record.serverType = info.ServerType.ServerType;
			record.accountPassword = info.Password;
			login::db::UpdateAccount(Account, ServerType.ServerType, record);
		},
		[this]
		{
			login::db::DeleteAccount(Account, ServerType.ServerType);
		});
}

#pragma endregion

#pragma region Character

void CharacterInfo::List(Action select_action)
{
	fmt::memory_buffer buf;
	const auto buf_ins = std::back_inserter(buf);

	for (const auto& [server, character] : login::db::ListCharacters(Account.Account, Account.ServerType.ServerType))
	{
		ImGui::PushID(character.c_str());
		ImGui::PushID(server.c_str());

		const bool is_selected = ci_equals(character, Character) &&
			ci_equals(server, Server);

		format_to(buf_ins, "{} : {}", character, server);

		if (ImGui::Selectable("", is_selected, ImGuiSelectableFlags_SpanAvailWidth))
		{
			Character = character;
			Server = server;

			select_action();
		}

		if (is_selected)
			ImGui::SetItemDefaultFocus();

		ImGui::Text("%.*s", static_cast<int>(buf.size()), buf.data());

		buf.clear();

		ImGui::PopID();
		ImGui::PopID();
	}
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
}

std::string CharacterInfo::Preview() const
{
	return fmt::format("{} : {}", Character, Server);
}

void CharacterInfo::Edit(const char* name, Action ok_action)
{
	static std::string account_preview;

	if (LauncherImGui::BeginModal(name, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::TextWrapped("Editing Character %s", Preview().c_str());
		ImGui::Spacing();

		Account.Combo(account_preview, [this]
		{
				Server.clear();
				Character.clear();
			});
		ImGui::Spacing();

		ImGui::InputText("Server", &Server);
		ImGui::Spacing();

		ImGui::InputText("Name", &Character);
		ImGui::Spacing();

		DefaultModalButtons(ok_action);

		LauncherImGui::EndModal();
	}
}

void CharacterInfo::Combo(std::string& preview, Action select_action)
{
	DefaultCombo(preview, *this,
		select_action,
		[this]
		{
			if (!Character.empty() && !Server.empty() && !Account.Account.empty() && !Account.ServerType.ServerType.empty())
			{
				ProfileRecord profile;
				profile.characterName = Character;
				profile.serverName = Server;
				profile.accountName = Account.Account;
				profile.serverType = Account.ServerType.ServerType;

				login::db::CreateCharacter(profile);
			}
		});
}

void CharacterInfo::ListBox()
{
	static CharacterInfo info;
	DefaultListBox(*this, info,
		[]
		{
			ProfileRecord record;
			record.accountName = info.Account.Account;
			record.serverType = info.Account.ServerType.ServerType;
			record.serverName = info.Server;
			record.characterName = info.Character;

			login::db::CreateCharacter(record);
		},
		[this]
		{
			ProfileRecord record;
			record.accountName = info.Account.Account;
			record.serverType = info.Account.ServerType.ServerType;
			record.serverName = info.Server;
			record.characterName = info.Character;

			login::db::UpdateCharacter(Server, Character, record);
		},
		[this]
		{
			login::db::DeleteCharacter(Server, Character);
		});
}

void CharacterTable(const std::string_view search)
{
	static CharacterInfo info;
	static ProfileRecord selected;
	static std::string remove_message;

	if (ImGui::BeginTable("Main List", 6, ImGuiTableFlags_SizingStretchProp | ImGuiTableFlags_Borders | ImGuiTableFlags_NoBordersInBody))
	{
		ImGui::TableSetupColumn("Account");
		ImGui::TableSetupColumn("Server Type");
		ImGui::TableSetupColumn("Server");
		ImGui::TableSetupColumn("Character");
		ImGui::TableSetupColumn("Persona");
		ImGui::TableSetupColumn("##buttons");
		ImGui::TableHeadersRow();

		for (const auto& match : login::db::ListCharacterMatches(search))
		{
			ImGui::PushID(match.serverName.c_str());
			ImGui::PushID(match.characterName.c_str());

			ImGui::TableNextRow();
			ImGui::TableNextColumn();

			// this allows right-clicking
			bool is_selected = false;
			ImGui::Selectable("", &is_selected, ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_AllowOverlap);
			if (ImGui::IsItemHovered() && ImGui::IsItemClicked(ImGuiMouseButton_Right))
				ImGui::OpenPopup("row_popup");

			if (ImGui::BeginPopup("row_popup"))
			{
				if (ImGui::Selectable("Edit"))
				{
					info.Server = match.serverName;
					info.Character = match.characterName;
					info.Account.Account = match.accountName;
					info.Account.ServerType.ServerType = match.serverType;

					selected = match;

					LauncherImGui::OpenModal("Edit Character");
				}

				if (ImGui::Selectable("Remove"))
				{
					remove_message = fmt::format("Are you certain you want to remove character '{} : {}'? All associated profiles will also be removed.", match.characterName, match.serverName);
					selected = match;
					LauncherImGui::OpenModal("Remove Character");
				}

				ImGui::EndPopup();
			}

			ImGui::SameLine();
			ImGui::Text(match.accountName.c_str());

			ImGui::TableNextColumn();
			ImGui::Text(match.serverType.c_str());

			ImGui::TableNextColumn();
			ImGui::Text(match.serverName.c_str());

			ImGui::TableNextColumn();
			ImGui::Text(match.characterName.c_str());

			ImGui::TableNextColumn();
			if (match.characterClass.empty())
				ImGui::Text("<None>");
			else
				ImGui::Text("%s %d", match.characterClass.c_str(), match.characterLevel);

			ImGui::TableNextColumn();
			if (ImGui::SmallButton("Play"))
			{
				LoginInstance instance;
				instance.Server = match.serverName;
				instance.Character = match.characterName;

				LoadCharacter(instance);
			}

			ImGui::SameLine();
			// this needs to be here to handle the fact that hotkey isn't optional
			if (ImGui::SmallButton("..."))
			{
				selected = match;

				LauncherImGui::OpenModal("Play With Params");
			}

			ImGui::PopID();
			ImGui::PopID();
		}

		ImGui::EndTable();
	}

	info.Edit("Edit Character", []
	{
			if (info && info.Account)
			{
				ProfileRecord profile;
				profile.characterName = info.Character;
				profile.serverName = info.Server;
				profile.accountName = info.Account.Account;
				profile.serverType = info.Account.ServerType.ServerType;
				login::db::UpdateCharacter(selected.serverName, selected.characterName, profile);
			}
		});

	DeleteModal("Remove Character", remove_message, []
	{
			login::db::DeleteCharacter(selected.serverName, selected.characterName);
		});

	if (LauncherImGui::BeginModal("Play With Params", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		// input box for hotkey (optional)
		if (ImGui::Button("Hotkey"))
			LauncherImGui::OpenModal("Input Hotkey");

		ShowHotkeyWindow("Input Hotkey", selected.hotkey);

		ImGui::SameLine();
		ImGui::Text("%s", !selected.hotkey.empty() ? selected.hotkey.c_str() : "<None>");

		// input for eq path override (optional)
		if (ImGui::Button("EQ Path"))
			LauncherImGui::OpenModal("Input EQ Path");

		SetEQDirModal(selected.eqPath, [] {});

		ImGui::SameLine();
		ImGui::Text("%s", selected.eqPath ? selected.eqPath->c_str() : "<Default>");

		DefaultModalButtons([]
		{
				LoginInstance instance;
				instance.Server = selected.serverName;
				instance.Character = selected.characterName;
				if (!selected.hotkey.empty()) instance.Hotkey = selected.hotkey;
				instance.EQPath = selected.eqPath;

				LoadCharacter(instance);
			});

		LauncherImGui::EndModal();
	}
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
	return fmt::format("[{}] {} : {}", profileName, Character.Character, Character.Server);
}

void ProfileInfo::Edit(const char* name, Action ok_action)
{
	static std::string account_preview;
	static std::string character_preview;

	if (LauncherImGui::BeginModal(name, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		Character.Account.Combo(account_preview, [this]
		{
				Character.Character.clear();
				Character.Server.clear();
				character_preview.clear();
			});

		// drop down for character or create new, only show this if an account has been selected
		if (Character.Account)
		{
			Character.Combo(character_preview, [this]
			{
					if (Character && !profileName.empty())
						login::db::ReadProfile(*this);
				});

			// display options to complete the profile only if the profile has a character
			if (Character)
			{
				if (ImGui::Button("Hotkey"))
					LauncherImGui::OpenModal("Input Hotkey");

				ShowHotkeyWindow("Input Hotkey", hotkey);

				ImGui::SameLine();
				ImGui::Text("%s", !hotkey.empty() ? hotkey.c_str() : "<None>");

				if (ImGui::Button("EQ Path"))
					LauncherImGui::OpenModal("Input EQ Path");

				SetEQDirModal(eqPath, [] {});

				ImGui::SameLine();
				ImGui::Text("%s", eqPath ? eqPath->c_str() : "<Default>");
			}
		}

		DefaultModalButtons(ok_action);

		LauncherImGui::EndModal();
	}
}

void ProfileTable(const ProfileGroupInfo& info)
{
	static ProfileInfo selected;
	static std::string remove_message;

	if (ImGui::BeginTable("Main List", 7, ImGuiTableFlags_SizingStretchProp | ImGuiTableFlags_Borders | ImGuiTableFlags_NoBordersInBody))
	{
		if (!info.profileName.empty())
		{
			ImGui::TableSetupColumn("Account");
			ImGui::TableSetupColumn("Server Type");
			ImGui::TableSetupColumn("Server");
			ImGui::TableSetupColumn("Character");
			ImGui::TableSetupColumn("Persona");
			ImGui::TableSetupColumn("Hotkey");
			ImGui::TableSetupColumn("##play");
			ImGui::TableHeadersRow();

			for (auto& profile : login::db::GetProfiles(info.profileName))
			{
				ImGui::PushID(&profile);

				ImGui::TableNextRow();
				ImGui::TableNextColumn();
				if (ImGui::Selectable("", profile.checked, ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_AllowOverlap))
					login::db::UpdateProfile(profile);

				if (ImGui::IsItemHovered() && ImGui::IsItemClicked(ImGuiMouseButton_Right))
					ImGui::OpenPopup("row_popup");

				if (ImGui::BeginPopup("row_popup"))
				{
					if (ImGui::Selectable("Edit"))
					{
						selected.ProfileRecord::operator=(profile);
						selected.Character.Character = profile.characterName;
						selected.Character.Server = profile.serverName;
						selected.Character.Account.Account = profile.accountName;
						selected.Character.Account.ServerType.ServerType = profile.serverType;
						LauncherImGui::OpenModal("Edit Profile");
					}

					if (ImGui::Selectable("Remove"))
					{
						selected.ProfileRecord::operator=(profile);
						selected.Character.Character = profile.characterName;
						selected.Character.Server = profile.serverName;
						remove_message = fmt::format("Are you sure you want to remove profile '{}'?", info.Preview());
						LauncherImGui::OpenModal("Remove Profile");
					}

					ImGui::EndPopup();
				}

				ImGui::SameLine();
				ImGui::Text(profile.accountName.c_str());

				ImGui::TableNextColumn();
				ImGui::Text(profile.serverType.c_str());

				ImGui::TableNextColumn();
				ImGui::Text(profile.serverName.c_str());

				ImGui::TableNextColumn();
				ImGui::Text(profile.characterName.c_str());

				ImGui::TableNextColumn();
				if (profile.characterClass.empty())
					ImGui::Text("<None>");
				else
					ImGui::Text("%s %d", profile.characterClass.c_str(), profile.characterLevel);

				ImGui::TableNextColumn();
				ImGui::Text(profile.hotkey.c_str());

				ImGui::TableNextColumn();
				if (ImGui::SmallButton("Play"))
				{
					LoginInstance instance;
					instance.ProfileGroup = profile.profileName;
					instance.Server = profile.serverName;
					instance.Character = profile.characterName;
					if (!profile.hotkey.empty()) instance.Hotkey = profile.hotkey;

					LoadCharacter(instance);
				}

				ImGui::PopID();
			}
		}

		ImGui::EndTable();
	}

	if (ImGui::Button("Add Profile"))
	{
		LauncherImGui::OpenModal("Add Profile");
	}

	selected.Edit("Add Profile", []
	{
			if (selected)
			{
				selected.characterName = selected.Character.Character;
				selected.serverName = selected.Character.Server;
				selected.accountName = selected.Character.Account.Account;
				selected.serverType = selected.Character.Account.ServerType.ServerType;
				login::db::CreateProfile(selected);
			}
		});

	selected.Edit("Edit Profile", []
	{
			if (selected)
			{
				selected.characterName = selected.Character.Character;
				selected.serverName = selected.Character.Server;
				login::db::UpdateProfile(selected);
			}
		});

	DeleteModal("Remove Profile", remove_message, []
	{
			login::db::DeleteProfile(
				selected.serverName,
				selected.characterName,
				selected.profileName);
		});
}

#pragma endregion

#pragma region ProfileGroupInfo

void ProfileGroupInfo::List(Action select_action)
{
	for (const auto& group : login::db::ListProfileGroups())
	{
		ImGui::PushID(group.c_str());

		const bool is_selected = ci_equals(group, profileName);
		if (ImGui::Selectable(group.c_str(), is_selected))
		{
			profileName = group;
			select_action();
		}

		if (is_selected)
			ImGui::SetItemDefaultFocus();

		ImGui::PopID();
	}
}

void ProfileGroupInfo::Fill()
{
	login::db::ReadProfileGroup(*this);
}

std::string ProfileGroupInfo::Preview() const
{
	return profileName;
}

void ProfileGroupInfo::Edit(const char* name, Action ok_action)
{
	if (LauncherImGui::BeginModal(name, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::InputText("Profile Group Name", &profileName);

		ImGui::Spacing();
		if (ImGui::Button("EQ Path"))
			LauncherImGui::OpenModal("Input EQ Path");

		SetEQDirModal(eqPath, [] {});

		ImGui::SameLine();
		ImGui::Text("%s", eqPath ? eqPath->c_str() : "<Default>");

		DefaultModalButtons(ok_action);

		LauncherImGui::EndModal();
	}
}

void ProfileGroupInfo::Combo(std::string& preview, Action select_action)
{
	DefaultCombo(preview, *this,
		select_action,
		[this]
		{
			if (!profileName.empty())
			{
				login::db::CreateProfileGroup(*this);
			}
		});
}

void ProfileGroupInfo::ListBox()
{
	static ProfileGroupInfo info;
	DefaultListBox(*this, info,
		[]
		{
			login::db::CreateProfileGroup(info);
		},
		[this]
		{
			login::db::UpdateProfileGroup(profileName, info);
		},
		[this]
		{
			login::db::DeleteProfileGroup(profileName);
		});
}

#pragma endregion

// TODO: Add settings section
// TODO: Add master password window button (in settings)
// TODO: Add default path editor (per server type, in settings)
void ShowAutoLoginWindow()
{
	ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.f);

	if (ImGui::BeginTabBar("Main Tab Bar", ImGuiTabBarFlags_FittingPolicyResizeDown))
	{
		const auto tab_size = ImGui::GetContentRegionMax().x * 0.33f;
		ImGui::SetNextItemWidth(tab_size);
		if (ImGui::BeginTabItem("Profiles"))
		{
			static ProfileGroupInfo info;
			// Code goes into this scope for selecting and modifying profiles/groups
			ImGui::BeginChild("Main Child", ImVec2(0, 0), ImGuiChildFlags_Border, ImGuiWindowFlags_MenuBar);

			if (ImGui::BeginMenuBar())
			{
				if (ImGui::SmallButton("Create"))
				{
					LauncherImGui::OpenModal("Create Profile Group");
				}

				info.Edit("Create Profile Group", []
				{
						login::db::CreateProfileGroup(info);
					});

				static std::string remove_message;
				if (ImGui::SmallButton("Remove") && !info.profileName.empty())
				{
					remove_message = fmt::format("Are you sure you want to remove profile group '{}'? All associated profiles will also be removed.", info.profileName.c_str());
					LauncherImGui::OpenModal("Remove Profile Group");
				}

				DeleteModal("Remove Profile Group", remove_message, []
				{
						login::db::DeleteProfileGroup(info.profileName);
						info.profileName.clear();
					});

				ImGui::EndMenuBar();
			}

			ImGui::SetNextItemWidth(ImGui::GetContentRegionMax().x -
				ImGui::CalcTextSize("Launch Group").x -
				ImGui::GetStyle().FramePadding.x * 2 -
				ImGui::GetStyle().ItemSpacing.x -
				ImGui::GetStyle().WindowPadding.x);
			info.Combo(info.profileName, [] {});

			ImGui::SameLine();
			if (ImGui::Button("Launch Group") && !info.profileName.empty())
			{
				LoadProfileGroup(info.profileName);
			}

			if (!info.profileName.empty()) ProfileTable(info);

			ImGui::EndChild();
			ImGui::EndTabItem();
		}

		ImGui::SetNextItemWidth(tab_size);
		if (ImGui::BeginTabItem("Characters"))
		{
			ImGui::BeginChild("Main Child", ImVec2(0, 0), ImGuiChildFlags_Border, ImGuiWindowFlags_MenuBar);

			static std::string search;
			static CharacterInfo info;

			ImGui::SetNextItemWidth(ImGui::GetContentRegionMax().x -
				ImGui::CalcTextSize("Add Character").x -
				ImGui::GetStyle().FramePadding.x * 2 -
				ImGui::GetStyle().ItemSpacing.x -
				ImGui::GetStyle().WindowPadding.x);
			ImGui::InputText("##Search Bar", &search, ImGuiInputTextFlags_EscapeClearsAll);

			ImGui::SameLine();
			if (ImGui::Button("Add Character"))
			{
				// reset to defaults
				info = {};
				LauncherImGui::OpenModal("Add Character");
			}

			info.Edit("Add Character", []
			{
					ProfileRecord profile;
					profile.characterName = info.Character;
					profile.serverName = info.Server;
					profile.accountName = info.Account.Account;
					profile.serverType = info.Account.ServerType.ServerType;
					login::db::CreateCharacter(profile);
				});

			CharacterTable(search);

			ImGui::EndChild();
			ImGui::EndTabItem();
		}

		ImGui::SetNextItemWidth(tab_size);
		if (ImGui::BeginTabItem("Settings"))
		{
			ImGui::EndTabItem();
		}

		ImGui::EndTabBar();
	}

	ImGui::PopStyleVar();
}

struct SizedProfileRecord
{
	ProfileRecord Profile;
	std::string LevelText;
	float LevelSize;
	float ClassSize;
};

void ShowAutoLoginMenu()
{
	bool is_paused = false;
	if (const auto raw_pause = login::db::ReadSetting("is_paused"))
		is_paused = GetBoolFromString(*raw_pause, false);

	ImGui::PushItemFlag(ImGuiItemFlags_SelectableDontClosePopup, true);
	if (ImGui::MenuItem(fmt::format("AutoLogin is {}", is_paused ? "Paused" : "Running").c_str()))
		login::db::WriteSetting("is_paused", !is_paused ? "true" : "false");
	ImGui::PopItemFlag();

	if (ImGui::BeginMenu("Quick Launch"))
	{
		if (ImGui::MenuItem("Without Login"))
			LaunchCleanSession();

		if (ImGui::BeginMenu("Profiles"))
		{
			for (const auto& group : login::db::ListProfileGroups())
			{
				ImGui::PushID(group.c_str());

				if (ImGui::BeginMenu(group.c_str()))
				{
					std::vector<SizedProfileRecord> profiles;
					float largest_level = 0.f;
					float largest_class = 0.f;

					for (auto& profile : login::db::GetProfiles(group))
					{
						auto level_text = fmt::format("{}", profile.characterLevel);
						const auto level_size = ImGui::CalcTextSize(level_text.c_str()).x;
						if (level_size > largest_level) largest_level = level_size;

						const auto class_size = ImGui::CalcTextSize(profile.characterClass.c_str()).x;
						if (class_size > largest_class) largest_class = class_size;

						profiles.emplace_back(SizedProfileRecord{
							profile,
							std::move(level_text),
							level_size,
							class_size
							});
					}

					for (auto& [profile, level_text, level_size, class_size] : profiles)
					{
						ImGui::PushID(&profile);

						if (LauncherImGui::SmallCheckbox("##checked", &profile.checked))
							login::db::UpdateProfile(profile);

						ImGui::SameLine();
						if (ImGui::Selectable("[", false, ImGuiSelectableFlags_SelectOnRelease | ImGuiSelectableFlags_NoSetKeyOwner | ImGuiSelectableFlags_SetNavIdOnHover | ImGuiSelectableFlags_SpanAvailWidth))
						{
							LoginInstance instance;
							instance.ProfileGroup = group;
							instance.Server = profile.serverName;
							instance.Character = profile.characterName;
							if (!profile.hotkey.empty()) instance.Hotkey = profile.hotkey;

							LoadCharacter(instance);
						}

						ImGui::SameLine(0, largest_level - level_size);
						ImGui::TextUnformatted(level_text.c_str());

						ImGui::SameLine(); ImGui::TextUnformatted(" ");

						ImGui::SameLine(0, largest_class - class_size);
						ImGui::TextUnformatted(profile.characterClass.c_str());

						ImGui::SameLine(0, 0); ImGui::Text("] %s ", profile.characterName.c_str());

						ImGui::PopID();
					}

					ImGui::EndMenu();
				}

				if (ImGui::IsItemClicked(ImGuiMouseButton_Left))
					LoadProfileGroup(group);

				ImGui::PopID();
			}
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Characters"))
		{
			for (const auto& server : login::db::ListServers())
			{
				ImGui::PushID(server.c_str());

				if (ImGui::BeginMenu(server.c_str()))
				{
					std::vector<SizedProfileRecord> profiles;
					float largest_level = 0.f;
					float largest_class = 0.f;

					for (auto& profile : login::db::ListCharactersOnServer(server))
					{
						auto level_text = fmt::format("{}", profile.characterLevel);
						const auto level_size = ImGui::CalcTextSize(level_text.c_str()).x;
						if (level_size > largest_level) largest_level = level_size;

						const auto class_size = ImGui::CalcTextSize(profile.characterClass.c_str()).x;
						if (class_size > largest_class) largest_class = class_size;

						profiles.emplace_back(SizedProfileRecord{
							profile,
							std::move(level_text),
							level_size,
							class_size
							});
					}

					for (auto& [profile, level_text, level_size, class_size] : profiles)
					{
						ImGui::PushID(&profile);

						if (ImGui::Selectable("[", false, ImGuiSelectableFlags_SelectOnRelease | ImGuiSelectableFlags_NoSetKeyOwner | ImGuiSelectableFlags_SetNavIdOnHover | ImGuiSelectableFlags_SpanAvailWidth))
						{
							LoginInstance instance;
							instance.Server = profile.serverName;
							instance.Character = profile.characterName;

							LoadCharacter(instance);
						}

						ImGui::SameLine(0, largest_level - level_size);
						ImGui::TextUnformatted(level_text.c_str());

						ImGui::SameLine(); ImGui::TextUnformatted(" ");

						ImGui::SameLine(0, largest_class - class_size);
						ImGui::TextUnformatted(profile.characterClass.c_str());

						ImGui::SameLine(0, 0); ImGui::Text("] %s ", profile.characterName.c_str());

						ImGui::PushStyleVar(ImGuiStyleVar_Alpha, ImGui::GetStyle().Alpha * 0.25f);
						ImGui::SameLine(); ImGui::Text("%s (%s)", profile.accountName.c_str(), profile.serverType.c_str());
						ImGui::PopStyleVar();

						ImGui::PopID();
					}

					ImGui::EndMenu();
				}

				ImGui::PopID();
			}

			ImGui::EndMenu();
		}

		ImGui::EndMenu();
	}
}

bool ShowPasswordWindow()
{
	bool is_open = true;
	ImGui::SetNextWindowPos(ImGui::GetMainViewport()->GetCenter(), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));

	if (ImGui::Begin("Enter Master Password", &is_open, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings))
	{
		static std::string label = "Please Enter Master Password";

		ImGui::SetCursorPosX(std::max(0.f, ImGui::GetContentRegionAvail().x / 2.f - ImGui::CalcTextSize(label.c_str()).x / 2.f));
		ImGui::Text(label.c_str());
		ImGui::Spacing();

		static bool show_password = false;
		static bool perpetual_password = false;
		static std::string password;

		ImGuiInputTextFlags flags = ImGuiInputTextFlags_None;
		if (!show_password) flags |= ImGuiInputTextFlags_Password;

		ImGui::InputText("##password", &password, flags);
		ImGui::Separator();

		ImGui::BeginDisabled(perpetual_password);
		int num_hours = 720; // 720 hours is 30 days
		if (const auto hours = login::db::ReadSetting("password_timeout_hours"))
			num_hours = GetIntFromString(*hours, num_hours);
		const std::string hours_label = fmt::format("Hours to Save ({:.1f} days)", static_cast<float>(num_hours) / 24.f);

		ImGui::SetCursorPosX(std::max(0.f, ImGui::GetContentRegionAvail().x / 2.f - ImGui::CalcTextSize(hours_label.c_str()).x / 2.f));
		ImGui::Text(hours_label.c_str());
		if (ImGui::InputInt("##hours", &num_hours))
		{
			login::db::WriteSetting(
				"password_timeout_hours",
				std::to_string(num_hours),
				"Number of hours before master password times out");
		}
		ImGui::SetItemTooltip("Number of hours to save this password before requiring re-entry.");
		ImGui::EndDisabled();
		ImGui::Separator();

		ImGui::Checkbox("Show password", &show_password);
		ImGui::SetItemTooltip("Show the password in plain text");
		ImGui::SameLine();
		ImGui::Checkbox("Never ask again", &perpetual_password);
		ImGui::SetItemTooltip("Save the password to this system so that it never has to be entered again.");
		ImGui::Spacing();

		if (ImGui::Button("Retrieve"))
			if (const auto pass = login::db::ReadStoredMasterPass())
				password = *pass;
		ImGui::SetItemTooltip("Retrieve the stored password from the system registry if present.");

		ImGui::SameLine();

		if (ImGui::Button("Reset Stored"))
			login::db::DeleteSetting("master_pass");
		ImGui::SetItemTooltip("Reset the stored master mass in the database, allowing a new master pass to be set.");

		ImGui::SameLine();

		ImGui::SetCursorPosX(ImGui::GetContentRegionMax().x - ImGui::CalcTextSize("  OK  ").x - ImGui::GetStyle().FramePadding.x * 2);
		if (ImGui::Button("  OK  "))
		{
			if (!login::db::ReadSetting("master_pass") || login::db::ValidatePass(password))
			{
				if (!perpetual_password)
					login::db::CreateMasterPass(password, num_hours);
				else
					login::db::CreateMasterPass(password, 0);

				is_open = false;
				label = "Please Enter Master Password";

				// do this here because doing it before will attempt to read/write passwords without the master pass
				if (const auto load_ini = login::db::ReadSetting("load_ini"); !load_ini || GetBoolFromString(*load_ini, false))
				{
					Import();
					login::db::WriteSetting("load_ini", "false", "Import data from autologin ini file one time");
				}
			}
			else
			{
				label = "Incorrect Password, Please Enter Master Password";
			}
		}
		ImGui::SetItemTooltip("Attempt to validate the entered password against the database, or set it if it does not exist.");
	}

	ImGui::End();
	return is_open;
}

}

#pragma endregion

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
	if (!login::db::ReadMasterPass())
		LauncherImGui::OpenWindow(&ShowPasswordWindow, "Enter Master Password");
	else if (const auto load_ini = login::db::ReadSetting("load_ini"); !load_ini || GetBoolFromString(*load_ini, false))
	{
		Import();
		login::db::WriteSetting("load_ini", "false", "Import data from autologin ini file one time");
	}

	// Initialize path to EQ
	if (const auto eq_path = login::db::GetPathFromServerType(GetServerType()))
		internal_paths::s_eqRoot = *eq_path;

	if (internal_paths::s_eqRoot.empty())
	{
		SPDLOG_ERROR("AutoLogin Error no EQ path specified, AutoLogin will not work correctly.");
	}

	LauncherImGui::AddMainPanel("AutoLogin", ShowAutoLoginWindow);
	LauncherImGui::AddContextGroup("AutoLogin Menu", ShowAutoLoginMenu);
}

void ShutdownAutoLogin()
{
	s_dropbox.Remove();

	if (s_eqDirDialog != nullptr)
		IGFD_Destroy(s_eqDirDialog);

}
