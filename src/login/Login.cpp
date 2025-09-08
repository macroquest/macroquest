/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
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
#include "mq/base/WString.h"
#include "mq/utils/Markov.h"

#include <wincrypt.h>
#pragma comment(lib, "Crypt32.lib")

#include <wil/resource.h>
#include <wil/registry.h>
#include <filesystem>
#include <regex>
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

static int StrToBlob(const std::string& string_in, DATA_BLOB* blob_out)
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

ProfileRecord ProfileRecord::FromString(const std::string& input)
{
	// we can use regex here because this is not a time-critical process, and makes the
	// code easier to read

	// store our matches in here

	// the first method of username format is underscores
	// we expect here a format of `<profile>_<server>:<character>`
	static std::regex blob_regex(R"((.+)_([^:]+):(\S+))");
	// <server>^<account>^<character>^<password>
	static std::regex plain_regex(R"(([^\^]+)\^(\S+)\^(\S+)\^(\S+))");
	// <server>^<account>^<password>
	static std::regex plain2_regex(R"(([^\^]+)\^(\S+)\^(\S+))");
	// <account>^<password>
	static std::regex plain3_regex(R"(([^\^]+)\^(\S+))");
	// <server>;<profile>:<character>
	static std::regex special_regex(R"(([^;]+);(\S+):(\S+);)");
	// <server>:<character>
	static std::regex blob2_regex(R"(([^:]+):(\S+))");
	// <profile>
	static std::regex single_regex(R"(([a-zA-Z0-9_]+))");

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

	return record;
}

std::vector<ProfileGroup> LoadAutoLoginProfiles(const std::string& ini_file_name, const std::string_view server_type)
{
	if (std::error_code ec; !fs::exists(ini_file_name, ec))
		return {};

	// if the user has set up an alternate ini location, read that instead
	std::string ini_location = GetPrivateProfileString("Settings", "IniLocation", "", ini_file_name);
	if (ini_location.empty())
		ini_location = ini_file_name;
	else if (std::error_code ec; !fs::exists(ini_location, ec))
		return {};

	// we've already tested if we need to set the default EQ path, which is represented by server_type

	std::vector<ProfileGroup> profiles;

	// first import blobs
	unsigned int sortOrder = 0;
	for (const auto& profile_key : GetPrivateProfileKeys("Profiles", ini_location))
	{
		if (!ci_starts_with(profile_key, "Profile"))
			continue;

		const auto section = GetPrivateProfileString("Profiles", profile_key, "", ini_location);
		if (section.empty())
			continue;

		ProfileGroup profile_group;
		profile_group.profileName = section;

		if (const auto path = GetPrivateProfileString(section, "EQPath", "", ini_location); !path.empty())
			profile_group.eqPath = path;

		// Get list of keys for this profile
		std::vector<std::string> key_names = GetPrivateProfileKeys(section, ini_location);
		for (const auto& key : key_names)
		{
			if (key.find("_Blob") == std::string::npos)
				continue;

			std::string blob = GetPrivateProfileString(section, key, "", ini_location);
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
			record.willLoad = checked;
			record.sortOrder = ++sortOrder;
			record.serverType = server_type;

			// the key name is split into server:character_Blob
			if (const size_t pos2 = key.find(':'); pos2 != std::string::npos)
			{
				record.serverName = key.substr(0, pos2);
			}

			if (record.characterName.empty() || record.accountName.empty() || record.serverName.empty())
				continue;

			profile_group.records.push_back(std::move(record));
		}

		if (!profile_group.records.empty())
			profiles.push_back(std::move(profile_group));
	}

	// next import station names and sessions
	sortOrder = 0;
	for (const auto& section : GetPrivateProfileSections(ini_location))
	{
		const auto password = GetPrivateProfileString(section, "Password", "", ini_location);
		if (password.empty())
			continue;

		const auto account = ci_starts_with(section, "Session") ?
			GetPrivateProfileString(section, "StationName", "", ini_location) :
			section;
		if (account.empty())
			continue;

		ProfileRecord record;
		record.profileName = section;
		record.accountName = account;
		record.serverType = server_type;
		record.sortOrder = ++sortOrder;
		record.accountPassword = password;

		record.serverName = GetPrivateProfileString(section, "Server", "", ini_location);
		record.characterName = GetPrivateProfileString(section, "Character", "", ini_location);

		if (const auto end = GetPrivateProfileString(section, "EndAfterSelect", "", ini_location); !end.empty())
			record.endAfterSelect = GetBoolFromString(end, false);

		if (const auto delay = GetPrivateProfileString(section, "CharSelectDelay", "", ini_location); !delay.empty())
			record.charSelectDelay = GetIntFromString(delay, 0);

		if (const auto path = GetPrivateProfileString(section, "EQPath", "", ini_location); !path.empty())
			record.eqPath = path;

		if (const auto ini = GetPrivateProfileString(section, "CustomClientIni", "", ini_location); !ini.empty())
			record.customClientIni = ini;

		ProfileGroup profile_group;
		profile_group.profileName = section;
		profile_group.records.push_back(std::move(record));
		profiles.push_back(std::move(profile_group));
	}

	// now load any settings present
	login::db::WriteSetting("debug",
		GetPrivateProfileString("Settings", "Debug", "false", ini_location),
		"Show debugging output in the plugin");

	login::db::WriteSetting("kick_active",
		GetPrivateProfileString("Settings", "KickActiveCharacter", "true", ini_location),
		"Kick active player automatically while attempting to log in");

	login::db::WriteSetting("end_after_select",
		GetPrivateProfileString("Settings", "EndAfterCharSelect", "false", ini_location),
		"End login automation after the character selection occurs");

	login::db::WriteSetting("char_select_delay",
		GetPrivateProfileString("Settings", "CharSelectDelay", "3", ini_location),
		"Number of seconds to delay at the character selection screen");

	int connect_retries = GetPrivateProfileInt("Settings", "ConnectRetries", 0, ini_location);
	if (connect_retries != 0)
	{
		login::db::WriteSetting("login_connect_retries", std::to_string(connect_retries),
			"Number of times to attempt to connect in case of failure (0 for infinite)");
	}

	login::db::WriteSetting("custom_client_ini",
		GetPrivateProfileString("Settings", "EnableCustomClientIni", "false", ini_location),
		"Enable using a custom eqclient.ini");

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

std::string ProfileRecord::ToString() const
{
	if (!profileName.empty() && !serverName.empty() && !characterName.empty())
		return fmt::format("{}_{}:{}", profileName, serverName, characterName);

	if (!accountName.empty() && !accountPassword.empty())
	{
		if (serverName.empty())
			return fmt::format("{}^{}", accountName, accountPassword);

		if (characterName.empty())
			return fmt::format("{}^{}^{}", serverName, accountName, accountPassword);

		return fmt::format("{}^{}^{}^{}",
			serverName,
			accountName,
			characterName,
			accountPassword);
	}

	if (!serverName.empty() && !characterName.empty())
		return fmt::format("{}:{}", serverName, characterName);

	if (!profileName.empty())
		return profileName;

	return "";
}

static void BindText(sqlite3_stmt* stmt, int position, std::string_view value)
{
	sqlite3_bind_text(stmt, position, value.data(), static_cast<int>(value.length()), SQLITE_STATIC);
}

static std::string ReadText(sqlite3_stmt* stmt, int position)
{
	return reinterpret_cast<const char*>(sqlite3_column_text(stmt, position));
}

static std::map<int, std::shared_ptr<WithDb>> s_connections;
class WithDb
{
public:
	template <typename T>
	using DoQuery = std::function<T(sqlite3_stmt*, sqlite3*)>;

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
	static T Query(const int flags, const std::string& query, const DoQuery<T>& action)
	{
		const auto connection = Get(flags);
		return WithStatement<T>(connection->m_db, query).Execute(action);
	}

	WithDb(const WithDb&) = delete;
	WithDb(WithDb&&) = delete;
	WithDb& operator=(const WithDb&) = delete;
	WithDb& operator=(WithDb&&) = delete;

	static const std::shared_ptr<WithDb>& Get(int flags)
	{
		auto connection = s_connections.find(flags);
		if (connection == s_connections.end())
			connection = s_connections.emplace_hint(connection, flags, std::make_shared<WithDb>(flags));

		return connection->second;
	}

	static void Close(int flags)
	{
		s_connections.erase(flags);
	}

private:
	template <typename T>
	class WithStatement
	{
	public:
		WithStatement(sqlite3* db, const std::string& query) : m_db(db), m_stmt(nullptr)
		{
			if (sqlite3_prepare_v2(m_db, query.c_str(), -1, &m_stmt, nullptr) != SQLITE_OK)
				SPDLOG_ERROR("{}", sqlite3_errmsg(m_db));
		}

		~WithStatement()
		{
			sqlite3_finalize(m_stmt);
		}

		T Execute(const DoQuery<T>& action) const
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

static std::string XorEncryptDecrypt(const std::string_view str, const std::string_view key)
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

struct HashParams
{
	size_t SaltLength = 16;
	size_t HashLength = 32;
	uint32_t TimeCost = 4;
	uint32_t MemoryCost = 1 << 4;
	uint32_t Parallelism = 1;
};

int login::db::ReadDataVersion()
{
	return WithDb::Query<int>(SQLITE_OPEN_READONLY,
		"PRAGMA data_version",
		[](sqlite3_stmt* stmt, sqlite3*)
		{
			if (sqlite3_step(stmt) == SQLITE_ROW)
				return sqlite3_column_int(stmt, 0);
			return 0;
		});
}

static std::string CreateCompany()
{
	static markov::Chain chain({
#include "Companies.h"
	});

	return chain.Generate();
}

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

static std::wstring GetRegistryKey()
{
	auto company = login::db::ReadSetting("reg_company");
	if (company.value_or("").empty())
	{
		company = CreateCompany();
		login::db::WriteSetting("reg_company", *company, "Company for caching the password in the registry");
	}

	return utf8_to_wstring(fmt::format("Software\\{}", *company));
}

void login::db::CacheMasterPass(std::string_view pass)
{
	wil::unique_hkey pass_hkey;

	if (create_unique_key_nothrow(HKEY_CURRENT_USER, GetRegistryKey().c_str(), pass_hkey, wil::reg::key_access::readwrite) == S_OK && pass_hkey)
	{
		// if we can't create or open the key, then we can't really do anything, but we can always just ask for the pass again
		// the timestamp is in hours since epoch

		using namespace std::chrono;
		static auto perpetual_password = login::db::CacheSetting<bool>("perpetual_password", false, GetBoolFromString);
		static auto hours_valid = login::db::CacheSetting<int>("password_timeout_hours", 720, GetIntFromString);
		const uint32_t expiry_timestamp = perpetual_password.Read() ? 0 : static_cast<uint32_t>(
			duration_cast<hours>(system_clock::now().time_since_epoch()).count() + hours_valid.Read());

		WriteSetting("master_pass_expiry", std::to_string(expiry_timestamp), "Epoch time (in hours) when the master pass expires");

		// the string must be converted to a wide string for the registry
		const std::wstring wide_pass = utf8_to_wstring(pass);

		wil::reg::set_value_string_nothrow(pass_hkey.get(), nullptr, wide_pass.c_str());
	}

	// and update the memoized value
	MemoizeMasterPass(pass);
}

bool login::db::CreateMasterPass(std::string_view pass)
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
		hash_params.SaltLength = static_cast<size_t>(GetUInt64FromString(*val, hash_params.SaltLength));

	if (const auto val = ReadSetting("hash_len"))
		hash_params.HashLength = static_cast<size_t>(GetUInt64FromString(*val, hash_params.HashLength));

	WithDb::Query<void>(SQLITE_OPEN_READWRITE, R"(
		INSERT INTO settings (key, value, description)
		VALUES('master_pass', ?, 'Encoded hash of the user''s master password.')
		ON CONFLICT (key) DO UPDATE SET value=excluded.value, description=excluded.description)",
		[pass, &hash_params](sqlite3_stmt* stmt, sqlite3* db)
		{
			std::mt19937 generator{ std::random_device{}() };
			std::uniform_int_distribution<int> distribution{ '!', '~' };
			std::string salt(hash_params.SaltLength, '\0');
			for (auto& c : salt)
				c = static_cast<char>(distribution(generator));

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
				BindText(stmt, 1, encoded);
				if (sqlite3_step(stmt) != SQLITE_DONE)
					SPDLOG_ERROR("AutoLogin Error failed to store master pass: {}", sqlite3_errmsg(db));
			}
			else
			{
				SPDLOG_ERROR("AutoLogin Error failed to hash master pass: {}", argon2_error_message(argon2_err));
			}
		});

	CacheMasterPass(pass);
	return true;
}

