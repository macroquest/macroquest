/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2022 MacroQuest Authors
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

#include "loader/MacroQuest.h"
#include "loader/PostOffice.h"
#include "routing/PostOffice.h"

#include <date/date.h>
#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/wincolor_sink.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <variant>

// TODO: callbacks can likely be simplified to just making sure we carry the sequence ID back to the source, which will do the callback lookup there
constexpr uint16_t DEFAULT_ACTOR_PEER_PORT = 7781;

using namespace postoffice;

using Container = ActorContainer;
using Network = Container::Network;
using Identification = ActorIdentification;
using Client = Identification::Client;

template <typename T>
struct ConnectionTypeMap;

template <> struct ConnectionTypeMap<uint32_t> { using Type = LocalConnection; };
template <> struct ConnectionTypeMap<Network> { using Type = PeerConnection; };

static std::optional<std::string> s_iniLocation;
static std::optional<GetCrashpadPipe> s_crashpadCallback;
static std::optional<RequestFocusCallback> s_requestFocusCallback;
static std::optional<std::function<void()>> s_triggerProcess;
static std::unordered_map<uint32_t, PostOfficeConfig> s_postOfficeConfigs;
std::optional<PostOfficeConfig> GetConfig(uint32_t index)
{
	const auto config = s_postOfficeConfigs.find(index);
	if (config != s_postOfficeConfigs.end())
		return config->second;

	return {};
}

// helper function to respond back for RPC messages with < 0 status
void RoutingFailed(
	int status,
	const PipeMessagePtr& message,
	const PipeMessageResponseCb& callback)
{
	// we can't assume that the mailbox exists here, so manually create the reply
	const auto envelope = ProtoMessage::Parse<proto::routing::Envelope>(message);
	proto::routing::Envelope outbound;
	*outbound.mutable_address() = envelope.return_address();
	outbound.set_payload(envelope.address().SerializeAsString());

	std::string data = outbound.SerializeAsString();
	if (callback == nullptr)
		message->SendReply(MQMessageId::MSG_ROUTE, data.data(), data.size(), static_cast<uint8_t>(status));
	else
		callback(status, std::make_unique<PipeMessage>(MQMessageId::MSG_ROUTE, data.data(), data.size()));
}

class LauncherPostOffice final : public PostOffice
{
public:
	LauncherPostOffice() = delete;
	LauncherPostOffice(const LauncherPostOffice&) = delete;
	LauncherPostOffice(LauncherPostOffice&&) = delete;
	LauncherPostOffice& operator=(const LauncherPostOffice&) = delete;
	LauncherPostOffice& operator=(LauncherPostOffice&&) = delete;

	explicit LauncherPostOffice(uint32_t index);
	~LauncherPostOffice() override = default;

	// TODO: This isn't right, it's only checking the address and not the container
	static bool IsRecipient(const proto::routing::Address& address, const Identification& id)
	{
		return std::visit(overload{
			[&address](const std::string& name) { return address.has_name() && ci_equals(name, address.name()); },
			[&address](const Client& client)
			{
				return address.has_client() &&
					(!address.client().has_account() || ci_equals(client.account, address.client().account())) &&
					(!address.client().has_server() || ci_equals(client.server, address.client().server())) &&
					(!address.client().has_character() || ci_equals(client.character, address.client().character()));
			}
		}, id.address);
	}

	auto FindIdentity(
		const proto::routing::Address& address,
		const std::unordered_multimap<Container, Identification>::iterator& from)
	{
		return std::find_if(from, m_identities.end(),
			[&address](const std::pair<Container, Identification>& pair)
			{ return IsRecipient(address, pair.second); });
	}

	// This is called when a dropbox registered to this pipe server attempts to send a message
	void RouteMessage(PipeMessagePtr&& message, const PipeMessageResponseCb& callback) override
	{
		const auto envelope = ProtoMessage::Parse<proto::routing::Envelope>(message);
		const auto& address = envelope.address();

		// if we have a PID here, we could still have multiple names on the same PID, so we can't
		// avoid the loop
		if (message->GetRequestMode() == MQRequestMode::CallAndResponse || callback != nullptr)
		{
			const auto identity = FindIdentity(envelope.address(), m_identities.begin());

			if (identity == m_identities.end())
				RoutingFailed(MsgError_RoutingFailed, message, callback);
			else if (FindIdentity(envelope.address(), std::next(identity)) != m_identities.end())
				RoutingFailed(MsgError_AmbiguousRecipient, message, callback);
			else
			{
				message->SetRequestMode(MQRequestMode::CallAndResponse);
				SendMessage(identity->first, std::move(message), callback);
			}
		}
		else
		{
			// we don't have a PID or a name and this is not an RPC, so we will send this message to 
			// all clients that match the address -- it's important to copy these messages
			for (const auto& identity : m_identities)
			{
				if (IsRecipient(address, identity.second))
				{
					SendMessage(
						identity.first,
						std::make_unique<PipeMessage>(*message->GetHeader(), message->get(), message->size()),
						callback);
				}
			}
		}
	}

