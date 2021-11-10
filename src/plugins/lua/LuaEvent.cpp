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

#include "pch.h"
#include "LuaEvent.h"
#include "LuaThread.h"

#include <mq/Plugin.h>

namespace mq::lua {

//============================================================================

unsigned int CALLBACK LuaVarProcess(char* VarName, char* Value, size_t ValueLen)
{
	// TODO: do we need to evaluate lua code in `Value` here? it should come to us as a string, not sure how to detect string vs lua code similar to the delay condition code
	strcpy_s(Value, ValueLen, VarName);
	return strlen(Value);
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

void LuaEventProcessor::AddEvent(std::string_view name, std::string_view expression, const sol::function& function)
{
	m_eventDefinitions.push_back(std::make_unique<LuaEvent>(name, expression, function, this, *m_blech));
}

void LuaEventProcessor::RemoveEvent(std::string_view name)
{
	RemoveEvents({ std::string(name) });
	auto it = std::find_if(m_eventDefinitions.begin(), m_eventDefinitions.end(),
		[&name](const std::unique_ptr<LuaEvent>& event) { return event->GetName() == name; });
	if (it != m_eventDefinitions.end())
	{
		m_eventDefinitions.erase(it);
	}
}

void LuaEventProcessor::AddBind(std::string_view name, const sol::function& function)
{
	std::string bind_name(name);
	if (IsCommand(bind_name.c_str()))
	{
		LuaError("Cannot bind %s, already bound in MQ.", bind_name.c_str());
	}
	else if (bind_name.empty() || bind_name[0] != '/')
	{
		LuaError("Cannot bind %s, not a valid command string.", bind_name.c_str());
	}
	else
	{
		m_bindDefinitions.push_back(std::make_unique<LuaBind>(bind_name, function, this));
	}
}

void LuaEventProcessor::RemoveBind(std::string_view name)
{
	RemoveBinds({ std::string(name) });
	auto it = std::find_if(m_bindDefinitions.begin(), m_bindDefinitions.end(),
		[&name](const std::unique_ptr<LuaBind>& bind)
		{
			return bind->GetName() == name;
		});

	if (it != m_bindDefinitions.end())
		m_bindDefinitions.erase(it);
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
		strcpy_s(line_char, line_str.c_str());
	}
	else
	{
		strncpy_s(line_char, line.data(), line.size());
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

		auto result = RunCoroutine(co->coroutine, co->args);

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
static void emplace_running(std::vector<std::shared_ptr<LuaEventFunction>>& running_vec, LuaEventInstance<R>& to_run)
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

// TODO: make this work (tokenize args into vector, queue the bind in an instance, etc)
static void BindHelper(LuaBind* bind, const char* args)
{
	bind->GetEventProcessor()->HandleBindCallback(bind, args);
}

// 55 8b ec ff 75 0c 68 00 00 00 00 e8 00 00 00 00 c9 c3
constexpr int s_callbackBufferSize = 18;

LuaBind::LuaBind(const std::string& name, const sol::function& func, LuaEventProcessor* processor)
	: m_name(name)
	, m_function(func)
	, m_callback(new uint8_t[s_callbackBufferSize])
	, m_processor(processor)
{
	// TODO: gut all this when core commands are fixed to allow generic callbacks

	static constexpr uint8_t callback_template[] =
	{
		0x55,                         // push ebp
		0x8b, 0xec,                   // mov ebp, esp
		0xff, 0x75, 0x0c,             // push dword ptr [ebp + 0xc] ; push Buffer
		0x68, 0x00, 0x00, 0x00, 0x00, // push LuaBind
		0xe8, 0x00, 0x00, 0x00, 0x00, // Call BindHelper
		0xc9,                         // leave
		0xc3                          // return
	};
	static_assert(lengthof(callback_template) == s_callbackBufferSize,
	              "Size of callback_template mismatch");

	memcpy(m_callback.get(), callback_template, s_callbackBufferSize);

	*(reinterpret_cast<uint32_t*>(m_callback.get() + 7)) = reinterpret_cast<uint32_t>(this);
	int diff = reinterpret_cast<int>(&BindHelper) - reinterpret_cast<int>(m_callback.get() + 16);
	*(reinterpret_cast<int*>(m_callback.get() + 12)) = diff;
	DWORD old_protect;
	VirtualProtectEx(GetCurrentProcess(), reinterpret_cast<LPVOID>(m_callback.get()), 18, PAGE_EXECUTE_READWRITE, &old_protect);

	AddCommand(m_name.c_str(), reinterpret_cast<fEQCommand>(m_callback.get()));
}

LuaBind::~LuaBind()
{
	RemoveCommand(m_name.c_str());
}

//----------------------------------------------------------------------------

static void lua_doevents(sol::variadic_args va, sol::this_state s)
{
	if (auto thread_ptr = LuaThread::get_from(s))
	{
		if (LuaEventProcessor* events = thread_ptr->GetEventProcessor())
		{
			std::vector<std::string> args;
			for (auto& a : va)
			{
				auto arg = a.as<std::optional<std::string>>();
				if (arg) args.emplace_back(*arg);
			}

			events->PrepareEvents(args);
			thread_ptr->DoYield(); // doevents needs to yield, event processing will pick up next frame
		}
	}
}

static void lua_flushevents(sol::variadic_args va, sol::this_state s)
{
	if (auto thread_ptr = LuaThread::get_from(s))
	{
		if (LuaEventProcessor* events = thread_ptr->GetEventProcessor())
		{
			std::vector<std::string> args;
			for (auto& a : va)
			{
				auto arg = a.as<std::optional<std::string>>();
				if (arg) args.emplace_back(*arg);
			}

			events->RemoveEvents(args);
		}
	}
}

static void lua_addevent(std::string_view name, std::string_view expression, sol::function function, sol::this_state s)
{
	if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
	{
		if (LuaEventProcessor* events = thread_ptr->GetEventProcessor())
			events->AddEvent(name, expression, function);
	}
}

static void lua_removeevent(std::string_view name, sol::this_state s)
{
	if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
	{
		if (LuaEventProcessor* events = thread_ptr->GetEventProcessor())
			events->RemoveEvent(name);
	}
}

static void lua_addbind(std::string_view name, sol::function function, sol::this_state s)
{
	if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
	{
		if (LuaEventProcessor* events = thread_ptr->GetEventProcessor())
			events->AddBind(name, function);
	}
}

static void lua_removebind(std::string_view name, sol::this_state s)
{
	if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
	{
		if (LuaEventProcessor* events = thread_ptr->GetEventProcessor())
			events->RemoveBind(name);
	}
}

void MQ_RegisterLua_Events(sol::table& mq)
{
	mq.set_function("doevents",                  &lua_doevents);
	mq.set_function("flushevents",               &lua_flushevents);
	mq.set_function("event",                     &lua_addevent);
	mq.set_function("unevent",                   &lua_removeevent);
	mq.set_function("bind",                      &lua_addbind);
	mq.set_function("unbind",                    &lua_removebind);
}

LuaEventFunction::~LuaEventFunction()
{
	luaThread->RemoveThread(solThreadInfo.first);
}

} // namespace mq::lua
