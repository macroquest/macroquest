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
	bool bNoGuild = false;
	bool bLoS = false;
	bool bExactName = false;
	bool bTargetable = false;
	uint32_t PlayerState = 0;
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
	char szName[MAX_STRING] = { 0 };
	char szLine[MAX_STRING] = { 0 };
	uint8_t Level = 0;
	uint32_t SpawnID = 0;
	float Distance = 0;
	int Class = 0;
	int Race = 0;
	int64_t GuildID = 0;
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

struct MQVarPtr
{
	using MQVariant = std::variant<
		void*,
		bool,
		float,
		int32_t,
		uint32_t,
		double,
		int64_t,
		uint64_t,
		std::shared_ptr<void>,
		CXStr
	>;
	
	MQVariant Data;

	enum class VariantIdx
	{
		Ptr = 0,
		Bool,
		Float,
		Int32,
		UInt32,
		Double,
		Int64,
		UInt64,
		ComplexObject,
		String
	};

	bool IsType(VariantIdx Index) { return Data.index() == static_cast<size_t>(Index); }
	VariantIdx GetType() { return static_cast<VariantIdx>(Data.index()); }

	bool operator==(const MQVarPtr& other) const
	{
		// this is a strict equals check, will be false if the underlying data type is not the same
		// if you want to compare unlike types, you will need to first actualize the variant
		return this->Data == other.Data;
	}

	template <typename T>
	struct ConvertVisitor
	{
		mutable std::optional<T> value;

		template <typename U>
		void operator()(U&& val)
		{
			if constexpr (std::is_convertible_v<U, T>)
				value = static_cast<T>(val);
		}

		ConvertVisitor() : value(std::nullopt) {}
	};

