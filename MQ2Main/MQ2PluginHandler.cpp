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
#if !defined(ISXEQ) && !defined(ISXEQ_LEGACY)

#if !defined(CINTERFACE)
#error /DCINTERFACE
#endif

#define DBG_SPEW

//#define DEBUG_PLUGINS

#ifdef DEBUG_PLUGINS
#define PluginDebug DebugSpew
#else
#define PluginDebug //
#endif

#include "MQ2Main.h"


CRITICAL_SECTION gPluginCS;
BOOL bPluginCS=0;

DWORD checkme(char *module)
{
    char *p;
    PIMAGE_DOS_HEADER pd = (PIMAGE_DOS_HEADER)module;
    PIMAGE_FILE_HEADER pf;
    p = module + pd->e_lfanew;
    p += 4;  //skip sig
    pf = (PIMAGE_FILE_HEADER) p;
    return pf->TimeDateStamp;
}

static unsigned int mq2mainstamp = 0;


DWORD LoadMQ2Plugin(const PCHAR pszFilename,BOOL bCustom)
{
    CHAR Filename[MAX_PATH]={0};

    strcpy(Filename,pszFilename);
    strlwr(Filename);
    PCHAR Temp=strstr(Filename,".dll");
	if (Temp)
        Temp[0]=0;
    if (!stricmp(Filename,"mq2warp")) // ^_^
    {
        return 0;
    }
    CHAR TheFilename[MAX_STRING]={0};
    sprintf(TheFilename,"%s.dll",Filename);
	if(HMODULE hThemod = GetModuleHandle(TheFilename)) {
		DebugSpew("LoadMQ2Plugin(0)(%s) already loaded",TheFilename);
		return 2;
	}
    CAutoLock Lock(&gPluginCS);
    DebugSpew("LoadMQ2Plugin(%s)",Filename);

    CHAR FullFilename[MAX_STRING]={0};
    sprintf(FullFilename,"%s\\%s.dll",gszINIPath,Filename);

    if (!mq2mainstamp) {
        mq2mainstamp = checkme((char*)GetModuleHandle("mq2main.dll"));
    }
	
    HMODULE hmod=LoadLibrary(FullFilename);
    if (!hmod)
    {
        DebugSpew("LoadMQ2Plugin(%s) Failed",Filename);
        return 0;
    }
    if (mq2mainstamp > checkme((char*)hmod)) {
        char tmpbuff[MAX_PATH];
        sprintf(tmpbuff, "Please recompile %s -- it is out of date with respect to mq2main (%d>%d)", FullFilename, mq2mainstamp, checkme((char*)hmod));
        DebugSpew(tmpbuff);
        MessageBoxA(NULL, tmpbuff, "Plugin Load Failed", MB_OK);
        FreeLibrary(hmod);
        return 0;
    }

    PMQPLUGIN pPlugin=pPlugins;
    while(pPlugin)
    {
        if (hmod==pPlugin->hModule)
        {
            DebugSpew("LoadMQ2Plugin(%s) already loaded",Filename);
            // LoadLibrary count must match FreeLibrary count for unloading to work.
            FreeLibrary(hmod);
            return 2; // already loaded
        }
        pPlugin=pPlugin->pNext;
    }

    pPlugin = new MQPLUGIN;
    memset(pPlugin,0,sizeof(MQPLUGIN));
	pPlugin->bCustom=bCustom;
    pPlugin->hModule=hmod;
    strcpy(pPlugin->szFilename,Filename);
    pPlugin->Initialize=(fMQInitializePlugin)GetProcAddress(hmod,"InitializePlugin");
    pPlugin->Shutdown=(fMQShutdownPlugin)GetProcAddress(hmod,"ShutdownPlugin");
    pPlugin->IncomingChat=(fMQIncomingChat)GetProcAddress(hmod,"OnIncomingChat");
    pPlugin->Pulse=(fMQPulse)GetProcAddress(hmod,"OnPulse");
    pPlugin->WriteChatColor=(fMQWriteChatColor)GetProcAddress(hmod,"OnWriteChatColor");
    pPlugin->Zoned=(fMQZoned)GetProcAddress(hmod,"OnZoned");
    pPlugin->CleanUI=(fMQCleanUI)GetProcAddress(hmod,"OnCleanUI");
    pPlugin->ReloadUI=(fMQReloadUI)GetProcAddress(hmod,"OnReloadUI");
    pPlugin->DrawHUD=(fMQDrawHUD)GetProcAddress(hmod,"OnDrawHUD");
    pPlugin->SetGameState=(fMQSetGameState)GetProcAddress(hmod,"SetGameState");
    pPlugin->AddSpawn=(fMQSpawn)GetProcAddress(hmod,"OnAddSpawn");
    pPlugin->RemoveSpawn=(fMQSpawn)GetProcAddress(hmod,"OnRemoveSpawn");
    pPlugin->AddGroundItem=(fMQGroundItem)GetProcAddress(hmod,"OnAddGroundItem");
    pPlugin->RemoveGroundItem=(fMQGroundItem)GetProcAddress(hmod,"OnRemoveGroundItem");
    pPlugin->BeginZone=(fMQBeginZone)GetProcAddress(hmod,"OnBeginZone"); 
    pPlugin->EndZone=(fMQEndZone)GetProcAddress(hmod,"OnEndZone"); 

    float *ftmp = (float*) GetProcAddress(hmod,"?MQ2Version@@3MA");
    if (ftmp)
		pPlugin->fpVersion = *ftmp;
    else pPlugin->fpVersion = 1.0;

    if (pPlugin->Initialize)
        pPlugin->Initialize();
    PluginCmdSort();
    if (pPlugin->SetGameState)
        pPlugin->SetGameState(gGameState);
    if (pPlugin->AddSpawn && gGameState==GAMESTATE_INGAME)
    {
        PSPAWNINFO pSpawn=(PSPAWNINFO)pSpawnList;
        while(pSpawn)
        {
            pPlugin->AddSpawn(pSpawn);
            pSpawn=pSpawn->pNext;
        }
    }
    if (pPlugin->AddGroundItem && gGameState==GAMESTATE_INGAME)
    {
        PGROUNDITEM pItem=*(PGROUNDITEM*)pItemList;
        while(pItem)
        {
            pPlugin->AddGroundItem(pItem);
            pItem=pItem->pNext;
        }
    }

    pPlugin->pLast=0;
    pPlugin->pNext=pPlugins;
    if (pPlugins)
        pPlugins->pLast=pPlugin;
    pPlugins=pPlugin;

    sprintf(FullFilename,"%s-AutoExec",Filename);
    LoadCfgFile(FullFilename,false);
    return 1;
}

