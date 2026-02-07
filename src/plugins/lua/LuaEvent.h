/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
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

class Blech;
struct BLECHVALUE;

namespace mq::lua {

class LuaThread;
class LuaEventProcessor;
struct LuaCoroutine;

//============================================================================

class LuaEvent
{
public:
	LuaEvent(std::string_view name,
		std::string_view expression,
		const sol::function& func,
		const sol::optional<sol::table>& options,
		LuaEventProcessor* processor);
	~LuaEvent();

	LuaEventProcessor* GetEventProcessor() { return m_processor; }

	std::string_view GetName() const { return m_name; }
	const sol::function GetFunction() const { return m_function; }

	bool KeepLinks() const { return m_keepLinks; }

private:
	const std::string m_name;
	const std::string m_expression;
	const sol::function m_function;
	LuaEventProcessor* m_processor;
	Blech* m_blech = nullptr;
	uint32_t m_id;
	bool m_keepLinks = false;
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
};

//----------------------------------------------------------------------------

template <typename T>
struct LuaEventInstance
{
	T* definition;
	std::vector<std::string> args;

	LuaEventInstance(T* definition, std::vector<std::string> args)
		: definition(definition)
		, args(std::move(args))
	{}

	LuaEventInstance(T* definition)
		: definition(definition)
	{}
};

//----------------------------------------------------------------------------

struct LuaEventFunction
{
	std::string name;
	LuaThread* luaThread;

	std::pair<uint32_t, sol::thread> solThreadInfo;
	std::shared_ptr<LuaCoroutine> coroutine;
	std::vector<std::string> args;

	template<typename T>
	LuaEventFunction(LuaEventInstance<T>& instance);
	~LuaEventFunction();
};

//----------------------------------------------------------------------------

class LuaEventProcessor
{
public:
	LuaEventProcessor(LuaThread* thread);
	~LuaEventProcessor();

	bool AddEvent(std::string_view name, std::string_view expression, const sol::function& function,
		const sol::optional<sol::table>& options);
	bool RemoveEvent(std::string_view name);

	bool AddBind(std::string_view name, const sol::function& function);
	bool RemoveBind(std::string_view name);

	void Process(std::string_view line);

	// this is guaranteed to always run at the exact same time, so we can run binds and events in it
	void RunEvents(LuaThread& thread);

	// we need two separate functions here because we need to be able to run these at separate points, independently
	void PrepareEvents(std::vector<std::string> events);
	void RemoveEvents(const std::vector<std::string>& events);
	void PrepareBinds();
	void RemoveBinds(const std::vector<std::string>& binds);

	LuaThread* GetThread() const { return m_thread; }

	void HandleBlechEvent(LuaEvent* event, BLECHVALUE* pValues);
	void HandleBindCallback(LuaBind* bind, const char* args);

	Blech& GetBlech() { return *m_blech; }
	Blech& GetBlechStripped() { return *m_blechStripped; }

private:
	LuaThread* m_thread;
	std::unique_ptr<Blech> m_blech;
	std::unique_ptr<Blech> m_blechStripped;
	const char* m_currentLineStripped = nullptr;
	const char* m_currentLine = nullptr;

	// Events
	std::vector<std::unique_ptr<LuaEvent>> m_eventDefinitions;
	std::vector<LuaEventInstance<LuaEvent>> m_eventsPending;
	std::vector<std::shared_ptr<LuaEventFunction>> m_eventsRunning;
	bool m_processingEvents = false;
	std::vector<std::string> m_deferredDoEvents;

	// Binds
	std::vector<std::unique_ptr<LuaBind>> m_bindDefinitions;
	std::vector<LuaEventInstance<LuaBind>> m_bindsPending;
	std::vector<std::shared_ptr<LuaEventFunction>> m_bindsRunning;
	bool m_processingBinds = false;
};

} // namespace mq::lua
