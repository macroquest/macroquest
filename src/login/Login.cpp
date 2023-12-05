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
#include <wil/registry.h>
#include <filesystem>
#include <regex>

#include <fmt/format.h>
#include <spdlog/spdlog.h>

#include "sqlite3.h"
#include "argon2.h"

#pragma comment(lib, "argon2")

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

// TODO: better encryption
std::string XorEncryptDecrypt(std::string_view str, std::string_view key)
{
	std::string out(str);

	auto mod_val = key.size() / sizeof(char);
	int i = 0;
	for (char& c : out)
	{
		c = c ^ key[++i % mod_val];
	}
}

// TODO: AutoLogin.cpp will pop up a dialog at startup if the registry key fails
// this will only try to read from the registry, and then validate against the master key hash
std::optional<std::string> GetMasterPass(sqlite3*& db, const std::filesystem::path& path)
{
	wil::unique_hkey pass_hkey;
	std::optional<DWORD> pass_timestamp;
	std::optional<std::wstring> pass;
	if (wil::reg::open_unique_key_nothrow(HKEY_CURRENT_USER, L"Software\\MacroQuest\\AutoLogin", pass_hkey, wil::reg::key_access::read) != S_OK || !pass_hkey)
	{
		SPDLOG_ERROR("AutoLogin Error failed to open registry key.");
	}
	else if (!(pass_timestamp = wil::reg::try_get_value_dword(pass_hkey.get(), L"MasterPassTimestamp")))
	{
		SPDLOG_ERROR("AutoLogin Error master pass is missing date.");
	}
	else if (*pass_timestamp + 720 > std::chrono::duration_cast<std::chrono::hours>(std::chrono::steady_clock::now().time_since_epoch()).count())
	{
		SPDLOG_ERROR("AutoLogin Error master pass has expired."); // 720 hours is 30 days
	}
	else if (!(pass = wil::reg::try_get_value_string(pass_hkey.get(), L"MasterPass")))
	{
		SPDLOG_ERROR("AutoLogin Error master pass is missing.");
	}
	else if (sqlite3_open_v2(path.string().c_str(), &db, SQLITE_OPEN_READONLY, nullptr) != SQLITE_OK)
	{
		SPDLOG_ERROR("AutoLogin Error opening login database: %s", sqlite3_errmsg(db));
		sqlite3_close(db);
		db = nullptr;
	}
	else
	{
		sqlite3_stmt* stmt;
		sqlite3_prepare_v2(db, R"(SELECT master_pass FROM login)", -1, &stmt, nullptr);

		if (sqlite3_step(stmt) == SQLITE_ROW)
		{
			// TODO: so many magic number, let's give these names
			uint8_t* stored_hash = (uint8_t*)sqlite3_column_blob(stmt, 0);
			if (sqlite3_column_bytes(stmt, 0) == 32)
			{
				std::string entered_pass(pass->begin(), pass->end());

				// TODO: what to salt with?
				const uint8_t salt[16] = { 0 };
				uint8_t entered_hash[32];
				argon2i_hash_raw(2, 1 << 16, 1, entered_pass.c_str(), entered_pass.length(), salt, 16, entered_hash, 32);

				if (std::equal(stored_hash, stored_hash + 32, entered_hash))
					return entered_pass;
			}
		}

		sqlite3_finalize(stmt);
	}

	return {};
}

