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

#include "pch.h"
#include "MQ2Main.h"

namespace mq {

CMQ2Alerts CAlerts;

// ***************************************************************************
// Function:    Unload
// Description: Our '/unload' command
//              Triggers the DLL to unload itself
// Usage:       /unload
// ***************************************************************************

void Unload(SPAWNINFO* pChar, char* szLine)
{
	if (!pChar)
		pChar = (SPAWNINFO*)pLocalPlayer;

	bRunNextCommand = true;
	if (GetCurrentMacroBlock())
	{
		EndAllMacros();
	}

	DebugSpew("%s", ToUnloadString);
	WriteChatColor(ToUnloadString, USERCOLOR_DEFAULT);
	gbUnload = true;

	if (IC_MQ2Unload)
	{
		IC_MQ2Unload(GetCurrentProcessId());
	}
}

// ***************************************************************************
// Function:    ListMacros
// Description: Our '/listmacros' command
//              Lists macro files
// Usage:       /listmacros <partial filename>
// ***************************************************************************
void ListMacros(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;

	WIN32_FIND_DATA FileData;
	HANDLE hSearch;
	if (szLine[0] != '\0')
	{
		hSearch = FindFirstFile((mq::internal_paths::Macros + "\\*" + szLine + "*.mac").c_str(), &FileData);
	}
	else
	{
		hSearch = FindFirstFile((mq::internal_paths::Macros + "\\*.mac").c_str(), &FileData);
	}

	if (hSearch == INVALID_HANDLE_VALUE)
	{
		WriteChatColor("Couldn't find any macros", USERCOLOR_DEFAULT);
		return;
	}

	std::vector<std::string> files;

	while (true)
	{
		files.emplace_back(FileData.cFileName);

		if (!FindNextFile(hSearch, &FileData))
			break;
	}

	FindClose(hSearch);

	std::sort(std::begin(files), std::end(files));

	WriteChatColor("Macro list", USERCOLOR_WHO);
	WriteChatColor("----------------", USERCOLOR_WHO);

	for (const std::string& file : files)
		WriteChatColor(file.c_str(), USERCOLOR_WHO);
}

// ***************************************************************************
// Function:    SetError
// Description: Our '/seterror' command
// Usage:       /seterror <clear|errormsg>
// ***************************************************************************
void SetError(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;

	if ((szLine[0] == 0) || (_stricmp(szLine, "clear")))
	{
		gszLastNormalError[0] = 0;
	}
	else
	{
		strcpy_s(gszLastNormalError, szLine);
	}
}

// ***************************************************************************
// Function:    SuperWho
// Description: Our '/who' command
//              Displays a list of spawns in the zone
// Usage:       /who <search string>
// ***************************************************************************

// <name|level|distance|race|class|guild|id>
const char* szSortBy[] =
{
	"level",   // Default sort by
	"name",
	"race",
	"class",
	"distance",
	"guild",
	"id",
	nullptr
};

void SuperWho(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;

	char szArg[MAX_STRING] = { 0 };

	bool Parsing = true;
	bool bConColor = false;

	MQSpawnSearch SearchSpawn;
	ClearSearchSpawn(&SearchSpawn);
	SearchSpawn.SpawnType = PC;

	char szLLine[MAX_STRING] = { 0 };
	strcpy_s(szLLine, szLine);
	_strlwr_s(szLLine);

	if ((!_stricmp(szLine, "all"))
		|| (!_strnicmp(szLine, "all ", 4))
		|| (!_strnicmp(szLine + strlen(szLine) - 4, " all", 4))
		|| (strstr(szLine, " all ")))
	{
		cmdWho(pChar, szLine);
		return;
	}

	char* szRest = szLLine;

	while (Parsing)
	{
		GetArg(szArg, szRest, 1);
		szRest = GetNextArg(szRest, 1);

		if (szArg[0] == 0)
		{
			Parsing = false;
		}
		else if (!strcmp(szArg, "sort"))
		{
			GetArg(szArg, szRest, 1);

			for (int Command = 0; szSortBy[Command]; Command++)
			{
				if (!strcmp(szArg, szSortBy[Command]))
				{
					SearchSpawn.SortBy = static_cast<SearchSortBy>(Command);
					szRest = GetNextArg(szRest, 1);
					break;
				}
			}
		}
		else if (!strcmp(szArg, "concolor"))
		{
			bConColor = true;
		}
		else
		{
			szRest = ParseSearchSpawnArgs(szArg, szRest, &SearchSpawn);
		}
	}

	DebugSpew("SuperWho - filtering %s", SearchSpawn.szName);
	SuperWhoDisplay(pChar, &SearchSpawn, bConColor);
}

// ***************************************************************************
// Function:    MacroPause
// Description: Our '/mqpause' command
//              Pause/resume a macro
// Usage:       /mqpause <off>
//              /mqpause chat [on|off]
// ***************************************************************************
void MacroPause(SPAWNINFO* pChar, char* szLine)
{
	const char* szPause[] = { "off", "on", nullptr };

	bRunNextCommand = true;

	char szArg[MAX_STRING] = { 0 };
	GetArg(szArg, szLine, 1);

	if (!_stricmp(szArg, "chat"))
	{
		char szArg1[MAX_STRING] = { 0 };
		GetArg(szArg1, szLine, 2);
		if (szLine[0] == 0)
		{
			gMQPauseOnChat = !gMQPauseOnChat;
		}
		else
		{
			for (int Command = 0; szPause[Command]; Command++)
			{
				if (!_stricmp(szArg1, szPause[Command]))
				{
					gMQPauseOnChat = Command != 0;
				}
			}
		}

		WritePrivateProfileBool("MacroQuest", "MQPauseOnChat", gMQPauseOnChat, mq::internal_paths::MQini);
		WriteChatf("Macros will %spause while in chat mode.", (gMQPauseOnChat) ? "" : "not ");
		return;
	}

	MQMacroBlockPtr pBlock = GetCurrentMacroBlock();
	if (!pBlock)
	{
		MacroError("You cannot pause a macro when one isn't running.");
		return;
	}

	bool Pause = true;
	for (int Command = 0; szPause[Command]; Command++)
	{
		if (!_stricmp(szArg, szPause[Command]))
		{
			Pause = Command != 0;
		}
	}

	if (szLine[0] != 0)
	{
		WriteChatColor("Syntax: /mqpause [on|off] [chat [on|off]]", USERCOLOR_DEFAULT);
	}
	else
	{
		Pause = !pBlock->Paused;
	}

	if (pBlock->Paused == Pause)
	{
		WriteChatf("Macro is already %s.", (Pause) ? "paused" : "running");
	}
	else
	{
		WriteChatf("Macro is %s.", (Pause) ? "paused" : "running again");
		pBlock->Paused = Pause;
	}
}

// ***************************************************************************
// Function:      KeepKeys
// Description:   Our /keepkeys command. Toggles if /endmacro will keep keys
//                by default.
// 2003-10-08     MacroFiend
// ***************************************************************************
void KeepKeys(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;

	char szArg[MAX_STRING] = { 0 };
	GetArg(szArg, szLine, 1);

	const char* szKeepKeys[] = {
		"off",
		"on",
		nullptr
	};

	if (szArg[0] == 0)
	{
		WriteChatf("Auto-Keep Keys: %s", szKeepKeys[gKeepKeys]);
		return;
	}

	for (int Command = 0; szKeepKeys[Command]; Command++)
	{
		if (!_stricmp(szArg, szKeepKeys[Command]))
		{
			gKeepKeys = Command != 0;

			WriteChatf("Auto-Keep Keys changed to: %s", szKeepKeys[gKeepKeys]);

			WritePrivateProfileBool("MacroQuest", "KeepKeys", gKeepKeys, mq::internal_paths::MQini);
			return;
		}
	}

	SyntaxError("Usage: /keepkeys [on|off]");
}

// ***************************************************************************
// Function:      EngineCommand
// Description:   Allows for switching engines.
// Usage:         /engine <type> <version> [noauto]
// ***************************************************************************
void EngineCommand(SPAWNINFO* pChar, char* szLine)
{
	bool bNoAuto = false;

	if (strstr(szLine, "noauto") != nullptr)
	{
		bNoAuto = true;
	}

	char szBuffer[MAX_STRING] = { 0 };

	// TODO: Fix GetArg and shorten the length of these. Probably 10 & 3 are good.
	// GetArg crashes if you pass it anything except MAX_STRING due to RtlZeroMemory
	char szEngine[MAX_STRING] = { 0 };
	char szVersion[MAX_STRING] = { 0 };
	GetArg(szEngine, szLine, 1);
	GetArg(szVersion, szLine, 2);

	if (strlen(szEngine) == 0)
	{
		SyntaxError("Usage: /engine parser <version> [noauto]");
		return;
	}

	if (!_stricmp(szEngine, "parser"))
	{
		if (strlen(szVersion) == 0)
		{
			SyntaxError("Usage: /engine parser <version> [noauto]");
			return;
		}

		const int iVersion = GetIntFromString(szVersion, 1);

		switch (iVersion)
		{
		case 2:
		case 1:
			gParserVersion = iVersion;
			if (!bNoAuto)
			{
				WritePrivateProfileInt("MacroQuest", "ParserEngine", gParserVersion, mq::internal_paths::MQini);
			}

			WriteChatf("Parser Version %d Enabled", iVersion);
			break;

		default:
			MacroError("Invalid Parser Version (%d) valid versions are 1 or 2.", iVersion);
			break;
		}

		return;
	}

	SyntaxError("Invalid Engine type (%s). Valid types are: parser", szEngine);
}

// ***************************************************************************
// Function:      PluginCommand
// Description:   Our /plugin command.
// ***************************************************************************
void PluginCommand(SPAWNINFO* pChar, char* szLine)
{
	char szBuffer[MAX_STRING] = { 0 };
	char szName[MAX_STRING] = { 0 };

	GetArg(szName, szLine, 1);
	char* szCommand = GetNextArg(szLine);

	if (!_stricmp(szName, "list"))
	{
		MQPlugin* pLoop = pPlugins;
		int Count = 0;

		WriteChatColor("Active Plugins", USERCOLOR_WHO);
		WriteChatColor("--------------------------", USERCOLOR_WHO);

		while (pLoop)
		{
			// TODO: Remove mq2ic from plugin list
			if (!ci_equals(pLoop->szFilename, "mq2ic"))
			{
				WriteChatColorf("%s", USERCOLOR_WHO, pLoop->szFilename);
				Count++;
			}
			pLoop = pLoop->pNext;
		}

		if (Count == 0)
		{
			WriteChatColor("No Plugins defined.", USERCOLOR_WHO);
		}
		else
		{
			WriteChatColorf("%d Plugin%s displayed.", USERCOLOR_WHO, Count, (Count == 1) ? "" : "s");
		}
		return;
	}

	if (szName[0] == 0)
	{
		SyntaxError("Usage: /plugin name [load/unload/toggle] [noauto], or /plugin list");
		return;
	}

	if (!_strnicmp(szCommand, "unload", 6) || ci_find_substr(szCommand, "toggle") != -1 && IsPluginLoaded(szName))
	{
		// TODO: Remove mq2ic from plugin list
		if (!ci_equals(szName, "mq2ic") && UnloadMQ2Plugin(szName))
		{
			WriteChatf("Plugin '%s' unloaded.", szName);

			if (!strstr(szCommand, "noauto"))
			{
				WritePrivateProfileBool("Plugins", szName, false, mq::internal_paths::MQini);
			}
		}
		else
		{
			MacroError("Plugin '%s' not found.", szName);
		}
	}
	else
	{
		// TODO: Remove mq2ic from plugin list
		if (!ci_equals(szName, "mq2ic") && LoadMQ2Plugin(szName))
		{
			WriteChatf("Plugin '%s' loaded.", szName);

			if (_stricmp(szCommand, "noauto"))
			{
				WritePrivateProfileBool("Plugins", szName, true, mq::internal_paths::MQini);
			}
		}
		else
		{
			MacroError("Plugin '%s' could not be loaded.", szName);
		}
	}
}

// ***************************************************************************
// Function:    Invoke
// Description: '/invoke' command
// Purpose:     Adds the ability to invoke Methods
// Example      /invoke ${Target.DoAssist}
//              will execute the DoAssist Method of the Spawn TLO
// Author:      EqMule
// ***************************************************************************
void InvokeCmd(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;
}

// ***************************************************************************
// Function:    SquelchCommand
// Description: Our '/squelch' command
// Usage:       /squelch <command>
// ***************************************************************************
void SquelchCommand(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /squelch <command>");
		return;
	}

	bool Temp = gFilterMQ;
	gFilterMQ = true;
	DoCommand(pChar, szLine);
	gFilterMQ = Temp;
}

// ***************************************************************************
// Function:    Items
// Description: Our '/items' command
//              Lists ground item info
// Usage:       /items <filter>
// ***************************************************************************
void Items(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;

	if (!pItemList)
		return;

	struct iteminfo
	{
		std::string name;
		int angle;
	};
	std::map<float, iteminfo> itemsMap;

	if (EQGroundItem* pItem = pItemList->Top)
	{
		char szName[MAX_STRING] = { 0 };

		while (pItem)
		{
			GetFriendlyNameForGroundItem(pItem, szName, sizeof(szName));

			DebugSpew("   Item found - %d: DropID %d %s (%s)", pItem->pContents, pItem->DropID, szName, pItem->Name);

			if (szLine[0] == 0 || ci_find_substr(szName, szLine) != -1)
			{
				float Distance = Get3DDistance(
					pChar->X, pChar->Y, pChar->Z,
					pItem->X, pItem->Y, pItem->Z);
				int Angle = static_cast<int>((atan2f(pChar->X - pItem->X, pChar->Y - pItem->Y) * 180.0f / PI + 360.0f) / 22.5f + 0.5f) % 16;

				itemsMap.emplace(Distance, iteminfo{ szName, Angle });
			}

			pItem = pItem->pNext;
		}
	}

	RealEstateManagerClient& manager = RealEstateManagerClient::Instance();
	EQPlacedItemManager& pPIM = EQPlacedItemManager::Instance();

	for (EQPlacedItem* pObj = pPIM.Top; pObj != nullptr; pObj = pObj->pNext)
	{
		const RealEstateItemClient* pRealEstateItem = manager.GetItemByRealEstateAndItemIds(pObj->RealEstateID, pObj->RealEstateItemID);
		if (!pRealEstateItem)
			continue;

		CONTENTS* pCont = pRealEstateItem->Object.pItemBase.get();
		if (!pCont)
			continue;

		ITEMINFO* pItem = pCont->GetItemDefinition();
		if (!pItem)
			continue;

		DebugSpew("   Item found - %d: DropID %d %s", pObj->RealEstateID, pObj->RealEstateItemID, pItem->Name);

		if (szLine[0] == 0 || ci_find_substr(pItem->Name, szLine) != -1)
		{
			float Distance = Get3DDistance(
				pChar->X, pChar->Y, pChar->Z,
				pObj->X, pObj->Y, pObj->Z);

			int Angle = static_cast<int>((atan2f(pChar->X - pObj->X, pChar->Y - pObj->Y) * 180.0f / PI + 360.0f) / 22.5f + 0.5f) % 16;

			std::string name = fmt::format("[{0}] {1} {2} ({3})",
				pObj->RealEstateItemID, pItem->Name, pObj->Name, pRealEstateItem->OwnerInfo.OwnerName);

			itemsMap.emplace(Distance, iteminfo{ std::move(name), Angle });
		}
	}

	if (itemsMap.empty())
	{
		WriteChatColor("No items found.");
	}
	else
	{
		WriteChatColor("Items on the ground:");
		WriteChatColor("---------------------------");

		for (auto& item : itemsMap)
		{
			WriteChatf("%s: %1.2f away to the %s", item.second.name.c_str(), item.first, szHeading[item.second.angle]);
		}

		WriteChatf("%d item%s found.", itemsMap.size(), (itemsMap.size() == 1) ? "" : "s");
	}
}

// ***************************************************************************
// Function:    ItemTarget
// Description: Our '/itemtarget' command
//              Lists ground item info
// Usage:       /itemtarget <text>
// ***************************************************************************
void ItemTarget(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;

	if (!szLine) return;

	if (!pItemList)
		return;

	char Arg1[MAX_STRING] = { 0 };
	GetArg(Arg1, szLine, 1);
	_strlwr_s(Arg1);

	char Arg2[MAX_STRING] = { 0 };
	GetArg(Arg2, szLine, 2);

	ZeroMemory(&EnviroTarget, sizeof(EnviroTarget));
	ZeroMemory(&GroundObject, sizeof(GroundObject));

	pGroundTarget = nullptr;

	if (EQGroundItem* pItem = pItemList->Top)
	{
		char szName[MAX_STRING] = { 0 };
		float cDistance = 100000.0f;
		SPAWNINFO tSpawn = { 0 };

		while (pItem)
		{
			GetFriendlyNameForGroundItem(pItem, szName, sizeof(szName));
			_strlwr_s(szName);

			if (((szLine[0] == '\0') || (strstr(szName, Arg1))))
			{
				if (((gZFilter >= 10000.0f) || ((pItem->Z <= pChar->Z + gZFilter) && (pItem->Z >= pChar->Z - gZFilter))))
				{
					ZeroMemory(&tSpawn, sizeof(tSpawn));
					strcpy_s(tSpawn.Name, szName);
					strcpy_s(tSpawn.DisplayedName, szName);
					tSpawn.Y = pItem->Y;
					tSpawn.X = pItem->X;
					tSpawn.Z = pItem->pSwitch->Z;
					tSpawn.Type = SPAWN_NPC;
					tSpawn.HPCurrent = 1;
					tSpawn.HPMax = 1;
					tSpawn.Heading = pItem->Heading;
					tSpawn.mActorClient.Race = pItem->DropID;
					tSpawn.StandState = STANDSTATE_STAND; //im using this for /clicked left item -eqmule
					float Distance = Get3DDistance(pChar->X, pChar->Y, pChar->Z, tSpawn.X, tSpawn.Y, tSpawn.Z);
					if (Distance < cDistance) {
						CopyMemory(&EnviroTarget, &tSpawn, sizeof(EnviroTarget));
						cDistance = Distance;
						pGroundTarget = pItem;
					}
				}
			}

			pItem = pItem->pNext;
		}
	}

	if (pGroundTarget)
	{
		GroundObject.Type = GO_GroundType;
		GroundObject.pGroundItem = pGroundTarget;
	}
	else
	{
		float cDistance = 100000.0f;
		SPAWNINFO tSpawn = { 0 };

		RealEstateManagerClient& manager = RealEstateManagerClient::Instance();
		if (&manager)
		{
			if (EQPlacedItemManager* pPIM = &EQPlacedItemManager::Instance())
			{
				char szName[MAX_STRING] = { 0 };
				for (EQPlacedItem* pObj = pPIM->Top; pObj != nullptr; pObj = pObj->pNext)
				{
					const RealEstateItemClient* pRealEstateItem = manager.GetItemByRealEstateAndItemIds(pObj->RealEstateID, pObj->RealEstateItemID);
					if (pRealEstateItem)
					{
						if (CONTENTS* pCont = pRealEstateItem->Object.pItemBase.get())
						{
							if (ITEMINFO* pItem = pCont->GetItemDefinition())
							{
								strcpy_s(szName, pItem->Name);
								_strlwr_s(szName);

								if (((szLine[0] == '\0') || (strstr(szName, Arg1)) || (strstr(szName, Arg1))))
								{
									if (((gZFilter >= 10000.0f) || ((pObj->Z <= pChar->Z + gZFilter) && (pObj->Z >= pChar->Z - gZFilter))))
									{
										ZeroMemory(&tSpawn, sizeof(tSpawn));
										strcpy_s(tSpawn.Name, pItem->Name);
										PEQSWITCH si = (PEQSWITCH)pObj->pActor;
										strcpy_s(tSpawn.DisplayedName, pItem->Name);
										tSpawn.Y = pObj->Y;
										tSpawn.X = pObj->X;
										tSpawn.Z = pObj->Z;
										tSpawn.Type = SPAWN_NPC;
										tSpawn.HPCurrent = 1;
										tSpawn.HPMax = 1;
										tSpawn.Heading = pObj->Heading;
										tSpawn.mActorClient.Race = pObj->RealEstateItemID;
										tSpawn.StandState = STANDSTATE_STAND; // im using this for /clicked left item -eqmule
										float Distance = Get3DDistance(pChar->X, pChar->Y, pChar->Z, tSpawn.X, tSpawn.Y, tSpawn.Z);
										if (Distance < cDistance)
										{
											CopyMemory(&EnviroTarget, &tSpawn, sizeof(EnviroTarget));
											cDistance = Distance;
											GroundObject.Type = GO_ObjectType;
											GroundObject.ObjPtr = (void*)pObj;
										}
									}
								}
							}
						}
					}
				}
			}
		}

		if (GroundObject.Type == GO_ObjectType)
		{
			EQPlacedItem* ObjPtr = (EQPlacedItem*)GroundObject.ObjPtr;

			// ok so its not actually a grounditem, we need to fake that for the tlo to be work
			// we do this because I want people to be able to use ${Ground} in their macros and not worry about if its an object or not.
			// also I want people to not have to update their macros.
			// this should make older tradeskill macros for example work in guild halls... -eqmule

			GroundObject.GroundItem.DropID = ObjPtr->RealEstateItemID;
			GroundObject.GroundItem.DropSubID = ObjPtr->RealEstateID;
			GroundObject.GroundItem.Expires = 0;
			GroundObject.GroundItem.Heading = ObjPtr->Heading;
			GroundObject.GroundItem.pContents = nullptr;
			if (EnviroTarget.DisplayedName[0] != '\0')
			{
				strcpy_s(GroundObject.GroundItem.Name, EnviroTarget.DisplayedName);
			}
			else
			{
				strcpy_s(GroundObject.GroundItem.Name, ObjPtr->Name);
			}
			GroundObject.GroundItem.Pitch = ObjPtr->Angle;
			GroundObject.GroundItem.pNext = 0;
			GroundObject.GroundItem.pPrev = 0;
			GroundObject.GroundItem.pSwitch = (PEQSWITCH)ObjPtr->pActor;
			GroundObject.GroundItem.Roll = ObjPtr->Roll;
			GroundObject.GroundItem.Scale = ObjPtr->Scale;
			GroundObject.GroundItem.Weight = 0;
			GroundObject.GroundItem.X = ObjPtr->X;
			GroundObject.GroundItem.Y = ObjPtr->Y;
			GroundObject.GroundItem.Z = ObjPtr->Z;
			GroundObject.GroundItem.ZoneID = ((SPAWNINFO*)pLocalPlayer)->GetZoneID() & 0x7FFF;
			pGroundTarget = &GroundObject.GroundItem;
		}
	}

	if (EnviroTarget.DisplayedName[0] != 0)
	{
		WriteChatf("Item '%s' targeted.", EnviroTarget.DisplayedName);
	}
	else
	{
		MacroError("Couldn't find '%s' to target.", szLine);
	}
}


