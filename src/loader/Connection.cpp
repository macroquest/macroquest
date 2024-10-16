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

// Uncomment to see super spammy read/write trace logging
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

#include "loader/MacroQuest.h"
#include "loader/PostOffice.h"
#include "routing/ProtoPipes.h" // LocalConnection
#include "routing/Network.h" // PeerConnection

#include <date/date.h>
#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/wincolor_sink.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <shellapi.h>

#include "ImGui.h"

using namespace mq::postoffice;

static std::optional<std::string> s_iniLocation;

void SetPostOfficeIni(std::string_view ini)
{
	s_iniLocation = ini;
}

// -------------------------- LocalConnection ---------------------------------

// pipe specific statics
static std::optional<GetCrashpadPipe> s_crashpadCallback;
static std::optional<std::function<void()>> s_triggerProcess;
static std::optional<RequestFocusCallback> s_requestFocusCallback;

void SetCrashpadCallback(const GetCrashpadPipe& getCrashpad)
{
	s_crashpadCallback = getCrashpad;
}

void SetTriggerPostOffice(const std::function<void()>& triggerProcess)
{
	s_triggerProcess = triggerProcess;
}

void SetRequestFocusCallback(const RequestFocusCallback& requestFocus)
{
	s_requestFocusCallback = requestFocus;
}

// This is the actual pipe connection handler -- it's important that it is separate from the post office
class PipeEventsHandler final : public NamedPipeEvents
{
public:
	explicit PipeEventsHandler(LocalConnection* connection)
		: m_connection(connection)
	{}

	// This is called when a message is received over the pipe connection
	void OnIncomingMessage(PipeMessagePtr&& message) override
	{
		SPDLOG_TRACE("{}: Received message id={} length={} connectionId={}",
			m_connection->GetPostOffice()->GetName(), static_cast<int>(message->GetMessageId()),
			message->size(), message->GetConnectionId());

		switch (message->GetMessageId())
		{
		case mq::MQMessageId::MSG_ECHO:
		{
			std::string str(message->get<const char>(), message->size() - 1);
			message->SendReply(MQMessageId::MSG_ECHO, str.data(), static_cast<uint32_t>(str.length()) + 1, 0);
			SPDLOG_INFO("{}: Handling echo request: {}", m_connection->GetPostOffice()->GetName(), str);
			break;
		}

		case mq::MQMessageId::MSG_ROUTE:
			m_connection->RouteFromPipe(ProtoMessage::Parse<proto::routing::Envelope>(message));
			break;

		case mq::MQMessageId::MSG_IDENTIFICATION:
			if (message->GetHeader()->messageLength > 0)
			{
				// if there is a payload, then we are getting a notification of ID
				// send this to the post office to process in the launcher dropbox
				m_connection->GetPostOffice()->AddIdentity(ActorIdentification(ProtoMessage::Parse<proto::routing::Identification>(message)));
			}
			else if (auto pipeServer = m_connection->GetPipeServer())
			{
				if (const auto& conn = pipeServer->GetConnection(message->GetConnectionId()))
				{
					// we are getting a request to send all IDs, do so sequentially and asynchronously
					// send this to the post office to process in the launcher dropbox
					m_connection->GetPostOffice()->SendIdentities(ActorContainer(conn->GetProcessId()));
				}
			}

			break;

		case mq::MQMessageId::MSG_DROPPED:
			m_connection->GetPostOffice()->DropIdentity(ActorIdentification(ProtoMessage::Parse<proto::routing::Identification>(message)));
			break;

		case mq::MQMessageId::MSG_MAIN_PROCESS_UNLOADED:
			break;

		case mq::MQMessageId::MSG_MAIN_PROCESS_LOADED:
			if (auto pipeServer = m_connection->GetPipeServer())
			{
				MQMessageProcessLoadedResponse response;
				response.processId = GetCurrentProcessId();

				pipeServer->SendMessage(message->GetConnectionId(), mq::MQMessageId::MSG_MAIN_PROCESS_LOADED,
					&response, sizeof(response));
			}
			break;

		case mq::MQMessageId::MSG_MAIN_FOCUS_REQUEST:
			if (message->size() >= sizeof(MQMessageFocusRequest) && s_requestFocusCallback)
			{
				(*s_requestFocusCallback)(message->get<MQMessageFocusRequest>());
			}
			break;

		case mq::MQMessageId::MSG_MAIN_MESSAGEBOX:
			if (const auto notification = ProtoMessage::Parse<proto::routing::Notification>(message);
				notification.has_message())
				LauncherImGui::OpenMessageBox(nullptr, notification.message(), notification.title());
			else
				LauncherImGui::OpenMessageBox(nullptr, notification.title(), notification.title());
			break;

		case mq::MQMessageId::MSG_MAIN_TRAY_NOTIFY:
		{
			const auto notification = ProtoMessage::Parse<proto::routing::Notification>(message);
			NOTIFYICONDATAA notify;
			notify.cbSize = sizeof(NOTIFYICONDATAA);
			notify.uID = WM_USER_SYSTRAY;
			notify.hWnd = hMainWnd;
			notify.uFlags = NIF_INFO;

			strcpy_s(notify.szInfoTitle, notification.title().c_str());
			if (notification.has_message())
				strcpy_s(notify.szInfo, notification.message().c_str());
			else
				strcpy_s(notify.szInfo, notification.title().c_str());

			if (notification.has_level())
			{
				switch (notification.level())
				{
				case proto::routing::NotifyLevel::Info:
					notify.dwInfoFlags = NIIF_INFO;
					break;
				case proto::routing::NotifyLevel::Warning:
					notify.dwInfoFlags = NIIF_WARNING;
					break;
				case proto::routing::NotifyLevel::Error:
					notify.dwInfoFlags = NIIF_ERROR;
					break;
				default:
					notify.dwInfoFlags = NIIF_INFO;
					break;
				}
			}
			else
				notify.dwInfoFlags = NIIF_INFO;

			Shell_NotifyIconA(NIM_MODIFY, &notify);
			break;
		}

		default: break;
		}
	}

