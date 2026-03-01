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

#include "ImGuiBackend.h"
#include "ImGuiManager.h"
#include "imgui/ImGuiUtils.h"
#include "MQ2DeveloperTools.h"

#include "mq/api/RenderDoc.h"
#include "mq/utils/Args.h"

#include <cstdint>
#include <chrono>
#include <utility>

using namespace std::chrono_literals;

namespace mq {

extern float gCurrentFPS;
extern float gCurrentCPU;

using MQ2Args = Args<&WriteChatf>;
using MQ2HelpArgument = HelpArgument;

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
static bool AreParticlesDisabled();
static bool IsLimiterEnabled();
static bool IsTieUiToSimulation();
static bool UpdateDisplay_Hook();
static bool ShouldDoRealRenderWorld();
bool DoThrottleFrameRate();

class CXWndManagerHook
{
public:
	// This hooks the UI draw function. Completely disable the UI draw if we have limiting enabled because
	// we are going to want to tie the UI draw to the render scene, otherwise it will potentially draw out
	// of order since the DrawWindows call happens outside of and before the RealRender_World call
	DETOUR_TRAMPOLINE_DEF(void, DrawWindows_Trampoline, ())
	void DrawWindows_Detour()
	{
		static bool lastHide = false;

		if (gDrawWindowFrameSkipCount >= 0)
		{
			--gDrawWindowFrameSkipCount;
		}

		if (pCursorAttachment)
		{
			if (gbHideCursorAttachment)
			{
				CXPoint pos = pCursorAttachment->Location.TopLeft();

				if (pos.x < 90000)
				{
					pCursorAttachment->Move(CXPoint(pos.x + 90000, pos.y + 90000));
				}
			}
			else if (lastHide && !gbHideCursorAttachment)
			{
				if (pCursorAttachment->Location.left > 80000)
				{
					CXPoint pos = pCursorAttachment->Location.TopLeft();

					pCursorAttachment->Move(CXPoint(pos.x - 90000, pos.y - 90000));
				}
			}

			lastHide = gbHideCursorAttachment;
		}

		if (gDrawWindowFrameSkipCount >= 0)
		{
			DrawWindows_Trampoline();
			return;
		}

		if (!IsLimiterEnabled())
		{
			// this is a pass through if we have the frame limiter off
			DrawWindows_Trampoline();
		}
	}

	static void CallDrawWindows()
	{
		if (gDrawWindowFrameSkipCount >= 0)
		{
			return;
		}

		if (pWndMgr && (pScreenMode == nullptr || *pScreenMode != 3))
		{
			pWndMgr.get_as<CXWndManagerHook>()->DrawWindows_Trampoline();
		}
	}
};

class CRenderHook
{
public:
	// This hooks the main render function. We can use it to toggle rendering of the main game scene.
	// If we disable rendering, we should still draw imgui.
	DETOUR_TRAMPOLINE_DEF(void, RenderScene_Trampoline, ())
	void RenderScene_Detour()
	{
		if (RenderScene_Hook())
		{
			MQScopedBenchmark bm(bmRenderScene);

			// call the UI DrawWindows function here to explicitly tie the framerates, but only do it if we have the limiter enabled
			if (IsLimiterEnabled())
				CXWndManagerHook::CallDrawWindows();

			RenderScene_Trampoline();
		}
		else
		{
			if (g_bRenderSceneCalled)
				*g_bRenderSceneCalled = TRUE;

			if (IsTieUiToSimulation())
			{
				RenderBlind_Trampoline();
			}
		}
	}

	// Same logic as above, but this is for when the player is blind.
	DETOUR_TRAMPOLINE_DEF(void, RenderBlind_Trampoline, ())
	void RenderBlind_Detour()
	{
		if (RenderScene_Hook())
		{
			MQScopedBenchmark bm(bmRenderScene);

			// call the UI DrawWindows function here to explicitly tie the framerates, but only do it if we have the limiter enabled
			if (IsLimiterEnabled())
				CXWndManagerHook::CallDrawWindows();

			RenderBlind_Trampoline();
		}
	}

	// This hooks the update display function, which is called during 2D surface render outside of
	// RenderScene. If RenderScene didn't call BeginScene, this will, and since our simulation update
	// is explicitly different than the draw update and the simulation update calls this at various
	// points, we need to explicitly throttle this as well if we have enabled the frame limiter
	DETOUR_TRAMPOLINE_DEF(void, UpdateDisplay_Trampoline, ())
	void UpdateDisplay_Detour()
	{
		if (UpdateDisplay_Hook())
		{
			UpdateDisplay_Trampoline();
		}
		else
		{
			if (pSpellBookWnd && pSpellBookWnd->IsVisible())
			{
				// this is a small kludge to allow spell memming and scribing to work while not rendering
				bool test;
				auto GetGaugeValueFromEQ = reinterpret_cast<int (*)(int, CXStr*, bool*, unsigned long*)>(__GetGaugeValueFromEQ);
				GetGaugeValueFromEQ(9, nullptr, &test, nullptr); // spell mem gauge
				GetGaugeValueFromEQ(10, nullptr, &test, nullptr); // spell scribe gauge
			}
		}
	}
};

class CParticleSystemHook
{
public:
	DETOUR_TRAMPOLINE_DEF(int, CreateSpellEmitter_Trampoline, (int, unsigned long, int, float, float, CVector3 const&, CActor*, CBoneInterface*, CParticlePointInterface*, void**, float, bool, bool, int))
	int CreateSpellEmitter_Detour(
		int index,
		unsigned long a,
		int b,
		float particleDensity,
		float particleOpacity,
		CVector3 const& pos,
		CActor* actor,
		CBoneInterface* bone,
		CParticlePointInterface* particlePoint,
		void** emitter, // CEmitterInterface**
		float k,
		bool l,
		bool m,
		int previewMode) // enum EObjectPreviewMode
	{
		if (AreParticlesDisabled())
			return 0;

		return CreateSpellEmitter_Trampoline(
			index,
			a,
			b,
			particleDensity,
			particleOpacity,
			pos,
			actor,
			bone,
			particlePoint,
			emitter,
			k,
			l,
			m,
			previewMode);
	}
};

class CDisplayHook
{
public:
	// This hooks the main world update function. We will never skip running it, but we change
	// when it is called based on our frame limiting scheme.
	DETOUR_TRAMPOLINE_DEF(void, RealRender_World_Trampoline, ())
	void RealRender_World_Detour()
	{
		// This will only be true if we the frame limiter is disabled, but there are side effects to do the simulation step later
		if (ShouldDoRealRenderWorld())
		{
			DoRealRender_World();
		}
	}

