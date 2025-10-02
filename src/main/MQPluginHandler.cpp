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
#include "Logging.h"

#include "mq/utils/OS.h"

#include <spdlog/spdlog.h>
#include <wil/resource.h>
#include <random>

#include "MQCommandAPI.h"

//#define DEBUG_PLUGINS


namespace mqplugin
{
	mq::MQPluginHandle ThisPluginHandle;   // our unique handle for Main.
}

namespace mq {

#ifdef DEBUG_PLUGINS
#define PluginDebug DebugSpew
#else
#define PluginDebug(...)
#endif

// This is the main plugin list. We use it to preserve some sort of order, thats about it.
MQPlugin* pPlugins = nullptr;

// This is a plugin entry for Main, but we don't fill its pointers.
MQPlugin MainPlugin;

static std::atomic_bool s_pluginsInitialized = false;
static std::recursive_mutex s_pluginsMutex;

struct PluginInfoRec
{
	MQPlugin* instance;
	MQPluginHandle handle;
};

// a map of plugin names to plugins. The string_view is a reference to the name in the
// MQPlugin instance.
using PluginMap = ci_unordered::map<std::string_view, PluginInfoRec>;
static PluginMap s_pluginMap;
static PluginMap s_pluginUnloadFailedMap;

using PluginHandleMap = std::unordered_map<uint64_t, MQPlugin*>;
static PluginHandleMap s_pluginHandleMap;

// String constant used to bake in the version of everquest when performing
// version checks against plugins.
static const char EverQuestVersion[] = __ExpectedVersionDate " " __ExpectedVersionTime;

// load failure string for reporting error message out of the plugin load command.
static std::string s_pluginLoadFailure;

//----------------------------------------------------------------------------

uint32_t bmWriteChatColor = 0;
uint32_t bmPluginsIncomingChat = 0;
uint32_t bmPluginsPulse = 0;
uint32_t bmPluginsOnZoned = 0;
uint32_t bmPluginsCleanUI = 0;
uint32_t bmPluginsReloadUI = 0;
uint32_t bmPluginsDrawHUD = 0;
uint32_t bmPluginsSetGameState = 0;
uint32_t bmCalculate = 0;
uint32_t bmBeginZone = 0;
uint32_t bmEndZone = 0;

//----------------------------------------------------------------------------
// If true, imgui should not run on plugins.
extern bool gbManualResetRequired;

// Defined in MQ2Utilities.cpp
DWORD CALLBACK InitializeMQ2SpellDb(void* pData);

extern std::set<HMODULE> g_knownModules;

//----------------------------------------------------------------------------
// Module handling
std::vector<MQModule*> gInternalModules;
static ModuleInitializer* s_moduleInitializerList = nullptr;

void InitializeInternalModules()
{
	ModuleInitializer* initializer = s_moduleInitializerList;

	while (initializer)
	{
		AddInternalModule(initializer->module);
		initializer = initializer->next;
	}
}

void AddStaticInitializationModule(ModuleInitializer* module)
{
	module->next = s_moduleInitializerList;
	s_moduleInitializerList = module;
}

void AddInternalModule(MQModule* module, bool manualUnload /*=false*/)
{
	LOG_DEBUG("Initializing module: {0}", module->name);

	gInternalModules.push_back(module);

	if (module->Initialize)
		module->Initialize();
	if (module->SetGameState)
		module->SetGameState(GetGameState());

	module->loaded = true;
	module->manualUnload = manualUnload;
}

void RemoveInternalModule(MQModule* module)
{
	auto iter = std::find(std::begin(gInternalModules),
		std::end(gInternalModules), module);
	if (iter == std::end(gInternalModules))
		return;

	gInternalModules.erase(iter);

	if (module->loaded && module->Shutdown)
	{
		module->Shutdown();
		module->loaded = false;
	}
}

void ShutdownInternalModules()
{
	auto modulesCopy = gInternalModules;

	for (auto iter = modulesCopy.rbegin(); iter != modulesCopy.rend(); ++iter)
	{
		auto mod = *iter;
		if (!mod->manualUnload)
		{
			RemoveInternalModule(mod);
		}
	}
}

static void PluginsLoadPlugin(const char* Name);
static void PluginsUnloadPlugin(const char* Name);
static void PluginsPostUnloadPlugin(const char* Name);

//----------------------------------------------------------------------------

bool IsPluginsInitialized()
{
	return s_pluginsInitialized;
}

MQPluginHandle CreatePluginHandle()
{
	static std::mt19937_64 rng(std::random_device{}());

	// Generate plugin ID
	uint64_t pluginID = 0;

	std::uniform_int_distribution<uint64_t> dist(0, std::numeric_limits<uint64_t>::max());

	do
	{
		pluginID = dist(rng);
	} while (s_pluginHandleMap.count(pluginID) != 0);

	return MQPluginHandle(pluginID);
}

// Strips MQ2/MQ off of the name and returns it back
std::string_view GetCanonicalPluginName(std::string_view name, bool stripExtension = true)
{
	if (stripExtension && name.length() >= 5)
	{
		if (name[name.length() - 4] == '.'
			&& (name[name.length() - 3] == 'd' || name[name.length() - 3] == 'D')
			&& (name[name.length() - 2] == 'l' || name[name.length() - 2] == 'L')
			&& (name[name.length() - 1] == 'l' || name[name.length() - 1] == 'L'))
		{
			name = name.substr(0, name.length() - 4);
		}
	}

	if (name.length() >= 2)
	{
		if ((name[0] == 'm' || name[0] == 'M')
			&& name[1] == 'q' || name[1] == 'Q')
		{
			name = name.substr(2);

			if (name.length() >= 1 && name[0] == '2')
				name = name.substr(1);
		}
	}

	// At this point we have a plugin name without the MQ[2]
	return name;
}

void PrintModules()
{
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, false, GetCurrentProcessId());
	if (hProcess)
	{
		HMODULE hMods[1024];
		DWORD cbNeeded;
		if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
		{
			for (unsigned int i = 0; i < (cbNeeded / sizeof(HMODULE)); ++i)
			{
				char szModName[MAX_PATH];
				if (GetModuleFileNameEx(hProcess, hMods[i], szModName, sizeof(szModName) / sizeof(char)))
				{
					WriteChatf("%s (0x%08X)", szModName, hMods[i]);
				}
			}
		}
	}
}

