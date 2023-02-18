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

#include <mq/proto/Mailbox.h>

bool SendSetForegroundWindow(HWND hWnd, uint32_t processID);
void SendUnloadAllCommand();
void SendForceUnloadAllCommand();
void ProcessPipeServer();

void InitializeNamedPipeServer();
void ShutdownNamedPipeServer();

std::shared_ptr<mailbox::PostOffice::Mailbox> AddMailbox(const std::string& localAddress, mailbox::PostOffice::ReceiveCallback receive);
bool RemoveMailbox(const std::string& localAddress);
void RouteMessage(MQMessageId messageId, const void* data, size_t length);
template <typename ID>
void RouteMessage(ID messageId, const void* data, size_t length)
{
	RouteMessage(static_cast<MQMessageId>(messageId), data, length);
}

void RouteMessage(MQMessageId messageId, const std::string& data);
template <typename ID>
void RouteMessage(ID messageId, const std::string& data)
{
	RouteMessage(static_cast<MQMessageId>(messageId), data);
}

void RouteMessage(const std::string& data); // envelopes come as strings, and will always want "ROUTE" message IDs
