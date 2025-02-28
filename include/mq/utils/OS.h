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

#include "mq/base/String.h"

#include <TlHelp32.h>
#include <Psapi.h>

#include <wil/resource.h>

namespace mq {

inline bool IsProcessRunning(std::string_view exeName)
{
	wil::unique_tool_help_snapshot hSnapshot(CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0));

	PROCESSENTRY32 proc = { sizeof(PROCESSENTRY32) };
	if (Process32First(hSnapshot.get(), &proc))
	{
		do
		{
			if (ci_equals(proc.szExeFile, exeName))
			{
				return true;
			}
		} while (Process32Next(hSnapshot.get(), &proc));
	}

	return false;
}

inline bool IsInModuleList(const char* moduleName, int processID = GetCurrentProcessId())
{
	const wil::unique_process_handle process(OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, false, processID));
	if (process.is_valid())
	{
		HMODULE hMods[1024];
		DWORD cbNeeded;
		if(EnumProcessModules(process.get(), hMods, sizeof(hMods), &cbNeeded))
		{
			for (DWORD i = 0; i < (cbNeeded / sizeof(HMODULE)); ++i)
			{
				char szModName[MAX_PATH];
				if (GetModuleFileNameEx(process.get(), hMods[i], szModName, sizeof(szModName) / sizeof(char)))
				{
					const std::filesystem::path mod_path = szModName;
					if (ci_equals(mod_path.filename().string(), moduleName) || ci_equals(mod_path.stem().string(), moduleName))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

} // namespace mq