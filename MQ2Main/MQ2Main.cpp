/*****************************************************************************
MQ2Main.dll: MacroQuest's extension DLL for EverQuest
Copyright (C) 2002-2003 Plazmic

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License, version 2, as published by
the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
******************************************************************************/

// Exclude rarely-used stuff from Windows headers
#if !defined(CINTERFACE)
#error /DCINTERFACE
#endif

#define DBG_SPEW
#include "stdafx.h"
#include "MQ2Main.h"

#ifdef EQLIB_EXPORTS
#pragma message("EQLIB_EXPORTS")
#else
#pragma message("EQLIB_IMPORTS")
#endif

DWORD WINAPI MQ2Start(LPVOID lpParameter);

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    CHAR szFilename[MAX_STRING]={0};
    CHAR ClientName[MAX_STRING]={0};
    PCHAR szProcessName;
    ghModule = (HMODULE)hModule;
    ghInstance = (HINSTANCE)hModule;

    GetModuleFileName(ghModule,szFilename,MAX_STRING);
    szProcessName = strrchr(szFilename,'\\');
    szProcessName[0] = '\0';
    strcat(szFilename,"\\eqgame.ini");
    GetPrivateProfileString("MacroQuest","ClientName","eqgame",ClientName,MAX_STRING,szFilename);

    GetModuleFileName(NULL,szFilename,MAX_STRING);

    szProcessName = strrchr(szFilename,'.');
    szProcessName[0] = '\0';
    szProcessName = strrchr(szFilename,'\\')+1;
    if (!stricmp(szProcessName,ClientName)) {
        if (ul_reason_for_call == DLL_PROCESS_ATTACH) {

            GetModuleFileName(ghModule,szFilename,MAX_STRING);
            szProcessName = strrchr(szFilename,'\\');
            szProcessName[0] = '\0';
            g_Loaded = TRUE;
            CreateThread(NULL,0,&MQ2Start,strdup(szFilename),0,&ThreadID);
        } else if (ul_reason_for_call == DLL_PROCESS_DETACH){
            gbUnload=TRUE;
            //Fuck waiting for us to cleanly exit... we're being unloaded!
            //while (g_Loaded) Sleep(20);
            return TRUE;
        }
    }
    return TRUE;
}


