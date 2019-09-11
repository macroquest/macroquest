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

#include "../MQ2Plugin.h"
#include "MQ2Map.h"

#include <sstream>
#include <algorithm>
#include <iomanip>
#include <tuple>

// ***************************************************************************
// Function:    MapFilters
// Description: Our '/mapfilter' command
//              Sets map filters
// Usage:       /mapfilter [options|help]
// ***************************************************************************
void MapFilterSetting(SPAWNINFO* pChar, DWORD nMapFilter, char* szValue)
{
	if (!pChar) return;

	char szBuffer[MAX_STRING] = { 0 };
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
		sprintf_s(szBuffer, "'%s' requires '%s' option.  Please enable this option first.", pMapFilter->szName, MapFilterOptions[pMapFilter->RequiresOption].szName);
		WriteChatColor(szBuffer, USERCOLOR_DEFAULT);
		return;
	}

	if (!szValue)
	{
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
			char szBuffer2[MAX_STRING] = { 0 };
			DWORD R, G, B;
			R = (pMapFilter->Color & 0xFF0000) / 0x10000;
			G = (pMapFilter->Color & 0xFF00) / 0x100;
			B = pMapFilter->Color & 0xFF;
			sprintf_s(szBuffer2, "%s (Color: %d %d %d)", szBuffer, R, G, B);
			strcpy_s(szBuffer, szBuffer2);
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
			sprintf_s(szBuffer, "%s is now set to: %s", pMapFilter->szName, szFilterMap[IsOptionEnabled(nMapFilter)]);
		}
		else if (nMapFilter == MAPFILTER_Custom)
		{
			ClearSearchSpawn(&MapFilterCustom);
			if (szValue[0] == 0)
			{
				pMapFilter->Enabled = 0;
				sprintf_s(szBuffer, "%s is now set to: Off", pMapFilter->szName);
			}
			else
			{
				pMapFilter->Enabled = 1;
				ParseSearchSpawn(szValue, &MapFilterCustom);
				sprintf_s(szBuffer, "%s is now set to: %s", pMapFilter->szName, FormatSearchSpawn(Buff, sizeof(Buff), &MapFilterCustom));
			}
		}
		else if (nMapFilter == MAPFILTER_Marker)
		{
			char szBuffer2[MAX_STRING] = { 0 };
			GetArg(szBuffer2, szValue, 1);

			if (!_stricmp(szFilterMap[0], szValue))
			{
				pMapFilter->Enabled = 0;
				sprintf_s(szBuffer, "%s is now set to: %s", pMapFilter->szName, szFilterMap[IsOptionEnabled(nMapFilter)]);
			}
			else if (!_stricmp(szFilterMap[1], szValue))
			{
				pMapFilter->Enabled = 1;
				sprintf_s(szBuffer, "%s is now set to: %s", pMapFilter->szName, szFilterMap[IsOptionEnabled(nMapFilter)]);
			}
			else
			{
				pMapFilter->Enabled = 1;
				sprintf_s(szBuffer, "%s %s", pMapFilter->szName, FormatMarker(szValue, Buff, sizeof(Buff)));
			}
		}
		else
		{
			pMapFilter->Enabled = atoi(szValue);
			sprintf_s(szBuffer, "%s is now set to: %d", pMapFilter->szName, pMapFilter->Enabled);
		}
	}

	WriteChatColor(szBuffer, USERCOLOR_DEFAULT);
	if (szValue)
	{
		_itoa_s(pMapFilter->Enabled, szBuffer, 10);
		WritePrivateProfileString("Map Filters", pMapFilter->szName, szBuffer, INIFileName);
	}
}

