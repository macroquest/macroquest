/*****************************************************************************
MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

Portions Copyright(C) 2004 Zaphod

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License, version 2, as published by
the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
******************************************************************************/
#ifndef ISXEQ

#if !defined(CINTERFACE)
#error /DCINTERFACE
#endif

#define DBG_SPEW


#include "MQ2Main.h"

VOID InitializeParser()
{
    DebugSpewNoFile("InitializeParser()");

    InitializeMQ2DataTypes();
    InitializeMQ2Data();
    bmParseMacroParameter=AddMQ2Benchmark("ParseMacroParameter");
}

VOID ShutdownParser()
{
    DebugSpewNoFile("ShutdownParser()");
    RemoveDetour(EQPlayer__SetNameSpriteState); // put here so it doesnt crash :)
    ShutdownMQ2Data();
    ShutdownMQ2DataTypes();
}


// ***************************************************************************
// Function:    ParseMacroParameter
// Description: Parses macro $ parameters ($cursor, etc)
// ***************************************************************************
/*****************************************************************************
* NOTE: New syntax for adding macro parameters!                             *
* Coded and converted by Valerian.                                          *
* 1: Make changes in EQLib_MacroParser.h to reflect new function, and text  *
*    to call that function.                                                 *
*    A: PMP funcs: Simply make note of those already there, and make yours  *
*                  the same.                                                *
*                                                                           *
*    B: Parms[] global variable:                                            *
*       First field is the text that will call the parm func, minus the "$" *
*       e.g. for $spawn(250,type) this would simply be "spawn". Lowercase.  *
*                                                                           *
*       Second field is the function name to call.                          *
*                                                                           *
*       Third field is NULL -- This field will be set to the address of the *
*       function, the first time ParseMacroParameter is run.                *
*                                                                           *
* 2: Function definition MUST be:                                           *
*    DWORD YourFuncName(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)      *
*    A: Parameters are as follows:                                          *
*                                                                           *
*       DWORD return value: Old "i++" value. e.g. number of chars to skip   *
*                           in original string. Size of your parameter,     *
*                           without the "$", and minus 1. $spawn(250,type)  *
*                           should return 14. Returning 10000 indicates an  *
*                           error return. (Bad macro parameter)             *
*                                                                           *
*       szVar:              Text of parameter, up to and including trailing *
*                           ")". May contain entire line if there are no ")"*
*                           characters in that parameter.                   *
*                                                                           *
*       szOutput:           Output string. You will need to strcat your     *
*                           output into this string.                        *
*                                                                           *
*  **NOTE** The ordering of commands in Parms[] variable may be important!  *
*           They get checked in the order they are in the variable, and     *
*           similar names must have the more specific one first! If there   *
*           are two parms, e.g. "item" and "items", "items" must be first,  *
*           or else the "item" command will be called and fail for a bad    *
*           parm. Also note that you should be able to include a "(" at the *
*           end of your parm name, or any number of chars there.            *
*           "myparm(thisoption," is acceptable.                             *
*****************************************************************************/

int FindLastParameter(PCSTR szOriginal, PCSTR& szRetCurPos, size_t& len)
{
    PCSTR szCurPos;
    PCSTR szParamPos = NULL;

    // iterate over the entire string
    for (szCurPos = szOriginal; *szCurPos; szCurPos++)
        if ((*szCurPos == '$') || (*szCurPos == '@')) // note parameter position
            szParamPos = szCurPos;

    // calculate the strings length
    len = (size_t)(szCurPos - szOriginal - 1);

    // return the parameters position
    szRetCurPos = szParamPos;

    if (szParamPos) // return offset into string if paramater found
        return (int)(szParamPos - szOriginal);

    return -1; // no parameter found
}



PCHAR ParseMacroParameter(PSPAWNINFO pChar, PCHAR szOriginal)
{
    PCHARINFO pCharInfo = GetCharInfo();
    if (!pCharInfo) 
        return szOriginal;
    EnterMQ2Benchmark(bmParseMacroParameter);

    ParseMacroData(szOriginal);
    ExitMQ2Benchmark(bmParseMacroParameter);
    return (szOriginal);
}

#endif