// ***************************************************************************
// Function:    ParseINIFile
// Description: Parse INI file for memory locations
// ***************************************************************************
BOOL ParseINIFile(PCHAR lpINIPath)
{
    CHAR Filename[MAX_STRING] = {0};
    CHAR MQChatSettings[MAX_STRING] = {0};
    CHAR CustomSettings[MAX_STRING] = {0};
    CHAR ClientINI[MAX_STRING] = {0};
    CHAR szBuffer[MAX_STRING] = {0};
    CHAR ClientName[MAX_STRING] = {0};
    CHAR AliasList[MAX_STRING*10] = {0};
    CHAR HotkeyList[MAX_STRING*10] = {0};
    CHAR FilterList[MAX_STRING*10] = {0};
    struct _stat stat;
    int client;
    BOOL clientOverride = FALSE;

    sprintf(Filename,"%s\\MacroQuest.ini",lpINIPath);
    sprintf(ClientINI,"%s\\eqgame.ini",lpINIPath);
    sprintf(MQChatSettings,"%s\\MQchat.ini",lpINIPath);
    sprintf(CustomSettings,"%s\\Custom.ini",lpINIPath);
    strcpy(gszINIFilename,Filename);
    strcpy(gszINIMQchat,MQChatSettings);
    GetPrivateProfileString("MacroQuest","ClientOverride","0",szBuffer,MAX_STRING,ClientINI);       clientOverride = atoi(szBuffer);
    GetPrivateProfileString("MacroQuest","ClientVersion","0",szBuffer,MAX_STRING,ClientINI);
    GetPrivateProfileString("MacroQuest","ClientName","eqgame",ClientName,MAX_STRING,ClientINI);
    strcat(ClientName,".exe");
    client = _open(ClientName,_O_RDONLY);
    if (client == -1) {
        sprintf(szBuffer,"Unable to check client version. (%d)",errno);
        MessageBox(NULL,szBuffer,"MacroQuest",MB_OK);
        return FALSE;
    }
    _fstat(client,&stat);
    _close(client);

    DebugSpewAlways("Expected Client version: %s",szBuffer);
    DebugSpewAlways("    Real Client version: %s",ctime(&stat.st_mtime));
    if (!clientOverride && !CompareTimes(ctime(&stat.st_mtime),szBuffer)) {
        sprintf(szBuffer,"Incorrect client version:\n%s",ctime(&stat.st_mtime));
        MessageBox(NULL,szBuffer,"MacroQuest",MB_OK);
        return FALSE;
    }

    GetPrivateProfileString("MacroQuest","MacroQuestVersion","0",gszVersion,MAX_STRING,ClientINI);
/*
    GetPrivateProfileString("Function Locations","WriteChatColor","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_DSPCHAT = strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","GetRaceByID","0",szBuffer,MAX_STRING,ClientINI);      GetRaceByID = (fEQGetStringByID)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","GetClassByID","0",szBuffer,MAX_STRING,ClientINI);     GetClassByID = (fEQGetStringByID)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","GetDeityByID","0",szBuffer,MAX_STRING,ClientINI);     GetDeityByID = (fEQGetStringByID)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","GetBodyTypeByID","0",szBuffer,MAX_STRING,ClientINI);  GetBodyTypeByID = (fEQGetStringByID)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","ScreenItem","0",szBuffer,MAX_STRING,ClientINI);       ScreenItem = (fEQScreenItem)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","ScreenSpawn","0",szBuffer,MAX_STRING,ClientINI);      ScreenSpawn = (fEQScreenSpawn)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","MaxMana","0",szBuffer,MAX_STRING,ClientINI);          EQADDR_MAXMANA = strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","Commands","0",szBuffer,MAX_STRING,ClientINI);         EQADDR_COMMANDS = strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","LoadSpells","0",szBuffer,MAX_STRING,ClientINI);       cmdLoadSpells = (fEQLoadSpells)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","MemSpell","0",szBuffer,MAX_STRING,ClientINI);         cmdMemSpell = (fEQMemSpell)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","SelectItem","0",szBuffer,MAX_STRING,ClientINI);      cmdSelectItem = (fEQSelectItem)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","BuyItem","0",szBuffer,MAX_STRING,ClientINI);         cmdBuyItem = (fEQBuyItem)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","SellItem","0",szBuffer,MAX_STRING,ClientINI);         cmdSellItem = (fEQSellItem)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","GetFocusCastingTimeModifier","0",szBuffer,MAX_STRING,ClientINI);  EQADDR_GETFOCUSCASTINGTIMEMODIFIER = (DWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","GetAACastingTimeModifier","0",szBuffer,MAX_STRING,ClientINI); EQADDR_GETAACASTINGTIMEMODIFIER = (DWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","WriteMapfile","0",szBuffer,MAX_STRING,ClientINI); EQADDR_WRITEMAPFILE = (DWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","RClickTarget","0",szBuffer,MAX_STRING,ClientINI); EQADDR_RCLICKTARGET = (DWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","LClickTarget","0",szBuffer,MAX_STRING,ClientINI); EQADDR_LCLICKTARGET = (DWORD)strtoul(szBuffer,NULL,16);
	GetPrivateProfileString("Function Locations","CleanGameUI","0",szBuffer,MAX_STRING,ClientINI); EQADDR_CLEANUI = (DWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","ItemDisplaySetItem","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_ITEMDISPLAYSETITEM = (DWORD)strtoul(szBuffer,NULL,16); 
    GetPrivateProfileString("Function Locations","CXStrAppend","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_CXSTRAPPEND = (DWORD)strtoul(szBuffer,NULL,16); 
    GetPrivateProfileString("Function Locations","CXStrSet","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_CXSTRSET = (DWORD)strtoul(szBuffer,NULL,16); 
/**/

    GetPrivateProfileString("Function Locations","NewUIINI","0",szBuffer,MAX_STRING,ClientINI);         NewUIINI = (fEQNewUIINI)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","ProcessGameEvents","0",szBuffer,MAX_STRING,ClientINI); ProcessGameEvents = (fEQProcGameEvts)strtoul(szBuffer,NULL,16);
	GetPrivateProfileString("Function Locations","SendMessage","0",szBuffer,MAX_STRING,ClientINI); send_message = (fEQSendMessage)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","ConvertItemTags","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_CONVERTITEMTAGS = (DWORD)strtoul(szBuffer,NULL,16);
	
	GetPrivateProfileString("Function Locations","MemChecker","0",szBuffer,MAX_STRING,ClientINI);       EQADDR_MEMCHECK = strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","MemChecker2","0",szBuffer,MAX_STRING,ClientINI);      EQADDR_MEMCHECK2 = strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","MemCheckAddr1","0",szBuffer,MAX_STRING,ClientINI);        EQADDR_MEMCHECKADDR1 = strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","MemCheckAddr2","0",szBuffer,MAX_STRING,ClientINI);        EQADDR_MEMCHECKADDR2 = strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","MemChecker3","0",szBuffer,MAX_STRING,ClientINI);      EQADDR_MEMCHECK3 = strtoul(szBuffer,NULL,16);
