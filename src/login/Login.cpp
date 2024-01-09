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
#include <codecvt>
#include <random>

#include <fmt/format.h>
#include <spdlog/spdlog.h>

#include "sqlite3.h"
#pragma comment(lib, "sqlite3")

#include "argon2.h"
#pragma comment(lib, "argon2")

std::string s_dbPath;

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

class WithDb
{
public:
	WithDb(int flags)
	{
		if (sqlite3_open_v2(s_dbPath.c_str(), &m_db, flags, nullptr) != SQLITE_OK)
		{
			SPDLOG_ERROR("AutoLogin Error failed to open database %s: %s", s_dbPath, sqlite3_errmsg(m_db));
			sqlite3_close(m_db);
			m_db = nullptr;
		}
	}

	~WithDb()
	{
		if (m_db != nullptr) sqlite3_close(m_db);
	}

	template <typename T>
	static std::function<T(const std::string&, const std::function<T(sqlite3_stmt*, sqlite3*)>&)> Query(int flags)
	{
		return [flags](const std::string& query, const std::function<T(sqlite3_stmt*, sqlite3*)>& action)
			{
				auto connection = Get(flags);
				return WithStatement<T>(connection->m_db, query)(action);
			};
	}

private:
	static const std::shared_ptr<WithDb>& Get(int flags)
	{
		static std::map<int, std::shared_ptr<WithDb>> connections;

		auto [connection, _] = connections.try_emplace(flags, std::move(std::make_shared<WithDb>(flags)));

		return connection->second;
	}

	template <typename T>
	class WithStatement
	{
	public:
		WithStatement(sqlite3* db, const std::string& query) : m_db(db), m_stmt(nullptr)
		{
			sqlite3_prepare_v2(m_db, query.c_str(), -1, &m_stmt, nullptr);
		}

		~WithStatement()
		{
			sqlite3_finalize(m_stmt);
		}

		T operator()(const std::function<T(sqlite3_stmt*, sqlite3*)>& action)
		{
			return action(m_stmt, m_db);
		}

	private:
		sqlite3* m_db;
		sqlite3_stmt* m_stmt;
	};

	sqlite3* m_db = nullptr;
};

// TODO: better encryption
static std::string XorEncryptDecrypt(std::string_view str, std::string_view key)
{
	std::string out(str);

	auto mod_val = key.size() / sizeof(char);
	int i = 0;
	for (char& c : out)
	{
		c = c ^ key[++i % mod_val];
	}

	return out;
}

// TODO: tweak these default params with testing
struct HashParams
{
	size_t SaltLength = 16;
	size_t HashLength = 32;
	uint32_t TimeCost = 4;
	uint32_t MemoryCost = 1 << 4;
	uint32_t Parallelism = 1;
};

