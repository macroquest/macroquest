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

namespace {
int StrToBlob(const std::string& string_in, DATA_BLOB* blob_out)
{
	std::string temp = string_in;
	MakeLower(temp);

	const auto data = static_cast<uint8_t*>(LocalAlloc(LPTR, temp.length() + 1));
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

		data[out] = CurByte;
	}
	data[out++] = 0;

	blob_out->cbData = out;
	blob_out->pbData = data;
	return static_cast<int>(blob_out->cbData);
}
}

ProfileRecord ProfileRecord::FromString(const std::string& input)
{
	// we can use regex here because this is not a time-critical process, and makes the
	// code easier to read

	// store our matches in here

	// the first method of username format is underscores
	// we expect here a format of `<profile>_<server>:<character>`
	static std::regex blob_regex(R"((\S+)_([^:]+):(\S+))");
	// <server>^<account>^<character>^<password>
	static std::regex plain_regex(R"(([^\^]+)\^(\S+)\^(\S+)\^(\S+))");
	// <server>^<account>^<password>
	static std::regex plain2_regex(R"(([^\^])\^(\S+)\^(\S+))");
	// <account>^<password>
	static std::regex plain3_regex(R"(([^\^])\^(\S+))");
	// <server>;<profile>:<character>
	static std::regex special_regex(R"(([^;]);(\S+):(\S+);)");
	// <server>:<character>
	static std::regex blob2_regex(R"(([^:]):(\S+))");
	// <profile>
	static std::regex single_regex(R"(([a-zA-Z0-9_]+)");

	ProfileRecord record;

	if (std::smatch matches; std::regex_match(input, matches, blob_regex))
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
	else if (std::regex_match(input, matches, plain3_regex))
	{
		// <stationname>^<pass>
		record.profileName = "";
		record.accountName = matches[1].str();
		record.accountPassword = matches[2].str();
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
	else if (std::regex_match(input, matches, single_regex))
	{
		record.profileName = matches[1].str();
	}

	// ReSharper disable once CppLocalVariableMightNotBeInitialized
	return record;
}

ProfileRecord ProfileRecord::FromBlob(const std::string& blob)
{
	ProfileRecord record;
	DATA_BLOB db, db_out;

	if (!blob.empty() && StrToBlob(blob, &db))
	{
		if (DecryptData(&db, &db_out) && db_out.pbData != nullptr)
		{
			const std::vector<std::string> tokens = split(reinterpret_cast<const char*>(db_out.pbData), ':');
			LocalFree(db_out.pbData);

			switch (tokens.size())
			{
			default:
			case 6:
				record.characterLevel = GetIntFromString(tokens[5], 0);
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

	// ReSharper disable once CppLocalVariableMightNotBeInitialized
	return record;
}

std::vector<ProfileGroup> LoadAutoLoginProfiles(const std::string& ini_file_name, const std::string_view server_type)
{
	if (std::error_code ec; !fs::exists(ini_file_name, ec))
		return {};

	// we've already tested if we need to set the default EQ path, which is represented by server_type

	std::vector<ProfileGroup> profiles;

	// first import blobs
	for (const auto& profile_key : GetPrivateProfileKeys("Profiles", ini_file_name))
	{
		if (!ci_starts_with(profile_key, "Profile"))
			continue;

		const auto section = GetPrivateProfileString("Profiles", profile_key, "", ini_file_name);
		if (section.empty())
			continue;

		ProfileGroup profile_group;
		profile_group.profileName = section;

		if (const auto path = GetPrivateProfileString(section, "EQPath", "", ini_file_name); !path.empty())
			profile_group.eqPath = path;

		// Get list of keys for this profile
		std::vector<std::string> key_names = GetPrivateProfileKeys(section, ini_file_name);
		for (const auto& key : key_names)
		{
			if (key.find("_Blob") == std::string::npos)
				continue;

			std::string blob = GetPrivateProfileString(section, key, "", ini_file_name);
			if (blob.empty())
				continue;

			// the blob has an =0 or =1 appended at the end.
			bool checked = true;
			if (const size_t pos = blob.find('='); pos != std::string::npos)
			{
				checked = blob.substr(pos + 1) != "0";
				blob = blob.substr(0, pos);
			}

			ProfileRecord record = ProfileRecord::FromBlob(blob);
			record.profileName = section;
			record.checked = checked;
			record.serverType = server_type;

			// the key name is split into server:character_Blob
			if (const size_t pos2 = key.find(':'); pos2 != std::string::npos)
			{
				record.serverName = key.substr(0, pos2);
			}

			profile_group.records.push_back(std::move(record));
		}

		if (!profile_group.records.empty())
			profiles.push_back(std::move(profile_group));
	}

	// next import station names and sessions
	for (const auto& section : GetPrivateProfileSections(ini_file_name))
	{
		const auto password = GetPrivateProfileString(section, "Password", "", ini_file_name);
		if (password.empty())
			continue;

		const auto account = ci_starts_with(section, "Session") ?
			GetPrivateProfileString(section, "StationName", "", ini_file_name) :
			section;
		if (account.empty())
			continue;

		ProfileRecord record;
		record.profileName = section;
		record.accountName = account;


		record.serverName = GetPrivateProfileString(section, "Server", "", ini_file_name);
		record.characterName = GetPrivateProfileString(section, "Character", "", ini_file_name);

		if (const auto end = GetPrivateProfileString(section, "EndAfterSelect", "", ini_file_name); !end.empty())
			record.endAfterSelect = GetBoolFromString(end, false);

		if (const auto delay = GetPrivateProfileString(section, "CharSelectDelay", "", ini_file_name); !delay.empty())
			record.charSelectDelay = GetIntFromString(delay, 0);

		if (const auto path = GetPrivateProfileString(section, "EQPath", "", ini_file_name); !path.empty())
			record.eqPath = path;

		ProfileGroup profile_group;
		profile_group.profileName = section;
		profile_group.records.push_back(std::move(record));
		profiles.push_back(std::move(profile_group));
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
	explicit WithDb(const int flags)
	{
		if (sqlite3_open_v2(s_dbPath.c_str(), &m_db, flags, nullptr) != SQLITE_OK)
		{
			SPDLOG_ERROR("AutoLogin Error failed to open database %s: %s", s_dbPath, sqlite3_errmsg(m_db));
			sqlite3_close(m_db);
			m_db = nullptr;
		}
		else
		{
			// pragmas don't need return values, just execute them
			sqlite3_exec(m_db, "PRAGMA journal_mode = WAL", nullptr, nullptr, nullptr);
			sqlite3_exec(m_db, "PRAGMA synchronous = normal", nullptr, nullptr, nullptr);
			sqlite3_exec(m_db, "PRAGMA temp_store = memory", nullptr, nullptr, nullptr);
			sqlite3_exec(m_db, "PRAGMA mmap_size = 100000000", nullptr, nullptr, nullptr);
			sqlite3_exec(m_db, "PRAGMA foreign_keys = ON", nullptr, nullptr, nullptr);
		}
	}

	~WithDb()
	{
		if (m_db != nullptr) sqlite3_close(m_db);
	}

	[[nodiscard]] sqlite3* GetDB() const { return m_db; }

	template <typename T>
	static std::function<T(const std::string&, const std::function<T(sqlite3_stmt*, sqlite3*)>&)> Query(int flags)
	{
		return [flags](const std::string& query, const std::function<T(sqlite3_stmt*, sqlite3*)>& action)
			{
				const auto connection = Get(flags);
				return WithStatement<T>(connection->m_db, query)(action);
			};
	}

	WithDb(const WithDb&) = delete;
	WithDb(WithDb&&) = delete;
	WithDb& operator=(const WithDb&) = delete;
	WithDb& operator=(WithDb&&) = delete;

	static const std::shared_ptr<WithDb>& Get(int flags)
	{
		static std::map<int, std::shared_ptr<WithDb>> connections;

		auto [connection, _] = connections.try_emplace(flags, std::make_shared<WithDb>(flags));

		return connection->second;
	}

private:
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

		WithStatement(const WithStatement&) = delete;
		WithStatement(WithStatement&&) = delete;
		WithStatement& operator=(const WithStatement&) = delete;
		WithStatement& operator=(WithStatement&&) = delete;

	private:
		sqlite3* m_db;
		sqlite3_stmt* m_stmt;
	};

	sqlite3* m_db = nullptr;
};

login::db::StatementHelper::StatementHelper(
	const std::shared_ptr<WithDb>& db,
	const std::string& query,
	const std::function<void(sqlite3_stmt*, sqlite3*)>& bind)
	: m_db(db->GetDB())
	, m_stmt(nullptr)
{
	sqlite3_prepare_v2(m_db, query.c_str(), -1, &m_stmt, nullptr);
	bind(m_stmt, m_db);
}

login::db::StatementHelper::~StatementHelper()
{
	sqlite3_finalize(m_stmt);
}

bool login::db::StatementHelper::Step() const
{
	return sqlite3_step(m_stmt) != SQLITE_ROW;
}

namespace {
// TODO: better encryption
std::string XorEncryptDecrypt(const std::string_view str, const std::string_view key)
{
	std::string out(str);

	const auto mod_val = key.size() / sizeof(char);
	int i = 0;
	for (char& c : out)
	{
		c = static_cast<char>(c ^ key[++i % mod_val]);
	}

	return out;
}
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

bool login::db::ValidatePass(const std::string_view pass)
{
	const auto hash = ReadSetting("master_pass");
	return hash && argon2id_verify(hash->c_str(), pass.data(), pass.length()) == ARGON2_OK;
}

std::optional<std::string> s_masterPass;
void login::db::MemoizeMasterPass(std::string_view pass)
{
	s_masterPass = pass;
}

std::optional<std::string> login::db::GetMasterPass()
{
	if (!s_masterPass) ReadMasterPass();
	return s_masterPass;
}

bool login::db::CreateMasterPass(std::string_view pass, int hours_valid)
{
	// first update the db with the new pass
	HashParams hash_params;
	if (const auto val = ReadSetting("time_cost"))
		hash_params.TimeCost = GetUIntFromString(*val, hash_params.TimeCost);

	if (const auto val = ReadSetting("memory_cost"))
		hash_params.MemoryCost = GetUIntFromString(*val, hash_params.MemoryCost);

	if (const auto val = ReadSetting("paralellism"))
		hash_params.Parallelism = GetUIntFromString(*val, hash_params.Parallelism);

	if (const auto val = ReadSetting("salt_len"))
		hash_params.SaltLength = GetUInt64FromString(*val, hash_params.SaltLength);

	if (const auto val = ReadSetting("hash_len"))
		hash_params.HashLength = GetUInt64FromString(*val, hash_params.HashLength);

	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(R"(
		INSERT INTO settings (key, value, description)
		VALUES('master_pass', ?, 'Encoded hash of the user''s master password.')
		ON CONFLICT (key) DO UPDATE SET value=excluded.value, description=excluded.description)",
		[pass, &hash_params](sqlite3_stmt* stmt, sqlite3* db)
		{
			std::mt19937 generator{ std::random_device{}() };
			std::uniform_int_distribution<unsigned char> distribution{ '!', '~' };
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

			if (const auto argon2_err = argon2id_hash_encoded(
				hash_params.TimeCost,
				hash_params.MemoryCost,
				hash_params.Parallelism,
				pass.data(),
				pass.length(),
				salt.c_str(),
				hash_params.SaltLength,
				hash_params.HashLength,
				encoded.data(),
				encoded.length()); argon2_err == ARGON2_OK)
			{
				sqlite3_bind_text(stmt, 1, encoded.c_str(), static_cast<int>(encoded.length()), SQLITE_STATIC);
				if (sqlite3_step(stmt) != SQLITE_DONE)
					SPDLOG_ERROR("AutoLogin Error failed to store master pass: {}", sqlite3_errmsg(db));
			}
			else
			{
				SPDLOG_ERROR("AutoLogin Error failed to hash master pass: {}", argon2_error_message(argon2_err));
			}
		});

	// then update the registry
	wil::unique_hkey pass_hkey;
	if (create_unique_key_nothrow(HKEY_CURRENT_USER, L"Software\\MacroQuest\\AutoLogin", pass_hkey, wil::reg::key_access::readwrite) == S_OK && pass_hkey)
	{
		// if we can't create or open the key, then we can't really do anything, but we can always just ask for the pass again
		// the timestamp is in hours since epoch

		using namespace std::chrono;
		const uint32_t expiry_timestamp = hours_valid <= 0 ? 0 : static_cast<uint32_t>(
			duration_cast<hours>(system_clock::now().time_since_epoch()).count() + hours_valid);

		// ReSharper disable once CppFunctionResultShouldBeUsed
		wil::reg::set_value_dword_nothrow(pass_hkey.get(), L"MasterPassTimestamp", expiry_timestamp);

		// the string must be converted to a wide string for the registry
		std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> cvt;
		std::wstring wide_pass(cvt.from_bytes(pass.data(), pass.data() + pass.length()));

		// ReSharper disable once CppFunctionResultShouldBeUsed
		wil::reg::set_value_string_nothrow(pass_hkey.get(), L"MasterPass", wide_pass.c_str());
	}

	// and update the memoized value
	s_masterPass = pass;

	return true;
}

std::optional<std::string> login::db::ReadStoredMasterPass()
{
	wil::unique_hkey pass_hkey;
	std::optional<std::wstring> pass; // this must be a wstring, that's the only way to store strings in the registry

	if (open_unique_key_nothrow(HKEY_CURRENT_USER, L"Software\\MacroQuest\\AutoLogin", pass_hkey, wil::reg::key_access::read) != S_OK || !pass_hkey)
	{
		SPDLOG_ERROR("AutoLogin Error failed to open registry key.");
	}
	else if (!((pass = wil::reg::try_get_value_string(pass_hkey.get(), L"MasterPass"))))
	{
		SPDLOG_ERROR("AutoLogin Error master pass is missing from registry.");
	}

	if (pass)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> cvt;
		return std::string(cvt.to_bytes(pass->c_str()));
	}

	return {};
}

bool login::db::ReadMasterPassExpired()
{
	using namespace std::chrono;
	wil::unique_hkey pass_hkey;
	std::optional<DWORD> pass_timestamp;

	if (open_unique_key_nothrow(HKEY_CURRENT_USER, L"Software\\MacroQuest\\AutoLogin", pass_hkey, wil::reg::key_access::read) != S_OK || !pass_hkey)
	{
		SPDLOG_ERROR("AutoLogin Error failed to open registry key.");
		return true;
	}

	if (!((pass_timestamp = wil::reg::try_get_value_dword(pass_hkey.get(), L"MasterPassTimestamp"))))
	{
		SPDLOG_ERROR("AutoLogin Error master pass is missing date.");
		return true;
	}

	if (*pass_timestamp > 0 && static_cast<int>(*pass_timestamp) < duration_cast<hours>(system_clock::now().time_since_epoch()).count())
	{
		SPDLOG_ERROR("AutoLogin Error master pass has expired.");
		return true;
	}

	return false;
}

// this will only try to read from the registry, and then validate against the master key hash
std::optional<std::string> login::db::ReadMasterPass()
{
	if (const auto pass = ReadStoredMasterPass(); pass && !ReadMasterPassExpired() && ValidatePass(*pass))
	{
		MemoizeMasterPass(*pass);
		return pass;
	}

	SPDLOG_ERROR("AutoLogin Error master pass hash does not match.");
	return {};
}

void login::db::WriteSetting(std::string_view key, std::string_view value, std::optional<std::string_view> description)
{
	if (description)
	{
		WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
			R"(
			INSERT INTO SETTINGS (key, value, description) VALUES(?, ?, ?)
			ON CONFLICT (key) DO UPDATE SET value=excluded.value, description=excluded.description)",
			[key, value, description = *description](sqlite3_stmt* stmt, sqlite3* db)
			{
				sqlite3_bind_text(stmt, 1, key.data(), static_cast<int>(key.length()), SQLITE_STATIC);
				sqlite3_bind_text(stmt, 2, value.data(), static_cast<int>(value.length()), SQLITE_STATIC);
				sqlite3_bind_text(stmt, 3, description.data(), static_cast<int>(description.length()), SQLITE_STATIC);

				sqlite3_step(stmt);
			});
	}
	else
	{
		WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
			R"(
			INSERT INTO SETTINGS (key, value, description) VALUES(?, ?, '')
			ON CONFLICT (key) DO UPDATE SET value=excluded.value)",
			[key, value](sqlite3_stmt* stmt, sqlite3* db)
			{
				sqlite3_bind_text(stmt, 1, key.data(), static_cast<int>(key.length()), SQLITE_STATIC);
				sqlite3_bind_text(stmt, 2, value.data(), static_cast<int>(value.length()), SQLITE_STATIC);

				sqlite3_step(stmt);
			});
	}
}

