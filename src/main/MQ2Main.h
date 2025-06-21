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

#include "mq/base/Traits.h"
#include "MQ2Internal.h"
#include "MQ2Globals.h"
#include "MQ2Inlines.h"
#include "MQ2Commands.h"
#include "MQ2DataContainers.h"
#include "MQ2Utilities.h"
#include "datatypes/MQ2DataTypes.h"

// TODO: Move these to mq/Plugin.h so that they are not globally included -- include them
// only where they are needed.

#include "mq/utils/Benchmarks.h"
#include "mq/utils/Keybinds.h"

#include "mq/api/Main.h"
#include "mq/api/CachedBuffs.h"
#include "mq/api/DetourAPI.h"
#include "mq/api/MacroAPI.h"
#include "mq/api/PluginAPI.h"
#include "mq/api/Textures.h"

// Link up ImGui
#include <imgui/imgui.h>

#if defined(MQLIB_STATIC)

#if defined(_M_AMD64)
#pragma comment(lib, "imgui_static-64.lib")
#else
#pragma comment(lib, "imgui_static.lib")
#endif

#else // defined(MQLIB_STATIC)

#if defined(_M_AMD64)
#pragma comment(lib, "imgui-64.lib")
#else
#pragma comment(lib, "imgui.lib")
#endif // defined(_WIN64)

#endif // !defined(MQLIB_STATIC)

//#define MQ2_PROFILING

// uncomment this line to turn off the single-line benchmark macro
// #define DISABLE_BENCHMARKS

// This is the MQNEXT build, it is here to help plugins conditionally compile against
// the new interfaces
#define MQNEXT

#ifdef DEBUG_TRY
#define DebugTry(x) DebugSpew("Trying %s",#x);x;DebugSpew("%s complete",#x)
#else
#define DebugTry(x) x
#endif

#define MAX_VARNAME           64

#ifndef MQ_FROM_PLUGIN
#define MQ_FROM_PLUGIN 0
#endif