bool login::db::ValidatePass(std::string_view pass, bool empty_is_valid)
{
	auto hash = WithDb::Query<std::optional<std::string>>(SQLITE_OPEN_READONLY)(
		R"(SELECT value FROM settings WHERE key = 'master_pass')",
		[](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<std::string>
		{
			auto result = sqlite3_step(stmt);
			if (result == SQLITE_ROW)
				return (const char*)sqlite3_column_text(stmt, 0);

			if (result != SQLITE_DONE)
				SPDLOG_ERROR("AutoLogin Error failed to read master pass: {}", sqlite3_errmsg(db));

			return {};
		});

	if (empty_is_valid)
		return !hash || argon2id_verify(hash->c_str(), pass.data(), pass.length()) == ARGON2_OK;

	return hash && argon2id_verify(hash->c_str(), pass.data(), pass.length()) == ARGON2_OK;
}

std::optional<std::string> s_masterPass;
void login::db::MemoizeMasterPass(std::string_view pass)
{
	s_masterPass = pass;
}

std::optional<std::string> login::db::GetMasterPass()
{
	return s_masterPass;
}

bool login::db::CreateMasterPass(std::string_view pass)
{
	// first update the db with the new pass
	auto db = WithDb::Query<std::optional<std::string>>(SQLITE_OPEN_READWRITE);
	auto get_setting = [&db](std::string_view setting)
		{
			return db(
				fmt::format("SELECT value FROM settings WHERE key = '{}'", setting),
				[](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<std::string>
				{
					if (sqlite3_step(stmt) == SQLITE_ROW)
						return (const char*)sqlite3_column_text(stmt, 0);

					return {};
				}
			);
		};

	HashParams hash_params;
	if (auto val = get_setting("time_cost"))
		hash_params.TimeCost = GetIntFromString(*val, hash_params.TimeCost);

	if (auto val = get_setting("memory_cost"))
		hash_params.MemoryCost = GetIntFromString(*val, hash_params.MemoryCost);

	if (auto val = get_setting("paralellism"))
		hash_params.Parallelism = GetIntFromString(*val, hash_params.Parallelism);

	if (auto val = get_setting("salt_len"))
		hash_params.SaltLength = GetIntFromString(*val, static_cast<int>(hash_params.SaltLength));

	if (auto val = get_setting("hash_len"))
		hash_params.HashLength = GetIntFromString(*val, static_cast<int>(hash_params.HashLength));

	auto update = [pass, &hash_params](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<std::string>
		{
			std::mt19937 generator{std::random_device{}()};
			std::uniform_int_distribution<unsigned char> distribution{'!', '~'};
			std::string salt(hash_params.SaltLength, '\0');
			for (auto& c : salt)
				c = distribution(generator);

			std::string encoded(argon2_encodedlen(
				hash_params.TimeCost,
				hash_params.MemoryCost,
				hash_params.Parallelism,
				static_cast<uint32_t>(hash_params.SaltLength),
				static_cast<uint32_t>(hash_params.HashLength),
				argon2_type::Argon2_id), '\0');

			auto argon2_err = argon2id_hash_encoded(
				hash_params.TimeCost,
				hash_params.MemoryCost,
				hash_params.Parallelism,
				pass.data(),
				pass.length(),
				salt.c_str(),
				hash_params.SaltLength,
				hash_params.HashLength,
				&encoded[0],
				encoded.length());

			if (argon2_err == ARGON2_OK)
			{
				sqlite3_bind_text(stmt, 1, encoded.c_str(), static_cast<int>(encoded.length()), SQLITE_STATIC);
				if (sqlite3_step(stmt) != SQLITE_DONE)
					SPDLOG_ERROR("AutoLogin Error failed to store master pass: {}", sqlite3_errmsg(db));
			}
			else
			{
				SPDLOG_ERROR("AutoLogin Error failed to hash master pass: {}", argon2_error_message(argon2_err));
			}

			return {};
		};

	db(R"(
		INSERT INTO settings (key, value, description) VALUES('master_pass', ?, 'Encoded hash of the user''s master password.')
		ON CONFLICT (key) DO UPDATE SET value=excluded.value, description=excluded.description)", update);

	// then update the registry
	wil::unique_hkey pass_hkey;
	if (wil::reg::create_unique_key_nothrow(HKEY_CURRENT_USER, L"Software\\MacroQuest\\AutoLogin", pass_hkey, wil::reg::key_access::readwrite) == S_OK && pass_hkey)
	{
		// if we can't create or open the key, then we can't really do anything, but we can always just ask for the pass again
		// the timestamp is in hours since epoch
		wil::reg::set_value_dword_nothrow(pass_hkey.get(), L"MasterPassTimestamp", std::chrono::duration_cast<std::chrono::hours>(std::chrono::system_clock::now().time_since_epoch()).count());

		// the string must be converted to a wide string for the registry
		std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> cvt;
		std::wstring wide_pass(cvt.from_bytes(pass.data(), pass.data() + pass.length()));
		wil::reg::set_value_string_nothrow(pass_hkey.get(), L"MasterPass", wide_pass.c_str());
	}

	return true;
}

// this will only try to read from the registry, and then validate against the master key hash
std::optional<std::string> login::db::ReadMasterPass()
{
	wil::unique_hkey pass_hkey;
	std::optional<DWORD> pass_timestamp;
	std::optional<std::wstring> pass; // this must be a wstring, that's the only way to store strings in the registry

	if (wil::reg::open_unique_key_nothrow(HKEY_CURRENT_USER, L"Software\\MacroQuest\\AutoLogin", pass_hkey, wil::reg::key_access::read) != S_OK || !pass_hkey)
	{
		SPDLOG_ERROR("AutoLogin Error failed to open registry key.");
	}
	else if (!(pass = wil::reg::try_get_value_string(pass_hkey.get(), L"MasterPass")))
	{
		SPDLOG_ERROR("AutoLogin Error master pass is missing from registry.");
	}
	else if (!(pass_timestamp = wil::reg::try_get_value_dword(pass_hkey.get(), L"MasterPassTimestamp")))
	{
		SPDLOG_ERROR("AutoLogin Error master pass is missing date.");
	}
	else if (static_cast<int>(*pass_timestamp) + 720 < std::chrono::duration_cast<std::chrono::hours>(std::chrono::system_clock::now().time_since_epoch()).count())
	{
		SPDLOG_ERROR("AutoLogin Error master pass has expired."); // 720 hours is 30 days
	}
	else
	{
		// we have a stored hash to compare against
		std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> cvt;
		std::string entered_pass(cvt.to_bytes(pass->c_str()));
		if (ValidatePass(entered_pass, false))
			return entered_pass;

		SPDLOG_ERROR("AutoLogin Error master pass hash does not match.");
	}

	return {};
}

void login::db::CreateEQPath(std::string_view path)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(
			INSERT INTO SETTINGS (key, value, description) VALUES('eq_path', ?, 'Default EQ path')
			ON CONFLICT (key) DO UPDATE SET value=excluded.value, description=excluded.description)",
		[path](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, path.data(), static_cast<int>(path.length()), SQLITE_STATIC);
			sqlite3_step(stmt);
		});
}

std::string login::db::ReadEQPath()
{
	return WithDb::Query<std::string>(SQLITE_OPEN_READONLY)(
		R"(SELECT value FROM settings WHERE key = 'eq_path')",
		[](sqlite3_stmt* stmt, sqlite3* db) -> std::string
		{
			if (sqlite3_step(stmt) == SQLITE_ROW)
				return (const char*)sqlite3_column_text(stmt, 0);

			return "";
		});
}

