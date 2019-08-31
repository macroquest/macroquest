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
#include <string_view>
#include <algorithm>

// warning C4530 : C++ exception handler used, but unwind semantics are not enabled.Specify / EHsc
#pragma warning(disable:4530)

// disable the noexcept warning there isnt really anything we can do about it as far as i know or is there? let me know if u know how to fix it - eqmule
#pragma warning(disable:4577)

// Windows Header Files:
#include <windows.h>

#include "..\Dxsdk90\include\dinput.h"
#include "..\Detours\inc\detours.h"

// MQ2
#include "..\Blech\Blech.h"

//#define MQ2_PROFILING

// uncomment this line to turn off the single-line benchmark macro
// #define DISABLE_BENCHMARKS

#define VersionString          __ExpectedVersionDate
#define TimeString             __ExpectedVersionTime
#define DebugHeader            "[MQ2]"
#define LoadedString           "MQ2 Loaded."
#define ToUnloadString         "MQ2 Unloading..."
#define UnloadedString         "MQ2 Unloaded."

//
// EQ Version selection
//

// If this is a test branch, define TEST so that certain differences are enabled
//#define TEST
#define LIVE

#define KeyRingWindowParent "KeyRingWnd"
#define MountWindowList "KRW_Mounts_List"
#define IllusionWindowList "KRW_Illusions_List"
#define FamiliarWindowList "KRW_Familiars_list"
#define KeyRingTab "KRW_Subwindows"

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

#define EzDetour(offset, detour, trampoline) AddDetourf((DWORD)offset, detour, trampoline)
#define EzDetourwName(offset, detour, trampoline, name) AddDetourf((DWORD)offset, detour, trampoline, name)

#ifndef THIS_
#define THIS_                   INTERFACE FAR* This,
#endif

#ifdef DEBUG_TRY
#define DebugTry(x) DebugSpew("Trying %s",#x);x;DebugSpew("%s complete",#x)
#else
#define DebugTry(x) x
#endif

#define MAX_VARNAME           64
#define MAX_STRING            2048

#define IsNaN(x) (x != x)

#include "EQLib/EQLib.h"

#include "MQ2Prototypes.h"
#include "MQ2Internal.h"
#include "MQ2Globals.h"

/* BENCHMARKING */
#ifdef DISABLE_BENCHMARKS
#define Benchmark(BMHandle, code) code
#else
#define Benchmark(BMHandle, code) { EnterMQ2Benchmark(BMHandle); code; ExitMQ2Benchmark(BMHandle); }
#endif
EQLIB_API void ShutdownMQ2Benchmarks();
EQLIB_API void InitializeMQ2Benchmarks();
EQLIB_API bool GetMQ2Benchmark(uint32_t BMHandle, MQBenchmark& Dest);
EQLIB_API void ExitMQ2Benchmark(uint32_t BMHandle);
EQLIB_API void EnterMQ2Benchmark(uint32_t BMHandle);
EQLIB_API void RemoveMQ2Benchmark(uint32_t BMHandle);
EQLIB_API uint32_t AddMQ2Benchmark(const char* Name);

/* SPAWN HANDLING */
EQLIB_API void InitializeMQ2Spawns();
EQLIB_API void ShutdownMQ2Spawns();
EQLIB_API void ProcessPendingGroundItems();
EQLIB_API void UpdateMQ2SpawnSort();
EQLIB_API bool SetNameSpriteState(SPAWNINFO* pSpawn, bool Show);
EQLIB_API bool IsTargetable(SPAWNINFO* pSpawn);

/* WINDOWS */
EQLIB_API HWND GetEQWindowHandle();
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
EQLIB_API void dsp_chat_no_events(const char* Text, int Color, bool EqLog = true, bool dopercentsubst = true);

/* DETOURING API */
EQLIB_API void InitializeMQ2Detours();
EQLIB_API void ShutdownMQ2Detours();


EQLIB_API bool AddDetour(DWORD address, BYTE* pfDetour = 0, BYTE* pfTrampoline = 0, DWORD Count = 20, char* Name = 0);
EQLIB_API void AddDetourf(DWORD address, ...);
EQLIB_API void RemoveDetour(DWORD address);
EQLIB_API void DeleteDetour(DWORD address);

