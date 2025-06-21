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
#include "MQPluginHandler.h"

#include "MQ2Main.h"
#include "ModuleSystem.h"
#include "MQCommandAPI.h"

#include "mq/utils/OS.h"

#include <spdlog/spdlog.h>
#include <wil/resource.h>

#include "MacroQuest.h"

using namespace eqlib;

namespace mq {

// This is the main plugin list. We use it to preserve some sort of order, that's about it.
// It's exposed to plugins, and a lot of plugins use it even though they shouldn't, so we still
// havw to keep it around even though it does almost nothing.
MQPlugin* pPlugins = nullptr;

// String constant used to bake in the version of everquest when performing
// version checks against plugins.
static constexpr char EverQuestVersion[] = __ExpectedVersionDate " " __ExpectedVersionTime;

//----------------------------------------------------------------------------

// Strips MQ2/MQ off of the name and returns it back
std::string_view GetCanonicalPluginName(std::string_view name, bool stripExtension)
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

static void PrintModules()
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

// Locate a plugin dll that matches the given name (canonical or otherwise).
static std::string FindPluginFile(std::string_view name)
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
			SPDLOG_DEBUG("Found non-exact plugin match: {} -> {}", name, existingFile.string());
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
			SPDLOG_DEBUG("Module loaded: {}", me32.szExePath);
			newModules.push_back(me32.hModule);
		}
	} while (Module32Next(hSnapshot.get(), &me32));
}

static void AddPluginToList(MQPlugin* pPlugin)
{
	// add to plugin list
	pPlugin->pLast = nullptr;
	pPlugin->pNext = pPlugins;
	if (pPlugins)
		pPlugins->pLast = pPlugin;
	pPlugins = pPlugin;
}

static void RemovePluginFromList(MQPlugin* pPlugin)
{
	// unlink from list
	if (pPlugin->pLast)
		pPlugin->pLast->pNext = pPlugin->pNext;
	else
		pPlugins = pPlugin->pNext;
	if (pPlugin->pNext)
		pPlugin->pNext->pLast = pPlugin->pLast;
}

//=================================================================================================
//=================================================================================================

MQPluginV1Module::MQPluginV1Module(MQPluginProvider* provider, HMODULE hModule, std::string_view path)
	: MQPluginModule(hModule, path, GetCanonicalPluginName(path), MQPluginModule::DEFAULT_PLUGIN_FLAGS, provider)
{
	m_plugin.Initialize = (fMQInitializePlugin)GetProcAddress(hModule, "InitializePlugin");
	m_plugin.Shutdown = (fMQShutdownPlugin)GetProcAddress(hModule, "ShutdownPlugin");
	m_plugin.IncomingChat = (fMQIncomingChat)GetProcAddress(hModule, "OnIncomingChat");
	if (!m_plugin.IncomingChat)
		m_flags |= ModuleFlags::SkipOnIncomingChat;
	m_plugin.Pulse = (fMQPulse)GetProcAddress(hModule, "OnPulse");
	if (!m_plugin.Pulse)
		m_flags |= ModuleFlags::SkipOnProcessFrame;
	m_plugin.WriteChatColor = (fMQWriteChatColor)GetProcAddress(hModule, "OnWriteChatColor");
	if (!m_plugin.WriteChatColor)
		m_flags |= ModuleFlags::SkipOnWriteChatColor;
	m_plugin.Zoned = (fMQZoned)GetProcAddress(hModule, "OnZoned");
	m_plugin.CleanUI = (fMQCleanUI)GetProcAddress(hModule, "OnCleanUI");
	m_plugin.ReloadUI = (fMQReloadUI)GetProcAddress(hModule, "OnReloadUI");
	m_plugin.DrawHUD = (fMQDrawHUD)GetProcAddress(hModule, "OnDrawHUD");
	if (!m_plugin.DrawHUD)
		m_flags |= ModuleFlags::SkipOnDrawHUD;
	m_plugin.SetGameState = (fMQSetGameState)GetProcAddress(hModule, "SetGameState");
	m_plugin.AddSpawn = (fMQSpawn)GetProcAddress(hModule, "OnAddSpawn");
	if (!m_plugin.AddSpawn)
		m_flags |= ModuleFlags::SkipOnSpawnAdded;
	m_plugin.RemoveSpawn = (fMQSpawn)GetProcAddress(hModule, "OnRemoveSpawn");
	if (!m_plugin.RemoveSpawn)
		m_flags |= ModuleFlags::SkipOnSpawnRemoved;
	m_plugin.AddGroundItem = (fMQGroundItem)GetProcAddress(hModule, "OnAddGroundItem");
	if (!m_plugin.AddGroundItem)
		m_flags |= ModuleFlags::SkipOnGroundItemAdded;
	m_plugin.RemoveGroundItem = (fMQGroundItem)GetProcAddress(hModule, "OnRemoveGroundItem");
	if (!m_plugin.RemoveGroundItem)
		m_flags |= ModuleFlags::SkipOnGroundItemRemoved;
	m_plugin.BeginZone = (fMQBeginZone)GetProcAddress(hModule, "OnBeginZone");
	m_plugin.EndZone = (fMQEndZone)GetProcAddress(hModule, "OnEndZone");
	m_plugin.UpdateImGui = (fMQUpdateImGui)GetProcAddress(hModule, "OnUpdateImGui");
	if (!m_plugin.UpdateImGui)
		m_flags |= ModuleFlags::SkipOnUpdateImGui;
	m_plugin.MacroStart = (fMQMacroStart)GetProcAddress(hModule, "OnMacroStart");
	m_plugin.MacroStop = (fMQMacroStop)GetProcAddress(hModule, "OnMacroStop");
	m_plugin.LoadPlugin = (fMQLoadPlugin)GetProcAddress(hModule, "OnLoadPlugin");
	m_plugin.UnloadPlugin = (fMQUnloadPlugin)GetProcAddress(hModule, "OnUnloadPlugin");
	m_plugin.OnPostUnloadPlugin = (fMQPostUnloadPlugin)GetProcAddress(hModule, "OnPostUnloadPlugin");
	m_plugin.GetPluginInterface = (fMQGetPluginInterface)GetProcAddress(hModule, "GetPluginInterface");
}