// ================================================================================================================================
// profile_groups
std::vector<std::string> login::db::ListProfileGroups()
{
	return WithDb::Query<std::vector<std::string>>(SQLITE_OPEN_READONLY)(
		R"(SELECT name FROM profile_groups)",
		[](sqlite3_stmt* stmt, sqlite3* db)
		{
			std::vector<std::string> groups;
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				groups.push_back((const char*)sqlite3_column_text(stmt, 0));
			}

			return groups;
		});
}
void login::db::CreateProfileGroup(const ProfileGroup& group)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(
			INSERT INTO profile_groups (name, eq_path) VALUES(?, ?)
			ON CONFLICT(name) DO UPDATE SET eq_path=excluded.eq_path)",
		[&group](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, group.profileName.c_str(), static_cast<int>(group.profileName.length()), SQLITE_STATIC);

			if (group.eqPath)
				sqlite3_bind_text(stmt, 2, group.eqPath->c_str(), static_cast<int>(group.eqPath->length()), SQLITE_STATIC);
			else
				sqlite3_bind_null(stmt, 2);

			sqlite3_step(stmt);
		}
	);
}

std::optional<unsigned int> login::db::ReadProfileGroup(ProfileGroup& group)
{
	return WithDb::Query<std::optional<unsigned int>>(SQLITE_OPEN_READONLY)(
		R"(SELECT id, eq_path FROM profile_groups WHERE name = ?)",
		[&group](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<unsigned int>
		{
			sqlite3_bind_text(stmt, 1, group.profileName.c_str(), static_cast<int>(group.profileName.length()), SQLITE_STATIC);

			if (sqlite3_step(stmt) == SQLITE_ROW)
			{
				if (sqlite3_column_type(stmt, 1) == SQLITE_TEXT)
					group.eqPath = (const char*)sqlite3_column_text(stmt, 1);

				return (unsigned int)sqlite3_column_int(stmt, 0);
			}

			SPDLOG_ERROR("AutoLogin Error failed to load profile group {}: {}", group.profileName, sqlite3_errmsg(db));
			return {};
		});
}

void login::db::UpdateProfileGroup(std::string_view name, const ProfileGroup& group)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(
			UPDATE OR REPLACE profile_groups
			SET name    = ?,
			    eq_path = ?
			WHERE name  = ?)",
		[name, &group](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, group.profileName.c_str(), static_cast<int>(group.profileName.length()), SQLITE_STATIC);

			if (group.eqPath)
				sqlite3_bind_text(stmt, 2, group.eqPath->c_str(), static_cast<int>(group.eqPath->length()), SQLITE_STATIC);
			else
				sqlite3_bind_null(stmt, 2);

			sqlite3_bind_text(stmt, 3, name.data(), static_cast<int>(name.length()), SQLITE_STATIC);

			sqlite3_step(stmt);
		}
	);
}

void login::db::DeleteProfileGroup(std::string_view name)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(DELETE FROM profile_groups WHERE name = ?)",
		[name](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, name.data(), static_cast<int>(name.length()), SQLITE_STATIC);

			sqlite3_step(stmt);
		}
	);
}
// ================================================================================================================================

// ================================================================================================================================
// accounts
std::vector<std::string> login::db::ListAccounts()
{
	return WithDb::Query<std::vector<std::string>>(SQLITE_OPEN_READONLY)(
		R"(SELECT account FROM accounts)",
		[](sqlite3_stmt* stmt, sqlite3* db) -> std::vector<std::string>
		{
			std::vector<std::string> accounts;
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				accounts.push_back((const char*)sqlite3_column_text(stmt, 0));
			}

			return accounts;
		});
}

void login::db::CreateAccount(const ProfileRecord& profile)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(
			INSERT INTO accounts (account, password) VALUES (?, ?)
			ON CONFLICT (account) DO UPDATE SET password=excluded.password)",
		[&profile](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, profile.accountName.c_str(), static_cast<int>(profile.accountName.length()), SQLITE_STATIC);

			std::string encrypted_pass;
			if (auto master_pass = GetMasterPass())
			{
				encrypted_pass = XorEncryptDecrypt(profile.accountPassword, *master_pass);
				sqlite3_bind_text(stmt, 2, encrypted_pass.c_str(), static_cast<int>(encrypted_pass.length()), SQLITE_STATIC);
			}
			else
			{
				sqlite3_bind_null(stmt, 2);
			}

			sqlite3_step(stmt);
		});
}

