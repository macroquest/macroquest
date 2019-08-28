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

/*
Change log:
# Version: 2.8 - SwiftyMUSE 03-11-2018 - Added global hotkey processing
# Version: 2.7 - EqMule 10-04-2016 - Added a new flag to make sure we have tried to get credentials. and some other stuff
# Version: 2.6 - Derple 08-21-2016 - Added a new flag which disables autologin after the first successful login.  It can re-enabled by pressing HOME.
# Version: 2.5 - Eqmule 07-29-2016 - Moved processing into its own detour, removed waitforinputidle and all arbitrary Sleeps.
# Version: 2.4 - Eqmule 07-22-2016 - Added support for emulators
# Version: 2.3 - Eqmule 07-22-2016 - Added string safety.
# Version: 2.2 by eqmule/derple 20160629
- made all WaitForInputIdle 60 seconds to prevent crashes
- Added an extra crash check.

# Version: 2.1 by eqmule 20160627
- Added Encryption to the plugin and support for MacroQuest2.exe profiles.

# Version: 2.0 by eqmule 20160616
- Added Version Support
- Updated to not crash on /unload
- Added a feature to login your char if you load/reload at char select
- this setting is called LoginOnReLoadAtCharSelect=1 and should go under Settings if you want to use it.

#  20150711 - eqmule
- Updated for lockjaw server

#  20150523 - eqmule
- Updated for ragefire server and some other bugfixes and stuff...

#  20150428 - eqmule
- Updated for latest patch

#  20131009 - ieatacid
- Added 'test' to server list, per request

#  20131004 - eqmule
- Updated for latest patch
- Had to change the MAX_WINDOWS or we would get caught in a loop...

Change log:
#  20121111
- Updated for latest patch

#  20121101
- Added vox and trakanon servers

#  20121020
- Added ability to check for active characters and login offline character
- Removed instant camp stuff

#  20120901
- Doubled Sleep durations to stop crashes

#  2011121
- Updated for VoA expansion release

#  20110215
- Added new server names (thanks, htw)

#  20101024
- Fixed offset patterns that were broken with House of Thule expansion release

#  20100622
- Adjusted for server merges

#  20091125
- Fixed issue with a blank character name making the login process stop at character select

#  20091121
- Now supports using station names rather than sessions (this is helpful if you use WinEQ2 profiles)

#  20091118
- The plugin now clicks through the order expansion screen

#  20091117
- The plugin will now click through the seizure warning screen

#  20091112
- Fixed for November 11th patch

#  20090908
- Made some adjustments that speed up logging in
- Debug logging now adds a time stamp

# 20090906a
- Fixed a bug where two threads were being created at start-up
- The session count is retrieved using the process list rather than enumerating through windows
- If debugging is enabled, the output now goes to a text file at "c:/MQ2AutoLogin_dbg.txt". The file path can be changed at the top of the .cpp file
- If server name isn't specified in the ini file it will stop at the server-select screen
- If a character name isn't specified in the ini file it will stop at the character-select screen

# 20090906
- Added ini option for setting a different ini file path, e.g. (in Settings) "IniLocation=x:\mq2"
- Integrated MQ2SwitchChar

# 20090831
- Initial release
******************************************************************************/

#include "../MQ2Plugin.h"

#include <map>
#include <tlhelp32.h>
#include <wincrypt.h>
#pragma comment(lib, "Crypt32.lib")

#define PLUGIN_NAME "MQ2AutoLogin"
#define PLUGIN_DATE 20181212
PLUGIN_VERSION(2.9);

PreSetup("MQ2AutoLogin");

#define MAX_WINDOWS 150 // had to lower this for CotF patch it never reaches 200...

/*** un-comment to enable debug logging ***/
//#define AUTOLOGIN_DBG

/*** this can be changed ***/
#define DBG_LOGFILE_PATH "c:\\MQ2AutoLogin_dbg.txt"

#ifdef AUTOLOGIN_DBG
#define AutoLoginDebug DebugLog
#else
#define AutoLoginDebug //
#endif

struct {
	const char* Name;
	int ID;
} ServerData[] = {
	{"lockjaw",     160},
	{"ragefire",    159},
	{"vox",         158},
	{"trakanon",    155},
	{"fippy",       156},
	{"vulak",       157},
	{"mayong",      163},
	{"antonius",    100},
	{"beta",        67},
	{"brekt",       162},
	{"bertox",      102},
	{"bristle",     104},
	{"cazic",       105},
	{"drinal",      106},
	{"erollisi",    109},
	{"firiona",     111},
	{"luclin",      116},
	{"povar",       123},
	{"rathe",       127},
	{"tunare",      140},
	{"xegony",      144},
	{"zek",         147},
	{"test",        1},
	{0, 0},
};

struct DateStruct
{
/*0x18*/ char      Hours;
/*0x19*/ char      Minutes;
/*0x1a*/ char      Seconds;
/*0x1b*/ char      Month;
/*0x1c*/ char      Day;
/*0x1e*/ WORD      Year;
/*0x20*/ CXStr     Unknown0x08;
/*0x24*/ CXStr     Unknown0x0c;
/*0x28*/ CXStr     Unknown0x10;
/*0x30*/ int64_t   TimeStamp;
/*0x38*/
};

// EQClientServerData
struct SERVERINFO
{
/*0x00*/ DWORD     ID;
/*0x04*/ CXStr     ServerName;
/*0x08*/ CXStr     HostName;
/*0x0C*/ CXStr     ServerIP;
/*0x10*/ DWORD     ExternalPort;
/*0x14*/ DWORD     InternalPort;
/*0x18*/ DateStruct DateCreated;
/*0x38*/ DWORD     Flags;
/*0x3C*/ DWORD     ServerType;
/*0x40*/ CXStr     LanguageCode;
/*0x44*/ CXStr     CountryCode;
/*0x48*/ DWORD     StatusFlags;
/*0x4C*/ DWORD     PopulationRanking;
/*0x50*/
};

struct SERVERLIST
{
/*0x00*/ SERVERINFO* Info;
/*0x04*/ SERVERLIST* Prev;
/*0x08*/ SERVERLIST* Next;
/*0x0C*/ DWORD     Unknown0x0C;
/*0x10*/ DWORD     Unknown0x10;
/*0x14*/ DWORD     Unknown0x14;
/*0x18*/
};

struct SERVERSTUFF
{
/*0x000*/ BYTE     Unknown0x000[0x8];
/*0x008*/ void*    GFXENGINE;
/*0x00C*/ BYTE     Unknown0x00C[0x9C];
/*0x0A8*/ DWORD    CurrentServerID;
/*0x0AC*/ DWORD    Unknown0x0AC;
/*0x0B0*/ CXStr    LoginName;
/*0x0B4*/ CXStr    Password;
/*0x0B8*/ CXStr    LoginNameCopy;
/*0x0BC*/ CXStr    PasswordCopy;
/*0x0C0*/ CXStr    AccountKey;
/*0x0C4*/ BYTE     Unknown0x0C4[0x14];
/*0x0D8*/ SERVERINFO** FirstServer;
/*0x0DC*/ SERVERINFO** LastServer;
/*0x0E0*/ BYTE     Unknown0x0E0[0x8];
/*0x0E8*/ SERVERLIST* pServerList;
/*0x0EC*/ DWORD    ServerListSize;
/*0x0F0*/ BYTE     Unknown0x0F0[0x8];
/*0x0F8*/ DWORD    QuickConnectServerID;
/*0x0FC*/ CXStr    QuickConnectServerName;
/*0x100*/ CXStr    QuickConnectIPAddress;
/*0x104*/
};

#define SERVER_DOWN 1
#define SERVER_LOCKED 4

class CLoginViewManager;

bool bWeAreDown = false;
int bNotifyOnServerUP = 0;
bool bLoginCheckDone = false;
bool bGotOffsets = false;
ULONGLONG ullerrorwait = 0;
DWORD dwServerInfo = 0;
CSidlManager* pSidlManager = nullptr;
CXWndManager* pWindowManager = nullptr;
CLoginViewManager* pLoginViewManager = nullptr;
DWORD dwEQMainBase = 0;
DWORD dwGetXMLDataAddr = 0;
DWORD dwSendLMouseClickAddr = 0;
DWORD dwEnterGameAddr = 0;
DWORD dwLoginClient = 0;
DWORD dwServerID = 0;
UINT bKickActiveChar = 1;
UINT bUseMQ2Login = false;
UINT bUseStationNamesInsteadOfSessions = false;
UINT bReLoggin = false;
bool bEndAfterCharSelect = false;
bool bLogin = true;
bool bEnd = false;
bool bInGame = false;
bool bSwitchServer = false;
bool bSwitchChar = false;
bool bSwitchTime = false;
bool bInjectorUpdate = false;
char szProfile[128] = { 0 };
char szStationName[64] = { 0 };
char szCustomIni[64] = { 0 };
char szPassword[64] = { 0 };
char szHotkey[64] = { 0 };
char szServerName[32] = { 0 };
char szCharacterName[64] = { 0 };
char szCharClass[64] = { 0 };
char szCharLevel[64] = { 0 };
char szSelectCharacterName[64] = { 0 };
char szNewChar[0x40] = { 0 };
char szUserName[MAX_PATH] = { 0 };
char szBlobKey[64] = { 0 };
ULONGLONG dwTime = 0;
ULONGLONG switchTime = 0;
std::map<std::string, CXWnd*> WindowMap;


// this changes frequently so it needs to be done this way
#define pLoginClient ((LoginServerAPI*)*(DWORD*)dwLoginClient)

bool SetOffsets();
bool SetOffsetsUI();
void HandleWindows();
void LoginReset();
void SwitchCharacter(char* szName);
void SelectCharacter(char* szName );
DWORD GetProcessCount(char* exeName);
void DebugLog(char* szFormat, ...);
unsigned long _FindPattern(unsigned long dwAddress,unsigned long dwLen, unsigned char* bPattern, char* szMask);
unsigned long _GetDWordAt(unsigned long address, unsigned long numBytes);
unsigned long _GetFunctionAddressAt(unsigned long address, unsigned long addressOffset, unsigned long numBytes);

