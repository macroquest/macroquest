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

#include <mq/Plugin.h>

#include "eqlib/WindowOverride.h"
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
std::vector<MapFilterOption*> mapFilterObjectOptions;
std::vector<MapFilterOption*> mapFilterGeneralOptions;

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
	{ nullptr,        false, MapFilter::Invalid, MQColor(255, 255, 255), MapFilter::Invalid, 0, nullptr };

std::vector<MapFilterOption> MapFilterOptions =
{
	{ "All",          true,  MapFilter::All,			MQColor(),              MapFilter::Invalid, MapFilterOption::Toggle | MapFilterOption::NoColor | MapFilterOption::Regenerate,
	                  "Enables/disables map functions" },

	{ "PC",           false, MapFilter::PC,				MQColor(255, 0, 255),   MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate | MapFilterOption::Object,
	                  "Displays PCs" },
	{ "PCConColor",   false, MapFilter::PCConColor,		MQColor(),              MapFilter::PC,      MapFilterOption::Toggle | MapFilterOption::NoColor,
	                  "Displays PCs in consider colors" },
	{ "Group",        false, MapFilter::Group,			MQColor(0, 128, 192),   MapFilter::PC,      MapFilterOption::Toggle,
	                  "Displays group members in a specific color" },
	{ "Mount",        false, MapFilter::Mount,			MQColor(112, 112, 112), MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate | MapFilterOption::Object,
	                  "Displays mounts" },
	{ "NPC",          false, MapFilter::NPC,			MQColor(64, 64, 64),    MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate | MapFilterOption::Object,
	                  "Displays NPCs" },
	{ "NPCConColor",  false, MapFilter::NPCConColor,	MQColor(),              MapFilter::NPC,     MapFilterOption::Toggle | MapFilterOption::NoColor,
	                  "Displays NPCs in consider colors" },
	{ "Untargetable", false, MapFilter::Untargetable,	MQColor(64, 64, 64),    MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate | MapFilterOption::Object,
	                  "Displays Untargetable NPCs" },
	{ "Pet",          false, MapFilter::Pet,			MQColor(112, 112, 112), MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate | MapFilterOption::Object,
	                  "Displays pets" },
	{ "Corpse",       false, MapFilter::Corpse,			MQColor(0, 192, 0),     MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate | MapFilterOption::Object,
	                  "Displays corpses" },
	{ "Chest",        false, MapFilter::Chest,			MQColor(192, 128, 0),   MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate | MapFilterOption::Object,
	                  "Displays chests" },
	{ "Trigger",      false, MapFilter::Trigger,		MQColor(192, 128, 0),   MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate | MapFilterOption::Object,
	                  "Displays hidden triggers" },
	{ "Trap",         false, MapFilter::Trap,			MQColor(192, 128, 0),   MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate | MapFilterOption::Object,
	                  "Displays hidden traps" },
	{ "Timer",        false, MapFilter::Timer,			MQColor(192, 128, 0),   MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate | MapFilterOption::Object,
	                  "Displays hidden timers" },
	{ "Ground",       false, MapFilter::Ground,			MQColor(192, 192, 192), MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate | MapFilterOption::Object,
	                  "Displays ground items" },
	{ "Target",       false, MapFilter::Target,			MQColor(192, 0, 0),     MapFilter::All,     MapFilterOption::Toggle,
	                  "Displays your target" },
	{ "TargetLine",   false, MapFilter::TargetLine,		MQColor(128, 0, 0),     MapFilter::Target,  MapFilterOption::Toggle,
	                  "Displays a line to your target" },
	{ "TargetRadius", false, MapFilter::TargetRadius,	MQColor(128, 128, 128), MapFilter::Target,  MapFilterOption::UsesRadius,
	                  "Sets radius of a circle around your target to # (omit or set to 0 to disable)" },
	{ "TargetMelee",  false, MapFilter::TargetMelee,	MQColor(255, 128, 128), MapFilter::Target,  MapFilterOption::Toggle,
	                  "Draws a melee-range circle around your target" },
	{ "Vector",       false, MapFilter::Vector,			MQColor(),              MapFilter::All,     MapFilterOption::NoColor | MapFilterOption::Toggle | MapFilterOption::Regenerate,
	                  "Displays heading vectors" },
	{ "Custom",       false, MapFilter::Custom,			MQColor(),              MapFilter::All,     MapFilterOption::NoColor | MapFilterOption::Regenerate,
	                  "Sets custom filter (omit to disable)" },
	{ "CastRadius",   false, MapFilter::CastRadius,		MQColor(128, 128, 128), MapFilter::All,     MapFilterOption::UsesRadius,
	                  "Sets radius of casting circle to # (omit or set to 0 to disable)" },
	{ "NormalLabels", false, MapFilter::NormalLabels,	MQColor(),              MapFilter::Invalid, MapFilterOption::Toggle | MapFilterOption::NoColor,
	                  "Toggles non-MQ2 label display" },
	{ "Menu",         false, MapFilter::ContextMenu,	MQColor(),              MapFilter::Invalid, MapFilterOption::Toggle | MapFilterOption::NoColor,
	                  "Allows display of right-click context menu" },
	{ "SpellRadius",  false, MapFilter::SpellRadius,	MQColor(0, 192, 0),     MapFilter::All,     MapFilterOption::UsesRadius,
	                  "Sets radius of 2nd casting circle to # (omit or set to 0 to disable)" },
	{ "Aura",         false, MapFilter::Aura,			MQColor(64, 64, 64),    MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate | MapFilterOption::Object,
	                  "Displays Auras" },
	{ "Object",       false, MapFilter::Object,			MQColor(64, 64, 64),    MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate | MapFilterOption::Object,
	                  "Displays inanimate objects" },
	{ "Banner",       false, MapFilter::Banner,			MQColor(64, 64, 64),    MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate | MapFilterOption::Object,
	                  "Displays banners" },
	{ "Campfire",     false, MapFilter::Campfire,		MQColor(64, 64, 64),    MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate | MapFilterOption::Object,
	                  "Displays campfires" },
	{ "PCCorpse",     false, MapFilter::PCCorpse,		MQColor(0, 192, 0),     MapFilter::Corpse,  MapFilterOption::Toggle | MapFilterOption::Regenerate | MapFilterOption::Object,
	                  "Displays PC corpses, when corpse setting is on" },
	{ "NPCCorpse",    false, MapFilter::NPCCorpse,		MQColor(0, 192, 0),     MapFilter::Corpse,  MapFilterOption::Toggle | MapFilterOption::Regenerate | MapFilterOption::Object,
	                  "Displays NPC corpses, when corpse setting is on" },
	{ "Mercenary",    false, MapFilter::Mercenary,		MQColor(64, 64, 64),    MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate | MapFilterOption::Object,
	                  "Displays mercenaries" },
	{ "Named",        false, MapFilter::Named,			MQColor(64, 64, 64),    MapFilter::All,     MapFilterOption::Toggle | MapFilterOption::Regenerate,
	                  "Displays named NPCs" },
	{ "TargetPath",   false, MapFilter::TargetPath,		MQColor(),              MapFilter::Target,  MapFilterOption::NoColor | MapFilterOption::Toggle,
	                  "Draws EQ Path to selected target" },
	{ "Marker",       false, MapFilter::Marker,			MQColor(),              MapFilter::All,     MapFilterOption::NoColor | MapFilterOption::Regenerate,
	                  "Displays marker (mobtype triangle/square/diamond size)" },
	{ "CampRadius",   false, MapFilter::CampRadius,		MQColor(128, 128, 128), MapFilter::All,     MapFilterOption::UsesRadius,
	                  "Sets radius of Camp circle to # (omit or set to 0 to disable)" },
	{ "PullRadius",   false, MapFilter::PullRadius,		MQColor(128, 128, 128), MapFilter::All,     MapFilterOption::UsesRadius,
	                  "Sets radius of casting circle to # (omit or set to 0 to disable)" },

	MapFilterInvalidOption,
};