	void OnRequestProcessEvents() override
	{
		if (s_triggerProcess) (*s_triggerProcess)();
		m_connection->RequestProcessEvents();
	}

	void OnIncomingConnection(int connectionId, int processId) override
	{
		if (auto pipeServer = m_connection->GetPipeServer())
		{
			const std::string namedPipe = s_crashpadCallback ? (*s_crashpadCallback)() : "";

			// send the name of the named pipe to the connected client. If crashpad isn't
			// enabled, or shared is disabled, this will send an empty string, which basically
			// tells the process that its on its own.
			pipeServer->SendMessage(connectionId,
				mq::MakeSimpleMessageV0(MQMessageId::MSG_MAIN_CRASHPAD_CONFIG,
					namedPipe.c_str(), static_cast<uint32_t>(namedPipe.length()) + 1));
		}
	}

	void OnConnectionClosed(int connectionId, int processId) override
	{
		m_connection->DropProcessId(static_cast<uint32_t>(processId));
	}

private:
	LocalConnection* m_connection;
};

std::string GetPipePath(LauncherPostOffice* postOffice)
{
	const auto& config = postOffice->GetConfig();
	return config.PipeName ? *config.PipeName : mq::MQ_PIPE_SERVER_PATH;
}

LocalConnection::LocalConnection(LauncherPostOffice* postOffice)
	: Connection(postOffice)
	, m_pipeServer(std::make_unique<ProtoPipeServer>(GetPipePath(postOffice).c_str()))
{
	m_pipeServer->SetHandler(std::make_shared<PipeEventsHandler>(this));
}

LocalConnection::~LocalConnection()
{}

void LocalConnection::Process()
{
	m_pipeServer->Process();
}

bool LocalConnection::SendMessage(
	uint32_t pid,
	proto::routing::Envelope&& message,
	const MessageResponseCallback& callback)
{
	const auto payload = std::make_unique<uint8_t[]>(message.ByteSizeLong());
	message.SerializeToArray(payload.get(), static_cast<int>(message.ByteSizeLong()));

	auto msg = std::make_unique<PipeMessage>(MQMessageId::MSG_ROUTE, payload.get(), message.ByteSizeLong());

	if (pid == GetCurrentProcessId())
	{
		// send to self, dispatch directly to the handler
		m_pipeServer->DispatchMessage(std::move(msg));
		return true;
	}

	if (const auto& connection = m_pipeServer->GetConnectionForProcessId(pid))
	{
		// found a connection to send it over
		if (callback != nullptr)
		{
			m_rpcs.emplace(message.sequence(), callback);
			connection->SendMessageWithResponse(std::move(msg),
				[this](int status, PipeMessagePtr&& message)
				{
					auto msg = ProtoMessage::Parse<proto::routing::Envelope>(message);
					if (const auto it = m_rpcs.find(msg.sequence()); it != m_rpcs.end())
					{
						msg.set_status(status);
						it->second(status, std::move(msg));
						m_rpcs.erase(it);
					}
					else
						SPDLOG_WARN("{}: Can't find RPC for message from local connection with sequence {}", msg.sequence());
				});
		}
		else
			connection->SendMessage(std::move(msg));
		return true;
	}

	SPDLOG_WARN("{}: Unable to get connection for PID {}, message route failed.", m_postOffice->GetName(), pid);
	m_postOffice->RoutingFailed(MsgError_NoConnection, std::move(message), callback);
	return false;
}

