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

unsigned int CALLBACK LuaVarProcess(char* VarName, char* Value, size_t ValueLen)
{
	// TODO: do we need to evaluate lua code in `Value` here? it should come to us as a string, not sure how to detect string vs lua code similar to the delay condition code
	strcpy_s(Value, ValueLen, VarName);
	return strlen(Value);
}

void CALLBACK LuaEventCallback(unsigned int ID, void* pData, PBLECHVALUE pValues)
{
	if (pData == nullptr)
		return;

	auto def = static_cast<LuaEvent*>(pData);
	auto thread = def->processor->thread;
	auto event_thread = sol::thread::create(thread->thread.state());

	std::vector<std::pair<uint32_t, std::string>> args;

	std::optional<std::string> line = thread->thread.state()["_mq_event_line"];
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
		def->processor->eventsPending.emplace_back(def, std::move(event_thread));
	}
	else
	{
		std::sort(args.begin(), args.end(), [](const auto& a, const auto& b) { return a.first < b.first; });

		std::vector<std::string> ordered_args(args.back().first + 1, "");
		for (const auto& a : args)
			ordered_args[a.first] = a.second;

		def->processor->eventsPending.emplace_back(def, std::move(ordered_args), std::move(event_thread));
	}
}

LuaEventProcessor::LuaEventProcessor(const LuaThread* thread)
	: thread(thread)
	, blech(std::make_unique<Blech>('#', '|', LuaVarProcess))
{
}

LuaEventProcessor::~LuaEventProcessor()
{
	eventDefinitions.clear();
}

void LuaEventProcessor::AddEvent(std::string_view name, std::string_view expression, const sol::function& function)
{
	eventDefinitions.push_back(std::make_unique<LuaEvent>(name, expression, function, this));
}

void LuaEventProcessor::RemoveEvent(std::string_view name)
{
	auto it = std::find_if(eventDefinitions.begin(), eventDefinitions.end(),
		[&name](const std::unique_ptr<LuaEvent>& e) { return e->name == name; });
	if (it != eventDefinitions.end())
	{
		eventDefinitions.erase(it);
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
		bindDefinitions.push_back(std::make_unique<LuaBind>(bind_name, function, this));
	}
}

void LuaEventProcessor::RemoveBind(std::string_view name)
{
	auto it = std::find_if(bindDefinitions.begin(), bindDefinitions.end(),
		[&name](const std::unique_ptr<LuaBind>& bind)
		{
			return bind->name == name;
		});

	if (it != bindDefinitions.end())
		bindDefinitions.erase(it);
}

void LuaEventProcessor::Process(std::string_view line) const
{
	if (!thread->thread.valid())
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

	auto& state = thread->thread.state();

	state["_mq_event_line"] = line_char;
	blech->Feed(line_char);
	state["_mq_event_line"] = sol::lua_nil;
}

static void loop_and_run(const LuaThread& thread,
	std::vector<std::pair<sol::coroutine, std::vector<std::string>>>& vec)
{
	vec.erase(std::remove_if(vec.begin(), vec.end(), [&thread](auto& co) -> bool
		{
			if (thread.yieldToFrame) return false; // return false for everything else because we need to yield to the frame

			auto result = RunCoroutine(co.first, co.second);
			if (!co.second.empty()) co.second.clear(); // a bit of mutation here, but we can only submit a non-empty args the first time

			return !result || result->status() != sol::call_status::yielded; // now just erase events that finished
		}), vec.end());
}

void LuaEventProcessor::RunEvents(const LuaThread& thread)
{
	loop_and_run(thread, bindsRunning);
	if (!thread.yieldToFrame) loop_and_run(thread, eventsRunning);
}

void LuaEventProcessor::PrepareEvents()
{
	for (auto& e : eventsPending)
	{
		eventsRunning.emplace_back(
			std::piecewise_construct,
			std::forward_as_tuple(e.thread.state(), std::move(e.definition->function)),
			std::forward_as_tuple(std::move(e.args)));
	}

	eventsPending.clear();
}

