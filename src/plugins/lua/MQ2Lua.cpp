// MQ2Lua.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup.

#include <mq/Plugin.h>

#include <sol/sol.hpp>

#include <string>
#include <unordered_map>

PreSetup("MQ2Lua");
PLUGIN_VERSION(0.1);

using namespace mq;
using namespace mq::datatypes;

// TODO: Make this configureable (read it from the lua file?)
#define TURBO_NUM 1000
std::filesystem::path s_luaDir = std::filesystem::path(gPathMQRoot) / "lua"; // TODO: can make this configurable

/**
 * \brief a global lua state needed so that thread states don't go out of scope
 */
sol::state s_lua;

// use a vector for s_running because we need to iterate it every pulse, and find only if a command is issued
std::vector<std::pair<std::string, sol::thread>> s_running;

// use a hashmap here because we never iterate this, only find
ci_unordered::map<std::string, sol::thread> s_paused;

void DebugStackTrace(lua_State* L)
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

struct lua_MQDataItem;
struct lua_MQTypeVar
{
	MQTypeVar self_;
	std::string member_;

	lua_MQTypeVar() = default;

	lua_MQTypeVar(const std::string& str)
	{
		auto* const type = FindMQ2DataType(str.c_str());
		if (type != nullptr)
		{
			self_.Type = type;
		}
	}

	/**
	 * \brief wraps an MQ type var in a lua implementation
	 * \param self the MQ type var data source to be represented in lua
	 */
	lua_MQTypeVar(MQTypeVar&& self) : self_(std::move(self)) {}

	bool operator==(const lua_MQTypeVar& right) const
	{
		return self_ == right.self_;
	}

	bool equal_data(const lua_MQDataItem& right) const;

	lua_MQTypeVar evaluate_member(char* index = nullptr) const
	{
		MQTypeVar result = self_;
		if (result.Type != nullptr && !member_.empty())
		{
			if (result.Type->GetMember(result.GetVarPtr(), &member_[0], index, result))
				return lua_MQTypeVar(std::move(result));

			// can't guarantee result didn't get modified, but we want to return nil if GetMember was false
			return lua_MQTypeVar();
		}

		return *this;
	}

	static std::string to_string(const lua_MQTypeVar& obj)
	{
		auto var = obj.evaluate_member();
		if (var.self_.Type != nullptr)
		{
			char buf[2048] = { 0 };
			var.self_.Type->ToString(var.self_, buf);
			return std::string(std::move(buf));
		}

		return "null";
	}

	sol::object call(std::string index, sol::this_state L) const
	{
		return sol::object(L, sol::in_place, lua_MQTypeVar(evaluate_member(&index[0])));
	}

	sol::object call_int(int index, sol::this_state L) const
	{
		return call(std::to_string(index), L);
	}

	sol::object call_empty(sol::this_state L) const
	{
		auto result = evaluate_member();

		if (result.self_.Type == nullptr)
			return sol::object(L, sol::in_place, sol::lua_nil);

		// There are seven basic types in Lua: nil, number, string, function, CFunction, userdata, and table. 
		// We only care about nil, number, and string, but multiple MQ types decay into the various types, so
		// we need to capture that.
		switch (result.self_.GetType())
		{
		case MQVarPtr::VariantIdx::Float:
		case MQVarPtr::VariantIdx::Double:
			// lua's number type is the same for integral and floating, but sol handles them each slightly differently
			return sol::object(L, sol::in_place, result.self_.Get<double>());
		case MQVarPtr::VariantIdx::Int32:
		case MQVarPtr::VariantIdx::Int64:
			return sol::object(L, sol::in_place, result.self_.Get<int64_t>());
		case MQVarPtr::VariantIdx::UInt32:
		case MQVarPtr::VariantIdx::UInt64:
			return sol::object(L, sol::in_place, result.self_.Get<uint64_t>());
		case MQVarPtr::VariantIdx::String:
			// if we know it's a string, let's get a string explicitly
			return sol::object(L, sol::in_place, result.self_.Get<CXStr>().c_str());
		default:
			// by default run it through the tostring conversion because we are assuming calling with empty parens means
			// to actualize the data in the native lua space
			char buf[MAX_STRING] = { 0 };
			result.self_.Type->ToString(result.self_.GetVarPtr(), buf);
			return sol::object(L, sol::in_place, buf);
		}
	}

