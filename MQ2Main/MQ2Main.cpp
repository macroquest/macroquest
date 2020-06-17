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
#include <Psapi.h>
#pragma comment( lib, "Psapi.lib" )
#ifdef ISXEQ
CRITICAL_SECTION gPluginCS = { 0 };
#endif
#ifdef EQLIB_EXPORTS
#pragma message("EQLIB_EXPORTS")
#else
#pragma message("EQLIB_IMPORTS")
#endif
HANDLE ghMemberMapLock = 0;
DWORD WINAPI MQ2Start(LPVOID lpParameter);
#if !defined(ISXEQ) && !defined(ISXEQ_LEGACY)
HANDLE hMQ2StartThread = 0;
BOOL APIENTRY DllMain( HANDLE hModule, 
                      DWORD  ul_reason_for_call, 
                      LPVOID lpReserved
                      )
{
    CHAR szFilename[MAX_STRING]={0};
    PCHAR szProcessName;
    ghModule = (HMODULE)hModule;
    ghInstance = (HINSTANCE)hModule;
	ghInjectorWnd = FindWindow(__MacroQuestWinClassName, __MacroQuestWinName);
	
    GetModuleFileName(ghModule,szFilename,MAX_STRING);
    szProcessName = strrchr(szFilename,'\\');
    szProcessName[0] = '\0';
    strcat_s(szFilename,"\\eqgame.ini");

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
            hMQ2StartThread = CreateThread(NULL,0,&MQ2Start,_strdup(szFilename),0,&ThreadID);
			//
        } else if (ul_reason_for_call == DLL_PROCESS_DETACH){
			gbUnload = TRUE;
			if (hMQ2StartThread)
			{
				int dwtime = WaitForSingleObject(hMQ2StartThread, 1000);
				if (dwtime == WAIT_TIMEOUT) {
					Sleep(0);
				}
				CloseHandle(hMQ2StartThread);
			}
			//while(g_Loaded)
			//	Sleep(0);
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
    GetEQPath(gszEQPath,MAX_STRING);
	DWORD StackingDebug = 0;

    sprintf_s(Filename,"%s\\MacroQuest.ini",lpINIPath);
    sprintf_s(ClientINI,"%s\\eqgame.ini",lpINIPath);
    strcpy_s(gszINIFilename,Filename);

    DebugSpew("Expected Client version: %s %s",__ExpectedVersionDate,__ExpectedVersionTime);
    DebugSpew("    Real Client version: %s %s",__ActualVersionDate,__ActualVersionTime);
	//MessageBox(NULL,"Debug me","MacroQuest",MB_OK);
    // note: __ClientOverride is always #defined as 1 or 0
#if (!__ClientOverride)
    if (strncmp(__ExpectedVersionDate,(const char *)__ActualVersionDate,strlen(__ExpectedVersionDate)) ||
        strncmp(__ExpectedVersionTime,(const char *)__ActualVersionTime,strlen(__ExpectedVersionTime)))
    {
        MessageBox(NULL,"Incorrect client version","MacroQuest",MB_OK);
        return FALSE;
    }
#endif
	//this is a new addition to core, if they dont have it, I want them to at least see it
	//from that point on they can chose to unload it.
	int defval = GetPrivateProfileInt("Plugins", "MQ2TargetInfo", -1, Filename);
	if (defval == -1)
	{
		WritePrivateProfileString("Plugins", "MQ2TargetInfo", "1", Filename);
	}
	int ic = GetPrivateProfileInt("Plugins", "MQ2Ic", 1, Filename);
	if (ic==0) {//its set to 0 thats not good
		WritePrivateProfileString("Plugins", "MQ2Ic", "1", Filename);
	}
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
	gUseTradeOnTarget = 1 == GetPrivateProfileInt("MacroQuest", "UseTradeOnTarget", 1, Filename);
    gbBeepOnTells = 1==GetPrivateProfileInt("MacroQuest","BeepOnTells",1,Filename);
    gbFlashOnTells = 1==GetPrivateProfileInt("MacroQuest","FlashOnTells",1,Filename);
	gbIgnoreAlertRecursion = 1==GetPrivateProfileInt("MacroQuest","IgnoreAlertRecursion",0,Filename);
	gbShowCurrentCamera = 1==GetPrivateProfileInt("MacroQuest","ShowCurrentCamera",1,Filename);	
	gTurboLimit = GetPrivateProfileInt("MacroQuest","TurboLimit",240,Filename);
	gCreateMQ2NewsWindow = 1==GetPrivateProfileInt("MacroQuest","CreateMQ2NewsWindow",1,Filename);
	gNetStatusXPos = GetPrivateProfileInt("MacroQuest","NetStatusXPos",0,Filename);
	gNetStatusYPos = GetPrivateProfileInt("MacroQuest","NetStatusYPos",0,Filename);
	StackingDebug = GetPrivateProfileInt("MacroQuest","BuffStackTestDebug",0,Filename); gStackingDebug = (StackingDebug == 2 ? -1 : StackingDebug);
	gUseNewNamedTest = 1 == GetPrivateProfileInt("MacroQuest", "UseNewNamedTest", 0, Filename);
    gdwParserEngineVer = GetPrivateProfileInt("MacroQuest", ("Parser" + ENGINE_SWITCH_CMD).c_str(),1,Filename);

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
            gAnonymize = 1==GetPrivateProfileInt("Captions","Anonymize",0,Filename); 
            gAnonymizeFlag = GetPrivateProfileInt("Captions","AnonymizeFlag",-1,Filename); 
			if (gAnonymizeFlag == -1)
			{
				WritePrivateProfileString("Captions", "AnonymizeFlag", "0", Filename);
				gAnonymizeFlag = 0;
			}
			GetPrivateProfileString("Captions", "AnonCaption", "", gszAnonCaption, MAX_STRING, Filename);
			if (gszAnonCaption[0] == '\0')
			{
				WritePrivateProfileString("Captions", "AnonCaption", "[${NamingSpawn.Level}] ${NamingSpawn.Race} ${NamingSpawn.Class} ${NamingSpawn.Type}", Filename);
			}
            ConvertCR(gszSpawnNPCName,MAX_STRING);
            ConvertCR(gszSpawnPlayerName[1], MAX_STRING);
            ConvertCR(gszSpawnPlayerName[2], MAX_STRING);
            ConvertCR(gszSpawnPlayerName[3], MAX_STRING);
            ConvertCR(gszSpawnPlayerName[4], MAX_STRING);
            ConvertCR(gszSpawnPlayerName[5], MAX_STRING);
            ConvertCR(gszSpawnPlayerName[6], MAX_STRING);
            ConvertCR(gszSpawnCorpseName, MAX_STRING);
            ConvertCR(gszSpawnPetName, MAX_STRING);
			ConvertCR(gszAnonCaption, MAX_STRING);

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
                sprintf_s(gszMacroPath,"%s%s",lpINIPath,szBuffer+1);
            } else {
                strcat_s(gszMacroPath,szBuffer);
            }


            GetPrivateProfileString("MacroQuest","LogPath",".",szBuffer,MAX_STRING,Filename);
            if (szBuffer[0]=='.') {
                sprintf_s(gszLogPath,"%s%s",lpINIPath,szBuffer+1);
            } else {
                strcat_s(gszLogPath,szBuffer);
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

            sprintf_s(Filename,"%s\\ItemDB.txt",lpINIPath);
			FILE *fDB = 0;
			errno_t err =fopen_s(&fDB,Filename, "rt");
            strcpy_s(gszItemDB,Filename);
			char *pDest = 0;
            if (!err) {
                fgets(szBuffer,MAX_STRING,fDB);
                while ((!feof(fDB)) && (strstr(szBuffer,"\t"))) {
                    if(PITEMDB Item = (PITEMDB)malloc(sizeof(ITEMDB))) {
						Item->pNext = gItemDB;
						Item->ID = atoi(szBuffer);
						if(pDest = (strstr(szBuffer, "\t") + 1)) {
							strcpy_s(szBuffer2, pDest);
							Item->StackSize = atoi(szBuffer2);
							if(pDest = strstr(szBuffer2,"\t")) {
								strcpy_s(Item->szName,pDest+1);
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
				sprintf_s(Filename,"%s\\CustomPlugin.ini",lpINIPath);
				gSpewToFile = 1==GetPrivateProfileInt("MacroQuest","DebugSpewToFile",0,Filename);
			}
			return TRUE;
}
VOID InitializeMQ2IcExports()
{
	IC_GetHashData = (fICGetHashData)GetProcAddress(ghmq2ic, "IC_GetHashData");
	IC_SetHashData = (fICSetHashData)GetProcAddress(ghmq2ic, "IC_SetHashData");
	IC_LoaderSetLoaded = (fLoaderSetLoaded)GetProcAddress(ghmq2ic, "IC_LoaderSetLoaded");
	IC_LoaderClearLoaded = (fLoaderClearLoaded)GetProcAddress(ghmq2ic, "IC_LoaderClearLoaded");
	IC_MQ2Unload = (fMQ2Unload)GetProcAddress(ghmq2ic, "IC_MQ2Unload");
	IC_ClassLvl = (fClassLvl)GetProcAddress(ghmq2ic, "IC_ClassLvl");
}
VOID DeInitializeMQ2IcExports()
{
	IC_GetHashData = 0;
	IC_SetHashData = 0;
	IC_LoaderSetLoaded = 0;
	IC_MQ2Unload = 0;
	IC_ClassLvl = 0;
}
#ifdef ISXEQ
void LoadMQ2Plugin(PMQPLUGIN hMQ2icplugin, const PCHAR pszFilename, char *modulepath, size_t bufflen, HMODULE *module)
{
	*module = LoadLibrary(pszFilename);
	if (*module) {
		hMQ2icplugin->hModule = *module;
		hMQ2icplugin->Initialize = (fMQInitializePlugin)GetProcAddress(hMQ2icplugin->hModule, "InitializePlugin");
		hMQ2icplugin->Initialize = (fMQInitializePlugin)GetProcAddress(hMQ2icplugin->hModule, "InitializePlugin");
		hMQ2icplugin->Initialize = (fMQInitializePlugin)GetProcAddress(hMQ2icplugin->hModule, "InitializePlugin");
		hMQ2icplugin->Initialize = (fMQInitializePlugin)GetProcAddress(hMQ2icplugin->hModule, "InitializePlugin");
		hMQ2icplugin->Initialize = (fMQInitializePlugin)GetProcAddress(hMQ2icplugin->hModule, "InitializePlugin");
		hMQ2icplugin->Initialize = (fMQInitializePlugin)GetProcAddress(hMQ2icplugin->hModule, "InitializePlugin");
		hMQ2icplugin->Shutdown = (fMQShutdownPlugin)GetProcAddress(hMQ2icplugin->hModule, "ShutdownPlugin");
		hMQ2icplugin->IncomingChat = (fMQIncomingChat)GetProcAddress(hMQ2icplugin->hModule, "OnIncomingChat");
		hMQ2icplugin->Pulse = (fMQPulse)GetProcAddress(hMQ2icplugin->hModule, "OnPulse");
		hMQ2icplugin->WriteChatColor = (fMQWriteChatColor)GetProcAddress(hMQ2icplugin->hModule, "OnWriteChatColor");
		hMQ2icplugin->Zoned = (fMQZoned)GetProcAddress(hMQ2icplugin->hModule, "OnZoned");
		hMQ2icplugin->CleanUI = (fMQCleanUI)GetProcAddress(hMQ2icplugin->hModule, "OnCleanUI");
		hMQ2icplugin->ReloadUI = (fMQReloadUI)GetProcAddress(hMQ2icplugin->hModule, "OnReloadUI");
		hMQ2icplugin->DrawHUD = (fMQDrawHUD)GetProcAddress(hMQ2icplugin->hModule, "OnDrawHUD");
		hMQ2icplugin->SetGameState = (fMQSetGameState)GetProcAddress(hMQ2icplugin->hModule, "SetGameState");
		hMQ2icplugin->AddSpawn = (fMQSpawn)GetProcAddress(hMQ2icplugin->hModule, "OnAddSpawn");
		hMQ2icplugin->RemoveSpawn = (fMQSpawn)GetProcAddress(hMQ2icplugin->hModule, "OnRemoveSpawn");
		hMQ2icplugin->AddGroundItem = (fMQGroundItem)GetProcAddress(hMQ2icplugin->hModule, "OnAddGroundItem");
		hMQ2icplugin->RemoveGroundItem = (fMQGroundItem)GetProcAddress(hMQ2icplugin->hModule, "OnRemoveGroundItem");
		hMQ2icplugin->BeginZone = (fMQBeginZone)GetProcAddress(hMQ2icplugin->hModule, "OnBeginZone");
		hMQ2icplugin->EndZone = (fMQEndZone)GetProcAddress(hMQ2icplugin->hModule, "OnEndZone");
		if (hMQ2icplugin->Initialize) {
			hMQ2icplugin->Initialize();
			printf("ISXEQ protected by MQ2Ic");
		}
	}
	else {
		DWORD dw; 
        char *errMsg; 
        dw = GetLastError(); 
        FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, 
        NULL, dw, 
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
        (LPTSTR) &errMsg, 0, NULL );
		//MessageBox(NULL, errMsg, "LoadLibrary of MQ2Ic.dll failed. I will exit now.", MB_SYSTEMMODAL | MB_OK);
        LocalFree( errMsg );
		printf("ISXEQ IS NOT protected by MQ2Ic");
		//exit(0);
	}
}

bool __cdecl MQ2Initialize(PMQPLUGIN plug, char*optionalmodulepath, size_t bufflen, HMODULE *module)
{
#else
bool __cdecl MQ2Initialize()
{
#endif
	if (!ghVariableLock)
		ghVariableLock = CreateMutex(NULL, FALSE, NULL);

	if (!ghMemberMapLock)
		ghMemberMapLock = CreateMutex(NULL, FALSE, NULL);
	MODULEINFO modinfo = {0};
	HMODULE heagamemod = GetModuleHandle(NULL);
	GetModuleInformation(GetCurrentProcess(), heagamemod, &modinfo, sizeof(MODULEINFO));
	g_eqgameimagesize = (DWORD)heagamemod + modinfo.SizeOfImage;
	if (GetModuleHandle("Lavish.dll") || GetModuleHandle("InnerSpace.dll")) {
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
        if((DWORD)EQMappableCommandList[i] == 0 || (DWORD)EQMappableCommandList[i] > g_eqgameimagesize) {
			//Sleep(0);//for debugging
            continue;
		}
        szEQMappableCommands[i]=EQMappableCommandList[i];
	}


    // as long nEQMappableCommands is right and these remain at the end, these should never need updating
    // who uses the unknowns anyway? - ieatacid
	// jul 16 2014 uhm had to update these, I didnt check the actual functions
	// so there is no guarantee calling for example TOGGLE_WINDOWMODE will work
	// but at least they are at the end again and nEQMappableCommands was 0x201 today,
	//but yeah I see no use for them... - eqmule
	// last update Mar 10 2015 nEQMappableCommands was 0x207
#if defined(ROF2EMU) || defined(UFEMU)
	szEQMappableCommands[nEQMappableCommands - 22] = "UNKNOWN0x1de";//"Magic"
	szEQMappableCommands[nEQMappableCommands - 21] = "UNKNOWN0x1df";//"Fire"
	szEQMappableCommands[nEQMappableCommands - 20] = "CHAT_SEMICOLON";//"Cold"
	szEQMappableCommands[nEQMappableCommands - 19] = "CHAT_SLASH";//"Disease"
	szEQMappableCommands[nEQMappableCommands - 18] = "INSTANT_CAMP";//"Poison"
	szEQMappableCommands[nEQMappableCommands - 17] = "UNKNOWN0x1e3";//"Physical"
	szEQMappableCommands[nEQMappableCommands - 16] = "UNKNOWN0x1e4";//"Corruption" confirmed 16 jul 2014 -eqmule
	szEQMappableCommands[nEQMappableCommands - 15] = "UNKNOWN0x1e5";//"Unknown"
	szEQMappableCommands[nEQMappableCommands - 14] = "UNKNOWN0x1e6";//"Avatar"
	szEQMappableCommands[nEQMappableCommands - 13] = "UNKNOWN0x1e7";//"RemoveButton"
	szEQMappableCommands[nEQMappableCommands - 12] = "CHAT_EMPTY";//"ClearAll"
	szEQMappableCommands[nEQMappableCommands - 11] = "TOGGLE_WINDOWMODE";//"ClearTaskBecauseTaskNotFound" confirmed 16 jul 2014 -eqmule
	szEQMappableCommands[nEQMappableCommands - 10] = "UNKNOWN0x1ea";//"NoPlayersLeft"
	szEQMappableCommands[nEQMappableCommands - 9] = "UNKNOWN0x1eb";//"CreatedSharedTask"
	szEQMappableCommands[nEQMappableCommands - 8] = "CHANGEFACE";//"Complete" confirmed 16 jul 2014 -eqmule
	szEQMappableCommands[nEQMappableCommands - 7] = "UNKNOWN0x1ed";//Expired
	szEQMappableCommands[nEQMappableCommands - 6] = "UNKNOWN0x1ee";//Script
	szEQMappableCommands[nEQMappableCommands - 5] = "UNKNOWN0x1ef";//LeaderRemoved
	szEQMappableCommands[nEQMappableCommands - 4] = "UNKNOWN0x1f0";
	szEQMappableCommands[nEQMappableCommands - 3] = "UNKNOWN0x1f1";
	szEQMappableCommands[nEQMappableCommands - 2] = "UNKNOWN0x1f2";
	szEQMappableCommands[nEQMappableCommands - 1] = "UNKNOWN0x1f3";
#else
	szEQMappableCommands[nEQMappableCommands - 22]="UNKNOWN0x20c";//"Magic"
    szEQMappableCommands[nEQMappableCommands - 21]="UNKNOWN0x20d";//"Fire"
    szEQMappableCommands[nEQMappableCommands - 20]="UNKNOWN0x20e";//"Cold"
    szEQMappableCommands[nEQMappableCommands - 19]="UNKNOWN0x20f";//"Disease"
    szEQMappableCommands[nEQMappableCommands - 18]="CHAT_SEMICOLON";//"Poison"
    szEQMappableCommands[nEQMappableCommands - 17]="CHAT_SLASH";//"Physical"
    szEQMappableCommands[nEQMappableCommands - 16]="INSTANT_CAMP";//"Corruption" confirmed 16 jul 2014 -eqmule
    szEQMappableCommands[nEQMappableCommands - 15]="UNKNOWN0x213";//"Unknown"
    szEQMappableCommands[nEQMappableCommands - 14]="UNKNOWN0x214";//"Avatar"
    szEQMappableCommands[nEQMappableCommands - 13]="UNKNOWN0x215";//"RemoveButton"
    szEQMappableCommands[nEQMappableCommands - 12]="CHAT_EMPTY";//"ClearAll"
    szEQMappableCommands[nEQMappableCommands - 11]="TOGGLE_WINDOWMODE";//"ClearTaskBecauseTaskNotFound" confirmed 16 jul 2014 -eqmule
    szEQMappableCommands[nEQMappableCommands - 10]="UNKNOWN0x218";//"NoPlayersLeft"
    szEQMappableCommands[nEQMappableCommands -  9]="UNKNOWN0x219";//"CreatedSharedTask"
    szEQMappableCommands[nEQMappableCommands -  8]="CHANGEFACE";//"Complete" confirmed 16 jul 2014 -eqmule
    szEQMappableCommands[nEQMappableCommands -  7]="UNKNOWN0x21b";//Expired
    szEQMappableCommands[nEQMappableCommands -  6]="UNKNOWN0x21c";//Script
    szEQMappableCommands[nEQMappableCommands -  5]="UNKNOWN0x21d";//LeaderRemoved
    szEQMappableCommands[nEQMappableCommands -  4]="UNKNOWN0x21e";
    szEQMappableCommands[nEQMappableCommands -  3]="UNKNOWN0x21f";
    szEQMappableCommands[nEQMappableCommands -  2]="UNKNOWN0x220";
    szEQMappableCommands[nEQMappableCommands -  1]="UNKNOWN0x221";
#endif

    for (nColorAdjective=0 ; szColorAdjective[nColorAdjective] ; nColorAdjective++){}
    for (nColorAdjectiveYou=0 ; szColorAdjectiveYou[nColorAdjectiveYou] ; nColorAdjectiveYou++) {}
    for (nColorExpletive=0 ; szColorExpletive[nColorExpletive] ; nColorExpletive++) {}
    for (nColorSyntaxError=0 ; szColorSyntaxError[nColorSyntaxError] ; nColorSyntaxError++) {}
    for (nColorMacroError=0 ; szColorMacroError[nColorMacroError] ; nColorMacroError++) {}
    for (nColorMQ2DataError=0 ; szColorMQ2DataError[nColorMQ2DataError] ; nColorMQ2DataError++) {}
    for (nColorFatalError=0 ; szColorFatalError[nColorFatalError] ; nColorFatalError++) {}
	
	InitializeCriticalSection(&gPluginCS);
	//from now on MQ2IC is not optional.
#ifdef ISXEQ
	LoadMQ2Plugin(plug,"mq2ic", optionalmodulepath,bufflen, module);
#else
	LoadMQ2Plugin("mq2ic");
#endif
	if (ghmq2ic = GetModuleHandle("mq2ic.dll"))
		InitializeMQ2IcExports();
    InitializeMQ2Benchmarks();
#ifndef ISXEQ
    InitializeParser();
#endif
    InitializeMQ2Detours();
    InitializeDisplayHook();
    InitializeChatHook();
    InitializeMQ2Spawns();
    InitializeMQ2Pulse();

#ifndef ISXEQ
	//ok so if we are precharselect we init here otherwise we init in HeartBeat
	DWORD gs = GetGameState();
	if(gs == GAMESTATE_PRECHARSELECT && bPluginCS==0 && gbLoad) {
	//we are loading stuff
		InitializeMQ2Commands();
		InitializeMQ2Windows();
		MQ2MouseHooks(1);
		Sleep(100);
		InitializeMQ2KeyBinds();
		InitializeMQ2Plugins();
		gbLoad = FALSE;
	} else {
		if(hLoadComplete) {
			WaitForSingleObject(hLoadComplete, 60000);
			Sleep(0);
		}
	}
#else
    InitializeMQ2Commands();
    InitializeMQ2Windows();
	MQ2MouseHooks(1);
    Sleep(100);
    InitializeMQ2KeyBinds();
#endif
//#ifndef ISXEQ
//    InitializeMQ2Plugins();
//#endif

	if (!ghLockPickZone)
		ghLockPickZone = CreateMutex(NULL, FALSE, NULL);
    return true;
}

void __cdecl MQ2Shutdown()
{
	OutputDebugString("MQ2Shutdown Called");
    DebugTry(ShutdownMQ2KeyBinds());
    DebugTry(ShutdownMQ2Spawns());
    DebugTry(ShutdownDisplayHook());
#ifndef ISXEQ
    DebugTry(ShutdownMQ2DInput());
#endif
    DebugTry(ShutdownChatHook());
#ifndef ISXEQ
    DebugTry(ShutdownMQ2Pulse());
//    DebugTry(ShutdownMQ2Plugins());
#endif
    DebugTry(ShutdownMQ2Windows());
	DebugTry(MQ2MouseHooks(0));
#ifndef ISXEQ
	RemoveDetour(EQPlayer__SetNameSpriteState); // put here so it doesnt crash :)
	DebugTry(ShutdownParser());
#endif
    DebugTry(ShutdownMQ2Commands());
    //needs to be done here
	DebugTry(ShutdownMQ2Plugins());
	DebugTry(DeInitializeMQ2IcExports());
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
	if (ghVariableLock) {
		ReleaseMutex(ghVariableLock);
		CloseHandle(ghVariableLock);
		ghVariableLock = 0;
	}
	if (ghMemberMapLock) {
		ReleaseMutex(ghMemberMapLock);
		CloseHandle(ghMemberMapLock);
		ghMemberMapLock = 0;
	}
	if (ghGetClassMemberLock) {
		ReleaseMutex(ghGetClassMemberLock);
		CloseHandle(ghGetClassMemberLock);
		ghGetClassMemberLock = 0;
	}
	if (ghCachedBuffsLock) {
		ReleaseMutex(ghCachedBuffsLock);
		CloseHandle(ghCachedBuffsLock);
		ghCachedBuffsLock = 0;
	}
}

DWORD __stdcall InitializeMQ2SpellDb(PVOID pData)
{
	switch ((DWORD)pData)
	{
		case 1:  { WriteChatfSafe("Initializing SpellMap from SetGameState."); break; }
		case 2:  { WriteChatfSafe("Initializing SpellMap from GetSpellByName."); break; }
		default: { WriteChatfSafe("Initializing SpellMap. (%d)", (DWORD)pData); break; }
	}
	if (!ghLockSpellMap)
		ghLockSpellMap = CreateMutex(NULL, FALSE, NULL);
	if (ghLockSpellMap) {
		while (!ppSpellMgr && gGameState != GAMESTATE_CHARSELECT && gGameState != GAMESTATE_INGAME) {
			Sleep(0);
		}
		while (ppSpellMgr && pSpellMgr && (!((PSPELLMGR)pSpellMgr)->Spells || (((PSPELLMGR)pSpellMgr)->Spells && !((PSPELLMGR)pSpellMgr)->Spells[TOTAL_SPELL_COUNT-1]))) {
			Sleep(0);
		}
		//test
		/*if (ClientSpellManager*pSMgr = (ClientSpellManager*)pSpellMgr) {
			pSMgr->Spells;
			Sleep(0);
		}*/
		//ok everything checks out lets fill our own map with spells
		PopulateSpellMap();
	}
	switch ((DWORD)pData)
	{
		case 1:  { WriteChatfSafe("SpellMap Initialized from SetGameState."); break; }
		case 2:  { WriteChatfSafe("SpellMap Initialized  from GetSpellByName."); break; }
		default: { WriteChatfSafe("SpellMap Initialized. (%d)", (DWORD)pData); break; }
	}
	ghInitializeMQ2SpellDb = 0;
	return 0;
}
#ifndef ISXEQ
#if defined(ROF2EMU) || defined(UFEMU)
//need to include any headers for your emu? add them here
#include "emu.h"
#endif
HMODULE GetCurrentModule()
{
	HMODULE hModule = NULL;
	GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)GetCurrentModule, &hModule);
	return hModule;
}
HANDLE hUnloadComplete = 0;
HANDLE hLoadComplete = 0;

// ***************************************************************************
// Function:    MQ2End Thread
// Description: Where we end execution during the ejection
// ***************************************************************************
DWORD WINAPI MQ2End(LPVOID lpParameter)
{
	DWORD gs = GetGameState();
	if(gs==GAMESTATE_PRECHARSELECT) {
		if(hUnloadComplete) {
			CloseHandle(hUnloadComplete);
			hUnloadComplete = 0;
		}
	}
	bRunNextCommand = TRUE;

		EndAllMacros();

	DebugSpew("%s", ToUnloadString);
	if (gs == GAMESTATE_INGAME || gs == GAMESTATE_CHARSELECT) {
		WriteChatColor(ToUnloadString, USERCOLOR_DEFAULT);
	}
	gbUnload = TRUE;
	return 0;
}
DWORD WINAPI GetlocalPlayerOffset()
{
	return (DWORD)pinstLocalPlayer_x;
}
void ForceUnload()
{
	DWORD oldscreenmode = ScreenMode;
	ScreenMode = 3;
	WriteChatColor(UnloadedString,USERCOLOR_DEFAULT);
	DebugSpewAlways("ForceUnload() called, this is not good %s", UnloadedString);
	//dont do this here ShutdownMQ2Plugins() will do it and its called from MQ2Shutdown();
	//UnloadMQ2Plugins();
	MQ2Shutdown();
	DebugSpew("Shutdown completed");
	g_Loaded = FALSE;
	ScreenMode = 2;
}

LONG WINAPI OurCrashHandler(EXCEPTION_POINTERS * ex)
{
	MQ2ExceptionFilter(0, ex, "OurCrashHandler");
	int mbret = MessageBox(NULL, "MQ2Start caught a crash.\nThis does NOT mean it was a MQ2 crash, it could also be a eqgame crash.\n\nYou can click retry and hope for the best, or just click cancel to kill the process right now.", "Crash Detected", MB_RETRYCANCEL|MB_DEFBUTTON1|MB_ICONERROR | MB_SYSTEMMODAL);
	if (mbret == IDCANCEL)
	{
		exit(0);
	}
	return EXCEPTION_CONTINUE_EXECUTION;
}
// ***************************************************************************
// Function:    MQ2Start Thread
// Description: Where we start execution during the insertion
// ***************************************************************************
DWORD WINAPI MQ2Start(LPVOID lpParameter)
{
	SetUnhandledExceptionFilter(OurCrashHandler);

	//_CrtSetDebugFillThreshold(0);
	ghCachedBuffsLock = CreateMutex(NULL, FALSE, NULL);
	ghGetClassMemberLock = CreateMutex(NULL, FALSE, NULL);
	hUnloadComplete = CreateEvent(NULL, TRUE, FALSE, NULL);
	hLoadComplete = CreateEvent(NULL, TRUE, FALSE, NULL);
	PCHAR lpINIPath = (PCHAR)lpParameter;
	strcpy_s(gszINIPath, lpINIPath);
	free(lpINIPath);
#if defined(ROF2EMU) || defined(UFEMU)
	MQ2StartEmu();//or whatever...
#endif
	CHAR szBuffer[MAX_STRING] = { 0 };
	//MessageBox(NULL, "Inject now", "MQ2 Debug", MB_OK);

	if (!MQ2Initialize()) {
		MessageBox(NULL, "Failed to Initialize MQ2 will free lib and exit", "MQ2 Error", MB_OK);
		if (HMODULE h = GetCurrentModule())
			FreeLibraryAndExitThread(h, 0);
	}
	while (gGameState != GAMESTATE_CHARSELECT && gGameState != GAMESTATE_INGAME) {
		if (gbUnload) {
			goto getout;
		}
		Sleep(500);
	}
    InitializeMQ2DInput();
	if (gGameState == GAMESTATE_INGAME || gGameState == GAMESTATE_CHARSELECT || gGameState == GAMESTATE_CHARCREATE) {
		gbInZone = TRUE;
		PluginsSetGameState(gGameState);
	}

    WriteChatfSafe(LoadedString);
    DebugSpewAlways("%s", LoadedString);
	
    while (!gbUnload) {
        Sleep(500);
    }
getout:
	if(hLoadComplete) {
		CloseHandle(hLoadComplete);
		hLoadComplete = 0;
	}
	if(hUnloadComplete) {
		DWORD dwtime = WaitForSingleObject(hUnloadComplete, 1800000);//30 mins so i can debug stuff
		if (dwtime == WAIT_TIMEOUT) {
			OutputDebugString("I am unloading in MQ2Start due to TIMEOUT");
			ForceUnload();
		}
		CloseHandle(hUnloadComplete);
		hUnloadComplete = 0;
	} else {
		OutputDebugString("I am unloading in MQ2Start this will probably crash");
		ForceUnload();
	}
	if(ScreenMode)
		ScreenMode = 2;
	if(HMODULE h = GetCurrentModule())
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
		AddStyle(CWS_TITLE | CWS_MINIMIZE);
		RemoveStyle(CWS_TRANSPARENT | CWS_CLOSE);
        OutputBox=(CStmlWnd*)GetChildItem("CW_ChatOutput");
		OutputBox->SetParentWindow((_CSIDLWND *)this);
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
                this->SetVisible(true);
                return 1;
            }
        }
        return CSidlScreenWnd::WndNotification(pWnd,Message,unknown);
    };

    //CTextEntryWnd *InputBox;
    CStmlWnd *OutputBox;
};


