#define VersionString "20031120a"
#define DebugHeader "[MQ2]"
#define LoadedString "MQ2 Loaded."
#define ToUnloadString "MQ2 Unloading..."
#define UnloadedString "MQ2 Unloaded."

#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x510
#define DIRECTINPUT_VERSION 0x800

// Windows Header Files:
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "..\Dxsdk81\include\dinput.h"
#include <time.h>
#include <io.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <winsock.h>
#include <math.h>

#include "..\Detours\inc\detours.h" 
#include "eqgame.h"

#ifdef EQLIB_EXPORTS
#define EQLIB_API extern "C" __declspec(dllexport)
#define EQLIB_VAR extern "C" __declspec(dllexport)
#define EQLIB_OBJECT __declspec(dllexport)
#else
#define EQLIB_API extern "C" __declspec(dllimport)
#define EQLIB_VAR extern "C" __declspec(dllimport)
#define EQLIB_OBJECT __declspec(dllimport)
#endif

#define REVERSE_DETOUR(function,offset) __declspec(naked) function\
{\
	__asm{mov eax, offset};\
	__asm{jmp eax};\
}

#define REVERSE_VIRTUAL_DETOUR(function,offset) __declspec(naked) function\
{\
	__asm{mov eax, [ecx]};\
	__asm{lea eax, [eax+offset]};\
	__asm{mov eax, [eax]};\
	__asm{jmp eax};\
}

#ifndef DOUBLE
typedef double DOUBLE;
#endif
#ifndef THIS_
#define THIS_                   INTERFACE FAR* This,
#endif

#ifdef DEBUG_TRY
#define DebugTry(x) DebugSpew("Trying %s",#x);x;DebugSpew("%s complete",#x)
#else
#define DebugTry(x) x
#endif


#define MAX_VARNAME 64
#define MAX_STRING            2048


#include "EQData.h"
#include "EQUIStructs.h"
#include "EQClasses.h"

#include "MQ2Prototypes.h"
#include "MQ2Internal.h"
#include "MQ2Globals.h"


/* API FOR THE INJECTOR ONLY */
EQLIB_API VOID  InjectEnable();
EQLIB_API VOID  InjectDisable();

/* CHAT HOOK */
EQLIB_API VOID InitializeChatHook();
EQLIB_API VOID ShutdownChatHook();

/* DETOURING API */
EQLIB_API VOID InitializeMQ2Detours();
EQLIB_API VOID ShutdownMQ2Detours();
EQLIB_API BOOL AddDetour(DWORD address, PBYTE pfDetour=0, PBYTE pfTrampoline=0);
EQLIB_API VOID RemoveDetour(DWORD address);

/* PLUGIN HANDLING */
EQLIB_API VOID InitializeMQ2Plugins();
EQLIB_API DWORD LoadMQ2Plugin(const PCHAR pszFilename);
EQLIB_API BOOL UnloadMQ2Plugin(const PCHAR pszFilename);
EQLIB_API VOID ShutdownMQ2Plugins();
EQLIB_API VOID WriteChatColor(PCHAR Line, DWORD Color=USERCOLOR_DEFAULT, DWORD Filter=0);
EQLIB_API VOID PulsePlugins();
EQLIB_API VOID PluginsZoned();
EQLIB_API VOID PluginsIncomingChat(PCHAR Line, DWORD Color);
EQLIB_API VOID RewriteMQ2Plugins(VOID);
EQLIB_API VOID PluginsCleanUI();
EQLIB_API VOID PluginsSetGameState(DWORD GameState);
EQLIB_API VOID PluginsDrawHUD();

/* DIRECT INPUT */
EQLIB_API VOID InitializeMQ2DInput();
EQLIB_API VOID ShutdownMQ2DInput();

/* CLEAN UI */
EQLIB_API VOID InitializeDisplayHook();
EQLIB_API VOID ShutdownDisplayHook();

