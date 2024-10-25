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
//#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

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

void Connection::RequestProcessEvents()
{
	m_postOffice->RequestProcessEvents();
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
		{
			m_connection->RouteFromPipe(std::make_unique<proto::routing::Envelope>(ProtoMessage::Parse<proto::routing::Envelope>(message)));
			break;
		}

		case mq::MQMessageId::MSG_IDENTIFICATION:
			if (message->GetHeader()->messageLength > 0)
			{
				// if there is a payload, then we are getting a notification of ID
				auto id = ProtoMessage::Parse<proto::routing::Identification>(message);
				m_connection->UpdateConnection(id.has_process() ? id.process().uuid() : id.peer().uuid(), message->GetConnectionId());

				// send this to the post office to process in the launcher dropbox
				m_connection->GetPostOffice()->AddIdentity(ActorIdentification(std::move(id)));
			}
			else if (auto pipeServer = m_connection->GetPipeServer())
			{
				if (const auto& conn = pipeServer->GetConnection(message->GetConnectionId()))
				{
					// we are getting a request to send all IDs, do so sequentially and asynchronously
					// send this to the post office to process in the launcher dropbox
					auto uuid = m_connection->GetConnectionUUID(message->GetConnectionId());
					m_connection->GetPostOffice()->SendIdentities(ActorContainer(ActorContainer::Process{ conn->GetProcessId(), uuid }));
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
		auto uuid = m_connection->GetConnectionUUID(connectionId);
		if (!uuid.empty())
			m_connection->DropProcess(ActorContainer::Process{ static_cast<uint32_t>(processId), uuid });
	}

private:
	LocalConnection* m_connection;
};

std::string GetPipePath(LauncherPostOffice* postOffice)
{
	const auto& config = postOffice->GetConfig();
	return config.PipeName;
}

LocalConnection::LocalConnection(LauncherPostOffice* postOffice)
	: Connection(postOffice)
	, m_pipeServer(std::make_unique<ProtoPipeServer>(GetPipePath(postOffice).c_str()))
	, m_uuid(postOffice->GetID().container.GetUUID())
{
	m_pipeServer->SetHandler(std::make_shared<PipeEventsHandler>(this));
}

LocalConnection::~LocalConnection()
{}

void LocalConnection::Process()
{
	m_pipeServer->Process();
}

bool LocalConnection::SendMessage(const ActorContainer::Process& process, MessagePtr message)
{
	const auto payload = std::make_unique<uint8_t[]>(message->ByteSizeLong());
	message->SerializeToArray(payload.get(), static_cast<int>(message->ByteSizeLong()));

	auto msg = std::make_unique<PipeMessage>(MQMessageId::MSG_ROUTE, payload.get(), message->ByteSizeLong());

	if (process.UUID == m_uuid)
	{
		SPDLOG_TRACE("{}: Pipe detected self message, dispatching {} (PID {}) seq={}", m_postOffice->GetName(), process.UUID, process.PID, message->sequence());
		// send to self, dispatch directly to the handler
		m_pipeServer->DispatchMessage(std::move(msg));
		return true;
	}

	if (const auto& connection = GetConnection(process.UUID))
	{
		// found a connection to send it over
		SPDLOG_TRACE("{}: Pipe found connection, dispatching {} (PID {}) seq={}", m_postOffice->GetName(), process.UUID, process.PID, message->sequence());
		connection->SendMessage(std::move(msg));
		return true;
	}

	SPDLOG_WARN("{}: Unable to get connection for {} (PID {}), message route failed. seq={}", m_postOffice->GetName(), process.UUID, process.PID, message->sequence());
	m_postOffice->RoutingFailed(MsgError_NoConnection, std::move(message), "Could not find connection");
	return false;
}

void LocalConnection::SendIdentification(const ActorContainer::Process& process, const ActorIdentification& identity) const
{
	if (const auto& connection = GetConnection(process.UUID))
	{
		proto::routing::Identification id = identity.GetProto();

		const auto payload = std::make_unique<uint8_t[]>(id.ByteSizeLong());
		id.SerializeToArray(payload.get(), static_cast<int>(id.ByteSizeLong()));

		connection->SendMessage(std::make_unique<PipeMessage>(MQMessageId::MSG_IDENTIFICATION, payload.get(), id.ByteSizeLong()));
	}
	else
		SPDLOG_WARN("{}: Unable to get connection for {} (PID {}), identification message failed.", m_postOffice->GetName(), process.UUID, process.PID);
}

void LocalConnection::DropIdentification(const ActorContainer::Process& process, const ActorIdentification& identity) const
{
	if (const auto& connection = GetConnection(process.UUID))
	{
		proto::routing::Identification id = identity.GetProto();

		const auto payload = std::make_unique<uint8_t[]>(id.ByteSizeLong());
		id.SerializeToArray(payload.get(), static_cast<int>(id.ByteSizeLong()));

		connection->SendMessage(std::make_unique<PipeMessage>(MQMessageId::MSG_DROPPED, payload.get(), id.ByteSizeLong()));
	}
	else
		SPDLOG_WARN("{}: Unable to get connection for {} (PID {}), drop message failed.", m_postOffice->GetName(), process.UUID, process.PID);
}

void LocalConnection::RequestIdentities(const ActorContainer::Process& process) const
{
	if (const auto& connection = GetConnection(process.UUID))
	{
		connection->SendMessage(std::make_unique<PipeMessage>(MQMessageId::MSG_IDENTIFICATION, nullptr, 0));
	}
	else
		SPDLOG_WARN("{}: Unable to get connection for {} (PID {}), send request failed.", m_postOffice->GetName(), process.UUID, process.PID);
}

void LocalConnection::BroadcastMessage(MessagePtr message)
{
	const auto payload = std::make_unique<uint8_t[]>(message->ByteSizeLong());
	message->SerializeToArray(payload.get(), static_cast<int>(message->ByteSizeLong()));

	m_pipeServer->BroadcastMessage(std::make_unique<PipeMessage>(MQMessageId::MSG_ROUTE, payload.get(), message->ByteSizeLong()));
}

void LocalConnection::RouteFromPipe(MessagePtr message)
{
	m_postOffice->RouteFromConnection(std::move(message));
}

void LocalConnection::DropProcess(const ActorContainer::Process& process) const
{
	m_postOffice->DropContainer(ActorContainer(process));
}

void LocalConnection::Start()
{
	m_pipeServer->Start();
}

void LocalConnection::Stop()
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

int LocalConnection::GetConnectionID(const std::string& uuid) const
{
	auto it = m_connections.find(uuid);
	if (it != m_connections.end())
		return it->second;

	return -1;
}

std::string LocalConnection::GetConnectionUUID(int connectionID) const
{
	auto it = std::find_if(m_connections.begin(), m_connections.end(),
		[connectionID](const auto& pair) { return pair.second == connectionID; });
	if (it != m_connections.end())
		return it->first;

	return "";
}

void LocalConnection::UpdateConnection(const std::string& uuid, int connectionID)
{
	auto it = m_connections.find(uuid);
	if (it != m_connections.end())
		it->second = connectionID;
	else
		m_connections.emplace(uuid, connectionID);
}

std::shared_ptr<mq::PipeConnection> LocalConnection::GetConnection(const std::string& uuid) const
{
	auto it = m_connections.find(uuid);
	if (it != m_connections.end())
		return m_pipeServer->GetConnection(it->second);

	return nullptr;
}

// ------------------------ PeerConnection ------------------------------------

uint16_t GetPeerPort(LauncherPostOffice* postOffice)
{
	const auto config = postOffice->GetConfig();
	return config.PeerPort;
}

PeerConnection::PeerConnection(LauncherPostOffice* postOffice)
	: Connection(postOffice)
	, m_network(std::make_unique<NetworkPeerAPI>(NetworkPeerAPI::GetOrCreate(
		GetPeerPort(postOffice),
		[this](const NetworkAddress& address, NetworkMessagePtr message)
		{
			using peernetwork::NetworkMessage;

			auto source_addr = ActorContainer::Network{
				address.IP, address.Port,
				ActorContainer(message->add().id()).GetUUID() };

			switch (message->contents_case())
			{
			case NetworkMessage::kAdd:
				m_postOffice->AddIdentity(ActorIdentification(
					std::move(source_addr), ActorIdentification::GetAddress(message->add().id())));
				break;
			case NetworkMessage::kDrop:
				m_postOffice->DropIdentity(ActorIdentification(
					std::move(source_addr), ActorIdentification::GetAddress(message->drop().id())));
				break;
			case NetworkMessage::kRequest:
				m_postOffice->SendIdentities(ActorContainer(source_addr));
				break;
			case NetworkMessage::kRouted:
			{
				auto routed = std::make_unique<proto::routing::Envelope>();
				routed->ParseFromString(message->routed());

				if (routed->has_return_address())
				{
					routed->mutable_return_address()->clear_process();
					routed->mutable_return_address()->mutable_peer()->set_ip(address.IP);
					routed->mutable_return_address()->mutable_peer()->set_port(address.Port);
				}

				// if this message has been routed here, then we need to let the local launcher handle any routing
				routed->mutable_address()->clear_process();
				routed->mutable_address()->mutable_peer()->set_ip("127.0.0.1");
				routed->mutable_address()->mutable_peer()->set_port(m_network->GetPort());

				// if the address is not on the pipe, this will fail or route back out to the network if the client has a peer container
				m_postOffice->RouteFromConnection(std::move(routed));

				break;
			}
			default:
				SPDLOG_WARN("{}: Got unknown inbound message type {}", m_postOffice->GetName(), static_cast<int>(message->contents_case()));
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
		},
		[this]()
		{
			if (s_triggerProcess) (*s_triggerProcess)();
			RequestProcessEvents();
		})))
{}

PeerConnection::~PeerConnection()
{
}

void PeerConnection::AddConfiguredHosts()
{
	const uint16_t default_port = GetPeerPort(m_postOffice);
	const auto config = m_postOffice->GetConfig();

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

void PeerConnection::Process()
{
	m_network->Process();
}

bool PeerConnection::SendMessage(const ActorContainer::Network& peer, MessagePtr message)
{
	// the network library handles routing of any address (we can't short circuit local IP
	// detection because it needs knowledge of the network)
	if (m_network->HasHost(peer.IP, peer.Port))
	{
		// the network has the host (we do this in order to provide routing errors)
		auto outbound = std::make_unique<peernetwork::NetworkMessage>();
		outbound->set_routed(message->SerializeAsString());

		m_network->Send(peer.IP, peer.Port, std::move(outbound));

		return true;
	}

	SPDLOG_WARN("{}: Unable to find peer for address {}:{}, message route failed. seq={}", m_postOffice->GetName(), peer.IP, peer.Port, message->sequence());
	m_postOffice->RoutingFailed(MsgError_NoConnection, std::move(message), "Could not find connection");
	return false;

}

void PeerConnection::SendIdentification(const ActorContainer::Network& peer, const ActorIdentification& identity) const
{
	if (m_network->HasHost(peer.IP, peer.Port))
	{
		auto outbound = std::make_unique<peernetwork::NetworkMessage>();
		proto::routing::AddIdentity& add = *outbound->mutable_add();
		*add.mutable_id() = identity.GetProto();

		m_network->Send(peer.IP, peer.Port, std::move(outbound));
	}
	else
		SPDLOG_WARN("{}: Unable to find peer for address {}:{}, identification message failed.", m_postOffice->GetName(), peer.IP, peer.Port);
}

void PeerConnection::DropIdentification(const ActorContainer::Network& peer, const ActorIdentification& identity) const
{
	if (m_network->HasHost(peer.IP, peer.Port))
	{
		auto outbound = std::make_unique<peernetwork::NetworkMessage>();
		proto::routing::DropIdentity& drop = *outbound->mutable_drop();
		*drop.mutable_id() = identity.GetProto();

		m_network->Send(peer.IP, peer.Port, std::move(outbound));
	}
	else
		SPDLOG_WARN("{}: Unable to find peer for address {}:{}, drop message failed.", m_postOffice->GetName(), peer.IP, peer.Port);
}

void PeerConnection::RequestIdentities(const ActorContainer::Network& peer) const
{
	if (m_network->HasHost(peer.IP, peer.Port))
	{
		auto outbound = std::make_unique<peernetwork::NetworkMessage>();
		proto::routing::RequestIdentities& req = *outbound->mutable_request();

		m_network->Send(peer.IP, peer.Port, std::move(outbound));
	}
	else
		SPDLOG_WARN("{}: Unable to find peer for address {}:{}, send request failed.", m_postOffice->GetName(), peer.IP, peer.Port);
}

void PeerConnection::BroadcastMessage(MessagePtr message)
{
	auto outbound = std::make_unique<peernetwork::NetworkMessage>();
	outbound->set_routed(message->SerializeAsString());

	m_network->Broadcast(std::move(outbound));
}

void PeerConnection::Start()
{
}

void PeerConnection::Stop()
{
	m_network->Shutdown();
}

void PeerConnection::AddHost(const std::string& address, uint16_t port) const
{
	m_network->AddHost(address, port);
}

void PeerConnection::RemoveHost(const std::string& address, uint16_t port) const
{
	m_network->RemoveHost(address, port);
	m_postOffice->DropContainer(ActorContainer(ActorContainer::Network{ address, port }));
}

uint16_t PeerConnection::GetPort() const
{
	return m_network->GetPort();
}