std::optional<std::string> login::db::ReadSetting(std::string_view key)
{
	return WithDb::Query<std::optional<std::string>>(SQLITE_OPEN_READONLY)(
		R"(SELECT value FROM settings WHERE key = ?)",
		[key](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<std::string>
		{
			sqlite3_bind_text(stmt, 1, key.data(), static_cast<int>(key.length()), SQLITE_STATIC);

			if (sqlite3_step(stmt) == SQLITE_ROW)
				return reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));

			return {};
		});
}

void login::db::DeleteSetting(std::string_view key)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(DELETE FROM settings WHERE key = ?)",
		[key](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, key.data(), static_cast<int>(key.length()), SQLITE_STATIC);

			sqlite3_step(stmt);
		}
	);
}

// ================================================================================================================================
login::db::Results<std::string> login::db::ListProfileGroups()
{
	return login::db::Results<std::string>(
		WithDb::Get(SQLITE_OPEN_READONLY),
		R"(SELECT name FROM profile_groups)",
		[](sqlite3_stmt* stmt, sqlite3*)
		{},
		[](sqlite3_stmt* stmt, sqlite3*) -> std::string
		{
			return reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
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
					group.eqPath = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));

				return static_cast<unsigned int>(sqlite3_column_int(stmt, 0));
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
login::db::Results<std::pair<std::string, std::string>> login::db::ListAccounts()
{
	return Results<std::pair<std::string, std::string>>(
		WithDb::Get(SQLITE_OPEN_READONLY),
		R"(SELECT account, server_type FROM accounts)",
		[](sqlite3_stmt*, sqlite3*) {},
		[](sqlite3_stmt* stmt, sqlite3*)
		{
			return std::make_pair(
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
		});
}

void login::db::CreateAccount(const ProfileRecord& profile)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(
			INSERT INTO accounts (account, password, server_type) VALUES (?, ?, ?)
			ON CONFLICT (account, server_type) DO UPDATE SET password=excluded.password)",
		[&profile](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, profile.accountName.c_str(), static_cast<int>(profile.accountName.length()), SQLITE_STATIC);

			std::string encrypted_pass;
			if (const auto master_pass = GetMasterPass())
			{
				encrypted_pass = XorEncryptDecrypt(profile.accountPassword, *master_pass);
				sqlite3_bind_text(stmt, 2, encrypted_pass.c_str(), static_cast<int>(encrypted_pass.length()), SQLITE_STATIC);
			}
			else
			{
				sqlite3_bind_null(stmt, 2);
			}

			sqlite3_bind_text(stmt, 3, profile.serverType.c_str(), static_cast<int>(profile.serverType.length()), SQLITE_STATIC);

			sqlite3_step(stmt);
		});
}