/* COMMAND HANDLING */
EQLIB_API VOID InitializeMQ2Commands();
EQLIB_API VOID ShutdownMQ2Commands();
EQLIB_API VOID AddCommand(PCHAR Command, fEQCommand Function, BOOL EQ=0, BOOL Parse=1);
EQLIB_API VOID AddParm(PCHAR Name, fMQParm Function);
EQLIB_API VOID RemoveParm(PCHAR Name);
EQLIB_API VOID AddAlias(PCHAR ShortCommand, PCHAR LongCommand);
EQLIB_API BOOL RemoveAlias(PCHAR ShortCommand);
EQLIB_API BOOL RemoveCommand(PCHAR Command);

/* MACRO COMMANDS */
EQLIB_API VOID DumpStack                           (PSPAWNINFO,PCHAR);
EQLIB_API VOID EndMacro                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID Echo									(PSPAWNINFO,PCHAR);



/* MACRO PARSING */
#define PMP_ERROR_BADPARM 10000
EQLIB_API PCHAR ParseMacroParameter(PSPAWNINFO pChar, PCHAR szOriginal);
EQLIB_API VOID GracefullyEndBadMacro(PSPAWNINFO pChar, PMACROBLOCK pBadLine, PCHAR szFormat, ...);
EQLIB_API VOID FailIf(PSPAWNINFO pChar, PCHAR szCommand, PMACROBLOCK pStartLine, BOOL All=FALSE);
EQLIB_API VOID InitializeParser();
EQLIB_API VOID ShutdownParser();

