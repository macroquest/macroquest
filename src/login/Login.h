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

#ifdef _DEBUG
#pragma comment(lib, "libprotobufd")
#else
#pragma comment(lib, "libprotobuf")
#endif

#pragma comment(lib, "login")

bool DecryptData(DATA_BLOB* DataIn, DATA_BLOB* DataOut);

struct ProfileRecord
{
	std::string profileName;
	std::string serverName;

	std::string accountName;
	std::string accountPassword;
	std::string characterName;

	std::string hotkey;
	std::string characterClass;
	int characterLevel = 0;
	bool checked = false;

	static ProfileRecord FromString(const std::string& input);
	static ProfileRecord FromBlob(const std::string& blob);
	static ProfileRecord FromINI(const std::string& profile, const std::string& blobKey, const std::string& iniFile);

	void FormatTo(char* buffer, size_t length) const;
};

struct ProfileGroup
{
	std::string profileName;
	std::vector<ProfileRecord> records;
};

std::vector<ProfileGroup> LoadAutoLoginProfiles(const std::string& szIniFileName);
