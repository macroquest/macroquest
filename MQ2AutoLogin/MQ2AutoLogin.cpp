/*****************************************************************************
MQ2AutoLogin.cpp

Copyright (C) 2012 ieatacid

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License, version 2, as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Change log:
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
- Added a feature to login your char if you inject/reinject at char select
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
PLUGIN_VERSION(2.6);
#include <map>
#include <tlhelp32.h>
PreSetup("MQ2AutoLogin");
#include <wincrypt.h>
#pragma comment( lib, "Crypt32.lib" )

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
ULONGLONG ullerrorwait = 0;

struct _ServerData {
    char *Name;
    DWORD ID;
};


_ServerData ServerData[] = {
    {"lockjaw",    160},
    {"ragefire",   159},
    {"vox",        158},
    {"trakanon",   154},
    {"fippy",      156},
    {"vulak",      157},
    {"mayong",     163},
    {"antonius",    68},
    {"bertox",      53},
    {"bristle",      9},
    {"cazic",       49},
    {"drinal",      40},
    {"erollisi",    48},
    {"firiona",     77},
    {"luclin",      76},
    {"povar",        5},
    {"rathe",       46},
    {"tunare",      57},
    {"xegony",      51},
    {"zek",         54},
    {"test",         1},
    {0, 0},
};
typedef struct _SERVERINFO
{
/*0x00*/	DWORD ID;
/*0x04*/	PCXSTR ServerName;
/*0x08*/	PCXSTR ServerIP;
/*0x0C*/	DWORD Unknown0x0C;
/*0x10*/	DWORD Unknown0x10;
/*0x14*/	DWORD Unknown0x14;
/*0x018*/	DWORD Unknown0x018;
/*0x01C*/	DWORD Unknown0x01C;
/*0x020*/	DWORD Unknown0x020;
/*0x024*/	DWORD Unknown0x024;
/*0x028*/	DWORD Unknown0x028;
/*0x02C*/	DWORD Unknown0x02C;
/*0x030*/	DWORD Unknown0x030;
/*0x034*/	DWORD Unknown0x034;
/*0x038*/	DWORD Unknown0x038;
/*0x03C*/	DWORD Unknown0x03C;
/*0x040*/	DWORD Unknown0x040;
/*0x044*/	DWORD Players;//only on emu, its not sent for live servers.
/*0x048*/	DWORD Unknown0x048;
/*0x04C*/	DWORD Unknown0x04C;
/*0x050*/
}SERVERINFO,*PSERVERINFO;
typedef struct _SERVERLIST
{
/*0x00*/	PSERVERINFO Info;
/*0x04*/	_SERVERLIST *Prev;
/*0x08*/	_SERVERLIST *Next;
/*0x0C*/	DWORD Unknown0x0C;
/*0x10*/	DWORD Unknown0x10;
/*0x14*/	DWORD Unknown0x14;
/*0x18*/
}SERVERLIST,*PSERVERLIST;

typedef struct _PSERVERSTUFF
{
/*0x000*/	BYTE Unknown0x000[0x8];
/*0x008*/	PVOID GFXENGINE;
/*0x00C*/	BYTE Unknown0x00C[0x9C];
/*0x0A8*/	DWORD CurrentServerID;
/*0x0AC*/	DWORD Unknown0x0AC;
/*0x0B0*/	PCXSTR LoginName;
/*0x0B4*/	PCXSTR Password;
/*0x0B8*/	PCXSTR LoginNameCopy;
/*0x0BC*/	PCXSTR PasswordCopy;
/*0x0C0*/	PCXSTR AccountKey;
/*0x0C4*/	BYTE Unknown0x0C4[0x14];
/*0x0D8*/	PSERVERINFO *FirstServer;//D8
/*0x0DC*/	PSERVERINFO *LastServer;//DC
/*0x0E0*/	BYTE Unknown0x0E0[0x8];
/*0x0E8*/	PSERVERLIST pServerList;
/*0x0EC*/	DWORD ServerListSize;
/*0x0F0*/	BYTE Unknown0x0F0[0x8];
/*0x0F8*/	DWORD QuickConnectServerID;
/*0x0FC*/	PCXSTR QuickConnectServerName;
/*0x100*/	PCXSTR QuickConnectIPAddress;//0x100
/*0x104*/
} SERVERSTUFF, *PSERVERSTUFF;
DWORD dwServerInfo = 0;
CSidlManager *pSidlManager = 0;
PCXWNDMGR pWindowManager = 0;
class CLoginViewManager *pLoginViewManager = 0;
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
char szStationName[64] = {0};
char szCustomIni[64] = { 0 };
char szPassword[64] = {0};
char szServerName[32] = {0};
char szCharacterName[64] = {0};
char szNewChar[0x40] = {0};
ULONGLONG dwTime = 0;
ULONGLONG switchTime = 0;
map<string, class CXWnd2 *> WindowMap;


// this changes frequently so it needs to be done this way
#define pLoginClient ((CLoginClient*)*(DWORD*)dwLoginClient)


bool SetOffsets();
bool SetOffsetsUI();
void HandleWindows();
void LoginReset();
void SwitchCharacter(char *szName);
void SelectCharacter( char *szName );
DWORD GetProcessCount(char *exeName);
void DebugLog(char *szFormat, ...);
unsigned long _FindPattern(unsigned long dwAddress,unsigned long dwLen,unsigned char *bPattern,char * szMask);
unsigned long _GetDWordAt(unsigned long address, unsigned long numBytes);
unsigned long _GetFunctionAddressAt(unsigned long address, unsigned long addressOffset, unsigned long numBytes);


PBYTE eqmainPattern = (PBYTE)"\x8B\x0D\x00\x00\x00\x00\x68\x00\x00\x00\x00\x51\xFF\xD6\xA3\x00\x00\x00\x00\x85\xC0\x75\x00\xFF\x15\x00\x00\x00\x00\x50\x68\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x83\xC4\x00\x33\xC0\x5E\xC3";
char eqmainMask[] = "xx????x????xxxx????xxx?xx????xx????x????xx?xxxx";

PBYTE lvmPattern = (PBYTE)"\xA3\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x83\xC4\x00\x85\xC0\x74\x00\x8B\x96\x00\x00\x00\x00\x52\x57\x8B\xC8\xE8\x00\x00\x00\x00\xEB\x00";
char lvmMask[] = "x????x????xx?xxx?xx????xxxxx????x?";

PBYTE xwmPattern = (PBYTE)"\x8B\x15\x00\x00\x00\x00\x89\x82\x00\x00\x00\x00\xA1\x00\x00\x00\x00\xC6\x80\x00\x00\x00\x00\x00\x8B\x0D\x00\x00\x00\x00\x89\x1D\x00\x00\x00\x00\x8B\x11\x8B\x42\x00\xFF\xD0\x85\xC0\x74\x00";
char xwmMask[] = "xx????xx????x????xx?????xx????xx????xxxx?xxxxx?";

PBYTE swmPattern = (PBYTE)"\xA1\x00\x00\x00\x00\x80\xB8\x00\x00\x00\x00\x00\x0F\x84\x00\x00\x00\x00\x8D\x88\x00\x00\x00\x00\x8B\x01\x3B\xC3\x74\x00\x89\x45\x00\x33\xDB\x8B\x45\x00\xF0\xFF\x00\x0F\x94\xC3\x89\x5D\x00";
char swmMask[] = "x????xx?????xx????xx????xxxxx?xx?xxxx?xxxxxxxx?";

PBYTE xmldataPattern = (PBYTE)"\x8B\x54\x24\x00\x56\x8B\x74\x24\x00\x8B\xC1\x85\xD2\x75\x00\x85\xF6\x75\x00\x33\xC0\x5E\xC2\x00\x00";
char xmldataMask[] = "xxx?xxxx?xxxxx?xxx?xxxx??";

