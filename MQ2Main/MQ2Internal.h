/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/

namespace MQ2Internal {

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
};

typedef struct _SEARCHSPAWN {
    DWORD MinLevel;
    DWORD MaxLevel;
    eSpawnType SpawnType;
    DWORD SpawnID;
    DWORD FromSpawnID;
    FLOAT Radius;
    CHAR szName[MAX_STRING];
    CHAR szBodyType[MAX_STRING];
    CHAR szRace[MAX_STRING];
    CHAR szClass[MAX_STRING];
    CHAR szLight[MAX_STRING];
    DWORD GuildID;
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
	BOOL bRaid;
	BOOL bGM;
	BOOL bNamed;
	BOOL bMerchant;
	BOOL bTributeMaster;
	BOOL bKnight;
	BOOL bTank;
	BOOL bHealer;
	BOOL bDps;
	BOOL bSlower;
	BOOL bAura;
    DWORD NotID;
    DWORD NotNearAlertList;
    DWORD NearAlertList;
    DWORD NoAlertList;
    DWORD AlertList;
    DOUBLE ZRadius;
    DOUBLE FRadius;
    FLOAT xLoc;
    FLOAT yLoc;
    BOOL bKnownLocation;
    BOOL bNoPet;
    DWORD SortBy;
    BOOL bNoGuild;
	BOOL bLoS;
} SEARCHSPAWN, *PSEARCHSPAWN;

static enum SearchItemFlag
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
	CHAR FlagMask[MAX_STRING];
	CHAR Flag[MAX_STRING];

	CHAR szName[MAX_STRING];
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
    CHAR szName[MAX_STRING];
    CHAR szLine[MAX_STRING];
    BYTE Level;
    DWORD SpawnID;
    FLOAT Distance;
    DWORD Class;
    DWORD Race;
    DWORD GuildID;
} SWHOSORT, *PSWHOSORT;

typedef struct _CONNECTION {
    SOCKET socket;
    BOOL Auth;
    struct _CONNECTION *pNext;
} CONNECTION, *PCONNECTION;

typedef struct _CHATBUF {
    CHAR szText[MAX_STRING];
    struct _CHATBUF *pNext;
} CHATBUF, *PCHATBUF;


typedef struct _MOUSEINFO {
    DWORD X;
    DWORD Y;
    DWORD SpeedX;
    DWORD SpeedY;
} MOUSEINFO, *PMOUSEINFO;


typedef struct _SPELLINFO {
    CHAR Name[32];
    CHAR Target[32];
} SPELLINFO, *PSPELLINFO;

typedef struct _PACKLOC {
    DWORD X;
    DWORD Y;
} PACKLOC, *PPACKLOC;

typedef struct _MACROBLOCK {
    CHAR Line[MAX_STRING];
    CHAR SourceFile[MAX_STRING];
    DWORD LineNumber;
#ifdef MQ2_PROFILING
    DWORD ExecutionCount;
    LONGLONG ExecutionTime;
#endif
    struct _MACROBLOCK *pNext;
    struct _MACROBLOCK *pPrev;
} MACROBLOCK, *PMACROBLOCK;


typedef struct _ALERT {
    SEARCHSPAWN SearchSpawn;
    struct _ALERT *pNext;
} ALERT, *PALERT;

typedef struct _ALERTLIST {
    DWORD Id;
    PALERT pAlert;
    struct _ALERTLIST *pNext;
} ALERTLIST, *PALERTLIST;

typedef struct _MQTIMER {
    CHAR szName[MAX_VARNAME];
    ULONG Original;
    ULONG Current;
    struct _MQTIMER *pNext;
	struct _MQTIMER *pPrev;
} MQTIMER, *PMQTIMER;

typedef struct _KEYPRESS {
    WORD KeyId;
    BOOL Pressed;
    struct _KEYPRESS *pNext;
} KEYPRESS, *PKEYPRESS;

typedef struct _DIKEYID {
    CHAR szName[32];
    WORD Id;
} DIKEYID, *PDIKEYID;

