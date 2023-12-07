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

#include "Login.pb.h"

#include <Windows.h>
#include <wincrypt.h>

#include <optional>
#include <filesystem>

#ifdef _DEBUG
#pragma comment(lib, "libprotobufd")
#else
#pragma comment(lib, "libprotobuf")
#endif

#pragma comment(lib, "login")

bool DecryptData(DATA_BLOB* DataIn, DATA_BLOB* DataOut);

struct ProfileRecord
{
	std::string profileName; // this is the group of characters
	std::string serverName;

	std::string accountName;
	std::string accountPassword;
	std::string characterName;

	std::string hotkey;
	std::string characterClass;
	int characterLevel = 0;

	std::optional<std::string> eqPath;
	bool checked = false;

	static ProfileRecord FromString(const std::string& input);
	static ProfileRecord FromBlob(const std::string& blob);
	static ProfileRecord FromINI(const std::string& profile, const std::string& blobKey, const std::string& iniFile);

	void FormatTo(char* buffer, size_t length) const;
};

struct ProfileGroup
{
	std::string profileName;
	std::optional<std::string> eqPath;
	std::vector<ProfileRecord> records;
};

std::vector<ProfileGroup> LoadAutoLoginProfiles(const std::string& szIniFileName);

namespace login::db {
std::optional<std::string> GetMasterPass();
bool UpdateMasterPass(std::string_view pass);
std::string GetEQPath();
void UpdateEQPath(std::string_view path);

void CreateProfileGroup(const ProfileGroup& group);
std::optional<unsigned int> ReadProfileGroup(ProfileGroup& group);
void UpdateProfileGroup(std::string_view name, const ProfileGroup& group);
void DeleteProfileGroup(std::string_view name);

void CreateAccount(const ProfileRecord& profile);
std::optional<std::string> ReadAccount(ProfileRecord& profile);
void UpdateAccount(std::string_view account, const ProfileRecord& record);
void DeleteAccount(std::string_view account);

void CreateCharacter(const ProfileRecord& profile);
std::optional<unsigned int> ReadCharacter(ProfileRecord& profile);
void UpdateCharacter(std::string_view server, std::string_view name, const ProfileRecord& profile);
void DeleteCharacter(std::string_view server, std::string_view name);

void CreatePersona(const ProfileRecord& profile);
std::optional<unsigned int> ReadPersona(ProfileRecord& profile);
void UpdatePersona(std::string_view cls, const ProfileRecord& profile);
void DeletePersona(std::string_view server, std::string_view name, std::string_view cls);

void CreateProfile(const ProfileRecord& profile);
std::optional<unsigned int> ReadProfile(ProfileRecord& profile);
std::optional<unsigned int> ReadFullProfile(ProfileRecord& profile);
std::optional<unsigned int> ReadFullProfile(std::string_view group, std::string_view server, std::string_view name, ProfileRecord& profile);
void UpdateProfile(const ProfileRecord& profile);
void DeleteProfile(std::string_view server, std::string_view name, std::string_view group);

std::optional<std::string> GetEQPath(std::string_view group, std::string_view server, std::string_view name);
std::vector<ProfileGroup> GetProfileGroups();
std::vector<ProfileGroup> InitDatabase(const std::filesystem::path& path);
} // namespace login::db
