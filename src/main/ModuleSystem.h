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

#include "mq/base/PluginHandle.h"
#include "mq/base/Enum.h"

#include "mq/api/PluginAPI.h"

#include "eqlib/Events.h"

namespace mq {

class ModuleSystem;
class PipeMessage;

enum class ModulePriority
{
	CrashHandler = 0,

	Commands = 10,
	DataTypes = 11,

	PostOffice = 20,

	Graphics = 50,
	ImGui = 51,

	HUD = 90,

	Default = 100,

	PluginHandler = 149,
	Plugins = 150,

	Macros = 200,
};

enum class ModuleFlags : uint32_t
{
	None                       = 0,
	CanUnload                  = 1 << 0,         // Module can be unloaded
	DefaultDisabled            = 1 << 1,         // Module is disabled by default
	Hidden                     = 1 << 2,         // Module is hidden from ui
	IsPlugin                   = 1 << 3,         // Module is a plugin
	IsDummy                    = 1 << 4,         // Module is a dummy

	SkipOnProcessFrame         = 1 << 19,        // Module has callback for this event
	SkipOnDrawHUD              = 1 << 20,        // ... and so on
	SkipOnUpdateImGui          = 1 << 21,
	SkipOnChatMessage          = 1 << 22,
	SkipOnTellWindowMessage    = 1 << 23,
	SkipOnIncomingWorldMessage = 1 << 24,
	SkipOnWriteChatColor       = 1 << 25,
	SkipOnIncomingChat         = 1 << 26,
	SkipOnSpawnAdded           = 1 << 27,
	SkipOnSpawnRemoved         = 1 << 28,
	SkipOnGroundItemAdded      = 1 << 29,
	SkipOnGroundItemRemoved    = 1 << 30,

	SkipAll                    = 0xFFF80000,
};
constexpr bool has_bitwise_operations(ModuleFlags) { return true; }

/**
 * Parameters for OnIncomingChat event
 */
struct IncomingChatParams
{
	const char* message;
	int color;

	bool filtered;              // true if message is filtered
	const char* stripped;       // original message with links stripped
};

/**
 * Describes the dependencies for a module. If the dependencies are not met,
 * the module will fail to load.
 */
struct ModuleDependencies
{
	/**
	 * List of module names that are required in order for this module to be loaded.
	 */
	std::vector<std::string> modules;
};

/**
 * Base class representing a module in the MacroQuest framework. A module is a basic unit of functionality,
 * providing a suite of events that can be overridden to implement custom behavior.
 */
class MQModuleBase
{
	friend class MacroQuest;

protected:
	/** Protected constructor. This class should be subclassed to implement module functionality. */
	MQModuleBase(std::string_view name, int priority = static_cast<int>(ModulePriority::Default), ModuleFlags flags = ModuleFlags::None);

	/**
	 * Add a module name to the list of module dependencies.
	 */
	void AddModuleDependency(std::string moduleDependency)
	{
		m_dependencies.modules.emplace_back(std::move(moduleDependency));
	}

	/**
	 * Set the list of module dependencies
	 */
	void SetModuleDependencies(std::vector<std::string> dependencies)
	{
		m_dependencies.modules = std::move(dependencies);
	}

public:
	virtual ~MQModuleBase() = default;

	/**
	 * Gets the name of the module.
	 *
	 * @return The name of the module.
	 */
	const std::string& GetName() const { return m_name; }

	/**
	 * Get the module's priority value. Module callbacks are executed in order of priority,
	 * with lower values executed first.
	 *
	 * @return The module's priority value.
	 */
	int GetPriority() const { return m_priority; }

	/**
	 * Get the module's flags. See `ModuleFlags` for the available flags.
	 *
	 * @return The module's flags value
	 */
	ModuleFlags GetFlags() const { return m_flags; }

	/**
	 * Returns true if this module is a plugin
	 */
	bool IsPlugin() const { return +(m_flags & ModuleFlags::IsPlugin); }

	/**
	 * Retrieve the module's handle
	 */
	MQPluginHandle GetHandle() const { return m_handle; }

	/**
	 * Retrieve this module's dependencies descriptor
	 */
	const ModuleDependencies& GetDependencies() const { return m_dependencies; }

	//----------------------------------------------------------------------------

	virtual void Initialize()
	{
	}

	virtual void Shutdown()
	{
	}

	virtual void OnProcessFrame()
	{
		m_flags |= ModuleFlags::SkipOnProcessFrame;
	}

	virtual void OnGameStateChanged(int gameState)
	{
		UNUSED(gameState);
	}

	virtual void OnUpdateImGui()
	{
		m_flags |= ModuleFlags::SkipOnUpdateImGui;
	}

