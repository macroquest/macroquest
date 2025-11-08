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

#include "mq/api/MacroAPI.h"
#include "mq/api/Main.h"
#include "mq/api/PluginAPI.h"
#include "mq/base/PluginHandle.h"

#include <map>
#include <memory>
#include <mutex>
#include <vector>
#include <variant>

namespace mq {

enum eAdventureTheme
{
	eAT_None,
	eAT_DeepGuk,
	eAT_Miraguls,
	eAT_Mistmoore,
	eAT_Rujarkian,
	eAT_Takish,
};

enum eSpawnType
{
	NONE = 0,
	PC,
	MOUNT,
	PET,
	PCPET,
	NPCPET,
	XTARHATER,
	NPC,
	CORPSE,
	TRIGGER,
	TRAP,
	TIMER,
	UNTARGETABLE,
	CHEST,
	ITEM,
	AURA,
	OBJECT,
	BANNER,
	CAMPFIRE,
	MERCENARY,
	FLYER,
	NPCCORPSE = 2000,
	PCCORPSE,
};

enum class SearchSortBy
{
	Level = 0,
	Name = 1,
	Race = 2,
	Class = 3,
	Distance = 4,
	Guild = 5,
	Id = 6
};

struct MQSpawnSearch
{
	int MinLevel = 0;
	int MaxLevel = eqlib::MAX_NPC_LEVEL;
	eSpawnType SpawnType = NONE;
	uint32_t SpawnID = 0;
	uint32_t FromSpawnID = 0;
	float Radius = 0;
	char szName[MAX_STRING] = { 0 };
	char szBodyType[MAX_STRING] = { 0 };
	char szRace[MAX_STRING] = { 0 };
	char szClass[MAX_STRING] = { 0 };
	char szLight[MAX_STRING] = { 0 };
	int64_t GuildID = -1;
	bool bSpawnID = false;
	bool bNotNearAlert = false;
	bool bNearAlert = false;
	bool bNoAlert = false;
	bool bAlert = false;
	bool bLFG = false;
	bool bTrader = false;
	bool bLight = false;
	bool bTargNext = false;
	bool bTargPrev = false;
	bool bGroup = false;
	bool bFellowship = false;
	bool bXTarHater = false;
	bool bNoGroup = false;
	bool bRaid = false;
	bool bGM = false;
	bool bNamed = false;
	bool bMerchant = false;
	bool bBanker = false;
	bool bTributeMaster = false;
	bool bKnight = false;
	bool bTank = false;
	bool bHealer = false;
	bool bDps = false;
	bool bSlower = false;
	bool bAura = false;
	bool bBanner = false;
	bool bCampfire = false;
	uint32_t NotID = 0;
	uint32_t NotNearAlertList = 0;
	uint32_t NearAlertList = 0;
	uint32_t NoAlertList = 0;
	uint32_t AlertList = 0;
	double ZRadius = 10000.0f;
	double FRadius = 10000.0f;
	float xLoc = 0;
	float yLoc = 0;
	float zLoc = 0;
	bool bKnownLocation = false;
	bool bNoPet = false;
	SearchSortBy SortBy = SearchSortBy::Level;
	bool bNoGuild = false;
	bool bLoS = false;
	bool bExactName = false;
	bool bTargetable = false;
	uint32_t PlayerState = 0;
};
using SEARCHSPAWN DEPRECATE("Use MQSpawnSearch instead of SEARCHSPAWN") = MQSpawnSearch;
using PSEARCHSPAWN DEPRECATE("Use MQSpawnSearch* instead of PSEARCHSPAWN") = MQSpawnSearch *;

enum SearchItemFlag
{
	Lore = 1,
	NoDrop = 2,
	NoRent = 3,
	Magic = 4,
	Book = 5,
	Pack = 6,
	Combinable = 7,
	Summoned = 8,
	Weapon = 9,
	Normal = 10,
	Instrument = 11,

	// item locations...
	Worn = 100,
	Inventory = 101,
	Bank = 102,
	Merchant = 103,
	Corpse = 104,
	SharedBank = 105,
	Trade = 106,
	Bazaar = 107,
	Inspect = 108,
	Enviro = 109,
};

struct MQItemSearch
{
	char FlagMask[MAX_STRING];
	char Flag[MAX_STRING];

	char szName[MAX_STRING];
	char szStat[MAX_STRING];
	char szSlot[MAX_STRING];
	char szRace[MAX_STRING];
	char szClass[MAX_STRING];

