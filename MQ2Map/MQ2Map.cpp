// MQ2Map.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup, do NOT do it in DllMain.


//#define DEBUG_TRY
#include "../MQ2Plugin.h"
#include <map>
using namespace std;

#define pMap     ((PEQMAPWINDOW)pMapViewWnd)

#define FAKESPAWNTYPE 0xFF

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
map<unsigned long,PMAPSPAWN> SpawnMap;
map<PGROUNDITEM,PMAPSPAWN> GroundItemMap;
BOOL Update=false;

#define CASTRADIUS_ANGLESIZE 10

PMAPSPAWN pLastTarget=0;
PSPAWNINFO pLastSafeTarget=0;
PMAPLINE pTargetLine=0;
PMAPLINE pTargetRadius[(360/CASTRADIUS_ANGLESIZE)+1];

PMAPLINE pCastRadius[(360/CASTRADIUS_ANGLESIZE)+1];

unsigned long bmMapPulse=0;

DWORD HighlightColor=0xFF700070;

CHAR MapNameString[MAX_STRING]={"%N"};
CHAR MapTargetNameString[MAX_STRING]={"%N"};

PreSetup("MQ2Map");
#include "MQ2Map.h"


inline BOOL IsOptionEnabled(DWORD Option)
{
	if (Option==MAPFILTER_Invalid)
		return true;
	return (gMapFilterOptions[Option].Enabled && IsOptionEnabled(gMapFilterOptions[Option].RequiresOption));
}

inline BOOL RequirementsMet(DWORD Option)
{
	if (Option==MAPFILTER_Invalid)
		return true;
	return (IsOptionEnabled(gMapFilterOptions[Option].RequiresOption));
}

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
	if (CMyMapViewWnd__OldvfTable) { 
	   delete pMapViewWnd->pvfTable;
		pMapViewWnd->pvfTable=CMyMapViewWnd__OldvfTable;
	}
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
				if (pMapSpawn->SpawnType==ITEM)
				{
					PGROUNDITEM pItem = (PGROUNDITEM)pMapSpawn->pSpawn;
					ZeroMemory(&EnviroTarget,sizeof(EnviroTarget));
					strcpy(EnviroTarget.Name,pMapSpawn->pMapLabel->Label);
					EnviroTarget.Y=pItem->Y;
					EnviroTarget.X=pItem->X;
					EnviroTarget.Z=pItem->Z;
					EnviroTarget.Type = SPAWN_NPC;
					EnviroTarget.HPCurrent = 1;
					EnviroTarget.HPMax = 1;
					EnviroTarget.pActorInfo = &EnviroActor;
					EnviroTarget.Heading=pItem->Heading;
					EnviroTarget.Race = pItem->DropID;
					EnviroTarget.GuildID=pItem->DxID;
					pTarget = (EQPlayer*)&EnviroTarget; 				}
				else
					pTarget=(EQPlayer*)pMapSpawn->pSpawn;
				break;
			}
			pMapSpawn=pMapSpawn->pNext;
		}
		return false;
	}
	if (!IsOptionEnabled(MAPFILTER_ContextMenu))
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
		if (CMyMapViewWnd__OldvfTable) { 
			delete pWnd->pvfTable;
			pWnd->pvfTable=CMyMapViewWnd__OldvfTable;
		}
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
        gMapFilterOptions[i].Enabled = GetPrivateProfileInt("Map Filters",gMapFilterOptions[i].szName,0,INIFileName);
       gMapFilterOptions[i].Color = GetPrivateProfileInt("Map Filters",szBuffer,gMapFilterOptions[i].DefaultColor,INIFileName) | 0xFF000000;
    }
	for (i = 0 ; i < (360/CASTRADIUS_ANGLESIZE) ; i++)
	{
		pCastRadius[i]=0;
		pTargetRadius[i]=0;
	}
	GetPrivateProfileString("Naming Schemes","Normal","%N",MapNameString,MAX_STRING,INIFileName);
	GetPrivateProfileString("Naming Schemes","Target","%N",MapTargetNameString,MAX_STRING,INIFileName);

	// Do not use Custom, since the string isn't stored
    gMapFilterOptions[MAPFILTER_Custom].Enabled = 0;

	Update=true;
	
	AddCommand("/mapfilter",MapFilters,0,1,1);
	AddCommand("/highlight",MapHighlight,0,1,1);
	AddCommand("/mapnames",MapNames,0,1,1);

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
	RemoveCommand("/mapnames");
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

