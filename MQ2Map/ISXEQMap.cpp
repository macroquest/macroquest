//
// ISXEQMap
//

#include "../ISXEQClient.h"
#include <windows.h>
#include "ISXEQMap.h"
#include "MQ2Map.h"


// The mandatory pre-setup function.  Our name is "ISXEQMap", and the class is ISXEQMap.
// This sets up a "ModulePath" variable which contains the path to this module in case we want it,
// and a "PluginLog" variable, which contains the path and filename of what we should use for our
// debug logging if we need it.  It also sets up a variable "pExtension" which is the pointer to
// our instanced class.
ISXPreSetup("ISXEQMap",ISXEQMap);

// Basic LavishScript datatypes, these get retrieved on startup by our initialize function, so we can
// use them in our Top-Level Objects or custom datatypes
LSType *pStringType=0;
LSType *pIntType=0;
LSType *pBoolType=0;
LSType *pFloatType=0;
LSType *pTimeType=0;
LSType *pByteType=0;

ISInterface *pISInterface=0;
HISXSERVICE hPulseService=0;
HISXSERVICE hMemoryService=0;
HISXSERVICE hServicesService=0;

HISXSERVICE hEQChatService=0;
HISXSERVICE hEQUIService=0;
HISXSERVICE hEQGamestateService=0;
HISXSERVICE hEQSpawnService=0;
//HISXSERVICE hEQZoneService=0;

// Forward declarations of callbacks
void __cdecl PulseService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl MemoryService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl ServicesService(bool Broadcast, unsigned int MSG, void *lpData);

extern VOID CMyMapViewWnd__PostDraw();
extern VOID MapViewMap__HandleRButtonDown(DWORD point, DWORD unknown);
extern DWORD CMyMapViewWnd__Destructor(const BOOL Deallocate);
extern PCSIDLWNDVFTABLE CMyMapViewWnd__OldvfTable;
extern PCSIDLWNDVFTABLE MapViewMap_OldvfTable;
extern DWORD CMyMapViewWnd__OldDestructor;
extern DWORD CMyMapViewWnd__OldPostDraw;
extern DWORD MapViewMap__OldHandleRButtonDown;

class CMyMapViewWnd
{
public:
    DWORD Constructor_Trampoline(class CXWnd *);
    DWORD Constructor_Detour(class CXWnd *wnd)
    {
        CMapViewWnd *pWnd=(CMapViewWnd*)this;
        DWORD Ret=Constructor_Trampoline(wnd);
        PCSIDLWNDVFTABLE pvfTable = new CSIDLWNDVFTABLE; 
        PCSIDLWNDVFTABLE pMapViewMapVfTable = new CSIDLWNDVFTABLE;
        *pvfTable=*pWnd->pvfTable;
        *pMapViewMapVfTable=*((PEQMAPWINDOW)pWnd)->pMapViewMapVfTable;

        CMyMapViewWnd__OldvfTable=pWnd->pvfTable;
        pWnd->pvfTable=pvfTable;
        MapViewMap_OldvfTable=((PEQMAPWINDOW)pWnd)->pMapViewMapVfTable;
        ((PEQMAPWINDOW)pWnd)->pMapViewMapVfTable=pMapViewMapVfTable;
        CMyMapViewWnd__OldPostDraw=(DWORD)((PEQMAPWINDOW)pWnd)->pMapViewMapVfTable->PostDraw2;
        CMyMapViewWnd__OldDestructor=(DWORD)pWnd->pvfTable->vector_deleting_destructor;
        pWnd->pvfTable->vector_deleting_destructor=CMyMapViewWnd__Destructor;
        ((PEQMAPWINDOW)pWnd)->pMapViewMapVfTable->PostDraw2=CMyMapViewWnd__PostDraw;
        MapViewMap__OldHandleRButtonDown=(DWORD)((PEQMAPWINDOW)pWnd)->pMapViewMapVfTable->HandleRButtonDown;
        ((PEQMAPWINDOW)pWnd)->pMapViewMapVfTable->HandleRButtonDown=MapViewMap__HandleRButtonDown;

        return Ret;
    }

