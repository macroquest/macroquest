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

bool SendSetForegroundWindow(HWND hWnd, uint32_t processID);
void SendUnloadAllCommand();
void SendForceUnloadAllCommand();
void ProcessPipeServer();

// networking interface
void PeerMessageReceived(std::string_view address, uint16_t port, std::unique_ptr<uint8_t[]>&& payload, size_t length);
void PeerConnected(std::string_view address, uint16_t port);

void InitializeNamedPipeServer();
void ShutdownNamedPipeServer();

