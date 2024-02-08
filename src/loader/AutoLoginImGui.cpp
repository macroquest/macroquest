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
#include "AutoLogin.h"

#include "login/Login.h"
#include "ImGui.h"

#include <spdlog/spdlog.h>

#include <fmt/format.h>
#include <fmt/compile.h>

#include "imgui/ImGuiFileDialog.h"
#include "imgui/misc/cpp/imgui_stdlib.h"
#include "imgui_internal.h"

#include <filesystem>

namespace fs = std::filesystem;
using namespace mq;

namespace {
ImGuiFileDialog* s_eqDirDialog = nullptr;

#pragma region Helpers

using Action = std::function<void()>;

void DefaultModalButtons(const Action& ok_action, const char* cancel = "Cancel", const char* ok = "OK")
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

template <typename T>
void DefaultOptional(std::optional<T>& opt, const char* label, const std::function<T()>& set_action, const std::function<bool(T&)>& input_action)
{
	bool override_toggle = opt.has_value();
	LauncherImGui::ToggleSlider(label, &override_toggle);

	if (override_toggle)
	{
		if (!opt)
		{
			opt = set_action();
		}

		auto opt_val = *opt;
		const float indent = ImGui::GetFrameHeight() * 1.55f + ImGui::GetStyle().ItemInnerSpacing.x;
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + indent);
		ImGui::SetNextItemWidth(ImGui::CalcItemWidth() - indent);
		if (input_action(opt_val))
			opt = opt_val;
	}
	else if (opt)
		opt.reset();
}

void DeleteModal(const std::string& name, const std::string_view message, const Action& yes_action)
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

struct ServerNameInfo
{
	std::string ShortName;
	std::string LongName;

	void List(const Action&);
	void Fill();
	[[nodiscard]] std::string Preview() const;
	void Edit(const char*, const Action&);

	void Update(const ServerNameInfo&) const
	{
		if (*this)
			login::db::CreateOrUpdateServer(ShortName, LongName);
	}

	void Delete() const
	{
		login::db::DeleteServer(ShortName, LongName);
	}

	static constexpr std::string_view label = "Server Name";

	explicit operator bool() const { return !ShortName.empty() && !LongName.empty(); }
};

struct ServerTypeInfo
{
	std::string ServerType;
	std::string EQPath;

	void List(const Action&);
	void Fill();
	[[nodiscard]] std::string Preview() const;
	void Edit(const char*, const Action&);

	void Update(const ServerTypeInfo&) const
	{
		if (*this && !EQPath.empty())
			login::db::CreateOrUpdateServerType(ServerType, EQPath);
	}

	void Delete() const
	{
		login::db::DeleteServerType(ServerType);
	}

	static constexpr std::string_view label = "Server Type";

	explicit operator bool() const { return !ServerType.empty(); }
};

struct AccountInfo
{
	std::string Account;
	std::string Password;
	ServerTypeInfo ServerType;

	void List(const Action&);
	void Fill();
	[[nodiscard]] std::string Preview() const;
	void Edit(const char*, const Action&);

	void Update(const AccountInfo& old) const
	{
		if (*this && !Password.empty())
		{
			ProfileRecord profile;
			profile.accountName = Account;
			profile.accountPassword = Password;
			profile.serverType = ServerType.ServerType;

			if (old)
				login::db::UpdateAccount(old.Account, old.ServerType.ServerType, profile);
			else
				login::db::CreateAccount(profile);
		}
	}

	void Delete() const
	{
		login::db::DeleteAccount(Account, ServerType.ServerType);
	}

	static constexpr std::string_view label = "Account";

	explicit operator bool() const { return !Account.empty() && ServerType; }
};

struct CharacterInfo
{
	AccountInfo Account;
	std::string Server;
	std::string Character;

	void List(const Action&);
	void Fill();
	[[nodiscard]] std::string Preview() const;
	void Edit(const char*, const Action&);

	void Update(const CharacterInfo& old) const
	{
		if (*this && !Account.Account.empty() && !Account.ServerType.ServerType.empty())
		{
			ProfileRecord profile;
			profile.characterName = Character;
			profile.serverName = Server;
			profile.accountName = Account.Account;
			profile.serverType = Account.ServerType.ServerType;

			if (old)
				login::db::UpdateCharacter(old.Server, old.Character, profile);
			else
				login::db::CreateCharacter(profile);
		}
	}

	void Delete() const
	{
		login::db::DeleteCharacter(Server, Character);
	}

	static constexpr std::string_view label = "Character";

	explicit operator bool() const { return !Server.empty() && !Character.empty(); }
};

struct ProfileInfo : ProfileRecord
{
	CharacterInfo Character;

	void Fill();
	[[nodiscard]] std::string Preview() const;
	void Edit(const char*, const Action&);

	static constexpr std::string_view label = "Profile";