	void DoRealRender_World()
	{
		RenderDoc_ScopedEvent e(MQColor(170, 255, 255), L"RealRender_World");

		{
			MQScopedBenchmark bm(bmRealRenderWorld);

			RealRender_World_Trampoline();
		}
	}
};

#if defined(_M_AMD64)
// Defined in AssemblyFunctions.asm, need the forward declare
void Throttler_Detour(uint32_t);
void(*Throttler_Trampoline)(uint32_t);
#else
DETOUR_TRAMPOLINE_DEF(void, Throttler_Trampoline, ());
void Throttler_Detour()
{
	// If DoThrottleFrameRate returns false, then it is disabled and we
	// want to just call the original code. If it returns true then we
	// are engaged with the frame limiter and we want to skip past the
	// built-in throttling.
	if (!DoThrottleFrameRate())
		Throttler_Trampoline();
}
#endif

#pragma endregion

#pragma region limiter

class FrameLimiter
{
	bool m_lastInForeground = false;
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
	bool m_pauseForZone = true;
	int m_updateDisplayCount = 0;
	std::string m_characterIni;

	// Settings
	bool m_enabled = false;
	bool m_enabledInForeground = false;
	bool m_saveByChar = false;
	bool m_renderInBackground = true;
	bool m_renderInForeground = true;
	bool m_tieImGuiToSimulation = false;
	bool m_tieUiToSimulation = false;
	bool m_clearScreen = false;
	float m_backgroundFPS = 1.0f;
	float m_foregroundFPS = 60.0f;
	float m_minSimulationFPS = 30.0f;

public:
	FrameLimiter() :
		m_startTime(std::chrono::steady_clock::now()),
		m_prevFrame(m_startTime)
	{
		ReadSettings();
	}

	void ReadSettings()
	{
		m_enabled = GetSetting<bool, LimiterSetting::Enable>();
		m_enabledInForeground = GetSetting<bool, LimiterSetting::ForegroundEnable>();
		m_saveByChar = GetSetting<bool, LimiterSetting::SaveByChar>();
		m_renderInBackground = GetSetting<bool, LimiterSetting::RenderInBackground>();
		m_tieImGuiToSimulation = GetSetting<bool, LimiterSetting::TieImGuiToSimulation>();
		m_tieUiToSimulation = GetSetting<bool, LimiterSetting::TieUiToSimulation>();
		m_clearScreen = GetSetting<bool, LimiterSetting::ClearScreen>();
		m_backgroundFPS = GetSetting<float, LimiterSetting::BackgroundFPS>();
		m_foregroundFPS = GetSetting<float, LimiterSetting::ForegroundFPS>();
		m_minSimulationFPS = GetSetting<float, LimiterSetting::MinSimulationFPS>();

		UpdateThrottler();
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

	inline bool IsSavedByChar() const { return m_saveByChar; }

	inline bool IsSupportedGameState() const {
		return !m_pauseForZone && gGameState == GAMESTATE_INGAME;
	}

	inline bool IsForeground() const { return m_lastInForeground; }
	inline bool IsBackground() const { return !IsForeground(); }

	float GetCPUUsage() const { return static_cast<float>(m_cpuUsage.Average()) / 1000.f; }
	float GetRecordedRenderFPS() const { return (!IsEnabled() || IsRenderingEnabled()) ? 1000000 / static_cast<float>(m_renderFPS.Average()) : 0.f; }
	float GetRecordedSimulationFPS() const { return 1000000 / static_cast<float>(m_gameFPS.Average()); }

	float GetTargetForegroundFPS() const { return m_renderInForeground ? m_foregroundFPS : 0.f; }
	float GetTargetBackgroundFPS() const { return m_renderInBackground ? m_backgroundFPS : 0.f; }

	inline bool IsEnabled() const {
		return IsSupportedGameState() && (IsForeground() ? m_enabledInForeground : m_enabled);
	}
	inline bool IsRenderingEnabled() const {
		return IsForeground()
			? (m_renderInForeground && m_foregroundFPS > 0.f)
			: (m_renderInBackground && m_backgroundFPS > 0.f);
	}

	float GetMinimumSimulationFPS() const { return m_minSimulationFPS; }

	bool GetTieImGuiToSimulation() const { return m_tieImGuiToSimulation && IsBackground(); }
	bool GetTieUiToSimulation() const { return m_tieUiToSimulation && GetTieImGuiToSimulation(); }

	bool GetClearScreen() const { return m_clearScreen; }

	bool DoRealRenderWorld()
	{
		if (!IsEnabled())
		{
			return true;
		}

		// The render function was called, don't need to wait anymore.
		m_needWaitRender = false;
		m_didTryRender = true;

		// If frame limiting is enabled, we always render from the throttle function as
		// it gives is better control over the render rate.
		return false;
	}

	bool DoThrottleFrameRate()
	{
		if (!IsEnabled())
			return false;

		// If we didn't get a call to DoRealRenderWorld, then we don't do anything. This is because sometimes
		// the game won't call it right after starting up the engine.
		if (m_needWaitRender)
		{
			RecordSimulationSample();
			return true;
		}

		// Decide if we should render the game.
		bool doRender = IsRenderingEnabled();

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
			RecordSimulationSample();

			pDisplay.get_as<CDisplayHook>()->DoRealRender_World();

			if (GetTieUiToSimulation())
				CXWndManagerHook::CallDrawWindows();
		}

		MQScopedBenchmark bm(bmThrottleTime);
		//auto gameRemaining = std::chrono::duration_cast<std::chrono::microseconds>(
		//	m_prevFrame + m_gameThrottler.GetMinDuration() - std::chrono::steady_clock::now());
		//DebugSpewAlways("Sleep for: %d -- gameRemaining: %d -- frameRemaining: %d", (int)waitTime.count(),
		//	(int)gameRemaining.count(), (int)frameRemaining.count());
		//std::this_thread::sleep_for(waitTime);
		std::this_thread::sleep_until(m_prevFrame + m_gameLoopDuration);
		m_prevFrame += m_gameLoopDuration;

		return true;
	}

