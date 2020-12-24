#pragma once

#include "LuaCommon.h"

namespace mq::lua::thread {
struct LuaThread;
}

namespace mq::lua::imgui {
void register_lua(sol::state& lua);

struct LuaImGui
{
	std::string Name;
	sol::function Callback;

	LuaImGui(std::string_view name, const sol::function& callback);
	~LuaImGui();

	void pulse() const;
};

struct LuaImGuiProcessor
{
	const thread::LuaThread* Thread;
	std::vector<std::unique_ptr<LuaImGui>> ImGuis;

	LuaImGuiProcessor(const thread::LuaThread* thread);
	~LuaImGuiProcessor();

	void add_callback(std::string_view name, sol::function callback);
	void remove_callback(std::string_view name);
	void pulse() const;
};
}
