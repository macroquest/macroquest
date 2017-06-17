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
	BOOL Explicit;
	DWORD Marker;
	DWORD MarkerSize;
	PMAPLINE MarkerLines[10];

	struct _MAPSPAWN *pLast;
	struct _MAPSPAWN *pNext;
} MAPSPAWN, *PMAPSPAWN;

#define FAKESPAWNTYPE 0xFF


PMAPSPAWN pActiveSpawns = 0;

PMAPLABEL pLabelList = 0;
PMAPLABEL pLabelListTail = 0;
PMAPLINE  pLineList = 0;
PMAPLINE  pLineListTail = 0;



map<unsigned long, PMAPSPAWN> SpawnMap;
map<unsigned long, PMAPSPAWN> GroundItemMap;
map<PMAPLABEL, PMAPSPAWN> LabelMap;
map<string, PMAPLOC> LocationMap;
PMAPLOC DefaultMapLoc = new MAPLOC;

BOOL Update = false;

#define CASTRADIUS_ANGLESIZE 10
PMAPLINE pCastRadius[(360 / CASTRADIUS_ANGLESIZE) + 1];

PMAPLINE pSpellRadius[(360 / CASTRADIUS_ANGLESIZE) + 1];

PMAPSPAWN pLastTarget = 0;

PMAPLINE pTargetRadius[(360 / CASTRADIUS_ANGLESIZE) + 1];

PMAPLINE pTargetMelee[(360 / CASTRADIUS_ANGLESIZE) + 1];

PMAPLINE pTargetLine = 0;


inline PMAPLINE InitLine()
{
	PMAPLINE pLine = new MAPLINE;
	pLine->pPrev = 0;
	pLine->pNext = pLineList;
	if (pLineList)
		pLineList->pPrev = pLine;
	else
		pLineListTail = pLine;
	pLineList = pLine;
	return pLine;
}

inline void DeleteLine(PMAPLINE pLine)
{
	if (pLine->pNext)
		pLine->pNext->pPrev = pLine->pPrev;
	else
		pLineListTail = pLine->pPrev;
	if (pLine->pPrev)
		pLine->pPrev->pNext = pLine->pNext;
	else
		pLineList = pLine->pNext;
	delete pLine;
}

inline PMAPLABEL InitLabel(PMAPSPAWN pMapSpawn)
{
	PMAPLABEL pLabel = new MAPLABEL;
	pLabel->pPrev = 0;
	pLabel->pNext = pLabelList;
	if (pLabelList)
		pLabelList->pPrev = pLabel;
	else
		pLabelListTail = pLabel;
	pLabelList = pLabel;
	LabelMap[pLabel] = pMapSpawn;
	return pLabel;
}

inline void DeleteLabel(PMAPLABEL pLabel)
{
	LabelMap[pLabel] = 0;
	if (pLabel->pNext)
		pLabel->pNext->pPrev = pLabel->pPrev;
	else
		pLabelListTail = pLabel->pPrev;
	if (pLabel->pPrev)
		pLabel->pPrev->pNext = pLabel->pNext;
	else
		pLabelList = pLabel->pNext;
	delete pLabel;
}

inline PMAPSPAWN InitSpawn()
{
	try {
		PMAPSPAWN pSpawn = new MAPSPAWN;
		pSpawn->pLast = 0;
		pSpawn->pNext = pActiveSpawns;
		if (pActiveSpawns)
			pActiveSpawns->pLast = pSpawn;
		pActiveSpawns = pSpawn;
		return pSpawn;
	}
	catch (std::bad_alloc& exc)
	{
		UNREFERENCED_PARAMETER(exc);
		MessageBox(NULL, "mq2map failed to allocate memory in InitSpawn", "Did we just discover a memory leak?", MB_SYSTEMMODAL | MB_OK);
	};
	return NULL;
}

inline void DeleteSpawn(PMAPSPAWN pMapSpawn)
{
	if (pMapSpawn && pMapSpawn->pNext)
		pMapSpawn->pNext->pLast = pMapSpawn->pLast;
	if (pMapSpawn && pMapSpawn->pLast)
		pMapSpawn->pLast->pNext = pMapSpawn->pNext;
	else {
		if (pMapSpawn) {
			pActiveSpawns = pMapSpawn->pNext;
		}
	}
	if (pMapSpawn) {
		delete pMapSpawn;
	}
}

void GenerateMarker(PMAPSPAWN pMapSpawn);
PCHAR GenerateSpawnName(PSPAWNINFO pSpawn, PCHAR NameString);//just a forward decl.
DWORD GetSpawnColor(eSpawnType Type, PSPAWNINFO pSpawn);//just a forward decl.
PMAPLABEL GenerateLabel(PMAPSPAWN pMapSpawn, DWORD Color);//just a forward decl.
PMAPLINE GenerateVector(PMAPSPAWN pMapSpawn);//just a forward decl.
BOOL CanDisplaySpawn(eSpawnType Type, PSPAWNINFO pSpawn);//just a forward decl.
void RemoveMarker(PMAPSPAWN pMapSpawn);
void MoveMarker(PMAPSPAWN pMapSpawn);