// ***************************************************************************
// Function:    Doors
// Description: Our '/doors' command
//              Lists door info
// Usage:       /doors <filter>
// ***************************************************************************
void Doors(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;

	if (!pSwitchMgr) return;

	struct doorinfo
	{
		std::string name;
		int angle;
		int ID;
	};
	std::map<float, doorinfo> doorsMap;

	DOORTABLE* pDoorTable = (DOORTABLE*)pSwitchMgr;

	for (int Count = 0; Count < pDoorTable->NumEntries; Count++)
	{
		DOOR* pDoor = pDoorTable->pDoor[Count];

		if (szLine[0] == 0 || ci_find_substr(pDoor->Name, szLine))
		{
			float distance = Get3DDistance(pChar->X, pChar->Y, pChar->Z, pDoor->X, pDoor->Y, pDoor->Z);
			int angle = static_cast<int>((atan2f(pChar->X - pDoor->X, pChar->Y - pDoor->Y) * 180.0f / PI + 360.0f) / 22.5f + 0.5f) % 16;

			doorsMap.emplace(distance, doorinfo{ pDoor->Name, angle, pDoor->ID });
		}
	}

	if (doorsMap.empty())
	{
		WriteChatColor("No Doors found.");
	}
	else
	{
		WriteChatColor("Doors:");
		WriteChatColor("---------------------------");

		for (auto& door : doorsMap)
		{
			WriteChatf("%d: %s: %1.2f away to the %s", door.second.ID,
				door.second.name.c_str(), door.first, szHeading[door.second.angle]);
		}

		WriteChatf("%d door%s found.", doorsMap.size(), (doorsMap.size() == 1) ? "" : "s");
	}
}

// ***************************************************************************
// Function:    DoorTarget
// Description: Our '/doortarget' command
//              Targets the nearest specified door
// Usage:       /doortarget <text>
// ***************************************************************************
void DoorTarget(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;

	if (!pSwitchMgr) return;

	// FIXME: Do not ZeroMemory SPAWNINFO
	ZeroMemory(&DoorEnviroTarget, sizeof(DoorEnviroTarget));
	pDoorTarget = nullptr;

	char Arg1[MAX_STRING] = { 0 };
	GetArg(Arg1, szLine, 1);

	char Arg2[MAX_STRING] = { 0 };
	GetArg(Arg2, szLine, 2);

	if (!_stricmp(Arg1, "id"))
	{
		if (Arg2[0] == 0)
		{
			MacroError("DoorTarget: id specified but no number provided.");
			return;
		}

		int ID = GetIntFromString(Arg2, 0);
		GetArg(Arg2, szLine, 3);

		for (int Count = 0; Count < pSwitchMgr->NumEntries; Count++)
		{
			EQSwitch* pSwitch = pSwitchMgr->Switches[Count];

			if (pSwitch->ID == ID)
			{
				strcpy_s(DoorEnviroTarget.Name, pSwitch->Name);
				strcpy_s(DoorEnviroTarget.DisplayedName, pSwitch->Name);
				DoorEnviroTarget.Y = pSwitch->Y;
				DoorEnviroTarget.X = pSwitch->X;
				DoorEnviroTarget.Z = pSwitch->Z;
				DoorEnviroTarget.Heading = pSwitch->Heading;
				DoorEnviroTarget.Type = SPAWN_NPC;
				DoorEnviroTarget.HPCurrent = 1;
				DoorEnviroTarget.HPMax = 1;
				pDoorTarget = pSwitch;
				break;
			}
		}
	}
	else
	{
		float cDistance = 100000.0f;

		for (int Count = 0; Count < pSwitchMgr->NumEntries; Count++)
		{
			EQSwitch* pSwitch = pSwitchMgr->Switches[Count];

			// Match against the name if it is within the z filter (or if the z filter is disabled)
			if ((Arg1[0] == 0 || ci_find_substr(pSwitch->Name, Arg1) == 0)
				&& (gZFilter >= 10000.0f || (pSwitch->Z <= pChar->Z + gZFilter && pSwitch->Z >= pChar->Z - gZFilter)))
			{
				// FIXME: Do not ZeroMemory SPAWNINFO
				SPAWNINFO tSpawn;
				ZeroMemory(&tSpawn, sizeof(tSpawn));
				strcpy_s(tSpawn.Name, pSwitch->Name);
				strcpy_s(tSpawn.DisplayedName, pSwitch->Name);
				tSpawn.Y = pSwitch->Y;
				tSpawn.X = pSwitch->X;
				tSpawn.Z = pSwitch->Z;
				tSpawn.Type = SPAWN_NPC;
				tSpawn.HPCurrent = 1;
				tSpawn.HPMax = 1;
				tSpawn.Heading = pSwitch->Heading;
				float Distance = Distance3DToSpawn(pChar, &tSpawn);

				if (Distance < cDistance)
				{
					CopyMemory(&DoorEnviroTarget, &tSpawn, sizeof(DoorEnviroTarget));
					pDoorTarget = pSwitch;
					cDistance = Distance;
				}
			}
		}
	}

	if (pDoorTarget && DoorEnviroTarget.Name[0] != '\0')
	{
		WriteChatf("Door %d '%s' targeted.", pDoorTarget->ID, DoorEnviroTarget.Name);
	}
	else
	{
		MacroError("Couldn't find door '%s' to target.", szLine);
	}
}

// ***************************************************************************
// Function:    CharInfo
// Description: Our '/charinfo' command
//              Displays character bind points
// Usage:       /charinfo
// ***************************************************************************
void CharInfo(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;

	if (gFilterMacro == FILTERMACRO_NONE)
		cmdCharInfo(pChar, szLine);

	if (CHARINFO* pCharInfo = GetCharInfo())
	{
		DoCommand(pCharInfo->pSpawn, "/charinfo");

		if (PcProfile* pProfile = GetPcProfile())
		{
			WriteChatf("The location of your bind is: %1.2f, %1.2f, %1.2f",
				pProfile->BoundLocations[0].ZoneBoundX, pProfile->BoundLocations[0].ZoneBoundY, pProfile->BoundLocations[0].ZoneBoundZ);
		}
	}
}

// ***************************************************************************
// Function:    ShowSpellSlotInfo
// Description: Our '/SpellSlotInfo' command
// Usage:       /SpellSlotInfo [#|"spell name"]
// ***************************************************************************
void SpellSlotInfo(SPAWNINFO* pChar, char* szLine)
{
	SPELL* pSpell = nullptr;

	char szArg1[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);

	IsNumber(szArg1) ? pSpell = GetSpellByID(GetIntFromString(szArg1, 0)) : pSpell = GetSpellByName(szLine);
	if (!pSpell)
	{
		WriteChatf("Usage: /SpellSlotInfo [#|\"spell name\"]");
		return;
	}

	char szBuff[MAX_STRING] = { 0 };
	char szTemp[MAX_STRING] = { 0 };

	WriteChatf("\ay%s\ax (ID: %d)", pSpell->Name, pSpell->ID);
	for (int i = 0; i < GetSpellNumEffects(pSpell); i++)
	{
		szBuff[0] = szTemp[0] = 0;
		strcat_s(szBuff, ParseSpellEffect(pSpell, i, szTemp, sizeof(szTemp)));

		if (szBuff[0] != 0)
			WriteChatf("%s", szBuff);
	}
}

// ***************************************************************************
// Function:    MemSpell
// Description: Our '/MemSpell' command
// Usage:       /MemSpell gem# "spell name"
// ***************************************************************************
void MemSpell(SPAWNINFO* pSpawn, char* szLine)
{
	if (!pSpellBookWnd)
		return;

	CHARINFO* pCharInfo = GetCharInfo();
	if (!pCharInfo)
		return;

	PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return;

	char szGem[MAX_STRING] = { 0 };
	GetArg(szGem, szLine, 1);

	int Gem = GetIntFromString(szGem, 0) - 1;
	if (Gem < 0 || Gem >= NUM_SPELL_GEMS) return;

	char SpellName[MAX_STRING] = { 0 };
	GetArg(SpellName, szLine, 2);

	SPELL* pSpell = nullptr;
	for (int index = 0; index < NUM_BOOK_SLOTS; index++)
	{
		if (SPELL* pTempSpell = GetSpellByID(pProfile->SpellBook[index]))
		{
			// exact name match only
			if (ci_equals(pTempSpell->Name, SpellName))
			{
				pSpell = pTempSpell;
				break;
			}
		}
	}

	if (!pSpell)
		return; // did not find spell

	if (pSpell->ClassLevel[pSpawn->mActorClient.Class] > pSpawn->Level)
		return; // level requirement not met

	int loadout[NUM_SPELL_GEMS];
	for (int sp = 0; sp < NUM_SPELL_GEMS; sp++)
		loadout[sp] = -1;
	loadout[Gem] = pSpell->ID;

	pSpellBookWnd->MemorizeSet(loadout, NUM_SPELL_GEMS);
}

// ***************************************************************************
// Function:    selectitem
// Description: Our '/selectitem' command
// Usage:       /selectitem Name
//
// will select the specified item in your inventory if merchantwindow is open
// ***************************************************************************
void SelectItem(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = false;

	if (!pMerchantWnd)
		return;

	char szBuffer[MAX_STRING] = { 0 };
	GetArg(szBuffer, szLine, 1);

	if (szBuffer[0])
	{
		char* pName = &szBuffer[0];
		bool bExact = false;

		if (*pName == '=')
		{
			bExact = true;
			pName++;
		}

		if (CHARINFO * pCharInfo = GetCharInfo())
		{
			if (CMerchantWnd* pmercho = (CMerchantWnd*)pMerchantWnd)
			{
				if (pmercho->IsVisible())
				{
					ITEMINFO* pItem = nullptr;
					CONTENTS* pCont = nullptr;
					bool bFound = false;

					if (CONTENTS* pCont = FindItemByName(szBuffer, bExact))
					{
						ItemGlobalIndex To;
						To.Location = pCont->GetGlobalIndex().GetLocation();
						To.Index.SetSlot(0, pCont->GetGlobalIndex().GetTopSlot());
						To.Index.SetSlot(1, pCont->GetGlobalIndex().GetIndex().GetSlot(1));

						pmercho->SelectBuySellSlot(To, To.GetTopSlot());
					}
					else
					{
						WriteChatf("/selectitem Could NOT find %s in your inventory to select.\n"
							"Use /invoke ${Merchant.SelectItem[%s]} if you want to select an item in the merchants inventory.", szBuffer, szBuffer);
					}
				}
			}
		}
	}
	else
	{
		WriteChatf("/selectitem works when a merchantwindow is open, it will select a item from YOUR inventory.\n"
			"Use /invoke ${Merchant.SelectItem[some item]} if you want to select an item in the MERCHANTS inventory.");
		WriteChatf(R"(Usage: /selectitem "some item in YOUR inventory", use "=some item in YOUR inventory" for EXACT name search.)");
	}
}

// ***************************************************************************
// Function:    buyitem
// Description: Our '/buyitem' command
// Usage:       /buyitem Quantity#
//
// uses void CMerchantWnd::RequestBuyItem(int)
// will buy the specified quantity of the currently selected item
// ***************************************************************************
void BuyItem(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = false;

	if (!pMerchantWnd) return;

	char szQty[MAX_STRING] = { 0 };
	CHARINFO* pCharInfo = nullptr;

	if (!GetCharInfo() || !pMerchantWnd->pSelectedItem)
		return;

	if (pMerchantWnd->PageHandlers[RegularMerchantPage])
	{
		GetArg(szQty, szLine, 1);
		int Qty = GetIntFromString(szQty, 0);
		if (Qty < 1) return;

		pMerchantWnd->PageHandlers[RegularMerchantPage]->RequestGetItem(Qty);
	}
}

// ***************************************************************************
// Function:    sellitem
// Description: Our '/sellitem' command
// Usage:       /sellitem Quantity#
// uses private: void __thiscall CMerchantWnd::RequestSellItem(int)
// will sell the specified quantity of the currently selected item
// ***************************************************************************
void SellItem(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = false;

	if (!pMerchantWnd) return;

	char szQty[MAX_STRING] = { 0 };
	CHARINFO* pCharInfo = nullptr;

	if (!GetCharInfo() || !pMerchantWnd->pSelectedItem)
		return;

	if (pMerchantWnd->PageHandlers[RegularMerchantPage])
	{
		GetArg(szQty, szLine, 1);
		int Qty = GetIntFromString(szQty, 0);
		if (Qty < 1) return;

		pMerchantWnd->PageHandlers[RegularMerchantPage]->RequestPutItem(Qty);
	}
}

// ***************************************************************************
// Function:    MacroBeep
// Description: Our '/beep' command
//              Beeps the system speaker
// Usage:       /beep
// ***************************************************************************
void MacroBeep(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;

	char szArg[MAX_STRING] = { 0 };

	GetArg(szArg, szLine, 1);
	if (szArg[0] == '\0')
		Beep(0x500, 250);
	else
		PlaySound(szArg, nullptr, SND_ASYNC);
}

// ***************************************************************************
// Function:    SWhoFilter
// Description: Our '/whofilter' command
//              Sets SuperWho filters
// Usage:       /whofilter [options]
// ***************************************************************************

void SetDisplaySWhoFilter(bool& bToggle, const char* szFilter, const char* szToggle)
{
	if (!_stricmp(szToggle, "on"))
		bToggle = true;
	else if (!_stricmp(szToggle, "off"))
		bToggle = false;

	WriteChatf("%s is: %s", szFilter, bToggle ? "on" : "off");
	WritePrivateProfileBool("SWho Filter", szFilter, bToggle, mq::internal_paths::MQini);
}

void SWhoFilter(SPAWNINFO* pChar, char* szLine)
{
	char szArg[MAX_STRING] = { 0 };
	GetArg(szArg, szLine, 1);

	char szToggle[MAX_STRING] = { 0 };
	GetArg(szToggle, szLine, 2);

	if (!_stricmp(szArg, "Lastname"))
	{
		SetDisplaySWhoFilter(gFilterSWho.Lastname, "Lastname", szToggle);
	}
	else if (!_stricmp(szArg, "Class"))
	{
		SetDisplaySWhoFilter(gFilterSWho.Class, "Class", szToggle);
	}
	else if (!_stricmp(szArg, "Race"))
	{
		SetDisplaySWhoFilter(gFilterSWho.Race, "Race", szToggle);
	}
	else if (!_stricmp(szArg, "Body"))
	{
		SetDisplaySWhoFilter(gFilterSWho.Body, "Body", szToggle);
	}
	else if (!_stricmp(szArg, "Level"))
	{
		SetDisplaySWhoFilter(gFilterSWho.Level, "Level", szToggle);
	}
	else if (!_stricmp(szArg, "GM"))
	{
		SetDisplaySWhoFilter(gFilterSWho.GM, "GM", szToggle);
	}
	else if (!_stricmp(szArg, "Guild"))
	{
		SetDisplaySWhoFilter(gFilterSWho.Guild, "Guild", szToggle);
	}
	else if (!_stricmp(szArg, "LD"))
	{
		SetDisplaySWhoFilter(gFilterSWho.LD, "LD", szToggle);
	}
	else if (!_stricmp(szArg, "Sneak"))
	{
		SetDisplaySWhoFilter(gFilterSWho.Sneak, "Sneak", szToggle);
	}
	else if (!_stricmp(szArg, "LFG"))
	{
		SetDisplaySWhoFilter(gFilterSWho.LFG, "LFG", szToggle);
	}
	else if (!_stricmp(szArg, "NPCTag"))
	{
		SetDisplaySWhoFilter(gFilterSWho.NPCTag, "NPCTag", szToggle);
	}
	else if (!_stricmp(szArg, "SpawnID"))
	{
		SetDisplaySWhoFilter(gFilterSWho.SpawnID, "SpawnID", szToggle);
	}
	else if (!_stricmp(szArg, "Trader"))
	{
		SetDisplaySWhoFilter(gFilterSWho.Trader, "Trader", szToggle);
	}
	else if (!_stricmp(szArg, "AFK"))
	{
		SetDisplaySWhoFilter(gFilterSWho.AFK, "AFK", szToggle);
	}
	else if (!_stricmp(szArg, "Anon"))
	{
		SetDisplaySWhoFilter(gFilterSWho.Anon, "Anon", szToggle);
	}
	else if (!_stricmp(szArg, "Distance"))
	{
		SetDisplaySWhoFilter(gFilterSWho.Distance, "Distance", szToggle);
	}
	else if (!_stricmp(szArg, "Light"))
	{
		SetDisplaySWhoFilter(gFilterSWho.Light, "Light", szToggle);
	}
	else if (!_stricmp(szArg, "Holding"))
	{
		SetDisplaySWhoFilter(gFilterSWho.Holding, "Holding", szToggle);
	}
	else if (!_stricmp(szArg, "ConColor"))
	{
		SetDisplaySWhoFilter(gFilterSWho.ConColor, "ConColor", szToggle);
	}
	else if (!_stricmp(szArg, "invisible"))
	{
		SetDisplaySWhoFilter(gFilterSWho.Invisible, "Invisible", szToggle);
	}
	else
	{
		SyntaxError("Usage: /whofilter <lastname|class|race|body|level|gm|guild|ld|sneak|lfg|npctag|spawnid|trader|afk|anon|distance|light|holding|concolor|invisible> [on|off]");
	}
}

// ***************************************************************************
// Function:    Filter
// Description: Our '/filter' command
//              Adds 'skills' to the built-in filter command
// Usage:       /filter skills
// ***************************************************************************

const char* szFilterSkills[] = {
	"all",
	"increase",
	"none",
	nullptr
};

const char* szFilterMacro[FILTERMACRO_MAX] = {
	"all",
	"enhanced",
	"none",
	"macroended",
};

const char* szFilterTarget[] = {
	"off",
	"on",
	nullptr
};

const char* szUseChat[] = {
	"off",
	"on",
	nullptr
};

