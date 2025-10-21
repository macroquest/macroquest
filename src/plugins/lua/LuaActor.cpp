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

#include "mq/base/Common.h"
#include "mq/api/ActorAPI.h"
#include "mq/Plugin.h"

#include "Actor.pb.h"

#include "LuaActor.h"
#include "LuaThread.h"
#include "LuaCoroutine.h"

// includes for datatype conversions to proto
#include "imgui.h"

#include "common/StringUtils.h"

#ifdef _DEBUG
#pragma comment(lib, "libprotobufd")
#else
#pragma comment(lib, "libprotobuf")
#endif

namespace mq::lua {
using namespace mq::postoffice;

namespace messaging = proto::lua::actor;

sol::object DeserializeProto(const messaging::Variant& data, sol::state_view s)
{
	switch (data.value_case())
	{
	case messaging::Variant::ValueCase::kNumber:
		return sol::make_object(s, data.number());
	case messaging::Variant::ValueCase::kBoolean:
		return sol::make_object(s, data.boolean());
	case messaging::Variant::ValueCase::kStr:
		return sol::make_object(s, data.str());
	case messaging::Variant::ValueCase::kTable:
	{
		if (data.has_table())
		{
			auto table = s.create_table(0, static_cast<int>(data.table().entries().size() + data.table().arr().size()));

			for (const auto& [k, v] : data.table().entries())
			{
				table[k] = DeserializeProto(v, s);
			}

			for (const auto& [k, v] : data.table().arr())
			{
				table[k] = DeserializeProto(v, s);
			}

			return sol::make_object(s, table);
		}
		
		return sol::lua_nil;
	}
	case messaging::Variant::ValueCase::kImvec2:
		return sol::make_object(s, ImVec2(
			data.imvec2().x(),
			data.imvec2().y()));
	case messaging::Variant::ValueCase::kImvec4:
		return sol::make_object(s, ImVec4(
			data.imvec4().x(),
			data.imvec4().y(),
			data.imvec4().z(),
			data.imvec4().w()
		));
	default:
		return sol::nil;
	}
}

messaging::Variant SerializeProto(const sol::object& data)
{
	messaging::Variant variant;

	switch (data.get_type())
	{
	case sol::type::string:
		variant.set_str(data.as<std::string>());
		break;
	case sol::type::number:
		variant.set_number(data.as<double>());
		break;
	case sol::type::boolean:
		variant.set_boolean(data.as<bool>());
		break;
	case sol::type::table:
	{
		messaging::Table table;
		google::protobuf::Map<std::string, messaging::Variant> entries;
		google::protobuf::Map<uint32_t, messaging::Variant> arr;
		for (const auto& [k, v] : data.as<sol::table>())
		{
			// a limitation of proto: keys can't be messages, so we have to limit it here
			if (k.is<std::string_view>())
			{
				entries[k.as<std::string_view>()] = SerializeProto(v);
			}
			else if (k.is<uint32_t>())
			{
				arr[k.as<uint32_t>()] = SerializeProto(v);
			}
		}

		if (!entries.empty())
			*table.mutable_entries() = entries;

		if (!arr.empty())
			*table.mutable_arr() = arr;

		if (!entries.empty() || !arr.empty())
			*variant.mutable_table() = table;
		break;
	}
	case sol::type::userdata:
		if (data.is<ImVec2>())
		{
			auto vec = data.as<ImVec2>();
			*variant.mutable_imvec2() = messaging::ImVec2();
			(*variant.mutable_imvec2()).set_x(vec.x);
			(*variant.mutable_imvec2()).set_y(vec.y);
		}
		else if (data.is<ImVec4>())
		{
			auto vec = data.as<ImVec4>();
			*variant.mutable_imvec4() = messaging::ImVec4();
			(*variant.mutable_imvec4()).set_x(vec.x);
			(*variant.mutable_imvec4()).set_y(vec.y);
			(*variant.mutable_imvec4()).set_z(vec.z);
			(*variant.mutable_imvec4()).set_w(vec.w);
		}
		break;
	default:
		break;
	}

	return variant;
}


void Send(sol::object payload);
void Send(sol::table header, sol::object payload);
void Send(sol::object payload, sol::function response_callback);
void Send(sol::table header, sol::object payload, sol::function response_callback);

class LuaDropbox;
struct LuaMessage
{
	const LuaDropbox* const dropbox;
	std::shared_ptr<Message> message;
	messaging::Variant data;
	bool has_data = false;