	// this function performs the actual graphics render. If we don't want to do it then
	// return true.
	bool DoRenderSceneHook()
	{
		bool doRender = !IsEnabled() || m_doRender;
		m_pauseForZone = false;

		if (doRender)
		{
			RecordRenderSample();
		}
		else
		{
			if (GetTieImGuiToSimulation())
			{
				RenderImGuiScene();
			}
		}

		return doRender;
	}

	bool DoUpdateDisplayHook()
	{
		++m_updateDisplayCount;

		return !IsEnabled() || m_doRender || GetTieUiToSimulation()
			|| gGameState != GAMESTATE_INGAME         // always call UpdateDisplay when we're not in game
			|| m_updateDisplayCount >= 2;             // if this is the 2nd+ call this frame. This happens when logging out.
	}

	void PauseForZone()
	{
		m_pauseForZone = true;
	}

	void OnPulse()
	{
		m_needWaitRender = mq::test_and_set(m_lastGameState, gGameState);
		m_updateDisplayCount = 0;

		m_cpuUsage.AddSample(static_cast<int64_t>(m_cpuUsageCalc.GetCurrentValue() * 1000));

		gCurrentFPS = static_cast<float>(1000000 / m_renderFPS.Average());
		gCurrentCPU = static_cast<float>(m_cpuUsage.Average() / 1000.f);

#if HAS_DIRECTX_9
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
#endif

		bool updateForeground = mq::test_and_set(m_lastInForeground, gbInForeground || ImGui_IsImGuiForeground());

		if (updateForeground)
		{
			UpdateForegroundState();

			// beyond this point we only handle frame limiting active.
			if (!IsEnabled())
				return;

			RenderImGuiScene();
		}
	}

	void UpdateForegroundState()
	{
		UpdateThrottler();

		m_frameThrottler.Prepare();
		m_prevFrame = std::chrono::steady_clock::now() - m_gameLoopDuration;
	}

	void UpdateThrottler()
	{
		float desiredRenderRate = m_lastInForeground ? m_foregroundFPS : m_backgroundFPS;
		if (desiredRenderRate == 0.f) desiredRenderRate = 0.001f; // prevent division by zero if someone forces the render rate
		m_frameThrottler.SetMinDuration(std::chrono::microseconds(static_cast<int64_t>(1000000 / desiredRenderRate)));

		// Cap the main loop at a minimum of m_minSimulationFPS.
		float desiredGameRate = std::max(m_minSimulationFPS, desiredRenderRate);
		m_gameLoopDuration = std::chrono::microseconds(static_cast<int64_t>(1000000 / desiredGameRate));
	}

