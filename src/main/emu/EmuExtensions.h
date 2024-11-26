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

// CPU Affinity was fixed in modern client
#define EMU_CONSTANT_AFFINITY_ENABLED IS_EXPANSION_LEVEL(EXPANSION_LEVEL_LS)

// Spell Links didn't existin the ROF client
#define EMU_SPELL_LINKS_ENABLED IS_EXPANSION_LEVEL_AT_MOST(EXPANSION_LEVEL_ROF)

// 64bit exception handler fixed this. (Not sure which client)
#define EMU_FIX_EXCEPTION_HANDLER_ENABLED IS_32BIT_CLIENT

#endif // IS_EMU_CLIENT