// Returns true if the plugin is loaded by checking its canonical name.
bool IsPluginLoaded(std::string_view name)
{
	return s_pluginMap.count(GetCanonicalPluginName(name)) != 0;
}

bool IsPluginUnloadFailed(std::string_view name)
{
	return s_pluginUnloadFailedMap.count(GetCanonicalPluginName(name)) != 0;
}

int GetPluginUnloadFailedCount()
{
	return static_cast<int>(s_pluginUnloadFailedMap.size());
}

MQPlugin* GetPlugin(std::string_view name)
{
	auto iter = s_pluginMap.find(GetCanonicalPluginName(name));
	return iter == s_pluginMap.end() ? nullptr : iter->second.instance;
}

PluginInfoRec* GetPluginInfoRec(std::string_view name)
{
	auto iter = s_pluginMap.find(GetCanonicalPluginName(name));
	return iter == s_pluginMap.end() ? nullptr : &iter->second;
}

MQPlugin* GetPluginByHandle(MQPluginHandle handle, bool noMain /* = false */)
{
	if (handle.pluginID == 0)
		return nullptr;

	if (noMain && handle == mqplugin::ThisPluginHandle)
		return nullptr;

	auto iter = s_pluginHandleMap.find(handle.pluginID);
	return iter == s_pluginHandleMap.end() ? nullptr : iter->second;
}

// Locate a plugin dll that matches the given name (canonical or otherwise).
std::string FindPluginFile(std::string_view name)
{
	namespace fs = std::filesystem;
	std::error_code ec;

	// Start with our search directory and plugin name
	fs::path pathToPlugins = fs::path(mq::internal_paths::Plugins);
	fs::path pluginName = name;
	pluginName.replace_extension(".dll");

	std::string_view canonicalName = GetCanonicalPluginName(name, false);
	bool isCanonical = (canonicalName == name);

	// If the plugin is not canonical, it means that we removed MQ2 or MQ. First check to see
	// if we have the exact match before we start making guesses.
	if (!isCanonical)
	{
		if (fs::is_regular_file(pathToPlugins / pluginName, ec))
			return pluginName.replace_extension().string();

		return {};
	}

	// Scan the directory looking for a match. We want this so that we can
	// get the casing that matches the filename.
	fs::directory_iterator directoryIterator(pathToPlugins, fs::directory_options::skip_permission_denied, ec);

	std::string checkName1 = fmt::format("MQ{}", pluginName.string());
	std::string checkName2 = fmt::format("MQ2{}", pluginName.string());

	for (const std::filesystem::directory_entry& dirEntry : directoryIterator)
	{
		// Only deal with files
		if (!dirEntry.is_regular_file(ec))
			continue;

		const std::filesystem::path& filePath = dirEntry.path();

		fs::path existingFile = filePath.filename();

		if (ci_equals(existingFile.string(), checkName1) || ci_equals(existingFile.string(), checkName2))
		{
			DebugSpew("Found non-exact plugin match: %.*s -> %s", name.length(), name.data(), existingFile.string().c_str());
			return existingFile.replace_extension().string();
		}
	}

	// didn't find a file that matches
	return {};
}

class ScopedModuleTracker
{
	struct TrackerData
	{
		std::set<HMODULE> modules;

		void Start();
		void Finish();
	};
	static inline TrackerData* s_activeTracker = nullptr;

public:
	ScopedModuleTracker()
	{
		if (s_activeTracker == nullptr)
		{
			s_activeTracker = &m_data;
			m_data.Start();
		}
	}

	~ScopedModuleTracker()
	{
		if (s_activeTracker == &m_data)
		{
			m_data.Finish();
			s_activeTracker = nullptr;
		}
	}

private:
	TrackerData m_data;
};

void ScopedModuleTracker::TrackerData::Start()
{
	::SetDllDirectoryA(gPathMQRoot);

	wil::unique_tool_help_snapshot hSnapshot(CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, GetCurrentProcessId()));
	if (!hSnapshot)
		return;

	MODULEENTRY32 me32 = { sizeof(MODULEENTRY32) };
	if (!Module32First(hSnapshot.get(), &me32))
		return;

	do {
		modules.insert(me32.hModule);
	} while (Module32Next(hSnapshot.get(), &me32));
}

void ScopedModuleTracker::TrackerData::Finish()
{
	::SetDllDirectoryA(nullptr);

	wil::unique_tool_help_snapshot hSnapshot(CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, GetCurrentProcessId()));
	if (!hSnapshot)
		return;

	MODULEENTRY32 me32 = { sizeof(MODULEENTRY32) };
	if (!Module32First(hSnapshot.get(), &me32))
		return;

	std::vector<HMODULE> newModules;
	do {
		if (modules.find(me32.hModule) == end(modules))
		{
			LOG_DEBUG("Module loaded: {}", me32.szExePath);
			newModules.push_back(me32.hModule);
		}
	} while (Module32Next(hSnapshot.get(), &me32));
}

