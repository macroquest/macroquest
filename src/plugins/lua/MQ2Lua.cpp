// MQ2Lua.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup.

#include <mq/Plugin.h>
#include <mq/utils/Args.h>
#include <Yaml.hpp>
#include <fmt/format.h>

#include <sol/sol.hpp>

#include <string>

#include "LuaCommon.h"
#include "LuaThread.h"

// bindings:
#include "bindings/lua_MQTypeVar.h"
#include "bindings/lua_MQDataItem.h"
#include "bindings/lua_MQCommand.h"

PreSetup("MQ2Lua");
PLUGIN_VERSION(0.1);

using namespace mq;
using namespace mq::datatypes;
using namespace mq::lua;

using MQ2Args = Args<&WriteChatf>;
using MQ2HelpArgument = HelpArgument;

static uint32_t s_turboNum = 500;
static std::string s_luaDir = (std::filesystem::path(gPathMQRoot) / "lua").string();

// this is static and will never change
static std::string s_configPath = (std::filesystem::path(gPathConfig) / "MQ2Lua.yaml").string();
static Yaml::Node s_configNode;

/**
 * \brief a global lua state needed so that thread states don't go out of scope
 */
static sol::state s_lua;

// use a vector for s_running because we need to iterate it every pulse, and find only if a command is issued
std::vector<thread::LuaThread> s_running;

void mq::lua::DebugStackTrace(lua_State* L)
{
	int i;
	int top = lua_gettop(L);
	DebugSpewAlways("---- Begin Stack ----");
	DebugSpewAlways("Stack size: %i\n", top);
	for (i = top; i >= 1; i--)
	{
		int t = lua_type(L, i);
		switch (t)
		{
		case LUA_TSTRING:
			DebugSpewAlways("%i -- (%i) ---- `%s'", i, i - (top + 1), lua_tostring(L, i));
			break;

		case LUA_TBOOLEAN:
			DebugSpewAlways("%i -- (%i) ---- %s", i, i - (top + 1), lua_toboolean(L, i) ? "true" : "false");
			break;

		case LUA_TNUMBER:
			DebugSpewAlways("%i -- (%i) ---- %g", i, i - (top + 1), lua_tonumber(L, i));
			break;

		case LUA_TUSERDATA:
			DebugSpewAlways("%i -- (%i) ---- [%s]", i, i - (top + 1), luaL_tolstring(L, i, NULL));
			break;

		default:
			DebugSpewAlways("%i -- (%i) ---- %s", i, i - (top + 1), lua_typename(L, t));
			break;
		}
	}
	DebugSpewAlways("---- End Stack ----\n");
}

#pragma region Bindings

std::string mq::lua::join(sol::this_state L, std::string delim, sol::variadic_args va)
{
	if (va.size() > 0)
	{
		fmt::memory_buffer str;
		const auto* del = "";
		for (const auto& arg : va)
		{
			auto value = luaL_tolstring(arg.lua_state(), arg.stack_index(), NULL);
			if (value != nullptr && strlen(value) > 0)
			{
				fmt::format_to(str, "{}{}", del, value);
				del = delim.c_str();
			}
		}

		return fmt::to_string(str);
	}

	return "";
}

void mq::lua::delay(sol::object delayObj, sol::object conditionObj, sol::this_state s)
{
	auto delay_int = delayObj.as<std::optional<int>>();
	if (!delay_int)
	{
		auto delay_str = delayObj.as<std::optional<std::string_view>>();
		if (delay_str)
		{
			if (delay_str->length() > 1 && delay_str->compare(delay_str->length() - 1, 1, "m") == 0)
				delay_int.emplace(GetIntFromString(*delay_str, 0) * 600);
			else if (delay_str->length() > 2 && delay_str->compare(delay_str->length() - 2, 2, "ms") == 0)
				delay_int.emplace(GetIntFromString(*delay_str, 0) / 100);
			else if (delay_str->length() > 1 && delay_str->compare(delay_str->length() - 1, 1, "s") == 0)
				delay_int.emplace(GetIntFromString(*delay_str, 0) * 10);
		}
	}

	if (delay_int)
	{
		auto it = std::find_if(s_running.begin(), s_running.end(), [&s](const thread::LuaThread& thread)
			{
				return thread.Thread.thread_state() == s.lua_state();
			});

		if (it != s_running.end())
		{
			uint64_t delay_ms = std::max(0L, *delay_int * 100L);
			auto condition = conditionObj.as<std::optional<sol::function>>();
			if (!condition)
			{
				// let's accept a string too, and assume they want us to loadstring it
				auto condition_str = conditionObj.as<std::optional<std::string_view>>();
				if (condition_str)
				{
					// only allocate the string if we need to, but let's help the user and add the return to make this valid code
					// the temporary string in the else case here only needs to live long enough for the load to happen, it's
					// fine that it gets destroyed after the result here
					auto result = it->Thread.state().load(
						condition_str->rfind("return ", 0) == 0 ?
						*condition_str :
						"return " + std::string(*condition_str));

					if (result.valid())
					{
						sol::function f = result;
						condition.emplace(f);
					}
				}
			}

			it->State->set_delay(*it, delay_ms + MQGetTickCount64(), condition);
		}
	}
}

