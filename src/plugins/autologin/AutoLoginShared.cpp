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

#include "AutoLoginShared.h"

#include <commdlg.h>
#include <shellapi.h>
#include <tlhelp32.h>
#pragma comment(lib, "Crypt32.lib")

#include <wil/resource.h>
#include <filesystem>
#include <sstream>

#include <fmt/format.h>

using namespace mq;


bool DecryptData(DATA_BLOB* DataIn, DATA_BLOB* DataOut)
{
	return CryptUnprotectData(DataIn, nullptr, nullptr, nullptr, nullptr, 0, DataOut) != 0;
}

int StrToBlob(const std::string& stringIn, DATA_BLOB* BlobOut)
{
	std::string temp = stringIn;
	MakeLower(temp);

	uint8_t* pbData = (uint8_t*)LocalAlloc(LPTR, temp.length() + 1);
	size_t out = 0;

	for (int count = 0; temp[count]; count += 2, out++)
	{
		if (((temp[count] < '0' || temp[count] > '9')
			&& (temp[count] < 'a' || temp[count] > 'f'))
			|| ((temp[count + 1] < '0' || temp[count + 1] > '9')
				&& (temp[count + 1] < 'a' || temp[count + 1] > 'f')))
		{
			break;
		}

		uint8_t CurByte = 0;

		if (temp[count] >= '0' && temp[count] <= '9')
			CurByte = temp[count] - '0';
		else if (temp[count] >= 'a' && temp[count] <= 'f')
			CurByte = temp[count] - 87;

		CurByte <<= 4;

		if (temp[count + 1] >= '0' && temp[count + 1] <= '9')
			CurByte |= temp[count + 1] - '0';
		else if (temp[count + 1] >= 'a' && temp[count + 1] <= 'f')
			CurByte |= temp[count + 1] - 87;

		pbData[out] = CurByte;
	}
	pbData[out++] = 0;

	BlobOut->cbData = out;
	BlobOut->pbData = pbData;
	return BlobOut->cbData;
}

bool ParseBlob(const std::string& blob, ProfileRecord& record)
{
	if (blob.empty())
		return false;


	DATA_BLOB db;
	if (!StrToBlob(blob.c_str(), &db))
		return false;

	DATA_BLOB dbout;
	if (!DecryptData(&db, &dbout) || dbout.pbData == nullptr)
	{
		LocalFree(db.pbData);
		return false;
	}

	LocalFree(db.pbData);

	std::vector<std::string> tokens = split(reinterpret_cast<const char*>(dbout.pbData), ':');
	LocalFree(dbout.pbData);

	switch (tokens.size())
	{
	default:
	case 6:
		record.characterLevel = atoi(tokens[5].c_str());
	case 5:
		record.characterClass = tokens[4];
	case 4:
		record.hotkey = tokens[3];
	case 3:
		record.accountPassword = tokens[2];
	case 2:
		record.characterName = tokens[1];
	case 1:
		record.accountName = tokens[0];
	case 0:
		break;
	}

	return true;
}
