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

#include "imgui/ImGuiUtils.h"

namespace fs = std::filesystem;
using namespace mq;

static ImGuiFileDialog* s_eqDirDialog = nullptr;

#pragma region Helpers

using Action = std::function<void()>;

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
		if (Valid())
			login::db::CreateOrUpdateServer(ShortName, LongName);
	}

	void Delete() const
	{
		login::db::DeleteServer(ShortName, LongName);
	}

	static constexpr std::string_view label = "Server Name";

	[[nodiscard]] bool Valid() const { return !ShortName.empty() && !LongName.empty(); }
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
		if (Valid() && !EQPath.empty())
			login::db::CreateOrUpdateServerType(ServerType, EQPath);
	}

	void Delete() const
	{
		login::db::DeleteServerType(ServerType);
	}

	static constexpr std::string_view label = "EQ Install";

	[[nodiscard]] bool Valid() const { return !ServerType.empty(); }
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

	void Delete() const
	{
		login::db::DeleteAccount(Account, ServerType.ServerType);
	}

	static constexpr std::string_view label = "Account";

	[[nodiscard]] bool Valid() const { return !Account.empty() && ServerType.Valid(); }

	enum class SortID : unsigned int
	{
		Account,
		EQ_Install,
	};

	static bool Compare(const ImGuiTableSortSpecs* specs, const ProfileRecord& l, const ProfileRecord& r)
	{
		for (int n = 0; n < specs->SpecsCount; ++n)
		{
			const auto& spec = specs->Specs[n];
			const auto str_cmp = [&spec](std::string_view a, std::string_view b)
				{
					static ci_less less;
					if (spec.SortDirection == ImGuiSortDirection_Ascending) return less(a, b);

					return !less(a, b);
				};

			switch (static_cast<SortID>(spec.ColumnUserID))
			{
			case SortID::Account:
				if (!ci_equals(l.accountName, r.accountName))
					return str_cmp(l.accountName, r.accountName);
				break;
			case SortID::EQ_Install:
				if (!ci_equals(l.serverType, r.serverType))
					return str_cmp(l.serverType, r.serverType);
				break;
			}
		}

		return false;
	}

	static void Sort(const ImGuiTableSortSpecs* sort_specs, std::vector<ProfileRecord>& items)
	{
		if (items.size() > 1)
			std::sort(items.begin(), items.end(),
				[sort_specs](const ProfileRecord& a, const ProfileRecord& b)
				{ return Compare(sort_specs, a, b); });
	}
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

	void Delete() const
	{
		login::db::DeleteCharacter(Server, Character);
	}

	static constexpr std::string_view label = "Character";

	[[nodiscard]] bool Valid() const { return !Server.empty() && !Character.empty(); }

	// character sort is universal (so that settings persist to the context menu)
	enum class SortID : unsigned int
	{
		Account,
		EQ_Install,
		Server,
		Character,
		Class,
		Level,
	};

	// TODO: persist the sort specs to share with the context menu
	// persist the sort specs to sync sorting with the character context
	static ImGuiID GetID()
	{
		static ImGuiID CharacterTableID = ImGui::GetIDWithSeed("Character Table", nullptr, ImGui::GetMainViewport()->ID);
		return CharacterTableID;
	}

	static void SetupColumns()
	{
		ImGui::TableSetupColumn(ICON_MD_VISIBILITY, ImGuiTableColumnFlags_NoSort | ImGuiTableColumnFlags_WidthFixed, ImGui::GetFrameHeight());
		ImGui::TableSetupColumn("Character", ImGuiTableColumnFlags_DefaultSort, 0.f, static_cast<ImGuiID>(SortID::Character));
		ImGui::TableSetupColumn("Server", ImGuiTableColumnFlags_None, 0.f, static_cast<ImGuiID>(SortID::Server));
		ImGui::TableSetupColumn("Class", ImGuiTableColumnFlags_None, 0.f, static_cast<ImGuiID>(SortID::Class));
		ImGui::TableSetupColumn("Level", ImGuiTableColumnFlags_None, 0.f, static_cast<ImGuiID>(SortID::Level));
		ImGui::TableSetupColumn("Account", ImGuiTableColumnFlags_None, 0.f, static_cast<ImGuiID>(SortID::Account));
		ImGui::TableSetupColumn("EQ Install", ImGuiTableColumnFlags_None, 0.f, static_cast<ImGuiID>(SortID::EQ_Install));
		ImGui::TableSetupColumn("##buttons", ImGuiTableColumnFlags_NoSort);
	}

	static std::vector<ImGuiTableColumnSortSpecs> s_sortSpecs;
	static bool s_contextMenuDirty;

	static void PersistSpecs(const ImGuiTableSortSpecs* specs)
	{
		s_sortSpecs.clear();
		for (int n = 0; n < specs->SpecsCount; ++n)
			s_sortSpecs.push_back(specs->Specs[n]);

		s_contextMenuDirty = true;
	}

	static bool Compare(const ProfileRecord& l, const ProfileRecord& r)
	{
		for (const auto& spec : s_sortSpecs)
		{
			const auto str_cmp = [&spec](std::string_view a, std::string_view b)
				{
					static ci_less less;
					if (spec.SortDirection == ImGuiSortDirection_Ascending) return less(a, b);

					return !less(a, b);
				};

			switch (static_cast<SortID>(spec.ColumnUserID))
			{
			case SortID::Account:
				if (!ci_equals(l.accountName, r.accountName))
					return str_cmp(l.accountName, r.accountName);
				break;
			case SortID::EQ_Install:
				if (!ci_equals(l.serverType, r.serverType))
					return str_cmp(l.serverType, r.serverType);
				break;
			case SortID::Server:
				if (!ci_equals(l.serverName, r.serverName))
					return str_cmp(l.serverName, r.serverName);
				break;
			case SortID::Character:
				if (!ci_equals(l.characterName, r.characterName))
					return str_cmp(l.characterName, r.characterName);
				break;
			case SortID::Class:
				if (!ci_equals(l.characterClass, r.characterClass))
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

	static void Sort(const ImGuiTableSortSpecs* sort_specs, std::vector<ProfileRecord>& items)
	{
		PersistSpecs(sort_specs);

		Sort(items);
	}

	static void Sort(std::vector<ProfileRecord>& items)
	{
		if (items.size() > 1)
			std::sort(items.begin(), items.end(), Compare);
	}
};

std::vector<ImGuiTableColumnSortSpecs> CharacterInfo::s_sortSpecs;
bool CharacterInfo::s_contextMenuDirty = false;

struct ProfileInfo : ProfileRecord
{
	CharacterInfo Character;

	void Fill();
	[[nodiscard]] std::string Preview() const;
	void Edit(const char*, const Action&);

	static constexpr std::string_view label = "Profile";

	[[nodiscard]] bool Valid() const { return !profileName.empty() && Character.Valid(); }

	ProfileInfo& operator=(const ProfileRecord& record)
	{
		ProfileRecord::operator=(record);
		Character = {};
		return *this;
	}

	static bool Compare(const ProfileRecord& a, const ProfileRecord& b)
	{
		if (a.selected == 0 && b.selected == 0)
			return a.characterName.compare(b.characterName) < 0;

		if (a.selected == 0)
			return false;

		if (b.selected == 0)
			return true;

		return a.selected < b.selected;
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
			if (old.Valid())
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

	[[nodiscard]] bool Valid() const { return !profileName.empty(); }
};

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
	selected.Edit(add_name, [&info]
		{
			selected.Update({});
			info = selected;
		});

	static constexpr std::string_view edit_prefix = "Edit ";
	static constexpr const char* edit_name = JoinLabels<edit_prefix, Info::label>::literal;
	ImGui::SameLine();
	if (ImGui::Button(edit_name) || ImGui::IsKeyPressed(ImGuiKey_Enter))
	{
		if (info.Valid())
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
		if (info.Valid())
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
static void DefaultCombo(Info& info, const Action& select_action)
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
			ImGui::TextUnformatted(JoinLabels<Info::label_override>::literal);
		}
	}
	else
	{
		ImGui::SameLine(0.f, ImGui::GetStyle().ItemInnerSpacing.x);
		ImGui::TextUnformatted(JoinLabels<Info::label>::literal);
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

static void SetEQDirModal(std::optional<std::string>& eq_path, const Action& ok_action)
{
	if (LauncherImGui::BeginModal("Input EQ Path", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		if (eq_path)
			ImGui::TextUnformatted(eq_path->c_str());
		else
			ImGui::TextUnformatted(GetEQRoot().c_str());

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
		const bool is_selected = ci_equals(short_name, ShortName) &&
			ci_equals(long_name, LongName);

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

void ServerNameInfo::Fill() {}

std::string ServerNameInfo::Preview() const
{
	if (Valid())
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
		const bool is_selected = ci_equals(server_type, ServerType);
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
		const bool is_selected = ci_equals(account, Account) &&
			ci_equals(server_type, ServerType.ServerType);

		format_to(buf_ins, "{} ({})", account, server_type);
		buf.push_back(0);

		if (ImGui::Selectable(buf.data(), is_selected))
		{
			Account = account;
			ServerType.ServerType = server_type;

			select_action();
		}

		if (is_selected)
			ImGui::SetItemDefaultFocus();

		buf.clear();
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
	if (Valid())
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

		DefaultCombo(ServerType, [] {});

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
					if (ImGui::Selectable("Edit"))
					{
						selected_account.Account = match.accountName;
						selected_account.ServerType.ServerType = match.serverType;
						selected_account.Fill();

						selected_profile = match;

						LauncherImGui::OpenModal("Edit Account");
					}

					if (ImGui::Selectable("Remove"))
					{
						remove_message = fmt::format("Are you certain you want to remove account '{} ({})'? All associated characters will also be removed.", match.accountName, match.serverType);
						selected_profile = match;
						LauncherImGui::OpenModal("Remove Account");
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

	selected_account.Edit("Edit Account", []
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
		const bool is_selected = ci_equals(character, Character) &&
			ci_equals(server, Server);

		format_to(buf_ins, "{} : {}", character, server);
		buf.push_back(0);

		if (ImGui::Selectable(buf.data(), is_selected, ImGuiSelectableFlags_SpanAvailWidth))
		{
			Character = character;
			Server = server;

			select_action();
		}

		if (is_selected)
			ImGui::SetItemDefaultFocus();

		buf.clear();
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
	if (Valid())
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

	static bool show_hidden = true;
	float height = ImGui::GetContentRegionAvail().y - ImGui::GetFrameHeightWithSpacing();

	ImGui::PushOverrideID(CharacterInfo::GetID());
	if (ImGui::BeginTable("Main List", 8, flags, { 0.f, height }))
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
		if (show_hidden)
			clipper.Begin(static_cast<int>(characters.Updated().size()));
		else
			clipper.Begin(static_cast<int>(filtered_characters.size()));

		while (clipper.Step())
		{
			for (int row = clipper.DisplayStart; row < clipper.DisplayEnd; ++row)
			{
				int idx = row;
				if (!show_hidden)
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
					LoadCharacter(match);
				}

				ImGui::SameLine();
				// this needs to be here to handle the fact that hotkey isn't optional
				if (ImGui::SmallButton("..."))
				{
					selected_profile = match;

					LauncherImGui::OpenModal("Play With Params");
				}

				ImGui::PopID();
			}
		}

		ImGui::EndTable();
	}
	ImGui::PopID();

	LauncherImGui::ToggleSlider("Show Hidden Characters", &show_hidden);

	selected_character.Edit("Edit Character", []
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

		DefaultModalButtons([]
			{
				LoadCharacter(selected_profile);
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
	if (Valid())
		return fmt::format("[{}] {}", profileName, Character.Preview());

	return "";
}

void ProfileInfo::Edit(const char* name, const Action& ok_action)
{
	static std::optional<std::string> eq_path;
	static std::string hot_key;
	static std::optional<std::string> custom_ini;

	if (LauncherImGui::BeginModal(name, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		DefaultCombo(Character.Account, [this]
			{
				Character.Character.clear();
				Character.Server.clear();
			});

		// drop down for character or create new, only show this if an account has been selected
		if (Character.Account.Valid())
		{
			DefaultCombo(Character, [this]
				{
					if (Character.Valid() && !profileName.empty())
						login::db::ReadProfile(*this);
				});

			// display options to complete the profile only if the profile has a character
			if (Character.Valid())
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
				ImGui::Text("%s", customClientIni ? customClientIni->c_str() : "<Default>");
			}
		}

		DefaultModalButtons(ok_action);

		LauncherImGui::EndModal();
	}
}

static void ProfileTable(const ProfileGroupInfo& info)
{
	static ProfileInfo selected;
	static std::string remove_message;

	constexpr ImGuiTableFlags flags = ImGuiTableFlags_SizingStretchProp
		| ImGuiTableFlags_Borders
		| ImGuiTableFlags_NoBordersInBody
		| ImGuiTableFlags_ScrollY;

	float height = ImGui::GetContentRegionAvail().y - ImGui::GetFrameHeightWithSpacing();

	if (ImGui::BeginTable("Main List", 7, flags, { 0.f, height }))
	{
		if (!info.profileName.empty())
		{
			ImGui::TableSetupColumn(ICON_MD_POWER_SETTINGS_NEW "##Selected", ImGuiTableColumnFlags_WidthFixed, ImGui::GetFrameHeight());
			ImGui::TableSetupColumn("Character");
			ImGui::TableSetupColumn("Server");
			ImGui::TableSetupColumn("Account");
			ImGui::TableSetupColumn("Persona");
			ImGui::TableSetupColumn("Hotkey");
			ImGui::TableSetupColumn("##play");
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableHeadersRow();

			if (ImGui::TableGetColumnFlags(0) & ImGuiTableColumnFlags_IsHovered)
				ImGui::SetTooltip("Indicates whether that character will load when the group is launched.");

			static auto last_group = info.profileName;
			static auto profiles = login::db::CacheResults([]
				{
					return login::db::GetProfiles(last_group);
				});

			const bool force_profiles_update = !ci_equals(last_group, info.profileName);
			if (force_profiles_update)
				last_group = info.profileName;

			static bool do_write = false;
			static ProfileRecord* held_ptr = nullptr;

			ImGuiListClipper clipper;
			clipper.Begin(static_cast<int>(profiles.Read(force_profiles_update).size()));
			while (clipper.Step())
			{
				for (int row = clipper.DisplayStart; row < clipper.DisplayEnd; ++row)
				{
					auto& profile = profiles.Updated().at(row);
					ImGui::PushID(&profile);

					ImGui::TableNextRow();
					ImGui::TableNextColumn();

					bool checked = profile.selected > 0;
					if (LauncherImGui::SmallCheckbox("##Selected", &checked))
					{
						profile.selected = checked ? 1 : 0;
						do_write = true;
					}

					ImGui::SameLine(0.f, 0.f);
					ImGui::Selectable("##row", false, ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_AllowOverlap);

					if (ImGui::IsItemHovered(ImGuiHoveredFlags_RectOnly))
					{
						if (held_ptr != nullptr && ImGui::IsMouseReleased(ImGuiMouseButton_Left))
						{
							held_ptr->selected = 1;
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
							held_ptr->selected = 0;
						}
						else if (ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
						{
							if (profile.selected > 0)
								profile.selected = 0;
							else
								profile.selected = 1;

							do_write = true;
						}
					}

					if (ImGui::IsItemClicked(ImGuiMouseButton_Right))
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
							remove_message = fmt::format("Are you sure you want to remove profile '{}'?", profile.characterName);
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
						LoadCharacter(profile);
					}

					ImGui::PopID();
				}
			}

			if (do_write)
			{
				unsigned int order = 0;
				for (auto& profile : profiles.Updated())
				{
					if (profile.selected > 0)
						profile.selected = ++order;

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
		selected = {};
		selected.profileName = info.profileName;
		LauncherImGui::OpenModal("Add Profile");
	}

	ImGui::SameLine();
	ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 0.5f), "Drag & drop a row to reorder");

	selected.Edit("Add Profile", []
		{
			if (selected.Valid())
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
			if (selected.Valid())
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
		const bool is_selected = ci_equals(group, profileName);
		if (ImGui::Selectable(group.c_str(), is_selected))
		{
			profileName = group;
			select_action();
		}

		if (is_selected)
			ImGui::SetItemDefaultFocus();
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

void ShowProfilesWindow()
{
	static ProfileGroupInfo info;
	static ProfileGroupInfo selected;
	// Code goes into this scope for selecting and modifying profiles/groups
	ImGui::BeginChild("Main Child", ImVec2(0, 0), ImGuiChildFlags_Border, ImGuiWindowFlags_MenuBar);

	if (ImGui::BeginMenuBar())
	{
		if (ImGui::SmallButton("Create"))
		{
			selected = {};
			LauncherImGui::OpenModal("Create Profile Group");
		}

		selected.Edit("Create Profile Group", []
			{
				info = selected;
				if (info.Valid())
					login::db::CreateProfileGroup(info);
			});

		if (ImGui::SmallButton("Edit") && info.Valid())
		{
			selected = info;
			LauncherImGui::OpenModal("Edit Profile Group");
		}

		selected.Edit("Edit Profile Group", []
			{
				if (selected.Valid())
					login::db::UpdateProfileGroup(info.profileName, selected);

				info = selected;
			});

		static std::string remove_message;
		if (ImGui::SmallButton("Remove") && info.Valid())
		{
			remove_message = fmt::format("Are you sure you want to remove profile group '{}'? All associated profiles will also be removed.", info.profileName.c_str());
			LauncherImGui::OpenModal("Remove Profile Group");
		}

		DeleteModal("Remove Profile Group", remove_message, []
			{
				if (info.Valid())
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

	if (info.profileName.empty())
	{
		const auto& groups = login::db::ListProfileGroups().vector();
		if (!groups.empty())
			info.profileName = groups.front();
	}

	if (ImGui::BeginCombo("##Profile Group", info.Preview().c_str()))
	{
		info.List([] {});

		ImGui::EndCombo();
	}

	ImGui::SameLine();
	if (ImGui::Button("Launch Group") && info.Valid())
	{
		LoadProfileGroup(info.profileName);
	}

	if (info.Valid()) ProfileTable(info);

	ImGui::EndChild();
}

void ShowCharactersWindow()
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
}

void ShowAccountsWindow()
{
	ImGui::BeginChild("Main Child", ImVec2(0, 0), ImGuiChildFlags_Border, ImGuiWindowFlags_MenuBar);

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

	info.Edit("Add Account", []
		{
			ProfileRecord profile;
			profile.accountName = info.Account;
			profile.accountPassword = info.Password;
			profile.serverType = info.ServerType.ServerType;
			login::db::CreateAccount(profile);
		});

	AccountTable(search);

	ImGui::EndChild();
}

void ShowSettingsWindow()
{
	ImGui::BeginChild("Main Child", ImVec2(0, 0), ImGuiChildFlags_Border, ImGuiWindowFlags_None);

	static auto debug = login::db::CacheSetting<bool>("debug", false, GetBoolFromString);
	static auto kick_active = login::db::CacheSetting<bool>("kick_active", true, GetBoolFromString);
	static auto end_after_select = login::db::CacheSetting<bool>("end_after_select", false, GetBoolFromString);
	static auto load_ini = login::db::CacheSetting<bool>("load_ini", false, GetBoolFromString);
	static auto client_launch_delay = login::db::CacheSetting<int>("client_launch_delay", 3, GetIntFromString);
	static auto char_select_delay = login::db::CacheSetting<int>("char_select_delay", 3, GetIntFromString);
	static auto connect_retries = login::db::CacheSetting<int>("connect_retries", 0, GetIntFromString);

	static auto password_timeout_hours = login::db::CacheSetting<int>("password_timeout_hours", 720, GetIntFromString);
	static std::string hours_label = fmt::format("Hours to Save Password ({:.1f} days)", static_cast<float>(password_timeout_hours.Read()) / 24.f);
	static auto perpetual_password = login::db::CacheSetting<bool>("perpetual_password", false, GetBoolFromString);

	static auto company = login::db::CacheSetting<std::string>("reg_company", "",
		[](const std::string_view result, const std::string& _) { return std::string(result); });

	static ServerTypeInfo server_type_info;
	static ServerNameInfo server_name_info;

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
		login::db::WriteSetting("connect_retries", std::to_string(connect_retries.Updated()), "Number of times to attempt to reconnect, 0 for infinite");
	ImGui::SameLine(); imgui::HelpMarker("Number of times to attempt to reconnect, 0 for infinite");

	ImGui::Spacing();
	if (ImGui::Button("Load Legacy Config"))
		Import();
	ImGui::SameLine(); imgui::HelpMarker("Import data from autologin ini right now");

	ImGui::Separator();
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

	ImGui::EndChild();
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

				const bool force_profiles_update = !ci_equals(last_group, group);
				if (force_profiles_update)
					last_group = group;

				if (profiles.Read(force_profiles_update).empty())
				{
					ImGui::Text("No available profiles");
				}
				else
				{
					if (ImGui::Selectable("Launch All", false, ImGuiSelectableFlags_SpanAllColumns))
					{
						LoadProfileGroup(group);
					}

					ImGui::Separator();

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

						for (auto& profile : profiles.Updated())
						{
							ImGui::TableNextRow(ImGuiTableRowFlags_None);
							ImGui::TableNextColumn();
							if (profile.selected != 0)
							{
								ImGui::PushStyleColor(ImGuiCol_Text, { .75f, .75f, 0.f, 1.f });
								ImGui::TextUnformatted(ICON_MD_STAR);
								ImGui::PopStyleColor();
							}

							ImGui::TableNextColumn();
							if (ImGui::Selectable(profile.characterName.c_str(), false, ImGuiSelectableFlags_SpanAllColumns))
								LoadCharacter(profile);

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
							if (loaded.find(LoginInstance::Key(profile)) != loaded.end())
							{
								ImGui::PushStyleColor(ImGuiCol_Text, { 0.f, 1.f, 0.f, 1.f });
								ImGui::TextUnformatted(ICON_MD_POWER_SETTINGS_NEW);
								ImGui::PopStyleColor();
							}
						}

						ImGui::EndTable();
					}
				}

				ImGui::EndMenu();
			}
		}
		ImGui::EndMenu();
	}

	ImGui::SetNextWindowSizeConstraints(ImVec2(120, 0), ImVec2(FLT_MAX, FLT_MAX));
	if (ImGui::BeginMenu("Characters"))
	{
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
						if (ImGui::BeginTable("Main List", 8, ImGuiTableFlags_Sortable | ImGuiTableFlags_SortMulti))
						{
							CharacterInfo::SetupColumns();
							CharacterInfo::Sort(ImGui::TableGetSortSpecs(), server_characters.Updated());
							ImGui::EndTable();
						}
						ImGui::PopID();

						window->RootWindow->Flags = win_flags;

						return &server_characters.Updated();
					}();

				const bool force_characters_update = !ci_equals(last_server, server);
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
							LoadCharacter(profile);

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
						if (loaded.find(LoginInstance::Key(profile)) != loaded.end())
						{
							ImGui::PushStyleColor(ImGuiCol_Text, { 0.f, 1.f, 0.f, 1.f });
							ImGui::TextUnformatted(ICON_MD_POWER_SETTINGS_NEW);
							ImGui::PopStyleColor();
						}	

						ImGui::PopID();
					}

					ImGui::EndTable();
				}

				ImGui::EndMenu();
			}
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
	LauncherImGui::AddMainPanel("AutoLogin/Profiles", ShowProfilesWindow);
	LauncherImGui::AddMainPanel("AutoLogin/Characters", ShowCharactersWindow);
	LauncherImGui::AddMainPanel("AutoLogin/Accounts", ShowAccountsWindow);
	LauncherImGui::AddMainPanel("AutoLogin/Settings", ShowSettingsWindow);
	LauncherImGui::AddContextGroup("AutoLogin", ShowAutoLoginMenu);
}

void ShutdownAutoLoginImGui()
{
	if (s_eqDirDialog != nullptr)
		IGFD_Destroy(s_eqDirDialog);
}