namespace mq {

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
MQLIB_API bool IsTargetable(eqlib::PlayerClient* pSpawn);
MQLIB_API bool AreNameSpritesCustomized();

/* OVERLAY */
MQLIB_API void SetOverlayEnabled(bool visible);
MQLIB_API bool IsOverlayEnabled();

using fPanelDrawFunction = void(*)();
MQLIB_API void AddSettingsPanel(const char* name, fPanelDrawFunction drawFunction);
MQLIB_API void RemoveSettingsPanel(const char* name);

/* EQ Menu */
MQLIB_OBJECT void AddCascadeMenuItem(const char* name, const char* keyBind, int icon = -1);

using fCascadeItemFunction = void(*)();
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
MQLIB_API eqlib::CXWnd* FindMQ2Window(const char* Name);
MQLIB_API eqlib::CXWnd* FindMQ2WindowPath(const char* Name);
MQLIB_API eqlib::CXWnd* GetParentWnd(eqlib::CXWnd* pWnd);
MQLIB_API bool IsScreenPieceLoaded(const char*);

MQLIB_API bool SendComboSelect(const char* WindowName, const char* ScreenID, int Value);
MQLIB_API bool SendListSelect(const char* WindowName, const char* ScreenID, int Value);
MQLIB_API bool SendListSelect2(eqlib::CXWnd* pList, int ListIndex);
MQLIB_API bool SendWndClick2(eqlib::CXWnd* pWnd, const char* ClickNotification);

/* CHAT HOOK */
MQLIB_API void dsp_chat_no_events(const char* message, int color = USERCOLOR_DEFAULT, bool allowLog = true, bool doPercentConvert = true);

/* MOUSE */
MQLIB_API bool IsMouseWaiting();
MQLIB_API bool IsMouseWaitingForButton();
MQLIB_API bool MoveMouse(int x, int y);
MQLIB_API bool ClickMouseButton(int mouseButton); // Uses DirectInput to simulate a mouse click at the current mouse position.
MQLIB_API bool MouseToPlayer(eqlib::PlayerClient* pPlayer, DWORD position, bool bClick = false);
MQLIB_API bool ClickMouseItem(const MQGroundSpawn& pGroundSpawn, bool left);
inline bool ClickMouseItem(eqlib::PlayerClient* pChar, const MQGroundSpawn& pGroundSpawn, bool left) { return ClickMouseItem(pGroundSpawn, left); }
void MouseConsume(int mouseButton, bool pressed);

/** Draw text on the HUD */
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

MQLIB_OBJECT void StripMQChat(std::string_view in, char* out, size_t len = MAX_STRING);

template <size_t Size>
void StripMQChat(const char* in, char(&buffer)[Size])
{
	StripMQChat(std::string_view{ in }, buffer, Size);
}

std::string StripMQChat(std::string_view in);

MQLIB_API void STMLToPlainText(char* in, char* out);
MQLIB_API bool CompareTimes(char* RealTime, char* ExpectedTime);

MQLIB_API void AddFilter(const char* szFilter, int Length, bool& pEnabled);
MQLIB_API void DefaultFilters();

MQLIB_API char* ConvertHotkeyNameToKeyName(char* szName);

MQLIB_API int FindInvSlotForContents(eqlib::ItemClient* pContents);
MQLIB_API int FindInvSlot(const char* Name, bool Exact);
MQLIB_API int FindNextInvSlot(const char* Name, bool Exact);

MQLIB_API int GetLanguageIDByName(const char* szName);
MQLIB_API int GetCurrencyIDByName(const char* szName);
MQLIB_API const char* GetSpellNameByID(int dwSpellID);
MQLIB_API eqlib::EQ_Spell* GetSpellByName(std::string_view name);
MQLIB_API eqlib::EQ_Spell* GetSpellByAAName(const char* szName);
MQLIB_API eqlib::CAltAbilityData* GetAAById(int nAbilityId, int playerLevel = -1);
inline eqlib::CAltAbilityData* GetAAByIdWrapper(int nAbilityId, int playerLevel = -1) { return GetAAById(nAbilityId, playerLevel); }
MQLIB_API int GetSpellRankByName(const char* SpellName);
MQLIB_API void TruncateSpellRankName(char* SpellName);
MQLIB_API int FindBuffIndex(std::string_view Name, int minSlot = 0, int maxSlot = -1);
MQLIB_API bool RemoveBuffByName(std::string_view buffName);
MQLIB_API bool RemoveBuffBySpellID(int buffName);
MQLIB_API bool RemoveBuffByIndex(int buffIndex);
MQLIB_API bool RemovePetBuffByName(std::string_view buffName);
MQLIB_API bool StripQuotes(char* str);
MQLIB_API int GetKeyRingCount(eqlib::KeyRingType keyRingType);
MQLIB_API int GetMountCount();
MQLIB_API int GetIllusionCount();
MQLIB_API int GetFamiliarCount();
MQLIB_API int GetHeroForgeCount();
MQLIB_API int GetTeleportationItemCount();
MQLIB_API int GetActivatedItemCount();

MQLIB_API bool IsActiveAA(const char* pSpellName);
MQLIB_API eqlib::CXWnd* GetAdvLootPersonalListItem(DWORD ListIndex, DWORD type);
MQLIB_API eqlib::CXWnd* GetAdvLootSharedListItem(DWORD ListIndex, DWORD type);
MQLIB_API bool LootInProgress(eqlib::CAdvancedLootWnd* pAdvLoot, eqlib::CListWnd* pPersonalList, eqlib::CListWnd* pSharedList);
MQLIB_API void WeDidStuff();
MQLIB_API int GetFreeInventory(int nSize);
MQLIB_API int GetFreeStack(eqlib::ItemClient* pContents);
MQLIB_API int RangeRandom(int min, int max);

MQLIB_API int GetCharMaxBuffSlots();
MQLIB_API int GetCharMaxLevel();

MQLIB_OBJECT bool IsRaidMember(const char* SpawnName);
MQLIB_OBJECT bool IsRaidMember(eqlib::PlayerClient* pSpawn);
MQLIB_OBJECT int GetRaidMemberIndex(const char* SpawnName);
MQLIB_OBJECT int GetRaidMemberIndex(eqlib::PlayerClient* pSpawn);
MQLIB_OBJECT bool IsGroupMember(const char* SpawnName);
MQLIB_OBJECT bool IsGroupMember(eqlib::PlayerClient* pSpawn);
MQLIB_API bool IsFellowshipMember(const char* SpawnName);
MQLIB_API bool IsGuildMember(const char* SpawnName);
MQLIB_API int GetGroupMercenaryCount(uint32_t ClassMASK);
MQLIB_API eqlib::PlayerClient* GetRaidMember(int index);
MQLIB_API eqlib::PlayerClient* GetGroupMember(int index);
MQLIB_API uint32_t GetGroupMarkedTargetID(int index);
MQLIB_API uint32_t GetRaidMarkedTargetID(int index);
MQLIB_API bool IsAssistNPC(eqlib::PlayerClient* pSpawn);
MQLIB_API void DoFace(eqlib::PlayerClient* pChar, const eqlib::CVector3& Position);

MQLIB_API int64_t GetGuildIDByName(const char* szGuild);
MQLIB_API const char* GetGuildByID(int64_t GuildID);

MQLIB_API int GetBodyType(eqlib::PlayerClient* pSpawn);
MQLIB_API eSpawnType GetSpawnType(eqlib::PlayerClient* pSpawn);
MQLIB_API const char* GetLightForSpawn(eqlib::PlayerClient* pSpawn);
MQLIB_API int GetDeityTeamByID(int DeityID);
MQLIB_API int ConColor(eqlib::PlayerClient* pSpawn);
MQLIB_API float FindSpeed(eqlib::PlayerClient* pSpawn);
MQLIB_API bool IsNamed(eqlib::PlayerClient* pSpawn);

MQLIB_API CMQ2Alerts CAlerts;

// Item Utilities

MQLIB_API eqlib::ItemDefinition* GetItemFromContents(eqlib::ItemClient* c); // Use c->GetItemDefinition() instead

MQLIB_API eqlib::ItemClient* GetEnviroContainer();
MQLIB_API eqlib::CContainerWnd* FindContainerForContents(eqlib::ItemClient* pContents);



MQLIB_API int ItemHasStat(eqlib::ItemClient* pCont, std::string_view search);

// Compatibility for ItemHasStat
DEPRECATE("Use string_view form of ItemHasStat instead")
inline bool ItemHasStat(eqlib::ItemClient* pCont, int* num, const char* buffer)
{
	*num = ItemHasStat(pCont, buffer);
	return *num != 0;
}

MQLIB_API const char* GetLoginName();
MQLIB_API float DistanceToPoint(eqlib::PlayerClient* pSpawn, float xLoc, float yLoc);
MQLIB_API float Distance3DToPoint(eqlib::PlayerClient* pSpawn, float xLoc, float yLoc, float zLoc);
MQLIB_API char* ShowSpellSlotInfo(eqlib::EQ_Spell* pSpell, char* szBuffer, size_t BufferSize, const char* lineBreak = "<br>");
MQLIB_API char* ParseSpellEffect(eqlib::EQ_Spell* pSpell, int i, char* szBuffer, size_t BufferSize, int level = 100);

MQLIB_API int GetSpellAttrib(const eqlib::EQ_Spell* pSpell, int index);
MQLIB_API int64_t GetSpellBase(const eqlib::EQ_Spell* pSpell, int index);
MQLIB_API int64_t GetSpellBase2(const eqlib::EQ_Spell* pSpell, int index);
MQLIB_API int64_t GetSpellMax(const eqlib::EQ_Spell* pSpell, int index);
MQLIB_API int GetSpellCalc(const eqlib::EQ_Spell* pSpell, int index);

MQLIB_API void SlotValueCalculate(char* szBuff, eqlib::EQ_Spell* pSpell, int i, double mp = 1.0);
MQLIB_API int64_t CalcValue(int calc, int64_t base, int64_t max, int tick, int minlevel = eqlib::MAX_PC_LEVEL, int level = eqlib::MAX_PC_LEVEL);
MQLIB_API char* GetSpellEffectName(int EffectID, char* szBuffer, size_t BufferSize);
MQLIB_API void GetGameDate(int* Month, int* Day, int* Year);
MQLIB_API void GetGameTime(int* Hour, int* Minute, int* Night);
MQLIB_API void SyntaxError(const char* szFormat, ...);
MQLIB_API void MacroError(const char* szFormat, ...);
MQLIB_API void FatalError(const char* szFormat, ...);
MQLIB_API char* GetSpellRestrictions(eqlib::EQ_Spell* pSpell, unsigned int nIndex, char* szBuffer, size_t BufferSize);
MQLIB_API void DisplayOverlayText(const char* szText, int dwColor, uint32_t dwTransparency, uint32_t msFadeIn, uint32_t msFadeOut, uint32_t msHold);
MQLIB_API void CustomPopup(const char* szPopText, bool bPopOutput);

MQLIB_API bool IsBardSong(eqlib::EQ_Spell* pSpell);
MQLIB_API bool IsSPAEffect(eqlib::EQ_Spell* pSpell, int EffectID);
MQLIB_API const char* GetLDoNTheme(int LDTheme);
MQLIB_API bool TriggeringEffectSpell(eqlib::EQ_Spell* aSpell, int i);
MQLIB_API bool BuffStackTest(eqlib::EQ_Spell* aSpell, eqlib::EQ_Spell* bSpell,
	bool bIgnoreTriggeringEffects = false, bool bTriggeredEffectCheck = false);
MQLIB_API bool WillStackWith(const eqlib::EQ_Spell* testSpell, const eqlib::EQ_Spell* existingSpell);
MQLIB_API bool IsSpellTooPowerful(eqlib::PlayerClient* caster, eqlib::PlayerClient* target, eqlib::EQ_Spell* spell);
MQLIB_API uint32_t GetItemTimer(eqlib::ItemClient* pItem);
MQLIB_API eqlib::ItemClient* GetItemContentsByName(const char* ItemName);
MQLIB_API DWORD GetAvailableSlots(eqlib::ItemClient* pContainer, eqlib::ItemClient* pItem, int *firstavailableslot);
MQLIB_API bool LoH_HT_Ready();
MQLIB_API eqlib::ECombatState GetCombatState();

MQLIB_API bool LoadCfgFile(const char* Filename, bool Delayed = static_cast<bool>(MQ_FROM_PLUGIN));

/* MQ2GROUNDSPAWNS */

using EQGroundItemPtr = MQEQObjectPtr<eqlib::EQGroundItem>;
using EQPlacedItemPtr = MQEQObjectPtr<eqlib::EQPlacedItem>;
using AnyMQGroundItem = std::variant<std::monostate, EQGroundItemPtr, EQPlacedItemPtr>;

enum class MQGroundSpawnType
{ // this ordering needs to match the GroundSpawn::Object variant class ordering
	None,
	Ground,
	Placed
};

inline auto EQObjectID(eqlib::EQGroundItem* Object) { return Object->DropID; }
inline auto EQObjectID(eqlib::EQPlacedItem* Object) { return Object->RealEstateItemID; }

struct MQGroundSpawn
{
	MQGroundSpawnType Type;
	AnyMQGroundItem Object;