PMAPSPAWN AddSpawn(PSPAWNINFO pNewSpawn)
{
	if (!pMapViewWnd)
		return 0;
//	DebugSpewAlways("MQ2Map::OnAddSpawn(%s)",pNewSpawn->Name);
	eSpawnType Type=GetSpawnType(pNewSpawn);
	// apply map filter
	if (!CanDisplaySpawn(Type,pNewSpawn))
		return 0;
	// add spawn to list

	PMAPSPAWN pMapSpawn = new MAPSPAWN;
	pMapSpawn->pLast=0;
	pMapSpawn->SpawnType=Type;
	pMapSpawn->pSpawn=pNewSpawn;
	pMapSpawn->pMapLabel = GenerateLabel(pMapSpawn,GetSpawnColor(Type,pNewSpawn));
	if (IsOptionEnabled(MAPFILTER_Vector))
		pMapSpawn->pVector= GenerateLine(pMapSpawn);
	else
		pMapSpawn->pVector=0;

	pMapSpawn->Highlight=false;

	pMapSpawn->pNext=pActiveSpawns;
	if (pActiveSpawns)
		pActiveSpawns->pLast=pMapSpawn;
	pActiveSpawns=pMapSpawn;
	SpawnMap[pNewSpawn->SpawnID]=pMapSpawn;
	return pMapSpawn;
}

PMAPSPAWN AddSpawnNoMap(PSPAWNINFO pNewSpawn)
{
	if (!pMapViewWnd)
		return 0;
//	DebugSpewAlways("MQ2Map::OnAddSpawn(%s)",pNewSpawn->Name);
	eSpawnType Type=GetSpawnType(pNewSpawn);
	// apply map filter
	if (!CanDisplaySpawn(Type,pNewSpawn))
		return 0;
	// add spawn to list

	PMAPSPAWN pMapSpawn = new MAPSPAWN;
	pMapSpawn->pLast=0;
	pMapSpawn->SpawnType=Type;
	pMapSpawn->pSpawn=pNewSpawn;
	pMapSpawn->pMapLabel = GenerateLabel(pMapSpawn,GetSpawnColor(Type,pNewSpawn));
	if (IsOptionEnabled(MAPFILTER_Vector))
		pMapSpawn->pVector= GenerateLine(pMapSpawn);
	else
		pMapSpawn->pVector=0;

	pMapSpawn->Highlight=false;

	pMapSpawn->pNext=pActiveSpawns;
	if (pActiveSpawns)
		pActiveSpawns->pLast=pMapSpawn;
	pActiveSpawns=pMapSpawn;
	return pMapSpawn;
}

// This is called each time a spawn is added to a zone (inserted into EQ's list of spawns),
// or for each existing spawn when a plugin first initializes
// NOTE: When you zone, these will come BEFORE OnZoned
PLUGIN_API VOID OnAddSpawn(PSPAWNINFO pNewSpawn)
{
	DebugSpewAlways("MQ2Map::OnAddSpawn(%s)",pNewSpawn->Name);
	AddSpawn(pNewSpawn);
}

BOOL RemoveSpawn(PMAPSPAWN pMapSpawn)
{
	if (!pMapSpawn)
		return false;
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
			pMapSpawn->pVector=0;
		}

		SpawnMap[pMapSpawn->pSpawn->SpawnID]=0;
		if (pMapSpawn->pSpawn->Type==FAKESPAWNTYPE)
			delete pMapSpawn->pSpawn;
		delete pMapSpawn;
	return true;
}

