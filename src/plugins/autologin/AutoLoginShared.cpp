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
#include <regex>

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

ProfileRecord ProfileRecord::FromString(const std::string& input)
{
	// we can use regex here because this is not a time-critical process, and makes the
	// code easier to read

	// store our matches in here
	std::smatch matches;

	// the first method of username format is underscores
	// we expect here a format of `<profile>_<server>:<character>`
	std::regex blob_regex("(\\S+)_(\\w+):(\\S+)"); // TODO: do we need one of these for just server?
	// <server>^<account>^<character>^<password>
	std::regex plain_regex("(\\S+)\\^(\\S+)\\^(\\S+)\\^(\\S+)");
	// <server>^<account>^<password>
	std::regex plain2_regex("(\\S+)\\^(\\S+)\\^(\\S+)");
	// <server>;<profile>:<character>
	std::regex special_regex("(\\S+);(\\S+):(\\S+);");
	// <server>:<character>
	std::regex blob2_regex("(\\w+):(\\S+)");

	ProfileRecord record;

	if (std::regex_match(input, matches, blob_regex))
	{
		// <profile>_<server>:<character>
		record.profileName = matches[1].str();
		record.serverName = matches[2].str();
		record.characterName = matches[3].str();
	}
	else if (std::regex_match(input, matches, plain_regex))
	{
		// <server>^<stationname>^<charname>^<pass>
		record.profileName = "";
		record.serverName = matches[1].str();
		record.accountName = matches[2].str();
		record.characterName = matches[3].str();
		record.accountPassword = matches[4].str();
	}
	else if (std::regex_match(input, matches, plain2_regex))
	{
		// <server>^<stationname>^<pass>
		record.profileName = "";
		record.serverName = matches[1].str();
		record.accountName = matches[2].str();
		record.accountPassword = matches[3].str();
	}
	else if (std::regex_match(input, matches, special_regex))
	{
		// unsure why we need this option when the first option is exactly equivalent
		// <server>;<profile>:<character>;
		record.serverName = matches[1].str();
		record.profileName = matches[2].str();
		record.characterName = matches[3].str();
	}
	else if (std::regex_match(input, matches, blob2_regex))
	{
		record.serverName = matches[1].str();
		record.characterName = matches[2].str();
	}

	return record;
}

ProfileRecord ProfileRecord::FromBlob(const std::string& blob)
{
	ProfileRecord record;
	DATA_BLOB db, dbout;

	if (!blob.empty() && StrToBlob(blob.c_str(), &db))
	{
		if (DecryptData(&db, &dbout) && dbout.pbData != nullptr)
		{
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
		}

		LocalFree(db.pbData);
	}

	return record;
}

ProfileRecord ProfileRecord::FromINI(const std::string& profile, const std::string& blobKey, const std::string& iniFile)
{
	std::string blob = GetPrivateProfileString(profile, blobKey, "", iniFile);
	blob = split(blob, '=').at(0); // remove the "checked" status

	auto record = ProfileRecord::FromBlob(blob);
	record.profileName = profile;
	record.serverName = split(blobKey, ':').at(0); // <server>:<character>_Blob

	return record;
}
