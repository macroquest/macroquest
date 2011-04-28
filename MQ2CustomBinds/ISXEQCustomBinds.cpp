//
// ISXEQCustomBinds
//
#pragma warning(disable:4996)
#include "../ISXEQClient.h"
#include "ISXEQCustomBinds.h"
#include <tchar.h>

// The mandatory pre-setup function.  Our name is "ISXEQCustomBinds", and the class is ISXEQCustomBinds.
// This sets up a "ModulePath" variable which contains the path to this module in case we want it,
// and a "PluginLog" variable, which contains the path and filename of what we should use for our
// debug logging if we need it.  It also sets up a variable "pExtension" which is the pointer to
// our instanced class.
ISXPreSetup("ISXEQCustomBinds",ISXEQCustomBinds);

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

int CMD_CustomBind(int argc, char *argv[]);
map<utf8stringnocase,class CCustomBind *> CustomBinds;

class CCustomBind 
{
public:
    CCustomBind(const char *p_Name, const char *p_CommandDown, const char *p_CommandUp)
    {
        Name=p_Name;
        if (p_CommandUp)
            CommandUp=p_CommandUp;
        if (p_CommandDown)
            CommandUp=p_CommandDown;
    }
    ~CCustomBind()
    {
    }

    utf8string Name;
    utf8string CommandUp;
    utf8string CommandDown;
};

// Initialize is called by Inner Space when the extension should initialize.
bool ISXEQCustomBinds::Initialize(ISInterface *p_ISInterface)
{    pISInterface=p_ISInterface;

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

WriteChatf("ISXEQCustomBinds Loaded");
return true;
}

// shutdown sequence
void ISXEQCustomBinds::Shutdown()
{
    // save settings, if you changed them and want to save them now.  You should normally save
    // changes immediately.
    //pISInterface->SaveSettings(XMLFileName);

    //    pISInterface->UnloadSettings(XMLFileName);

    for (map<utf8stringnocase,class CCustomBind *>::iterator i=CustomBinds.begin() ; i!=CustomBinds.end() ; i++)
    {
        delete i->second;
    }
    CustomBinds.clear();
    DisconnectServices();

    UnRegisterServices();
    UnRegisterTopLevelObjects();
    UnRegisterDataTypes();
    UnRegisterAliases();
    UnRegisterCommands();
}


void ISXEQCustomBinds::ConnectServices()
{
    // connect to any services.  Here we connect to "Pulse" which receives a
    // message every frame (after the frame is displayed) and "Memory" which
    // wraps "detours" and memory modifications
    hPulseService=pISInterface->ConnectService(this,"Pulse",PulseService);
    hMemoryService=pISInterface->ConnectService(this,"Memory",MemoryService);
    hServicesService=pISInterface->ConnectService(this,"Services",ServicesService);


}

void ISXEQCustomBinds::RegisterCommands()
{
    // add any commands
    //    pISInterface->AddCommand("MyCommand",MyCommand,true,false);
    pISInterface->AddCommand("CustomBind",CMD_CustomBind,true,false);
}

void ISXEQCustomBinds::RegisterAliases()
{
    // add any aliases
}

void ISXEQCustomBinds::RegisterDataTypes()
{
    // add any datatypes
    // pMyType = new MyType;
    // pISInterface->AddLSType(*pMyType);
}

void ISXEQCustomBinds::RegisterTopLevelObjects()
{
    // add any Top-Level Objects
    //    pISInterface->AddTopLevelObject("MapSpawn",tloMapSpawn);
}

void ISXEQCustomBinds::RegisterServices()
{
    // register any services.  Here we demonstrate a service that does not use a
    // callback
    // set up a 1-way service (broadcast only)
    //    hISXEQCustomBindsService=pISInterface->RegisterService(this,"ISXEQCustomBinds Service",0);
    // broadcast a message, which is worthless at this point because nobody will receive it
    // (nobody has had a chance to connect)
    //    pISInterface->ServiceBroadcast(this,hISXEQCustomBindsService,ISXSERVICE_MSG+1,0);

}

void ISXEQCustomBinds::DisconnectServices()
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