	void UpdateSettingsPanel()
	{
		ImGui::Text("Status: "); ImGui::SameLine(0, 0);

		if (gbInForeground || ImGui_IsImGuiForeground())
			ImGui::TextColored(ImColor(0, 255, 0), "Foreground");
		else
			ImGui::TextColored(ImColor(255, 0, 0), "Background");

		ImGui::Text("Frame limiter is: "); ImGui::SameLine(0, 0);
		if (IsEnabled())
			ImGui::TextColored(ImColor(0, 255, 0), "Active");
		else
			ImGui::TextColored(ImColor(255, 255, 0), "Inactive");

		ImGui::Text("CPU Usage: %.2f%%", GetCPUUsage());
		ImGui::Columns(2, nullptr, false);
		ImGui::Text("Render FPS: %.2f", GetRecordedRenderFPS());
		ImGui::NextColumn();

		// When not enabled, there is no sim fps, so just display recorded fps
		if (IsEnabled())
			ImGui::Text("Simulation FPS: %.2f", GetRecordedSimulationFPS());
		else
			ImGui::Text("Simulation FPS: %.2f", GetRecordedRenderFPS());
		ImGui::Columns(1);

		ImGui::Separator();
		if (ImGui::Checkbox("Save settings by character", &m_saveByChar))
		{
			WriteSetting<LimiterSetting::SaveByChar>(m_saveByChar);
			// Re-read settings after changing SaveByChar to load the correct character or global settings
			ReadSettings();
		}

		ImGui::NewLine();
		ImGui::Separator();

		//----------------------------------------------------------------------------
		// Background options
		ImGui::PushID("Background");

		if (ImGui::Checkbox("##Background", &m_enabled))
		{
			WriteSetting<LimiterSetting::Enable>(m_enabled);
			UpdateThrottler();
		}
		ImGui::SameLine(0, 4.0f); ImGui::Text("Enable frame limiting when in the "); ImGui::SameLine(0, 0); ImGui::TextColored(ImColor(255, 0, 0), "background");

		{
			ImGui::Indent();

			if (ImGui::Checkbox("Render game scene", &m_renderInBackground))
			{
				WriteSetting<LimiterSetting::RenderInBackground>(m_renderInBackground);
			}

			if (ImGui::SliderFloat("Target FPS", &m_backgroundFPS, 0.001f, 120.0f))
			{
				WriteSetting<LimiterSetting::BackgroundFPS>(m_backgroundFPS);
				UpdateThrottler();
			}

			if (ImGui::Checkbox("Draw ImGui at simulation rate", &m_tieImGuiToSimulation))
			{
				if (!m_tieImGuiToSimulation)
				{
					m_tieUiToSimulation = false;
					WriteSetting<LimiterSetting::TieUiToSimulation>(m_tieUiToSimulation);
				}

				WriteSetting<LimiterSetting::TieImGuiToSimulation>(m_tieImGuiToSimulation);
			}
			ImGui::SameLine(); mq::imgui::HelpMarker(
				"This setting applies when frame limiting is active and the game is in the background.\n"
				"\n"
				"This setting allows for fluid updates to the ImGui while the window is in the background.\n"
				"\n"
				"When this setting is enabled, ImGui will draw at a frame rate equal to the render fps or "
				"the simulation rate, whichever is higher.");

			{
				ImGui::Indent();

				if (ImGui::Checkbox("Draw Game UI at simulation rate", &m_tieUiToSimulation))
				{
					WriteSetting<LimiterSetting::TieUiToSimulation>(m_tieUiToSimulation);
					if (m_tieUiToSimulation)
					{
						m_tieImGuiToSimulation = true;
						WriteSetting<LimiterSetting::TieImGuiToSimulation>(m_tieImGuiToSimulation);
					}
				}
				ImGui::SameLine(); mq::imgui::HelpMarker(
					"This setting applies when frame limiting is active and the game is in the background. This"
					"setting is also dependent on \"Draw ImGui at simulation rate\" being enabled.\n"
					"\n"
					"This setting allows for fluid updates to the Game UI while the window is in the background.\n"
					"\n"
					"When this setting is enabled, the Game UI will draw at a frame rate equal to the render fps or "
					"the simulation rate, whichever is higher.");

				ImGui::Unindent();
			}

			ImGui::Unindent();
		}
		ImGui::PopID();


		ImGui::NewLine();
		ImGui::Separator();

		//----------------------------------------------------------------------------
		// Foreground options
		ImGui::PushID("Foreground");

		if (ImGui::Checkbox("##BForeground", &m_enabledInForeground))
		{
			WriteSetting<LimiterSetting::ForegroundEnable>(m_enabledInForeground);
			UpdateThrottler();
		}
		ImGui::SameLine(0, 4.0f); ImGui::Text("Enable frame limiting when in the "); ImGui::SameLine(0, 0); ImGui::TextColored(ImColor(0, 255, 0), "foreground");
		
		{
			ImGui::Indent();

#if defined(_DEBUG) && 0
			if (ImGui::Checkbox("Draw game scene", &m_renderInForeground))
			{
				WriteSetting<LimiterSetting::RenderInForeground>(m_renderInForeground);
			}
#endif

			if (ImGui::SliderFloat("Target FPS", &m_foregroundFPS, 5.0f, 120.0f))
			{
				WriteSetting<LimiterSetting::ForegroundFPS>(m_foregroundFPS);
				UpdateThrottler();
			}
			ImGui::Unindent(); 
		}

		ImGui::PopID();

		ImGui::NewLine();
		ImGui::Separator();
		if (ImGui::CollapsingHeader("Advanced Options"))
		{
			ImGui::Text("Minimum Simulation Rate:"); ImGui::SameLine();
			mq::imgui::HelpMarker(
				"This setting applies when frame limiting is active.\n"
				"\n"
				"The simulation rate is how often the game state updates. MacroQuest can control "
				"this rate separately from the frame rate, allowing smooth updates even when the "
				"target frame rate is set low.\n"
				"\n"
				"By setting a minimum simulation rate, we can ensure that the game continues processing "
				"updates quickly even when the frame rate is low.\n"
				"\n"
				"A low simulation rate will cause problems with gameplay, such as stuttering or "
				"laggy movement. You generally do not want the simulation rate to drop below "
				"30 updates per second.");

			if (ImGui::SliderFloat("FPS", &m_minSimulationFPS, 5.0f, 120.0f))
			{
				WriteSetting<LimiterSetting::MinSimulationFPS>(m_minSimulationFPS);
				UpdateThrottler();
			}

			if (ImGui::Checkbox("Clear screen when not rendering", &m_clearScreen))
			{
				WriteSetting<LimiterSetting::ClearScreen>(m_clearScreen);
			}
			ImGui::SameLine();
			mq::imgui::HelpMarker(
				"This setting applies when frame limiting is active.\n"
				"\n"
				"Clear the game scene to BLACK when frames are dropped by the frame limiter.\n"
				"\n"
				"NOT RECOMMENDED if you have epilepsy");

#if HAS_DIRECTX_9
			if (ImGui::Button("Reset Device"))
			{
				m_resetOnNextPulse = true;
			}

			ImGui::SameLine(); mq::imgui::HelpMarker(
				"This is meant as a debugging tool. Resetting the device should *not* crash, but "
				"sometimes it does, and that is an indicator that there is a bug that needs to be fixed."
			);
#endif

			ImGui::NewLine();
		}

		ImGui::Separator();

		if (ImGui::Button("Reset Defaults"))
		{
			ResetDefaults();
		}
	}

private:
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

		if (m_clearScreen && !IsRenderingEnabled())
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

	// settings
public:
	enum class LimiterSetting
	{
		Enable,
		ForegroundEnable,
		SaveByChar,
		RenderInBackground,
		RenderInForeground,
		TieImGuiToSimulation,
		TieUiToSimulation,
		ClearScreen,
		BackgroundFPS,
		ForegroundFPS,
		MinSimulationFPS
	};

