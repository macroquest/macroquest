/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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

namespace mq::lua {

void Events_RegisterLua(sol::table& lua);

struct LuaThread;
struct LuaEventProcessor;
struct ThreadState;

struct LuaEvent
{
	const std::string name;
	const std::string expression;
	const sol::function function;
	LuaEventProcessor* processor;
	uint32_t id;

	LuaEvent(std::string_view name, std::string_view expression, const sol::function& function, LuaEventProcessor* processor);
	~LuaEvent();
};

struct LuaBind
{
	const std::string name;
	const sol::function function;
	LuaEventProcessor* processor;

	LuaBind(const std::string& name, const sol::function& function, LuaEventProcessor* processor);
	~LuaBind();

private:
	std::unique_ptr<uint8_t[]> callback;
};

template <typename T>
struct LuaEventInstance
{
	T* definition;
	std::vector<std::string> args;
	sol::thread thread;

	LuaEventInstance(T* definition, std::vector<std::string> args, sol::thread thread)
		: definition(definition)
		, args(std::move(args))
		, thread(std::move(thread))
	{}

	LuaEventInstance(T* definition, sol::thread thread)
		: definition(definition)
		, thread(std::move(thread))
	{}
};

struct LuaEventProcessor
{
	const LuaThread* thread;

	std::unique_ptr<Blech> blech;
	std::vector<std::unique_ptr<LuaEvent>> eventDefinitions;
	std::vector<LuaEventInstance<LuaEvent>> eventsPending;
	std::vector<std::pair<sol::coroutine, std::vector<std::string>>> eventsRunning;

	std::vector<std::unique_ptr<LuaBind>> bindDefinitions;
	std::vector<LuaEventInstance<LuaBind>> bindsPending;
	std::vector<std::pair<sol::coroutine, std::vector<std::string>>> bindsRunning;

	LuaEventProcessor(const LuaThread* thread);
	~LuaEventProcessor();

	void AddEvent(std::string_view name, std::string_view expression, const sol::function& function);
	void RemoveEvent(std::string_view name);

	void AddBind(std::string_view name, const sol::function& function);
	void RemoveBind(std::string_view name);

	void Process(std::string_view line) const;

	// this is guaranteed to always run at the exact same time, so we can run binds and events in it
	void RunEvents(const LuaThread& thread);

	// we need two separate functions here because we need to be able to run these at separate points, independently
	void PrepareEvents(const std::vector<std::string>& events);
	void RemoveEvents(const std::vector<std::string>& events);
	void PrepareBinds();
};

} // namespace mq::lua
