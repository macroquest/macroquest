/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2022 MacroQuest Authors
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

#include <mq/base/String.h>

#include <string>
#include <vector>

#include <windows.h>

// These are replaced with our own wrappers
#undef GetPrivateProfileInt
#undef GetPrivateProfileString
#undef WritePrivateProfileSection
#undef WritePrivateProfileString

namespace mq {

inline float GetPrivateProfileFloat(const std::string& Section, const std::string& Key, const float DefaultValue, const std::string& iniFileName)
{
	const std::string strDefaultValue = std::to_string(DefaultValue);
	const size_t Size = 100;
	char Return[Size] = { 0 };
	::GetPrivateProfileStringA(Section.c_str(), Key.c_str(), strDefaultValue.c_str(), Return, Size, iniFileName.c_str());
	return GetFloatFromString(Return, DefaultValue);
}

inline bool GetPrivateProfileBool(const std::string& Section, const std::string& Key, const bool DefaultValue, const std::string& iniFileName)
{
	const size_t Size = 10;
	char Return[Size] = { 0 };
	::GetPrivateProfileStringA(Section.c_str(), Key.c_str(), DefaultValue ? "true" : "false", Return, Size, iniFileName.c_str());
	return GetBoolFromString(Return, DefaultValue);
}

inline bool GetPrivateProfileBool(const char* Section, const char* Key, const bool DefaultValue, const std::string& iniFileName)
{
	const size_t Size = 10;
	char Return[Size] = { 0 };
	::GetPrivateProfileStringA(Section, Key, DefaultValue ? "true" : "false", Return, Size, iniFileName.c_str());
	return GetBoolFromString(Return, DefaultValue);
}

inline int GetPrivateProfileInt(const std::string& Section, const std::string& Key, const int DefaultValue, const std::string& iniFileName)
{
	return ::GetPrivateProfileIntA(Section.c_str(), Key.c_str(), DefaultValue, iniFileName.c_str());
}

inline int GetPrivateProfileInt(const char* Section, const char* Key, const int DefaultValue, const char* iniFileName)
{
	return ::GetPrivateProfileIntA(Section, Key, DefaultValue, iniFileName);
}

inline int GetPrivateProfileString(const std::string& Section, const std::string& Key, const std::string& DefaultValue, char* Return, const size_t Size, const std::string& iniFileName)
{
	return ::GetPrivateProfileStringA(Section.empty() ? nullptr : Section.c_str(), Key.empty() ? nullptr : Key.c_str(), DefaultValue.c_str(), Return, static_cast<DWORD>(Size), iniFileName.c_str());
}

inline int GetPrivateProfileString(const char* Section, const char* Key, const char* DefaultValue, char* Return, const size_t Size, const char* iniFileName)
{
	return ::GetPrivateProfileStringA(Section, Key, DefaultValue, Return, static_cast<DWORD>(Size), iniFileName);
}

inline std::string GetPrivateProfileString(const std::string& Section, const std::string& Key, const std::string& DefaultValue, const std::string& iniFileName)
{
	char szBuffer[MAX_STRING] = { 0 };

	const DWORD length = ::GetPrivateProfileStringA(Section.empty() ? nullptr : Section.c_str(), Key.empty() ? nullptr : Key.c_str(), DefaultValue.c_str(), szBuffer, MAX_STRING, iniFileName.c_str());
	return std::string{ szBuffer, length };
}

inline std::string GetPrivateProfileString(const char* Section, const char* Key, const char* DefaultValue, const char* iniFileName)
{
	char szBuffer[MAX_STRING] = { 0 };

	const DWORD length = ::GetPrivateProfileStringA(Section, Key, DefaultValue, szBuffer, MAX_STRING, iniFileName);
	return std::string{ szBuffer, length };
}

// GetPrivateProfileValue provides overloads to allow dispatching by type (selected by the type of default value)
inline int GetPrivateProfileValue(const char* Section, const char* Key, int defaultValue, const char* IniFileName) { return GetPrivateProfileInt(Section, Key, defaultValue, IniFileName); }
inline unsigned int GetPrivateProfileValue(const char* Section, const char* Key, unsigned int defaultValue, const char* IniFileName) { return static_cast<unsigned int>(GetPrivateProfileInt(Section, Key, static_cast<int>(defaultValue), IniFileName)); }
inline float GetPrivateProfileValue(const char* Section, const char* Key, float defaultValue, const char* IniFileName) { return GetPrivateProfileFloat(Section, Key, defaultValue, IniFileName); }
inline bool GetPrivateProfileValue(const char* Section, const char* Key, bool defaultValue, const char* IniFileName) { return GetPrivateProfileBool(Section, Key, defaultValue, IniFileName); }
inline std::string GetPrivateProfileValue(const char* Section, const char* Key, const char* defaultValue, const char* IniFileName) { return GetPrivateProfileString(Section, Key, defaultValue, IniFileName); }
inline std::string GetPrivateProfileValue(const char* Section, const char* Key, const std::string& defaultValue, const char* IniFileName) { return GetPrivateProfileString(Section, Key, defaultValue.c_str(), IniFileName); }

template <typename T>
inline auto GetPrivateProfileValue(const std::string& Section, const std::string& Key, T defaultValue, const char* IniFileName)
{
	return GetPrivateProfileValue(Section.c_str(), Key.c_str(), defaultValue, IniFileName);
}

template <size_t BUFFER_SIZE = MAX_STRING>
inline std::vector<std::string> GetPrivateProfileKeys(const std::string& section, const std::string& iniFileName)
{
	char keybuffer[BUFFER_SIZE] = { 0 };

	const int bufferLen = ::GetPrivateProfileStringA(section.c_str(), nullptr, "", keybuffer, BUFFER_SIZE, iniFileName.c_str());
	char* ptr = keybuffer;

	std::vector<std::string> results;

	while (ptr < keybuffer + bufferLen)
	{
		std::string keyName = ptr;
		ptr += keyName.length() + 1;

		results.push_back(std::move(keyName));
	}

	return results;
}

template <size_t BUFFER_SIZE = MAX_STRING>
inline std::vector<std::string> GetPrivateProfileSections(const std::string& iniFileName)
{
	char sectionbuffer[BUFFER_SIZE] = { 0 };

	const int bufferLen = ::GetPrivateProfileSectionNamesA(sectionbuffer, BUFFER_SIZE, iniFileName.c_str());
	char* ptr = sectionbuffer;

	std::vector<std::string> results;

	while (ptr < sectionbuffer + bufferLen)
	{
		std::string keyName = ptr;
		ptr += keyName.length() + 1;

		results.push_back(std::move(keyName));
	}

	return results;
}

inline bool WritePrivateProfileSection(const std::string& Section, const std::string& KeysAndValues, const std::string& iniFileName)
{
	return ::WritePrivateProfileSectionA(Section.c_str(), KeysAndValues.c_str(), iniFileName.c_str());
}

inline bool WritePrivateProfileSection(const char* Section, const char* KeysAndValues, const char* iniFileName)
{
	return ::WritePrivateProfileSectionA(Section, KeysAndValues, iniFileName);
}

inline bool WritePrivateProfileString(const std::string& Section, const std::string& Key, const std::string& Value, const std::string& iniFileName)
{
	return ::WritePrivateProfileStringA(Section.c_str(), Key.c_str(), Value.c_str(), iniFileName.c_str());
}

inline bool WritePrivateProfileString(const char* Section, const char* Key, const char* Value, const char* iniFileName)
{
	return ::WritePrivateProfileStringA(Section, Key, Value, iniFileName);
}

inline bool WritePrivateProfileBool(const std::string& Section, const std::string& Key, bool Value, const std::string& iniFileName)
{
	return ::WritePrivateProfileStringA(Section.c_str(), Key.c_str(), Value ? "1" : "0", iniFileName.c_str());
}

inline bool WritePrivateProfileBool(const char* Section, const char* Key, bool Value, const char* iniFileName)
{
	return ::WritePrivateProfileStringA(Section, Key, Value ? "1" : "0", iniFileName);
}

inline bool WritePrivateProfileInt(const std::string& Section, const std::string& Key, int Value, const std::string& iniFileName)
{
	std::string ValueString = std::to_string(Value);
	return ::WritePrivateProfileStringA(Section.c_str(), Key.c_str(), ValueString.c_str(), iniFileName.c_str());
}

inline bool WritePrivateProfileInt(const char* Section, const char* Key, int Value, const char* iniFileName)
{
	std::string ValueString = std::to_string(Value);
	return ::WritePrivateProfileStringA(Section, Key, ValueString.c_str(), iniFileName);
}

inline bool WritePrivateProfileFloat(const std::string& Section, const std::string& Key, float Value, const std::string& iniFileName)
{
	std::string ValueString = std::to_string(Value);
	return ::WritePrivateProfileStringA(Section.c_str(), Key.c_str(), ValueString.c_str(), iniFileName.c_str());
}

inline bool WritePrivateProfileFloat(const char* Section, const char* Key, float Value, const char* iniFileName)
{
	std::string ValueString = std::to_string(Value);
	return ::WritePrivateProfileStringA(Section, Key, ValueString.c_str(), iniFileName);
}

inline bool DeletePrivateProfileKey(const std::string& Section, const std::string& Key, const std::string& iniFileName)
{
	return ::WritePrivateProfileStringA(Section.c_str(), Key.c_str(), nullptr, iniFileName.c_str());
}

// WritePrivateProfileValue provides overloads to allow dispatching by type (selected by the type of default value)
inline bool WritePrivateProfileValue(const char* Section, const char* Key, int Value, const char* IniFileName) { return WritePrivateProfileInt(Section, Key, Value, IniFileName); }
inline bool WritePrivateProfileValue(const char* Section, const char* Key, unsigned int Value, const char* IniFileName) { return WritePrivateProfileInt(Section, Key, static_cast<int>(Value), IniFileName); }
inline bool WritePrivateProfileValue(const char* Section, const char* Key, float Value, const char* IniFileName) { return WritePrivateProfileFloat(Section, Key, Value, IniFileName); }
inline bool WritePrivateProfileValue(const char* Section, const char* Key, bool Value, const char* IniFileName) { return WritePrivateProfileBool(Section, Key, Value, IniFileName); }
inline bool WritePrivateProfileValue(const char* Section, const char* Key, const char* Value, const char* IniFileName) { return WritePrivateProfileString(Section, Key, Value, IniFileName); }
inline bool WritePrivateProfileValue(const char* Section, const char* Key, const std::string& Value, const char* IniFileName) { return WritePrivateProfileString(Section, Key, Value.c_str(), IniFileName); }

template <typename T>
inline auto WritePrivateProfileValue(const std::string& Section, const std::string& Key, T Value, const char* IniFileName)
{
	return WritePrivateProfileValue(Section.c_str(), Key.c_str(), Value, IniFileName);
}

} // namespace mq
