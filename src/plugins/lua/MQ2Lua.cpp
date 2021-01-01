/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2020 MacroQuest Authors
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
#include "LuaCommon.h"
#include "LuaThread.h"
#include "LuaEvent.h"
#include "LuaImGui.h"
#include "bindings/lua_MQTypeVar.h"
#include "bindings/lua_MQDataItem.h"
#include "bindings/lua_MQCommand.h"

#include <mq/Plugin.h>
#include <mq/utils/Args.h>
#include <fmt/format.h>

#pragma warning( push )
#pragma warning( disable:4996 )
#include <yaml-cpp/yaml.h>
#pragma warning( pop )

#include <string>
#include <fstream>

PreSetup("MQ2Lua");
PLUGIN_VERSION(0.1);

// TODO: Add aggressive bind/event options that scriptwriters can set with functions
// TODO: Add OnExit callbacks (potentially both as an explicit argument to exit and a set callback)

// TODO: Add UI for start/stop/info/config

using MQ2Args = Args<&WriteChatf>;
using MQ2HelpArgument = HelpArgument;

namespace mq::lua {

// provide option strings here
static const std::string turboNum = "turboNum";
static const std::string luaDir = "luaDir";
static const std::string luaRequirePaths = "luaRequirePaths";
static const std::string dllRequirePaths = "dllRequirePaths";
static const std::string infoGC = "infoGC";
static const std::string squelchStatus = "squelchStatus";

// configurable options, defaults provided where needed
static uint32_t s_turboNum = 500;
static std::string s_luaDir = (std::filesystem::path(gPathMQRoot) / "lua").string();
static std::vector<std::string> s_luaRequirePaths;
static std::vector<std::string> s_dllRequirePaths;
static uint64_t s_infoGC = 3600000; // 1 hour
static bool s_squelchStatus = false;

// this is static and will never change
static std::string s_configPath = (std::filesystem::path(gPathConfig) / "MQ2Lua.yaml").string();
static YAML::Node s_configNode;

// use a vector for s_running because we need to iterate it every pulse, and find only if a command is issued
std::vector<std::shared_ptr<LuaThread>> s_running;

std::unordered_map<uint32_t, LuaThreadInfo> s_finished;

#pragma region Shared Function Definitions

void DebugStackTrace(lua_State* L)
{
	lua_Debug ar;
	lua_getstack(L, 1, &ar);
	lua_getinfo(L, "nSl", &ar);
	LuaError("%s: %s (%s)", ar.what, ar.name, ar.namewhat);
	LuaError("Line %i in %s", ar.currentline, ar.short_src);

	int top = lua_gettop(L);
	LuaError("---- Begin Stack (size: %i) ----", top);
	for (int i = top; i >= 1; i--)
	{
		int t = lua_type(L, i);
		switch (t)
		{
		case LUA_TSTRING:
			LuaError("%i -- (%i) ---- `%s'", i, i - (top + 1), lua_tostring(L, i));
			break;

		case LUA_TBOOLEAN:
			LuaError("%i -- (%i) ---- %s", i, i - (top + 1), lua_toboolean(L, i) ? "true" : "false");
			break;

		case LUA_TNUMBER:
			LuaError("%i -- (%i) ---- %g", i, i - (top + 1), lua_tonumber(L, i));
			break;

		case LUA_TUSERDATA:
			LuaError("%i -- (%i) ---- [%s]", i, i - (top + 1), luaL_tolstring(L, i, NULL));
			break;

		default:
			LuaError("%i -- (%i) ---- %s", i, i - (top + 1), lua_typename(L, t));
			break;
		}
	}
	LuaError("---- End Stack ----\n");
}

bool DoStatus()
{
	return !s_squelchStatus;
}

#pragma endregion

#pragma region TLO

class MQ2LuaInfoType* pLuaInfoType = nullptr;
class MQ2LuaInfoType : public MQ2Type
{
public:
	enum class Members
	{
		PID,
		Name,
		Path,
		Arguments,
		StartTime,
		EndTime,
		ReturnCount,
		Return
	};