static void register_mq_type(sol::state& lua)
{
	lua.open_libraries();

	bindings::lua_MQTypeVar::register_binding(lua);
	bindings::lua_MQDataItem::register_binding(lua);
	bindings::lua_MQCommand::register_binding(lua);

	lua["delay"] = &mq::lua::delay;
	lua["join"] = &mq::lua::join;
}

#pragma endregion

#pragma region TLO

class MQ2LuaType* pLuaType = nullptr;
class MQ2LuaType : public MQ2Type
{
private:
public:
	enum class Members
	{
		PIDs,
		Dir,
		Turbo
	};

	MQ2LuaType() : MQ2Type("lua")
	{
		ScopedTypeMember(Members, PIDs);
		ScopedTypeMember(Members, Dir);
		ScopedTypeMember(Members, Turbo);
	}

	virtual bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override
	{
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
				[](const thread::LuaThread& thread) { return std::to_string(thread.PID); });
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

		default:
			return false;
		}
	}

	bool ToString(MQVarPtr VarPtr, char* Destination)
	{
		strcpy_s(Destination, MAX_STRING, "Lua");
		return true;
	}

    virtual bool FromString(MQVarPtr& VarPtr, const char* Source) override { return false; }
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
		auto entry = thread::LuaThread(s_lua, script.Get());
		WriteChatf("Running lua script '%s' with PID %d", script.Get().c_str(), entry.PID);
		s_running.emplace_back(std::move(entry));

		try
		{
			s_running.back().start_file(s_luaDir, s_turboNum, script_args.Get());
		}
		catch (sol::error& e)
		{
			MacroError("%s", e.what());
			s_running.pop_back(); // guaranteed that we need to pop the back of the running vector
		}
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
		auto thread_it = std::find_if(s_running.begin(), s_running.end(), [&pid](const thread::LuaThread& thread) -> bool
			{
				return thread.PID == pid.Get();
			});

		if (thread_it != s_running.end())
		{
			// this will force the coroutine to yield, and removing this thread from the vector will cause it to gc
			thread_it->yield_at(0);
			WriteChatf("Ending running lua script '%s' with PID %d", thread_it->Name.c_str(), thread_it->PID);
			s_running.erase(thread_it);
		}
		else
		{
			WriteChatf("No lua script with PID %d to end", pid.Get());
		}
	}
	else
	{
		// kill all scripts
		for (thread::LuaThread& thread : s_running)
			thread.yield_at(0);

		s_running.clear();

		WriteChatf("Ending ALL lua scripts");
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
		auto thread_it = std::find_if(s_running.begin(), s_running.end(), [&pid](const thread::LuaThread& thread) -> bool
			{
				return thread.PID == pid.Get();
			});

		if (thread_it != s_running.end())
		{
			thread_it->State->pause(*thread_it, s_turboNum);
		}
		else
		{
			WriteChatf("No lua script with PID %d to pause/resume", pid.Get());
		}
	}
	else
	{
		// try to get the user's intention here. If all scripts are running/paused, batch toggle state. If there are any running, assume we want to pause those only.
		if (std::find_if(s_running.cbegin(), s_running.cend(), [](const thread::LuaThread& thread) -> bool {
			return thread.State->is_paused();
			}) != s_running.cend())
		{
			// have at least one running script, so pause all running scripts
			for (auto& thread : s_running)
				thread.State->pause(thread, s_turboNum);

			WriteChatf("Pausing ALL running lua scripts");
		}
		else if (!s_running.empty())
		{
			// we have no running scripts, so restart all paused scripts
			for (auto& thread : s_running)
				thread.State->pause(thread, s_turboNum);

			WriteChatf("Resuming ALL paused lua scripts");
		}
		else
		{
			// there are no scripts running or paused, just inform the user of that
			WriteChatf("There are no running OR paused lua scripts to pause/resume");
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
		auto entry = thread::LuaThread(s_lua, "/luastring");
		WriteChatf("Running lua string with PID %d", entry.PID);
		s_running.emplace_back(std::move(entry));

		try
		{
			s_running.back().start_string(s_turboNum, join(script.Get(), " "));
		}
		catch (sol::error& e)
		{
			MacroError("%s", e.what());
			s_running.pop_back(); // guaranteed that we need to pop the back of the running vector
		}
	}
}

void WriteSettings()
{
	Yaml::Serialize(s_configNode, s_configPath.c_str());
}

