// MQ2Map.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup, do NOT do it in DllMain.



#include "../MQ2Plugin.h"
#include <map>
using namespace std;

#define pMap     ((PEQMAPWINDOW)pMapViewWnd)


typedef struct _MAPSPAWN
{
	PSPAWNINFO pSpawn;
	eSpawnType SpawnType;
	PMAPLABEL pMapLabel;
	PMAPLINE pVector;
	BOOL Highlight;

	struct _MAPSPAWN *pLast;
	struct _MAPSPAWN *pNext;
} MAPSPAWN, *PMAPSPAWN;

//PMAPLINEX pActiveLines=0;
PMAPSPAWN pActiveSpawns=0;
map<PSPAWNINFO,PMAPSPAWN> SpawnMap;
BOOL Update=false;

#define CASTRADIUS_ANGLESIZE 10

PMAPLINE pTargetLine=0;
PMAPLINE pCastRadius[(360/CASTRADIUS_ANGLESIZE)+1];

unsigned long bmMapPulse=0;

DWORD HighlightColor=0xFF700070;

PreSetup("MQ2Map");
#include "MQ2Map.h"




inline PMAPLINE InitLine()
{
	PMAPLINE pLine=new MAPLINE;
	pLine->pPrev=0;
	pLine->pNext=pMap->pLines;
	if (pMap->pLines)
		pMap->pLines->pPrev=pLine;
	pMap->pLines=pLine;
	return pLine;
}

inline void DeleteLine(PMAPLINE pLine)
{
	if (pLine->pNext)
		pLine->pNext->pPrev=pLine->pPrev;
	if (pLine->pPrev)
		pLine->pPrev->pNext=pLine->pNext;
	else
		pMap->pLines=pLine->pNext;
	delete pLine;
}

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
		ClearMap();
		SaveEx_Trampoline(szZonename, Layer);
		GenerateMap();
	}

	VOID Clear_Detour()
	{
		ClearMap();
		Clear_Trampoline();
		GenerateMap();
	}

	VOID Clear_Trampoline();
};

PCSIDLWNDVFTABLE CMyMapViewWnd__OldvfTable=0;
DWORD CMyMapViewWnd__OldDestructor=0;
DWORD CMyMapViewWnd__OldHandleRButtonDown=0;

DWORD __declspec(naked) CMyMapViewWnd__Destructor(BOOL Deallocate)
{
   __asm {   
   push ecx;
   push eax;
   }
   delete pMapViewWnd->pvfTable;
   pMapViewWnd->pvfTable=CMyMapViewWnd__OldvfTable;
   __asm
   {
   pop eax;
   pop ecx;
      jmp [CMyMapViewWnd__OldDestructor];
   }
}

bool RButtonDown()
{
	CHAR szOut[MAX_STRING]={0};
	if (pCurrentMapLabel)
	{
		PMAPSPAWN pMapSpawn=pActiveSpawns;
		while(pMapSpawn)
		{
			if (pMapSpawn->pMapLabel==pCurrentMapLabel)
			{
				pTarget=(EQPlayer*)pMapSpawn->pSpawn;
				break;
			}
			pMapSpawn=pMapSpawn->pNext;
		}
		return false;
	}
	if (!gMapFilters[MAPFILTER_ContextMenu])
		return false;
	return true;
}

VOID __declspec(naked) CMyMapViewWnd__HandleRButtonDown(DWORD point, DWORD unknown)
{
   __asm {   
   push ecx;
   push eax;
  }
	if (RButtonDown())
	{
   __asm {
   pop eax;
   pop ecx;
   jmp [CMyMapViewWnd__OldHandleRButtonDown];
   };
	}
	else
	{
		__asm {
			pop eax;
			pop ecx;
			xor eax, eax;
			retn 8;
		}
	}
} 


