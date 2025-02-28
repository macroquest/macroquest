/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
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
#include "MapObject.h"

#include <mq/Plugin.h>

#include <fmt/format.h>
#include <sstream>

extern MapObject* gpActiveMapObjects;
extern MapViewLabel* gpLabelList;
extern MapViewLabel* gpLabelListTail;

MapViewLine*  pLineList = nullptr;
MapViewLine*  pLineListTail = nullptr;
MapViewLabel* pActualLineList = nullptr;

MapObject* pLastTarget = nullptr;

MapViewLine* pTargetLine = nullptr;

MapCircle CastCircle;
MapCircle SpellCircle;
MapCircle TargetCircle;
MapCircle TargetMeleeCircle;
MapCircle CampCircle;
MapCircle PullCircle;

static MapObject* GetCurrentMapObject()
{
	if (!pCurrentMapLabel)
		return nullptr;

	return GetMapObjectForLabel(pCurrentMapLabel);
}

MapViewLine* InitLine()
{
	MapViewLine* pLine = new MapViewLine;
	pLine->pPrev = nullptr;
	pLine->pNext = pLineList;

	if (pLineList)
		pLineList->pPrev = pLine;
	else
		pLineListTail = pLine;

	pLineList = pLine;
	return pLine;
}

void DeleteLine(MapViewLine* pLine)
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

void MapInit()
{
	CastCircle.Clear();
	SpellCircle.Clear();
	TargetCircle.Clear();
	TargetMeleeCircle.Clear();
	CampCircle.Clear();
	PullCircle.Clear();
}

MapObject* AddSpawn(SPAWNINFO* pNewSpawn, bool ExplicitAllow /* = false */)
{
	return MakeMapObject(pNewSpawn, ExplicitAllow);
}

void RemoveMapObject(MapObject* pMapSpawn)
{
	delete pMapSpawn;
}

bool RemoveSpawn(SPAWNINFO* pSpawn)
{
	MapObject* pMapObject = FindMapObject(pSpawn);
	if (pMapObject)
	{
		RemoveMapObject(pMapObject);
		return true;
	}

	return false;
}

MapObject* AddGroundItem(EQGroundItem* pGroundItem)
{
	return MakeMapObject(pGroundItem);
}

void RemoveGroundItem(EQGroundItem* pGroundItem)
{
	if (MapObject* mapObject = FindMapObject(pGroundItem))
	{
		RemoveMapObject(mapObject);
	}
}

void MapGenerate()
{
	if (!IsOptionEnabled(MapFilter::All))
		return;

	SPAWNINFO* pSpawn = (SPAWNINFO*)pSpawnList;
	while (pSpawn)
	{
		AddSpawn(pSpawn);
		pSpawn = pSpawn->pNext;
	}

	if (IsOptionEnabled(MapFilter::Ground))
	{
		EQGroundItem* pItem = pItemList->Top;
		while (pItem)
		{
			AddGroundItem(pItem);
			pItem = pItem->pNext;
		}
	}

	CreateAllMapLocs();
}

void MapClear()
{
	MapObjects_Clear();

	pLastTarget = nullptr;

	if (pTargetLine)
	{
		DeleteLine(pTargetLine);
		pTargetLine = nullptr;
	}

	CastCircle.Clear();
	SpellCircle.Clear();
	TargetCircle.Clear();
	TargetMeleeCircle.Clear();
	CampCircle.Clear();
	PullCircle.Clear();
}

