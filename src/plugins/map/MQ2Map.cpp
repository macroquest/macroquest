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

#include <mq/Plugin.h>

#include "MQ2Map.h"
#include "MapObject.h"

#include <sstream>

PreSetup("MQ2Map");

long repeatLast = 0;
long repeatInterval = 10;
clock_t highPulseRepeatLast = clock();
long highPulseRepeatIntervalMillis = 50;
uint32_t bmMapRefresh = 0;
int activeLayer = 2;
float CampX = 0.0f;
float CampY = 0.0f;
float PullX = 0.0f;
float PullY = 0.0f;
uint16_t currentZoneId = 0;
bool repeatMaphide = false;
bool repeatMapshow = false;
MQColor HighlightColor = MQColor(112, 0, 112);
int HighlightSIDELEN = 100;
bool HighlightPulse = false;
bool HighlightPulseIncreasing = true;
int HighlightPulseIndex = 0;
int HighlightPulseDiff = HighlightSIDELEN / 10;
extern MapObject* gpActiveMapObjects;

#define INVALID_FLOOR ((float)-1.0e27)

char MapSpecialClickString[MAX_CLICK_STRINGS][MAX_STRING] =
{
	"",                      // unused, will always target
	"",                      // SHIFT
	"/maphide id %i",        // CTRL
	"",                      // CTRL|SHIFT
	"/highlight id %i",      // LALT
	"",                      // LALT|SHIFT
	"",                      // LALT|CTRL
	"",                      // LALT|SHIFT|CTRL
	"",                      // RALT
	"",                      // RALT|SHIFT
	"",                      // RALT|CTRL
	"",                      // RALT|SHIFT|CTRL
	"",                      // RALT|LALT
	"",                      // RALT|LALT|SHIFT
	"",                      // RALT|LALT|CTRL
	""                       // RALT|LALT|SHIFT|CTRL
};

char MapLeftClickString[MAX_CLICK_STRINGS][MAX_STRING] =
{
	"",                      //  unused, will always target
	"",                      // SHIFT
	"",                      // CTRL
	"/nav locxy %x %y",      // CTRL|SHIFT
	"",                      // LALT
	"",                      // LALT|SHIFT
	"",                      // LALT|CTRL
	"",                      // LALT|SHIFT|CTRL
	"",                      // RALT
	"",                      // RALT|SHIFT
	"",                      // RALT|CTRL
	"",                      // RALT|SHIFT|CTRL
	"",                      // RALT|LALT
	"",                      // RALT|LALT|SHIFT
	"",                      // RALT|LALT|CTRL
	""                       // RALT|LALT|SHIFT|CTRL
};

char MapNameString[MAX_STRING] = { "%N" };
char MapTargetNameString[MAX_STRING] = { "%N" };
char mapshowStr[MAX_STRING] = { "" };
char maphideStr[MAX_STRING] = { "" };
MQSpawnSearch MapFilterCustom;
MQSpawnSearch MapFilterNamed;

MapFilterOption MapFilterInvalidOption =
	{ nullptr,        false, MQColor(255, 255, 255), MapFilter::Invalid, 0, nullptr };

