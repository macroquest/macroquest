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

#include "MacroQuest.h"
#include "resource.h"

#include <wil/resource.h>
#include <spdlog/spdlog.h>
#include <fmt/chrono.h>
#include <fmt/os.h>

#include <chrono>
#include <condition_variable>
#include <filesystem>
#include <thread>
#include <mutex>

#define _PEPARSE_WINDOWS_CONFLICTS
#include <pe-parse/parse.h>

namespace fs = std::filesystem;
using namespace std::chrono_literals;

static std::thread s_injectorThread;
static std::condition_variable s_cv;
static std::mutex s_mutex;
static std::atomic_bool s_injectorRunning = false;

// Delay before a process is injected.
const std::chrono::milliseconds NEW_PROCESS_INJECTION_DELAY_MS = 1s;

const std::string s_mainDLL = "MQ2Main.dll";

struct InjectRequest
{
	// The id of the request
	uint32_t id = 0;

	// The id of the process
	uint32_t processId;

	// number of retries we should attempt
	int retries = 0;

	// timepoint when we should perform the injection.
	std::chrono::steady_clock::time_point injectTime;
};

static std::vector<InjectRequest> s_injectRequests;

using ParsedPeRef = std::unique_ptr<peparse::parsed_pe, void (*)(peparse::parsed_pe*)>;

ParsedPeRef openExecutable(const std::string& path)
{
	// The factory function does not throw exceptions!
	ParsedPeRef obj(peparse::ParsePEFromFile(path.data()),
		peparse::DestructParsedPE);
	if (!obj)
	{
		return ParsedPeRef(nullptr, peparse::DestructParsedPE);
	}

	return obj;
}


enum class AddressType {
	PhysicalOffset,
	RelativeVirtualAddress,
	VirtualAddress
};

