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
#pragma pack(push)
#pragma pack(8)
#define VersionString __ExpectedVersionDate
#define TimeString __ExpectedVersionTime
#define DebugHeader "[MQ2]"
#define LoadedString "MQ2 Loaded."
#define ToUnloadString "MQ2 Unloading..."
#define UnloadedString "MQ2 Unloaded."

#define WIN32_LEAN_AND_MEAN
#if defined(_WIN32_WINNT)
#undef _WIN32_WINNT
#define  _WIN32_WINNT   0x510
#endif
#define DIRECTINPUT_VERSION 0x800

//#define MQ2_PROFILING

// uncomment this line to turn off the single-line benchmark macro
// #define DISABLE_BENCHMARKS

//warning C4530 : C++ exception handler used, but unwind semantics are not enabled.Specify / EHsc
#pragma warning(disable:4530)

//disable the noexcept warning there isnt really anything we can do about it as far as i know or is there? let me know if u know how to fix it - eqmule
#pragma warning(disable:4577)


// Windows Header Files:
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <io.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <winsock.h>
#include <math.h>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <algorithm>
//dont enable this again, because we littler all the rest of the code with this namespace if we do.
//namespaces don't belong in gloabl header files
//let everyone that needs this one put it in their own projects.
//using namespace std;

#if !defined(ISXEQ) && !defined(ISXEQ_LEGACY)
// MQ2
#include "..\Dxsdk90\include\dinput.h"
#include "..\Detours\inc\detours.h" 
#include "..\Blech\Blech.h"
#elif !defined(ISXEQ_LEGACY)
// ISXEQ
#ifndef MQ2PLUGIN
#include "ISXEQ\ISXEQ.h"
#else
#pragma pack(push)
#pragma pack(8)
#include <isxdk.h>
#pragma pack(pop)
#include "ISXEQ\ISXEQServices.h"
#endif
#define PMQ2TYPEMEMBER PLSTYPEMEMBER
#define PMQ2TYPEMETHOD PLSTYPEMETHOD
#define MQ2Type LSType
#define MQ2TYPEVAR LSTYPEVAR

#else
// ISXEQ_LEGACY
#include <winthreading.h>
#include <Index.h>
#include "..\Dxsdk81\include\dinput.h"
#include "..\Blech\Blech.h"
#endif

extern CRITICAL_SECTION gPluginCS;
#if defined(LIVE) || defined(TEST) || defined(EQBETA) || defined(ROF2EMU) || defined(UFEMU)
//do nothing because the user has set one of these as a preprocessor argument instead...
//we default to LIVE though...
#else
//define LIVE, TEST, EQBETA, ROF2EMU or UFEMU here depending on which eqgame you are building for. -eqmule sep 27 2014
#define TEST
#endif
#if defined(LIVE)
#include "eqgame.h"
//#define NEWCHARINFO
#elif defined(TEST)
#include "eqgame(Test).h"
//#define NEWCHARINFO
#elif defined(EQBETA)
#include "eqgame(beta).h"
//#define NEWCHARINFO
#elif defined(ROF2EMU)
#include "eqgame(emu).h"
//#define NEWCHARINFO
#elif defined(UFEMU)
#include "eqgame(uf).h"
#endif
#ifndef ISXEQ
#define RETURN(x) return;
#else
#define RETURN(x) return x;
#endif
#ifdef ISXEQ
#define MacroError WriteChatf
#endif
#define KeyRingWindowParent "KeyRingWnd"
#define MountWindowList "KRW_Mounts_List"
#define IllusionWindowList "KRW_Illusions_List"
#define FamiliarWindowList "KRW_Familiars_list"
#define KeyRingTab "KRW_Subwindows"

#if defined(ROF2EMU) || defined(UFEMU)
#define csnOffset 0x1a4
#define sncOffset 0x190
#define cbssOffset 0x18c
#else
#define csnOffset 0x1a8
#define sncOffset 0x194
#define cbssOffset 0x190
#endif
#ifdef ISXEQ_LEGACY
#define LEGACY_API extern
#define LEGACY_VAR extern
#else
#define LEGACY_API EQLIB_API
#define LEGACY_VAR EQLIB_VAR
#endif

#ifdef EQLIB_EXPORTS
#define EQLIB_API extern "C" __declspec(dllexport)
#define EQLIB_VAR extern "C" __declspec(dllexport)
#define EQLIB_OBJECT __declspec(dllexport)
#else
#define EQLIB_API extern "C" __declspec(dllimport)
#define EQLIB_VAR extern "C" __declspec(dllimport)
#define EQLIB_OBJECT __declspec(dllimport)
#endif

#ifdef MQ2PLUGIN
#define FromPlugin 1
#else
#define FromPlugin 0
#endif

// Lax/Blech event support *READY*
#define USEBLECHEVENTS

// reroute malloc/free
EQLIB_API VOID *MQ2Malloc(size_t size);
EQLIB_API VOID MQ2Free(VOID *memblock);
/*
#ifdef MQ2PLUGIN
#define malloc(x) MQ2Malloc(x)
#define free(x) MQ2Free(x)
#else
#ifdef DEBUG_ALLOC
#define malloc(x) MQ2Malloc(x)
#define free(x) MQ2Free(x)
#endif
#endif
*/
#ifdef DEBUG_ALLOC
extern DWORD CountMallocs;
extern DWORD CountFrees;
#endif

#ifndef ISXEQ
#define FUNCTION_AT_ADDRESS(function,offset)  __declspec(naked) function\
{\
    __asm{mov eax, offset};\
    __asm{jmp eax};\
}

#define FUNCTION_AT_VARIABLE_ADDRESS(function,variable) __declspec(naked) function\
{\
    __asm{mov eax, [variable]};\
    __asm{jmp eax};\
}

#define FUNCTION_AT_VIRTUAL_ADDRESS(function,virtualoffset) __declspec(naked) function\
{\
    __asm{mov eax, [ecx]};\
    __asm{lea eax, [eax+virtualoffset]};\
    __asm{mov eax, [eax]};\
    __asm{jmp eax};\
}
#endif

#define PreserveRegisters(code) \
{\
    __asm {push eax};\
    __asm {push ebx};\
    __asm {push ecx};\
    __asm {push edx};\
    __asm {push esi};\
    __asm {push edi};\
    code;\
    __asm {pop edi};\
    __asm {pop esi};\
    __asm {pop edx};\
    __asm {pop ecx};\
    __asm {pop ebx};\
    __asm {pop eax};\
}

