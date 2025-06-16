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

#include "MQPluginHandler.h"

#include "ModuleSystem.h"

#include "mq/base/Logging.h"

#include "eqlib/MemoryPatcher.h"
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
#include <random>

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

namespace mqplugin
{
	mq::MQPluginHandle ThisPluginHandle;   // our unique handle for Main.
}

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

// Forward declare our modules
#define MODULE(x) \
	class x; \
	extern std::unique_ptr<MQModuleBase> CreateModule_##x();

#include "ModuleList.inl"

#undef MODULE

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

static std::vector<std::function<void()>> s_queuedEvents;
static std::recursive_mutex s_queuedEventMutex;

void PostToMainThread(std::function<void()>&& callback)
{
	std::scoped_lock lock(s_queuedEventMutex);

	s_queuedEvents.push_back(std::move(callback));
}

static void ProcessQueuedEvents()
{
	std::unique_lock lock(s_queuedEventMutex);

	if (s_queuedEvents.empty())
		return;

	std::vector<std::function<void()>> events;
	events.swap(s_queuedEvents);

	lock.unlock();

	for (auto& ev : events)
		std::invoke(ev);
}

struct MacroQuest::ScopedIteratingModules
{
	ScopedIteratingModules(MacroQuest* mq)
		: m_mq(mq)
	{
		++m_mq->m_iteratingModules;
	}

	~ScopedIteratingModules()
	{
		if (--m_mq->m_iteratingModules == 0 && (!m_mq->m_pendingWork.empty() || !m_mq->m_pendingModuleAdds.empty()))
		{
			m_mq->HandlePendingWork();
		}
	}

private:
	MacroQuest* m_mq;
};

/**
 * Immediately upon startup, make sure we've allowed enough time for InnerSpace/Lavish software to
 * inject and set up its hooks, so that we can come in after them. If we go before, we may lose our
 * hooks and fail to function properly.
 */