	void ProcessPostOffice()
	{
		if (m_processing)
		{
			m_needsProcessing = true;
			return;
		}

		m_processing = true;

		ProcessConnections();
		Process(10);

		m_processing = false;

		if (m_needsProcessing)
		{
			m_needsProcessing = false;
			if (s_triggerProcess) (*s_triggerProcess)();
		}
	}

	void AddIdentity(const Identification& id)
	{
		DropIdentity(id); // make sure we remove any duplicates

		m_identities.emplace(id.container, id);
		SPDLOG_INFO("Got identification from {}", id);

		// we also need to update all the clients
		BroadcastMessage(MQMessageId::MSG_IDENTIFICATION, id.GetProto());
	}

	void DropIdentity(const Identification& id)
	{
		for (auto ident_it = m_identities.begin(); ident_it != m_identities.end();)
		{
			if (ident_it->second.IsDuplicate(id))
			{
				BroadcastMessage(MQMessageId::MSG_DROPPED, ident_it->second.GetProto());
				ident_it = m_identities.erase(ident_it);
			}
			else
				++ident_it;
		}
	}

	void DropContainer(const Container& container)
	{
		const auto range = m_identities.equal_range(container);
		for (auto it = range.first; it != range.second; ++it)
		{
			// TODO: does this need to exclude the dropped container?
			BroadcastMessage(MQMessageId::MSG_DROPPED, it->second.GetProto());
		}

		m_identities.erase(container);
	}

	void SendIdentities(const Container& requester)
	{
		for (const auto& [_, client] : m_identities)
		{
			proto::routing::Identification id = client.GetProto();

			const auto payload = std::make_unique<uint8_t[]>(id.ByteSizeLong());
			id.SerializeToArray(payload.get(), static_cast<int>(id.ByteSizeLong()));

			SendMessage(requester,
				std::make_unique<PipeMessage>(MQMessageId::MSG_IDENTIFICATION, payload.get(), id.ByteSizeLong()),
				nullptr);
		}
	}

	// TODO: add callback handling to this as well
	void Route(const proto::routing::Envelope& message)
	{
		const auto& address = message.address();

		auto make_message = [&message]
			{
				const auto payload = std::make_unique<uint8_t[]>(message.ByteSizeLong());
				message.SerializeToArray(payload.get(), static_cast<int>(message.ByteSizeLong()));

				return std::make_unique<PipeMessage>(mq::MQMessageId::MSG_ROUTE,
					payload.get(), message.ByteSizeLong());
			};

		// curry out the callback in the failure helper
		auto routing_failed = [](int status, PipeMessagePtr&& message)
			{ RoutingFailed(status, message, nullptr); };

		// we want to deliver the message to launcher _and then_ forward it to other launchers
		// TODO: how do we only deliver to the local launcher? -- by setting peer to "127.0.0.1" (0 port would be fine)

		// TODO: make sure network messages set the pid before passing it along to be routed (pipe messages can be either)
		// we have to intentionally and explicitly handle the case where something is addressed to this peer
		// for any mailbox we have registered here
		if ((address.has_pid() && address.pid() == GetCurrentProcessId()) ||
			(!address.has_pid() && !address.has_peer() && address.has_name() && ci_equals(address.name(), "launcher")))
		{
			if (!address.has_pid())
			{
				// if we don't have a PID, then we have a launcher that needs to be routed out, so we need a copy of the message
				RouteMessage(make_message(), nullptr);
			}

			if (address.has_mailbox())
			{
				// this is a local message
				DeliverTo(address.mailbox(), make_message(), routing_failed);
			}
			else
			{
				// This is a failsafe action, we shouldn't expect to be here often. For this code to
				// be reached, we would have to have a client that packages a message in an envelope
				// that is intended to be parsed directly by the server and not routed anywhere (so
				// no mailbox routing information is included), rather than just send the message
				DeliverTo("post_office", make_message(), routing_failed);
			}
		}
		else
		{
			// forward everything else (pid is _not_ this and (pid, peer, or name is not launcher)
			// all we have to do here is route, this is the same as if an internal mailbox is
			// attempting to route a message
			// note: this is calling the same callback that gets called when something is trying to send
			//       a message from their registered dropboxes, care needs to be taken to avoid infinite
			//       message loops because of that
			RouteMessage(make_message(), nullptr);
		}
	}