	// These ctors will automatically register the Object in the invalidation mapper for zoning
	MQLIB_OBJECT MQGroundSpawn(eqlib::EQGroundItem* Object) : Type(MQGroundSpawnType::Ground), Object(ObserveEQObject(Object)) {}
	MQLIB_OBJECT MQGroundSpawn(eqlib::EQPlacedItem* Object) : Type(MQGroundSpawnType::Placed), Object(ObserveEQObject(Object)) {}
	MQLIB_OBJECT MQGroundSpawn() : Type(MQGroundSpawnType::None), Object() {}

	MQLIB_OBJECT float Distance(eqlib::PlayerClient* pSpawn) const;
	MQLIB_OBJECT float Distance3D(eqlib::PlayerClient* pSpawn) const;
	MQLIB_OBJECT eqlib::CActorInterface* Actor() const;
	MQLIB_OBJECT eqlib::CXStr Name() const;
	MQLIB_OBJECT eqlib::CXStr DisplayName() const;
	MQLIB_OBJECT eqlib::CVector3 Position() const;
	MQLIB_OBJECT int ID() const;
	MQLIB_OBJECT int SubID() const;
	MQLIB_OBJECT int ZoneID() const;
	MQLIB_OBJECT float Heading() const;
	MQLIB_OBJECT MQGameObject ToGameObject() const;
	MQLIB_OBJECT void Reset();