#define SetWndNotification(thisclass) \
{\
    int (thisclass::*pfWndNotification)(CXWnd *pWnd, unsigned int Message, void *unknown)=&thisclass::WndNotification;\
    SetvfTable(34,*(DWORD*)&pfWndNotification);\
}

#ifndef ISXEQ
#ifdef ISXEQ_LEGACY
#define EzDetour(offset,detour,trampoline)
#define EzDetourwName(offset,detour,trampoline,name)
#define DETOUR_TRAMPOLINE_EMPTY(blah)
#else
#define EzDetour(offset,detour,trampoline) AddDetourf((DWORD)offset,detour,trampoline)
#define EzDetourwName(offset,detour,trampoline,name) AddDetourf((DWORD)offset,detour,trampoline,name)
#endif
#endif

#ifndef DOUBLE
typedef double DOUBLE;
#endif
#ifndef THIS_
#define THIS_                   INTERFACE FAR* This,
#endif

// DEBUGGING
//#ifndef DEBUG_TRY
//#define DEBUG_TRY
//#endif
#ifdef DEBUG_TRY
#define DebugTry(x) DebugSpew("Trying %s",#x);x;DebugSpew("%s complete",#x)
#else
#define DebugTry(x) x
#endif

#ifndef ISXEQ
#define MakeLower(yourstring) std::transform (yourstring.begin(),yourstring.end(), yourstring.begin(), tolower);
#endif

#define MAX_VARNAME 64
#define MAX_STRING            2048

#define IsNaN(x) (x != x)

#if defined(LIVE)
#include "EQData.h"
#include "EQUIStructs.h"
#elif defined(TEST)
#include "EQData(Test).h"
#include "EQUIStructs(Test).h"
#elif defined(EQBETA)
#include "EQData(beta).h"
#include "EQUIStructs(beta).h"
#elif defined(ROF2EMU)
#include "EQData(emu).h"
#include "EQUIStructs(emu).h"
#elif defined(UFEMU)
#include "EQData(uf).h"
#include "EQUIStructs(uf).h"
#endif

//class CXMLData *GetXMLData(class CXWnd *pWnd)

#include "EQClasses.h"

#include "MQ2Prototypes.h"
#include "MQ2Internal.h"
#include "MQ2Globals.h"



/* BENCHMARKING */
#ifdef DISABLE_BENCHMARKS
#define Benchmark(BMHandle,code) code
#else
#define Benchmark(BMHandle,code) {EnterMQ2Benchmark(BMHandle);code;ExitMQ2Benchmark(BMHandle);}
#endif
EQLIB_API VOID ShutdownMQ2Benchmarks();
EQLIB_API VOID InitializeMQ2Benchmarks();
EQLIB_API BOOL GetMQ2Benchmark(DWORD BMHandle, MQBENCH &Dest);
EQLIB_API VOID ExitMQ2Benchmark(DWORD BMHandle);
EQLIB_API VOID EnterMQ2Benchmark(DWORD BMHandle);
EQLIB_API VOID RemoveMQ2Benchmark(DWORD BMHandle);
EQLIB_API DWORD AddMQ2Benchmark(PCHAR Name);

/* SPAWN HANDLING */
EQLIB_API VOID InitializeMQ2Spawns();
EQLIB_API VOID ShutdownMQ2Spawns();
EQLIB_API VOID ProcessPendingGroundItems();
EQLIB_API VOID UpdateMQ2SpawnSort();
EQLIB_API BOOL SetNameSpriteState(PSPAWNINFO pSpawn, bool Show);
EQLIB_API BOOL IsTargetable(PSPAWNINFO pSpawn);

/* WINDOWS */
EQLIB_API BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);
EQLIB_API VOID InitializeMQ2Windows();
EQLIB_API VOID ShutdownMQ2Windows();
EQLIB_API void RemoveXMLFile(const char *filename);
EQLIB_API void AddXMLFile(const char *filename);
EQLIB_API bool SendWndClick(PCHAR WindowName, PCHAR ScreenID, PCHAR ClickNotification);
EQLIB_API bool SendWndNotification(PCHAR WindowName, PCHAR ScreenID, DWORD Notification, VOID *Data = 0);
EQLIB_API void AddWindow(char *WindowName, CXWnd **ppWindow);
EQLIB_API void RemoveWindow(char *WindowName);
EQLIB_API CXWnd *FindMQ2Window(PCHAR Name);
EQLIB_API CXWnd *GetParentWnd(class CXWnd const * pWnd);

EQLIB_API bool SendComboSelect(PCHAR WindowName, PCHAR ScreenID, DWORD Value);
EQLIB_API bool SendListSelect(PCHAR WindowName, PCHAR ScreenID, DWORD Value);
EQLIB_API bool SendListSelect2(CXWnd *pList, LONG ListIndex);
EQLIB_API bool SendWndClick2(CXWnd *pWnd, PCHAR ClickNotification);

EQLIB_API VOID CreateMQ2NewsWindow();
EQLIB_API VOID DeleteMQ2NewsWindow();

/* CHAT HOOK */
EQLIB_API VOID InitializeChatHook();
EQLIB_API VOID ShutdownChatHook();
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_API VOID dsp_chat_no_events(const char *, int, bool, bool = 1,int = 0);
#else
EQLIB_API VOID dsp_chat_no_events(const char *, int, bool, bool = 1);
#endif

/* DETOURING API */
EQLIB_API VOID InitializeMQ2Detours();
EQLIB_API VOID ShutdownMQ2Detours();

#ifndef ISXEQ
#ifdef ISXEQ_LEGACY
#define RemoveDetour(address)
#define AddDetour __noop
#define AddDetourf __noop
#else
EQLIB_API BOOL AddDetour(DWORD address, PBYTE pfDetour = 0, PBYTE pfTrampoline = 0, DWORD Count = 20, PCHAR Name = 0);
EQLIB_API VOID AddDetourf(DWORD address, ...);
EQLIB_API VOID RemoveDetour(DWORD address);
EQLIB_API void DeleteDetour(DWORD address);
#endif
#else
#define RemoveDetour EzUnDetour
#endif