PBYTE lmousePattern = (PBYTE)"\x55\x8B\xEC\x6A\x00\x68\x00\x00\x00\x00\x64\xA1\x00\x00\x00\x00\x50\x83\xEC\x00\x53\x56\x57\xA1\x00\x00\x00\x00\x33\xC5\x50\x8D\x45\x00\x64\xA3\x00\x00\x00\x00\x8B\xF1\x83\x7E\x00\x00";
char lmouseMask[] = "xxxx?x????xx????xxx?xxxx????xxxxx?xx????xxxx??";

PBYTE lcPattern = (PBYTE)"\xA3\x00\x00\x00\x00\x8B\x56\x00\x8B\x4A\x00\x6A\x00\x51\x52\x8B\xC8\xC7\x45\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00";
char lcMask[] = "x????xx?xx?x?xxxxxx?????x????";

//login::pulse
PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x28\xFD\xFF\xFF\x8B\xCE\x5E\xE9\x10\xF7\xFF\xFF\xC7\x01\x00\x00\x00\x00\xC3\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\x55\x8B\xEC\xF6\x45\x08\x01\x56\x8B\xF1\xC7\x06";
char lpMask[] = "xxxxxxxxxxxxxxxxxx????xxxxxxxxxxxxxxxxxxxxxx";


#ifndef EMU
#define SPLASH "dbgsplash"
PBYTE lcEGPattern = (PBYTE)"\x55\x8B\xEC\x6A\xFF\x68\x00\x00\x00\x00\x64\xA1\x00\x00\x00\x00\x50\x83\xEC\x34\x53\x56\xA1\x00\x00\x00\x00\x33\xC5\x50\x8D\x45\xF4\x64\xA3\x00\x00\x00\x00\x8B\xF1\x33\xDB\xC7\x45\x00\x00\x00\x00\x00\xC7\x45\x00\x00\x00\x00\x00\x89\x5D\xEC\x89\x5D\xE8\x8D\x45\xE0\x50\x89\x5D\xFC\xE8\x00\x00\x00\x00\x8D\x4D\xF0\x51\xE8\x00\x00\x00\x00\x83\xC4\x08\x8D\x4D\xC0\xE8\x00\x00\x00\x00\x8B\x45\xE4\x8B\x55\x08\x50\x8D\x4D\xD8\xC6\x45\xFC\x01\x89\x55\xD4\xE8\x00\x00\x00\x00\x8B\x4D\xF0\x8B\x55\x10\x8B\x45\x0C\x52\x89\x4D\xDC\x50\x8D\x4D\xC0\x51\x8B\xCE\xE8\x00\x00\x00\x00\x8D\x4D\xC0\x8B\xF0\x88\x5D\xFC\xE8\x00\x00\x00\x00\xC7\x45\x00\x00\x00\x00\x00\xC7\x45\x00\x00\x00\x00\x00\x39\x5D\xEC\x7E\x20\x8B\x45\xE4\x83\xC0\xFC\x8B\xD0\x83\xC9\xFF\xF0\x0F\xC1\x0A\x49\x85\xC9\x7F\x0C\x8B\x55\xE0\x50\x8B\x42\x08\x8D\x4D\xE0\xFF\xD0\x8B\xC6\x8B\x4D\xF4\x64\x89\x0D\x00\x00\x00\x00\x59\x5E\x5B\x8B\xE5\x5D\xC2\x0C\x00";
char lcEGMask[] = "xxxxxx????xx????xxxxxxx????xxxxxxxx????xxxxxx?????xx?????xxxxxxxxxxxxxx????xxxxx????xxxxxxx????xxxxxxxxxxxxxxxxxx????xxxxxxxxxxxxxxxxxxxxx????xxxxxxxxx????xx?????xx?????xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx????xxxxxxxxx";
#else
#define SPLASH "soesplash"
PBYTE lcEGPattern = (PBYTE)"\x55\x8B\xEC\x6A\xFF\x68\x00\x00\x00\x00\x64\xA1\x00\x00\x00\x00\x50\x83\xEC\x18\x56\xA1\x00\x00\x00\x00\x33\xC5\x50\x8D\x45\xF4\x64\xA3\x00\x00\x00\x00\x8B\xF1\x8d\x4d\xDC\xE8\x00\x00\x00\x00\x00\x4d\x10\x00\x00\x00\x00\x00\x0c\x51\x89\x45\xf0\x52\x8D\x45";
char lcEGMask[] = "xxxxxx????xx????xxxxxx????xxxxxxxx????xxxxxx?????xx?????xxxxxxxx";
#endif
BOOL DecryptData(DATA_BLOB *DataIn,DATA_BLOB *DataOut)
{
	return CryptUnprotectData(DataIn,NULL,NULL,NULL,NULL,0,DataOut);
}

int StrToBlobA(LPCSTR szIn,DATA_BLOB *BlobOut)
{
	size_t len = strlen(szIn);
	BlobOut->pbData = (BYTE *)LocalAlloc(LPTR,(len)+1);
	char *szArg = new char[len+1];
	strcpy_s(szArg,len+1,szIn);
	BYTE CurByte=0;
	DWORD out=0;
	_strlwr_s(szArg,len+1);
	for (int count=0;szArg[count];count+=2,out++) 
	{
		if (((szArg[count]<'0' || szArg[count]>'9') && (szArg[count]<'a' || szArg[count]>'f')) || ((szArg[count+1]<'0' || szArg[count+1]>'9') && (szArg[count+1]<'a' || szArg[count+1]>'f'))) 
			break; 

		if (szArg[count]>='0' && szArg[count]<='9') CurByte=szArg[count]-0x30; 
		else if (szArg[count]>='a' && szArg[count]<='f') CurByte=szArg[count]-87; 

		CurByte<<=4; 

		if (szArg[count+1]>='0' && szArg[count+1]<='9') CurByte|=szArg[count+1]-0x30; 
		else if (szArg[count+1]>='a' && szArg[count+1]<='f') CurByte|=szArg[count+1]-87; 

		BlobOut->pbData[out]=CurByte; 
	} 
	BlobOut->cbData=out;
	BlobOut->pbData[out++] = '\0';
	delete[] szArg;
	return BlobOut->cbData;
}
class CXMLDataManager2
{
public:
    CXMLData *GetXMLData(int, int);
};

class CXWnd2 : public CXWnd
{
public:
    CXMLData *GetXMLData()
    {
        if(XMLIndex)
        {
            return ((CXMLDataManager2*)&((PCSIDLMGR)pSidlManager)->pXMLDataMgr)->GetXMLData(XMLIndex>>16,XMLIndex&0xFFFF);
        }
        return 0;
    }

    enum UIType GetType()
    {
        if (CXMLData *pXMLData = GetXMLData())
            return pXMLData->Type;
        return UI_Unknown;
    }
    CXWnd *_GetChildItem(PCHAR);
};

class CLoginViewManager
{
public:
    int SendLMouseClick(CXPoint &);
};

class CLoginClient
{
public:
    int EnterGame(DWORD serverID, DWORD zero = 0, DWORD ten = 0xa);
};

FUNCTION_AT_VARIABLE_ADDRESS(CXMLData *CXMLDataManager2::GetXMLData(int,int), dwGetXMLDataAddr);
FUNCTION_AT_VARIABLE_ADDRESS(int CLoginViewManager::SendLMouseClick(CXPoint &), dwSendLMouseClickAddr);
FUNCTION_AT_VARIABLE_ADDRESS(int CLoginClient::EnterGame(DWORD, DWORD, DWORD), dwEnterGameAddr);


class CXWnd2 *_RecurseAndFindName(class CXWnd2 *pWnd, PCHAR Name)
{
    CHAR Buffer[MAX_STRING]={0};
    class CXWnd2 *tmp;

    if (!pWnd) return pWnd;

