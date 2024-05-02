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
#include "loader/Crashpad.h"
#include "loader/LoaderAutoLogin.h"
#include "routing/PostOffice.h"
#include "loader/Network.h"

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

class LauncherPostOffice;
class Connection
{
public:
	Connection() = delete;
	Connection(const Connection&) = default;
	Connection(Connection&&) = default;
	Connection& operator=(const Connection&) = default;
	Connection& operator=(Connection&&) = default;
	virtual ~Connection() = default;

	explicit Connection(LauncherPostOffice* postOffice)
		: m_postOffice(postOffice)
	{}

	virtual void Initialize() {}
	virtual void Shutdown() {}
	virtual void Process() = 0;

	virtual bool SendMessage(uint32_t pid, PipeMessagePtr&& message, const PipeMessageResponseCb& callback) = 0;
	virtual bool SendMessage(const Network& peer, PipeMessagePtr&& message, const PipeMessageResponseCb& callback) = 0;
	virtual void BroadcastMessage(PipeMessagePtr&& message) = 0;

protected:
	LauncherPostOffice* m_postOffice;
};

template <typename T>
Connection* GetConnection()
{
	static_assert(false, "Type does not point to a valid connection.");
}

template <>
Connection* GetConnection<uint32_t>();

template <>
Connection* GetConnection<Network>();

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

class LauncherPostOffice : public PostOffice
{
public:
	LauncherPostOffice()
	{
		Identification id(GetCurrentProcessId(), "launcher");
		m_identities.emplace(id.container, id);
	}

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
			PostMessageA(hMainWnd, WM_USER_CALLBACK, 0, 0);
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
		InitializeConnections();

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

		ShutdownConnections();
	}

private:
	std::unordered_multimap<Container, Identification> m_identities;

	Dropbox m_serverDropbox;

	bool m_processing = false;
	bool m_needsProcessing = false;

	template <std::size_t I = 0>
	void ProcessConnections() const
	{
		using V = decltype(Container::value);
		if constexpr (I < std::variant_size_v<V>)
		{
			GetConnection<std::variant_alternative_t<I, V>>()->Process();
			ProcessConnections<I + 1>();
		}
	}

	template <std::size_t I = 0>
	void InitializeConnections() const
	{
		using V = decltype(Container::value);
		if constexpr (I < std::variant_size_v<V>)
		{
			GetConnection<std::variant_alternative_t<I, V>>()->Initialize();
			InitializeConnections<I + 1>();
		}
	}

	template <std::size_t I = 0>
	void ShutdownConnections() const
	{
		using V = decltype(Container::value);
		if constexpr (I < std::variant_size_v<V>)
		{
			GetConnection<std::variant_alternative_t<I, V>>()->Shutdown();
			ShutdownConnections<I + 1>();
		}
	}

	template <std::size_t I = 0>
	void BroadcastMessage(PipeMessagePtr&& message)
	{
		using V = decltype(Container::value);
		if constexpr (I < std::variant_size_v<V>)
		{
			// copy the message for broadcasting on each connection
			GetConnection<std::variant_alternative_t<I, V>>()->BroadcastMessage(
				std::make_unique<PipeMessage>(*message->GetHeader(), message->get(), message->size()));
			BroadcastMessage<I + 1>(std::move(message));
		}
	}

	template <typename T>
	void BroadcastMessage(const MQMessageId& id, const T& proto)
	{
		const auto payload = std::make_unique<uint8_t[]>(proto.ByteSizeLong());
		proto.SerializeToArray(payload.get(), static_cast<int>(proto.ByteSizeLong()));

		BroadcastMessage(std::make_unique<PipeMessage>(id, payload.get(), proto.ByteSizeLong()));
	}

	bool SendMessage(
		const Container& ident,
		PipeMessagePtr&& message,
		const PipeMessageResponseCb& callback)
	{
		return std::visit([this, message = std::move(message), &callback](const auto& c) mutable
		{
			return GetConnection<decltype(c)>()->SendMessage(c, std::move(message), callback);
		}, ident.value);
	}
};

// This is the actual pipe connection handler -- it's important that it is separate from the post office
class PipeEventsHandler final : public Connection, public NamedPipeEvents, public std::enable_shared_from_this<PipeEventsHandler>
{
public:
	explicit PipeEventsHandler(LauncherPostOffice* postOffice)
		: Connection(postOffice)
		, m_pipeServer{ mq::MQ_PIPE_SERVER_PATH }
	{}

