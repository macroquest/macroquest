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

#include <mq/Plugin.h>
#include "MQ2Map.h"

#include <sstream>
#include <algorithm>
#include <iomanip>
#include <tuple>

#include <fmt/format.h>

// ***************************************************************************
// Function:    MapFilters
// Description: Our '/mapfilter' command
//              Sets map filters
// Usage:       /mapfilter [options|help]
// ***************************************************************************
void MapFilterSetting(SPAWNINFO* pChar, DWORD nMapFilter, char* szValue)
{
	if (!pChar) return;

	char Buff[MAX_STRING] = { 0 };
	DWORD dwValue = 0;

	char* szFilterMap[] =
	{
		"hide",
		"show",
		nullptr
	};

	MAPFILTER* pMapFilter = &MapFilterOptions[nMapFilter];
	if (!RequirementsMet(nMapFilter))
	{
		WriteChatf("'%s' requires '%s' option.  Please enable this option first.", pMapFilter->szName, MapFilterOptions[pMapFilter->RequiresOption].szName);
		return;
	}

	if (!szValue)
	{
		char szBuffer[MAX_STRING] = { 0 };

		if (pMapFilter->bIsToggle)
		{
			sprintf_s(szBuffer, "%s: %s", pMapFilter->szName, szFilterMap[pMapFilter->Enabled]);
		}
		else if (nMapFilter == MAPFILTER_Custom)
		{
			if (IsOptionEnabled(nMapFilter) == 0)
			{
				sprintf_s(szBuffer, "%s: Off", pMapFilter->szName);
			}
			else
			{
				sprintf_s(szBuffer, "%s: %s", pMapFilter->szName, FormatSearchSpawn(Buff, sizeof(Buff), &MapFilterCustom));
			}
		}
		else
		{
			sprintf_s(szBuffer, "%s: %d", pMapFilter->szName, pMapFilter->Enabled);
		}

		if (pMapFilter->DefaultColor != -1)
		{
			DWORD R = (pMapFilter->Color & 0xFF0000) / 0x10000;
			DWORD G = (pMapFilter->Color & 0xFF00) / 0x100;
			DWORD B = pMapFilter->Color & 0xFF;
			WriteChatf("%s (Color: %d %d %d)", szBuffer, R, G, B);
		}
		else
		{
			WriteChatf("%s", szBuffer);
		}
	}
	else
	{
		if (pMapFilter->bIsToggle)
		{
			if (!_stricmp(szFilterMap[0], szValue))
			{
				pMapFilter->Enabled = 0;
			}
			else if (!_stricmp(szFilterMap[1], szValue))
			{
				pMapFilter->Enabled = 1;
			}
			else
			{
				pMapFilter->Enabled = 1 - pMapFilter->Enabled;
			}
			WriteChatf("%s is now set to: %s", pMapFilter->szName, szFilterMap[IsOptionEnabled(nMapFilter)]);
		}
		else if (nMapFilter == MAPFILTER_Custom)
		{
			ClearSearchSpawn(&MapFilterCustom);
			if (szValue[0] == 0)
			{
				pMapFilter->Enabled = 0;
				WriteChatf("%s is now set to: Off", pMapFilter->szName);
			}
			else
			{
				pMapFilter->Enabled = 1;
				ParseSearchSpawn(szValue, &MapFilterCustom);

				WriteChatf("%s is now set to: %s", pMapFilter->szName, FormatSearchSpawn(Buff, sizeof(Buff), &MapFilterCustom));
			}
		}
		else if (nMapFilter == MAPFILTER_Marker)
		{
			char szBuffer2[MAX_STRING] = { 0 };
			GetArg(szBuffer2, szValue, 1);

			if (!_stricmp(szFilterMap[0], szValue))
			{
				pMapFilter->Enabled = 0;
				WriteChatf("%s is now set to: %s", pMapFilter->szName, szFilterMap[IsOptionEnabled(nMapFilter)]);
			}
			else if (!_stricmp(szFilterMap[1], szValue))
			{
				pMapFilter->Enabled = 1;
				WriteChatf("%s is now set to: %s", pMapFilter->szName, szFilterMap[IsOptionEnabled(nMapFilter)]);
			}
			else
			{
				pMapFilter->Enabled = 1;
				WriteChatf("%s %s", pMapFilter->szName, FormatMarker(szValue, Buff, sizeof(Buff)));
			}
		}
		else
		{
			pMapFilter->Enabled = GetIntFromString(szValue, 0);

			if (pMapFilter->Enabled && !_stricmp(pMapFilter->szName, "CampRadius"))
			{
				CampX = pChar->X;
				CampY = pChar->Y;
			}

			if (pMapFilter->Enabled && !_stricmp(pMapFilter->szName , "PullRadius"))
			{
				PullX = pChar->X;
				PullY = pChar->Y;
			}

			WriteChatf("%s is now set to: %d", pMapFilter->szName, pMapFilter->Enabled);
		}
	}

	if (szValue)
	{
		WritePrivateProfileBool("Map Filters", pMapFilter->szName, pMapFilter->Enabled, INIFileName);
	}
}

