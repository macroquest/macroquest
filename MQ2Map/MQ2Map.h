//#define MapINIFile "mq2map.ini"

typedef struct _LABELALLOC {
    struct _LABELALLOC *pNext;
    PMAPLABEL pLabel;
} LABELALLOC, *PLABELALLOC;

typedef struct _LINEALLOC {
    struct _LINEALLOC *pNext;
    PMAPLINE pLine;
} LINEALLOC, *PLINEALLOC;

PLABELALLOC pLabelAllocs = NULL;
PLINEALLOC pLineAllocs = NULL;


#define MAPFILTER_All           0
#define MAPFILTER_PC            1
#define MAPFILTER_NPC           2
#define MAPFILTER_Pet           3
#define MAPFILTER_Corpse        4
#define MAPFILTER_Trigger       5
#define MAPFILTER_Ground        6
#define MAPFILTER_Target        7
#define MAPFILTER_Vector        8
#define MAPFILTER_UserFilter    9
#define MAPFILTER_CastRadius    10
#define MAPFILTER_SpawnRadius   11
#define MAPFILTER_ConColor      12
#define MAPFILTER_Refresh       13
#define MAPFILTER_NUMBER        14

typedef struct _MAPFILTER {
    PCHAR szName;
    DWORD Index;
    DWORD DefaultColor;
    BOOL bIsToggle;
    PCHAR szHelpString;
} MAPFILTER, *PMAPFILTER;

DWORD gMapFilters[MAPFILTER_NUMBER] = {0};
DWORD gMapFiltersColor[MAPFILTER_NUMBER] = {0};
SEARCHSPAWN gMapFilterUserFilter = {0};
MAPFILTER gMapFilterOptions[] = {
    {"All",         MAPFILTER_All,          -1,         TRUE,   "Enables/disables map functions (you still must select which items to display)"},
    {"PC",          MAPFILTER_PC,           0x0000C0,   TRUE,   "Enables/disables displaying PCs"},
    {"NPC",         MAPFILTER_NPC,          0x404040,   TRUE,   "Enables/disables displaying NPCs"},
    {"Pet",         MAPFILTER_Pet,          0x707070,   TRUE,   "Enables/disables displaying pets"},
    {"Corpse",      MAPFILTER_Corpse,       0x00C000,   TRUE,   "Enables/disables displaying corpses"},
    {"Trigger",     MAPFILTER_Trigger,      0xC08000,   TRUE,   "Enables/disables displaying hidden triggers/traps"},
    {"Ground",      MAPFILTER_Ground,       0xC0C0C0,   TRUE,   "Enables/disables displaying ground items"},
    {"Target",      MAPFILTER_Target,       0xC00000,   TRUE,   "Enables/disables displaying a line to your target"},
    {"ConColor",    MAPFILTER_ConColor,     -1,         TRUE,   "Enables/disables displaying NPCs in consider colors"},
    {"Vector",      MAPFILTER_Vector,       -1,         TRUE,   "Enables/disables displaying heading vectors of spawns"},
    {"Custom",      MAPFILTER_UserFilter,   -1,         FALSE,  "Sets custom filter (omit to disable)"},
    {"CastRadius",  MAPFILTER_CastRadius,   0x808080,   FALSE,  "Sets radius of casting circle to # (omit or set to 0 to disable)"},
    {"SpawnRadius", MAPFILTER_SpawnRadius,  -1,         FALSE,  "Sets radius of spawns to display to # (omit or set to 0 to show all)"},
    {"Refresh",     MAPFILTER_Refresh,      -1,         FALSE,  "Sets refresh delay of spawns (omit or set to 0 to disable delay)"},
    {NULL,          NULL,                   -1,         FALSE,  NULL}
};

VOID ClearMapAllocs();
VOID MapFilters(PSPAWNINFO pChar, PCHAR szLine);
VOID MapFilterSetting(PSPAWNINFO pChar, PMAPFILTER pMapFilter, PCHAR szValue=NULL);
VOID HandleMapCastRadius();
VOID HandleMapLabelAdditions();