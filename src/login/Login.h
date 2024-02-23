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

#pragma once

#include <filesystem>

#include "Login.pb.h"

#include <optional>

#ifdef _DEBUG
#pragma comment(lib, "libprotobufd")
#else
#pragma comment(lib, "libprotobuf")
#endif

#pragma comment(lib, "login")

struct ProfileRecord
{
	std::string profileName; // this is the group of characters
	std::string serverName;
	std::string serverType;

	std::string accountName;
	std::string accountPassword;
	std::string characterName;

	std::string hotkey;
	std::string characterClass;
	int characterLevel = 0;

	std::optional<std::string> eqPath;
	unsigned int sortOrder = 0;
	bool willLoad = true;
	bool visible = true;

	std::optional<bool> endAfterSelect;
	std::optional<int> charSelectDelay;
	std::optional<std::string> customClientIni;

	static ProfileRecord FromString(const std::string& input);
	static ProfileRecord FromBlob(const std::string& blob);

	void FormatTo(char* buffer, size_t length) const;

	[[nodiscard]] std::string ToString() const;
};

struct ProfileGroup
{
	std::string profileName;
	std::optional<std::string> eqPath;
	std::vector<ProfileRecord> records;

	unsigned int selected = 0;
};

std::vector<ProfileGroup> LoadAutoLoginProfiles(const std::string& ini_file_name, std::string_view server_type);

struct sqlite3;
struct sqlite3_stmt;
class WithDb;
namespace login::db {

// ReadDataVersion uses the SQLITE_OPEN_READONLY connection, so any READWRITE connection results can't be cached
// This means that the read version will be guaranteed to change each time the DB is written to
int ReadDataVersion();
template <typename T> class Cache
{
public:
	using Result = std::invoke_result_t<T>;
	using UpdateCache = std::function<Result()>;

	explicit Cache(const T& update)
		: m_update(update)
		, m_value(m_update())
		, m_updatedValue(m_value)
		, m_dataVersion(ReadDataVersion())
	{}

	Result& Read(const bool force = false)
	{
		if (HasChanges() || force)
		{
			m_value = m_update();
			m_updatedValue = m_value;
		}

		return m_updatedValue;
	}

	bool ReadHasChanged(const bool force = false)
	{
		if (HasChanges() || force)
		{
			m_value = m_update();
			m_updatedValue = m_value;
			return true;
		}

		return false;
	}

	Result& Updated() { return m_updatedValue; }

private:
	bool HasChanges()
	{
		if (const int latest = ReadDataVersion(); latest != m_dataVersion)
		{
			m_dataVersion = latest;
			return true;
		}

		return false;
	}

	UpdateCache m_update;
	Result m_value;
	Result m_updatedValue;
	int m_dataVersion;
};

class StatementHelper
{
public:
	StatementHelper(
		const std::shared_ptr<WithDb>& db,
		const std::string& query,
		const std::function<void(sqlite3_stmt*, sqlite3*)>& bind);
	~StatementHelper();

	[[nodiscard]] bool Step() const;

	template <typename T>
	T Result(const std::function<T(sqlite3_stmt*, sqlite3*)>& result) const { return result(m_stmt, m_db); }

	StatementHelper(const StatementHelper&) = delete;
	StatementHelper(StatementHelper&&) = delete;
	StatementHelper& operator=(const StatementHelper&) = delete;
	StatementHelper& operator=(StatementHelper&&) = delete;

private:
	sqlite3* m_db;
	sqlite3_stmt* m_stmt;
};

template <typename T>
class Results
{
public:
	using Type = T;

	class Iterator
	{
	public:
		using iterator_category = std::input_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T const;
		using pointer = T const* const;
		using reference = T const&;

		explicit Iterator(Results const* results)
			: m_done(false)
			, m_results(results)
		{
			m_done = m_results->m_stmt.Step();
			if (!m_done)
				m_current = m_results->m_stmt.Result(m_results->m_result);
		}

		explicit operator bool() const { return !m_done; }

		reference operator*() const { return m_current; }
		pointer operator->() const { return &m_current; }

		Iterator& operator++()
		{
			assert(!m_done);

			m_done = m_results->m_stmt.Step();
			if (!m_done)
				m_current = m_results->m_stmt.Result(m_results->m_result);

			return *this;
		}

		friend bool operator==(Iterator l, Iterator r) { return l.m_current == r.m_current; }
		friend bool operator!=(Iterator l, Iterator r) { return !(l == r); }

		class Sentinel {};
		friend bool operator==(Iterator it, Sentinel) { return it.m_done; }
		friend bool operator!=(Iterator it, Sentinel) { return !(it == Sentinel{}); }
		friend bool operator==(Sentinel, Iterator it) { return it == Sentinel{}; }
		friend bool operator!=(Sentinel, Iterator it) { return it != Sentinel{}; }

	private:
		bool m_done;
		T m_current;
		Results const* m_results;
	};

	Results(
		const std::shared_ptr<WithDb>& db,
		const std::string& query,
		const std::function<void(sqlite3_stmt*, sqlite3*)>& bind,
		const std::function<T(sqlite3_stmt*, sqlite3*)>& result)
		: m_db(db)
		, m_stmt(db, query, bind)
		, m_result(result)
	{}

	[[nodiscard]] Iterator begin() const { return Iterator(this); }
	[[nodiscard]] typename Iterator::Sentinel end() const { return Iterator::Sentinel{}; }

