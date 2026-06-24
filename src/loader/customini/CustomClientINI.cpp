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

#include "mq/base/String.h"

#include <Windows.h>

// The resolved custom ini path parsed from the command line. Empty means inactive.
static std::string s_customIni = {};

/**
 * @fn IsEqClientIni
 *
 * @brief Tests whether a file name refers to eqclient.ini.
 *
 * @param fileName the file name to test
 * @return true if fileName refers to eqclient.ini, false otherwise
 */
static bool IsEqClientIni(const char* fileName)
{
	return fileName != nullptr && mq::ci_find_substr(fileName, "eqclient.ini") != -1;
}

// ---------------------------------------------------------------------------
// Hooks - swap in the custom path then call through to the original function.
// ---------------------------------------------------------------------------

using GetPrivateProfileStringA_t = DWORD(WINAPI*)(LPCSTR, LPCSTR, LPCSTR, LPSTR, DWORD, LPCSTR);
using GetPrivateProfileIntA_t = UINT(WINAPI*)(LPCSTR, LPCSTR, INT, LPCSTR);
using WritePrivateProfileStringA_t = BOOL(WINAPI*)(LPCSTR, LPCSTR, LPCSTR, LPCSTR);
using CreateFileA_t = HANDLE(WINAPI*)(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);

static GetPrivateProfileStringA_t s_origGetString = &::GetPrivateProfileStringA;
static GetPrivateProfileIntA_t s_origGetInt = &::GetPrivateProfileIntA;
static WritePrivateProfileStringA_t s_origWriteString = &::WritePrivateProfileStringA;
static CreateFileA_t s_origCreateFileA = &::CreateFileA;

static DWORD WINAPI Hook_GetPrivateProfileStringA(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpDefault, LPSTR lpReturnedString, DWORD nSize, LPCSTR lpFileName)
{
	if (!s_customIni.empty() && IsEqClientIni(lpFileName))
		lpFileName = s_customIni.c_str();

	return s_origGetString(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName);
}

static UINT WINAPI Hook_GetPrivateProfileIntA(LPCSTR lpAppName, LPCSTR lpKeyName, INT nDefault, LPCSTR lpFileName)
{
	if (!s_customIni.empty() && IsEqClientIni(lpFileName))
		lpFileName = s_customIni.c_str();

	return s_origGetInt(lpAppName, lpKeyName, nDefault, lpFileName);
}

static BOOL WINAPI Hook_WritePrivateProfileStringA(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpString, LPCSTR lpFileName)
{
	if (!s_customIni.empty() && IsEqClientIni(lpFileName))
		lpFileName = s_customIni.c_str();

	return s_origWriteString(lpAppName, lpKeyName, lpString, lpFileName);
}

static HANDLE WINAPI Hook_CreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
{
	if (!s_customIni.empty() && IsEqClientIni(lpFileName))
		lpFileName = s_customIni.c_str();

	return s_origCreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
}

// ---------------------------------------------------------------------------
// Command line parsing
// ---------------------------------------------------------------------------

/**
 * @fn ParseCustomIniArg
 *
 * @brief Parses the custom ini path from the process command line.
 *
 * Looks for a "/customini:" token (case-insensitive) and returns the value that
 * follows it, with surrounding quotes removed.
 *
 * @return the custom ini path, or an empty string if the token is not present
 */
static std::string ParseCustomIniArg()
{
	const char* cmdLine = ::GetCommandLineA();
	if (cmdLine != nullptr)
	{
		constexpr std::string_view token = "/customini:";

		const std::string_view command = cmdLine;
		const int pos = mq::ci_find_substr(command, token);
		if (pos != -1)
		{
			std::string_view value = command.substr(pos + token.length());

			// If there's a quote assume this is a quoted string
			if (!value.empty() && value.front() == '"')
			{
				value.remove_prefix(1);
				value = value.substr(0, value.find('"'));
			}
			// Otherwise end on the next space (or length from above)
			else
			{
				value = value.substr(0, value.find_first_of(" "));
			}

			return std::string(value);
		}
	}
	return {};
}

// ---------------------------------------------------------------------------
// IAT hooking
// ---------------------------------------------------------------------------

