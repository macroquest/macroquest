/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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

#include <detours/detours.h>

namespace mq {

//============================================================================

static Detour* s_detourMap = nullptr;

Detour::Detour(uintptr_t address, void** target, void* detour, const std::string_view name)
	: m_address(address)
	, m_name(name)
	, m_target(target)
	, m_detour(detour)
	, next(nullptr)
	, prev(nullptr)
{
	memcpy(m_bytes, reinterpret_cast<uint8_t*>(address), DETOUR_COUNT);
	*m_target = reinterpret_cast<void*>(address);

	DetourRestoreAfterWith();

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(m_target, m_detour);
	DetourTransactionCommit();
}

Detour::Detour(uintptr_t address, const std::string_view name)
	: m_address(address)
	, m_name(name)
	, m_target(nullptr)
	, m_detour(nullptr)
	, next(nullptr)
	, prev(nullptr)
{
	memcpy(m_bytes, reinterpret_cast<uint8_t*>(address), DETOUR_COUNT);
}

Detour::~Detour()
{
	DetourRestoreAfterWith();

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach(m_target, m_detour);
	DetourTransactionCommit();
}

void Detour::AddToMap()
{
	prev = nullptr;
	next = s_detourMap;
	s_detourMap = this;
	if (next != nullptr)
		next->prev = this;
}

void Detour::RemoveFromMap()
{
	if (prev != nullptr)
		prev->next = next;
	else
		s_detourMap = next;

	if (next != nullptr)
		next->prev = prev;
}

void RemoveDetour(uintptr_t address)
{
	auto detour = s_detourMap;
	while (detour != nullptr)
	{
		if (detour->Address() == address)
		{
			detour->Drop();
			delete detour;
			return;
		}
		
		detour = detour->next;
	}
}

bool gbDoingSpellChecks = false;
int gbInMemCheck4 = 0;

void RemoveDetours()
{
	auto detour = s_detourMap;
	while (detour != nullptr)
	{
		auto next = detour->next;
		delete detour;
		detour = next;
	}
}

void SetAssist(BYTE* address)
{
	gbAssistComplete = AS_AssistReceived;

	if (!address) return;
	DWORD Assistee = *(DWORD*)address;

	if (SPAWNINFO* pSpawn = GetSpawnByID(Assistee))
		gbAssistComplete = AS_AssistSent;
}

// Defined in AssemblyFunctions.asm, need the forward declare
void GetAssistParam();

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

	if (hopcode == EQ_ASSIST)
	{
		GetAssistParam();
	}

	return hopcode;
}
#pragma optimize("", on)

//============================================================================

class SpellManager_Detours
{
public:
	bool LoadTextSpells_Detour(char* FileName, char* AssocFileName, EQ_Spell* SpellArray, SpellAffectData* EffectArray)
	{
		gbDoingSpellChecks = true;
		bool ret = LoadTextSpells_Trampoline(FileName, AssocFileName, SpellArray, EffectArray);
		gbDoingSpellChecks = false;
		return ret;
	}

	DETOUR_TRAMPOLINE_DEF(bool, LoadTextSpells_Trampoline, (char*, char*, EQ_Spell*, SpellAffectData*))
};

//============================================================================

class CDisplay_Detours
{
public:
	void ZoneMainUI_Detour()
	{
		if (GetServerIDFromServerName(EQADDR_SERVERNAME) == ServerID::Invalid)
		{
			// unload
			WriteChatf("MQ2 does not function on this server: %s -- UNLOADING", EQADDR_SERVERNAME);
			EzCommand("/unload");
		}

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

int memcheck0(unsigned char* buffer, size_t count);
int memcheck1(unsigned char* buffer, size_t count, mckey key);
int memcheck2(unsigned char* buffer, size_t count, mckey key);
int WINAPI memcheck4(unsigned char* buffer, size_t* count);

// ***************************************************************************
// Function:    HookMemChecker
// Description: Hook MemChecker
// ***************************************************************************
DETOUR_TRAMPOLINE_DEF(int, memcheck0_tramp, (unsigned char* buffer, size_t count))
DETOUR_TRAMPOLINE_DEF(int, memcheck1_tramp, (unsigned char* buffer, size_t count, mckey key))
DETOUR_TRAMPOLINE_DEF(int, memcheck2_tramp, (unsigned char* buffer, size_t count, mckey key))
DETOUR_TRAMPOLINE_DEF(int, memcheck3_tramp, (unsigned char* buffer, size_t count, mckey key))
DETOUR_TRAMPOLINE_DEF(int WINAPI, memcheck4_tramp, (unsigned char* buffer, size_t* count))

void HookMemChecker(bool Patch)
{
	DebugSpew("HookMemChecker - %satching", (Patch) ? "P" : "Unp");

	if (Patch)
	{
		EzDetour(__MemChecker0, memcheck0, memcheck0_tramp);
		EzDetour(__MemChecker1, memcheck1, memcheck1_tramp);
		EzDetour(__MemChecker2, memcheck2, memcheck2_tramp);
		EzDetour(__MemChecker3, memcheck2, memcheck3_tramp); // shares same impl as memcheck2.
		EzDetour(__MemChecker4, memcheck4, memcheck4_tramp);

		EzDetour(CPacketScrambler__ntoh, &CPacketScrambler_Detours::ntoh_Detour, &CPacketScrambler_Detours::ntoh_Trampoline);
		EzDetour(Spellmanager__LoadTextSpells, &SpellManager_Detours::LoadTextSpells_Detour, &SpellManager_Detours::LoadTextSpells_Trampoline);
		EzDetour(CDisplay__ZoneMainUI, &CDisplay_Detours::ZoneMainUI_Detour, &CDisplay_Detours::ZoneMainUI_Trampoline);
		EzDetour(CDisplay__PreZoneMainUI, &CDisplay_Detours::PreZoneMainUI_Detour, &CDisplay_Detours::PreZoneMainUI_Trampoline);
	}
	else
	{
		RemoveDetour(__MemChecker0);
		RemoveDetour(__MemChecker1);
		RemoveDetour(__MemChecker2);
		RemoveDetour(__MemChecker3);
		RemoveDetour(__MemChecker4);

		RemoveDetour(CPacketScrambler__ntoh);
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

	auto detour = s_detourMap;
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
	auto detour = s_detourMap;
	while (detour != nullptr)
	{
		if (address >= detour->Address() && address < detour->Address() + DETOUR_COUNT)
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

void InitializeDetours()
{
	// hit the debugger if we don't hook this. take no chances
	if (!__MemChecker0
		|| !__MemChecker1
		|| !__MemChecker2
		|| !__MemChecker3
		|| !__MemChecker4
		|| !__EncryptPad0)
	{
		__debugbreak();
	}

	extern_array0 = reinterpret_cast<uint32_t*>(__EncryptPad0);

	HookMemChecker(true);

	uintptr_t GetProcAddress_Addr = (uintptr_t)&::GetProcAddress;
	EzDetour(GetProcAddress_Addr, &GetProcAddress_Detour, &GetProcAddress_Trampoline);
	EzDetour(__ModuleList, FindModules_Detour, FindModules_Trampoline);
}

void ShutdownDetours()
{
	uintptr_t GetProcAddress_Addr = (uintptr_t)&::GetProcAddress;
	RemoveDetour(GetProcAddress_Addr);
	RemoveDetour(__ModuleList);

	HookMemChecker(false);
	RemoveDetours();

	s_detourMap = nullptr;
}

} // namespace mq