/*
    GetPrivateProfileString("Function Locations","CastSpell","0",szBuffer,MAX_STRING,ClientINI);        EQADDR_CASTSPELL = (DWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","CXStrConstructor","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_CXSTRCONSTRUCTOR = (DWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","CXStrFree","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_CXSTRFREE = (DWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","CStmlWndAppend","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_APPENDSTML = (DWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","CChatManagerInitContextMenu","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_CHATMANAGERINITCONTEXTMENU = (DWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","CChatWindowConstructor","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_CCHATWINDOWCONSTRUCTOR = (DWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","CChatWindowDeconstructor","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_CCHATWINDOWDECONSTRUCTOR = (DWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","CChatManagerGetRGBAFromIndex","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_CCHATMANAGERGETRGBAFROMINDEX = (DWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","GetItemLinkHash","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_GETITEMLINKHASH = (DWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","GetNumBankSlots","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_GETNUMBANKSLOTS = (DWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","CLabelDraw","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_EQLABELS = (DWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","Zoning","0",szBuffer,MAX_STRING,ClientINI);             EQADDR_ZONING = (DWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","EQCharacterMaxHP","0",szBuffer,MAX_STRING,ClientINI);             EQADDR_GETMAXHP = (DWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","EQCharacterCurHP","0",szBuffer,MAX_STRING,ClientINI);             EQADDR_GETCURHP = (DWORD)strtoul(szBuffer,NULL,16);
	
	GetPrivateProfileString("Function Locations","EQCharacterCurHP","0",szBuffer,MAX_STRING,ClientINI);             EQADDR_GETCURHP = (DWORD)strtoul(szBuffer,NULL,16); 
/**/

    GetPrivateProfileString("DirectInput8","Main","0",szBuffer,MAX_STRING,ClientINI);                   EQADDR_DIMAIN = strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("DirectInput8","Keyboard","0",szBuffer,MAX_STRING,ClientINI);               EQADDR_DIKEYBOARD = (IDirectInputDevice8A**)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("DirectInput8","Mouse","0",szBuffer,MAX_STRING,ClientINI);                  EQADDR_DIMOUSE = (IDirectInputDevice8A**)strtoul(szBuffer,NULL,16);

    GetPrivateProfileString("Memory Locations","ZoneInfo","0",szBuffer,MAX_STRING,ClientINI);           EQADDR_ZONEINFO = (PZONEINFO)strtoul(szBuffer,NULL,16);