class CMyMapViewWnd
{
public:
	DWORD Constructor_Trampoline(class CXWnd *);
	DWORD Constructor_Detour(class CXWnd *wnd)
	{
		CMapViewWnd *pWnd=(CMapViewWnd*)this;
		DWORD Ret=Constructor_Trampoline(wnd);
		
		PCSIDLWNDVFTABLE pvfTable = new CSIDLWNDVFTABLE; 
		*pvfTable=*pWnd->pvfTable;

		CMyMapViewWnd__OldvfTable=pWnd->pvfTable;
		pWnd->pvfTable=pvfTable;
		CMyMapViewWnd__OldHandleRButtonDown=(DWORD)pWnd->pvfTable->HandleRButtonDown;
		CMyMapViewWnd__OldDestructor=(DWORD)pWnd->pvfTable->vector_deleting_destructor;
		pWnd->pvfTable->vector_deleting_destructor=CMyMapViewWnd__Destructor;
		pWnd->pvfTable->HandleRButtonDown=CMyMapViewWnd__HandleRButtonDown; 
		
		return Ret;
	}

	void RestoreVFTable()
	{
		CMapViewWnd *pWnd=(CMapViewWnd*)this;
	   delete pWnd->pvfTable;
	   pWnd->pvfTable=CMyMapViewWnd__OldvfTable;
	}
};





DETOUR_TRAMPOLINE_EMPTY(VOID MapViewMapHook::SaveEx_Trampoline(PCHAR szZonename, DWORD Layer)); 
DETOUR_TRAMPOLINE_EMPTY(VOID MapViewMapHook::Clear_Trampoline()); 

DETOUR_TRAMPOLINE_EMPTY(DWORD CMyMapViewWnd::Constructor_Trampoline(class CXWnd *)); 


// Called once, when the plugin is to initialize
PLUGIN_API VOID InitializePlugin(VOID)
{
	DebugSpewAlways("Initializing MQ2Map");

	// Add commands, macro parameters, hooks, etc.
	// AddCommand("/mycommand",MyCommand);
	// AddParm("$myparm(x)",MyParm);
	// AddXMLFile("MQUI_MyXMLFile.xml");
	// bmMyBenchmark=AddMQ2Benchmark("My Benchmark Name");

	bmMapPulse=AddMQ2Benchmark("Map Refresh");
	unsigned long i;
	CHAR szBuffer[MAX_STRING]={0};
    for (i=0;gMapFilterOptions[i].szName;i++) {
        sprintf(szBuffer,"%s-Color",gMapFilterOptions[i].szName);
        gMapFilters[gMapFilterOptions[i].Index] = GetPrivateProfileInt("Map Filters",gMapFilterOptions[i].szName,0,INIFileName);
        gMapFiltersColor[gMapFilterOptions[i].Index] = GetPrivateProfileInt("Map Filters",szBuffer,gMapFilterOptions[i].DefaultColor,INIFileName) | 0xFF000000;
    }
	for (i = 0 ; i < (360/CASTRADIUS_ANGLESIZE) ; i++)
	{
		pCastRadius[i]=0;
	}

	// Do not use Custom, since the string isn't stored
    gMapFilters[MAPFILTER_Custom] = 0;

	Update=true;
	
	AddCommand("/mapfilter",MapFilters,0,1,1);
	AddCommand("/highlight",MapHighlight,0,1,1);

	EasyClassDetour(MapViewMap__SaveEx,MapViewMapHook,SaveEx_Detour,void,(PCHAR szZonename, DWORD Layer),SaveEx_Trampoline);
	EasyClassDetour(MapViewMap__Clear,MapViewMapHook,Clear_Detour,void,(),Clear_Trampoline);
	EasyClassDetour(CMapViewWnd__CMapViewWnd,CMyMapViewWnd,Constructor_Detour,DWORD,(CXWnd*),Constructor_Trampoline);
}

// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
	DebugSpewAlways("Shutting down MQ2Map");

	// Remove commands, macro parameters, hooks, etc.
	// RemoveMQ2Benchmark(bmMyBenchmark);
	// RemoveParm("$myparm(x)");
	// RemoveCommand("/mycommand");
	// RemoveXMLFile("MQUI_MyXMLFile.xml");
	Update=false;
	ClearMap();

	RemoveDetour(MapViewMap__SaveEx);
	RemoveDetour(MapViewMap__Clear);
	RemoveDetour(CMapViewWnd__CMapViewWnd);
	((CMyMapViewWnd*)pMapViewWnd)->RestoreVFTable();

	RemoveMQ2Benchmark(bmMapPulse);
	RemoveCommand("/mapfilter");
	RemoveCommand("/highlight");
}

