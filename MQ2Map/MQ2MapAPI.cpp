#include "../MQ2Plugin.h"
#include "MQ2Map.h"

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

#define FAKESPAWNTYPE 0xFF


PMAPSPAWN pActiveSpawns=0;

PMAPLABEL pLabelList=0;
PMAPLABEL pLabelListTail=0;
PMAPLINE  pLineList=0;
PMAPLINE  pLineListTail=0;



map<unsigned long,PMAPSPAWN> SpawnMap;
map<unsigned long,PMAPSPAWN> GroundItemMap;
BOOL Update=false;

#define CASTRADIUS_ANGLESIZE 10
PMAPLINE pCastRadius[(360/CASTRADIUS_ANGLESIZE)+1];

PMAPSPAWN pLastTarget=0;

PMAPLINE pTargetRadius[(360/CASTRADIUS_ANGLESIZE)+1];
PMAPLINE pTargetLine=0;


inline PMAPLINE InitLine()
{
	PMAPLINE pLine=new MAPLINE;
	pLine->pPrev=0;
	pLine->pNext=pLineList;
	if (pLineList)
		pLineList->pPrev=pLine;
	else
		pLineListTail=pLine;
	pLineList=pLine;
	return pLine;
}

inline void DeleteLine(PMAPLINE pLine)
{
	if (pLine->pNext)
		pLine->pNext->pPrev=pLine->pPrev;
	else
		pLineListTail=pLine->pPrev;
	if (pLine->pPrev)
		pLine->pPrev->pNext=pLine->pNext;
	else
		pLineList=pLine->pNext;
	delete pLine;
}

inline PMAPLABEL InitLabel()
{
	PMAPLABEL pLabel=new MAPLABEL;
	pLabel->pPrev=0;
	pLabel->pNext=pLabelList;
	if (pLabelList)
		pLabelList->pPrev=pLabel;
	else
		pLabelListTail=pLabel;
	pLabelList=pLabel;
	return pLabel;
}

inline void DeleteLabel(PMAPLABEL pLabel)
{
	if (pLabel->pNext)
		pLabel->pNext->pPrev=pLabel->pPrev;
	else
		pLabelListTail=pLabel->pPrev;
	if (pLabel->pPrev)
		pLabel->pPrev->pNext=pLabel->pNext;
	else
		pLabelList=pLabel->pNext;
	delete pLabel;
}

inline PMAPSPAWN InitSpawn()
{
	PMAPSPAWN pSpawn=new MAPSPAWN;
	pSpawn->pLast=0;
	pSpawn->pNext=pActiveSpawns;
	if (pActiveSpawns)
		pActiveSpawns->pLast=pSpawn;
	pActiveSpawns=pSpawn;
	return pSpawn;	
}

inline void DeleteSpawn(PMAPSPAWN pMapSpawn)
{
	if (pMapSpawn->pNext)
		pMapSpawn->pNext->pLast=pMapSpawn->pLast;
	if (pMapSpawn->pLast)
		pMapSpawn->pLast->pNext=pMapSpawn->pNext;
	else
		pActiveSpawns=pMapSpawn->pNext;
	delete pMapSpawn;
}

PCHAR GenerateSpawnName(PSPAWNINFO pSpawn, PCHAR NameString);
DWORD GetSpawnColor(eSpawnType Type, PSPAWNINFO pSpawn);
PMAPLABEL GenerateLabel(PMAPSPAWN pMapSpawn, DWORD Color);
PMAPLINE GenerateVector(PMAPSPAWN pMapSpawn);
BOOL CanDisplaySpawn(eSpawnType Type, PSPAWNINFO pSpawn);

VOID MapInit()
{
	for (unsigned long i = 0 ; i < (360/CASTRADIUS_ANGLESIZE) ; i++)
	{
		pCastRadius[i]=0;
		pTargetRadius[i]=0;
	}
}