	template <LimiterSetting Value>
	static constexpr const char* SettingName();
	template <> static constexpr const char* SettingName<LimiterSetting::Enable>() { return "Enable"; }
	template <> static constexpr const char* SettingName<LimiterSetting::ForegroundEnable>() { return "ForegroundEnable"; }
	template <> static constexpr const char* SettingName<LimiterSetting::SaveByChar>() { return "SaveByChar"; }
	template <> static constexpr const char* SettingName<LimiterSetting::RenderInBackground>() { return "RenderInBackground"; }
	template <> static constexpr const char* SettingName<LimiterSetting::RenderInForeground>() { return "RenderInForeground"; }
	template <> static constexpr const char* SettingName<LimiterSetting::TieImGuiToSimulation>() { return "TieImGuiToSimulation"; }
	template <> static constexpr const char* SettingName<LimiterSetting::TieUiToSimulation>() { return "TieUiToSimulation"; }
	template <> static constexpr const char* SettingName<LimiterSetting::ClearScreen>() { return "ClearScreen"; }
	template <> static constexpr const char* SettingName<LimiterSetting::BackgroundFPS>() { return "BackgroundFPS"; }
	template <> static constexpr const char* SettingName<LimiterSetting::ForegroundFPS>() { return "ForegroundFPS"; }
	template <> static constexpr const char* SettingName<LimiterSetting::MinSimulationFPS>() { return "MinSimulationFPS"; }

private:
	template <typename T, LimiterSetting Value>
	static constexpr T GetDefault();
	template <> static constexpr bool GetDefault<bool, LimiterSetting::Enable>() { return false; }
	template <> static constexpr bool GetDefault<bool, LimiterSetting::ForegroundEnable>() { return false; }
	template <> static constexpr bool GetDefault<bool, LimiterSetting::SaveByChar>() { return false; }
	template <> static constexpr bool GetDefault<bool, LimiterSetting::RenderInBackground>() { return true; }
	template <> static constexpr bool GetDefault<bool, LimiterSetting::RenderInForeground>() { return true; }
	template <> static constexpr bool GetDefault<bool, LimiterSetting::TieImGuiToSimulation>() { return false; }
	template <> static constexpr bool GetDefault<bool, LimiterSetting::TieUiToSimulation>() { return false; }
	template <> static constexpr bool GetDefault<bool, LimiterSetting::ClearScreen>() { return false; }
	template <> static constexpr float GetDefault<float, LimiterSetting::BackgroundFPS>() { return 1.f; }
	template <> static constexpr float GetDefault<float, LimiterSetting::ForegroundFPS>() { return 60.f; }
	template <> static constexpr float GetDefault<float, LimiterSetting::MinSimulationFPS>() { return 30.f; }

	std::string& GetINIFileName(LimiterSetting value)
	{
		// SaveByChar should only ever be saved under global settings
		if (value == LimiterSetting::SaveByChar || !IsSavedByChar()
			|| !pLocalPC || m_characterIni.empty())
		{
			return mq::internal_paths::MQini;
		}

		return m_characterIni;
	}

	template <typename T, LimiterSetting Value>
	std::enable_if_t<std::is_same_v<T, bool>, bool> GetSetting()
	{
		return GetPrivateProfileBool("FrameLimiter", SettingName<Value>(), GetDefault<T, Value>(), GetINIFileName(Value));
	}

	template <typename T, LimiterSetting Value>
	std::enable_if_t<std::is_same_v<T, float>, float> GetSetting()
	{
		return GetPrivateProfileFloat("FrameLimiter", SettingName<Value>(), GetDefault<T, Value>(), GetINIFileName(Value));
	}

	template <LimiterSetting Value>
	bool WriteSetting(bool NewValue)
	{
		return WritePrivateProfileBool("FrameLimiter", SettingName<Value>(), NewValue, GetINIFileName(Value));
	}

	template <LimiterSetting Value>
	float WriteSetting(float NewValue)
	{
		return WritePrivateProfileFloat("FrameLimiter", SettingName<Value>(), NewValue, GetINIFileName(Value));
	}

	void ResetDefaults()
	{
		// could alternately delete all keys here, but it's more valuable to be able to write out all defaults
		m_enabled = GetDefault<bool, LimiterSetting::Enable>();
		WriteSetting<LimiterSetting::Enable>(m_enabled);
		m_enabledInForeground = GetDefault<bool, LimiterSetting::ForegroundEnable>();
		WriteSetting<LimiterSetting::ForegroundEnable>(m_enabledInForeground);
		m_renderInBackground = GetDefault<bool, LimiterSetting::RenderInBackground>();
		WriteSetting<LimiterSetting::RenderInBackground>(m_renderInBackground);
		m_renderInForeground = GetDefault<bool, LimiterSetting::RenderInForeground>();
		WriteSetting<LimiterSetting::RenderInForeground>(m_renderInForeground);
		m_tieImGuiToSimulation = GetDefault<bool, LimiterSetting::TieImGuiToSimulation>();
		WriteSetting<LimiterSetting::TieImGuiToSimulation>(m_tieImGuiToSimulation);
		m_tieUiToSimulation = GetDefault<bool, LimiterSetting::TieUiToSimulation>();
		WriteSetting<LimiterSetting::TieUiToSimulation>(m_tieUiToSimulation);
		m_clearScreen = GetDefault<bool, LimiterSetting::ClearScreen>();
		WriteSetting<LimiterSetting::ClearScreen>(m_clearScreen);
		m_backgroundFPS = GetDefault<float, LimiterSetting::BackgroundFPS>();
		WriteSetting<LimiterSetting::BackgroundFPS>(m_backgroundFPS);
		m_foregroundFPS = GetDefault<float, LimiterSetting::ForegroundFPS>();
		WriteSetting<LimiterSetting::ForegroundFPS>(m_foregroundFPS);
		m_minSimulationFPS = GetDefault<float, LimiterSetting::MinSimulationFPS>();
		WriteSetting<LimiterSetting::MinSimulationFPS>(m_minSimulationFPS);
	}

	template <typename T, LimiterSetting Setting>
	T InternalSet(T& Member, T Value)
	{
		Member = Value;
		WriteSetting<Setting>(Member);
		return Member;
	}

public:
	void SetGameState(int GameState)
	{
		// Read settings on INGAME state in order to pickup character specific settings
		if (GameState == GAMESTATE_INGAME)
		{
			m_saveByChar = GetPrivateProfileBool("FrameLimiter", "SaveByChar", false, mq::internal_paths::MQini);
			if (pLocalPC)
				m_characterIni = fmt::format("{}\\{}_{}.ini", gPathConfig, GetServerShortName(), pLocalPC->Name);
			else // shouldn't happen
				m_characterIni.clear();

			ReadSettings();
		}
		else
		{
			m_characterIni.clear();
		}
	}

