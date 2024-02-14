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

#pragma once

#include <mq/Plugin.h>
#include <map>

enum class MapFilter {
	Invalid = -1,
	All = 0,
	PC = 1,
	PCConColor = 2,
	Group = 3,
	Mount = 4,
	NPC = 5,
	NPCConColor = 6,
	Untargetable = 7,
	Pet = 8,
	Corpse = 9,
	Chest = 10,
	Trigger = 11,
	Trap = 12,
	Timer = 13,
	Ground = 14,
	Target = 15,
	TargetLine = 16,
	TargetRadius = 17,
	TargetMelee = 18,
	Vector = 19,
	Custom = 20,
	CastRadius = 21,
	NormalLabels = 22,
	ContextMenu = 23,
	SpellRadius = 24,
	Aura = 25,
	Object = 26,
	Banner = 27,
	Campfire = 28,
	PCCorpse = 29,
	NPCCorpse = 30,
	Mercenary = 31,
	Named = 32,
	TargetPath = 33,
	Marker = 34,
	CampRadius = 35,
	PullRadius = 36,

	Last,
};

// normal labels

class MapObject;
using MAPSPAWN = MapObject;

enum class MarkerType
{
	None = 0,
	Triangle,
	Square,
	Diamond,
	Ring,
	Unknown,
};

struct MapFilterOption
{
	enum Flags {
		Toggle       = 0x01,       // option is an on/off
		NoColor      = 0x02,       // option has no color property
		Regenerate   = 0x04,       // map is regenerated if this option is changed
		UsesRadius   = 0x08,       // option has a radius (draws a circle)
		Object       = 0x10,       // option is an Object filter
	};

	const char*      szName = nullptr;
	bool             Default = false;
	MapFilter        ThisFilter = MapFilter::Invalid;
	MQColor          DefaultColor;
	MapFilter        RequiresOption = MapFilter::Invalid;
	uint32_t         Flags = 0;
	const char*      szHelpString = nullptr;

	MarkerType       Marker = MarkerType::None;
	int              MarkerSize = 0;
	bool             Enabled = false;
	float            Radius = 0;
	MQColor          Color;

	bool IsToggle() const { return Flags & Toggle; }
	bool IsRegenerateOnChange() const { return Flags & Regenerate; }
	bool IsRadius() const { return Flags & UsesRadius; }
	bool HasColor() const { return !(Flags & NoColor); }
	bool IsObject() const { return Flags & Object; }
};

extern uint32_t bmMapRefresh;
extern int activeLayer;
extern float CampX;
extern float CampY;
extern float PullX;
extern float PullY;

extern MQColor HighlightColor;
extern int HighlightSIDELEN;
extern bool HighlightPulse;
extern bool HighlightPulseIncreasing;
extern int HighlightPulseIndex;
extern int HighlightPulseDiff;

extern char MapNameString[MAX_STRING];
extern char MapTargetNameString[MAX_STRING];
extern char mapshowStr[MAX_STRING];
extern char maphideStr[MAX_STRING];
extern MQSpawnSearch MapFilterCustom;
extern MQSpawnSearch MapFilterNamed;

extern std::vector<MapFilterOption> MapFilterOptions;
extern MapFilterOption MapFilterInvalidOption;

constexpr int MAX_CLICK_STRINGS = 16;
extern char MapSpecialClickString[MAX_CLICK_STRINGS][MAX_STRING];
extern char MapLeftClickString[MAX_CLICK_STRINGS][MAX_STRING];
extern bool repeatMapshow;
extern bool repeatMaphide;

extern std::vector<MapFilterOption*> mapFilterObjectOptions;
extern std::vector<MapFilterOption*> mapFilterGeneralOptions;

/* COMMANDS */
void MapFilters(PlayerClient* pChar, const char* szLine);
void MapFilterSetting(PlayerClient* pChar, MapFilter nMapFilter, const char* szValue = nullptr);
void MapHighlightCmd(PlayerClient* pChar, const char* szLine);
void PulseReset();
void MapHideCmd(PlayerClient* pChar, const char* szLine);
void MapShowCmd(PlayerClient* pChar, const char* szLine);
void MapNames(PlayerClient* pChar, const char* szLine);
void MapClickCommand(PlayerClient* pChar, const char* szLine);
void MapActiveLayerCmd(PlayerClient* pChar, const char* szLine);
void MapSetLocationCmd(PlayerClient* pChar, const char* szLine);
char* FormatMarker(const char* szLine, char* szDest, size_t BufferSize);
bool IsFloat(const std::string& in);

/* API */
void MapInit();
void MapClear();
void MapGenerate();
int MapHighlight(MQSpawnSearch* pSearch);
int MapHide(MQSpawnSearch& Search);
int MapShow(MQSpawnSearch& Search);
void MapUpdate();
void MapAttach();
void MapDetach();

void MapLocSyntaxOutput();
void MapRemoveLocation(const char* szLine);

bool MapSelectTarget();
void MapClickLocation(float x, float y, const std::vector<float>& z_hits);

int MakeTime();
void DrawMapSettingsPanel();

bool dataMapSpawn(const char* szIndex, MQTypeVar& Ret);

MapObject* AddSpawn(SPAWNINFO* pNewSpawn, bool ExplicitAllow = false);
bool RemoveSpawn(SPAWNINFO* pSpawn);
MapObject* AddGroundItem(GROUNDITEM* pGroundItem);
void RemoveGroundItem(GROUNDITEM* pGroundItem);

inline MapFilterOption& GetMapFilterOption(MapFilter Option)
{
	if (Option < MapFilter::All || Option >= MapFilter::Last)
		return MapFilterInvalidOption;

	return MapFilterOptions[static_cast<size_t>(Option)];
}

inline bool IsOptionEnabled(MapFilter Option)
{
	if (Option == MapFilter::Invalid)
		return true;

	MapFilterOption& option = GetMapFilterOption(Option);
	return option.Enabled && IsOptionEnabled(option.RequiresOption);
}

inline bool RequirementsMet(MapFilter Option)
{
	if (Option == MapFilter::Invalid)
		return true;

	MapFilterOption& option = GetMapFilterOption(Option);
	return IsOptionEnabled(option.RequiresOption);
}

MarkerType FindMarker(std::string_view szMark, MarkerType fallback = MarkerType::Unknown);

PLUGIN_API MapViewLine* InitLine();
PLUGIN_API void DeleteLine(MapViewLine* pLine);