	virtual void OnLoginFrontendEntered()
	{
	}

	virtual void OnLoginFrontendExited()
	{
	}

	virtual void OnCleanUI()
	{
	}

	virtual void OnReloadUI(const eqlib::ReloadUIParams& params)
	{
	}

	virtual void OnPreZoneUI()
	{
	}

	virtual void OnPostZoneUI()
	{
	}

	virtual bool OnChatMessage(eqlib::ChatMessageParams& params)
	{
		UNUSED(params);

		m_flags |= ModuleFlags::SkipOnChatMessage;

		return true;
	}

	virtual bool OnTellWindowMessage(eqlib::TellWindowMessageParams& params)
	{
		UNUSED(params);

		m_flags |= ModuleFlags::SkipOnTellWindowMessage;

		return true;
	}

	virtual bool OnIncomingWorldMessage(eqlib::IncomingWorldMessageParams& params)
	{
		UNUSED(params);

		m_flags |= ModuleFlags::SkipOnIncomingWorldMessage;
		
		return false;
	}

	virtual void OnWriteChatColor(const char* message, int color, int filter)
	{
		UNUSED(message);
		UNUSED(color);
		UNUSED(filter);

		m_flags |= ModuleFlags::SkipOnWriteChatColor;
	}

	virtual bool OnIncomingChat(const IncomingChatParams& params)
	{
		UNUSED(params);

		m_flags |= ModuleFlags::SkipOnIncomingChat;

		return false;
	}

	virtual void OnZoned()
	{
	}

	virtual void OnDrawHUD()
	{
		m_flags |= ModuleFlags::SkipOnDrawHUD;
	}

	virtual void OnSpawnAdded(eqlib::PlayerClient* player)
	{
		UNUSED(player);

		m_flags |= ModuleFlags::SkipOnSpawnAdded;
	}

	virtual void OnSpawnRemoved(eqlib::PlayerClient* player)
	{
		UNUSED(player);

		m_flags |= ModuleFlags::SkipOnSpawnRemoved;
	}

	virtual void OnGroundItemAdded(eqlib::EQGroundItem* groundItem)
	{
		UNUSED(groundItem);

		m_flags |= ModuleFlags::SkipOnGroundItemAdded;
	}

	virtual void OnGroundItemRemoved(eqlib::EQGroundItem* groundItem)
	{
		UNUSED(groundItem);

		m_flags |= ModuleFlags::SkipOnGroundItemRemoved;
	}

	virtual void OnModuleLoaded(MQModuleBase* module)
	{
		UNUSED(module);
	}

	virtual void OnBeforeModuleUnloaded(MQModuleBase* module)
	{
		UNUSED(module);
	}

	virtual void OnAfterModuleUnloaded(MQModuleBase* module)
	{
		UNUSED(module);
	}

	virtual void OnMacroStart(const char* macroName)
	{
		UNUSED(macroName);
	}

	virtual void OnMacroStop(const char* macroName)
	{
		UNUSED(macroName);
	}

	virtual bool OnPipeMessage(PipeMessage* message)
	{
		UNUSED(message);

		return false;
	}

	MQModuleBase(const MQModuleBase&) = delete;
	MQModuleBase(MQModuleBase&&) = delete;

	MQModuleBase& operator=(const MQModuleBase&) = delete;
	MQModuleBase& operator=(MQModuleBase&&) = delete;

protected:
	int m_priority;
	std::string m_name;
	ModuleFlags m_flags = ModuleFlags::None;
	ModuleDependencies m_dependencies;

private:
	MQPluginHandle m_handle;
};

class MQDynamicModule : public MQModuleBase
{
public:
	static constexpr ModuleFlags DEFAULT_PLUGIN_FLAGS = ModuleFlags::CanUnload | ModuleFlags::IsPlugin
		| ModuleFlags::SkipOnChatMessage | ModuleFlags::SkipOnTellWindowMessage | ModuleFlags::SkipOnIncomingWorldMessage;

	MQDynamicModule(std::string_view name, HMODULE hModule, ModuleFlags flags = DEFAULT_PLUGIN_FLAGS);
	virtual ~MQDynamicModule() override;

	virtual MQPlugin* GetPlugin() = 0;
	HMODULE GetHModule() const { return m_hModule; }

protected:
	HMODULE m_hModule;
};

template <typename ModuleType>
std::unique_ptr<MQModuleBase> CreateModule();

#define DECLARE_MODULE_FACTORY(ModuleType) \
	template <> std::unique_ptr<MQModuleBase> mq::CreateModule<ModuleType>() \
	{ \
		return std::make_unique<ModuleType>(); \
	}


} // namespace mq
