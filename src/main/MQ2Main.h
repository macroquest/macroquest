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

#pragma once

#include "pch.h"
#include "MQ2MainBase.h"

#include "blech/Blech.h"
#include "eqlib/EQLib.h"
using namespace eqlib;

//#define MQ2_PROFILING

// uncomment this line to turn off the single-line benchmark macro
// #define DISABLE_BENCHMARKS

#define LoadedString           "MacroQuest Loaded."
#define ToUnloadString         "MacroQuest Unloading..."
#define UnloadedString         "MacroQuest Unloaded."

//
// EQ Version selection
//

// This is the MQNEXT build, it is here to help plugins conditionally compile against
// the new interfaces
#define MQNEXT

#ifdef DEBUG_TRY
#define DebugTry(x) DebugSpew("Trying %s",#x);x;DebugSpew("%s complete",#x)
#else
#define DebugTry(x) x
#endif

#define MAX_VARNAME           64

#include "mq/base/Traits.h"
#include "../common/Common.h"
#include "MQ2Prototypes.h"
#include "MQ2Internal.h"
#include "MQ2Globals.h"
#include "MQ2Inlines.h"
#include "MQ2Commands.h"
#include "MQ2DataContainers.h"
#include "MQ2Utilities.h"
#include "datatypes/MQ2DataTypes.h"

// Link up ImGui
#include <imgui/imgui.h>
#if defined(_M_AMD64)
#pragma comment(lib, "imgui-64.lib")
#else
#pragma comment(lib, "imgui.lib")
#endif // defined(_WIN64)

// TODO: Move these to mq/Plugin.h so that they are not globally included -- include them
// only where they are needed.

#include "mq/utils/Benchmarks.h"
#include "mq/utils/Keybinds.h"

#include "mq/api/Main.h"
#include "mq/api/DetourAPI.h"
#include "mq/api/MacroAPI.h"
#include "mq/api/PluginAPI.h"

