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

#pragma once

#include "Routing.h"

#include <fmt/format.h>

#include <string>
#include <unordered_map>
#include <queue>
#include <memory>
#include <variant>

namespace mq::postoffice {

template <typename... Ts> struct overload : Ts... { using Ts::operator()...; };
template <typename... Ts> overload(Ts...) -> overload<Ts...>;

using ReceiveCallback = std::function<void(ProtoMessagePtr&&)>;
using PostCallback = std::function<void(const std::string&, const PipeMessageResponseCb&)>;
using DropboxDropper = std::function<void(const std::string&)>;

struct ActorContainer
{
	struct Network
	{
		std::string IP; // always use IP here, if we ever allow host names, make sure to resolve to IP first
		uint16_t Port;

		bool operator==(const Network& other) const
		{
			// exact match on IP, can just use string == override
			return IP == other.IP && Port == other.Port;
		}
	};

	const std::variant<uint32_t, Network> value;

	template <typename T>
	explicit ActorContainer(const T& t) : value(t) {}

	static std::variant<uint32_t, Network> GetContainer(const proto::routing::Identification& id) noexcept
	{
		switch (id.container_case())
		{
		case proto::routing::Identification::kPid:
			return id.pid();
		case proto::routing::Identification::kPeer:
			return Network{ id.peer().ip(), static_cast<uint16_t>(id.peer().port()) };
		default:
			return 0;
		}
	}

	explicit ActorContainer(const proto::routing::Identification& id) : value(GetContainer(id)) {}

	static std::variant<uint32_t, Network> GetContainer(const proto::routing::Address& addr) noexcept
	{
		if (addr.has_pid())
			return addr.pid();

		if (addr.has_peer())
			return GetContainer(addr.peer());

		return 0;
	}

	explicit ActorContainer(const proto::routing::Address& addr) : value(GetContainer(addr)) {}

	static Network GetContainer(const proto::routing::Peer& peer)
	{
		return Network{ peer.ip(), static_cast<uint16_t>(peer.port()) };
	}

	explicit ActorContainer(const proto::routing::Peer& peer) : value(GetContainer(peer)) {}

	template <typename T>
	bool operator==(const T& other) const
	{
		return std::get<T>(other) == value;
	}

	bool operator==(const ActorContainer& other) const
	{
		return other.value == value;
	}

	std::string ToString() const
	{
		return std::visit(overload{
			[](uint32_t v) { return std::to_string(v); },
			[](const Network& addr) { return fmt::format("{}:{}", addr.IP, addr.Port); }
			}, value);
	}
};

/**
 * A shared type to unify the way clients are addressed and identified
 */
struct ActorIdentification
{
	/**
	 * The type for a game client actor
	 */
	struct Client
	{
		std::string account;
		std::string server;
		std::string character;

		bool operator==(const Client& other) const
		{
			return account == other.account &&
				server == other.server &&
				character == other.character;
		}
	};

	/**
	 * a container is where we send traffic to, it can be a PID or a network address
	 */
	ActorContainer container;

	/**
	 * the address is how the container will address the individual actor (name or client)
	 */
	std::variant<std::string, Client> address;

	/**
	 * generic constructor to create a container and address from any parameters that are accepted
	 *
	 * @tparam A a type that can be used to construct a Container type
	 * @tparam T a type that can construct address (string or Client)
	 * @param container the value to construct the Container with
	 * @param address the value to construct the address with
	 */
	template <typename A, typename T>
	ActorIdentification(A container, T address)
		: container(std::move(container))
		, address(std::move(address))
	{}

	/**
	 * factory function to create an address from an id message
	 *
	 * @tparam T Identification or Address proto that contains an address
	 * @param id the proto  message that contains the address
	 * @return a constructed variant address using the value from id
	 */
	template <typename T>
	static std::variant<std::string, Client> GetAddress(const T& id)
	{
		switch (id.address_case())
		{
		case T::kName:
			return id.name();
		case T::kClient:
			return Client{
				id.client().account(),
				id.client().server(),
				id.client().character()
			};
		default:
			return "";
		}
	}

