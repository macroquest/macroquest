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

#if !defined(MQ2MAIN_IMPL) && !defined(__clang__)
#error This header should only be included from the MQ2Main project
#endif

#include "routing/ClientPostOffice.h"

#include <string>

namespace mq {

class MQPostOffice final : public postoffice::ClientPostOffice
{
public:
	MQPostOffice();
	virtual ~MQPostOffice() override;

	void NotifyIsForegroundWindow(bool isForeground);
	void RequestActivateWindow(HWND hWnd, bool sendMessage);
	void SendNotification(const std::string& message, const std::string& title);
	void SetGameState(int GameState);

private:
	virtual void OnIncomingMessage(PipeMessagePtr message) override;
	virtual void OnClientConnected() override;

	virtual void SendSelfIdentification() override;

	virtual postoffice::ActorIdentification::Client GetCurrentClient() const override;

	bool m_loggedIn = false;
};

MQPostOffice& GetPostOffice();

namespace pipeclient {
// this namespace is for interfaces that directly send messages over the pipe, without the
// need for a post office. The only reason they are here is because the post office handles
// the pipe connection

void NotifyIsForegroundWindow(bool isForeground);
void RequestActivateWindow(HWND hWnd, bool sendMessage = true);
void SendNotification(const std::string& message, const std::string& title);

} // namespace pipeclient

} // namespace mq
