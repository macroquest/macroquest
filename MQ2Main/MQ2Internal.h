namespace MQ2Internal {
typedef struct _SEARCHSPAWN {
    DWORD MinLevel;
    DWORD MaxLevel;
    DWORD SpawnType;
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
    BOOL bTargInvis;
    BOOL bTargNext;
    BOOL bTargPrev;
	BOOL bGroup;
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
} SEARCHSPAWN, *PSEARCHSPAWN;

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

typedef struct _VARSTRINGS {
    CHAR szName[MAX_VARNAME];
    CHAR szVar[MAX_STRING];
    struct _VARSTRINGS *pNext;
} VARSTRINGS, *PVARSTRINGS;

typedef struct _VARARRAYS {
    CHAR szName[MAX_VARNAME];
    BOOL OneDimension;
    PVARSTRINGS pVarStrings;
    struct _VARARRAYS *pNext;
} VARARRAYS, *PVARARRAYS;

typedef struct _MACROSTACK {
    PMACROBLOCK Location;
    struct _MACROSTACK *pNext;
    CHAR Return[MAX_STRING];
    PVARSTRINGS StackStr;
    PVARSTRINGS LocalStr;
} MACROSTACK, *PMACROSTACK;

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
} EVENTLIST, *PEVENTLIST;


typedef struct _ALIAS {
    struct _ALIAS *pNext;
    struct _ALIAS *pLast;
    CHAR szName[MAX_STRING];
    CHAR szCommand[MAX_STRING];
} ALIAS, *PALIAS;

typedef struct _MQCOMMAND {
	CHAR Command[64];
	fEQCommand Function;
	BOOL EQ;
	BOOL Parse;
	struct _MQCOMMAND* pLast;
	struct _MQCOMMAND* pNext;
} MQCOMMAND, *PMQCOMMAND;

typedef struct _HOTKEY {
    struct _HOTKEY *pNext;
    CHAR szName[MAX_STRING];
    DWORD DIKey;
    CHAR szCommand[MAX_STRING];
} HOTKEY, *PHOTKEY;

typedef struct _EVENTSTACK {
    struct _EVENTSTACK *pNext;
    DWORD Type;
    PEVENTLIST pEventList;
    PVARSTRINGS EventStr;
} EVENTSTACK, *PEVENTSTACK;

typedef struct _TIMER {
    CHAR szName[MAX_VARNAME];
    ULONG Original;
    ULONG Current;
    struct _TIMER *pNext;
} TIMER, *PTIMER;

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

typedef struct _MQPlugin
{
	char szFilename[MAX_PATH];
	HMODULE hModule;

	fMQInitializePlugin Initialize;
	fMQShutdownPlugin Shutdown;
	fMQZoned Zoned;
	fMQWriteChatColor WriteChatColor;
	fMQPulse Pulse;
	fMQIncomingChat IncomingChat;
	fMQCleanUI CleanUI;
	fMQDrawHUD DrawHUD;
	fMQSetGameState SetGameState;
	struct _MQPlugin* pLast;
	struct _MQPlugin* pNext;
} MQPLUGIN, *PMQPLUGIN;

class CAutoLock {
public:
    void Lock() { if (!bLocked) { EnterCriticalSection(pLock); bLocked = TRUE; }}
    void Unlock() { if (bLocked) { LeaveCriticalSection(pLock); bLocked = FALSE; }}
    CAutoLock(LPCRITICAL_SECTION _pLock) { bLocked = FALSE; pLock = _pLock; Lock(); }
    ~CAutoLock() { Unlock(); }

private:
    LPCRITICAL_SECTION pLock;
    BOOL bLocked;
};
};
using namespace MQ2Internal;