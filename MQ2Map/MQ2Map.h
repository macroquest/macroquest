BOOL CanDisplaySpawn(eSpawnType Type, PSPAWNINFO pSpawn);
VOID UpdateMap();
VOID ClearMap();
DWORD GetSpawnColor(eSpawnType Type, PSPAWNINFO pSpawn);
PCHAR GenerateSpawnName(PSPAWNINFO pSpawn, PCHAR NameString);
PMAPLABEL GenerateLabel(PMAPSPAWN pMapSpawn, DWORD Color);
PMAPLINE GenerateLine(PMAPSPAWN pMapSpawn);
VOID GenerateMap();
VOID MapNames(PSPAWNINFO pChar, PCHAR szLine);

#define MAPFILTER_All           0
#define MAPFILTER_PC            1
#define MAPFILTER_PCConColor	2
#define MAPFILTER_Mount			3
#define MAPFILTER_NPC           4
#define MAPFILTER_NPCConColor   5
#define MAPFILTER_Pet           6
#define MAPFILTER_Corpse        7
#define MAPFILTER_Trigger       8
#define MAPFILTER_Ground        9
#define MAPFILTER_Target        10
#define MAPFILTER_TargetLine	11
#define MAPFILTER_TargetRadius	12
#define MAPFILTER_Vector        13
#define MAPFILTER_Custom	    14
#define MAPFILTER_CastRadius    15
#define MAPFILTER_ContextMenu   16
#define MAPFILTER_NUMBER        17
#define MAPFILTER_Invalid		(-1)

typedef struct _MAPFILTER {
    PCHAR szName;
//    DWORD Index;
    DWORD DefaultColor;
    BOOL bIsToggle;
	DWORD RequiresOption;
	BOOL RegenerateOnChange;
    PCHAR szHelpString;

	DWORD Enabled;
	DWORD Color;

} MAPFILTER, *PMAPFILTER;

//DWORD gMapFilters[MAPFILTER_NUMBER] = {0};
//DWORD gMapFiltersColor[MAPFILTER_NUMBER] = {0};
SEARCHSPAWN gMapFilterCustom = {0};
MAPFILTER gMapFilterOptions[] = {
    {"All",         /*MAPFILTER_All,*/          -1,         TRUE,MAPFILTER_Invalid,TRUE,   "Enables/disables map functions"},
    {"PC",          /*MAPFILTER_PC,*/           0xFF00FF,   TRUE,MAPFILTER_All,TRUE,   "Displays PCs"},
    {"PCConColor",    /*MAPFILTER_ConColor,*/     -1,         TRUE,MAPFILTER_PC,FALSE,   "Displays PCs in consider colors"},
    {"Mount",       /*MAPFILTER_Mount,*/        0x707070,   TRUE,MAPFILTER_All,TRUE,   "Displays mounts"},
    {"NPC",         /*MAPFILTER_NPC,*/          0x404040,   TRUE,MAPFILTER_All,TRUE,   "Displays NPCs"},
    {"NPCConColor",    /*MAPFILTER_ConColor,*/     -1,         TRUE,MAPFILTER_NPC,FALSE,   "Displays NPCs in consider colors"},
    {"Pet",         /*MAPFILTER_Pet,*/          0x707070,   TRUE,MAPFILTER_All,TRUE,   "Displays pets"},
    {"Corpse",      /*MAPFILTER_Corpse,*/       0x00C000,   TRUE,MAPFILTER_All,TRUE,   "Displays corpses"},
    {"Trigger",     /*MAPFILTER_Trigger,*/      0xC08000,   TRUE,MAPFILTER_All,TRUE,   "Displays hidden triggers/traps"},
    {"Ground",      /*MAPFILTER_Ground,*/       0xC0C0C0,   TRUE,MAPFILTER_All,TRUE,   "Displays ground items"},
    {"Target",      /*MAPFILTER_Target,*/       0xC00000,   TRUE,MAPFILTER_All,FALSE,   "Displays your target"},
    {"TargetLine",  /*MAPFILTER_TargetLine,*/   0x808080,   TRUE,MAPFILTER_Target,FALSE,  "Displays a line to your target"},
    {"TargetRadius",  /*MAPFILTER_TargetRadius,*/   0x808080,   FALSE,MAPFILTER_Target,FALSE,  "Sets radius of a circle around your target to # (omit or set to 0 to disable)"},
    {"Vector",      /*MAPFILTER_Vector,*/       -1,         TRUE,MAPFILTER_All,TRUE,   "Displays heading vectors"},
    {"Custom",      /*MAPFILTER_Custom,*/	    -1,         FALSE,MAPFILTER_All,TRUE,  "Sets custom filter (omit to disable)"},
    {"CastRadius",  /*MAPFILTER_CastRadius,*/   0x808080,   FALSE,MAPFILTER_All,FALSE,  "Sets radius of casting circle to # (omit or set to 0 to disable)"},
    {"Menu",        /*MAPFILTER_ContextMenu,*/  -1,         TRUE,MAPFILTER_Invalid,FALSE,   "Allows display of right-click context menu"},
    {NULL,          /*NULL,*/                   -1,         FALSE,MAPFILTER_Invalid,FALSE,  NULL}
};

VOID MapFilters(PSPAWNINFO pChar, PCHAR szLine);
VOID MapFilterSetting(PSPAWNINFO pChar, DWORD nMapFilter, PCHAR szValue=NULL);
VOID MapHighlight(PSPAWNINFO pChar, PCHAR szLine);