void Filter(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;

	char szArg[MAX_STRING] = { 0 };

	char* szRest = szLine;
	GetArg(szArg, szRest, 1);
	szRest = GetNextArg(szRest, 1);

	if (szArg[0] == 0)
	{
		cmdFilter(pChar, szArg);
		if (gFilterMacro != FILTERMACRO_NONE)
			WriteChatColor("skills, target, money, encumber, food, name, zrange, macros, mq, debug");
		return;
	}

	if (!_stricmp("skills", szArg))
	{
		if (szRest[0] == 0)
		{
			WriteChatf("Filtering of skills is set to: %s",
				(gFilterSkillsIncrease) ? "None" : (gFilterSkillsAll) ? "Increase" : "All");
			return;
		}

		for (int Command = 0; szFilterSkills[Command]; Command++)
		{
			if (!_stricmp(szRest, szFilterSkills[Command]))
			{
				gFilterSkillsAll = (0 != Command);
				gFilterSkillsIncrease = (2 == Command);

				WriteChatf("Filtering of skills changed to: %s",
					(gFilterSkillsIncrease) ? "None" : (gFilterSkillsAll) ? "Increase" : "All");

				WritePrivateProfileBool("MacroQuest", "FilterSkills", Command, mq::internal_paths::MQini);
				return;
			}
		}

		SyntaxError("Usage: /filter skills [all|increase|none]");
		return;
	}

	if (!_stricmp("macros", szArg))
	{
		if (szRest[0] == 0)
		{
			WriteChatf("Filtering of macros is set to: %s", szFilterMacro[gFilterMacro]);
			return;
		}

		for (int Command = FILTERMACRO_ALL; Command != FILTERMACRO_MAX; ++Command)
		{
			if (!_stricmp(szRest, szFilterMacro[Command]))
			{
				gFilterMacro = (eFilterMacro)Command;

				WriteChatf("Filtering of macros changed to: %s", szFilterMacro[gFilterMacro]);

				WritePrivateProfileInt("MacroQuest", "FilterMacro", gFilterMacro, mq::internal_paths::MQini);
				return;
			}
		}

		SyntaxError("Usage: /filter macros [all|enhanced|none|macroended]");
		return;
	}

	if (!_stricmp("mq", szArg))
	{
		if (szRest[0] == 0)
		{
			WriteChatf("Filtering of MQ is set to: %s", szUseChat[gFilterMQ]);
			return;
		}

		for (int Command = 0; szUseChat[Command]; Command++)
		{
			if (!_stricmp(szRest, szUseChat[Command]))
			{
				gFilterMQ = Command != 0;

				WriteChatf("Filtering of MQ changed to: %s", szUseChat[gFilterMQ]);

				WritePrivateProfileBool("MacroQuest", "FilterMQ", gFilterMQ, mq::internal_paths::MQini);
				return;
			}
		}

		SyntaxError("Usage: /filter mq [on|off]");
		return;
	}

	if (!_stricmp("mq2data", szArg))
	{
		if (szRest[0] == 0)
		{
			WriteChatf("Filtering of MQ2Data Errors is set to: %s", szUseChat[gFilterMQ2DataErrors]);
			return;
		}

		for (int Command = 0; szUseChat[Command]; Command++)
		{
			if (!_stricmp(szRest, szUseChat[Command]))
			{
				gFilterMQ2DataErrors = Command != 0;

				WriteChatf("Filtering of MQ changed to: %s", szUseChat[gFilterMQ2DataErrors]);

				WritePrivateProfileBool("MacroQuest", "FilterMQ2Data", gFilterMQ2DataErrors, mq::internal_paths::MQini);
				return;
			}
		}

		SyntaxError("Usage: /filter mq2data [on|off]");
		return;
	}

	if (!_stricmp("target", szArg))
	{
		if (szRest[0] == 0)
		{
			WriteChatf("Filtering of target lost messages is set to: %s", szFilterTarget[gFilterTarget ? 1 : 0]);
			return;
		}

		for (int Command = 0; szFilterTarget[Command]; Command++)
		{
			if (!_stricmp(szRest, szFilterTarget[Command]))
			{
				gFilterTarget = Command != 0;

				WriteChatf("Filtering of target lost messages changed to: %s", szFilterTarget[gFilterTarget ? 1 : 0]);

				WritePrivateProfileBool("MacroQuest", "FilterTarget", gFilterTarget, mq::internal_paths::MQini);
				return;
			}
		}

		SyntaxError("Usage: /filter target [on|off]");
		return;
	}

	if (!_stricmp("debug", szArg))
	{
		if (szRest[0] == 0)
		{
			WriteChatf("Filtering of debug messages is set to: %s", szFilterTarget[gFilterDebug]);
			return;
		}

		for (int Command = 0; szFilterTarget[Command]; Command++)
		{
			if (!_stricmp(szRest, szFilterTarget[Command]))
			{
				gFilterDebug = Command != 0;

				WriteChatf("Filtering of debug messages changed to: %s", szFilterTarget[gFilterDebug]);

				WritePrivateProfileBool("MacroQuest", "FilterDebug", gFilterTarget, mq::internal_paths::MQini);
				return;
			}
		}

		SyntaxError("Usage: /filter debug [on|off]");
		return;
	}

	if (!_stricmp("money", szArg))
	{
		if (szRest[0] == 0)
		{
			WriteChatf("Filtering of money messages is set to: %s", szFilterTarget[gFilterMoney]);
			return;
		}

		for (int Command = 0; szFilterTarget[Command]; Command++)
		{
			if (!_stricmp(szRest, szFilterTarget[Command]))
			{
				gFilterMoney = Command;

				WriteChatf("Filtering of money messages changed to: %s", szFilterTarget[gFilterMoney]);

				WritePrivateProfileBool("MacroQuest", "FilterMoney", gFilterMoney, mq::internal_paths::MQini);
				return;
			}
		}

		SyntaxError("Usage: /filter money [on|off]");
		return;
	}

	if (!_stricmp("encumber", szArg))
	{
		if (szRest[0] == 0)
		{
			WriteChatf("Filtering of encumber messages is set to: %s", szFilterTarget[gFilterEncumber]);
			return;
		}

		for (int Command = 0; szFilterTarget[Command]; Command++)
		{
			if (!_stricmp(szRest, szFilterTarget[Command]))
			{
				gFilterEncumber = Command != 0;

				WriteChatf("Filtering of encumber messages changed to: %s", szFilterTarget[gFilterEncumber]);

				WritePrivateProfileBool("MacroQuest", "FilterEncumber", gFilterEncumber, mq::internal_paths::MQini);
				return;
			}
		}

		SyntaxError("Usage: /filter encumber [on|off]");
		return;
	}

	if (!_stricmp("food", szArg))
	{
		if (szRest[0] == 0)
		{
			WriteChatf("Filtering of food messages is set to: %s", szFilterTarget[gFilterFood ? 1 : 0]);
			return;
		}

		for (int Command = 0; szFilterTarget[Command]; Command++)
		{
			if (!_stricmp(szRest, szFilterTarget[Command]))
			{
				gFilterFood = Command != 0;

				WriteChatf("Filtering of food messages changed to: %s", szFilterTarget[gFilterFood ? 1 : 0]);

				WritePrivateProfileBool("MacroQuest", "FilterFood", gFilterFood, mq::internal_paths::MQini);
				return;
			}
		}

		SyntaxError("Usage: /filter food [on|off]");
		return;
	}

	if (!_stricmp("name", szArg))
	{
		if (szRest[0] == 0)
		{
			WriteChatColor("Names currently filtered:");
			WriteChatColor("---------------------------");

			MQFilter* pFilter = gpFilters;
			while (pFilter)
			{
				if (pFilter->pEnabled == &gFilterCustom)
				{
					WriteChatf("   %s", pFilter->FilterText);
				}

				pFilter = pFilter->pNext;
			}
		}
		else
		{
			GetArg(szArg, szRest, 1);
			szRest = GetNextArg(szRest);

			if (!_stricmp(szArg, "on") || !_stricmp(szArg, "off"))
			{
				for (int Command = 0; szFilterTarget[Command]; Command++)
				{
					if (!_stricmp(szArg, szFilterTarget[Command]))
					{
						gFilterCustom = Command != 0;

						WriteChatf("Filtering of custom messages changed to: %s", szFilterTarget[gFilterCustom]);

						WritePrivateProfileBool("MacroQuest", "FilterCustom", gFilterCustom, mq::internal_paths::MQini);
						return;
					}
				}

				return;
			}

			if (!_stricmp(szArg, "remove"))
			{
				if (szRest[0] == 0)
				{
					WriteChatColor("Remove what?");
				}

				if (!_stricmp(szRest, "all"))
				{
					MQFilter* pFilter = gpFilters;
					MQFilter* pLastFilter = nullptr;

					while (pFilter)
					{
						if (pFilter->pEnabled == &gFilterCustom)
						{
							if (!pLastFilter)
							{
								gpFilters = pFilter->pNext;
								delete pFilter;
								pFilter = gpFilters->pNext;
							}
							else
							{
								pLastFilter->pNext = pFilter->pNext;
								delete pFilter;
								pFilter = pLastFilter->pNext;
							}
						}
						else
						{
							pLastFilter = pFilter;
							pFilter = pFilter->pNext;
						}
					}

					WriteChatColor("Cleared all name filters.");
					WriteFilterNames();
					return;
				}

				MQFilter* pFilter = gpFilters;
				MQFilter* pLastFilter = nullptr;

				while (pFilter)
				{
					if ((pFilter->pEnabled == &gFilterCustom) && !_stricmp(pFilter->FilterText, szRest))
					{
						if (!pLastFilter)
						{
							gpFilters = pFilter->pNext;
						}
						else
						{
							pLastFilter->pNext = pFilter->pNext;
						}

						delete pFilter;

						WriteChatf("Stopped filtering on: %s", szRest);
						WriteFilterNames();
						return;
					}

					pLastFilter = pFilter;
					pFilter = pFilter->pNext;
				}

				return;
			}

			if (!_stricmp(szArg, "add"))
			{
				if (szRest[0] == 0)
				{
					WriteChatColor("Add what?");
					return;
				}

				MQFilter* pFilter = gpFilters;
				while (pFilter)
				{
					if ((pFilter->pEnabled == &gFilterCustom) && !_stricmp(pFilter->FilterText, szRest))
					{
						WriteChatf("Name '%s' is already being filtered.", szRest);
						return;
					}

					pFilter = pFilter->pNext;
				}

				AddFilter(szRest, -1, gFilterCustom);
				WriteFilterNames();

				WriteChatf("Started filtering on: %s", szRest);
				return;
			}

			SyntaxError("Usage: /filter name on|off|add|remove <name>");
			return;
		}

		return;
	}

	if (!_stricmp("zrange", szArg))
	{
		if (szRest[0] == 0)
		{
			if (gZFilter >= 10000.0f)
			{
				WriteChatColor("Z range is not currently set.");
			}
			else
			{
				WriteChatf("Z range is set to: %1.2f", gZFilter);
			}
		}
		else
		{
			gZFilter = GetDoubleFromString(szRest, 0);
		}
	}

	if (cmdFilter)
	{
		cmdFilter(pChar, szArg);
	}
}


// ***************************************************************************
// Function:    DebugSpewFile
// Description: Our '/spewfile' command
//              Controls logging of DebugSpew to a file
// Usage:       /spewfile [on,off]
// ***************************************************************************
void DebugSpewFile(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;

	if (!_strnicmp(szLine, "off", 3))
	{
		gSpewToFile = false;
	}
	else if (!_strnicmp(szLine, "on", 2))
	{
		gSpewToFile = true;
	}
	else if (szLine[0] != 0)
	{
		WriteChatColor("Syntax: /spewfile [on|off]");
	}

	if (gSpewToFile)
	{
		WriteChatColor("Debug Spew is being logged to a file.");
	}
	else
	{
		WriteChatColor("Debug Spew is not being logged to a file.");
	}
}

// ***************************************************************************
// Function:    Identify
// Description: Our '/identify' command
//              Identifies the item on the cursor, displaying the LORE name.
// Usage:       /identify
// ***************************************************************************
void Identify(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;

	PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return;

	CONTENTS* pCursor = pProfile->pInventoryArray->Inventory.Cursor;
	if (!pCursor)
	{
		MacroError("You must be holding an item to identify it.");
		return;
	}

	ITEMINFO* pItemInfo = GetItemFromContents(pCursor);
	DebugSpew("Identify - %s", pItemInfo->LoreName);

	WriteChatColor(" ", USERCOLOR_SPELLS);

	if (pItemInfo->Type == ITEMTYPE_NORMAL && pItemInfo->ItemType < MAX_ITEMTYPES && szItemTypes[pItemInfo->ItemType] != nullptr)
	{
		WriteChatColorf("Item: %s (Slot: %s, Weight: %.1f, Value: %dcp, Type: %s)", USERCOLOR_SPELLS,
			pItemInfo->Name,
			szSize[pItemInfo->Size],
			static_cast<float>(pItemInfo->Weight) / 10.f,
			pItemInfo->Cost,
			szItemTypes[pItemInfo->ItemType]);
	}
	else if (pItemInfo->Type == ITEMTYPE_PACK && pItemInfo->Combine < MAX_COMBINES && szCombineTypes[pItemInfo->Combine] != nullptr)
	{
		WriteChatColorf("Item: %s (Slot: %s, Weight: %.1f, Value: %dcp, Type: %s)", USERCOLOR_SPELLS,
			pItemInfo->Name,
			szSize[pItemInfo->Size],
			static_cast<float>(pItemInfo->Weight) / 10.f,
			pItemInfo->Cost,
			szCombineTypes[pItemInfo->Combine]);
	}
	else
	{
		WriteChatColorf("Item: %s (Slot: %s, Weight: %.1f, Value: %dcp)", USERCOLOR_SPELLS,
			pItemInfo->Name, szSize[pItemInfo->Size],
			static_cast<float>(pItemInfo->Weight) / 10.f,
			pItemInfo->Cost);
	}

	if (pItemInfo->LoreName[0] != '*' && strcmp(pItemInfo->LoreName, pItemInfo->Name))
	{
		WriteChatColorf("Lore Name: %s", USERCOLOR_SPELLS, pItemInfo->LoreName);
	}
	else if (pItemInfo->LoreName[0] == '*' && strcmp(pItemInfo->LoreName + 1, pItemInfo->Name))
	{
		WriteChatColorf("Lore Name: %s", USERCOLOR_SPELLS, pItemInfo->LoreName + 1);
	}

	char szMsg[MAX_STRING] = { 0 };

	if (pItemInfo->LoreName[0] == '*')
		strcat_s(szMsg, "LORE ");
	if (!pItemInfo->NoDrop)
		strcat_s(szMsg, "NODROP ");
	if (!pItemInfo->NoRent)
		strcat_s(szMsg, "NORENT ");

	if (pItemInfo->Type == ITEMTYPE_NORMAL)
	{
		if (pItemInfo->Magic)
			strcat_s(szMsg, "MAGIC ");

		uint8_t Light = pItemInfo->Light;
		if (Light > 0 && Light <= LIGHT_COUNT)
		{
			strcat_s(szMsg, "(Light: ");
			strcat_s(szMsg, szLights[Light]);
			strcat_s(szMsg, ") ");
		}
	}

	if (szMsg[0] != 0)
	{
		WriteChatColorf("Flags: %s", USERCOLOR_SPELLS, szMsg);
	}

	// Reset for round two:
	szMsg[0] = 0;

	if (pItemInfo->Type == ITEMTYPE_PACK)
	{
		char szCombine[256] = { 0 };

		if (pItemInfo->Combine < MAX_COMBINES && szCombineTypes[pItemInfo->Combine] != nullptr)
		{
			strcpy_s(szCombine, szCombineTypes[pItemInfo->Combine]);
		}
		else
		{
			sprintf_s(szCombine, "*Unknown%d", pItemInfo->Combine);
		}

		sprintf_s(szMsg, "Container: %d Slot %s, %d%% Reduction, Combine=%s",
			pItemInfo->Slots,
			szSize[pItemInfo->SizeCapacity],
			pItemInfo->WeightReduction,
			szCombine);
	}
	else if (pItemInfo->Type == ITEMTYPE_BOOK)
	{
		//sprintf_s(szMsg,"Book file: %s", pItemInfo->Book.File);
	}
	else
	{
		char szTmp[MAX_STRING] = { 0 };

		strcpy_s(szMsg, "Item: ");
		if (pItemInfo->AC)
		{
			sprintf_s(szTmp, "AC%d ", pItemInfo->AC);
			strcat_s(szMsg, szTmp);
		}

		if (pItemInfo->Damage)
		{
			sprintf_s(szTmp, "%dDam ", pItemInfo->Damage);
			strcat_s(szMsg, szTmp);
		}

		if (pItemInfo->Delay)
		{
			sprintf_s(szTmp, "%dDly ", pItemInfo->Delay);
			strcat_s(szMsg, szTmp);
		}

		if (pItemInfo->Range)
		{
			sprintf_s(szTmp, "%dRng ", pItemInfo->Range);
			strcat_s(szMsg, szTmp);
		}

		if (pItemInfo->HP)
		{
			sprintf_s(szTmp, "%dHP ", pItemInfo->HP);
			strcat_s(szMsg, szTmp);
		}

		if (pItemInfo->Mana)
		{
			sprintf_s(szTmp, "%dMana ", pItemInfo->Mana);
			strcat_s(szMsg, szTmp);
		}

		if (pItemInfo->STR)
		{
			sprintf_s(szTmp, "%dSTR ", pItemInfo->STR);
			strcat_s(szMsg, szTmp);
		}

		if (pItemInfo->STA)
		{
			sprintf_s(szTmp, "%dSTA ", pItemInfo->STA);
			strcat_s(szMsg, szTmp);
		}

		if (pItemInfo->DEX)
		{
			sprintf_s(szTmp, "%dDEX ", pItemInfo->DEX);
			strcat_s(szMsg, szTmp);
		}

		if (pItemInfo->AGI)
		{
			sprintf_s(szTmp, "%dAGI ", pItemInfo->AGI);
			strcat_s(szMsg, szTmp);
		}

		if (pItemInfo->WIS)
		{
			sprintf_s(szTmp, "%dWIS ", pItemInfo->WIS);
			strcat_s(szMsg, szTmp);
		}

		if (pItemInfo->INT)
		{
			sprintf_s(szTmp, "%dINT ", pItemInfo->INT);
			strcat_s(szMsg, szTmp);
		}

		if (pItemInfo->CHA)
		{
			sprintf_s(szTmp, "%dCHA ", pItemInfo->CHA);
			strcat_s(szMsg, szTmp);
		}

		if (pItemInfo->SvMagic)
		{
			sprintf_s(szTmp, "%dSvM ", pItemInfo->SvMagic);
			strcat_s(szMsg, szTmp);
		}

		if (pItemInfo->SvDisease)
		{
			sprintf_s(szTmp, "%dSvD ", pItemInfo->SvDisease);
			strcat_s(szMsg, szTmp);
		}

		if (pItemInfo->SvPoison)
		{
			sprintf_s(szTmp, "%dSvP ", pItemInfo->SvPoison);
			strcat_s(szMsg, szTmp);
		}

		if (pItemInfo->SvFire)
		{
			sprintf_s(szTmp, "%dSvF ", pItemInfo->SvFire);
			strcat_s(szMsg, szTmp);
		}

		if (pItemInfo->SvCold)
		{
			sprintf_s(szTmp, "%dSvC ", pItemInfo->SvCold);
			strcat_s(szMsg, szTmp);
		}

		if (pItemInfo->SvCorruption)
		{
			sprintf_s(szTmp, "%dSvCorruption ", pItemInfo->SvCorruption);
			strcat_s(szMsg, szTmp);
		}

		if (((EQ_Item*)pCursor)->IsStackable() == 1)
		{
			sprintf_s(szTmp, "Stack size = %d ", pCursor->StackCount);
			strcat_s(szMsg, szTmp);
		}
	}

	if (strlen(szMsg) > 6)
	{
		WriteChatColor(szMsg, USERCOLOR_SPELLS);
	}
}

// ***************************************************************************
// Function:    Location
// Description: Our '/loc' command
//              Displays your loc and current heading...
//              on a 16 point compass (ie. NNE)
// Usage:       /loc
// ***************************************************************************
void Location(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;

	if (gFilterMacro == FILTERMACRO_NONE)
		cmdLocation(pChar, szLine);

	int Angle = static_cast<int>((pChar->Heading / 32.0f) + 8.5f) % 16;

	WriteChatf("Your Location is %3.2f, %3.2f, %3.2f, and are heading %s.",
		pChar->Y, pChar->X, pChar->Z, szHeading[Angle]);
}

// FIXME: CMQ2Alerts should not be implementd in MQ2Commands.cpp
bool CMQ2Alerts::RemoveAlertFromList(uint32_t Id, MQSpawnSearch* pSearchSpawn)
{
	std::scoped_lock lock(m_mutex);

	auto alertIter = m_alertMap.find(Id);
	if (alertIter != m_alertMap.end())
	{
		auto& alertMap = alertIter->second;

		for (auto iter = alertMap.begin(); iter != alertMap.end(); iter++)
		{
			MQSpawnSearch* pSearch = &*iter;

			if (SearchSpawnMatchesSearchSpawn(pSearch, pSearchSpawn))
			{
				alertMap.erase(iter);
				return true;
			}
		}
	}

	return false;
}

bool CMQ2Alerts::AddNewAlertList(uint32_t Id, MQSpawnSearch* pSearchSpawn)
{
	std::scoped_lock lock(m_mutex);

	auto alertIter = m_alertMap.find(Id);
	if (alertIter != m_alertMap.end())
	{
		auto& alertMap = alertIter->second;

		for (auto& iter : alertMap)
		{
			if (SearchSpawnMatchesSearchSpawn(&iter, pSearchSpawn))
			{
				return false;
			}
		}
	}

	m_alertMap[Id].push_back(*pSearchSpawn);
	return true;
}

void CMQ2Alerts::FreeAlerts(uint32_t id)
{
	std::scoped_lock lock(m_mutex);

	char szBuffer[64] = { 0 };

	auto alertIter = m_alertMap.find(id);
	if (alertIter != m_alertMap.end())
	{
		m_alertMap.erase(alertIter);
		WriteChatf("Alert list %d cleared.", id);
	}
	else
	{
		WriteChatf("No Alert list for %d was found.", id);
	}
}

bool CMQ2Alerts::GetAlert(uint32_t id, std::vector<MQSpawnSearch>& ss)
{
	std::scoped_lock lock(m_mutex);

	auto alertIter = m_alertMap.find(id);
	if (alertIter != m_alertMap.end())
	{
		ss = alertIter->second;
		return true;
	}

	return false;
}

size_t CMQ2Alerts::GetCount(uint32_t id) const
{
	std::scoped_lock lock(m_mutex);

	auto alertIter = m_alertMap.find(id);
	if (alertIter != m_alertMap.end())
	{
		return alertIter->second.size();
	}

	return 0;
}

bool CMQ2Alerts::AlertExist(uint32_t List)
{
	std::scoped_lock lock(m_mutex);

	return m_alertMap.find(List) != m_alertMap.end();
}

