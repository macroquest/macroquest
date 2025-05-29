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
#include "MQDetourAPI.h"
#include "MQRenderDoc.h"
#include "MQ2KeyBinds.h"
#include "MQPluginHandler.h"
#include "ImGuiManager.h"
#include "GraphicsResources.h"

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

// From MQ2PluginHandler.cpp
void ShutdownInternalModules();

MQModule* GetSpellsModule();
MQModule* GetImGuiToolsModule();
MQModule* GetDataAPIModule();
MQModule* GetActorAPIModule();
MQModule* GetGroundSpawnsModule();
MQModule* GetSpawnsModule();
MQModule* GetItemsModule();
MQModule* GetWindowsModule();
MQModule* GetPostOfficeModule();
#if IS_EMU_CLIENT
MQModule* GetEmuExtensionsModule();
#endif

void InitializeMQ2AutoInventory();
void ShutdownMQ2AutoInventory();

// Perform first time initialization on the main thread.
void DoMainThreadInitialization()
{
	InitializeDisplayHook();
	GraphicsResources_Initialize();
	ImGuiManager_Initialize();

	// this needs to be done before anything that would need to add a callback to string message parsing
	InitializeStringDB();

	InitializeChatHook();
	InitializeAnonymizer();
	InitializeInternalModules();
	AddInternalModule(GetWindowsModule());
	AddInternalModule(GetImGuiToolsModule());
	AddInternalModule(GetSpellsModule());
	AddInternalModule(GetDataAPIModule());
	AddInternalModule(GetActorAPIModule());
	AddInternalModule(GetGroundSpawnsModule());
	AddInternalModule(GetSpawnsModule());
	AddInternalModule(GetItemsModule());
	AddInternalModule(GetPostOfficeModule());
#if IS_EMU_CLIENT
	AddInternalModule(GetEmuExtensionsModule());
#endif
	InitializeMQ2Benchmarks();
	InitializeMQ2AutoInventory();
	InitializeMQ2KeyBinds();
	InitializePlugins();
	InitializeCachedBuffs();
}

// Do shutdown time stuff on the main thread.
void DoMainThreadShutdown()
{
	ShutdownCachedBuffs();
	ShutdownMQ2KeyBinds();
	ShutdownDisplayHook();
	ShutdownChatHook();
	ShutdownMQ2Pulse();
	ShutdownMQ2AutoInventory();
	ShutdownAnonymizer();
	ShutdownPlugins();
	ShutdownFailedPlugins();
	ShutdownInternalModules();
	ImGuiManager_Shutdown();
	GraphicsResources_Shutdown();
	ShutdownStringDB();
	ShutdownMQ2Benchmarks();
}

HMODULE GetCurrentModule()
{
	HMODULE hModule = nullptr;

	// Retrieve our current module handle by using the address of this function as a search param.
	GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS
		| GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)GetCurrentModule, &hModule);

	return hModule;
}

class CMQNewsWnd : public CCustomWnd
{
public:
	CMQNewsWnd() : CCustomWnd("ChatWindow")
	{
		AddStyle(CWS_TITLE | CWS_MINIMIZE);
		RemoveStyle(CWS_TRANSPARENT | CWS_CLOSE);
		SetBGColor(0xFF000000);
		SetLocation({ 230,620,850,920 });
		SetWindowText("MacroQuest Recent Changes");
		SetZLayer(1);

		OutputBox = (CStmlWnd*)GetChildItem("CW_ChatOutput");
		OutputBox->SetParentWindow(this);

		// Disable the input box since it doesn't handle anything anyway.
		InputBox = (CEditWnd*)GetChildItem("CW_ChatInput");
		InputBox->SetParentWindow(this);
		InputBox->Enabled = false;
	}

	~CMQNewsWnd()
	{
	}

	int WndNotification(CXWnd* pWnd, unsigned int Message, void* unknown) override
	{
		if (pWnd == nullptr)
		{
			if (Message == XWM_CLOSE)
			{
				this->SetVisible(true);
				return 1;
			}
		}

		return CCustomWnd::WndNotification(pWnd, Message, unknown);
	};

