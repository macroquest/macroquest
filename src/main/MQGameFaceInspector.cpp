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

// GameFace Inspector
//
// Two parts:
//   Monitor   - hooks the cohtml binding layer and records the traffic that crosses it.
//   Inspector - the GameFace Inspector window under DevTools -> Inspectors. Shows the monitor log, EQ's
//               GameFace state and the cohtml debug tools.

#include "pch.h"

#if HAS_GAMEFACE_UI

#include "MQ2Main.h"
#include "MQ2DeveloperTools.h"
#include "Logging.h"

#include "mq/api/DetourAPI.h"
#include "imgui/implot/implot.h"
#include "imgui/misc/cpp/imgui_stdlib.h"
#include "imgui/fonts/IconsFontAwesome.h"
#include "imgui/ImGuiUtils.h"
#include "mq/zep/ImGuiZepConsole.h"

#include <fmt/format.h>
#include <fmt/ranges.h>

#include <atomic>
#include <chrono>
#include <deque>
#include <filesystem>
#include <functional>
#include <fstream>
#include <map>
#include <mutex>
#include <optional>
#include <unordered_map>

//############################################################################
// Monitor
//############################################################################

// How this works
// --------------
// EQ talks to cohtml only through virtual interfaces, so the monitor observes the traffic by hooking
// vtable slots.
//
// EQ's C++ <-> JS protocol is small:
//   JS  -> C++  BindCall "cpp_js_is_ready"          once, after JS starts
//   C++ -> JS   TriggerEvent "eq_request_js_news"   JS replies synchronously with cpp_on_news_from_js
//   JS  -> C++  BindCall "cpp_on_news_from_js"      args: kv, events
//                 kv is a flat [key, value, ...] array of model changes. events is one string: records
//                 separated by '$', fields separated by '@'.
//   C++ -> JS   Event "eq_sync_js"                  args: kv, events
//                 kv as above. events is a flat array with six fields per event: dispatch, sender,
//                 message, modifiers, params, position.

namespace mq::gameface {

using namespace eqlib::cohtml;

//============================================================================
// Log entries
//
// The monitor records three kinds of traffic:
//   ToUI      - View::TriggerEvent, Binder::BeginEvent..EndEvent with the bound values, ExecuteScript.
//   FromUI    - calls to handlers registered with BindCall or RegisterForEvent, with the values EQ reads
//               from the binder. Also cohtml log messages.
//   Lifecycle - handler registrations, OnReadyForBindings, OnFinishLoad, ...

enum class Direction : uint8_t
{
	ToUI,
	FromUI,
	Lifecycle,
};

static const char* DirectionLabel(Direction direction)
{
	switch (direction)
	{
	case Direction::ToUI: return "->UI";
	case Direction::FromUI: return "<-UI";
	default: return "";
	}
}

enum class TokenType : uint8_t
{
	String,
	Int,
	UInt,
	Double,
	Bool,
	Null,
	Undefined,
	ArrayBegin,     // text = element count
	ArrayEnd,
	MapBegin,       // text = element count
	MapEnd,
	Argument,       // text = argument index, for calls from JS
	Other,          // anything else, text describes it
};

struct Token
{
	TokenType type;
	std::string text;
};

enum class EntryKind : uint8_t
{
	Event,                // Binder::BeginEvent..EndEvent
	TriggerEvent,
	Call,                 // IEventHandler::Invoke
	BindCall,
	RegisterForEvent,
	ExecuteScript,
	RegisterModel,
	OnReadyForBindings,
	OnBindingsReleased,
	OnFinishLoad,
	OnLoadFailed,
	Log,                  // cohtml log message
	Count
};

static const char* KindName(EntryKind kind)
{
	static constexpr const char* s_names[] = {
		"Event", "TriggerEvent", "Call", "BindCall", "RegisterForEvent", "ExecuteScript", "RegisterModel",
		"OnReadyForBindings", "OnBindingsReleased", "OnFinishLoad", "OnLoadFailed", "Log",
	};
	static_assert(std::size(s_names) == static_cast<size_t>(EntryKind::Count));
	return s_names[static_cast<size_t>(kind)];
}

struct LogEntry
{
	uint64_t seq = 0;
	std::chrono::system_clock::time_point time;
	Direction direction = Direction::Lifecycle;
	EntryKind kind = EntryKind::Log;
	std::string name;               // event / call name, url, etc.
	std::vector<Token> tokens;      // flat token stream of the payload
	bool complete = false;          // false while the event is still being bound/read
};

// cohtml log messages that start with CONSOLE_MARKER are collected instead of passed on to EQ. The JS
// console uses them to return results through console.error.
constexpr std::string_view CONSOLE_MARKER = "\x01" "mq";

static void Lifecycle(EntryKind kind, std::string_view name, std::vector<Token> tokens = {});
static std::string FormatEntry(const LogEntry& entry);

//============================================================================
// Log storage

static constexpr size_t MAX_LOG_ENTRIES = 10000;

static std::mutex s_logMutex;
static std::deque<LogEntry> s_log;
static uint64_t s_nextSeq = 1;
static std::atomic_bool s_enabled = false;
static std::ofstream s_logFile;
// Also write completed entries to Logs\GameFaceMonitor.log while the monitor is on.
static bool s_logToFile = false;

struct OpenEntry
{
	uint64_t seq;
	std::string name;
	std::vector<Token> tokens;
	bool hasKeptChild = false;   // a nested entry was recorded while this one was open
};

// EQ syncs with JS every frame: it pushes changes with Event eq_sync_js and polls for news with
// TriggerEvent eq_request_js_news, which JS answers with Call cpp_on_news_from_js. Syncs that carry
// nothing are not recorded; this counts them.
static std::atomic<uint64_t> s_suppressedCount = 0;
// Entries currently being built: an event between BeginEvent and EndEvent, or a handler call. Entries
// nest when a handler triggers events.
static thread_local std::vector<OpenEntry> s_openEntries;

static uint64_t OpenLogEntry(Direction direction, EntryKind kind, std::string_view name)
{
	std::scoped_lock lock(s_logMutex);

	LogEntry& entry = s_log.emplace_back();
	entry.seq = s_nextSeq++;
	entry.time = std::chrono::system_clock::now();
	entry.direction = direction;
	entry.kind = kind;
	entry.name = name;

	while (s_log.size() > MAX_LOG_ENTRIES)
		s_log.pop_front();

	return entry.seq;
}

static void CloseLogEntry(uint64_t seq, std::vector<Token> tokens)
{
	std::scoped_lock lock(s_logMutex);

	for (auto it = s_log.rbegin(); it != s_log.rend(); ++it)
	{
		if (it->seq == seq)
		{
			it->tokens = std::move(tokens);
			it->complete = true;

			if (s_logFile.is_open())
				s_logFile << FormatEntry(*it) << '\n';
			return;
		}

		if (it->seq < seq)
			return; // already trimmed
	}
}

static void DropLogEntry(uint64_t seq)
{
	std::scoped_lock lock(s_logMutex);

	for (auto it = s_log.rbegin(); it != s_log.rend() && it->seq >= seq; ++it)
	{
		if (it->seq == seq)
		{
			s_log.erase(std::next(it).base());
			return;
		}
	}
}

static bool IsEmptySync(const OpenEntry& entry)
{
	if (entry.name == "eq_request_js_news")
		return !entry.hasKeptChild;

	// No keys, no events. "Other" covers arrays bound by reference, whose values aren't visible here.
	if (entry.name == "cpp_on_news_from_js" || entry.name == "eq_sync_js")
	{
		return std::none_of(entry.tokens.begin(), entry.tokens.end(), [](const Token& t) {
			return (t.type == TokenType::String && !t.text.empty()) || t.type == TokenType::Other; });
	}

	return false;
}

static void BeginEntry(Direction direction, EntryKind kind, std::string_view name)
{
	s_openEntries.push_back({ OpenLogEntry(direction, kind, name), std::string(name) });
}

// Last value seen on the wire for every model key, in either direction. Main thread only.
static std::unordered_map<std::string, std::string> s_wireValues;
// Also record syncs with no net effect: no events, and every key ends with the value it already had.
static bool s_showNoOpSyncs = false;
// Record the TriggerEvent/Event eq_request_js_news wrappers of the per-frame JS poll.
static bool s_showPollRequests = false;

// For eq_sync_js and cpp_on_news_from_js. Applies the key/value pairs from the first string array to
// s_wireValues. Returns true if the sync has no net effect: it carries no events and every key ends with
// the value it had before. EQ sends these; for example, CInvSlotMgr::UpdateSlots sets <slot>.Visible to 0
// and back to 1 for empty bazaar slots every 200ms.
static bool ApplySyncAndCheckNoOp(const OpenEntry& entry)
{
	if (entry.name != "eq_sync_js" && entry.name != "cpp_on_news_from_js")
		return false;

	std::vector<const std::string*> kv;
	bool hasEvents = false, unknown = false;
	int arrayIndex = -1, depth = 0;
	for (const Token& t : entry.tokens)
	{
		switch (t.type)
		{
		case TokenType::ArrayBegin: if (depth++ == 0) ++arrayIndex; break;
		case TokenType::ArrayEnd: --depth; break;
		case TokenType::String:
			if (depth > 0 && arrayIndex == 0) kv.push_back(&t.text);
			else if (!t.text.empty()) hasEvents = true;
			break;
		case TokenType::Other: unknown = true; break;
		default: break;
		}
	}

	std::unordered_map<std::string_view, std::optional<std::string>> before;
	for (size_t i = 0; i + 1 < kv.size(); i += 2)
	{
		const std::string& key = *kv[i];
		auto it = s_wireValues.find(key);
		before.try_emplace(key, it != s_wireValues.end() ? std::optional(it->second) : std::nullopt);
		s_wireValues[key] = *kv[i + 1];
	}

	if (hasEvents || unknown || kv.empty())
		return false;

	return std::all_of(before.begin(), before.end(), [](const auto& item) {
		return item.second && *item.second == s_wireValues[std::string(item.first)]; });
}

static void EndEntry()
{
	if (s_openEntries.empty())
		return;

	OpenEntry open = std::move(s_openEntries.back());
	s_openEntries.pop_back();

	bool noOp = ApplySyncAndCheckNoOp(open);
	if (IsEmptySync(open) || (noOp && !s_showNoOpSyncs))
	{
		DropLogEntry(open.seq);
		++s_suppressedCount;
		return;
	}

	// The poll wrappers carry no data: the TriggerEvent, and the Binder event cohtml implements it with.
	// The cpp_on_news_from_js reply nested inside them is what matters, so hide them unless asked for.
	if (open.name == "eq_request_js_news" && !s_showPollRequests)
	{
		DropLogEntry(open.seq);
		if (open.hasKeptChild && !s_openEntries.empty())
			s_openEntries.back().hasKeptChild = true;
		return;
	}

	CloseLogEntry(open.seq, std::move(open.tokens));
	if (!s_openEntries.empty())
		s_openEntries.back().hasKeptChild = true;
}

static void AddToken(TokenType type, std::string text = {})
{
	if (!s_openEntries.empty())
		s_openEntries.back().tokens.push_back({ type, std::move(text) });
}

static void Lifecycle(EntryKind kind, std::string_view name, std::vector<Token> tokens)
{
	CloseLogEntry(OpenLogEntry(Direction::Lifecycle, kind, name), std::move(tokens));
}

//============================================================================
// Formatting

static void AppendQuoted(std::string& out, std::string_view str)
{
	out.push_back('"');
	for (char c : str)
	{
		switch (c)
		{
		case '"': out += "\\\""; break;
		case '\\': out += "\\\\"; break;
		case '\n': out += "\\n"; break;
		case '\r': out += "\\r"; break;
		case '\t': out += "\\t"; break;
		default: out.push_back(c); break;
		}
	}
	out.push_back('"');
}

// "a", ["b", 1], {..}
static std::string FormatTokens(const std::vector<Token>& tokens)
{
	std::string out;
	bool needComma = false;

	for (const Token& token : tokens)
	{
		bool closing = token.type == TokenType::ArrayEnd || token.type == TokenType::MapEnd;
		if (needComma && !closing)
			out += ", ";
		needComma = true;

		switch (token.type)
		{
		case TokenType::String: AppendQuoted(out, token.text); break;
		case TokenType::Null: out += "null"; break;
		case TokenType::Undefined: out += "undefined"; break;
		case TokenType::ArrayBegin: out += "["; needComma = false; break;
		case TokenType::ArrayEnd: out += "]"; break;
		case TokenType::MapBegin: out += "{"; needComma = false; break;
		case TokenType::MapEnd: out += "}"; break;
		case TokenType::Argument: out += "$" + token.text + "="; needComma = false; break;
		case TokenType::Other: out += "<" + token.text + ">"; break;
		default: out += token.text; break;
		}
	}

	return out;
}

static std::string FormatEntry(const LogEntry& entry)
{
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(entry.time.time_since_epoch()).count();
	return fmt::format("[{:>6}] {}.{:03} {:4} {} {}({})", entry.seq, ms / 1000, ms % 1000,
		DirectionLabel(entry.direction), KindName(entry.kind), entry.name, FormatTokens(entry.tokens));
}

//============================================================================
// vtable slot patching

// Keyed by vtable slot address.
static std::unordered_map<void**, void*> s_originals;
static std::vector<uintptr_t> s_patchedAddresses;
static std::unordered_map<const void*, std::string> s_handlerNames;
static bool s_viewHooksInstalled = false;

static bool HookSlot(void** vtable, int slot, void* detour, std::string_view name)
{
	if (!vtable || slot < 0 || s_originals.contains(&vtable[slot]))
		return true;

	void* original = vtable[slot];
	if (original == detour)
		return true;

	uintptr_t address = reinterpret_cast<uintptr_t>(&vtable[slot]);
	if (!AddPatch(address, reinterpret_cast<const uint8_t*>(&detour), sizeof(void*),
		reinterpret_cast<const uint8_t*>(&original), fmt::format("GameFaceMonitor {}", name)))
	{
		LOG_WARN("GameFaceMonitor: failed to hook {} (vtable 0x{:X} slot {})", name, reinterpret_cast<uintptr_t>(vtable), slot);
		return false;
	}

	s_originals[&vtable[slot]] = original;
	s_patchedAddresses.push_back(address);
	return true;
}

namespace slot_probe {

// Must be larger than the vtable of any interface we probe.
static constexpr int TABLE_SIZE = 128;

// Slot index of the most recent probe call. Written by Record, read by Slot.
static thread_local int s_slot = -1;

// Entry N of the fake vtable. Stores N in s_slot, so after the call s_slot holds the slot the virtual call
// dispatched through.
template <int N>
static void Record() { s_slot = N; }

// The fake vtable: entry N is Record<N>.
template <int... N>
static const void* const* Table(std::integer_sequence<int, N...>)
{
	static const void* const table[] = { reinterpret_cast<const void*>(&Record<N>)... };
	return table;
}

// Record ignores its arguments; a reference only needs something to bind to.
template <typename T>
static T Arg()
{
	if constexpr (std::is_reference_v<T>)
	{
		static char unused;
		return reinterpret_cast<T>(unused);
	}
	else
		return T{};
}

// Splits a member function pointer type into its class, return type and arguments.
template <typename>
struct MemberFn;

template <typename C, typename R, typename... Args>
struct MemberFn<R (C::*)(Args...)>
{
	// The same function called directly, with this as the first argument.
	using Free = R(*)(C*, Args...);

