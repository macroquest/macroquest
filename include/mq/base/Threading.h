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

#include <mq/base/Common.h>

namespace mq {

MQLIB_API DWORD GetMainThreadId();
MQLIB_API bool IsMainThread();

// Queue a function to be called on the main thread on the next pulse
MQLIB_OBJECT void PostToMainThread(std::function<void()>&& callback);

} // namespace mq