	sol::object get(sol::stack_object key, sol::this_state L) const
	{
		auto var = lua_MQTypeVar(evaluate_member());
		auto maybe_key = key.as<std::optional<std::string_view>>();

		if (maybe_key)
			var.member_ = *maybe_key;

		return sol::object(L, sol::in_place, var);
	}
};

struct lua_MQDataItem
{
	const MQDataItem* const self_;

	lua_MQDataItem() : self_(nullptr) {}

	// this will allow users an alternate way to get data items
	lua_MQDataItem(const std::string& str) : self_(FindMQ2Data(str.c_str())) {}

	lua_MQDataItem(const MQDataItem* const self) : self_(self) {}

	lua_MQTypeVar evaluate_self() const
	{
		MQTypeVar result;
		if (self_ != nullptr)
			self_->Function("", result);

		return lua_MQTypeVar(std::move(result));
	}

	bool operator==(const lua_MQDataItem& right) const
	{
		return evaluate_self().self_ == right.evaluate_self().self_;
	}

	bool equal_var(const lua_MQTypeVar& right) const
	{
		return evaluate_self().self_ == right.evaluate_member().self_;
	}

	static std::string to_string(const lua_MQDataItem& data)
	{
		return lua_MQTypeVar::to_string(data.evaluate_self());
	}

	[[nodiscard]] sol::object call(const std::string& index, sol::this_state L) const
	{
		MQTypeVar result;
		if (self_ != nullptr && self_->Function(index.c_str(), result))
			return sol::object(L, sol::in_place, lua_MQTypeVar(std::move(result)));

		return sol::object(L, sol::in_place, lua_MQTypeVar());
	}

	[[nodiscard]] sol::object call_int(int index, sol::this_state L) const
	{
		return call(std::to_string(index), L);
	}

	[[nodiscard]] sol::object call_empty(sol::this_state L) const
	{
		MQTypeVar result;
		if (self_ != nullptr && self_->Function("", result))
			return lua_MQTypeVar(std::move(result)).call_empty(L);

		return sol::object(L, sol::in_place, sol::lua_nil);
	}

	[[nodiscard]] sol::object get(sol::stack_object key, sol::this_state L) const
	{
		MQTypeVar result;
		if (self_ != nullptr && self_->Function("", result))
			return lua_MQTypeVar(std::move(result)).get(key, L);

		return sol::object(L, sol::in_place, lua_MQTypeVar());
	}
};

bool lua_MQTypeVar::equal_data(const lua_MQDataItem& right) const
{
	return evaluate_member().self_ == right.evaluate_self().self_;
}

template <typename Handler>
bool sol_lua_check(sol::types<lua_MQTypeVar>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking)
{
	if (!sol::stack::check_usertype<lua_MQTypeVar>(L, index) &&
		!sol::stack::check_usertype<lua_MQDataItem>(L, index) &&
		!sol::stack::check<sol::lua_nil_t>(L, index))
	{
		handler(L, index, sol::type_of(L, index), sol::type::userdata, "Expected an MQ type");
		return false;
	}
	tracking.use(1);
	return true;
}

lua_MQTypeVar sol_lua_get(sol::types<lua_MQTypeVar>, lua_State* L, int index, sol::stack::record& tracking)
{
	if (sol::stack::check_usertype<lua_MQTypeVar>(L, index))
	{
		lua_MQTypeVar& var = sol::stack::get_usertype<lua_MQTypeVar>(L, index, tracking);
		var.evaluate_member();
		return var;
	}

	if (sol::stack::check_usertype<lua_MQDataItem>(L, index))
	{
		lua_MQDataItem& data = sol::stack::get_usertype<lua_MQDataItem>(L, index, tracking);
		return data.evaluate_self();
	}

	return lua_MQTypeVar();
}

template <typename Handler>
bool sol_lua_check(sol::types<lua_MQDataItem>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking)
{
	if (!sol::stack::check_usertype<lua_MQDataItem>(L, index) &&
		!sol::stack::check<sol::lua_nil_t>(L, index))
	{
		handler(L, index, sol::type_of(L, index), sol::type::userdata, "Expected an MQ type");
		return false;
	}
	tracking.use(1);
	return true;
}

lua_MQDataItem sol_lua_get(sol::types<lua_MQDataItem>, lua_State* L, int index, sol::stack::record& tracking)
{
	if (sol::stack::check_usertype<lua_MQDataItem>(L, index))
	{
		lua_MQDataItem& data = sol::stack::get_usertype<lua_MQDataItem>(L, index, tracking);
		return data;
	}

	return lua_MQDataItem();
}