	static int Slot(R (C::*fn)(Args...))
	{
		// An object that is nothing but a pointer to the fake vtable.
		struct { const void* const* vtable; } fake{ Table(std::make_integer_sequence<int, TABLE_SIZE>{}) };

		// The virtual call goes through fake's vtable and lands in Record<slot>.
		s_slot = -1;
		(reinterpret_cast<C*>(&fake)->*fn)(Arg<Args>()...);
		return s_slot;
	}
};

} // namespace slot_probe

// Vtable slot of the virtual member function Fn, found once by calling Fn on a fake object whose vtable
// entries each record their own index.
template <auto Fn>
static int SlotOf()
{
	static const int slot = slot_probe::MemberFn<decltype(Fn)>::Slot(Fn);
	return slot;
}

template <auto Fn>
static bool HookSlot(const void* object, void* detour, std::string_view name)
{
	return object && HookSlot(*(void***)object, SlotOf<Fn>(), detour, name);
}

// The original function behind a hooked slot. Call it as fn(self, args...).
template <auto Fn>
static auto Original(const void* self)
{
	using Free = typename slot_probe::MemberFn<decltype(Fn)>::Free;
	return reinterpret_cast<Free>(s_originals.at(&(*(void***)self)[SlotOf<Fn>()]));
}

static void RemoveAllHooks()
{
	for (uintptr_t address : s_patchedAddresses)
		RemovePatch(address);

	s_patchedAddresses.clear();
	s_originals.clear();
	s_viewHooksInstalled = false;
	s_openEntries.clear();
}

//============================================================================
// Binder hooks. C++ binds values for outgoing events and reads values in incoming calls.

static void HookBinder(Binder* binder);

static std::string ToString(bool v) { return v ? "true" : "false"; }
template <typename T> static std::string ToString(T v) { return std::to_string(v); }

template <typename T>
static constexpr TokenType TokenTypeOf()
{
	if constexpr (std::is_same_v<T, bool>) return TokenType::Bool;
	else if constexpr (std::is_floating_point_v<T>) return TokenType::Double;
	else if constexpr (std::is_signed_v<T>) return TokenType::Int;
	else return TokenType::UInt;
}

// The Bind/Read overload for T.
template <typename T>
static constexpr auto BindOverload = static_cast<void (Binder::*)(T)>(&Binder::Bind);
template <typename T>
static constexpr auto ReadOverload = static_cast<void (Binder::*)(T&)>(&Binder::Read);
static constexpr auto ReadStringOverload = static_cast<void (Binder::*)(const char*&, size_t&)>(&Binder::Read);

template <typename T>
static void Binder_Bind(Binder* self, T value)
{
	Original<BindOverload<T>>(self)(self, value);
	AddToken(TokenTypeOf<T>(), ToString(value));
}

template <typename T>
static void Binder_Read(Binder* self, T& value)
{
	Original<ReadOverload<T>>(self)(self, value);
	AddToken(TokenTypeOf<T>(), ToString(value));
}

template <auto Fn, TokenType Type>
static void Binder_Marker(Binder* self)
{
	Original<Fn>(self)(self);
	AddToken(Type);
}

template <auto Fn, TokenType Type>
static void Binder_Begin(Binder* self, size_t count)
{
	Original<Fn>(self)(self, count);
	AddToken(Type, std::to_string(count));
}

template <auto Fn, TokenType Type>
static size_t Binder_ReadBegin(Binder* self)
{
	size_t count = Original<Fn>(self)(self);
	AddToken(Type, std::to_string(count));
	return count;
}

static void Binder_BeginEvent(Binder* self, const char* name, int argCount)
{
	if (s_enabled)
		BeginEntry(Direction::ToUI, EntryKind::Event, name ? name : "(null)");

	Original<&Binder::BeginEvent>(self)(self, name, argCount);
}

static void Binder_EndEvent(Binder* self)
{
	Original<&Binder::EndEvent>(self)(self);

	if (s_enabled)
		EndEntry();
}

static void Binder_BindString(Binder* self, const char* value)
{
	Original<BindOverload<const char*>>(self)(self, value);

	if (value)
		AddToken(TokenType::String, value);
	else
		AddToken(TokenType::Null);
}

static void Binder_ReadString(Binder* self, const char*& buffer, size_t& size)
{
	Original<ReadStringOverload>(self)(self, buffer, size);
	AddToken(TokenType::String, buffer ? std::string(buffer, size) : std::string());
}

static bool Binder_TryBindArrayByRef(Binder* self, void* arr, void* elementBinder, void* elementReader, void* lengthGetter, void* elementGetter)
{
	bool result = Original<&Binder::TryBindArrayByRef>(self)(self, arr, elementBinder, elementReader, lengthGetter, elementGetter);

	// When this succeeds the elements are not bound through Bind() and won't show up in the log.
	if (result)
		AddToken(TokenType::Other, "array by ref");
	return result;
}

static void HookBinder(Binder* binder)
{
	using B = Binder;

	HookSlot<&B::BeginEvent>(binder, &Binder_BeginEvent, "Binder::BeginEvent");
	HookSlot<&B::EndEvent>(binder, &Binder_EndEvent, "Binder::EndEvent");
	HookSlot<&B::BindNull>(binder, &Binder_Marker<&B::BindNull, TokenType::Null>, "Binder::BindNull");
	HookSlot<&B::BindUndefined>(binder, &Binder_Marker<&B::BindUndefined, TokenType::Undefined>, "Binder::BindUndefined");
	HookSlot<BindOverload<const char*>>(binder, &Binder_BindString, "Binder::Bind(const char*)");
	HookSlot<BindOverload<bool>>(binder, &Binder_Bind<bool>, "Binder::Bind(bool)");
	HookSlot<BindOverload<int>>(binder, &Binder_Bind<int>, "Binder::Bind(int)");
	HookSlot<BindOverload<unsigned int>>(binder, &Binder_Bind<unsigned int>, "Binder::Bind(unsigned)");
	HookSlot<BindOverload<long long>>(binder, &Binder_Bind<long long>, "Binder::Bind(int64)");
	HookSlot<BindOverload<unsigned long long>>(binder, &Binder_Bind<unsigned long long>, "Binder::Bind(uint64)");
	HookSlot<BindOverload<float>>(binder, &Binder_Bind<float>, "Binder::Bind(float)");
	HookSlot<BindOverload<double>>(binder, &Binder_Bind<double>, "Binder::Bind(double)");
	HookSlot<&B::TryBindArrayByRef>(binder, &Binder_TryBindArrayByRef, "Binder::TryBindArrayByRef");
	HookSlot<&B::ArrayBegin>(binder, &Binder_Begin<&B::ArrayBegin, TokenType::ArrayBegin>, "Binder::ArrayBegin");
	HookSlot<&B::ArrayEnd>(binder, &Binder_Marker<&B::ArrayEnd, TokenType::ArrayEnd>, "Binder::ArrayEnd");
	HookSlot<&B::MapBegin>(binder, &Binder_Begin<&B::MapBegin, TokenType::MapBegin>, "Binder::MapBegin");
	HookSlot<&B::MapEnd>(binder, &Binder_Marker<&B::MapEnd, TokenType::MapEnd>, "Binder::MapEnd");

	HookSlot<ReadStringOverload>(binder, &Binder_ReadString, "Binder::Read(const char*&)");
	HookSlot<ReadOverload<bool>>(binder, &Binder_Read<bool>, "Binder::Read(bool&)");
	HookSlot<ReadOverload<int>>(binder, &Binder_Read<int>, "Binder::Read(int&)");
	HookSlot<ReadOverload<unsigned int>>(binder, &Binder_Read<unsigned int>, "Binder::Read(unsigned&)");
	HookSlot<ReadOverload<long long>>(binder, &Binder_Read<long long>, "Binder::Read(int64&)");
	HookSlot<ReadOverload<unsigned long long>>(binder, &Binder_Read<unsigned long long>, "Binder::Read(uint64&)");
	HookSlot<ReadOverload<float>>(binder, &Binder_Read<float>, "Binder::Read(float&)");
	HookSlot<ReadOverload<double>>(binder, &Binder_Read<double>, "Binder::Read(double&)");
	HookSlot<&B::ReadArrayBegin>(binder, &Binder_ReadBegin<&B::ReadArrayBegin, TokenType::ArrayBegin>, "Binder::ReadArrayBegin");
	HookSlot<&B::ReadArrayEnd>(binder, &Binder_Marker<&B::ReadArrayEnd, TokenType::ArrayEnd>, "Binder::ReadArrayEnd");
	HookSlot<&B::ReadMapBegin>(binder, &Binder_ReadBegin<&B::ReadMapBegin, TokenType::MapBegin>, "Binder::ReadMapBegin");
	HookSlot<&B::ReadMapEnd>(binder, &Binder_Marker<&B::ReadMapEnd, TokenType::MapEnd>, "Binder::ReadMapEnd");
}

//============================================================================
// Incoming calls: IEventHandler::Invoke for handlers registered through BindCall / RegisterForEvent

static Binder* ArgumentsBinder_GetArgument(ArgumentsBinder* self, int index)
{
	Binder* binder = Original<&ArgumentsBinder::GetArgument>(self)(self, index);

	// The argument binder may be a different class than the view binder.
	if (binder)
		HookBinder(binder);

	AddToken(TokenType::Argument, std::to_string(index));
	return binder;
}

static void EventHandler_Invoke(IEventHandler* self, ArgumentsBinder* args)
{
	if (s_enabled)
	{
		auto it = s_handlerNames.find(self);
		BeginEntry(Direction::FromUI, EntryKind::Call, it != s_handlerNames.end() ? it->second : fmt::format("handler@{}", (void*)self));
		HookSlot<&ArgumentsBinder::GetArgument>(args, &ArgumentsBinder_GetArgument, "ArgumentsBinder::GetArgument");
	}

	Original<&IEventHandler::Invoke>(self)(self, args);

	if (s_enabled)
		EndEntry();
}

static void TrackHandler(EntryKind kind, const char* name, IEventHandler* handler)
{
	if (!handler)
		return;

	const std::string& handlerName = s_handlerNames[handler] = name ? name : "(null)";
	HookSlot<&IEventHandler::Invoke>(handler, &EventHandler_Invoke, fmt::format("IEventHandler::Invoke ({})", handlerName));

	if (s_enabled)
		Lifecycle(kind, handlerName, { { TokenType::Other, fmt::format("handler {}", (void*)handler) } });
}

//============================================================================
// View hooks

static void* View_BindCall(View* self, const char* name, IEventHandler* handler)
{
	TrackHandler(EntryKind::BindCall, name, handler);
	return Original<&View::BindCall>(self)(self, name, handler);
}

static void* View_RegisterForEvent(View* self, const char* name, IEventHandler* handler)
{
	TrackHandler(EntryKind::RegisterForEvent, name, handler);
	return Original<&View::RegisterForEvent>(self)(self, name, handler);
}

static void View_TriggerEvent(View* self, const char* name)
{
	if (s_enabled)
		BeginEntry(Direction::ToUI, EntryKind::TriggerEvent, name ? name : "(null)");

	// JS handlers run synchronously, so anything they call back into C++ nests inside this entry's timeline.
	Original<&View::TriggerEvent>(self)(self, name);

	if (s_enabled)
		EndEntry();
}

static void View_ExecuteScript(View* self, const char* script)
{
	if (s_enabled)
		Lifecycle(EntryKind::ExecuteScript, "", { { TokenType::String, script ? script : "" } });

	Original<&View::ExecuteScript>(self)(self, script);
}

static void View_RegisterModelOfType(View* self, const char* name, void* model, TypeInfo* typeInfo, void* bindFunc)
{
	if (s_enabled)
		Lifecycle(EntryKind::RegisterModel, name ? name : "(null)", { { TokenType::Other, fmt::format("model {}", model) } });

	Original<&View::RegisterModelOfType>(self)(self, name, model, typeInfo, bindFunc);
}

static Binder* View_GetBinder(View* self)
{
	Binder* binder = Original<&View::GetBinder>(self)(self);
	if (binder)
		HookBinder(binder);
	return binder;
}

//============================================================================
// GF::ViewListener and LogHandler hooks. These are EQ's implementations.

static void Listener_OnReadyForBindings(GF::ViewListener* self)
{
	if (s_enabled)
		Lifecycle(EntryKind::OnReadyForBindings, "");
	Original<&IViewListener::OnReadyForBindings>(self)(self);
}

static void Listener_OnBindingsReleased(GF::ViewListener* self)
{
	if (s_enabled)
		Lifecycle(EntryKind::OnBindingsReleased, "");
	Original<&IViewListener::OnBindingsReleased>(self)(self);
}

static void Listener_OnFinishLoad(GF::ViewListener* self, const char* url)
{
	if (s_enabled)
		Lifecycle(EntryKind::OnFinishLoad, url ? url : "");
	Original<&IViewListener::OnFinishLoad>(self)(self, url);
}

static void Listener_OnLoadFailed(GF::ViewListener* self, const char* url, const char* error)
{
	if (s_enabled)
		Lifecycle(EntryKind::OnLoadFailed, url ? url : "", { { TokenType::String, error ? error : "" } });
	Original<&IViewListener::OnLoadFailed>(self)(self, url, error);
}

// cohtml may log from its worker threads, so this hook must not touch s_originals, which is main-thread only.
// The original stays valid after unhooking; it's a function in eqgame.
static constexpr const char* SEVERITY_NAMES[] = { "Trace", "Debug", "Info", "Warning", "Error", "Critical" };
static_assert(std::size(SEVERITY_NAMES) == Logging::SeveritiesCount);

using WriteLogFn = void(*)(Logging::ILogHandler*, Logging::Severity, const char*, size_t);
static std::atomic<WriteLogFn> s_originalWriteLog = nullptr;

static std::mutex s_consoleMutex;
static std::vector<std::string> s_consoleOutput;

static void LogHandler_WriteLog(Logging::ILogHandler* self, Logging::Severity severity, const char* message, size_t length)
{
	// Results of the inspector's JS console; keep them out of EQ's UI error log.
	if (message && std::string_view(message, length).starts_with(CONSOLE_MARKER))
	{
		std::scoped_lock lock(s_consoleMutex);
		s_consoleOutput.emplace_back(message + CONSOLE_MARKER.size(), length - CONSOLE_MARKER.size());
		return;
	}

	if (s_enabled && message)
	{
		const char* severityName = severity >= 0 && severity < Logging::SeveritiesCount ? SEVERITY_NAMES[severity] : "?";
		CloseLogEntry(OpenLogEntry(Direction::FromUI, EntryKind::Log, severityName), { { TokenType::String, std::string(message, length) } });
	}

	s_originalWriteLog.load()(self, severity, message, length);
}

//============================================================================

// Returns true once the view-level hooks are in. EQ registers its bindings in OnReadyForBindings, so
// bindings registered before this point need a /reloadui to be seen.
static bool TryInstallHooks()
{
	if (s_viewHooksInstalled)
		return true;

	GF::ViewListener* listener = pGFViewListener.get();
	if (!listener || !listener->pView)
		return false;

	View* view = listener->pView;
	HookSlot<&View::BindCall>(view, &View_BindCall, "View::BindCall");
	HookSlot<&View::RegisterForEvent>(view, &View_RegisterForEvent, "View::RegisterForEvent");
	HookSlot<&View::TriggerEvent>(view, &View_TriggerEvent, "View::TriggerEvent");
	HookSlot<&View::ExecuteScript>(view, &View_ExecuteScript, "View::ExecuteScript");
	HookSlot<&View::RegisterModelOfType>(view, &View_RegisterModelOfType, "View::RegisterModelOfType");
	HookSlot<&View::GetBinder>(view, &View_GetBinder, "View::GetBinder");

	HookSlot<&IViewListener::OnReadyForBindings>(listener, &Listener_OnReadyForBindings, "ViewListener::OnReadyForBindings");
	HookSlot<&IViewListener::OnBindingsReleased>(listener, &Listener_OnBindingsReleased, "ViewListener::OnBindingsReleased");
	HookSlot<&IViewListener::OnFinishLoad>(listener, &Listener_OnFinishLoad, "ViewListener::OnFinishLoad");
	HookSlot<&IViewListener::OnLoadFailed>(listener, &Listener_OnLoadFailed, "ViewListener::OnLoadFailed");
	s_originalWriteLog = reinterpret_cast<WriteLogFn>((*(void***)&listener->logHandler)[SlotOf<&Logging::ILogHandler::WriteLog>()]);
	HookSlot<&Logging::ILogHandler::WriteLog>(&listener->logHandler, &LogHandler_WriteLog, "LogHandler::WriteLog");

	// GetBinder returns null until the binder is ready; View_GetBinder picks it up later in that case.
	if (Binder* binder = Original<&View::GetBinder>(view)(view))
		HookBinder(binder);

	s_viewHooksInstalled = true;
	return true;
}

// Opens the log file while the monitor is on and logging to file is enabled, and closes it otherwise.
static void UpdateLogFile()
{
	std::scoped_lock lock(s_logMutex);
	bool wanted = s_enabled && s_logToFile;
	if (wanted && !s_logFile.is_open())
		s_logFile.open(std::filesystem::path(gPathLogs) / "GameFaceMonitor.log", std::ios::out | std::ios::trunc);
	else if (!wanted && s_logFile.is_open())
		s_logFile.close();
}

static void SetMonitorEnabled(bool enabled)
{
	if (enabled == s_enabled)
		return;

	if (enabled)
	{
		s_enabled = true;
		UpdateLogFile();
		TryInstallHooks();
	}
	else
	{
		s_enabled = false;
		RemoveAllHooks();
		s_handlerNames.clear();
		s_wireValues.clear();
		UpdateLogFile();
	}
}

// Visit completed entries with seq > afterSeq, oldest -> newest, stopping at the first entry that is
// still being built. Returns the seq of the last entry visited, or afterSeq if none.
static uint64_t ForEachLogEntryAfter(uint64_t afterSeq, const std::function<void(const LogEntry&)>& fn)
{
	std::scoped_lock lock(s_logMutex);

	auto it = std::upper_bound(s_log.begin(), s_log.end(), afterSeq,
		[](uint64_t seq, const LogEntry& entry) { return seq < entry.seq; });

	for (; it != s_log.end() && it->complete; ++it)
	{
		fn(*it);
		afterSeq = it->seq;
	}

	return afterSeq;
}

static std::vector<std::string> TakeConsoleOutput()
{
	std::scoped_lock lock(s_consoleMutex);
	return std::exchange(s_consoleOutput, {});
}

static std::vector<std::string> GetKnownHandlerNames()
{
	std::vector<std::string> names;
	for (const auto& [handler, name] : s_handlerNames)
		names.push_back(name);
	std::sort(names.begin(), names.end());
	return names;
}

static void ClearLog()
{
	std::scoped_lock lock(s_logMutex);
	s_log.clear();
}

//############################################################################
// Inspector
//############################################################################

//============================================================================
// Decoded copy of the monitor log
//
// The protocol is described under "How this works" above. In the log it looks like this:
//   ->UI  Event "eq_sync_js"            [key, value, ...], [dispatch, sender, message, modifiers, params, position, ...]
//   <-UI  Call  "cpp_on_news_from_js"   $0=[key, value, ...], $1="f0@f1@f2@f3@f4@f5$f0@..."

struct JsEvent
{
	std::string dispatch;     // window name; "InvSlots" goes to the inventory slot manager
	std::string sender;       // component itemPath
	std::string message;      // EventLClick, EventSelItem, ...
	std::string modifiers;    // '|' separated Ctrl/Shift/Alt
	std::string params;
	std::string position;     // "x,y"
};

static constexpr size_t JS_EVENT_FIELDS = 6;
static constexpr const char* JS_EVENT_FIELD_NAMES[JS_EVENT_FIELDS] = { "Dispatch", "Sender", "Message", "Modifiers", "Params", "Position" };

// Pointers to an event's fields in protocol order. Works for JsEvent and EQ's GFJsEvent.
template <typename Event>
static auto EventFields(Event& e)
{
	return std::array{ &e.dispatch, &e.sender, &e.message, &e.modifiers, &e.params, &e.position };
}
static_assert(std::tuple_size_v<decltype(EventFields(std::declval<JsEvent&>()))> == JS_EVENT_FIELDS);

struct KeyValue
{
	std::string key;
	std::string value;
	std::string previous;     // last value seen on the wire for this key, in either direction
	bool known = false;       // the key was seen before
	bool changed = true;      // value differs from previous, or the key is new
};

struct Record
{
	uint64_t seq = 0;
	std::chrono::system_clock::time_point time;
	Direction direction = Direction::Lifecycle;
	EntryKind kind = EntryKind::Log;
	std::string name;
	std::vector<Token> tokens;

