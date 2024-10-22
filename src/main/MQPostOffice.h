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

#ifndef MQ2MAIN_EXPORTS
#error This header should only be included from the MQ2Main project
#endif

#ifndef _WINDEF_
class HWND__;
typedef HWND__* HWND;
#endif

#include <string>
#include <optional>

namespace mq {

struct MQPostOfficeConfig
{
	uint32_t Index;
	std::string Name; // useful for debugging
	std::optional<std::string> PipeName;
	std::optional<std::string> AccountOverride;
	std::optional<std::string> ServerOverride;
	std::optional<std::string> CharacterOverride;
};

// setting these configs is to allow testing without spoofing config files
void SetPostOfficeConfig(const MQPostOfficeConfig& config);
void DropPostOfficeConfig(uint32_t index);
void ClearPostOfficeConfigs();
void ClearPostOffices();

void InitializePostOffice(uint32_t index = 0);
void ShutdownPostOffice(uint32_t index = 0);
void PulsePostOffice(uint32_t index = 0);
void SetGameStatePostOffice(int GameState, uint32_t index = 0);

namespace pipeclient {
// this namespace is for interfaces that directly send messages over the pipe, without the
// need for a post office. The only reason they are here is because the post office handles
// the pipe connection

void NotifyIsForegroundWindow(bool isForeground);
void RequestActivateWindow(HWND hWnd, bool sendMessage = true);
void SendNotification(const std::string& message, const std::string& title);

} // namespace pipeclient

} // namespace mq