std::optional<std::string> login::db::ReadAccount(ProfileRecord& profile)
{
	return WithDb::Query<std::optional<std::string>>(SQLITE_OPEN_READONLY)(
		R"(
				SELECT account, password, server_type
				FROM accounts
				JOIN characters USING (account_id)
				WHERE server = ? AND character = ?)",
		[&profile](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<std::string>
		{
			sqlite3_bind_text(stmt, 1, profile.serverName.c_str(), static_cast<int>(profile.serverName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, profile.characterName.c_str(), static_cast<int>(profile.characterName.length()), SQLITE_STATIC);

			if (sqlite3_step(stmt) == SQLITE_ROW)
			{
				profile.accountName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
				profile.serverType = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));

				const auto master_pass = GetMasterPass();
				if (master_pass && sqlite3_column_type(stmt, 1) == SQLITE_TEXT)
				{
					std::string pass(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)), sqlite3_column_bytes(stmt, 1));
					pass = XorEncryptDecrypt(pass, *master_pass);
					profile.accountPassword = pass;
					return pass;
				}
			}

			SPDLOG_ERROR("AutoLogin Error failed to load account {}: {}", profile.accountName, sqlite3_errmsg(db));
			return {};
		});
}

std::optional<std::string> login::db::ReadPassword(std::string_view account, std::string_view server_type)
{
	return WithDb::Query<std::optional<std::string>>(SQLITE_OPEN_READONLY)(
		R"(SELECT password FROM accounts WHERE account = ? AND server_type = ?)",
		[account, server_type](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<std::string>
		{
			sqlite3_bind_text(stmt, 1, account.data(), static_cast<int>(account.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, server_type.data(), static_cast<int>(server_type.length()), SQLITE_STATIC);

			const auto master_pass = GetMasterPass();
			if (master_pass && sqlite3_step(stmt) == SQLITE_ROW && sqlite3_column_type(stmt, 0) == SQLITE_TEXT)
			{
				std::string pass(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)), sqlite3_column_bytes(stmt, 0));
				pass = XorEncryptDecrypt(pass, *master_pass);
				return pass;
			}

			SPDLOG_ERROR("AutoLogin Error failed to load account {} ({}): {}", account, server_type, sqlite3_errmsg(db));
			return {};
		});
}