	template <typename T>
	T Cast() const
	{
		auto visitor = ConvertVisitor<T>();
		std::visit(visitor, Data);
		if (visitor.value)
			return *visitor.value;

		return T();
	}

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
	typename ReturnType<T>::type Get() const
	{
		if (Data.index() != static_cast<size_t>(VariantIdx::ComplexObject))
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
	CXStr Get<CXStr>() const
	{
		if (Data.index() != static_cast<size_t>(VariantIdx::String))
			return CXStr();

		return std::get<CXStr>(Data);
	}

#define MQVARPTR_SPECIALIZE(Type) \
template<> struct ReturnType<Type> { using type = Type; }; \
template<> Type Set<Type>(Type Val) { return std::get<Type>(Data = Val); } \
template<> Type Get<Type>() const { return Cast<Type>(); }

	MQVARPTR_SPECIALIZE(void*);
	MQVARPTR_SPECIALIZE(bool);
	MQVARPTR_SPECIALIZE(float);
	MQVARPTR_SPECIALIZE(int32_t);
	MQVARPTR_SPECIALIZE(uint32_t);
	MQVARPTR_SPECIALIZE(double);
	MQVARPTR_SPECIALIZE(int64_t);
	MQVARPTR_SPECIALIZE(uint64_t);

#define MQVARPTR_PROPERTIES(Type, Prop) \
Type set_##Prop(Type Val) { return Set<Type>(Val); } \
Type get_##Prop() const { return Get<Type>(); } \
__declspec(property(get = get_##Prop, put = set_##Prop)) Type Prop;

	// TODO: Future work -- deprecate all of these in favor of Get/Set
	MQVARPTR_PROPERTIES(void*, Ptr);
	MQVARPTR_PROPERTIES(float, Float);
	MQVARPTR_PROPERTIES(int32_t, Int);
	MQVARPTR_PROPERTIES(uint32_t, DWord);
	MQVARPTR_PROPERTIES(double, Double);
	MQVARPTR_PROPERTIES(int64_t, Int64);
	MQVARPTR_PROPERTIES(uint64_t, UInt64);

	// TODO: Future work -- uncomment the deprecates and refactor all uses of high/low part
	// these are here only to support deprecated functionality where some types rely on storing ints in low and high parts
	//DEPRECATE("Use Get<uint32_t>() instead of LowPart. For data needing High and Low part, create a data structure instead.")
	uint32_t get_LowPart() const { return Get<uint32_t>(); }

	//DEPRECATE("Use Set<uint32_t>(v) instead of LowPart. For data needing High and Low part, create a data structure instead.")
	uint32_t set_LowPart(uint32_t Val)
	{
		// we can assume that if the user wanted to also set HighPart, they did it explicitly either before or after setting
		// LowPart, which falls into 2 cases. Either the underlying data was set before the 64-bit, or it wasn't (either the
		// the default or an explicit 32-bit/pointer value).

		// first check if we have 64-bit Data -- we only need to worry about unsigned because this trick wouldn't work with signed
		// data without some explicit or implicit casting to unsigned
		if (Data.index() == static_cast<size_t>(VariantIdx::UInt64))
		{
			// if so, we need to save the HighPart off before setting the low part, then retain the data type in the variant
			ULARGE_INTEGER i;
			i.QuadPart = Get<uint64_t>();
			i.LowPart = Val;
			Set<uint64_t>(i.QuadPart);
			return i.LowPart;
		}

		// if we get here, we don't have 64-bit data, so HighPart is either unset, or set in the convenience variable above
		// we can just set the LowPart as uint32_t
		return Set<uint32_t>(Val);
	}

#pragma warning(disable: 4996)
	__declspec(property(get = get_LowPart, put = set_LowPart)) uint32_t LowPart;
#pragma warning(default: 4996)

	// HighPart is slightly more complicated, but only just. We just save off the HighPart in this member variable unless
	// the underlying data is uint64_t -- and we will prefer to store the uint32_t variant when setting
	uint32_t HighPart_;

	//DEPRECATE("For data needing High and Low part, create a data structure instead.")
	uint32_t get_HighPart() const
	{
		// this data is only stored in Data if the type of variant is UInt64
		if (Data.index() == static_cast<size_t>(VariantIdx::UInt64))
		{
			ULARGE_INTEGER i;
			i.QuadPart = Get<uint64_t>();
			return i.HighPart;
		}

		// otherwise, just return the extra storage information
		return HighPart_;
	}

	//DEPRECATE("For data needing High and Low part, create a data structure instead.")
	uint32_t set_HighPart(uint32_t Val)
	{
		// again, check if we  have already set the underlying data type to uint64_t
		if (Data.index() == static_cast<size_t>(VariantIdx::UInt64))
		{
			ULARGE_INTEGER i;
			i.QuadPart = Get<uint64_t>();
			i.HighPart = Val;
			Set<uint64_t>(i.QuadPart);
			return i.HighPart;
		}

		// otherwise, just set the extra storage information and move on
		HighPart_ = Val;
		return HighPart_;
	}

#pragma warning(disable: 4996)
	__declspec(property(get = get_HighPart, put = set_HighPart)) uint32_t HighPart;
#pragma warning(default: 4996)

	ARGBCOLOR get_Argb() const
	{
		auto ptr = Get<ARGBCOLOR>();
		if (ptr != nullptr)
			return *ptr;

		return { { 0, 0, 0, 0 } };
	}

	ARGBCOLOR set_Argb(ARGBCOLOR Val)
	{
		// this is a bit of a cowboy deref, but we are guaranteed that Set constructs a new shared pointer
		return *Set<ARGBCOLOR>(Val);
	}

	__declspec(property(get = get_Argb, put = set_Argb)) ARGBCOLOR Argb;
};
using MQ2VARPTR [[deprecated("Use MQVarPtr instead")]] = MQVarPtr;
using PMQ2VARPTR [[deprecated("Use MQVarPtr* instead")]] = MQVarPtr*;

struct MQTypeVar : public MQVarPtr
{
	MQ2Type* Type = nullptr;
	
	bool operator==(const MQTypeVar& other) const
	{
		return Type == other.Type && this->MQVarPtr::operator==(other);
	}

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

//----------------------------------------------------------------------------
// actual internals

void RefreshKeyRingWindow();


} // namespace mq