void MapFilters(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;

	char szArg[MAX_STRING] = { 0 };
	GetArg(szArg, szLine, 1);
	char* szRest = GetNextArg(szLine);

	if (szArg[0] == 0) // Display Settings
	{
		WriteChatColor("Map filtering settings:");
		WriteChatColor("-----------------------");

		for (DWORD i = 0; MapFilterOptions[i].szName != nullptr; i++)
		{
			if (RequirementsMet(i))
				MapFilterSetting(pChar, i);
		}
	}
	else if (!_strnicmp(szArg, "help", 4)) // Display Help
	{
		WriteChatColor("Map filtering options:");

		for (DWORD i = 0; MapFilterOptions[i].szName != nullptr; i++)
		{
			WriteChatf("%s%s: %s", MapFilterOptions[i].szName, (MapFilterOptions[i].bIsToggle) ? "" : " #", MapFilterOptions[i].szHelpString);
		}

		WriteChatColor("'option' color [r g b]: Set display color for 'option' (Omit to reset to default)");
	}
	else // Set Option
	{
		MAPFILTER* Found = nullptr;
		for (DWORD i = 0; MapFilterOptions[i].szName != nullptr; i++)
		{
			if (!_stricmp(szArg, MapFilterOptions[i].szName))
			{
				if (!_strnicmp(szRest, "color", 5))
				{
					if (MapFilterOptions[i].DefaultColor == -1)
					{
						WriteChatf("Option '%s' does not have a color.", MapFilterOptions[i].szName);
					}
					else
					{
						DWORD R, G, B;
						char szBuffer2[MAX_STRING] = { 0 };
						GetArg(szArg, szRest, 2);

						if (szArg[0] == 0)
						{
							MapFilterOptions[i].Color = MapFilterOptions[i].DefaultColor;
						}
						else
						{
							R = GetIntFromString(szArg, 256);
							G = GetIntFromString(GetArg(szArg, szRest, 3), 256);
							B = GetIntFromString(GetArg(szArg, szRest, 4), 256);
							if (R > 255) R = 255;
							if (G > 255) G = 255;
							if (B > 255) B = 255;
							MapFilterOptions[i].Color = R * 0x10000 + G * 0x100 + B;
						}

						WriteChatf("Option '%s' color set to: %d %d %d", MapFilterOptions[i].szName, R, G, B);

						WritePrivateProfileInt("Map Filters",
							fmt::format("{}-Color", MapFilterOptions[i].szName),
							MapFilterOptions[i].Color & 0xFFFFFF, INIFileName);

						MapFilterOptions[i].Color |= 0xFF000000;
					}
				}
				else
				{
					MapFilterSetting(pChar, i, szRest);
				}

				Found = &MapFilterOptions[i];
			}
		}

		if (!Found)
		{
			SyntaxError("Usage: /mapfilter [option|help]");
		}
		else if (Found->RegenerateOnChange)
		{
			MapClear();
			MapGenerate();
		}
	}
}

