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

//#define DEBUG_PLUGINS

namespace mq {

#ifdef DEBUG_PLUGINS
#define PluginDebug DebugSpew
#else
#define PluginDebug //
#endif

#define NO_TIMESTAMP_CHECK

static std::atomic_bool s_pluginsInitialized = false;
static uint32_t s_mq2mainstamp = 0;
static std::recursive_mutex s_pluginsMutex;
static const char EverQuestVersion[] = __ExpectedVersionDate " " __ExpectedVersionTime;
MQPlugin* pPlugins = nullptr;

extern bool gbManualResetRequired;
char szPluginLoadFailure[MAX_STRING];

std::vector<MQModule*> gInternalModules;

// Defined in MQ2Utilities.cpp
DWORD CALLBACK InitializeMQ2SpellDb(void* pData);

// Defined in MQ2LoginFrontend.cpp
void RemoveLoginFrontendHooks();

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

static uint32_t checkme(char* module)
{
	PIMAGE_DOS_HEADER pd = (PIMAGE_DOS_HEADER)module;
	PIMAGE_FILE_HEADER pf;

	uint8_t* p = reinterpret_cast<uint8_t*>(module) + pd->e_lfanew;
	p += 4;  // skip sig

	pf = reinterpret_cast<PIMAGE_FILE_HEADER>(p);
	return pf->TimeDateStamp;
}

int LoadMQ2Plugin(const char* pszFilename, bool bCustom /* = false */)
{
	// Clear the load error message;
	szPluginLoadFailure[0] = 0;

	std::string strFileName = pszFilename;
	const int Pos = ci_find_substr(strFileName, ".dll");
	if (Pos != -1)
	{
		strFileName = strFileName.substr(0, Pos);
	}
	std::string strFileNameWithDll = strFileName + ".dll";

	if (HMODULE hThemod = GetModuleHandle(strFileNameWithDll.c_str()))
	{
		DebugSpew("LoadMQ2Plugin(%s) already loaded", strFileNameWithDll.c_str());
		return 2;
	}

	std::scoped_lock lock(s_pluginsMutex);

	DebugSpew("LoadMQ2Plugin(%s)", strFileName.c_str());

	std::filesystem::path pathToPlugin;

	pathToPlugin = std::filesystem::path(mq::internal_paths::Plugins);
	pathToPlugin /= strFileNameWithDll;

	HMODULE hmod = LoadLibrary(pathToPlugin.string().c_str());
	if (hmod == nullptr)
	{
		const auto err = GetLastError();
		DebugSpew("LoadMQ2Plugin(%s) Failed: %i", strFileName.c_str(), err);
		return 0;
	}

	// Perform MQNext version check
	void* isBuildForNext = GetProcAddress(hmod, "IsBuiltForNext");
	if (isBuildForNext == nullptr)
	{
		DebugSpew("LoadMQ2Plugin(%s) failed: Plugin was not built for this version of MacroQuest",
			strFileName.c_str());
		strcpy_s(szPluginLoadFailure, "Plugin was not built for this version of MacroQuest");

		FreeLibrary(hmod);
		return 0;
	}

	// Perform EQ version check
	const char* eqVersion = reinterpret_cast<const char*>(GetProcAddress(hmod, "EverQuestVersion"));
	if (eqVersion == nullptr)
	{
		DebugSpew("LoadMQ2Plugin(%s) failed: Plugin was not built for this version of EverQuest",
			strFileName.c_str());
		strcpy_s(szPluginLoadFailure, "Plugin was not built for this version of EverQuest");

		FreeLibrary(hmod);
		return 0;
	}
	else if (strcmp(eqVersion, EverQuestVersion) != 0)
	{
		DebugSpew("LoadMQ2Plugin(%s) failed: Plugin was not built for this version of EverQuest (was built for %s)",
			strFileName.c_str(), eqVersion);
		sprintf_s(szPluginLoadFailure, "Plugin was not built for this version of EverQuest (was built for %s)",
			eqVersion);

		FreeLibrary(hmod);
		return 0;
	}

	MQPlugin* pPlugin = pPlugins;
	while (pPlugin)
	{
		if (hmod == pPlugin->hModule)
		{
			DebugSpew("LoadMQ2Plugin(%s) already loaded", strFileName.c_str());

			// LoadLibrary count must match FreeLibrary count for unloading to work.
			FreeLibrary(hmod);
			return 2; // already loaded
		}
		pPlugin = pPlugin->pNext;
	}

	pPlugin = new MQPlugin;
	memset(pPlugin, 0, sizeof(MQPlugin));
	pPlugin->bCustom           = bCustom;
	pPlugin->hModule           = hmod;
	strcpy_s(pPlugin->szFilename, strFileName.c_str());
	pPlugin->Initialize        = (fMQInitializePlugin)GetProcAddress(hmod, "InitializePlugin");
	pPlugin->Shutdown          = (fMQShutdownPlugin)GetProcAddress(hmod, "ShutdownPlugin");
	pPlugin->IncomingChat      = (fMQIncomingChat)GetProcAddress(hmod, "OnIncomingChat");
	pPlugin->Pulse             = (fMQPulse)GetProcAddress(hmod, "OnPulse");
	pPlugin->WriteChatColor    = (fMQWriteChatColor)GetProcAddress(hmod, "OnWriteChatColor");
	pPlugin->Zoned             = (fMQZoned)GetProcAddress(hmod, "OnZoned");
	pPlugin->CleanUI           = (fMQCleanUI)GetProcAddress(hmod, "OnCleanUI");
	pPlugin->ReloadUI          = (fMQReloadUI)GetProcAddress(hmod, "OnReloadUI");
	pPlugin->DrawHUD           = (fMQDrawHUD)GetProcAddress(hmod, "OnDrawHUD");
	pPlugin->SetGameState      = (fMQSetGameState)GetProcAddress(hmod, "SetGameState");
	pPlugin->AddSpawn          = (fMQSpawn)GetProcAddress(hmod, "OnAddSpawn");
	pPlugin->RemoveSpawn       = (fMQSpawn)GetProcAddress(hmod, "OnRemoveSpawn");
	pPlugin->AddGroundItem     = (fMQGroundItem)GetProcAddress(hmod, "OnAddGroundItem");
	pPlugin->RemoveGroundItem  = (fMQGroundItem)GetProcAddress(hmod, "OnRemoveGroundItem");
	pPlugin->BeginZone         = (fMQBeginZone)GetProcAddress(hmod, "OnBeginZone");
	pPlugin->EndZone           = (fMQEndZone)GetProcAddress(hmod, "OnEndZone");
	pPlugin->UpdateImGui       = (fMQUpdateImGui)GetProcAddress(hmod, "OnUpdateImGui");
	pPlugin->MacroStart        = (fMQMacroStart)GetProcAddress(hmod, "OnMacroStart");
	pPlugin->MacroStop         = (fMQMacroStop)GetProcAddress(hmod, "OnMacroStop");
	pPlugin->LoadPlugin        = (fMQLoadPlugin)GetProcAddress(hmod, "OnLoadPlugin");
	pPlugin->UnloadPlugin      = (fMQUnloadPlugin)GetProcAddress(hmod, "OnUnloadPlugin");
	pPlugin->GetPluginInterface = (fMQGetPluginInterface)GetProcAddress(hmod, "GetPluginInterface");

	float* ftmp = (float*)GetProcAddress(hmod, "?MQ2Version@@3MA");
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

	// init spawns
	if (pPlugin->AddSpawn && GetGameState() == GAMESTATE_INGAME)
	{
		SPAWNINFO* pSpawn = pSpawnList;
		while (pSpawn)
		{
			pPlugin->AddSpawn(pSpawn);
			pSpawn = pSpawn->pNext;
		}
	}

	// init ground items
	if (pPlugin->AddGroundItem && GetGameState() == GAMESTATE_INGAME)
	{
		EQGroundItem* pItem = pItemList->Top;
		while (pItem)
		{
			pPlugin->AddGroundItem(pItem);
			pItem = pItem->pNext;
		}
	}

	// add to plugin list
	pPlugin->pLast = nullptr;
	pPlugin->pNext = pPlugins;
	if (pPlugins)
		pPlugins->pLast = pPlugin;
	pPlugins = pPlugin;

	// load cfg file if exists
	LoadCfgFile((strFileName + "-AutoExec").c_str(), false);

	PluginsLoadPlugin(strFileName.c_str());

	return 1;
}

bool UnloadMQ2Plugin(const char* pszFilename)
{
	DebugSpew("UnloadMQ2Plugin");

	char Filename[MAX_PATH] = { 0 };
	strcpy_s(Filename, pszFilename);
	_strlwr_s(Filename);
	char* Temp = strstr(Filename, ".dll");
	if (Temp) *Temp = 0;

	// lock before accessing the list
	std::scoped_lock lock(s_pluginsMutex);

	// find plugin in list
	MQPlugin* pPlugin = pPlugins;
	while (pPlugin)
	{
		if (!_stricmp(Filename, pPlugin->szFilename))
		{
			PluginsUnloadPlugin(Filename);

			// unlink from list
			if (pPlugin->pLast)
				pPlugin->pLast->pNext = pPlugin->pNext;
			else
				pPlugins = pPlugin->pNext;
			if (pPlugin->pNext)
				pPlugin->pNext->pLast = pPlugin->pLast;

			// call Plugin:CleanUI
			if (pPlugin->CleanUI)
				pPlugin->CleanUI();

			// call Plugin:Shutdown
			if (pPlugin->Shutdown)
				pPlugin->Shutdown();

			FreeLibrary(pPlugin->hModule);

			delete pPlugin;
			return true;
		}

		pPlugin = pPlugin->pNext;
	}

	return false;
}

// Deprecated
void SaveMQ2PluginLoadStatus(const char* Name, bool bLoad)
{
	std::scoped_lock lock(s_pluginsMutex);

	WritePrivateProfileBool("Plugins", Name, bLoad, mq::internal_paths::MQini);
}

void InitializeMQ2Plugins()
{
	DebugSpew("Initializing plugins");

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

	auto plugins = GetPrivateProfileKeys("Plugins", mq::internal_paths::MQini);
	for (const std::string& pluginName : plugins)
	{
		if (GetPrivateProfileBool("Plugins", pluginName, false, mq::internal_paths::MQini))
		{
			LoadMQ2Plugin(pluginName.c_str());
		}
	}
}

void UnloadMQ2Plugins()
{
	std::scoped_lock lock(s_pluginsMutex);

	while (pPlugins)
	{
		DebugSpew("%s->Unload()", pPlugins->szFilename);
		UnloadMQ2Plugin(pPlugins->szFilename);
	}
}

void ShutdownMQ2Plugins()
{
	s_pluginsInitialized = false;

	std::scoped_lock lock(s_pluginsMutex);
	MQPlugin* pPlugin = nullptr;
	while (pPlugins)
	{
		DebugSpew("%s->Unload()", pPlugins->szFilename);
		UnloadMQ2Plugin(pPlugins->szFilename);
	}
	pPlugins = pPlugin;
}

void PluginsWriteChatColor(const char* Line, int Color, int Filter)
{
	if (!s_pluginsInitialized)
		return;
	if (gFilterMQ)
		return;

	PluginDebug("Begin WriteChatColor()");
	EnterMQ2Benchmark(bmWriteChatColor);

	if (size_t len = strlen(Line))
	{
		std::unique_ptr<char[]> plainText = std::make_unique<char[]>(len + 1);

		StripMQChat(Line, plainText.get());
		CheckChatForEvent(plainText.get());

		DebugSpew("WriteChatColor(%s)", Line);
	}

	for (const MQModule* module : gInternalModules)
	{
		if (module->WriteChatColor)
		{
			module->WriteChatColor(Line, Color, Filter);
		}
	}

	// enter lock before accessing the plugin list
	std::scoped_lock lock(s_pluginsMutex);
	MQPlugin* pPlugin = pPlugins;
	while (pPlugin)
	{
		if (pPlugin->WriteChatColor)
		{
			pPlugin->WriteChatColor(Line, Color, Filter);
		}

		pPlugin = pPlugin->pNext;
	}

	ExitMQ2Benchmark(bmWriteChatColor);
}

bool PluginsIncomingChat(const char* Line, DWORD Color)
{
	if (!s_pluginsInitialized)
		return false;
	if (!Line[0])
		return false;

	PluginDebug("PluginsIncomingChat()");

	std::scoped_lock lock(s_pluginsMutex);
	bool Ret = false;
	MQPlugin* pPlugin = pPlugins;
	while (pPlugin)
	{
		if (pPlugin->IncomingChat)
		{
			Ret = Ret || pPlugin->IncomingChat(Line, Color);
		}

		pPlugin = pPlugin->pNext;
	}

	return Ret;
}

void PulsePlugins()
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PulsePlugins()");

