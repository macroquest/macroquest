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

#include "pch.h"
#include "MQDetourAPI.h"

#include "MQ2Main.h"
#include "MQPluginHandler.h"
#include "CrashHandler.h"
#include "mq/base/WString.h"

#include "eqlib/MemoryPatcher.h"

#include <TlHelp32.h>

using namespace eqlib;

namespace mq {

bool gbDoingSpellChecks = false;
int gbInMemCheck4 = 0;

// this is the memory checker key struct
struct mckey
{
	union
	{
		int x;
		unsigned char a[4];
		char sa[4];
	};
};

// pointer to encryption pad for memory checker
unsigned int* extern_array0 = nullptr;

//============================================================================

class SpellManager_Detours
{
public:
#if !IS_EXPANSION_LEVEL(EXPANSION_LEVEL_COTF)
	DETOUR_TRAMPOLINE_DEF(bool, LoadTextSpells_Trampoline, (char*, char*, EQ_Spell*))
	bool LoadTextSpells_Detour(char* FileName, char* AssocFileName, EQ_Spell* SpellArray)
	{
		gbDoingSpellChecks = true;
		bool ret = LoadTextSpells_Trampoline(FileName, AssocFileName, SpellArray);
		gbDoingSpellChecks = false;
		return ret;
	}
#else
	DETOUR_TRAMPOLINE_DEF(bool, LoadTextSpells_Trampoline, (char*, char*, EQ_Spell*, SpellAffectData*))
	bool LoadTextSpells_Detour(char* FileName, char* AssocFileName, EQ_Spell* SpellArray, SpellAffectData* EffectArray)
	{
		gbDoingSpellChecks = true;
		bool ret = LoadTextSpells_Trampoline(FileName, AssocFileName, SpellArray, EffectArray);
		gbDoingSpellChecks = false;
		return ret;
	}
#endif
};

//============================================================================
	
#if 0
// TODO: Maybe someday revisit detection of assist completion...
//void SetAssist(BYTE* address)
//{
//	gbAssistComplete = AS_AssistReceived;
//
//	if (!address) return;
//	int Assistee = *(int*)address;
//
//	if (PlayerClient* pSpawn = GetSpawnByID(Assistee))
//	{
//		//DebugSpew("Assist Result: %d => %s", Assistee, pSpawn->Name);
//		gbAssistComplete = AS_AssistSent;
//	}
//}

// Defined in AssemblyFunctions.asm, need the forward declare
//void GetAssistParam();

//============================================================================

class CPacketScrambler_Detours
{
public:
	int ntoh_Detour(int nopcode);
	DETOUR_TRAMPOLINE_DEF(int, ntoh_Trampoline, (int))
};

// ntoh_detour actually climbs into the stack and pulls data out from the caller's
// stack frame. Because of this we need to avoid optimizing this function as it
// changes the layout of the stack. Keep optimizations off for this function or
// it will break.

#pragma optimize("", off)
int CPacketScrambler_Detours::ntoh_Detour(int nopcode)
{
	int hopcode = ntoh_Trampoline(nopcode);

#if 0
	if (hopcode == EQ_ASSIST)
	{
		GetAssistParam();
	}
#endif

	return hopcode;
}
#pragma optimize("", on)
#endif


DETOUR_TRAMPOLINE_DEF(int, memcheck0_tramp, (unsigned char* buffer, size_t count))
int memcheck0(unsigned char* buffer, size_t count);
DETOUR_TRAMPOLINE_DEF(int, memcheck1_tramp, (unsigned char* buffer, size_t count, mckey key))
int memcheck1(unsigned char* buffer, size_t count, mckey key);

#if defined(__MemChecker2)
DETOUR_TRAMPOLINE_DEF(int, memcheck2_tramp, (unsigned char* buffer, size_t count, mckey key))
int memcheck2(unsigned char* buffer, size_t count, mckey key);
#endif
#if defined(__MemChecker3)
int memcheck2(unsigned char* buffer, size_t count, mckey key);
DETOUR_TRAMPOLINE_DEF(int, memcheck3_tramp, (unsigned char* buffer, size_t count, mckey key))
#endif

#if defined(__MemChecker4_x)
DETOUR_TRAMPOLINE_DEF(int WINAPI, memcheck4_tramp, (unsigned char* buffer, size_t* count))
int WINAPI memcheck4(unsigned char* buffer, size_t* count);
#endif

struct OrderedPatchSet
{
	OrderedPatchSet(std::vector<eqlib::MemoryPatch*> patches)
		: patches(std::move(patches))
	{
		if (!patches.empty())
		{
			lastAddress = patches.back()->GetAddress() + patches.back()->GetBytesSize();
		}
	}