bool convertAddress(ParsedPeRef& pe,
	uintptr_t address,
	AddressType source_type,
	AddressType destination_type,
	uintptr_t& result) noexcept {
	if (source_type == destination_type) {
		result = address;
		return true;
	}

	uintptr_t image_base_address = 0U;
	if (pe->peHeader.nt.FileHeader.Machine == IMAGE_FILE_MACHINE_AMD64) {
#ifdef _WIN64
		image_base_address = pe->peHeader.nt.OptionalHeader64.ImageBase;
#else
		image_base_address = pe->peHeader.nt.OptionalHeader.ImageBase;
#endif
	}
	else {
		image_base_address = pe->peHeader.nt.OptionalHeader.ImageBase;
	}

	struct SectionAddressLimits final {
		uintptr_t lowest_rva;
		uintptr_t lowest_offset;

		uintptr_t highest_rva;
		uintptr_t highest_offset;
	};

	auto L_getSectionAddressLimits = [](void* N,
		const peparse::VA& secBase,
		const std::string& secName,
		const peparse::image_section_header& s,
		const peparse::bounded_buffer* data) -> int {
			static_cast<void>(secBase);
			static_cast<void>(secName);
			static_cast<void>(data);

			SectionAddressLimits* section_address_limits =
				static_cast<SectionAddressLimits*>(N);

			section_address_limits->lowest_rva =
				std::min(section_address_limits->lowest_rva,
					static_cast<uintptr_t>(s.VirtualAddress));

			section_address_limits->lowest_offset =
				std::min(section_address_limits->lowest_offset,
					static_cast<uintptr_t>(s.PointerToRawData));

			uintptr_t sectionSize;
			if (s.SizeOfRawData != 0) {
				sectionSize = s.SizeOfRawData;
			}
			else {
				sectionSize = s.Misc.VirtualSize;
			}

			section_address_limits->highest_rva =
				std::max(section_address_limits->highest_rva,
					static_cast<uintptr_t>(s.VirtualAddress + sectionSize));

			section_address_limits->highest_offset =
				std::max(section_address_limits->highest_offset,
					static_cast<uintptr_t>(s.PointerToRawData + sectionSize));

			return 0;
	};

	SectionAddressLimits section_address_limits = {
		std::numeric_limits<uintptr_t>::max(),
		std::numeric_limits<uintptr_t>::max(),
		std::numeric_limits<uintptr_t>::min(),
		std::numeric_limits<uintptr_t>::min() };

	IterSec(pe.get(), L_getSectionAddressLimits, &section_address_limits);

	switch (source_type) {
	case AddressType::PhysicalOffset: {
		if (address >= section_address_limits.highest_offset) {
			return false;
		}

		if (destination_type == AddressType::RelativeVirtualAddress) {
			struct CallbackData final {
				bool found;
				uintptr_t address;
				uintptr_t result;
			};

			auto L_inspectSection = [](void* N,
				const peparse::VA& secBase,
				const std::string& secName,
				const peparse::image_section_header& s,
				const peparse::bounded_buffer* data) -> int {
					static_cast<void>(secBase);
					static_cast<void>(secName);
					static_cast<void>(data);

					uintptr_t sectionBaseOffset = s.PointerToRawData;

					uintptr_t sectionEndOffset = sectionBaseOffset;
					if (s.SizeOfRawData != 0) {
						sectionEndOffset += s.SizeOfRawData;
					}
					else {
						sectionEndOffset += s.Misc.VirtualSize;
					}

					auto callback_data = static_cast<CallbackData*>(N);
					if (callback_data->address >= sectionBaseOffset &&
						callback_data->address < sectionEndOffset) {
						callback_data->result = s.VirtualAddress + (callback_data->address -
							s.PointerToRawData);

						callback_data->found = true;
						return 1;
					}

					return 0;
			};

			CallbackData callback_data = { false, address, 0U };
			IterSec(pe.get(), L_inspectSection, &callback_data);

			if (!callback_data.found) {
				return false;
			}

			result = callback_data.result;
			return true;

		}
		else if (destination_type == AddressType::VirtualAddress) {
			uintptr_t rva = 0U;
			if (!convertAddress(pe,
				address,
				source_type,
				AddressType::RelativeVirtualAddress,
				rva)) {
				return false;
			}

			result = image_base_address + rva;
			return true;
		}

		return false;
	}

	case AddressType::RelativeVirtualAddress: {
		if (address < section_address_limits.lowest_rva) {
			result = address;
			return true;
		}
		else if (address >= section_address_limits.highest_rva) {
			return false;
		}

		if (destination_type == AddressType::PhysicalOffset) {
			struct CallbackData final {
				bool found;
				uintptr_t address;
				uintptr_t result;
			};

			auto L_inspectSection = [](void* N,
				const peparse::VA& secBase,
				const std::string& secName,
				const peparse::image_section_header& s,
				const peparse::bounded_buffer* data) -> int {
					static_cast<void>(secBase);
					static_cast<void>(secName);
					static_cast<void>(data);

					uintptr_t sectionBaseAddress = s.VirtualAddress;
					uintptr_t sectionEndAddress =
						sectionBaseAddress + s.Misc.VirtualSize;

					auto callback_data = static_cast<CallbackData*>(N);
					if (callback_data->address >= sectionBaseAddress &&
						callback_data->address < sectionEndAddress) {
						callback_data->result =
							s.PointerToRawData +
							(callback_data->address - sectionBaseAddress);

						callback_data->found = true;
						return 1;
					}

					return 0;
			};

			CallbackData callback_data = { false, address, 0U };
			IterSec(pe.get(), L_inspectSection, &callback_data);

			if (!callback_data.found) {
				return false;
			}

			result = callback_data.result;
			return true;

		}
		else if (destination_type == AddressType::VirtualAddress) {
			result = image_base_address + address;
			return true;
		}

		return false;
	}

	case AddressType::VirtualAddress: {
		if (address < image_base_address) {
			return false;
		}

		uintptr_t rva = address - image_base_address;
		return convertAddress(pe,
			rva,
			AddressType::RelativeVirtualAddress,
			destination_type,
			result);
	}

	default: {
		return false;
	}
	}
}

uintptr_t convertAddress(ParsedPeRef& pe,
	uintptr_t address,
	AddressType source_type,
	AddressType destination_type) noexcept
{
	uintptr_t result = 0;
	convertAddress(pe, address, source_type, destination_type, result);
	return result;
}

std::string ReadStringAtVA(peparse::parsed_pe* pe, peparse::VA v)
{
	std::string str;

	while (true)
	{
		uint8_t b;
		if (!peparse::ReadByteAtVA(pe, v++, b))
			break;

		if (b == 0)
			break;

		str.push_back(static_cast<char>(b));
	}

	return str;
}

bool ProcessMQ2MainModule(DWORD processId, const std::function<bool(MODULEENTRY32*)>& cb)
{
	wil::unique_tool_help_snapshot hSnapshot(CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, processId));
	if (!hSnapshot.is_valid())
		return false;

	MODULEENTRY32 me32;
	ZeroMemory(&me32, sizeof(me32));
	me32.dwSize = sizeof(MODULEENTRY32);

	if (!Module32First(hSnapshot.get(), &me32))
	{
		return false;
	}

	bool result = false;

	do
	{
		if (ci_find_substr(me32.szExePath, s_mainDLL) != -1)
		{
			bool result = cb(&me32);
			return result;
		}
	} while (Module32Next(hSnapshot.get(), &me32));

	return result;
}

uint8_t* GetMQ2MainBaseAddress(DWORD processId)
{
	uint8_t* pBaseAddr = nullptr;

	ProcessMQ2MainModule(processId, [&pBaseAddr](MODULEENTRY32* pME)
		{
			pBaseAddr = pME->modBaseAddr;
			return true;
		});

	return pBaseAddr;
}

