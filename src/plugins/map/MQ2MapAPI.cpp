/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "MQ2Map.h"

#include <mq/Plugin.h>

#include <fmt/format.h>
#include <sstream>

#define FAKESPAWNTYPE 0xFF

MAPSPAWN* pActiveSpawns = nullptr;
MAPLABEL* pLabelList = nullptr;
MAPLABEL* pLabelListTail = nullptr;
MAPLINE*  pLineList = nullptr;
MAPLINE*  pLineListTail = nullptr;

MAPLABEL* pActualLineList = nullptr;

std::map<unsigned long, MAPSPAWN*> SpawnMap;
std::map<unsigned long, MAPSPAWN*> GroundItemMap;
std::map<MAPLABEL*, MAPSPAWN*> LabelMap;
std::map<std::string, MAPLOC*> LocationMap;
std::list<MAPLOC*> maplocOrder;
MAPLOC* DefaultMapLoc = new MAPLOC;

BOOL Update = false;

const int CASTRADIUS_ANGLESIZE = 10;

MAPLINE* pCastRadius[(360 / CASTRADIUS_ANGLESIZE) + 1];
MAPLINE* pSpellRadius[(360 / CASTRADIUS_ANGLESIZE) + 1];
MAPSPAWN* pLastTarget = nullptr;
MAPLINE* pTargetRadius[(360 / CASTRADIUS_ANGLESIZE) + 1];
MAPLINE* pTargetMelee[(360 / CASTRADIUS_ANGLESIZE) + 1];
MAPLINE* pTargetLine = nullptr;
MAPLINE* pCampRadius[(360 / CASTRADIUS_ANGLESIZE) + 1];
MAPLINE* pPullRadius[(360 / CASTRADIUS_ANGLESIZE) + 1];

MAPLINE* InitLine()
{
	MAPLINE* pLine = new MAPLINE;
	pLine->pPrev = nullptr;
	pLine->pNext = pLineList;

	if (pLineList)
		pLineList->pPrev = pLine;
	else
		pLineListTail = pLine;

	pLineList = pLine;
	return pLine;
}

void DeleteLine(MAPLINE* pLine)
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

MAPLABEL* InitLabel(MAPSPAWN* pMapSpawn)
{
	MAPLABEL* pLabel = new MAPLABEL;
	pLabel->pPrev = nullptr;
	pLabel->pNext = pLabelList;

	if (pLabelList)
		pLabelList->pPrev = pLabel;
	else
		pLabelListTail = pLabel;

	pLabelList = pLabel;
	LabelMap[pLabel] = pMapSpawn;
	return pLabel;
}