	for (const MQModule* module : gInternalModules)
	{
		if (module->Pulse)
		{
			module->Pulse();
		}
	}

	std::scoped_lock lock(s_pluginsMutex);
	MQPlugin* pPlugin = pPlugins;
	while (pPlugin)
	{
		if (pPlugin->Pulse)
		{
			pPlugin->Pulse();
		}

		pPlugin = pPlugin->pNext;
	}
}

void PluginsZoned()
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsZoned()");

	for (const MQModule* module : gInternalModules)
	{
		if (module->Zoned)
		{
			module->Zoned();
		}
	}

	std::scoped_lock lock(s_pluginsMutex);
	MQPlugin* pPlugin = pPlugins;
	while (pPlugin)
	{
		if (pPlugin->Zoned)
		{
			DebugSpew("%s->Zoned()", pPlugin->szFilename);
			pPlugin->Zoned();
		}

		pPlugin = pPlugin->pNext;
	}

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

	std::scoped_lock lock(s_pluginsMutex);
	MQPlugin* pPlugin = pPlugins;
	while (pPlugin)
	{
		if (pPlugin->CleanUI)
		{
			DebugSpew("%s->CleanUI()", pPlugin->szFilename);
			pPlugin->CleanUI();
		}
		pPlugin = pPlugin->pNext;
	}
}