// processId, mq2main module handle
std::tuple<bool, HMODULE> FindMQ2MainInEQ(DWORD processId)
{
	std::tuple<bool, HMODULE> data = { false, 0 };

	ProcessMQ2MainModule(processId, [&data](MODULEENTRY32* pME)
		{
			std::get<0>(data) = true;
			std::get<1>(data) = pME->hModule;
			return true;
		});

	return data;
}

bool IsInjected(DWORD processId)
{
	auto [bInjected, hModMq2] = FindMQ2MainInEQ(processId);
	return bInjected;
}

uintptr_t GetEQGameBaseAddressByPID(DWORD processId)
{
	wil::unique_tool_help_snapshot hSnapshot(CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, processId));
	if (!hSnapshot.is_valid())
		return false;

	MODULEENTRY32 me32 = { 0 };
	me32.dwSize = sizeof(MODULEENTRY32);

	uintptr_t baseAddr = 0;

	if (Module32First(hSnapshot.get(), &me32))
	{
		if (!_stricmp(me32.szModule, "eqgame.exe"))
		{
			baseAddr = (uintptr_t)me32.modBaseAddr;
		}
	}

	return baseAddr;
}

HMODULE GetEQGameModuleByPID(DWORD processId)
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, processId);
	if (hSnapshot == INVALID_HANDLE_VALUE)
		return nullptr;

	MODULEENTRY32 me32 = { 0 };
	me32.dwSize = sizeof(MODULEENTRY32);

	HMODULE hModule = nullptr;

	if (Module32First(hSnapshot, &me32))
	{
		if (!_stricmp(me32.szModule, "eqgame.exe"))
		{
			hModule = me32.hModule;
		}
	}

	CloseHandle(hSnapshot);
	return hModule;
}