    static void StealVFTable()
    {
        if (CMapViewWnd *pWnd=(CMapViewWnd*)pMapViewWnd)
        {
            PCSIDLWNDVFTABLE pvfTable = new CSIDLWNDVFTABLE;
            PCSIDLWNDVFTABLE pMapViewMapVfTable = new CSIDLWNDVFTABLE;
            *pvfTable=*pWnd->pvfTable;
            *pMapViewMapVfTable=*((PEQMAPWINDOW)pWnd)->pMapViewMapVfTable;

            CMyMapViewWnd__OldvfTable=pWnd->pvfTable;
            pWnd->pvfTable=pvfTable;
            MapViewMap_OldvfTable=((PEQMAPWINDOW)pWnd)->pMapViewMapVfTable;
            ((PEQMAPWINDOW)pWnd)->pMapViewMapVfTable=pMapViewMapVfTable;
            CMyMapViewWnd__OldPostDraw=(DWORD)((PEQMAPWINDOW)pWnd)->pMapViewMapVfTable->PostDraw2;
            CMyMapViewWnd__OldDestructor=(DWORD)pWnd->pvfTable->vector_deleting_destructor;
            pWnd->pvfTable->vector_deleting_destructor=CMyMapViewWnd__Destructor;
            ((PEQMAPWINDOW)pWnd)->pMapViewMapVfTable->PostDraw2=CMyMapViewWnd__PostDraw;
            MapViewMap__OldHandleRButtonDown=(DWORD)((PEQMAPWINDOW)pWnd)->pMapViewMapVfTable->HandleRButtonDown;
            ((PEQMAPWINDOW)pWnd)->pMapViewMapVfTable->HandleRButtonDown=MapViewMap__HandleRButtonDown;
        }
    }

    static void RestoreVFTable()
    {
        if (CMapViewWnd *pWnd=(CMapViewWnd*)pMapViewWnd)
        {
            if (CMyMapViewWnd__OldvfTable && MapViewMap_OldvfTable)
            { 
                delete pWnd->pvfTable;
                pWnd->pvfTable=CMyMapViewWnd__OldvfTable;
                delete ((PEQMAPWINDOW)pWnd)->pMapViewMapVfTable;
                ((PEQMAPWINDOW)pWnd)->pMapViewMapVfTable = MapViewMap_OldvfTable;
            }
        }
    }
};

extern bool Update;
// Initialize is called by Inner Space when the extension should initialize.
bool ISXEQMap::Initialize(ISInterface *p_ISInterface)
{    pISInterface=p_ISInterface;

    // retrieve basic ISData types
    pStringType=pISInterface->FindLSType("string");
    pIntType=pISInterface->FindLSType("int");
    pBoolType=pISInterface->FindLSType("bool");
    pFloatType=pISInterface->FindLSType("float");
    pTimeType=pISInterface->FindLSType("time");
    pByteType=pISInterface->FindLSType("byte");


    pISInterface->OpenSettings("ISXEQMap.XML");

    bmMapRefresh=AddMQ2Benchmark("Map Refresh");
    unsigned int i;
    CHAR szBuffer[MAX_STRING]={0};
    for (i=0;MapFilterOptions[i].szName;i++) {
        sprintf(szBuffer,"%s Color",MapFilterOptions[i].szName);
        int Temp;
        if (pISInterface->GetSettingi("ISXEQMap.XML","Map Filters",MapFilterOptions[i].szName,Temp))
            MapFilterOptions[i].Enabled=Temp;
        else
            MapFilterOptions[i].Enabled=MapFilterOptions[i].Default;

        if (pISInterface->GetSettingi("ISXEQMap.XML","Map Filters",szBuffer,Temp))
            MapFilterOptions[i].Color=Temp|0xFF000000;
        else
            MapFilterOptions[i].Color=MapFilterOptions[i].DefaultColor|0xFF000000;
    }
    MapInit();
    pISInterface->GetSetting("ISXEQMap.XML","Naming Schemes","Normal",MapNameString,sizeof(MapNameString));
    pISInterface->GetSetting("ISXEQMap.XML","Naming Schemes","Target",MapTargetNameString,sizeof(MapTargetNameString));

    for (i=1;i<16;i++)
    {
        sprintf(szBuffer,"KeyCombo%d",i);
        pISInterface->GetSetting("ISXEQMap.XML","Right Click",szBuffer,MapSpecialClickString[i],sizeof(MapSpecialClickString[i]));
    }

    // Do not use Custom, since the string isn't stored
    MapFilterOptions[MAPFILTER_Custom].Enabled = 0;


    ConnectServices();

    RegisterCommands();
    RegisterAliases();
    RegisterDataTypes();
    RegisterTopLevelObjects();
    RegisterServices();

    EzDetour(CMapViewWnd__CMapViewWnd,&CMyMapViewWnd::Constructor_Detour,&CMyMapViewWnd::Constructor_Trampoline);
    CMyMapViewWnd::StealVFTable();

    printf("ISXEQMap Loaded");
    return true;
}

