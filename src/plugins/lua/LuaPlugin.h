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
	std::string m_typeName;
	ci_unordered::map<std::string, sol::function> m_memberMap;
	sol::function m_toString;
	sol::function m_fromData;
	sol::function m_fromString;

public:
	MQ2LuaGenericType(const std::string& typeName, sol::table members, sol::function toString, sol::function fromData, sol::function fromString);
	virtual bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source);
	bool FromString(MQVarPtr& VarPtr, const char* Source);
	void Abandon();
};

#pragma endregion

class LuaThread;
class LuaPlugin : public std::enable_shared_from_this<LuaPlugin>
{
#pragma region Callbacks

public:
	enum class Callback
	{
		InitializePlugin,
		ShutdownPlugin,
		OnCleanUI,
		OnReloadUI,
		OnDrawHUD,
		SetGameState,
		OnPulse,
		OnWriteChatColor,
		OnIncomingChat,
		OnAddSpawn,
		OnRemoveSpawn,
		OnAddGroundItem,
		OnRemoveGroundItem,
		OnBeginZone,
		OnEndZone,
		OnZoned,
		OnUpdateImGui,
		OnMacroStart,
		OnMacroStop,
		OnLoadPlugin,
		OnUnloadPlugin
	};

	void InitializePlugin();
	void ShutdownPlugin();
	void OnCleanUI();
	void OnReloadUI();
	void OnDrawHUD();
	void SetGameState(int GameState);
	void OnPulse();
	void OnWriteChatColor(const char* Line, int Color, int Filter);
	bool OnIncomingChat(const char* Line, unsigned long Color);
	void OnAddSpawn(PlayerClient* pNewSpawn);
	void OnRemoveSpawn(PlayerClient* pSpawn);
	void OnAddGroundItem(EQGroundItem* pNewGroundItem);
	void OnRemoveGroundItem(EQGroundItem* pGroundItem);
	void OnBeginZone();
	void OnEndZone();
	void OnZoned();
	void OnUpdateImGui();
	void OnMacroStart(const char* Name);
	void OnMacroStop(const char* Name);
	void OnLoadPlugin(const char* Name);
	void OnUnloadPlugin(const char* Name);

private:
	sol::function m_InitializePlugin = sol::lua_nil;
	sol::function m_ShutdownPlugin = sol::lua_nil;
	sol::function m_OnCleanUI = sol::lua_nil;
	sol::function m_OnReloadUI = sol::lua_nil;
	sol::function m_OnDrawHUD = sol::lua_nil;
	sol::function m_SetGameState = sol::lua_nil;
	sol::function m_OnPulse = sol::lua_nil;
	sol::function m_OnWriteChatColor = sol::lua_nil;
	sol::function m_OnIncomingChat = sol::lua_nil;
	sol::function m_OnAddSpawn = sol::lua_nil;
	sol::function m_OnRemoveSpawn = sol::lua_nil;
	sol::function m_OnAddGroundItem = sol::lua_nil;
	sol::function m_OnRemoveGroundItem = sol::lua_nil;
	sol::function m_OnBeginZone = sol::lua_nil;
	sol::function m_OnEndZone = sol::lua_nil;
	sol::function m_OnZoned = sol::lua_nil;
	sol::function m_OnUpdateImGui = sol::lua_nil;
	sol::function m_OnMacroStart = sol::lua_nil;
	sol::function m_OnMacroStop = sol::lua_nil;
	sol::function m_OnLoadPlugin = sol::lua_nil;
	sol::function m_OnUnloadPlugin = sol::lua_nil;

#pragma endregion

#pragma region Commands

public:
	void RegisterCommand(const std::string& name, sol::function func);
	void UnregisterCommands();

private:
	ci_unordered::map<std::string, sol::function> m_commands;

#pragma endregion

#pragma region Datatypes

public:
	void RegisterDatatype(const std::string& name, sol::table members, sol::function toString, sol::function fromData, sol::function fromString);
	void UnregisterDatatypes();

private:
	ci_unordered::map<std::string, std::unique_ptr<MQ2LuaGenericType>> m_dataTypes;

#pragma endregion

#pragma region TLOs

private:
	// this is a hack because you can't capture in a function pointer, but we need to capture the lua function
	struct FPtr
	{
		template <typename T>
		static bool func_ptr_exec(const char* Index, MQTypeVar& Dest)
		{
			return (bool)(*(T*)fn<T>())(Index, Dest);
		}

		template <typename T>
		static fMQData ptr(T& t)
		{
			fn<T>(&t);
			return func_ptr_exec<T>;
		}

		template <typename T>
		static void* fn(void* new_fn = nullptr)
		{
			static void* fn;
			if (new_fn != nullptr) fn = new_fn;
			return fn;
		}
	};

	static fMQData CreateData(sol::function func);

public:
	void RegisterData(const std::string& name, sol::function func);
	void UnregisterData();

private:
	ci_unordered::map<std::string, sol::function> m_dataTLOs;

#pragma endregion

#pragma region Interface

public:
	LuaPlugin(const std::string& name, const std::string& version, sol::this_state s);
	static sol::table Create(sol::table, const std::string& name, const std::string& version, sol::this_state s);
	static void Start(sol::table plugin);
	static void Stop(const std::string& name);
	static sol::table Lookup(const std::string& name);
	static bool IsRunning(const std::string& name);
	static std::vector<std::string> GetRunning();
	void Set(const std::string& name, sol::object val, sol::this_state s);
	static void RegisterLua(sol::table& mq);
	std::string Name() { return m_name; }
	static bool IsPlugin(sol::table table);

private:
	std::shared_ptr<LuaThread> m_thread;
	sol::table m_pluginTable;
	std::string m_name;
	std::string m_version;
#pragma endregion
};
} // namespace mq::lua