std::pair<std::string, std::string> GetEQGameVersionStrings(const std::string& Path)
{
	// We're going to map the eqgame.exe file to memory and then scan it, looking for the version strings.

	HANDLE hSourceFile = CreateFile(Path.c_str(), FILE_READ_DATA, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
	if (!hSourceFile)
		return {};

	// Get the file size
	LARGE_INTEGER fileSize = { 0 };
	GetFileSizeEx(hSourceFile, &fileSize);
	size_t size = static_cast<size_t>(fileSize.QuadPart);

	HANDLE hMapFile = CreateFileMappingA(hSourceFile, nullptr, PAGE_READONLY, 0, 0, "MQ2LoaderEQGameMappedFile");
	if (hMapFile == nullptr)
	{
		CloseHandle(hSourceFile);

		return {};
	}

	uint8_t* pBuf = (uint8_t*)MapViewOfFile(hMapFile, FILE_MAP_READ, 0, 0, size);
	if (pBuf == nullptr)
	{
		CloseHandle(hMapFile);
		CloseHandle(hSourceFile);

		return {};
	}

	PIMAGE_NT_HEADERS nthdrs = ImageNtHeader(pBuf);
	if (!nthdrs)
	{
		UnmapViewOfFile(pBuf);
		CloseHandle(hMapFile);
		CloseHandle(hSourceFile);

		return {};
	}

	ParsedPeRef peFile = openExecutable(Path);

	//----------------------------------------------------------------------------
	// first, find the string "Starting Everquest (Build %s %s)"
	uintptr_t versionStringPhysicalOffset = 0;

	for (intptr_t i = 0; i < (intptr_t)(size); ++i)
	{
		if (strncmp(reinterpret_cast<const char*>(pBuf + i), "Starting Ev", 10) == 0)
		{
			versionStringPhysicalOffset = i;
			break;
		}
	}

	// if we didn't find it, bail out.
	if (versionStringPhysicalOffset == 0)
	{
		return {};
	}

	std::string eqDate, eqTime;

#if defined(_WIN64)
	// figure out what the address to this reference in the data section should be, from the code section.
	// a.k.a. convert offset to address.
	uintptr_t versionStringVirtualAddress = 0;
	if (!convertAddress(peFile, versionStringPhysicalOffset, AddressType::PhysicalOffset,
		AddressType::VirtualAddress, versionStringVirtualAddress))
	{
		SPDLOG_ERROR("Failed to locate virtual address for version string");
		return {};
	}

	// lea     r8, __ActualVersionTime  ; "17:45:44"                           4C 8D 05 8A A6 54 00
	// lea     rdx, __ActualVersionDate ; "Jan 11 2022"                        48 8D 15 93 A6 54 00
	// lea     rcx, aStartingEverqu     ; "Starting EverQuest (Built %s %s)"   48 8D 0D 7C B1 54 00

	// search for the first part of the lea rcx sequence.

	uint8_t pattern[] = { 0x4C, 0x8D, 0x05, 0x00, 0x00, 0x00, 0x00,    // lea     r8, rva
						  0x48, 0x8D, 0x15, 0x00, 0x00, 0x00, 0x00,    // lea     rdx, rva
						  0x48, 0x8D, 0x0D, 0x00, 0x00, 0x00, 0x00 };  // lea     rcx, rva
	uint8_t mask[] =    { 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
	                      0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
	                      0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00 };

	uint32_t offsets[3] = { 3, 10, 17 };

	// An optimized way to do this would be to read the bytes from memory, AND it with the mask, and then do
	// a vectorized compare. For now we just brute force it to get it working.

	for (size_t i = 0; i < size; ++i)
	{
		uint8_t* pData = pBuf + i;

		for (size_t q = 0; q < lengthof(pattern); ++q)
		{
			if ((pData[q] & mask[q]) != pattern[q])
				goto next;
		}

		// if we made it here, the pattern matches. convert our physical offset into a relative virtual address.
		uintptr_t baseRva = 0;
		convertAddress(peFile, i, AddressType::PhysicalOffset, AddressType::RelativeVirtualAddress, baseRva);

		// Get RVA of the version string.
		uintptr_t stringRefDisplacement = *(int32_t*)&(pData[offsets[2]]);
		uintptr_t stringRefVirtualAddress = 0;

		uintptr_t stringRefRVA = baseRva + offsets[2] + 4;

		uintptr_t stringRef = stringRefRVA + stringRefDisplacement;
		if (!convertAddress(peFile, stringRef, AddressType::RelativeVirtualAddress, AddressType::VirtualAddress, stringRefVirtualAddress))
			continue; // failed to convert address. its probably not a valid address..?
		
		if (stringRefVirtualAddress != versionStringVirtualAddress)
			continue; // not the string we're looking for.

		// Read the time and date strings.
		uintptr_t timeVA = convertAddress(peFile,
			baseRva + offsets[0] + 4 + *(int32_t*)&(pData[offsets[0]]),
				AddressType::RelativeVirtualAddress, AddressType::VirtualAddress);

		uintptr_t dateVA = convertAddress(peFile,
			baseRva + offsets[1] + 4 + *(int32_t*)&(pData[offsets[1]]),
			AddressType::RelativeVirtualAddress, AddressType::VirtualAddress);

		eqDate = ReadStringAtVA(peFile.get(), dateVA);
		eqTime = ReadStringAtVA(peFile.get(), timeVA);
		break;

	next:
		continue;
	}


#else
	// a.k.a. convert rva to address.
	PIMAGE_SECTION_HEADER pImgSect = ImageRvaToSection(nthdrs, pBuf, (ULONG)versionStringPhysicalOffset);
	int codeSize = nthdrs->OptionalHeader.SizeOfCode + nthdrs->OptionalHeader.SizeOfHeaders;

	versionStringPhysicalOffset = versionStringPhysicalOffset - codeSize
		+ pImgSect->VirtualAddress + nthdrs->OptionalHeader.ImageBase;

	// find the one and only cross-reference to this string. This also happens to be in WinMain.
	union int2byte {
		intptr_t value; uint8_t b[4];
	} i2b;
	i2b.value = versionStringPhysicalOffset;

	// push offset aStartingEverq ; 68 94 1e ae 00
	uint8_t stringRef[5] = { 0x68, i2b.b[0], i2b.b[1], i2b.b[2], i2b.b[3] };

	// now we search for this by sequence to discover the reference to the string.
	for (intptr_t i = 0; i < (intptr_t)size; ++i)
	{
		if (memcmp(pBuf + i, stringRef, 5) == 0)
		{
			// found a byte sequence match. The full block of code looks like this:

			// push    offset a161025         ; "16:10:25"                                          68 98 14 AE 00 | -9 = time
			// push    offset aSep132019      ; "Sep 13 2019"                                       68 A4 14 AE 00 | -4 = date
			// push    offset aStartingEverqu ; "Starting EverQuest (Build %s %s)"                  68 94 1E AE 00

			// backtrack a couple of bytes and convert the result into an address.

			intptr_t dateOffset = *(DWORD*)(pBuf + i - 4) - (nthdrs->OptionalHeader.ImageBase + pImgSect->VirtualAddress - codeSize);
			eqDate = std::string{ reinterpret_cast<char*>(pBuf) + dateOffset };

			intptr_t timeOffset = *(DWORD*)(pBuf + i - 9) - (nthdrs->OptionalHeader.ImageBase + pImgSect->VirtualAddress - codeSize);
			eqTime = std::string{ reinterpret_cast<char*>(pBuf) + timeOffset };
			break;
		}
	}
#endif

	UnmapViewOfFile(pBuf);
	CloseHandle(hMapFile);
	CloseHandle(hSourceFile);

	return { eqDate, eqTime };
}

std::string GetInjecteePath()
{
	static std::string path;
	if (path.empty())
	{
		// Create path to MQ2Main.dll
		char szModuleFile[MAX_PATH] = { 0 };
		GetModuleFileNameA(nullptr, szModuleFile, 255);

		if (char* pDest = strrchr(szModuleFile, '\\'))
		{
			pDest[0] = '\0';

			path = fmt::format("{}\\{}", szModuleFile, s_mainDLL);
		}
		else
		{
			path = szModuleFile;
		}
	}

	return path;
}

std::vector<DWORD> GetAllEqGameSessions()
{
	std::vector<DWORD> theList;

	wil::unique_tool_help_snapshot hSnapshot(CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0));
	if (!hSnapshot)
		return {};

	PROCESSENTRY32 pe32 = { 0 };
	pe32.dwSize = sizeof(PROCESSENTRY32);

	if (Process32First(hSnapshot.get(), &pe32))
	{
		do
		{
			if (ci_find_substr(pe32.szExeFile, "eqgame.exe") != -1)
			{
				theList.push_back(pe32.th32ProcessID);
			}
		} while (Process32Next(hSnapshot.get(), &pe32));
	}

	return theList;
}

