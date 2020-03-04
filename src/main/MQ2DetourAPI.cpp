/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
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

#define DEBUG_GETPROCADDRESS 1

namespace mq {

struct DetourRecord
{
/*0x00*/ uint32_t      addr;
/*0x04*/ uint32_t      count;
/*0x08*/ char          Name[0x64];
/*0x6c*/ uint8_t       array[0x40];
/*0xac*/ uint8_t*      pfDetour;
/*0xb0*/ uint8_t*      pfTrampoline;
/*0xb4*/ DetourRecord* pNext;
/*0xb8*/ DetourRecord* pLast;
/*0xbc*/
};

MQLIB_VAR DetourRecord* g_detours = nullptr;
std::recursive_mutex g_detourMutex;
bool g_bDoingSpellChecks = false;

DetourRecord* FindDetour(DWORD address)
{
	DetourRecord* pDetour = g_detours;
	while (pDetour)
	{
		if (pDetour->addr == address)
			return pDetour;
		pDetour = pDetour->pNext;
	}

	return nullptr;
}

bool AddDetour(DWORD address, BYTE* pfDetour, BYTE* pfTrampoline, DWORD Count, const char* Name)
{
	std::scoped_lock lock(g_detourMutex);

	char szName[MAX_STRING] = { 0 };

	if (Name && Name[0] != '\0')
	{
		strcpy_s(szName, Name);
	}
	else
	{
		strcpy_s(szName, "Unknown");
	}

	bool Ret = true;
	DebugSpew("AddDetour(%s, 0x%X, 0x%X, 0x%X, 0x%X)", szName, address, pfDetour, pfTrampoline, Count);
	if (FindDetour(address))
	{
		DebugSpew("Address for %s (0x%x) already detoured.", szName, address);
		return false;
	}

	DetourRecord* detour = new DetourRecord;
	strcpy_s(detour->Name, szName);
	detour->addr = address;
	detour->count = Count;
	memcpy(detour->array, (char*)address, Count);
	detour->pNext = g_detours;
	if (g_detours)
		g_detours->pLast = detour;
	detour->pLast = nullptr;

	if (pfTrampoline)
	{
		// its an indirect jump, likely due to incremental linking. The actual
		// function body is at the other end of the jump. We need to follow it.
		if (pfTrampoline[0] == 0xe9)
		{
			pfTrampoline = pfTrampoline + *(DWORD*)&pfTrampoline[1] + 5;
		}
		if (pfTrampoline[0] && pfTrampoline[1])
		{
			DWORD oldperm = 0, tmp;
			VirtualProtectEx(GetCurrentProcess(), (void*)pfTrampoline, 2, PAGE_EXECUTE_READWRITE, &oldperm);
			pfTrampoline[0] = 0x90;
			pfTrampoline[1] = 0x90;
			VirtualProtectEx(GetCurrentProcess(), (void*)pfTrampoline, 2, oldperm, &tmp);
		}
	}

	if (pfDetour && !DetourFunctionWithEmptyTrampoline(pfTrampoline, (BYTE*)address, pfDetour))
	{
		detour->pfDetour = nullptr;
		detour->pfTrampoline = nullptr;
		Ret = false;
		DebugSpew("Detour of %s failed.", szName);
	}
	else
	{
		detour->pfDetour = pfDetour;
		detour->pfTrampoline = pfTrampoline;
		DebugSpew("Detour of %s was successful.", szName);
	}

	g_detours = detour;
	return Ret;
}

void AddDetourf(DWORD address, ...)
{
	va_list marker;
	int i = 0;

	va_start(marker, address);
	DWORD Parameters[4] = { 0 };
	DWORD nParameters = 0;
	while (i != -1)
	{
		if (nParameters < 4)
		{
			Parameters[nParameters] = i;
			nParameters++;
		}
		else
		{
			// we can break out now...
			break;
		}
		i = va_arg(marker, int);
	}
	va_end(marker);

	if (nParameters == 4)
	{
		AddDetour(address, (BYTE*)Parameters[1], (BYTE*)Parameters[2], 20, (char*)Parameters[3]);
	}
	else
	{
		DebugSpew("Illegal AddDetourf call");
	}
}

void RemoveDetour(DWORD address)
{
	std::scoped_lock lock(g_detourMutex);

	DetourRecord* detour = g_detours;
	char szFilename[MAX_STRING] = { 0 };
	HMODULE hModule = nullptr;
	DWORD myaddress = 0;

	_strlwr_s(szFilename);
	while (detour)
	{
		if (detour->addr == address)
		{
			if (detour->pfDetour)
			{
				if (hModule == nullptr)
				{
					GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)address, &hModule);
					myaddress = (DWORD)hModule;
					GetModuleFileName(hModule, szFilename, MAX_STRING);

					if (char* pDest = strrchr(szFilename, '\\'))
					{
						pDest[0] = '\0';
						strcpy_s(szFilename, &pDest[1]);
					}
				}

				if (strstr(szFilename, "eqgame"))
					DebugSpewAlways("DetourRemove %s (%s [0x%08X])", detour->Name, szFilename, address - myaddress + 0x400000);
				else
					DebugSpewAlways("DetourRemove %s (%s [0x%08X])", detour->Name, szFilename, address - myaddress + 0x10000000);

				DetourRemove(detour->pfTrampoline, detour->pfDetour);

				// sometimes its useful to add and then remove a detour and then add it again... and so on...
				// the following 2 lines fixes a detours "bug"
				// I don't know if this was MS intention, but if we don't set these to nop
				// we cant detour the same function more than once... so dont remove these.

				DWORD oldperm = 0, tmp;
				VirtualProtectEx(GetCurrentProcess(), (void*)detour->pfTrampoline, 2, PAGE_EXECUTE_READWRITE, &oldperm);
				detour->pfTrampoline[0] = 0x90;
				detour->pfTrampoline[1] = 0x90;
				VirtualProtectEx(GetCurrentProcess(), (void*)detour->pfTrampoline, 2, oldperm, &tmp);
			}

			if (detour->pLast)
				detour->pLast->pNext = detour->pNext;
			else
				g_detours = detour->pNext;

			if (detour->pNext)
				detour->pNext->pLast = detour->pLast;

			delete detour;
			return;
		}
		detour = detour->pNext;
	}

	if (strstr(szFilename, "eqgame"))
		DebugSpewAlways("Detour for (%s [0x%08X]) not found in RemoveDetour()", szFilename, address - myaddress + 0x400000);
	else
		DebugSpewAlways("Detour for (%s [0x%08X]) not found in RemoveDetour()", szFilename, address - myaddress + 0x10000000);
}