EQLIB_API void WriteChatf(const char* Format, ...);
EQLIB_API void WriteChatfSafe(const char* szFormat, ...);
EQLIB_API void WriteChatColor(const char* Line, DWORD Color = USERCOLOR_DEFAULT, DWORD Filter = 0);

/* PLUGIN HANDLING */
EQLIB_API void InitializeMQ2Plugins();
EQLIB_API int LoadMQ2Plugin(const char* pszFilename, bool bCustom = false);
EQLIB_API bool UnloadMQ2Plugin(const char* pszFilename);
EQLIB_API void UnloadMQ2Plugins();
EQLIB_API void ShutdownMQ2Plugins();
EQLIB_API void SaveMQ2PluginLoadStatus(const char* Name, bool bLoad);
EQLIB_API void PulsePlugins();
EQLIB_API void PluginsZoned();
EQLIB_API bool PluginsIncomingChat(const char* Line, DWORD Color);
EQLIB_API void PluginsCleanUI();
EQLIB_API void PluginsReloadUI();
EQLIB_API void PluginsSetGameState(DWORD GameState);
EQLIB_API void PluginsDrawHUD();
EQLIB_API void PluginsAddSpawn(SPAWNINFO* pNewSpawn);
EQLIB_API void PluginsRemoveSpawn(SPAWNINFO* pSpawn);
EQLIB_API void PluginsAddGroundItem(GROUNDITEM* pNewGroundItem);
EQLIB_API void PluginsRemoveGroundItem(GROUNDITEM* pGroundItem);
EQLIB_API void PluginsBeginZone();
EQLIB_API void PluginsEndZone();
EQLIB_API bool IsPluginsInitialized();
EQLIB_API void* GetPluginProc(const char* plugin, const char* proc);

/* DIRECT INPUT */
EQLIB_API void InitializeMQ2DInput();
EQLIB_API void ShutdownMQ2DInput();

/* CLEAN UI */
EQLIB_API void InitializeDisplayHook();
EQLIB_API void ShutdownDisplayHook();
EQLIB_API void DrawHUD();

/* COMMAND HANDLING */
EQLIB_API void InitializeMQ2Commands();
EQLIB_API void ShutdownMQ2Commands();
EQLIB_API void AddCommand(const char* Command, fEQCommand Function, bool EQ = false, bool Parse = true, bool InGame = false);
EQLIB_API void AddAlias(const char* ShortCommand, const char* LongCommand);
EQLIB_API bool RemoveAlias(const char* ShortCommand);
EQLIB_API void AddSubstitute(const char* Original, const char* Substitution);
EQLIB_API bool RemoveSubstitute(const char* Original);
EQLIB_API bool RemoveCommand(const char* Command);
EQLIB_API void PulseCommands();
EQLIB_API void TimedCommand(const char* Command, int msDelay);
EQLIB_API bool IsCommand(const char* command);
EQLIB_API bool IsAlias(const char* alias);

/* MACRO COMMANDS */
EQLIB_API void DumpStack(PSPAWNINFO, char*);
EQLIB_API void EndMacro(PSPAWNINFO, char*);
EQLIB_API void Echo(SPAWNINFO*, char*);

/* MACRO PARSING */
void __stdcall EventBlechCallback(unsigned int ID, void * pData, PBLECHVALUE pValues);

EQLIB_API char* ParseMacroParameter(PSPAWNINFO pChar, char* szOriginal, size_t BufferSize);

template <unsigned int _Size>
inline char* ParseMacroParameter(PSPAWNINFO pChar, char(&szOriginal)[_Size])
{
	return ParseMacroParameter(pChar, szOriginal, _Size);
}

EQLIB_API void FailIf(PSPAWNINFO pChar, char* szCommand, int pStartLine, BOOL All = FALSE);
EQLIB_API void InitializeParser();
EQLIB_API void ShutdownParser();