static uint32_t s_nextRequestId = 0;

void Inject(uint32_t PID, std::chrono::milliseconds delay)
{
	if (!IsInjected(PID))
	{
		if (delay > 0ms)
			SPDLOG_INFO("Requesting injection into process id {0} with delay {1}", PID, delay);
		else
			SPDLOG_INFO("Requesting injection into process id {0}", PID);

		std::unique_lock lock(s_mutex);
		// Add PID to the injection queue
		InjectRequest request;
		request.id = ++s_nextRequestId;
		request.injectTime = std::chrono::steady_clock::now() + delay;
		request.retries = 10;
		request.processId = PID;

		s_injectRequests.emplace_back(request);
		s_cv.notify_one();
	}
}

static void InjectAllRunningProcesses()
{
	SPDLOG_INFO("Performing injections on any existing eqgame.exe processes");

	auto pids = GetAllEqGameSessions();
	for (auto pid : pids)
	{
		Inject(pid);
	}
}

// https://www.codeproject.com/Tips/139349/Getting-the-address-of-a-function-in-a-DLL-loaded

void ForceRemoteUnloadMQ2(int pID)
{
	wil::unique_tool_help_snapshot hProcessSnap(CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pID));
	if (!hProcessSnap.is_valid())
		return;

	MODULEENTRY32 me32 = { sizeof(MODULEENTRY32) };
	if (Module32First(hProcessSnap.get(), &me32))
	{
		do
		{
			fs::path modulePath{ me32.szModule };
			if (ci_find_substr(modulePath.filename().string(), "mq2main") == 0)
			{
				using fMQShutdownPlugin = void(__cdecl*)();

				wil::unique_handle hProcess(OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION |
					PROCESS_VM_WRITE | PROCESS_VM_READ | PROCESS_TERMINATE, FALSE, pID));
				if (!hProcess.is_valid())
					return;

				fMQShutdownPlugin Shutdown = (fMQShutdownPlugin)GetRemoteProcAddress(hProcess.get(), me32.hModule, "ShutdownPlugin");
				fMQShutdownPlugin MQ2End = (fMQShutdownPlugin)GetRemoteProcAddress(hProcess.get(), me32.hModule, "_MQ2End@4");
				if (MQ2End)
				{
					Shutdown = MQ2End;
				}

				if (Shutdown)
				{
					FARPROC FreeLib = GetProcAddress(GetModuleHandle("kernel32.dll"), "FreeLibrary");

					SECURITY_ATTRIBUTES sa = { sizeof(SECURITY_ATTRIBUTES), nullptr, TRUE };
					DWORD ThreadTeminationStatus = 0;

					wil::unique_handle hRemoteThread(CreateRemoteThread(hProcess.get(), &sa, 0, (LPTHREAD_START_ROUTINE)Shutdown, nullptr, 0, nullptr));
					if (!hRemoteThread)
					{
						DWORD hmm = GetLastError();
						char* szError = nullptr;

						FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
							FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
							nullptr,
							hmm,
							MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
							(LPTSTR)&szError,
							0,
							nullptr);

						MessageBox(nullptr, szError, "Unloading ALL failed", MB_ICONWARNING | MB_SYSTEMMODAL);
						return;
					}
					else
					{
						WaitForSingleObject(hRemoteThread.get(), 20000);
					}
				}

				break;
			}
		} while (Module32Next(hProcessSnap.get(), &me32));
	}
}

bool ForceRemoteUnload()
{
	auto pids = GetAllEqGameSessions();

	for (auto pid : pids)
	{
		ForceRemoteUnloadMQ2(pid);
	}

	return false;
}