// Called once directly before shutdown of the new ui system, and also
// every time the game calls CDisplay::CleanGameUI()
PLUGIN_API VOID OnCleanUI(VOID)
{
	DebugSpewAlways("MQ2Map::OnCleanUI()");
	// destroy custom windows, etc
	ClearMap();
}

// This is called every time MQ pulses
PLUGIN_API VOID OnPulse(VOID)
{
	// DONT leave in this debugspew, even if you leave in all the others
//	DebugSpewAlways("MQ2Map::OnPulse()");
	if (!pMapViewWnd)
		return;
	if (Update)
	{
		EnterMQ2Benchmark(bmMapPulse);
		
		UpdateMap();
		ExitMQ2Benchmark(bmMapPulse);
	}
}

// This is called each time a spawn is added to a zone (inserted into EQ's list of spawns),
// or for each existing spawn when a plugin first initializes
// NOTE: When you zone, these will come BEFORE OnZoned
PLUGIN_API VOID OnAddSpawn(PSPAWNINFO pNewSpawn)
{
	if (!pMapViewWnd)
		return;
	DebugSpewAlways("MQ2Map::OnAddSpawn(%s)",pNewSpawn->Name);
	eSpawnType Type=GetSpawnType(pNewSpawn);
	// apply map filter
	if (!CanDisplaySpawn(Type,pNewSpawn))
		return;
	// add spawn to list

	PMAPSPAWN pMapSpawn = new MAPSPAWN;
	pMapSpawn->pLast=0;
	pMapSpawn->SpawnType=Type;
	pMapSpawn->pSpawn=pNewSpawn;
	pMapSpawn->pMapLabel = GenerateLabel(pMapSpawn,GetSpawnColor(Type,pNewSpawn));
	if (gMapFilters[MAPFILTER_Vector])
		pMapSpawn->pVector= GenerateLine(pMapSpawn);
	else
		pMapSpawn->pVector=0;

	pMapSpawn->Highlight=false;

	pMapSpawn->pNext=pActiveSpawns;
	if (pActiveSpawns)
		pActiveSpawns->pLast=pMapSpawn;
	pActiveSpawns=pMapSpawn;
	SpawnMap[pNewSpawn]=pMapSpawn;
}

// This is called each time a spawn is removed from a zone (removed from EQ's list of spawns).
// It is NOT called for each existing spawn when a plugin shuts down.
PLUGIN_API VOID OnRemoveSpawn(PSPAWNINFO pSpawn)
{
	if (!pMapViewWnd)
		return;
	DebugSpewAlways("MQ2Map::OnRemoveSpawn(%s)",pSpawn->Name);
	if (PMAPSPAWN pMapSpawn=SpawnMap[pSpawn])
	{
		if (pMapSpawn->pNext)
			pMapSpawn->pNext->pLast=pMapSpawn->pLast;

		if (pMapSpawn->pLast)
			pMapSpawn->pLast->pNext=pMapSpawn->pNext;
		else
			pActiveSpawns=pMapSpawn->pNext;

		PMAPLABEL pLabel=pMapSpawn->pMapLabel;
		if (pLabel->pPrev)
			pLabel->pPrev->pNext=pLabel->pNext;
		else
			pMap->pLabels=pLabel->pNext;
		if (pLabel->pNext)
			pLabel->pNext->pPrev=pLabel->pPrev;
		free(pLabel->Label);
		delete pLabel;

		if (pMapSpawn->pVector)
		{
			DeleteLine(pMapSpawn->pVector);
		}

		delete pMapSpawn;
		SpawnMap[pSpawn]=0;
	}
	else
	{
		DebugSpew("MQ2Map::OnRemoveSpawn - Spawn not found in list");
	}
}

