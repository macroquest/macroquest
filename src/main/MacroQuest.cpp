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
#include "MacroQuest.h"

#include "CrashHandler.h"
#include "MQActorAPI.h"
#include "MQCommandAPI.h"
#include "MQDataAPI.h"
#include "MQDetourAPI.h"
#include "MQRenderDoc.h"

#include "mq/base/Logging.h"
#include "eqlib/game/Globals.h"

#include "MQ2Globals.h"
#include "MQ2Main.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>
#include <chrono>
#include <filesystem>
#include <fstream>

#include <Psapi.h>

#include "MQPluginHandler.h"

namespace fs = std::filesystem;

#if IS_LIVE_CLIENT

#if !defined(_M_AMD64)
#error Live build is only for x64
#endif
#pragma message("Building MacroQuest for LIVE (x64)")
#define MacroQuestWinClassName "__MacroQuestTray(Live)"
#define MacroQuestWinName "MacroQuest(Live)"

#elif IS_TEST_CLIENT

#if !defined(_M_AMD64)
#error Test build is only for x64
#endif
#pragma message("Building MacroQuest for TEST (x64)")
#define MacroQuestWinClassName "__MacroQuestTray(Test)"
#define MacroQuestWinName "MacroQuest(Test)"

#elif IS_BETA_CLIENT

#if !defined(_M_AMD64)
#error Beta build is only for x64
#endif
#pragma message("Building MacroQuest for BETA (x64)")
#define MacroQuestWinClassName "__MacroQuestTray(Beta)"
#define MacroQuestWinName "MacroQuest(Beta)"

#elif IS_EMU_CLIENT

#if defined(_M_AMD64)
#error Emulator Build is only for x86
#endif
#pragma message("Building MacroQuest for EMULATOR (x86)")
#define MacroQuestWinClassName "__MacroQuestTray(EQEmu)"
#define MacroQuestWinName "MacroQuest(EQEmu)"

#endif

#define CLIENT_OVERRIDE 0

namespace mq {

// Internal path variables
std::string mq::internal_paths::MQRoot = ".";
std::string mq::internal_paths::Config = "Config";
std::string mq::internal_paths::MQini = mq::internal_paths::Config + "\\MacroQuest.ini";
std::string mq::internal_paths::Macros = "Macros";
std::string mq::internal_paths::Logs = "Logs";
std::string mq::internal_paths::CrashDumps = mq::internal_paths::Logs + "\\Dumps";
std::string mq::internal_paths::Plugins = "Plugins";
std::string mq::internal_paths::Resources = "Resources";
std::string mq::internal_paths::EverQuest = "%PUBLIC%\\Daybreak Game Company\\Installed Games\\EverQuest"; // Although the working directory is EverQuest, the WIN_API calls source to %WINDIR%

// Exported path variables
char gPathMQRoot[MAX_PATH] = {};
char gPathConfig[MAX_PATH] = {};
char gPathMQini[MAX_PATH] = {};
char gPathMacros[MAX_PATH] = {};
char gPathLogs[MAX_PATH] = {};
char gPathCrashDumps[MAX_PATH] = {};
char gPathPlugins[MAX_PATH] = {};
char gPathResources[MAX_PATH] = {};
char gPathEverQuest[MAX_PATH] = {};

// Deprecated exported path variables
char gszEQPath[MAX_STRING] = {};      // Deprecated
char gszMacroPath[MAX_STRING] = {};   // Deprecated
char gszLogPath[MAX_STRING] = {};     // Deprecated
char gszINIPath[MAX_STRING] = {};     // Deprecated
char gszINIFilename[MAX_STRING] = {}; // Deprecated
char gszItemDB[MAX_STRING] = {};      // Deprecated

char gszVersion[32] = __ExpectedVersionDate;
char gszTime[32]    = __ExpectedVersionTime;

#if defined(EMULATOR)
int gBuild = static_cast<int>(BuildTarget::Emu);                // EMU (ROF2)
#elif defined(TEST)
int gBuild = static_cast<int>(BuildTarget::Test);               // TEST
#else
int gBuild = static_cast<int>(BuildTarget::Live);               // LIVE
#endif

MacroQuest* g_mq = nullptr;

wil::unique_event g_loadComplete;
wil::unique_event g_unloadComplete;

static HANDLE s_backgroundThread = nullptr;

// FIXME: Remove these forward declarations
void InitializePluginHandle();
void Heartbeat();
void SetMainThreadId();

struct MQStartupParams
{
	HANDLE hModule;
	bool backgroundThread;
};

// The main thread ID
static DWORD dwMainThreadId = 0;

/**
 * Get the ID of the main thread
 */
DWORD GetMainThreadId()
{
	return dwMainThreadId;
}

/**
 * Check if the current function is running from the main thread.
 */
bool IsMainThread()
{
	// If not initialized yet, we don't know. Treat as if we're on another
	// thread, then we'll stay extra safe.
	if (dwMainThreadId == 0)
		return false;

	return dwMainThreadId == ::GetCurrentThreadId();
}

/**
 * Immediately upon startup, make sure we've allowed enough time for InnerSpace/Lavish software to
 * inject and set up its hooks, so that we can come in after them. If we go before, we may lose our
 * hooks and fail to function properly.
 */
static void WaitForLavishSoftware()
{
	// IsBoxer/InnerSpace
	HMODULE hISModule = GetModuleHandle("InnerSpace.dll");
	if (!hISModule)
	{
		// Joe MultiBoxer / WinEQ2022
		hISModule = GetModuleHandle("JMB.dll");
	}
	if (!hISModule)
	{
		// WinEQ?
		hISModule = GetModuleHandle("Lavish.dll");
	}
	if (hISModule)
	{
		uintptr_t baseAddressLS = 0;
		uintptr_t endAddress = 0;

		MODULEINFO moduleInfo;
		HMODULE hKernelModule = GetModuleHandleA("kernel32.dll");

		if (hISModule
			&& GetModuleInformation(GetCurrentProcess(), hISModule, &moduleInfo, sizeof(MODULEINFO)))
		{
			baseAddressLS = (uintptr_t)moduleInfo.lpBaseOfDll;
			endAddress = baseAddressLS + (uintptr_t)moduleInfo.SizeOfImage;
		}

		bool foundHooks = baseAddressLS == 0;             // skip checks if InnerSpace.dll isn't loaded
		bool foundWindowHandle = false;

		// Do some checks against Lavish/InnerSpace integrations. Wait a total of 10 seconds or we fail all checks.
		const auto startTime = std::chrono::steady_clock::now();
		while (std::chrono::steady_clock::now() - startTime < std::chrono::seconds(10) && !(foundHooks && foundWindowHandle))
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(200));

			if (!foundHooks)
			{
				// Wait for module to finish loading before we try to continue. Otherwise it will modify our
				// import address table, resulting in our detours being ineffective if we go first.
				uintptr_t fnGetProcAddress = (uintptr_t) & ::GetProcAddress;
				if (fnGetProcAddress >= baseAddressLS && fnGetProcAddress < endAddress)
				{
					foundHooks = true;
				}
				else
				{
					fnGetProcAddress = (uintptr_t)GetProcAddress(hKernelModule, "GetProcAddress");
					if (fnGetProcAddress >= baseAddressLS && fnGetProcAddress < endAddress)
					{
						foundHooks = true;
					}
				}
			}

			if (!foundWindowHandle)
			{
				// we also use this loop to wait for wineq2/innerspace to get the eqwindow up and running before we move on.
				HWND hEQWnd = GetEQWindowHandle();
				if (hEQWnd != nullptr)
				{
					foundWindowHandle = true;
				}
			}
		}

