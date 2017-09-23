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

#ifndef _MQ2PLUGIN_H
#define _MQ2PLUGIN_H

#define MQ2PLUGIN
#ifndef ISXEQ
#ifndef ISXEQ_LEGACY
#define ISXEQ
#endif
#endif
#include "MQ2Main/MQ2Main.h"
#include "MQ2Main/MQ2Globals.h"

#pragma comment(lib, "isxdk.lib")
#pragma comment(lib, "ISXEQ")

#ifdef EQLIB_EXPORTS
#pragma message("EQLIB_EXPORTS")
#else
#pragma message("EQLIB_IMPORTS")
#endif

#define PLUGIN_API extern "C" __declspec(dllexport)


#endif