namespace mq {

// Initialize/shutdown subsystems
void ShutdownMQ2Benchmarks();
void InitializeMQ2Benchmarks();

void InitializeDisplayHook();
void ShutdownDisplayHook();

void InitializeMQ2Pulse();
void ShutdownMQ2Pulse();

void InitializeChatHook();
void ShutdownChatHook();

// Logging / Console output
MQLIB_API void WriteChatColor(const char* Line, int Color = USERCOLOR_DEFAULT, int Filter = 0);
MQLIB_API void WriteChatf(const char* Format, ...);
MQLIB_API void WriteChatColorf(const char* szFormat, int color, ...);

MQLIB_API DEPRECATE("Use WriteChatf instead")
void WriteChatfSafe(const char* szFormat, ...);

MQLIB_API void DebugSpew(const char* szFormat, ...);
MQLIB_API void DebugSpewAlways(const char* szFormat, ...);
MQLIB_API void DebugSpewAlwaysFile(const char* szFormat, ...);
MQLIB_API void DebugSpewNoFile(const char* szFormat, ...);

/* SPAWN HANDLING */
MQLIB_API bool IsTargetable(SPAWNINFO* pSpawn);
MQLIB_API bool AreNameSpritesCustomized();

/* OVERLAY */
MQLIB_API bool IsImGuiForeground();
MQLIB_API void SetOverlayEnabled(bool visible);
MQLIB_API bool IsOverlayEnabled();

using fPanelDrawFunction = void(*)();
MQLIB_API void AddSettingsPanel(const char* name, fPanelDrawFunction drawFunction);
MQLIB_API void RemoveSettingsPanel(const char* name);

/* EQ Menu */
MQLIB_OBJECT void AddCascadeMenuItem(const char* name, const char* keyBind, int icon = -1);
MQLIB_OBJECT void AddCascadeMenuItem(const char* name, fCascadeItemFunction function, int icon = -1);
MQLIB_OBJECT void RemoveCascadeMenuItem(const char* name);

/* WINDOWS */
MQLIB_API HWND GetEQWindowHandle();
MQLIB_API void ReinitializeWindowList();
MQLIB_API void RemoveXMLFile(const char* filename);
MQLIB_API void AddXMLFile(const char* filename);
MQLIB_API DEPRECATE("IsXMLFilePresent does not ensure that the content of the XML file is available. Add the XML file with AddXMLFile and use IsScreenPieceLoaded with the name of the screen piece to check if it was loaded successfully")
bool IsXMLFilePresent(const char* filename);
MQLIB_API bool SendWndClick(const char* WindowName, const char* ScreenID, const char* ClickNotification);
MQLIB_API bool SendWndNotification(const char* WindowName, const char* ScreenID, int Notification, void* Data = nullptr);
MQLIB_API bool SendTabSelect(const char* WindowName, const char* ScreenID, int Value);
MQLIB_API CXWnd* FindMQ2Window(const char* Name);
MQLIB_API CXWnd* FindMQ2WindowPath(const char* Name);
MQLIB_API CXWnd* GetParentWnd(CXWnd* pWnd);
MQLIB_API bool IsScreenPieceLoaded(const char*);

MQLIB_API bool SendComboSelect(const char* WindowName, const char* ScreenID, int Value);
MQLIB_API bool SendListSelect(const char* WindowName, const char* ScreenID, int Value);
MQLIB_API bool SendListSelect2(CXWnd* pList, int ListIndex);
MQLIB_API bool SendWndClick2(CXWnd* pWnd, const char* ClickNotification);

MQLIB_API void CreateMQ2NewsWindow();
MQLIB_API void DeleteMQ2NewsWindow();

/* CHAT HOOK */
MQLIB_API void dsp_chat_no_events(const char* Text, int Color, bool EqLog = true, bool dopercentsubst = true);

/* CLEAN UI */
MQLIB_API void DrawHUD();


/* MOUSE */
MQLIB_API bool IsMouseWaiting();
MQLIB_API bool IsMouseWaitingForButton();
MQLIB_API bool MoveMouse(int x, int y);
MQLIB_API bool ClickMouseButton(int mouseButton); // Uses DirectInput to simulate a mouse click at the current mouse position.
MQLIB_API bool MouseToPlayer(PlayerClient* pPlayer, DWORD position, bool bClick = false);
MQLIB_API bool ClickMouseItem(const MQGroundSpawn& pGroundSpawn, bool left);
inline bool ClickMouseItem(SPAWNINFO* pChar, const MQGroundSpawn& pGroundSpawn, bool left) { return ClickMouseItem(pGroundSpawn, left); }
void MouseConsume(int mouseButton, bool pressed);

/* UTILITIES */
MQLIB_API void ConvertCR(char* Text, size_t LineLen);
MQLIB_API void DrawHUDText(const char* Text, int X, int Y, unsigned int Argb, int Font);


//----------------------------------------------------------------------------
// Argument string parsing

MQLIB_API const char* GetNextArg(const char* szLine, int dwNumber = 1, bool CSV = false, char Separator = 0);
MQLIB_API const char* GetArg(char* szDest, const char* szSrc, int dwNumber, bool LeaveQuotes = false, bool ToParen = false, bool CSV = false, char Separator = 0, bool AnyNonAlphaNum = false);
MQLIB_API const char* GetMaybeQuotedArg(char* szDest, int sizeDest, const char* szSrc, int expectedPos);

// GetNextArg that takes a non-const szLine and returns non-const. always prefer to use the const version.
inline char* GetNextArg(char* szLine, int dwNumber = 1, bool CSV = false, char Separator = 0)
{
	return (char*)GetNextArg((const char*)szLine, dwNumber, CSV, Separator);
}

//----------------------------------------------------------------------------

MQLIB_API DEPRECATE("The EQ Path is the working directory.")
char* GetEQPath(char* szBuffer, size_t len);

MQLIB_API DWORD MQToSTML(const char* in, char* out, size_t maxlen = MAX_STRING, uint32_t ColorOverride = 0xFFFFFF);
MQLIB_API void StripMQChat(const char* in, char* out);
MQLIB_OBJECT void StripMQChat(std::string_view in, char* out);
MQLIB_API void STMLToPlainText(char* in, char* out);
MQLIB_API char* GetSubFromLine(int Line, char* szSub, size_t Sublen);
MQLIB_API const char* GetFilenameFromFullPath(const char* Filename);
MQLIB_API bool CompareTimes(char* RealTime, char* ExpectedTime);
MQLIB_API void AddFilter(const char* szFilter, int Length, bool& pEnabled);
MQLIB_API void DefaultFilters();
MQLIB_API char* ConvertHotkeyNameToKeyName(char* szName);
MQLIB_API void CheckChatForEvent(const char* szMsg);
MQLIB_API int FindInvSlotForContents(ItemClient* pContents);
MQLIB_API int FindInvSlot(const char* Name, bool Exact);
MQLIB_API int FindNextInvSlot(const char* Name, bool Exact);

MQLIB_API int GetLanguageIDByName(const char* szName);
MQLIB_API int GetCurrencyIDByName(const char* szName);
MQLIB_API const char* GetSpellNameByID(int dwSpellID);
MQLIB_API EQ_Spell* GetSpellByName(std::string_view name);
MQLIB_API EQ_Spell* GetSpellByAAName(const char* szName);
MQLIB_API CAltAbilityData* GetAAById(int nAbilityId, int playerLevel = -1);
inline CAltAbilityData* GetAAByIdWrapper(int nAbilityId, int playerLevel = -1) { return GetAAById(nAbilityId, playerLevel); }
MQLIB_API int GetSpellRankByName(const char* SpellName);
MQLIB_API void TruncateSpellRankName(char* SpellName);
MQLIB_API int FindBuffIndex(std::string_view Name, int minSlot = 0, int maxSlot = -1);
MQLIB_API bool RemoveBuffByName(std::string_view buffName);
MQLIB_API bool RemoveBuffBySpellID(int buffName);
MQLIB_API bool RemoveBuffByIndex(int buffIndex);
MQLIB_API bool RemovePetBuffByName(std::string_view buffName);
MQLIB_API bool StripQuotes(char* str);
MQLIB_API int GetKeyRingCount(KeyRingType keyRingType);
MQLIB_API int GetMountCount();
MQLIB_API int GetIllusionCount();
MQLIB_API int GetFamiliarCount();
MQLIB_API int GetHeroForgeCount();
MQLIB_API int GetTeleportationItemCount();
MQLIB_API int GetActivatedItemCount();

MQLIB_API bool IsActiveAA(const char* pSpellName);
MQLIB_API CXWnd* GetAdvLootPersonalListItem(DWORD ListIndex, DWORD type);
MQLIB_API CXWnd* GetAdvLootSharedListItem(DWORD ListIndex, DWORD type);
MQLIB_API bool LootInProgress(CAdvancedLootWnd* pAdvLoot, CListWnd* pPersonalList, CListWnd* pSharedList);
MQLIB_API void WeDidStuff();
MQLIB_API int GetFreeInventory(int nSize);
MQLIB_API int GetFreeStack(ItemClient* pContents);
MQLIB_API int RangeRandom(int min, int max);

MQLIB_API int GetCharMaxBuffSlots();
MQLIB_API int GetCharMaxLevel();

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
MQLIB_API uint32_t GetGroupMarkedTargetID(int index);
MQLIB_API uint32_t GetRaidMarkedTargetID(int index);
MQLIB_API bool IsAssistNPC(SPAWNINFO* pSpawn);
MQLIB_API void DoFace(SPAWNINFO* pChar, CVector3 Position);

MQLIB_API int64_t GetGuildIDByName(const char* szGuild);
MQLIB_API const char* GetGuildByID(int64_t GuildID);

MQLIB_API int GetBodyType(PlayerClient* pSpawn);
MQLIB_API eSpawnType GetSpawnType(SPAWNINFO* pSpawn);
MQLIB_API const char* GetLightForSpawn(SPAWNINFO* pSpawn);
MQLIB_API int GetDeityTeamByID(int DeityID);
MQLIB_API int ConColor(SPAWNINFO* pSpawn);
MQLIB_API float FindSpeed(SPAWNINFO* pSpawn);
MQLIB_API bool IsNamed(SPAWNINFO* pSpawn);

MQLIB_API CMQ2Alerts CAlerts;

// Item Utilities

MQLIB_API ItemDefinition* GetItemFromContents(ItemClient* c); // Use c->GetItemDefinition() instead

MQLIB_API ItemClient* GetEnviroContainer();
MQLIB_API CContainerWnd* FindContainerForContents(ItemClient* pContents);



MQLIB_API int ItemHasStat(ItemClient* pCont, std::string_view search);

// Compatibility for ItemHasStat
DEPRECATE("Use string_view form of ItemHasStat instead")
inline bool ItemHasStat(ItemClient* pCont, int* num, const char* buffer)
{
	*num = ItemHasStat(pCont, buffer);
	return *num != 0;
}

MQLIB_API const char* GetLoginName();
MQLIB_API float DistanceToPoint(SPAWNINFO* pSpawn, float xLoc, float yLoc);
MQLIB_API float Distance3DToPoint(SPAWNINFO* pSpawn, float xLoc, float yLoc, float zLoc);
MQLIB_API char* ShowSpellSlotInfo(EQ_Spell* pSpell, char* szBuffer, size_t BufferSize, const char* lineBreak = "<br>");
MQLIB_API char* ParseSpellEffect(EQ_Spell* pSpell, int i, char* szBuffer, size_t BufferSize, int level = 100);

MQLIB_API int GetSpellAttrib(const EQ_Spell* pSpell, int index);
MQLIB_API int64_t GetSpellBase(const EQ_Spell* pSpell, int index);
MQLIB_API int64_t GetSpellBase2(const EQ_Spell* pSpell, int index);
MQLIB_API int64_t GetSpellMax(const EQ_Spell* pSpell, int index);
MQLIB_API int GetSpellCalc(const EQ_Spell* pSpell, int index);

MQLIB_API void SlotValueCalculate(char* szBuff, EQ_Spell* pSpell, int i, double mp = 1.0);
MQLIB_API int64_t CalcValue(int calc, int64_t base, int64_t max, int tick, int minlevel = MAX_PC_LEVEL, int level = MAX_PC_LEVEL);
MQLIB_API char* GetSpellEffectName(int EffectID, char* szBuffer, size_t BufferSize);
MQLIB_API void GetGameDate(int* Month, int* Day, int* Year);
MQLIB_API void GetGameTime(int* Hour, int* Minute, int* Night);
MQLIB_API void SyntaxError(const char* szFormat, ...);
MQLIB_API void MacroError(const char* szFormat, ...);
MQLIB_API void FatalError(const char* szFormat, ...);
MQLIB_API char* GetSpellRestrictions(EQ_Spell* pSpell, unsigned int nIndex, char* szBuffer, size_t BufferSize);
MQLIB_API void MQ2DataError(const char* szFormat, ...);
MQLIB_API void DisplayOverlayText(const char* szText, int dwColor, uint32_t dwTransparency, uint32_t msFadeIn, uint32_t msFadeOut, uint32_t msHold);
MQLIB_API void CustomPopup(const char* szPopText, bool bPopOutput);

MQLIB_API bool IsBardSong(EQ_Spell* pSpell);
MQLIB_API bool IsSPAEffect(EQ_Spell* pSpell, int EffectID);
MQLIB_API const char* GetLDoNTheme(int LDTheme);
MQLIB_API bool TriggeringEffectSpell(SPELL* aSpell, int i);
MQLIB_API bool BuffStackTest(SPELL* aSpell, SPELL* bSpell, bool bIgnoreTriggeringEffects = false, bool bTriggeredEffectCheck = false);
MQLIB_API bool WillStackWith(const EQ_Spell* testSpell, const EQ_Spell* existingSpell);
MQLIB_API bool IsSpellTooPowerful(PlayerClient* caster, PlayerClient* target, EQ_Spell* spell);
MQLIB_API uint32_t GetItemTimer(ItemClient* pItem);
MQLIB_API ItemClient* GetItemContentsByName(const char* ItemName);
MQLIB_API DWORD GetAvailableSlots(ItemClient* pContainer, ItemClient* pItem, int *firstavailableslot);
MQLIB_API bool LoH_HT_Ready();
MQLIB_API ECombatState GetCombatState();

/* MQ2DATAVARS */
MQLIB_API char* GetFuncParam(const char* szMacroLine, int ParamNum, char* szParamName, size_t ParamNameLen, char* szParamType, size_t ParamTypeLen);

MQLIB_API void DropTimers();

/*                 */

MQLIB_API bool LoadCfgFile(const char* Filename, bool Delayed = FromPlugin);

/* MQ2GROUNDSPAWNS */

using EQGroundItemPtr = MQEQObjectPtr<EQGroundItem>;
using EQPlacedItemPtr = MQEQObjectPtr<EQPlacedItem>;
using AnyMQGroundItem = std::variant<std::monostate, EQGroundItemPtr, EQPlacedItemPtr>;

enum class MQGroundSpawnType
{ // this ordering needs to match the GroundSpawn::Object variant class ordering
	None,
	Ground,
	Placed
};

inline auto EQObjectID(EQGroundItem* Object) { return Object->DropID; }
inline auto EQObjectID(EQPlacedItem* Object) { return Object->RealEstateItemID; }

struct MQGroundSpawn
{
	MQGroundSpawnType Type;
	AnyMQGroundItem Object;