static std::pair<wil::unique_hmodule, std::string> LoadPluginModule(std::string_view name)
{
	namespace fs = std::filesystem;

	// Our job here is to return the module handle if we found a plugin matching
	// the name requested. If we fail for whatever reason, we return a null hmodule
	// and set the reason in szPluginLoadFailure.

	DebugSpew("LoadPlugin(%.*s)", name.length(), name.data());

	std::string fileName = FindPluginFile(name);
	if (fileName.empty())
	{
		s_pluginLoadFailure = "Plugin not found";
		return {};
	}

	const fs::path pathToPlugin = fs::path(mq::internal_paths::Plugins) / fileName;

	wil::unique_hmodule hModule{ ::LoadLibraryA(pathToPlugin.string().c_str()) };
	if (!hModule)
	{
		DWORD lastError = ::GetLastError();
		char* szError = nullptr;

		FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			nullptr,
			lastError,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR)&szError,
			0,
			nullptr);

		s_pluginLoadFailure = fmt::format("LoadLibrary failed with error {:#08x}: {}", lastError, szError);
		return {};
	}

	// Perform MQNext version check
	void* isBuildForNext = GetProcAddress(hModule.get(), "IsBuiltForNext");
	if (isBuildForNext == nullptr)
	{
		s_pluginLoadFailure = "Plugin was not built for this version of MacroQuest";
		return {};
	}

	// Perform EQ version check
	const char* eqVersion = reinterpret_cast<const char*>(GetProcAddress(hModule.get(), "EverQuestVersion"));
	if (eqVersion == nullptr)
	{
		s_pluginLoadFailure = "Plugin was not built for this version of EverQuest";
		return {};
	}

	if (strcmp(eqVersion, EverQuestVersion) != 0)
	{
		s_pluginLoadFailure = fmt::format("Plugin was not built for this version of EverQuest (was built for {})",
			eqVersion);
		return {};
	}

	return { std::move(hModule), std::move(fileName) };
}

void AddPluginToList(MQPlugin* pPlugin)
{
	std::scoped_lock lock(s_pluginsMutex);

	// add to plugin list
	pPlugin->pLast = nullptr;
	pPlugin->pNext = pPlugins;
	if (pPlugins)
		pPlugins->pLast = pPlugin;
	pPlugins = pPlugin;
}

void RemovePluginFromList(MQPlugin* pPlugin)
{
	std::scoped_lock lock(s_pluginsMutex);

	// unlink from list
	if (pPlugin->pLast)
		pPlugin->pLast->pNext = pPlugin->pNext;
	else
		pPlugins = pPlugin->pNext;
	if (pPlugin->pNext)
		pPlugin->pNext->pLast = pPlugin->pLast;
}