	void Initialize() override
	{
		m_pipeServer.SetHandler(shared_from_this());
		m_pipeServer.Start();
	}

	void Shutdown() override
	{
		// we don't need to worry about sending messages after we stop because the pipe client will log
		// and handle this situation.
		m_pipeServer.Stop();
	}

	void Process() override
	{
		m_pipeServer.Process();
	}

	bool SendMessage(
		uint32_t pid,
		PipeMessagePtr&& message,
		const PipeMessageResponseCb& callback) override
	{
		if (pid == GetCurrentProcessId())
		{
			// send to self, dispatch directly to the handler
			m_pipeServer.DispatchMessage(std::move(message));
			return true;
		}

		if (const auto connection = m_pipeServer.GetConnectionForProcessId(pid))
		{
			// found a connection to send it over
			if (callback != nullptr)
				connection->SendMessageWithResponse(std::move(message), callback);
			else
				connection->SendMessage(std::move(message));
			return true;
		}

		SPDLOG_WARN("Unable to get connection for PID {}, message route failed.", pid);
		RoutingFailed(MsgError_NoConnection, message, callback);
		return false;
	}

	bool SendMessage(
		const Network& peer,
		PipeMessagePtr&& message,
		const PipeMessageResponseCb& callback) override
	{
		SPDLOG_WARN("Attempted to send to peer {} over local pipe", peer);
		RoutingFailed(MsgError_NoConnection, message, callback);
		return false;
	}

	void BroadcastMessage(PipeMessagePtr&& message) override
	{
		m_pipeServer.BroadcastMessage(std::move(message));
	}

	// This is called when a message is received over the pipe connection
	void OnIncomingMessage(PipeMessagePtr&& message) override
	{
		using namespace mq::proto;
		SPDLOG_TRACE("Received message: id={} length={} connectionId={}", message->GetMessageId(),
			message->size(), message->GetConnectionId());

		switch (message->GetMessageId())
		{
		case mq::MQMessageId::MSG_ECHO:
		{
			std::string str(message->get<const char>(), message->size() - 1);
			message->SendReply(MQMessageId::MSG_ECHO, str.data(), static_cast<uint32_t>(str.length()) + 1, 0);
			SPDLOG_INFO("Handling echo request: {}", str);
			break;
		}

		case mq::MQMessageId::MSG_ROUTE:
			m_postOffice->Route(ProtoMessage::Parse<proto::routing::Envelope>(message));
			break;

		case mq::MQMessageId::MSG_IDENTIFICATION:
			if (message->GetHeader()->messageLength > 0)
			{
				// if there is a payload, then we are getting a notification of ID
				// send this to the post office to process in the launcher dropbox
				m_postOffice->AddIdentity(Identification(ProtoMessage::Parse<proto::routing::Identification>(message)));
			}
			else if (const auto& conn = m_pipeServer.GetConnection(message->GetConnectionId()))
			{
				// we are getting a request to send all IDs, do so sequentially and asynchronously
				// send this to the post office to process in the launcher dropbox
				m_postOffice->SendIdentities(Container(conn->GetProcessId()));
			}

			break;

		case mq::MQMessageId::MSG_DROPPED:
			m_postOffice->DropIdentity(Identification(ProtoMessage::Parse<proto::routing::Identification>(message)));
			break;

		case mq::MQMessageId::MSG_MAIN_PROCESS_UNLOADED:
			break;

		case mq::MQMessageId::MSG_MAIN_PROCESS_LOADED:
		{
			MQMessageProcessLoadedResponse response;
			response.processId = GetCurrentProcessId();

			m_pipeServer.SendMessage(message->GetConnectionId(), mq::MQMessageId::MSG_MAIN_PROCESS_LOADED,
				&response, sizeof(response));
			break;
		}

		case mq::MQMessageId::MSG_MAIN_FOCUS_REQUEST: {
			if (message->size() >= sizeof(MQMessageFocusRequest))
			{
				const MQMessageFocusRequest* request = message->get<MQMessageFocusRequest>();
				if (request->focusMode == MQMessageFocusRequest::FocusMode::HasFocus)
				{
					SetFocusWindowPID(request->processId, request->state);
				}
				else if (request->focusMode == MQMessageFocusRequest::FocusMode::WantFocus)
				{
					SetForegroundWindowInternal(static_cast<HWND>(request->hWnd));
				}
			}
			break;
		}

		default: break;
		}
	}

	void OnRequestProcessEvents() override
	{
		PostMessageA(hMainWnd, WM_USER_CALLBACK, 0, 0);
	}