void DeleteDetour(DWORD address)
{
	std::scoped_lock lock(g_detourMutex);

	DetourRecord* detour = g_detours;
	while (detour)
	{
		if (detour->addr == address)
		{
			DebugSpew("Deleted %s (%X)", detour->Name, ((DWORD)GetModuleHandle(nullptr) - address + 0x400000));
			if (detour->pLast)
				detour->pLast->pNext = detour->pNext;
			else
				g_detours = detour->pNext;

			if (detour->pNext)
				detour->pNext->pLast = detour->pLast;
			delete detour;
			return;
		}
		detour = detour->pNext;
	}
	DebugSpew("Failed Deleting (%X)", ((DWORD)GetModuleHandle(nullptr) - address + 0x400000));
}

void RemoveDetours()
{
	std::scoped_lock lock(g_detourMutex);
	DebugSpew("RemoveOurDetours()");

	if (!g_detours)
		return;

	while (g_detours)
	{
		if (g_detours->pfDetour)
		{
			DebugSpew("RemoveOurDetours() -- Removing %s (%X)", g_detours->Name, g_detours->addr);
			RemoveDetour(g_detours->addr);
		}

		if (g_detours)
		{
			DetourRecord* pNext = g_detours->pNext;
			delete g_detours;
			g_detours = pNext;
		}
	}

	g_detours = nullptr;
}

void SetAssist(BYTE* address)
{
	if ((DWORD)address == -1)
		return;

	bool bExpectTarget = false;
	if (address)
	{
		if (DWORD Assistee = *(DWORD*)address)
		{
			if (SPAWNINFO* pSpawn = (SPAWNINFO*)GetSpawnByID(Assistee))
			{
				bExpectTarget = true;
				gbAssistComplete = AS_AssistSent;
				//WriteChatf("We can expect a target packet because assist retuned %s", pSpawn->Name);
			}
		}
	}

	if (!bExpectTarget)
	{
		//WriteChatColor("We can NOT expect a target packet because assist was 0");
		gbAssistComplete = AS_AssistReceived;
	}
}

//============================================================================
//============================================================================

class CPacketScrambler_Detours
{
public:
	int ntoh_Trampoline(int);
	int ntoh_Detour(int nopcode);
};
DETOUR_TRAMPOLINE_EMPTY(int CPacketScrambler_Detours::ntoh_Trampoline(int));

using fGetAssistCalc = DWORD(*)(DWORD);
static fGetAssistCalc GetAssistCalc = nullptr;

// ntoh_detour actually climbs into the stack and pulls data out from the caller's
// stack frame. Because of this we need to avoid optimizing this function as it
// changes the layout of the stack. Keep optimizations off for this function or
// it will break.
#pragma optimize("", off)
int CPacketScrambler_Detours::ntoh_Detour(int nopcode)
{
	int hopcode = ntoh_Trampoline(nopcode);

#if 0
	if (hopcode == EQ_ASSIST_COMPLETE) {
		DWORD calc = 0;
		__asm {
			push eax;
			push ebx;
			mov eax, dword ptr[esi + 0x19];
			mov ebx, dword ptr[esi + 0x15];
			xor eax, ebx;
			mov calc, eax;
			pop ebx;
			pop eax;
		};
		DWORD assistflag = 0;
		if (GetAssistCalc = (fGetAssistCalc)GetProcAddress(ghmq2ic, "GetAssistCalc")) {
			assistflag = GetAssistCalc(calc);
		}
		SetAssist((BYTE*)assistflag);
	}
#endif
	if (hopcode == EQ_ASSIST)
	{
		__asm {
			push eax;
			mov eax, dword ptr[ebp];
			test eax, eax;
			jz emptyassist;
			mov eax, dword ptr[eax + 0x10];
			test eax, eax;
			jz emptyassist;
			push eax;
			call SetAssist;
			pop eax;
		emptyassist:
			pop eax;
		};
	}

	return hopcode;
}
#pragma optimize("", on)