std::optional<std::string> login::db::ReadAccount(ProfileRecord& profile)
{
	if (profile.accountName.empty())
	{
		return WithDb::Query<std::optional<std::string>>(SQLITE_OPEN_READONLY)(
			R"(
				SELECT account, password
				FROM accounts
				JOIN characters USING (account)
				WHERE server = ? AND character = ?)",
			[&profile](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<std::string>
			{
				sqlite3_bind_text(stmt, 1, profile.serverName.c_str(), static_cast<int>(profile.serverName.length()), SQLITE_STATIC);
				sqlite3_bind_text(stmt, 2, profile.characterName.c_str(), static_cast<int>(profile.characterName.length()), SQLITE_STATIC);

				profile.accountName = (const char*)sqlite3_column_text(stmt, 0);

				auto master_pass = GetMasterPass();
				if (master_pass && sqlite3_step(stmt) == SQLITE_ROW && sqlite3_column_type(stmt, 1) == SQLITE_TEXT)
				{
					std::string pass((const char*)sqlite3_column_text(stmt, 1), sqlite3_column_bytes(stmt, 1));
					pass = XorEncryptDecrypt(pass, *master_pass);
					profile.accountPassword = pass;
					return pass;
				}

				SPDLOG_ERROR("AutoLogin Error failed to load account {}: {}", profile.accountName, sqlite3_errmsg(db));
				return {};
			});
	}

	return WithDb::Query<std::optional<std::string>>(SQLITE_OPEN_READONLY)(
		R"(SELECT password FROM accounts WHERE account = ?)",
		[&profile](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<std::string>
		{
			sqlite3_bind_text(stmt, 1, profile.accountName.c_str(), static_cast<int>(profile.accountName.length()), SQLITE_STATIC);

			auto master_pass = GetMasterPass();
			if (master_pass && sqlite3_step(stmt) == SQLITE_ROW && sqlite3_column_type(stmt, 0) == SQLITE_TEXT)
			{
				std::string pass((const char*)sqlite3_column_text(stmt, 0), sqlite3_column_bytes(stmt, 0));
				pass = XorEncryptDecrypt(pass, *master_pass);
				profile.accountPassword = pass;
				return pass;
			}

			SPDLOG_ERROR("AutoLogin Error failed to load account {}: {}", profile.accountName, sqlite3_errmsg(db));
			return {};
		});
}

void login::db::UpdateAccount(std::string_view account, const ProfileRecord& record)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(
			UPDATE OR REPLACE accounts
			SET account = ?,
			    password = ?
			WHERE account = ?)",
		[account, &record](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, record.accountName.c_str(), static_cast<int>(record.accountName.length()), SQLITE_STATIC);

			std::string encrypted_pass;
			if (auto master_pass = GetMasterPass())
			{
				encrypted_pass = XorEncryptDecrypt(record.accountPassword, *master_pass);
				sqlite3_bind_text(stmt, 2, encrypted_pass.c_str(), static_cast<int>(encrypted_pass.length()), SQLITE_STATIC);
			}
			else
			{
				sqlite3_bind_null(stmt, 2);
			}

			sqlite3_bind_text(stmt, 3, account.data(), static_cast<int>(account.length()), SQLITE_STATIC);

			sqlite3_step(stmt);
		});
}

void login::db::DeleteAccount(std::string_view account)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(DELETE FROM accounts WHERE account = ?)",
		[account](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, account.data(), static_cast<int>(account.length()), SQLITE_STATIC);
			sqlite3_step(stmt);
		});
}
// ================================================================================================================================

// ================================================================================================================================
// characters
std::vector<std::pair<std::string, std::string>> login::db::ListCharacters(std::string_view account)
{
	return WithDb::Query<std::vector<std::pair<std::string, std::string>>>(SQLITE_OPEN_READONLY)(
		R"(SELECT server, character FROM characters WHERE account = ?)",
		[account](sqlite3_stmt* stmt, sqlite3* db) -> std::vector<std::pair<std::string, std::string>>
		{
			sqlite3_bind_text(stmt, 1, account.data(), static_cast<int>(account.length()), SQLITE_STATIC);

			std::vector<std::pair<std::string, std::string>> characters;
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				characters.push_back(std::make_pair(
					(const char*)sqlite3_column_text(stmt, 0),
					(const char*)sqlite3_column_text(stmt, 1)
				));
			}

			return characters;
		});
}

void login::db::CreateCharacter(const ProfileRecord& profile)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(
			INSERT INTO characters (character, server, account) VALUES(?, ?, ?)
			ON CONFLICT(character, server) DO UPDATE SET account=excluded.account)",
		[&profile](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, profile.characterName.c_str(), static_cast<int>(profile.characterName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, profile.serverName.c_str(), static_cast<int>(profile.serverName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 3, profile.accountName.c_str(), static_cast<int>(profile.accountName.length()), SQLITE_STATIC);

			sqlite3_step(stmt);
		});
}

std::optional<unsigned int> login::db::ReadCharacter(ProfileRecord& profile)
{
	return WithDb::Query<std::optional<unsigned int>>(SQLITE_OPEN_READONLY)(
		R"(
			SELECT id, account
			FROM characters
			WHERE character = ? AND server = ?)",
		[&profile](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<unsigned int>
		{
			sqlite3_bind_text(stmt, 1, profile.characterName.c_str(), static_cast<int>(profile.characterName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, profile.serverName.c_str(), static_cast<int>(profile.serverName.length()), SQLITE_STATIC);

			if (sqlite3_step(stmt) == SQLITE_ROW)
			{
				profile.accountName = (const char*)sqlite3_column_text(stmt, 1);
				return (unsigned int)sqlite3_column_int(stmt, 0);
			}

			SPDLOG_ERROR("AutoLogin Error failed to load server {} and character {}: {}", profile.serverName, profile.characterName, sqlite3_errmsg(db));
			return {};
		});
}

void login::db::UpdateCharacter(std::string_view server, std::string_view name, const ProfileRecord& profile)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(
			UPDATE OR REPLACE characters
			SET character = ?,
			    server = ?,
			    account = ?
			WHERE character = ? AND server = ?)",
		[server, name, &profile](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, profile.characterName.c_str(), static_cast<int>(profile.characterName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, profile.serverName.c_str(), static_cast<int>(profile.serverName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 3, profile.accountName.c_str(), static_cast<int>(profile.accountName.length()), SQLITE_STATIC);

			sqlite3_bind_text(stmt, 4, name.data(), static_cast<int>(name.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 5, server.data(), static_cast<int>(server.length()), SQLITE_STATIC);

			sqlite3_step(stmt);
		});
}

void login::db::DeleteCharacter(std::string_view server, std::string_view name)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(DELETE FROM characters WHERE character = ? AND server = ?)",
		[server, name](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, name.data(), static_cast<int>(name.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, server.data(), static_cast<int>(server.length()), SQLITE_STATIC);

			sqlite3_step(stmt);
		});
}
// ================================================================================================================================