	// These ctors will automatically register the Object in the invalidation mapper for zoning
	MQLIB_OBJECT MQGroundSpawn(EQGroundItem* Object) : Type(MQGroundSpawnType::Ground), Object(ObserveEQObject(Object)) {}
	MQLIB_OBJECT MQGroundSpawn(EQPlacedItem* Object) : Type(MQGroundSpawnType::Placed), Object(ObserveEQObject(Object)) {}
	MQLIB_OBJECT MQGroundSpawn() : Type(MQGroundSpawnType::None), Object() {}

	MQLIB_OBJECT float Distance(SPAWNINFO* pSpawn) const;
	MQLIB_OBJECT float Distance3D(SPAWNINFO* pSpawn) const;
	MQLIB_OBJECT CActorInterface* Actor() const;
	MQLIB_OBJECT CXStr Name() const;
	MQLIB_OBJECT CXStr DisplayName() const;
	MQLIB_OBJECT CVector3 Position() const;
	MQLIB_OBJECT int ID() const;
	MQLIB_OBJECT int SubID() const;
	MQLIB_OBJECT int ZoneID() const;
	MQLIB_OBJECT float Heading() const;
	MQLIB_OBJECT MQGameObject ToGameObject() const;
	MQLIB_OBJECT void Reset();

	template <typename T> T* Get() const { static_assert(mq::always_false<T>::value, "Unsupported GroundSpawn Type."); }
	template <> MQLIB_OBJECT EQGroundItem* Get<EQGroundItem>() const;
	template <> MQLIB_OBJECT EQPlacedItem* Get<EQPlacedItem>() const;