MapFilterOption MapFilterOptions[] =
{
	{ "All",          true,  MQColor(),              MapFilter::Invalid, MapFilterOption::Toggle | MapFilterOption::NoColor | MapFilterOption::Regenerate,
	                  "Enables/disables map functions" },

	{ "PC",           false, MQColor(255, 0, 255),   MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate,
	                  "Displays PCs" },
	{ "PCConColor",   false, MQColor(),              MapFilter::PC,      MapFilterOption::Toggle | MapFilterOption::NoColor,
	                  "Displays PCs in consider colors" },
	{ "Group",        false, MQColor(0, 128, 192),   MapFilter::PC,      MapFilterOption::Toggle,
	                  "Displays group members in a specific color" },
	{ "Mount",        false, MQColor(112, 112, 112), MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate,
	                  "Displays mounts" },
	{ "NPC",          false, MQColor(64, 64, 64),    MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate,
	                  "Displays NPCs" },
	{ "NPCConColor",  false, MQColor(),              MapFilter::NPC,     MapFilterOption::Toggle | MapFilterOption::NoColor,
	                  "Displays NPCs in consider colors" },
	{ "Untargetable", false, MQColor(64, 64, 64),    MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate,
	                  "Displays Untargetable NPCs" },
	{ "Pet",          false, MQColor(112, 112, 112), MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate,
	                  "Displays pets" },
	{ "Corpse",       false, MQColor(0, 192, 0),     MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate,
	                  "Displays corpses" },
	{ "Chest",        false, MQColor(192, 128, 0),   MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate,
	                  "Displays chests" },
	{ "Trigger",      false, MQColor(192, 128, 0),   MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate,
	                  "Displays hidden triggers" },
	{ "Trap",         false, MQColor(192, 128, 0),   MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate,
	                  "Displays hidden traps" },
	{ "Timer",        false, MQColor(192, 128, 0),   MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate,
	                  "Displays hidden timers" },
	{ "Ground",       false, MQColor(192, 192, 192), MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate,
	                  "Displays ground items" },
	{ "Target",       false, MQColor(192, 0, 0),     MapFilter::All,     MapFilterOption::Toggle,
	                  "Displays your target" },
	{ "TargetLine",   false, MQColor(128, 0, 0),     MapFilter::Target,  MapFilterOption::Toggle,
	                  "Displays a line to your target" },
	{ "TargetRadius", false, MQColor(128, 128, 128), MapFilter::Target,  MapFilterOption::UsesRadius,
	                  "Sets radius of a circle around your target to # (omit or set to 0 to disable)" },
	{ "TargetMelee",  false, MQColor(255, 128, 128), MapFilter::Target,  MapFilterOption::UsesRadius,
	                  "Draws a melee-range circle around your target" },
	{ "Vector",       false, MQColor(),              MapFilter::All,     MapFilterOption::NoColor | MapFilterOption::Toggle | MapFilterOption::Regenerate,
	                  "Displays heading vectors" },
	{ "Custom",       false, MQColor(),              MapFilter::All,     MapFilterOption::NoColor | MapFilterOption::Regenerate,
	                  "Sets custom filter (omit to disable)" },
	{ "CastRadius",   false, MQColor(128, 128, 128), MapFilter::All,     MapFilterOption::UsesRadius,
	                  "Sets radius of casting circle to # (omit or set to 0 to disable)" },
	{ "NormalLabels", false, MQColor(),              MapFilter::Invalid, MapFilterOption::Toggle | MapFilterOption::NoColor,
	                  "Toggles non-MQ2 label display" },
	{ "Menu",         false, MQColor(),              MapFilter::Invalid, MapFilterOption::Toggle | MapFilterOption::NoColor,
	                  "Allows display of right-click context menu" },
	{ "SpellRadius",  false, MQColor(0, 192, 0),     MapFilter::All,     MapFilterOption::UsesRadius,
	                  "Sets radius of 2nd casting circle to # (omit or set to 0 to disable)" },
	{ "Aura",         false, MQColor(64, 64, 64),    MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate,
	                  "Displays Auras" },
	{ "Object",       false, MQColor(64, 64, 64),    MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate,
	                  "Displays inanimate objects" },
	{ "Banner",       false, MQColor(64, 64, 64),    MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate,
	                  "Displays banners" },
	{ "Campfire",     false, MQColor(64, 64, 64),    MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate,
	                  "Displays campfires" },
	{ "PCCorpse",     false, MQColor(0, 192, 0),     MapFilter::Corpse,  MapFilterOption::Toggle | MapFilterOption::Regenerate,
	                  "Displays PC corpses, when corpse setting is on" },
	{ "NPCCorpse",    false, MQColor(0, 192, 0),     MapFilter::Corpse,  MapFilterOption::Toggle | MapFilterOption::Regenerate,
	                  "Displays NPC corpses, when corpse setting is on" },
	{ "Mercenary",    false, MQColor(64, 64, 64),    MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate,
	                  "Displays mercenaries" },
	{ "Named",        false, MQColor(64, 64, 64),    MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate,
	                  "Displays named NPCs" },
	{ "TargetPath",   false, MQColor(),              MapFilter::Target,  MapFilterOption::NoColor | MapFilterOption::Toggle,
	                  "Draws EQ Path to selected target" },
	{ "Marker",       false, MQColor(),              MapFilter::All,     MapFilterOption::NoColor | MapFilterOption::Regenerate,
	                  "Displays marker (mobtype triangle/square/diamond size)" },
	{ "CampRadius",   false, MQColor(128, 128, 128), MapFilter::All,     MapFilterOption::UsesRadius,
	                  "Sets radius of Camp circle to # (omit or set to 0 to disable)" },
	{ "PullRadius",   false, MQColor(128, 128, 128), MapFilter::All,     MapFilterOption::UsesRadius,
	                  "Sets radius of casting circle to # (omit or set to 0 to disable)" },

	MapFilterInvalidOption,
};