	explicit operator bool() const { return !profileName.empty() && Character; }

	ProfileInfo& operator=(const ProfileRecord& record)
	{
		ProfileRecord::operator=(record);
		Character = {};
		return *this;
	}
};

struct ProfileGroupInfo : ProfileGroup
{
	void List(const Action&);
	void Fill();
	[[nodiscard]] std::string Preview() const;
	void Edit(const char*, const Action&);

	void Update(const ProfileGroupInfo& old) const
	{
		if (!profileName.empty())
		{
			if (old)
				login::db::UpdateProfileGroup(old.profileName, *this);
			else
				login::db::CreateProfileGroup(*this);
		}
	}

	void Delete() const
	{
		login::db::DeleteProfileGroup(profileName);
	}

	static constexpr std::string_view label = "Profile Group";
	static constexpr std::string_view label_override;

	explicit operator bool() const { return !profileName.empty(); }
};

template <typename Info>
void DefaultListBox(Info& info)
{
	static Info selected;

	static constexpr std::string_view hidden_prefix = "##";
	ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
	if (ImGui::BeginListBox(JoinLabels<hidden_prefix, Info::label>::literal))
	{
		info.List([] {});
		ImGui::EndListBox();
	}

	if (ImGui::IsKeyPressed(ImGuiKey_Escape))
		info = {};

	static constexpr std::string_view add_prefix = "Add ";
	static constexpr const char* add_name = JoinLabels<add_prefix, Info::label>::literal;
	if (ImGui::Button(add_name))
	{
		selected = {};
		LauncherImGui::OpenModal(add_name);
	}
	selected.Edit(add_name, [&info]
		{
			selected.Update(info);
			info = selected;
		});

	static constexpr std::string_view edit_prefix = "Edit ";
	static constexpr const char* edit_name = JoinLabels<edit_prefix, Info::label>::literal;
	ImGui::SameLine();
	if (ImGui::Button(edit_name) || ImGui::IsKeyPressed(ImGuiKey_Enter))
	{
		if (info)
		{
			selected = info;
			selected.Fill();

			LauncherImGui::OpenModal(edit_name);
		}
	}
	selected.Edit(edit_name, [&info]
		{
			selected.Update(info);
			info = selected;
		});

	static constexpr std::string_view remove_prefix = "Remove ";
	static constexpr const char* remove_name = JoinLabels<remove_prefix, Info::label>::literal;
	static std::string remove_message;
	ImGui::SameLine();
	if (ImGui::Button(remove_name) || ImGui::IsKeyPressed(ImGuiKey_Delete))
	{
		if (info)
		{
			remove_message = fmt::format("Are you sure you want to remove {} '{}'? All dependent data will also be removed.", Info::label, info.Preview());
			LauncherImGui::OpenModal(remove_name);
		}
	}

	DeleteModal(remove_name, remove_message, [&info]
		{
			info.Delete();
			info = {};
		});
}

template <typename Info>
void DefaultCombo(Info& info, const Action& select_action)
{
	static Info selected;

	static constexpr std::string_view hidden_prefix = "##";
	const auto width = ImGui::CalcItemWidth() - ImGui::CalcTextSize("...").x - ImGui::GetStyle().FramePadding.x * 2;
	ImGui::SetNextItemWidth(width);
	if (ImGui::BeginCombo(JoinLabels<hidden_prefix, Info::label>::literal, info.Preview().c_str(), ImGuiComboFlags_NoArrowButton))
	{
		info.List(select_action);

		ImGui::EndCombo();
	}

	static constexpr std::string_view modal_suffix = " Select";
	static constexpr const char* modal_name = JoinLabels<Info::label, modal_suffix>::literal;

	static constexpr std::string_view button_prefix = "...##";
	static constexpr const char* button_label = JoinLabels<button_prefix, Info::label>::literal;

	ImGui::SameLine(0.f, 0.f);
	if (ImGui::Button(button_label))
	{
		selected = info;
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
		DefaultListBox(selected);

		DefaultModalButtons([&info]
			{
				selected.Update(info);
				info = selected;
			});

		LauncherImGui::EndModal();
	}
}

