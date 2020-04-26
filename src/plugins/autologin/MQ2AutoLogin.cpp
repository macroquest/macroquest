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

// For list of changes, see CHANGELOG.md

#include <mq/Plugin.h>

#include "AutoLoginShared.h"
#include "MQ2AutoLogin.h"

#include <imgui.h>
#include <imgui_stdlib.h>
#include <imgui_internal.h>

#include <map>
#include <tlhelp32.h>
#pragma comment(lib, "Crypt32.lib")

#include <filesystem>

namespace fs = std::filesystem;

PLUGIN_VERSION(3.0);

PreSetup("MQ2AutoLogin");

// this needs to be a char* to interact with the windows ini system
char CustomIni[64] = { 0 };
uint64_t ReenableTime = 0;

void Cmd_SwitchServer(SPAWNINFO* pChar, char* szLine)
{
	char szServer[MAX_STRING] = { 0 };
	char szCharacter[MAX_STRING] = { 0 };

	GetArg(szServer, szLine, 1);
	GetArg(szCharacter, szLine, 2);

	if (!szServer[0] || !szCharacter[0])
	{
		WriteChatf("\ayUsage:\ax /switchserver <server short name> <character name>");
		return;
	}

	// this is just a validity check, that's the only reason we have that set of server names
	if (ServerData.find(szServer) == std::cend(ServerData) && GetPrivateProfileString("Servers", szServer, "", INIFileName).empty())
	{
		WriteChatf("Invalid server name \ag%s\ax.  Valid server names are:", szServer);

		std::vector<std::string_view> server_names;
		std::transform(ServerData.cbegin(), ServerData.cend(), server_names.end(), [](const auto& e) { return e.first; });
		std::vector<std::string> custom_server_names = GetPrivateProfileKeys("Servers", INIFileName);

		server_names.insert(server_names.end(), custom_server_names.cbegin(), custom_server_names.cend());
		WriteChatColor(join(server_names, ", ").c_str());

		return;
	}

	Login::dispatch(SetLoginInformation(szServer, szCharacter));

	if (GetGameState() == GAMESTATE_INGAME)
	{
		if (pChar && ci_equals(EQADDR_SERVERNAME, szServer) && ci_equals(pChar->DisplayedName, szCharacter))
		{
			WriteChatf("\ayYou're already logged into '%s' on '%s'\ax", szCharacter, szServer);
		}
		else
		{
			if (pChar && pChar->StandState == STANDSTATE_FEIGN)
			{
				// using DoMappable here doesn't create enough of a delay for camp to work
				EzCommand("/stand");
			}

			EzCommand("/camp");
		}
	}

	WriteChatf("Switching to \ag%s\ax on server \ag%s\ax", szCharacter, szServer);
}

void Cmd_SwitchCharacter(SPAWNINFO* pChar, char* szLine)
{
	char szArg1[MAX_STRING] = { 0 };

	if (!szLine[0])
	{
		WriteChatf("\ayUsage:\ax /switchchar <name>");
		return;
	}

	GetArg(szArg1, szLine, 1);

	Login::dispatch(SetLoginInformation(szArg1));

	if (GetGameState() == GAMESTATE_INGAME)
	{
		if (pChar && ci_equals(pChar->DisplayedName, szArg1))
		{
			WriteChatf("\ayYou're already logged onto '%s'\ax", szArg1);
		}
		else
		{
			if (pChar->StandState == STANDSTATE_FEIGN)
			{
				// using DoMappable here doesn't create enough of a delay for camp to work
				EzCommand("/stand");
			}

			EzCommand("/camp");
		}
	}

	WriteChatf("Switch to \ag%s\ax is now active and will commence at character select.", szArg1);
}