// __LoadFrontEnd_x not used?
// ida style sig1 just mov     ecx, hLibModule : 8B 0D ? ? ? ? 68 ? ? ? ? 51 FF D6 A3 ? ? ? ? 85 C0 75 18
// ida style sig2 func start: 68 ? ? ? ? FF 15 ? ? ? ? A3 ? ? ? ? 85 C0
// 8B 0D ?? ?? ?? ?? 68 ?? ?? ?? ?? 51 FF D6 A3 ?? ?? ?? ?? 85 C0 75 ?? FF 15 ?? ?? ?? ?? 50 68 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 C4 ?? 33 C0 5E C3
// x   x  ?  ?  ?  ?  x  ?  ?  ?  ?  x  x  x  x  ?  ?  ?  ?  x  x  x  ?  x  x  ?  ?  ?  ?  x  x  ?  ?  ?  ?  x  ?  ?  ?  ?  x  x  ?  x  x  x  x

// search in eqgame.exe
// Feb 16 2018 Test
// IDA Style Sig: FF 35 ? ? ? ? FF 15 ? ? ? ? A3
PBYTE eqmainPattern = (PBYTE)"\xFF\x35\x00\x00\x00\x00\xFF\x15\x00\x00\x00\x00\xA3";
char eqmainMask[] = "xx????xx????x";

// A3 ? ? ? ? E8 ? ? ? ? 83 C4 ? 85 C0 74 ? 8B 96 ? ? ? ? 52 57 8B C8 E8 ? ? ? ? EB ?
// eqmain.dll
// Feb 16 2018 Test
// A3 ? ? ? ? E8 ? ? ? ? 83 C4 04 85 C0
PBYTE lvmPattern = (PBYTE)"\xA3\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x83\xC4\x04\x85\xC0";
char lvmMask[] = "x????x????xxxxx";

// 8B 15 ? ? ? ? 89 82 ? ? ? ? A1 ? ? ? ? C6 80 ? ? ? ? ? 8B 0D ? ? ? ? 89 1D ? ? ? ? 8B 11 8B 42 ? FF D0 85 C0 74 ?
// eqmain.dll
// Apr 10 2018 Test
// A1 ? ? ? ? 89 88 ? ? ? ?
PBYTE xwmPattern = (PBYTE)"\xA1\x00\x00\x00\x00\x89\x88\x00\x00\x00\x00";
char xwmMask[] = "x????xx????";

// A1 ? ? ? ? 80 B8 ? ? ? ? ? 0F 84 ? ? ? ? 8D 88 ? ? ? ? 8B 01 3B C3 74 ? 89 45 ? 33 DB 8B 45 ? F0 FF ? 0F 94 C3 89 5D ?
// eqmain.dll
// Apr 10 2018 Test
// 8B 35 ? ? ? ? C6 45 FC 08
PBYTE swmPattern = (PBYTE)"\x8B\x35\x00\x00\x00\x00\xC6\x45\xFC\x08";
char swmMask[] = "xx????xxxx";

// 8B 54 24 ? 56 8B 74 24 ? 8B C1 85 D2 75 ? 85 F6 75 ? 33 C0 5E C2 ? ?
// eqmain.dll func start
// Feb 16 2018 Test
// IDA Style Sig: 53 8B 5C 24 0C 8B C1 57
// Code Style Signature: \x53\x8B\x5C\x24\x0C\x8B\xC1\x57 xxxxxxxx
PBYTE xmldataPattern = (PBYTE)"\x53\x8B\x5C\x24\x0C\x8B\xC1\x57";
char xmldataMask[] = "xxxxxxxx";

// 55 8B EC 6A ? 68 ? ? ? ? 64 A1 ? ? ? ? 50 83 EC ? 53 56 57 A1 ? ? ? ? 33 C5 50 8D 45 ? 64 A3 ? ? ? ? 8B F1 83 7E ? ?
// eqmain.dll func start
// Feb 16 2018 Test
// 55 8B EC 6A FF 68 ? ? ? ? 64 A1 ? ? ? ? 50 83 EC 08 53 56 57 A1 ? ? ? ? 33 C5 50 8D 45 F4 64 A3 ? ? ? ? 8B F1 83 7E 14 00 74 5D 51 8B CC 89 65 F0 68 ? ? ? ? E8 ? ? ? ? 51 8B CC 89 65 EC 68 ? ? ? ? C7 45 ? ? ? ? ? E8 ? ? ? ? 8B 4E 14 C6 45 FC 01 E8 ? ? ? ? 8B F8 51 8B DC 8B 0F 85 C9 74 09 51 E8 ? ? ? ? 83 C4 04 8B 07 8B CE 89 03 C7 45 ? ? ? ? ? E8 ? ? ? ? 84 C0 75 17 8B 4E 1C 8B 7D 08 85 C9 74 26 8B 01 57 FF 90 ? ? ? ? 85 C0 74 29 B8 ? ? ? ? 8B 4D F4 64 89 0D ? ? ? ? 59 5F 5E 5B 8B E5 5D C2 04 00 8B 4E 14 85 C9 74 09 8B 01 57 FF 90 ? ? ? ? 8B 0D ? ? ? ? 57 E8 ? ? ? ? 8B 4D F4 64 89 0D ? ? ? ? 59 5F 5E 5B 8B E5 5D C2 04 00
PBYTE lmousePattern = (PBYTE)"\x55\x8B\xEC\x6A\xFF\x68\x00\x00\x00\x00\x64\xA1\x00\x00\x00\x00\x50\x83\xEC\x08\x53\x56\x57\xA1\x00\x00\x00\x00\x33\xC5\x50\x8D\x45\xF4\x64\xA3\x00\x00\x00\x00\x8B\xF1\x83\x7E\x14\x00\x74\x5D\x51\x8B\xCC\x89\x65\xF0\x68\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x51\x8B\xCC\x89\x65\xEC\x68\x00\x00\x00\x00\xC7\x45\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x8B\x4E\x14\xC6\x45\xFC\x01\xE8\x00\x00\x00\x00\x8B\xF8\x51\x8B\xDC\x8B\x0F\x85\xC9\x74\x09\x51\xE8\x00\x00\x00\x00\x83\xC4\x04\x8B\x07\x8B\xCE\x89\x03\xC7\x45\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x84\xC0\x75\x17\x8B\x4E\x1C\x8B\x7D\x08\x85\xC9\x74\x26\x8B\x01\x57\xFF\x90\x00\x00\x00\x00\x85\xC0\x74\x29\xB8\x00\x00\x00\x00\x8B\x4D\xF4\x64\x89\x0D\x00\x00\x00\x00\x59\x5F\x5E\x5B\x8B\xE5\x5D\xC2\x04\x00\x8B\x4E\x14\x85\xC9\x74\x09\x8B\x01\x57\xFF\x90\x00\x00\x00\x00\x8B\x0D\x00\x00\x00\x00\x57\xE8\x00\x00\x00\x00\x8B\x4D\xF4\x64\x89\x0D\x00\x00\x00\x00\x59\x5F\x5E\x5B\x8B\xE5\x5D\xC2\x04\x00";
char lmouseMask[] = "xxxxxx????xx????xxxxxxxx????xxxxxxxx????xxxxxxxxxxxxxxx????x????xxxxxxx????xx?????x????xxxxxxxx????xxxxxxxxxxxxx????xxxxxxxxxxx?????x????xxxxxxxxxxxxxxxxxxx????xxxxx????xxxxxx????xxxxxxxxxxxxxxxxxxxxxx????xx????xx????xxxxxx????xxxxxxxxxx";

// A3 ? ? ? ? 8B 56 ? 8B 4A ? 6A ? 51 52 8B C8 C7 45 ? ? ? ? ? E8 ? ? ? ?
// eqmain.dll dword in func
// Feb 16 2018 Test
// IDA Style Sig: 89 0D ? ? ? ? 8B 46 2C
PBYTE lcPattern = (PBYTE)"\x89\x0D\x00\x00\x00\x00\x8B\x46\x2C";
char lcMask[] = "xx????xxx";

// 55 8B EC 6A FF 68 ? ? ? ? 64 A1 ? ? ? ? 50 83 EC 34 53 56 A1 ? ? ? ? 33 C5 50 8D 45 F4 64 A3 ? ? ? ? 8B F1 33 DB C7 45 ? ? ? ? ? C7 45 ? ? ? ? ? 89 5D EC 89 5D E8 8D 45 E0 50 89 5D FC E8 ? ? ? ? 8D 4D F0 51 E8 ? ? ? ? 83 C4 08 8D 4D C0 E8 ? ? ? ? 8B 45 E4 8B 55 08 50 8D 4D D8 C6 45 FC 01 89 55 D4 E8 ? ? ? ? 8B 4D F0 8B 55 10 8B 45 0C 52 89 4D DC 50 8D 4D C0 51 8B CE E8 ? ? ? ? 8D 4D C0 8B F0 88 5D FC E8 ? ? ? ? C7 45 ? ? ? ? ? C7 45 ? ? ? ? ? 39 5D EC 7E 20 8B 45 E4 83 C0 FC 8B D0 83 C9 FF F0 0F C1 0A 49 85 C9 7F 0C 8B 55 E0 50 8B 42 08 8D 4D E0 FF D0 8B C6 8B 4D F4 64 89 0D ? ? ? ? 59 5E 5B 8B E5 5D C2 0C ?
//eqmain.dll start func
//55 8B EC 6A FF 68 ? ? ? ? 64 A1 ? ? ? ? 50 83 EC 34 53 56 A1
//Feb 16 2018 Test
//IDA Style Sig: 55 8B EC 6A FF 68 ? ? ? ? 64 A1 ? ? ? ? 50 83 EC 34 56
// 0x55 0x8B 0xEC 0x6A 0xFF 0x68 ? ? ? ? 0x64 0xA1 ? ? ? ? 0x50 0x83 0xEC 0x34 0x56
// 55 8B EC 6A FF 68 ?? ?? ?? ?? 64 A1 ?? ?? ?? ?? 50 83 EC 3C 56
PBYTE lcEGPattern = (PBYTE)"\x55\x8B\xEC\x6A\xFF\x68\x00\x00\x00\x00\x64\xA1\x00\x00\x00\x00\x50\x83\xEC\x3C\x56";
char lcEGMask[] = "xxxxxx????xx????xxxxx";


bool DecryptData(DATA_BLOB* DataIn, DATA_BLOB* DataOut)
{
	return CryptUnprotectData(DataIn, NULL, NULL, NULL, NULL, 0, DataOut) != 0;
}

