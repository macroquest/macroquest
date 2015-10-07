// MQ2CustomBinds.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup, do NOT do it in DllMain.



#include "../MQ2Plugin.h"


PreSetup("MQ2CustomBinds");


typedef struct _CustomBind {
    CHAR Name[32];
    CHAR CommandDown[MAX_STRING];
    CHAR CommandUp[MAX_STRING];
} CUSTOMBIND, *PCUSTOMBIND;

CIndex<PCUSTOMBIND> CustomBinds(10);

VOID ExecuteCustomBind(PCHAR Name,BOOL Down);

int FindCustomBind(PCHAR Name)
{
    for (unsigned long N = 0 ; N < CustomBinds.Size ; N++)
        if (PCUSTOMBIND pBind=CustomBinds[N])
        {
            if (!_stricmp(Name,pBind->Name))
                return N;
        }
        return -1;
}

PCUSTOMBIND AddCustomBind(PCHAR Name, PCHAR CommandDown, PCHAR CommandUp)
{
    if (AddMQ2KeyBind(Name,ExecuteCustomBind))
    {
        PCUSTOMBIND pBind = new CUSTOMBIND;
        ZeroMemory(pBind,sizeof(CUSTOMBIND));
        strcpy(pBind->Name,Name);
        if (CommandDown)
            strcpy(pBind->CommandDown,CommandDown);
        if (CommandUp)
            strcpy(pBind->CommandUp,CommandUp);
        CustomBinds+=pBind;
        return pBind;
    }
    return 0;
}

VOID RemoveCustomBind(unsigned long N)
{
    if (N>=CustomBinds.Size)
        return;
    if (PCUSTOMBIND pBind=CustomBinds[N])
    {
        RemoveMQ2KeyBind(pBind->Name);
        delete pBind;
        CustomBinds[N]=0;
    }
}

VOID LoadCustomBinds();
VOID CustomBindCmd(PSPAWNINFO pChar, PCHAR szLine);
VOID SaveCustomBinds();

// Called once, when the plugin is to initialize
PLUGIN_API VOID InitializePlugin(VOID)
{
    DebugSpewAlways("Initializing MQ2CustomBinds");

    AddCommand("/custombind",CustomBindCmd,0,0,0);
    // Add commands, macro parameters, hooks, etc.
    // AddCommand("/mycommand",MyCommand);
    // AddParm("$myparm(x)",MyParm);
    // AddXMLFile("MQUI_MyXMLFile.xml");
    // bmMyBenchmark=AddMQ2Benchmark("My Benchmark Name");
}

// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
    DebugSpewAlways("Shutting down MQ2CustomBinds");
    RemoveCommand("/custombind");
    //SaveCustomBinds();

    for (unsigned long N = 0 ; N < CustomBinds.Size ; N++)
        if (PCUSTOMBIND pBind=CustomBinds[N])
        {
            RemoveMQ2KeyBind(pBind->Name);
        }
        CustomBinds.Cleanup();
        // Remove commands, macro parameters, hooks, etc.
        // RemoveMQ2Benchmark(bmMyBenchmark);
        // RemoveParm("$myparm(x)");
        // RemoveCommand("/mycommand");
        // RemoveXMLFile("MQUI_MyXMLFile.xml");
}

PLUGIN_API VOID SetGameState(DWORD GameState)
{
    static bool BindsLoaded=false;
    if (GameState==GAMESTATE_INGAME || GameState==GAMESTATE_CHARSELECT) 
    {
        if (!BindsLoaded) 
        {
            LoadCustomBinds();
            BindsLoaded=true;
        }
    }
}

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
        if (!_stricmp(szLine,"name"))
        {
            ZeroMemory(&NewBind,sizeof(CUSTOMBIND));
            strcpy(NewBind.Name,&szLine[5]);
        }
        else if (!_stricmp(szLine,"up"))
        {
            strcpy(NewBind.CommandUp,&szLine[3]);
            AddCustomBind(NewBind.Name,NewBind.CommandDown,NewBind.CommandUp);
        }
        else if (!_stricmp(szLine,"down"))
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

    for (unsigned long N = 0 ; N < CustomBinds.Size ; N++)
        if (PCUSTOMBIND pBind=CustomBinds[N])
        {
            fprintf(file,"name=%s\ndown=%s\nup=%s\n",pBind->Name,pBind->CommandDown,pBind->CommandUp);
        }    
        fclose(file);
}