void MapFilters(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = TRUE;
	char szArg[MAX_STRING] = { 0 };
	GetArg(szArg, szLine, 1);
	char* szRest = GetNextArg(szLine);
	char szBuffer[MAX_STRING] = { 0 };

	if (szArg[0] == 0) // Display Settings
	{
		WriteChatColor("Map filtering settings:", USERCOLOR_DEFAULT);
		WriteChatColor("-----------------------", USERCOLOR_DEFAULT);

		for (DWORD i = 0; MapFilterOptions[i].szName != nullptr; i++)
		{
			if (RequirementsMet(i))
				MapFilterSetting(pChar, i);
		}
	}
	else if (!_strnicmp(szArg, "help", 4)) // Display Help
	{
		WriteChatColor("Map filtering options:", USERCOLOR_DEFAULT);
		for (DWORD i = 0; MapFilterOptions[i].szName != nullptr; i++)
		{
			sprintf_s(szBuffer, "%s%s: %s", MapFilterOptions[i].szName, (MapFilterOptions[i].bIsToggle) ? "" : " #", MapFilterOptions[i].szHelpString);
			WriteChatColor(szBuffer, USERCOLOR_DEFAULT);
		}

		WriteChatColor("'option' color [r g b]: Set display color for 'option' (Omit to reset to default)", USERCOLOR_DEFAULT);
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
						sprintf_s(szBuffer, "Option '%s' does not have a color.", MapFilterOptions[i].szName);
						WriteChatColor(szBuffer, USERCOLOR_DEFAULT);
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
							R = atoi(szArg);
							G = atoi(GetArg(szArg, szRest, 3));
							B = atoi(GetArg(szArg, szRest, 4));
							if (R>255) R = 255;
							if (G>255) G = 255;
							if (B>255) B = 255;
							MapFilterOptions[i].Color = R * 0x10000 + G * 0x100 + B;
						}

						sprintf_s(szBuffer, "Option '%s' color set to: %d %d %d", MapFilterOptions[i].szName, R, G, B);
						WriteChatColor(szBuffer, USERCOLOR_DEFAULT);
						_itoa_s(MapFilterOptions[i].Color & 0xFFFFFF, szBuffer, 10);
						sprintf_s(szBuffer2, "%s-Color", MapFilterOptions[i].szName);
						WritePrivateProfileString("Map Filters", szBuffer2, szBuffer, INIFileName);
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
			SyntaxError("Usage: /mapfilter [option|help]");
		else if (Found->RegenerateOnChange)
		{
			MapClear();
			MapGenerate();
		}
	}
}

