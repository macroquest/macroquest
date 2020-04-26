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
};

// TODO: add a version 2 of this parser that will also fill in the server name (and move this into the record itself as a constructor)
bool ParseBlob(const std::string& blob, ProfileRecord& record);