struct lua_MQCommand
{
	std::string command_;

	lua_MQCommand(std::string_view command) : command_(command) {}

	void operator()(sol::variadic_args va)
	{
		std::stringstream cmd;
		cmd << command_;
		for (const auto& a : va)
		{
			auto value = luaL_tolstring(a.lua_state(), a.stack_index(), NULL);
			if (value != nullptr && strlen(value) > 0)
				cmd << " " << value;
		}

		HideDoCommand(pLocalPlayer, cmd.str().c_str(), false);
	}
};

struct lua_MQTLO
{
	[[nodiscard]] sol::object get(sol::stack_object key, sol::this_state L) const
	{
		auto maybe_key = key.as<std::optional<std::string>>();
		if (maybe_key)
		{
			MQDataItem* result = FindMQ2Data(maybe_key->c_str());
			if (result != nullptr)
				return sol::object(L, sol::in_place, lua_MQDataItem(result));
		}

		return sol::object(L, sol::in_place, sol::lua_nil);
	}
};

struct lua_MQDoCommand
{
	// this is only used to provide a namespace for commands
	[[nodiscard]] sol::object get(sol::stack_object key, sol::this_state L) const
	{
		auto maybe_key = key.as<std::optional<std::string>>();
		if (maybe_key)
		{
			std::string cmd("/");
			cmd += *maybe_key;
			if (IsCommand(cmd.c_str()))
				return sol::object(L, sol::in_place, lua_MQCommand(cmd));
		}

		return sol::object(L, sol::in_place, sol::lua_nil);
	}
};

static void register_mq_type(sol::state& lua)
{
	lua.open_libraries(sol::lib::base);

	lua.new_usertype<lua_MQTypeVar>("mqtype",
		sol::constructors<lua_MQTypeVar(const std::string&)>(),
		sol::meta_function::call, sol::overload(&lua_MQTypeVar::call, &lua_MQTypeVar::call_int, &lua_MQTypeVar::call_empty),
		sol::meta_function::index, &lua_MQTypeVar::get,
		sol::meta_function::to_string, lua_MQTypeVar::to_string,
		sol::meta_function::equal_to, sol::overload(&lua_MQTypeVar::operator==, &lua_MQTypeVar::equal_data));

	lua.new_usertype<lua_MQDataItem>("mqdata",
		sol::constructors<lua_MQDataItem(const std::string&)>(),
		sol::meta_function::call, sol::overload(&lua_MQDataItem::call, &lua_MQDataItem::call_int, &lua_MQDataItem::call_empty),
		sol::meta_function::index, &lua_MQDataItem::get,
		sol::meta_function::to_string, lua_MQDataItem::to_string,
		sol::meta_function::equal_to, sol::overload(&lua_MQDataItem::operator==, &lua_MQDataItem::equal_var));

	lua.new_usertype<lua_MQCommand>("mqcommand",
		sol::no_constructor);

	lua.new_usertype<lua_MQTLO>("mqtlo",
		sol::no_constructor,
		sol::meta_function::index, &lua_MQTLO::get);

	lua.new_usertype<lua_MQDoCommand>("mqdocommand",
		sol::no_constructor,
		sol::meta_function::index, &lua_MQDoCommand::get);

	lua["TLO"] = lua_MQTLO();
	lua["cmd"] = lua_MQDoCommand();
	lua["null"] = lua_MQTypeVar();

	// TODO: need to implement a sleep command that doesn't use any macrostate
	//       variables. delay can redirect to this sleep function. Also investigate
	//       other macro commands that rely on macrostate variables (/dquery?)
}

static void ForceYield(lua_State* L, lua_Debug* D)
{
	lua_yield(L, 0);
}