void MapActiveLayerCmd(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;
	const int newActiveLayer = GetIntFromString(szLine, -1);
	if (szLine == nullptr || szLine[0] == 0 || newActiveLayer < 0 || newActiveLayer > 3)
	{
		SyntaxError("Usage: /mapactivelayer [0|1|2|3]");
		return;
	}

	activeLayer = newActiveLayer;

	WriteChatf("Map Active Layer: %d", activeLayer);

	// Write setting to file
	WritePrivateProfileInt("Map Filters", "ActiveLayer", activeLayer, INIFileName);

	// refresh map
	MapClear();
	MapGenerate();
}

void MapSetLocationCmd(SPAWNINFO* pChar, char* szLine)
{
	std::string input = szLine;
	input.erase(std::remove(input.begin(), input.end(), ','), input.end());

	char tag[64] = { 0 };
	char size[32] = { 0 };
	char width[32] = { 0 };
	char red[32] = { 0 };
	char green[32] = { 0 };
	char blue[32] = { 0 };
	char radius[32] = { 0 };
	char label[64] = { 0 };
	char radius_red[32] = { 0 };
	char radius_green[32] = { 0 };
	char radius_blue[32] = { 0 };
	char yloc[32] = { "not set" };
	char xloc[32] = { "not set" };
	char zloc[32] = { "0" };
	bool isDefaultLocSettings = true;
	bool isFirstLoop = true;

	if (szLine == nullptr || szLine[0] == 0)
	{
		MapLocSyntaxOutput();
		return;
	}

	std::stringstream ss(input);
	char arg[512];

	// Read arguments into vars
	while (ss && !ss.eof())
	{
		ss >> arg;

		if (isFirstLoop && !_stricmp(arg, "remove"))
		{
			MapRemoveLocation(pChar, szLine);
			return;
		}

		isFirstLoop = false;

		if (!_stricmp(arg, "size"))
		{
			if (ss && !ss.eof())
			{
				ss >> size;
				isDefaultLocSettings = false;
			}
			else
			{
				MapLocSyntaxOutput();
				return;
			}

			if (GetIntFromString(size, 9) < 10 || GetIntFromString(width, 201) > 200)
			{
				MapLocSyntaxOutput();
				return;
			}
		}
		else if (!_stricmp(arg, "width"))
		{
			if (ss && !ss.eof())
			{
				ss >> width;
				isDefaultLocSettings = false;
			}
			else
			{
				MapLocSyntaxOutput();
				return;
			}

			if (GetIntFromString(width, 0) < 1 || GetIntFromString(width, 11) > 10)
			{
				MapLocSyntaxOutput();
				return;
			}
		}
		else if (!_stricmp(arg, "color"))
		{
			if (ss && !ss.eof())
			{
				ss >> red;
				isDefaultLocSettings = false;
			}
			else
			{
				MapLocSyntaxOutput();
				return;
			}
			if (ss && !ss.eof())
			{
				ss >> green;
			}
			else
			{
				MapLocSyntaxOutput();
				return;
			}
			if (ss && !ss.eof())
			{
				ss >> blue;
			}
			else
			{
				MapLocSyntaxOutput();
				return;
			}

			if (GetIntFromString(red, -1) < 0 || GetIntFromString(red, 256) > 255 || GetIntFromString(green, -1) < 0 || GetIntFromString(green, 256) > 255 || GetIntFromString(blue, -1) < 0 || GetIntFromString(blue, 256) > 255)
			{
				MapLocSyntaxOutput();
				return;
			}
		}
		else if (!_stricmp(arg, "radius"))
		{
			if (ss && !ss.eof())
			{
				ss >> radius;
				isDefaultLocSettings = false;
			}
			else
			{
				MapLocSyntaxOutput();
				return;
			}
		}
		else if (!_stricmp(arg, "rcolor"))
		{
			if (ss && !ss.eof())
			{
				ss >> radius_red;
				isDefaultLocSettings = false;
			}
			else
			{
				MapLocSyntaxOutput();
				return;
			}
			if (ss && !ss.eof())
			{
				ss >> radius_green;
			}
			else
			{
				MapLocSyntaxOutput();
				return;
			}
			if (ss && !ss.eof())
			{
				ss >> radius_blue;
			}
			else
			{
				MapLocSyntaxOutput();
				return;
			}

			if (GetIntFromString(radius_red, -1) < 0 || GetIntFromString(radius_red, 256) > 255 || GetIntFromString(radius_green, -1) < 0 || GetIntFromString(radius_green, 256) > 255 || GetIntFromString(radius_blue, -1) < 0 || GetIntFromString(radius_blue, 256) > 255)
			{
				MapLocSyntaxOutput();
				return;
			}
		}
		else if (!_stricmp(arg, "target"))
		{
			if (!pTarget)
			{
				WriteChatColor("You have no target", CONCOLOR_RED);
				return;
			}

			auto targetLoc = GetTargetLoc();

			std::stringstream sslocx;
			sslocx << std::fixed << std::setprecision(0) << targetLoc.X;
			sslocx >> xloc;

			std::stringstream sslocy;
			sslocy << std::fixed << std::setprecision(0) << targetLoc.Y;
			sslocy >> yloc;

			std::stringstream sslocz;
			sslocz << std::fixed << std::setprecision(0) << targetLoc.Z;
			sslocz >> zloc;

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
		}
		else if (!_stricmp(arg, "label"))
		{
			std::string labelTemp;
			std::getline(ss, labelTemp);
			sprintf_s(label, "%s", labelTemp.c_str());
		}
		else // assuming yloc xloc <zloc>
		{
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
			}
			else
			{
				MapLocSyntaxOutput();
				return;
			}

			if (ss && !ss.eof())
			{
				ss >> arg;

				if (IsFloat(arg))
				{
					strcpy_s(zloc, arg);
				}
				else
				{
					// zloc was optional, maybe this is another command. Put back in ss
					std::stringstream temp;
					temp << arg;
					temp << ss.rdbuf();
					ss = std::move(temp);
				}
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

			sprintf_s(tag, "%s,%s,%s", yloc, xloc, zloc);
		}
	}

	// Get or create MAPLOC entry in LocationMap
	MAPLOC* loc;
	if (LocationMap.count(tag) > 0)
	{
		loc = LocationMap[tag];
	}
	else
	{
		loc = new MAPLOC{};
		loc->tag = tag;
		loc->lineSize = DefaultMapLoc->lineSize;
		loc->width = DefaultMapLoc->width;
		loc->r_color = DefaultMapLoc->r_color;
		loc->g_color = DefaultMapLoc->g_color;
		loc->b_color = DefaultMapLoc->b_color;
		loc->radius = DefaultMapLoc->radius;
		loc->rr_color = DefaultMapLoc->rr_color;
		loc->rg_color = DefaultMapLoc->rg_color;
		loc->rb_color = DefaultMapLoc->rb_color;
	}

	std::stringstream MapLocVars;
	MapLocVars << "MapLoc: ";

	if (size[0] != 0)
	{
		loc->lineSize = GetIntFromString(size, DefaultMapLoc->lineSize);
	}
	if (width[0] != 0)
	{
		loc->width = GetIntFromString(width, DefaultMapLoc->width);
	}
	if (red[0] != 0)
	{
		loc->r_color = GetIntFromString(red, DefaultMapLoc->r_color);
		loc->g_color = GetIntFromString(green, DefaultMapLoc->g_color);
		loc->b_color = GetIntFromString(blue, DefaultMapLoc->b_color);
	}
	if (radius[0] != 0)
	{
		loc->radius = GetIntFromString(radius, DefaultMapLoc->radius);
	}
	if (radius_red[0] != 0)
	{
		loc->rr_color = GetIntFromString(radius_red, DefaultMapLoc->rr_color);
		loc->rg_color = GetIntFromString(radius_green, DefaultMapLoc->rg_color);
		loc->rb_color = GetIntFromString(radius_blue, DefaultMapLoc->rb_color);
	}

	// Are we placing a new MapLoc?
	if (strcmp(yloc, "not set") != 0)
	{
		loc->yloc = static_cast<int>(std::stof(yloc));
		loc->xloc = static_cast<int>(std::stof(xloc));
		loc->zloc = static_cast<int>(std::stof(zloc));
		loc->isCreatedFromDefaultLoc = isDefaultLocSettings;
		MapLocVars << "y:" << loc->yloc << " x:" << loc->xloc << " z:" << loc->zloc;

		if (label[0] != 0)
		{
			loc->label = label;
			MapLocVars << ", Label: " << label;
		}

		LocationMap[tag] = loc;
		AddMapLocToList(loc);
		UpdateMapLocIndexes();
		UpdateMapLoc(loc);
	}
	else
	{
		MapLocVars << "DefaultLoc";

		// If we aren't placing a loc, then the values are updates to the default. Persist them.
		WritePrivateProfileInt("MapLoc", "Size", loc->lineSize, INIFileName);
		WritePrivateProfileInt("MapLoc", "Width", loc->width, INIFileName);
		WritePrivateProfileInt("MapLoc", "Red", loc->r_color, INIFileName);
		WritePrivateProfileInt("MapLoc", "Green", loc->g_color, INIFileName);
		WritePrivateProfileInt("MapLoc", "Blue", loc->b_color, INIFileName);
		WritePrivateProfileInt("MapLoc", "Radius", loc->radius, INIFileName);
		WritePrivateProfileInt("MapLoc", "RadiusGreen", loc->rg_color, INIFileName);
		WritePrivateProfileInt("MapLoc", "RadiusRed", loc->rr_color, INIFileName);
		WritePrivateProfileInt("MapLoc", "RadiusBlue", loc->rb_color, INIFileName);
		UpdateDefaultMapLoc();
	}

	if (!isDefaultLocSettings)
	{
		MapLocVars << ", Width:" << loc->width
			<< ", Size:" << loc->lineSize
			<< ", Color:" << loc->r_color << "," << loc->g_color << "," << loc->b_color
			<< ", Radius:" << loc->radius
			<< ", Radius Color:" << loc->rr_color << "," << loc->rg_color << "," << loc->rb_color;
	}

	WriteChatf("%s", MapLocVars.str().c_str());
}

