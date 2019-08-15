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

#pragma once

#if !defined(NOMINMAX)
#define NOMINMAX
#endif
#if !defined(WIN32_LEAN_AND_MEAN)
#define WIN32_LEAN_AND_MEAN
#endif

// targeting Windows 7+
#if defined(_WIN32_WINNT)
#undef _WIN32_WINNT
#endif
#define  _WIN32_WINNT          0x0601
#if defined(WINVER)
#undef WINVER
#endif
#define WINVER                 0x0601

#define DIRECTINPUT_VERSION    0x800

//warning C4530 : C++ exception handler used, but unwind semantics are not enabled.Specify / EHsc
#pragma warning(disable:4530)

// disable the noexcept warning there isnt really anything we can do about it as far as i know or is there? let me know if u know how to fix it - eqmule
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

//#define MQ2_PROFILING

// uncomment this line to turn off the single-line benchmark macro
// #define DISABLE_BENCHMARKS

// Probably needs a Config.h
//#define KNIGHTLYPARSE

#define VersionString          __ExpectedVersionDate
#define TimeString             __ExpectedVersionTime
#define DebugHeader            "[MQ2]"
#define LoadedString           "MQ2 Loaded."
#define ToUnloadString         "MQ2 Unloading..."
#define UnloadedString         "MQ2 Unloaded."


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

//
// EQ Version selection
//

#if defined(LIVE) || defined(TEST) || defined(EQBETA) || defined(ROF2EMU) || defined(UFEMU)
// If one of these macros was manually specified, respect it
#else

// the currently active configuration. Can be one of LIVE or TEST. To build LIVE, eqgame.h
// and other headers must be provided or it will build TEST instead
#define TEST

// Validate that LIVE is available to build
#if defined(LIVE) && !__has_include("live/eq.h")
#undef LIVE
#define TEST
#endif
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
EQLIB_API void *MQ2Malloc(size_t size);
EQLIB_API void MQ2Free(void *memblock);
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

#include "EQLib/EQLib.h"

#include "MQ2Prototypes.h"
#include "MQ2Internal.h"
#include "MQ2Globals.h"

/* BENCHMARKING */
#ifdef DISABLE_BENCHMARKS
#define Benchmark(BMHandle,code) code
#else
#define Benchmark(BMHandle,code) {EnterMQ2Benchmark(BMHandle);code;ExitMQ2Benchmark(BMHandle);}
#endif
EQLIB_API void ShutdownMQ2Benchmarks();
EQLIB_API void InitializeMQ2Benchmarks();
EQLIB_API BOOL GetMQ2Benchmark(DWORD BMHandle, MQBENCH &Dest);
EQLIB_API void ExitMQ2Benchmark(DWORD BMHandle);
EQLIB_API void EnterMQ2Benchmark(DWORD BMHandle);
EQLIB_API void RemoveMQ2Benchmark(DWORD BMHandle);
EQLIB_API DWORD AddMQ2Benchmark(PCHAR Name);

/* SPAWN HANDLING */
EQLIB_API void InitializeMQ2Spawns();
EQLIB_API void ShutdownMQ2Spawns();
EQLIB_API void ProcessPendingGroundItems();
EQLIB_API void UpdateMQ2SpawnSort();
EQLIB_API BOOL SetNameSpriteState(SPAWNINFO* pSpawn, bool Show);
EQLIB_API BOOL IsTargetable(PSPAWNINFO pSpawn);

/* WINDOWS */
EQLIB_API BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);
EQLIB_API void InitializeMQ2Windows();
EQLIB_API void ShutdownMQ2Windows();
EQLIB_API void RemoveXMLFile(const char* filename);
EQLIB_API void AddXMLFile(const char* filename);
EQLIB_API bool IsXMLFilePresent(const char* filename);
EQLIB_API bool SendWndClick(const char* WindowName, const char* ScreenID, const char* ClickNotification);
EQLIB_API bool SendWndNotification(const char* WindowName, const char* ScreenID, int Notification, void* Data = 0);
EQLIB_API void AddWindow(char *WindowName, CXWnd **ppWindow);
EQLIB_API void RemoveWindow(char* WindowName);
EQLIB_API CXWnd* FindMQ2Window(const char* Name);
EQLIB_API CXWnd* GetParentWnd(CXWnd* pWnd);