int StrToBlobA(const char* szIn, DATA_BLOB* BlobOut)
{
	size_t len = strlen(szIn);
	BlobOut->pbData = (BYTE*)LocalAlloc(LPTR, (len)+1);
	char* szArg = new char[len + 1];
	strcpy_s(szArg, len + 1, szIn);
	BYTE CurByte = 0;
	DWORD out = 0;
	_strlwr_s(szArg, len + 1);

	for (int count = 0; szArg[count]; count += 2, out++)
	{
		if (((szArg[count] < '0' || szArg[count] > '9')
			&& (szArg[count] < 'a' || szArg[count] > 'f'))
			|| ((szArg[count + 1] < '0' || szArg[count + 1] > '9')
				&& (szArg[count + 1] < 'a' || szArg[count + 1] > 'f')))
			break;

		if (szArg[count] >= '0' && szArg[count] <= '9')
			CurByte = szArg[count] - 48;
		else if (szArg[count] >= 'a' && szArg[count] <= 'f')
			CurByte = szArg[count] - 87;

		CurByte <<= 4;

		if (szArg[count + 1] >= '0' && szArg[count + 1] <= '9')
			CurByte |= szArg[count + 1] - 48;
		else if (szArg[count + 1] >= 'a' && szArg[count + 1] <= 'f')
			CurByte |= szArg[count + 1] - 87;

		BlobOut->pbData[out] = CurByte;
	}
	BlobOut->cbData = out;
	BlobOut->pbData[out++] = '\0';
	delete[] szArg;
	return BlobOut->cbData;
}

char* gettok(char* _String, int _Delimiter)
{
	static char theString[MAX_STRING] = { 0 };
	static char* szString = theString;
	char* szToken = nullptr;
	char* szRet = nullptr;

	if (_String != nullptr)
	{
		strcpy_s(theString, _String);
		szString = theString;
	}
	if (szString)
	{
		if (szToken = strchr(szString, _Delimiter))
		{
			szToken[0] = '\0';
			szRet = szString;
			szString = ++szToken;
		}
		else {
			szRet = szString;
			szString = nullptr;
		}
		return szRet;
	}
	
	return nullptr;
}
template <
	unsigned int _SNSize,
	unsigned int _CNSize,
	unsigned int _PSize,
	unsigned int _HKSize,
	unsigned int _CCSize,
	unsigned int _CLSize>
bool ParseBlob(
	const std::string& blob,
	char(&szStationName)[_SNSize],
	char(&szCharacterName)[_CNSize],
	char(&szPassword)[_PSize],
	char(&szHotkey)[_HKSize],
	char(&szCharClass)[_CCSize],
	char(&szCharLevel)[_CLSize])
{
	if (blob.empty())
		return false;

	DATA_BLOB db = { 0 };
	if (!StrToBlobA(blob.c_str(), &db))
		return false;

	DATA_BLOB dbout = { 0 };
	BOOL success = DecryptData(&db, &dbout);
	LocalFree(db.pbData);

	if (!success)
		return false;

	if (!dbout.pbData)
	{
		LocalFree(dbout.pbData);
		return false;
	}

	int token = 0;
	char* pToken = gettok((char*)dbout.pbData, ':');
	while (pToken)
	{
		token++;
		switch (token)
		{
		case 1:
			strcpy_s(szStationName, pToken);
			break;
		case 2:
			strcpy_s(szCharacterName, pToken);
			break;
		case 3:
			strcpy_s(szPassword, pToken);
			break;
		case 4:
			strcpy_s(szHotkey, pToken);
			break;
		case 5:
			strcpy_s(szCharClass, pToken);
			break;
		case 6:
			strcpy_s(szCharLevel, pToken);
			break;
		}
		pToken = gettok(nullptr, ':');
	}

	LocalFree(dbout.pbData);
	return true;
}

class CLoginViewManager
{
public:
	int SendLMouseClick(CXPoint&);
};
FUNCTION_AT_VARIABLE_ADDRESS(int CLoginViewManager::SendLMouseClick(CXPoint&), dwSendLMouseClickAddr);

class LoginServerAPI
{
public:
	//see 100129F0 in eqmain.dll dated jul 13 2017 - eqmule
	unsigned int JoinServer(int serverID, void* userdata = 0, int timoutseconds = 10);
};
FUNCTION_AT_VARIABLE_ADDRESS(unsigned int LoginServerAPI::JoinServer(int, void*, int), dwEnterGameAddr);

template <unsigned int _Size, unsigned int _OutSize>
bool GetServerLongName(char(&szName)[_Size], char(&szOut)[_OutSize])
{
	if (GetPrivateProfileString("Servers", szName, 0, szOut, _OutSize, INIFileName))
	{
		if (szOut[0] != '\0')
			return true;
	}
	return false;
}

template <unsigned int _Size>
bool GetPassword(char(&szBuffer)[_Size])
{
	if (dwServerInfo)
	{
		if (SERVERSTUFF* serveridoff = *(SERVERSTUFF**)dwServerInfo)
		{
			strcpy_s(szBuffer, serveridoff->Password.c_str());
		}
	}

	return false;
}

template <unsigned int _Size>
bool GetServerName(char(&szBuffer)[_Size])
{
	if (EQADDR_SERVERNAME)
	{
		strcpy_s(szBuffer, _Size, EQADDR_SERVERNAME);
		if (szBuffer[0] != '\0')
		{
			return true;
		}
	}
	return false;
}

bool CheckServerUp(int ID)
{
	if (WindowMap.find("SERVERSELECT_ServerList") != WindowMap.end())
	{
		if (CListWnd* serverlist = (CListWnd*)WindowMap["SERVERSELECT_ServerList"])
		{
			if (serverlist->ItemsArray.Count && dwServerInfo)
			{
				if (SERVERSTUFF* serveridoff = *(SERVERSTUFF**)dwServerInfo)
				{
					if (serveridoff->pServerList && serveridoff->pServerList->Info)
					{
						SERVERLIST* pList = serveridoff->pServerList;
						while (pList)
						{
							if (pList->Info->ID == ID)
							{
								if (pList->Info->StatusFlags & SERVER_LOCKED || pList->Info->StatusFlags & SERVER_DOWN)
								{
									bWeAreDown = true;
									return false;
								}
								else {
									return true;
								}
							}
							pList = pList->Next;
						}
					}
				}
			}
		}
	}
	return false;
}

// todo fix this to do an actual select on the listitem
template <unsigned int _Size>
DWORD SelectServer(char(&szShortName)[_Size])
{
	if (GetGameState() != GAMESTATE_PRECHARSELECT)
	{
		bGotOffsets = false;
		return 0;
	}

	char szLongName[MAX_STRING] = { 0 };
	if (GetServerLongName(szShortName, szLongName))
	{
		if (WindowMap.find("SERVERSELECT_ServerList") != WindowMap.end())
		{
			if (CListWnd* serverlist = (CListWnd*)WindowMap["SERVERSELECT_ServerList"])
			{
				if (serverlist->ItemsArray.Count && dwServerInfo)
				{
					if (SERVERSTUFF* serveridoff = *(SERVERSTUFF**)dwServerInfo)
					{
						if (serveridoff->pServerList && serveridoff->pServerList->Info)
						{
							SERVERLIST* pList = serveridoff->pServerList;
							while (pList)
							{
								if (pList->Info)
								{
									if (!_stricmp(pList->Info->ServerName.c_str(), szLongName))
									{
										return pList->Info->ID;
									}
								}
								pList = pList->Next;
							}
						}
						else
						{
							bGotOffsets = false;
						}
					}
				}
			}
		}
	}
	return 0;
}

template <unsigned int _Size>
DWORD GetServerIDFromName(char(&szShortName)[_Size])
{
	if (GetGameState() != GAMESTATE_PRECHARSELECT)
	{
		bGotOffsets = false;
		return 0;
	}

	char szLongName[MAX_STRING] = { 0 };
	if (GetServerLongName(szShortName, szLongName))
	{
		if (WindowMap.find("SERVERSELECT_ServerList") != WindowMap.end())
		{
			if (CListWnd * serverlist = (CListWnd*)WindowMap["SERVERSELECT_ServerList"])
			{
				if (serverlist->ItemsArray.Count && dwServerInfo)
				{
					if (SERVERSTUFF* serveridoff = *(SERVERSTUFF**)dwServerInfo)
					{
						if (serveridoff->pServerList && serveridoff->pServerList->Info)
						{
							SERVERLIST* pList = serveridoff->pServerList;
							while (pList)
							{
								if (pList->Info)
								{
									if (!_stricmp(pList->Info->ServerName.c_str(), szLongName))
									{
										return pList->Info->ID;
									}
								}
								pList = pList->Next;
							}
						}
						else
						{
							bGotOffsets = false;
						}
					}
				}
			}
		}
	}

	return 0;
}

template <unsigned int _Size>
DWORD GetServerID(char(&szName)[_Size])
{
	for (DWORD n = 0; ServerData[n].ID; n++)
	{
		if (!_stricmp(szName, ServerData[n].Name))
		{
			return ServerData[n].ID;
		}
	}

	if (DWORD ID = GetServerIDFromName(szName))
	{
		return ID;
	}

	return 0;
}

void Cmd_SwitchServer(SPAWNINFO* pChar, char* szLine)
{
	char szServer[MAX_STRING] = { 0 };
	char szCharacter[MAX_STRING] = { 0 };
	char szLongName[MAX_STRING] = { 0 };

	GetArg(szServer, szLine, 1);
	GetArg(szCharacter, szLine, 2);

	if (szServer[0] && szCharacter[0])
	{
		bool oktomoveon = false;
		if (GetServerID(szServer))
			oktomoveon = true;
		else if (GetServerLongName(szServer, szLongName))
			oktomoveon = true;
		if (oktomoveon) {
			dwServerID = -1;
			strcpy_s(szServerName, szServer);
			strcpy_s(szCharacterName, szCharacter);
			bSwitchServer = true;

			if (pChar->StandState == STANDSTATE_FEIGN)
			{
				// using DoMappable here doesn't create enough of a delay for camp to work
				EzCommand("/stand");
			}
			EzCommand("/camp");
			bInGame = false;
			bInjectorUpdate = true;
			WriteChatf("Switching to \ag%s\ax on server \ag%s\ax", szCharacterName, szServer);
			return;
		}
		else
		{
			char szServers[MAX_STRING] = { 0 };

			WriteChatf("Invalid server name \ag%s\ax.  Valid server names are:", szServer);

			for (DWORD n = 0; ServerData[n].ID; n++)
			{
				if (n)
					strcat_s(szServers, ", ");
				strcat_s(szServers, ServerData[n].Name);
			}
			strcat_s(szServers, " as well as any server you have defined in your mq2autologin.ini under the [Servers] section.");
			WriteChatColor(szServers);
			return;
		}
	}

	WriteChatf("\ayUsage:\ax /switchserver <server short name> <character name>");
}

