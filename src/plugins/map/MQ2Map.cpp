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

#include <mq/Plugin.h>
#include "MQ2Map.h"

#include <sstream>

PreSetup("MQ2Map");

long repeatLast = 0;
long repeatInterval = 10;
clock_t highPulseRepeatLast = clock();
long highPulseRepeatIntervalMillis = 50;
unsigned long bmMapRefresh = 0;
int activeLayer = 2;
float CampX = 0.0f;
float CampY = 0.0f;
float PullX = 0.0f;
float PullY = 0.0f;
bool wasAnon = false;
bool needAnon = false;
bool Update = true;
uint16_t currentZoneId = 0;
bool repeatMaphide = false;
bool repeatMapshow = false;
DWORD HighlightColor = 0xFF700070;
int HighlightSIDELEN = 100;
bool HighlightPulse = false;
bool HighlightPulseIncreasing = true;
int HighlightPulseIndex = 0;
int HighlightPulseDiff = HighlightSIDELEN / 10;

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
	"",                      // CTRL|SHIFT
	"/nav locxyz %x %y %z",  // LALT
	"/nav locxyz %x %y %u",  // LALT|SHIFT
	"/nav locxyz %x %y %d",  // LALT|CTRL
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

MAPFILTER MapFilterOptions[] =
{
	{ "All",          TRUE,  (DWORD)-1,         TRUE,  (DWORD)MAPFILTER_Invalid, TRUE,  "Enables/disables map functions" },
	{ "PC",           FALSE, (DWORD)0xFF00FF,   TRUE,  MAPFILTER_All,            TRUE,  "Displays PCs" },
	{ "PCConColor",   FALSE, (DWORD)-1,         TRUE,  MAPFILTER_PC,             FALSE, "Displays PCs in consider colors" },
	{ "Group",        FALSE, (DWORD)0x0080C0,   TRUE,  MAPFILTER_PC,             FALSE, "Displays group members in a specific color" },
	{ "Mount",        FALSE, (DWORD)0x707070,   TRUE,  MAPFILTER_All,            TRUE,  "Displays mounts" },
	{ "NPC",          FALSE, (DWORD)0x404040,   TRUE,  MAPFILTER_All,            TRUE,  "Displays NPCs" },
	{ "NPCConColor",  FALSE, (DWORD)-1,         TRUE,  MAPFILTER_NPC,            FALSE, "Displays NPCs in consider colors" },
	{ "Untargetable", FALSE, (DWORD)0x404040,   TRUE,  MAPFILTER_All,            TRUE,  "Displays Untargetable NPCs" },
	{ "Pet",          FALSE, (DWORD)0x707070,   TRUE,  MAPFILTER_All,            TRUE,  "Displays pets" },
	{ "Corpse",       FALSE, (DWORD)0x00C000,   TRUE,  MAPFILTER_All,            TRUE,  "Displays corpses" },
	{ "Chest",        FALSE, (DWORD)0xC08000,   TRUE,  MAPFILTER_All,            TRUE,  "Displays chests" },
	{ "Trigger",      FALSE, (DWORD)0xC08000,   TRUE,  MAPFILTER_All,            TRUE,  "Displays hidden triggers" },
	{ "Trap",         FALSE, (DWORD)0xC08000,   TRUE,  MAPFILTER_All,            TRUE,  "Displays hidden traps" },
	{ "Timer",        FALSE, (DWORD)0xC08000,   TRUE,  MAPFILTER_All,            TRUE,  "Displays hidden timers" },
	{ "Ground",       FALSE, (DWORD)0xC0C0C0,   TRUE,  MAPFILTER_All,            TRUE,  "Displays ground items" },
	{ "Target",       FALSE, (DWORD)0xC00000,   TRUE,  MAPFILTER_All,            FALSE, "Displays your target" },
	{ "TargetLine",   FALSE, (DWORD)0x808080,   TRUE,  MAPFILTER_Target,         FALSE, "Displays a line to your target" },
	{ "TargetRadius", FALSE, (DWORD)0x808080,   FALSE, MAPFILTER_Target,         FALSE, "Sets radius of a circle around your target to # (omit or set to 0 to disable)" },
	{ "TargetMelee",  FALSE, (DWORD)0xFF8080,   FALSE, MAPFILTER_Target,         FALSE, "Draws a melee-range circle around your target" },
	{ "Vector",       FALSE, (DWORD)-1,         TRUE,  MAPFILTER_All,            TRUE,  "Displays heading vectors" },
	{ "Custom",       FALSE, (DWORD)-1,         FALSE, MAPFILTER_All,            TRUE,  "Sets custom filter (omit to disable)" },
	{ "CastRadius",   FALSE, (DWORD)0x808080,   FALSE, MAPFILTER_All,            FALSE, "Sets radius of casting circle to # (omit or set to 0 to disable)" },
	{ "NormalLabels", FALSE, (DWORD)-1,         TRUE,  (DWORD)MAPFILTER_Invalid, FALSE, "Toggles non-MQ2 label display" },
	{ "Menu",         FALSE, (DWORD)-1,         TRUE,  (DWORD)MAPFILTER_Invalid, FALSE, "Allows display of right-click context menu" },
	{ "SpellRadius",  FALSE, (DWORD)0x00C000,   FALSE, MAPFILTER_All,            FALSE, "Sets radius of 2nd casting circle to # (omit or set to 0 to disable)" },
	{ "Aura",         FALSE, (DWORD)0x404040,   TRUE,  MAPFILTER_All,            TRUE,  "Displays Auras" },
	{ "Object",       FALSE, (DWORD)0x404040,   TRUE,  MAPFILTER_All,            TRUE,  "Displays inanimate objects" },
	{ "Banner",       FALSE, (DWORD)0x404040,   TRUE,  MAPFILTER_All,            TRUE,  "Displays banners" },
	{ "Campfire",     FALSE, (DWORD)0x404040,   TRUE,  MAPFILTER_All,            TRUE,  "Displays campfires" },
	{ "PCCorpse",     FALSE, (DWORD)0x00C000,   TRUE,  MAPFILTER_All,            TRUE,  "Displays PC corpses, when corpse setting is on" },
	{ "NPCCorpse",    FALSE, (DWORD)0x00C000,   TRUE,  MAPFILTER_All,            TRUE,  "Displays NPC corpses, when corpse setting is on" },
	{ "Mercenary",    FALSE, (DWORD)0x404040,   TRUE,  MAPFILTER_All,            TRUE,  "Displays mercenaries" },
	{ "Named",        FALSE, (DWORD)0x404040,   TRUE,  MAPFILTER_All,            TRUE,  "Displays named NPCs" },
	{ "TargetPath",   FALSE, (DWORD)-1,         TRUE,  MAPFILTER_Target,         FALSE, "Draws EQ Path to selected target" },
	{ "Marker",       FALSE, (DWORD)-1,         FALSE, MAPFILTER_All,            TRUE,  "Displays marker (mobtype triangle/square/diamond size)" },
	{ "CampRadius",   FALSE, (DWORD)0x808080,   FALSE, MAPFILTER_All,            FALSE, "Sets radius of Camp circle to # (omit or set to 0 to disable)" },
	{ "PullRadius",   FALSE, (DWORD)0x808080,   FALSE, MAPFILTER_All,            FALSE, "Sets radius of casting circle to # (omit or set to 0 to disable)" },

	{ nullptr,        FALSE, (DWORD)-1,         FALSE, (DWORD)MAPFILTER_Invalid, FALSE, NULL }
};