void mq::postoffice::LocalConnection::SendIdentification(uint32_t pid, const ActorIdentification& identity) const
{
	if (const auto& connection = m_pipeServer->GetConnectionForProcessId(pid))
	{
		proto::routing::Identification id = identity.GetProto();

		const auto payload = std::make_unique<uint8_t[]>(id.ByteSizeLong());
		id.SerializeToArray(payload.get(), static_cast<int>(id.ByteSizeLong()));

		connection->SendMessage(std::make_unique<PipeMessage>(MQMessageId::MSG_IDENTIFICATION, payload.get(), id.ByteSizeLong()));
	}
	else
		SPDLOG_WARN("{}: Unable to get connection for PID {}, identification message failed.", m_postOffice->GetName(), pid);
}

void mq::postoffice::LocalConnection::DropIdentification(uint32_t pid, const ActorIdentification& identity) const
{
	if (const auto& connection = m_pipeServer->GetConnectionForProcessId(pid))
	{
		proto::routing::Identification id = identity.GetProto();

		const auto payload = std::make_unique<uint8_t[]>(id.ByteSizeLong());
		id.SerializeToArray(payload.get(), static_cast<int>(id.ByteSizeLong()));

		connection->SendMessage(std::make_unique<PipeMessage>(MQMessageId::MSG_DROPPED, payload.get(), id.ByteSizeLong()));
	}
	else
		SPDLOG_WARN("{}: Unable to get connection for PID {}, drop message failed.", m_postOffice->GetName(), pid);
}

// TODO: this could be RPC
void mq::postoffice::LocalConnection::RequestIdentities(uint32_t pid) const
{
	if (const auto& connection = m_pipeServer->GetConnectionForProcessId(pid))
	{
		connection->SendMessage(std::make_unique<PipeMessage>(MQMessageId::MSG_IDENTIFICATION, nullptr, 0));
	}
	else
		SPDLOG_WARN("{}: Unable to get connection for PID {}, send request failed.", m_postOffice->GetName(), pid);
}

void LocalConnection::BroadcastMessage(proto::routing::Envelope&& message)
{
	const auto payload = std::make_unique<uint8_t[]>(message.ByteSizeLong());
	message.SerializeToArray(payload.get(), static_cast<int>(message.ByteSizeLong()));

	m_pipeServer->BroadcastMessage(std::make_unique<PipeMessage>(MQMessageId::MSG_ROUTE, payload.get(), message.ByteSizeLong()));
}

void LocalConnection::RouteFromPipe(proto::routing::Envelope&& message)
{
	m_postOffice->RouteFromConnection(std::move(message));
}

void LocalConnection::DropProcessId(uint32_t processId) const
{
	m_postOffice->DropContainer(ActorContainer(processId));
}

void mq::postoffice::LocalConnection::Start()
{
	m_pipeServer->Start();
}

void mq::postoffice::LocalConnection::Stop()
{
	m_pipeServer->Stop();
}

bool LocalConnection::SendSetForegroundWindow(HWND hWnd, uint32_t processID)
{
	if (processID != 0)
	{
		if (const auto connection = m_pipeServer->GetConnectionForProcessId(processID))
		{
			MQMessageActivateWnd message;
			message.hWnd = hWnd;

			m_pipeServer->SendMessage(connection->GetConnectionId(),
					mq::MQMessageId::MSG_MAIN_FOCUS_ACTIVATE_WND, &message, sizeof(message));

			return true;
		}
	}

	return false;
}

void LocalConnection::SendUnloadAllCommand()
{
	SPDLOG_DEBUG("{}: Requesting to unload all instances", m_postOffice->GetName());
	m_pipeServer->BroadcastMessage(mq::MQMessageId::MSG_MAIN_REQ_UNLOAD, nullptr, 0);
}