std::optional<std::string> login::db::ReadStoredMasterPass()
{
	wil::unique_hkey pass_hkey;
	std::optional<std::wstring> pass; // this must be a wstring, that's the only way to store strings in the registry

	//pass_hkey = wil::reg::open_unique_key(HKEY_CURRENT_USER, GetRegistryKey().c_str());
	open_unique_key_nothrow(HKEY_CURRENT_USER, GetRegistryKey().c_str(), pass_hkey, wil::reg::key_access::read);
	if (pass_hkey)
		pass = wil::reg::try_get_value_string(pass_hkey.get(), nullptr);

	if (pass)
	{
		return wstring_to_utf8(*pass);
	}

	return {};
}

bool login::db::ReadMasterPassExpired()
{
	using namespace std::chrono;
	uint32_t pass_timestamp;
	if (const auto timestamp = ReadSetting("master_pass_expiry"))
		pass_timestamp = GetUIntFromString(*timestamp, 0);
	else
		return true;

	if (pass_timestamp > 0 && static_cast<int>(pass_timestamp) < duration_cast<hours>(system_clock::now().time_since_epoch()).count())
		return true;

	return false;
}

// this will only try to read from the registry, and then validate against the master key hash
std::optional<std::string> login::db::ReadMasterPass()
{
	std::optional<std::string> pass = ReadStoredMasterPass();
	if (pass.has_value() && (pass->empty() || !ReadMasterPassExpired()) && ValidatePass(*pass))
	{
		MemoizeMasterPass(*pass);
		return pass;
	}

	// this is only an error if there is a master pass in the db
	if (ReadSetting("master_pass"))
		SPDLOG_ERROR("AutoLogin Error master pass hash does not match.");

	return {};
}

// this function could update more than just password if more fields are added later
void login::db::UpdateEncryptedData(std::string_view old_pass)
{
	// since the hashing is done in c++, we have to update everything individually
	for (const auto& [account, server_type] : ListAccounts())
	{
		// do nothing if the password couldn't be read
		if (const auto password = ReadPassword(account, server_type, old_pass))
		{
			ProfileRecord record;
			record.accountName = account;
			record.serverType = server_type;
			record.accountPassword = *password;
			UpdateAccount(account, server_type, record);
		}
	}
}

void login::db::WriteSetting(std::string_view key, std::string_view value, std::optional<std::string_view> description)
{
	if (description)
	{
		WithDb::Query<void>(SQLITE_OPEN_READWRITE,
			R"(
			INSERT INTO SETTINGS (key, value, description) VALUES(?, ?, ?)
			ON CONFLICT (key) DO UPDATE SET value=excluded.value, description=excluded.description)",
			[key, value, description = *description](sqlite3_stmt* stmt, sqlite3* db)
			{
				BindText(stmt, 1, key);
				BindText(stmt, 2, value);
				BindText(stmt, 3, description);

				sqlite3_step(stmt);
			});
	}
	else
	{
		WithDb::Query<void>(SQLITE_OPEN_READWRITE,
			R"(
			INSERT INTO SETTINGS (key, value) VALUES(?, ?)
			ON CONFLICT (key) DO UPDATE SET value=excluded.value)",
			[key, value](sqlite3_stmt* stmt, sqlite3* db)
			{
				BindText(stmt, 1, key);
				BindText(stmt, 2, value);

				sqlite3_step(stmt);
			});
	}
}

std::optional<std::string> login::db::ReadSetting(std::string_view key)
{
	return WithDb::Query<std::optional<std::string>>(SQLITE_OPEN_READONLY,
		R"(SELECT value FROM settings WHERE key = ?)",
		[key](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<std::string>
		{
			BindText(stmt, 1, key);

			if (sqlite3_step(stmt) == SQLITE_ROW)
				return ReadText(stmt, 0);

			return {};
		});
}

void login::db::DeleteSetting(std::string_view key)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE,
		R"(DELETE FROM settings WHERE key = ?)",
		[key](sqlite3_stmt* stmt, sqlite3* db)
		{
			BindText(stmt, 1, key);

			sqlite3_step(stmt);
		}
	);
}

// ================================================================================================================================
login::db::Results<std::string> login::db::ListProfileGroups()
{
	return {
		WithDb::Get(SQLITE_OPEN_READONLY),
		R"(SELECT name FROM profile_groups ORDER BY sort_order ASC)",
		[](sqlite3_stmt* stmt, sqlite3*)
		{},
		[](sqlite3_stmt* stmt, sqlite3*) -> std::string
		{
			return ReadText(stmt, 0);
		}
	};
}
void login::db::CreateProfileGroup(const ProfileGroup& group)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE,
		R"(
			INSERT INTO profile_groups (name, eq_path) VALUES(LOWER(?), ?)
			ON CONFLICT(name) DO UPDATE SET eq_path=excluded.eq_path)",
		[&group](sqlite3_stmt* stmt, sqlite3* db)
		{
			BindText(stmt, 1, group.profileName);

			if (group.eqPath)
				BindText(stmt, 2, *group.eqPath);
			else
				sqlite3_bind_null(stmt, 2);

			sqlite3_step(stmt);
		}
	);
}