// 0 - failed
// 1 - success
// 2 - already loaded
// 3 - previous load of plugin is still unloading
int LoadPlugin(std::string_view pluginName, bool save)
{
	// Clear the load error message;
	s_pluginLoadFailure.clear();

	if (IsPluginLoaded(pluginName))
	{
		DebugSpew("LoadPlugin(%.*s) already loaded", pluginName.length(), pluginName.data());
		s_pluginLoadFailure = "Plugin is already loaded";

		return 2;
	}

	if (IsPluginUnloadFailed(pluginName))
	{
		DebugSpew("LoadPlugin(%.*s) previous instance failed unload", pluginName.length(), pluginName.data());
		s_pluginLoadFailure = "Plugin failed unload from a previous instance, cannot load";

		return 3;
	}

	ScopedModuleTracker moduleTracker;

	auto [hModule, pluginPath] = LoadPluginModule(pluginName);
	if (!hModule)
	{
		// szPluginLoadFailure is set in LoadPluginModule
		DebugSpew("LoadPlugin(%.*s) failed: %s", pluginName.length(), pluginName.data(), s_pluginLoadFailure.c_str());
		return 0;
	}

	MQPlugin* pPlugin = new MQPlugin();
	PluginInfoRec rec;
	rec.instance = pPlugin;
	rec.handle = CreatePluginHandle();
	strcpy_s(pPlugin->szFilename, pluginPath.c_str());
	pPlugin->name              = std::string{ GetCanonicalPluginName(pluginPath) };
	pPlugin->hModule           = hModule.release();

	s_pluginHandleMap.emplace(rec.handle.pluginID, rec.instance);

	// Pass the plugin instance and handle to the plugin
	using InitPluginHandleFunc = void(*)(mq::MQPlugin*, mq::MQPluginHandle);

	auto initPluginFunc = reinterpret_cast<InitPluginHandleFunc>(GetProcAddress(pPlugin->hModule, "InitPluginHandle"));
	initPluginFunc(rec.instance, rec.handle);

	pPlugin->Initialize        = (fMQInitializePlugin)GetProcAddress(pPlugin->hModule, "InitializePlugin");
	pPlugin->Shutdown          = (fMQShutdownPlugin)GetProcAddress(pPlugin->hModule, "ShutdownPlugin");
	pPlugin->IncomingChat      = (fMQIncomingChat)GetProcAddress(pPlugin->hModule, "OnIncomingChat");
	pPlugin->Pulse             = (fMQPulse)GetProcAddress(pPlugin->hModule, "OnPulse");
	pPlugin->WriteChatColor    = (fMQWriteChatColor)GetProcAddress(pPlugin->hModule, "OnWriteChatColor");
	pPlugin->Zoned             = (fMQZoned)GetProcAddress(pPlugin->hModule, "OnZoned");
	pPlugin->CleanUI           = (fMQCleanUI)GetProcAddress(pPlugin->hModule, "OnCleanUI");
	pPlugin->ReloadUI          = (fMQReloadUI)GetProcAddress(pPlugin->hModule, "OnReloadUI");
	pPlugin->DrawHUD           = (fMQDrawHUD)GetProcAddress(pPlugin->hModule, "OnDrawHUD");
	pPlugin->SetGameState      = (fMQSetGameState)GetProcAddress(pPlugin->hModule, "SetGameState");
	pPlugin->AddSpawn          = (fMQSpawn)GetProcAddress(pPlugin->hModule, "OnAddSpawn");
	pPlugin->RemoveSpawn       = (fMQSpawn)GetProcAddress(pPlugin->hModule, "OnRemoveSpawn");
	pPlugin->AddGroundItem     = (fMQGroundItem)GetProcAddress(pPlugin->hModule, "OnAddGroundItem");
	pPlugin->RemoveGroundItem  = (fMQGroundItem)GetProcAddress(pPlugin->hModule, "OnRemoveGroundItem");
	pPlugin->BeginZone         = (fMQBeginZone)GetProcAddress(pPlugin->hModule, "OnBeginZone");
	pPlugin->EndZone           = (fMQEndZone)GetProcAddress(pPlugin->hModule, "OnEndZone");
	pPlugin->UpdateImGui       = (fMQUpdateImGui)GetProcAddress(pPlugin->hModule, "OnUpdateImGui");
	pPlugin->MacroStart        = (fMQMacroStart)GetProcAddress(pPlugin->hModule, "OnMacroStart");
	pPlugin->MacroStop         = (fMQMacroStop)GetProcAddress(pPlugin->hModule, "OnMacroStop");
	pPlugin->LoadPlugin        = (fMQLoadPlugin)GetProcAddress(pPlugin->hModule, "OnLoadPlugin");
	pPlugin->UnloadPlugin      = (fMQUnloadPlugin)GetProcAddress(pPlugin->hModule, "OnUnloadPlugin");
	pPlugin->GetPluginInterface = (fMQGetPluginInterface)GetProcAddress(pPlugin->hModule, "GetPluginInterface");
	pPlugin->OnPostUnloadPlugin = (fMQPostUnloadPlugin)GetProcAddress(pPlugin->hModule, "OnPostUnloadPlugin");

	float* ftmp = (float*)GetProcAddress(pPlugin->hModule, "?MQ2Version@@3MA");
	if (ftmp)
		pPlugin->fpVersion = *ftmp;
	else
		pPlugin->fpVersion = 1.0;

	// initialize plugin
	if (pPlugin->Initialize)
		pPlugin->Initialize();

	// init gamestate
	if (pPlugin->SetGameState)
		pPlugin->SetGameState(GetGameState());

	if (GetGameState() == GAMESTATE_INGAME)
	{
		// init spawns
		if (pPlugin->AddSpawn)
		{
			SPAWNINFO* pSpawn = pSpawnList;
			while (pSpawn)
			{
				pPlugin->AddSpawn(pSpawn);
				pSpawn = pSpawn->pNext;
			}
		}

		// init ground items
		if (pPlugin->AddGroundItem)
		{
			EQGroundItem* pItem = pItemList->Top;
			while (pItem)
			{
				pPlugin->AddGroundItem(pItem);
				pItem = pItem->pNext;
			}
		}
	}

	AddPluginToList(pPlugin);
	s_pluginMap.emplace(std::string_view(pPlugin->name), rec);

	// load cfg file if exists
	std::string autoExec = fmt::format("{}-AutoExec", pPlugin->szFilename);
	LoadCfgFile(autoExec.c_str(), false);

	PluginsLoadPlugin(pPlugin->szFilename);

	if (save)
	{
		WritePrivateProfileBool("Plugins", pPlugin->szFilename, true, mq::internal_paths::MQini);
	}
	return 1;
}

static void ShutdownPlugin(const PluginInfoRec& rec)
{
	MQPlugin* pPlugin = rec.instance;

	// call Plugin:CleanUI
	if (pPlugin->CleanUI)
		pPlugin->CleanUI();

	// call Plugin:Shutdown
	if (pPlugin->Shutdown)
		pPlugin->Shutdown();

	// Allow other plugins to cleanup resources after plugin shutdown but before the dll is freed
	PluginsPostUnloadPlugin(pPlugin->szFilename);

	// Perform any additional de-registration as required
	pCommandAPI->OnPluginUnloaded(pPlugin, rec.handle);
}

