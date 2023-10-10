/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
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

#include "pch.h"
#include "MQ2Main.h"
#include "MQ2DeveloperTools.h"
#include "CrashHandler.h"
#include "ImGuiManager.h"
#include "ImGuiBackend.h"
#include "GraphicsEngine.h"

#include "common/HotKeys.h"
#include "imgui/ImGuiUtils.h"

#include <imgui.h>
#include <imgui_stdlib.h>

#include <spdlog/spdlog.h>
#include <fmt/format.h>
#include <atomic>
#include <vector>

namespace mq {

//----------------------------------------------------------------------------
// statics



void ShutdownOverlayInternal()
{
	if (!gbDeviceHooksInstalled)
		return;

	RemoveDetours();
	gbDeviceHooksInstalled = false;
	gHooks.clear();

	ShutdownImGui();

	gpD3D9Device = nullptr;
	gResetDeviceAddress = 0;
	gbRetryHooks = false;
	gbInitializationFailed = false;
	gbDeviceAcquired = false;

	engine::ResetInputState();
}



} // namespace mq
