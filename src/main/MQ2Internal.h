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

enum ePVPServer
{
	PVP_NONE = 0,
	PVP_TEAM = 1,
	PVP_RALLOS = 2, // the only PVP server type still alive
	PVP_SULLON = 3,
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
	int MaxLevel = MAX_NPC_LEVEL;
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

struct MQMacroLine
{
	std::string Command;

	int LoopStart = 0;
	// used for loops/while if its 0 no action is taken, otherwise it will jump to the line indicated.
	int LoopEnd = 0;

	std::string SourceFile;
	int LineNumber = 0;

#ifdef MQ2_PROFILING
	int ExecutionCount = 0;
	uint64_t ExecutionTime = 0;
#endif

	MQMacroLine(std::string Line, std::string sourceFile, int lineNumber)
		: Command(std::move(Line))
		, SourceFile(std::move(sourceFile))
		, LineNumber(lineNumber)
	{}

	MQMacroLine(const MQMacroLine&) = delete;
	MQMacroLine& operator=(const MQMacroLine&) = delete;
};
using MACROLINE DEPRECATE("Use MQMacroLine instead MACROLINE") = MQMacroLine;
using PMACROLINE DEPRECATE("Use MQMacroLine* instead of PMACROLINE") = MQMacroLine;

struct MQMacroBlock
{
	std::string Name;                           // our macro Name
	bool Paused = false;
	int CurrIndex = 0;                          // the current macro line we are on
	int BindStackIndex = -1;                    // where we were at before calling the bind.
	std::string BindCmd;                        // the actual command including parameters
	std::map<int, MQMacroLine> Line;
	bool Removed = false;

	MQMacroBlock(std::string name) : Name(std::move(name)) {}

	MQMacroBlock(const MQMacroBlock&) = delete;
	MQMacroBlock& operator=(const MQMacroBlock&) = delete;
};
using MQMacroBlockPtr = std::shared_ptr<MQMacroBlock>;

using PMACROBLOCK DEPRECATE("Use MQMacroBlockPtr instead of PMACROBLOCK") = MQMacroBlockPtr;
using MACROBLOCK DEPRECATE("Use MQMacroBlock instead MACROBLOCK") = MQMacroBlock;

struct MQTimer
{
	std::string Name;
	uint32_t Original = 0;
	uint32_t Current = 0;
	MQTimer* pNext = nullptr;
	MQTimer* pPrev = nullptr;
};
using MQTIMER DEPRECATE("Use MQTimer instead of MQTIMER") = MQTimer;
using PMQTIMER DEPRECATE("Use MQTimer* instead of PMQTIMER") = MQTimer*;

struct MQKeyPress
{
	uint16_t KeyId = 0;
	bool     Pressed = false;

	MQKeyPress* pNext = nullptr;
};
using KEYPRESS DEPRECATE("Use MQKeyPress instead of KEYPRESS") = MQKeyPress;

struct ITEMDB {
	ITEMDB* pNext;
	DWORD ID;
	DWORD StackSize;
	char szName[256];
};
using PITEMDB DEPRECATE("Use ITEMDB* instead of PITEMDB") = ITEMDB*;

struct MQDefine
{
	char szName[MAX_STRING];
	char szReplace[MAX_STRING];

	MQDefine* pNext = nullptr;
};

struct MQEventList
{
	char szName[MAX_STRING];
	char szMatch[MAX_STRING];
	int pEventFunc = 0;
	DWORD BlechID = 0;

	MQEventList* pNext = nullptr;
};
using EVENTLIST DEPRECATE("Use MQEventList instead of EVENTLIST") = MQEventList;
using PEVENTLIST DEPRECATE("Use MQEventList* instead PEVENTLIST") = MQEventList *;

struct MQBindList
{
	char szName[MAX_STRING];
	char szFuncName[MAX_STRING];
	bool Parse = true;

	MQBindList* pNext = nullptr;
};

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

struct MQGroundPending
{
	GROUNDITEM* pGroundItem = nullptr;
	MQGroundPending* pLast = nullptr;
	MQGroundPending* pNext = nullptr;
};

// Like lightweight plugins, but these are internal to mq2main
struct MQModule
{
	char                 name[64] = { 0 };
	bool                 canUnload = false;
	fMQInitializePlugin  Initialize = 0;
	fMQShutdownPlugin    Shutdown = 0;
	fMQPulse             Pulse = 0;
	fMQSetGameState      SetGameState = 0;
	fMQUpdateImGui       UpdateImGui = 0;
	fMQZoned             Zoned = 0;
	fMQWriteChatColor    WriteChatColor = 0;
	fMQSpawn             SpawnAdded = 0;
	fMQSpawn             SpawnRemoved = 0;
	fMQBeginZone         BeginZone = 0;
	fMQEndZone           EndZone = 0;
	fMQLoadPlugin        LoadPlugin = 0;
	fMQUnloadPlugin      UnloadPlugin = 0;
	fMQCleanUI           CleanUI = 0;
	fMQReloadUI          ReloadUI = 0;
	fMQPostUnloadPlugin  OnPostUnloadPlugin = 0;