void MapHighlightCmd(SPAWNINFO* pChar, char* szLine)
{
	char szArg[MAX_STRING] = { 0 };
	char red[64] = { 0 };
	char green[64] = { 0 };
	char blue[64] = { 0 };
	std::stringstream ss(szLine);

	if (szLine[0] == 0)
	{
		SyntaxError("Usage: /highlight [reset|spawnfilter|size|pulse|[color # # #]]");
		return;
	}

	ss >> szArg;

	if (!_stricmp(szArg, "color"))
	{
		char usage[MAX_STRING] = { "Usage: /highlight color [0-255] [0-255] [0-255]" };

		if (ss && !ss.eof())
		{
			ss >> red;
		}
		else
		{
			SyntaxError(usage);
			return;
		}

		if (ss && !ss.eof())
		{
			ss >> green;
		}
		else
		{
			SyntaxError(usage);
			return;
		}

		if (ss && !ss.eof())
		{
			ss >> blue;
		}
		else
		{
			SyntaxError(usage);
			return;
		}

		if (GetIntFromString(red, -1) < 0 || GetIntFromString(red, 256) > 255 || GetIntFromString(green, -1) < 0 || GetIntFromString(green, 256) > 255 || GetIntFromString(blue, -1) < 0 || GetIntFromString(blue, 256) > 255)
		{
			SyntaxError(usage);
			return;
		}

		unsigned char R = GetIntFromString(red, 255);
		unsigned char G = GetIntFromString(green, 255);
		unsigned char B = GetIntFromString(blue, 255);
		HighlightColor = 0xFF000000 | (R << 16) | (G << 8) | (B);

		WriteChatf("Highlight color: %d %d %d", R, G, B);
		return;
	}
	else if (!_stricmp(szArg, "reset"))
	{
		MapHighlight(nullptr);
		WriteChatColor("Highlighting reset");
		return;
	}
	else if (!_stricmp(szArg, "size"))
	{
		if (ss && !ss.eof())
		{
			ss >> szArg;
		}
		else
		{
			SyntaxError("Usage: /highlight size #");
			return;
		}

		if (GetIntFromString(szArg, -1) == -1)
		{
			SyntaxError("Usage: /highlight size #");
			return;
		}

		HighlightSIDELEN = GetIntFromString(szArg, HighlightSIDELEN);
		PulseReset();

		WriteChatf("Highlight size: \ag%d", HighlightSIDELEN);

		// Write setting to file
		WritePrivateProfileInt("Map Filters", "HighSize", HighlightSIDELEN, INIFileName);
		return;
	}
	else if (!_stricmp(szArg, "pulse"))
	{
		HighlightPulse = !HighlightPulse;
		PulseReset();

		WriteChatf("Highlight pulse: %s", HighlightPulse ? "\agON" : "\arOFF");

		// Write setting to file
		WritePrivateProfileBool("Map Filters", "HighPulse", HighlightPulse, INIFileName);
		return;
	}

	if (CHARINFO* pCharInfo = GetCharInfo())
	{
		MQSpawnSearch ssHighlight;
		ClearSearchSpawn(&ssHighlight);
		ParseSearchSpawn(szLine, &ssHighlight);

		WriteChatf("%d mapped spawns highlighted", MapHighlight(&ssHighlight));
	}
}