MQPluginV1Module::~MQPluginV1Module()
{
}

void MQPluginV1Module::Initialize()
{
	if (m_plugin.Initialize)
	{
		m_plugin.Initialize();
	}
}

void MQPluginV1Module::Shutdown()
{
	if (m_plugin.Shutdown)
	{
		m_plugin.Shutdown();
	}
}

void MQPluginV1Module::OnProcessFrame()
{
	if (m_plugin.Pulse)
	{
		m_plugin.Pulse();
	}
}

void MQPluginV1Module::OnGameStateChanged(int gameState)
{
	if (m_plugin.SetGameState)
	{
		m_plugin.SetGameState(gameState);
	}
}

void MQPluginV1Module::OnUpdateImGui()
{
	if (m_plugin.UpdateImGui)
	{
		m_plugin.UpdateImGui();
	}
}

void MQPluginV1Module::OnCleanUI()
{
	if (m_plugin.CleanUI)
	{
		m_plugin.CleanUI();
	}
}

void MQPluginV1Module::OnReloadUI(const eqlib::ReloadUIParams& params)
{
	UNUSED(params);

	if (m_plugin.ReloadUI)
	{
		m_plugin.ReloadUI();
	}
}

void MQPluginV1Module::OnPreZoneUI()
{
	if (m_plugin.BeginZone)
	{
		m_plugin.BeginZone();
	}
}

void MQPluginV1Module::OnPostZoneUI()
{
	if (m_plugin.EndZone)
	{
		m_plugin.EndZone();
	}
}

void MQPluginV1Module::OnWriteChatColor(const char* message, int color, int filter)
{
	if (m_plugin.WriteChatColor)
	{
		m_plugin.WriteChatColor(message, color, filter);
	}
}

bool MQPluginV1Module::OnIncomingChat(const IncomingChatParams& params)
{
	if (params.filtered)
		return false;

	if (m_plugin.IncomingChat)
	{
		return m_plugin.IncomingChat(params.message, params.color);
	}

	return false;
}

void MQPluginV1Module::OnZoned()
{
	if (m_plugin.Zoned)
	{
		m_plugin.Zoned();
	}
}