void Cmd_Relog(SPAWNINFO* pChar, char* szLine)
{
	if (GetGameState() != GAMESTATE_INGAME)
		return;

	if (!szLine[0])
	{
		WriteChatf("\ayUsage:\ax /relog [#s|#m]");
		WriteChatf("Example: /relog 30m (logs character out for 30 minutes then logs back in)");
		return;
	}

	DWORD n = GetIntFromString(szLine, 0);

	switch (szLine[strlen(szLine) - 1])
	{
	case 's':
	case 'S':
		n *= 1000;
		break;
	case 'm':
	case 'M':
		n *= 60000;
		break;
	default:
		n *= 1000;
		break;
	}

	if (n)
	{
		ReenableTime = MQGetTickCount64() + n;
	}

	if (ReenableTime)
		ReenableTime += 30000; // add 30 seconds for camp time

	Login::dispatch(SetLoginInformation(EQADDR_SERVERNAME, pChar != nullptr ? pChar->DisplayedName : ""));

	if (pChar->StandState == STANDSTATE_FEIGN)
	{
		// using DoMappable here doesn't create enough of a delay for camp to work
		EzCommand("/stand");
	}

	EzCommand("/camp");
}

DETOUR_TRAMPOLINE_EMPTY(DWORD WINAPI GetPrivateProfileStringA_Trampoline(LPCSTR, LPCSTR, LPCSTR, LPSTR, DWORD, LPCSTR));

void SetupCustomIni()
{
	if (CustomIni && CustomIni[0] != '\0')
		return;

	if (const char* pLogin = GetLoginName())
	{
		GetPrivateProfileStringA_Trampoline(pLogin, "CustomClientIni", 0, CustomIni, 64, INIFileName);
	}
}

DWORD WINAPI GetPrivateProfileStringA_Detour(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpDefault, LPSTR lpReturnedString, DWORD nSize, LPCSTR lpFileName)
{
	if (lpFileName)
	{
		SetupCustomIni();

		if (CustomIni[0] != 0 && ci_find_substr(lpFileName, "eqclient.ini") != -1)
		{
			fs::path path = fs::path{ lpFileName } / CustomIni;

			return GetPrivateProfileStringA_Trampoline(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, path.string().c_str());
		}
	}

	return GetPrivateProfileStringA_Trampoline(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName);
}

BOOL WINAPI WritePrivateProfileStringA_Trampoline(LPCSTR, LPCSTR, LPCSTR, LPCSTR);
BOOL WINAPI WritePrivateProfileStringA_Detour(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpString, LPCSTR lpFileName)
{
	if (lpFileName)
	{
		SetupCustomIni();

		if (CustomIni[0] != 0 && ci_find_substr(lpFileName, "eqclient.ini") != -1)
		{
			fs::path path = fs::path{ lpFileName } / CustomIni;

			return WritePrivateProfileStringA_Trampoline(lpAppName, lpKeyName, lpString, path.string().c_str());
		}
	}

	return WritePrivateProfileStringA_Trampoline(lpAppName, lpKeyName, lpString, lpFileName);
}
DETOUR_TRAMPOLINE_EMPTY(BOOL WINAPI WritePrivateProfileStringA_Trampoline(LPCSTR, LPCSTR, LPCSTR, LPCSTR));

UINT WINAPI GetPrivateProfileIntA_Tramp(LPCSTR, LPCSTR, INT, LPCSTR);
UINT WINAPI GetPrivateProfileIntA_Detour(LPCSTR lpAppName, LPCSTR lpKeyName, INT nDefault, LPCSTR lpFileName)
{
	if (lpFileName)
	{
		SetupCustomIni();

		if (CustomIni[0] != '\0' && ci_find_substr(lpFileName, "eqclient.ini") != -1)
		{
			fs::path path = fs::path{ lpFileName } / CustomIni;

			return GetPrivateProfileIntA_Tramp(lpAppName, lpKeyName, nDefault, path.string().c_str());
		}
	}

	return GetPrivateProfileIntA_Tramp(lpAppName, lpKeyName, nDefault, lpFileName);
}
DETOUR_TRAMPOLINE_EMPTY(UINT WINAPI GetPrivateProfileIntA_Tramp(LPCSTR, LPCSTR, INT, LPCSTR));

