// MQ2Lua.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup.

#include <mq/Plugin.h>
#include <mq/utils/Args.h>
#include <Yaml.hpp>

#include <sol/sol.hpp>

#include <string>

PreSetup("MQ2Lua");
PLUGIN_VERSION(0.1);

using namespace mq;
using namespace mq::datatypes;

using MQ2Args = Args<&WriteChatf>;
using MQ2HelpArgument = HelpArgument;

uint32_t s_turboNum = 500;
std::filesystem::path s_luaDir = std::filesystem::path(gPathMQRoot) / "lua";

// this is static and will never change
static std::filesystem::path s_configPath = std::filesystem::path(gPathConfig) / "MQ2Lua.yaml";
static Yaml::Node s_configNode;

/**
 * \brief a global lua state needed so that thread states don't go out of scope
 */
sol::state s_lua;

static void ForceYield(lua_State* L, lua_Debug* D)
{
	lua_yield(L, 0);
}

#pragma region Threads

struct ThreadState;
struct LuaThread
{
	sol::thread m_thread;
	sol::environment m_env;
	std::string m_name;
	std::unique_ptr<ThreadState> m_state;
	uint32_t m_PID;

	static uint32_t next_id()
	{
		// no need to do anything special, this will be fine
		static uint32_t next = 0;
		return ++next;
	}
};

struct ThreadState
{
	virtual bool should_run(const LuaThread& thread) = 0;
	virtual bool is_paused() = 0;
	virtual void set_delay(const LuaThread& thread, uint64_t time, std::optional<sol::function> condition = std::nullopt) = 0;
	virtual void pause(LuaThread& thread) = 0;

	static bool check_condition(const LuaThread& thread, std::optional<sol::function>& func)
	{
		if (func)
		{
			try
			{
				auto check = sol::function(s_lua, *func);
				thread.m_env.set_on(check);
				return check();
			}
			catch (sol::error& e)
			{
				MacroError("Failed to check delay condition check with error '%s'", e.what());
				func = std::nullopt;
			}
		}

		return false;
	}
};

struct RunningState : public ThreadState
{
	RunningState() : m_delayTime(0L), m_delayCondition(std::nullopt) {}

	bool should_run(const LuaThread& thread) override
	{
		// check delayed status here
		bool delay_condition = check_condition(thread, m_delayCondition);

		if (m_delayTime <= MQGetTickCount64() || delay_condition)
		{
			lua_sethook(thread.m_thread.state(), ForceYield, LUA_MASKCOUNT, s_turboNum);
			m_delayTime = 0L;
			m_delayCondition = std::nullopt;
			return true;
		}

		return false;
	}

	bool is_paused() override { return false; }

	void set_delay(const LuaThread& thread, uint64_t time, std::optional<sol::function> condition = std::nullopt) override
	{
		bool delay_condition = check_condition(thread, condition);

		if (time > MQGetTickCount64() && !delay_condition)
		{
			lua_sethook(thread.m_thread.state(), ForceYield, LUA_MASKLINE, 0);
			m_delayTime = time;
			m_delayCondition = condition;
		}
	}

	void pause(LuaThread&) override;

private:
	uint64_t m_delayTime;
	std::optional<sol::function> m_delayCondition;
};

struct PausedState : public ThreadState
{
	bool should_run(const LuaThread&) override { return false; }
	bool is_paused() override { return true; }
	void set_delay(const LuaThread& thread, uint64_t time, std::optional<sol::function> condition = std::nullopt) override {}
	void pause(LuaThread& thread) override
	{
		lua_sethook(thread.m_thread.state(), ForceYield, LUA_MASKCOUNT, s_turboNum);
		WriteChatf("Resuming paused lua script '%s' with PID %d", thread.m_name.c_str(), thread.m_PID);
		thread.m_state = std::make_unique<RunningState>();
	}

};

void RunningState::pause(LuaThread& thread)
{
	// this will force the coroutine to yield, and removing this thread from the vector will cause it to gc
	lua_sethook(thread.m_thread.state(), ForceYield, LUA_MASKLINE, 0);
	WriteChatf("Pausing running lua script '%s' with PID %d", thread.m_name.c_str(), thread.m_PID);
	thread.m_state = std::make_unique<PausedState>();
}

#pragma endregion

// use a vector for s_running because we need to iterate it every pulse, and find only if a command is issued
std::vector<LuaThread> s_running;

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

// TODO: add variadic args to call for multi-parameter parsing
// TODO: add concat support
// TODO: add function that creates "args" with delim

#pragma region Bindings

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

static void delay(sol::object delayObj, sol::object conditionObj, sol::this_state s)
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
		auto it = std::find_if(s_running.begin(), s_running.end(), [&s](LuaThread& thread)
			{
				return thread.m_thread.thread_state() == s.lua_state();
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
					auto result = it->m_thread.state().load(
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

			it->m_state->set_delay(*it, delay_ms + MQGetTickCount64(), condition);
		}
	}
}

