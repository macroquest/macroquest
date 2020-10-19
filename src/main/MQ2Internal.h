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

#include <map>
#include <memory>
#include <mutex>
#include <vector>
#include <variant>

namespace mq {

namespace datatypes {
class MQ2Type;
}

using datatypes::MQ2Type;

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
	bool bNoGuild;
	bool bLoS;
	bool bExactName;
	bool bTargetable;
	uint32_t PlayerState;
};
using SEARCHSPAWN [[deprecated("Use MQSpawnSearch instead")]] = MQSpawnSearch;
using PSEARCHSPAWN [[deprecated("Use MQSpawnSearch* instead")]] = MQSpawnSearch *;

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
using SEARCHITEM [[deprecated("Use MQItemSearch instead")]] = MQItemSearch;
using PSEARCHITEM [[deprecated("Use MQItemSearch instead")]] = MQItemSearch*;

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
using SWHOFILTER [[deprecated("Use MQWhoFilter instead")]] = MQWhoFilter;
using PSWHOFILTER [[deprecated("Use MQWhoFilter* instead")]] = MQWhoFilter*;

struct MQWhoSort
{
	char szName[MAX_STRING];
	char szLine[MAX_STRING];
	uint8_t Level = 0;
	uint32_t SpawnID = 0;
	float Distance = 0;
	int Class = 0;
	int Race = 0;
	int64_t GuildID;
};
using WHOSORT [[deprecated("Use MQWhoSort instead")]] = MQWhoSort;
using PWHOSORT [[deprecated("Use MQWhoSort* instead")]] = MQWhoSort*;

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
using PMACROLINE [[deprecated("Use MQMacroLine* instead")]] = MQMacroLine;
using MACROLINE [[deprecated("Use MQMacroLine instead")]] = MQMacroLine;

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

using PMACROBLOCK [[deprecated("Use MQMacroBlockPtr instead")]] = MQMacroBlockPtr;
using MACROBLOCK [[deprecated("Use MQMacroBlock instead")]] = MQMacroBlock;

struct MQTimer
{
	std::string Name;
	uint32_t Original = 0;
	uint32_t Current = 0;
	MQTimer* pNext = nullptr;
	MQTimer* pPrev = nullptr;
};
using MQTIMER [[deprecated("Use MQTimer instead")]] = MQTimer;
using PMQTIMER [[deprecated("Use MQTimer* instead")]] = MQTimer*;

struct MQKeyPress
{
	uint16_t KeyId = 0;
	bool     Pressed = false;

	MQKeyPress* pNext = nullptr;
};
using KEYPRESS [[deprecated("Use MQKeyPress instead")]] = MQKeyPress;
typedef struct _ITEMDB {
	struct _ITEMDB* pNext;
	DWORD ID;
	DWORD StackSize;
	char szName[256];
} ITEMDB, * PITEMDB;

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
using EVENTLIST [[deprecated("Use MQEventList instead")]] = MQEventList;
using PEVENTLIST [[deprecated("Use MQEventList* instead")]] = MQEventList *;

struct MQBindList
{
	char szName[MAX_STRING];
	char szFuncName[MAX_STRING];
	bool Parse = true;

	MQBindList* pNext = nullptr;
};
using BINDLIST [[deprecated("Use MQBindList instead")]] = MQBindList;
using PBINDLIST [[deprecated("Use MQBindList* instead")]] = MQBindList *;

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
using FILTER [[deprecated("use MQFilter instead")]] = MQFilter;
using PFILTER [[deprecated("use MQFilter* instead")]] = MQFilter*;

struct MQBenchmark
{
	std::string Name;
	std::chrono::steady_clock::time_point Entry;
	std::chrono::microseconds LastTime = std::chrono::microseconds::zero();
	std::chrono::microseconds TotalTime = std::chrono::microseconds::zero();
	uint64_t Count = 0;

	MQBenchmark(const std::string& name) : Name(name) {}
};

