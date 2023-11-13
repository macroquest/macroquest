/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
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

static void UnloadPluginActorAPI(const char*);

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
	UnloadPluginActorAPI,            // UnloadPlugin
	false,                           // loaded
	false                            // manualUnload
};
MQModule* GetActorAPIModule() { return &s_ActorAPIModule; }

static void UnloadPluginActorAPI(const char* pluginName)
{
	MQPlugin* plugin = GetPlugin(pluginName);
	if (plugin != nullptr && pActorAPI != nullptr)
	{
		pActorAPI->OnUnloadPlugin(plugin);
	}
}

MQActorAPI* pActorAPI = nullptr;

std::map<MQPlugin*, std::vector<std::unique_ptr<postoffice::Dropbox>>> s_dropboxes;

void MQActorAPI::SendToActor(postoffice::Dropbox* dropbox, const postoffice::Address& address, uint16_t messageId, const std::string& data, MQPlugin* owner)
{
	if (dropbox != nullptr)
	{
		proto::routing::Address addr;

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

		dropbox->Post(addr, static_cast<MQMessageId>(messageId), data);
	}
}

void MQActorAPI::ReplyToActor(postoffice::Dropbox* dropbox, postoffice::Message&& message, uint16_t messageId, const std::string& data, uint8_t status, MQPlugin* owner)
{
	if (dropbox != nullptr && dropbox->IsValid())
	{
		// we don't want to do any address mangling here because a reply is always going to be fully qualified
		dropbox->PostReply(std::move(message.Original), messageId, data, status);
	}
}

postoffice::Dropbox* MQActorAPI::AddActor(const char* localAddress, ReceiveCallbackAPI&& receive, MQPlugin* owner)
{
	auto dropbox = std::make_unique<Dropbox>(GetPostOffice().RegisterAddress(localAddress,
		[receive = std::move(receive)](ProtoMessagePtr&& message)
		{
			auto sender = message->GetSender().value_or(proto::routing::Address());
			auto envelope = message->Parse<proto::routing::Envelope>();
			// we can discard the address here because the message has been routed already.

			std::string data;
			if (envelope.has_payload())
				data = envelope.payload();

			receive(postoffice::Message{
				std::move(message),
				postoffice::Address{
					sender.has_pid() ? std::make_optional(sender.pid()) : std::nullopt,
					sender.has_name() ? std::make_optional(sender.name()) : std::nullopt,
					sender.has_mailbox() ? std::make_optional(sender.mailbox()) : std::nullopt,
					sender.has_account() ? std::make_optional(sender.account()) : std::nullopt,
					sender.has_server() ? std::make_optional(sender.server()) : std::nullopt,
					sender.has_character() ? std::make_optional(sender.character()) : std::nullopt,
					true
				},
				data
			});
		}));

	// return even if it's invalid so users don't have to null check
	// note that owner can be nullptr here (which would be for mq2main)
	return s_dropboxes[owner].emplace_back(std::move(dropbox)).get();
}

void MQActorAPI::RemoveActor(postoffice::Dropbox*& dropbox, MQPlugin* owner)
{
	if (dropbox != nullptr)
	{
		dropbox->Remove();
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

void MQActorAPI::OnUnloadPlugin(MQPlugin* plugin)
{}

} // namespace mq
