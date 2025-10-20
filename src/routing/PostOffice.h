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

#pragma once

#include "Routing.h"

#include "fmt/format.h"

#include <string>
#include <unordered_map>
#include <queue>
#include <memory>
#include <variant>
#include <optional>

namespace mq::postoffice {

template <typename... Ts> struct overload : Ts... { using Ts::operator()...; };
template <typename... Ts> overload(Ts...) -> overload<Ts...>;

using MessagePtr = std::unique_ptr<proto::routing::Envelope>;

using MessageResponseCallback = std::function<void(int status, MessagePtr message)>;
using ReceiveCallback = std::function<void(MessagePtr)>;
using PostCallback = std::function<void(MessagePtr, const MessageResponseCallback&) > ;
using DropboxDropper = std::function<void(const std::string&)>;

struct ActorContainer
{
	struct Process
	{
		Process(uint32_t processId)
			: PID(processId)
		{
		}

		Process& operator=(const Process& other)
		{
			if (*this != other)
			{
				PID = other.PID;
			}

			return *this;
		}

		bool operator==(const Process& other) const
		{
			return PID == other.PID;
		}

		bool operator!=(const Process& other) const
		{
			return !(*this == other);
		}

		std::string ToString() const
		{
			return fmt::format("{}", PID);
		}

		template <typename T>
		T& GetProto(T& p) const
		{
			p.mutable_process()->set_pid(PID);
			return p;
		}

		template <typename T>
		T GetProto() const
		{
			T p;
			return GetProto(p);
		}

		// PID isn't guaranteed to be unique, so we need to use UUID to disambiguate
		uint32_t PID;
	};

	static Process CurrentProcess;

	struct Network
	{
		std::string IP; // always use IP here, if we ever allow host names, make sure to resolve to IP first
		uint16_t Port;

		bool operator==(const Network& other) const
		{
			// exact match on IP, can just use string == override
			return IP == other.IP && Port == other.Port;
		}

		bool operator!=(const Network& other) const
		{
			return !(*this == other);
		}

		Network& operator=(const Network& other)
		{
			if (*this != other)
			{
				IP = other.IP;
				Port = other.Port;
			}

			return *this;
		}

		std::string ToString() const
		{
			return fmt::format("{}:{}", IP, Port);
		}

		template <typename T>
		T& GetProto(T& p) const
		{
			p.mutable_peer()->set_ip(IP);
			p.mutable_peer()->set_port(Port);
			return p;
		}

		template <typename T>
		T GetProto() const
		{
			T p;
			return GetProto(p);
		}
	};

	using Value = std::variant<Process, Network>;
	Value value;

	std::string uuid;

	template <typename T>
	ActorContainer(const T& t, std::string uuid)
		: value(t)
		, uuid(uuid)
	{}

	static Value GetContainer(const proto::routing::Identification& id) noexcept
	{
		switch (id.container_case())
		{
		case proto::routing::Identification::kProcess:
			return Process{ id.process().pid() };
		case proto::routing::Identification::kPeer:
			return Network{ id.peer().ip(), static_cast<uint16_t>(id.peer().port())};
		default:
			return Process{ 0 };
		}
	}

	explicit ActorContainer(const proto::routing::Identification& id)
		: value(GetContainer(id))
		, uuid(id.uuid())
	{}

	static Value GetContainer(const proto::routing::Address& addr) noexcept
	{
		if (addr.has_process())
			return Process{ addr.process().pid() };

		if (addr.has_peer())
			return Network{ addr.peer().ip(), static_cast<uint16_t>(addr.peer().port())};

		return Process{ 0 };
	}

	explicit ActorContainer(const proto::routing::Address& addr)
		: value(GetContainer(addr))
		, uuid(addr.uuid())
	{}

	bool IsLocal() const
	{
		return std::visit(overload{
			[](const Process&) { return true; },
			[](const Network&) { return false; }
		}, value);
	}

	bool IsIn(const ActorContainer& other) const
	{
		return std::visit([this, &o = other.value](const auto& c)
		{
			if constexpr (std::is_same_v<std::remove_const_t<std::remove_reference_t<decltype(c)>>, std::remove_const_t<std::remove_reference_t<decltype(o)>>>)
				return std::get<std::remove_const_t<std::remove_reference_t<decltype(c)>>>(o) == c;

			return false;
		}, value);
	}

	template <typename T>
	bool operator==(const T& other) const
	{
		return other.uuid == uuid && std::get<T>(other) == value;
	}

	bool operator==(const ActorContainer& other) const
	{
		return other.uuid == uuid && other.value == value;
	}

	template <typename T>
	bool operator!=(const T& other) const
	{
		return !(*this == other);
	}

	template <typename T>
	bool HasValue(const T& v)
	{
		const T* c = std::get_if<T>(&value);
		return c && *c == v;
	}

	ActorContainer& operator=(const ActorContainer& other)
	{
		if (*this != other)
		{
			uuid = other.uuid;
			value = other.value;
		}

		return *this;
	}