EQLIB_API void InitializeMQ2DataTypes();
EQLIB_API void ShutdownMQ2DataTypes();
EQLIB_API void InitializeMQ2Data();
EQLIB_API void ShutdownMQ2Data();
EQLIB_API BOOL ParseMacroData(char* szOriginal, size_t BufferSize);
EQLIB_API bool AddMQ2Data(const char* szName, fMQData Function);
EQLIB_API bool RemoveMQ2Data(const char* szName);
EQLIB_API MQ2Type* FindMQ2DataType(const char* szName);
EQLIB_API MQ2DataItem* FindMQ2Data(const char* szName);
EQLIB_API PDATAVAR FindMQ2DataVariable(const char* szName);
EQLIB_API bool ParseMQ2DataPortion(char* szOriginal, MQ2TYPEVAR &Result);
EQLIB_API bool AddMQ2TypeExtension(const char* typeName, MQ2Type* extension);
EQLIB_API bool RemoveMQ2TypeExtension(const char* typeName, MQ2Type* extension);


/* MOUSE */
EQLIB_API bool IsMouseWaiting();
EQLIB_API bool IsMouseWaitingForButton();
EQLIB_API void MQ2MouseHooks(bool bFlag);
EQLIB_API bool MoveMouse(int x, int y, bool bClick = false);
EQLIB_API bool MouseToPlayer(PlayerClient* pPlayer, DWORD position, bool bClick = false);

/* KEY BINDS */
EQLIB_API void InitializeMQ2KeyBinds();
EQLIB_API void ShutdownMQ2KeyBinds();
EQLIB_API bool PressMQ2KeyBind(const char* name, bool Hold);
EQLIB_API bool SetMQ2KeyBind(const char* name, bool Alternate, KeyCombo& Combo);
EQLIB_API bool AddMQ2KeyBind(const char* name, fMQExecuteCmd Function);
EQLIB_API bool RemoveMQ2KeyBind(const char* name);
EQLIB_API bool GetMQ2KeyBind(const char* name, bool Alt, KeyCombo& Combo);
EQLIB_API bool DumpBinds(const char* Filename);
EQLIB_API bool MQ2HandleKeyDown(const KeyCombo& Combo);
EQLIB_API bool MQ2HandleKeyUp(const KeyCombo& Combo);
EQLIB_API int FindMappableCommand(const char* name);

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
EQLIB_API unsigned long GetFastTime();
EQLIB_API char * __stdcall GetXtargetType(DWORD type);
EQLIB_API DWORD EQGetTime();
EQLIB_OBJECT CXStr STMLToText(const CXStr& In, bool bReplaceBrWithNewline = true);
EQLIB_API class IconCache *__cdecl GetAnimationCache(int index);
EQLIB_API void SaveColors(int, int, int, int);

/* UTILITIES */
EQLIB_API void ConvertCR(char* Text, size_t LineLen);
EQLIB_API void DrawHUDText(const char* Text, int X, int Y, unsigned int Argb, int Font);
EQLIB_API void FixStringTable();
EQLIB_API void DebugSpew(char* szFormat, ...);
EQLIB_API void DebugSpewAlways(char* szFormat, ...);
EQLIB_API void DebugSpewAlwaysFile(char* szFormat, ...);
EQLIB_API void DebugSpewNoFile(char* szFormat, ...);
EQLIB_API PSTR GetNextArg(PCSTR szLine, DWORD dwNumber = 1, BOOL CSV = FALSE, char Separator = 0);
EQLIB_API PSTR GetArg(PSTR szDest, PCSTR szSrc, DWORD dwNumber, BOOL LeaveQuotes = FALSE, BOOL ToParen = FALSE, BOOL CSV = FALSE, char Separator = 0, BOOL AnyNonAlphaNum = FALSE);
EQLIB_API void AddCustomEvent(PEVENTLIST pEList, char* szLine);
EQLIB_API float DistanceToSpawn(PSPAWNINFO pChar, PSPAWNINFO pSpawn);
EQLIB_API char* GetEQPath(char* szBuffer, size_t len);

#define DoCommand(pspawninfo, commandtoexecute) HideDoCommand(pspawninfo, commandtoexecute, FromPlugin != 0)
EQLIB_API void HideDoCommand(SPAWNINFO* pChar, const char* szLine, bool delayed);
#define EzCommand(commandtoexecute) DoCommand((PSPAWNINFO)pLocalPlayer, commandtoexecute)