EQLIB_API bool SendComboSelect(const char* WindowName, const char* ScreenID, int Value);
EQLIB_API bool SendListSelect(const char* WindowName, const char* ScreenID, int Value);
EQLIB_API bool SendListSelect2(CXWnd* pList, int ListIndex);
EQLIB_API bool SendWndClick2(CXWnd* pWnd, const char* ClickNotification);

EQLIB_API void CreateMQ2NewsWindow();
EQLIB_API void DeleteMQ2NewsWindow();

/* CHAT HOOK */
EQLIB_API void InitializeChatHook();
EQLIB_API void ShutdownChatHook();
#if !defined(ROF2EMU) && !defined(UFEMU)
EQLIB_API void dsp_chat_no_events(const char *Text, int Color, bool EqLog = true, bool dopercentsubst = true, char *SomeStr = NULL);
#else
EQLIB_API void dsp_chat_no_events(const char *Text, int Color, bool EqLog = true, bool dopercentsubst = true);
#endif

/* DETOURING API */
EQLIB_API void InitializeMQ2Detours();
EQLIB_API void ShutdownMQ2Detours();

#ifndef ISXEQ
#ifdef ISXEQ_LEGACY
#define RemoveDetour(address)
#define AddDetour __noop
#define AddDetourf __noop
#else
EQLIB_API BOOL AddDetour(DWORD address, PBYTE pfDetour = 0, PBYTE pfTrampoline = 0, DWORD Count = 20, PCHAR Name = 0);
EQLIB_API void AddDetourf(DWORD address, ...);
EQLIB_API void RemoveDetour(DWORD address);
EQLIB_API void DeleteDetour(DWORD address);
#endif
#else
#define RemoveDetour EzUnDetour
#endif

/* PLUGIN HANDLING */
EQLIB_API void WriteChatf(PCHAR Format, ...);
EQLIB_API void WriteChatfSafe(PCHAR szFormat, ...);
EQLIB_API void WriteChatColor(PCHAR Line, DWORD Color = USERCOLOR_DEFAULT, DWORD Filter = 0);
#ifndef ISXEQ
EQLIB_API void InitializeMQ2Plugins();
EQLIB_API DWORD LoadMQ2Plugin(const PCHAR pszFilename, BOOL bCustom = 0);
EQLIB_API BOOL UnloadMQ2Plugin(const PCHAR pszFilename);
EQLIB_API void UnloadMQ2Plugins();
EQLIB_API void ShutdownMQ2Plugins();
EQLIB_API void SaveMQ2PluginLoadStatus(char*Name, bool bLoad);
#endif
EQLIB_API void PulsePlugins();
EQLIB_API void PluginsZoned();
EQLIB_API BOOL PluginsIncomingChat(PCHAR Line, DWORD Color);
EQLIB_API void PluginsCleanUI();
EQLIB_API void PluginsReloadUI();
EQLIB_API void PluginsSetGameState(DWORD GameState);
EQLIB_API void PluginsDrawHUD();
EQLIB_API void PluginsAddSpawn(PSPAWNINFO pNewSpawn);
EQLIB_API void PluginsRemoveSpawn(PSPAWNINFO pSpawn);
EQLIB_API void PluginsAddGroundItem(PGROUNDITEM pNewGroundItem);
EQLIB_API void PluginsRemoveGroundItem(PGROUNDITEM pGroundItem);
EQLIB_API void PluginsBeginZone(void);
EQLIB_API void PluginsEndZone(void);

/* DIRECT INPUT */
#ifndef ISXEQ
EQLIB_API void InitializeMQ2DInput();
EQLIB_API void ShutdownMQ2DInput();
#endif

/* CLEAN UI */
EQLIB_API void InitializeDisplayHook();
EQLIB_API void ShutdownDisplayHook();
EQLIB_API void DrawHUD();

/* COMMAND HANDLING */
LEGACY_API void InitializeMQ2Commands();
LEGACY_API void ShutdownMQ2Commands();
LEGACY_API void AddCommand(PCHAR Command, fEQCommand Function, BOOL EQ = 0, BOOL Parse = 1, BOOL InGame = 0);
LEGACY_API void AddAlias(PCHAR ShortCommand, PCHAR LongCommand);
LEGACY_API BOOL RemoveAlias(PCHAR ShortCommand);
LEGACY_API void AddSubstitute(PCHAR Original, PCHAR Substitution);
LEGACY_API BOOL RemoveSubstitute(PCHAR Original);
LEGACY_API BOOL RemoveCommand(PCHAR Command);
LEGACY_API void DoTimedCommands();
LEGACY_API void TimedCommand(PCHAR Command, DWORD msDelay);

