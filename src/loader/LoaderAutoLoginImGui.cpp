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

#include "loader/MacroQuest.h"
#include "loader/LoaderAutoLogin.h"
#include "loader/ImGui.h"

#include "imgui/ImGuiFileDialog.h"
#include "imgui/misc/cpp/imgui_stdlib.h"
#include "imgui/imgui_internal.h"
#include "imgui/ImGuiUtils.h"
#include "login/AutoLogin.h"
#include "login/Login.h"

#include <fmt/format.h>
#include <fmt/compile.h>
#include <spdlog/spdlog.h>
#include <filesystem>

namespace fs = std::filesystem;
using namespace mq;

static ImGuiFileDialog* s_eqDirDialog = nullptr;
static constexpr AutoLoginSettings defaultSettings;

#pragma region Helpers

static void DefaultModalButtons(const Action& ok_action, const char* cancel = "Cancel", const char* ok = "OK")
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
static void DefaultOptional(std::optional<T>& opt, const char* label, const std::function<T()>& set_action, const std::function<bool(T&)>& input_action)
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

static void DeleteModal(const std::string& name, const std::string_view message, const Action& yes_action)
{
	ImGui::SetNextWindowSizeConstraints({ 200.f, 0.f }, { FLT_MAX, FLT_MAX });
	if (LauncherImGui::BeginModal(name, nullptr, ImGuiWindowFlags_None))
	{
		ImGui::Text("%.*s", static_cast<int>(message.length()), message.data());
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

template <typename Info>
static void DefaultListBox(Info& info)
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
	EditBehavior(selected, add_name, [&info]
		{
			selected.Update({});
			info = selected;
		});

	static constexpr std::string_view edit_prefix = "Edit ";
	static constexpr const char* edit_name = JoinLabels<edit_prefix, Info::label>::literal;
	ImGui::SameLine();
	if (ImGui::Button(edit_name))
	{
		if (info.Valid())
		{
			selected = info;
			selected.Fill();

			LauncherImGui::OpenModal(edit_name);
		}
	}
	EditBehavior(selected, edit_name, [&info]
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
		if (info.Valid())
		{
			remove_message = fmt::format("Are you sure you want to remove {} '{}'?\n\nAll dependent data will also be removed.", Info::label, info.Preview());
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
static void DefaultCombo(Info& info, const Action& select_action)
{
	static Info selected;

	static constexpr std::string_view hidden_prefix = "##";
	const auto width = ImGui::CalcItemWidth()
		- ImGui::CalcTextSize(ICON_MD_ADD_BOX).x
		- ImGui::CalcTextSize(ICON_MD_EDIT).x
		- ImGui::GetStyle().FramePadding.x * 4;
	ImGui::SetNextItemWidth(width);
	if (ImGui::BeginCombo(JoinLabels<hidden_prefix, Info::label>::literal, info.Preview().c_str(), ImGuiComboFlags_NoArrowButton))
	{
		info.List(select_action);

		ImGui::EndCombo();
	}

	ImGui::SameLine(0.f, 0.f);
	static constexpr std::string_view edit_prefix = "Edit ";
	static constexpr const char* edit_name = JoinLabels<edit_prefix, Info::label>::literal;
	if (ImGui::Button(ICON_MD_EDIT))
	{
		if (info.Valid())
		{
			selected = info;
			selected.Fill();

			LauncherImGui::OpenModal(edit_name);
		}
	}
	ImGui::SetItemTooltip("Edit selected entry");
	EditBehavior(selected, edit_name, [&info]
		{
			selected.Update(info);
			info = selected;
		});

	ImGui::SameLine(0.f, 0.f);
	static constexpr std::string_view add_prefix = "Add ";
	static constexpr const char* add_name = JoinLabels<add_prefix, Info::label>::literal;
	if (ImGui::Button(ICON_MD_ADD_BOX))
	{
		selected = {};
		LauncherImGui::OpenModal(add_name);
	}
	ImGui::SetItemTooltip("Create new entry");
	EditBehavior(selected, add_name, [&info]
		{
			selected.Update({});
			info = selected;
		});

	if constexpr (HasLabelOverride<Info>::value)
	{
		if constexpr (!Info::label_override.empty())
		{
			ImGui::SameLine(0.f, ImGui::GetStyle().ItemInnerSpacing.x);
			ImGui::TextUnformatted(JoinLabels<Info::label_override>::literal);
		}
	}
	else
	{
		ImGui::SameLine(0.f, ImGui::GetStyle().ItemInnerSpacing.x);
		ImGui::TextUnformatted(JoinLabels<Info::label>::literal);
	}
}

static bool IsEQGameInFolder(const std::string& path)
{
	static std::string lastPath = "/";
	static bool result = false;

	if (lastPath != path)
	{
		lastPath = path;
		std::error_code ec;
		result = fs::exists(fs::path(path) / "eqgame.exe", ec);
	}
	return result;
}

static void SetEQDirModal(std::optional<std::string>& eq_path, const Action& ok_action)
{
	if (LauncherImGui::BeginModal("Input EQ Path", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		auto showPath = [](const std::string& path) {
			if (!IsEQGameInFolder(path))
			{
				ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
				ImGui::Text("Invalid EverQuest path, eqgame.exe does not exist:");
				ImGui::PopStyleColor();
			}

			ImGui::TextUnformatted(path.c_str());
		};

		if (eq_path)
			showPath(*eq_path);
		else
			showPath(GetEQRoot());

		if (!s_eqDirDialog)
			s_eqDirDialog = IGFD_Create();

		if (ImGui::Button("Choose"))
		{
			LauncherImGui::OpenModal("Choose EverQuest Directory");
			IGFD_OpenDialog(s_eqDirDialog, "ChooseEQDirKey", "Choose EverQuest Directory",
				nullptr, GetEQRoot().c_str(), "", 1, nullptr, ImGuiFileDialogFlags_NoDialog);
		}

		ImGui::SetNextWindowSizeConstraints({ 350.f, 350.f }, { FLT_MAX, FLT_MAX });
		if (LauncherImGui::BeginModal("Choose EverQuest Directory", nullptr, ImGuiWindowFlags_NoScrollbar))
		{
			if (IGFD_DisplayDialog(s_eqDirDialog, "ChooseEQDirKey", ImGuiWindowFlags_None, { 0.f, 0.f }, { 0.f, 0.f }))
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

				LauncherImGui::CloseModal();
			}

			LauncherImGui::EndModal();
		}

		DefaultModalButtons(ok_action);

		LauncherImGui::EndModal();
	}
}

static void SetEQFileModal(const char* label, std::optional<std::string>& path, const char* default_path, const Action& ok_action)
{
	if (LauncherImGui::BeginModal(label, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		if (path)
			ImGui::TextUnformatted(path->c_str());
		else
			ImGui::TextUnformatted(default_path);

		if (!s_eqDirDialog)
			s_eqDirDialog = IGFD_Create();

		if (ImGui::Button("Choose"))
		{
			LauncherImGui::OpenModal("Choose Path");
			IGFD_OpenDialog(s_eqDirDialog, "ChoosePathKey", label,
				".ini", GetEQRoot().c_str(), default_path, 1, nullptr, ImGuiFileDialogFlags_NoDialog);
		}

		ImGui::SetNextWindowSizeConstraints({ 350.f, 350.f }, { FLT_MAX, FLT_MAX });
		if (LauncherImGui::BeginModal("Choose Path", nullptr, ImGuiWindowFlags_NoScrollbar))
		{
			if (IGFD_DisplayDialog(s_eqDirDialog, "ChoosePathKey", ImGuiWindowFlags_None, { 0.f, 0.f }, { 0.f, 0.f }))
			{
				if (IGFD_IsOk(s_eqDirDialog))
				{
					const std::shared_ptr<char> selected_path(IGFD_GetCurrentPath(s_eqDirDialog), IGFD_DestroyString);
					const std::shared_ptr<char> selected_file(IGFD_GetCurrentFileName(s_eqDirDialog, IGFD_ResultMode_KeepInputFile), IGFD_DestroyString);
					if (std::error_code ec; selected_path && selected_file && exists(fs::path(selected_path.get()) / fs::path(selected_file.get()), ec))
					{
						path = relative(fs::path(selected_path.get()) / fs::path(selected_file.get()), GetEQRoot(), ec).string();
					}
				}

				IGFD_CloseDialog(s_eqDirDialog);

				LauncherImGui::CloseModal();
			}

			LauncherImGui::EndModal();
		}

		DefaultModalButtons(ok_action);

		LauncherImGui::EndModal();
	}
}

static ProfileInfo s_modalProfile;
static std::string s_currentProfileGroup;
static ProfileGroupInfo s_modalProfileGroup;
static std::string s_removeMessage;
static void HandleProfilesModals();
static void HandleProfileGroupsModals();

#pragma endregion

#pragma region Hotkey

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

static void ShowHotkeyWindow(const std::string& name, std::string& hotkey, const Action& ok_action)
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

		ImGui::SameLine();
		if (ImGui::Button("Clear##hotkey"))
		{
			hotkey.clear();
		}

		DefaultModalButtons(ok_action);

		LauncherImGui::EndModal();
	}
}

#pragma endregion

void EditBehavior(ServerNameInfo& serverNameInfo, const char* name, const Action& ok_action)
{
	if (LauncherImGui::BeginModal(name, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::InputText("Short Name", &serverNameInfo.ShortName);
		ImGui::Spacing();

		ImGui::InputText("Long Name", &serverNameInfo.LongName);

		DefaultModalButtons(ok_action);

		LauncherImGui::EndModal();
	}
}

void EditBehavior(ServerTypeInfo& serverTypeInfo, const char* name, const Action& ok_action)
{
	static std::optional<std::string> eq_path;

	if (LauncherImGui::BeginModal(name, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::InputText("Type", &serverTypeInfo.ServerType);
		ImGui::Spacing();

		if (ImGui::Button("EQ Path"))
		{
			if (!serverTypeInfo.EQPath.empty())
				eq_path = serverTypeInfo.EQPath;
			else
				eq_path = {};

			LauncherImGui::OpenModal("Input EQ Path");
		}

		SetEQDirModal(eq_path, [&serverTypeInfo]
			{
				if (eq_path) serverTypeInfo.EQPath = *eq_path;
			});

		ImGui::SameLine();
		ImGui::Text("%.*s", static_cast<int>(serverTypeInfo.EQPath.size()), serverTypeInfo.EQPath.data());

		DefaultModalButtons(ok_action);

		LauncherImGui::EndModal();
	}
}

void EditBehavior(AccountInfo& accountInfo, const char* name, const Action& ok_action)
{
	static bool show_password = false;

	if (LauncherImGui::BeginModal(name, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::TextWrapped("Editing Account %s", accountInfo.Preview().c_str());
		ImGui::Spacing();

		ImGui::InputText("Account Name", &accountInfo.Account);
		ImGui::Spacing();

		DefaultCombo(accountInfo.ServerType, [] {});

		ImGui::Spacing();

		ImGuiInputTextFlags flags = ImGuiInputTextFlags_None;
		if (!show_password) flags |= ImGuiInputTextFlags_Password;
		ImGui::InputText("Password", &accountInfo.Password, flags);
		ImGui::Spacing();

		ImGui::Checkbox("Show password", &show_password);
		ImGui::Spacing();

		DefaultModalButtons(ok_action);

		LauncherImGui::EndModal();
	}
}

static void AccountTable(const std::string_view search)
{
	static AccountInfo selected_account;
	static ProfileRecord selected_profile;
	static std::string remove_message;

	constexpr ImGuiTableFlags flags = ImGuiTableFlags_SizingStretchProp
		| ImGuiTableFlags_Borders
		| ImGuiTableFlags_NoBordersInBody
		| ImGuiTableFlags_ScrollY
		| ImGuiTableFlags_Sortable
		| ImGuiTableFlags_SortMulti;

	if (ImGui::BeginTable("Main List", 2, flags, { 0.f, 0.f }))
	{
		ImGui::TableSetupColumn("Account", ImGuiTableColumnFlags_WidthStretch, 0.f, static_cast<ImGuiID>(AccountInfo::SortID::Account));
		ImGui::TableSetupColumn("EQ Install", ImGuiTableColumnFlags_WidthFixed, 0.f, static_cast<ImGuiID>(AccountInfo::SortID::EQ_Install));
		ImGui::TableSetupScrollFreeze(0, 1);
		ImGui::TableHeadersRow();

		static std::string last_search(search);
		static auto accounts = login::db::CacheResults([]
			{
				return login::db::ListAccountMatches(last_search);
			});

		const bool force_update = !ci_equals(last_search, search);
		if (force_update)
			last_search = search;

		const bool did_update = accounts.ReadHasChanged(force_update);
		if (const auto sort_specs = ImGui::TableGetSortSpecs(); sort_specs->SpecsDirty || did_update)
		{
			AccountInfo::Sort(sort_specs, accounts.Updated());
			sort_specs->SpecsDirty = false;
		}

		ImGuiListClipper clipper;
		clipper.Begin(static_cast<int>(accounts.Updated().size()));
		while (clipper.Step())
		{
			for (int row = clipper.DisplayStart; row < clipper.DisplayEnd; ++row)
			{
				auto& match = accounts.Updated().at(row);
				ImGui::PushID(&match);

				ImGui::TableNextRow();
				ImGui::TableNextColumn();

				// this allows right-clicking
				bool is_selected = false;
				ImGui::Selectable("##row", &is_selected, ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_AllowOverlap);

				if (ImGui::IsItemHovered() && ImGui::IsItemClicked(ImGuiMouseButton_Right))
					ImGui::OpenPopup("row_popup");

				if (ImGui::BeginPopup("row_popup"))
				{
					if (ImGui::Selectable("Edit Account"))
					{
						selected_account.Account = match.accountName;
						selected_account.ServerType.ServerType = match.serverType;
						selected_account.Fill();

						selected_profile = match;

						LauncherImGui::OpenModal("Edit Account");
					}

					if (ImGui::Selectable("Remove Account"))
					{
						remove_message = fmt::format("Are you certain you want to remove account '{} ({})'?\n\nAll associated characters will also be removed.", match.accountName, match.serverType);
						selected_profile = match;
						LauncherImGui::OpenModal("Remove Account");
					}

					ImGui::Separator();

					if (ImGui::Selectable("Launch Client & Log In"))
					{
						selected_profile = match;
						selected_profile.accountPassword = login::db::ReadPassword(match.accountName, match.serverType).value_or("");

						LoadCharacter(selected_profile, true);
					}

					ImGui::EndPopup();
				}

				ImGui::SameLine(0.f, 0.f);
				ImGui::TextUnformatted(match.accountName.c_str());

				ImGui::TableNextColumn();
				ImGui::TextUnformatted(match.serverType.c_str());

				ImGui::PopID();
			}
		}

		ImGui::EndTable();
	}

	EditBehavior(selected_account, "Edit Account", []
		{
			if (selected_account.Valid())
			{
				ProfileRecord profile;
				profile.accountName = selected_account.Account;
				profile.accountPassword = selected_account.Password;
				profile.serverType = selected_account.ServerType.ServerType;
				login::db::UpdateAccount(selected_profile.accountName, selected_profile.serverType, profile);
			}
		});

	DeleteModal("Remove Account", remove_message, []
		{
			login::db::DeleteAccount(selected_profile.accountName, selected_profile.serverType);
		});
}

void EditBehavior(CharacterInfo& characterInfo, const char* name, const Action& ok_action)
{
	if (LauncherImGui::BeginModal(name, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::TextWrapped("Editing Character %s", characterInfo.Preview().c_str());
		ImGui::Spacing();

		DefaultCombo(characterInfo.Account, [&characterInfo]
			{
			});
		ImGui::Spacing();

		ImGui::InputText("Server", &characterInfo.Server);
		ImGui::Spacing();

		ImGui::InputText("Name", &characterInfo.Character);
		ImGui::Spacing();

		DefaultModalButtons(ok_action);

		LauncherImGui::EndModal();
	}
}

static void CharacterTable(const std::string_view search)
{
	static CharacterInfo selected_character;
	static ProfileInfo selected_profile;
	static std::string remove_message;

	constexpr ImGuiTableFlags flags = ImGuiTableFlags_SizingStretchProp
		| ImGuiTableFlags_Borders
		| ImGuiTableFlags_NoBordersInBody
		| ImGuiTableFlags_ScrollY
		| ImGuiTableFlags_Sortable
		| ImGuiTableFlags_SortMulti;

	static auto show_hidden = login::db::CacheSetting<bool>("show_hidden_characters", defaultSettings.ShowHiddenCharacters, GetBoolFromString);
	float height = ImGui::GetContentRegionAvail().y - ImGui::GetFrameHeightWithSpacing();

	bool should_show_hidden = show_hidden.Read();

	ImGui::PushOverrideID(CharacterInfo::GetID());
	if (ImGui::BeginTable("Main List", 9, flags, { 0.f, height }))
	{
		CharacterInfo::SetupColumns();
		ImGui::TableSetupScrollFreeze(0, 1);

		if (ImGui::TableGetColumnFlags(0) & ImGuiTableColumnFlags_IsHovered)
			ImGui::SetTooltip("Show character in quick launch menu.");

		ImGui::TableHeadersRow();

		static std::string last_search(search);
		static auto characters = login::db::CacheResults([]
			{
				return login::db::ListCharacterMatches(last_search);
			});

		const bool force_update = !ci_equals(last_search, search);
		if (force_update)
			last_search = search;

		const bool did_update = characters.ReadHasChanged(force_update);
		static std::vector<size_t> filtered_characters;
		if (const auto sort_specs = ImGui::TableGetSortSpecs(); sort_specs->SpecsDirty || did_update)
		{
			CharacterInfo::Sort(sort_specs, characters.Updated());

			filtered_characters.clear();
			for (auto it = characters.Updated().begin(); it != characters.Updated().end(); ++it)
			{
				if (it->visible)
					filtered_characters.push_back(std::distance(characters.Updated().begin(), it));
			}

			sort_specs->SpecsDirty = false;
		}

		ImGuiListClipper clipper;
		if (should_show_hidden)
			clipper.Begin(static_cast<int>(characters.Updated().size()));
		else
			clipper.Begin(static_cast<int>(filtered_characters.size()));

		const auto& loaded = GetLoadedInstances();
		while (clipper.Step())
		{
			for (int row = clipper.DisplayStart; row < clipper.DisplayEnd; ++row)
			{
				int idx = row;
				if (!should_show_hidden)
					idx = static_cast<int>(filtered_characters.at(row));
				auto& match = characters.Updated().at(idx);
				ImGui::PushID(&match);

				ImGui::TableNextRow();
				ImGui::TableNextColumn();

				// this allows right-clicking
				bool is_selected = false;

				if (LauncherImGui::SmallCheckbox("##Visible", &match.visible))
				{
					login::db::UpdateCharacter(match.serverName, match.characterName, match);
				}

				ImGui::SameLine(0.f, 0.f);
				ImGui::Selectable("##row", &is_selected, ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_AllowOverlap);

				if (ImGui::IsItemHovered() && ImGui::IsItemClicked(ImGuiMouseButton_Right))
					ImGui::OpenPopup("row_popup");

				if (ImGui::BeginPopup("row_popup"))
				{
					if (ImGui::Selectable("Edit Character"))
					{
						selected_character.Server = match.serverName;
						selected_character.Character = match.characterName;
						selected_character.Account.Account = match.accountName;
						selected_character.Account.ServerType.ServerType = match.serverType;

						selected_profile = match;
						selected_profile.Character = selected_character;

						LauncherImGui::OpenModal("Edit Character");
					}

					if (ImGui::Selectable("Remove Character"))
					{
						remove_message = fmt::format("Are you certain you want to remove character '{} ({})'?\n\nAll associated profiles will also be removed.", match.characterName, match.serverName);
						selected_profile = match;
						LauncherImGui::OpenModal("Remove Character");
					}

					ImGui::Separator();

					if (ImGui::Selectable("Add To Profile Group"))
					{
						s_modalProfile = match;
						s_modalProfile.Character.Server = match.serverName;
						s_modalProfile.Character.Character = match.characterName;
						s_modalProfile.Character.Account.Account = match.accountName;
						s_modalProfile.Character.Account.ServerType.ServerType = match.serverType;

						LauncherImGui::OpenModal("Add Profile");
					}

					ImGui::EndPopup();
				}

				ImGui::TableNextColumn();
				ImGui::TextUnformatted(match.characterName.c_str());

				ImGui::TableNextColumn();
				ImGui::TextUnformatted(match.serverName.c_str());

				ImGui::TableNextColumn();
				ImGui::Text("%s", !match.characterClass.empty() ? match.characterClass.c_str() : "<None>");

				ImGui::TableNextColumn();
				if (match.characterLevel > 0) ImGui::Text("%d", match.characterLevel);

				ImGui::TableNextColumn();
				ImGui::TextUnformatted(match.accountName.c_str());

				ImGui::TableNextColumn();
				ImGui::TextUnformatted(match.serverType.c_str());

				ImGui::TableNextColumn();
				if (ImGui::SmallButton("Play"))
				{
					LoadCharacter(match, true);
				}

				ImGui::SameLine();
				// this needs to be here to handle the fact that hotkey isn't optional
				if (ImGui::SmallButton("..."))
				{
					selected_profile = match;

					LauncherImGui::OpenModal("Play With Params");
				}

				ImGui::TableNextColumn();
				DrawStatusIcon(match);

				ImGui::PopID();
			}
		}

		ImGui::EndTable();
	}
	ImGui::PopID();

	if (LauncherImGui::ToggleSlider("Show Hidden Characters", &should_show_hidden))
	{
		login::db::WriteSetting("show_hidden_characters", should_show_hidden ? "1" : "0", "Show hidden characters in the characters list");
	}

	EditBehavior(selected_character, "Edit Character", []
		{
			if (selected_character.Valid() && selected_character.Account.Valid())
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

		ImGui::SameLine();
		if (ImGui::Button("Clear##path"))
		{
			selected_profile.eqPath = std::nullopt;
		}

		DefaultModalButtons([]
			{
				LoadCharacter(selected_profile, true);
			});

		LauncherImGui::EndModal();
	}

	HandleProfilesModals();
}

void EditBehavior(ProfileInfo& profileInfo, const char* name, const Action& ok_action)
{
	static ProfileGroupInfo group;
	static std::optional<std::string> eq_path;
	static std::string hot_key;
	static std::optional<std::string> custom_ini;

	if (LauncherImGui::BeginModal(name, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		DefaultCombo(profileInfo.Character, [&profileInfo]
			{
				if (profileInfo.Character.Valid())
				{
					profileInfo.characterName = profileInfo.Character.Character;
					profileInfo.serverName = profileInfo.Character.Server;
					login::db::ReadAccount(profileInfo);
				}
			});

		if (!ci_equals(profileInfo.profileName, group.profileName))
			group.profileName = profileInfo.profileName;

		DefaultCombo(group, [&profileInfo]
			{
				if (group.Valid())
				{
					profileInfo.profileName = group.profileName;
				}
			});
		ImGui::SameLine(0.f, ImGui::GetStyle().ItemInnerSpacing.x); ImGui::TextUnformatted("Profile Group");

		if (ImGui::Button("Hotkey"))
		{
			hot_key = profileInfo.hotkey;
			LauncherImGui::OpenModal("Input Hotkey");
		}

		ShowHotkeyWindow("Input Hotkey", hot_key,
			[&profileInfo] { profileInfo.hotkey = hot_key; });

		ImGui::SameLine();
		ImGui::Text("%s", !profileInfo.hotkey.empty() ? profileInfo.hotkey.c_str() : "<None>");

		if (ImGui::Button("EQ Path"))
		{
			eq_path = profileInfo.eqPath;
			LauncherImGui::OpenModal("Input EQ Path");
		}

		SetEQDirModal(eq_path, [&profileInfo] { profileInfo.eqPath = eq_path; });

		ImGui::SameLine();
		ImGui::Text("%s", profileInfo.eqPath ? profileInfo.eqPath->c_str() : "<Default>");

		ImGui::SameLine();
		if (ImGui::Button("Clear##path"))
		{
			profileInfo.eqPath = std::nullopt;
		}

		DefaultOptional<int>(profileInfo.charSelectDelay, "Override Character Select Delay",
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

		DefaultOptional<bool>(profileInfo.endAfterSelect, "Override End After Character Select",
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
			custom_ini = profileInfo.customClientIni;
			LauncherImGui::OpenModal("Input Character INI File");
		}

		SetEQFileModal("Input Character INI File", custom_ini, "eqclient.ini",
			[&profileInfo] { profileInfo.customClientIni = custom_ini; });

		ImGui::SameLine();
		ImGui::Text("%s", profileInfo.customClientIni ? profileInfo.customClientIni->c_str() : "<Default>");

		DefaultModalButtons(ok_action);

		LauncherImGui::EndModal();
	}
}

static void ProfileTable(const std::string& group)
{
	constexpr ImGuiTableFlags flags = ImGuiTableFlags_SizingStretchProp
		| ImGuiTableFlags_Borders
		| ImGuiTableFlags_NoBordersInBody
		| ImGuiTableFlags_ScrollY;

	ImVec2 size = ImGui::GetContentRegionAvail() - ImVec2(1, ImGui::GetFrameHeightWithSpacing());

	if (ImGui::BeginTable("Main List", 8, flags, size))
	{
		if (!group.empty())
		{
			ImGui::TableSetupColumn(ICON_MD_STAR "##Selected", ImGuiTableColumnFlags_WidthFixed, ImGui::GetFrameHeight());
			ImGui::TableSetupColumn("Character");
			ImGui::TableSetupColumn("Server");
			ImGui::TableSetupColumn("Account");
			ImGui::TableSetupColumn("Persona");
			ImGui::TableSetupColumn("Hotkey");
			ImGui::TableSetupColumn("Launch");
			ImGui::TableSetupColumn(ICON_MD_POWER_SETTINGS_NEW, ImGuiTableColumnFlags_WidthFixed);
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableHeadersRow();

			if (ImGui::TableGetColumnFlags(0) & ImGuiTableColumnFlags_IsHovered)
				ImGui::SetTooltip("Indicates whether that character will load when the group is launched.");

			static auto last_group = group;
			static auto profiles = login::db::CacheResults([]
				{
					return login::db::GetProfiles(last_group);
				});

			const bool force_profiles_update = !ci_equals(last_group, group);
			if (force_profiles_update)
				last_group = group;

			static bool do_write = false;
			static ProfileRecord* held_ptr = nullptr;

			ImGuiListClipper clipper;
			clipper.Begin(static_cast<int>(profiles.Read(force_profiles_update).size()));
			const auto& loaded = GetLoadedInstances();

			while (clipper.Step())
			{
				for (int row = clipper.DisplayStart; row < clipper.DisplayEnd; ++row)
				{
					auto& profile = profiles.Updated().at(row);
					ImGui::PushID(&profile);

					ImGui::TableNextRow();
					ImGui::TableNextColumn();

					if (LauncherImGui::SmallCheckbox("##Selected", &profile.willLoad))
					{
						do_write = true;
					}

					ImGui::SameLine(0.f, 0.f);
					ImGui::Selectable("##row", false, ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_AllowOverlap);

					if (ImGui::IsItemHovered(ImGuiHoveredFlags_RectOnly))
					{
						if (held_ptr != nullptr && ImGui::IsMouseReleased(ImGuiMouseButton_Left))
						{
							held_ptr = nullptr;
							do_write = true;
						}
						else if (held_ptr != nullptr && held_ptr != &profile && ImGui::IsMouseDown(ImGuiMouseButton_Left))
						{
							std::swap(*held_ptr, profile);
							held_ptr = &profile;
						}
						else if (held_ptr == nullptr && ImGui::IsMouseDragging(ImGuiMouseButton_Left))
						{
							held_ptr = &profile;
						}
						else if (ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
						{
							profile.willLoad = !profile.willLoad;
							do_write = true;
						}
					}

					if (ImGui::IsItemClicked(ImGuiMouseButton_Right))
						ImGui::OpenPopup("row_popup");

					if (ImGui::BeginPopup("row_popup"))
					{
						if (ImGui::Selectable("Edit Profile"))
						{
							s_modalProfile = profile;
							s_modalProfile.Character.Character = profile.characterName;
							s_modalProfile.Character.Server = profile.serverName;
							s_modalProfile.Character.Account.Account = profile.accountName;
							s_modalProfile.Character.Account.ServerType.ServerType = profile.serverType;
							LauncherImGui::OpenModal("Edit Profile");
						}

						if (ImGui::Selectable("Remove Profile"))
						{
							s_modalProfile = profile;
							s_modalProfile.Character.Character = profile.characterName;
							s_modalProfile.Character.Server = profile.serverName;
							s_removeMessage = fmt::format("Are you sure you want to remove profile '{}'?", profile.characterName);
							LauncherImGui::OpenModal("Remove Profile");
						}

						ImGui::EndPopup();
					}

					ImGui::TableNextColumn();
					ImGui::TextUnformatted(profile.characterName.c_str());

					ImGui::TableNextColumn();
					ImGui::TextUnformatted(profile.serverName.c_str());

					ImGui::TableNextColumn();
					ImGui::TextUnformatted(profile.accountName.c_str());

					ImGui::TableNextColumn();
					if (profile.characterClass.empty())
						ImGui::Text("<None>");
					else
						ImGui::Text("%s %d", profile.characterClass.c_str(), profile.characterLevel);

					ImGui::TableNextColumn();
					ImGui::TextUnformatted(profile.hotkey.c_str());

					ImGui::TableNextColumn();
					if (ImGui::SmallButton("Play"))
					{
						LoadCharacter(profile, ImGui::IsKeyPressed(ImGuiMod_Shift));
					}

					ImGui::TableNextColumn();
					DrawStatusIcon(profile);

					ImGui::PopID();
				}
			}

			if (do_write)
			{
				unsigned int order = 0;
				for (auto& profile : profiles.Updated())
				{
					profile.sortOrder = ++order;
					login::db::UpdateProfile(profile);
				}

				do_write = false;
				last_group.clear();
			}
		}

		ImGui::EndTable();
	}

	if (ImGui::Button("Add Profile"))
	{
		s_modalProfile = {};
		s_modalProfile.profileName = group;
		LauncherImGui::OpenModal("Add Profile");
	}

	ImGui::SameLine();
	ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 0.5f), "Drag & drop a row to reorder");
	HandleProfilesModals();
}

void EditBehavior(ProfileGroupInfo& profileGroupInfo, const char* name, const Action& ok_action)
{
	static std::optional<std::string> eq_path;
	if (LauncherImGui::BeginModal(name, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::InputText("Profile Group Name", &profileGroupInfo.profileName);

		ImGui::Spacing();
		if (ImGui::Button("EQ Path"))
		{
			eq_path = profileGroupInfo.eqPath;
			LauncherImGui::OpenModal("Input EQ Path");
		}

		SetEQDirModal(eq_path, [&profileGroupInfo] { profileGroupInfo.eqPath = eq_path; });

		ImGui::SameLine();
		ImGui::Text("%s", profileGroupInfo.eqPath ? profileGroupInfo.eqPath->c_str() : "<Default>");

		ImGui::SameLine();
		if (ImGui::Button("Clear##path"))
		{
			profileGroupInfo.eqPath = std::nullopt;
		}

		DefaultModalButtons(ok_action);

		LauncherImGui::EndModal();
	}
}

static void HandleProfileGroupsModals(std::string& group)
{
	EditBehavior(s_modalProfileGroup, "Create Profile Group", [&group]
		{
			if (s_modalProfileGroup.Valid())
			{
				login::db::CreateProfileGroup(s_modalProfileGroup);
				group = s_modalProfileGroup.profileName;
			}
		});

	EditBehavior(s_modalProfileGroup, "Edit Profile Group", [&group]
		{
			if (s_modalProfileGroup.Valid())
			{
				login::db::UpdateProfileGroup(group, s_modalProfileGroup);
				group = s_modalProfileGroup.profileName;
			}
		});

	DeleteModal("Remove Profile Group", s_removeMessage, [&group]
		{
			if (s_modalProfileGroup.Valid())
			{
				login::db::DeleteProfileGroup(s_modalProfileGroup.profileName);
				group.clear();
			}
		});
}

static void ProfileGroupTable(std::string& group)
{
	constexpr ImGuiTableFlags flags = ImGuiTableFlags_SizingStretchProp
		| ImGuiTableFlags_Borders
		| ImGuiTableFlags_NoBordersInBody
		| ImGuiTableFlags_ScrollY;

	float height = ImGui::GetContentRegionAvail().y - ImGui::GetFrameHeightWithSpacing();

	ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
	if (ImGui::BeginListBox("##Main List", { 0.f, height }))
	{
		static auto profile_groups = login::db::CacheResults([]
			{
				return login::db::ListProfileGroups();
			});

		static bool do_write = false;
		static std::string* held_ptr = nullptr;

		ImGuiListClipper clipper;
		clipper.Begin(static_cast<int>(profile_groups.Read().size()));
		const auto& loaded = GetLoadedInstances();
		while (clipper.Step())
		{
			for (int row = clipper.DisplayStart; row < clipper.DisplayEnd; ++row)
			{
				auto& profile_group = profile_groups.Updated().at(row);
				ImGui::PushID(&profile_group);

				ImGui::Selectable("##row", ci_equals(group, profile_group), ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_AllowOverlap);

				if (ImGui::IsItemHovered(ImGuiHoveredFlags_RectOnly))
				{
					if (held_ptr != nullptr && ImGui::IsMouseReleased(ImGuiMouseButton_Left))
					{
						group = *held_ptr;
						held_ptr = nullptr;
						do_write = true;
					}
					else if (held_ptr != nullptr && held_ptr != &profile_group && ImGui::IsMouseDown(ImGuiMouseButton_Left))
					{
						std::swap(*held_ptr, profile_group);
						held_ptr = &profile_group;
					}
					else if (held_ptr == nullptr && ImGui::IsMouseDragging(ImGuiMouseButton_Left))
					{
						held_ptr = &profile_group;
					}
				}

				if (ImGui::IsItemClicked(ImGuiMouseButton_Right))
				{
					group = profile_group;
					login::db::TouchProfileGroup(group);
					ImGui::OpenPopup("row_popup");
				}
				else if (!ImGui::IsPopupOpen("row_popup") && ImGui::IsItemClicked(ImGuiMouseButton_Left))
				{
					group = profile_group;
					login::db::TouchProfileGroup(group);
				}

				if (ImGui::BeginPopup("row_popup"))
				{
					if (ImGui::Selectable("Edit Profile Group"))
					{
						s_modalProfileGroup = {};
						s_modalProfileGroup.profileName = group;
						login::db::ReadProfileGroup(s_modalProfileGroup);
						LauncherImGui::OpenModal("Edit Profile Group");
					}

					if (ImGui::Selectable("Remove Profile Group"))
					{
						s_modalProfileGroup = {};
						s_modalProfileGroup.profileName = group;
						s_removeMessage = fmt::format("Are you sure you want to remove profile group '{}'?\n\nAll associated profiles will also be removed.", group);
						LauncherImGui::OpenModal("Remove Profile Group");
					}

					ImGui::EndPopup();
				}

				ImGui::SameLine(0.f, 0.f);
				ImGui::TextUnformatted(profile_group.c_str());

				ImGui::PopID();
			}
		}

		if (do_write)
		{
			unsigned int order = 0;
			for (const auto& profile_group : profile_groups.Updated())
			{
				ProfileGroup record;
				record.profileName = profile_group;
				login::db::ReadProfileGroup(record);
				record.sortOrder = ++order;
				login::db::UpdateProfileGroup(profile_group, record);
			}

			login::db::TouchProfileGroup(group);

			do_write = false;
		}

		ImGui::EndListBox();
	}

	if (ImGui::Button("Add Group"))
	{
		s_modalProfile = {};
		LauncherImGui::OpenModal("Create Profile Group");
	}

	HandleProfileGroupsModals(group);
}

#pragma region Password

static void ShowValidatePassword(const Action& ok_action)
{
	static bool failed_pass = false;

	ImGui::SetCursorPosX(std::max(0.f, ImGui::GetContentRegionAvail().x / 2.f - ImGui::CalcTextSize("Please Enter Master Password").x / 2.f));
	ImGui::Text("Please Enter Master Password");
	ImGui::Spacing();

	if (failed_pass)
	{
		ImGui::SetCursorPosX(std::max(0.f, ImGui::GetContentRegionAvail().x / 2.f - ImGui::CalcTextSize("Incorrect Password!").x / 2.f));
		ImGui::TextColored({ 1.f, 0.f, 0.f, 1.f }, "Incorrect Password!");
		ImGui::Spacing();
	}

	static bool show_password = false;
	static std::string password;

	ImGuiInputTextFlags flags = ImGuiInputTextFlags_None;
	if (!show_password) flags |= ImGuiInputTextFlags_Password;

	ImGui::InputText("##password", &password, flags);
	ImGui::SameLine(); imgui::HelpMarker("Attempt to validate the entered password against the database, or set it if it does not exist.");
	ImGui::Separator();

	ImGui::Checkbox("Show password", &show_password);
	ImGui::SameLine(); imgui::HelpMarker("Show the password in plain text");
	ImGui::Spacing();

	ImGui::SetCursorPosX(ImGui::GetContentRegionMax().x - 75.f - ImGui::GetStyle().FramePadding.x * 2);
	if (ImGui::Button("OK", { 75.f, 0.f }))
	{
		if (!login::db::ReadSetting("master_pass") || login::db::ValidatePass(password))
		{
			login::db::CacheMasterPass(password);
			failed_pass = false;

			ok_action();
		}
		else
		{
			failed_pass = true;
		}
	}
}

static void ShowNewPassword(const Action& ok_action)
{
	static constexpr const char* label = "Please Enter New Master Password";

	ImGui::SetCursorPosX(std::max(0.f, ImGui::GetContentRegionAvail().x / 2.f - ImGui::CalcTextSize(label).x / 2.f));
	ImGui::TextUnformatted(label);
	ImGui::Spacing();

	ImGui::TextUnformatted(R"(MacroQuest's AutoLogin feature lets you set a master password
that will be used to encrypt autologin account information.

Please enter a master password, or leave the field blank and
no encryption will be used.)");
	ImGui::Spacing();

	static bool show_password = false;
	static auto perpetual_password = login::db::CacheSetting<bool>("perpetual_password", false, GetBoolFromString);
	static std::string password;

	ImGuiInputTextFlags flags = ImGuiInputTextFlags_None;
	if (!show_password) flags |= ImGuiInputTextFlags_Password;

	ImGui::InputText("##password", &password, flags);
	ImGui::SameLine(); imgui::HelpMarker("Set the new master password, will require validation of the current password if there is none stored\nAn empty password will proceed with no master password (all data will be stored in plaintext)");
	ImGui::Separator();

	ImGui::Checkbox("Show password", &show_password);
	ImGui::SameLine(); imgui::HelpMarker("Show the password in plain text");

	ImGui::SameLine();
	if (ImGui::Checkbox("Never ask again", &perpetual_password.Read()))
		login::db::WriteSetting("perpetual_password", perpetual_password.Updated() ? "true" : "false");
	ImGui::SameLine(); imgui::HelpMarker("Save the password to this system so that it never has to be entered again.");
	ImGui::Spacing();

	ImGui::SetCursorPosX(ImGui::GetContentRegionMax().x - 75.f - ImGui::GetStyle().FramePadding.x * 2);
	if (ImGui::Button("OK", { 75.f, 0.f }))
	{
		if (const auto old_pass = login::db::GetMasterPass();
			old_pass || !login::db::ReadSetting("master_pass"))
		{
			if (password.empty())
				login::db::DeleteSetting("master_pass");
			else
				login::db::CreateMasterPass(password);

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
}

#pragma endregion

static void HandleProfilesModals()
{
	EditBehavior(s_modalProfile, "Add Profile", []
		{
			if (s_modalProfile.Valid())
			{
				s_modalProfile.characterName = s_modalProfile.Character.Character;
				s_modalProfile.serverName = s_modalProfile.Character.Server;
				s_modalProfile.accountName = s_modalProfile.Character.Account.Account;
				s_modalProfile.serverType = s_modalProfile.Character.Account.ServerType.ServerType;
				login::db::CreateProfile(s_modalProfile);
			}
		});

	EditBehavior(s_modalProfile, "Edit Profile", []
		{
			if (s_modalProfile.Valid())
			{
				s_modalProfile.characterName = s_modalProfile.Character.Character;
				s_modalProfile.serverName = s_modalProfile.Character.Server;
				s_modalProfile.accountName = s_modalProfile.Character.Account.Account;
				s_modalProfile.serverType = s_modalProfile.Character.Account.ServerType.ServerType;
				login::db::UpdateProfile(s_modalProfile);
			}
		});

	DeleteModal("Remove Profile", s_removeMessage, []
		{
			login::db::DeleteProfile(
				s_modalProfile.serverName,
				s_modalProfile.characterName,
				s_modalProfile.profileName);
		});
}

void ShowProfilesWindow()
{
	static std::string group;
	// Code goes into this scope for selecting and modifying profiles/groups
	if (group.empty())
	{
		if (const auto& latest_group = login::db::GetLatestProfileGroup())
			group = *latest_group;
		else
		{
			const auto& groups = login::db::ListProfileGroups().vector();
			if (!groups.empty())
				group = groups.front();
		}
	}

	static float rightPaneSize = 0.0f;
	static float leftPaneSize = 150.0f;

	imgui::DrawSplitter(false, 9.0f, &leftPaneSize, &rightPaneSize, 50, 250);

	ImVec2 availSize = ImGui::GetContentRegionAvail();
	if (rightPaneSize == 0.0f)
		rightPaneSize = availSize.x - leftPaneSize - 1;

	// Left Pane
	if (ImGui::BeginChild("Profile Groups", { leftPaneSize, 0 }))
	{
		ProfileGroupTable(group);
	}
	ImGui::EndChild();

	ImGui::SameLine();

	// Right Pane
	ImVec2 rightPaneContentSize = ImGui::GetContentRegionAvail();
	if (ImGui::BeginChild("Profiles", { rightPaneContentSize.x, 0 }))
	{
		if (ImGui::Button("Launch Selected Group"))
			LoadProfileGroup(group, ImGui::IsKeyPressed(ImGuiMod_Shift));

		ImGui::SameLine();
		ImGui::TextColored({ 1.0f, 1.0f, 1.0f, 0.5f }, "Right click list items to edit or remove");

		ProfileTable(group);
	}

	ImGui::EndChild();
}

void ShowCharactersWindow()
{
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

	EditBehavior(info, "Add Character", []
		{
			ProfileRecord profile;
			profile.characterName = info.Character;
			profile.serverName = info.Server;
			profile.accountName = info.Account.Account;
			profile.serverType = info.Account.ServerType.ServerType;
			login::db::CreateCharacter(profile);
		});

	CharacterTable(search);
}

void ShowAccountsWindow()
{
	static std::string search;
	static AccountInfo info;

	ImGui::SetNextItemWidth(ImGui::GetContentRegionMax().x -
		ImGui::CalcTextSize("Add Account").x -
		ImGui::GetStyle().FramePadding.x * 2 -
		ImGui::GetStyle().ItemSpacing.x -
		ImGui::GetStyle().WindowPadding.x);
	ImGui::InputText("##Search Bar", &search, ImGuiInputTextFlags_EscapeClearsAll);

	ImGui::SameLine();
	if (ImGui::Button("Add Account"))
	{
		// reset to defaults
		info = {};
		LauncherImGui::OpenModal("Add Account");
	}

	EditBehavior(info, "Add Account", []
		{
			ProfileRecord profile;
			profile.accountName = info.Account;
			profile.accountPassword = info.Password;
			profile.serverType = info.ServerType.ServerType;
			login::db::CreateAccount(profile);
		});

	AccountTable(search);
}

void ShowSettingsWindow()
{
	static auto debug = login::db::CacheSetting<bool>("debug", false, GetBoolFromString);
	static auto kick_active = login::db::CacheSetting<bool>("kick_active", defaultSettings.KickActiveCharacter, GetBoolFromString);
	static auto end_after_select = login::db::CacheSetting<bool>("end_after_select", defaultSettings.EndAfterSelect, GetBoolFromString);
	static auto load_ini = login::db::CacheSetting<bool>("load_ini", false, GetBoolFromString);
	static auto detect_info = login::db::CacheSetting<bool>("detect_info", defaultSettings.DetectInformation, GetBoolFromString);
	static auto client_launch_delay = login::db::CacheSetting<int>("client_launch_delay", defaultSettings.ClientLaunchDelay, GetIntFromString);
	static auto char_select_delay = login::db::CacheSetting<int>("char_select_delay", defaultSettings.CharSelectDelay, GetIntFromString);
	static auto connect_retries = login::db::CacheSetting<int>("login_connect_retries", defaultSettings.ConnectRetries, GetIntFromString);

	static auto password_timeout_hours = login::db::CacheSetting<int>("password_timeout_hours", 720, GetIntFromString);
	static std::string hours_label = fmt::format("Hours to Save Password ({:.1f} days)", static_cast<float>(password_timeout_hours.Read()) / 24.f);
	static auto perpetual_password = login::db::CacheSetting<bool>("perpetual_password", false, GetBoolFromString);

	static auto company = login::db::CacheSetting<std::string>("reg_company", "",
		[](const std::string_view result, const std::string& _) { return std::string(result); });

	static ServerTypeInfo server_type_info;
	static ServerNameInfo server_name_info;

	// session section
	if (ImGui::Checkbox("Debug Output", &debug.Read()))
		login::db::WriteSetting("debug", debug.Updated() ? "true" : "false", "Show plugin debug statements");
	ImGui::SameLine(); imgui::HelpMarker("Show plugin debug statements");

	ImGui::Spacing();
	if (ImGui::Checkbox("Kick Active Character", &kick_active.Read()))
		login::db::WriteSetting("kick_active", kick_active.Updated() ? "true" : "false", "Automatically kick the active character when prompted");
	ImGui::SameLine(); imgui::HelpMarker("Automatically kick the active character when prompted");

	ImGui::Spacing();
	if (ImGui::Checkbox("End After Character Select", &end_after_select.Read()))
		login::db::WriteSetting("end_after_select", end_after_select.Updated() ? "true" : "false", "Disable the plugin once the character has been selected");
	ImGui::SameLine(); imgui::HelpMarker("Disable the plugin once the character has been selected");

	ImGui::Spacing();
	if (ImGui::Checkbox("Load Legacy Config Next Load", &load_ini.Read()))
		login::db::WriteSetting("load_ini", load_ini.Updated() ? "true" : "false", "Import data from autologin ini file one time at load");
	ImGui::SameLine(); imgui::HelpMarker("Import data from autologin ini file one time at load");

	ImGui::Spacing();
	if (ImGui::Checkbox("Automatically Detect Login Info", &detect_info.Read()))
		login::db::WriteSetting("detect_info", detect_info.Updated() ? "true" : "false", "Automatically detect login information from the client as the user logs in");
	ImGui::SameLine(); imgui::HelpMarker("Automatically detect login information from the client as the user logs in");

	ImGui::Spacing();
	ImGui::SetNextItemWidth(50.f);
	if (ImGui::InputScalar("Client Launch Delay", ImGuiDataType_U32, &client_launch_delay.Read()))
		login::db::WriteSetting("client_launch_delay", std::to_string(client_launch_delay.Updated()), "Seconds in between client launches");
	ImGui::SameLine(); imgui::HelpMarker("Seconds in between client launches");

	ImGui::Spacing();
	ImGui::SetNextItemWidth(50.f);
	if (ImGui::InputScalar("Character Select Delay", ImGuiDataType_U32, &char_select_delay.Read()))
		login::db::WriteSetting("char_select_delay", std::to_string(char_select_delay.Updated()), "Seconds to delay character selection at the character select screen");
	ImGui::SameLine(); imgui::HelpMarker("Seconds to delay character selection at the character select screen");

	ImGui::Spacing();
	ImGui::SetNextItemWidth(50.f);
	if (ImGui::InputScalar("Connect Retries", ImGuiDataType_U32, &connect_retries.Read()))
		login::db::WriteSetting("login_connect_retries", std::to_string(connect_retries.Updated()), "Number of times to attempt to reconnect, 0 for infinite");
	ImGui::SameLine(); imgui::HelpMarker("Number of times to attempt to reconnect, 0 for infinite");

	ImGui::Spacing();
	if (ImGui::Button("Load Legacy Config"))
		Import();
	ImGui::SameLine(); imgui::HelpMarker("Import data from autologin ini right now");

	ImGui::Separator();
	// password section
	ImGui::Spacing();
	if (ImGui::Checkbox("Save Password Forever", &perpetual_password.Read()))
		login::db::WriteSetting("perpetual_password", perpetual_password.Updated() ? "true" : "false", "Save the master password to this system so that it never has to be entered again");
	ImGui::SameLine(); imgui::HelpMarker("Save the master password to this system so that it never has to be entered again");

	ImGui::Spacing();
	ImGui::BeginDisabled(perpetual_password.Read());
	ImGui::SetNextItemWidth(50.f);
	if (ImGui::InputScalar(hours_label.c_str(), ImGuiDataType_U32, &password_timeout_hours.Read()))
	{
		hours_label = fmt::format("Hours to Save Password ({:.1f} days)", static_cast<float>(password_timeout_hours.Updated()) / 24.f);
		login::db::WriteSetting("password_timeout_hours", std::to_string(password_timeout_hours.Updated()), "Number of hours to save the master password before requiring re-entry");
	}
	ImGui::SameLine(); imgui::HelpMarker("Number of hours to save the master password before requiring re-entry");
	ImGui::EndDisabled();

	ImGui::Spacing();
	if (ImGui::Button("Retrieve Master Password"))
		LauncherImGui::OpenModal("Stored Master Password");
	ImGui::SameLine(); imgui::HelpMarker("Retrieve the stored password from the system registry if present");

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
	ImGui::SameLine(); imgui::HelpMarker("Set a new master password (will update all saved encrypted values)");

	ImGui::Spacing();
	ImGui::SetNextItemWidth(200.f);
	if (ImGui::InputText("Registry Company Name", &company.Read(), ImGuiInputTextFlags_EnterReturnsTrue))
	{
		const auto pass = login::db::ReadMasterPass();
		login::db::WriteSetting("reg_company", company.Updated());
		if (pass)
			login::db::CacheMasterPass(*pass);
	}
	ImGui::SameLine(); imgui::HelpMarker("Set the company where the master pass is cached in the registry");

	ImGui::Separator();
	// management section
	ImGui::Spacing();
	if (ImGui::Button("Manage EQ Installs"))
		LauncherImGui::OpenModal("Manage EQ Installs");
	ImGui::SameLine(); imgui::HelpMarker("Manage the the mapping of EQ build to EQ install location");

	if (LauncherImGui::BeginModal("Manage EQ Installs", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
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
	ImGui::SameLine(); imgui::HelpMarker("Manage the server short name to long name mappings");

	if (LauncherImGui::BeginModal("Manage Server Names", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		DefaultListBox(server_name_info);

		ImGui::Separator();
		ImGui::SetCursorPosX(ImGui::GetContentRegionMax().x - ImGui::CalcTextSize("Done").x - ImGui::GetStyle().FramePadding.x * 2);
		if (ImGui::Button("Done"))
			LauncherImGui::CloseModal();

		LauncherImGui::EndModal();
	}
}

void ShowAutoLoginMenu()
{
	fmt::memory_buffer buf;
	const auto buf_ins = std::back_inserter(buf);

	if (ImGui::MenuItem("Open Config"))
		LauncherImGui::SelectMainPanel("AutoLogin/Profiles");

	if (ImGui::MenuItem("Launch Without Login"))
		LaunchCleanSession();

	ImGui::SetNextWindowSizeConstraints(ImVec2(120, 0), ImVec2(FLT_MAX, FLT_MAX));
	if (ImGui::BeginMenu("Profiles"))
	{
		ShowProfilesMenu(true);

		ImGui::EndMenu();
	}

	ImGui::SetNextWindowSizeConstraints(ImVec2(120, 0), ImVec2(FLT_MAX, FLT_MAX));
	if (ImGui::BeginMenu("Characters"))
	{
		ShowCharactersMenu();

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
	LauncherImGui::AddMainPanel("AutoLogin/Profiles", ShowProfilesWindow);
	LauncherImGui::AddMainPanel("AutoLogin/Characters", ShowCharactersWindow);
	LauncherImGui::AddMainPanel("AutoLogin/Accounts", ShowAccountsWindow);
	LauncherImGui::AddMainPanel("AutoLogin/Settings", ShowSettingsWindow);
	LauncherImGui::AddContextGroup("AutoLogin", ShowAutoLoginMenu);

	LoadAllStarredCallback = LoadProfileGroup;
	LoadCharacterCallback = LoadCharacter;
	UnregisterGlobalHotkeyCallback = [](uint32_t pid, const std::string& hotkey)
	{
		SPDLOG_DEBUG("Unregister Global Hotkey: pid={} hotkey={}", pid, hotkey);

		UnregisterGlobalHotkey(hotkey);
	};

	RegisterGlobalHotkeyCallback = [](uint32_t processId, const std::string& hotkey)
	{
		SPDLOG_DEBUG("Register Global Hotkey: pid={} hotkey={}", processId, hotkey);

		RegisterGlobalHotkey(GetEQWindowHandleForProcessId(processId), hotkey);
	};
}

void ShutdownAutoLoginImGui()
{
	if (s_eqDirDialog != nullptr)
		IGFD_Destroy(s_eqDirDialog);
}
