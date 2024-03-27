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
#include "MQ2Main.h"
#include "CrashHandler.h"

#include <detours/detours.h>

namespace mq {

//============================================================================

bool gbDoingSpellChecks = false;
int gbInMemCheck4 = 0;

class Detour;
static Detour* s_detourList = nullptr;

class Detour final
{
public:
	Detour(uintptr_t address, void** target, void* detour, std::string_view name)
		: m_address(address)
		, m_name(name)
		, m_target(target)
		, m_detour(detour)
	{
		memcpy(m_bytes, reinterpret_cast<uint8_t*>(address), DETOUR_BYTES_COUNT);
		*m_target = reinterpret_cast<void*>(address);

		//SPDLOG_DEBUG("Add detour: {} at {}: {} -> {}", m_name, (void*)m_address,
		//	(void*)m_target, (void*)m_detour);

		DetourTransactionBegin();
		DetourAttach(m_target, m_detour);
		LONG result = DetourTransactionCommit();
		if (result != NO_ERROR)
		{
			SPDLOG_ERROR("Failed to commit detour: {} -> {}", m_name, result);
		}
	}

	Detour(uintptr_t address, std::string_view name)
		: m_address(address)
		, m_name(name)
	{
		memcpy(m_bytes, reinterpret_cast<uint8_t*>(address), DETOUR_BYTES_COUNT);

		//SPDLOG_DEBUG("Add detour (patch): {} at {}", m_name, (void*)m_address);
	}

	~Detour()
	{
		//SPDLOG_DEBUG("Remove detour: {} at {}", m_name, (void*)m_address);

		DetourTransactionBegin();
		DetourDetach(m_target, m_detour);
		DetourTransactionCommit();
	}

	uintptr_t Address() const { return m_address; }
	uint8_t* Bytes() { return reinterpret_cast<uint8_t*>(m_bytes); }

protected:
	static inline uintptr_t GetAddressFromProc(const char* handle, const char* procedure)
	{
		auto mod = ::GetModuleHandleA(handle);
		if (mod != 0)
			return reinterpret_cast<uintptr_t>(GetProcAddress(mod, procedure));

		return {};
	}

	static inline HMODULE GetModuleFromAddress(const uintptr_t address)
	{
		HMODULE mod;
		::GetModuleHandleExA(
			GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
			GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
			(const char*)address,
			&mod);

		return mod;
	}

private:
	const uintptr_t m_address;
	const std::string m_name;
	uint8_t m_bytes[DETOUR_BYTES_COUNT];

	void** m_target = nullptr;
	void* m_detour = nullptr;

public:
	Detour* next = nullptr;
	Detour* prev = nullptr;
};

//============================================================================

static void AddDetourToList(Detour*& head, Detour* detour)
{
	detour->prev = nullptr;
	detour->next = head;
	head = detour;

	if (detour->next != nullptr)
		detour->next->prev = detour;
}

static void RemoveDetourFromList(Detour*& head, Detour* detour)
{
	if (detour->prev != nullptr)
		detour->prev->next = detour->next;
	else
		head = detour->next;

	if (detour->next != nullptr)
		detour->next->prev = detour->prev;
}

void detail::CreateDetour(uintptr_t address, void** target, void* detour, const std::string_view name)
{
	Detour* newDetour = new Detour(address, target, detour, name);
	AddDetourToList(s_detourList, newDetour);
}

void detail::CreateDetour(uintptr_t address, std::string_view name)
{
	Detour* newDetour = new Detour(address, name);
	AddDetourToList(s_detourList, newDetour);
}

void RemoveDetour(uintptr_t address)
{
	Detour* detour = s_detourList;

	while (detour != nullptr)
	{
		if (detour->Address() == address)
		{
			RemoveDetourFromList(s_detourList, detour);
			delete detour;
			return;
		}
		
		detour = detour->next;
	}
}

void RemoveDetours()
{
	auto detour = s_detourList;
	while (detour != nullptr)
	{
		auto next = detour->next;
		delete detour;
		detour = next;
	}
}

// TODO: Maybe someday revisit detection of assist completion...
//void SetAssist(BYTE* address)
//{
//	gbAssistComplete = AS_AssistReceived;
//
//	if (!address) return;
//	int Assistee = *(int*)address;
//
//	if (SPAWNINFO* pSpawn = GetSpawnByID(Assistee))
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

class CDisplay_Detours
{
public:
	void ZoneMainUI_Detour()
	{
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_COTF)
		if (GetServerIDFromServerName(GetServerShortName()) == ServerID::Invalid)
		{
			// unload
			WriteChatf("MQ does not function on this server: %s -- UNLOADING", GetServerShortName());
			EzCommand("/unload");
		}
#endif

		PluginsEndZone();
		ZoneMainUI_Trampoline();
	}

