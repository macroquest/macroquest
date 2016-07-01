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
PLUGIN_VERSION(2.2);
#include <map>
#include <tlhelp32.h>
PreSetup("MQ2AutoLogin");
#include <wincrypt.h>
#pragma comment( lib, "Crypt32.lib" )

bool oktologin = false;
HANDLE hthisisatest = 0;
HANDLE hLoginThread = 0;

#define CurrCharSelectChar 0x38E80 // see .text:004419A0                 cmp     eax, [ecx+38E80h] in eqgame.exe dated apr 28 2015
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
bool bLogin = false;
bool bInGame = false;
bool bSwitchServer = false;
char szStationName[64] = {0};
char szPassword[64] = {0};
char szServerName[32] = {0};
char szCharacterName[64] = {0};
char szNewChar[0x40] = {0};
ULONGLONG dwTime = 0;
map<string, class CXWnd2 *> WindowMap;


// this changes frequently so it needs to be done this way
#define pLoginClient ((CLoginClient*)*(DWORD*)dwLoginClient)


bool SetOffsets();
bool SetOffsetsUI();
void HandleWindows();
void LoginReset();
bool FindCharacter(char *szName);
void SwitchCharacter(char *szName);
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

PBYTE lcEGPattern = (PBYTE)"\x55\x8B\xEC\x6A\xFF\x68\x00\x00\x00\x00\x64\xA1\x00\x00\x00\x00\x50\x83\xEC\x34\x53\x56\xA1\x00\x00\x00\x00\x33\xC5\x50\x8D\x45\xF4\x64\xA3\x00\x00\x00\x00\x8B\xF1\x33\xDB\xC7\x45\x00\x00\x00\x00\x00\xC7\x45\x00\x00\x00\x00\x00\x89\x5D\xEC\x89\x5D\xE8\x8D\x45\xE0\x50\x89\x5D\xFC\xE8\x00\x00\x00\x00\x8D\x4D\xF0\x51\xE8\x00\x00\x00\x00\x83\xC4\x08\x8D\x4D\xC0\xE8\x00\x00\x00\x00\x8B\x45\xE4\x8B\x55\x08\x50\x8D\x4D\xD8\xC6\x45\xFC\x01\x89\x55\xD4\xE8\x00\x00\x00\x00\x8B\x4D\xF0\x8B\x55\x10\x8B\x45\x0C\x52\x89\x4D\xDC\x50\x8D\x4D\xC0\x51\x8B\xCE\xE8\x00\x00\x00\x00\x8D\x4D\xC0\x8B\xF0\x88\x5D\xFC\xE8\x00\x00\x00\x00\xC7\x45\x00\x00\x00\x00\x00\xC7\x45\x00\x00\x00\x00\x00\x39\x5D\xEC\x7E\x20\x8B\x45\xE4\x83\xC0\xFC\x8B\xD0\x83\xC9\xFF\xF0\x0F\xC1\x0A\x49\x85\xC9\x7F\x0C\x8B\x55\xE0\x50\x8B\x42\x08\x8D\x4D\xE0\xFF\xD0\x8B\xC6\x8B\x4D\xF4\x64\x89\x0D\x00\x00\x00\x00\x59\x5E\x5B\x8B\xE5\x5D\xC2\x0C\x00";
char lcEGMask[] = "xxxxxx????xx????xxxxxxx????xxxxxxxx????xxxxxx?????xx?????xxxxxxxxxxxxxx????xxxxx????xxxxxxx????xxxxxxxxxxxxxxxxxx????xxxxxxxxxxxxxxxxxxxxx????xxxxxxxxx????xx?????xx?????xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx????xxxxxxxxx";

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
        if (GetCXStr(pXMLData->Name.Ptr,Buffer,MAX_STRING) && !stricmp(Buffer,Name)) {
            return pWnd;
        }
        //AutoLoginDebug("RecurseAndFindName looking for %s but found %s", Name, Buffer);
        if (GetCXStr(pXMLData->ScreenID.Ptr,Buffer,MAX_STRING) && !stricmp(Buffer,Name)) {
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

DWORD WINAPI LoginThread(LPVOID lpParam)
{
    WaitForInputIdle(GetCurrentProcess(), 60000);
    bool bOffsets = false;

    if(bSwitchServer && dwServerID) // char select -> server select
    {
        AutoLoginDebug("bSwitchServer && dwServerID");

        while(!dwEQMainBase) // eqmain isn't loaded
            Sleep(500);

        AutoLoginDebug("bSwitchServer && dwServerID, before SetOffsets()");

        if(SetOffsets())
        {
            ULONGLONG n = MQGetTickCount64() + 5000; // wait 5 seconds
            while(n > MQGetTickCount64())
                Sleep(500);

            AutoLoginDebug("bSwitchServer && dwServerID, calling EnterGame");

            pLoginClient->EnterGame(dwServerID);

            bSwitchServer = false;
        }

        hLoginThread = 0;
        return 0;
    }

    while(bLogin)
    {
        Sleep(100);

        if(GetAsyncKeyState(VK_END) & 1)
        {
            AutoLoginDebug("User pressed END key.  Killing login thread");
            hLoginThread = 0;
            return 0;
        }

        if(!dwEQMainBase) // eqmain isn't loaded
        {
            AutoLoginDebug("bLogin loop: waiting for eqmain");

            if(bOffsets) // server select -> character select
            {
                AutoLoginDebug("bLogin loop: ending LoginThread (server select -> char select)");
                LoginReset();
				hLoginThread = 0;
                return 0;
            }

            Sleep(1000);
            continue;
        }

        if((dwEQMainBase = (DWORD)GetModuleHandle("eqmain.dll"))==0) 
        {
            bOffsets = false;
            pWindowManager=0;
            hLoginThread = 0;
            return 0;
        }

        if(!bOffsets)
        {
            AutoLoginDebug("bLogin loop: Setting up offsets");
            WaitForInputIdle(GetCurrentProcess(), 60000);
            while (!dwEQMainBase) // eqmain isn't loaded
            {
                Sleep(100);
            }

            if(!SetOffsets())
            {
                AutoLoginDebug("bLogin loop: Error in SetOffsets()");
				hLoginThread = 0;
                return 0;
            }

            if(!SetOffsetsUI())
            {
                AutoLoginDebug("bLogin loop: Error in SetOffsetsUI()");
				hLoginThread = 0;
                return 0;
            }

            bOffsets = true;
        }

        AutoLoginDebug("bLogin loop: waiting for window data");
      
        // wait for window data to be populated
        int iFailures = 0;
        bool bReady = false;
        PCSIDLWND* ppWnd = NULL;
        CHAR Name[MAX_STRING] = { 0 };

        while (!bReady)
        {
            if (iFailures++ > 10000)
            {
                AutoLoginDebug("bLogin loop: Failed way too much waiting for window data.  Bailing.");
                hLoginThread = 0;
                return 0;
            }

            WaitForInputIdle(GetCurrentProcess(), 60000);

            while (!pWindowManager)
            {
                Sleep(1000);
            }
            
            while (IsBadReadPtr(pWindowManager, 4))
            {
                Sleep(1000);
            }

            if (pWindowManager && pWindowManager->Count < MAX_WINDOWS)
            {
                continue;
            }

            WaitForInputIdle(GetCurrentProcess(), 60000);

            if (IsBadReadPtr(pWindowManager, 4))
            {
                hLoginThread = 0;
                return 0;
            }
            
            ppWnd = pWindowManager->pWindows;
            
            if (!ppWnd)
            {
                //MessageBox(NULL, "break in", "ppWnd was NULL", MB_SYSTEMMODAL | MB_OK);
                Sleep(500);
                continue;
            }
            if (IsBadReadPtr(ppWnd, 4))
            {
                //MessageBox(NULL, "break in", "ppWnd was not NULL but was unreadable crash avoided.", MB_SYSTEMMODAL | MB_OK);
                Sleep(500);
                continue;
            }
            if ((!*ppWnd) || IsBadReadPtr(*ppWnd, 4))
            {
                //MessageBox(NULL, "break in", "ppWnd was NULL", MB_SYSTEMMODAL | MB_OK);
                Sleep(500);
                continue;
            }

            bReady = true;

        }
        PCSIDLWND pWnd=*ppWnd;

        DWORD count = pWindowManager->Count;

        while(pWnd = *ppWnd)
        {
            if(count-- == 0)
                break;

            if(CXMLData *pXMLData=((CXWnd2*)pWnd)->GetXMLData())
            {
                GetCXStr(pXMLData->Name.Ptr, Name, MAX_STRING);

                if(Name[0])
                {
                    AutoLoginDebug("bLogin loop: adding window '%s'", Name);
                    WindowMap[Name] = (CXWnd2*)pWnd;
                }
            }

            ppWnd++;
        }
        AutoLoginDebug("bLogin loop: call HandleWindows()");
        HandleWindows();
        WaitForInputIdle(GetCurrentProcess(), 60000);
    }

    AutoLoginDebug("LoginThread finished");
    LoginReset();
	hLoginThread = 0;
    return 0;
}

DWORD GetServerID(char *szName)
{
    for(DWORD n = 0; ServerData[n].ID; n++)
    {
        if(!stricmp(szName, ServerData[n].Name))
        {
            return ServerData[n].ID;
        }
    }
    return 0;
}

void Cmd_SwitchServer(PSPAWNINFO pChar, char *szLine)
{
    char szServer[MAX_STRING] = {0};
    char szCharacter[MAX_STRING] = {0};

    GetArg(szServer, szLine, 1);
    GetArg(szCharacter, szLine, 2);

    if(szServer[0] && szCharacter[0])
    {
        if(dwServerID = GetServerID(szServer))
        {
            strcpy(szCharacterName, szCharacter);
            bSwitchServer = true;

            if(pChar->StandState == STANDSTATE_FEIGN)
            {
                // using DoMappable here doesn't create enough of a delay for camp to work
                EzCommand("/stand");
            }
            EzCommand("/camp");

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
                    strcat(szServers, ", ");
                strcat(szServers, ServerData[n].Name);
            }
           
            WriteChatColor(szServers);
            return;
        }
    }

    WriteChatf("\ayUsage:\ax /switchserver <server short name> <character name>");
}

