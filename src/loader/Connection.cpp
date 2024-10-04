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

#include "loader/PostOffice.h"

// -------------------------- LocalConnection ---------------------------------

LocalConnection::LocalConnection(LauncherPostOffice* postOffice, uint32_t index)
	: Connection(postOffice)
	, m_pipeServer{ GetPipePath(index).c_str() }
{
	m_pipeServer.SetHandler(std::make_shared<PipeEventsHandler>(this));
	m_pipeServer.Start();
}

LocalConnection::~LocalConnection() override
{
	// we don't need to worry about sending messages after we stop because the pipe client will log
	// and handle this situation.
	m_pipeServer.Stop();
}

void LocalConnection::Process() override
{
	m_pipeServer.Process();
}

bool LocalConnection::SendMessage(
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

bool LocalConnection::SendMessage(
		const Network& peer,
		PipeMessagePtr&& message,
		const PipeMessageResponseCb& callback) override
{
	SPDLOG_WARN("Attempted to send to peer {} over local pipe", Container(peer));
	RoutingFailed(MsgError_NoConnection, message, callback);
	return false;
}

void LocalConnection::BroadcastMessage(PipeMessagePtr&& message) override
{
	m_pipeServer.BroadcastMessage(std::move(message));
}

void LocalConnection::RouteFromPipe(PipeMessagePtr&& message)
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
														  if (message->size() >= sizeof(MQMessageFocusRequest) && s_requestFocusCallback)
														  {
															  (*s_requestFocusCallback)(message->get<MQMessageFocusRequest>());
														  }
														  break;
													  }

		default: break;
	}
}

void LocalConnection::RouteToPipe(int connectionId, PipeMessagePtr&& message)
{
	m_pipeServer.SendMessage(connectionId, std::move(message));
}

void LocalConnection::DropProcessId(uint32_t processId) const
{
	m_postOffice->DropContainer(Container(processId));
}

bool LocalConnection::SendSetForegroundWindow(HWND hWnd, uint32_t processID)
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

void LocalConnection::SendUnloadAllCommand()
{
	SPDLOG_DEBUG("Requesting to unload all instances");
	m_pipeServer.BroadcastMessage(mq::MQMessageId::MSG_MAIN_REQ_UNLOAD, nullptr, 0);
}

void LocalConnection::SendForceUnloadAllCommand()
{
	SPDLOG_DEBUG("Requesting to FORCE unload all instances");
	m_pipeServer.BroadcastMessage(mq::MQMessageId::MSG_MAIN_REQ_FORCEUNLOAD, nullptr, 0);
}

// ------------------------ PeerConnection ------------------------------------

uint16_t GetPeerPort(uint32_t index)
{
	const auto config = GetConfig(index);
	return config && config->PeerPort ? *config->PeerPort : DEFAULT_ACTOR_PEER_PORT;
}

	// TODO: make the port configurable (default to 7781)
PeerConnection::PeerConnection(LauncherPostOffice* postOffice, uint32_t index)
	: Connection(postOffice)
	, m_network(NetworkPeerAPI::GetOrCreate(
				GetPeerPort(index),
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
				SPDLOG_WARN("Got unknown inbound message type {}", static_cast<int>(inbound.contents_case()));
				break;
				}
				}))
{
	// TODO: use configured port here as well
	const uint16_t default_port = GetPeerPort(index);
	const auto config = GetConfig(index);

	if (config && config->Peers)
	{
		for (const auto& [address, port] : *config->Peers)
		{
			m_network.AddHost(address, port > 0 ? port : default_port);
		}
	}
	else if (s_iniLocation)
	{
		for (const auto& [address, port_raw] : GetPrivateProfileKeyValues("NetworkPeers", *s_iniLocation))
		{
			const uint16_t port = static_cast<uint16_t>(GetUIntFromString(port_raw, 0));
			m_network.AddHost(address, port > 0 ? port : default_port);
		}
	}
}

PeerConnection::~PeerConnection() override
{
	m_network.Shutdown();
}

bool PeerConnection::SendMessage(uint32_t pid, PipeMessagePtr&& message, const PipeMessageResponseCb& callback) override
{
	SPDLOG_WARN("Attempted to send to pid {} over network", pid);
	RoutingFailed(MsgError_NoConnection, message, callback);
	return false;
}

// TODO: wrap this callback? how do we handle callbacks sent over the network? We've lost the sequence ID
bool PeerConnection::SendMessage(const Network& peer, PipeMessagePtr&& message, const PipeMessageResponseCb& callback) override
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

void PeerConnection::BroadcastMessage(PipeMessagePtr&& message) override
{
	const auto outbound = Translate(message);
	auto payload = std::make_unique<uint8_t[]>(outbound.ByteSizeLong());
	outbound.SerializeToArray(payload.get(), static_cast<int>(outbound.ByteSizeLong()));

	m_network.Broadcast(std::move(payload), outbound.ByteSizeLong());
}

proto::routing::NetworkMessage PeerConnection::Translate(const PipeMessagePtr& message)
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
			SPDLOG_WARN("Attempted to translate a pipe message of unknown type {}, empty message returned", static_cast<int>(message->GetMessageId()));
			break;
	}

	return inbound;
}