//============================================================================

class Spellmanager
{
public:
	bool LoadTextSpells_Trampoline(char*, char*, EQ_Spell*, SPELLCALCINFO*);
	bool LoadTextSpells_Detour(char* FileName, char* AssocFileName, EQ_Spell* SpellArray, SPELLCALCINFO* EffectArray) // SpellAffectData*
	{
		g_bDoingSpellChecks = true;
		bool ret = LoadTextSpells_Trampoline(FileName, AssocFileName, SpellArray, EffectArray);
		g_bDoingSpellChecks = false;
		return ret;
	}
};
DETOUR_TRAMPOLINE_EMPTY(bool Spellmanager::LoadTextSpells_Trampoline(char*, char*, EQ_Spell*, PSPELLCALCINFO));

//============================================================================

// helper function just initializes stack space so that sending an email
// doesn't send uninitialized memory.
void emotify();

// we need this detour to clean up the stack because emote sends 1024 bytes
// no matter how many bytes in the string, and MQ2 variables get left on the stack
class CEmoteHook
{
public:
	void SendEmote_Trampoline();
	void SendEmote_Detour()
	{
		emotify();
		SendEmote_Trampoline();
	}
};
DETOUR_TRAMPOLINE_EMPTY(void CEmoteHook::SendEmote_Trampoline());

//============================================================================

class CDisplay_Detours
{
public:
	void ZoneMainUI_Trampoline();
	void ZoneMainUI_Detour()
	{
		PluginsEndZone();
		ZoneMainUI_Trampoline();
	}

	void PreZoneMainUI_Trampoline();
	void PreZoneMainUI_Detour()
	{
		PluginsBeginZone();
		PreZoneMainUI_Trampoline();
	}
};
DETOUR_TRAMPOLINE_EMPTY(void CDisplay_Detours::PreZoneMainUI_Trampoline());
DETOUR_TRAMPOLINE_EMPTY(void CDisplay_Detours::ZoneMainUI_Trampoline());

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
unsigned int* extern_array1 = nullptr;
unsigned int* extern_array2 = nullptr;
unsigned int* extern_array3 = nullptr;
unsigned int* extern_array4 = nullptr;

int memcheck0(unsigned char* buffer, size_t count);
int memcheck1(unsigned char* buffer, size_t count, mckey key);
int memcheck2(unsigned char* buffer, size_t count, mckey key);
int memcheck3(unsigned char* buffer, size_t count, mckey key);
int memcheck4(unsigned char* buffer, size_t count, mckey key);

// ***************************************************************************
// Function:    HookMemChecker
// Description: Hook MemChecker
// ***************************************************************************

DETOUR_TRAMPOLINE_EMPTY(int memcheck0_tramp(unsigned char* buffer, size_t count));
DETOUR_TRAMPOLINE_EMPTY(int memcheck1_tramp(unsigned char* buffer, size_t count, mckey key));
DETOUR_TRAMPOLINE_EMPTY(int memcheck2_tramp(unsigned char* buffer, size_t count, mckey key));
DETOUR_TRAMPOLINE_EMPTY(int memcheck3_tramp(unsigned char* buffer, size_t count, mckey key));
DETOUR_TRAMPOLINE_EMPTY(int memcheck4_tramp(unsigned char* buffer, size_t count, mckey key));

