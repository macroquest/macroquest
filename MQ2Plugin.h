/*****************************************************************************
    Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/

#ifdef ISXEQ
#include "ISXEQClient.h"
#define PreSetup(UNUSED)
#else

#ifndef _MQ2PLUGIN_H
#define _MQ2PLUGIN_H

#define MQ2PLUGIN
#include "MQ2Main/MQ2Main.h"
#include "MQ2Main/MQ2Globals.h"

#pragma comment(lib, "MQ2Main")

#ifdef EQLIB_EXPORTS
#pragma message("EQLIB_EXPORTS")
#else
#pragma message("EQLIB_IMPORTS")
#endif

#define PLUGIN_API extern "C" __declspec(dllexport)
#define PLUGIN_VERSION(X) __declspec(dllexport) float MQ2Version = (float)X


//#define SetINIFileName(ini) sprintf(INIFileName,"%s\\%s",gszINIPath,ini);
extern CHAR INIFileName[MAX_PATH];

#define PreSetup(pluginname) CHAR INIFileName[MAX_PATH]={0};\
BOOL APIENTRY DllMain( HANDLE hModule, \
                       DWORD  ul_reason_for_call, \
                       LPVOID lpReserved\
                     )\
{\
    if (ul_reason_for_call==DLL_PROCESS_ATTACH)\
    {\
    DebugSpewAlways("%s Module Loaded",pluginname );\
    sprintf(INIFileName,"%s\\%s.ini",gszINIPath,pluginname);\
    }\
    else if (ul_reason_for_call==DLL_PROCESS_DETACH)\
    DebugSpewAlways("%s Module Unloaded",pluginname);\
    return TRUE;\
}
#endif

#endif