EQLIB_API DWORD MQToSTML(const char* in, char* out, DWORD maxlen = MAX_STRING, DWORD ColorOverride = 0xFFFFFF);
EQLIB_API void StripMQChat(const char* in, char* out);
EQLIB_API void STMLToPlainText(char* in, char* out);
EQLIB_API char* GetSubFromLine(int Line, char* szSub, size_t Sublen);
EQLIB_API char* GetFilenameFromFullPath(char* Filename);
EQLIB_API BOOL CompareTimes(char* RealTime, char* ExpectedTime);
EQLIB_API void AddFilter(char* szFilter, DWORD Length, PBOOL pEnabled);
EQLIB_API void DefaultFilters();
EQLIB_API char* ConvertHotkeyNameToKeyName(char* szName);
EQLIB_API void CheckChatForEvent(const char* szMsg);
EQLIB_API void ConvertItemTags(CXStr &cxstr, BOOL Tag = TRUE);
EQLIB_API BOOL ParseKeyCombo(char* text, KeyCombo &Dest);
EQLIB_API char* DescribeKeyCombo(KeyCombo &Combo, char* szDest, size_t BufferSize);
EQLIB_API int FindInvSlotForContents(CONTENTS* pContents);
EQLIB_API int FindInvSlot(char* Name, BOOL Exact);
EQLIB_API int FindNextInvSlot(char* Name, BOOL Exact);

EQLIB_API int GetLanguageIDByName(char* szName);
EQLIB_API int GetCurrencyIDByName(char* szName);
EQLIB_API char* GetSpellNameByID(LONG dwSpellID);
EQLIB_API SPELL* GetSpellByName(const char* szName);
EQLIB_API PSPELL GetSpellByAAName(char* szName);
EQLIB_API PSPELL GetSpellByAAName(char* szName);
EQLIB_API PALTABILITY GetAAByIdWrapper(int nAbilityId, int playerLevel = -1);
EQLIB_API int GetSpellRankByName(const char* SpellName);
EQLIB_API void TruncateSpellRankName(char* SpellName);
EQLIB_API void RemoveBuff(SPAWNINFO* pChar, char* szLine);
EQLIB_API void RemovePetBuff(SPAWNINFO* pChar, char* szLine);
EQLIB_API bool StripQuotes(char* str);
EQLIB_API void MakeMeVisible(SPAWNINFO* pChar, char* szLine);
EQLIB_API void RemoveAura(SPAWNINFO* pChar, char* szLine);
EQLIB_API bool GetAllMercDesc(std::map<int, MercDesc>& minfo);

DWORD GetKeyRingIndex(DWORD KeyRing, char* szItemName, size_t BuffLen, bool bExact = true, bool usecmd = false);
EQLIB_API int GetMountCount();
EQLIB_API int GetIllusionCount();
EQLIB_API int GetFamiliarCount();
EQLIB_API void RefreshKeyRings(void* kr);
EQLIB_API void InitKeyRings();
EQLIB_API BOOL IsActiveAA(char* pSpellName);
EQLIB_API CXWnd* GetAdvLootPersonalListItem(DWORD ListIndex/*YES ITS THE INTERNAL INDEX*/, DWORD type);
EQLIB_API CXWnd* GetAdvLootSharedListItem(DWORD ListIndex/*YES IT REALLY IS THE LISTINDEX*/, DWORD type);
EQLIB_API bool LootInProgress(CAdvancedLootWnd* pAdvLoot, CListWnd* pPersonalList, CListWnd* pSharedList);
EQLIB_API void WeDidStuff();
EQLIB_API int GetFreeInventory(int nSize);
EQLIB_API int RangeRandom(int min, int max);
EQLIB_API DWORD __stdcall BeepOnTellThread(void* pData);
EQLIB_API DWORD __stdcall FlashOnTellThread(void* pData);
EQLIB_API CMQ2Alerts CAlerts;

struct RefreshKeyRingsThreadData
{
	char ItemName[256];
	CSidlScreenWnd *phWnd;
	bool bExact;
	bool bUseCmd;
};

EQLIB_API ITEMINFO *GetItemFromContents(CONTENTS* c);

#include "MQ2Inlines.h"

//#define GETMEMBER() GetMember(MQ2VARPTR VarPtr, char* Member, char* Index, MQ2TYPEVAR& Dest)
//#define DECLAREGETMETHOD()
//#define INHERITDIRECT(X)
//#define INHERITINDIRECT(X,Y,Z)

#include "MQ2DataTypes.h"