void Cmd_SwitchCharacter(PSPAWNINFO pChar, char *szLine)
{
    char szArg1[MAX_STRING] = {0};
    char szArg2[MAX_STRING] = {0};

    if(szLine[0])
    {
        GetArg(szArg1, szLine, 1);
        GetArg(szArg2, szLine, 2);

        if(GetGameState() == GAMESTATE_INGAME)
        {
            if(stricmp(szArg1, pChar->DisplayedName))
            {
                strcpy(szNewChar, szArg1);

                if(pChar->StandState == STANDSTATE_FEIGN)
                {
                    // using DoMappable here doesn't create enough of a delay for camp to work
                    EzCommand("/stand");
                }
                EzCommand("/camp");
            }
            else
            {
                WriteChatf("\ayYou're already logged onto '%s'\ax", szArg1);
            }

        }
        else if(GetGameState() == GAMESTATE_CHARSELECT)
        {
            SwitchCharacter(szLine);
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

        strcpy(szNewChar, pChar->DisplayedName);

        if(dwTime)
            dwTime += 30000; // add 30 seconds for camp time

        if(pChar->StandState == STANDSTATE_FEIGN)
        {
            // using DoMappable here doesn't create enough of a delay for camp to work
            EzCommand("/stand");
        }
        EzCommand("/camp");
    }
}
PLUGIN_API VOID SetGameState(DWORD GameState);
BOOL firstrun=0;
PLUGIN_API VOID InitializePlugin(VOID)
{
    AddCommand("/switchserver", Cmd_SwitchServer);
    AddCommand("/switchcharacter", Cmd_SwitchCharacter);
    AddCommand("/relog", Cmd_Relog);

    char szPath[MAX_PATH];
    GetPrivateProfileStringA("Settings", "IniLocation", 0, szPath, MAX_PATH, INIFileName);
    if(szPath[0])
        strcpy(INIFileName, szPath);

    bKickActiveChar = GetPrivateProfileInt("Settings", "KickActiveCharacter", 1, INIFileName);
    bUseMQ2Login = GetPrivateProfileInt("Settings", "UseMQ2Login", 0, INIFileName);
    bUseStationNamesInsteadOfSessions = GetPrivateProfileInt("Settings", "UseStationNamesInsteadOfSessions", 0, INIFileName);
    bReLoggin = GetPrivateProfileInt("Settings", "LoginOnReLoadAtCharSelect", 0, INIFileName);

#ifdef AUTOLOGIN_DBG
    remove(DBG_LOGFILE_PATH);
#endif
	//force a check if user loads us at charselect for example...
	if(GetGameState() == GAMESTATE_CHARSELECT && bReLoggin)
    {
        DWORD nProcs = GetProcessCount("eqgame.exe");
		if (bUseMQ2Login) {
			//i dont think we need to load anything here
			/*if (char *pLogin = GetLoginName()) {
				strcpy_s(szStationName, pLogin);
				if (EQADDR_SERVERNAME && EQADDR_SERVERNAME[0]) {
					//CHAR szName[64] = { 0 };
					//sprintf_s(szName,"_Blob",)
					//GetPrivateProfileString(EQADDR_SERVERNAME, "Password", 0, szPassword, 64, INIFileName);
				}
			}*/
		} else if (!bUseStationNamesInsteadOfSessions) {
            char szSession[32];
               
            sprintf(szSession, "Session%d", nProcs);
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
		if(!dwServerID && EQADDR_SERVERNAME[0]) {
			DWORD lserver = 0;
			dwServerID = GetServerID(EQADDR_SERVERNAME);
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
	SetGameState(GetGameState());
}

PLUGIN_API VOID ShutdownPlugin(VOID)
{
    RemoveCommand("/switchserver");
    RemoveCommand("/switchcharacter");
    RemoveCommand("/relog");
    LoginReset();
}
DWORD __stdcall thisisatest(PVOID pData)
{
loop:
	DWORD gs = GetGameState();
	if(gs==GAMESTATE_PRECHARSELECT) {
		dwEQMainBase = (DWORD)GetModuleHandle("eqmain.dll");
		if(!dwEQMainBase) {
			Sleep(1000);
			goto loop;
		}
		//Sleep(5000);
	}
	WaitForInputIdle(GetCurrentProcess(), 60000);
	oktologin = true;
	SetGameState((DWORD)pData);
	return 0;
}

PLUGIN_API VOID SetGameState(DWORD GameState)
{
	if (firstrun == 0) {
		//MessageBox(NULL, "Inject now", "", MB_SYSTEMMODAL | MB_OK);
		DWORD nThreadID = 0;
		firstrun = 1;
		hthisisatest = CreateThread(NULL, 0, thisisatest, (PVOID)GameState, NULL, &nThreadID);
		return;
	}
    if(GetGameState() == GAMESTATE_PRECHARSELECT && oktologin)
    {
		
        static DWORD threadID = 0;

        if(!bInGame && !threadID)
        {
            AutoLoginDebug("SetGameState(GAMESTATE_PRECHARSELECT): !bInGame");
            DWORD nProcs = GetProcessCount("eqgame.exe");
            AutoLoginDebug("SetGameState(GAMESTATE_PRECHARSELECT) nProcs=%d", nProcs);

			if (bUseMQ2Login) {

			} else if(!bUseStationNamesInsteadOfSessions) {
                char szSession[32];
               
                sprintf(szSession, "Session%d", nProcs);
                AutoLoginDebug(szSession);

                GetPrivateProfileString(szSession, "StationName", 0, szStationName, 64, INIFileName);
                GetPrivateProfileString(szSession, "Password", 0, szPassword, 64, INIFileName);
                GetPrivateProfileString(szSession, "Server", 0, szServerName, 32, INIFileName);
                GetPrivateProfileString(szSession, "Character", 0, szCharacterName, 64, INIFileName);
            }

            AutoLoginDebug("SetGameState(GAMESTATE_PRECHARSELECT): creating LoginThread (bLogin = true)");
            bLogin = true;
			if(!hLoginThread) {
				hLoginThread = CreateThread(0, 0, &LoginThread, 0, 0, &threadID);
			}
        }
        else if(bInGame && dwServerID)
        {
            AutoLoginDebug("SetGameState(GAMESTATE_PRECHARSELECT): creating LoginThread (dwServerID != 0)");
            if(!hLoginThread) {
				hLoginThread = CreateThread(0, 0, &LoginThread, 0, 0, &threadID);
			}
        }
    }
    else if(GetGameState() == GAMESTATE_CHARSELECT)
    {
        if(dwServerID)
        {
            if(bSwitchServer) // world -> char select
            {
                AutoLoginDebug("SetGameState(GAMESTATE_CHARSELECT): bSwitchServer = true");
                ExecuteCmd(nEQMappableCommands - 5, 1, 0); // quit
            }
            else // server select -> char select
            {
                AutoLoginDebug("SetGameState(GAMESTATE_CHARSELECT): bSwitchServer = false");
               
                dwServerID = 0;
               
                if(szCharacterName[0])
                {
                    Sleep(1000);
                    AutoLoginDebug("SetGameState(GAMESTATE_CHARSELECT): logging in");
                    SwitchCharacter(szCharacterName);
                }
                else
                    AutoLoginDebug("SetGameState(GAMESTATE_CHARSELECT): szCharacterName NULL");
            }
        }
        else if(szNewChar && szNewChar[0] && !dwTime)
        {
            AutoLoginDebug("SetGameState(GAMESTATE_CHARSELECT): calling SwitchCharacter");
            SwitchCharacter(szNewChar);
            szNewChar[0] = 0;
        }
    }
    else if(GetGameState() == GAMESTATE_INGAME)
    {
        bInGame = true;
    }
}

PLUGIN_API VOID OnPulse(VOID)
{
    if(dwTime && GetGameState() == GAMESTATE_CHARSELECT && dwTime <= MQGetTickCount64())
    {
        SwitchCharacter(szNewChar);
        szNewChar[0] = 0;
        dwTime = 0;
    }
}

bool FindCharacter(char *szName)
{
    if(pCharSpawn && ((PSPAWNINFO)pCharSpawn)->Name[0])
    {
        DWORD x = *(DWORD*)(((char*)pEverQuest)+CurrCharSelectChar);
        DWORD i = 0;
        do
        {
            if(!stricmp(((PSPAWNINFO)pCharSpawn)->Name, szName))
                return true;

            SendListSelect("CLW_CharactersScreen", "Character_List", i);
            Sleep(100);
        }
        while(i++ < x);
    }
    AutoLoginDebug("FindCharacter returning false");
    return false;
}

void SwitchCharacter(char *szName)
{
    if(FindCharacter(szName))
        ExecuteCmd(nEQMappableCommands - 4, 1, 0);
    else
    {
        AutoLoginDebug("FindCharacter(%s) failed", szName);
        WriteChatf("\arError:\ax FindCharacter(\ay%s\ax) failed", szName);
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
bool bOnce = true;
void HandleWindows()
{
	CXWnd *pWnd = 0;
	if (WindowActive("EulaWindow"))
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
	else if (WindowActive("dbgsplash"))
	{
		CXPoint pt;
		pt.A = 1;
		pt.B = 1;
		pLoginViewManager->SendLMouseClick(pt); // WndNotification doesn't work on this
	}
	else if (WindowActive("main"))
	{
		if (pWnd = WindowMap["main"]->_GetChildItem("MAIN_ConnectButton"))
			pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
	}
	else if (WindowActive("connect"))
	{
		if (WindowActive("okdialog"))
		{
			//MessageBox(NULL,"inject now 1","",MB_OK);
			if (pWnd = WindowMap["okdialog"]->_GetChildItem("OK_Display"))
			{
				char szTemp[MAX_STRING * 8] = { 0 };

				if (((CXWnd2*)pWnd)->GetType() == UI_STMLBox)
					GetCXStr(((CSidlScreenWnd*)pWnd)->SidlText, szTemp, MAX_STRING * 8);
				else
					GetCXStr(((CSidlScreenWnd*)pWnd)->WindowText, szTemp, MAX_STRING * 8);

				//0x08ad6bac "The server requires that you logout and log back in before proceeding.  Please do so."
				if (szTemp[0] && strstr(szTemp, "Logging in to the server.  Please wait...."))
				{
					return;
				}
				WaitForInputIdle(GetCurrentProcess(), 60000);
				if (szTemp[0] && strstr(szTemp, "The server requires that you logout and log back in before proceeding.  Please do so.")) {
					pWnd = WindowMap["okdialog"]->_GetChildItem("OK_OKButton");
					if (pWnd)
						pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
					return;
				}
				bOnce = true;
			}
		}
		if (!bOnce)
			return;
		if (pWnd = WindowMap["connect"]->_GetChildItem("LOGIN_UsernameEdit"))
		{
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
						WaitForInputIdle(GetCurrentProcess(), 60000);
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
					WaitForInputIdle(GetCurrentProcess(), 60000);
					pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
					ScreenMode = oldscreenmode;
					bOnce = false;
				}
            }
        }
    }
    else if(WindowActive("serverselect"))
    {
		if (!szServerName[0])
		{
			AutoLoginDebug("HandleWindows(): szServerName NULL at serverselect.  Ending LoginThread");
			bLogin = false;
			return;
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

                if(szTemp[0] && strstr(szTemp, "The world server is currently at maximum capacity and not allowing further logins until the number of players online decreases.  Please try again later."))
                {
                    pWnd = WindowMap["okdialog"]->_GetChildItem("OK_OKButton");
                    if(pWnd)
                        pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
                } else if(szTemp[0] && strstr(szTemp, "That server is currently unavailable")) {
                    pWnd = WindowMap["okdialog"]->_GetChildItem("OK_OKButton");
                    if(pWnd)
                        pWnd->WndNotification(pWnd, XWM_LCLICK, 0);
                }
            bOnce = true;
            }
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

                    bLogin = false; // kill LoginThread since we're either entering game or doing nothing
                }
            }
        }
        else
        {
            if(dwServerID = GetServerID(szServerName))
                pLoginClient->EnterGame(dwServerID);
            else
                AutoLoginDebug("HandleWindows(): GetServerID(%s) returned 0 at serverselect", szServerName);
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
            if(!stricmp(proc.szExeFile, exeName))
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
	int ret = WaitForSingleObject(hLoginThread, 10000);
	if (ret == WAIT_TIMEOUT) {
		TerminateThread(hLoginThread, 0);
	}
	int ret2 = WaitForSingleObject(hthisisatest, 10000);
	if (ret2 == WAIT_TIMEOUT) {
		TerminateThread(hthisisatest, 0);
	}
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
        sprintf(szOutput, "[%02d/%02d/%04d %02d:%02d:%02d] ", pTime->tm_mon+1, pTime->tm_mday, pTime->tm_year+1900, pTime->tm_hour, pTime->tm_min, pTime->tm_sec);
        strcat(szOutput, szTmp);

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