		// The lavish dlls steal our detour so that our GetProcAddress never sees the eqmain.dll load.  Delaying here
		// gives eqmain.dll time to load so that we're not waiting for that trigger when we inject at startup.
		std::this_thread::sleep_for(std::chrono::seconds(1));

		if (!foundHooks)
		{
			DebugSpewAlways("Was not able to detect the InnerSpace hook on GetProcAddress!");
		}

		if (!foundWindowHandle)
		{
			DebugSpewAlways("Was not able to detect the main EQ window handle!");
		}
	}
}

static bool InitDirectory(std::string& strPathToInit,
	const std::string& strIniKey,
	const std::string& iniToRead,
	const fs::path& appendPathIfRelative = mq::internal_paths::MQRoot)
{
	DebugSpewAlways("Initializing Directory:  %s", strIniKey.c_str());

	fs::path pathToInit = GetPrivateProfileString("MacroQuest", strIniKey, strPathToInit, iniToRead);

	if (gbWriteAllConfig)
	{
		WritePrivateProfileString("MacroQuest", strIniKey, pathToInit.string(), iniToRead);
	}

	if (pathToInit.is_relative())
	{
		pathToInit = fs::absolute(appendPathIfRelative / pathToInit);
	}

	// Either way, update the string
	strPathToInit = pathToInit.string();
	std::error_code ec_fs;

	if (fs::exists(pathToInit, ec_fs) || fs::create_directories(pathToInit, ec_fs))
	{
		DebugSpewAlways("Directory Init of %s successful at: %s", strIniKey.c_str(), strPathToInit.c_str());
		return true;
	}

	const std::string strTemp = fmt::format("Could not find or create {} path: {}", strIniKey, strPathToInit);
	DebugSpewAlways("%s", strTemp.c_str());
	MessageBox(nullptr, strTemp.c_str(), "MacroQuest", MB_OK);
	return false;
}

bool InitDirectories(const std::string& iniToRead)
{
	DebugSpewAlways("Initializing Required Directories...");

	if (InitDirectory(mq::internal_paths::Macros, "MacroPath", iniToRead, mq::internal_paths::MQRoot)
		&& InitDirectory(mq::internal_paths::Logs, "LogPath", iniToRead, mq::internal_paths::MQRoot)
		&& InitDirectory(mq::internal_paths::CrashDumps, "CrashDumpPath", iniToRead, mq::internal_paths::MQRoot)
		&& InitDirectory(mq::internal_paths::Plugins, "PluginPath", iniToRead, mq::internal_paths::MQRoot)
		&& InitDirectory(mq::internal_paths::Resources, "ResourcePath", iniToRead, mq::internal_paths::MQRoot))
	{
		std::error_code ec;
		mq::internal_paths::EverQuest = fs::current_path(ec).string();
#pragma warning(push)
#pragma warning(disable: 4996) // temporarily disable deprecation warnings.
		// Backwards compatible before we deprecate
		strcpy_s(gszMacroPath, mq::internal_paths::Macros.c_str());
		strcpy_s(gszLogPath, mq::internal_paths::Logs.c_str());
		strcpy_s(gszEQPath, mq::internal_paths::EverQuest.c_str());
#pragma warning(pop)
		// API compatible
		strcpy_s(gPathMacros, mq::internal_paths::Macros.c_str());
		strcpy_s(gPathLogs, mq::internal_paths::Logs.c_str());
		strcpy_s(gPathCrashDumps, mq::internal_paths::CrashDumps.c_str());
		strcpy_s(gPathPlugins, mq::internal_paths::Plugins.c_str());
		strcpy_s(gPathResources, mq::internal_paths::Resources.c_str());
		strcpy_s(gPathEverQuest, mq::internal_paths::EverQuest.c_str());
		return true;
	}

	return false;
}

/*
 * Find the initial MacroQuest.ini to set the config directory.
 * Additional settings will be parsed out of the MacroQuest.ini in
 * that directory, but we don't want to parse the config directory
 * from there since that could cause a circular config relationship.
 */
