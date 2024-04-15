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

#include <yaml-cpp/yaml.h>

constexpr float INVALID_FLOOR = static_cast<float>(-1.0e27);
constexpr int MAX_CLICK_STRINGS = 16;
constexpr const char* const OPEN_MENU_TOKEN = "{contextmenu}";
constexpr const char* const TARGET_PATH_TOKEN = "{targetpath}";

static uint32_t ParseCombo(const char* Combo);
static char* DescribeCombo(uint32_t Combo, char* outBuffer, size_t length);

enum BindingType
{
	BindingType_None = 0,
	BindingType_Spawn = 1,
	BindingType_GroundItem = 2,
};

struct ClickBinding
{
	using Key = std::tuple<int, uint32_t, BindingType>;
	Key binding;
	std::string command;

	ClickBinding(int mouseButton, uint32_t flags, BindingType type, const std::string& command)
		: binding(mouseButton, flags, type), command(command) {}

	bool matches(int mouseButton_, uint32_t flags_, BindingType type_) const
	{
		return mouseButton_ == mouseButton() && flags_ == flags() && type_ == type();
	}

	int mouseButton() const
	{
		return std::get<0>(binding);
	}

	uint32_t flags() const
	{
		return std::get<1>(binding);
	}

	BindingType type() const
	{
		return std::get<2>(binding);
	}
};

using MapBindingsTable = std::unordered_map<ClickBinding::Key, ClickBinding>;
static MapBindingsTable s_bindings;

const ClickBinding* MapGetClickBinding(int mouseButton, uint32_t flags, BindingType type)
{
	// Mask flags to just the shift/ctrl/alt flags
	flags &= 0x0f;

	// We treat both alt keys as the same.
	if ((flags & KeyboardFlags_Alt) != 0)
		flags |= KeyboardFlags_Alt;

	ClickBinding::Key key = { mouseButton, flags, type };

	// Do a search for matching criteria
	auto iter = s_bindings.find(key);
	if (iter != s_bindings.end())
	{
		return &iter->second;
	}

	// If searching for object-specific binding, and none was found, try searching
	// for a non-object-specific binding.
	if (type != BindingType_None)
	{
		ClickBinding::Key key2 = { mouseButton, flags, BindingType_None };

		auto iter2 = s_bindings.find(key2);
		if (iter2 != s_bindings.end())
		{
			return &iter2->second;
		}
	}

	// nothing was found.
	return nullptr;
}

static bool MapAddClickBinding(MapBindingsTable& table, int mouseButton, uint32_t flags, BindingType type, const std::string& command)
{
	auto [_, inserted] = table.emplace(
		std::piecewise_construct,
		std::forward_as_tuple(mouseButton, flags, type),
		std::forward_as_tuple(mouseButton, flags, type, command)
	);
	return inserted;
}

MapBindingsTable MapLoadDefaultClickBindings()
{
	MapBindingsTable table;

	// Default right click bindings
	MapAddClickBinding(table, 1, 0,                                      BindingType_Spawn,      "/mqtarget id %i");
	MapAddClickBinding(table, 1, 0,                                      BindingType_GroundItem, "/itemtarget id %i");
	MapAddClickBinding(table, 1, 0,                                      BindingType_None,       OPEN_MENU_TOKEN);

	// Ctrl+RightClick to hide
	MapAddClickBinding(table, 1, KeyboardFlags_Ctrl,                     BindingType_Spawn,      "/maphide id %i");
	// Alt+RightClick to highlight
	MapAddClickBinding(table, 1, KeyboardFlags_Alt,                      BindingType_Spawn,      "/highlight id %i");

	// Ctrl+Shift+LeftClick to navigate anywhere on the map
	MapAddClickBinding(table, 0, KeyboardFlags_Ctrl | KeyboardFlags_Alt, BindingType_None,       "/nav locxy %x %y");

	return table;
}

static MapBindingsTable MapImportLegacyClickBindings()
{
	// Import click bindings from .ini file

	char szBuffer[MAX_STRING];
	MapBindingsTable table;

	const char* buttonNames[] = {
		"Left Click",
		"Right Click"
	};

	for (int button = 0; button < (int)lengthof(buttonNames); ++button)
	{
		for (int i = 0; i < MAX_CLICK_STRINGS; i++)
		{
			std::string binding = GetPrivateProfileString(buttonNames[button], fmt::format("KeyCombo{}", i), std::string(), INIFileName);

			if (!binding.empty())
			{
				uint32_t flags = i;

				// We treat both alt keys as the same.
				if ((flags & KeyboardFlags_Alt) != 0)
					flags |= KeyboardFlags_Alt;

				// Legacy bindings always treated right click as spawn and left click as none

				MapAddClickBinding(table, button, flags, button == 0 ? BindingType_None : BindingType_Spawn, binding);
			}
		}
	}

	return table;
}

static MapBindingsTable MapLoadSavedClickBindings()
{
	MapBindingsTable table;

	return table;
}

static void MapStoreSavedClickBindings()
{
	
}

static bool MapSelectTarget()
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
		if (Flags && MapRightClickString[Flags][0])
		{
			// This just processes the format string in MapSpecialClickString
			CXStr cmd = pMapSpawn->FormatString(MapRightClickString[Flags]);
			EzCommand(cmd.c_str());
		}
		else
		{
			pTarget = pSpawn;
		}
	}

	return IsOptionEnabled(MapFilter::TargetPath);
}

static void MapClickLocation(float world_point_y, float world_point_x, const std::vector<float>& z_hits)
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

