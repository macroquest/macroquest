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

namespace mq {

#define DebugTryBegin()
#define DebugTryEnd()

#define DebugTryBeginRet()
#define DebugTryEndRet()

#define DebugTryEx(x) x

//============================================================================

// Install/Remove the actual crash handler.
void InstallUnhandledExceptionFilter();
void UninstallUnhandledExceptionFilter();

bool InitializeCrashpad();
void InitializeCrashpadPipe(const std::string& pipeName);

void CrashHandler_Startup();
void CrashHandler_SetLastCommand(const char* command);
void CrashHandler_SetLastMacroData(const char* macroData);

} // namespace mq

typedef struct _EXCEPTION_POINTERS EXCEPTION_POINTERS;

namespace mq {
	void InvokeExceptionHandler(EXCEPTION_POINTERS* p);
}