	/**
	 * constructor that fills the identity from a proto Identification message
	 *
	 * @param id the proto identification message that contains the address and container
	 */
	explicit ActorIdentification(const proto::routing::Identification& id)
		: container(id)
		, address(GetAddress(id))
	{}

	explicit ActorIdentification(const proto::routing::Address& addr)
		: container(addr)
		, address(GetAddress(addr))
	{}

	/**
	 * provided equality helper, a name address is equal if the container and the name match
	 * and a client is considered equal if only the address matches
	 *
	 * @param other the other identity to compare against
	 * @return true if other has the same identity as this
	 */
	bool operator==(const ActorIdentification& other) const
	{
		return container == other.container && address == other.address;
	}

	/**
	 * provided inequality helper, a name address is equal if the container and the name match
	 * and a client is considered equal if only the address matches
	 *
	 * @param other the other identity to compare against
	 * @return true if other has the same identity as this
	 */
	bool operator!=(const ActorIdentification& other) const
	{
		return !(*this == other);
	}

	/**
	 * helper method to translate this id into a proto id
	 *
	 * @return a proto id containing this id
	 */
	proto::routing::Identification GetProto() const
	{
		proto::routing::Identification id;

		std::visit(overload{
			[&id](uint32_t pid) { id.set_pid(pid); },
			[&id](const ActorContainer::Network& addr)
			{
				proto::routing::Peer* p = id.mutable_peer();
				p->set_ip(addr.IP);
				p->set_port(addr.Port);
			}
		}, container.value);

		std::visit(overload{
			[&id](const std::string& name) { id.set_name(name); },
			[&id](const Client& cid)
			{
				proto::routing::Client* c = id.mutable_client();
				if (!cid.account.empty()) c->set_account(cid.account);
				if (!cid.server.empty()) c->set_server(cid.server);
				if (!cid.character.empty()) c->set_character(cid.character);
			}
		}, address);

		return id;
	}

	/**
	 * helper method to set this id into a proto address
	 */
	proto::routing::Address& BuildAddress(proto::routing::Address& addr) const
	{
		std::visit(overload{
			[&addr](uint32_t pid) { addr.set_pid(pid); },
			[&addr](const ActorContainer::Network& netaddr)
			{
				proto::routing::Peer* p = addr.mutable_peer();
				p->set_ip(netaddr.IP);
				p->set_port(netaddr.Port);
			}
		}, container.value);

		std::visit(overload{
			[&addr](const std::string& name) { addr.set_name(name); },
			[&addr](const Client& cid)
			{
				proto::routing::Client* c = addr.mutable_client();
				if (!cid.account.empty()) c->set_account(cid.account);
				if (!cid.server.empty()) c->set_server(cid.server);
				if (!cid.character.empty()) c->set_character(cid.character);
			}
		}, address);

		return addr;
	}

	/**
	 * this tests identity for "duplicates" which follows these rules:
	 * - container and address are both equal (just use the equality operator)
	 * - client address is equal, but container are not
	 * - pid container is equal, and address is a client address
	 * - special note: we cannot do anything special for only network equality
	 *
	 * @param other the other identity to compare against
	 * @return if this identity duplicates other 
	 */
	bool IsDuplicate(const ActorIdentification& other)
	{
		return *this == other || std::visit(overload{
			// this will always be false because the true case is covered in the equality check
			[this](const std::string&) { return false; },
			[this, &other](const Client&)
			{ return std::visit(overload{
				[this, &other](uint32_t) { return container.value == other.container.value; },
				[](const ActorContainer::Network&) { return false; } // we can't assume anything about network here
			}, container.value) || address == other.address; }
		}, address);
	}

	/**
	 * string creation helper
	 *
	 * @return a string of format "address (container)"
	 */
	std::string ToString() const
	{
		return fmt::format("{} ({})", std::visit(overload{
			[](const std::string& name) { return name; },
			[](const Client& client) { return fmt::format("{} [{}]", client.character, client.server); }
		}, address), container);
	}
};

class Mailbox
{
public:
	Mailbox(std::string localAddress, ReceiveCallback&& receive)
		: m_localAddress(localAddress)
		, m_receive(std::move(receive))
	{}