	LuaMessage(const LuaDropbox* const dropbox_, const std::shared_ptr<Message>& message_)
		: dropbox(dropbox_)
		, message(message_)
	{
		has_data = message && message->Payload && data.ParseFromString(*message->Payload);
	}

	sol::object Get(sol::this_state s)
	{
		if (has_data)
			return DeserializeProto(data, s);

		return sol::lua_nil;
	}

	sol::table Sender(sol::this_state s)
	{
		if (message && message->Sender)
		{
			sol::table table = sol::state_view(s).create_table();
			if (message->Sender->UUID) table["uuid"] = *message->Sender->UUID;
			if (message->Sender->PID) table["pid"] = *message->Sender->PID;
			if (message->Sender->Name) table["name"] = *message->Sender->Name;
			if (message->Sender->Mailbox) table["mailbox"] = *message->Sender->Mailbox;
			if (message->Sender->Account) table["account"] = *message->Sender->Account;
			if (message->Sender->Server) table["server"] = *message->Sender->Server;
			if (message->Sender->Character) table["character"] = *message->Sender->Character;
			table["absolute_mailbox"] = message->Sender->AbsoluteMailbox;

			return table;
		}

		return sol::lua_nil;
	}

	void Reply(sol::object reply);
	void Reply(int status, sol::object reply);
	void Send(sol::object reply, sol::this_state s);
};

struct CallbackInstance
{
	sol::function m_callback;
	sol::thread m_thread;
	sol::thread m_parentThread;
	sol::coroutine m_coroutine;

	int m_status = 0;
	LuaMessage m_message;

	// the thread lifetime is necessarily longer than this CallbackInstance because if the thread goes
	// down, the dropboxes will be closed
	CallbackInstance(const sol::thread& parent_thread, const sol::function& callback, LuaMessage&& message)
		: m_message(std::move(message))
		, m_callback(callback)
		, m_parentThread(parent_thread)
	{
		m_thread = sol::thread::create(parent_thread.state());
		m_coroutine = sol::coroutine(m_thread.state(), m_callback);
	}

	~CallbackInstance()
	{
		//lua_gc(coroutine->thread.lua_state(), LUA_GCCOLLECT, 0);
	}

	void Run()
	{
		try
		{
			ScopedYieldDisabler disableYield(LuaThread::get_from(m_thread.state()));

			sol::function_result result = m_coroutine(m_status, m_message);
			if (!result.valid())
			{
				LuaError("Lua Actor Failure:\n%s", sol::stack::get<std::string>(result.lua_state(), result.stack_index()).c_str());
				result.abandon();
			}
		}
		catch (std::runtime_error& e)
		{
			LuaError("Lua Actor Failure:\n%s", e.what());
		}
	}
};

// global callbacks for anonymous sends
std::vector<std::unique_ptr<CallbackInstance>> s_queue;

/**
 * A local lua driobox type. The postoffice dropbox will route messages to these dropboxes and provide
 * addressing to route messages from these dropboxes. These are the actual lua interfaces into userland,
 * and they will have message processing callbacks defined in lua space by the user.
 */
class LuaDropbox
{
public:
	static std::shared_ptr<LuaDropbox> RegisterWithName(const std::string& name, const sol::function& callback, sol::this_state s);
	static std::shared_ptr<LuaDropbox> Register(const sol::function& callback, sol::this_state s);
	void Unregister();

	Address ParseHeader(sol::table header) const;
	static Address ParseHeader(sol::table header, const std::shared_ptr<LuaThread>& thread, std::string_view script_name);
	void Send(sol::object payload) const;
	void Send(sol::table header, sol::object payload) const;
	void Send(sol::object payload, sol::function response_callback);
	void Send(sol::table header, sol::object payload, sol::function response_callback);
	void Reply(const std::shared_ptr<Message>& message, const sol::object& reply, int status) const;
	void Receive(const std::shared_ptr<Message>& message);
	void Process();

	const std::string& GetName() { return m_name; }