void PluginsReloadUI()
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsReloadUI()");

	std::scoped_lock lock(s_pluginsMutex);
	MQPlugin* pPlugin = pPlugins;
	while (pPlugin)
	{
		if (pPlugin->ReloadUI)
		{
			DebugSpew("%s->ReloadUI()", pPlugin->szFilename);
			pPlugin->ReloadUI();
		}

		pPlugin = pPlugin->pNext;
	}
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

	for (const MQModule* module : gInternalModules)
	{
		if (module->SetGameState)
		{
			module->SetGameState(GameState);
		}
	}

	std::scoped_lock lock(s_pluginsMutex);
	MQPlugin* pPlugin = pPlugins;
	while (pPlugin)
	{
		if (pPlugin->SetGameState)
		{
			DebugSpew("%s->SetGameState(%d)", pPlugin->szFilename, GameState);
			pPlugin->SetGameState(GameState);
		}

		pPlugin = pPlugin->pNext;
	}
}

void PluginsDrawHUD()
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsDrawHUD()");

	std::scoped_lock lock(s_pluginsMutex);
	MQPlugin* pPlugin = pPlugins;
	while (pPlugin)
	{
		if (pPlugin->DrawHUD)
		{
			pPlugin->DrawHUD();
		}

		pPlugin = pPlugin->pNext;
	}
}