VOID ClearMap()
{
    if (!pMap)
        return;
	DebugSpew("MQ2Map::ClearMap");
	while(pActiveSpawns)
	{
		PMAPSPAWN pNextActive=pActiveSpawns->pNext;
		
		PMAPLABEL pLabel=pActiveSpawns->pMapLabel;
		if (pLabel->pPrev)
			pLabel->pPrev->pNext=pLabel->pNext;
		else
			pMap->pLabels=pLabel->pNext;
		if (pLabel->pNext)
			pLabel->pNext->pPrev=pLabel->pPrev;
		free(pLabel->Label);
		delete pLabel;
		SpawnMap[pActiveSpawns->pSpawn]=0;

		if (pActiveSpawns->pVector)
		{
			DeleteLine(pActiveSpawns->pVector);
		}

		delete pActiveSpawns;
		pActiveSpawns=pNextActive;
	}

	if (pTargetLine)
	{
		DeleteLine(pTargetLine);
		pTargetLine=0;
	}

	if (pCastRadius[0])
	{
		for (unsigned long i = 0 ; i < (360/CASTRADIUS_ANGLESIZE) ; i++)
		{
			DeleteLine(pCastRadius[i]);
			pCastRadius[i]=0;
		}
	}
}

VOID UpdateMap()
{
	PCHARINFO pCharInfo=GetCharInfo();
	if (!pCharInfo)
		return;

	eSpawnType Type;
	PMAPSPAWN pMapSpawn=pActiveSpawns;
	while(pMapSpawn)
	{
		// update!
		pMapSpawn->pMapLabel->Location.X = -pMapSpawn->pSpawn->X;
		pMapSpawn->pMapLabel->Location.Y = -pMapSpawn->pSpawn->Y;
		pMapSpawn->pMapLabel->Location.Z = pMapSpawn->pSpawn->Z;

		if (pMapSpawn->Highlight)
		{
			pMapSpawn->pMapLabel->Color.ARGB=HighlightColor;
		}
		else if (gMapFilters[MAPFILTER_Target] && pMapSpawn->pSpawn==(PSPAWNINFO)pTarget)
		{
			pMapSpawn->pMapLabel->Color.ARGB=gMapFiltersColor[MAPFILTER_Target];
		}
		else
		{
			Type=GetSpawnType(pMapSpawn->pSpawn);
			if (Type!=pMapSpawn->SpawnType)
			{
				if (!CanDisplaySpawn(Type,pMapSpawn->pSpawn))
				{
					PMAPSPAWN pNext=pMapSpawn->pNext;
					OnRemoveSpawn(pMapSpawn->pSpawn);
					pMapSpawn=pNext;
					continue;
				}

				pMapSpawn->SpawnType=Type;
				free(pMapSpawn->pMapLabel->Label);
				pMapSpawn->pMapLabel->Label=CleanupName(strdup(pMapSpawn->pSpawn->Name),FALSE);
			}
			pMapSpawn->pMapLabel->Color.ARGB=GetSpawnColor(pMapSpawn->SpawnType,pMapSpawn->pSpawn);
		}

		if (pMapSpawn->pVector)
		{
			if (pMapSpawn->pSpawn->SpeedRun>0) {
				pMapSpawn->pVector->Start.X = -pMapSpawn->pSpawn->X;
				pMapSpawn->pVector->Start.Y = -pMapSpawn->pSpawn->Y;
				pMapSpawn->pVector->Start.Z = pMapSpawn->pSpawn->Z;
				pMapSpawn->pVector->End.X = -pMapSpawn->pSpawn->X-pMapSpawn->pSpawn->SpeedX*4;
				pMapSpawn->pVector->End.Y = -pMapSpawn->pSpawn->Y-pMapSpawn->pSpawn->SpeedY*4;
				pMapSpawn->pVector->End.Z = pMapSpawn->pSpawn->Z+pMapSpawn->pSpawn->SpeedZ*4;
			} else {
			pMapSpawn->pVector->Start.X = -pMapSpawn->pSpawn->X;
			pMapSpawn->pVector->Start.Y = -pMapSpawn->pSpawn->Y;
			pMapSpawn->pVector->Start.Z = pMapSpawn->pSpawn->Z;
			pMapSpawn->pVector->End.X =-pMapSpawn->pSpawn->X-sinf(pMapSpawn->pSpawn->Heading/256.0f*(FLOAT)PI)*4;
			pMapSpawn->pVector->End.Y =-pMapSpawn->pSpawn->Y-cosf(pMapSpawn->pSpawn->Heading/256.0f*(FLOAT)PI)*4;
			pMapSpawn->pVector->End.Z =pMapSpawn->pSpawn->Z;
			}
		}

		pMapSpawn=pMapSpawn->pNext;
	}


	if (gMapFilters[MAPFILTER_CastRadius])
	{
		unsigned long Angle=0;
		for (unsigned long i = 0 ; i < (360/CASTRADIUS_ANGLESIZE) ; i++,Angle+=CASTRADIUS_ANGLESIZE)
		{
			if (!pCastRadius[i])
			{
				pCastRadius[i]=InitLine();
				pCastRadius[i]->Layer=2;
			}

			pCastRadius[i]->Color.ARGB=gMapFiltersColor[MAPFILTER_CastRadius];
			pCastRadius[i]->Start.Z=pCharInfo->pSpawn->Z;
			pCastRadius[i]->End.Z=pCharInfo->pSpawn->Z;
			pCastRadius[i]->Start.X=-pCharInfo->pSpawn->X + (FLOAT)gMapFilters[MAPFILTER_CastRadius]*cosf((FLOAT)Angle/180.0f*(FLOAT)PI);
			pCastRadius[i]->Start.Y=-pCharInfo->pSpawn->Y + (FLOAT)gMapFilters[MAPFILTER_CastRadius]*sinf((FLOAT)Angle/180.0f*(FLOAT)PI);;
			pCastRadius[i]->End.X=-pCharInfo->pSpawn->X + (FLOAT)gMapFilters[MAPFILTER_CastRadius]*cosf((FLOAT)(Angle+CASTRADIUS_ANGLESIZE)/180.0f*(FLOAT)PI);
			pCastRadius[i]->End.Y=-pCharInfo->pSpawn->Y + (FLOAT)gMapFilters[MAPFILTER_CastRadius]*sinf((FLOAT)(Angle+CASTRADIUS_ANGLESIZE)/180.0f*(FLOAT)PI);
		}
	}
	else if (pCastRadius[0])
	{
		for (unsigned long i = 0 ; i < (360/CASTRADIUS_ANGLESIZE) ; i++)
		{
			DeleteLine(pCastRadius[i]);
			pCastRadius[i]=0;
		}
	}

	if (gMapFilters[MAPFILTER_Target] && pTarget)
	{
		if (!pTargetLine)
		{
			pTargetLine=InitLine();
			pTargetLine->Layer=2;
		}
		pTargetLine->Color.ARGB=gMapFiltersColor[MAPFILTER_Target];
		pTargetLine->Start.X=-pCharInfo->pSpawn->X;
		pTargetLine->Start.Y=-pCharInfo->pSpawn->Y;
		pTargetLine->Start.Z=pCharInfo->pSpawn->Z;

		pTargetLine->End.X=-((PSPAWNINFO)pTarget)->X;
		pTargetLine->End.Y=-((PSPAWNINFO)pTarget)->Y;
		pTargetLine->End.Z=((PSPAWNINFO)pTarget)->Z;
	}
	else
	{
		if (pTargetLine)
		{
			DeleteLine(pTargetLine);
			pTargetLine=0;
		}
	}

}