void LuaCommand(SPAWNINFO* pChar, char* Buffer)
{
	// TODO: redo this to accept arguments and instead generate a PID to map with.
	//       this should be a simple call to another function that returns a PID
	//       so it can be reused as a lua function call where you can simple store
	//       PIDs of called scripts.
	//       This also implies that we need to have a way to search PIDs (inside
	//       the TLO, but also in lua)
	MQ2Args arg_parser("MQ2Lua: A lua script binding plugin.");
	arg_parser.Prog("/lua");
	args::Group arguments(arg_parser, "");
	args::Positional<std::string> script(arguments, "script", "the name of the lua script to run. will automatically append .lua extension if no extension specified.");
	args::Positional<std::string> name(arguments, "name", "optional parameter to specify a callback name if different from the first parameter.");

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
		const std::string& entry = name.Matched() ? name.Get() : script.Get();

		// don't do anything if we already have the same key
		if (std::find_if(s_running.cbegin(), s_running.cend(), [&entry](const std::pair<std::string, sol::thread>& kv) -> bool
			{
				return kv.first == entry;
			}) == s_running.cend() && s_paused.find(entry) == s_paused.cend())
		{
			auto script_path = std::filesystem::path(script.Get());
			if (script_path.is_relative()) script_path = s_luaDir / script_path;
			if (!script_path.has_extension()) script_path += ".lua";

			auto thread = sol::thread::create(s_lua);
			try
			{
				sol::coroutine co = thread.state().load_file(script_path.string());

				s_running.emplace_back(entry, thread);
				lua_sethook(thread.state(), ForceYield, LUA_MASKCOUNT, TURBO_NUM);

				WriteChatf("Running lua script '%s' from path %s", entry.c_str(), script_path.c_str());

				auto result = co();
			}
			catch (sol::error& e)
			{
				MacroError("%s", e.what());
				if (s_running.back().first == entry)
					s_running.pop_back();
			}
		}
		else
		{
			MacroError("'%s' is already running!", entry.c_str());
		}
	}
}

void EndLuaCommand(SPAWNINFO* pChar, char* Buffer)
{
	MQ2Args arg_parser("MQ2Lua: A lua script binding plugin.");
	arg_parser.Prog("/endlua");
	arg_parser.RequireCommand(false);
	args::Group arguments(arg_parser, "");
	args::Positional<std::string> name(arguments, "name", "optional parameter to specify a callback name of script to stop, if not specified will stop all running scripts.");

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

	if (name)
	{
		auto thread_it = std::find_if(s_running.begin(), s_running.end(), [&name](const std::pair<std::string, sol::thread>& kv) -> bool
			{
				return kv.first == name.Get();
			});

		if (thread_it != s_running.end())
		{
			// this will force the coroutine to yield, and removing this thread from the vector will cause it to gc
			lua_sethook(thread_it->second.state(), ForceYield, LUA_MASKLINE, 0);
			WriteChatf("Ending running lua script '%s'", thread_it->first.c_str());
			s_running.erase(thread_it);
		}
		else
		{
			// didn't find a running thread, let's just kill the paused thread if it exists
			if (s_paused.erase(name.Get()) > 0)
				WriteChatf("Ended paused lua script '%s'", name.Get().c_str());
			else
				WriteChatf("No lua script '%s' to end", name.Get().c_str());
		}
	}
	else
	{
		// kill all scripts
		for (const auto& kv : s_running)
			lua_sethook(kv.second.state(), ForceYield, LUA_MASKLINE, 0);

		s_running.clear();
		s_paused.clear(); // don't need to stop these, they've already yielded

		WriteChatf("Ending ALL lua scripts");
	}
}