void PluginsAddSpawn(SPAWNINFO* pNewSpawn)
{
	if (!s_pluginsInitialized)
		return;

	DWORD BodyType = GetBodyType(pNewSpawn);
	PluginDebug("PluginsAddSpawn(%s,%d,%d)", pNewSpawn->Name, pNewSpawn->mActorClient.Race, BodyType);

	if (GetGameState() > GAMESTATE_CHARSELECT)
		SetNameSpriteState(pNewSpawn, true);

	if (GetBodyTypeDesc(BodyType)[0] == '*')
		WriteChatf("Spawn '%s' has unknown bodytype %d", pNewSpawn->Name, BodyType);

	for (const MQModule* module : gInternalModules)
	{
		if (module->SpawnAdded)
		{
			module->SpawnAdded(pNewSpawn);
		}
	}

	std::scoped_lock lock(s_pluginsMutex);
	MQPlugin* pPlugin = pPlugins;
	while (pPlugin)
	{
		if (pPlugin->AddSpawn)
		{
			pPlugin->AddSpawn(pNewSpawn);
		}

		pPlugin = pPlugin->pNext;
	}
}

void PluginsRemoveSpawn(SPAWNINFO* pSpawn)
{
	InvalidateObservedEQObject(pSpawn);

	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsRemoveSpawn(%s)", pSpawn->Name);

	ClearCachedBuffsSpawn(pSpawn);

	for (const MQModule* module : gInternalModules)
	{
		if (module->SpawnRemoved)
		{
			module->SpawnRemoved(pSpawn);
		}
	}

	std::scoped_lock lock(s_pluginsMutex);
	MQPlugin* pPlugin = pPlugins;
	while (pPlugin)
	{
		if (pPlugin->RemoveSpawn)
		{
			pPlugin->RemoveSpawn(pSpawn);
		}
		pPlugin = pPlugin->pNext;
	}
}

void PluginsAddGroundItem(GROUNDITEM* pNewGroundItem)
{
	if (!s_pluginsInitialized)
		return;

	if (!pNewGroundItem)
	{
		DebugSpew("PluginsAddGroundItem was NULL");
		return;
	}

	DebugSpew("PluginsAddGroundItem(%s) %.1f,%.1f,%.1f", pNewGroundItem->Name, pNewGroundItem->X, pNewGroundItem->Y, pNewGroundItem->Z);

	std::scoped_lock lock(s_pluginsMutex);
	MQPlugin* pPlugin = pPlugins;
	while (pPlugin)
	{
		if (pPlugin->AddGroundItem)
		{
			pPlugin->AddGroundItem(pNewGroundItem);
		}
		pPlugin = pPlugin->pNext;
	}
}