/* MOUSE */
EQLIB_API VOID MouseClickL(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID MouseClickR(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API BOOL IsMouseWaiting(VOID);
EQLIB_API BOOL IsMouseWaitingForButton();

/* PULSING */
EQLIB_API VOID InitializeMQ2Pulse();
EQLIB_API VOID ShutdownMQ2Pulse();

/* UTILITIES */
EQLIB_API VOID ClearSearchSpawn(PSEARCHSPAWN pSearchSpawn);

EQLIB_API PCHARINFO GetCharInfo(VOID);
EQLIB_API VOID DebugSpew(PCHAR szFormat, ...);
EQLIB_API VOID DebugSpewAlways(PCHAR szFormat, ...);
EQLIB_API PCHAR GetNextArg(PCHAR szLine, DWORD dwNumber = 1, BOOL CSV = FALSE, CHAR Separator = 0);
EQLIB_API PCHAR GetArg(PCHAR szDest, PCHAR szSrc, DWORD dwNumber, BOOL LeaveQuotes = FALSE, BOOL ToParen = FALSE, BOOL CSV = FALSE, CHAR Separator = 0, BOOL AnyNonAlphaNum = FALSE);
EQLIB_API VOID AddCustomEvent(PEVENTLIST pEList, PCHAR szLine);
EQLIB_API PCHAR GetFuncParamName(PCHAR szMacroLine, DWORD ParamNum, PCHAR szParamName);
EQLIB_API FLOAT DistanceToSpawn(PSPAWNINFO pChar, PSPAWNINFO pSpawn);
EQLIB_API PCHAR GetEQPath(PCHAR szBuffer);
EQLIB_API VOID DoCommand(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID AppendCXStr(PCXSTR *cxstr, PCHAR text); 
EQLIB_API VOID SetCXStr(PCXSTR *cxstr, PCHAR text); 
EQLIB_API VOID GetCXStr(PCXSTR pCXStr, PCHAR szBuffer, DWORD maxlen=MAX_STRING);
EQLIB_API DWORD MQToSTML(PCHAR in, PCHAR out, DWORD maxlen=MAX_STRING, DWORD ColorOverride=0xFFFFFF);
EQLIB_API VOID StripMQChat(PCHAR in, PCHAR out);
EQLIB_API VOID STMLToPlainText(PCHAR in, PCHAR out);
EQLIB_API PCHAR GetSubFromLine(PMACROBLOCK pLine, PCHAR szSub);
EQLIB_API PCHAR GetFilenameFromFullPath(PCHAR Filename);
EQLIB_API BOOL CompareTimes(PCHAR RealTime, PCHAR ExpectedTime);
EQLIB_API VOID AddFilter(PCHAR szFilter, DWORD Length, PBOOL pEnabled);
EQLIB_API VOID DefaultFilters(VOID);
EQLIB_API PCHAR ConvertHotkeyNameToKeyName(PCHAR szName);
EQLIB_API VOID CheckChatForEvent(PCHAR szMsg);
EQLIB_API VOID ConvertItemTags(CXStr &cxstr);



EQLIB_API PMACROBLOCK AddMacroLine(PCHAR szLine);
EQLIB_API PCHAR GetSpellByID(DWORD dwSpellID);
EQLIB_API PCHAR GetLightForSpawn(PSPAWNINFO pSpawn);
EQLIB_API DWORD GetSpellDuration(PSPELLLIST pSpell, PSPAWNINFO pSpawn);
EQLIB_API DWORD GetDeityTeamByID(DWORD DeityID);
EQLIB_API DWORD ConColorToARGB(DWORD ConColor);
EQLIB_API DWORD ConColor(WORD CharLevel, WORD SpawnLevel);
EQLIB_API DWORD GetMaxMana(VOID);
EQLIB_API DWORD GetMaxHPS(VOID);
EQLIB_API DWORD GetCurHPS(VOID);
EQLIB_API PSPELLLIST GetSpellByName(PCHAR szName);
EQLIB_API PCHAR GetGuildByID(DWORD GuildID);
EQLIB_API DWORD GetGuildIDByName(PCHAR szGuild);
EQLIB_API PCONTENTS GetEnviroContainer();
EQLIB_API PEQCONTAINERWINDOW FindContainerForContents(PCONTENTS pContents);
EQLIB_API PSPAWNINFO FindMount(PSPAWNINFO pSpawn);
EQLIB_API FLOAT FindSpeed(PSPAWNINFO pSpawn);
EQLIB_API VOID GetItemLinkHash(PCONTENTS Item, PCHAR Buffer);
EQLIB_API VOID GetItemLink(PCONTENTS Item, PCHAR Buffer);
EQLIB_API VOID SendEQMessage(DWORD PacketType, PVOID pData, DWORD Length);
EQLIB_API PCHAR GetLoginName();

/* USERVARS */
EQLIB_API VOID FreeVarStrings(PVARSTRINGS pVarStrings);
EQLIB_API VOID FreeVarArrays();
EQLIB_API VOID FreeTimers();
EQLIB_API PTIMER GetTimer(PCHAR szName, BOOL Create = FALSE);
EQLIB_API PCHAR GetEventStr(PEVENTSTACK pEvent, PCHAR szName, BOOL Create = FALSE);
EQLIB_API PCHAR GetMacroStr(PCHAR szName, BOOL Create = FALSE);
EQLIB_API PCHAR GetLocalStr(PCHAR szName, BOOL Create = FALSE);
EQLIB_API PCHAR GetStackStr(PCHAR szName, BOOL Create = FALSE);
EQLIB_API PVARARRAYS GetArray(PCHAR szName, BOOL Create = FALSE);
EQLIB_API PCHAR GetArrayStr(PVARARRAYS pArray, DWORD Id1, DWORD Id2=0, BOOL Create = FALSE);
EQLIB_API VOID GetVariable(PCHAR szVar, PCHAR *szResult, PTIMER *pTimer);
EQLIB_API VOID DropTimers(VOID);
EQLIB_API BOOL SearchVariables(PCHAR szVar,PCHAR szOutput,PVARSTRINGS pVarStrings);
EQLIB_API BOOL SearchTimers(PCHAR szVar,PCHAR szOutput);
EQLIB_API BOOL SearchArrays(PCHAR szVar,PCHAR szOutput);
EQLIB_API VOID CheckVariableRecursion(PCHAR szVar);
EQLIB_API BOOL IsVariableDefined(PCHAR szVar);

/* COMMANDS */
EQLIB_API PCHAR GetFriendlyNameForGroundItem(PGROUNDITEM pItem);
EQLIB_API VOID ClearSearchSpawn(PSEARCHSPAWN pSearchSpawn);
EQLIB_API PSPAWNINFO SearchThroughSpawns(PSEARCHSPAWN pSearchSpawn, PSPAWNINFO pChar);
EQLIB_API BOOL SpawnMatchesSearch(PSEARCHSPAWN pSearchSpawn, PSPAWNINFO pChar, PSPAWNINFO pSpawn);
EQLIB_API PCHAR ParseSearchSpawnArgs(PCHAR szArg, PCHAR szRest, PSEARCHSPAWN pSearchSpawn);
EQLIB_API VOID ParseSearchSpawn(PCHAR Buffer, PSEARCHSPAWN pSearchSpawn);
EQLIB_API PCHAR FormatSearchSpawn(PCHAR Buffer, PSEARCHSPAWN pSearchSpawn);
EQLIB_API BOOL IsPCNear(PSPAWNINFO pSpawn, FLOAT Radius);
EQLIB_API BOOL IsInGroup(PSPAWNINFO pSpawn);
EQLIB_API BOOL IsAlert(PSPAWNINFO pChar, PSPAWNINFO pSpawn, DWORD List);


EQLIB_API VOID        OverwriteTable          (DWORD Address);
EQLIB_API DWORD       Include                 (PCHAR szFile);
EQLIB_API PCHAR       GetFullZone             (DWORD ZoneID);
EQLIB_API DWORD       GetZoneID               (PCHAR ZoneShortName);
EQLIB_API PCHAR       GetShortZone            (DWORD ZoneID);
EQLIB_API PCHAR       CleanupName             (PCHAR szName, BOOL Article = TRUE);
EQLIB_API VOID        SwapSWho                (PSWHOSORT pSWho1, PSWHOSORT pSWho2);
EQLIB_API VOID        SortSWho                (PSWHOSORT pSWhoSort, DWORD SpawnCount, DWORD SortBy = 0);
EQLIB_API VOID        SuperWhoFindPets        (PSPAWNINFO pChar, WORD SpawnID);
EQLIB_API VOID        SuperWhoDisplay         (PSPAWNINFO pChar, PSEARCHSPAWN pFilter, PSPAWNINFO psTarget, WORD Padding = 0, DWORD Color = 0);
EQLIB_API FLOAT       DistanceToSpawn         (PSPAWNINFO pChar, PSPAWNINFO pSpawn);
EQLIB_API FLOAT       DistanceToSpawn3D       (PSPAWNINFO pChar, PSPAWNINFO pSpawn);
EQLIB_API FLOAT       EstimatedDistanceToSpawn(PSPAWNINFO pChar, PSPAWNINFO pSpawn);
EQLIB_API PMACROBLOCK AddMacroLine            (PCHAR szLine);
EQLIB_API VOID        GracefullyEndBadMacro   (PSPAWNINFO pChar, PMACROBLOCK pBadLine, PCHAR szFormat, ...);
EQLIB_API PSPAWNINFO  GetClosestAlert         (PSPAWNINFO pChar,DWORD List, DWORD* pdwCount);
EQLIB_API VOID        FreeAlertList           (PALERTLIST pAlertList);
EQLIB_API DWORD       ConColor                (WORD CharLevel, WORD SpawnLevel);
EQLIB_API DWORD WINAPI InsertCommands         (LPVOID lpParameter);
EQLIB_API VOID        UpdateMonitoredSpawns   (VOID);
EQLIB_API PCHAR       GetModel                (PSPAWNINFO pSpawn, DWORD Slot);
EQLIB_API PSPAWNINFO  GetPet                  (DWORD OwnerID);
EQLIB_API BOOL        IfCompare               (PCHAR szCond);



/* PARMS */

EQLIB_API DWORD parmGetLastFindSlot					(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmCursor							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmItem								(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmEquip								(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmGroup								(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmTarget							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmSpawn							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmSearchSpawn					(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmChar							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmHeading						(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmID								(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmMouse							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmChar							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmSpell							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmReturn							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmZone							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmFind							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmAlert							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmGM								(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmCombat							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmFreeInv						(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmDistance						(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmRand							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmGetLastError					(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmLastTell						(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmLastCommand					(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmInvPanel						(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmIf								(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmIfN							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmMerchantName					(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmMerchantXXX					(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmCorpse							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmRunning						(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmTime							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmDate							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmPack							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmArg							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmLeft							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmMid							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmRight							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmInstr							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmStrLen							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmUcase							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmLcase							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmSpawnName						(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmCount							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmCalc							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmSpellItem						(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmInt							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmAbs							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmSin							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmCos							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmTan							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmAsin							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmAcos							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmAtan							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmDoor							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmGround							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmHex							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmDec							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmNot							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmIni							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmMerchant						(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmFinditemBank					(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmFinditem						(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmEQPath							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmMacroPath						(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmMQPath							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmLogPath						(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmSqrt							(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmDefined						(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmEnvOpen						(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmGiveWnd						(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmSelectedItem					(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmServerName						(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmLoginName						(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmGameState						(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DWORD parmBanker						(PCHAR, PCHAR, PSPAWNINFO);
EQLIB_API DOUBLE Calculate(PCHAR szFormula);

/* COMMANDS */
EQLIB_API VOID Alert                               (PSPAWNINFO,PCHAR);
EQLIB_API VOID Alias                               (PSPAWNINFO,PCHAR);
EQLIB_API VOID BankList                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID Breakin                             (PSPAWNINFO,PCHAR);
EQLIB_API VOID BuyItem                             (PSPAWNINFO,PCHAR);
EQLIB_API VOID Call                                (PSPAWNINFO,PCHAR);
EQLIB_API VOID CharInfo                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID Cast                                (PSPAWNINFO,PCHAR);
EQLIB_API VOID Cleanup                             (PSPAWNINFO,PCHAR);
EQLIB_API VOID Click                               (PSPAWNINFO,PCHAR);
EQLIB_API VOID DebugSpewFile                       (PSPAWNINFO,PCHAR);
EQLIB_API VOID DeclareVar                          (PSPAWNINFO,PCHAR);
EQLIB_API VOID Delay                               (PSPAWNINFO,PCHAR);
EQLIB_API VOID EQDestroyHeldItemOrMoney				(PSPAWNINFO,PCHAR);
EQLIB_API VOID DisplayLoginName						(PSPAWNINFO,PCHAR);
EQLIB_API VOID DisplayZem                          (PSPAWNINFO,PCHAR);
EQLIB_API VOID DoAbility                           (PSPAWNINFO,PCHAR);
EQLIB_API VOID DoEvents                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID Doors                               (PSPAWNINFO,PCHAR);
EQLIB_API VOID DoorTarget                          (PSPAWNINFO,PCHAR);
EQLIB_API VOID DumpStack                           (PSPAWNINFO,PCHAR);
EQLIB_API VOID Echo                                (PSPAWNINFO,PCHAR);
EQLIB_API VOID EditMacro                           (PSPAWNINFO,PCHAR);
EQLIB_API VOID EndMacro                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID Face                                (PSPAWNINFO,PCHAR);
EQLIB_API VOID Filter                              (PSPAWNINFO,PCHAR);
EQLIB_API VOID FindItem                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID For                                 (PSPAWNINFO,PCHAR);
EQLIB_API VOID Goto                                (PSPAWNINFO,PCHAR);
EQLIB_API VOID Help                                (PSPAWNINFO,PCHAR);
EQLIB_API VOID Hotkey                              (PSPAWNINFO,PCHAR);
EQLIB_API VOID Identify                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID If                                  (PSPAWNINFO,PCHAR);
EQLIB_API VOID IniOutput                           (PSPAWNINFO,PCHAR);
EQLIB_API VOID Items                               (PSPAWNINFO,PCHAR);
EQLIB_API VOID ItemTarget                          (PSPAWNINFO,PCHAR);
EQLIB_API VOID KeepKeys                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID WindowState							(PSPAWNINFO,PCHAR);
EQLIB_API VOID ListMacros                          (PSPAWNINFO,PCHAR);
EQLIB_API VOID LoadSpells                          (PSPAWNINFO,PCHAR);
EQLIB_API VOID Location                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID Look                                (PSPAWNINFO,PCHAR);
EQLIB_API VOID Macro                               (PSPAWNINFO,PCHAR);
EQLIB_API VOID MacroBeep                           (PSPAWNINFO,PCHAR);
EQLIB_API VOID MacroLog                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID MacroPause                          (PSPAWNINFO,PCHAR);
EQLIB_API VOID MemSpell                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID MouseClickL                         (PSPAWNINFO,PCHAR);
EQLIB_API VOID MouseClickR                         (PSPAWNINFO,PCHAR);
EQLIB_API VOID MouseTo                             (PSPAWNINFO,PCHAR);
EQLIB_API VOID MQMsgBox                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID MyVarAdd                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID MyVarAnd                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID MyVarCat                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID MyVarOr                             (PSPAWNINFO,PCHAR);
EQLIB_API VOID MyVarSub                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID Next                                (PSPAWNINFO,PCHAR);
EQLIB_API VOID PluginCommand						(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID Press                               (PSPAWNINFO,PCHAR);
EQLIB_API VOID Return                              (PSPAWNINFO,PCHAR);
EQLIB_API VOID SelectItem                          (PSPAWNINFO,PCHAR);
EQLIB_API VOID SellItem                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID SendKey                             (PSPAWNINFO,PCHAR);
EQLIB_API VOID SetAutoRun                          (PSPAWNINFO,PCHAR);
EQLIB_API VOID SetError                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID Skills                              (PSPAWNINFO,PCHAR);
EQLIB_API VOID SuperWho                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID SuperWhoTarget                      (PSPAWNINFO,PCHAR);
EQLIB_API VOID SWhoFilter							(PSPAWNINFO,PCHAR);
EQLIB_API VOID Target                              (PSPAWNINFO,PCHAR);
EQLIB_API VOID Unload                              (PSPAWNINFO,PCHAR);
EQLIB_API VOID UpdateItemInfo                      (PSPAWNINFO,PCHAR);
EQLIB_API VOID VarCalc                             (PSPAWNINFO,PCHAR);
EQLIB_API VOID VarLShift                           (PSPAWNINFO,PCHAR);
EQLIB_API VOID VarRShift                           (PSPAWNINFO,PCHAR);
EQLIB_API VOID VarSet                              (PSPAWNINFO,PCHAR);
EQLIB_API VOID Where                               (PSPAWNINFO,PCHAR);
EQLIB_API VOID ZapVars                             (PSPAWNINFO,PCHAR);
// OTHER SHIT

#define LIGHT_COUNT     13
#define MAX_COMBINES    52
#define MAX_ITEMTYPES   53

#define GAMESTATE_CHARSELECT    1
#define GAMESTATE_SOMETHING     4
#define GAMESTATE_INGAME        5
#define GAMESTATE_PRECHARSELECT 6
#define GAMESTATE_LOGGINGIN     253
#define GAMESTATE_UNLOADING     255

#define MAX_ITEM4xx			416

