//
// ISXEQTemplate
//
#pragma warning(disable:4996)
#include "../ISXEQClient.h"
#include "ISXEQTemplate.h"

// The mandatory pre-setup function.  Our name is "ISXEQTemplate", and the class is ISXEQTemplate.
// This sets up a "ModulePath" variable which contains the path to this module in case we want it,
// and a "PluginLog" variable, which contains the path and filename of what we should use for our
// debug logging if we need it.  It also sets up a variable "pExtension" which is the pointer to
// our instanced class.
ISXPreSetup("ISXEQTemplate",ISXEQTemplate);

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

unsigned int ISXEQTemplateXML=0;

// Forward declarations of callbacks
void __cdecl PulseService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl MemoryService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl ServicesService(bool Broadcast, unsigned int MSG, void *lpData);


// Initialize is called by Inner Space when the extension should initialize.
bool ISXEQTemplate::Initialize(ISInterface *p_ISInterface)
{    pISInterface=p_ISInterface;

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

WriteChatf("ISXEQTemplate Loaded");
return true;
}

// shutdown sequence
void ISXEQTemplate::Shutdown()
{
    // save settings, if you changed them and want to save them now.  You should normally save
    // changes immediately.
    //pISInterface->ExportSet(ISXEQTemplateXML,XMLFileName);

    pISInterface->UnloadSet(ISXEQTemplateXML);

    DisconnectServices();

    UnRegisterServices();
    UnRegisterTopLevelObjects();
    UnRegisterDataTypes();
    UnRegisterAliases();
    UnRegisterCommands();
}


void ISXEQTemplate::ConnectServices()
{
    // connect to any services.  Here we connect to "Pulse" which receives a
    // message every frame (after the frame is displayed) and "Memory" which
    // wraps "detours" and memory modifications
    hPulseService=pISInterface->ConnectService(this,"Pulse",PulseService);
    hMemoryService=pISInterface->ConnectService(this,"Memory",MemoryService);
    hServicesService=pISInterface->ConnectService(this,"Services",ServicesService);


}

void ISXEQTemplate::RegisterCommands()
{
    // add any commands
    //    pISInterface->AddCommand("MyCommand",MyCommand,true,false);

}

void ISXEQTemplate::RegisterAliases()
{
    // add any aliases
}

void ISXEQTemplate::RegisterDataTypes()
{
    // add any datatypes
    // pMyType = new MyType;
    // pISInterface->AddLSType(*pMyType);
}

void ISXEQTemplate::RegisterTopLevelObjects()
{
    // add any Top-Level Objects
    //    pISInterface->AddTopLevelObject("MapSpawn",tloMapSpawn);
}

void ISXEQTemplate::RegisterServices()
{
    // register any services.  Here we demonstrate a service that does not use a
    // callback
    // set up a 1-way service (broadcast only)
    //    hISXEQTemplateService=pISInterface->RegisterService(this,"ISXEQTemplate Service",0);
    // broadcast a message, which is worthless at this point because nobody will receive it
    // (nobody has had a chance to connect)
    //    pISInterface->ServiceBroadcast(this,hISXEQTemplateService,ISXSERVICE_MSG+1,0);

}

void ISXEQTemplate::DisconnectServices()
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

void ISXEQTemplate::UnRegisterCommands()
{
    // remove commands
    //    pISInterface->RemoveCommand("MyCommand");
}
void ISXEQTemplate::UnRegisterAliases()
{
    // remove aliases
}
void ISXEQTemplate::UnRegisterDataTypes()
{
    // remove data types
    //if (pMyType)
    //{
    //    pISInterface->RemoveLSType(*pMyType);
    //    delete pMyType;
    //}
}
void ISXEQTemplate::UnRegisterTopLevelObjects()
{
    // remove Top-Level Objects
    //    pISInterface->RemoveTopLevelObject("MapSpawn");
}
void ISXEQTemplate::UnRegisterServices()
{
    // shutdown our own services
    //    if (hISXEQTemplateService)
    //        pISInterface->ShutdownService(this,hISXEQTemplateService);
}

void ISXEQTemplate::LoadSettings()
{
    bool bChanged=false;

    // open the settings file, and store the ID number in ISXEQTemplateXML
    ISXEQTemplateXML=pISInterface->OpenSettings(XMLFileName);
    // This ID is used to refer to the base set of the loaded settings

    /*
    Here is an example settings hierarchy:
    base set
    ..settings
    .."General" set
    .."Characters" set
    ...."Server A" set
    ......"Character A" set
    ........settings
    ......"Character B" set
    ........settings
    ...."Server B" set
    ......"Character A" set
    ........settings
    ...."Server C" set 
    ......"Character A" set
    ........settings
    ......"Character B" set
    ........settings
    ......"Character C" set
    ........settings

    As you can see, there can be any number of nested sets, which can contain sets, settings, and comments.
    Any set can be referred to by its ID.  The base set is stored in ISXEQTemplateXML.  Note that the settings
    are NOT "xml" after loading them, they are simply settings stored in memory!
    */
    // Get General set ID, which can be a child of the base set
    if (unsigned int GeneralGUID=pISInterface->FindSet(ISXEQTemplateXML,"General"))
    {
        // retrieve a text setting from the General set
        char Text[512];
        if (pISInterface->GetSetting(GeneralGUID,"Name of setting",Text,512))
        {
            // success
        }
        unsigned int IntSetting;
        if (pISInterface->GetSetting(GeneralGUID,"Name of int setting",IntSetting))
        {
            // success
        }
    }
    /*
    Deeper sets and settings are accessed in exactly the same way.  If a sub-set of General was to be used,
    accessing it would work like so:
    if (unsigned int SubSetGUID=pISInterface->FindSet(GeneralGUID,"Sub-set name"))
    {
    // got the sub-set
    }
    */

    // save settings if we changed them
    if (bChanged)
        pISInterface->ExportSet(ISXEQTemplateXML,XMLFileName);
    // Note: ExportSet can save ANY set and its settings, sets, and comments as ANY filename.  The "General" set
    // could be stored as "General.XML" simply by doing pISInterface->ExportSet(GeneralGUID,"General.XML");
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

void __cdecl EQChatService(bool Broadcast, unsigned int MSG, void *lpData)
{
#define pChat ((_EQChat*)lpData)
    switch(MSG)
    {
    case CHATSERVICE_OUTGOING:
        // same as OnWriteChatColor
        break;
    case CHATSERVICE_INCOMING:
        // same as OnIncomingChat
        break;
    }
#undef pChat
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
        else if (!stricmp(Name,"EQ Chat Service"))
        {
            hEQChatService=pISInterface->ConnectService(pExtension,Name,EQChatService);
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
        else if (!stricmp(Name,"EQ Chat Service"))
        {
            if (hEQChatService)
            {
                pISInterface->DisconnectService(pExtension,hEQChatService);
                hEQChatService=0;
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
    pISInterface->GetArgs(1,argc,argv,FullText, sizeof(FullText)); // this gets the rest of the arguments, from 1 to argc
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