void PluginsRemoveGroundItem(GROUNDITEM* pGroundItem)
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsRemoveGroundItem()");

	std::scoped_lock lock(s_pluginsMutex);
	MQPlugin* pPlugin = pPlugins;
	while (pPlugin)
	{
		if (pPlugin->RemoveGroundItem)
		{
			pPlugin->RemoveGroundItem(pGroundItem);
		}

		pPlugin = pPlugin->pNext;
	}
}

void PluginsBeginZone()
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsBeginZone()");

	gbInZone = false;
	gZoning = true;

	for (const MQModule* module : gInternalModules)
	{
		if (module->BeginZone)
		{
			module->BeginZone();
		}
	}

	std::scoped_lock lock(s_pluginsMutex);
	MQPlugin* pPlugin = pPlugins;
	while (pPlugin)
	{
		if (pPlugin->BeginZone)
		{
			DebugSpew("%s->BeginZone()", pPlugin->szFilename);
			pPlugin->BeginZone();
		}
		pPlugin = pPlugin->pNext;
	}
}

void PluginsEndZone()
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsEndZone()");

	gbInZone = true;
	WereWeZoning = true;
	LastEnteredZone = MQGetTickCount64();

	for (const MQModule* module : gInternalModules)
	{
		if (module->EndZone)
		{
			module->EndZone();
		}
	}

	std::scoped_lock lock(s_pluginsMutex);
	MQPlugin* pPlugin = pPlugins;
	while (pPlugin)
	{
		if (pPlugin->EndZone)
		{
			DebugSpew("%s->EndZone()", pPlugin->szFilename);
			pPlugin->EndZone();
		}

		pPlugin = pPlugin->pNext;
	}

	LoadCfgFile("zoned", true);
	LoadCfgFile(pZoneInfo->ShortName, false);
}

void PluginsUpdateImGui()
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsUpdateImGui");

	for (const MQModule* module : gInternalModules)
	{
		if (module->UpdateImGui)
		{
			module->UpdateImGui();
		}
	}

	if (!gbManualResetRequired)
	{
		std::scoped_lock lock(s_pluginsMutex);

		MQPlugin* pPlugin = pPlugins;
		while (pPlugin)
		{
			if (pPlugin->UpdateImGui)
			{
				pPlugin->UpdateImGui();
			}

			pPlugin = pPlugin->pNext;
		}
	}
}

void PluginsMacroStart(const char* Name)
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsMacroStart");

	std::scoped_lock lock(s_pluginsMutex);
	MQPlugin* pPlugin = pPlugins;
	while (pPlugin)
	{
		if (pPlugin->MacroStart)
			pPlugin->MacroStart(Name);

		pPlugin = pPlugin->pNext;
	}
}

void PluginsMacroStop(const char* Name)
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsMacroStop");

	std::scoped_lock lock(s_pluginsMutex);
	MQPlugin* pPlugin = pPlugins;
	while (pPlugin)
	{
		if (pPlugin->MacroStop)
			pPlugin->MacroStop(Name);

		pPlugin = pPlugin->pNext;
	}
}

void PluginsLoadPlugin(const char* Name)
{
	if (!s_pluginsInitialized)
		return;

	PluginDebug("PluginsLoadPlugin");

	std::scoped_lock lock(s_pluginsMutex);
	MQPlugin* pPlugin = pPlugins;
	while (pPlugin)
	{
		if (pPlugin->LoadPlugin)
			pPlugin->LoadPlugin(Name);

		pPlugin = pPlugin->pNext;
	}
}

void PluginsUnloadPlugin(const char* Name)
{
	PluginDebug("PluginsUnloadPlugin");

	std::scoped_lock lock(s_pluginsMutex);
	MQPlugin* pPlugin = pPlugins;
	while (pPlugin)
	{
		if (pPlugin->UnloadPlugin)
			pPlugin->UnloadPlugin(Name);

		pPlugin = pPlugin->pNext;
	}
}


bool IsPluginsInitialized()
{
	return s_pluginsInitialized;
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

MQPlugin* GetPlugin(std::string_view PluginName)
{
	MQPlugin* pPlugin = pPlugins;
	while (pPlugin && !ci_equals(PluginName, pPlugin->szFilename)) pPlugin = pPlugin->pNext;
	return pPlugin;
}

bool IsPluginLoaded(std::string_view PluginName)
{
	return GetPlugin(PluginName) != nullptr;
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


} // namespace mq