BOOL UnloadMQ2Plugin(const PCHAR pszFilename)
{
    DebugSpew("UnloadMQ2Plugin");
    CHAR Filename[MAX_PATH]={0};
    strcpy(Filename,pszFilename);
    strlwr(Filename);
    PCHAR Temp=strstr(Filename,".dll");
    if (Temp)
        Temp[0]=0;

    // find plugin in list
    CAutoLock Lock(&gPluginCS);
    PMQPLUGIN pPlugin=pPlugins;
    while(pPlugin)
    {
        if (!stricmp(Filename,pPlugin->szFilename))
        {
            if (pPlugin->pLast)
                pPlugin->pLast->pNext=pPlugin->pNext;
            else
                pPlugins=pPlugin->pNext;
            if (pPlugin->pNext)
                pPlugin->pNext->pLast=pPlugin->pLast;

            if (pPlugin->CleanUI)
                pPlugin->CleanUI();
            if (pPlugin->Shutdown)
                pPlugin->Shutdown();
            FreeLibrary(pPlugin->hModule);
            delete pPlugin;
            return 1;
        }
        pPlugin=pPlugin->pNext;
    }

    return 0;
}

VOID RewriteMQ2Plugins(VOID)
{
    CAutoLock Lock(&gPluginCS);
	CHAR PluginList[MAX_STRING*10] = {0};
    CHAR szBuffer[MAX_STRING] = {0};
    CHAR MainINI[MAX_STRING] = {0};
    sprintf(MainINI,"%s\\macroquest.ini",gszINIPath);
	DWORD dwAttrs = 0,bChangedfileattribs = 0;
	if ((dwAttrs = GetFileAttributes(MainINI))!=INVALID_FILE_ATTRIBUTES) {
		if(dwAttrs & FILE_ATTRIBUTE_READONLY) {
			bChangedfileattribs = 1;
			SetFileAttributes(MainINI,FILE_ATTRIBUTE_NORMAL);
		}
	}
    GetPrivateProfileString("Plugins",NULL,"",PluginList,MAX_STRING*10,MainINI);
    PCHAR pPluginList = PluginList;
	BOOL loadvalue = 0;
    while (pPluginList[0]!=0) {
		WritePrivateProfileString("Plugins",pPluginList,"0",gszINIFilename);
        pPluginList+=strlen(pPluginList)+1;
    }
    PMQPLUGIN pLoop = pPlugins;
    if (!pLoop) {
		if(bChangedfileattribs) {
			SetFileAttributes(MainINI,dwAttrs);
		}
        return;
	}
    // start from the end, we're writing this the order they were added.
    while (pLoop->pNext)
        pLoop=pLoop->pNext; 
    while (pLoop) {
		if(!pLoop->bCustom)
			WritePrivateProfileString("Plugins",pLoop->szFilename,"1",gszINIFilename);
        pLoop = pLoop->pLast;
    }
	if(bChangedfileattribs) {
		SetFileAttributes(MainINI,dwAttrs);
	}
}