static bool InitConfig(std::string& strMQRoot, std::string& strConfig, std::string& strMQini)
{
	DebugSpewAlways("Initializing Configuration...");

	fs::path pathMQRoot = strMQRoot;

	// If we still have a relative path to the MQ directory, make it absolute.
	if (pathMQRoot.is_relative())
	{
		pathMQRoot = fs::absolute(pathMQRoot).string();
	}
	// Set strMQRoot to the path we found.
	strMQRoot = pathMQRoot.string();
	std::error_code ec;

	// If the path to MQ doesn't exist none of our relative paths are going to work
	if (fs::exists(pathMQRoot, ec))
	{
		strMQini = GetCreateMacroQuestIni(pathMQRoot, strConfig, strMQini);

		gbWriteAllConfig = GetPrivateProfileBool("MacroQuest", "WriteAllConfig", false, strMQini);
		// Write the MQIniPath if we're writing all config.  This will be the full path and in the redirected ini
		// (not the original ini) but since WriteAllConfig is meant to write a full config, that's okay.
		if (gbWriteAllConfig)
		{
			WritePrivateProfileString("MacroQuest", "MQIniPath", strMQini, strMQini);
		}

		// Init the Config directory based on the ini we found.
		if (InitDirectory(strConfig, "ConfigPath", strMQini, strMQRoot))
		{
#pragma warning(push)
#pragma warning(disable: 4996) // temporarily disable deprecation warnings.
			// Backwards compatible before we deprecate
			strcpy_s(gszEQPath, fs::absolute(".").string().c_str());
			strcpy_s(gszINIPath, strMQRoot.c_str()); // or mq::internal_paths::Config but since it's mostly used to find the MQ2 directory...
			strcpy_s(gszINIFilename, strMQini.c_str());
			// API compatible
			strcpy_s(gPathMQRoot, strMQRoot.c_str());
			strcpy_s(gPathMQini, strMQini.c_str());
			strcpy_s(gPathConfig, strConfig.c_str());
#pragma warning(pop)
			return true;
		}
	}

	return false;
}

MacroQuest::MacroQuest()
{
	srand(static_cast<uint32_t>(time(nullptr)));
}

MacroQuest::~MacroQuest()
{
}

bool MacroQuest::Initialize()
{
	WaitForLavishSoftware();

	DebugSpew("Expected Client version: %s %s", __ExpectedVersionDate, __ExpectedVersionTime);
	DebugSpew("    Real Client version: %s %s", eqlib::__ActualVersionDate, eqlib::__ActualVersionTime);

	const char* actualVersionDate = (const char*)eqlib::__ActualVersionDate;
	const char* actualVersionTime = (const char*)eqlib::__ActualVersionTime;

	// note: CLIENT_OVERRIDE is always #defined as 1 or 0
#if !CLIENT_OVERRIDE
	if (strncmp(__ExpectedVersionDate, actualVersionDate, strlen(__ExpectedVersionDate)) ||
		strncmp(__ExpectedVersionTime, actualVersionTime, strlen(__ExpectedVersionTime)))
	{
		::MessageBoxA(nullptr, "Incorrect client version", "MacroQuest", MB_OK);
		return false;
	}
#endif

	// Load configuration so that we can create a logger.
	if (!InitConfig(mq::internal_paths::MQRoot, mq::internal_paths::Config, mq::internal_paths::MQini))
	{
		DebugSpewAlways("InitConfig returned false - initialization aborted.");
		return false;
	}

	if (!InitDirectories(mq::internal_paths::MQini))
	{
		DebugSpewAlways("InitDirectories returned false - initialization aborted.");
		return false;
	}

	// Initialize logging, we will need a logger to initialize eqlib
	InitializeLogging();

	if (!InitializeEQLib())
	{
		DebugSpewAlways("InitializeEQLib failed - check logs for more details");
		return false;
	}

	if (!LoadPreferences(mq::internal_paths::MQini))
	{
		DebugSpewAlways("ParseINIFile returned false - initialization aborted.");
		return false;
	}

	CrashHandler_Startup();

	InitializePluginHandle();

	pDetourAPI = new MQDetourAPI();
	pCommandAPI = new MQCommandAPI();

	// These two sub-systems will get us onto the main thread.
	InitializeMQ2Pulse();

	// We will wait for pulse from the game to init on main thread.
	return g_loadComplete.wait();
}

void MacroQuest::InitializeLogging()
{
	fs::path loggingPath = mq::internal_paths::Logs;

	auto new_logger = std::make_shared<spdlog::logger>("MQ");

	if (IsDebuggerPresent())
	{
		new_logger->sinks().push_back(std::make_shared<spdlog::sinks::msvc_sink_mt>(false));
	}

	fmt::memory_buffer filename;
	auto out = fmt::format_to(fmt::appender(filename),
		"{}\\{}", mq::internal_paths::Logs, mq::CreateLogFilename("MacroQuest"));
	*out = 0;

	// Create file sink
	try
	{
		auto fileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(filename.data(), true);
		new_logger->sinks().push_back(fileSink);
	}
	catch (const spdlog::spdlog_ex& ex)
	{
		SPDLOG_WARN("Failed to create file logger: {}, ex: {}",
			std::string_view(filename.data(), filename.size()), ex.what());
	}

	m_logger = new_logger;
	spdlog::set_default_logger(new_logger);

	m_eqlibLogger = std::make_shared<spdlog::logger>("EQLib", begin(m_logger->sinks()), end(m_logger->sinks()));
	spdlog::register_logger(m_eqlibLogger);

#if LOG_FILENAMES
	spdlog::set_pattern("%L %Y-%m-%d %T.%f [%n] %v (%@)");
#else
	spdlog::set_pattern("%L %Y-%m-%d %T.%f [%n] %v");
#endif
	spdlog::flush_on(spdlog::level::trace);
	spdlog::set_level(spdlog::level::trace);

	SPDLOG_DEBUG("Logging Initialized");
}