	MQ2LuaInfoType() : MQ2Type("luainfo")
	{
		ScopedTypeMember(Members, PID);
		ScopedTypeMember(Members, Name);
		ScopedTypeMember(Members, Path);
		ScopedTypeMember(Members, Arguments);
		ScopedTypeMember(Members, StartTime);
		ScopedTypeMember(Members, EndTime);
		ScopedTypeMember(Members, ReturnCount);
		ScopedTypeMember(Members, Return);
	};

	virtual bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override
	{
		using namespace mq::datatypes;

		auto pMember = MQ2LuaInfoType::FindMember(Member);
		if (pMember == nullptr)
			return false;

		auto info = VarPtr.Get<LuaThreadInfo>();
		if (!info)
			return false;

		switch (static_cast<Members>(pMember->ID))
		{
		case Members::PID:
			Dest.Type = pIntType;
			Dest.Set(info->pid);
			return true;

		case Members::Name:
			Dest.Type = pStringType;
			strcpy_s(DataTypeTemp, MAX_STRING, info->name.c_str());
			Dest.Ptr = &DataTypeTemp[0];
			return true;

		case Members::Path:
			Dest.Type = pStringType;
			strcpy_s(DataTypeTemp, MAX_STRING, info->path.c_str());
			Dest.Ptr = &DataTypeTemp[0];
			return true;

		case Members::Arguments:
			Dest.Type = pStringType;
			strcpy_s(DataTypeTemp, MAX_STRING, join(info->arguments, ",").c_str());
			Dest.Ptr = &DataTypeTemp[0];
			return true;

		case Members::StartTime:
			Dest.Type = pInt64Type;
			Dest.Set(info->startTime);
			return true;

		case Members::EndTime:
			Dest.Type = pInt64Type;
			Dest.Set(info->endTime);
			return true;

		case Members::ReturnCount:
			Dest.Type = pIntType;
			Dest.Set(info->returnValues.size());
			return true;

		case Members::Return:
			Dest.Type = pStringType;
			if (info->returnValues.empty())
				return false;

			if (!Index || !Index[0])
			{
				strcpy_s(DataTypeTemp, MAX_STRING, join(info->returnValues, ",").c_str());
			}
			else
			{
				int index = GetIntFromString(Index, 0) - 1;
				if (index < 0 || index >= static_cast<int>(info->returnValues.size()))
					return false;

				strcpy_s(DataTypeTemp, MAX_STRING, info->returnValues.at(index).c_str());
			}

			Dest.Ptr = &DataTypeTemp[0];
			return true;

		default:
			return false;
		}
	}

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		auto info = VarPtr.Get<LuaThreadInfo>();
		if (!info || info->returnValues.empty())
			return false;

		strcpy_s(Destination, MAX_STRING, join(info->returnValues, ",").c_str());
		return true;
	}

	virtual bool FromString(MQVarPtr& VarPtr, const char* Source) override
	{
		return false;
	}
};

//----------------------------------------------------------------------------

class MQ2LuaType* pLuaType = nullptr;
class MQ2LuaType : public MQ2Type
{
public:
	enum class Members
	{
		PIDs,
		Dir,
		Turbo,
		RequirePaths,
		CRequirePaths,
		Script
	};

	MQ2LuaType() : MQ2Type("lua")
	{
		ScopedTypeMember(Members, PIDs);
		ScopedTypeMember(Members, Dir);
		ScopedTypeMember(Members, Turbo);
		ScopedTypeMember(Members, RequirePaths);
		ScopedTypeMember(Members, CRequirePaths);
		ScopedTypeMember(Members, Script);
	}