	void Initialize()
	{
		m_serverDropbox = RegisterAddress("post_office",
			[this](ProtoMessagePtr&& message)
			{
				// if we've gotten here, then something is delivering a message to this
				// post office ("post_office"), so handle messages directly
			});

		// request IDs from all pre-existing connections
		// we could theoretically just ask a single peer but this will guarantee we have all
		// potential addresses
		BroadcastMessage(std::make_unique<PipeMessage>(MQMessageId::MSG_IDENTIFICATION, nullptr, 0));
	}

	void Shutdown()
	{
		// after the mailbox is removed from the post office, it won't get any more messages, and let's
		// make sure all remaining messages get discarded by dropping the last reference, so we stop
		// processing
		m_serverDropbox.Remove();
	}

	template <typename I, typename C = typename ConnectionTypeMap<I>::Type>
	const std::unique_ptr<C>& GetConnection()
	{
		static_assert(std::is_same_v<I, C>, "Type does not point to a valid connection.");
	}

private:
	std::unordered_multimap<Container, Identification> m_identities;

	Dropbox m_serverDropbox;
	const std::unique_ptr<LocalConnection> m_localConnection;
	const std::unique_ptr<PeerConnection> m_peerConnection;

	bool m_processing = false;
	bool m_needsProcessing = false;

	template <size_t I = 0> void ProcessConnections();
	template <size_t I = 0> void BroadcastMessage(PipeMessagePtr&& message);
	template <typename T> void BroadcastMessage(const MQMessageId& id, const T& proto);
	bool SendMessage(const Container& ident, PipeMessagePtr&& message, const PipeMessageResponseCb& callback);
};

// This is the actual pipe connection handler -- it's important that it is separate from the post office
class PipeEventsHandler final : public NamedPipeEvents
{
public:
	explicit PipeEventsHandler(LocalConnection* connection) : m_connection(connection) {}

	// This is called when a message is received over the pipe connection
	void OnIncomingMessage(PipeMessagePtr&& message) override
	{
		m_connection->RouteFromPipe(std::move(message));
	}

	void OnRequestProcessEvents() override
	{
		if (s_triggerProcess) (*s_triggerProcess)();
	}

	void OnIncomingConnection(int connectionId, int processId) override
	{
		const std::string namedPipe = s_crashpadCallback ? (*s_crashpadCallback)() : "";

		// send the name of the named pipe to the connected client. If crashpad isn't
		// enabled, or shared is disabled, this will send an empty string, which basically
		// tells the process that its on its own.
		m_connection->RouteToPipe(connectionId,
			mq::MakeSimpleMessageV0(MQMessageId::MSG_MAIN_CRASHPAD_CONFIG,
				namedPipe.c_str(), static_cast<uint32_t>(namedPipe.length()) + 1));
	}

	void OnConnectionClosed(int connectionId, int processId) override
	{
		m_connection->DropProcessId(static_cast<uint32_t>(processId));
	}

private:
	LocalConnection* m_connection;
};

std::string GetPipePath(uint32_t index)
{
	const auto config = GetConfig(index);
	return config && config->PipeName ? *config->PipeName : mq::MQ_PIPE_SERVER_PATH;
}

LauncherPostOffice::LauncherPostOffice(uint32_t index)
	: m_localConnection(std::make_unique<LocalConnection>(this, index))
	, m_peerConnection(std::make_unique<PeerConnection>(this, index))
{
	Identification id(GetCurrentProcessId(), "launcher");
	m_identities.emplace(id.container, id);
}

template <>
const std::unique_ptr<LocalConnection>& LauncherPostOffice::GetConnection<uint32_t>()
{
	return m_localConnection;
}

template <>
const std::unique_ptr<PeerConnection>& LauncherPostOffice::GetConnection<Network>()
{
	return m_peerConnection;
}