void HookInlineChecks(bool Patch)
{
	DWORD cmps[] = {
		__AC1 + 6
	};

	DWORD cmps2[] = {
		__AC2,
		__AC3,
		__AC4,
		__AC5,
		__AC6,
		__AC7
	};

	int len2[] = { 6, 6, 6, 6, 6, 6 };
	char NewData2[20];
	static char OldData2[lengthof(cmps2)][20];

	if (Patch)
	{
		uint32_t NewData = 0x7fffffff;

		for (size_t i = 0; i < lengthof(cmps); i++)
		{
			void* dest = reinterpret_cast<void*>(cmps[i]);
			void* src = &NewData;
			size_t length = 4;

			// Add the detour record
			AddDetour(cmps[i], nullptr, nullptr, 4, "cmps");

			// patch bytes
			PatchMemory(dest, src, length);
		}

		memset(NewData2, 0x90, 20);

		for (size_t i = 0; i < lengthof(cmps2); i++)
		{
			void* dest = reinterpret_cast<void*>(cmps2[i]);
			void* src = NewData2;
			size_t length = len2[i];

			// Add the detour record
			AddDetour(cmps2[i], nullptr, nullptr, length, "cmps2");

			// Make a backup
			memcpy(reinterpret_cast<void*>(OldData2[i]), dest, length);

			// patch bytes
			PatchMemory(dest, src, length);
		}
	}
	else
	{
		uint32_t NewData = __AC1_Data;

		for (size_t i = 0; i < lengthof(cmps); i++)
		{
			void* dest = reinterpret_cast<void*>(cmps[i]);
			void* src = &NewData;
			size_t length = 4;

			// unpatch bytes
			PatchMemory(dest, src, length);

			// Remove detour record
			RemoveDetour(cmps[i]);
		}

		for (size_t i = 0; i < lengthof(cmps2); i++)
		{
			void* dest = reinterpret_cast<void*>(cmps2[i]);
			void* src = reinterpret_cast<void*>(OldData2[i]);
			size_t length = len2[i];

			// unpatch bytes
			PatchMemory(dest, src, length);

			// Remove detour record
			RemoveDetour(cmps2[i]);
		}
	}
}

void HookMemChecker(bool Patch)
{
	// hit the debugger if we don't hook this. take no chances
	if (!EQADDR_MEMCHECK0
		|| !EQADDR_MEMCHECK1
		|| !EQADDR_MEMCHECK2
		|| !EQADDR_MEMCHECK3
		|| !EQADDR_MEMCHECK4)
	{
		__debugbreak();
	}

	DebugSpew("HookMemChecker - %satching", (Patch) ? "P" : "Unp");

	if (Patch) {

		EzDetour(EQADDR_MEMCHECK0, memcheck0, memcheck0_tramp);
		EzDetour(EQADDR_MEMCHECK1, memcheck1, memcheck1_tramp);
		EzDetour(EQADDR_MEMCHECK2, memcheck2, memcheck2_tramp);
		EzDetour(EQADDR_MEMCHECK3, memcheck3, memcheck3_tramp);
		EzDetour(EQADDR_MEMCHECK4, memcheck4, memcheck4_tramp);

		EzDetour(CPacketScrambler__ntoh, &CPacketScrambler_Detours::ntoh_Detour, &CPacketScrambler_Detours::ntoh_Trampoline);
		EzDetour(CEverQuest__Emote, &CEmoteHook::SendEmote_Detour, &CEmoteHook::SendEmote_Trampoline);
		EzDetour(Spellmanager__LoadTextSpells, &Spellmanager::LoadTextSpells_Detour, &Spellmanager::LoadTextSpells_Trampoline);
		EzDetour(CDisplay__ZoneMainUI, &CDisplay_Detours::ZoneMainUI_Detour, &CDisplay_Detours::ZoneMainUI_Trampoline);
		EzDetour(CDisplay__PreZoneMainUI, &CDisplay_Detours::PreZoneMainUI_Detour, &CDisplay_Detours::PreZoneMainUI_Trampoline);

		HookInlineChecks(Patch);
	}
	else
	{
		HookInlineChecks(Patch);

		RemoveDetour(EQADDR_MEMCHECK0);
		RemoveDetour(EQADDR_MEMCHECK1);
		RemoveDetour(EQADDR_MEMCHECK2);
		RemoveDetour(EQADDR_MEMCHECK3);
		RemoveDetour(EQADDR_MEMCHECK4);

		RemoveDetour(CPacketScrambler__ntoh);
		RemoveDetour(CEverQuest__Emote);
		RemoveDetour(Spellmanager__LoadTextSpells);
		RemoveDetour(CDisplay__ZoneMainUI);
		RemoveDetour(CDisplay__PreZoneMainUI);
	}
}

DWORD IsAddressDetoured(uint32_t address, size_t count)
{
	if (g_bDoingModuleChecks)
		return 4;
	if (g_bDoingSpellChecks)
		return 3;

	if (address && *(DWORD*)address == 0x00905a4d)
	{
		// its a executable being checked
		return 2;
	}

	DetourRecord* detour = g_detours;
	while (detour)
	{
		if (IsBadReadPtr(detour, 4))
			return 0;

		if (detour->count && address <= detour->addr && detour->addr <= (address + count))
			return 1;

		detour = detour->pNext;
	}

	return 0;
}

