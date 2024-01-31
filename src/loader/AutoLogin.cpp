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

	mq::proto::login::LoginMessage message;
	message.set_id(mq::proto::login::StartInstance);
	message.set_payload(start.SerializeAsString());

	mq::proto::routing::Address address;
	address.set_name("launcher");
	address.set_mailbox("autologin");

	s_dropbox.Post(address, message);
}
}

void AutoLoginRemoveProcess(const DWORD process_id)
{
	proto::login::StopInstanceMissive stop;
	stop.set_pid(process_id);

	mq::proto::login::LoginMessage message;
	message.set_id(mq::proto::login::ProfileUnloaded);
	message.set_payload(stop.SerializeAsString());

	mq::proto::routing::Address address;
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
	::CreateProcessA(nullptr, parameters.data(), nullptr, nullptr, FALSE, 0, nullptr, internal_paths::s_eqRoot.c_str(), &si, &pi);
}
}

#pragma region ImGui

namespace {
bool ToggleSlider(const char* label, bool* v)
{
	const ImVec4* colors = ImGui::GetStyle().Colors;
	const ImVec2 position = ImGui::GetCursorScreenPos();
	ImDrawList* draw_list = ImGui::GetWindowDrawList();

	const float height = ImGui::GetFrameHeight();
	const float width = height * 1.55f;
	const float radius = height * 0.5f;

	const bool ret = ImGui::InvisibleButton(label, ImVec2(width, height));
	if (ImGui::IsItemClicked()) *v = !*v;

	float t = *v ? 1.f : 0.f;

	if (const ImGuiContext* g = ImGui::GetCurrentContext(); g->LastActiveId == g->CurrentWindow->GetID(label))
	{
		constexpr float animation_speed = 8.5f;
		const float t_anim = ImSaturate(g->LastActiveIdTimer * animation_speed);
		t = *v ? t_anim : (1.f - t_anim);
	}

	const ImU32 bg_color = ImGui::GetColorU32(colors[ImGuiCol_Text]);

	ImU32 fg_color;
	if (ImGui::IsItemClicked())
		fg_color = ImGui::GetColorU32(colors[ImGuiCol_ButtonActive]);
	else if (ImGui::IsItemHovered())
		fg_color = ImGui::GetColorU32(colors[ImGuiCol_ButtonHovered]);
	else
		fg_color = ImGui::GetColorU32(colors[ImGuiCol_Button]);

	draw_list->AddRectFilled(position, ImVec2(position.x + width, position.y + height), bg_color, height * 0.5f);
	draw_list->AddCircleFilled(ImVec2(position.x + radius + t * (width - radius * 2.f), position.y + radius), radius - 1.5f, fg_color);

	return ret;
}

float ButtonWidth(const char* text)
{
	return ImGui::GetStyle().FramePadding.x * 2 + ImGui::CalcTextSize(text).x;// +ImGui::GetStyle().WindowPadding.x;
}

void SetEQDir(std::optional<std::string>& eq_path)
{
	ImGui::PushID("EQ Dir");

	std::string eqDir;
	if (eq_path)
		eqDir = *eq_path;
	else
		eqDir = internal_paths::s_eqRoot;

	ImGui::InputText("EQ Dir", eqDir.data(), eqDir.size(), ImGuiInputTextFlags_ReadOnly);

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
				eq_path = std::filesystem::canonical(std::filesystem::path(selected_path.get()), ec).string();
			}
		}

		IGFD_CloseDialog(s_eqDirDialog);
	}

	ImGui::PopID();
}

