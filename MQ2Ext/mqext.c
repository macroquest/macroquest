/*****************************************************************************
mqext.dll: NTSD extensions for EQLib.dll
Copyright (C) 2002 Plazmic

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License, version 2, as published by
the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
******************************************************************************/

#include "mqext.h"

#include <ntverp.h>

//
// globals
//
#if defined(EXT_API_VERSION_NUMBER64)
EXT_API_VERSION         ApiVersion = { (VER_PRODUCTVERSION_W >> 8), (VER_PRODUCTVERSION_W & 0xff), EXT_API_VERSION_NUMBER64, 0 };
#else
EXT_API_VERSION         ApiVersion = { (VER_PRODUCTVERSION_W >> 8), (VER_PRODUCTVERSION_W & 0xff), EXT_API_VERSION_NUMBER, 0 };
#endif
WINDBG_EXTENSION_APIS   ExtensionApis;
ULONG SavedMajorVersion;
ULONG SavedMinorVersion;

DllInit(
        HANDLE hModule,
        DWORD  dwReason,
        DWORD  dwReserved
        )
{
    switch (dwReason) {
        case DLL_THREAD_ATTACH:
            break;

        case DLL_THREAD_DETACH:
            break;

        case DLL_PROCESS_DETACH:
            break;

        case DLL_PROCESS_ATTACH:
            break;
    }

    return TRUE;
}


VOID
WinDbgExtensionDllInit(
                       PWINDBG_EXTENSION_APIS lpExtensionApis,
                       USHORT MajorVersion,
                       USHORT MinorVersion
                       )
{
    ExtensionApis = *lpExtensionApis;

    SavedMajorVersion = MajorVersion;
    SavedMinorVersion = MinorVersion;

    return;
}

LPEXT_API_VERSION
ExtensionApiVersion(
                    VOID
                    )
{
    return &ApiVersion;
}

//
// Routine called by debugger after load
//
VOID
CheckVersion(
             VOID
             )
{
    return;
}