/* PLUGIN HANDLING */
EQLIB_API VOID WriteChatf(PCHAR Format, ...);
EQLIB_API VOID WriteChatfSafe(PCHAR szFormat, ...);
EQLIB_API VOID WriteChatColor(PCHAR Line, DWORD Color = USERCOLOR_DEFAULT, DWORD Filter = 0);
#ifndef ISXEQ
EQLIB_API VOID InitializeMQ2Plugins();
EQLIB_API DWORD LoadMQ2Plugin(const PCHAR pszFilename, BOOL bCustom = 0);
EQLIB_API BOOL UnloadMQ2Plugin(const PCHAR pszFilename);
EQLIB_API VOID UnloadMQ2Plugins();
EQLIB_API VOID ShutdownMQ2Plugins();
EQLIB_API VOID SaveMQ2PluginLoadStatus(char*Name, bool bLoad);
#endif
EQLIB_API VOID PulsePlugins();
EQLIB_API VOID PluginsZoned();
EQLIB_API BOOL PluginsIncomingChat(PCHAR Line, DWORD Color);
EQLIB_API VOID PluginsCleanUI();
EQLIB_API VOID PluginsReloadUI();
EQLIB_API VOID PluginsSetGameState(DWORD GameState);
EQLIB_API VOID PluginsDrawHUD();
EQLIB_API VOID PluginsAddSpawn(PSPAWNINFO pNewSpawn);
EQLIB_API VOID PluginsRemoveSpawn(PSPAWNINFO pSpawn);
EQLIB_API VOID PluginsAddGroundItem(PGROUNDITEM pNewGroundItem);
EQLIB_API VOID PluginsRemoveGroundItem(PGROUNDITEM pGroundItem);
EQLIB_API VOID PluginsBeginZone(VOID);
EQLIB_API VOID PluginsEndZone(VOID);

/* DIRECT INPUT */
#ifndef ISXEQ
EQLIB_API VOID InitializeMQ2DInput();
EQLIB_API VOID ShutdownMQ2DInput();
#endif

/* CLEAN UI */
EQLIB_API VOID InitializeDisplayHook();
EQLIB_API VOID ShutdownDisplayHook();
EQLIB_API VOID DrawHUD();

/* COMMAND HANDLING */
LEGACY_API VOID InitializeMQ2Commands();
LEGACY_API VOID ShutdownMQ2Commands();
LEGACY_API VOID AddCommand(PCHAR Command, fEQCommand Function, BOOL EQ = 0, BOOL Parse = 1, BOOL InGame = 0);
LEGACY_API VOID AddAlias(PCHAR ShortCommand, PCHAR LongCommand);
LEGACY_API BOOL RemoveAlias(PCHAR ShortCommand);
LEGACY_API VOID AddSubstitute(PCHAR Original, PCHAR Substitution);
LEGACY_API BOOL RemoveSubstitute(PCHAR Original);
LEGACY_API BOOL RemoveCommand(PCHAR Command);
LEGACY_API VOID DoTimedCommands();
LEGACY_API VOID TimedCommand(PCHAR Command, DWORD msDelay);

/* MACRO COMMANDS */
LEGACY_API VOID DumpStack(PSPAWNINFO, PCHAR);
LEGACY_API VOID EndMacro(PSPAWNINFO, PCHAR);
LEGACY_API VOID Echo(PSPAWNINFO, PCHAR);

/* MACRO PARSING */
#ifdef USEBLECHEVENTS
void __stdcall EventBlechCallback(unsigned int ID, void * pData, PBLECHVALUE pValues);
#endif
#define PMP_ERROR_BADPARM 10000
LEGACY_API PCHAR ParseMacroParameter(PSPAWNINFO pChar, PCHAR szOriginal, SIZE_T BufferSize);
template <unsigned int _Size>__declspec(dllexport) PCHAR ParseMacroParameter(PSPAWNINFO pChar, CHAR(&szOriginal)[_Size])
{
	return ParseMacroParameter(pChar, szOriginal, _Size);
}
#ifndef ISXEQ
LEGACY_API VOID FailIf(PSPAWNINFO pChar, PCHAR szCommand, int pStartLine, BOOL All = FALSE);
LEGACY_API VOID InitializeParser();
LEGACY_API VOID ShutdownParser();

LEGACY_API VOID InitializeMQ2DataTypes();
LEGACY_API VOID ShutdownMQ2DataTypes();
LEGACY_API VOID InitializeMQ2Data();
LEGACY_API VOID ShutdownMQ2Data();
LEGACY_API BOOL ParseMacroData(PCHAR szOriginal, SIZE_T BufferSize);
LEGACY_API BOOL AddMQ2Data(PCHAR szName, fMQData Function);
LEGACY_API BOOL RemoveMQ2Data(PCHAR szName);
LEGACY_API MQ2Type *FindMQ2DataType(PCHAR szName);
LEGACY_API PMQ2DATAITEM FindMQ2Data(PCHAR szName);
LEGACY_API PDATAVAR FindMQ2DataVariable(PCHAR szName);
LEGACY_API BOOL ParseMQ2DataPortion(PCHAR szOriginal, MQ2TYPEVAR &Result);
LEGACY_API bool AddMQ2TypeExtension(const char* typeName, MQ2Type* extension);
LEGACY_API bool RemoveMQ2TypeExtension(const char* typeName, MQ2Type* extension);
#endif


/* MOUSE */
EQLIB_API BOOL IsMouseWaiting(VOID);
EQLIB_API BOOL IsMouseWaitingForButton();
EQLIB_API void MQ2MouseHooks(BOOL bFlag);
EQLIB_API BOOL MoveMouse(DWORD x, DWORD y, BOOL bClick = 0);
EQLIB_API bool MouseToPlayer(EQPlayer*pPlayer, DWORD position, BOOL bClick = 0);

/* KEY BINDS */
EQLIB_API VOID InitializeMQ2KeyBinds();
EQLIB_API VOID ShutdownMQ2KeyBinds();
EQLIB_API BOOL PressMQ2KeyBind(PCHAR name, BOOL Hold);
EQLIB_API BOOL SetMQ2KeyBind(PCHAR name, BOOL Alternate, KeyCombo &Combo);
EQLIB_API BOOL AddMQ2KeyBind(PCHAR name, fMQExecuteCmd Function);
EQLIB_API BOOL RemoveMQ2KeyBind(PCHAR name);
EQLIB_API BOOL GetMQ2KeyBind(PCHAR name, BOOL Alt, KeyCombo &Combo);
EQLIB_API BOOL DumpBinds(PCHAR Filename);
EQLIB_API BOOL MQ2HandleKeyDown(class KeyCombo const &Combo);
EQLIB_API BOOL MQ2HandleKeyUp(class KeyCombo const &Combo);