void PulseReset()
{
	HighlightPulseIncreasing = true;
	HighlightPulseIndex = 0;
	HighlightPulseDiff = HighlightSIDELEN / 10;
}

void MapHideCmd(SPAWNINFO* pChar, char* szLine)
{
	char szArg[MAX_STRING] = { 0 };
	bRunNextCommand = true;

	if (szLine == nullptr || szLine[0] == 0)
	{
		SyntaxError("Usage: /maphide [spawnfilter|reset|repeat]");
		return;
	};

	GetArg(szArg, szLine, 1);
	if (!_stricmp(szArg, "reset"))
	{
		MapClear();
		MapGenerate();
		WriteChatColor("Map spawns regenerated", USERCOLOR_DEFAULT);
		return;
	}

	if (!_stricmp(szArg, "repeat"))
	{
		repeatMaphide = !repeatMaphide;

		WritePrivateProfileInt("Map Filters", "Maphide-Repeat", repeatMaphide, INIFileName);

		WriteChatf("maphide repeat set to: %s", (repeatMaphide ? "\agon" : "\aroff"));
		return;
	}

	if (CHARINFO* pCharInfo = GetCharInfo())
	{
		MQSpawnSearch ssHide;
		ClearSearchSpawn(&ssHide);
		ParseSearchSpawn(szLine, &ssHide);

		WriteChatf("%d mapped spawns hidden", MapHide(ssHide));
	}
}