void AutoLoginDebug(std::string_view svLogMessage, const bool bDebugOn /* = AUTOLOGIN_DBG */)
{
	if (bDebugOn)
	{
		std::filesystem::path pathToDebugLog = gPathLogs;
		pathToDebugLog /= "MQ2AutoLogin_DBG.log";

		FILE* fLog = nullptr;
		const errno_t err = fopen_s(&fLog, pathToDebugLog.string().c_str(), "a");

		if (err || !fLog)
		{
			DebugSpewAlways("Could not open MQ2Autologin Debug log for appending.");
		}
		else
		{
			SYSTEMTIME t;
			GetLocalTime(&t);

			const std::string strLogMessage = fmt::format("[{Year:0=4d}-{Month:0=2d}-{Day:0=2d} {Hour:0=2d}:{Minute:0=2d}:{Second:0=2d}] {LogMessage}",
			                            fmt::arg("Year", t.wYear),
			                                  fmt::arg("Month", t.wMonth),
			                                  fmt::arg("Day", t.wDay),
			                                  fmt::arg("Hour", t.wHour),
			                                  fmt::arg("Minute", t.wMinute),
			                                  fmt::arg("Second", t.wSecond),
			                                  fmt::arg("LogMessage", svLogMessage));

			DebugSpewAlways(strLogMessage.c_str());
			fprintf(fLog, "%s\n", strLogMessage.c_str());
			fclose(fLog);
		}
	}
}

void ReadINI()
{
	std::string path = GetPrivateProfileString("Settings", "IniLocation", "", INIFileName);
	if (!path.empty())
	{
		strcpy_s(INIFileName, path.c_str());
	}

	AUTOLOGIN_DBG = GetPrivateProfileBool("Settings", "Debug", AUTOLOGIN_DBG, INIFileName);
	AutoLoginDebug("MQ2AutoLogin: InitializePlugin()");

	s_loginSettings.NotifyOnServerUp = static_cast<LoginSettings::ServerUpNotification>(GetPrivateProfileInt("Settings", "NotifyOnServerUp", 0, INIFileName));
	s_loginSettings.KickActiveCharacter = GetPrivateProfileBool("Settings", "KickActiveCharacter", true, INIFileName);
	s_loginSettings.EndAfterSelect = GetPrivateProfileBool("Settings", "EndAfterCharSelect", false, INIFileName);

	bool bUseMQ2Login = GetPrivateProfileBool("Settings", "UseMQ2Login", false, INIFileName);
	bool bUseStationNamesInsteadOfSessions = GetPrivateProfileBool("Settings", "UseStationNamesInsteadOfSessions", false, INIFileName);
	if (bUseMQ2Login)
		s_loginSettings.LoginType = LoginSettings::Type::MQ2Login;
	else if (bUseStationNamesInsteadOfSessions)
		s_loginSettings.LoginType = LoginSettings::Type::StationNames;
	else
		s_loginSettings.LoginType = LoginSettings::Type::Sessions;
}

void LoginReset()
{
	AutoLoginDebug("LoginReset()");
	ReadINI();
}

PLUGIN_API void InitializePlugin()
{
	DebugSpewAlways("MQ2AutoLogin: InitializePlugin()");

	Login::set_initial_state();
	ReadINI();

	AddCommand("/switchserver", Cmd_SwitchServer);
	AddCommand("/switchcharacter", Cmd_SwitchCharacter);
	AddCommand("/relog", Cmd_Relog);

	if (GetPrivateProfileBool("Settings", "EnableCustomClientIni", false, INIFileName))
	{
		if (s_loginSettings.LoginType == LoginSettings::Type::StationNames)
		{
			SetupCustomIni();
		}

		DWORD pfnGetPrivateProfileIntA = (DWORD) & ::GetPrivateProfileIntA;
		EzDetour(pfnGetPrivateProfileIntA, GetPrivateProfileIntA_Detour, GetPrivateProfileIntA_Tramp);

		DWORD pfnGetPrivateProfileStringA = (DWORD) & ::GetPrivateProfileStringA;
		EzDetour(pfnGetPrivateProfileStringA, GetPrivateProfileStringA_Detour, GetPrivateProfileStringA_Trampoline);

		DWORD pfnWritePrivateProfileStringA = (DWORD) & ::WritePrivateProfileStringA;
		EzDetour(pfnWritePrivateProfileStringA, WritePrivateProfileStringA_Detour, WritePrivateProfileStringA_Trampoline);
	}
}