	std::vector<KeyValue> kv;
	std::vector<JsEvent> events;
	std::string summary;      // one line, for the table
	int changedKeys = 0;      // distinct keys whose final value differs from the value before this record
	bool protocol = false;    // eq_sync_js / cpp_on_news_from_js / cpp_js_is_ready / eq_request_js_news
};

static constexpr size_t MAX_RECORDS = 20000;
static constexpr size_t MAX_EVENTS = 20000;
static constexpr int STATS_SECONDS = 120;

static ImVec4 DirectionColor(Direction direction)
{
	switch (direction)
	{
	case Direction::ToUI: return ImVec4(0.55f, 0.80f, 1.00f, 1.0f);
	case Direction::FromUI: return ImVec4(1.00f, 0.80f, 0.45f, 1.0f);
	default: return ImVec4(0.70f, 0.70f, 0.70f, 1.0f);
	}
}

static std::string FormatTime(std::chrono::system_clock::time_point time)
{
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(time.time_since_epoch()).count();
	time_t secs = static_cast<time_t>(ms / 1000);
	tm local;
	localtime_s(&local, &secs);
	return fmt::format("{:02}:{:02}:{:02}.{:03}", local.tm_hour, local.tm_min, local.tm_sec, ms % 1000);
}

// Pulls the string arrays and loose strings out of a token stream.
static void CollectStrings(const std::vector<Token>& tokens, std::vector<std::vector<std::string>>& arrays,
	std::vector<std::string>& loose)
{
	int depth = 0;
	for (const Token& token : tokens)
	{
		switch (token.type)
		{
		case TokenType::ArrayBegin:
			if (depth++ == 0)
				arrays.emplace_back();
			break;
		case TokenType::ArrayEnd:
			--depth;
			break;
		case TokenType::String:
			if (depth > 0)
				arrays.back().push_back(token.text);
			else
				loose.push_back(token.text);
			break;
		default:
			break;
		}
	}
}

static std::vector<KeyValue> ToKeyValues(const std::vector<std::string>& flat)
{
	std::vector<KeyValue> kv;
	for (size_t i = 0; i + 1 < flat.size(); i += 2)
		kv.push_back({ flat[i], flat[i + 1] });
	return kv;
}

static JsEvent MakeEvent(const std::string* f, size_t count)
{
	JsEvent e;
	auto fields = EventFields(e);
	for (size_t i = 0; i < count && i < JS_EVENT_FIELDS; ++i)
		*fields[i] = f[i];
	return e;
}

static std::vector<JsEvent> SplitEventString(std::string_view text)
{
	std::vector<JsEvent> events;
	for (auto part : split_view(text, '$'))
	{
		if (part.empty())
			continue;
		std::vector<std::string> fields;
		for (auto field : split_view(part, '@'))
			fields.emplace_back(field);
		events.push_back(MakeEvent(fields.data(), fields.size()));
	}
	return events;
}

static Record Decode(const LogEntry& entry)
{
	Record r;
	r.seq = entry.seq;
	r.time = entry.time;
	r.direction = entry.direction;
	r.kind = entry.kind;
	r.name = entry.name;
	r.tokens = entry.tokens;

	std::vector<std::vector<std::string>> arrays;
	std::vector<std::string> loose;
	CollectStrings(entry.tokens, arrays, loose);

	if (entry.name == "eq_sync_js")
	{
		r.protocol = true;
		if (arrays.size() > 0)
			r.kv = ToKeyValues(arrays[0]);
		if (arrays.size() > 1)
			for (size_t i = 0; i + JS_EVENT_FIELDS <= arrays[1].size(); i += JS_EVENT_FIELDS)
				r.events.push_back(MakeEvent(&arrays[1][i], JS_EVENT_FIELDS));
	}
	else if (entry.name == "cpp_on_news_from_js")
	{
		r.protocol = true;
		if (arrays.size() > 0)
			r.kv = ToKeyValues(arrays[0]);
		if (!loose.empty())
			r.events = SplitEventString(loose[0]);
	}
	else if (entry.name == "cpp_js_is_ready" || entry.name == "eq_request_js_news")
	{
		r.protocol = true;
	}

	// Syncs with keys or events are summarized by RecordStore::Add, which knows the net changes.
	if (!r.protocol || (r.kv.empty() && r.events.empty()))
	{
		r.summary = FormatTokens(entry.tokens);
		if (r.summary.size() > 300)
			r.summary = r.summary.substr(0, 300) + "...";
	}

	return r;
}

//----------------------------------------------------------------------------

struct ModelValue
{
	std::string value;
	uint64_t seq = 0;
	std::chrono::system_clock::time_point time;
	Direction direction = Direction::Lifecycle;
	uint32_t updates = 0;
};

struct EventRow
{
	uint64_t seq;
	std::chrono::system_clock::time_point time;
	Direction direction;
	JsEvent event;
};

struct SecondBucket
{
	int64_t second = 0;
	float toUI = 0, fromUI = 0, keysToUI = 0, keysFromUI = 0, events = 0;
};

class RecordStore
{
public:
	std::deque<Record> records;
	std::deque<EventRow> events;
	std::map<std::string, ModelValue> model;          // every key seen in either direction
	std::unordered_map<std::string, uint32_t> keysByWindow;     // first key segment -> updates
	std::map<std::string, uint32_t> eventsByWindow;   // dispatch -> events
	std::unordered_map<std::string, uint32_t> eventsByMessage;
	std::deque<SecondBucket> seconds;
	uint64_t lastSeq = 0;

	void Poll()
	{
		lastSeq = ForEachLogEntryAfter(lastSeq, [this](const LogEntry& entry) { Add(Decode(entry)); });

		while (records.size() > MAX_RECORDS)
			records.pop_front();
		while (events.size() > MAX_EVENTS)
			events.pop_front();
	}

	void Clear()
	{
		records.clear();
		events.clear();
		model.clear();
		keysByWindow.clear();
		eventsByWindow.clear();
		eventsByMessage.clear();
		seconds.clear();
		ClearLog();
	}

private:
	SecondBucket& Bucket(std::chrono::system_clock::time_point time)
	{
		int64_t second = std::chrono::duration_cast<std::chrono::seconds>(time.time_since_epoch()).count();
		if (seconds.empty() || seconds.back().second < second)
		{
			// Fill gaps so the plot has a continuous x axis. A gap longer than the plot starts it over.
			if (!seconds.empty() && second - seconds.back().second > STATS_SECONDS)
				seconds.clear();
			int64_t next = seconds.empty() ? second : seconds.back().second + 1;
			for (; next <= second; ++next)
				seconds.push_back({ next });
			while (seconds.size() > STATS_SECONDS)
				seconds.pop_front();
		}
		return seconds.back();
	}

	void Add(Record&& r)
	{
		SecondBucket& bucket = Bucket(r.time);
		if (r.direction == Direction::ToUI) ++bucket.toUI;
		if (r.direction == Direction::FromUI) ++bucket.fromUI;

		std::unordered_map<std::string, int> byWindow;
		std::unordered_map<std::string, std::optional<std::string>> before;   // value before this record, per distinct key
		for (KeyValue& kv : r.kv)
		{
			auto it = model.find(kv.key);
			if (it != model.end())
			{
				kv.known = true;
				kv.previous = it->second.value;
				kv.changed = kv.previous != kv.value;
			}
			before.try_emplace(kv.key, it != model.end() ? std::optional(it->second.value) : std::nullopt);
			std::string window = kv.key.substr(0, kv.key.find('.'));
			++byWindow[window];

			ModelValue& mv = model[kv.key];
			mv.value = kv.value;
			mv.seq = r.seq;
			mv.time = r.time;
			mv.direction = r.direction;
			++mv.updates;

			++keysByWindow[window];
			(r.direction == Direction::ToUI ? bucket.keysToUI : bucket.keysFromUI) += 1;
		}

		for (const auto& [key, value] : before)
			r.changedKeys += !value || *value != model[key].value;

		if (r.protocol && (!r.kv.empty() || !r.events.empty()))
		{
			// Example: "400 keys (3 net changes), 1 events | InventoryWindow 120 BuffWindow 80 ... | dispatch.sender message"
			std::vector<std::pair<std::string, int>> top(byWindow.begin(), byWindow.end());
			std::sort(top.begin(), top.end(), [](const auto& a, const auto& b) { return a.second > b.second; });
			std::string summary = fmt::format("{} keys ({} net changes), {} events", r.kv.size(), r.changedKeys, r.events.size());
			if (!top.empty())
				summary += " |";
			for (size_t i = 0; i < top.size() && i < 4; ++i)
				summary += fmt::format(" {} {}", top[i].first, top[i].second);
			if (top.size() > 4)
				summary += " ...";
			for (const JsEvent& e : r.events)
			{
				if (summary.size() > 300)
					break;
				summary += fmt::format(" | {}.{} {}", e.dispatch, e.sender, e.message);
			}
			r.summary = std::move(summary);
		}

		for (const JsEvent& e : r.events)
		{
			events.push_back({ r.seq, r.time, r.direction, e });
			++eventsByWindow[e.dispatch];
			++eventsByMessage[e.message];
			++bucket.events;
		}

		records.push_back(std::move(r));
	}
};

static RecordStore s_store;

// The model as EQ holds it in g_pGF->model.values, with the wire metadata merged in. Falls back to the
// keys seen on the wire when the GF manager isn't available. Rebuilt at most every 250ms.
static std::map<std::string, ModelValue> s_liveModel;
static std::chrono::steady_clock::time_point s_liveModelTime;
static bool s_useLiveModel = true;

static bool IsLiveModelAvailable()
{
	return pGF && GetGameState() != GAMESTATE_PRECHARSELECT;
}

static const std::map<std::string, ModelValue>& GetModel()
{
	if (!s_useLiveModel || !IsLiveModelAvailable())
		return s_store.model;

	auto now = std::chrono::steady_clock::now();
	if (now - s_liveModelTime > std::chrono::milliseconds(250))
	{
		s_liveModelTime = now;
		s_liveModel.clear();
		for (const auto& [key, value] : pGF->model.values)
		{
			std::string name(key.c_str(), key.size());
			auto wire = s_store.model.find(name);
			ModelValue& mv = s_liveModel[std::move(name)];
			if (wire != s_store.model.end())
				mv = wire->second;
			mv.value.assign(value.c_str(), value.size());
		}
	}
	return s_liveModel;
}

//============================================================================
// Main-thread action queue. ImGui is drawn from the render hook; anything that calls into cohtml
// is deferred to the next pulse so it never runs in the middle of a view render.

static std::vector<std::function<void()>> s_pendingActions;

// Runs action on the main thread at the next pulse, outside any cohtml call.
static void QueueGameFaceAction(std::function<void()> action)
{
	s_pendingActions.push_back(std::move(action));
}

//============================================================================

class GameFaceInspector : public ImGuiWindowBase
{
public:
	GameFaceInspector() : ImGuiWindowBase("GameFace Inspector")
	{
		SetDefaultSize(ImVec2(900, 600));
	}