void ShowAccountWindow(std::optional<std::pair<std::string, std::string>>& selected)
{
	// declare account statics
	static bool show_password = false;
	static std::string password;
	static std::string account_name;
	static std::string server_type_name;
	static std::optional<std::string> server_eq_path;

	ImGui::PushID("Accounts List");
	ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
	if (ImGui::BeginListBox("Accounts List"))
	{
		static auto buf = [](const size_t size)
			{
				fmt::memory_buffer buffer;
				buffer.reserve(size);

				return buffer;
			}(256);

		static auto buf_ins = std::back_inserter(buf);

		for (const auto& [account, server_type] : login::db::ListAccounts())
		{
			ImGui::PushID(account.c_str());
			ImGui::PushID(server_type.c_str());

			const bool is_selected = selected &&
				ci_equals(account, selected->first) &&
				ci_equals(server_type, selected->second);

			fmt::format_to(buf_ins, "{} ({})", account, server_type);

			if (ImGui::Selectable("", is_selected, ImGuiSelectableFlags_SpanAvailWidth))
				selected = std::make_pair(account, server_type);

			if (is_selected) ImGui::SetItemDefaultFocus();

			ImGui::SameLine();
			ImGui::Text("%.*s", static_cast<int>(buf.size()), buf.data());

			buf.clear();

			ImGui::PopID();
			ImGui::PopID();
		}

		ImGui::EndListBox();
	}
	ImGui::PopID();

	if (selected)
	{
		if (ImGui::IsKeyPressed(ImGuiKey_Delete)) LauncherImGui::OpenModal("Delete Account");

		if (ImGui::IsKeyPressed(ImGuiKey_Enter))
		{
			if (const auto pass = login::db::ReadPassword(selected->first, selected->second))
				password = *pass;

			LauncherImGui::OpenModal("Edit Account");
		}

		if (ImGui::IsKeyPressed(ImGuiKey_Escape)) selected = {};
	}

	if (selected && LauncherImGui::BeginModal("Delete Account", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::PushID("Delete Account Modal");

		ImGui::TextWrapped("Are you sure you want to delete account '%s (%s)'? All associated characters and profiles will also be removed.", selected->first.c_str(), selected->second.c_str());
		ImGui::Spacing();

		if (ImGui::Button("Yes", ImVec2(120, 0)))
		{
			login::db::DeleteAccount(selected->first, selected->second);
			selected = {};
			LauncherImGui::CloseModal();
		}

		ImGui::SetItemDefaultFocus();
		ImGui::SameLine();
		if (ImGui::Button("No", ImVec2(120, 0)))
		{
			LauncherImGui::CloseModal();
		}

		ImGui::PopID();
		LauncherImGui::EndModal();
	}

	if (selected && LauncherImGui::BeginModal("Edit Account", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::PushID("Edit Account Modal");

		ImGui::TextWrapped("Update account '%s (%s)':", selected->first.c_str(), selected->second.c_str());
		ImGui::Spacing();

		ImGui::InputText("Account Name", &account_name);
		ImGui::Spacing();

		if (ImGui::BeginCombo("Server Type", server_type_name.c_str()))
		{
			for (const auto& server_type : login::db::ListServerTypes())
			{
				const bool is_selected = ci_equals(server_type, server_type_name);
				if (ImGui::Selectable(server_type.c_str(), is_selected))
					server_type_name = server_type;

				if (is_selected)
					ImGui::SetItemDefaultFocus();
			}
			ImGui::EndCombo();
		}

		ImGui::SameLine();
		if (ImGui::Button("..."))
		{
			server_eq_path = login::db::GetPathFromServerType(server_type_name);
			LauncherImGui::OpenModal("Server Type");
		}

		ImGui::Spacing();

		ImGuiInputTextFlags flags = ImGuiInputTextFlags_None;
		if (!show_password) flags |= ImGuiInputTextFlags_Password;
		ImGui::InputText("##password", &password, flags);
		ImGui::Spacing();

		ImGui::Checkbox("Show password", &show_password);
		ImGui::Spacing();

		if (ImGui::Button("OK", ImVec2(120, 0)))
		{
			ProfileRecord record;
			record.accountName = account_name;
			record.serverType = server_type_name;
			record.accountPassword = password;
			login::db::UpdateAccount(selected->first, selected->second, record);
			selected = std::make_pair(account_name, server_type_name);
			LauncherImGui::CloseModal();
		}

		ImGui::SetItemDefaultFocus();
		ImGui::SameLine();
		if (ImGui::Button("Cancel", ImVec2(120, 0)))
		{
			LauncherImGui::CloseModal();
		}

		ImGui::PopID();
		LauncherImGui::EndModal();
	}

	if (LauncherImGui::BeginModal("Create Account", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::PushID("Create Account Modal");

		ImGui::TextWrapped("Create a new account, or update existing account.");
		ImGui::Spacing();

		ImGui::InputText("Account Name", &account_name);
		ImGui::Spacing();

		ImGui::PushID("Choose Type");
		if (ImGui::BeginCombo("##Choose Type", server_type_name.c_str()))
		{
			for (const auto& server_type : login::db::ListServerTypes())
			{
				const bool is_selected = ci_equals(server_type, server_type_name);
				if (ImGui::Selectable(server_type.c_str(), is_selected))
					server_type_name = server_type;

				if (is_selected)
					ImGui::SetItemDefaultFocus();
			}
			ImGui::EndCombo();
		}
		ImGui::PopID();

		ImGui::SameLine();
		if (ImGui::Button("..."))
		{
			server_eq_path = login::db::GetPathFromServerType(server_type_name);
			LauncherImGui::OpenModal("Server Type");
		}

		ImGui::Spacing();

		ImGuiInputTextFlags flags = ImGuiInputTextFlags_None;
		if (!show_password) flags |= ImGuiInputTextFlags_Password;
		ImGui::InputText("##password", &password, flags);
		ImGui::Spacing();


		ImGui::Checkbox("Show password", &show_password);
		ImGui::Spacing();

		if (ImGui::Button("OK", ImVec2(120, 0)))
		{
			ProfileRecord record;
			record.accountName = account_name;
			record.serverType = server_type_name;
			record.accountPassword = password;
			login::db::CreateAccount(record);
			selected = std::make_pair(account_name, server_type_name);
			LauncherImGui::CloseModal();
		}

		ImGui::SetItemDefaultFocus();
		ImGui::SameLine();
		if (ImGui::Button("Cancel", ImVec2(120, 0)))
		{
			LauncherImGui::CloseModal();
		}

		ImGui::PopID();
		LauncherImGui::EndModal();
	}
	
	if (LauncherImGui::BeginModal("Server Type", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::PushID("Server Type Modal");

		ImGui::Text("Create or select a server type for this account");
		ImGui::Spacing();

		if (ImGui::BeginListBox("Server Types"))
		{
			for (const auto& server_type : login::db::ListServerTypes())
			{
				ImGui::PushID(server_type.c_str());

				const bool is_selected = ci_equals(server_type_name, server_type);
				if (ImGui::Selectable(server_type.c_str(), is_selected))
					server_type_name = server_type;

				if (is_selected)
					ImGui::SetItemDefaultFocus();

				ImGui::SameLine();
				if (ImGui::Button("..."))
				{
					server_type_name = server_type;
					server_eq_path = login::db::GetPathFromServerType(server_type);
					LauncherImGui::OpenModal("Input EQ Path");
				}

				if (LauncherImGui::BeginModal("Input EQ Path", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
				{
					SetEQDir(server_eq_path);

					ImGui::Separator();
					if (ImGui::Button("OK"))
					{
						if (server_eq_path)
							login::db::CreateOrUpdateServerType(server_type_name, *server_eq_path);

						LauncherImGui::CloseModal();
					}

					LauncherImGui::EndModal();
				}

				ImGui::PopID();
			}
			ImGui::EndListBox();
		}

		if (ImGui::Button("New Server Type"))
			LauncherImGui::OpenModal("Create Server Type");

		if (LauncherImGui::BeginModal("Create Server Type", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
		{
			ImGui::PushID("create server type modal");

			ImGui::InputText("Type", &server_type_name);
			ImGui::Spacing();

			if (ImGui::Button("EQ Path"))
				LauncherImGui::OpenModal("Input EQ Path");

			ImGui::SameLine();
			ImGui::Text("%s", server_eq_path ? server_eq_path->c_str() : "");

			if (LauncherImGui::BeginModal("Input EQ Path", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
			{
				SetEQDir(server_eq_path);

				ImGui::Separator();
				if (ImGui::Button("OK"))
					LauncherImGui::CloseModal();

				LauncherImGui::EndModal();
			}

			if (ImGui::Button("OK", ImVec2(120, 0)))
			{
				if (server_eq_path)
				{
					login::db::CreateOrUpdateServerType(server_type_name, *server_eq_path);
					selected = std::make_pair(server_type_name, *server_eq_path);
				}

				LauncherImGui::CloseModal();
			}

			ImGui::SetItemDefaultFocus();
			ImGui::SameLine();
			if (ImGui::Button("Cancel", ImVec2(120, 0)))
			{
				LauncherImGui::CloseModal();
			}

			ImGui::PopID();
			LauncherImGui::EndModal();
		}

		ImGui::PopID();
		LauncherImGui::EndModal();
	}

	if (ImGui::Button("Add Account"))
	{
		if (selected)
		{
			account_name = selected->first;
			server_type_name = selected->second;
		}
		else
		{
			account_name = "";
			server_type_name = "";
		}
		LauncherImGui::OpenModal("Create Account");
	}

	ImGui::SameLine();
	if (ImGui::Button("Edit Account") && selected)
	{
		if (const auto pass = login::db::ReadPassword(selected->first, selected->second))
			password = *pass;

		LauncherImGui::OpenModal("Edit Account");
	}

	ImGui::SameLine();
	if (ImGui::Button("Remove Account") && selected) LauncherImGui::OpenModal("Delete Account");
}

 void ShowCharacterWindow(const std::pair<std::string, std::string>& account, std::optional<std::pair<std::string, std::string>>& selected, std::string& preview)
{
	auto set_selection = [&selected, &preview](const std::pair<std::string, std::string>& character)
		{
			selected = character;
			preview = fmt::format("{} : {}", character.first, character.second);
		};

	static std::string account_name;
	static std::string server_type;
	static std::string server_name;
	static std::string character_name;

	ImGui::PushID("Characters List");
	ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
	if (ImGui::BeginListBox("Characters List"))
	{
		// this avoids a buffer allocation
		static auto buf = [](size_t size)
			{
				fmt::memory_buffer buf;
				buf.reserve(size);

				return buf;
			}(256);

		static auto buf_ins = std::back_inserter(buf);

		for (const auto& character : login::db::ListCharacters(account.first, account.second))
		{
			ImGui::PushID(character.first.c_str());
			ImGui::PushID(character.second.c_str());

			const bool is_selected = selected &&
				ci_equals(character.first, selected->first) &&
				ci_equals(character.second, selected->second);

			fmt::format_to(buf_ins, "{} : {}", character.first, character.second);

			if (ImGui::Selectable("", is_selected, ImGuiSelectableFlags_SpanAvailWidth))
				set_selection(character);

			if (is_selected)
				ImGui::SetItemDefaultFocus();

			ImGui::SameLine();
			ImGui::Text("%.*s", static_cast<int>(buf.size()), buf.data());

			buf.clear();

			ImGui::PopID();
			ImGui::PopID();
		}

		ImGui::EndListBox();
	}
	ImGui::PopID();

	if (selected)
	{
		if (ImGui::IsKeyPressed(ImGuiKey_Delete)) LauncherImGui::OpenModal("Delete Character");

		if (ImGui::IsKeyPressed(ImGuiKey_Enter))
		{
			account_name = account.first;
			server_type = account.second;
			server_name = selected->first;
			character_name = selected->second;

			LauncherImGui::OpenModal("Edit Character");
		}

		if (ImGui::IsKeyPressed(ImGuiKey_Escape)) selected = {};
	}

	if (selected && LauncherImGui::BeginModal("Delete Character", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::PushID("Delete Character Modal");

		ImGui::TextWrapped("Are you sure you want to delete character '%s : %s'? All associated profiles will also be removed.", selected->first.c_str(), selected->second.c_str());
		ImGui::Spacing();

		if (ImGui::Button("Yes", ImVec2(120, 0)))
		{
			login::db::DeleteCharacter(selected->first, selected->second);
			selected = {};
			preview = "";
			LauncherImGui::CloseModal();
		}

		ImGui::SetItemDefaultFocus();
		ImGui::SameLine();
		if (ImGui::Button("No", ImVec2(120, 0)))
		{
			LauncherImGui::CloseModal();
		}

		ImGui::PopID();
		LauncherImGui::EndModal();
	}

	if (LauncherImGui::BeginModal("Edit Character", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::PushID("Edit Character Modal");

		ImGui::InputText("Account", &account_name);
		ImGui::Spacing();

		ImGui::InputText("Server Type", &server_type);
		ImGui::Spacing();

		ImGui::InputText("Server", &server_name);
		ImGui::Spacing();

		ImGui::InputText("Name", &character_name);
		ImGui::Spacing();

		if (ImGui::Button("OK", ImVec2(120, 0)))
		{
			if (selected)
			{
				ProfileRecord record;
				record.accountName = account_name;
				record.serverType = server_type;
				record.serverName = server_name;
				record.characterName = character_name;

				login::db::UpdateCharacter(selected->first, selected->second, record);
				set_selection(std::make_pair(server_name, character_name));
			}

			LauncherImGui::CloseModal();
		}

		ImGui::SetItemDefaultFocus();
		ImGui::SameLine();
		if (ImGui::Button("Cancel", ImVec2(120, 0)))
		{
			LauncherImGui::CloseModal();
		}

		ImGui::PopID();
		LauncherImGui::EndModal();
	}

	if (LauncherImGui::BeginModal("Create Character", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::PushID("Create Character Modal");

		ImGui::InputText("Account", &account_name);
		ImGui::Spacing();

		ImGui::InputText("Server Type", &server_type);
		ImGui::Spacing();

		ImGui::InputText("Server", &server_name);
		ImGui::Spacing();

		ImGui::InputText("Name", &character_name);
		ImGui::Spacing();

		if (ImGui::Button("OK", ImVec2(120, 0)))
		{
			ProfileRecord record;
			record.accountName = account_name;
			record.serverType = server_type;
			record.serverName = server_name;
			record.characterName = character_name;

			login::db::CreateCharacter(record);
			set_selection(std::make_pair(server_name, character_name));

			LauncherImGui::CloseModal();
		}

		ImGui::SetItemDefaultFocus();
		ImGui::SameLine();
		if (ImGui::Button("Cancel", ImVec2(120, 0)))
		{
			LauncherImGui::CloseModal();
		}

		ImGui::PopID();
		LauncherImGui::EndModal();
	}

	if (ImGui::Button("Add Character"))
	{
		account_name = account.first;
		server_type = account.second;
		if (selected)
		{
			server_name = selected->first;
			character_name = selected->second;
		}
		else
		{
			server_name.clear();
			character_name.clear();
		}
		LauncherImGui::OpenModal("Create Character");
	}

	ImGui::SameLine();
	if (ImGui::Button("Edit Character") && selected)
	{
		account_name = account.first;
		server_type = account.second;
		server_name = selected->first;
		character_name = selected->second;

		LauncherImGui::OpenModal("Edit Character");
	}

	ImGui::SameLine();
	if (ImGui::Button("Remove Character") && selected) LauncherImGui::OpenModal("Delete Character");
}

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

void ShowHotkeyWindow(std::optional<std::string>& hotkey)
{
	fmt::memory_buffer buf;
	const auto buf_ins = std::back_inserter(buf);

	if (ImGui::IsKeyDown(ImGuiMod_Ctrl))
		fmt::format_to(buf_ins, "CTRL+");

	if (ImGui::IsKeyDown(ImGuiMod_Shift))
		fmt::format_to(buf_ins, "SHIFT+");

	if (ImGui::IsKeyDown(ImGuiMod_Alt))
		fmt::format_to(buf_ins, "ALT+");

	if (ImGui::IsKeyDown(ImGuiMod_Super))
		fmt::format_to(buf_ins, "WIN+");

	for (const auto& [key, name] : s_hotkeyMap)
	{
		if (ImGui::IsKeyDown(key))
		{
			fmt::format_to(buf_ins, name);
			hotkey = fmt::to_string(buf);
			break;
		}
	}

	ImGui::Text("Pressed: %.*s", static_cast<int>(buf.size()), buf.data());
	ImGui::Text("Current: %s", hotkey ? hotkey->c_str() : "<None>");
}

struct InterimProfileRecord
{
	std::optional<std::pair<std::string, std::string>> CurrentAccount = {};
	std::optional<std::pair<std::string, std::string>> CurrentCharacter = {};
	std::optional<std::string> Hotkey = {};
	std::optional<std::string> EQPath = {};
	std::string CharPreview;

	bool Finalize = false;
};

void ShowAddProfile(std::string_view profile_group, InterimProfileRecord& profile)
{
	ImGui::PushID("Add Profile Window");

	static std::string account_preview;

	// drop down for account or create new
	ImGui::PushID("Choose Account");
	if (ImGui::BeginCombo("##Choose Account", account_preview.c_str()))
	{
		static auto buf = [](size_t size)
			{
				fmt::memory_buffer buf;
				buf.reserve(size);

				return buf;
			}(256);

		static auto buf_ins = std::back_inserter(buf);

		for (const auto& [account, server_type] : login::db::ListAccounts())
		{
			ImGui::PushID(account.c_str());
			ImGui::PushID(server_type.c_str());

			const bool is_selected = profile.CurrentAccount &&
				ci_equals(account, profile.CurrentAccount->first) &&
				ci_equals(server_type, profile.CurrentAccount->second);

			fmt::format_to(buf_ins, "{} ({})", account, server_type);

			if (ImGui::Selectable("", is_selected, ImGuiSelectableFlags_SpanAvailWidth))
			{
				profile.CurrentAccount = std::make_pair(account, server_type);
				account_preview = fmt::to_string(buf);
			}

			if (is_selected)
				ImGui::SetItemDefaultFocus();

			ImGui::SameLine();
			ImGui::Text("%.*s", static_cast<int>(buf.size()), buf.data());

			buf.clear();

			ImGui::PopID();
			ImGui::PopID();
		}
		ImGui::EndCombo();
	}

	ImGui::SameLine();
	if (ImGui::Button("..."))
		LauncherImGui::OpenModal("Select or Create Account");

	ImGui::PopID();

	if (LauncherImGui::BeginModal("Select or Create Account", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::PushID("Select or Create Account Modal");

		ShowAccountWindow(profile.CurrentAccount);

		ImGui::Separator();
		if (ImGui::Button("OK"))
			LauncherImGui::CloseModal();

		ImGui::PopID();
		LauncherImGui::EndModal();
	}

	// drop down for character or create new, only show this if an account has been selected
	if (profile.CurrentAccount)
	{
		ImGui::PushID("Choose Character");
		if (ImGui::BeginCombo("##Choose Character", profile.CharPreview.c_str()))
		{
			// this avoids a buffer allocation
			static auto buf = [](const size_t size)
				{
					fmt::memory_buffer buffer;
					buffer.reserve(size);

					return buffer;
				}(256);

				static auto buf_ins = std::back_inserter(buf);

				for (const auto& character : login::db::ListCharacters(profile.CurrentAccount->first, profile.CurrentAccount->second))
				{
					const bool is_selected = profile.CurrentCharacter &&
						ci_equals(character.first, profile.CurrentCharacter->first) &&
						ci_equals(character.second, profile.CurrentCharacter->second);

					fmt::format_to(buf_ins, "{} : {}", character.first, character.second);

					if (ImGui::Selectable("", is_selected, ImGuiSelectableFlags_SpanAvailWidth))
					{
						profile.CurrentCharacter = character;
						profile.CharPreview = fmt::to_string(buf);
					}

					if (is_selected)
						ImGui::SetItemDefaultFocus();

					ImGui::Text("%.*s", static_cast<int>(buf.size()), buf.data());

					buf.clear();
				}
				ImGui::EndCombo();
		}

		ImGui::SameLine();
		if (ImGui::Button("..."))
			LauncherImGui::OpenModal("Select or Create Character");

		ImGui::PopID();

		if (LauncherImGui::BeginModal("Select or Create Character", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
		{
			ImGui::PushID("Select or Create Character Modal");
			ShowCharacterWindow(*profile.CurrentAccount, profile.CurrentCharacter, profile.CharPreview);

			ImGui::Separator();
			if (ImGui::Button("OK"))
			{
				ProfileRecord record;
				record.profileName = profile_group;
				record.serverName = profile.CurrentCharacter->first;
				record.characterName = profile.CurrentCharacter->second;

				login::db::ReadProfile(record);
				if (!record.hotkey.empty())
					profile.Hotkey = record.hotkey;

				profile.EQPath = record.eqPath;

				LauncherImGui::CloseModal();
			}

			ImGui::PopID();
			LauncherImGui::EndModal();
		}
	}
	else if (profile.CurrentCharacter)
		profile.CurrentCharacter = {};

	if (profile.CurrentAccount && profile.CurrentCharacter)
	{
		// input box for hotkey (optional)
		if (ImGui::Button("Hotkey"))
			LauncherImGui::OpenModal("Input Hotkey");

		ImGui::SameLine();
		ImGui::Text("%s", profile.Hotkey ? profile.Hotkey->c_str() : "<None>");

		if (LauncherImGui::BeginModal("Input Hotkey", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
		{
			ShowHotkeyWindow(profile.Hotkey);

			ImGui::Separator();
			if (ImGui::Button("OK"))
				LauncherImGui::CloseModal();

			LauncherImGui::EndModal();
		}

		// input for eq path override (optional)
		if (ImGui::Button("EQ Path"))
			LauncherImGui::OpenModal("Input EQ Path");

		ImGui::SameLine();
		ImGui::Text("%s", profile.EQPath ? profile.EQPath->c_str() : "<Default>");

		if (LauncherImGui::BeginModal("Input EQ Path", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
		{
			SetEQDir(profile.EQPath);

			ImGui::Separator();
			if (ImGui::Button("OK"))
				LauncherImGui::CloseModal();

			LauncherImGui::EndModal();
		}
	}

	if (ImGui::Button("Cancel"))
	{
		LauncherImGui::CloseModal();
	}


	ImGui::SameLine();
	ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetContentRegionAvail().x - ButtonWidth("Cancel"));
	if (ImGui::Button("OK", ImVec2(ButtonWidth("Cancel"), ImGui::GetStyle().FramePadding.y * 2 + ImGui::CalcTextSize("Cancel").y)))
	{
		if (profile.CurrentCharacter)
			profile.Finalize = true;

		LauncherImGui::CloseModal();
	}

	ImGui::PopID();
}

// TODO: Add settings section
// TODO: Add default path editor (per server type)
// TODO: Remove all fallthrough eq path handling since it's guaranteed per account now
void ShowAutoLoginWindow()
{
	ImGui::PushID("Main Tab Bar");

	ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.f);

	if (ImGui::BeginTabBar("Main Tab Bar", ImGuiTabBarFlags_FittingPolicyResizeDown))
	{
		ImGui::PushID("profile");
		ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x * 0.5f);
		if (ImGui::BeginTabItem("Profiles"))
		{
			static std::optional<std::string> current_group;
			// Code goes into this scope for selecting and modifying profiles/groups
			ImGui::BeginChild("Main Child", ImVec2(0, 0), ImGuiChildFlags_Border, ImGuiWindowFlags_MenuBar);

			ImGui::PushID("Menu Bar");
			if (ImGui::BeginMenuBar())
			{
				static std::string new_group;
				static std::optional<std::string> new_group_path;
				if (ImGui::SmallButton("Create"))
				{
					new_group = "";
					new_group_path = {};
					LauncherImGui::OpenModal("Create Profile Group");
				}

				if (LauncherImGui::BeginModal("Create Profile Group", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
				{
					ImGui::PushID("Create Profile Group Modal");

					ImGui::InputText("Group Name", &new_group);

					ImGui::Spacing();
					if (ImGui::Button("EQ Path"))
						LauncherImGui::OpenModal("Input EQ Path");

					ImGui::SameLine();
					ImGui::Text("%s", new_group_path ? new_group_path->c_str() : "<Default>");

					if (LauncherImGui::BeginModal("Input EQ Path", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
					{
						SetEQDir(new_group_path);

						ImGui::Separator();
						if (ImGui::Button("OK"))
							LauncherImGui::CloseModal();

						LauncherImGui::EndModal();
					}

					ImGui::Separator();
					if (ImGui::Button("Cancel"))
					{
						LauncherImGui::CloseModal();
					}

					ImGui::SameLine();
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetContentRegionAvail().x - ButtonWidth("Cancel"));
					if (ImGui::Button("OK", ImVec2(ButtonWidth("Cancel"), ImGui::GetStyle().FramePadding.y * 2 + ImGui::CalcTextSize("Cancel").y)))
					{
						if (!new_group.empty())
						{
							ProfileGroup group;
							group.profileName = new_group;
							group.eqPath = new_group_path;

							login::db::CreateProfileGroup(group);
						}

						current_group = new_group;
						new_group = {};
						new_group_path = {};

						LauncherImGui::CloseModal();
					}

					ImGui::PopID();
					LauncherImGui::EndModal();
				}

				if (ImGui::SmallButton("Remove") && current_group)
					LauncherImGui::OpenModal("Delete Profile Group");

				if (LauncherImGui::BeginModal("Delete Profile Group", nullptr, ImGuiWindowFlags_AlwaysAutoResize) && current_group)
				{
					ImGui::PushID("Delete Profile Group Modal");

					ImGui::TextWrapped("Are you sure you want to delete profile group '%s'? All associated profiles will also be removed.", current_group->c_str());
					ImGui::Spacing();

					if (ImGui::Button("Yes", ImVec2(120, 0)))
					{
						login::db::DeleteProfileGroup(*current_group);
						current_group = {};
						LauncherImGui::CloseModal();
					}

					ImGui::SetItemDefaultFocus();
					ImGui::SameLine();
					if (ImGui::Button("No", ImVec2(120, 0)))
					{
						LauncherImGui::CloseModal();
					}

					ImGui::PopID();
					LauncherImGui::EndModal();
				}

				constexpr auto label = "Profiles";
				ImGui::SameLine(ImGui::GetContentRegionMax().x - ImGui::CalcTextSize(label).x - 5.f);
				ImGui::Text(label);

				ImGui::EndMenuBar();
			}
			ImGui::PopID();

			ImGui::PushID("Profile Combo");
			ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x - ButtonWidth("Add Profile") - ButtonWidth("Launch Group"));
			if (ImGui::BeginCombo("##Profile Combo", current_group ? current_group->c_str() : ""))
			{
				for (const auto& group : login::db::ListProfileGroups())
				{
					const bool is_selected = current_group && ci_equals(group, *current_group);
					if (ImGui::Selectable(group.c_str(), is_selected))
						current_group = group;

					if (is_selected)
						ImGui::SetItemDefaultFocus();
				}
				ImGui::EndCombo();
			}
			ImGui::PopID();

			ImGui::SameLine();
			static InterimProfileRecord interim_profile;
			static bool edit_profile = false;

			if (ImGui::Button("Add Profile"))
			{
				// reset to defaults
				interim_profile = {};
				LauncherImGui::OpenModal("Add Profile");
			}

			if (current_group && LauncherImGui::BeginModal("Add Profile", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
			{
				ShowAddProfile(*current_group, interim_profile);
				LauncherImGui::EndModal();
			}

			if (!edit_profile && current_group && interim_profile.Finalize && interim_profile.CurrentCharacter)
			{
				ProfileRecord record;
				record.profileName = *current_group;
				record.serverName = interim_profile.CurrentCharacter->first;
				record.characterName = interim_profile.CurrentCharacter->second;
				record.hotkey = interim_profile.Hotkey ? *interim_profile.Hotkey : "";
				record.eqPath = interim_profile.EQPath;
				record.checked = true;

				interim_profile = {};

				login::db::CreateProfile(record);
			}

			ImGui::SameLine();
			if (ImGui::Button("Launch Group") && current_group)
			{
				LoadProfileGroup(*current_group);
			}

			ImGui::PushID("Main List");
			if (ImGui::BeginTable("Main List", 7, ImGuiTableFlags_SizingStretchProp | ImGuiTableFlags_Borders | ImGuiTableFlags_NoBordersInBody))
			{
				if (current_group)
				{
					ImGui::TableSetupColumn("Account");
					ImGui::TableSetupColumn("Server Type");
					ImGui::TableSetupColumn("Server");
					ImGui::TableSetupColumn("Character");
					ImGui::TableSetupColumn("Persona");
					ImGui::TableSetupColumn("Hotkey");
					ImGui::TableSetupColumn("##play");
					ImGui::TableHeadersRow();

					for (auto& profile : login::db::GetProfiles(*current_group))
					{
						ImGui::PushID(profile.serverName.c_str());
						ImGui::PushID(profile.characterName.c_str());

						ImGui::TableNextRow();
						ImGui::TableNextColumn();
						if (ImGui::Selectable("", &profile.checked, ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_AllowOverlap))
							login::db::UpdateProfile(profile);

						if (ImGui::IsItemHovered() && ImGui::IsItemClicked(ImGuiMouseButton_Right))
							ImGui::OpenPopup("row_popup");

						if (ImGui::BeginPopup("row_popup"))
						{
							if (ImGui::Selectable("Edit"))
							{
								interim_profile.CurrentCharacter = std::make_pair(profile.serverName, profile.characterName);
								interim_profile.CurrentAccount = std::make_pair(profile.accountName, profile.serverType);
								interim_profile.Hotkey = profile.hotkey;
								interim_profile.EQPath = profile.eqPath;
								interim_profile.CharPreview = fmt::format("{} : {}", profile.serverName, profile.characterName);
								
								interim_profile.Finalize = false;

								edit_profile = true;
							}

							if (ImGui::Selectable("Remove"))
								login::db::DeleteProfile(profile.serverName, profile.characterName, *current_group);

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
							instance.ProfileGroup = current_group;
							instance.Server = profile.serverName;
							instance.Character = profile.characterName;
							if (!profile.hotkey.empty()) instance.Hotkey = profile.hotkey;

							LoadCharacter(instance);
						}

						ImGui::PopID();
						ImGui::PopID();
					}

					if (edit_profile && interim_profile.CurrentCharacter)
						LauncherImGui::OpenModal("Edit Profile");

					if (LauncherImGui::BeginModal("Edit Profile", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
					{
						ShowAddProfile(*current_group, interim_profile);
						LauncherImGui::EndModal();
					}

					if (interim_profile.Finalize && interim_profile.CurrentCharacter)
					{
						ProfileRecord record;
						record.profileName = *current_group;
						record.serverName = interim_profile.CurrentCharacter->first;
						record.characterName = interim_profile.CurrentCharacter->second;
						record.hotkey = interim_profile.Hotkey ? *interim_profile.Hotkey : "";
						record.eqPath = interim_profile.EQPath;
						record.checked = true;

						interim_profile = {};
						edit_profile = false;

						login::db::UpdateProfile(record);
					}
				}

				ImGui::EndTable();
			}
			ImGui::PopID();

			ImGui::EndChild();
			ImGui::EndTabItem();
		}

		ImGui::PopID();

		ImGui::PushID("character");
		ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
		if (ImGui::BeginTabItem("Characters"))
		{
			ImGui::BeginChild("Main Child", ImVec2(0, 0), ImGuiChildFlags_Border, ImGuiWindowFlags_MenuBar);

			static std::string search;
			static auto matches = login::db::ListCharacterMatches(search);
			static ProfileRecord interim_profile;
			static std::optional<std::pair<std::string, std::string>> selected;

			ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x - ButtonWidth("Add Character"));
			if (ImGui::InputText("##Search Bar", &search, ImGuiInputTextFlags_EscapeClearsAll))
			{
				matches = login::db::ListCharacterMatches(search);
			}

			ImGui::SameLine();
			if (ImGui::Button("Add Character"))
			{
				// reset to defaults
				interim_profile = {};
				LauncherImGui::OpenModal("Add Character");
			}

			if (LauncherImGui::BeginModal("Add Character", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
			{
				ImGui::PushID("Create Character Modal");

				ImGui::InputText("Account", &interim_profile.accountName);
				ImGui::Spacing();

				ImGui::InputText("Server Type", &interim_profile.serverType);
				ImGui::Spacing();

				ImGui::InputText("Server", &interim_profile.serverName);
				ImGui::Spacing();

				ImGui::InputText("Name", &interim_profile.characterName);
				ImGui::Spacing();

				if (ImGui::Button("OK", ImVec2(120, 0)))
				{
					login::db::CreateCharacter(interim_profile);
					LauncherImGui::CloseModal();
				}

				ImGui::SetItemDefaultFocus();
				ImGui::SameLine();
				if (ImGui::Button("Cancel", ImVec2(120, 0)))
				{
					LauncherImGui::CloseModal();
				}

				ImGui::PopID();
				LauncherImGui::EndModal();
			}

			ImGui::PushID("Main List");
			if (ImGui::BeginTable("Main List", 6, ImGuiTableFlags_SizingStretchProp | ImGuiTableFlags_Borders | ImGuiTableFlags_NoBordersInBody))
			{
				ImGui::TableSetupColumn("Account");
				ImGui::TableSetupColumn("Server Type");
				ImGui::TableSetupColumn("Server");
				ImGui::TableSetupColumn("Character");
				ImGui::TableSetupColumn("Persona");
				ImGui::TableSetupColumn("##buttons");
				ImGui::TableHeadersRow();

				for (const auto& match : matches)
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
							interim_profile = {};
							interim_profile.serverName = match.serverName;
							interim_profile.characterName = match.characterName;
							login::db::ReadCharacter(interim_profile);

							selected = std::make_pair(match.serverName, match.characterName);
						}

						if (ImGui::Selectable("Remove"))
							login::db::DeleteCharacter(match.serverName, match.characterName);

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
					static std::optional<std::string> hotkey;
					ImGui::PushID("Play With Params");
					if (ImGui::SmallButton("..."))
					{
						interim_profile = {};
						interim_profile.serverName = match.serverName;
						interim_profile.characterName = match.characterName;
						hotkey = {};
						LauncherImGui::OpenModal("Play With Params");
					}
					ImGui::PopID();

					if (LauncherImGui::BeginModal("Play With Params", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
					{
						ImGui::PushID("Play With Params Modal");

						// input box for hotkey (optional)
						if (ImGui::Button("Hotkey"))
							LauncherImGui::OpenModal("Input Hotkey");

						ImGui::SameLine();
						ImGui::Text("%s", hotkey ? hotkey->c_str() : "<None>");

						if (LauncherImGui::BeginModal("Input Hotkey", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
						{
							ShowHotkeyWindow(hotkey);

							ImGui::Separator();
							if (ImGui::Button("OK"))
								LauncherImGui::CloseModal();

							LauncherImGui::EndModal();
						}

						// input for eq path override (optional)
						if (ImGui::Button("EQ Path"))
							LauncherImGui::OpenModal("Input EQ Path");

						ImGui::SameLine();
						ImGui::Text("%s", interim_profile.eqPath ? interim_profile.eqPath->c_str() : "<Default>");

						if (LauncherImGui::BeginModal("Input EQ Path", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
						{
							SetEQDir(interim_profile.eqPath);

							ImGui::Separator();
							if (ImGui::Button("OK"))
								LauncherImGui::CloseModal();

							LauncherImGui::EndModal();
						}

						if (ImGui::Button("Cancel"))
							LauncherImGui::CloseModal();


						ImGui::SameLine();
						ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetContentRegionAvail().x - ButtonWidth("Cancel"));
						if (ImGui::Button("OK", ImVec2(ButtonWidth("Cancel"), ImGui::GetStyle().FramePadding.y * 2 + ImGui::CalcTextSize("Cancel").y)))
						{
							LoginInstance instance;
							instance.Server = interim_profile.serverName;
							instance.Character = interim_profile.characterName;
							instance.Hotkey = hotkey;
							instance.EQPath = interim_profile.eqPath;

							LoadCharacter(instance);

							LauncherImGui::CloseModal();
						}

						ImGui::PopID();
						LauncherImGui::EndModal();
					}

					ImGui::PopID();
					ImGui::PopID();
				}

				if (selected)
					LauncherImGui::OpenModal("Edit Character");

				if (LauncherImGui::BeginModal("Edit Character", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
				{
					ImGui::PushID("Edit Character Modal");

					ImGui::InputText("Account", &interim_profile.accountName);
					ImGui::Spacing();

					ImGui::InputText("Server Type", &interim_profile.serverType);
					ImGui::Spacing();

					ImGui::InputText("Server", &interim_profile.serverName);
					ImGui::Spacing();

					ImGui::InputText("Name", &interim_profile.characterName);
					ImGui::Spacing();

					if (ImGui::Button("OK", ImVec2(120, 0)))
					{
						if (selected)
							login::db::UpdateCharacter(selected->first, selected->second, interim_profile);

						selected = {};
						interim_profile = {};
						LauncherImGui::CloseModal();
					}

					ImGui::SetItemDefaultFocus();
					ImGui::SameLine();
					if (ImGui::Button("Cancel", ImVec2(120, 0)))
					{
						LauncherImGui::CloseModal();
					}

					ImGui::PopID();
					LauncherImGui::EndModal();
				}

				ImGui::EndTable();
			}
			ImGui::PopID();

			ImGui::EndChild();
			ImGui::EndTabItem();
		}

		ImGui::PopID();

		ImGui::EndTabBar();
	}

	ImGui::PopStyleVar();

	ImGui::PopID();
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
	ImGui::PushID("contextmenu");

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
							std::move(profile),
							std::move(level_text),
							level_size,
							class_size
							});
					}

					for (auto& sized_profile : profiles)
					{
						auto& profile = sized_profile.Profile;
						ImGui::PushID(profile.characterName.c_str());
						ImGui::PushID(profile.serverName.c_str());

						if (LauncherImGui::SmallCheckbox("##checked", &profile.checked))
							login::db::UpdateProfile(profile);

						ImGui::SameLine();
						constexpr ImGuiSelectableFlags selectable_flags = ImGuiSelectableFlags_SelectOnRelease | ImGuiSelectableFlags_NoSetKeyOwner | ImGuiSelectableFlags_SetNavIdOnHover | ImGuiSelectableFlags_SpanAvailWidth;
						if (ImGui::Selectable("[", false, selectable_flags))
						{
							LoginInstance instance;
							instance.ProfileGroup = group;
							instance.Server = profile.serverName;
							instance.Character = profile.characterName;
							if (!profile.hotkey.empty()) instance.Hotkey = profile.hotkey;

							LoadCharacter(instance);
						}

						ImGui::SameLine(0, largest_level - sized_profile.LevelSize);
						ImGui::TextUnformatted(sized_profile.LevelText.c_str());

						ImGui::SameLine(); ImGui::TextUnformatted(" ");

						ImGui::SameLine(0, largest_class - sized_profile.ClassSize);
						ImGui::TextUnformatted(profile.characterClass.c_str());

						ImGui::SameLine(0, 0); ImGui::Text("] %s ", profile.characterName.c_str());

						ImGui::PopID();
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
							std::move(profile),
							std::move(level_text),
							level_size,
							class_size
							});
					}

					for (auto& sized_profile : profiles)
					{
						auto& profile = sized_profile.Profile;
						ImGui::PushID(profile.characterName.c_str());
						ImGui::PushID(profile.serverName.c_str());

						constexpr ImGuiSelectableFlags selectable_flags = ImGuiSelectableFlags_SelectOnRelease | ImGuiSelectableFlags_NoSetKeyOwner | ImGuiSelectableFlags_SetNavIdOnHover | ImGuiSelectableFlags_SpanAvailWidth;
						if (ImGui::Selectable("[", false, selectable_flags))
						{
							LoginInstance instance;
							instance.Server = profile.serverName;
							instance.Character = profile.characterName;

							LoadCharacter(instance);
						}

						ImGui::SameLine(0, largest_level - sized_profile.LevelSize);
						ImGui::TextUnformatted(sized_profile.LevelText.c_str());

						ImGui::SameLine(); ImGui::TextUnformatted(" ");

						ImGui::SameLine(0, largest_class - sized_profile.ClassSize);
						ImGui::TextUnformatted(profile.characterClass.c_str());

						ImGui::SameLine(0, 0); ImGui::Text("] %s ", profile.characterName.c_str());

						ImGui::PushStyleVar(ImGuiStyleVar_Alpha, ImGui::GetStyle().Alpha * 0.25f);
						ImGui::SameLine(); ImGui::Text("%s (%s)", profile.accountName.c_str(), profile.serverType.c_str());
						ImGui::PopStyleVar();

						ImGui::PopID();
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

	ImGui::PopID();
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

		ImGui::SetCursorPosX(ImGui::GetContentRegionMax().x - ButtonWidth("  OK  "));
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

	if (const auto load_ini = login::db::ReadSetting("load_ini"); !load_ini || GetBoolFromString(*load_ini, false))
	{
		login::db::WriteProfileGroups(LoadAutoLoginProfiles(internal_paths::s_autoLoginIni));
		login::db::WriteSetting("load_ini", "false", "Import data from autologin ini file one time");
	}

	// Initialize path to EQ
	// TODO: This should detect the current build or something and get the path for that build
	internal_paths::s_eqRoot = GetPrivateProfileString("Profiles", "DefaultEQPath", "", internal_paths::s_autoLoginIni);
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