bool CMQ2Alerts::ListAlerts(char* szOut, size_t max)
{
	std::scoped_lock lock(m_mutex);

	if (m_alertMap.empty())
		return false;

	char szTemp[32] = { 0 };

	for (auto& [id, alertMap] : m_alertMap)
	{
		_itoa_s(id, szTemp, 10);
		strcat_s(szOut, max, szTemp);
		strcat_s(szOut, max, "|");
	}

	// remove trailing pipe.
	size_t len = strlen(szOut);
	if (len && szOut[len - 1] == '|')
		szOut[len - 1] = '\0';

	return true;
}

// ***************************************************************************
// Function:    Alert
// Description: Our '/alert' command
//              Sets up $alert notifications
// Usage:       /alert [clear #] [list #] [add/remove # [pc|npc|corpse|any] [radius ###] [zradius ###] [race race] [class class] [range min max] [name]]
// ***************************************************************************
void Alert(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;

	bool bOutput = pChar != nullptr;
	char szArg[MAX_STRING] = { 0 };
	char szLLine[MAX_STRING] = { 0 };
	bool Parsing = true;
	bool DidSomething = false;

	strcpy_s(szLLine, szLine);
	_strlwr_s(szLLine);
	char* szRest = szLLine;

	while (Parsing)
	{
		if (szRest[0] == 0)
		{
			Parsing = false;
		}
		else
		{
			GetArg(szArg, szRest, 1);
			szRest = GetNextArg(szRest, 1);

			if (!strcmp(szArg, "clear"))
			{
				GetArg(szArg, szRest, 1);
				CAlerts.FreeAlerts(GetIntFromString(szArg, 0));

				DidSomething = true;
			}
			else if (!strcmp(szArg, "list"))
			{
				GetArg(szArg, szRest, 1);
				szRest = GetNextArg(szRest, 1);

				std::vector<MQSpawnSearch> ss;

				if (CAlerts.GetAlert(GetIntFromString(szArg, 0), ss))
				{
					WriteChatColor(" ");
					WriteChatColor("Current alerts:");

					char szTemp[2048] = { 0 };
					for (auto i = ss.begin(); i != ss.end(); i++)
					{
						char Buffer[MAX_STRING] = { 0 };
						FormatSearchSpawn(Buffer, sizeof(Buffer), &(*i));

						int dist = std::distance(ss.begin(), i);
						WriteChatf("[%d] %s", dist, Buffer);
					}

					WriteChatf("%d alerts listed.", ss.size());
				}
				else
				{
					WriteChatColor("No alerts active.");
				}

				DidSomething = true;
			}
			else if (!strcmp(szArg, "remove"))
			{

				GetArg(szArg, szRest, 1);
				szRest = GetNextArg(szRest, 1);

				MQSpawnSearch searchSpawn;

				ClearSearchSpawn(&searchSpawn);

				bool ParsingAdd = true;
				while (ParsingAdd)
				{
					char szArg1[MAX_STRING] = { 0 };
					GetArg(szArg1, szRest, 1);
					szRest = GetNextArg(szRest, 1);
					if (szArg1[0] == 0)
					{
						ParsingAdd = false;
					}
					else
					{
						szRest = ParseSearchSpawnArgs(szArg1, szRest, &searchSpawn);
					}
				}

				char szTemp[MAX_STRING] = { 0 };
				int List = GetIntFromString(szArg, 0);

				if (CAlerts.RemoveAlertFromList(List, &searchSpawn))
				{
					WriteChatf("Removed alert for: %s", FormatSearchSpawn(szTemp, sizeof(szTemp), &searchSpawn));
				}
				else
				{
					WriteChatf("Couldn't find alert.");
				}

				DidSomething = true;
			}
			else if (!strcmp(szArg, "add"))
			{
				GetArg(szArg, szRest, 1);
				szRest = GetNextArg(szRest, 1);

				MQSpawnSearch searchSpawn;
				ClearSearchSpawn(&searchSpawn);

				bool ParsingAdd = true;
				while (ParsingAdd)
				{
					char szArg1[MAX_STRING] = { 0 };
					GetArg(szArg1, szRest, 1);
					szRest = GetNextArg(szRest, 1);

					if (szArg1[0] == 0)
					{
						ParsingAdd = false;
					}
					else
					{
						szRest = ParseSearchSpawnArgs(szArg1, szRest, &searchSpawn);
					}
				}

				// prev/next aren't logical in alerts
				searchSpawn.bTargNext = false;
				searchSpawn.bTargPrev = false;

				char szTemp[MAX_STRING] = { 0 };
				int List = GetIntFromString(szArg, 0);

				if (CheckAlertForRecursion(&searchSpawn, List))
				{
					if (bOutput)
					{
						WriteChatf("Alert would have caused recursion: %s",
							FormatSearchSpawn(szTemp, sizeof(szTemp), &searchSpawn));
					}
				}
				else
				{
					if (CAlerts.AddNewAlertList(List, &searchSpawn))
					{
						if (bOutput)
						{
							WriteChatf("Added alert for: %s",
								FormatSearchSpawn(szTemp, sizeof(szTemp), &searchSpawn));
						}
					}
					else
					{
						if (bOutput)
						{
							WriteChatf("Alert NOT added because there was already an alert for: %s",
								FormatSearchSpawn(szTemp, sizeof(szTemp), &searchSpawn));
						}
					}
				}

				DidSomething = true;
			}
		}
	}

	if (!DidSomething)
	{
		SyntaxError("Usage: /alert [clear #] [list #] [add/remove # [pc|npc|corpse|any] [radius radius] [zradius radius] [range min max] spawn]");
	}
}

// ***************************************************************************
// Function:    SuperWhoTarget
// Description: Our '/whotarget' command
//              Displays spawn currently selected
// Usage:       /whotarget
// ***************************************************************************
void SuperWhoTarget(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;

	SPAWNINFO* psTarget = nullptr;

	if (gFilterMacro == FILTERMACRO_NONE)
		cmdWhoTarget(pChar, szLine);

	if (pTarget)
	{
		psTarget = (SPAWNINFO*)pTarget;
	}

	if (!psTarget)
	{
		MacroError("You must have a target selected for /whotarget.");
		return;
	}

	DebugSpew("SuperWhoTarget - %s", psTarget->Name);

	bool Temp = gFilterSWho.Distance;
	gFilterSWho.Distance = true;

	SuperWhoDisplay(psTarget, USERCOLOR_WHO);

	gFilterSWho.Distance = Temp;
}

//============================================================================

static DWORD WINAPI thrMsgBox(void* lpParameter)
{
	MessageBox(nullptr, (const char*)lpParameter, "MacroQuest", MB_OK);
	free(lpParameter);
	return 0;
}

// ***************************************************************************
// Function:    MQMsgBox
// Description: Our '/msgbox' command
//              Our message box
// Usage:       /msgbox text
// ***************************************************************************
void MQMsgBox(SPAWNINFO* pChar, char* szLine)
{
	char szBuffer[MAX_STRING] = { 0 };
	bRunNextCommand = true;

	sprintf_s(szBuffer, "${Time.Date} ${Time}\r\n%s", szLine);
	ParseMacroParameter(pChar, szBuffer);

	CreateThread(nullptr, 0, thrMsgBox, _strdup(szBuffer), 0, nullptr);
}

// ***************************************************************************
// Function:    MacroLog
// Description: Our '/mqlog' command
//              Our logging
// Usage:       /mqlog text
// ***************************************************************************
void MacroLog(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;


	std::filesystem::path logFilePath = mq::internal_paths::Logs;
	if (gszMacroName[0] == 0)
	{
		logFilePath /= "MacroQuest.log";
	}
	else
	{
		logFilePath /= std::string(gszMacroName) + ".log";
	}

	if (!_stricmp(szLine, "clear"))
	{
		FILE* fOut = nullptr;
		errno_t err = fopen_s(&fOut, logFilePath.string().c_str(), "wt");
		if (err || !fOut)
		{
			MacroError("Couldn't open log file: %s", logFilePath.string().c_str());
			return;
		}

		WriteChatColor("Cleared log.", USERCOLOR_DEFAULT);
		fclose(fOut);
		return;
	}

	FILE* fOut = nullptr;
	errno_t err = fopen_s(&fOut, logFilePath.string().c_str(), "at");
	if (err || !fOut)
	{
		MacroError("Couldn't open log file: %s", logFilePath.string().c_str());
		return;
	}

	char szBuffer[MAX_STRING] = { 0 };
	sprintf_s(szBuffer, "[${Time.Date} ${Time.Time24}] %s", szLine);
	ParseMacroParameter(pChar, szBuffer);

	fprintf(fOut, "%s\n", szBuffer);
	DebugSpew("MacroLog - %s", szBuffer);

	fclose(fOut);
}

// ***************************************************************************
// Function:    Face
// Description: Our '/face' command
//              Faces the direction to a spawn
// Usage:       /face <spawn>
// Usage:       /face loc <y>,<x>
// ***************************************************************************
void Face(SPAWNINFO* pChar, char* szLine)
{
	if (!pSpawnManager) return;
	if (!pSpawnList) return;

	if (GetGameState() != GAMESTATE_INGAME)
	{
		MacroError("You shouldn't execute /face when not in game. Gamestate is %d", GetGameState());
		return;
	}

	bRunNextCommand = false;

	SPAWNINFO* pSpawnClosest = nullptr;
	SPAWNINFO* psTarget = nullptr;
	SPAWNINFO LocSpawn = { 0 };

	MQSpawnSearch SearchSpawn;
	ClearSearchSpawn(&SearchSpawn);

	char szMsg[MAX_STRING] = { 0 };
	char szName[MAX_STRING] = { 0 };
	char szArg[MAX_STRING] = { 0 };

	bool bArg = true;
	bool bOtherArgs = false;
	bool Away = false;
	bool Predict = false;
	bool Fast = false;
	bool Look = true;
	bool Parsing = true;

	char szLLine[MAX_STRING] = { 0 };
	strcpy_s(szLLine, szLine);
	_strlwr_s(szLLine);
	char* szFilter = szLLine;

	while (bArg)
	{
		GetArg(szArg, szFilter, 1);
		szFilter = GetNextArg(szFilter, 1);

		if (szArg[0] == 0)
		{
			bArg = false;
		}
		else if (!strcmp(szArg, "predict"))
		{
			Predict = true;
		}
		else if (!strcmp(szArg, "fast"))
		{
			Fast = true;
		}
		else if (!strcmp(szArg, "away"))
		{
			Away = true;
		}
		else if (!strcmp(szArg, "nolook"))
		{
			Look = false;
		}
		else if (!_stricmp(szArg, "loc"))
		{
			pSpawnClosest = &LocSpawn;
			strcpy_s(LocSpawn.Name, "location");

			if ((szFilter[0] == 0) || (!strstr(szFilter, ",")))
			{
				MacroError("Face: loc specified but <y>,<x> not found.");
				return;
			}

			pSpawnClosest->Y = GetFloatFromString(szFilter, 0);

			while ((szFilter[0] != ',') && (szFilter[0] != 0))
				szFilter++;

			if (szFilter[0] == 0)
			{
				MacroError("Face: loc specified but <y>,<x> not found.");
				return;
			}

			szFilter++;
			pSpawnClosest->X = GetFloatFromString(szFilter, 0);

			while ((szFilter[0] != ',') && (szFilter[0] != 0))
				szFilter++;

			if (szFilter[0] != 0)
			{
				szFilter++;
				pSpawnClosest->Z = GetFloatFromString(szFilter, 0);
			}
		}
		else if (!_stricmp(szArg, "item"))
		{
			if (EnviroTarget.Name[0] == 0)
			{
				MacroError("Face: item specified but no item targetted.");
				return;
			}

			pSpawnClosest = &EnviroTarget;
		}
		else if (!_stricmp(szArg, "door"))
		{
			if (DoorEnviroTarget.Name[0] == 0)
			{
				MacroError("Face: door specified but no door targetted.");
				return;
			}

			pSpawnClosest = &DoorEnviroTarget;
		}
		else if (!_stricmp(szArg, "heading"))
		{
			if (szFilter[0] == 0)
			{
				MacroError("Face: heading specified but angle not found.");
			}
			else
			{
				float Heading = GetFloatFromString(szFilter, 0);
				gFaceAngle = Heading / 0.703125f;

				if (gFaceAngle >= 512.0f)
					gFaceAngle -= 512.0f;
				if (gFaceAngle < 0.0f)
					gFaceAngle += 512.0f;

				if (Fast)
				{
					//changed
					((SPAWNINFO*)pCharSpawn)->Heading = (float)gFaceAngle;
					gFaceAngle = 10000.0f;
					bRunNextCommand = true;
				}
			}

			return;
		}
		else if (!strcmp(szArg, "help"))
		{
			SyntaxError("Usage: /face [spawn] [item] [door] [id #] [heading <ang>] [loc <y>,<x>] [away] [alert #]");
			bRunNextCommand = true;
			return;
		}
		else
		{
			bOtherArgs = true;
			szFilter = ParseSearchSpawnArgs(szArg, szFilter, &SearchSpawn);
		}
	}

	if (!pSpawnClosest)
	{
		if (!bOtherArgs)
		{
			if (pTarget)
			{
				pSpawnClosest = (SPAWNINFO*)pTarget;
			}
		}
		else
		{
			pSpawnClosest = SearchThroughSpawns(&SearchSpawn, pChar);
		}
	}

	szMsg[0] = 0;

	if (!pSpawnClosest)
	{
		MacroError("There were no matches for: %s", FormatSearchSpawn(szArg, sizeof(szArg), &SearchSpawn));
	}
	else
	{
		if (Predict)
		{
			float distance = Distance3DToSpawn(pChar, pSpawnClosest);

			gFaceAngle = atan2(
				(pSpawnClosest->X + (pSpawnClosest->SpeedX * distance)) - pChar->X,
				(pSpawnClosest->Y + (pSpawnClosest->SpeedY * distance)) - pChar->Y)
				* 256.0f / PI;
		}
		else
		{
			gFaceAngle = atan2(pSpawnClosest->X - pChar->X,pSpawnClosest->Y - pChar->Y) * 256.0f / PI;
		}

		if (Look)
		{
			float distance = Distance3DToSpawn(pChar, pSpawnClosest);

			float spawnHeight = pSpawnClosest->AvatarHeight * StateHeightMultiplier(pSpawnClosest->StandState);
			float charHeight = pChar->AvatarHeight * StateHeightMultiplier(pChar->StandState);

			gLookAngle = atan2(pSpawnClosest->Z + spawnHeight - pChar->Z - charHeight, distance) * 256.0f / PI;

			if (Away)
				gLookAngle = -gLookAngle;

			if (Fast)
			{
				pChar->CameraAngle = (float)gLookAngle;
				gLookAngle = 10000.0f;
			}
		}

		if (Away)
			gFaceAngle += 256.0f;

		if (gFaceAngle >= 512.0f)
			gFaceAngle -= 512.0f;
		if (gFaceAngle < 0.0f)
			gFaceAngle += 512.0f;

		if (Fast)
		{
			((SPAWNINFO*)pCharSpawn)->Heading = (float)gFaceAngle;
			gFaceAngle = 10000.0f;
			bRunNextCommand = true;
		}

		sprintf_s(szMsg, "Facing %s'%s'...", (Away) ? "away from " : "", pSpawnClosest->DisplayedName);
	}

	if (pTarget)
	{
		psTarget = (SPAWNINFO*)pTarget;
	}

	if (szMsg[0] && ((pSpawnClosest != &LocSpawn) && ((Away) || (pSpawnClosest != psTarget))))
		WriteChatColor(szMsg, USERCOLOR_WHO);

	DebugSpew("Face - %s", szMsg);
}

// ***************************************************************************
// Function:      Look
// Description:   Our /look command. Changes camera angle
// 2003-08-30     MacroFiend
// ***************************************************************************
void Look(SPAWNINFO* pChar, char* szLine)
{
	char szLookAngle[MAX_STRING] = { 0 };
	GetArg(szLookAngle, szLine, 1);

	float fLookAngle = GetFloatFromString(szLookAngle, 0);

	if (fLookAngle > 128.0f || fLookAngle < -128.0f)
	{
		MacroError("/look -- Angle %f out of range.", fLookAngle);
		return;
	}

	pChar->CameraAngle = fLookAngle;
	gLookAngle = 10000.0f;
}

// ***************************************************************************
// Function:    Where
// Description: Our '/where' command
//              Displays the direction and distance to the closest spawn
// Usage:       /where <spawn>
// ***************************************************************************
void Where(SPAWNINFO* pChar, char* szLine)
{
	if (!pSpawnManager) return;
	if (!pSpawnList) return;

	bRunNextCommand = true;

	MQSpawnSearch SearchSpawn;
	ClearSearchSpawn(&SearchSpawn);

	char szLLine[MAX_STRING] = { 0 };
	strcpy_s(szLLine, szLine);
	_strlwr_s(szLLine);
	char* szFilter = szLLine;

	char szArg[MAX_STRING] = { 0 };
	while (true)
	{
		GetArg(szArg, szFilter, 1);
		szFilter = GetNextArg(szFilter, 1);

		if (szArg[0] == 0)
		{
			break;
		}

		szFilter = ParseSearchSpawnArgs(szArg, szFilter, &SearchSpawn);
	}

	SPAWNINFO* pSpawnClosest = SearchThroughSpawns(&SearchSpawn, pChar);

	if (!pSpawnClosest)
	{
		WriteChatColorf("There were no matches for: %s", USERCOLOR_WHO, FormatSearchSpawn(szArg, sizeof(szArg), &SearchSpawn));
	}
	else
	{
		int Angle = static_cast<int>((atan2f(pChar->X - pSpawnClosest->X, pChar->Y - pSpawnClosest->Y) * 180.0f / PI + 360.0f) / 22.5f + 0.5f) % 16;

		WriteChatColorf("The closest '%s' is a level %d %s %s and %1.2f away to the %s, Z difference = %1.2f", USERCOLOR_WHO,
			pSpawnClosest->DisplayedName,
			pSpawnClosest->Level,
			pEverQuest->GetRaceDesc(pSpawnClosest->mActorClient.Race),
			GetClassDesc(pSpawnClosest->mActorClient.Class),
			Distance3DToSpawn(pChar, pSpawnClosest),
			szHeading[Angle],
			pSpawnClosest->Z - pChar->Z);
	}
}

// ***************************************************************************
// Function:    DoAbility
// Description: Our '/doability' command
//              Does (or lists) your abilities
// Usage:       /doability [list|ability|#]
// ***************************************************************************
void DoAbility(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine[0] || !cmdDoAbility)
		return;

	char szBuffer[MAX_STRING] = { 0 };
	GetArg(szBuffer, szLine, 1);

	int abil = GetIntFromString(szBuffer, 0);
	if (abil && abil > 5 && abil < NUM_SKILLS) // user wants us to activate a ability by its REAL ID...
	{
		if (int nToken = pSkillMgr->GetNameToken(abil))
		{
			if (const char* thename = pStringTable->getString(nToken))
			{
				strcpy_s(szBuffer, thename);
			}
		}
	}
	else
	{
		if (abil || !EQADDR_DOABILITYLIST)
		{
			cmdDoAbility(pChar, szLine);
			return;
		}
	}

	PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return;

	// display available abilities list
	if (!_stricmp(szBuffer, "list"))
	{
		WriteChatColor("Abilities & Combat Skills:");

		// display skills that have activated state
		for (int Index = 0; Index < NUM_SKILLS; Index++)
		{
			if (HasSkill(Index))
			{
				bool Avail = pSkillMgr->pSkill[Index]->Activated;

				// make sure remove trap is added, they give it to everyone except rogues
				if (Index == 75 && strncmp(pEverQuest->GetClassDesc(pProfile->Class & 0xFF), "Rogue", 6))
					Avail = true;

				if (Avail)
				{
					WriteChatf("<\ag%s\ax>", szSkills[Index]);
				}
			}
		}

		// display innate skills that are available
		for (int Index = 0; Index < 28; Index++)
		{
			if (pProfile->InnateSkill[Index] != 0xFF && strlen(szSkills[Index + 100]) > 3)
			{
				WriteChatf("<\ag%s\ax>", szSkills[Index + 100]);
			}
		}

		// display discipline i have
		WriteChatColor("Combat Abilities:", USERCOLOR_DEFAULT);

		for (int Index = 0; Index < NUM_COMBAT_ABILITIES; Index++)
		{
			if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(Index))
			{
				if (SPELL* pCA = GetSpellByID(pPCData->GetCombatAbility(Index)))
				{
					WriteChatf("<\ag%s\ax>", pCA->Name);
				}
			}
		}
		return;
	}

	// scan for matching abilities name
	for (int Index = 0; Index < 128; Index++)
	{
		if (Index < NUM_SKILLS && pSkillMgr->pSkill[Index]->Activated
			|| Index > NUM_SKILLS && pProfile->InnateSkill[Index - 100] != 0xFF)
		{
			if (!_stricmp(szBuffer, szSkills[Index]))
			{
				if (!HasSkill(Index))
				{
					WriteChatf("you do not have this skill (%s)", szBuffer);
					return;
				}

				if (pCharData)
				{
					pCharData->UseSkill(static_cast<uint8_t>(Index), pCharData->me);
				}

				return;
			}
		}
	}

	// scan for matching discipline name
	for (int Index = 0; Index < NUM_COMBAT_ABILITIES; Index++)
	{
		if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(Index))
		{
			if (SPELL* pCA = GetSpellByID(pProfile->CombatAbilities[Index]))
			{
				if (!_stricmp(pCA->Name, szBuffer))
				{
					pCharData->DoCombatAbility(pCA->ID);
					return;
				}
			}
		}
	}

	// else display that we didnt found abilities
	WriteChatColor("You do not seem to have that ability available", USERCOLOR_DEFAULT);
}