bool RButtonDown()
{
	if (pCurrentMapLabel)
	{
		return MapSelectTarget();
	}

	if (!IsOptionEnabled(MAPFILTER_ContextMenu))
	{
		return false;
	}

	return true;
}

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

		ZONEINFO* pZone = reinterpret_cast<ZONEINFO*>(pZoneInfo);

		std::vector<float> z_hits;

		float curr_z = 0.0f;
		for (float f = pZone->Ceiling; f > pZone->Floor; f -= 2.0f)
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
		} while (curr_z >= pZone->Floor - 1.f);

		MapClickLocation(points.X, points.Y, z_hits);

		return MapViewMap::HandleLButtonDown(pos, flags);
	}

	virtual int HandleRButtonDown(const CXPoint& pos, uint32_t flags) override
	{
		if (RButtonDown())
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
	CMapViewWnd* Constructor_Trampoline(CXWnd*);
	CMapViewWnd* Constructor_Detour(CXWnd* pParent)
	{
		CMapViewWnd* pThis = Constructor_Trampoline(pParent);
		// the global pMapViewWnd isn't set yet, access MapView from this pointer.
		CCustomMapViewMap* pMapViewMap = static_cast<CCustomMapViewMap*>(&pThis->MapView);
		CCustomMapViewMap::HookVFTable(pMapViewMap);
		return pThis;
	}
};
DETOUR_TRAMPOLINE_EMPTY(CMapViewWnd* CMapViewWndHook::Constructor_Trampoline(CXWnd*));

