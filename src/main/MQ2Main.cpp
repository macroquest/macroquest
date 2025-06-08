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

#include "pch.h"
#include "MQ2Main.h"
#include "CrashHandler.h"
#include "MQActorAPI.h"
#include "MQCommandAPI.h"
#include "MQDataAPI.h"
#include "MQ2KeyBinds.h"
#include "MQPluginHandler.h"
#include "ImGuiManager.h"

#include "eqlib/Init.h"
#include "mq/base/Logging.h"

#include <fmt/format.h>

#include <wil/resource.h>
#include <fstream>

#if !defined(COMMENT_UPDATER)
#include "client/crashpad_client.h"
#endif

#include <Psapi.h>

#pragma comment(lib, "Psapi.lib")
#pragma comment(lib, "version.lib")

namespace fs = std::filesystem;

using namespace std::chrono_literals;
using namespace eqlib;

namespace mq {

//============================================================================

HMODULE GetCurrentModule()
{
	HMODULE hModule = nullptr;

	// Retrieve our current module handle by using the address of this function as a search param.
	GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS
		| GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)GetCurrentModule, &hModule);

	return hModule;
}


//============================================================================

} // namespace mq