    if (CXMLData *pXMLData=pWnd->GetXMLData()) {
        if (GetCXStr(pXMLData->Name.Ptr,Buffer,MAX_STRING) && !_stricmp(Buffer,Name)) {
            return pWnd;
        }
        //AutoLoginDebug("RecurseAndFindName looking for %s but found %s", Name, Buffer);
        if (GetCXStr(pXMLData->ScreenID.Ptr,Buffer,MAX_STRING) && !_stricmp(Buffer,Name)) {
            return pWnd;
        }
    }

    if (pWnd->pFirstChildWnd) {
        tmp = _RecurseAndFindName((class CXWnd2 *)pWnd->pFirstChildWnd, Name);
        if (tmp)
            return tmp;
    }
    return _RecurseAndFindName((class CXWnd2 *)pWnd->pNextSiblingWnd, Name);
}

class CXWnd * CXWnd2::_GetChildItem(PCHAR Name)
{
    return _RecurseAndFindName(this, Name);
}

template <unsigned int _Size,unsigned int _OutSize>bool GetServerLongName(CHAR(&szName)[_Size], CHAR(&szOut)[_OutSize])
{
	if (GetPrivateProfileString("Servers", szName, 0, szOut, _OutSize, INIFileName)) {
		if (szOut[0] != '\0')
			return true;
	}
	return false;
}
template <unsigned int _Size>bool GetPassword(CHAR(&szBuffer)[_Size])
{
	if (dwServerInfo) {
		if (PSERVERSTUFF serveridoff = *(PSERVERSTUFF*)dwServerInfo) {
			if (serveridoff->Password) {
				GetCXStr(serveridoff->Password, szBuffer, _Size);
				if (szBuffer[0]!='\0') {
					return true;
				}
			}
		}
	}
	return false;
}
template <unsigned int _Size>DWORD GetServerIDFromName(CHAR(&szShortName)[_Size])
{
	if (GetGameState() != GAMESTATE_PRECHARSELECT) {
		bGotOffsets = false;
		return 0;
	}
	CHAR szLongName[MAX_STRING] = { 0 };
	if (GetServerLongName(szShortName, szLongName)) {
		if (WindowMap.find("SERVERSELECT_ServerList") != WindowMap.end()) {
			if (CListWnd*serverlist = (CListWnd*)WindowMap["SERVERSELECT_ServerList"]) {
				if (serverlist->Items && dwServerInfo) {
					if (PSERVERSTUFF serveridoff = *(PSERVERSTUFF*)dwServerInfo) {
						if (serveridoff->pServerList && serveridoff->pServerList->Info) {
							PSERVERLIST pList = serveridoff->pServerList;
							while (pList) {
								if (pList->Info) {
									CHAR szServer[MAX_STRING] = { 0 };
									GetCXStr(pList->Info->ServerName, szServer);
									if (szServer[0] != '\0') {
										if (!_stricmp(szServer, szLongName)) {
											return pList->Info->ID;
										}
										//CHAR szID[MAX_STRING] = { 0 };
										//sprintf_s(szID, "%d", pList->Info->ID);
										//WritePrivateProfileString("Servers", szServer, szID, "C:\\eqservers.ini");
									}
								}
								pList = pList->Next;
							}
						} else {
							bGotOffsets = false;
						}
					}
				}
			}
		}
	}
	return 0;
}
template <unsigned int _Size>DWORD GetServerID(CHAR(&szName)[_Size])
{
    for(DWORD n = 0; ServerData[n].ID; n++)
    {
        if(!_stricmp(szName, ServerData[n].Name))
        {
            return ServerData[n].ID;
        }
    }
	if(DWORD ID = GetServerIDFromName(szName)) {
		return ID;
	}
    return 0;
}