// Get the EQ Window handle for the given process id
HWND GetEQWindowHandleForProcessId(DWORD processId)
{
	struct Param
	{
		DWORD processId;
		HWND outHWnd;
	};

	WNDENUMPROC enumProc = [](HWND hWnd, LPARAM lParam) -> BOOL
	{
		Param* param = reinterpret_cast<Param*>(lParam);

		DWORD otherProcessId;
		GetWindowThreadProcessId(hWnd, &otherProcessId);
		if (otherProcessId != param->processId)
			return TRUE;

		char className[32];
		if (!::GetClassNameA(hWnd, className, 32) || strcmp(className, "_EverQuestwndclass"))
			return TRUE;

		param->outHWnd = hWnd;
		return FALSE;
	};

	Param p{ processId, nullptr };
	EnumWindows(enumProc, reinterpret_cast<LPARAM>(&p));
	return p.outHWnd;
}

// Returns list of currently active EQ window handles
std::vector<HWND> GetEQWindowHandles()
{
	struct Param
	{
		std::vector<HWND> hWnds;
	};

	WNDENUMPROC enumProc = [](HWND hWnd, LPARAM lParam) -> BOOL
	{
		Param* param = reinterpret_cast<Param*>(lParam);

		char className[32];
		if (!::GetClassNameA(hWnd, className, 32) || strcmp(className, "_EverQuestwndclass"))
			return TRUE;

		param->hWnds.push_back(hWnd);
		return TRUE;
	};

	Param p;
	EnumWindows(enumProc, reinterpret_cast<LPARAM>(&p));

	return p.hWnds;
}

// the preferred base of eqgame.exe
#if defined(_WIN64)
constexpr uintptr_t EQGamePreferredAddress = 0x140000000;
#else
constexpr uintptr_t EQGamePreferredAddress = 0x400000;
#endif // defined(_WIN64)

// Read from an EQ process and find the name of the current character
std::string GetLocalPlayer(DWORD pid)
{
	// If its not eqgame.exe this will be empty
	HMODULE hEQGameMod = GetEQGameModuleByPID(pid);
	if (!hEQGameMod)
	{
		return {};
	}

	if (HMODULE hmq2main = LoadLibrary("mq2main.dll"))
	{
		uintptr_t plocalplayer = (uintptr_t)GetProcAddress(hmq2main, "gdwLocalPlayer");
		uintptr_t localplayer = 0;

		if (plocalplayer)
		{
			localplayer = *(uintptr_t*)plocalplayer;
		}

		FreeLibrary(hmq2main);

		if (localplayer)
		{
			uintptr_t addroff = (uintptr_t)hEQGameMod - EQGamePreferredAddress + localplayer;
			uint8_t spawnstruct[0xe4] = { 0 };
			char name[64] = { 0 };
			uintptr_t addrbuffer = 0;
			uintptr_t address = 0;
			size_t size = 4;

			wil::unique_handle hProcess{ OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_READ, FALSE, pid) };
			if (hProcess.is_valid())
			{
				if (ReadProcessMemory(hProcess.get(), (void*)addroff, &address, size, (SIZE_T*)&addrbuffer))
				{
					if (ReadProcessMemory(hProcess.get(), (void*)address, &spawnstruct, 0xe4, (SIZE_T*)&addrbuffer))
					{
						return (char*)&spawnstruct[0xa4];
					}
				}
			}
		}
	}

	return {};
}

