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

#include "common/Common.h"

#define TEST

// EQLib Configuration

//#define NEWCHARINFO

// Probably needs a Config.h
//#define KNIGHTLYPARSE

// Apply the configuration
#if defined(LIVE)

#include "live/eqgame.h"

#include "live/EQUIStructs.h"
#include "live/EQData.h"

#include "EQClasses.h"

#elif defined(TEST)

#include "test/eqgame(test).h"

#include "test/EQUIStructs(Test).h"
#include "test/EQData(Test).h"

#endif

#include "common/Globals.h"
#include "common/EQClasses.h"
#include "common/Items.h"
#include "common/PlayerClient.h"
#include "common/PcClient.h"
#include "common/Spells.h"