// ================================================================================================================================
// personas
void login::db::CreatePersona(const ProfileRecord& profile)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(
			INSERT INTO personas (character_id, class, level) VALUES ((SELECT id FROM characters WHERE server = ? AND character = ?), ?, ?)
			ON CONFLICT (character_id, class) DO UPDATE SET level=excluded.level)",
		[&profile](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, profile.serverName.c_str(), static_cast<int>(profile.serverName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, profile.characterName.c_str(), static_cast<int>(profile.characterName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 3, profile.characterClass.c_str(), static_cast<int>(profile.characterClass.length()), SQLITE_STATIC);
			sqlite3_bind_int(stmt, 4, profile.characterLevel);

			sqlite3_step(stmt);
		});
}

std::optional<unsigned int> login::db::ReadPersona(ProfileRecord& profile)
{
	return WithDb::Query<std::optional<unsigned int>>(SQLITE_OPEN_READONLY)(
		R"(
			SELECT p.id, level
			FROM personas p
			JOIN characters c ON p.character_id = c.id
			WHERE server = ? AND character = ? AND class = ?)",
		[&profile](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<unsigned int>
		{
			sqlite3_bind_text(stmt, 1, profile.serverName.c_str(), static_cast<int>(profile.serverName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, profile.characterName.c_str(), static_cast<int>(profile.characterName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 3, profile.characterClass.c_str(), static_cast<int>(profile.characterClass.length()), SQLITE_STATIC);

			if (sqlite3_step(stmt) == SQLITE_ROW)
			{
				profile.characterLevel = sqlite3_column_int(stmt, 1);
				return (unsigned int)sqlite3_column_int(stmt, 0);
			}

			// this is a warning because persona isn't strictly required
			SPDLOG_WARN("AutoLogin Error failed to load persona {}, server {}, character {}: {}", profile.characterClass, profile.serverName, profile.characterName, sqlite3_errmsg(db));
			return {};
		});
}

void login::db::UpdatePersona(std::string_view cls, const ProfileRecord& profile)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(
			UPDATE OR REPLACE personas
			SET class = ?,
			    level = ?
			WHERE character_id IN (SELECT id FROM characters WHERE server = ? AND character = ?) AND class = ?)",
		[cls, &profile](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, profile.characterClass.c_str(), static_cast<int>(profile.characterClass.length()), SQLITE_STATIC);
			sqlite3_bind_int(stmt, 2, profile.characterLevel);
			sqlite3_bind_text(stmt, 3, profile.serverName.c_str(), static_cast<int>(profile.serverName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 4, profile.characterName.c_str(), static_cast<int>(profile.characterName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 5, cls.data(), static_cast<int>(cls.length()), SQLITE_STATIC);

			sqlite3_step(stmt);
		});
}

void login::db::DeletePersona(std::string_view server, std::string_view name, std::string_view cls)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(
			DELETE FROM personas
			WHERE character_id IN (SELECT id FROM characters WHERE server = ? AND character = ?) AND class = ?)",
		[server, name, cls](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, server.data(), static_cast<int>(server.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, name.data(), static_cast<int>(name.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 3, cls.data(), static_cast<int>(cls.length()), SQLITE_STATIC);

			sqlite3_step(stmt);
		});
}
// ================================================================================================================================

// ================================================================================================================================
// profiles
std::vector<ProfileRecord> login::db::GetProfiles(std::string_view group)
{
	// TODO: personas or characters should have a "current persona" -- this will currently return multiple entries for the same character
	return WithDb::Query<std::vector<ProfileRecord>>(SQLITE_OPEN_READONLY)(
		R"(
			SELECT hotkey, character, server, class, level, account, selected, eq_path
			FROM profiles
			JOIN (SELECT id AS character_id, character, server, account FROM characters) USING (character_id)
			JOIN (SELECT id AS group_id FROM profile_groups WHERE name = ?) USING (group_id)
			LEFT JOIN (SELECT character_id, class, level FROM personas) USING (character_id))",
		[group](sqlite3_stmt* stmt, sqlite3* db)
		{
			std::vector<ProfileRecord> records;
			sqlite3_bind_text(stmt, 1, group.data(), static_cast<int>(group.length()), SQLITE_STATIC);

			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				ProfileRecord record;
				if (sqlite3_column_type(stmt, 0) != SQLITE_NULL)
					record.hotkey = (const char*)sqlite3_column_text(stmt, 0);

				record.characterName = (const char*)sqlite3_column_text(stmt, 1);
				record.serverName = (const char*)sqlite3_column_text(stmt, 2);

				if (sqlite3_column_type(stmt, 3) != SQLITE_NULL)
					record.characterClass = (const char*)sqlite3_column_text(stmt, 3);
				if (sqlite3_column_type(stmt, 4) != SQLITE_NULL)
					record.characterLevel = sqlite3_column_int(stmt, 4);

				record.accountName = (const char*)sqlite3_column_text(stmt, 5);

				if (sqlite3_column_type(stmt, 6) != SQLITE_NULL)
					record.checked = sqlite3_column_int(stmt, 6) != 0;

				if (sqlite3_column_type(stmt, 7) != SQLITE_NULL)
					record.eqPath = (const char*)sqlite3_column_text(stmt, 7);

				record.profileName = group;

				records.push_back(std::move(record));
			}

			return records;
		});
}