PMAPSPAWN AddSpawn(PSPAWNINFO pNewSpawn)
{
	eSpawnType Type=GetSpawnType(pNewSpawn);
	// apply map filter
	if (!CanDisplaySpawn(Type,pNewSpawn))
		return 0;
	// add spawn to list

	PMAPSPAWN pMapSpawn = InitSpawn();
	if (pNewSpawn->Type!=FAKESPAWNTYPE)
		SpawnMap[pNewSpawn->SpawnID]=pMapSpawn;
	pMapSpawn->SpawnType=Type;
	pMapSpawn->pSpawn=pNewSpawn;
	pMapSpawn->pMapLabel = GenerateLabel(pMapSpawn,GetSpawnColor(Type,pNewSpawn));
	if (IsOptionEnabled(MAPFILTER_Vector))
		pMapSpawn->pVector= GenerateVector(pMapSpawn);
	else
		pMapSpawn->pVector=0;

	pMapSpawn->Highlight=false;

	return pMapSpawn;
}

void RemoveSpawn(PMAPSPAWN pMapSpawn)
{
	free(pMapSpawn->pMapLabel->Label);
	DeleteLabel(pMapSpawn->pMapLabel);

	if (pMapSpawn->pVector)
	{
		DeleteLine(pMapSpawn->pVector);
		pMapSpawn->pVector=0;
	}

	if (pMapSpawn->pSpawn->Type==FAKESPAWNTYPE)
		delete pMapSpawn->pSpawn;
	else
		SpawnMap[pMapSpawn->pSpawn->SpawnID]=0;

	if (pMapSpawn==pLastTarget)
		pLastTarget=0;
	DeleteSpawn(pMapSpawn);
}

bool RemoveSpawn(PSPAWNINFO pSpawn)
{
	PMAPSPAWN pMapSpawn=SpawnMap[pSpawn->SpawnID];
	if (pMapSpawn)
	{
		RemoveSpawn(pMapSpawn);
		return true;
	}
	return false;
}

void AddGroundItem(PGROUNDITEM pGroundItem)
{
	PSPAWNINFO pFakeSpawn=new SPAWNINFO;
	memset(pFakeSpawn,0,sizeof(SPAWNINFO));
	GetFriendlyNameForGroundItem(pGroundItem,pFakeSpawn->Name);
    pFakeSpawn->X = pGroundItem->X;
    pFakeSpawn->Y = pGroundItem->Y;
    pFakeSpawn->Z = pGroundItem->Z;
	pFakeSpawn->Type=FAKESPAWNTYPE;
	PMAPSPAWN pMapSpawn=AddSpawn(pFakeSpawn);
	if (pMapSpawn)
		GroundItemMap[pGroundItem->ID]=pMapSpawn;
	else
		delete pFakeSpawn;
}

void RemoveGroundItem(PGROUNDITEM pGroundItem)
{
	PMAPSPAWN pMapSpawn=GroundItemMap[pGroundItem->ID];
	if (pMapSpawn)
	{
		GroundItemMap[pGroundItem->ID]=0;
		RemoveSpawn(pMapSpawn);
	}
}


void MapGenerate()
{
	if (!IsOptionEnabled(MAPFILTER_All))
		return;
	PSPAWNINFO pSpawn=(PSPAWNINFO)pSpawnList;
	while(pSpawn)
	{
		AddSpawn(pSpawn);
		pSpawn=pSpawn->pNext;
	}	
	if (!IsOptionEnabled(MAPFILTER_Ground))
		return;
	PGROUNDITEM pItem=(PGROUNDITEM)pItemList;
	while(pItem)
	{
		AddGroundItem(pItem);
		pItem=pItem->pNext;
	}	
}