VOID MapInit()
{
	for (unsigned long i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
	{
		pCastRadius[i] = 0;
		pSpellRadius[i] = 0;
		pTargetRadius[i] = 0;
		pTargetMelee[i] = 0;
	}
}

PMAPSPAWN AddSpawn(PSPAWNINFO pNewSpawn, BOOL ExplicitAllow)
{
	CHAR szBuffer[MAX_STRING] = { 0 };
	char buf[MAX_STRING] = { 0 };
	eSpawnType Type = GetSpawnType(pNewSpawn);
	// apply map filter
	if (!ExplicitAllow && !CanDisplaySpawn(Type, pNewSpawn))
		return 0;
	// add spawn to list

	if (PMAPSPAWN pMapSpawn = InitSpawn()) {
		if (pNewSpawn->Type != FAKESPAWNTYPE)
			SpawnMap[pNewSpawn->SpawnID] = pMapSpawn;
		pMapSpawn->SpawnType = Type;
		pMapSpawn->pSpawn = pNewSpawn;
		pMapSpawn->pMapLabel = GenerateLabel(pMapSpawn, GetSpawnColor(Type, pNewSpawn));
		pMapSpawn->Explicit = ExplicitAllow;
		if (IsOptionEnabled(MAPFILTER_Vector))
			pMapSpawn->pVector = GenerateVector(pMapSpawn);
		else
			pMapSpawn->pVector = 0;

		pMapSpawn->Highlight = false;

#if 0
		//Debugging
		if (Type == SPAWN_CORPSE || Type == ITEM)
		{
			sprintf_s(buf, "AddSpawn(Corpse or Item): Name: %s, Type: %d, BodyType: %d",
				pMapSpawn->pSpawn->Name, pMapSpawn->pSpawn->Type, GetBodyType(pMapSpawn->pSpawn));
			DebugSpew("%s", buf);
		}
#endif

		// new stuff for Marker changes
		if (IsOptionEnabled(MAPFILTER_Marker)) {
			pMapSpawn->Marker = MapFilterOptions[TypeToMapfilter(pNewSpawn)].Marker;
			pMapSpawn->MarkerSize = MapFilterOptions[TypeToMapfilter(pNewSpawn)].MarkerSize;

			GenerateMarker(pMapSpawn);
			MoveMarker(pMapSpawn);
		}
		else if (!IsOptionEnabled(MAPFILTER_Marker)) {
			if (pMapSpawn->Marker != 0)
				pMapSpawn->Marker = 0;
		}
		return pMapSpawn;
	}
	return 0;
}

void RemoveSpawn(PMAPSPAWN pMapSpawn)
{
	if (pMapSpawn && pMapSpawn->pMapLabel) {
		if (pMapSpawn->pMapLabel->Label)
			free(pMapSpawn->pMapLabel->Label);
		DeleteLabel(pMapSpawn->pMapLabel);
	}
	if (pMapSpawn && pMapSpawn->pVector)
	{
		DeleteLine(pMapSpawn->pVector);
		pMapSpawn->pVector = 0;
	}
	if (pMapSpawn && pMapSpawn->Marker) {
		RemoveMarker(pMapSpawn);
	}
	if (pMapSpawn && pMapSpawn->pSpawn && pMapSpawn->pSpawn->Type == FAKESPAWNTYPE)
		delete pMapSpawn->pSpawn;
	else {
		if (pMapSpawn && pMapSpawn->pSpawn) {
			SpawnMap[pMapSpawn->pSpawn->SpawnID] = 0;
		}
	}
	if (pMapSpawn && pMapSpawn == pLastTarget) {
		pLastTarget = 0;
	}
	if (pMapSpawn) {
		DeleteSpawn(pMapSpawn);
	}
}

bool RemoveSpawn(PSPAWNINFO pSpawn)
{
	if (pSpawn) {
		if (SpawnMap.find(pSpawn->SpawnID) != SpawnMap.end()) {
			PMAPSPAWN pMapSpawn = SpawnMap[pSpawn->SpawnID];
			RemoveSpawn(pMapSpawn);
			return true;
		}
	}
	return false;
}

void AddGroundItem(PGROUNDITEM pGroundItem)
{
	PSPAWNINFO pFakeSpawn = new SPAWNINFO;
	memset(pFakeSpawn, 0, sizeof(SPAWNINFO));
	GetFriendlyNameForGroundItem(pGroundItem, pFakeSpawn->Name, sizeof(pFakeSpawn->Name));
	strcpy_s(pFakeSpawn->DisplayedName, pFakeSpawn->Name);
	pFakeSpawn->X = pGroundItem->X;
	pFakeSpawn->Y = pGroundItem->Y;
	pFakeSpawn->Z = pGroundItem->Z;

	pFakeSpawn->HPCurrent = 1;
	pFakeSpawn->HPMax = 1;
	pFakeSpawn->Heading = pGroundItem->Heading;
	pFakeSpawn->mActorClient.Race = pGroundItem->DropID;

	pFakeSpawn->Type = FAKESPAWNTYPE;
	PMAPSPAWN pMapSpawn = AddSpawn(pFakeSpawn);
	if (pMapSpawn)
		GroundItemMap[pGroundItem->DropID] = pMapSpawn;
	else
		delete pFakeSpawn;
}

void RemoveGroundItem(PGROUNDITEM pGroundItem)
{
	PMAPSPAWN pMapSpawn = GroundItemMap[pGroundItem->DropID];
	if (pMapSpawn)
	{
		GroundItemMap[pGroundItem->DropID] = 0;
		RemoveSpawn(pMapSpawn);
	}
}


void MapGenerate()
{
	if (!IsOptionEnabled(MAPFILTER_All))
		return;
	PSPAWNINFO pSpawn = (PSPAWNINFO)pSpawnList;
	while (pSpawn)
	{
		AddSpawn(pSpawn);
		pSpawn = pSpawn->pNext;
	}
	if (!IsOptionEnabled(MAPFILTER_Ground))
		return;
	PGROUNDITEM pItem = *(PGROUNDITEM*)pItemList;
	while (pItem)
	{
		AddGroundItem(pItem);
		pItem = pItem->pNext;
	}
}

void MapClear()
{
	GroundItemMap.clear();
	SpawnMap.clear();


	while (pActiveSpawns)
	{
		PMAPSPAWN pNextActive = pActiveSpawns->pNext;

		PMAPLABEL pLabel = pActiveSpawns->pMapLabel;
		DebugTry(free(pLabel->Label));
		DeleteLabel(pLabel);

		if (pActiveSpawns->pVector)
		{
			DeleteLine(pActiveSpawns->pVector);
			pActiveSpawns->pVector = 0;
		}

		if (pActiveSpawns->Marker)
			RemoveMarker(pActiveSpawns);
		if (pActiveSpawns->pSpawn && pActiveSpawns->pSpawn->Type == FAKESPAWNTYPE) // fake!
		{
			delete pActiveSpawns->pSpawn;
		}

		DeleteSpawn(pActiveSpawns);
		pActiveSpawns = pNextActive;
	}

	pLastTarget = 0;

	if (pTargetLine)
	{
		DeleteLine(pTargetLine);
		pTargetLine = 0;
	}

	if (pCastRadius[0])
	{
		for (unsigned long i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
		{
			DeleteLine(pCastRadius[i]);
			pCastRadius[i] = 0;
		}
	}
	if (pSpellRadius[0])
	{
		for (unsigned long i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
		{
			DeleteLine(pSpellRadius[i]);
			pSpellRadius[i] = 0;
		}
	}
	if (pTargetRadius[0])
	{
		for (unsigned long i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
		{
			DeleteLine(pTargetRadius[i]);
			pTargetRadius[i] = 0;
		}
	}
	if (pTargetMelee[0])
	{
		for (unsigned long i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
		{
			DeleteLine(pTargetMelee[i]);
			pTargetMelee[i] = 0;
		}
	}
}

void MapUpdate()
{
	char buf[MAX_STRING] = { 0 };
	PCHARINFO pCharInfo = GetCharInfo();
	if (!pCharInfo)
		return;
	EnterMQ2Benchmark(bmMapRefresh);
	eSpawnType Type;
	PMAPSPAWN pMapSpawn;
	PMAPSPAWN pOldLastTarget = NULL;
	bool bTargetChanged = false;
	
	pOldLastTarget = pLastTarget;
	if (pLastTarget && pLastTarget->pSpawn != (PSPAWNINFO)pTarget)
	{
		if (pLastTarget->pSpawn == &EnviroTarget || !CanDisplaySpawn(pLastTarget->SpawnType, pLastTarget->pSpawn))
		{
			RemoveSpawn(pLastTarget);
		}
		pLastTarget = 0;
		bTargetChanged = true;
	}

	if (pTarget && IsOptionEnabled(MAPFILTER_Target))
	{
		pLastTarget = SpawnMap[((PSPAWNINFO)pTarget)->SpawnID];
		if (!pLastTarget)
		{
			pLastTarget = AddSpawn((PSPAWNINFO)pTarget);
		}
	}

	pMapSpawn = pActiveSpawns;

	while (pMapSpawn)
	{
#if 0
		// Debugging
		DWORD BodyType = GetBodyType(pMapSpawn->pSpawn);
		if (pMapSpawn->pSpawn->Type == SPAWN_PLAYER)
		{
			if (BodyType != 1)
			{
				sprintf_s(buf, "MapUpdate: Name: %s, Type: %d, BodyType: %d",
					pMapSpawn->pSpawn->Name, pMapSpawn->pSpawn->Type, BodyType);
				DebugSpew("%s", buf);
			}
		}
		else if (pMapSpawn->pSpawn->Type == SPAWN_NPC)
		{
			if (BodyType != 1 && BodyType != 11 &&
				BodyType != 33 && BodyType != 65 &&
				BodyType != 66 && BodyType != 67 &&
				BodyType != 21 && BodyType != 23 &&
				BodyType != 34 && BodyType != 3 &&
				BodyType != 24)
			{
				sprintf_s(buf, "MapUpdate: Name: %s, Type: %d, BodyType: %d",
					pMapSpawn->pSpawn->Name, pMapSpawn->pSpawn->Type, BodyType);
				DebugSpew("%s", buf);
			}
		}
		else
		{
			sprintf_s(buf, "MapUpdate: Name: %s, Type: %d, BodyType: %d",
				pMapSpawn->pSpawn->Name, pMapSpawn->pSpawn->Type, BodyType);
			DebugSpew("%s", buf);
		}

		//End Debugging
#endif

		//Starting New Checks
		if (!pMapSpawn->Explicit && !CanDisplaySpawn(GetSpawnType(pMapSpawn->pSpawn), pMapSpawn->pSpawn))
		{
			PMAPSPAWN pNext = pMapSpawn->pNext;
			RemoveSpawn(pMapSpawn);
			pMapSpawn = pNext;
			continue;
		}
		//End New Checks

		pMapSpawn->pMapLabel->Location.X = -pMapSpawn->pSpawn->X;
		pMapSpawn->pMapLabel->Location.Y = -pMapSpawn->pSpawn->Y;
		pMapSpawn->pMapLabel->Location.Z = pMapSpawn->pSpawn->Z;

		if (pMapSpawn->Highlight)
		{
			pMapSpawn->pMapLabel->Color.ARGB = HighlightColor;
		}
		else
		{
			Type = GetSpawnType(pMapSpawn->pSpawn);
			if (Type != pMapSpawn->SpawnType || ((pMapSpawn == pOldLastTarget) && bTargetChanged))
			{
				if (!CanDisplaySpawn(Type, pMapSpawn->pSpawn))
				{
					PMAPSPAWN pNext = pMapSpawn->pNext;
					RemoveSpawn(pMapSpawn);
					pMapSpawn = pNext;
					continue;
				}

				pMapSpawn->SpawnType = Type;
				free(pMapSpawn->pMapLabel->Label);
				pMapSpawn->pMapLabel->Label = GenerateSpawnName(pMapSpawn->pSpawn, MapNameString);

			}
			pMapSpawn->pMapLabel->Color.ARGB = GetSpawnColor(pMapSpawn->SpawnType, pMapSpawn->pSpawn);
		}

		if (pMapSpawn->pVector)
		{
			if (pMapSpawn->pSpawn->SpeedRun>0) {
				pMapSpawn->pVector->Start.X = -pMapSpawn->pSpawn->X;
				pMapSpawn->pVector->Start.Y = -pMapSpawn->pSpawn->Y;
				pMapSpawn->pVector->Start.Z = pMapSpawn->pSpawn->Z;
				pMapSpawn->pVector->End.X = -pMapSpawn->pSpawn->X - pMapSpawn->pSpawn->SpeedX * 4;
				pMapSpawn->pVector->End.Y = -pMapSpawn->pSpawn->Y - pMapSpawn->pSpawn->SpeedY * 4;
				pMapSpawn->pVector->End.Z = pMapSpawn->pSpawn->Z + pMapSpawn->pSpawn->SpeedZ * 4;
			}
			else {
				pMapSpawn->pVector->Start.X = -pMapSpawn->pSpawn->X;
				pMapSpawn->pVector->Start.Y = -pMapSpawn->pSpawn->Y;
				pMapSpawn->pVector->Start.Z = pMapSpawn->pSpawn->Z;
				pMapSpawn->pVector->End.X = -pMapSpawn->pSpawn->X - sinf(pMapSpawn->pSpawn->Heading / 256.0f*(FLOAT)PI) * 4;
				pMapSpawn->pVector->End.Y = -pMapSpawn->pSpawn->Y - cosf(pMapSpawn->pSpawn->Heading / 256.0f*(FLOAT)PI) * 4;
				pMapSpawn->pVector->End.Z = pMapSpawn->pSpawn->Z;
			}
		}

		if (IsOptionEnabled(MAPFILTER_Marker))
			MoveMarker(pMapSpawn);
		else if (!IsOptionEnabled(MAPFILTER_Marker))
			RemoveMarker(pMapSpawn);
		pMapSpawn = pMapSpawn->pNext;
	}

	if (IsOptionEnabled(MAPFILTER_CastRadius))
	{
		unsigned long Angle = 0;
		for (unsigned long i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++, Angle += CASTRADIUS_ANGLESIZE)
		{
			if (!pCastRadius[i])
			{
				pCastRadius[i] = InitLine();
				pCastRadius[i]->Layer = activeLayer;
			}

			pCastRadius[i]->Color.ARGB = MapFilterOptions[MAPFILTER_CastRadius].Color;
			pCastRadius[i]->Start.Z = pCharInfo->pSpawn->Z;
			pCastRadius[i]->End.Z = pCharInfo->pSpawn->Z;
			pCastRadius[i]->Start.X = -pCharInfo->pSpawn->X + (FLOAT)MapFilterOptions[MAPFILTER_CastRadius].Enabled*cosf((FLOAT)Angle / 180.0f*(FLOAT)PI);
			pCastRadius[i]->Start.Y = -pCharInfo->pSpawn->Y + (FLOAT)MapFilterOptions[MAPFILTER_CastRadius].Enabled*sinf((FLOAT)Angle / 180.0f*(FLOAT)PI);;
			pCastRadius[i]->End.X = -pCharInfo->pSpawn->X + (FLOAT)MapFilterOptions[MAPFILTER_CastRadius].Enabled*cosf((FLOAT)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f*(FLOAT)PI);
			pCastRadius[i]->End.Y = -pCharInfo->pSpawn->Y + (FLOAT)MapFilterOptions[MAPFILTER_CastRadius].Enabled*sinf((FLOAT)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f*(FLOAT)PI);
		}
	}
	else if (pCastRadius[0])
	{
		for (unsigned long i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
		{
			DeleteLine(pCastRadius[i]);
			pCastRadius[i] = 0;
		}
	}

	if (IsOptionEnabled(MAPFILTER_SpellRadius))
	{
		unsigned long Angle = 0;
		for (unsigned long i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++, Angle += CASTRADIUS_ANGLESIZE)
		{
			if (!pSpellRadius[i])
			{
				pSpellRadius[i] = InitLine();
				pSpellRadius[i]->Layer = activeLayer;
			}

			pSpellRadius[i]->Color.ARGB = MapFilterOptions[MAPFILTER_SpellRadius].Color;
			pSpellRadius[i]->Start.Z = pCharInfo->pSpawn->Z;
			pSpellRadius[i]->End.Z = pCharInfo->pSpawn->Z;
			pSpellRadius[i]->Start.X = -pCharInfo->pSpawn->X + (FLOAT)MapFilterOptions[MAPFILTER_SpellRadius].Enabled*cosf((FLOAT)Angle / 180.0f*(FLOAT)PI);
			pSpellRadius[i]->Start.Y = -pCharInfo->pSpawn->Y + (FLOAT)MapFilterOptions[MAPFILTER_SpellRadius].Enabled*sinf((FLOAT)Angle / 180.0f*(FLOAT)PI);;
			pSpellRadius[i]->End.X = -pCharInfo->pSpawn->X + (FLOAT)MapFilterOptions[MAPFILTER_SpellRadius].Enabled*cosf((FLOAT)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f*(FLOAT)PI);
			pSpellRadius[i]->End.Y = -pCharInfo->pSpawn->Y + (FLOAT)MapFilterOptions[MAPFILTER_SpellRadius].Enabled*sinf((FLOAT)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f*(FLOAT)PI);
		}
	}
	else if (pSpellRadius[0])
	{
		for (unsigned long i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
		{
			DeleteLine(pSpellRadius[i]);
			pSpellRadius[i] = 0;
		}
	}

	if (IsOptionEnabled(MAPFILTER_Group))
	{
		PCHARINFO pChar = GetCharInfo();
		for (unsigned long i = 1; i<6; i++)
		{
			if (pChar->pGroupInfo && pChar->pGroupInfo->pMember[i])
			{
				CHAR Name[MAX_STRING] = { 0 };
				GetCXStr(pChar->pGroupInfo->pMember[i]->pName, Name, MAX_STRING);
				PSPAWNINFO pSpawn = (PSPAWNINFO)GetSpawnByName(Name);
				if (pSpawn)
					if (pMapSpawn = SpawnMap[pSpawn->SpawnID])
					{
						pMapSpawn->pMapLabel->Color.ARGB = MapFilterOptions[MAPFILTER_Group].Color;
					}
			}
		}
	}

	if (pLastTarget)
	{
		pLastTarget->pMapLabel->Color.ARGB = MapFilterOptions[MAPFILTER_Target].Color;
		free(pLastTarget->pMapLabel->Label);
		pLastTarget->pMapLabel->Label = GenerateSpawnName(pLastTarget->pSpawn, MapTargetNameString);

		if (IsOptionEnabled(MAPFILTER_TargetLine))
		{
			if (!pTargetLine)
			{
				pTargetLine = InitLine();
				pTargetLine->Layer = activeLayer;
			}
			pTargetLine->Color.ARGB = MapFilterOptions[MAPFILTER_Target].Color;
			pTargetLine->Start.X = -pCharInfo->pSpawn->X;
			pTargetLine->Start.Y = -pCharInfo->pSpawn->Y;
			pTargetLine->Start.Z = pCharInfo->pSpawn->Z;

			pTargetLine->End.X = -((PSPAWNINFO)pTarget)->X;
			pTargetLine->End.Y = -((PSPAWNINFO)pTarget)->Y;
			pTargetLine->End.Z = ((PSPAWNINFO)pTarget)->Z;
		}
		else if (pTargetLine)
		{
			DeleteLine(pTargetLine);
			pTargetLine = 0;
		}

		if (IsOptionEnabled(MAPFILTER_TargetRadius))
		{
			unsigned long Angle = 0;
			for (unsigned long i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++, Angle += CASTRADIUS_ANGLESIZE)
			{
				if (!pTargetRadius[i])
				{
					pTargetRadius[i] = InitLine();
					pTargetRadius[i]->Layer = activeLayer;
				}

				pTargetRadius[i]->Color.ARGB = MapFilterOptions[MAPFILTER_TargetRadius].Color;
				pTargetRadius[i]->Start.Z = ((PSPAWNINFO)pTarget)->Z;
				pTargetRadius[i]->End.Z = ((PSPAWNINFO)pTarget)->Z;
				pTargetRadius[i]->Start.X = -((PSPAWNINFO)pTarget)->X + (FLOAT)MapFilterOptions[MAPFILTER_TargetRadius].Enabled*cosf((FLOAT)Angle / 180.0f*(FLOAT)PI);
				pTargetRadius[i]->Start.Y = -((PSPAWNINFO)pTarget)->Y + (FLOAT)MapFilterOptions[MAPFILTER_TargetRadius].Enabled*sinf((FLOAT)Angle / 180.0f*(FLOAT)PI);;
				pTargetRadius[i]->End.X = -((PSPAWNINFO)pTarget)->X + (FLOAT)MapFilterOptions[MAPFILTER_TargetRadius].Enabled*cosf((FLOAT)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f*(FLOAT)PI);
				pTargetRadius[i]->End.Y = -((PSPAWNINFO)pTarget)->Y + (FLOAT)MapFilterOptions[MAPFILTER_TargetRadius].Enabled*sinf((FLOAT)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f*(FLOAT)PI);
			}
		}
		else if (pTargetRadius[0])
		{
			for (unsigned long i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
			{
				DeleteLine(pTargetRadius[i]);
				pTargetRadius[i] = 0;
			}
		}

		if (IsOptionEnabled(MAPFILTER_TargetMelee))
		{
			unsigned long Angle = 0;
			for (unsigned long i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++, Angle += CASTRADIUS_ANGLESIZE)
			{
				if (!pTargetMelee[i])
				{
					pTargetMelee[i] = InitLine();
					pTargetMelee[i]->Layer = activeLayer;
				}

				pTargetMelee[i]->Color.ARGB = MapFilterOptions[MAPFILTER_TargetMelee].Color;
				pTargetMelee[i]->Start.Z = ((PSPAWNINFO)pTarget)->Z;
				pTargetMelee[i]->End.Z = ((PSPAWNINFO)pTarget)->Z;
				FLOAT MaxMelee;
				if (MapFilterOptions[MAPFILTER_TargetMelee].Enabled == 1)
					MaxMelee = get_melee_range(pCharSpawn, pTarget);
				else
					MaxMelee = get_melee_range(pTarget, pTarget);
				pTargetMelee[i]->Start.X = -((PSPAWNINFO)pTarget)->X + MaxMelee*cosf((FLOAT)Angle / 180.0f*(FLOAT)PI);
				pTargetMelee[i]->Start.Y = -((PSPAWNINFO)pTarget)->Y + MaxMelee*sinf((FLOAT)Angle / 180.0f*(FLOAT)PI);;
				pTargetMelee[i]->End.X = -((PSPAWNINFO)pTarget)->X + MaxMelee*cosf((FLOAT)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f*(FLOAT)PI);
				pTargetMelee[i]->End.Y = -((PSPAWNINFO)pTarget)->Y + MaxMelee*sinf((FLOAT)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f*(FLOAT)PI);
			}
		}
		else if (pTargetMelee[0])
		{
			for (unsigned long i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
			{
				DeleteLine(pTargetMelee[i]);
				pTargetMelee[i] = 0;
			}
		}
	}
	else
	{
		if (pTargetRadius[0])
		{
			for (unsigned long i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
			{
				DeleteLine(pTargetRadius[i]);
				pTargetRadius[i] = 0;
			}
		}

		if (pTargetMelee[0])
		{
			for (unsigned long i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
			{
				DeleteLine(pTargetMelee[i]);
				pTargetMelee[i] = 0;
			}
		}

		if (pTargetLine)
		{
			DeleteLine(pTargetLine);
			pTargetLine = 0;
		}
	}
	ExitMQ2Benchmark(bmMapRefresh);



}


PMAPLABEL pActualLineList = 0;
void MapAttach()
{
	if (pLabelList)
	{
		pActualLineList = pMap->pLabels;
		if (IsOptionEnabled(MAPFILTER_NormalLabels))
			pLabelListTail->pNext = pMap->pLabels;
		pMap->pLabels = pLabelList;
	}

	if (pLineList)
	{
		pLineListTail->pNext = pMap->pLines;
		pMap->pLines = pLineList;
	}
}

void MapDetach()
{
	if (pLabelList)
	{
		pMap->pLabels = pActualLineList;
		pLabelListTail->pNext = 0;
	}
	if (pLineList)
	{
		pMap->pLines = pLineListTail->pNext;
		pLineListTail->pNext = 0;
	}
}

bool MapSelectTarget()
{
	if (!pCurrentMapLabel)
		return false;
	PMAPSPAWN pMapSpawn = LabelMap[pCurrentMapLabel];
	if (!pMapSpawn)
		return true;
	if (pMapSpawn->SpawnType == ITEM)
	{
		EnviroTarget = *pMapSpawn->pSpawn;
		EnviroTarget.Type = SPAWN_NPC;
		//EnviroTarget.SpawnID=2999;
		//pTarget = (EQPlayer*)&EnviroTarget;                 
	}
	else
	{
		DWORD Flags = pWndMgr->GetKeyboardFlags();
		PCHARINFO pCharInfo = GetCharInfo();
		if (pCharInfo && Flags && MapSpecialClickString[Flags][0])
		{
			PCHAR Cmd = GenerateSpawnName(pMapSpawn->pSpawn, MapSpecialClickString[Flags]);
#ifndef ISXEQ
			DoCommand(pCharInfo->pSpawn, Cmd);
#else
			pISInterface->ExecuteCommand(Cmd);
#endif
			free(Cmd);
		}
		else
		{
			pTarget = (EQPlayer*)pMapSpawn->pSpawn;
		}
	}
	if (IsOptionEnabled(MAPFILTER_TargetPath))
		return true;
	return false;
}

DWORD MapHighlight(SEARCHSPAWN *pSearch)
{
	if (!pSearch)
	{
		PMAPSPAWN pMapSpawn = pActiveSpawns;
		while (pMapSpawn)
		{
			pMapSpawn->Highlight = false;
			pMapSpawn = pMapSpawn->pNext;
		}
		return 0;
	}
	else
	{
		PCHARINFO pCharInfo = GetCharInfo();
		if (!pCharInfo || !pCharInfo->pSpawn)
			return 0;
		PMAPSPAWN pMapSpawn = pActiveSpawns;
		unsigned long Count = 0;
		while (pMapSpawn)
		{
			// update!
			if (SpawnMatchesSearch(pSearch, pCharInfo->pSpawn, pMapSpawn->pSpawn))
			{
				pMapSpawn->Highlight = true;
				Count++;
			}

			pMapSpawn = pMapSpawn->pNext;
		}
		return Count;
	}
}

PCHAR GenerateSpawnName(PSPAWNINFO pSpawn, PCHAR NameString)
{
    string sOutput;
#define AddString(str) {sOutput.append( str );}
#define AddInt(yourint) {sOutput.append( to_string( yourint ) );}
#define AddFloat10th(yourfloat) {sOutput.append( to_string( yourfloat ) );}

	for (unsigned long N = 0; NameString[N]; N++)
	{
		if (NameString[N] == '%')
		{
			N++;
			switch (NameString[N])
			{
			case 'N':// cleaned up name
                sOutput.append( pSpawn->DisplayedName );
                if( pSpawn->Type == SPAWN_CORPSE )
                {
                    sOutput.append( "'s Corpse" );
                }
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
				AddString(pEverQuest->GetRaceDesc(pSpawn->mActorClient.Race));
				break;
			case 'C':
				AddString(GetClassDesc(pSpawn->mActorClient.Class));
				break;
			case 'c':
				AddString(pEverQuest->GetClassThreeLetterCode(pSpawn->mActorClient.Class));
				break;
			case 'l':
				AddInt(pSpawn->Level);
				break;
			case '%':
				sOutput.append( 1, NameString[N] );
				break;
			}
		}
		else
            sOutput.append( 1, NameString[N] );
	}
	
    int len = sOutput.length() + 1;
	if (PCHAR ret = (PCHAR)malloc(len)) {
		strcpy_s(ret, len, sOutput.c_str());
		return ret;
	}
	return 0;
}

DWORD TypeToMapfilter(PSPAWNINFO pNewSpawn)
{
	eSpawnType Type = GetSpawnType(pNewSpawn);

	switch (Type)
	{
	case PC:
		return MAPFILTER_PC;
	case NPC:
		if (IsOptionEnabled(MAPFILTER_Named)) {
			if (PCHARINFO pCharInfo = GetCharInfo()) {
				if (SpawnMatchesSearch(&MapFilterNamed, pCharInfo->pSpawn, pNewSpawn)) {
					return MAPFILTER_Named;
				}
			}
		}

		return MAPFILTER_NPC;
	case CORPSE:
		return MAPFILTER_Corpse;
	case ITEM:
		return MAPFILTER_Ground;
	case UNTARGETABLE:
		return MAPFILTER_Untargetable;
	case TIMER:
		return MAPFILTER_Timer;
	case TRAP:
		return MAPFILTER_Trap;
	case TRIGGER:
		return MAPFILTER_Trigger;
	case CHEST:
		return MAPFILTER_Chest;
	case PET:
		return MAPFILTER_Pet;
	case MOUNT:
		return MAPFILTER_Mount;
	case AURA:
		return MAPFILTER_Aura;
	case OBJECT:
		return MAPFILTER_Object;
	case BANNER:
		return MAPFILTER_Banner;
	}

	return MAPFILTER_Invalid;
}
BOOL CanDisplaySpawn(eSpawnType Type, PSPAWNINFO pSpawn)
{
	if (!pSpawn)
		return FALSE;

	if ((pSpawn == (PSPAWNINFO)pTarget) && IsOptionEnabled(MAPFILTER_Target))
	{
		return TRUE;
	}
	if (IsOptionEnabled(MAPFILTER_Custom))
	{
		if (PCHARINFO pCharInfo = GetCharInfo())
			if (pCharInfo->pSpawn)
				return SpawnMatchesSearch(&MapFilterCustom, pCharInfo->pSpawn, pSpawn);
	}
	switch (Type)
	{
	case PC:
		return IsOptionEnabled(MAPFILTER_PC);
	case NPC:
		if (IsOptionEnabled(MAPFILTER_Named))
			return IsNamed(pSpawn);
		else
			return IsOptionEnabled(MAPFILTER_NPC);
	case CORPSE:
		if (pSpawn->Deity == 0)
			return (IsOptionEnabled(MAPFILTER_NPCCorpse) && IsOptionEnabled(MAPFILTER_Corpse));
		else
			return (IsOptionEnabled(MAPFILTER_PCCorpse) && IsOptionEnabled(MAPFILTER_Corpse));
	case ITEM:
		return IsOptionEnabled(MAPFILTER_Ground);
	case UNTARGETABLE:
		return IsOptionEnabled(MAPFILTER_Untargetable);
	case TIMER:
		return IsOptionEnabled(MAPFILTER_Timer);
	case TRAP:
		return IsOptionEnabled(MAPFILTER_Trap);
	case TRIGGER:
		return IsOptionEnabled(MAPFILTER_Trigger);
	case CHEST:
		return IsOptionEnabled(MAPFILTER_Chest);
	case PET:
		return IsOptionEnabled(MAPFILTER_Pet);
	case MOUNT:
		return IsOptionEnabled(MAPFILTER_Mount);
	case AURA:
		return IsOptionEnabled(MAPFILTER_Aura);
	case OBJECT:
		return IsOptionEnabled(MAPFILTER_Object);
	case BANNER:
		return IsOptionEnabled(MAPFILTER_Banner);
	case CAMPFIRE:
		return IsOptionEnabled(MAPFILTER_Campfire);
	case MERCENARY:
		return IsOptionEnabled(MAPFILTER_Mercenary);
	case FLYER:
		return FALSE; // they have no location data, no use trying to display them
	}
	return TRUE;
}

inline DWORD GetSpawnColor(eSpawnType Type, PSPAWNINFO pSpawn)
{
	PCHARINFO pChar = GetCharInfo();
	if (!pChar)
		return 0;

	switch (Type)
	{
	case PC:
		if (IsOptionEnabled(MAPFILTER_PCConColor))
			return ConColorToARGB(ConColor(pSpawn));
		return MapFilterOptions[MAPFILTER_PC].Color;
	case NPC:
		if (IsOptionEnabled(MAPFILTER_NPCConColor))
			return ConColorToARGB(ConColor(pSpawn));
		return MapFilterOptions[MAPFILTER_NPC].Color;
	case CORPSE:
		if (pSpawn->Deity == 0)
			return MapFilterOptions[MAPFILTER_NPCCorpse].Color;
		else
			return MapFilterOptions[MAPFILTER_PCCorpse].Color;
	case UNTARGETABLE:
		return MapFilterOptions[MAPFILTER_Untargetable].Color;
	case CHEST:
		return MapFilterOptions[MAPFILTER_Chest].Color;
	case TRIGGER:
		return MapFilterOptions[MAPFILTER_Trigger].Color;
	case TIMER:
		return MapFilterOptions[MAPFILTER_Timer].Color;
	case TRAP:
		return MapFilterOptions[MAPFILTER_Trap].Color;
	case ITEM:
		return MapFilterOptions[MAPFILTER_Ground].Color;
	case MOUNT:
		return MapFilterOptions[MAPFILTER_Mount].Color;
	case PET:
		return MapFilterOptions[MAPFILTER_Pet].Color;
	case AURA:
		return MapFilterOptions[MAPFILTER_Aura].Color;
	case OBJECT:
		return MapFilterOptions[MAPFILTER_Object].Color;
	case BANNER:
		return MapFilterOptions[MAPFILTER_Banner].Color;
	case CAMPFIRE:
		return MapFilterOptions[MAPFILTER_Campfire].Color;
	case MERCENARY:
		return MapFilterOptions[MAPFILTER_Mercenary].Color;
	}
	return 0;
}

PMAPLABEL GenerateLabel(PMAPSPAWN pMapSpawn, DWORD Color)
{
	PMAPLABEL pLabel = InitLabel(pMapSpawn);
	pLabel->Location.X = -pMapSpawn->pSpawn->X;
	pLabel->Location.Y = -pMapSpawn->pSpawn->Y;
	pLabel->Location.Z = pMapSpawn->pSpawn->Z;
	pLabel->Layer = activeLayer;
	pLabel->Size = 3;
	pLabel->Label = GenerateSpawnName(pMapSpawn->pSpawn, MapNameString);
	pLabel->Color.ARGB = Color;
	pLabel->Width = 20;
	pLabel->Height = 14;
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
		pNewLine->End.X = -pMapSpawn->pSpawn->X - pMapSpawn->pSpawn->SpeedX * 4;
		pNewLine->End.Y = -pMapSpawn->pSpawn->Y - pMapSpawn->pSpawn->SpeedY * 4;
		pNewLine->End.Z = pMapSpawn->pSpawn->Z + pMapSpawn->pSpawn->SpeedZ * 4;
	}
	else {
		pNewLine->Start.X = -pMapSpawn->pSpawn->X;
		pNewLine->Start.Y = -pMapSpawn->pSpawn->Y;
		pNewLine->Start.Z = pMapSpawn->pSpawn->Z;
		pNewLine->End.X = -pMapSpawn->pSpawn->X - sinf(pMapSpawn->pSpawn->Heading / 256.0f*(FLOAT)PI) * 4;
		pNewLine->End.Y = -pMapSpawn->pSpawn->Y - cosf(pMapSpawn->pSpawn->Heading / 256.0f*(FLOAT)PI) * 4;
		pNewLine->End.Z = pMapSpawn->pSpawn->Z;
	}



	pNewLine->Layer = activeLayer;
	pNewLine->Color = pMapSpawn->pMapLabel->Color;

	return pNewLine;
}

DWORD MapHide(SEARCHSPAWN &Search)
{
	PCHARINFO pCharInfo = GetCharInfo();
	if (!pCharInfo || !pCharInfo->pSpawn)
		return 0;
	PMAPSPAWN pMapSpawn = pActiveSpawns;
	unsigned long Count = 0;
	while (pMapSpawn)
	{
		if (pMapSpawn->pSpawn->Type != FAKESPAWNTYPE && SpawnMatchesSearch(&Search, pCharInfo->pSpawn, pMapSpawn->pSpawn))
		{
			PMAPSPAWN pNext = pMapSpawn->pNext;
			RemoveSpawn(pMapSpawn);
			pMapSpawn = pNext;
			Count++;
		}
		else
			pMapSpawn = pMapSpawn->pNext;
	}
	return Count;
}

DWORD MapShow(SEARCHSPAWN &Search)
{
	PCHARINFO pCharInfo = GetCharInfo();
	if (!pCharInfo)
		return 0;

	PSPAWNINFO pSpawn = (PSPAWNINFO)pSpawnList;
	unsigned long Count = 0;
	while (pSpawn)
	{
		if (!SpawnMap[pSpawn->SpawnID] && SpawnMatchesSearch(&Search, pCharInfo->pSpawn, pSpawn))
		{
			AddSpawn(pSpawn, true);
			Count++;
		}
		pSpawn = pSpawn->pNext;
	}
	return Count;
}

#ifndef ISXEQ
BOOL dataMapSpawn(PCHAR szIndex, MQ2TYPEVAR &Ret)
#else
bool dataMapSpawn(int argc, char *argv[], MQ2TYPEVAR &Ret)
#endif
{
	if (!pCurrentMapLabel)
		return false;
	if (PMAPSPAWN pMapSpawn = LabelMap[pCurrentMapLabel])
	{
		Ret.Ptr = pMapSpawn->pSpawn;
		Ret.Type = pSpawnType;
		return true;
	}
	return false;
}
void GenerateMarker(PMAPSPAWN pMapSpawn)
{
	if (pMapSpawn->Marker == 0) return;
	long lNumSides = 4;

	if (pMapSpawn->Marker == 1)
		lNumSides = 3;
	if (pMapSpawn->Marker == 4)
	{
		lNumSides = 8;
	}


	long i;
	for (i = 0; i < 9; i++)
		pMapSpawn->MarkerLines[i] = NULL;

	for (i = 0; i < lNumSides; i++) {
		PMAPLINE pNewLine = InitLine();
		pNewLine->Start.X = 0;
		pNewLine->Start.Y = 0;
		pNewLine->Start.Z = pMapSpawn->pSpawn->Z;
		pNewLine->End.X = 0;
		pNewLine->End.Y = 0;
		pNewLine->End.Z = pMapSpawn->pSpawn->Z;
		pNewLine->Layer = activeLayer;
		pNewLine->Color = pMapSpawn->pMapLabel->Color;
		pMapSpawn->MarkerLines[i] = pNewLine;
	}
}

void RemoveMarker(PMAPSPAWN pMapSpawn)
{
	if (pMapSpawn->Marker == 0 || !pMapSpawn->Marker) return;
	pMapSpawn->Marker = 0;
	for (int i = 0; pMapSpawn->MarkerLines[i]; i++) {
		if (pMapSpawn->MarkerLines[i]) {
			DeleteLine(pMapSpawn->MarkerLines[i]);
			pMapSpawn->MarkerLines[i] = NULL;
		}
	}
}

void MSM(PMAPSPAWN pMapSpawn)
{
	DWORD MARKERSIDELEN = pMapSpawn->MarkerSize;
	float x[1], y[1], X[1], Y[1];
	if (pMapSpawn->Highlight)
	{
		if (HighlightPulse)
		{
			MARKERSIDELEN = HighlightSIDELEN + (HighlightPulseIndex * HighlightPulseDiff);
		}
		else
		{
			MARKERSIDELEN = HighlightSIDELEN;
		}
	}

	x[0] = -pMapSpawn->pSpawn->X - MARKERSIDELEN / 2;
	x[1] = -pMapSpawn->pSpawn->X + MARKERSIDELEN / 2;
	y[0] = -pMapSpawn->pSpawn->Y - MARKERSIDELEN / 2;
	y[1] = -pMapSpawn->pSpawn->Y + MARKERSIDELEN / 2;

	for (int i = 0; i<4; i++) {
		switch (i) {
		case 0:   X[0] = x[0]; X[1] = x[1]; Y[0] = y[0]; Y[1] = y[0]; break;
		case 1:   X[0] = x[1]; X[1] = x[1]; Y[0] = y[0]; Y[1] = y[1]; break;
		case 2:   X[0] = x[1]; X[1] = x[0]; Y[0] = y[1]; Y[1] = y[1]; break;
		case 3:   X[0] = x[0]; X[1] = x[0]; Y[0] = y[1]; Y[1] = y[0]; break;
		}

		pMapSpawn->MarkerLines[i]->Start.X = X[0];
		pMapSpawn->MarkerLines[i]->Start.Y = Y[0];
		pMapSpawn->MarkerLines[i]->End.X = X[1];
		pMapSpawn->MarkerLines[i]->End.Y = Y[1];
		pMapSpawn->MarkerLines[i]->Start.Z = pMapSpawn->pSpawn->Z;
		pMapSpawn->MarkerLines[i]->End.Z = pMapSpawn->pSpawn->Z;

		if (pMapSpawn->MarkerLines[i]->Color.ARGB != pMapSpawn->pMapLabel->Color.ARGB)
			pMapSpawn->MarkerLines[i]->Color = pMapSpawn->pMapLabel->Color;
	}
}

void MTM(PMAPSPAWN pMapSpawn)
{
	DWORD MARKERSIDELEN = pMapSpawn->MarkerSize;
	float x[2], y[2], X[1], Y[1], Angle;
	if (pMapSpawn->Highlight)
	{
		if (HighlightPulse)
		{
			MARKERSIDELEN = HighlightSIDELEN + (HighlightPulseIndex * HighlightPulseDiff);
		}
		else
		{
			MARKERSIDELEN = HighlightSIDELEN;
		}
	}

	Angle = pMapSpawn->pSpawn->Heading*0.703125f;
	x[0] = -pMapSpawn->pSpawn->X + (MARKERSIDELEN*1.5f)*sqrtf(3) / 3 * sinf((Angle + 180) / 180.0f*(FLOAT)PI);
	x[1] = -pMapSpawn->pSpawn->X - (MARKERSIDELEN*1.5f)*sqrtf(3) / 3 * sinf((Angle + 210) / 180.0f*(FLOAT)PI);
	x[2] = -pMapSpawn->pSpawn->X + (MARKERSIDELEN*1.5f)*sqrtf(3) / 3 * sinf((Angle + 330) / 180.0f*(FLOAT)PI);
	y[0] = -pMapSpawn->pSpawn->Y + (MARKERSIDELEN*1.5f)*sqrtf(3) / 3 * cosf((Angle + 180) / 180.0f*(FLOAT)PI);
	y[1] = -pMapSpawn->pSpawn->Y - (MARKERSIDELEN*1.5f)*sqrtf(3) / 3 * cosf((Angle + 210) / 180.0f*(FLOAT)PI);
	y[2] = -pMapSpawn->pSpawn->Y + (MARKERSIDELEN*1.5f)*sqrtf(3) / 3 * cosf((Angle + 330) / 180.0f*(FLOAT)PI);

	for (int i = 0; i<3; i++) {
		switch (i) {
		case 0:   X[0] = x[0]; X[1] = x[1]; Y[0] = y[0]; Y[1] = y[1]; break;
		case 1:   X[0] = x[1]; X[1] = x[2]; Y[0] = y[1]; Y[1] = y[2]; break;
		case 2:   X[0] = x[2]; X[1] = x[0]; Y[0] = y[2]; Y[1] = y[0]; break;
		}

		pMapSpawn->MarkerLines[i]->Start.X = X[0];
		pMapSpawn->MarkerLines[i]->Start.Y = Y[0];
		pMapSpawn->MarkerLines[i]->End.X = X[1];
		pMapSpawn->MarkerLines[i]->End.Y = Y[1];
		pMapSpawn->MarkerLines[i]->Start.Z = pMapSpawn->pSpawn->Z;
		pMapSpawn->MarkerLines[i]->End.Z = pMapSpawn->pSpawn->Z;

		if (pMapSpawn->MarkerLines[i]->Color.ARGB != pMapSpawn->pMapLabel->Color.ARGB)
			pMapSpawn->MarkerLines[i]->Color = pMapSpawn->pMapLabel->Color;
	}
}

void MDM(PMAPSPAWN pMapSpawn)
{
	DWORD MARKERSIDELEN = pMapSpawn->MarkerSize;
	float x[2], y[2], X[1], Y[1];
	if (pMapSpawn->Highlight)
	{
		if (HighlightPulse)
		{
			MARKERSIDELEN = HighlightSIDELEN + (HighlightPulseIndex * HighlightPulseDiff);
		}
		else
		{
			MARKERSIDELEN = HighlightSIDELEN;
		}
	}

	x[0] = -pMapSpawn->pSpawn->X;
	x[1] = -pMapSpawn->pSpawn->X + MARKERSIDELEN*.71f;   // sqrt(2)/2
	x[2] = -pMapSpawn->pSpawn->X - MARKERSIDELEN*.71f;
	y[0] = -pMapSpawn->pSpawn->Y - MARKERSIDELEN*.71f;
	y[1] = -pMapSpawn->pSpawn->Y;
	y[2] = -pMapSpawn->pSpawn->Y + MARKERSIDELEN*.71f;

	for (int i = 0; i<4; i++) {
		switch (i) {
		case 0:   X[0] = x[0]; X[1] = x[1]; Y[0] = y[0]; Y[1] = y[1]; break;
		case 1:   X[0] = x[1]; X[1] = x[0]; Y[0] = y[1]; Y[1] = y[2]; break;
		case 2:   X[0] = x[0]; X[1] = x[2]; Y[0] = y[2]; Y[1] = y[1]; break;
		case 3:   X[0] = x[2]; X[1] = x[0]; Y[0] = y[1]; Y[1] = y[0]; break;
		}

		pMapSpawn->MarkerLines[i]->Start.X = X[0];
		pMapSpawn->MarkerLines[i]->Start.Y = Y[0];
		pMapSpawn->MarkerLines[i]->End.X = X[1];
		pMapSpawn->MarkerLines[i]->End.Y = Y[1];
		pMapSpawn->MarkerLines[i]->Start.Z = pMapSpawn->pSpawn->Z;
		pMapSpawn->MarkerLines[i]->End.Z = pMapSpawn->pSpawn->Z;

		if (pMapSpawn->MarkerLines[i]->Color.ARGB != pMapSpawn->pMapLabel->Color.ARGB)
			pMapSpawn->MarkerLines[i]->Color = pMapSpawn->pMapLabel->Color;
	}
}


void MRM(PMAPSPAWN pMapSpawn)
{
	DWORD MARKERSIDELEN = pMapSpawn->MarkerSize;
	if (pMapSpawn->Highlight)
	{
		if (HighlightPulse)
		{
			MARKERSIDELEN = HighlightSIDELEN + (HighlightPulseIndex * HighlightPulseDiff);
		}
		else
		{
			MARKERSIDELEN = HighlightSIDELEN;
		}
	}

	for (int i = 0; i<8; i++) {

		pMapSpawn->MarkerLines[i]->Start.X = -pMapSpawn->pSpawn->X + MARKERSIDELEN*sinf((i * 45 + (FLOAT)22.5) / 180.0f*(FLOAT)PI);
		pMapSpawn->MarkerLines[i]->Start.Y = -pMapSpawn->pSpawn->Y + MARKERSIDELEN*cosf((i * 45 + (FLOAT)22.5) / 180.0f*(FLOAT)PI);
		pMapSpawn->MarkerLines[i]->End.X = -pMapSpawn->pSpawn->X + MARKERSIDELEN*sinf(((i + 1) * 45 + (FLOAT)22.5) / 180.0f*(FLOAT)PI);
		pMapSpawn->MarkerLines[i]->End.Y = -pMapSpawn->pSpawn->Y + MARKERSIDELEN*cosf(((i + 1) * 45 + (FLOAT)22.5) / 180.0f*(FLOAT)PI);
		pMapSpawn->MarkerLines[i]->Start.Z = pMapSpawn->pSpawn->Z;
		pMapSpawn->MarkerLines[i]->End.Z = pMapSpawn->pSpawn->Z;

		if (pMapSpawn->MarkerLines[i]->Color.ARGB != pMapSpawn->pMapLabel->Color.ARGB)
			pMapSpawn->MarkerLines[i]->Color = pMapSpawn->pMapLabel->Color;
	}
}

void MoveMarker(PMAPSPAWN pMapSpawn)
{
	switch (pMapSpawn->Marker) {
	case 1: //triangle
		MTM(pMapSpawn);
		return;
	case 2: //square
		MSM(pMapSpawn);
		return;
	case 3: //diamond
		MDM(pMapSpawn);
		return;
	case 4: //ring
		MRM(pMapSpawn);
		return;
	}
}

DWORD FindMarker(PCHAR szMark)
{
	if (!_stricmp(szMark, "none"))
		return 0;
	else if (!_stricmp(szMark, "triangle"))
		return 1;
	else if (!_stricmp(szMark, "square"))
		return 2;
	else if (!_stricmp(szMark, "diamond"))
		return 3;
	else if (!_stricmp(szMark, "ring"))
		return 4;
	return 99;
}

// make a current timestamp in tenths of a second
long MakeTime()
{
	SYSTEMTIME st;
	::GetSystemTime(&st);
	long lCurrent = 0;
	lCurrent = st.wDay * 24 * 60 * 60 * 10;
	lCurrent += st.wHour * 60 * 60 * 10;
	lCurrent += st.wMinute * 60 * 10;
	lCurrent += st.wSecond * 10;
	lCurrent += (long)(st.wMilliseconds / 100);
	return (lCurrent);
}

VOID UpdateDefaultMapLoc()
{
#ifdef ISXEQ
	DefaultMapLoc->lineSize = 50;
	DefaultMapLoc->width = 10;
	DefaultMapLoc->r_color = 255;
	DefaultMapLoc->g_color = 0;
	DefaultMapLoc->b_color = 0;
#else
	DefaultMapLoc->lineSize = GetPrivateProfileInt("MapLoc", "Size", 50, INIFileName);
	DefaultMapLoc->width = GetPrivateProfileInt("MapLoc", "Width", 10, INIFileName);
	DefaultMapLoc->r_color = GetPrivateProfileInt("MapLoc", "Red", 255, INIFileName);
	DefaultMapLoc->g_color = GetPrivateProfileInt("MapLoc", "Green", 0, INIFileName);
	DefaultMapLoc->b_color = GetPrivateProfileInt("MapLoc", "Blue", 0, INIFileName);
#endif
	// Update existing default maplocs
	for (map<string, PMAPLOC>::iterator it = LocationMap.begin(); it != LocationMap.end(); it++)
	{
		PMAPLOC loc = it->second;
		if (loc && loc->isCreatedFromDefaultLoc)
		{
			loc->lineSize = DefaultMapLoc->lineSize;
			loc->width = DefaultMapLoc->width;
			loc->r_color = DefaultMapLoc->r_color;
			loc->g_color = DefaultMapLoc->g_color;
			loc->b_color = DefaultMapLoc->b_color;
			UpdateMapLocLines(loc);
		}
	}
}

VOID ClearMapLocLines(PMAPLOC mapLoc)
{
	if (mapLoc)
	{
		for (int i = 0; i < 50; i++)
		{
			if (mapLoc->markerLines[i])
			{
				DeleteLine(mapLoc->markerLines[i]);
				mapLoc->markerLines[i] = NULL;
			}
		}
	}
}

VOID UpdateMapLocLines(PMAPLOC mapLoc)
{
	if (!mapLoc)
	{
		return;
	}
	ClearMapLocLines(mapLoc);

	int j = 0;
	
	for (int i = 1; i <= mapLoc->width; i++) {
		if (i == 1)
		{
			//Backslash
			mapLoc->markerLines[j] = InitLine();
			mapLoc->markerLines[j]->Start.X = (FLOAT) -mapLoc->xloc - mapLoc->lineSize;
			mapLoc->markerLines[j]->Start.Y = (FLOAT)-mapLoc->yloc - mapLoc->lineSize;
			mapLoc->markerLines[j]->Start.Z = 0;
			mapLoc->markerLines[j]->End.X = (FLOAT)-mapLoc->xloc + mapLoc->lineSize;
			mapLoc->markerLines[j]->End.Y = (FLOAT)-mapLoc->yloc + mapLoc->lineSize;
			mapLoc->markerLines[j]->End.Z = 0;
			mapLoc->markerLines[j]->Layer = activeLayer;
			ARGBCOLOR bsColor;
			bsColor.ARGB = 0xFF000000 | (mapLoc->r_color << 16) | (mapLoc->g_color << 8) | (mapLoc->b_color);
			mapLoc->markerLines[j++]->Color = bsColor;

			//Forwardslash
			mapLoc->markerLines[j] = InitLine();
			mapLoc->markerLines[j]->Start.X = (FLOAT)-mapLoc->xloc - mapLoc->lineSize;
			mapLoc->markerLines[j]->Start.Y = (FLOAT)-mapLoc->yloc + mapLoc->lineSize;
			mapLoc->markerLines[j]->Start.Z = 0;
			mapLoc->markerLines[j]->End.X = (FLOAT)-mapLoc->xloc + mapLoc->lineSize;
			mapLoc->markerLines[j]->End.Y = (FLOAT)-mapLoc->yloc - mapLoc->lineSize;
			mapLoc->markerLines[j]->End.Z = 0;
			mapLoc->markerLines[j]->Layer = activeLayer;
			ARGBCOLOR fsColor;
			fsColor.ARGB = 0xFF000000 | (mapLoc->r_color << 16) | (mapLoc->g_color << 8) | (mapLoc->b_color);
			mapLoc->markerLines[j++]->Color = fsColor;
		}
		else
		{
			//Backslash lower
			mapLoc->markerLines[j] = InitLine();
			mapLoc->markerLines[j]->Start.X = (FLOAT)-mapLoc->xloc - mapLoc->lineSize;
			mapLoc->markerLines[j]->Start.Y = (FLOAT)-mapLoc->yloc - mapLoc->lineSize + i - 1;
			mapLoc->markerLines[j]->Start.Z = 0;
			mapLoc->markerLines[j]->End.X = (FLOAT)-mapLoc->xloc + mapLoc->lineSize - i + 1;
			mapLoc->markerLines[j]->End.Y = (FLOAT)-mapLoc->yloc + mapLoc->lineSize;
			mapLoc->markerLines[j]->End.Z = 0;
			mapLoc->markerLines[j]->Layer = activeLayer;
			ARGBCOLOR bslColor;
			bslColor.ARGB = 0xFF000000 | (mapLoc->r_color << 16) | (mapLoc->g_color << 8) | (mapLoc->b_color);
			mapLoc->markerLines[j++]->Color = bslColor;

			//Forwardslash lower
			mapLoc->markerLines[j] = InitLine();
			mapLoc->markerLines[j]->Start.X = (FLOAT)-mapLoc->xloc - mapLoc->lineSize + i - 1;
			mapLoc->markerLines[j]->Start.Y = (FLOAT)-mapLoc->yloc + mapLoc->lineSize;
			mapLoc->markerLines[j]->Start.Z = 0;
			mapLoc->markerLines[j]->End.X = (FLOAT)-mapLoc->xloc + mapLoc->lineSize;
			mapLoc->markerLines[j]->End.Y = (FLOAT)-mapLoc->yloc - mapLoc->lineSize + i - 1;
			mapLoc->markerLines[j]->End.Z = 0;
			mapLoc->markerLines[j]->Layer = activeLayer;
			ARGBCOLOR fslColor;
			fslColor.ARGB = 0xFF000000 | (mapLoc->r_color << 16) | (mapLoc->g_color << 8) | (mapLoc->b_color);
			mapLoc->markerLines[j++]->Color = fslColor;

			//Backslash upper
			mapLoc->markerLines[j] = InitLine();
			mapLoc->markerLines[j]->Start.X = (FLOAT)-mapLoc->xloc - mapLoc->lineSize + i - 1;
			mapLoc->markerLines[j]->Start.Y = (FLOAT)-mapLoc->yloc - mapLoc->lineSize;
			mapLoc->markerLines[j]->Start.Z = 0;
			mapLoc->markerLines[j]->End.X = (FLOAT)-mapLoc->xloc + mapLoc->lineSize;
			mapLoc->markerLines[j]->End.Y = (FLOAT)-mapLoc->yloc + mapLoc->lineSize - i + 1;
			mapLoc->markerLines[j]->End.Z = 0;
			mapLoc->markerLines[j]->Layer = activeLayer;
			ARGBCOLOR bsuColor;
			bsuColor.ARGB = 0xFF000000 | (mapLoc->r_color << 16) | (mapLoc->g_color << 8) | (mapLoc->b_color);
			mapLoc->markerLines[j++]->Color = bsuColor;

			//Forwardslash upper
			mapLoc->markerLines[j] = InitLine();
			mapLoc->markerLines[j]->Start.X = (FLOAT)-mapLoc->xloc - mapLoc->lineSize;
			mapLoc->markerLines[j]->Start.Y = (FLOAT)-mapLoc->yloc + mapLoc->lineSize - i + 1;
			mapLoc->markerLines[j]->Start.Z = 0;
			mapLoc->markerLines[j]->End.X = (FLOAT)-mapLoc->xloc + mapLoc->lineSize - i + 1;
			mapLoc->markerLines[j]->End.Y = (FLOAT)-mapLoc->yloc - mapLoc->lineSize;
			mapLoc->markerLines[j]->End.Z = 0;
			mapLoc->markerLines[j]->Layer = activeLayer;
			ARGBCOLOR fsuColor;
			fsuColor.ARGB = 0xFF000000 | (mapLoc->r_color << 16) | (mapLoc->g_color << 8) | (mapLoc->b_color);
			mapLoc->markerLines[j++]->Color = fsuColor;
		}
	}
}