// ***************************************************************************
// Function:    LoadSpells
// Description: Our '/loadspells' command
//              Loads (or lists) a spell favorite list
// Usage:       /loadspells [list|"name"]
// ***************************************************************************
void LoadSpells(SPAWNINFO* pChar, char* szLine)
{
	if (!pSpellSets || !pSpellBookWnd || szLine[0] == 0)
		return;

	char szArg1[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);

	char szArg2[MAX_STRING] = { 0 };
	GetArg(szArg2, szLine, 2);

	if (!_stricmp(szArg1, "list") && szArg2[0] == 0)
	{
		WriteChatColor("Spell favorites list:");
		WriteChatColor("--------------------------");

		for (int Index = 0; Index < NUM_SPELL_SETS; Index++)
		{
			if (pSpellSets[Index].Name[0] != 0)
			{
				WriteChatf("%d) %s", Index, pSpellSets[Index].Name);
			}
		}
		return;
	}

	if (!_stricmp(szArg1, "list"))
	{
		int DoIndex = IsNumber(szArg2) ? GetIntFromString(szArg2, -1) : FindSpellListByName(szArg2);

		if (DoIndex < 0 || DoIndex > NUM_SPELL_SETS - 1)
		{
			WriteChatf("Unable to find favorite list '%s'", szArg2);
			return;
		}

		WriteChatf("Favorite list '%s':", pSpellSets[DoIndex].Name);

		for (int Index = 0; Index < NUM_SPELL_GEMS; Index++)
		{
			if (pSpellSets[DoIndex].SpellId[Index] != -1)
			{
				WriteChatf("%d) %s", Index, GetSpellByID(pSpellSets[DoIndex].SpellId[Index])->Name);
			}
		}

		return;
	}

	int DoIndex = IsNumber(szArg1) ? GetIntFromString(szArg1, -1) : FindSpellListByName(szArg1);
	if (DoIndex >= 0 && DoIndex < NUM_SPELL_SETS)
	{
		bool bMissingSpell = false;

		for (int Index = 0; Index < NUM_SPELL_GEMS; Index++)
		{
			if (pSpellSets[DoIndex].SpellId[Index] != -1)
			{
				if (GetMemorizedSpell(Index) != pSpellSets[DoIndex].SpellId[Index])
				{
					bMissingSpell = true;
				}

			}
		}

		if (bMissingSpell)
		{
			pSpellBookWnd->MemorizeSet(pSpellSets[DoIndex].SpellId, NUM_SPELL_GEMS);
		}
	}
	else
	{
		WriteChatf("Unable to find favorite list '%s'", szArg1);
	}
}

static void CastSplash(int Index, SPELL* pSpell, const CVector3* pos)
{
	pEverQuest->CreateTargetIndicator(Index, pSpell, ItemGlobalIndex(), eActivatableSpell);
	SPAWNINFO* pMySpawn = pLocalPlayer;

	if (CTargetRing* pTR = (CTargetRing*)((EVERQUEST*)pEverQuest)->pFreeTargetRing)
	{
		CVector3 vec3;

		if (pos)
		{
			vec3.X = pos->Y;
			vec3.Y = pos->X;
			vec3.Z = pos->Z;
		}
		else if (pTarget)
		{
			vec3.X = ((SPAWNINFO*)pTarget)->Y; // yes we really need to set Y to x, this is not a bug.
			vec3.Y = ((SPAWNINFO*)pTarget)->X;
			vec3.Z = ((SPAWNINFO*)pTarget)->Z;
		}
		else
		{
			// ok fine, this is probably not what the user wants but if he doesnt have a target im just gonna splash myself...
			vec3.X = pMySpawn->Y;
			vec3.Y = pMySpawn->X;
			vec3.Z = pMySpawn->Z;
		}

		// check if splash can be cast in the location
		if (pLocalPlayer->CanSee(vec3))
		{
			float dist = Get3DDistance(vec3.Y, vec3.X, vec3.Z, pMySpawn->X, pMySpawn->Y, pMySpawn->Z);

			if (dist < pTR->thespell->Range)
			{
				pTR->Cast(vec3);
			}
			else
			{
				WriteChatColor("You too far away from your target", CONCOLOR_LIGHTBLUE);
			}
		}
		else
		{
			WriteChatColor("You cannot see your target", CONCOLOR_LIGHTBLUE);
		}

		// cleanup the target indicator
		pEverQuest->DeleteTargetIndicator();
	}
	else
	{
		WriteChatColor("Creation of a TargetIndicator Failed.", CONCOLOR_YELLOW);
	}
}

// ***************************************************************************
// Function:    Cast
// Description: Our '/cast' command
// Usage:       /cast [list|#|"name of spell"|item "name of item"] optional:<loc x y z> (spash location)
// ***************************************************************************
void Cast(SPAWNINFO* pChar, char* szLine)
{
	if (!cmdCast)
		return;

	char szArg1[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);
	char szArg2[MAX_STRING] = { 0 };
	GetArg(szArg2, szLine, 2);

	if (szLine[0] == 0 || GetIntFromString(szLine, 0) || !pSpellMgr || !pCharData)
	{
		int Index = GetIntFromString(szLine, 0) - 1;

		if (Index >= 0 && Index < NUM_SPELL_GEMS)
		{
			if (SPELL* pSpell = GetSpellByID(GetMemorizedSpell(Index)))
			{
				if (pSpell->TargetType == TT_SPLASH)
				{
					// is it a splashspell?
					if (!_stricmp(szArg2, "loc"))
					{
						CVector3 castLoc;

						// they want to cast it at a specific location
						char loc[32] = { 0 };
						GetArg(loc, szLine, 3);
						castLoc.X = GetFloatFromString(loc, 0);

						GetArg(loc, szLine, 4);
						castLoc.Y = GetFloatFromString(loc, 0);

						GetArg(loc, szLine, 5);
						castLoc.Z = GetFloatFromString(loc, 0);

						CastSplash(Index, pSpell, &castLoc);
					}
					else
					{
						CastSplash(Index, pSpell, nullptr);
					}
					return;
				}
			}
		}

		cmdCast(pChar, szLine);
		return;
	}

	if (!_stricmp(szLine, "list"))
	{
		WriteChatColor("Spells:");

		for (int Index = 0; Index < NUM_SPELL_GEMS; Index++)
		{
			int Spellid = GetMemorizedSpell(Index);
			if (Spellid == -1)
			{
				WriteChatf("%d. <Empty>", Index + 1);
			}
			else
			{
				WriteChatf("%d. %s", Index + 1, GetSpellNameByID(Spellid));
			}
		}

		return;
	}

	if (!_stricmp(szArg1, "item"))
	{
		if (HasExpansion(EXPANSION_VoA))
		{
			if (CONTENTS* pItem = FindItemByName(szArg2, true))
			{
				if (GetItemFromContents(pItem)->Clicky.SpellID > 0 && GetItemFromContents(pItem)->Clicky.SpellID != -1)
				{
					char cmd[MAX_STRING] = { 0 };
					sprintf_s(cmd, "/useitem \"%s\"", GetItemFromContents(pItem)->Name);
					EzCommand(cmd);
				}
			}
			else
			{
				WriteChatf("Item '%s' not found.", szArg2);
			}
		}
		else
		{
			if (CONTENTS* pItem = FindItemByName(szArg2, true))
			{
				if (pItem->GetGlobalIndex().GetTopSlot() < NUM_INV_SLOTS)
				{
					if (GetItemFromContents(pItem)->Clicky.SpellID > 0 && GetItemFromContents(pItem)->Clicky.SpellID != -1)
					{
						if (pInvSlotMgr)
						{
							if (CInvSlot* pSlot = pInvSlotMgr->FindInvSlot(pItem->GetGlobalIndex().GetTopSlot()))
							{
								CXPoint p;
								pSlot->HandleRButtonUp(p);
							}
						}
					}
				}
			}
			else
			{
				WriteChatf("Item '%s' not found.", szArg2);
			}
		}
		return;
	}

	// Check this, but i think it isn't necessary.
	GetArg(szArg1, szLine, 1);

	for (int Index = 0; Index < NUM_SPELL_GEMS; Index++)
	{
		int Spellid = GetMemorizedSpell(Index);
		if (Spellid != -1)
		{
			if (SPELL* pSpell = GetSpellByID(Spellid))
			{
				if (!_strnicmp(szArg1, pSpell->Name, strlen(szArg1)))
				{
					if (pSpell->TargetType == TT_SPLASH)
					{
						// is it a splashspell?
						if (!_stricmp(szArg2, "loc"))
						{
							CVector3 castLoc;

							// they want to cast it at a specific location
							char loc[32] = { 0 };
							GetArg(loc, szLine, 3);
							castLoc.X = GetFloatFromString(loc, 0);

							GetArg(loc, szLine, 4);
							castLoc.Y = GetFloatFromString(loc, 0);

							GetArg(loc, szLine, 5);
							castLoc.Z = GetFloatFromString(loc, 0);

							CastSplash(Index, pSpell, &castLoc);
						}
						else
						{
							CastSplash(Index, pSpell, nullptr);
						}
					}
					else
					{
						// nope normal, so just pipe it through
						_itoa_s(Index + 1, szArg1, 10);
						cmdCast(pChar, szArg1);
					}

					return;
				}
			}
		}
	}

	WriteChatColor("You do not seem to have that spell memorized.");
}

// ***************************************************************************
// Function:    Target
// Description: Our '/target' command
//              Selects the closest spawn
// Usage:       /target [spawn|myself|mycorpse]
// ***************************************************************************
void Target(SPAWNINFO* pChar, char* szLine)
{
	gTargetbuffs = false;

	if (!pSpawnManager) return;
	if (!pSpawnList) return;

	bRunNextCommand = true;

	MQSpawnSearch SearchSpawn;
	ClearSearchSpawn(&SearchSpawn);

	bool DidTarget = false;
	SPAWNINFO* pSpawnClosest = nullptr;

	char szLLine[MAX_STRING] = { 0 };
	strcpy_s(szLLine, szLine);
	_strlwr_s(szLLine);
	char* szFilter = szLLine;

	char szArg[MAX_STRING] = { 0 };

	while (true)
	{
		GetArg(szArg, szFilter, 1);
		szFilter = GetNextArg(szFilter, 1);

		if (szArg[0] == 0)
		{
			break;
		}

		if (!strcmp(szArg, "myself"))
		{
			if (pLocalPlayer)
			{
				pSpawnClosest = (SPAWNINFO*)pLocalPlayer;
				DidTarget = true;
			}
		}
		else if (!strcmp(szArg, "mycorpse"))
		{
			if (((CHARINFO*)pCharData)->pSpawn)
			{
				sprintf_s(szFilter, MAX_STRING, "%s's Corpse", ((SPAWNINFO*)pLocalPlayer)->Name);
				_strlwr_s(szFilter, MAX_STRING);
			}
		}
		else if (!strcmp(szArg, "clear"))
		{
			pTarget = nullptr;
			pDoorTarget = nullptr;
			pGroundTarget = nullptr;

			ZeroMemory(&GroundObject, sizeof(GroundObject));
			ZeroMemory(&EnviroTarget, sizeof(EnviroTarget));
			ZeroMemory(&DoorEnviroTarget, sizeof(DoorEnviroTarget));

			if (pChar)
				pChar->GroupMemberTargeted = 1;

			DebugSpew("Target cleared.");
			WriteChatColor("Target cleared.", USERCOLOR_WHO);
			return;
		}
		else if (!strcmp(szArg, "ccb"))
		{
			ClearCachedBuffsSpawn(pTarget);
			WriteChatColor("Cached Buffs for Target cleared.", USERCOLOR_WHO);
			return;
		}
		else if (!strcmp(szArg, "cacb"))
		{
			pTarget = nullptr;

			WriteChatColor("Cached Buffs for ALL Targets cleared.", USERCOLOR_WHO);
			ClearCachedBuffs();
			return;
		}
		else
		{
			szFilter = ParseSearchSpawnArgs(szArg, szFilter, &SearchSpawn);
		}
	}

	if (pTarget)
		SearchSpawn.FromSpawnID = ((SPAWNINFO*)pTarget)->SpawnID;

	if (!DidTarget)
	{
		pSpawnClosest = SearchThroughSpawns(&SearchSpawn, pChar);
	}

	if (!pSpawnClosest)
	{
		if (!gFilterTarget)
		{
			char szTemp[MAX_STRING] = { 0 };
			WriteChatColorf("There are no spawns matching: %s",
				USERCOLOR_WHO, FormatSearchSpawn(szTemp, sizeof(szTemp), &SearchSpawn));
		}
	}
	else
	{
		pTarget = pSpawnClosest;

		DebugSpew("Target - %s selected", pSpawnClosest->Name);
	}
}

// ***************************************************************************
// Function:    Skills
// Description: Our '/skills' command
//              Displays what your current skill levels are
// Usage:       /skills [skill name]
// ***************************************************************************
void Skills(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;

	CHARINFO* pCharInfo = GetCharInfo();
	if (!pCharInfo)
		return;

	PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return;

	int SkillCount = 0;

	WriteChatColor("Skills");
	WriteChatColor("-----------------------");


	for (int Skill = 0; szSkills[Skill]; Skill++)
	{
		if (szLine[0] != 0)
		{
			char szName[MAX_STRING] = { 0 };
			strcpy_s(szName, szSkills[Skill]);
			_strlwr_s(szName);

			if (ci_find_substr(szSkills[Skill], szLine) != -1)
				continue;
		}

		SkillCount++;

		switch (pProfile->Skill[Skill])
		{
		case 255:
			// Untrainable
			SkillCount--;
			break;

		case 254:
			// Can train
			WriteChatf("%s: Trainable", szSkills[Skill]);
			break;

		case 253:
			// Unknown
			WriteChatf("%s: Unknown(253)", szSkills[Skill]);
			break;

		default:
			// Have skill
			WriteChatf( "%s: %d", szSkills[Skill], pProfile->Skill[Skill]);
			break;
		}
	}

	if (SkillCount == 0)
	{
		WriteChatf("No skills matched '%s'.", szLine);
	}
	else
	{
		WriteChatf("%d skills displayed.", SkillCount);
	}
}

// ***************************************************************************
// Function:    SetAutoRun
// Description: Our '/setautorun' command
//              Set autorun value
// Usage:       /setautorun [command]
// ***************************************************************************
void SetAutoRun(SPAWNINFO* pChar, char* szLine)
{
	char szServerAndName[256] = { 0 };
	sprintf_s(szServerAndName, "%s.%s", EQADDR_SERVERNAME, ((CHARINFO*)pCharData)->Name);
	WritePrivateProfileString("AutoRun", szServerAndName, szLine, mq::internal_paths::MQini);

	WriteChatf("Set autorun to: '%s'", szLine);
}

// ***************************************************************************
// Function:   IniOutput our /ini command
// Description:   Outputs string data to an INI file using WritePrivateProfileString.
// If the inifile does'nt exist one will be created.
// Usage:
//
//	/ini "someini.ini" "the section" "NULL" "NULL"
//	adds a key named nullptr and a value named nullptr under the [the section]:
//	to remove the key named nullptr:
//	/ini "someini.ini" "the section" "NULL" nullptr
//	OR /ini "someini.ini" "the section" "NULL"
//	to remove section "the section":
//	/ini "someini.ini" "the section" nullptr
//	OR /ini "someini.ini" "the section"
//
//	Basically leaving the third and/or fourth parameter blank will be interpreted as nullptr
//	enclosing nullptr in quotes will interpret it as an actual string "NULL"
// ***************************************************************************
void IniOutput(SPAWNINFO* pChar, char* szLine)
{
	char szArg1[MAX_STRING] = { 0 };   // Filename
	GetArg(szArg1, szLine, 1);

	char szArg2[MAX_STRING] = { 0 };   // Section
	GetArg(szArg2, szLine, 2);

	char szArg3[MAX_STRING] = { 0 };   // Key
	GetArg(szArg3, szLine, 3, 1);

	char szArg4[MAX_STRING] = { 0 };   // Data to write
	GetArg(szArg4, szLine, 4, 1);

	char szOutput[MAX_STRING] = { 0 };  //Success / Error Output

	DebugSpew("/ini input -- %s %s %s %s", szArg1, szArg2, szArg3, szArg4);

	if (!strstr(szArg1, "."))
	{
		strcat_s(szArg1, ".ini");
	}

	std::filesystem::path iniFile = szArg1;
	if (iniFile.is_relative())
	{
		iniFile = mq::internal_paths::Config / iniFile;
	}

	std::string Arg3 = { szArg3 };
	std::string Arg4 = { szArg4 };

	if (ci_equals(szArg3, "NULL"))
	{
		Arg3 = "";
	}
	if (ci_equals(szArg4, "NULL"))
	{
		Arg4 = "";
	}

	// Strip the double quotes
	if (!Arg3.empty() && Arg3[0] == '"' && Arg3[Arg3.length() - 1] == '"')
	{
	    Arg3 = Arg3.substr(1, Arg3.length() - 2);
	}
	if (!Arg4.empty() && Arg4[0] == '"' && Arg4[Arg4.length() - 1] == '"')
	{
	    Arg4 = Arg4.substr(1, Arg4.length() - 2);
	}

	if (!WritePrivateProfileString(szArg2, Arg3, Arg4, iniFile.string()))
	{
		DebugSpew("IniOutput ERROR -- during WritePrivateProfileString: %s", szLine);
	}
	else
	{
		DebugSpew("IniOutput Write Successful: %s", szLine);
	}
}

// ***************************************************************************
// Function:        BankList
// Description:     Our /banklist command. Lists bank contents to chat buffer.
// 2003-08-30       Valerian
// ***************************************************************************
void BankList(SPAWNINFO* pChar, char* szLine)
{
	CHARINFO* pCharInfo = GetCharInfo();
	if (!pCharInfo)
		return;

	WriteChatColor("Listing of Bank Inventory");
	WriteChatColor("-------------------------");

	char Link[MAX_STRING] = { 0 };

	for (int a = 0; a < NUM_BANK_SLOTS; a++)
	{
		CONTENTS* pContainer = nullptr;

		if (pCharInfo && pCharInfo->pBankArray)
			pContainer = pCharInfo->pBankArray->Bank[a];

		if (pContainer)
		{
			GetItemLink(pContainer, Link);
			WriteChatf("Slot %d: %dx %s (%s)", a, pContainer->StackCount ? pContainer->StackCount : 1, Link, GetItemFromContents(pContainer)->LoreName);

			if (pContainer->Contents.ContainedItems.pItems)
			{
				for (int b = 0; b < GetItemFromContents(pContainer)->Slots; b++)
				{
					CONTENTS* pItem = pContainer->Contents.ContainedItems.pItems->Item[b];

					if (pItem)
					{
						GetItemLink(pItem, Link);
						WriteChatf("- Slot %d: %dx %s (%s)", b,
							pItem->StackCount ? pItem->StackCount : 1,
							Link,
							GetItemFromContents(pItem)->LoreName);
					}
				}
			}
		}
	}
}

// ***************************************************************************
// Function:      WindowState
// Description:      Our /windowstate command. Toggles windows open/closed.
// ***************************************************************************
void WindowState(SPAWNINFO* pChar, char* szLine)
{
	char Arg1[MAX_STRING] = { 0 };
	GetArg(Arg1, szLine, 1);

	char Arg2[MAX_STRING] = { 0 };
	GetArg(Arg2, szLine, 2);

	CSidlScreenWnd* pWnd = (CSidlScreenWnd*)FindMQ2Window(Arg1);
	if (pWnd && pWnd->IsType(WRT_SIDLSCREENWND))
	{
		bool show = pWnd->IsVisible();

		if (ci_equals(Arg2, "open")) show = false;
		if (ci_equals(Arg2, "close")) show = true;
		show = !show;

		if (show)
		{
			pWnd->Activate();
		}
		else
		{
			pWnd->Deactivate();
		}

		if (!pWnd->GetWindowText().empty())
		{
			WriteChatf("Window '%s' is now %s.", pWnd->GetWindowText().c_str(), show ? "open" : "closed");
		}
		else
		{
			WriteChatf("Window '%s' is now %s.", Arg1, show ? "open" : "closed");
		}

		pWnd->StoreIniVis();
		return;
	}

	SyntaxError("Usage: /windowstate <window> [open|close]");
}

// ***************************************************************************
// Function:      DisplayLoginName
// Description:   Our /loginname command.
// ***************************************************************************
void DisplayLoginName(SPAWNINFO* pChar, char* szLine)
{
	const char* szLogin = GetLoginName();
	if (!szLogin)
	{
		MacroError("Unable to retrieve login name.");
	}
	else
	{
		WriteChatf("Login name: \ay%s\ax", szLogin);
	}
}

// ***************************************************************************
// Function:      EQDestroyHeldItemOrMoney
// Description:   Our /destroy command.
// ***************************************************************************
void EQDestroyHeldItemOrMoney(SPAWNINFO* pChar, char* szLine)
{
	(pPCData)->DestroyHeldItemOrMoney();
}

