/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
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

#include <cstdint>
#include <chrono>

using namespace std::chrono_literals;

namespace mq {

extern float gCurrentFPS;
extern float gCurrentCPU;

#pragma region analysis

class CpuUsage
{
	ULARGE_INTEGER lastCPU, lastSysCPU, lastUserCPU;
	int numProcessors;
	HANDLE self;

public:
	CpuUsage()
	{
		SYSTEM_INFO sysInfo;
		FILETIME ftime, fsys, fuser;

		GetSystemInfo(&sysInfo);
		numProcessors = sysInfo.dwNumberOfProcessors;

		GetSystemTimeAsFileTime(&ftime);
		memcpy(&lastCPU, &ftime, sizeof(FILETIME));

		self = GetCurrentProcess();
		GetProcessTimes(self, &ftime, &ftime, &fsys, &fuser);
		memcpy(&lastSysCPU, &fsys, sizeof(FILETIME));
		memcpy(&lastUserCPU, &fuser, sizeof(FILETIME));
	}

	double GetCurrentValue()
	{
		FILETIME ftime, fsys, fuser;
		ULARGE_INTEGER now, sys, user;
		double percent;

		GetSystemTimeAsFileTime(&ftime);
		memcpy(&now, &ftime, sizeof(FILETIME));

		GetProcessTimes(self, &ftime, &ftime, &fsys, &fuser);
		memcpy(&sys, &fsys, sizeof(FILETIME));
		memcpy(&user, &fuser, sizeof(FILETIME));
		percent = (double)(sys.QuadPart - lastSysCPU.QuadPart) + (user.QuadPart - lastUserCPU.QuadPart);
		percent /= (now.QuadPart - lastCPU.QuadPart);
		percent /= numProcessors;
		lastCPU = now;
		lastUserCPU = user;
		lastSysCPU = sys;

		return percent * 100;
	}
};

class FrameCounter
{
public:
	static const int SampleCount = 32;

	FrameCounter()
	{
		memset(m_samples, 0, sizeof(m_samples));
	}

	void AddSample(int64_t sample)
	{
		m_sum -= m_samples[m_index];
		m_sum += sample;
		m_samples[m_index++] = sample;

		if (m_index == SampleCount)
			m_index = 0;
	}

	void AddRelativeSample(int64_t relativeSample)
	{
		if (m_isFirstSample)
		{
			m_isFirstSample = false;
			m_prevSample = relativeSample;
			return;
		}

		int64_t sample = relativeSample - m_prevSample;
		m_prevSample = relativeSample;

		AddSample(sample);
	}

	double Average() const { return m_sum == 0 ? 0.0 : ((double)m_sum / SampleCount); }

	void Clear()
	{
		m_sum = 0;
		m_index = 0;
		m_prevSample = 0;
		m_isFirstSample = true;
	}

private:
	int64_t m_samples[SampleCount];
	int64_t m_sum = 0;
	int64_t m_prevSample = 0;
	int m_index = 0;
	bool m_isFirstSample = true;
};

#pragma endregion

#pragma region globals
// Global bool controlling this whole feature.
bool gbFrameLimiterEnabled = false;
float gCurrentFPS = 0.0f;
float gCurrentCPU = 0.0f;

static DWORD bmRealRenderWorld = 0;
static DWORD bmThrottleTime = 0;
#pragma endregion

#pragma region throttler

class FrameThrottler
{
public:
	FrameThrottler() = default;

	void SetMinDuration(std::chrono::microseconds duration)
	{
		m_minDuration = duration;
		m_previous = std::chrono::steady_clock::now();
	}

	std::chrono::microseconds GetMinDuration() const
	{
		return m_minDuration;
	}

	void Prepare()
	{
		m_previous = std::chrono::steady_clock::now() - m_minDuration;
	}