void Cmd_SwitchCharacter(SPAWNINFO* pChar, char* szLine)
{
	char szArg1[MAX_STRING] = { 0 };

	if (szLine[0])
	{
		GetArg(szArg1, szLine, 1);
		if (GetGameState() == GAMESTATE_INGAME)
		{
			if (_stricmp(szArg1, pChar->DisplayedName))
			{
				strcpy_s(szNewChar, szArg1);

				if (pChar->StandState == STANDSTATE_FEIGN)
				{
					// using DoMappable here doesn't create enough of a delay for camp to work
					EzCommand("/stand");
				}
				EzCommand("/camp");
				bSwitchChar = true;
				bInjectorUpdate = true;
				WriteChatf("Switch to \ag%s\ax is now active and will commence at character select.", szNewChar);
			}
			else
			{
				WriteChatf("\ayYou're already logged onto '%s'\ax", szArg1);
			}
		}
		else if (GetGameState() == GAMESTATE_CHARSELECT)
		{
			strcpy_s(szNewChar, szArg1);
			bSwitchChar = true;
		}
	}
	else
	{
		WriteChatf("\ayUsage:\ax /switchchar <name>");
	}
}

void Cmd_Relog(PSPAWNINFO pChar, char* szLine)
{
	if (GetGameState() == GAMESTATE_INGAME)
	{
		if (!szLine[0])
		{
			WriteChatf("\ayUsage:\ax /relog [#s|#m]");
			WriteChatf("Example: /relog 30m (logs character out for 30 minutes then logs back in)");
			return;
		}

		DWORD n = atol(szLine);

		switch (szLine[strlen(szLine) - 1])
		{
		case 's':
		case 'S':
			n *= 1000;
			break;
		case 'm':
		case 'M':
			n *= 60000;
			break;
		default:
			n *= 1000;
			break;
		}

		if (n)
			dwTime = MQGetTickCount64() + n;

		strcpy_s(szNewChar, pChar->DisplayedName);

		if (dwTime)
			dwTime += 30000; // add 30 seconds for camp time

		if (pChar->StandState == STANDSTATE_FEIGN)
		{
			// using DoMappable here doesn't create enough of a delay for camp to work
			EzCommand("/stand");
		}
		EzCommand("/camp");
		bInGame = false;
		bInjectorUpdate = true;
	}
}

bool GetAllOffsets(DWORD dweqmain)
{
	if (!dweqmain)
		return false;
	if (dwLoginClient = _FindPattern(dweqmain, 0x100000, lcPattern, lcMask))
	{
		dwLoginClient = _GetDWordAt(dwLoginClient, 2);
	}
	else
	{
		AutoLoginDebug("Error: !dwLoginClient");
		return false;
	}

	if (!(dwEnterGameAddr = _FindPattern(dweqmain, 0x200000, lcEGPattern, lcEGMask)))
	{
		AutoLoginDebug("Error: !dwEnterGame");
		return false;
	}

	DWORD dwSidlMgr = 0, dwWndMgr = 0, dwLoginMgr = 0;

	if (!(dwGetXMLDataAddr = _FindPattern(dweqmain, 0x100000, xmldataPattern, xmldataMask)))
	{
		AutoLoginDebug("Error: !dwGetXMLDataAddr");
		return false;
	}

	if (!(dwSendLMouseClickAddr = _FindPattern(dweqmain, 0x100000, lmousePattern, lmouseMask)))
	{
		AutoLoginDebug("Error: !dwSendLMouseClickAddr");
		return false;
	}

	if (dwSidlMgr = _FindPattern(dweqmain, 0x100000, swmPattern, swmMask))
	{
		dwSidlMgr = _GetDWordAt(dwSidlMgr, 2);
	}
	else
	{
		AutoLoginDebug("Error: !dwSidlMgr");
		return false;
	}

	if (dwWndMgr = _FindPattern(dweqmain, 0x200000, xwmPattern, xwmMask))
	{
		dwWndMgr = _GetDWordAt(dwWndMgr, 1);
	}
	else
	{
		AutoLoginDebug("Error: !dwWndMgr");
		return false;
	}

	if (dwLoginMgr = _FindPattern(dweqmain, 0x200000, lvmPattern, lvmMask))
	{
		dwLoginMgr = _GetDWordAt(dwLoginMgr, 1);
		dwServerInfo = dwLoginMgr - 4;
	}
	else
	{
		AutoLoginDebug("Error: !dwLoginMgr");
		return false;
	}

	pSidlManager = nullptr;
	pWindowManager = nullptr;
	pLoginViewManager = nullptr;

	while (!pSidlManager || !pWindowManager || !pLoginViewManager)
	{
		pSidlManager = (CSidlManager*)*(DWORD*)dwSidlMgr;
		pWindowManager = (CXWndManager*)*(DWORD*)dwWndMgr;
		pLoginViewManager = (CLoginViewManager*)*(DWORD*)dwLoginMgr;
	}

	WindowMap.clear();
	char Name[MAX_STRING] = { 0 };

	CXMLDataManager* xmlDataManager = pSidlManager->GetParamManager();

	for (int i = 0; i < pWindowManager->pWindows.Count; i++)
	{
		if (CXWnd* pWnd = pWindowManager->pWindows[i])
		{
			if (CXMLData* pXMLData = pWnd->GetXMLData(xmlDataManager))
			{
				if (!pXMLData->Name.empty())
				{
					AutoLoginDebug("bLogin loop: adding window '%s'", pXMLData->Name.c_str());
					WindowMap[pXMLData->Name.c_str()] = pWnd;
				}
			}
		}
	}

	bGotOffsets = true;
	return true;
}

void LoginPulse()
{
	if (ullerrorwait)
	{
		if (ullerrorwait > MQGetTickCount64())
		{
			Sleep(0);
			return;
		}
		else
		{
			ullerrorwait = 0;
		}
	}

	if (GetAsyncKeyState(VK_END) & 1)
	{
		bEnd = true;
		return;
	}

	if (GetAsyncKeyState(VK_HOME) & 1)
	{
		bLogin = true;
		bEnd = false;
		return;
	}
	if (!bGotOffsets) {
		GetAllOffsets(dwEQMainBase);
	}
	else {
		if (!bEnd)
			HandleWindows();
	}
}

void AddOurPulse()
{
	if (*(DWORD*)__heqmain)
	{
		bEnd = false;
		if (dwEQMainBase = *(DWORD*)__heqmain)
		{
			if (LoginController__GiveTime)
			{
				bGotOffsets = false;
			}
		}

		if (!bInGame && !bSwitchServer && !dwTime)
		{
			if (bUseMQ2Login)
			{
				// then we don't need anything else
			}
			else if (!bUseStationNamesInsteadOfSessions)
			{
				DWORD nProcs = GetProcessCount("eqgame.exe");
				char szSession[32] = { 0 };
				sprintf_s(szSession, "Session%d", nProcs);
				AutoLoginDebug(szSession);

				GetPrivateProfileString(szSession, "StationName", 0, szStationName, 64, INIFileName);
				GetPrivateProfileString(szSession, "Password", 0, szPassword, 64, INIFileName);
				GetPrivateProfileString(szSession, "Server", 0, szServerName, 32, INIFileName);
				GetPrivateProfileString(szSession, "Character", 0, szCharacterName, 64, INIFileName);
                GetPrivateProfileString(szSession, "SelectCharacter", 0, szSelectCharacterName, 64, INIFileName);
			}
		}
	}
}

// custom ini support
DWORD_PTR gppi = 0;
DWORD_PTR gpps = 0;
DWORD_PTR wpps = 0;

DWORD WINAPI GetPrivateProfileStringA_Tramp(LPCSTR, LPCSTR, LPCSTR, LPSTR, DWORD, LPCSTR);

void SetupCustomIni()
{
	if (szCustomIni && szCustomIni[0] != '\0')
		return;

	if (char* pLogin = GetLoginName())
	{
		strcpy_s(szStationName, pLogin);
		if (gpps)
		{
			GetPrivateProfileStringA_Tramp(szStationName, "CustomClientIni", 0, szCustomIni, 64, INIFileName);
		}
		else
		{
			GetPrivateProfileString(szStationName, "CustomClientIni", 0, szCustomIni, 64, INIFileName);
		}
	}
}

DWORD WINAPI GetPrivateProfileStringA_Detour(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpDefault, LPSTR lpReturnedString, DWORD nSize, LPCSTR lpFileName)
{
	if (lpFileName)
	{
		SetupCustomIni();
		char szPath[MAX_STRING] = { 0 };
		strcpy_s(szPath, lpFileName);
		_strlwr_s(szPath);

		if (szCustomIni && szCustomIni[0] != '\0' && strstr(szPath, "eqclient.ini"))
		{
			strcpy_s(szPath, ".\\");
			strcat_s(szPath, szCustomIni);
			return GetPrivateProfileStringA_Tramp(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, szPath);
		}
	}

	return GetPrivateProfileStringA_Tramp(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName);
}
DETOUR_TRAMPOLINE_EMPTY(DWORD WINAPI GetPrivateProfileStringA_Tramp(LPCSTR, LPCSTR, LPCSTR, LPSTR, DWORD, LPCSTR));

BOOL WINAPI WritePrivateProfileStringA_Tramp(LPCSTR, LPCSTR, LPCSTR, LPCSTR);
BOOL WINAPI WritePrivateProfileStringA_Detour(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpString, LPCSTR lpFileName)
{
	if (lpFileName)
	{
		SetupCustomIni();
		char szPath[MAX_STRING] = { 0 };
		strcpy_s(szPath, lpFileName);
		_strlwr_s(szPath);

		if (szCustomIni && szCustomIni[0] != '\0' && strstr(szPath, "eqclient.ini"))
		{
			strcpy_s(szPath, ".\\");
			strcat_s(szPath, szCustomIni);
			return WritePrivateProfileStringA_Tramp(lpAppName, lpKeyName, lpString, szPath);
		}
	}

	return WritePrivateProfileStringA_Tramp(lpAppName, lpKeyName, lpString, lpFileName);
}
DETOUR_TRAMPOLINE_EMPTY(BOOL WINAPI WritePrivateProfileStringA_Tramp(LPCSTR, LPCSTR, LPCSTR, LPCSTR));

