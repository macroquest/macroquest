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

#pragma once

#define MQ2PLUGIN

#include "../src/main/MQ2Main.h"
using namespace mq;

#pragma comment(lib, "MQ2Main")
#pragma comment(lib, "eqlib")

#define PLUGIN_API extern "C" __declspec(dllexport)
#define PLUGIN_VERSION(X) __declspec(dllexport) float MQ2Version = (float)X

extern char INIFileName[MAX_STRING];

#define PreSetup(pluginname) char INIFileName[MAX_STRING] = {0};              \
BOOL APIENTRY DllMain(HANDLE hModule,                                         \
                      DWORD ul_reason_for_call,                               \
                      void* lpReserved)                                       \
{                                                                             \
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)                             \
    {                                                                         \
        DebugSpewAlways("%s Module Loaded", pluginname);                      \
        sprintf_s(INIFileName,"%s\\%s.ini", gPathConfig, pluginname);         \
    }                                                                         \
    else if (ul_reason_for_call == DLL_PROCESS_DETACH)                        \
    {                                                                         \
        DebugSpewAlways("%s Module Unloaded", pluginname);                    \
    }                                                                         \
    return TRUE;                                                              \
}
