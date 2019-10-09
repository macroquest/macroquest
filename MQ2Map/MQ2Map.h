#include <map>
using namespace std;
#ifdef ISXEQ
#include "ISXEQMap.h"
#endif

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
#define MAPFILTER_CampRadius	 35
#define MAPFILTER_PullRadius	 36
//#define MAPFILTER_NUMBER         35 //This is not used in the options list, what is this for??
#define MAPFILTER_Invalid        (-1)

// normal labels

typedef struct _MAPSPAWN
{
	PSPAWNINFO pSpawn = 0;
	eSpawnType SpawnType;

	PMAPLABEL pMapLabel;
	PMAPLINE pVector;
	BOOL Highlight;
	BOOL Explicit;
	DWORD Marker;
	DWORD MarkerSize;
	PMAPLINE MarkerLines[10];

	struct _MAPSPAWN *pLast;
	struct _MAPSPAWN *pNext;
} MAPSPAWN, *PMAPSPAWN;

typedef struct _MAPLOC {
	bool isCreatedFromDefaultLoc;
	int index;
	PMAPSPAWN mapSpawn;
	int yloc;
	int xloc;
	int zloc;
	string label;
	string tag; // "yloc,xloc,zloc"
	int lineSize;
	int width;
	int r_color;
	int g_color;
	int b_color;
	int radius;
	int rr_color; // radius colors..
	int rg_color;
	int rb_color;
	PMAPLINE markerLines[150]; // lineMax = 4*maxWidth + 360/CASTRADIUS_ANGLESIZE
} MAPLOC, *PMAPLOC;

typedef struct _MAPFILTER {
	PCHAR szName;
	//DWORD Index;
	DWORD Default;
	DWORD DefaultColor;
	BOOL bIsToggle;
	DWORD RequiresOption;
	BOOL RegenerateOnChange;
	PCHAR szHelpString;
	DWORD Marker;
	DWORD MarkerSize;
	DWORD Enabled;
	DWORD Color;
} MAPFILTER, *PMAPFILTER;

extern unsigned long bmMapRefresh;

extern int activeLayer;
extern float CampX;
extern float CampY;
extern float PullX;
extern float PullY;

extern map<string, PMAPLOC> LocationMap;
extern PMAPLOC DefaultMapLoc;

extern DWORD HighlightColor;
extern DWORD HighlightSIDELEN;
extern BOOL HighlightPulse;
extern BOOL HighlightPulseIncreasing;
extern int HighlightPulseIndex;
extern DWORD HighlightPulseDiff;

extern CHAR MapNameString[MAX_STRING];
extern CHAR MapTargetNameString[MAX_STRING];
extern CHAR mapshowStr[MAX_STRING];
extern CHAR maphideStr[MAX_STRING];
extern SEARCHSPAWN MapFilterCustom;
extern SEARCHSPAWN MapFilterNamed;
extern MAPFILTER MapFilterOptions[];
extern CHAR MapSpecialClickString[16][MAX_STRING];
extern CHAR MapLeftClickString[16][MAX_STRING];
extern BOOL repeatMapshow;
extern BOOL repeatMaphide;

/* COMMANDS */
VOID MapFilters(PSPAWNINFO pChar, PCHAR szLine);
VOID MapFilterSetting(PSPAWNINFO pChar, DWORD nMapFilter, PCHAR szValue = NULL);
VOID MapHighlightCmd(PSPAWNINFO pChar, PCHAR szLine);
VOID PulseReset();
VOID MapHideCmd(PSPAWNINFO pChar, PCHAR szLine);
VOID MapShowCmd(PSPAWNINFO pChar, PCHAR szLine);
VOID MapNames(PSPAWNINFO pChar, PCHAR szLine);
VOID MapClickCommand(PSPAWNINFO pChar, PCHAR szLine);
VOID MapActiveLayerCmd(PSPAWNINFO pChar, PCHAR szLine);
VOID MapSetLocationCmd(PSPAWNINFO pChar, PCHAR szLine);
PCHAR FormatMarker(PCHAR szLine, PCHAR szDest, SIZE_T BufferSize);
DWORD TypeToMapfilter(PSPAWNINFO pChar);
VOID MapRemoveLocation(PSPAWNINFO pChar, PCHAR szLine);
bool is_float(const string &in);
std::tuple<float, float, float> getTargetLoc();


/* API */
VOID MapInit();
VOID MapClear();
VOID MapGenerate();
DWORD MapHighlight(SEARCHSPAWN *pSearch);
DWORD MapHide(SEARCHSPAWN &Search);
DWORD MapShow(SEARCHSPAWN &Search);
VOID MapUpdate();
VOID MapAttach();
VOID MapDetach();
VOID UpdateDefaultMapLoc();
VOID MapLocSyntaxOutput();
VOID MapRemoveLocation(PSPAWNINFO pChar, PCHAR szLine);
VOID DeleteMapLoc(PMAPLOC mapLoc);
VOID UpdateMapLoc(PMAPLOC mapLoc);
VOID AddMapLocToList(PMAPLOC loc);
VOID UpdateMapLocIndexes();
VOID AddMapSpawnForMapLoc(PMAPLOC mapLoc);

bool MapSelectTarget();
void MapClickLocation(float world_point[2], std::vector<float> z_hits);
DWORD FindMarker(PCHAR szMark);
long  MakeTime();

#ifndef ISXEQ
BOOL dataMapSpawn(PCHAR szIndex, MQ2TYPEVAR &Ret);
#else
bool dataMapSpawn(int argc, char *argv[], LSTYPEVAR &Ret);
#endif

struct _MAPSPAWN* AddSpawn(PSPAWNINFO pNewSpawn, BOOL ExplicitAllow = false);
bool RemoveSpawn(PSPAWNINFO pSpawn);
void AddGroundItem(PGROUNDITEM pGroundItem);
void RemoveGroundItem(PGROUNDITEM pGroundItem);

static inline BOOL IsOptionEnabled(DWORD Option)
{
	if (Option == MAPFILTER_Invalid)
		return true;
	return (MapFilterOptions[Option].Enabled && IsOptionEnabled(MapFilterOptions[Option].RequiresOption));
}

static inline BOOL RequirementsMet(DWORD Option)
{
	if (Option == MAPFILTER_Invalid)
		return true;
	return (IsOptionEnabled(MapFilterOptions[Option].RequiresOption));
}
PLUGIN_API PMAPLINE InitLine();
PLUGIN_API VOID DeleteLine(PMAPLINE pLine);