void DeleteLabel(MAPLABEL* pLabel)
{
	LabelMap[pLabel] = nullptr;

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

MAPSPAWN* InitSpawn()
{
	MAPSPAWN* pMapSpawn = new MAPSPAWN;
	pMapSpawn->SpawnType = NONE;
	pMapSpawn->pVector = nullptr;
	pMapSpawn->Highlight = 0;
	pMapSpawn->Explicit = 0;
	pMapSpawn->Marker = 0;
	pMapSpawn->MarkerSize = 0;
	pMapSpawn->pSpawn = nullptr;
	pMapSpawn->pMapLabel = nullptr;
	pMapSpawn->pLast = nullptr;
	pMapSpawn->pNext = pActiveSpawns;

	if (pActiveSpawns)
		pActiveSpawns->pLast = pMapSpawn;

	pActiveSpawns = pMapSpawn;
	return pMapSpawn;
}

inline void DeleteSpawn(MAPSPAWN* pMapSpawn)
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

void GenerateMarker(MAPSPAWN* pMapSpawn);
char* GenerateSpawnName(SPAWNINFO* pSpawn, char* NameString);
DWORD GetSpawnColor(eSpawnType Type, SPAWNINFO* pSpawn);
MAPLABEL* GenerateLabel(MAPSPAWN* pMapSpawn, DWORD Color);
PMAPLINE GenerateVector(MAPSPAWN* pMapSpawn);
BOOL CanDisplaySpawn(eSpawnType Type, SPAWNINFO* pSpawn);
void RemoveMarker(MAPSPAWN* pMapSpawn);
void MoveMarker(MAPSPAWN* pMapSpawn);

void MapInit()
{
	for (int i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
	{
		pCastRadius[i] = nullptr;
		pSpellRadius[i] = nullptr;
		pTargetRadius[i] = nullptr;
		pTargetMelee[i] = nullptr;
		pCampRadius[i] = nullptr;
		pPullRadius[i] = nullptr;
	}
}

MAPSPAWN* AddSpawn(SPAWNINFO* pNewSpawn, BOOL ExplicitAllow)
{
	char szBuffer[MAX_STRING] = { 0 };
	char buf[MAX_STRING] = { 0 };
	eSpawnType Type = GetSpawnType(pNewSpawn);

	// apply map filter
	if (!ExplicitAllow && !CanDisplaySpawn(Type, pNewSpawn))
		return nullptr;

	// add spawn to list

	if (MAPSPAWN* pMapSpawn = InitSpawn())
	{
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

		// new stuff for Marker changes
		if (IsOptionEnabled(MAPFILTER_Marker))
		{
			pMapSpawn->Marker = MapFilterOptions[TypeToMapfilter(pNewSpawn)].Marker;
			pMapSpawn->MarkerSize = MapFilterOptions[TypeToMapfilter(pNewSpawn)].MarkerSize;

			GenerateMarker(pMapSpawn);
			MoveMarker(pMapSpawn);
		}
		else if (!IsOptionEnabled(MAPFILTER_Marker))
		{
			if (pMapSpawn->Marker != 0)
				pMapSpawn->Marker = 0;
		}
		return pMapSpawn;
	}

	return nullptr;
}

void RemoveSpawn(MAPSPAWN* pMapSpawn)
{
	if (pMapSpawn && pMapSpawn->pMapLabel)
	{
		if (pMapSpawn->pMapLabel->Label)
			free(pMapSpawn->pMapLabel->Label);
		DeleteLabel(pMapSpawn->pMapLabel);
	}

	if (pMapSpawn && pMapSpawn->pVector)
	{
		DeleteLine(pMapSpawn->pVector);
		pMapSpawn->pVector = nullptr;
	}
	if (pMapSpawn && pMapSpawn->Marker)
	{
		RemoveMarker(pMapSpawn);
	}

	if (pMapSpawn && pMapSpawn->pSpawn && pMapSpawn->pSpawn->Type == FAKESPAWNTYPE)
	{
		delete pMapSpawn->pSpawn;
	}
	else
	{
		if (pMapSpawn && pMapSpawn->pSpawn)
		{
			SpawnMap[pMapSpawn->pSpawn->SpawnID] = nullptr;
		}
	}

	if (pMapSpawn && pMapSpawn == pLastTarget)
	{
		pLastTarget = nullptr;
	}

	if (pMapSpawn)
	{
		DeleteSpawn(pMapSpawn);
	}
}

bool RemoveSpawn(SPAWNINFO* pSpawn)
{
	if (pSpawn)
	{
		if (SpawnMap.find(pSpawn->SpawnID) != SpawnMap.end())
		{
			MAPSPAWN* pMapSpawn = SpawnMap[pSpawn->SpawnID];
			RemoveSpawn(pMapSpawn);
			return true;
		}
	}
	return false;
}

void AddGroundItem(PGROUNDITEM pGroundItem)
{
	SPAWNINFO* pFakeSpawn = new SPAWNINFO;
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
	MAPSPAWN* pMapSpawn = AddSpawn(pFakeSpawn);
	if (pMapSpawn)
		GroundItemMap[pGroundItem->DropID] = pMapSpawn;
	else
		delete pFakeSpawn;
}

void RemoveGroundItem(PGROUNDITEM pGroundItem)
{
	MAPSPAWN* pMapSpawn = GroundItemMap[pGroundItem->DropID];
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

	SPAWNINFO* pSpawn = (SPAWNINFO*)pSpawnList;
	while (pSpawn)
	{
		AddSpawn(pSpawn);
		pSpawn = pSpawn->pNext;
	}

	if (IsOptionEnabled(MAPFILTER_Ground))
	{
		EQGroundItem* pItem = pItemList->Top;
		while (pItem)
		{
			AddGroundItem(pItem);
			pItem = pItem->pNext;
		}
	}

	for (MAPLOC* mapLoc : maplocOrder)
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
		MAPSPAWN* pNextActive = nullptr;
		if (pActiveSpawns->pNext)
			pNextActive = pActiveSpawns->pNext;

		MAPLABEL* pLabel = nullptr;
		if (pActiveSpawns->pMapLabel)
			pLabel = pActiveSpawns->pMapLabel;

		if (pLabel && pLabel->Label)
			DebugTry(free(pLabel->Label));

		if (pLabel)
			DeleteLabel(pLabel);

		if (pActiveSpawns && pActiveSpawns->pVector)
		{
			DeleteLine(pActiveSpawns->pVector);
			pActiveSpawns->pVector = nullptr;
		}

		if (pActiveSpawns && pActiveSpawns->Marker)
			RemoveMarker(pActiveSpawns);

		if (pActiveSpawns && pActiveSpawns->pSpawn)
		{
			if (!IsBadReadPtr(pActiveSpawns->pSpawn, 4))
			{
				if (pActiveSpawns->pSpawn->Type == FAKESPAWNTYPE)
				{
					// fake!
					delete pActiveSpawns->pSpawn;
				}
			}
		}
		if (pActiveSpawns)
			DeleteSpawn(pActiveSpawns);
		pActiveSpawns = pNextActive;
	}

	pLastTarget = nullptr;

	if (pTargetLine)
	{
		DeleteLine(pTargetLine);
		pTargetLine = nullptr;
	}

	if (pCastRadius[0])
	{
		for (int i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
		{
			DeleteLine(pCastRadius[i]);
			pCastRadius[i] = nullptr;
		}
	}

	if (pSpellRadius[0])
	{
		for (int i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
		{
			DeleteLine(pSpellRadius[i]);
			pSpellRadius[i] = nullptr;
		}
	}

	if (pTargetRadius[0])
	{
		for (int i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
		{
			DeleteLine(pTargetRadius[i]);
			pTargetRadius[i] = nullptr;
		}
	}

	if (pTargetMelee[0])
	{
		for (int i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
		{
			DeleteLine(pTargetMelee[i]);
			pTargetMelee[i] = nullptr;
		}
	}

	if (pCampRadius[0])
	{
		for (int i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
		{
			DeleteLine(pCampRadius[i]);
			pCampRadius[i] = nullptr;
		}
	}

	if (pPullRadius[0])
	{
		for (int i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
		{
			DeleteLine(pPullRadius[i]);
			pPullRadius[i] = nullptr;
		}
	}
}

void MapUpdate()
{
	char buf[MAX_STRING] = { 0 };
	CHARINFO* pCharInfo = GetCharInfo();
	if (!pCharInfo)
		return;

	EnterMQ2Benchmark(bmMapRefresh);
	eSpawnType Type;
	MAPSPAWN* pMapSpawn;
	MAPSPAWN* pOldLastTarget = nullptr;
	bool bTargetChanged = false;

	pOldLastTarget = pLastTarget;
	if (pLastTarget && pLastTarget->pSpawn != (SPAWNINFO*)pTarget)
	{
		if (pLastTarget->pSpawn == &EnviroTarget || !CanDisplaySpawn(pLastTarget->SpawnType, pLastTarget->pSpawn))
		{
			RemoveSpawn(pLastTarget);
		}
		pLastTarget = nullptr;
		bTargetChanged = true;
	}

	if (pTarget && IsOptionEnabled(MAPFILTER_Target))
	{
		pLastTarget = SpawnMap[((SPAWNINFO*)pTarget)->SpawnID];
		if (!pLastTarget)
		{
			pLastTarget = AddSpawn((SPAWNINFO*)pTarget);
		}
	}

	pMapSpawn = pActiveSpawns;

	while (pMapSpawn)
	{
		if (!pMapSpawn->Explicit && !CanDisplaySpawn(GetSpawnType(pMapSpawn->pSpawn), pMapSpawn->pSpawn))
		{
			MAPSPAWN* pNext = pMapSpawn->pNext;
			RemoveSpawn(pMapSpawn);
			pMapSpawn = pNext;
			continue;
		}

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
					MAPSPAWN* pNext = pMapSpawn->pNext;
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
			if (pMapSpawn->pSpawn->SpeedRun > 0) {
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
				pMapSpawn->pVector->End.X = -pMapSpawn->pSpawn->X - sinf(pMapSpawn->pSpawn->Heading / 256.0f * (float)PI) * 4;
				pMapSpawn->pVector->End.Y = -pMapSpawn->pSpawn->Y - cosf(pMapSpawn->pSpawn->Heading / 256.0f * (float)PI) * 4;
				pMapSpawn->pVector->End.Z = pMapSpawn->pSpawn->Z;
			}
		}

		if (IsOptionEnabled(MAPFILTER_Marker))
			MoveMarker(pMapSpawn);
		else if (!IsOptionEnabled(MAPFILTER_Marker))
			RemoveMarker(pMapSpawn);
		pMapSpawn = pMapSpawn->pNext;
	}

	needAnon = false;

	if (IsOptionEnabled(MAPFILTER_CastRadius))
	{
		unsigned long Angle = 0;
		for (int i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++, Angle += CASTRADIUS_ANGLESIZE)
		{
			if (!pCastRadius[i])
			{
				pCastRadius[i] = InitLine();
				pCastRadius[i]->Layer = activeLayer;
			}

			pCastRadius[i]->Color.ARGB = MapFilterOptions[MAPFILTER_CastRadius].Color;
			pCastRadius[i]->Start.Z = pCharInfo->pSpawn->Z;
			pCastRadius[i]->End.Z = pCharInfo->pSpawn->Z;
			pCastRadius[i]->Start.X = -pCharInfo->pSpawn->X + (float)MapFilterOptions[MAPFILTER_CastRadius].Enabled * cosf((float)Angle / 180.0f * (float)PI);
			pCastRadius[i]->Start.Y = -pCharInfo->pSpawn->Y + (float)MapFilterOptions[MAPFILTER_CastRadius].Enabled * sinf((float)Angle / 180.0f * (float)PI);;
			pCastRadius[i]->End.X = -pCharInfo->pSpawn->X + (float)MapFilterOptions[MAPFILTER_CastRadius].Enabled * cosf((float)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f * (float)PI);
			pCastRadius[i]->End.Y = -pCharInfo->pSpawn->Y + (float)MapFilterOptions[MAPFILTER_CastRadius].Enabled * sinf((float)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f * (float)PI);
		}
	}
	else if (pCastRadius[0])
	{
		for (int i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
		{
			DeleteLine(pCastRadius[i]);
			pCastRadius[i] = nullptr;
		}
	}

	if (IsOptionEnabled(MAPFILTER_CampRadius))
	{
		unsigned long Angle = 0;
		for (int i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++, Angle += CASTRADIUS_ANGLESIZE)
		{
			if (!pCampRadius[i])
			{
				pCampRadius[i] = InitLine();
				pCampRadius[i]->Layer = activeLayer;
			}

			pCampRadius[i]->Color.ARGB = MapFilterOptions[MAPFILTER_CampRadius].Color;
			pCampRadius[i]->Start.Z = pCharInfo->pSpawn->Z;
			pCampRadius[i]->End.Z = pCharInfo->pSpawn->Z;
			pCampRadius[i]->Start.X = -CampX + (float)MapFilterOptions[MAPFILTER_CampRadius].Enabled * cosf((float)Angle / 180.0f * (float)PI);
			pCampRadius[i]->Start.Y = -CampY + (float)MapFilterOptions[MAPFILTER_CampRadius].Enabled * sinf((float)Angle / 180.0f * (float)PI);;
			pCampRadius[i]->End.X = -CampX + (float)MapFilterOptions[MAPFILTER_CampRadius].Enabled * cosf((float)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f * (float)PI);
			pCampRadius[i]->End.Y = -CampY + (float)MapFilterOptions[MAPFILTER_CampRadius].Enabled * sinf((float)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f * (float)PI);
		}
	}
	else if (pCampRadius[0])
	{
		for (int i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
		{
			DeleteLine(pCampRadius[i]);
			pCampRadius[i] = nullptr;
		}
	}

	if (IsOptionEnabled(MAPFILTER_PullRadius))
	{
		unsigned long Angle = 0;
		for (int i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++, Angle += CASTRADIUS_ANGLESIZE)
		{
			if (!pPullRadius[i])
			{
				pPullRadius[i] = InitLine();
				pPullRadius[i]->Layer = activeLayer;
			}

			pPullRadius[i]->Color.ARGB = MapFilterOptions[MAPFILTER_PullRadius].Color;
			pPullRadius[i]->Start.Z = pCharInfo->pSpawn->Z;
			pPullRadius[i]->End.Z = pCharInfo->pSpawn->Z;
			pPullRadius[i]->Start.X = -PullX + (float)MapFilterOptions[MAPFILTER_PullRadius].Enabled * cosf((float)Angle / 180.0f * (float)PI);
			pPullRadius[i]->Start.Y = -PullY + (float)MapFilterOptions[MAPFILTER_PullRadius].Enabled * sinf((float)Angle / 180.0f * (float)PI);;
			pPullRadius[i]->End.X = -PullX + (float)MapFilterOptions[MAPFILTER_PullRadius].Enabled * cosf((float)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f * (float)PI);
			pPullRadius[i]->End.Y = -PullY + (float)MapFilterOptions[MAPFILTER_PullRadius].Enabled * sinf((float)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f * (float)PI);
		}
	}
	else if (pPullRadius[0])
	{
		for (int i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
		{
			DeleteLine(pPullRadius[0]);
			pPullRadius[i] = nullptr;
		}
	}

	if (IsOptionEnabled(MAPFILTER_SpellRadius))
	{
		unsigned long Angle = 0;
		for (int i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++, Angle += CASTRADIUS_ANGLESIZE)
		{
			if (!pSpellRadius[i])
			{
				pSpellRadius[i] = InitLine();
				pSpellRadius[i]->Layer = activeLayer;
			}

			pSpellRadius[i]->Color.ARGB = MapFilterOptions[MAPFILTER_SpellRadius].Color;
			pSpellRadius[i]->Start.Z = pCharInfo->pSpawn->Z;
			pSpellRadius[i]->End.Z = pCharInfo->pSpawn->Z;
			pSpellRadius[i]->Start.X = -pCharInfo->pSpawn->X + (float)MapFilterOptions[MAPFILTER_SpellRadius].Enabled * cosf((float)Angle / 180.0f * (float)PI);
			pSpellRadius[i]->Start.Y = -pCharInfo->pSpawn->Y + (float)MapFilterOptions[MAPFILTER_SpellRadius].Enabled * sinf((float)Angle / 180.0f * (float)PI);;
			pSpellRadius[i]->End.X = -pCharInfo->pSpawn->X + (float)MapFilterOptions[MAPFILTER_SpellRadius].Enabled * cosf((float)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f * (float)PI);
			pSpellRadius[i]->End.Y = -pCharInfo->pSpawn->Y + (float)MapFilterOptions[MAPFILTER_SpellRadius].Enabled * sinf((float)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f * (float)PI);
		}
	}
	else if (pSpellRadius[0])
	{
		for (int i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
		{
			DeleteLine(pSpellRadius[i]);
			pSpellRadius[i] = nullptr;
		}
	}

	if (IsOptionEnabled(MAPFILTER_Group))
	{
		CHARINFO* pChar = GetCharInfo();
		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			if (pChar->pGroupInfo && pChar->pGroupInfo->pMember[i])
			{
				auto pSpawn = GetSpawnByName(pChar->pGroupInfo->pMember[i]->Name.c_str());
				if (pSpawn)
				{
					if (pMapSpawn = SpawnMap[pSpawn->SpawnID])
					{
						pMapSpawn->pMapLabel->Color.ARGB = MapFilterOptions[MAPFILTER_Group].Color;
					}
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

			pTargetLine->End.X = -((SPAWNINFO*)pTarget)->X;
			pTargetLine->End.Y = -((SPAWNINFO*)pTarget)->Y;
			pTargetLine->End.Z = ((SPAWNINFO*)pTarget)->Z;
		}
		else if (pTargetLine)
		{
			DeleteLine(pTargetLine);
			pTargetLine = nullptr;
		}

		if (IsOptionEnabled(MAPFILTER_TargetRadius))
		{
			unsigned long Angle = 0;
			for (int i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++, Angle += CASTRADIUS_ANGLESIZE)
			{
				if (!pTargetRadius[i])
				{
					pTargetRadius[i] = InitLine();
					pTargetRadius[i]->Layer = activeLayer;
				}

				pTargetRadius[i]->Color.ARGB = MapFilterOptions[MAPFILTER_TargetRadius].Color;
				pTargetRadius[i]->Start.Z = ((SPAWNINFO*)pTarget)->Z;
				pTargetRadius[i]->End.Z = ((SPAWNINFO*)pTarget)->Z;
				pTargetRadius[i]->Start.X = -((SPAWNINFO*)pTarget)->X + (float)MapFilterOptions[MAPFILTER_TargetRadius].Enabled * cosf((float)Angle / 180.0f * (float)PI);
				pTargetRadius[i]->Start.Y = -((SPAWNINFO*)pTarget)->Y + (float)MapFilterOptions[MAPFILTER_TargetRadius].Enabled * sinf((float)Angle / 180.0f * (float)PI);;
				pTargetRadius[i]->End.X = -((SPAWNINFO*)pTarget)->X + (float)MapFilterOptions[MAPFILTER_TargetRadius].Enabled * cosf((float)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f * (float)PI);
				pTargetRadius[i]->End.Y = -((SPAWNINFO*)pTarget)->Y + (float)MapFilterOptions[MAPFILTER_TargetRadius].Enabled * sinf((float)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f * (float)PI);
			}
		}
		else if (pTargetRadius[0])
		{
			for (int i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
			{
				DeleteLine(pTargetRadius[i]);
				pTargetRadius[i] = nullptr;
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
				pTargetMelee[i]->Start.Z = ((SPAWNINFO*)pTarget)->Z;
				pTargetMelee[i]->End.Z = ((SPAWNINFO*)pTarget)->Z;
				float MaxMelee;

				if (MapFilterOptions[MAPFILTER_TargetMelee].Enabled == 1)
					MaxMelee = get_melee_range(pCharSpawn, pTarget);
				else
					MaxMelee = get_melee_range(pTarget, pTarget);

				pTargetMelee[i]->Start.X = -((SPAWNINFO*)pTarget)->X + MaxMelee * cosf((float)Angle / 180.0f * (float)PI);
				pTargetMelee[i]->Start.Y = -((SPAWNINFO*)pTarget)->Y + MaxMelee * sinf((float)Angle / 180.0f * (float)PI);;
				pTargetMelee[i]->End.X = -((SPAWNINFO*)pTarget)->X + MaxMelee * cosf((float)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f * (float)PI);
				pTargetMelee[i]->End.Y = -((SPAWNINFO*)pTarget)->Y + MaxMelee * sinf((float)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f * (float)PI);
			}
		}
		else if (pTargetMelee[0])
		{
			for (int i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
			{
				DeleteLine(pTargetMelee[i]);
				pTargetMelee[i] = nullptr;
			}
		}
	}
	else
	{
		if (pTargetRadius[0])
		{
			for (int i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
			{
				DeleteLine(pTargetRadius[i]);
				pTargetRadius[i] = nullptr;
			}
		}

		if (pTargetMelee[0])
		{
			for (int i = 0; i < (360 / CASTRADIUS_ANGLESIZE); i++)
			{
				DeleteLine(pTargetMelee[i]);
				pTargetMelee[i] = nullptr;
			}
		}

		if (pTargetLine)
		{
			DeleteLine(pTargetLine);
			pTargetLine = nullptr;
		}
	}
	ExitMQ2Benchmark(bmMapRefresh);
}

void MapAttach()
{
	if (pLabelList)
	{
		pActualLineList = pMapViewWnd->MapView.pLabels;
		if (IsOptionEnabled(MAPFILTER_NormalLabels))
			pLabelListTail->pNext = pMapViewWnd->MapView.pLabels;
		pMapViewWnd->MapView.pLabels = pLabelList;
	}

	if (pLineList)
	{
		pLineListTail->pNext = pMapViewWnd->MapView.pLines;
		pMapViewWnd->MapView.pLines = pLineList;
	}
}

void MapDetach()
{
	if (pLabelList)
	{
		pMapViewWnd->MapView.pLabels = pActualLineList;
		pLabelListTail->pNext = nullptr;
	}
	if (pLineList)
	{
		pMapViewWnd->MapView.pLines = pLineListTail->pNext;
		pLineListTail->pNext = nullptr;
	}
}

bool MapSelectTarget()
{
	if (!pCurrentMapLabel)
		return false;

	MAPSPAWN* pMapSpawn = LabelMap[pCurrentMapLabel];
	if (!pMapSpawn)
		return true;

	if (pMapSpawn->SpawnType == ITEM)
	{
		EnviroTarget = *pMapSpawn->pSpawn;
		EnviroTarget.Type = SPAWN_NPC;
	}
	else
	{
		DWORD Flags = pWndMgr->GetKeyboardFlags();
		CHARINFO* pCharInfo = GetCharInfo();
		if (pCharInfo && Flags && MapSpecialClickString[Flags][0])
		{
			char* Cmd = GenerateSpawnName(pMapSpawn->pSpawn, MapSpecialClickString[Flags]);

			DoCommand(pCharInfo->pSpawn, Cmd);			free(Cmd);
		}
		else
		{
			pTarget = reinterpret_cast<PlayerClient*>(pMapSpawn->pSpawn);
		}
	}
	if (IsOptionEnabled(MAPFILTER_TargetPath))
		return true;
	return false;
}

void MapClickLocation(float world_point_x, float world_point_y, const std::vector<float>& z_hits)
{
	CHARINFO* pCharInfo = GetCharInfo();

	std::vector<float> sorted_z(z_hits);
	std::sort(sorted_z.begin(), sorted_z.end());

	float point_z = (pCharInfo && pCharInfo->pSpawn) ? pCharInfo->pSpawn->Z : 0.f;
	auto closest_z_it = std::lower_bound(sorted_z.begin(), sorted_z.end(), point_z);

	if (closest_z_it == sorted_z.end() && closest_z_it != sorted_z.begin())
	{
		--closest_z_it;
	}
	else if (closest_z_it != sorted_z.end() && closest_z_it != sorted_z.begin()
		&& (std::abs(*closest_z_it - point_z) > std::abs(*(closest_z_it - 1) - point_z)))
	{
		--closest_z_it;
	}

	DWORD Flags = pWndMgr->GetKeyboardFlags();
	if (pCharInfo && Flags && MapLeftClickString[Flags][0])
	{
		char CommandString[MAX_STRING];
		strcpy_s(CommandString, MapLeftClickString[Flags]);
		std::string sOutput;

		for (unsigned short N = 0; CommandString[N]; ++N)
		{
			if (CommandString[N] == '%')
			{
				++N;
				switch (CommandString[N])
				{
				case 'x':
					sOutput.append(std::to_string(world_point_x));
					break;

				case 'y':
					sOutput.append(std::to_string(world_point_y));
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
					}
					else
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
			}
			else
			{
				sOutput.append(1, CommandString[N]);
			}
		}

		strcpy_s(CommandString, sOutput.c_str());
		DoCommand(pCharInfo->pSpawn, CommandString);
	}
}

int MapHighlight(MQSpawnSearch* pSearch)
{
	if (!pSearch)
	{
		MAPSPAWN* pMapSpawn = pActiveSpawns;
		while (pMapSpawn)
		{
			pMapSpawn->Highlight = false;
			pMapSpawn = pMapSpawn->pNext;
		}
		return 0;
	}
	else
	{
		CHARINFO* pCharInfo = GetCharInfo();
		if (!pCharInfo || !pCharInfo->pSpawn)
			return 0;
		MAPSPAWN* pMapSpawn = pActiveSpawns;
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

char* GenerateSpawnName(SPAWNINFO* pSpawn, char* NameString)
{
	std::string sOutput;
#define AddString(str) {sOutput.append( str );}
#define AddInt(yourint) {sOutput.append( std::to_string( yourint ) );}
#define AddFloat10th(yourfloat) {sOutput.append( std::to_string( yourfloat ) );}

	auto FormatAnonymizedName = [&](SPAWNINFO* pSpawn, const char* defaultName)
	{
		switch (pSpawn->Type)
		{
		case SPAWN_CORPSE:
			if (pSpawn->Deity)
			{
				AddString(GetClassDesc(pSpawn->GetClass()));
			}
			else
			{
				AddString(pSpawn->DisplayedName);
			}
			break;

		case SPAWN_NPC:
			if (pSpawn->MasterID || pSpawn->Rider)
			{
				bool isPlayers = false;

				if (SPAWNINFO * petOwner = (SPAWNINFO*)GetSpawnByID(pSpawn->MasterID))
				{
					if (petOwner->Type == SPAWN_PLAYER || petOwner->Type == SPAWN_CORPSE)
					{
						isPlayers = true;
					}
				}

				if (pSpawn->Rider)
				{
					if (SPAWNINFO * rider = (SPAWNINFO*)GetSpawnByID(pSpawn->Rider->SpawnID))
					{
						if (rider->Type == SPAWN_PLAYER)
							isPlayers = true;
					}
				}

				if (isPlayers)
				{
					AddString(GetClassDesc(pSpawn->GetClass()));
				}
				else
				{
					AddString(defaultName);
				}
			}
			else
			{
				AddString(defaultName);
			}
			break;

		case SPAWN_PLAYER:
			AddString(GetClassDesc(pSpawn->GetClass()));
			break;

		default:
			AddString(defaultName);
			break;
		}
	};

	for (unsigned long N = 0; NameString[N]; N++)
	{
		if (NameString[N] == '%')
		{
			N++;
			switch (NameString[N])
			{
			case 'N': // cleaned up name
				if (gAnonymize)
				{
					FormatAnonymizedName(pSpawn, pSpawn->DisplayedName);
				}
				else
				{
					AddString(pSpawn->DisplayedName);
				}

				if (pSpawn->Type == SPAWN_CORPSE)
				{
					sOutput.append("'s Corpse");
				}
				break;

			case 'n': // original name
				if (gAnonymize)
				{
					FormatAnonymizedName(pSpawn, pSpawn->Name);
				}
				else
				{
					AddString(pSpawn->Name);
				}
				break;

			case 'h': // current health %
				AddInt(pSpawn->HPCurrent);
				break;

			case 'i':
				if (gAnonymize)
				{
					AddInt(0); // Don't display SpawnID if we are Anon.
				}
				else
				{
					AddInt(pSpawn->SpawnID);
				}
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
				if (gAnonymize)
				{
					// Only display the class if it's an NPC, otherwise we'll display it twice for corpses and players.
					if (pSpawn->Type == SPAWN_NPC)
						AddString(GetClassDesc(pSpawn->mActorClient.Class));
				}
				else
				{
					AddString(GetClassDesc(pSpawn->mActorClient.Class));
				}
				break;

			case 'c':
				if (gAnonymize)
				{
					// Only display the 3 letter race if it's an NPC, we're already displaying the full race name otherwise.
					if (pSpawn->Type == SPAWN_NPC)
						AddString(pEverQuest->GetClassThreeLetterCode(pSpawn->mActorClient.Class));
				}
				else
				{
					AddString(pEverQuest->GetClassThreeLetterCode(pSpawn->mActorClient.Class));
				}
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

	int len = sOutput.length() + 1;

	if (char* ret = (char*)malloc(len))
	{
		strcpy_s(ret, len, sOutput.c_str());
		return ret;
	}

	return nullptr;
}

DWORD TypeToMapfilter(SPAWNINFO* pNewSpawn)
{
	eSpawnType Type = GetSpawnType(pNewSpawn);

	switch (Type)
	{
	case PC:
		return MAPFILTER_PC;
	case NPC:
		if (IsOptionEnabled(MAPFILTER_Named)) {
			if (CHARINFO * pCharInfo = GetCharInfo()) {
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

BOOL CanDisplaySpawn(eSpawnType Type, SPAWNINFO* pSpawn)
{
	if (!pSpawn)
		return FALSE;

	if ((pSpawn == (SPAWNINFO*)pTarget) && IsOptionEnabled(MAPFILTER_Target))
	{
		return TRUE;
	}
	if (IsOptionEnabled(MAPFILTER_Custom))
	{
		if (CHARINFO* pCharInfo = GetCharInfo())
		{
			if (pCharInfo->pSpawn)
				return SpawnMatchesSearch(&MapFilterCustom, pCharInfo->pSpawn, pSpawn);
		}
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

DWORD GetSpawnColor(eSpawnType Type, SPAWNINFO* pSpawn)
{
	CHARINFO* pChar = GetCharInfo();
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

MAPLABEL* GenerateLabel(MAPSPAWN* pMapSpawn, DWORD Color)
{
	MAPLABEL* pLabel = InitLabel(pMapSpawn);
	pLabel->Location.X = -pMapSpawn->pSpawn->X;
	pLabel->Location.Y = -pMapSpawn->pSpawn->Y;
	pLabel->Location.Z = pMapSpawn->pSpawn->Z;
	pLabel->Layer = activeLayer;
	pLabel->Size = 3;
	pLabel->Label = GenerateSpawnName(pMapSpawn->pSpawn, MapNameString);
	pLabel->Color.ARGB = Color;
	pLabel->Width = 20;
	pLabel->Height = 14;
	pLabel->OffsetX = 0;
	pLabel->OffsetY = 0;
	return pLabel;
}

PMAPLINE GenerateVector(MAPSPAWN* pMapSpawn)
{
	PMAPLINE pNewLine = InitLine();

	if (pMapSpawn->pSpawn->SpeedRun > 0)
	{
		pNewLine->Start.X = -pMapSpawn->pSpawn->X;
		pNewLine->Start.Y = -pMapSpawn->pSpawn->Y;
		pNewLine->Start.Z = pMapSpawn->pSpawn->Z;
		pNewLine->End.X = -pMapSpawn->pSpawn->X - pMapSpawn->pSpawn->SpeedX * 4;
		pNewLine->End.Y = -pMapSpawn->pSpawn->Y - pMapSpawn->pSpawn->SpeedY * 4;
		pNewLine->End.Z = pMapSpawn->pSpawn->Z + pMapSpawn->pSpawn->SpeedZ * 4;
	}
	else
	{
		pNewLine->Start.X = -pMapSpawn->pSpawn->X;
		pNewLine->Start.Y = -pMapSpawn->pSpawn->Y;
		pNewLine->Start.Z = pMapSpawn->pSpawn->Z;
		pNewLine->End.X = -pMapSpawn->pSpawn->X - sinf(pMapSpawn->pSpawn->Heading / 256.0f * (float)PI) * 4;
		pNewLine->End.Y = -pMapSpawn->pSpawn->Y - cosf(pMapSpawn->pSpawn->Heading / 256.0f * (float)PI) * 4;
		pNewLine->End.Z = pMapSpawn->pSpawn->Z;
	}

	pNewLine->Layer = activeLayer;
	pNewLine->Color = pMapSpawn->pMapLabel->Color;

	return pNewLine;
}

int MapHide(MQSpawnSearch& Search)
{
	CHARINFO* pCharInfo = GetCharInfo();
	if (!pCharInfo || !pCharInfo->pSpawn)
		return 0;

	MAPSPAWN* pMapSpawn = pActiveSpawns;
	unsigned long Count = 0;

	while (pMapSpawn)
	{
		if (pMapSpawn->pSpawn->Type != FAKESPAWNTYPE && SpawnMatchesSearch(&Search, pCharInfo->pSpawn, pMapSpawn->pSpawn))
		{
			MAPSPAWN* pNext = pMapSpawn->pNext;
			RemoveSpawn(pMapSpawn);
			pMapSpawn = pNext;
			Count++;
		}
		else
			pMapSpawn = pMapSpawn->pNext;
	}
	return Count;
}

int MapShow(MQSpawnSearch& Search)
{
	CHARINFO* pCharInfo = GetCharInfo();
	if (!pCharInfo)
		return 0;

	SPAWNINFO* pSpawn = (SPAWNINFO*)pSpawnList;
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

bool dataMapSpawn(const char* szIndex, MQTypeVar& Ret)
{
	if (!pCurrentMapLabel)
		return false;

	if (MAPSPAWN * pMapSpawn = LabelMap[pCurrentMapLabel])
	{
		Ret.Ptr = pMapSpawn->pSpawn;
		Ret.Type = datatypes::pSpawnType;
		return true;
	}
	return false;
}

void GenerateMarker(MAPSPAWN* pMapSpawn)
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
		pMapSpawn->MarkerLines[i] = nullptr;

	for (i = 0; i < lNumSides; i++)
	{
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

void RemoveMarker(MAPSPAWN* pMapSpawn)
{
	if (pMapSpawn->Marker == 0 || !pMapSpawn->Marker) return;
	pMapSpawn->Marker = 0;

	for (int i = 0; pMapSpawn->MarkerLines[i]; i++)
	{
		if (pMapSpawn->MarkerLines[i]) {
			DeleteLine(pMapSpawn->MarkerLines[i]);
			pMapSpawn->MarkerLines[i] = nullptr;
		}
	}
}

void MSM(MAPSPAWN* pMapSpawn)
{
	DWORD MARKERSIDELEN = pMapSpawn->MarkerSize;
	float x[2], y[2], X[2], Y[2];

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

	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
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

void MTM(MAPSPAWN* pMapSpawn)
{
	DWORD MARKERSIDELEN = pMapSpawn->MarkerSize;
	float x[2], y[2], X[2], Y[2], Angle;
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

	Angle = pMapSpawn->pSpawn->Heading * 0.703125f;
	x[0] = -pMapSpawn->pSpawn->X + (MARKERSIDELEN * 1.5f) * sqrtf(3) / 3 * sinf((Angle + 180) / 180.0f * (float)PI);
	x[1] = -pMapSpawn->pSpawn->X - (MARKERSIDELEN * 1.5f) * sqrtf(3) / 3 * sinf((Angle + 210) / 180.0f * (float)PI);
	x[2] = -pMapSpawn->pSpawn->X + (MARKERSIDELEN * 1.5f) * sqrtf(3) / 3 * sinf((Angle + 330) / 180.0f * (float)PI);
	y[0] = -pMapSpawn->pSpawn->Y + (MARKERSIDELEN * 1.5f) * sqrtf(3) / 3 * cosf((Angle + 180) / 180.0f * (float)PI);
	y[1] = -pMapSpawn->pSpawn->Y - (MARKERSIDELEN * 1.5f) * sqrtf(3) / 3 * cosf((Angle + 210) / 180.0f * (float)PI);
	y[2] = -pMapSpawn->pSpawn->Y + (MARKERSIDELEN * 1.5f) * sqrtf(3) / 3 * cosf((Angle + 330) / 180.0f * (float)PI);

	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0: X[0] = x[0]; X[1] = x[1]; Y[0] = y[0]; Y[1] = y[1]; break;
		case 1: X[0] = x[1]; X[1] = x[2]; Y[0] = y[1]; Y[1] = y[2]; break;
		case 2: X[0] = x[2]; X[1] = x[0]; Y[0] = y[2]; Y[1] = y[0]; break;
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

void MDM(MAPSPAWN* pMapSpawn)
{
	DWORD MARKERSIDELEN = pMapSpawn->MarkerSize;
	float x[2], y[2], X[2], Y[2];
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
	x[1] = -pMapSpawn->pSpawn->X + MARKERSIDELEN * .71f;   // sqrt(2)/2
	x[2] = -pMapSpawn->pSpawn->X - MARKERSIDELEN * .71f;
	y[0] = -pMapSpawn->pSpawn->Y - MARKERSIDELEN * .71f;
	y[1] = -pMapSpawn->pSpawn->Y;
	y[2] = -pMapSpawn->pSpawn->Y + MARKERSIDELEN * .71f;

	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0: X[0] = x[0]; X[1] = x[1]; Y[0] = y[0]; Y[1] = y[1]; break;
		case 1: X[0] = x[1]; X[1] = x[0]; Y[0] = y[1]; Y[1] = y[2]; break;
		case 2: X[0] = x[0]; X[1] = x[2]; Y[0] = y[2]; Y[1] = y[1]; break;
		case 3: X[0] = x[2]; X[1] = x[0]; Y[0] = y[1]; Y[1] = y[0]; break;
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


void MRM(MAPSPAWN* pMapSpawn)
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

		pMapSpawn->MarkerLines[i]->Start.X = -pMapSpawn->pSpawn->X + MARKERSIDELEN*sinf((i * 45 + (float)22.5) / 180.0f*(float)PI);
		pMapSpawn->MarkerLines[i]->Start.Y = -pMapSpawn->pSpawn->Y + MARKERSIDELEN*cosf((i * 45 + (float)22.5) / 180.0f*(float)PI);
		pMapSpawn->MarkerLines[i]->End.X = -pMapSpawn->pSpawn->X + MARKERSIDELEN*sinf(((i + 1) * 45 + (float)22.5) / 180.0f*(float)PI);
		pMapSpawn->MarkerLines[i]->End.Y = -pMapSpawn->pSpawn->Y + MARKERSIDELEN*cosf(((i + 1) * 45 + (float)22.5) / 180.0f*(float)PI);
		pMapSpawn->MarkerLines[i]->Start.Z = pMapSpawn->pSpawn->Z;
		pMapSpawn->MarkerLines[i]->End.Z = pMapSpawn->pSpawn->Z;

		if (pMapSpawn->MarkerLines[i]->Color.ARGB != pMapSpawn->pMapLabel->Color.ARGB)
			pMapSpawn->MarkerLines[i]->Color = pMapSpawn->pMapLabel->Color;
	}
}

void MoveMarker(MAPSPAWN* pMapSpawn)
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

int FindMarker(std::string_view szMark, int fallback)
{
	if (ci_equals(szMark, "none"))
		return 0;
	if (ci_equals(szMark, "triangle"))
		return 1;
	if (ci_equals(szMark, "square"))
		return 2;
	if (ci_equals(szMark, "diamond"))
		return 3;
	if (ci_equals(szMark, "ring"))
		return 4;

	return fallback;
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

void UpdateDefaultMapLoc()
{
	DefaultMapLoc->lineSize = GetPrivateProfileInt("MapLoc", "Size", 50, INIFileName);
	DefaultMapLoc->width = GetPrivateProfileInt("MapLoc", "Width", 10, INIFileName);
	DefaultMapLoc->r_color = GetPrivateProfileInt("MapLoc", "Red", 255, INIFileName);
	DefaultMapLoc->g_color = GetPrivateProfileInt("MapLoc", "Green", 0, INIFileName);
	DefaultMapLoc->b_color = GetPrivateProfileInt("MapLoc", "Blue", 0, INIFileName);
	DefaultMapLoc->radius = GetPrivateProfileInt("MapLoc", "Radius", 0, INIFileName);
	DefaultMapLoc->rr_color = GetPrivateProfileInt("MapLoc", "RadiusRed", 0, INIFileName);
	DefaultMapLoc->rg_color = GetPrivateProfileInt("MapLoc", "RadiusGreen", 0, INIFileName);
	DefaultMapLoc->rb_color = GetPrivateProfileInt("MapLoc", "RadiusBlue", 255, INIFileName);

	// Update existing default maplocs
	for (auto const& [tag, loc] : LocationMap)
	{
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

void PrintDefaultMapLocSettings()
{
	DefaultMapLoc->lineSize = GetPrivateProfileInt("MapLoc", "Size", 50, INIFileName);
	DefaultMapLoc->width = GetPrivateProfileInt("MapLoc", "Width", 10, INIFileName);
	DefaultMapLoc->r_color = GetPrivateProfileInt("MapLoc", "Red", 255, INIFileName);
	DefaultMapLoc->g_color = GetPrivateProfileInt("MapLoc", "Green", 0, INIFileName);
	DefaultMapLoc->b_color = GetPrivateProfileInt("MapLoc", "Blue", 0, INIFileName);
	DefaultMapLoc->radius = GetPrivateProfileInt("MapLoc", "Radius", 0, INIFileName);
	DefaultMapLoc->rr_color = GetPrivateProfileInt("MapLoc", "RadiusRed", 0, INIFileName);
	DefaultMapLoc->rg_color = GetPrivateProfileInt("MapLoc", "RadiusGreen", 0, INIFileName);
	DefaultMapLoc->rb_color = GetPrivateProfileInt("MapLoc", "RadiusBlue", 255, INIFileName);

	WriteChatf("%s", fmt::format("MapLoc Defaults: Width:{}, Size:{}, Color:{},{},{}, Radius:{}, Radius Color:{},{},{}",
		DefaultMapLoc->width, DefaultMapLoc->lineSize, DefaultMapLoc->r_color, DefaultMapLoc->g_color, DefaultMapLoc->b_color,
		DefaultMapLoc->radius, DefaultMapLoc->rr_color, DefaultMapLoc->rg_color, DefaultMapLoc->rb_color).c_str());
}

void MapLocSyntaxOutput()
{
	SyntaxError("Usage: /maploc [[size 10-200] | [width 1-10] | [color r g b] | [radius <distance>] | [rcolor r g b] | [yloc xloc (zloc) | target]] | [label text]");
	SyntaxError(" -- Omit locs to set defaults");
	SyntaxError(" -- Add label to loc by putting 'label <my text here>' only at end of command");
	SyntaxError("Remove maplocs: /maploc remove [index | [yloc xloc (zloc)]]");
	PrintDefaultMapLocSettings();
}

void MapRemoveLocation(SPAWNINFO* pChar, char* szLine)
{
	char arg[MAX_STRING];
	std::stringstream ss(szLine);
	ss >> arg; // remove reparsed initial clear

	if (!ss || ss.eof())
	{
		auto it = LocationMap.begin();
		while (it != LocationMap.end())
		{
			MAPLOC* loc = it->second;
			maplocOrder.remove(loc);
			DeleteMapLoc(loc);
			delete loc;
			it = LocationMap.erase(it);
		}

		LocationMap.clear();
		WriteChatColor("MapLocs removed", USERCOLOR_DEFAULT);
		return;
	}

	char szBuffer[MAX_STRING] = { 0 };
	char yloc[MAX_STRING] = { "not set" };
	char xloc[MAX_STRING] = { "not set" };
	char zloc[MAX_STRING] = { "0" };
	char tag[MAX_STRING] = { 0 };

	ss >> arg;

	if (!IsFloat(arg))
	{
		MapLocSyntaxOutput();
		return;
	}

	strcpy_s(yloc, arg);

	if (ss && !ss.eof())
	{
		ss >> arg;

		if (!IsFloat(arg))
		{
			MapLocSyntaxOutput();
			return;
		}

		strcpy_s(xloc, arg);

		if (ss && !ss.eof())
		{
			ss >> arg;

			if (!IsFloat(arg))
			{
				MapLocSyntaxOutput();
				return;
			}

			strcpy_s(zloc, arg);
		}

		// deal only in full int locs, makes it easier to do things like clear locs later
		std::string delim = ".";
		std::string temp = yloc;

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
		int index = static_cast<int>(std::stof(yloc));
		if (index < (int)maplocOrder.size() + 1)
		{
			MAPLOC* mapLocToRemove = nullptr;
			auto it = maplocOrder.begin();
			std::advance(it, index - 1);
			mapLocToRemove = *it;
			strcpy_s(yloc, std::to_string(mapLocToRemove->yloc).c_str());
			strcpy_s(xloc, std::to_string(mapLocToRemove->xloc).c_str());
			strcpy_s(zloc, std::to_string(mapLocToRemove->zloc).c_str());
		}
		else
		{
			WriteChatf("\arRemove loc by index out of bounds: %s", yloc);
			return;
		}
	}

	sprintf_s(tag, "%s,%s,%s", yloc, xloc, zloc);

	MAPLOC* loc = LocationMap[tag];
	if (!loc)
	{
		SyntaxError("Could not find MapLoc: %s", tag);
		return;
	}

	std::string index = std::to_string(loc->index);

	// Delete the loc
	maplocOrder.remove(loc);
	DeleteMapLoc(loc);
	delete loc;
	LocationMap.erase(tag);

	// Update index labels for remaining locs
	UpdateMapLocIndexes();
	for (MAPLOC* locToUpdate : maplocOrder)
	{
		if (locToUpdate->mapSpawn)
		{
			RemoveSpawn(locToUpdate->mapSpawn);
		}

		AddMapSpawnForMapLoc(locToUpdate);
	}

	WriteChatf("MapLoc removed: Index:%s, loc:%s", index.c_str(), tag);
}

void DeleteMapLoc(MAPLOC* mapLoc)
{
	if (mapLoc)
	{
		for (auto& markerLine : mapLoc->markerLines)
		{
			if (markerLine)
			{
				DeleteLine(markerLine);
				markerLine = nullptr;
			}
		}

		if (mapLoc->mapSpawn)
		{
			RemoveSpawn(mapLoc->mapSpawn);
		}
	}
}

void UpdateMapLoc(MAPLOC* mapLoc)
{
	if (!mapLoc)
	{
		return;
	}

	DeleteMapLoc(mapLoc);

	int lineIndex = 0;

	// Create the X
	for (int xWidth = 1; xWidth <= mapLoc->width; xWidth++)
	{
		if (xWidth == 1)
		{
			// Backslash
			mapLoc->markerLines[lineIndex] = InitLine();
			mapLoc->markerLines[lineIndex]->Start.X = (float)-mapLoc->xloc - mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->Start.Y = (float)-mapLoc->yloc - mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->Start.Z = (float)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->End.X = (float)-mapLoc->xloc + mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->End.Y = (float)-mapLoc->yloc + mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->End.Z = (float)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->Layer = activeLayer;
			ARGBCOLOR bsColor;
			bsColor.ARGB = 0xFF000000 | (mapLoc->r_color << 16) | (mapLoc->g_color << 8) | (mapLoc->b_color);
			mapLoc->markerLines[lineIndex++]->Color = bsColor;

			// Forwardslash
			mapLoc->markerLines[lineIndex] = InitLine();
			mapLoc->markerLines[lineIndex]->Start.X = (float)-mapLoc->xloc - mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->Start.Y = (float)-mapLoc->yloc + mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->Start.Z = (float)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->End.X = (float)-mapLoc->xloc + mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->End.Y = (float)-mapLoc->yloc - mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->End.Z = (float)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->Layer = activeLayer;
			ARGBCOLOR fsColor;
			fsColor.ARGB = 0xFF000000 | (mapLoc->r_color << 16) | (mapLoc->g_color << 8) | (mapLoc->b_color);
			mapLoc->markerLines[lineIndex++]->Color = fsColor;
		}
		else
		{
			// Backslash lower
			mapLoc->markerLines[lineIndex] = InitLine();
			mapLoc->markerLines[lineIndex]->Start.X = (float)-mapLoc->xloc - mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->Start.Y = (float)-mapLoc->yloc - mapLoc->lineSize + xWidth - 1;
			mapLoc->markerLines[lineIndex]->Start.Z = (float)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->End.X = (float)-mapLoc->xloc + mapLoc->lineSize - xWidth + 1;
			mapLoc->markerLines[lineIndex]->End.Y = (float)-mapLoc->yloc + mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->End.Z = (float)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->Layer = activeLayer;
			ARGBCOLOR bslColor;
			bslColor.ARGB = 0xFF000000 | (mapLoc->r_color << 16) | (mapLoc->g_color << 8) | (mapLoc->b_color);
			mapLoc->markerLines[lineIndex++]->Color = bslColor;

			// Forwardslash lower
			mapLoc->markerLines[lineIndex] = InitLine();
			mapLoc->markerLines[lineIndex]->Start.X = (float)-mapLoc->xloc - mapLoc->lineSize + xWidth - 1;
			mapLoc->markerLines[lineIndex]->Start.Y = (float)-mapLoc->yloc + mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->Start.Z = (float)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->End.X = (float)-mapLoc->xloc + mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->End.Y = (float)-mapLoc->yloc - mapLoc->lineSize + xWidth - 1;
			mapLoc->markerLines[lineIndex]->End.Z = (float)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->Layer = activeLayer;
			ARGBCOLOR fslColor;
			fslColor.ARGB = 0xFF000000 | (mapLoc->r_color << 16) | (mapLoc->g_color << 8) | (mapLoc->b_color);
			mapLoc->markerLines[lineIndex++]->Color = fslColor;

			// Backslash upper
			mapLoc->markerLines[lineIndex] = InitLine();
			mapLoc->markerLines[lineIndex]->Start.X = (float)-mapLoc->xloc - mapLoc->lineSize + xWidth - 1;
			mapLoc->markerLines[lineIndex]->Start.Y = (float)-mapLoc->yloc - mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->Start.Z = (float)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->End.X = (float)-mapLoc->xloc + mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->End.Y = (float)-mapLoc->yloc + mapLoc->lineSize - xWidth + 1;
			mapLoc->markerLines[lineIndex]->End.Z = (float)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->Layer = activeLayer;
			ARGBCOLOR bsuColor;
			bsuColor.ARGB = 0xFF000000 | (mapLoc->r_color << 16) | (mapLoc->g_color << 8) | (mapLoc->b_color);
			mapLoc->markerLines[lineIndex++]->Color = bsuColor;

			// Forwardslash upper
			mapLoc->markerLines[lineIndex] = InitLine();
			mapLoc->markerLines[lineIndex]->Start.X = (float)-mapLoc->xloc - mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->Start.Y = (float)-mapLoc->yloc + mapLoc->lineSize - xWidth + 1;
			mapLoc->markerLines[lineIndex]->Start.Z = (float)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->End.X = (float)-mapLoc->xloc + mapLoc->lineSize - xWidth + 1;
			mapLoc->markerLines[lineIndex]->End.Y = (float)-mapLoc->yloc - mapLoc->lineSize;
			mapLoc->markerLines[lineIndex]->End.Z = (float)mapLoc->zloc;
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
			mapLoc->markerLines[lineIndex]->Start.X = -mapLoc->xloc + (float)mapLoc->radius * cosf((float)Angle / 180.0f * (float)PI);
			mapLoc->markerLines[lineIndex]->Start.Y = -mapLoc->yloc + (float)mapLoc->radius * sinf((float)Angle / 180.0f * (float)PI);
			mapLoc->markerLines[lineIndex]->Start.Z = (float)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->End.X = -mapLoc->xloc + (float)mapLoc->radius * cosf((float)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f * (float)PI);
			mapLoc->markerLines[lineIndex]->End.Y = -mapLoc->yloc + (float)mapLoc->radius * sinf((float)(Angle + CASTRADIUS_ANGLESIZE) / 180.0f * (float)PI);
			mapLoc->markerLines[lineIndex]->End.Z = (float)mapLoc->zloc;
			mapLoc->markerLines[lineIndex]->Layer = activeLayer;
			ARGBCOLOR rColor;
			rColor.ARGB = 0xFF000000 | (mapLoc->rr_color << 16) | (mapLoc->rg_color << 8) | (mapLoc->rb_color);
			mapLoc->markerLines[lineIndex++]->Color = rColor;
		}
	}

	AddMapSpawnForMapLoc(mapLoc);
}

void AddMapSpawnForMapLoc(MAPLOC* mapLoc)
{
	// Set the index label
	std::string labelStr = std::to_string(mapLoc->index);

	if (!mapLoc->label.empty())
	{
		labelStr.append(mapLoc->label);
	}

	// Create unique "spawnid"
	int mapId = 3000;
	std::map<unsigned long, MAPSPAWN*>::iterator it;

	do
	{
		mapId++;
		it = SpawnMap.find(mapId);
	} while (it != SpawnMap.end() && mapId < 4000);

	// Build the SpawnInfo
	SPAWNINFO* pFakeSpawn = new SPAWNINFO;
	memset(pFakeSpawn, 0, sizeof(SPAWNINFO));
	strcpy_s(pFakeSpawn->DisplayedName, labelStr.c_str());
	pFakeSpawn->X = (float)mapLoc->xloc;
	pFakeSpawn->Y = (float)mapLoc->yloc;
	pFakeSpawn->Z = (float)mapLoc->zloc;
	pFakeSpawn->HPCurrent = 1;
	pFakeSpawn->HPMax = 1;
	pFakeSpawn->Heading = 0;
	pFakeSpawn->mActorClient.Race = 0;
	pFakeSpawn->SpawnID = mapId;

	// Build pMapSpawn and add to SpawnMaps
	MAPSPAWN* pMapSpawn = InitSpawn();
	pMapSpawn->SpawnType = UNTARGETABLE;
	pMapSpawn->pSpawn = pFakeSpawn;
	pMapSpawn->pMapLabel = GenerateLabel(pMapSpawn, CONCOLOR_BLACK);
	pMapSpawn->Explicit = true; // These are a unique "spawn type" but we don't have a way to make a new entry in the enum, so force show just like a /mapshow on a filtered object
	pMapSpawn->pVector = nullptr;
	pMapSpawn->Highlight = false;
	if (pMapSpawn->Marker != 0)
		pMapSpawn->Marker = 0;
	SpawnMap[pFakeSpawn->SpawnID] = pMapSpawn;
	mapLoc->mapSpawn = pMapSpawn;
}

void UpdateMapLocIndexes()
{
	int i = 1;
	for (MAPLOC* loc : maplocOrder)
	{
		loc->index = i++;
	}
}

bool IsFloat(const std::string& in)
{
	std::stringstream sstr(in);
	float f;
	return !((sstr >> std::noskipws >> f).rdstate() ^ std::ios_base::eofbit);
}

CVector3 GetTargetLoc()
{
	return { pLastTarget->pSpawn->X, pLastTarget->pSpawn->Y, pLastTarget->pSpawn->Z };
}

void AddMapLocToList(MAPLOC* loc)
{
	bool found = (std::find(maplocOrder.begin(), maplocOrder.end(), loc) != maplocOrder.end());
	if (!found)
	{
		maplocOrder.push_back(loc);
	}
}