/* PULSING */
EQLIB_API VOID InitializeMQ2Pulse();
EQLIB_API VOID ShutdownMQ2Pulse();

/* OTHER IMPORTED FROM EQ */
EQLIB_API int CastRay(PSPAWNINFO, float y, float x, float z);
EQLIB_API int CastRayLoc(const CVector3& SourcePos, int Race, float DestX, float DestY, float DestZ);
EQLIB_API float HeadingDiff(float h1, float h2, float *DiffOut);
EQLIB_API float FixHeading(float Heading);
EQLIB_API float get_bearing(float x1, float y1, float x2, float y2);
EQLIB_API unsigned long GetFastTime(void);
EQLIB_API char * __stdcall GetXtargetType(DWORD type);
EQLIB_API DWORD EQGetTime();
EQLIB_API CXStr *__cdecl STMLToText(CXStr *Out, CXStr const &In, bool bFlag);
EQLIB_API class IconCache *__cdecl GetAnimationCache(int index);
EQLIB_API void SaveColors(int, int, int, int);

/* UTILITIES */
EQLIB_API VOID ConvertCR(PCHAR Text, size_t LineLen);
EQLIB_API VOID DrawHUDText(PCHAR Text, DWORD X, DWORD Y, DWORD Argb, DWORD Font);
EQLIB_API VOID FixStringTable();
EQLIB_API VOID DebugSpew(PCHAR szFormat, ...);
EQLIB_API VOID DebugSpewAlways(PCHAR szFormat, ...);
EQLIB_API VOID DebugSpewAlwaysFile(PCHAR szFormat, ...);
EQLIB_API VOID DebugSpewNoFile(PCHAR szFormat, ...);
//#ifndef ISXEQ
LEGACY_API PSTR GetNextArg(PCSTR szLine, DWORD dwNumber = 1, BOOL CSV = FALSE, CHAR Separator = 0);
LEGACY_API PSTR GetArg(PSTR szDest, PCSTR szSrc, DWORD dwNumber, BOOL LeaveQuotes = FALSE, BOOL ToParen = FALSE, BOOL CSV = FALSE, CHAR Separator = 0, BOOL AnyNonAlphaNum = FALSE);
//#endif
LEGACY_API VOID AddCustomEvent(PEVENTLIST pEList, PCHAR szLine);
EQLIB_API FLOAT DistanceToSpawn(PSPAWNINFO pChar, PSPAWNINFO pSpawn);
EQLIB_API PCHAR GetEQPath(PCHAR szBuffer, size_t len);

#define DoCommand(pspawninfo,commandtoexecute) HideDoCommand(pspawninfo,commandtoexecute,FromPlugin)
LEGACY_API VOID HideDoCommand(PSPAWNINFO pChar, PCHAR szLine, BOOL delayed);
#define EzCommand(commandtoexecute) DoCommand((PSPAWNINFO)pLocalPlayer,commandtoexecute)

EQLIB_API VOID AppendCXStr(PCXSTR *cxstr, PCHAR text);
EQLIB_API VOID SetCXStr(PCXSTR *cxstr, PCHAR text);
EQLIB_API DWORD GetCXStr(PCXSTR pCXStr, PCHAR szBuffer, DWORD maxlen = MAX_STRING);
EQLIB_API DWORD MQToSTML(PCHAR in, PCHAR out, DWORD maxlen = MAX_STRING, DWORD ColorOverride = 0xFFFFFF);
EQLIB_API VOID StripMQChat(PCHAR in, PCHAR out);
EQLIB_API VOID STMLToPlainText(PCHAR in, PCHAR out);
EQLIB_API PCHAR GetSubFromLine(int Line, PCHAR szSub, size_t Sublen);
EQLIB_API PCHAR GetFilenameFromFullPath(PCHAR Filename);
EQLIB_API BOOL CompareTimes(PCHAR RealTime, PCHAR ExpectedTime);
EQLIB_API VOID AddFilter(PCHAR szFilter, DWORD Length, PBOOL pEnabled);
EQLIB_API VOID DefaultFilters(VOID);
EQLIB_API PCHAR ConvertHotkeyNameToKeyName(PCHAR szName);
LEGACY_API VOID CheckChatForEvent(PCHAR szMsg);
EQLIB_API VOID ConvertItemTags(CXStr &cxstr, BOOL Tag = TRUE);
EQLIB_API BOOL ParseKeyCombo(PCHAR text, KeyCombo &Dest);
EQLIB_API PCHAR DescribeKeyCombo(KeyCombo &Combo, PCHAR szDest, SIZE_T BufferSize);
EQLIB_API int FindInvSlotForContents(PCONTENTS pContents);
EQLIB_API int FindInvSlot(PCHAR Name, BOOL Exact);
EQLIB_API int FindNextInvSlot(PCHAR Name, BOOL Exact);
EQLIB_API int FindMappableCommand(const char *name);