int memcheck0(unsigned char* buffer, size_t count)
{
	int origCrc = memcheck0_tramp(buffer, count);
	unsigned int addr = (int)&buffer[0];

	// If we are not detouring memory that overlaps this region, just let it pass through.
	DWORD dwGetOrg = IsAddressDetoured(addr, count);
	if (dwGetOrg >= 2)
		return origCrc;

	if (!extern_array0)
	{
		if (!EQADDR_ENCRYPTPAD0)
		{
			__debugbreak();
		}

		extern_array0 = reinterpret_cast<uint32_t*>(EQADDR_ENCRYPTPAD0);
	}

	unsigned int eax = 0xffffffff;

	for (size_t i = 0; i < count; i++)
	{
		// Feed in bytes to the hash algorithm using the source bytes of a detour
		// if the data range overlaps an active detour.
		unsigned char tmp = 0;
		if (dwGetOrg == 1)
		{

			unsigned int startAddr = (int)&buffer[i];
			DetourRecord* detour = g_detours;

			while (detour)
			{
				if (detour->count && (startAddr >= detour->addr) && (startAddr < detour->addr + detour->count))
				{
					tmp = detour->array[startAddr - detour->addr];
					break;
				}

				detour = detour->pNext;
			}

			if (!detour)
			{
				tmp = buffer[i];
			}
		}
		else
		{
			tmp = buffer[i];
		}

		int x = (int)tmp ^ (eax & 0xff);
		eax = ((int)eax >> 8) & 0xffffff;
		x = extern_array0[x];
		eax ^= x;
	}

	return eax;
}

using fGetHashSum = DWORD(*)(DWORD,DWORD);
static fGetHashSum GetHashSum = nullptr;

int memcheck5(DWORD count)
{
	if (!GetHashSum)
	{
		GetHashSum = (fGetHashSum)GetProcAddress(ghmq2ic, "GetHashSum");
	}

	if (GetHashSum)
	{
		return GetHashSum(count, __EP1_Data_x);
	}

	return 0;
}

int memcheck1(unsigned char* buffer, size_t count, mckey key)
{
	// leave this here. I uncomment now and then to check the hash -eqmule
	//int realchecksum = memcheck1Tester(buffer, (UINT)count, (int)key.x);
	unsigned int ebx, eax, edx;

	if (!extern_array1)
	{
		if (!EQADDR_ENCRYPTPAD1)
		{
			__debugbreak();
		}

		extern_array1 = (uint32_t*)EQADDR_ENCRYPTPAD1;
	}

	//                push    ebp
	//                mov     ebp, esp
	//                push    esi
	//                push    edi
	//                or      edi, 0FFFFFFFFh
	//                cmp     [ebp+arg_8], 0
	int creset = memcheck5(count);
	if (key.x != 0 && creset == __EncryptPad5_x) {
	//                mov     esi, 0FFh
	//                mov     ecx, 0FFFFFFh
	//                jz      short loc_4C3978
	//                xor     eax, eax
	//                mov     al, byte ptr [ebp+arg_8]
	//                xor     edx, edx
	//                mov     dl, byte ptr [ebp+arg_8+1]
		edx = key.a[1];
	//                not     eax
	//                and     eax, esi
		eax = ~key.a[0] & 0xff;
	//                mov     eax, encryptpad1[eax*4]
		eax = extern_array1[eax];
	//                xor     eax, ecx
		eax ^= 0xffffff;
	//                xor     edx, eax
	//                and     edx, esi
		edx = (edx ^ eax) & 0xff;
	//                sar     eax, 8
	//                and     eax, ecx
		eax = ((int)eax >> 8) & 0xffffff;
	//                xor     eax, encryptpad1[edx*4]
		eax ^= extern_array1[edx];
	//                xor     edx, edx
	//                mov     dl, byte ptr [ebp+arg_8+2]
		edx = key.a[2];
	//                xor     edx, eax
	//                sar     eax, 8
	//                and     edx, esi
		edx = (edx ^ eax) & 0xff;
	//                and     eax, ecx
		eax = ((int)eax >> 8) & 0xffffff;
	//                xor     eax, encryptpad1[edx*4]
		eax ^= extern_array1[edx];
	//                xor     edx, edx
	//                mov     dl, byte ptr [ebp+arg_8+3]
		edx = key.a[3];
	//                xor     edx, eax
	//                sar     eax, 8
	//                and     edx, esi
		edx = (edx ^ eax) & 0xff;
	//                and     eax, ecx
		eax = ((int)eax >> 8) & 0xffffff;
	//                xor     eax, encryptpad1[edx*4]
		eax ^= extern_array1[edx];
	//                mov     edi, eax
	//
	} else { // key.x != 0
		eax = 0xffffffff;
	}
	//loc_4C3978:                             ; CODE XREF: new_memcheck1+16j
	//                mov     edx, [ebp+arg_0]
	//                mov     eax, [ebp+arg_4]
	//                add     eax, edx
	//                cmp     edx, eax
	//                jnb     short loc_4C399F
	//                push    ebx
	//
	//loc_4C3985:                             ; CODE XREF: new_memcheck1+8Fj
	//                xor     ebx, ebx
	//                mov     bl, [edx]
	//                xor     ebx, edi
	//                sar     edi, 8
	//                and     ebx, esi
	//                and     edi, ecx
	//                xor     edi, encryptpad1[ebx*4]
	//                inc     edx
	//                cmp     edx, eax
	//                jb      short loc_4C3985
	//                pop     ebx
	//
	//loc_4C399F:                             ; CODE XREF: new_memcheck1+75j
	//                mov     eax, edi
	//                pop     edi
	//                not     eax
	//                pop     esi
	//                pop     ebp
	//                retn
	//

	for (size_t i = 0; i < count; i++)
	{
		unsigned char tmp;
		unsigned int b = (int)& buffer[i];
		DetourRecord* detour = g_detours;
		while (detour)
		{
			if (detour->count && (b >= detour->addr) && (b < detour->addr + detour->count))
			{
				tmp = detour->array[b - detour->addr];
				break;
			}

			detour = detour->pNext;
		}
		if (!detour)
			tmp = buffer[i];
		ebx = ((int)tmp ^ eax) & 0xff;
		eax = ((int)eax >> 8) & 0xffffff;
		eax ^= extern_array1[ebx];
	}
	ebx = ~eax;
	return ebx;
}

