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

#include "eqlib/BuildType.h"

#if IS_EMU_CLIENT

#if MQ_EXPANSION_LEVEL == EXPANSION_LEVEL_ROF
#define EMU_CONSTANT_AFFINITY_ENABLED 1
#else
#define EMU_CONSTANT_AFFINITY_ENABLED 0
#endif

#define EMU_SPELL_LINKS_ENABLED 0

#if MQ_EXPANSION_LEVEL == EXPANSION_LEVEL_ROF
#define EMU_FIX_EXCEPTION_HANDLER_ENABLED 1
#else
#define EMU_FIX_EXCEPTION_HANDLER_ENABLED 0
#endif

#if MQ_EXPANSION_LEVEL == EXPANSION_LEVEL_ROF
#define EMU_CEFFECT_CRASH_WORKAROUND 1
#else
#define EMU_CEFFECT_CRASH_WORKAROUND 0
#endif

#endif // IS_EMU_CLIENT