void MQPluginV1Module::OnDrawHUD()
{
	if (m_plugin.DrawHUD)
	{
		m_plugin.DrawHUD();
	}
}

void MQPluginV1Module::OnSpawnAdded(eqlib::PlayerClient* player)
{
	if (m_plugin.AddSpawn)
	{
		m_plugin.AddSpawn(player);
	}
}

void MQPluginV1Module::OnSpawnRemoved(eqlib::PlayerClient* player)
{
	if (m_plugin.RemoveSpawn)
	{
		m_plugin.RemoveSpawn(player);
	}
}

void MQPluginV1Module::OnGroundItemAdded(eqlib::EQGroundItem* groundItem)
{
	if (m_plugin.AddGroundItem)
	{
		m_plugin.AddGroundItem(groundItem);
	}
}

void MQPluginV1Module::OnGroundItemRemoved(eqlib::EQGroundItem* groundItem)
{
	if (m_plugin.RemoveGroundItem)
	{
		m_plugin.RemoveGroundItem(groundItem);
	}
}

void MQPluginV1Module::OnModuleLoaded(MQModule* module)
{
	if (m_plugin.LoadPlugin && module->IsPlugin())
	{
		m_plugin.LoadPlugin(module->GetName().c_str());
	}
}

void MQPluginV1Module::OnBeforeModuleUnloaded(MQModule* module)
{
	if (m_plugin.UnloadPlugin && module->IsPlugin())
	{
		m_plugin.UnloadPlugin(module->GetName().c_str());
	}
}

void MQPluginV1Module::OnAfterModuleUnloaded(MQModule* module)
{
	if (m_plugin.OnPostUnloadPlugin && module->IsPlugin())
	{
		m_plugin.OnPostUnloadPlugin(module->GetName().c_str());
	}
}

void MQPluginV1Module::OnMacroStart(const char* macroName)
{
	if (m_plugin.MacroStart)
	{
		m_plugin.MacroStart(macroName);
	}
}

void MQPluginV1Module::OnMacroStop(const char* macroName)
{
	if (m_plugin.MacroStop)
	{
		m_plugin.MacroStop(macroName);
	}
}

PluginInterface* MQPluginV1Module::GetPluginInterface()
{
	if (m_plugin.GetPluginInterface)
	{
		return m_plugin.GetPluginInterface();
	}

	return nullptr;
}

//=================================================================================================

MQPluginHandler* g_pluginHandler = nullptr;

DECLARE_MODULE_FACTORY(MQPluginHandler)

MQPluginHandler::MQPluginHandler()
	: MQModule("PluginHandler", static_cast<int>(ModulePriority::PluginHandler))
{
	g_pluginHandler = this;
}

MQPluginHandler::~MQPluginHandler()
{
	g_pluginHandler = nullptr;
}

void MQPluginHandler::Initialize()
{
	AddCommand("/plugin",
		[this](PlayerClient*, const char* szLine) { PluginCommand(szLine); }, false, true, false);

	LoadPlugins();
}

void MQPluginHandler::OnBeforePluginInitialized(MQPluginModule* pluginModule)
{
	// Pass the plugin instance and handle to the plugin
	using InitPluginHandleFunc = void(*)(mq::MQPlugin*, mq::MQPluginHandle);

	MQPlugin* plugin = pluginModule->GetPlugin();
	HMODULE hModule = pluginModule->GetHModule();

	auto initPluginFunc = reinterpret_cast<InitPluginHandleFunc>(GetProcAddress(hModule, "InitPluginHandle"));
	initPluginFunc(plugin, GetHandle());

	if (float* pVersion = reinterpret_cast<float*>(GetProcAddress(hModule, "?MQ2Version@@3MA")))
		plugin->fpVersion = *pVersion;
	else
		plugin->fpVersion = 1.0;
}

void MQPluginHandler::OnAfterPluginInitialized(MQPluginModule* plugin)
{
	// Called after a plugin that was provided by this provider was initialized

	UNUSED(plugin);
}

