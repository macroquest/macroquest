/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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

#include <spdlog/spdlog.h>
#include <wil/resource.h>

//#define DEBUG_PLUGINS

namespace mq {

#ifdef DEBUG_PLUGINS
#define PluginDebug DebugSpew
#else
#define PluginDebug //
#endif

// This is the main plugin list. We use it to preserve some sort of order, thats about it.
MQPlugin* pPlugins = nullptr;

static std::atomic_bool s_pluginsInitialized = false;
static std::recursive_mutex s_pluginsMutex;

// a map of plugin names to plugins. The string_view is a reference to the name in the
// MQPlugin instance.
using PluginMap = ci_unordered::map<std::string_view, MQPlugin*>;
static PluginMap g_pluginMap;

// String constant used to bake in the version of everquest when performing
// version checks against plugins.
static const char EverQuestVersion[] = __ExpectedVersionDate " " __ExpectedVersionTime;

// load failure string for reporting error message out of the plugin load command.
static char szPluginLoadFailure[MAX_STRING];

static bool s_hotReloadEnabled = true;

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
	SPDLOG_DEBUG("Initializing module: {0}", module->name);

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

//----------------------------------------------------------------------------

bool IsPluginsInitialized()
{
	return s_pluginsInitialized;
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

// Returns true if the plugin is loaded by checking its canonical name.
bool IsPluginLoaded(std::string_view name)
{
	return g_pluginMap.count(GetCanonicalPluginName(name)) != 0;
}

MQPlugin* GetPlugin(std::string_view name)
{
	auto iter = g_pluginMap.find(GetCanonicalPluginName(name));
	return iter == g_pluginMap.end() ? nullptr : iter->second;
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

//class HotReloadModule
//{
//public:
//};
//static ci_unordered::map<std::string, std::shared_ptr<HotReloadModule>> s_hotReloadMap;
//
//std::shared_ptr<HotReloadModule> HotReload_SetupPlugin(std::string_view pluginName, std::string pluginPath)
//{
//
//}
//
//void HotReload_CleanupPlugin(std::string_view pluginName)
//{
//}


std::pair<wil::unique_hmodule, std::string> LoadPluginModule(std::string_view name)
{
	namespace fs = std::filesystem;

	// Our job here is to return the module handle if we found a plugin matching
	// the name requested. If we fail for whatever reason, we return a null hmodule
	// and set the reason in szPluginLoadFailure.

	DebugSpew("LoadMQ2Plugin(%.*s)", name.length(), name.data());

	std::string fileName = FindPluginFile(name);
	if (fileName.empty())
	{
		return {};
	}

	fs::path pathToPlugin = fs::path(mq::internal_paths::Plugins) / fileName;

	if (s_hotReloadEnabled)
	{
	}

	wil::unique_hmodule hModule{ ::LoadLibraryA(pathToPlugin.string().c_str()) };
	if (!hModule)
	{
		DWORD lastError = ::GetLastError();
		sprintf_s(szPluginLoadFailure, "LoadLibrary failed with error 0x%08x", lastError);

		return {};
	}

	// Perform MQNext version check
	void* isBuildForNext = GetProcAddress(hModule.get(), "IsBuiltForNext");
	if (isBuildForNext == nullptr)
	{
		strcpy_s(szPluginLoadFailure, "Plugin was not built for this version of MacroQuest");

		return {};
	}

	// Perform EQ version check
	const char* eqVersion = reinterpret_cast<const char*>(GetProcAddress(hModule.get(), "EverQuestVersion"));
	if (eqVersion == nullptr)
	{
		strcpy_s(szPluginLoadFailure, "Plugin was not built for this version of EverQuest");

		return {};
	}
	else if (strcmp(eqVersion, EverQuestVersion) != 0)
	{
		sprintf_s(szPluginLoadFailure, "Plugin was not built for this version of EverQuest (was built for %s)",
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

int LoadMQ2Plugin(const char* pszFilename, bool)
{
	// Clear the load error message;
	szPluginLoadFailure[0] = 0;

	std::string pluginName = pszFilename;

	if (IsPluginLoaded(pluginName))
	{
		DebugSpew("LoadMQ2Plugin(%s) already loaded", pluginName.c_str());
		strcpy_s(szPluginLoadFailure, "Plugin is already loaded");

		return 2;
	}

	auto [hModule, pluginPath] = LoadPluginModule(pluginName);
	if (!hModule)
	{
		DebugSpew("LoadMQ2Plugin(%s) failed: %s", pluginName.c_str(), szPluginLoadFailure);

		return 0;
	}

	MQPlugin* pPlugin = new MQPlugin();
	strcpy_s(pPlugin->szFilename, pluginPath.c_str());
	pPlugin->name              = std::string{ GetCanonicalPluginName(pluginName) };
	pPlugin->hModule           = hModule.release();
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
	g_pluginMap.emplace(std::string_view(pPlugin->name), pPlugin);


	// load cfg file if exists
	std::string autoExec = fmt::format("{}-AutoExec", pPlugin->szFilename);
	LoadCfgFile(autoExec.c_str(), false);

	PluginsLoadPlugin(pPlugin->szFilename);
	return 1;
}

bool UnloadMQ2Plugin(const char* pszFilename)
{
	DebugSpew("UnloadMQ2Plugin");

	std::string_view canonicalName = GetCanonicalPluginName(pszFilename);

	auto iter = g_pluginMap.find(canonicalName);
	if (iter == g_pluginMap.end())
		return false;

	MQPlugin* pPlugin = iter->second;

	// Inform other plugins that this plugin is being removed
	PluginsUnloadPlugin(pPlugin->szFilename);

	// Remove it from the list so that it can no longer be accessed
	RemovePluginFromList(pPlugin);
	g_pluginMap.erase(iter);

	// call Plugin:CleanUI
	if (pPlugin->CleanUI)
		pPlugin->CleanUI();

	// call Plugin:Shutdown
	if (pPlugin->Shutdown)
		pPlugin->Shutdown();

	// Cleanup
	FreeLibrary(pPlugin->hModule);
	delete pPlugin;

	return true;
}

void UnloadMQ2Plugins()
{
	while (pPlugins)
	{
		DebugSpew("%s->Unload()", pPlugins->szFilename);
		UnloadMQ2Plugin(pPlugins->szFilename);
	}
}

template <typename Callback>
void ForEachModule(Callback& callback)
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

	//SPDLOG_DEBUG("Begin WriteChatColor()");

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

bool PluginsIncomingChat(const char* Line, DWORD Color)
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
	RemoveAutoBankMenu();

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

	ForEachPlugin([](const MQPlugin* plugin)
		{
			if (plugin->ReloadUI)
			{
				DebugSpew("%s->ReloadUI()", plugin->szFilename);
				plugin->ReloadUI();
			}
		});
}

void PluginsSetGameState(DWORD GameState)
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

			DebugSpew("PluginsSetGameState(%s server)", EQADDR_SERVERNAME);

			LoadCfgFile("InGame", false);

			if (pLocalPC)
			{
				DebugSpew("PluginsSetGameState(%s name)", pLocalPC->Name);

				sprintf_s(szBuffer, "%s_%s", EQADDR_SERVERNAME, pLocalPC->Name);
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

void PluginsAddSpawn(SPAWNINFO* pNewSpawn)
{
	if (!s_pluginsInitialized)
		return;

	DWORD BodyType = GetBodyType(pNewSpawn);
	PluginDebug("PluginsAddSpawn(%s,%d,%d)", pNewSpawn->Name, pNewSpawn->GetRace(), BodyType);

	if (GetGameState() > GAMESTATE_CHARSELECT)
		SetNameSpriteState(pNewSpawn, true);

	if (GetBodyTypeDesc(BodyType)[0] == '*')
		WriteChatf("Spawn '%s' has unknown bodytype %d", pNewSpawn->Name, BodyType);

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

void PluginsRemoveSpawn(SPAWNINFO* pSpawn)
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

void PluginsAddGroundItem(GROUNDITEM* pNewGroundItem)
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

void PluginsRemoveGroundItem(GROUNDITEM* pGroundItem)
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
}

void* GetPluginProc(const char* plugin, const char* proc)
{
	unsigned int uiLength = strlen(plugin) + 1;
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
	char szBuffer[MAX_STRING] = { 0 };
	char szName[MAX_STRING] = { 0 };

	GetArg(szName, szLine, 1);
	const char* szCommand = GetNextArg(szLine);

	if (!_stricmp(szName, "list"))
	{
		MQPlugin* pLoop = pPlugins;
		int Count = 0;

		WriteChatColor("Active Plugins", USERCOLOR_WHO);
		WriteChatColor("--------------------------", USERCOLOR_WHO);

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
		return;
	}

	if (szName[0] == 0)
	{
		SyntaxError("Usage: /plugin name [load/unload/toggle] [noauto], or /plugin list");
		return;
	}

	bool doload = true;
	bool dounload = false;

	// helps us check if this plugin is already loaded
	MQPlugin* plugin = GetPlugin(szName);
	std::string origPluginName;
	if (plugin)
		origPluginName = plugin->szFilename;

	// why substring? oh.. because we're not actually parsing this part. could have auto...
	if (ci_find_substr(szCommand, "toggle") == 0)
	{
		dounload = (plugin != nullptr);
		doload = !dounload;
	}
	else if (ci_find_substr(szCommand, "unload") == 0)
	{
		dounload = true;
		doload = false;
	}
	else if (ci_find_substr(szCommand, "load") == 0)
	{
		dounload = false;
		doload = true;
	}

	if (dounload)
	{
		// Get the original plugin name in case we need to do something with it ...
		if (plugin)
		{
			UnloadMQ2Plugin(szName);
			WriteChatf("Plugin '%s' unloaded.", origPluginName.c_str());

			// As below, this will capture MQ2NoAutomaticstuff as well.  As a long term fix, consider arg parsing.
			if (ci_find_substr(szCommand, "noauto") == -1)
			{
				WritePrivateProfileBool("Plugins", origPluginName, false, mq::internal_paths::MQini);
			}
		}
		else
		{
			MacroError("Plugin '%s' not found.", szName);
		}

		return;
	}

	if (doload)
	{
		if (plugin)
		{
			WriteChatf("Plugin '%s' is already loaded.", plugin->szFilename);
			return;
		}

		if (LoadMQ2Plugin(szName))
		{
			plugin = GetPlugin(szName);
			WriteChatf("Plugin '%s' loaded.", plugin->szFilename);

			// As above, this will capture MQ2NoAutomaticstuff as well.  As a long term fix, consider arg parsing.
			if (ci_find_substr(szCommand, "noauto") == -1)
			{
				WritePrivateProfileBool("Plugins", plugin->szFilename, true, mq::internal_paths::MQini);
			}
		}
		else
		{
			if (szPluginLoadFailure[0] != 0)
				MacroError("Plugin '%s' could not be loaded: %s", szName, szPluginLoadFailure);
			else
				MacroError("Plugin '%s' could not be loaded.", szName);
		}
	}
}

//----------------------------------------------------------------------------
// Deprecated
void SaveMQ2PluginLoadStatus(const char* Name, bool bLoad)
{
	std::scoped_lock lock(s_pluginsMutex);

	WritePrivateProfileBool("Plugins", Name, bLoad, mq::internal_paths::MQini);
}

//----------------------------------------------------------------------------

void InitializeMQ2Plugins()
{
	AddCommand("/plugin", PluginCommand, false, false, false);

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

	std::vector<std::string> plugins = GetPrivateProfileKeys("Plugins", mq::internal_paths::MQini);
	for (const std::string& pluginName : plugins)
	{
		if (GetPrivateProfileBool("Plugins", pluginName, false, mq::internal_paths::MQini))
		{
			LoadMQ2Plugin(pluginName.c_str());
		}
	}
}

void ShutdownMQ2Plugins()
{
	s_pluginsInitialized = false;

	UnloadMQ2Plugins();
	RemoveCommand("/plugin");
}


} // namespace mq