template <size_t I>
void LauncherPostOffice::ProcessConnections()
{
	using V = std::remove_const_t<decltype(Container::value)>;
	if constexpr (I < std::variant_size_v<V>)
	{
		GetConnection<std::variant_alternative_t<I, V>>()->Process();
		ProcessConnections<I + 1>();
	}
}

template <size_t I>
void LauncherPostOffice::BroadcastMessage(PipeMessagePtr&& message)
{
	using V = std::remove_const_t<decltype(Container::value)>;
	if constexpr (I < std::variant_size_v<V>)
	{
		// copy the message for broadcasting on each connection
		GetConnection<std::variant_alternative_t<I, V>>()->BroadcastMessage(
			std::make_unique<PipeMessage>(*message->GetHeader(), message->get(), message->size()));
		BroadcastMessage<I + 1>(std::move(message));
	}
}

template <typename T>
void LauncherPostOffice::BroadcastMessage(const MQMessageId& id, const T& proto)
{
	const auto payload = std::make_unique<uint8_t[]>(proto.ByteSizeLong());
	proto.SerializeToArray(payload.get(), static_cast<int>(proto.ByteSizeLong()));

	BroadcastMessage(std::make_unique<PipeMessage>(id, payload.get(), proto.ByteSizeLong()));
}

bool LauncherPostOffice::SendMessage(
	const Container& ident,
	PipeMessagePtr&& message,
	const PipeMessageResponseCb& callback)
{
	return std::visit([this, message = std::move(message), &callback](const auto& c) mutable
		{
			return GetConnection<std::remove_const_t<std::remove_reference_t<decltype(c)>>>()->SendMessage(c, std::move(message), callback);
		}, ident.value);
}

// this map is exclusively to allow testing by standing up multiple post offices
static std::unordered_map<uint32_t, LauncherPostOffice> s_postOffices;
template <>
LauncherPostOffice& postoffice::GetPostOffice<LauncherPostOffice>(uint32_t index)
{
	auto it = s_postOffices.find(index);
	if (it == s_postOffices.end())
		it = s_postOffices.emplace(index, index).first;

	return it->second;
}

template <>
PostOffice& postoffice::GetPostOffice<PostOffice>(uint32_t index)
{
	return postoffice::GetPostOffice<LauncherPostOffice>(index);
}

//----------------------------------------------------------------------------
// HELPER FUNCTIONS -- try to minimize refactoring
//----------------------------------------------------------------------------

bool SendSetForegroundWindow(HWND hWnd, uint32_t processID)
{
	return GetPostOffice<LauncherPostOffice>().GetConnection<uint32_t>()->SendSetForegroundWindow(hWnd, processID);
}

void SendUnloadAllCommand()
{
	GetPostOffice<LauncherPostOffice>().GetConnection<uint32_t>()->SendUnloadAllCommand();
}

void SendForceUnloadAllCommand()
{
	GetPostOffice<LauncherPostOffice>().GetConnection<uint32_t>()->SendForceUnloadAllCommand();
}

//----------------------------------------------------------------------------

void SetPostOfficeConfig(uint32_t index, const PostOfficeConfig& config)
{
	s_postOfficeConfigs[index] = config;
}

void DropPostOfficeConfig(uint32_t index)
{
	s_postOfficeConfigs.erase(index);
}

void ClearPostOfficeConfigs()
{
	s_postOfficeConfigs.clear();
}

void ClearPostOffices()
{
	for (auto& [_, post_office] : s_postOffices)
		post_office.Shutdown();

	s_postOffices.clear();
}

void SetPostOfficeIni(std::string_view ini)
{
	s_iniLocation = ini;
}

void SetCrashpadCallback(const GetCrashpadPipe& getCrashpad)
{
	s_crashpadCallback = getCrashpad;
}

void SetRequestFocusCallback(const RequestFocusCallback& requestFocus)
{
	s_requestFocusCallback = requestFocus;
}

void SetTriggerPostOffice(const std::function<void()>& triggerProcess)
{
	s_triggerProcess = triggerProcess;
}

void ProcessPostOffice(uint32_t index)
{
	GetPostOffice<LauncherPostOffice>(index).ProcessPostOffice();
}

void InitializePostOffice(uint32_t index)
{
	GetPostOffice<LauncherPostOffice>(index).Initialize();
}

void ShutdownPostOffice(uint32_t index)
{
	GetPostOffice<LauncherPostOffice>(index).Shutdown();
	s_postOffices.erase(index);
}

//----------------------------------------------------------------------------