void MapClear()
{
	GroundItemMap.clear();
	SpawnMap.clear();



	while(pActiveSpawns) 
	{
		PMAPSPAWN pNextActive=pActiveSpawns->pNext;
		
		PMAPLABEL pLabel=pActiveSpawns->pMapLabel;
		DebugTry(free(pLabel->Label));
		DeleteLabel(pLabel);

		if (pActiveSpawns->pVector)
		{
			DeleteLine(pActiveSpawns->pVector);
			pActiveSpawns->pVector=0;
		}

		if (pActiveSpawns->pSpawn->Type==FAKESPAWNTYPE) // fake!
			delete pActiveSpawns->pSpawn;

		DeleteSpawn(pActiveSpawns);
		pActiveSpawns=pNextActive;
	}

	pLastTarget=0;

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

void MapUpdate()
{
	PCHARINFO pCharInfo=GetCharInfo();
	if (!pCharInfo)
		return;
	EnterMQ2Benchmark(bmMapRefresh);
	eSpawnType Type;
	PMAPSPAWN pMapSpawn;

	if (pLastTarget && pLastTarget->pSpawn!=(PSPAWNINFO)pTarget)
	{
		if (!CanDisplaySpawn(pLastTarget->SpawnType,pLastTarget->pSpawn))
		{
			RemoveSpawn(pLastTarget);
		}
		pLastTarget=0;
	}
	
	if (pTarget && IsOptionEnabled(MAPFILTER_Target))
	{
		pLastTarget=SpawnMap[((PSPAWNINFO)pTarget)->SpawnID];
		if (!pLastTarget)
		{
			pLastTarget=AddSpawn((PSPAWNINFO)pTarget);
		}
	}

	pMapSpawn=pActiveSpawns;

	while(pMapSpawn)
	{
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
					RemoveSpawn(pMapSpawn);
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

			pCastRadius[i]->Color.ARGB=MapFilterOptions[MAPFILTER_CastRadius].Color;
			pCastRadius[i]->Start.Z=pCharInfo->pSpawn->Z;
			pCastRadius[i]->End.Z=pCharInfo->pSpawn->Z;
			pCastRadius[i]->Start.X=-pCharInfo->pSpawn->X + (FLOAT)MapFilterOptions[MAPFILTER_CastRadius].Enabled*cosf((FLOAT)Angle/180.0f*(FLOAT)PI);
			pCastRadius[i]->Start.Y=-pCharInfo->pSpawn->Y + (FLOAT)MapFilterOptions[MAPFILTER_CastRadius].Enabled*sinf((FLOAT)Angle/180.0f*(FLOAT)PI);;
			pCastRadius[i]->End.X=-pCharInfo->pSpawn->X + (FLOAT)MapFilterOptions[MAPFILTER_CastRadius].Enabled*cosf((FLOAT)(Angle+CASTRADIUS_ANGLESIZE)/180.0f*(FLOAT)PI);
			pCastRadius[i]->End.Y=-pCharInfo->pSpawn->Y + (FLOAT)MapFilterOptions[MAPFILTER_CastRadius].Enabled*sinf((FLOAT)(Angle+CASTRADIUS_ANGLESIZE)/180.0f*(FLOAT)PI);
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

	if (pLastTarget)
	{
		pLastTarget->pMapLabel->Color.ARGB=MapFilterOptions[MAPFILTER_Target].Color;
		free(pLastTarget->pMapLabel->Label);
		pLastTarget->pMapLabel->Label=GenerateSpawnName(pLastTarget->pSpawn,MapTargetNameString);			

		if (IsOptionEnabled(MAPFILTER_TargetLine))
		{
			if (!pTargetLine)
			{
				pTargetLine=InitLine();
				pTargetLine->Layer=2;
			}
			pTargetLine->Color.ARGB=MapFilterOptions[MAPFILTER_Target].Color;
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

				pTargetRadius[i]->Color.ARGB=MapFilterOptions[MAPFILTER_TargetRadius].Color;
				pTargetRadius[i]->Start.Z=((PSPAWNINFO)pTarget)->Z;
				pTargetRadius[i]->End.Z=((PSPAWNINFO)pTarget)->Z;
				pTargetRadius[i]->Start.X=-((PSPAWNINFO)pTarget)->X + (FLOAT)MapFilterOptions[MAPFILTER_TargetRadius].Enabled*cosf((FLOAT)Angle/180.0f*(FLOAT)PI);
				pTargetRadius[i]->Start.Y=-((PSPAWNINFO)pTarget)->Y + (FLOAT)MapFilterOptions[MAPFILTER_TargetRadius].Enabled*sinf((FLOAT)Angle/180.0f*(FLOAT)PI);;
				pTargetRadius[i]->End.X=-((PSPAWNINFO)pTarget)->X + (FLOAT)MapFilterOptions[MAPFILTER_TargetRadius].Enabled*cosf((FLOAT)(Angle+CASTRADIUS_ANGLESIZE)/180.0f*(FLOAT)PI);
				pTargetRadius[i]->End.Y=-((PSPAWNINFO)pTarget)->Y + (FLOAT)MapFilterOptions[MAPFILTER_TargetRadius].Enabled*sinf((FLOAT)(Angle+CASTRADIUS_ANGLESIZE)/180.0f*(FLOAT)PI);
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
	ExitMQ2Benchmark(bmMapRefresh);



}

void MapAttach()
{
	if (pLabelList)
	{
		pLabelListTail->pNext=pMap->pLabels;
		pMap->pLabels=pLabelList;
	}

	if (pLineList)
	{
		pLineListTail->pNext=pMap->pLines;
		pMap->pLines=pLineList;
	}
}

void MapDetach()
{
	if (pLabelList)
	{
		pMap->pLabels=pLabelListTail->pNext;
		pLabelListTail->pNext=0;
	}
	if (pLineList)
	{
		pMap->pLines=pLineListTail->pNext;
		pLineListTail->pNext=0;
	}
}

void MapSelectTarget()
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
				pTarget = (EQPlayer*)&EnviroTarget; 				}
			else
				pTarget=(EQPlayer*)pMapSpawn->pSpawn;
			break;
		}
		pMapSpawn=pMapSpawn->pNext;
	}
}

