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

#include "MQ2MainBase.h"

namespace mq {

namespace pipeclient {

// setting these configs is to allow testing without spoofing config files
void SetPostOfficeConfig(uint32_t index, std::string_view pipeName);
void DropPostOfficeConfig(uint32_t index);
void ClearPostOfficeConfigs();
void ClearPostOffices();

void NotifyIsForegroundWindow(bool isForeground);
void RequestActivateWindow(HWND hWnd, bool sendMessage = true);
void SendNotification(const std::string& message, const std::string& title);

void InitializePostOffice(uint32_t index = 0);
void ShutdownPostOffice(uint32_t index = 0);
void PulsePostOffice(uint32_t index = 0);
void SetGameStatePostOffice(DWORD, uint32_t index = 0);

} // namespace pipeclient

} // namespace mq