VOID InitializeMQ2Plugins()
{
    DebugSpew("Initializing plugins");
    bmWriteChatColor=AddMQ2Benchmark("WriteChatColor");
    bmPluginsIncomingChat=AddMQ2Benchmark("PluginsIncomingChat");
    bmPluginsPulse=AddMQ2Benchmark("PluginsPulse");
    bmPluginsOnZoned=AddMQ2Benchmark("PluginsOnZoned");
    bmPluginsCleanUI=AddMQ2Benchmark("PluginsCleanUI");
    bmPluginsReloadUI=AddMQ2Benchmark("PluginsReloadUI");
    bmPluginsDrawHUD=AddMQ2Benchmark("PluginsDrawHUD");
    bmPluginsSetGameState=AddMQ2Benchmark("PluginsSetGameState");
    bmCalculate=AddMQ2Benchmark("Calculate");
    bmBeginZone=AddMQ2Benchmark("BeginZone"); 
    bmEndZone=AddMQ2Benchmark("EndZone"); 

    InitializeCriticalSection(&gPluginCS);
    bPluginCS=1;

    CHAR PluginList[MAX_STRING*10] = {0};
    CHAR szBuffer[MAX_STRING] = {0};
    CHAR MainINI[MAX_STRING] = {0};
    sprintf(MainINI,"%s\\macroquest.ini",gszINIPath);
    GetPrivateProfileString("Plugins",NULL,"",PluginList,MAX_STRING*10,MainINI);
    PCHAR pPluginList = PluginList;
	BOOL loadvalue = 0;
    while (pPluginList[0]!=0) {
        GetPrivateProfileString("Plugins",pPluginList,"",szBuffer,MAX_STRING,MainINI);
        if (IsNumber(szBuffer)) {
			loadvalue=atoi(szBuffer);
			szBuffer[0] = '\0';
		}
		if(loadvalue==1 || szBuffer[0]!=0) {
            LoadMQ2Plugin(pPluginList);
        }
        pPluginList+=strlen(pPluginList)+1;
    }
	//ok now check if user has a CustomPlugin.ini and load those as well...
	sprintf(MainINI,"%s\\CustomPlugins.ini",gszINIPath);
    GetPrivateProfileString("Plugins",NULL,"",PluginList,MAX_STRING*10,MainINI);
    pPluginList = PluginList;
    while (pPluginList[0]!=0) {
        GetPrivateProfileString("Plugins",pPluginList,"",szBuffer,MAX_STRING,MainINI);
        if (IsNumber(szBuffer)) {
			loadvalue=atoi(szBuffer);
			szBuffer[0] = '\0';
		}
		if(loadvalue==1 || szBuffer[0]!=0) {
            LoadMQ2Plugin(pPluginList,1);
        }
        pPluginList+=strlen(pPluginList)+1;
    }
}