void LocalConnection::SendForceUnloadAllCommand()
{
	SPDLOG_DEBUG("{}: Requesting to FORCE unload all instances", m_postOffice->GetName());
	m_pipeServer->BroadcastMessage(mq::MQMessageId::MSG_MAIN_REQ_FORCEUNLOAD, nullptr, 0);
}

// ------------------------ PeerConnection ------------------------------------

uint16_t GetPeerPort(LauncherPostOffice* postOffice)
{
	const auto config = postOffice->GetConfig();
	return config.PeerPort ? *config.PeerPort : DEFAULT_NETWORK_PEER_PORT;
}

PeerConnection::PeerConnection(LauncherPostOffice* postOffice)
	: Connection(postOffice)
	, m_network(std::make_unique<NetworkPeerAPI>(NetworkPeerAPI::GetOrCreate(
		GetPeerPort(postOffice),
		[this](const NetworkAddress& address, std::unique_ptr<uint8_t[]>&& payload, size_t length)
		{
			using proto::routing::NetworkMessage;

			NetworkMessage inbound;
			inbound.ParseFromArray(payload.get(), static_cast<int>(length));

			auto source_addr = ActorContainer::Network{ address.IP, address.Port };

			switch (inbound.contents_case())
			{
			case NetworkMessage::kAdd:
				m_postOffice->AddIdentity(ActorIdentification(
					std::move(source_addr), ActorIdentification::GetAddress(inbound.add().id())));
				break;
			case NetworkMessage::kDrop:
				m_postOffice->DropIdentity(ActorIdentification(
					std::move(source_addr), ActorIdentification::GetAddress(inbound.drop().id())));
				break;
			case NetworkMessage::kRequest:
				m_postOffice->SendIdentities(ActorContainer(source_addr));
				break;
			case NetworkMessage::kRouted:
			{
				proto::routing::Envelope routed = inbound.routed();
				if (routed.has_return_address())
				{
					routed.mutable_return_address()->clear_pid();
					routed.mutable_return_address()->mutable_peer()->set_ip(address.IP);
					routed.mutable_return_address()->mutable_peer()->set_port(address.Port);
				}

				// if this message has been routed here, then we need to let the local launcher handle any routing
				routed.mutable_address()->clear_pid();
				routed.mutable_address()->mutable_peer()->set_ip("127.0.0.1");
				routed.mutable_address()->mutable_peer()->set_port(m_network->GetPort());

				// if the address is not on the pipe, this will fail or route back out to the network if the client has a peer container
				m_postOffice->RouteFromConnection(std::move(routed));
				break;
			}
			default:
				SPDLOG_WARN("{}: Got unknown inbound message type {}", m_postOffice->GetName(), static_cast<int>(inbound.contents_case()));
				break;
			}
		},
		[this](const NetworkAddress& address)
		{
			// once the connect attempt is successful, send all known identities to the remote to sync
			m_postOffice->SendIdentities(ActorContainer(ActorContainer::Network{ address.IP, address.Port }));
		},
		[this](const NetworkAddress& address)
		{
			// let's just always reconnect to disconnected hosts
			AddHost(address.IP, address.Port);
		})))
{}

PeerConnection::~PeerConnection()
{
}

void mq::postoffice::PeerConnection::AddConfiguredHosts()
{
	const uint16_t default_port = GetPeerPort(m_postOffice);
	const auto config = m_postOffice->GetConfig();

	// TODO: add a way to add/remove hosts during runtime
	if (config.Peers)
	{
		for (const auto& [address, port] : *config.Peers)
		{
			AddHost(address, port > 0 ? port : default_port);
		}
	}
	else if (s_iniLocation)
	{
		for (const auto& [address, port_raw] : GetPrivateProfileKeyValues("NetworkPeers", *s_iniLocation))
		{
			const uint16_t port = static_cast<uint16_t>(GetUIntFromString(port_raw, 0));
			AddHost(address, port > 0 ? port : default_port);
		}
	}
}