void login::db::UpdateAccount(std::string_view account, std::string_view server_type, const ProfileRecord& record)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(
			UPDATE OR REPLACE accounts
			SET account = ?,
			    password = ?
			    server_type = ?
			WHERE account = ? AND server_type = ?)",
		[account, server_type, &record](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, record.accountName.c_str(), static_cast<int>(record.accountName.length()), SQLITE_STATIC);

			std::string encrypted_pass;
			if (const auto master_pass = GetMasterPass())
			{
				encrypted_pass = XorEncryptDecrypt(record.accountPassword, *master_pass);
				sqlite3_bind_text(stmt, 2, encrypted_pass.c_str(), static_cast<int>(encrypted_pass.length()), SQLITE_STATIC);
			}
			else
			{
				sqlite3_bind_null(stmt, 2);
			}

			sqlite3_bind_text(stmt, 3, record.serverType.c_str(), static_cast<int>(record.serverType.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 4, account.data(), static_cast<int>(account.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 5, server_type.data(), static_cast<int>(server_type.length()), SQLITE_STATIC);

			sqlite3_step(stmt);
		});
}

void login::db::DeleteAccount(std::string_view account, std::string_view server_type)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(DELETE FROM accounts WHERE account = ? AND server_type = ?)",
		[account, server_type](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, account.data(), static_cast<int>(account.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, server_type.data(), static_cast<int>(server_type.length()), SQLITE_STATIC);
			sqlite3_step(stmt);
		});
}
// ================================================================================================================================

// ================================================================================================================================
// characters
login::db::Results<std::pair<std::string, std::string>> login::db::ListCharacters(std::string_view account, std::string_view server_type)
{
	return Results<std::pair<std::string, std::string>>(
		WithDb::Get(SQLITE_OPEN_READONLY),
		R"(
			SELECT server, character
			FROM characters
			JOIN accounts ON accounts.id = account_id
			WHERE account = ? AND server_type = ?)",
		[account, server_type](sqlite3_stmt* stmt, sqlite3*)
		{
			sqlite3_bind_text(stmt, 1, account.data(), static_cast<int>(account.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, server_type.data(), static_cast<int>(server_type.length()), SQLITE_STATIC);
		},
		[](sqlite3_stmt* stmt, sqlite3*)
		{
			return std::make_pair(
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
		});
}

login::db::Results<std::string> login::db::ListServers()
{
	return Results<std::string>(
		WithDb::Get(SQLITE_OPEN_READONLY),
		R"(SELECT DISTINCT server FROM characters)",
		[](sqlite3_stmt*, sqlite3*) {},
		[](sqlite3_stmt* stmt, sqlite3*)
		{
			return reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
		});
}

login::db::Results<ProfileRecord> login::db::ListCharactersOnServer(std::string_view server)
{
	return Results<ProfileRecord>(
		WithDb::Get(SQLITE_OPEN_READONLY),
		R"(
			SELECT DISTINCT character, account, server_type,
				FIRST_VALUE(class) OVER (PARTITION BY characters.id ORDER BY last_seen DESC) AS class,
				FIRST_VALUE(level) OVER (PARTITION BY characters.id ORDER BY last_seen DESC) AS level
			FROM characters
			JOIN accounts ON accounts.id = account_id
			LEFT JOIN personas ON characters.id = character_id
			WHERE server = ?
			GROUP BY characters.id)",
		[server](sqlite3_stmt* stmt, sqlite3*)
		{
			sqlite3_bind_text(stmt, 1, server.data(), static_cast<int>(server.length()), SQLITE_STATIC);
		},
		[server](sqlite3_stmt* stmt, sqlite3*)
		{
			ProfileRecord record;
			record.serverName = server;
			record.characterName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
			record.accountName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
			record.serverType = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));

			if (sqlite3_column_type(stmt, 3) != SQLITE_NULL)
				record.characterClass = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));

			if (sqlite3_column_type(stmt, 4) != SQLITE_NULL)
				record.characterLevel = sqlite3_column_int(stmt, 4);

			return record;
		});
}

login::db::Results<ProfileRecord> login::db::ListCharacterMatches(std::string_view search)
{
	return Results<ProfileRecord>(
		WithDb::Get(SQLITE_OPEN_READONLY),
		R"(
			SELECT DISTINCT server, character, account, server_type,
				FIRST_VALUE(class) OVER (PARTITION BY characters.id ORDER BY last_seen DESC) AS class,
				FIRST_VALUE(level) OVER (PARTITION BY characters.id ORDER BY last_seen DESC) AS level
			FROM characters
			JOIN accounts ON accounts.id = account_id
			LEFT JOIN personas ON characters.id = character_id
			WHERE LOWER(server) LIKE '%' || ? || '%'
			   OR LOWER(character) LIKE '%' || ? || '%'
			   OR LOWER(account) LIKE '%' || ? || '%'
               OR LOWER(class) LIKE '%' || ? || '%'
			GROUP BY characters.id)",
		[search](sqlite3_stmt* stmt, sqlite3*)
		{
			std::string lower_search(search);
			to_lower(lower_search);

			sqlite3_bind_text(stmt, 1, lower_search.c_str(), static_cast<int>(lower_search.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, lower_search.c_str(), static_cast<int>(lower_search.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 3, lower_search.c_str(), static_cast<int>(lower_search.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 4, lower_search.c_str(), static_cast<int>(lower_search.length()), SQLITE_STATIC);
		},
		[](sqlite3_stmt* stmt, sqlite3*)
		{
			ProfileRecord record;
			record.serverName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
			record.characterName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
			record.accountName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
			record.serverType = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));

			// these can be null because of the left join
			if (sqlite3_column_type(stmt, 4) != SQLITE_NULL)
				record.characterClass = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));

			if (sqlite3_column_type(stmt, 5) != SQLITE_NULL)
				record.characterLevel = sqlite3_column_int(stmt, 5);

			return record;
		});
}

void login::db::CreateCharacter(const ProfileRecord& profile)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(
			INSERT INTO characters (character, server, account_id) VALUES(?, ?, (SELECT id FROM accounts WHERE account = ? AND server_type = ?))
			ON CONFLICT(character, server) DO UPDATE SET account_id=excluded.account_id)",
		[&profile](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, profile.characterName.c_str(), static_cast<int>(profile.characterName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, profile.serverName.c_str(), static_cast<int>(profile.serverName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 3, profile.accountName.c_str(), static_cast<int>(profile.accountName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 4, profile.serverType.c_str(), static_cast<int>(profile.serverType.length()), SQLITE_STATIC);

			sqlite3_step(stmt);
		});
}