	~Mailbox() {}

	/**
	 * Gets the address of this mailbox
	 *
	 * @return the local address of this mailbox
	 */
	const std::string& GetAddress() const { return m_localAddress; }

	/**
	 * Delivers a message to this mailbox to be handled by the receive callback
	 *
	 * @param message the message to deliver
	 */
	void Deliver(PipeMessagePtr&& message) const;

	/**
	 * Process some messages that have been delivered
	 *
	 * @param howMany how many messages to process off the queue
	 */
	void Process(size_t howMany) const;

private:
	static ProtoMessagePtr Open(proto::routing::Envelope&& envelope, const PipeMessagePtr& header);

	const std::string m_localAddress;
	const ReceiveCallback m_receive;

	mutable std::queue<ProtoMessagePtr> m_receiveQueue;
};

class Dropbox
{
	friend class PostOffice;

public:
	Dropbox()
		: m_valid(false)
	{}

	~Dropbox() {}

	Dropbox(std::string localAddress, PostCallback&& post, DropboxDropper&& unregister);
	Dropbox(const Dropbox& other);
	Dropbox(Dropbox&& other) noexcept;
	//Dropbox& operator=(const Dropbox& other);
	Dropbox& operator=(Dropbox other) noexcept;

	/**
	 * Sends a message to an address
	 *
	 * @tparam T the message being sent, usually some kind of proto
	 *
	 * @param address the address to send the message
	 * @param obj the message (as an object)
	 * @param callback optional callback for an expected response
	 */
	template <typename T>
	void Post(const proto::routing::Address& address, const T& obj, const PipeMessageResponseCb& callback = nullptr)
	{
		if (IsValid()) m_post(Stuff(address, obj), callback);
	}

	/**
	 * Sends an empty message to an address
	 *
	 * @param address the address to send the message
	 * @param callback optional callback for an expected response
	 */
	void Post(const proto::routing::Address& address, const PipeMessageResponseCb& callback = nullptr)
	{
		if (IsValid()) m_post(Stuff(address, std::string()), callback);
	}

	/**
	 * Sends a reply to the sender of a message -- the message can be anything
	 * because we make no assumption about what is wrapped in the envelope
	 *
	 * @tparam T the message being sent, usually some kind of proto
	 *
	 * @param message the original message to reply to
	 * @param obj the message (as an object)
	 * @param status a return status, sometimes used by reply handling logic
	 */
	template <typename T>
	void PostReply(PipeMessagePtr&& message, const T& obj, uint8_t status = 0)
	{
		if (IsValid())
		{
			std::string data(Data(obj));
			message->SendReply(message->GetMessageId(), &data[0], data.size(), status);
		}
	}

	/**
	 * Sends a reply to the sender of a message -- the message can be anything
	 * because we make no assumption about what is wrapped in the envelope
	 *
	 * @param message the original message to reply to
	 * @param obj the message (as an object)
	 * @param status a return status, sometimes used by reply handling logic
	 */
	template <typename T>
	void PostReply(ProtoMessagePtr&& message, const T& obj, uint8_t status = 0)
	{
		if (IsValid())
		{
			if (auto sender = message->GetSender())
			{
				std::string data(Stuff(*sender, obj));
				message->SendReply(MQMessageId::MSG_ROUTE, &data[0], data.size(), status);
			}
			else
			{
				std::string data(Data(obj));
				message->SendReply(message->GetMessageId(), &data[0], data.size(), status);
			}
		}
	}

	/**
	 * Checks if the dropbox has a post callback and an address
	 *
	 * @return this dropbox is valid and will send messages
	 */
	bool IsValid() { return m_valid; }

	/**
	 * Removes the mailbox with the same name from the post office
	 */
	void Remove();

private:
	template <typename T>
	std::string Data(const T& obj)
	{
		return obj.SerializeAsString();
	}

	std::string Data(const std::string& obj)
	{
		return obj;
	}

	template <typename T>
	std::string Stuff(const proto::routing::Address& address, const T& obj)
	{
		return Stuff(address, obj.SerializeAsString());
	}