EQLIB_API BOOL AddMacroLine(char* FileName, char* szLine, size_t Linelen, int *LineNumber, int localLine);

EQLIB_API const char* GetLightForSpawn(PSPAWNINFO pSpawn);
EQLIB_API unsigned int GetSpellDuration(SPELL* pSpell, SPAWNINFO* pSpawn);
EQLIB_API DWORD GetDeityTeamByID(DWORD DeityID);
EQLIB_API DWORD ConColor(PSPAWNINFO pSpawn);

EQLIB_API char* GetGuildByID(int64_t GuildID);
EQLIB_API int64_t GetGuildIDByName(char* szGuild);

extern std::map<int, std::string>targetBuffSlotToCasterMap;
extern std::map<int, std::map<int,TargetBuff>>CachedBuffsMap;
EQLIB_API CONTENTS* GetEnviroContainer();
EQLIB_API CContainerWnd* FindContainerForContents(CONTENTS* pContents);
EQLIB_API float FindSpeed(SPAWNINFO* pSpawn);
EQLIB_API BOOL IsNamed(PSPAWNINFO pSpawn);
EQLIB_API void GetItemLinkHash(CONTENTS* Item, char* Buffer, size_t BufferSize);

template <unsigned int _Size>
inline void GetItemLinkHash(CONTENTS* Item, char(&Buffer)[_Size])
{
	return GetItemLinkHash(Item, Buffer, _Size);
}

EQLIB_API bool GetItemLink(CONTENTS* Item, char* Buffer, size_t BufferSize, BOOL Clickable = TRUE);

template <unsigned int _Size>
inline bool GetItemLink(CONTENTS* Item, char(&Buffer)[_Size], BOOL Clickable = TRUE)
{
	return GetItemLink(Item, Buffer, _Size, Clickable);
}

EQLIB_API char* GetLoginName();
EQLIB_API float DistanceToPoint(PSPAWNINFO pSpawn, float xLoc, float yLoc);
EQLIB_API float Distance3DToPoint(PSPAWNINFO pSpawn, float xLoc, float yLoc, float zLoc);
EQLIB_API char* ShowSpellSlotInfo(PSPELL pSpell, char* szBuffer, size_t BufferSize);
EQLIB_API char* ParseSpellEffect(PSPELL pSpell, int i, char* szBuffer, size_t BufferSize, LONG level = 100);

EQLIB_API int GetSpellAttrib(PSPELL pSpell, int index);
EQLIB_API LONG GetSpellBase(PSPELL pSpell, int index);
EQLIB_API LONG GetSpellBase2(PSPELL pSpell, int index);
EQLIB_API LONG GetSpellMax(PSPELL pSpell, int index);
EQLIB_API LONG GetSpellCalc(PSPELL pSpell, int index);

EQLIB_API void SlotValueCalculate(char* szBuff, PSPELL pSpell, int i, double mp = 1.0);
EQLIB_API LONG CalcValue(LONG calc, LONG base, LONG max, LONG tick, LONG minlevel = MAX_PC_LEVEL, LONG level = MAX_PC_LEVEL);
EQLIB_API char* GetSpellEffectName(LONG EffectID, char* szBuffer, size_t BufferSize);
EQLIB_API void GetGameDate(int* Month, int* Day, int* Year);
EQLIB_API void GetGameTime(int* Hour, int* Minute, int* Night);
EQLIB_API void SyntaxError(char* szFormat, ...);
EQLIB_API void MacroError(char* szFormat, ...);
EQLIB_API void FatalError(char* szFormat, ...);
EQLIB_API char* GetSpellRestrictions(PSPELL pSpell, unsigned int nIndex, char* szBuffer, size_t BufferSize);
EQLIB_API void MQ2DataError(char* szFormat, ...);
EQLIB_API void DisplayOverlayText(char* szText, DWORD dwColor, DWORD dwTransparency, DWORD msFadeIn, DWORD msFadeOut, DWORD msHold);
EQLIB_API void CustomPopup(char* szPopText, bool bPopOutput);

