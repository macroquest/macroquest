// MQ2Map.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup, do NOT do it in DllMain.



#include "../MQ2Plugin.h"
#include "MQ2Map.h"

PreSetup("MQ2Map");


// *************************************************************************** 
// Function:    MapViewMapHook
// Description: Our map view map Hook 
// *************************************************************************** 
class MapViewMapHook
{ 
public: 
	VOID SaveEx_Trampoline(PCHAR szZonename, DWORD Layer); 
	VOID SaveEx_Detour(PCHAR szZonename, DWORD Layer) 
	{ 
		// clear our list before writing...
		ClearMapAllocs();
		SaveEx_Trampoline(szZonename, Layer);
	}
};

DETOUR_TRAMPOLINE_EMPTY(VOID MapViewMapHook::SaveEx_Trampoline(PCHAR szZonename, DWORD Layer)); 


// Called once, when the plugin is to initialize
PLUGIN_API VOID InitializePlugin(VOID)
{
	DebugSpewAlways("Initializing MQ2Map");

	// Add commands, macro parameters, hooks, etc.

	// INI Settings
	CHAR szBuffer[MAX_STRING]={0};
    for (DWORD i=0;gMapFilterOptions[i].szName;i++) {
        sprintf(szBuffer,"%s-Color",gMapFilterOptions[i].szName);
        gMapFilters[gMapFilterOptions[i].Index] = GetPrivateProfileInt("Map Filters",gMapFilterOptions[i].szName,0,INIFileName);
        gMapFiltersColor[gMapFilterOptions[i].Index] = GetPrivateProfileInt("Map Filters",szBuffer,gMapFilterOptions[i].DefaultColor,INIFileName) | 0xFF000000;
    }
    // Do not use Custom, since the string isn't stored
    gMapFilters[MAPFILTER_UserFilter] = 0;

	// Commands
	AddCommand("/mapfilter",MapFilters,0,1);

	// Hooks
	void (MapViewMapHook::*pfDetour)(PCHAR szZonename, DWORD Layer) = MapViewMapHook::SaveEx_Detour; 
	void (MapViewMapHook::*pfTrampoline)(PCHAR szZonename, DWORD Layer) = MapViewMapHook::SaveEx_Trampoline; 
	AddDetour(MapViewMap__SaveEx,*(PBYTE*)&pfDetour,*(PBYTE*)&pfTrampoline);
}

// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
	DebugSpewAlways("Shutting down MQ2Map");

	// Remove commands, macro parameters, hooks, etc.
	RemoveCommand("/mapfilter");
	RemoveDetour(MapViewMap__SaveEx);
}

// Called once directly before shutdown of the cleanui system, and also
// every time the game calls CDisplay::CleanGameUI()
PLUGIN_API VOID OnCleanUI(VOID)
{
	DebugSpewAlways("MQ2Map::OnCleanUI()");
	ClearMapAllocs();
}

// This is called every time MQ pulses
PLUGIN_API VOID OnPulse(VOID)
{
	// DONT leave in this debugspew, even if you leave in all the others
//	DebugSpewAlways("MQ2Map::OnPulse()");
	static DWORD MapDelay=0;

    if (gMapFilters[MAPFILTER_Refresh]>0) {
        if (++MapDelay>gMapFilters[MAPFILTER_Refresh]) MapDelay=0;
    } else MapDelay=0;

    if (ppMapViewWnd && pMapViewWnd && ((PCSIDLWND)pMapViewWnd)->Open && ppSpawnList && pSpawnList && !MapDelay) {
            ClearMapAllocs();
            if (gMapFilters[MAPFILTER_All]) HandleMapLabelAdditions();
            if (gMapFilters[MAPFILTER_CastRadius] > 0) HandleMapCastRadius();
        }
}