// Called once, when the plugin is to initialize
PLUGIN_API void InitializePlugin()
{
	DebugSpewAlways("Initializing MQ2Map");

	wasAnon = gAnonymize;
	bmMapRefresh = AddMQ2Benchmark("Map Refresh");

	char szBuffer[MAX_STRING] = { 0 };

	for (int i = 0; MapFilterOptions[i].szName; i++)
	{
		// If it's the CampRadius or PullRadius, let's not get the last on/off state, lets assume it's off so we don't draw a circle at 0, 0.
		if (_stricmp(MapFilterOptions[i].szName, "CampRadius") && _stricmp(MapFilterOptions[i].szName, "PullRadius"))
		{
			MapFilterOptions[i].Enabled = GetPrivateProfileInt("Map Filters", MapFilterOptions[i].szName, MapFilterOptions[i].Default, INIFileName);
		}
		else
		{
			MapFilterOptions[i].Enabled = 0;
		}

		// Lets see what color option was last saved as, if any. If none then use the default.
		MapFilterOptions[i].Color = GetPrivateProfileInt("Map Filters", fmt::format("{}-Color", MapFilterOptions[i].szName),
			MapFilterOptions[i].DefaultColor, INIFileName) | 0xFF000000;
		MapFilterOptions[i].MarkerSize = GetPrivateProfileInt("Marker Filters", fmt::format("{}-Size",
			MapFilterOptions[i].szName), 0, INIFileName);

		std::string markerString = GetPrivateProfileString("Marker Filters", MapFilterOptions[i].szName, "None", INIFileName);
		MapFilterOptions[i].Marker = FindMarker(markerString, 0);
	}

	activeLayer = GetPrivateProfileInt("Map Filters", "ActiveLayer", activeLayer, INIFileName);

	UpdateDefaultMapLoc();

	repeatMapshow = GetPrivateProfileBool("Map Filters", "Mapshow-Repeat", false, INIFileName);
	repeatMaphide = GetPrivateProfileBool("Map Filters", "Maphide-Repeat", false, INIFileName);

	HighlightSIDELEN = GetPrivateProfileInt("Map Filters", "HighSize", HighlightSIDELEN, INIFileName);
	HighlightPulse = GetPrivateProfileBool("Map Filters", "HighPulse", HighlightPulse, INIFileName);
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
	MapFilterOptions[MAPFILTER_Custom].Enabled = 0;

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
}

// Called once, when the plugin is to shutdown
PLUGIN_API void ShutdownPlugin()
{
	DebugSpewAlways("Shutting down MQ2Map");
	Update = false;
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
}

// This is called every time MQ pulses
PLUGIN_API void OnPulse()
{
	long curTime = MakeTime();
	clock_t curClockTime = clock();
	bool cleared = false;

	// Clear MapLocs on zone
	if (CHARINFO* charInfo = GetCharInfo())
	{
		if (currentZoneId != (charInfo->zoneId & 0x7FFF))
		{
			if (!LocationMap.empty())
			{
				MapRemoveLocation(nullptr, "");
			}

			currentZoneId = (charInfo->zoneId & 0x7FFF);
		}
	}

	if (gAnonymize != wasAnon)
	{
		wasAnon = gAnonymize;
		needAnon = true;
	}

	char szBuffer[MAX_STRING] = { 0 };

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
		if (repeatMapshow && strlen(mapshowStr) > 0)
		{
			if (!cleared)
			{
				MapClear();
				MapGenerate();
				cleared = true;
			}

			MQSpawnSearch ss;
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

			MQSpawnSearch ss;
			ClearSearchSpawn(&ss);
			ParseSearchSpawn(maphideStr, &ss);
			MapHide(ss);
		}

		repeatLast = curTime;
	}
}

// This is called each time a spawn is added to a zone (inserted into EQ's list of spawns),
// or for each existing spawn when a plugin first initializes
// NOTE: When you zone, these will come BEFORE OnZoned
PLUGIN_API void OnAddSpawn(SPAWNINFO* pNewSpawn)
{
	// your toon's spawn id changes and it's no longer zero to start
	// don't added it all
	if (pNewSpawn)
	{
		if (PCHARINFO pMe = GetCharInfo())
		{
			if (Update && pNewSpawn->SpawnID != 0 && pMe->pSpawn != pNewSpawn)
			{
				AddSpawn(pNewSpawn);
			}
		}
	}
}

// This is called each time a spawn is removed from a zone (removed from EQ's list of spawns).
// It is NOT called for each existing spawn when a plugin shuts down.
PLUGIN_API void OnRemoveSpawn(SPAWNINFO* pSpawn)
{
	if (Update && pSpawn)
	{
		RemoveSpawn(pSpawn);
	}
}

PLUGIN_API void SetGameState(DWORD GameState)
{
	if (GameState == 3)
	{
		MapClear();
	}
}

// This is called each time a ground item is added to a zone
// or for each existing ground item when a plugin first initializes
// NOTE: When you zone, these will come BEFORE OnZoned
PLUGIN_API void OnAddGroundItem(PGROUNDITEM pNewGroundItem)
{
	if (Update)
	{
		AddGroundItem(pNewGroundItem);
	}
}

// This is called each time a ground item is removed from a zone
// It is NOT called for each existing ground item when a plugin shuts down.
PLUGIN_API void OnRemoveGroundItem(PGROUNDITEM pGroundItem)
{
	if (Update)
	{
		RemoveGroundItem(pGroundItem);
	}
}

PLUGIN_API PMAPLINE MQ2MapAddLine()
{
	return InitLine();
}

PLUGIN_API void MQ2MapDeleteLine(PMAPLINE pLine)
{
	DeleteLine(pLine);
}