VOID GenerateMap()
{
	PSPAWNINFO pSpawn=(PSPAWNINFO)pSpawnList;
	while(pSpawn)
	{
		OnAddSpawn(pSpawn);
		pSpawn=pSpawn->pNext;
	}	
}

BOOL CanDisplaySpawn(eSpawnType Type, PSPAWNINFO pSpawn)
{
	if (gMapFilters[MAPFILTER_Custom])
	{
		if (PCHARINFO pCharInfo=GetCharInfo())
			return SpawnMatchesSearch(&gMapFilterCustom,pCharInfo->pSpawn,pSpawn);
	}
	switch(Type)
	{
	case PC:
		return gMapFilters[MAPFILTER_PC];
	case NPC:
		return gMapFilters[MAPFILTER_NPC];
	case CORPSE:
		return gMapFilters[MAPFILTER_Corpse];
	case ITEM:
		return gMapFilters[MAPFILTER_Ground];
	case TRIGGER:
		return gMapFilters[MAPFILTER_Trigger];
	case PET:
		return gMapFilters[MAPFILTER_Pet];
	case MOUNT:
		return gMapFilters[MAPFILTER_Mount];
	}
	return TRUE;
}

inline DWORD GetSpawnColor(eSpawnType Type, PSPAWNINFO pSpawn)
{
	PCHARINFO pChar=GetCharInfo();
	if (!pChar)
		return 0;

	switch(Type)
	{
	case PC:
//		if (gMapFilters[MAPFILTER_ConColor])
//			return ConColorToARGB(ConColor(pChar->Level,pSpawn->Level,pSpawn->Type));
		return gMapFiltersColor[MAPFILTER_PC];
	case NPC:
		if (gMapFilters[MAPFILTER_ConColor])
			return ConColorToARGB(ConColor(pChar->Level,pSpawn->Level,pSpawn->Type));
		return gMapFiltersColor[MAPFILTER_NPC];
	case CORPSE:
		return gMapFiltersColor[MAPFILTER_Corpse];
	case TRIGGER:
		return gMapFiltersColor[MAPFILTER_Trigger];
	case ITEM:
		return gMapFiltersColor[MAPFILTER_Ground];
	case MOUNT:
		return gMapFiltersColor[MAPFILTER_Mount];
	case PET:
		return gMapFiltersColor[MAPFILTER_Pet];
	}
	return 0;
}