typedef struct _ITEMDB {
    struct _ITEMDB *pNext;
    DWORD ID;
    CHAR szName[256];
} ITEMDB, *PITEMDB;

typedef struct _DEFINE {
    struct _DEFINE *pNext;
    CHAR szName[MAX_STRING];
    CHAR szReplace[MAX_STRING];
} DEFINE, *PDEFINE;

typedef struct _EVENTLIST {
    struct _EVENTLIST *pNext;
    CHAR szName[MAX_STRING];
    CHAR szMatch[MAX_STRING];
    PMACROBLOCK pEventFunc;
#ifdef USEBLECHEVENTS
	DWORD BlechID;
#endif
} EVENTLIST, *PEVENTLIST;


typedef struct _ALIAS {
    struct _ALIAS *pNext;
    struct _ALIAS *pLast;
    CHAR szName[MAX_STRING];
    CHAR szCommand[MAX_STRING];
} ALIAS, *PALIAS;

typedef struct _SUB {
	struct _SUB *pNext;
	struct _SUB *pLast;
	CHAR szOrig[MAX_STRING];
	CHAR szSub[MAX_STRING];
} SUB, *PSUB;

typedef struct _MQCOMMAND {
	CHAR Command[64];
	fEQCommand Function;
	BOOL EQ;
	BOOL Parse;
	BOOL InGameOnly;
	struct _MQCOMMAND* pLast;
	struct _MQCOMMAND* pNext;
} MQCOMMAND, *PMQCOMMAND;


typedef struct _FILTER {
    struct _FILTER *pNext;
    CHAR FilterText[MAX_STRING];
    DWORD Length;
    PBOOL pEnabled;
} FILTER, *PFILTER;

typedef struct _PARMLIST {
	CHAR szName[MAX_STRING];
	DWORD (__cdecl *fAddress)(PCHAR, PCHAR, PSPAWNINFO);
} PARMLIST, *PPARMLIST;

typedef struct _MQXMLFile
{
	char szFilename[MAX_PATH];
	_MQXMLFile *pLast;
	_MQXMLFile *pNext;
} MQXMLFILE, *PMQXMLFILE;

typedef struct _MQBENCH
{
	CHAR szName[64];
	DWORD Entry;
	DWORD LastTime;
	DWORD TotalTime;
	DWORD Count;
} MQBENCH, *PMQBENCH;

typedef struct _MQGroundPending
{
	PGROUNDITEM pGroundItem;
	struct _MQGroundPending *pLast;
	struct _MQGroundPending *pNext;
} MQGROUNDPENDING, *PMQGROUNDPENDING;

typedef struct _MQPlugin
{
	char szFilename[MAX_PATH];
	HMODULE hModule;
        float fpVersion;

	fMQInitializePlugin Initialize;
	fMQShutdownPlugin Shutdown;
	fMQZoned Zoned;
	fMQWriteChatColor WriteChatColor;
	fMQPulse Pulse;
	fMQIncomingChat IncomingChat;
	fMQCleanUI CleanUI;
	fMQReloadUI ReloadUI;
	fMQDrawHUD DrawHUD;
	fMQSetGameState SetGameState;
	fMQSpawn AddSpawn;
	fMQSpawn RemoveSpawn;
	fMQGroundItem AddGroundItem;
	fMQGroundItem RemoveGroundItem;
        fMQBeginZone BeginZone; 
        fMQEndZone EndZone; 
	struct _MQPlugin* pLast;
	struct _MQPlugin* pNext;
} MQPLUGIN, *PMQPLUGIN;

class CAutoLock {
public:
    inline void Lock() { if (!bLocked) { EnterCriticalSection(pLock); bLocked = TRUE; }}
    inline void Unlock() { if (bLocked) { LeaveCriticalSection(pLock); bLocked = FALSE; }}
    CAutoLock(LPCRITICAL_SECTION _pLock) { bLocked = FALSE; pLock = _pLock; Lock(); }
    ~CAutoLock() { Unlock(); }

private:
    LPCRITICAL_SECTION pLock;
    BOOL bLocked;
};