std::optional<unsigned int> login::db::ReadProfileGroup(ProfileGroup& group)
{
	return WithDb::Query<std::optional<unsigned int>>(SQLITE_OPEN_READONLY,
		R"(SELECT id, eq_path, sort_order FROM profile_groups WHERE name = LOWER(?))",
		[&group](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<unsigned int>
		{
			BindText(stmt, 1, group.profileName);

			if (sqlite3_step(stmt) == SQLITE_ROW)
			{
				if (sqlite3_column_type(stmt, 1) == SQLITE_TEXT)
					group.eqPath = ReadText(stmt, 1);

				group.sortOrder = sqlite3_column_int(stmt, 2) != 0;

				return static_cast<unsigned int>(sqlite3_column_int(stmt, 0));
			}

			SPDLOG_ERROR("AutoLogin Error failed to load profile group {}: {}", group.profileName, sqlite3_errmsg(db));
			return {};
		});
}

std::optional<std::string> login::db::GetLatestProfileGroup()
{
	return WithDb::Query<std::optional<std::string>>(SQLITE_OPEN_READONLY,
		R"(SELECT name FROM profile_groups ORDER BY last_selected DESC LIMIT 1)",
		[](sqlite3_stmt* stmt, sqlite3*) -> std::optional<std::string>
		{
			if (sqlite3_step(stmt) == SQLITE_ROW)
				return ReadText(stmt, 0);

			return {};
		});
}

void login::db::UpdateProfileGroup(std::string_view name, const ProfileGroup& group)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE,
		R"(
			UPDATE profile_groups
			SET name = LOWER(?),
			    eq_path = ?,
			    sort_order = ?,
			    last_selected = strftime('%s', 'now')
			WHERE name  = LOWER(?))",
		[name, &group](sqlite3_stmt* stmt, sqlite3* db)
		{
			BindText(stmt, 1, group.profileName);

			if (group.eqPath)
				BindText(stmt, 2, *group.eqPath);
			else
				sqlite3_bind_null(stmt, 2);

			sqlite3_bind_int(stmt, 3, static_cast<int>(group.sortOrder));

			BindText(stmt, 4, name);

			sqlite3_step(stmt);
		}
	);
}

void login::db::TouchProfileGroup(std::string_view name)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE,
		R"(
			UPDATE profile_groups
			SET last_selected = strftime('%s', 'now')
			WHERE name  = LOWER(?))",
		[name](sqlite3_stmt* stmt, sqlite3* db)
		{
			BindText(stmt, 1, name);
			sqlite3_step(stmt);
		}
	);
}

void login::db::DeleteProfileGroup(std::string_view name)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE,
		R"(DELETE FROM profile_groups WHERE name = LOWER(?))",
		[name](sqlite3_stmt* stmt, sqlite3* db)
		{
			BindText(stmt, 1, name);

			sqlite3_step(stmt);
		}
	);
}
// ================================================================================================================================

// ================================================================================================================================
// accounts
login::db::Results<std::pair<std::string, std::string>> login::db::ListAccounts()
{
	return {
		WithDb::Get(SQLITE_OPEN_READONLY),
		R"(SELECT account, server_type FROM accounts)",
		[](sqlite3_stmt*, sqlite3*) {},
		[](sqlite3_stmt* stmt, sqlite3*)
		{
			return std::make_pair(
				ReadText(stmt, 0),
				ReadText(stmt, 1));
		}
	};
}

login::db::Results<ProfileRecord> login::db::ListAccountMatches(std::string_view search)
{
	return {
		WithDb::Get(SQLITE_OPEN_READONLY),
		R"(
			SELECT DISTINCT account, server_type
			FROM accounts
			WHERE LOWER(server_type) LIKE '%' || LOWER(?) || '%'
			   OR account LIKE '%' || LOWER(?) || '%')",
		[search](sqlite3_stmt* stmt, sqlite3*)
		{
			BindText(stmt, 1, search);
			BindText(stmt, 2, search);
		},
		[](sqlite3_stmt* stmt, sqlite3*)
		{
			ProfileRecord record;
			record.accountName = ReadText(stmt, 0);
			record.serverType = ReadText(stmt, 1);

			return record;
		}
	};
}

void login::db::CreateAccount(const ProfileRecord& profile)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE,
		R"(
			INSERT INTO accounts (account, password, server_type) VALUES (LOWER(?), ?, LOWER(?))
			ON CONFLICT (account, server_type) DO UPDATE SET password=excluded.password)",
		[&profile](sqlite3_stmt* stmt, sqlite3* db)
		{
			BindText(stmt, 1, profile.accountName);

			std::string encrypted_pass;
			if (const auto master_pass = GetMasterPass())
			{
				encrypted_pass = XorEncryptDecrypt(profile.accountPassword, *master_pass);
				BindText(stmt, 2, encrypted_pass);
			}
			else if (!ReadSetting("master_pass"))
			{
				BindText(stmt, 2, profile.accountPassword);
			}
			else
			{
				sqlite3_bind_null(stmt, 2);
			}

			BindText(stmt, 3, profile.serverType);

			sqlite3_step(stmt);
		});
}

std::optional<std::string> login::db::ReadAccount(ProfileRecord& profile)
{
	return WithDb::Query<std::optional<std::string>>(SQLITE_OPEN_READONLY,
		R"(
				SELECT account, password, server_type, eq_path
				FROM accounts
				JOIN characters ON account_id = accounts.id
				JOIN server_types ON server_type = type
				WHERE server = LOWER(?) AND character = LOWER(?))",
		[&profile](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<std::string>
		{
			BindText(stmt, 1, profile.serverName);
			BindText(stmt, 2, profile.characterName);

			if (sqlite3_step(stmt) == SQLITE_ROW)
			{
				profile.accountName = ReadText(stmt, 0);
				profile.serverType = ReadText(stmt, 2);
				profile.eqPath = ReadText(stmt, 3);

				std::string pass(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)), sqlite3_column_bytes(stmt, 1));
				if (const auto master_pass = GetMasterPass())
					pass = XorEncryptDecrypt(pass, *master_pass);

				profile.accountPassword = pass;
				return pass;
			}

			SPDLOG_ERROR("AutoLogin Error failed to load account {}: {}", profile.accountName, sqlite3_errmsg(db));
			return {};
		});
}

std::optional<std::string> login::db::ReadPassword(std::string_view account, std::string_view server_type, std::optional<std::string_view> password_override /* = {} */)
{
	return WithDb::Query<std::optional<std::string>>(SQLITE_OPEN_READONLY,
		R"(SELECT password FROM accounts WHERE account = LOWER(?) AND server_type = LOWER(?))",
		[account, server_type, &password_override](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<std::string>
		{
			BindText(stmt, 1, account);
			BindText(stmt, 2, server_type);

			if (sqlite3_step(stmt) == SQLITE_ROW)
			{
				std::string pass(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)), sqlite3_column_bytes(stmt, 0));
				if (password_override)
				{
					if (!password_override->empty())
						pass = XorEncryptDecrypt(pass, *password_override);
				}
				else if (const auto master_pass = GetMasterPass())
					pass = XorEncryptDecrypt(pass, *master_pass);

				return pass;
			}

			SPDLOG_ERROR("AutoLogin Error failed to load account {} ({}): {}", account, server_type, sqlite3_errmsg(db));
			return {};
		});
}

void login::db::UpdateAccount(std::string_view account, std::string_view server_type, const ProfileRecord& record)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE,
		R"(
			UPDATE accounts
			SET account = LOWER(?),
			    password = ?,
			    server_type = LOWER(?)
			WHERE account = LOWER(?) AND server_type = LOWER(?))",
		[account, server_type, &record](sqlite3_stmt* stmt, sqlite3* db)
		{
			BindText(stmt, 1, record.accountName);

			std::string encrypted_pass;
			if (const auto master_pass = GetMasterPass())
			{
				encrypted_pass = XorEncryptDecrypt(record.accountPassword, *master_pass);
				BindText(stmt, 2, encrypted_pass);
			}
			else if (!ReadSetting("master_pass"))
			{
				BindText(stmt, 2, record.accountPassword);
			}
			else
			{
				sqlite3_bind_null(stmt, 2);
			}

			BindText(stmt, 3, record.serverType);
			BindText(stmt, 4, account);
			BindText(stmt, 5, server_type);

			sqlite3_step(stmt);
		});
}

void login::db::DeleteAccount(std::string_view account, std::string_view server_type)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE,
		R"(DELETE FROM accounts WHERE account = LOWER(?) AND server_type = LOWER(?))",
		[account, server_type](sqlite3_stmt* stmt, sqlite3* db)
		{
			BindText(stmt, 1, account);
			BindText(stmt, 2, server_type);
			sqlite3_step(stmt);
		});
}
// ================================================================================================================================