bool MacroQuest::InitializeEQLib()
{
	eqlib::LibraryConfig config;
	config.flags = eqlib::ConfigFlags::EnableAllEvents;
	config.eventReceiver = this;
	config.logger = m_eqlibLogger;

	m_eqlib = eqlib::Initialize(&config);
	return m_eqlib != nullptr;
}

void DoMainThreadInitialization();

bool MacroQuest::FirstFrameInitialize()
{
	// initialize main thread id
	dwMainThreadId = ::GetCurrentThreadId();

	// MainImpl::DoMainThreadInitialization()
	pDataAPI = new MQDataAPI();
	pDataAPI->Initialize();

	pActorAPI = new MQActorAPI();

	DoMainThreadInitialization();

	return true;
}

void MacroQuest::Shutdown()
{
	DoMainThreadShutdown();

	delete pDataAPI;
	pDataAPI = nullptr;

	delete pActorAPI;
	pActorAPI = nullptr;

	delete pDetourAPI;
	pDetourAPI = nullptr;

	eqlib::Shutdown(m_eqlib);
	m_eqlib = nullptr;

	spdlog::shutdown();

	DebugSpew("Shutdown completed");
}

void MacroQuest::OnProcessFrame()
{
	if (!m_initializedFirstFrame)
	{
		FirstFrameInitialize();

		m_initializedFirstFrame = true;
	}
	else if (gbUnload)
	{
		gbUnload = false;

		WriteChatColor(UnloadedString, USERCOLOR_DEFAULT);
		DebugSpewAlways("%s", UnloadedString);

		// cant unload these here there are detours still in use that call functions from plugins...
		//UnloadMQ2Plugins();

		DoMainThreadShutdown();

		m_initializedFirstFrame = false;
		g_unloadComplete.SetEvent();
	}
	else
	{
		Heartbeat();
	}
}

void MacroQuest::OnGameStateChanged(int newGameState)
{
	MQScopedBenchmark bm(bmPluginsSetGameState);

	PluginsSetGameState(newGameState);
}

void MacroQuest::OnLoginFrontendEntered()
{
	
}

void MacroQuest::OnLoginFrontendExited()
{

}

void MacroQuest::OnReloadUI(const eqlib::ReloadUIParams& params)
{
	MQScopedBenchmark bm(bmPluginsReloadUI);

	if (params.fastReload)
	{
		//gDrawWindowFrameSkipCount = 2;
	}

	PluginsReloadUI();
}

void MacroQuest::OnCleanUI()
{
	MQScopedBenchmark bm(bmPluginsCleanUI);
	PluginsCleanUI();
}

void MacroQuest::OnPreZoneUI()
{
	PluginsBeginZone();
}

void MacroQuest::OnPostZoneUI()
{
	PluginsEndZone();
}

bool MacroQuest::OnChatMessage(eqlib::ChatMessageParams& params)
{
	return false;
}

bool MacroQuest::OnTellWindowMessage(eqlib::TellWindowMessageParams& params)
{
	return false;
}

bool MacroQuest::OnIncomingWorldMessage(eqlib::IncomingWorldMessageParams& params)
{
	return false;
}

void MacroQuest::OnSpawnAdded(eqlib::PlayerClient* player)
{
	PluginsAddSpawn(player);
}

void MacroQuest::OnSpawnRemoved(eqlib::PlayerClient* player)
{
	PluginsRemoveSpawn(player);
}

void MacroQuest::OnGroundItemAdded(eqlib::EQGroundItem* groundItem)
{
	PluginsAddGroundItem(groundItem);
}

void MacroQuest::OnGroundItemRemoved(eqlib::EQGroundItem* groundItem)
{
	PluginsRemoveGroundItem(groundItem);
}