UINT WINAPI GetPrivateProfileIntA_Tramp(LPCSTR, LPCSTR, INT, LPCSTR);
UINT WINAPI GetPrivateProfileIntA_Detour(LPCSTR lpAppName, LPCSTR lpKeyName, INT nDefault, LPCSTR lpFileName)
{
	if (lpFileName)
	{
		SetupCustomIni();
		char szPath[MAX_STRING] = { 0 };
		strcpy_s(szPath, lpFileName);
		_strlwr_s(szPath);
		if (szCustomIni && szCustomIni[0] != '\0' && strstr(szPath, "eqclient.ini"))
		{
			strcpy_s(szPath, ".\\");
			strcat_s(szPath, szCustomIni);
			return GetPrivateProfileIntA_Tramp(lpAppName, lpKeyName, nDefault, szPath);
		}
	}

	return GetPrivateProfileIntA_Tramp(lpAppName, lpKeyName, nDefault, lpFileName);
}
DETOUR_TRAMPOLINE_EMPTY(UINT WINAPI GetPrivateProfileIntA_Tramp(LPCSTR, LPCSTR, INT, LPCSTR));

PLUGIN_API void InitializePlugin()
{
	//MessageBox(NULL, "Inject now", "MQ2 Debug", MB_OK|MB_SYSTEMMODAL);
	int sizeofSPAWNINFO = sizeof(SPAWNINFO);
	int sizeofCXWnd = sizeof(CXWnd);
	int sizeofCONTENTS = sizeof(CONTENTS);

	char szPath[MAX_PATH] = { 0 };
	GetPrivateProfileStringA("Settings", "IniLocation", 0, szPath, MAX_PATH, INIFileName);
	if (szPath[0])
		strcpy_s(INIFileName, szPath);
	bNotifyOnServerUP = GetPrivateProfileInt("Settings", "NotifyOnServerUP", -1, INIFileName);
	if (bNotifyOnServerUP == -1)
	{
		WritePrivateProfileString("Settings", "NotifyOnServerUP", "0", INIFileName);
		bNotifyOnServerUP = 0;
	}
	bKickActiveChar = GetPrivateProfileInt("Settings", "KickActiveCharacter", 1, INIFileName);
	bUseMQ2Login = GetPrivateProfileInt("Settings", "UseMQ2Login", 0, INIFileName);
	bUseStationNamesInsteadOfSessions = GetPrivateProfileInt("Settings", "UseStationNamesInsteadOfSessions", 0, INIFileName);
	bReLoggin = GetPrivateProfileInt("Settings", "LoginOnReLoadAtCharSelect", 0, INIFileName);
	bool bUseCustomClientIni = GetPrivateProfileInt("Settings", "EnableCustomClientIni", 0, INIFileName) == 1;
	bEndAfterCharSelect = GetPrivateProfileInt("Settings", "EndAfterCharSelect", 0, INIFileName) == 1;

	// is eqmain.dll loaded
	if (GetModuleHandle("eqmain.dll"))
	{
		// well well well... what do u know... it's loaded...
		// ok fine that means we wont get any frontload notification, so lets fake it
		AddOurPulse();
	}

	AddCommand("/switchserver", Cmd_SwitchServer);
	AddCommand("/switchcharacter", Cmd_SwitchCharacter);
	AddCommand("/relog", Cmd_Relog);

	if (bUseCustomClientIni)
	{
		if (bUseStationNamesInsteadOfSessions && !bUseMQ2Login)
		{
			SetupCustomIni();
		}
		if (gppi = (DWORD_PTR)GetProcAddress(GetModuleHandle("kernel32.dll"), "GetPrivateProfileIntA"))
		{
			EzDetourwName(gppi, GetPrivateProfileIntA_Detour, GetPrivateProfileIntA_Tramp, "GetPrivateProfileIntA_Detour");
		}
		if (gpps = (DWORD_PTR)GetProcAddress(GetModuleHandle("kernel32.dll"), "GetPrivateProfileStringA"))
		{
			EzDetourwName(gpps, GetPrivateProfileStringA_Detour, GetPrivateProfileStringA_Tramp, "GetPrivateProfileStringA_Detour");
		}
		if (wpps = (DWORD_PTR)GetProcAddress(GetModuleHandle("kernel32.dll"), "WritePrivateProfileStringA"))
		{
			EzDetourwName(wpps, WritePrivateProfileStringA_Detour, WritePrivateProfileStringA_Tramp, "WritePrivateProfileStringA_Detour");
		}
	}

#ifdef AUTOLOGIN_DBG
	remove(DBG_LOGFILE_PATH);
#endif

	// force a check if user loads us at charselect for example...
	if (GetGameState() == GAMESTATE_CHARSELECT && bReLoggin)
	{
		DWORD nProcs = GetProcessCount("eqgame.exe");
		if (bUseMQ2Login)
		{
			// i dont think we need to load anything here
		}
		else if (!bUseStationNamesInsteadOfSessions)
		{
			char szSession[32] = { 0 };
			sprintf_s(szSession, "Session%d", nProcs);
			AutoLoginDebug(szSession);
			GetPrivateProfileString(szSession, "StationName", 0, szStationName, 64, INIFileName);
			GetPrivateProfileString(szSession, "Password", 0, szPassword, 64, INIFileName);
			GetPrivateProfileString(szSession, "Server", 0, szServerName, 32, INIFileName);
			GetPrivateProfileString(szSession, "Character", 0, szCharacterName, 64, INIFileName);
			GetPrivateProfileString(szSession, "SelectCharacter", 0, szSelectCharacterName, 64, INIFileName);
		}
		else
		{
			if (char* pLogin = GetLoginName())
			{
				strcpy_s(szStationName, pLogin);
				GetPrivateProfileString(szStationName, "Password", 0, szPassword, 64, INIFileName);
				GetPrivateProfileString(szStationName, "Server", 0, szServerName, 32, INIFileName);
				GetPrivateProfileString(szStationName, "Character", 0, szCharacterName, 64, INIFileName);
				GetPrivateProfileString(szStationName, "SelectCharacter", 0, szSelectCharacterName, 64, INIFileName);
			}
		}

		if (!dwServerID || dwServerID == -1 && EQADDR_SERVERNAME[0])
		{
			char szServTemp[MAX_STRING] = { 0 };
			strcpy_s(szServTemp, EQADDR_SERVERNAME);
			DWORD lserver = 0;
			dwServerID = GetServerID(szServTemp);
			if (szServerName[0])
			{
				lserver = GetServerID(szServerName);
			}
			if (lserver != dwServerID)
			{
				dwServerID = lserver;
				bSwitchServer = true;
			}
			if (szCharacterName[0] == '\0' && pCharSpawn && ((SPAWNINFO*)pCharSpawn)->Name[0]) {
				strcpy_s(szCharacterName, ((SPAWNINFO*)pCharSpawn)->Name);
			}
		}
	}
}

PLUGIN_API void ShutdownPlugin()
{
	RemoveCommand("/switchserver");
	RemoveCommand("/switchcharacter");
	RemoveCommand("/relog");

	if (gppi)
		RemoveDetour(gppi);
	if (gpps)
		RemoveDetour(gpps);
	if (wpps)
		RemoveDetour(wpps);
	LoginReset();
}

void RemovePulse()
{
	if (dwEQMainBase)
		dwEQMainBase = 0;
	if (bGotOffsets)
		bGotOffsets = false;
}

PLUGIN_API void SetGameState(DWORD GameState)
{
	bEndAfterCharSelect = GetPrivateProfileInt("Settings", "EndAfterCharSelect", 0, INIFileName) == 1;

	if (GameState == GAMESTATE_PRECHARSELECT)
	{
		if (GetModuleHandle("eqmain.dll"))
		{
			// well well well... what do u know... it's loaded...
			// ok fine that means we wont get any frontload notification, so lets fake it
			if (!LoginController__GiveTime)
				AddOurPulse();
		}
	}
	else if (GameState == GAMESTATE_POSTFRONTLOAD)
	{
		// we know eqmain.dll is loaded now...
		if (!LoginController__GiveTime)
			AddOurPulse();
	}
	else if (GameState == GAMESTATE_CHARSELECT)
	{
		RemovePulse();

		if (dwServerID)
		{
			dwServerID = 0;
			if (!bSwitchChar)
			{
				strcpy_s(szNewChar, szCharacterName);
				bSwitchChar = true;
			}
		}
	}
	else if (GameState == GAMESTATE_INGAME)
	{
		bInGame = true;
	}
}

template <unsigned int _Size>
bool CurrentCharacter(char(&szBuffer)[_Size])
{
	if (CXWnd* pWnd = FindMQ2Window("CLW_CharactersScreen"))
	{
		if (CListWnd* charlist = (CListWnd*)pWnd->GetChildItem("Character_List"))
		{
			if (charlist->ItemsArray.Count)
			{
				CXStr str = charlist->GetItemText(charlist->CurSel, 2);

				if (!str.empty())
				{
					strcpy_s(szBuffer, str.c_str());
				}
			}
		}
	}
	return false;
}

int BugTimer = 0;
int retrylogincounter = 0;