void LuaPauseCommand(SPAWNINFO* pChar, char* Buffer)
{
	MQ2Args arg_parser("MQ2Lua: A lua script binding plugin.");
	arg_parser.Prog("/luapause");
	arg_parser.RequireCommand(false);
	args::Group arguments(arg_parser, "");
	args::Positional<std::string> name(arguments, "name", "optional parameter to specify a callback name of script to pause, if not specified will pause all running scripts.");

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

	if (name)
	{
		auto thread_it = std::find_if(s_running.begin(), s_running.end(), [&name](const std::pair<std::string, sol::thread>& kv) -> bool
			{
				return kv.first == name.Get();
			});

		if (thread_it != s_running.end())
		{
			// this will force the coroutine to yield, and removing this thread from the vector will cause it to gc
			lua_sethook(thread_it->second.state(), ForceYield, LUA_MASKLINE, 0);
			WriteChatf("Pausing running lua script '%s'", thread_it->first.c_str());
			s_paused.emplace(*thread_it); // already got the pair, just put it in paused
			s_running.erase(thread_it);
		}
		else
		{
			// didn't find a running thread, so restart a paused thread if it exists
			auto thread_it = s_paused.find(name.Get());
			if (thread_it != s_paused.end())
			{
				WriteChatf("Resuming paused lua script '%s'", name.Get().c_str());
				s_running.emplace_back(*thread_it);
				s_paused.erase(thread_it);
			}
			else
				WriteChatf("No lua script '%s' to pause/resume", name.Get().c_str());
		}
	}
	else
	{
		// try to get the user's intention here. If all scripts are running/paused, batch toggle state. If there are any running, assume we want to pause those only.
		if (!s_running.empty())
		{
			for (const auto& kv : s_running)
			{
				lua_sethook(kv.second.state(), ForceYield, LUA_MASKLINE, 0);
				s_paused.emplace(kv);
			}

			s_running.clear();

			WriteChatf("Pausing ALL running lua scripts");
		}
		else if (!s_paused.empty())
		{
			// we have no running scripts, so restart all paused scripts
			for (const auto& kv : s_paused)
				s_running.emplace_back(kv);

			s_paused.clear();

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
	// TODO: This needs to actually create a script with a PID in the s_running
	//       map so things like sleep() will be respected.

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
		try
		{
			s_lua.script(join(script.Get(), " "));
		}
		catch (sol::error& e)
		{
			MacroError("%s", e.what());
		}
	}
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

	if (!std::filesystem::exists(s_luaDir) && !std::filesystem::create_directories(s_luaDir))
	{
		WriteChatf("Failed to open or create directory at %s. Scripts will not run.", s_luaDir.c_str());
	}

	// TODO: Add the Lua TLO, which will include things like the lua script
	//       directory, the "turbo" parameter (which also needs a command to
	//       change at runtime), and current running lua scripts with PIDs
	// TODO: Add the /luaturbo command to change the lua turbo setting
	register_mq_type(s_lua);

	AddCommand("/lua", LuaCommand);
	AddCommand("/endlua", EndLuaCommand);
	AddCommand("/luapause", LuaPauseCommand);
	AddCommand("/luastring", LuaStringCommand);

	//	s_lua.safe_script("y = mq.Me.PctHPs\nx = (y == null)\n", sol::script_pass_on_error); // this is nil before a character is loaded, use to test nil handling
	//	s_lua.script("x = mq.EverQuest.GameState\n");
	//	s_lua.script("x = mq.Int(20).Hex\n");


	// this will freeze the client!
//	char cmd[] = R"(
//function f ()
//  x = 1
//  while true
//  do
//    mq.echo(tostring(x))
//    x = x + 1
//  end
//end
//
//co = coroutine.create(f)
//
//while true
//do
//  coroutine.resume(co)
//end
//)";

	//char cmd[] = "mq.echo(mq.EverQuest.GameState)\n";

	//LuaCommand(nullptr, cmd);// "y = mq.Int(20).Hex\nx = mq.EverQuest.GameState\n");

	// Examples:
	// AddCommand("/mycommand", MyCommand);
	// AddXMLFile("MQUI_MyXMLFile.xml");
	// AddMQ2Data("mytlo", MyTLOData);
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

	// Examples:
	// RemoveCommand("/mycommand");
	// RemoveXMLFile("MQUI_MyXMLFile.xml");
	// RemoveMQ2Data("mytlo");
}

/**
 * @fn OnCleanUI
 *
 * This is called once just before the shutdown of the UI system and each time the
 * game requests that the UI be cleaned.  Most commonly this happens when a
 * /loadskin command is issued, but it also occurs when reaching the character
 * select screen and when first entering the game.
 *
 * One purpose of this function is to allow you to destroy any custom windows that
 * you have created and cleanup any UI items that need to be removed.
 */
PLUGIN_API void OnCleanUI()
{
	// DebugSpewAlways("MQ2Lua::OnCleanUI()");
}

/**
 * @fn OnReloadUI
 *
 * This is called once just after the UI system is loaded. Most commonly this
 * happens when a /loadskin command is issued, but it also occurs when first
 * entering the game.
 *
 * One purpose of this function is to allow you to recreate any custom windows
 * that you have setup.
 */
PLUGIN_API void OnReloadUI()
{
	// DebugSpewAlways("MQ2Lua::OnReloadUI()");
}

/**
 * @fn OnDrawHUD
 *
 * This is called each time the Heads Up Display (HUD) is drawn.  The HUD is
 * responsible for the net status and packet loss bar.
 *
 * Note that this is not called at all if the HUD is not shown (default F11 to
 * toggle).
 *
 * Because the net status is updated frequently, it is recommended to have a
 * timer or counter at the start of this call to limit the amount of times the
 * code in this section is executed.
 */
PLUGIN_API void OnDrawHUD()
{
/*
	static int DrawHUDCount = 0;
	// Skip ~500 draws
	if (++DrawHUDCount > 500)
	{
		DrawHUDCount = 0;
		DebugSpewAlways("MQ2Lua::OnDrawHUD()");
	}
*/
}

/**
 * @fn SetGameState
 *
 * This is called when the GameState changes.  It is also called once after the
 * plugin is initialized.
 *
 * For a list of known GameState values, see the constants that begin with
 * GAMESTATE_.  The most commonly used of these is GAMESTATE_INGAME.
 *
 * When zoning, this is called once after @ref OnBeginZone @ref OnRemoveSpawn
 * and @ref OnRemoveGroundItem are all done and then called once again after
 * @ref OnEndZone and @ref OnAddSpawn are done but prior to @ref OnAddGroundItem
 * and @ref OnZoned
 *
 * @param GameState int - The value of GameState at the time of the call
 */
PLUGIN_API void SetGameState(int GameState)
{
	// DebugSpewAlways("MQ2Lua::SetGameState(%d)", GameState);
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
		[](const std::pair<const std::string, sol::thread>& kv) -> bool {
			auto& [name, thread] = kv;
			if (thread.status() == sol::thread_status::yielded)
			{
				try
				{
					int nresults;
					lua_resume(thread.state(), nullptr, 0, &nresults);
					return false;
				}
				catch (sol::error& e)
				{
					MacroError("%s", e.what());
				}
			}

			WriteChatf("Ending lua script %s", name.c_str());
			return true;
		}),
		s_running.end());