struct MQGroundPending
{
	GROUNDITEM* pGroundItem = nullptr;
	MQGroundPending* pLast = nullptr;
	MQGroundPending* pNext = nullptr;
};

struct MQPlugin
{
	char                 szFilename[MAX_PATH] = { 0 };
	HMODULE              hModule = nullptr;
	float                fpVersion = 1.0;
	bool                 bCustom = false;
	fMQInitializePlugin  Initialize = 0;
	fMQShutdownPlugin    Shutdown = 0;
	fMQZoned             Zoned = 0;
	fMQWriteChatColor    WriteChatColor = 0;
	fMQPulse             Pulse = 0;
	fMQIncomingChat      IncomingChat = 0;
	fMQCleanUI           CleanUI = 0;
	fMQReloadUI          ReloadUI = 0;
	fMQDrawHUD           DrawHUD = 0;
	fMQSetGameState      SetGameState =0;
	fMQSpawn             AddSpawn = 0;
	fMQSpawn             RemoveSpawn = 0;
	fMQGroundItem        AddGroundItem = 0;
	fMQGroundItem        RemoveGroundItem = 0;
	fMQBeginZone         BeginZone = 0;
	fMQEndZone           EndZone = 0;
	fMQUpdateImGui       UpdateImGui = 0;
	fMQMacroStart        MacroStart = 0;
	fMQMacroStop         MacroStop = 0;
	fMQLoadPlugin        LoadPlugin = 0;
	fMQUnloadPlugin      UnloadPlugin = 0;

	MQPlugin* pLast = nullptr;
	MQPlugin* pNext = nullptr;
};
using PMQPLUGIN [[deprecated("Use MQPlugin* instead")]] = MQPlugin*;
using MQPLUGIN [[deprecated("Use MQPlugin instead")]] = MQPlugin;

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

	bool                 loaded = false;
};

void InitializeInternalModules();
void AddInternalModule(MQModule* module);
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

#define FORCE_UNDEFINED_SYMBOL(x) __pragma(comment (linker, "/export:_" #x))

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
	CCustomWnd(const CXStr& screenpiece)
		: CSidlScreenWnd(0, screenpiece, eIniFlag_All)
	{
		Init();
	}

	CCustomWnd(const char* screenpiece) : CSidlScreenWnd(0, screenpiece, eIniFlag_All)
	{
		Init();
	}

	~CCustomWnd()
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

	~CCustomMenu()
	{
	}
};

//============================================================================

struct MQColor
{
	// default is opaque black
	MQLIB_OBJECT constexpr MQColor()
		: Red(0)
		, Green(0)
		, Blue(0)
		, Alpha(255)
	{}

	MQLIB_OBJECT constexpr MQColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255)
		: Blue(blue)
		, Green(green)
		, Red(red)
		, Alpha(alpha)
	{}

	MQLIB_OBJECT constexpr MQColor(uint32_t argbcolor)
		: ARGB(argbcolor)
	{}

	MQLIB_OBJECT constexpr operator ARGBCOLOR() const
	{
		ARGBCOLOR color = { 0 };
		color.ARGB = ARGB;
		return color;
	}

	MQLIB_OBJECT constexpr operator COLORREF() const
	{
		return ARGB;
	}

	MQLIB_OBJECT constexpr operator uint32_t() const
	{
		return ARGB;
	}

	MQLIB_OBJECT constexpr uint32_t ToRGBA8() const
	{
		return (((uint32_t)(Alpha) << 24)
			| ((uint32_t)(Blue) << 16)
			| ((uint32_t)(Green) << 8)
			| ((uint32_t)(Red) << 0));
	}

	// Layout matches ARGBCOLOR
	union
	{
		struct
		{
			uint8_t Blue;
			uint8_t Green;
			uint8_t Red;
			uint8_t Alpha;
		};

		uint32_t ARGB = 0;
	};
};

//============================================================================

