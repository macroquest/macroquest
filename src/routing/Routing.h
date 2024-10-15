/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2020 MacroQuest Authors
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

#include "Routing.pb.h"

enum class MQRequestMode : uint8_t
{
	SimpleMessage   = 0,          // (Default) This is a simple message. There is no reply.
	CallAndResponse = 1,          // This is an RPC style message with a reply.
	MessageReply    = 2,          // This is an RPC style message reply.
};

// Error Codes that can be delivered in a message callback. These are negative, because positive error
// codes should originate from the message itself.
constexpr int MsgError_ConnectionClosed        = -1;                  // connection was closed
constexpr int MsgError_NoConnection            = -2;                  // no connection established
constexpr int MsgError_RoutingFailed           = -3;                  // message routing failed
constexpr int MsgError_AmbiguousRecipient      = -4;                  // RPC message couldn't determine single recipient

#ifdef _DEBUG
#pragma comment(lib, "libprotobufd")
#else
#pragma comment(lib, "libprotobuf")
#endif

#pragma comment(lib, "routing")