//    GetPrivateProfileString("Memory Locations","SpawnHeader","0",szBuffer,MAX_STRING,ClientINI);        EQADDR_SPAWNLIST = (PSPAWNINFO*)strtoul(szBuffer,NULL,16);
//    GetPrivateProfileString("Memory Locations","SpawnFooter","0",szBuffer,MAX_STRING,ClientINI);        EQADDR_SPAWNTAIL = (PSPAWNINFO*)strtoul(szBuffer,NULL,16);
//    GetPrivateProfileString("Memory Locations","Char","0",szBuffer,MAX_STRING,ClientINI);				EQADDR_CHAR= (PSPAWNINFO*)strtoul(szBuffer,NULL,16);
//    GetPrivateProfileString("Memory Locations","Zones","0",szBuffer,MAX_STRING,ClientINI);              EQADDR_ZONELIST = (PZONELIST**)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Memory Locations","Guilds","0",szBuffer,MAX_STRING,ClientINI);             EQADDR_GUILDLIST = strtoul(szBuffer,NULL,16);
//    GetPrivateProfileString("Memory Locations","Target","0",szBuffer,MAX_STRING,ClientINI);             EQADDR_TARGET = (PSPAWNINFO*)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Memory Locations","LastTell","0",szBuffer,MAX_STRING,ClientINI);           EQADDR_LASTTELL = (PCHAR)strtoul(szBuffer,NULL,16);
//    GetPrivateProfileString("Memory Locations","CharInfo","0",szBuffer,MAX_STRING,ClientINI);           EQADDR_CHAR_INFO = (PCHARINFO*)strtoul(szBuffer,NULL,16);
//    GetPrivateProfileString("Memory Locations","Packs","0",szBuffer,MAX_STRING,ClientINI);              EQADDR_PACKLOCS = (PPACKLOC)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Memory Locations","Mouse","0",szBuffer,MAX_STRING,ClientINI);              EQADDR_MOUSE = (PMOUSEINFO)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Memory Locations","Attack","0",szBuffer,MAX_STRING,ClientINI);             EQADDR_ATTACK = (PBYTE)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Memory Locations","InChatMode","0",szBuffer,MAX_STRING,ClientINI);         EQADDR_NOTINCHATMODE = (PBYTE)strtoul(szBuffer,NULL,16);
//    GetPrivateProfileString("Memory Locations","Items","0",szBuffer,MAX_STRING,ClientINI);              EQADDR_ITEMS = (PGROUNDITEM*)strtoul(szBuffer,NULL,16);
//    GetPrivateProfileString("Memory Locations","Doors","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_DOORS = (PDOORTABLE*)strtoul(szBuffer,NULL,16);
//    GetPrivateProfileString("Memory Locations","Spells","0",szBuffer,MAX_STRING,ClientINI);             EQADDR_SPELLS = (_SPELLPOINTER**)strtoul(szBuffer,NULL,16);
//    GetPrivateProfileString("Memory Locations","Group","0",szBuffer,MAX_STRING,ClientINI);              EQADDR_GROUP = (PSPAWNINFO*)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Memory Locations","GroupCount","0",szBuffer,MAX_STRING,ClientINI);         EQADDR_GROUPCOUNT = (PBYTE)strtoul(szBuffer,NULL,16);
	GetPrivateProfileString("Memory Locations","gWorld","0",szBuffer,MAX_STRING,ClientINI);				EQADDR_GWORLD = (PVOID)strtoul(szBuffer,NULL,16);
