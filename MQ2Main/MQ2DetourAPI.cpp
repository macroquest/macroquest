/*****************************************************************************
MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License, version 2, as published by
the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
******************************************************************************/

// Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x510
#define DIRECTINPUT_VERSION 0x800

#if !defined(CINTERFACE)
#error /DCINTERFACE
#endif

#define DBG_SPEW

#include "MQ2Main.h"
#ifndef ISXEQ

typedef struct _OurDetours {
/* 0x00 */    unsigned int addr;
/* 0x04 */    unsigned int count;
/* 0x08 */    CHAR Name[0x64];
/* 0x6c */    unsigned char array[0x40];
/* 0xac */    PBYTE pfDetour;
/* 0xb0 */    PBYTE pfTrampoline;
/* 0xb4 */    struct _OurDetours *pNext;
/* 0xb8 */    struct _OurDetours *pLast;
/* 0xbc */
} OurDetours;

EQLIB_VAR OurDetours *ourdetours = 0;
CRITICAL_SECTION gDetourCS;


OurDetours *FindDetour(DWORD address)
{
	OurDetours *pDetour = ourdetours;
	while (pDetour)
	{
		if (pDetour->addr == address)
			return pDetour;
		pDetour = pDetour->pNext;
	}
	return 0;
}

BOOL AddDetour(DWORD address, PBYTE pfDetour, PBYTE pfTrampoline, DWORD Count, PCHAR Name)
{
	if (address == 0)
	{
		MessageBox(NULL, "You are trying to detour a NULL address, please chack your code.", Name, MB_SYSTEMMODAL | MB_OK);
		return false;
	}
	CAutoLock Lock(&gDetourCS);
	CHAR szName[MAX_STRING] = { 0 };
	if (Name && Name[0] != '\0') {
		strcpy_s(szName, Name);
	} else {
		strcpy_s(szName, "Unknown");
	}
	BOOL Ret = TRUE;
	DebugSpew("AddDetour(%s, 0x%X,0x%X,0x%X,0x%X)", szName, address, pfDetour, pfTrampoline, Count);
	if (FindDetour(address))
	{
		DebugSpew("Address for %s (0x%x) already detoured.", szName, address);
		return FALSE;
	}
	OurDetours *detour = new OurDetours;
	strcpy_s(detour->Name, szName);
	detour->addr = address;
	detour->count = Count;
	memcpy(detour->array, (char *)address, Count);
	detour->pNext = ourdetours;
	if (ourdetours)
		ourdetours->pLast = detour;
	detour->pLast = 0;

	if (pfTrampoline) {
		// its an indirect jump, likely due to incremental linking. The actual
		// function body is at the other end of the jump. We need to follow it.
		if (pfTrampoline[0] == 0xe9) {
			pfTrampoline = pfTrampoline + *(DWORD*)&pfTrampoline[1] + 5;	
		}
		if (pfTrampoline[0] && pfTrampoline[1]) {
			DWORD oldperm = 0, tmp;
			VirtualProtectEx(GetCurrentProcess(), (LPVOID)pfTrampoline, 2, PAGE_EXECUTE_READWRITE, &oldperm);
			pfTrampoline[0] = 0x90;
			pfTrampoline[1] = 0x90;
			VirtualProtectEx(GetCurrentProcess(), (LPVOID)pfTrampoline, 2, oldperm, &tmp);
		}
	}
	if (pfDetour && !DetourFunctionWithEmptyTrampoline(pfTrampoline, (PBYTE)address, pfDetour))
	{
		detour->pfDetour = 0;
		detour->pfTrampoline = 0;
		Ret = FALSE;
		DebugSpew("Detour of %s failed.", szName);
	}
	else
	{
		detour->pfDetour = pfDetour;
		detour->pfTrampoline = pfTrampoline;
		DebugSpew("Detour of %s was successful.", szName);
	}
	ourdetours = detour;
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
		if (nParameters<4)
		{
			Parameters[nParameters] = i;
			nParameters++;
		} else {
			//we can break out now...
			break;
		}
		i = va_arg(marker, int);
	}
	va_end(marker);
	if (nParameters == 4)
	{
		AddDetour(address, (PBYTE)Parameters[1], (PBYTE)Parameters[2], 20,(PCHAR)Parameters[3]);
	}
	else
	{
		DebugSpew("Illegal AddDetourf call");
	}
}

