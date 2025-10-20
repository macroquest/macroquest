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

#include "routing/ServerPostOffice.h"

#include <string>
#include <optional>
#include <vector>
#include <chrono>

namespace mq {

struct MQMessageFocusRequest;
class ProtoPipeServer;
class PipeConnection;
class NetworkPeerAPI;

} // namespace mq

using GetCrashpadPipe = std::function<std::string()>;
using RequestFocusCallback = std::function<void(const mq::MQMessageFocusRequest*)>;

// ImGui
void InitializePostOfficeImGui();
void ShutdownPostOfficeImGui();

bool SendSetForegroundWindow(HWND hWnd, uint32_t processID);
void SendUnloadAllCommand();
void SendForceUnloadAllCommand();

void SetPostOfficeIni(std::string_view ini);
void SetCrashpadCallback(const GetCrashpadPipe& getCrashpad);
void SetRequestFocusCallback(const RequestFocusCallback& requestFocus);
void SetTriggerPostOffice(const std::function<void()>& triggerProcess);
void InitializePostOffice();
void ShutdownPostOffice();

// ----------------------------- Post Office ----------------------------------

class LauncherPostOffice final : public mq::postoffice::ServerPostOffice
{
public:
	explicit LauncherPostOffice();
	virtual ~LauncherPostOffice() override;

	LauncherPostOffice(const LauncherPostOffice&) = delete;
	LauncherPostOffice& operator=(const LauncherPostOffice&) = delete;
	LauncherPostOffice(LauncherPostOffice&&) = delete;
	LauncherPostOffice& operator=(LauncherPostOffice&&) = delete;

	virtual void AddConfiguredHosts() override;

	virtual void OnIncomingMessage(mq::postoffice::LocalConnection* connection, mq::PipeMessagePtr message) override;
	virtual void OnRequestProcessEvents(mq::postoffice::LocalConnection* connection) override;
	virtual void OnIncomingConnection(mq::postoffice::LocalConnection* connection, int connectionId, int processId) override;
};

LauncherPostOffice& GetPostOffice();