PLUGIN_API void ShutdownPlugin()
{
	RemoveCommand("/switchserver");
	RemoveCommand("/switchcharacter");
	RemoveCommand("/relog");

	DWORD pfnGetPrivateProfileIntA = (DWORD) & ::GetPrivateProfileIntA;
	RemoveDetour(pfnGetPrivateProfileIntA);

	DWORD pfnGetPrivateProfileStringA = (DWORD) & ::GetPrivateProfileStringA;
	RemoveDetour(pfnGetPrivateProfileStringA);

	DWORD pfnWritePrivateProfileStringA = (DWORD) & ::WritePrivateProfileStringA;
	RemoveDetour(pfnWritePrivateProfileStringA);

	LoginReset();
}

PLUGIN_API void SetGameState(DWORD GameState)
{
	s_loginSettings.EndAfterSelect = GetPrivateProfileInt("Settings", "EndAfterCharSelect", 0, INIFileName) == 1;
}

PLUGIN_API void OnPulse()
{
	if (GetAsyncKeyState(VK_HOME) & 1)
		Login::dispatch(HomePressed());
	else if (GetAsyncKeyState(VK_END) & 1)
		Login::dispatch(EndPressed());
	else if (GetGameState() == GAMESTATE_INGAME && MQGetTickCount64() > ReenableTime)
		Login::dispatch(LoginStateSensor(LoginState::InGame, nullptr));
	else if (GetGameState() == GAMESTATE_CHARSELECT && MQGetTickCount64() > ReenableTime)
	{
		if (CXWnd* pWnd = GetWindow("CLW_CharactersScreen"))
			Login::dispatch(LoginStateSensor(LoginState::CharacterSelect, pWnd));
	}
	else if (GetGameState() == GAMESTATE_PRECHARSELECT && MQGetTickCount64() > ReenableTime)
	{
		// pair of WindowNames / ButtonNames
		std::vector<std::pair<const char*, const char*>> PromptWindows = {
			{ "OrderWindow", "Order_DeclineButton" },
			{ "EulaWindow", "EULA_AcceptButton" },
			{ "seizurewarning", "HELP_OKButton"},
			{ "OrderExpansionWindow", "OrderExp_DeclineButton" },
			{ "main", "MAIN_ConnectButton" },
			{ "news", "NEWS_OKButton"}
		};

		// Click through any dialogs, don't need a whole state for this
		for (const auto& [windowName, buttonName] : PromptWindows)
		{
			if (CButtonWnd* pButton = GetActiveChildWindow<CButtonWnd>(windowName, buttonName))
			{
				pButton->WndNotification(pButton, XWM_LCLICK);
				return;
			}
		}

		if (IsWindowActive("dbgsplash"))
		{
			Login::dispatch(LoginStateSensor(LoginState::SplashScreen, nullptr));
		}
		else if (CXWnd* pConnectWnd = GetActiveWindow("connect"))
		{
			if (CXWnd* pOkDialog = GetActiveWindow("okdialog"))
				Login::dispatch(LoginStateSensor(LoginState::ConnectConfirm, pOkDialog));
			else
				Login::dispatch(LoginStateSensor(LoginState::Connect, pConnectWnd));
		}
		else if (CXWnd* pServerWnd = GetActiveWindow("serverselect"))
		{
			if (CXWnd* pOkDialog = GetActiveWindow("okdialog"))
				Login::dispatch(LoginStateSensor(LoginState::ServerSelectConfirm, pOkDialog));
			else if (CXWnd* pYesNoDialog = GetActiveWindow("yesnodialog"))
				Login::dispatch(LoginStateSensor(LoginState::ServerSelectKick, pYesNoDialog));
			else
				Login::dispatch(LoginStateSensor(LoginState::ServerSelect, pServerWnd));
		}
	}
}