//	GetPrivateProfileString("Memory Locations","clsMainNewUI","0",szBuffer,MAX_STRING,ClientINI);       EQADDR_CLSMAINNEWUI = (PDWORD)strtoul(szBuffer,NULL,16);
//    GetPrivateProfileString("Memory Locations","clsItems","0",szBuffer,MAX_STRING,ClientINI);           EQADDR_CLSITEMS = strtoul(szBuffer,NULL,16);
//    GetPrivateProfileString("Memory Locations","clsSpawns","0",szBuffer,MAX_STRING,ClientINI);          EQADDR_CLSSPAWNS = strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Memory Locations","CommandList","0",szBuffer,MAX_STRING,ClientINI);                EQADDR_CMDLIST = (PCMDLIST)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Memory Locations","DoAbilityList","0",szBuffer,MAX_STRING,ClientINI);              EQADDR_DOABILITYLIST = (PDWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Memory Locations","DoAbilityAvailable","0",szBuffer,MAX_STRING,ClientINI);         EQADDR_DOABILITYAVAILABLE = (PBYTE)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Memory Locations","EncryptPad","0",szBuffer,MAX_STRING,ClientINI);         EQADDR_ENCRYPTPAD = (PBYTE)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Memory Locations","EncryptPad2","0",szBuffer,MAX_STRING,ClientINI);            EQADDR_ENCRYPTPAD2 = (PBYTE)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Memory Locations","EncryptPad3","0",szBuffer,MAX_STRING,ClientINI);            EQADDR_ENCRYPTPAD3 = (PBYTE)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Memory Locations","ServerHost","0",szBuffer,MAX_STRING,ClientINI);            EQADDR_SERVERHOST = (PCHAR)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Memory Locations","ServerName","0",szBuffer,MAX_STRING,ClientINI);            EQADDR_SERVERNAME = (PCHAR)strtoul(szBuffer,NULL,16);
//    GetPrivateProfileString("Memory Locations","SpellFavorites","0",szBuffer,MAX_STRING,ClientINI);            EQADDR_SPELLFAVORITES = (PSPELLFAVORITE)strtoul(szBuffer,NULL,16);
//    GetPrivateProfileString("Memory Locations","ActiveMerchant","0",szBuffer,MAX_STRING,ClientINI);            EQADDR_ACTIVEMERCHANT = (PCHAR*)strtoul(szBuffer,NULL,16);
//    GetPrivateProfileString("Memory Locations","ActiveCorpse","0",szBuffer,MAX_STRING,ClientINI);            EQADDR_ACTIVECORPSE = (PCHAR*)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Memory Locations","SlotList","0",szBuffer,MAX_STRING,ClientINI);            EQADDR_SLOTLIST = (PDWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Memory Locations","Clicks","0",szBuffer,MAX_STRING,ClientINI);             EQADDR_MOUSECLICK = (PMOUSECLICK)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Memory Locations","HWnd","0",szBuffer,MAX_STRING,ClientINI);             EQADDR_HWND = (DWORD)strtoul(szBuffer,NULL,16);
/*
    GetPrivateProfileString("Class Locations","SpellBookWnd","0",szBuffer,MAX_STRING,ClientINI);            EQADDR_SPELLBOOKWND = (PDWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Class Locations","ClassMerchWnd","0",szBuffer,MAX_STRING,ClientINI);         EQADDR_CLASSMERCHWND = (PDWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Class Locations","ClassTextureAnim","0",szBuffer,MAX_STRING,ClientINI);      EQADDR_CLASSTEXTUREANIMATION = (PDWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Class Locations","InventoryWindow","0",szBuffer,MAX_STRING,ClientINI);     EQADDR_INVENTORYWND = (PDWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Class Locations","ClassCastSpellWnd","0",szBuffer,MAX_STRING,ClientINI);      EQADDR_CLASSCASTSPELLWND = (PDWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Class Locations","ClassHotButtonWnd","0",szBuffer,MAX_STRING,ClientINI);       EQADDR_CLASSHOTBUTTONWND = (PDWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Class Locations","CastingWindow","0",szBuffer,MAX_STRING,ClientINI);           EQADDR_CASTINGWND = (PDWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Class Locations","LootWnd","0",szBuffer,MAX_STRING,ClientINI);                 EQADDR_LOOTWND = (PDWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Class Locations","ClassMapWnd","0",szBuffer,MAX_STRING,ClientINI);                 EQADDR_CLASSMAPWND = (PDWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Class Locations","ClassContainerMgr","0",szBuffer,MAX_STRING,ClientINI);      EQADDR_CLASSCONTAINERMGR = (PEQ_CONTAINERWND_MANAGER *)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Class Locations","ClassGiveWnd","0",szBuffer,MAX_STRING,ClientINI);            EQADDR_CLASSGIVEWND = (PDWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Class Locations","ClassNotesWnd","0",szBuffer,MAX_STRING,ClientINI);           EQADDR_CLASSNOTESWND = (PEQNOTESWINDOW*)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Class Locations","ClassChatManager","0",szBuffer,MAX_STRING,ClientINI);         pChatMgr = (CChatManager*)strtoul(szBuffer,NULL,16);
	GetPrivateProfileString("Class Locations","ClassDisplayObject","0",szBuffer,MAX_STRING,ClientINI);			EQADDR_CLASSDISPLAYOBJECT = (PDWORD)strtoul(szBuffer,NULL,16); 
	GetPrivateProfileString("Class Locations","ClassBankWnd","0",szBuffer,MAX_STRING,ClientINI);			EQADDR_CLASSBANKWND = (PDWORD)strtoul(szBuffer,NULL,16); 
	GetPrivateProfileString("Class Locations","ClassEverQuest","0",szBuffer,MAX_STRING,ClientINI);			pEverQuest = (CEverQuest*)strtoul(szBuffer,NULL,16); 
/**/

    gFilterSkillsAll = 0!=GetPrivateProfileInt("MacroQuest","FilterSkills",0,Filename);
    gFilterSkillsIncrease = 2==GetPrivateProfileInt("MacroQuest","FilterSkills",0,Filename);
    gFilterDebug  = 1==GetPrivateProfileInt("MacroQuest","FilterDebug",0,Filename);
    gFilterTarget = 1==GetPrivateProfileInt("MacroQuest","FilterTarget",0,Filename);
    gFilterMoney  = 1==GetPrivateProfileInt("MacroQuest","FilterMoney",0,Filename);
    gFilterFood   = 1==GetPrivateProfileInt("MacroQuest","FilterFood",0,Filename);
	gUseMQChatWnd = 1==GetPrivateProfileInt("MacroQuest","UseMQChatWnd",1,Filename);
    gFilterMacro  = GetPrivateProfileInt("MacroQuest","FilterMacro",0,Filename);
    gFilterEncumber=1==GetPrivateProfileInt("MacroQuest","FilterEncumber",0,Filename);
    gFilterCustom = 1==GetPrivateProfileInt("MacroQuest","FilterCustom",1,Filename);
    gSpewToFile   = 1==GetPrivateProfileInt("MacroQuest","DebugSpewToFile",0,Filename);
    gMQPauseOnChat= 1==GetPrivateProfileInt("MacroQuest","MQPauseOnChat",0,Filename);
    gKeepKeys     = 1==GetPrivateProfileInt("MacroQuest","KeepKeys",0,Filename);
