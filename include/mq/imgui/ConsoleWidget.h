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

#include "mq/zep/ImGuiZepConsole.h"

namespace mq::imgui {

// ConsoleWidget has been migrated to ImGuiZepConsole. This specialization simply installs the
// MQConsoleDelegate into a fresh instance of the ImGuiZepConsole.
class ConsoleWidget : public mq::ImGuiZepConsole
{
public:
	using mq::ImGuiZepConsole::ImGuiZepConsole;

	MQLIB_OBJECT static std::shared_ptr<ConsoleWidget> Create(std::string_view id);
};

} // namespace mq::imgui
