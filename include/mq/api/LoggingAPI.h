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

namespace mq {

// Logging / Console output
void WriteChatColor(const char* line, int color = -1, int filter = 0);
void WriteChatf(const char* format, ...);
void WriteChatColorf(const char* format, int color, ...); // info level

// Outputs to debug console when gFilterDebug is false.  Does not output to file. (/filter debug or FilterDebug=0 in ini)
void DebugSpew(const char* format, ...); // -> debug level

// Outputs to debug console always. Outputs to file when gSpewToFile is true. (/spewfile or DebugSpewToFile=1 in ini)
void DebugSpewAlways(const char* format, ...); // -> debug level

// Outputs to debug console when DBG_SPEW is defined -> trace level
void DebugSpewNoFile(const char* format, ...);

// error logging
MQLIB_API void SyntaxError(const char* szFormat, ...); // -> warning level with extra steps
MQLIB_API void MacroError(const char* szFormat, ...); // -> error level with extra steps

// Internal usage only:
void FatalError(const char* szFormat, ...);
void MQ2DataError(const char* szFormat, ...);


MQLIB_API DWORD MQToSTML(const char* in, char* out, size_t maxlen = MAX_STRING, uint32_t ColorOverride = 0xFFFFFF);
MQLIB_API size_t StripMQChat(const char* in, char* out);
MQLIB_OBJECT size_t StripMQChat(std::string_view in, char* out);
MQLIB_API void STMLToPlainText(char* in, char* out);
MQLIB_API void CheckChatForEvent(const char* szMsg);

} // namespace mq