	uint32_t ID = 0;
};
using SEARCHITEM DEPRECATE("Use MQItemSearch instead of SEARCHITEM") = MQItemSearch;
using PSEARCHITEM DEPRECATE("Use MQItemSearch instead of PSEARCHITEM") = MQItemSearch*;

struct MQWhoFilter
{
	bool Lastname = true;
	bool Class = true;
	bool Race = true;
	bool Body = false;
	bool Level = true;
	bool Distance = true;
	bool GM = true;
	bool Guild = true;
	bool LD = true;
	bool Sneak = true;
	bool Anon = true;
	bool LFG = true;
	bool NPCTag = true;
	bool SpawnID = false;
	bool Trader = true;
	bool AFK = true;
	bool Light = false;
	bool Holding = true;
	bool ConColor = false;
	bool Invisible = false;
};
using SWHOFILTER DEPRECATE("Use MQWhoFilter instead of SWHOFILTER") = MQWhoFilter;
using PSWHOFILTER DEPRECATE("Use MQWhoFilter* instead of PSWHOFILTER") = MQWhoFilter*;

struct MQWhoSort
{
	char szName[MAX_STRING] = { 0 };
	char szLine[MAX_STRING] = { 0 };
	uint8_t Level = 0;
	uint32_t SpawnID = 0;
	float Distance = 0;
	int Class = 0;
	int Race = 0;
	int64_t GuildID = 0;
};
using WHOSORT DEPRECATE("Use MQWhoSort instead of WHOSORT") = MQWhoSort;
using PWHOSORT DEPRECATE("Use MQWhoSort* instead PWHOSORT") = MQWhoSort*;


struct ITEMDB {
	ITEMDB* pNext;
	DWORD ID;
	DWORD StackSize;
	char szName[256];
};
using PITEMDB DEPRECATE("Use ITEMDB* instead of PITEMDB") = ITEMDB*;

struct MQFilter
{
	MQFilter(const char* szFilter, int length, bool& bEnabled)
		: pEnabled(&bEnabled)
		, Length(length == -1 ? strlen(szFilter) : length)
	{
		strcpy_s(FilterText, szFilter);
	}

	char FilterText[MAX_STRING];
	size_t Length;
	bool* pEnabled;
	MQFilter* pNext = nullptr;
};
using FILTER DEPRECATE("use MQFilter instead FILTER") = MQFilter;
using PFILTER DEPRECATE("use MQFilter* instead of PFILTER") = MQFilter*;

//============================================================================

class CMQ2Alerts
{
public:
	CMQ2Alerts() = default;
	~CMQ2Alerts() = default;

	MQLIB_OBJECT bool AddNewAlertList(uint32_t id, MQSpawnSearch* pSearchSpawn);
	MQLIB_OBJECT bool RemoveAlertFromList(uint32_t id, MQSpawnSearch* pSearchSpawn);

	MQLIB_OBJECT bool GetAlert(uint32_t id, std::vector<MQSpawnSearch>& ss);
	MQLIB_OBJECT size_t GetCount(uint32_t id) const;
	MQLIB_OBJECT bool AlertExist(uint32_t id);

	MQLIB_OBJECT bool ListAlerts(char* szOut, size_t max);
	MQLIB_OBJECT void FreeAlerts(uint32_t id);

private:
	mutable std::mutex m_mutex;
	std::map<uint32_t, std::vector<MQSpawnSearch>> m_alertMap;
};

//============================================================================

class CCustomWnd : public eqlib::CSidlScreenWnd
{
public:
	explicit CCustomWnd(const eqlib::CXStr& screenpiece)
		: CSidlScreenWnd(nullptr, screenpiece, eqlib::eIniFlag_All)
	{
		Init();
	}

	explicit CCustomWnd(const char* screenpiece)
		: CSidlScreenWnd(nullptr, screenpiece, eqlib::eIniFlag_All)
	{
		Init();
	}

	~CCustomWnd() override
	{
	}

private:
	void Init()
	{
		CreateChildrenFromSidl();
		Show(true);

		SetEscapable(false);
	}

};

//============================================================================

class CCustomMenu : public eqlib::CContextMenu
{
public:
	CCustomMenu(CXWnd* pParent, uint32_t MenuID, const eqlib::CXRect& rect)
		: CContextMenu(pParent, MenuID, rect)
	{
	}

	~CCustomMenu() override
	{
	}
};

//============================================================================

struct MQRank
{
	MQRank(eqlib::PlayerClient* pSpawn, float distanceSquared)
		: VarPtr(pSpawn)
		, Value(distanceSquared)
	{}

	struct MQRankSpawnPtr
	{
		MQRankSpawnPtr(eqlib::PlayerClient* pSpawn) : Ptr(pSpawn) {}

		eqlib::PlayerClient* Ptr = nullptr;
	};
	MQRankSpawnPtr VarPtr;

	struct MQRankValue
	{
		MQRankValue(float value) : DistSq(value) {}

		float DistSq = 0.0f;

		float get_Distance() const
		{
			if (floatValue != 0.0f)
				return floatValue;

			if (DistSq == 0.0f)
				return 0.0;
			floatValue = sqrt(DistSq);
			return floatValue;
		}
		__declspec(property(get = get_Distance)) float Float;

	private:
		mutable float floatValue = 0.0f; // holds the actual distance, is zero until accessed.
	};
	MQRankValue Value;
};
using MQRANK DEPRECATE("Use MQRank instead") = MQRank;

static bool pMQRankFloatCompare(const MQRank* A, const MQRank* B)
{
	return A->Value.DistSq < B->Value.DistSq;
}

static bool MQRankFloatCompare(const MQRank& A, const MQRank& B)
{
	return A.Value.DistSq < B.Value.DistSq;
}

// This replaces MQRank. We keep the MQRank part of this for backwards
// compatability until the deprecated parts are removed.
struct MQSpawnArrayItem : public MQRank
{
	MQSpawnArrayItem(eqlib::PlayerClient* pSpawn, float DistanceSquared)
		: MQRank(pSpawn, DistanceSquared)
	{
	}

