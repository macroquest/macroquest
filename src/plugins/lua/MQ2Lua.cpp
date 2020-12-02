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

/**
 * \brief a global lua state needed so that thread states don't go out of scope
 */
sol::state s_lua;
std::filesystem::path s_luaDir = std::filesystem::path(gPathMQRoot) / "lua"; // TODO: can make this configurable

ci_unordered::map<sol::state_view, sol::thread> s_instanceMap;
std::vector<sol::thread> s_instances;

struct lua_MQTypeVar
{
	MQTypeVar self_;
	std::string member_;

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

	lua_MQTypeVar(const lua_MQTypeVar& other) noexcept :
		self_(other.self_), member_(other.member_)
	{
		evaluate_member();
	}

	lua_MQTypeVar(lua_MQTypeVar&& other) noexcept :
		self_(std::move(other.self_)), member_(std::move(other.member_))
	{
		evaluate_member();
	}

	~lua_MQTypeVar() = default;

	lua_MQTypeVar& operator=(lua_MQTypeVar other) noexcept
	{
		swap(*this, other);
		return *this;
	}

	friend void swap(lua_MQTypeVar& first, lua_MQTypeVar& second) noexcept
	{
		using std::swap;
		swap(first.self_, second.self_);
		swap(first.member_, second.member_);
	}

	bool operator==(const lua_MQTypeVar& right) const
	{
		return self_ == right.self_;
	}

	void evaluate_member()
	{
		if (self_.Type != nullptr && !member_.empty())
		{
			char index[1] = "";
			MQTypeVar result;
			self_.Type->GetMember(self_.VarPtr, &member_[0], index, result);

			self_ = result;
			member_.clear();
		}
	}

	sol::object call(std::string index, sol::this_state L)
	{
		if (self_.Type != nullptr && !member_.empty())
		{
			MQTypeVar result;
			self_.Type->GetMember(self_.VarPtr, &member_[0], &index[0], result);

			return sol::object(L, sol::in_place, lua_MQTypeVar(std::move(result)));
		}

		return sol::object(L, sol::in_place, sol::lua_nil);
	}

	sol::object call_int(int index, sol::this_state L)
	{
		return call(std::to_string(index), L);
	}

	sol::object call_empty(sol::this_state L)
	{
		if (self_.Type != nullptr && !member_.empty())
		{
			char index[1] = "";
			MQTypeVar result;
			self_.Type->GetMember(self_.VarPtr, &member_[0], index, result);

			return sol::object(L, sol::in_place, lua_MQTypeVar(std::move(result)));
		}

		return sol::object(L, sol::in_place, sol::lua_nil);
	}

	sol::object get(sol::stack_object key, sol::this_state L)
	{
		auto maybe_key = key.as<std::optional<std::string_view>>();
		if (maybe_key && self_.Type != nullptr)
		{
			if (!member_.empty())
			{
				char index[1] = "";
				self_.Type->GetMember(self_.VarPtr, &member_[0], index, self_);
			}

			member_ = *maybe_key;
			return sol::object(L, sol::in_place, *this);
		}

		return sol::object(L, sol::in_place, sol::lua_nil);
	}
};

std::ostream& operator<<(std::ostream& os, lua_MQTypeVar& right)
{
	right.evaluate_member();

	if (right.self_.Type != nullptr)
	{
		char buf[2048] = { 0 };
		right.self_.Type->ToString(right.self_, buf);
		os << buf;
	}
	return os;
}

struct lua_MQDataItem
{
	const MQDataItem* const self_;

	// this will allow users an alternate way to get data items
	lua_MQDataItem(const std::string& str) : self_(FindMQ2Data(str.c_str())) {}

	lua_MQDataItem(const MQDataItem* const self) : self_(self) {}

	[[nodiscard]] sol::object call(const std::string& index, sol::this_state L) const
	{
		if (self_ != nullptr)
		{
			MQTypeVar result;
			if (self_->Function(index.c_str(), result))
				return sol::object(L, sol::in_place, lua_MQTypeVar(std::move(result)));
		}

		return sol::object(L, sol::in_place, sol::lua_nil);
	}

	[[nodiscard]] sol::object call_int(int index, sol::this_state L) const
	{
		return call(std::to_string(index), L);
	}