CMQNewsWnd *pNewsWindow=0;
VOID InsertMQ2News();
//#pragma once
#define CCXStr__operator_equal1_x CXStr__operator_equal1_x
#define CINITIALIZE_EQGAME_OFFSET(var) DWORD var = (((DWORD)var##_x - 0x400000) + (DWORD)GetModuleHandle(NULL))
CINITIALIZE_EQGAME_OFFSET(CCXStr__operator_equal1);
FUNCTION_AT_ADDRESS(class CCXStr& CCXStr::operator=(char const *),CCXStr__operator_equal1);

VOID CreateMQ2NewsWindow()
{
	//MessageBox(NULL, "inject in news", "news debug", MB_SYSTEMMODAL | MB_OK);
	//int sizeofCXWnd = sizeof(CXWnd);
	//int sizeofCSidlScreenWnd = sizeof(CSidlScreenWnd);
    CHAR Filename[MAX_STRING]={0};
    sprintf_s(Filename,"%s\\changes.txt",gszINIPath);
    if (!pNewsWindow && _FileExists(Filename))
    {
        pNewsWindow = new CMQNewsWnd("ChatWindow");
		pNewsWindow->SetBGColor(0xFF000000);
		pNewsWindow->SetLocation({ 230,620,850,920 });
		pNewsWindow->CSetWindowText("MacroQuest2 Recent Changes");
		pNewsWindow->SetZLayer(1);
    }
    InsertMQ2News();
}