void MapActiveLayerCmd(SPAWNINFO* pChar, char* szLine)
{
	char szBuffer[MAX_STRING] = { 0 };
	bRunNextCommand = TRUE;
	int newActiveLayer = atoi(szLine);
	if (szLine == nullptr || szLine[0] == 0 || newActiveLayer < 0 || newActiveLayer > 3)
	{
		SyntaxError("Usage: /mapactivelayer [0|1|2|3]");
		return;
	};

	activeLayer = newActiveLayer;

	sprintf_s(szBuffer, "Map Active Layer: %d", activeLayer);
	WriteChatColor(szBuffer);

	// Write setting to file
	char szTest[5];
	sprintf_s(szTest, "%d", activeLayer);
	WritePrivateProfileString("Map Filters", "ActiveLayer", szTest, INIFileName);

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

	if (szLine == 0 || szLine[0] == 0)
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

			if (atoi(size) < 10 || atoi(width) > 200)
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

			if (atoi(width) < 1 || atoi(width) > 10)
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

			if (atoi(red) < 0 || atoi(red) > 255 || atoi(green) < 0 || atoi(green) > 255 || atoi(blue) < 0 || atoi(blue) > 255)
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

			if (atoi(radius_red) < 0 || atoi(radius_red) > 255 || atoi(radius_green) < 0 || atoi(radius_green) > 255 || atoi(radius_blue) < 0 || atoi(radius_blue) > 255)
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

	if (size != 0 && size[0] != 0)
	{
		loc->lineSize = atoi(size);
	}
	if (width != 0 && width[0] != 0)
	{
		loc->width = atoi(width);
	}
	if (red != 0 && red[0] != 0)
	{
		loc->r_color = atoi(red);
		loc->g_color = atoi(green);
		loc->b_color = atoi(blue);
	}
	if (radius != 0 && radius[0] != 0)
	{
		loc->radius = atoi(radius);
	}
	if (radius_red != 0 && radius_red[0] != 0)
	{
		loc->rr_color = atoi(radius_red);
		loc->rg_color = atoi(radius_green);
		loc->rb_color = atoi(radius_blue);
	}

	// Are we placing a new MapLoc?
	if (strcmp(yloc, "not set") != 0)
	{
		loc->yloc = static_cast<int>(std::stof(yloc));
		loc->xloc = static_cast<int>(std::stof(xloc));
		loc->zloc = static_cast<int>(std::stof(zloc));
		loc->isCreatedFromDefaultLoc = isDefaultLocSettings;
		MapLocVars << "y:" << loc->yloc << " x:" << loc->xloc << " z:" << loc->zloc;

		if (label != 0 && label[0] != 0)
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
		WritePrivateProfileString("MapLoc", "Size", std::to_string(loc->lineSize).c_str(), INIFileName);
		WritePrivateProfileString("MapLoc", "Width", std::to_string(loc->width).c_str(), INIFileName);
		WritePrivateProfileString("MapLoc", "Red", std::to_string(loc->r_color).c_str(), INIFileName);
		WritePrivateProfileString("MapLoc", "Green", std::to_string(loc->g_color).c_str(), INIFileName);
		WritePrivateProfileString("MapLoc", "Blue", std::to_string(loc->b_color).c_str(), INIFileName);
		WritePrivateProfileString("MapLoc", "Radius", std::to_string(loc->radius).c_str(), INIFileName);
		WritePrivateProfileString("MapLoc", "RadiusGreen", std::to_string(loc->rg_color).c_str(), INIFileName);
		WritePrivateProfileString("MapLoc", "RadiusRed", std::to_string(loc->rr_color).c_str(), INIFileName);
		WritePrivateProfileString("MapLoc", "RadiusBlue", std::to_string(loc->rb_color).c_str(), INIFileName);
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
	char szBuffer[MAX_STRING] = { 0 };
	char red[MAX_STRING] = { 0 };
	char green[MAX_STRING] = { 0 };
	char blue[MAX_STRING] = { 0 };
	std::stringstream ss(szLine);

	if (szLine == 0 || szLine[0] == 0)
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

		if (atoi(red) < 0 || atoi(red) > 255 || atoi(green) < 0 || atoi(green) > 255 || atoi(blue) < 0 || atoi(blue) > 255
			|| strcmp(szArg, std::to_string(atoi(szArg)).c_str()) != 0
			|| strcmp(szArg, std::to_string(atoi(green)).c_str()) != 0
			|| strcmp(szArg, std::to_string(atoi(blue)).c_str()) != 0)
		{
			SyntaxError(usage);
			return;
		}

		unsigned char R = atoi(szArg);
		unsigned char G = atoi(green);
		unsigned char B = atoi(blue);
		HighlightColor = 0xFF000000 | (R << 16) | (G << 8) | (B);
		sprintf_s(szBuffer, "Highlight color: %d %d %d", R, G, B);
		WriteChatColor(szBuffer);
		return;
	}
	else if (!_stricmp(szArg, "reset"))
	{
		MapHighlight(0);
		WriteChatColor("Highlighting reset", USERCOLOR_DEFAULT);
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

		if (strcmp(szArg, std::to_string(atoi(szArg)).c_str()) != 0) {
			SyntaxError("Usage: /highlight size #");
			return;
		}

		HighlightSIDELEN = strtol(szArg, 0, 0);
		PulseReset();
		sprintf_s(szBuffer, "Highlight size: %d", HighlightSIDELEN);
		WriteChatColor(szBuffer);

		// Write setting to file
		char szTest[5];
		sprintf_s(szTest, "%d", HighlightSIDELEN);
		WritePrivateProfileString("Map Filters", "HighSize", szTest, INIFileName);
		return;
	}
	else if (!_stricmp(szArg, "pulse"))
	{
		HighlightPulse = !HighlightPulse;
		PulseReset();
		sprintf_s(szBuffer, "Highlight pulse: %s", HighlightPulse ? "ON" : "OFF");
		WriteChatColor(szBuffer);

		// Write setting to file
		WritePrivateProfileString("Map Filters", "HighPulse", HighlightPulse ? "1" : "0", INIFileName);
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
	HighlightPulseIncreasing = TRUE;
	HighlightPulseIndex = 0;
	HighlightPulseDiff = HighlightSIDELEN / 10;
}

void MapHideCmd(SPAWNINFO* pChar, char* szLine)
{
	char szArg[MAX_STRING] = { 0 };
	char szBuffer[MAX_STRING] = { 0 };
	bRunNextCommand = TRUE;
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
		if (repeatMaphide)
			repeatMaphide = FALSE;
		else
			repeatMaphide = TRUE;

		_itoa_s(repeatMaphide, szBuffer, 10);
		WritePrivateProfileString("Map Filters", "Maphide-Repeat", szBuffer, INIFileName);

		WriteChatf("maphide repeat set to: %s", (repeatMaphide ? "on" : "off"));
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
	bRunNextCommand = TRUE;

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
		if (repeatMapshow)
			repeatMapshow = FALSE;
		else
			repeatMapshow = TRUE;

		_itoa_s(repeatMapshow, szBuffer, 10);
		WritePrivateProfileString("Map Filters", "Mapshow-Repeat", szBuffer, INIFileName);

		sprintf_s(szBuffer, "mapshow repeat set to: %s", (repeatMapshow ? "on" : "off"));
		WriteChatColor(szBuffer, USERCOLOR_DEFAULT);
		return;
	}

	if (CHARINFO* pCharInfo = GetCharInfo())
	{
		MQSpawnSearch ssShow;
		ClearSearchSpawn(&ssShow);
		ParseSearchSpawn(szLine, &ssShow);
		sprintf_s(szBuffer, "%d previously hidden spawns shown", MapShow(ssShow));
		WriteChatColor(szBuffer, USERCOLOR_DEFAULT);
	}
}

