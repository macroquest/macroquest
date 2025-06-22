/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
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

// Indicates to MQMain.h that it is being included from a plugin
#define MQ_FROM_PLUGIN 1

#include "mq/plugin/pluginapi.h"
#include "eqlib/EQLib.h"

#ifndef MQLIB_STATIC
#pragma comment(lib, "pluginapi")
#pragma comment(lib, "MQ2Main")
#endif

#ifdef EQLIB_STATIC
#pragma comment(lib, "eqlib-static")
#else
#pragma comment(lib, "eqlib")
#endif

// For legacy purpoess, we add these usings by default. Pretty much all existing plugin code expects tthese.
#ifndef MQPLUGIN_NO_GLOBAL_USING
using namespace mq;         // NOLINT(clang-diagnostic-header-hygiene)
using namespace eqlib;      // NOLINT(clang-diagnostic-header-hygiene)
#endif