	void OnIncomingConnection(int connectionId, int processId) override
	{
		std::string namedPipe;

		if (IsCrashpadInitialized() && gEnableSharedCrashpad)
		{
			namedPipe = GetHandlerIPCPipe();
		}

		// send the name of the named pipe to the connected client. If crashpad isn't
		// enabled, or shared is disabled, this will send an empty string, which basically
		// tells the process that its on its own.
		m_pipeServer.SendMessage(connectionId,
			mq::MakeSimpleMessageV0(MQMessageId::MSG_MAIN_CRASHPAD_CONFIG,
				namedPipe.c_str(), static_cast<uint32_t>(namedPipe.length()) + 1));
	}

	void OnConnectionClosed(int connectionId, int processId) override
	{
		m_postOffice->DropContainer(Container(processId));
	}

	bool SendSetForegroundWindow(HWND hWnd, uint32_t processID)
	{
		if (processID != 0)
		{
			if (const auto connection = m_pipeServer.GetConnectionForProcessId(processID))
			{
				MQMessageActivateWnd message;
				message.hWnd = hWnd;

				m_pipeServer.SendMessage(connection->GetConnectionId(),
					mq::MQMessageId::MSG_MAIN_FOCUS_ACTIVATE_WND, &message, sizeof(message));

				return true;
			}
		}

		return false;
	}

	void SendUnloadAllCommand()
	{
		SPDLOG_DEBUG("Requesting to unload all instances");
		m_pipeServer.BroadcastMessage(mq::MQMessageId::MSG_MAIN_REQ_UNLOAD, nullptr, 0);
	}

	void SendForceUnloadAllCommand()
	{
		SPDLOG_DEBUG("Requesting to FORCE unload all instances");
		m_pipeServer.BroadcastMessage(mq::MQMessageId::MSG_MAIN_REQ_FORCEUNLOAD, nullptr, 0);
	}

private:
	mq::ProtoPipeServer m_pipeServer;
};

class PeerEventsHandler final : public Connection
{
public:
	// TODO: make the port configurable (default to 7781)
	explicit PeerEventsHandler(LauncherPostOffice* postOffice)
		: Connection(postOffice)
		, m_network(NetworkPeerAPI::GetOrCreate(
			DEFAULT_ACTOR_PEER_PORT,
			[this](const std::string& address, uint16_t port, std::unique_ptr<uint8_t[]>&& payload, size_t length)
			{
				using proto::routing::NetworkMessage;

				NetworkMessage inbound;
				inbound.ParseFromArray(payload.get(), static_cast<int>(length));

				auto source_addr = Network{ address, port };

				switch (inbound.contents_case())
				{
				case NetworkMessage::kAdd:
					m_postOffice->AddIdentity(Identification(
						std::move(source_addr), Identification::GetAddress(inbound.add().id())));
					break;
				case NetworkMessage::kDrop:
					m_postOffice->DropIdentity(Identification(
						std::move(source_addr), Identification::GetAddress(inbound.drop().id())));
					break;
				case NetworkMessage::kRequest:
					m_postOffice->SendIdentities(Container(source_addr));
					break;
				case NetworkMessage::kRouted:
					if (inbound.routed().has_return_address())
					{
						inbound.mutable_routed()->mutable_return_address()->clear_pid();
						inbound.mutable_routed()->mutable_return_address()->mutable_peer()->set_ip(address);
						inbound.mutable_routed()->mutable_return_address()->mutable_peer()->set_port(port);
					}

					// if the address is not on the pipe, this will fail or route back out to the network if the client has a peer container
					m_postOffice->Route(inbound.routed());
					break;
				default:
					SPDLOG_WARN("Got unknown inbound message type {}", inbound.contents_case());
					break;
				}
			}))
	{}

	void Initialize() override
	{
		for (const auto& [address, port]:GetPrivateProfileKeyValues("NetworkPeers", internal_paths::MQini))
		{
			// TODO: use configured port here as well
			m_network.AddHost(address, static_cast<uint16_t>(GetUIntFromString(port, DEFAULT_ACTOR_PEER_PORT)));
		}
	}

	void Shutdown() override
	{
		m_network.Shutdown();
	}

	// This does nothing now, but if we ever have timed maintenance tasks, they would go here
	void Process() override {}

	bool SendMessage(uint32_t pid, PipeMessagePtr&& message, const PipeMessageResponseCb& callback) override
	{
		SPDLOG_WARN("Attempted to send to pid {} over network", pid);
		RoutingFailed(MsgError_NoConnection, message, callback);
		return false;
	}