static InjectResult DoInject(uint32_t PID)
{
	SPDLOG_DEBUG("Injecting MQ into eqgame.exe: pid={0}", PID);

	wil::unique_process_handle hEQGame(::OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION |
		PROCESS_VM_WRITE | PROCESS_VM_READ | PROCESS_TERMINATE, FALSE, PID));

	if (!hEQGame.is_valid())
	{
		DWORD lastErr = GetLastError();

		SPDLOG_ERROR("{}",
			fmt::windows_error(GetLastError(), "Failed to open eqgame.exe with pid {}", PID).what());

		if (lastErr == ERROR_ACCESS_DENIED)
		{
			SPDLOG_ERROR("Failed to inject: Access Denied. This usually means that EQ is being launched as Administrator");
			ReportFailedInjection(InjectResult::FailedElevationRequired, PID);
			return InjectResult::FailedElevationRequired;
		}

		return InjectResult::FailedPermanent;
	}

	//bool is64bit = false;
	//BOOL isWow64 = FALSE;
	//if (!IsWow64Process(hEQGame.get(), &isWow64))
	//{
	//	if (!isWow64)
	//	{
	//		SYSTEM_INFO sysInfo;
	//		GetNativeSystemInfo(&sysInfo);

	//		if (sysInfo.dwProcessorType == PROCESSOR_AMD_X8664)
	//		{
	//			is64bit = true;
	//		}
	//	}
	//}

	HMODULE hEqGameMod = (HMODULE)GetEQGameBaseAddressByPID(PID);
	if (!hEqGameMod)
	{
		// Something went wrong - we couldn't get the EQ base address
		SPDLOG_ERROR("{}",
			fmt::windows_error(GetLastError(), "Failed to get eqgame.exe base address for pid={}", PID).what());
		return InjectResult::FailedRetry;
	}

	char szOutPath[MAX_STRING] = { 0 };
	::GetModuleFileNameExA(hEQGame.get(), hEqGameMod, szOutPath, MAX_STRING);

	auto [clientDate, clientTime] = GetEQGameVersionStrings(szOutPath);

	if (clientDate.empty() || clientTime.empty())
	{
		// missing a date or time from eqgame is fatal.
		// TODO: Error Message.
		SPDLOG_ERROR("Injection failed: unable to get version information from eqgame.exe. pid={0}", PID);
		return InjectResult::FailedPermanent;
	}

	SPDLOG_DEBUG("eqgame.exe version: {0} {1} pid={2}", clientDate, clientTime, PID);

	// Load up mq2main.dll so we can do a version check.
	wil::unique_hmodule hMQ2Main(::LoadLibraryA("mq2main.dll"));
	if (!hMQ2Main.is_valid())
	{
		SPDLOG_ERROR("Injection failed: failed to load mq2main.dll. pid={0}", PID);
		return InjectResult::FailedPermanent;
	}

	char mqdate[64] = { 0 };
	char mqtime[64] = { 0 };
	char* szversion = (char*)::GetProcAddress(hMQ2Main.get(), "gszVersion");
	strcpy_s(mqdate, szversion);
	szversion = (char*)GetProcAddress(hMQ2Main.get(), "gszTime");
	strcpy_s(mqtime, szversion);

	bool isMatch = clientDate == mqdate && clientTime == mqtime;

	if (!isMatch)
	{
		SPDLOG_ERROR("Injection failed: version mismatch (mq version: {0} {1})", mqdate, mqtime);

		char szOut[256] = { 0 };
		sprintf_s(szOut, "EverQuest version: %s %s\n"
			"MacroQuest version: %s %s\n"
			"\n"
			"These versions need to match in order to load MacroQuest.\n"
			"One of them may be out of date. Loading of MacroQuest cannot be completed.", clientDate.c_str(), clientTime.c_str(), mqdate, mqtime);

		::MessageBoxA(hMainWnd, szOut, "MacroQuest version mismatch!", MB_SYSTEMMODAL | MB_OK);
		return InjectResult::FailedPermanent;
	}

	// We need to do two things:
	// 1. add the path to mq2main.dll as a search directory for loading dlls. This is doing using SetDllDirectoryA
	// 2. Load the library

	// Things that we will need for our adventure
	HMODULE hModule = ::GetModuleHandle("kernel32.dll");
	assert(hModule != nullptr);

	HANDLE hRemoteThread = nullptr;

	SECURITY_ATTRIBUTES sa = { sizeof(SECURITY_ATTRIBUTES), nullptr, TRUE };

	// Get address of LoadLibraryA, its the same in every process.
	void* LoadLibraryAddr = (void*)::GetProcAddress(hModule, "LoadLibraryA");
	void* SetDllDirectoryAddr = (void*)::GetProcAddress(hModule, "SetDllDirectoryA");

	// Allocate memory buffer in the other process.

	void* pRemoteBuffer = (void*)::VirtualAllocEx(hEQGame.get(), nullptr, 1024, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

	std::string injectee = GetInjecteePath();
	std::filesystem::path injecteePath{ injectee };
	auto injecteeDirectory = injecteePath.parent_path().string();

	// Call SetDllDirectoryA(<mq2 directory>)
	WriteProcessMemory(hEQGame.get(), pRemoteBuffer, injecteeDirectory.data(), injecteeDirectory.length(), nullptr);
	hRemoteThread = CreateRemoteThread(hEQGame.get(), &sa, 0, (LPTHREAD_START_ROUTINE)SetDllDirectoryAddr, pRemoteBuffer, 0, nullptr);
	WaitForSingleObject(hRemoteThread, 120000);
	CloseHandle(hRemoteThread);

	// Call LoadLibraryA(<mq2 dll>)
	WriteProcessMemory(hEQGame.get(), pRemoteBuffer, injectee.data(), injectee.length(), nullptr);
	hRemoteThread = CreateRemoteThread(hEQGame.get(), &sa, 0, (LPTHREAD_START_ROUTINE)LoadLibraryAddr, pRemoteBuffer, 0, nullptr);
	WaitForSingleObject(hRemoteThread, 120000);
	CloseHandle(hRemoteThread);

	VirtualFreeEx(hEQGame.get(), pRemoteBuffer, 0, MEM_RELEASE);

	SPDLOG_INFO("Injection completed on process id {0}", PID);
	return InjectResult::Success;
}

