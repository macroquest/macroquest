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

#include "common/Mailbox.h"
#include "common/ProtoPipes.h"

bool SendSetForegroundWindow(HWND hWnd, uint32_t processID);
void SendUnloadAllCommand();
void SendForceUnloadAllCommand();
void ProcessPipeServer();

void InitializeNamedPipeServer();
void ShutdownNamedPipeServer();

using PipeServerPO = mq::mailbox::PostOffice<PipeMessagePtr>;
template <typename MessageType>
bool AddMailbox(
	const std::string& localAddress,
	PipeServerPO::ParseCallback<MessageType> deliver,
	PipeServerPO::ReceiveCallback<MessageType> receive)
{
	AddMailbox(localAddress, PipeServerPO::CreateMailbox(localAddress, deliver, receive));
}

bool AddMailbox(const std::string& localAddress, std::unique_ptr<PipeServerPO::MailboxConcept>&& mailbox);
bool RemoveMailbox(const std::string& localAddress);