class CCustomWnd : public CSidlScreenWnd
{
public:
	CCustomWnd(CXStr *screenpiece):CSidlScreenWnd(0,screenpiece,-1,1,0)
	{
		CreateChildrenFromSidl();
		pXWnd()->Show(1,1);
		ReplacevfTable();

	};
	CCustomWnd(char *screenpiece):CSidlScreenWnd(0,&CXStr(screenpiece),-1,1,0)
	{
		CreateChildrenFromSidl();
		pXWnd()->Show(1,1);
		ReplacevfTable();
        }


	~CCustomWnd()
	{
		RemovevfTable();
	};

//	int WndNotification(CXWnd *pWnd, unsigned int Message, void *unknown)
//	{	
//		return CSidlScreenWnd::WndNotification(pWnd,Message,unknown);
//	};

	void ReplacevfTable()
	{
		OldvfTable=((_CSIDLWND*)this)->pvfTable;
		PCSIDLWNDVFTABLE NewvfTable=new CSIDLWNDVFTABLE;
		memcpy(NewvfTable,OldvfTable,sizeof(CSIDLWNDVFTABLE));
		((_CSIDLWND*)this)->pvfTable=NewvfTable;
	};

	void RemovevfTable()
	{
		PCSIDLWNDVFTABLE NewvfTable=((_CSIDLWND*)this)->pvfTable;
		((_CSIDLWND*)this)->pvfTable=OldvfTable;
		delete NewvfTable;
	}

	void SetvfTable(DWORD index, DWORD value)
	{
		DWORD* vtable=(DWORD*)((_CSIDLWND*)this)->pvfTable;
		vtable[index]=value;
	}

	PCSIDLWNDVFTABLE OldvfTable;

//	inline CXWnd *GetChildItem(const char *Name) {return CSidlScreenWnd::GetChildItem(Name);};
};

#if !defined(ISXEQ) && !defined(ISXEQ_LEGACY)
/* CIndex class stolen from teqim - Lax */
template <class Any>
class CIndex
{
public:
	CIndex()
	{
		InitializeCriticalSection(&CS);
		Size=0;
		List=0;
	}

	CIndex(unsigned long InitialSize)
	{
		InitializeCriticalSection(&CS);
		Size=0;
		List=0;
		Resize(InitialSize);
	}

	~CIndex()
	{// user is responsible for managing elements
		CAutoLock L(&CS);
		if (List)
			free(List);
		List=0;
		Size=0;
		DeleteCriticalSection(&CS);
	}

	void Cleanup()
	{
		for (unsigned long i = 0 ; i < Size ; i++)
		{
			if (List[i])
			{
				delete List[i];
				List[i]=0;
			}
		}
	}

	void Resize(unsigned long NewSize)
	{
		CAutoLock L(&CS);
		if (List)
		{
			if (NewSize>Size)
			{
				// because we want to zero out the unused portions, we wont use realloc
				Any *NewList=(Any*)malloc(NewSize*sizeof(Any));
				memset(NewList,0,NewSize*sizeof(Any));
				memcpy(NewList,List,Size*sizeof(Any));
				free(List);
				List=NewList;
				Size=NewSize;
			}
		}
		else
		{
			List=(Any*)malloc(NewSize*sizeof(Any));
			memset(List,0,NewSize*sizeof(Any));
			Size=NewSize;
		}
	}

	// gets the next unused index, resizing if necessary
	inline unsigned long GetUnused()
	{
                unsigned long i;
		CAutoLock L(&CS);
		for (i = 0 ; i < Size ; i++)
		{
			if (!List[i])
				return i;
		}
		Resize(Size+10);
		return i;
	}

	unsigned long Count()
	{
		CAutoLock L(&CS);
		unsigned long ret=0;
		for (unsigned long i = 0 ; i < Size ; i++)
		{
			if (List[i])
				ret++;
		}
		return ret;
	}

	unsigned long Size;
	Any *List;

	inline Any& operator+=(Any& Value){return List[GetUnused()]=Value;}
	inline Any& operator[](unsigned long Index){return List[Index];}
	CRITICAL_SECTION CS;
};
#endif

