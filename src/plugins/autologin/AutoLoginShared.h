/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
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

// AutoLogin code shared between MacroQuest2.exe and MQ2AutoLogin.dll

#pragma once

#include "../../common/Common.h"

#include <Windows.h>
#include <wincrypt.h>

// This is a constant set of live server shortnames
const mq::ci_unordered::map<std::string_view, int> ServerData = {
	{ "rizlona",     169 },
	{ "lockjaw",     160 },
	{ "ragefire",    159 },
	{ "vox",         158 },
	{ "trakanon",    155 },
	{ "fippy",       156 },
	{ "vulak",       157 },
	{ "mayong",      163 },
	{ "antonius",    100 },
	{ "brekt",       162 },
	{ "bertox",      102 },
	{ "bristle",     104 },
	{ "cazic",       105 },
	{ "drinal",      106 },
	{ "erollisi",    109 },
	{ "firiona",     111 },
	{ "luclin",      116 },
	{ "povar",       123 },
	{ "rathe",       127 },
	{ "tunare",      140 },
	{ "xegony",      144 },
	{ "zek",         147 },
	{ "beta",        2   },
	{ "test",        1   }
};

bool DecryptData(DATA_BLOB* DataIn, DATA_BLOB* DataOut);

struct ProfileRecord
{
	std::string profileName;

	std::string accountName;
	std::string accountPassword;

	std::string serverName;
	std::string characterName;

	std::string hotkey;
	std::string characterClass;
	int characterLevel = 0;

	static ProfileRecord FromString(const std::string& input);
	static ProfileRecord FromBlob(const std::string& blob);
	static ProfileRecord FromINI(const std::string& profile, const std::string& blobKey, const std::string& iniFile);
};