/*
	static int PulseCount = 0;
	// Skip ~500 pulses
	if (++PulseCount > 500)
	{
		PulseCount = 0;
		DebugSpewAlways("MQ2Lua::OnPulse()");
	}
*/
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
	// DebugSpewAlways("MQ2Lua::OnWriteChatColor(%s, %d, %d)", Line, Color, Filter);
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
	// DebugSpewAlways("MQ2Lua::OnIncomingChat(%s, %d)", Line, Color);
	return false;
}

/**
 * @fn OnAddSpawn
 *
 * This is called each time a spawn is added to a zone (ie, something spawns). It is
 * also called for each existing spawn when a plugin first initializes.
 *
 * When zoning, this is called for all spawns in the zone after @ref OnEndZone is
 * called and before @ref OnZoned is called.
 *
 * @param pNewSpawn PSPAWNINFO - The spawn that was added
 */
PLUGIN_API void OnAddSpawn(PSPAWNINFO pNewSpawn)
{
	// DebugSpewAlways("MQ2Lua::OnAddSpawn(%s)", pNewSpawn->Name);
}

/**
 * @fn OnRemoveSpawn
 *
 * This is called each time a spawn is removed from a zone (ie, something despawns
 * or is killed).  It is NOT called when a plugin shuts down.
 *
 * When zoning, this is called for all spawns in the zone after @ref OnBeginZone is
 * called.
 *
 * @param pSpawn PSPAWNINFO - The spawn that was removed
 */
PLUGIN_API void OnRemoveSpawn(PSPAWNINFO pSpawn)
{
	// DebugSpewAlways("MQ2Lua::OnRemoveSpawn(%s)", pSpawn->Name);
}

/**
 * @fn OnAddGroundItem
 *
 * This is called each time a ground item is added to a zone (ie, something spawns).
 * It is also called for each existing ground item when a plugin first initializes.
 *
 * When zoning, this is called for all ground items in the zone after @ref OnEndZone
 * is called and before @ref OnZoned is called.
 *
 * @param pNewGroundItem PGROUNDITEM - The ground item that was added
 */
PLUGIN_API void OnAddGroundItem(PGROUNDITEM pNewGroundItem)
{
	// DebugSpewAlways("MQ2Lua::OnAddGroundItem(%d)", pNewGroundItem->DropID);
}

/**
 * @fn OnRemoveGroundItem
 *
 * This is called each time a ground item is removed from a zone (ie, something
 * despawns or is picked up).  It is NOT called when a plugin shuts down.
 *
 * When zoning, this is called for all ground items in the zone after
 * @ref OnBeginZone is called.
 *
 * @param pGroundItem PGROUNDITEM - The ground item that was removed
 */