std::optional<unsigned int> login::db::ReadCharacter(ProfileRecord& profile)
{
	return WithDb::Query<std::optional<unsigned int>>(SQLITE_OPEN_READONLY)(
		R"(
			SELECT id, account, server_type
			FROM characters
			JOIN accounts ON accounts.id = account_id
			WHERE character = ? AND server = ?)",
		[&profile](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<unsigned int>
		{
			sqlite3_bind_text(stmt, 1, profile.characterName.c_str(), static_cast<int>(profile.characterName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, profile.serverName.c_str(), static_cast<int>(profile.serverName.length()), SQLITE_STATIC);

			if (sqlite3_step(stmt) == SQLITE_ROW)
			{
				profile.accountName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
				profile.serverType = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
				return static_cast<unsigned int>(sqlite3_column_int(stmt, 0));
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
			    account_id = (SELECT id FROM accounts WHERE account = ? AND server_type = ?)
			WHERE character = ? AND server = ?)",
		[server, name, &profile](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, profile.characterName.c_str(), static_cast<int>(profile.characterName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, profile.serverName.c_str(), static_cast<int>(profile.serverName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 3, profile.accountName.c_str(), static_cast<int>(profile.accountName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 4, profile.serverType.c_str(), static_cast<int>(profile.serverType.length()), SQLITE_STATIC);

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
			INSERT INTO personas (character_id, class, level, last_seen)
			VALUES ((SELECT id FROM characters WHERE server = ? AND character = ?), ?, ?, datetime())
			ON CONFLICT (character_id, class) DO UPDATE SET level=excluded.level, last_seen=excluded.last_seen)",
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
				return static_cast<unsigned int>(sqlite3_column_int(stmt, 0));
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
			    level = ?,
			    last_seen = datetime()
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
// servers

void login::db::CreateOrUpdateServer(std::string_view short_name, std::string_view long_name)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(
			INSERT INTO servers (short_name, long_name, last_seen) VALUES (?, ?, datetime())
			ON CONFLICT (short_name, long_name) DO UPDATE SET last_seen=excluded.last_seen)",
		[short_name, long_name](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, short_name.data(), static_cast<int>(short_name.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, long_name.data(), static_cast<int>(long_name.length()), SQLITE_STATIC);

			sqlite3_step(stmt);
		});
}

std::optional<std::string> login::db::ReadLongServer(std::string_view short_name)
{
	return WithDb::Query<std::optional<std::string>>(SQLITE_OPEN_READONLY)(
		R"(
			SELECT long_name FROM servers WHERE short_name = ?
			ORDER BY last_seen DESC LIMIT 1)",
		[short_name](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<std::string>
		{
			sqlite3_bind_text(stmt, 1, short_name.data(), static_cast<int>(short_name.length()), SQLITE_STATIC);

			if (sqlite3_step(stmt) == SQLITE_ROW)
				return reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));

			return {};
		});
}

std::optional<std::string> login::db::ReadShortServer(std::string_view long_name)
{
	return WithDb::Query<std::optional<std::string>>(SQLITE_OPEN_READONLY)(
		R"(
			SELECT short_name FROM servers WHERE long_name = ?
			ORDER BY last_seen DESC LIMIT 1)",
		[long_name](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<std::string>
		{
			sqlite3_bind_text(stmt, 1, long_name.data(), static_cast<int>(long_name.length()), SQLITE_STATIC);

			if (sqlite3_step(stmt) == SQLITE_ROW)
				return reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));

			return {};
		});
}

void login::db::DeleteServer(std::string_view short_name, std::string_view long_name)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(
			DELETE FROM servers WHERE short_name = ? AND long_name = ?)",
		[short_name, long_name](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, short_name.data(), static_cast<int>(short_name.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, long_name.data(), static_cast<int>(long_name.length()), SQLITE_STATIC);

			sqlite3_step(stmt);
		});
}

// ================================================================================================================================

// ================================================================================================================================
// server types

void login::db::CreateOrUpdateServerType(std::string_view server_type, std::string_view eq_path)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(
			INSERT INTO server_types (type, eq_path) VALUES (?, ?)
			ON CONFLICT (type) DO UPDATE SET eq_path=excluded.eq_path)",
		[server_type, eq_path](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, server_type.data(), static_cast<int>(server_type.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, eq_path.data(), static_cast<int>(eq_path.length()), SQLITE_STATIC);

			sqlite3_step(stmt);
		});
}

login::db::Results<std::string> login::db::ListServerTypes()
{
	return Results<std::string>(
		WithDb::Get(SQLITE_OPEN_READONLY),
		R"(SELECT type FROM server_types)",
		[](sqlite3_stmt*, sqlite3*) {},
		[](sqlite3_stmt* stmt, sqlite3*)
		{
			return reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
		});
}

std::optional<std::string> login::db::GetPathFromServerType(std::string_view server_type)
{
	return WithDb::Query<std::optional<std::string>>(SQLITE_OPEN_READONLY)(
		R"(SELECT eq_path FROM server_types WHERE type = ?)",
		[server_type](sqlite3_stmt* stmt, sqlite3*) -> std::optional<std::string>
		{
			sqlite3_bind_text(stmt, 1, server_type.data(), static_cast<int>(server_type.length()), SQLITE_STATIC);

			if (sqlite3_step(stmt) == SQLITE_ROW)
				return reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));

			return {};
		});
}

std::optional<std::string> login::db::GetServerTypeFromPath(std::string_view path)
{
	return WithDb::Query<std::optional<std::string>>(SQLITE_OPEN_READONLY)(
		R"(SELECT type FROM server_types WHERE eq_path = ?)",
		[path](sqlite3_stmt* stmt, sqlite3*) -> std::optional<std::string>
		{
			sqlite3_bind_text(stmt, 1, path.data(), static_cast<int>(path.length()), SQLITE_STATIC);

			if (sqlite3_step(stmt) == SQLITE_ROW)
				return reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));

			return {};
		});
}

void login::db::DeleteServerType(std::string_view server_type)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(
			DELETE FROM server_types WHERE server_type = ?)",
		[server_type](sqlite3_stmt* stmt, sqlite3* db)
		{
			sqlite3_bind_text(stmt, 1, server_type.data(), static_cast<int>(server_type.length()), SQLITE_STATIC);

			sqlite3_step(stmt);
		});
}

// ================================================================================================================================