	std::chrono::microseconds ThrottleFrame(std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now())
	{
		auto delta = std::chrono::duration_cast<std::chrono::microseconds>(now - m_previous);

		if (delta < 0us)
		{
			m_previous = now;
			return 0us;
		}
		else if (delta < m_minDuration)
		{
			return std::chrono::duration_cast<std::chrono::microseconds>(m_minDuration - delta);
		}

		m_previous += m_minDuration;
		return 0us;
	}

private:
	std::chrono::steady_clock::time_point m_previous;
	std::chrono::microseconds m_minDuration;
};

#pragma endregion

#pragma region Detours

static bool RenderScene_Hook();
static bool UseEQRenderer();
static bool UpdateDisplay_Hook();
static bool ShouldDoRealRenderWorld();
static bool ShouldDoThrottle();

class CXWndManagerHook
{
public:
	// This hooks the UI draw function. Completely disable the UI draw if we have limiting enabled because
	// we are going to want to tie the UI draw to the render scene, otherwise it will potentially draw out
	// of order since the DrawWindows call happens outside of and before the RealRender_World call
	void DrawWindows_Trampoline();
	void DrawWindows_Detour()
	{
		if (UseEQRenderer())
		{
			// this is a pass through if we have the frame limiter off
			DrawWindows_Trampoline();
		}
	}
};
DETOUR_TRAMPOLINE_EMPTY(void CXWndManagerHook::DrawWindows_Trampoline());

class CRenderHook
{
public:
	// This hooks the main render function. We can use it to toggle rendering of the main game scene.
	// If we disable rendering, we should still draw imgui.
	void RenderScene_Trampoline();
	void RenderScene_Detour()
	{
		if (RenderScene_Hook())
		{
			MQScopedBenchmark bm(bmRenderScene);
			// call the UI DrawWindows function here to explicitly tie the framerates, but only do it if we have the limiter enabled
			if (!UseEQRenderer() && pWndMgr) pWndMgr.get_as<CXWndManagerHook>()->DrawWindows_Trampoline();
			RenderScene_Trampoline();
		}
	}

	// This hooks the update display function, which is called during 2D surface render outside of
	// RenderScene. If RenderScene didn't call BeginScene, this will, and since our simulation update
	// is explicitly different than the draw update and the simulation update calls this at various
	// points, we need to explicitly throttle this as well if we have enabled the frame limiter
	void UpdateDisplay_Trampoline();
	void UpdateDisplay_Detour()
	{
		if (UpdateDisplay_Hook())
		{
			UpdateDisplay_Trampoline();
		}
	}
};
DETOUR_TRAMPOLINE_EMPTY(void CRenderHook::RenderScene_Trampoline());
DETOUR_TRAMPOLINE_EMPTY(void CRenderHook::UpdateDisplay_Trampoline());

class CDisplayHook
{
public:
	// This hooks the main world update function. We will never skip running it, but we change
	// when it is called based on our frame limiting scheme.
	void RealRender_World_Trampoline();
	void RealRender_World_Detour()
	{
		// This will only be true if we the frame limiter is disabled, but there are side effects to do the simulation step later
		if (ShouldDoRealRenderWorld())
		{
			MQScopedBenchmark bm(bmRealRenderWorld);
			RealRender_World_Trampoline();
		}
	}
};
DETOUR_TRAMPOLINE_EMPTY(void CDisplayHook::RealRender_World_Trampoline());

DETOUR_TRAMPOLINE_EMPTY(static void Throttler_Trampoline());
static void Throttler_Detour()
{
	if (ShouldDoThrottle())
		Throttler_Trampoline();
}

#pragma endregion

#pragma region limiter

class FrameLimiter
{
	bool m_lastInForeground = true;
	bool m_resetOnNextPulse = false;
	FrameCounter m_renderFPS;
	FrameCounter m_gameFPS;
	CpuUsage m_cpuUsageCalc;
	FrameCounter m_cpuUsage;
	FrameThrottler m_frameThrottler;          // throttler for framerate
	std::chrono::steady_clock::time_point m_startTime;
	std::chrono::steady_clock::time_point m_prevFrame;
	std::chrono::microseconds m_gameLoopDuration = 0us;
	uint32_t m_lastGameState = 0;
	uint32_t m_lastScreenMode = 0;
	bool m_needWaitRender = true;     // wait for RenderReal_World function to be called
	bool m_didTryRender = false;      // real render function was called
	bool m_doRender = false;          // if set to false, we won't render (per frame).