void ReadSettings()
{
	try
	{
		Yaml::Parse(s_configNode, s_configPath.c_str());
	}
	catch (const Yaml::OperationException&)
	{
		// if we can't read the file, then try to write it with an empty config
		Yaml::Serialize(s_configNode, s_configPath);
	}

	s_turboNum = s_configNode["turboNum"].As<uint32_t>(s_turboNum);
	s_luaDir = s_configNode["luaDir"].As<std::string>(s_luaDir);
}

void LuaConfCommand(SPAWNINFO* pChar, char* Buffer)
{
	MQ2Args arg_parser("MQ2Lua: A lua script binding plugin.");
	arg_parser.Prog("/luaconf");
	arg_parser.RequireCommand(false);
	args::Group arguments(arg_parser, "");
	args::Positional<std::string> setting(arguments, "setting", "The setting to display/set");
	args::Positional<std::string> value(arguments, "value", "An optional parameter to specify the value to set");

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
			WriteChatf("Lua setting %s to %s and saving...", setting.Get().c_str(), value.Get().c_str());
			s_configNode[setting.Get()] = value.Get();
			WriteSettings();
			ReadSettings();
		}
		else
		{
			WriteChatf("Lua setting %s is set to %s.", setting.Get().c_str(), s_configNode[setting.Get()].As<std::string>().c_str());
		}
	}
	else
	{
		WriteChatf("Reloading lua config.");
		ReadSettings();
	}
}

#pragma endregion

bool dataLua(const char* Index, MQTypeVar& Dest)
{
	Dest.DWord = 1;
	Dest.Type = pLuaType;
	return true;
}

/**
 * @fn InitializePlugin
 *
 * This is called once on plugin initialization and can be considered the startup
 * routine for the plugin.
 */
PLUGIN_API void InitializePlugin()
{
	DebugSpewAlways("MQ2Lua::Initializing version %f", MQ2Version);

	ReadSettings();

	if (!std::filesystem::exists(s_luaDir) && !std::filesystem::create_directories(s_luaDir))
	{
		WriteChatf("Failed to open or create directory at %s. Scripts will not run.", s_luaDir.c_str());
	}

	register_mq_type(s_lua);

	AddCommand("/lua", LuaCommand);
	AddCommand("/endlua", EndLuaCommand);
	AddCommand("/luapause", LuaPauseCommand);
	AddCommand("/luastring", LuaStringCommand);
	AddCommand("/luaconf", LuaConfCommand);

	pLuaType = new MQ2LuaType;
	AddMQ2Data("Lua", dataLua);
}

/**
 * @fn ShutdownPlugin
 *
 * This is called once when the plugin has been asked to shutdown.  The plugin has
 * not actually shut down until this completes.
 */
PLUGIN_API void ShutdownPlugin()
{
	DebugSpewAlways("MQ2Lua::Shutting down");

	RemoveCommand("/lua");
	RemoveCommand("/endlua");
	RemoveCommand("/luapause");
	RemoveCommand("/luastring");
	RemoveCommand("/luaconf");

	RemoveMQ2Data("Lua");
	delete pLuaType;
}

/**
 * @fn OnPulse
 *
 * This is called each time MQ2 goes through its heartbeat (pulse) function.
 *
 * Because this happens very frequently, it is recommended to have a timer or
 * counter at the start of this call to limit the amount of times the code in
 * this section is executed.
 */
PLUGIN_API void OnPulse()
{
	s_running.erase(std::remove_if(
		s_running.begin(), s_running.end(),
		[](thread::LuaThread& thread) -> bool {
			// should_run() will automatically re-set the count debug hook when appropriate so we can simply change the turboNum on the fly and it will be respected next pulse.
			if (thread.Thread.status() == sol::thread_status::yielded && thread.State->should_run(thread, s_turboNum))
			{
				try
				{
					int nresults;
					lua_resume(thread.Thread.state(), nullptr, 0, &nresults);
				}
				catch (sol::error& e)
				{
					MacroError("Ending lua script '%s' with PID %d and error %s", thread.Name.c_str(), thread.PID, e.what());
					return true;
				}
			}

			if (thread.Thread.status() == sol::thread_status::runtime)
			{
				auto str = luaL_tolstring(thread.Thread.state(), -1, NULL);
				MacroError("Ending lua script %s with PID %d and error '%s'", thread.Name.c_str(), thread.PID, str);
				return true;
			}

			if (thread.Thread.status() != sol::thread_status::ok && thread.Thread.status() != sol::thread_status::yielded)
			{
				WriteChatf("Ending lua script %s with PID %d and status %d", thread.Name.c_str(), thread.PID, static_cast<int>(thread.Thread.status()));
				return true;
			}

			return false;
		}),
		s_running.end());
}
