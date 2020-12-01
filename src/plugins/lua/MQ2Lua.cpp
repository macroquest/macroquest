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

#define TEMPLATE_AUTO(x) decltype(x), x

sol::state s_lua;

struct lua_MQTypeVar
{
	MQTypeVar self;
	std::string member;

	lua_MQTypeVar(const std::string& str)
	{
		auto type = FindMQ2DataType(str.c_str());
		if (type != nullptr)
		{
			self.Type = type;
		}
	}

	lua_MQTypeVar(const MQTypeVar& self) : self(self) {}

	lua_MQTypeVar(lua_MQTypeVar& other)
	{
		if (other.self.Type != nullptr && !other.member.empty())
		{
			char index[1] = "";
			MQTypeVar result;
			other.self.Type->GetMember(other.self.VarPtr, &other.member[0], index, result);

			self = result;
		}
		else
		{
			self = other.self;
			// don't copy member if type is null
		}
	}

	~lua_MQTypeVar() {}

	sol::object call(std::string index, sol::this_state L)
	{
		if (self.Type != nullptr && !member.empty())
		{
			MQTypeVar result;
			self.Type->GetMember(self.VarPtr, &member[0], &index[0], result);

			return sol::object(L, sol::in_place, lua_MQTypeVar(result));
		}

		return sol::object(L, sol::in_place, sol::lua_nil);
	}

	sol::object call_int(int index, sol::this_state L)
	{
		return call(std::to_string(index), L);
	}

	sol::object call_empty(sol::this_state L)
	{
		if (self.Type != nullptr && !member.empty())
		{
			char index[1] = "";
			MQTypeVar result;
			self.Type->GetMember(self.VarPtr, &member[0], index, result);

			return sol::object(L, sol::in_place, lua_MQTypeVar(result));
		}

		return sol::object(L, sol::in_place, sol::lua_nil);
	}

	sol::object get(sol::stack_object key, sol::this_state L)
	{
		auto maybe_key = key.as<std::optional<std::string_view>>();
		if (maybe_key && self.Type != nullptr)
		{
			if (!member.empty())
			{
				char index[1] = "";
				self.Type->GetMember(self.VarPtr, &member[0], index, self);
			}

			member = *maybe_key;
			return sol::object(L, sol::in_place, *this);
		}

		return sol::object(L, sol::in_place, sol::lua_nil);
	}
};

struct lua_MQDataItem
{
	const MQDataItem* const self;

	// this will allow users an alternate way to get data items
	lua_MQDataItem(const std::string& str) : self(FindMQ2Data(str.c_str())) {}

	lua_MQDataItem(const MQDataItem* const self) : self(self) {}

	lua_MQDataItem(lua_MQDataItem& other) : self(other.self) {}

	sol::object call(const std::string& index, sol::this_state L)
	{
		if (self != nullptr)
		{
			MQTypeVar result;
			if (self->Function(index.c_str(), result))
				return sol::object(L, sol::in_place, lua_MQTypeVar(result));
		}

		return sol::object(L, sol::in_place, sol::lua_nil);
	}

	sol::object call_int(int index, sol::this_state L)
	{
		return call(std::to_string(index), L);
	}

	sol::object call_empty(sol::this_state L)
	{
		if (self != nullptr)
		{
			MQTypeVar result;
			if (self->Function("", result))
				return sol::object(L, sol::in_place, lua_MQTypeVar(result));
		}

		return sol::object(L, sol::in_place, sol::lua_nil);
	}

	sol::object get(sol::stack_object key, sol::this_state L)
	{
		if (self != nullptr)
		{
			MQTypeVar result;
			if (self->Function("", result))
			{
				return lua_MQTypeVar(result).get(key, L);
			}
		}

		return sol::object(L, sol::in_place, sol::lua_nil);
	}
};

struct lua_mq
{
	sol::object get(sol::stack_object key, sol::this_state L)
	{
		auto maybe_key = key.as<std::optional<std::string>>();
		if (maybe_key)
		{
			MQDataItem* result;
			result = FindMQ2Data(maybe_key->c_str());
			if (result != nullptr)
				return sol::object(L, sol::in_place, lua_MQDataItem(result));
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

	lua.new_usertype<lua_mq>("mq",
		sol::no_constructor,
		sol::meta_function::index, &lua_mq::get);

	lua["TLO"] = lua_mq();
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

	s_lua.open_libraries(sol::lib::base);
	register_mq_type(s_lua);

	//s_lua.script("x = TLO.Me.PctHPs()\n"); // this is nil before a character is loaded, use to test nil handling
	//s_lua.script("x = TLO.EverQuest.GameState\n");
	s_lua.script("x = TLO.Int(20).Hex");

	lua_MQTypeVar& x = s_lua["x"];
	
	WriteChatf("%s", (const char*)x.self.Ptr);

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