	inline explicit operator bool() const { return Type != MQGroundSpawnType::None; }
};

inline bool operator==(const MQGroundSpawn& groundItem, EQGroundItem* other)
{
	if (groundItem.Type != MQGroundSpawnType::Ground)
		return false;

	return groundItem.Get<EQGroundItem>() == other;
}

inline bool operator==(EQGroundItem* other, const MQGroundSpawn& groundItem)
{
	return groundItem == other;
}

inline bool operator==(const MQGroundSpawn& groundItem, EQPlacedItem* other)
{
	if (groundItem.Type != MQGroundSpawnType::Placed)
		return false;

	return groundItem.Get<EQPlacedItem>() == other;
}

inline bool operator==(EQPlacedItem* other, const MQGroundSpawn& groundItem)
{
	return groundItem == other;
}

inline bool operator==(const MQGroundSpawn& groundItemA, const MQGroundSpawn& groundItemB)
{
	return groundItemA.Type == groundItemB.Type
		&& groundItemA.Object == groundItemB.Object;
}

MQLIB_OBJECT MQGroundSpawn GetGroundSpawnByName(std::string_view Name);
MQLIB_OBJECT MQGroundSpawn GetGroundSpawnByID(int ID);
MQLIB_OBJECT MQGroundSpawn GetNearestGroundSpawn();
MQLIB_OBJECT MQGroundSpawn GetNthGroundSpawnFromMe(size_t N);
MQLIB_OBJECT int GetGroundSpawnCount();
MQLIB_OBJECT int GetGroundSpawnCountByName(std::string_view Name);
MQLIB_OBJECT MQGroundSpawn CurrentGroundSpawn();
MQLIB_OBJECT MQGroundSpawn FirstGroundSpawn();
MQLIB_OBJECT MQGroundSpawn LastGroundSpawn();
MQLIB_OBJECT MQGroundSpawn NextGroundSpawn();
MQLIB_OBJECT MQGroundSpawn PrevGroundSpawn();
MQLIB_OBJECT void SetGroundSpawn(std::string_view Name);
MQLIB_OBJECT void SetGroundSpawn(const MQGroundSpawn& groundSpawn);
MQLIB_OBJECT void ClearGroundSpawn();
MQLIB_OBJECT bool HasCurrentGroundSpawn();
MQLIB_OBJECT CXStr GetFriendlyNameForGroundItem(const EQGroundItem* pItem);
MQLIB_OBJECT CXStr GetFriendlyNameForPlacedItem(const EQPlacedItem* pItem);
MQLIB_API char* GetFriendlyNameForGroundItem(PGROUNDITEM pItem, char* szName, size_t BufferSize);

inline auto EQObjectID(PlayerClient* pSpawn) { return pSpawn->SpawnID; }
using ObservedSpawnPtr = MQEQObjectPtr<PlayerClient>;

MQLIB_API void AddObservedEQObject(const std::shared_ptr<MQTransient>& Object);
MQLIB_API void InvalidateObservedEQObject(void* Object);

// A.k.a. "Door target"
MQLIB_API void SetSwitchTarget(EQSwitch* pSwitch);
MQLIB_API EQSwitch* GetSwitchByID(int id);
// retrieves the closest switch with the specified name.
MQLIB_API EQSwitch* FindSwitchByName(const char* szName = nullptr);


MQLIB_API void ClearSearchSpawn(MQSpawnSearch* pSearchSpawn);
MQLIB_API SPAWNINFO* NthNearestSpawn(MQSpawnSearch* pSearchSpawn, int Nth, SPAWNINFO* pOrigin, bool IncludeOrigin = false);
MQLIB_API int CountMatchingSpawns(MQSpawnSearch* pSearchSpawn, SPAWNINFO* pOrigin, bool IncludeOrigin = false);
MQLIB_API SPAWNINFO* SearchThroughSpawns(MQSpawnSearch* pSearchSpawn, SPAWNINFO* pChar);
MQLIB_API bool SpawnMatchesSearch(MQSpawnSearch* pSearchSpawn, SPAWNINFO* pChar, SPAWNINFO* pSpawn);
MQLIB_API bool SearchSpawnMatchesSearchSpawn(MQSpawnSearch* pSearchSpawn1, MQSpawnSearch* pSearchSpawn2);
MQLIB_API const char* ParseSearchSpawnArgs(char* szArg, const char* szRest, MQSpawnSearch* pSearchSpawn);
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
MQLIB_API int FindSpellListByName(const char* szName);
MQLIB_API float StateHeightMultiplier(DWORD StandState);
MQLIB_API PlayerClient* GetClosestBanker(bool forInteraction = true);

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
MQLIB_API bool        HasExpansion(int64_t nExpansion);
MQLIB_API void        ListMercAltAbilities();
MQLIB_API ItemClient*   FindItemBySlot(int InvSlot, int BagSlot = -1, ItemContainerInstance location = eItemContainerPossessions);
MQLIB_API ItemContainer* GetItemContainerByType(ItemContainerInstance type);
   inline ItemContainer* GetItemContainerByGlobalIndex(const ItemGlobalIndex& index) { return GetItemContainerByType(index.GetLocation()); }
MQLIB_API ItemClient*   FindItemByGlobalIndex(const ItemGlobalIndex& idx);
   inline ItemClient* FindItemBySlot(const ItemGlobalIndex& idx) { return FindItemByGlobalIndex(idx); }
   DEPRECATE("Use FindItemByGlobalIndex instead of FindItemBySlot2")
   inline ItemClient*   FindItemBySlot2(const ItemGlobalIndex& idx) { return FindItemByGlobalIndex(idx); }
MQLIB_API ItemClient*   FindItemByName(const char* pName, bool bExact = false);
MQLIB_API ItemClient*   FindItemByID(int ItemID);
MQLIB_API int         FindItemCountByName(const char* pName);
MQLIB_API int         FindItemCountByID(int ItemID);
MQLIB_API int         FindInventoryItemCountByName(const char* pName, StringMatchType matchType = StringMatchType::CaseInsensitive,
                                                   int slotBegin = -1, int slotEnd = -1);
MQLIB_API ItemClient* FindInventoryItemByName(const char* pName, StringMatchType matchType = StringMatchType::CaseInsensitive,
                                              int slotBegin = -1, int slotEnd = -1);
MQLIB_API int         FindInventoryItemCountByID(int ItemID, int slobBegin = -1, int slotEnd = -1);
MQLIB_API ItemClient*   FindBankItemByName(const char* pName, bool bExact);
MQLIB_API ItemClient*   FindBankItemByID(int ItemID);
MQLIB_API int         FindBankItemCountByName(const char* pName, bool bExact);
MQLIB_API int         FindBankItemCountByID(int ItemID);
MQLIB_API CInvSlot*   GetInvSlot(const ItemGlobalIndex& idx);
   inline CInvSlot*   GetInvSlot(DWORD type, short Invslot, short Bagslot = -1) { return GetInvSlot(ItemGlobalIndex(static_cast<ItemContainerInstance>(type), ItemIndex(Invslot, Bagslot))); }
   DEPRECATE("Use GetInvSlot instead of GetInvSlot2")
   inline CInvSlot*   GetInvSlot2(const ItemGlobalIndex& idx) { return GetInvSlot(idx); }
MQLIB_API bool        IsItemInsideContainer(ItemClient* pItem);
MQLIB_API bool        ItemMatchesSearch(MQItemSearch& itemSearch, ItemClient* pItem);
MQLIB_API bool        PickupItem(const ItemGlobalIndex& index);
   inline bool        PickupItem(ItemContainerInstance type, ItemClient* pItem) { return PickupItem(pItem->GetItemLocation()); }
MQLIB_API bool        DropItem(const ItemGlobalIndex& index);
   inline bool        DropItem(ItemContainerInstance type, short InvSlot, short Bagslot) { return DropItem(ItemGlobalIndex(type, ItemIndex(InvSlot, Bagslot))); }
   DEPRECATE("Use DropItem instead of DropItem2")
   inline bool        DropItem2(ItemContainerInstance type, short InvSlot, short Bagslot) { return DropItem(ItemGlobalIndex(type, ItemIndex(InvSlot, Bagslot))); }
MQLIB_API bool        ItemOnCursor();
MQLIB_API bool        OpenContainer(ItemClient* pItem, bool hidden = false, bool allowTradeskill = false);
MQLIB_API bool        CloseContainer(ItemClient* pItem);

// The number of available inventory slots are limited by expansion level.
MQLIB_API int         GetAvailableBagSlots();          // returns the number of bag slots that are enabled
MQLIB_API int         GetHighestAvailableBagSlot();    // returns the InvSlot of the highest bag slot that is enabled
MQLIB_API int         GetAvailableBankSlots();         // returns the number of bank slots that are enabled
MQLIB_API int         GetAvailableSharedBankSlots();   // returns the number of shared bank slots that are enabled

/* MQ2CACHEDBUFFS */
class CachedBuff
{
public:
	int slot;
	int spellId;
	int duration;            // in ticks...
	int count;
	char casterName[64];
	DWORD timeStamp;