	// TODO: wrap this callback? how do we handle callbacks sent over the network? We've lost the sequence ID
	bool SendMessage(const Network& peer, PipeMessagePtr&& message, const PipeMessageResponseCb& callback) override
	{
		// the network library handles routing of any address (we can't short circuit local IP
		// detection because it needs knowledge of the network)
		if (m_network.HasHost(peer.IP, peer.Port))
		{
			// the network has the host (we do this in order to provide routing errors)
			const auto outbound = Translate(message);
			auto payload = std::make_unique<uint8_t[]>(outbound.ByteSizeLong());
			outbound.SerializeToArray(payload.get(), static_cast<int>(outbound.ByteSizeLong()));

			m_network.Send(peer.IP, peer.Port, std::move(payload), outbound.ByteSizeLong());
			return true;
		}

		SPDLOG_WARN("Unable to find peer for address {}:{}, message route failed.", peer.IP, peer.Port);
		RoutingFailed(MsgError_NoConnection, message, callback);
		return false;

	}

	void BroadcastMessage(PipeMessagePtr&& message) override
	{
		const auto outbound = Translate(message);
		auto payload = std::make_unique<uint8_t[]>(outbound.ByteSizeLong());
		outbound.SerializeToArray(payload.get(), static_cast<int>(outbound.ByteSizeLong()));

		m_network.Broadcast(std::move(payload), outbound.ByteSizeLong());
	}

	// TODO: need add_connection/remove_connection callbacks in NetworkAPI

private:
	NetworkPeerAPI m_network;

	static proto::routing::NetworkMessage Translate(const PipeMessagePtr& message)
	{
		proto::routing::NetworkMessage inbound;
		switch (message->GetMessageId())
		{
		case MQMessageId::MSG_IDENTIFICATION:
			if (message->GetHeader()->messageLength > 0)
				*inbound.mutable_add()->mutable_id() = ProtoMessage::Parse<proto::routing::Identification>(message);
			else
				// if we have a pipe message, then the requester must be this PID (destination networks will translate from pid to network)
				inbound.mutable_request()->set_pid(GetCurrentProcessId());
			break;
		case MQMessageId::MSG_DROPPED:
			*inbound.mutable_drop()->mutable_id() = ProtoMessage::Parse<proto::routing::Identification>(message);
			break;
		case MQMessageId::MSG_ROUTE:
			*inbound.mutable_routed() = ProtoMessage::Parse<proto::routing::Envelope>(message);
			break;
		default:
			SPDLOG_WARN("Attempted to translate a pipe message of unknown type {}, empty message returned", message->GetMessageId());
			break;
		}

		return inbound;
	}
};

PostOffice& postoffice::GetPostOffice()
{
	static LauncherPostOffice s_postOffice;
	return s_postOffice;
}

template <>
Connection* GetConnection<uint32_t>()
{
	static auto pipeConnection = PipeEventsHandler(dynamic_cast<LauncherPostOffice*>(&GetPostOffice()));
	return &pipeConnection;
}

template <>
Connection* GetConnection<Network>()
{
	static auto peerConnection = PeerEventsHandler(dynamic_cast<LauncherPostOffice*>(&GetPostOffice()));
	return &peerConnection;
}

//----------------------------------------------------------------------------
// HELPER FUNCTIONS -- try to minimize refactoring
//----------------------------------------------------------------------------

bool SendSetForegroundWindow(HWND hWnd, uint32_t processID)
{
	return dynamic_cast<PipeEventsHandler*>(GetConnection<uint32_t>())->SendSetForegroundWindow(hWnd, processID);
}

void SendUnloadAllCommand()
{
	dynamic_cast<PipeEventsHandler*>(GetConnection<uint32_t>())->SendUnloadAllCommand();
}

void SendForceUnloadAllCommand()
{
	dynamic_cast<PipeEventsHandler*>(GetConnection<uint32_t>())->SendForceUnloadAllCommand();
}

void ProcessPostOffice()
{
	dynamic_cast<LauncherPostOffice&>(GetPostOffice()).ProcessPostOffice();
}

void InitializeNamedPipeServer()
{
	dynamic_cast<LauncherPostOffice&>(GetPostOffice()).Initialize();
}

void ShutdownNamedPipeServer()
{
	dynamic_cast<LauncherPostOffice&>(GetPostOffice()).Shutdown();
}

//----------------------------------------------------------------------------