	template <typename T> T* Get() const { static_assert(mq::always_false<T>::value, "Unsupported GroundSpawn Type."); }
	template <> MQLIB_OBJECT eqlib::EQGroundItem* Get<eqlib::EQGroundItem>() const;
	template <> MQLIB_OBJECT eqlib::EQPlacedItem* Get<eqlib::EQPlacedItem>() const;

	explicit operator bool() const { return Type != MQGroundSpawnType::None; }
};

inline bool operator==(const MQGroundSpawn& groundItem, eqlib::EQGroundItem* other)
{
	if (groundItem.Type != MQGroundSpawnType::Ground)
		return false;

	return groundItem.Get<eqlib::EQGroundItem>() == other;
}

inline bool operator==(eqlib::EQGroundItem* other, const MQGroundSpawn& groundItem)
{
	return groundItem == other;
}

inline bool operator==(const MQGroundSpawn& groundItem, eqlib::EQPlacedItem* other)
{
	if (groundItem.Type != MQGroundSpawnType::Placed)
		return false;

	return groundItem.Get<eqlib::EQPlacedItem>() == other;
}

inline bool operator==(eqlib::EQPlacedItem* other, const MQGroundSpawn& groundItem)
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
MQLIB_OBJECT eqlib::CXStr GetFriendlyNameForGroundItem(const eqlib::EQGroundItem* pItem);
MQLIB_OBJECT eqlib::CXStr GetFriendlyNameForPlacedItem(const eqlib::EQPlacedItem* pItem);
MQLIB_API char* GetFriendlyNameForGroundItem(eqlib::EQGroundItem* pItem, char* szName, size_t BufferSize);

inline auto EQObjectID(eqlib::PlayerClient* pSpawn) { return pSpawn->SpawnID; }
using ObservedSpawnPtr = MQEQObjectPtr<eqlib::PlayerClient>;

MQLIB_API void AddObservedEQObject(const std::shared_ptr<MQTransient>& Object);

// A.k.a. "Door target"
MQLIB_API void SetSwitchTarget(eqlib::EQSwitch* pSwitch);
MQLIB_API eqlib::EQSwitch* GetSwitchByID(int id);
// retrieves the closest switch with the specified name.
MQLIB_API eqlib::EQSwitch* FindSwitchByName(const char* szName = nullptr);


MQLIB_API void ClearSearchSpawn(MQSpawnSearch* pSearchSpawn);
MQLIB_API eqlib::PlayerClient* NthNearestSpawn(MQSpawnSearch* pSearchSpawn, int Nth, eqlib::PlayerClient* pOrigin, bool IncludeOrigin = false);
MQLIB_API int CountMatchingSpawns(MQSpawnSearch* pSearchSpawn, eqlib::PlayerClient* pOrigin, bool IncludeOrigin = false);
MQLIB_API eqlib::PlayerClient* SearchThroughSpawns(MQSpawnSearch* pSearchSpawn, eqlib::PlayerClient* pChar);
MQLIB_API bool SpawnMatchesSearch(MQSpawnSearch* pSearchSpawn, eqlib::PlayerClient* pChar, eqlib::PlayerClient* pSpawn);
MQLIB_API bool SearchSpawnMatchesSearchSpawn(MQSpawnSearch* pSearchSpawn1, MQSpawnSearch* pSearchSpawn2);
MQLIB_API const char* ParseSearchSpawnArgs(char* szArg, const char* szRest, MQSpawnSearch* pSearchSpawn);
MQLIB_API void ParseSearchSpawn(const char* Buffer, MQSpawnSearch* pSearchSpawn);
MQLIB_API char* FormatSearchSpawn(char* Buffer, size_t BufferSize, MQSpawnSearch* pSearchSpawn);
MQLIB_API bool IsPCNear(eqlib::PlayerClient* pSpawn, float Radius);
MQLIB_API bool IsInGroup(eqlib::PlayerClient* pSpawn, bool bCorpse = false);
MQLIB_API bool IsInFellowship(eqlib::PlayerClient* pSpawn, bool bCorpse = false);
MQLIB_API bool IsInRaid(eqlib::PlayerClient* pSpawn, bool bCorpse = false);
MQLIB_API bool IsAlert(eqlib::PlayerClient* pChar, eqlib::PlayerClient* pSpawn, uint32_t id);
MQLIB_API bool GetClosestAlert(eqlib::PlayerClient* pSpawn, uint32_t id);
MQLIB_API bool IsAlert(eqlib::PlayerClient* pChar, eqlib::PlayerClient* pSpawn, uint32_t List);
MQLIB_API bool CheckAlertForRecursion(MQSpawnSearch* pSearchSpawn, uint32_t id);
MQLIB_API void WriteFilterNames();
MQLIB_API int FindSpellListByName(const char* szName);
MQLIB_API float StateHeightMultiplier(DWORD StandState);
MQLIB_API eqlib::PlayerClient* GetClosestBanker(bool forInteraction = true);

MQLIB_API const char* GetFullZone(int ZoneID);
MQLIB_API int         GetZoneID(const char* ZoneShortName);
MQLIB_API const char* GetShortZone(int ZoneID);
MQLIB_API float       DistanceToSpawn3D(eqlib::PlayerClient* pChar, eqlib::PlayerClient* pSpawn);
MQLIB_API float       EstimatedDistanceToSpawn(eqlib::PlayerClient* pChar, eqlib::PlayerClient* pSpawn);
MQLIB_API bool        PlayerHasAAAbility(int AAIndex);
MQLIB_API const char* GetAANameByIndex(int AAIndex);
MQLIB_API int         GetAAIndexByName(const char* AAName);
MQLIB_API int         GetAAIndexByID(int ID);
MQLIB_API int         GetSkillIDFromName(const char* name);
MQLIB_API bool        InHoverState();
MQLIB_API int         GetGameState();
MQLIB_API int         GetWorldState();
MQLIB_API float       GetMeleeRange(eqlib::PlayerClient*, eqlib::PlayerClient*);
MQLIB_API uint32_t    GetSpellGemTimer(int nGem);
MQLIB_API uint32_t    GetSpellBuffTimer(int SpellID);
MQLIB_API bool        HasExpansion(int64_t nExpansion);
MQLIB_API void        ListMercAltAbilities();
MQLIB_API eqlib::ItemClient*   FindItemBySlot(int InvSlot, int BagSlot = -1, eqlib::ItemContainerInstance location = eqlib::eItemContainerPossessions);
MQLIB_API eqlib::ItemContainer* GetItemContainerByType(eqlib::ItemContainerInstance type);
   inline eqlib::ItemContainer* GetItemContainerByGlobalIndex(const eqlib::ItemGlobalIndex& index) { return GetItemContainerByType(index.GetLocation()); }
MQLIB_API eqlib::ItemClient*   FindItemByGlobalIndex(const eqlib::ItemGlobalIndex& idx);
   inline eqlib::ItemClient* FindItemBySlot(const eqlib::ItemGlobalIndex& idx) { return FindItemByGlobalIndex(idx); }
   DEPRECATE("Use FindItemByGlobalIndex instead of FindItemBySlot2")
   inline eqlib::ItemClient*   FindItemBySlot2(const eqlib::ItemGlobalIndex& idx) { return FindItemByGlobalIndex(idx); }
MQLIB_API eqlib::ItemClient*   FindItemByName(const char* pName, bool bExact = false);
MQLIB_API eqlib::ItemClient*   FindItemByID(int ItemID);
MQLIB_API int         FindItemCountByName(const char* pName);
MQLIB_API int         FindItemCountByID(int ItemID);
MQLIB_API int         FindInventoryItemCountByName(const char* pName, StringMatchType matchType = StringMatchType::CaseInsensitive,
                                                   int slotBegin = -1, int slotEnd = -1);
MQLIB_API eqlib::ItemClient* FindInventoryItemByName(const char* pName, StringMatchType matchType = StringMatchType::CaseInsensitive,
                                              int slotBegin = -1, int slotEnd = -1);
MQLIB_API int         FindInventoryItemCountByID(int ItemID, int slobBegin = -1, int slotEnd = -1);
MQLIB_API eqlib::ItemClient*   FindBankItemByName(const char* pName, bool bExact);
MQLIB_API eqlib::ItemClient*   FindBankItemByID(int ItemID);
MQLIB_API int         FindBankItemCountByName(const char* pName, bool bExact);
MQLIB_API int         FindBankItemCountByID(int ItemID);
MQLIB_API eqlib::CInvSlot*   GetInvSlot(const eqlib::ItemGlobalIndex& idx);
   inline eqlib::CInvSlot*   GetInvSlot(DWORD type, short Invslot, short Bagslot = -1) { return GetInvSlot(eqlib::ItemGlobalIndex(static_cast<eqlib::ItemContainerInstance>(type), eqlib::ItemIndex(Invslot, Bagslot))); }
   DEPRECATE("Use GetInvSlot instead of GetInvSlot2")
   inline eqlib::CInvSlot*   GetInvSlot2(const eqlib::ItemGlobalIndex& idx) { return GetInvSlot(idx); }
MQLIB_API bool        IsItemInsideContainer(eqlib::ItemClient* pItem);
MQLIB_API bool        ItemMatchesSearch(MQItemSearch& itemSearch, eqlib::ItemClient* pItem);
MQLIB_API bool        PickupItem(const eqlib::ItemGlobalIndex& index);
   inline bool        PickupItem(eqlib::ItemContainerInstance type, eqlib::ItemClient* pItem) { return PickupItem(pItem->GetItemLocation()); }
MQLIB_API bool        DropItem(const eqlib::ItemGlobalIndex& index);
   inline bool        DropItem(eqlib::ItemContainerInstance type, short InvSlot, short Bagslot) { return DropItem(eqlib::ItemGlobalIndex(type, eqlib::ItemIndex(InvSlot, Bagslot))); }
   DEPRECATE("Use DropItem instead of DropItem2")
   inline bool        DropItem2(eqlib::ItemContainerInstance type, short InvSlot, short Bagslot) { return DropItem(eqlib::ItemGlobalIndex(type, eqlib::ItemIndex(InvSlot, Bagslot))); }
MQLIB_API bool        ItemOnCursor();
MQLIB_API bool        OpenContainer(eqlib::ItemClient* pItem, bool hidden = false, bool allowTradeskill = false);
MQLIB_API bool        CloseContainer(eqlib::ItemClient* pItem);

// The number of available inventory slots are limited by expansion level.
MQLIB_API int         GetAvailableBagSlots();          // returns the number of bag slots that are enabled
MQLIB_API int         GetHighestAvailableBagSlot();    // returns the InvSlot of the highest bag slot that is enabled
MQLIB_API int         GetAvailableBankSlots();         // returns the number of bank slots that are enabled
MQLIB_API int         GetAvailableSharedBankSlots();   // returns the number of shared bank slots that are enabled

MQLIB_API    bool        HasSPA(eqlib::EQ_Spell* pSpell, eqlib::eEQSPA eSPA, bool bIncrease = false);
MQLIB_OBJECT bool        HasSPA(const eqlib::EQ_Affect& buff, eqlib::eEQSPA eSPA, bool bIncrease = false);

MQLIB_API    int         GetPlayerClass(const char* name);
MQLIB_API    bool        IsSpellUsableForClass(eqlib::EQ_Spell* pSpell, unsigned int classmask = 0);
MQLIB_OBJECT bool        IsSpellUsableForClass(const eqlib::EQ_Affect& buff, unsigned int classmask = 0);
MQLIB_API    int         GetSpellCategory(eqlib::EQ_Spell* pSpell);
MQLIB_OBJECT int         GetSpellCategory(const eqlib::EQ_Affect& buff);
MQLIB_API    int         GetSpellSubcategory(eqlib::EQ_Spell* pSpell);
MQLIB_OBJECT int         GetSpellSubcategory(const eqlib::EQ_Affect& buff);
MQLIB_API    eqlib::EQ_Spell*   GetSpellParent(int id);
MQLIB_API    int64_t     GetSpellCounters(eqlib::eEQSPA spa, const eqlib::EQ_Affect& buff); // Get spell counters of given spa for the given buff.
MQLIB_API    int64_t     GetMySpellCounters(eqlib::eEQSPA spa);                             // Get spell counters of given spa on my character.
MQLIB_API    int64_t     GetTotalSpellCounters(const eqlib::EQ_Affect& buff);               // Get total count of spell counters for the given buff.
MQLIB_API    int64_t     GetMyTotalSpellCounters();                                         // Get total count of spell counters for my character.
MQLIB_API    int         GetMeleeSpeedPctFromSpell(eqlib::EQ_Spell* pSpell, bool increase);
MQLIB_API    eqlib::EQ_Spell*   GetHighestLearnedSpellByGroupID(int dwSpellGroupID);
MQLIB_API    uint32_t    GetSpellID(eqlib::EQ_Spell* spell);
MQLIB_OBJECT uint32_t    GetSpellID(const eqlib::EQ_Affect& buff);
MQLIB_API    const char* GetSpellName(eqlib::EQ_Spell* spell);
MQLIB_OBJECT const char* GetSpellName(const eqlib::EQ_Affect& buff);
MQLIB_API    const char* GetSpellCaster(const eqlib::EQ_Affect& buff);
MQLIB_API    const char* GetPetSpellCaster(const eqlib::EQ_Affect& buff);
MQLIB_API    eqlib::eEQSPELLCAT GetSpellCategoryFromName(const char* category);
MQLIB_API    eqlib::eEQSPA      GetSPAFromName(const char* spa);

MQLIB_OBJECT int      GetSelfBuff(const std::function<bool(const eqlib::EQ_Affect&)>& fPredicate, int minSlot = 0, int maxSlot = -1);
MQLIB_OBJECT int      GetSelfBuff(const std::function<bool(eqlib::EQ_Spell*)>& fPredicate, int minSlot = 0, int maxSlot = -1);


MQLIB_API    const char* GetTeleportName(DWORD id);

MQLIB_API HMODULE GetCurrentModule();

///////////////////////////////////////////////////////////////////////////////////////////////////
// Functions that were built into commands and people used DoCommand to execute                  //

MQLIB_API void AttackRanged(eqlib::PlayerClient* pRangedTarget = eqlib::pTarget);
MQLIB_API void UseAbility(const char* sAbility);

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

MQLIB_API bool WillFitInBank(eqlib::ItemClient* pContent);
MQLIB_API bool WillFitInInventory(eqlib::ItemClient* pContent);

/* MQ2ANONYMIZE */
MQLIB_API bool IsAnonymized();
MQLIB_OBJECT eqlib::CXStr Anonymize(const eqlib::CXStr& Text);
MQLIB_OBJECT eqlib::CXStr& PluginAnonymize(eqlib::CXStr& Text);

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

using fMQTokenMessageCmd = void(*)(const TokenTextParam&);

MQLIB_OBJECT int AddTokenMessageCmd(int StringID, fMQTokenMessageCmd Command);
MQLIB_OBJECT void RemoveTokenMessageCmd(int StringID, int CallbackID);

//----------------------------------------------------------------------------

MQLIB_API eqlib::MembershipLevel GetMembershipLevel();
inline DEPRECATE("Use GetMembershipLevel instead of GetSubscriptionLevel") int GetSubscriptionLevel() { return (int)GetMembershipLevel(); }

} // namespace mq

#include "mq/api/Achievements.h"
#include "mq/api/Spells.h"

#include "GraphicsEngine.h"  // TODO: Move exports to mq/api header

#if __has_include("../private/MQ2Main-private.h")
#include "../private/MQ2Main-private.h"
#endif