PLUGIN_API void OnPulse()
{
	// since in game pulse starts at charselect we can use that for charswitching and serverswithcing as well as relog...
	if (!bLogin && GetAsyncKeyState(VK_HOME) & 1)
	{
		WriteChatf("\agHOME key pressed. AutoLogin Re-Enabled.", szNewChar);
		bEndAfterCharSelect = false;
		bLogin = true;
		return;
	}

	if (GetGameState() == GAMESTATE_INGAME)
	{
		if (retrylogincounter)
			retrylogincounter = 0;
	}

	else if (GetGameState() == GAMESTATE_CHARSELECT)
	{
		// fix for the stuck at char select "Loading Characters" bug.
		BugTimer++;
		if (BugTimer > 100 && retrylogincounter == 0)
		{
			BugTimer = 0;

			if (CSidlScreenWnd* pWnd = (CSidlScreenWnd*)FindMQ2Window("ConfirmationDialogBox"))
			{
				if (pWnd->IsVisible() == 1)
				{
					if (CStmlWnd* Child = (CStmlWnd*)pWnd->GetChildItem("cd_textoutput"))
					{
						if (strstr(Child->STMLText.c_str(), "Loading Characters"))
						{
							// TODO: FIXME
							if (CCharacterListWnd* pCharSelect = *(CCharacterListWnd**)pinstCCharacterListWnd)
							{
								retrylogincounter = 1;
								bLogin = true;
								if (szServerName && szServerName[0] == '\0')
								{
									GetServerName(szServerName);
								}
								if (szNewChar && szNewChar[0] == '\0')
								{
									CurrentCharacter(szNewChar);
								}
								switchTime = MQGetTickCount64() + 3000;

								pCharSelect->Quit();
								AutoLoginDebug("Quit() called due to charselect list being empty");
							}
						}
					}
				}
			}
		}

		if (dwTime && szNewChar[0] && GetAsyncKeyState(VK_END) & 1)
		{
			WriteChatf("END key pressed. Login of %s aborted.", szNewChar);
			szNewChar[0] = 0;
			dwTime = 0;
			switchTime = 0;
			return;
		}

		if (bSwitchServer)
		{
			// world -> char select
			AutoLoginDebug("SetGameState(GAMESTATE_CHARSELECT): bSwitchServer = true");
			DWORD pCharSelect = *(DWORD*)pinstCCharacterListWnd;
			((CCharacterListWnd*)pCharSelect)->Quit();
			if (bInjectorUpdate)
			{
				IC_LoaderClearLoaded(szProfile, szStationName, szServerName, szCharacterName, GetCurrentProcessId());
			}
			bInjectorUpdate = false;
			return;
		}

		if (bSwitchChar)
		{
			// we have to give the chatwindow time to show up at char select... so we wait a couple seconds...
			switchTime = MQGetTickCount64() + 2000;
			bSwitchChar = false;
			if (bInjectorUpdate)
			{
				IC_LoaderClearLoaded(szProfile, szStationName, szServerName, szCharacterName, GetCurrentProcessId());
			}
			bInjectorUpdate = false;
			return;
		}

		if (switchTime && switchTime <= MQGetTickCount64() && szNewChar[0] != '\0')
		{
			// at this point the user has 3 seconds to read the message and abort.
			WriteChatf("Selecting \ag%s\ax in 3 seconds. please Wait... or press the END key to abort", szNewChar);
			switchTime = 0;
			dwTime = MQGetTickCount64() + 3000;
			SelectCharacter(szNewChar);
			IC_LoaderSetLoaded(szProfile, szStationName, szServerName, szNewChar, GetCurrentProcessId());
			return;
		}

		if (switchTime && switchTime <= MQGetTickCount64() && szSelectCharacterName[0] != '\0')
		{
			// at this point the user has 3 seconds to read the message and abort.
			WriteChatf("Selecting \ag%s\ax in 3 seconds. please Wait... or press the END key to abort", szSelectCharacterName);
			switchTime = 0;
			SelectCharacter(szSelectCharacterName);
			IC_LoaderSetLoaded(szProfile, szStationName, szServerName, szCharacterName, GetCurrentProcessId());
			return;
		}

		if (szNewChar[0] != '\0' && dwTime && dwTime <= MQGetTickCount64())
		{
			SwitchCharacter(szNewChar);
			szNewChar[0] = 0;
			dwTime = 0;
		}

		if (!szNewChar || szNewChar[0] == '\0' && bEndAfterCharSelect && bLogin)
		{
			bLogin = false;
			WriteChatf("\ayAutologin now ended... press HOME to Re-Enable.", szNewChar);
		}
	}
	else if (GetGameState() == GAMESTATE_PRECHARSELECT)
	{
		dwEQMainBase = *(DWORD*)__heqmain;
		LoginPulse();
	}
}

void SwitchCharacter(char* szName)
{
	if (szName && szName[0] != '\0')
	{
		if (CXWnd*pWnd = FindMQ2Window("CLW_CharactersScreen"))
		{
			if (CListWnd * charlist = (CListWnd*)pWnd->GetChildItem("Character_List"))
			{
				if (charlist->ItemsArray.Count)
				{
					for (int i = 0; i < charlist->ItemsArray.Count; i++)
					{
						CXStr Str = charlist->GetItemText(i, 2);
						if (!_stricmp(Str.c_str(), szName))
						{
							DWORD pCharSelect = *(DWORD*)pinstCCharacterListWnd;
							((CCharacterListWnd*)pCharSelect)->SelectCharacter(i);
							((CCharacterListWnd*)pCharSelect)->EnterWorld();

							if (bEndAfterCharSelect)
							{
								bLogin = false;
							}

							return;
						}
					}
				}
			}
		}
	}
	else
	{
		AutoLoginDebug("SwitchCharacter failed");
		WriteChatf("\arUsage\ax /switchcharacter \ay<name>\ax");
	}
}

void SelectCharacter(char* szName)
{
	if (szName && szName[0] != '\0')
	{
		if (CXWnd* pWnd = FindMQ2Window("CLW_CharactersScreen"))
		{
			if (CListWnd* charlist = (CListWnd*)pWnd->GetChildItem("Character_List"))
			{
				if (charlist->ItemsArray.Count)
				{
					char szOut[MAX_STRING] = { 0 };
					for (int i = 0; i < charlist->ItemsArray.Count; i++)
					{
						CXStr Str = charlist->GetItemText(i, 2);
						if (!_stricmp(szName, Str.c_str()))
						{
							DWORD pCharSelect = *(DWORD*)pinstCCharacterListWnd;
							((CCharacterListWnd*)pCharSelect)->SelectCharacter(i);
							return;
						}
					}
				}
			}
		}
	}
	else
	{
		AutoLoginDebug("SwitchCharacter failed");
		WriteChatf("\arUsage\ax /switchcharacter \ay<name>\ax");
	}
}

inline bool WindowActive(char* name)
{
	if (dwEQMainBase)
	{
		if (WindowMap.find(name) != WindowMap.end())
		{
			if (CXWnd* pWnd = WindowMap[name])
			{
				if (pWnd->IsVisible() && pWnd->IsEnabled())
				{
					return true;
				}
			}
		}
	}
	return false;
}

struct HOST
{
	CXStr* Name;
	int Port;
};

struct EQDEVICE
{
	char Name[0x40];
};

struct EQLOGIN
{
	EQDEVICE  Devices[0x10];
	int       NumDevices;
	HWND      hEQWnd;
	int       ReturnCode; // -1 = failed login
    char      Login[0x80];
	char      PW[0x80];
	char      PW2[0x80];
	char      ServerLong[0x80];
	int       ServerPort;
	char      AccountKey[0x80];
	int       ActiveDeviceIndex;
	char      LastZoneEntered[0x20];
	char      StationName[0x20];
	char      ExeName[0x20];
	char      CommandLine[0x1c0];
	char      ServerShort[0x80];
	char      Session[0x40];
	char      Character[0x40];
	// more below I don't need atm
};

// work in progress to get short servername... -eqmule
class LoginClient// : public A_Callback?, public ChannelServerHandler?
{
public:
	void*     A_Callback_vfTable;
	void*     ChannelServerHandler_vfTable;
	EQLOGIN*  pLoginData;
	DoublyLinkedList<HOST*> Hosts;
	HOST*     pHost;
	bool      bRetryConnect;
	// more below don't need right now
};

bool bWait = false;
bool bServerWait = false;

