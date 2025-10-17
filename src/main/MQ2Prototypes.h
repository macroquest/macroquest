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

namespace mq {

struct MQGroundSpawn;

using fEQGetMelee            = float  (*)(eqlib::PlayerClient*, eqlib::PlayerClient*);

// MQ2 Callback types
using fMQCommand             = void   (*)(eqlib::PlayerClient*, char* Buffer, size_t BuffLen);
using fCascadeItemFunction   = void   (*)();
struct TokenTextParam;
using fMQTokenMessageCmd     = void   (*)(const TokenTextParam&);


// Misc Function types
using fEQW_GetDisplayWindow  = HWND(CALLBACK*)();

} // namespace mq