VOID AddNewsLine(PCHAR Line, DWORD Color)
{
	CHAR szLine[MAX_STRING] = { 0 };
	strcpy_s(szLine, Line);
    Color=pChatManager->GetRGBAFromIndex(Color);

	CHAR szProcessed[MAX_STRING] = { 0 };
    MQToSTML(szLine,szProcessed,MAX_STRING,Color);
    strcat_s(szProcessed,"<br>");
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
    sprintf_s(Filename,"%s\\changes.txt",gszINIPath);
	FILE *file = 0;
	errno_t err = fopen_s(&file,Filename, "rb");
    if (err)
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
		char *Next_Token1 = 0;
		if (PCHAR Cmd = strtok_s(szLine, "\r\n", &Next_Token1)) {
			if (atoi(Cmd))
				AddNewsLine(Cmd, CONCOLOR_GREEN);
			else
				AddNewsLine(Cmd, CONCOLOR_YELLOW);
		}
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
#ifdef __CastRay2_x
FUNCTION_AT_ADDRESS(int CastRayLoc(const CVector3& SourcePos, int Race, float DestX, float DestY, float DestZ),__CastRay2);
#endif
#ifdef __CleanItemTags_x
//this really should be CXStr CleanItemTags(const CXStr& str) but i cant get that to compile so we fake it...
#if defined(ROF2EMU) || defined(UFEMU)
FUNCTION_AT_ADDRESS(CXStr *__cdecl CleanItemTags(CXStr *Out, const CXStr &In),__CleanItemTags);
#else
FUNCTION_AT_ADDRESS(CXStr *__cdecl CleanItemTags(CXStr *Out, const CXStr &In, bool bFlag),__CleanItemTags);
#endif
#endif
#ifdef __HeadingDiff_x
FUNCTION_AT_ADDRESS(float HeadingDiff(float h1, float h2, float *DiffOut),__HeadingDiff);
#endif
#ifdef __FixHeading_x
FUNCTION_AT_ADDRESS(float FixHeading(float Heading),__FixHeading);
#endif
#ifdef __FlushDxKeyboard_x
FUNCTION_AT_ADDRESS(int FlushDxKeyboard(), __FlushDxKeyboard);
#endif
#ifdef __get_bearing_x
FUNCTION_AT_ADDRESS(float get_bearing(float x1, float y1, float x2, float y2),__get_bearing)
#endif
#ifdef Util__FastTime_x
FUNCTION_AT_ADDRESS(unsigned long  GetFastTime(void),Util__FastTime);
#endif
#ifdef __CopyLayout_x
FUNCTION_AT_ADDRESS(bool CopyLayout(const CXStr& currlayout, const CXStr& newlayout, bool bHotbuttons, bool bLoadouts, bool bSocials, CXStr& ErrorOut, bool bForceReload),__CopyLayout);
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
#ifdef __GetAnimationCache_x
FUNCTION_AT_ADDRESS(class IconCache *__cdecl GetAnimationCache(int index), __GetAnimationCache);
#endif
#ifdef __SaveColors_x
FUNCTION_AT_ADDRESS(void SaveColors(int,int,int,int),__SaveColors);
#endif