bool MacroQuest::LoadPreferences(const std::string& iniFile)
{
	char szBuffer[MAX_STRING] = { 0 };

	// TODO: Break these out per feature

	gFilterSkillsAll = GetPrivateProfileBool("MacroQuest", "FilterSkills", gFilterSkillsAll, iniFile);
	gFilterSkillsIncrease = 2 == GetPrivateProfileInt("MacroQuest", "FilterSkills", gFilterSkillsIncrease ? 2 : 0, iniFile);
	if (gbWriteAllConfig)
	{
		if (gFilterSkillsAll && gFilterSkillsIncrease)
			WritePrivateProfileInt("MacroQuest", "FilterSkills", 2, iniFile);
		else
			WritePrivateProfileBool("MacroQuest", "FilterSkills", gFilterSkillsAll, iniFile);
	}

	gFilterDebug = GetPrivateProfileBool("MacroQuest", "FilterDebug", gFilterDebug, iniFile);
	gFilterMQ2DataErrors = GetPrivateProfileBool("MacroQuest", "FilterMQ2Data", gFilterMQ2DataErrors, iniFile);
	gFilterTarget = GetPrivateProfileBool("MacroQuest", "FilterTarget", gFilterTarget, iniFile);
	gFilterMoney = GetPrivateProfileBool("MacroQuest", "FilterMoney", gFilterMoney, iniFile);
	gFilterFood = GetPrivateProfileBool("MacroQuest", "FilterFood", gFilterFood, iniFile);
	gFilterMacro = (eFilterMacro)GetPrivateProfileInt("MacroQuest", "FilterMacro", gFilterMacro, iniFile);
	gFilterEncumber = GetPrivateProfileBool("MacroQuest", "FilterEncumber", gFilterEncumber, iniFile);
	gFilterCustom = GetPrivateProfileBool("MacroQuest", "FilterCustom", gFilterCustom, iniFile);
	gSpewToFile = GetPrivateProfileBool("MacroQuest", "DebugSpewToFile", gSpewToFile, iniFile);
	gMQPauseOnChat = GetPrivateProfileBool("MacroQuest", "MQPauseOnChat", gMQPauseOnChat, iniFile);
	gKeepKeys = GetPrivateProfileBool("MacroQuest", "KeepKeys", gKeepKeys, iniFile);
	bAllErrorsDumpStack = GetPrivateProfileBool("MacroQuest", "AllErrorsDumpStack", bAllErrorsDumpStack, iniFile);
	bAllErrorsFatal = GetPrivateProfileBool("MacroQuest", "AllErrorsFatal", bAllErrorsFatal, iniFile);
	gbMQ2LoadingMsg = GetPrivateProfileBool("MacroQuest", "MQ2LoadingMsg", gbMQ2LoadingMsg, iniFile);
	gbExactSearchCleanNames = GetPrivateProfileBool("MacroQuest", "ExactSearchCleanNames", gbExactSearchCleanNames, iniFile);
	gUseTradeOnTarget = GetPrivateProfileBool("MacroQuest", "UseTradeOnTarget", gUseTradeOnTarget, iniFile);
	gbBeepOnTells = GetPrivateProfileBool("MacroQuest", "BeepOnTells", gbBeepOnTells, iniFile);
	gbFlashOnTells = GetPrivateProfileBool("MacroQuest", "FlashOnTells", gbFlashOnTells, iniFile);
	gbIgnoreAlertRecursion = GetPrivateProfileBool("MacroQuest", "IgnoreAlertRecursion", gbIgnoreAlertRecursion, iniFile);
	gbShowCurrentCamera = GetPrivateProfileBool("MacroQuest", "ShowCurrentCamera", gbShowCurrentCamera, iniFile);
	gTurboLimit = GetPrivateProfileInt("MacroQuest", "TurboLimit", gTurboLimit, iniFile);
	gCreateMQ2NewsWindow = GetPrivateProfileBool("MacroQuest", "CreateMQ2NewsWindow", gCreateMQ2NewsWindow, iniFile);
	gNetStatusXPos = GetPrivateProfileInt("MacroQuest", "NetStatusXPos", gNetStatusXPos, iniFile);
	gNetStatusYPos = GetPrivateProfileInt("MacroQuest", "NetStatusYPos", gNetStatusYPos, iniFile);
	gStackingDebug = (eStackingDebug)GetPrivateProfileInt("MacroQuest", "BuffStackDebugMode", gStackingDebug, iniFile);
	gUseNewNamedTest = GetPrivateProfileBool("MacroQuest", "UseNewNamedTest", gUseNewNamedTest, iniFile);
	gParserVersion = GetPrivateProfileInt("MacroQuest", "ParserEngine", gParserVersion, iniFile); // 2 = new parser, everything else = old parser
	gIfDelimiter = GetPrivateProfileString("MacroQuest", "IfDelimiter", std::string(1, gIfDelimiter), iniFile)[0];
	gIfAltDelimiter = GetPrivateProfileString("MacroQuest", "IfAltDelimiter", std::string(1, gIfAltDelimiter), iniFile)[0];
#if HAS_CHAT_TIMESTAMPS
	gbTimeStampChat = GetPrivateProfileBool("MacroQuest", "TimeStampChat", gbTimeStampChat, iniFile);
#endif

	if (gbWriteAllConfig)
	{
		WritePrivateProfileBool("MacroQuest", "FilterDebug", gFilterDebug, iniFile);
		WritePrivateProfileBool("MacroQuest", "FilterMQ2Data", gFilterMQ2DataErrors, iniFile);
		WritePrivateProfileBool("MacroQuest", "FilterTarget", gFilterTarget, iniFile);
		WritePrivateProfileBool("MacroQuest", "FilterMoney", gFilterMoney, iniFile);
		WritePrivateProfileBool("MacroQuest", "FilterFood", gFilterFood, iniFile);
		WritePrivateProfileBool("MacroQuest", "FilterMacro", gFilterMacro, iniFile);
		WritePrivateProfileBool("MacroQuest", "FilterEncumber", gFilterEncumber, iniFile);
		WritePrivateProfileBool("MacroQuest", "FilterCustom", gFilterCustom, iniFile);
		WritePrivateProfileBool("MacroQuest", "DebugSpewToFile", gSpewToFile, iniFile);
		WritePrivateProfileBool("MacroQuest", "MQPauseOnChat", gMQPauseOnChat, iniFile);
		WritePrivateProfileBool("MacroQuest", "KeepKeys", gKeepKeys, iniFile);
		WritePrivateProfileBool("MacroQuest", "AllErrorsDumpStack", bAllErrorsDumpStack, iniFile);
		WritePrivateProfileBool("MacroQuest", "AllErrorsFatal", bAllErrorsFatal, iniFile);
		WritePrivateProfileBool("MacroQuest", "MQ2LoadingMsg", gbMQ2LoadingMsg, iniFile);
		WritePrivateProfileBool("MacroQuest", "ExactSearchCleanNames", gbExactSearchCleanNames, iniFile);
		WritePrivateProfileBool("MacroQuest", "UseTradeOnTarget", gUseTradeOnTarget, iniFile);
		WritePrivateProfileBool("MacroQuest", "BeepOnTells", gbBeepOnTells, iniFile);
		WritePrivateProfileBool("MacroQuest", "FlashOnTells", gbFlashOnTells, iniFile);
		WritePrivateProfileBool("MacroQuest", "IgnoreAlertRecursion", gbIgnoreAlertRecursion, iniFile);
		WritePrivateProfileBool("MacroQuest", "ShowCurrentCamera", gbShowCurrentCamera, iniFile);
		WritePrivateProfileInt("MacroQuest", "TurboLimit", gTurboLimit, iniFile);
		WritePrivateProfileBool("MacroQuest", "CreateMQ2NewsWindow", gCreateMQ2NewsWindow, iniFile);
		WritePrivateProfileInt("MacroQuest", "NetStatusXPos", gNetStatusXPos, iniFile);
		WritePrivateProfileInt("MacroQuest", "NetStatusYPos", gNetStatusYPos, iniFile);
		WritePrivateProfileInt("MacroQuest", "BuffStackDebugMode", gStackingDebug, iniFile);
		WritePrivateProfileBool("MacroQuest", "UseNewNamedTest", gUseNewNamedTest, iniFile);
		WritePrivateProfileInt("MacroQuest", "ParserEngine", gParserVersion, iniFile);
		WritePrivateProfileString("MacroQuest", "IfDelimiter", std::string(1, gIfDelimiter), iniFile);
		WritePrivateProfileString("MacroQuest", "IfAltDelimiter", std::string(1, gIfAltDelimiter), iniFile);
#if HAS_CHAT_TIMESTAMPS
		WritePrivateProfileBool("MacroQuest", "TimeStampChat", gbTimeStampChat, iniFile);
#endif

	}

	GetPrivateProfileString("MacroQuest", "HUDMode", "UnderUI", szBuffer, MAX_STRING, iniFile);

	if (ci_equals(szBuffer, "normal"))
	{
		gbAlwaysDrawMQHUD = false;
		gbHUDUnderUI = false;
	}
	else
	{
		if (ci_equals(szBuffer, "always"))
		{
			gbAlwaysDrawMQHUD = true;
			gbHUDUnderUI = true;
		}
		else
		{
			strcpy_s(szBuffer, "UnderUI");
			gbAlwaysDrawMQHUD = false;
			gbHUDUnderUI = true;
		}
	}

	if (gbWriteAllConfig)
		WritePrivateProfileString("MacroQuest", "HUDMode", szBuffer, iniFile);

	gFilterSWho.Lastname = GetPrivateProfileBool("SWho Filter", "Lastname", gFilterSWho.Lastname, iniFile);
	gFilterSWho.Class = GetPrivateProfileBool("SWho Filter", "Class", gFilterSWho.Class, iniFile);
	gFilterSWho.Race = GetPrivateProfileBool("SWho Filter", "Race", gFilterSWho.Race, iniFile);
	gFilterSWho.Level = GetPrivateProfileBool("SWho Filter", "Level", gFilterSWho.Level, iniFile);
	gFilterSWho.GM = GetPrivateProfileBool("SWho Filter", "GM", gFilterSWho.GM, iniFile);
	gFilterSWho.Guild = GetPrivateProfileBool("SWho Filter", "Guild", gFilterSWho.Guild, iniFile);
	gFilterSWho.Sneak = GetPrivateProfileBool("SWho Filter", "Sneak", gFilterSWho.Sneak, iniFile);
	gFilterSWho.LD = GetPrivateProfileBool("SWho Filter", "LD", gFilterSWho.LD, iniFile);
	gFilterSWho.LFG = GetPrivateProfileBool("SWho Filter", "LFG", gFilterSWho.LFG, iniFile);
	gFilterSWho.NPCTag = GetPrivateProfileBool("SWho Filter", "NPCTag", gFilterSWho.NPCTag, iniFile);
	gFilterSWho.Trader = GetPrivateProfileBool("SWho Filter", "Trader", gFilterSWho.Trader, iniFile);
	gFilterSWho.AFK = GetPrivateProfileBool("SWho Filter", "AFK", gFilterSWho.AFK, iniFile);
	gFilterSWho.Anon = GetPrivateProfileBool("SWho Filter", "Anon", gFilterSWho.Anon, iniFile);
	gFilterSWho.Distance = GetPrivateProfileBool("SWho Filter", "Distance", gFilterSWho.Distance, iniFile);
	gFilterSWho.Light = GetPrivateProfileBool("SWho Filter", "Light", gFilterSWho.Light, iniFile);
	gFilterSWho.Body = GetPrivateProfileBool("SWho Filter", "Body", gFilterSWho.Body, iniFile);
	gFilterSWho.SpawnID = GetPrivateProfileBool("SWho Filter", "SpawnID", gFilterSWho.SpawnID, iniFile);
	gFilterSWho.Holding = GetPrivateProfileBool("SWho Filter", "Holding", gFilterSWho.Holding, iniFile);
	gFilterSWho.ConColor = GetPrivateProfileBool("SWho Filter", "ConColor", gFilterSWho.ConColor, iniFile);
	gFilterSWho.Invisible = GetPrivateProfileBool("SWho Filter", "Invisible", gFilterSWho.Invisible, iniFile);

	if (gbWriteAllConfig)
	{
		WritePrivateProfileBool("SWho Filter", "Lastname", gFilterSWho.Lastname, iniFile);
		WritePrivateProfileBool("SWho Filter", "Class", gFilterSWho.Class, iniFile);
		WritePrivateProfileBool("SWho Filter", "Race", gFilterSWho.Race, iniFile);
		WritePrivateProfileBool("SWho Filter", "Level", gFilterSWho.Level, iniFile);
		WritePrivateProfileBool("SWho Filter", "GM", gFilterSWho.GM, iniFile);
		WritePrivateProfileBool("SWho Filter", "Guild", gFilterSWho.Guild, iniFile);
		WritePrivateProfileBool("SWho Filter", "Sneak", gFilterSWho.Sneak, iniFile);
		WritePrivateProfileBool("SWho Filter", "LD", gFilterSWho.LD, iniFile);
		WritePrivateProfileBool("SWho Filter", "LFG", gFilterSWho.LFG, iniFile);
		WritePrivateProfileBool("SWho Filter", "NPCTag", gFilterSWho.NPCTag, iniFile);
		WritePrivateProfileBool("SWho Filter", "Trader", gFilterSWho.Trader, iniFile);
		WritePrivateProfileBool("SWho Filter", "AFK", gFilterSWho.AFK, iniFile);
		WritePrivateProfileBool("SWho Filter", "Anon", gFilterSWho.Anon, iniFile);
		WritePrivateProfileBool("SWho Filter", "Distance", gFilterSWho.Distance, iniFile);
		WritePrivateProfileBool("SWho Filter", "Light", gFilterSWho.Light, iniFile);
		WritePrivateProfileBool("SWho Filter", "Body", gFilterSWho.Body, iniFile);
		WritePrivateProfileBool("SWho Filter", "SpawnID", gFilterSWho.SpawnID, iniFile);
		WritePrivateProfileBool("SWho Filter", "Holding", gFilterSWho.Holding, iniFile);
		WritePrivateProfileBool("SWho Filter", "ConColor", gFilterSWho.ConColor, iniFile);
		WritePrivateProfileBool("SWho Filter", "Invisible", gFilterSWho.Invisible, iniFile);
	}

	DefaultFilters();

	// TODO:  Add a function that gets map for a section?
	char FilterList[MAX_STRING * 10] = { 0 };
	GetPrivateProfileString("Filter Names", "", "", FilterList, MAX_STRING * 10, iniFile);

	char* pFilterList = FilterList;
	if (pFilterList[0] == '\0' && gbWriteAllConfig)
	{
		WritePrivateProfileString("Filter Names", "Example", "NOBODY", iniFile);
	}
	while (pFilterList[0] != '\0')
	{
		std::string filter = GetPrivateProfileString("Filter Names", pFilterList, "", iniFile);

		if (!filter.empty() && filter != "NOBODY")
		{
			AddFilter(filter.c_str(), -1, gFilterCustom);
		}

		pFilterList += strlen(pFilterList) + 1;
	}

	const fs::path itemDBPath = fs::path(mq::internal_paths::Resources) / "ItemDB.txt";
	std::error_code ec_exists;
	if (fs::exists(itemDBPath, ec_exists))
	{
		// Backwards compatibility prior to deprecation
#pragma warning(suppress: 4996) // temporarily disable deprecation warnings.
		strcpy_s(gszItemDB, itemDBPath.string().c_str());

		std::ifstream itemDB(itemDBPath);
		std::string itemDBLineStr;
		while (std::getline(itemDB, itemDBLineStr))
		{
			std::string_view itemDBLine = itemDBLineStr;
			size_t firstTab = itemDBLine.find('\t');
			size_t lastTab = itemDBLine.rfind('\t');

			if (firstTab != std::string::npos && lastTab != std::string::npos)
			{
				int itemID = GetIntFromString(itemDBLine.substr(0, firstTab), 0);
				int stackQTY = GetIntFromString(itemDBLine.substr(firstTab + 1, lastTab - firstTab), 0);
				std::string_view itemName = itemDBLine.substr(lastTab + 1);
				if (itemID != 0)
				{
					if (ITEMDB* Item = new ITEMDB())
					{
						Item->pNext = gItemDB;
						Item->ID = itemID;
						Item->StackSize = stackQTY;
						strncpy_s(Item->szName, itemName.data(), itemName.length());
						gItemDB = Item;
					}
				}
				else
				{
					std::string strMessage = fmt::format("Failed to parse ItemDB. Check the data at {}", itemDBPath.string());
					MessageBox(nullptr, strMessage.c_str(), "MacroQuest", MB_OK);
					break;
				}
			}
			else
			{
				std::string strMessage = fmt::format("Unexpected Data in ItemDB. Check the format at {}", itemDBPath.string());
				MessageBox(nullptr, strMessage.c_str(), "MacroQuest", MB_OK);
				break;
			}
		}
	}

	return true;
}

