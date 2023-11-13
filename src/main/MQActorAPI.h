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

#pragma once

#include "mq/base/Common.h"
#include "mq/api/ActorAPI.h"

namespace mq {

class MQActorAPI
{
public:
	void SendToActor(postoffice::Dropbox* dropbox, const postoffice::Address& address, uint16_t messageId, const std::string& data, MQPlugin* owner = nullptr);
	void ReplyToActor(postoffice::Dropbox* dropbox, ProtoMessagePtr&& message, uint16_t messageId, const std::string& data, uint8_t status, MQPlugin* owner = nullptr);
	postoffice::Dropbox* AddActor(const char* localAddress, postoffice::ReceiveCallback&& receive, MQPlugin* owner = nullptr);
	void RemoveActor(postoffice::Dropbox*& dropbox, MQPlugin* owner = nullptr);
	void OnUnloadPlugin(MQPlugin* plugin);

private:
	std::map<MQPlugin*, std::vector<std::unique_ptr<postoffice::Dropbox>>> m_dropboxes;
};

extern MQActorAPI* pActorAPI;

} // namespace mq