void MapShowCmd(SPAWNINFO* pChar, char* szLine)
{
	char szArg[MAX_STRING] = { 0 };
	char szBuffer[MAX_STRING] = { 0 };
	bRunNextCommand = true;

	if (szLine == nullptr || szLine[0] == 0)
	{
		SyntaxError("Usage: /mapshow [spawnfilter|reset|repeat]");
		return;
	};

	GetArg(szArg, szLine, 1);
	if (!_stricmp(szArg, "reset"))
	{
		MapClear();
		MapGenerate();

		WriteChatColor("Map spawns regenerated");
		return;
	}

	if (!_stricmp(szArg, "repeat"))
	{
		repeatMapshow = !repeatMapshow;

		WritePrivateProfileBool("Map Filters", "Mapshow-Repeat", repeatMapshow, INIFileName);

		WriteChatf("mapshow repeat set to: %s", (repeatMapshow ? "\agon" : "\aroff"));
		return;
	}

	if (CHARINFO* pCharInfo = GetCharInfo())
	{
		MQSpawnSearch ssShow;
		ClearSearchSpawn(&ssShow);
		ParseSearchSpawn(szLine, &ssShow);

		WriteChatf("%d previously hidden spawns shown", MapShow(ssShow));
	}
}

void MapNames(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;

	if (!szLine[0])
	{
		WriteChatf("Normal naming string: %s", MapNameString);
		WriteChatf("Target naming string: %s", MapTargetNameString);
		return;
	}

	char szArg[MAX_STRING] = { 0 };
	GetArg(szArg, szLine, 1);
	char* szRest = GetNextArg(szLine);

	if (!_stricmp(szArg, "target"))
	{
		if (!_stricmp(szRest, "reset"))
			strcpy_s(MapTargetNameString, "%N");
		else
			strcpy_s(MapTargetNameString, szRest);

		WriteChatf("Target naming string: %s", MapTargetNameString);

		WritePrivateProfileString("Naming Schemes", "Target", MapTargetNameString, INIFileName);
		MapClear();
		MapGenerate();
	}
	else if (!_stricmp(szArg, "normal"))
	{
		if (!_stricmp(szRest, "reset"))
			strcpy_s(MapNameString, "%N");
		else
			strcpy_s(MapNameString, szRest);

		WriteChatf("Normal naming string: %s", MapNameString);

		WritePrivateProfileString("Naming Schemes", "Normal", MapNameString, INIFileName);
		MapClear();
		MapGenerate();
	}
	else
	{
		SyntaxError("Usage: /mapnames <target|normal> [value|reset]");
	}
}