typedef struct _MQ2VarPtr
{
	union {
		PVOID Ptr;
		FLOAT Float;
		DWORD DWord;
		ARGBCOLOR Argb;
		int   Int;
		UCHAR Array[4];
	};
} MQ2VARPTR, *PMQ2VARPTR;

#ifndef ISXEQ

typedef struct _MQ2TypeVar
{
	class MQ2Type *Type;
	union {
		MQ2VARPTR VarPtr;
		PVOID Ptr;
		FLOAT Float;
		DWORD DWord;
		ARGBCOLOR Argb;
		int   Int;
		UCHAR Array[4];
	};
} MQ2TYPEVAR, *PMQ2TYPEVAR;

typedef struct _MQ2TypeMember
{
	DWORD ID;
	PCHAR Name;
} MQ2TYPEMEMBER, *PMQ2TYPEMEMBER;

typedef BOOL  (__cdecl *fMQData)(PCHAR szIndex, MQ2TYPEVAR &Ret);

typedef struct _MQ2DataItem
{
	CHAR Name[64];
	fMQData Function;
} MQ2DATAITEM, *PMQ2DATAITEM;

LEGACY_API BOOL AddMQ2Type(class MQ2Type &Type);
LEGACY_API BOOL RemoveMQ2Type(class MQ2Type &Type);

typedef struct _DATAVAR {
	CHAR szName[MAX_STRING];
	MQ2TYPEVAR Var;
	struct _DATAVAR *pNext;
	struct _DATAVAR *pPrev;
	struct _DATAVAR **ppHead;
} DATAVAR, *PDATAVAR;

class MQ2Type
{
public:
	inline MQ2Type(PCHAR NewName)
	{
		strncpy(TypeName,NewName,32);
		TypeName[31]=0;
		Official=AddMQ2Type(*this);
		pInherits=0;
	}

	inline void InitializeMembers(PMQ2TYPEMEMBER MemberArray)
	{
		for (unsigned long i = 0 ; MemberArray[i].ID ; i++)
		{
			AddMember(MemberArray[i].ID,MemberArray[i].Name);
		}
	}

	inline ~MQ2Type() 
	{
		if (Official)
			RemoveMQ2Type(*this);
		Members.Cleanup();
	}

	virtual bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)=0;
	virtual bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)=0;
	virtual void InitVariable(MQ2VARPTR &VarPtr) {VarPtr.Ptr=0;}
	virtual void FreeVariable(MQ2VARPTR &VarPtr) {}

	virtual bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)=0;
//	virtual bool SetMember(PVOID Ptr, PCHAR Member, DWORD Index, MQ2TYPEVAR &Data)=0;
	virtual bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		strcpy(Destination,TypeName);
		return true;
	}

	inline PCHAR GetName() {return &TypeName[0];}

	PCHAR GetMemberName(DWORD ID)
	{
		for (unsigned long N=0 ; N < Members.Size ; N++)
		{
			if (PMQ2TYPEMEMBER pMember = Members[N])
			{
				if (pMember->ID==ID)
					return &pMember->Name[0];
			}
		}
		return 0;
	}

	BOOL GetMemberID(PCHAR Name, DWORD &Result)
	{
		unsigned long N=MemberMap[Name];
		if (N==0)
			return false;
		N--;
		PMQ2TYPEMEMBER pMember = Members[N];
		Result=pMember->ID;
		return true;
	}
	PMQ2TYPEMEMBER FindMember(PCHAR Name)
	{
		unsigned long N=MemberMap[Name];
		if (!N)
			return 0;
		N--;
		return Members[N];
	}
	BOOL InheritedMember(PCHAR Name)
	{
		if (!pInherits || !pInherits->FindMember(Name))
			return FALSE;
		return TRUE;
	}
	void SetInheritance(MQ2Type *pNewInherit)
	{
		pInherits=pNewInherit;
	}