static bool HandleLeftClick(MapViewLabel* pMapLabel, const CXPoint& point, uint32_t flags)
{
	CVector3 points = { (float)point.x, (float)point.y, 0.f };
	pMapViewWnd->MapView.GetWorldCoordinates(points); // this writes the world X & Y coords into points

	std::vector<float> z_hits;

	float curr_z = 0.0f;
	for (float f = pZoneInfo->Ceiling; f > pZoneInfo->Floor; f -= 2.0f)
	{
		curr_z = pDisplay->GetFloorHeight(points.X, points.Y, f);
		if (curr_z != INVALID_FLOOR)
		{
			break;
		}
	}

	do
	{
		z_hits.push_back(curr_z);
		curr_z = pDisplay->GetFloorHeight(points.X, points.Y, curr_z - 2.f);
	} while (curr_z >= pZoneInfo->Floor - 1.f);

	MapClickLocation(points.X, points.Y, z_hits);

	return true;
}

static bool HandleRightClick(MapViewLabel* pMapLabel, const CXPoint& point, uint32_t flags)
{
	bool handleClick = false;

	if (pMapLabel)
	{
		handleClick = MapSelectTarget();
	}
	else
	{
		handleClick = IsOptionEnabled(MapFilter::ContextMenu);
	}

	return handleClick;
}

bool MapHandleMouseClick(MapViewLabel* pMapLabel, const CXPoint& point,
	int mouseButton, uint32_t flags)
{
	WriteChatf("MapHandleMouseClick: %p %d,%d %d, %x", pMapLabel, point.x, point.y,
		mouseButton, flags);

	if (mouseButton == 0)
		return HandleLeftClick(pMapLabel, point, flags);

	if (mouseButton == 1)
		return HandleRightClick(pMapLabel, point, flags);

	return true;
}

static char* DescribeCombo(uint32_t Combo, char* outBuffer, size_t length)
{
	strcpy_s(outBuffer, length, "");
	bool first = true;

	if (Combo & KeyboardFlags_Shift)
	{
		strcpy_s(outBuffer, length, "shift");
		first = false;
	}

	if (Combo & KeyboardFlags_Ctrl)
	{
		if (!first)
		{
			strcat_s(outBuffer, length, "+");
		}

		strcpy_s(outBuffer, length, "ctrl");
		first = false;
	}

	if (Combo & KeyboardFlags_Alt)
	{
		if (!first)
		{
			strcat_s(outBuffer, length, "+");
		}

		strcpy_s(outBuffer, length, "alt");
		first = false;
	}

	if (first)
	{
		strcpy_s(outBuffer, length, "Invalid");
	}

	return outBuffer;
}

static uint32_t ParseCombo(const char* Combo)
{
	uint32_t Ret = 0;
	if (!Combo || !Combo[0])
		return 0;

	char Copy[MAX_STRING];
	strcpy_s(Copy, Combo);
	char* Next_Token1 = nullptr;
	Combo = strtok_s(Copy, "+", &Next_Token1);
	while (Combo)
	{
		if (!_stricmp(Combo, "ctrl"))
			Ret |= KeyboardFlags_Ctrl;
		else if (!_stricmp(Combo, "shift"))
			Ret |= KeyboardFlags_Shift;
		else if (!_stricmp(Combo, "lalt") || !_stricmp(Combo, "ralt") || !_stricmp(Combo, "alt"))
			Ret |= KeyboardFlags_Alt;
		Combo = strtok_s(nullptr, "+", &Next_Token1);
	}

	return Ret;
}

void MapClickCommand(PlayerClient* pChar, const char* szLine)
{
	bRunNextCommand = true;

	if (!szLine[0])
	{
		SyntaxError("Usage: /mapclick [left] <list|<key[+key[...]]> <clear|command>>");
		return;
	}

	auto f = [](char szArg[MAX_STRING], const char* szRest, char(&command_array)[16][MAX_STRING], const char* szSection)
		{
			char szBuffer[MAX_STRING] = { 0 };

			if (!_stricmp(szArg, "list"))
			{
				int Count = 0;
				for (int i = 1; i < 16; i++)
				{
					if (command_array[i][0])
					{
						WriteChatf("%s: %s", DescribeCombo(i, szBuffer, lengthof(szBuffer)), command_array[i]);
						Count++;
					}
				}

				WriteChatf("%d special %s command%s", Count, szSection, Count == 1 ? "" : "s");
				return;
			}

			uint32_t Combo = ParseCombo(szArg);
			if (!Combo)
			{
				WriteChatf("Invalid combo '%s'", szArg);
				return;
			}

			if (!szRest[0])
			{
				WriteChatf("%s: %s", DescribeCombo(Combo, szBuffer, lengthof(szBuffer)), command_array[Combo]);
				return;
			}

			if (!_stricmp(szRest, "clear"))
			{
				command_array[Combo][0] = 0;
				WritePrivateProfileString(szSection, fmt::format("KeyCombo{:d}", Combo), command_array[Combo], INIFileName);

				WriteChatf("%s -- %s cleared", szSection, DescribeCombo(Combo, szBuffer, lengthof(szBuffer)));
				return;
			}

			strcpy_s(command_array[Combo], szRest);
			WritePrivateProfileString(szSection, fmt::format("KeyCombo{:d}", Combo), command_array[Combo], INIFileName);

			WriteChatf("%s -- %s: %s", szSection, DescribeCombo(Combo, szBuffer, lengthof(szBuffer)), command_array[Combo]);
		};

	char szArg[MAX_STRING] = { 0 };
	GetArg(szArg, szLine, 1);
	const char* szRest = GetNextArg(szLine);

	if (!_stricmp(szArg, "left"))
	{
		GetArg(szArg, szRest, 1);
		szRest = GetNextArg(szRest);
		f(szArg, szRest, MapLeftClickString, "Left Click");
	}
	else
	{
		f(szArg, szRest, MapRightClickString, "Right Click");
	}
}