	[[nodiscard]] std::vector<T> vector() const
	{
		std::vector<T> vec; // we don't know the size, so we can't reserve
		for (auto t : *this)
			vec.emplace_back(std::move(t));
		return vec;
	}

private:
	std::shared_ptr<WithDb> m_db;
	StatementHelper m_stmt;
	std::function<T(sqlite3_stmt*, sqlite3*)> m_result;
};

// wrap the cache system for results because they generically need to be transformed
// into a vector

template <typename T>
using ResultsVector = std::function<std::vector<typename std::invoke_result_t<T>::Type>()>;

template <typename T>
Cache<ResultsVector<T>>
CacheResults(const T& update)
{
	return Cache<ResultsVector<T>>([update]
		{
			return update().vector();
		});
}

bool ValidatePass(std::string_view pass);

void MemoizeMasterPass(std::string_view pass);
std::optional<std::string> GetMasterPass();

void CacheMasterPass(std::string_view pass);
bool CreateMasterPass(std::string_view pass);
std::optional<std::string> ReadStoredMasterPass();
bool ReadMasterPassExpired();
std::optional<std::string> ReadMasterPass();
void UpdateEncryptedData(std::string_view old_pass);

void WriteSetting(std::string_view key, std::string_view value, std::optional<std::string_view> description = {});
std::optional<std::string> ReadSetting(std::string_view key);
void DeleteSetting(std::string_view key);

template <typename T>
Cache<std::function<T()>> CacheSetting(
	const std::string_view setting,
	const T default_value,
	const std::function<T(const std::string_view, const T)>& parse_func)
{
	return Cache<std::function<T()>>(
		[setting, default_value, parse_func]
		{
			if (const auto value = ReadSetting(setting))
				return parse_func(*value, default_value);
			return default_value;
		});
}

Results<std::string> ListProfileGroups();
void CreateProfileGroup(const ProfileGroup& group);
std::optional<unsigned int> ReadProfileGroup(ProfileGroup& group);
void UpdateProfileGroup(std::string_view name, const ProfileGroup& group);
void DeleteProfileGroup(std::string_view name);

Results<std::pair<std::string, std::string>> ListAccounts();
login::db::Results<ProfileRecord> ListAccountMatches(std::string_view search);
void CreateAccount(const ProfileRecord& profile);
std::optional<std::string> ReadAccount(ProfileRecord& profile);
std::optional<std::string> ReadPassword(std::string_view account, std::string_view server_type, std::optional<std::string_view> password_override = {});
void UpdateAccount(std::string_view account, std::string_view server_type, const ProfileRecord& record);
void DeleteAccount(std::string_view account, std::string_view server_type);

Results<std::pair<std::string, std::string>> ListCharacters(std::string_view account, std::string_view server_type);
Results<std::string> ListServers();
Results<ProfileRecord> ListCharactersOnServer(std::string_view server);
Results<ProfileRecord> ListCharacterMatches(std::string_view search);
void CreateCharacter(const ProfileRecord& profile);
std::optional<unsigned int> ReadCharacter(ProfileRecord& profile);
void UpdateCharacter(std::string_view server, std::string_view name, const ProfileRecord& profile);
void DeleteCharacter(std::string_view server, std::string_view name);

void CreatePersona(const ProfileRecord& profile);
std::optional<unsigned int> ReadPersona(ProfileRecord& profile);
void UpdatePersona(std::string_view cls, const ProfileRecord& profile);
void DeletePersona(std::string_view server, std::string_view name, std::string_view cls);

void CreateOrUpdateServer(std::string_view short_name, std::string_view long_name);
Results<std::pair<std::string, std::string>> ListServerNames();
Results<std::pair<std::string, std::string>> ListServerMatches(std::string_view search);
Results<std::string> ReadLongServer(std::string_view short_name);
std::optional<std::string> ReadShortServer(std::string_view long_name);
void DeleteServer(std::string_view short_name, std::string_view long_name);

void CreateOrUpdateServerType(std::string_view server_type, std::string_view eq_path);
Results<std::string> ListServerTypes();
std::optional<std::string> GetPathFromServerType(std::string_view server_type);
std::optional<std::string> GetServerTypeFromPath(std::string_view path);
void DeleteServerType(std::string_view server_type);

Results<ProfileRecord> GetProfiles(std::string_view group);
std::vector<ProfileRecord> GetActiveProfiles(std::string_view group);
void CreateProfile(const ProfileRecord& profile);
std::optional<unsigned int> ReadProfile(ProfileRecord& profile);
std::optional<unsigned int> ReadFullProfile(ProfileRecord& profile);
std::optional<unsigned int> ReadFullProfile(std::string_view group, std::string_view server, std::string_view name, ProfileRecord& profile);
std::optional<unsigned int> ReadFirstProfile(ProfileRecord& profile);
void UpdateProfile(const ProfileRecord& profile);
void DeleteProfile(std::string_view server, std::string_view name, std::string_view group);

std::optional<std::string> GetEQPath(std::string_view group, std::string_view server, std::string_view name);
std::vector<ProfileGroup> GetProfileGroups();
Results<std::string> ListProfileGroupMatches(std::string_view search);
void WriteProfileGroups(const std::vector<ProfileGroup>& groups, std::string_view eq_path);
bool InitDatabase(const std::string& path);
void ShutdownDatabase();
} // namespace login::db
