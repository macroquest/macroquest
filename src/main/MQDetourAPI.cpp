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

#include "MacroQuest.h"
#include "Logging.h"
#include "MQMain.h"

#include "mq/api/DetourAPI.h"
#include "mq/base/WString.h"
#include "eqlib/MemoryPatcher.h"

#include <TlHelp32.h>
#include <Psapi.h>

namespace eqlib
{
	class MemoryPatcher;
	class MemoryPatch;
}

using namespace eqlib;

namespace mq {

#if !IS_EMU_CLIENT

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
static unsigned int* extern_array0 = nullptr;

static bool s_doingSpellChecks = false;
static int s_inMemCheck4 = 0;
static bool s_isValid = true;
static bool s_hasNotified = false;

//============================================================================

class SpellManager_Detours
{
public:
#if !IS_EXPANSION_LEVEL(EXPANSION_LEVEL_COTF)
	DETOUR_TRAMPOLINE_DEF(bool, LoadTextSpells_Trampoline, (char*, char*, EQ_Spell*))
	bool LoadTextSpells_Detour(char* FileName, char* AssocFileName, EQ_Spell* SpellArray)
	{
		s_doingSpellChecks = true;
		bool ret = LoadTextSpells_Trampoline(FileName, AssocFileName, SpellArray);
		s_doingSpellChecks = false;
		return ret;
	}
#else
	DETOUR_TRAMPOLINE_DEF(bool, LoadTextSpells_Trampoline, (char*, char*, EQ_Spell*, SpellAffectData*))
	bool LoadTextSpells_Detour(char* FileName, char* AssocFileName, EQ_Spell* SpellArray, SpellAffectData* EffectArray)
	{
		s_doingSpellChecks = true;
		bool ret = LoadTextSpells_Trampoline(FileName, AssocFileName, SpellArray, EffectArray);
		s_doingSpellChecks = false;
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
#endif

//============================================================================

enum class AddressDetourState
{
	None = 0,
	CodeDetour = 1,
	KnownSkippable = 2,
};

static AddressDetourState IsAddressDetoured(uintptr_t address, size_t width)
{
	if (s_doingSpellChecks || s_inMemCheck4 > 0)
		return AddressDetourState::KnownSkippable;

	// Executables start with a header that has 'MZ\x90\x00'. This is checking for this
	// magic value and skipping the crc32 of an executable since we don't care about those.
	if (address && width >= 4 && *(DWORD*)address == 0x00905a4d)
		return AddressDetourState::KnownSkippable;

	if (g_mq->IsAddressPatched(address, width))
		return AddressDetourState::CodeDetour;

	return AddressDetourState::None;
}

DETOUR_TRAMPOLINE_DEF(int, memcheck0_tramp, (unsigned char* buffer, size_t count))
int memcheck0(unsigned char* buffer, size_t count);
DETOUR_TRAMPOLINE_DEF(int, memcheck1_tramp, (unsigned char* buffer, size_t count, mckey key))
int memcheck1(unsigned char* buffer, size_t count, mckey key);
#if defined(__MemChecker4_x)
DETOUR_TRAMPOLINE_DEF(int WINAPI, memcheck4_tramp, (unsigned char* buffer, size_t* count))
int WINAPI memcheck4(unsigned char* buffer, size_t* count);
#endif

struct OrderedPatchSet
{
	OrderedPatchSet(std::vector<eqlib::MemoryPatch*>&& patches)
		: patches(std::move(patches))
	{
		if (!patches.empty())
		{
			lastAddress = patches.back()->GetAddress() + patches.back()->GetBytesSize();
		}
	}

	// Optimized based on the assumption that patches are sorted and addresses are accessed in increasing order
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
	OrderedPatchSet patches{ g_mq->FindPatches(addr, count) };

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
	AddressDetourState detourState = IsAddressDetoured(addr, count);
	if (detourState != AddressDetourState::CodeDetour)
	{
		return memcheck0_tramp(buffer, count);
	}

	return DetourAwareHash(buffer, count);
}

int memcheck1(unsigned char* buffer, size_t count, mckey key)
{
	unsigned int eax, edx;

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

	return ~DetourAwareHash(buffer, count, eax);
}

#if defined(__MemChecker4_x)
int WINAPI memcheck4(unsigned char* buffer, size_t* count_)
{
	uintptr_t addr = reinterpret_cast<uintptr_t>(buffer);
	size_t count = *count_ & 0xff;
	uint8_t bmask = *gpMemCheckBitmask;

	if (!bmask && *gpMemCheckActive)
		*gpMemCheckBitmask |= 1;

	// If we are not detouring memory that overlaps this region, just let it pass through.
	AddressDetourState detourState = IsAddressDetoured(addr, count);
	if (detourState != AddressDetourState::CodeDetour)
	{
		s_inMemCheck4 = 1;
		int result = memcheck4_tramp(buffer, count_);
		s_inMemCheck4 = 0;
		return result;
	}

	unsigned int crc32 = DetourAwareHash(buffer, count, 0xffffffff);

	*gpMemCheckBitmask = bmask;

	return crc32;
}
#endif // defined(__MemChecker4_x)

DETOUR_TRAMPOLINE_DEF(uint64_t, decompress_block_trampoline, (uint64_t ctx))
uint64_t decompress_block_detour(uint64_t ctx)
{
	if (s_inMemCheck4)
		return decompress_block_trampoline(ctx);

	return 0;
}

DETOUR_TRAMPOLINE_DEF(BOOL WINAPI, FindModules_Trampoline, (HANDLE, HMODULE*, DWORD, DWORD*))
BOOL WINAPI FindModules_Detour(HANDLE hProcess, HMODULE* hModule, DWORD cb, DWORD* lpcbNeeded)
{
	if (s_inMemCheck4 != 1) return FindModules_Trampoline(hProcess, hModule, cb, lpcbNeeded);
	++s_inMemCheck4;
	bool getMacroQuestModules = true;
	bool result = GetFilteredModules(hProcess, hModule, cb, lpcbNeeded,
		[&getMacroQuestModules](HMODULE hModule) -> bool { return IsMacroQuestModule(hModule, getMacroQuestModules); }) ? TRUE : FALSE;
	--s_inMemCheck4;
	return result ? 1 : 0;
}

DETOUR_TRAMPOLINE_DEF(BOOL WINAPI, FindProcesses_Trampoline, (DWORD*, DWORD, DWORD*))
BOOL WINAPI FindProcesses_Detour(DWORD* lpidProcess, DWORD cb, DWORD* lpcbNeeded)
{
	if (s_inMemCheck4 != 1) return FindProcesses_Trampoline(lpidProcess, cb, lpcbNeeded);
	++s_inMemCheck4;
	bool getMacroQuestProcesses = true;
	bool result = GetFilteredProcesses(lpidProcess, cb, lpcbNeeded,
		[&getMacroQuestProcesses](std::string_view process_name) -> bool { return IsMacroQuestProcess(process_name, getMacroQuestProcesses); }) ? TRUE : FALSE;
	--s_inMemCheck4;
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

struct HookInfo
{
	std::string name;
	uintptr_t address = 0;

	std::function<void(HookInfo&)> patch = nullptr;
};
static std::vector<HookInfo> s_hooks;
static std::vector<uintptr_t> s_patches;

template <typename T>
void AddHook_(uintptr_t address, T& detour, T*& target, const char* name)
{
	HookInfo hookInfo;
	hookInfo.name = name;
	hookInfo.address = 0;
	hookInfo.patch = [address, &detour, &target](HookInfo& hi)
		{
			hi.address = address;
			mq::detail::CreateDetour(hi.address, &(void*&)target, detour, hi.name);
		};
	
	s_hooks.push_back(std::move(hookInfo));
}

#define AddHook(address, detour, trampoline) \
	AddHook_(static_cast<uintptr_t>(address), detour, trampoline##_Ptr, STRINGIFY(address))

static void InstallHooks()
{
	for (HookInfo& hook : s_hooks)
	{
		if (hook.address == 0)
		{
			hook.patch(hook);
		}
	}
}

static void RemoveHooks()
{
	for (HookInfo& hook : s_hooks)
	{
		if (hook.address != 0)
		{
			mq::RemoveDetour(hook.address);
			hook.address = 0;
		}
	}
	s_hooks.clear();

	for (uintptr_t patchAddr : s_patches)
	{
		mq::RemovePatch(patchAddr);
	}
	s_patches.clear();
}

static bool IsHooked(uintptr_t addr)
{
	for (const HookInfo& hook : s_hooks)
	{
		if (hook.address == addr)
		{
			return true;
		}
	}
	return false;
}

static void HookMemChecker(bool Patch)
{
	LOG_DEBUG("HookMemChecker - {}atching", (Patch) ? "P" : "Unp");

	if (Patch)
	{
		mq::AddPatch(__compress_block, __decompress_block - __compress_block + DETOUR_BYTES_COUNT, "__compress_block");
		EzDetour(Spellmanager__LoadTextSpells, &SpellManager_Detours::LoadTextSpells_Detour, &SpellManager_Detours::LoadTextSpells_Trampoline);

		InstallHooks();

		MODULEINFO EQGameModuleInfo;
		HMODULE hEQGameModule = ::GetModuleHandleW(nullptr);

		::K32GetModuleInformation(GetCurrentProcess(), hEQGameModule, &EQGameModuleInfo, sizeof(MODULEINFO));

		uintptr_t imageStart = (uintptr_t)::GetModuleHandleA(nullptr);
		uintptr_t imageEnd = EQGameModuleInfo.SizeOfImage;
		uintptr_t addr = imageStart;
		constexpr uint8_t pattern[] = {
			0x0F, 0xB6, 0x01, 0x3C, 0x00, 0x75, 0x00, 0xB0, 0x00, 0xEB,
			0x00, 0x3C, 0x00, 0x75, 0x00, 0x0F, 0xB6, 0x49, 0x00, 0x80,
			0xE9, 0x00, 0x80, 0xF9, 0x00, 0x77, 0x00, 0xB0, 0x00, 0xEB
		};
		uintptr_t deltas[] = { 5, 13 };
		while ((addr = FindPattern(addr, imageEnd - addr, pattern, "xxxx?x?x?x?x?x?xxx?xx?xx?x?x?x")))
		{
			uint8_t bytes[] = { 0x48, 0x8D, 0x0D };
			if (memcmp(reinterpret_cast<void*>(addr - 7), bytes, 3) != 0
				|| IsHooked(*reinterpret_cast<uint32_t*>(addr - 4) + addr))
				for (uintptr_t delta : deltas) { mq::AddPatch(addr + delta, { 0xEB }); s_patches.push_back(addr + delta); }
			addr += lengthof(pattern);
		}
	}
	else
	{
		RemoveHooks();
		RemoveDetour(Spellmanager__LoadTextSpells);
		mq::RemovePatch(__compress_block);
	}
}

static void InitializeDetours()
{
	// hit the debugger if we don't hook this. take no chances
	if (!__MemChecker0
		|| !__MemChecker1
#if defined(__MemChecker4_x)
		|| !__MemChecker4
#endif
		|| !__EncryptPad0)
	{
		__debugbreak();
	}

	extern_array0 = reinterpret_cast<uint32_t*>(__EncryptPad0);

	AddHook(__MemChecker0, memcheck0, memcheck0_tramp);
	AddHook(__MemChecker1, memcheck1, memcheck1_tramp);
#if defined(__MemChecker4_x)
	AddHook(__MemChecker4, memcheck4, memcheck4_tramp);
#endif
	AddHook(__decompress_block, decompress_block_detour, decompress_block_trampoline);

	AddHook(__ModuleList, FindModules_Detour, FindModules_Trampoline);
	AddHook(__ProcessList, FindProcesses_Detour, FindProcesses_Trampoline);

	HMODULE hKernel32 = GetModuleHandle("kernel32.dll");
	__Module32First = (uintptr_t)GetProcAddress(hKernel32, "Module32First");
	__Module32Next = (uintptr_t)GetProcAddress(hKernel32, "Module32Next");
	__Process32First = (uintptr_t)GetProcAddress(hKernel32, "Process32First");
	__Process32Next = (uintptr_t)GetProcAddress(hKernel32, "Process32Next");

	AddHook(__Module32First, Module32First_Detour, Module32First_Trampoline);
	AddHook(__Module32Next, Module32Next_Detour, Module32Next_Trampoline);
	AddHook(__Process32First, Process32First_Detour, Process32First_Trampoline);
	AddHook(__Process32Next, Process32Next_Detour, Process32Next_Trampoline);

	HookMemChecker(true);
}

static void ShutdownDetours()
{
	HookMemChecker(false);
}

static void PulseDetours()
{
	if (!s_isValid && s_hasNotified)
	{
		gbUnload = true;
		return;
	}

#if IS_LIVE_CLIENT
	constexpr uint8_t salt[8] = { 0x04, 0xc4, 0x57, 0xbf, 0x31, 0xd3, 0x62, 0x5a };
	constexpr uint8_t hashes[25][8] = {
		{0xc3, 0x33, 0x27, 0x8c, 0xc9, 0x9c, 0x4f, 0xe1},
		{0x11, 0xa7, 0xac, 0x4a, 0x03, 0x79, 0x29, 0xb8},
		{0x72, 0x63, 0x78, 0xde, 0x7c, 0xb6, 0xfe, 0xa2},
		{0xbe, 0x49, 0xa1, 0xf3, 0x9d, 0xc9, 0xfa, 0x84},
		{0x09, 0xaf, 0x0d, 0xf3, 0x42, 0xd0, 0xd0, 0x54},
		{0xdc, 0x42, 0x3a, 0x35, 0xe6, 0x90, 0xbb, 0xe4},
		{0xe6, 0x18, 0xee, 0x6a, 0x4b, 0xe9, 0x55, 0x7e},
		{0x86, 0x6d, 0x4b, 0x14, 0x9d, 0x44, 0x5e, 0x81},
		{0x50, 0x73, 0x0f, 0x9b, 0x6b, 0x92, 0x61, 0x34},
		{0xa7, 0x7d, 0xca, 0x36, 0x27, 0x84, 0x87, 0xfe},
		{0xeb, 0xb9, 0x82, 0x87, 0x75, 0x28, 0x05, 0xaf},
		{0x34, 0xc2, 0xd0, 0xe7, 0xda, 0x1e, 0xea, 0xc1},
		{0xf6, 0x55, 0x1e, 0x82, 0x24, 0x38, 0xa3, 0xf5},
		{0x10, 0xae, 0x3e, 0x85, 0xef, 0x62, 0x15, 0x3f},
		{0x13, 0x1f, 0x73, 0x7e, 0xe2, 0xb9, 0x31, 0x44},
		{0xc9, 0x8c, 0xe1, 0xcc, 0x98, 0xe4, 0x64, 0x91},
		{0xd0, 0x66, 0xe6, 0x98, 0x70, 0xac, 0x09, 0x4a},
		{0x89, 0xe1, 0xdc, 0x85, 0x3f, 0xe9, 0x13, 0xab},
		{0x40, 0x46, 0xa8, 0x55, 0x52, 0xc1, 0x99, 0x27},
		{0x12, 0xc3, 0x8c, 0x05, 0xf2, 0xad, 0xa4, 0x54},
		{0x3f, 0x4b, 0x77, 0x94, 0x1f, 0x1f, 0x85, 0xd1},
		{0x3e, 0xb1, 0x87, 0x6c, 0x2a, 0xe5, 0x1f, 0x21},
		{0xe6, 0x57, 0xf9, 0x13, 0x93, 0xac, 0xea, 0x4a},
		{0x93, 0x53, 0x3d, 0x8d, 0x37, 0x48, 0xd0, 0x7c},
		{0xab, 0xbc, 0x07, 0x9f, 0x3e, 0xe3, 0x66, 0xde},
	};

	const auto now = std::chrono::steady_clock::now();

	static std::mt19937 generator{ std::random_device{}() };
	static std::uniform_int_distribution<unsigned int> distribution{ 30, 60 };
	static std::chrono::steady_clock::time_point next_check = now + std::chrono::seconds(distribution(generator));

	if (s_isValid && now > next_check)
	{
		next_check = now + std::chrono::seconds(distribution(generator));
		const char* name = GetServerShortName();
		const size_t len = strlen(name);

		if (len > 0)
		{
			uint8_t hash[8];
			const int argon2_err = argon2id_hash_raw(
				1, 8, 1,
				name, len, salt,
				8, hash, 8);

			const auto valid = [&hash](const uint8_t* test)
				{
					for (uint8_t idx = 0; idx < 8; ++idx)
						if (hash[idx] != test[idx]) return false;

					return true;
				};

			if (argon2_err == ARGON2_OK)
			{
				for (const auto* test : hashes)
					if (valid(test)) return;

				s_isValid = false;
			}

		}
	}

	if (!s_isValid && !s_hasNotified)
	{
		pipeclient::SendNotification("MQ does not support this server, unloading", "Invalid Server");
		s_hasNotified = true;
	}
#endif
}

static void PostZoneDetours()
{
	if (GetServerIDFromServerName(GetServerShortName()) == ServerID::Invalid)
	{
		// unload
		WriteChatf("MQ does not function on this server: %s -- UNLOADING", GetServerShortName());
		DoCommand("/unload", false);
	}
}

#else

static void InitializeDetours()
{
}

static void ShutdownDetours()
{
}

static void PulseDetours()
{
}

static void PostZoneDetours()
{
}

#endif // !IS_EMU_CLIENT

static void CheckGameState()
{
	static int lastGameState = gGameState;

	if (lastGameState != gGameState)
	{
		LOG_INFO("GameState Change: {} -> {}", lastGameState, gGameState);
		lastGameState = gGameState;
	}

	// Testing for in game flags
	if (gGameState == GAMESTATE_INGAME)
	{
		if (!pLocalPC)
			LOG_ERROR("InGame with no pLocalPC");

		if (pLocalPC)
		{
			if (pLocalPC->me != pLocalPlayer)
				LOG_ERROR("pLocalPC->me ({}) is different than pLocalPlayer ({})",
					(void*)pLocalPC->me, (void*)pLocalPlayer.get());
		}

		if (!pControlledPlayer)
			LOG_ERROR("InGame with no pControlledPlayer");
		if (!pLocalPlayer)
			LOG_ERROR("InGame with no pLocalPlayer");

		// Check UI state
		if (!pPlayerWnd)
			LOG_ERROR("InGame with no pPlayerWnd");
		if (!gbInZone)
			LOG_ERROR("InGame but not gbInZone");
	}
	else if (gGameState == GAMESTATE_CHARSELECT)
	{
		if (!pLocalPC)
			LOG_ERROR("At CharSelect without pLocalPC");
		else if (pLocalPC->me != nullptr)
		{
			// Me should be null
			LOG_ERROR("At CharSelect with pLocalPC->me ({} {})", (void*)pLocalPC->me, pLocalPC->me->Name);
		}

		if (!pLocalPlayer)
			LOG_ERROR("At CharSelect without pLocalPlayer");
		if (!pControlledPlayer)
			LOG_ERROR("At CharSelect without pControlledPlayer");

		// Check UI state
		if (pPlayerWnd)
			LOG_ERROR("Not InGame with pPlayerWnd");

		if (!gbInZone)
			LOG_ERROR("At CharSelect without gbInZone");
	}

	if (pLocalPC)
	{
		if (pLocalPC->ProfileManager.GetCurrentProfile() == nullptr)
			LOG_ERROR("pLocalPC exists but CurrentProfile does not");
	}
	else if (pLocalPlayer)
	{
		LOG_ERROR("pLocalPlayer exists but pLocalPC doesn't");
	}

	if (pLocalPlayer && !pControlledPlayer)
	{
		LOG_ERROR("pLocalPlayer ({}) exists but no pControlledPlayer ({})",
			(void*)pLocalPlayer.get(), (void*)pControlledPlayer.get());
	}

	// Check for changes.
	static PcClient* OldLocalPC = nullptr;
	static PlayerClient* OldControlledPlayer = nullptr;
	static PlayerClient* OldLocalPlayer = nullptr;
	static PlayerClient* OldMe = nullptr;

	if (test_and_set(OldLocalPC, pLocalPC.get()))
		LOG_INFO("pLocalPC Changed: {}", (void*)pLocalPC.get());

	if (test_and_set(OldControlledPlayer, pControlledPlayer.get()))
		LOG_INFO("pControlledPlayer Changed: {} {}", (void*)pControlledPlayer.get(), pControlledPlayer ? pControlledPlayer->Name : "<null>");
	if (test_and_set(OldLocalPlayer, pLocalPlayer.get()))
		LOG_INFO("pLocalPlayer Changed: {} {}", (void*)pLocalPlayer.get(), pLocalPlayer ? pLocalPlayer->Name : "<null>");

	PlayerClient* pMe = pLocalPC ? pLocalPC->me : nullptr;
	if (test_and_set(OldMe, pMe))
		LOG_INFO("pLocalPC->Me Changed: {} {}", (void*)pMe, pMe ? pMe->Name : "<null>");
}

//----------------------------------------------------------------------------

class DetoursModule : public MQModule
{
public:
	DetoursModule() : MQModule("Detours")
	{
	}

	virtual void Initialize() override
	{
		InitializeDetours();
	}

	virtual void Shutdown() override
	{
		ShutdownDetours();
	}

	virtual void OnProcessFrame() override
	{
		PulseDetours();
	}

	virtual void OnPostZoneUI() override
	{
		PostZoneDetours();
	}
};

DECLARE_MODULE_FACTORY(DetoursModule)

//============================================================================

} // namespace mq