static bool bShowAutoLoginOverlay = true;
static bool bShowOverlayDebugInfo = false;

static void ToggleButton(const char* str_id, bool* v)
{
    ImVec2 p = ImGui::GetCursorScreenPos();
    ImDrawList* draw_list = ImGui::GetWindowDrawList();

    float height = ImGui::GetFrameHeight();
    float width = height * 1.55f;
    float radius = height * 0.50f;

    ImGui::InvisibleButton(str_id, ImVec2(width, height));
    if (ImGui::IsItemClicked())
        *v = !*v;

    float t = *v ? 1.0f : 0.0f;

    ImGuiContext& g = *GImGui;
    float ANIM_SPEED = 0.08f;
    if (g.LastActiveId == g.CurrentWindow->GetID(str_id))// && g.LastActiveIdTimer < ANIM_SPEED)
    {
        float t_anim = ImSaturate(g.LastActiveIdTimer / ANIM_SPEED);
        t = *v ? (t_anim) : (1.0f - t_anim);
    }

    ImU32 col_bg;
    if (ImGui::IsItemHovered())
        col_bg = ImGui::GetColorU32(ImLerp(ImVec4(0.78f, 0.78f, 0.78f, 1.0f), ImVec4(0.64f, 0.83f, 0.34f, 1.0f), t));
    else
        col_bg = ImGui::GetColorU32(ImLerp(ImVec4(0.85f, 0.85f, 0.85f, 1.0f), ImVec4(0.56f, 0.83f, 0.26f, 1.0f), t));

    draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, height * 0.5f);
    draw_list->AddCircleFilled(ImVec2(p.x + radius + t * (width - radius * 2.0f), p.y + radius), radius - 1.5f, IM_COL32(255, 255, 255, 255));
}

template <typename T>
static bool RadioButton(const char* label, T* v, T v_button)
{
    const bool pressed = ImGui::RadioButton(label, *v == v_button);
    if (pressed)
        *v = v_button;
    return pressed;
}