// ================================================================================================================================
// characters
login::db::Results<std::pair<std::string, std::string>> login::db::ListCharacters(std::string_view account, std::string_view server_type)
{
	return {
		WithDb::Get(SQLITE_OPEN_READONLY),
		R"(
			SELECT server, character
			FROM characters
			JOIN accounts ON accounts.id = account_id
			WHERE account = LOWER(?) AND server_type = LOWER(?))",
		[account, server_type](sqlite3_stmt* stmt, sqlite3*)
		{
			BindText(stmt, 1, account);
			BindText(stmt, 2, server_type);
		},
		[](sqlite3_stmt* stmt, sqlite3*)
		{
			return std::make_pair(
				ReadText(stmt, 0),
				ReadText(stmt, 1));
		}
	};
}

login::db::Results<std::string> login::db::ListServers()
{
	return {
		WithDb::Get(SQLITE_OPEN_READONLY),
		R"(SELECT DISTINCT server FROM characters)",
		[](sqlite3_stmt*, sqlite3*) {},
		[](sqlite3_stmt* stmt, sqlite3*)
		{
			return ReadText(stmt, 0);
		}
	};
}

login::db::Results<ProfileRecord> login::db::ListCharactersOnServer(std::string_view server)
{
	return {
		WithDb::Get(SQLITE_OPEN_READONLY),
		R"(
			SELECT DISTINCT character, account, server_type,
				FIRST_VALUE(class) OVER (PARTITION BY characters.id ORDER BY last_seen DESC) AS class,
				FIRST_VALUE(level) OVER (PARTITION BY characters.id ORDER BY last_seen DESC) AS level
			FROM characters
			JOIN accounts ON accounts.id = account_id
			LEFT JOIN personas ON characters.id = character_id
			WHERE server = LOWER(?) AND visible <> 0)",
		[server](sqlite3_stmt* stmt, sqlite3*)
		{
			BindText(stmt, 1, server);
		},
		[server](sqlite3_stmt* stmt, sqlite3*)
		{
			ProfileRecord record;
			record.serverName = server;
			record.characterName = ReadText(stmt, 0);
			record.accountName = ReadText(stmt, 1);
			record.serverType = ReadText(stmt, 2);

			if (sqlite3_column_type(stmt, 3) != SQLITE_NULL)
				record.characterClass = ReadText(stmt, 3);

			if (sqlite3_column_type(stmt, 4) != SQLITE_NULL)
				record.characterLevel = sqlite3_column_int(stmt, 4);

			return record;
		}
	};
}

login::db::Results<ProfileRecord> login::db::ListCharacterMatches(std::string_view search)
{
	return {
		WithDb::Get(SQLITE_OPEN_READONLY),
		R"(
			SELECT DISTINCT server, character, account, server_type,
			    FIRST_VALUE(class) OVER (PARTITION BY characters.id ORDER BY last_seen DESC) AS class,
			    FIRST_VALUE(level) OVER (PARTITION BY characters.id ORDER BY last_seen DESC) AS level,
			    visible
			FROM characters
			JOIN accounts ON accounts.id = account_id
			LEFT JOIN personas ON characters.id = character_id
			WHERE server LIKE '%' || LOWER(?) || '%'
			   OR character LIKE '%' || LOWER(?) || '%'
			   OR account LIKE '%' || LOWER(?) || '%'
			   OR LOWER(class) LIKE '%' || LOWER(?) || '%')",
		[search](sqlite3_stmt* stmt, sqlite3*)
		{
			BindText(stmt, 1, search);
			BindText(stmt, 2, search);
			BindText(stmt, 3, search);
			BindText(stmt, 4, search);
		},
		[](sqlite3_stmt* stmt, sqlite3*)
		{
			ProfileRecord record;
			record.serverName = ReadText(stmt, 0);
			record.characterName = ReadText(stmt, 1);
			record.accountName = ReadText(stmt, 2);
			record.serverType = ReadText(stmt, 3);

			// these can be null because of the left join
			if (sqlite3_column_type(stmt, 4) != SQLITE_NULL)
				record.characterClass = ReadText(stmt, 4);

			if (sqlite3_column_type(stmt, 5) != SQLITE_NULL)
				record.characterLevel = sqlite3_column_int(stmt, 5);

			record.visible = sqlite3_column_int(stmt, 6) != 0;

			return record;
		}
	};
}

void login::db::CreateCharacter(const ProfileRecord& profile)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE,
		R"(
			INSERT INTO characters (character, server, account_id, visible) VALUES(LOWER(?), LOWER(?), (SELECT id FROM accounts WHERE account = LOWER(?) AND server_type = LOWER(?)), ?)
			ON CONFLICT(character, server) DO UPDATE SET account_id=excluded.account_id, visible=excluded.visible)",
		[&profile](sqlite3_stmt* stmt, sqlite3* db)
		{
			BindText(stmt, 1, profile.characterName);
			BindText(stmt, 2, profile.serverName);
			BindText(stmt, 3, profile.accountName);
			BindText(stmt, 4, profile.serverType);

			sqlite3_bind_int(stmt, 5, profile.visible ? 1 : 0);

			sqlite3_step(stmt);
		});
}

std::optional<unsigned int> login::db::ReadCharacter(ProfileRecord& profile)
{
	return WithDb::Query<std::optional<unsigned int>>(SQLITE_OPEN_READONLY,
		R"(
			SELECT characters.id, account, server_type, visible
			FROM characters
			JOIN accounts ON accounts.id = account_id
			WHERE character = LOWER(?) AND server = LOWER(?))",
		[&profile](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<unsigned int>
		{
			BindText(stmt, 1, profile.characterName);
			BindText(stmt, 2, profile.serverName);

			if (sqlite3_step(stmt) == SQLITE_ROW)
			{
				profile.accountName = ReadText(stmt, 1);
				profile.serverType = ReadText(stmt, 2);
				profile.visible = sqlite3_column_int(stmt, 3) != 0;
				return static_cast<unsigned int>(sqlite3_column_int(stmt, 0));
			}

			return {};
		});
}

void login::db::UpdateCharacter(std::string_view server, std::string_view name, const ProfileRecord& profile)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE,
		R"(
			UPDATE characters
			SET character = LOWER(?),
			    server = LOWER(?),
			    account_id = (SELECT id FROM accounts WHERE account = LOWER(?) AND server_type = LOWER(?)),
			    visible = ?
			WHERE character = LOWER(?) AND server = LOWER(?))",
		[server, name, &profile](sqlite3_stmt* stmt, sqlite3* db)
		{
			BindText(stmt, 1, profile.characterName);
			BindText(stmt, 2, profile.serverName);
			BindText(stmt, 3, profile.accountName);
			BindText(stmt, 4, profile.serverType);

			sqlite3_bind_int(stmt, 5, profile.visible ? 1 : 0);

			BindText(stmt, 6, name);
			BindText(stmt, 7, server);

			sqlite3_step(stmt);
		});
}

void login::db::DeleteCharacter(std::string_view server, std::string_view name)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE,
		R"(DELETE FROM characters WHERE character = LOWER(?) AND server = LOWER(?))",
		[server, name](sqlite3_stmt* stmt, sqlite3* db)
		{
			BindText(stmt, 1, name);
			BindText(stmt, 2, server);

			sqlite3_step(stmt);
		});
}
// ================================================================================================================================

// ================================================================================================================================
// personas
void login::db::CreatePersona(const ProfileRecord& profile)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE,
		R"(
			INSERT INTO personas (character_id, class, level, last_seen)
			VALUES ((SELECT id FROM characters WHERE server = LOWER(?) AND character = LOWER(?)), UPPER(?), ?, datetime())
			ON CONFLICT (character_id, class) DO UPDATE SET level=excluded.level, last_seen=excluded.last_seen)",
		[&profile](sqlite3_stmt* stmt, sqlite3* db)
		{
			BindText(stmt, 1, profile.serverName);
			BindText(stmt, 2, profile.characterName);
			BindText(stmt, 3, profile.characterClass);
			sqlite3_bind_int(stmt, 4, profile.characterLevel);

			sqlite3_step(stmt);
		});
}

std::optional<unsigned int> login::db::ReadPersona(ProfileRecord& profile)
{
	return WithDb::Query<std::optional<unsigned int>>(SQLITE_OPEN_READONLY,
		R"(
			SELECT p.id, level
			FROM personas p
			JOIN characters c ON p.character_id = c.id
			WHERE server = LOWER(?) AND character = LOWER(?) AND class = UPPER(?))",
		[&profile](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<unsigned int>
		{
			BindText(stmt, 1, profile.serverName);
			BindText(stmt, 2, profile.characterName);
			BindText(stmt, 3, profile.characterClass);

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
	WithDb::Query<void>(SQLITE_OPEN_READWRITE,
		R"(
			UPDATE personas
			SET class = UPPER(?),
			    level = ?,
			    last_seen = datetime()
			WHERE character_id IN (SELECT id FROM characters WHERE server = LOWER(?) AND character = LOWER(?)) AND class = UPPER(?))",
		[cls, &profile](sqlite3_stmt* stmt, sqlite3* db)
		{
			BindText(stmt, 1, profile.characterClass);
			sqlite3_bind_int(stmt, 2, profile.characterLevel);
			BindText(stmt, 3, profile.serverName);
			BindText(stmt, 4, profile.characterName);
			BindText(stmt, 5, cls);

			sqlite3_step(stmt);
		});
}

void login::db::DeletePersona(std::string_view server, std::string_view name, std::string_view cls)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE,
		R"(
			DELETE FROM personas
			WHERE character_id IN (SELECT id FROM characters WHERE server = LOWER(?) AND character = LOWER(?)) AND class = UPPER(?))",
		[server, name, cls](sqlite3_stmt* stmt, sqlite3* db)
		{
			BindText(stmt, 1, server);
			BindText(stmt, 2, name);
			BindText(stmt, 3, cls);

			sqlite3_step(stmt);
		});
}
// ================================================================================================================================