void ISXEQCustomBinds::UnRegisterCommands()
{
    // remove commands
    pISInterface->RemoveCommand("CustomBind");
}
void ISXEQCustomBinds::UnRegisterAliases()
{
    // remove aliases
}
void ISXEQCustomBinds::UnRegisterDataTypes()
{
    // remove data types
    //if (pMyType)
    //{
    //    pISInterface->RemoveLSType(*pMyType);
    //    delete pMyType;
    //}
}
void ISXEQCustomBinds::UnRegisterTopLevelObjects()
{
    // remove Top-Level Objects
    //    pISInterface->RemoveTopLevelObject("MapSpawn");
}
void ISXEQCustomBinds::UnRegisterServices()
{
    // shutdown our own services
    //    if (hISXEQCustomBindsService)
    //        pISInterface->ShutdownService(this,hISXEQCustomBindsService);
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

VOID ExecuteCustomBind(PCHAR Name,BOOL Down);

CCustomBind *FindCustomBind(const char *Name)
{
    map<utf8stringnocase,CCustomBind *>::iterator i=CustomBinds.find(Name);
    if (i==CustomBinds.end())
        return 0;
    return i->second;
}

CCustomBind *AddCustomBind(const char *Name, const char *CommandDown, const char *CommandUp)
{
    if (AddMQ2KeyBind((char*)Name,ExecuteCustomBind))
    {
        CCustomBind *pBind = new CCustomBind(Name,CommandDown,CommandUp);
        CustomBinds[Name]=pBind;
        return pBind;
    }
    return 0;
}

bool RemoveCustomBind(const char *Name)
{
    CCustomBind *pBind=FindCustomBind(Name);
    if (!pBind)
        return false;
    delete pBind;
    CustomBinds.erase(Name);
    return true;
}

/*
VOID LoadCustomBinds();
VOID CustomBindCmd(PSPAWNINFO pChar, PCHAR szLine);
VOID SaveCustomBinds();
VOID LoadCustomBinds()
{
    CHAR filename[MAX_STRING];
    strcpy(filename,gszINIPath);
    strcat(filename,"\\MQ2CustomBinds.txt");
    FILE *file=fopen(filename,"rt");
    if (!file)
        return;
    CUSTOMBIND NewBind;
    ZeroMemory(&NewBind,sizeof(CUSTOMBIND));
    CHAR szLine[MAX_STRING];

    while(fgets(szLine,2048,file))
    {
        strtok(szLine,"\r\n");
        strtok(szLine,"=");
        if (!stricmp(szLine,"name"))
        {
            ZeroMemory(&NewBind,sizeof(CUSTOMBIND));
            strcpy(NewBind.Name,&szLine[5]);
        }
        else if (!stricmp(szLine,"up"))
        {
            strcpy(NewBind.CommandUp,&szLine[3]);
            AddCustomBind(NewBind.Name,NewBind.CommandDown,NewBind.CommandUp);
        }
        else if (!stricmp(szLine,"down"))
        {
            strcpy(NewBind.CommandDown,&szLine[5]);
        }
    }

    fclose(file);
}

VOID SaveCustomBinds()
{
    CHAR filename[MAX_STRING];
    strcpy(filename,gszINIPath);
    strcat(filename,"\\MQ2CustomBinds.txt");
    FILE *file=fopen(filename,"wt");
    if (!file)
        return;

    for (unsigned int N = 0 ; N < CustomBinds.Size ; N++)
        if (PCUSTOMBIND pBind=CustomBinds[N])
        {
            fprintf(file,"name=%s\ndown=%s\nup=%s\n",pBind->Name,pBind->CommandDown,pBind->CommandUp);
        }    
        fclose(file);
}
/**/

VOID ExecuteCustomBind(PCHAR Name,BOOL Down)
{
    CCustomBind *pBind=FindCustomBind(Name);
    if (!pBind)
        return;
    PCHARINFO pCharInfo=GetCharInfo();
    if (!pCharInfo)
        return;
    if (Down)
    {
        if (pBind->CommandDown.Characters())
            DoCommand(pCharInfo->pSpawn,pBind->CommandDown.unsafe_str());
    }
    else if (pBind->CommandUp.Characters())
        DoCommand(pCharInfo->pSpawn,pBind->CommandUp.unsafe_str());
}

int CMD_CustomBind(int argc, char *argv[])
{
    if (argc<2)
    {
        WriteChatf("Syntax: %s <-list|-add <name>|-delete <name>|-clear <name><-down|-up>|-set <name><-down|-up> <command>>",argv[0]);
        return 1;
    }
    //CHAR szBuffer[MAX_STRING];
    //CHAR szArg[MAX_STRING] = {0};
    //CHAR szArg2[MAX_STRING] = {0};
    //GetArg(szArg,szLine,1);
    //GetArg(szArg2,szLine,2);
    //PCHAR szRest = GetNextArg(szLine,2);

    if (!stricmp(argv[1],"-list"))
    {
        WriteChatColor("Custom binds");
        WriteChatColor("--------------");

        for (map<utf8stringnocase,CCustomBind *>::iterator i=CustomBinds.begin() ; i!=CustomBinds.end() ; i++)
            if (CCustomBind *pBind=i->second)
            {
                WriteChatf("[\ay%s\ax] [Down:\at%s\ax] [Up:\at%s\ax]",pBind->Name.c_str(),pBind->CommandDown.c_str(),pBind->CommandUp.c_str());
            }
            WriteChatColor("--------------");
            WriteChatColor("End custom binds");
            return 0;
    }
    if (!stricmp(argv[1],"-add"))
    {
        if (argc<3)
        {
            WriteChatf("Usage: %s -add <name>",argv[0]);
            return 1;
        }
        if (_tcschr(argv[2],'-'))
        {
            WriteChatColor("'-' is not allowed in a custom bind name");
        }
        if (AddCustomBind(argv[2],0,0))
        {
            WriteChatColor("Custom bind added.  Use /custombind set to set the custom commands.");
        }
        else
        {
            WriteChatColor("Failed to add custom bind (name in use)");
        }
        return 0;
    }
    if (!stricmp(argv[1],"-delete"))
    {
        if (argc<3)
        {
            WriteChatf("Usage: %s -delete <name>",argv[0]);
            return 1;
        }

        if (RemoveCustomBind(argv[2]))
        {
            WriteChatColor("Custom bind deleted");
        }
        else
        {
            WriteChatColor("Could not find custom bind with that name to delete");
        }
        return 0;
    }
    if (!stricmp(argv[1],"-set"))
    {
        if (argc<4)
        {
            WriteChatf("Usage: %s -set <name><-down|-up> <command>",argv[0]);
            return 1;
        }

        BOOL Down=true;
        if (PCHAR minus=strchr(argv[2],'-'))
        {
            minus[0]=0;
            if (!stricmp(&minus[1],"up"))
                Down=false;
        }
        CCustomBind *pBind=FindCustomBind(argv[2]);
        if (!pBind)
        {
            WriteChatf("Could not find custom bind '%s'",argv[2]);
            return 0;
        }
        if (Down)
            pBind->CommandDown=argv[3];
        else
            pBind->CommandUp=argv[3];
        WriteChatf("[\ay%s\ax] [Down:\at%s\ax] [Up:\at%s\ax]",pBind->Name.c_str(),pBind->CommandDown.c_str(),pBind->CommandUp.c_str());
//        SaveCustomBinds();
        return 0;
    }
    if (!stricmp(argv[1],"-clear"))
    {
        if (argc<3)
        {
            WriteChatf("Usage: %s -clear <name><-down|-up>",argv[0]);
            return 1;
        }

        BOOL Down=true;
        if (PCHAR minus=strchr(argv[2],'-'))
        {
            minus[0]=0;
            if (!stricmp(&minus[1],"up"))
                Down=false;
        }
        CCustomBind *pBind=FindCustomBind(argv[2]);
        if (!pBind)
        {
            WriteChatf("Could not find custom bind '%s'",argv[2]);
            return 0;
        }
        if (Down)
            pBind->CommandDown="";
        else
            pBind->CommandUp="";
        WriteChatf("[\ay%s\ax] [Down:\at%s\ax] [Up:\at%s\ax]",pBind->Name.c_str(),pBind->CommandDown.c_str(),pBind->CommandUp.c_str());
//        SaveCustomBinds();
        return 0;
    }

    WriteChatf("Syntax: %s <-list|-add <name>|-delete <name>|-clear <name><-down|-up>|-set <name><-down|-up> <command>>",argv[0]);
    return 1;
}