//=================================================================================================
//=================================================================================================
//=================================================================================================

#pragma region MainInterface implementation

/**
 * MainInterface implementation - forwards calls to respective API implementations
 */

// DataAPI functions

bool MacroQuest::AddTopLevelObject(const char* name, MQTopLevelObjectFunction callback, const MQPluginHandle& pluginHandle)
{
	return pDataAPI->AddTopLevelObject(name, std::move(callback), pluginHandle);
}

bool MacroQuest::RemoveTopLevelObject(const char* name, const MQPluginHandle& pluginHandle)
{
	return pDataAPI->RemoveTopLevelObject(name, pluginHandle);
}

MQTopLevelObject* MacroQuest::FindTopLevelObject(const char* name)
{
	return pDataAPI->FindTopLevelObject(name);
}

// ActorAPI functions

void MacroQuest::SendToActor(postoffice::Dropbox* dropbox, const postoffice::Address& address, const std::string& data,
	const postoffice::ResponseCallbackAPI& callback, const MQPluginHandle& pluginHandle)
{
	pActorAPI->SendToActor(dropbox, address, data, callback, pluginHandle);
}

void MacroQuest::ReplyToActor(postoffice::Dropbox* dropbox, const std::shared_ptr<postoffice::Message>& message,
	const std::string& data, uint8_t status, const MQPluginHandle& pluginHandle)
{
	pActorAPI->ReplyToActor(dropbox, message, data, status, pluginHandle);
}