bool UnloadPlugin(std::string_view pluginName, bool save /* = false */)
{
	DebugSpew("UnloadPlugin(%.*s)", pluginName.length(), pluginName.data());

	// Clear the load error message;
	s_pluginLoadFailure.clear();

	PluginInfoRec rec;
	MQPlugin* pPlugin;
	std::string_view canonicalName = GetCanonicalPluginName(pluginName);

	if (save)
	{
		std::string pluginNameStr = std::string(pluginName);

		// Regardless of whether unload succeeds, turn it off in the ini if it exists.  This prevents a scenario where
		// a plugin failing to unload keeps it enabled in the ini despite the user trying to turn it off.
		if (PrivateProfileKeyExists("Plugins", pluginNameStr, mq::internal_paths::MQini))
		{
			WritePrivateProfileBool("Plugins", pluginNameStr, false, mq::internal_paths::MQini);
		}
	}

	if (IsPluginUnloadFailed(canonicalName))
	{
		auto iter = s_pluginUnloadFailedMap.find(canonicalName);
		// We know this exists because we just checked it, but in case that changes later...
		if (iter == s_pluginUnloadFailedMap.end())
			return false;

		rec = iter->second;
		pPlugin = rec.instance;

		s_pluginUnloadFailedMap.erase(iter);
	}
	else
	{
		auto iter = s_pluginMap.find(canonicalName);
		if (iter == s_pluginMap.end())
			return false;

		rec = iter->second;
		pPlugin = rec.instance;

		// Inform other plugins that this plugin is being removed
		PluginsUnloadPlugin(pPlugin->szFilename);

		// Remove it from the list so that it can no longer be accessed
		RemovePluginFromList(pPlugin);

		s_pluginMap.erase(iter);
		s_pluginHandleMap.erase(rec.handle.pluginID);
	}

	ShutdownPlugin(rec);

	// Cleanup
	if (FreeLibrary(pPlugin->hModule))
	{
		if (IsInModuleList(pPlugin->szFilename))
		{
			s_pluginLoadFailure = "Plugin files still loaded.";
			DebugSpew("UnloadPlugin(%s) failed: %.*s", s_pluginLoadFailure.c_str(), pluginName.length(), pluginName.data());

			s_pluginUnloadFailedMap.emplace(canonicalName, rec);
			return false;
		}
		delete pPlugin;
	}
	else
	{
		DWORD lastError = ::GetLastError();
		char* szError = nullptr;

		FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			nullptr,
			lastError,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR)&szError,
			0,
			nullptr);

		s_pluginLoadFailure = fmt::format("FreeLibrary failed with error {:#08x}: {}", lastError, szError);
		DebugSpew("UnloadPlugin(%s) failed: %.*s", pluginName.length(), pluginName.data(), s_pluginLoadFailure.c_str());

		s_pluginUnloadFailedMap.emplace(canonicalName, rec);
		return false;
	}

	return true;
}

void UnloadPlugins()
{
	while (pPlugins)
	{
		DebugSpew("%s->Unload()", pPlugins->szFilename);
		UnloadPlugin(pPlugins->szFilename);
	}
}

bool UnloadFailedPlugins()
{
	// UnloadPlugin modifies the global map, so use a copy here.
	const PluginMap pluginUnloadFailedCopy = s_pluginUnloadFailedMap;
	for (auto& [key, rec] : pluginUnloadFailedCopy)
	{
		DebugSpew("UnloadFailedPlugins(%s)", rec.instance->name.c_str());
		UnloadPlugin(rec.instance->szFilename);
	}

	return GetPluginUnloadFailedCount() == 0;
}

void ShutdownFailedPlugins()
{
	if (!UnloadFailedPlugins() && !gbForceUnload)
	{
		int msgReturn = IDRETRY;
		while (msgReturn == IDRETRY && !UnloadFailedPlugins())
		{
			msgReturn = MessageBox(nullptr,
				"You have plugins that failed to unload. Unloading MacroQuest now would be unsafe.\n"
				"\n"
				"RETRY to try unloading again.\n"
				"ABORT to kill the game.\n"
				"IGNORE to accept the risk and continue unloading.\n",
				"UNLOAD FAILURE", MB_ICONWARNING | MB_ABORTRETRYIGNORE);
		}

		if (msgReturn == IDABORT)
		{
			std::quick_exit(EXIT_FAILURE);
		}
	}
}

template <typename Callback>
void ForEachModule(Callback&& callback)
{
	for (const MQModule* module : gInternalModules)
	{
		callback(module);
	}
}

template <typename Callback>
void ForEachPlugin(Callback&& callback)
{
	std::scoped_lock lock(s_pluginsMutex);

	MQPlugin* pPlugin = pPlugins;
	while (pPlugin)
	{
		callback(pPlugin);

		pPlugin = pPlugin->pNext;
	}
}

void PluginsWriteChatColor(const char* Line, int Color, int Filter)
{
	if (!s_pluginsInitialized)
		return;
	if (gFilterMQ)
		return;

	//LOG_DEBUG("Begin WriteChatColor()");

	MQScopedBenchmark bm(bmWriteChatColor);

	if (size_t len = strlen(Line))
	{
		std::unique_ptr<char[]> plainText = std::make_unique<char[]>(len + 1);

		StripMQChat(Line, plainText.get());
		CheckChatForEvent(plainText.get());

		DebugSpew("WriteChatColor(%s)", Line);
	}

	ForEachModule([&](const MQModule* module)
		{
			if (module->WriteChatColor)
				module->WriteChatColor(Line, Color, Filter);
		});

	ForEachPlugin([&](const MQPlugin* plugin)
		{
			if (plugin->WriteChatColor)
				plugin->WriteChatColor(Line, Color, Filter);
		});
}

bool PluginsIncomingChat(const char* Line, uint32_t Color)
{
	if (!s_pluginsInitialized)
		return false;
	if (!Line[0])
		return false;

	PluginDebug("PluginsIncomingChat()");

	bool Ret = false;

	ForEachPlugin([&](const MQPlugin* plugin) mutable
		{
			if (plugin->IncomingChat)
				Ret = Ret || plugin->IncomingChat(Line, Color);
		});

	return Ret;
}

void PulsePlugins()
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PulsePlugins()");

	ForEachModule([](const MQModule* module)
		{
			if (module->Pulse)
				module->Pulse();
		});

	ForEachPlugin([](const MQPlugin* plugin)
		{
			if (plugin->Pulse)
				plugin->Pulse();
		});
}

void PluginsZoned()
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsZoned()");

	ForEachModule([](const MQModule* module)
		{
			if (module->Zoned)
				module->Zoned();
		});

	ForEachPlugin([](const MQPlugin* plugin)
		{
			if (plugin->Zoned)
			{
				DebugSpew("%s->Zoned()", plugin->szFilename);
				plugin->Zoned();
			}
		});


	char szTemp[128];
	sprintf_s(szTemp, "You have entered %s.", pZoneInfo->LongName);

	CheckChatForEvent(szTemp);
}

