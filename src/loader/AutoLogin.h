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

// AutoLogin
void LoadCharacter(const LoginInstance& instance_template);
void LoadProfileGroup(std::string_view group);
void LaunchCleanSession();
void Import();
std::string GetEQRoot();

// ImGui
void ShowAutoLoginWindow();
void ShowAutoLoginMenu();
bool ShowPasswordWindow();
void InitializeAutoLoginImGui();
void ShutdownAutoLoginImGui();
