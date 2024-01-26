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

struct RawProfileRecord
{
	std::string profileName;
	std::string serverName;
	std::string characterName;

	std::string eqPath;
	std::string encryptedBlob;
	bool checked;
};

CHotKeyCtrl* pHotKeyCtrl = nullptr;

struct LoginInstance
{
	mutable unsigned long PID;

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

// set of loaded instances -- be careful to only read/write this from actors to ensure no race conditions
static std::unordered_set<LoginInstance, LoginInstance> s_loadedInstances;
using LoginIterator = std::unordered_set<LoginInstance, LoginInstance>::const_iterator;

postoffice::Dropbox s_dropbox;

static ImGuiFileDialog* s_eqDirDialog = nullptr;

namespace internal_paths
{
	std::string AutoLoginIni;
	std::string EQRoot;
}

// need a map of shortname to name (TODO: Use long names in the display)
// order matters here in the logic, so we need to make sure these are in the same order as MQ2
struct SClassInfo
{
	const char* Name;
	const char* UCShortName;
};

static SClassInfo ClassInfo[] =
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

const char* GetClassShortName(DWORD playerclass)
{
	return ClassInfo[playerclass].UCShortName;
}

static void ActOnPid(DWORD pid, const std::function<void(const LoginIterator&)>& func)
{
	auto login_it = std::find_if(s_loadedInstances.begin(), s_loadedInstances.end(),
		[pid](const LoginInstance& instance) { return instance.PID == pid; });
	if (login_it != s_loadedInstances.end())
		func(login_it);
}

// This sends a message to self so that we ensure that all access of s_loadedInstances happens on the main thread
static void LoadCharacter(const LoginInstance& instance_template)
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

void AutoLoginRemoveProcess(DWORD processId)
{
	proto::login::StopInstanceMissive stop;
	stop.set_pid(processId);

	mq::proto::login::LoginMessage message;
	message.set_id(mq::proto::login::ProfileUnloaded);
	message.set_payload(stop.SerializeAsString());

	mq::proto::routing::Address address;
	address.set_name("launcher");
	address.set_mailbox("autologin");

	s_dropbox.Post(address, message);
}

// TODO: hotkey/eqpath information is lost once we start the instance because the ack will unset them
static LoginIterator StartOrUpdateInstance(const LoginInstance& instance_template, bool do_inject)
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
			// to reload and we aren't catching that event
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

		std::string eq_path = instance_template.EQPath.value_or(instance_template.ProfileGroup ? 
			login::db::GetEQPath(*instance_template.ProfileGroup, instance_template.Server, instance_template.Character) :
			login::db::ReadEQPath());

