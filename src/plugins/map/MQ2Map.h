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
#include <map>

constexpr int MAPFILTER_All          = 0;
constexpr int MAPFILTER_PC           = 1;
constexpr int MAPFILTER_PCConColor   = 2;
constexpr int MAPFILTER_Group        = 3;
constexpr int MAPFILTER_Mount        = 4;
constexpr int MAPFILTER_NPC          = 5;
constexpr int MAPFILTER_NPCConColor  = 6;
constexpr int MAPFILTER_Untargetable = 7;
constexpr int MAPFILTER_Pet          = 8;
constexpr int MAPFILTER_Corpse       = 9;
constexpr int MAPFILTER_Chest        = 10;
constexpr int MAPFILTER_Trigger      = 11;
constexpr int MAPFILTER_Trap         = 12;
constexpr int MAPFILTER_Timer        = 13;
constexpr int MAPFILTER_Ground       = 14;
constexpr int MAPFILTER_Target       = 15;
constexpr int MAPFILTER_TargetLine   = 16;
constexpr int MAPFILTER_TargetRadius = 17;
constexpr int MAPFILTER_TargetMelee  = 18;
constexpr int MAPFILTER_Vector       = 19;
constexpr int MAPFILTER_Custom       = 20;
constexpr int MAPFILTER_CastRadius   = 21;
constexpr int MAPFILTER_NormalLabels = 22;
constexpr int MAPFILTER_ContextMenu  = 23;
constexpr int MAPFILTER_SpellRadius  = 24;
constexpr int MAPFILTER_Aura         = 25;
constexpr int MAPFILTER_Object       = 26;
constexpr int MAPFILTER_Banner       = 27;
constexpr int MAPFILTER_Campfire     = 28;
constexpr int MAPFILTER_PCCorpse     = 29;
constexpr int MAPFILTER_NPCCorpse    = 30;
constexpr int MAPFILTER_Mercenary    = 31;
constexpr int MAPFILTER_Named        = 32;
constexpr int MAPFILTER_TargetPath   = 33;
constexpr int MAPFILTER_Marker       = 34;
constexpr int MAPFILTER_CampRadius   = 35;
constexpr int MAPFILTER_PullRadius   = 36;
constexpr int MAPFILTER_Invalid      = -1;
// normal labels

struct MAPSPAWN
{
	SPAWNINFO* pSpawn = nullptr;
	eSpawnType SpawnType;

	MAPLABEL*   pMapLabel = nullptr;
	MAPLINE*    pVector = nullptr;
	bool        Highlight = false;
	bool        Explicit = false;
	int         Marker = 0;
	int         MarkerSize = 0;
	MAPLINE*    MarkerLines[10];

	MAPSPAWN*   pLast = nullptr;
	MAPSPAWN*   pNext = nullptr;
};

struct MAPLOC
{
	bool        isCreatedFromDefaultLoc;
	int         index;
	MAPSPAWN* mapSpawn;
	int         yloc;
	int         xloc;
	int         zloc;
	std::string label;
	std::string tag; // "yloc,xloc,zloc"
	int         lineSize;
	int         width;
	int         r_color;
	int         g_color;
	int         b_color;
	int         radius;
	int         rr_color; // radius colors..
	int         rg_color;
	int         rb_color;
	MAPLINE*    markerLines[150]; // lineMax = 4*maxWidth + 360 / CASTRADIUS_ANGLESIZE
};

struct MAPFILTER
{
	char*       szName;
	DWORD       Default;
	DWORD       DefaultColor;
	BOOL        bIsToggle;
	DWORD       RequiresOption;
	BOOL        RegenerateOnChange;
	char*       szHelpString;
	DWORD       Marker;
	DWORD       MarkerSize;
	DWORD       Enabled;
	DWORD       Color;
};

struct MAPSPAWN;

extern unsigned long bmMapRefresh;
extern int activeLayer;
extern float CampX;
extern float CampY;
extern float PullX;
extern float PullY;

extern std::map<std::string, MAPLOC*> LocationMap;
extern MAPLOC* DefaultMapLoc;

extern DWORD HighlightColor;
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
extern MAPFILTER MapFilterOptions[];

constexpr int MAX_CLICK_STRINGS = 16;
extern char MapSpecialClickString[MAX_CLICK_STRINGS][MAX_STRING];
extern char MapLeftClickString[MAX_CLICK_STRINGS][MAX_STRING];
extern bool repeatMapshow;
extern bool repeatMaphide;

/* COMMANDS */
void MapFilters(SPAWNINFO* pChar, char* szLine);
void MapFilterSetting(SPAWNINFO* pChar, DWORD nMapFilter, char* szValue = NULL);
void MapHighlightCmd(SPAWNINFO* pChar, char* szLine);
void PulseReset();
void MapHideCmd(SPAWNINFO* pChar, char* szLine);
void MapShowCmd(SPAWNINFO* pChar, char* szLine);
void MapNames(SPAWNINFO* pChar, char* szLine);
void MapClickCommand(SPAWNINFO* pChar, char* szLine);
void MapActiveLayerCmd(SPAWNINFO* pChar, char* szLine);
void MapSetLocationCmd(SPAWNINFO* pChar, char* szLine);
char* FormatMarker(char* szLine, char* szDest, size_t BufferSize);
DWORD TypeToMapfilter(SPAWNINFO* pChar);
void MapRemoveLocation(SPAWNINFO* pChar, char* szLine);
bool IsFloat(const std::string& in);
CVector3 GetTargetLoc();


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
void UpdateDefaultMapLoc();
void MapLocSyntaxOutput();
void MapRemoveLocation(SPAWNINFO* pChar, char* szLine);
void DeleteMapLoc(MAPLOC* maploc);
void UpdateMapLoc(MAPLOC* mapLoc);
void AddMapLocToList(MAPLOC* loc);
void UpdateMapLocIndexes();
void AddMapSpawnForMapLoc(MAPLOC* mapLoc);

bool MapSelectTarget();
void MapClickLocation(float x, float y, const std::vector<float>& z_hits);
int FindMarker(std::string_view szMark, int fallback = 99);
long  MakeTime();

bool dataMapSpawn(const char* szIndex, MQTypeVar& Ret);

MAPSPAWN* AddSpawn(SPAWNINFO* pNewSpawn, BOOL ExplicitAllow = false);
bool RemoveSpawn(SPAWNINFO* pSpawn);
void AddGroundItem(PGROUNDITEM pGroundItem);
void RemoveGroundItem(PGROUNDITEM pGroundItem);

inline bool IsOptionEnabled(DWORD Option)
{
	if (Option == MAPFILTER_Invalid)
		return true;
	return (MapFilterOptions[Option].Enabled && IsOptionEnabled(MapFilterOptions[Option].RequiresOption));
}

inline bool RequirementsMet(DWORD Option)
{
	if (Option == MAPFILTER_Invalid)
		return true;
	return (IsOptionEnabled(MapFilterOptions[Option].RequiresOption));
}

PLUGIN_API PMAPLINE InitLine();
PLUGIN_API void DeleteLine(PMAPLINE pLine);