void LuaEventProcessor::PrepareBinds()
{
	for (auto& b : bindsPending)
	{
		bindsRunning.emplace_back(
			std::piecewise_construct,
			std::forward_as_tuple(b.thread.state(), std::move(b.definition->function)),
			std::forward_as_tuple(std::move(b.args)));
	}

	bindsPending.clear();
}

LuaEvent::LuaEvent(std::string_view name, std::string_view expression,
	const sol::function& function, LuaEventProcessor* processor)
	: name(name)
	, expression(expression)
	, function(function)
	, processor(processor)
{
	id = processor->blech->AddEvent(this->expression.c_str(), LuaEventCallback, this);
}

LuaEvent::~LuaEvent()
{
	processor->blech->RemoveEvent(id);
}

//----------------------------------------------------------------------------

// TODO: make this work (tokenize args into vector, queue the bind in an instance, etc)
static void BindHelper(LuaBind* bind, const char* args)
{
	auto thread = bind->processor->thread;
	auto bind_thread = sol::thread::create(thread->thread.state());

	auto& args_view = tokenize_args(args);
	if (args_view.empty())
	{
		bind->processor->bindsPending.emplace_back(bind, std::move(bind_thread));
	}
	else
	{
		std::vector<std::string> args_vector(args_view.begin(), args_view.end());
		bind->processor->bindsPending.emplace_back(bind, std::move(args_vector), std::move(bind_thread));
	}
}

// 55 8b ec ff 75 0c 68 00 00 00 00 e8 00 00 00 00 c9 c3
constexpr int s_callbackBufferSize = 18;

LuaBind::LuaBind(const std::string& name, const sol::function& function, LuaEventProcessor* processor)
	: name(name)
	, function(function)
	, callback(new uint8_t[s_callbackBufferSize])
	, processor(processor)
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

	memcpy(callback.get(), callback_template, s_callbackBufferSize);

	*(reinterpret_cast<uint32_t*>(callback.get() + 7)) = reinterpret_cast<uint32_t>(this);
	int diff = reinterpret_cast<int>(&BindHelper) - reinterpret_cast<int>(callback.get() + 16);
	*(reinterpret_cast<int*>(callback.get() + 12)) = diff;
	DWORD old_protect;
	VirtualProtectEx(GetCurrentProcess(), reinterpret_cast<LPVOID>(callback.get()), 18, PAGE_EXECUTE_READWRITE, &old_protect);

	AddCommand(name.c_str(), reinterpret_cast<fEQCommand>(callback.get()));//, false, true, true);
}

LuaBind::~LuaBind()
{
	RemoveCommand(name.c_str());
}

//----------------------------------------------------------------------------

static void doevents(sol::this_state s)
{
	if (auto thread_ptr = LuaThread::get_from(s))
	{
		thread_ptr->eventProcessor->PrepareEvents();
		thread_ptr->YieldAt(0); // doevents needs to yield, event processing will pick up next frame
	}
}

static void addevent(std::string_view name, std::string_view expression, sol::function function, sol::this_state s)
{
	if (auto thread_ptr = LuaThread::get_from(s))
	{
		thread_ptr->eventProcessor->AddEvent(name, expression, function);
	}
}

static void removeevent(std::string_view name, sol::this_state s)
{
	if (auto thread_ptr = LuaThread::get_from(s))
	{
		thread_ptr->eventProcessor->RemoveEvent(name);
	}
}

static void addbind(std::string_view name, sol::function function, sol::this_state s)
{
	if (auto thread_ptr = LuaThread::get_from(s))
	{
		thread_ptr->eventProcessor->AddBind(name, function);
	}
}

static void removebind(std::string_view name, sol::this_state s)
{
	if (auto thread_ptr = LuaThread::get_from(s))
	{
		thread_ptr->eventProcessor->RemoveBind(name);
	}
}

void Events_RegisterLua(sol::table& lua)
{
	lua["doevents"] = &doevents;
	lua["event"] = &addevent;
	lua["unevent"] = &removeevent;
	lua["bind"] = &addbind;
	lua["unbind"] = &removebind;
}

} // namespace mq::lua