	// assumes patches is sorted and addresses are accessed in increasing order. Optimized
	uint8_t GetPatchedByte(uintptr_t address, uint8_t originalByte)
	{
		// Early out if there are no patches
		if (patches.empty())
			return originalByte;

		// Early out if address is out of range
		if (lastPatchIndex >= patches.size() || address < patches[lastPatchIndex]->GetAddress() || address >= lastAddress)
			return originalByte;

		// If this fails, the address has gone past the patch.
		if (!patches[lastPatchIndex]->IsAddressInRange(address))
		{
			++lastPatchIndex;

			// We've exhausted all of our patches.
			if (lastPatchIndex >= patches.size())
				return originalByte;

			// We haven't caught up to the next one yet.
			if (address < patches[lastPatchIndex]->GetAddress())
				return originalByte;
		}

		// At this point we are expecting a patch covering the current range. (It isn't possible to go from
		// one patch to another without going through the address range of the next patch)
		return patches[lastPatchIndex]->ReadOriginalByte(address);
	}

private:
	size_t lastPatchIndex = 0;
	uintptr_t lastAddress = 0;
	std::vector<eqlib::MemoryPatch*> patches;
};

static uint32_t DetourAwareHash(uint8_t* origBytes, size_t count, uint32_t value = 0xffffffff)
{
	uintptr_t addr = reinterpret_cast<uintptr_t>(origBytes);
	OrderedPatchSet patches{ pDetourAPI->FindPatches(addr, count) };

	for (size_t i = 0; i < count; ++i)
	{
		// Feed in bytes to the hash algorithm using the source bytes of a detour
		// if the data range overlaps an active detour.
		uint8_t newByte = patches.GetPatchedByte(addr + i, origBytes[i]);

		int temp = static_cast<int>(newByte) ^ (value & 0xff);
		value = (static_cast<int>(value) >> 8) & 0xffffff;

		value ^= extern_array0[temp];
	}

	return value;
}

int memcheck0(unsigned char* buffer, size_t count)
{
	uintptr_t addr = reinterpret_cast<uintptr_t>(buffer);

	// If we are not detouring memory that overlaps this region, just let it pass through.
	AddressDetourState detourState = pDetourAPI->IsAddressDetoured(addr, count);
	if (detourState != AddressDetourState::CodeDetour)
	{
		return memcheck0_tramp(buffer, count);
	}

	return DetourAwareHash(buffer, count);
}

int memcheck1(unsigned char* buffer, size_t count, mckey key)
{
	uintptr_t addr = reinterpret_cast<uintptr_t>(buffer);
	unsigned int ebx, eax, edx;

	if (key.x != 0) {
		eax = ~key.a[0] & 0xff;
		eax = extern_array0[eax];
		eax ^= 0xffffff;

		edx = key.a[1];
		edx = (edx ^ eax) & 0xff;
		eax = ((int)eax >> 8) & 0xffffff;
		eax ^= extern_array0[edx];

		edx = key.a[2];
		edx = (edx ^ eax) & 0xff;
		eax = ((int)eax >> 8) & 0xffffff;
		eax ^= extern_array0[edx];

		edx = key.a[3];
		edx = (edx ^ eax) & 0xff;
		eax = ((int)eax >> 8) & 0xffffff;
		eax ^= extern_array0[edx];
	} else {
		eax = 0xffffffff;
	}

	eax = ~DetourAwareHash(buffer, count, eax);

	ebx = ~eax;
	return ebx;
}

#if defined(__MemChecker2) || defined(__MemChecker3)
int memcheck2(unsigned char* buffer, size_t count, mckey key)
{
	uintptr_t addr = reinterpret_cast<uintptr_t>(buffer);
	unsigned int ebx, edx, eax;

	eax = ~key.a[0] & 0xff;
	eax = extern_array0[eax];
	eax ^= 0xffffff;

	edx = key.a[1];
	edx = (edx ^ eax) & 0xff;
	eax = ((int)eax >> 8) & 0xffffff;
	eax ^= extern_array0[edx];

	edx = key.a[2];
	edx = (edx ^ eax) & 0xff;
	eax = ((int)eax >> 8) & 0xffffff;
	edx = eax ^ extern_array0[edx];

	ebx = key.a[3];
	ebx = (edx ^ ebx) & 0xff;
	edx = ((int)edx >> 8) & 0xffffff;
	edx ^= extern_array0[ebx];

	edx = ~DetourAwareHash(buffer, count, eax);

	eax = ~edx;
	return eax;
}
#endif // defined(__MemChecker2) || defined(__MemChecker3)

#if defined(__MemChecker4_x)
int WINAPI memcheck4(unsigned char* buffer, size_t* count_)
{
	uintptr_t addr = reinterpret_cast<uintptr_t>(buffer);
	size_t count = *count_ & 0xff;
	uint8_t bmask = *gpMemCheckBitmask;

	if (!bmask && *gpMemCheckActive)
		*gpMemCheckBitmask |= 1;

	// If we are not detouring memory that overlaps this region, just let it pass through.
	AddressDetourState detourState = pDetourAPI->IsAddressDetoured(addr, count);
	if (detourState != AddressDetourState::CodeDetour)
	{
		gbInMemCheck4 = 1;
		int result = memcheck4_tramp(buffer, count_);
		gbInMemCheck4 = 0;
		return result;
	}

	unsigned int crc32 = 0xffffffff;

	crc32 = DetourAwareHash(buffer, count, crc32);

	*gpMemCheckBitmask = bmask;

	return crc32;
}
#endif // defined(__MemChecker4_x)

DETOUR_TRAMPOLINE_DEF(uint64_t, decompress_block_trampoline, (uint64_t ctx))
uint64_t decompress_block_detour(uint64_t ctx)
{
	if (gbInMemCheck4)
		return decompress_block_trampoline(ctx);

	return 0;
}

DETOUR_TRAMPOLINE_DEF(BOOL WINAPI, FindModules_Trampoline, (HANDLE, HMODULE*, DWORD, DWORD*))
BOOL WINAPI FindModules_Detour(HANDLE hProcess, HMODULE* hModule, DWORD cb, DWORD* lpcbNeeded)
{
	if (gbInMemCheck4 != 1) return FindModules_Trampoline(hProcess, hModule, cb, lpcbNeeded);
	++gbInMemCheck4;
	bool getMacroQuestModules = true;
	bool result = GetFilteredModules(hProcess, hModule, cb, lpcbNeeded,
		[&getMacroQuestModules](HMODULE hModule) -> bool { return IsMacroQuestModule(hModule, getMacroQuestModules); }) ? TRUE : FALSE;
	--gbInMemCheck4;
	return result ? 1 : 0;
}

DETOUR_TRAMPOLINE_DEF(BOOL WINAPI, FindProcesses_Trampoline, (DWORD*, DWORD, DWORD*))
BOOL WINAPI FindProcesses_Detour(DWORD* lpidProcess, DWORD cb, DWORD* lpcbNeeded)
{
	if (gbInMemCheck4 != 1) return FindProcesses_Trampoline(lpidProcess, cb, lpcbNeeded);
	++gbInMemCheck4;
	bool getMacroQuestProcesses = true;
	bool result = GetFilteredProcesses(lpidProcess, cb, lpcbNeeded,
		[&getMacroQuestProcesses](std::string_view process_name) -> bool { return IsMacroQuestProcess(process_name, getMacroQuestProcesses); }) ? TRUE : FALSE;
	--gbInMemCheck4;
	return result ? 1 : 0;
}

DETOUR_TRAMPOLINE_DEF(BOOL WINAPI, Module32Next_Trampoline, (HANDLE, LPMODULEENTRY32))
static BOOL FilterModuleEntry(HANDLE hSnapshot, LPMODULEENTRY32 lpme)
{
	while (IsMacroQuestModule(lpme->hModule, true))
	{
		if (!Module32Next_Trampoline(hSnapshot, lpme))
			return FALSE;
	}

	return TRUE;
}

BOOL WINAPI Module32Next_Detour(HANDLE hSnapshot, LPMODULEENTRY32 lpme)
{
	if (Module32Next_Trampoline(hSnapshot, lpme))
	{
		return FilterModuleEntry(hSnapshot, lpme);
	}

	return FALSE;
}

DETOUR_TRAMPOLINE_DEF(BOOL WINAPI, Module32First_Trampoline, (HANDLE, LPMODULEENTRY32))
BOOL WINAPI Module32First_Detour(HANDLE hSnapshot, LPMODULEENTRY32 lpme)
{
	if (Module32First_Trampoline(hSnapshot, lpme))
	{
		return FilterModuleEntry(hSnapshot, lpme);
	}

	return FALSE;
}

DETOUR_TRAMPOLINE_DEF(BOOL WINAPI, Process32Next_Trampoline, (HANDLE, LPPROCESSENTRY32))
static BOOL FilterProcessEntry(HANDLE hSnapshot, LPPROCESSENTRY32 lppe)
{
	while (IsMacroQuestProcess(lppe->th32ProcessID, true)
		|| IsMacroQuestProcess(lppe->th32ParentProcessID, true))
	{
		if (!Process32Next_Trampoline(hSnapshot, lppe))
			return FALSE;
	}

	return TRUE;
}

BOOL WINAPI Process32Next_Detour(HANDLE hSnapshot, LPPROCESSENTRY32 lppe)
{
	if (Process32Next_Trampoline(hSnapshot, lppe))
	{
		return FilterProcessEntry(hSnapshot, lppe);
	}

	return FALSE;
}

DETOUR_TRAMPOLINE_DEF(BOOL WINAPI, Process32First_Trampoline, (HANDLE, LPPROCESSENTRY32))
BOOL WINAPI Process32First_Detour(HANDLE hSnapshot, LPPROCESSENTRY32 lppe)
{
	if (Process32First_Trampoline(hSnapshot, lppe))
	{
		return FilterProcessEntry(hSnapshot, lppe);
	}

	return FALSE;
}

uintptr_t __Module32First = 0;
uintptr_t __Module32Next = 0;
uintptr_t __Process32First = 0;
uintptr_t __Process32Next = 0;

void HookMemChecker(bool Patch)
{
	DebugSpew("HookMemChecker - %satching", (Patch) ? "P" : "Unp");

	if (Patch)
	{
#if !defined(EMULATOR)
		EzDetour(__MemChecker0, memcheck0, memcheck0_tramp);
		EzDetour(__MemChecker1, memcheck1, memcheck1_tramp);
#if defined(__MemChecker2_x)
		EzDetour(__MemChecker2, memcheck2, memcheck2_tramp);
#endif
#if defined(__MemChecker3_x)
		EzDetour(__MemChecker3, memcheck2, memcheck3_tramp);
#endif
#if defined(__MemChecker4_x)
		EzDetour(__MemChecker4, memcheck4, memcheck4_tramp);
#endif
#endif
		mq::AddDetourBytes(__compress_block, __decompress_block - __compress_block + DETOUR_BYTES_COUNT, "__compress_block");
		EzDetour(__decompress_block, decompress_block_detour, decompress_block_trampoline);

		EzDetour(Spellmanager__LoadTextSpells, &SpellManager_Detours::LoadTextSpells_Detour, &SpellManager_Detours::LoadTextSpells_Trampoline);
	}
	else
	{
#if !defined(EMULATOR)
		RemoveDetour(__MemChecker0);
		RemoveDetour(__MemChecker1);
#if defined(__MemChecker2_x)
		RemoveDetour(__MemChecker2);
#endif
#if defined(__MemChecker3_x)
		RemoveDetour(__MemChecker3);
#endif
#if defined(__MemChecker4_x)
		RemoveDetour(__MemChecker4);
#endif
#endif

		//RemoveDetour(CPacketScrambler__ntoh);
		RemoveDetour(Spellmanager__LoadTextSpells);
	}
}

static void InitializeDetours()
{
#if !defined(EMULATOR)
	// hit the debugger if we don't hook this. take no chances
	if (!__MemChecker0
		|| !__MemChecker1
#if defined(__MemChecker2_x)
		|| !__MemChecker2
#endif
#if defined(__MemChecker3_x)
		|| !__MemChecker3
#endif
#if defined(__MemChecker4_x)
		|| !__MemChecker4
#endif
		|| !__EncryptPad0)
	{
		__debugbreak();
	}
#endif

	extern_array0 = reinterpret_cast<uint32_t*>(__EncryptPad0);

	HookMemChecker(true);

	EzDetour(__ModuleList, FindModules_Detour, FindModules_Trampoline);
	EzDetour(__ProcessList, FindProcesses_Detour, FindProcesses_Trampoline);

	HMODULE hKernel32 = GetModuleHandle("kernel32.dll");
	__Module32First = (uintptr_t)GetProcAddress(hKernel32, "Module32First");
	__Module32Next = (uintptr_t)GetProcAddress(hKernel32, "Module32Next");
	__Process32First = (uintptr_t)GetProcAddress(hKernel32, "Process32First");
	__Process32Next = (uintptr_t)GetProcAddress(hKernel32, "Process32Next");

	EzDetour(__Module32First, &Module32First_Detour, &Module32First_Trampoline);
	EzDetour(__Module32Next, &Module32Next_Detour, &Module32Next_Trampoline);
	EzDetour(__Process32First, &Process32First_Detour, &Process32First_Trampoline);
	EzDetour(__Process32Next, &Process32Next_Detour, &Process32Next_Trampoline);
}

static void ShutdownDetours()
{
	RemoveDetour(__ModuleList);
	RemoveDetour(__ProcessList);
	RemoveDetour(__Module32First);
	RemoveDetour(__Module32Next);
	RemoveDetour(__Process32First);
	RemoveDetour(__Process32Next);

	HookMemChecker(false);
}

//============================================================================
//============================================================================

MQDetourAPI* pDetourAPI = nullptr;

MQDetourAPI::MQDetourAPI(eqlib::MemoryPatcher* memoryPatcher)
	: m_memoryPatcher(memoryPatcher)
{
	// TODO: Decouple detours from the memory patcher
	InitializeDetours();
}

MQDetourAPI::~MQDetourAPI()
{
	ShutdownDetours();
}

bool MQDetourAPI::ValidateNewPatch(uintptr_t address, std::string_view name, const MQPluginHandle& pluginHandle) const
{
	eqlib::MemoryPatch* existingPatch = nullptr;

	if (m_memoryPatcher->FindPatches(address, eqlib::DETOUR_BYTES_COUNT, &existingPatch, 1) != 0)
	{
		if (pluginHandle == mqplugin::ThisPluginHandle || existingPatch->GetUserData() == 0)
			return false;

		MQPlugin* otherPlugin = GetPluginByHandle(MQPluginHandle{ existingPatch->GetUserData() });
		MQPlugin* thisPlugin = GetPluginByHandle(pluginHandle);

		if (existingPatch->GetAddress() == address)
		{
			SPDLOG_ERROR("Plugin \"{}\" tried to detour address 0x{:X} (\"{}\") but it already exists as another detour created by {}",
				thisPlugin->name, address, name, otherPlugin ? std::string_view(otherPlugin->name) : std::string_view("(NULL)"));
		}
		else
		{
			SPDLOG_ERROR("Plugin \"{}\" tried to detour address 0x{:X} (\"{}\") but it conflicts with another detour created by {}",
				thisPlugin->name, address, name, otherPlugin ? std::string_view(otherPlugin->name) : std::string_view("(NULL)"));
		}

		return false;
	}

	return true;
}

bool MQDetourAPI::CreateDetour(uintptr_t address, void** target, void* detour, std::string_view name,
	const MQPluginHandle& pluginHandle)
{
	if (!ValidateNewPatch(address, name, pluginHandle))
		return false;

	if (eqlib::MemoryPatch* memoryPatch = m_memoryPatcher->CreatePatch(address, target, detour, name))
	{
		m_memoryPatcher->SetUserData(memoryPatch, pluginHandle.pluginID);

		return true;
	}

	return false;
}

bool MQDetourAPI::CreateDetour(uintptr_t address, size_t width, std::string_view name,
	const MQPluginHandle& pluginHandle)
{
	if (!ValidateNewPatch(address, name, pluginHandle))
		return false;

	if (eqlib::MemoryPatch* memoryPatch = m_memoryPatcher->CreatePatch(address, width, name))
	{
		m_memoryPatcher->SetUserData(memoryPatch, pluginHandle.pluginID);

		return true;
	}

	return false;
}

bool MQDetourAPI::RemoveDetour(uintptr_t address, const MQPluginHandle& pluginHandle)
{
	eqlib::MemoryPatch* patch = m_memoryPatcher->GetPatch(address);

	if (!patch || patch->GetType() != MemoryPatch::Type::Detour)
	{
		SPDLOG_WARN("Failed to remove detour at 0x{:X}: Detour not found", address);

		return false;
	}

	if (patch->GetUserData() != pluginHandle.pluginID)
	{
		if (patch->GetUserData() == 0)
		{
			SPDLOG_WARN("Failed to remove detour at 0x{:X}: Detour is owned by MQ", address);
		}
		else
		{
			MQPlugin* plugin = GetPluginByHandle(MQPluginHandle{ patch->GetUserData() });

			if (plugin)
			{
				SPDLOG_WARN("Failed to remove detour at 0x{:X}: Detour is owned by {}", address, plugin->name);
			}
			else
			{
				SPDLOG_WARN("Failed to remove detour at 0x{:X}: Detour is owned by an unknown plugin", address);
			}
		}
	}

	return m_memoryPatcher->RemovePatch(address);
}

AddressDetourState MQDetourAPI::IsAddressDetoured(uintptr_t address, size_t width) const
{
	if (gbDoingSpellChecks || gbInMemCheck4 > 0)
		return AddressDetourState::KnownSkippable;

	// Executables start with a header that has 'MZ\x90\x00'. This is checking for this
	// magic value and skipping the crc32 of an executable since we don't care about those.
	if (address && width >= 4 && *(DWORD*)address == 0x00905a4d)
		return AddressDetourState::KnownSkippable;

	if (m_memoryPatcher->IsAddressPatched(address, width))
		return AddressDetourState::CodeDetour;

	return AddressDetourState::None;
}

std::vector<eqlib::MemoryPatch*> MQDetourAPI::FindPatches(uintptr_t address, size_t width)
{
	std::vector<eqlib::MemoryPatch*> result;
	uintptr_t endAddress = address + width;
	size_t offset = 0;

	// Ferry list of patches across dll boundary...
	constexpr uint32_t MAX_PER_ITERATION = 100;
	eqlib::MemoryPatch* patches[MAX_PER_ITERATION];

	uint32_t count = m_memoryPatcher->FindPatches(address, width, patches, MAX_PER_ITERATION);
	if (count == 0)
		return result;

	// Count is the total number of patches found, so we can resize as soon as we know.
	result.resize(count);

	// Now we iterate through results until we have all the patches.
	memcpy(result.data() + offset, patches, std::min(MAX_PER_ITERATION, count));

	while (count > MAX_PER_ITERATION)
	{
		offset += MAX_PER_ITERATION;

		address = result.back()->GetAddress() + result.back()->GetBytesSize();
		width = endAddress - address;

		count = m_memoryPatcher->FindPatches(address, width, patches, MAX_PER_ITERATION);

		memcpy(result.data() + offset, patches, std::min(MAX_PER_ITERATION, count));
	}

	return result;
}

//============================================================================

bool detail::CreateDetour(uintptr_t address, void** target, void* detour, std::string_view name)
{
	return pDetourAPI->CreateDetour(address, target, detour, name, mqplugin::ThisPluginHandle);
}

bool detail::CreateDetour(uintptr_t address, size_t width, std::string_view name)
{
	return pDetourAPI->CreateDetour(address, width, name, mqplugin::ThisPluginHandle);
}

bool RemoveDetour(uintptr_t address)
{
	return pDetourAPI->RemoveDetour(address, mqplugin::ThisPluginHandle);
}

} // namespace mq
