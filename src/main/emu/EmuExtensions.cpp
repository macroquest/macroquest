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

	AddSettingsPanel("Emu Extensions", EmuExtensions_SettingsPanel);
}

static void EmuExtensions_Shutdown()
{
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
}

static void EmuExtensions_UpdateImGui()
{
}

} // namespace mq
#endif // IS_EMU_CLIENT
