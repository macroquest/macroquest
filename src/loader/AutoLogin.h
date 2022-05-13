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

#include <string>

#include <Windows.h>

struct ProfileInfo
{
	std::string profileName;
	std::string CharacterName;
	std::string Inifile;
	std::string Hotkey;
	std::string PlayerClass;
	bool Loaded = false;
	DWORD PID = 0;
	DWORD PlayerLevel = 0;
};

struct RawProfileRecord
{
	std::string profileName;
	std::string serverName;
	std::string characterName;

	std::string eqPath;
	std::string encryptedBlob;
	bool checked;
};

struct ExportEntry
{
	std::string profileKey;
	std::string profile;
	std::string keyName;
	std::string eqPath;
	bool checked;
	std::string blob;

};

extern HWND hEditProfileWnd;

void InitializeAutoLogin();
void ShutdownAutoLogin();
void AutoLoginRemoveProcess(DWORD processId);

// IPC messages
void HandleAutoLoginProfileLoaded(std::string_view szMessage);
void HandleAutoLoginProfileUnloaded(std::string_view szMessage);
void HandleAutoLoginMQ2Unload(std::string_view szMessage);
void HandleAutoLoginUpdateCharacterDetails(std::string_view szMessage);
void HandleAutoLoginStartInstance(std::string_view szMessage);

void ShowImportDialog();
void ShowNewProfileDlg();

bool HandleAutoLoginWindowMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, LRESULT* result);
void LoadProfiles();