template <class Any>
class CIndex
{
public:
	[[deprecated("Use std::vector instead")]] CIndex() = default;

	[[deprecated("Use std::vector instead")]] CIndex(size_t InitialSize)
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

union MQPrimitiveData
{
	void* Ptr;
	float Float;
	DWORD DWord;
	ARGBCOLOR Argb;
	int32_t Int;
	double Double;
	int64_t Int64;
	uint64_t UInt64;
	ULARGE_INTEGER LargeUInt;
};

struct MQVarPtr
{
	std::variant<MQPrimitiveData, std::shared_ptr<void>, CXStr> Data;

	enum VariantIdx
	{
		PlainData = 0,
		ComplexObject,
		String
	};

	template <typename T>
	struct ReturnType { using type = std::shared_ptr<T>; };

	template <typename T>
	typename ReturnType<T>::type Set(T Object)
	{
		return std::static_pointer_cast<T>(std::get<std::shared_ptr<void>>(Data = std::shared_ptr<T>(new T(Object),
			[](T* ptr) { if constexpr (std::is_array_v<T>) delete[] ptr; else delete ptr; })));
	}

	template <typename T>
	typename ReturnType<T>::type Set(std::shared_ptr<T> Object)
	{
		if (Object)
			return Set<T>(*Object);

		return std::static_pointer_cast<T>(std::get<std::shared_ptr<void>>(Data = std::shared_ptr<T>()));
	}

	template <typename T>
	typename ReturnType<T>::type Get()
	{
		if (Data.index() != VariantIdx::ComplexObject)
			return std::shared_ptr<T>();

		return std::static_pointer_cast<T>(std::get<std::shared_ptr<void>>(Data));
	}

	template <> struct ReturnType<CXStr> { using type = CXStr; };
	template <>
	CXStr Set<CXStr>(CXStr String)
	{
		return std::get<CXStr>(Data = String);
	}

	// this function is special to allow us to set a CXStr from a string_view without needing extra allocations
	CXStr SetString(std::string_view String)
	{
		return std::get<CXStr>(Data = CXStr(String));
	}

	template <>
	CXStr Get<CXStr>()
	{
		if (Data.index() != VariantIdx::String)
			return CXStr();

		return std::get<CXStr>(Data);
	}

	MQPrimitiveData get_POD() const
	{
		if (Data.index() != VariantIdx::PlainData)
		{
			MQPrimitiveData u;
			u.UInt64 = 0;
			return u;
		}

		return std::get<MQPrimitiveData>(Data);
	}

	MQPrimitiveData set_POD(MQPrimitiveData POD)
	{
		return std::get<MQPrimitiveData>(Data = POD);
	}

	void* get_Ptr() const { return get_POD().Ptr; }
	void* set_Ptr(void* Ptr) {
		auto u = get_POD();
		u.Ptr = Ptr;
		return set_POD(u).Ptr;
	}
	__declspec(property(get = get_Ptr, put = set_Ptr)) void* Ptr;
	template <> struct ReturnType<void*> { using type = void*; };
	template <> void* Set<void*>(void* Ptr) { return set_Ptr(Ptr); }
	template <> void* Get<void*>() { return get_POD().Ptr; }

	float get_Float() const { return get_POD().Float; }
	float set_Float(float Float)
	{
		auto u = get_POD();
		u.Float = Float;
		return set_POD(u).Float;
	}
	__declspec(property(get = get_Float, put = set_Float)) float Float;
	template <> struct ReturnType<float> { using type = float; };
	template <> float Set<float>(float Float) { return set_Float(Float); }
	template <> float Get<float>() { return get_POD().Float; }

	DWORD get_DWord() const { return get_POD().DWord; }
	DWORD set_DWord(DWORD DWord)
	{
		auto u = get_POD();
		u.DWord = DWord;
		return set_POD(u).DWord;
	}
	__declspec(property(get = get_DWord, put = set_DWord)) DWORD DWord;
	template <> struct ReturnType<DWORD> { using type = DWORD; };
	template <> DWORD Set<DWORD>(DWORD DWord) { return set_DWord(DWord); }
	template <> DWORD Get<DWORD>() { return get_POD().DWord; }