	// Settings
	bool m_renderInBackground = false;
	bool m_renderInForeground = true;
	bool m_tieImGuiToSimulation = false;
	bool m_clearScreen = false;
	float m_backgroundFPS = 1;
	float m_foregroundFPS = 60;
	float m_minSimulationFPS = 30;

public:
	FrameLimiter()
	{
		UpdateThrottler();

		m_startTime = std::chrono::steady_clock::now();
		m_prevFrame = m_startTime;
	}

	//
	// Main loop looks something like this pseudocode:
	//
	// while (true)
	// {
	//     DrawWindows()
	//     RealRender_World()
	//         // .. game state update
	//         RenderScene()
	//
	//     ThrottleFrameRate();
	// }
	//
	// this implementation moves RealRender_World into ThrottleFrameRate
	// where we can determine how long to wait in order to manage both the
	// render rate and the game update rate.
	//
	// The framerate will be set such that we maintain a minimum of m_minSimulationFPS
	// for the game simulation rate. If the render rate is set below that, then
	// we will skip frames while maintaining a m_minSimulationFPS game simulation.

	bool IsEnabled() const { return gbFrameLimiterEnabled; }

	bool DoRealRenderWorld()
	{
		if (!IsEnabled())
			return true;

		// The render function was called, don't need to wait anymore.
		m_needWaitRender = false;
		m_didTryRender = true;

		// If frame limiting is enabled, we always render from the throttle function as
		// it gives is better control over the render rate.
		return false;
	}

	bool DoThrottleFrameRate()
	{
		// If we didn't get a call to DoRealRenderWorld, then we don't do anything. This is because sometimes
		// the game won't call it right after starting up the engine.
		if (!IsEnabled() || m_needWaitRender)
		{
			RecordSimulationSample();
			return true;
		}

		// Decide if we should render the game.
		bool doRender = IsRendering();

		// Make sure we're calling throttle frame each time to update the time accounting
		auto frameRemaining = m_frameThrottler.ThrottleFrame();

		if (doRender)
		{
			doRender = frameRemaining == std::chrono::microseconds(0);
		}

		m_doRender = doRender;

		// always perform the real world update, the limiting here happens in the sleep later in this function
		{
			// Measure how long it takes to do a realrender
			MQScopedBenchmark bm(bmRealRenderWorld);
			RecordSimulationSample();

			pDisplay.get_as<CDisplayHook>()->RealRender_World_Trampoline();
		}

		MQScopedBenchmark bm(bmThrottleTime);
		//auto gameRemaining = std::chrono::duration_cast<std::chrono::microseconds>(
		//	m_prevFrame + m_gameThrottler.GetMinDuration() - std::chrono::steady_clock::now());
		//DebugSpewAlways("Sleep for: %d -- gameRemaining: %d -- frameRemaining: %d", (int)waitTime.count(),
		//	(int)gameRemaining.count(), (int)frameRemaining.count());
		//std::this_thread::sleep_for(waitTime);
		std::this_thread::sleep_until(m_prevFrame + m_gameLoopDuration);
		m_prevFrame += m_gameLoopDuration;

		return false;
	}

	// this function performs the actual graphics render. If we don't want to do it then
	// return true.
	bool DoRenderSceneHook()
	{
		bool doRender = !IsEnabled() || m_doRender;

		if (doRender)
		{
			RecordRenderSample();
		}
		else if (m_tieImGuiToSimulation)
		{
			RenderImGuiScene();
		}

		return doRender;
	}

	// this function performs the UI render. This is tied directly to the scene render, they should always match
	bool DoUpdateDisplayHook()
	{
		return !IsEnabled() || m_doRender;
	}

	void OnPulse()
	{
		m_needWaitRender = mq::test_and_set(m_lastGameState, gGameState);
		bool updateForeground = mq::test_and_set(m_lastInForeground, gbInForeground || IsImGuiForeground());

		m_cpuUsage.AddSample(static_cast<int64_t>(m_cpuUsageCalc.GetCurrentValue() * 1000));

		gCurrentFPS = static_cast<float>(1000000 / m_renderFPS.Average());
		gCurrentCPU = static_cast<float>(m_cpuUsage.Average() / 1000.f);

		if (m_resetOnNextPulse)
		{
			m_resetOnNextPulse = false;

			if (gpD3D9Device)
			{
				IDirect3DSwapChain9* pSwapChain = nullptr;
				if (SUCCEEDED(gpD3D9Device->GetSwapChain(0, &pSwapChain)) && pSwapChain)
				{
					D3DPRESENT_PARAMETERS params;
					pSwapChain->GetPresentParameters(&params);
					pSwapChain->Release();

					gpD3D9Device->Reset(&params);
				}
			}
		}

		// beyond this point we only handle frame limiting active.
		if (!gbFrameLimiterEnabled)
			return;

		if (updateForeground)
		{
			UpdateForegroundState();
		}
	}