void MQPluginHandler::OnBeforePluginShutdown(MQPluginModule* plugin)
{
	// This is called immediately before the plugin's Shutdown function is called,
	// allow us to prepare before shutdown.

	// Remove it from the list so that it can no longer be accessed
	RemovePluginFromList(plugin->GetPlugin());

	auto iter = m_pluginMap.find(plugin->GetName());
	if (iter != m_pluginMap.end())
	{
		m_pluginMap.erase(iter);
	}
}

void MQPluginHandler::OnAfterPluginShutdown(MQPluginModule* plugin)
{
	// Called after a plugin that was provided by this provider was shutdown

	UNUSED(plugin);
}

void MQPluginHandler::Shutdown()
{
	m_shutdown = true;

	// Unload plugins
	while (pPlugins)
	{
		UnloadPlugin(pPlugins->szFilename);
	}

	ShutdownFailedPlugins();

	RemoveCommand("/plugin");
}

void MQPluginHandler::LoadPlugins()
{
	ScopedModuleTracker moduleTracker;

	const std::vector<std::string> plugins = GetPrivateProfileKeys<MAX_STRING * 2>("Plugins", mq::internal_paths::MQini);
	for (const std::string& pluginName : plugins)
	{
		if (GetPrivateProfileBool("Plugins", pluginName, false, mq::internal_paths::MQini))
		{
			LoadPlugin(pluginName, false);
		}
	}
}

LoadPluginResult MQPluginHandler::LoadPlugin(std::string_view pluginName, bool save)
{
	// Clear the load error message;
	m_pluginLoadFailure.clear();

	if (IsPluginLoaded(pluginName))
	{
		SPDLOG_INFO("LoadPlugin({}): Plugin is already loaded", pluginName);
		m_pluginLoadFailure = "Plugin is already loaded";

		return LoadPluginResult_AlreadyLoaded;
	}

	if (IsPluginUnloadFailed(pluginName))
	{
		SPDLOG_ERROR("LoadPlugin({}): previous instance failed unload", pluginName);
		m_pluginLoadFailure = "Plugin failed unload from a previous instance, cannot load";

		return LoadPluginResult_PreviousUnloadFailed;
	}

	ScopedModuleTracker moduleTracker;

	auto [hModule, pluginPath] = LoadPluginModule(pluginName);
	if (!hModule)
	{
		// szPluginLoadFailure is set in LoadPluginModule
		SPDLOG_ERROR("LoadPlugin({}) failed: {}", pluginName, m_pluginLoadFailure);
		return LoadPluginResult_Failed;
	}

	MQModulePtr plugin;

	// Check if this is a V1 plugin or a V2 plugin.
	if (fMQCreateModule CreateModuleProc = (fMQCreateModule)GetProcAddress(hModule.get(), "CreateModule"))
	{
		// Validate that it also has a DestroyModule
		fMQDestroyModule DestroyModuleProc = (fMQDestroyModule)GetProcAddress(hModule.get(), "DestroyModule");
		if (!DestroyModuleProc)
		{
			m_pluginLoadFailure = fmt::format("Plugin {} uses CreateModule does not have a DestroyModule", pluginPath);

			SPDLOG_ERROR("LoadPlugin({}) failed: {}", pluginName, m_pluginLoadFailure);
			return LoadPluginResult_Failed;
		}

		MQPluginArguments arguments;
		arguments.pluginProvider = this;
		arguments.hModule = hModule.release();
		arguments.path = pluginPath;
		arguments.name = GetCanonicalPluginName(pluginPath);
		arguments.flags = MQPluginModule::DEFAULT_PLUGIN_FLAGS;

		plugin = std::shared_ptr<MQPluginModule>(CreateModuleProc(arguments),
			[this, DestroyModuleProc](MQPluginModule* module) { DeletePluginModule(module, DestroyModuleProc); });

		SPDLOG_DEBUG("LoadPlugin({}): Plugin module created as a V2 plugin module. name={} fileName={}",
			pluginName, plugin->GetName(), plugin->GetPluginFilename());
	}
	else
	{
		plugin = std::shared_ptr<MQPluginV1Module>(new MQPluginV1Module(this, hModule.release(), pluginPath),
			[this](MQPluginModule* module) { DeletePluginModule(module); });

		SPDLOG_DEBUG("LoadPlugin({}): Plugin module created as a V1 plugin module. name={} fileName={}",
			pluginName, plugin->GetName(), plugin->GetPluginFilename());
	}

	// Add the plugin to the plugin list.
	AddPluginToList(plugin->GetPlugin());
	MQModule* pluginModule = plugin.get();
	g_mq->AddModule(std::move(plugin));
	m_pluginMap.emplace(pluginModule->GetName(), pluginModule);

	if (save)
	{
		WritePrivateProfileBool("Plugins", pluginModule->GetPluginFilename(), true, mq::internal_paths::MQini);
	}
	return LoadPluginResult_Success;
}