BOOL RemoveSpawnNoMap(PMAPSPAWN pMapSpawn)
{
	if (!pMapSpawn)
		return false;
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
			pMapSpawn->pVector=0;
		}

		if (pMapSpawn->pSpawn->Type==FAKESPAWNTYPE)
			delete pMapSpawn->pSpawn;
		delete pMapSpawn;
	return true;
}

// This is called each time a spawn is removed from a zone (removed from EQ's list of spawns).
// It is NOT called for each existing spawn when a plugin shuts down.
PLUGIN_API VOID OnRemoveSpawn(PSPAWNINFO pSpawn)
{
	if (!pMapViewWnd)
		return;
	DebugSpewAlways("MQ2Map::OnRemoveSpawn(%s)",pSpawn->Name);
	if (!RemoveSpawn(SpawnMap[pSpawn->SpawnID]))
	{
//		DebugSpew("MQ2Map::OnRemoveSpawn - Spawn not found in list");
	}
}

// This is called each time a spawn is added to a zone (inserted into EQ's list of spawns),
// or for each existing spawn when a plugin first initializes
// NOTE: When you zone, these will come BEFORE OnZoned
PLUGIN_API VOID OnAddGroundItem(PGROUNDITEM pNewGroundItem)
{
	DebugSpewAlways("MQ2Map::OnAddGroundItem(%d)",pNewGroundItem->DropID);
	PSPAWNINFO pFakeSpawn=new SPAWNINFO;
	memset(pFakeSpawn,0,sizeof(SPAWNINFO));
	GetFriendlyNameForGroundItem(pNewGroundItem,pFakeSpawn->Name);
    pFakeSpawn->X = pNewGroundItem->X;
    pFakeSpawn->Y = pNewGroundItem->Y;
    pFakeSpawn->Z = pNewGroundItem->Z;
	pFakeSpawn->Type=FAKESPAWNTYPE;
	PMAPSPAWN pMapSpawn=AddSpawn(pFakeSpawn);
	if (pMapSpawn)
		GroundItemMap[pNewGroundItem]=pMapSpawn;
	else
		delete pFakeSpawn;
}

// This is called each time a ground item is removed from a zone
// It is NOT called for each existing ground item when a plugin shuts down.
PLUGIN_API VOID OnRemoveGroundItem(PGROUNDITEM pGroundItem)
{
	DebugSpewAlways("MQ2Map::OnRemoveGroundItem(%d)",pGroundItem->DropID);
	PMAPSPAWN pMapSpawn=GroundItemMap[pGroundItem];
	if (pMapSpawn)
	{
		GroundItemMap[pGroundItem]=0;
		RemoveSpawn(pMapSpawn);
	}
}


VOID ClearMap()
{
	GroundItemMap.clear();
	SpawnMap.clear();
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
		DebugTry(free(pLabel->Label));
		DebugTry(delete pLabel);

		if (pActiveSpawns->pVector)
		{
			DeleteLine(pActiveSpawns->pVector);
			pActiveSpawns->pVector=0;
		}

		if (pActiveSpawns->pSpawn->Type==FAKESPAWNTYPE) // fake!
			delete pActiveSpawns->pSpawn;

		delete pActiveSpawns;
		pActiveSpawns=pNextActive;
	}
	pLastTarget=0;
	pLastSafeTarget=0;
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
	if (pTargetRadius[0])
	{
		for (unsigned long i = 0 ; i < (360/CASTRADIUS_ANGLESIZE) ; i++)
		{
			DeleteLine(pTargetRadius[i]);
			pTargetRadius[i]=0;
		}
	}

}

