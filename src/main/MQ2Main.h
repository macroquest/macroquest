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

#include "pch.h"

#include "blech\Blech.h"

#include "../eqlib/eqlib.h"
using namespace eqlib;

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

#ifdef MQ2MAIN_EXPORTS
#define MQLIB_API extern "C" __declspec(dllexport)
#define MQLIB_VAR extern "C" __declspec(dllexport)
#define MQLIB_OBJECT __declspec(dllexport)
#else
#define MQLIB_API extern "C" __declspec(dllimport)
#define MQLIB_VAR extern "C" __declspec(dllimport)
#define MQLIB_OBJECT __declspec(dllimport)
#endif

#ifdef MQ2PLUGIN
#define FromPlugin true
#else
#define FromPlugin false
#endif

#define STRINGIFY_IMPL(x) #x
#define STRINGIFY(x) STRINGIFY_IMPL(x)

// Define access to a member with another name (and type if you so will it)
#define ALT_MEMBER_GETTER(type, orig, name) \
    type& getter_ ## name() { return (type&)orig; } \
    __declspec(property(get=getter_ ## name)) type name;

#define EzDetour(offset, detour, trampoline) AddDetourf((DWORD)offset, detour, trampoline, STRINGIFY(offset))
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

#define LODWORD(_qw)          ((uint32_t)(_qw))
#define HIDWORD(_qw)          ((uint32_t)(((_qw) >> 32) & 0xffffffff))

#include "MQ2Prototypes.h"
#include "MQ2Internal.h"
#include "MQ2Globals.h"
#include "MQ2Inlines.h"
#include "MQ2DataTypes.h"
#include "MQ2TopLevelObjects.h"
#include "MQ2Commands.h"

namespace mq {

/* THREADING */
MQLIB_API DWORD GetMainThreadId();
MQLIB_API bool IsMainThread();

// Queue a function to be called on the main thread on the next pulse
MQLIB_OBJECT void PostToMainThread(std::function<void()>&& callback);

/* BENCHMARKING */
#ifdef DISABLE_BENCHMARKS
#define Benchmark(BMHandle, code) code
#else
#define Benchmark(BMHandle, code) { EnterMQ2Benchmark(BMHandle); code; ExitMQ2Benchmark(BMHandle); }
#endif
MQLIB_API void ShutdownMQ2Benchmarks();
MQLIB_API void InitializeMQ2Benchmarks();
MQLIB_API bool GetMQ2Benchmark(uint32_t BMHandle, MQBenchmark& Dest);
MQLIB_API void ExitMQ2Benchmark(uint32_t BMHandle);
MQLIB_API void EnterMQ2Benchmark(uint32_t BMHandle);
MQLIB_API void RemoveMQ2Benchmark(uint32_t BMHandle);
MQLIB_API uint32_t AddMQ2Benchmark(const char* Name);

/* SPAWN HANDLING */
MQLIB_API void InitializeMQ2Spawns();
MQLIB_API void ShutdownMQ2Spawns();
MQLIB_API void ProcessPendingGroundItems();
MQLIB_API void UpdateMQ2SpawnSort();
MQLIB_API bool SetNameSpriteState(SPAWNINFO* pSpawn, bool Show);
MQLIB_API bool IsTargetable(SPAWNINFO* pSpawn);

/* WINDOWS */
MQLIB_API HWND GetEQWindowHandle();
MQLIB_API void InitializeMQ2Windows();
MQLIB_API void ShutdownMQ2Windows();
MQLIB_API void RemoveXMLFile(const char* filename);
MQLIB_API void AddXMLFile(const char* filename);
MQLIB_API bool IsXMLFilePresent(const char* filename);
MQLIB_API bool SendWndClick(const char* WindowName, const char* ScreenID, const char* ClickNotification);
MQLIB_API bool SendWndNotification(const char* WindowName, const char* ScreenID, int Notification, void* Data = 0);
MQLIB_API void AddWindow(char *WindowName, CXWnd **ppWindow);
MQLIB_API void RemoveWindow(char* WindowName);
MQLIB_API CXWnd* FindMQ2Window(const char* Name);
MQLIB_API CXWnd* GetParentWnd(CXWnd* pWnd);

MQLIB_API bool SendComboSelect(const char* WindowName, const char* ScreenID, int Value);
MQLIB_API bool SendListSelect(const char* WindowName, const char* ScreenID, int Value);
MQLIB_API bool SendListSelect2(CXWnd* pList, int ListIndex);
MQLIB_API bool SendWndClick2(CXWnd* pWnd, const char* ClickNotification);

MQLIB_API void CreateMQ2NewsWindow();
MQLIB_API void DeleteMQ2NewsWindow();

/* CHAT HOOK */
MQLIB_API void InitializeChatHook();
MQLIB_API void ShutdownChatHook();
MQLIB_API void dsp_chat_no_events(const char* Text, int Color, bool EqLog = true, bool dopercentsubst = true);

/* DETOURING API */
MQLIB_API void InitializeMQ2Detours();
MQLIB_API void ShutdownMQ2Detours();

MQLIB_API bool AddDetour(DWORD address, BYTE* pfDetour = 0, BYTE* pfTrampoline = 0, DWORD Count = 20, char* Name = 0);
MQLIB_API void AddDetourf(DWORD address, ...);
MQLIB_API void RemoveDetour(DWORD address);
MQLIB_API void DeleteDetour(DWORD address);

MQLIB_API void WriteChatColor(const char* Line, int Color = USERCOLOR_DEFAULT, int Filter = 0);
MQLIB_API void WriteChatf(const char* Format, ...);
MQLIB_API void WriteChatColorf(const char* szFormat, int color, ...);

MQLIB_API [[deprecated("Use WriteChatf instead")]]
void WriteChatfSafe(const char* szFormat, ...);

/* PLUGIN HANDLING */
MQLIB_API void InitializeMQ2Plugins();
MQLIB_API int LoadMQ2Plugin(const char* pszFilename, bool bCustom = false);
MQLIB_API bool UnloadMQ2Plugin(const char* pszFilename);
MQLIB_API void UnloadMQ2Plugins();
MQLIB_API void ShutdownMQ2Plugins();
MQLIB_API [[deprecated("This is handled on load/unload without the direct call.")]] void SaveMQ2PluginLoadStatus(const char* Name, bool bLoad);
MQLIB_API void PulsePlugins();
MQLIB_API void PluginsZoned();
MQLIB_API bool PluginsIncomingChat(const char* Line, DWORD Color);
MQLIB_API void PluginsCleanUI();
MQLIB_API void PluginsReloadUI();
MQLIB_API void PluginsSetGameState(DWORD GameState);
MQLIB_API void PluginsDrawHUD();
MQLIB_API void PluginsAddSpawn(SPAWNINFO* pNewSpawn);
MQLIB_API void PluginsRemoveSpawn(SPAWNINFO* pSpawn);
MQLIB_API void PluginsAddGroundItem(GROUNDITEM* pNewGroundItem);
MQLIB_API void PluginsRemoveGroundItem(GROUNDITEM* pGroundItem);
MQLIB_API void PluginsBeginZone();
MQLIB_API void PluginsEndZone();
MQLIB_API bool IsPluginsInitialized();
MQLIB_API void* GetPluginProc(const char* plugin, const char* proc);

/* DIRECT INPUT */
MQLIB_API void InitializeMQ2DInput();
MQLIB_API void ShutdownMQ2DInput();

/* CLEAN UI */
MQLIB_API void InitializeDisplayHook();
MQLIB_API void ShutdownDisplayHook();
MQLIB_API void DrawHUD();

/* COMMAND HANDLING */
MQLIB_API void InitializeMQ2Commands();
MQLIB_API void ShutdownMQ2Commands();
MQLIB_API void AddCommand(const char* Command, fEQCommand Function, bool EQ = false, bool Parse = true, bool InGame = false);
MQLIB_API void AddAlias(const char* ShortCommand, const char* LongCommand);
MQLIB_API bool RemoveAlias(const char* ShortCommand);
MQLIB_API void AddSubstitute(const char* Original, const char* Substitution);
MQLIB_API bool RemoveSubstitute(const char* Original);
MQLIB_API bool RemoveCommand(const char* Command);
MQLIB_API void PulseCommands();
MQLIB_API void TimedCommand(const char* Command, int msDelay);
MQLIB_API bool IsCommand(const char* command);
MQLIB_API bool IsAlias(const char* alias);

/* MACRO COMMANDS */
MQLIB_API void DumpStack(SPAWNINFO*, char*);
MQLIB_API void EndMacro(SPAWNINFO*, char*);
MQLIB_API void Echo(SPAWNINFO*, char*);

/* MACRO PARSING */
void CALLBACK EventBlechCallback(unsigned int ID, void* pData, PBLECHVALUE pValues);

MQLIB_API char* ParseMacroParameter(SPAWNINFO* pChar, char* szOriginal, size_t BufferSize);

template <unsigned int _Size>
inline char* ParseMacroParameter(SPAWNINFO* pChar, char(&szOriginal)[_Size])
{
	return ParseMacroParameter(pChar, szOriginal, _Size);
}

MQLIB_API void FailIf(SPAWNINFO* pChar, const char* szCommand, int pStartLine, bool All = false);
MQLIB_API void InitializeParser();
MQLIB_API void ShutdownParser();

MQLIB_API void InitializeMQ2DataTypes();
MQLIB_API void ShutdownMQ2DataTypes();
MQLIB_API void InitializeMQ2Data();
MQLIB_API void ShutdownMQ2Data();
MQLIB_API bool ParseMacroData(char* szOriginal, size_t BufferSize);
MQLIB_API bool AddMQ2Data(const char* szName, fMQData Function);
MQLIB_API bool RemoveMQ2Data(const char* szName);
MQLIB_API MQ2Type* FindMQ2DataType(const char* szName);
MQLIB_API MQDataItem* FindMQ2Data(const char* szName);
MQLIB_API MQDataVar* FindMQ2DataVariable(const char* szName);
MQLIB_API bool AddMQ2Type(MQ2Type& type);
MQLIB_API bool RemoveMQ2Type(MQ2Type& type);
MQLIB_API bool ParseMQ2DataPortion(char* szOriginal, MQTypeVar &Result);
MQLIB_API bool AddMQ2TypeExtension(const char* typeName, MQ2Type* extension);
MQLIB_API bool RemoveMQ2TypeExtension(const char* typeName, MQ2Type* extension);

// Compatibility shims
[[deprecated("The data function's signature must be updated to bool functionName(const char* szIndex, MQTypeVar& ret)")]]
inline bool AddMQ2Data(const char* szName, fMQDataOld Function)
{
	return AddMQ2Data(szName, (fMQData)Function);
}

/* MOUSE */
MQLIB_API bool IsMouseWaiting();
MQLIB_API bool IsMouseWaitingForButton();
MQLIB_API void MQ2MouseHooks(bool bFlag);
MQLIB_API bool MoveMouse(int x, int y, bool bClick = false);
MQLIB_API bool MouseToPlayer(PlayerClient* pPlayer, DWORD position, bool bClick = false);

/* KEY BINDS */
MQLIB_API void InitializeMQ2KeyBinds();
MQLIB_API void ShutdownMQ2KeyBinds();
MQLIB_API bool PressMQ2KeyBind(const char* name, bool Hold);
MQLIB_API bool SetMQ2KeyBind(const char* name, bool Alternate, KeyCombo& Combo);
MQLIB_API bool AddMQ2KeyBind(const char* name, fMQExecuteCmd Function);
MQLIB_API bool RemoveMQ2KeyBind(const char* name);
MQLIB_API bool GetMQ2KeyBind(const char* name, bool Alt, KeyCombo& Combo);
MQLIB_API bool DumpBinds(const char* Filename);
MQLIB_API bool MQ2HandleKeyDown(const KeyCombo& Combo);
MQLIB_API bool MQ2HandleKeyUp(const KeyCombo& Combo);
MQLIB_API int FindMappableCommand(const char* name);

/* PULSING */
MQLIB_API void InitializeMQ2Pulse();
MQLIB_API void ShutdownMQ2Pulse();

/* UTILITIES */
MQLIB_API void ConvertCR(char* Text, size_t LineLen);
MQLIB_API void DrawHUDText(const char* Text, int X, int Y, unsigned int Argb, int Font);

// Logging utilities
MQLIB_API void DebugSpew(const char* szFormat, ...);
MQLIB_API void DebugSpewAlways(const char* szFormat, ...);
MQLIB_API void DebugSpewAlwaysFile(const char* szFormat, ...);
MQLIB_API void DebugSpewNoFile(const char* szFormat, ...);

MQLIB_API char* GetNextArg(char* szLine, int dwNumber = 1, bool CSV = false, char Separator = 0);
MQLIB_API char* GetArg(char* szDest, char* szSrc, int dwNumber, bool LeaveQuotes = false, bool ToParen = false, bool CSV = false, char Separator = 0, bool AnyNonAlphaNum = false);
MQLIB_API [[deprecated("The EQ Path is the working directory.")]] char* GetEQPath(char* szBuffer, size_t len);

// Command Execution
MQLIB_API void HideDoCommand(SPAWNINFO* pChar, const char* szLine, bool delayed);
MQLIB_API void DoCommandf(const char* szFormat, ...);
inline void DoCommand(PSPAWNINFO pSpawnInfo, const char* szCommand)
{
	HideDoCommand(pSpawnInfo, szCommand, FromPlugin);
}
inline void EzCommand(const char* szCommand) { DoCommand((SPAWNINFO*)pLocalPlayer, szCommand); }

MQLIB_API DWORD MQToSTML(const char* in, char* out, size_t maxlen = MAX_STRING, uint32_t ColorOverride = 0xFFFFFF);
MQLIB_API void StripMQChat(const char* in, char* out);
MQLIB_API void STMLToPlainText(char* in, char* out);
MQLIB_API char* GetSubFromLine(int Line, char* szSub, size_t Sublen);
MQLIB_API const char* GetFilenameFromFullPath(const char* Filename);
MQLIB_API bool CompareTimes(char* RealTime, char* ExpectedTime);
MQLIB_API void AddFilter(const char* szFilter, int Length, bool& pEnabled);
MQLIB_API void DefaultFilters();
MQLIB_API char* ConvertHotkeyNameToKeyName(char* szName);
MQLIB_API void CheckChatForEvent(const char* szMsg);
MQLIB_API void ConvertItemTags(CXStr& cxstr, bool Tag = true);
MQLIB_API bool ParseKeyCombo(const char* text, KeyCombo& Dest);
MQLIB_API char* DescribeKeyCombo(KeyCombo& Combo, char* szDest, size_t BufferSize);
MQLIB_API int FindInvSlotForContents(CONTENTS* pContents);
MQLIB_API int FindInvSlot(const char* Name, bool Exact);
MQLIB_API int FindNextInvSlot(const char* Name, bool Exact);

MQLIB_API int GetLanguageIDByName(const char* szName);
MQLIB_API int GetCurrencyIDByName(char* szName);
MQLIB_API const char* GetSpellNameByID(int dwSpellID);
MQLIB_API SPELL* GetSpellByName(const char* szName);
MQLIB_API SPELL* GetSpellByAAName(const char* szName);
MQLIB_API ALTABILITY* GetAAByIdWrapper(int nAbilityId, int playerLevel = -1);
MQLIB_API int GetSpellRankByName(const char* SpellName);
MQLIB_API void TruncateSpellRankName(char* SpellName);
MQLIB_API void RemoveBuff(SPAWNINFO* pChar, char* szLine);
MQLIB_API void RemovePetBuff(SPAWNINFO* pChar, char* szLine);
MQLIB_API bool StripQuotes(char* str);
MQLIB_API void MakeMeVisible(SPAWNINFO* pChar, char* szLine);
MQLIB_API void RemoveAura(SPAWNINFO* pChar, char* szLine);
MQLIB_API bool GetAllMercDesc(std::map<int, MercDesc>& minfo);
MQLIB_API int GetKeyRingIndex(KeyRingType KeyRing, const char* szItemName, bool bExact = true, bool usecmd = false);
MQLIB_API int GetMountCount();
MQLIB_API int GetIllusionCount();
MQLIB_API int GetFamiliarCount();
MQLIB_API void RefreshKeyRings(void* kr);
MQLIB_API void InitKeyRings();
MQLIB_API bool IsActiveAA(const char* pSpellName);
MQLIB_API CXWnd* GetAdvLootPersonalListItem(DWORD ListIndex, DWORD type);
MQLIB_API CXWnd* GetAdvLootSharedListItem(DWORD ListIndex, DWORD type);
MQLIB_API bool LootInProgress(CAdvancedLootWnd* pAdvLoot, CListWnd* pPersonalList, CListWnd* pSharedList);
MQLIB_API void WeDidStuff();
MQLIB_API int GetFreeInventory(int nSize);
MQLIB_API int RangeRandom(int min, int max);

MQLIB_API int GetCharMaxBuffSlots();
MQLIB_API int GetBodyType(SPAWNINFO* pSpawn);
MQLIB_API eSpawnType GetSpawnType(SPAWNINFO* pSpawn);

MQLIB_OBJECT bool IsRaidMember(const char* SpawnName);
MQLIB_OBJECT bool IsRaidMember(SPAWNINFO* pSpawn);
MQLIB_OBJECT int GetRaidMemberIndex(const char* SpawnName);
MQLIB_OBJECT int GetRaidMemberIndex(SPAWNINFO* pSpawn);
MQLIB_OBJECT bool IsGroupMember(const char* SpawnName);
MQLIB_OBJECT bool IsGroupMember(SPAWNINFO* pSpawn);
MQLIB_API bool IsFellowshipMember(const char* SpawnName);
MQLIB_API bool IsGuildMember(const char* SpawnName);
MQLIB_API int GetGroupMercenaryCount(uint32_t ClassMASK);
MQLIB_API SPAWNINFO* GetRaidMember(int index);
MQLIB_API SPAWNINFO* GetGroupMember(int index);
MQLIB_API uint32_t GetGroupMainAssistTargetID();
MQLIB_API uint32_t GetRaidMainAssistTargetID(int index);
MQLIB_API bool IsAssistNPC(SPAWNINFO* pSpawn);

MQLIB_API CMQ2Alerts CAlerts;

struct RefreshKeyRingsThreadData
{
	char ItemName[256];
	CSidlScreenWnd *phWnd;
	bool bExact;
	bool bUseCmd;
};

MQLIB_API ITEMINFO* GetItemFromContents(CONTENTS* c);

MQLIB_API bool AddMacroLine(const char* FileName, char* szLine, size_t Linelen, int* LineNumber, int localLine);

MQLIB_API const char* GetLightForSpawn(SPAWNINFO* pSpawn);
MQLIB_API int GetSpellDuration(SPELL* pSpell, SPAWNINFO* pSpawn);
MQLIB_API int GetDeityTeamByID(int DeityID);
MQLIB_API int ConColor(SPAWNINFO* pSpawn);

MQLIB_API const char* GetGuildByID(int64_t GuildID);
MQLIB_API int64_t GetGuildIDByName(char* szGuild);

MQLIB_API CONTENTS* GetEnviroContainer();
MQLIB_API CContainerWnd* FindContainerForContents(CONTENTS* pContents);
MQLIB_API float FindSpeed(SPAWNINFO* pSpawn);
MQLIB_API bool IsNamed(SPAWNINFO* pSpawn);
MQLIB_API void GetItemLinkHash(CONTENTS* Item, char* Buffer, size_t BufferSize);

template <unsigned int _Size>
inline void GetItemLinkHash(CONTENTS* Item, char(&Buffer)[_Size])
{
	return GetItemLinkHash(Item, Buffer, _Size);
}

MQLIB_API bool GetItemLink(CONTENTS* Item, char* Buffer, size_t BufferSize, bool Clickable = true);

template <unsigned int _Size>
inline bool GetItemLink(CONTENTS* Item, char(&Buffer)[_Size], bool Clickable = true)
{
	return GetItemLink(Item, Buffer, _Size, Clickable);
}

MQLIB_API const char* GetLoginName();
MQLIB_API float DistanceToPoint(SPAWNINFO* pSpawn, float xLoc, float yLoc);
MQLIB_API float Distance3DToPoint(SPAWNINFO* pSpawn, float xLoc, float yLoc, float zLoc);
MQLIB_API char* ShowSpellSlotInfo(SPELL* pSpell, char* szBuffer, size_t BufferSize);
MQLIB_API char* ParseSpellEffect(SPELL* pSpell, int i, char* szBuffer, size_t BufferSize, int level = 100);

MQLIB_API int GetSpellAttrib(SPELL* pSpell, int index);
MQLIB_API int GetSpellBase(SPELL* pSpell, int index);
MQLIB_API int GetSpellBase2(SPELL* pSpell, int index);
MQLIB_API int GetSpellMax(SPELL* pSpell, int index);
MQLIB_API int GetSpellCalc(SPELL* pSpell, int index);

MQLIB_API void SlotValueCalculate(char* szBuff, SPELL* pSpell, int i, double mp = 1.0);
MQLIB_API int CalcValue(int calc, int base, int max, int tick, int minlevel = MAX_PC_LEVEL, int level = MAX_PC_LEVEL);
MQLIB_API char* GetSpellEffectName(int EffectID, char* szBuffer, size_t BufferSize);
MQLIB_API void GetGameDate(int* Month, int* Day, int* Year);
MQLIB_API void GetGameTime(int* Hour, int* Minute, int* Night);
MQLIB_API void SyntaxError(const char* szFormat, ...);
MQLIB_API void MacroError(const char* szFormat, ...);
MQLIB_API void FatalError(const char* szFormat, ...);
MQLIB_API char* GetSpellRestrictions(SPELL* pSpell, unsigned int nIndex, char* szBuffer, size_t BufferSize);
MQLIB_API void MQ2DataError(char* szFormat, ...);
MQLIB_API void DisplayOverlayText(const char* szText, int dwColor, uint32_t dwTransparency, uint32_t msFadeIn, uint32_t msFadeOut, uint32_t msHold);
MQLIB_API void CustomPopup(char* szPopText, bool bPopOutput);

MQLIB_API bool IsBardSong(SPELL* pSpell);
MQLIB_API bool IsSPAEffect(SPELL* pSpell, int EffectID);
MQLIB_API bool GetShortBuffID(SPELLBUFF* pBuff, int& nID);
MQLIB_API bool GetBuffID(SPELLBUFF* pBuff, int& nID);
MQLIB_API const char* GetLDoNTheme(int LDTheme);
MQLIB_API bool TriggeringEffectSpell(SPELL* aSpell, int i);
MQLIB_API bool BuffStackTest(SPELL* aSpell, SPELL* bSpell, bool bIgnoreTriggeringEffects = false, bool bTriggeredEffectCheck = false);
MQLIB_API uint32_t GetItemTimer(CONTENTS* pItem);
MQLIB_API CONTENTS* GetItemContentsBySlotID(int dwSlotID);
MQLIB_API CONTENTS* GetItemContentsByName(const char* ItemName);
MQLIB_API DWORD GetAvailableSlots(CONTENTS* pContainer, CONTENTS* pItem, int *firstavailableslot);
MQLIB_API bool LoH_HT_Ready();

/* MQ2DATAVARS */
MQLIB_API char* GetFuncParam(const char* szMacroLine, int ParamNum, char* szParamName, size_t ParamNameLen, char* szParamType, size_t ParamTypeLen);
MQLIB_API MQDataVar* FindMQ2DataVariable(const char* Name);
MQLIB_API bool AddMQ2DataVariable(const char* Name, const char* Index, MQ2Type* pType, MQDataVar** ppHead, const char* Default);
MQLIB_API bool AddMQ2DataVariableFromData(const char* Name, const char* Index, MQ2Type* pType, MQDataVar** ppHead, MQTypeVar Default);
MQLIB_API MQDataVar** FindVariableScope(const char* Name);
MQLIB_API bool DeleteMQ2DataVariable(const char* Name);
MQLIB_API void ClearMQ2DataVariables(MQDataVar** ppHead);
MQLIB_API void NewDeclareVar(SPAWNINFO* pChar, char* szLine);
MQLIB_API void NewDeleteVarCmd(SPAWNINFO* pChar, char* szLine);
MQLIB_API void NewVarset(SPAWNINFO* pChar, char* szLine);
MQLIB_API void NewVarcalc(SPAWNINFO* pChar, char* szLine);
MQLIB_API void NewVardata(SPAWNINFO* pChar, char* szLine);
MQLIB_API void DropTimers();

/*                 */

MQLIB_API bool LoadCfgFile(const char* Filename, bool Delayed = FromPlugin);
MQLIB_API char* GetFriendlyNameForGroundItem(PGROUNDITEM pItem, char* szName, size_t BufferSize);
MQLIB_API void ClearSearchSpawn(MQSpawnSearch* pSearchSpawn);
MQLIB_API SPAWNINFO* NthNearestSpawn(MQSpawnSearch* pSearchSpawn, int Nth, SPAWNINFO* pOrigin, bool IncludeOrigin = false);
MQLIB_API int CountMatchingSpawns(MQSpawnSearch* pSearchSpawn, SPAWNINFO* pOrigin, bool IncludeOrigin = false);
MQLIB_API SPAWNINFO* SearchThroughSpawns(MQSpawnSearch* pSearchSpawn, SPAWNINFO* pChar);
MQLIB_API bool SpawnMatchesSearch(MQSpawnSearch* pSearchSpawn, SPAWNINFO* pChar, SPAWNINFO* pSpawn);
MQLIB_API bool SearchSpawnMatchesSearchSpawn(MQSpawnSearch* pSearchSpawn1, MQSpawnSearch* pSearchSpawn2);
MQLIB_API char* ParseSearchSpawnArgs(char* szArg, char* szRest, MQSpawnSearch* pSearchSpawn);
MQLIB_API void ParseSearchSpawn(const char* Buffer, MQSpawnSearch* pSearchSpawn);
MQLIB_API char* FormatSearchSpawn(char* Buffer, size_t BufferSize, MQSpawnSearch* pSearchSpawn);
MQLIB_API bool IsPCNear(SPAWNINFO* pSpawn, float Radius);
MQLIB_API bool IsInGroup(SPAWNINFO* pSpawn, bool bCorpse = false);
MQLIB_API bool IsInFellowship(SPAWNINFO* pSpawn, bool bCorpse = false);
MQLIB_API bool IsInRaid(SPAWNINFO* pSpawn, bool bCorpse = false);
MQLIB_API bool IsAlert(SPAWNINFO* pChar, SPAWNINFO* pSpawn, uint32_t id);
MQLIB_API bool GetClosestAlert(SPAWNINFO* pSpawn, uint32_t id);
MQLIB_API bool IsAlert(SPAWNINFO* pChar, SPAWNINFO* pSpawn, uint32_t List);
MQLIB_API bool CheckAlertForRecursion(MQSpawnSearch* pSearchSpawn, uint32_t id);
MQLIB_API void WriteFilterNames();
MQLIB_API void RewriteSubstitutions();
MQLIB_API void RewriteAliases();
MQLIB_API void WriteAliasToIni(const char* Name, const char* Command);
MQLIB_API int FindSpellListByName(const char* szName);
MQLIB_API float StateHeightMultiplier(DWORD StandState);
extern void SuperWhoDisplay(SPAWNINFO* pChar, MQSpawnSearch* pSearchSpawn, DWORD Color);
extern void SuperWhoDisplay(SPAWNINFO* pSpawn, DWORD Color);

MQLIB_API bool        Include(const char* szFile, int* LineNumber);
MQLIB_API const char* GetFullZone(int ZoneID);
MQLIB_API int         GetZoneID(const char* ZoneShortName);
MQLIB_API const char* GetShortZone(int ZoneID);
MQLIB_API float       DistanceToSpawn3D(SPAWNINFO* pChar, SPAWNINFO* pSpawn);
MQLIB_API float       EstimatedDistanceToSpawn(SPAWNINFO* pChar, SPAWNINFO* pSpawn);
MQLIB_API bool        PlayerHasAAAbility(int AAIndex);
MQLIB_API const char* GetAANameByIndex(int AAIndex);
MQLIB_API int         GetAAIndexByName(const char* AAName);
MQLIB_API int         GetAAIndexByID(int ID);
MQLIB_API int         GetSkillIDFromName(const char* name);
MQLIB_API bool        InHoverState();
MQLIB_API int         GetGameState();
MQLIB_API int         GetWorldState();
MQLIB_API float       GetMeleeRange(PlayerClient*, PlayerClient*);
MQLIB_API uint32_t    GetSpellGemTimer(int nGem);
MQLIB_API uint32_t    GetSpellBuffTimer(int SpellID);
MQLIB_API bool        HasExpansion(int nExpansion);
MQLIB_API void        ListMercAltAbilities();
MQLIB_API CONTENTS*   FindItemBySlot(short InvSlot, short BagSlot = -1, ItemContainerInstance location = eItemContainerPossessions);
MQLIB_API CONTENTS*   FindItemBySlot2(const ItemGlobalIndex& idx);
MQLIB_API CONTENTS*   FindItemByName(const char* pName, bool bExact = false);
MQLIB_API CONTENTS*   FindItemByID(int ItemID);
MQLIB_API int         FindItemCountByName(const char* pName, bool bExact = false);
MQLIB_API int         FindItemCountByID(int ItemID);
MQLIB_API CONTENTS*   FindBankItemByName(const char* pName, bool bExact);
MQLIB_API CONTENTS*   FindBankItemByID(int ItemID);
MQLIB_API int         FindBankItemCountByName(const char* pName, bool bExact);
MQLIB_API int         FindBankItemCountByID(int ItemID);
MQLIB_API CInvSlot*   GetInvSlot(DWORD type, short Invslot, short Bagslot = -1);
MQLIB_API CInvSlot*   GetInvSlot2(const ItemGlobalIndex& idx);
MQLIB_API bool        IsItemInsideContainer(CONTENTS* pItem);
MQLIB_API bool        PickupItem(ItemContainerInstance type, CONTENTS* pItem);
MQLIB_API bool        DropItem(ItemContainerInstance type, short InvSlot, short Bagslot);
MQLIB_API bool        DropItem2(const ItemGlobalIndex& index);
MQLIB_API bool        ItemOnCursor();
MQLIB_API bool        OpenContainer(CONTENTS* pItem, bool hidden, bool flag = false);
MQLIB_API bool        CloseContainer(CONTENTS* pItem);
MQLIB_API int         GetTargetBuffByCategory(int category, unsigned int classmask = 0, int startslot = 0);
MQLIB_API int         GetTargetBuffBySubCat(const char* subcat, unsigned int classmask = 0, int startslot = 0);
MQLIB_API int         GetTargetBuffBySPA(int spa, bool bIncrease, int startslot = 0);
MQLIB_API bool        HasCachedTargetBuffSubCat(const char* subcat, SPAWNINFO* pSpawn, TargetBuff* pcTargetBuff, unsigned int classmask = 0);
MQLIB_API bool        HasCachedTargetBuffSPA(int spa, bool bIncrease, SPAWNINFO* pSpawn, TargetBuff* pcTargetBuff);
MQLIB_API int         GetSelfBuffByCategory(int category, unsigned int classmask = 0, int startslot = 0);
MQLIB_API int         GetSelfBuffBySubCat(const char* subcat, unsigned int classmask = 0, int startslot = 0);
MQLIB_API int         GetSelfBuffBySPA(int spa, bool bIncrease, int startslot = 0);
MQLIB_API int         GetSelfShortBuffBySPA(int spa, bool bIncrease, int startslot = 0);
MQLIB_API bool        IsSpellUsableForClass(SPELL* pSpell, unsigned int classmask = 0);
MQLIB_API bool        IsAegoSpell(SPELL* pSpell);
MQLIB_API int         GetSpellCategory(SPELL* pSpell);
MQLIB_API int         GetSpellSubcategory(SPELL* pSpell);
MQLIB_API SPELL*      GetSpellParent(int id);
MQLIB_API HMODULE GetCurrentModule();
MQLIB_API DWORD CALLBACK MQ2End(void* lpParameter);
MQLIB_API DWORD CALLBACK GetlocalPlayerOffset();
MQLIB_API void MQ2Shutdown();
MQLIB_API HANDLE hUnloadComplete;
MQLIB_API HANDLE hLoadComplete;

///////////////////////////////////////////////////////////////////////////////////////////////////
// Functions that were built into commands and people used DoCommand to execute                  //

MQLIB_API void AttackRanged(PlayerClient* pRangedTarget = pTarget);
MQLIB_API void UseAbility(const char* sAbility);
MQLIB_OBJECT MQMacroBlockPtr GetNextMacroBlock();
MQLIB_OBJECT MQMacroBlockPtr GetCurrentMacroBlock();
MQLIB_API int GetMacroBlockCount();
MQLIB_API void EndAllMacros();
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

// Parse Operations
std::string HandleParseParam(std::string_view strOriginal, bool bParseOnce = false);

enum class ModifyMacroMode { Default, Wrap, WrapNoDoubles };

std::string ModifyMacroString(std::string_view strOriginal, bool bParseOnce = false,
	ModifyMacroMode iOperation = ModifyMacroMode::Default);

MQLIB_API bool Calculate(const char* szFormula, double& Dest);

constexpr int LIGHT_COUNT = 13;
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

MQLIB_API void memchecks_tramp(char*, DWORD, void*, DWORD, bool);
MQLIB_API void memchecks(char*, DWORD, void*, DWORD, bool);
MQLIB_API void InitializeLoginPulse();
MQLIB_API void RemoveAutoBankMenu();
MQLIB_API bool WillFitInBank(CONTENTS* pContent);
MQLIB_API bool WillFitInInventory(CONTENTS* pContent);
MQLIB_API void AddAutoBankMenu();
MQLIB_API void AutoBankPulse();
MQLIB_API bool Anonymize(char* name, int maxlen, int NameFlag = 0);
MQLIB_API bool Anonymize2(CXStr& name, int NameFlag = 0);
MQLIB_API void UpdatedMasterLooterLabel();

MQLIB_API int MQ2ExceptionFilter(unsigned int code, struct _EXCEPTION_POINTERS* ex, const char * description, ...);

} // namespace mq