void HandleWindows()
{
	CXMLDataManager* pXmlMgr = pSidlManager->GetParamManager();

	if (!bLogin)
	{
		// we have to check this even when bLogin is false because we could be stuck at charselect in a timeout...
		if (WindowActive("serverselect"))
		{
			if (WindowActive("okdialog"))
			{
				if (CXWnd* pWnd = WindowMap["okdialog"]->GetChildItem(pXmlMgr, "OK_Display"))
				{
					CXStr str;

					if (pXmlMgr->GetWindowType(pWnd) == UI_STMLBox)
					{
						CStmlWnd* cstm = (CStmlWnd*)pWnd;
						str = cstm->STMLText;
					}
					else
					{
						CSidlScreenWnd* cwnd = (CSidlScreenWnd*)pWnd;
						str = cwnd->GetWindowText();
					}

					if (strstr(str.c_str(), "A timeout occurred"))
					{
						bLogin = true;
					}
				}
			}
		}

		return;
	}

	// pair of WindowNames / ButtonNames
	std::vector<std::pair<const char*, const char*>> PromptWindows = {
		{ "OrderWindow", "Order_DeclineButton" },
		{ "EulaWindow", "EULA_AcceptButton" },
		{ "seizurewarning", "HELP_OKButton"},
		{ "OrderExpansionWindow", "OrderExp_DeclineButton" }
	};

	for (const auto [windowName, buttonName] : PromptWindows)
	{
		auto iter = WindowMap.find(windowName);
		if (iter != WindowMap.end())
		{
			CXWnd* pWindow = iter->second;
			if (pWindow->IsVisible() && pWindow->IsEnabled())
			{
				if (CXWnd* pButton = pWindow->GetChildItem(pXmlMgr, buttonName))
				{
					pButton->WndNotification(pButton, XWM_LCLICK);
				}

				return;
			}
		}
	}

	if (WindowActive("dbgsplash"))
	{
		CXPoint pt{ 1, 1 };
		pLoginViewManager->SendLMouseClick(pt); // WndNotification doesn't work on this

		return;
	}

	if (WindowActive("main"))
	{
		if (CXWnd* pWnd = WindowMap["main"]->GetChildItem(pXmlMgr, "MAIN_ConnectButton"))
		{
			// this clicks the Login Button on the main page so we get the username and password page
			pWnd->WndNotification(pWnd, XWM_LCLICK);
		}

		return;
	}

	if (WindowActive("connect"))
	{
		if (WindowActive("okdialog"))
		{
			bServerWait = false;
			if (CXWnd* pWnd = WindowMap["okdialog"]->GetChildItem(pXmlMgr, "OK_Display"))
			{
				CXStr str;

				if (pXmlMgr->GetWindowType(pWnd) == UI_STMLBox)
				{
					CStmlWnd* pStmlWnd = (CStmlWnd*)pWnd;
					str = pStmlWnd->STMLText;
				}
				else
				{
					str = pWnd->GetWindowText();
				}

				if (strstr(str.c_str(), "Logging in to the server.  Please wait...."))
				{
					return;
				}

				bGotOffsets = false;
				ullerrorwait = MQGetTickCount64() + 2000; // we give the server 5 seconds to catch its breath...

				std::vector<const char*> ErrorMessages = {
					"The server requires that you logout and log back in before proceeding.  Please do so.",
					"failed login attempts on your account since the last time you logged in",
					"The Login Server is currently unavailable.  Please try again later.",
					"Cannot login to the EverQuest server",
					"This login requires a valid",
					"A timeout occurred",
					"A connection to the server could not be reached.",
					"An unknown login error occurred",
					"Invalid Session"
				};

				for (const char* msg : ErrorMessages)
				{
					if (strstr(str.c_str(), msg))
					{
						if (CXWnd* pButton = WindowMap["okdialog"]->GetChildItem(pXmlMgr, "OK_OKButton"))
							pButton->WndNotification(pButton, XWM_LCLICK);

						return;
					}
				}

				if (strstr(str.c_str(), "password were not valid")
					|| strstr(str.c_str(), "This login requires that the account be activated.  Please make sure your account is active in order to login."))
				{
					AutoLoginDebug("%s",str.c_str());
					bLogin = false;
					return;
				}

				if (strstr(str.c_str(), "You have a character logged into a world server as an OFFLINE TRADER from this account"))
				{
					if (CXWnd* pButton = WindowMap["okdialog"]->GetChildItem(pXmlMgr, "YESNO_YesButton"))
						pButton->WndNotification(pWnd, XWM_LCLICK);

					return;
				}
			}
			return;
		}

		if (CEditWnd* pEditWnd = (CEditWnd*)WindowMap["connect"]->GetChildItem(pXmlMgr, "LOGIN_PasswordEdit"))
		{
			if (pEditWnd->InputText.empty())
				bWait = false;
		}

		if (bWait)
			return;

		if (CEditWnd* pEditWnd = (CEditWnd*)WindowMap["connect"]->GetChildItem(pXmlMgr, "LOGIN_UsernameEdit"))
		{
			if (bUseMQ2Login)
			{
				AutoLoginDebug("HandleWindows(): Using MQ2Login Method");
				strcpy_s(szUserName, pEditWnd->InputText.c_str());

				if (szUserName[0])
				{
					strcpy_s(szProfile, szUserName);
					AutoLoginDebug("HandleWindows() szUserName(%s)", szUserName);

					if (char* pDest = strchr(szProfile, '_'))
					{
						// we have a mq2login user... good boy/girl :) welcome to 2016.
						pDest[0] = '\0';
						pDest++;
						sprintf_s(szBlobKey, "%s_Blob", pDest);
						strcpy_s(szCharacterName, szBlobKey);
						AutoLoginDebug("HandleWindows() szProfile(%s), szCharacterName(%s)", szProfile, szCharacterName);

						if (char* pDest2 = strchr(szCharacterName, ':'))
						{
							pDest2[0] = '\0';
							strcpy_s(szServerName, szCharacterName);
						}
						else
						{
							strcpy_s(szServerName, szUserName);
						}

						AutoLoginDebug("HandleWindows() szProfile(%s), szBlobKey(%s), szServerName(%s)", szProfile, szBlobKey, szServerName);

						// now that we have the server and the charname, we can figure out the stationname and password from the blob
						char szBlob[MAX_STRING] = { 0 };
						if (GetPrivateProfileString(szProfile, szBlobKey, "", szBlob, sizeof(szBlob), INIFileName))
						{
							if (pDest = strrchr(szBlob, '='))
							{
								pDest[0] = '\0';
							}
							AutoLoginDebug("HandleWindows() szBlob(%s)", szBlob);
							if (ParseBlob(szBlob, szStationName, szCharacterName, szPassword, szHotkey, szCharClass, szCharLevel)) {
								IC_LoaderSetLoaded(szProfile, szStationName, szServerName, szCharacterName, GetCurrentProcessId());
							}
						}

						DWORD oldscreenmode = std::exchange(ScreenMode, 3);
						ScreenMode = 3;

						pEditWnd->InputText.clear(); // ???
						pEditWnd->InputText = szStationName;

						ScreenMode = oldscreenmode;
					}
					else if (char* pDest = strchr(szUserName, '^')) // special login no profile just straight plaintext login...
					{
						// server^stationname^charname^pass
						// if charname is empty we just stop at charselect.

						if (char* cmdline = GetCommandLineA())
						{
							int cmdlinelen = strlen(cmdline);
							if (char* ploginDest = strstr(cmdline, "/login:"))
							{
								ploginDest += 7;
								strcpy_s(szUserName, ploginDest);
								pDest = strchr(szUserName, '^');
							}
						}

						pDest[0] = '\0';
						pDest++;
						strcpy_s(szServerName, szUserName);
						strcpy_s(szStationName, pDest);

						if (char* pDest = strchr(szStationName, '^'))
						{
							pDest[0] = '\0';
							pDest++;
							strcpy_s(szCharacterName, pDest);
						}

						if (char* pDest = strchr(szCharacterName, '^'))
						{
							pDest[0] = '\0';
							pDest++;
							strcpy_s(szPassword, pDest);
						}
						else
						{
							strcpy_s(szPassword, szCharacterName);
							szCharacterName[0] = '\0';
						}

						DWORD oldscreenmode = std::exchange(ScreenMode, 3);

						pEditWnd->InputText.clear();
						pEditWnd->InputText = szStationName;

						ScreenMode = oldscreenmode;
					}
					else if (char* pDest = strchr(szUserName, ';'))
					{
						// special login:
						// basically this allows for a piped login where password, server, and name
						// are sent directly. Should not be used under normal circumstances but its
						// handy when u want a quick way to login a char(s) that is not a regular
						// from your profile(s).
						// format is: Server;Character;Password
						if (char* cmdline = GetCommandLine())
						{
							int cmdlinelen = strlen(cmdline);
							if (char* ploginDest = strstr(cmdline, "/login:"))
							{
								ploginDest += 7;
								strcpy_s(szUserName, ploginDest);
								pDest = strchr(szUserName, '^');
							}
						}

						pDest[0] = '\0';
						pDest++;
						sprintf_s(szCharacterName, "%s", pDest);
						strcpy_s(szProfile, szCharacterName);

						if (char* pDest2 = strchr(szProfile, ':'))
						{
							pDest2[0] = '\0';
							strcpy_s(szServerName, szProfile);
						}
						else
						{
							strcpy_s(szServerName, szUserName);
						}

						// now that we have the server and the charname, we can figure out the stationname and password from the blob
						char szBlob[MAX_STRING] = { 0 };

						if (GetPrivateProfileString(szUserName, szCharacterName, "", szBlob, sizeof(szBlob), INIFileName))
						{
							if (pDest = strrchr(szBlob, '='))
							{
								pDest[0] = '\0';
							}
							if (ParseBlob(szBlob, szStationName, szCharacterName, szPassword, szHotkey, szCharClass, szCharLevel))
							{
								IC_LoaderSetLoaded(szProfile, szStationName, szServerName, szCharacterName, GetCurrentProcessId());
							}
						}

						DWORD oldscreenmode = std::exchange(ScreenMode, 3);

						pEditWnd->InputText.clear();
						pEditWnd->InputText = szStationName;

						ScreenMode = oldscreenmode;
					}
				}
			}
			else if (bUseStationNamesInsteadOfSessions)
			{
				AutoLoginDebug("HandleWindows(): Using station name instead of session number");
				bLoginCheckDone = true;

				pEditWnd->InputText = szStationName;

				if (szStationName[0])
				{
					GetPrivateProfileString(szStationName, "Password", 0, szPassword, 64, INIFileName);
					GetPrivateProfileString(szStationName, "Server", 0, szServerName, 32, INIFileName);
					GetPrivateProfileString(szStationName, "Character", 0, szCharacterName, 64, INIFileName);
					GetPrivateProfileString(szStationName, "SelectCharacter", 0, szSelectCharacterName, 64, INIFileName);
				}
				else
				{
					AutoLoginDebug("HandleWindows(): No station name found in LOGIN_UsernameEdit");
					bLogin = false;
					return;
				}
			}

			if (!szStationName[0] || !szPassword[0] || !szServerName[0])
			{
				AutoLoginDebug("*** Login data couldn't be retrieved.  Please check your ini file.");
				bLogin = false;
				return;
			}

			if (bUseMQ2Login)
			{
				// dont need to do anything, we already done this.
			}
			else if (!bUseStationNamesInsteadOfSessions)
			{
				pEditWnd->InputText.clear();
				pEditWnd->InputText = szStationName;
			}

			CXWnd* pConnectWnd = WindowMap["connect"];

			if (CEditWnd* pPasswordEdit = (CEditWnd*)pConnectWnd->GetChildItem(pXmlMgr, "LOGIN_PasswordEdit"))
			{
				pPasswordEdit->InputText = szPassword;

				CButtonWnd* pConnectButton = (CButtonWnd*)pConnectWnd->GetChildItem(pXmlMgr, "LOGIN_ConnectButton");
				if (pConnectButton)
				{
					DWORD oldscreenmode = std::exchange(ScreenMode, 3);

					pConnectButton->WndNotification(pConnectButton, XWM_LCLICK);

					ScreenMode = oldscreenmode;
					bWait = true;
					return;
				}
			}
		}

		return;
	}

	if (WindowActive("serverselect"))
	{
		if (bInGame)
			return;
		bWait = false;

		if (szPassword[0] == '\0')
		{
			GetPassword(szPassword);
		}

		if (WindowActive("okdialog"))
		{
			CXWnd* pOkDialog = WindowMap["okdialog"];
			if (CXWnd* pWnd = pOkDialog->GetChildItem(pXmlMgr, "OK_Display"))
			{
				CXStr str;

				if (pXmlMgr->GetWindowType(pWnd) == UI_STMLBox)
				{
					CStmlWnd* pStmlWnd = (CStmlWnd*)pWnd;
					str = pStmlWnd->STMLText;
				}
				else
				{
					str = pWnd->GetWindowText();
				}

				bGotOffsets = false;
				ullerrorwait = MQGetTickCount64() + 2000; // we give the server 5 seconds to catch its breath...

				CButtonWnd* pOkButton = (CButtonWnd*)pOkDialog->GetChildItem(pXmlMgr, "OK_OKButton");

				if (strstr(str.c_str(), "The world server is currently at maximum capacity. You are still in the login queue for this server")
					|| strstr(str.c_str(), "The world server is currently at maximum capacity. You have been added to the login queue for this server"))
				{
					if (pOkButton)
						pOkButton->WndNotification(pOkButton, XWM_LCLICK);

					// 3 mins 5 seconds... no need to click login again and again when this message has been shown...
					ullerrorwait = MQGetTickCount64() + 185000;
					bServerWait = false;
					return;
				}

				std::vector<const char*> ErrorMessages = {
					"The world server is currently at maximum capacity and not allowing further logins until the number of players online decreases.  Please try again later.",
					"That server is currently unavailable",
					"An unknown error occurred while trying to join the server.",
					"The connection has been terminated by the server.  Most likely you have been inactive",
					"A timeout occurred"
				};

				for (const char* msg : ErrorMessages)
				{
					if (strstr(str.c_str(), msg))
					{
						if (pOkButton)
							pOkButton->WndNotification(pOkButton, XWM_LCLICK);
					}
				}
			}

			bServerWait = false;
			return;
		}

		if (WindowActive("yesnodialog"))
		{
			CXWnd* pDialog = WindowMap["yesnodialog"];

			if (CXWnd* pWnd = pDialog->GetChildItem(pXmlMgr, "YESNO_Display"))
			{
				CXStr str;

				if (pXmlMgr->GetWindowType(pWnd) == UI_STMLBox)
				{
					CStmlWnd* pStmlWnd = (CStmlWnd*)pWnd;
					str = pStmlWnd->STMLText;
				}
				else
				{
					str = pWnd->GetWindowText();
				}

				// kick active character?
				if (strstr(str.c_str(), "You already have a character logged into a world server from this account."))
				{
					CButtonWnd* pButton = (CButtonWnd*)pDialog->GetChildItem(pXmlMgr,
						bKickActiveChar ? "YESNO_YesButton" : "YESNO_NoButton");

					if (pButton)
					{
						pButton->WndNotification(pButton, XWM_LCLICK);
					}

					bLogin = false;
				}
				else if (strstr(str.c_str(), "You have a character logged into a world server as an OFFLINE TRADER from this account."))
				{
					if (CButtonWnd* pButton = (CButtonWnd*)pDialog->GetChildItem(pXmlMgr, "YESNO_YesButton"))
					{
						pButton->WndNotification(pButton, XWM_LCLICK);
					}

					bLogin = false;
				}
			}

			bWait = false;
			bServerWait = false;
			return;
		}

		if (!szServerName[0])
		{
			AutoLoginDebug("HandleWindows(): szServerName NULL at serverselect.  Ending Login");

			bLogin = false;
			bEnd = true;
			return;
		}

		if (bServerWait)
			return;

		// just messing with finding short servername so we don't have to have it hardcoded... -eqmule
		// not working at all right now, maybe another day.
		// LoginClient*lc = (LoginClient*)pLoginClient;//wrong one... this address is at 1015E5B0 in eqmain.dll 03/12 2019 patch...
		// for this to work we would need a patternfind for it.
		// PEQLOGIN pldd = (PEQLOGIN)pinstEqLogin;//this is correct though...

		if (dwServerID = GetServerID(szServerName))
		{
			if (CheckServerUp(dwServerID))
			{
				if (bWeAreDown)
				{
					bWeAreDown = false;

					if (bNotifyOnServerUP == 2)
					{
						if (IsCommand("/gmail"))
						{
							DoCommand(nullptr, "/gmail \"Server is UP\" \"Time to login!\"");
						}

						bNotifyOnServerUP = 0;
					}
					else if (bNotifyOnServerUP == 1)
					{
						bNotifyOnServerUP = 0;
					}
				}

				pLoginClient->JoinServer(dwServerID);
				bSwitchServer = false;
				bServerWait = true;
			}
			else
			{
				ullerrorwait = MQGetTickCount64() + 2000;
			}
		}
		else
		{
			AutoLoginDebug("HandleWindows(): GetServerID(%s) returned 0 at serverselect", szServerName);
		}
		return;
	}

	if (WindowActive("news"))
	{
		CXWnd* pNewsWnd = WindowMap["news"];

		if (CXWnd* pWnd = pNewsWnd->GetChildItem(pXmlMgr, "NEWS_WndLabel"))
		{
			CXStr str;

			if (pXmlMgr->GetWindowType(pWnd) == UI_STMLBox)
			{
				CStmlWnd* pStmlWnd = (CStmlWnd*)pWnd;
				str = pStmlWnd->STMLText;
			}
			else
			{
				str = pWnd->GetWindowText();
			}

			// click OK button if news window is open
			if (!strcmp(str.c_str(), "NEWS"))
			{
				if (CXWnd* pButton = pNewsWnd->GetChildItem(pXmlMgr, "NEWS_OKButton"))
				{
					pButton->WndNotification(pButton, XWM_LCLICK);
				}
			}
		}
	}
}