void MapUpdate()
{
	if (!pLocalPC) return;
	EnterMQ2Benchmark(bmMapRefresh);

	bool bTargetChanged = false;
	MapObject* pOldLastTarget = pLastTarget;

	// Check if current target is obsolete
	if (pLastTarget && pLastTarget->GetSpawn() != pTarget)
	{
		if (!pLastTarget->CanDisplayObject())
		{
			RemoveMapObject(pLastTarget);
		}

		pLastTarget = nullptr;
		bTargetChanged = true;
	}

	// Update target with new
	if (pTarget && IsOptionEnabled(MapFilter::Target))
	{
		if (MapObject* pMapObject = FindMapObject(pTarget))
		{
			pLastTarget = pMapObject;
		}
		else
		{
			pLastTarget = nullptr;
		}

		if (!pLastTarget)
		{
			pLastTarget = AddSpawn(pTarget);
		}
	}

	MapObject* mapObject = gpActiveMapObjects;
	while (mapObject)
	{
		bool forced = (mapObject == pOldLastTarget) && bTargetChanged;
		mapObject->Update(forced);

		if (!mapObject->CanDisplayObject())
		{
			MapObject* pNext = mapObject->GetNext();
			RemoveMapObject(mapObject);
			mapObject = pNext;
		}
		else
		{
			mapObject = mapObject->GetNext();
		}
	}

	if (IsOptionEnabled(MapFilter::CastRadius))
	{
		const MapFilterOption& option = GetMapFilterOption(MapFilter::CastRadius);
		CastCircle.UpdateCircle(option.Color, option.Radius, pLocalPlayer->X, pLocalPlayer->Y, pLocalPlayer->Z);
	}
	else
	{
		CastCircle.Clear();
	}

	if (IsOptionEnabled(MapFilter::CampRadius))
	{
		const MapFilterOption& option = GetMapFilterOption(MapFilter::CampRadius);
		CampCircle.UpdateCircle(option.Color, option.Radius, CampX, CampY, pLocalPlayer->Z);
	}
	else
	{
		CampCircle.Clear();
	}

	if (IsOptionEnabled(MapFilter::PullRadius))
	{
		const MapFilterOption& option = GetMapFilterOption(MapFilter::PullRadius);
		PullCircle.UpdateCircle(option.Color, option.Radius, PullX, PullY, pLocalPlayer->Z);
	}
	else
	{
		PullCircle.Clear();
	}

	if (IsOptionEnabled(MapFilter::SpellRadius))
	{
		const MapFilterOption& option = GetMapFilterOption(MapFilter::SpellRadius);
		SpellCircle.UpdateCircle(option.Color, option.Radius, pLocalPlayer->X, pLocalPlayer->Y, pLocalPlayer->Z);
	}
	else
	{
		SpellCircle.Clear();
	}

	if (IsOptionEnabled(MapFilter::Group) && pLocalPC->Group)
	{
		const MapFilterOption& option = MapFilterOptions[static_cast<size_t>(MapFilter::Group)];

		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			CGroupMember* pMember = pLocalPC->Group->GetGroupMember(i);
			if (!pMember) continue;

			if (MapObject* obj = FindMapObject((SPAWNINFO*)pMember->GetPlayer()))
			{
				obj->SetColor(option.Color);
			}
		}
	}

	if (pLastTarget)
	{
		if (IsOptionEnabled(MapFilter::TargetLine))
		{
			if (!pTargetLine)
			{
				pTargetLine = InitLine();
				pTargetLine->Layer = activeLayer;
			}

			pTargetLine->Color.ARGB = GetMapFilterOption(MapFilter::TargetLine).Color.ToARGB();
			pTargetLine->Start.X = -pLocalPlayer->X;
			pTargetLine->Start.Y = -pLocalPlayer->Y;
			pTargetLine->Start.Z = pLocalPlayer->Z;

			pTargetLine->End.X = -pTarget->X;
			pTargetLine->End.Y = -pTarget->Y;
			pTargetLine->End.Z = pTarget->Z;
		}
		else if (pTargetLine)
		{
			DeleteLine(pTargetLine);
			pTargetLine = nullptr;
		}

		if (IsOptionEnabled(MapFilter::TargetRadius))
		{
			const MapFilterOption& option = GetMapFilterOption(MapFilter::TargetRadius);
			TargetCircle.UpdateCircle(option.Color, option.Radius, pTarget->X, pTarget->Y, pTarget->Z);
		}
		else
		{
			TargetCircle.Clear();
		}

		if (IsOptionEnabled(MapFilter::TargetMelee))
		{
			const MapFilterOption& option = GetMapFilterOption(MapFilter::TargetMelee);

			// At the time of this writing, setting radius > 1 will use target's melee radius. Setting it < 1 will
			// use the player's melee radius. wut.
			float radius = get_melee_range(static_cast<int>(option.Radius) <= 1 ? pControlledPlayer : pTarget, pTarget);

			TargetMeleeCircle.UpdateCircle(option.Color, radius, pTarget->X, pTarget->Y, pTarget->Z);
		}
		else
		{
			TargetMeleeCircle.Clear();
		}
	}
	else
	{
		TargetCircle.Clear();
		TargetMeleeCircle.Clear();

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
	if (gpLabelList)
	{
		pActualLineList = pMapViewWnd->MapView.pLabels;

		if (IsOptionEnabled(MapFilter::NormalLabels))
			gpLabelListTail->pNext = pMapViewWnd->MapView.pLabels;

		pMapViewWnd->MapView.pLabels = gpLabelList;
	}

	if (pLineList)
	{
		pLineListTail->pNext = pMapViewWnd->MapView.pLines;
		pMapViewWnd->MapView.pLines = pLineList;
	}
}