	virtual bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override
	{
		using namespace mq::datatypes;

		auto pMember = MQ2LuaType::FindMember(Member);
		if (pMember == nullptr)
			return false;

		switch (static_cast<Members>(pMember->ID))
		{
		case Members::PIDs:
		{
			Dest.Type = pStringType;
			std::vector<std::string> pids;
			std::transform(s_running.cbegin(), s_running.cend(), std::back_inserter(pids),
				[](const auto& thread) { return std::to_string(thread->pid); });
			strcpy_s(DataTypeTemp, join(pids, ",").c_str());
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		case Members::Dir:
			Dest.Type = pStringType;
			strcpy_s(DataTypeTemp, s_luaDir.c_str());
			Dest.Ptr = &DataTypeTemp[0];
			return true;

		case Members::Turbo:
			Dest.Type = pIntType;
			Dest.Set(s_turboNum);
			return true;

		case Members::RequirePaths:
			Dest.Type = pStringType;
			strcpy_s(DataTypeTemp, fmt::format("{}\\?.lua;{}{}", s_luaDir,
				s_luaRequirePaths.empty() ? "" : join(s_luaRequirePaths, ";")).c_str());
			Dest.Ptr = &DataTypeTemp[0];
			return true;

		case Members::CRequirePaths:
			Dest.Type = pStringType;
			strcpy_s(DataTypeTemp, fmt::format("{}\\?.dll;{}{}", s_luaDir,
				s_dllRequirePaths.empty() ? "" : join(s_dllRequirePaths, ";")).c_str());
			Dest.Ptr = &DataTypeTemp[0];
			return true;

		case Members::Script:
		{
			Dest.Type = pLuaInfoType;
			if (!Index || !Index[0])
			{
				if (s_finished.empty())
					return false;

				// grab the latest start time that has an end time
				auto latest = s_finished.cbegin();
				for (auto it = s_finished.cbegin(); it != s_finished.cend(); ++it)
				{
					if (it->second.endTime > 0 && it->second.startTime > latest->second.startTime)
						latest = it;
				}

				if (latest->second.endTime > 0)
				{
					Dest.Set(latest->second);
					return true;
				}

				return false;
			}

			auto pid = GetIntFromString(Index, -1);
			auto it = s_finished.find(pid);
			if (it != s_finished.end())
			{
				Dest.Set(it->second);
				return true;
			}

			return false;
		}

		default:
			return false;
		}
	}

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		strcpy_s(Destination, MAX_STRING, "Lua");
		return true;
	}

	virtual bool FromString(MQVarPtr& VarPtr, const char* Source) override
	{
		return false;
	}

	static bool dataLua(const char* Index, MQTypeVar& Dest)
	{
		Dest.DWord = 1;
		Dest.Type = pLuaType;
		return true;
	}
};

#pragma endregion

#pragma region Commands

void LuaCommand(SPAWNINFO* pChar, char* Buffer)
{
	MQ2Args arg_parser("MQ2Lua: A lua script binding plugin.");
	arg_parser.Prog("/lua");
	args::Group arguments(arg_parser, "");
	args::Positional<std::string> script(arguments, "script", "the name of the lua script to run. will automatically append .lua extension if no extension specified.");
	args::PositionalList<std::string> script_args(arguments, "args", "optional arguments to pass to the lua script.");

	MQ2HelpArgument h(arguments);
	auto args = allocate_args(Buffer);
	try
	{
		arg_parser.ParseArgs(args);
	}
	catch (const args::Help&)
	{
		arg_parser.Help();
	}
	catch (const args::Error& e)
	{
		WriteChatColor(e.what());
	}

	if (script)
	{
		auto entry = std::make_shared<LuaThread>(script.Get(), s_luaDir, s_luaRequirePaths, s_dllRequirePaths);
		WriteChatStatus("Running lua script '%s' with PID %d", script.Get().c_str(), entry->pid);
		s_running.emplace_back(entry); // this needs to be in the running vector before we run at all

		entry->RegisterLuaState(entry);
		auto result = entry->StartFile(s_luaDir, s_turboNum, script_args.Get());
		if (result)
			s_finished.emplace(result->pid, *result);
	}
}