void InjectorThread(bool injectOnce)
{
	SPDLOG_DEBUG("Injector thread started");

	do
	{
		std::unique_lock lock(s_mutex);

		std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
		std::chrono::milliseconds wait_for = 5s;

		// Grab a list of the requests that we should be processing *right now*
		std::vector<InjectRequest> requests;

		const auto startRequests = s_injectRequests.size();

		// Check the request list. Any element that has its inject time being >= than current time
		// should be injected and then removed from the list.
		s_injectRequests.erase(std::remove_if(std::begin(s_injectRequests), std::end(s_injectRequests),
			[&now, &wait_for, &requests](InjectRequest& request)
			{
				if (now >= request.injectTime)
				{
					requests.push_back(request);
					return true;
				}
				else
				{
					// calculate next wakeup time
					auto remaining = request.injectTime - now;
					if (remaining < wait_for)
						wait_for = std::chrono::duration_cast<std::chrono::milliseconds>(remaining);
				}

				return false;
			}), std::end(s_injectRequests));

		// unlock the mutex while we try to process the list
		lock.unlock();

		// Process entries and remove all the completions from the list.
		requests.erase(std::remove_if(std::begin(requests), std::end(requests),
			[&now, &wait_for](InjectRequest& request)
			{
				InjectResult result = DoInject(request.processId);
				if (result == InjectResult::FailedRetry)
				{
					if (request.retries > 0)
					{
						SPDLOG_INFO("Scheduling injection for retry: pid={0} retriesLeft={1}", request.processId, request.retries - 1);

						--request.retries;
						request.injectTime = now + 1s;


						return false;
					}
				}
				return true;
			}), std::end(requests));

		// Re-lock and copy back to the list
		lock.lock();

		for (const InjectRequest& request : requests)
			s_injectRequests.push_back(request);

		s_cv.wait_for(lock, wait_for);

		if (injectOnce && s_injectRequests.size() < startRequests)
		{
			SPDLOG_DEBUG("Injected at least once, stopping");
			PostMessage(hMainWnd, WM_QUIT, 0, 0);
		}
	} while (s_injectorRunning);

	SPDLOG_DEBUG("Injector thread finished");
}

static bool CheckArchitecture(const std::string path)
{
	ParsedPeRef peRef = openExecutable(path);
	if (!peRef) {
		return true;
	}

	uint16_t machine = peRef->peHeader.nt.FileHeader.Machine;
#if defined(_WIN64)
	uint16_t expectedArchitecture = IMAGE_FILE_MACHINE_AMD64;
	const char* expectedName = "x64";
#else
	uint16_t expectedArchitecture = IMAGE_FILE_MACHINE_I386;
	const char* expectedName = "x86";
#endif
	if (machine != expectedArchitecture)
	{
		const char* actualMachine = peparse::GetMachineAsString(peRef.get());
		if (!actualMachine) actualMachine = "Unknown";

		SPDLOG_ERROR("Fatal Error: Architecture mismatch. Expected {} but got {} instead", expectedName, actualMachine);
		MessageBox(nullptr, "Could not load MQ2Main.dll. The process architecture is incorrect.\n\nMacroQuest will now exit.", "Could not start MacroQuest", MB_SYSTEMMODAL | MB_OK | MB_ICONERROR);
		return false;
	}

	return true;
}

bool InitializeInjector(bool injectOnce)
{
	SPDLOG_DEBUG("Initializing injector");

	std::string injectee = GetInjecteePath();

	std::error_code ec;
	if (!std::filesystem::exists(injectee, ec))
	{
		SPDLOG_ERROR("Fatal Error: Could not find MQ2Main.dll");
		MessageBox(nullptr, "Could not find MQ2Main.dll. Make sure that the file exists next to MacroQuest.exe and try again.\n\nMacroQuest will now exit.", "Could not start MacroQuest", MB_SYSTEMMODAL | MB_OK | MB_ICONERROR);
		return false;
	}

	wil::unique_hmodule hModule(::LoadLibraryA("MQ2Main.dll"));
	if (!hModule.is_valid())
	{
		SPDLOG_ERROR("Fatal Error: Could not load MQ2Main.dll");
		MessageBox(nullptr, "Could not load MQ2Main.dll or one of its dependencies.\n\nMacroQuest will now exit.", "Could not start MacroQuest", MB_SYSTEMMODAL | MB_OK | MB_ICONERROR);
		return false;
	}

	if (!CheckArchitecture(injectee))
	{
		return false;
	}

	// Start the injector thread
	s_injectorRunning = true;
	s_injectorThread = std::thread(InjectorThread, injectOnce);

	InjectAllRunningProcesses();
	return true;
}

void ShutdownInjector()
{
	s_injectorRunning = false;
	s_cv.notify_one();

	if (s_injectorThread.joinable())
		s_injectorThread.join();
}

void RefreshInjections()
{
	SPDLOG_INFO("Refreshing injections");
	InjectAllRunningProcesses();
}
