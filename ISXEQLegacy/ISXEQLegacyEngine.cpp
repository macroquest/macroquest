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

#include "ISXEQLegacy.h"
#include "isxeqlegacyengine.h"

ISXEQLegacyEngine::ISXEQLegacyEngine(void)
{
}

ISXEQLegacyEngine::~ISXEQLegacyEngine(void)
{
}

bool ISXEQLegacyEngine::GetCaps(ISXSCRIPTENGINECAPS &Dest)
{
    if (Dest.Sizeof==sizeof(ISXSCRIPTENGINECAPS))
    {
        Dest.bMultipleScripts=false;
        Dest.bPersistent=true;
        Dest.bPreprocessor=true;
        return true;
    }
    return false;
}

extern void Heartbeat();
void ISXEQLegacyEngine::Pulse()
{
    Heartbeat();
}

bool ISXEQLegacyEngine::ExecuteScript(const char *FullFilename, int argc, char *argv[])
{
    char MacroLine[2048]={0};

    if (argc)
    {
        char *pOut=MacroLine;
        pOut+=sprintf(MacroLine,"\"%s\" ",FullFilename);
        pISInterface->GetArgs(0,argc,argv,pOut);
    }
    else
    {
        sprintf(MacroLine,"\"%s\"",FullFilename);
    }

    Macro((PSPAWNINFO)pCharSpawn,MacroLine);
    return true;
}

bool ISXEQLegacyEngine::EndScript(const char *Name)
{
    EndMacro((PSPAWNINFO)pCharSpawn,"");
    return true;
}

unsigned long __stdcall MQ2DataVariableLookup(char * VarName, char * Value)
{
    strcpy(Value,VarName);
    return strlen(ParseMacroParameter(GetCharInfo()->pSpawn,Value));
}