// Demonstrate creating a simple static window with no decoration + a context-menu to choose which corner of the screen to use.
static void ShowAutoLoginOverlay(bool* p_open)
{
	const float DISTANCE = 10.0f;

	int gameState = GetGameState();
	int corner = (gameState == GAMESTATE_CHARSELECT ? 1 : 0); // 0 = top left, 1 = top right, 2 = bottom left, 3 = bottom right
	ImGuiIO& io = ImGui::GetIO();

	if (corner != -1)
	{
		ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImVec2 window_pos = ImVec2((corner & 1) ? (viewport->Pos.x + viewport->Size.x - DISTANCE) : (viewport->Pos.x + DISTANCE), (corner & 2) ? (viewport->Pos.y + viewport->Size.y - DISTANCE) : (viewport->Pos.y + DISTANCE));
		ImVec2 window_pos_pivot = ImVec2((corner & 1) ? 1.0f : 0.0f, (corner & 2) ? 1.0f : 0.0f);
		ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always, window_pos_pivot);
		ImGui::SetNextWindowViewport(viewport->ID);
	}
	ImGui::SetNextWindowBgAlpha(gameState == GAMESTATE_CHARSELECT ? .85f : .35f); // Transparent background
	if (ImGui::Begin("MQ2AutoLogin Status", p_open, (corner != -1 ? ImGuiWindowFlags_NoMove : 0) | ImGuiWindowFlags_NoBringToFrontOnFocus  | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav))
	{
		ImGui::Text("MQ2AutoLogin Method:");
		RadioButton("MQ2Login", &s_loginSettings.LoginType, LoginSettings::Type::MQ2Login); ImGui::SameLine();
		RadioButton("StationNames", &s_loginSettings.LoginType, LoginSettings::Type::StationNames); ImGui::SameLine();
		RadioButton("Sessions", &s_loginSettings.LoginType, LoginSettings::Type::Sessions);

		ImGui::Text("(right-click to hide)");
		ImGui::Separator();

		bool bUseMQ2Login = !Login::paused();
		if (ImGui::Checkbox("Enable Auto Login", &bUseMQ2Login))
		{
			bUseMQ2Login ? Login::dispatch(HomePressed()) : Login::dispatch(EndPressed());
		}

		if (bUseMQ2Login)
		{
			ImGui::Separator();

			ImGui::Text("Current Status:");
			ImGui::Text("Server: %s", Login::server().c_str());
			ImGui::Text("Character: %s", Login::character().c_str());
		}

		if (bShowOverlayDebugInfo)
		{
			ImGui::Separator();

			ImGui::Text("Settings:");
			ImGui::Checkbox("Kick Active Character", &s_loginSettings.KickActiveCharacter);
			ImGui::Checkbox("End After Select", &s_loginSettings.EndAfterSelect);

			ImGui::Separator();
			ImGui::Text("Server Up Notification:");
			RadioButton("None", &s_loginSettings.NotifyOnServerUp, LoginSettings::ServerUpNotification::None); ImGui::SameLine();
			RadioButton("Email", &s_loginSettings.NotifyOnServerUp, LoginSettings::ServerUpNotification::Email); ImGui::SameLine();
			RadioButton("Beeps", &s_loginSettings.NotifyOnServerUp, LoginSettings::ServerUpNotification::Beeps);

			ImGui::Separator();
			ImGui::Text("State Variables:");
			ImGui::RadioButton("Offsets Loaded", Login::offsets_loaded());
			ImGui::Text("Delay Time: %llu", Login::delay_time() > MQGetTickCount64() ? Login::delay_time() - MQGetTickCount64() : 0ULL);
			ImGui::Text("Last State: "); ImGui::SameLine();
			switch (Login::last_state())
			{
				case LoginState::SplashScreen: ImGui::Text("SplashScreen"); break;
				case LoginState::Connect: ImGui::Text("Connect"); break;
				case LoginState::ConnectConfirm: ImGui::Text("ConnectConfirm"); break;
				case LoginState::ServerSelect: ImGui::Text("ServerSelect"); break;
				case LoginState::ServerSelectConfirm: ImGui::Text("ServerSelectConfirm"); break;
				case LoginState::ServerSelectKick: ImGui::Text("ServerSelectKick"); break;
				case LoginState::ServerSelectDown: ImGui::Text("ServerSelectDown"); break;
				case LoginState::CharacterSelect: ImGui::Text("CharacterSelect"); break;
				case LoginState::InGame: ImGui::Text("InGame"); break;
				default: ImGui::Text(""); break;
			}
			if (Login::current_window() != nullptr && Login::current_window()->GetXMLData() != nullptr)
			{
				ImGui::Text("Current Window: %s", Login::current_window()->GetXMLData()->Name.c_str());
			}

			ImGui::Separator();
			ImGui::Checkbox("Enable Debug Logging", &AUTOLOGIN_DBG);
		}

		if (ImGui::BeginPopupContextWindow())
		{
			ImGui::MenuItem("Show Debug Info", nullptr, &bShowOverlayDebugInfo);
			ImGui::Separator();
			if (p_open && ImGui::MenuItem("Close")) *p_open = false;
			ImGui::EndPopup();
		}
	}
	ImGui::End();
}

PLUGIN_API void OnUpdateImGui()
{
	int gameState = GetGameState();

	// Only show autologin overlay during character select or login
	//if (gameState == GAMESTATE_CHARSELECT || gameState == GAMESTATE_PRECHARSELECT)
	{
		ShowAutoLoginOverlay(&bShowAutoLoginOverlay);
	}
}