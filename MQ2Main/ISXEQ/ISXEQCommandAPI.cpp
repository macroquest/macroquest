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

class CCommandHook 
{ 
public: 
	VOID Detour(PSPAWNINFO pChar, PCHAR szFullLine) 
	{ 
		//DebugSpew("CCommandHook::Detour(%s)",szFullLine);

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
	} 

	VOID Trampoline(PSPAWNINFO pChar, PCHAR szFullLine); 

}; 

DETOUR_TRAMPOLINE_EMPTY(VOID CCommandHook::Trampoline(PSPAWNINFO pChar, PCHAR szFullLine)); 

int CMD_EQExecute(int argc, char *argv[])
{
	if (gGameState!=GAMESTATE_INGAME)
	{
		printf("Cannot execute EQ command, not in game!");
		return 0;
	}
	if (argc<2)
	{
		printf("Syntax: %s <command>",argv[0]);
		return 0;
	}
	char Line[8192]={0};
	pISInterface->GetArgs(1,argc,argv,Line);
	((CCommandHook*)pEverQuest)->Trampoline((PSPAWNINFO)pLocalPlayer,Line);
	return 0;
}

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
}