// ================================================================================================================================
// servers

void login::db::CreateOrUpdateServer(std::string_view short_name, std::string_view long_name)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE,
		R"(
			INSERT INTO servers (short_name, long_name, last_seen) VALUES (LOWER(?), LOWER(?), datetime())
			ON CONFLICT (short_name, long_name) DO UPDATE SET last_seen=excluded.last_seen)",
		[short_name, long_name](sqlite3_stmt* stmt, sqlite3* db)
		{
			BindText(stmt, 1, short_name);
			BindText(stmt, 2, long_name);

			sqlite3_step(stmt);
		});
}

login::db::Results<std::pair<std::string, std::string>> login::db::ListServerNames()
{
	return {
		WithDb::Get(SQLITE_OPEN_READONLY),
		R"(SELECT short_name, long_name FROM servers)",
		[](sqlite3_stmt*, sqlite3*) {},
		[](sqlite3_stmt* stmt, sqlite3*)
		{
			return std::make_pair(
				ReadText(stmt, 0),
				ReadText(stmt, 1));
		}
	};
}

login::db::Results<std::pair<std::string, std::string>> login::db::ListServerMatches(std::string_view search)
{
	return {
		WithDb::Get(SQLITE_OPEN_READONLY),
		R"(
			SELECT short_name, long_name FROM servers
			WHERE LOWER(short_name) LIKE '%' || LOWER(?) || '%'
			   OR LOWER(long name) LIKE '%' || LOWER(?) || '%')",
		[search](sqlite3_stmt* stmt, sqlite3*)
		{
			BindText(stmt, 1, search);
			BindText(stmt, 2, search);
		},
		[](sqlite3_stmt* stmt, sqlite3*)
		{
			return std::make_pair(
				ReadText(stmt, 0),
				ReadText(stmt, 1));
		}
	};
}

login::db::Results<std::string> login::db::ReadLongServer(std::string_view short_name)
{
	return {
		WithDb::Get(SQLITE_OPEN_READONLY),
		R"(
			SELECT long_name FROM servers WHERE short_name = LOWER(?)
			ORDER BY last_seen DESC)",
		[short_name](sqlite3_stmt* stmt, sqlite3*)
		{ BindText(stmt, 1, short_name); },
		[](sqlite3_stmt* stmt, sqlite3*)
		{
			return ReadText(stmt, 0);
		}
	};
}

std::optional<std::string> login::db::ReadShortServer(std::string_view long_name)
{
	return WithDb::Query<std::optional<std::string>>(SQLITE_OPEN_READONLY,
		R"(
			SELECT short_name FROM servers WHERE long_name = LOWER(?)
			ORDER BY last_seen DESC LIMIT 1)",
		[long_name](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<std::string>
		{
			BindText(stmt, 1, long_name);

			if (sqlite3_step(stmt) == SQLITE_ROW)
				return ReadText(stmt, 0);

			return {};
		});
}

void login::db::DeleteServer(std::string_view short_name, std::string_view long_name)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE,
		R"(
			DELETE FROM servers WHERE short_name = LOWER(?) AND long_name = LOWER(?))",
		[short_name, long_name](sqlite3_stmt* stmt, sqlite3* db)
		{
			BindText(stmt, 1, short_name);
			BindText(stmt, 2, long_name);

			sqlite3_step(stmt);
		});
}

// ================================================================================================================================

// ================================================================================================================================
// server types

void login::db::CreateOrUpdateServerType(std::string_view server_type, std::string_view eq_path)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE,
		R"(
			INSERT INTO server_types (type, eq_path) VALUES (LOWER(?), ?)
			ON CONFLICT (type) DO UPDATE SET eq_path=excluded.eq_path)",
		[server_type, eq_path](sqlite3_stmt* stmt, sqlite3* db)
		{
			BindText(stmt, 1, server_type);
			BindText(stmt, 2, eq_path);

			sqlite3_step(stmt);
		});
}

login::db::Results<std::string> login::db::ListServerTypes()
{
	return {
		WithDb::Get(SQLITE_OPEN_READONLY),
		R"(SELECT type FROM server_types)",
		[](sqlite3_stmt*, sqlite3*) {},
		[](sqlite3_stmt* stmt, sqlite3*)
		{
			return ReadText(stmt, 0);
		}
	};
}

std::optional<std::string> login::db::GetPathFromServerType(std::string_view server_type)
{
	return WithDb::Query<std::optional<std::string>>(SQLITE_OPEN_READONLY,
		R"(SELECT eq_path FROM server_types WHERE type = LOWER(?))",
		[server_type](sqlite3_stmt* stmt, sqlite3*) -> std::optional<std::string>
		{
			BindText(stmt, 1, server_type);

			if (sqlite3_step(stmt) == SQLITE_ROW)
				return ReadText(stmt, 0);

			return {};
		});
}

std::optional<std::string> login::db::GetServerTypeFromPath(std::string_view path)
{
	return WithDb::Query<std::optional<std::string>>(SQLITE_OPEN_READONLY,
		R"(SELECT type FROM server_types WHERE LOWER(eq_path) = LOWER(?))",
		[path](sqlite3_stmt* stmt, sqlite3*) -> std::optional<std::string>
		{
			BindText(stmt, 1, path);

			if (sqlite3_step(stmt) == SQLITE_ROW)
				return ReadText(stmt, 0);

			return {};
		});
}

void login::db::DeleteServerType(std::string_view server_type)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE,
		R"(
			DELETE FROM server_types WHERE type = LOWER(?))",
		[server_type](sqlite3_stmt* stmt, sqlite3* db)
		{
			BindText(stmt, 1, server_type);

			sqlite3_step(stmt);
		});
}

// ================================================================================================================================

// ================================================================================================================================
// profiles
login::db::Results<ProfileRecord> login::db::GetProfiles(std::string_view group)
{
	return {
		WithDb::Get(SQLITE_OPEN_READONLY),
		R"(
			SELECT DISTINCT hotkey, character, server,
				FIRST_VALUE(class) OVER (PARTITION BY characters.id ORDER BY last_seen DESC) AS class,
				FIRST_VALUE(level) OVER (PARTITION BY characters.id ORDER BY last_seen DESC) AS level,
				account, server_type, profiles.sort_order,
				COALESCE(profiles.eq_path, profile_groups.eq_path) AS eq_path,
				end_after_select, char_select_delay, custom_client_ini, will_load
			FROM profiles
			JOIN characters ON characters.id = character_id
			JOIN accounts ON accounts.id = account_id
			JOIN profile_groups ON profile_groups.id = group_id
			LEFT JOIN personas USING (character_id)
			WHERE profile_groups.name = LOWER(?)
			ORDER BY profiles.sort_order ASC)",
		[group](sqlite3_stmt* stmt, sqlite3*)
		{
			BindText(stmt, 1, group);
		},
		[group](sqlite3_stmt* stmt, sqlite3*)
		{
			ProfileRecord record;
			if (sqlite3_column_type(stmt, 0) != SQLITE_NULL)
				record.hotkey = ReadText(stmt, 0);

			record.characterName = ReadText(stmt, 1);
			record.serverName = ReadText(stmt, 2);

			if (sqlite3_column_type(stmt, 3) != SQLITE_NULL)
				record.characterClass = ReadText(stmt, 3);
			if (sqlite3_column_type(stmt, 4) != SQLITE_NULL)
				record.characterLevel = sqlite3_column_int(stmt, 4);

			record.accountName = ReadText(stmt, 5);
			record.serverType = ReadText(stmt, 6);

			if (sqlite3_column_type(stmt, 7) != SQLITE_NULL)
				record.sortOrder = sqlite3_column_int(stmt, 7);
			else
				record.sortOrder = 0;

			if (sqlite3_column_type(stmt, 8) != SQLITE_NULL)
				record.eqPath = ReadText(stmt, 8);

			if (sqlite3_column_type(stmt, 9) != SQLITE_NULL)
				record.endAfterSelect = sqlite3_column_int(stmt, 9) != 0;

			if (sqlite3_column_type(stmt, 10) != SQLITE_NULL)
				record.charSelectDelay = sqlite3_column_int(stmt, 10);

			if (sqlite3_column_type(stmt, 11) != SQLITE_NULL)
				record.customClientIni = ReadText(stmt, 11);

			record.willLoad = sqlite3_column_int(stmt, 12) != 0;

			record.profileName = group;

			return record;
		}
	};
}