void login::db::CreateProfile(const ProfileRecord& profile)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(
			INSERT INTO profiles (character_id, group_id, eq_path, hotkey, selected)
			VALUES((SELECT id FROM characters WHERE server = ? AND character = ?), (SELECT id FROM profile_groups WHERE name = ?), ?, ?, ?)
			ON CONFLICT(character_id, group_id) DO UPDATE SET eq_path=excluded.eq_path, hotkey=excluded.hotkey, selected=excluded.selected)",
		[&profile](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, profile.serverName.c_str(), static_cast<int>(profile.serverName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, profile.characterName.c_str(), static_cast<int>(profile.characterName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 3, profile.profileName.c_str(), static_cast<int>(profile.profileName.length()), SQLITE_STATIC);

			if (profile.eqPath)
				sqlite3_bind_text(stmt, 4, profile.eqPath->c_str(), static_cast<int>(profile.eqPath->length()), SQLITE_STATIC);
			else
				sqlite3_bind_null(stmt, 4);

			sqlite3_bind_text(stmt, 5, profile.hotkey.c_str(), static_cast<int>(profile.hotkey.length()), SQLITE_STATIC);
			sqlite3_bind_int(stmt, 6, profile.checked ? 1 : 0);

			sqlite3_step(stmt);
		});
}