PLUGIN_API void OnRemoveGroundItem(PGROUNDITEM pGroundItem)
{
	// DebugSpewAlways("MQ2Lua::OnRemoveGroundItem(%d)", pGroundItem->DropID);
}

/**
 * @fn OnBeginZone
 *
 * This is called just after entering a zone line and as the loading screen appears.
 */
PLUGIN_API void OnBeginZone()
{
	// DebugSpewAlways("MQ2Lua::OnBeginZone()");
}

/**
 * @fn OnEndZone
 *
 * This is called just after the loading screen, but prior to the zone being fully
 * loaded.
 *
 * This should occur before @ref OnAddSpawn and @ref OnAddGroundItem are called. It
 * always occurs before @ref OnZoned is called.
 */
PLUGIN_API void OnEndZone()
{
	// DebugSpewAlways("MQ2Lua::OnEndZone()");
}

/**
 * @fn OnZoned
 *
 * This is called after entering a new zone and the zone is considered "loaded."
 *
 * It occurs after @ref OnEndZone @ref OnAddSpawn and @ref OnAddGroundItem have
 * been called.
 */
PLUGIN_API void OnZoned()
{
	// DebugSpewAlways("MQ2Lua::OnZoned()");
}

/**
 * @fn OnUpdateImGui
 *
 * This is called each time that the ImGui Overlay is rendered. Use this to render
 * and update plugin specific widgets.
 *
 * Because this happens extremely frequently, it is recommended to move any actual
 * work to a separate call and use this only for updating the display.
 */
PLUGIN_API void OnUpdateImGui()
{
/*
	static int UpdateCount = 0;
	// Skip ~4000 updates for debug spew message
	if (++UpdateCount > 4000)
	{
		UpdateCount = 0;
		DebugSpewAlways("MQ2Lua::OnUpdateImGui()");
	}

	if (GetGameState() == GAMESTATE_INGAME)
	{
		static bool ShowMQ2LuaWindow = true;
		ImGui::Begin("MQ2Lua", &ShowMQ2LuaWindow, ImGuiWindowFlags_MenuBar);
		if (ImGui::BeginMenuBar())
		{
			ImGui::Text("MQ2Lua is loaded!");
			ImGui::EndMenuBar();
		}
		ImGui::End();
	}
*/
}

/**
 * @fn OnMacroStart
 *
 * This is called each time a macro starts (ex: /mac somemacro.mac), prior to
 * launching the macro.
 *
 * @param Name const char* - The name of the macro that was launched
 */
PLUGIN_API void OnMacroStart(const char* Name)
{
	// DebugSpewAlways("MQ2Lua::OnMacroStart(%s)", Name);
}

/**
 * @fn OnMacroStop
 *
 * This is called each time a macro stops (ex: /endmac), after the macro has ended.
 *
 * @param Name const char* - The name of the macro that was stopped.
 */
PLUGIN_API void OnMacroStop(const char* Name)
{
	// DebugSpewAlways("MQ2Lua::OnMacroStop(%s)", Name);
}

/**
 * @fn OnLoadPlugin
 *
 * This is called each time a plugin is loaded (ex: /plugin someplugin), after the
 * plugin has been loaded and any associated -AutoExec.cfg file has been launched.
 * This means it will be executed after the plugin's @ref InitializePlugin callback.
 *
 * This is also called when THIS plugin is loaded, but initialization tasks should
 * still be done in @ref InitializePlugin.
 *
 * @param Name const char* - The name of the plugin that was loaded
 */
PLUGIN_API void OnLoadPlugin(const char* Name)
{
	// DebugSpewAlways("MQ2Lua::OnLoadPlugin(%s)", Name);
}

/**
 * @fn OnUnloadPlugin
 *
 * This is called each time a plugin is unloaded (ex: /plugin someplugin unload),
 * just prior to the plugin unloading.  This means it will be executed prior to that
 * plugin's @ref ShutdownPlugin callback.
 *
 * This is also called when THIS plugin is unloaded, but shutdown tasks should still
 * be done in @ref ShutdownPlugin.
 *
 * @param Name const char* - The name of the plugin that is to be unloaded
 */
PLUGIN_API void OnUnloadPlugin(const char* Name)
{
	// DebugSpewAlways("MQ2Lua::OnUnloadPlugin(%s)", Name);
}
