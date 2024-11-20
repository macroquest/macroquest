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
#include "MQ2Main.h"

#include "MQActorAPI.h"

#include "routing/Routing.h"
#include "routing/PostOffice.h"

namespace mq {
using namespace postoffice;

static void OnPostUnloadPluginActorAPI(const char*);

static MQModule s_ActorAPIModule = {
	"ActorAPI",                      // Name
	false,                           // CanUnload
	nullptr,                         // Initialize
	nullptr,                         // Shutdown
	nullptr,                         // Pulse
	nullptr,                         // SetGameState
	nullptr,                         // UpdateImGui
	nullptr,                         // Zoned
	nullptr,                         // WriteChatColor
	nullptr,                         // SpawnAdded
	nullptr,                         // SpawnRemoved
	nullptr,                         // BeginZone
	nullptr,                         // EndZone
	nullptr,                         // LoadPlugin
	nullptr,                         // UnloadPlugin
	nullptr,                         // CleanUI
	nullptr,                         // ReloadUI
	OnPostUnloadPluginActorAPI,      // OnPostUnloadPlugin
};
MQModule* GetActorAPIModule() { return &s_ActorAPIModule; }
MQActorAPI* pActorAPI = nullptr;

std::unordered_map<MQPlugin*, std::vector<std::unique_ptr<postoffice::Dropbox>>> s_dropboxes;

// this is to allow for replies while not exposing message internals to the API
std::map<PipeMessage*, std::unique_ptr<ProtoMessage>> s_messageStorage;

static void OnPostUnloadPluginActorAPI(const char* pluginName)
{
	MQPlugin* plugin = GetPlugin(pluginName);
	auto it = s_dropboxes.find(plugin);
	if (it != s_dropboxes.end())
	{
		for (auto& dropbox : it->second)
			dropbox->Remove();

		it->second.clear();
		s_dropboxes.erase(it);
	}
}

void MQActorAPI::SendToActor(
	postoffice::Dropbox* dropbox,
	const postoffice::Address& address,
	const std::string& data,
	const postoffice::ResponseCallbackAPI& callback,
	const MQPluginHandle& pluginHandle /* = mqplugin::ThisPluginHandle */)
{
	proto::routing::Address addr;

	// Treat Main plugin handle as having no owner.
	MQPlugin* owner = GetPluginByHandle(pluginHandle, true);

	if (address.PID)
		addr.set_pid(*address.PID);
	else if (address.Name)
		addr.set_name(*address.Name);

	if (address.Mailbox && (address.AbsoluteMailbox || owner == nullptr))
		addr.set_mailbox(*address.Mailbox);
	else if (address.Mailbox && owner != nullptr)
		addr.set_mailbox(fmt::format("{}:{}", owner->name, *address.Mailbox));
	else if (owner != nullptr)
		addr.set_mailbox(owner->name);
	// else we have no mailbox or owner, so it must remain blank

	if (address.Account)
		addr.set_account(*address.Account);

	if (address.Server)
		addr.set_server(*address.Server);

	if (address.Character)
		addr.set_character(*address.Character);

	PipeMessageResponseCb pipe_callback = nullptr;
	if (callback != nullptr)
	{
		pipe_callback = [callback, address](int status, PipeMessagePtr&& message)
			{
				// no need to store this message in the message storage since we know it
				// can't be replied to -- which means we also don't need the custom deleter
				// assume that the sender is the address we sent to
				if (message->GetMessageId() == MQMessageId::MSG_ROUTE)
				{
					auto envelope = ProtoMessage::Parse<proto::routing::Envelope>(message);

					std::optional<postoffice::Address> sender;
					if (envelope.has_return_address())
					{
						auto s = envelope.return_address();
						sender = postoffice::Address{
							s.has_pid() ? std::make_optional(s.pid()) : std::nullopt,
							s.has_name() ? std::make_optional(s.name()) : std::nullopt,
							s.has_mailbox() ? std::make_optional(s.mailbox()) : std::nullopt,
							s.has_account() ? std::make_optional(s.account()) : std::nullopt,
							s.has_server() ? std::make_optional(s.server()) : std::nullopt,
							s.has_character() ? std::make_optional(s.character()) : std::nullopt,
							true
						};
					}

					std::optional<std::string> data;
					if (envelope.has_payload())
						data = envelope.payload();

					callback(status, std::make_shared<postoffice::Message>(
						postoffice::Message{message.get(), sender, data}));
				}
				else
				{
					callback(status, std::make_shared<postoffice::Message>(postoffice::Message{
						message.get(), address, std::string(message->get<const char>(), message->size())
					}));
				}
			};
	}

	// this addr can be ambiguous to allow multi-send -- rely on the post office to check for
	// ambiguity in the mailbox, the router to check for ambiguity in the client address, and
	// the receiving post office to check local ambiguity in the mailbox _for RPC messages
	// only_
	if (dropbox != nullptr)
	{
		dropbox->Post(addr, data, pipe_callback);
	}
	else
	{
		GetPostOffice().RouteMessage(addr, data, pipe_callback);
	}
}

void MQActorAPI::ReplyToActor(
	postoffice::Dropbox* dropbox,
	const std::shared_ptr<postoffice::Message>& message,
	const std::string& data,
	uint8_t status,
	const MQPluginHandle& pluginHandle)
{
	if (dropbox != nullptr && dropbox->IsValid())
	{
		auto message_ptr = s_messageStorage.find(message->Original);
		if (message_ptr != s_messageStorage.end())
		{
			// we don't want to do any address mangling here because a reply is always going to be fully qualified
			dropbox->PostReply(std::move(message_ptr->second), data, status);
			s_messageStorage.erase(message_ptr);
		}
	}

	// we don't need to erase the message from storage, the message destructor handles that for us
}

postoffice::Dropbox* MQActorAPI::AddActor(
	const char* localAddress,
	ReceiveCallbackAPI&& receive,
	const MQPluginHandle& pluginHandle)
{
	MQPlugin* owner = GetPluginByHandle(pluginHandle, true);

	auto dropbox = std::make_unique<Dropbox>(GetPostOffice().RegisterAddress(localAddress,
		[receive = std::move(receive)](ProtoMessagePtr&& message)
		{
			//auto sender = message->GetSender().value_or(proto::routing::Address());
			std::optional<postoffice::Address> sender;
			if (auto s = message->GetSender())
			{
				sender = postoffice::Address{
					s->has_pid() ? std::make_optional(s->pid()) : std::nullopt,
					s->has_name() ? std::make_optional(s->name()) : std::nullopt,
					s->has_mailbox() ? std::make_optional(s->mailbox()) : std::nullopt,
					s->has_account() ? std::make_optional(s->account()) : std::nullopt,
					s->has_server() ? std::make_optional(s->server()) : std::nullopt,
					s->has_character() ? std::make_optional(s->character()) : std::nullopt,
					true
				};
			}

			std::optional<std::string> data;
			if (message->size() > 0)
				data = std::string(message->get<char>(), message->size());

			ProtoMessage* message_ptr = message.get();
			s_messageStorage.emplace(message_ptr, std::move(message));

			receive(std::shared_ptr<postoffice::Message>(
				new postoffice::Message{ message_ptr, sender, data },
				[](postoffice::Message* message)
				{
					s_messageStorage.erase(message->Original);
					delete message;
				}));
		}));

	// return even if it's invalid so users don't have to null check
	// note that owner can be nullptr here (which would be for mq2main)
	return s_dropboxes[owner].emplace_back(std::move(dropbox)).get();
}

void MQActorAPI::RemoveActor(
	postoffice::Dropbox*& dropbox,
	const MQPluginHandle& pluginHandle)
{
	if (dropbox != nullptr)
	{
		dropbox->Remove();

		MQPlugin* owner = GetPluginByHandle(pluginHandle, true);

		auto dropboxes_it = s_dropboxes.find(owner);
		if (dropboxes_it != s_dropboxes.end())
		{
			auto dropbox_it = std::find_if(dropboxes_it->second.begin(), dropboxes_it->second.end(),
				[dropbox](const std::unique_ptr<postoffice::Dropbox>& ptr) { return ptr.get() == dropbox; });

			if (dropbox_it != dropboxes_it->second.end())
				dropboxes_it->second.erase(dropbox_it);

			if (dropboxes_it->second.empty())
				s_dropboxes.erase(dropboxes_it);
		}

		dropbox = nullptr;
	}
}

} // namespace mq
