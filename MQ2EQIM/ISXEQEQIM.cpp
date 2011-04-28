//
// ISXEQEQIM
//
#pragma warning(disable:4996)
#include "../ISXEQClient.h"
#include "ISXEQEQIM.h"

// The mandatory pre-setup function.  Our name is "ISXEQEQIM", and the class is ISXEQEQIM.
// This sets up a "ModulePath" variable which contains the path to this module in case we want it,
// and a "PluginLog" variable, which contains the path and filename of what we should use for our
// debug logging if we need it.  It also sets up a variable "pExtension" which is the pointer to
// our instanced class.
ISXPreSetup("ISXEQEQIM",ISXEQEQIM);

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
HISXSERVICE hEQZoneService=0;

// Forward declarations of callbacks
void __cdecl PulseService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl MemoryService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl ServicesService(bool Broadcast, unsigned int MSG, void *lpData);


// Initialize is called by Inner Space when the extension should initialize.
bool ISXEQEQIM::Initialize(ISInterface *p_ISInterface)
{
    pISInterface=p_ISInterface;

    // retrieve basic ISData types
    pStringType=pISInterface->FindLSType("string");
    pIntType=pISInterface->FindLSType("int");
    pBoolType=pISInterface->FindLSType("bool");
    pFloatType=pISInterface->FindLSType("float");
    pTimeType=pISInterface->FindLSType("time");
    pByteType=pISInterface->FindLSType("byte");


    pISInterface->OpenSettings(XMLFileName);
    LoadSettings();

    ConnectServices();

    RegisterCommands();
    RegisterAliases();
    RegisterDataTypes();
    RegisterTopLevelObjects();
    RegisterServices();

    WriteChatf("ISXEQEQIM Loaded");
    return true;
}

// shutdown sequence
void ISXEQEQIM::Shutdown()
{
    // save settings, if you changed them and want to save them now.  You should normally save
    // changes immediately.
    //pISInterface->SaveSettings(XMLFileName);

    pISInterface->UnloadSettings(XMLFileName);

    DisconnectServices();

    UnRegisterServices();
    UnRegisterTopLevelObjects();
    UnRegisterDataTypes();
    UnRegisterAliases();
    UnRegisterCommands();
}


void ISXEQEQIM::ConnectServices()
{
    // connect to any services.  Here we connect to "Pulse" which receives a
    // message every frame (after the frame is displayed) and "Memory" which
    // wraps "detours" and memory modifications
    hPulseService=pISInterface->ConnectService(this,"Pulse",PulseService);
    hMemoryService=pISInterface->ConnectService(this,"Memory",MemoryService);
    hServicesService=pISInterface->ConnectService(this,"Services",ServicesService);


}

void ISXEQEQIM::RegisterCommands()
{
    // add any commands
    //    pISInterface->AddCommand("MyCommand",MyCommand,true,false);

}

void ISXEQEQIM::RegisterAliases()
{
    // add any aliases
}

void ISXEQEQIM::RegisterDataTypes()
{
    // add any datatypes
    // pMyType = new MyType;
    // pISInterface->AddLSType(*pMyType);
}

void ISXEQEQIM::RegisterTopLevelObjects()
{
    // add any Top-Level Objects
    //    pISInterface->AddTopLevelObject("MapSpawn",tloMapSpawn);
}

void ISXEQEQIM::RegisterServices()
{
    // register any services.  Here we demonstrate a service that does not use a
    // callback
    // set up a 1-way service (broadcast only)
    //    hISXEQEQIMService=pISInterface->RegisterService(this,"ISXEQEQIM Service",0);
    // broadcast a message, which is worthless at this point because nobody will receive it
    // (nobody has had a chance to connect)
    //    pISInterface->ServiceBroadcast(this,hISXEQEQIMService,ISXSERVICE_MSG+1,0);

}

void ISXEQEQIM::DisconnectServices()
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

void ISXEQEQIM::UnRegisterCommands()
{
    // remove commands
    //    pISInterface->RemoveCommand("MyCommand");
}
void ISXEQEQIM::UnRegisterAliases()
{
    // remove aliases
}
void ISXEQEQIM::UnRegisterDataTypes()
{
    // remove data types
    //if (pMyType)
    //{
    //    pISInterface->RemoveLSType(*pMyType);
    //    delete pMyType;
    //}
}
void ISXEQEQIM::UnRegisterTopLevelObjects()
{
    // remove Top-Level Objects
    //    pISInterface->RemoveTopLevelObject("MapSpawn");
}
void ISXEQEQIM::UnRegisterServices()
{
    // shutdown our own services
    //    if (hISXEQEQIMService)
    //        pISInterface->ShutdownService(this,hISXEQEQIMService);
}