	ARGBCOLOR get_Argb() const { return get_POD().Argb; }
	ARGBCOLOR set_Argb(ARGBCOLOR Argb)
	{
		auto u = get_POD();
		u.Argb = Argb;
		return set_POD(u).Argb;
	}
	__declspec(property(get = get_Argb, put = set_Argb)) ARGBCOLOR Argb;
	template <> struct ReturnType<ARGBCOLOR> { using type = ARGBCOLOR; };
	template <> ARGBCOLOR Set<ARGBCOLOR>(ARGBCOLOR Argb) { return set_Argb(Argb); }
	template <> ARGBCOLOR Get<ARGBCOLOR>() { return get_POD().Argb; }

	int32_t get_Int() const { return get_POD().Int; }
	int32_t set_Int(int32_t Int)
	{
		auto u = get_POD();
		u.Int = Int;
		return set_POD(u).Int;
	}
	__declspec(property(get = get_Int, put = set_Int)) int32_t Int;
	template <> struct ReturnType<int32_t> { using type = int32_t; };
	template <> int32_t Set<int32_t>(int32_t Int) { return set_Int(Int); }
	template <> int32_t Get<int32_t>() { return get_POD().Int; }

	double get_Double() const { return get_POD().Double; }
	double set_Double(double Double)
	{
		auto u = get_POD();
		u.Double = Double;
		return set_POD(u).Double;
	}
	__declspec(property(get = get_Double, put = set_Double)) double Double;
	template <> struct ReturnType<double> { using type = double; };
	template <> double Set<double>(double Double) { return set_Double(Double); }
	template <> double Get<double>() { return get_POD().Double; }

	int64_t get_Int64() const { return get_POD().Int64; }
	int64_t set_Int64(int64_t Int64)
	{
		auto u = get_POD();
		u.Int64 = Int64;
		return set_POD(u).Int64;
	}
	__declspec(property(get = get_Int64, put = set_Int64)) int64_t Int64;
	template <> struct ReturnType<int64_t> { using type = int64_t; };
	template <> int64_t Set<int64_t>(int64_t Int64) { return set_Int64(Int64); }
	template <> int64_t Get<int64_t>() { return get_POD().Int64; }

	uint64_t get_UInt64() const { return get_POD().UInt64; }
	uint64_t set_UInt64(uint64_t UInt64)
	{
		auto u = get_POD();
		u.UInt64 = UInt64;
		return set_POD(u).UInt64;
	}
	__declspec(property(get = get_UInt64, put = set_UInt64)) uint64_t UInt64;
	template <> struct ReturnType<uint64_t> { using type = uint64_t; };
	template <> uint64_t Set<uint64_t>(uint64_t UInt64) { return set_UInt64(UInt64); }
	template <> uint64_t Get<uint64_t>() { return get_POD().UInt64; }

	DWORD get_LowPart() const { return get_POD().LargeUInt.LowPart; }
	DWORD set_LowPart(DWORD LowPart)
	{
		auto u = get_POD();
		u.LargeUInt.LowPart = LowPart;
		return set_POD(u).LargeUInt.LowPart;
	}
	__declspec(property(get = get_LowPart, put = set_LowPart)) DWORD LowPart;

