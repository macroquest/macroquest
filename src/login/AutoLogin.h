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

#pragma once

#include "login/Login.h"
#include "imgui/imgui.h"
#include "imgui/misc/cpp/imgui_stdlib.h"

#include <functional>
#include <optional>
#include <string>
#include <unordered_map>
#include <fmt/format.h>

struct ProfileRecord;

using Action = std::function<void()>;

struct AutoLoginSettings
{
	bool KickActiveCharacter = true;
	bool EndAfterSelect = false;
	int CharSelectDelay = 3;
	int ConnectRetries = 5;
	int ClientLaunchDelay = 3;
	bool ShowHiddenCharacters = true;
	bool DetectInformation = true;
};

struct LoginInstance
{
	LoginInstance(uint32_t pid, const ProfileRecord& profile);

	static std::string Key(std::string_view Server, std::string_view Character);
	static std::string Key(const ProfileRecord& profile);
	[[nodiscard]] std::string Key() const { return Key(Server, Character); }

	void Update(uint32_t pid, const ProfileRecord& profile);

	uint32_t PID = 0;

	const std::string Server;
	const std::string ServerType;
	const std::string Character;
	const std::string Account;
	const std::string EQPath;

	std::optional<std::string> ProfileGroup;
	std::optional<std::string> Hotkey;
};

struct ServerNameInfo
{
	std::string ShortName;
	std::string LongName;

	static constexpr std::string_view label = "Server Name";

	void List(const Action&);
	void Fill();
	[[nodiscard]] std::string Preview() const;

	void Update(const ServerNameInfo&) const;
	void Delete() const;

	[[nodiscard]] bool Valid() const { return !ShortName.empty() && !LongName.empty(); }
};

struct ServerTypeInfo
{
	std::string ServerType;
	std::string EQPath;

	static constexpr std::string_view label = "EQ Install";

	void List(const Action&);
	void Fill();
	[[nodiscard]] std::string Preview() const;

	void Update(const ServerTypeInfo&) const;
	void Delete() const;

	[[nodiscard]] bool Valid() const { return !ServerType.empty(); }
};

struct AccountInfo
{
	std::string Account;
	std::string Password;
	ServerTypeInfo ServerType;

	static constexpr std::string_view label = "Account";

	void List(const Action&);
	void Fill();
	[[nodiscard]] std::string Preview() const;

	void Update(const AccountInfo& old) const;
	void Delete() const;


	[[nodiscard]] bool Valid() const { return !Account.empty() && ServerType.Valid(); }

	enum class SortID : unsigned int
	{
		Account,
		EQ_Install,
	};

	static bool Compare(const ImGuiTableSortSpecs* specs, const ProfileRecord& l, const ProfileRecord& r);
	static void Sort(const ImGuiTableSortSpecs* sort_specs, std::vector<ProfileRecord>& items);
};

struct CharacterInfo
{
	AccountInfo Account;
	std::string Server;
	std::string Character;

	static constexpr std::string_view label = "Character";

	void List(const Action&);
	void Fill();
	[[nodiscard]] std::string Preview() const;

	void Update(const CharacterInfo& old) const;
	void Delete() const;

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

	static ImGuiID GetID();

	static void SetupColumns();

	static std::vector<ImGuiTableColumnSortSpecs> s_sortSpecs;
	static bool s_contextMenuDirty;

	static void PersistSpecs(const ImGuiTableSortSpecs* specs);
	static bool Compare(const ProfileRecord& l, const ProfileRecord& r);
	static void Sort(const ImGuiTableSortSpecs* sort_specs, std::vector<ProfileRecord>& items);
	static void Sort(std::vector<ProfileRecord>& items);
};

struct ProfileInfo : ProfileRecord
{
	CharacterInfo Character;

	static constexpr std::string_view label = "Profile";

	void Fill();
	[[nodiscard]] std::string Preview() const;

	[[nodiscard]] bool Valid() const { return !profileName.empty() && Character.Valid(); }

	ProfileInfo& operator=(const ProfileRecord& record);
};

struct ProfileGroupInfo : ProfileGroup
{
	static constexpr std::string_view label = "Profile Group";
	static constexpr std::string_view label_override;

	void List(const Action&);
	void Fill();
	[[nodiscard]] std::string Preview() const;

	void Update(const ProfileGroupInfo& old) const;
	void Delete() const;

	[[nodiscard]] bool Valid() const { return !profileName.empty(); }
};

const std::unordered_map<std::string, LoginInstance>& GetLoadedInstances();
const LoginInstance* GetAccountInstance(std::string_view accountName, std::string_view serverType);
const LoginInstance* UpdateInstance(uint32_t pid, const ProfileRecord& profile, bool add = false);
void RemoveInstance(uint32_t pid);
const LoginInstance* StartInstance(ProfileRecord& profile);

void DrawStatusIcon(const ProfileRecord& record);
void ShowProfilesMenu(bool showLoadAll);
void ShowCharactersMenu();

extern std::function<void(const std::string&, bool)> LoadAllStarredCallback;
extern std::function<void(const ProfileRecord&, bool)> LoadCharacterCallback;
extern std::function<void(uint32_t, const std::string&)> UnregisterGlobalHotkeyCallback;
extern std::function<void(uint32_t, const std::string&)> RegisterGlobalHotkeyCallback;
extern std::string EQPathErrorMessage;

template <typename Result>
void DefaultComboList(
	std::string& search,
	const std::function<void(const Result&)>& select_action,
	login::db::Cache<std::function<std::vector<Result>()>>& cache,
	const std::function<bool(const Result&)>& is_selected,
	const std::function<void(fmt::memory_buffer&, const Result&)>& preview)
{
	fmt::memory_buffer buf;

	static bool force_update = false;
	auto do_select = [&search, &select_action](const Result& match)
		{
			select_action(match);
			search.clear();
			force_update = true;

			ImGui::CloseCurrentPopup();
		};

	cache.ReadHasChanged(force_update);
	if (force_update) force_update = false;

	if (!ImGui::IsAnyItemActive()) ImGui::SetKeyboardFocusHere();
	if (ImGui::InputText("##search", &search, ImGuiInputTextFlags_EscapeClearsAll))
		force_update = true;

	if (ImGui::IsKeyPressed(ImGuiKey_Enter) && !cache.Updated().empty())
		do_select(cache.Updated().front());

	ImGuiListClipper clipper;
	clipper.Begin(static_cast<int>(cache.Updated().size()));
	while (clipper.Step())
	{
		for (int row = clipper.DisplayStart; row < clipper.DisplayEnd; ++row)
		{
			auto& match = cache.Updated().at(row);

			preview(buf, match);
			buf.push_back(0);

			if (ImGui::Selectable(buf.data(), is_selected(match)))
				do_select(match);

			buf.clear();
		}
	}
}

void SerializeProfile(const ProfileRecord& record, mq::proto::login::ProfileMethod& profile);
void SerializeProfile(const ProfileRecord& record, mq::proto::login::DirectMethod& direct);

ProfileRecord ParseProfileFromMessage(const mq::proto::login::DirectMethod& direct);
ProfileRecord ParseProfileFromMessage(const mq::proto::login::ProfileMethod& profile);

template <typename Missive>
ProfileRecord ParseProfileFromMessage(const Missive& missive)
{
	switch (missive.method_case())
	{
	case mq::proto::login::StartInstanceMissive::MethodCase::kDirect:
		return ParseProfileFromMessage(missive.direct());

	case mq::proto::login::StartInstanceMissive::MethodCase::kProfile:
		return ParseProfileFromMessage(missive.profile());

	default:
		return {};
	}
}