void ISXEQEQIM::LoadSettings()
{
    // IS provides easy methods of reading and writing settings of all types (bool, int, string, float, etc)
    bool BoolSetting=true;
    char StringSetting[512]={0};
    int IntSetting=15;
    float FloatSetting=25.3f;
    if (!pISInterface->GetSettingi(XMLFileName,"My Section","My Int Setting",IntSetting))
    {
        // int setting did not exist, should we modify the xml?
        // It returned false, so IntSetting is still our default value of 15. Let's
        // use that from here, and store it in the xml
        pISInterface->SetSettingi(XMLFileName,"My Section","My Int Setting",IntSetting);
    }
    if (!pISInterface->GetSettingb(XMLFileName,"My Section","My Bool Setting",BoolSetting))
    {
        // bool setting did not exist, should we modify the xml?
        // It returned false, so BoolSetting is still our default value of true. Let's
        // use that from here, and store it.
        // Bool settings are stored as integers, so just use SetSettingi
        pISInterface->SetSettingi(XMLFileName,"My Section","My Bool Setting",BoolSetting);
    }
    if (!pISInterface->GetSettingf(XMLFileName,"My Section","My Float Setting",FloatSetting))
    {
        // float setting did not exist, should we modify the xml?
        // It returned false, so FloatSetting is still our default value of 25.3. Let's
        // use that from here, and store it.
        pISInterface->SetSettingf(XMLFileName,"My Section","My Float Setting",FloatSetting);
    }
    if (!pISInterface->GetSetting(XMLFileName,"My Section","My String Setting",StringSetting,sizeof(StringSetting)))
    {
        // string setting did not exist, should we modify the xml?
        // It returned false, so StringSetting is still our default empty string. 
        // Let's set it to a new default, "ISXEQEQIM", and store it.
        strcpy(StringSetting,"ISXEQEQIM");
        pISInterface->SetSetting(XMLFileName,"My Section","My String Setting",StringSetting);
    }

    // save settings if we changed them
    pISInterface->SaveSettings(XMLFileName);
}


void __cdecl PulseService(bool Broadcast, unsigned int MSG, void *lpData)
{
    if (MSG==PULSE_PULSE)
    {
        // Same as OnPulse
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
        // same as OnCleanUI
        break;
    case UISERVICE_RELOAD:
        // same as OnReloadUI
        break;
    }
}
void __cdecl EQGamestateService(bool Broadcast, unsigned int MSG, void *lpData)
{
#define GameState ((unsigned int)lpData)
    if (MSG==GAMESTATESERVICE_CHANGED)
    {
        // same as SetGameState
    }
#undef GameState
}
void __cdecl EQSpawnService(bool Broadcast, unsigned int MSG, void *lpData)
{
    switch(MSG)
    {
#define pSpawn ((PSPAWNINFO)lpData)
    case SPAWNSERVICE_ADDSPAWN:
        // same as OnAddSpawn
        break;
    case SPAWNSERVICE_REMOVESPAWN:
        // same as OnRemoveSpawn
        break;
#undef pSpawn
#define pGroundItem ((PGROUNDITEM)lpData)
    case SPAWNSERVICE_ADDITEM:
        // same as OnAddGroundItem
        break;
    case SPAWNSERVICE_REMOVEITEM:
        // same as OnRemoveGroundItem
        break;
#undef pGroundItem
    }
}

void __cdecl EQZoneService(bool Broadcast, unsigned int MSG, void *lpData)
{
    switch(MSG)
    {
    case ZONESERVICE_BEGINZONE:
        // same as OnBeginZone
        break;
    case ZONESERVICE_ENDZONE:
        // same as OnEndZone
        break;
    case ZONESERVICE_ZONED:
        // same as OnZoned
        break;
    }
}

// This uses the Services service to connect to ISXEQ services
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
        else if (!stricmp(Name,"EQ Zone Service"))
        {
            hEQZoneService=pISInterface->ConnectService(pExtension,Name,EQZoneService);
        }
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
        else if (!stricmp(Name,"EQ Zone Service"))
        {
            if (hEQZoneService)
            {
                pISInterface->DisconnectService(pExtension,hEQZoneService);
                hEQZoneService=0;
            }
        }
        break;
    }
#undef Name
}

int MyCommand(int argc, char *argv[])
{
    // IS Commands work just like console programs. argc is the argument (aka parameter) count, 
    // argv is an array containing them.  The name of the command is always the first argument.
    if (argc<2)
    {
        // This command requires arguments
        WriteChatf("Syntax: %s <text>",argv[0]);
        return 0;
    }

    char FullText[8192]={0};
    pISInterface->GetArgs(1,argc,argv,FullText,sizeof(FullText)); // this gets the rest of the arguments, from 1 to argc
    WriteChatf("You passed the following text to the command:");
    WriteChatf("%s",FullText);

    // For most commands, you need to deal with only one argument at a time, instead of the entire line.
    for (int i = 1 ; i < argc ; i++)
    {
        WriteChatf("argv[%d]=\"%s\"",i,argv[i]);
    }

    // return 0 or greater for normal conditions, or return -1 for an error that should stop
    // a script. 
    return 0;
}