static void register_mq_type(sol::state& lua)
{
	lua.open_libraries();

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
	lua["delay"] = delay;
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
				[](const LuaThread& thread) { return std::to_string(thread.m_PID); });
			strcpy_s(DataTypeTemp, join(pids, ",").c_str());
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		case Members::Dir:
			Dest.Type = pStringType;
			strcpy_s(DataTypeTemp, s_luaDir.string().c_str());
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
		auto script_path = std::filesystem::path(script.Get());
		if (script_path.is_relative()) script_path = s_luaDir / script_path;
		if (!script_path.has_extension()) script_path += ".lua";

		sol::environment env(s_lua, sol::create, s_lua.globals());
		auto thread = sol::thread::create(s_lua);
		env.set_on(thread);
		auto entry = LuaThread{ thread, env, script.Get(), std::make_unique<RunningState>(), LuaThread::next_id() };
		WriteChatf("Running lua script '%s' with PID %d", script.Get().c_str(), entry.m_PID);
		s_running.emplace_back(std::move(entry));

		try
		{
			sol::coroutine co = thread.state().load_file(script_path.string());
			lua_sethook(thread.state(), ForceYield, LUA_MASKCOUNT, s_turboNum);

			// this manually runs the script with the vector of arguments that the user specified.
			// need to do it this way because we want to break up arguments and not pass a single
			// vector 
			co.push();
			for (auto arg : script_args.Get())
				sol::stack::push(thread.state(), arg);
			
			int nresults;
			lua_resume(thread.state(), nullptr, script_args.Get().size(), &nresults);

			//auto result = co(join(script_args.Get(), " "));
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
		auto thread_it = std::find_if(s_running.begin(), s_running.end(), [&pid](const LuaThread& thread) -> bool
			{
				return thread.m_PID == pid.Get();
			});

		if (thread_it != s_running.end())
		{
			// this will force the coroutine to yield, and removing this thread from the vector will cause it to gc
			lua_sethook(thread_it->m_thread.state(), ForceYield, LUA_MASKLINE, 0);
			WriteChatf("Ending running lua script '%s' with PID %d", thread_it->m_name.c_str(), thread_it->m_PID);
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
		for (const auto& thread : s_running)
			lua_sethook(thread.m_thread.state(), ForceYield, LUA_MASKLINE, 0);

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
		auto thread_it = std::find_if(s_running.begin(), s_running.end(), [&pid](const LuaThread& thread) -> bool
			{
				return thread.m_PID == pid.Get();
			});

		if (thread_it != s_running.end())
		{
			thread_it->m_state->pause(*thread_it);
		}
		else
		{
			WriteChatf("No lua script with PID %d to pause/resume", pid.Get());
		}
	}
	else
	{
		// try to get the user's intention here. If all scripts are running/paused, batch toggle state. If there are any running, assume we want to pause those only.
		if (std::find_if(s_running.cbegin(), s_running.cend(), [](const LuaThread& thread) -> bool {
			return thread.m_state->is_paused();
			}) != s_running.cend())
		{
			// have at least one running script, so pause all running scripts
			for (auto& thread : s_running)
				thread.m_state->pause(thread);

			WriteChatf("Pausing ALL running lua scripts");
		}
		else if (!s_running.empty())
		{
			// we have no running scripts, so restart all paused scripts
			for (auto& thread : s_running)
				thread.m_state->pause(thread);

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
		sol::environment env(s_lua, sol::create, s_lua.globals());
		auto thread = sol::thread::create(s_lua);
		env.set_on(thread);
		auto entry = LuaThread{ thread, env, "/luastring", std::make_unique<RunningState>(), LuaThread::next_id() };
		WriteChatf("Running lua string with PID %d", entry.m_PID);
		s_running.emplace_back(std::move(entry));

		try
		{
			sol::coroutine co = thread.state().load(join(script.Get(), " "));
			lua_sethook(thread.state(), ForceYield, LUA_MASKCOUNT, s_turboNum);

			auto result = co();
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
	Yaml::Serialize(s_configNode, s_configPath.string().c_str());
}

void ReadSettings()
{
	try
	{
		Yaml::Parse(s_configNode, s_configPath.string().c_str());
	}
	catch (const Yaml::OperationException&)
	{
		// if we can't read the file, then try to write it with an empty config
		Yaml::Serialize(s_configNode, s_configPath.string());
	}

	s_turboNum = s_configNode["turboNum"].As<uint32_t>(s_turboNum);
	s_luaDir = s_configNode["luaDir"].As<std::string>(s_luaDir.string());
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
		[](LuaThread& thread) -> bool {
			// should_run() will automatically re-set the count debug hook when appropriate so we can simply change the turboNum on the fly and it will be respected next pulse.
			if (thread.m_thread.status() == sol::thread_status::yielded && thread.m_state->should_run(thread))
			{
				try
				{
					int nresults;
					lua_resume(thread.m_thread.state(), nullptr, 0, &nresults);
				}
				catch (sol::error& e)
				{
					MacroError("Ending lua script '%s' with PID %d and error %s", thread.m_name.c_str(), thread.m_PID, e.what());
					return true;
				}
			}

			if (thread.m_thread.status() == sol::thread_status::runtime)
			{
				auto str = luaL_tolstring(thread.m_thread.state(), -1, NULL);
				MacroError("Ending lua script %s with PID %d and error '%s'", thread.m_name.c_str(), thread.m_PID, str);
				return true;
			}

			if (thread.m_thread.status() != sol::thread_status::ok && thread.m_thread.status() != sol::thread_status::yielded)
			{
				WriteChatf("Ending lua script %s with PID %d and status %d", thread.m_name.c_str(), thread.m_PID, static_cast<int>(thread.m_thread.status()));
				return true;
			}

			return false;
		}),
		s_running.end());
}