std::vector<ProfileRecord> login::db::GetActiveProfiles(std::string_view group)
{
	return WithDb::Query<std::vector<ProfileRecord>>(SQLITE_OPEN_READONLY,
		R"(
			SELECT hotkey, character, server, 
				COALESCE(profiles.eq_path, profile_groups.eq_path) AS eq_path
			FROM profiles
			JOIN characters ON characters.id = character_id
			JOIN profile_groups ON profile_groups.id = group_id
			WHERE profile_groups.name = LOWER(?)
			  AND will_load <> 0
			ORDER BY profiles.sort_order ASC)",
		[group](sqlite3_stmt* stmt, sqlite3*)
		{
			std::vector<ProfileRecord> profiles;
			BindText(stmt, 1, group);

			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				ProfileRecord profile;
				if (sqlite3_column_type(stmt, 0) != SQLITE_NULL)
					profile.hotkey = ReadText(stmt, 0);

				profile.characterName = ReadText(stmt, 1);
				profile.serverName = ReadText(stmt, 2);

				if (sqlite3_column_type(stmt, 3) != SQLITE_NULL)
					profile.eqPath = ReadText(stmt, 3);

				profile.profileName = group;

				profiles.push_back(std::move(profile));
			}

			return profiles;
		});
}

void login::db::CreateProfile(const ProfileRecord& profile)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE,
		R"(
			INSERT INTO profiles (character_id, group_id, eq_path, hotkey, end_after_select, char_select_delay, custom_client_ini, will_load)
			VALUES((SELECT id FROM characters WHERE server = LOWER(?) AND character = LOWER(?)), (SELECT id FROM profile_groups WHERE name = LOWER(?)), ?, ?, ?, ?, ?, ?)
			ON CONFLICT(character_id, group_id) DO UPDATE SET eq_path=excluded.eq_path, hotkey=excluded.hotkey, sort_order=excluded.sort_order, will_load=excluded.will_load)",
		[&profile](sqlite3_stmt* stmt, sqlite3* db)
		{
			BindText(stmt, 1, profile.serverName);
			BindText(stmt, 2, profile.characterName);
			BindText(stmt, 3, profile.profileName);

			if (profile.eqPath)
				BindText(stmt, 4, *profile.eqPath);
			else
				sqlite3_bind_null(stmt, 4);

			BindText(stmt, 5, profile.hotkey);

			if (profile.endAfterSelect)
				sqlite3_bind_int(stmt, 6, *profile.endAfterSelect ? 1 : 0);
			else
				sqlite3_bind_null(stmt, 6);

			if (profile.charSelectDelay)
				sqlite3_bind_int(stmt, 7, *profile.charSelectDelay);
			else
				sqlite3_bind_null(stmt, 7);

			if (profile.customClientIni)
				BindText(stmt, 8, *profile.customClientIni);
			else
				sqlite3_bind_null(stmt, 8);

			sqlite3_bind_int(stmt, 9, profile.willLoad ? 1 : 0);

			sqlite3_step(stmt);
		});
}

std::optional<unsigned int> login::db::ReadProfile(ProfileRecord& profile)
{
	return WithDb::Query<std::optional<unsigned int>>(SQLITE_OPEN_READONLY,
		R"(
			SELECT profiles.id, COALESCE(profiles.eq_path, profile_groups.eq_path), hotkey, profiles.sort_order, end_after_select, char_select_delay, custom_client_ini, will_load
			FROM profiles
			JOIN characters ON character_id = characters.id
			JOIN profile_groups ON group_id = profile_groups.id
			WHERE server = LOWER(?) AND character = LOWER(?) AND name = LOWER(?))",
		[&profile](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<unsigned int>
		{
			BindText(stmt, 1, profile.serverName);
			BindText(stmt, 2, profile.characterName);
			BindText(stmt, 3, profile.profileName);

			if (sqlite3_step(stmt) == SQLITE_ROW)
			{
				if (sqlite3_column_type(stmt, 1) != SQLITE_NULL)
					profile.eqPath = ReadText(stmt, 1);

				if (sqlite3_column_type(stmt, 2) != SQLITE_NULL)
					profile.hotkey = ReadText(stmt, 2);

				if (sqlite3_column_type(stmt, 3) != SQLITE_NULL)
					profile.sortOrder = sqlite3_column_int(stmt, 3);
				else
					profile.sortOrder = 0;

				if (sqlite3_column_type(stmt, 4) != SQLITE_NULL)
					profile.endAfterSelect = sqlite3_column_int(stmt, 4) != 0;

				if (sqlite3_column_type(stmt, 5) != SQLITE_NULL)
					profile.charSelectDelay = sqlite3_column_int(stmt, 5);

				if (sqlite3_column_type(stmt, 6) != SQLITE_NULL)
					profile.customClientIni = ReadText(stmt, 6);

				profile.willLoad = sqlite3_column_int(stmt, 7) != 0;

				return static_cast<unsigned int>(sqlite3_column_int(stmt, 0));
			}

			SPDLOG_ERROR("AutoLogin Error failed to load profile {}, server {}, character {}: {}", profile.profileName, profile.serverName, profile.characterName, sqlite3_errmsg(db));
			return {};
		});
}

std::optional<unsigned int> login::db::ReadFullProfile(ProfileRecord& profile)
{
	// left join group here to allow for empty group (in the case where you want character/server, and it doesn't matter)
	return WithDb::Query<std::optional<unsigned int>>(SQLITE_OPEN_READONLY,
		R"(
			SELECT id, eq_path, hotkey, level, account, password, sort_order, server_type, end_after_select, char_select_delay, custom_client_ini, will_load
			FROM profiles
			JOIN (SELECT id AS character_id, account_id FROM characters WHERE server = LOWER(?) AND character = LOWER(?)) USING (character_id)
			JOIN (SELECT id AS account_id, account, server_type FROM accounts) USING (account_id)
			LEFT JOIN (SELECT id AS group_id FROM profile_groups WHERE name = LOWER(?)) USING (group_id)
			LEFT JOIN (SELECT character_id, class, level FROM personas WHERE class = UPPER(?)) USING (character_id))",
		[&profile](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<unsigned int>
		{
			BindText(stmt, 1, profile.serverName);
			BindText(stmt, 2, profile.characterName);
			BindText(stmt, 3, profile.profileName);
			BindText(stmt, 4, profile.characterClass);

			if (sqlite3_step(stmt) == SQLITE_ROW)
			{
				if (sqlite3_column_type(stmt, 1) != SQLITE_NULL)
					profile.eqPath = ReadText(stmt, 1);
				if (sqlite3_column_type(stmt, 2) != SQLITE_NULL)
					profile.hotkey = ReadText(stmt, 2);
				if (sqlite3_column_type(stmt, 3) != SQLITE_NULL)
					profile.characterLevel = sqlite3_column_int(stmt, 3);

				profile.accountName = ReadText(stmt, 4);
				const std::string pass(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)), sqlite3_column_bytes(stmt, 5));
				if (const auto master_pass = GetMasterPass())
					profile.accountPassword = XorEncryptDecrypt(pass, *master_pass);
				else
					profile.accountPassword = pass;

				if (sqlite3_column_type(stmt, 6) != SQLITE_NULL)
					profile.sortOrder = sqlite3_column_int(stmt, 6);
				else
					profile.sortOrder = 0;

				profile.serverType = ReadText(stmt, 7);

				if (sqlite3_column_type(stmt, 8) != SQLITE_NULL)
					profile.endAfterSelect = sqlite3_column_int(stmt, 8) != 0;

				if (sqlite3_column_type(stmt, 9) != SQLITE_NULL)
					profile.charSelectDelay = sqlite3_column_int(stmt, 9);

				if (sqlite3_column_type(stmt, 10) != SQLITE_NULL)
					profile.customClientIni = ReadText(stmt, 10);

				profile.willLoad = sqlite3_column_int(stmt, 11) != 0;

				return static_cast<unsigned int>(sqlite3_column_int(stmt, 0));
			}

			SPDLOG_ERROR("AutoLogin Error failed to load profile {}, server {}, character {}: {}", profile.profileName, profile.serverName, profile.characterName, sqlite3_errmsg(db));
			return {};
		});
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
	// left join group here to allow for empty group (in the case where you want character/server, and it doesn't matter)
	return WithDb::Query<std::optional<unsigned int>>(SQLITE_OPEN_READONLY,
		R"(
			SELECT p.id, COALESCE(p.eq_path, g.eq_path), hotkey, server_type, account, password, server, character, sort_order, end_after_select, char_select_delay, custom_client_ini
			FROM profiles p
			JOIN (SELECT id AS character_id, character, server, account_id FROM characters) c USING (character_id)
			JOIN (SELECT id AS account_id, account, password, server_type FROM accounts) a USING (account_id)
			JOIN (SELECT id AS group_id, eq_path FROM profile_groups WHERE name = LOWER(?)) g USING (group_id)
			WHERE will_load <> 0
			ORDER BY sort_order ASC
			LIMIT 1)",
		[&profile](sqlite3_stmt* stmt, sqlite3* db) -> std::optional<unsigned int>
		{
			BindText(stmt, 1, profile.profileName);

			if (sqlite3_step(stmt) == SQLITE_ROW)
			{
				if (sqlite3_column_type(stmt, 1) != SQLITE_NULL)
					profile.eqPath = ReadText(stmt, 1);
				if (sqlite3_column_type(stmt, 2) != SQLITE_NULL)
					profile.hotkey = ReadText(stmt, 2);

				profile.serverType = ReadText(stmt, 3);
				profile.accountName = ReadText(stmt, 4);
				const std::string pass(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)), sqlite3_column_bytes(stmt, 5));
				if (const auto master_pass = GetMasterPass())
					profile.accountPassword = XorEncryptDecrypt(pass, *master_pass);
				else
					profile.accountPassword = pass;

				profile.serverName = ReadText(stmt, 6);
				profile.characterName = ReadText(stmt, 7);

				if (sqlite3_column_type(stmt, 8) != SQLITE_NULL)
					profile.sortOrder = sqlite3_column_int(stmt, 8);
				else
					profile.sortOrder = 0;

				if (sqlite3_column_type(stmt, 9) != SQLITE_NULL)
					profile.endAfterSelect = sqlite3_column_int(stmt, 9) != 0;

				if (sqlite3_column_type(stmt, 10) != SQLITE_NULL)
					profile.charSelectDelay = sqlite3_column_int(stmt, 10);

				if (sqlite3_column_type(stmt, 11) != SQLITE_NULL)
					profile.customClientIni = ReadText(stmt, 11);

				return static_cast<unsigned int>(sqlite3_column_int(stmt, 0));
			}

			SPDLOG_ERROR("AutoLogin Error failed to load from profile {}: {}", profile.profileName, sqlite3_errmsg(db));
			return {};
		});
}

