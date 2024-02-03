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

namespace wil {
    // These were originally in wil's registry.h but were removed.  They are still useful to have
    // for legacy code so that you can get access to MAX_KEY_LENGTH and MAX_VALUE_NAME without
    // including windows.h.

    // The key name includes the absolute path of the key in the registry, always starting at a
    // base key, for example, HKEY_LOCAL_MACHINE.
    constexpr size_t max_registry_key_name_length = 255;

    // The maximum number of characters allowed in a registry value's name.
    constexpr size_t max_registry_value_name_length = 16383;
}