	template <LimiterSetting Setting>
	bool Set(bool Value);
	template<> bool Set<LimiterSetting::Enable>(bool Value) { return InternalSet<bool, LimiterSetting::Enable>(m_enabled, Value); }
	template<> bool Set<LimiterSetting::ForegroundEnable>(bool Value) { return InternalSet<bool, LimiterSetting::ForegroundEnable>(m_enabledInForeground, Value); }
	template<> bool Set<LimiterSetting::SaveByChar>(bool Value) { return InternalSet<bool, LimiterSetting::SaveByChar>(m_saveByChar, Value); }
	template<> bool Set<LimiterSetting::RenderInBackground>(bool Value) { return InternalSet<bool, LimiterSetting::RenderInBackground>(m_renderInBackground, Value); }
	template<> bool Set<LimiterSetting::ClearScreen>(bool Value) { return InternalSet<bool, LimiterSetting::ClearScreen>(m_clearScreen, Value); }
	template<> bool Set<LimiterSetting::RenderInForeground>(bool Value) { return InternalSet<bool, LimiterSetting::RenderInForeground>(m_renderInForeground, Value); }
	template<> bool Set<LimiterSetting::TieImGuiToSimulation>(bool Value) { return InternalSet<bool, LimiterSetting::TieImGuiToSimulation>(m_tieImGuiToSimulation, Value); }
	template<> bool Set<LimiterSetting::TieUiToSimulation>(bool Value) { return InternalSet<bool, LimiterSetting::TieUiToSimulation>(m_tieUiToSimulation, Value); }

	template <LimiterSetting Setting>
	bool Toggle() { return Set<Setting>(!GetSetting<bool, Setting>()); }

