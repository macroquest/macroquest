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
#include "MQRenderDoc.h"
#include "Logging.h"

#include "mq/base/WString.h"

#include <renderdoc/renderdoc_app.h>
#include <wil/resource.h>
#include <atomic>
#include <filesystem>

namespace mq {

#if HAS_DIRECTX_11

static void RenderDoc_Initialize();
static void RenderDoc_Shutdown();
static void RenderDoc_Pulse();

static MQModule gRenderDocModule = {
	"RenderDoc",                  // Name
	false,                        // CanUnload
	RenderDoc_Initialize,         // Initialize
	RenderDoc_Shutdown,           // Shutdown
	RenderDoc_Pulse,              // Pulse
};
DECLARE_MODULE_INITIALIZER(gRenderDocModule);

namespace fs = std::filesystem;

static bool s_renderDocInitialized = false;
static bool s_renderDocEnabled = false;
static std::string s_renderDocPath;
static std::string s_renderDocCapturesPath;
static bool s_captureNextFrame = false;
static HMODULE s_renderDocModule;
static RENDERDOC_API_1_6_0* s_renderDocAPI = nullptr;
static bool s_capturingFrames = false;

// Renderdoc Options
static int s_apiValidation = 0;
static int s_captureCallStacks = 0;
static int s_captureCallStacksOnlyActions = 0;
static int s_verifyBufferAccess = 0;
static int s_refAllResources = 0;
static int s_captureAllCmdLists = 0;
static int s_debugOutputMute = 1;
static int s_overlayBits = 0;

static constexpr const char* s_renderDocDefaultPath = R"(C:\Program Files\RenderDoc)";

static std::atomic_int s_stubBeginEventCounter = 0;
static HMODULE s_hDXCaptureReplayModule = nullptr;
extern std::set<HMODULE> g_knownModules;

using D3DPERF_BeginEvent_FPtr = int (WINAPI*)(D3DCOLOR, LPCWSTR);
using D3DPERF_EndEvent_FPtr = int (WINAPI*)();
using D3DPERF_SetMarker_FPtr = void (WINAPI*)(D3DCOLOR, LPCWSTR);

int WINAPI D3DPERF_BeginEventStub(D3DCOLOR col, LPCWSTR wszName)
{
	UNUSED(col);
	UNUSED(wszName);

	return ++s_stubBeginEventCounter;
}

int WINAPI D3DPERF_EndEventStub()
{
	int counter = --s_stubBeginEventCounter;
	if (counter < 0)
	{
		++s_stubBeginEventCounter;
		counter = 0;
	}

	return counter + 1;
}

void WINAPI D3DPERF_SetMarkerStub(D3DCOLOR col, LPCWSTR wszName)
{
	UNUSED(col);
	UNUSED(wszName);
}

D3DPERF_BeginEvent_FPtr pD3DPERF_BeginEvent = D3DPERF_BeginEventStub;
D3DPERF_EndEvent_FPtr pD3DPERF_EndEvent = D3DPERF_EndEventStub;
D3DPERF_SetMarker_FPtr pD3DPERF_SetMarker = D3DPERF_SetMarkerStub;

static void DXCaptureReplay_Initialize()
{
	if (s_hDXCaptureReplayModule == nullptr)
	{
		s_hDXCaptureReplayModule = ::LoadLibraryW(L"DXCaptureReplay.dll");
		if (s_hDXCaptureReplayModule != nullptr)
		{
			g_knownModules.insert(s_hDXCaptureReplayModule);

			pD3DPERF_BeginEvent = (D3DPERF_BeginEvent_FPtr)::GetProcAddress(s_hDXCaptureReplayModule, "D3DPERF_BeginEvent");
			pD3DPERF_EndEvent = (D3DPERF_EndEvent_FPtr)::GetProcAddress(s_hDXCaptureReplayModule, "D3DPERF_EndEvent");
			pD3DPERF_SetMarker = (D3DPERF_SetMarker_FPtr)::GetProcAddress(s_hDXCaptureReplayModule, "D3DPERF_SetMarker");
		}
	}
}

static void DXCaptureReplay_Shutdown()
{
	if (s_hDXCaptureReplayModule != nullptr)
	{
		::FreeLibrary(s_hDXCaptureReplayModule);
		g_knownModules.erase(s_hDXCaptureReplayModule);

		s_hDXCaptureReplayModule = nullptr;

		pD3DPERF_BeginEvent = D3DPERF_BeginEventStub;
		pD3DPERF_EndEvent = D3DPERF_EndEventStub;
		pD3DPERF_SetMarker = D3DPERF_SetMarkerStub;
	}
}


static void SetRenderDocOptions()
{
	s_renderDocAPI->SetCaptureOptionU32(eRENDERDOC_Option_APIValidation, s_apiValidation);
	s_renderDocAPI->SetCaptureOptionU32(eRENDERDOC_Option_CaptureCallstacks, s_captureCallStacks);
	s_renderDocAPI->SetCaptureOptionU32(eRENDERDOC_Option_CaptureCallstacksOnlyDraws, s_captureCallStacksOnlyActions);
	s_renderDocAPI->SetCaptureOptionU32(eRENDERDOC_Option_VerifyBufferAccess, s_verifyBufferAccess);
	s_renderDocAPI->SetCaptureOptionU32(eRENDERDOC_Option_RefAllResources, s_refAllResources);
	s_renderDocAPI->SetCaptureOptionU32(eRENDERDOC_Option_CaptureAllCmdLists, s_captureAllCmdLists);
	s_renderDocAPI->SetCaptureOptionU32(eRENDERDOC_Option_DebugOutputMute, s_debugOutputMute);
	s_renderDocAPI->MaskOverlayBits(0, s_overlayBits);
}

static void LoadRenderDoc()
{
	if (s_renderDocInitialized)
		return;

	fs::path renderDocDLL = fs::path(s_renderDocPath) / "renderdoc.dll";

	if (!fs::is_regular_file(renderDocDLL))
	{
		WriteChatf("\arCould not start renderdoc integration: DLL not found at %s", renderDocDLL.string().c_str());
		return;
	}

	// Try to find renderdoc.dll - it might already be loaded.
	wil::unique_hmodule hModule(::GetModuleHandleA("renderdoc.dll"));
	if (!hModule)
	{
		// Load renderdoc.dll
		hModule = wil::unique_hmodule(::LoadLibraryA(renderDocDLL.string().c_str()));
		if (!hModule)
		{
			WriteChatf("\arCould not start renderdoc integration: LoadLibrary failed");
			return;
		}
	}

	// Get the RENDERDOC_GetAPI function
	pRENDERDOC_GetAPI pRenderDoc_GetAPI = (pRENDERDOC_GetAPI)::GetProcAddress(hModule.get(), "RENDERDOC_GetAPI");
	if (pRenderDoc_GetAPI == nullptr)
	{
		WriteChatf("\arCould not start renderdoc integration: Could not load RENDERDOC_GetAPI");
		return;
	}

	constexpr RENDERDOC_Version version = eRENDERDOC_API_Version_1_6_0;

	int result = pRenderDoc_GetAPI(version, (void**)&s_renderDocAPI);

	if (result == 0)
	{
		s_renderDocAPI = nullptr;

		WriteChatf("\arCould not start renderdoc integration: Version %d is not supported", static_cast<int>(version));
		return;
	}

	// Unload the crash handler because we have our own.
	s_renderDocAPI->UnloadCrashHandler();

	s_apiValidation = GetPrivateProfileInt("RenderDoc", "APIValidation", 0, mq::internal_paths::MQini);
	s_captureCallStacks = GetPrivateProfileInt("RenderDoc", "CaptureCallStacks", 0, mq::internal_paths::MQini);
	s_captureCallStacksOnlyActions = GetPrivateProfileInt("RenderDoc", "CaptureCallStacksOnlyActions", 0, mq::internal_paths::MQini);
	s_verifyBufferAccess = GetPrivateProfileInt("RenderDoc", "VerifyBufferAccess", 0, mq::internal_paths::MQini);
	s_refAllResources = GetPrivateProfileInt("RenderDoc", "RefAllResources", 1, mq::internal_paths::MQini);
	s_captureAllCmdLists = GetPrivateProfileInt("RenderDoc", "CaptureAllCmdLists", 1, mq::internal_paths::MQini);
	s_debugOutputMute = GetPrivateProfileInt("RenderDoc", "DebugOutputMute", 1, mq::internal_paths::MQini);
	s_overlayBits = GetPrivateProfileInt("RenderDoc", "OverlayBits", 0, mq::internal_paths::MQini);

	SetRenderDocOptions();

	s_renderDocAPI->SetFocusToggleKeys(nullptr, 0);
	s_renderDocAPI->SetCaptureKeys(nullptr, 0);

	LOG_INFO("\agRenderDoc support enabled");

	// Sleep for a bit to give RenderDoc time to initialize
	Sleep(1000);

	DXCaptureReplay_Initialize();

	s_renderDocModule = hModule.release();
	s_renderDocInitialized = true;
}

void RenderDoc_BeginEvent(MQColor color, const char* name)
{
	if (s_renderDocEnabled)
	{
		std::wstring wName = mq::utf8_to_wstring(name);

		pD3DPERF_BeginEvent(color.ToARGB(), wName.c_str());
	}
}

#ifdef _DEBUG

void RenderDoc_BeginEvent(MQColor color, const wchar_t* name)
{
	if (s_renderDocEnabled)
	{
		pD3DPERF_BeginEvent(color.ToARGB(), name);
	}
}

void RenderDoc_EndEvent()
{
	if (s_renderDocEnabled)
	{
		pD3DPERF_EndEvent();
	}
}

void RenderDoc_SetMarker(MQColor color, const wchar_t* name)
{
	if (s_renderDocAPI != nullptr)
	{
		pD3DPERF_SetMarker(color.ToARGB(), name);
	}
}

#endif // _DEBUG

bool RenderDoc_IsEnabled()
{
	return s_renderDocAPI != nullptr;
}

static void RenderDoc_Command(PlayerClient* pChar, const char* szLine)
{
	if (!s_renderDocAPI)
	{
		WriteChatf("\arRenderDoc is not initialized");
		return;
	}

	if (ci_equals(szLine, "capture"))
	{
		s_captureNextFrame = true;
	}
}

static void RenderDoc_ImGuiDraw()
{
	if (!s_renderDocInitialized)
	{
		ImGui::Text("RenderDoc is not initialized");
		return;
	}

	if (ImGui::BeginTabBar("RenderDocTabs"))
	{
		if (ImGui::BeginTabItem("Capture"))
		{
			ImGui::Text("RenderDoc Path: %s", s_renderDocPath.c_str());
			ImGui::SameLine();
			ImGui::BeginDisabled(!fs::is_directory(s_renderDocPath));
			if (ImGui::Button("Open##ExploreRenderDocPath"))
			{
				ShellExecuteA(nullptr, "explore", s_renderDocPath.c_str(), nullptr, nullptr, SW_SHOW);
			}
			ImGui::EndDisabled();

			ImGui::Text("RenderDoc Captures Path: %s", s_renderDocCapturesPath.c_str());
			ImGui::SameLine();
			ImGui::BeginDisabled(!fs::is_directory(s_renderDocCapturesPath));
			if (ImGui::Button("Open##ExploreCapturesPath"))
			{
				ShellExecuteA(nullptr, "explore", s_renderDocCapturesPath.c_str(), nullptr, nullptr, SW_SHOW);
			}
			ImGui::EndDisabled();

			if (s_renderDocAPI)
			{
				ImGui::Separator();

				if (s_renderDocAPI->IsTargetControlConnected())
				{
					ImGui::TextColored(MQColor(0, 255, 0).ToImColor(), "RenderDoc UI Connected");

					ImGui::SameLine();

					if (ImGui::Button("Show Replay UI"))
					{
						s_renderDocAPI->ShowReplayUI();
					}
				}
				else if (ImGui::Button("Launch RenderDoc Replay UI"))
				{
					s_renderDocAPI->LaunchReplayUI(1, nullptr);
				}

				ImGui::Text("Frame Capture: "); ImGui::SameLine();
				bool isCapturing = s_renderDocAPI->IsFrameCapturing();

				if (s_renderDocAPI->IsFrameCapturing())
				{
					ImGui::TextColored(MQColor(0, 255, 0).ToImColor(), "Active");
				}
				else
				{
					ImGui::TextColored(MQColor(255, 255, 0).ToImColor(), "Inactive");
				}

				if (s_capturingFrames)
				{
					if (ImGui::Button("Stop Capture"))
					{
						s_renderDocAPI->EndFrameCapture(gpD3D11Device, *(HWND*)EQADDR_HWND);
						s_capturingFrames = false;
					}

					ImGui::SameLine();

					if (ImGui::Button("Cancel Capture"))
					{
						s_renderDocAPI->DiscardFrameCapture(gpD3D11Device, *(HWND*)EQADDR_HWND);
						s_capturingFrames = false;
					}
				}
				else
				{
					if (ImGui::Button("Start Capture"))
					{
						s_renderDocAPI->StartFrameCapture(gpD3D11Device, *(HWND*)EQADDR_HWND);
						s_capturingFrames = true;
					}
				}

				ImGui::SameLine();
				if (ImGui::Button("Capture Single Frame"))
				{
					s_captureNextFrame = true;
				}

				ImGui::Separator();

				int numCaptures = s_renderDocAPI->GetNumCaptures();
				ImGui::Text("Captures: %d", s_renderDocAPI->GetNumCaptures());

				char capturePath[512];
				uint32_t pathLength = sizeof(capturePath);

				for (int i = 0; i < numCaptures; ++i)
				{
					uint64_t timestamp = 0;
					if (s_renderDocAPI->GetCapture(i, capturePath, &pathLength, &timestamp))
					{
						if (!fs::is_regular_file(capturePath))
							continue;

						ImGui::PushID(i);

						ImGui::Text("%s", capturePath);
						ImGui::SameLine();
						if (ImGui::Button("Open"))
						{
							s_renderDocAPI->LaunchReplayUI(1, capturePath);
						}

						ImGui::PopID();
					}
				}
			}

			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Options"))
		{
			bool changed = false;

			bool apiValidation = s_apiValidation != 0;
			if (ImGui::Checkbox("API Validation", &apiValidation))
			{
				s_apiValidation = apiValidation ? 1 : 0;
				changed = true;

				WritePrivateProfileInt("RenderDoc", "APIValidation", s_apiValidation, mq::internal_paths::MQini);
			}

			bool captureCallStacks = s_captureCallStacks != 0;
			if (ImGui::Checkbox("Capture Call Stacks", &captureCallStacks))
			{
				s_captureCallStacks = captureCallStacks ? 1 : 0;
				changed = true;

				WritePrivateProfileInt("RenderDoc", "CaptureCallStacks", s_captureCallStacks, mq::internal_paths::MQini);
			}

			ImGui::BeginDisabled(!captureCallStacks);

			bool captureCallStacksOnlyActions = s_captureCallStacksOnlyActions != 0;
			if (ImGui::Checkbox("Capture Call Stacks Only Actions", &captureCallStacksOnlyActions))
			{
				s_captureCallStacksOnlyActions = captureCallStacksOnlyActions ? 1 : 0;
				changed = true;

				WritePrivateProfileInt("RenderDoc", "CaptureCallStacksOnlyActions", s_captureCallStacksOnlyActions, mq::internal_paths::MQini);
			}

			ImGui::EndDisabled();

			bool verifyBufferAccess = s_verifyBufferAccess != 0;
			if (ImGui::Checkbox("Verify Buffer Access", &verifyBufferAccess))
			{
				s_verifyBufferAccess = verifyBufferAccess ? 1 : 0;
				changed = true;

				WritePrivateProfileInt("RenderDoc", "VerifyBufferAccess", s_verifyBufferAccess, mq::internal_paths::MQini);
			}

			bool refAllResources = s_refAllResources != 0;
			if (ImGui::Checkbox("Ref All Resources", &refAllResources))
			{
				s_refAllResources = refAllResources ? 1 : 0;
				changed = true;

				WritePrivateProfileInt("RenderDoc", "RefAllResources", s_refAllResources, mq::internal_paths::MQini);
			}

			bool captureAllCmdLists = s_captureAllCmdLists != 0;
			if (ImGui::Checkbox("Capture All Cmd Lists", &captureAllCmdLists))
			{
				s_captureAllCmdLists = captureAllCmdLists ? 1 : 0;
				changed = true;

				WritePrivateProfileInt("RenderDoc", "CaptureAllCmdLists", s_captureAllCmdLists, mq::internal_paths::MQini);
			}

			bool debugOutputMute = s_debugOutputMute != 0;
			if (ImGui::Checkbox("Debug Output Mute", &debugOutputMute))
			{
				s_debugOutputMute = debugOutputMute ? 1 : 0;
				changed = true;

				WritePrivateProfileInt("RenderDoc", "DebugOutputMute", s_debugOutputMute, mq::internal_paths::MQini);
			}

			ImGui::Separator();

			ImGui::Text("Overlay Options");

			int overlayBits = s_overlayBits;
			ImGui::CheckboxFlags("Enabled", &s_overlayBits, eRENDERDOC_Overlay_Enabled);
			ImGui::CheckboxFlags("Frame Rate", &s_overlayBits, eRENDERDOC_Overlay_FrameRate);
			ImGui::CheckboxFlags("Frame Number", &s_overlayBits, eRENDERDOC_Overlay_FrameNumber);
			ImGui::CheckboxFlags("Capture List", &s_overlayBits, eRENDERDOC_Overlay_CaptureList);

			if (overlayBits != s_overlayBits)
			{
				changed = true;

				WritePrivateProfileInt("RenderDoc", "OverlayBits", s_overlayBits, mq::internal_paths::MQini);
			}

			if (changed)
			{
				SetRenderDocOptions();
			}

			ImGui::EndTabItem();
		}

		ImGui::EndTabBar();
	}
}

static void DBG_BeginBlock(int, int, const char* file, int*, int lineNo, const char* label, int*)
{
	//DebugSpew("DBG_BeginBlock: %s:%d => %s", file, lineNo, label);
	RenderDoc_BeginEvent(MQColor(153, 255, 132), label);
}

static void DBG_EndBlock(int)
{
	//DebugSpew("DBG_EndBlock");
	RenderDoc_EndEvent();
}

struct GraphicsDebugAPI
{
	using BeginBlock = void(*)(int, int, const char* filename, int*, int lineNumber, const char* label, int*);
	using EndBlock = void(*)(int);

	/*0x00*/ uint8_t unknown0[0xa0];
	/*0xa0*/ BeginBlock begin;
	/*0xa8*/ uint64_t padding;
	/*0xb0*/ EndBlock end;
};
GraphicsDebugAPI s_fakeDebugAPI;

void RenderDoc_Startup()
{
	// Get path to render doc. We don't have MQini set 
	std::string MQini = mq::internal_paths::MQRoot + "\\Config\\MacroQuest.ini";
	s_renderDocPath = GetPrivateProfileString("MacroQuest", "RenderDocPath", s_renderDocDefaultPath, MQini);
	s_renderDocEnabled = GetPrivateProfileBool("MacroQuest", "RenderDocEnabled", false, MQini);

	if (s_renderDocEnabled)
	{
		LoadRenderDoc();
	}
}

static void RenderDoc_Pulse()
{
	if (s_captureNextFrame)
	{
		s_renderDocAPI->TriggerCapture();

		s_captureNextFrame = false;
	}
}

static void RenderDoc_Initialize()
{
	if (s_renderDocInitialized)
	{
		g_knownModules.insert(s_renderDocModule);
		s_renderDocCapturesPath = (fs::path(mq::internal_paths::Logs) / "Captures").string();

		std::string captureFilePathTemplate = (fs::path(s_renderDocCapturesPath) / "eqgame").string();
		s_renderDocAPI->SetCaptureFilePathTemplate(captureFilePathTemplate.c_str());

		AddCommand("/renderdoc", RenderDoc_Command);
		AddSettingsPanel("RenderDoc", RenderDoc_ImGuiDraw);

		s_fakeDebugAPI.begin = DBG_BeginBlock;
		s_fakeDebugAPI.end = DBG_EndBlock;

		*(GraphicsDebugAPI**)EQGraphics_DebugAPI_Ptr = &s_fakeDebugAPI;
	}
}

static void RenderDoc_Shutdown()
{
	DXCaptureReplay_Shutdown();

	// We cannot free the module since it may be still loaded, so we will just let it leak.
	s_renderDocModule = nullptr;
	s_renderDocInitialized = false;
	s_renderDocAPI = nullptr;

	*(GraphicsDebugAPI**)EQGraphics_DebugAPI_Ptr = nullptr;

	if (s_renderDocInitialized)
	{
		RemoveCommand("/renderdoc");
		RemoveSettingsPanel("RenderDoc");
	}
}

#else // HAS_DIRECTX_11

#ifdef _DEBUG
void RenderDoc_BeginEvent(MQColor color, const wchar_t* name) {}
void RenderDoc_EndEvent() {}
void RenderDoc_SetMarker(MQColor color, const wchar_t* name) {}
#endif

void RenderDoc_Startup()
{
}

#endif // !HAS_DIRECTX_11

} // namespace mq