void login::db::UpdateProfile(const ProfileRecord& profile)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE,
		R"(
			UPDATE profiles
			SET eq_path = ?,
			    hotkey = ?,
			    sort_order = ?,
			    end_after_select = ?,
			    char_select_delay = ?,
			    custom_client_ini = ?,
				will_load = ?
			WHERE character_id IN (SELECT id FROM characters WHERE server = LOWER(?) AND character = LOWER(?))
			  AND group_id IN (SELECT id FROM profile_groups WHERE name = LOWER(?)))",
		[&profile](sqlite3_stmt* stmt, sqlite3* db)
		{
			if (profile.eqPath)
				BindText(stmt, 1, *profile.eqPath);
			else
				sqlite3_bind_null(stmt, 1);

			BindText(stmt, 2, profile.hotkey);
			sqlite3_bind_int(stmt, 3, static_cast<int>(profile.sortOrder));

			if (profile.endAfterSelect)
				sqlite3_bind_int(stmt, 4, *profile.endAfterSelect ? 1 : 0);
			else
				sqlite3_bind_null(stmt, 4);

			if (profile.charSelectDelay)
				sqlite3_bind_int(stmt, 5, *profile.charSelectDelay);
			else
				sqlite3_bind_null(stmt, 5);

			if (profile.customClientIni)
				BindText(stmt, 6, *profile.customClientIni);
			else
				sqlite3_bind_null(stmt, 6);

			sqlite3_bind_int(stmt, 7, profile.willLoad ? 1 : 0);

			BindText(stmt, 8, profile.serverName);
			BindText(stmt, 9, profile.characterName);
			BindText(stmt, 10, profile.profileName);

			sqlite3_step(stmt);
		});
}

void login::db::DeleteProfile(std::string_view server, std::string_view name, std::string_view group)
{
	WithDb::Query<void>(SQLITE_OPEN_READWRITE,
		R"(
			DELETE FROM profiles
			WHERE character_id IN (SELECT id FROM characters WHERE server = LOWER(?) AND character = LOWER(?))
			  AND group_id IN (SELECT id FROM profile_groups WHERE name = LOWER(?)))",
		[server, name, group](sqlite3_stmt* stmt, sqlite3* db)
		{
			BindText(stmt, 1, server);
			BindText(stmt, 2, name);
			BindText(stmt, 3, group);

			sqlite3_step(stmt);
		});
}
// ================================================================================================================================

std::optional<std::string> login::db::GetEQPath(std::string_view group, std::string_view server, std::string_view name,
	std::string* eqPathFoundWhere)
{
	if (!group.empty())
	{
		if (!server.empty() && !name.empty())
		{
			ProfileRecord profile;
			profile.profileName = group;
			profile.serverName = server;
			profile.characterName = name;
			if (ReadProfile(profile) && profile.eqPath)
			{
				if (eqPathFoundWhere)
					*eqPathFoundWhere = "profile";
				return profile.eqPath;
			}
		}

		ProfileGroup grp;
		grp.profileName = group;
		if (ReadProfileGroup(grp) && grp.eqPath)
		{
			if (eqPathFoundWhere)
				*eqPathFoundWhere = "profile group";
			return grp.eqPath;
		}
	}

	if (!server.empty() && !name.empty())
	{
		ProfileRecord profile;
		profile.serverName = server;
		profile.characterName = name;
		if (ReadAccount(profile) && profile.eqPath)
		{
			if (eqPathFoundWhere)
				*eqPathFoundWhere = "eq installs";
			return profile.eqPath;
		}
	}

	return {};
}

std::vector<ProfileGroup> login::db::GetProfileGroups()
{
	std::vector<ProfileGroup> profile_groups;

	auto groups = WithDb::Query<std::map<unsigned int, ProfileGroup>>(SQLITE_OPEN_READONLY,
		R"(SELECT id, name, eq_path FROM profile_groups ORDER BY sort_order ASC)",
		[](sqlite3_stmt* stmt, sqlite3* db)
		{
			std::map<unsigned int, ProfileGroup> groups;
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				auto id = static_cast<unsigned int>(sqlite3_column_int(stmt, 0));
				const std::string name(ReadText(stmt, 1));

				if (sqlite3_column_type(stmt, 2) == SQLITE_TEXT)
					groups[id] = ProfileGroup{ name, ReadText(stmt, 2), {} };
				else
					groups[id] = ProfileGroup{ name, {}, {} };
			}

			return groups;
		}
	);

	for (auto& group : groups)
	{
		WithDb::Query<void>(SQLITE_OPEN_READONLY,
			R"(
					SELECT DISTINCT a.account, a.password, c.server, c.character, p.hotkey, p.sort_order, p.eq_path,
					    FIRST_VALUE(l.class) OVER (PARTITION BY c.id ORDER BY l.last_seen DESC) AS class,
					    FIRST_VALUE(l.level) OVER (PARTITION BY c.id ORDER BY l.last_seen DESC) AS level,
					    a.server_type, p.end_after_select, p.char_select_delay, p.custom_client_ini, p.will_load
					FROM profiles p
					JOIN characters c ON p.character_id = c.id
					JOIN accounts a ON c.account_id = a.id
					LEFT JOIN personas l ON l.character_id = c.id
					WHERE p.group_id = ?
					ORDER BY p.sort_order ASC)",
			[&id = group.first, &group = group.second](sqlite3_stmt* stmt, sqlite3*)
			{
				sqlite3_bind_int(stmt, 1, static_cast<int>(id));
				while (sqlite3_step(stmt) == SQLITE_ROW)
				{
					ProfileRecord record;
					record.profileName = group.profileName;

					record.accountName = ReadText(stmt, 0);
					const std::string pass(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)), sqlite3_column_bytes(stmt, 1));
					if (auto master_pass = GetMasterPass())
						record.accountPassword = XorEncryptDecrypt(pass, *master_pass);
					else
						record.accountPassword = pass;

					record.serverName = ReadText(stmt, 2);
					record.characterName = ReadText(stmt, 3);

					record.hotkey = ReadText(stmt, 4);

					if (sqlite3_column_type(stmt, 5) != SQLITE_NULL)
						record.sortOrder = sqlite3_column_int(stmt, 5);
					else
						record.sortOrder = 0;

					if (sqlite3_column_type(stmt, 6) != SQLITE_NULL)
						record.eqPath = ReadText(stmt, 6);

					if (sqlite3_column_type(stmt, 7) != SQLITE_NULL)
						record.characterClass = ReadText(stmt, 7);

					if (sqlite3_column_type(stmt, 8) != SQLITE_NULL)
						record.characterLevel = sqlite3_column_int(stmt, 8);

					record.serverType = ReadText(stmt, 9);

					if (sqlite3_column_type(stmt, 10) != SQLITE_NULL)
						record.endAfterSelect = sqlite3_column_int(stmt, 10) != 0;

					if (sqlite3_column_type(stmt, 11) != SQLITE_NULL)
						record.charSelectDelay = sqlite3_column_int(stmt, 11);

					if (sqlite3_column_type(stmt, 12) != SQLITE_NULL)
						record.customClientIni = ReadText(stmt, 12);

					record.willLoad = sqlite3_column_int(stmt, 13) != 0;

					group.records.push_back(std::move(record));
				}
			}
		);

		profile_groups.push_back(std::move(group.second));
	}

	return profile_groups;
}