/**
 * @fn PatchImportsForModule
 *
 * @brief Installs the redirect hooks by patching a module's Import Address Table.
 *
 * Walks the module's import descriptors and, for every named import matching one
 * of our target functions, saves the original resolved address and overwrites the
 * IAT slot with the address of our hook. Imports by ordinal are skipped. The function
 * is a no-op if the module has no valid PE headers or no import directory.
 *
 * @param hModule base address (HMODULE) of the loaded module to patch
 */
static void PatchImportsForModule(HMODULE hModule)
{
	auto base = reinterpret_cast<BYTE*>(hModule);

	auto dosHeader = reinterpret_cast<IMAGE_DOS_HEADER*>(base);
	if (dosHeader->e_magic == IMAGE_DOS_SIGNATURE)
	{
		auto ntHeaders = reinterpret_cast<IMAGE_NT_HEADERS*>(base + dosHeader->e_lfanew);
		if (ntHeaders->Signature == IMAGE_NT_SIGNATURE)
		{
			const IMAGE_DATA_DIRECTORY& importDir = ntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
			if (importDir.VirtualAddress != 0 && importDir.Size != 0)
			{
				auto importDesc = reinterpret_cast<IMAGE_IMPORT_DESCRIPTOR*>(base + importDir.VirtualAddress);

				// The import descriptor array is terminated by an all-zero entry (Name == 0)
				while (importDesc->Name != 0)
				{
					auto nameThunk = reinterpret_cast<IMAGE_THUNK_DATA*>(base + (importDesc->OriginalFirstThunk ? importDesc->OriginalFirstThunk : importDesc->FirstThunk));
					auto addrThunk = reinterpret_cast<IMAGE_THUNK_DATA*>(base + importDesc->FirstThunk);

					// Both thunk arrays are terminated by a zero entry
					while (nameThunk->u1.AddressOfData != 0)
					{
						// Only consider named imports - our targets are imported by name, not ordinal.
						if (!IMAGE_SNAP_BY_ORDINAL(nameThunk->u1.Ordinal))
						{
							auto importByName = reinterpret_cast<IMAGE_IMPORT_BY_NAME*>(base + nameThunk->u1.AddressOfData);
							const char* fnName = reinterpret_cast<const char*>(importByName->Name);

							// Remember the original (resolved) address so our hook can call through, and pick our
							// replacement. Addresses are handled as ULONG_PTR (arch-width) to match the IAT slot.
							const ULONG_PTR original = addrThunk->u1.Function;
							ULONG_PTR hook = 0;

							if (lstrcmpiA(fnName, "GetPrivateProfileStringA") == 0)
							{
								s_origGetString = reinterpret_cast<GetPrivateProfileStringA_t>(original);
								hook = reinterpret_cast<ULONG_PTR>(&Hook_GetPrivateProfileStringA);
							}
							else if (lstrcmpiA(fnName, "GetPrivateProfileIntA") == 0)
							{
								s_origGetInt = reinterpret_cast<GetPrivateProfileIntA_t>(original);
								hook = reinterpret_cast<ULONG_PTR>(&Hook_GetPrivateProfileIntA);
							}
							else if (lstrcmpiA(fnName, "WritePrivateProfileStringA") == 0)
							{
								s_origWriteString = reinterpret_cast<WritePrivateProfileStringA_t>(original);
								hook = reinterpret_cast<ULONG_PTR>(&Hook_WritePrivateProfileStringA);
							}
							else if (lstrcmpiA(fnName, "CreateFileA") == 0)
							{
								s_origCreateFileA = reinterpret_cast<CreateFileA_t>(original);
								hook = reinterpret_cast<ULONG_PTR>(&Hook_CreateFileA);
							}

							// Overwrite the IAT slot with our hook.
							if (hook != 0)
							{
								DWORD oldProtect = 0;
								if (::VirtualProtect(&addrThunk->u1.Function, sizeof(addrThunk->u1.Function), PAGE_READWRITE, &oldProtect))
								{
									addrThunk->u1.Function = hook;
									::VirtualProtect(&addrThunk->u1.Function, sizeof(addrThunk->u1.Function), oldProtect, &oldProtect);
								}
							}
						}
						++nameThunk;
						++addrThunk;
					}
					++importDesc;
				}
			}
		}
	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID /*reserved*/)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		::DisableThreadLibraryCalls(hModule);

		s_customIni = ParseCustomIniArg();
		
		if (!s_customIni.empty())
			PatchImportsForModule(::GetModuleHandleA(nullptr));
	}

	return TRUE;
}