void MQPluginHandler::DeletePluginModule(MQPluginModule* module, fMQDestroyModule destroyProc /* = nullptr */)
{
	HMODULE hModule = module->GetHModule();
	std::string pluginName = module->GetPluginFilename();

	SPDLOG_DEBUG("DeletePluginModule({})", pluginName);

	// If destroyProc was provided, use it to delete the module. Otherwise, we just delete it normally.
	if (destroyProc)
	{
		destroyProc(module);
	}
	else
	{
		delete module;
	}

	if (hModule && !CleanupPluginModule(pluginName, hModule))
	{
		UnloadFailedItem failedItem;
		failedItem.fileName = pluginName;
		failedItem.hModule = hModule;
		std::string_view key = failedItem.fileName;

		m_pluginUnloadFailedMap.emplace(key, std::move(failedItem));
	}
}

bool MQPluginHandler::UnloadPlugin(std::string_view pluginName, bool save /* = false */)
{
	SPDLOG_DEBUG("UnloadPlugin({})", pluginName);

	// Clear the load error message;
	m_pluginLoadFailure.clear();

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

	// If this is already a failed-to-unload plugin, try to clean it up again.
	auto failedIter = m_pluginUnloadFailedMap.find(canonicalName);
	if (failedIter != m_pluginUnloadFailedMap.end())
	{
		// Try to clean it up again.
		const UnloadFailedItem& failedItem = failedIter->second;

		if (CleanupPluginModule(failedItem.fileName, failedItem.hModule))
		{
			m_pluginUnloadFailedMap.erase(failedIter);
			return true;
		}

		return false;
	}

	auto iter = m_pluginMap.find(canonicalName);
	if (iter != m_pluginMap.end())
	{
		MQPluginHandle handle = iter->second->GetHandle();

		// This should return the last unique copy of the module.
		MQModulePtr module = g_mq->RemoveModule(handle);
		assert(module.use_count() == 1);

		// This will delete the module, and call CleanupPluginModule. If the plugin is now found in the
		// unload failure map, then we know the unload operation failed.
		module.reset();

		if (m_pluginUnloadFailedMap.count(canonicalName) == 0)
			return true;
	}

	return false;
}

bool MQPluginHandler::CleanupPluginModule(std::string_view pluginName, HMODULE hModule)
{
	if (FreeLibrary(hModule))
	{
		if (!IsInModuleList(pluginName))
		{
			return true;
		}

		m_pluginLoadFailure = "Plugin files still loaded.";
		SPDLOG_ERROR("UnloadPlugin({}) failed: {}", pluginName, m_pluginLoadFailure);
	}
	else
	{
		DWORD lastError = ::GetLastError();
		char* szError = nullptr;

		::FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			nullptr,
			lastError,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR)&szError,
			0,
			nullptr);

		m_pluginLoadFailure = fmt::format("FreeLibrary failed with error {:#08x}: {}", lastError, szError);
		SPDLOG_ERROR("UnloadPlugin({}) failed: {}", pluginName, m_pluginLoadFailure);
	}

	return false;
}

bool MQPluginHandler::IsPluginLoaded(std::string_view pluginName) const
{
	return m_pluginMap.count(GetCanonicalPluginName(pluginName)) != 0;
}

MQPlugin* MQPluginHandler::GetPluginPtr(std::string_view name)
{
	auto iter = m_pluginMap.find(GetCanonicalPluginName(name));

	if (iter != m_pluginMap.end())
	{
		return iter->second->GetPlugin();
	}

	return nullptr;
}

