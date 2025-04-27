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

#include "eqlib/game/KeyCombo.h"

namespace mq {

//----------------------------------------------------------------------------
// Public Functions

// Add an MQ2 Keybind
using fMQExecuteCmd = void(*)(const char* Name, bool Down);
MQLIB_API bool AddMQ2KeyBind(const char* name, fMQExecuteCmd Function);

// Remove an MQ2 Keybind
MQLIB_API bool RemoveMQ2KeyBind(const char* name);

// Assign an MQ2 Keybind
MQLIB_API bool SetMQ2KeyBind(const char* name, bool Alternate, eqlib::KeyCombo& Combo);

// Retrieve an MQ2 Keybind
MQLIB_API bool GetMQ2KeyBind(const char* name, bool Alt, eqlib::KeyCombo& Combo);

// Trigger an MQ2 Keybind
MQLIB_API bool PressMQ2KeyBind(const char* name, bool Hold);

// Set an EQ Keybind
MQLIB_API bool SetEQKeyBind(const char* name, bool alternate, eqlib::KeyCombo& combo);

// Find an EQ mappable command by its name.
MQLIB_API int FindMappableCommand(const char* name);

// Dump the list of binds to a file
MQLIB_API bool DumpBinds(const char* Filename);

// Parse a text string into a KeyCombo
MQLIB_API bool ParseKeyCombo(const char* text, eqlib::KeyCombo& Dest);

// Serialize a KeyCombo into a string.
MQLIB_API char* DescribeKeyCombo(const eqlib::KeyCombo& Combo, char* szDest, size_t BufferSize);

} // namespace mq
