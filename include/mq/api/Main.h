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

#include "mq/api/MacroAPI.h"
#include "mq/api/ActorAPI.h"
#include "mq/api/Plugin.h"

namespace mq {

class MainInterface
{
public:
	virtual ~MainInterface() {}

	// TLO Access
	virtual bool AddTopLevelObject(const char* name, MQTopLevelObjectFunction callback, MQPlugin* owner) = 0;
	virtual bool RemoveTopLevelObject(const char* name, MQPlugin* owner) = 0;
	virtual MQTopLevelObject* FindTopLevelObject(const char* name) = 0;

	// Actor Access
	virtual void SendToActor(
		postoffice::Dropbox* dropbox,
		const postoffice::Address& address,
		const std::string& data,
		const postoffice::ResponseCallbackAPI& callback,
		MQPlugin* owner) = 0;

	virtual void ReplyToActor(
		postoffice::Dropbox* dropbox,
		const std::shared_ptr<postoffice::Message>& message,
		const std::string& data,
		uint8_t status,
		MQPlugin* owner) = 0;

	virtual postoffice::Dropbox* AddActor(
		const char* localAddress,
		postoffice::ReceiveCallbackAPI&& receive,
		MQPlugin* owner) = 0;

	virtual void RemoveActor(
		postoffice::Dropbox*& dropbox,
		MQPlugin* owner) = 0;
};

MQLIB_OBJECT MainInterface* GetMainInterface();

} // namespace mq
