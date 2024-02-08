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

#include "pch.h"
#include "LuaEvent.h"
#include "LuaThread.h"
#include "LuaCoroutine.h"

#include <mq/Plugin.h>

namespace mq::lua {

//============================================================================

unsigned int CALLBACK LuaVarProcess(char* VarName, char* Value, size_t ValueLen)
{
	// TODO: do we need to evaluate lua code in `Value` here? it should come to us as a string, not sure how to detect string vs lua code similar to the delay condition code
	strcpy_s(Value, ValueLen, VarName);
	return static_cast<int>(strlen(Value));
}

//----------------------------------------------------------------------------

LuaEventProcessor::LuaEventProcessor(LuaThread* thread)
	: m_thread(thread)
	, m_blech(std::make_unique<Blech>('#', '|', LuaVarProcess))
{
}

LuaEventProcessor::~LuaEventProcessor()
{
	m_eventDefinitions.clear();
}

bool LuaEventProcessor::AddEvent(std::string_view name, std::string_view expression, const sol::function& function)
{
	// the number of events will always be fairly small, and this is a manual operation.
	// If this is deemed too slow, the event names can be memoized in a set of string_views.
	auto it = std::find_if(m_eventDefinitions.begin(), m_eventDefinitions.end(),
		[&name](const std::unique_ptr<LuaEvent>& event) { return event->GetName() == name; });

	if (it != m_eventDefinitions.end())
	{
		LuaError("Cannot create event %.*s, it is already defined.", name.length(), name.data());
		return false;
	}

	m_eventDefinitions.push_back(std::make_unique<LuaEvent>(name, expression, function, this, *m_blech));
	return true;
}

bool LuaEventProcessor::RemoveEvent(std::string_view name)
{
	RemoveEvents({ std::string(name) });
	auto it = std::find_if(m_eventDefinitions.begin(), m_eventDefinitions.end(),
		[&name](const std::unique_ptr<LuaEvent>& event) { return event->GetName() == name; });
	if (it != m_eventDefinitions.end())
	{
		m_eventDefinitions.erase(it);
		return true;
	}

	return false;
}

bool LuaEventProcessor::AddBind(std::string_view name, const sol::function& function)
{
	std::string bind_name(name);
	if (IsCommand(bind_name.c_str()))
	{
		LuaError("Cannot bind %s, already bound in MQ.", bind_name.c_str());
		return false;
	}
	else if (bind_name.empty() || bind_name[0] != '/')
	{
		LuaError("Cannot bind %s, not a valid command string.", bind_name.c_str());
		return false;
	}

	m_bindDefinitions.push_back(std::make_unique<LuaBind>(bind_name, function, this));
	return true;
}

bool LuaEventProcessor::RemoveBind(std::string_view name)
{
	RemoveBinds({ std::string(name) });
	auto it = std::find_if(m_bindDefinitions.begin(), m_bindDefinitions.end(),
		[&name](const std::unique_ptr<LuaBind>& bind)
		{
			return bind->GetName() == name;
		});

	if (it != m_bindDefinitions.end())
	{
		m_bindDefinitions.erase(it);
		return true;
	}

	return false;
}

void LuaEventProcessor::Process(std::string_view line) const
{
	if (!m_thread->IsValid())
		return;
	if (m_eventDefinitions.empty())
		return;
	if (line.size() >= MAX_STRING)
		return;

	char line_char[MAX_STRING] = { 0 };

	if (line.find_first_of('\x12') != std::string::npos)
	{
		CXStr line_str(line);
		line_str = CleanItemTags(line_str, false);
		StripMQChat(line_str, line_char);
	}
	else
	{
		StripMQChat(line, line_char);
	}

	// since we initialized to 0, we know that any remaining members will be 0, so just in case we Get an overflow, re-set the last character to 0
	line_char[MAX_STRING - 1] = 0;

	sol::state_view state = m_thread->GetState();

	state["_mq_event_line"] = line_char;
	m_blech->Feed(line_char);
	state["_mq_event_line"] = sol::lua_nil;
}

static void loop_and_run(LuaThread& thread, std::vector<std::shared_ptr<LuaEventFunction>>& vec)
{
	vec.erase(std::remove_if(vec.begin(), vec.end(),
		[&thread](std::shared_ptr<LuaEventFunction> co) -> bool
	{
		// return false for everything else because we need to yield to the frame
		if (thread.ShouldYield()) return false;

		// in case we have a nullptr (how?)
		if (!co) return true;

		// check if we are paused or if this thread is delayed
		if (!co->coroutine->ShouldRun()) return false;

		auto result = co->coroutine->RunCoroutine(co->args);

		// a bit of mutation here, but we can only submit a non-empty args the first time
		if (!co->args.empty()) co->args.clear();

		// now just erase events that finished
		return !result || result->status() != sol::call_status::yielded;
	}), vec.end());
}

void LuaEventProcessor::RunEvents(LuaThread& thread)
{
	loop_and_run(thread, m_bindsRunning);
	if (!thread.ShouldYield()) loop_and_run(thread, m_eventsRunning);
}

template <typename R>
static void emplace_running(
	std::vector<std::shared_ptr<LuaEventFunction>>& running_vec,
	LuaEventInstance<R>& to_run)
{
	running_vec.emplace_back(std::make_shared<LuaEventFunction>(to_run));
}

void LuaEventProcessor::PrepareEvents(const std::vector<std::string>& events)
{
	if (events.empty())
	{
		for (LuaEventInstance<LuaEvent>& ev : m_eventsPending)
		{
			emplace_running(m_eventsRunning, ev);
		}

		m_eventsPending.clear();
	}
	else
	{
		m_eventsPending.erase(std::remove_if(m_eventsPending.begin(), m_eventsPending.end(),
			[this, &events](LuaEventInstance<LuaEvent>& ev)
		{
			if (std::find(events.cbegin(), events.cend(), ev.definition->GetName()) != events.cend())
			{
				emplace_running(m_eventsRunning, ev);
				return true;
			}

			return false;
		}), m_eventsPending.end());
	}
}

void LuaEventProcessor::RemoveEvents(const std::vector<std::string>& events)
{
	if (events.empty())
		m_eventsPending.clear();
	else
	{
		m_eventsPending.erase(std::remove_if(m_eventsPending.begin(), m_eventsPending.end(),
			[this, &events](LuaEventInstance<LuaEvent>& ev)
		{
			return std::find(events.cbegin(), events.cend(), ev.definition->GetName()) != events.cend();
		}), m_eventsPending.end());
	}
}

void LuaEventProcessor::PrepareBinds()
{
	for (auto& b : m_bindsPending)
	{
		emplace_running(m_bindsRunning, b);
	}

	m_bindsPending.clear();
}

void LuaEventProcessor::RemoveBinds(const std::vector<std::string>& binds)
{
	if (binds.empty())
		m_bindsPending.clear();
	else
	{
		m_bindsPending.erase(std::remove_if(m_bindsPending.begin(), m_bindsPending.end(),
			[this, &binds](LuaEventInstance<LuaBind>& b)
		{
			return std::find(binds.cbegin(), binds.cend(), b.definition->GetName()) != binds.cend();
		}), m_bindsPending.end());
	}
}

void LuaEventProcessor::HandleBlechEvent(LuaEvent* pEvent, BLECHVALUE* pValues)
{
	std::vector<std::pair<uint32_t, std::string>> args;

	std::optional<std::string> line = m_thread->GetState()["_mq_event_line"];
	args.emplace_back(0, line.value_or(""));

	auto value = pValues;
	while (value != nullptr)
	{
		auto num = GetIntFromString(value->Name, 0);
		if (num > 0) // this will skip any '*' instances for me -- it will in fact only Get valid argument positions
			args.emplace_back(num, value->Value);
		value = value->pNext;
	}

	if (args.empty())
	{
		m_eventsPending.emplace_back(pEvent);
	}
	else
	{
		std::sort(args.begin(), args.end(), [](const auto& a, const auto& b) { return a.first < b.first; });

		std::vector<std::string> ordered_args(args.back().first + 1, "");
		for (const auto& a : args)
			ordered_args[a.first] = a.second;

		m_eventsPending.emplace_back(pEvent, std::move(ordered_args));
	}
}

void LuaEventProcessor::HandleBindCallback(LuaBind* bind, const char* args)
{
	auto& args_view = tokenize_args(args);
	if (args_view.empty())
	{
		m_bindsPending.emplace_back(bind);
	}
	else
	{
		std::vector<std::string> args_vector(args_view.begin(), args_view.end());
		m_bindsPending.emplace_back(bind, std::move(args_vector));
	}
}

//============================================================================

void CALLBACK LuaEventCallback(unsigned int ID, void* pData, BLECHVALUE* pValues)
{
	if (pData == nullptr)
		return;

	auto def = static_cast<LuaEvent*>(pData);

	def->GetEventProcessor()->HandleBlechEvent(def, pValues);
}

LuaEvent::LuaEvent(std::string_view name, std::string_view expression,
	const sol::function& func, LuaEventProcessor* processor, Blech& blech)
	: m_name(name)
	, m_expression(expression)
	, m_function(func)
	, m_processor(processor)
	, m_blech(blech)
{
	m_id = m_blech.AddEvent(m_expression.c_str(), LuaEventCallback, this);
}

LuaEvent::~LuaEvent()
{
	m_blech.RemoveEvent(m_id);
}

//============================================================================

LuaBind::LuaBind(const std::string& name, const sol::function& func, LuaEventProcessor* processor)
	: m_name(name)
	, m_function(func)
	, m_processor(processor)
{
	AddCommand(m_name.c_str(), [this](PlayerClient*, const char* args) -> void
	{
		this->GetEventProcessor()->HandleBindCallback(this, args);
	});
}

LuaBind::~LuaBind()
{
	RemoveCommand(m_name.c_str());
}

//----------------------------------------------------------------------------

template<> LuaEventFunction::LuaEventFunction(LuaEventInstance<LuaBind>& instance)
	: luaThread(instance.definition->GetEventProcessor()->GetThread())
	, solThreadInfo(luaThread->CreateThread())
	, args(std::move(instance.args))
	, coroutine(LuaCoroutine::Create(solThreadInfo.second, luaThread))
{
	coroutine->coroutine = sol::coroutine(solThreadInfo.second.state(), instance.definition->GetFunction());
}

template<> LuaEventFunction::LuaEventFunction(LuaEventInstance<LuaEvent>& instance)
	: luaThread(instance.definition->GetEventProcessor()->GetThread())
	, solThreadInfo(luaThread->CreateThread())
	, args(std::move(instance.args))
	, coroutine(LuaCoroutine::Create(solThreadInfo.second, luaThread))
{
	coroutine->coroutine = sol::coroutine(solThreadInfo.second.state(), instance.definition->GetFunction());
}

LuaEventFunction::~LuaEventFunction()
{
	luaThread->RemoveThread(solThreadInfo.first);
}

} // namespace mq::lua
