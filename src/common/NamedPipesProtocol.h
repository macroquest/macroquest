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

#include <cstdint>

namespace mq {

// The name of the named pipe used by the named pipe server to communicate with other clients.
constexpr const char* MQ2_PIPE_SERVER_PATH = R"(\\.\pipe\mqpipe)";

enum class MQMessageId : uint16_t
{
	MSG_NULL                               = 0,     // An empty message, used for transmitting an acknowledgement response
	MSG_ECHO                               = 1,     // Send an echo message. Server will reply with the same payload. For testing.

	// FIXME: We really should have message ids separated by plugins or services. For now we will use a single enum
	// and just change it later.

	// Messages to/from MQ2Main
	MSG_MAIN_PROCESS_LOADED                = 1000,  // to/from mq: process has successfully injected
	MSG_MAIN_PROCESS_UNLOADED              = 1001,  // from mq: process is about to unload mq
	MSG_MAIN_CRASHPAD_CONFIG               = 1002,  // to mq: sends named pipe used for crashpad.
	MSG_MAIN_REQ_UNLOAD                    = 1003,  // to mq: ask mq to nicely unload.
	MSG_MAIN_FOCUS_REQUEST                 = 1004,  // to/from mq: i have focus or i want focus.
	MSG_MAIN_FOCUS_ACTIVATE_WND            = 1005,  // to mq: activate requested window
	MSG_MAIN_REQ_FORCEUNLOAD               = 1006,  // to mq: ask mq to less nicely unload.

	MSG_AUTOLOGIN_PROFILE_LOADED           = 2000,  // profile has been loaded
	MSG_AUTOLOGIN_PROFILE_UNLOADED         = 2001,  // profile has been uploaded
	MSG_AUTOLOGIN_PROFILE_CHARINFO         = 2002,  // update the character info
	MSG_AUTOLOGIN_START_INSTANCE           = 2003,  // create a new process, optionally with params
};

enum class MQProtoVersion : uint8_t
{
	V0              = 0,          // Initial protocol version is v0.
	Version_Default = V0,
};

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

#pragma pack(push)
#pragma pack(1)

// Message structure used for sending messages over the named pipe
struct MQMessageHeader
{
/*0x00*/ MQProtoVersion protoVersion;               // protocol version. Initial version is 0.
/*0x01*/ MQRequestMode  mode;                       // mode for a request
/*0x02*/ uint8_t        status;                     // status code for a reply
/*0x03*/ uint8_t        placeholder;                // nothing yet.
/*0x04*/ uint32_t       sequenceId;                 // sequence id. Replies will use the same sequence id.
/*0x08*/ MQMessageId    messageId;                  // id of the message.
/*0x0A*/ uint16_t       placeholder2;               // nothing yet.
/*0x0C*/ uint32_t       messageLength;              // length of the message
/*0x10*/
};

#pragma pack(pop)

// MSG_MAIN_PROCESS_LOADED
struct MQMessageProcessLoadedFromMQ
{
	uint32_t            processId;     // id of eqgame process
};

struct MQMessageProcessLoadedResponse
{
	uint32_t            processId;     // id of launcher process
};

// MSG_MAIN_FOCUS_REQUEST   -> from mq
struct MQMessageFocusRequest
{
	enum class FocusMode : uint32_t { HasFocus, WantFocus };
	FocusMode           focusMode;
	bool                state = false;       // has focus
	uint32_t            processId = 0;       // has focus
	void*               hWnd = nullptr;      // want focus
};

// MSG_MAIN_FOCUS_ACTIVATE_WND -> to mq
struct MQMessageActivateWnd
{
	void*               hWnd = nullptr;
};

//----------------------------------------------------------------------------

// MSG_MAIN_CRASHPAD_PIPENAME
// message is just a variable length string.

} // namespace mq