	CStmlWnd* OutputBox;
	CEditWnd* InputBox;
};
CMQNewsWnd* pNewsWindow = nullptr;

void AddNewsLine(const char* Line, int inColor)
{
	char szLine[MAX_STRING] = { 0 };
	strcpy_s(szLine, Line);

	COLORREF color = pChatManager->GetRGBAFromIndex(inColor);

	char szProcessed[MAX_STRING] = { 0 };
	MQToSTML(szLine, szProcessed, MAX_STRING, color);

	strcat_s(szProcessed, "<br>");
	CXStr NewText(szProcessed);
	ConvertItemTags(NewText, 0);

	pNewsWindow->OutputBox->AppendSTML(NewText);
}

void DeleteMQ2NewsWindow()
{
	delete pNewsWindow;
	pNewsWindow = nullptr;
}

void InsertMQ2News(const std::filesystem::path& pathChangeLog)
{
	if (!pNewsWindow)
		return;

	FILE* file = _fsopen(pathChangeLog.string().c_str(), "rb", _SH_DENYNO);
	if (!file)
	{
		DeleteMQ2NewsWindow();
		return;
	}

	//AddNewsLine("If you need help, refer to www.macroquest2.com/wiki", CONCOLOR_RED);
	AddNewsLine("Recent changes...", CONCOLOR_RED);

	char szLine[MAX_STRING] = { 0 };
	int nLines = 0;

	while (fgets(szLine, MAX_STRING, file))
	{
		char* Next_Token1 = nullptr;

		if (char* Cmd = strtok_s(szLine, "\r\n", &Next_Token1))
		{
			// TODO:  Move this to a method that isn't going to hit false positives.  Change the colors to be nicer on the eyes.
			if (GetIntFromString(Cmd, 0) != 0
				|| ci_starts_with(Cmd, "Jan")
				|| ci_starts_with(Cmd, "Feb")
				|| ci_starts_with(Cmd, "Mar")
				|| ci_starts_with(Cmd, "Apr")
				|| ci_starts_with(Cmd, "May")
				|| ci_starts_with(Cmd, "Jun")
				|| ci_starts_with(Cmd, "Jul")
				|| ci_starts_with(Cmd, "Aug")
				|| ci_starts_with(Cmd, "Sep")
				|| ci_starts_with(Cmd, "Oct")
				|| ci_starts_with(Cmd, "Nov")
				|| ci_starts_with(Cmd, "Dec"))
				AddNewsLine(Cmd, CONCOLOR_YELLOW);
			else
				AddNewsLine(Cmd, CONCOLOR_GREEN);
		}
		else
		{
			AddNewsLine("", CONCOLOR_GREEN);
		}

		nLines++;

		if (nLines > 200)
		{
			AddNewsLine("...read CHANGELOG.md for more.", CONCOLOR_RED);
			break;
		}
	}

	fclose(file);
}

void CreateMQ2NewsWindow()
{
	// NOTE: This change log search logic is duplicated in the launcher menu item.
	// This is one of the few places we want to hardcode the path since if the user redirects their resources we would not have distributed that file and they would always have old news.
	const std::filesystem::path pathMQRootChangeLog = std::filesystem::path(internal_paths::MQRoot) / "resources" / "CHANGELOG.md";
	const std::filesystem::path pathResourceChangeLog = std::filesystem::path(internal_paths::Resources) / "CHANGELOG.md";
	// Default to the one in the resource path.
	std::filesystem::path pathChangeLog = pathResourceChangeLog;

	std::error_code ec;
	// If the paths are different, and the Resource Change Log doesn't exist or is older than the Root\Resource changelog
	if (pathMQRootChangeLog != pathResourceChangeLog
		&& (!exists(pathResourceChangeLog, ec)
			|| last_write_time(pathMQRootChangeLog, ec) > last_write_time(pathResourceChangeLog, ec)))
	{
		pathChangeLog = pathMQRootChangeLog;
	}
	// END Duplicate logic

	if (!pNewsWindow && exists(pathChangeLog, ec))
	{
		pNewsWindow = new CMQNewsWnd();
	}

	InsertMQ2News(pathChangeLog);
}

//============================================================================

} // namespace mq
