//
// ISXEQItemDisplay
//
// complete
#pragma warning(disable:4996)
#include "../ISXEQClient.h"
#include "ISXEQItemDisplay.h"

// just use the MQ2 plugin as an include
#include "MQ2ItemDisplay.cpp"

// The mandatory pre-setup function.  Our name is "ISXEQItemDisplay", and the class is ISXEQItemDisplay.
// This sets up a "ModulePath" variable which contains the path to this module in case we want it,
// and a "PluginLog" variable, which contains the path and filename of what we should use for our
// debug logging if we need it.  It also sets up a variable "pExtension" which is the pointer to
// our instanced class.
ISXPreSetup("ISXEQItemDisplay",ISXEQItemDisplay);

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
bool ISXEQItemDisplay::Initialize(ISInterface *p_ISInterface)
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

    ConnectServices();

    RegisterCommands();
    RegisterAliases();
    RegisterDataTypes();
    RegisterTopLevelObjects();
    RegisterServices();
    EzDetour(CItemDisplayWnd__SetSpell,&ItemDisplayHook::SetSpell_Detour,&ItemDisplayHook::SetSpell_Trampoline);
    EzDetour(CItemDisplayWnd__UpdateStrings, &ItemDisplayHook::UpdateStrings_Detour, &ItemDisplayHook::UpdateStrings_Trampoline);
    //EzDetour(CXWnd__DrawTooltipAtPoint,&XWndHook::DrawTooltipAtPoint_Detour,&XWndHook::DrawTooltipAtPoint_Trampoline);
    //EzDetour(CInvSlotWnd__DrawTooltip, &InvSlotWndHook::DrawTooltip_Detour, &InvSlotWndHook::DrawTooltip_Trampoline);

    WriteChatf("ISXEQItemDisplay Loaded");
    return true;
}

// shutdown sequence
void ISXEQItemDisplay::Shutdown()
{
    RemoveDetour(CItemDisplayWnd__SetSpell);
    RemoveDetour(CItemDisplayWnd__UpdateStrings);
    //RemoveDetour(CXWnd__DrawTooltipAtPoint);
    //RemoveDetour(CInvSlotWnd__DrawTooltip);

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


void ISXEQItemDisplay::ConnectServices()
{
    // connect to any services.  Here we connect to "Pulse" which receives a
    // message every frame (after the frame is displayed) and "Memory" which
    // wraps "detours" and memory modifications
    hMemoryService=pISInterface->ConnectService(this,"Memory",MemoryService);
}

void ISXEQItemDisplay::RegisterCommands()
{
    // add any commands
    //    pISInterface->AddCommand("MyCommand",MyCommand,true,false);

}

void ISXEQItemDisplay::RegisterAliases()
{
    // add any aliases
}

void ISXEQItemDisplay::RegisterDataTypes()
{
    // add any datatypes
    // pMyType = new MyType;
    // pISInterface->AddLSType(*pMyType);
}

void ISXEQItemDisplay::RegisterTopLevelObjects()
{
    // add any Top-Level Objects
    //    pISInterface->AddTopLevelObject("MapSpawn",tloMapSpawn);
}

void ISXEQItemDisplay::RegisterServices()
{
    // register any services.  Here we demonstrate a service that does not use a
    // callback
    // set up a 1-way service (broadcast only)
    //    hISXEQItemDisplayService=pISInterface->RegisterService(this,"ISXEQItemDisplay Service",0);
    // broadcast a message, which is worthless at this point because nobody will receive it
    // (nobody has had a chance to connect)
    //    pISInterface->ServiceBroadcast(this,hISXEQItemDisplayService,ISXSERVICE_MSG+1,0);

}

void ISXEQItemDisplay::DisconnectServices()
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

void ISXEQItemDisplay::UnRegisterCommands()
{
    // remove commands
    //    pISInterface->RemoveCommand("MyCommand");
}
void ISXEQItemDisplay::UnRegisterAliases()
{
    // remove aliases
}
void ISXEQItemDisplay::UnRegisterDataTypes()
{
    // remove data types
    //if (pMyType)
    //{
    //    pISInterface->RemoveLSType(*pMyType);
    //    delete pMyType;
    //}
}
void ISXEQItemDisplay::UnRegisterTopLevelObjects()
{
    // remove Top-Level Objects
    //    pISInterface->RemoveTopLevelObject("MapSpawn");
}
void ISXEQItemDisplay::UnRegisterServices()
{
    // shutdown our own services
    //    if (hISXEQItemDisplayService)
    //        pISInterface->ShutdownService(this,hISXEQItemDisplayService);
}

void __cdecl MemoryService(bool Broadcast, unsigned int MSG, void *lpData)
{
    // no messages are currently associated with this service (other than
    // system messages such as client disconnect), so do nothing.
}