login::db::Results<std::string> login::db::ListProfileGroupMatches(std::string_view search)
{
	return {
		WithDb::Get(SQLITE_OPEN_READONLY),
		R"(
			SELECT name FROM profile_groups
			WHERE LOWER(name) LIKE '%' || LOWER(?) || '%')",
		[search](sqlite3_stmt* stmt, sqlite3*)
		{
			BindText(stmt, 1, search);
		},
		[](sqlite3_stmt* stmt, sqlite3*)
		{
			return ReadText(stmt, 0);
		}
	};
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

static bool CreateVersion0Schema()
{
	auto query = [](const std::string& query, std::string_view table)
		{
			WithDb::Query<void>(SQLITE_OPEN_READWRITE,
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

	return true;
}

static bool MigrateTableSchema(const std::string& create_query)
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
static bool MigrateVersion1Schema()
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
		  custom_client_ini text,
		  foreign key (character_id) references characters(id) on delete cascade,
		  foreign key (group_id) references profile_groups(id) on delete cascade,
		  unique (character_id, group_id));

		INSERT INTO new_profiles
		SELECT id, character_id, group_id, eq_path, hotkey, null, null, selected, null
		FROM profiles;

		DROP TABLE profiles;

		ALTER TABLE new_profiles RENAME TO profiles;

		CREATE TABLE server_types (
		  type text primary key,
		  eq_path text not null);

		INSERT INTO server_types(type, eq_path)
		SELECT 'import', '' FROM accounts LIMIT 1;

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

// changes the selected column to mean order selected for loading
static bool MigrateVersion2Schema()
{
	return MigrateTableSchema(R"(
		UPDATE profiles
		SET selected = row_number() OVER (PARTITION BY group_id ORDER BY character, server ASC)
		FROM characters c
		WHERE c.id = profiles.character_id AND selected <> 0;
	)");
}

// add a visible column to characters to persist showing in the quick launch
static bool MigrateVersion3Schema()
{
	return MigrateTableSchema(R"(
		ALTER TABLE characters ADD visible INTEGER NOT NULL DEFAULT 1;
	)");
}

// set servers to lower
static bool MigrateVersion4Schema()
{
	return MigrateTableSchema(R"(
		DELETE FROM characters AS c1
		WHERE EXISTS (
			SELECT 1
			FROM characters AS c2
			WHERE LOWER(c1.server) = LOWER(c2.server)
			  AND c1.character = c2.character
			  AND c1.id <> c2.id
			  AND c1.server <> LOWER(c1.server)
		);
		
		UPDATE characters
		SET server = LOWER(server)
		WHERE server <> LOWER(server);
	)");
}

// set server mapping to lower
static bool MigrateVersion5Schema()
{
	return MigrateTableSchema(R"(
		DELETE FROM servers AS s1
		WHERE EXISTS (
			SELECT 1
			FROM servers AS s2
			WHERE LOWER(s1.short_name) = LOWER(s2.short_name)
			  AND LOWER(s1.long_name) = LOWER(s2.long_name)
			  AND s1.id <> s2.id
			  AND s1.short_name <> LOWER(s1.short_name)
			  AND s1.long_name <> LOWER(s1.long_name)
		);

		UPDATE servers
		SET short_name = LOWER(short_name), long_name = LOWER(long_name)
		WHERE short_name <> LOWER(short_name) OR long_name <> LOWER(long_name)
	)");
}

// add more ordering and separate do_load
static bool MigrateVersion6Schema()
{
	return MigrateTableSchema(R"(
		ALTER TABLE profile_groups ADD selected INTEGER NOT NULL DEFAULT 0;

		UPDATE profile_groups
		SET selected = id;

		ALTER TABLE profiles ADD will_load INTEGER NOT NULL DEFAULT 1;

		UPDATE profiles
		SET will_load = 0
		WHERE selected = 0;
	)");
}

// fix up ordering
static bool MigrateVersion7Schema()
{
	return MigrateTableSchema(R"(
		DROP TABLE IF EXISTS profile_groups_new;
		CREATE TABLE profile_groups_new (
		  id integer primary key,
		  name text not null,
		  eq_path text,
		  sort_order integer,
		  last_selected integer not null default (strftime('%s', 'now')),
		  unique (name));

		INSERT INTO profile_groups_new (id, name, eq_path, sort_order)
		SELECT id, name, eq_path, selected AS sort_order
		FROM profile_groups;

		UPDATE profile_groups_new
		SET last_selected = strftime('%s', 'now') + 1
		WHERE id = 1;

		DROP TABLE profile_groups;
		ALTER TABLE profile_groups_new RENAME TO profile_groups;

		CREATE TRIGGER profile_groups_order AFTER INSERT ON profile_groups
		BEGIN
		  UPDATE profile_groups
		  SET sort_order = CASE WHEN s.sort_order IS NULL THEN 1 ELSE s.sort_order + 1 END
		  FROM (SELECT max(sort_order) AS sort_order FROM profile_groups) s
		  WHERE id = new.id AND new.sort_order IS NULL;
		END;

		WITH o AS (
		  SELECT group_id, MAX(selected) AS selected
		  FROM profiles
		  GROUP BY group_id
		)
		UPDATE profiles
		SET selected = row_number() OVER (PARTITION BY p.group_id ORDER BY p.character ASC, p.server ASC) + p.selected
		FROM (
		  SELECT p.id, p.group_id, c.character, c.server, o.selected
		  FROM o
		  JOIN profiles p USING (group_id)
		  JOIN (SELECT id as character_id, character, server FROM characters) c USING (character_id)
		) p
		WHERE profiles.id = p.id AND (profiles.selected IS NULL OR profiles.selected <= 0);

		DROP TABLE IF EXISTS profiles_new;
		CREATE TABLE profiles_new (
		  id integer primary key,
		  character_id integer not null,
		  group_id integer not null,
		  eq_path text,
		  hotkey text,
		  end_after_select integer,
		  char_select_delay integer,
		  custom_client_ini text,
		  sort_order integer,
		  will_load integer not null default 1,
		  foreign key (character_id) references characters(id) on delete cascade,
		  foreign key (group_id) references profile_groups(id) on delete cascade,
		  unique (character_id, group_id));

		INSERT INTO profiles_new (
		  id,
		  character_id,
		  group_id,
		  eq_path,
		  hotkey,
		  end_after_select,
		  char_select_delay,
		  custom_client_ini,
		  sort_order,
		  will_load)
		SELECT
		  id,
		  character_id,
		  group_id,
		  eq_path,
		  hotkey,
		  end_after_select,
		  char_select_delay,
		  custom_client_ini,
		  selected AS sort_order,
		  will_load
		FROM profiles;

		DROP TABLE profiles;
		ALTER TABLE profiles_new RENAME TO profiles;

		CREATE TRIGGER profiles_order AFTER INSERT ON profiles
		BEGIN
		  UPDATE profiles
		  SET sort_order = CASE WHEN s.sort_order IS NULL THEN 1 ELSE s.sort_order + 1 END
		  FROM (SELECT MAX(sort_order) AS sort_order FROM profiles WHERE group_id = new.group_id) s
		  WHERE id = new.id AND new.sort_order IS NULL;
		END;
	)");
}

// sqlite init concurrency should be solved by sqlite, if two processes try to create the db at the same time, one will lock
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
	if (WithDb::Query<std::optional<std::string>>(SQLITE_OPEN_READONLY,
		"SELECT name FROM sqlite_master WHERE type='table' AND name = 'settings'",
		[](sqlite3_stmt* stmt, sqlite3*) -> std::optional<std::string>
		{
			if (sqlite3_step(stmt) == SQLITE_ROW)
				return ReadText(stmt, 0);

			return {};
		}))
		version = CacheSetting<unsigned int>("version", version, GetUIntFromString).Read();

	std::vector<bool(*)()> migrations;
	switch (version)
	{
	case 0:
		migrations.push_back(&CreateVersion0Schema);
		[[fallthrough]];
	case 1:
		migrations.push_back(&MigrateVersion1Schema);
		[[fallthrough]];
	case 2:
		migrations.push_back(&MigrateVersion2Schema);
		[[fallthrough]];
	case 3:
		migrations.push_back(&MigrateVersion3Schema);
		[[fallthrough]];
	case 4:
		migrations.push_back(&MigrateVersion4Schema);
		[[fallthrough]];
	case 5:
		migrations.push_back(&MigrateVersion5Schema);
		[[fallthrough]];
	case 6:
		migrations.push_back(&MigrateVersion6Schema);
		[[fallthrough]];
	case 7:
		migrations.push_back(&MigrateVersion7Schema);
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

void login::db::ShutdownDatabase()
{
	s_connections.clear();
}