postoffice::Dropbox* MacroQuest::AddActor(const char* localAddress, postoffice::ReceiveCallbackAPI&& receive,
	const MQPluginHandle& pluginHandle)
{
	return pActorAPI->AddActor(localAddress, std::move(receive), pluginHandle);
}

void MacroQuest::RemoveActor(postoffice::Dropbox*& dropbox, const MQPluginHandle& pluginHandle)
{
	pActorAPI->RemoveActor(dropbox, pluginHandle);
}

// CommandAPI functions

bool MacroQuest::AddCommand(std::string_view command, MQCommandHandler handler, bool eq, bool parse, bool inGame, const MQPluginHandle& pluginHandle)
{
	return pCommandAPI->AddCommand(command, handler, eq, parse, inGame, pluginHandle);
}

bool MacroQuest::RemoveCommand(std::string_view command, const MQPluginHandle& pluginHandle)
{
	return pCommandAPI->RemoveCommand(command, pluginHandle);
}

bool MacroQuest::IsCommand(std::string_view command) const
{
	return pCommandAPI->IsCommand(command);
}

void MacroQuest::DoCommand(const char* command, bool delayed, const MQPluginHandle& pluginHandle)
{
	pCommandAPI->DoCommand(command, delayed, pluginHandle);
}

void MacroQuest::TimedCommand(const char* command, int msDelay, const MQPluginHandle& pluginHandle)
{
	pCommandAPI->TimedCommand(command, msDelay, pluginHandle);
}

