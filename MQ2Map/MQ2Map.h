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

#include <map>

#define MAPFILTER_All            0
#define MAPFILTER_PC             1
#define MAPFILTER_PCConColor     2
#define MAPFILTER_Group          3
#define MAPFILTER_Mount          4
#define MAPFILTER_NPC            5
#define MAPFILTER_NPCConColor    6
#define MAPFILTER_Untargetable   7
#define MAPFILTER_Pet            8
#define MAPFILTER_Corpse         9
#define MAPFILTER_Chest          10
#define MAPFILTER_Trigger        11
#define MAPFILTER_Trap           12
#define MAPFILTER_Timer          13
#define MAPFILTER_Ground         14
#define MAPFILTER_Target         15
#define MAPFILTER_TargetLine     16
#define MAPFILTER_TargetRadius   17
#define MAPFILTER_TargetMelee    18
#define MAPFILTER_Vector         19
#define MAPFILTER_Custom         20
#define MAPFILTER_CastRadius     21
#define MAPFILTER_NormalLabels   22
#define MAPFILTER_ContextMenu    23
#define MAPFILTER_SpellRadius    24
#define MAPFILTER_Aura           25
#define MAPFILTER_Object         26
#define MAPFILTER_Banner         27
#define MAPFILTER_Campfire       28
#define MAPFILTER_PCCorpse       29
#define MAPFILTER_NPCCorpse      30
#define MAPFILTER_Mercenary      31
#define MAPFILTER_Named          32
#define MAPFILTER_TargetPath     33
#define MAPFILTER_Marker         34
#define MAPFILTER_NUMBER         35
#define MAPFILTER_Invalid        (-1)
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

extern std::map<std::string, MAPLOC*> LocationMap;
extern MAPLOC* DefaultMapLoc;

extern DWORD HighlightColor;
extern DWORD HighlightSIDELEN;
extern BOOL HighlightPulse;
extern BOOL HighlightPulseIncreasing;
extern int HighlightPulseIndex;
extern DWORD HighlightPulseDiff;

extern char MapNameString[MAX_STRING];
extern char MapTargetNameString[MAX_STRING];
extern char mapshowStr[MAX_STRING];
extern char maphideStr[MAX_STRING];
extern SEARCHSPAWN MapFilterCustom;
extern SEARCHSPAWN MapFilterNamed;
extern MAPFILTER MapFilterOptions[];
extern char MapSpecialClickString[16][MAX_STRING];
extern char MapLeftClickString[16][MAX_STRING];
extern BOOL repeatMapshow;
extern BOOL repeatMaphide;

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
char* FormatMarker(char* szLine, char* szDest, SIZE_T BufferSize);
DWORD TypeToMapfilter(SPAWNINFO* pChar);
void MapRemoveLocation(SPAWNINFO* pChar, char* szLine);
bool IsFloat(const std::string& in);
CVector3 GetTargetLoc();


/* API */
void MapInit();
void MapClear();
void MapGenerate();
DWORD MapHighlight(SEARCHSPAWN *pSearch);
DWORD MapHide(SEARCHSPAWN &Search);
DWORD MapShow(SEARCHSPAWN &Search);
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
DWORD FindMarker(char* szMark);
long  MakeTime();

BOOL dataMapSpawn(char* szIndex, MQ2TYPEVAR &Ret);

MAPSPAWN* AddSpawn(SPAWNINFO* pNewSpawn, BOOL ExplicitAllow = false);
bool RemoveSpawn(SPAWNINFO* pSpawn);
void AddGroundItem(PGROUNDITEM pGroundItem);
void RemoveGroundItem(PGROUNDITEM pGroundItem);

inline BOOL IsOptionEnabled(DWORD Option)
{
	if (Option == MAPFILTER_Invalid)
		return true;
	return (MapFilterOptions[Option].Enabled && IsOptionEnabled(MapFilterOptions[Option].RequiresOption));
}

inline BOOL RequirementsMet(DWORD Option)
{
	if (Option == MAPFILTER_Invalid)
		return true;
	return (IsOptionEnabled(MapFilterOptions[Option].RequiresOption));
}

PLUGIN_API PMAPLINE InitLine();
PLUGIN_API void DeleteLine(PMAPLINE pLine);