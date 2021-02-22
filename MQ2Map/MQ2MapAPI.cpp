#include "../MQ2Plugin.h"
#include "MQ2Map.h"
#include <sstream>
#include <tuple>

#define pMap     ((PEQMAPWINDOW)pMapViewWnd)
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
list<PMAPLOC> maplocOrder = {};
PMAPLOC DefaultMapLoc = new MAPLOC;

BOOL Update = false;

#define CASTRADIUS_ANGLESIZE 10
PMAPLINE pCastRadius[(360 / CASTRADIUS_ANGLESIZE) + 1];
PMAPLINE pSpellRadius[(360 / CASTRADIUS_ANGLESIZE) + 1];
PMAPLINE pCampRadius[(360 / CASTRADIUS_ANGLESIZE) + 1];
PMAPLINE pPullRadius[(360 / CASTRADIUS_ANGLESIZE) + 1];
PMAPLINE pTargetRadius[(360 / CASTRADIUS_ANGLESIZE) + 1];
PMAPLINE pTargetMelee[(360 / CASTRADIUS_ANGLESIZE) + 1];

PMAPSPAWN pLastTarget = 0;
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
	if (!pLine)
		return;
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
		PMAPSPAWN pMapSpawn = new MAPSPAWN;
		pMapSpawn->SpawnType = NONE;
		pMapSpawn->pVector = 0;
		pMapSpawn->Highlight = 0;
		pMapSpawn->Explicit = 0;
		pMapSpawn->Marker = 0;
		pMapSpawn->MarkerSize = 0;
		pMapSpawn->pSpawn = 0;
		pMapSpawn->pMapLabel = 0;
		pMapSpawn->pLast = 0;
		pMapSpawn->pNext = pActiveSpawns;
		if (pActiveSpawns)
			pActiveSpawns->pLast = pMapSpawn;
		pActiveSpawns = pMapSpawn;
		return pMapSpawn;
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
		pCampRadius[i] = 0;
		pPullRadius[i] = 0;
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

	if (IsOptionEnabled(MAPFILTER_Ground))
	{
		PGROUNDITEM pItem = *(PGROUNDITEM*)pItemList;
		while (pItem)
		{
			AddGroundItem(pItem);
			pItem = pItem->pNext;
		}
	}

	for (PMAPLOC mapLoc : maplocOrder)
	{
		AddMapSpawnForMapLoc(mapLoc);
	}
}

