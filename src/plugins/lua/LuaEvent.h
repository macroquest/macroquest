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

#pragma once

#include "LuaCommon.h"

#include <queue>

class Blech;

namespace mq::lua::thread {
struct LuaThread;
struct ThreadState;
}

namespace mq::lua::events {

void register_lua(sol::table& lua);

struct LuaEventProcessor;
struct LuaEvent
{
	const std::string Name;
	const std::string Expression;
	const sol::function Function;
	LuaEventProcessor* Processor;
	uint32_t ID;

	LuaEvent(std::string_view name, std::string_view expression, const sol::function& function, LuaEventProcessor* processor);
	~LuaEvent();
};

struct LuaBind
{
	const std::string Name;
	const sol::function Function;
	uint8_t* Callback;
	LuaEventProcessor* Processor;

	LuaBind(const std::string& name, const sol::function& function, LuaEventProcessor* processor);
	~LuaBind();
};

template <typename T>
struct LuaEventInstance
{
	T* Definition;
	std::vector<std::string> Args;
	sol::thread Thread;
};

struct LuaEventProcessor
{
	const thread::LuaThread* Thread;

	std::unique_ptr<Blech> Trie;
	std::vector<std::unique_ptr<LuaEvent>> EventDefinitions;
	std::vector<LuaEventInstance<LuaEvent>> EventsPending;
	std::vector<std::pair<sol::coroutine, std::vector<std::string>>> EventsRunning;

	std::vector<std::unique_ptr<LuaBind>> BindDefinitions;
	std::vector<LuaEventInstance<LuaBind>> BindsPending;
	std::vector<std::pair<sol::coroutine, std::vector<std::string>>> BindsRunning;

	LuaEventProcessor(const thread::LuaThread* thread);
	~LuaEventProcessor();

	void add_event(std::string_view name, std::string_view expression, const sol::function& function);
	void remove_event(std::string_view name);

	void add_bind(std::string_view name, const sol::function& function);
	void remove_bind(std::string_view name);

	void process(std::string_view line) const;

	// this is guaranteed to always run at the exact same time, so we can run binds and events in it
	void run_events(const thread::LuaThread& thread);

	// we need two separate functions here because we need to be able to run these at separate points, independently
	void prepare_events();
	void prepare_binds();
};

} // namespace mq::lua::events