/* MACRO COMMANDS */
LEGACY_API void DumpStack(PSPAWNINFO, PCHAR);
LEGACY_API void EndMacro(PSPAWNINFO, PCHAR);
LEGACY_API void Echo(PSPAWNINFO, PCHAR);

/* MACRO PARSING */
#ifdef USEBLECHEVENTS
void __stdcall EventBlechCallback(unsigned int ID, void * pData, PBLECHVALUE pValues);
#endif
#define PMP_ERROR_BADPARM 10000
LEGACY_API PCHAR ParseMacroParameter(PSPAWNINFO pChar, PCHAR szOriginal, SIZE_T BufferSize);

template <unsigned int _Size>
inline PCHAR ParseMacroParameter(PSPAWNINFO pChar, CHAR(&szOriginal)[_Size])
{
	return ParseMacroParameter(pChar, szOriginal, _Size);
}

#ifndef ISXEQ
LEGACY_API void FailIf(PSPAWNINFO pChar, PCHAR szCommand, int pStartLine, BOOL All = FALSE);
LEGACY_API void InitializeParser();
LEGACY_API void ShutdownParser();

LEGACY_API void InitializeMQ2DataTypes();
LEGACY_API void ShutdownMQ2DataTypes();
LEGACY_API void InitializeMQ2Data();
LEGACY_API void ShutdownMQ2Data();
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
EQLIB_API BOOL IsMouseWaiting(void);
EQLIB_API BOOL IsMouseWaitingForButton();
EQLIB_API void MQ2MouseHooks(BOOL bFlag);
EQLIB_API bool MoveMouse(int x, int y, bool bClick = false);
EQLIB_API bool MouseToPlayer(PlayerClient* pPlayer, DWORD position, BOOL bClick = 0);

/* KEY BINDS */
EQLIB_API void InitializeMQ2KeyBinds();
EQLIB_API void ShutdownMQ2KeyBinds();
EQLIB_API BOOL PressMQ2KeyBind(PCHAR name, BOOL Hold);
EQLIB_API BOOL SetMQ2KeyBind(PCHAR name, BOOL Alternate, KeyCombo &Combo);
EQLIB_API BOOL AddMQ2KeyBind(PCHAR name, fMQExecuteCmd Function);
EQLIB_API BOOL RemoveMQ2KeyBind(PCHAR name);
EQLIB_API BOOL GetMQ2KeyBind(PCHAR name, BOOL Alt, KeyCombo &Combo);
EQLIB_API BOOL DumpBinds(PCHAR Filename);
EQLIB_API BOOL MQ2HandleKeyDown(class KeyCombo const &Combo);
EQLIB_API BOOL MQ2HandleKeyUp(class KeyCombo const &Combo);

/* PULSING */
EQLIB_API void InitializeMQ2Pulse();
EQLIB_API void ShutdownMQ2Pulse();

/* OTHER IMPORTED FROM EQ */
EQLIB_API int CastRay(PSPAWNINFO, float y, float x, float z);
EQLIB_API int CastRayLoc(const CVector3& SourcePos, int Race, float DestX, float DestY, float DestZ);
EQLIB_OBJECT CXStr CleanItemTags(const CXStr& In, bool bFlag);
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
EQLIB_API void ConvertCR(PCHAR Text, size_t LineLen);
EQLIB_API void DrawHUDText(const char* Text, int X, int Y, unsigned int Argb, int Font);
EQLIB_API void FixStringTable();
EQLIB_API void DebugSpew(PCHAR szFormat, ...);
EQLIB_API void DebugSpewAlways(PCHAR szFormat, ...);
EQLIB_API void DebugSpewAlwaysFile(PCHAR szFormat, ...);
EQLIB_API void DebugSpewNoFile(PCHAR szFormat, ...);
//#ifndef ISXEQ
LEGACY_API PSTR GetNextArg(PCSTR szLine, DWORD dwNumber = 1, BOOL CSV = FALSE, CHAR Separator = 0);
LEGACY_API PSTR GetArg(PSTR szDest, PCSTR szSrc, DWORD dwNumber, BOOL LeaveQuotes = FALSE, BOOL ToParen = FALSE, BOOL CSV = FALSE, CHAR Separator = 0, BOOL AnyNonAlphaNum = FALSE);
//#endif
LEGACY_API void AddCustomEvent(PEVENTLIST pEList, PCHAR szLine);
EQLIB_API FLOAT DistanceToSpawn(PSPAWNINFO pChar, PSPAWNINFO pSpawn);
EQLIB_API PCHAR GetEQPath(PCHAR szBuffer, size_t len);