// ================================================================================================================================
// profiles
login::db::Results<ProfileRecord> login::db::GetProfiles(std::string_view group)
{
	return Results<ProfileRecord>(
		WithDb::Get(SQLITE_OPEN_READONLY),
		R"(
			SELECT DISTINCT hotkey, character, server,
				FIRST_VALUE(class) OVER (PARTITION BY characters.id ORDER BY last_seen DESC) AS class,
				FIRST_VALUE(level) OVER (PARTITION BY characters.id ORDER BY last_seen DESC) AS level,
				account, server_type, selected,
				COALESCE(profiles.eq_path, profile_groups.eq_path) AS eq_path,
			    end_after_select, char_select_delay
			FROM profiles
			JOIN characters ON characters.id = character_id
			JOIN accounts ON accounts.id = account_id
			JOIN profile_groups ON profile_groups.id = group_id
			LEFT JOIN personas USING (character_id)
			WHERE profile_groups.name = ?)",
		[group](sqlite3_stmt* stmt, sqlite3*)
		{
			std::vector<ProfileRecord> records;
			sqlite3_bind_text(stmt, 1, group.data(), static_cast<int>(group.length()), SQLITE_STATIC);
		},
		[group](sqlite3_stmt* stmt, sqlite3*)
		{
			ProfileRecord record;
			if (sqlite3_column_type(stmt, 0) != SQLITE_NULL)
				record.hotkey = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));

			record.characterName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
			record.serverName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));

			if (sqlite3_column_type(stmt, 3) != SQLITE_NULL)
				record.characterClass = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
			if (sqlite3_column_type(stmt, 4) != SQLITE_NULL)
				record.characterLevel = sqlite3_column_int(stmt, 4);

			record.accountName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
			record.serverType = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));

			if (sqlite3_column_type(stmt, 7) != SQLITE_NULL)
				record.checked = sqlite3_column_int(stmt, 7) != 0;

			if (sqlite3_column_type(stmt, 8) != SQLITE_NULL)
				record.eqPath = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8));

			if (sqlite3_column_type(stmt, 9) != SQLITE_NULL)
				record.endAfterSelect = sqlite3_column_int(stmt, 9) != 0;

			if (sqlite3_column_type(stmt, 10) != SQLITE_NULL)
				record.charSelectDelay = sqlite3_column_int(stmt, 10);

			record.profileName = group;

			return record;
		});
}

void login::db::CreateProfile(const ProfileRecord& profile)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(
			INSERT INTO profiles (character_id, group_id, eq_path, hotkey, end_after_select, char_select_delay, selected)
			VALUES((SELECT id FROM characters WHERE server = ? AND character = ?), (SELECT id FROM profile_groups WHERE name = ?), ?, ?, ?, ?, ?)
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

			if (profile.endAfterSelect)
				sqlite3_bind_int(stmt, 6, *profile.endAfterSelect ? 1 : 0);
			else
				sqlite3_bind_null(stmt, 6);

			if (profile.charSelectDelay)
				sqlite3_bind_int(stmt, 7, *profile.charSelectDelay);
			else
				sqlite3_bind_null(stmt, 7);

			sqlite3_bind_int(stmt, 8, profile.checked ? 1 : 0);

			sqlite3_step(stmt);
		});
}

std::optional<unsigned int> login::db::ReadProfile(ProfileRecord& profile)
{
	return WithDb::Query<std::optional<unsigned int>>(SQLITE_OPEN_READONLY)(
		R"(SELECT id, eq_path, hotkey, selected, end_after_select, char_select_delay FROM profiles
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
					profile.eqPath = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));

				if (sqlite3_column_type(stmt, 2) != SQLITE_NULL)
					profile.hotkey = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));

				if (sqlite3_column_type(stmt, 3) != SQLITE_NULL)
					profile.checked = sqlite3_column_int(stmt, 3) != 0;

				if (sqlite3_column_type(stmt, 4) != SQLITE_NULL)
					profile.endAfterSelect = sqlite3_column_int(stmt, 4) != 0;

				if (sqlite3_column_type(stmt, 5) != SQLITE_NULL)
					profile.charSelectDelay = sqlite3_column_int(stmt, 5);

				return static_cast<unsigned int>(sqlite3_column_int(stmt, 0));
			}

			SPDLOG_ERROR("AutoLogin Error failed to load profile {}, server {}, character {}: {}", profile.profileName, profile.serverName, profile.characterName, sqlite3_errmsg(db));
			return {};
		});
}

std::optional<unsigned int> login::db::ReadFullProfile(ProfileRecord& profile)
{
	if (auto master_pass = GetMasterPass())
	{
		// left join group here to allow for empty group (in the case where you want character/server, and it doesn't matter)
		return WithDb::Query<std::optional<unsigned int>>(SQLITE_OPEN_READONLY)(
			R"(
			SELECT id, eq_path, hotkey, level, account, password, selected, server_type, end_after_select, char_select_delay
			FROM profiles
			JOIN (SELECT id AS character_id, account FROM characters WHERE server = ? AND character = ?) USING (character_id)
			JOIN (SELECT id AS account_id, account_id, server_type FROM accounts) USING (account_id)
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
						profile.eqPath = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
					if (sqlite3_column_type(stmt, 2) != SQLITE_NULL)
						profile.hotkey = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
					if (sqlite3_column_type(stmt, 3) != SQLITE_NULL)
						profile.characterLevel = sqlite3_column_int(stmt, 3);

					profile.accountName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
					const std::string pass(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)), sqlite3_column_bytes(stmt, 5));
					profile.accountPassword = XorEncryptDecrypt(pass, *master_pass);

					if (sqlite3_column_type(stmt, 6) != SQLITE_NULL)
						profile.checked = sqlite3_column_int(stmt, 6) != 0;

					profile.serverType = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));

					if (sqlite3_column_type(stmt, 8) != SQLITE_NULL)
						profile.endAfterSelect = sqlite3_column_int(stmt, 8) != 0;

					if (sqlite3_column_type(stmt, 9) != SQLITE_NULL)
						profile.charSelectDelay = sqlite3_column_int(stmt, 9);

					return static_cast<unsigned int>(sqlite3_column_int(stmt, 0));
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