void* MQPluginHandler::GetPluginProcFromPlugin(std::string_view pluginName, const char* proc)
{
	if (MQPlugin* plugin = GetPluginPtr(pluginName))
	{
		return GetProcAddress(plugin->hModule, proc);
	}

	return nullptr;
}

PluginInterface* MQPluginHandler::GetPluginInterfaceFromPlugin(std::string_view pluginName)
{
	if (MQPlugin* pPlugin = GetPluginPtr(pluginName))
	{
		if (pPlugin->GetPluginInterface)
		{
			return pPlugin->GetPluginInterface();
		}
	}

	return nullptr;
}

//=================================================================================================

void MQPluginHandler::PluginCommand(const char* szLine)
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
				if (m_pluginUnloadFailedMap.empty())
				{
					WriteChatColor("No Failed Plugins.", USERCOLOR_WHO);
				}
				else
				{
					for (auto const& [key, failedItem] : m_pluginUnloadFailedMap)
					{
						WriteChatColorf("%s", USERCOLOR_WHO, failedItem.fileName.c_str());
					}
					WriteChatColorf("%d Plugin(s) displayed. To try to unload again use /plugin <pluginame> unload",
						USERCOLOR_WHO, m_pluginUnloadFailedMap.size());
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
			MQPlugin* plugin = GetPluginPtr(szName);

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
				m_pluginLoadFailure.clear();

				if (dounload)
				{
					// Make a copy of the string since unloading it will also remove the string
					const std::string origPluginName = plugin ? plugin->szFilename : szName;
					if (plugin || IsPluginUnloadFailed(origPluginName))
					{
						if (UnloadPlugin(origPluginName, !noauto))
						{
							WriteChatf("Plugin '%s' unloaded.", origPluginName.c_str());
						}
						else if (m_pluginLoadFailure.empty())
						{
							m_pluginLoadFailure = "Unknown Error";
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
							plugin = GetPluginPtr(szName);
							WriteChatf("Plugin '%s' loaded.", plugin->szFilename);
						}
						else if (m_pluginLoadFailure.empty())
						{
							m_pluginLoadFailure = "Unknown Error";
						}
					}
				}

				if (!m_pluginLoadFailure.empty())
				{
					MacroError("Plugin '%s' could not be %sloaded: %s", szName, dounload ? "un" : "", m_pluginLoadFailure.c_str());

					m_pluginLoadFailure.clear();
				}
			}
		}
	}

	if (show_usage)
	{
		SyntaxError("Usage: /plugin <pluginName> [load/unload/toggle] [noauto], or /plugin list [active|failed|dlls]");
	}
}

std::pair<wil::unique_hmodule, std::string> MQPluginHandler::LoadPluginModule(std::string_view name)
{
	namespace fs = std::filesystem;

	// Our job here is to return the module handle if we found a plugin matching
	// the name requested. If we fail for whatever reason, we return a null hmodule
	// and set the reason in szPluginLoadFailure.

	SPDLOG_DEBUG("LoadPlugin({})", name);

	std::string fileName = FindPluginFile(name);
	if (fileName.empty())
	{
		m_pluginLoadFailure = "Plugin not found";
		return {};
	}

	const fs::path pathToPlugin = fs::path(mq::internal_paths::Plugins) / fileName;

	wil::unique_hmodule hModule{ ::LoadLibraryA(pathToPlugin.string().c_str()) };
	if (!hModule)
	{
		DWORD lastError = ::GetLastError();
		char* szError = nullptr;

		::FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			nullptr,
			lastError,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR)&szError,
			0,
			nullptr);

		m_pluginLoadFailure = fmt::format("LoadLibrary failed with error {:#08x}: {}", lastError, szError);
		return {};
	}

	// Perform MQNext version check
	void* isBuildForNext = GetProcAddress(hModule.get(), "IsBuiltForNext");
	if (isBuildForNext == nullptr)
	{
		m_pluginLoadFailure = "Plugin was not built for this version of MacroQuest";
		return {};
	}

	// Perform EQ version check
	const char* eqVersion = reinterpret_cast<const char*>(GetProcAddress(hModule.get(), "EverQuestVersion"));
	if (eqVersion == nullptr)
	{
		m_pluginLoadFailure = "Plugin was not built for this version of EverQuest";
		return {};
	}

	if (strcmp(eqVersion, EverQuestVersion) != 0)
	{
		m_pluginLoadFailure = fmt::format("Plugin was not built for this version of EverQuest (was built for {})",
			eqVersion);
		return {};
	}

	return { std::move(hModule), std::move(fileName) };
}