void SetEQDirModal(std::optional<std::string>& eq_path, const Action& ok_action)
{
	if (LauncherImGui::BeginModal("Input EQ Path", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		if (eq_path)
			ImGui::Text(eq_path->c_str());
		else
			ImGui::Text(GetEQRoot());

		if (!s_eqDirDialog)
			s_eqDirDialog = IGFD_Create();

		if (ImGui::Button("Choose"))
		{
			IGFD_OpenDialog(s_eqDirDialog, "ChooseEQDirKey", "Choose Default EverQuest Directory",
				nullptr, GetEQRoot(), "", 1, nullptr, ImGuiFileDialogFlags_None);
		}

		if (IGFD_DisplayDialog(s_eqDirDialog, "ChooseEQDirKey", ImGuiFileDialogFlags_None, ImVec2(350, 350), ImVec2(FLT_MAX, FLT_MAX)))
		{
			if (IGFD_IsOk(s_eqDirDialog))
			{
				const std::shared_ptr<char> selected_path(IGFD_GetCurrentPath(s_eqDirDialog), IGFD_DestroyString);
				if (std::error_code ec; selected_path && fs::exists(selected_path.get(), ec))
				{
					eq_path = canonical(fs::path(selected_path.get()), ec).string();
				}
			}

			IGFD_CloseDialog(s_eqDirDialog);
		}

		DefaultModalButtons(ok_action);

		LauncherImGui::EndModal();
	}
}

void SetEQFileModal(const char* label, std::optional<fs::path>& path, const char* default_path, const Action& ok_action)
{
	if (LauncherImGui::BeginModal(label, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		if (path)
			ImGui::Text(path->string().c_str());
		else
			ImGui::Text(default_path);

		if (!s_eqDirDialog)
			s_eqDirDialog = IGFD_Create();

		if (ImGui::Button("Choose"))
		{
			IGFD_OpenDialog(s_eqDirDialog, "ChoosePathKey", label,
				".ini", GetEQRoot(), default_path, 1, nullptr, ImGuiFileDialogFlags_None);
		}

		if (IGFD_DisplayDialog(s_eqDirDialog, "ChoosePathKey", ImGuiFileDialogFlags_None, ImVec2(350, 350), ImVec2(FLT_MAX, FLT_MAX)))
		{
			if (IGFD_IsOk(s_eqDirDialog))
			{
				const std::shared_ptr<char> selected_path(IGFD_GetCurrentPath(s_eqDirDialog), IGFD_DestroyString);
				const std::shared_ptr<char> selected_file(IGFD_GetCurrentFileName(s_eqDirDialog, IGFD_ResultMode_KeepInputFile), IGFD_DestroyString);
				if (std::error_code ec; selected_path && selected_file && exists(fs::path(selected_path.get()) / fs::path(selected_file.get()), ec))
				{
					path = relative(fs::path(selected_path.get()) / fs::path(selected_file.get()), GetEQRoot(), ec);
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

void ShowHotkeyWindow(const std::string& name, std::string& hotkey, const Action& ok_action)
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

		DefaultModalButtons(ok_action);

		LauncherImGui::EndModal();
	}
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
		ImGui::PushID(short_name.c_str());
		ImGui::PushID(long_name.c_str());

		const bool is_selected = ci_equals(short_name, ShortName) &&
			ci_equals(long_name, LongName);

		format_to(buf_ins, "[{}] {}", short_name, long_name);

		if (ImGui::Selectable("", is_selected, ImGuiSelectableFlags_SpanAvailWidth))
		{
			ShortName = short_name;
			LongName = long_name;

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

void ServerNameInfo::Fill() {}

std::string ServerNameInfo::Preview() const
{
	if (*this)
		return fmt::format("[{}] {}", ShortName, LongName);

	return "";
}

void ServerNameInfo::Edit(const char* name, const Action& ok_action)
{
	if (LauncherImGui::BeginModal(name, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::InputText("Short Name", &ShortName);
		ImGui::Spacing();

		ImGui::InputText("Long Name", &LongName);

		DefaultModalButtons(ok_action);

		LauncherImGui::EndModal();
	}
}

#pragma endregion

#pragma region ServerType

void ServerTypeInfo::List(const Action& select_action)
{
	static auto server_types = CacheResults(login::db::ListServerTypes);
	for (const auto& server_type : server_types.Read())
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

void ServerTypeInfo::Edit(const char* name, const Action& ok_action)
{
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

#pragma endregion

#pragma region Account

void AccountInfo::List(const Action& select_action)
{
	fmt::memory_buffer buf;
	const auto buf_ins = std::back_inserter(buf);

	static auto accounts = CacheResults(login::db::ListAccounts);
	for (const auto& [account, server_type] : accounts.Read())
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
	if (*this)
		return fmt::format("{} ({})", Account, ServerType.ServerType);

	return "";
}

void AccountInfo::Edit(const char* name, const Action& ok_action)
{
	static bool show_password = false;

	if (LauncherImGui::BeginModal(name, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::TextWrapped("Editing Account %s", Preview().c_str());
		ImGui::Spacing();

		ImGui::InputText("Account Name", &Account);
		ImGui::Spacing();

		DefaultCombo(ServerType, [this]
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

#pragma endregion

#pragma region Character

void CharacterInfo::List(const Action& select_action)
{
	fmt::memory_buffer buf;
	const auto buf_ins = std::back_inserter(buf);

	static auto last_account = Account.Account;
	static auto last_server_type = Account.ServerType.ServerType;
	static auto characters = login::db::CacheResults([]
		{ return login::db::ListCharacters(last_account, last_server_type); });

	// this could happen a couple ways:
	//  - the account on `this` changes
	//  - we have a different instance of `this` with a different account (it's static)
	const bool force_update = !ci_equals(last_account, Account.Account) ||
		!ci_equals(last_server_type, Account.ServerType.ServerType);
	if (force_update)
	{
		last_account = Account.Account;
		last_server_type = Account.ServerType.ServerType;
	}

	for (const auto& [server, character] : characters.Read(force_update))
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

		ImGui::SameLine();
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
	if (*this)
		return fmt::format("{} : {}", Character, Server);

	return "";
}

void CharacterInfo::Edit(const char* name, const Action& ok_action)
{
	if (LauncherImGui::BeginModal(name, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::TextWrapped("Editing Character %s", Preview().c_str());
		ImGui::Spacing();

		DefaultCombo(Account, [this]
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

void CharacterTable(const std::string_view search)
{
	static CharacterInfo selected_character;
	static ProfileInfo selected_profile;
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

		static std::string last_search(search);
		static auto characters = login::db::CacheResults([]
			{
				return login::db::ListCharacterMatches(last_search);
			});

		const bool force_update = !ci_equals(last_search, search);
		if (force_update)
			last_search = search;

		for (const auto& match : characters.Read(force_update))
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
					selected_character.Server = match.serverName;
					selected_character.Character = match.characterName;
					selected_character.Account.Account = match.accountName;
					selected_character.Account.ServerType.ServerType = match.serverType;

					selected_profile = match;
					selected_profile.Character = selected_character;

					LauncherImGui::OpenModal("Edit Character");
				}

				if (ImGui::Selectable("Remove"))
				{
					remove_message = fmt::format("Are you certain you want to remove character '{} : {}'? All associated profiles will also be removed.", match.characterName, match.serverName);
					selected_profile = match;
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
				selected_profile = match;

				LauncherImGui::OpenModal("Play With Params");
			}

			ImGui::PopID();
			ImGui::PopID();
		}

		ImGui::EndTable();
	}

	selected_character.Edit("Edit Character", []
		{
			if (selected_character && selected_character.Account)
			{
				ProfileRecord profile;
				profile.characterName = selected_character.Character;
				profile.serverName = selected_character.Server;
				profile.accountName = selected_character.Account.Account;
				profile.serverType = selected_character.Account.ServerType.ServerType;
				login::db::UpdateCharacter(selected_profile.serverName, selected_profile.characterName, profile);
			}
		});

	DeleteModal("Remove Character", remove_message, []
		{
			login::db::DeleteCharacter(selected_profile.serverName, selected_profile.characterName);
		});

	if (LauncherImGui::BeginModal("Play With Params", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		static std::optional<std::string> eq_path;
		static std::string hotkey;
		// input box for hotkey (optional)
		if (ImGui::Button("Hotkey"))
		{
			hotkey = selected_profile.hotkey;
			LauncherImGui::OpenModal("Input Hotkey");
		}

		ShowHotkeyWindow("Input Hotkey", hotkey,
			[] { selected_profile.hotkey = hotkey; });

		ImGui::SameLine();
		ImGui::Text("%s", !selected_profile.hotkey.empty() ? selected_profile.hotkey.c_str() : "<None>");

		// input for eq path override (optional)
		if (ImGui::Button("EQ Path"))
		{
			eq_path = selected_profile.eqPath;
			LauncherImGui::OpenModal("Input EQ Path");
		}

		SetEQDirModal(eq_path, [] { selected_profile.eqPath = eq_path; });

		ImGui::SameLine();
		ImGui::Text("%s", selected_profile.eqPath ? selected_profile.eqPath->c_str() : "<Default>");

		DefaultModalButtons([]
		{
				LoginInstance instance;
				instance.Server = selected_profile.serverName;
				instance.Character = selected_profile.characterName;
				if (!selected_profile.hotkey.empty()) instance.Hotkey = selected_profile.hotkey;
				instance.EQPath = selected_profile.eqPath;

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
	if (*this)
		return fmt::format("[{}] {}", profileName, Character.Preview());

	return "";
}

void ProfileInfo::Edit(const char* name, const Action& ok_action)
{
	static std::optional<std::string> eq_path;
	static std::string hot_key;
	static std::optional<fs::path> custom_ini;

	if (LauncherImGui::BeginModal(name, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		DefaultCombo(Character.Account, [this]
			{
				Character.Character.clear();
				Character.Server.clear();
			});

		// drop down for character or create new, only show this if an account has been selected
		if (Character.Account)
		{
			DefaultCombo(Character, [this]
				{
					if (Character && !profileName.empty())
						login::db::ReadProfile(*this);
				});

			// display options to complete the profile only if the profile has a character
			if (Character)
			{
				if (ImGui::Button("Hotkey"))
				{
					hot_key = hotkey;
					LauncherImGui::OpenModal("Input Hotkey");
				}

				ShowHotkeyWindow("Input Hotkey", hot_key,
					[this] { hotkey = hot_key; });

				ImGui::SameLine();
				ImGui::Text("%s", !hotkey.empty() ? hotkey.c_str() : "<None>");

				if (ImGui::Button("EQ Path"))
				{
					eq_path = eqPath;
					LauncherImGui::OpenModal("Input EQ Path");
				}

				SetEQDirModal(eq_path, [this] { eqPath = eq_path; });

				ImGui::SameLine();
				ImGui::Text("%s", eqPath ? eqPath->c_str() : "<Default>");

				DefaultOptional<int>(charSelectDelay, "Override Character Select Delay",
					[]()
					{
						if (const auto delay = login::db::ReadSetting("char_select_delay"))
							return GetIntFromString(*delay, 3);
						return 3;
					},
					[](int& char_select_delay)
					{
						return ImGui::InputScalar("##Character Select Delay", ImGuiDataType_U32, &char_select_delay);
					});

				DefaultOptional<bool>(endAfterSelect, "Override End After Character Select",
					[]()
					{
						if (const auto end = login::db::ReadSetting("end_after_select"))
							return GetBoolFromString(*end, false);
						return false;
					},
					[](bool& end_after_select)
					{
						bool changed = false;
						if (ImGui::BeginCombo("##End After Character Select", end_after_select ? "enabled" : "disabled"))
						{
							if (ImGui::Selectable("enabled", end_after_select))
							{
								end_after_select = true;
								changed = true;
							}

							if (ImGui::Selectable("disabled", !end_after_select))
							{
								end_after_select = false;
								changed = true;
							}

							ImGui::EndCombo();
						}

						return changed;
					});

				if (ImGui::Button("Custom Character INI"))
				{
					custom_ini = customClientIni;
					LauncherImGui::OpenModal("Input Character INI File");
				}

				SetEQFileModal("Input Character INI File", custom_ini, "eqclient.ini",
					[this] { customClientIni = custom_ini; });

				ImGui::SameLine();
				ImGui::Text("%s", customClientIni ? customClientIni->string().c_str() : "<Default>");
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
						selected = profile;
						selected.Character.Character = profile.characterName;
						selected.Character.Server = profile.serverName;
						selected.Character.Account.Account = profile.accountName;
						selected.Character.Account.ServerType.ServerType = profile.serverType;
						LauncherImGui::OpenModal("Edit Profile");
					}

					if (ImGui::Selectable("Remove"))
					{
						selected = profile;
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
		selected = {};
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
				selected.accountName = selected.Character.Account.Account;
				selected.serverType = selected.Character.Account.ServerType.ServerType;
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

void ProfileGroupInfo::List(const Action& select_action)
{
	static auto profile_groups = CacheResults(login::db::ListProfileGroups);
	for (const auto& group : profile_groups.Read())
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

void ProfileGroupInfo::Edit(const char* name, const Action& ok_action)
{
	static std::optional<std::string> eq_path;
	if (LauncherImGui::BeginModal(name, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::InputText("Profile Group Name", &profileName);

		ImGui::Spacing();
		if (ImGui::Button("EQ Path"))
		{
			eq_path = eqPath;
			LauncherImGui::OpenModal("Input EQ Path");
		}

		SetEQDirModal(eq_path, [this] { eqPath = eq_path; });

		ImGui::SameLine();
		ImGui::Text("%s", eqPath ? eqPath->c_str() : "<Default>");

		DefaultModalButtons(ok_action);

		LauncherImGui::EndModal();
	}
}

#pragma endregion

#pragma region Password

void ShowValidatePassword(const Action& ok_action)
{
	static const char* label = "Please Enter Master Password";

	ImGui::SetCursorPosX(std::max(0.f, ImGui::GetContentRegionAvail().x / 2.f - ImGui::CalcTextSize(label).x / 2.f));
	ImGui::Text(label);
	ImGui::Spacing();

	static bool show_password = false;
	static std::string password;

	ImGuiInputTextFlags flags = ImGuiInputTextFlags_None;
	if (!show_password) flags |= ImGuiInputTextFlags_Password;

	ImGui::InputText("##password", &password, flags);
	ImGui::Separator();

	ImGui::Checkbox("Show password", &show_password);
	ImGui::SetItemTooltip("Show the password in plain text");
	ImGui::Spacing();

	ImGui::SetCursorPosX(ImGui::GetContentRegionMax().x - 75.f - ImGui::GetStyle().FramePadding.x * 2);
	if (ImGui::Button("OK", { 75.f, 0.f }))
	{
		if (!login::db::ReadSetting("master_pass") || login::db::ValidatePass(password))
		{
			login::db::MemoizeMasterPass(password);
			label = "Please Enter Master Password";

			ok_action();
		}
		else
		{
			label = "Incorrect Password, Please Enter Master Password";
		}
	}
	ImGui::SetItemTooltip("Attempt to validate the entered password against the database, or set it if it does not exist.");
}

void ShowNewPassword(const Action& ok_action)
{
	static constexpr const char* label = "Please Enter New Master Password";

	ImGui::SetCursorPosX(std::max(0.f, ImGui::GetContentRegionAvail().x / 2.f - ImGui::CalcTextSize(label).x / 2.f));
	ImGui::Text(label);
	ImGui::Spacing();

	static bool show_password = false;
	static auto perpetual_password = login::db::CacheSetting<bool>("perpetual_password", false, GetBoolFromString);
	static std::string password;

	ImGuiInputTextFlags flags = ImGuiInputTextFlags_None;
	if (!show_password) flags |= ImGuiInputTextFlags_Password;

	ImGui::InputText("##password", &password, flags);
	ImGui::Separator();

	ImGui::Checkbox("Show password", &show_password);
	ImGui::SetItemTooltip("Show the password in plain text");
	ImGui::SameLine();
	if (ImGui::Checkbox("Never ask again", &perpetual_password.Read()))
		login::db::WriteSetting("perpetual_password", perpetual_password.Updated() ? "true" : "false");
	ImGui::SetItemTooltip("Save the password to this system so that it never has to be entered again.");
	ImGui::Spacing();

	ImGui::SetCursorPosX(ImGui::GetContentRegionMax().x - 75.f - ImGui::GetStyle().FramePadding.x);
	if (ImGui::Button("OK", { 75.f, 0.f }))
	{
		if (const auto old_pass = login::db::GetMasterPass();
			old_pass || !login::db::ReadSetting("master_pass"))
		{
			if (password.empty())
				login::db::DeleteSetting("master_pass");
			else if (perpetual_password.Read())
				login::db::CreateMasterPass(password, 0);
			else
			{
				const auto hours_valid = login::db::CacheSetting<int>("password_timeout_hours", 720, GetIntFromString).Read();
				login::db::CreateMasterPass(password, hours_valid);
			}

			login::db::UpdateEncryptedData(old_pass ? *old_pass : "");

			ok_action();
		}
		else
			LauncherImGui::OpenModal("Enter Current Password");

		bool validate_open = true;
		if (LauncherImGui::BeginModal("Enter Current Password", &validate_open, ImGuiWindowFlags_AlwaysAutoResize))
		{
			ShowValidatePassword([] { LauncherImGui::CloseModal(); });
			LauncherImGui::EndModal();
		}
	}
	ImGui::SetItemTooltip("Set the new master password, will require validation of the current password if there is none stored\nAn empty password will proceed with no master password (all data will be stored in plaintext)");
}

#pragma endregion

}

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
					info = {};
					LauncherImGui::OpenModal("Create Profile Group");
				}

				info.Edit("Create Profile Group", []
					{
						if (info)
							login::db::CreateProfileGroup(info);
					});

				static std::string remove_message;
				if (ImGui::SmallButton("Remove") && info)
				{
					remove_message = fmt::format("Are you sure you want to remove profile group '{}'? All associated profiles will also be removed.", info.profileName.c_str());
					LauncherImGui::OpenModal("Remove Profile Group");
				}

				DeleteModal("Remove Profile Group", remove_message, []
					{
						if (info)
						{
							login::db::DeleteProfileGroup(info.profileName);
							info.profileName.clear();
						}
					});

				ImGui::EndMenuBar();
			}

			ImGui::SetNextItemWidth(ImGui::GetContentRegionMax().x -
				ImGui::CalcTextSize("Launch Group").x -
				ImGui::GetStyle().FramePadding.x * 2 -
				ImGui::GetStyle().ItemSpacing.x -
				ImGui::GetStyle().WindowPadding.x);
			DefaultCombo(info, [] {});

			ImGui::SameLine();
			if (ImGui::Button("Launch Group") && info)
			{
				LoadProfileGroup(info.profileName);
			}

			if (info) ProfileTable(info);

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
			static auto is_paused = login::db::CacheSetting<bool>("is_paused", false, GetBoolFromString);
			static auto debug = login::db::CacheSetting<bool>("debug", false, GetBoolFromString);
			static auto kick_active = login::db::CacheSetting<bool>("kick_active", true, GetBoolFromString);
			static auto end_after_select = login::db::CacheSetting<bool>("end_after_select", false, GetBoolFromString);
			static auto load_ini = login::db::CacheSetting<bool>("load_ini", false, GetBoolFromString);
			static auto char_select_delay = login::db::CacheSetting<int>("char_select_delay", 3, GetIntFromString);
			static auto connect_retries = login::db::CacheSetting<int>("connect_retries", 0, GetIntFromString);

			static auto password_timeout_hours = login::db::CacheSetting<int>("password_timeout_hours", 720, GetIntFromString);
			static std::string hours_label = fmt::format("Hours to Save Password ({:.1f} days)", static_cast<float>(password_timeout_hours.Read()) / 24.f);
			static auto perpetual_password = login::db::CacheSetting<bool>("perpetual_password", false, GetBoolFromString);

			static ServerTypeInfo server_type_info;
			static ServerNameInfo server_name_info;

			if (ImGui::Checkbox("Pause on Start", &is_paused.Read()))
				login::db::WriteSetting("is_paused", is_paused.Updated() ? "true" : "false", "Pause autologin when client starts");
			ImGui::SetItemTooltip("Pause autologin when client starts");

			ImGui::Spacing();
			if (ImGui::Checkbox("Debug Output", &debug.Read()))
				login::db::WriteSetting("debug", debug.Updated() ? "true" : "false", "Show plugin debug statements");
			ImGui::SetItemTooltip("Show plugin debug statements");

			ImGui::Spacing();
			if (ImGui::Checkbox("Kick Active Character", &kick_active.Read()))
				login::db::WriteSetting("kick_active", kick_active.Updated() ? "true" : "false", "Automatically kick the active character when prompted");
			ImGui::SetItemTooltip("Automatically kick the active character when prompted");

			ImGui::Spacing();
			if (ImGui::Checkbox("End After Character Select", &end_after_select.Read()))
				login::db::WriteSetting("end_after_select", end_after_select.Updated() ? "true" : "false", "Disable the plugin once the character has been selected");
			ImGui::SetItemTooltip("Disable the plugin once the character has been selected");

			ImGui::Spacing();
			if (ImGui::Checkbox("Load Legacy Config Next Load", &load_ini.Read()))
				login::db::WriteSetting("load_ini", load_ini.Updated() ? "true" : "false", "Import data from autologin ini file one time at load");
			ImGui::SetItemTooltip("Import data from autologin ini file one time at load");
			
			ImGui::Spacing();
			if (ImGui::InputScalar("Character Select Delay", ImGuiDataType_U32, &char_select_delay.Read()))
				login::db::WriteSetting("char_select_delay", std::to_string(char_select_delay.Updated()), "Seconds to delay character selection at the character select screen");
			ImGui::SetItemTooltip("Seconds to delay character selection at the character select screen");

			ImGui::Spacing();
			if (ImGui::InputScalar("Connect Retries", ImGuiDataType_U32, &connect_retries.Read()))
				login::db::WriteSetting("connect_retries", std::to_string(connect_retries.Updated()), "Number of times to attempt to reconnect, 0 for infinite");
			ImGui::SetItemTooltip("Number of times to attempt to reconnect, 0 for infinite");

			ImGui::Spacing();
			if (ImGui::Button("Load Legacy Config"))
				Import();
			ImGui::SetItemTooltip("Import data from autologin ini right now");

			ImGui::Separator();
			ImGui::Spacing();
			if (ImGui::Checkbox("Save Password Forever", &perpetual_password.Read()))
				login::db::WriteSetting("perpetual_password", perpetual_password.Updated() ? "true" : "false", "Save the master password to this system so that it never has to be entered again");
			ImGui::SetItemTooltip("Save the master password to this system so that it never has to be entered again");

			ImGui::Spacing();
			ImGui::BeginDisabled(perpetual_password.Read());
			if (ImGui::InputScalar(hours_label.c_str(), ImGuiDataType_U32, &password_timeout_hours.Read()))
			{
				hours_label = fmt::format("Hours to Save Password ({:.1f} days)", static_cast<float>(password_timeout_hours.Updated()) / 24.f);
				login::db::WriteSetting("password_timeout_hours", std::to_string(password_timeout_hours.Updated()), "Number of hours to save the master password before requiring re-entry");
			}
			ImGui::SetItemTooltip("Number of hours to save the master password before requiring re-entry");
			ImGui::EndDisabled();

			ImGui::Spacing();
			if (ImGui::Button("Retrieve Master Password"))
				LauncherImGui::OpenModal("Stored Master Password");
			ImGui::SetItemTooltip("Retrieve the stored password from the system registry if present");

			if (LauncherImGui::BeginModal("Stored Master Password", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
			{
				if (auto pass = login::db::ReadStoredMasterPass())
				{
					ImGui::TextWrapped("The current master password saved in the registry:");
					ImGui::InputText("##password", &*pass, ImGuiInputTextFlags_AutoSelectAll | ImGuiInputTextFlags_ReadOnly);
				}
				else
					ImGui::Text("There is no master password saved in the registry.");

				ImGui::Spacing();
				ImGui::SetCursorPosX(ImGui::GetContentRegionMax().x - ImGui::CalcTextSize("Done").x - ImGui::GetStyle().FramePadding.x * 2);
				if (ImGui::Button("Done"))
					LauncherImGui::CloseModal();

				LauncherImGui::EndModal();
			}

			ImGui::SameLine();
			if (ImGui::Button("Set Master Password"))
				LauncherImGui::OpenModal("Set Master Password");

			bool set_pass_open;
			if (LauncherImGui::BeginModal("Set Master Password", &set_pass_open, ImGuiWindowFlags_AlwaysAutoResize))
			{
				ShowNewPassword([] { LauncherImGui::CloseModal(); });
				LauncherImGui::EndModal();
			}

			ImGui::Separator();
			ImGui::Spacing();
			if (ImGui::Button("Manage Server Types"))
				LauncherImGui::OpenModal("Manage Server Types");
			ImGui::SetItemTooltip("Manage the server type to default path mappings and entries");

			if (LauncherImGui::BeginModal("Manage Server Types", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
			{
				DefaultListBox(server_type_info);

				ImGui::Separator();
				ImGui::SetCursorPosX(ImGui::GetContentRegionMax().x - ImGui::CalcTextSize("Done").x - ImGui::GetStyle().FramePadding.x * 2);
				if (ImGui::Button("Done"))
					LauncherImGui::CloseModal();

				LauncherImGui::EndModal();
			}

			ImGui::Spacing();
			if (ImGui::Button("Manage Server Names"))
				LauncherImGui::OpenModal("Manage Server Names");
			ImGui::SetItemTooltip("Manage the server short name to long name mappings");

			if (LauncherImGui::BeginModal("Manage Server Names", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
			{
				DefaultListBox(server_name_info);

				ImGui::Separator();
				ImGui::SetCursorPosX(ImGui::GetContentRegionMax().x - ImGui::CalcTextSize("Done").x - ImGui::GetStyle().FramePadding.x * 2);
				if (ImGui::Button("Done"))
					LauncherImGui::CloseModal();

				LauncherImGui::EndModal();
			}

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
	static auto is_paused = login::db::CacheSetting<bool>("is_paused", false, GetBoolFromString);
	ImGui::PushItemFlag(ImGuiItemFlags_SelectableDontClosePopup, true);
	if (ImGui::MenuItem(fmt::format("AutoLogin is {}", is_paused.Read() ? "Paused" : "Running").c_str()))
		login::db::WriteSetting("is_paused", !is_paused.Updated() ? "true" : "false");
	ImGui::PopItemFlag();

	if (ImGui::BeginMenu("Quick Launch"))
	{
		if (ImGui::MenuItem("Without Login"))
			LaunchCleanSession();

		if (ImGui::BeginMenu("Profiles"))
		{
			static auto profile_groups = CacheResults(login::db::ListProfileGroups);
			for (const auto& group : profile_groups.Read())
			{
				ImGui::PushID(group.c_str());

				if (ImGui::BeginMenu(group.c_str()))
				{
					std::vector<SizedProfileRecord> profiles;
					float largest_level = 0.f;
					float largest_class = 0.f;

					static auto last_group = group;
					static auto group_profiles = login::db::CacheResults([]
						{
							return login::db::GetProfiles(last_group);
						});

					const bool force_profiles_update = !ci_equals(last_group, group);
					if (force_profiles_update)
						last_group = group;
					for (auto& profile : group_profiles.Read(force_profiles_update))
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
			static auto servers = CacheResults(login::db::ListServers);
			for (const auto& server : servers.Read())
			{
				ImGui::PushID(server.c_str());

				if (ImGui::BeginMenu(server.c_str()))
				{
					std::vector<SizedProfileRecord> profiles;
					float largest_level = 0.f;
					float largest_class = 0.f;

					static auto last_server = server;
					static auto server_characters = login::db::CacheResults([]
						{
							return login::db::ListCharactersOnServer(last_server);
						});

					const bool force_characters_update = !ci_equals(last_server, server);
					if (force_characters_update)
						last_server = server;

					for (auto& profile : server_characters.Read(force_characters_update))
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
		auto ok_action = [&is_open]
			{
				is_open = false;

				// do this here because doing it before will attempt to read/write passwords without the master pass
				if (const auto load_ini = login::db::ReadSetting("load_ini"); !load_ini || GetBoolFromString(*load_ini, false))
				{
					Import();
					login::db::WriteSetting("load_ini", "false", "Import data from autologin ini file one time at load");
				}
			};

		if (login::db::ReadSetting("master_pass"))
			ShowValidatePassword(ok_action);
		else
			ShowNewPassword(ok_action);
	}

	ImGui::End();
	return is_open;
}

void InitializeAutoLoginImGui()
{
	LauncherImGui::AddMainPanel("AutoLogin", ShowAutoLoginWindow);
	LauncherImGui::AddContextGroup("AutoLogin Menu", ShowAutoLoginMenu);
}

void ShutdownAutoLoginImGui()
{
	if (s_eqDirDialog != nullptr)
		IGFD_Destroy(s_eqDirDialog);
}