void EndLuaCommand(SPAWNINFO* pChar, char* Buffer)
{
	MQ2Args arg_parser("MQ2Lua: A lua script binding plugin.");
	arg_parser.Prog("/endlua");
	arg_parser.RequireCommand(false);
	args::Group arguments(arg_parser, "");
	args::Positional<uint32_t> pid(arguments, "PID", "optional parameter to specify a PID of script to stop, if not specified will stop all running scripts.");

	MQ2HelpArgument h(arguments);
	auto args = allocate_args(Buffer);
	try
	{
		arg_parser.ParseArgs(args);
	}
	catch (const args::Help&)
	{
		arg_parser.Help();
	}
	catch (const args::Error& e)
	{
		WriteChatColor(e.what());
	}

	if (pid)
	{
		auto thread_it = std::find_if(s_running.begin(), s_running.end(), [&pid](const auto& thread) -> bool
			{
				return thread->pid == pid.Get();
			});

		if (thread_it != s_running.end())
		{
			// this will force the coroutine to yield, and removing this thread from the vector will cause it to gc
			(*thread_it)->YieldAt(0);
			(*thread_it)->thread.abandon();
			WriteChatStatus("Ending running lua script '%s' with PID %d", (*thread_it)->name.c_str(), (*thread_it)->pid);
		}
		else
		{
			WriteChatStatus("No lua script with PID %d to end", pid.Get());
		}
	}
	else
	{
		// kill all scripts
		for (auto& thread : s_running)
		{
			thread->YieldAt(0);
			thread->thread.abandon();
		}

		WriteChatStatus("Ending ALL lua scripts");
	}
}

void LuaPauseCommand(SPAWNINFO* pChar, char* Buffer)
{
	MQ2Args arg_parser("MQ2Lua: A lua script binding plugin.");
	arg_parser.Prog("/luapause");
	arg_parser.RequireCommand(false);
	args::Group arguments(arg_parser, "");
	args::Positional<uint32_t> pid(arguments, "PID", "optional parameter to specify a PID of script to pause, if not specified will pause all running scripts.");

	MQ2HelpArgument h(arguments);
	auto args = allocate_args(Buffer);
	try
	{
		arg_parser.ParseArgs(args);
	}
	catch (const args::Help&)
	{
		arg_parser.Help();
	}
	catch (const args::Error& e)
	{
		WriteChatColor(e.what());
	}

	if (pid)
	{
		auto thread_it = std::find_if(s_running.begin(), s_running.end(), [&pid](const auto& thread) -> bool
			{
				return thread->pid == pid.Get();
			});

		if (thread_it != s_running.end())
		{
			(*thread_it)->state->Pause(**thread_it, s_turboNum);
		}
		else
		{
			WriteChatStatus("No lua script with PID %d to pause/resume", pid.Get());
		}
	}
	else
	{
		// try to Get the user's intention here. If all scripts are running/paused, batch toggle state. If there are any running, assume we want to pause those only.
		if (std::find_if(s_running.cbegin(), s_running.cend(), [](const auto& thread) -> bool {
			return thread->state->IsPaused();
			}) != s_running.cend())
		{
			// have at least one running script, so pause all running scripts
			for (auto& thread : s_running)
				thread->state->Pause(*thread, s_turboNum);

			WriteChatStatus("Pausing ALL running lua scripts");
		}
		else if (!s_running.empty())
		{
			// we have no running scripts, so restart all paused scripts
			for (auto& thread : s_running)
				thread->state->Pause(*thread, s_turboNum);

			WriteChatStatus("Resuming ALL paused lua scripts");
		}
		else
		{
			// there are no scripts running or paused, just inform the user of that
			WriteChatStatus("There are no running OR paused lua scripts to pause/resume");
		}
	}
}