std::optional<unsigned> login::db::ReadFirstProfile(ProfileRecord& profile)
{
	if (auto master_pass = GetMasterPass())
	{
		// left join group here to allow for empty group (in the case where you want character/server, and it doesn't matter)
		return WithDb::Query<std::optional<unsigned int>>(SQLITE_OPEN_READONLY)(
			R"(
			SELECT p.id, COALESCE(p.eq_path, g.eq_path), hotkey, server_type, account, password, server, character, selected, end_after_select, char_select_delay
			FROM profiles p
			JOIN (SELECT id AS character_id, character, server, account_id FROM characters) c USING (character_id)
			JOIN (SELECT id AS account_id, account, password, server_type FROM accounts) a USING (account_id)
			LEFT JOIN (SELECT id AS group_id, eq_path FROM profile_groups WHERE name = ?) g USING (group_id)
			LIMIT 1)",
			[&master_pass, &profile](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<unsigned int>
			{
				sqlite3_bind_text(stmt, 1, profile.serverName.c_str(), static_cast<int>(profile.serverName.length()), SQLITE_STATIC);
				sqlite3_bind_text(stmt, 2, profile.characterName.c_str(), static_cast<int>(profile.characterName.length()), SQLITE_STATIC);
				sqlite3_bind_text(stmt, 3, profile.profileName.c_str(), static_cast<int>(profile.profileName.length()), SQLITE_STATIC);
				sqlite3_bind_text(stmt, 4, profile.characterClass.c_str(), static_cast<int>(profile.characterClass.length()), SQLITE_STATIC);

				if (sqlite3_step(stmt) == SQLITE_ROW)
				{
					if (sqlite3_column_type(stmt, 1) != SQLITE_NULL)
						profile.eqPath = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
					if (sqlite3_column_type(stmt, 2) != SQLITE_NULL)
						profile.hotkey = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));

					profile.serverType = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
					profile.accountName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
					const std::string pass(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)), sqlite3_column_bytes(stmt, 5));
					profile.accountPassword = XorEncryptDecrypt(pass, *master_pass);

					profile.serverName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
					profile.characterName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));

					if (sqlite3_column_type(stmt, 8) != SQLITE_NULL)
						profile.checked = sqlite3_column_int(stmt, 8) != 0;

					if (sqlite3_column_type(stmt, 9) != SQLITE_NULL)
						profile.endAfterSelect = sqlite3_column_int(stmt, 9) != 0;

					if (sqlite3_column_type(stmt, 10) != SQLITE_NULL)
						profile.charSelectDelay = sqlite3_column_int(stmt, 10);

					return static_cast<unsigned int>(sqlite3_column_int(stmt, 0));
				}

				SPDLOG_ERROR("AutoLogin Error failed to load from profile {}: {}", profile.profileName, sqlite3_errmsg(db));
				return {};
			});
	}

	SPDLOG_ERROR("AutoLogin Error failed to read profile because there is no master pass.");
	return {};
}

void login::db::UpdateProfile(const ProfileRecord& profile)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
		R"(
			UPDATE OR REPLACE profiles
			SET eq_path = ?,
			    hotkey = ?,
			    selected = ?,
			    end_after_select = ?,
			    char_select_delay = ?
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

			if (profile.endAfterSelect)
				sqlite3_bind_int(stmt, 4, *profile.endAfterSelect ? 1 : 0);
			else
				sqlite3_bind_null(stmt, 4);

			if (profile.charSelectDelay)
				sqlite3_bind_int(stmt, 4, *profile.charSelectDelay);
			else
				sqlite3_bind_null(stmt, 4);

			sqlite3_bind_text(stmt, 5, profile.serverName.c_str(), static_cast<int>(profile.serverName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 6, profile.characterName.c_str(), static_cast<int>(profile.characterName.length()), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 7, profile.profileName.c_str(), static_cast<int>(profile.profileName.length()), SQLITE_STATIC);

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

std::optional<std::string> login::db::GetEQPath(std::string_view group, std::string_view server, std::string_view name)
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

	return {};
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
					auto id = static_cast<unsigned int>(sqlite3_column_int(stmt, 0));
					const std::string name(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));

					if (sqlite3_column_type(stmt, 2) == SQLITE_TEXT)
						groups[id] = ProfileGroup{ name, reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)), {} };
					else
						groups[id] = ProfileGroup{ name, {}, {} };
				}

				return groups;
			}
		);

		for (auto& group : groups)
		{
			WithDb::Query<void>(SQLITE_OPEN_READONLY)(
				R"(
					SELECT a.account, a.password, c.server, c.character, p.hotkey, p.selected, p.eq_path, l.class, l.level, a.server_type, p.end_after_select, p.char_select_delay
					FROM profiles p
					JOIN characters c ON p.character_id = c.id
					JOIN accounts a ON c.account_id = a.id
					LEFT JOIN personas l ON l.character_id = c.id
					WHERE p.group_id = ?)",
				[&id = group.first, &group = group.second, &pass](sqlite3_stmt* stmt, sqlite3* db)
				{
					sqlite3_bind_int(stmt, 1, static_cast<int>(id));
					while (sqlite3_step(stmt) == SQLITE_ROW)
					{
						ProfileRecord record;

						record.accountName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
						const std::string read_pass(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)), sqlite3_column_bytes(stmt, 1));
						record.accountPassword = XorEncryptDecrypt(read_pass, *pass);

						record.serverName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
						record.characterName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));

						record.hotkey = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));

						if (sqlite3_column_type(stmt, 5) != SQLITE_NULL)
							record.checked = sqlite3_column_int(stmt, 5) != 0;

						if (sqlite3_column_type(stmt, 6) != SQLITE_NULL)
							record.eqPath = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));

						if (sqlite3_column_type(stmt, 7) != SQLITE_NULL)
							record.characterClass = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));

						if (sqlite3_column_type(stmt, 8) != SQLITE_NULL)
							record.characterLevel = sqlite3_column_int(stmt, 8);

						record.serverType = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 9));

						if (sqlite3_column_type(stmt, 10) != SQLITE_NULL)
							record.endAfterSelect = sqlite3_column_int(stmt, 10) != 0;

						if (sqlite3_column_type(stmt, 11) != SQLITE_NULL)
							record.charSelectDelay = sqlite3_column_int(stmt, 11);

						group.records.push_back(std::move(record));
					}
				}
			);

			profile_groups.push_back(std::move(group.second));
		}
	}
	else
	{
		SPDLOG_ERROR("AutoLogin Error failed to read profiles groups because there is no master pass.");
	}

	return profile_groups;
}

void login::db::WriteProfileGroups(const std::vector<ProfileGroup>& groups, const std::string_view eq_path)
{
	// all of these creates are upserts, we don't have to worry about testing for existence
	for (auto& group : groups)
	{
		CreateProfileGroup(group);
		for (auto& profile : group.records)
		{
			if (!GetPathFromServerType(profile.serverType))
				CreateOrUpdateServerType(profile.serverType, eq_path);
			CreateAccount(profile);
			CreateCharacter(profile);
			CreatePersona(profile);
			CreateProfile(profile);
		}
	}
}

namespace {
bool CreateVersion0Schema()
{
	auto query = [](const std::string& query, std::string_view table)
		{
			WithDb::Query<void>(SQLITE_OPEN_READWRITE)(
				query,
				[table](sqlite3_stmt* stmt, sqlite3* db)
				{
					if (sqlite3_step(stmt) != SQLITE_DONE)
						SPDLOG_ERROR("Autologin Error creating {} table : {}", table, sqlite3_errmsg(db));
				});
		};
	query(R"(
			CREATE TABLE IF NOT EXISTS settings (
			  key text primary key,
			  value text not null,
			  description text
			))", "settings");
	query(R"(
			CREATE TABLE IF NOT EXISTS accounts (
			  account text primary key,
			  password text
			))", "accounts");
	query(R"(
			CREATE TABLE IF NOT EXISTS characters (
			  id integer primary key,
			  character text not null,
			  server text not null,
			  account text not null,
			  foreign key (account) references accounts(account) on delete cascade,
			  unique (character, server)
			))", "characters");
	query(R"(
			CREATE TABLE IF NOT EXISTS profile_groups (
			  id integer primary key,
			  name text not null,
			  eq_path text,
			  unique (name)
			))", "profile_groups");
	query(R"(
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
			))", "profiles");
	query(R"(
			CREATE TABLE IF NOT EXISTS personas (
			  id integer primary key,
			  character_id integer not null,
			  class text not null,
			  level integer not null,
			  last_seen text,
			  foreign key (character_id) references characters(id) on delete cascade,
			  unique (character_id, class)
			))", "personas");
	query(R"(
			CREATE TABLE IF NOT EXISTS servers (
			  id integer primary key,
			  short_name text,
			  long_name text,
			  last_seen text,
			  unique (short_name, long_name)
			))", "servers");