	[[nodiscard]] sol::object call_empty(sol::this_state L) const
	{
		if (self_ != nullptr)
		{
			MQTypeVar result;
			if (self_->Function("", result))
				return sol::object(L, sol::in_place, lua_MQTypeVar(std::move(result)));
		}

		return sol::object(L, sol::in_place, sol::lua_nil);
	}

	[[nodiscard]] sol::object get(sol::stack_object key, sol::this_state L) const
	{
		if (self_ != nullptr)
		{
			MQTypeVar result;
			if (self_->Function("", result))
			{
				return lua_MQTypeVar(std::move(result)).get(key, L);
			}
		}

		return sol::object(L, sol::in_place, sol::lua_nil);
	}
};

struct lua_MQCommand
{
	std::string command_;

	lua_MQCommand(std::string_view command) : command_(command) {}

	void operator()(sol::variadic_args va)
	{
		std::stringstream cmd;
		cmd << command_;
		for (const auto& a : va)
			cmd << " " << a.as<std::string_view>();

		HideDoCommand(pLocalPlayer, cmd.str().c_str(), false);
	}
};

struct lua_mq
{
	[[nodiscard]] sol::object get(sol::stack_object key, sol::this_state L) const
	{
		auto maybe_key = key.as<std::optional<std::string>>();
		if (maybe_key)
		{
			{
				MQDataItem* result = FindMQ2Data(maybe_key->c_str());
				if (result != nullptr)
					return sol::object(L, sol::in_place, lua_MQDataItem(result));
			}

			{
				std::string maybe_command("/");
				maybe_command += *maybe_key;
				if (IsCommand(maybe_command.c_str()))
					return sol::object(L, sol::in_place, lua_MQCommand(maybe_command));
			}
		}

		return sol::object(L, sol::in_place, sol::lua_nil);
	}
};

static void register_mq_type(sol::state& lua)
{
	lua.new_usertype<lua_MQTypeVar>("mqtype",
		sol::constructors<lua_MQTypeVar(const std::string&), lua_MQTypeVar(lua_MQTypeVar&)>(),
		sol::meta_function::call, sol::overload(&lua_MQTypeVar::call, &lua_MQTypeVar::call_int, &lua_MQTypeVar::call_empty),
		sol::meta_function::index, &lua_MQTypeVar::get);

	lua.new_usertype<lua_MQDataItem>("mqdata",
		sol::constructors<lua_MQDataItem(const std::string&), lua_MQDataItem(lua_MQDataItem&)>(),
		sol::meta_function::call, sol::overload(&lua_MQDataItem::call, &lua_MQDataItem::call_int, &lua_MQDataItem::call_empty),
		sol::meta_function::index, &lua_MQDataItem::get);

	lua.new_usertype<lua_MQCommand>("mqcommand",
		sol::no_constructor);

	lua.new_usertype<lua_mq>("mqbind",
		sol::no_constructor,
		sol::meta_function::index, &lua_mq::get);

	lua["mq"] = lua_mq();
}

static void ForceYield(lua_State* L, lua_Debug* D)
{
	lua_yield(L, 0);
}

void LuaCommand(SPAWNINFO* pChar, char* Buffer)
{
	// TODO: change this to accept a path
	// TODO: add a stop command that exploits hooks
	// TODO: add a pause command that also exploits hooks (harder because we have to know to resume or not, store in paused vector)
	auto x = sol::thread::create(s_lua);

	s_instances.emplace_back(x);
	sol::coroutine script = x.state().load(Buffer);

	lua_sethook(x.state(), ForceYield, LUA_MASKCOUNT, TURBO_NUM);

	try
	{
		auto result = script();
	}
	catch (sol::error& e)
	{
		MacroError("%s", e.what());
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

	s_lua.open_libraries(sol::lib::base);
	register_mq_type(s_lua);

	AddCommand("/lua", LuaCommand);

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

	char cmd[] = "mq.echo(mq.EverQuest.GameState)\n";

	LuaCommand(nullptr, cmd);// "y = mq.Int(20).Hex\nx = mq.EverQuest.GameState\n");

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
	s_instances.erase(std::remove_if(
		s_instances.begin(), s_instances.end(),
		[](const sol::thread& thread) -> bool {
			if (thread.status() == sol::thread_status::yielded)
			{
				try
				{
					lua_resume(thread.state(), nullptr, 0);
					return false;
				}
				catch (sol::error& e)
				{
					MacroError("%s", e.what());
					return true;
				}
			}

			return true;
		}),
		s_instances.end());
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