std::optional<unsigned int> login::db::ReadProfile(ProfileRecord& profile)
{
	return WithDb::Query<std::optional<unsigned int>>(SQLITE_OPEN_READONLY)(
		R"(SELECT id, eq_path, hotkey, selected FROM profiles
			WHERE character_id IN (SELECT id FROM characters WHERE server = ? AND character = ?)
			  AND group_id IN (SELECT id FROM profile_groups WHERE name = ?))",
		[&profile](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<unsigned int>
		{
			sqlite3_bind_text(stmt, 1, profile.serverName.c_str(), static_cast<int>(profile.serverName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, profile.characterName.c_str(), static_cast<int>(profile.characterName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 3, profile.profileName.c_str(), static_cast<int>(profile.profileName.length()), SQLITE_STATIC);

			if (sqlite3_step(stmt) == SQLITE_ROW)
			{
				if (sqlite3_column_type(stmt, 1) != SQLITE_NULL)
					profile.eqPath = (const char*)sqlite3_column_text(stmt, 1);

				if (sqlite3_column_type(stmt, 2) != SQLITE_NULL)
					profile.hotkey = (const char*)sqlite3_column_text(stmt, 2);

				if (sqlite3_column_type(stmt, 3) != SQLITE_NULL)
					profile.checked = sqlite3_column_int(stmt, 3) != 0;

				return (unsigned int)sqlite3_column_int(stmt, 0);
			}

			SPDLOG_ERROR("AutoLogin Error failed to load profile {}, server {}, character {}: {}", profile.profileName, profile.serverName, profile.characterName, sqlite3_errmsg(db));
			return {};
		});
}

std::optional<unsigned int> login::db::ReadFullProfile(ProfileRecord& profile)
{
	if (auto master_pass = GetMasterPass())
	{
		// left join group here to allow for empty group (in the case where you want character/server and it doesn't matter)
		return WithDb::Query<std::optional<unsigned int>>(SQLITE_OPEN_READONLY)(
			R"(
			SELECT id, eq_path, hotkey, level, account, password, selected
			FROM profiles
			JOIN (SELECT id AS character_id, account FROM characters WHERE server = ? AND character = ?) USING (character_id)
			JOIN accounts USING (account)
			LEFT JOIN (SELECT id AS group_id FROM profile_groups WHERE name = ?) USING (group_id)
			LEFT JOIN (SELECT character_id, class, level FROM personas WHERE class = ?) USING (character_id))",
			[&master_pass, &profile](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<unsigned int>
			{
				sqlite3_bind_text(stmt, 1, profile.serverName.c_str(), static_cast<int>(profile.serverName.length()), SQLITE_STATIC);
				sqlite3_bind_text(stmt, 2, profile.characterName.c_str(), static_cast<int>(profile.characterName.length()), SQLITE_STATIC);
				sqlite3_bind_text(stmt, 3, profile.profileName.c_str(), static_cast<int>(profile.profileName.length()), SQLITE_STATIC);
				sqlite3_bind_text(stmt, 4, profile.characterClass.c_str(), static_cast<int>(profile.characterClass.length()), SQLITE_STATIC);

				if (sqlite3_step(stmt) == SQLITE_ROW)
				{
					if (sqlite3_column_type(stmt, 1) != SQLITE_NULL)
						profile.eqPath = (const char*)sqlite3_column_text(stmt, 1);
					if (sqlite3_column_type(stmt, 2) != SQLITE_NULL)
						profile.hotkey = (const char*)sqlite3_column_text(stmt, 2);
					if (sqlite3_column_type(stmt, 3) != SQLITE_NULL)
						profile.characterLevel = sqlite3_column_int(stmt, 3);

					profile.accountName = (const char*)sqlite3_column_text(stmt, 4);
					std::string pass((const char*)sqlite3_column_text(stmt, 5), sqlite3_column_bytes(stmt, 5));
					profile.accountPassword = XorEncryptDecrypt(pass, *master_pass);

					if (sqlite3_column_type(stmt, 6) != SQLITE_NULL)
						profile.checked = sqlite3_column_int(stmt, 6) != 0;

					return (unsigned int)sqlite3_column_int(stmt, 0);
				}

				SPDLOG_ERROR("AutoLogin Error failed to load profile {}, server {}, character {}: {}", profile.profileName, profile.serverName, profile.characterName, sqlite3_errmsg(db));
				return {};
			});
	}

	SPDLOG_ERROR("AutoLogin Error failed to read profile because there is no master pass.");
	return {};
}

std::optional<unsigned int> login::db::ReadFullProfile(std::string_view group, std::string_view server, std::string_view name, ProfileRecord& profile)
{
	profile.profileName = group;
	profile.serverName = server;
	profile.characterName = name;

	return ReadFullProfile(profile);
}

void login::db::UpdateProfile(const ProfileRecord& profile)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(
			UPDATE OR REPLACE profiles
			SET eq_path = ?,
			    hotkey = ?,
			    selected = ?
			WHERE character_id IN (SELECT id FROM characters WHERE server = ? AND character = ?)
			  AND group_id IN (SELECT id FROM profile_groups WHERE name = ?))",
		[&profile](sqlite3_stmt* stmt, sqlite3* db)
		{
			if (profile.eqPath)
				sqlite3_bind_text(stmt, 1, profile.eqPath->c_str(), static_cast<int>(profile.eqPath->length()), SQLITE_STATIC);
			else
				sqlite3_bind_null(stmt, 1);
			sqlite3_bind_text(stmt, 2, profile.hotkey.c_str(), static_cast<int>(profile.hotkey.length()), SQLITE_STATIC);
			sqlite3_bind_int(stmt, 3, profile.checked ? 1 : 0);

			sqlite3_bind_text(stmt, 4, profile.serverName.c_str(), static_cast<int>(profile.serverName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 5, profile.characterName.c_str(), static_cast<int>(profile.characterName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 6, profile.profileName.c_str(), static_cast<int>(profile.profileName.length()), SQLITE_STATIC);

			sqlite3_step(stmt);
		});
}

void login::db::DeleteProfile(std::string_view server, std::string_view name, std::string_view group)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(
			DELETE FROM profiles
			WHERE character_id IN (SELECT id FROM characters WHERE server = ? AND character = ?)
			  AND group_id IN (SELECT id FROM profile_groups WHERE name = ?))",
		[server, name, group](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, server.data(), static_cast<int>(server.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, name.data(), static_cast<int>(name.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 3, group.data(), static_cast<int>(group.length()), SQLITE_STATIC);

			sqlite3_step(stmt);
		});
}
// ================================================================================================================================

std::string login::db::GetEQPath(std::string_view group, std::string_view server, std::string_view name)
{
	ProfileRecord profile;
	profile.profileName = group;
	profile.serverName = server;
	profile.characterName = name;
	if (ReadProfile(profile) && profile.eqPath)
		return *profile.eqPath;

	ProfileGroup grp;
	grp.profileName = group;
	if (ReadProfileGroup(grp) && grp.eqPath)
		return *grp.eqPath;

	return ReadEQPath();
}

std::vector<ProfileGroup> login::db::GetProfileGroups()
{
	std::vector<ProfileGroup> profile_groups;

	if (auto pass = GetMasterPass())
	{
		auto groups = WithDb::Query<std::map<unsigned int, ProfileGroup>>(SQLITE_OPEN_READONLY)(
			R"(SELECT id, name, eq_path FROM profile_groups)",
			[](sqlite3_stmt* stmt, sqlite3* db)
			{
				std::map<unsigned int, ProfileGroup> groups;
				while (sqlite3_step(stmt) == SQLITE_ROW)
				{
					auto id = (unsigned int)sqlite3_column_int(stmt, 0);
					std::string name((const char*)sqlite3_column_text(stmt, 1));

					if (sqlite3_column_type(stmt, 2) == SQLITE_TEXT)
						groups[id] = ProfileGroup{ name, (const char*)sqlite3_column_text(stmt, 2), {} };
					else
						groups[id] = ProfileGroup{ name, {}, {} };
				}

				return groups;
			}
		);

		for (auto& [id, group] : groups)
		{
			WithDb::Query<void>(SQLITE_OPEN_READONLY)(
				R"(
					SELECT a.account, a.password, c.server, c.character, p.hotkey, p.selected, p.eq_path, l.class, l.level
					FROM profiles p
					JOIN characters c ON p.character_id = c.id
					JOIN accounts a ON c.account = a.account
					LEFT JOIN personas l ON l.character_id = c.id
					WHERE p.group_id = ?)",
				[&id, &group, &pass](sqlite3_stmt* stmt, sqlite3* db)
				{
					sqlite3_bind_int(stmt, 1, id);
					while (sqlite3_step(stmt) == SQLITE_ROW)
					{
						std::string account((const char*)sqlite3_column_text(stmt, 0));
						std::string readpass((const char*)sqlite3_column_text(stmt, 1), sqlite3_column_bytes(stmt, 1));
						std::string password(XorEncryptDecrypt(readpass, *pass));

						std::string server((const char*)sqlite3_column_text(stmt, 2));
						std::string character((const char*)sqlite3_column_text(stmt, 3));

						std::string hotkey((const char*)sqlite3_column_text(stmt, 4));
						auto selected = (bool)sqlite3_column_int(stmt, 5);

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
							sqlite3_column_type(stmt, 6) == SQLITE_TEXT
								? std::make_optional<std::string>((const char*)sqlite3_column_text(stmt, 6))
								: std::nullopt,
							selected
							});
					}
				}
			);

			profile_groups.push_back(group);
		}
	}
	else
	{
		SPDLOG_ERROR("AutoLogin Error failed to read profiles groups because there is no master pass.");
	}

	return profile_groups;
}