// This class inherits from MapViewMap to set up virtual functions, but we
// do not ever actually instantiate this class. As a result, we can't store any
// data members in it. We're using some tricks to use the compiler's generation
// of the virtual function table to essentially inherit this class and override
// virtuals.
class CCustomMapViewMap : public MapViewMap
{
public:
	inline static VirtualFunctionTable* s_mapViewWndTablePatched = nullptr;
	inline static VirtualFunctionTable* s_mapViewWndTableOrig = nullptr;
	inline static bool s_patchingVFTable = false;

	// We need to do this *before* we patch the constructor.
	static VirtualFunctionTable* GetPatchedVFTable()
	{
		static VirtualFunctionTable* table = nullptr;

		if (table == nullptr)
		{
			// If we crash here, it means that the size of
			// MapViewMap is off.
			CCustomMapViewMap tempMap;
			table = tempMap.GetVFTable();
		}

		return table;
	}

	static void HookVFTable(MapViewMap* pThis)
	{
		if (s_patchingVFTable)
			return;
		s_patchingVFTable = true;

		// initialize the MapViewMap patched virtual function table
		s_mapViewWndTablePatched = GetPatchedVFTable();

		// save the original vftable in case we need to put it back
		s_mapViewWndTableOrig = pThis->GetVFTable();

		// now replace with the patched version
		pThis->ReplaceVFTable(s_mapViewWndTablePatched);

		s_patchingVFTable = false;
	}

	static void UnhookVFTable(MapViewMap* pThis)
	{
		// put the original table back
		pThis->ReplaceVFTable(s_mapViewWndTableOrig);
	}

	virtual int PostDraw() override
	{
		MapUpdate();
		MapAttach();
		int result = MapViewMap::PostDraw();
		MapDetach();
		return result;
	}

	virtual int HandleLButtonDown(const CXPoint& pos, uint32_t flags) override
	{
		CVector3 points = { (float)pos.x, (float)pos.y, 0.f };
		GetWorldCoordinates(points); // this writes the world X & Y coords into points

		std::vector<float> z_hits;

		float curr_z = 0.0f;
		for (float f = pZoneInfo->Ceiling; f > pZoneInfo->Floor; f -= 2.0f)
		{
			curr_z = pDisplay->GetFloorHeight(points.X, points.Y, f);
			if (curr_z != INVALID_FLOOR)
			{
				break;
			}
		}

		do
		{
			z_hits.push_back(curr_z);
			curr_z = pDisplay->GetFloorHeight(points.X, points.Y, curr_z - 2.f);
		} while (curr_z >= pZoneInfo->Floor - 1.f);

		MapClickLocation(points.X, points.Y, z_hits);

		return MapViewMap::HandleLButtonDown(pos, flags);
	}

	virtual int HandleRButtonDown(const CXPoint& pos, uint32_t flags) override
	{
		bool handleClick = false;

		if (pCurrentMapLabel)
		{
			handleClick = MapSelectTarget();
		}
		else
		{
			handleClick = IsOptionEnabled(MapFilter::ContextMenu);
		}

		if (handleClick)
		{
			return MapViewMap::HandleRButtonDown(pos, flags);
		}

		return 0;
	}
};

// Note: Do not combine this with CCustomMapViewMap, as it will change the
// layout of the function pointers used in the detour, which will break the detour.
class CMapViewWndHook
{
public:
	DETOUR_TRAMPOLINE_DEF(CMapViewWnd*, Constructor_Trampoline, (CXWnd*))
	CMapViewWnd* Constructor_Detour(CXWnd* pParent)
	{
		CMapViewWnd* pThis = Constructor_Trampoline(pParent);
		// the global pMapViewWnd isn't set yet, access MapView from this pointer.
		CCustomMapViewMap* pMapViewMap = static_cast<CCustomMapViewMap*>(&pThis->MapView);
		CCustomMapViewMap::HookVFTable(pMapViewMap);
		return pThis;
	}
};