	void UpdateForegroundState()
	{
		UpdateThrottler();

		m_frameThrottler.Prepare();
		m_prevFrame = std::chrono::steady_clock::now() - m_gameLoopDuration;

		RenderImGuiScene();
	}

	void UpdateThrottler()
	{
		float desiredRenderRate = m_lastInForeground ? m_foregroundFPS : m_backgroundFPS;
		m_frameThrottler.SetMinDuration(std::chrono::microseconds(static_cast<int64_t>(1000000 / desiredRenderRate)));

		// Cap the main loop at a minimum of m_minSimulationFPS.
		float desiredGameRate = std::max(m_minSimulationFPS, desiredRenderRate);
		m_gameLoopDuration = std::chrono::microseconds(static_cast<int64_t>(1000000 / desiredGameRate));
	}

	void UpdateSettingsPanel()
	{
		ImGui::Text("Status: "); ImGui::SameLine(0, 0);
		if (m_lastInForeground)
			ImGui::TextColored(ImColor(0, 255, 0), "Foreground");
		else
			ImGui::TextColored(ImColor(255, 0, 0), "Background");

		ImGui::Text("CPU Usage: %.2f%%", m_cpuUsage.Average() / 1000.f);
		ImGui::Text("Render FPS: %.2f", (!IsEnabled() || IsRendering()) ? 1000000 / m_renderFPS.Average() : 0.f);
		ImGui::Text("Simulation FPS: %.2f", 1000000 / m_gameFPS.Average());

		ImGui::Separator();
		if (ImGui::Checkbox("Enable frame limiting", &gbFrameLimiterEnabled))
			UpdateThrottler();

		ImGui::Indent();
		// Background options
		ImGui::Text("When in the "); ImGui::SameLine(0, 0); ImGui::TextColored(ImColor(255, 0, 0), "background"); ImGui::SameLine(0, 0); ImGui::Text(":");
		ImGui::PushID("Background"); ImGui::Indent();
		ImGui::Checkbox("Draw game scene", &m_renderInBackground);
		if (ImGui::SliderFloat("Target FPS", &m_backgroundFPS, 0.001f, 120.0f))
			UpdateThrottler();
		ImGui::Unindent(); ImGui::PopID();

		ImGui::Spacing();

		// Foreground options
		ImGui::Text("When in the "); ImGui::SameLine(0, 0); ImGui::TextColored(ImColor(0, 255, 0), "foreground"); ImGui::SameLine(0, 0); ImGui::Text(":");
		ImGui::PushID("Foreground"); ImGui::Indent();
		if (ImGui::Checkbox("Draw game scene", &m_renderInForeground) && !m_renderInForeground)
			mq::test_and_set(m_tieImGuiToSimulation, true);
		if (ImGui::SliderFloat("Target FPS", &m_foregroundFPS, 5.0f, 120.0f))
			UpdateThrottler();
		ImGui::Unindent(); ImGui::PopID();

		ImGui::Spacing();

		ImGui::Text("Minimum Universal Simulation Rate:");
		if (ImGui::SliderFloat("Min FPS", &m_minSimulationFPS, 5.0f, 120.0f))
			UpdateThrottler();

		ImGui::Spacing();

		ImGui::Checkbox("Clear screen when not rendering", &m_clearScreen);
		if (ImGui::Checkbox("Render ImGui at simulation rate", &m_tieImGuiToSimulation) && !m_renderInForeground)
			m_tieImGuiToSimulation = true; // force this to true if we aren't rendering in the foreground

		ImGui::Unindent();

		ImGui::Separator();

		if (ImGui::Button("Force Reset"))
		{
			m_resetOnNextPulse = true;
		}
	}

private:
	bool IsRendering()
	{
		return m_lastInForeground ? m_renderInForeground : m_renderInBackground;
	}