	template <LimiterSetting Setting>
	float Set(float Value);
	template<> float Set<LimiterSetting::BackgroundFPS>(float Value) { return InternalSet<float, LimiterSetting::BackgroundFPS>(m_backgroundFPS, Value); }
	template<> float Set<LimiterSetting::ForegroundFPS>(float Value) { return InternalSet<float, LimiterSetting::ForegroundFPS>(m_foregroundFPS, Value); }
	template<> float Set<LimiterSetting::MinSimulationFPS>(float Value) { return InternalSet<float, LimiterSetting::MinSimulationFPS>(m_minSimulationFPS, Value); }
};
static FrameLimiter s_frameLimiter;

#pragma endregion

#pragma region accessors

// Our hook for the main render function. Returns true to call the trampoline and render.
static bool RenderScene_Hook()
{
	return s_frameLimiter.DoRenderSceneHook();
}

static bool AreParticlesDisabled()
{
	return !s_frameLimiter.IsRenderingEnabled();
}

static bool IsLimiterEnabled()
{
	return s_frameLimiter.IsEnabled();
}

static bool IsTieUiToSimulation()
{
	return s_frameLimiter.GetTieUiToSimulation();
}

static bool UpdateDisplay_Hook()
{
	return s_frameLimiter.DoUpdateDisplayHook();
}

static bool ShouldDoRealRenderWorld()
{
	return s_frameLimiter.DoRealRenderWorld();
}

bool DoThrottleFrameRate()
{
	return s_frameLimiter.DoThrottleFrameRate();
}

static void FrameLimiterSettings()
{
	s_frameLimiter.UpdateSettingsPanel();
}

#pragma endregion

#pragma region command

static void FrameLimiterReloadSettings(args::Subparser& parser)
{
	args::Group arguments(parser, "", args::Group::Validators::None);
	MQ2HelpArgument h(arguments);
	parser.Parse();

	WriteChatf("Reloading settings...");

	s_frameLimiter.ReadSettings();
}

template <FrameLimiter::LimiterSetting Setting, bool Position>
static void SetFrameLimiterBool(args::Subparser& parser)
{
	args::Group arguments(parser, "", args::Group::Validators::AtMostOne);
	MQ2HelpArgument h(arguments);
	parser.Parse();

	auto result = s_frameLimiter.Set<Setting>(Position);

	WriteChatf("FrameLimiter setting \at%s\ax has been set to \ay%s\ax.", FrameLimiter::SettingName<Setting>(), result ? "ENABLED" : "DISABLED");
}

template <FrameLimiter::LimiterSetting Setting>
static void SetFrameLimiterBool(args::Subparser& parser)
{
	args::Group arguments(parser, "", args::Group::Validators::AtMostOne);
	args::Positional<std::string> value(arguments, "value", "the value to set");
	MQ2HelpArgument h(arguments);
	parser.Parse();

	auto result = value ?
		s_frameLimiter.Set<Setting>(ci_starts_with(value.Get(), "true") || ci_starts_with(value.Get(), "on") || ci_equals(value.Get(), "1")) :
		s_frameLimiter.Toggle<Setting>();

	WriteChatf("FrameLimiter setting \at%s\ax has been set to \ay%s\ax.", FrameLimiter::SettingName<Setting>(), result ? "ENABLED" : "DISABLED");
}

template <FrameLimiter::LimiterSetting Setting>
static void SetFrameLimiterFloat(args::Subparser& parser)
{
	args::Group arguments(parser, "", args::Group::Validators::AtMostOne);
	args::Positional<float> value(arguments, "value", "the value to set");
	MQ2HelpArgument h(arguments);
	parser.Parse();
	if (value)
	{
		auto result = s_frameLimiter.Set<Setting>(value.Get());

		WriteChatf("FrameLimiter setting \at%s\ax has been set to \ay%.2f\ax.", FrameLimiter::SettingName<Setting>(), result);
	}
	else
	{
		WriteChatf("\at%s\ax requires an argument, use \ay-h\ax to determine the correct value.", FrameLimiter::SettingName<Setting>());
	}
}

void FrameLimiterCommand(SPAWNINFO* pChar, char* szLine)
{
	MQ2Args arg_parser("Frame limiter tool: allows adjusting internal frame limiter settings.");
	arg_parser.Prog("/framelimiter");
	arg_parser.RequireCommand(false);
	args::Group commands(arg_parser, "", args::Group::Validators::AtMostOne);

	args::Command enable(commands, "enable", "turn the framelimiter on (background)", SetFrameLimiterBool<FrameLimiter::LimiterSetting::Enable, true>);
	args::Command on(commands, "on", "turn the framelimiter on (background)", SetFrameLimiterBool<FrameLimiter::LimiterSetting::Enable, true>);
	args::Command disable(commands, "disable", "turn the rendering client off", SetFrameLimiterBool<FrameLimiter::LimiterSetting::Enable, false>);
	args::Command off(commands, "off", "turn the rendering client off", SetFrameLimiterBool<FrameLimiter::LimiterSetting::Enable, false>);
	args::Command toggle(commands, "toggle", "set/toggle the framelimiter functionality", SetFrameLimiterBool<FrameLimiter::LimiterSetting::Enable>);

	args::Command enablefg(commands, "enablefg", "turn the framelimiter on (foreground)", SetFrameLimiterBool<FrameLimiter::LimiterSetting::ForegroundEnable, true>);
	args::Command onfg(commands, "onfg", "turn the framelimiter on (foreground)", SetFrameLimiterBool<FrameLimiter::LimiterSetting::ForegroundEnable, true>);
	args::Command disablefg(commands, "disablefg", "turn the framelimiter off (foreground)", SetFrameLimiterBool<FrameLimiter::LimiterSetting::ForegroundEnable, false>);
	args::Command offfg(commands, "offfg", "turn the framelimiter off (foreground)", SetFrameLimiterBool<FrameLimiter::LimiterSetting::ForegroundEnable, false>);
	args::Command togglefg(commands, "togglefg", "set/toggle the framelimiter (foreground)", SetFrameLimiterBool<FrameLimiter::LimiterSetting::ForegroundEnable>);

	args::Command savebychar(commands, "savebychar", "set/toggle saving settings by character", SetFrameLimiterBool<FrameLimiter::LimiterSetting::SaveByChar>);

	args::Command bgrender(commands, "bgrender", "set/toggle rendering when client is in background", SetFrameLimiterBool<FrameLimiter::LimiterSetting::RenderInBackground>);

	args::Command imguirender(commands, "imguirender", "set/toggle rendering ImGui when rendering is otherwise disabled", SetFrameLimiterBool<FrameLimiter::LimiterSetting::TieImGuiToSimulation>);

	args::Command uirender(commands, "uirender", "set/toggle rendering the UI when rendering is otherwise disabled", SetFrameLimiterBool<FrameLimiter::LimiterSetting::TieUiToSimulation>);

	args::Command clearscreen(commands, "clearscreen", "set/toggle clearing (blanking) the screen when rendering is disabled", SetFrameLimiterBool<FrameLimiter::LimiterSetting::ClearScreen>);

	args::Command bgfps(commands, "bgfps", "set the FPS rate for the background process", SetFrameLimiterFloat<FrameLimiter::LimiterSetting::BackgroundFPS>);

	args::Command fgfps(commands, "fgfps", "set the FPS rate for the foreground process", SetFrameLimiterFloat<FrameLimiter::LimiterSetting::ForegroundFPS>);

	args::Command simfps(commands, "simfps", "sets the minimum FPS the simulation will run", SetFrameLimiterFloat<FrameLimiter::LimiterSetting::MinSimulationFPS>);

	args::Command reload(commands, "reloadsettings", "reload settings from ini", FrameLimiterReloadSettings);

	MQ2HelpArgument h(commands);
	auto args = allocate_args(szLine);

	try
	{
		arg_parser.ParseArgs(args);
	}
	catch (const args::Help&)
	{
		arg_parser.Help();
	}
	catch (const args::Error& e)
	{
		WriteChatColor(e.what());
		arg_parser.Help();
	}

	if (args.empty())
	{
		auto result = s_frameLimiter.Toggle<FrameLimiter::LimiterSetting::Enable>();
		WriteChatf("Toggling frame limiter state to \at%s\ax, use \ay%s -h\ax for a list of commands.", result ? "ENABLED" : "DISABLED", arg_parser.Prog().c_str());
	}
}

#pragma endregion

#pragma region module

static void InitializeFrameLimiter()
{
	AddSettingsPanel("Frame Limiter", FrameLimiterSettings);

	bmRenderScene = AddMQ2Benchmark("Render_Scene");
	bmRealRenderWorld = AddMQ2Benchmark("Render_Simulation");
	bmThrottleTime = AddMQ2Benchmark("Render_Throttle");

	// Hook UI render function
	EzDetour(CXWndManager__DrawWindows, &CXWndManagerHook::DrawWindows_Detour, &CXWndManagerHook::DrawWindows_Trampoline);

	// Hook main render function
	EzDetour(CRender__RenderScene, &CRenderHook::RenderScene_Detour, &CRenderHook::RenderScene_Trampoline);
	EzDetour(CRender__RenderBlind, &CRenderHook::RenderBlind_Detour, &CRenderHook::RenderBlind_Trampoline);
	EzDetour(CParticleSystem__CreateSpellEmitter, &CParticleSystemHook::CreateSpellEmitter_Detour, &CParticleSystemHook::CreateSpellEmitter_Trampoline);

	// Hook update function (will begin scene if render isn't called)
	EzDetour(CRender__UpdateDisplay, &CRenderHook::UpdateDisplay_Detour, &CRenderHook::UpdateDisplay_Trampoline);

	// Hook the main loop throttle function
#if defined(_M_AMD64)
	if constexpr (__ThrottleFrameRate_x && __ThrottleFrameRateEnd_x)
		AddDetour(__ThrottleFrameRate, Throttler_Detour, Throttler_Trampoline, "ThrottleFrameRate");
#else
	EzDetour(__ThrottleFrameRate, Throttler_Detour, Throttler_Trampoline);
#endif

	// Hook CDisplay::RealRender_World to control render loop
	EzDetour(CDisplay__RealRender_World, &CDisplayHook::RealRender_World_Detour, &CDisplayHook::RealRender_World_Trampoline);

	s_frameLimiter.ReadSettings();

	AddCommand("/framelimiter", FrameLimiterCommand, false, false, false);
}

static void ShutdownFrameLimiter()
{
	RemoveCommand("/framelimiter");

	RemoveSettingsPanel("Frame Limiter");

	RemoveDetour(CXWndManager__DrawWindows);
	RemoveDetour(CRender__RenderScene);
	RemoveDetour(CRender__RenderBlind);
	RemoveDetour(CParticleSystem__CreateSpellEmitter);
	RemoveDetour(CRender__UpdateDisplay);
	RemoveDetour(CDisplay__RealRender_World);
	RemoveDetour(__ThrottleFrameRate);

	RemoveMQ2Benchmark(bmRenderScene);
	RemoveMQ2Benchmark(bmRealRenderWorld);
	RemoveMQ2Benchmark(bmThrottleTime);
}

static void PulseFrameLimiter()
{
	s_frameLimiter.OnPulse();
}

static void SetGameStateFrameLimiter(int GameState)
{
	s_frameLimiter.PauseForZone();

	s_frameLimiter.SetGameState(GameState);
}

static MQModule s_FrameLimiterModule = {
	"FrameLimiter",                // Name
	false,                         // CanUnload
	InitializeFrameLimiter,        // Initialize
	ShutdownFrameLimiter,          // Shutdown
	PulseFrameLimiter,             // Pulse
	SetGameStateFrameLimiter,      // SetGameState
	nullptr,                       // UpdateImGui
	nullptr,                       // Zoned
	nullptr                        // WriteChatColor
};
DECLARE_MODULE_INITIALIZER(s_FrameLimiterModule);

#pragma endregion

#pragma region tlo

namespace datatypes {
enum class FrameLimiterTypeMembers
{
	Enabled,
	SaveByChar,
	Status,
	CPU,
	RenderFPS,
	SimulationFPS,
	BackgroundFPS,
	ForegroundFPS,
	MinSimulationFPS,
	ClearScreen
};

MQ2FrameLimiterType::MQ2FrameLimiterType() : MQ2Type("framelimiter")
{
	ScopedTypeMember(FrameLimiterTypeMembers, Enabled);
	ScopedTypeMember(FrameLimiterTypeMembers, SaveByChar);
	ScopedTypeMember(FrameLimiterTypeMembers, Status);
	ScopedTypeMember(FrameLimiterTypeMembers, CPU);
	ScopedTypeMember(FrameLimiterTypeMembers, RenderFPS);
	ScopedTypeMember(FrameLimiterTypeMembers, SimulationFPS);
	ScopedTypeMember(FrameLimiterTypeMembers, BackgroundFPS);
	ScopedTypeMember(FrameLimiterTypeMembers, ForegroundFPS);
	ScopedTypeMember(FrameLimiterTypeMembers, MinSimulationFPS);
	ScopedTypeMember(FrameLimiterTypeMembers, ClearScreen);
}

bool MQ2FrameLimiterType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	auto pMember = MQ2FrameLimiterType::FindMember(Member);
	if (pMember == nullptr)
		return false;