VOID UnloadMQ2Plugins()
{
    CAutoLock Lock(&gPluginCS);
    while(pPlugins)
    {
        DebugSpew("%s->Unload()",pPlugins->szFilename);
        UnloadMQ2Plugin(pPlugins->szFilename);
    }
}

VOID ShutdownMQ2Plugins()
{
    bPluginCS=0;
    {
        CAutoLock Lock(&gPluginCS);
        while(pPlugins)
        {
            DebugSpew("%s->Unload()",pPlugins->szFilename);
            UnloadMQ2Plugin(pPlugins->szFilename);
        }
    }
    Sleep(50); // fixes crash on Windows 7 (Vista too?) in RtlpWaitOnCriticalSection
    DeleteCriticalSection(&gPluginCS);
}

VOID WriteChatColor(PCHAR Line, DWORD Color, DWORD Filter)
{
    if (!bPluginCS)
        return;
    if (gFilterMQ)
        return;
    PluginDebug("Begin WriteChatColor()");
    EnterMQ2Benchmark(bmWriteChatColor);

	if(size_t len = strlen(Line)) {
		if(char *PlainText = (char*)LocalAlloc(LPTR,len+1)) {
			StripMQChat(Line,PlainText);
			CheckChatForEvent(PlainText);
			LocalFree(PlainText);
		}
		DebugSpew("WriteChatColor(%s)",Line);
	}
	CAutoLock Lock(&gPluginCS);
	PMQPLUGIN pPlugin=pPlugins;
	while(pPlugin)
	{
		if (pPlugin->WriteChatColor)
		{
			pPlugin->WriteChatColor(Line,Color,Filter);
		}
		pPlugin=pPlugin->pNext;
	}
    ExitMQ2Benchmark(bmWriteChatColor);
}

BOOL PluginsIncomingChat(PCHAR Line, DWORD Color)
{
    PluginDebug("PluginsIncomingChat()");
    if (!bPluginCS)
        return 0;
    if(!Line[0])
        return 0;
    CAutoLock Lock(&gPluginCS);
    PMQPLUGIN pPlugin=pPlugins;
    BOOL Ret=0;
    while(pPlugin)
    {
        if (pPlugin->IncomingChat)
        {
            Ret|=pPlugin->IncomingChat(Line,Color);
        }
        pPlugin=pPlugin->pNext;
    }
    return Ret;
}

VOID PulsePlugins()
{
    PluginDebug("PulsePlugins()");
    if (!bPluginCS)
        return;
    CAutoLock Lock(&gPluginCS);
    PMQPLUGIN pPlugin=pPlugins;
    while(pPlugin)
    {
        if (pPlugin->Pulse)
        {
            //DebugSpew("%s->Pulse()",pPlugin->szFilename);
            pPlugin->Pulse();
        }
		if(pPlugin && pPlugin->pNext) {
			pPlugin=pPlugin->pNext;
		} else {
			pPlugin=0;
		}
    }    
}

VOID PluginsZoned()
{
    PluginDebug("PluginsZoned()");
    if (!bPluginCS)
        return;
    CAutoLock Lock(&gPluginCS);
    PMQPLUGIN pPlugin=pPlugins;
    while(pPlugin)
    {
        if (pPlugin->Zoned)
        {
            DebugSpew("%s->Zoned()",pPlugin->szFilename);
            pPlugin->Zoned();
        }
        pPlugin=pPlugin->pNext;
    }
    char szTemp[256];
    sprintf(szTemp, "You have entered %s.", ((PZONEINFO)pZoneInfo)->LongName);
    CheckChatForEvent(szTemp);
}

