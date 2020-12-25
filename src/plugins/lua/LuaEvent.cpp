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
	auto thread = def->Processor->Thread;
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
		def->Processor->EventsPending.emplace_back(LuaEventInstance<LuaEvent>{ def, {}, std::move(event_thread) });
	}
	else
	{
		std::sort(args.begin(), args.end(), [](const auto& a, const auto& b) { return a.first < b.first; });

		std::vector<std::string> ordered_args(args.back().first, "");
		for (const auto& a : args)
			ordered_args[a.first - 1] = a.second;

		def->Processor->EventsPending.emplace_back(LuaEventInstance<LuaEvent>{ def, ordered_args, std::move(event_thread) });
	}
}

LuaEventProcessor::LuaEventProcessor(const thread::LuaThread* thread) :
	Thread(thread),
	Trie(std::make_unique<Blech>('#', '|', LuaVarProcess)) {}

LuaEventProcessor::~LuaEventProcessor()
{
	EventDefinitions.clear();
}

void LuaEventProcessor::add_event(std::string_view name, std::string_view expression, const sol::function& function)
{
	EventDefinitions.emplace_back(std::make_unique<LuaEvent>(name, expression, function, this));
}

void LuaEventProcessor::remove_event(std::string_view name)
{
	auto it = std::find_if(EventDefinitions.begin(), EventDefinitions.end(),
		[&name](const std::unique_ptr<LuaEvent>& e) { return e->Name == name; });
	if (it != EventDefinitions.end())
	{
		EventDefinitions.erase(it);
	}
}

void LuaEventProcessor::add_bind(std::string_view name, const sol::function& function)
{
	std::string bind_name(name);
	if (IsCommand(bind_name.c_str()))
	{
		MacroError("Cannot bind %s, already bound in MQ.", bind_name.c_str());
	}
	else if (bind_name.empty() || bind_name[0] != '/')
	{
		MacroError("Cannot bind %s, not a valid command string.", bind_name.c_str());
	}
	else
	{
		BindDefinitions.emplace_back(std::make_unique<LuaBind>(bind_name, function, this));
	}
}