// ***************************************************************************
// Function:      Exec
// Description:   Our /exec command.
// ***************************************************************************
void Exec(SPAWNINFO* pChar, char* szLine)
{
	char szTemp1[MAX_STRING] = { 0 };
	GetArg(szTemp1, szLine, 1);

	char szTemp2[MAX_STRING] = { 0 };
	GetArg(szTemp2, szLine, 2);

	char szTemp3[MAX_STRING] = { 0 };
	GetArg(szTemp3, szLine, 3);

	if (szTemp1[0] != 0 && szTemp2[0] != 0)
	{
		WriteChatf("Opening %s %s %s", szTemp1, szTemp2, szTemp3);

		char exepath[MAX_STRING] = { 0 };
		GetPrivateProfileString("Application Paths", szTemp1, szTemp1, exepath, MAX_STRING, mq::internal_paths::MQini);

		if (!strcmp(szTemp2, "bg"))
		{
			ShellExecute(nullptr, "open", exepath, nullptr, nullptr, SW_SHOWMINNOACTIVE);
		}
		else if (!strcmp(szTemp2, "fg"))
		{
			ShellExecute(nullptr, "open", exepath, nullptr, nullptr, SW_SHOWNOACTIVATE);
		}
		else if (!strcmp(szTemp3, "bg"))
		{
			ShellExecute(nullptr, "open", exepath, szTemp2, nullptr, SW_SHOWMINNOACTIVE);
		}
		else if (!strcmp(szTemp3, "fg"))
		{
			ShellExecute(nullptr, "open", exepath, szTemp2, nullptr, SW_SHOWNOACTIVATE);
		}
	}
	else
	{
		WriteChatColor("/exec [application \"parameters\"] [fg | bg]", USERCOLOR_DEFAULT);
	}
}

// /keypress
void DoMappable(SPAWNINFO* pChar, char* szLine)
{
	if (szLine[0] == 0)
	{
		SyntaxError("Usage: /keypress <eqcommand|keycombo> [hold|chat]");
		return;
	}

	char szArg1[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);

	char szArg2[MAX_STRING] = { 0 };
	GetArg(szArg2, szLine, 2);

	bool Hold = (_stricmp(szArg2, "hold") == 0);

	if (!PressMQ2KeyBind(szArg1, Hold))
	{
		int nCmd = FindMappableCommand(szArg1);
		if (nCmd >= 0)
		{
			// ok if the user issues a movement keypress like "FORWARD" here and at charselect he ctd
			// lets see if we can fix that -eqmule
			if (EQbCommandStates[nCmd] == false)
			{
				MacroError("%s is disabled right now Gamestate is %d", szArg1, GetGameState());
				return;
			}

			ExecuteCmd(nCmd, true);
			if (!Hold)
				ExecuteCmd(nCmd, false);

			return;
		}

		KeyCombo Temp;

		if (ParseKeyCombo(szArg1, Temp))
		{
			if (!_stricmp(szArg2, "chat"))
			{
				if (Temp.Data[3] != 0x92)
				{
					pWndMgr->HandleKeyboardMsg(Temp.Data[3], true);
					pWndMgr->HandleKeyboardMsg(Temp.Data[3], false);
				}
				else
				{
					// ugly ass hack -- the ':' char no longer
					// seems to be handled independently.  simulate
					// a shift and a ;
					pWndMgr->HandleKeyboardMsg(0x2a, true);
					pWndMgr->HandleKeyboardMsg(0x27, true);
					pWndMgr->HandleKeyboardMsg(0x27, false);
					pWndMgr->HandleKeyboardMsg(0x2a, false);
				}
			}
			else
			{
				MQ2HandleKeyDown(Temp);

				if (!Hold)
					MQ2HandleKeyUp(Temp);
			}
			return;
		}

		MacroError("Invalid mappable command or key combo '%s'", szArg1);
		return;
	}
}

// /popup
void PopupText(SPAWNINFO* pChar, char* szLine)
{
	DisplayOverlayText(szLine, CONCOLOR_LIGHTBLUE, 100, 500, 500, 3000);
}

// /popcustom
void PopupTextCustom(SPAWNINFO* pChar, char* szLine)
{
	CustomPopup(szLine, false);
}

// /popupecho
void PopupTextEcho(SPAWNINFO* pChar, char* szLine)
{
	CustomPopup(szLine, true);
}

// /multiline
void MultilineCommand(SPAWNINFO* pChar, char* szLine)
{
	if (szLine[0] == 0)
	{
		SyntaxError("Usage: /multiline <delimiter> <command>[delimiter<command>[delimiter<command>[. . .]]]");
		return;
	}

	char szArg[MAX_STRING] = { 0 }; // delimiter(s)
	GetArg(szArg, szLine, 1);

	char* szRest = GetNextArg(szLine);
	if (!szRest[0])
		return;

	char Copy[MAX_STRING];
	strcpy_s(Copy, szRest); // dont destroy original...

	char szCmd[MAX_STRING] = { 0 };

	char* next_token1 = nullptr;
	char* token1 = strtok_s(Copy, szArg, &next_token1);
	while (token1 != nullptr)
	{
		strcpy_s(szCmd, token1);
		DoCommand(pChar, szCmd);

		token1 = strtok_s(nullptr, szArg, &next_token1);
	}
}

// /ranged
void do_ranged(SPAWNINFO* pChar, char* szLine)
{
	PlayerClient* pRangedTarget = pTarget;

	if (szLine[0])
	{
		pRangedTarget = GetSpawnByID(GetIntFromString(szLine, 0));
		if (!pRangedTarget)
		{
			MacroError("Invalid spawn ID.  Use /ranged with no parameters, or with a spawn ID");
			return;
		}
	}

	if (!pRangedTarget)
	{
		MacroError("No target for ranged attack");
		return;
	}

	AttackRanged(pRangedTarget);
}

// /loadcfg
void LoadCfgCommand(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /loadcfg <filename>");
		return;
	}

	if (LoadCfgFile(szLine, false))
		return;

	MacroError("Could not /loadcfg '%s'", szLine);
}

// /dumpbinds
void DumpBindsCommand(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage /dumpbinds <filename>");
		return;
	}

	if (!DumpBinds(szLine))
	{
		MacroError("Could not dump binds to %s", szLine);
		return;
	}

	WriteChatColor("Binds dumped to file.");
}

// /docommand
void DoCommandCmd(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /docommand <command>");
		return;
	}

	DoCommand(pChar, szLine);
}

// /alt
void DoAltCmd(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /alt <command>");
		return;
	}

	bool Old = pWndMgr->KeyboardFlags[2];
	pWndMgr->KeyboardFlags[2] = true;

	DoCommand(pChar, szLine);

	pWndMgr->KeyboardFlags[2] = Old;
}

// /shift
void DoShiftCmd(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /shift <command>");
		return;
	}

	bool Old = pWndMgr->KeyboardFlags[0];
	pWndMgr->KeyboardFlags[0] = true;
	gShiftKeyDown = 1;

	DoCommand(pChar, szLine);

	gShiftKeyDown = 0;
	pWndMgr->KeyboardFlags[0] = Old;
}

// /ctrl
void DoCtrlCmd(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /ctrl <command>");
		return;
	}

	bool Old = pWndMgr->KeyboardFlags[1];
	pWndMgr->KeyboardFlags[1] = true;

	DoCommand(pChar, szLine);

	pWndMgr->KeyboardFlags[1] = Old;
}

void NoModKeyCmd(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /nomodkey <command>");
		return;
	}

	bool KeyboardFlags[4];
	*(DWORD*)&KeyboardFlags = *(DWORD*)&pWndMgr->KeyboardFlags;
	*(DWORD*)&pWndMgr->KeyboardFlags = 0;

	DoCommand(pChar, szLine);

	*(DWORD*)&pWndMgr->KeyboardFlags = *(DWORD*)&KeyboardFlags;
}

// ***************************************************************************
// Function:    UseItemCmd
// Description: '/useitem' command
//              Activates an item that has a clicky effect.
// Usage:       /useitem 1 0 or /useitem "item name" or /useitem item name
// ***************************************************************************
void UseItemCmd(SPAWNINFO* pChar, char* szLine)
{
	char szCmd[MAX_STRING] = { 0 };
	strcpy_s(szCmd, szLine);

	if (!szCmd[0])
	{
		WriteChatColor("Usage: /useitem \"item name\"");

		cmdUseItem(pChar, szCmd);
		return;
	}
	else
	{
		char szSlot1[MAX_STRING] = { 0 };
		GetArg(szSlot1, szCmd, 1);

		bool stripped = StripQuotes(szCmd);
		if (IsNumber(szSlot1))
		{
			cmdUseItem(pChar, szCmd);
		}
		else
		{
			if (CONTENTS* pItem = FindItemByName(szCmd, stripped))
			{
				bool bKeyring = false;

				if (CHARINFO* pCharInfo = GetCharInfo())
				{
					ItemGlobalIndex location;
					location.Location = pItem->GlobalIndex.Location;

					bKeyring = location.IsKeyRingLocation();
				}

				if (!bKeyring)
				{
					char szTemp[32] = { 0 };
					sprintf_s(szTemp, "%d %d", pItem->GetGlobalIndex().GetTopSlot(), pItem->GetGlobalIndex().GetIndex().GetSlot(1));
					cmdUseItem(pChar, szTemp);
					return;
				}

				auto checkKeyRing = [&](KeyRingType keyringType, const char* windowList) -> bool
				{
					if (!((EQ_Item*)pItem)->IsKeyRingItem(keyringType))
						return false;

					if (int index = GetKeyRingIndex(keyringType, szCmd, stripped, true))
					{
						if (CXWnd* krWnd = FindMQ2Window(KeyRingWindowParent))
						{
							if (CListWnd* pListWnd = (CListWnd*)krWnd->GetChildItem(windowList))
							{
								int numItems = pListWnd->ItemsArray.Count;
								if (numItems > 0)
								{
									SendListSelect(KeyRingWindowParent, windowList, index - 1);
									int listData = static_cast<int>(pListWnd->GetItemData(index - 1));

									VePointer<CONTENTS> pContents{ pItem };
									CKeyRingWnd::ExecuteRightClick(keyringType, pContents, listData);
								}
							}
						}
					}

					return true;
				};

				// TODO: Further refactor this to clean it up
				if (!checkKeyRing(eMount, MountWindowList))
				{
					if (!checkKeyRing(eIllusion, IllusionWindowList))
					{
						checkKeyRing(eFamiliar, FamiliarWindowList);
					}
				}
			}
		}
	}
}

// ***************************************************************************
// Function:    DoSocial
// Description: '/dosocial' command
//              Does (or lists) your programmed socials
// Usage:       /dosocial [list|"social name"]
// ***************************************************************************
void DoSocial(SPAWNINFO* pChar, char* szLine)
{
	if (!pSocialList) return;

	//DWORD SocialIndex = -1, LineIndex;
	//DWORD SocialPage = 0, SocialNum = 0;
	char szBuffer[MAX_STRING] = { 0 };
	GetArg(szBuffer, szLine, 1);

	bool displayUsage = false;

	if (!_stricmp(szBuffer, "list"))
	{
		WriteChatColor("Socials: (page,number) name");

		for (int SocialIndex = 0; SocialIndex < 120; SocialIndex++)
		{
			int SocialPage = SocialIndex / 12;
			int SocialNum = SocialIndex - (SocialPage * 12);

			if (pSocialList[SocialIndex].Name[0] != 0)
			{
				WriteChatColorf("(%2d,%2d) %s ", USERCOLOR_ECHO_EMOTE, SocialPage + 1, SocialNum + 1, pSocialList[SocialIndex].Name);

				for (int LineIndex = 0; LineIndex < 5; LineIndex++)
				{
					if (pSocialList[SocialIndex].Line[LineIndex][0] != 0)
					{
						WriteChatf("  %d: %s", LineIndex + 1, pSocialList[SocialIndex].Line[LineIndex]);
					}
				}
			}
		}

		return;
	}

	int SocialIndex = -1;

	if (szBuffer[0] != 0)
	{
		// assume we have a social name to match
		// FIXME: Add a constant
		for (int index = 0; index < 120; index++)
		{
			if (!_stricmp(szBuffer, pSocialList[index].Name))
			{
				SocialIndex = index;
				break;
			}
		}
	}

	if (gCurrentSocial == -1)
	{
		gCurrentSocial = SocialIndex;
	}
	else
	{
		if (SocialIndex < 120)
		{
			for (int LineIndex = 0; LineIndex < 5; LineIndex++)
			{
				if (pSocialList[SocialIndex].Line[LineIndex][0] != 0)
					DoCommand(pChar, pSocialList[SocialIndex].Line[LineIndex]);
			}
		}
		else
		{
			if (szLine[0] != 0)
			{
				WriteChatf("Invalid Argument(s): %s", szLine);
			}

			SyntaxError("Usage: /dosocial <list|\"social name\">", USERCOLOR_DEFAULT);
		}
	}
}

// ***************************************************************************
// Function:    DoHotbutton
// Description: our '/hotbutton' command
//              Extends the built in /hotbutton command with multiple lines support
// Usage:       /hotbutton [Name] <color> <Line:><Cursor:>[Text]
//				<Line can be 1-5
//				<Cursor can ONLY be 0 which means DO NOT put the hotbutton on the cursor.
//				Usage:
//				/hotbutton TheName 14 1:0:/echo hi	(Where 14 1:0: in this case means use color 14, then place /echo hi on LINE 1 and NO Cursor Attachment.)
//				/hotbutton TheName 14 1:/echo hi	(Where 14 1: in this case means use color 14, then place /echo hi on LINE 1.)
//				/hotbutton TheName 1:0:/echo hi		(Where 1:0: in this case means place /echo hi on LINE 1 and NO Cursor Attachment.)
//				/hotbutton TheName 1:/echo hi		(Where 1: in this case means place /echo hi on LINE 1.)
//				/hotbutton TheName 0:/echo hi		(Where 0: in this case means NO Cursor Attachment.)
//				Finally, just doing /hotbutton TheName 14 /echo hi OR /hotbutton TheName /echo hi just calls the eq function like before.
// ***************************************************************************
void DoHotButton(PSPAWNINFO pChar, char* pBuffer)
{
	if (!pSocialList || !pSocialChangedList)
		return;

	DWORD SocialIndex = -1, LineIndex;
	DWORD SocialPage = 0, SocialNum = 0;
	int iColor = -1;
	int iLine = -1;
	int iCursor = 1;
	bool bUseEqFunction = true;
	CHAR szTemp[MAX_STRING] = { 0 };
	CHAR szName[MAX_STRING] = { 0 };
	CHAR szNext[MAX_STRING] = { 0 };
	CHAR szText[MAX_STRING] = { 0 };

	GetArg(szName, pBuffer, 1);
	GetArg(szNext, pBuffer, 2);

	int offset = 1;
	if (strchr(szName, ' ')) // the only way this can have a space in it, is if the user used quotes
	{
		offset = 3;
	}

	if (IsNumber(szNext))
	{
		// we have a color
		iColor = atoi(szNext);
		// that means the rest of the buffer IS Text
		int len = strlen(szName) + offset + strlen(szNext) + 1;
		strcpy_s(szText, &pBuffer[len]);
	}
	else
	{
		// no color detected, that means the rest of the buffer IS Text
		int len = strlen(szName) + offset;
		strcpy_s(szText, &pBuffer[len]);
	}

	// we have to check Text for line and cursor now...
	if (szText[0] == '0' && szText[1] == ':')
	{
		bUseEqFunction = false;

		// it's a <cursor> then cause line cant be 0;
		iCursor = 0;
		strcpy_s(szTemp, &szText[2]);
		strcpy_s(szText, szTemp);
		if (szText[1] == ':')
		{
			// the user is not using the command properly
			WriteChatf("/hotbutton ERROR: Line can only be a number between 1-5, you specified 0.");
			WriteChatf("Correct Usage Example1: \"/hotbutton %s 14 1:0:/echo hi\" (Where 14 1:0: in this case means use color 14, then place /echo hi on LINE 1 and NO Cursor Attachment.)", szName);
			WriteChatf("Correct Usage Example2: \"/hotbutton %s 14 1:/echo hi\" (Where 14 1: in this case means use color 14, then place /echo hi on LINE 1.)", szName);
			WriteChatf("Correct Usage Example3: \"/hotbutton %s 1:0:/echo hi\" (Where 1:0: in this case means place /echo hi on LINE 1 and NO Cursor Attachment.)", szName);
			WriteChatf("Correct Usage Example4: \"/hotbutton %s 1:/echo hi\" (Where 1: in this case means place /echo hi on LINE 1.)", szName);
			WriteChatf("Correct Usage Example5: \"/hotbutton %s 0:/echo hi\" (Where 0: in this case means NO Cursor Attachment.)", szName);
			return;
		}
	}
	else if (szText[0] == '1' || szText[0] == '2' || szText[0] == '3' || szText[0] == '4' || szText[0] == '5' && szText[1] == ':')
	{
		bUseEqFunction = false;

		// this is a line number
		szText[1] = '\0';
		iLine = atoi(szText);
		iLine--;
		strcpy_s(szTemp, &szText[2]);
		strcpy_s(szText, szTemp);
		if (szText[0] == '0' && szText[1] == ':')
		{
			iCursor = 0;
			strcpy_s(szTemp, &szText[2]);
			strcpy_s(szText, szTemp);
		}
	}

	if (!bUseEqFunction)
	{
		if (iLine == -1)
		{
			iLine = 0;
		}
		LineIndex = iLine;

		// it's a hotbutton command with a line number specified so we jump in, otherwise, lets jut eq handle it...
		for (SocialIndex = 0; SocialIndex < 120; SocialIndex++)
		{
			SocialPage = SocialIndex / 12;
			SocialNum = SocialIndex - (SocialPage * 12);

			if (pSocialList[SocialIndex].Name[0] == 0 || ci_equals(pSocialList[SocialIndex].Name, szName))
			{
				// found one we can use...
				strcpy_s(pSocialList[SocialIndex].Name, szName);
				if (iColor != -1)
				{
					pSocialList[SocialIndex].Color = (BYTE)iColor;
				}
				strcpy_s(pSocialList[SocialIndex].Line[LineIndex], szText);

				pSocialChangedList->bChanged[SocialPage][SocialNum] = true;

				if (iCursor)
				{
					pCursorAttachment->AttachToCursor(nullptr, nullptr, eCursorAttachment_Social, SocialIndex, szName, szText);
				}
				break;
			}
		}
		return;
	}

	if (pBuffer[0] == 0)
	{
		WriteChatf("Usage: /hotbutton [Name] <color> <Line:><Cursor:>[Text]\n<Line can be 1-5\n<Cursor can ONLY be 0 which means DO NOT put the hotbutton on the cursor.");
		WriteChatf("Example1: \"/hotbutton TheName 14 1:0:/echo hi\" (Where 14 1:0: in this case means use color 14, then place /echo hi on LINE 1 and NO Cursor Attachment.)");
		WriteChatf("Example2: \"/hotbutton TheName 14 1:/echo hi\" (Where 14 1: in this case means use color 14, then place /echo hi on LINE 1.)");
		WriteChatf("Example3: \"/hotbutton TheName 1:0:/echo hi\" (Where 1:0: in this case means place /echo hi on LINE 1 and NO Cursor Attachment.)");
		WriteChatf("Example4: \"/hotbutton TheName 1:/echo hi\" (Where 1: in this case means place /echo hi on LINE 1.)");
		WriteChatf("Example5: \"/hotbutton TheName 0:/echo hi\" (Where 0: in this case means NO Cursor Attachment.)");
	}

	cmdHotbutton(pChar, pBuffer);
}

// /timed
void DoTimedCmd(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /timed <deciseconds> <command>");
		return;
	}

	char szArg[MAX_STRING] = { 0 }; // delay
	GetArg(szArg, szLine, 1);

	char* szRest = GetNextArg(szLine);
	if (!szRest[0])
		return;

	TimedCommand(szRest, GetIntFromString(szArg, 0) * 100);
}

void ClearErrorsCmd(SPAWNINFO* pChar, char* szLine)
{
	gszLastNormalError[0] = 0;
	gszLastSyntaxError[0] = 0;
	gszLastMQ2DataError[0] = 0;
}

void CombineCmd(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /combine <pack>");
		return;
	}

	CXWnd* pWnd = FindMQ2Window(szLine);
	if (!pWnd)
	{
		MacroError("Window '%s' not open", szLine);
		return;
	}

	// TODO: Check this string logic
	if (*pWnd->GetWindowName() == "ContainerWindow")
	{
		CContainerWnd* pContainerWnd = static_cast<CContainerWnd*>(pWnd);
		pContainerWnd->HandleCombine();

		return;
	}

	MacroError("Window '%s' not container window", szLine);
}

void DropCmd(SPAWNINFO* pChar, char* szLine)
{
	PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return;

	if (pProfile->pInventoryArray && pProfile->pInventoryArray->Inventory.Cursor)
	{
		if (((EQ_Item*)pProfile->pInventoryArray->Inventory.Cursor)->CanDrop(0, 1))
		{
			pEverQuest->DropHeldItemOnGround(1);
		}
	}
}