VOID ExecuteCustomBind(PCHAR Name,BOOL Down)
{
    int N=FindCustomBind(Name);
    if (N<0)
        return;
    PCHARINFO pCharInfo=GetCharInfo();
    if (!pCharInfo)
        return;
    if (PCUSTOMBIND pBind=CustomBinds[N])
    {
        if (Down)
        {
            if (pBind->CommandDown[0])
                DoCommand(pCharInfo->pSpawn,pBind->CommandDown);
        }
        else if (pBind->CommandUp[0])
            DoCommand(pCharInfo->pSpawn,pBind->CommandUp);
    }
}

VOID CustomBindCmd(PSPAWNINFO pChar, PCHAR szLine)
{
    if (szLine[0]==0)
    {
        SyntaxError("Usage: /custombind <list|add <name>|delete <name>|clear <name><-down|-up>|set <name><-down|-up> <command>>");
        return;
    }
    CHAR szBuffer[MAX_STRING];
    CHAR szArg[MAX_STRING] = {0};
    CHAR szArg2[MAX_STRING] = {0};
    GetArg(szArg,szLine,1);
    GetArg(szArg2,szLine,2);
    PCHAR szRest = GetNextArg(szLine,2);

    if (!_stricmp(szArg,"list"))
    {
        WriteChatColor("Custom binds");
        WriteChatColor("--------------");
        for (unsigned long N = 0 ; N < CustomBinds.Size ; N++)
            if (PCUSTOMBIND pBind=CustomBinds[N])
            {
                sprintf(szBuffer,"[\ay%s\ax] [Down:\at%s\ax] [Up:\at%s\ax]",pBind->Name,pBind->CommandDown,pBind->CommandUp);
                WriteChatColor(szBuffer);
            }
            WriteChatColor("--------------");
            WriteChatColor("End custom binds");
            return;
    }
    if (!_stricmp(szArg,"add"))
    {
        if (strchr(szArg2,'-'))
        {
            WriteChatColor("'-' is not allowed in a custom bind name");
        }
        if (PCUSTOMBIND pBind=AddCustomBind(szArg2,0,0))
        {
            WriteChatColor("Custom bind added.  Use /custombind set to set the custom commands.");
        }
        else
        {
            WriteChatColor("Failed to add custom bind (name in use)");
        }
        return;
    }
    if (!_stricmp(szArg,"delete"))
    {
        int N=FindCustomBind(szArg2);
        if (N>=0)
        {
            RemoveCustomBind(N);
            WriteChatColor("Custom bind deleted");
        }
        else
        {
            WriteChatColor("Could not find custom bind with that name to delete");
        }
        return;
    }
    if (!_stricmp(szArg,"set"))
    {
        BOOL Down=true;
        if (PCHAR minus=strchr(szArg2,'-'))
        {
            minus[0]=0;
            if (!_stricmp(&minus[1],"up"))
                Down=false;
        }
        int N=FindCustomBind(szArg2);
        if (N<0)
        {
            sprintf(szBuffer,"Could not find custom bind '%s'",szArg2);
            WriteChatColor(szBuffer);
            return;
        }
        PCUSTOMBIND pBind=CustomBinds[N];
        if (Down)
            strcpy(pBind->CommandDown,szRest);
        else
            strcpy(pBind->CommandUp,szRest);
        sprintf(szBuffer,"[\ay%s\ax] [Down:\at%s\ax] [Up:\at%s\ax]",pBind->Name,pBind->CommandDown,pBind->CommandUp);
        WriteChatColor(szBuffer);
        SaveCustomBinds();
        return;
    }
    if (!_stricmp(szArg,"clear"))
    {
        BOOL Down=true;
        if (PCHAR minus=strchr(szArg2,'-'))
        {
            minus[0]=0;
            if (!_stricmp(&minus[1],"up"))
                Down=false;
        }
        int N=FindCustomBind(szArg2);
        if (N<0)
        {
            sprintf(szBuffer,"Could not find custom bind '%s'",szArg2);
            WriteChatColor(szBuffer);
            return;
        }
        PCUSTOMBIND pBind=CustomBinds[N];
        if (Down)
            pBind->CommandDown[0]=0;
        else
            pBind->CommandUp[0]=0;
        sprintf(szBuffer,"[\ay%s\ax] [Down:\at%s\ax] [Up:\at%s\ax]",pBind->Name,pBind->CommandDown,pBind->CommandUp);
        WriteChatColor(szBuffer);
        SaveCustomBinds();
        return;
    }
}