int memcheck2(unsigned char* buffer, size_t count, mckey key)
{
	if (!extern_array2)
	{
		if (!EQADDR_ENCRYPTPAD2)
		{
			__debugbreak();
		}

		extern_array2 = (unsigned int*)EQADDR_ENCRYPTPAD2;
	}

	unsigned int ebx, edx, eax;

	//                push    ebp
	//                mov     ebp, esp
	//                push    ecx
	//                xor     eax, eax
	//                mov     al, [ebp+arg_8]
	//                xor     edx, edx
	//                mov     dl, [ebp+arg_9]
	edx = key.a[1];
	//                push    ebx
	//                push    esi
	//                mov     esi, 0FFh
	//                mov     ecx, 0FFFFFFh
	//                not     eax
	//                and     eax, esi
	eax = ~key.a[0] & 0xff;
	//                mov     eax, encryptpad2[eax*4]
	eax = extern_array2[eax];
	//                xor     eax, ecx
	eax ^= 0xffffff;
	//                xor     edx, eax
	edx = (edx ^ eax) & 0xff;
	//                sar     eax, 8
	//                and     edx, esi
	//                and     eax, ecx
	eax = ((int)eax >> 8) & 0xffffff;
	//                xor     eax, encryptpad2[edx*4]
	eax ^= extern_array2[edx];
	//                xor     edx, edx
	//                mov     dl, [ebp+arg_A]
	edx = key.a[2];
	//                push    edi
	//                xor     edx, eax
	edx = (edx ^ eax) & 0xff;
	//                sar     eax, 8
	//                and     edx, esi
	//                and     eax, ecx
	eax = ((int)eax >> 8) & 0xffffff;
	//                xor     eax, encryptpad2[edx*4]
	//                mov     edx, eax
	edx = eax ^ extern_array2[edx];
	//                call    null_sub_ret_0
	eax = 0;
	//                mov     edi, [ebp+arg_0]
	//                xor     ebx, ebx
	//                mov     bl, [ebp+arg_B]
	ebx = key.a[3];
	//                mov     [ebp+var_4], eax
	//                xor     ebx, edx
	ebx = (edx ^ ebx) & 0xff;
	//                sar     edx, 8
	//                and     edx, ecx
	//                and     ebx, esi
	edx = ((int)edx >> 8) & 0xffffff;
	//                xor     edx, encryptpad2[ebx*4]
	edx ^= extern_array2[ebx];
	//                xor     edx, eax
	edx ^= eax;
	//                mov     eax, [ebp+arg_4]
	//                add     eax, edi
	//                jmp     short loc_4C5776
	//; ---------------------------------------------------------------------------
	//
	//loc_4C5761:                             ; CODE XREF: new_memcheck2+8Fj
	//                xor     ebx, ebx
	//                mov     bl, [edi]
	//                xor     ebx, edx
	//                sar     edx, 8
	//                and     ebx, esi
	//                and     edx, ecx
	//                xor     edx, encryptpad2[ebx*4]
	//                inc     edi
	//
	//loc_4C5776:                             ; CODE XREF: new_memcheck2+76j
	//                cmp     edi, eax
	//                jb      short loc_4C5761
	//                pop     edi
	//                mov     eax, edx
	//                not     eax
	//                xor     eax, [ebp+var_4]
	//                pop     esi
	//                pop     ebx
	//                leave
	//                retn

	for (size_t i = 0; i < count; i++)
	{
		unsigned char tmp;
		unsigned int b = (int)&buffer[i];
		DetourRecord* detour = g_detours;

		while (detour)
		{
			if (detour->count && (b >= detour->addr) && (b < detour->addr + detour->count))
			{
				tmp = detour->array[b - detour->addr];
				break;
			}

			detour = detour->pNext;
		}
		if (!detour)
			tmp = buffer[i];

		ebx = ((int)tmp ^ edx) & 0xff;
		edx = ((int)edx >> 8) & 0xffffff;
		edx ^= extern_array2[ebx];
	}
	eax = ~edx ^ 0;

	return eax;
}

//extern int extern_arrray[];
//unsigned int *extern_array3 = (unsigned int *)0x5C0E98;