char* DescribeCombo(DWORD Combo)
{
	static char Description[256];
	Description[0] = 0;
	int pos = 0;
	if (Combo & XKF_SHIFT)
	{
		strcpy_s(&Description[pos], 256 - pos, "shift");
		pos += 5;
	}
	if (Combo & XKF_CTRL)
	{
		if (pos)
		{
			Description[pos] = '+';
			pos++;
		}

		strcpy_s(&Description[pos], 256 - pos, "ctrl");
		pos += 4;
	}

	if (Combo & XKF_LALT)
	{
		if (pos)
		{
			Description[pos] = '+';
			pos++;
		}

		strcpy_s(&Description[pos], sizeof(Description) - pos, "lalt");
		pos += 4;
	}

	if (Combo & XKF_RALT)
	{
		if (pos)
		{
			Description[pos] = '+';
			pos++;
		}

		strcpy_s(&Description[pos], sizeof(Description) - pos, "ralt");
	}

	if (!Description[0])
	{
		return "Invalid";
	}

	return &Description[0];
}

DWORD ParseCombo(char* Combo)
{
	DWORD Ret = 0;
	if (!Combo || !Combo[0])
		return 0;
	char Copy[MAX_STRING];
	strcpy_s(Copy, Combo);
	char* Next_Token1 = nullptr;
	Combo = strtok_s(Copy, "+", &Next_Token1);
	while (Combo)
	{
		if (!_stricmp(Combo, "ctrl"))
			Ret += XKF_CTRL;
		else if (!_stricmp(Combo, "shift"))
			Ret += XKF_SHIFT;
		else if (!_stricmp(Combo, "lalt"))
			Ret += XKF_LALT;
		else if (!_stricmp(Combo, "ralt"))
			Ret += XKF_RALT;
		else if (!_stricmp(Combo, "alt"))
			Ret += XKF_LALT;
		Combo = strtok_s(nullptr, "+", &Next_Token1);
	}
	return Ret;
}