// Called once, when the plugin is to initialize
PLUGIN_API void InitializePlugin()
{
	bmMapRefresh = AddMQ2Benchmark("Map Refresh");

	char szBuffer[MAX_STRING] = { 0 };

	for (int i = 0; MapFilterOptions[i].szName; i++)
	{
		MapFilterOption& option = MapFilterOptions[i];

		// If it's the CampRadius or PullRadius, let's not get the last on/off state, lets assume it's off so we don't draw a circle at 0, 0.
		if (_stricmp(option.szName, "CampRadius") && _stricmp(option.szName, "PullRadius"))
		{
			option.Enabled = GetPrivateProfileInt("Map Filters", option.szName, option.Default, INIFileName);
		}
		else
		{
			option.Enabled = 0;
		}

		// Lets see what color option was last saved as, if any. If none then use the default.
		option.Color.SetARGB(GetPrivateProfileInt("Map Filters", fmt::format("{}-Color", option.szName), option.DefaultColor.ToARGB(), INIFileName));
		option.Color.Alpha = 255; // always enforce 255 alpha channel
		option.MarkerSize = GetPrivateProfileInt("Marker Filters", fmt::format("{}-Size", option.szName), 0, INIFileName);

		std::string markerString = GetPrivateProfileString("Marker Filters", option.szName, "None", INIFileName);
		option.Marker = FindMarker(markerString, MarkerType::None);
	}

	activeLayer = GetPrivateProfileInt("Map Filters", "ActiveLayer", activeLayer, INIFileName);

	UpdateDefaultMapLocParams();

	repeatMapshow = GetPrivateProfileBool("Map Filters", "Mapshow-Repeat", false, INIFileName);
	repeatMaphide = GetPrivateProfileBool("Map Filters", "Maphide-Repeat", false, INIFileName);

	HighlightSIDELEN = GetPrivateProfileInt("Map Filters", "HighSize", HighlightSIDELEN, INIFileName);
	HighlightPulse = GetPrivateProfileBool("Map Filters", "HighPulse", HighlightPulse, INIFileName);
	HighlightPulseIncreasing = true;
	HighlightPulseIndex = 0;
	HighlightPulseDiff = HighlightSIDELEN / 10;

	GetPrivateProfileString("Map Filters", "Mapshow", "", mapshowStr, MAX_STRING, INIFileName);
	GetPrivateProfileString("Map Filters", "Maphide", "", maphideStr, MAX_STRING, INIFileName);
	GetPrivateProfileString("Naming Schemes", "Normal", "%N", MapNameString, MAX_STRING, INIFileName);
	GetPrivateProfileString("Naming Schemes", "Target", "%N", MapTargetNameString, MAX_STRING, INIFileName);

	for (int i = 1; i < MAX_CLICK_STRINGS; i++)
	{
		sprintf_s(szBuffer, "KeyCombo%d", i);
		GetPrivateProfileString("Right Click", szBuffer, MapSpecialClickString[i], MapSpecialClickString[i], MAX_STRING, INIFileName);
		GetPrivateProfileString("Left Click", szBuffer, MapLeftClickString[i], MapLeftClickString[i], MAX_STRING, INIFileName);
	}

	// Do not use Custom, since the string isn't stored
	MapFilterOptions[static_cast<size_t>(MapFilter::Custom)].Enabled = false;

	AddCommand("/mapfilter", MapFilters, false, true, true);
	AddCommand("/maphide", MapHideCmd, false, true, true);
	AddCommand("/mapshow", MapShowCmd, false, true, true);
	AddCommand("/highlight", MapHighlightCmd, false, true, true);
	AddCommand("/mapnames", MapNames, false, true, true);
	AddCommand("/mapclick", MapClickCommand, false, true, false);
	AddCommand("/mapactivelayer", MapActiveLayerCmd, false, true, true);
	AddCommand("/maploc", MapSetLocationCmd, false, true, true);

	// Hook the constructor. If window already exists then we just hook the vftable.
	// If it does not exist then we need to hook the constructor to do the same thing when the window is created.
	EzDetour(CMapViewWnd__CMapViewWnd, &CMapViewWndHook::Constructor_Detour, &CMapViewWndHook::Constructor_Trampoline);
	if (pMapViewWnd)
	{
		CCustomMapViewMap::HookVFTable(&pMapViewWnd->MapView);
	}

	AddMQ2Data("MapSpawn", dataMapSpawn);
	ClearSearchSpawn(&MapFilterNamed);
	ParseSearchSpawn("#", &MapFilterNamed);

	AddSettingsPanel("plugins/Map", DrawMapSettingsPanel);

	MapInit();
}

