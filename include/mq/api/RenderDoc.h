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
#include "mq/base/Color.h"

namespace mq {
	
#ifdef _DEBUG

MQLIB_API void RenderDoc_BeginEvent(MQColor color, const wchar_t* name);
MQLIB_API void RenderDoc_EndEvent();

struct RenderDoc_ScopedEvent
{
	RenderDoc_ScopedEvent(MQColor color, const wchar_t* name) { RenderDoc_BeginEvent(color, name); }
	~RenderDoc_ScopedEvent() { RenderDoc_EndEvent(); }

	RenderDoc_ScopedEvent(const RenderDoc_ScopedEvent&) = delete;
	RenderDoc_ScopedEvent& operator=(const RenderDoc_ScopedEvent&) = delete;
	RenderDoc_ScopedEvent(RenderDoc_ScopedEvent&&) = delete;
	RenderDoc_ScopedEvent& operator=(RenderDoc_ScopedEvent&&) = delete;
};

MQLIB_API void RenderDoc_SetMarker(MQColor color, const wchar_t* name);

#else

inline void RenderDoc_BeginEvent(MQColor color, const wchar_t* name) {}
inline void RenderDoc_EndEvent() {}

struct RenderDoc_ScopedEvent
{
	RenderDoc_ScopedEvent(MQColor color, const wchar_t* name) {}
};

inline void RenderDoc_SetMarker(MQColor color, const wchar_t* name) {}

#endif // _DEBUG

MQLIB_API bool RenderDoc_IsEnabled();

} // namespace mq