void LuaStringCommand(SPAWNINFO* pChar, char* Buffer)
{
	MQ2Args arg_parser("MQ2Lua: A lua script binding plugin.");
	arg_parser.Prog("/luastring");
	args::Group arguments(arg_parser, "");
	args::PositionalList<std::string> script(arguments, "script", "the text of the lua script to run");

	MQ2HelpArgument h(arguments);
	auto args = allocate_args(Buffer);
	try
	{
		arg_parser.ParseArgs(args);
	}
	catch (const args::Help&)
	{
		arg_parser.Help();
	}
	catch (const args::Error& e)
	{
		WriteChatColor(e.what());
	}

	if (script)
	{
		auto entry = std::make_shared<LuaThread>("/luastring", s_luaDir, s_luaRequirePaths, s_dllRequirePaths);
		WriteChatStatus("Running lua string with PID %d", entry->pid);
		s_running.emplace_back(entry); // this needs to be in the running vector before we run at all

		// Create lua state with mq namespace already injected.
		entry->RegisterLuaState(entry, true);
		auto result = entry->StartString(s_turboNum, join(script.Get(), " "));
		if (result)
			s_finished.emplace(result->pid, *result);
	}
}

void WriteSettings()
{
	if (!s_configNode.IsNull())
	{
		YAML::Emitter y_out;
		y_out << s_configNode;

		std::fstream file(s_configPath, std::ios::out);
		file << y_out.c_str();
	}
}

void ReadSettings()
{
	try
	{
		s_configNode = YAML::LoadFile(s_configPath);
	}
	catch (const YAML::ParserException& e)
	{
		// failed to parse, notify and return
		WriteChatf("Failed to parse YAML in %s with %s", s_configPath.c_str(), e.what());
		return;
	}
	catch (const YAML::BadFile&)
	{
		// if we can't read the file, then try to write it with an empty config
		WriteSettings();
	}

	s_turboNum = s_configNode[turboNum].as<uint32_t>(s_turboNum);

	s_luaDir = (std::filesystem::path(gPathMQRoot) / s_configNode[luaDir].as<std::string>(s_luaDir)).string();

	std::error_code ec;
	if (!std::filesystem::exists(s_luaDir, ec) && !std::filesystem::create_directories(s_luaDir, ec))
	{
		WriteChatf("Failed to open or create directory at %s. Scripts will not run.", s_luaDir.c_str());
		WriteChatf("Error was %s", ec.message().c_str());
	}

	s_luaRequirePaths.clear();
	if (s_configNode[luaRequirePaths].IsSequence()) // if this is not a sequence, add nothing
	{
		for (const auto& path : s_configNode[luaRequirePaths])
		{
			auto fin_path = std::filesystem::path(gPathMQRoot) / std::filesystem::path(path.as<std::string>());
			s_luaRequirePaths.emplace_back(fin_path.string());
		}
	}

	s_dllRequirePaths.clear();
	if (s_configNode[dllRequirePaths].IsSequence()) // if this is not a sequence, add nothing
	{
		for (const auto& path : s_configNode[dllRequirePaths])
		{
			auto fin_path = std::filesystem::path(gPathMQRoot) / std::filesystem::path(path.as<std::string>());
			s_dllRequirePaths.emplace_back(fin_path.string());
		}
	}

	auto GC_interval = s_configNode[infoGC].as<std::string>(std::to_string(s_infoGC));
	trim(GC_interval);
	if (GC_interval.length() > 1 && GC_interval.find_first_not_of("0123456789") == std::string::npos)
		std::from_chars(GC_interval.data(), GC_interval.data() + GC_interval.size(), s_infoGC);
	else if (GC_interval.length() > 1 && GC_interval.compare(GC_interval.length() - 1, 1, "h") == 0)
	{
		auto result = 0ULL;
		std::from_chars(GC_interval.data(), GC_interval.data() + GC_interval.size() - 1, result);
		if (result >= 0) s_infoGC = result * 3600000;
	}
	else if (GC_interval.length() > 1 && GC_interval.compare(GC_interval.length() - 1, 1, "m") == 0)
	{
		auto result = 0ULL;
		std::from_chars(GC_interval.data(), GC_interval.data() + GC_interval.size() - 1, result);
		if (result >= 0) s_infoGC = result * 60000;
	}
	else if (GC_interval.length() > 2 && GC_interval.compare(GC_interval.length() - 2, 2, "ms") == 0)
		std::from_chars(GC_interval.data(), GC_interval.data() + GC_interval.size() - 2, s_infoGC);
	else if (GC_interval.length() > 1 && GC_interval.compare(GC_interval.length() - 1, 1, "s") == 0)
	{
		auto result = 0ULL;
		std::from_chars(GC_interval.data(), GC_interval.data() + GC_interval.size() - 1, result);
		if (result >= 0) s_infoGC = result * 1000;
	}

	s_squelchStatus = s_configNode[squelchStatus].as<bool>(s_squelchStatus);

	WriteSettings();
}

