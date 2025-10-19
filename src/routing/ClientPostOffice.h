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

#include "PostOffice.h"
#include "ProtoPipes.h"

#include <optional>

namespace mq::postoffice {

// this post office has exactly one connection, the pipe connection that connects to the launcher for routing. With
// that in mind, this is going to couple the post office and the connection because there's no intention of creating
// more types of connections in main
class ClientPostOffice : public PostOffice
{
	friend class PostOfficePipeHandler;

public:
	ClientPostOffice(const std::string& name, const std::string& pipeName, ActorIdentification id);
	virtual ~ClientPostOffice() override;

	const std::string& GetName() const { return m_name; }

	using PostOffice::RouteMessage;
	virtual void RouteMessage(postoffice::MessagePtr message) override;

	void Initialize();
	void Shutdown();
	void ProcessPipeClient();

protected:
	virtual void OnIncomingMessage(PipeMessagePtr message);
	virtual void OnClientConnected();

	virtual void SendSelfIdentification();

	virtual ActorIdentification::Client GetCurrentClient() const { return ActorIdentification::Client{}; }

	// Find a mailbox by address, starting from 'from' iterator
	MailboxMap::iterator FindMailbox(const proto::routing::Address& address,
		MailboxMap::iterator from);
	MailboxMap::const_iterator FindMailbox(const proto::routing::Address& address,
		MailboxMap::const_iterator from) const;

protected:
	std::string m_name;
	ProtoPipeClient m_pipeClient;
	postoffice::Dropbox m_clientDropbox;
	uint32_t m_launcherProcessID = 0;
	bool m_initialized = false;
};

} // namespace mq::postoffice