void Cmd_SwitchServer(PSPAWNINFO pChar, char *szLine)
{
    char szServer[MAX_STRING] = {0};
    char szCharacter[MAX_STRING] = {0};
    char szLongName[MAX_STRING] = {0};

    GetArg(szServer, szLine, 1);
    GetArg(szCharacter, szLine, 2);

    if(szServer[0] && szCharacter[0])
    {
		bool oktomoveon = false;
		if (GetServerID(szServer))
			oktomoveon = true;
		else if (GetServerLongName(szServer, szLongName))
			oktomoveon = true;
		if(oktomoveon) {
			dwServerID = -1;
            strcpy_s(szServerName, szServer);
            strcpy_s(szCharacterName, szCharacter);
            bSwitchServer = true;

            if(pChar->StandState == STANDSTATE_FEIGN)
            {
                // using DoMappable here doesn't create enough of a delay for camp to work
                EzCommand("/stand");
            }
            EzCommand("/camp");
			bInGame = false;
            WriteChatf("Switching to \ag%s\ax on server \ag%s\ax", szCharacterName, szServer);
            return;
        }
        else
        {
            char szServers[MAX_STRING] = {0};

            WriteChatf("Invalid server name \ag%s\ax.  Valid server names are:", szServer);

            for(DWORD n = 0; ServerData[n].ID; n++)
            {
                if(n)
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

void Cmd_SwitchCharacter(PSPAWNINFO pChar, char *szLine)
{
    char szArg1[MAX_STRING] = {0};

    if(szLine[0])
    {
        GetArg(szArg1, szLine, 1);
        if(GetGameState() == GAMESTATE_INGAME)
        {
            if(_stricmp(szArg1, pChar->DisplayedName))
            {
                strcpy_s(szNewChar, szArg1);

                if(pChar->StandState == STANDSTATE_FEIGN)
                {
                    // using DoMappable here doesn't create enough of a delay for camp to work
                    EzCommand("/stand");
                }
                EzCommand("/camp");
				bSwitchChar = true;
				WriteChatf("Switch to \ag%s\ax is now active and will commence at character select.", szNewChar);
            }
            else
            {
                WriteChatf("\ayYou're already logged onto '%s'\ax", szArg1);
            }
        }
        else if(GetGameState() == GAMESTATE_CHARSELECT)
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

void Cmd_Relog(PSPAWNINFO pChar, char *szLine)
{
    if(GetGameState() == GAMESTATE_INGAME)
    {
        if(!szLine[0])
        {
            WriteChatf("\ayUsage:\ax /relog [#s|#m]");
            WriteChatf("Example: /relog 30m (logs character out for 30 minutes then logs back in)");
            return;
        }

        DWORD n = atol(szLine);

        switch(szLine[strlen(szLine) - 1])
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

        if(n)
            dwTime = MQGetTickCount64() + n;     

        strcpy_s(szNewChar, pChar->DisplayedName);

        if(dwTime)
            dwTime += 30000; // add 30 seconds for camp time

        if(pChar->StandState == STANDSTATE_FEIGN)
        {
            // using DoMappable here doesn't create enough of a delay for camp to work
            EzCommand("/stand");
        }
        EzCommand("/camp");
		bInGame = false;
    }
}
DWORD Login__Pulse_x = 0;
bool bGotOffsets = false;
bool GetAllOffsets(DWORD dweqmain)
{
	if (!dweqmain)
		return false;
	if(dwLoginClient = _FindPattern(dweqmain, 0x100000, lcPattern, lcMask))
    {
        dwLoginClient = _GetDWordAt(dwLoginClient, 1);
    }
    else
    {
        AutoLoginDebug("Error: !dwLoginClient");
        return false;
    }
    if(!(dwEnterGameAddr = _FindPattern(dweqmain, 0x200000, lcEGPattern, lcEGMask)))
    {
        AutoLoginDebug("Error: !dwEnterGame");
        return false;
    }
	DWORD dwSidlMgr = 0, dwWndMgr = 0, dwLoginMgr = 0;

    if(!(dwGetXMLDataAddr = _FindPattern(dweqmain, 0x100000, xmldataPattern, xmldataMask)))
    {
        AutoLoginDebug("Error: !dwGetXMLDataAddr");
        return false;
    }

    if(!(dwSendLMouseClickAddr = _FindPattern(dweqmain, 0x100000, lmousePattern, lmouseMask)))
    {
        AutoLoginDebug("Error: !dwSendLMouseClickAddr");
        return false;
    }

    if(dwSidlMgr = _FindPattern(dweqmain, 0x100000, swmPattern, swmMask))
    {
        dwSidlMgr = _GetDWordAt(dwSidlMgr, 1);
    }
    else
    {
        AutoLoginDebug("Error: !dwSidlMgr");
        return false;
    }

    if(dwWndMgr = _FindPattern(dweqmain, 0x100000, xwmPattern, xwmMask))
    {
        dwWndMgr = _GetDWordAt(dwWndMgr, 2);
    }
    else
    {
        AutoLoginDebug("Error: !dwWndMgr");
        return false;
    }

    if(dwLoginMgr = _FindPattern(dweqmain, 0x100000, lvmPattern, lvmMask))
    {
        dwLoginMgr = _GetDWordAt(dwLoginMgr, 1);
		dwServerInfo = dwLoginMgr - 4;
    }
    else
    {
        AutoLoginDebug("Error: !dwLoginMgr");
        return false;
    }
	pSidlManager = 0; pWindowManager = 0; pLoginViewManager = 0;

    while(!pSidlManager || !pWindowManager || !pLoginViewManager)
    {
        pSidlManager = (CSidlManager*)*(DWORD*)dwSidlMgr;
        pWindowManager = (PCXWNDMGR)*(DWORD*)dwWndMgr;
        pLoginViewManager = (CLoginViewManager*)*(DWORD*)dwLoginMgr;
    }
	WindowMap.clear();
	PCSIDLWND* ppWnd = pWindowManager->pWindows;
	PCSIDLWND pWnd=*ppWnd;
	DWORD count = pWindowManager->Count;
	CHAR Name[MAX_STRING] = { 0 };
	while (pWnd = *ppWnd)
	{
		if (count-- == 0)
			break;
		if (CXMLData *pXMLData = ((CXWnd2*)pWnd)->GetXMLData())
		{
			GetCXStr(pXMLData->Name.Ptr, Name, MAX_STRING);

			if (Name[0])
			{
				AutoLoginDebug("bLogin loop: adding window '%s'", Name);
				WindowMap[Name] = (CXWnd2*)pWnd;
			}
		}
		ppWnd++;
	}
	bGotOffsets = true;
	return true;
}
void LoginPulse()
{
	if (ullerrorwait) {
		if (ullerrorwait > MQGetTickCount64()) {
			Sleep(0);
			return;
		}
		else {
			ullerrorwait = 0;
		}
	}
	if (GetAsyncKeyState(VK_END) & 1)
	{
		bEnd = true;
		return;
	}
    if( GetAsyncKeyState( VK_HOME ) & 1 )
    {
        bLogin = true;
        bEnd = false;
        return;
    }
	if (!bGotOffsets) {
		GetAllOffsets(dwEQMainBase);
	} else {
		if(!bEnd)
			HandleWindows();
	}
}
class Login
{
public:
	int Pulse_Tramp();
	int Pulse_Detour()
	{
		LoginPulse();
		return Pulse_Tramp();
	}
};
void RemoveLoginPulse();

DETOUR_TRAMPOLINE_EMPTY(int Login::Pulse_Tramp());
void AddOurPulse()
{
	if (GetModuleHandle("eqmain.dll")) {
		bEnd = false;
		if (dwEQMainBase = (DWORD)GetModuleHandle("eqmain.dll")) {
			if (Login__Pulse_x)
				RemoveLoginPulse();
			if (!(Login__Pulse_x = _FindPattern(dwEQMainBase, 0x200000, lpPattern, lpMask)))
			{
				//MessageBox(NULL, "MQ2AutoLogin needs an update.", "Couldn't find Login__Pulse_x", MB_SYSTEMMODAL | MB_OK);
				return;
			}
			if (Login__Pulse_x) {// = (DWORD)dwEQMainBase + 0x11030;
				bGotOffsets = false;
				if (*(BYTE*)Login__Pulse_x != 0xe9) {
					EzDetourwName(Login__Pulse_x, &Login::Pulse_Detour, &Login::Pulse_Tramp,"Login__Pulse_x");
				}
			}
		}
		if (!bInGame && !bSwitchServer && !dwTime)
		{
			if (bUseMQ2Login) {
				//then we don't need anything else
			}
			else if (!bUseStationNamesInsteadOfSessions) {
				DWORD nProcs = GetProcessCount("eqgame.exe");
				CHAR szSession[32] = { 0 };
				sprintf_s(szSession, "Session%d", nProcs);
				AutoLoginDebug(szSession);

				GetPrivateProfileString(szSession, "StationName", 0, szStationName, 64, INIFileName);
				GetPrivateProfileString(szSession, "Password", 0, szPassword, 64, INIFileName);
				GetPrivateProfileString(szSession, "Server", 0, szServerName, 32, INIFileName);
				GetPrivateProfileString(szSession, "Character", 0, szCharacterName, 64, INIFileName);
			}
		}
	}
}

// custom ini support
DWORD_PTR gppi = 0;
DWORD_PTR gpps = 0;
DWORD_PTR wpps = 0;

DWORD WINAPI GetPrivateProfileStringA_Tramp( LPCSTR, LPCSTR, LPCSTR, LPSTR, DWORD, LPCSTR );

void SetupCustomIni()
{
    if( szCustomIni && szCustomIni[0] != '\0' )
        return;

    if( char *pLogin = GetLoginName() )
    {
        strcpy_s( szStationName, pLogin );
        if( gpps )
        {
            GetPrivateProfileStringA_Tramp( szStationName, "CustomClientIni", 0, szCustomIni, 64, INIFileName );
        }
        else
        {
            GetPrivateProfileString( szStationName, "CustomClientIni", 0, szCustomIni, 64, INIFileName );
        }
    }
}

DWORD WINAPI GetPrivateProfileStringA_Detour( LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpDefault, LPSTR lpReturnedString, DWORD nSize, LPCSTR lpFileName )
{
    if( lpFileName )
    {
        SetupCustomIni();
        CHAR szPath[MAX_STRING] = { 0 };
        strcpy_s( szPath, lpFileName );
        _strlwr_s( szPath );

        if( szCustomIni && szCustomIni[0] != '\0' && strstr( szPath, "eqclient.ini" ) )
        {
            strcpy_s( szPath, ".\\" );
            strcat_s( szPath, szCustomIni );
            return GetPrivateProfileStringA_Tramp( lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, szPath );
        }
    }

    return GetPrivateProfileStringA_Tramp( lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName );
}
DETOUR_TRAMPOLINE_EMPTY( DWORD WINAPI GetPrivateProfileStringA_Tramp( LPCSTR, LPCSTR, LPCSTR, LPSTR, DWORD, LPCSTR ) );

BOOL WINAPI WritePrivateProfileStringA_Tramp( LPCSTR, LPCSTR, LPCSTR, LPCSTR );
BOOL WINAPI WritePrivateProfileStringA_Detour( LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpString, LPCSTR lpFileName )
{
    if( lpFileName )
    {
        SetupCustomIni();
        CHAR szPath[MAX_STRING] = { 0 };
        strcpy_s( szPath, lpFileName );
        _strlwr_s( szPath );

        if( szCustomIni && szCustomIni[0] != '\0' && strstr( szPath, "eqclient.ini" ) )
        {
            strcpy_s( szPath, ".\\" );
            strcat_s( szPath, szCustomIni );
            return WritePrivateProfileStringA_Tramp( lpAppName, lpKeyName, lpString, szPath );
        }
    }

    return WritePrivateProfileStringA_Tramp( lpAppName, lpKeyName, lpString, lpFileName );
}
DETOUR_TRAMPOLINE_EMPTY( BOOL WINAPI WritePrivateProfileStringA_Tramp( LPCSTR, LPCSTR, LPCSTR, LPCSTR ) );

UINT WINAPI GetPrivateProfileIntA_Tramp( LPCSTR, LPCSTR, INT, LPCSTR );
UINT WINAPI GetPrivateProfileIntA_Detour( LPCSTR lpAppName, LPCSTR lpKeyName, INT nDefault, LPCSTR lpFileName )
{
    if( lpFileName )
    {
        SetupCustomIni();
        CHAR szPath[MAX_STRING] = { 0 };
        strcpy_s( szPath, lpFileName );
        _strlwr_s( szPath );
        if( szCustomIni && szCustomIni[0] != '\0' && strstr( szPath, "eqclient.ini" ) )
        {
            strcpy_s( szPath, ".\\" );
            strcat_s( szPath, szCustomIni );
            return GetPrivateProfileIntA_Tramp( lpAppName, lpKeyName, nDefault, szPath );
        }
    }

    return GetPrivateProfileIntA_Tramp( lpAppName, lpKeyName, nDefault, lpFileName );
}
DETOUR_TRAMPOLINE_EMPTY( UINT WINAPI GetPrivateProfileIntA_Tramp( LPCSTR, LPCSTR, INT, LPCSTR ) );

PLUGIN_API VOID InitializePlugin(VOID)
{
	//MessageBox(NULL, "Inject now", "MQ2 Debug", MB_OK|MB_SYSTEMMODAL);
	CHAR szPath[MAX_PATH] = { 0 };
    GetPrivateProfileStringA("Settings", "IniLocation", 0, szPath, MAX_PATH, INIFileName);
    if(szPath[0])
        strcpy_s(INIFileName, szPath);

    bKickActiveChar = GetPrivateProfileInt("Settings", "KickActiveCharacter", 1, INIFileName);
    bUseMQ2Login = GetPrivateProfileInt("Settings", "UseMQ2Login", 0, INIFileName);
    bUseStationNamesInsteadOfSessions = GetPrivateProfileInt("Settings", "UseStationNamesInsteadOfSessions", 0, INIFileName);
    bReLoggin = GetPrivateProfileInt("Settings", "LoginOnReLoadAtCharSelect", 0, INIFileName);
    bool bUseCustomClientIni = GetPrivateProfileInt( "Settings", "EnableCustomClientIni", 0, INIFileName ) == 1;
    bEndAfterCharSelect = GetPrivateProfileInt( "Settings", "EndAfterCharSelect", 0, INIFileName ) == 1;

	//is eqmain.dll loaded
	if (GetModuleHandle("eqmain.dll")) {
		//well well well... what do u know... it's loaded...
		//ok fine that means we wont get any frontload notification, so lets fake it
		AddOurPulse();
	}
    AddCommand("/switchserver", Cmd_SwitchServer);
    AddCommand("/switchcharacter", Cmd_SwitchCharacter);
    AddCommand("/relog", Cmd_Relog);
    
    if( bUseCustomClientIni )
    {
        if( bUseStationNamesInsteadOfSessions && !bUseMQ2Login ) 
        {
            SetupCustomIni();
        }
        if( gppi = (DWORD_PTR)GetProcAddress( GetModuleHandle( "kernel32.dll" ), "GetPrivateProfileIntA" ) ) {
            EzDetourwName( gppi, GetPrivateProfileIntA_Detour, GetPrivateProfileIntA_Tramp, "GetPrivateProfileIntA_Detour" );
        }
        if( gpps = (DWORD_PTR)GetProcAddress( GetModuleHandle( "kernel32.dll" ), "GetPrivateProfileStringA" ) ) {
            EzDetourwName( gpps, GetPrivateProfileStringA_Detour, GetPrivateProfileStringA_Tramp, "GetPrivateProfileStringA_Detour" );
        }
        if( wpps = (DWORD_PTR)GetProcAddress( GetModuleHandle( "kernel32.dll" ), "WritePrivateProfileStringA" ) ) {
            EzDetourwName( wpps, WritePrivateProfileStringA_Detour, WritePrivateProfileStringA_Tramp, "WritePrivateProfileStringA_Detour" );
        }
    }

#ifdef AUTOLOGIN_DBG
    remove(DBG_LOGFILE_PATH);
#endif
	//force a check if user loads us at charselect for example...
	if(GetGameState() == GAMESTATE_CHARSELECT && bReLoggin)
    {
        DWORD nProcs = GetProcessCount("eqgame.exe");
		if (bUseMQ2Login) {
			//i dont think we need to load anything here
		} else if (!bUseStationNamesInsteadOfSessions) {
			CHAR szSession[32] = { 0 };
            sprintf_s(szSession, "Session%d", nProcs);
            AutoLoginDebug(szSession);
            GetPrivateProfileString(szSession, "StationName", 0, szStationName, 64, INIFileName);
            GetPrivateProfileString(szSession, "Password", 0, szPassword, 64, INIFileName);
            GetPrivateProfileString(szSession, "Server", 0, szServerName, 32, INIFileName);
            GetPrivateProfileString(szSession, "Character", 0, szCharacterName, 64, INIFileName);
		} else {
			if(char *pLogin = GetLoginName())
            {
				strcpy_s(szStationName, pLogin);
                GetPrivateProfileString(szStationName, "Password", 0, szPassword, 64, INIFileName);
                GetPrivateProfileString(szStationName, "Server", 0, szServerName, 32, INIFileName);
                GetPrivateProfileString(szStationName, "Character", 0, szCharacterName, 64, INIFileName);
            }
		}
		if(!dwServerID || dwServerID==-1 && EQADDR_SERVERNAME[0]) {
			CHAR szServTemp[MAX_STRING] = { 0 };
			strcpy_s(szServTemp, EQADDR_SERVERNAME);
			DWORD lserver = 0;
			dwServerID = GetServerID(szServTemp);
			if (szServerName[0]) {
				lserver = GetServerID(szServerName);
			}
			if (lserver != dwServerID) {
				dwServerID = lserver;
				bSwitchServer = true;
			}
			if (szCharacterName[0]=='\0' && pCharSpawn && ((PSPAWNINFO)pCharSpawn)->Name[0]) {
				strcpy_s(szCharacterName, ((PSPAWNINFO)pCharSpawn)->Name);
			}
		}
	}
}

void RemoveLoginPulse()
{
	if (Login__Pulse_x) {
		if (!IsBadReadPtr((PVOID)Login__Pulse_x, 4)) {
			RemoveDetour(Login__Pulse_x);
			Login__Pulse_x = 0;
		}
		else {
			DeleteDetour(Login__Pulse_x);
			Login__Pulse_x = 0;
		}
	}
	if (dwEQMainBase)
		dwEQMainBase = 0;
	bGotOffsets = false;
    bEnd = false;
}

PLUGIN_API VOID ShutdownPlugin(VOID)
{
	RemoveLoginPulse();
	RemoveCommand("/switchserver");
	RemoveCommand("/switchcharacter");
	RemoveCommand("/relog");
    
    if( gppi )
        RemoveDetour( gppi );
    if( gpps )
        RemoveDetour( gpps );
    if( wpps )
        RemoveDetour( wpps );
	LoginReset();
}

PLUGIN_API VOID SetGameState(DWORD GameState)
{
    bEndAfterCharSelect = GetPrivateProfileInt( "Settings", "EndAfterCharSelect", 0, INIFileName ) == 1;

	if (GameState == GAMESTATE_PRECHARSELECT) 
    {
		if (GetModuleHandle("eqmain.dll")) 
        {
			//well well well... what do u know... it's loaded...
			//ok fine that means we wont get any frontload notification, so lets fake it
			if(!Login__Pulse_x)
				AddOurPulse();
		}
	}
	if (GameState == GAMESTATE_POSTFRONTLOAD) 
    {
		//we know eqmain.dll is loaded now...
		if(!Login__Pulse_x)
			AddOurPulse();
	} else if(GameState == GAMESTATE_CHARSELECT) 
    {
		RemoveLoginPulse();
		if (dwServerID) {
			dwServerID = 0;
			if (!bSwitchChar) {
				strcpy_s(szNewChar, szCharacterName);
				bSwitchChar = true;
			}
		}
    }
    else if(GameState == GAMESTATE_INGAME)
    {
		RemoveLoginPulse();
        bInGame = true;
    }
}

PLUGIN_API VOID OnPulse(VOID)
{
	//ok since in game pulse starts at charselect we can use that for charswitching and serverswithcing as well as relog...
    if( !bLogin && GetAsyncKeyState( VK_HOME ) & 1 )
    {
        WriteChatf( "\agHOME key pressed. AutoLogin Re-Enabled.", szNewChar );
        bEndAfterCharSelect = false;
        bLogin = true;
        return;
    }

    if (GetGameState() == GAMESTATE_CHARSELECT) {
		if(dwTime && szNewChar[0] && GetAsyncKeyState(VK_END) & 1)
        {
            WriteChatf("END key pressed. Login of %s aborted.",szNewChar);
			szNewChar[0] = 0;
			dwTime = 0;
			switchTime = 0;
            return;
        }
		if (bSwitchServer) 
        {
            // world -> char select
			AutoLoginDebug("SetGameState(GAMESTATE_CHARSELECT): bSwitchServer = true");
			DWORD pCharSelect = *(DWORD*)pinstCCharacterSelect;
			((CCharacterSelect *)pCharSelect)->Quit();
			return;
		}
		if (bSwitchChar) 
        {
            //we have to give the chatwindow time to show up at char select... so we wait a couple seconds...
			switchTime = MQGetTickCount64() + 2000;
			bSwitchChar = false;
			return;
		}
		if (switchTime && switchTime <= MQGetTickCount64() && szNewChar[0] != '\0' ) 
        {
            //ok at this point the user has 3 seconds to read the message and abort.
			WriteChatf("Selecting \ag%s\ax in 3 seconds. please Wait... or press the END key to abort", szNewChar);
			switchTime = 0;
			dwTime = MQGetTickCount64() + 3000;
            SelectCharacter( szNewChar );
			return;
		}
		if (szNewChar[0] != '\0' && dwTime && dwTime <= MQGetTickCount64())
		{
			SwitchCharacter(szNewChar);
			szNewChar[0] = 0;
			dwTime = 0;
		}
        if( !szNewChar || szNewChar[0] == '\0' && bEndAfterCharSelect && bLogin )
        {
            bLogin = false;
            WriteChatf( "\ayAutologin now ended... press HOME to Re-Enable.", szNewChar );
        }
	}
}

void SwitchCharacter(char *szName)
{
	if (szName && szName[0] != '\0') {
		if (CXWnd*pWnd = FindMQ2Window("CLW_CharactersScreen")) {
			if (CListWnd *charlist = (CListWnd *)pWnd->GetChildItem("Character_List")) {
				if (charlist->Items) {
					CXStr Str;
					int column = 2;
					for (int i = 0; i < charlist->Items; i++) {
						charlist->GetItemText(&Str, i, column);
						CHAR szOut[255] = { 0 };
						GetCXStr(Str.Ptr, szOut, 254);
						if (szOut[0] != '\0') {
							if (!_stricmp(szName, szOut)) {
								DWORD pCharSelect = *(DWORD*)pinstCCharacterSelect;
								((CCharacterSelect *)pCharSelect)->SelectCharacter(i, 1, 1);
								((CCharacterSelect *)pCharSelect)->EnterWorld();
                                
                                if( bEndAfterCharSelect ) bLogin = false;

								return;
							}
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

void SelectCharacter( char *szName )
{
    if( szName && szName[0] != '\0' ) {
        if( CXWnd*pWnd = FindMQ2Window( "CLW_CharactersScreen" ) ) {
            if( CListWnd *charlist = (CListWnd *)pWnd->GetChildItem( "Character_List" ) ) {
                if( charlist->Items ) {
                    CXStr Str;
                    int column = 2;
                    for( int i = 0; i < charlist->Items; i++ ) {
                        charlist->GetItemText( &Str, i, column );
                        CHAR szOut[255] = { 0 };
                        GetCXStr( Str.Ptr, szOut, 254 );
                        if( szOut[0] != '\0' ) {
                            if( !_stricmp( szName, szOut ) ) {
                                DWORD pCharSelect = *(DWORD*)pinstCCharacterSelect;
                                ((CCharacterSelect *)pCharSelect)->SelectCharacter( i, 1, 1 );
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        AutoLoginDebug( "SwitchCharacter failed" );
        WriteChatf( "\arUsage\ax /switchcharacter \ay<name>\ax" );
    }
}

inline bool WindowActive(char *name)
{
	if (dwEQMainBase) {
		if (WindowMap.find(name) != WindowMap.end()) {
			if (CXWnd2 *pWnd = WindowMap[name]) {
				if (pWnd->dShow && pWnd->Enabled) {
					return true;
				}
			}
		}
	}
	return false;
}
bool bWait = false;
bool bServerWait = false;
void HandleWindows()
{
    if( !bLogin )
    {
        return;
    }

	CXWnd *pWnd = 0;
	if (WindowActive("OrderWindow"))
	{
		if (pWnd = WindowMap["OrderWindow"]->_GetChildItem("Order_DeclineButton"))
			pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
	} else if (WindowActive("EulaWindow"))
	{
		if (pWnd = WindowMap["EulaWindow"]->_GetChildItem("EULA_AcceptButton"))
			pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
	}
	else if (WindowActive("seizurewarning"))
	{
		if (pWnd = WindowMap["seizurewarning"]->_GetChildItem("HELP_OKButton"))
			pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
	}
	else if (WindowActive("OrderExpansionWindow"))
	{
		if (pWnd = WindowMap["OrderExpansionWindow"]->_GetChildItem("OrderExp_DeclineButton"))
		{
			AutoLoginDebug("clicking OrderExp_DeclineButton");
			pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
		}
	}
	else if (WindowActive(SPLASH))
	{
		CXPoint pt;
		pt.A = 1;
		pt.B = 1;
		pLoginViewManager->SendLMouseClick(pt); // WndNotification doesn't work on this
	}
	else if (WindowActive("main"))
	{
		if (pWnd = WindowMap["main"]->_GetChildItem("MAIN_ConnectButton")) {
			//this clicks the Login Button on the main page so we get the username and password page
			pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
		}
	}
	else if (WindowActive("connect"))
	{
		if (WindowActive("okdialog"))
		{
			bServerWait = false;
			if (pWnd = WindowMap["okdialog"]->_GetChildItem("OK_Display"))
			{	
				char szTemp[MAX_STRING * 8] = { 0 };
				if (((CXWnd2*)pWnd)->GetType() == UI_STMLBox)
					GetCXStr(((CSidlScreenWnd*)pWnd)->SidlText, szTemp, MAX_STRING * 8);
				else
					GetCXStr(((CSidlScreenWnd*)pWnd)->WindowText, szTemp, MAX_STRING * 8);
				if (szTemp[0] && strstr(szTemp, "Logging in to the server.  Please wait...."))
				{
					return;
				}
				bGotOffsets = false;
				ullerrorwait = MQGetTickCount64() + 2000;//we give the server 5 seconds to catch its breath...
				if (szTemp[0] && strstr(szTemp, "The server requires that you logout and log back in before proceeding.  Please do so.")) {
					pWnd = WindowMap["okdialog"]->_GetChildItem("OK_OKButton");
					if (pWnd)
						pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
					return;
				} else if (szTemp[0] && strstr(szTemp, "failed login attempts on your account since the last time you logged in")) {
					pWnd = WindowMap["okdialog"]->_GetChildItem("OK_OKButton");
					if (pWnd)
						pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
					return;
				} else if (szTemp[0] && strstr(szTemp, "The Login Server is currently unavailable.  Please try again later.")) {
					pWnd = WindowMap["okdialog"]->_GetChildItem("OK_OKButton");
					if (pWnd)
						pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
					return;
				} else if (szTemp[0] && strstr(szTemp, "Cannot login to the EverQuest server")) {
					pWnd = WindowMap["okdialog"]->_GetChildItem("OK_OKButton");
					if (pWnd)
						pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
					return;
				} else if (szTemp[0] && strstr(szTemp, "password were not valid")) {
					AutoLoginDebug(szTemp);
					bLogin = false;
					return;
				} else if (szTemp[0] && strstr(szTemp, "A timeout occurred")) {
					pWnd = WindowMap["okdialog"]->_GetChildItem("OK_OKButton");
					if (pWnd)
						pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
					return;
				} else if (szTemp[0] && strstr(szTemp, "This login requires that the account be activated.  Please make sure your account is active in order to login.")) {
					AutoLoginDebug(szTemp);
					bLogin = false;
					return;
				} else if (szTemp[0] && strstr(szTemp, "You have a character logged into a world server as an OFFLINE TRADER from this account")) {
					pWnd = WindowMap["okdialog"]->_GetChildItem("YESNO_YesButton");
					if (pWnd)
						pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
					return;
				} else if (szTemp[0] && strstr(szTemp, "A connection to the server could not be reached.")) {
					pWnd = WindowMap["okdialog"]->_GetChildItem("OK_OKButton");
					if (pWnd)
						pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
					return;
				}
			}
			return;
		}
		if (pWnd = WindowMap["connect"]->_GetChildItem("LOGIN_PasswordEdit"))
		{
			CHAR szTempPass[MAX_STRING] = { 0 };
			GetCXStr(((CSidlScreenWnd*)pWnd)->InputText, szTempPass, MAX_STRING);
			if (szTempPass[0] == '\0')
				bWait = false;
		}
		if (bWait)
			return;
		if (pWnd = WindowMap["connect"]->_GetChildItem("LOGIN_UsernameEdit")) {
			if (bUseMQ2Login) {
				AutoLoginDebug("HandleWindows(): Using MQ2Login Method");
				GetCXStr(((CSidlScreenWnd*)pWnd)->InputText, szStationName, 64);
				if (szStationName[0]) {
					if (char *pDest = strchr(szStationName, '_')) {
						//we have a mq2login user... good boy/girl :) welcome to 2016.
						pDest[0] = '\0';
						pDest++;
						sprintf_s(szCharacterName, "%s_Blob", pDest);
						CHAR szProfile[128] = { 0 };
						strcpy_s(szProfile, szCharacterName);
						if (char *pDest2 = strchr(szProfile, ':')) {
							pDest2[0] = '\0';
							strcpy_s(szServerName, szProfile);
						} else {
							strcpy_s(szServerName, szStationName);
						}
						//now that we have the server and the charname, we can figure out the stationname and password from the blob
						CHAR szBlob[2048] = { 0 };
						if (GetPrivateProfileString(szStationName, szCharacterName, "", szBlob, sizeof(szBlob), INIFileName)) {
							if (pDest = strrchr(szBlob, '=')) {
								pDest[0] = '\0';
							}
							DATA_BLOB db = { 0 };
							DATA_BLOB dbout = { 0 };
							if (StrToBlobA(szBlob, &db)) {
								if (DecryptData(&db, &dbout)) {
									if (char *thestring = (char*)dbout.pbData) {
										//we should parse out Login, CharName, Pass
										CHAR szTemp[2048] = { 0 };
										strcpy_s(szTemp, thestring);
										LocalFree(db.pbData);//always remember to free this (MSDN)
										LocalFree(dbout.pbData);//always remember to free this (MSDN)
										if (char *pDest = strchr(szTemp, ':')) {
											pDest[0] = '\0';
											strcpy_s(szStationName, szTemp);
											pDest++;
											if (pDest[0]) {
												strcpy_s(szTemp, pDest);
												if (pDest = strchr(szTemp, ':')) {
													pDest[0] = '\0';
													strcpy_s(szCharacterName, szTemp);
													pDest++;
													strcpy_s(szPassword, pDest);
												}
											}
										}
									}
								}
							}
						}
						DWORD oldscreenmode = ScreenMode;
						ScreenMode = 3;
						SetCXStr(&((CSidlScreenWnd*)pWnd)->InputText, "");
						SetCXStr(&((CSidlScreenWnd*)pWnd)->InputText, szStationName);
						ScreenMode = oldscreenmode;
					}
				}
			} else if(bUseStationNamesInsteadOfSessions) {
                AutoLoginDebug("HandleWindows(): Using station name instead of session number");

                GetCXStr(((CSidlScreenWnd*)pWnd)->InputText, szStationName, 64);

                if(szStationName[0])
                {
                    GetPrivateProfileString(szStationName, "Password", 0, szPassword, 64, INIFileName);
                    GetPrivateProfileString(szStationName, "Server", 0, szServerName, 32, INIFileName);
                    GetPrivateProfileString(szStationName, "Character", 0, szCharacterName, 64, INIFileName);
                }
                else
                {
                    AutoLoginDebug("HandleWindows(): No station name found in LOGIN_UsernameEdit");
                    bLogin = false;
                    return;
                }
            }
           
            if(!szStationName[0] || !szPassword[0] || !szServerName[0])
            {
                AutoLoginDebug("*** Login data couldn't be retrieved.  Please check your ini file.");
                bLogin = false;
                return;
            }

			if (bUseMQ2Login) {
				//dont need to do anything, we already done this.
			} else if (!bUseStationNamesInsteadOfSessions) {
				SetCXStr(&((CSidlScreenWnd*)pWnd)->InputText, "");
				SetCXStr(&((CSidlScreenWnd*)pWnd)->InputText, szStationName);
			}

			if(pWnd = WindowMap["connect"]->_GetChildItem("LOGIN_PasswordEdit"))
            {
                SetCXStr(&((CSidlScreenWnd*)pWnd)->InputText, szPassword);
				if (pWnd = WindowMap["connect"]->_GetChildItem("LOGIN_ConnectButton"))
				{
					DWORD oldscreenmode = ScreenMode;
					ScreenMode = 3;
					pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
					ScreenMode = oldscreenmode;
					bWait = true;
					return;
				}
            }
        }
    }
    else if(WindowActive("serverselect"))
    {
		if (bInGame)
			return;
		bWait = false;
		if (szPassword[0] == '\0') {
			GetPassword(szPassword);
		}
		if(WindowActive("okdialog"))
        {
         //MessageBox(NULL,"inject now 2","",MB_OK);
            if(pWnd = WindowMap["okdialog"]->_GetChildItem("OK_Display"))
            {
                char szTemp[MAX_STRING * 8] = {0};

                if(((CXWnd2*)pWnd)->GetType() == UI_STMLBox)
                    GetCXStr(((CSidlScreenWnd*)pWnd)->SidlText, szTemp, MAX_STRING * 8);
                else
                    GetCXStr(((CSidlScreenWnd*)pWnd)->WindowText, szTemp, MAX_STRING * 8);
				bGotOffsets = false;
				ullerrorwait = MQGetTickCount64() + 2000;//we give the server 5 seconds to catch its breath...

                if(szTemp[0] && strstr(szTemp, "The world server is currently at maximum capacity and not allowing further logins until the number of players online decreases.  Please try again later."))
                {
                    pWnd = WindowMap["okdialog"]->_GetChildItem("OK_OKButton");
                    if(pWnd)
                        pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
                } else if(szTemp[0] && strstr(szTemp, "That server is currently unavailable")) {
                    pWnd = WindowMap["okdialog"]->_GetChildItem("OK_OKButton");
                    if(pWnd)
                        pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
                } else if(szTemp[0] && strstr(szTemp, "An unknown error occurred while trying to join the server.")) {
                    pWnd = WindowMap["okdialog"]->_GetChildItem("OK_OKButton");
                    if(pWnd)
                        pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
                } else if(szTemp[0] && strstr(szTemp, "The connection has been terminated by the server.  Most likely you have been inactive")) {
                    pWnd = WindowMap["okdialog"]->_GetChildItem("OK_OKButton");
                    if(pWnd)
                        pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
                } else if (szTemp[0] && strstr(szTemp, "A timeout occurred")) {
					pWnd = WindowMap["okdialog"]->_GetChildItem("OK_OKButton");
					if (pWnd)
						pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
				}
            }
			bServerWait = false;
			return;
        } else if(WindowActive("yesnodialog"))
        {
            if(pWnd = WindowMap["yesnodialog"]->_GetChildItem("YESNO_Display"))
            {
                char szTemp[MAX_STRING * 8] = {0};

                if(((CXWnd2*)pWnd)->GetType() == UI_STMLBox)
                    GetCXStr(((CSidlScreenWnd*)pWnd)->SidlText, szTemp, MAX_STRING * 8);
                else
                    GetCXStr(((CSidlScreenWnd*)pWnd)->WindowText, szTemp, MAX_STRING * 8);

                // kick active character?
                if(szTemp[0] && strstr(szTemp, "You already have a character logged into a world server from this account."))
                {
                    if(bKickActiveChar)
                        pWnd = WindowMap["yesnodialog"]->_GetChildItem("YESNO_YesButton");
                    else
                        pWnd = WindowMap["yesnodialog"]->_GetChildItem("YESNO_NoButton");

                    if(pWnd)
                        pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
                    bLogin = false;
                }
            }
			bWait = false;
			bServerWait = false;
			return;
        } else if (!szServerName[0]) {
			AutoLoginDebug("HandleWindows(): szServerName NULL at serverselect.  Ending Login");
			bLogin = false;
			bEnd = true;
			return;
		} else {
			if (bServerWait)
				return;
			if (dwServerID = GetServerID(szServerName)) {
				pLoginClient->EnterGame(dwServerID);
				bSwitchServer = false;
				bServerWait = true;
			} else {
				AutoLoginDebug("HandleWindows(): GetServerID(%s) returned 0 at serverselect", szServerName);
			}
			return;
        }
    }
    else if(WindowActive("news"))
    {
        if(pWnd = WindowMap["news"]->_GetChildItem("NEWS_WndLabel"))
        {
            char szTemp[MAX_STRING] = {0};

            if(((CXWnd2*)pWnd)->GetType() == UI_STMLBox)
                GetCXStr(((CSidlScreenWnd*)pWnd)->SidlText,szTemp,MAX_STRING);
            else
                GetCXStr(((CSidlScreenWnd*)pWnd)->WindowText,szTemp,MAX_STRING);

            // click OK button if news window is open
            if(szTemp[0] && !strcmp(szTemp, "NEWS"))
            {
                if(pWnd = WindowMap["news"]->_GetChildItem("NEWS_OKButton"))
                {
                    pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
                }
            }
        }
    }
}

bool SetOffsets()
{
	//MessageBox(NULL, "About to find addresses", "Inject Now", MB_OK | MB_SYSTEMMODAL);
    if(dwLoginClient = _FindPattern(dwEQMainBase, 0x100000, lcPattern, lcMask))
    {
        dwLoginClient = _GetDWordAt(dwLoginClient, 1);
    }
    else
    {
        AutoLoginDebug("Error: !dwLoginClient");
        return false;
    }

    if(!(dwEnterGameAddr = _FindPattern(dwEQMainBase, 0x200000, lcEGPattern, lcEGMask)))
    {
        AutoLoginDebug("Error: !dwEnterGame");
        return false;
    }
    return true;
}

bool SetOffsetsUI()
{
	DWORD dwSidlMgr = 0, dwWndMgr = 0, dwLoginMgr = 0;

    if(!(dwGetXMLDataAddr = _FindPattern(dwEQMainBase, 0x100000, xmldataPattern, xmldataMask)))
    {
        AutoLoginDebug("Error: !dwGetXMLDataAddr");
        return false;
    }

    if(!(dwSendLMouseClickAddr = _FindPattern(dwEQMainBase, 0x100000, lmousePattern, lmouseMask)))
    {
        AutoLoginDebug("Error: !dwSendLMouseClickAddr");
        return false;
    }

    if(dwSidlMgr = _FindPattern(dwEQMainBase, 0x100000, swmPattern, swmMask))
    {
        dwSidlMgr = _GetDWordAt(dwSidlMgr, 1);
    }
    else
    {
        AutoLoginDebug("Error: !dwSidlMgr");
        return false;
    }

    if(dwWndMgr = _FindPattern(dwEQMainBase, 0x100000, xwmPattern, xwmMask))
    {
        dwWndMgr = _GetDWordAt(dwWndMgr, 2);
    }
    else
    {
        AutoLoginDebug("Error: !dwWndMgr");
        return false;
    }

    if(dwLoginMgr = _FindPattern(dwEQMainBase, 0x100000, lvmPattern, lvmMask))
    {
        dwLoginMgr = _GetDWordAt(dwLoginMgr, 1);
		dwServerInfo = dwLoginMgr - 4;
    }
    else
    {
        AutoLoginDebug("Error: !dwLoginMgr");
        return false;
    }

    while(!pSidlManager || !pWindowManager || !pLoginViewManager)
    {
        pSidlManager = (CSidlManager*)*(DWORD*)dwSidlMgr;
        pWindowManager = (PCXWNDMGR)*(DWORD*)dwWndMgr;
        pLoginViewManager = (CLoginViewManager*)*(DWORD*)dwLoginMgr;
        Sleep(100);
    }

    return true;
}

DWORD GetProcessCount(char *exeName)
{
    HANDLE hnd = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 proc;
    proc.dwSize = sizeof(PROCESSENTRY32);
    DWORD n = 0;

    if(Process32First(hnd, &proc))
    {
        do
        {
            if(!_stricmp(proc.szExeFile, exeName))
                n++;
        }
        while(Process32Next(hnd, &proc));
    }

    CloseHandle(hnd);

    return n;
}

inline void LoginReset()
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
void DebugLog(char *szFormat, ...)
{
   char szOutput[512] = {0};
    char szTmp[512] = {0};
    va_list vaList;

   if(FILE *fLog = fopen(DBG_LOGFILE_PATH, "a"))
   {
        va_start(vaList, szFormat);
        vsprintf(szTmp, szFormat, vaList);
       
        time_t CurTime;
        time(&CurTime);
        tm *pTime = localtime(&CurTime);
        sprintf_s(szOutput, "[%02d/%02d/%04d %02d:%02d:%02d] ", pTime->tm_mon+1, pTime->tm_mday, pTime->tm_year+1900, pTime->tm_hour, pTime->tm_min, pTime->tm_sec);
        strcat_s(szOutput, szTmp);

      fprintf(fLog, "%s\n", szOutput);
      fclose(fLog);
   }
}
#endif

// originally created by: radioactiveman/bunny771/(dom1n1k?) of GameDeception -----------
inline bool _DataCompare(const unsigned char* pData, const unsigned char* bMask, const char* szMask)
{
    for(;*szMask;++szMask,++pData,++bMask)
        if(*szMask=='x' && *pData!=*bMask )
            return false;
    return (*szMask) == 0;
}

unsigned long _FindPattern(unsigned long dwAddress,unsigned long dwLen,unsigned char *bPattern,char * szMask)
{
    for(unsigned long i=0; i < dwLen; i++)
        if(_DataCompare( (unsigned char*)( dwAddress+i ),bPattern,szMask) )
            return (unsigned long)(dwAddress+i);
   
    return 0;
}
// --------------------------------------------------------------------------------------

// ieatacid - 3/11/09
unsigned long _GetDWordAt(unsigned long address, unsigned long numBytes)
{
    if(address)
    {
        address += numBytes;
        if(*(unsigned long*)address)
            return *(unsigned long*)address;
    }
    return 0;
}

// ieatacid - 3/11/09
unsigned long _GetFunctionAddressAt(unsigned long address, unsigned long addressOffset, unsigned long numBytes)
{
    if(address)
    {
        unsigned long n = *(unsigned long*)(address + addressOffset);
        return address + n + numBytes;
    }
    return 0;
}