	DWORD Duration() const
	{
		auto end = timeStamp + (duration * 6000);
		auto now = EQGetTime();

		if (end > now)
			return end - now;

		return 0UL;
	}

	DWORD Staleness() const
	{
		return EQGetTime() - timeStamp;
	}
};

void InitializeCachedBuffs();
void ShutdownCachedBuffs();

MQLIB_API    int GetCachedBuff(SPAWNINFO* pSpawn, const std::function<bool(const CachedBuff&)>& predicate);
MQLIB_API    int GetCachedBuffAt(SPAWNINFO* pSpawn, size_t index);
MQLIB_OBJECT int GetCachedBuffAt(SPAWNINFO* pSpawn, size_t index, const std::function<bool(const CachedBuff&)>& predicate);
MQLIB_OBJECT std::optional<CachedBuff> GetCachedBuffAtSlot(SPAWNINFO* pSpawn, int slot);
MQLIB_OBJECT std::vector<CachedBuff> FilterCachedBuffs(SPAWNINFO* pSpawn, const std::function<bool(const CachedBuff&)>& predicate);
MQLIB_API    DWORD GetCachedBuffCount(SPAWNINFO* pSpawn);
MQLIB_OBJECT DWORD GetCachedBuffCount(SPAWNINFO* pSpawn, const std::function<bool(const CachedBuff&)>& predicate);
MQLIB_API    void ClearCachedBuffsSpawn(SPAWNINFO* pSpawn);
MQLIB_API    void ClearCachedBuffs();

MQLIB_API DEPRECATE("Use GetCachedBuff with predicates instead") int GetTargetBuffByCategory(DWORD category, DWORD classmask = 0, int startslot = 0);
MQLIB_API DEPRECATE("Use GetCachedBuff with predicates instead") int GetTargetBuffBySubCat(const char* subcat, DWORD classmask = 0, int startslot = 0);
MQLIB_API DEPRECATE("Use GetCachedBuff with predicates instead") int GetTargetBuffBySPA(int spa, bool bIncrease, int startslot = 0);
MQLIB_API DEPRECATE("Use GetCachedBuff with predicates instead") bool HasCachedTargetBuffSubCat(const char* subcat, SPAWNINFO* pSpawn, void*, DWORD classmask = 0);
MQLIB_API DEPRECATE("Use GetCachedBuff with predicates instead") bool HasCachedTargetBuffSPA(int spa, bool bIncrease, SPAWNINFO* pSpawn, void*);

MQLIB_API bool HasBuffCastByPlayer(SPAWNINFO* pBuffOwner, const char* szBuffName, const char* casterName);
MQLIB_API DEPRECATE("Use HasBuffCastByPlayer instead of TargetBuffCastByMe") bool TargetBuffCastByMe(const char* szBuffName);

MQLIB_OBJECT int      GetSelfBuff(const std::function<bool(const EQ_Affect&)>& fPredicate, int minSlot = 0, int maxSlot = -1);
MQLIB_OBJECT int      GetSelfBuff(const std::function<bool(EQ_Spell*)>& fPredicate, int minSlot = 0, int maxSlot = -1);

MQLIB_API DEPRECATE("Use GetSelfBuff with predicates instead") int GetSelfBuffByCategory(DWORD category, DWORD classmask = 0, int startslot = 0);
MQLIB_API DEPRECATE("Use GetSelfBuff with predicates instead") int GetSelfBuffBySubCat(PCHAR subcat, DWORD classmask = 0, int startslot = 0);
MQLIB_API DEPRECATE("Use GetSelfBuff with predicates instead") int GetSelfBuffBySPA(int spa, bool bIncrease, int startslot = 0);
MQLIB_API DEPRECATE("Use GetSelfBuff with predicates instead") int GetSelfShortBuffBySPA(int spa, bool bIncrease, int startslot = 0);

MQLIB_API    bool        HasSPA(EQ_Spell* pSpell, eEQSPA eSPA, bool bIncrease = false);
MQLIB_OBJECT bool        HasSPA(const EQ_Affect& buff, eEQSPA eSPA, bool bIncrease = false);
MQLIB_OBJECT bool        HasSPA(const CachedBuff& buff, eEQSPA eSPA, bool bIncrease = false);
MQLIB_API    int         GetPlayerClass(const char* name);
MQLIB_API    bool        IsSpellUsableForClass(EQ_Spell* pSpell, unsigned int classmask = 0);
MQLIB_OBJECT bool        IsSpellUsableForClass(const EQ_Affect& buff, unsigned int classmask = 0);
MQLIB_OBJECT bool        IsSpellUsableForClass(CachedBuff buff, unsigned int classmask = 0);
MQLIB_API    int         GetSpellCategory(EQ_Spell* pSpell);
MQLIB_OBJECT int         GetSpellCategory(const EQ_Affect& buff);
MQLIB_OBJECT int         GetSpellCategory(CachedBuff buff);
MQLIB_API    int         GetSpellSubcategory(EQ_Spell* pSpell);
MQLIB_OBJECT int         GetSpellSubcategory(const EQ_Affect& buff);
MQLIB_OBJECT int         GetSpellSubcategory(CachedBuff buff);
MQLIB_API    EQ_Spell*   GetSpellParent(int id);
MQLIB_API    int64_t     GetSpellCounters(eEQSPA spa, const EQ_Affect& buff); // Get spell counters of given spa for the given buff.
MQLIB_API    int64_t     GetMySpellCounters(eEQSPA spa);                      // Get spell counters of given spa on my character.
MQLIB_API    int64_t     GetTotalSpellCounters(const EQ_Affect& buff);        // Get total count of spell counters for the given buff.
MQLIB_API    int64_t     GetMyTotalSpellCounters();                           // Get total count of spell counters for my character.
MQLIB_API    int         GetMeleeSpeedPctFromSpell(EQ_Spell* pSpell, bool increase);
MQLIB_API    EQ_Spell*   GetHighestLearnedSpellByGroupID(int dwSpellGroupID);
MQLIB_API    DWORD       GetSpellID(EQ_Spell* spell);
MQLIB_OBJECT DWORD       GetSpellID(const EQ_Affect& buff);
MQLIB_OBJECT DWORD       GetSpellID(const CachedBuff& buff);
MQLIB_API    const char* GetSpellName(EQ_Spell* spell);
MQLIB_OBJECT const char* GetSpellName(const EQ_Affect& buff);
MQLIB_OBJECT const char* GetSpellName(const CachedBuff& buff);
MQLIB_API    const char* GetSpellCaster(const EQ_Affect& buff);
MQLIB_OBJECT const char* GetSpellCaster(const CachedBuff& buff);
MQLIB_API    const char* GetPetSpellCaster(const EQ_Affect& buff);
MQLIB_API    eEQSPELLCAT GetSpellCategoryFromName(const char* category);
MQLIB_API    eEQSPA      GetSPAFromName(const char* spa);

MQLIB_API    const char* GetTeleportName(DWORD id);

MQLIB_API HMODULE GetCurrentModule();
MQLIB_API DWORD CALLBACK MQ2End(void* lpParameter);
MQLIB_API DWORD CALLBACK GetlocalPlayerOffset();
void DoMainThreadShutdown();
MQLIB_API HANDLE hUnloadComplete;

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

MQLIB_API bool Calculate(const char* szFormula, double& Dest);

// Given a string that contains a number, make the number "pretty" by adding things like
// comma separators, or decimals.
MQLIB_API void PrettifyNumber(char* string, size_t bufferSize, int decimals = 0);

constexpr int LIGHT_COUNT = 13;
//#define MAX_COMBINES		61
//#define MAX_ITEMTYPES		71
//#define MAX_SPELLEFFECTS	487

constexpr int GAMESTATE_PRECHARSELECT  = -1;
constexpr int GAMESTATE_CHARSELECT     = 1;
constexpr int GAMESTATE_CHARCREATE     = 2;
constexpr int GAMESTATE_POSTCHARSELECT = 3;
constexpr int GAMESTATE_SOMETHING      = 4;
constexpr int GAMESTATE_INGAME         = 5;
constexpr int GAMESTATE_LOGGINGIN      = 253;
constexpr int GAMESTATE_UNLOADING      = 255;

#define XKF_SHIFT               1
#define XKF_CTRL                2
#define XKF_LALT                4
#define XKF_RALT                8

MQLIB_API void RemoveFindItemMenu();
MQLIB_API bool WillFitInBank(ItemClient* pContent);
MQLIB_API bool WillFitInInventory(ItemClient* pContent);

/* MQ2ANONYMIZE */
void InitializeAnonymizer();
void ShutdownAnonymizer();
MQLIB_API bool IsAnonymized();
MQLIB_OBJECT CXStr Anonymize(const CXStr& Text);
MQLIB_OBJECT CXStr& PluginAnonymize(CXStr& Text);

// Can take a std::string_view, std::string, or CXStr to check if we think we *might* run anonymize
template <typename T>
inline bool MaybeAnonymize(T& text)
{
	return IsAnonymized() && GetGameState() == GAMESTATE_INGAME && !text.empty();
}

/* MQ2STRINGDB */
// EQ sends us tokenized text that's been serialized into a stream of bytes. This struct holds that
// data and parses the stream.
struct TokenTextParam
{
	bool World;
	int StringID;
	int Color;
	std::vector<std::string> Tokens;
	TokenTextParam(const char* Data, DWORD Length);
};

void InitializeStringDB();
void ShutdownStringDB();
MQLIB_OBJECT int AddTokenMessageCmd(int StringID, fMQTokenMessageCmd Command);
MQLIB_OBJECT void RemoveTokenMessageCmd(int StringID, int CallbackID);

//----------------------------------------------------------------------------

MQLIB_API MembershipLevel GetMembershipLevel();
inline DEPRECATE("Use GetMembershipLevel instead of GetSubscriptionLevel") int GetSubscriptionLevel() { return (int)GetMembershipLevel(); }

} // namespace mq

#include "mq/api/Achievements.h"
#include "mq/api/Spells.h"

#include "GraphicsEngine.h"  // TODO: Move exports to mq/api header

#if __has_include("../private/MQ2Main-private.h")
#include "../private/MQ2Main-private.h"
#endif