VOID AddLabel(PSPAWNINFO pSpawn, DWORD Color)
{
    PEQMAPWINDOW pMap = (PEQMAPWINDOW)pMapViewWnd;

	
    PMAPLABEL pNewLabel = (PMAPLABEL)malloc(sizeof(MAPLABEL));

    pNewLabel->Location.X = -pSpawn->X;
    pNewLabel->Location.Y = -pSpawn->Y;
    pNewLabel->Location.Z = pSpawn->Z;
    pNewLabel->Layer = 2;
    pNewLabel->Size = 3;
    pNewLabel->Label = CleanupName(strdup(pSpawn->Name),FALSE);
    pNewLabel->Color.ARGB = Color;
    pNewLabel->Width = 20;
    pNewLabel->Height= 14;
    pNewLabel->unk_0x2c = 0xfffffff5;
    pNewLabel->unk_0x30 = 0xfffffff0;
    pNewLabel->pPrev = NULL;
    pNewLabel->pNext = pMap->pLabels;
    if (pMap->pLabels) pMap->pLabels->pPrev = pNewLabel;
    pMap->pLabels = pNewLabel;

    PLABELALLOC pNewAlloc = (PLABELALLOC)malloc(sizeof(LABELALLOC));
    pNewAlloc->pLabel = pNewLabel;
    pNewAlloc->pNext = pLabelAllocs;
    pLabelAllocs = pNewAlloc;
}

VOID AddLine(FLOAT X1, FLOAT Y1, FLOAT Z1, FLOAT X2, FLOAT Y2, FLOAT Z2, DWORD Color)
{
    PEQMAPWINDOW pMap = (PEQMAPWINDOW)pMapViewWnd;
    PMAPLINE pNewLine = (PMAPLINE)malloc(sizeof(MAPLINE));

    pNewLine->Start.X = X1;
    pNewLine->Start.Y = Y1;
    pNewLine->Start.Z = Z1;
    pNewLine->End.X = X2;
    pNewLine->End.Y = Y2;
    pNewLine->End.Z = Z2;
    pNewLine->Layer = 2;
    pNewLine->Color.ARGB = Color;
    pNewLine->pPrev = NULL;
    pNewLine->pNext = pMap->pLines;
    if (pMap->pLines) pMap->pLines->pPrev = pNewLine;
    pMap->pLines = pNewLine;

    PLINEALLOC pNewAlloc = (PLINEALLOC)malloc(sizeof(LINEALLOC));
    pNewAlloc->pLine = pNewLine;
    pNewAlloc->pNext = pLineAllocs;
    pLineAllocs = pNewAlloc;
}

VOID AddSpawnToMap(PSPAWNINFO pSpawn, DWORD Color)
{
    AddLabel(pSpawn,Color);
    if (gMapFilters[MAPFILTER_Vector]) {
        if (pSpawn->SpeedRun>0) {
            AddLine(
                -pSpawn->X,
                -pSpawn->Y,
                pSpawn->Z,
                -pSpawn->X-pSpawn->SpeedX*4,
                -pSpawn->Y-pSpawn->SpeedY*4,
                pSpawn->Z+pSpawn->SpeedZ*4,
                Color);
        } else {
            AddLine(
                -pSpawn->X,
                -pSpawn->Y,
                pSpawn->Z,
                -pSpawn->X-sinf(pSpawn->Heading/256.0f*(FLOAT)PI)*4,
                -pSpawn->Y-cosf(pSpawn->Heading/256.0f*(FLOAT)PI)*4,
                pSpawn->Z,
                Color);
        }
    }
}

VOID AddItemToMap(PGROUNDITEM pItem, DWORD Color)
{
    SPAWNINFO ItemSpawn = {0};
    PCHAR szName = GetFriendlyNameForGroundItem(pItem);
    strcpy(ItemSpawn.Name,szName);
    free(szName);
    ItemSpawn.X = pItem->X;
    ItemSpawn.Y = pItem->Y;
    ItemSpawn.Z = pItem->Z;
    ItemSpawn.Heading = pItem->Heading;
    AddSpawnToMap(&ItemSpawn,Color);
}