void PluginsCleanUI()
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsCleanUI()");

	DeleteMQ2NewsWindow();
	RemoveFindItemMenu();

	ForEachModule([](const MQModule* module)
		{
			if (module->CleanUI)
				module->CleanUI();
		});

	ForEachPlugin([](const MQPlugin* plugin)
		{
			if (plugin->CleanUI)
			{
				DebugSpew("%s->CleanUI()", plugin->szFilename);
				plugin->CleanUI();
			}
		});
}

void PluginsReloadUI()
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsReloadUI()");

	ForEachModule([](const MQModule* module)
		{
			if (module->CleanUI)
				module->ReloadUI();
		});

	ForEachPlugin([](const MQPlugin* plugin)
		{
			if (plugin->ReloadUI)
			{
				DebugSpew("%s->ReloadUI()", plugin->szFilename);
				plugin->ReloadUI();
			}
		});
}

void PluginsSetGameState(int GameState)
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsSetGameState()");

	static bool AutoExec = false;
	static bool CharSelect = true;

	DrawHUDParams[0] = 0;
	gGameState = GameState;

	if (GameState != GAMESTATE_INGAME && GameState != GAMESTATE_LOGGINGIN)
	{
		gbSpelldbLoaded = false;
		ghInitializeSpellDbThread = nullptr;
	}

	if (GameState == GAMESTATE_INGAME)
	{
		if (!gbSpelldbLoaded && ghInitializeSpellDbThread == nullptr)
		{
			ghInitializeSpellDbThread = CreateThread(nullptr, 0, InitializeMQ2SpellDb, nullptr, 0, nullptr);
		}

		gZoning = false;
		gbDoAutoRun = true;

		if (!AutoExec)
		{
			AutoExec = true;
			LoadCfgFile("AutoExec", false);
		}

		if (CharSelect)
		{
			CharSelect = false;
			char szBuffer[MAX_STRING] = { 0 };

			DebugSpew("PluginsSetGameState(%s server)", GetServerShortName());

			LoadCfgFile("InGame", false);

			if (pLocalPC)
			{
				DebugSpew("PluginsSetGameState(%s name)", pLocalPC->Name);

				sprintf_s(szBuffer, "%s_%s", GetServerShortName(), pLocalPC->Name);
				LoadCfgFile(szBuffer, false);
			}

			if (PcProfile* pProfile = GetPcProfile())
			{
				DebugSpew("PluginsSetGameState(%d class)", pProfile->Class);

				sprintf_s(szBuffer, "%s", GetClassDesc(pProfile->Class));
				LoadCfgFile(szBuffer, false);
			}
		}
	}
	else if (GameState == GAMESTATE_CHARSELECT)
	{
		if (!AutoExec)
		{
			AutoExec = true;
			LoadCfgFile("AutoExec", false);
		}
		CharSelect = true;
		LoadCfgFile("CharSelect", false);
	}

	ForEachModule([GameState](const MQModule* module)
		{
			if (module->SetGameState)
				module->SetGameState(GameState);
		});

	ForEachPlugin([GameState](const MQPlugin* plugin)
		{
			if (plugin->SetGameState)
			{
				DebugSpew("%s->SetGameState(%d)", plugin->szFilename, GameState);
				plugin->SetGameState(GameState);
			}
		});
}

void PluginsDrawHUD()
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsDrawHUD()");

	ForEachPlugin([](const MQPlugin* plugin)
		{
			if (plugin->DrawHUD)
				plugin->DrawHUD();
		});
}

void PluginsAddSpawn(PlayerClient* pNewSpawn)
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsAddSpawn(%s,%d,%d)", pNewSpawn->Name, pNewSpawn->GetRace());

	ForEachModule([pNewSpawn](const MQModule* module)
		{
			if (module->SpawnAdded)
				module->SpawnAdded(pNewSpawn);
		});

	ForEachPlugin([pNewSpawn](const MQPlugin* plugin)
		{
			if (plugin->AddSpawn)
				plugin->AddSpawn(pNewSpawn);
		});
}

void PluginsRemoveSpawn(PlayerClient* pSpawn)
{
	InvalidateObservedEQObject(pSpawn);

	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsRemoveSpawn(%s)", pSpawn->Name);

	ClearCachedBuffsSpawn(pSpawn);

	ForEachModule([pSpawn](const MQModule* module)
		{
			if (module->SpawnRemoved)
				module->SpawnRemoved(pSpawn);
		});

	ForEachPlugin([pSpawn](const MQPlugin* plugin)
		{
			if (plugin->RemoveSpawn)
				plugin->RemoveSpawn(pSpawn);
		});
}

void PluginsAddGroundItem(EQGroundItem* pNewGroundItem)
{
	if (!s_pluginsInitialized)
		return;
	if (!pNewGroundItem)
		return;

	DebugSpew("PluginsAddGroundItem(%s) %.1f,%.1f,%.1f", pNewGroundItem->Name, pNewGroundItem->X, pNewGroundItem->Y, pNewGroundItem->Z);

	ForEachPlugin([pNewGroundItem](const MQPlugin* plugin)
		{
			if (plugin->AddGroundItem)
				plugin->AddGroundItem(pNewGroundItem);
		});
}

void PluginsRemoveGroundItem(EQGroundItem* pGroundItem)
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsRemoveGroundItem()");

	ForEachPlugin([pGroundItem](const MQPlugin* plugin)
		{
			if (plugin->RemoveGroundItem)
				plugin->RemoveGroundItem(pGroundItem);
		});
}

void PluginsBeginZone()
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsBeginZone()");

	gbInZone = false;
	gZoning = true;

	ForEachModule([](const MQModule* module)
		{
			if (module->BeginZone)
				module->BeginZone();
		});

	ForEachPlugin([](const MQPlugin* plugin)
		{
			if (plugin->BeginZone)
			{
				DebugSpew("%s->BeginZone()", plugin->szFilename);
				plugin->BeginZone();
			}
		});
}