//  004F4AB9: 55                 push        ebp
//  004F4ABA: 8B EC              mov         ebp,esp
//  004F4ABC: 56                 push        esi

//  bah - 83 /1 ib OR r/m16,imm8 r/m16 OR imm8 (sign-extended)
//  sign extended!!!!!!!!!!!!

//  004F4ABD: 83 C8 FF           or          eax,0FFh

int memcheck3(unsigned char* buffer, size_t count, mckey key)
{
	unsigned int eax, ebx, edx;

	if (!extern_array3)
	{
		if (!EQADDR_ENCRYPTPAD3)
		{
			__debugbreak();
		}

		extern_array3 = (unsigned int*)EQADDR_ENCRYPTPAD3;
	}

	//                push    ebp
	//                mov     ebp, esp
	//                push    ecx
	//                xor     eax, eax
	//                mov     al, [ebp+arg_8]
	//                xor     edx, edx
	//                mov     dl, [ebp+arg_9]
	edx = key.a[1];
	//                push    ebx
	//                push    esi
	//                mov     esi, 0FFh
	//                mov     ecx, 0FFFFFFh
	//                not     eax
	//                and     eax, esi
	eax = ~key.a[0] & 0xff;
	//                mov     eax, encryptpad3[eax*4]
	eax = extern_array3[eax];
	//                xor     eax, ecx
	eax ^= 0xffffff;
	//                xor     edx, eax
	//                sar     eax, 8
	//                and     edx, esi
	edx = (edx ^ eax) & 0xff;
	//                and     eax, ecx
	eax = ((int)eax >> 8) & 0xffffff;
	//                xor     eax, encryptpad3[edx*4]
	eax ^= extern_array3[edx];
	//                xor     edx, edx
	//                mov     dl, [ebp+arg_A]
	edx = key.a[2];
	//                push    edi
	//                xor     edx, eax
	edx = (edx ^ eax) & 0xff;
	//                sar     eax, 8
	//                and     edx, esi
	//                and     eax, ecx
	eax = ((int)eax >> 8) & 0xffffff;
	//                xor     eax, encryptpad3[edx*4]
	//                mov     edx, eax
	edx = eax ^ extern_array3[edx];

	//                call    null_sub_ret_0
	eax = 0;
	//                mov     edi, [ebp+arg_0]
	//                xor     ebx, ebx
	//                mov     bl, [ebp+arg_B]
	ebx = key.a[3];
	//                mov     [ebp+var_4], eax
	//                xor     ebx, edx
	//                sar     edx, 8
	//                and     edx, ecx
	//                and     ebx, esi
	ebx = (ebx ^ edx) & 0xff;
	edx = ((int)edx >> 8) & 0xffffff;
	//                xor     edx, encryptpad3[ebx*4]
	edx ^= extern_array3[ebx];
	//                xor     edx, eax
	edx ^= eax;
	//                mov     eax, [ebp+arg_4]
	//                add     eax, edi
	//                jmp     short loc_4C5813
	//; ---------------------------------------------------------------------------
	//
	//loc_4C57FE:                             ; CODE XREF: new_memcheck3+8Fj
	//                xor     ebx, ebx
	//                mov     bl, [edi]
	//                xor     ebx, edx
	//                sar     edx, 8
	//                and     ebx, esi
	//                and     edx, ecx
	//                xor     edx, encryptpad3[ebx*4]
	//                inc     edi
	//

	for (size_t i = 0; i < count; i++)
	{
		unsigned char tmp;
		unsigned int b = (int)& buffer[i];
		DetourRecord* detour = g_detours;
		while (detour)
		{
			if (detour->count && (b >= detour->addr) && (b < detour->addr + detour->count))
			{
				tmp = detour->array[b - detour->addr];
				break;
			}
			detour = detour->pNext;
		}
		if (!detour)
			tmp = buffer[i];

		ebx = (tmp ^ edx) & 0xff;
		edx = ((int)edx >> 8) & 0xffffff;
		edx ^= extern_array3[ebx];
	}

	//loc_4C5813:                             ; CODE XREF: new_memcheck3+76j
	//                cmp     edi, eax
	//                jb      short loc_4C57FE
	//                pop     edi
	//                mov     eax, edx
	//                not     eax
	//                xor     eax, [ebp+var_4]
	eax = ~edx ^ 0;

	return eax;
	//                pop     esi
	//                pop     ebx
	//                leave
	//                retn
}