void LuaConfCommand(SPAWNINFO* pChar, char* Buffer)
{
	MQ2Args arg_parser("MQ2Lua: A lua script binding plugin.");
	arg_parser.Prog("/luaconf");
	arg_parser.RequireCommand(false);
	args::Group arguments(arg_parser, "");
	args::Positional<std::string> setting(arguments, "setting", "The setting to display/set");
	args::PositionalList<std::string> value(arguments, "value", "An optional parameter to specify the value to set");

	MQ2HelpArgument h(arguments);
	auto args = allocate_args(Buffer);
	try
	{
		arg_parser.ParseArgs(args);
	}
	catch (const args::Help&)
	{
		arg_parser.Help();
	}
	catch (const args::Error& e)
	{
		WriteChatColor(e.what());
	}

	if (setting)
	{
		if (value)
		{
			auto to_set = join(value.Get(), " ");
			WriteChatStatus("Lua setting %s to %s and saving...", setting.Get().c_str(), to_set.c_str());
			s_configNode[setting.Get()] = to_set;
			WriteSettings();
			ReadSettings();
		}
		else if (s_configNode[setting.Get()])
		{
			WriteChatStatus("Lua setting %s is set to %s.", setting.Get().c_str(), s_configNode[setting.Get()].as<std::string>().c_str());
		}
		else
		{
			WriteChatStatus("Lua setting %s is not set (using default).", setting.Get().c_str());
		}
	}
	else
	{
		WriteChatStatus("Reloading lua config.");
		ReadSettings();
	}
}

void LuaRestartCommand(SPAWNINFO* pChar, char* Buffer)
{
	WriteChatStatus("Stopping all running lua scripts and re-reading the settings.");
	EndLuaCommand(pChar, "");

	s_running.clear();
	ReadSettings();
}

#pragma endregion

} // namespace mq::lua

/**
 * @fn InitializePlugin
 *
 * This is called once on plugin initialization and can be considered the startup
 * routine for the plugin.
 */
PLUGIN_API void InitializePlugin()
{
	using namespace mq::lua;

	DebugSpewAlways("MQ2Lua::Initializing version %f", MQ2Version);

	ReadSettings();

	AddCommand("/lua", LuaCommand);
	AddCommand("/endlua", EndLuaCommand);
	AddCommand("/luapause", LuaPauseCommand);
	AddCommand("/luastring", LuaStringCommand);
	AddCommand("/luaconf", LuaConfCommand);
	AddCommand("/luarestart", LuaRestartCommand);

	pLuaInfoType = new MQ2LuaInfoType;
	pLuaType = new MQ2LuaType;
	AddMQ2Data("Lua", &MQ2LuaType::dataLua);
}

/**
 * @fn ShutdownPlugin
 *
 * This is called once when the plugin has been asked to shutdown.  The plugin has
 * not actually shut down until this completes.
 */
PLUGIN_API void ShutdownPlugin()
{
	using namespace mq::lua;

	DebugSpewAlways("MQ2Lua::Shutting down");

	RemoveCommand("/lua");
	RemoveCommand("/endlua");
	RemoveCommand("/luapause");
	RemoveCommand("/luastring");
	RemoveCommand("/luaconf");
	RemoveCommand("/luarestart");

	RemoveMQ2Data("Lua");
	delete pLuaType;
	delete pLuaInfoType;
}

