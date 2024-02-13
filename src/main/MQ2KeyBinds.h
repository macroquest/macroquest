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

#include <mq/utils/Keybinds.h>

#include <functional>
#include <map>
#include <string>

namespace mq {

//----------------------------------------------------------------------------
// Internal functions

struct MQKeyBind
{
	std::string     Name;
	eqlib::KeyCombo Normal;
	eqlib::KeyCombo Alt;
	fMQExecuteCmd   Function;
	bool            State = false;
	int             Id = -1;

	MQKeyBind(std::string name, fMQExecuteCmd func)
		: Name(std::move(name))
		, Function(func)
	{}
};

// execute a keybind
bool MQ2HandleKeyDown(const eqlib::KeyCombo& Combo);
bool MQ2HandleKeyUp(const eqlib::KeyCombo& Combo);

// visit all keybinds
void EnumerateKeyBinds(const std::function<void(const MQKeyBind& keyBind)>& func);

// Get the total number of keybinds
int GetKeyBindsCount();

void InitializeMQ2KeyBinds();
void ShutdownMQ2KeyBinds();

} // namespace mq