static void WaitForLavishSoftware()
{
	// IsBoxer/InnerSpace
	HMODULE hISModule = ::GetModuleHandleA("InnerSpace.dll");
	if (!hISModule)
	{
		// Joe MultiBoxer / WinEQ2022
		hISModule = ::GetModuleHandleA("JMB.dll");
	}
	if (!hISModule)
	{
		// WinEQ?
		hISModule = ::GetModuleHandleA("Lavish.dll");
	}
	if (hISModule)
	{
		uintptr_t baseAddressLS = 0;
		uintptr_t endAddress = 0;

		MODULEINFO moduleInfo;
		HMODULE hKernelModule = ::GetModuleHandleA("kernel32.dll");

		if (hISModule
			&& ::K32GetModuleInformation(GetCurrentProcess(), hISModule, &moduleInfo, sizeof(MODULEINFO)))
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

//=================================================================================================

MQModuleBase::MQModuleBase(std::string_view name, int priority, ModuleFlags flags)
	: m_priority(priority)
	, m_name(name)
	, m_flags(flags)
{
}

//=================================================================================================

MQDynamicModule::MQDynamicModule(std::string_view name, HMODULE hModule, ModuleFlags flags)
	: MQModuleBase(std::move(name), static_cast<int>(ModulePriority::Plugins), flags)
	, m_hModule(hModule)
{
}

MQDynamicModule::~MQDynamicModule()
{
}

//=================================================================================================

class MQDummyModule : public MQModuleBase
{
public:
	MQDummyModule(std::string_view name, int priority)
		: MQModuleBase(std::move(name), priority, ModuleFlags::IsDummy | ModuleFlags::SkipAll)
	{
	}
};

//=================================================================================================
//=================================================================================================

MacroQuest::MacroQuest(HMODULE hModule)
	: MQDynamicModule("main", hModule, ModuleFlags::Hidden)
{
	srand(static_cast<uint32_t>(time(nullptr)));

#if HAS_DIRECTX_11
	// Special case for RenderDoc integration - this has to go before anything else to give RenderDoc
	// the earliest chance to inject. Especially before we wait for lavishsoft stuff.
	AddModule(CreateModule<RenderDocModule>());
#endif
}

MacroQuest::~MacroQuest()
{
}

bool MacroQuest::CoreInitialize()
{
	WaitForLavishSoftware();

	DebugSpew("Expected Client version: %s %s", __ExpectedVersionDate, __ExpectedVersionTime);
	DebugSpew("    Real Client version: %s %s", eqlib::__ActualVersionDate, eqlib::__ActualVersionTime);

	const char* actualVersionDate = (const char*)eqlib::__ActualVersionDate;
	const char* actualVersionTime = (const char*)eqlib::__ActualVersionTime;

	// note: CLIENT_OVERRIDE is always #defined as 1 or 0
#if !CLIENT_OVERRIDE
	if (strncmp(__ExpectedVersionDate, actualVersionDate, strlen(__ExpectedVersionDate))
		|| strncmp(__ExpectedVersionTime, actualVersionTime, strlen(__ExpectedVersionTime)))
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

	m_memoryPatcher = m_eqlib->GetMemoryPatcher();

	// Construct our module handle
	mqplugin::ThisPluginHandle = CreateModuleHandle();
	m_handle = mqplugin::ThisPluginHandle;

	m_plugin.name = m_name;
	m_plugin.hModule = m_hModule;

	char szFilename[MAX_STRING] = {};
	::GetModuleFileNameA(m_hModule, szFilename, MAX_STRING);

	char* szModuleName = strrchr(szFilename, '.');
	szModuleName[0] = '\0';
	strcpy_s(m_plugin.szFilename, strrchr(szFilename, '\\') + 1);
	m_moduleHandleMap.emplace(m_handle.pluginID, static_cast<MQModuleBase*>(this));

	// We will wait for pulse from the game to init on main thread.
	return g_loadComplete.wait();
}

void MacroQuest::CoreShutdown()
{
	// We get called on the injection thread. The modules should have already been
	// shutdown on the main thread (or never initialized).
	assert(m_initializedModules == false);

	eqlib::Shutdown(m_eqlib);
	m_eqlib = nullptr;

	spdlog::shutdown();

	DebugSpew("Shutdown completed");
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

//=================================================================================================

void MacroQuest::Initialize()
{
	// initialize main thread id
	dwMainThreadId = ::GetCurrentThreadId();

	// UI Exists if we're in any of the ingame states.
	m_createdUI = gGameState >= eqlib::GAMESTATE_CHARSELECT && gGameState <= eqlib::GAMESTATE_INGAME;

	// This will populate our list of modules, but we won't initialize them yet.
	LoadModules();

	// Ok now initialize everything
	InitializeModules();

	m_initializedFirstFrame = true;
	g_loadComplete.SetEvent();
}

void MacroQuest::Shutdown()
{
	gbUnload = false;
	m_shuttingDown = true;

	WriteChatColor(UnloadedString, USERCOLOR_DEFAULT);
	DebugSpewAlways("%s", UnloadedString);

	ShutdownModules();

	m_initializedFirstFrame = false;
	g_unloadComplete.SetEvent();
}

//============================================================================
//============================================================================

void MacroQuest::LoadModules()
{
	// Register our modules
#define MODULE(x) AddModule(CreateModule<x>());
#include "ModuleList.inl"
#undef MODULE
}

void MacroQuest::AddModule(std::unique_ptr<MQModuleBase> module)
{
	if (m_shuttingDown)
	{
		SPDLOG_DEBUG("AddModule ignored: shutting down! module={}", module->GetName());
		return;
	}

	if (m_iteratingModules)
	{
		SPDLOG_DEBUG("AddModule deferred: module={}", module->GetName());

		m_pendingModuleAdds.push_back(std::move(module));
	}
	else
	{
		MQModuleBase* m = module.get();

		m->m_handle = CreateModuleHandle();

		SPDLOG_DEBUG("AddModule: module={} handle={}", module->GetName(), module->GetHandle().pluginID);

		// Insert module into m_modules in order sorted by priority. Lowest priority values go first.
		auto it = std::lower_bound(m_modules.begin(), m_modules.end(), m,
			[](const std::unique_ptr<MQModuleBase>& a, const MQModuleBase* b)
			{ return a->GetPriority() < b->GetPriority(); });

		m_modules.emplace(it, std::move(module));
		m_moduleHandleMap[m->m_handle.pluginID] = m;

		if (m_initializedModules)
		{
			InitializeModule(m);
		}
	}
}

std::unique_ptr<MQModuleBase> MacroQuest::RemoveModule(MQPluginHandle handle)
{
	if (handle.pluginID == 0)
		return nullptr;

	SPDLOG_DEBUG("RemoveModule: handle={}", handle.pluginID);

	// check if module is still in the list of pending adds. Removing it from here means
	// it hasn't been initialized yet, so we don't need to shut it down.
	{
		auto iter = std::find_if(m_pendingModuleAdds.begin(), m_pendingModuleAdds.end(),
			[handle](const std::unique_ptr<MQModuleBase>& module) { return module->GetHandle() == handle; });
		if (iter != m_pendingModuleAdds.end())
		{
			std::unique_ptr<MQModuleBase> module = std::move(*iter);
			m_pendingModuleAdds.erase(iter);

			SPDLOG_DEBUG("RemoveModule: module removed from pending list. handle={} module={}", handle.pluginID, module->GetName());

			return module;
		}
	}

	// Check main list of loaded modules
	auto iter = m_moduleHandleMap.find(handle.pluginID);
	if (iter != m_moduleHandleMap.end())
	{
		auto iter2 = std::find_if(m_modules.begin(), m_modules.end(),
			[handle](const std::unique_ptr<MQModuleBase>& module) { return module->GetHandle() == handle; });

		if (iter2 != m_modules.end())
		{
			if (m_shuttingDown)
			{
				SPDLOG_DEBUG("RemoveModule ignored: shutting down! module={}", (*iter2)->GetName());
				return nullptr;
			}

			SPDLOG_DEBUG("RemoveModule: handle={} module={}", handle.pluginID, (*iter2)->GetName());

			// Before we actually move the module from the list, give other modules an opportunity to do any last actions with it.
			OnBeforeModuleUnloaded(iter2->get());

			std::unique_ptr<MQModuleBase> module = std::move(*iter2);

			// We need to remove this module from the list before we issue callbacks, or it'll end up notifying itself
			// of shutdown events.
			//
			// If we're iterating modules, we can't remove it from the list now. Instead, we will swap it with a dummy module,
			// which won't interfere with the shutdown process. After we leave the module list, we can remove the dummy.

			if (m_iteratingModules)
			{
				std::unique_ptr<MQModuleBase> dummyModule = std::make_unique<MQDummyModule>(module->GetName(), module->GetPriority());
				*iter2 = std::move(dummyModule);

				SPDLOG_DEBUG("RemoveModule: module swapped with dummy");

				m_pendingWork.push_back([this]()
					{
						// Remove the dummy
						auto dummyIter = std::find_if(m_modules.begin(), m_modules.end(),
							[](const std::unique_ptr<MQModuleBase>& module) { return !!(module->GetFlags() & ModuleFlags::IsDummy); });
						if (dummyIter != m_modules.end())
						{
							SPDLOG_DEBUG("RemoveModule: removing dummy module for {}", (*dummyIter)->GetName());

							m_modules.erase(dummyIter);
						}
					});
			}
			else
			{
				m_modules.erase(iter2);
			}

			ShutdownModule(module.get());

			// This is safe to remove now.
			m_moduleHandleMap.erase(iter);

			return module;
		}
		
		// This is safe to remove now.
		m_moduleHandleMap.erase(iter);
	}

	return nullptr;
}

MQPluginHandle MacroQuest::CreateModuleHandle()
{
	static std::mt19937_64 rng(std::random_device{}());

	// Generate plugin ID
	uint64_t pluginID = 0;

	std::uniform_int_distribution<uint64_t> dist(0, std::numeric_limits<uint64_t>::max());

	do
	{
		pluginID = dist(rng);
	} while (m_moduleHandleMap.count(pluginID) != 0);

	return MQPluginHandle(pluginID);
}

MQModuleBase* MacroQuest::GetModuleByHandle(MQPluginHandle handle, bool noMain /* = false */) const
{
	if (handle.pluginID == 0)
		return nullptr;

	if (noMain && handle == mqplugin::ThisPluginHandle)
		return nullptr;

	auto iter = m_moduleHandleMap.find(handle.pluginID);
	return iter == m_moduleHandleMap.end() ? nullptr : iter->second;
}

void MacroQuest::InitializeModules()
{
	if (m_initializedModules)
		return;

	bmWriteChatColor = AddBenchmark("WriteChatColor");
	bmPluginsIncomingChat = AddBenchmark("PluginsIncomingChat");
	bmPluginsPulse = AddBenchmark("PluginsPulse");
	bmPluginsOnZoned = AddBenchmark("PluginsOnZoned");
	bmPluginsCleanUI = AddBenchmark("PluginsCleanUI");
	bmPluginsReloadUI = AddBenchmark("PluginsReloadUI");
	bmPluginsDrawHUD = AddBenchmark("PluginsDrawHUD");
	bmPluginsSetGameState = AddBenchmark("PluginsSetGameState");
	bmBeginZone = AddBenchmark("BeginZone");
	bmEndZone = AddBenchmark("EndZone");
	bmPluginsUpdateImGui = AddBenchmark("PluginsUpdateImGui");

	// Why is this here?
	bmCalculate = AddBenchmark("Calculate");

	{
		// Any modules that are loaded while we're within this scope will be deferred until
		// after we leave the scope, but before we leave the function.
		ScopedIteratingModules s(this);

		SPDLOG_DEBUG("Initializing modules");

		for (const auto& module : m_modules)
		{
			InitializeModule(module.get());
		}

		// Any modules that were added from inside InitializeModules will be added,
		// and this will ensure they are also initialized before we leave
		m_initializedModules = true;
	}

	SPDLOG_DEBUG("Module initialization complete");
}

void MacroQuest::InitializeModule(MQModuleBase* module)
{
	SPDLOG_DEBUG("InitializeModule: module={}", module->GetName());

	module->Initialize();
	module->OnGameStateChanged(gGameState);

	if (m_loginEntered)
	{
		module->OnLoginFrontendEntered();
	}

	if (m_createdUI)
	{
		eqlib::ReloadUIParams params;
		params.loadIni = true;
		params.fastReload = false;

		module->OnReloadUI(params);
	}

	if (gGameState == eqlib::GAMESTATE_INGAME)
	{
		if (!(module->GetFlags() & ModuleFlags::SkipOnSpawnAdded))
		{
			// init spawns
			eqlib::PlayerClient* pSpawn = eqlib::pSpawnList;
			while (pSpawn)
			{
				module->OnSpawnAdded(pSpawn);

				pSpawn = pSpawn->GetNext();
			}
		}

		if (!(module->GetFlags() & ModuleFlags::SkipOnGroundItemAdded))
		{
			// init ground items
			eqlib::EQGroundItem* pItem = eqlib::pItemList->Top;
			while (pItem)
			{
				module->OnGroundItemAdded(pItem);

				pItem = pItem->pNext;
			}
		}
	}

	OnModuleLoaded(module);

	SPDLOG_DEBUG("InitializeModule completed: module={}", module->GetName());
}

void MacroQuest::ShutdownModules()
{
	if (!m_initializedModules)
		return;

	SPDLOG_DEBUG("Shutdown modules: count={}", m_modules.size());

	// Iterate over modules in reverse order to gracefully shut everything down.
	// We do it without using iterators so we can safely remove stuff from the list.
	while (!m_modules.empty())
	{
		// Call OnBeforeModuleUnloaded while the module is still in the list.
		OnBeforeModuleUnloaded(m_modules.back().get());

		// Remove it from the list then shut it down.
		std::unique_ptr<MQModuleBase> module = std::move(m_modules.back());
		m_modules.pop_back();

		ShutdownModule(module.get());

		// Module is destroyed by leaving scope.
	}

	SPDLOG_DEBUG("Done shutting down modules");

	m_pendingModuleAdds.clear();
	m_pendingWork.clear();
	m_moduleHandleMap.clear();

	m_initializedModules = false;
}

void MacroQuest::ShutdownModule(MQModuleBase* module)
{
	SPDLOG_DEBUG("ShutdownModule: module={}", module->GetName());

	if (m_createdUI)
	{
		module->OnCleanUI();
	}

	if (m_loginEntered)
	{
		module->OnLoginFrontendExited();
	}

	module->Shutdown();

	OnAfterModuleUnloaded(module);

	SPDLOG_DEBUG("ShutdownModule completed: module={}", module->GetName());
}

void MacroQuest::HandlePendingWork()
{
	if (!m_pendingWork.empty())
	{
		SPDLOG_DEBUG("Handle pending work: {} callbacks", m_pendingWork.size());

		decltype(m_pendingWork) callbacks;
		std::swap(callbacks, m_pendingWork);

		for (const auto& work : callbacks)
		{
			work();
		}
	}

	if (!m_pendingModuleAdds.empty())
	{
		SPDLOG_DEBUG("Handle pending module adds: {} modules", m_pendingModuleAdds.size());

		decltype(m_pendingModuleAdds) modules;
		std::swap(modules, m_pendingModuleAdds);

		for (auto&& ptr : modules)
		{
			AddModule(std::move(ptr));
		}
	}
}

//============================================================================
//============================================================================

void MacroQuest::OnProcessFrame()
{
	if (m_shuttingDown)
		return;

	if (!m_initializedFirstFrame)
	{
		Initialize();
	}
	else if (gbUnload)
	{
		Shutdown();
	}
	else
	{
		ProcessQueuedEvents();

		if (!m_initializedModules)
			return;

		if (eqlib::pLocalPlayer != m_lastPlayer
			&& m_zoningInProgress
			&& !gZoning)
		{
			m_zoningInProgress = false;
			m_lastPlayer = eqlib::pLocalPlayer;

			OnZoned();
		}

		ScopedIteratingModules s(this);
		MQScopedBenchmark bm(bmPluginsPulse);

		for (const auto& module : m_modules)
		{
			if (+(module->GetFlags() & ModuleFlags::SkipOnProcessFrame))
				continue;

			module->OnProcessFrame();
		}
	}
}

void MacroQuest::OnGameStateChanged(int newGameState)
{
	switch (newGameState)
	{
	case eqlib::GAMESTATE_INGAME:
		gZoning = false;
		[[fallthrough]];
	case eqlib::GAMESTATE_CHARSELECT:
	case eqlib::GAMESTATE_CHARCREATE:
		gbInZone = true;
		break;

	default:
		gbInZone = false;
	}

	gGameState = newGameState;

	ScopedIteratingModules s(this);
	SPDLOG_DEBUG("OnGameStateChanged gameState={}", newGameState);

	for (const auto& module : m_modules)
	{
		module->OnGameStateChanged(newGameState);
	}
}

void MacroQuest::OnLoginFrontendEntered()
{
	m_loginEntered = true;

	if (!m_initializedModules)
		return;

	ScopedIteratingModules s(this);
	SPDLOG_DEBUG("OnLoginFrontendEntered");

	for (const auto& module : m_modules)
	{
		module->OnLoginFrontendEntered();
	}
}

void MacroQuest::OnLoginFrontendExited()
{
	m_loginEntered = false;

	if (!m_initializedModules)
		return;

	ScopedIteratingModules s(this);
	SPDLOG_DEBUG("OnLoginFrontendExited");

	for (const auto& module : m_modules)
	{
		module->OnLoginFrontendEntered();
	}
}

void MacroQuest::OnReloadUI(const eqlib::ReloadUIParams& params)
{
	MQScopedBenchmark bm(bmPluginsReloadUI);

	ScopedIteratingModules s(this);
	SPDLOG_DEBUG("OnReloadUI loadIni={} fastReload={}", params.loadIni, params.fastReload);

	m_createdUI = true;

	for (const auto& module : m_modules)
	{
		module->OnReloadUI(params);
	}
}

void MacroQuest::OnCleanUI()
{
	MQScopedBenchmark bm(bmPluginsCleanUI);

	ScopedIteratingModules s(this);
	SPDLOG_DEBUG("OnCleanUI");

	for (const auto& module : m_modules)
	{
		module->OnCleanUI();
	}

	m_createdUI = false;
}

void MacroQuest::OnPreZoneUI()
{
	gbInZone = false;
	gZoning = true;

	ScopedIteratingModules s(this);
	SPDLOG_DEBUG("OnPreZoneUI");

	for (const auto& module : m_modules)
	{
		module->OnPreZoneUI();
	}
}

void MacroQuest::OnPostZoneUI()
{
	// update zoning states
	gbInZone = true;
	gZoning = false;
	m_zoningInProgress = true;
	LastEnteredZone = MQGetTickCount64();

	ScopedIteratingModules s(this);
	SPDLOG_DEBUG("OnPostZoneUI");

	for (const auto& module : m_modules)
	{
		module->OnPostZoneUI();
	}
}

bool MacroQuest::OnChatMessage(eqlib::ChatMessageParams& params)
{
	bool result = true;

	ScopedIteratingModules s(this);

	for (const auto& module : m_modules)
	{
		if (+(module->GetFlags() & ModuleFlags::SkipOnChatMessage))
			continue;

		result = result && module->OnChatMessage(params);
	}

	return result;
}

bool MacroQuest::OnTellWindowMessage(eqlib::TellWindowMessageParams& params)
{
	bool result = true;

	ScopedIteratingModules s(this);

	for (const auto& module : m_modules)
	{
		if (+(module->GetFlags() & ModuleFlags::SkipOnTellWindowMessage))
			continue;

		result = result && module->OnTellWindowMessage(params);
	}

	return result;
}

bool MacroQuest::OnIncomingWorldMessage(eqlib::IncomingWorldMessageParams& params)
{
	bool result = true;

	ScopedIteratingModules s(this);

	for (const auto& module : m_modules)
	{
		if (+(module->GetFlags() & ModuleFlags::SkipOnIncomingWorldMessage))
			continue;

		result = result && module->OnIncomingWorldMessage(params);
	}

	return result;
}

void MacroQuest::OnSpawnAdded(eqlib::PlayerClient* player)
{
	ScopedIteratingModules s(this);

	for (const auto& module : m_modules)
	{
		module->OnSpawnAdded(player);
	}
}

void MacroQuest::OnSpawnRemoved(eqlib::PlayerClient* player)
{
	ScopedIteratingModules s(this);

	for (const auto& module : m_modules)
	{
		module->OnSpawnRemoved(player);
	}
}

void MacroQuest::OnGroundItemAdded(eqlib::EQGroundItem* groundItem)
{
	ScopedIteratingModules s(this);

	for (const auto& module : m_modules)
	{
		module->OnGroundItemAdded(groundItem);
	}
}

void MacroQuest::OnGroundItemRemoved(eqlib::EQGroundItem* groundItem)
{
	ScopedIteratingModules s(this);

	for (const auto& module : m_modules)
	{
		module->OnGroundItemRemoved(groundItem);
	}
}

void MacroQuest::OnWriteChatColor(const char* message, int color, int filter)
{
	if (gFilterMQ)
		return;

	MQScopedBenchmark bm(bmWriteChatColor);

	if (size_t len = strlen(message))
	{
		std::unique_ptr<char[]> plainText = std::make_unique<char[]>(len + 1);

		StripMQChat(message, plainText.get());
		CheckChatForEvent(plainText.get());
	}

	ScopedIteratingModules s(this);

	for (const auto& module : m_modules)
	{
		if (+(module->GetFlags() & ModuleFlags::SkipOnWriteChatColor))
			continue;

		module->OnWriteChatColor(message, color, filter);
	}
}

bool MacroQuest::OnIncomingChat(const char* message, int color)
{
	// Ignore empty messages
	if (message[0] == 0)
		return false;

	bool result = false;

	MQScopedBenchmark bm(bmPluginsIncomingChat);
	ScopedIteratingModules s(this);

	for (const auto& module : m_modules)
	{
		if (+(module->GetFlags() & ModuleFlags::SkipOnIncomingChat))
			continue;

		result = result || module->OnIncomingChat(message, color);
	}

	return result;
}

void MacroQuest::OnZoned()
{
	srand((unsigned int)time(nullptr)); // reseed

	char szTemp[128];
	sprintf_s(szTemp, "You have entered %s.", eqlib::pZoneInfo->LongName);

	CheckChatForEvent(szTemp);

	ScopedIteratingModules s(this);
	MQScopedBenchmark bm(bmPluginsOnZoned);

	for (const auto& module : m_modules)
	{
		module->OnZoned();
	}
}

void MacroQuest::OnDrawHUD()
{
	MQScopedBenchmark bm(bmPluginsDrawHUD);
	ScopedIteratingModules s(this);

	for (const auto& module : m_modules)
	{
		if (+(module->GetFlags() & ModuleFlags::SkipOnDrawHUD))
			continue;

		module->OnDrawHUD();
	}
}

void MacroQuest::OnModuleLoaded(MQModuleBase* otherModule)
{
	ScopedIteratingModules s(this);

	SPDLOG_DEBUG("OnModuleLoaded: module={}", otherModule->GetName());

	for (const auto& module : m_modules)
	{
		module->OnModuleLoaded(otherModule);
	}
}

void MacroQuest::OnBeforeModuleUnloaded(MQModuleBase* otherModule)
{
	ScopedIteratingModules s(this);

	SPDLOG_DEBUG("OnBeforeModuleUnloaded: module={}", otherModule->GetName());

	for (const auto& module : m_modules)
	{
		module->OnBeforeModuleUnloaded(otherModule);
	}
}

void MacroQuest::OnAfterModuleUnloaded(MQModuleBase* otherModule)
{
	ScopedIteratingModules s(this);

	SPDLOG_DEBUG("OnAfterModuleUnloaded: module={}", otherModule->GetName());

	for (const auto& module : m_modules)
	{
		module->OnAfterModuleUnloaded(otherModule);
	}
}

void MacroQuest::OnMacroStart(const char* macroName)
{
	ScopedIteratingModules s(this);

	for (const auto& module : m_modules)
	{
		module->OnMacroStart(macroName);
	}
}

void MacroQuest::OnMacroStop(const char* macroName)
{
	ScopedIteratingModules s(this);

	for (const auto& module : m_modules)
	{
		module->OnMacroStop(macroName);
	}
}

void MacroQuest::HandlePipeMessage(PipeMessagePtr message)
{
	ScopedIteratingModules s(this);

	for (const auto& module: m_modules)
	{
		if (module->OnPipeMessage(message.get()))
			break;
	}
}

void MacroQuest::HandleUpdateImGui(bool internalOnly)
{
	MQScopedBenchmark bm(bmPluginsUpdateImGui);
	ScopedIteratingModules s(this);

	for (const auto& module : m_modules)
	{
		if (+(module->GetFlags() & ModuleFlags::SkipOnUpdateImGui))
			continue;

		if (internalOnly && +(module->GetFlags() & ModuleFlags::IsPlugin))
			continue;

		module->OnUpdateImGui();
	}
}

//============================================================================
//============================================================================

bool MacroQuest::LoadPreferences(const std::string& iniFile)
{
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
	gbExactSearchCleanNames = GetPrivateProfileBool("MacroQuest", "ExactSearchCleanNames", gbExactSearchCleanNames, iniFile);
	gUseTradeOnTarget = GetPrivateProfileBool("MacroQuest", "UseTradeOnTarget", gUseTradeOnTarget, iniFile);
	gbIgnoreAlertRecursion = GetPrivateProfileBool("MacroQuest", "IgnoreAlertRecursion", gbIgnoreAlertRecursion, iniFile);
	gTurboLimit = GetPrivateProfileInt("MacroQuest", "TurboLimit", gTurboLimit, iniFile);
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
		WritePrivateProfileBool("MacroQuest", "ExactSearchCleanNames", gbExactSearchCleanNames, iniFile);
		WritePrivateProfileBool("MacroQuest", "UseTradeOnTarget", gUseTradeOnTarget, iniFile);
		WritePrivateProfileBool("MacroQuest", "IgnoreAlertRecursion", gbIgnoreAlertRecursion, iniFile);
		WritePrivateProfileInt("MacroQuest", "TurboLimit", gTurboLimit, iniFile);
		WritePrivateProfileInt("MacroQuest", "BuffStackDebugMode", gStackingDebug, iniFile);
		WritePrivateProfileBool("MacroQuest", "UseNewNamedTest", gUseNewNamedTest, iniFile);
		WritePrivateProfileInt("MacroQuest", "ParserEngine", gParserVersion, iniFile);
		WritePrivateProfileString("MacroQuest", "IfDelimiter", std::string(1, gIfDelimiter), iniFile);
		WritePrivateProfileString("MacroQuest", "IfAltDelimiter", std::string(1, gIfAltDelimiter), iniFile);
#if HAS_CHAT_TIMESTAMPS
		WritePrivateProfileBool("MacroQuest", "TimeStampChat", gbTimeStampChat, iniFile);
#endif
	}

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

#pragma endregion

// DetourAPI functions
#pragma region Detour functions

bool MacroQuest::ValidateNewPatch(uintptr_t address, std::string_view name, const MQPluginHandle& pluginHandle) const
{
	eqlib::MemoryPatch* existingPatch = nullptr;

	if (m_memoryPatcher->FindPatches(address, eqlib::DETOUR_BYTES_COUNT, &existingPatch, 1) != 0)
	{
		if (pluginHandle == mqplugin::ThisPluginHandle || existingPatch->GetUserData() == 0)
			return false;

		MQPlugin* otherPlugin = GetPluginByHandle(MQPluginHandle{ existingPatch->GetUserData() });
		MQPlugin* thisPlugin = GetPluginByHandle(pluginHandle);

		if (existingPatch->GetAddress() == address)
		{
			SPDLOG_ERROR("Plugin \"{}\" tried to detour address 0x{:X} (\"{}\") but it already exists as another detour created by {}",
				thisPlugin->name, address, name, otherPlugin ? std::string_view(otherPlugin->name) : std::string_view("(NULL)"));
		}
		else
		{
			SPDLOG_ERROR("Plugin \"{}\" tried to detour address 0x{:X} (\"{}\") but it conflicts with another detour created by {}",
				thisPlugin->name, address, name, otherPlugin ? std::string_view(otherPlugin->name) : std::string_view("(NULL)"));
		}

		return false;
	}

	return true;
}

bool MacroQuest::CreateDetour(uintptr_t address, void** target, void* detour, std::string_view name, const MQPluginHandle& pluginHandle)
{
	if (!ValidateNewPatch(address, name, pluginHandle))
		return false;

	if (eqlib::MemoryPatch* memoryPatch = m_memoryPatcher->CreatePatch(address, target, detour, name))
	{
		m_memoryPatcher->SetUserData(memoryPatch, pluginHandle.pluginID);

		return true;
	}

	return false;
}

bool MacroQuest::CreateDetour(uintptr_t address, size_t width, std::string_view name, const MQPluginHandle& pluginHandle)
{
	if (!ValidateNewPatch(address, name, pluginHandle))
		return false;

	if (eqlib::MemoryPatch* memoryPatch = m_memoryPatcher->CreatePatch(address, width, name))
	{
		m_memoryPatcher->SetUserData(memoryPatch, pluginHandle.pluginID);

		return true;
	}

	return false;
}

bool MacroQuest::RemoveDetour(uintptr_t address, const MQPluginHandle& pluginHandle)
{
	eqlib::MemoryPatch* patch = m_memoryPatcher->GetPatch(address);

	if (!patch || patch->GetType() != eqlib::MemoryPatch::Type::Detour)
	{
		SPDLOG_WARN("Failed to remove detour at 0x{:X}: Detour not found", address);

		return false;
	}

	if (patch->GetUserData() != pluginHandle.pluginID)
	{
		if (patch->GetUserData() == 0)
		{
			SPDLOG_WARN("Failed to remove detour at 0x{:X}: Detour is owned by MQ", address);
		}
		else
		{
			MQPlugin* plugin = GetPluginByHandle(MQPluginHandle{ patch->GetUserData() });

			if (plugin)
			{
				SPDLOG_WARN("Failed to remove detour at 0x{:X}: Detour is owned by {}", address, plugin->name);
			}
			else
			{
				SPDLOG_WARN("Failed to remove detour at 0x{:X}: Detour is owned by an unknown plugin", address);
			}
		}
	}

	return m_memoryPatcher->RemovePatch(address);
}

std::vector<eqlib::MemoryPatch*> MacroQuest::FindPatches(uintptr_t address, size_t width)
{
	std::vector<eqlib::MemoryPatch*> result;
	uintptr_t endAddress = address + width;
	size_t offset = 0;

	// Ferry list of patches across dll boundary...
	constexpr uint32_t MAX_PER_ITERATION = 100;
	eqlib::MemoryPatch* patches[MAX_PER_ITERATION];

	uint32_t count = m_memoryPatcher->FindPatches(address, width, patches, MAX_PER_ITERATION);
	if (count == 0)
		return result;

	// Count is the total number of patches found, so we can resize as soon as we know.
	result.resize(count);

	// Now we iterate through results until we have all the patches.
	memcpy(result.data() + offset, patches, std::min(MAX_PER_ITERATION, count));

	while (count > MAX_PER_ITERATION)
	{
		offset += MAX_PER_ITERATION;

		address = result.back()->GetAddress() + result.back()->GetBytesSize();
		width = endAddress - address;

		count = m_memoryPatcher->FindPatches(address, width, patches, MAX_PER_ITERATION);

		memcpy(result.data() + offset, patches, std::min(MAX_PER_ITERATION, count));
	}

	return result;
}

bool MacroQuest::IsAddressPatched(uintptr_t address, size_t width)
{
	return m_memoryPatcher->IsAddressPatched(address, width);
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

	g_loadComplete.create(wil::EventOptions::ManualReset);
	g_unloadComplete.create(wil::EventOptions::ManualReset);

	g_mq = new MacroQuest(ghModule);

	// Initialize will block until the first frame is handled.
	if (g_mq->CoreInitialize())
	{
		DebugSpewAlways("%s", "MacroQuest Loaded.");

		// Wait for unload to complete
		g_unloadComplete.wait();
	}
	else
	{
		::MessageBoxA(nullptr, "Failed to Initialize MQ.", "MQ Error", MB_OK);
	}

	g_mq->CoreShutdown();

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

bool detail::CreateDetour(uintptr_t address, void** target, void* detour, std::string_view name)
{
	return g_mq->CreateDetour(address, target, detour, name, mqplugin::ThisPluginHandle);
}

bool detail::CreateDetour(uintptr_t address, size_t width, std::string_view name)
{
	return g_mq->CreateDetour(address, width, name, mqplugin::ThisPluginHandle);
}

bool RemoveDetour(uintptr_t address)
{
	return g_mq->RemoveDetour(address, mqplugin::ThisPluginHandle);
}


} // namespace mq

#if __has_include("../private/MQ2Main-private.cpp")
#include "../private/MQ2Main-private.cpp"
#endif