DWORD MapHighlight(SEARCHSPAWN *pSearch)
{
	if (!pSearch)
	{
		PMAPSPAWN pMapSpawn=pActiveSpawns;
		while(pMapSpawn)
		{
			pMapSpawn->Highlight=false;
			pMapSpawn=pMapSpawn->pNext;
		}
		return 0;
	}
	else
	{
		PCHARINFO pCharInfo=GetCharInfo();
		if (!pCharInfo)
			return 0;
		PMAPSPAWN pMapSpawn=pActiveSpawns;
		unsigned long Count=0;
		while(pMapSpawn)
		{
			// update!
			if (SpawnMatchesSearch(pSearch,pCharInfo->pSpawn,pMapSpawn->pSpawn))
			{
				//pMapSpawn->pMapLabel->Color.ARGB=HighlightColor;
				pMapSpawn->Highlight=true;
				Count++;
			}

			pMapSpawn=pMapSpawn->pNext;
		}
		return Count;
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
}



BOOL CanDisplaySpawn(eSpawnType Type, PSPAWNINFO pSpawn)
{
	if ((pSpawn==(PSPAWNINFO)pTarget) && IsOptionEnabled(MAPFILTER_Target))
	{
		return TRUE;
	}
	if (IsOptionEnabled(MAPFILTER_Custom))
	{
		if (PCHARINFO pCharInfo=GetCharInfo())
			return SpawnMatchesSearch(&MapFilterCustom,pCharInfo->pSpawn,pSpawn);
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
		return MapFilterOptions[MAPFILTER_PC].Color;
	case NPC:
		if (IsOptionEnabled(MAPFILTER_NPCConColor))
			return ConColorToARGB(ConColor(pChar->Level,pSpawn->Level,pSpawn->Type));
		return MapFilterOptions[MAPFILTER_NPC].Color;
	case CORPSE:
		return MapFilterOptions[MAPFILTER_Corpse].Color;
	case TRIGGER:
		return MapFilterOptions[MAPFILTER_Trigger].Color;
	case ITEM:
		return MapFilterOptions[MAPFILTER_Ground].Color;
	case MOUNT:
		return MapFilterOptions[MAPFILTER_Mount].Color;
	case PET:
		return MapFilterOptions[MAPFILTER_Pet].Color;
	}
	return 0;
}

PMAPLABEL GenerateLabel(PMAPSPAWN pMapSpawn, DWORD Color)
{
	PMAPLABEL pLabel=InitLabel();
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
	return pLabel;
}

PMAPLINE GenerateVector(PMAPSPAWN pMapSpawn)
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