void login::db::WriteProfileGroups(const std::vector<ProfileGroup>& groups)
{
	// all of these creates are upserts, we don't have to worry about testing for existence
	for (auto& group : groups)
	{
		CreateProfileGroup(group);
		for (auto& profile : group.records)
		{
			CreateAccount(profile);
			CreateCharacter(profile);
			CreatePersona(profile);
			CreateProfile(profile);
		}
	}
}

// sqlite init concurrency should be solved by sqlite, if two processes try to create the db at the same time, one will lock
// TODO: test this (open a bunch of clients simultaneously)
bool login::db::InitDatabase(const std::string& path)
{
	s_dbPath = path;
	sqlite3* db = nullptr;

	// first check if the db exists, and if it doesn't then attempt to create it by loading from the ini
	// we specifically don't want to do this if we have a db already, we assume that it's more recent
	// than any ini
	// no matter what happens here, we have to close the db to clear resources as per the sqlite API
	// TODO: is there a better way to detect if a file exists and is a sqlite db
	bool load_ini = sqlite3_open_v2(s_dbPath.c_str(), &db, SQLITE_OPEN_READONLY, nullptr) != SQLITE_OK;
	sqlite3_close(db);
	db = nullptr;

	// now init the db, allowing creation if it's not already created
	if (sqlite3_open_v2(s_dbPath.c_str(), &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, nullptr) != SQLITE_OK)
	{
		SPDLOG_ERROR("AutoLogin Error opening login database: {}", sqlite3_errmsg(db));
	}
	else
	{
		SPDLOG_INFO("AutoLogin Opening database at {}", path);
		char* err_msg = nullptr;
		auto err = [&err_msg, &db](std::string_view text)
			{
				SPDLOG_ERROR("{}: {}", text, err_msg);
				sqlite3_free(err_msg);
			};

		// TODO: account needs another entry to differentiate between emu/live
		//		 this means we can also tie default eq path to emu/live (while
		//		 still allowing for overrides in profile/groups)
		// TODO: persona needs to also store the active persona to persist
		if (sqlite3_exec(db, R"(
			CREATE TABLE IF NOT EXISTS settings (
			  key text primary key,
			  value text not null,
			  description text
			))", nullptr, nullptr, &err_msg) != SQLITE_OK)
			err("AutoLogin Error creating settings table.");
		else if (sqlite3_exec(db, R"(
			CREATE TABLE IF NOT EXISTS accounts (
			  account text primary key,
			  password text
			))",
			nullptr, nullptr, &err_msg) != SQLITE_OK)
			err("AutoLogin Error creating accounts table.");
		else if (sqlite3_exec(db, R"(
			CREATE TABLE IF NOT EXISTS characters (
			  id integer primary key,
			  character text not null,
			  server text not null,
			  account text not null,
			  foreign key (account) references accounts(account) on delete cascade,
			  unique (character, server)
			))",
			nullptr, nullptr, &err_msg) != SQLITE_OK)
			err("AutoLogin Error creating characters table.");
		else if (sqlite3_exec(db, R"(
			CREATE TABLE IF NOT EXISTS profile_groups (
			  id integer primary key,
			  name text not null,
			  eq_path text,
			  unique (name)
			))",
			nullptr, nullptr, &err_msg) != SQLITE_OK)
			err("AutoLogin Error creating profile_groups table.");
		else if (sqlite3_exec(db, R"(
			CREATE TABLE IF NOT EXISTS profiles (
			  id integer primary key,
			  character_id integer not null,
			  group_id integer not null,
			  eq_path text,
			  hotkey text,
			  selected integer,
			  foreign key (character_id) references characters(id) on delete cascade,
			  foreign key (group_id) references profile_groups(id) on delete cascade,
			  unique (character_id, group_id)
			))",
			nullptr, nullptr, &err_msg) != SQLITE_OK)
			err("AutoLogin Error creating profiles table.");
		else if (sqlite3_exec(db, R"(
			CREATE TABLE IF NOT EXISTS personas (
			  id integer primary key,
			  character_id integer not null,
			  class text not null,
			  level integer not null,
			  foreign key (character_id) references characters(id) on delete cascade,
			  unique (character_id, class)
			))",
			nullptr, nullptr, &err_msg) != SQLITE_OK)
			err("AutoLogin Error creating personas table.");
	}

	sqlite3_close(db);
	return load_ini;
}

