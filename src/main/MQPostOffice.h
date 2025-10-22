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

#include "routing/NamedPipesProtocol.h"

#include <string>

namespace mq {

namespace pipeclient {
// this namespace is for interfaces that directly send messages over the pipe, without the
// need for a post office. The only reason they are here is because the post office handles
// the pipe connection

/**
 * Returns true if the named pipe is connected.
 */
bool IsConnected();

/**
 * Sends a message over the named pipe connection.
 */
void SendPipeMessage(MQMessageId messageId, const void* data, size_t dataLength);

/**
 * Request that the specified window be activated. If the named pipe is connected
 * and sendMessage is true, the request will be fulfilled by sending a request to
 * the post office. If sendMessage is false, or the named pipe is not connected,
 * the application will attempt to focus itself (which may not always work).
 * 
 * @param hWnd The window handle to request activation for.
 * @param sendMessage If true, attempt to activate using the named pipe connection.
 * @return True if the request was sent. False otherwise.
 */
bool RequestActivateWindow(HWND hWnd, bool sendMessage = true);

/**
 * Request a notification be displayed from the launcher with the specified parameters.
 *
 * @param title Text to display in the notification title
 * @param message Text to display in the notification message body
 * @return True if the request was sent. False otherwise.
 */
bool SendTrayNotification(const std::string& title, const std::string& message);

} // namespace pipeclient

} // namespace mq