/*
	DWORD Temp=0;
    Temp = GetPrivateProfileInt("MacroQuest","ForegroundMaxFPS",50,Filename);
	SetForegroundMaxFPS(Temp);
    Temp = GetPrivateProfileInt("MacroQuest","BackgroundMaxFPS",20,Filename);
	SetBackgroundMaxFPS(Temp);
/**/

/*
    for (DWORD i=0;gMapFilterOptions[i].szName;i++) {
        sprintf(szBuffer,"%s-Color",gMapFilterOptions[i].szName);
        gMapFilters[gMapFilterOptions[i].Index] = GetPrivateProfileInt("Map Filters",gMapFilterOptions[i].szName,0,Filename);
        gMapFiltersColor[gMapFilterOptions[i].Index] = GetPrivateProfileInt("Map Filters",szBuffer,gMapFilterOptions[i].DefaultColor,Filename) | 0xFF000000;
    }
    // Do not use Custom, since the string isn't stored
    gMapFilters[MAPFILTER_UserFilter] = 0;
/**/

	gFilterSWho.Lastname= GetPrivateProfileInt("SWho Filter","Lastname",1,Filename);
	gFilterSWho.Class	= GetPrivateProfileInt("SWho Filter","Class",1,Filename);
	gFilterSWho.Race	= GetPrivateProfileInt("SWho Filter","Race",1,Filename);
	gFilterSWho.Level	= GetPrivateProfileInt("SWho Filter","Level",1,Filename);
	gFilterSWho.GM		= GetPrivateProfileInt("SWho Filter","GM",1,Filename);
	gFilterSWho.Guild	= GetPrivateProfileInt("SWho Filter","Guild",1,Filename);
	gFilterSWho.LD		= GetPrivateProfileInt("SWho Filter","LD",1,Filename);
	gFilterSWho.LFG		= GetPrivateProfileInt("SWho Filter","LFG",1,Filename);
	gFilterSWho.NPCTag	= GetPrivateProfileInt("SWho Filter","NPCTag",1,Filename);
	gFilterSWho.Trader	= GetPrivateProfileInt("SWho Filter","Trader",1,Filename);
	gFilterSWho.AFK		= GetPrivateProfileInt("SWho Filter","AFK",1,Filename);
	gFilterSWho.Anon	= GetPrivateProfileInt("SWho Filter","Anon",1,Filename);
	gFilterSWho.Distance= GetPrivateProfileInt("SWho Filter","Distance",1,Filename);
	gFilterSWho.Light	= GetPrivateProfileInt("SWho Filter","Light",0,Filename);
	gFilterSWho.Body	= GetPrivateProfileInt("SWho Filter","Body",0,Filename);
	gFilterSWho.SpawnID = GetPrivateProfileInt("SWho Filter","SpawnID",0,Filename);
	gFilterSWho.Holding = GetPrivateProfileInt("SWho Filter","Holding",0,Filename);
	gFilterSWho.ConColor= GetPrivateProfileInt("SWho Filter","ConColor",0,Filename);

    GetPrivateProfileString("MacroQuest","MacroPath",".",szBuffer,MAX_STRING,Filename);
    if (szBuffer[0]=='.') {
        sprintf(gszMacroPath,"%s%s",lpINIPath,szBuffer+1);
    } else {
        strcat(gszMacroPath,szBuffer);
    }

    GetPrivateProfileString("MacroQuest","LogPath",".",szBuffer,MAX_STRING,Filename);
    if (szBuffer[0]=='.') {
        sprintf(gszLogPath,"%s%s",lpINIPath,szBuffer+1);
    } else {
        strcat(gszLogPath,szBuffer);
    }

    DefaultFilters();
    GetPrivateProfileString("Filter Names",NULL,"",FilterList,MAX_STRING*10,Filename);
    PCHAR pFilterList = FilterList;
    while (pFilterList[0]!=0) {
        GetPrivateProfileString("Filter Names",pFilterList,"",szBuffer,MAX_STRING,Filename);
        if (szBuffer[0]!=0 && strcmp(szBuffer,"NOBODY")) {
            AddFilter(szBuffer,-1,&gFilterCustom);
        }
        pFilterList+=strlen(pFilterList)+1;
    }

    GetPrivateProfileString("Hotkeys",NULL,"",HotkeyList,MAX_STRING*10,Filename);
    PCHAR pHotkeyList = HotkeyList;
    while (pHotkeyList[0]!=0) {
        GetPrivateProfileString("Hotkeys",pHotkeyList,"",szBuffer,MAX_STRING,Filename);
        if (szBuffer[0]!=0) {
            PHOTKEY pNew = (PHOTKEY)malloc(sizeof(HOTKEY));
            strcpy(pNew->szName,pHotkeyList);
            ConvertHotkeyNameToKeyName(pNew->szName);
            DWORD i;
            for (i=0;gDiKeyID[i].szName[0];i++) {
                if (!stricmp(gDiKeyID[i].szName,pNew->szName)) {
                    pNew->DIKey = gDiKeyID[i].Id;
                }
            }
            strcpy(pNew->szCommand,szBuffer);
            pNew->pNext=pHotkey;
            pHotkey=pNew;
        }
        pHotkeyList+=strlen(pHotkeyList)+1;
    }

	sprintf(Filename,"%s\\ItemDB.txt",lpINIPath);
    FILE *fDB = fopen(Filename,"rt");
    strcpy(gszItemDB,Filename);
    if (fDB) {
        fgets(szBuffer,MAX_STRING,fDB);
        while ((!feof(fDB)) && (strstr(szBuffer,"\t"))) {
            PITEMDB Item = (PITEMDB)malloc(sizeof(ITEMDB));
            Item->pNext = gItemDB;
            Item->ID = atoi(szBuffer);
            strcpy(Item->szName,strstr(szBuffer,"\t")+1);
            Item->szName[strstr(Item->szName,"\n")-Item->szName]=0;
            gItemDB = Item;
            fgets(szBuffer,MAX_STRING,fDB);
        }
        fclose(fDB);
    }

    return TRUE;
}


