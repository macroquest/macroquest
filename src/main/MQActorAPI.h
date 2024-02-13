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

#include "mq/base/Common.h"
#include "mq/api/ActorAPI.h"

namespace mq {

class MQActorAPI
{
public:
	void SendToActor(
		postoffice::Dropbox* dropbox,
		const postoffice::Address& address,
		const std::string& data,
		const postoffice::ResponseCallbackAPI& callback,
		MQPlugin* owner = nullptr);

	void ReplyToActor(
		postoffice::Dropbox* dropbox,
		const std::shared_ptr<postoffice::Message>& message,
		const std::string& data,
		uint8_t status,
		MQPlugin* owner = nullptr);

	postoffice::Dropbox* AddActor(
		const char* localAddress,
		postoffice::ReceiveCallbackAPI&& receive,
		MQPlugin* owner = nullptr);

	void RemoveActor(
		postoffice::Dropbox*& dropbox,
		MQPlugin* owner = nullptr);

	void OnUnloadPlugin(MQPlugin* plugin);
};

extern MQActorAPI* pActorAPI;

} // namespace mq