void RemoveDetour(DWORD address)
{
	CAutoLock Lock(&gDetourCS);
	OurDetours *detour = ourdetours;
	HMODULE hModule = 0;
	CHAR szFilename[MAX_STRING] = { 0 };
	GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)address, &hModule);
	DWORD myaddress = (DWORD)hModule;
	GetModuleFileName(hModule, szFilename, MAX_STRING);
	if (char*pDest = strrchr(szFilename, '\\'))
	{
		pDest[0] = '\0';
		strcpy_s(szFilename, &pDest[1]);
	}
	_strlwr_s(szFilename);
	while (detour)
	{
		if (detour->addr == address)
		{
			
			
			if (detour->pfDetour)
			{
				if(strstr(szFilename,"eqgame"))
					DebugSpewAlways("DetourRemove %s (%s [0x%08X])", detour->Name, szFilename, address - myaddress + 0x400000);
				else
					DebugSpewAlways("DetourRemove %s (%s [0x%08X])", detour->Name, szFilename,address - myaddress + 0x10000000);
				DetourRemove(detour->pfTrampoline, detour->pfDetour);
				//sometimes its useful to add and then remove a detour and then add it again... and so on...
				//the following 2 lines fixes a detours "bug"
				//I don't know if this was MS intention
				//but if we don't set these to nop
				//we cant detour the same function more than once. -eqmule
				//so dont remove these.
				DWORD oldperm = 0,tmp;
				VirtualProtectEx(GetCurrentProcess(), (LPVOID)detour->pfTrampoline, 2, PAGE_EXECUTE_READWRITE, &oldperm);
				detour->pfTrampoline[0] = 0x90;
				detour->pfTrampoline[1] = 0x90;
				VirtualProtectEx(GetCurrentProcess(), (LPVOID)detour->pfTrampoline, 2, oldperm, &tmp);
			}
			if (detour->pLast)
				detour->pLast->pNext = detour->pNext;
			else
				ourdetours = detour->pNext;

			if (detour->pNext)
				detour->pNext->pLast = detour->pLast;
			delete detour;
			return;
		}
		detour = detour->pNext;
	}
	if(strstr(szFilename,"eqgame"))
		DebugSpewAlways("Detour for (%s [0x%08X]) not found in RemoveDetour()", szFilename, address - myaddress + 0x400000);
	else
		DebugSpewAlways("Detour for (%s [0x%08X]) not found in RemoveDetour()", szFilename, address - myaddress + 0x10000000);
}

void DeleteDetour(DWORD address)
{
	CAutoLock Lock(&gDetourCS);
	OurDetours *detour = ourdetours;
	while (detour)
	{
		if (detour->addr == address)
		{
			DebugSpew("Deleted %s (%X)", detour->Name, ((DWORD)GetModuleHandle(NULL) - address + 0x400000));
			if (detour->pLast)
				detour->pLast->pNext = detour->pNext;
			else
				ourdetours = detour->pNext;

			if (detour->pNext)
				detour->pNext->pLast = detour->pLast;
			delete detour;
			return;
		}
		detour = detour->pNext;
	}
	DebugSpew("Failed Deleting (%X)", ((DWORD)GetModuleHandle(NULL) - address + 0x400000));
}

void RemoveOurDetours()
{
	CAutoLock Lock(&gDetourCS);
	DebugSpew("RemoveOurDetours()");
	if (!ourdetours)
		return;
	while (ourdetours)
	{
		if (ourdetours->pfDetour)
		{
			DebugSpew("RemoveOurDetours() -- Removing %s (%X)", ourdetours->Name, ourdetours->addr);
			RemoveDetour(ourdetours->addr);
		}
		if (ourdetours)
		{
			OurDetours *pNext = ourdetours->pNext;
			delete ourdetours;
			ourdetours = pNext;
		}
	}
	ourdetours = 0;
}
#endif