class MapViewMapOverride : public WindowOverride<MapViewMapOverride, MapViewMap>
{
public:
	static void OnHooked(MapViewMapOverride* pWnd) { pWnd->OnHooked(); }
	static void OnAboutToUnhook(MapViewMapOverride* pWnd) { pWnd->OnAboutToUnhook(); }

	virtual int PostDraw() override
	{
		MapUpdate();
		MapAttach();
		int result = Super::PostDraw();
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

		return Super::HandleLButtonDown(pos, flags);
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
			return Super::HandleRButtonDown(pos, flags);
		}

		return 0;
	}

	//----------------------------------------------------------------------------
private:

	void OnHooked()
	{
	}

	void OnAboutToUnhook()
	{
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

		option.Enabled = GetPrivateProfileBool("Map Filters", option.szName, option.Default, INIFileName);

		if (option.IsRadius())
			option.Radius = GetPrivateProfileFloat("Map Filters", option.szName, option.Default, INIFileName);

		// If it's the CampRadius or PullRadius, set the radius value as well as the loc
		if (!_stricmp(option.szName, "CampRadius"))
		{
			if (pLocalPlayer && option.Radius > 0.0f)
			{
				CampX = pLocalPlayer->X;
				CampY = pLocalPlayer->Y;
			}
		}
		if (!_stricmp(option.szName, "PullRadius"))
		{
			if (pLocalPlayer && option.Radius > 0.0f)
			{
				PullX = pLocalPlayer->X;
				PullY = pLocalPlayer->Y;
			}
		}

		if (option.HasColor())
		{
			option.Color.SetARGB(GetPrivateProfileInt("Map Filters", fmt::format("{}-Color", option.szName), option.DefaultColor.ToARGB(), INIFileName));
			option.Color.Alpha = 255; // always enforce 255 alpha channel
		}

		option.MarkerSize = GetPrivateProfileInt("Marker Filters", fmt::format("{}-Size", option.szName), 0, INIFileName);
		std::string markerString = GetPrivateProfileString("Marker Filters", option.szName, "None", INIFileName);
		option.Marker = FindMarker(markerString, MarkerType::None);
	}

	activeLayer = GetPrivateProfileInt("Map Filters", "ActiveLayer", activeLayer, INIFileName);

	InitDefaultMapLocParams();
	ResetMapLocOverrides();

	repeatMapshow = GetPrivateProfileBool("Map Filters", "Mapshow-Repeat", false, INIFileName);
	repeatMaphide = GetPrivateProfileBool("Map Filters", "Maphide-Repeat", false, INIFileName);

	HighlightSIDELEN = GetPrivateProfileInt("Map Filters", "HighSize", HighlightSIDELEN, INIFileName);
	HighlightPulse = GetPrivateProfileBool("Map Filters", "HighPulse", HighlightPulse, INIFileName);
	HighlightColor.SetARGB(GetPrivateProfileInt("Map Filters", "High-Color", MQColor(112, 0, 112).ToARGB(), INIFileName));
	HighlightPulseIncreasing = true;
	HighlightPulseIndex = 0;
	HighlightPulseDiff = HighlightSIDELEN / 10;

	GetPrivateProfileString("Map Filters", "Mapshow", "", mapshowStr, MAX_STRING, INIFileName);
	GetPrivateProfileString("Map Filters", "Maphide", "", maphideStr, MAX_STRING, INIFileName);
	MapInit();
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

	// Hook the map window
	if (pMapViewWnd)
	{
		MapViewMapOverride::InstallHooks(&pMapViewWnd->MapView);
	}

	AddMQ2Data("MapSpawn", dataMapSpawn);
	ClearSearchSpawn(&MapFilterNamed);
	ParseSearchSpawn("#", &MapFilterNamed);

	AddSettingsPanel("plugins/Map", DrawMapSettingsPanel);
}

// Called once, when the plugin is to shutdown
PLUGIN_API void ShutdownPlugin()
{
	RemoveMQ2Data("MapSpawn");

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

PLUGIN_API void OnCleanUI()
{
	if (pMapViewWnd)
	{
		MapViewMapOverride::RemoveHooks(&pMapViewWnd->MapView);
	}
}

PLUGIN_API void OnReloadUI()
{
	if (pMapViewWnd)
	{
		MapViewMapOverride::InstallHooks(&pMapViewWnd->MapView);
	}
}
