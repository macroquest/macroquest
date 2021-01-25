/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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
#include <string>

namespace mq {

struct PlatformHotkey
{
	enum modifier { Alt = 1, Ctrl = 2, Shift = 4, Win = 8 };

	uint16_t modifiers;
	uint16_t virtualKey;

	char keybind[32];
};

// Parse a string into the parameters for a PlatformHotKey.
bool ConvertStringToModifiersAndVirtualKey(const std::string& str, uint16_t& modkey, uint16_t& virtualKey);

// Returns if the modifiers used by the specified hotkey are pressed. If no modifiers are specified then this
// function returns true.
bool IsHotKeyModifiersPressed(const PlatformHotkey& hotkey);

// Get the name of the key by virtual key using our own code
const char* GetKeyNameFromVirtualKey(uint16_t virtualKey);

void GetModifiersName(uint16_t modifiers, char* szTemp, size_t length);

// Get the name of the modifiers
std::string GetModifiersName(uint16_t modifiers);

// Convert modifiers used by Hotkey control to modifiers
// used by RegisterHotKey
uint16_t ConvertHotKeyModifiersFromControl(uint16_t inModifiers);

// Convert modifiers used by RegisterHotKey to those used by
// the hotkey control.
uint16_t ConvertHotKeyModifiersToControl(uint16_t inModifiers);

bool ConvertModifiersAndVirtualKeyToString(uint16_t modkey, uint16_t virtualKey, std::string& str);

// Convert data from hotkey control into a string
std::string GetKeyNameFromHotKeyControl(uint32_t hotkey);

} // namespace mq
