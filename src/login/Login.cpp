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

// AutoLogin code shared between MacroQuest.exe and MQ2AutoLogin.dll

#include "Login.h"

#include "common/Common.h"

#include <commdlg.h>
#include <shellapi.h>
#pragma comment(lib, "Crypt32.lib")

#include <wil/resource.h>
#include <filesystem>
#include <regex>

#include <fmt/format.h>

using namespace mq;
namespace fs = std::filesystem;

bool DecryptData(DATA_BLOB* DataIn, DATA_BLOB* DataOut)
{
	return CryptUnprotectData(DataIn, nullptr, nullptr, nullptr, nullptr, 0, DataOut) != 0;
}

int StrToBlob(const std::string& stringIn, DATA_BLOB* BlobOut)
{
	std::string temp = stringIn;
	MakeLower(temp);

	uint8_t* pbData = (uint8_t*)LocalAlloc(LPTR, temp.length() + 1);
	DWORD out = 0;

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
	static std::regex blob_regex("(\\S+)_([^:]+):(\\S+)"); // TODO: do we need one of these for just server?
	// <server>^<account>^<character>^<password>
	static std::regex plain_regex("([^\\^]+)\\^(\\S+)\\^(\\S+)\\^(\\S+)");
	// <server>^<account>^<password>
	static std::regex plain2_regex("([^\\^])\\^(\\S+)\\^(\\S+)");
	// <server>;<profile>:<character>
	static std::regex special_regex("([^;]);(\\S+):(\\S+);");
	// <server>:<character>
	static std::regex blob2_regex("([^:]):(\\S+)");

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
	if (!blob.empty())
		blob = split(blob, '=').at(0); // remove the "checked" status

	auto record = ProfileRecord::FromBlob(blob);
	record.profileName = profile;
	record.serverName = split(blobKey, ':').at(0); // <server>:<character>_Blob

	return record;
}

std::vector<ProfileGroup> LoadAutoLoginProfiles(const std::string& szIniFileName)
{
	std::error_code ec;

	if (!fs::exists(szIniFileName, ec))
		return {};

	int NumProfiles = GetPrivateProfileInt("Profiles", "NumProfiles", 0, szIniFileName);
	if (NumProfiles <= 0)
		return {};

	std::vector<ProfileGroup> profiles;

	for (int i = 0; i < NumProfiles; i++)
	{
		std::string sectionName = GetPrivateProfileString("Profiles", fmt::format("Profile{:d}", i + 1), "", szIniFileName);
		if (sectionName.empty())
			continue;

		ProfileGroup profileGroup;
		profileGroup.profileName = sectionName;

		// Get list of keys for this profile
		std::vector<std::string> keyNames = GetPrivateProfileKeys(sectionName, szIniFileName);
		for (const auto& section : keyNames)
		{
			// FIXME: Use RawProfileRecord & ReadBlob
			if (section.find("_Blob") == std::string::npos)
				continue;

			std::string blob = GetPrivateProfileString(sectionName, section, "", szIniFileName);
			if (blob.empty())
				continue;

			// the blob has an =0 or =1 appended at the end.
			bool checked = true;
			size_t pos = blob.find("=");
			if (pos != std::string::npos)
			{
				checked = blob.substr(pos + 1) != "0";
				blob = blob.substr(0, pos);
			}

			ProfileRecord record = ProfileRecord::FromBlob(blob);
			record.profileName = sectionName;
			record.checked = checked;

			// the key name is split into server:character_Blob
			size_t pos2 = section.find(":");
			if (pos2 != std::string::npos)
			{
				record.serverName = section.substr(0, pos2);
			}

			profileGroup.records.push_back(std::move(record));
		}

		if (!profileGroup.records.empty())
			profiles.push_back(std::move(profileGroup));
	}

	return profiles;
}

void ProfileRecord::FormatTo(char* buffer, size_t length) const
{
	fmt::format_to_n_result<char*> result;

	if (!characterClass.empty())
		result = fmt::format_to_n(buffer, length - 1, "[{}] {}->{} [{:d} {}]", accountName, serverName,
			characterName, characterLevel, characterClass);
	else
		result = fmt::format_to_n(buffer, length - 1, "[{}] {}->{}", accountName, serverName, characterName);

	*result.out = 0;
}