VOID UpdateMap()
{
	PCHARINFO pCharInfo=GetCharInfo();
	if (!pCharInfo)
		return;

	eSpawnType Type;
	PMAPSPAWN pMapSpawn;

	// remove "last target"
	if (pLastTarget && pLastTarget->pSpawn!=(PSPAWNINFO)pTarget)
	{
		RemoveSpawnNoMap(pLastTarget);
		pLastTarget=0;
	}

	if (pLastSafeTarget && pLastSafeTarget!=(PSPAWNINFO)pTarget)
	{
		if (pMapSpawn=SpawnMap[pLastSafeTarget->SpawnID])
		{
			free(pMapSpawn->pMapLabel->Label);
			pMapSpawn->pMapLabel->Label=GenerateSpawnName(pLastSafeTarget,MapNameString);
		}
		pLastSafeTarget=0;
	}
	
	pMapSpawn=pActiveSpawns;

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
				pMapSpawn->pMapLabel->Label=GenerateSpawnName(pMapSpawn->pSpawn,MapNameString);

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


	if (IsOptionEnabled(MAPFILTER_CastRadius))
	{
		unsigned long Angle=0;
		for (unsigned long i = 0 ; i < (360/CASTRADIUS_ANGLESIZE) ; i++,Angle+=CASTRADIUS_ANGLESIZE)
		{
			if (!pCastRadius[i])
			{
				pCastRadius[i]=InitLine();
				pCastRadius[i]->Layer=2;
			}

			pCastRadius[i]->Color.ARGB=gMapFilterOptions[MAPFILTER_CastRadius].Color;
			pCastRadius[i]->Start.Z=pCharInfo->pSpawn->Z;
			pCastRadius[i]->End.Z=pCharInfo->pSpawn->Z;
			pCastRadius[i]->Start.X=-pCharInfo->pSpawn->X + (FLOAT)gMapFilterOptions[MAPFILTER_CastRadius].Enabled*cosf((FLOAT)Angle/180.0f*(FLOAT)PI);
			pCastRadius[i]->Start.Y=-pCharInfo->pSpawn->Y + (FLOAT)gMapFilterOptions[MAPFILTER_CastRadius].Enabled*sinf((FLOAT)Angle/180.0f*(FLOAT)PI);;
			pCastRadius[i]->End.X=-pCharInfo->pSpawn->X + (FLOAT)gMapFilterOptions[MAPFILTER_CastRadius].Enabled*cosf((FLOAT)(Angle+CASTRADIUS_ANGLESIZE)/180.0f*(FLOAT)PI);
			pCastRadius[i]->End.Y=-pCharInfo->pSpawn->Y + (FLOAT)gMapFilterOptions[MAPFILTER_CastRadius].Enabled*sinf((FLOAT)(Angle+CASTRADIUS_ANGLESIZE)/180.0f*(FLOAT)PI);
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

	if (pTarget && IsOptionEnabled(MAPFILTER_Target))
	{
		if (pLastTarget)
		{
			pLastTarget->pMapLabel->Color.ARGB=gMapFilterOptions[MAPFILTER_Target].Color;
			free(pLastTarget->pMapLabel->Label);
			pLastTarget->pMapLabel->Label=GenerateSpawnName(pLastTarget->pSpawn,MapTargetNameString);			
		}
		else
		{
			PMAPSPAWN pMapSpawn=SpawnMap[((PSPAWNINFO)pTarget)->SpawnID];
			if (pMapSpawn)
			{
				pLastSafeTarget=(PSPAWNINFO)pTarget;
				pMapSpawn->pMapLabel->Color.ARGB=gMapFilterOptions[MAPFILTER_Target].Color;
				free(pMapSpawn->pMapLabel->Label);
				pMapSpawn->pMapLabel->Label=GenerateSpawnName(pMapSpawn->pSpawn,MapTargetNameString);			
			}
			else
			{
				if (pLastTarget=AddSpawnNoMap((PSPAWNINFO)pTarget))
				{
					pLastTarget->pMapLabel->Color.ARGB=gMapFilterOptions[MAPFILTER_Target].Color;	
					free(pLastTarget->pMapLabel->Label);
					pLastTarget->pMapLabel->Label=GenerateSpawnName(pLastTarget->pSpawn,MapTargetNameString);			
				}
			}
		}

		if (IsOptionEnabled(MAPFILTER_TargetLine))
		{
			if (!pTargetLine)
			{
				pTargetLine=InitLine();
				pTargetLine->Layer=2;
			}
			pTargetLine->Color.ARGB=gMapFilterOptions[MAPFILTER_Target].Color;
			pTargetLine->Start.X=-pCharInfo->pSpawn->X;
			pTargetLine->Start.Y=-pCharInfo->pSpawn->Y;
			pTargetLine->Start.Z=pCharInfo->pSpawn->Z;

			pTargetLine->End.X=-((PSPAWNINFO)pTarget)->X;
			pTargetLine->End.Y=-((PSPAWNINFO)pTarget)->Y;
			pTargetLine->End.Z=((PSPAWNINFO)pTarget)->Z;
		}
		else if (pTargetLine)
		{
			DeleteLine(pTargetLine);
			pTargetLine=0;
		}

		if (IsOptionEnabled(MAPFILTER_TargetRadius))
		{
			unsigned long Angle=0;
			for (unsigned long i = 0 ; i < (360/CASTRADIUS_ANGLESIZE) ; i++,Angle+=CASTRADIUS_ANGLESIZE)
			{
				if (!pTargetRadius[i])
				{
					pTargetRadius[i]=InitLine();
					pTargetRadius[i]->Layer=2;
				}

				pTargetRadius[i]->Color.ARGB=gMapFilterOptions[MAPFILTER_TargetRadius].Color;
				pTargetRadius[i]->Start.Z=((PSPAWNINFO)pTarget)->Z;
				pTargetRadius[i]->End.Z=((PSPAWNINFO)pTarget)->Z;
				pTargetRadius[i]->Start.X=-((PSPAWNINFO)pTarget)->X + (FLOAT)gMapFilterOptions[MAPFILTER_TargetRadius].Enabled*cosf((FLOAT)Angle/180.0f*(FLOAT)PI);
				pTargetRadius[i]->Start.Y=-((PSPAWNINFO)pTarget)->Y + (FLOAT)gMapFilterOptions[MAPFILTER_TargetRadius].Enabled*sinf((FLOAT)Angle/180.0f*(FLOAT)PI);;
				pTargetRadius[i]->End.X=-((PSPAWNINFO)pTarget)->X + (FLOAT)gMapFilterOptions[MAPFILTER_TargetRadius].Enabled*cosf((FLOAT)(Angle+CASTRADIUS_ANGLESIZE)/180.0f*(FLOAT)PI);
				pTargetRadius[i]->End.Y=-((PSPAWNINFO)pTarget)->Y + (FLOAT)gMapFilterOptions[MAPFILTER_TargetRadius].Enabled*sinf((FLOAT)(Angle+CASTRADIUS_ANGLESIZE)/180.0f*(FLOAT)PI);
			}
		}
		else if (pTargetRadius[0])
		{
			for (unsigned long i = 0 ; i < (360/CASTRADIUS_ANGLESIZE) ; i++)
			{
				DeleteLine(pTargetRadius[i]);
				pTargetRadius[i]=0;
			}
		}
	}
	else
	{
		if (pTargetRadius[0])
		{
			for (unsigned long i = 0 ; i < (360/CASTRADIUS_ANGLESIZE) ; i++)
			{
				DeleteLine(pTargetRadius[i]);
				pTargetRadius[i]=0;
			}
		}

		if (pTargetLine)
		{
			DeleteLine(pTargetLine);
			pTargetLine=0;
		}
	}

}

VOID GenerateMap()
{
	if (!IsOptionEnabled(MAPFILTER_All))
		return;
	PSPAWNINFO pSpawn=(PSPAWNINFO)pSpawnList;
	while(pSpawn)
	{
		OnAddSpawn(pSpawn);
		pSpawn=pSpawn->pNext;
	}	
	if (!IsOptionEnabled(MAPFILTER_Ground))
		return;
	PGROUNDITEM pItem=(PGROUNDITEM)pItemList;
	while(pItem)
	{
		OnAddGroundItem(pItem);
		pItem=pItem->pNext;
	}

}

BOOL CanDisplaySpawn(eSpawnType Type, PSPAWNINFO pSpawn)
{
//	if (!IsOptionEnabled(MAPFILTER_All))
//		return FALSE;
	// ^^^^ not necessary anymore, it will be caught by IsOptionEnabled
	if (IsOptionEnabled(MAPFILTER_Target))
	{
		if (pSpawn==(PSPAWNINFO)pTarget)
			return TRUE;
	}
	if (IsOptionEnabled(MAPFILTER_Custom))
	{
		if (PCHARINFO pCharInfo=GetCharInfo())
			return SpawnMatchesSearch(&gMapFilterCustom,pCharInfo->pSpawn,pSpawn);
	}
	switch(Type)
	{
	case PC:
		return IsOptionEnabled(MAPFILTER_PC);
	case NPC:
		return IsOptionEnabled(MAPFILTER_NPC);
	case CORPSE:
		return IsOptionEnabled(MAPFILTER_Corpse);
	case ITEM:
		return IsOptionEnabled(MAPFILTER_Ground);
	case TRIGGER:
		return IsOptionEnabled(MAPFILTER_Trigger);
	case PET:
		return IsOptionEnabled(MAPFILTER_Pet);
	case MOUNT:
		return IsOptionEnabled(MAPFILTER_Mount);
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
		if (IsOptionEnabled(MAPFILTER_PCConColor))
			return ConColorToARGB(ConColor(pChar->Level,pSpawn->Level,pSpawn->Type));
		return gMapFilterOptions[MAPFILTER_PC].Color;
	case NPC:
		if (IsOptionEnabled(MAPFILTER_NPCConColor))
			return ConColorToARGB(ConColor(pChar->Level,pSpawn->Level,pSpawn->Type));
		return gMapFilterOptions[MAPFILTER_NPC].Color;
	case CORPSE:
		return gMapFilterOptions[MAPFILTER_Corpse].Color;
	case TRIGGER:
		return gMapFilterOptions[MAPFILTER_Trigger].Color;
	case ITEM:
		return gMapFilterOptions[MAPFILTER_Ground].Color;
	case MOUNT:
		return gMapFilterOptions[MAPFILTER_Mount].Color;
	case PET:
		return gMapFilterOptions[MAPFILTER_Pet].Color;
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
    pLabel->Label = GenerateSpawnName(pMapSpawn->pSpawn,MapNameString);
    pLabel->Color.ARGB = Color;
    pLabel->Width = 20;
    pLabel->Height= 14;
    pLabel->unk_0x2c = 0;
	pLabel->unk_0x30 = 0;


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
VOID MapFilterSetting(PSPAWNINFO pChar, DWORD nMapFilter, PCHAR szValue)
{
    CHAR szBuffer[MAX_STRING] = {0};
    CHAR Buff[MAX_STRING]={0};
    DWORD dwValue = 0;
    PCHAR szFilterMap[] = {
        "hide",
        "show",
        NULL
    };
    if (!pChar) return;
	PMAPFILTER pMapFilter=&gMapFilterOptions[nMapFilter];
	if (!RequirementsMet(nMapFilter))
	{
		sprintf(szBuffer,"'%s' requires '%s' option.  Please enable this option first.",pMapFilter->szName,gMapFilterOptions[pMapFilter->RequiresOption].szName);
		WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
		return;
	}
    if (!szValue) {
        if (pMapFilter->bIsToggle) {
            sprintf(szBuffer,"%s: %s",pMapFilter->szName,szFilterMap[pMapFilter->Enabled]);
        } else if (nMapFilter == MAPFILTER_Custom) {
            if (IsOptionEnabled(nMapFilter)==0) {
                sprintf(szBuffer,"%s: Off",pMapFilter->szName);
            } else {
                sprintf(szBuffer,"%s: %s",pMapFilter->szName,FormatSearchSpawn(Buff,&gMapFilterCustom));
            }
        } else {
            sprintf(szBuffer,"%s: %d",pMapFilter->szName,pMapFilter->Enabled);
        }
        if (pMapFilter->DefaultColor != -1) {
            CHAR szBuffer2[MAX_STRING] = {0};
            DWORD R,G,B;
            R= (pMapFilter->Color&0xFF0000)/0x10000;
            G= (pMapFilter->Color&0xFF00)/0x100;
            B= pMapFilter->Color&0xFF;
            sprintf(szBuffer2,"%s (Color: %d %d %d)",szBuffer,R,G,B);
            strcpy(szBuffer,szBuffer2);
        }
    } else {
        if (pMapFilter->bIsToggle) {
                        if (!stricmp(szFilterMap[0],szValue)) {
                            pMapFilter->Enabled = 0;
                        } else if (!stricmp(szFilterMap[1],szValue)) {
                            pMapFilter->Enabled = 1;
                        } else {
                pMapFilter->Enabled = 1 - pMapFilter->Enabled;
                        }
            sprintf(szBuffer,"%s is now set to: %s",pMapFilter->szName,szFilterMap[IsOptionEnabled(nMapFilter)]);
        } else if (nMapFilter == MAPFILTER_Custom) {
            ClearSearchSpawn(&gMapFilterCustom);
            if (szValue[0]==0) {
                pMapFilter->Enabled = 0;
                sprintf(szBuffer,"%s is now set to: Off",pMapFilter->szName);
            } else {
                pMapFilter->Enabled = 1;
                ParseSearchSpawn(szValue,&gMapFilterCustom);
                sprintf(szBuffer,"%s is now set to: %s",pMapFilter->szName,FormatSearchSpawn(Buff,&gMapFilterCustom));
            }
        } else {
            pMapFilter->Enabled = atoi(szValue);
            sprintf(szBuffer,"%s is now set to: %d",pMapFilter->szName,pMapFilter->Enabled);
        }
    }
    WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
    if (szValue) {
        itoa(pMapFilter->Enabled,szBuffer,10);
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
		WriteChatColor("-----------------------",USERCOLOR_DEFAULT);
        for (DWORD i=0;gMapFilterOptions[i].szName!=NULL;i++) 
			if (RequirementsMet(i))
				MapFilterSetting(pChar,i);

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
        PMAPFILTER Found = 0;
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
                            gMapFilterOptions[i].Color = gMapFilterOptions[i].DefaultColor;
                        } else {
                            R=atoi(szArg);
                            G=atoi(GetArg(szArg,szRest,3));
                            B=atoi(GetArg(szArg,szRest,4));
                            if (R>255) R=255;
                            if (G>255) G=255;
                            if (B>255) B=255;
                           gMapFilterOptions[i].Color = R*0x10000 + G*0x100 + B;
                        }
                        sprintf(szBuffer,"Option '%s' color set to: %d %d %d",gMapFilterOptions[i].szName,R,G,B);
                        WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
                        itoa(gMapFilterOptions[i].Color & 0xFFFFFF,szBuffer,10);
                        sprintf(szBuffer2,"%s-Color",gMapFilterOptions[i].szName);
                        WritePrivateProfileString("Map Filters",szBuffer2,szBuffer,INIFileName);
                        gMapFilterOptions[i].Color |= 0xFF000000;
                    }
                } else {
                    MapFilterSetting(pChar,i,szRest);
                }
                Found=&gMapFilterOptions[i];
            }
        }
        if (!Found) 
			WriteChatColor("Usage: /mapfilter [option|help]",USERCOLOR_DEFAULT);
		else if (Found->RegenerateOnChange)
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

PCHAR GenerateSpawnName(PSPAWNINFO pSpawn, PCHAR NameString)
{
	CHAR Name[MAX_STRING]={0};
	unsigned long outpos=0;
#define AddString(str) {strcpy(&Name[outpos],str);outpos+=strlen(&Name[outpos]);}
#define AddInt(yourint) {_itoa(yourint,&Name[outpos],10);outpos+=strlen(&Name[outpos]);}
#define AddFloat10th(yourfloat) {outpos+=sprintf(&Name[outpos],"%.1f",yourfloat);}
	for (unsigned long N = 0 ; NameString[N] ; N++)
	{
		if (NameString[N]=='%')
		{
			N++;
			switch(NameString[N])
			{
			case 'N':// cleaned up name
				strcpy(&Name[outpos],pSpawn->Name);
				CleanupName(&Name[outpos],FALSE);
				outpos+=strlen(&Name[outpos]);
				break;
			case 'n':// original name
				AddString(pSpawn->Name);
				break;
			case 'h':// current health %
				AddInt(pSpawn->HPCurrent);
				break;
			case 'i':
				AddInt(pSpawn->SpawnID);
				break;
			case 'x':
				AddFloat10th(pSpawn->X);
				break;
			case 'y':
				AddFloat10th(pSpawn->Y);
				break;
			case 'z':
				AddFloat10th(pSpawn->Z);
				break;
			case 'R':
				AddString(pEverQuest->GetRaceDesc(pSpawn->Race));
				break;
			case 'C':
				AddString(pEverQuest->GetClassDesc(pSpawn->Class));
				break;
			case 'l':
				AddInt(pSpawn->Level);
				break;
			case '%':
				Name[outpos++]=NameString[N];
				break;
			}
		}
		else
			Name[outpos++]=NameString[N];
	}
	Name[outpos]=0;

	PCHAR ret=(PCHAR)malloc(strlen(Name)+1);
	strcpy(ret,Name);
	return ret;
	//return CleanupName(strdup(pSpawn->Name),FALSE);
}

VOID MapNames(PSPAWNINFO pChar, PCHAR szLine)
{
	CHAR szOut[MAX_STRING]={0};
	if (!szLine[0])
	{
		sprintf(szOut,"Normal naming string: %s",MapNameString);
		WriteChatColor(szOut,USERCOLOR_DEFAULT);
		sprintf(szOut,"Target naming string: %s",MapTargetNameString);
		WriteChatColor(szOut,USERCOLOR_DEFAULT);
		return;
	}
    CHAR szArg[MAX_STRING] = {0};
    GetArg(szArg,szLine,1);
    PCHAR szRest = GetNextArg(szLine);
	if (!stricmp(szArg,"target"))
	{
		if (!stricmp(szRest,"reset"))
			strcpy(MapTargetNameString,"%N");
		else
			strcpy(MapTargetNameString,szRest);
		sprintf(szOut,"Target naming string: %s",MapTargetNameString);
		WriteChatColor(szOut,USERCOLOR_DEFAULT);
		WritePrivateProfileString("Naming Schemes","Target",MapNameString,INIFileName);
		ClearMap();
		GenerateMap();
	}
	else if (!stricmp(szArg,"normal"))
	{
		if (!stricmp(szRest,"reset"))
			strcpy(MapNameString,"%N");
		else
			strcpy(MapNameString,szRest);
		sprintf(szOut,"Normal naming string: %s",MapNameString);
		WriteChatColor(szOut,USERCOLOR_DEFAULT);
		WritePrivateProfileString("Naming Schemes","Normal",MapNameString,INIFileName);
		ClearMap();
		GenerateMap();
	}
	else
	{
		WriteChatColor("Usage: /mapnames <target|normal> [value|reset]");
	}
}