	std::string Stuff(const proto::routing::Address& address, const std::string& data)
	{
		proto::routing::Envelope envelope;
		*envelope.mutable_address() = address;

		proto::routing::Address& ret = *envelope.mutable_return_address();
		ret.set_pid(GetCurrentProcessId());
		ret.set_mailbox(m_localAddress);

		envelope.set_payload(data);

		return envelope.SerializeAsString();
	}

	std::string m_localAddress;
	PostCallback m_post;
	DropboxDropper m_unregister;
	bool m_valid;
};


/**
 * Abstract post office class for handling routing of messages
 *
 * Each application's post office (for instance, MQ and Launcher) will need to implement
 * this class, specifying how to route proto messages. They will also need to define the
 * singleton that the application can use to get the post office to do things like create
 * mailboxes or send mail to other actors (nominally through the launcher).
 *
 * we should assume that everything lives inside an Envelope here. All mail must be
 * in an envelope, no postcards (yet), but we open the Envelope to create ProtoMessages
 * when we put them on the queue
 */
class PostOffice
{
public:
	virtual ~PostOffice() {}

	/**
	 * The interface to route a message, to be implemented in the post office instantiation
	 *
	 * @param message the message to route -- it should be in an envelope and have the ID of ROUTE
	 * @param callback an optional callback for RPC responses
	 */
	virtual void RouteMessage(PipeMessagePtr&& message, const PipeMessageResponseCb& callback) = 0;

	/**
	 * The interface to route a message, to be implemented in the post office instantiation
	 *
	 * @param data the data buffer of the message to route
	 * @param length the length of the data buffer
	 * @param callback an optional callback for RPC responses
	 */
	void RouteMessage(const void* data, size_t length, const PipeMessageResponseCb& callback);

	/**
	 * A helper interface to route a message directly
	 *
	 * @param address the address to send the message to
	 * @param obj a protobuf object to route
	 * @param callback an optional callback for RPC responses
	 */
	template <typename T>
	void RouteMessage(const proto::routing::Address& address, const T& obj, const PipeMessageResponseCb& callback)
	{
		RouteMessage(address, obj.SerializeAsString(), callback);
	}

	/**
	 * A helper interface to route a message directly
	 *
	 * @param address the address to send the message to
	 * @param data a string of data (which embeds its length)
	 * @param callback an optional callback for RPC responses
	 */
	void RouteMessage(const proto::routing::Address& address, const std::string& data, const PipeMessageResponseCb& callback)
	{
		proto::routing::Envelope envelope;
		*envelope.mutable_address() = address;

		proto::routing::Address& ret = *envelope.mutable_return_address();
		ret.set_pid(GetCurrentProcessId());

		envelope.set_payload(data);

		RouteMessage(envelope, callback);
	}

	/**
	 * A helper interface to route a message
	 *
	 * @param obj a protobuf object to route
	 * @param callback an optional callback for RPC responses
	 */
	template <typename T>
	void RouteMessage(const T& obj, const PipeMessageResponseCb& callback)
	{
		RouteMessage(obj.SerializeAsString(), callback);
	}

	/**
	 * A helper interface to route a message
	 *
	 * @param data a string of data (which embeds its length)
	 * @param callback an optional callback for RPC responses
	 */
	void RouteMessage(const std::string& data, const PipeMessageResponseCb& callback);

	/**
	 * Creates and registers a mailbox with the post office
	 *
	 * @param localAddress the string address to create the address at
	 * @param receive a callback rvalue that will process messages as they are received in this mailbox
	 * @return an dropbox that the creator can use to send addressed messages. will be invalid if it failed to add
	 */
	Dropbox RegisterAddress(const std::string& localAddress, ReceiveCallback&& receive);

	/**
	 * Removes a mailbox from the post office
	 *
	 * @param localAddress the string address that identifies the mailbox to be removed
	 * @return true if the mailbox was removed
	 */
	bool RemoveMailbox(const std::string& localAddress);

	/**
	 * Callback for when a message is delivered to a mailbox, called before the delivery happens
	 *
	 * @param localAddress the local address the message will be delivered to
	 * @param message the message that is being sent
	 */
	virtual void OnDeliver(const std::string& localAddress, PipeMessagePtr& message) {}