	switch (static_cast<FrameLimiterTypeMembers>(pMember->ID))
	{
	case FrameLimiterTypeMembers::Enabled:
		Dest.Type = pBoolType;
		Dest.Set(s_frameLimiter.IsEnabled());
		return true;

	case FrameLimiterTypeMembers::SaveByChar:
		Dest.Type = pBoolType;
		Dest.Set(s_frameLimiter.IsSavedByChar());
		return true;

	case FrameLimiterTypeMembers::Status:
		Dest.Type = pStringType;
		strcpy_s(DataTypeTemp, s_frameLimiter.IsForeground() ? "Foreground" : "Background");
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case FrameLimiterTypeMembers::CPU:
		Dest.Type = pFloatType;
		Dest.Set(s_frameLimiter.GetCPUUsage());
		return true;

	case FrameLimiterTypeMembers::RenderFPS:
		Dest.Type = pFloatType;
		Dest.Set(s_frameLimiter.GetRecordedRenderFPS());
		return true;

	case FrameLimiterTypeMembers::SimulationFPS:
		Dest.Type = pFloatType;
		Dest.Set(s_frameLimiter.GetRecordedSimulationFPS());
		return true;

	case FrameLimiterTypeMembers::BackgroundFPS:
		Dest.Type = pFloatType;
		Dest.Set(s_frameLimiter.GetTargetBackgroundFPS());
		return true;

	case FrameLimiterTypeMembers::ForegroundFPS:
		Dest.Type = pFloatType;
		Dest.Set(s_frameLimiter.GetTargetForegroundFPS());
		return true;

	case FrameLimiterTypeMembers::MinSimulationFPS:
		Dest.Type = pFloatType;
		Dest.Set(s_frameLimiter.GetMinimumSimulationFPS());
		return true;

	case FrameLimiterTypeMembers::ClearScreen:
		Dest.Type = pBoolType;
		Dest.Set(s_frameLimiter.GetClearScreen());
		return true;

	default:
		return false;
	}
}

bool MQ2FrameLimiterType::ToString(MQVarPtr VarPtr, char* Destination)
{
	strcpy_s(Destination, MAX_STRING, s_frameLimiter.IsEnabled() ? "TRUE" : "FALSE");
	return true;
}

bool MQ2FrameLimiterType::dataFrameLimiter(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Ptr = nullptr;
	Ret.Type = pFrameLimiterType;
	return true;
}


} // namespace datatypes

#pragma endregion

} // namespace mq
