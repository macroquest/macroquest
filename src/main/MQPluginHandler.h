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

#ifndef MQ2MAIN_EXPORTS
#error This header should only be included from the MQ2Main project
#endif

#include "ModuleSystem.h"

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

class MQPluginModule : public MQModuleBase
{
public:
	MQPluginModule();
	virtual ~MQPluginModule() override;

protected:
	virtual void Initialize() override;
	virtual void Shutdown() override;

	virtual void OnProcessFrame() override;
	virtual void OnGameStateChanged(int gameState) override;
	virtual void OnUpdateImGui() override;
	virtual void OnCleanUI() override;
	virtual void OnReloadUI(const eqlib::ReloadUIParams& params) override;
	virtual void OnPreZoneUI() override;
	virtual void OnPostZoneUI() override;
	virtual void OnWriteChatColor(const char* message, int color, int filter) override;
	virtual bool OnIncomingChat(const char* message, int color) override;
	virtual void OnZoned() override;
	virtual void OnDrawHUD() override;
	virtual void OnSpawnAdded(eqlib::PlayerClient* player) override;
	virtual void OnSpawnRemoved(eqlib::PlayerClient* player) override;
	virtual void OnGroundItemAdded(eqlib::EQGroundItem* groundItem) override;
	virtual void OnGroundItemRemoved(eqlib::EQGroundItem* groundItem) override;
	virtual void OnModuleLoaded(MQModuleBase* module) override;
	virtual void OnBeforeModuleUnloaded(MQModuleBase* module) override;
	virtual void OnAfterModuleUnloaded(MQModuleBase* module) override;
	virtual void OnMacroStart(const char* macroName) override;
	virtual void OnMacroStop(const char* macroName) override;

private:
	MQPlugin m_plugin;
};

class MQPluginHandler : MQModuleBase
{
public:
	MQPluginHandler();
	virtual ~MQPluginHandler() override;

	virtual void Initialize() override;
	virtual void Shutdown() override;
};

DECLARE_MODULE_FACTORY(MQPluginHandler)

} // namespace mq