VOID HandleMapLabelAdditions()
{
    PSPAWNINFO pSpawn = (PSPAWNINFO)pSpawnList;
    PSPAWNINFO pChar = NULL;
    PCHARINFO pCharInfo = GetCharInfo();
    if (pCharInfo) pChar=pCharInfo->pSpawn;
    while (pSpawn) {
        if (ppTarget && (pSpawn == (PSPAWNINFO)pTarget)) {
            AddSpawnToMap(pSpawn,gMapFiltersColor[MAPFILTER_Target]);
            if (gMapFilters[MAPFILTER_Target] && pChar) {
                AddLine(-pChar->X,-pChar->Y,pChar->Z,
                        -pSpawn->X,-pSpawn->Y,pSpawn->Z,gMapFiltersColor[MAPFILTER_Target]);
            }
        } else if (strstr(pSpawn->Name,"`s mount")) {
            // Don't display mounts
        } else if (gMapFilters[MAPFILTER_SpawnRadius]>0 && gMapFilters[MAPFILTER_SpawnRadius]<(DWORD)DistanceToSpawn(pCharInfo->pSpawn,pSpawn)) {
            // Don't display out of range spawns
        } else if ((gMapFilters[MAPFILTER_UserFilter]==0) || (SpawnMatchesSearch(&gMapFilterUserFilter,pChar,pSpawn))) {
            if (pSpawn->Type == SPAWN_PLAYER && gMapFilters[MAPFILTER_PC]) {
            AddSpawnToMap(pSpawn,gMapFiltersColor[MAPFILTER_PC]);
        } else if (pSpawn->Type == SPAWN_NPC && pSpawn->BodyType>0x40 && gMapFilters[MAPFILTER_Trigger]) {
            AddSpawnToMap(pSpawn,gMapFiltersColor[MAPFILTER_Trigger]);
            } else if (pSpawn->Type == SPAWN_NPC && pSpawn->BodyType<0x41 && pSpawn->MasterID==0 && gMapFilters[MAPFILTER_NPC]) {
            AddSpawnToMap(pSpawn,(gMapFilters[MAPFILTER_ConColor] && pChar)?
                ConColorToARGB(ConColor(pChar->Level,pSpawn->Level)):
                gMapFiltersColor[MAPFILTER_NPC]);
            } else if (pSpawn->Type == SPAWN_NPC && pSpawn->BodyType<0x41 && pSpawn->MasterID!=0 && gMapFilters[MAPFILTER_Pet]) {
            AddSpawnToMap(pSpawn,gMapFiltersColor[MAPFILTER_Pet]);
        } else if (pSpawn->Type == SPAWN_CORPSE && gMapFilters[MAPFILTER_Corpse]) {
            AddSpawnToMap(pSpawn,gMapFiltersColor[MAPFILTER_Corpse]);
        }
        }
        pSpawn = pSpawn->pNext;
    }
    if (gMapFilters[MAPFILTER_Ground] && ppItemList && pItemList) {
        PGROUNDITEM pItem = (PGROUNDITEM)pItemList;
        while (pItem) {
            AddItemToMap(pItem,gMapFiltersColor[MAPFILTER_Ground]);
            pItem = pItem->pNext;
        }
    }
}

#define ANGLESIZE 10
VOID HandleMapCastRadius()
{
    PSPAWNINFO pChar = NULL;
    if (GetCharInfo()) pChar = GetCharInfo()->pSpawn;
    if (!pChar) return;
    int Angle = 0;
    for (Angle=0;Angle<361;Angle+=ANGLESIZE) {
        FLOAT X1,Y1,X2,Y2;
        X1 = -pChar->X + (FLOAT)gMapFilters[MAPFILTER_CastRadius]*cosf((FLOAT)Angle/180.0f*(FLOAT)PI);
        X2 = -pChar->X + (FLOAT)gMapFilters[MAPFILTER_CastRadius]*cosf((FLOAT)(Angle+ANGLESIZE)/180.0f*(FLOAT)PI);
        Y1 = -pChar->Y + (FLOAT)gMapFilters[MAPFILTER_CastRadius]*sinf((FLOAT)Angle/180.0f*(FLOAT)PI);
        Y2 = -pChar->Y + (FLOAT)gMapFilters[MAPFILTER_CastRadius]*sinf((FLOAT)(Angle+ANGLESIZE)/180.0f*(FLOAT)PI);
        AddLine(X1,Y1,pChar->Z,X2,Y2,pChar->Z,gMapFiltersColor[MAPFILTER_CastRadius]);
    }
}