protected:

	inline BOOL AddMember(DWORD ID, PCHAR Name)
	{
		unsigned long N=MemberMap[Name];
		if (N>0)
			return false;
		N=Members.GetUnused();
		MemberMap[Name]=N+1;
		PMQ2TYPEMEMBER pMember = new MQ2TYPEMEMBER;
		pMember->Name=Name;
		pMember->ID=ID;
		Members[N]=pMember;
		return true;
	}

	inline BOOL RemoveMember(PCHAR Name)
	{
		unsigned long N=MemberMap[Name];
		if (N==0)
			return false;
		N--;
		PMQ2TYPEMEMBER pMember = Members[N];
		delete pMember;
		Members[N]=0;
	}

	CHAR TypeName[32];
	BOOL Official;
	CIndex<PMQ2TYPEMEMBER> Members;
	map<string,DWORD> MemberMap;
	MQ2Type *pInherits;
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

	CDataArray(MQ2Type *Type, PCHAR Index, PCHAR Default)
	{
		nExtents=1;

		// count number of , 's
		if (PCHAR pComma=strchr(Index,','))
		{
			nExtents++;
			while(pComma=strchr(&pComma[1],','))
			{
				nExtents++;
			}
		}

		// allocate extents

		pExtents=(DWORD*)malloc(sizeof(DWORD)*nExtents);

		TotalElements=1;

		// read extents
		PCHAR pStart=Index;
		unsigned long N;
		for (N = 0 ; N < nExtents ; N++)
		{
			PCHAR pComma=strchr(pStart,',');
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

		pData = (MQ2VARPTR*) malloc(sizeof(MQ2VARPTR)*TotalElements);

		if (pType=Type)
		for (N = 0 ; N < TotalElements ; N++)
		{
			pType->InitVariable(pData[N]);
			pType->FromString(pData[N],Default);
		}

	}

	void Delete()
	{
		if (pExtents)
			free(pExtents);
		if (pType && pData)
		for (unsigned long N = 0 ; N < TotalElements ; N++)
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

	int GetElement(PCHAR Index)
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

			if (PCHAR pComma=strchr(Index,','))
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
			PCHAR pStart=Index;
			unsigned long N;
			for (N = 0 ; N < nExtents ; N++)
			{
				PCHAR pComma=strchr(pStart,',');
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

	BOOL GetElement(PCHAR Index, MQ2TYPEVAR &Dest)
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

			if (PCHAR pComma=strchr(Index,','))
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
			PCHAR pStart=Index;
			unsigned long N;
			for (N = 0 ; N < nExtents ; N++)
			{
				PCHAR pComma=strchr(pStart,',');
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
#endif

typedef struct _MQRANK
{
	MQ2VARPTR VarPtr;
	MQ2VARPTR Value;
} MQRANK, *PMQRANK;

static int pMQRankFloatCompare(const void *A, const void *B)
{
    if ((*(PMQRANK*)A)->Value.Float==(*(PMQRANK*)B)->Value.Float)
		return 0;
    if ((*(PMQRANK*)A)->Value.Float<(*(PMQRANK*)B)->Value.Float)
		return -1;
	return 1;
}

static int MQRankFloatCompare(const void *A, const void *B)
{
    if (((PMQRANK)A)->Value.Float==((PMQRANK)B)->Value.Float)
		return 0;
    if (((PMQRANK)A)->Value.Float<((PMQRANK)B)->Value.Float)
		return -1;
	return 1;
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

#ifndef ISXEQ
typedef struct _MACROSTACK {
    PMACROBLOCK Location;
    struct _MACROSTACK *pNext;
    CHAR Return[MAX_STRING];
    PDATAVAR Parameters;
    PDATAVAR LocalVariables;
} MACROSTACK, *PMACROSTACK;

typedef struct _EVENTQUEUE {
    struct _EVENTQUEUE *pPrev;
	struct _EVENTQUEUE *pNext;
    DWORD Type;
    PEVENTLIST pEventList;
    PDATAVAR Parameters;
} EVENTQUEUE, *PEVENTQUEUE;
#endif

};
using namespace MQ2Internal;

