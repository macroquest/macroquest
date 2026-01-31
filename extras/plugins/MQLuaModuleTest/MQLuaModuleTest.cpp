// MQLuaModuleTest.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup.

#include <mq/Plugin.h>
#include "plugins/lua/LuaInterface.h"
#include <cstring>
#include <stdexcept>

PreSetup("MQLuaModuleTest");
PLUGIN_VERSION(0.1);

static constexpr const char* kLuaModuleName = "luamoduletest";
static mq::lua::LuaPluginInterface* s_lua = nullptr;

static sol::object RegisterLuaModule(sol::this_state s)
{
	sol::state_view sv{ s };
	sol::table module = sv.create_table();

	module.set_function("ping", []() { return "pong"; });
	module.set_function("add", sol::overload(
		[](int a, int b) { return a + b; },
		[](sol::table t) {
			int a = t.get_or("a", 0);
			int b = t.get_or("b", 0);
			return a + b;
		}));
	module.set_function("echo", [](sol::object value) { return value; });
	module.set_function("make_point", [](double x, double y, sol::this_state s) {
		sol::state_view state{ s };
		sol::table point = state.create_table();
		point["x"] = x;
		point["y"] = y;
		return point;
	});
	module.set_function("boom", []() {
		throw std::runtime_error("boom");
	});

	return sol::make_object(s, module);
}

PLUGIN_API void InitializePlugin()
{
	DebugSpewAlways("MQLuaModuleTest::Initializing version %f", MQ2Version);

	s_lua = mq::lua::GetLuaInterface();
	if (!s_lua)
	{
		WriteChatf("MQLuaModuleTest: MQ2Lua is not loaded.");
		return;
	}

	if (!s_lua->RegisterLuaModule(kLuaModuleName, &RegisterLuaModule, mqplugin::ThisPluginHandle))
	{
		WriteChatf("MQLuaModuleTest: Failed to register Lua module '%s'.", kLuaModuleName);
	}
}

PLUGIN_API void ShutdownPlugin()
{
	DebugSpewAlways("MQLuaModuleTest::Shutting down");

	if (s_lua)
	{
		s_lua->UnregisterLuaModule(kLuaModuleName, mqplugin::ThisPluginHandle);
		s_lua = nullptr;
	}
}

PLUGIN_API void OnLoadPlugin(const char* Name)
{
	if (!Name)
		return;

	if (!_stricmp(Name, "MQ2Lua") || !_stricmp(Name, "Lua"))
	{
		s_lua = mq::lua::GetLuaInterface();
		if (s_lua)
		{
			if (!s_lua->RegisterLuaModule(kLuaModuleName, &RegisterLuaModule, mqplugin::ThisPluginHandle))
				WriteChatf("MQLuaModuleTest: Failed to register Lua module '%s'.", kLuaModuleName);
		}
	}
}

PLUGIN_API void OnUnloadPlugin(const char* Name)
{
	if (!Name)
		return;

	if (!_stricmp(Name, "MQ2Lua") || !_stricmp(Name, "Lua"))
	{
		s_lua = nullptr;
	}
}
