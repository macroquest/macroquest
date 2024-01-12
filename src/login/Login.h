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

// TODO:
//	master pass should be stored in launcher and gotten via a message
//		reset message when new pass is entered
//		can store locally once retrieved
//		only the launcher should be retrieving it from the registry/db
//		allow people to just get pass from the registry easily (it doesn't need to be _that_ secure)

namespace login::db {
bool ValidatePass(std::string_view pass, bool empty_is_valid);

void MemoizeMasterPass(std::string_view pass);
std::optional<std::string> GetMasterPass();

bool CreateMasterPass(std::string_view pass);
std::optional<std::string> ReadMasterPass();

void WriteSetting(std::string_view key, std::string_view value, std::optional<std::string_view> description = {});
std::optional<std::string> ReadSetting(std::string_view key);

void CreateEQPath(std::string_view path);
std::string ReadEQPath();

std::vector<std::string> ListProfileGroups();
void CreateProfileGroup(const ProfileGroup& group);
std::optional<unsigned int> ReadProfileGroup(ProfileGroup& group);
void UpdateProfileGroup(std::string_view name, const ProfileGroup& group);
void DeleteProfileGroup(std::string_view name);

std::vector<std::string> ListAccounts();
void CreateAccount(const ProfileRecord& profile);
std::optional<std::string> ReadAccount(ProfileRecord& profile);
void UpdateAccount(std::string_view account, const ProfileRecord& record);
void DeleteAccount(std::string_view account);

std::vector<std::pair<std::string, std::string>> ListCharacters(std::string_view account);
std::vector<ProfileRecord> ListCharacterMatches(std::string_view search);
void CreateCharacter(const ProfileRecord& profile);
std::optional<unsigned int> ReadCharacter(ProfileRecord& profile);
void UpdateCharacter(std::string_view server, std::string_view name, const ProfileRecord& profile);
void DeleteCharacter(std::string_view server, std::string_view name);

void CreatePersona(const ProfileRecord& profile);
std::optional<unsigned int> ReadPersona(ProfileRecord& profile);
void UpdatePersona(std::string_view cls, const ProfileRecord& profile);
void DeletePersona(std::string_view server, std::string_view name, std::string_view cls);

std::vector<ProfileRecord> GetProfiles(std::string_view group);
void CreateProfile(const ProfileRecord& profile);
std::optional<unsigned int> ReadProfile(ProfileRecord& profile);
std::optional<unsigned int> ReadFullProfile(ProfileRecord& profile);
std::optional<unsigned int> ReadFullProfile(std::string_view group, std::string_view server, std::string_view name, ProfileRecord& profile);
void UpdateProfile(const ProfileRecord& profile);
void DeleteProfile(std::string_view server, std::string_view name, std::string_view group);

std::string GetEQPath(std::string_view group, std::string_view server, std::string_view name);
std::vector<ProfileGroup> GetProfileGroups();
void WriteProfileGroups(const std::vector<ProfileGroup>& groups);
bool InitDatabase(const std::string& path);
} // namespace login::db
