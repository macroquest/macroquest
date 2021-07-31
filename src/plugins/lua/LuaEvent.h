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
struct BLECHVALUE;

namespace mq::lua {

void MQ_RegisterLua_Events(sol::table& lua);

class LuaThread;
class LuaEventProcessor;

//============================================================================

class LuaEvent
{
public:
	LuaEvent(std::string_view name,
		std::string_view expression,
		const sol::function& func,
		LuaEventProcessor* processor,
		Blech& blech);
	~LuaEvent();

	LuaEventProcessor* GetEventProcessor() { return m_processor; }

	std::string_view GetName() const { return m_name; }
	const sol::function GetFunction() const { return m_function; }

private:
	const std::string m_name;
	const std::string m_expression;
	const sol::function m_function;
	LuaEventProcessor* m_processor;
	Blech& m_blech;
	uint32_t m_id;
};

//----------------------------------------------------------------------------

class LuaBind
{
public:
	LuaBind(const std::string& name, const sol::function& func, LuaEventProcessor* processor);
	~LuaBind();

	LuaEventProcessor* GetEventProcessor() { return m_processor; }

	std::string_view GetName() const { return m_name; }
	const sol::function GetFunction() const { return m_function; }

private:
	const std::string m_name;
	const sol::function m_function;
	LuaEventProcessor* m_processor;
	std::unique_ptr<uint8_t[]> m_callback;
};

//----------------------------------------------------------------------------

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

//----------------------------------------------------------------------------

class LuaEventProcessor
{
public:
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

	const LuaThread* GetThread() const { return m_thread; }

	void HandleBlechEvent(LuaEvent* event, BLECHVALUE* pValues);
	void HandleBindCallback(LuaBind* bind, const char* args);

private:
	const LuaThread* m_thread;
	std::unique_ptr<Blech> m_blech;

	// Events
	std::vector<std::unique_ptr<LuaEvent>> m_eventDefinitions;
	std::vector<LuaEventInstance<LuaEvent>> m_eventsPending;
	std::vector<std::pair<sol::coroutine, std::vector<std::string>>> m_eventsRunning;

	// Binds
	std::vector<std::unique_ptr<LuaBind>> m_bindDefinitions;
	std::vector<LuaEventInstance<LuaBind>> m_bindsPending;
	std::vector<std::pair<sol::coroutine, std::vector<std::string>>> m_bindsRunning;
};

} // namespace mq::lua