void PluginsEndZone()
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsEndZone()");

	gbInZone = true;
	WereWeZoning = true;
	LastEnteredZone = MQGetTickCount64();

	ForEachModule([](const MQModule* module)
		{
			if (module->EndZone)
				module->EndZone();
		});

	ForEachPlugin([](const MQPlugin* plugin)
		{
			if (plugin->EndZone)
			{
				DebugSpew("%s->EndZone()", plugin->szFilename);
				plugin->EndZone();
			}
		});

	if (GetGameState() == GAMESTATE_INGAME)
	{
		LoadCfgFile("zoned", true);
		LoadCfgFile(pZoneInfo->ShortName, false);
	}
}

void ModulesUpdateImGui()
{
	ForEachModule([](const MQModule* module)
		{
			if (module->UpdateImGui)
				module->UpdateImGui();
		});
}

void PluginsUpdateImGui()
{
	if (!s_pluginsInitialized)
		return;

	ForEachPlugin([](const MQPlugin* plugin)
		{
			if (plugin->UpdateImGui)
				plugin->UpdateImGui();
		});
}

void PluginsMacroStart(const char* Name)
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsMacroStart(%s)", Name);

	ForEachPlugin([Name](const MQPlugin* plugin)
		{
			if (plugin->MacroStart)
			{
				DebugSpew("%s->MacroStart(%s)", plugin->szFilename, Name);
				plugin->MacroStart(Name);
			}
		});
}

void PluginsMacroStop(const char* Name)
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsMacroStop(%s)", Name);

	ForEachPlugin([Name](const MQPlugin* plugin)
		{
			if (plugin->MacroStop)
			{
				DebugSpew("%s->MacroStop(%s)", plugin->szFilename, Name);
				plugin->MacroStop(Name);
			}
		});
}

static void PluginsLoadPlugin(const char* Name)
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsLoadPlugin(%s)", Name);

	ForEachPlugin([Name](const MQPlugin* plugin)
		{
			if (plugin->LoadPlugin)
			{
				DebugSpew("%s->LoadPlugin(%s)", plugin->szFilename, Name);
				plugin->LoadPlugin(Name);
			}
		});

	ForEachModule([Name](const MQModule* mod)
		{
			if (mod->LoadPlugin)
			{
				mod->LoadPlugin(Name);
			}
		});
}

static void PluginsUnloadPlugin(const char* Name)
{
	PluginDebug("PluginsUnloadPlugin(%s)", Name);

	ForEachPlugin([Name](const MQPlugin* plugin)
		{
			if (plugin->UnloadPlugin)
			{
				DebugSpew("%s->UnloadPlugin(%s)", plugin->szFilename, Name);
				plugin->UnloadPlugin(Name);
			}
		});

	ForEachModule([Name](const MQModule* mod)
		{
			if (mod->UnloadPlugin)
			{
				mod->UnloadPlugin(Name);
			}
		});
}

static void PluginsPostUnloadPlugin(const char* Name)
{
	PluginDebug("PluginsPostUnloadPlugin(%s)", Name);

	ForEachPlugin([Name](const MQPlugin* plugin)
		{
			if (plugin->OnPostUnloadPlugin)
			{
				DebugSpew("%s->OnPostUnloadPlugin(%s)", plugin->szFilename, Name);
				plugin->OnPostUnloadPlugin(Name);
			}
		});

	ForEachModule([Name](const MQModule* mod)
		{
			if (mod->OnPostUnloadPlugin)
			{
				mod->OnPostUnloadPlugin(Name);
			}
		});
}

void* GetPluginProc(const char* plugin, const char* proc)
{
	size_t uiLength = strlen(plugin) + 1;
	auto pLook = pPlugins;
	while (pLook)
	{
		if (!_strnicmp(plugin, pLook->szFilename, uiLength))
			return GetProcAddress(pLook->hModule, proc);
		pLook = pLook->pNext;
	}

	return nullptr;
}

PluginInterface* GetPluginInterface(std::string_view PluginName)
{
	if (MQPlugin* pPlugin = GetPlugin(PluginName))
	{
		if (pPlugin->GetPluginInterface)
			return pPlugin->GetPluginInterface();
	}

	return nullptr;
}