	void Draw() override
	{
		s_store.Poll();

		DrawToolbar();

		if (ImGui::BeginTabBar("##GameFaceTabs"))
		{
			if (ImGui::BeginTabItem("Event Log"))
			{
				DrawEventLog();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Windows"))
			{
				DrawWindows();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("JS Events"))
			{
				DrawJsEvents();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Model"))
			{
				DrawModel();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Statistics"))
			{
				DrawStatistics();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Engine"))
			{
				DrawEngineState();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Debug Tools"))
			{
				DrawDebugTools();
				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();
		}
	}

private:
	//------------------------------------------------------------------------
	void DrawToolbar()
	{
		bool enabled = s_enabled;
		if (ImGui::Checkbox("Monitor", &enabled))
			SetMonitorEnabled(enabled);
		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("Hooks the cohtml binding layer and records traffic.\n"
				"Bindings registered before the monitor was enabled are named after a /reloadui.");

		ImGui::SameLine();
		if (ImGui::Checkbox("Log to file", &s_logToFile))
			UpdateLogFile();
		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("Also writes recorded traffic to Logs\\GameFaceMonitor.log while the monitor is on.\n"
				"The file is overwritten each time it is opened.");

		ImGui::SameLine();
		ImGui::Checkbox("Show no-op syncs", &s_showNoOpSyncs);
		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("Record syncs whose keys all end with the value they already had (and that carry no events).\n"
				"EQ sends these: every 200ms CInvSlotMgr::UpdateSlots sets <slot>.Visible 0 then 1 for empty bazaar slots.\n"
				"Applies to new traffic only; hidden ones are not recorded.");

		ImGui::SameLine();
		ImGui::Checkbox("Show poll requests", &s_showPollRequests);
		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("Record the TriggerEvent / Event eq_request_js_news wrappers around each JS poll.\n"
				"EQ polls JS every frame; cohtml implements TriggerEvent with a Binder event, hence the pair.\n"
				"The cpp_on_news_from_js reply (the actual news) is shown either way.");

		ImGui::SameLine();
		if (ImGui::Button("Clear"))
			s_store.Clear();

		ImGui::SameLine();
		ImGui::BeginDisabled(!pGFViewListener);
		if (ImGui::Button("Reload UI"))
			DoCommand("/reloadui", false);
		ImGui::EndDisabled();

		ImGui::SameLine();
		if (!s_enabled)
			ImGui::TextDisabled("monitor off");
		else if (!s_viewHooksInstalled)
			ImGui::TextColored(ImVec4(1, 0.8f, 0.3f, 1), "waiting for GameFace view");
		else
			ImGui::TextDisabled("%d hooks, %d records, %d keys, %llu empty/no-op syncs hidden", (int)s_patchedAddresses.size(), (int)s_store.records.size(),
				(int)s_store.model.size(), s_suppressedCount.load());
	}

	//------------------------------------------------------------------------
	// Event Log

	bool m_showToUI = true, m_showFromUI = true, m_showLifecycle = true, m_showLog = true;
	bool m_protocolOnly = false, m_autoScroll = true;
	ImGuiTextFilter m_logFilter;
	uint64_t m_selectedSeq = 0;

	bool PassesLogFilter(const Record& r)
	{
		if (r.kind == EntryKind::Log) { if (!m_showLog) return false; }
		else if (r.direction == Direction::ToUI && !m_showToUI) return false;
		else if (r.direction == Direction::FromUI && !m_showFromUI) return false;
		else if (r.direction == Direction::Lifecycle && !m_showLifecycle) return false;

		if (m_protocolOnly && !r.protocol)
			return false;

		if (m_logFilter.IsActive())
		{
			if (m_logFilter.PassFilter(r.name.c_str()) || m_logFilter.PassFilter(KindName(r.kind))
				|| m_logFilter.PassFilter(r.summary.c_str()))
				return true;
			for (const KeyValue& kv : r.kv)
				if (m_logFilter.PassFilter(kv.key.c_str()) || m_logFilter.PassFilter(kv.value.c_str()))
					return true;
			return false;
		}
		return true;
	}

	void DrawEventLog()
	{
		ImGui::Checkbox("->UI", &m_showToUI); ImGui::SameLine();
		ImGui::Checkbox("<-UI", &m_showFromUI); ImGui::SameLine();
		ImGui::Checkbox("Lifecycle", &m_showLifecycle); ImGui::SameLine();
		ImGui::Checkbox("cohtml log", &m_showLog); ImGui::SameLine();
		ImGui::Checkbox("Protocol only", &m_protocolOnly); ImGui::SameLine();
		ImGui::Checkbox("Auto-scroll", &m_autoScroll); ImGui::SameLine();
		m_logFilter.Draw("Filter##log", 200);

		std::vector<const Record*> rows;
		rows.reserve(s_store.records.size());
		for (const Record& r : s_store.records)
			if (PassesLogFilter(r))
				rows.push_back(&r);

		const Record* selected = nullptr;
		for (const Record* r : rows)
			if (r->seq == m_selectedSeq) selected = r;

		float detailHeight = selected ? ImGui::GetContentRegionAvail().y * 0.4f : 0.0f;

		if (ImGui::BeginTable("##EventLog", 5, ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_ScrollY
			| ImGuiTableFlags_BordersInnerV, ImVec2(0, -detailHeight)))
		{
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableSetupColumn("Seq", ImGuiTableColumnFlags_WidthFixed, 50);
			ImGui::TableSetupColumn("Time", ImGuiTableColumnFlags_WidthFixed, 85);
			ImGui::TableSetupColumn("Dir", ImGuiTableColumnFlags_WidthFixed, 35);
			ImGui::TableSetupColumn("Kind / Name", ImGuiTableColumnFlags_WidthFixed, 230);
			ImGui::TableSetupColumn("Payload", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableHeadersRow();

			ImGuiListClipper clipper;
			clipper.Begin(static_cast<int>(rows.size()));
			while (clipper.Step())
			{
				for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; ++i)
				{
					const Record& r = *rows[i];
					ImGui::TableNextRow();
					ImGui::TableNextColumn();
					ImGui::PushID(static_cast<int>(r.seq));
					if (ImGui::Selectable(fmt::format("{}", r.seq).c_str(), r.seq == m_selectedSeq, ImGuiSelectableFlags_SpanAllColumns))
						m_selectedSeq = r.seq == m_selectedSeq ? 0 : r.seq;
					ImGui::PopID();
					ImGui::TableNextColumn(); ImGui::TextUnformatted(FormatTime(r.time).c_str());
					ImGui::TableNextColumn(); ImGui::TextColored(DirectionColor(r.direction), "%s", DirectionLabel(r.direction));
					ImGui::TableNextColumn(); ImGui::Text("%s %s", KindName(r.kind), r.name.c_str());
					ImGui::TableNextColumn(); ImGui::TextUnformatted(r.summary.c_str());
				}
			}

			if (m_autoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY() - 20)
				ImGui::SetScrollHereY(1.0f);

			ImGui::EndTable();
		}

		if (selected)
		{
			ImGui::BeginChild("##detail", ImVec2(0, 0), ImGuiChildFlags_Borders);
			DrawRecordDetail(*selected);
			ImGui::EndChild();
		}
	}

	static void DrawKeyValueTable(const char* id, const std::vector<KeyValue>& kv)
	{
		if (ImGui::BeginTable(id, 2, ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersInnerV))
		{
			ImGui::TableSetupColumn("Key", ImGuiTableColumnFlags_WidthFixed, 300);
			ImGui::TableSetupColumn("Value", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableHeadersRow();
			for (const KeyValue& item : kv)
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::TextUnformatted(item.key.c_str());
				ImGui::TableNextColumn(); ImGui::TextWrapped("%s", item.value.c_str());
			}
			ImGui::EndTable();
		}
	}

	static void DrawRecordKeyTable(const char* id, const std::vector<KeyValue>& kv)
	{
		static bool changedOnly = false;
		ImGui::Checkbox("Changed only", &changedOnly);

		if (ImGui::BeginTable(id, 3, ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersInnerV))
		{
			ImGui::TableSetupColumn("Key", ImGuiTableColumnFlags_WidthFixed, 300);
			ImGui::TableSetupColumn("Value", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupColumn("Previous", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableHeadersRow();
			for (const KeyValue& item : kv)
			{
				if (changedOnly && !item.changed)
					continue;
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::TextUnformatted(item.key.c_str());
				ImGui::TableNextColumn();
				if (item.changed)
					ImGui::TextColored(ImVec4(0.4f, 1.0f, 0.4f, 1.0f), "%s", item.value.c_str());
				else
					ImGui::TextDisabled("%s", item.value.c_str());
				ImGui::TableNextColumn();
				if (!item.known)
					ImGui::TextDisabled("(new)");
				else if (item.changed)
					ImGui::TextWrapped("%s", item.previous.c_str());
				else
					ImGui::TextDisabled("(same)");
			}
			ImGui::EndTable();
		}
	}

	static void DrawJsEventTable(const char* id, const std::vector<JsEvent>& events)
	{
		if (ImGui::BeginTable(id, JS_EVENT_FIELDS, ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersInnerV))
		{
			for (const char* col : JS_EVENT_FIELD_NAMES)
				ImGui::TableSetupColumn(col);
			ImGui::TableHeadersRow();
			for (const JsEvent& e : events)
			{
				ImGui::TableNextRow();
				for (const auto* f : EventFields(e))
				{
					ImGui::TableNextColumn();
					ImGui::TextUnformatted(f->c_str());
				}
			}
			ImGui::EndTable();
		}
	}

	static void DrawRecordDetail(const Record& r)
	{
		ImGui::TextColored(DirectionColor(r.direction), "#%llu %s %s %s  %s", r.seq, DirectionLabel(r.direction),
			KindName(r.kind), r.name.c_str(), FormatTime(r.time).c_str());

		if (ImGui::SmallButton("Copy raw"))
			ImGui::SetClipboardText(FormatTokens(r.tokens).c_str());

		if (!r.events.empty() && ImGui::CollapsingHeader(fmt::format("JS events ({})###ev", r.events.size()).c_str(), ImGuiTreeNodeFlags_DefaultOpen))
			DrawJsEventTable("##detailEvents", r.events);

		if (!r.kv.empty() && ImGui::CollapsingHeader(fmt::format("Model keys ({}, {} net changes)###kv", r.kv.size(), r.changedKeys).c_str(), ImGuiTreeNodeFlags_DefaultOpen))
			DrawRecordKeyTable("##detailKv", r.kv);

		if (ImGui::CollapsingHeader("Raw", r.kv.empty() && r.events.empty() ? ImGuiTreeNodeFlags_DefaultOpen : 0))
			ImGui::TextWrapped("%s", FormatTokens(r.tokens).c_str());
	}

	//------------------------------------------------------------------------
	// JS Events: every event crossing the boundary, both directions

	ImGuiTextFilter m_eventFilter;
	std::string m_eventWindow;

	void DrawJsEvents()
	{
		if (ImGui::BeginCombo("Window", m_eventWindow.empty() ? "(all)" : m_eventWindow.c_str(), ImGuiComboFlags_HeightLarge))
		{
			if (ImGui::Selectable("(all)", m_eventWindow.empty()))
				m_eventWindow.clear();
			for (const auto& [window, count] : s_store.eventsByWindow)
				if (ImGui::Selectable(fmt::format("{} ({})", window, count).c_str(), window == m_eventWindow))
					m_eventWindow = window;
			ImGui::EndCombo();
		}
		ImGui::SameLine();
		m_eventFilter.Draw("Filter##events", 250);

		std::vector<const EventRow*> rows;
		for (const EventRow& row : s_store.events)
		{
			if (!m_eventWindow.empty() && row.event.dispatch != m_eventWindow)
				continue;
			if (m_eventFilter.IsActive() && !m_eventFilter.PassFilter(row.event.sender.c_str())
				&& !m_eventFilter.PassFilter(row.event.message.c_str()) && !m_eventFilter.PassFilter(row.event.params.c_str()))
				continue;
			rows.push_back(&row);
		}

		if (ImGui::BeginTable("##JsEvents", 3 + JS_EVENT_FIELDS, ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_ScrollY
			| ImGuiTableFlags_BordersInnerV))
		{
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableSetupColumn("Seq", ImGuiTableColumnFlags_WidthFixed, 50);
			ImGui::TableSetupColumn("Time", ImGuiTableColumnFlags_WidthFixed, 85);
			ImGui::TableSetupColumn("Dir", ImGuiTableColumnFlags_WidthFixed, 35);
			for (const char* col : JS_EVENT_FIELD_NAMES)
				ImGui::TableSetupColumn(col);
			ImGui::TableHeadersRow();

			ImGuiListClipper clipper;
			clipper.Begin(static_cast<int>(rows.size()));
			while (clipper.Step())
			{
				for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; ++i)
				{
					const EventRow& row = *rows[i];
					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("%llu", row.seq);
					ImGui::TableNextColumn(); ImGui::TextUnformatted(FormatTime(row.time).c_str());
					ImGui::TableNextColumn(); ImGui::TextColored(DirectionColor(row.direction), "%s", DirectionLabel(row.direction));
					const JsEvent& e = row.event;
					for (const auto* f : EventFields(e))
					{
						ImGui::TableNextColumn();
						ImGui::TextUnformatted(f->c_str());
					}
				}
			}
			if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY() - 20)
				ImGui::SetScrollHereY(1.0f);
			ImGui::EndTable();
		}
	}

	//------------------------------------------------------------------------
	// Model: every key seen on the wire, as a tree split on '.'

	ImGuiTextFilter m_modelFilter;
	bool m_modelTree = true;
	float m_highlightSeconds = 1.5f;

	struct ModelNode
	{
		std::map<std::string, ModelNode> children;
		const std::pair<const std::string, ModelValue>* leaf = nullptr;
		uint32_t updates = 0;
	};

	void DrawModelValue(const std::pair<const std::string, ModelValue>& item, std::string_view label)
	{
		const ModelValue& mv = item.second;
		float age = std::chrono::duration<float>(std::chrono::system_clock::now() - mv.time).count();

		ImGui::TableNextRow();
		ImGui::TableNextColumn();
		ImGui::TreeNodeEx(item.first.c_str(), ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen | ImGuiTreeNodeFlags_SpanFullWidth,
			"%.*s", (int)label.size(), label.data());
		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("%s", item.first.c_str());
		if (ImGui::BeginPopupContextItem(item.first.c_str()))
		{
			if (ImGui::MenuItem("Copy key")) ImGui::SetClipboardText(item.first.c_str());
			if (ImGui::MenuItem("Copy value")) ImGui::SetClipboardText(mv.value.c_str());
			ImGui::EndPopup();
		}

		ImGui::TableNextColumn();
		if (age < m_highlightSeconds)
			ImGui::TextColored(ImVec4(0.4f, 1.0f, 0.4f, 1.0f), "%s", mv.value.c_str());
		else
			ImGui::TextUnformatted(mv.value.c_str());
		ImGui::TableNextColumn(); ImGui::TextColored(DirectionColor(mv.direction), "%s", DirectionLabel(mv.direction));
		ImGui::TableNextColumn(); ImGui::Text("%u", mv.updates);
		ImGui::TableNextColumn(); ImGui::TextUnformatted(FormatTime(mv.time).c_str());
	}

	void DrawModelNode(const std::string& name, const ModelNode& node)
	{
		if (node.leaf && node.children.empty())
		{
			DrawModelValue(*node.leaf, name);
			return;
		}

		ImGui::TableNextRow();
		ImGui::TableNextColumn();
		bool open = ImGui::TreeNodeEx(name.c_str(), ImGuiTreeNodeFlags_SpanFullWidth);
		ImGui::TableNextColumn(); ImGui::TextDisabled("%d", (int)node.children.size());
		ImGui::TableNextColumn();
		ImGui::TableNextColumn(); ImGui::TextDisabled("%u", node.updates);
		ImGui::TableNextColumn();
		if (open)
		{
			if (node.leaf)
				DrawModelValue(*node.leaf, "(value)");
			for (const auto& [childName, child] : node.children)
				DrawModelNode(childName, child);
			ImGui::TreePop();
		}
	}

	void DrawModel()
	{
		ImGui::Checkbox("Tree", &m_modelTree);
		ImGui::SameLine();
		ImGui::BeginDisabled(!IsLiveModelAvailable());
		ImGui::Checkbox("Live store", &s_useLiveModel);
		ImGui::EndDisabled();
		ImGui::SameLine();
		ImGui::TextDisabled("%d keys", (int)GetModel().size());
		ImGui::SameLine();
		m_modelFilter.Draw("Filter##model", 250);
		ImGui::SameLine();
		ImGui::TextDisabled("(?)");
		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("Live store: EQ's model (g_pGF->model.values). Otherwise: keys seen on the wire.\n"
				"Dir/Updates/Last come from the wire and need the monitor on.\n"
				"Keys are '<itemPath>.<Property>'; the tree splits them on '.'.");

		if (!ImGui::BeginTable("##Model", 5, ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_ScrollY
			| ImGuiTableFlags_BordersInnerV))
			return;

		ImGui::TableSetupScrollFreeze(0, 1);
		ImGui::TableSetupColumn("Key", ImGuiTableColumnFlags_WidthFixed, 320);
		ImGui::TableSetupColumn("Value", ImGuiTableColumnFlags_WidthStretch);
		ImGui::TableSetupColumn("Dir", ImGuiTableColumnFlags_WidthFixed, 35);
		ImGui::TableSetupColumn("Updates", ImGuiTableColumnFlags_WidthFixed, 55);
		ImGui::TableSetupColumn("Last", ImGuiTableColumnFlags_WidthFixed, 85);
		ImGui::TableHeadersRow();

		if (m_modelTree)
		{
			ModelNode root;
			for (const auto& item : GetModel())
			{
				if (m_modelFilter.IsActive() && !m_modelFilter.PassFilter(item.first.c_str()) && !m_modelFilter.PassFilter(item.second.value.c_str()))
					continue;

				ModelNode* node = &root;
				for (auto part : split_view(item.first, '.'))
				{
					node = &node->children[std::string(part)];
					node->updates += item.second.updates;
				}
				node->leaf = &item;
			}
			for (const auto& [name, child] : root.children)
				DrawModelNode(name, child);
		}
		else
		{
			for (const auto& item : GetModel())
			{
				if (m_modelFilter.IsActive() && !m_modelFilter.PassFilter(item.first.c_str()) && !m_modelFilter.PassFilter(item.second.value.c_str()))
					continue;
				DrawModelValue(item, item.first);
			}
		}

		ImGui::EndTable();
	}

	//------------------------------------------------------------------------
	// Statistics

	static void DrawCountTable(const char* id, const auto& counts, int limit)
	{
		std::vector<std::pair<std::string, uint32_t>> sorted(counts.begin(), counts.end());
		std::sort(sorted.begin(), sorted.end(), [](const auto& a, const auto& b) { return a.second > b.second; });

		if (ImGui::BeginTable(id, 2, ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersInnerV | ImGuiTableFlags_ScrollY, ImVec2(0, 250)))
		{
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupColumn("Count", ImGuiTableColumnFlags_WidthFixed, 60);
			ImGui::TableHeadersRow();
			for (int i = 0; i < (int)sorted.size() && i < limit; ++i)
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::TextUnformatted(sorted[i].first.c_str());
				ImGui::TableNextColumn(); ImGui::Text("%u", sorted[i].second);
			}
			ImGui::EndTable();
		}
	}

	void DrawStatistics()
	{
		const auto& seconds = s_store.seconds;
		if (!seconds.empty() && ImPlot::BeginPlot("Traffic per second", ImVec2(-1, 220)))
		{
			std::vector<float> xs, toUI, fromUI, keysToUI, keysFromUI, events;
			int64_t now = seconds.back().second;
			for (const SecondBucket& b : seconds)
			{
				xs.push_back(static_cast<float>(b.second - now));
				toUI.push_back(b.toUI); fromUI.push_back(b.fromUI);
				keysToUI.push_back(b.keysToUI); keysFromUI.push_back(b.keysFromUI);
				events.push_back(b.events);
			}
			int n = static_cast<int>(xs.size());
			ImPlot::SetupAxes("seconds", "count", ImPlotAxisFlags_AutoFit, ImPlotAxisFlags_AutoFit);
			ImPlot::PlotLine("calls ->UI", xs.data(), toUI.data(), n);
			ImPlot::PlotLine("calls <-UI", xs.data(), fromUI.data(), n);
			ImPlot::PlotLine("keys ->UI", xs.data(), keysToUI.data(), n);
			ImPlot::PlotLine("keys <-UI", xs.data(), keysFromUI.data(), n);
			ImPlot::PlotLine("JS events", xs.data(), events.data(), n);
			ImPlot::EndPlot();
		}

		if (ImGui::BeginTable("##statsLayout", 3, ImGuiTableFlags_SizingStretchSame))
		{
			ImGui::TableNextColumn();
			ImGui::TextUnformatted("Key updates by window");
			DrawCountTable("##keysByWindow", s_store.keysByWindow, 200);

			ImGui::TableNextColumn();
			ImGui::TextUnformatted("JS events by window");
			DrawCountTable("##eventsByWindow", s_store.eventsByWindow, 200);

			ImGui::TableNextColumn();
			ImGui::TextUnformatted("JS events by message");
			DrawCountTable("##eventsByMessage", s_store.eventsByMessage, 200);
			ImGui::EndTable();
		}

		std::unordered_map<std::string, uint32_t> hotKeys;
		for (const auto& [key, mv] : s_store.model)
			hotKeys[key] = mv.updates;
		ImGui::TextUnformatted("Most updated keys");
		DrawCountTable("##hotKeys", hotKeys, 100);

		if (ImGui::CollapsingHeader("Known bindings"))
		{
			for (const std::string& name : GetKnownHandlerNames())
				ImGui::BulletText("%s", name.c_str());
		}
	}

	//------------------------------------------------------------------------
	CGFScreenWnd* m_selectedWindow = nullptr;
	ImGuiTextFilter m_windowFilter;

	void DrawWindows();
	void DrawWindowDetail(CGFScreenWnd* wnd);
	void DrawEngineState();
	void DrawDebugTools();
};

static GameFaceInspector* s_inspector = nullptr;

//============================================================================
// Windows: every CGFScreenWnd, its components, and the model keys/events seen for them

static std::vector<CGFScreenWnd*> GetGameFaceWindows()
{
	std::vector<CGFScreenWnd*> windows;
	if (!pWndMgr || GetGameState() == GAMESTATE_PRECHARSELECT)
		return windows;

	for (CXWnd* wnd : pWndMgr->ParentAndContextMenuWindows)
	{
		if (wnd && string_equals(wnd->GetWndClassName(), "GFScreenWnd"))
			windows.push_back(static_cast<CGFScreenWnd*>(wnd));
	}

	std::sort(windows.begin(), windows.end(), [](CGFScreenWnd* a, CGFScreenWnd* b) {
		return ci_less{}(a->WindowComponent.itemPath, b->WindowComponent.itemPath);
	});
	return windows;
}

static size_t CountModelKeys(std::string_view prefix)
{
	const auto& model = GetModel();
	size_t count = 0;
	for (auto it = model.lower_bound(std::string(prefix)); it != model.end() && it->first.starts_with(prefix); ++it)
		++count;
	return count;
}

void GameFaceInspector::DrawWindows()
{
	std::vector<CGFScreenWnd*> windows = GetGameFaceWindows();
	if (std::find(windows.begin(), windows.end(), m_selectedWindow) == windows.end())
		m_selectedWindow = nullptr;

	m_windowFilter.Draw("Filter##windows", 200);

	if (ImGui::BeginTable("##windowsLayout", 2, ImGuiTableFlags_Resizable | ImGuiTableFlags_BordersInnerV))
	{
		ImGui::TableSetupColumn("list", ImGuiTableColumnFlags_WidthFixed, 260);
		ImGui::TableSetupColumn("detail", ImGuiTableColumnFlags_WidthStretch);
		ImGui::TableNextColumn();

		if (ImGui::BeginTable("##gfWindows", 4, ImGuiTableFlags_RowBg | ImGuiTableFlags_ScrollY | ImGuiTableFlags_BordersInnerV))
		{
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableSetupColumn("Window", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupColumn("Vis", ImGuiTableColumnFlags_WidthFixed, 25);
			ImGui::TableSetupColumn("Comp", ImGuiTableColumnFlags_WidthFixed, 35);
			ImGui::TableSetupColumn("Keys", ImGuiTableColumnFlags_WidthFixed, 35);
			ImGui::TableHeadersRow();

			for (CGFScreenWnd* wnd : windows)
			{
				const eqstd::string& path = wnd->WindowComponent.itemPath;
				if (m_windowFilter.IsActive() && !m_windowFilter.PassFilter(path.c_str()))
					continue;

				ImGui::TableNextRow();
				ImGui::TableNextColumn();
				if (ImGui::Selectable(path.empty() ? "(unnamed)" : path.c_str(), wnd == m_selectedWindow, ImGuiSelectableFlags_SpanAllColumns))
					m_selectedWindow = wnd;
				ImGui::TableNextColumn(); ImGui::TextUnformatted(wnd->IsVisible() ? ICON_FA_EYE : "");
				ImGui::TableNextColumn(); ImGui::Text("%d", (int)wnd->ChildComponents.size());
				ImGui::TableNextColumn(); ImGui::Text("%d", (int)CountModelKeys(wnd->WindowComponent.modelPrefix));
			}
			ImGui::EndTable();
		}

		ImGui::TableNextColumn();
		if (m_selectedWindow)
		{
			ImGui::BeginChild("##windowDetail");
			DrawWindowDetail(m_selectedWindow);
			ImGui::EndChild();
		}
		else
		{
			ImGui::TextDisabled("Select a window. Model keys and events need the monitor on.");
		}
		ImGui::EndTable();
	}
}

void GameFaceInspector::DrawWindowDetail(CGFScreenWnd* wnd)
{
	const UIScreenComponent& screen = wnd->WindowComponent;
	ImGui::Text("%s", screen.itemPath.c_str());
	ImGui::SameLine();
	if (ImGui::SmallButton("Window Inspector"))
		DeveloperTools_WindowInspector_Show(wnd);
	ImGui::TextDisabled("model prefix '%s'  opacity %d  %s", screen.modelPrefix.c_str(), (int)screen.opacity,
		wnd->IsVisible() ? "visible" : "hidden");

	if (ImGui::CollapsingHeader(fmt::format("Components ({})###components", wnd->ChildComponents.size()).c_str(), ImGuiTreeNodeFlags_DefaultOpen))
	{
		std::vector<std::pair<std::string, UIComponent*>> components;
		for (auto& [name, component] : wnd->ChildComponents)
			components.emplace_back(name.c_str(), component);
		std::sort(components.begin(), components.end(), [](const auto& a, const auto& b) { return a.first < b.first; });

		if (ImGui::BeginTable("##components", 5, ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersInnerV))
		{
			ImGui::TableSetupColumn("Item Path", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthFixed, 80);
			ImGui::TableSetupColumn("Classic Window", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupColumn("Keys", ImGuiTableColumnFlags_WidthFixed, 35);
			ImGui::TableSetupColumn("Tooltip", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableHeadersRow();

			for (auto& [path, component] : components)
			{
				if (!component)
					continue;
				ImGui::TableNextRow();
				ImGui::TableNextColumn();
				bool open = ImGui::TreeNodeEx(path.c_str(), ImGuiTreeNodeFlags_SpanFullWidth, "%s", path.c_str());
				ImGui::TableNextColumn(); ImGui::TextUnformatted(component->GetTypeName().c_str());
				ImGui::TableNextColumn();
				if (component->target)
				{
					if (ImGui::SmallButton(fmt::format("{}##{}", component->target->GetXMLNameSv(), path).c_str()))
						DeveloperTools_WindowInspector_Show(component->target);
				}
				ImGui::TableNextColumn(); ImGui::Text("%d", (int)CountModelKeys(component->modelPrefix));
				ImGui::TableNextColumn(); ImGui::TextUnformatted(component->tooltip.c_str());

				if (open)
				{
					std::string_view prefix = component->modelPrefix;
					const auto& model = GetModel();
					for (auto it = model.lower_bound(std::string(prefix)); it != model.end() && it->first.starts_with(prefix); ++it)
					{
						ImGui::TableNextRow();
						ImGui::TableNextColumn(); ImGui::TextDisabled("  .%s", it->first.c_str() + prefix.size());
						ImGui::TableNextColumn();
						ImGui::TableNextColumn(); ImGui::TextWrapped("%s", it->second.value.c_str());
						ImGui::TableNextColumn(); ImGui::TextDisabled("%u", it->second.updates);
						ImGui::TableNextColumn(); ImGui::TextColored(DirectionColor(it->second.direction), "%s", DirectionLabel(it->second.direction));
					}
					ImGui::TreePop();
				}
			}
			ImGui::EndTable();
		}
	}

	if (ImGui::CollapsingHeader("Window keys"))
	{
		std::vector<KeyValue> kv;
		std::string_view prefix = screen.modelPrefix;
		const auto& model = GetModel();
		for (auto it = model.lower_bound(std::string(prefix)); it != model.end() && it->first.starts_with(prefix); ++it)
			if (it->first.find('.', prefix.size()) == std::string::npos)
				kv.push_back({ it->first, it->second.value });
		DrawKeyValueTable("##windowKeys", kv);
	}

	if (ImGui::CollapsingHeader("Recent JS events"))
	{
		std::vector<JsEvent> events;
		std::string name = screen.itemPath.c_str();
		for (auto it = s_store.events.rbegin(); it != s_store.events.rend() && events.size() < 200; ++it)
			if (it->event.dispatch == name)
				events.push_back(it->event);
		DrawJsEventTable("##windowEvents", events);
	}
}

//============================================================================
// Engine state

namespace engine {

static void Row(const char* label, const char* fmt, ...)
{
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
	ImGui::TextUnformatted(label);
	ImGui::TableNextColumn();
	va_list args;
	va_start(args, fmt);
	ImGui::TextV(fmt, args);
	va_end(args);
}

static bool BeginProps(const char* id)
{
	if (!ImGui::BeginTable(id, 2, ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersInnerV | ImGuiTableFlags_Resizable))
		return false;
	ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed, 200);
	ImGui::TableSetupColumn("Value", ImGuiTableColumnFlags_WidthStretch);
	return true;
}

static const char* UIModeName(uint32_t mode)
{
	switch (mode)
	{
	case GF::UIMode_InGame: return "InGame (index.html)";
	case GF::UIMode_CharacterSelect: return "CharacterSelect (index_choose.html)";
	case GF::UIMode_CharacterCreate: return "CharacterCreate (index_create.html)";
	case GF::UIMode_None: return "None";
	default: return "?";
	}
}

static void DrawJsEventQueue(const char* label, const eqstd::vector<GFJsEvent>& events)
{
	ImGui::Text("%s: %d", label, (int)events.size());
	if (events.empty())
		return;

	if (ImGui::BeginTable(label, JS_EVENT_FIELDS, ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersInnerV | ImGuiTableFlags_Resizable))
	{
		for (const char* col : JS_EVENT_FIELD_NAMES)
			ImGui::TableSetupColumn(col);
		ImGui::TableHeadersRow();
		for (const GFJsEvent& e : events)
		{
			ImGui::TableNextRow();
			for (const auto* f : EventFields(e))
			{
				ImGui::TableNextColumn();
				ImGui::TextUnformatted(f->c_str());
			}
		}
		ImGui::EndTable();
	}
}

template <typename Map>
static void DrawNameIntMap(const char* id, const Map& map)
{
	std::vector<std::pair<std::string, int>> sorted;
	for (const auto& [name, value] : map)
		sorted.emplace_back(name.c_str(), value);
	std::sort(sorted.begin(), sorted.end(), [](const auto& a, const auto& b) { return a.second < b.second; });

	if (ImGui::BeginTable(id, 2, ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersInnerV | ImGuiTableFlags_ScrollY, ImVec2(0, 200)))
	{
		ImGui::TableSetupScrollFreeze(0, 1);
		ImGui::TableSetupColumn("Name");
		ImGui::TableSetupColumn("Value", ImGuiTableColumnFlags_WidthFixed, 60);
		ImGui::TableHeadersRow();
		for (const auto& [name, value] : sorted)
		{
			ImGui::TableNextRow();
			ImGui::TableNextColumn(); ImGui::TextUnformatted(name.c_str());
			ImGui::TableNextColumn(); ImGui::Text("%d", value);
		}
		ImGui::EndTable();
	}
}

static void DrawManager()
{
	GF::Manager* mgr = pGF.get();
	if (!mgr)
	{
		ImGui::TextDisabled("g_pGF is not set");
		return;
	}

	const GF::GFSync& sync = mgr->sync;
	if (BeginProps("##sync"))
	{
		Row("GF manager", "%p", mgr);
		Row("Bindings initialized", "%s", sync.bindingsInitialized ? "yes" : "no");
		Row("JS ready", "%d", sync.cppJsReady);
		Row("JS news received", "%d", sync.jsNewsReceived);
		Row("Model keys", "%d", (int)mgr->model.values.size());
		Row("Pending -> JS", "%d pairs", (int)mgr->model.pendingToJS.size());
		Row("Pending <- JS", "%d pairs", (int)mgr->model.pendingFromJS.size());
		Row("Keys sent each frame", "%d", (int)mgr->model.keysSentEachFrame.size());
		Row("Registered windows", "%d", (int)mgr->windowsByName.size());
		ImGui::EndTable();
	}

	if (ImGui::TreeNode("Event queues"))
	{
		DrawJsEventQueue("Incoming (from JS)", sync.incomingEvents);
		DrawJsEventQueue("Dispatching", sync.dispatchingEvents);
		DrawJsEventQueue("Outgoing (to JS)", sync.outgoingEvents);
		ImGui::TextDisabled("Queues are normally empty between frames; the monitor shows the traffic.");
		ImGui::TreePop();
	}

	if (ImGui::TreeNode("Keys sent each frame"))
	{
		for (const eqstd::string& key : mgr->model.keysSentEachFrame)
		{
			auto it = mgr->model.values.find(key);
			ImGui::BulletText("%s = %s", key.c_str(), it != mgr->model.values.end() ? it->second.c_str() : "");
		}
		ImGui::TreePop();
	}

	if (ImGui::TreeNode("Registered windows"))
	{
		std::vector<std::pair<std::string, CSidlScreenWnd*>> windows;
		for (const auto& [name, wnd] : mgr->windowsByName)
			windows.emplace_back(name.c_str(), wnd);
		std::sort(windows.begin(), windows.end());
		for (const auto& [name, wnd] : windows)
		{
			ImGui::PushID(wnd);
			if (ImGui::SmallButton(ICON_FA_SEARCH))
				DeveloperTools_WindowInspector_Show(wnd);
			ImGui::SameLine();
			ImGui::Text("%s  %p %s", name.c_str(), wnd, wnd && wnd->IsVisible() ? "(visible)" : "");
			ImGui::PopID();
		}
		ImGui::TreePop();
	}

	if (ImGui::TreeNode("Type tables"))
	{
		ImGui::TextUnformatted("Gauge types (GAUGETYPE_*)");
		DrawNameIntMap("##gaugeTypes", mgr->gaugeTypes);
		ImGui::TextUnformatted("Label types (LABELTYPE_*)");
		DrawNameIntMap("##labelTypes", mgr->labelTypes);
		ImGui::TextUnformatted("Event -> window notification");
		DrawNameIntMap("##eventTypes", mgr->eventTypes);
		ImGui::TreePop();
	}
}

static void DrawSkin(const char* label, const GF::Skin& skin)
{
	if (!ImGui::TreeNode(label, "%s: %s (%d textures, %d animations)", label, skin.rootPath.c_str(),
		(int)skin.textures.size(), (int)skin.animations.size()))
		return;

	static ImGuiTextFilter filter;
	filter.Draw("Filter##skin", 200);

	if (ImGui::BeginTable("##textures", 4, ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersInnerV | ImGuiTableFlags_Resizable
		| ImGuiTableFlags_ScrollY, ImVec2(0, 300)))
	{
		ImGui::TableSetupScrollFreeze(0, 1);
		ImGui::TableSetupColumn("Texture / sub-image", ImGuiTableColumnFlags_WidthStretch);
		ImGui::TableSetupColumn("Image", ImGuiTableColumnFlags_WidthStretch);
		ImGui::TableSetupColumn("Size", ImGuiTableColumnFlags_WidthFixed, 90);
		ImGui::TableSetupColumn("Rect", ImGuiTableColumnFlags_WidthFixed, 140);
		ImGui::TableHeadersRow();

		for (const auto& [name, texture] : skin.textures)
		{
			bool any = !filter.IsActive() || filter.PassFilter(name.c_str());
			if (!any)
				for (const GF::UIAtlasSubImage& sub : texture.subImages)
					if (filter.PassFilter(sub.name.c_str())) { any = true; break; }
			if (!any)
				continue;

			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			bool open = ImGui::TreeNodeEx(name.c_str(), ImGuiTreeNodeFlags_SpanFullWidth, "%s (%d)", name.c_str(), (int)texture.subImages.size());
			ImGui::TableNextColumn(); ImGui::TextUnformatted(texture.imagePath.c_str());
			ImGui::TableNextColumn(); ImGui::Text("%ux%u", texture.width, texture.height);
			ImGui::TableNextColumn();
			if (open)
			{
				for (const GF::UIAtlasSubImage& sub : texture.subImages)
				{
					if (filter.IsActive() && !filter.PassFilter(sub.name.c_str()) && !filter.PassFilter(name.c_str()))
						continue;
					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::TextUnformatted(sub.name.c_str());
					ImGui::TableNextColumn();
					ImGui::TableNextColumn(); ImGui::Text("%dx%d", sub.width, sub.height);
					ImGui::TableNextColumn(); ImGui::Text("%d,%d", sub.left, sub.top);
				}
				ImGui::TreePop();
			}
		}
		ImGui::EndTable();
	}

	if (!skin.animations.empty() && ImGui::TreeNode("Animations"))
	{
		for (const auto& [name, anim] : skin.animations)
		{
			if (ImGui::TreeNode(name.c_str(), "%s: %d frames%s%s", name.c_str(), (int)anim.frames.size(),
				anim.cycle ? ", cycle" : "", anim.grid ? ", grid" : ""))
			{
				if (anim.grid)
					ImGui::Text("Cells %dx%d %s", anim.cellWidth, anim.cellHeight, anim.vertical ? "(vertical)" : "");
				for (const GF::UIAnimationFrame& frame : anim.frames)
					ImGui::BulletText("%s  %d,%d %dx%d  %d ms", frame.texture.c_str(), frame.left, frame.top, frame.width, frame.height, frame.duration);
				ImGui::TreePop();
			}
		}
		ImGui::TreePop();
	}

	ImGui::TreePop();
}

static void DrawResources(GF::ViewListener* gf)
{
	const GF::AsyncResourceHandler& res = gf->resourceHandler;

	if (BeginProps("##resources"))
	{
		Row("Atlas images", "%d", (int)res.atlasImages.size());
		Row("Atlas textures", "%d", (int)res.textures.size());
		Row("Render target images", "%d", (int)res.renderTargetImages.size());
		Row("Next image handle", "%u", res.nextImageHandle);
		Row("Render target refs", "%d", (int)gf->renderTargetRefs.size());
		Row("Pending work jobs", "%d", (int)gf->pendingWork.size());
		Row("HTML forbidden names", "%d", (int)res.htmlParser.forbiddenNames.size());
		ImGui::EndTable();
	}

	if (ImGui::TreeNode("Atlas images (coui:// paths served from atlases)"))
	{
		static ImGuiTextFilter filter;
		filter.Draw("Filter##atlasImages", 200);

		std::vector<std::pair<std::string, const GF::UserImageData*>> images;
		for (const auto& [path, image] : res.atlasImages)
			if (!filter.IsActive() || filter.PassFilter(path.c_str()))
				images.emplace_back(path.c_str(), &image);
		std::sort(images.begin(), images.end(), [](const auto& a, const auto& b) { return a.first < b.first; });

		if (ImGui::BeginTable("##atlasImages", 4, ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersInnerV | ImGuiTableFlags_Resizable
			| ImGuiTableFlags_ScrollY, ImVec2(0, 300)))
		{
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableSetupColumn("Path", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupColumn("Texture", ImGuiTableColumnFlags_WidthFixed, 90);
			ImGui::TableSetupColumn("Content rect", ImGuiTableColumnFlags_WidthFixed, 150);
			ImGui::TableSetupColumn("Texture id", ImGuiTableColumnFlags_WidthFixed, 80);
			ImGui::TableHeadersRow();

			ImGuiListClipper clipper;
			clipper.Begin(static_cast<int>(images.size()));
			while (clipper.Step())
			{
				for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; ++i)
				{
					const GF::UserImageData& image = *images[i].second;
					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::TextUnformatted(images[i].first.c_str());
					ImGui::TableNextColumn(); ImGui::Text("%ux%u", image.width, image.height);
					ImGui::TableNextColumn(); ImGui::Text("%u,%u %ux%u", image.contentRectX, image.contentRectY, image.contentRectWidth, image.contentRectHeight);
					ImGui::TableNextColumn(); ImGui::Text("%llu", image.textureId);
				}
			}
			ImGui::EndTable();
		}
		ImGui::TreePop();
	}

	if (ImGui::TreeNode("Render targets"))
	{
		for (const auto& [kind, image] : res.renderTargetImages)
			ImGui::BulletText("kind %u%s: %ux%u handle %u texture %llu", kind, kind == GF::UserImageKind_ObjectView ? " (object_view)" : "",
				image.width, image.height, image.imageHandle, image.textureId);
		for (const auto& [kind, ref] : gf->renderTargetRefs)
			ImGui::BulletText("ref kind %u: handle %u, %d refs", kind, ref.imageHandle, ref.refCount);
		ImGui::TreePop();
	}

	if (ImGui::TreeNode("File system"))
	{
		ImGui::TextUnformatted("Path redirects (tried in order)");
		for (const GF::FileSystem::PathRedirect& redirect : gf->fileSystem.redirects)
			ImGui::BulletText("'%s' -> '%s'", redirect.from.c_str(), redirect.to.c_str());
		ImGui::TextUnformatted("Checksummed files");
		for (const auto& [file, checksum] : gf->fileSystem.checksums)
			ImGui::BulletText("%s  %08X", file.c_str(), checksum);
		ImGui::TreePop();
	}

	if (ImGui::TreeNode("HTML parser forbidden names"))
	{
		std::vector<std::string> names;
		for (const eqstd::string& name : res.htmlParser.forbiddenNames)
			names.emplace_back(name.c_str());
		std::sort(names.begin(), names.end());
		ImGui::TextWrapped("%s", fmt::format("{}", fmt::join(names, ", ")).c_str());
		ImGui::TreePop();
	}
}

} // namespace engine

void GameFaceInspector::DrawEngineState()
{
	using namespace engine;

	GF::ViewListener* gf = pGFViewListener.get();
	if (!gf)
	{
		ImGui::TextUnformatted("GameFace is not running (it is created on world entry).");
		return;
	}

	if (ImGui::CollapsingHeader("View", ImGuiTreeNodeFlags_DefaultOpen) && BeginProps("##view"))
	{
		Row("ViewListener", "%p", gf);
		Row("Library / System", "%p / %p", gf->pLibrary, gf->pSystem);
		Row("View / ViewRenderer", "%p / %p", gf->pView, gf->pViewRenderer);
		Row("SystemRenderer", "%p", gf->pSystemRenderer);
		Row("UI mode", "%u %s", gf->uiMode, UIModeName(gf->uiMode));
		Row("Base skin", "%s%s", gf->baseSkinPath.c_str(), gf->reloadBaseSkin ? " (reload pending)" : "");
		Row("Skin", "%s%s", gf->skinName.c_str(), gf->reloadPending ? " (reload pending)" : "");
		Row("UI scale", "%.2f", gf->uiScale);
		Row("Last advance frame", "%u", gf->lastAdvanceResult);
		Row("Last tick", "%llu", gf->lastTickTime);
		Row("Cursor", "%d", static_cast<int>(gf->cursor));
		Row("Keyboard / mouse captured", "%s / %s", gf->keyboardCaptured ? "yes" : "no", gf->mouseCaptured ? "yes" : "no");
		Row("Bindings listener", "%p", gf->pBindingsListener);
		ImGui::EndTable();
	}

	if (ImGui::CollapsingHeader("GF manager & sync", ImGuiTreeNodeFlags_DefaultOpen))
		DrawManager();

	if (ImGui::CollapsingHeader("Skins"))
	{
		DrawSkin("Active skin", gf->activeSkin);
		DrawSkin("Base skin", gf->baseSkin);
		DrawSkin("Override skin", gf->overrideSkin);
	}

	if (ImGui::CollapsingHeader("Resources"))
		DrawResources(gf);
}

//============================================================================
// Debug tools
//
// cohtml debug tools, reached through the Library, System and View that GF::ViewListener holds. Anything
// that calls into cohtml is queued to the next pulse, so it runs on the main thread between frames.

namespace debug {

// The live view, or null when GameFace isn't running.
static View* GetView()
{
	GF::ViewListener* gf = pGFViewListener.get();
	return gf ? gf->pView : nullptr;
}

static std::filesystem::path OutputDirectory()
{
	std::filesystem::path dir = std::filesystem::path(gPathLogs) / "GameFace";
	std::error_code ec;
	std::filesystem::create_directories(dir, ec);
	return dir;
}

static std::string TimestampedName(std::string_view prefix, std::string_view ext)
{
	time_t now = time(nullptr);
	tm local;
	localtime_s(&local, &now);
	return fmt::format("{}_{:04}{:02}{:02}_{:02}{:02}{:02}{}", prefix, local.tm_year + 1900, local.tm_mon + 1, local.tm_mday,
		local.tm_hour, local.tm_min, local.tm_sec, ext);
}

static std::string s_status;

// QueueClearCaches takes a mask of cache types. Every bit set clears all of them.
static constexpr unsigned ALL_CACHES = ~0u;

//----------------------------------------------------------------------------
// Settings applied when GameFace is initialized, which happens on every world entry. We detour the exported
// Library::Initialize to set LibraryParams.LoggingSeverity before the call, and hook the returned
// Library's CreateSystem to set SystemSettings.DebuggerPort and EnableDebugger. Both structs live on EQ's
// stack, so they can be written even though cohtml takes them as const. Only applied to
// SUPPORTED_COHTML_VERSION, in case their layout changes.

// Packs a file version the way VS_FIXEDFILEINFO stores it, major in the high word.
static constexpr uint64_t FileVersion(uint16_t major, uint16_t minor, uint16_t build, uint16_t revision)
{
	return (uint64_t{ major } << 48) | (uint64_t{ minor } << 32) | (uint64_t{ build } << 16) | revision;
}

static constexpr uint64_t SUPPORTED_COHTML_VERSION = FileVersion(1, 69, 5, 2);

static bool s_remoteDebugger = false;
static int s_remoteDebuggerPort = 9444;
static int s_initLogSeverity = -1;          // -1 leaves EQ's value, which is Error
static int s_activeDebuggerPort = 0;        // port passed at the last CreateSystem, 0 = debugger off

using LibraryInitializeFn = Library* (*)(const char* license, LibraryParams* params);
static LibraryInitializeFn s_libraryInitializeTrampoline = nullptr;
static uintptr_t s_libraryInitializeAddress = 0;

using CreateSystemFn = System* (*)(Library* library, SystemSettings* settings);
static CreateSystemFn s_createSystemOriginal = nullptr;
static uintptr_t s_createSystemSlot = 0;

static HMODULE CohtmlModule()
{
	return GetModuleHandleA("cohtml.WindowsDesktop.dll");
}

static uint64_t GetModuleVersion(HMODULE module)
{
	HRSRC res = module ? FindResourceA(module, MAKEINTRESOURCEA(VS_VERSION_INFO), RT_VERSION) : nullptr;
	HGLOBAL data = res ? LoadResource(module, res) : nullptr;
	const uint8_t* bytes = data ? static_cast<const uint8_t*>(LockResource(data)) : nullptr;
	if (!bytes)
		return 0;

	DWORD size = SizeofResource(module, res);
	for (DWORD i = 0; i + sizeof(VS_FIXEDFILEINFO) <= size; i += 4)
	{
		auto info = reinterpret_cast<const VS_FIXEDFILEINFO*>(bytes + i);
		if (info->dwSignature == 0xFEEF04BD)
			return (static_cast<uint64_t>(info->dwFileVersionMS) << 32) | info->dwFileVersionLS;
	}
	return 0;
}

static bool IsSupportedCohtml()
{
	static uint64_t version = GetModuleVersion(CohtmlModule());
	return version == SUPPORTED_COHTML_VERSION;
}

static System* CreateSystem_Hook(Library* library, SystemSettings* settings)
{
	s_activeDebuggerPort = 0;
	if (s_remoteDebugger && settings && s_remoteDebuggerPort > 0 && s_remoteDebuggerPort < 65536)
	{
		settings->DebuggerPort = s_remoteDebuggerPort;
		settings->EnableDebugger = true;
		s_activeDebuggerPort = s_remoteDebuggerPort;
	}
	return s_createSystemOriginal(library, settings);
}

static Library* LibraryInitialize_Detour(const char* license, LibraryParams* params)
{
	if (params && s_initLogSeverity >= 0)
		params->LoggingSeverity = static_cast<Logging::Severity>(s_initLogSeverity);

	Library* library = s_libraryInitializeTrampoline(license, params);

	if (library && !s_createSystemSlot)
	{
		void** slot = &(*reinterpret_cast<void***>(library))[SlotOf<&Library::CreateSystem>()];
		void* original = *slot;
		void* hook = reinterpret_cast<void*>(&CreateSystem_Hook);
		if (AddPatch(reinterpret_cast<uintptr_t>(slot), reinterpret_cast<const uint8_t*>(&hook), sizeof(void*),
			reinterpret_cast<const uint8_t*>(&original), "GameFace Library::CreateSystem"))
		{
			s_createSystemOriginal = reinterpret_cast<CreateSystemFn>(original);
			s_createSystemSlot = reinterpret_cast<uintptr_t>(slot);
		}
	}
	return library;
}

static void LoadSettings()
{
	const std::string& ini = mq::internal_paths::MQini;
	s_remoteDebugger = GetPrivateProfileBool("GameFace", "RemoteDebugger", false, ini);
	s_remoteDebuggerPort = GetPrivateProfileInt("GameFace", "RemoteDebuggerPort", 9444, ini);
	s_initLogSeverity = GetPrivateProfileInt("GameFace", "LogSeverity", -1, ini);
}

static void SaveSettings()
{
	const std::string& ini = mq::internal_paths::MQini;
	WritePrivateProfileBool("GameFace", "RemoteDebugger", s_remoteDebugger, ini);
	WritePrivateProfileInt("GameFace", "RemoteDebuggerPort", s_remoteDebuggerPort, ini);
	WritePrivateProfileInt("GameFace", "LogSeverity", s_initLogSeverity, ini);
}

static void InstallInitHooks()
{
	if (!IsSupportedCohtml())
		return;

	FARPROC address = GetProcAddress(CohtmlModule(), "?Initialize@Library@cohtml@@SAPEAV12@PEBDAEBULibraryParams@2@@Z");
	if (!address)
		return;

	s_libraryInitializeAddress = reinterpret_cast<uintptr_t>(address);
	if (!mq::AddDetour(s_libraryInitializeAddress, LibraryInitialize_Detour, s_libraryInitializeTrampoline, "cohtml Library::Initialize"))
		s_libraryInitializeAddress = 0;
}

static void RemoveInitHooks()
{
	if (s_createSystemSlot)
		RemovePatch(s_createSystemSlot);
	if (s_libraryInitializeAddress)
		RemoveDetour(s_libraryInitializeAddress);
	s_createSystemSlot = 0;
	s_libraryInitializeAddress = 0;
}

// Finds cohtml's global logger pointer from the code that assigns it:
//   mov [rdi+10h], rsi
//   mov rbp, [rsp+30h]
//   mov rsi, [rsp+38h]
//   mov r14, [rsp+48h]
//   mov [g_logger], rdi
static Logging::Logger** FindLoggerGlobal()
{
	HMODULE module = CohtmlModule();
	if (!module)
		return nullptr;

	constexpr uint8_t pattern[] = {
		0x48, 0x89, 0x77, 0x10,
		0x48, 0x8B, 0x6C, 0x24, 0x00,
		0x48, 0x8B, 0x74, 0x24, 0x00,
		0x4C, 0x8B, 0x74, 0x24, 0x00,
		0x48, 0x89, 0x3D, 0x00, 0x00, 0x00, 0x00,
	};
	constexpr const char* mask = "xxxxxxxx?xxxx?xxxx?xxx????";

	// Only code sections are scanned; other parts of the image may not be readable.
	uintptr_t base = reinterpret_cast<uintptr_t>(module);
	auto nt = reinterpret_cast<const IMAGE_NT_HEADERS*>(base + reinterpret_cast<const IMAGE_DOS_HEADER*>(base)->e_lfanew);
	const IMAGE_SECTION_HEADER* section = IMAGE_FIRST_SECTION(nt);
	for (WORD i = 0; i < nt->FileHeader.NumberOfSections; ++i, ++section)
	{
		if (!(section->Characteristics & IMAGE_SCN_MEM_EXECUTE) || section->Misc.VirtualSize < sizeof(pattern))
			continue;

		uintptr_t match = FindPattern(base + section->VirtualAddress, section->Misc.VirtualSize - sizeof(pattern), pattern, mask);
		if (match)
		{
			// The store's address operand is relative to the end of the instruction, which ends the pattern.
			uintptr_t next = match + sizeof(pattern);
			return reinterpret_cast<Logging::Logger**>(next + *reinterpret_cast<const int32_t*>(next - 4));
		}
	}

	return nullptr;
}

// cohtml's logger, if it belongs to EQ's view. It's recreated with every Library, so changes to it last
// until the next world entry.
static Logging::Logger* GetLogger()
{
	static Logging::Logger** loggerGlobal = FindLoggerGlobal();

	GF::ViewListener* gf = pGFViewListener.get();
	if (!gf || !loggerGlobal)
		return nullptr;

	// Checking the handler confirms the global is the logger EQ's view logs through.
	Logging::Logger* logger = *loggerGlobal;
	if (!logger || logger->Handler != &gf->logHandler)
		return nullptr;
	return logger;
}

//----------------------------------------------------------------------------
// JS console. Results come back through console.error with CONSOLE_MARKER. The monitor's WriteLog hook
// collects them and keeps them out of EQ's log.

static constexpr int MAX_CONSOLE_LINES = 1000;
static constexpr size_t MAX_CONSOLE_HISTORY = 100;
static constexpr MQColor CONSOLE_INPUT_COLOR = MQColor(140, 204, 255);
static constexpr MQColor CONSOLE_ERROR_COLOR = MQColor(255, 102, 102);

// cohtml cuts log messages at about 2 KB, so results are sent in pieces of at most this many UTF-16 units,
// which is at most 1.5 KB of UTF-8.
static constexpr int CONSOLE_CHUNK = 500;
// The pieces of a long result received so far.
static std::string s_consolePartial;

static std::unique_ptr<ImGuiZepConsole> s_console;
static std::deque<std::string> s_consoleHistory;

// Created on first use, because the editor needs ImGui to be running.
static ImGuiZepConsole& Console()
{
	if (!s_console)
	{
		s_console = std::make_unique<ImGuiZepConsole>("##GameFaceConsole");
		s_console->SetMaxBufferLines(MAX_CONSOLE_LINES);
	}
	return *s_console;
}

static std::string ToJsStringLiteral(std::string_view text)
{
	std::string out = "\"";
	for (size_t i = 0; i < text.size(); ++i)
	{
		unsigned char c = static_cast<unsigned char>(text[i]);
		if (c == '"' || c == '\\') { out.push_back('\\'); out.push_back(c); }
		else if (c == '\n') out += "\\n";
		else if (c == '\r') out += "\\r";
		else if (c == '\t') out += "\\t";
		else if (c < 0x20) out += fmt::format("\\u{:04x}", c);
		// U+2028/U+2029 end a line inside JS string literals
		else if (c == 0xE2 && i + 2 < text.size() && static_cast<unsigned char>(text[i + 1]) == 0x80
			&& (static_cast<unsigned char>(text[i + 2]) & 0xFE) == 0xA8)
		{
			out += static_cast<unsigned char>(text[i + 2]) == 0xA8 ? "\\u2028" : "\\u2029";
			i += 2;
		}
		else out.push_back(c);
	}
	out.push_back('"');
	return out;
}

// Added to every page load of the view so the console can use the UI's EQ class and EQEngine object. The UI
// bundle keeps both private, so this catches them while the bundle sets up, which needs it to run first:
//   EQ        the bundle ends with window.printValues = EQ.printValues.bind(EQ).
//   EQEngine  its constructor defines each field with a helper that calls Object.defineProperty when the
//             field name is already "in" the object. An inherited placeholder for its last field sends it
//             down that path.
static constexpr std::string_view CONSOLE_GLOBALS = R"js(
(() => {
	const bind = Function.prototype.bind;
	Function.prototype.bind = function (thisArg, ...args) {
		if (typeof thisArg === 'function' && thisArg.printValues === this) {
			window.EQ = thisArg;
			Function.prototype.bind = bind;
		}
		return bind.call(this, thisArg, ...args);
	};

	const field = 'KeysSentEachFrameWasChanged_', defineProperty = Object.defineProperty;
	defineProperty(Object.prototype, field, { configurable: true, get() { return undefined; } });
	Object.defineProperty = function (obj, key, descriptor) {
		if (key === field && obj !== Object.prototype) {
			window.EQEngine = obj;
			Object.defineProperty = defineProperty;
			delete Object.prototype[field];
		}
		return defineProperty(obj, key, descriptor);
	};
})();
)js";

// The view the console globals were added to. A new view is created on every world entry.
static View* s_consoleGlobalsView = nullptr;

static void AddConsoleGlobals()
{
	View* view = GetView();
	if (view && view != s_consoleGlobalsView)
		view->AddInitialScript(std::string(CONSOLE_GLOBALS).c_str());
	s_consoleGlobalsView = view;
}

static void RunScript(const std::string& code)
{
	Console().AppendText("> " + code, CONSOLE_INPUT_COLOR, true);
	if (s_consoleHistory.empty() || s_consoleHistory.back() != code)
		s_consoleHistory.push_back(code);
	if (s_consoleHistory.size() > MAX_CONSOLE_HISTORY)
		s_consoleHistory.pop_front();

	// The result channel is the monitor's WriteLog hook.
	SetMonitorEnabled(true);

	// send() splits the result into CONSOLE_CHUNK pieces without breaking surrogate pairs. Every piece but the
	// last is tagged '+'.
	std::string script = fmt::format(
		"(function(){{var M={1},C={2};"
		"function send(tag,s){{s=String(s);var i=0;while(s.length-i>C){{var c=s.charCodeAt(i+C-1),n=c>=0xD800&&c<0xDC00?C-1:C;"
		"console.error(M+'+'+s.slice(i,i+n));i+=n;}}console.error(M+tag+s.slice(i));}}"
		"try{{var r=(0,eval)({0});var s;if(typeof r==='string')s=r;else{{try{{s=JSON.stringify(r,null,2);}}catch(e){{}}"
		"if(s===undefined)s=String(r);}}send(':',s);}}"
		"catch(e){{send('err:',e&&e.stack?e.stack:e);}}}})()",
		ToJsStringLiteral(code), ToJsStringLiteral(CONSOLE_MARKER), CONSOLE_CHUNK);

	QueueGameFaceAction([script = std::move(script)] {
		if (View* view = GetView())
			view->ExecuteScript(script.c_str());
	});
}

static void CollectConsoleOutput()
{
	for (std::string& message : TakeConsoleOutput())
	{
		// cohtml appends the script location to errors
		if (size_t pos = message.rfind("\n While executing JS"); pos != std::string::npos)
			message.resize(pos);

		if (message.starts_with("+"))
		{
			s_consolePartial.append(message, 1);
			continue;
		}
		message.insert(message.find(':') + 1, std::exchange(s_consolePartial, {}));

		while (!message.empty() && isspace(static_cast<unsigned char>(message.back())))
			message.pop_back();

		if (message.starts_with(":"))
			Console().AppendText(std::string_view(message).substr(1), ImGuiZepConsole::DEFAULT_COLOR, true);
		else if (message.starts_with("err:"))
			Console().AppendText(std::string_view(message).substr(4), CONSOLE_ERROR_COLOR, true);
	}
}

//----------------------------------------------------------------------------

struct CacheInfo
{
	unsigned id;
	const char* name;
	bool hasBytes;
	unsigned count = 0, countCapacity = 0, bytes = 0, bytesCapacity = 0;
};

static std::vector<CacheInfo> s_caches = {
	{ 1,   "Shadows",                   false },
	{ 2,   "Paths",                     false },
	{ 4,   "Textures",                  true },
	{ 8,   "Scratch layers",            true },
	{ 16,  "Scratch textures",          true },
	{ 32,  "Gfx command buffers",       true },
	{ 64,  "Gfx command processors",    true },
	{ 512, "(512)",                     true },
};

struct ImageCacheStats
{
	unsigned aliveCount = 0, aliveBytes = 0, orphanedCount = 0, orphanedBytes = 0;
	bool valid = false;
};

static ImageCacheStats s_imageStats;
static std::vector<std::string> s_usedImages;

static void RefreshCacheStats()
{
	if (View* view = GetView())
	{
		for (CacheInfo& cache : s_caches)
		{
			view->GetCacheCountStats(cache.id, cache.count, cache.countCapacity);
			if (cache.hasBytes)
				view->GetCacheBytesStats(cache.id, cache.bytes, cache.bytesCapacity);
		}
	}

	s_imageStats = {};
	GF::ViewListener* gf = pGFViewListener.get();
	if (gf && gf->pSystem && IsSupportedCohtml())
	{
		if (SystemCacheStats* stats = gf->pSystem->GetSystemCacheStats())
		{
			if (const cohtml::ImageCacheStats* image = stats->GetImageCacheStats())
			{
				s_imageStats.aliveCount = image->aliveImagesCount;
				s_imageStats.aliveBytes = image->aliveTotalBytesUsed;
				s_imageStats.orphanedCount = image->orphanedImagesCount;
				s_imageStats.orphanedBytes = image->orphanedBytesUsed;
				s_imageStats.valid = true;
			}
			stats->Release();
		}
	}
}

static void RefreshUsedImages(int options)
{
	s_usedImages.clear();
	View* view = GetView();
	ImagesList* list = view ? view->GetUsedImagesList(options) : nullptr;
	if (!list)
		return;
	while (const char* image = list->Next())
		s_usedImages.emplace_back(image);
	list->Release();
	std::sort(s_usedImages.begin(), s_usedImages.end());
}

static std::string s_dumpTitle;
static std::string s_dumpText;

static void TakeDump(DebugDump* dump, std::string_view title)
{
	s_dumpTitle = title;
	s_dumpText = dump && dump->dump ? dump->dump : "(nothing returned - is a document loaded?)";
	if (dump)
		dump->Release();
}

} // namespace debug

void GameFaceInspector::DrawDebugTools()
{
	using namespace debug;

	GF::ViewListener* gf = pGFViewListener.get();
	bool running = gf && gf->pView;
	bool supported = IsSupportedCohtml();

	CollectConsoleOutput();

	if (!supported)
		ImGui::TextColored(ImVec4(1, 0.5f, 0.3f, 1), "Unrecognized cohtml.WindowsDesktop.dll version; version-specific tools are disabled.");
	if (!s_status.empty())
		ImGui::TextWrapped("%s", s_status.c_str());

	//------------------------------------------------------------------------
	if (ImGui::CollapsingHeader("JavaScript console", ImGuiTreeNodeFlags_DefaultOpen))
	{
		ImGui::BeginDisabled(!running);

		float outputHeight = std::max(120.0f, ImGui::GetContentRegionAvail().y * 0.35f);
		Console().Render("##consoleOutput", ImVec2(0, outputHeight));

		static std::string input;
		ImGui::PushFont(mq::imgui::ConsoleFont);
		bool run = ImGui::InputTextMultiline("##consoleInput", &input, ImVec2(-90, ImGui::GetTextLineHeight() * 3.5f),
			ImGuiInputTextFlags_CtrlEnterForNewLine | ImGuiInputTextFlags_EnterReturnsTrue);
		ImGui::PopFont();
		ImGui::SameLine();
		ImGui::BeginGroup();
		run |= ImGui::Button("Run", ImVec2(80, 0));
		if (ImGui::Button("Clear##console", ImVec2(80, 0)))
			Console().Clear();
		if (ImGui::BeginCombo("##snippets", "Snippets", ImGuiComboFlags_NoPreview | ImGuiComboFlags_HeightLarge))
		{
			static const std::pair<const char*, const char*> snippets[] = {
				{ "Page URL", "location.href" },
				{ "Open windows", "Array.from(document.querySelectorAll('eq-screen')).map(e => e.getAttribute('item'))" },
				{ "Element counts", "Object.entries(Array.from(document.querySelectorAll('*')).reduce((m, e) => (m[e.localName] = (m[e.localName] || 0) + 1, m), {})).sort((a, b) => b[1] - a[1]).slice(0, 30)" },
				{ "Model values (filter)", "Object.fromEntries(Object.entries(EQEngine.Model).filter(([key]) => key.includes('InventoryWindow')))" },
				{ "Model value", "EQ.getValue('InventoryWindow.Title')" },
				{ "Window markup", "document.querySelector('eq-screen[item=\"QuantityWnd\"]').outerHTML" },
				{ "Viewport", "({ w: innerWidth, h: innerHeight, dpr: devicePixelRatio, font: getComputedStyle(document.documentElement).fontSize })" },
			};
			for (const auto& [label, code] : snippets)
				if (ImGui::Selectable(label))
					input = code;
			if (!s_consoleHistory.empty())
			{
				ImGui::Separator();
				for (auto it = s_consoleHistory.rbegin(); it != s_consoleHistory.rend(); ++it)
					if (ImGui::Selectable(it->substr(0, 80).c_str()))
						input = *it;
			}
			ImGui::EndCombo();
		}
		ImGui::EndGroup();

		if (run && !input.empty())
		{
			RunScript(input);
			input.clear();
		}
		ImGui::TextDisabled("Enter runs, Ctrl+Enter for a new line. Evaluated in the page's global scope; results are JSON.stringify'd.");
		ImGui::EndDisabled();
	}

	//------------------------------------------------------------------------
	if (ImGui::CollapsingHeader("Rendering"))
	{
		ImGui::BeginDisabled(!running);
		static bool continuousRepaint = false, aabbs = false, renderingEnabled = true;
		if (ImGui::Checkbox("Show element bounding boxes", &aabbs))
			QueueGameFaceAction([v = aabbs] { if (View* view = GetView()) view->ShowElementAABBs(v); });
		if (ImGui::Checkbox("Continuous repaint", &continuousRepaint))
			QueueGameFaceAction([v = continuousRepaint] { if (View* view = GetView()) view->ContinuousRepaint(v); });
		if (ImGui::Checkbox("Render UI", &renderingEnabled))
			QueueGameFaceAction([v = renderingEnabled] { if (View* view = GetView()) view->EnableRendering(v); });
		ImGui::TextDisabled("These are not read back from cohtml; they reset when GameFace is recreated (world entry).");

		ImGui::SeparatorText("CSS media feature override");
		static std::string featureName = "prefers-reduced-motion", featureValue = "reduce";
		ImGui::SetNextItemWidth(200); ImGui::InputText("Feature", &featureName); ImGui::SameLine();
		ImGui::SetNextItemWidth(150); ImGui::InputText("Value", &featureValue); ImGui::SameLine();
		if (ImGui::Button("Set") && supported)
			QueueGameFaceAction([n = featureName, v = featureValue] {
				View* view = GetView();
				bool ok = view && view->SetMediaFeatureOverride(n.c_str(), v.c_str());
				s_status = fmt::format("Media feature ({}: {}) {}", n, v, ok ? "set" : "rejected");
			});
		ImGui::SameLine();
		if (ImGui::Button("Clear all") && supported)
			QueueGameFaceAction([] { if (View* view = GetView()) view->ClearMediaFeatureOverrides(); s_status = "Media feature overrides cleared"; });
		ImGui::EndDisabled();
	}

	//------------------------------------------------------------------------
	if (ImGui::CollapsingHeader("DOM / layout dumps"))
	{
		ImGui::BeginDisabled(!running);
		static bool styles = false, layout = false;
		ImGui::Checkbox("Include styles", &styles); ImGui::SameLine();
		ImGui::Checkbox("Include layout", &layout); ImGui::SameLine();
		if (ImGui::Button("Dump DOM tree"))
			QueueGameFaceAction([flags = (styles ? 2u : 0u) | (layout ? 4u : 0u)] {
				View* view = GetView();
				TakeDump(view ? view->DebugDumpDOMTree(flags) : nullptr, "DOM tree");
			});
		ImGui::SameLine();
		if (ImGui::Button("Dump stacking contexts"))
			QueueGameFaceAction([] {
				View* view = GetView();
				TakeDump(view ? view->DebugDumpStackingContextTree() : nullptr, "Stacking context tree");
			});
		ImGui::EndDisabled();

		if (!s_dumpText.empty())
		{
			static ImGuiTextFilter dumpFilter;
			ImGui::Text("%s (%d KB)", s_dumpTitle.c_str(), (int)(s_dumpText.size() / 1024));
			ImGui::SameLine();
			if (ImGui::SmallButton("Copy##dump")) ImGui::SetClipboardText(s_dumpText.c_str());
			ImGui::SameLine();
			if (ImGui::SmallButton("Save##dump"))
			{
				std::filesystem::path path = OutputDirectory() / TimestampedName("dump", ".txt");
				bool written = static_cast<bool>(std::ofstream(path) << s_dumpText);
				s_status = fmt::format("{} {}", written ? "Wrote" : "Failed to write", path.string());
			}
			ImGui::SameLine();
			dumpFilter.Draw("Filter lines##dump", 200);

			ImGui::BeginChild("##dumpText", ImVec2(0, 300), ImGuiChildFlags_Borders, ImGuiWindowFlags_HorizontalScrollbar);
			std::vector<std::string_view> lines = split_view(s_dumpText, '\n');
			std::vector<std::string_view> shown;
			for (std::string_view line : lines)
				if (!dumpFilter.IsActive() || dumpFilter.PassFilter(line.data(), line.data() + line.size()))
					shown.push_back(line);
			ImGuiListClipper clipper;
			clipper.Begin(static_cast<int>(shown.size()));
			while (clipper.Step())
				for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; ++i)
					ImGui::TextUnformatted(shown[i].data(), shown[i].data() + shown[i].size());
			ImGui::EndChild();
		}
	}

	//------------------------------------------------------------------------
	if (ImGui::CollapsingHeader("Caches & images"))
	{
		ImGui::BeginDisabled(!running);
		if (ImGui::Button("Refresh stats"))
			QueueGameFaceAction(&RefreshCacheStats);
		ImGui::SameLine();
		if (ImGui::Button("Clear view caches"))
			QueueGameFaceAction([] { if (View* view = GetView()) view->QueueClearCaches(ALL_CACHES); s_status = "View caches will be cleared on the next frame"; });
		ImGui::SameLine();
		ImGui::BeginDisabled(!supported);
		if (ImGui::Button("Clear unused images"))
			QueueGameFaceAction([] {
				if (GF::ViewListener* l = pGFViewListener.get(); l && l->pSystem)
					l->pSystem->ClearCachedUnusedImages();
				s_status = "Unused images cleared";
			});
		ImGui::EndDisabled();

		if (ImGui::BeginTable("##caches", 3, ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersInnerV))
		{
			ImGui::TableSetupColumn("Cache");
			ImGui::TableSetupColumn("Count / capacity");
			ImGui::TableSetupColumn("Bytes / capacity");
			ImGui::TableHeadersRow();
			for (const CacheInfo& cache : s_caches)
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("%s", cache.name);
				ImGui::TableNextColumn(); ImGui::Text("%u / %u", cache.count, cache.countCapacity);
				ImGui::TableNextColumn();
				if (cache.hasBytes) ImGui::Text("%u KB / %u KB", cache.bytes / 1024, cache.bytesCapacity / 1024);
			}
			ImGui::EndTable();
		}
		if (s_imageStats.valid)
			ImGui::Text("Image cache: %u alive (%u KB), %u orphaned (%u KB)", s_imageStats.aliveCount, s_imageStats.aliveBytes / 1024,
				s_imageStats.orphanedCount, s_imageStats.orphanedBytes / 1024);

		static int imageOptions = 0;
		ImGui::SetNextItemWidth(120);
		ImGui::Combo("##imageOptions", &imageOptions, "Visible\0Hidden\0Styles\0");
		ImGui::SameLine();
		if (ImGui::Button("List used images"))
			QueueGameFaceAction([o = imageOptions] { RefreshUsedImages(o); });
		if (!s_usedImages.empty())
		{
			ImGui::BeginChild("##images", ImVec2(0, 200), ImGuiChildFlags_Borders);
			for (const std::string& image : s_usedImages)
				ImGui::TextUnformatted(image.c_str());
			ImGui::EndChild();
		}
		ImGui::EndDisabled();
	}

	//------------------------------------------------------------------------
	if (ImGui::CollapsingHeader("Logging & remote debugger"))
	{
		ImGui::SeparatorText("cohtml log level");
		if (Logging::Logger* logger = GetLogger())
		{
			int current = std::clamp<int>(logger->MinSeverity, Logging::Trace, Logging::Critical);
			ImGui::SetNextItemWidth(150);
			if (ImGui::Combo("Current", &current, SEVERITY_NAMES, IM_ARRAYSIZE(SEVERITY_NAMES)))
			{
				QueueGameFaceAction([current] {
					if (Logging::Logger* logger = GetLogger())
						logger->MinSeverity = static_cast<Logging::Severity>(current);
				});
			}
			ImGui::SameLine();
			ImGui::TextDisabled("(until the next world entry; EQ uses Error. Info includes console.log)");
		}
		else
		{
			ImGui::TextDisabled("Logger not available. GameFace isn't running, or this cohtml build isn't recognized.");
		}

		// The startup settings write into cohtml's settings structs, whose layout is version specific.
		ImGui::BeginDisabled(!supported);

		int initSeverity = s_initLogSeverity + 1;
		ImGui::SetNextItemWidth(150);
		auto startupName = [](void*, int i) { return i == 0 ? "EQ default" : SEVERITY_NAMES[i - 1]; };
		if (ImGui::Combo("At startup", &initSeverity, startupName, nullptr, IM_ARRAYSIZE(SEVERITY_NAMES) + 1))
		{
			s_initLogSeverity = initSeverity - 1;
			SaveSettings();
		}

		ImGui::SeparatorText("Remote debugger (Chrome DevTools)");
		bool changed = ImGui::Checkbox("Enable", &s_remoteDebugger);
		ImGui::SameLine();
		ImGui::SetNextItemWidth(100);
		changed |= ImGui::InputInt("Port", &s_remoteDebuggerPort, 0);
		s_remoteDebuggerPort = std::clamp(s_remoteDebuggerPort, 1, 65535);
		if (changed)
			SaveSettings();

		if (s_activeDebuggerPort)
		{
			ImGui::TextColored(ImVec4(0.4f, 1, 0.4f, 1), "Active on port %d", s_activeDebuggerPort);
			ImGui::SameLine();
			if (ImGui::SmallButton("Open in browser"))
				ShellExecuteA(nullptr, "open", fmt::format("http://localhost:{}/", s_activeDebuggerPort).c_str(), nullptr, nullptr, SW_SHOWNORMAL);
		}
		else
		{
			ImGui::TextDisabled("Not active.");
		}
		ImGui::TextWrapped("GameFace is created on world entry, so these settings apply after camping to character select "
			"and entering the world again (/reloadui is not enough). The debugger opens a TCP listener on the port; "
			"cohtml logs \"Remote debugging available on port N\" at Info level.");
		if (!s_libraryInitializeAddress)
			ImGui::TextColored(ImVec4(1, 0.5f, 0.3f, 1), "Startup hook not installed.");

		ImGui::EndDisabled();
	}
}

//============================================================================

static void GameFaceInspector_Initialize()
{
	debug::LoadSettings();
	debug::InstallInitHooks();

	s_inspector = new GameFaceInspector();
	DeveloperTools_RegisterMenuItem(s_inspector, "GameFace Inspector", s_menuNameInspectors);
}

static void GameFaceInspector_Shutdown()
{
	DeveloperTools_UnregisterMenuItem(s_inspector);
	delete s_inspector;
	s_inspector = nullptr;
	s_pendingActions.clear();
	debug::s_console.reset();

	debug::RemoveInitHooks();
}

static void GameFaceInspector_Pulse()
{
	debug::AddConsoleGlobals();

	auto actions = std::exchange(s_pendingActions, {});
	for (auto& action : actions)
		action();
}

//############################################################################
// Module
//############################################################################

static void GameFaceMonitor_Initialize()
{
	GameFaceInspector_Initialize();
}

static void GameFaceMonitor_Shutdown()
{
	GameFaceInspector_Shutdown();
	SetMonitorEnabled(false);
}

static void GameFaceMonitor_Pulse()
{
	// The view doesn't exist until GameFace is initialized; keep trying while enabled.
	if (s_enabled && !s_viewHooksInstalled)
		TryInstallHooks();

	GameFaceInspector_Pulse();
}

static MQModule s_gameFaceMonitorModule = {
	"GameFaceMonitor",             // Name
	true,                          // CanUnload
	GameFaceMonitor_Initialize,
	GameFaceMonitor_Shutdown,
	GameFaceMonitor_Pulse,
};
DECLARE_MODULE_INITIALIZER(s_gameFaceMonitorModule);

} // namespace mq::gameface

#endif // HAS_GAMEFACE_UI