void MapDetach()
{
	if (gpLabelList)
	{
		pMapViewWnd->MapView.pLabels = pActualLineList;
		gpLabelListTail->pNext = nullptr;
	}

	if (pLineList)
	{
		pMapViewWnd->MapView.pLines = pLineListTail->pNext;
		pLineListTail->pNext = nullptr;
	}
}


bool MapSelectTarget()
{
	MAPSPAWN* pMapSpawn = GetCurrentMapObject();
	if (!pMapSpawn)
		return true;

	if (EQGroundItem* pGroundItem = pMapSpawn->GetGroundItem())
	{
		// don't need to do anything else here, this will set our target for us, but give some feedback
		MQGroundSpawn result = GetGroundSpawnByID(pGroundItem->DropID);
		if (result)
		{
			WriteChatf("Item '%s' targeted.", result.DisplayName().c_str());
		}
		else
		{
			MacroError("Couldn't target item from map click.");
		}
	}
	else if (SPAWNINFO* pSpawn = pMapSpawn->GetSpawn())
	{
		uint32_t Flags = pWndMgr->GetKeyboardFlags();
		if (Flags && MapSpecialClickString[Flags][0])
		{
			// This just processes the format string in MapSpecialClickString
			CXStr cmd = pMapSpawn->FormatString(MapSpecialClickString[Flags]);
			EzCommand(cmd.c_str());
		}
		else
		{
			pTarget = pSpawn;
		}
	}

	return IsOptionEnabled(MapFilter::TargetPath);
}

void MapClickLocation(float world_point_y, float world_point_x, const std::vector<float>& z_hits)
{
	if (!pLocalPlayer) return;

	std::vector<float> sorted_z(z_hits);
	std::sort(sorted_z.begin(), sorted_z.end());

	float point_z = pLocalPlayer->Z;
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
	if (Flags && MapLeftClickString[Flags][0])
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
		DoCommand(pLocalPlayer, CommandString);
	}
}

int MapHighlight(MQSpawnSearch* pSearch)
{
	if (!pSearch)
	{
		MapObject* pMapSpawn = gpActiveMapObjects;
		while (pMapSpawn)
		{
			pMapSpawn->SetHighlight(false);
			pMapSpawn = pMapSpawn->GetNext();
		}

		return 0;
	}

	uint32_t Count = 0;
	MAPSPAWN* pMapSpawn = gpActiveMapObjects;

	while (pMapSpawn)
	{
		// update!
		SPAWNINFO* pSpawn = pMapSpawn->GetSpawn();
		if (pSpawn && SpawnMatchesSearch(pSearch, pLocalPlayer, pSpawn))
		{
			pMapSpawn->SetHighlight(true);
			Count++;
		}

		pMapSpawn = pMapSpawn->GetNext();
	}

	return Count;
}

int MapHide(MQSpawnSearch& Search)
{
	MapObject* pMapSpawn = gpActiveMapObjects;
	uint32_t Count = 0;

	while (pMapSpawn)
	{
		SPAWNINFO* pSpawn = pMapSpawn->GetSpawn();
		if (pSpawn && SpawnMatchesSearch(&Search, pLocalPlayer, pSpawn))
		{
			MapObject* pNext = pMapSpawn->GetNext();
			RemoveMapObject(pMapSpawn);
			pMapSpawn = pNext;
			Count++;
		}
		else
		{
			pMapSpawn = pMapSpawn->GetNext();
		}
	}

	return Count;
}