	DETOUR_TRAMPOLINE_DEF(void, ZoneMainUI_Trampoline, ())

	void PreZoneMainUI_Detour()
	{
		PluginsBeginZone();
		PreZoneMainUI_Trampoline();
	}

	DETOUR_TRAMPOLINE_DEF(void, PreZoneMainUI_Trampoline, ())
};

//============================================================================

void PatchMemory(void* dest, void* src, size_t length)
{
	HANDLE hProcess = GetCurrentProcess();

	DWORD oldPerms = 0;
	VirtualProtectEx(hProcess, dest, length, PAGE_EXECUTE_READWRITE, &oldPerms);
	WriteProcessMemory(hProcess, dest, src, length, nullptr);
	VirtualProtectEx(hProcess, dest, length, oldPerms, &oldPerms);
}

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

// ***************************************************************************
// Function:    HookMemChecker
// Description: Hook MemChecker
// ***************************************************************************
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

		//EzDetour(CPacketScrambler__ntoh, &CPacketScrambler_Detours::ntoh_Detour, &CPacketScrambler_Detours::ntoh_Trampoline);
		EzDetour(Spellmanager__LoadTextSpells, &SpellManager_Detours::LoadTextSpells_Detour, &SpellManager_Detours::LoadTextSpells_Trampoline);
		EzDetour(CDisplay__ZoneMainUI, &CDisplay_Detours::ZoneMainUI_Detour, &CDisplay_Detours::ZoneMainUI_Trampoline);
		EzDetour(CDisplay__PreZoneMainUI, &CDisplay_Detours::PreZoneMainUI_Detour, &CDisplay_Detours::PreZoneMainUI_Trampoline);
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
		RemoveDetour(CDisplay__ZoneMainUI);
		RemoveDetour(CDisplay__PreZoneMainUI);
	}
}

enum class AddressDetourState {
	None = 0,
	CodeDetour = 1,
	KnownSkippable = 2,
};

AddressDetourState IsAddressDetoured(uintptr_t address, size_t count)
{
	if (gbDoingSpellChecks || gbInMemCheck4 > 0)
		return AddressDetourState::KnownSkippable;

	// Executables start with a header that has 'MZ\x90\x00'. This is checking for this
	// magic value and skipping the crc32 of an executable since we don't care about those.
	if (address && count >= 4 && *(DWORD*)address == 0x00905a4d)
		return AddressDetourState::KnownSkippable;

	auto detour = s_detourList;
	while (detour != nullptr)
	{
		if (address <= detour->Address() && detour->Address() <= address + count)
			return AddressDetourState::CodeDetour;

		detour = detour->next;
	}

	return AddressDetourState::None;
}

inline uint8_t GetDetouredByte(uintptr_t address, uint8_t original)
{
	auto detour = s_detourList;
	while (detour != nullptr)
	{
		if (address >= detour->Address() && address < detour->Address() + DETOUR_BYTES_COUNT)
		{
			uint8_t* bytes = detour->Bytes();
			return *(bytes + address - detour->Address());
		}

		detour = detour->next;
	}

	return original;
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

	unsigned int crc32 = 0xffffffff;

	for (size_t i = 0; i < count; i++)
	{
		// Feed in bytes to the hash algorithm using the source bytes of a detour
		// if the data range overlaps an active detour.
		uint8_t value = GetDetouredByte(addr + i, buffer[i]);

		int x = (int)value ^ (crc32 & 0xff);
		crc32 = ((int)crc32 >> 8) & 0xffffff;
		x = extern_array0[x];
		crc32 ^= x;
	}

	return crc32;
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

	for (size_t i = 0; i < count; i++)
	{
		uint8_t value = GetDetouredByte(addr + i, buffer[i]);

		ebx = ((int)value ^ eax) & 0xff;
		eax = ((int)eax >> 8) & 0xffffff;
		eax ^= extern_array0[ebx];
	}
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

	for (size_t i = 0; i < count; i++)
	{
		uint8_t value = GetDetouredByte(addr + i, buffer[i]);

		ebx = ((int)value ^ edx) & 0xff;
		edx = ((int)edx >> 8) & 0xffffff;
		edx ^= extern_array0[ebx];
	}

	eax = ~edx;
	return eax;
}
#endif // defined(__MemChecker2) || defined(__MemChecker3)