#define DoCommand(pspawninfo,commandtoexecute) HideDoCommand(pspawninfo,commandtoexecute,FromPlugin)
LEGACY_API void HideDoCommand(PSPAWNINFO pChar, PCHAR szLine, BOOL delayed);
#define EzCommand(commandtoexecute) DoCommand((PSPAWNINFO)pLocalPlayer,commandtoexecute)

EQLIB_API DWORD MQToSTML(PCHAR in, PCHAR out, DWORD maxlen = MAX_STRING, DWORD ColorOverride = 0xFFFFFF);
EQLIB_API void StripMQChat(PCHAR in, PCHAR out);
EQLIB_API void STMLToPlainText(PCHAR in, PCHAR out);
EQLIB_API PCHAR GetSubFromLine(int Line, PCHAR szSub, size_t Sublen);
EQLIB_API PCHAR GetFilenameFromFullPath(PCHAR Filename);
EQLIB_API BOOL CompareTimes(PCHAR RealTime, PCHAR ExpectedTime);
EQLIB_API void AddFilter(PCHAR szFilter, DWORD Length, PBOOL pEnabled);
EQLIB_API void DefaultFilters(void);
EQLIB_API PCHAR ConvertHotkeyNameToKeyName(char* szName);
LEGACY_API void CheckChatForEvent(PCHAR szMsg);
EQLIB_API void ConvertItemTags(CXStr &cxstr, BOOL Tag = TRUE);
EQLIB_API BOOL ParseKeyCombo(PCHAR text, KeyCombo &Dest);
EQLIB_API PCHAR DescribeKeyCombo(KeyCombo &Combo, PCHAR szDest, SIZE_T BufferSize);
EQLIB_API int FindInvSlotForContents(CONTENTS* pContents);
EQLIB_API int FindInvSlot(PCHAR Name, BOOL Exact);
EQLIB_API int FindNextInvSlot(PCHAR Name, BOOL Exact);
EQLIB_API int FindMappableCommand(const char *name);

EQLIB_API int GetLanguageIDByName(PCHAR szName);
EQLIB_API int GetCurrencyIDByName(PCHAR szName);
EQLIB_API PCHAR GetSpellNameByID(LONG dwSpellID);
EQLIB_API SPELL* GetSpellByName(const char* szName);
EQLIB_API PSPELL GetSpellByAAName(PCHAR szName);
EQLIB_API PSPELL GetSpellByAAName(PCHAR szName);
EQLIB_API PALTABILITY GetAAByIdWrapper(int nAbilityId, int playerLevel = -1);
EQLIB_API int GetSpellRankByName(const char* SpellName);
EQLIB_API void TruncateSpellRankName(char* SpellName);
EQLIB_API void RemoveBuff(SPAWNINFO* pChar, char* szLine);
EQLIB_API void RemovePetBuff(SPAWNINFO* pChar, char* szLine);
EQLIB_API bool StripQuotes(char* str);
EQLIB_API void MakeMeVisible(SPAWNINFO* pChar, char* szLine);
EQLIB_API void RemoveAura(SPAWNINFO* pChar, char* szLine);
EQLIB_API bool GetAllMercDesc(std::map<int, MercDesc>& minfo);

DWORD GetKeyRingIndex(DWORD KeyRing, PCHAR szItemName, SIZE_T BuffLen, bool bExact = true, bool usecmd = false);
EQLIB_API int GetMountCount();
EQLIB_API int GetIllusionCount();
EQLIB_API int GetFamiliarCount();
EQLIB_API void RefreshKeyRings(void* kr);
EQLIB_API void InitKeyRings();
EQLIB_API BOOL IsActiveAA(PCHAR pSpellName);
EQLIB_API CXWnd* GetAdvLootPersonalListItem(DWORD ListIndex/*YES ITS THE INTERNAL INDEX*/, DWORD type);
EQLIB_API CXWnd* GetAdvLootSharedListItem(DWORD ListIndex/*YES IT REALLY IS THE LISTINDEX*/, DWORD type);
EQLIB_API bool LootInProgress(CAdvancedLootWnd* pAdvLoot, CListWnd* pPersonalList, CListWnd* pSharedList);
EQLIB_API void WeDidStuff();
EQLIB_API int GetFreeInventory(int nSize);
EQLIB_API int RangeRandom(int min, int max);
EQLIB_API DWORD __stdcall BeepOnTellThread(void* pData);
EQLIB_API DWORD __stdcall FlashOnTellThread(void* pData);
EQLIB_API CMQ2Alerts CAlerts;
EQLIB_VAR BOOL bPluginCS;