	float GetDistanceSquared() const { return Value.DistSq; }
	float GetDistance() const { return Value.get_Distance(); }

	eqlib::PlayerClient* GetSpawn() const { return VarPtr.Ptr; }
};

//----------------------------------------------------------------------------

// This structure is deprecated
enum eGroundObjectType
{
	GO_None,
	GO_GroundType,
	GO_ObjectType
};

struct MQGroundObject
{
/*0x00*/ eGroundObjectType    Type;
/*0x04*/ eqlib::EQGroundItem  GroundItem;         // for conversion between switch and grounditems
/*0x84*/ void*                ObjPtr;             // EQPlacedItem *
/*0x88*/ eqlib::EQGroundItem* pGroundItem;
/*0x8c*/

	// Currently necessary because of MQ2DataTypes
	MQGroundObject() { ZeroMemory(this, sizeof(MQGroundObject)); }
};

enum class eGameObjectType {
	None,
	GroundItem,
	PlaceableItem,
	Spawn,
	SpawnTarget,
	Location,
	Switch,
};

enum eFaceCommandFlags : uint8_t {
	FaceFlags_None                        = 0,
	FaceFlags_FaceAway                    = 0x01,
	FaceFlags_Predict                     = 0x02,
	FaceFlags_Fast                        = 0x04,
	FaceFlags_NoLook                      = 0x08,
	FaceFlags_HeadingOnly                 = 0x10,
};

// generic structure for storing positional information about an object
struct MQGameObject
{
	eGameObjectType type = eGameObjectType::None;
	uint32_t id = 0;
	uint32_t subId = 0;
	std::string name;

	float y = 0.f;
	float x = 0.f;
	float z = 0.f;
	float heading = 0.f;
	std::string displayName;

	// optional params
	float velocityY = 0.f;
	float velocityX = 0.f;
	float velocityZ = 0.f;
	float height = 0.f;
	eqlib::CActorInterface* actor = nullptr;

	bool valid = false;

	const std::string& GetDisplayName() const
	{
		if (!displayName.empty())
			return displayName;

		return name;
	}
};

struct MQGroundSpawn;

MQGameObject ToGameObject(const eqlib::EQGroundItem& groundItem);
MQGameObject ToGameObject(const eqlib::EQPlacedItem& placedItem);
MQGameObject ToGameObject(const MQGroundSpawn& groundSpawn);
MQGameObject ToGameObject(const eqlib::PlayerClient* spawnInfo);
MQGameObject ToGameObject(float y, float x, float z);
MQGameObject ToGameObject(const eqlib::EQSwitch* pSwitch);

//----------------------------------------------------------------------------

int GetTriggerSPA(eqlib::EQ_Spell* pSpell);

// this is a helper class to help us deprecate global variables
template <typename T>
class Property
{
private:
	T(*Getter)();
	T(*Setter)(const T&);

public:
	Property(T(*Getter)(), T(*Setter)(const T&)) : Getter(Getter), Setter(Setter) {}

	operator T() const
	{
		return Getter();
	}

	T operator=(const T& other)
	{
		return Setter(other);
	}

	bool operator==(const T& other) const
	{
		return Getter() == other;
	}
};

// need to specialize to pointers for special handling of them
template <typename T>
class Property<T*>
{
private:
	T*(*Getter)();
	T*(*Setter)(T*);

public:
	Property(T*(*Getter)(), T*(*Setter)(T*)) : Getter(Getter), Setter(Setter) {}

	operator T*() const
	{
		return Getter();
	}

	T* operator=(T* other)
	{
		return Setter(other);
	}

	bool operator==(T* other) const
	{
		return Getter() == other;
	}

	T& operator*()
	{
		return *Getter();
	}

	T* operator->()
	{
		return Getter();
	}
};

//----------------------------------------------------------------------------
// actual internals

void RefreshKeyRingWindow();

//----------------------------------------------------------------------------
bool GetFilteredModules(HANDLE hProcess, HMODULE* hModule, DWORD cb, DWORD* lpcbNeeded,
	const std::function<bool(HMODULE)>& filter);
bool GetFilteredProcesses(DWORD* lpidProcess, DWORD cb, DWORD* lpcbNeeded,
	const std::function<bool(std::string_view)>& filter);
std::string GetProcessName(DWORD processID);
bool IsMacroQuestModule(HMODULE hModule, bool getMacroQuestModules = false);
bool IsMacroQuestProcess(std::string_view path, bool getMacroQuestProcesses = false);
bool IsMacroQuestProcess(DWORD dwProcessID, bool getMacroQuestProcesses = false);
bool IsModuleSubstring(HMODULE hModule, std::wstring_view searchString);
std::string GetCurrentUI();

} // namespace mq