void LuaEventProcessor::remove_bind(std::string_view name)
{
	auto it = std::find_if(BindDefinitions.begin(), BindDefinitions.end(),
		[&name](const std::unique_ptr<LuaBind>& bind)
		{
			return bind->Name == name;
		});

	if (it != BindDefinitions.end())
		BindDefinitions.erase(it);
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

static void loop_and_run(const thread::LuaThread& thread, std::vector<std::pair<sol::coroutine, std::vector<std::string>>>& vec)
{
	vec.erase(std::remove_if(vec.begin(), vec.end(), [&thread](auto& co) -> bool
		{
			if (thread.YieldToFrame) return false; // return false for everything else because we need to yield to the frame

			auto result = thread::run_co(co.first, co.second);
			if (!co.second.empty()) co.second.clear(); // a bit of mutation here, but we can only submit a non-empty args the first time

			return !result || result->status() != sol::call_status::yielded; // now just erase events that finished
		}), vec.end());
}

void LuaEventProcessor::run_events(const thread::LuaThread& thread)
{
	loop_and_run(thread, BindsRunning);
	if (!thread.YieldToFrame) loop_and_run(thread, EventsRunning);
}

void LuaEventProcessor::prepare_events()
{
	for (const auto& e : EventsPending)
		EventsRunning.emplace_back(sol::coroutine(e.Thread.state(), e.Definition->Function), e.Args);

	EventsPending.clear();
}

void LuaEventProcessor::prepare_binds()
{
	for (const auto& b : BindsPending)
		BindsRunning.emplace_back(sol::coroutine(b.Thread.state(), b.Definition->Function), b.Args);

	BindsPending.clear();
}

LuaEvent::LuaEvent(std::string_view name, std::string_view expression, const sol::function& function, LuaEventProcessor* processor) :
	Name(name), Expression(expression), Function(function), Processor(processor)
{
	ID = Processor->Trie->AddEvent(Expression.c_str(), LuaEventCallback, this);
}

LuaEvent::~LuaEvent()
{
	Processor->Trie->RemoveEvent(ID);
}

// TODO: make this work (tokenize args into vector, queue the bind in an instance, etc)
static void BindHelper(LuaBind* bind, const char* args)
{
	auto thread = bind->Processor->Thread;
	auto bind_thread = sol::thread::create(thread->Thread.state());

	auto& args_view = tokenize_args(args);
	if (args_view.empty())
	{
		bind->Processor->BindsPending.emplace_back(LuaEventInstance<LuaBind>{ bind, {}, std::move(bind_thread) });
	}
	else
	{
		std::vector<std::string> args_vector(args_view.begin(), args_view.end());
		bind->Processor->BindsPending.emplace_back(LuaEventInstance<LuaBind>{ bind, args_vector, std::move(bind_thread) });
	}
}

LuaBind::LuaBind(const std::string& name, const sol::function& function, LuaEventProcessor* processor) :
	Name(name), Function(function), Callback(new uint8_t[18]), Processor(processor)
{
	// TODO: gut all this when core commands are fixed to allow generic callbacks

	static constexpr uint8_t callback_template[] =
	{
		0x55,                         // push ebp
		0x8b, 0xec,                   // mov ebp, esp
		0xff, 0x75, 0x0c,             // push dword ptr [ebp + 0xc] ; push Buffer
		0x68, 0x00, 0x00, 0x00, 0x00, // push LuaBind
		0xe8, 0x00, 0x00, 0x00, 0x00, // call BindHelper
		0xc9,                         // leave
		0xc3                          // return
	};
//55 8b ec ff 75 0c 68 00 00 00 00 e8 00 00 00 00 c9 c3


	memcpy(Callback, callback_template, 18);

	*(reinterpret_cast<uint32_t*>(Callback + 7)) = reinterpret_cast<uint32_t>(this);
	int diff = reinterpret_cast<int>(&BindHelper) - reinterpret_cast<int>(Callback + 16);
	*(reinterpret_cast<int*>(Callback + 12)) = diff;
	DWORD old_protect;
	VirtualProtectEx(GetCurrentProcess(), reinterpret_cast<LPVOID>(Callback), 18, PAGE_EXECUTE_READWRITE, &old_protect);

	AddCommand(Name.c_str(), reinterpret_cast<fEQCommand>(Callback));//, false, true, true);
}

LuaBind::~LuaBind()
{
	RemoveCommand(Name.c_str());
	delete[] Callback;
}

static void doevents(sol::this_state s)
{
	std::optional<std::weak_ptr<mq::lua::thread::LuaThread>> thread = sol::state_view(s)["mqthread"];
	if (thread && !thread->expired())
	{
		auto thread_ptr = thread->lock();
		thread_ptr->EventProcessor->prepare_events();
		thread_ptr->yield_at(0); // doevents needs to yield, event processing will pick up next frame
	}
}

static void addevent(std::string_view name, std::string_view expression, sol::function function, sol::this_state s)
{
	std::optional<std::weak_ptr<mq::lua::thread::LuaThread>> thread = sol::state_view(s)["mqthread"];
	if (thread && !thread->expired())
		thread->lock()->EventProcessor->add_event(name, expression, function);
}

static void removeevent(std::string_view name, sol::this_state s)
{
	std::optional<std::weak_ptr<mq::lua::thread::LuaThread>> thread = sol::state_view(s)["mqthread"];
	if (thread && !thread->expired())
		thread->lock()->EventProcessor->remove_event(name);
}

static void addbind(std::string_view name, sol::function function, sol::this_state s)
{
	std::optional<std::weak_ptr<mq::lua::thread::LuaThread>> thread = sol::state_view(s)["mqthread"];
	if (thread && !thread->expired())
		thread->lock()->EventProcessor->add_bind(name, function);
}

static void removebind(std::string_view name, sol::this_state s)
{
	std::optional<std::weak_ptr<mq::lua::thread::LuaThread>> thread = sol::state_view(s)["mqthread"];
	if (thread && !thread->expired())
		thread->lock()->EventProcessor->remove_bind(name);
}

void register_lua(sol::state& lua)
{
	lua["doevents"] = &doevents;
	lua["event"] = &addevent;
	lua["unevent"] = &removeevent;
	lua["bind"] = &addbind;
	lua["unbind"] = &removebind;
}
}