void HudCmd(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /hud <normal|underui|always>");
		WriteChatColor("Note: 'always' forces 'underui' also. The Network Status indicator is not 'always' drawn and is toggled with F11.");
		return;
	}
	else if (!_stricmp(szLine, "normal"))
	{
		WritePrivateProfileString("MacroQuest", "HUDMode", "Normal", mq::internal_paths::MQini);
		gbAlwaysDrawMQHUD = false;
		gbHUDUnderUI = false;
	}
	else if (!_stricmp(szLine, "underui"))
	{
		WritePrivateProfileString("MacroQuest", "HUDMode", "UnderUI", mq::internal_paths::MQini);
		gbHUDUnderUI = true;
		gbAlwaysDrawMQHUD = false;
	}
	else if (!_stricmp(szLine, "always"))
	{
		WritePrivateProfileString("MacroQuest", "HUDMode", "Always", mq::internal_paths::MQini);
		gbHUDUnderUI = true;
		gbAlwaysDrawMQHUD = true;
	}
}

void NoParseCmd(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /noparse <command>");
		return;
	}

	if (gParserVersion == 2)
	{
		// To maintain backwards compatibility, but not rely on globals we need to wrap the parameters in a Parse Zero.
		// However, in the future it would be better to just do your command as /echo ${Parse[0,${Me.Name}]} to get the same functionality.
		// Cast it as a char*, Modify the line, and run the command
		std::string macroString = ModifyMacroString(szLine, true, ModifyMacroMode::WrapNoDoubles);

		DoCommand(pChar, &macroString[0]);
	}
	else
	{
		bAllowCommandParse = false;
		DoCommand(pChar, szLine);
		bAllowCommandParse = true;
	}
}

void AltAbility(SPAWNINFO* pChar, char* szLine)
{
	char szCommand[MAX_STRING] = { 0 };
	GetArg(szCommand, szLine, 1);
	char* szName = GetNextArg(szLine);

	if (szName[0] == 0 || szCommand[0] == 0)
	{
		SyntaxError("Usage: /aa list [all|timers], /aa info [ability name], or /aa act [ability name]");
		return;
	}

	if (!_stricmp(szCommand, "list"))
	{
		if (!_stricmp(szName, "all"))
		{
			WriteChatColor("Alternative Abilities (Complete List)", CONCOLOR_YELLOW);
			WriteChatColor("-------------------------------------", USERCOLOR_WHO);

			for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
			{
				if (ALTABILITY* pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility)))
				{
					WriteChatColorf("[ %d: %s ]", USERCOLOR_WHO, pAbility->ID,
						pCDBStr->GetString(pAbility->nName, eAltAbilityName));
				}
			}
		}
		else if (!_stricmp(szName, "timers"))
		{
			WriteChatColor("Alternative Abilities With Timers", CONCOLOR_YELLOW);
			WriteChatColor("---------------------------------", USERCOLOR_WHO);

			for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
			{
				if (ALTABILITY* pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility)))
				{
					if ((pAltAdvManager->GetCalculatedTimer(pPCData, pAbility)) > 0)
					{
						if (pAltAdvManager->IsAbilityReady(pPCData, pAbility, nullptr))
						{
							WriteChatColorf("[ %d: %s ] (Reuse Time: %d seconds) <Ready>", USERCOLOR_WHO,
								pAbility->ID, pCDBStr->GetString(pAbility->nName, eAltAbilityName),
								pAltAdvManager->GetCalculatedTimer((PcClient*)pPCData, pAbility));
						}
						else
						{
							int i = 0;
							pAltAdvManager->IsAbilityReady(pPCData, pAbility, &i);

							WriteChatColorf("[ %d: %s ] (Reuse Time: %d seconds) <Ready in %d seconds>",
								USERCOLOR_WHO, pAbility->ID, pCDBStr->GetString(pAbility->nName, eAltAbilityName),
								pAltAdvManager->GetCalculatedTimer(pPCData, pAbility), i);
						}
					}
				}
			}
		}
		else
		{
			SyntaxError("Usage: /aa list [all|timers], /aa info [ability name], or /aa act [ability name]");
			return;
		}
	}
	else if (!_stricmp(szCommand, "info"))
	{
		for (int nAbility = 0; nAbility < NUM_ALT_ABILITIES; nAbility++)
		{
			if (ALTABILITY* pAbility = GetAAByIdWrapper(nAbility))
			{
				const char* pName = pCDBStr->GetString(pAbility->nName, eAltAbilityName);
				if (!_stricmp(pName, szName))
				{
					WriteChatColor("Alternative Advancement Ability Information", CONCOLOR_YELLOW);
					WriteChatColor("-------------------------------------------", USERCOLOR_WHO);

					if ((pAltAdvManager->GetCalculatedTimer(pPCData, pAbility)) > 0)
					{
						// has a timer
						int i = 0;
						if (!pAltAdvManager->IsAbilityReady(pPCData, pAbility, &i))
						{
							// it's not ready
							WriteChatColorf("[ %d: %s ] %s", USERCOLOR_WHO, pAbility->ID, pName, pCDBStr->GetString(pAbility->nName, eAltAbilityDescription));
							WriteChatColorf("Min Level: %d, Cost: %d, Max Rank: %d, Type: %d, Reuse Time: %d seconds", USERCOLOR_WHO,
								pAbility->MinLevel, pAbility->Cost, pAbility->MaxRank, pAbility->Type, pAltAdvManager->GetCalculatedTimer(pPCData, pAbility));

							if (pAbility->SpellID > 0)
							{
								WriteChatColorf("Casts Spell: %s", USERCOLOR_WHO, GetSpellNameByID(pAbility->SpellID));
							}

							if (PlayerHasAAAbility(pAbility->Index))
							{
								WriteChatColorf("Ready: No (%d seconds until refresh)", USERCOLOR_WHO, i);
							}
							else
							{
								WriteChatColor("Ready: Not Purchased", USERCOLOR_WHO);
							}
						}
						else
						{
							WriteChatColorf("[ %d: %s ] %s", USERCOLOR_WHO, pAbility->ID, pName, pCDBStr->GetString(pAbility->nName, eAltAbilityDescription));
							WriteChatColorf("Min Level: %d, Cost: %d, Max Rank: %d, Type: %d, Reuse Time: %d seconds", USERCOLOR_WHO,
								pAbility->MinLevel, pAbility->Cost, pAbility->MaxRank, pAbility->Type, pAltAdvManager->GetCalculatedTimer(pPCData, pAbility));

							if (pAbility->SpellID > 0)
							{
								WriteChatColorf("Casts Spell: %s", USERCOLOR_WHO, GetSpellNameByID(pAbility->SpellID));
							}

							WriteChatColorf("Ready: Yes", USERCOLOR_WHO);
						}
					}
					else
					{
						int i = 0;
						pAltAdvManager->IsAbilityReady(pPCData, pAbility, &i);

						WriteChatColorf("[ %d: %s ] %s", USERCOLOR_WHO, pAbility->ID, pName, pCDBStr->GetString(pAbility->nName, eAltAbilityName));
						WriteChatColorf("Min Level: %d, Cost: %d, Max Rank: %d, Type: %d", USERCOLOR_WHO,
							pAbility->MinLevel, pAbility->Cost, pAbility->MaxRank, pAbility->Type);

						if (pAbility->SpellID > 0)
						{
							WriteChatColorf("Casts Spell: %s", USERCOLOR_WHO, GetSpellNameByID(pAbility->SpellID));
						}
					}
				}
			}
		}
	}
	else if (!_stricmp(szCommand, "act"))
	{
		// we want to get the rank thats for our level here
		int level = -1;

		if (SPAWNINFO* pMe = (SPAWNINFO*)pLocalPlayer)
		{
			level = pMe->Level;
		}

		// only search through the ones we have...
		for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
		{
			if (ALTABILITY* pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility), level))
			{
				if (const char* pName = pCDBStr->GetString(pAbility->nName, eAltAbilityName))
				{
					if (!_stricmp(szName, pName))
					{
						char szBuffer[MAX_STRING] = { 0 };
						sprintf_s(szBuffer, "/alt act %d", pAbility->ID);
						DoCommand(pChar, szBuffer);
						break;
					}
				}
			}
		}
	}
	else
	{
		SyntaxError("Usage: /aa list [all|timers|ready], /aa info [ability name], or /aa act [ability name]");
	}
}

// ***************************************************************************
// Function:    Echo
// Description: Our '/echo' command
//              Echos text to the chatbox
// Usage:       /echo <text>
// ***************************************************************************
void Echo(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;

	char szEcho[MAX_STRING] = { 0 };
	strcpy_s(szEcho, DebugHeader);
	strcat_s(szEcho, " ");
	int NewPos = strlen(DebugHeader) + 1, OldPos = 0;

	if (szLine)
	{
		while (OldPos < (int)strlen(szLine))
		{
			if (szLine[OldPos] == '\\')
			{
				OldPos++;
				if (szLine[OldPos])
				{
					if (szLine[OldPos] == '\\')
						szEcho[NewPos] = szLine[OldPos];
					else if (szLine[OldPos] == 'n')
					{
						szEcho[NewPos++] = '\r';
						szEcho[NewPos] = '\n';
					}
					else if (szLine[OldPos] >= 'a' && szLine[OldPos] <= 'z')
					{
						szEcho[NewPos] = szLine[OldPos] - 'a' + 7;
					}
					else if (szLine[OldPos] >= 'A' && szLine[OldPos] <= 'Z')
					{
						szEcho[NewPos] = szLine[OldPos] - 'a' + 7;
					}

					NewPos++;
					OldPos++;
				}
			}
			else
			{
				szEcho[NewPos] = szLine[OldPos];
				NewPos++;
				OldPos++;
			}

			szEcho[NewPos] = 0;
		}
	}

	WriteChatColor(szEcho, USERCOLOR_CHAT_CHANNEL);
}

// ***************************************************************************
// Function:    LootAll
// Description: Our '/lootall' command
//              Loots everything on the targeted corpse
// Usage:       /lootall
// ***************************************************************************
void LootAll(SPAWNINFO* pChar, char* szLine)
{
	pLootWnd->LootAll(true);
}

// ***************************************************************************
// Function:    SetWinTitle
// Description: Our '/setwintitle' command
//              Set the Window Title
// Usage:       /setwintitle <something something>
// ***************************************************************************
void SetWinTitle(SPAWNINFO* pChar, char* szLine)
{
	HWND hEQWnd = GetEQWindowHandle();

	if (hEQWnd)
	{
		if (szLine && szLine[0] != '\0')
		{
			SetWindowText(hEQWnd, szLine);
		}
	}
}

// ***************************************************************************
// Function:    GetWinTitle
// Description: Our '/getwintitle' command
//              Gets the Window Title
// Usage:       /getwintitle
// ***************************************************************************
void GetWinTitle(SPAWNINFO* pChar, char* szLine)
{
	HWND hEQWnd = GetEQWindowHandle();

	if (hEQWnd)
	{
		if (GetWindowTextA(hEQWnd, szLine, 255) && szLine[0] != 0)
		{
			WriteChatf("Window Title: \ay%s\ax", szLine);
		}
	}
}

// ***************************************************************************
// Function:    PetCmd
// Description: '/pet' command
//              Adds the ability to do /pet attack #id
// Usage:       /pet attack 1234 or whatever the spawnid is you want the pet to attack
// ***************************************************************************
void PetCmd(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine[0])
	{
		WriteChatColor("Usage: /pet attack/qattack # where # is the spawnid of the mob you want the pet to attack");
		cmdPet(pChar, szLine);
		return;
	}

	char szCmd[MAX_STRING] = { 0 };
	GetArg(szCmd, szLine, 1);

	ePetCommandType cmdtype = PCT_DoNothing;

	if (!_stricmp(szCmd, "attack"))
	{
		cmdtype = PCT_Attack;
	}
	else if (!_stricmp(szCmd, "qattack"))
	{
		cmdtype = PCT_QueueAttack;
	}

	if (cmdtype)
	{
		char szID[MAX_STRING] = { 0 };
		GetArg(szID, szLine, 2);

		if (IsNumber(szID))
		{
			if (SPAWNINFO* pSpawn = (SPAWNINFO*)GetSpawnByID(GetIntFromString(szID, 0)))
			{
				pEverQuest->IssuePetCommand(cmdtype, pSpawn->SpawnID, false);
				return;
			}
		}
	}

	cmdPet(pChar, szLine);
}

// ***************************************************************************
// Function:    MercSwitchCmd
// Description: '/mercswitch' command
//              Adds the ability to do /mercswitch Healer,Damage Caster,Melee Damage or Tank
// Usage:       /mercswitch healer will switch to a Healer merc
// ***************************************************************************
void MercSwitchCmd(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine[0])
	{
		WriteChatColor("Usage: /mercswitch <Healer,Damage Caster,Melee Damage or Tank>");
		cmdMercSwitch(pChar, szLine);
		return;
	}

	std::map<int, MercDesc> descmap;
	GetAllMercDesc(descmap);

	for (auto& n : descmap)
	{
		if (ci_equals(n.second.Type, szLine))
		{
			char szTemp[256] = { 0 };
			sprintf_s(szTemp, "%d", n.first + 1);

			cmdMercSwitch(pChar, szTemp);
			return;
		}
	}

	cmdMercSwitch(pChar, szLine);
}

// ***************************************************************************
// Function:    AdvLootCmd
// Description: '/advloot' command
//              Extend the /advloot command to accept some parameters:
// Usage: /advloot personal #(listid)| loot,leave,an,ag,never
// Or:    /advloot shared #(listid) item,status,action,manage,autoroll,nd,gd,no,an,ag,nv,name
// Or:    /advloot shared set "item from the shared set to all combo box, can be player name any of the other items that exist in that box..."
// ***************************************************************************

void AdvLootCmd(SPAWNINFO* pChar, char* szLine)
{
	if (GetGameState() != GAMESTATE_INGAME)
		return;

	char szAction[MAX_STRING] = { 0 };
	GetArg(szAction, szLine, 3);

	if (!szLine[0] || !szAction[0])
	{
		WriteChatColor(R"(Usage: /advloot personal #(listid) item,loot,leave,an,ag,never,name)");
		WriteChatColor(R"(Or:    /advloot shared <#(listid) or \"item name\"> item,status,action,manage,autoroll,nd,gd,no,an,ag,nv,name)");
		WriteChatColor(R"(Or:    you can "Give To:" /advloot shared <#(listid) or "Item Name"> giveto <name> <qty>)");
		WriteChatColor(R"(Or:    you can "Leave on Corpse" /advloot shared <#(listid) or "Item Name"> leave)");
		WriteChatColor(R"(Or:    /advloot shared set "name from the shared set to all combo box, can be player name or any of the other names that exist in that box...")");
		cmdAdvLoot(pChar, szLine);
		return;
	}

	if (pAdvancedLootWnd)
	{
		CListWnd* pPersonalList = (CListWnd*)pAdvancedLootWnd->GetChildItem("ADLW_PLLList");
		CListWnd* pSharedList = nullptr;

		if (pAdvancedLootWnd->pCLootList)
		{
			pSharedList = (CListWnd*)pAdvancedLootWnd->pCLootList->SharedLootList;
		}

		// we dont know if we have a user that checks if loot is in progress in his macro, so we do that for him here
		if (LootInProgress(pAdvancedLootWnd, pPersonalList, pSharedList))
		{
			MacroError("Woah! hold your horses there little filly... You better add a !${AdvLoot.LootInProgress} check in your macro to make sure loot is not in progress.");
			return;
		}

		char szCmd[MAX_STRING] = { 0 };
		GetArg(szCmd, szLine, 1);

		int cmdtype = 0;
		if (!_stricmp(szCmd, "personal"))
		{
			cmdtype = 2;
		}
		else if (!_stricmp(szCmd, "shared"))
		{
			cmdtype = 3;
		}

		AdvancedLootItem* pitem = nullptr;

		if (cmdtype == 2)
		{
			char szID[MAX_STRING] = { 0 };
			GetArg(szID, szLine, 2);

			int index = -1;

			if (pPersonalList)
			{
				if (IsNumber(szID))
				{
					index = GetIntFromString(szID, index) - 1;
				}
				else
				{
					// if its not a number its a itemname
					// need to roll through the list to get the index
					if (pAdvancedLootWnd->pPLootList)
					{
						for (int k = 0; k < pPersonalList->ItemsArray.Count; k++)
						{
							int listindex = (int)pPersonalList->GetItemData(k);
							if (listindex != -1)
							{
								AdvancedLootItem& item = pAdvancedLootWnd->pPLootList->Items[listindex];

								if (!_stricmp(item.Name, szID))
								{
									index = k;
									break;
								}
							}
						}
					}
				}

				int listindex = (int)pPersonalList->GetItemData(index);
				if (pAdvancedLootWnd && pAdvancedLootWnd->pPLootList && listindex != -1)
				{
					if (!_stricmp(szAction, "loot"))
					{
						if (CXWnd* pwnd = GetAdvLootPersonalListItem(listindex, 2)) // loot
						{
							SendWndClick2(pwnd, "leftmouseup");
						}
					}
					else if (!_stricmp(szAction, "leave"))
					{
						if (CXWnd* pwnd = GetAdvLootPersonalListItem(listindex, 3)) // leave
						{
							SendWndClick2(pwnd, "leftmouseup");
						}
					}
					else if (!_stricmp(szAction, "name"))
					{
						if (CXWnd* pwnd = GetAdvLootPersonalListItem(listindex, 0)) // name
						{
							SendWndClick2(pwnd, "leftmouseup");
						}
					}
					else if (!_stricmp(szAction, "item"))
					{
						if (CXWnd* pwnd = GetAdvLootPersonalListItem(listindex, 1)) // item
						{
							SendWndClick2(pwnd, "leftmouseup");
						}
					}
					else if (!_stricmp(szAction, "never"))
					{
						if (CXWnd* pwnd = GetAdvLootPersonalListItem(listindex, 4)) // never
						{
							SendWndClick2(pwnd, "leftmouseup");
						}
					}
					else if (!_stricmp(szAction, "an"))
					{
						if (CXWnd* pwnd = GetAdvLootPersonalListItem(listindex, 5)) // an
						{
							SendWndClick2(pwnd, "leftmouseup");
						}
					}
					else if (!_stricmp(szAction, "ag"))
					{
						if (CXWnd* pwnd = GetAdvLootPersonalListItem(listindex, 6)) // ag
						{
							SendWndClick2(pwnd, "leftmouseup");
						}
					}
				}
			}
			return;
		}

		if (cmdtype == 3)
		{
			char szID[MAX_STRING] = { 0 };
			GetArg(szID, szLine, 2);

			if (!_stricmp(szID, "set"))
			{
				char szEntity[MAX_STRING] = { 0 };
				GetArg(szEntity, szLine, 3);

				if (CComboWnd* pCombo = (CComboWnd*)pAdvancedLootWnd->GetChildItem("ADLW_CLLSetCmbo"))
				{
					if (CListWnd* pListWnd = pCombo->pListWnd)
					{
						for (int i = 0; i < pCombo->GetItemCount(); i++)
						{
							CXStr str = pListWnd->GetItemText(i, 0);
							if (!str.empty())
							{
								if (!_stricmp(szEntity, str.c_str()))
								{
									CXPoint combopt = pCombo->GetScreenRect().CenterPoint();
									pCombo->SetChoice(i);
									pCombo->HandleLButtonDown(combopt, 0);
									int index = pListWnd->GetCurSel();
									CXRect listrect = pListWnd->GetItemRect(index, 0);
									CXPoint listpt = listrect.CenterPoint();
									pListWnd->HandleLButtonDown(listpt, 0);
									pListWnd->HandleLButtonUp(listpt, 0);
									gMouseEventTime = GetFastTime();

									if (CXWnd* pButton = pAdvancedLootWnd->GetChildItem("ADLW_CLLSetBtn"))
									{
										SendWndClick2(pButton, "leftmouseup");
									}
									break;
								}
							}
						}
					}
				}
				return;
			}

			int index = -1;
			if (IsNumber(szID))
			{
				index = GetIntFromString(szID, index) - 1;
			}
			else
			{
				// if its not a number its a itemname
				// need to roll through the list to get the index
				if (pSharedList)
				{
					for (int k = 0; k < pSharedList->ItemsArray.Count; k++)
					{
						int listindex = (int)pSharedList->GetItemData(k);
						if (listindex != -1)
						{
							AdvancedLootItem& item = pAdvancedLootWnd->pCLootList->Items[listindex];
							if (!_stricmp(item.Name, szID))
							{
								index = k;
								break;
							}
						}
					}
				}
			}

			if (index != -1)
			{
				if (pSharedList)
				{
					int listindex = (int)pSharedList->GetItemData(index);
					if (listindex != -1)
					{
						AdvancedLootItem& item = pAdvancedLootWnd->pCLootList->Items[listindex];
						if (!_stricmp(szAction, "leave"))
						{
							if (CHARINFO * pchar = GetCharInfo())
							{
								if (GetGameState() == GAMESTATE_INGAME && pitem && pitem->LootDetails.GetSize())
								{
									pAdvancedLootWnd->DoSharedAdvLootAction(pitem, pchar->Name, true, pitem->LootDetails[0].StackCount);
								}
							}
						}
						else if (!_stricmp(szAction, "giveto"))
						{
							char szEntity[MAX_STRING] = { 0 };
							GetArg(szEntity, szLine, 4);
							char szQty[MAX_STRING] = { 0 };
							GetArg(szQty, szLine, 5);

							if (szEntity[0] != '\0')
							{
								if (CHARINFO* pCI = GetCharInfo())
								{
									CXStr out;

									if (pCI->pGroupInfo)
									{
										for (auto& member : pCI->pGroupInfo->pMember)
										{
											if (member
												&& member->Type == EQP_PC
												&& !member->Name.empty())
											{
												if (!_stricmp(member->Name.c_str(), szEntity))
												{
													out = member->Name;
													break;
												}
											}
										}
									}

									// not found? check raid
									if (out.empty())
									{
										if (pRaid && pRaid->RaidMemberCount)
										{
											for (DWORD nMember = 0; nMember < 72; nMember++)
											{
												if (pRaid->RaidMemberUsed[nMember] && !_stricmp(pRaid->RaidMember[nMember].Name, szEntity))
												{
													out = pRaid->RaidMember[nMember].Name;
													break;
												}
											}
										}
									}

									if (!_stricmp(out.c_str(), szEntity))
									{
										// TODO: Check array usage
										int qty = GetIntFromString(szQty, 0);
										if (pitem && !pitem->LootDetails.IsEmpty())
										{
											if (qty == 0 || qty > pitem->LootDetails[0].StackCount)
											{
												qty = pitem->LootDetails[0].StackCount;
												if (qty == 0)
												{
													qty = 1;
												}
											}

											pAdvancedLootWnd->DoSharedAdvLootAction(pitem, out, 0, qty);
											return;
										}
									}
								}
							}
						}
						else if (!_stricmp(szAction, "name"))
						{
							if (CXWnd* pwnd = GetAdvLootSharedListItem(listindex, 0))
							{
								SendWndClick2(pwnd, "leftmouseup");
							}
						}
						else if (!_stricmp(szAction, "item"))
						{
							if (CXWnd* pwnd = GetAdvLootSharedListItem(listindex, 1))
							{
								SendWndClick2(pwnd, "leftmouseup");
							}
						}
						else if (!_stricmp(szAction, "status"))
						{
							if (CXWnd* pwnd = GetAdvLootSharedListItem(listindex, 2))
							{
								SendWndClick2(pwnd, "leftmouseup");
							}
						}
						else if (!_stricmp(szAction, "action"))
						{
							if (CXWnd* pwnd = GetAdvLootSharedListItem(listindex, 3))
							{
								SendWndClick2(pwnd, "leftmouseup");
							}
						}
						else if (!_stricmp(szAction, "manage"))
						{
							if (CXWnd* pwnd = GetAdvLootSharedListItem(listindex, 4))
							{
								SendWndClick2(pwnd, "leftmouseup");
							}
						}
						else if (!_stricmp(szAction, "an"))
						{
							if (CXWnd* pwnd = GetAdvLootSharedListItem(listindex, 5))
							{
								SendWndClick2(pwnd, "leftmouseup");
							}
						}
						else if (!_stricmp(szAction, "ag"))
						{
							if (CXWnd* pwnd = GetAdvLootSharedListItem(listindex, 6))
							{
								SendWndClick2(pwnd, "leftmouseup");
							}
						}
						else if (!_stricmp(szAction, "autoroll"))
						{
							if (CXWnd * pwnd = GetAdvLootSharedListItem(listindex, 7))
							{
								SendWndClick2(pwnd, "leftmouseup");
							}
						}
						else if (!_stricmp(szAction, "nv"))
						{
							if (CXWnd* pwnd = GetAdvLootSharedListItem(listindex, 8))
							{
								SendWndClick2(pwnd, "leftmouseup");
							}
						}
						else if (!_stricmp(szAction, "nd"))
						{
							if (CXWnd* pwnd = GetAdvLootSharedListItem(listindex, 9))
							{
								SendWndClick2(pwnd, "leftmouseup");
							}
						}
						else if (!_stricmp(szAction, "gd"))
						{
							if (CXWnd* pwnd = GetAdvLootSharedListItem(listindex, 10))
							{
								SendWndClick2(pwnd, "leftmouseup");
							}
						}
						else if (!_stricmp(szAction, "no"))
						{
							if (CXWnd* pwnd = GetAdvLootSharedListItem(listindex, 11))
							{
								SendWndClick2(pwnd, "leftmouseup");
							}
						}
					}
				}
			}
			return;
		}

		cmdAdvLoot(pChar, szLine);
	}
}