struct RefreshKeyRingsThreadData
{
	CHAR ItemName[256];
	CSidlScreenWnd *phWnd;
	bool bExact;
	bool bUseCmd;
};

EQLIB_API ITEMINFO *GetItemFromContents(CONTENTS* c);

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
EQLIB_API unsigned int GetSpellDuration(SPELL* pSpell, SPAWNINFO* pSpawn);
EQLIB_API DWORD GetDeityTeamByID(DWORD DeityID);
EQLIB_API DWORD ConColor(PSPAWNINFO pSpawn);

EQLIB_API PCHAR GetGuildByID(int64_t GuildID);
EQLIB_API int64_t GetGuildIDByName(PCHAR szGuild);

extern std::map<int, std::string>targetBuffSlotToCasterMap;
extern std::map<int, std::map<int,cTargetBuff>>CachedBuffsMap;
EQLIB_API CONTENTS* GetEnviroContainer();
EQLIB_API CContainerWnd* FindContainerForContents(CONTENTS* pContents);
EQLIB_API float FindSpeed(SPAWNINFO* pSpawn);
EQLIB_API BOOL IsNamed(PSPAWNINFO pSpawn);
EQLIB_API void GetItemLinkHash(CONTENTS* Item, PCHAR Buffer, SIZE_T BufferSize);

template <unsigned int _Size>
inline void GetItemLinkHash(CONTENTS* Item, CHAR(&Buffer)[_Size])
{
	return GetItemLinkHash(Item, Buffer, _Size);
}

EQLIB_API bool GetItemLink(CONTENTS* Item, PCHAR Buffer, SIZE_T BufferSize, BOOL Clickable = TRUE);

template <unsigned int _Size>
inline bool GetItemLink(CONTENTS* Item, CHAR(&Buffer)[_Size], BOOL Clickable = TRUE)
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

EQLIB_API void SlotValueCalculate(PCHAR szBuff, PSPELL pSpell, int i, double mp = 1.0);
EQLIB_API LONG CalcValue(LONG calc, LONG base, LONG max, LONG tick, LONG minlevel = MAX_PC_LEVEL, LONG level = MAX_PC_LEVEL);
EQLIB_API PCHAR GetSpellEffectName(LONG EffectID, PCHAR szBuffer, SIZE_T BufferSize);
EQLIB_API void GetGameDate(int* Month, int* Day, int* Year);
EQLIB_API void GetGameTime(int* Hour, int* Minute, int* Night);
LEGACY_API void SyntaxError(PCHAR szFormat, ...);
LEGACY_API void MacroError(PCHAR szFormat, ...);
LEGACY_API void FatalError(PCHAR szFormat, ...);
EQLIB_API PCHAR GetSpellRestrictions(PSPELL pSpell, unsigned int nIndex, PCHAR szBuffer, SIZE_T BufferSize);
#ifndef ISXEQ
LEGACY_API void MQ2DataError(PCHAR szFormat, ...);
#endif
EQLIB_API void DisplayOverlayText(PCHAR szText, DWORD dwColor, DWORD dwTransparency, DWORD msFadeIn, DWORD msFadeOut, DWORD msHold);
EQLIB_API void CustomPopup(char* szPopText, bool bPopOutput);