std::vector<ProfileGroup> GetProfileGroups(sqlite3*& db, const std::filesystem::path& path)
{
	std::vector<ProfileGroup> profile_groups;
	std::optional<std::string> pass;
	if (sqlite3_open_v2(path.string().c_str(), &db, SQLITE_OPEN_READONLY, nullptr) != SQLITE_OK)
	{
		SPDLOG_ERROR("AutoLogin Error opening login database: %s", sqlite3_errmsg(db));
		sqlite3_close(db);
		db = nullptr;
	}
	else if (!(pass = GetMasterPass(db, path)))
	{
		SPDLOG_ERROR("AutoLogin Error failed to get password.");
	}
	else
	{
		sqlite3_stmt* groups_stmt;
		sqlite3_prepare_v2(db, R"(SELECT id, name, eq_path FROM profile_groups)", -1, &groups_stmt, nullptr);

		std::map<unsigned int, ProfileGroup> group_map;
		while (sqlite3_step(groups_stmt) == SQLITE_ROW)
		{
			auto id = (unsigned int)sqlite3_column_int(groups_stmt, 0);
			std::string name((const char*)sqlite3_column_text(groups_stmt, 1));

			// TODO: this is nullable, need to make it an optional
			std::string eq_path((const char*)sqlite3_column_text(groups_stmt, 2));

			group_map[id] = ProfileGroup{ name, eq_path, {} };
		}

		sqlite3_finalize(groups_stmt);

		for (auto& [id, group] : group_map)
		{
			sqlite3_stmt* stmt;
			sqlite3_prepare_v2(db, R"(
SELECT a.account, a.password, c.server, c.character, p.hotkey, p.selected, p.eq_path, l.class, l.level
FROM profiles p
JOIN characters c
ON p.character_id = c.id
JOIN accounts a
ON c.account = a.account
JOIN personas l
ON l.character_id = c.id
WHERE p.group_id = ?
			)", -1, &stmt, nullptr);

			sqlite3_bind_int(stmt, 1, id);

			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				std::string account((const char*)sqlite3_column_text(stmt, 0));
				std::string password(XorEncryptDecrypt((const char*)sqlite3_column_text(stmt, 1), *pass));

				std::string server((const char*)sqlite3_column_text(stmt, 2));
				std::string character((const char*)sqlite3_column_text(stmt, 3));

				std::string hotkey((const char*)sqlite3_column_text(stmt, 4));
				auto selected = (bool)sqlite3_column_int(stmt, 5);

				// TODO: this is nullable, need to make it optional
				std::string eq_path((const char*)sqlite3_column_text(stmt, 6));

				std::string cls((const char*)sqlite3_column_text(stmt, 7));
				auto level = sqlite3_column_int(stmt, 8);

				group.records.push_back(ProfileRecord{
					group.profileName,
					server,
					account,
					password,
					character,
					hotkey,
					cls,
					level,
					eq_path,
					selected
				});
			}

			sqlite3_finalize(stmt);
		}
	}

	if (db != nullptr) sqlite3_close(db);
	return profile_groups;
}

std::vector<ProfileGroup> InitDatabase(sqlite3*& db, const std::filesystem::path& path)
{
	if (sqlite3_open_v2(path.string().c_str(), &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, nullptr) != SQLITE_OK)
	{
		SPDLOG_ERROR("AutoLogin Error opening login database: %s", sqlite3_errmsg(db));
		sqlite3_close(db);
		db = nullptr;
	}
	else
	{
		char* err_msg = nullptr;
		auto err = [&err_msg, &db](std::string_view text)
			{
				SPDLOG_ERROR("%s: %s", text, err_msg);
				sqlite3_free(err_msg);
				sqlite3_close(db);
				db = nullptr;
			};

		// TODO: This uses a lot of foreign keys -- test if we need to enable them

		if (sqlite3_exec(db, R"(
CREATE TABLE IF NOT EXISTS login (
  master_pass blob not null -- just the hash, of course
  eq_path text
) WITHOUT ROWID;
		)", nullptr, nullptr, &err_msg) != SQLITE_OK)
			err("AutoLogin Error creating login master table");
		else if (sqlite3_exec(db, R"(
CREATE TABLE IF NOT EXISTS accounts (
  account text primary key,
  password blob not null -- this will be encrypted internally with master_pass as key
) WITHOUT ROWID;
		)", nullptr, nullptr, &err_msg) != SQLITE_OK)
			err("");
		else if (sqlite3_exec(db, R"(
CREATE TABLE IF NOT EXISTS characters (
  id integer primary key,
  character text not null,
  server text not null,
  account text not null,
  foreign key (account) references accounts(account) on delete cascade,
  unique (character, server)
) WITHOUT ROWID;
		)", nullptr, nullptr, &err_msg) != SQLITE_OK)
			err("");
		else if (sqlite3_exec(db, R"(
CREATE TABLE IF NOT EXISTS profile_groups (
  id integer primary key,
  name text not null,
  eq_path text,
  unique (name)
) WITHOUT ROWID;
		)", nullptr, nullptr, &err_msg) != SQLITE_OK)
			err("");
		else if (sqlite3_exec(db, R"(
CREATE TABLE IF NOT EXISTS profiles (
  character_id integer not null,
  group_id integer not null,
  eq_path text,
  hotkey text,
  selected integer not null, -- if the character is selected to login (boolean)
  foreign key (character_id) references characters(id) on delete cascade,
  foreign key (group_id) references profile_groups(id) on delete cascade
) WITHOUT ROWID;
		)", nullptr, nullptr, &err_msg) != SQLITE_OK)
			err("");
		else if (sqlite3_exec(db, R"(
CREATE TABLE IF NOT EXISTS personas (
  character_id integer not null,
  class text not null,
  level text not null,
  foreign key (character_id) references characters(id) on delete cascade
) WITHOUT ROWID;
		)", nullptr, nullptr, &err_msg) != SQLITE_OK)
			err("");
		else
		{
			return GetProfileGroups(db, path);
		}
	}

	if (db != nullptr) sqlite3_close(db);
	return {};
}