	// TODO: This should probably actually check the result of the creations
	return true;
}

bool MigrateTableSchema(const std::string& create_query)
{
	const auto db = WithDb::Get(SQLITE_OPEN_READWRITE)->GetDB();
	char* err_msg = nullptr;
	auto fail = [&err_msg, &db](std::string_view message)
	{
			SPDLOG_INFO("AutoLogin Error Migration failed {} : {}", message, err_msg);
			sqlite3_free(err_msg);
			if (sqlite3_exec(db, "ROLLBACK TRANSACTION; PRAGMA foreign_keys = ON;", nullptr, nullptr, &err_msg) != SQLITE_OK)
			{
				SPDLOG_INFO("AutoLogin Error Rollback failed : {}", err_msg);
				sqlite3_free(err_msg);
			}
	};

	if (sqlite3_exec(db, "PRAGMA foreign_keys = OFF; BEGIN TRANSACTION;", nullptr, nullptr, &err_msg) != SQLITE_OK)
	{
		fail("fkey OFF");
		return false;
	}

	if (sqlite3_exec(db, fmt::format("{};\nPRAGMA foreign_key_check;", create_query).c_str(), nullptr, nullptr, &err_msg) != SQLITE_OK)
	{
		fail(create_query);
		return false;
	}

	if (sqlite3_exec(db, "END TRANSACTION; PRAGMA foreign_keys = ON;", nullptr, nullptr, &err_msg) != SQLITE_OK)
	{
		fail("fkey ON");
		return false;
	}

	return true;
}

// when creating a schema migration, follow these steps exactly as per 
// https://www.sqlite.org/lang_altertable.html step 7:
//  1. Create new table
//  2. Copy data
//  3. Drop old table
//  4. Rename new into old
//  5. Re-add all old INDEX, TRIGGER, and VIEW
// all the fkey and transaction stuff surrounding this is done in MigrateTableSchema
// finally, return if the migration was successful

// adds end_after_select and char_select_delay options to profile
// changes accounts to be keyed by id and associates an eq instance with account with uniqueness constraint
// necessary changes to characters to accomodate new account method
bool MigrateVersion1Schema()
{
	return MigrateTableSchema(R"(
		CREATE TABLE new_profiles (
		  id integer primary key,
		  character_id integer not null,
		  group_id integer not null,
		  eq_path text,
		  hotkey text,
		  end_after_select integer,
		  char_select_delay integer,
		  selected integer,
		  foreign key (character_id) references characters(id) on delete cascade,
		  foreign key (group_id) references profile_groups(id) on delete cascade,
		  unique (character_id, group_id));

		INSERT INTO new_profiles
		SELECT id, character_id, group_id, eq_path, hotkey, null, null, selected
		FROM profiles;

		DROP TABLE profiles;

		ALTER TABLE new_profiles RENAME TO profiles;

		CREATE TABLE server_types (
		  type text primary key,
		  eq_path text not null);

		INSERT INTO server_types(type, eq_path)
		VALUES('import', '');

		CREATE TABLE new_accounts (
		  id integer primary key,
		  account text not null,
		  password text not null,
		  server_type text default 'import' not null,
		  foreign key (server_type) references server_types(type) on delete cascade,
		  unique(account, server_type));

		INSERT INTO new_accounts(account, password)
		SELECT account, COALESCE(password, 'invalid')
		FROM accounts;

		DROP TABLE accounts;

		ALTER TABLE new_accounts RENAME TO accounts;

		CREATE TABLE new_characters (
		  id integer primary key,
		  character text not null,
		  server text not null,
		  account_id integer not null,
		  foreign key (account_id) references accounts(id) on delete cascade,
		  unique (character, server));

		INSERT INTO new_characters
		SELECT
		  id,
		  character,
		  server,
		  account_id
		FROM characters
		JOIN (SELECT id AS account_id, account FROM accounts) USING (account);

		DROP TABLE characters;

		ALTER TABLE new_characters RENAME TO characters;
	)");
}
}

// sqlite init concurrency should be solved by sqlite, if two processes try to create the db at the same time, one will lock
// TODO: test this (open a bunch of clients simultaneously)
// TODO: LOWER() account, character, server and UPPER() class
// TODO: add a server edit window, have a server dropdown in character, and server type dropdown in account
// TODO: the list getters need to provide iterators/generators
// TODO: consider never reading the db in the plugin
bool login::db::InitDatabase(const std::string& path)
{
	s_dbPath = path;
	sqlite3* db = nullptr;

	// first check if the db exists, and if it doesn't then attempt to create it by loading from the ini
	// we specifically don't want to do this if we have a db already, we assume that it's more recent
	// than any ini
	// no matter what happens here, we have to close the db to clear resources as per the sqlite API
	const bool first_load = sqlite3_open_v2(s_dbPath.c_str(), &db, SQLITE_OPEN_READONLY, nullptr) != SQLITE_OK;
	sqlite3_close(db);
	db = nullptr;
	
	// now create the db if it wasn't already present (!first_load means it's already been created)
	// we're not actually going to use this db as we want to use WithDb to ensure pragmas are set
	const bool db_ready = !first_load || sqlite3_open_v2(s_dbPath.c_str(), &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, nullptr) == SQLITE_OK;
	if (db != nullptr)
	{
		// don't do anything if the second open call wasn't attempted
		sqlite3_close(db);
		db = nullptr;
	}

	if (!db_ready)
	{
		SPDLOG_ERROR("AutoLogin Error creating or opening login database: {}", sqlite3_errmsg(db));
		return false;
	}

	SPDLOG_INFO("AutoLogin Opening database at {}", path);

	// first let's get the version number (default to 0, which means no version or empty db)
	// we can't really trust PRAGMA schema_version because that changes with user edits

	unsigned int version = 0;
	if (const auto version_setting = ReadSetting("version"))
		version = GetUIntFromString(*version_setting, version);

	std::vector<bool(*)()> migrations;
	switch (version)
	{
	case 0:
		migrations.push_back(&CreateVersion0Schema);
		[[fallthrough]];
	case 1:
		migrations.push_back(&MigrateVersion1Schema);
		[[fallthrough]];
	default:
		break;
	}

	for (const auto& f : migrations)
	{
		// we need to stop processing migrations if any of them fail
		if (!f()) return false;

		// set version here for 2 reasons:
		//  1) if the migration fails, this correctly sets the last migration that succeeded
		//  2) if there are no migrations, nothing is written
		WriteSetting("version", std::to_string(++version), "The current schema version");
	}

	return true;
}