PMAPLABEL GenerateLabel(PMAPSPAWN pMapSpawn, DWORD Color)
{
	PMAPLABEL pLabel=new MAPLABEL;
    pLabel->Location.X = -pMapSpawn->pSpawn->X;
    pLabel->Location.Y = -pMapSpawn->pSpawn->Y;
    pLabel->Location.Z = pMapSpawn->pSpawn->Z;
    pLabel->Layer = 2;
    pLabel->Size = 3;
    pLabel->Label = CleanupName(strdup(pMapSpawn->pSpawn->Name),FALSE);
    pLabel->Color.ARGB = Color;
    pLabel->Width = 20;
    pLabel->Height= 14;
    pLabel->unk_0x2c = 0xfffffff5;
	pLabel->unk_0x30 = 0xfffffff0;


    pLabel->pPrev = NULL;
    pLabel->pNext = pMap->pLabels;
    if (pMap->pLabels) 
		pMap->pLabels->pPrev = pLabel;
    pMap->pLabels = pLabel;
	
	return pLabel;
}

PMAPLINE GenerateLine(PMAPSPAWN pMapSpawn)
{

	PMAPLINE pNewLine = InitLine();
		
        if (pMapSpawn->pSpawn->SpeedRun>0) {
			pNewLine->Start.X = -pMapSpawn->pSpawn->X;
			pNewLine->Start.Y = -pMapSpawn->pSpawn->Y;
			pNewLine->Start.Z = pMapSpawn->pSpawn->Z;
			pNewLine->End.X = -pMapSpawn->pSpawn->X-pMapSpawn->pSpawn->SpeedX*4;
			pNewLine->End.Y = -pMapSpawn->pSpawn->Y-pMapSpawn->pSpawn->SpeedY*4;
			pNewLine->End.Z = pMapSpawn->pSpawn->Z+pMapSpawn->pSpawn->SpeedZ*4;
        } else {
           pNewLine->Start.X = -pMapSpawn->pSpawn->X;
           pNewLine->Start.Y = -pMapSpawn->pSpawn->Y;
           pNewLine->Start.Z = pMapSpawn->pSpawn->Z;
           pNewLine->End.X =-pMapSpawn->pSpawn->X-sinf(pMapSpawn->pSpawn->Heading/256.0f*(FLOAT)PI)*4;
           pNewLine->End.Y =-pMapSpawn->pSpawn->Y-cosf(pMapSpawn->pSpawn->Heading/256.0f*(FLOAT)PI)*4;
           pNewLine->End.Z =pMapSpawn->pSpawn->Z;
        }



    pNewLine->Layer = 2;
    pNewLine->Color = pMapSpawn->pMapLabel->Color;

	return pNewLine;	
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
        } else if (pMapFilter->Index == MAPFILTER_Custom) {
            if (gMapFilters[pMapFilter->Index]==0) {
                sprintf(szBuffer,"%s: Off",pMapFilter->szName);
            } else {
                sprintf(szBuffer,"%s: %s",pMapFilter->szName,FormatSearchSpawn(Buff,&gMapFilterCustom));
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
        } else if (pMapFilter->Index == MAPFILTER_Custom) {
            ClearSearchSpawn(&gMapFilterCustom);
            if (szValue[0]==0) {
                gMapFilters[pMapFilter->Index] = 0;
                sprintf(szBuffer,"%s is now set to: Off",pMapFilter->szName);
            } else {
                gMapFilters[pMapFilter->Index] = 1;
                ParseSearchSpawn(szValue,&gMapFilterCustom);
                sprintf(szBuffer,"%s is now set to: %s",pMapFilter->szName,FormatSearchSpawn(Buff,&gMapFilterCustom));
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
        if (!Found) 
			WriteChatColor("Usage: /mapfilter [option|help]",USERCOLOR_DEFAULT);
		else
		{
			ClearMap();
			GenerateMap();
		}
    }
}


VOID MapHighlight(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szArg[MAX_STRING] = {0};
    CHAR szBuffer[MAX_STRING] = {0};
    bRunNextCommand = TRUE;
	if (szLine==0 || szLine[0]==0)
	{
		WriteChatColor("Usage: /highlight [spawnfilter|[color # # #]]",USERCOLOR_DEFAULT);
		return;
	};

    GetArg(szArg,szLine,1);
	if (!stricmp(szArg,"color"))
	{
		GetArg(szArg,szLine,2);
		if (szLine[0]==0)
		{
			sprintf(szBuffer,"Highlight color: %d %d %d",(HighlightColor&0x00FF0000)>>16,(HighlightColor&0x0000FF00)>>8,(HighlightColor&0x000000FF));
			WriteChatColor(szBuffer);
			return;
		}
        unsigned char R=atoi(szArg);
        unsigned char G=atoi(GetArg(szArg,szLine,3));
        unsigned char B=atoi(GetArg(szArg,szLine,4));
		HighlightColor=0xFF000000 | (R << 16) | (G << 8) | (B);
		sprintf(szBuffer,"Highlight color: %d %d %d",R,G,B);
		WriteChatColor(szBuffer);
		return;
	}
	else if (!stricmp(szArg,"reset"))
	{
		PMAPSPAWN pMapSpawn=pActiveSpawns;
		while(pMapSpawn)
		{
			pMapSpawn->Highlight=false;
			pMapSpawn=pMapSpawn->pNext;
		}
		WriteChatColor("Highlighting reset",USERCOLOR_DEFAULT);
		return;
	}

	if (PCHARINFO pCharInfo=GetCharInfo())
	{
		SEARCHSPAWN ssHighlight;
		ClearSearchSpawn(&ssHighlight);
		ParseSearchSpawn(szLine,&ssHighlight);
		
		PMAPSPAWN pMapSpawn=pActiveSpawns;
		unsigned long Count=0;
		while(pMapSpawn)
		{
			// update!
			if (SpawnMatchesSearch(&ssHighlight,pCharInfo->pSpawn,pMapSpawn->pSpawn))
			{
				//pMapSpawn->pMapLabel->Color.ARGB=HighlightColor;
				pMapSpawn->Highlight=true;
				Count++;
			}

			pMapSpawn=pMapSpawn->pNext;
		}
		sprintf(szBuffer,"%d mapped spawns highlighted",Count);
		WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
	}
}