VOID ClearMapAllocs()
{
    PEQMAPWINDOW pMap = (PEQMAPWINDOW)pMapViewWnd;
    if (!pMap)
        return;
    while (pMap->pLabels && pLabelAllocs && pMap->pLabels == pLabelAllocs->pLabel) {
        PMAPLABEL pNext = pMap->pLabels->pNext;
        PLABELALLOC pOurNext = pLabelAllocs->pNext;
        free(pMap->pLabels->Label);
        free(pMap->pLabels);
        pMap->pLabels = pNext;
        free(pLabelAllocs);
        pLabelAllocs = pOurNext;
    }
    pLabelAllocs = NULL;

    while (pMap->pLines && pLineAllocs && pMap->pLines == pLineAllocs->pLine) {
        PMAPLINE pNext = pMap->pLines->pNext;
        PLINEALLOC pOurNext = pLineAllocs->pNext;
        free(pMap->pLines);
        pMap->pLines = pNext;
        free(pLineAllocs);
        pLineAllocs = pOurNext;
    }
    pLineAllocs = NULL;

}


// ***************************************************************************
// Function:    MapFilters
// Description: Our '/mapfilter' command
//              Sets map filters
// Usage:       /mapfilter [options|help]
// ***************************************************************************
VOID MapFilterSetting(PSPAWNINFO pChar, PMAPFILTER pMapFilter, PCHAR szValue)
{
    CHAR szBuffer[MAX_STRING] = {0};
    CHAR Buff[MAX_STRING]={0};
    DWORD dwValue = 0;
    PCHAR szFilterMap[] = {
        "hide",
        "show",
        NULL
    };
    if (!pMapFilter || !pChar) return;
    if (!szValue) {
        if (pMapFilter->bIsToggle) {
            sprintf(szBuffer,"%s: %s",pMapFilter->szName,szFilterMap[gMapFilters[pMapFilter->Index]]);
        } else if (pMapFilter->Index == MAPFILTER_UserFilter) {
            if (gMapFilters[pMapFilter->Index]==0) {
                sprintf(szBuffer,"%s: Off",pMapFilter->szName);
            } else {
                sprintf(szBuffer,"%s: %s",pMapFilter->szName,FormatSearchSpawn(Buff,&gMapFilterUserFilter));
            }
        } else {
            sprintf(szBuffer,"%s: %d",pMapFilter->szName,gMapFilters[pMapFilter->Index]);
        }
        if (pMapFilter->DefaultColor != -1) {
            CHAR szBuffer2[MAX_STRING] = {0};
            DWORD R,G,B;
            R= (gMapFiltersColor[pMapFilter->Index]&0xFF0000)/0x10000;
            G= (gMapFiltersColor[pMapFilter->Index]&0xFF00)/0x100;
            B= gMapFiltersColor[pMapFilter->Index]&0xFF;
            sprintf(szBuffer2,"%s (Color: %d %d %d)",szBuffer,R,G,B);
            strcpy(szBuffer,szBuffer2);
        }
    } else {
        if (pMapFilter->bIsToggle) {
                        if (!stricmp(szFilterMap[0],szValue)) {
                            gMapFilters[pMapFilter->Index] = 0;
                        } else if (!stricmp(szFilterMap[1],szValue)) {
                            gMapFilters[pMapFilter->Index] = 1;
                        } else {
                gMapFilters[pMapFilter->Index] = 1 - gMapFilters[pMapFilter->Index];
                        }
            sprintf(szBuffer,"%s is now set to: %s",pMapFilter->szName,szFilterMap[gMapFilters[pMapFilter->Index]]);
        } else if (pMapFilter->Index == MAPFILTER_UserFilter) {
            ClearSearchSpawn(&gMapFilterUserFilter);
            if (szValue[0]==0) {
                gMapFilters[pMapFilter->Index] = 0;
                sprintf(szBuffer,"%s is now set to: Off",pMapFilter->szName);
            } else {
                gMapFilters[pMapFilter->Index] = 1;
                ParseSearchSpawn(szValue,&gMapFilterUserFilter);
                sprintf(szBuffer,"%s is now set to: %s",pMapFilter->szName,FormatSearchSpawn(Buff,&gMapFilterUserFilter));
            }
        } else {
            gMapFilters[pMapFilter->Index] = atoi(szValue);
            sprintf(szBuffer,"%s is now set to: %d",pMapFilter->szName,gMapFilters[pMapFilter->Index]);
        }
    }
    WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
    if (szValue) {
        itoa(gMapFilters[pMapFilter->Index],szBuffer,10);
        WritePrivateProfileString("Map Filters",pMapFilter->szName,szBuffer,INIFileName);
    }
}

