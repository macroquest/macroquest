#include <map>
using namespace std;








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

extern unsigned long bmMapRefresh;

extern DWORD HighlightColor;

extern CHAR MapNameString[MAX_STRING];
extern CHAR MapTargetNameString[MAX_STRING];
extern SEARCHSPAWN MapFilterCustom;
extern MAPFILTER MapFilterOptions[];



/* COMMANDS */
VOID MapFilters(PSPAWNINFO pChar, PCHAR szLine);
VOID MapFilterSetting(PSPAWNINFO pChar, DWORD nMapFilter, PCHAR szValue=NULL);
VOID MapHighlightCmd(PSPAWNINFO pChar, PCHAR szLine);
VOID MapNames(PSPAWNINFO pChar, PCHAR szLine);

/* API */
VOID MapInit();
VOID MapClear();
VOID MapGenerate();
DWORD MapHighlight(SEARCHSPAWN *pSearch);
VOID MapUpdate();
VOID MapAttach();
VOID MapDetach();

VOID MapSelectTarget();

struct _MAPSPAWN* AddSpawn(PSPAWNINFO pNewSpawn);
bool RemoveSpawn(PSPAWNINFO pSpawn);
void AddGroundItem(PGROUNDITEM pGroundItem);
void RemoveGroundItem(PGROUNDITEM pGroundItem);

static inline BOOL IsOptionEnabled(DWORD Option)
{
	if (Option==MAPFILTER_Invalid)
		return true;
	return (MapFilterOptions[Option].Enabled && IsOptionEnabled(MapFilterOptions[Option].RequiresOption));
}

static inline BOOL RequirementsMet(DWORD Option)
{
	if (Option==MAPFILTER_Invalid)
		return true;
	return (IsOptionEnabled(MapFilterOptions[Option].RequiresOption));
}