#if defined(__MemChecker4_x)
int WINAPI memcheck4(unsigned char* buffer, size_t* count_)
{
	uintptr_t addr = reinterpret_cast<uintptr_t>(buffer);
	size_t count = *count_ & 0xff;

	// If we are not detouring memory that overlaps this region, just let it pass through.
	AddressDetourState detourState = IsAddressDetoured(addr, count);
	if (detourState != AddressDetourState::CodeDetour)
	{
		gbInMemCheck4 = 1;
		int result = memcheck4_tramp(buffer, count_);
		gbInMemCheck4 = 0;
		return result;
	}

	unsigned int crc32 = 0xffffffff;

	for (size_t i = 0; i < count; i++)
	{
		// Feed in bytes to the hash algorithm using the source bytes of a detour
		// if the data range overlaps an active detour.
		uint8_t value = GetDetouredByte(addr + i, buffer[i]);

		int x = (int)value ^ (crc32 & 0xff);
		crc32 = ((int)crc32 >> 8) & 0xffffff;
		x = extern_array0[x];
		crc32 ^= x;
	}

	return crc32;
}
#endif // defined(__MemChecker4_x)

void TryInitializeLogin();

DETOUR_TRAMPOLINE_DEF(void* WINAPI, GetProcAddress_Trampoline, (HMODULE, LPCSTR))
void* WINAPI GetProcAddress_Detour(HMODULE hModule, LPCSTR lpProcName)
{
	if (void* result = GetProcAddress_Trampoline(hModule, lpProcName))
	{
		// This is the trigger for loading the eqmain.dll
		if (hModule == *ghEQMainInstance && std::string_view{ lpProcName } == "new_dll_main")
			TryInitializeLogin();

		return result;
	}

	return nullptr;
}

DETOUR_TRAMPOLINE_DEF(BOOL WINAPI, FindModules_Trampoline, (HANDLE, HMODULE*, DWORD, DWORD*))
BOOL WINAPI FindModules_Detour(HANDLE hProcess, HMODULE* hModule, DWORD cb, DWORD* lpcbNeeded)
{
	if (gbInMemCheck4 != 1) return FindModules_Trampoline(hProcess, hModule, cb, lpcbNeeded);
	++gbInMemCheck4;
	bool getMacroQuestModules = true;
	BOOL result = GetFilteredModules(hProcess, hModule, cb, lpcbNeeded,
		[&getMacroQuestModules](HMODULE hModule) -> bool { return IsMacroQuestModule(hModule, getMacroQuestModules); }) ? TRUE : FALSE;
	--gbInMemCheck4;
	return result;
}

DETOUR_TRAMPOLINE_DEF(BOOL WINAPI, FindProcesses_Trampoline, (DWORD*, DWORD, DWORD*))
BOOL WINAPI FindProcesses_Detour(DWORD* lpidProcess, DWORD cb, DWORD* lpcbNeeded)
{
	if (gbInMemCheck4 != 1) return FindProcesses_Trampoline(lpidProcess, cb, lpcbNeeded);
	++gbInMemCheck4;
	bool getMacroQuestProcesses = true;
	BOOL result = GetFilteredProcesses(lpidProcess, cb, lpcbNeeded,
		[&getMacroQuestProcesses](char process_name[MAX_PATH]) -> bool { return IsMacroQuestProcess(process_name, getMacroQuestProcesses); }) ? TRUE : FALSE;
	--gbInMemCheck4;
	return result;
}

#if defined(__ExceptionFilter_x)
// Exception filter hook for ROF2 emu. The game loop is wrapped in a __try/__except with this function
// as its filter. We will capture the exception pointer and pass it to our UnhandledExceptionFilter function.
DETOUR_TRAMPOLINE_DEF(void, ExceptionFilter_Trampoline, (EXCEPTION_POINTERS*, void*, void*));
void ExceptionFilter_Detour(EXCEPTION_POINTERS* pointers, void* a, void* b)
{
	UNUSED(a);
	UNUSED(b);

	InvokeExceptionHandler(pointers);
}

#endif // defined(__ExceptionFilter_x)

void InitializeDetours()
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

	uintptr_t GetProcAddress_Addr = (uintptr_t)&::GetProcAddress;
	EzDetour(GetProcAddress_Addr, &GetProcAddress_Detour, &GetProcAddress_Trampoline);
	EzDetour(__ModuleList, FindModules_Detour, FindModules_Trampoline);
	EzDetour(__ProcessList, FindProcesses_Detour, FindProcesses_Trampoline);

#if defined(__ExceptionFilter_x)
	EzDetour(__ExceptionFilter, ExceptionFilter_Detour, ExceptionFilter_Trampoline);
#endif
}

void ShutdownDetours()
{
	uintptr_t GetProcAddress_Addr = (uintptr_t)&::GetProcAddress;
	RemoveDetour(GetProcAddress_Addr);
	RemoveDetour(__ModuleList);
	RemoveDetour(__ProcessList);

#if defined(__ExceptionFilter_x)
	RemoveDetour(__ExceptionFilter);
#endif

	HookMemChecker(false);
	RemoveDetours();

	s_detourList = nullptr;
}

} // namespace mq