void MapNames(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = TRUE;
	char szOut[MAX_STRING] = { 0 };
	if (!szLine[0])
	{
		sprintf_s(szOut, "Normal naming string: %s", MapNameString);
		WriteChatColor(szOut, USERCOLOR_DEFAULT);
		sprintf_s(szOut, "Target naming string: %s", MapTargetNameString);
		WriteChatColor(szOut, USERCOLOR_DEFAULT);
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
		sprintf_s(szOut, "Target naming string: %s", MapTargetNameString);
		WriteChatColor(szOut, USERCOLOR_DEFAULT);
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
		sprintf_s(szOut, "Normal naming string: %s", MapNameString);
		WriteChatColor(szOut, USERCOLOR_DEFAULT);
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
	if (!szLine[0])
	{
		SyntaxError("Usage: /mapclick [left] <list|<key[+key[...]]> <clear|command>>");
		return;
	}
	bRunNextCommand = TRUE;

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
					sprintf_s(szBuffer, "%s: %s", DescribeCombo(i), command_array[i]);
					WriteChatColor(szBuffer);
					Count++;
				}
			}

			sprintf_s(szBuffer, "%d special right-click commands", Count);
			WriteChatColor(szBuffer);
			return;
		}

		DWORD Combo = ParseCombo(szArg);
		if (!Combo)
		{
			sprintf_s(szBuffer, "Invalid combo '%s'", szArg);
			WriteChatColor(szBuffer);
			return;
		}

		if (!szRest[0])
		{
			sprintf_s(szBuffer, "%s: %s", DescribeCombo(Combo), command_array[Combo]);
			WriteChatColor(szBuffer);
			return;
		}

		if (!_stricmp(szRest, "clear"))
		{
			command_array[Combo][0] = 0;

			sprintf_s(szBuffer, "KeyCombo%d", Combo);
			WritePrivateProfileString(szSection, szBuffer, command_array[Combo], INIFileName);
			sprintf_s(szBuffer, "%s -- %s cleared", szSection, DescribeCombo(Combo));
			WriteChatColor(szBuffer);
			return;
		}

		strcpy_s(command_array[Combo], szRest);
		sprintf_s(szBuffer, "KeyCombo%d", Combo);
		WritePrivateProfileString(szSection, szBuffer, command_array[Combo], INIFileName);
		sprintf_s(szBuffer, "%s -- %s: %s", szSection, DescribeCombo(Combo), command_array[Combo]);
		WriteChatColor(szBuffer);
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
			DWORD Marker = FindMarker(MarkShape);
			if (Marker == 99)
			{
				sprintf_s(szDest, BufferSize, "unchanged, unknown shape: '%s'", MarkShape);
				return szDest;
			}

			DWORD Size = 6;
			if (strlen(MarkSize))
			{
				Size = (int)atoi(MarkSize);
				if (!Size)
				{
					sprintf_s(szDest, BufferSize, "unchanged, invalid size: '%s'", MarkSize);
					return szDest;
				}
			}

			char tmp_1[MAX_STRING] = { 0 };
			char tmp_2[MAX_STRING] = { 0 };
			sprintf_s(tmp_1, "%s-Size", MapFilterOptions[i].szName);
			sprintf_s(tmp_2, "%d", Size);

			WritePrivateProfileString("Marker Filters", MapFilterOptions[i].szName, szMarkType[Marker], INIFileName);
			WritePrivateProfileString("Marker Filters", tmp_1, tmp_2, INIFileName);

			MapFilterOptions[i].Marker = Marker;
			MapFilterOptions[i].MarkerSize = Size;

			sprintf_s(szDest, BufferSize, "'%s' is now set to '%s' with size %d.", MapFilterOptions[i].szName, szMarkType[Marker], Size);
			return szDest;
		}
	}

	sprintf_s(szDest, BufferSize, "unchanged, unknown spawn type: %s", MarkType);
	return szDest;
}
