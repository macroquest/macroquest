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

static unsigned int CALLBACK LuaVarProcess(char* VarName, char* Value, size_t ValueLen)
{
	strcpy_s(Value, ValueLen, VarName);

	if (pLocalPlayer)
	{
		return static_cast<uint32_t>(strlen(ParseMacroParameter(Value, ValueLen)));
	}

	return static_cast<uint32_t>(strlen(Value));
}

//----------------------------------------------------------------------------

LuaEventProcessor::LuaEventProcessor(LuaThread* thread)
	: m_thread(thread)
	, m_blech(std::make_unique<Blech>('#', '|', LuaVarProcess))
	, m_blechStripped(std::make_unique<Blech>('#', '|', LuaVarProcess))
{
}

LuaEventProcessor::~LuaEventProcessor()
{
	m_eventDefinitions.clear();
}

bool LuaEventProcessor::AddEvent(std::string_view name, std::string_view expression, const sol::function& function,
	const sol::optional<sol::table>& options)
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

	m_eventDefinitions.push_back(std::make_unique<LuaEvent>(name, expression, function, options, this));
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

void LuaEventProcessor::Process(std::string_view line)
{
	if (!m_thread->IsValid())
		return;
	if (m_eventDefinitions.empty())
		return;
	if (line.size() >= MAX_STRING)
		return;

	char line_char[MAX_STRING] = { 0 };
	char line_char_stripped[MAX_STRING] = { 0 };

	m_currentLineStripped = nullptr;
	m_currentLine = nullptr;

	// Split event handling by whether we have links in the string or not. If there are no links in
	// the string then this is much simpler.
	if (line.find_first_of('\x12') == std::string::npos)
	{
		StripMQChat(line, line_char);

		m_currentLineStripped = line_char;
		m_currentLine = line_char;
	}
	else
	{
		// We have links in the string. Do the minimal amount of work required based on what kinds of
		// events have been registered.

		// Check if we need to keep both the stripped and unstripped links.
		if (!m_blech->IsEmpty() && !m_blechStripped->IsEmpty())
		{
			StripMQChat(line, line_char);
			m_currentLine = line_char;

			CXStr line_str(line);
			line_str = CleanItemTags(line_str, false);
			StripMQChat(line_str, line_char_stripped);
			m_currentLineStripped = line_char_stripped;
		}
		else if (!m_blech->IsEmpty())
		{
			StripMQChat(line, line_char);

			m_currentLine = line_char;
			m_currentLineStripped = line_char;
		}
		else if (!m_blechStripped->IsEmpty())
		{
			CXStr line_str(line);
			line_str = CleanItemTags(line_str, false);
			StripMQChat(line_str, line_char_stripped);

			m_currentLineStripped = line_char_stripped;
			m_currentLine = line_char_stripped;
		}
	}

	// since we initialized to 0, we know that any remaining members will be 0, so just in case we
	// get an overflow, re-set the last character to 0
	line_char[MAX_STRING - 1] = 0;
	line_char_stripped[MAX_STRING - 1] = 0;

	if (!m_blech->IsEmpty() && m_currentLine != nullptr)
	{
		m_blech->Feed(m_currentLine, MAX_STRING);
	}
	if (!m_blechStripped->IsEmpty() && m_currentLineStripped != nullptr)
	{
		m_blechStripped->Feed(m_currentLineStripped, MAX_STRING);
	}

	m_currentLineStripped = nullptr;
	m_currentLine = nullptr;
}

void LuaEventProcessor::HandleBlechEvent(LuaEvent* pEvent, BLECHVALUE* pValues)
{
	std::vector<std::pair<uint32_t, std::string>> args;

	const char* line = pEvent->KeepLinks() ? m_currentLine : m_currentLineStripped;
	args.emplace_back(0, line ? line : "");

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

void LuaEventProcessor::HandleBindCallback(LuaBind* bind, const char* args)
{
	std::vector<std::string_view> args_view = tokenize_args(args);
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
	const sol::function& func, const sol::optional<sol::table>& options,
	LuaEventProcessor* processor)
	: m_name(name)
	, m_expression(expression)
	, m_function(func)
	, m_processor(processor)
{
	if (options.has_value())
	{
		const sol::table& optionsTable = options.value();

		m_keepLinks = optionsTable.get_or("keepLinks", false);
	}

	m_blech = m_keepLinks ? &processor->GetBlech() : &processor->GetBlechStripped();
	m_id = m_blech->AddEvent(m_expression.c_str(), LuaEventCallback, this);
}

LuaEvent::~LuaEvent()
{
	m_blech->RemoveEvent(m_id);
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
	, coroutine(LuaCoroutine::Create(solThreadInfo.second, luaThread))
	, args(std::move(instance.args))
{
	coroutine->coroutine = sol::coroutine(solThreadInfo.second.state(), instance.definition->GetFunction());
}

template<> LuaEventFunction::LuaEventFunction(LuaEventInstance<LuaEvent>& instance)
	: luaThread(instance.definition->GetEventProcessor()->GetThread())
	, solThreadInfo(luaThread->CreateThread())
	, coroutine(LuaCoroutine::Create(solThreadInfo.second, luaThread))
	, args(std::move(instance.args))
{
	coroutine->coroutine = sol::coroutine(solThreadInfo.second.state(), instance.definition->GetFunction());
}

LuaEventFunction::~LuaEventFunction()
{
	luaThread->RemoveThread(solThreadInfo.first);
}

} // namespace mq::lua