bool MQPluginHandler::UnloadFailedPlugins()
{
	decltype(m_pluginUnloadFailedMap) failedModules;
	failedModules.swap(m_pluginUnloadFailedMap);

	for (auto&& [_, failedItem] : failedModules)
	{
		SPDLOG_DEBUG("UnloadFailedPlugins({})", failedItem.fileName.c_str());
		if (!CleanupPluginModule(failedItem.fileName, failedItem.hModule))
		{
			UnloadFailedItem newFailedItem = std::move(failedItem);
			std::string_view key = newFailedItem.fileName;

			m_pluginUnloadFailedMap.emplace(key, std::move(newFailedItem));
		}
	}

	return m_pluginUnloadFailedMap.empty();
}
  
void MQPluginHandler::ShutdownFailedPlugins()
{
	if (!UnloadFailedPlugins() && !gbForceUnload)
	{
		int msgReturn = IDRETRY;
		while (msgReturn == IDRETRY && !UnloadFailedPlugins())
		{
			msgReturn = ::MessageBoxA(nullptr,
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

bool MQPluginHandler::IsPluginUnloadFailed(std::string_view name)
{
	return m_pluginUnloadFailedMap.count(name) != 0;
}

//=================================================================================================
// PluginAPI function implementations

int LoadPlugin(std::string_view pluginName, bool save)
{
	if (g_pluginHandler)
	{
		return (int)g_pluginHandler->LoadPlugin(pluginName, save);
	}

	SPDLOG_ERROR("Attempt to call LoadPlugin without PluginHandler module loaded");
	return LoadPluginResult_Failed;
}

bool UnloadPlugin(std::string_view pluginName, bool save)
{
	if (g_pluginHandler)
	{
		return g_pluginHandler->UnloadPlugin(pluginName, save);
	}

	SPDLOG_ERROR("Attempt to call UnloadPlugin without PluginHandler module loaded");
	return false;
}

void* GetPluginProc(std::string_view pluginName, const char* proc)
{
	if (g_pluginHandler)
	{
		return g_pluginHandler->GetPluginProcFromPlugin(pluginName, proc);
	}

	SPDLOG_ERROR("Attempt to call GetPluginProc without PluginHandler module loaded");
	return nullptr;
}

MQPlugin* GetPlugin(std::string_view pluginName)
{
	if (g_pluginHandler)
	{
		return g_pluginHandler->GetPluginPtr(pluginName);
	}

	SPDLOG_ERROR("Attempt to call GetPlugin without PluginHandler module loaded");
	return nullptr;
}

MQPlugin* GetPluginByHandle(MQPluginHandle handle, bool noMain /* = false */)
{
	// MQ has everything stored by handle, we just call into it there and
	// filter the results
	MQModule* pModule = g_mq->GetModuleByHandle(handle, noMain);

	if (pModule && pModule->IsPlugin())
	{
		MQPluginModule* pPluginModule = static_cast<MQPluginModule*>(pModule);

		return pPluginModule->GetPlugin();
	}

	return nullptr;
}

PluginInterface* GetPluginInterface(std::string_view pluginName)
{
	if (g_pluginHandler)
	{
		return g_pluginHandler->GetPluginInterfaceFromPlugin(pluginName);
	}

	SPDLOG_ERROR("Attempt to call GetPluginInterface without PluginHandler module loaded");
	return nullptr;
}

// Returns true if the plugin is loaded by checking its canonical name.
bool IsPluginLoaded(std::string_view pluginName)
{
	if (g_pluginHandler)
	{
		return g_pluginHandler->IsPluginLoaded(pluginName);
	}

	SPDLOG_ERROR("Attempt to call IsPluginLoaded without PluginHandler module loaded");
	return nullptr;
}

int GetPluginUnloadFailedCount()
{
	if (g_pluginHandler)
	{
		return g_pluginHandler->GetPluginUnloadFailedCount();
	}

	return 0;
}

} // namespace mq