EQLIB_API BOOL IsBardSong(PSPELL pSpell);
EQLIB_API BOOL IsSPAEffect(PSPELL pSpell, LONG EffectID);
EQLIB_API bool GetShortBuffID(SPELLBUFF* pBuff, DWORD& nID);
EQLIB_API bool GetBuffID(SPELLBUFF* pBuff, DWORD& nID);
EQLIB_API PCHAR GetLDoNTheme(DWORD LDTheme);
EQLIB_API BOOL TriggeringEffectSpell(PSPELL aSpell, int i);
EQLIB_API BOOL BuffStackTest(PSPELL aSpell, PSPELL bSpell, BOOL bIgnoreTriggeringEffects = FALSE, BOOL bTriggeredEffectCheck = FALSE);
EQLIB_API DWORD GetItemTimer(CONTENTS* pItem);
EQLIB_API CONTENTS* GetItemContentsBySlotID(DWORD dwSlotID);
EQLIB_API CONTENTS* GetItemContentsByName(const char* ItemName);
EQLIB_API DWORD GetAvailableSlots(CONTENTS* pContainer, CONTENTS* pItem, int *firstavailableslot);
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
LEGACY_API void ClearMQ2DataVariables(PDATAVAR *ppHead);
LEGACY_API void NewDeclareVar(PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API void NewDeleteVarCmd(PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API void NewVarset(PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API void NewVarcalc(PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API void NewVardata(PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API void DropTimers();
#endif

/*                 */

LEGACY_API BOOL LoadCfgFile(PCHAR Filename, BOOL Delayed = FromPlugin);
//EQLIB_API PCHAR GetFriendlyNameForGroundItem(PGROUNDITEM pItem, PCHAR szName);
EQLIB_API void ClearSearchSpawn(PSEARCHSPAWN pSearchSpawn);
EQLIB_API PSPAWNINFO NthNearestSpawn(PSEARCHSPAWN pSearchSpawn, DWORD Nth, PSPAWNINFO pOrigin, BOOL IncludeOrigin = FALSE);
EQLIB_API DWORD CountMatchingSpawns(PSEARCHSPAWN pSearchSpawn, PSPAWNINFO pOrigin, BOOL IncludeOrigin = FALSE);
EQLIB_API PSPAWNINFO SearchThroughSpawns(PSEARCHSPAWN pSearchSpawn, PSPAWNINFO pChar);
EQLIB_API BOOL SpawnMatchesSearch(PSEARCHSPAWN pSearchSpawn, PSPAWNINFO pChar, PSPAWNINFO pSpawn);
EQLIB_API BOOL SearchSpawnMatchesSearchSpawn(PSEARCHSPAWN pSearchSpawn1, PSEARCHSPAWN pSearchSpawn2);
LEGACY_API PCHAR ParseSearchSpawnArgs(PCHAR szArg, PCHAR szRest, PSEARCHSPAWN pSearchSpawn);
#ifndef ISXEQ
LEGACY_API void ParseSearchSpawn(PCHAR Buffer, PSEARCHSPAWN pSearchSpawn);
#else
LEGACY_API void ParseSearchSpawn(int BeginInclusive, int EndExclusive, char *argv[], SEARCHSPAWN &SearchSpawn);
#endif
EQLIB_API PCHAR FormatSearchSpawn(PCHAR Buffer, SIZE_T BufferSize, PSEARCHSPAWN pSearchSpawn);
EQLIB_API BOOL IsPCNear(PSPAWNINFO pSpawn, FLOAT Radius);
EQLIB_API bool IsInGroup(SPAWNINFO* pSpawn, bool bCorpse = false);
EQLIB_API BOOL IsInFellowship(PSPAWNINFO pSpawn, BOOL bCorpse = 0);
EQLIB_API BOOL IsInRaid(PSPAWNINFO pSpawn, BOOL bCorpse = 0);
EQLIB_API BOOL IsAlert(PSPAWNINFO pChar, PSPAWNINFO pSpawn, DWORD List);
EQLIB_API BOOL GetClosestAlert(PSPAWNINFO pSpawn, DWORD List);
EQLIB_API BOOL IsAlert(PSPAWNINFO pChar, PSPAWNINFO pSpawn, DWORD List);
EQLIB_API BOOL CheckAlertForRecursion(PSEARCHSPAWN pSearchSpawn, DWORD List);
EQLIB_API void WriteFilterNames();
EQLIB_API void SetDisplaySWhoFilter(PBOOL bToggle, PCHAR szFilter, PCHAR szToggle);
EQLIB_API PCHAR GetModel(PSPAWNINFO pSpawn, DWORD Slot);
EQLIB_API void RewriteSubstitutions(void);
EQLIB_API void RewriteAliases(void);
EQLIB_API void WriteAliasToIni(char*Name, char*Command);
EQLIB_API DWORD FindSpellListByName(PCHAR szName);
EQLIB_API FLOAT StateHeightMultiplier(DWORD StandState);
EQLIB_API DWORD WINAPI thrMsgBox(LPVOID lpParameter);
extern void SuperWhoDisplay(PSPAWNINFO pChar, PSEARCHSPAWN pSearchSpawn, DWORD Color);
extern void SuperWhoDisplay(PSPAWNINFO pSpawn, DWORD Color);
LEGACY_API bool pWHOSORTCompare(const PSPAWNINFO A, const PSPAWNINFO B);

EQLIB_API void        OverwriteTable(DWORD Address);
#ifndef ISXEQ
LEGACY_API DWORD      Include(PCHAR szFile, int *LineNumber);
#endif
EQLIB_API PCHAR       GetFullZone(DWORD ZoneID);
EQLIB_API DWORD       GetZoneID(PCHAR ZoneShortName);
EQLIB_API PCHAR       GetShortZone(DWORD ZoneID);
//EQLIB_API void        SwapSWho                (PSWHOSORT pSWho1, PSWHOSORT pSWho2);
//EQLIB_API void        SortSWho                (PSWHOSORT pSWhoSort, DWORD SpawnCount, DWORD SortBy = 0);
//EQLIB_API void        SuperWhoFindPets        (PSPAWNINFO pChar, WORD SpawnID);
//EQLIB_API void        SuperWhoDisplay         (PSPAWNINFO pChar, PSEARCHSPAWN pFilter, PSPAWNINFO psTarget, WORD Padding = 0, DWORD Color = 0);
EQLIB_API FLOAT       DistanceToSpawn3D(PSPAWNINFO pChar, PSPAWNINFO pSpawn);
EQLIB_API FLOAT       EstimatedDistanceToSpawn(PSPAWNINFO pChar, PSPAWNINFO pSpawn);
EQLIB_API DWORD WINAPI InsertCommands(LPVOID lpParameter);
EQLIB_API void        UpdateMonitoredSpawns(void);
EQLIB_API PCHAR       GetModel(PSPAWNINFO pSpawn, DWORD Slot);
//EQLIB_API PSPAWNINFO  GetPet                  (DWORD OwnerID);
//EQLIB_API BOOL        IfCompare               (PCHAR szCond);
EQLIB_API bool        PlayerHasAAAbility(DWORD AAIndex);
EQLIB_API PCHAR       GetAANameByIndex(DWORD AAIndex);
EQLIB_API DWORD       GetAAIndexByName(PCHAR AAName);
EQLIB_API DWORD       GetAAIndexByID(DWORD ID);
EQLIB_API DWORD       GetSkillIDFromName(PCHAR name);
EQLIB_API bool        InHoverState();
EQLIB_API DWORD       GetGameState(void);
EQLIB_API DWORD       GetWorldState(void);
EQLIB_API float       GetMeleeRange(PlayerClient*, PlayerClient*);
EQLIB_API DWORD       GetSpellGemTimer(DWORD nGem);
EQLIB_API DWORD       GetSpellBuffTimer(DWORD SpellID);
EQLIB_API bool        HasExpansion(DWORD nExpansion);
EQLIB_API void		  ListMercAltAbilities();
EQLIB_API CONTENTS*   FindItemBySlot(short InvSlot, short BagSlot = -1, ItemContainerInstance location = eItemContainerPossessions);
EQLIB_API CONTENTS*   FindItemBySlot2(const ItemGlobalIndex& idx);
EQLIB_API CONTENTS*   FindItemByName(PCHAR pName, BOOL bExact = false);
EQLIB_API CONTENTS*   FindItemByID(int ItemID);
EQLIB_API DWORD	      FindItemCountByName(PCHAR pName, BOOL bExact = false);
EQLIB_API DWORD	      FindItemCountByID(int ItemID);
EQLIB_API CONTENTS*   FindBankItemByName(char *pName, BOOL bExact);
EQLIB_API CONTENTS*   FindBankItemByID(int ItemID);
EQLIB_API DWORD       FindBankItemCountByName(char *pName, BOOL bExact);
EQLIB_API DWORD       FindBankItemCountByID(int ItemID);
EQLIB_API CInvSlot*   GetInvSlot(DWORD type, short Invslot, short Bagslot = -1);
EQLIB_API CInvSlot*   GetInvSlot2(const ItemGlobalIndex& idx);
EQLIB_API bool        IsItemInsideContainer(CONTENTS* pItem);
EQLIB_API bool        PickupItem(ItemContainerInstance type, CONTENTS* pItem);
EQLIB_API bool        DropItem(ItemContainerInstance type, short InvSlot, short Bagslot);
EQLIB_API bool        DropItem2(const ItemGlobalIndex& index);
EQLIB_API bool        ItemOnCursor();
EQLIB_API bool        OpenContainer(CONTENTS* pItem, bool hidden, bool flag = false);
EQLIB_API bool        CloseContainer(CONTENTS* pItem);
EQLIB_API int         GetTargetBuffByCategory(int category, unsigned int classmask = 0, int startslot = 0);
EQLIB_API int         GetTargetBuffBySubCat(const char* subcat, unsigned int classmask = 0, int startslot = 0);
EQLIB_API int         GetTargetBuffBySPA(int spa, bool bIncrease, int startslot = 0);
EQLIB_API bool        HasCachedTargetBuffSubCat(const char* subcat, SPAWNINFO* pSpawn, cTargetBuff* pcTargetBuff, unsigned int classmask = 0);
EQLIB_API bool        HasCachedTargetBuffSPA(int spa, bool bIncrease, SPAWNINFO* pSpawn, cTargetBuff* pcTargetBuff);
EQLIB_API int         GetSelfBuffByCategory(int category, unsigned int classmask = 0, int startslot = 0);
EQLIB_API int         GetSelfBuffBySubCat(const char* subcat, unsigned int classmask = 0, int startslot = 0);
EQLIB_API int         GetSelfBuffBySPA(int spa, bool bIncrease, int startslot = 0);
EQLIB_API int         GetSelfShortBuffBySPA(int spa, bool bIncrease, int startslot = 0);
EQLIB_API bool        IsSpellUsableForClass(SPELL* pSpell, unsigned int classmask = 0);
EQLIB_API bool        IsAegoSpell(SPELL* pSpell);
EQLIB_API int         GetSpellCategory(SPELL* pSpell);
EQLIB_API int         GetSpellSubcategory(SPELL* pSpell);
EQLIB_API void		  PopulateSpellMap();
EQLIB_API PSPELL      GetSpellParent(int id);
EQLIB_API DWORD __stdcall InitializeMQ2SpellDb(void* pData);
EQLIB_API HMODULE GetCurrentModule();
EQLIB_API DWORD WINAPI MQ2End(LPVOID lpParameter);
EQLIB_API DWORD WINAPI GetlocalPlayerOffset();
EQLIB_API void __cdecl MQ2Shutdown();
EQLIB_API HANDLE hUnloadComplete;
EQLIB_API HANDLE hLoadComplete;
///////////////////////////////////////////////////////////////////////////////////////////////////
// Functions that were built into commands and people used DoCommand to execute                  //

EQLIB_API void AttackRanged(PlayerClient* pRangedTarget = pTarget);
EQLIB_API void UseAbility(char *sAbility);
EQLIB_OBJECT PMACROBLOCK GetNextMacroBlock();
EQLIB_OBJECT PMACROBLOCK GetCurrentMacroBlock();
EQLIB_API int GetMacroBlockCount();
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

EQLIB_API void memchecks_tramp(PCHAR, DWORD, void*, DWORD, BOOL);
EQLIB_API void memchecks(PCHAR, DWORD, void*, DWORD, BOOL);
EQLIB_API void InitializeLoginPulse();
EQLIB_API void RemoveAutoBankMenu();
EQLIB_API bool WillFitInBank(CONTENTS* pContent);
EQLIB_API bool WillFitInInventory(CONTENTS* pContent);
EQLIB_API void AddAutoBankMenu();
EQLIB_API void AutoBankPulse();
EQLIB_API void DoCommandf(PCHAR szFormat, ...);
EQLIB_API KeypressHandler *GetKeyPresshandler();
EQLIB_API AggroMeterManagerClient *GetAggroInfo();
EQLIB_API ClientSOIManager *GetAuraMgr();
EQLIB_API CBroadcast *GetTextOverlay();
EQLIB_API MercenaryAlternateAdvancementManagerClient *GetMercAltAbilities();
EQLIB_API bool Anonymize(char* name, int maxlen, int LootFlag = 0);
EQLIB_API bool Anonymize2(CXStr& name, int LootFlag = 0);
EQLIB_API void UpdatedMasterLooterLabel();
//EQLIB_API EQGroundItemListManager *GetItemList();

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