	template <typename T>
	T& GetProto(T& p) const
	{
		p = std::visit([this](const auto& v)
		{
			return v.GetProto<T>();
		}, value);
		p.set_uuid(uuid);
		return p;
	}

	template <typename T>
	T GetProto() const
	{
		T p;
		return GetProto(p);
	}

	std::string ToStringLite() const
	{
		return std::visit([this](const auto& v)
		{
			return fmt::format("{}", v.ToString());
		}, value);
	}

	std::string ToString() const
	{
		return std::visit([this](const auto& v)
		{
			return fmt::format("{} ({})", v.ToString(), uuid);
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

		bool operator!=(const Client& other) const
		{
			return !(*this == other);
		}

		Client& operator=(const Client& other)
		{
			if (*this != other)
			{
				account = other.account;
				server = other.server;
				character = other.character;
			}

			return *this;
		}

		std::string ToString() const
		{
			if (character.empty() && server.empty())
				return "(unnamed)";
			return fmt::format("{} [{}]", character, server);
		}

		proto::routing::Client GetProto() const
		{
			proto::routing::Client c;
			if (!account.empty())
				c.set_account(account);
			if (!server.empty())
				c.set_server(server);
			if (!character.empty())
				c.set_character(character);
			return c;
		}
	};

	/**
	 * a container is where we send traffic to, it can be a PID or a network address
	 */
	ActorContainer container;

	using Value = std::variant<std::string, Client>;

	/**
	 * the address is how the container will address the individual actor (name or client)
	 */
	Value address;

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
		: container(std::forward<A>(container))
		, address(std::forward<T>(address))
	{}

	/**
	 * factory function to create an address from an id message
	 *
	 * @tparam T Identification or Address proto that contains an address
	 * @param id the proto  message that contains the address
	 * @return a constructed variant address using the value from id
	 */
	template <typename T>
	static Value GetAddress(const T& id)
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

	ActorIdentification& operator=(const ActorIdentification& other)
	{
		if (*this != other)
		{
			container = other.container;
			address = other.address;
		}

		return *this;
	}

	/**
	 * helper method to translate this id into a proto id
	 *
	 * @return a proto id containing this id
	 */
	proto::routing::Identification GetProto() const
	{
		auto id = container.GetProto<proto::routing::Identification>();

		std::visit(overload{
			[&id](const std::string& name) { id.set_name(name); },
			[&id](const Client& cid) { *id.mutable_client() = cid.GetProto(); }
		}, address);

		return id;
	}

	/**
	 * helper method to set this id into a proto address
	 *
	 * @return a proto id containing this id
	 */
	proto::routing::Address& BuildAddress(proto::routing::Address& addr) const
	{
		std::visit(overload{
			[&addr](const ActorContainer::Process& proc) { *addr.mutable_process() = proc.GetProto<proto::routing::Address>().process(); },
			[&addr](const ActorContainer::Network& netaddr) { *addr.mutable_peer() = netaddr.GetProto<proto::routing::Address>().peer(); }
		}, container.value);

		addr.set_uuid(container.uuid);

		std::visit(overload{
			[&addr](const std::string& name) { addr.set_name(name); },
			[&addr](const Client& cid) { *addr.mutable_client() = cid.GetProto(); }
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
	bool IsDuplicate(const ActorIdentification& other) const
	{
		return *this == other || std::visit(overload{
			// this will always be false because the true case is covered in the equality check
			[this](const std::string&) { return false; },
			[this, &other](const Client&)
			{ return std::visit(overload{
				[this, &other](const ActorContainer::Process&) { return container.value == other.container.value; },
				[](const ActorContainer::Network&) { return false; } // we can't assume anything about network here
			}, container.value) || address == other.address; }
		}, address);
	}

	/**
	 * this test the identity for having an address
	 * 
	 * @tparam T the type of address
	 * 
	 * @param v the value of the address to check against
	 * @return if this address is the same as the passed value
	 */
	template <typename T>
	bool HasAddress(const T& v) const
	{
		const T* c = std::get_if<T>(&address);
		return c && *c == v;
	}

	/**
	 * string creation helper without uuid
	 *
	 * @return a string of format "address (container)"
	 */
	std::string ToStringLite() const
	{
		return fmt::format("{} ({})", std::visit(overload{
			[](const std::string& name)
			{
				return name;
			},
			[](const Client& client)
			{
				return client.ToString();
			}
		}, address), container.ToStringLite());
	}

	/**
	 * string creation helper with uuid
	 *
	 * @return a string of format "address (container (uuid))"
	 */
	std::string ToString() const
	{
		return fmt::format("{} ({})", std::visit(overload{
			[](const std::string& name)
			{
				return name;
			},
			[](const Client& client)
			{
				return client.ToString();
			}
		}, address), container);
	}
};

class Mailbox
{
public:
	Mailbox(std::string localAddress, ReceiveCallback&& receive)
		: m_localAddress(std::move(localAddress))
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
	void Deliver(MessagePtr message) const;

	/**
	 * Process some messages that have been delivered
	 *
	 * @param howMany how many messages to process off the queue
	 */
	void Process(size_t howMany) const;

private:
	const std::string m_localAddress;
	const ReceiveCallback m_receive;

	mutable std::queue<MessagePtr> m_receiveQueue;
};

class Dropbox
{
	friend class PostOffice;

public:
	Dropbox()
	{
	}

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
	void Post(const proto::routing::Address& address, const T& obj, const MessageResponseCallback& callback = nullptr)
	{
		if (IsValid()) m_post(Stuff(address, obj), callback);
	}

	/**
	 * Sends an empty message to an address
	 *
	 * @param address the address to send the message
	 * @param callback optional callback for an expected response
	 */
	void Post(const proto::routing::Address& address, const MessageResponseCallback& callback = nullptr)
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
	void PostReply(MessagePtr message, const T& obj, int status = 0)
	{
		PostReply(std::move(message), Data(obj), status);
	}

	void PostReply(MessagePtr message, const std::string& data, int status = 0);

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
	MessagePtr Stuff(const proto::routing::Address& address, const T& obj)
	{
		return Stuff(address, obj.SerializeAsString());
	}

	MessagePtr Stuff(const proto::routing::Address& address, const std::string& data);

	std::string m_localAddress;
	PostCallback m_post;
	DropboxDropper m_unregister;
	bool m_valid = false;
};

/**
 * Defines the type used for the container of mailboxes in the post office
 */
using MailboxMap = std::unordered_map<std::string, std::unique_ptr<Mailbox>>;


/**
 * Abstract post office class for handling routing of messages
 *
 * Each application's post office (for instance, MQ and Launcher) will need to implement
 * this class, specifying how to route proto messages. They will also need to define the
 * singleton that the application can use to get the post office to do things like create
 * mailboxes or send mail to other actors (nominally through the launcher).
 *
 * we should assume that everything lives inside an Envelope here. All mail must be
 * in an envelope, no postcards (yet), and put the Envelopes on the queue directly
 */
class PostOffice
{
public:
	PostOffice(ActorIdentification id);

	virtual ~PostOffice();

	/**
	 * The interface to route a message, to be implemented in the post office instantiation
	 *
	 * @param message the message to route -- it should be in an envelope and have the ID of ROUTE
	 */
	virtual void RouteMessage(MessagePtr message) = 0;

	/**
	 * A helper interface to route a message directly
	 *
	 * @param address the address to send the message to
	 * @param obj a protobuf object to route
	 */
	template <typename T>
	void RouteMessage(const proto::routing::Address& address, const T& obj)
	{
		RouteMessage(address, obj.SerializeAsString());
	}

	/**
	 * A helper interface to route a message directly
	 *
	 * @param address the address to send the message to
	 * @param data a string of data (which embeds its length)
	 */
	void RouteMessage(const proto::routing::Address& address, const std::string& data);

	/**
	 * A helper to easily formulate routing failed messages to the source
	 * 
	 * @param status the integer status of the reply -- matches the pipe implementation but can be independent
	 * @param message the originating message that failed to route, used to build the response
	 * @param what a string message that prepends to the address to print out at the source
	 */
	void RoutingFailed(int status, MessagePtr message, std::string_view what);

	/**
	 * Creates and registers a mailbox with the post office
	 *
	 * @param localAddress the string address to create the address at
	 * @param receive a callback rvalue that will process messages as they are received in this mailbox
	 * @return a dropbox that the creator can use to send addressed messages. will be invalid if it failed to add
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
	virtual void OnDeliver(const std::string& localAddress, MessagePtr& message) {}

	/**
	 * Delivers a message to a local mailbox
	 *
	 * @param localAddress the local address to deliver the message to
	 * @param message the message to send
	 * @return true if routing was successful
	 */
	bool DeliverTo(const std::string& localAddress, MessagePtr message);

	/**
	 * Processes messages waiting in the queue
	 *
	 * @param howMany how many messages to process (up to)
	 */
	void Process(size_t howMany);

	/**
	 * Get the local post office identification
	 * 
	 * @return the actor identification used to address this specific post office
	 */
	const ActorIdentification& GetID() { return m_id; }

protected:
	MailboxMap m_mailboxes;
	Dropbox m_dropbox;
	ActorIdentification m_id;

	uint32_t m_nextSequence = 0;
	std::unordered_map<uint32_t, RpcRequest<MessageResponseCallback>> m_rpcRequests;
};

} // namespace mq::postoffice

/**
 * hash helper for processes
 */
template <> struct std::hash<mq::postoffice::ActorContainer::Process>
{
	size_t operator()(const mq::postoffice::ActorContainer::Process& process) const noexcept
	{
		return std::hash<uint32_t>{}(process.PID) << 1;
	}
};

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
 * hash helper for the actor container
 */
template<> struct std::hash<mq::postoffice::ActorContainer>
{
	size_t operator()(const mq::postoffice::ActorContainer& container) const noexcept
	{
		return std::hash<mq::postoffice::ActorContainer::Value>{}(container.value) ^ std::hash<std::string>{}(container.uuid) << 1;
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
		return fmt::format_to(ctx.out(), container.ToString());
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
		return fmt::format_to(ctx.out(), ident.ToString());
	}
};