EQLIB_API BOOL IsBardSong(PSPELL pSpell);
EQLIB_API BOOL IsSPAEffect(PSPELL pSpell, LONG EffectID);
EQLIB_API bool GetShortBuffID(SPELLBUFF* pBuff, DWORD& nID);
EQLIB_API bool GetBuffID(SPELLBUFF* pBuff, DWORD& nID);
EQLIB_API char* GetLDoNTheme(DWORD LDTheme);
EQLIB_API BOOL TriggeringEffectSpell(PSPELL aSpell, int i);
EQLIB_API BOOL BuffStackTest(PSPELL aSpell, PSPELL bSpell, BOOL bIgnoreTriggeringEffects = FALSE, BOOL bTriggeredEffectCheck = FALSE);
EQLIB_API DWORD GetItemTimer(CONTENTS* pItem);
EQLIB_API CONTENTS* GetItemContentsBySlotID(DWORD dwSlotID);
EQLIB_API CONTENTS* GetItemContentsByName(const char* ItemName);
EQLIB_API DWORD GetAvailableSlots(CONTENTS* pContainer, CONTENTS* pItem, int *firstavailableslot);
EQLIB_API bool LoH_HT_Ready();

/* MQ2DATAVARS */
EQLIB_API char* GetFuncParam(char* szMacroLine, DWORD ParamNum, char* szParamName, size_t ParamNameLen, char* szParamType, size_t ParamTypeLen);
//EQLIB_API char* GetFuncParam(char* szMacroLine, DWORD ParamNum, char* szParamName, char* szParamType);
EQLIB_API PDATAVAR FindMQ2DataVariable(const char* Name);
EQLIB_API bool AddMQ2DataVariable(const char* Name, const char* Index, MQ2Type* pType, PDATAVAR* ppHead, const char* Default);
EQLIB_API bool AddMQ2DataVariableFromData(const char* Name, const char* Index, MQ2Type* pType, PDATAVAR* ppHead, MQ2TYPEVAR Default);
EQLIB_API PDATAVAR* FindVariableScope(const char* Name);
EQLIB_API bool DeleteMQ2DataVariable(const char* Name);
EQLIB_API void ClearMQ2DataVariables(PDATAVAR* ppHead);
EQLIB_API void NewDeclareVar(PSPAWNINFO pChar, char* szLine);
EQLIB_API void NewDeleteVarCmd(PSPAWNINFO pChar, char* szLine);
EQLIB_API void NewVarset(PSPAWNINFO pChar, char* szLine);
EQLIB_API void NewVarcalc(PSPAWNINFO pChar, char* szLine);
EQLIB_API void NewVardata(PSPAWNINFO pChar, char* szLine);
EQLIB_API void DropTimers();

/*                 */