VOID MapFilters(PSPAWNINFO pChar, PCHAR szLine)
{
    bRunNextCommand = TRUE;
    CHAR szArg[MAX_STRING] = {0};
    GetArg(szArg,szLine,1);
    PCHAR szRest = GetNextArg(szLine);
    CHAR szBuffer[MAX_STRING] = {0};

    // Display settings
    if (szArg[0]==0) {
        WriteChatColor("Map filtering settings:",USERCOLOR_DEFAULT);
        for (DWORD i=0;gMapFilterOptions[i].szName!=NULL;i++) MapFilterSetting(pChar,&gMapFilterOptions[i]);

    // Display Help
    } else if (!strnicmp(szArg,"help",6)) {
        WriteChatColor("Map filtering options:",USERCOLOR_DEFAULT);
        for (DWORD i=0;gMapFilterOptions[i].szName!=NULL;i++) {
            sprintf(szBuffer,"%s%s: %s",gMapFilterOptions[i].szName,(gMapFilterOptions[i].bIsToggle)?"":" #",gMapFilterOptions[i].szHelpString);
            WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
        }
        WriteChatColor("'option' color [r g b]: Set display color for 'option' (Omit to reset to default)",USERCOLOR_DEFAULT);

    // Set option
    } else {
        BOOL Found = FALSE;
        for (DWORD i=0;gMapFilterOptions[i].szName!=NULL;i++) {
            if (!stricmp(szArg,gMapFilterOptions[i].szName)) {
                if (!strnicmp(szRest,"color",5)) {
                    if (gMapFilterOptions[i].DefaultColor == -1) {
                        sprintf(szBuffer,"Option '%s' does not have a color.",gMapFilterOptions[i].szName);
                        WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
                    } else {
                        DWORD R,G,B;
                        CHAR szBuffer2[MAX_STRING] = {0};
                        GetArg(szArg,szRest,2);
                        if (szArg[0]==0) {
                            gMapFiltersColor[gMapFilterOptions[i].Index] = gMapFilterOptions[i].DefaultColor;
                        } else {
                            R=atoi(szArg);
                            G=atoi(GetArg(szArg,szRest,3));
                            B=atoi(GetArg(szArg,szRest,4));
                            if (R>255) R=255;
                            if (G>255) G=255;
                            if (B>255) B=255;
                            gMapFiltersColor[gMapFilterOptions[i].Index] = R*0x10000 + G*0x100 + B;
                        }
                        sprintf(szBuffer,"Option '%s' color set to: %d %d %d",gMapFilterOptions[i].szName,R,G,B);
                        WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
                        itoa(gMapFiltersColor[gMapFilterOptions[i].Index] & 0xFFFFFF,szBuffer,10);
                        sprintf(szBuffer2,"%s-Color",gMapFilterOptions[i].szName);
                        WritePrivateProfileString("Map Filters",szBuffer2,szBuffer,INIFileName);
                        gMapFiltersColor[gMapFilterOptions[i].Index] |= 0xFF000000;
                    }
                } else {
                    MapFilterSetting(pChar,&gMapFilterOptions[i],szRest);
                }
                Found=TRUE;
            }
        }
        if (!Found) WriteChatColor("Usage: /mapfilter [option|help]",USERCOLOR_DEFAULT);
    }
}
