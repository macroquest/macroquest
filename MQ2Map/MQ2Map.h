BOOL CanDisplaySpawn(eSpawnType Type, PSPAWNINFO pSpawn);
VOID UpdateMap();
VOID ClearMap();
DWORD GetSpawnColor(eSpawnType Type, PSPAWNINFO pSpawn);
PMAPLABEL GenerateLabel(PMAPSPAWN pMapSpawn, DWORD Color);
PMAPLINE GenerateLine(PMAPSPAWN pMapSpawn);
VOID GenerateMap();


#define MAPFILTER_All           0
#define MAPFILTER_PC            1
#define MAPFILTER_Mount			2
#define MAPFILTER_NPC           3
#define MAPFILTER_Pet           4
#define MAPFILTER_Corpse        5
#define MAPFILTER_Trigger       6
#define MAPFILTER_Ground        7
#define MAPFILTER_Target        8
#define MAPFILTER_Vector        9
#define MAPFILTER_Custom	    10
#define MAPFILTER_CastRadius    11
#define MAPFILTER_ConColor      12
#define MAPFILTER_ContextMenu   13
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
SEARCHSPAWN gMapFilterCustom = {0};
MAPFILTER gMapFilterOptions[] = {
    {"All",         MAPFILTER_All,          -1,         TRUE,   "Enables/disables map functions (you still must select which items to display)"},
    {"PC",          MAPFILTER_PC,           0xFF00FF,   TRUE,   "Enables/disables displaying PCs"},
    {"Mount",       MAPFILTER_Mount,        0x707070,   TRUE,   "Enables/disables displaying mounts"},
    {"NPC",         MAPFILTER_NPC,          0x404040,   TRUE,   "Enables/disables displaying NPCs"},
    {"Pet",         MAPFILTER_Pet,          0x707070,   TRUE,   "Enables/disables displaying pets"},
    {"Corpse",      MAPFILTER_Corpse,       0x00C000,   TRUE,   "Enables/disables displaying corpses"},
    {"Trigger",     MAPFILTER_Trigger,      0xC08000,   TRUE,   "Enables/disables displaying hidden triggers/traps"},
    {"Ground",      MAPFILTER_Ground,       0xC0C0C0,   TRUE,   "Enables/disables displaying ground items"},
    {"Target",      MAPFILTER_Target,       0xC00000,   TRUE,   "Enables/disables displaying a line to your target"},
    {"Vector",      MAPFILTER_Vector,       -1,         TRUE,   "Enables/disables displaying heading vectors of spawns"},
    {"Custom",      MAPFILTER_Custom,	    -1,         FALSE,  "Sets custom filter (omit to disable)"},
    {"CastRadius",  MAPFILTER_CastRadius,   0x808080,   FALSE,  "Sets radius of casting circle to # (omit or set to 0 to disable)"},
    {"ConColor",    MAPFILTER_ConColor,     -1,         TRUE,   "Enables/disables displaying NPCs in consider colors"},
    {"Menu",        MAPFILTER_ContextMenu,  -1,         TRUE,   "Enables/disables the right-click context menu"},
    {NULL,          NULL,                   -1,         FALSE,  NULL}
};

VOID MapFilters(PSPAWNINFO pChar, PCHAR szLine);
VOID MapFilterSetting(PSPAWNINFO pChar, PMAPFILTER pMapFilter, PCHAR szValue=NULL);
VOID MapHighlight(PSPAWNINFO pChar, PCHAR szLine);