/**
 * @fn OnPulse
 *
 * This is called each time MQ2 goes through its heartbeat (pulse) function.
 *
 * Because this happens very frequently, it is recommended to have a timer or
 * counter at the start of this Call to limit the amount of times the code in
 * this section is executed.
 */
PLUGIN_API void OnPulse()
{
	using namespace mq::lua;

	s_running.erase(std::remove_if(s_running.begin(), s_running.end(), [](const auto& thread) -> bool
		{
			if (thread->coroutine.status() != sol::call_status::yielded)
			{
				WriteChatStatus("Ending lua script %s with PID %d and status %d", thread->name.c_str(), thread->pid, static_cast<int>(thread->coroutine.status()));
				return true;
			}

			auto result = thread->Run(s_turboNum);

			if (result.first != sol::thread_status::yielded)
			{
				WriteChatStatus("Ending lua script %s with PID %d and status %d", thread->name.c_str(), thread->pid, static_cast<int>(result.first));
				auto fin_it = s_finished.find(thread->pid);
				if (fin_it != s_finished.end() && result.second)
					fin_it->second.SetResult(*result.second);

				return true;
			}

			return false;
		}), s_running.end());

	static uint64_t last_check_time = MQGetTickCount64();
	if (MQGetTickCount64() >= last_check_time + s_infoGC)
	{
		// this doesn't need to be super tight, no one should be depending on this clearing objects at exactly the GC
		// interval, so just clear out anything that existed last time we checked.
		for (auto it = s_finished.begin(); it != s_finished.end();)
		{
			if (it->second.endTime > 0 && it->second.endTime <= last_check_time)
				it = s_finished.erase(it);
			else
				++it;
		}

		last_check_time = MQGetTickCount64();
	}
}

/**
 * @fn OnUpdateImGui
 *
 * This is called each time that the ImGui Overlay is rendered. Use this to render
 * and update plugin specific widgets.
 *
 * Because this happens extremely frequently, it is recommended to move any actual
 * work to a separate Call and use this only for updating the display.
 */
PLUGIN_API void OnUpdateImGui()
{
	using namespace mq::lua;

	for (const auto& thread : s_running)
	{
		thread->imguiProcessor->Pulse();
	}
}


/**
 * @fn OnWriteChatColor
 *
 * This is called each time WriteChatColor is called (whether by MQ2Main or by any
 * plugin).  This can be considered the "when outputting text from MQ" callback.
 *
 * This ignores filters on display, so if they are needed either implement them in
 * this section or see @ref OnIncomingChat where filters are already handled.
 *
 * If CEverQuest::dsp_chat is not called, and events are required, they'll need to
 * be implemented here as well.  Otherwise, see @ref OnIncomingChat where that is
 * already handled.
 *
 * For a list of Color values, see the constants for USERCOLOR_.  The default is
 * USERCOLOR_DEFAULT.
 *
 * @param Line const char* - The line that was passed to WriteChatColor
 * @param Color int - The type of chat text this is to be sent as
 * @param Filter int - (default 0)
 */
PLUGIN_API void OnWriteChatColor(const char* Line, int Color, int Filter)
{
	using namespace mq::lua;

	for (const auto& thread : s_running)
	{
		if (!thread->state->IsPaused())
			thread->eventProcessor->Process(Line);
	}
}

/**
 * @fn OnIncomingChat
 *
 * This is called each time a line of chat is shown.  It occurs after MQ filters
 * and chat events have been handled.  If you need to know when MQ2 has sent chat,
 * consider using @ref OnWriteChatColor instead.
 *
 * For a list of Color values, see the constants for USERCOLOR_. The default is
 * USERCOLOR_DEFAULT.
 *
 * @param Line const char* - The line of text that was shown
 * @param Color int - The type of chat text this was sent as
 *
 * @return bool - whether something was done based on the incoming chat
 */
PLUGIN_API bool OnIncomingChat(const char* Line, DWORD Color)
{
	using namespace mq::lua;

	for (const auto& thread : s_running)
	{
		if (!thread->state->IsPaused())
			thread->eventProcessor->Process(Line);
	}

	return false;
}
