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

#pragma once

struct ProfileRecord;
struct LoginInstance
{
	uint32_t PID = 0;

	const std::string Server;
	const std::string Character;
	const std::string EQPath;

	std::optional<std::string> ProfileGroup;
	std::optional<std::string> Hotkey;

	static std::string Key(std::string_view Server, std::string_view Character);
	static std::string Key(const ProfileRecord& profile);
	[[nodiscard]] std::string Key() const { return Key(Server, Character); }

	void Update(uint32_t pid, const ProfileRecord& profile);

	LoginInstance(uint32_t pid, const ProfileRecord& profile);
};

// AutoLogin
void LoadCharacter(const ProfileRecord& profile);
void LoadProfileGroup(std::string_view group);
void LaunchCleanSession();
void ProcessPendingLogins();
void Import();
std::string GetEQRoot();
const std::unordered_map<std::string, LoginInstance>& GetLoadedInstances();

// ImGui
bool ShowPasswordWindow();
void InitializeAutoLoginImGui();
void ShutdownAutoLoginImGui();