bool MacroQuest::AddAlias(const std::string& shortCommand, const std::string& longCommand, bool persist, const MQPluginHandle& pluginHandle)
{
	return pCommandAPI->AddAlias(shortCommand, longCommand, persist, pluginHandle);
}

bool MacroQuest::RemoveAlias(const std::string& shortCommand, const MQPluginHandle& pluginHandle)
{
	return pCommandAPI->RemoveAlias(shortCommand, pluginHandle);
}

bool MacroQuest::IsAlias(const std::string& alias) const
{
	return pCommandAPI->IsAlias(alias);
}

// DetourAPI functions

bool MacroQuest::CreateDetour(uintptr_t address, void** target, void* detour, std::string_view name, const MQPluginHandle& pluginHandle)
{
	return pDetourAPI->CreateDetour(address, target, detour, name, pluginHandle);
}

bool MacroQuest::CreateDetour(uintptr_t address, size_t width, std::string_view name, const MQPluginHandle& pluginHandle)
{
	return pDetourAPI->CreateDetour(address, width, name, pluginHandle);
}

bool MacroQuest::RemoveDetour(uintptr_t address, const MQPluginHandle& pluginHandle)
{
	return pDetourAPI->RemoveDetour(address, pluginHandle);
}

#pragma endregion

//=================================================================================================
//=================================================================================================

static std::string GetModuleDirectory()
{
	static char szDirectoryName[MAX_STRING] = { 0 };

	if (szDirectoryName[0] != 0)
	{
		return szDirectoryName;
	}

	// Get path to the dll and strip off the filename
	::GetModuleFileNameA(ghModule, szDirectoryName, MAX_STRING);

	char* szProcessName = strrchr(szDirectoryName, '\\');
	szProcessName[0] = '\0';

	return szDirectoryName;
}

/**
 * Initialization point immediately after injection. Thread will persist until unload is requested,
 * and then will wait for unload to complete. When thread exits, it will unload the library.
 * 
 * @param lpParameter Pointer to MQInjectStartupParams
 * @return 
 */
static DWORD WINAPI MacroQuestBackgroundThread(void* lpParameter)
{
	std::unique_ptr<MQStartupParams> params(static_cast<MQStartupParams*>(lpParameter));

	if (params->backgroundThread)
	{
		ghModule = (HMODULE)params->hModule;
		ghInstance = (HINSTANCE)params->hModule;
		ghInjectorWnd = FindWindowA(MacroQuestWinClassName, MacroQuestWinName);
	}

	InstallUnhandledExceptionFilter();

	// Renderdoc requires very early startup which needs the MQRoot directory, so set
	// a provisional MQRoot and start up RenderDoc integration.
	mq::internal_paths::MQRoot = GetModuleDirectory();
	RenderDoc_Startup();

	g_loadComplete.create(wil::EventOptions::ManualReset);
	g_unloadComplete.create(wil::EventOptions::ManualReset);

	g_mq = new MacroQuest();

	// Initialize will block until the first frame is handled.
	if (g_mq->Initialize())
	{
		DebugSpewAlways("%s", "MacroQuest Loaded.");

		// Wait for unload to complete
		g_unloadComplete.wait();
	}
	else
	{
		::MessageBoxA(nullptr, "Failed to Initialize MQ.", "MQ Error", MB_OK);
	}

	UninstallUnhandledExceptionFilter();

	FreeLibraryAndExitThread(ghModule, 0);
}

extern "C" BOOL APIENTRY DllMain(HANDLE hModule, DWORD ul_reason_for_call, void* lpReserved)
{
	if (ul_reason_for_call != DLL_PROCESS_ATTACH && ul_reason_for_call != DLL_PROCESS_DETACH)
	{
		return true;
	}

	char szFilename[MAX_STRING] = { 0 };
	::GetModuleFileNameA(nullptr, szFilename, MAX_STRING);

	char* szProcessName = strrchr(szFilename, '.');
	szProcessName[0] = '\0';
	szProcessName = strrchr(szFilename, '\\') + 1;

	if (_stricmp(szProcessName, "eqgame") == 0)
	{
		if (ul_reason_for_call == DLL_PROCESS_ATTACH)
		{
			::SetDllDirectoryA(nullptr);

			MQStartupParams* startupParams = new MQStartupParams();
			startupParams->hModule = hModule;
			startupParams->backgroundThread = true;

			s_backgroundThread = ::CreateThread(nullptr, 0, MacroQuestBackgroundThread, startupParams, 0, &ThreadID);
		}
		else if (ul_reason_for_call == DLL_PROCESS_DETACH)
		{
			// This entire block can probably be removed. Every time I've tested this, the thread has already been
			// destroyed by the operating system, or we're in a call to FreeLibraryAndExitThread from unloading already.
			gbUnload = true;

			if (s_backgroundThread)
			{
				WaitForSingleObject(s_backgroundThread, 1000);
				CloseHandle(s_backgroundThread);
			}

			return TRUE;
		}
	}

	return TRUE;
}

MainInterface* GetMainInterface()
{
	return g_mq;
}

} // namespace mq

#if __has_include("../private/MQ2Main-private.cpp")
#include "../private/MQ2Main-private.cpp"
#endif