void MapClear()
{
	GroundItemMap.clear();
	SpawnMap.clear();

	while (pActiveSpawns)
	{
		PMAPSPAWN pNextActive = 0;
		if(pActiveSpawns->pNext)
			pNextActive = pActiveSpawns->pNext;

		PMAPLABEL pLabel = 0;
		if(pActiveSpawns->pMapLabel)
			pLabel = pActiveSpawns->pMapLabel;
		if(pLabel && pLabel->Label)
			DebugTry(free(pLabel->Label));
		if(pLabel)
			DeleteLabel(pLabel);

		if (pActiveSpawns && pActiveSpawns->pVector)
		{
			DeleteLine(pActiveSpawns->pVector);
			pActiveSpawns->pVector = 0;
		}

		if (pActiveSpawns && pActiveSpawns->Marker)
			RemoveMarker(pActiveSpawns);
		if (pActiveSpawns && pActiveSpawns->pSpawn) {
			if (!IsBadReadPtr(pActiveSpawns->pSpawn, 4)) {
				if (pActiveSpawns->pSpawn->Type == FAKESPAWNTYPE) { // fake!

					delete pActiveSpawns->pSpawn;
				}
			}
			else {
				Sleep(0);//need to figure out why this can happen... -eqmule
			}
		}
		if (pActiveSpawns)
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
	if (pCampRadius[0]) {
		for (unsigned long i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
		{
			DeleteLine(pCampRadius[i]);
			pCampRadius[i] = 0;
		}
	}
	if (pPullRadius[0]) {
		for (unsigned long i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
		{
			DeleteLine(pPullRadius[i]);
			pPullRadius[i] = 0;
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
			if (Type != pMapSpawn->SpawnType || ((pMapSpawn == pOldLastTarget) && bTargetChanged) || needAnon)
			{
				if (!pMapSpawn->Explicit && !CanDisplaySpawn(Type, pMapSpawn->pSpawn))
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
	if (needAnon) needAnon = false;
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

	if (IsOptionEnabled(MAPFILTER_CampRadius))
	{
		unsigned long Angle = 0;
		for (unsigned long i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++, Angle += CASTRADIUS_ANGLESIZE)
		{
			if (!pCampRadius[i])
			{
				pCampRadius[i] = InitLine();
				pCampRadius[i]->Layer = activeLayer;
			}

			pCampRadius[i]->Color.ARGB = MapFilterOptions[MAPFILTER_CampRadius].Color;
			pCampRadius[i]->Start.Z = pCharInfo->pSpawn->Z;//the Z Locations are always my character current Z location because I want it to show up regardless of where I am on the map.
			pCampRadius[i]->End.Z = pCharInfo->pSpawn->Z;
			pCampRadius[i]->Start.X = -CampX + (FLOAT)MapFilterOptions[MAPFILTER_CampRadius].Enabled * cosf((FLOAT)Angle / 180.0f * (FLOAT)PI);
			pCampRadius[i]->Start.Y = -CampY + (FLOAT)MapFilterOptions[MAPFILTER_CampRadius].Enabled * sinf((FLOAT)Angle / 180.0f * (FLOAT)PI);;
			pCampRadius[i]->End.X = -CampX + (FLOAT)MapFilterOptions[MAPFILTER_CampRadius].Enabled * cosf((FLOAT)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f * (FLOAT)PI);
			pCampRadius[i]->End.Y = -CampY + (FLOAT)MapFilterOptions[MAPFILTER_CampRadius].Enabled * sinf((FLOAT)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f * (FLOAT)PI);
		}
	}
	else if (pCampRadius[0])
	{
		for (unsigned long i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++) {
			DeleteLine(pCampRadius[i]);
			pCampRadius[i] = 0;
		}
	}

	if (IsOptionEnabled(MAPFILTER_PullRadius))
	{
		unsigned long Angle = 0;
		for (unsigned long i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++, Angle += CASTRADIUS_ANGLESIZE)
		{
			if (!pPullRadius[i])
			{
				pPullRadius[i] = InitLine();
				pPullRadius[i]->Layer = activeLayer;
			}

			pPullRadius[i]->Color.ARGB = MapFilterOptions[MAPFILTER_PullRadius].Color;
			pPullRadius[i]->Start.Z = pCharInfo->pSpawn->Z;//the Z Locations are always my character current Z location because I want it to show up regardless of where I am on the map.
			pPullRadius[i]->End.Z = pCharInfo->pSpawn->Z;
			pPullRadius[i]->Start.X = -PullX + (FLOAT)MapFilterOptions[MAPFILTER_PullRadius].Enabled * cosf((FLOAT)Angle / 180.0f * (FLOAT)PI);
			pPullRadius[i]->Start.Y = -PullY + (FLOAT)MapFilterOptions[MAPFILTER_PullRadius].Enabled * sinf((FLOAT)Angle / 180.0f * (FLOAT)PI);;
			pPullRadius[i]->End.X = -PullX + (FLOAT)MapFilterOptions[MAPFILTER_PullRadius].Enabled * cosf((FLOAT)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f * (FLOAT)PI);
			pPullRadius[i]->End.Y = -PullY + (FLOAT)MapFilterOptions[MAPFILTER_PullRadius].Enabled * sinf((FLOAT)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f * (FLOAT)PI);
		}
	}
	else if (pPullRadius[0])
	{
		for (unsigned long i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++) {
			DeleteLine(pPullRadius[0]);
			pPullRadius[i] = 0;
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
		for (unsigned long i = 1; i < 6; i++)
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
	if (!pMapSpawn || !pMapSpawn->pSpawn)
		return true;
	
	if (!pMapSpawn->pSpawn->vtable)
	{
		return true;
	}
	else if (pMapSpawn->SpawnType == ITEM)
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

void MapClickLocation(float world_point[2], std::vector<float> z_hits) {
    PCHARINFO pCharInfo = GetCharInfo();
    std::vector<float> sorted_z(z_hits);
    std::sort(sorted_z.begin(), sorted_z.end());

    float point_z = (pCharInfo && pCharInfo->pSpawn) ? pCharInfo->pSpawn->Z : 0.f;
    auto closest_z_it = std::lower_bound(sorted_z.begin(), sorted_z.end(), point_z);
    if (closest_z_it == sorted_z.end() && closest_z_it != sorted_z.begin()) {
        --closest_z_it;
    } else if (closest_z_it != sorted_z.end() && closest_z_it != sorted_z.begin() &&
        (std::abs(*closest_z_it - point_z) > std::abs(*(closest_z_it - 1) - point_z))) {
        --closest_z_it;
    }

    DWORD Flags = pWndMgr->GetKeyboardFlags();
    if (pCharInfo && Flags && MapLeftClickString[Flags][0]) {
        CHAR CommandString[MAX_STRING];
        strcpy_s(CommandString, MapLeftClickString[Flags]);
        std::string sOutput;

        for (unsigned short N = 0; CommandString[N]; ++N) {
            if (CommandString[N] == '%') {
                ++N;
                switch (CommandString[N]) {
                case 'x':
                    sOutput.append(std::to_string(world_point[1]));
                    break;
                case 'y':
                    sOutput.append(std::to_string(world_point[0]));
                    break;
                case 'z': // closest z
                    if (closest_z_it != sorted_z.end())
                        sOutput.append(std::to_string(*closest_z_it));
                    else
                        sOutput.append(std::to_string(point_z));
                    break;
                case 'u': // up one z
                    if (closest_z_it != sorted_z.end()) {
                        if (closest_z_it + 1 != sorted_z.end())
                            sOutput.append(std::to_string(*(closest_z_it + 1)));
                        else
                            sOutput.append(std::to_string(*closest_z_it));
                    } else
                        sOutput.append(std::to_string(point_z));
                    break;
                case 'd': // down one z
                    if (closest_z_it != sorted_z.begin())
                        sOutput.append(std::to_string(*(closest_z_it - 1)));
                    else if (closest_z_it != sorted_z.end())
                        sOutput.append(std::to_string(*closest_z_it));
                    else
                        sOutput.append(std::to_string(point_z));
                    break;
                case 't': // top z
                    if (!sorted_z.empty())
                        sOutput.append(std::to_string(sorted_z.back()));
                    else
                        sOutput.append(std::to_string(point_z));
                    break;
                case 'b': // bottom z
                    if (!sorted_z.empty())
                        sOutput.append(std::to_string(sorted_z.front()));
                    else
                        sOutput.append(std::to_string(point_z));
                    break;
                case '%':
                    sOutput.append(1, CommandString[N]);
                    break;
                }
            } else
                sOutput.append(1, CommandString[N]);
        }

        strcpy_s(CommandString, sOutput.c_str());

#ifndef ISXEQ
        DoCommand(pCharInfo->pSpawn, CommandString);
#else
        pISInterface->ExecuteCommand(CommandString);
#endif
#if 0
        // debugging
        WriteChatf("COMMAND: %s", sOutput.c_str());
#endif
    }

#if 0
    // debugging
    for (auto z : z_hits) {
        WriteChatf("Z HIT: %f", z);
    }
    WriteChatf("I CLICKED: X: %f Y: %f", world_point[1], world_point[0]);
#endif
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
		if (!gAnonymize) {
			if (NameString[N] == '%')
			{
				N++;
				switch (NameString[N])
				{
				case 'N':// cleaned up name
					sOutput.append(pSpawn->DisplayedName);
					if (pSpawn->Type == SPAWN_CORPSE)
					{
						sOutput.append("'s Corpse");
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
					sOutput.append(1, NameString[N]);
					break;
				}
			}
			else
				sOutput.append(1, NameString[N]);
		}
		else {
			if (NameString[N] == '%')
			{
				N++;
				switch (NameString[N])
				{
				case 'N':// cleaned up name
					switch (pSpawn->Type) {
					case SPAWN_CORPSE:
						if (pSpawn->Deity) {
							AddString(GetClassDesc(pSpawn->GetClass()));
						}
						else {
							AddString(pSpawn->DisplayedName);
						}
						break;
					case SPAWN_NPC:
						if (pSpawn->MasterID || pSpawn->Rider) {
							bool isPlayers = false;
							if (PSPAWNINFO petOwner = (PSPAWNINFO)GetSpawnByID(pSpawn->MasterID)) {
								if (petOwner->Type == SPAWN_PLAYER || petOwner->Type == SPAWN_CORPSE) {
									isPlayers = true;
								}
							}
							if (pSpawn->Rider)
								if (PSPAWNINFO rider = (PSPAWNINFO)GetSpawnByID(pSpawn->Rider->SpawnID)) {
									if (rider->Type == SPAWN_PLAYER)
										isPlayers = true;
								}
							if (isPlayers) {
								AddString(GetClassDesc(pSpawn->GetClass()));
							}
							else {
								AddString(pSpawn->DisplayedName);
							}
						}
						else {
							AddString(pSpawn->DisplayedName);
						}
						break;
					case SPAWN_PLAYER:
						AddString(GetClassDesc(pSpawn->GetClass()));
					default:
						break;
					}
					if (pSpawn->Type == SPAWN_CORPSE)
					{
						AddString("'s Corpse");
					}
					break;
				case 'n':// original name
					switch (pSpawn->Type) {
					case SPAWN_CORPSE:
						if (pSpawn->Deity) {
							AddString(GetClassDesc(pSpawn->GetClass()));
						}
						else {
							AddString(pSpawn->DisplayedName);
						}
						break;
					case SPAWN_NPC:
					
						if (pSpawn->MasterID || pSpawn->Rider) {
							bool isPlayers = false;
							if (PSPAWNINFO petOwner = (PSPAWNINFO)GetSpawnByID(pSpawn->MasterID)) {
								if (petOwner->Type == SPAWN_PLAYER || petOwner->Type == SPAWN_CORPSE) {
									isPlayers = true;
								}
							}
							if (pSpawn->Rider)
								if (PSPAWNINFO rider = (PSPAWNINFO)GetSpawnByID(pSpawn->Rider->SpawnID)) {
									if (rider->Type == SPAWN_PLAYER)
										isPlayers = true;
								}
							if (isPlayers) {
								AddString(GetClassDesc(pSpawn->GetClass()));
							} 
							else {
								AddString(pSpawn->DisplayedName);
							}
						}
						else {
							AddString(pSpawn->DisplayedName);
						}
						break;
					
					case SPAWN_PLAYER:
						AddString(GetClassDesc(pSpawn->GetClass()));
					default:
						break;
					}
					if (pSpawn->Type == SPAWN_CORPSE)
					{
						AddString("'s Corpse");
					}
					break;
				case 'h':// current health %
					AddInt(pSpawn->HPCurrent);
					break;
				case 'i':
					//AddInt(pSpawn->SpawnID);Don't Display SpawnID if we are Anon
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
					if (pSpawn->Type == SPAWN_NPC)//Only display the class if it's an NPC, otherwise we'll display it twice for corpses and players. 
						AddString(GetClassDesc(pSpawn->mActorClient.Class));
					break;
				case 'c':
					if (pSpawn->Type == SPAWN_NPC)//Only display the 3 letter race if it's an NPC, we're already displaying the full race name otherwise. 
						AddString(pEverQuest->GetClassThreeLetterCode(pSpawn->mActorClient.Class));
					break;
				case 'l':
					AddInt(pSpawn->Level);
					break;
				case '%':
					sOutput.append(1, NameString[N]);
					break;
				}
			}
			else
				sOutput.append(1, NameString[N]);
		}
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
	DefaultMapLoc->radius = 0;
	DefaultMapLoc->rr_color = 0;
	DefaultMapLoc->rg_color = 0;
	DefaultMapLoc->rb_color = 255;
#else
	DefaultMapLoc->lineSize = GetPrivateProfileInt("MapLoc", "Size", 50, INIFileName);
	DefaultMapLoc->width = GetPrivateProfileInt("MapLoc", "Width", 10, INIFileName);
	DefaultMapLoc->r_color = GetPrivateProfileInt("MapLoc", "Red", 255, INIFileName);
	DefaultMapLoc->g_color = GetPrivateProfileInt("MapLoc", "Green", 0, INIFileName);
	DefaultMapLoc->b_color = GetPrivateProfileInt("MapLoc", "Blue", 0, INIFileName);
	DefaultMapLoc->radius = GetPrivateProfileInt("MapLoc", "Radius", 0, INIFileName);
	DefaultMapLoc->rr_color = GetPrivateProfileInt("MapLoc", "RadiusRed", 0, INIFileName);
	DefaultMapLoc->rg_color = GetPrivateProfileInt("MapLoc", "RadiusGreen", 0, INIFileName);
	DefaultMapLoc->rb_color = GetPrivateProfileInt("MapLoc", "RadiusBlue", 255, INIFileName);
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
			loc->radius = DefaultMapLoc->radius;
			loc->rr_color = DefaultMapLoc->rr_color;
			loc->rg_color = DefaultMapLoc->rg_color;
			loc->rb_color = DefaultMapLoc->rb_color;
			UpdateMapLoc(loc);
		}
	}
}

VOID PrintDefaultMapLocSettings()
{
#ifdef ISXEQ
	DefaultMapLoc->lineSize = 50;
	DefaultMapLoc->width = 10;
	DefaultMapLoc->r_color = 255;
	DefaultMapLoc->g_color = 0;
	DefaultMapLoc->b_color = 0;
	DefaultMapLoc->radius = 0;
	DefaultMapLoc->rr_color = 0;
	DefaultMapLoc->rg_color = 0;
	DefaultMapLoc->rb_color = 255;
#else
	DefaultMapLoc->lineSize = GetPrivateProfileInt("MapLoc", "Size", 50, INIFileName);
	DefaultMapLoc->width = GetPrivateProfileInt("MapLoc", "Width", 10, INIFileName);
	DefaultMapLoc->r_color = GetPrivateProfileInt("MapLoc", "Red", 255, INIFileName);
	DefaultMapLoc->g_color = GetPrivateProfileInt("MapLoc", "Green", 0, INIFileName);
	DefaultMapLoc->b_color = GetPrivateProfileInt("MapLoc", "Blue", 0, INIFileName);
	DefaultMapLoc->radius = GetPrivateProfileInt("MapLoc", "Radius", 0, INIFileName);
	DefaultMapLoc->rr_color = GetPrivateProfileInt("MapLoc", "RadiusRed", 0, INIFileName);
	DefaultMapLoc->rg_color = GetPrivateProfileInt("MapLoc", "RadiusGreen", 0, INIFileName);
	DefaultMapLoc->rb_color = GetPrivateProfileInt("MapLoc", "RadiusBlue", 255, INIFileName);
#endif

	stringstream MapLocVars;
	MapLocVars << "MapLoc Defaults: ";

	MapLocVars << "Width:" << DefaultMapLoc->width
		<< ", Size:" << DefaultMapLoc->lineSize
		<< ", Color:" << DefaultMapLoc->r_color << "," << DefaultMapLoc->g_color << "," << DefaultMapLoc->b_color
		<< ", Radius:" << DefaultMapLoc->radius
		<< ", Radius Color:" << DefaultMapLoc->rr_color << "," << DefaultMapLoc->rg_color << "," << DefaultMapLoc->rb_color;

	CHAR szBuffer[MAX_STRING] = { 0 };
	sprintf_s(szBuffer, MapLocVars.str().c_str());
	WriteChatColor(szBuffer, USERCOLOR_DEFAULT);
}

VOID MapLocSyntaxOutput()
{
	SyntaxError("Usage: /maploc [[size 10-200] | [width 1-10] | [color r g b] | [radius <distance>] | [rcolor r g b] | [yloc xloc (zloc) | target]] | [label text]");
	SyntaxError(" -- Omit locs to set defaults");
	SyntaxError(" -- Add label to loc by putting 'label <my text here>' only at end of command");
	SyntaxError("Remove maplocs: /maploc remove [index | [yloc xloc (zloc)]]");
	PrintDefaultMapLocSettings();
}

VOID MapRemoveLocation(PSPAWNINFO pChar, PCHAR szLine)
{
	CHAR arg[MAX_STRING];
	stringstream ss(szLine);
	ss >> arg; // remove reparsed initial clear

	if (!ss || ss.eof())
	{
		map<string, PMAPLOC>::iterator it = LocationMap.begin();
		while (it != LocationMap.end())
		{
			PMAPLOC loc = it->second;
			maplocOrder.remove(loc);
			DeleteMapLoc(loc);
			delete loc;
			it = LocationMap.erase(it);
		}

		LocationMap.clear();
		WriteChatColor("MapLocs removed", USERCOLOR_DEFAULT);
		return;
	}

	CHAR szBuffer[MAX_STRING] = { 0 };
	CHAR yloc[MAX_STRING] = { "not set" };
	CHAR xloc[MAX_STRING] = { "not set" };
	CHAR zloc[MAX_STRING] = { "0" };
	CHAR tag[MAX_STRING] = { 0 };

	ss >> arg;

	if (!is_float(std::string(arg))) {
		MapLocSyntaxOutput();
		return;
	}
	strcpy_s(yloc, arg);
	if (ss && !ss.eof())
	{
		ss >> arg;
		if (!is_float(std::string(arg))) {
			MapLocSyntaxOutput();
			return;
		}
		strcpy_s(xloc, arg);

		if (ss && !ss.eof())
		{
			ss >> arg;
			if (!is_float(std::string(arg))) {
				MapLocSyntaxOutput();
				return;
			}
			strcpy_s(zloc, arg);
		}

		// deal only in full int locs, makes it easier to do things like clear locs later
		std::string delim = ".";
		std::string temp(yloc);
		temp.erase(std::remove(temp.begin(), temp.end(), '+'), temp.end());
		strcpy_s(yloc, temp.substr(0, temp.find(delim)).c_str());
		temp = xloc;
		temp.erase(std::remove(temp.begin(), temp.end(), '+'), temp.end());
		strcpy_s(xloc, temp.substr(0, temp.find(delim)).c_str());
		temp = zloc;
		temp.erase(std::remove(temp.begin(), temp.end(), '+'), temp.end());
		strcpy_s(zloc, temp.substr(0, temp.find(delim)).c_str());
	}
	else // remove by index
	{
		int index = static_cast<int>(stof(yloc));
		if (index < (int)maplocOrder.size() + 1)
		{
			PMAPLOC mapLocToRemove;
			std::list<PMAPLOC>::iterator it = maplocOrder.begin();
			std::advance(it, index - 1);
			mapLocToRemove = *it;
			strcpy_s(yloc, std::to_string(mapLocToRemove->yloc).c_str());
			strcpy_s(xloc, std::to_string(mapLocToRemove->xloc).c_str());
			strcpy_s(zloc, std::to_string(mapLocToRemove->zloc).c_str());
		}
		else
		{
			CHAR output[MAX_STRING] = { 0 };
			sprintf_s(output, "Remove loc by index out of bounds: %s", yloc);
			WriteChatColor(output, CONCOLOR_RED);
			return;
		}
	}

	sprintf_s(tag, "%s,%s,%s", yloc, xloc, zloc);

	PMAPLOC loc = LocationMap[tag];
	if (!loc) {
		SyntaxError("Could not find MapLoc: %s", tag);
		return;
	}

	string index = std::to_string(loc->index);
	
	// Delete the loc
	maplocOrder.remove(loc);
	DeleteMapLoc(loc);
	delete loc;
	LocationMap.erase(tag);
	
	// Update index labels for remaining locs
	UpdateMapLocIndexes();
	//list<PMAPLOC>::iterator it = maplocOrder.begin();
	for (list<PMAPLOC>::iterator it = maplocOrder.begin();it!=maplocOrder.end();it++)
	{
	//for (int i = 1; i <= (int)maplocOrder.size(); i++)
		PMAPLOC locToUpdate = *it;
		if (locToUpdate->mapSpawn)
		{
			RemoveSpawn(locToUpdate->mapSpawn);
		}
		AddMapSpawnForMapLoc(locToUpdate);
		//std::advance(it, 1);
	}

	CHAR output[MAX_STRING] = { 0 };
	sprintf_s(output, "MapLoc removed: Index:%s, loc:%s", index.c_str(), tag);
	WriteChatColor(output, USERCOLOR_DEFAULT);
}

VOID DeleteMapLoc(PMAPLOC mapLoc)
{
	if (mapLoc)
	{
		for (int i = 0; i < 150; i++)
		{
			if (mapLoc->markerLines[i])
			{
				DeleteLine(mapLoc->markerLines[i]);
				mapLoc->markerLines[i] = NULL;
			}
		}

		if (mapLoc->mapSpawn)
		{
			RemoveSpawn(mapLoc->mapSpawn);
		}
	}
}

VOID UpdateMapLoc(PMAPLOC mapLoc)
{
	if (!mapLoc)
	{
		return;
	}

	DeleteMapLoc(mapLoc);

	int lineIndex = 0;

	// Create the X
	for (int xWidth = 1; xWidth <= mapLoc->width; xWidth++) {
		if (xWidth == 1)
		{
			//Backslash
			mapLoc->markerLines[lineIndex] = InitLine();
			mapLoc->markerLines[lineIndex]->Start.X = (FLOAT)-mapLoc->xloc - mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->Start.Y = (FLOAT)-mapLoc->yloc - mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->Start.Z = (FLOAT)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->End.X = (FLOAT)-mapLoc->xloc + mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->End.Y = (FLOAT)-mapLoc->yloc + mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->End.Z = (FLOAT)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->Layer = activeLayer;
			ARGBCOLOR bsColor;
			bsColor.ARGB = 0xFF000000 | (mapLoc->r_color << 16) | (mapLoc->g_color << 8) | (mapLoc->b_color);
			mapLoc->markerLines[lineIndex++]->Color = bsColor;

			//Forwardslash
			mapLoc->markerLines[lineIndex] = InitLine();
			mapLoc->markerLines[lineIndex]->Start.X = (FLOAT)-mapLoc->xloc - mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->Start.Y = (FLOAT)-mapLoc->yloc + mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->Start.Z = (FLOAT)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->End.X = (FLOAT)-mapLoc->xloc + mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->End.Y = (FLOAT)-mapLoc->yloc - mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->End.Z = (FLOAT)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->Layer = activeLayer;
			ARGBCOLOR fsColor;
			fsColor.ARGB = 0xFF000000 | (mapLoc->r_color << 16) | (mapLoc->g_color << 8) | (mapLoc->b_color);
			mapLoc->markerLines[lineIndex++]->Color = fsColor;
		}
		else
		{
			//Backslash lower
			mapLoc->markerLines[lineIndex] = InitLine();
			mapLoc->markerLines[lineIndex]->Start.X = (FLOAT)-mapLoc->xloc - mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->Start.Y = (FLOAT)-mapLoc->yloc - mapLoc->lineSize + xWidth - 1;
			mapLoc->markerLines[lineIndex]->Start.Z = (FLOAT)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->End.X = (FLOAT)-mapLoc->xloc + mapLoc->lineSize - xWidth + 1;
			mapLoc->markerLines[lineIndex]->End.Y = (FLOAT)-mapLoc->yloc + mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->End.Z = (FLOAT)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->Layer = activeLayer;
			ARGBCOLOR bslColor;
			bslColor.ARGB = 0xFF000000 | (mapLoc->r_color << 16) | (mapLoc->g_color << 8) | (mapLoc->b_color);
			mapLoc->markerLines[lineIndex++]->Color = bslColor;

			//Forwardslash lower
			mapLoc->markerLines[lineIndex] = InitLine();
			mapLoc->markerLines[lineIndex]->Start.X = (FLOAT)-mapLoc->xloc - mapLoc->lineSize + xWidth - 1;
			mapLoc->markerLines[lineIndex]->Start.Y = (FLOAT)-mapLoc->yloc + mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->Start.Z = (FLOAT)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->End.X = (FLOAT)-mapLoc->xloc + mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->End.Y = (FLOAT)-mapLoc->yloc - mapLoc->lineSize + xWidth - 1;
			mapLoc->markerLines[lineIndex]->End.Z = (FLOAT)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->Layer = activeLayer;
			ARGBCOLOR fslColor;
			fslColor.ARGB = 0xFF000000 | (mapLoc->r_color << 16) | (mapLoc->g_color << 8) | (mapLoc->b_color);
			mapLoc->markerLines[lineIndex++]->Color = fslColor;

			//Backslash upper
			mapLoc->markerLines[lineIndex] = InitLine();
			mapLoc->markerLines[lineIndex]->Start.X = (FLOAT)-mapLoc->xloc - mapLoc->lineSize + xWidth - 1;
			mapLoc->markerLines[lineIndex]->Start.Y = (FLOAT)-mapLoc->yloc - mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->Start.Z = (FLOAT)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->End.X = (FLOAT)-mapLoc->xloc + mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->End.Y = (FLOAT)-mapLoc->yloc + mapLoc->lineSize - xWidth + 1;
			mapLoc->markerLines[lineIndex]->End.Z = (FLOAT)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->Layer = activeLayer;
			ARGBCOLOR bsuColor;
			bsuColor.ARGB = 0xFF000000 | (mapLoc->r_color << 16) | (mapLoc->g_color << 8) | (mapLoc->b_color);
			mapLoc->markerLines[lineIndex++]->Color = bsuColor;

			//Forwardslash upper
			mapLoc->markerLines[lineIndex] = InitLine();
			mapLoc->markerLines[lineIndex]->Start.X = (FLOAT)-mapLoc->xloc - mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->Start.Y = (FLOAT)-mapLoc->yloc + mapLoc->lineSize - xWidth + 1;
			mapLoc->markerLines[lineIndex]->Start.Z = (FLOAT)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->End.X = (FLOAT)-mapLoc->xloc + mapLoc->lineSize - xWidth + 1;
			mapLoc->markerLines[lineIndex]->End.Y = (FLOAT)-mapLoc->yloc - mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->End.Z = (FLOAT)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->Layer = activeLayer;
			ARGBCOLOR fsuColor;
			fsuColor.ARGB = 0xFF000000 | (mapLoc->r_color << 16) | (mapLoc->g_color << 8) | (mapLoc->b_color);
			mapLoc->markerLines[lineIndex++]->Color = fsuColor;
		}
	}

	// Create the Radius
	if (mapLoc->radius > 0)
	{
		unsigned long Angle = 0;
		for (unsigned long i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++, Angle += CASTRADIUS_ANGLESIZE)
		{
			mapLoc->markerLines[lineIndex] = InitLine();
			mapLoc->markerLines[lineIndex]->Start.X = -mapLoc->xloc + (FLOAT)mapLoc->radius*cosf((FLOAT)Angle / 180.0f*(FLOAT)PI);
			mapLoc->markerLines[lineIndex]->Start.Y = -mapLoc->yloc + (FLOAT)mapLoc->radius*sinf((FLOAT)Angle / 180.0f*(FLOAT)PI);
			mapLoc->markerLines[lineIndex]->Start.Z = (FLOAT)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->End.X = -mapLoc->xloc + (FLOAT)mapLoc->radius*cosf((FLOAT)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f*(FLOAT)PI);
			mapLoc->markerLines[lineIndex]->End.Y = -mapLoc->yloc + (FLOAT)mapLoc->radius*sinf((FLOAT)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f*(FLOAT)PI);
			mapLoc->markerLines[lineIndex]->End.Z = (FLOAT)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->Layer = activeLayer;
			ARGBCOLOR rColor;
			rColor.ARGB = 0xFF000000 | (mapLoc->rr_color << 16) | (mapLoc->rg_color << 8) | (mapLoc->rb_color);
			mapLoc->markerLines[lineIndex++]->Color = rColor;
		}
	}

	AddMapSpawnForMapLoc(mapLoc);
}

VOID AddMapSpawnForMapLoc(PMAPLOC mapLoc)
{
	// Set the index label
	string labelStr = std::to_string(mapLoc->index);
	if (mapLoc->label.length() > 0)
	{
		labelStr.append(mapLoc->label);
	}

	// Create unique "spawnid"
	unsigned long mapId = 300000;
	std::map<unsigned long, PMAPSPAWN>::iterator it;
	do
	{
		mapId++;
		it = SpawnMap.find(mapId);
	} while (it != SpawnMap.end() && mapId < 304000);

	// Build the SpawnInfo
	PSPAWNINFO pFakeSpawn = new SPAWNINFO;
	memset(pFakeSpawn, 0, sizeof(SPAWNINFO));
	strcpy_s(pFakeSpawn->DisplayedName, labelStr.c_str());
	pFakeSpawn->X = (FLOAT)mapLoc->xloc;
	pFakeSpawn->Y = (FLOAT)mapLoc->yloc;
	pFakeSpawn->Z = (FLOAT)mapLoc->zloc;
	pFakeSpawn->HPCurrent = 1;
	pFakeSpawn->HPMax = 1;
	pFakeSpawn->Heading = 0;
	pFakeSpawn->mActorClient.Race = 0;
	pFakeSpawn->SpawnID = mapId;

	// Build pMapSpawn and add to SpawnMaps
	PMAPSPAWN pMapSpawn = InitSpawn();
	pMapSpawn->SpawnType = UNTARGETABLE;
	pMapSpawn->pSpawn = pFakeSpawn;
	pMapSpawn->pMapLabel = GenerateLabel(pMapSpawn, CONCOLOR_BLACK);
	pMapSpawn->Explicit = true; // These are a unique "spawn type" but we don't have a way to make a new entry in the enum, so force show just like a /mapshow on a filtered object
	pMapSpawn->pVector = 0;
	pMapSpawn->Highlight = false;
	if (pMapSpawn->Marker != 0)
		pMapSpawn->Marker = 0;
	SpawnMap[pFakeSpawn->SpawnID] = pMapSpawn;
	mapLoc->mapSpawn = pMapSpawn;
}

VOID UpdateMapLocIndexes()
{
	list<PMAPLOC>::iterator it = maplocOrder.begin();
	for (int i = 1; i <= (int)maplocOrder.size(); i++)
	{
		PMAPLOC loc = *it;
		loc->index = i;
		std::advance(it, 1);
	}
}

bool is_float(const string &in)
{
	std::stringstream sstr(in);
	float f;
	return !((sstr >> noskipws >> f).rdstate() ^ ios_base::eofbit);
}

std::tuple<float, float, float> getTargetLoc()
{
	return std::make_tuple(pLastTarget->pSpawn->X, pLastTarget->pSpawn->Y, pLastTarget->pSpawn->Z);
}

VOID AddMapLocToList(PMAPLOC loc)
{
	bool found = (std::find(maplocOrder.begin(), maplocOrder.end(), loc) != maplocOrder.end());
	if (!found)
	{
		maplocOrder.push_back(loc);
	}
}