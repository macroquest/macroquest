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

#include <cstdint>

// Interface for handling the notifications of processes being added or removed
class ProcessMonitorEvents
{
public:
	virtual ~ProcessMonitorEvents() = default;

	virtual void HandleProcessCreation(uint32_t processId) = 0;

	virtual void HandleProcessDestruction(uint32_t processId) = 0;
};

//----------------------------------------------------------------------------

void StartProcessMonitor(ProcessMonitorEvents*);
void StopProcessMonitor();