void MapClickCommand(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;

	if (!szLine[0])
	{
		SyntaxError("Usage: /mapclick [left] <list|<key[+key[...]]> <clear|command>>");
		return;
	}

	auto f = [](char szArg[MAX_STRING], char* szRest, char(&command_array)[16][MAX_STRING], const char* szSection)
	{
		char szBuffer[MAX_STRING] = { 0 };

		if (!_stricmp(szArg, "list"))
		{
			int Count = 0;
			for (int i = 1; i < 16; i++)
			{
				if (command_array[i][0])
				{
					WriteChatf("%s: %s", DescribeCombo(i), command_array[i]);
					Count++;
				}
			}

			WriteChatf("%d special right-click commands", Count);
			return;
		}

		DWORD Combo = ParseCombo(szArg);
		if (!Combo)
		{
			WriteChatf("Invalid combo '%s'", szArg);
			return;
		}

		if (!szRest[0])
		{
			WriteChatf("%s: %s", DescribeCombo(Combo), command_array[Combo]);
			return;
		}

		if (!_stricmp(szRest, "clear"))
		{
			command_array[Combo][0] = 0;
			WritePrivateProfileString(szSection, fmt::format("KeyCombo{:d}", Combo), command_array[Combo], INIFileName);

			WriteChatf("%s -- %s cleared", szSection, DescribeCombo(Combo));
			return;
		}

		strcpy_s(command_array[Combo], szRest);
		WritePrivateProfileString(szSection, fmt::format("KeyCombo{:d}", Combo), command_array[Combo], INIFileName);

		WriteChatf("%s -- %s: %s", szSection, DescribeCombo(Combo), command_array[Combo]);
	};

	char szArg[MAX_STRING] = { 0 };
	GetArg(szArg, szLine, 1);
	char* szRest = GetNextArg(szLine);

	if (!_stricmp(szArg, "left"))
	{
		GetArg(szArg, szRest, 1);
		szRest = GetNextArg(szRest);
		f(szArg, szRest, MapLeftClickString, "Left Click");
	}
	else
	{
		f(szArg, szRest, MapSpecialClickString, "Right Click");
	}
}

// marker code
char* szMarkType[] =
{
	"None",
	"Triangle",
	"Square",
	"Diamond",
	"Ring",
};

char* FormatMarker(char* szLine, char* szDest, size_t BufferSize)
{
	ZeroMemory(szDest, BufferSize);

	char MarkType[MAX_STRING] = { 0 };
	char MarkShape[MAX_STRING] = { 0 };
	char MarkSize[MAX_STRING] = { 0 };

	GetArg(MarkType, szLine, 1);
	GetArg(MarkShape, szLine, 2);
	GetArg(MarkSize, szLine, 3);

	if (!strlen(MarkType))
	{
		sprintf_s(szDest, BufferSize, "unchanged, no spawn type given.");
		return szDest;
	}

	if (!strlen(MarkShape))
	{
		sprintf_s(szDest, BufferSize, "unchanged, no shape given.");
		return szDest;
	}

	for (DWORD i = 0; MapFilterOptions[i].szName != nullptr; i++)
	{
		if (!_stricmp(MarkType, MapFilterOptions[i].szName))
		{
			int Marker = FindMarker(MarkShape);
			if (Marker == 99)
			{
				sprintf_s(szDest, BufferSize, "unchanged, unknown shape: '%s'", MarkShape);
				return szDest;
			}

			int Size = 6;
			if (strlen(MarkSize))
			{
				Size = GetIntFromString(MarkSize, 0);
				if (!Size)
				{
					sprintf_s(szDest, BufferSize, "unchanged, invalid size: '%s'", MarkSize);
					return szDest;
				}
			}

			WritePrivateProfileString("Marker Filters", MapFilterOptions[i].szName, szMarkType[Marker], INIFileName);
			WritePrivateProfileInt("Marker Filters", fmt::format("{}-Size", MapFilterOptions[i].szName), Size, INIFileName);

			MapFilterOptions[i].Marker = Marker;
			MapFilterOptions[i].MarkerSize = Size;

			sprintf_s(szDest, BufferSize, "'%s' is now set to '%s' with size %d.", MapFilterOptions[i].szName, szMarkType[Marker], Size);
			return szDest;
		}
	}

	sprintf_s(szDest, BufferSize, "unchanged, unknown spawn type: %s", MarkType);
	return szDest;
}