EQLIB_API int GetLanguageIDByName(PCHAR szName);
EQLIB_API int GetCurrencyIDByName(PCHAR szName);
EQLIB_API PCHAR GetSpellNameByID(LONG dwSpellID);
EQLIB_API PSPELL GetSpellByName(PCHAR szName);
EQLIB_API PSPELL GetSpellByAAName(PCHAR szName);
EQLIB_API PSPELL GetSpellByAAName(PCHAR szName);
EQLIB_API PALTABILITY GetAAByIdWrapper(int nAbilityId, int playerLevel = -1);
EQLIB_API DWORD GetSpellRankByName(PCHAR SpellName);
EQLIB_API VOID TruncateSpellRankName(PCHAR SpellName);
EQLIB_API VOID RemoveBuff(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID RemovePetBuff(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API bool StripQuotes(char *str);
EQLIB_API VOID MakeMeVisible(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID RemoveAura(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API BOOL GetAllMercDesc(std::map<DWORD, MercDesc>&minfo);

DWORD GetKeyRingIndex(DWORD KeyRing, PCHAR szItemName, SIZE_T BuffLen, bool bExact = true, bool usecmd = false);
EQLIB_API int GetMountCount();
EQLIB_API int GetIllusionCount();
EQLIB_API int GetFamiliarCount();
EQLIB_API void RefreshKeyRings(PVOID kr);
EQLIB_API void InitKeyRings();
EQLIB_API BOOL IsActiveAA(PCHAR pSpellName);
EQLIB_API CXWnd *GetAdvLootPersonalListItem(DWORD ListIndex/*YES ITS THE INTERNAL INDEX*/, DWORD type);
EQLIB_API CXWnd *GetAdvLootSharedListItem(DWORD ListIndex/*YES IT REALLY IS THE LISTINDEX*/, DWORD type);
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_API BOOL LootInProgress(PEQADVLOOTWND pAdvLoot, CListWnd*pPersonalList, CListWnd*pSharedList);
#endif
EQLIB_API void WeDidStuff();
EQLIB_API int GetFreeInventory(int nSize);
EQLIB_API int RangeRandom(int min, int max);
EQLIB_API DWORD __stdcall BeepOnTellThread(PVOID pData);
EQLIB_API DWORD __stdcall FlashOnTellThread(PVOID pData);
EQLIB_API CMQ2Alerts CAlerts;
EQLIB_VAR BOOL bPluginCS;
typedef struct _krdata
{
	CHAR ItemName[256];
	CXWnd *phWnd;
	MQ2TYPEVAR mq2typevar;
	bool bExact;
	bool bUseCmd;
}krdata, *pkrdata;

namespace EQData {
	EQLIB_API struct _ITEMINFO *GetItemFromContents(struct _CONTENTS *c);
};
#include "MQ2Inlines.h"


#ifdef ISXEQ
#define GETMEMBER() GetMember(LSVARPTR VarPtr, PCHAR Member, int argc, char *argv[], LSTYPEVAR &Dest)
#define GETMETHOD() GetMethod(LSVARPTR &VarPtr, PCHAR Method, int argc, char *argv[])
#define DECLAREGETMETHOD() bool GETMETHOD()
#else
#define GETMEMBER() GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
#define DECLAREGETMETHOD()
#define INHERITDIRECT(X)
#define INHERITINDIRECT(X,Y,Z)
#endif

#include "MQ2DataTypes.h"

#ifndef ISXEQ
LEGACY_API BOOL AddMacroLine(PCHAR FileName, PCHAR szLine, size_t Linelen, int *LineNumber, int localLine);
#endif

EQLIB_API PCHAR GetLightForSpawn(PSPAWNINFO pSpawn);
EQLIB_API DWORD GetSpellDuration(PSPELL pSpell, PSPAWNINFO pSpawn);
EQLIB_API DWORD GetDeityTeamByID(DWORD DeityID);
EQLIB_API DWORD ConColor(PSPAWNINFO pSpawn);

#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_API PCHAR GetGuildByID(__int64 GuildID);
EQLIB_API __int64 GetGuildIDByName(PCHAR szGuild);
#else
EQLIB_API PCHAR GetGuildByID(DWORD GuildID);
EQLIB_API DWORD GetGuildIDByName(PCHAR szGuild);
#endif
extern std::map<int, std::string>targetBuffSlotToCasterMap; 

EQLIB_API PCONTENTS GetEnviroContainer();
EQLIB_API PEQCONTAINERWINDOW FindContainerForContents(PCONTENTS pContents);
EQLIB_API FLOAT FindSpeed(PSPAWNINFO pSpawn);
EQLIB_API BOOL IsNamed(PSPAWNINFO pSpawn);
EQLIB_API VOID GetItemLinkHash(PCONTENTS Item, PCHAR Buffer, SIZE_T BufferSize);
template <unsigned int _Size>__declspec(dllexport) VOID GetItemLinkHash(PCONTENTS Item, CHAR(&Buffer)[_Size])
{
	return GetItemLinkHash(Item, Buffer, _Size);
}
EQLIB_API BOOL GetItemLink(PCONTENTS Item, PCHAR Buffer, SIZE_T BufferSize, BOOL Clickable = TRUE);
template <unsigned int _Size>__declspec(dllexport) BOOL GetItemLink(PCONTENTS Item, CHAR(&Buffer)[_Size], BOOL Clickable = TRUE)
{
	return GetItemLink(Item, Buffer, _Size, Clickable);
}
EQLIB_API PCHAR GetLoginName();
EQLIB_API FLOAT DistanceToPoint(PSPAWNINFO pSpawn, FLOAT xLoc, FLOAT yLoc);
EQLIB_API FLOAT Distance3DToPoint(PSPAWNINFO pSpawn, FLOAT xLoc, FLOAT yLoc, FLOAT zLoc);
EQLIB_API PCHAR ShowSpellSlotInfo(PSPELL pSpell, PCHAR szBuffer, SIZE_T BufferSize);
EQLIB_API PCHAR ParseSpellEffect(PSPELL pSpell, int i, PCHAR szBuffer, SIZE_T BufferSize, LONG level = 100);

EQLIB_API LONG GetSpellAttrib(PSPELL pSpell, int index);
EQLIB_API LONG GetSpellBase(PSPELL pSpell, int index);
EQLIB_API LONG GetSpellBase2(PSPELL pSpell, int index);
EQLIB_API LONG GetSpellMax(PSPELL pSpell, int index);
EQLIB_API LONG GetSpellCalc(PSPELL pSpell, int index);

EQLIB_API VOID SlotValueCalculate(PCHAR szBuff, PSPELL pSpell, int i, double mp = 1.0);
EQLIB_API LONG CalcValue(LONG calc, LONG base, LONG max, LONG tick, LONG minlevel = MAX_PC_LEVEL, LONG level = MAX_PC_LEVEL);
EQLIB_API PCHAR GetSpellEffectName(LONG EffectID, PCHAR szBuffer, SIZE_T BufferSize);
EQLIB_API VOID GetGameDate(int* Month, int* Day, int* Year);
EQLIB_API VOID GetGameTime(int* Hour, int* Minute, int* Night);
LEGACY_API VOID SyntaxError(PCHAR szFormat, ...);
LEGACY_API VOID MacroError(PCHAR szFormat, ...);
LEGACY_API VOID FatalError(PCHAR szFormat, ...);
EQLIB_API PCHAR GetSpellRestrictions(PSPELL pSpell, unsigned int nIndex, PCHAR szBuffer, SIZE_T BufferSize);
#ifndef ISXEQ
LEGACY_API VOID MQ2DataError(PCHAR szFormat, ...);
#endif
EQLIB_API void DisplayOverlayText(PCHAR szText, DWORD dwColor, DWORD dwTransparency, DWORD msFadeIn, DWORD msFadeOut, DWORD msHold);
EQLIB_API void CustomPopup(char* szPopText, bool bPopOutput);

EQLIB_API BOOL IsBardSong(PSPELL pSpell);
EQLIB_API BOOL IsSPAEffect(PSPELL pSpell, LONG EffectID);
EQLIB_API bool GetShortBuffID(PSPELLBUFF pBuff, DWORD &nID);
EQLIB_API bool GetBuffID(PSPELLBUFF pBuff, DWORD &nID);
EQLIB_API PCHAR GetLDoNTheme(DWORD LDTheme);
EQLIB_API BOOL TriggeringEffectSpell(PSPELL aSpell, int i);
EQLIB_API BOOL BuffStackTest(PSPELL aSpell, PSPELL bSpell, BOOL bIgnoreTriggeringEffects = FALSE, BOOL bTriggeredEffectCheck = FALSE);
EQLIB_API DWORD GetItemTimer(PCONTENTS pItem);
EQLIB_API PCONTENTS GetItemContentsBySlotID(DWORD dwSlotID);
EQLIB_API PCONTENTS GetItemContentsByName(CHAR *ItemName);
EQLIB_API DWORD GetAvailableSlots(PCONTENTS pContainer, PCONTENTS pItem, int *firstavailableslot);
EQLIB_API bool LoH_HT_Ready();

/* MQ2DATAVARS */
#ifndef ISXEQ
LEGACY_API PCHAR GetFuncParam(PCHAR szMacroLine, DWORD ParamNum, PCHAR szParamName, size_t ParamNameLen, PCHAR szParamType, size_t ParamTypeLen);
//LEGACY_API PCHAR GetFuncParam(PCHAR szMacroLine, DWORD ParamNum, PCHAR szParamName, PCHAR szParamType);
LEGACY_API PDATAVAR FindMQ2DataVariable(PCHAR Name);
LEGACY_API BOOL AddMQ2DataVariable(PCHAR Name, PCHAR Index, MQ2Type *pType, PDATAVAR *ppHead, PCHAR Default);
LEGACY_API BOOL AddMQ2DataVariableFromData(PCHAR Name, PCHAR Index, MQ2Type *pType, PDATAVAR *ppHead, MQ2TYPEVAR Default);
LEGACY_API PDATAVAR *FindVariableScope(PCHAR Name);
LEGACY_API BOOL DeleteMQ2DataVariable(PCHAR Name);
LEGACY_API VOID ClearMQ2DataVariables(PDATAVAR *ppHead);
LEGACY_API VOID NewDeclareVar(PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID NewDeleteVarCmd(PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID NewVarset(PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID NewVarcalc(PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID NewVardata(PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID DropTimers(VOID);
#endif

/*                 */

LEGACY_API BOOL LoadCfgFile(PCHAR Filename, BOOL Delayed = FromPlugin);
//EQLIB_API PCHAR GetFriendlyNameForGroundItem(PGROUNDITEM pItem, PCHAR szName);
EQLIB_API VOID ClearSearchSpawn(PSEARCHSPAWN pSearchSpawn);
EQLIB_API PSPAWNINFO NthNearestSpawn(PSEARCHSPAWN pSearchSpawn, DWORD Nth, PSPAWNINFO pOrigin, BOOL IncludeOrigin = FALSE);
EQLIB_API DWORD CountMatchingSpawns(PSEARCHSPAWN pSearchSpawn, PSPAWNINFO pOrigin, BOOL IncludeOrigin = FALSE);
EQLIB_API PSPAWNINFO SearchThroughSpawns(PSEARCHSPAWN pSearchSpawn, PSPAWNINFO pChar);
EQLIB_API BOOL SpawnMatchesSearch(PSEARCHSPAWN pSearchSpawn, PSPAWNINFO pChar, PSPAWNINFO pSpawn);
EQLIB_API BOOL SearchSpawnMatchesSearchSpawn(PSEARCHSPAWN pSearchSpawn1, PSEARCHSPAWN pSearchSpawn2);
LEGACY_API PCHAR ParseSearchSpawnArgs(PCHAR szArg, PCHAR szRest, PSEARCHSPAWN pSearchSpawn);
#ifndef ISXEQ
LEGACY_API VOID ParseSearchSpawn(PCHAR Buffer, PSEARCHSPAWN pSearchSpawn);
#else
LEGACY_API VOID ParseSearchSpawn(int BeginInclusive, int EndExclusive, char *argv[], SEARCHSPAWN &SearchSpawn);
#endif
EQLIB_API PCHAR FormatSearchSpawn(PCHAR Buffer, SIZE_T BufferSize, PSEARCHSPAWN pSearchSpawn);
EQLIB_API BOOL IsPCNear(PSPAWNINFO pSpawn, FLOAT Radius);
EQLIB_API BOOL IsInGroup(PSPAWNINFO pSpawn, BOOL bCorpse = 0);
EQLIB_API BOOL IsInFellowship(PSPAWNINFO pSpawn, BOOL bCorpse = 0);
EQLIB_API BOOL IsInRaid(PSPAWNINFO pSpawn, BOOL bCorpse = 0);
EQLIB_API BOOL IsAlert(PSPAWNINFO pChar, PSPAWNINFO pSpawn, DWORD List);
EQLIB_API BOOL GetClosestAlert(PSPAWNINFO pSpawn, DWORD List);
EQLIB_API BOOL IsAlert(PSPAWNINFO pChar, PSPAWNINFO pSpawn, DWORD List);
EQLIB_API BOOL CheckAlertForRecursion(PSEARCHSPAWN pSearchSpawn, DWORD List);
EQLIB_API VOID WriteFilterNames(VOID);
EQLIB_API VOID SetDisplaySWhoFilter(PBOOL bToggle, PCHAR szFilter, PCHAR szToggle);
EQLIB_API PCHAR GetModel(PSPAWNINFO pSpawn, DWORD Slot);
EQLIB_API VOID RewriteSubstitutions(VOID);
EQLIB_API VOID RewriteAliases(VOID);
EQLIB_API VOID WriteAliasToIni(char*Name, char*Command);
EQLIB_API DWORD FindSpellListByName(PCHAR szName);
EQLIB_API FLOAT StateHeightMultiplier(DWORD StandState);
EQLIB_API DWORD WINAPI thrMsgBox(LPVOID lpParameter);
extern VOID SuperWhoDisplay(PSPAWNINFO pChar, PSEARCHSPAWN pSearchSpawn, DWORD Color);
extern VOID SuperWhoDisplay(PSPAWNINFO pSpawn, DWORD Color);
LEGACY_API bool pWHOSORTCompare(const PSPAWNINFO A, const PSPAWNINFO B);

EQLIB_API VOID        OverwriteTable(DWORD Address);
#ifndef ISXEQ
LEGACY_API DWORD      Include(PCHAR szFile, int *LineNumber);
#endif
EQLIB_API PCHAR       GetFullZone(DWORD ZoneID);
EQLIB_API DWORD       GetZoneID(PCHAR ZoneShortName);
EQLIB_API PCHAR       GetShortZone(DWORD ZoneID);
//EQLIB_API VOID        SwapSWho                (PSWHOSORT pSWho1, PSWHOSORT pSWho2);
//EQLIB_API VOID        SortSWho                (PSWHOSORT pSWhoSort, DWORD SpawnCount, DWORD SortBy = 0);
//EQLIB_API VOID        SuperWhoFindPets        (PSPAWNINFO pChar, WORD SpawnID);
//EQLIB_API VOID        SuperWhoDisplay         (PSPAWNINFO pChar, PSEARCHSPAWN pFilter, PSPAWNINFO psTarget, WORD Padding = 0, DWORD Color = 0);
EQLIB_API FLOAT       DistanceToSpawn3D(PSPAWNINFO pChar, PSPAWNINFO pSpawn);
EQLIB_API FLOAT       EstimatedDistanceToSpawn(PSPAWNINFO pChar, PSPAWNINFO pSpawn);
EQLIB_API DWORD WINAPI InsertCommands(LPVOID lpParameter);
EQLIB_API VOID        UpdateMonitoredSpawns(VOID);
EQLIB_API PCHAR       GetModel(PSPAWNINFO pSpawn, DWORD Slot);
//EQLIB_API PSPAWNINFO  GetPet                  (DWORD OwnerID);
//EQLIB_API BOOL        IfCompare               (PCHAR szCond);
EQLIB_API bool        PlayerHasAAAbility(DWORD AAIndex);
EQLIB_API PCHAR       GetAANameByIndex(DWORD AAIndex);
EQLIB_API DWORD       GetAAIndexByName(PCHAR AAName);
EQLIB_API DWORD       GetAAIndexByID(DWORD ID);
EQLIB_API DWORD       GetSkillIDFromName(PCHAR name);
EQLIB_API bool        InHoverState();
EQLIB_API DWORD       GetGameState(VOID);
EQLIB_API DWORD       GetWorldState(VOID);
EQLIB_API float       GetMeleeRange(class EQPlayer *, class EQPlayer *);
EQLIB_API DWORD       GetSpellGemTimer(DWORD nGem);
EQLIB_API DWORD       GetSpellBuffTimer(DWORD SpellID);
EQLIB_API bool        HasExpansion(DWORD nExpansion);
EQLIB_API VOID		  ListMercAltAbilities();
EQLIB_API PCONTENTS	  FindItemBySlot(short InvSlot, short BagSlot = -1, ItemContainerInstance location = eItemContainerPossessions);
EQLIB_API PCONTENTS	  FindItemByName(PCHAR pName, BOOL bExact = false);
EQLIB_API PCONTENTS	  FindItemByID(int ItemID);
EQLIB_API DWORD	      FindItemCountByName(PCHAR pName, BOOL bExact = false);
EQLIB_API DWORD	      FindItemCountByID(int ItemID);
EQLIB_API PCONTENTS   FindBankItemByName(char *pName, BOOL bExact);
EQLIB_API PCONTENTS   FindBankItemByID(int ItemID);
EQLIB_API DWORD       FindBankItemCountByName(char *pName, BOOL bExact);
EQLIB_API DWORD       FindBankItemCountByID(int ItemID);
EQLIB_API PEQINVSLOT  GetInvSlot(DWORD type, short Invslot, short Bagslot = -1);
EQLIB_API BOOL		  IsItemInsideContainer(PCONTENTS pItem);
EQLIB_API BOOL		  PickupItem(ItemContainerInstance type, PCONTENTS pItem);
EQLIB_API BOOL		  DropItem(ItemContainerInstance type, short InvSlot, short Bagslot);
EQLIB_API bool		  ItemOnCursor();
EQLIB_API BOOL		  OpenContainer(PCONTENTS pItem, bool hidden, bool flag = 0);
EQLIB_API BOOL		  CloseContainer(PCONTENTS pItem);
EQLIB_API int		  GetTargetBuffByCategory(DWORD category, DWORD classmask = 0, int startslot = 0);
EQLIB_API int		  GetTargetBuffBySubCat(PCHAR subcat, DWORD classmask = 0, int startslot = 0);
EQLIB_API int		  GetTargetBuffBySPA(int spa, bool bIncrease, int startslot = 0);
EQLIB_API int		  GetSelfBuffByCategory(DWORD category, DWORD classmask = 0, int startslot = 0);
EQLIB_API int		  GetSelfBuffBySubCat(PCHAR subcat, DWORD classmask = 0, int startslot = 0);
EQLIB_API int		  GetSelfBuffBySPA(int spa, bool bIncrease, int startslot = 0);
EQLIB_API int		  GetSelfShortBuffBySPA(int spa, bool bIncrease, int startslot = 0);
EQLIB_API bool        IsSpellUsableForClass(PSPELL pSpell, DWORD classmask = 0);
EQLIB_API bool        IsAegoSpell(PSPELL pSpell);
EQLIB_API int         GetSpellCategory(PSPELL pSpell);
EQLIB_API int         GetSpellSubcategory(PSPELL pSpell);
EQLIB_API void		  PopulateSpellMap();
EQLIB_API PSPELL      GetSpellParent(int id);
EQLIB_API DWORD __stdcall InitializeMQ2SpellDb(PVOID pData);
EQLIB_API HMODULE GetCurrentModule();
EQLIB_API DWORD WINAPI MQ2End(LPVOID lpParameter);
EQLIB_API DWORD WINAPI GetlocalPlayerOffset();
EQLIB_API void __cdecl MQ2Shutdown();
EQLIB_API HANDLE hUnloadComplete;
EQLIB_API HANDLE hLoadComplete;
///////////////////////////////////////////////////////////////////////////////////////////////////
// Functions that were built into commands and people used DoCommand to execute                  //

EQLIB_API void AttackRanged(EQPlayer *pRangedTarget = pTarget);
EQLIB_API VOID UseAbility(char *sAbility);
EQLIB_API PMACROBLOCK GetNextMacroBlock();
EQLIB_API PMACROBLOCK GetCurrentMacroBlock();
EQLIB_API int GetmacroBlockCount();
EQLIB_API void EndAllMacros();
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////


LEGACY_API BOOL Calculate(PCHAR szFormula, DOUBLE& Dest);


#ifndef ISXEQ
#include "MQ2TopLevelObjects.h"
#include "MQ2Commands.h"
#else
#include "ISXEQ\ISXEQUtilities.h"
#include "ISXEQ\ISXEQCommands.h"
#define TOPLEVELOBJECT(name,funcname) extern bool funcname(int argc, char *argv[], LSTYPEVAR &Ret);
#include "ISXEQ\ISXEQTopLevelObjects.h"
#undef TOPLEVELOBJECT
#endif
// OTHER SHIT

#define LIGHT_COUNT			13
//#define MAX_COMBINES		61
//#define MAX_ITEMTYPES		71
//#define MAX_SPELLEFFECTS	487

#define GAMESTATE_CHARSELECT    1
#define GAMESTATE_CHARCREATE    2
#define GAMESTATE_SOMETHING     4
#define GAMESTATE_INGAME        5
#define GAMESTATE_PRECHARSELECT -1
#define GAMESTATE_POSTFRONTLOAD 500
#define GAMESTATE_LOGGINGIN     253
#define GAMESTATE_UNLOADING     255

#define XWM_LCLICK              1
#define XWM_LMOUSEUP            2
#define XWM_RCLICK              3
#define XWM_LDBLCLICK           4
#define XWM_HITENTER            6
#define XWM_CLOSE               10
#define XWN_TOOLTIP             12
#define XWM_NEWVALUE            14
#define XWM_COLUMNCLICK         15
#define XWM_SORTREQUEST         16
#define XWM_IS_LINK_ACTIVE      19
#define XWM_MENUSELECT          20
#define XWM_MOUSEOVER           21
#define XWM_HISTORY             22
#define XWM_LCLICKHOLD          23
#define XWM_LINK                27
#define XWM_ACHIEVEMENTLINK     31
//not sure what 32 is now, they inserted a new message smack in the middle instead of adding it to the end
//i think its achievement related. -eqmule
#if !defined(ROF2EMU) && !defined(UFEMU)
#define XWN_DIALOGRESPONSELINK  33
#define XWM_FOCUS               34
#define XWM_LOSTFOCUS           35
#define XWM_TEXTENTRY_COMPLETE  41
#define XWM_RSELITEM_DOWN       47
#define XWN_OUTPUT_TEXT         49
#define XWN_COMMANDLINK         50
//ok so here we have 2 new messages 51 and 52 see https://forums.daybreakgames.com/eq/index.php?threads/game-update-notes-july-19-2017.242705/
//I think they where added in that patch
//they are dynamiczone/raid related or something
//need to investigate further to know for sure -eqmule
#else
#define XWN_DIALOGRESPONSELINK  32
#define XWM_FOCUS               33
#define XWM_LOSTFOCUS           34
#define XWM_TEXTENTRY_COMPLETE  40
#define XWM_RSELITEM_DOWN       46
#define XWN_OUTPUT_TEXT         48
#define XWN_COMMANDLINK         49
#endif

#define XKF_SHIFT               1
#define XKF_CTRL                2
#define XKF_LALT                4
#define XKF_RALT                8

#define CHATMENU_NEW			42
#define CHATMENU_ALWAYS_CHAT_HERE	43
#define CHATMENU_RENAME			44
#define CHATMENU_SCROLLBAR		45

// DO NOT CHANGE these user message id's.
// They must be identical between MQ2 and the
// injector process (macroquest2.exe).
//#define WM_USER_REGISTER_HK		(WM_USER + 1000)
//#define WM_USER_UNREGISTER_HK	(WM_USER + 1001)
//#define WM_USER_RESETLOADED		(WM_USER + 1002)
//#define WM_USER_SETLOADED		(WM_USER + 1003)

EQLIB_API VOID memchecks_tramp(PCHAR, DWORD, PVOID, DWORD, BOOL);
EQLIB_API VOID memchecks(PCHAR, DWORD, PVOID, DWORD, BOOL);
EQLIB_API void InitializeLoginPulse();
EQLIB_API void RemoveAutoBankMenu();
EQLIB_API bool WillFitInBank(PCONTENTS pContent);
EQLIB_API bool WillFitInInventory(PCONTENTS pContent);
EQLIB_API void AddAutoBankMenu();
EQLIB_API void AutoBankPulse();
EQLIB_API void DoCommandf(PCHAR szFormat, ...);
EQLIB_API int MQ2ExceptionFilter(unsigned int code, struct _EXCEPTION_POINTERS* ex, const char * description, ...);
inline PCHAR ISXEQArgToMQ2Arg(int argc, char *argv[], char *szTemp, size_t size)
{
	for (int qq = 1; qq < argc; qq++) {
		strcat_s(szTemp, size, argv[qq]);
		strcat_s(szTemp, size, " ");
	}
	size_t len = strlen(szTemp);
	if (len && szTemp[len - 1] == ' ')
		szTemp[len - 1] = '\0';
	return &szTemp[0];
}
#define LODWORD(_qw)    ((DWORD)(_qw))
#define HIDWORD(_qw)    ((DWORD)(((_qw) >> 32) & 0xffffffff))
#pragma pack(pop)