bool SetOffsets()
{
	if (dwLoginClient = _FindPattern(dwEQMainBase, 0x100000, lcPattern, lcMask))
	{
		dwLoginClient = _GetDWordAt(dwLoginClient, 1);
	}
	else
	{
		AutoLoginDebug("Error: !dwLoginClient");
		return false;
	}

	if (!(dwEnterGameAddr = _FindPattern(dwEQMainBase, 0x200000, lcEGPattern, lcEGMask)))
	{
		AutoLoginDebug("Error: !dwEnterGame");
		return false;
	}
	return true;
}

bool SetOffsetsUI()
{
	DWORD dwSidlMgr = 0, dwWndMgr = 0, dwLoginMgr = 0;

	if (!(dwGetXMLDataAddr = _FindPattern(dwEQMainBase, 0x100000, xmldataPattern, xmldataMask)))
	{
		AutoLoginDebug("Error: !dwGetXMLDataAddr");
		return false;
	}

	if (!(dwSendLMouseClickAddr = _FindPattern(dwEQMainBase, 0x100000, lmousePattern, lmouseMask)))
	{
		AutoLoginDebug("Error: !dwSendLMouseClickAddr");
		return false;
	}

	if (dwSidlMgr = _FindPattern(dwEQMainBase, 0x100000, swmPattern, swmMask))
	{
		dwSidlMgr = _GetDWordAt(dwSidlMgr, 1);
	}
	else
	{
		AutoLoginDebug("Error: !dwSidlMgr");
		return false;
	}

	if (dwWndMgr = _FindPattern(dwEQMainBase, 0x100000, xwmPattern, xwmMask))
	{
		dwWndMgr = _GetDWordAt(dwWndMgr, 2);
	}
	else
	{
		AutoLoginDebug("Error: !dwWndMgr");
		return false;
	}

	if (dwLoginMgr = _FindPattern(dwEQMainBase, 0x100000, lvmPattern, lvmMask))
	{
		dwLoginMgr = _GetDWordAt(dwLoginMgr, 1);
		dwServerInfo = dwLoginMgr - 4;
	}
	else
	{
		AutoLoginDebug("Error: !dwLoginMgr");
		return false;
	}

	while (!pSidlManager || !pWindowManager || !pLoginViewManager)
	{
		pSidlManager = (CSidlManager*)*(DWORD*)dwSidlMgr;
		pWindowManager = (CXWndManager*)*(DWORD*)dwWndMgr;
		pLoginViewManager = (CLoginViewManager*) * (DWORD*)dwLoginMgr;
	}

	return true;
}

DWORD GetProcessCount(char* exeName)
{
	HANDLE hnd = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 proc;
	proc.dwSize = sizeof(PROCESSENTRY32);
	DWORD n = 0;

	if (Process32First(hnd, &proc))
	{
		do
		{
			if (!_stricmp(proc.szExeFile, exeName))
				n++;
		} while (Process32Next(hnd, &proc));
	}

	CloseHandle(hnd);

	return n;
}

void LoginReset()
{
	AutoLoginDebug("LoginReset()");
	bLogin = false;
	bInGame = true;
	pSidlManager = 0;
	pWindowManager = 0;
	pLoginViewManager = 0;
	WindowMap.clear();
}

#ifdef AUTOLOGIN_DBG
void DebugLog(char* szFormat, ...)
{
	char szOutput[512] = { 0 };
	char szTmp[512] = { 0 };
	va_list vaList;

	if (FILE * fLog = fopen(DBG_LOGFILE_PATH, "a"))
	{
		va_start(vaList, szFormat);
		vsprintf(szTmp, szFormat, vaList);

		time_t CurTime;
		time(&CurTime);
		tm* pTime = localtime(&CurTime);
		sprintf_s(szOutput, "[%02d/%02d/%04d %02d:%02d:%02d] ", pTime->tm_mon + 1, pTime->tm_mday, pTime->tm_year + 1900, pTime->tm_hour, pTime->tm_min, pTime->tm_sec);
		strcat_s(szOutput, szTmp);

		fprintf(fLog, "%s\n", szOutput);
		fclose(fLog);
	}
}
#endif

// originally created by: radioactiveman/bunny771/(dom1n1k?) of GameDeception -----------
inline bool _DataCompare(const unsigned char* pData, const unsigned char* bMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++bMask)
	{
		if (*szMask == 'x' && *pData != *bMask)
			return false;
	}
	return (*szMask) == 0;
}

unsigned long _FindPattern(unsigned long dwAddress, unsigned long dwLen, unsigned char* bPattern, char* szMask)
{
	for (unsigned long i = 0; i < dwLen; i++)
	{
		if (_DataCompare((unsigned char*)(dwAddress + i), bPattern, szMask))
			return (unsigned long)(dwAddress + i);
	}

	return 0;
}
// --------------------------------------------------------------------------------------

// ieatacid - 3/11/09
unsigned long _GetDWordAt(unsigned long address, unsigned long numBytes)
{
	if (address)
	{
		address += numBytes;
		if (*(unsigned long*)address)
			return *(unsigned long*)address;
	}
	return 0;
}

// ieatacid - 3/11/09
unsigned long _GetFunctionAddressAt(unsigned long address, unsigned long addressOffset, unsigned long numBytes)
{
	if (address)
	{
		unsigned long n = *(unsigned long*)(address + addressOffset);
		return address + n + numBytes;
	}
	return 0;
}
