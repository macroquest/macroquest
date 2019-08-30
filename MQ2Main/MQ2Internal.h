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

EQLIB_API void WriteChatfSafe(const char* szFormat, ...);

namespace MQ2Internal {

	class MQ2Type;

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
        PVP_RALLOS = 2,
        PVP_SULLON = 3,
    };

    enum eSpawnType
    {
        NONE=0,
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
        NPCCORPSE=2000,
        PCCORPSE,
    };

    typedef struct _SEARCHSPAWN {
        DWORD MinLevel;
        DWORD MaxLevel;
        eSpawnType SpawnType;
        DWORD SpawnID;
        DWORD FromSpawnID;
        float Radius;
        char szName[MAX_STRING];
        char szBodyType[MAX_STRING];
        char szRace[MAX_STRING];
        char szClass[MAX_STRING];
        char szLight[MAX_STRING];
		int64_t GuildID;
        BOOL bSpawnID;
        BOOL bNotNearAlert;
        BOOL bNearAlert;
        BOOL bNoAlert;
        BOOL bAlert;
        BOOL bLFG;
        BOOL bTrader;
        BOOL bLight;
        BOOL bTargNext;
        BOOL bTargPrev;
        BOOL bGroup;
		BOOL bFellowship;
        BOOL bXTarHater;
        BOOL bNoGroup;
        BOOL bRaid;
        BOOL bGM;
        BOOL bNamed;
        BOOL bMerchant;
		BOOL bBanker;
        BOOL bTributeMaster;
        BOOL bKnight;
        BOOL bTank;
        BOOL bHealer;
        BOOL bDps;
        BOOL bSlower;
        BOOL bAura;
        BOOL bBanner;
        BOOL bCampfire;
        DWORD NotID;
        DWORD NotNearAlertList;
        DWORD NearAlertList;
        DWORD NoAlertList;
        DWORD AlertList;
        double ZRadius;
		double FRadius;
        float xLoc;
		float yLoc;
		float zLoc;
        BOOL bKnownLocation;
        BOOL bNoPet;
        DWORD SortBy;
        BOOL bNoGuild;
        BOOL bLoS;
        BOOL bExactName;
        BOOL bTargetable;
		DWORD PlayerState;
    } SEARCHSPAWN, *PSEARCHSPAWN;

    enum SearchItemFlag
    {
        Lore=1,
        NoDrop=2,
        NoRent=3,
        Magic=4,
        Book=5,
        Pack=6,
        Combinable=7,
        Summoned=8,
        Weapon=9,
        Normal=10,
        Instrument=11,

        // item locations...
        Worn=100,
        Inventory=101,
        Bank=102,
        Merchant=103,
        Corpse=104,
        SharedBank=105,
        Trade=106,
        Bazaar=107,
        Inspect=108,
        Enviro=109,

    };

    typedef struct _SEARCHITEM {
        char FlagMask[MAX_STRING];
        char Flag[MAX_STRING];

        char szName[MAX_STRING];
        DWORD ID;

    } SEARCHITEM, *PSEARCHITEM;

    typedef struct _SWHOFILTER {
        BOOL Lastname;
        BOOL Class;
        BOOL Race;
        BOOL Body;
        BOOL Level;
        BOOL Distance;
        BOOL GM;
        BOOL Guild;
        BOOL LD;
        BOOL Sneak;
        BOOL Anon;
        BOOL LFG;
        BOOL NPCTag;
        BOOL SpawnID;
        BOOL Trader;
        BOOL AFK;
        BOOL Light;
        BOOL Holding;
        BOOL ConColor;
        BOOL Invisible;
    } SWHOFILTER, *PSWHOFILTER;

    typedef struct _SWHOSORT {
        char szName[MAX_STRING];
        char szLine[MAX_STRING];
        BYTE Level;
        DWORD SpawnID;
        float Distance;
        DWORD Class;
        DWORD Race;
        int64_t GuildID;
    } SWHOSORT, *PSWHOSORT;

    typedef struct _CONNECTION {
        unsigned int socket;
        BOOL Auth;
        struct _CONNECTION *pNext;
    } CONNECTION, *PCONNECTION;

	typedef struct _MOUSEINFO {
		DWORD X;
		DWORD Y;
		DWORD SpeedX;
		DWORD SpeedY;
		DWORD Scroll;
	} MOUSEINFO, *PMOUSEINFO;

    typedef struct _SPELLINFO {
        char Name[32];
        char Target[32];
    } SPELLINFO, *PSPELLINFO;

    typedef struct _PACKLOC {
        DWORD X;
        DWORD Y;
    } PACKLOC, *PPACKLOC;

	typedef struct _MACROLINE {
		std::string Command;
		std::string SourceFile;
		int LoopStart;
		int LoopEnd;//used for loops/while if its 0 no action is taken, otherwise it will jump to the line indicated. -eqmule
		int LineNumber;
#ifdef MQ2_PROFILING
		DWORD ExecutionCount;
		LONGLONG ExecutionTime;
#endif
	} MACROLINE,*PMACROLINE;
	struct MACROBLOCK {
		std::string Name;//our macro Name
		BOOL Paused;
		int CurrIndex;//the current macro line we are on
		int BindStackIndex;//where we were at before calling the bind.
		std::string BindCmd;//the actual command including parameters
		std::map<int, MACROLINE>Line;
		bool Removed;
	};
	using PMACROBLOCK = std::shared_ptr<MACROBLOCK>;

    typedef struct _MQTIMER {
        char szName[MAX_VARNAME];
        ULONG Original;
        ULONG Current;
        struct _MQTIMER *pNext;
        struct _MQTIMER *pPrev;
    } MQTIMER, *PMQTIMER;

	struct KEYPRESS
	{
		uint16_t KeyId;
		bool     Pressed;

		KEYPRESS* pNext;
	};

    typedef struct _ITEMDB {
        struct _ITEMDB *pNext;
        DWORD ID;
		DWORD StackSize;
        char szName[256];
    } ITEMDB, *PITEMDB;

    typedef struct _DEFINE {
        struct _DEFINE *pNext;
        char szName[MAX_STRING];
        char szReplace[MAX_STRING];
    } DEFINE, *PDEFINE;

    typedef struct _EVENTLIST {
        struct _EVENTLIST *pNext;
        char szName[MAX_STRING];
        char szMatch[MAX_STRING];
        int pEventFunc;
        DWORD BlechID;
    } EVENTLIST, *PEVENTLIST;

    typedef struct _BINDLIST {
        struct _BINDLIST *pNext;
        char szName[MAX_STRING];
        char szFuncName[MAX_STRING];
		bool Parse = true;
    } BINDLIST, *PBINDLIST;

    typedef struct _FILTER {
        struct _FILTER *pNext;
        char FilterText[MAX_STRING];
        DWORD Length;
        PBOOL pEnabled;
    } FILTER, *PFILTER;

    typedef struct _PARMLIST {
        char szName[MAX_STRING];
        DWORD (__cdecl *fAddress)(char*, char*, PSPAWNINFO);
    } PARMLIST, *PPARMLIST;

	struct MQBenchmark
	{
		char     szName[64];
		uint64_t Entry;
		uint64_t LastTime;
		uint64_t TotalTime;
		uint64_t Count;
	};

	struct MQGroundPending
	{
		GROUNDITEM*          pGroundItem;
		MQGroundPending*     pLast;
		MQGroundPending*     pNext;
	};

	struct MQPlugin
	{
		char                 szFilename[MAX_PATH];
		HMODULE              hModule;
		float                fpVersion;
		bool                 bCustom;
		fMQInitializePlugin  Initialize;
		fMQShutdownPlugin    Shutdown;
		fMQZoned             Zoned;
		fMQWriteChatColor    WriteChatColor;
		fMQPulse             Pulse;
		fMQIncomingChat      IncomingChat;
		fMQCleanUI           CleanUI;
		fMQReloadUI          ReloadUI;
		fMQDrawHUD           DrawHUD;
		fMQSetGameState      SetGameState;
		fMQSpawn             AddSpawn;
		fMQSpawn             RemoveSpawn;
		fMQGroundItem        AddGroundItem;
		fMQGroundItem        RemoveGroundItem;
		fMQBeginZone         BeginZone;
		fMQEndZone           EndZone;

		MQPlugin*            pLast;
		MQPlugin*            pNext;
	};

	class CMQ2Alerts
	{
	private:
		std::mutex m_mutex;
		std::map<uint32_t, std::vector<SEARCHSPAWN>> m_alertMap;

	public:
		CMQ2Alerts() = default;
		~CMQ2Alerts() = default;

		bool AddNewAlertList(uint32_t id, SEARCHSPAWN* pSearchSpawn);
		bool RemoveAlertFromList(uint32_t id, SEARCHSPAWN* pSearchSpawn);

		bool GetAlert(uint32_t id, std::vector<SEARCHSPAWN>& ss);
		bool AlertExist(uint32_t id);

		bool ListAlerts(char* szOut, size_t max);
		void FreeAlerts(uint32_t id);
	};

	class CCustomWnd : public CSidlScreenWnd
	{
	public:
		CCustomWnd(const CXStr& screenpiece) : CSidlScreenWnd(0, screenpiece, eIniFlag_All)
		{
			CreateChildrenFromSidl();
			Show(true);

			SetEscapable(false);
		}

		CCustomWnd(const char* screenpiece) : CSidlScreenWnd(0, screenpiece, eIniFlag_All)
		{
			CreateChildrenFromSidl();
			Show(true);

			SetEscapable(false);
		}

		~CCustomWnd()
		{
		}
	};

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

	template <class Any>
	class CIndex
	{
	public:
		CIndex() = default;

		CIndex(size_t InitialSize)
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

	private:
		size_t m_size = 0;
		Any* m_list = nullptr;
		std::mutex m_mutex;
	};

    typedef struct _MQ2VarPtr
    {
        union {
            struct {
				void* Ptr;
				LONG HighPart;
			};
			struct {
				float Float;
				LONG HighPart;
			};
			struct {
				DWORD DWord;
				LONG HighPart;
			};
			struct {
				ARGBCOLOR Argb;
				LONG HighPart;
			};
			struct {
				int   Int;
				LONG HighPart;
			};
            struct {
				UCHAR Array[4];
				LONG HighPart;
			};
			struct {
				UCHAR FullArray[8];
			};
			double Double;
			int64_t   Int64;
			uint64_t   UInt64;
        };
	} MQ2VARPTR, *PMQ2VARPTR;

    typedef struct _MQ2TypeVar
    {
        class MQ2Type *Type;
        union {
			MQ2VARPTR VarPtr;
            struct {
				void* Ptr;
				LONG HighPart;
			};
			struct {
				float Float;
				LONG HighPart;
			};
			struct {
				DWORD DWord;
				LONG HighPart;
			};
			struct {
				ARGBCOLOR Argb;
				LONG HighPart;
			};
			struct {
				int   Int;
				LONG HighPart;
			};
            struct {
				UCHAR Array[4];
				LONG HighPart;
			};
			struct {
				UCHAR FullArray[8];
			};
			double Double;
			int64_t   Int64;
			uint64_t   UInt64;
        };
    } MQ2TYPEVAR, *PMQ2TYPEVAR;

	struct MQ2TypeMember
	{
		int          ID;
		const char*  Name;
		uint32_t     Type;
	};
	using PMQ2TYPEMEMBER [[deprecated]] = MQ2TypeMember*;

	using fMQData = BOOL(*)(char*, MQ2TYPEVAR&);

	struct MQ2DataItem
	{
		char Name[64];
		fMQData Function;
	};
	using PMQ2DATAITEM [[deprecated]] = MQ2DataItem*;

	EQLIB_API bool AddMQ2Type(MQ2Type& type);
	EQLIB_API bool RemoveMQ2Type(MQ2Type& type);

	typedef struct _DATAVAR {
        char szName[MAX_STRING];
        MQ2TYPEVAR Var;
        struct _DATAVAR *pNext;
        struct _DATAVAR *pPrev;
        struct _DATAVAR **ppHead;
    } DATAVAR, *PDATAVAR;

	class MQ2Type
	{
	public:
		MQ2Type(const char* NewName)
		{
			strcpy_s(TypeName, NewName);
			Official = AddMQ2Type(*this);
		}

		virtual ~MQ2Type()
		{
			if (Official)
			{
				RemoveMQ2Type(*this);
			}

			Members.Cleanup();
			Methods.Cleanup();
		}

		void InitializeMembers(MQ2TypeMember* MemberArray)
		{
			for (int i = 0; MemberArray[i].ID; i++)
			{
				AddMember(MemberArray[i].ID, MemberArray[i].Name);
			}
		}

		virtual bool FromData(MQ2VARPTR& VarPtr, MQ2TYPEVAR& Source) = 0;
		virtual bool FromString(MQ2VARPTR& VarPtr, char* Source) = 0;

		virtual void InitVariable(MQ2VARPTR& VarPtr)
		{
			VarPtr.Ptr = 0;
			VarPtr.HighPart = 0;
		}

		virtual void FreeVariable(MQ2VARPTR& VarPtr) {}

		virtual bool GetMember(MQ2VARPTR VarPtr, char* Member, char* Index, MQ2TYPEVAR& Dest) = 0;

		virtual bool ToString(MQ2VARPTR VarPtr, char* Destination)
		{
			strcpy_s(Destination, MAX_STRING, TypeName);
			return true;
		}

		const char* GetName()
		{
			if (TypeName)
				return &TypeName[0];

			return nullptr;
		}

		const char* GetMemberName(int ID)
		{
			for (size_t index = 0; index < Members.m_size; index++)
			{
				if (MQ2TypeMember* pMember = Members[index])
				{
					if (pMember->ID == ID)
						return &pMember->Name[0];
				}
			}

			return nullptr;
		}

		bool GetMemberID(const char* Name, int& Result)
		{
			std::scoped_lock lock(m_mutex);

			if (MemberMap.find(Name) == MemberMap.end())
				return false;

			int index = MemberMap[Name] - 1;
			if (index < 0)
				return false;

			MQ2TypeMember* pMember = Members[index];
			Result = pMember->ID;
			return true;
		}

		MQ2TypeMember* FindMember(const char* Name)
		{
			std::scoped_lock lock(m_mutex);

			if (MemberMap.find(Name) == MemberMap.end())
				return nullptr;

			int index = MemberMap[Name] - 1;
			if (index < 0)
				return nullptr;

			return Members[index];
		}

		MQ2TypeMember* FindMethod(const char* Name)
		{
			std::scoped_lock lock(m_mutex);

			if (MethodMap.find(Name) == MethodMap.end())
				return nullptr;

			int index = MethodMap[Name] - 1;
			if (index < 0)
				return nullptr;

			return Methods[index];
		}

		bool InheritedMember(const char* Name)
		{
			if (!pInherits || !pInherits->FindMember(Name))
				return false;

			return true;
		}

		void SetInheritance(MQ2Type* pNewInherit)
		{
			pInherits = pNewInherit;
		}

	protected:
		bool AddMember(DWORD ID, const char* Name)
		{
			std::scoped_lock lock(m_mutex);

			if (MemberMap.find(Name) != MemberMap.end())
				return false;

			int index = Members.GetUnused();
			MemberMap[Name] = index + 1;

			MQ2TypeMember* pMember = new MQ2TypeMember;
			pMember->Name = Name;
			pMember->ID = ID;
			pMember->Type = 0;
			Members[index] = pMember;
			return true;
		}

		bool AddMethod(int ID, const char* Name)
		{
			std::scoped_lock lock(m_mutex);

			if (MethodMap.find(Name) != MethodMap.end())
				return false;

			int index = Methods.GetUnused();
			MethodMap[Name] = index + 1;

			MQ2TypeMember* pMethod = new MQ2TypeMember;
			pMethod->Name = Name;
			pMethod->ID = ID;
			pMethod->Type = 1;
			Methods[index] = pMethod;
			return true;
		}

		bool RemoveMember(const char* Name)
		{
			std::scoped_lock lock(m_mutex);

			if (MemberMap.find(Name) == MemberMap.end())
				return false;

			int index = MemberMap[Name] - 1;
			if (index < 0)
				return false;

			MQ2TypeMember* pMember = Members[index];
			delete pMember;

			Members[index] = 0;
		}

		bool RemoveMethod(const char* Name)
		{
			std::scoped_lock lock(m_mutex);

			if (MethodMap.find(Name) == MethodMap.end())
				return false;

			int index = MethodMap[Name] - 1;
			if (index < 0)
				return false;

			MQ2TypeMember* pMethod = Methods[index];
			delete pMethod;

			Methods[index] = 0;
		}

		char TypeName[32];
		bool Official;
		CIndex<MQ2TypeMember*> Members;
		CIndex<MQ2TypeMember*> Methods;
		std::map<std::string, int> MemberMap;
		std::map<std::string, int> MethodMap;
		MQ2Type* pInherits = nullptr;

	protected:
		std::mutex m_mutex;
	};

    class CDataArray
    {
    public:
        CDataArray()
        {
            pType=0;
            nExtents=0;
            pExtents=0;
            pData=0;
            TotalElements=0;
        }

        CDataArray(MQ2Type *Type, char* Index, const char* Default, BOOL ByData=FALSE)
        {
            nExtents=1;
			TotalElements=1;

            // count number of , 's
            if (const char* pComma=strchr(Index,','))
            {
                nExtents++;
                while(pComma=strchr(&pComma[1],','))
                {
                    nExtents++;
                }
            }

            // allocate extents
            if(pExtents=(DWORD*)malloc(sizeof(DWORD)*nExtents)) {
				// read extents
				char* pStart=Index;
				for (DWORD N = 0 ; N < nExtents ; N++)
				{
					char* pComma=strchr(pStart,',');
					if (pComma)
						*pComma=0;

					pExtents[N]=atoi(pStart);
					TotalElements*=pExtents[N];
					if (pComma)
					{
						*pComma=',';
						pStart=&pComma[1];
					}
				}
			}

            if(pData = (MQ2VARPTR*) malloc(sizeof(MQ2VARPTR)*TotalElements)) {
				if (pType=Type) {
					for (DWORD N = 0 ; N < TotalElements ; N++)
					{
						pType->InitVariable(pData[N]);
						if (ByData)
							pType->FromData(pData[N],*(MQ2TYPEVAR *)Default);
						else
							pType->FromString(pData[N], (char*)Default);
					}
				}
			}
        }

        void Delete()
        {
            if (pExtents)
                free(pExtents);
            if (pType && pData)
                for (DWORD N = 0 ; N < TotalElements ; N++)
                {
                    pType->FreeVariable(pData[N]);
                }
                free(pData);
                pType=0;
                nExtents=0;
                pExtents=0;
                pData=0;
                TotalElements=0;
        }

        int GetElement(char* Index)
        {
            DWORD Element=0;
            if (nExtents==1)
            {
                if (strchr(Index,','))
                    return -1;
                Element=atoi(Index)-1;
                if (Element>=TotalElements)
                    return -1;
                return Element;
            }
            else
            {
                DWORD nGetExtents = 1;

                if (char* pComma=strchr(Index,','))
                {
                    nGetExtents++;
                    while(pComma=strchr(&pComma[1],','))
                    {
                        nGetExtents++;
                    }
                }
                if (nGetExtents!=nExtents)
                    return -1;

                // read extents
                char* pStart=Index;
                for (DWORD N = 0 ; N < nExtents ; N++)
                {
                    char* pComma=strchr(pStart,',');
                    if (pComma)
                        *pComma=0;

                    DWORD Temp=atoi(pStart)-1;
                    if (Temp>=pExtents[N])
                        return -1;
                    for (unsigned long i = N+1 ; i < nExtents; i++)
                        Temp*=pExtents[i];
                    Element+=Temp;

                    if (pComma)
                    {
                        *pComma=',';
                        pStart=&pComma[1];
                    }
                }
                if (Element>=TotalElements)
                {
                    // bug in array logic
                    OutputDebugString("Bug in array logic\n");
                    return -1;
                }
                return Element;
            }
        }

        BOOL GetElement(char* Index, MQ2TYPEVAR &Dest)
        {
            DWORD Element=0;
            if (nExtents==1)
            {
                if (strchr(Index,','))
                    return FALSE;
                Element=atoi(Index)-1;
                if (Element>=TotalElements)
                    return FALSE;
                Dest.Type=pType;
                Dest.VarPtr=pData[Element];
                return TRUE;
            }
            else
            {
                DWORD nGetExtents = 1;

                if (char* pComma=strchr(Index,','))
                {
                    nGetExtents++;
                    while(pComma=strchr(&pComma[1],','))
                    {
                        nGetExtents++;
                    }
                }
                if (nGetExtents!=nExtents)
                    return FALSE;

                // read extents
                char* pStart=Index;
                unsigned long N;
                for (N = 0 ; N < nExtents ; N++)
                {
                    char* pComma=strchr(pStart,',');
                    if (pComma)
                        *pComma=0;

                    DWORD Temp=atoi(pStart)-1;
                    if (Temp>=pExtents[N])
                        return FALSE;
                    for (unsigned long i = N+1 ; i < nExtents; i++)
                        Temp*=pExtents[i];
                    Element+=Temp;

                    if (pComma)
                    {
                        *pComma=',';
                        pStart=&pComma[1];
                    }
                }
                if (Element>=TotalElements)
                {
                    // bug in array logic
                    OutputDebugString("Bug in array logic\n");
                    return FALSE;
                }
                Dest.Type=pType;
                Dest.VarPtr=pData[Element];
                return TRUE;
            }

        }

        ~CDataArray()
        {
            if (pExtents)
                free(pExtents);
            if (pType && pData)
                for (unsigned long N = 0 ; N < TotalElements ; N++)
                {
                    pType->FreeVariable(pData[N]);
                }
                free(pData);
        }

        MQ2Type *pType;
        DWORD nExtents;
        DWORD *pExtents;
        MQ2VARPTR *pData;
        DWORD TotalElements;
    };

    typedef struct _MQRANK
    {
        MQ2VARPTR VarPtr;
        MQ2VARPTR Value;
    } MQRANK, *PMQRANK;

    static bool pMQRankFloatCompare(const PMQRANK A, const PMQRANK B)
    {
        return A->Value.Float < B->Value.Float;
    }
	static bool MQRankFloatCompare(const MQRANK &A, const MQRANK &B)
	{
		return A.Value.Float < B.Value.Float;
	}

    static int MQRankFloatCompareReverse(const void *A, const void *B)
    {
        if (((PMQRANK)A)->Value.Float==((PMQRANK)B)->Value.Float)
            return 0;
        if (((PMQRANK)A)->Value.Float>((PMQRANK)B)->Value.Float)
            return -1;
        return 1;
    }
    static int MQRankCompare(const void *A, const void *B)
    {
        if (((PMQRANK)A)->Value.DWord==((PMQRANK)B)->Value.DWord)
            return 0;
        if (((PMQRANK)A)->Value.DWord<((PMQRANK)B)->Value.DWord)
            return -1;
        return 1;
    }

    static int MQRankCompareReverse(const void *A, const void *B)
    {
        if (((PMQRANK)A)->Value.DWord==((PMQRANK)B)->Value.DWord)
            return 0;
        if (((PMQRANK)A)->Value.DWord>((PMQRANK)B)->Value.DWord)
            return -1;
        return 1;
    }
	static bool nonalpha ( int value ) {
		int ret = isalnum(value);
		if(ret==0)
			return true;
	   return false;
	}
	static bool noblank ( char value ) {
		if(value == ' ' || value == '\t')
			return true;
	   return false;
	}
	static errno_t _httoi_s(const char *thevalue,size_t _Size)
	{
		struct CHexMap {
			char chr;
			int avalue;
		};
		const int HexMapL = 16;
		CHexMap HexMap[HexMapL] =
		{
			{'0', 0}, {'1', 1},
			{'2', 2}, {'3', 3},
			{'4', 4}, {'5', 5},
			{'6', 6}, {'7', 7},
			{'8', 8}, {'9', 9},
			{'A', 10}, {'B', 11},
			{'C', 12}, {'D', 13},
			{'E', 14}, {'F', 15}
		};
		char *mstr = _strdup(thevalue);
		mstr[_Size] = '\0';
		_strupr_s(mstr,_Size+1);
		char *s = mstr;
		int result = 0;
		std::string s1 = mstr;
	
		s1.erase(remove_if(s1.begin(),s1.end(), nonalpha), s1.end());
	
		s = (char *)s1.c_str();
		if (*s == '0' && *(s + 1) == 'X')
			s += 2;
		bool firsttime = true;
		while (*s != '\0') {
			bool found = false;
			for (int i = 0; i < HexMapL; i++) {
				if (*s == HexMap[i].chr) {
					if (!firsttime) {
						result <<= 4;
					}
					result |= HexMap[i].avalue;
					found = true;
					break;
				}
			}
			if (!found) {
				break;
			}
			s++;
			firsttime = false;
		}
		free(mstr);
		return result;
	}

struct Loop
{
	enum Type {None,For,While};
	Type type{None};
	int	first_line{0};
	int last_line{0};
	std::string for_variable;
};

    typedef struct MACROSTACK {
		bool bIsBind;
         int LocationIndex;
        struct MACROSTACK *pNext;
        char Return[MAX_STRING];
        PDATAVAR Parameters;
        PDATAVAR LocalVariables;
		std::vector<Loop> loop_stack;
	} *PMACROSTACK;

    typedef struct _EVENTQUEUE {
        struct _EVENTQUEUE *pPrev;
        struct _EVENTQUEUE *pNext;
        DWORD Type;
		std::string Name;
        PEVENTLIST pEventList;
        PDATAVAR Parameters;
    } EVENTQUEUE, *PEVENTQUEUE;

	struct MercDesc
	{
		std::string Race;
		std::string Type;
		std::string Confidence;
		std::string Proficiency;
	};
};
using namespace MQ2Internal;

