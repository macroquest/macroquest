/*****************************************************************************
MQ2Main.dll: MacroQuest's extension DLL for EverQuest
Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

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
#define DEBUG_TRY

#include "MQ2Main.h"

#ifdef EQLIB_EXPORTS
#pragma message("EQLIB_EXPORTS")
#else
#pragma message("EQLIB_IMPORTS")
#endif

DWORD WINAPI MQ2Start(LPVOID lpParameter);
#if !defined(ISXEQ) && !defined(ISXEQ_LEGACY)

BOOL APIENTRY DllMain( HANDLE hModule, 
                      DWORD  ul_reason_for_call, 
                      LPVOID lpReserved
                      )
{
    CHAR szFilename[MAX_STRING]={0};
    PCHAR szProcessName;
    ghModule = (HMODULE)hModule;
    ghInstance = (HINSTANCE)hModule;

    GetModuleFileName(ghModule,szFilename,MAX_STRING);
    szProcessName = strrchr(szFilename,'\\');
    szProcessName[0] = '\0';
    strcat(szFilename,"\\eqgame.ini");

    GetModuleFileName(NULL,szFilename,MAX_STRING);

    szProcessName = strrchr(szFilename,'.');
    szProcessName[0] = '\0';
    szProcessName = strrchr(szFilename,'\\')+1;
    if (!_stricmp(szProcessName,__ClientName)) {
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
    if (szProcessName[0]!='\0' && !_stricmp(szProcessName,"LaunchPad")) {
        if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
            exit(-1);
        }
    }
    return TRUE;
}

#endif

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
	CHAR szBuffer2[MAX_STRING] = {0};
    CHAR ClientName[MAX_STRING] = {0};
    CHAR FilterList[MAX_STRING*10] = {0};
	CHAR Delimiter[MAX_STRING] = {0};
    GetEQPath(gszEQPath);


    sprintf(Filename,"%s\\MacroQuest.ini",lpINIPath);
    sprintf(ClientINI,"%s\\eqgame.ini",lpINIPath);
    strcpy(gszINIFilename,Filename);

    DebugSpew("Expected Client version: %s %s",__ExpectedVersionDate,__ExpectedVersionTime);
    DebugSpew("    Real Client version: %s %s",__ActualVersionDate,__ActualVersionTime);

    // note: __ClientOverride is always #defined as 1 or 0
#if (!__ClientOverride)
    if (strncmp(__ExpectedVersionDate,(const char *)__ActualVersionDate,strlen(__ExpectedVersionDate)) ||
        strncmp(__ExpectedVersionTime,(const char *)__ActualVersionTime,strlen(__ExpectedVersionTime)))
    {
        MessageBox(NULL,"Incorrect client version","MacroQuest",MB_OK);
        return FALSE;
    }
#endif

    gFilterSkillsAll = 0!=GetPrivateProfileInt("MacroQuest","FilterSkills",0,Filename);
    gFilterSkillsIncrease = 2==GetPrivateProfileInt("MacroQuest","FilterSkills",0,Filename);
    gFilterDebug  = 1==GetPrivateProfileInt("MacroQuest","FilterDebug",0,Filename);
    gFilterMQ2DataErrors  = 1==GetPrivateProfileInt("MacroQuest","FilterMQ2Data",0,Filename);
    gFilterTarget = 1==GetPrivateProfileInt("MacroQuest","FilterTarget",0,Filename);
    gFilterMoney  = 1==GetPrivateProfileInt("MacroQuest","FilterMoney",0,Filename);
    gFilterFood   = 1==GetPrivateProfileInt("MacroQuest","FilterFood",0,Filename);
    gFilterMacro  = GetPrivateProfileInt("MacroQuest","FilterMacro",0,Filename);
    gFilterEncumber=1==GetPrivateProfileInt("MacroQuest","FilterEncumber",0,Filename);
    gFilterCustom = 1==GetPrivateProfileInt("MacroQuest","FilterCustom",1,Filename);
    gSpewToFile   = 1==GetPrivateProfileInt("MacroQuest","DebugSpewToFile",0,Filename);
    gMQPauseOnChat= 1==GetPrivateProfileInt("MacroQuest","MQPauseOnChat",0,Filename);
    gKeepKeys     = 1==GetPrivateProfileInt("MacroQuest","KeepKeys",0,Filename);
    bLaxColor=1==GetPrivateProfileInt("MacroQuest","LaxColor",0,Filename);
    bAllErrorsDumpStack = 1==GetPrivateProfileInt("MacroQuest","AllErrorsDumpStack",1,Filename);
    bAllErrorsFatal = 1==GetPrivateProfileInt("MacroQuest","AllErrorsFatal",0,Filename);
    gbMQ2LoadingMsg = 1==GetPrivateProfileInt("MacroQuest","MQ2LoadingMsg",1,Filename);
    gbExactSearchCleanNames = 1==GetPrivateProfileInt("MacroQuest","ExactSearchCleanNames",0,Filename);
    gbTimeStampChat = 1==GetPrivateProfileInt("MacroQuest","TimeStampChat",1,Filename);
    gbBeepOnTells = 1==GetPrivateProfileInt("MacroQuest","BeepOnTells",1,Filename);
    gbFlashOnTells = 1==GetPrivateProfileInt("MacroQuest","FlashOnTells",1,Filename);
	gCreateMQ2NewsWindow = 1==GetPrivateProfileInt("MacroQuest","CreateMQ2NewsWindow",1,Filename);

	GetPrivateProfileString("Macroquest","IfDelimiter",",",Delimiter,MAX_STRING,Filename); gIfDelimiter = Delimiter[0];
	GetPrivateProfileString("Macroquest","IfAltDelimiter","~",Delimiter,MAX_STRING,Filename); gIfAltDelimiter = Delimiter[0];

	GetPrivateProfileString("MacroQuest","HUDMode","UnderUI",CustomSettings,MAX_STRING,Filename);
    if (!_stricmp(CustomSettings,"normal")) {
        gbAlwaysDrawMQHUD=false;
        gbHUDUnderUI=false;
    }
	else
        if (!_stricmp(CustomSettings,"underui"))
        {
            gbHUDUnderUI=true;
            gbAlwaysDrawMQHUD=false;
        }
		else
            if (!_stricmp(CustomSettings,"always"))
            {
                gbHUDUnderUI=true;
                gbAlwaysDrawMQHUD=true;
            }



            GetPrivateProfileString("Captions","NPC",gszSpawnNPCName,gszSpawnNPCName,MAX_STRING,Filename);
            GetPrivateProfileString("Captions","Player1",gszSpawnPlayerName[1],gszSpawnPlayerName[1],MAX_STRING,Filename);
            GetPrivateProfileString("Captions","Player2",gszSpawnPlayerName[2],gszSpawnPlayerName[2],MAX_STRING,Filename);
            GetPrivateProfileString("Captions","Player3",gszSpawnPlayerName[3],gszSpawnPlayerName[3],MAX_STRING,Filename);
            GetPrivateProfileString("Captions","Player4",gszSpawnPlayerName[4],gszSpawnPlayerName[4],MAX_STRING,Filename);
            GetPrivateProfileString("Captions","Player5",gszSpawnPlayerName[5],gszSpawnPlayerName[5],MAX_STRING,Filename);
            GetPrivateProfileString("Captions","Player6",gszSpawnPlayerName[6],gszSpawnPlayerName[6],MAX_STRING,Filename);

            GetPrivateProfileString("Captions","Corpse",gszSpawnCorpseName,gszSpawnCorpseName,MAX_STRING,Filename);
            GetPrivateProfileString("Captions","Pet",gszSpawnPetName,gszSpawnPetName,MAX_STRING,Filename);
            gMaxSpawnCaptions=GetPrivateProfileInt("Captions","Update",gMaxSpawnCaptions,Filename);
            gMQCaptions = 1==GetPrivateProfileInt("Captions","MQCaptions",1,Filename); 
            ConvertCR(gszSpawnNPCName);
            ConvertCR(gszSpawnPlayerName[1]);
            ConvertCR(gszSpawnPlayerName[2]);
            ConvertCR(gszSpawnPlayerName[3]);
            ConvertCR(gszSpawnPlayerName[4]);
            ConvertCR(gszSpawnPlayerName[5]);
            ConvertCR(gszSpawnPlayerName[6]);
            ConvertCR(gszSpawnCorpseName);
            ConvertCR(gszSpawnPetName);

            gFilterSWho.Lastname= GetPrivateProfileInt("SWho Filter","Lastname",1,Filename);
            gFilterSWho.Class    = GetPrivateProfileInt("SWho Filter","Class",1,Filename);
            gFilterSWho.Race    = GetPrivateProfileInt("SWho Filter","Race",1,Filename);
            gFilterSWho.Level    = GetPrivateProfileInt("SWho Filter","Level",1,Filename);
            gFilterSWho.GM        = GetPrivateProfileInt("SWho Filter","GM",1,Filename);
            gFilterSWho.Guild    = GetPrivateProfileInt("SWho Filter","Guild",1,Filename);
            gFilterSWho.Sneak   = GetPrivateProfileInt("SWho Filter","Sneak",1,Filename); 
            gFilterSWho.LD        = GetPrivateProfileInt("SWho Filter","LD",1,Filename);
            gFilterSWho.LFG        = GetPrivateProfileInt("SWho Filter","LFG",1,Filename);
            gFilterSWho.NPCTag    = GetPrivateProfileInt("SWho Filter","NPCTag",1,Filename);
            gFilterSWho.Trader    = GetPrivateProfileInt("SWho Filter","Trader",1,Filename);
            gFilterSWho.AFK        = GetPrivateProfileInt("SWho Filter","AFK",1,Filename);
            gFilterSWho.Anon    = GetPrivateProfileInt("SWho Filter","Anon",1,Filename);
            gFilterSWho.Distance= GetPrivateProfileInt("SWho Filter","Distance",1,Filename);
            gFilterSWho.Light    = GetPrivateProfileInt("SWho Filter","Light",0,Filename);
            gFilterSWho.Body    = GetPrivateProfileInt("SWho Filter","Body",0,Filename);
            gFilterSWho.SpawnID = GetPrivateProfileInt("SWho Filter","SpawnID",0,Filename);
            gFilterSWho.Holding = GetPrivateProfileInt("SWho Filter","Holding",0,Filename);
            gFilterSWho.ConColor= GetPrivateProfileInt("SWho Filter","ConColor",0,Filename);
            gFilterSWho.Invisible= GetPrivateProfileInt("SWho Filter","Invisible",0,Filename);

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

            sprintf(Filename,"%s\\ItemDB.txt",lpINIPath);
            FILE *fDB = fopen(Filename,"rt");
            strcpy(gszItemDB,Filename);
			char *pDest = 0;
            if (fDB) {
                fgets(szBuffer,MAX_STRING,fDB);
                while ((!feof(fDB)) && (strstr(szBuffer,"\t"))) {
                    if(PITEMDB Item = (PITEMDB)malloc(sizeof(ITEMDB))) {
						Item->pNext = gItemDB;
						Item->ID = atoi(szBuffer);
						if(pDest = (strstr(szBuffer, "\t") + 1)) {
							strcpy_s(szBuffer2, pDest);
							Item->StackSize = atoi(szBuffer2);
							if(pDest = strstr(szBuffer2,"\t")) {
								strcpy(Item->szName,pDest+1);
								Item->szName[strstr(Item->szName,"\n")-Item->szName]=0;
								gItemDB = Item;
								fgets(szBuffer,MAX_STRING,fDB);
							} else {
								sprintf_s(szBuffer,"Your file: %s is old.\nPlease replace it with the one from the latest zip",Filename);
								MessageBox(NULL,szBuffer,"ItemDB.txt version mismatch",MB_OK);
								exit(0);
							}
						}
					}
                }
                fclose(fDB);
			}
			if(!gSpewToFile) {//lets check if the user has it set in his/her custom ini
				sprintf(Filename,"%s\\CustomPlugin.ini",lpINIPath);
				gSpewToFile = 1==GetPrivateProfileInt("MacroQuest","DebugSpewToFile",0,Filename);
			}
			return TRUE;
}

bool __cdecl MQ2Initialize()
{
	if (HMODULE hmLavish=GetModuleHandle("Lavish.dll")) {
		//I dont know why but if we dont sleep here for a while
		//we will crash but only if I have a detour on wwsCrashReportCheckForUploader
		//I suspect Lax would know more about this than me -eqmule
		//DebugBreak();
		DWORD lReturn = GetCurrentProcessId();
		DWORD pid = lReturn;
		//we use this loop to just wait for wineq2 to get the eqwindow up and running before we move on
		//there is some kind of weird race condition going on... again lax would know more about this than I...
		checkagain:
		EnumWindows(EnumWindowsProc,(LPARAM)&lReturn);
		if(lReturn==pid) {
			Sleep(1000);
			goto checkagain;
		}
		//do an extra second for good measure...
		Sleep(1000);
	}
    if(!InitOffsets())
    {
        DebugSpewAlways("InitOffsets returned false - thread aborted.");
        g_Loaded = FALSE;
        return false;
    }

    if (!ParseINIFile(gszINIPath)) {
        DebugSpewAlways("ParseINIFile returned false - thread aborted.");
        g_Loaded = FALSE;
        return false;
    }
    srand((unsigned int)time(0));
    ZeroMemory(gDiKeyName,sizeof(gDiKeyName));
    unsigned long i;
    for (i = 0 ; gDiKeyID[i].Id ; i++) {
        gDiKeyName[gDiKeyID[i].Id]=gDiKeyID[i].szName;
    }

    ZeroMemory(szEQMappableCommands,sizeof(szEQMappableCommands));
    for (i = 0 ; i < nEQMappableCommands; i++)
    {
        if((DWORD)EQMappableCommandList[i] == 0 || (DWORD)EQMappableCommandList[i] > (DWORD)__AC1_Data) {
			//Sleep(0);//for debugging
            continue;
		}
        szEQMappableCommands[i]=EQMappableCommandList[i];
    }
    gnNormalEQMappableCommands=i;

    // as long nEQMappableCommands is right and these remain at the end, these should never need updating
    // who uses the unknowns anyway? - ieatacid
	// jul 16 2014 uhm had to update these, I didnt check the actual functions
	// so there is no guarantee calling for example TOGGLE_WINDOWMODE will work
	// but at least they are at the end again and nEQMappableCommands was 0x201 today,
	//but yeah I see no use for them... - eqmule
	// last update Mar 23 2015 nEQMappableCommands was 0x206
	szEQMappableCommands[nEQMappableCommands - 22]="UNKNOWN0x1f1";//"Magic"
    szEQMappableCommands[nEQMappableCommands - 21]="UNKNOWN0x1f2";//"Fire"
    szEQMappableCommands[nEQMappableCommands - 20]="UNKNOWN0x1f3";//"Cold"
    szEQMappableCommands[nEQMappableCommands - 19]="UNKNOWN0x1f4";//"Disease"
    szEQMappableCommands[nEQMappableCommands - 18]="CHAT_SEMICOLON";//"Poison"
    szEQMappableCommands[nEQMappableCommands - 17]="CHAT_SLASH";//"Physical"
    szEQMappableCommands[nEQMappableCommands - 16]="INSTANT_CAMP";//"Corruption" confirmed 16 jul 2014 -eqmule
    szEQMappableCommands[nEQMappableCommands - 15]="UNKNOWN0x1f8";//"Unknown"
    szEQMappableCommands[nEQMappableCommands - 14]="UNKNOWN0x1f9";//"Avatar"
    szEQMappableCommands[nEQMappableCommands - 13]="UNKNOWN0x1fa";//"RemoveButton"
    szEQMappableCommands[nEQMappableCommands - 12]="CHAT_EMPTY";//"ClearAll"
    szEQMappableCommands[nEQMappableCommands - 11]="TOGGLE_WINDOWMODE";//"ClearTaskBecauseTaskNotFound" confirmed 16 jul 2014 -eqmule
    szEQMappableCommands[nEQMappableCommands - 10]="UNKNOWN0x1fd";//"NoPlayersLeft"
    szEQMappableCommands[nEQMappableCommands -  9]="UNKNOWN0x1fe";//"CreatedSharedTask"
    szEQMappableCommands[nEQMappableCommands -  8]="CHANGEFACE";//"Complete" confirmed 16 jul 2014 -eqmule
    szEQMappableCommands[nEQMappableCommands -  7]="UNKNOWN0x200";//Expired
    szEQMappableCommands[nEQMappableCommands -  6]="UNKNOWN0x201";//Script
    szEQMappableCommands[nEQMappableCommands -  5]="UNKNOWN0x202";//LeaderRemoved
    szEQMappableCommands[nEQMappableCommands -  4]="UNKNOWN0x203";
    szEQMappableCommands[nEQMappableCommands -  3]="UNKNOWN0x204";
    szEQMappableCommands[nEQMappableCommands -  2]="UNKNOWN0x205";
    szEQMappableCommands[nEQMappableCommands -  1]="UNKNOWN0x206";

    for (nColorAdjective=0 ; szColorAdjective[nColorAdjective] ; nColorAdjective++){}
    for (nColorAdjectiveYou=0 ; szColorAdjectiveYou[nColorAdjectiveYou] ; nColorAdjectiveYou++) {}
    for (nColorExpletive=0 ; szColorExpletive[nColorExpletive] ; nColorExpletive++) {}
    for (nColorSyntaxError=0 ; szColorSyntaxError[nColorSyntaxError] ; nColorSyntaxError++) {}
    for (nColorMacroError=0 ; szColorMacroError[nColorMacroError] ; nColorMacroError++) {}
    for (nColorMQ2DataError=0 ; szColorMQ2DataError[nColorMQ2DataError] ; nColorMQ2DataError++) {}
    for (nColorFatalError=0 ; szColorFatalError[nColorFatalError] ; nColorFatalError++) {}

    InitializeMQ2Benchmarks();
#ifndef ISXEQ
    InitializeParser();
#endif
    InitializeMQ2Detours();
    InitializeDisplayHook();
    InitializeChatHook();
    InitializeMQ2Spawns();
    InitializeMQ2Pulse();
    InitializeMQ2Commands();
    InitializeMQ2Windows();
	MQ2MouseHooks(1);
    Sleep(100);
    InitializeMQ2KeyBinds();
#ifndef ISXEQ
    InitializeMQ2Plugins();
#endif
	if (!ghLockPickZone)
		ghLockPickZone = CreateMutex(NULL, FALSE, NULL);
	if (!ghLockDelayCommand)
		ghLockDelayCommand = CreateMutex(NULL, FALSE, NULL);
    return true;
}

void __cdecl MQ2Shutdown()
{
    DebugTry(ShutdownMQ2KeyBinds());
    DebugTry(ShutdownMQ2Spawns());
    DebugTry(ShutdownDisplayHook());
#ifndef ISXEQ
    DebugTry(ShutdownMQ2DInput());
#endif
    DebugTry(ShutdownChatHook());
#ifndef ISXEQ
    DebugTry(ShutdownMQ2Pulse());
    DebugTry(ShutdownMQ2Plugins());
#endif
    DebugTry(ShutdownMQ2Windows());
	DebugTry(MQ2MouseHooks(0));
#ifndef ISXEQ
    DebugTry(ShutdownParser());
#endif
    DebugTry(ShutdownMQ2Commands());
    DebugTry(ShutdownMQ2Detours());
    DebugTry(ShutdownMQ2Benchmarks());
	if (ghLockSpellMap) {
		ReleaseMutex(ghLockSpellMap);
		CloseHandle(ghLockSpellMap);
		ghLockSpellMap = 0;
	}
	if (ghLockPickZone) {
		ReleaseMutex(ghLockPickZone);
		CloseHandle(ghLockPickZone);
		ghLockPickZone = 0;
	}
	if (ghLockDelayCommand) {
		ReleaseMutex(ghLockDelayCommand);
		CloseHandle(ghLockDelayCommand);
		ghLockDelayCommand = 0;
	}
}

DWORD __stdcall InitializeMQ2SpellDb(PVOID pData)
{
	if (!ghLockSpellMap)
		ghLockSpellMap = CreateMutex(NULL, FALSE, NULL);
	if (ghLockSpellMap) {
		while (!ppSpellMgr && gGameState != GAMESTATE_CHARSELECT && gGameState != GAMESTATE_INGAME) {
			Sleep(0);
		}
		while (ppSpellMgr && pSpellMgr && (!((PSPELLMGR)pSpellMgr)->Spells || (((PSPELLMGR)pSpellMgr)->Spells && !((PSPELLMGR)pSpellMgr)->Spells[TOTAL_SPELL_COUNT-1]))) {
			Sleep(0);
		}
		//ok everything checks out lets fill our own map with spells
		PopulateSpellMap();
	}
	return 0;
}
#ifndef ISXEQ
#ifdef EMU
//need to include any headers for your emu? add them here
#include "emu.h"
#endif
// ***************************************************************************
// Function:    MQ2Start Thread
// Description: Where we start execution during the insertion
// ***************************************************************************
DWORD WINAPI MQ2Start(LPVOID lpParameter)
{
	PCHAR lpINIPath = (PCHAR)lpParameter;
    strcpy(gszINIPath, lpINIPath);
    free(lpINIPath);
#ifdef EMU
	MQ2StartEmu();//or whatever...
#endif
	CHAR szBuffer[MAX_STRING] = { 0 };

    if (!MQ2Initialize()) {
		MessageBox(NULL,"Failed to Initialize MQ2 will free lib and exit","MQ2 Error",MB_OK);
		if(HMODULE h = GetModuleHandle("MQ2Main.dll"))
			FreeLibraryAndExitThread(h,0);
	}
    while (gGameState != GAMESTATE_CHARSELECT && gGameState != GAMESTATE_INGAME) 
        Sleep(500);

    InitializeMQ2DInput();
    if (gGameState == GAMESTATE_INGAME) {
        gbInZone = TRUE;
		WriteChatColor("Initializing SpellMap from MQ2Start, this will take a few seconds, please wait", CONCOLOR_YELLOW);
		InitializeMQ2SpellDb(NULL);
		PluginsSetGameState(GAMESTATE_INGAME);
	}

    WriteChatColor(LoadedString,USERCOLOR_DEFAULT);
    DebugSpewAlways(LoadedString);

    while (!gbUnload) {
        Sleep(500);
    }

    WriteChatColor(UnloadedString,USERCOLOR_DEFAULT);
    DebugSpewAlways(UnloadedString);
    UnloadMQ2Plugins();
    MQ2Shutdown();


    DebugSpew("Shutdown completed");
    g_Loaded = FALSE;

	if(HMODULE h = GetModuleHandle("MQ2Main.dll"))
		FreeLibraryAndExitThread(h,0);
    return 0;
}


#ifdef DEBUG_ALLOC
DWORD CountMallocs=0;
DWORD CountFrees=0;
#endif

#ifdef malloc
#undef malloc
#endif

void *MQ2Malloc(size_t size)
{
#ifdef DEBUG_ALLOC
    CountMallocs++;
#endif
    return malloc(size);
}

#ifdef free
#undef free
#endif

void MQ2Free(void *memblock)
{
#ifdef DEBUG_ALLOC
    CountFrees++;
#endif
    free(memblock);
}
#endif

class CMQNewsWnd : public CCustomWnd
{
public:
    CMQNewsWnd(char *Template):CCustomWnd(Template)
    {
        SetWndNotification(CMQNewsWnd);
        InputBox=(CTextEntryWnd*)GetChildItem("CWChatInput");
        InputBox->WindowStyle|=0x800C0;
        BitOff(WindowStyle,CWS_CLOSE);
        InputBox->UnknownCW|=0xFFFFFFFF;
        InputBox->Enabled=0;
        InputBox->SetMaxChars(512);
        OutputBox=(CStmlWnd*)GetChildItem("CWChatOutput");
    }

    ~CMQNewsWnd()
    {
    }

    int WndNotification(CXWnd *pWnd, unsigned int Message, void *unknown)
    {    
        if (pWnd==0)
        {
            if (Message==XWM_CLOSE)
            {
                dShow=1;
                return 1;
            }
        }
        return CSidlScreenWnd::WndNotification(pWnd,Message,unknown);
    };

    CTextEntryWnd *InputBox;
    CStmlWnd *OutputBox;
};


CMQNewsWnd *pNewsWindow=0;
VOID InsertMQ2News();
VOID CreateMQ2NewsWindow()
{
    CHAR Filename[MAX_STRING]={0};
    sprintf(Filename,"%s\\changes.txt",gszINIPath);
    if (!pNewsWindow && _FileExists(Filename))
    {
        pNewsWindow = new CMQNewsWnd("ChatWindow");
        pNewsWindow->Location.top=620;
        pNewsWindow->Location.bottom=920;
        pNewsWindow->Location.left=230;
        pNewsWindow->Location.right=850;
        SetCXStr(&pNewsWindow->WindowText,"MacroQuest2 Recent Changes");
    }
    InsertMQ2News();
}

VOID AddNewsLine(PCHAR Line, DWORD Color)
{
    Color=pChatManager->GetRGBAFromIndex(Color);

    CHAR szProcessed[MAX_STRING];
    MQToSTML(Line,szProcessed,MAX_STRING,Color);
    strcat(szProcessed,"<br>");
    CXStr NewText(szProcessed);
    ConvertItemTags(NewText,0);
    pNewsWindow->OutputBox->AppendSTML(NewText);
    //    ((CXWnd*)pNewsWindow->OutputBox)->SetVScrollPos(0);

}

VOID DeleteMQ2NewsWindow()
{
    if (pNewsWindow)
    {
        delete pNewsWindow;
        pNewsWindow=0;
    }
}

VOID InsertMQ2News()
{
    if (!pNewsWindow)
        return;
    CHAR Filename[MAX_STRING]={0};
    sprintf(Filename,"%s\\changes.txt",gszINIPath);
    FILE *file=fopen(Filename,"rb");
    if (!file)
    {
        DeleteMQ2NewsWindow();    
        return;
    }
    AddNewsLine("If you need help, refer to www.macroquest2.com/wiki",CONCOLOR_RED);
    AddNewsLine("Recent changes...",CONCOLOR_RED);
    CHAR szLine[MAX_STRING]={0};
    DWORD nLines=0;
    while(fgets(szLine,MAX_STRING,file))
    {
        strtok(szLine,"\r\n");
        if (atoi(szLine) && strstr(szLine," by "))
            AddNewsLine(szLine,CONCOLOR_GREEN);
        else
            AddNewsLine(szLine,CONCOLOR_YELLOW);
        nLines++;
        if (nLines>200)
        {
            AddNewsLine("...read changes.txt for more.",CONCOLOR_RED);
            break;
        }
    }
    fclose(file);
}


#ifndef ISXEQ

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
#endif

/* OTHER FUNCTIONS IMPORTED FROM EQ */
#ifdef __CastRay_x
FUNCTION_AT_ADDRESS(int CastRay(PSPAWNINFO,float y,float x,float z),__CastRay);
#endif
#ifdef Util__FastTime_x
FUNCTION_AT_ADDRESS(unsigned long  GetFastTime(void),Util__FastTime);
#endif
#ifdef __GetXTargetType_x
FUNCTION_AT_ADDRESS(char * __stdcall GetXtargetType(DWORD type), __GetXTargetType);
#endif
#ifdef __EQGetTime_x
FUNCTION_AT_ADDRESS(DWORD EQGetTime(), __EQGetTime);
#endif
#ifdef __msg_successful_hit_x
FUNCTION_AT_ADDRESS(void msg_successful_hit(struct _EQSuccessfulHit*),__msg_successful_hit);
#endif
#ifdef __STMLToText_x
FUNCTION_AT_ADDRESS(CXStr *__cdecl STMLToText(CXStr *Out, CXStr const &In, bool bFlag), __STMLToText);
#endif

