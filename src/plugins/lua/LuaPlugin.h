/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2022 MacroQuest Authors
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

#include "LuaCommon.h"

#include <mq/Plugin.h>

namespace mq::lua {
#pragma region Type Helper

class MQ2LuaGenericType : public MQ2Type
{
private:
	sol::table m_pluginTable; // this is "self", which can be used for local data storage
	std::string m_typeName;
	ci_unordered::map<std::string, std::tuple<int, sol::function>> m_memberMap;
	std::tuple<int, sol::function> m_toString;
	std::tuple<int, sol::function> m_fromData;
	std::tuple<int, sol::function> m_fromString;

public:
	MQ2LuaGenericType(sol::table plugin, const std::string& typeName, sol::table members, sol::function toString, sol::function fromData, sol::function fromString);
	virtual bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source);
	bool FromString(MQVarPtr& VarPtr, const char* Source);
	lua_State* GetState();
};

#pragma endregion

class LuaThread;
class LuaPlugin : public std::enable_shared_from_this<LuaPlugin>
{
#pragma region Callbacks

public:
	void SetCallback(const std::string& name, sol::object val, sol::this_state s);
	void InitializePlugin();
	void ShutdownPlugin();
	static void OnCleanUI();
	static void OnReloadUI();
	static void OnDrawHUD();
	static void SetGameState(int GameState);
	static void OnPulse();
	static void OnWriteChatColor(const char* Line, int Color, int Filter);
	static bool OnIncomingChat(const char* Line, unsigned long Color);
	static void OnAddSpawn(PlayerClient* pNewSpawn);
	static void OnRemoveSpawn(PlayerClient* pSpawn);
	static void OnAddGroundItem(EQGroundItem* pNewGroundItem);
	static void OnRemoveGroundItem(EQGroundItem* pGroundItem);
	static void OnBeginZone();
	static void OnEndZone();
	static void OnZoned();
	static void OnUpdateImGui();
	static void OnMacroStart(const char* Name);
	static void OnMacroStop(const char* Name);
	static void OnLoadPlugin(const char* Name);
	static void OnUnloadPlugin(const char* Name);

private:
	std::optional<std::function<void()>> m_InitializePlugin;
	std::optional<std::function<void()>> m_ShutdownPlugin;
	std::optional<std::function<void()>> m_OnCleanUI;
	std::optional<std::function<void()>> m_OnReloadUI;
	std::optional<std::function<void()>> m_OnDrawHUD;
	std::optional<std::function<void(int)>> m_SetGameState;
	std::optional<std::function<void()>> m_OnPulse;
	std::optional<std::function<void(const char*, int, int)>> m_OnWriteChatColor;
	std::optional<std::function<bool(const char*, unsigned long)>> m_OnIncomingChat;
	std::optional<std::function<void(PlayerClient*)>> m_OnAddSpawn;
	std::optional<std::function<void(PlayerClient*)>> m_OnRemoveSpawn;
	std::optional<std::function<void(EQGroundItem*)>> m_OnAddGroundItem;
	std::optional<std::function<void(EQGroundItem*)>> m_OnRemoveGroundItem;
	std::optional<std::function<void()>> m_OnBeginZone;
	std::optional<std::function<void()>> m_OnEndZone;
	std::optional<std::function<void()>> m_OnZoned;
	std::optional<std::function<void()>> m_OnUpdateImGui;
	std::optional<std::function<void(const char*)>> m_OnMacroStart;
	std::optional<std::function<void(const char*)>> m_OnMacroStop;
	std::optional<std::function<void(const char*)>> m_OnLoadPlugin;
	std::optional<std::function<void(const char*)>> m_OnUnloadPlugin;

#pragma endregion

#pragma region Commands

public:
	void RegisterCommand(const std::string& name, sol::function func);
	void AddCommands();
	void UnregisterCommands();

private:
	ci_unordered::map<std::string, sol::function> m_commands;

#pragma endregion

#pragma region Datatypes

public:
	void RegisterDatatype(const std::string& name, sol::table datatype);
	static bool IsDatatype(const std::string& name);
	void UnregisterDatatypes();

private:
	ci_unordered::map<std::string, std::unique_ptr<MQ2LuaGenericType>> m_dataTypes;

#pragma endregion

#pragma region TLOs

private:

public:
	void RegisterData(const std::string& name, sol::function func);
	void AddData();
	void UnregisterData();

private:
	ci_unordered::map<std::string, sol::function> m_dataTLOs;

#pragma endregion

#pragma region Interface

public:
	LuaPlugin(const std::string& name, const std::string& version, sol::this_state s);
	~LuaPlugin();
	const std::string& Name() const { return m_name; }
	sol::object Get(sol::object key, sol::this_state s) const;
	static sol::table Create(sol::table, const std::string& name, const std::string& version, sol::this_state s);
	static void Start(sol::table plugin);
	static void Stop(std::string_view name);
	static void StopAll();
	static std::shared_ptr<LuaPlugin> Lookup(std::string_view name);
	static bool IsRunning(std::string_view name);
	static std::vector<std::string_view> GetRunning();
	static void RegisterLua(sol::table& mq);
	static bool IsPlugin(sol::table table);

private:
	std::shared_ptr<LuaThread> m_thread;
	sol::table m_pluginTable;
	std::string m_name;
	std::string m_version;
#pragma endregion
};
} // namespace mq::lua
