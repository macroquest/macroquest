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

#include "MQ2MainBase.h"
#include "common/Mailbox.h"
#include "common/ProtoPipes.h"

namespace mq {

void InitializePipeClient();
void ShutdownPipeClient();

namespace pipeclient {

MQLIB_API uint32_t GetLauncherProcessID();

void NotifyIsForegroundWindow(bool isForeground);
void RequestActivateWindow(HWND hWnd, bool sendMessage = true);

MQLIB_OBJECT std::shared_ptr<mailbox::PostOffice::Mailbox> AddMailbox(const std::string& localAddress, mailbox::PostOffice::ReceiveCallback receive);
MQLIB_OBJECT bool RemoveMailbox(const std::string& localAddress);
MQLIB_OBJECT void RouteMessage(MQMessageId messageId, const void* data, size_t length);
MQLIB_OBJECT void RouteMessage(MQMessageId messageId, const std::string& data);
MQLIB_OBJECT void RouteMessage(const std::string& data); // envelopes come as strings, and will always want "ROUTE" message IDs

} // namespace pipeclient

} // namespace mq