VOID PluginsCleanUI()
{
    PluginDebug("PluginsCleanUI()");
    if (!bPluginCS)
        return;
    CAutoLock Lock(&gPluginCS);
    PMQPLUGIN pPlugin=pPlugins;
    DeleteMQ2NewsWindow();
    while(pPlugin)
    {
        if (pPlugin->CleanUI)
        {
            DebugSpew("%s->CleanUI()",pPlugin->szFilename);
            pPlugin->CleanUI();
        }
        pPlugin=pPlugin->pNext;
    }
}

VOID PluginsReloadUI()
{
    PluginDebug("PluginsReloadUI()");
    if (!bPluginCS)
        return;
    CAutoLock Lock(&gPluginCS);
    PMQPLUGIN pPlugin=pPlugins;
    while(pPlugin)
    {
        if (pPlugin->ReloadUI)
        {
            DebugSpew("%s->ReloadUI()",pPlugin->szFilename);
            pPlugin->ReloadUI();
        }
        pPlugin=pPlugin->pNext;
    }
}

VOID PluginsSetGameState(DWORD GameState)
{
    PluginDebug("PluginsSetGameState()");
    static bool AutoExec=false;
    static bool CharSelect=true;
    DrawHUDParams[0]=0;
    if (!bPluginCS)
        return;
    gGameState=GameState;
    if (GameState==GAMESTATE_INGAME)
    {
        gZoning=false;
        gbDoAutoRun=TRUE;
        if (!AutoExec)
        {
            AutoExec=true;
            LoadCfgFile("AutoExec",false);
        }
        if (CharSelect)
        {
            CharSelect=false;
            CHAR szBuffer[MAX_STRING]={0};

DebugSpew("PluginsSetGameState( %s server)",EQADDR_SERVERNAME);
            if (PCHARINFO pCharInfo=GetCharInfo())
            {
DebugSpew("PluginsSetGameState( %s name)",pCharInfo->Name);
                sprintf(szBuffer,"%s_%s",EQADDR_SERVERNAME,pCharInfo->Name);
                LoadCfgFile(szBuffer,false);
            }
            if (PCHARINFO2 pCharInfo2=GetCharInfo2())
            {
DebugSpew("PluginsSetGameState( %d class)",pCharInfo2->Class);
                sprintf(szBuffer,"%s",GetClassDesc(pCharInfo2->Class));
                LoadCfgFile(szBuffer,false);
            }
        }
    }
    else if (GameState==GAMESTATE_CHARSELECT)
    {
        if (!AutoExec)
        {
            AutoExec=true;
            LoadCfgFile("AutoExec",false);
        }
		DWORD nThreadId = 0;
		CreateThread(NULL, 0, InitializeMQ2SpellDb, 0, 0, &nThreadId);
        CharSelect=true;
        LoadCfgFile("CharSelect",false);
    }

    CAutoLock Lock(&gPluginCS);
    DebugSpew("PluginsSetGameState(%d)",GameState);
    PMQPLUGIN pPlugin=pPlugins;
    while(pPlugin)
    {
        if (pPlugin->SetGameState)
        {
            DebugSpew("%s->SetGameState(%d)",pPlugin->szFilename,GameState);
            pPlugin->SetGameState(GameState);
        }
        pPlugin=pPlugin->pNext;
    }
}

VOID PluginsDrawHUD()
{
    PluginDebug("PluginsDrawHUD()");
    if (!bPluginCS)
        return;
    CAutoLock Lock(&gPluginCS);
    PMQPLUGIN pPlugin=pPlugins;
    while(pPlugin)
    {
        if (pPlugin->DrawHUD)
        {
            pPlugin->DrawHUD();
        }
        pPlugin=pPlugin->pNext;
    }
}

