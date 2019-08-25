/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "../MQ2Plugin.h"

PreSetup("MQ2CustomBinds");

typedef struct _CustomBind {
    char Name[32];
    char CommandDown[MAX_STRING];
    char CommandUp[MAX_STRING];
} CUSTOMBIND, *PCUSTOMBIND;

CIndex<PCUSTOMBIND> CustomBinds(10);

void ExecuteCustomBind(PCHAR Name,BOOL Down);

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
        strcpy_s(pBind->Name,Name);
        if (CommandDown)
            strcpy_s(pBind->CommandDown,CommandDown);
        if (CommandUp)
            strcpy_s(pBind->CommandUp,CommandUp);
        CustomBinds+=pBind;
        return pBind;
    }
    return 0;
}

void RemoveCustomBind(unsigned long N)
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

void LoadCustomBinds();
void CustomBindCmd(PSPAWNINFO pChar, PCHAR szLine);
void SaveCustomBinds();

// Called once, when the plugin is to initialize
PLUGIN_API void InitializePlugin()
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
PLUGIN_API void ShutdownPlugin()
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

PLUGIN_API void SetGameState(DWORD GameState)
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

void LoadCustomBinds()
{
    char filename[MAX_STRING];
    strcpy_s(filename,gszINIPath);
    strcat_s(filename,"\\MQ2CustomBinds.txt");
	FILE *file = 0;
	errno_t err = fopen_s(&file,filename, "rt");
    if (err)
        return;
    CUSTOMBIND NewBind;
    ZeroMemory(&NewBind,sizeof(CUSTOMBIND));
    char szLine[MAX_STRING];

    while(fgets(szLine,2048,file))
    {
		char *Next_Token1 = 0;
		char *Next_Token2 = 0;
        char *Cmd = strtok_s(szLine,"\r\n",&Next_Token1);
        char *Cmd2 = strtok_s(Cmd,"=",&Next_Token2);
        if (!_stricmp(Cmd2,"name"))
        {
            ZeroMemory(&NewBind,sizeof(CUSTOMBIND));
            strcpy_s(NewBind.Name,&szLine[5]);
        }
        else if (!_stricmp(Cmd2,"up"))
        {
            strcpy_s(NewBind.CommandUp,&szLine[3]);
            AddCustomBind(NewBind.Name,NewBind.CommandDown,NewBind.CommandUp);
        }
        else if (!_stricmp(Cmd2,"down"))
        {
            strcpy_s(NewBind.CommandDown,&szLine[5]);
        }
    }

    fclose(file);
}

void SaveCustomBinds()
{
    char filename[MAX_STRING];
    strcpy_s(filename,gszINIPath);
    strcat_s(filename,"\\MQ2CustomBinds.txt");
	FILE *file = 0;
	errno_t err = fopen_s(&file,filename, "wt");
    if (err)
        return;

	for (unsigned long N = 0; N < CustomBinds.Size; N++) {
		if (PCUSTOMBIND pBind = CustomBinds[N])
		{
			fprintf(file, "name=%s\ndown=%s\nup=%s\n", pBind->Name, pBind->CommandDown, pBind->CommandUp);
		}
	}
	fclose(file);
}

void ExecuteCustomBind(PCHAR Name,BOOL Down)
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

void CustomBindCmd(PSPAWNINFO pChar, PCHAR szLine)
{
    if (szLine[0]==0)
    {
        SyntaxError("Usage: /custombind <list|add <name>|delete <name>|clear <name><-down|-up>|set <name><-down|-up> <command>>");
        return;
    }
    char szBuffer[MAX_STRING];
    char szArg[MAX_STRING] = {0};
    char szArg2[MAX_STRING] = {0};
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
                sprintf_s(szBuffer,"[\ay%s\ax] [Down:\at%s\ax] [Up:\at%s\ax]",pBind->Name,pBind->CommandDown,pBind->CommandUp);
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
            sprintf_s(szBuffer,"Could not find custom bind '%s'",szArg2);
            WriteChatColor(szBuffer);
            return;
        }
        PCUSTOMBIND pBind=CustomBinds[N];
        if (Down)
            strcpy_s(pBind->CommandDown,szRest);
        else
            strcpy_s(pBind->CommandUp,szRest);
        sprintf_s(szBuffer,"[\ay%s\ax] [Down:\at%s\ax] [Up:\at%s\ax]",pBind->Name,pBind->CommandDown,pBind->CommandUp);
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
            sprintf_s(szBuffer,"Could not find custom bind '%s'",szArg2);
            WriteChatColor(szBuffer);
            return;
        }
        PCUSTOMBIND pBind=CustomBinds[N];
        if (Down)
            pBind->CommandDown[0]=0;
        else
            pBind->CommandUp[0]=0;
        sprintf_s(szBuffer,"[\ay%s\ax] [Down:\at%s\ax] [Up:\at%s\ax]",pBind->Name,pBind->CommandDown,pBind->CommandUp);
        WriteChatColor(szBuffer);
        SaveCustomBinds();
        return;
    }
}