int MapShow(MQSpawnSearch& Search)
{
	SPAWNINFO* pSpawn = (SPAWNINFO*)pSpawnList;
	uint32_t Count = 0;

	while (pSpawn)
	{
		if (FindMapObject(pSpawn)
			== nullptr && SpawnMatchesSearch(&Search, pLocalPlayer, pSpawn))
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
	if (MapObject* pMapSpawn = GetCurrentMapObject())
	{
		if (SPAWNINFO* pSpawn = pMapSpawn->GetSpawn())
		{
			Ret = datatypes::pSpawnType->MakeTypeVar(pSpawn);
			return true;
		}
		else if (EQGroundItem* pGroundItem = pMapSpawn->GetGroundItem())
		{
			Ret.Type = datatypes::pGroundType;
			Ret.Set(MQGroundSpawn(pGroundItem));
			return true;
		}
	}

	return false;
}

MarkerType FindMarker(std::string_view szMark, MarkerType fallback)
{
	if (ci_equals(szMark, "none"))
		return MarkerType::None;
	if (ci_equals(szMark, "triangle"))
		return MarkerType::Triangle;
	if (ci_equals(szMark, "square"))
		return MarkerType::Square;
	if (ci_equals(szMark, "diamond"))
		return MarkerType::Diamond;
	if (ci_equals(szMark, "ring"))
		return MarkerType::Ring;

	return fallback;
}

// make a current timestamp in tenths of a second
int MakeTime()
{
	SYSTEMTIME st;
	::GetSystemTime(&st);
	int lCurrent = 0;
	lCurrent = st.wDay * 24 * 60 * 60 * 10;
	lCurrent += st.wHour * 60 * 60 * 10;
	lCurrent += st.wMinute * 60 * 10;
	lCurrent += st.wSecond * 10;
	lCurrent += (int)(st.wMilliseconds / 100);
	return (lCurrent);
}

void PrintDefaultMapLocSettings()
{
	WriteChatf("%s", fmt::format("MapLoc Defaults: Width:{}, Size:{}, Color:{},{},{}, Radius:{}, Radius Color:{},{},{}",
		gDefaultMapLocParams.width,
		gDefaultMapLocParams.lineSize,
		gDefaultMapLocParams.color.Red, gDefaultMapLocParams.color.Green, gDefaultMapLocParams.color.Blue,
		gDefaultMapLocParams.circleRadius,
		gDefaultMapLocParams.circleColor.Red, gDefaultMapLocParams.circleColor.Green, gDefaultMapLocParams.circleColor.Blue).c_str());
}

void MapLocSyntaxOutput()
{
	SyntaxError("Usage: /maploc [[size 10-200] | [width 1-10] | [color r g b] | [radius <distance>] | [rcolor r g b] | [yloc xloc (zloc) | target]] | [label text]");
	SyntaxError(" -- Omit locs to set defaults");
	SyntaxError(" -- Add label to loc by putting 'label <my text here>' only at end of command");
	SyntaxError("Remove maplocs: /maploc remove [index | [yloc xloc (zloc)]]");
	PrintDefaultMapLocSettings();
}

bool IsFloat(const std::string& in)
{
	std::stringstream sstr(in);
	float f;
	return !((sstr >> std::noskipws >> f).rdstate() ^ std::ios_base::eofbit);
}

void MapRemoveLocation(const char* szLine)
{
	char arg[MAX_STRING];
	std::stringstream ss(szLine);
	ss >> arg; // remove reparsed initial clear

	if (!ss || ss.eof())
	{
		DeleteAllMapLocs();
		WriteChatf("%d MapLoc(s) removed", (int)gMapLocTemplates.size());
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
	MapLocTemplate* loc = nullptr;

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

		sprintf_s(tag, "%s,%s,%s", yloc, xloc, zloc);

		auto maploc = GetMapLocTemplateByTag(tag);

		if (maploc == nullptr)
		{
			SyntaxError("Could not find MapLoc: %s", tag);
			return;
		}

		loc = maploc;
	}
	else // remove by index
	{
		size_t index;
		try
		{
			index = static_cast<size_t>(std::stoul(yloc));
		}
		catch (const std::exception&)
		{
			SyntaxError("Could not parse index: %s", yloc);
			return;
		}

		loc = GetMapLocByIndex((int)index);
		if (!loc)
		{
			WriteChatf("\arRemove loc by index out of bounds: %s", yloc);
			return;
		}

		strcpy_s(tag, loc->GetTag().c_str());
	}

	if (!loc)
	{
		SyntaxError("Could not find MapLoc: %s", tag);
		return;
	}

	DeleteMapLoc(loc);
	WriteChatf("MapLoc removed: Index:%d, loc:%s", loc->GetIndex(), tag);
}