	LuaDropbox(std::string_view name, const sol::function& callback, const sol::thread& parent_thread);
	~LuaDropbox();

private:
	std::string m_name;
	sol::function m_callback;
	sol::thread m_thread;
	sol::thread m_parentThread;
	sol::coroutine m_coroutine;
	std::vector<std::unique_ptr<CallbackInstance>> m_queue;

	DropboxAPI m_dropbox;
};

// now create a map of script dropboxes to route to
static ci_unordered::map<std::string, std::weak_ptr<LuaDropbox>> s_dropboxes;

void LuaMessage::Reply(sol::object reply)
{
	if (message && dropbox != nullptr) dropbox->Reply(message, reply, 0);
}

void LuaMessage::Reply(int status, sol::object reply)
{
	if (message && dropbox != nullptr) dropbox->Reply(message, reply, status);
}

void LuaMessage::Send(sol::object reply, sol::this_state s)
{
	if (dropbox != nullptr)
		dropbox->Send(Sender(s), reply);
	else
		mq::lua::Send(Sender(s), reply);
}

std::shared_ptr<LuaDropbox> LuaDropbox::RegisterWithName(const std::string& name, const sol::function& callback, sol::this_state s)
{
	if (auto thread = LuaThread::get_from(s))
	{
		auto full_name = fmt::format("{}:{}", thread->GetName(), name);
		auto dropbox = std::make_shared<LuaDropbox>(full_name, callback, thread->GetLuaThread());

		// if we can't place the dropbox in the map for some reason, then return a nullptr
		if (!s_dropboxes.emplace(full_name, dropbox).second)
			dropbox.reset();

		return dropbox;
	}

	return nullptr;
}

std::shared_ptr<LuaDropbox> LuaDropbox::Register(const sol::function& callback, sol::this_state s)
{
	if (auto thread = LuaThread::get_from(s))
	{
		auto dropbox = std::make_shared<LuaDropbox>(thread->GetName(), callback, thread->GetLuaThread());

		if (!s_dropboxes.emplace(thread->GetName(), dropbox).second)
			dropbox.reset();

		return dropbox;
	}

	return nullptr;
}

void LuaDropbox::Unregister()
{
	s_dropboxes.erase(m_name);
}

LuaDropbox::LuaDropbox(std::string_view name, const sol::function& callback, const sol::thread& parent_thread)
	: m_name(name)
	, m_callback(callback)
	, m_parentThread(parent_thread)
	, m_dropbox(AddActor(m_name.c_str(), [this](const std::shared_ptr<Message>& message) { Receive(message); }))
{
	m_thread = sol::thread::create(parent_thread.state());
	m_coroutine = sol::coroutine(m_thread.state(), m_callback);
}

LuaDropbox::~LuaDropbox()
{
	m_dropbox.Remove();
}

Address LuaDropbox::ParseHeader(sol::table header) const
{
	return ParseHeader(header, LuaThread::get_from(m_parentThread.state()), m_name);
}

Address LuaDropbox::ParseHeader(sol::table header, const std::shared_ptr<LuaThread>& thread, std::string_view script_name)
{
	// parse the header for routing information
	Address addr;
	addr.Mailbox = header.get<std::optional<std::string>>("mailbox");
	addr.AbsoluteMailbox = header.get<std::optional<bool>>("absolute_mailbox").value_or(false);
	
	// also grab the script if its available for mailbox construction
	std::optional<std::string_view> script = header["script"];

	// if the mailbox contains a colon delimiter, then it's an absolute, but we still
	// need to detect if it's script to script or script to anywhere
	// of course, do nothing to Mailbox if it is declared absolute
	if (!addr.AbsoluteMailbox)
	{
		if (addr.Mailbox)
		{
			if (script)
				addr.Mailbox = fmt::format("{}:{}", *script, *addr.Mailbox);
			else if (thread)
				addr.Mailbox = fmt::format("{}:{}", thread->GetName(), *addr.Mailbox);
		}
		else if (script)
		{
			// we have a script but not a mailbox, so that means we want to send to the script's mailbox
			addr.Mailbox = *script;
		}
		else
		{
			// we have nothing, so send to "self"
			addr.Mailbox = script_name;
		}
	}

	// it's not likely these are set, but if they are we want to make sure they get routed correctly
	addr.UUID = header.get<std::optional<std::string>>("uuid");
	addr.PID = header.get<std::optional<uint32_t>>("pid");
	addr.Name = header.get<std::optional<std::string>>("name");

	// any ambiguity in address means that it will get sent to all mailboxes
	// that match. In this way, Send is simultaneously a "tell" and a "shout"
	// these are optionals, so it's safe to set them directly
	addr.Account = header.get<std::optional<std::string>>("account");
	addr.Server = header.get<std::optional<std::string>>("server");
	addr.Character = header.get<std::optional<std::string>>("character");

	return addr;
}

void LuaDropbox::Send(sol::object payload) const
{
	Send(sol::state_view(payload.lua_state()).create_table(), payload);
}

void LuaDropbox::Send(sol::table header, sol::object payload) const
{
	m_dropbox.Post(ParseHeader(header), SerializeProto(payload));
}

void LuaDropbox::Send(sol::object payload, sol::function response_callback)
{
	Send(sol::state_view(payload.lua_state()).create_table(), payload, response_callback);
}

void LuaDropbox::Send(sol::table header, sol::object payload, sol::function response_callback)
{
	// need to create the callback instance before response_callback goes out of scope in lua
	auto callback = std::make_unique<CallbackInstance>(m_parentThread, response_callback, LuaMessage(this, nullptr));
	m_dropbox.Post(ParseHeader(header), SerializeProto(payload),
		[callback = callback.release(), this](int status, const std::shared_ptr<Message>& message)
		{
			callback->m_status = status;
			callback->m_message.message = message;
			callback->m_message.has_data = message && message->Payload && callback->m_message.data.ParseFromString(*message->Payload);
			m_queue.push_back(std::unique_ptr<CallbackInstance>(callback));
		});
}

void LuaDropbox::Reply(const std::shared_ptr<Message>& message, const sol::object& reply, int status) const
{
	m_dropbox.PostReply(message, SerializeProto(reply), static_cast<uint8_t>(status));
}

void LuaDropbox::Receive(const std::shared_ptr<Message>& message)
{
	try
	{
		ScopedYieldDisabler disableYield(LuaThread::get_from(m_thread.state()));

		sol::function_result result = m_coroutine(LuaMessage(this, message));
		if (!result.valid())
		{
			LuaError("Lua Actor Failure:\n%s", sol::stack::get<std::string>(result.lua_state(), result.stack_index()).c_str());
			result.abandon();
		}
	}
	catch (std::runtime_error& e)
	{
		LuaError("Lua Actor Failure:\n%s", e.what());
	}
}

void LuaDropbox::Process()
{
	// remove any existing hooks, they will be re-installed when running in onpulse
	// this is to help prevent us from yielding from the thread while we're running imgui stuff.
	if (auto thread = LuaThread::get_from(m_thread.state()))
		lua_sethook(thread->GetLuaThread().lua_state(), nullptr, 0, 0);

	for (auto& callback : m_queue)
	{
		callback->Run();
	}

	m_queue.clear();
}

void Send(sol::object payload)
{
	Send(sol::state_view(payload.lua_state()).create_table(), payload);
}

void Send(sol::table header, sol::object payload)
{
	auto thread = LuaThread::get_from(header.lua_state());
	postoffice::SendToActor(LuaDropbox::ParseHeader(header, thread, thread ? thread->GetName() : ""), SerializeProto(payload));
}

void Send(sol::object payload, sol::function response_callback)
{
	Send(sol::state_view(payload.lua_state()).create_table(), payload, response_callback);
}

void Send(sol::table header, sol::object payload, sol::function response_callback)
{
	// need to create the callback instance before response_callback goes out of scope in lua
	auto thread = LuaThread::get_from(header.lua_state());
	if (thread)
	{
		auto callback = std::make_unique<CallbackInstance>(thread->GetLuaThread(), response_callback, LuaMessage(nullptr, nullptr));
		postoffice::SendToActor(LuaDropbox::ParseHeader(header, thread, thread->GetName()), SerializeProto(payload),
			[callback = callback.release()](int status, const std::shared_ptr<Message>& message)
			{
				callback->m_status = status;
				callback->m_message.message = message;
				callback->m_message.has_data = message && message->Payload && callback->m_message.data.ParseFromString(*message->Payload);
				s_queue.push_back(std::unique_ptr<CallbackInstance>(callback));
			});
	}
}

// TODO: are these useful?
sol::object StatelessIterator(sol::object, sol::object k, sol::this_state s)
{
	if (s_dropboxes.begin() == s_dropboxes.end())
		return sol::lua_nil;

	if (k == sol::lua_nil)
	{
		// if any of these mailboxes are invalid, just erase them from the map, this will
		// return as soon as a valid mailbox is found.
		for (auto& it = s_dropboxes.begin(); it != s_dropboxes.end(); it = s_dropboxes.erase(it))
		{
			if (auto ptr = it->second.lock())
				return sol::make_object(s, ptr);
		}
	}

	if (k.is<std::shared_ptr<LuaDropbox>>())
	{
		auto ptr = k.as<std::shared_ptr<LuaDropbox>>();
		auto dropbox = std::find_if(s_dropboxes.begin(), s_dropboxes.end(),
			[&ptr](const std::pair<std::string, std::weak_ptr<LuaDropbox>>& pair)
			{
				return pair.second.lock() == ptr;
			});

		// grab the next one, if we are at end we need to return nil though
		if (dropbox != s_dropboxes.end())
		{
			// erase any that are expired in the process
			for (auto& it = ++dropbox; it != s_dropboxes.end(); it = s_dropboxes.erase(it))
			{
				if (auto ptr = it->second.lock())
					return sol::make_object(s, ptr);
			}
		}
	}

	return sol::lua_nil;
}

sol::object Iterator(sol::this_state s)
{
	return sol::make_object(s, std::make_tuple(StatelessIterator, sol::lua_nil, sol::lua_nil));
}

// TODO: add address storage for connected remote actors (parse ident and drop messages from the pipe_client)
sol::table LuaActors::RegisterLua(sol::state_view s)
{
	auto actors = s.create_table();
	actors.new_usertype<LuaDropbox>(
		"dropbox", sol::no_constructor,
		"send", sol::overload(
			sol::resolve<void(sol::object) const>(&LuaDropbox::Send),
			sol::resolve<void(sol::object, sol::function)>(&LuaDropbox::Send),
			sol::resolve<void(sol::table, sol::object) const>(&LuaDropbox::Send),
			sol::resolve<void(sol::table, sol::object, sol::function)>(&LuaDropbox::Send)),
		"unregister", &LuaDropbox::Unregister);

	actors.new_usertype<LuaMessage>(
		"message", sol::no_constructor,
		"content", sol::property(&LuaMessage::Get),
		"reply", sol::overload(
			sol::resolve<void(sol::object)>(&LuaMessage::Reply),
			sol::resolve<void(int, sol::object)>(&LuaMessage::Reply)),
		"sender", sol::property(&LuaMessage::Sender),
		"send", &LuaMessage::Send,
		sol::meta_function::call, &LuaMessage::Get);

	actors.set_function("register", sol::overload(&LuaDropbox::RegisterWithName, &LuaDropbox::Register));
	actors.set_function("iter", &Iterator);
	actors.set_function("send", sol::overload(
		sol::resolve<void(sol::object)>(&Send),
		sol::resolve<void(sol::object, sol::function)>(&Send),
		sol::resolve<void(sol::table, sol::object)>(&Send),
		sol::resolve<void(sol::table, sol::object, sol::function)>(&Send)));

	actors.new_enum("ResponseStatus",
		"ConnectionClosed", postoffice::ResponseStatus::ConnectionClosed,
		"NoConnection", postoffice::ResponseStatus::NoConnection,
		"RoutingFailed", postoffice::ResponseStatus::RoutingFailed,
		"AmbiguousRecipient", postoffice::ResponseStatus::AmbiguousRecipient);

	return actors;
}

void LuaActors::Start()
{
}

void LuaActors::Stop()
{
}

void LuaActors::Process()
{
	for (auto& dropbox_it = s_dropboxes.begin(); dropbox_it != s_dropboxes.end();)
	{
		auto ptr = dropbox_it->second.lock();
		if (ptr)
		{
			ptr->Process();
			++dropbox_it;
		}
		else
		{
			dropbox_it = s_dropboxes.erase(dropbox_it);
		}
	}

	for (auto& callback : s_queue)
	{
		callback->Run();
	}

	s_queue.clear();
}

} // namespace mq::lua
