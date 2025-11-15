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

#if !defined(MQ2MAIN_IMPL) && !defined(__clang__)
#error This header should only be included from the MQ2Main project
#endif

#include <cstdint>

namespace eqlib
{
	class PlayerClient;
	class EQGroundItem;
}

namespace mq {

void InitializePlugins();
void UnloadPlugins();
void ShutdownPlugins();
void ShutdownFailedPlugins();
void InitializePluginHandle();

bool IsPluginsInitialized();

void PulsePlugins();
void PluginsZoned();
bool PluginsIncomingChat(const char* Line, uint32_t Color);
void PluginsCleanUI();
void PluginsReloadUI();
void PluginsSetGameState(int GameState);
void PluginsDrawHUD();
void PluginsAddSpawn(PlayerClient* pNewSpawn);
void PluginsRemoveSpawn(PlayerClient* pSpawn);
void PluginsAddGroundItem(EQGroundItem* pNewGroundItem);
void PluginsRemoveGroundItem(EQGroundItem* pGroundItem);
void PluginsBeginZone();
void PluginsEndZone();
void PluginsUpdateImGui();
void ModulesUpdateImGui();
void PluginsMacroStart(const char* Name);
void PluginsMacroStop(const char* Name);

} // namespace mq