// shutdown sequence
void ISXEQMap::Shutdown()
{
    Update=false;

    RemoveDetour(CMapViewWnd__CMapViewWnd);

    MapClear();
    CMyMapViewWnd::RestoreVFTable();
    RemoveMQ2Benchmark(bmMapRefresh);

    pISInterface->RemoveCommand("MapHide");
    pISInterface->RemoveCommand("MapShow");
    pISInterface->RemoveCommand("MapFilter");
    pISInterface->RemoveCommand("Highlight");
    pISInterface->RemoveCommand("MapNames");
    pISInterface->RemoveCommand("MapClick");

    pISInterface->UnloadSettings("ISXEQMap.xml");

    DisconnectServices();

    UnRegisterServices();
    UnRegisterTopLevelObjects();
    UnRegisterDataTypes();
    UnRegisterAliases();
    UnRegisterCommands();
}


void ISXEQMap::ConnectServices()
{
    // connect to any services.  Here we connect to "Pulse" which receives a
    // message every frame (after the frame is displayed) and "Memory" which
    // wraps "detours" and memory modifications
    hPulseService=pISInterface->ConnectService(this,"Pulse",PulseService);
    hMemoryService=pISInterface->ConnectService(this,"Memory",MemoryService);
    hServicesService=pISInterface->ConnectService(this,"Services",ServicesService);


}

extern int CMD_MapFilter(int argc, char *argv[]);
extern int CMD_MapHide(int argc, char *argv[]);
extern int CMD_MapShow(int argc, char *argv[]);
extern int CMD_MapHighlight(int argc, char *argv[]);
extern int CMD_MapNames(int argc, char *argv[]);
extern int CMD_MapClick(int argc, char *argv[]);
void ISXEQMap::RegisterCommands()
{
    // add any commands
    //    pISInterface->AddCommand("MyCommand",MyCommand,true,false);

    pISInterface->AddCommand("MapFilter",CMD_MapFilter,true,false);
    pISInterface->AddCommand("MapHide",CMD_MapHide,true,false);
    pISInterface->AddCommand("MapShow",CMD_MapShow,true,false);
    pISInterface->AddCommand("Highlight",CMD_MapHighlight,true,false);
    pISInterface->AddCommand("MapNames",CMD_MapNames,true,false);
    pISInterface->AddCommand("MapClick",CMD_MapClick,true,false);

}

void ISXEQMap::RegisterAliases()
{
    // add any aliases
}

void ISXEQMap::RegisterDataTypes()
{
    // add any datatypes
    // pMyType = new MyType;
    // pISInterface->AddLSType(*pMyType);
}

void ISXEQMap::RegisterTopLevelObjects()
{
    // add any Top-Level Objects
    pISInterface->AddTopLevelObject("MapSpawn",dataMapSpawn);
}

void ISXEQMap::RegisterServices()
{
    // register any services.  Here we demonstrate a service that does not use a
    // callback
    // set up a 1-way service (broadcast only)
    //    hISXEQMapService=pISInterface->RegisterService(this,"ISXEQMap Service",0);
    // broadcast a message, which is worthless at this point because nobody will receive it
    // (nobody has had a chance to connect)
    //    pISInterface->ServiceBroadcast(this,hISXEQMapService,ISXSERVICE_MSG+1,0);

}

void ISXEQMap::DisconnectServices()
{
    // gracefully disconnect from services
    if (hPulseService)
        pISInterface->DisconnectService(this,hPulseService);
    if (hMemoryService)
    {
        pISInterface->DisconnectService(this,hMemoryService);
        // memory modifications are automatically undone when disconnecting
        // also, since this service accepts messages from clients we should reset our handle to
        // 0 to make sure we dont try to continue using it
        hMemoryService=0; 
    }
    if (hServicesService)
        pISInterface->DisconnectService(this,hServicesService);
}

void ISXEQMap::UnRegisterCommands()
{
    // remove commands
    //    pISInterface->RemoveCommand("MyCommand");
}
void ISXEQMap::UnRegisterAliases()
{
    // remove aliases
}
void ISXEQMap::UnRegisterDataTypes()
{
    // remove data types

}
void ISXEQMap::UnRegisterTopLevelObjects()
{
    // remove Top-Level Objects
    pISInterface->RemoveTopLevelObject("MapSpawn");
}
void ISXEQMap::UnRegisterServices()
{
    // shutdown our own services
    //    if (hISXEQMapService)
    //        pISInterface->ShutdownService(this,hISXEQMapService);
}