	/**
	 * Delivers a message to a local mailbox
	 *
	 * @param localAddress the local address to deliver the message to
	 * @param message the message to send
	 * @param failed a callback for failure (since message is moved)
	 * @return true if routing was successful
	 */
	bool DeliverTo(const std::string& localAddress, PipeMessagePtr&& message, const std::function<void(int, PipeMessagePtr&&)>& failed = [](int, const auto&) {});

	/**
	 * Delivers a message to all local mailboxes, optionally excluding self
	 *
	 * @param message the message to send -- only the message ID and the payload is used (the header is rebuilt per message)
	 * @param fromAddress the address to exclude from the delivery
	 */
	void DeliverAll(PipeMessagePtr& message, std::optional<std::string_view> fromAddress = {});

	/**
	 * Processes messages waiting in the queue
	 *
	 * @param howMany how many messages to process (up to)
	 */
	void Process(size_t howMany);

protected:
	std::unordered_map<std::string, std::unique_ptr<Mailbox>> m_mailboxes;
};

/**
 * Returns this application's post office singleton
 *
 * @tparam P the derived type of post office to get
 * @param index the index of the post office to get (used for testing)
 * @return the post office in this application at index
 */
template <typename P = PostOffice>
P& GetPostOffice(uint32_t index);

/**
 * template specialization that must be implemented in order for clients to get the PostOffice interface
 *
 * @param index the index of the post office to get (used for testing)
 * @return the post office in this application at index
 */
template <>
PostOffice& GetPostOffice<PostOffice>(uint32_t index);

/**
 * provides a way to default the previous templated functions to index 0
 *
 * @tparam P the derived type of post office to get
 * @tparam I the index of the post office to get (used for testing)
 * @return the post office in this application at index
 */
template <typename P = PostOffice, uint32_t I = 0>
P& GetPostOffice() { return GetPostOffice<P>(I); }

} // namespace mq::postoffice

/**
 * hash helper for networking
 */
template<> struct std::hash<mq::postoffice::ActorContainer::Network>
{
	size_t operator()(const mq::postoffice::ActorContainer::Network& address) const noexcept
	{
		return std::hash<std::string>{}(address.IP) ^ std::hash<uint16_t>{}(address.Port) << 1;
	}
};

/**
 * fmt string helper for the actor container
 */
template<> struct fmt::formatter<mq::postoffice::ActorContainer>
{
	template <typename ParseContext>
	constexpr auto parse(ParseContext& ctx)
	{
		return ctx.begin();
	}

	template <typename FormatContext>
	auto format(const mq::postoffice::ActorContainer& container, FormatContext& ctx)
	{
		return std::visit(mq::postoffice::overload{
			[&ctx](uint32_t v) { return fmt::format_to(ctx.out(), "{}", v); },
			[&ctx](const mq::postoffice::ActorContainer::Network& addr) { return fmt::format_to(ctx.out(), "{}:{}", addr.IP, addr.Port); }
		}, container.value);
	}
};

/**
 * hash helper for the actor container
 */
template<> struct std::hash<mq::postoffice::ActorContainer>
{
	size_t operator()(const mq::postoffice::ActorContainer& container) const noexcept
	{
		return std::hash<std::variant<uint32_t, mq::postoffice::ActorContainer::Network>>{}(container.value);
	}
};

/**
 * fmt string helper for identification
 */
template <> struct fmt::formatter<mq::postoffice::ActorIdentification>
{
	template <typename ParseContext>
	constexpr auto parse(ParseContext& ctx)
	{
		return ctx.begin();
	}

	template <typename FormatContext>
	auto format(const mq::postoffice::ActorIdentification& ident, FormatContext& ctx)
	{
		using Client = mq::postoffice::ActorIdentification::Client;
		return std::visit(mq::postoffice::overload{
			[&ctx, &ident](const std::string& name)
			{ return fmt::format_to(ctx.out(), "{} ({})", name, ident.container); },
			[&ctx, &ident](const Client& client)
			{ return fmt::format_to(ctx.out(), "{} [{}] ({})", client.character, client.server, ident.container); }
		}, ident.address);
	}
};
