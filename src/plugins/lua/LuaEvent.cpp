#include "LuaEvent.h"
#include "LuaThread.h"

#include <mq/Plugin.h>

namespace mq::lua::events {
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
	if (def->Thread.expired()) // this should never actually happen
		return;

	auto thread = def->Thread.lock();
	auto event_thread = sol::thread::create(thread->Thread.state());

	std::vector<std::pair<uint32_t, std::string>> args;
	auto value = pValues;
	while (value != nullptr)
	{
		auto num = GetIntFromString(value->Name, 0);
		if (num > 0) // this will skip any '*' instances for me -- it will in fact only get valid argument positions
			args.emplace_back(num, value->Value);
		value = value->pNext;
	}

	if (args.empty())
	{
		thread->EventProcessor->Pending.emplace_back(LuaEventInstance{ def, {}, std::move(event_thread) });
	}
	else
	{
		std::sort(args.begin(), args.end(), [](const auto& a, const auto& b) { return a.first < b.first; });

		std::vector<std::string> ordered_args(args.back().first, "");
		for (const auto& a : args)
			ordered_args[a.first - 1] = a.second;

		thread->EventProcessor->Pending.emplace_back(LuaEventInstance{ def, ordered_args, std::move(event_thread) });
	}
}

LuaEventProcessor::LuaEventProcessor() :
	Trie(std::make_unique<Blech>('#', '|', LuaVarProcess)) {}

LuaEventProcessor::~LuaEventProcessor()
{
	for (auto e : Definitions)
		delete e;

	Definitions.clear();
}

void LuaEventProcessor::add_event(std::string_view name, std::string_view expression, const sol::function& function, const std::shared_ptr<thread::LuaThread>& thread)
{
	LuaEvent* e = new LuaEvent{std::string(name), std::string(expression), function, thread, 0};
	Definitions.emplace_back(e);
	e->ID = Trie->AddEvent(e->Expression.c_str(), LuaEventCallback, e);
}

void LuaEventProcessor::remove_event(std::string_view name)
{
	auto it = std::find_if(Definitions.begin(), Definitions.end(), [&name](LuaEvent* e) { return e->Name == name; });
	if (it != Definitions.end())
	{
		Trie->RemoveEvent((*it)->ID);
		Definitions.erase(it);
		delete *it;
	}
}

void LuaEventProcessor::process(std::string_view line) const
{
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
		// since we initialized to 0, we know that any remaining members will be 0, so just in case we get an overflow, re-set the last character to 0
		line_char[MAX_STRING - 1] = 0;
	}

	Trie->Feed(line_char);
}

void LuaEventProcessor::run_events(const thread::LuaThread& thread)
{
	Running.erase(std::remove_if(Running.begin(), Running.end(), [&thread](auto& co) -> bool
		{
			if (thread.YieldToFrame) return false; // return false for everything else because we need to yield to the frame

			auto result = thread::run_co(co.first, co.second);
			if (!co.second.empty())
				co.second.clear();
			return result != sol::thread_status::yielded; // now just erase events that finished
		}
	), Running.end());
}

void LuaEventProcessor::prepare_events()
{
	for (const auto& e : Pending)
		Running.emplace_back(sol::coroutine(e.Thread.state(), e.Definition->Function), e.Args);

	Pending.clear();
}
}