VOID PluginsAddSpawn(PSPAWNINFO pNewSpawn)
{
    DWORD BodyType=GetBodyType(pNewSpawn);
    PluginDebug("PluginsAddSpawn(%s,%d,%d)",pNewSpawn->Name,pNewSpawn->Race,BodyType);
    if (!bPluginCS)
        return;
    if (gGameState>GAMESTATE_CHARSELECT)
        SetNameSpriteState(pNewSpawn,1);
    if (GetBodyTypeDesc(BodyType)[0]=='*')
    {
        WriteChatf("Spawn '%s' has unknown bodytype %d",pNewSpawn->Name,BodyType);
    }
    CAutoLock Lock(&gPluginCS);
    PMQPLUGIN pPlugin=pPlugins;
    while(pPlugin)
    {
        if (pPlugin->AddSpawn)
        {
            pPlugin->AddSpawn(pNewSpawn);
        }
        pPlugin=pPlugin->pNext;
    }
}

VOID PluginsRemoveSpawn(PSPAWNINFO pSpawn)
{
    PluginDebug("PluginsRemoveSpawn(%s)",pSpawn->Name);
    SpawnByName.erase(pSpawn->Name);
    if (!bPluginCS)
        return;
    CAutoLock Lock(&gPluginCS);
    PMQPLUGIN pPlugin=pPlugins;
    while(pPlugin)
    {
        if (pPlugin->RemoveSpawn)
        {
            pPlugin->RemoveSpawn(pSpawn);
        }
        pPlugin=pPlugin->pNext;
    }
}

VOID PluginsAddGroundItem(PGROUNDITEM pNewGroundItem)
{
    PluginDebug("PluginsAddGroundItem()");
    if (!bPluginCS)
        return;
    CAutoLock Lock(&gPluginCS);
    PMQPLUGIN pPlugin=pPlugins;
    DebugSpew("PluginsAddGroundItem(%s) %.1f,%.1f,%.1f",pNewGroundItem->Name,pNewGroundItem->X,pNewGroundItem->Y,pNewGroundItem->Z);
    while(pPlugin)
    {
        if (pPlugin->AddGroundItem)
        {
            pPlugin->AddGroundItem(pNewGroundItem);
        }
        pPlugin=pPlugin->pNext;
    }
}

VOID PluginsRemoveGroundItem(PGROUNDITEM pGroundItem)
{
    PluginDebug("PluginsRemoveGroundItem()");
    if (!bPluginCS)
        return;
    CAutoLock Lock(&gPluginCS);
    PMQPLUGIN pPlugin=pPlugins;
    while(pPlugin)
    {
        if (pPlugin->RemoveGroundItem)
        {
            pPlugin->RemoveGroundItem(pGroundItem);
        }
        pPlugin=pPlugin->pNext;
    }
}

VOID PluginsBeginZone() 
{ 
    PluginDebug("PluginsBeginZone()"); 
    if (!bPluginCS) 
        return; 
    gbInZone=false;
    CAutoLock Lock(&gPluginCS); 
    PMQPLUGIN pPlugin=pPlugins; 
    while(pPlugin) 
    { 
        if (pPlugin->BeginZone) 
        { 
            DebugSpew("%s->BeginZone()",pPlugin->szFilename); 
            pPlugin->BeginZone(); 
        } 
        pPlugin=pPlugin->pNext; 
    } 
} 

VOID PluginsEndZone() 
{ 
    PluginDebug("PluginsEndZone()"); 
    if (!bPluginCS) 
        return;
    gbInZone=true;
    CAutoLock Lock(&gPluginCS); 
    PMQPLUGIN pPlugin=pPlugins; 
    while(pPlugin) 
    { 
        if (pPlugin->EndZone) 
        { 
            DebugSpew("%s->EndZone()",pPlugin->szFilename); 
            pPlugin->EndZone(); 
        } 
        pPlugin=pPlugin->pNext; 
    } 
    LoadCfgFile("zoned",true);
    LoadCfgFile(((PZONEINFO)pZoneInfo)->ShortName,true);
} 

#endif
