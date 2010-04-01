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

#if !defined(CINTERFACE)
#error /DCINTERFACE
#endif

#define DBG_SPEW

#include "..\MQ2Main.h"

/*
typedef struct _ISXEQAlias
{
	char Replacement[256];
} ISXEQALIAS, *PISXEQALIAS;

map<string,PISXEQALIAS> ISXEQAliases;


PISXEQALIAS FindISXEQAlias(const char *Token)
{
	if (!Token || !Token[0])
		return 0;
	char Temp[512];
	strcpy(Temp,Token);
	strlwr(Temp);
	return ISXEQAliases[Temp];
}

void AddISXEQAlias(const char *Replace, const char *With)
{
	if (!Replace || !Replace[0])
		return;
	if (!With || !With[0])
		return;
	PISXEQALIAS pAlias=FindISXEQAlias(Replace);
	if (pAlias)
	{
		strcpy(pAlias->Replacement,With);
		return;
	}
	pAlias=new ISXEQALIAS;
	strcpy(pAlias->Replacement,With);
	char Temp[512];
	strcpy(Temp,Replace);
	strlwr(Temp);
	ISXEQAliases[Temp]=pAlias;
}

bool RemoveISXEQAlias(const char *Token)
{
	if (!Token || !Token[0])
		return 0;
	char Temp[512];
	strcpy(Temp,Token);
	strlwr(Temp);
	PISXEQALIAS pAlias=ISXEQAliases[Temp];
	if (!pAlias)
		return false;
	delete pAlias;
	ISXEQAliases[Temp]=0;
	return true;
}
/**/

extern VOID StrReplaceSection(PCHAR szInsert,DWORD Length,PCHAR szNewString);


bool ExecuteISCommand(char *Command, char *Parameters=0)
{
	char Temp[4096]={0};
	if (!strchr(Command,':') && !pISInterface->IsAlias(Command) && !pISInterface->ResolveCommand(Command,Temp,sizeof(Temp)))
	{
		return false;
	}

	if (Parameters)
	{
		sprintf(Temp,"%s %s",Command,Parameters);
		pISInterface->ExecuteCommand(Temp);
	}
	else
		pISInterface->ExecuteCommand(Command);

	return true;
}

class CCommandHook 
{ 
public: 
	VOID Detour(PSPAWNINFO pChar, PCHAR szFullLine) 
	{ 
		//DebugSpew("CCommandHook::Detour(%s)",szFullLine);

		// apply one alias
		char FullCommand[4096];
		strcpy(FullCommand,szFullLine);
		szFullLine=FullCommand;

		char CommandName[256]={0};

		char *pSpace=strchr(FullCommand,' ');
		if (pSpace)
			*pSpace=0;
		strcpy(CommandName,FullCommand);
		if (pSpace)
		{
			*pSpace=' ';
			pSpace++;
		}

		if (CommandName[0]!='/' || !CommandName[1] || !ExecuteISCommand(&CommandName[1],pSpace))
		{
			char FullCommand[8192]={0};
//			strcpy(FullCommand,szFullLine);
			pISInterface->DataParse(szFullLine,FullCommand,8192);
			Trampoline(pChar,FullCommand); 
		}
		strcpy(szLastCommand,FullCommand);

		/*
		PISXEQALIAS pAlias=FindISXEQAlias(CommandName);
		if (pAlias)
			StrReplaceSection(CommandName,strlen(CommandName),pAlias->Replacement);

		if (CommandName[0]=='/' && CommandName[1] && pISInterface->IsCommand(&CommandName[1]))
		{

		}
		if (szFullLine[0]=='#')
		{
			pISInterface->ExecuteCommand(&szFullLine[1]);
			strcpy(szLastCommand,szFullLine);
		}
		else
		{
			char FullCommand[8192]={0};
			strcpy(FullCommand,szFullLine);
			pISInterface->DataParse(FullCommand);
			Trampoline(pChar,FullCommand); 
			strcpy(szLastCommand,FullCommand);
		}
		/**/
	} 

	VOID Trampoline(PSPAWNINFO pChar, PCHAR szFullLine); 

}; 

DETOUR_TRAMPOLINE_EMPTY(VOID CCommandHook::Trampoline(PSPAWNINFO pChar, PCHAR szFullLine)); 

int CMD_EQExecute(int argc, char *argv[])
{
	if (gGameState!=GAMESTATE_INGAME)
	{
		WriteChatf("Cannot execute EQ command, not in game!");
		return 0;
	}
	if (argc<2)
	{
		WriteChatf("Syntax: %s <command>",argv[0]);
		return 0;
	}
	char Line[8192]={0};
	pISInterface->GetArgs(1,argc,argv,Line);
	((CCommandHook*)pEverQuest)->Trampoline((PSPAWNINFO)pLocalPlayer,Line);
	return 0;
}

/*

int CMD_EQAlias(int argc, char *argv[])
{
	if (argc<2)
	{
		WriteChatf("Syntax: %s -list|-delete <name>|<replace> <with>",argv[0]);
		return 0;
	}

	if (!stricmp(argv[1],"-list"))
	{
		WriteChatf("Registered EQ Aliases");
		WriteChatf("---------------------");
		for(map<string,PISXEQALIAS>::iterator i = ISXEQAliases.begin();i != ISXEQAliases.end();i++)
		{
			if (PISXEQALIAS pAlias=i->second)
			{
				WriteChatf("[%s] %s",i->first,pAlias->Replacement);
			}
		}
	}
	else if (argc>=3)
	{
		if (!stricmp(argv[1],"-delete"))
		{
			RemoveISXEQAlias(argv[1]);
		}
		else
		{
			char FullCommand[8192]={0};
			pISInterface->GetArgs(2,argc,argv,FullCommand);
			AddISXEQAlias(argv[1],FullCommand);
			if (PISXEQALIAS pAlias=FindISXEQAlias(argv[1]))
			{
				WriteChatf("[%s] %s",argv[1],pAlias->Replacement);
			}
			else
				WriteChatf("ISXEQ Alias NOT added");
		}
	}
	else
	{
		printf("Syntax: %s -list|-delete <name>|<replace> <with>",argv[0]);
	}
	return 0;
}
/**/

void InitializeMQ2Commands()
{
	EzDetour(CEverQuest__InterpretCmd,CCommandHook::Detour,CCommandHook::Trampoline);

//	pISInterface->AddCommand("EQExecute",CMD_EQExecute);

#define COMMAND(name,cmd,parse,hide) pISInterface->AddCommand(name,cmd,parse,hide)
#include "ISXEQCommandList.h"
#undef COMMAND


}

void ShutdownMQ2Commands()
{
#define COMMAND(name,cmd,parse,hide) pISInterface->RemoveCommand(name)
#include "ISXEQCommandList.h"
#undef COMMAND

	EzUnDetour(CEverQuest__InterpretCmd);

	/*
	for(map<string,PISXEQALIAS>::iterator i = ISXEQAliases.begin();i != ISXEQAliases.end();i++)
	{
		if (PISXEQALIAS pAlias=i->second)
		{
			delete pAlias;
		}
	}
	ISXEQAliases.clear();
	/**/
}