	DWORD get_HighPart() const { return get_POD().LargeUInt.HighPart; }
	DWORD set_HighPart(DWORD HighPart)
	{
		auto u = get_POD();
		u.LargeUInt.HighPart = HighPart;
		return set_POD(u).LargeUInt.HighPart;
	}
	__declspec(property(get = get_HighPart, put = set_HighPart)) DWORD HighPart;
	template <> struct ReturnType<ULARGE_INTEGER> { using type = ULARGE_INTEGER; };
	template <> ULARGE_INTEGER Set<ULARGE_INTEGER>(ULARGE_INTEGER LargeUInt)
	{
		auto u = get_POD();
		u.LargeUInt = LargeUInt;
		return set_POD(u).LargeUInt;
	}
	template <> ULARGE_INTEGER Get<ULARGE_INTEGER>() { return get_POD().LargeUInt; }
};
using MQ2VARPTR [[deprecated("Use MQVarPtr instead")]] = MQVarPtr;
using PMQ2VARPTR [[deprecated("Use MQVarPtr* instead")]] = MQVarPtr*;

struct MQTypeVar : public MQVarPtr
{
	MQ2Type* Type = nullptr;

	MQVarPtr& GetVarPtr() { return *this; }
	MQVarPtr& SetVarPtr(const MQVarPtr& VarPtr) { Data = VarPtr.Data; return *this; }
	__declspec(property(get = GetVarPtr, put = SetVarPtr)) MQVarPtr VarPtr;
};
using MQ2TYPEVAR [[deprecated("Use MQTypeVar instead")]] = MQTypeVar;
using PMQ2TYPEVAR [[deprecated("Use MQTypeVar* instead")]] = MQTypeVar;

struct MQTypeMember
{
	int          ID;
	const char*  Name;
	uint32_t     Type;
};
using MQ2TYPEMEMBER [[deprecated("Use MQTypeMember instead")]] = MQTypeMember;
using PMQ2TYPEMEMBER [[deprecated("Use MQTypeMember* instead")]] = MQTypeMember*;

using fMQData = bool(*)(const char*, MQTypeVar&);
using fMQDataOld = BOOL(*)(char*, MQTypeVar&);

struct MQDataItem
{
	char Name[64];
	fMQData Function;
};
using MQ2DATAITEM [[deprecated("Use MQDataItem instead")]] = MQDataItem;
using PMQ2DATAITEM [[deprecated("Use MQDataItem* instead")]] = MQDataItem*;

struct MQDataVar
{
	char szName[MAX_STRING];
	MQTypeVar Var;

	MQDataVar* pNext;
	MQDataVar* pPrev;
	MQDataVar** ppHead;
};
using PDATAVAR [[deprecated("Use MQDataVar* instead")]] = MQDataVar*;
using DATAVAR [[deprecated("Use MQDataVar instead")]] = MQDataVar;

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
using PMACROSTACK [[deprecated("Use MQMacroStack* instead")]] = MQMacroStack *;
using MACROSTACK [[deprecated("Use MQMacroStack instead")]] = MQMacroStack;

struct MQEventQueue
{
	MQEventQueue* pPrev = nullptr;
	MQEventQueue* pNext = nullptr;
	int           Type = 0; // one of EVENT_xxx defines
	std::string   Name;
	MQEventList*  pEventList = nullptr;
	MQDataVar*      Parameters = nullptr;
};
using EVENTQUEUE [[deprecated("Use MQEventQueue instead")]] = MQEventQueue;
using PEVENTQUEUE [[deprecated("Use MQEventQueue* instead")]] = MQEventQueue *;

struct MercDesc
{
	std::string Race;
	std::string Type;
	std::string Confidence;
	std::string Proficiency;
};

//----------------------------------------------------------------------------

enum eGroundObjectType
{
	GO_None,
	GO_GroundType,
	GO_ObjectType
};

struct MQGroundObject
{
/*0x00*/ eGroundObjectType  Type;
/*0x04*/ EQGroundItem       GroundItem;         // for conversion between switch and gorunditems
/*0x84*/ void*              ObjPtr;             // EQPlacedItem *
/*0x88*/ EQGroundItem*      pGroundItem;
/*0x8c*/

	// Currently necessary because of MQ2DataTypes
	MQGroundObject() { ZeroMemory(this, sizeof(MQGroundObject)); }
};

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

void RefreshKeyRingWindow();

} // namespace mq