EQLIB_API BOOL LoadCfgFile(char* Filename, BOOL Delayed = FromPlugin);
//EQLIB_API char* GetFriendlyNameForGroundItem(PGROUNDITEM pItem, char* szName);
EQLIB_API void ClearSearchSpawn(PSEARCHSPAWN pSearchSpawn);
EQLIB_API SPAWNINFO* NthNearestSpawn(SEARCHSPAWN* pSearchSpawn, int Nth, SPAWNINFO* pOrigin, bool IncludeOrigin = false);
EQLIB_API DWORD CountMatchingSpawns(PSEARCHSPAWN pSearchSpawn, PSPAWNINFO pOrigin, BOOL IncludeOrigin = FALSE);
EQLIB_API PSPAWNINFO SearchThroughSpawns(PSEARCHSPAWN pSearchSpawn, PSPAWNINFO pChar);
EQLIB_API BOOL SpawnMatchesSearch(PSEARCHSPAWN pSearchSpawn, PSPAWNINFO pChar, PSPAWNINFO pSpawn);
EQLIB_API BOOL SearchSpawnMatchesSearchSpawn(PSEARCHSPAWN pSearchSpawn1, PSEARCHSPAWN pSearchSpawn2);
EQLIB_API char* ParseSearchSpawnArgs(char* szArg, char* szRest, PSEARCHSPAWN pSearchSpawn);
EQLIB_API void ParseSearchSpawn(char* Buffer, PSEARCHSPAWN pSearchSpawn);
EQLIB_API char* FormatSearchSpawn(char* Buffer, size_t BufferSize, PSEARCHSPAWN pSearchSpawn);
EQLIB_API BOOL IsPCNear(PSPAWNINFO pSpawn, float Radius);
EQLIB_API bool IsInGroup(SPAWNINFO* pSpawn, bool bCorpse = false);
EQLIB_API BOOL IsInFellowship(PSPAWNINFO pSpawn, BOOL bCorpse = 0);
EQLIB_API BOOL IsInRaid(PSPAWNINFO pSpawn, BOOL bCorpse = 0);
EQLIB_API bool IsAlert(SPAWNINFO* pChar, SPAWNINFO* pSpawn, uint32_t id);
EQLIB_API bool GetClosestAlert(SPAWNINFO* pSpawn, uint32_t id);
EQLIB_API bool IsAlert(SPAWNINFO* pChar, SPAWNINFO* pSpawn, uint32_t List);
EQLIB_API bool CheckAlertForRecursion(SEARCHSPAWN* pSearchSpawn, uint32_t id);
EQLIB_API void WriteFilterNames();
EQLIB_API void SetDisplaySWhoFilter(PBOOL bToggle, char* szFilter, char* szToggle);
EQLIB_API char* GetModel(PSPAWNINFO pSpawn, DWORD Slot);
EQLIB_API void RewriteSubstitutions();
EQLIB_API void RewriteAliases();
EQLIB_API void WriteAliasToIni(const char* Name, const char* Command);
EQLIB_API DWORD FindSpellListByName(char* szName);
EQLIB_API float StateHeightMultiplier(DWORD StandState);
EQLIB_API DWORD WINAPI thrMsgBox(void* lpParameter);
extern void SuperWhoDisplay(SPAWNINFO* pChar, SEARCHSPAWN* pSearchSpawn, DWORD Color);
extern void SuperWhoDisplay(SPAWNINFO* pSpawn, DWORD Color);
EQLIB_API bool pWHOSORTCompare(const PSPAWNINFO A, const PSPAWNINFO B);

EQLIB_API void        OverwriteTable(DWORD Address);
EQLIB_API DWORD      Include(char* szFile, int *LineNumber);
EQLIB_API char*       GetFullZone(DWORD ZoneID);
EQLIB_API DWORD       GetZoneID(char* ZoneShortName);
EQLIB_API char*       GetShortZone(DWORD ZoneID);
//EQLIB_API void        SwapSWho                (PSWHOSORT pSWho1, PSWHOSORT pSWho2);
//EQLIB_API void        SortSWho                (PSWHOSORT pSWhoSort, DWORD SpawnCount, DWORD SortBy = 0);
//EQLIB_API void        SuperWhoFindPets        (PSPAWNINFO pChar, WORD SpawnID);
//EQLIB_API void        SuperWhoDisplay         (PSPAWNINFO pChar, PSEARCHSPAWN pFilter, PSPAWNINFO psTarget, WORD Padding = 0, DWORD Color = 0);
EQLIB_API float       DistanceToSpawn3D(PSPAWNINFO pChar, PSPAWNINFO pSpawn);
EQLIB_API float       EstimatedDistanceToSpawn(PSPAWNINFO pChar, PSPAWNINFO pSpawn);
EQLIB_API DWORD WINAPI InsertCommands(void* lpParameter);
EQLIB_API void        UpdateMonitoredSpawns();
EQLIB_API char*       GetModel(PSPAWNINFO pSpawn, DWORD Slot);
//EQLIB_API PSPAWNINFO  GetPet                  (DWORD OwnerID);
//EQLIB_API BOOL        IfCompare               (char* szCond);
EQLIB_API bool        PlayerHasAAAbility(DWORD AAIndex);
EQLIB_API char*       GetAANameByIndex(DWORD AAIndex);
EQLIB_API DWORD       GetAAIndexByName(char* AAName);
EQLIB_API DWORD       GetAAIndexByID(DWORD ID);
EQLIB_API DWORD       GetSkillIDFromName(char* name);
EQLIB_API bool        InHoverState();
EQLIB_API DWORD       GetGameState();
EQLIB_API DWORD       GetWorldState();
EQLIB_API float       GetMeleeRange(PlayerClient*, PlayerClient*);
EQLIB_API DWORD       GetSpellGemTimer(DWORD nGem);
EQLIB_API DWORD       GetSpellBuffTimer(DWORD SpellID);
EQLIB_API bool        HasExpansion(DWORD nExpansion);
EQLIB_API void		  ListMercAltAbilities();
EQLIB_API CONTENTS*   FindItemBySlot(short InvSlot, short BagSlot = -1, ItemContainerInstance location = eItemContainerPossessions);
EQLIB_API CONTENTS*   FindItemBySlot2(const ItemGlobalIndex& idx);
EQLIB_API CONTENTS*   FindItemByName(char* pName, BOOL bExact = false);
EQLIB_API CONTENTS*   FindItemByID(int ItemID);
EQLIB_API DWORD	      FindItemCountByName(char* pName, BOOL bExact = false);
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
EQLIB_API bool        HasCachedTargetBuffSubCat(const char* subcat, SPAWNINFO* pSpawn, TargetBuff* pcTargetBuff, unsigned int classmask = 0);
EQLIB_API bool        HasCachedTargetBuffSPA(int spa, bool bIncrease, SPAWNINFO* pSpawn, TargetBuff* pcTargetBuff);
EQLIB_API int         GetSelfBuffByCategory(int category, unsigned int classmask = 0, int startslot = 0);
EQLIB_API int         GetSelfBuffBySubCat(const char* subcat, unsigned int classmask = 0, int startslot = 0);
EQLIB_API int         GetSelfBuffBySPA(int spa, bool bIncrease, int startslot = 0);
EQLIB_API int         GetSelfShortBuffBySPA(int spa, bool bIncrease, int startslot = 0);
EQLIB_API bool        IsSpellUsableForClass(SPELL* pSpell, unsigned int classmask = 0);
EQLIB_API bool        IsAegoSpell(SPELL* pSpell);
EQLIB_API int         GetSpellCategory(SPELL* pSpell);
EQLIB_API int         GetSpellSubcategory(SPELL* pSpell);
EQLIB_API PSPELL      GetSpellParent(int id);
EQLIB_API HMODULE GetCurrentModule();
EQLIB_API DWORD CALLBACK MQ2End(void* lpParameter);
EQLIB_API DWORD CALLBACK GetlocalPlayerOffset();
EQLIB_API void MQ2Shutdown();
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