void PluginCommand(SPAWNINFO* pChar, char* szLine)
{
	bool show_usage = false;
	char szName[MAX_STRING] = { 0 };
	GetArg(szName, szLine, 1);

	char szCommand[MAX_STRING] = { 0 };
	GetArg(szCommand, szLine, 2);

	if (szName[0] == '\0')
	{
		show_usage = true;
	}
	else
	{
		if (!_stricmp(szName, "list"))
		{
			if (szCommand[0] == '\0' || ci_equals(szCommand, "active"))
			{
				MQPlugin* pLoop = pPlugins;
				int Count = 0;

				WriteChatColor("Active Plugins", USERCOLOR_WHO);
				WriteChatColor("-----------------------------", USERCOLOR_WHO);

				while (pLoop)
				{
					WriteChatColorf("%s", USERCOLOR_WHO, pLoop->szFilename);
					Count++;
					pLoop = pLoop->pNext;
				}

				if (Count == 0)
				{
					WriteChatColor("No Plugins defined.", USERCOLOR_WHO);
				}
				else
				{
					WriteChatColorf("%d Plugin%s displayed.", USERCOLOR_WHO, Count, (Count == 1) ? "" : "s");
				}
			}
			else if (ci_equals(szCommand, "failed"))
			{
				WriteChatColor("Plugins that Failed to Unload", USERCOLOR_WHO);
				WriteChatColor("-----------------------------", USERCOLOR_WHO);
				if (s_pluginUnloadFailedMap.empty())
				{
					WriteChatColor("No Failed Plugins.", USERCOLOR_WHO);
				}
				else
				{
					for (auto const& [key, rec] : s_pluginUnloadFailedMap)
					{
						WriteChatColorf("%s", USERCOLOR_WHO, rec.instance->szFilename);
					}
					WriteChatColorf("%d Plugin(s) displayed. To try to unload again use /plugin <pluginame> unload", USERCOLOR_WHO, s_pluginUnloadFailedMap.size());
				}
			}
			else if (ci_equals(szCommand, "dlls"))
			{
				PrintModules();
			}
			else
			{
				show_usage = true;
			}
		}
		else
		{
			bool dounload = false;
			bool noauto = false;

			// helps us check if this plugin is already loaded
			MQPlugin* plugin = GetPlugin(szName);

			if (szCommand[0] != '\0')
			{
				// /plugin MQStuff noauto
				if (ci_equals(szCommand, "noauto"))
				{
					noauto = true;
				}
				// /plugin MQStuff toggle [noauto]
				else if (ci_equals(szCommand, "toggle"))
				{
					dounload = (plugin != nullptr);
				}
				else if (ci_equals(szCommand, "unload"))
				{
					dounload = true;
				}
				// load is the default so if it's not any of the known keywords...
				else if (!ci_equals(szCommand, "load"))
				{
					show_usage = true;
				}
			}

			const char* szNoAuto = GetNextArg(szLine, 2);
			if (szNoAuto && szNoAuto[0] != '\0')
			{
				if (ci_equals(szNoAuto, "noauto"))
				{
					noauto = true;
				}
				else
				{
					show_usage = true;
				}
			}

			// If we're showing usage, then we had something syntactically wrong earlier
			if (!show_usage)
			{
				s_pluginLoadFailure.clear();

				if (dounload)
				{
					const std::string origPluginName = plugin ? plugin->szFilename : szName;
					if (plugin || IsPluginUnloadFailed(origPluginName))
					{
						if (UnloadPlugin(origPluginName, !noauto))
						{
							WriteChatf("Plugin '%s' unloaded.", origPluginName.c_str());
						}
						else if (s_pluginLoadFailure.empty())
						{
							s_pluginLoadFailure = "Unknown Error";
						}
					}
					else
					{
						MacroError("Plugin '%s' not found.", szName);
					}
				}
				else
				{
					if (plugin)
					{
						WriteChatf("Plugin '%s' is already loaded.", plugin->szFilename);
					}
					else
					{
						bool save = !noauto;
						if (LoadPlugin(szName, save) == 1)
						{
							plugin = GetPlugin(szName);
							WriteChatf("Plugin '%s' loaded.", plugin->szFilename);
						}
						else if (s_pluginLoadFailure.empty())
						{
							s_pluginLoadFailure = "Unknown Error";
						}
					}
				}

				if (!s_pluginLoadFailure.empty())
				{
					MacroError("Plugin '%s' could not be %sloaded: %s", szName, dounload ? "un" : "", s_pluginLoadFailure.c_str());

					s_pluginLoadFailure.clear();
				}
			}
		}
	}

	if (show_usage)
	{
		SyntaxError("Usage: /plugin <pluginName> [load/unload/toggle] [noauto], or /plugin list [active|failed|dlls]");
	}
}

//----------------------------------------------------------------------------

void InitializePlugins()
{
	AddCommand("/plugin", PluginCommand, false, true, false);

	bmWriteChatColor = AddMQ2Benchmark("WriteChatColor");
	bmPluginsIncomingChat = AddMQ2Benchmark("PluginsIncomingChat");
	bmPluginsPulse = AddMQ2Benchmark("PluginsPulse");
	bmPluginsOnZoned = AddMQ2Benchmark("PluginsOnZoned");
	bmPluginsCleanUI = AddMQ2Benchmark("PluginsCleanUI");
	bmPluginsReloadUI = AddMQ2Benchmark("PluginsReloadUI");
	bmPluginsDrawHUD = AddMQ2Benchmark("PluginsDrawHUD");
	bmPluginsSetGameState = AddMQ2Benchmark("PluginsSetGameState");
	bmCalculate = AddMQ2Benchmark("Calculate");
	bmBeginZone = AddMQ2Benchmark("BeginZone");
	bmEndZone = AddMQ2Benchmark("EndZone");

	// lock plugin list before manipulating it
	std::scoped_lock lock(s_pluginsMutex);
	s_pluginsInitialized = true;

	DebugSpew("Initializing plugins");
	ScopedModuleTracker moduleTracker;

	const std::vector<std::string> plugins = GetPrivateProfileKeys<MAX_STRING * 2>("Plugins", mq::internal_paths::MQini);
	for (const std::string& pluginName : plugins)
	{
		if (GetPrivateProfileBool("Plugins", pluginName, false, mq::internal_paths::MQini))
		{
			LoadPlugin(pluginName.c_str(), false);
		}
	}
}

void ShutdownPlugins()
{
	s_pluginsInitialized = false;

	UnloadPlugins();
	RemoveCommand("/plugin");
}

void InitializePluginHandle()
{
	mqplugin::ThisPluginHandle = CreatePluginHandle();

	MainPlugin.name = "main";
	MainPlugin.hModule = ghModule;
	strcpy_s(MainPlugin.szFilename, "MQ2Main.dll");

	s_pluginHandleMap.emplace(mqplugin::ThisPluginHandle.pluginID, &MainPlugin);
}

} // namespace mq