	void RecordRenderSample()
	{
		m_renderFPS.AddRelativeSample(
			std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - m_startTime).count());
	}

	void RecordSimulationSample()
	{
		m_gameFPS.AddRelativeSample(
			std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - m_startTime).count());
	}

	void RenderImGuiScene()
	{
		// This is pretty simple. We just begin/end scene with error checking as appropriate.
		if (!gpD3D9Device)
			return; // ???

		HRESULT hResult = gpD3D9Device->TestCooperativeLevel();
		if (FAILED(hResult))
		{
			return; // Nope!
		}

		if (m_clearScreen && !IsRendering())
		{
			gpD3D9Device->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
		}

		hResult = gpD3D9Device->BeginScene();
		if (FAILED(hResult))
		{
			return; // Goodbye!
		}

		// Draw Hud
		gpD3D9Device->EndScene();
		gpD3D9Device->Present(nullptr, nullptr, nullptr, nullptr);
	}
};
static FrameLimiter s_frameLimiter;

#pragma endregion

// Our hook for the main render function. Returns true to call the trampoline and render.
static bool RenderScene_Hook()
{
	return s_frameLimiter.DoRenderSceneHook();
}

static bool UseEQRenderer()
{
	return !s_frameLimiter.IsEnabled();
}

static bool UpdateDisplay_Hook()
{
	return s_frameLimiter.DoUpdateDisplayHook();
}

static bool ShouldDoRealRenderWorld()
{
	return s_frameLimiter.DoRealRenderWorld();
}

static bool ShouldDoThrottle()
{
	return s_frameLimiter.DoThrottleFrameRate();
}

static void FrameLimiterSettings()
{
	s_frameLimiter.UpdateSettingsPanel();
}

static void InitializeFrameLimiter()
{
	AddSettingsPanel("FPS Limiter", FrameLimiterSettings);

	bmRenderScene = AddMQ2Benchmark("Render_Scene");
	bmRealRenderWorld = AddMQ2Benchmark("Render_Simulation");
	bmThrottleTime = AddMQ2Benchmark("Render_Throttle");

	// Hook UI render function
	EzDetour(CXWndManager__DrawWindows, &CXWndManagerHook::DrawWindows_Detour, &CXWndManagerHook::DrawWindows_Trampoline);

	// Hook main render function
	EzDetour(CRender__RenderScene, &CRenderHook::RenderScene_Detour, &CRenderHook::RenderScene_Trampoline);

	// Hook update function (will begin scene if render isn't called)
	EzDetour(CRender__UpdateDisplay, &CRenderHook::UpdateDisplay_Detour, &CRenderHook::UpdateDisplay_Trampoline);

	// Hook the main loop throttle function
	EzDetour(__ThrottleFrameRate, &Throttler_Detour, &Throttler_Trampoline);

	// Hook CDisplay::RealRender_World to control render loop
	EzDetour(CDisplay__RealRender_World, &CDisplayHook::RealRender_World_Detour, &CDisplayHook::RealRender_World_Trampoline);
}

static void ShutdownFrameLimiter()
{
	RemoveSettingsPanel("FPS Limiter");

	RemoveDetour(CXWndManager__DrawWindows);
	RemoveDetour(CRender__RenderScene);
	RemoveDetour(CRender__UpdateDisplay);
	RemoveDetour(__ThrottleFrameRate);
	RemoveDetour(CDisplay__RealRender_World);

	RemoveMQ2Benchmark(bmRenderScene);
	RemoveMQ2Benchmark(bmRealRenderWorld);
	RemoveMQ2Benchmark(bmThrottleTime);
}

static void PulseFrameLimiter()
{
	s_frameLimiter.OnPulse();
}

static MQModule s_FrameLimiterModule = {
	"FrameLimiter",                // Name
	false,                         // CanUnload
	InitializeFrameLimiter,        // Initialize
	ShutdownFrameLimiter,          // Shutdown
	PulseFrameLimiter,             // Pulse
	nullptr,                       // SetGameState
	nullptr,                       // UpdateImGui
	nullptr,                       // Zoned
	nullptr                        // WriteChatColor
};
DECLARE_MODULE_INITIALIZER(s_FrameLimiterModule);

}