// TODO: wrap this callback like we do for local connections -- this requires the network to handle RPC as well to work
bool PeerConnection::SendMessage(
	const ActorContainer::Network& peer,
	proto::routing::Envelope&& message,
	const MessageResponseCallback& callback)
{
	// the network library handles routing of any address (we can't short circuit local IP
	// detection because it needs knowledge of the network)
	if (m_network->HasHost(peer.IP, peer.Port))
	{
		// the network has the host (we do this in order to provide routing errors)
		proto::routing::NetworkMessage outbound;
		*outbound.mutable_routed() = std::move(message);
		auto payload = std::make_unique<uint8_t[]>(outbound.ByteSizeLong());
		outbound.SerializeToArray(payload.get(), static_cast<int>(outbound.ByteSizeLong()));

		m_network->Send(peer.IP, peer.Port, std::move(payload), outbound.ByteSizeLong());
		return true;
	}

	SPDLOG_WARN("{}: Unable to find peer for address {}:{}, message route failed.", m_postOffice->GetName(), peer.IP, peer.Port);
	m_postOffice->RoutingFailed(MsgError_NoConnection, std::move(message), callback);
	return false;

}

void mq::postoffice::PeerConnection::SendIdentification(const ActorContainer::Network& peer, const ActorIdentification& identity) const
{
	if (m_network->HasHost(peer.IP, peer.Port))
	{
		proto::routing::NetworkMessage outbound;
		proto::routing::AddIdentity& add = *outbound.mutable_add();
		*add.mutable_id() = identity.GetProto();

		auto payload = std::make_unique<uint8_t[]>(outbound.ByteSizeLong());
		outbound.SerializeToArray(payload.get(), static_cast<int>(outbound.ByteSizeLong()));
		m_network->Send(peer.IP, peer.Port, std::move(payload), outbound.ByteSizeLong());
	}
	else
		SPDLOG_WARN("{}: Unable to find peer for address {}:{}, identification message failed.", m_postOffice->GetName(), peer.IP, peer.Port);
}

void mq::postoffice::PeerConnection::DropIdentification(const ActorContainer::Network& peer, const ActorIdentification& identity) const
{
	if (m_network->HasHost(peer.IP, peer.Port))
	{
		proto::routing::NetworkMessage outbound;
		proto::routing::DropIdentity& drop = *outbound.mutable_drop();
		*drop.mutable_id() = identity.GetProto();

		auto payload = std::make_unique<uint8_t[]>(outbound.ByteSizeLong());
		outbound.SerializeToArray(payload.get(), static_cast<int>(outbound.ByteSizeLong()));
		m_network->Send(peer.IP, peer.Port, std::move(payload), outbound.ByteSizeLong());
	}
	else
		SPDLOG_WARN("{}: Unable to find peer for address {}:{}, drop message failed.", m_postOffice->GetName(), peer.IP, peer.Port);
}

// TODO: this could be RPC
void mq::postoffice::PeerConnection::RequestIdentities(const ActorContainer::Network& peer) const
{
	if (m_network->HasHost(peer.IP, peer.Port))
	{
		proto::routing::NetworkMessage outbound;
		proto::routing::RequestIdentities& req = *outbound.mutable_request();

		auto payload = std::make_unique<uint8_t[]>(outbound.ByteSizeLong());
		outbound.SerializeToArray(payload.get(), static_cast<int>(outbound.ByteSizeLong()));
		m_network->Send(peer.IP, peer.Port, std::move(payload), outbound.ByteSizeLong());
	}
	else
		SPDLOG_WARN("{}: Unable to find peer for address {}:{}, send request failed.", m_postOffice->GetName(), peer.IP, peer.Port);
}

void PeerConnection::BroadcastMessage(proto::routing::Envelope&& message)
{
	proto::routing::NetworkMessage outbound;
	*outbound.mutable_routed() = std::move(message);
	auto payload = std::make_unique<uint8_t[]>(outbound.ByteSizeLong());
	outbound.SerializeToArray(payload.get(), static_cast<int>(outbound.ByteSizeLong()));

	m_network->Broadcast(std::move(payload), outbound.ByteSizeLong());
}

void mq::postoffice::PeerConnection::Start()
{
}

void mq::postoffice::PeerConnection::Stop()
{
	m_network->Shutdown();
}

void mq::postoffice::PeerConnection::AddHost(const std::string& address, uint16_t port) const
{
	m_network->AddHost(address, port);
}

void mq::postoffice::PeerConnection::RemoveHost(const std::string& address, uint16_t port) const
{
	m_network->RemoveHost(address, port);
	m_postOffice->DropContainer(ActorContainer(ActorContainer::Network{ address, port }));
}

uint16_t mq::postoffice::PeerConnection::GetPort() const
{
	return m_network->GetPort();
}