// Called once, when the plugin is to shutdown
PLUGIN_API void ShutdownPlugin()
{
	RemoveMQ2Data("MapSpawn");

	if (pMapViewWnd)
	{
		CCustomMapViewMap::UnhookVFTable(&pMapViewWnd->MapView);
	}
	RemoveDetour(CMapViewWnd__CMapViewWnd);

	MapClear();

	RemoveMQ2Benchmark(bmMapRefresh);
	RemoveCommand("/maphide");
	RemoveCommand("/mapshow");
	RemoveCommand("/mapfilter");
	RemoveCommand("/highlight");
	RemoveCommand("/mapnames");
	RemoveCommand("/mapclick");
	RemoveCommand("/mapactivelayer");
	RemoveCommand("/maploc");

	RemoveSettingsPanel("plugins/Map");
}

// This is called every time MQ pulses
PLUGIN_API void OnPulse()
{
	if (GetGameState() != GAMESTATE_INGAME)
		return;

	long curTime = MakeTime();
	clock_t curClockTime = clock();
	bool cleared = false;

	// Clear MapLocs on zone
	if (CHARINFO* charInfo = GetCharInfo())
	{
		if (currentZoneId != (charInfo->zoneId & 0x7FFF))
		{
			DeleteAllMapLocs();

			currentZoneId = (charInfo->zoneId & 0x7FFF);
		}
	}

	if (curClockTime > highPulseRepeatLast + highPulseRepeatIntervalMillis && HighlightPulse)
	{
		if (HighlightPulseIndex == 5 || HighlightPulseIndex == -5)
			HighlightPulseIncreasing = !HighlightPulseIncreasing;

		if (HighlightPulseIncreasing)
			HighlightPulseIndex++;
		else
			HighlightPulseIndex--;

		highPulseRepeatLast = curClockTime;
	}

	if (curTime > repeatLast + repeatInterval)
	{
		static MQSpawnSearch ss;

		if (repeatMapshow && strlen(mapshowStr) > 0)
		{
			if (!cleared)
			{
				MapClear();
				MapGenerate();
				cleared = true;
			}

			ClearSearchSpawn(&ss);
			ParseSearchSpawn(mapshowStr, &ss);
			MapShow(ss);
		}

		if (repeatMaphide && strlen(maphideStr) > 0)
		{
			if (!cleared)
			{
				MapClear();
				MapGenerate();
				cleared = true;
			}

			ClearSearchSpawn(&ss);
			ParseSearchSpawn(maphideStr, &ss);
			MapHide(ss);
		}

		repeatLast = curTime;
	}
}

PLUGIN_API void OnAddSpawn(SPAWNINFO* pNewSpawn)
{
	// your toon's spawn id changes and it's no longer zero to start don't added it all
	if (pLocalPlayer != pNewSpawn && pNewSpawn->SpawnID != 0)
	{
		AddSpawn(pNewSpawn);
	}
}

PLUGIN_API void OnRemoveSpawn(SPAWNINFO* pSpawn)
{
	RemoveSpawn(pSpawn);
}

PLUGIN_API void SetGameState(DWORD GameState)
{
	if (GameState == GAMESTATE_POSTCHARSELECT)
	{
		MapClear();
	}
}

PLUGIN_API void OnAddGroundItem(PGROUNDITEM pNewGroundItem)
{
	AddGroundItem(pNewGroundItem);
}

PLUGIN_API void OnRemoveGroundItem(PGROUNDITEM pGroundItem)
{
	RemoveGroundItem(pGroundItem);
}

PLUGIN_API MapViewLine* MQ2MapAddLine()
{
	return InitLine();
}

PLUGIN_API void MQ2MapDeleteLine(MapViewLine* pLine)
{
	DeleteLine(pLine);
}
