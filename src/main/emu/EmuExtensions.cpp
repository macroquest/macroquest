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
#include "emu/EmuExtensions.h"

#include "MQ2Main.h"
#include "MQPluginHandler.h"
#include "imgui/ImGuiUtils.h"

#if IS_EMU_CLIENT
namespace mq {

static void EmuExtensions_Initialize();
static void EmuExtensions_Shutdown();
static void EmuExtensions_Pulse();
static void EmuExtensions_UpdateImGui();

static MQModule gEmuExtensionsModule = {
	"EmuExtensions",              // Name
	true,                         // CanUnload
	EmuExtensions_Initialize,     // Initialize
	EmuExtensions_Shutdown,       // Shutdown
	EmuExtensions_Pulse,          // Pulse
	nullptr,                      // SetGameState
	EmuExtensions_UpdateImGui,    // UpdateImGui
	nullptr,                      // Zoned
	nullptr,                      // WriteChatColor
	nullptr,                      // SpawnAdded
	nullptr,                      // SpawnRemoved
	nullptr,                      // BeginZone
	nullptr,                      // EndZone
	nullptr,                      // LoadPlugin
	nullptr,                      // UnloadPlugin
};
MQModule* GetEmuExtensionsModule() { return &gEmuExtensionsModule; }


//--------------------------------------------------------------------------
// Emu Constant CPU Affinity Support
//--------------------------------------------------------------------------

#if EMU_CONSTANT_AFFINITY_ENABLED

static bool s_setCpuConstantAffinity = true;
static bool s_hasSetCpuAffinity = false;

void EmuInitCpuAffinity()
{
	s_setCpuConstantAffinity = GetPrivateProfileBool("MacroQuest", "SetConstantAffinity", true, mq::internal_paths::MQini);
	if (gbWriteAllConfig)
	{
		WritePrivateProfileBool("MacroQuest", "SetConstantAffinity", s_setCpuConstantAffinity, mq::internal_paths::MQini);
	}
}

void EmuSetCpuAffinity()
{
	if (s_setCpuConstantAffinity)
	{
		SYSTEM_INFO SystemInfo;
		HANDLE processHandle = GetCurrentProcess();
		GetSystemInfo(&SystemInfo);
		int cores = SystemInfo.dwNumberOfProcessors;

		int m = int(pow(2, cores) - 1);
		DebugSpewAlways("Setting processor affinity to %d (%d logical cores)", m, cores);
		SetProcessAffinityMask(processHandle, m);
	}
}

#endif // EMU_CONSTANT_AFFINITY_ENABLED

//--------------------------------------------------------------------------
// Emu Exception Handler "Fix"
//--------------------------------------------------------------------------

#if EMU_FIX_EXCEPTION_HANDLER_ENABLED

static bool s_hasFixedExceptionHandlerChain = false;

// This a workaround for the EMU client having a global __try/__catch block wrapping
// the main game loop, which causes exceptions that we want to catch to be swallowed
// up instead of going to our unhandled exception filter.

// Structure for the exception registration record
struct EXCEPTION_REGISTRATION_RECORD {
	EXCEPTION_REGISTRATION_RECORD* Next;
	PVOID ExceptionHandler;
};

#pragma warning(push)
#pragma warning(disable: 4733)
static EXCEPTION_REGISTRATION_RECORD* GetExceptionRegistrationRecords()
{
	EXCEPTION_REGISTRATION_RECORD* result;

	__asm {
		mov eax, dword ptr fs : [0]
		mov result, eax
	}

	return result;
}

bool EmuFixExceptionHandler()
{
	EXCEPTION_REGISTRATION_RECORD* pRecord = GetExceptionRegistrationRecords();
	EXCEPTION_REGISTRATION_RECORD* pPrevRecord = nullptr;

	while (reinterpret_cast<uintptr_t>(pRecord) != 0xffffffff)
	{
		if (reinterpret_cast<uintptr_t>(pRecord->ExceptionHandler) == __ExceptionFilter)
		{
			DebugSpewAlways("Removing exception handler: 0x%p", pRecord);

			if (pPrevRecord)
			{
				pPrevRecord->Next = pRecord->Next;
			}
			else
			{
				EXCEPTION_REGISTRATION_RECORD* pNextRecord = pRecord->Next;
				__asm {
					mov eax, pNextRecord
					mov dword ptr fs:[0], eax
				}
			}
			return true;
		}

		pPrevRecord = pRecord;
		pRecord = pRecord->Next;
	}

	return false;
}

static void Command_PrintSEHChain(PlayerClient*, const char*)
{
	EXCEPTION_REGISTRATION_RECORD* pRecord = GetExceptionRegistrationRecords();

	WriteChatf("SEH Chain:");
	while (reinterpret_cast<uintptr_t>(pRecord) != 0xffffffff)
	{
		const char* color = "\ag";
		if (reinterpret_cast<uintptr_t>(pRecord->ExceptionHandler) == __ExceptionFilter)
			color = "\ar";
		WriteChatf("%s%p: Next: %p, Handler: %p", color, pRecord, pRecord->Next, pRecord->ExceptionHandler);
		pRecord = pRecord->Next;
	}
}
#pragma warning(pop)

#endif // EMU_POP_EXCEPTION_HANDLER_ENABLED

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

static void EmuExtensions_SettingsPanel()
{
#if EMU_CONSTANT_AFFINITY_ENABLED
	if (ImGui::Checkbox("Set CPU Affinity", &s_setCpuConstantAffinity))
	{
		WritePrivateProfileBool("MacroQuest", "SetConstantAffinity", s_setCpuConstantAffinity, mq::internal_paths::MQini);

		EmuSetCpuAffinity();
	}
	ImGui::SameLine();
	mq::imgui::HelpMarker("When enabled, the client will be able to use all cores (RECOMMENDED). Disabling this option will require a client restart to apply.");
#endif
}

static void EmuExtensions_Initialize()
{
#if EMU_CONSTANT_AFFINITY_ENABLED
	EmuInitCpuAffinity();
#endif
#if EMU_FIX_EXCEPTION_HANDLER_ENABLED
	AddCommand("/printsehchain", Command_PrintSEHChain);
#endif

	AddSettingsPanel("Emu Extensions", EmuExtensions_SettingsPanel);
}

static void EmuExtensions_Shutdown()
{
#if EMU_SPELL_LINKS_ENABLED
	RemoveDetour(__ConvertItemTags);
	RemoveDetour(CChatWindow__WndNotification);
#endif
#if EMU_FIX_EXCEPTION_HANDLER_ENABLED
	RemoveCommand("/printsehchain");
#endif
}

static void EmuExtensions_Pulse()
{
#if EMU_CONSTANT_AFFINITY_ENABLED
	// Wait for first pulse to set affinity, to ensure that we always set this after EQ messes it up.
	if (!s_hasSetCpuAffinity)
	{
		EmuSetCpuAffinity();
		s_hasSetCpuAffinity = true;
	}
#endif // EMU_CONSTANT_AFFINITY_ENABLED
#if EMU_FIX_EXCEPTION_HANDLER_ENABLED
	if (gGameState >= GAMESTATE_CHARSELECT && gGameState <= GAMESTATE_INGAME)
	{
		if (!s_hasFixedExceptionHandlerChain)
		{
			EmuFixExceptionHandler();
			s_hasFixedExceptionHandlerChain = true;
		}
	}
	else if (s_hasFixedExceptionHandlerChain)
	{
		// We'll need to fix it again when we're back in game
		s_hasFixedExceptionHandlerChain = false;
	}
#endif // EMU_FIX_EXCEPTION_HANDLER_ENABLED
}

static void EmuExtensions_UpdateImGui()
{
}

} // namespace mq
#endif // IS_EMU_CLIENT