		if (!eq_path.empty())
		{
			SHELLEXECUTEINFOA sei = { sizeof(SHELLEXECUTEINFOA) };
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
				ProfileRecord record;
				record.serverName = instance_template.Server;
				record.characterName = instance_template.Character;

				if (login::db::ReadAccount(record))
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

			if (ShellExecuteEx(&sei) && sei.hProcess != 0)
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
	fs::path eqlsPlayerDataIni = fs::path{ internal_paths::EQRoot } / "eqlsPlayerData.ini";

	// Get default username from eqlsPlayerData.ini
	std::string username = GetPrivateProfileString("PLAYER", "Username", "<>", eqlsPlayerDataIni.string());

	// create command line arguments
	std::string parameters = fmt::format("{}\\eqgame.exe patchme /login:{}", internal_paths::EQRoot, username);

	STARTUPINFOA si = { sizeof(STARTUPINFOA) };
	si.wShowWindow = SW_SHOWNORMAL;
	si.dwFlags = STARTF_USESHOWWINDOW;

	wil::unique_process_information pi;
	::CreateProcessA(nullptr, &parameters[0], nullptr, nullptr, FALSE, 0, nullptr, internal_paths::EQRoot.c_str(), &si, &pi);
}

#pragma region ImGui

bool ToggleSlider(const char* label, bool* v)
{
	ImVec4* colors = ImGui::GetStyle().Colors;
	ImVec2 position = ImGui::GetCursorScreenPos();
	ImDrawList* draw_list = ImGui::GetWindowDrawList();

	float height = ImGui::GetFrameHeight();
	float width = height * 1.55f;
	float radius = height * 0.5f;

	bool ret = ImGui::InvisibleButton(label, ImVec2(width, height));
	if (ImGui::IsItemClicked()) *v = !*v;

	float t = *v ? 1.f : 0.f;

	ImGuiContext* g = ImGui::GetCurrentContext();
	float animation_speed = 8.5f;
	if (g->LastActiveId == g->CurrentWindow->GetID(label))
	{
		float t_anim = ImSaturate(g->LastActiveIdTimer * animation_speed);
		t = *v ? t_anim : (1.f - t_anim);
	}

	ImU32 bg_color = ImGui::GetColorU32(colors[ImGuiCol_Text]);

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
	return ImGui::GetStyle().FramePadding.x * 2 + ImGui::CalcTextSize(text).x + ImGui::GetStyle().WindowPadding.x;
}

void SetEQDir(std::optional<std::string>& eq_path)
{
	auto eqDir = eq_path.value_or(login::db::ReadEQPath());
	ImGui::InputText("EQ Dir", &eqDir[0], eqDir.size(), ImGuiInputTextFlags_ReadOnly);

	if (!s_eqDirDialog)
		s_eqDirDialog = IGFD_Create();

	if (ImGui::Button("Choose##eqdir"))
	{
		IGFD_OpenDialog2(s_eqDirDialog, "ChooseEQDirKey", "Choose Default EverQuest Directory",
			nullptr, (internal_paths::EQRoot + "/").c_str(), 1, nullptr, ImGuiFileDialogFlags_None);
	}

	if (IGFD_DisplayDialog(s_eqDirDialog, "ChooseEQDirKey", ImGuiFileDialogFlags_None, ImVec2(350, 350), ImVec2(FLT_MAX, FLT_MAX)))
	{
		if (IGFD_IsOk(s_eqDirDialog))
		{
			std::shared_ptr<char> selected_path(IGFD_GetCurrentPath(s_eqDirDialog), IGFD_DestroyString);
			std::error_code ec;
			if (selected_path && std::filesystem::exists(selected_path.get(), ec))
			{
				eq_path = std::filesystem::canonical(std::filesystem::path(selected_path.get()), ec).string();
			}
		}

		IGFD_CloseDialog(s_eqDirDialog);
	}
}

void ShowAccountWindow(std::optional<std::string>& selected)
{
	// declare account statics
	static bool show_password = false;
	static std::string password;
	static std::string account_name;

	ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
	if (ImGui::BeginListBox("##accountslist"))
	{
		for (const auto& account : login::db::ListAccounts())
		{
			const bool is_selected = selected && ci_equals(account, *selected);
			if (ImGui::Selectable(account.c_str(), is_selected))
				selected = account;

			if (is_selected) ImGui::SetItemDefaultFocus();
		}

		ImGui::EndListBox();
	}

	if (selected)
	{
		if (ImGui::IsKeyPressed(ImGuiKey_Delete)) ImGui::OpenModal("Delete Account");

		if (ImGui::IsKeyPressed(ImGuiKey_Enter))
		{
			ProfileRecord profile;
			profile.accountName = *selected;
			if (auto pass = login::db::ReadAccount(profile))
				password = *pass;

			ImGui::OpenModal("Edit Account");
		}

		if (ImGui::IsKeyPressed(ImGuiKey_Escape)) selected = {};
	}

	if (ImGui::BeginModal("Delete Account", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::TextWrapped("Are you sure you want to delete account '%s'? All associated characters and profiles will also be removed.", selected->c_str());
		ImGui::Spacing();

		if (ImGui::Button("Yes##deleteaccount", ImVec2(120, 0)))
		{
			login::db::DeleteAccount(*selected);
			selected = {};
			ImGui::CloseModal();
		}

		ImGui::SetItemDefaultFocus();
		ImGui::SameLine();
		if (ImGui::Button("No##deleteaccount", ImVec2(120, 0)))
		{
			ImGui::CloseModal();
		}

		ImGui::EndModal();
	}

	if (ImGui::BeginModal("Edit Account", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::TextWrapped("Set password for account '%s':", selected->c_str());
		ImGui::Spacing();

		ImGuiInputTextFlags flags = ImGuiInputTextFlags_None;
		if (!show_password) flags |= ImGuiInputTextFlags_Password;
		ImGui::InputText("##password##editaccount", &password, flags);
		ImGui::Spacing();

		ImGui::Checkbox("Show password##editaccount", &show_password);
		ImGui::Spacing();

		if (ImGui::Button("OK##editaccount", ImVec2(120, 0)))
		{
			ProfileRecord record;
			record.accountName = *selected;
			record.accountPassword = password;
			login::db::UpdateAccount(*selected, record);
			ImGui::CloseModal();
		}

		ImGui::SetItemDefaultFocus();
		ImGui::SameLine();
		if (ImGui::Button("Cancel##editaccount", ImVec2(120, 0)))
		{
			ImGui::CloseModal();
		}

		ImGui::EndModal();
	}

	if (ImGui::BeginModal("Create Account", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::TextWrapped("Create a new account, or update existing account.");
		ImGui::Spacing();

		ImGui::InputText("Account Name##createaccount", &account_name);
		ImGui::Spacing();

		ImGuiInputTextFlags flags = ImGuiInputTextFlags_None;
		if (!show_password) flags |= ImGuiInputTextFlags_Password;
		ImGui::InputText("##password##createaccount", &password, flags);
		ImGui::Spacing();

		ImGui::Checkbox("Show password##createaccount", &show_password);
		ImGui::Spacing();

		if (ImGui::Button("OK##createaccount", ImVec2(120, 0)))
		{
			ProfileRecord record;
			record.accountName = account_name;
			record.accountPassword = password;
			login::db::CreateAccount(record);
			selected = account_name;
			ImGui::CloseModal();
		}

		ImGui::SetItemDefaultFocus();
		ImGui::SameLine();
		if (ImGui::Button("Cancel##createaccount", ImVec2(120, 0)))
		{
			ImGui::CloseModal();
		}

		ImGui::EndModal();
	}

	if (ImGui::Button("Add Account"))
	{
		account_name = selected ? *selected : "";
		ImGui::OpenModal("Create Account");
	}

	ImGui::SameLine();
	if (ImGui::Button("Edit Account") && selected)
	{
		ProfileRecord profile;
		profile.accountName = *selected;
		if (auto pass = login::db::ReadAccount(profile))
			password = *pass;

		ImGui::OpenModal("Edit Account");
	}

	ImGui::SameLine();
	if (ImGui::Button("Remove Account") && selected) ImGui::OpenModal("Delete Account");
}

void ShowCharacterWindow(std::string_view account, std::optional<std::pair<std::string, std::string>>& selected, std::string& preview)
{
	auto set_selection = [&selected, &preview](const std::pair<std::string, std::string> character)
		{
			selected = character;
			preview = fmt::format("{} : {}", character.first, character.second);
		};

	static std::string accountName;
	static std::string serverName;
	static std::string characterName;

	ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
	if (ImGui::BeginListBox("##characterslist"))
	{
		// this avoids a buffer allocation
		static auto buf = [](size_t size)
			{
				fmt::memory_buffer buf;
				buf.reserve(size);

				return buf;
			}(256);

		static auto buf_ins = std::back_inserter(buf);

		for (const auto& character : login::db::ListCharacters(account))
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
			ImGui::Text("%.*s", buf.size(), buf.data());

			buf.clear();

			ImGui::PopID();
			ImGui::PopID();
		}

		ImGui::EndListBox();
	}

	if (selected)
	{
		if (ImGui::IsKeyPressed(ImGuiKey_Delete)) ImGui::OpenModal("Delete Character");

		if (ImGui::IsKeyPressed(ImGuiKey_Enter))
		{
			accountName = account;
			serverName = selected->first;
			characterName = selected->second;

			ImGui::OpenModal("Edit Character");
		}

		if (ImGui::IsKeyPressed(ImGuiKey_Escape)) selected = {};
	}

	if (ImGui::BeginModal("Delete Character", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::TextWrapped("Are you sure you want to delete character '%s : %s'? All associated profiles will also be removed.", selected->first.c_str(), selected->second.c_str());
		ImGui::Spacing();

		if (ImGui::Button("Yes##deletecharacter", ImVec2(120, 0)))
		{
			login::db::DeleteCharacter(selected->first, selected->second);
			selected = {};
			preview = "";
			ImGui::CloseModal();
		}

		ImGui::SetItemDefaultFocus();
		ImGui::SameLine();
		if (ImGui::Button("No##deletecharacter", ImVec2(120, 0)))
		{
			ImGui::CloseModal();
		}

		ImGui::EndModal();
	}

	if (ImGui::BeginModal("Edit Character", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::InputText("Account##editcharacter", &accountName);
		ImGui::Spacing();

		ImGui::InputText("Server##editcharacter", &serverName);
		ImGui::Spacing();

		ImGui::InputText("Name##editcharacter", &characterName);
		ImGui::Spacing();

		if (ImGui::Button("OK##editcharacter", ImVec2(120, 0)))
		{
			if (selected)
			{
				ProfileRecord record;
				record.accountName = accountName;
				record.serverName = serverName;
				record.characterName = characterName;

				login::db::UpdateCharacter(selected->first, selected->second, record);
				set_selection(std::make_pair(serverName, characterName));
			}

			ImGui::CloseModal();
		}

		ImGui::SetItemDefaultFocus();
		ImGui::SameLine();
		if (ImGui::Button("Cancel##editcharacter", ImVec2(120, 0)))
		{
			ImGui::CloseModal();
		}

		ImGui::EndModal();
	}

	if (ImGui::BeginModal("Create Character", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::InputText("Account##createcharacter", &accountName);
		ImGui::Spacing();

		ImGui::InputText("Server##createcharacter", &serverName);
		ImGui::Spacing();

		ImGui::InputText("Name##createcharacter", &characterName);
		ImGui::Spacing();

		if (ImGui::Button("OK##createcharacter", ImVec2(120, 0)))
		{
			ProfileRecord record;
			record.accountName = accountName;
			record.serverName = serverName;
			record.characterName = characterName;

			login::db::CreateCharacter(record);
			set_selection(std::make_pair(serverName, characterName));

			ImGui::CloseModal();
		}

		ImGui::SetItemDefaultFocus();
		ImGui::SameLine();
		if (ImGui::Button("Cancel##createcharacter", ImVec2(120, 0)))
		{
			ImGui::CloseModal();
		}

		ImGui::EndModal();
	}

	if (ImGui::Button("Add Character"))
	{
		accountName = account;
		if (selected)
		{
			serverName = selected->first;
			characterName = selected->second;
		}
		else
		{
			serverName.clear();
			characterName.clear();
		}
		ImGui::OpenModal("Create Character");
	}

	ImGui::SameLine();
	if (ImGui::Button("Edit Character") && selected)
	{
		accountName = account;
		serverName = selected->first;
		characterName = selected->second;

		ImGui::OpenModal("Edit Character");
	}

	ImGui::SameLine();
	if (ImGui::Button("Remove Character") && selected) ImGui::OpenModal("Delete Character");
}

static const std::unordered_map<ImGuiKey, std::string> s_hotkeyMap = {
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
	auto buf_ins = std::back_inserter(buf);

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

	ImGui::Text("Pressed: %.*s", buf.size(), buf.data());
	ImGui::Text("Current: %s", hotkey ? hotkey->c_str() : "<None>");
}

struct InterimProfileRecord
{
	std::optional<std::string> current_account = {};
	std::optional<std::pair<std::string, std::string>> current_character = {};
	std::optional<std::string> hotkey = {};
	std::optional<std::string> eq_path = {};
	std::string char_preview = "";

	bool finalize = false;
};

void ShowAddProfile(std::string_view profile_group, InterimProfileRecord& profile)
{
	ImGui::PushID("addprofilewindow");

	// drop down for account or create new
	if (ImGui::BeginCombo("##chooseaccount", profile.current_account ? profile.current_account->c_str() : ""))
	{
		for (const auto& account : login::db::ListAccounts())
		{
			bool is_selected = profile.current_account && ci_equals(account, *profile.current_account);
			if (ImGui::Selectable(account.c_str(), is_selected))
				profile.current_account = account;

			if (is_selected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndCombo();
	}

	ImGui::SameLine();
	if (ImGui::Button("...##account"))
		ImGui::OpenModal("Select or Create Account");

	if (ImGui::BeginModal("Select or Create Account", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ShowAccountWindow(profile.current_account);

		ImGui::Separator();
		if (ImGui::Button("OK"))
			ImGui::CloseModal();

		ImGui::EndModal();
	}

	// drop down for character or create new, only show this if an account has been selected
	if (profile.current_account)
	{
		if (ImGui::BeginCombo("##choosecharacter", profile.char_preview.c_str()))
		{
			// this avoids a buffer allocation
			static auto buf = [](size_t size)
				{
					fmt::memory_buffer buf;
					buf.reserve(size);

					return buf;
				}(256);

				static auto buf_ins = std::back_inserter(buf);

				for (const auto& character : login::db::ListCharacters(*profile.current_account))
				{
					const bool is_selected = profile.current_character &&
						ci_equals(character.first, profile.current_character->first) &&
						ci_equals(character.second, profile.current_character->second);

					fmt::format_to(buf_ins, "{} : {}", character.first, character.second);

					if (ImGui::Selectable("", is_selected, ImGuiSelectableFlags_SpanAvailWidth))
					{
						profile.current_character = character;
						profile.char_preview = fmt::to_string(buf);
					}

					if (is_selected)
						ImGui::SetItemDefaultFocus();

					ImGui::Text("%.*s", buf.size(), buf.data());

					buf.clear();
				}
				ImGui::EndCombo();
		}

		ImGui::SameLine();
		if (ImGui::Button("...##character"))
			ImGui::OpenModal("Select or Create Character");

		if (ImGui::BeginModal("Select or Create Character", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
		{
			ShowCharacterWindow(*profile.current_account, profile.current_character, profile.char_preview);

			ImGui::Separator();
			if (ImGui::Button("OK"))
			{
				ProfileRecord record;
				record.profileName = profile_group;
				record.serverName = profile.current_character->first;
				record.characterName = profile.current_character->second;

				login::db::ReadProfile(record);
				if (!record.hotkey.empty())
					profile.hotkey = record.hotkey;

				profile.eq_path = record.eqPath;

				ImGui::CloseModal();
			}

			ImGui::EndModal();
		}
	}
	else if (profile.current_character)
		profile.current_character = {};

	if (profile.current_account && profile.current_character)
	{
		// input box for hotkey (optional)
		if (ImGui::Button("Hotkey"))
			ImGui::OpenModal("Input Hotkey");

		ImGui::SameLine();
		ImGui::Text("%s", profile.hotkey ? profile.hotkey->c_str() : "<None>");

		if (ImGui::BeginModal("Input Hotkey", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
		{
			ShowHotkeyWindow(profile.hotkey);

			ImGui::Separator();
			if (ImGui::Button("OK"))
				ImGui::CloseModal();

			ImGui::EndModal();
		}

		// input for eq path override (optional)
		if (ImGui::Button("EQ Path"))
			ImGui::OpenModal("Input EQ Path");

		ImGui::SameLine();
		ImGui::Text("%s", profile.eq_path ? profile.eq_path->c_str() : "<Default>");

		if (ImGui::BeginModal("Input EQ Path", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
		{
			SetEQDir(profile.eq_path);

			ImGui::Separator();
			if (ImGui::Button("OK"))
				ImGui::CloseModal();

			ImGui::EndModal();
		}
	}

	if (ImGui::Button("Cancel"))
	{
		ImGui::CloseModal();
	}


	ImGui::SameLine();
	ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetContentRegionAvail().x - ButtonWidth("Cancel"));
	if (ImGui::Button("OK", ImVec2(ButtonWidth("Cancel"), ImGui::GetStyle().FramePadding.y * 2 + ImGui::CalcTextSize("Cancel").y)))
	{
		if (profile.current_character)
			profile.finalize = true;

		ImGui::CloseModal();
	}

	ImGui::PopID();
}

// TODO: Add settings section
void ShowAutoLoginWindow()
{
	ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.f);

	if (ImGui::BeginTabBar("##maintabbar", ImGuiTabBarFlags_FittingPolicyResizeDown))
	{
		ImGui::PushID("profile");
		ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x * 0.5f);
		if (ImGui::BeginTabItem("Profiles"))
		{
			static std::optional<std::string> current_group;
			// Code goes into this scope for selecting and modifying profiles/groups
			ImGui::BeginChild("##mainchild", ImVec2(0, 0), ImGuiChildFlags_Border, ImGuiWindowFlags_MenuBar);

			ImGui::PushID("menubar");
			if (ImGui::BeginMenuBar())
			{
				static std::string new_group;
				static std::optional<std::string> new_group_path;
				if (ImGui::SmallButton("Create"))
				{
					new_group = "";
					new_group_path = {};
					ImGui::OpenModal("Create Profile Group");
				}

				if (ImGui::BeginModal("Create Profile Group", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
				{
					ImGui::InputText("Group Name", &new_group);

					ImGui::Spacing();
					if (ImGui::Button("EQ Path"))
						ImGui::OpenModal("Input EQ Path");

					ImGui::SameLine();
					ImGui::Text("%s", new_group_path ? new_group_path->c_str() : "<Default>");

					if (ImGui::BeginModal("Input EQ Path", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
					{
						SetEQDir(new_group_path);

						ImGui::Separator();
						if (ImGui::Button("OK"))
							ImGui::CloseModal();

						ImGui::EndModal();
					}

					ImGui::Separator();
					if (ImGui::Button("Cancel"))
					{
						ImGui::CloseModal();
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

						ImGui::CloseModal();
					}

					ImGui::EndModal();
				}

				if (ImGui::SmallButton("Remove") && current_group)
					ImGui::OpenModal("Delete Profile Group");

				if (ImGui::BeginModal("Delete Profile Group", nullptr, ImGuiWindowFlags_AlwaysAutoResize) && current_group)
				{
					ImGui::TextWrapped("Are you sure you want to delete profile group '%s'? All associated profiles will also be removed.", current_group->c_str());
					ImGui::Spacing();

					if (ImGui::Button("Yes##deletegroup", ImVec2(120, 0)))
					{
						login::db::DeleteProfileGroup(*current_group);
						current_group = {};
						ImGui::CloseModal();
					}

					ImGui::SetItemDefaultFocus();
					ImGui::SameLine();
					if (ImGui::Button("No##deletegroup", ImVec2(120, 0)))
					{
						ImGui::CloseModal();
					}

					ImGui::EndModal();
				}

				constexpr const char* label = "Profiles";
				ImGui::SameLine(ImGui::GetContentRegionMax().x - ImGui::CalcTextSize(label).x - 5.f);
				ImGui::Text(label);

				ImGui::EndMenuBar();
			}
			ImGui::PopID();

			ImGui::PushID("profilecombo");
			ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x - ButtonWidth("Add Profile") - ButtonWidth("Launch Group"));
			if (ImGui::BeginCombo("##profilegroups", current_group ? current_group->c_str() : ""))
			{
				for (const auto& group : login::db::ListProfileGroups())
				{
					bool is_selected = current_group && ci_equals(group, *current_group);
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
				ImGui::OpenModal("Add Profile");
			}

			if (current_group && ImGui::BeginModal("Add Profile", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
			{
				ShowAddProfile(*current_group, interim_profile);
				ImGui::EndModal();
			}

			if (!edit_profile && current_group && interim_profile.finalize && interim_profile.current_character)
			{
				ProfileRecord record;
				record.profileName = *current_group;
				record.serverName = interim_profile.current_character->first;
				record.characterName = interim_profile.current_character->second;
				record.hotkey = interim_profile.hotkey ? *interim_profile.hotkey : "";
				record.eqPath = interim_profile.eq_path;
				record.checked = true;

				interim_profile = {};

				login::db::CreateProfile(record);
			}

			ImGui::SameLine();
			if (ImGui::Button("Launch Group") && current_group)
			{
				LoadProfileGroup(*current_group);
			}

			ImGui::PushID("mainlist");
			if (ImGui::BeginTable("##maintable", 6, ImGuiTableFlags_SizingStretchProp | ImGuiTableFlags_Borders | ImGuiTableFlags_NoBordersInBody))
			{
				if (current_group)
				{
					ImGui::TableSetupColumn("Account");
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
						if (ImGui::Selectable("##rowselect", &profile.checked, ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_AllowOverlap))
							login::db::UpdateProfile(profile);

						if (ImGui::IsItemHovered() && ImGui::IsItemClicked(ImGuiMouseButton_Right))
							ImGui::OpenPopup("row_popup");

						if (ImGui::BeginPopup("row_popup"))
						{
							if (ImGui::Selectable("Edit"))
							{
								interim_profile.current_character = std::make_pair(profile.serverName, profile.characterName);
								interim_profile.current_account = profile.accountName;
								interim_profile.hotkey = profile.hotkey;
								interim_profile.eq_path = profile.eqPath;
								interim_profile.char_preview = fmt::format("{} : {}", profile.serverName, profile.characterName);
								
								interim_profile.finalize = false;

								edit_profile = true;
							}

							if (ImGui::Selectable("Remove"))
								login::db::DeleteProfile(profile.serverName, profile.characterName, *current_group);

							ImGui::EndPopup();
						}

						ImGui::SameLine();
						ImGui::Text(profile.accountName.c_str());

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

					if (edit_profile && interim_profile.current_character)
						ImGui::OpenModal("Edit Profile");

					if (ImGui::BeginModal("Edit Profile", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
					{
						ShowAddProfile(*current_group, interim_profile);
						ImGui::EndModal();
					}

					if (interim_profile.finalize && interim_profile.current_character)
					{
						ProfileRecord record;
						record.profileName = *current_group;
						record.serverName = interim_profile.current_character->first;
						record.characterName = interim_profile.current_character->second;
						record.hotkey = interim_profile.hotkey ? *interim_profile.hotkey : "";
						record.eqPath = interim_profile.eq_path;
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
			ImGui::BeginChild("##mainchild", ImVec2(0, 0), ImGuiChildFlags_Border, ImGuiWindowFlags_MenuBar);

			static std::string search;
			static auto matches = login::db::ListCharacterMatches(search);
			static ProfileRecord interim_profile;
			static std::optional<std::pair<std::string, std::string>> selected;

			ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x - ButtonWidth("Add Character"));
			if (ImGui::InputText("##searchbar", &search, ImGuiInputTextFlags_EscapeClearsAll))
			{
				matches = login::db::ListCharacterMatches(search);
			}

			ImGui::SameLine();
			if (ImGui::Button("Add Character"))
			{
				// reset to defaults
				interim_profile = {};
				ImGui::OpenModal("Add Character");
			}

			if (ImGui::BeginModal("Add Character", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
			{
				ImGui::InputText("Account##createcharacter", &interim_profile.accountName);
				ImGui::Spacing();

				ImGui::InputText("Server##createcharacter", &interim_profile.serverName);
				ImGui::Spacing();

				ImGui::InputText("Name##createcharacter", &interim_profile.characterName);
				ImGui::Spacing();

				if (ImGui::Button("OK##createcharacter", ImVec2(120, 0)))
				{
					login::db::CreateCharacter(interim_profile);
					ImGui::CloseModal();
				}

				ImGui::SetItemDefaultFocus();
				ImGui::SameLine();
				if (ImGui::Button("Cancel##createcharacter", ImVec2(120, 0)))
				{
					ImGui::CloseModal();
				}

				ImGui::EndModal();
			}

			ImGui::PushID("mainlist");
			if (ImGui::BeginTable("##maintable", 5, ImGuiTableFlags_SizingStretchProp | ImGuiTableFlags_Borders | ImGuiTableFlags_NoBordersInBody))
			{
				ImGui::TableSetupColumn("Account");
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

					// this allows right clicking
					bool is_selected = false;
					ImGui::Selectable("##rowselect", &is_selected, ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_AllowOverlap);
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
					if (ImGui::SmallButton("...##playwithparams"))
					{
						interim_profile = {};
						interim_profile.serverName = match.serverName;
						interim_profile.characterName = match.characterName;
						hotkey = {};
						ImGui::OpenModal("Play With Params");
					}

					if (ImGui::BeginModal("Play With Params", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
					{
						// input box for hotkey (optional)
						if (ImGui::Button("Hotkey"))
							ImGui::OpenModal("Input Hotkey");

						ImGui::SameLine();
						ImGui::Text("%s", hotkey ? hotkey->c_str() : "<None>");

						if (ImGui::BeginModal("Input Hotkey", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
						{
							ShowHotkeyWindow(hotkey);

							ImGui::Separator();
							if (ImGui::Button("OK"))
								ImGui::CloseModal();

							ImGui::EndModal();
						}

						// input for eq path override (optional)
						if (ImGui::Button("EQ Path"))
							ImGui::OpenModal("Input EQ Path");

						ImGui::SameLine();
						ImGui::Text("%s", interim_profile.eqPath ? interim_profile.eqPath->c_str() : "<Default>");

						if (ImGui::BeginModal("Input EQ Path", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
						{
							SetEQDir(interim_profile.eqPath);

							ImGui::Separator();
							if (ImGui::Button("OK"))
								ImGui::CloseModal();

							ImGui::EndModal();
						}

						if (ImGui::Button("Cancel"))
							ImGui::CloseModal();


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

							ImGui::CloseModal();
						}

						ImGui::EndModal();
					}

					ImGui::PopID();
					ImGui::PopID();
				}

				if (selected)
					ImGui::OpenModal("Edit Character");

				if (ImGui::BeginModal("Edit Character", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
				{
					ImGui::InputText("Account##editcharacter", &interim_profile.accountName);
					ImGui::Spacing();

					ImGui::InputText("Server##editcharacter", &interim_profile.serverName);
					ImGui::Spacing();

					ImGui::InputText("Name##editcharacter", &interim_profile.characterName);
					ImGui::Spacing();

					if (ImGui::Button("OK##editcharacter", ImVec2(120, 0)))
					{
						if (selected)
							login::db::UpdateCharacter(selected->first, selected->second, interim_profile);

						selected = {};
						interim_profile = {};
						ImGui::CloseModal();
					}

					ImGui::SetItemDefaultFocus();
					ImGui::SameLine();
					if (ImGui::Button("Cancel##editcharacter", ImVec2(120, 0)))
					{
						ImGui::CloseModal();
					}

					ImGui::EndModal();
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
}

struct SizedProfileRecord
{
	ProfileRecord profile;
	std::string level_text;
	float level_size;
	float class_size;
};
void ShowAutoLoginMenu()
{
	ImGui::PushID("contextmenu");

	bool is_paused = false;
	if (auto raw_pause = login::db::ReadSetting("is_paused"))
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
						auto level_size = ImGui::CalcTextSize(level_text.c_str()).x;
						if (level_size > largest_level) largest_level = level_size;

						auto class_size = ImGui::CalcTextSize(profile.characterClass.c_str()).x;
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
						auto& profile = sized_profile.profile;
						ImGui::PushID(profile.characterName.c_str());
						ImGui::PushID(profile.serverName.c_str());

						if (ImGui::SmallCheckbox("##checked", &profile.checked))
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

						ImGui::SameLine(0, largest_level - ImGui::CalcTextSize(sized_profile.level_text.c_str()).x);
						ImGui::TextUnformatted(sized_profile.level_text.c_str());

						ImGui::SameLine(); ImGui::TextUnformatted(" ");

						ImGui::SameLine(0, largest_class - ImGui::CalcTextSize(profile.characterClass.c_str()).x);
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
						auto level_size = ImGui::CalcTextSize(level_text.c_str()).x;
						if (level_size > largest_level) largest_level = level_size;

						auto class_size = ImGui::CalcTextSize(profile.characterClass.c_str()).x;
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
						auto& profile = sized_profile.profile;
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

						ImGui::SameLine(0, largest_level - ImGui::CalcTextSize(sized_profile.level_text.c_str()).x);
						ImGui::TextUnformatted(sized_profile.level_text.c_str());

						ImGui::SameLine(); ImGui::TextUnformatted(" ");

						ImGui::SameLine(0, largest_class - ImGui::CalcTextSize(profile.characterClass.c_str()).x);
						ImGui::TextUnformatted(profile.characterClass.c_str());

						ImGui::SameLine(0, 0); ImGui::Text("] %s ", profile.characterName.c_str());

						ImGui::PushStyleVar(ImGuiStyleVar_Alpha, ImGui::GetStyle().Alpha * 0.25f);
						ImGui::SameLine(); ImGui::Text(profile.accountName.c_str());
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

#pragma endregion

static LoginInstance ParseInstanceFromMessage(const proto::login::StartInstanceMissive& start)
{
	LoginInstance instance;

	switch (start.method_case())
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

void ReceivedMessageHandler(ProtoMessagePtr&& message)
{
	// TODO: This needs to handle identify messages (to fill loaded instance set)
	auto login_message = message->Parse<proto::login::LoginMessage>();
	switch (login_message.id())
	{
	case proto::login::MessageId::ProfileLoaded:
		// this message needs to come from the client after it has injected,
		// this acts as an ack or an update
		if (login_message.has_payload())
		{
			proto::login::StartInstanceMissive start;
			start.ParseFromString(login_message.payload());
			auto login_it = StartOrUpdateInstance(ParseInstanceFromMessage(start), false);

			// only set the hotkey if the instance reports successfully loaded
			if (login_it != s_loadedInstances.end() && login_it->Hotkey)
				RegisterGlobalHotkey(GetEQWindowHandleForProcessId(login_it->PID), *login_it->Hotkey);
		}

		break;

	case proto::login::MessageId::ProfileUnloaded:
		if (login_message.has_payload())
		{
			proto::login::StopInstanceMissive stop;
			stop.ParseFromString(login_message.payload());
			auto login_it = std::find_if(s_loadedInstances.begin(), s_loadedInstances.end(),
				[pid = stop.pid()](const LoginInstance& instance) { return instance.PID == pid; });
			if (login_it != s_loadedInstances.end())
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
			profile.characterLevel = charinfo.level();
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

void InitializeAutoLogin()
{
	s_dropbox = postoffice::GetPostOffice().RegisterAddress("autologin", ReceivedMessageHandler);
	// TODO: build list of logged in instances from the list of registered clients in the post office
	// TODO: figure out how to determine hotkeys from that list

	// Get path to mq2autologin.ini
	fs::path pathAutoLoginIni = fs::path{ internal_paths::Config }  / "MQ2AutoLogin.ini";
	internal_paths::AutoLoginIni = pathAutoLoginIni.string();
	auto load_ini = login::db::InitDatabase((fs::path(internal_paths::Config) / "login.db").string());

	// do absolutely nothing until a master pass is set
	// TODO: add in checkbox for never forget, and a button to pull the password from registry. Also clean up
	auto pass = login::db::ReadMasterPass();
	if (!pass)
	{
		LauncherImGui::OpenWindow(
			[&pass]() {
				bool is_open = true;
				if (ImGui::Begin("Enter Master Password", &is_open))
				{
					static const char* label = "Please Enter Master Password";
					ImGui::Text(label);
					ImGui::Spacing();

					// TODO: This can be a lot nicer -- also the hashing can take a bit so it should
					// probably happen in a thread to prevent the UI from hanging on slower computers
					static bool show_password = false;
					static std::string password;

					ImGuiInputTextFlags flags = ImGuiInputTextFlags_EnterReturnsTrue;
					if (!show_password) flags |= ImGuiInputTextFlags_Password;


					if (ImGui::InputText("##password", &password, flags))
					{
						if (login::db::ValidatePass(password, true))
						{
							login::db::CreateMasterPass(password);
							pass = password;
							is_open = false;
							label = "Please Enter Master Password";
						}
						else
						{
							label = "Incorrect Password, Please Enter Master Password";
						}
					}
					ImGui::Spacing();

					ImGui::Checkbox("Show password", &show_password);
					ImGui::Spacing();
				}

				ImGui::End();
				return is_open;
			},
			"Enter Master Password"
		);
	}

	if (pass)
	{
		if (load_ini) login::db::WriteProfileGroups(LoadAutoLoginProfiles(internal_paths::AutoLoginIni));

		// Initialize path to EQ
		internal_paths::EQRoot = login::db::ReadEQPath();
		if (internal_paths::EQRoot.empty())
		{
			internal_paths::EQRoot = GetPrivateProfileString("Profiles", "DefaultEQPath", "", internal_paths::AutoLoginIni);
			if (internal_paths::EQRoot.empty())
			{
				SPDLOG_ERROR("AutoLogin Error no EQ path specified, AutoLogin will not work.");
			}
			else
			{
				// update the path to the db
				login::db::CreateEQPath(internal_paths::EQRoot);
			}
		}

		LauncherImGui::AddMainPanel("AutoLogin", ShowAutoLoginWindow);
		LauncherImGui::AddContextGroup("AutoLogin Menu", ShowAutoLoginMenu);
	}
}

void ShutdownAutoLogin()
{
	s_dropbox.Remove();

	if (s_eqDirDialog != nullptr)
		IGFD_Destroy(s_eqDirDialog);
}