void __cdecl PulseService(bool Broadcast, unsigned int MSG, void *lpData)
{
    if (MSG==PULSE_PULSE)
    {
        // "OnPulse"
    }
}

void __cdecl MemoryService(bool Broadcast, unsigned int MSG, void *lpData)
{
    // no messages are currently associated with this service (other than
    // system messages such as client disconnect), so do nothing.
}

void __cdecl EQUIService(bool Broadcast, unsigned int MSG, void *lpData)
{
    switch(MSG)
    {
    case UISERVICE_CLEANUP:
        break;
    case UISERVICE_RELOAD:
        break;
    }
}
void __cdecl EQGamestateService(bool Broadcast, unsigned int MSG, void *lpData)
{
#define GameState ((unsigned int)lpData)
    if (MSG==GAMESTATESERVICE_CHANGED)
    {
        if (GameState==3)
        {
            MapClear();
        }
    }
#undef GameState
}
void __cdecl EQSpawnService(bool Broadcast, unsigned int MSG, void *lpData)
{
    switch(MSG)
    {
#define pNewSpawn ((PSPAWNINFO)lpData)
    case SPAWNSERVICE_ADDSPAWN:
        if (Update && pNewSpawn->SpawnID != 0 && GetCharInfo()->pSpawn != pNewSpawn)
        {
            DebugSpewAlways("MQ2Map::OnAddSpawn(%s)",pNewSpawn->Name);
            AddSpawn(pNewSpawn);
        }
        break;
    case SPAWNSERVICE_REMOVESPAWN:
        DebugSpewAlways("MQ2Map::OnRemoveSpawn(%s)",pNewSpawn->Name);
        if (Update)
            RemoveSpawn(pNewSpawn);
        break;
#undef pNewSpawn
#define pGroundItem ((PGROUNDITEM)lpData)
    case SPAWNSERVICE_ADDITEM:
        DebugSpewAlways("MQ2Map::OnAddGroundItem(%d)",pGroundItem->DropID);
        if (Update)
            AddGroundItem(pGroundItem);
        break;
    case SPAWNSERVICE_REMOVEITEM:
        DebugSpewAlways("MQ2Map::OnRemoveGroundItem(%d)",pGroundItem->DropID);
        if (Update)
            RemoveGroundItem(pGroundItem);
        break;
#undef pGroundItem
    }
}

/*
void __cdecl EQZoneService(bool Broadcast, unsigned int MSG, void *lpData)
{
    switch(MSG)
    {
    case ZONESERVICE_BEGINZONE:
        break;
    case ZONESERVICE_ENDZONE:
        break;
    case ZONESERVICE_ZONED:
        break;
    }
}/**/

void __cdecl ServicesService(bool Broadcast, unsigned int MSG, void *lpData)
{
#define Name ((char*)lpData)
    switch(MSG)
    {
    case SERVICES_ADDED:
        if (!stricmp(Name,"EQ UI Service"))
        {
            hEQUIService=pISInterface->ConnectService(pExtension,Name,EQUIService);
        }
        else if (!stricmp(Name,"EQ Gamestate Service"))
        {
            hEQGamestateService=pISInterface->ConnectService(pExtension,Name,EQGamestateService);
        }
        else if (!stricmp(Name,"EQ Spawn Service"))
        {
            hEQSpawnService=pISInterface->ConnectService(pExtension,Name,EQSpawnService);
        }
        /*
        else if (!stricmp(Name,"EQ Zone Service"))
        {
            hEQZoneService=pISInterface->ConnectService(pExtension,Name,EQZoneService);
        }
        /**/
        break;
    case SERVICES_REMOVED:
        if (!stricmp(Name,"EQ UI Service"))
        {
            if (hEQUIService)
            {
                pISInterface->DisconnectService(pExtension,hEQUIService);
                hEQUIService=0;
            }
        }
        else if (!stricmp(Name,"EQ Gamestate Service"))
        {
            if (hEQGamestateService)
            {
                pISInterface->DisconnectService(pExtension,hEQGamestateService);
                hEQGamestateService=0;
            }
        }
        else if (!stricmp(Name,"EQ Spawn Service"))
        {
            if (hEQSpawnService)
            {
                pISInterface->DisconnectService(pExtension,hEQSpawnService);
                hEQSpawnService=0;
            }
        }
        /*
        else if (!stricmp(Name,"EQ Zone Service"))
        {
            if (hEQZoneService)
            {
                pISInterface->DisconnectService(pExtension,hEQZoneService);
                hEQZoneService=0;
            }
        }
        /**/
        break;
    }
#undef Name
}