	bool                 loaded = false;
	bool                 manualUnload = false;
};

void InitializeInternalModules();
void AddInternalModule(MQModule* module, bool manualUnload = false);
void RemoveInternalModule(MQModule* module);

struct ModuleInitializer;
void AddStaticInitializationModule(ModuleInitializer* module);

struct ModuleInitializer
{
	ModuleInitializer(MQModule* thisModule)
		: module(thisModule)
	{
		AddStaticInitializationModule(this);
	}

	ModuleInitializer* next = nullptr;
	MQModule* module = nullptr;
};

#if _M_AMD64
#define FORCE_UNDEFINED_SYMBOL(x) __pragma(comment (linker, "/export:" #x))
#else
#define FORCE_UNDEFINED_SYMBOL(x) __pragma(comment (linker, "/export:_" #x))
#endif

#define DECLARE_MODULE_INITIALIZER(moduleRecord) \
	extern "C" ModuleInitializer s_moduleInitializer ## moduleRecord { &moduleRecord } \
	FORCE_UNDEFINED_SYMBOL(s_moduleInitializer ## moduleRecord);



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

// TODO: Move to MQ2Windows.h (doesn't exist yet)
class CCustomWnd : public CSidlScreenWnd
{
public:
	explicit CCustomWnd(const CXStr& screenpiece)
		: CSidlScreenWnd(nullptr, screenpiece, eIniFlag_All)
	{
		Init();
	}

	explicit CCustomWnd(const char* screenpiece) : CSidlScreenWnd(0, screenpiece, eIniFlag_All)
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

// TODO: Move to MQ2Windows.h (doesn't exist yet)
class CCustomMenu : public CContextMenu
{
public:
	CCustomMenu(CXWnd* pParent, uint32_t MenuID, const CXRect& rect) : CContextMenu(pParent, MenuID, rect)
	{
	}

	~CCustomMenu() override
	{
	}
};

//============================================================================

template <class Any>
class CIndex
{
public:
	DEPRECATE("Use std::vector instead of CIndex") CIndex() = default;

	DEPRECATE("Use std::vector instead of CIndex") CIndex(size_t InitialSize)
	{
		Resize(InitialSize);
	}

	~CIndex()
	{
		std::scoped_lock lock(m_mutex);

		delete[] m_list;
		m_size = 0;
	}

	Any& operator+=(Any Value)
	{
		return m_list[GetUnused()] = Value;
	}

	Any& operator[](size_t Index)
	{
		return m_list[Index];
	}

	void Cleanup()
	{
		std::scoped_lock lock(m_mutex);

		for (size_t index = 0; index < m_size; index++)
		{
			if (m_list[index])
			{
				delete m_list[index];
				m_list[index] = nullptr;
			}
		}
	}

	void Resize(size_t newSize)
	{
		std::scoped_lock lock(m_mutex);
		if (newSize > m_size)
		{
			Any* newList = new Any[newSize];
			for (size_t i = 0; i < newSize; ++i)
				newList[i] = nullptr;

			memset(newList, 0, newSize * sizeof(Any));
			memcpy(newList, m_list, m_size * sizeof(Any));

			delete[] m_list;
			m_list = newList;
			m_size = newSize;
		}
	}

	size_t GetSize() const { return m_size; }

	// gets the next unused index, resizing if necessary
	size_t GetUnused()
	{
		std::scoped_lock lock(m_mutex);

		size_t index = 0;
		for (index = 0; index < m_size; index++)
		{
			if (!m_list[index])
				return index;
		}

		Resize(m_size + 10);
		return index;
	}

	size_t Count() const
	{
		std::scoped_lock lock(m_mutex);

		size_t ret = 0;
		for (size_t i = 0; i < m_size; i++)
		{
			if (m_list[i])
				ret++;
		}
		return ret;
	}

	//__declspec(property(get = GetSize)) size_t Size;

private:
	size_t m_size = 0;
	Any* m_list = nullptr;
	std::recursive_mutex m_mutex;
};

//============================================================================

struct MQRank
{
	MQRank(SPAWNINFO* pSpawn, float distanceSquared)
		: VarPtr(pSpawn)
		, Value(distanceSquared)
	{}

	struct MQRankSpawnPtr
	{
		MQRankSpawnPtr(SPAWNINFO* pSpawn) : Ptr(pSpawn) {}

		SPAWNINFO* Ptr = nullptr;
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
	MQSpawnArrayItem(SPAWNINFO* pSpawn, float DistanceSquared)
		: MQRank(pSpawn, DistanceSquared)
	{
	}

	float GetDistanceSquared() const { return Value.DistSq; }
	float GetDistance() const { return Value.get_Distance(); }

	SPAWNINFO* GetSpawn() const { return VarPtr.Ptr; }
};

struct MQLoop
{
	enum Type { None, For, While };
	Type type = None;
	int	firstLine = 0;
	int lastLine = 0;
	std::string forVariable;
};

struct MQMacroStack
{
	bool bIsBind = false;
	int LocationIndex = 0;
	MQDataVar* Parameters = nullptr;
	MQDataVar* LocalVariables = nullptr;
	std::vector<MQLoop> loopStack;
	std::string Return;

	MQMacroStack* pNext = nullptr;

	MQMacroStack(int locationIndex)
		: LocationIndex(locationIndex)
	{}

	MQMacroStack(const MQMacroStack&) = delete;
	MQMacroStack& operator=(const MQMacroStack&) = delete;
};
using PMACROSTACK DEPRECATE("Use MQMacroStack* instead of PMACROSTACK") = MQMacroStack *;
using MACROSTACK DEPRECATE("Use MQMacroStack instead of MACROSTACK") = MQMacroStack;

enum MQEventType {
	EVENT_CHAT = 0,
	EVENT_TIMER,
	EVENT_CUSTOM,
	EVENT_EVAL,
	EVENT_EXEC,
	EVENT_PULSE,
	EVENT_SHUTDOWN,
	EVENT_BREAK,

	NUM_EVENTS
};

struct MQEventQueue
{
	MQEventQueue* pPrev = nullptr;
	MQEventQueue* pNext = nullptr;
	MQEventType   Type = EVENT_CHAT;
	std::string   Name;
	MQEventList*  pEventList = nullptr;
	MQDataVar*    Parameters = nullptr;
};
using EVENTQUEUE DEPRECATE("Use MQEventQueue instead of EVENTQUEUE") = MQEventQueue;
using PEVENTQUEUE DEPRECATE("Use MQEventQueue* instead of PEVENTQUEUE") = MQEventQueue *;

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
/*0x00*/ eGroundObjectType  Type;
/*0x04*/ EQGroundItem       GroundItem;         // for conversion between switch and grounditems
/*0x84*/ void*              ObjPtr;             // EQPlacedItem *
/*0x88*/ EQGroundItem*      pGroundItem;
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
	CActorInterface* actor = nullptr;

	bool valid = false;

	const std::string& GetDisplayName() const
	{
		if (!displayName.empty())
			return displayName;

		return name;
	}
};

MQGameObject ToGameObject(const EQGroundItem& groundItem);
MQGameObject ToGameObject(const EQPlacedItem& placedItem);
MQGameObject ToGameObject(const MQGroundSpawn& groundSpawn);
MQGameObject ToGameObject(const SPAWNINFO* spawnInfo);
MQGameObject ToGameObject(float y, float x, float z);
MQGameObject ToGameObject(const EQSwitch* pSwitch);

//----------------------------------------------------------------------------

int GetTriggerSPA(SPELL* pSpell);

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

//----------------------------------------------------------------------------

class MainImpl : public MainInterface
{
public:
	MainImpl();
	~MainImpl() override;

	void DoMainThreadInitialization();

	bool AddTopLevelObject(
		const char* name,
		MQTopLevelObjectFunction callback,
		const MQPluginHandle& pluginHandle) override;

	bool RemoveTopLevelObject(
		const char* name,
		const MQPluginHandle& pluginHandle) override;

	MQTopLevelObject* FindTopLevelObject(const char* name) override;

	void SendToActor(
		postoffice::Dropbox* dropbox,
		const postoffice::Address& address,
		const std::string& data,
		const postoffice::ResponseCallbackAPI& callback,
		const MQPluginHandle& pluginHandle) override;

	void ReplyToActor(
		postoffice::Dropbox* dropbox,
		const std::shared_ptr<postoffice::Message>& message,
		const std::string& data,
		uint8_t status,
		const MQPluginHandle& pluginHandle) override;

	postoffice::Dropbox* AddActor(
		const char* localAddress,
		postoffice::ReceiveCallbackAPI&& receive,
		const MQPluginHandle& pluginHandle) override;

	void RemoveActor(
		postoffice::Dropbox*& dropbox,
		const MQPluginHandle& pluginHandle) override;

	// Commands
	bool AddCommand(
		std::string_view command,
		MQCommandHandler handler,
		bool eq,
		bool parse,
		bool inGame,
		const MQPluginHandle& pluginHandle) override;

	bool RemoveCommand(
		std::string_view command,
		const MQPluginHandle& pluginHandle) override;

	bool IsCommand(std::string_view command) const override;

	void DoCommand(
		const char* command,
		bool delayed,
		const MQPluginHandle& pluginHandle) override;

	void TimedCommand(
		const char* command,
		int msDelay,
		const MQPluginHandle& pluginHandle) override;

	// Aliases
	bool AddAlias(
		const std::string& shortCommand,
		const std::string& longCommand,
		bool persist,
		const MQPluginHandle& pluginHandle) override;
	bool RemoveAlias(
		const std::string& shortCommand,
		const MQPluginHandle& pluginHandle) override;
	bool IsAlias(
		const std::string& alias) const override;

	// Detours
	bool CreateDetour(uintptr_t address, void** target, void* detour, std::string_view name,
		const MQPluginHandle& pluginHandle) override;
	bool CreateDetour(uintptr_t address, size_t width, std::string_view name, const MQPluginHandle& pluginHandle) override;
	bool RemoveDetour(uintptr_t address, const MQPluginHandle& pluginHandle) override;
};

extern MainImpl* gpMainAPI;

MQPluginHandle CreatePluginHandle();

} // namespace mq