//?Crc32@UdpMisc@UdpLibrary@@SAHPBXHH@Z
int memcheck4(unsigned char* buffer, size_t count, mckey key)
{
	int origCrc = memcheck4_tramp(buffer, count, key);
	unsigned int addr = (int)&buffer[0];
	DWORD dwGetOrg = IsAddressDetoured(addr, count);

	if (dwGetOrg == 0)
		return origCrc;

	if (!extern_array4)
	{
		if (!EQADDR_ENCRYPTPAD4)
		{
			__debugbreak();
		}

		extern_array4 = (unsigned int*)EQADDR_ENCRYPTPAD4;
	}

	unsigned int eax, ebx, edx;

	edx = key.a[1];
	eax = ~key.a[0] & 0xff;
	eax = extern_array4[eax];
	eax ^= 0xffffff;
	edx = (edx ^ eax) & 0xff;
	eax = ((int)eax >> 8) & 0xffffff;
	eax ^= extern_array4[edx];
	edx = key.a[2];
	edx = (edx ^ eax) & 0xff;
	eax = ((int)eax >> 8) & 0xffffff;
	edx = eax ^ extern_array4[edx];
	eax = 0;
	ebx = key.a[3];
	ebx = (ebx ^ edx) & 0xff;
	edx = ((int)edx >> 8) & 0xffffff;
	edx ^= extern_array4[ebx];
	edx ^= eax;

	for (size_t i = 0; i < count; i++)
	{
		unsigned char tmp;
		if (dwGetOrg == 1)
		{
			unsigned int b = (int)& buffer[i];
			DetourRecord* detour = g_detours;
			while (detour)
			{
				if (detour->count && (b >= detour->addr) &&
					(b < detour->addr + detour->count)) {
					tmp = detour->array[b - detour->addr];
					break;
				}
				detour = detour->pNext;
			}
			if (!detour)
				tmp = buffer[i];
		}
		else
		{
			tmp = buffer[i];
		}

		ebx = (tmp ^ edx) & 0xff;
		edx = ((int)edx >> 8) & 0xffffff;
		edx ^= extern_array4[ebx];
	}
	eax = ~edx ^ 0;

	if (origCrc != eax)
	{
		__debugbreak();
		return origCrc;
	}
	return eax;
}

// MQ2Ic loads things from MQ2Main, but they've been moved to eqlib. So we forward them.
DETOUR_TRAMPOLINE_EMPTY(void* WINAPI GetProcAddress_Trampoline(HMODULE, LPCSTR));
void* WINAPI GetProcAddress_Detour(HMODULE hModule, LPCSTR lpProcName)
{
	if (void* result = GetProcAddress_Trampoline(hModule, lpProcName))
	{
		return result;
	}

	static HMODULE eqlibModule = GetModuleHandle("eqlib.dll");

	// If this is our module...
	if (hModule == ghModule)
	{
		void* pRet = GetProcAddress_Trampoline(eqlibModule, lpProcName);

		if (!pRet)
		{
			if (ci_equals("ppLocalPlayer", lpProcName))
			{
				pRet = &pLocalPlayer;
			}
			else if (ci_equals("ppCharData", lpProcName))
			{
				pRet = &pCharData;
			}
			else if (ci_equals("ppEverQuest", lpProcName))
			{
				pRet = &pEverQuest;
			}
			else if (ci_equals("ppEverQuestInfo", lpProcName))
			{
				pRet = &pEverQuestInfo;
			}
		}

#if DEBUG_GETPROCADDRESS
		char szModuleName[MAX_PATH] = { 0 };
		char* pModuleName = szModuleName;

		HMODULE hModuleCaller = nullptr;
		if (::GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
			(LPCSTR)_ReturnAddress(), &hModuleCaller))
		{
			::GetModuleFileNameA(hModuleCaller, szModuleName, MAX_PATH);

			if (char* value = strrchr(pModuleName, '\\'))
			{
				pModuleName = value + 1;
			}
		}

		DebugSpewAlways("GetProcAddressHook: %s -> %p (from %s)", lpProcName, pRet, pModuleName);
#endif

		return pRet;
	}

	return nullptr;
}

void InitializeMQ2Detours()
{
	HookMemChecker(true);

	DWORD GetProcAddress_Addr = (DWORD)&::GetProcAddress;
	EzDetour(GetProcAddress_Addr, &GetProcAddress_Detour, &GetProcAddress_Trampoline);
}

void ShutdownMQ2Detours()
{
	DWORD GetProcAddress_Addr = (DWORD)&::GetProcAddress;
	RemoveDetour(GetProcAddress_Addr);

	HookMemChecker(false);
	RemoveDetours();
}

//============================================================================
// Workaround for /emote message sending uninitialized memory

#pragma optimize("", off)
// used to fill the buffer with random data
void emotify2(char* A, int size)
{
	for (int i = 0; i < size; i += 1024)
		memcpy(A + i, EQADDR_ENCRYPTPAD0, 1024);
}

void emotify()
{
	char buffer[1024 * 4];
	emotify2(buffer, lengthof(buffer));
}
#pragma optimize( "", on )

} // namespace mq

//============================================================================
// this shit is here to satisfy mq2ic. Just because its here doesn't mean you should ever use it
class CCXStr
{
public:
	MQLIB_OBJECT CCXStr& operator= (char const* str);
	void* Ptr [[deprecated]] ;
};
FUNCTION_AT_ADDRESS(CCXStr& CCXStr::operator=(char const*), CXStr__operator_equal1);