static std::recursive_mutex s_openPickZoneWndMutex;

// FIXME: Never do this
DWORD CALLBACK openpickzonewnd(void* pData)
{
	std::scoped_lock lock(s_openPickZoneWndMutex);

	int nInst = (int)pData;
	char szInst[32] = { 0 };
	_itoa_s(nInst, szInst, 10);

	// this thread is definitely not threadsafe. BEWARE!

	CHARINFO* pCharInfo = GetCharInfo();
	if (!pCharInfo)
		return 0;

	cmdPickZone(pCharInfo->pSpawn, nullptr);
	Sleep(2000); // i need to make this hardcoded wait dynamic but im in a hurry ill do it later -eqmule

	CXWnd* zoneSelectWnd = FindMQ2Window("MIZoneSelectWnd");
	if (!zoneSelectWnd)
		return 0;

	if (!zoneSelectWnd->IsVisible())
		return 0;

	CListWnd* pListWnd = (CListWnd*)zoneSelectWnd->GetChildItem("MIZ_ZoneList");
	CButtonWnd* pButtonWnd = (CButtonWnd*)zoneSelectWnd->GetChildItem("MIZ_SelectButton");

	if (pListWnd->ItemsArray.IsEmpty())
		return 0;

	bool isMain = false;
	bool doClick = false;

	for (int i = 0; i < pListWnd->ItemsArray.GetCount(); i++)
	{
		CXStr Str = pListWnd->GetItemText(i, 0);
		if (Str.empty())
			continue;

		std::string s{ Str };

		if (s.find_first_of("123456789") == std::string::npos)
		{
			isMain = true;
		}

		if (isMain && nInst == 0)
		{
			doClick = true;
		}
		else if (nInst >= 1)
		{
			if (std::string::npos != s.find(szInst))
			{
				doClick = true;
			}
		}

		if (doClick)
		{
			SendListSelect("MIZoneSelectWnd", "MIZ_ZoneList", i);
			Sleep(500);
			SendWndClick2(pButtonWnd, "leftmouseup");
			WriteChatf("%s selected.", Str.c_str());
			return 0;
		}
	}

	WriteChatf("%s instance %d NOT found in list", GetFullZone(pCharInfo->zoneId), nInst);
	return 0;
}

// ***************************************************************************
// Function:    PickZoneCmd
// Description: '/pickzone' command
//              Adds the ability to do /pickzone #
// Usage:       /pickzone 2 will switch zone to number 2 pickzone 0 will pick main instance
// ***************************************************************************
void PickZoneCmd(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine[0])
	{
		WriteChatColor("Usage: /pick # where # is the instance number you want to pick");
		cmdPickZone(pChar, szLine);
		return;
	}

	int index = GetIntFromString(szLine, 0);
	CreateThread(nullptr, 0, openpickzonewnd, (void*)index, 0, nullptr);
}

// ***************************************************************************
// Function:    QuitCmd
// Description: '/quit' command
// Purpose:     Adds the ability to /quit at charselect
// Author:      EqMule
// ***************************************************************************
void QuitCmd(SPAWNINFO* pChar, char* szLine)
{
	if (GetGameState() != GAMESTATE_INGAME)
	{
		if (HANDLE hHandle = OpenProcess(PROCESS_TERMINATE, 0, GetCurrentProcessId()))
		{
			TerminateProcess(hHandle, 0);
		}
	}

	cmdQuit(pChar, szLine);
}

// ***************************************************************************
// Function:    AssistCmd
// Description: '/assist' command
// Purpose:     Adds the ability to forward /assist so we can set the gbAssist flag
// Author:      EqMule
// ***************************************************************************
void AssistCmd(SPAWNINFO* pChar, char* szLine)
{
	gbAssistComplete = AS_None;
	cmdAssist(pChar, szLine);
}

// ***************************************************************************
// Function:    SetProcessPriority
// Description: '/setprio' command
// Purpose:     Adds the ability to set the process priority
// Example:		/setprio <1-6> Where 1 is Low, 2 is below Normal, 3 is Normal, 4 is Above Normal, 5 is High, and 6 is RealTime
// Author:      EqMule
// ***************************************************************************
void SetProcessPriority(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine || szLine[0] == 0)
	{
		WriteChatf("Usage: /setprio <1-6> Where 1 is Low 2 is Below Normal 3 is Normal 4 is Above Normal 5 is High and 6 is RealTime");
		return;
	}

	HANDLE hProcess = OpenProcess(PROCESS_SET_INFORMATION, false, GetCurrentProcessId());
	if (!hProcess)
	{
		WriteChatf("Process Priority was NOT changed, Could not open Process");
		return;
	}

	switch (GetIntFromString(szLine, 3))
	{
	case 1:
		SetPriorityClass(hProcess, IDLE_PRIORITY_CLASS);
		WriteChatf("Process Priority Set to \agLOW\ax");
		break;

	case 2:
		SetPriorityClass(hProcess, BELOW_NORMAL_PRIORITY_CLASS);
		WriteChatf("Process Priority Set to \agBELOW NORMAL\ax");
		break;

	case 3:
		SetPriorityClass(hProcess, NORMAL_PRIORITY_CLASS);
		WriteChatf("Process Priority Set to \agNORMAL\ax");
		break;

	case 4:
		SetPriorityClass(hProcess, ABOVE_NORMAL_PRIORITY_CLASS);
		WriteChatf("Process Priority Set to \agABOVE NORMAL\ax");
		break;

	case 5:
		SetPriorityClass(hProcess, HIGH_PRIORITY_CLASS);
		WriteChatf("Process Priority Set to \agHIGH\ax");
		break;

	case 6:
		SetPriorityClass(hProcess, REALTIME_PRIORITY_CLASS);
		WriteChatf("Process Priority Set to \agREALTIME\ax");
		break;

	default:
		SetPriorityClass(hProcess, NORMAL_PRIORITY_CLASS);
		WriteChatf("Process Priority Set to \agREALTIME\ax");
		break;
	}

	CloseHandle(hProcess);
}

// ***************************************************************************
// Function:    ScreenModeCmd
// Description: '/screenmode' command
// Purpose:     Adds the ability to set the screenmode
// Example:		/screenmode <#> Where 2 is Normal and 3 is No Windows
// Author:      EqMule
// ***************************************************************************
void ScreenModeCmd(SPAWNINFO* pChar, char* szLine)
{
	if (szLine && szLine[0] == '\0')
	{
		WriteChatf("Usage: /screenmode <#>");
		return;
	}

	int newprio = GetIntFromString(szLine, 2);
	ScreenMode = newprio;
	WriteChatf("Screen Mode Set to \ag%d\ax", newprio);
}

// ***************************************************************************
// Function:    UserCameraCmd
// Description: '/usercamera' command
// Purpose:     Adds the ability to load and save the User 1 Camera
// Example:     /usercamera on/off toggle the camera text in the Window Selector on/off
// Example:     /usercamera save saves the user 1 camera settings
// Example:     /usercamera load loades the user 1 camera settings
// Author:      EqMule
// ***************************************************************************
void UserCameraCmd(SPAWNINFO* pChar, char* szLine)
{
	if (szLine && szLine[0] == '\0')
	{
		WriteChatf("Usage: /usercamera 0-7 sets camera to the number specified.");
		WriteChatf("Usage: /usercamera save <optional charname> to save the user 1 camera");
		WriteChatf("Usage: /usercamera load <optional charname> to load your saved user 1 camera");
		WriteChatf("Usage: /usercamera on/off to toggle Window Selector Display of Current Camera");
		return;
	}

	char szArg1[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);

	char szArg2[MAX_STRING] = { 0 };
	GetArg(szArg2, szLine, 2);

	EQCAMERABASE* pUserCam1 = (EQCAMERABASE*)((DWORD*)EverQuest__Cameras)[EQ_USER_CAM_1];

	if (!_stricmp(szArg1, "0"))
	{
		*(DWORD*)CDisplay__cameraType = EQ_FIRST_PERSON_CAM;
	}
	else if (!_stricmp(szArg1, "1"))
	{
		*(DWORD*)CDisplay__cameraType = EQ_OVERHEAD_CAM;
	}
	else if (!_stricmp(szArg1, "2"))
	{
		*(DWORD*)CDisplay__cameraType = EQ_CHASE_CAM;
	}
	else if (!_stricmp(szArg1, "3"))
	{
		*(DWORD*)CDisplay__cameraType = EQ_USER_CAM_1;
	}
	else if (!_stricmp(szArg1, "4"))
	{
		*(DWORD*)CDisplay__cameraType = EQ_USER_CAM_2;
	}
	else if (!_stricmp(szArg1, "5"))
	{
		*(DWORD*)CDisplay__cameraType = 5;
	}
	else if (!_stricmp(szArg1, "6"))
	{
		*(DWORD*)CDisplay__cameraType = 6;
	}
	else if (!_stricmp(szArg1, "7"))
	{
		*(DWORD*)CDisplay__cameraType = 7;
	}
	else if (!_stricmp(szArg1, "on"))
	{
		gbShowCurrentCamera = true;
		WritePrivateProfileBool("MacroQuest", "ShowCurrentCamera", gbShowCurrentCamera, mq::internal_paths::MQini);

		if (pSelectorWnd)
		{
			char szOut[64] = { 0 };
			sprintf_s(szOut, "Selector Window (Camera %d)", *(DWORD*)CDisplay__cameraType);

			pSelectorWnd->SetWindowText(szOut);
		}
	}
	else if (!_stricmp(szArg1, "off"))
	{
		gbShowCurrentCamera = false;
		WritePrivateProfileBool("MacroQuest", "ShowCurrentCamera", gbShowCurrentCamera, mq::internal_paths::MQini);

		if (pSelectorWnd)
		{
			pSelectorWnd->SetWindowText("Selector Window");
		}
	}
	else if (!_stricmp(szArg1, "save"))
	{
		std::string pathIniFile = mq::internal_paths::MQini;

		if (szArg2 && szArg2[0] != '\0')
		{
			const std::string tmpFileName = std::string(EQADDR_SERVERNAME) + "_" + std::string(szArg2) + ".ini";
			pathIniFile = (std::filesystem::path(mq::internal_paths::Config) / tmpFileName).string();
		}

		WritePrivateProfileBool("User Camera 1", "bAutoHeading", pUserCam1->bAutoHeading, pathIniFile);
		WritePrivateProfileBool("User Camera 1", "bAutoPitch", pUserCam1->bAutoPitch, pathIniFile);
		WritePrivateProfileBool("User Camera 1", "bSkipFrame", pUserCam1->bSkipFrame, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "DirectionalHeading", pUserCam1->DirectionalHeading, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "Distance", pUserCam1->Distance, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "Heading", pUserCam1->Heading, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "Height", pUserCam1->Height, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "OldPosition_X", pUserCam1->OldPosition_X, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "OldPosition_Y", pUserCam1->OldPosition_Y, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "OldPosition_Z", pUserCam1->OldPosition_Z, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "Orientation_X", pUserCam1->Orientation_X, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "Orientation_Y", pUserCam1->Orientation_Y, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "Orientation_Z", pUserCam1->Orientation_Z, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "Pitch", pUserCam1->Pitch, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "SideMovement", pUserCam1->SideMovement, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "Zoom", pUserCam1->Zoom, pathIniFile);
	}
	else if (!_stricmp(szArg1, "load"))
	{
		std::string pathIniFile = mq::internal_paths::MQini;

		if (szArg2 && szArg2[0] != '\0')
		{
			const std::string tmpFileName = std::string(EQADDR_SERVERNAME) + "_" + std::string(szArg2) + ".ini";
			pathIniFile = (std::filesystem::path(mq::internal_paths::Config) / tmpFileName).string();
		}

		pUserCam1->bAutoHeading = GetPrivateProfileBool("User Camera 1", "bAutoHeading", pUserCam1->bAutoHeading, pathIniFile);
		pUserCam1->bAutoPitch = GetPrivateProfileBool("User Camera 1", "bAutoPitch", pUserCam1->bAutoPitch, pathIniFile);
		pUserCam1->bSkipFrame = GetPrivateProfileBool("User Camera 1", "bSkipFrame", pUserCam1->bSkipFrame, pathIniFile);
		pUserCam1->DirectionalHeading = GetPrivateProfileFloat("User Camera 1", "DirectionalHeading", pUserCam1->DirectionalHeading, pathIniFile);
		pUserCam1->Distance = GetPrivateProfileFloat("User Camera 1", "Distance", pUserCam1->Distance, pathIniFile);
		pUserCam1->Heading = GetPrivateProfileFloat("User Camera 1", "Heading", pUserCam1->Heading, pathIniFile);
		pUserCam1->Height = GetPrivateProfileFloat("User Camera 1", "Height", pUserCam1->Height, pathIniFile);
		pUserCam1->OldPosition_X = GetPrivateProfileFloat("User Camera 1", "OldPosition_X", pUserCam1->OldPosition_X, pathIniFile);
		pUserCam1->OldPosition_Y = GetPrivateProfileFloat("User Camera 1", "OldPosition_Y", pUserCam1->OldPosition_Y, pathIniFile);
		pUserCam1->OldPosition_Z = GetPrivateProfileFloat("User Camera 1", "OldPosition_Z", pUserCam1->OldPosition_Z, pathIniFile);
		pUserCam1->Orientation_X = GetPrivateProfileFloat("User Camera 1", "Orientation_X", pUserCam1->Orientation_X, pathIniFile);
		pUserCam1->Orientation_Y = GetPrivateProfileFloat("User Camera 1", "Orientation_Y", pUserCam1->Orientation_Y, pathIniFile);
		pUserCam1->Orientation_Z = GetPrivateProfileFloat("User Camera 1", "Orientation_Z", pUserCam1->Orientation_Z, pathIniFile);
		pUserCam1->Pitch = GetPrivateProfileFloat("User Camera 1", "Pitch", pUserCam1->Pitch, pathIniFile);
		pUserCam1->SideMovement = GetPrivateProfileFloat("User Camera 1", "SideMovement", pUserCam1->SideMovement, pathIniFile);
		pUserCam1->Zoom = GetPrivateProfileFloat("User Camera 1", "Zoom", pUserCam1->Zoom, pathIniFile);

		*(DWORD*)CDisplay__cameraType = EQ_USER_CAM_1;
	}
}

void SetForegroundWindowInternal(HWND hWnd)
{
	if (!IsWindow(hWnd)) return;

	BYTE keyState[256] = { 0 };
	//to unlock SetForegroundWindow we need to imitate Alt pressing
	if (GetKeyboardState((LPBYTE)& keyState))
	{
		if (!(keyState[VK_MENU] & 0x80))
		{
			keybd_event(VK_MENU, 0, KEYEVENTF_EXTENDEDKEY | 0, 0);
		}
	}

	SetForegroundWindow(hWnd);
	ShowWindow(hWnd, SW_SHOWNORMAL);

	if (GetKeyboardState((LPBYTE)& keyState))
	{
		if (keyState[VK_MENU] & 0x80)
		{
			keybd_event(VK_MENU, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
		}
	}
}

// ***************************************************************************
// Function:    ForeGroundCmd
// Description: '/foreground' command
// Purpose:     Adds the ability to move your eq window to the foreground.
// Usage:       /foreground
// Example:     /bct <toonname> //foreground
// Author:      EqMule
// ***************************************************************************
void ForeGroundCmd(SPAWNINFO* pChar, char* szLine)
{
	HWND EQhWnd = GetEQWindowHandle();

	// Is this even necessary?
	AllowSetForegroundWindow(GetCurrentProcessId());

	if (EQhWnd)
	{
		SetForegroundWindowInternal(EQhWnd);
	}
	else
	{
		if (EQW_GetDisplayWindow)
			EQhWnd = EQW_GetDisplayWindow();
		else
			EQhWnd = *(HWND*)EQADDR_HWND;

		SetForegroundWindowInternal(EQhWnd);
	}
}

// ***************************************************************************
// Function:    RemoveLevCmd
// Description: '/removelev' command
// Purpose:     Adds the ability to remove the levitate effect.
// Usage:       /removelev
// Author:      ChatWithThisName
// ***************************************************************************

static bool HasLevSPA(SPELL* pBuff)
{
	int effects = GetSpellNumEffects(pBuff);

	for (int i = 0; i < effects; ++i)
	{
		if (GetSpellAttrib(pBuff, i) == SPA_LEVITATION)
			return true;
	}

	return false;
}

void RemoveLevCmd(SPAWNINFO* pChar, char* szLine)
{
	PcProfile* pcProfile = GetPcProfile();
	if (!pcProfile)
		return;

	// Check long buffs
	for (int i = 0; i < NUM_LONG_BUFFS; ++i)
	{
		if (SPELL* pBuff = GetSpellByID(pcProfile->Buff[i].SpellID))
		{
			if (HasLevSPA(pBuff))
			{
				pPCData->RemoveBuffEffect(i, pLocalPlayer->SpawnID);

				WriteChatf("\arRemoving: \ap%s", pBuff->Name);
			}
		}
	}

	// Check short buffs
	for (int i = 0; i < NUM_SHORT_BUFFS; ++i)
	{
		if (SPELL* pBuff = GetSpellByID(pcProfile->ShortBuff[i].SpellID))
		{
			if (HasLevSPA(pBuff))
			{
				pPCData->RemoveBuffEffect(i + NUM_LONG_BUFFS, pLocalPlayer->SpawnID);
				WriteChatf("\arRemoving: \ap%s", pBuff->Name);
			}
		}
	}
}

} // namespace mq
