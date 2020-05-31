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

#include "pch.h"
#include "MQ2Main.h"

#include <tinyfsm.hpp>
#include <chrono>

using namespace std::chrono_literals;

namespace mq {

static void Items_Initialize();
static void Items_Shutdown();
static void Items_Pulse();
static void Items_SetGameState(DWORD gameState);

static MQModule gItemsModule = {
	"Items",                      // Name
	false,                        // CanUnload
	Items_Initialize,             // Initialize
	Items_Shutdown,               // Shutdown
	Items_Pulse,                  // Pulse
	Items_SetGameState,           // SetGameState
};
MQModule* GetItemsModule() { return &gItemsModule; }

//----------------------------------------------------------------------------

int GetKeyRingCount(KeyRingType keyRingType)
{
	if (!pCharData)
		return 0;

	switch (keyRingType)
	{
	case eMount:
	case eIllusion:
	case eFamiliar:
	case eHeroForge:
		break;
	default: return 0;
	}

	return pCharData->GetKeyRingItems(keyRingType).GetCount();
}

int GetMountCount() { return GetKeyRingCount(eMount); }
int GetIllusionCount() { return GetKeyRingCount(eIllusion); }
int GetFamiliarCount() { return GetKeyRingCount(eFamiliar); }
int GetHeroForgeCount() { return GetKeyRingCount(eHeroForge); }

//----------------------------------------------------------------------------

static void Items_Initialize()
{
}

static void Items_Shutdown()
{
}

static void Items_Pulse()
{
}

static void Items_SetGameState(DWORD gameState)
{
}

} // namespace mq