// Parse Operations
std::string HandleParseParam(const std::string& strOriginal, bool bParseOnce = false);
std::string ModifyMacroString(const std::string& strOriginal, bool bParseOnce = false, int iOperation = -1);

EQLIB_API BOOL Calculate(char* szFormula, double& Dest);

#include "MQ2TopLevelObjects.h"
#include "MQ2Commands.h"

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

EQLIB_API void memchecks_tramp(char*, DWORD, void*, DWORD, BOOL);
EQLIB_API void memchecks(char*, DWORD, void*, DWORD, BOOL);
EQLIB_API void InitializeLoginPulse();
EQLIB_API void RemoveAutoBankMenu();
EQLIB_API bool WillFitInBank(CONTENTS* pContent);
EQLIB_API bool WillFitInInventory(CONTENTS* pContent);
EQLIB_API void AddAutoBankMenu();
EQLIB_API void AutoBankPulse();
EQLIB_API void DoCommandf(char* szFormat, ...);
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
inline char* ISXEQArgToMQ2Arg(int argc, char *argv[], char *szTemp, size_t size)
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

inline void MakeLower(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

struct ci_less
{
	struct nocase_compare
	{
		bool operator() (const unsigned char& c1, const unsigned char& c2) const noexcept
		{
			if (c1 == c2)
				return true;
			return ::tolower(c1) < ::tolower(c2);
		}
	};

	bool operator()(std::string_view s1, std::string_view s2) const noexcept
	{
		return std::lexicographical_compare(
			s1.begin(), s1.end(),
			s2.begin(), s2.end(),
			nocase_compare());
	}
};

inline int ci_find_substr(std::string_view haystack, std::string_view needle, const std::locale& loc = std::locale())
{
	auto iter = std::search(std::begin(haystack), std::end(haystack),
		std::begin(needle), std::end(needle), ci_less::nocase_compare());
	if (iter == std::end(haystack)) return -1;
	return iter - std::begin(haystack);
}

inline bool ci_equals(std::string_view sv1, std::string_view sv2)
{
	return sv1.size() == sv2.size()
		&& std::equal(sv1.begin(), sv1.end(), sv2.begin(), ci_less::nocase_compare());
}
