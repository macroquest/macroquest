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
static void Items_UpdateImGui();

static MQModule gItemsModule = {
	"Items",                      // Name
	false,                        // CanUnload
	Items_Initialize,             // Initialize
	Items_Shutdown,               // Shutdown
	Items_Pulse,                  // Pulse
	Items_SetGameState,           // SetGameState
	Items_UpdateImGui,            // UpdateImGui
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

static bool gbDidUpdateKeyRing = false;
static uint64_t gLastKeyRingUpdate = 0;

void RefreshKeyRingWindow()
{
	if (gbDidUpdateKeyRing) // only need to update keyring every so often.
		return;
	if (!pKeyRingWnd)
		return;

	bool isVisible = pKeyRingWnd->IsVisible();
	auto currentPage = pKeyRingWnd->CurrentPage;
	int lastUpdateTime = pKeyRingWnd->LastUpdateTime;

	// We can update the keyring window simply by flagging it as visible,
	// resetting the timer, and calling OnProcessFrame. When we're done we
	// reset the state back to how we found it.

	if (!isVisible)
		pKeyRingWnd->Show(true);

	for (int type = CKeyRingWnd::ePageFirst; type <= CKeyRingWnd::ePageLast; ++type)
	{
		pKeyRingWnd->CurrentPage = (CKeyRingWnd::KeyRingPages)type;
		pKeyRingWnd->LastUpdateTime = 0;
		pKeyRingWnd->OnProcessFrame();
	}

	// Reset the state back to what it was.
	if (!isVisible)
		pKeyRingWnd->Show(false);
	else
		pKeyRingWnd->CurrentPage = currentPage;
	pKeyRingWnd->LastUpdateTime = lastUpdateTime;

	gbDidUpdateKeyRing = true;
	gLastKeyRingUpdate = MQGetTickCount64();
}

//----------------------------------------------------------------------------

static void Items_Initialize()
{
}

static void Items_Shutdown()
{
}

static void Items_Pulse()
{
	// This may not be necessary if the data cannot be manipulated without the UI.
	// This resets the check for gbDidUpdateKeyRing 5 seconds after it is set.
	if (gbDidUpdateKeyRing)
	{
		if (gLastKeyRingUpdate + 5000 < MQGetTickCount64())
		{
			gbDidUpdateKeyRing = false;
		}
	}
}

static void Items_SetGameState(DWORD gameState)
{
	if (gameState == GAMESTATE_INGAME)
		gbDidUpdateKeyRing = false;
}

static void Items_UpdateImGui()
{
}

} // namespace mq