void SetAssist(PBYTE address)
{
	if ((DWORD)address == -1)
		return;
	bool bexpectTarget = false;
	if (address) {
		if (DWORD Assistee = *(DWORD*)address) {
			if (PSPAWNINFO pSpawn = (PSPAWNINFO)GetSpawnByID(Assistee)) {
				bexpectTarget = true;
				gbAssistComplete = 1;
				//WriteChatf("We can expect a target packet because assist retuned %s",pSpawn->Name);
			}
		}
	}
	else {
		InterlockedIncrement((volatile unsigned long *)gbAssistComplete);
	}
	if (!bexpectTarget) {
		//WriteChatColor("We can NOT expect a target packet because assist was 0");
		gbAssistComplete = 2;
	}
}
//whatever the frak you do, do not remove this #pragma
//I spent a lot of time figuring out how to get the assist code to work
//on all compilers/settings etc.
//this pragma basically forces it to build the same on all machines
//no matter what kind of optimization you have turned on in settings...
//so just leave it alone. -eqmule
#pragma optimize( "", off )
class CPacketScrambler
{
public:
	int CPacketScrambler::ntoh_tramp(int);
	int CPacketScrambler::ntoh_detour(int nopcode);
	void CDisplay__ZoneMainUI_Tramp();
	void CDisplay__ZoneMainUI_Detour()
	{
		PluginsEndZone();
		CDisplay__ZoneMainUI_Tramp();
	};
	void CDisplay__PreZoneMainUI_Tramp();
	void CDisplay__PreZoneMainUI_Detour()
	{
		PluginsBeginZone();
		CDisplay__PreZoneMainUI_Tramp();
	}
};
typedef DWORD(__cdecl *fGetAssistCalc)(DWORD);
static fGetAssistCalc GetAssistCalc = 0;
typedef DWORD(__cdecl *fGetHashSum)(DWORD,DWORD);
static fGetHashSum GetHashSum = 0;
int CPacketScrambler::ntoh_detour(int nopcode)
{
	int hopcode = ntoh_tramp(nopcode);
	if (hopcode == EQ_ASSIST_COMPLETE) {
		DWORD calc = 0;
#if defined(TEST)
		__asm {
			push eax;
			push ecx;
			mov eax, dword ptr[ebx + 0x1b];
			mov ecx, dword ptr[ebx + 0x17];
			xor eax, ecx;
			mov calc, eax;
			pop ecx;
			pop eax;
		};
#else
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
#endif
		DWORD assistflag = 0;
		if (GetAssistCalc = (fGetAssistCalc)GetProcAddress(ghmq2ic, "GetAssistCalc")) {
			assistflag = GetAssistCalc(calc);
		}
		SetAssist((PBYTE)assistflag);
	}
	if (hopcode == EQ_ASSIST) {
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

DETOUR_TRAMPOLINE_EMPTY(int CPacketScrambler::ntoh_tramp(int));
DETOUR_TRAMPOLINE_EMPTY(void CPacketScrambler::CDisplay__PreZoneMainUI_Tramp());
DETOUR_TRAMPOLINE_EMPTY(void CPacketScrambler::CDisplay__ZoneMainUI_Tramp());

#pragma optimize( "", on )

#define EB_SIZE (1024*4)
void emotify(void);
void emotify2(char *buffer);
bool gbDoingSpellChecks = false;

class Spellmanager
{
public:
#if !defined(ROF2EMU) && !defined(UFEMU)
	bool LoadTextSpells_Tramp(char*, char*, EQ_Spell*, PSPELLCALCINFO);
	bool LoadTextSpells_Detour(char*FileName, char*AssocFileName, EQ_Spell* SpellArray, PSPELLCALCINFO EffectArray)//SpellAffectData*
#else
	bool LoadTextSpells_Tramp(char*, char*, EQ_Spell*);
	bool LoadTextSpells_Detour(char*FileName, char*AssocFileName, EQ_Spell* SpellArray)
#endif
	{
		gbDoingSpellChecks = true;
		#if !defined(ROF2EMU) && !defined(UFEMU)
		bool ret = LoadTextSpells_Tramp(FileName, AssocFileName, SpellArray, EffectArray);
		#else
		bool ret = LoadTextSpells_Tramp(FileName, AssocFileName, SpellArray);
		#endif
		gbDoingSpellChecks = false;
		return ret;
	}
};
#if !defined(ROF2EMU) && !defined(UFEMU)
DETOUR_TRAMPOLINE_EMPTY(bool Spellmanager::LoadTextSpells_Tramp(char*, char*, EQ_Spell*, PSPELLCALCINFO));
#else
DETOUR_TRAMPOLINE_EMPTY(bool Spellmanager::LoadTextSpells_Tramp(char*, char*, EQ_Spell*));
#endif
// we need this detour to clean up the stack because
// emote sends 1024 bytes no matter how many bytes in the string
// MQ2 variables get left on the stack....
class CEmoteHook
{
public:
	VOID CEmoteHook::Trampoline(void);
	VOID CEmoteHook::Detour(void);
};
VOID CEmoteHook::Detour(void)
{
	emotify();
	Trampoline();
}
DETOUR_TRAMPOLINE_EMPTY(VOID CEmoteHook::Trampoline(void));


// this is the memory checker key struct
struct mckey {
	union {
		int x;
		unsigned char a[4];
		char sa[4];
	};
};

// pointer to encryption pad for memory checker
unsigned int *extern_array0 = NULL;
unsigned int *extern_array1 = NULL;
unsigned int *extern_array2 = NULL;
unsigned int *extern_array3 = NULL;
unsigned int *extern_array4 = NULL;
#ifndef ISXEQ
int __cdecl memcheck0(unsigned char *buffer, int count);
int __cdecl memcheck1(unsigned char *buffer, int count, struct mckey key);
int __cdecl memcheck2(unsigned char *buffer, int count, struct mckey key);
int __cdecl memcheck3(unsigned char *buffer, int count, struct mckey key);
int __cdecl memcheck4(unsigned char *buffer, int count, struct mckey key);
#endif

// ***************************************************************************
// Function:    HookMemChecker
// Description: Hook MemChecker
// ***************************************************************************
//int(__cdecl *memcheck0_tramp)(unsigned char *buffer, int count);
//int(__cdecl *memcheck1_tramp)(unsigned char *buffer, int count, struct mckey key);
//int(__cdecl *memcheck2_tramp)(unsigned char *buffer, int count, struct mckey key);
//int(__cdecl *memcheck3_tramp)(unsigned char *buffer, int count, struct mckey key);
//int(__cdecl *memcheck4_tramp)(unsigned char *buffer, int count, struct mckey key);
DETOUR_TRAMPOLINE_EMPTY(int memcheck0_tramp(unsigned char *buffer, int count));
DETOUR_TRAMPOLINE_EMPTY(int memcheck1_tramp(unsigned char *buffer, int count, struct mckey key));
DETOUR_TRAMPOLINE_EMPTY(int memcheck2_tramp(unsigned char *buffer, int count, struct mckey key));
DETOUR_TRAMPOLINE_EMPTY(int memcheck3_tramp(unsigned char *buffer, int count, struct mckey key));
DETOUR_TRAMPOLINE_EMPTY(int memcheck4_tramp(unsigned char *buffer, int count, struct mckey key));

VOID HookInlineChecks(BOOL Patch)
{
	int i;
#ifndef ISXEQ
	DWORD oldperm, tmp;
#endif
	DWORD NewData;

	DWORD cmps[] = { __AC1 + 6 };

	DWORD cmps2[] = { __AC2,
		__AC3,
		__AC4,
		__AC5,
		__AC6,
		__AC7 };

	int len2[] = { 6, 6, 6, 6, 6, 6 };

	char NewData2[20];

	static char OldData2[sizeof(cmps2) / sizeof(cmps2[0])][20];

	if (Patch)
	{
		NewData = 0x7fffffff;

		for (i = 0; i<sizeof(cmps) / sizeof(cmps[0]); i++) {
#ifdef ISXEQ
			EzModify(cmps[i], &NewData, 4);
#else
			AddDetour(cmps[i], NULL, NULL, 4,"cmps");
			VirtualProtectEx(GetCurrentProcess(), (LPVOID)cmps[i], 4, PAGE_EXECUTE_READWRITE, &oldperm);
			WriteProcessMemory(GetCurrentProcess(), (LPVOID)cmps[i], (LPVOID)&NewData, 4, NULL);
			VirtualProtectEx(GetCurrentProcess(), (LPVOID)cmps[i], 4, oldperm, &tmp);
#endif
		}

		memset(NewData2, 0x90, 20);

		for (i = 0; i<sizeof(cmps2) / sizeof(cmps2[0]); i++) {
#ifdef ISXEQ
			EzModify(cmps2[i], NewData2, len2[i]);
#else
			AddDetour(cmps2[i], NULL, NULL, len2[i],"cmps2");
			VirtualProtectEx(GetCurrentProcess(), (LPVOID)cmps2[i], len2[i], PAGE_EXECUTE_READWRITE, &oldperm);
			memcpy((void *)OldData2[i], (void *)cmps2[i], len2[i]);
			WriteProcessMemory(GetCurrentProcess(), (LPVOID)cmps2[i], (LPVOID)NewData2, len2[i], NULL);
			VirtualProtectEx(GetCurrentProcess(), (LPVOID)cmps2[i], len2[i], oldperm, &tmp);
#endif
		}
	}
	else
	{
		NewData = __AC1_Data;

		for (i = 0; i<sizeof(cmps) / sizeof(cmps[0]); i++) {
#ifdef ISXEQ
			EzUnModify(cmps[i]);
#else
			VirtualProtectEx(GetCurrentProcess(), (LPVOID)cmps[i], 4, PAGE_EXECUTE_READWRITE, &oldperm);
			WriteProcessMemory(GetCurrentProcess(), (LPVOID)cmps[i], (LPVOID)&NewData, 4, NULL);
			VirtualProtectEx(GetCurrentProcess(), (LPVOID)cmps[i], 4, oldperm, &tmp);
			RemoveDetour(cmps[i]);
#endif
		}

		for (i = 0; i<sizeof(cmps2) / sizeof(cmps2[0]); i++) {
#ifdef ISXEQ
			EzUnModify(cmps2[i]);
#else
			VirtualProtectEx(GetCurrentProcess(), (LPVOID)cmps2[i], len2[i], PAGE_EXECUTE_READWRITE, &oldperm);
			WriteProcessMemory(GetCurrentProcess(), (LPVOID)cmps2[i], (LPVOID)OldData2[i], len2[i], NULL);
			VirtualProtectEx(GetCurrentProcess(), (LPVOID)cmps2[i], len2[i], oldperm, &tmp);
			RemoveDetour(cmps2[i]);
#endif
		}
	}
}

#ifndef ISXEQ
VOID HookMemChecker(BOOL Patch)
{
	// hit the debugger if we don't hook this
	// take no chances
	if ((!EQADDR_MEMCHECK0) ||
		(!EQADDR_MEMCHECK1) ||
		(!EQADDR_MEMCHECK2) ||
		(!EQADDR_MEMCHECK3) ||
		(!EQADDR_MEMCHECK4)) {
		_asm int 3
	}

	DebugSpew("HookMemChecker - %satching", (Patch) ? "P" : "Unp");
	if (Patch) {

		EzDetourwName(EQADDR_MEMCHECK0, memcheck0, memcheck0_tramp, "EQADDR_MEMCHECK0");
		//AddDetour((DWORD)EQADDR_MEMCHECK0);

		//(*(PBYTE*)&memcheck0_tramp) = DetourFunction((PBYTE)EQADDR_MEMCHECK0,(PBYTE)memcheck0);
		EzDetourwName(EQADDR_MEMCHECK1, memcheck1, memcheck1_tramp, "EQADDR_MEMCHECK1");

		//AddDetour((DWORD)EQADDR_MEMCHECK1);
		//(*(PBYTE*)&memcheck1_tramp) = DetourFunction((PBYTE)EQADDR_MEMCHECK1,(PBYTE)memcheck1);

		EzDetourwName(EQADDR_MEMCHECK2, memcheck2, memcheck2_tramp, "EQADDR_MEMCHECK2");
		//AddDetour((DWORD)EQADDR_MEMCHECK2);
		//(*(PBYTE*)&memcheck2_tramp) = DetourFunction((PBYTE)EQADDR_MEMCHECK2,(PBYTE)memcheck2);

		EzDetourwName(EQADDR_MEMCHECK3, memcheck3, memcheck3_tramp, "EQADDR_MEMCHECK3");
		//AddDetour((DWORD)EQADDR_MEMCHECK3);
		//(*(PBYTE*)&memcheck3_tramp) = DetourFunction((PBYTE)EQADDR_MEMCHECK3,(PBYTE)memcheck3);

		EzDetourwName(EQADDR_MEMCHECK4, memcheck4, memcheck4_tramp, "EQADDR_MEMCHECK4");
		//AddDetour((DWORD)EQADDR_MEMCHECK4);
		//(*(PBYTE*)&memcheck4_tramp) = DetourFunction((PBYTE)EQADDR_MEMCHECK4,(PBYTE)memcheck4);

		EzDetourwName(CPacketScrambler__ntoh, &CPacketScrambler::ntoh_detour, &CPacketScrambler::ntoh_tramp,"CPacketScrambler__ntoh");
		EzDetourwName(CEverQuest__Emote, &CEmoteHook::Detour, &CEmoteHook::Trampoline,"CEverQuest__Emote");
		EzDetourwName(Spellmanager__LoadTextSpells, &Spellmanager::LoadTextSpells_Detour, &Spellmanager::LoadTextSpells_Tramp,"Spellmanager__LoadTextSpells");
		EzDetourwName(CDisplay__ZoneMainUI, &CPacketScrambler::CDisplay__ZoneMainUI_Detour, &CPacketScrambler::CDisplay__ZoneMainUI_Tramp,"CDisplay__ZoneMainUI");
		EzDetourwName(CDisplay__PreZoneMainUI, &CPacketScrambler::CDisplay__PreZoneMainUI_Detour, &CPacketScrambler::CDisplay__PreZoneMainUI_Tramp,"CDisplay__PreZoneMainUI");


		HookInlineChecks(Patch);
	}
	else {
		HookInlineChecks(Patch);

		//DetourRemove((PBYTE)memcheck0_tramp,(PBYTE)memcheck0);
		//memcheck0_tramp = NULL;
		RemoveDetour(EQADDR_MEMCHECK0);

		//DetourRemove((PBYTE)memcheck1_tramp,(PBYTE)memcheck1);
		//memcheck1_tramp = NULL;
		RemoveDetour(EQADDR_MEMCHECK1);

		//DetourRemove((PBYTE)memcheck2_tramp,(PBYTE)memcheck2);
		//memcheck2_tramp = NULL;
		RemoveDetour(EQADDR_MEMCHECK2);

		//DetourRemove((PBYTE)memcheck3_tramp,(PBYTE)memcheck3);
		//memcheck3_tramp = NULL;
		RemoveDetour(EQADDR_MEMCHECK3);

		//DetourRemove((PBYTE)memcheck4_tramp,(PBYTE)memcheck4);
		//memcheck4_tramp = NULL;
		RemoveDetour(EQADDR_MEMCHECK4);
		
		RemoveDetour(CDisplay__PreZoneMainUI);
		RemoveDetour(CDisplay__ZoneMainUI);
		RemoveDetour(CPacketScrambler__ntoh);

		RemoveDetour(CEverQuest__Emote);
		RemoveDetour(Spellmanager__LoadTextSpells);
	}
}

DWORD IsAddressDetoured(unsigned int address, int count)
{
	if (gbDoingModuleChecks)
		return 4;
	if (gbDoingSpellChecks)
		return 3;
	if (address && *(DWORD*)address == 0x00905a4d)
	{
		//its a executable being checked
		return 2;
	}

	
	OurDetours *detour = ourdetours;
	while (detour) {
		if (IsBadReadPtr(detour, 4))
			return 0;
		if(detour->count && address <= detour->addr && detour->addr <= (address + count)) {
			return 1;
		}
		detour = detour->pNext;
	}
	return 0;
}
#endif

int __cdecl memcheck0(unsigned char *buffer, int count)
{
	//MessageBox(NULL, "ddd", "ddd", MB_SYSTEMMODAL | MB_OK);
	//int realchecksum = checkmemcheck0((const char *)buffer, count);
#ifndef	ISXEQ
	int orgret = memcheck0_tramp(buffer, count);
	unsigned int addr = (int)&buffer[0];
 
	DWORD dwGetOrg = IsAddressDetoured(addr, count);
	if (dwGetOrg >= 2)//pointless to detour check this cause its just getting a hash for the spelldb or a executable we dont care about, and we dont mess with that.
		return orgret;
#endif
	unsigned int x, i;
	unsigned int eax = 0xffffffff;

	if (!extern_array0) {
		if (!EQADDR_ENCRYPTPAD0) {
			//_asm int 3
		}
		else {
			extern_array0 = (unsigned int *)EQADDR_ENCRYPTPAD0;
		}
	}

#ifdef ISXEQ
	unsigned char *realbuffer = (unsigned char *)malloc(count);
	pExtension->Memcpy_Clean((unsigned int)buffer, realbuffer, count);
#endif

	for (i = 0; i<(unsigned int)count; i++) {
		unsigned char tmp;
#ifdef ISXEQ
		tmp = realbuffer[i];
#else
		if (dwGetOrg==1) {
			DWORD eqgamebase = (DWORD)GetModuleHandle(NULL);
			unsigned int b = (int)&buffer[i];
			OurDetours *detour = ourdetours;
			while (detour)
			{
				if (detour->Name[0]!='\0' && !_stricmp(detour->Name, "LoginController__GiveTime")) {
					//its not a valid detour to check at this point
					detour = detour->pNext;
					continue;
				}
				DWORD newaddr = b + 0x400 + (detour->addr-eqgamebase-0x1000);
				if (newaddr && newaddr <= (addr+count) && *(BYTE*)newaddr==0xe9 && *(DWORD*)newaddr==*(DWORD*)detour->addr) {
					Sleep(0);
				}
				if (detour->count && (b >= detour->addr) &&	(b < detour->addr + detour->count)) {
					tmp = detour->array[b - detour->addr];
					break;
				}
				detour = detour->pNext;
			}
			if (!detour)
				tmp = buffer[i];
		}
		else {
			//if (!detour)
			tmp = buffer[i];
		}
#endif
		x = (int)tmp ^ (eax & 0xff);
		eax = ((int)eax >> 8) & 0xffffff;
		x = extern_array0[x];
		eax ^= x;
	}

#ifdef ISXEQ
	free(realbuffer);
#endif
#ifndef ISXEQ
	if (orgret != eax)
	{
		//wtf?
#ifdef _DEBUG
		MessageBox(NULL, "WARNING, this should not happen, contact eqmule", "memchecker0 mismatch", MB_OK | MB_SYSTEMMODAL);
		_asm int 3;
		return orgret;
#endif
	}
#endif
	return eax;
}

int __cdecl memcheck5(DWORD count)
{
	DWORD dwsum = 0;
	if (GetHashSum = (fGetHashSum)GetProcAddress(ghmq2ic, "GetHashSum")) {
		dwsum = GetHashSum(count,__EP1_Data_x);
	}
	return dwsum;
}

int __cdecl memcheck1(unsigned char *buffer, int count, struct mckey key)
{
	//leave this here i uncomment now and then to check the hash -eqmule
	//int realchecksum = memcheck1Tester(buffer, (UINT)count, (int)key.x);
	unsigned int i;
	unsigned int ebx, eax, edx;

	if (!extern_array1) {
		if (!EQADDR_ENCRYPTPAD1) {
			//_asm int 3
		}
		else {
			extern_array1 = (unsigned int *)EQADDR_ENCRYPTPAD1;
		}
	}
	//                push    ebp
	//                mov     ebp, esp
	//                push    esi
	//                push    edi
	//                or      edi, 0FFFFFFFFh
	//                cmp     [ebp+arg_8], 0
	int creset = memcheck5(count);
	if (key.x != 0 && creset==__EncryptPad5_x) {
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
	}
	else { // key.x != 0
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

#ifdef ISXEQ
	unsigned char *realbuffer = (unsigned char *)malloc(count);
	pExtension->Memcpy_Clean((unsigned int)buffer, realbuffer, count);
#endif

	for (i = 0; i<(unsigned int)count; i++) {
		unsigned char tmp;
#ifdef ISXEQ
		tmp = realbuffer[i];
#else
		unsigned int b = (int)&buffer[i];
		OurDetours *detour = ourdetours;
		while (detour) {
			if (detour->count && (b >= detour->addr) &&	(b < detour->addr + detour->count)) {
				//MessageBox(NULL, "realchecksum", "need to fix", MB_SYSTEMMODAL | MB_OK);
				tmp = detour->array[b - detour->addr];
				break;
			}
			detour = detour->pNext;
		}
		if (!detour)
			tmp = buffer[i];
#endif
		ebx = ((int)tmp ^ eax) & 0xff;
		eax = ((int)eax >> 8) & 0xffffff;
		eax ^= extern_array1[ebx];
	}
#ifdef ISXEQ
	free(realbuffer);
#endif
	ebx = ~eax;
	/*if (realchecksum != ebx)
	{
		MessageBox(NULL, "realchecksum", "fail", MB_SYSTEMMODAL | MB_OK);
	}*/
	return ebx;
}

int __cdecl memcheck2(unsigned char *buffer, int count, struct mckey key)
{
	unsigned int i;
	unsigned int ebx, edx, eax;
	//MessageBox(NULL, "ddddd", "ddddd", MB_SYSTEMMODAL | MB_OK);
	//int realchecksum = checkmemcheck2(buffer, count, key.x);
	//DebugSpewAlways("memcheck2: 0x%x", buffer);

	if (!extern_array2) {
		if (!EQADDR_ENCRYPTPAD2) {
			//_asm int 3
		}
		else {
			extern_array2 = (unsigned int *)EQADDR_ENCRYPTPAD2;
		}
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


#ifdef ISXEQ
	unsigned char *realbuffer = (unsigned char *)malloc(count);
	pExtension->Memcpy_Clean((unsigned int)buffer, realbuffer, count);
#endif

	for (i = 0; i<(unsigned int)count; i++) {
		unsigned char tmp;

#ifdef ISXEQ
		tmp = realbuffer[i];
#else
		unsigned int b = (int)&buffer[i];
		OurDetours *detour = ourdetours;
		while (detour) {
			if (detour->count && (b >= detour->addr) &&
				(b < detour->addr + detour->count)) {
				tmp = detour->array[b - detour->addr];
				break;
			}
			detour = detour->pNext;
		}
		if (!detour) tmp = buffer[i];
#endif

		ebx = ((int)tmp ^ edx) & 0xff;
		edx = ((int)edx >> 8) & 0xffffff;
		edx ^= extern_array2[ebx];
	}
	eax = ~edx ^ 0;
#ifdef ISXEQ
	free(realbuffer);
#endif
	/*if (realchecksum != eax)
	{
		//crap...
		MessageBox(NULL, "crap", "memcheck2 hash did not match tell eqmule", MB_SYSTEMMODAL | MB_OK);
		DebugBreak();
		return realchecksum;
	}*/
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

int __cdecl memcheck3(unsigned char *buffer, int count, struct mckey key)
{
	unsigned int eax, ebx, edx, i;

	if (!extern_array3) {
		if (!EQADDR_ENCRYPTPAD3) {
			//_asm int 3
		}
		else {
			extern_array3 = (unsigned int *)EQADDR_ENCRYPTPAD3;
		}
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

#ifdef ISXEQ
	unsigned char *realbuffer = (unsigned char *)malloc(count);
	pExtension->Memcpy_Clean((unsigned int)buffer, realbuffer, count);
#endif

	for (i = 0; i<(unsigned int)count; i++) {
		unsigned char tmp;
#ifdef ISXEQ
		tmp = realbuffer[i];
#else
		unsigned int b = (int)&buffer[i];
		OurDetours *detour = ourdetours;
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
#endif

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

#ifdef ISXEQ
	free(realbuffer);
#endif
	return eax;
	//                pop     esi
	//                pop     ebx
	//                leave
	//                retn
}
//?Crc32@UdpMisc@UdpLibrary@@SAHPBXHH@Z
int __cdecl memcheck4(unsigned char *buffer, int count, struct mckey key)
{
	#ifndef ISXEQ
	int orgret = memcheck4_tramp(buffer, count, key);
	unsigned int addr = (int)&buffer[0];
	DWORD dwGetOrg = IsAddressDetoured(addr, count);
	if (dwGetOrg == 0)
		return orgret;
	#endif
	unsigned int eax, ebx, edx, i;

	if (!extern_array4) {
		if (!EQADDR_ENCRYPTPAD4) {
			//_asm int 3
		}
		else {
			extern_array4 = (unsigned int *)EQADDR_ENCRYPTPAD4;
		}
	}
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

#ifdef ISXEQ
	unsigned char *realbuffer = (unsigned char *)malloc(count);
	pExtension->Memcpy_Clean((unsigned int)buffer, realbuffer, count);
#endif

	for (i = 0; i<(unsigned int)count; i++) {
		unsigned char tmp;
#ifdef ISXEQ
		tmp = realbuffer[i];
#else
		if (dwGetOrg == 1) {
			unsigned int b = (int)&buffer[i];
			OurDetours *detour = ourdetours;
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
		else {
			tmp = buffer[i];
		}
#endif

		ebx = (tmp ^ edx) & 0xff;
		edx = ((int)edx >> 8) & 0xffffff;
		edx ^= extern_array4[ebx];
	}
	eax = ~edx ^ 0;

#ifdef ISXEQ
	free(realbuffer);
#else
	if (orgret != eax)
	{
	#ifdef _DEBUG
		MessageBox(NULL, "WARNING, this should not hapen, contact eqmule", "memchecker4 mismatch", MB_OK | MB_SYSTEMMODAL);
		_asm int 3;
		return orgret;
	#endif
	}
#endif
	return eax;
}
#if defined(ROF2EMU) || defined(UFEMU)
PCHAR __cdecl CrashDetected_Trampoline();
PCHAR __cdecl CrashDetected_Detour()
{
	//this function returns a pointer to whatever it writes to the log.
	//yeah uhm we don't need to show this dialog or we could show our own to have crashdumps sent to us
	//but for now im just gonna put a pin in that idea. -eqmule
	MessageBox(0, "Uhm hi... yes you crashed, nothing u can do.", "EverQuest Crash Report Sending Detected", MB_YESNO);
	//DebugBreak();
	return 0;
}
DETOUR_TRAMPOLINE_EMPTY(PCHAR CrashDetected_Trampoline());
#else
typedef struct _Launchinfo
{
	/*0x000*/	PCHAR eqgamepath;
	/*0x004*/	PCHAR CmdLine;
} Launchinfo, *PLaunchinfo;
class SessionFolderDescription {
public:
	UINT TimeStamp;
	UINT RootFolderId;
};

class SessionFolderLock {
    public:
        HANDLE hLockFile;
};

typedef struct _EQCrash
{
/*0x000*/	PVOID		CrashCallback;
/*0x004*/	char **		argv;
/*0x008*/	int			argc;
/*0x00C*/	PCHAR		pAppName;//EverQuest 1 Client ( Live )
/*0x010*/	PVOID		ReservedMemory;
/*0x014*/	UINT		ReservedMeminMB;
/*0x018*/	PCHAR		SomeName;
/*0x01c*/	UINT		MinidumpFlags;
/*0x020*/	HANDLE		MinidumpThread;
/*0x024*/	HANDLE		MinidumpThreadEvent;
/*0x028*/	HANDLE		MinidumpAPCComplete;
/*0x02c*/	HANDLE		MinidumpMutex;
/*0x030*/	UINT		CrashedThreadId;
/*0x034*/	UINT	    BreakpointMode;
/*0x038*/	UINT        PromptMode;
/*0x03c*/	UINT		UploadTransport;
/*0x040*/	PCHAR		PublicKeyBase64;
/*0x044*/	PVOID		PostUploadCallback;
/*0x048*/	PVOID		PostUploadContext;
/*0x04c*/	bool		bLocalFullDump;
/*0x04d*/	bool		bContinueExecutionAfterDump;
/*0x04e*/	bool		bInInit;
/*0x050*/	PCHAR		pPathToUploader;//wws_crashreport_uploader.exe
/*0x054*/	PCHAR		pConnectHostName;//recap.daybreakgames.com:15081
/*0x058*/	PCHAR		pRecapSessionName;
/*0x05c*/	PCHAR		pProductVersion;//87717
/*0x060*/	UINT        LogLevel;
/*0x064*/   PVOID       LogFunc;
/*0x068*/   PVOID       LogContext;
/*0x06c*/   SessionFolderDescription SessionFolderDesc;
/*0x074*/   SessionFolderLock SFLock;
/*0x078*/   bool		bNoUploaderUi;
/*0x079*/   bool		bRequestCallstack;
/*0x07a*/   bool		bCoreDumpInProgress;
/*0x07b*/   BYTE		NoExceptionHandler;
/*0x07c*/   bool		bDisplaySessionURL;
/*0x07d*/   bool		bUploadSupplemental;
/*0x080*/
} EQCrash, *PEQCrash;
typedef struct _CrashReport
{
	/*0x000*/	BYTE Unknown0x000[0x24];
	/*0x024*/	PCHAR sessionpath;
} CrashReport, *PCrashReport;
//you can customize the crash dialog message here if this doesn't suit you.
//these args needs to be allocated properly if u call this func, but you shouldnt...
//just know that you can customize it for now as long as u keep the string lenghts < MAX_STRING
EQLIB_API VOID GetCrashDialogMessage(char *Title, char *Message1,char *Message2,char *Message3,char *Message4)
{
	strcpy_s(Title ,MAX_STRING, "MQ2 Crash Notification");
	strcpy_s(Message1 ,MAX_STRING, "MQ2 has detected that your client may have crashed.");
	strcpy_s(Message2 ,MAX_STRING, "It is often possible to determine where and why the crash occurred.");
	strcpy_s(Message3 ,MAX_STRING, "Click OK to send this data back to EqMule in an effort to help improve the stability of MQ2.");
	strcpy_s(Message4 ,MAX_STRING, "Also, if you have a moment, please enter details about what you were doing when you crashed:");
}
//this function is called after a crashdump has been generated and it points to that file
EQLIB_API VOID MQ2CrashCallBack(PCHAR DumpFile)
{
	//add your own handling here if you dont want like the default one or have other ideas on how to handle crashes yourself
	//you can delete the file, copy/move it or just upload to your own dump server etc...

}

#endif
DETOUR_TRAMPOLINE_EMPTY(int LoadFrontEnd_Trampoline());
PVOID pv = 0;
ULONG op;

#ifndef TESTMEM
int LoadFrontEnd_Detour()
{
	int ret = LoadFrontEnd_Trampoline();
	gGameState = GetGameState();
	DebugTry(Benchmark(bmPluginsSetGameState, PluginsSetGameState(gGameState)));
	return ret;
}
HANDLE ghFrontEnd = 0;
DWORD __stdcall WaitForeqmain(PVOID pData)
{
	while (!GetModuleHandle("eqmain.dll"))
	{
		Sleep(10);
		if (GetGameState() != GAMESTATE_PRECHARSELECT)
			break;
	}
	if (GetGameState() == GAMESTATE_PRECHARSELECT)
	{
		Sleep(1000);//this is stupid we should replace this with a function that checks tht eqmain is fully loaded: todo
		OutputDebugString("InitializeLoginPulse will be called\n");
		PluginsSetGameState(GAMESTATE_POSTFRONTLOAD);
		InitializeLoginPulse();
	}
	ghFrontEnd = 0;
	return 0;
}

LONG NTAPI ExceptionHandler(::PEXCEPTION_POINTERS pep)
{
 	if (pep->ExceptionRecord->ExceptionCode == STATUS_GUARD_PAGE_VIOLATION)
	{
		DWORD ThreadID = 0;
		if (!ghFrontEnd)
		{
			ghFrontEnd = CreateThread(NULL, 0, WaitForeqmain, 0, 0, &ThreadID);
		}
		return EXCEPTION_CONTINUE_EXECUTION;
	}

	return EXCEPTION_CONTINUE_SEARCH;
}
#endif
void InitializeMQ2Detours()
{
#ifndef ISXEQ
	__try
	{
		InitializeCriticalSection(&gDetourCS);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		//DWORD Status = GetExceptionCode();
		MessageBox(NULL, "could not initialize the detours.", "an exception occured in InitializeMQ2Detours", MB_OK);
		return;
	}

	HookMemChecker(TRUE);
#endif
#if !defined(ROF2EMU) && !defined(UFEMU)
	//this is handled by mq2ic from now on
	//EzDetourwName(wwsCrashReportCheckForUploader, wwsCrashReportCheckForUploader_Detour, wwsCrashReportCheckForUploader_Trampoline,"wwsCrashReportCheckForUploader");
	//EzDetourwName(CrashDetected, CrashDetected_Detour, CrashDetected_Trampoline,"CrashDetected");
#endif
#ifndef TESTMEM
	//we don't need this detour anymore, we wil just add a one time guard page exception and add login pulse up when it's hit
	#if defined(ROF2EMU) || defined(UFEMU)
	EzDetourwName(__LoadFrontEnd, LoadFrontEnd_Detour, LoadFrontEnd_Trampoline,"__LoadFrontEnd");
	#else
	pv = AddVectoredExceptionHandler(TRUE, ExceptionHandler);
	VirtualProtect((LPVOID)__ExecuteFrontEnd, 1, PAGE_EXECUTE_READWRITE|PAGE_GUARD, &op);
	#endif
#endif
}

void ShutdownMQ2Detours()
{
	#if !defined(ROF2EMU) && !defined(UFEMU)
	RemoveVectoredExceptionHandler(pv);
	ULONG tmp;
	VirtualProtect((LPVOID)__ExecuteFrontEnd, 1, op, &tmp);
	TerminateThread(ghFrontEnd, 0);
	ghFrontEnd = 0;
	#else
	RemoveDetour(__LoadFrontEnd);
	#endif
#ifndef ISXEQ
	HookMemChecker(FALSE);
	RemoveOurDetours();
#if !defined(ROF2EMU) && !defined(UFEMU)
	//RemoveDetour(CrashDetected);
	//RemoveDetour(wwsCrashReportCheckForUploader);
#endif
	DeleteCriticalSection(&gDetourCS);
#endif
}


#pragma optimize( "", off )

void emotify(void)
{
	char buffer[EB_SIZE];
	emotify2(buffer);
}
void emotify2(char *A)
{
	int i;
	for (i = 0; i<EB_SIZE; i += 1024)
		memcpy(A + i, EQADDR_ENCRYPTPAD0, 1024);
	/*
	int Pos = &A[0];
	int End = Pos + EB_SIZE;
	for (Pos ; Pos < End ; Pos++)
	A[Pos]=0;

	int t;
	for (Pos ; Pos < 1024 ; Pos++) {
	t = (int)(397.0*rand()/(RAND_MAX+1.0));
	A[Pos]=(t <= 255) ? (char)t : 0;
	}
	*/
}
#pragma optimize( "", on )