// ***************************************************************************
// Function:    MQ2Start
// Description: Where we start execution during the insertion
// ***************************************************************************
DWORD WINAPI MQ2Start(LPVOID lpParameter)
{
    PCHAR lpINIPath = (PCHAR)lpParameter;
    strcpy(gszINIPath, lpINIPath);
    CHAR szBuffer[MAX_STRING] = {0};
    if (!ParseINIFile(lpINIPath)) {
        DebugSpewAlways("ParseINIFile returned false - thread aborted.");
        g_Loaded = FALSE;
        free(lpINIPath);
        return 1;
    }


	InitializeParser();
	InitializeMQ2Detours();
	InitializeCleanUI();
	InitializeChatHook();
	InitializeMQ2Pulse();
	InitializeMQ2Commands();
	InitializeMQ2Plugins();
	while (gGameState != GAMESTATE_INGAME) Sleep(500);
	InitializeMQ2DInput();

    WriteChatColor(LoadedString,USERCOLOR_DEFAULT);
    DebugSpewAlways(LoadedString);

    while (!gbUnload) {
        Sleep(500);
    }

    WriteChatColor(UnloadedString,USERCOLOR_DEFAULT);
    DebugSpewAlways(UnloadedString);

	ShutdownCleanUI();
	ShutdownMQ2DInput();
	ShutdownChatHook();
	ShutdownMQ2Pulse();
	ShutdownMQ2Plugins();
	ShutdownMQ2Commands();
	ShutdownMQ2Detours();
	ShutdownParser();

    free(lpINIPath);
    g_Loaded = FALSE;
    return 0;
}


HHOOK g_hHook;

LRESULT CALLBACK hookCBTProc( int nCode, WPARAM wParam, LPARAM lParam )
{
    return ::CallNextHookEx( g_hHook, nCode, wParam, lParam );
}

VOID InjectEnable()
{
    // Install the global hook, injecting this DLL into every other process
    g_hHook = SetWindowsHookEx( WH_CBT, hookCBTProc, ghInstance, 0 );
}

VOID InjectDisable()
{
    UnhookWindowsHookEx( g_hHook );
    g_hHook = NULL;
}
