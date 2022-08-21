/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2022 MacroQuest Authors
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
#include "MapObject.h"

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
void MapFilterSetting(SPAWNINFO* pChar, MapFilter nMapFilter, const char* szValue /* = nullptr */)
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

	MapFilterOption* pMapFilter = &MapFilterOptions[static_cast<size_t>(nMapFilter)];
	if (!RequirementsMet(nMapFilter))
	{
		MapFilterOption& option = MapFilterOptions[static_cast<size_t>(pMapFilter->RequiresOption)];
		WriteChatf("'%s' requires '%s' option.  Please enable this option first.", pMapFilter->szName, option.szName);
		return;
	}

	if (!szValue)
	{
		char szBuffer[MAX_STRING] = { 0 };

		if (pMapFilter->IsToggle())
		{
			sprintf_s(szBuffer, "%s: %s", pMapFilter->szName, szFilterMap[pMapFilter->Enabled]);
		}
		else if (nMapFilter == MapFilter::Custom)
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
		else if (pMapFilter->UsesRadius)
		{
			sprintf_s(szBuffer, "%s: %0.2f", pMapFilter->szName, pMapFilter->Radius);
		}
		else
		{
			sprintf_s(szBuffer, "%s: %d", pMapFilter->szName, pMapFilter->Enabled);
		}

		if (pMapFilter->HasColor())
		{
			WriteChatf("%s (Color: %d %d %d)", szBuffer, pMapFilter->Color.Red,
				pMapFilter->Color.Green, pMapFilter->Color.Blue);
		}
		else
		{
			WriteChatf("%s", szBuffer);
		}
	}
	else
	{
		if (pMapFilter->IsToggle())
		{
			if (!_stricmp(szFilterMap[0], szValue))
			{
				pMapFilter->Enabled = false;
			}
			else if (!_stricmp(szFilterMap[1], szValue))
			{
				pMapFilter->Enabled = true;
			}
			else
			{
				pMapFilter->Enabled = !pMapFilter->Enabled;
			}

			WriteChatf("%s is now set to: %s", pMapFilter->szName, szFilterMap[IsOptionEnabled(nMapFilter)]);
		}
		else if (nMapFilter == MapFilter::Custom)
		{
			ClearSearchSpawn(&MapFilterCustom);
			if (szValue[0] == 0)
			{
				pMapFilter->Enabled = false;
				WriteChatf("%s is now set to: Off", pMapFilter->szName);
			}
			else
			{
				pMapFilter->Enabled = true;
				ParseSearchSpawn(szValue, &MapFilterCustom);

				WriteChatf("%s is now set to: %s", pMapFilter->szName, FormatSearchSpawn(Buff, sizeof(Buff), &MapFilterCustom));
			}
		}
		else if (nMapFilter == MapFilter::Marker)
		{
			char szBuffer2[MAX_STRING] = { 0 };
			GetArg(szBuffer2, szValue, 1);

			if (!_stricmp(szFilterMap[0], szValue))
			{
				pMapFilter->Enabled = false;
				WriteChatf("%s is now set to: %s", pMapFilter->szName, szFilterMap[IsOptionEnabled(nMapFilter)]);
			}
			else if (!_stricmp(szFilterMap[1], szValue))
			{
				pMapFilter->Enabled = true;
				WriteChatf("%s is now set to: %s", pMapFilter->szName, szFilterMap[IsOptionEnabled(nMapFilter)]);
			}
			else
			{
				pMapFilter->Enabled = true;
				WriteChatf("%s %s", pMapFilter->szName, FormatMarker(szValue, Buff, sizeof(Buff)));
			}
		}
	}

	if (szValue)
	{
		WritePrivateProfileBool("Map Filters", pMapFilter->szName, pMapFilter->Enabled, INIFileName);
	}
}

void MapFilterColorSetting(MapFilter nMapFilter, const char* szValue)
{
	char szArg[MAX_STRING] = { 0 };
	MapFilterOption option = MapFilterOptions[static_cast<size_t>(nMapFilter)];

	if (!option.HasColor())
	{
		WriteChatf("Option '%s' does not have a color.", option.szName);
	}
	else
	{
		char szBuffer2[MAX_STRING] = { 0 };
		GetArg(szArg, szValue, 2);

		MQColor& color = option.Color;

		if (szArg[0] == 0)
		{
			option.Color = option.DefaultColor;
		}
		else
		{
			uint8_t R = std::clamp(GetIntFromString(szArg, 255), 0, 255);
			uint8_t G = std::clamp(GetIntFromString(GetArg(szArg, szValue, 3), 255), 0, 255);
			uint8_t B = std::clamp(GetIntFromString(GetArg(szArg, szValue, 4), 255), 0, 255);
			color = MQColor(R, G, B);
		}

		WriteChatf("Option '%s' color set to: %d %d %d", option.szName, color.Red, color.Green, color.Blue);
		WritePrivateProfileInt("Map Filters", fmt::format("{}-Color", option.szName), option.Color.ToRGB(), INIFileName);
	}
}

void MapFilterRadiusSetting(SPAWNINFO* pChar, MapFilter nMapFilter, const char* szValue)
{
	if (!pChar) return;
	MapFilterOption* option = &MapFilterOptions[static_cast<size_t>(nMapFilter)];
	option->Radius = GetFloatFromString(szValue, 0.0f);
	option->Enabled = option->Radius > 0.0f;

	if (option->Radius > 0.0f && !_stricmp(option->szName, "CampRadius"))
	{
		CampX = pChar->X;
		CampY = pChar->Y;
	}

	if (option->Radius > 0.0f && !_stricmp(option->szName, "PullRadius"))
	{
		PullX = pChar->X;
		PullY = pChar->Y;
	}

	WriteChatf("%s is now set to: %.2f", option->szName, option->Radius);
	WritePrivateProfileFloat("Map Filters", option->szName, option->Radius, INIFileName);
}

void MapFilters(SPAWNINFO* pChar, char* szLine)
{
	bRunNextCommand = true;

	char szArg[MAX_STRING] = { 0 };
	GetArg(szArg, szLine, 1);
	const char* szRest = GetNextArg(szLine);

	if (szArg[0] == 0) // Display Settings
	{
		WriteChatColor("Map filtering settings:");
		WriteChatColor("-----------------------");

		for (uint32_t i = 0; MapFilterOptions[i].szName != nullptr; i++)
		{
			MapFilter mf = static_cast<MapFilter>(i);

			if (RequirementsMet(mf))
				MapFilterSetting(pChar, mf);
		}
	}
	else if (!_strnicmp(szArg, "help", 4)) // Display Help
	{
		WriteChatColor("Map filtering options:");

		for (DWORD i = 0; MapFilterOptions[i].szName != nullptr; i++)
		{
			WriteChatf("%s%s: %s", MapFilterOptions[i].szName, (MapFilterOptions[i].IsToggle()) ? "" : " #", MapFilterOptions[i].szHelpString);
		}

		WriteChatColor("'option' color [r g b]: Set display color for 'option' (Omit to reset to default)");
	}
	else // Set Option
	{
		MapFilterOption* Found = nullptr;
		for (uint32_t i = 0; MapFilterOptions[i].szName != nullptr; i++)
		{
			MapFilterOption& option = MapFilterOptions[i];

			if (!_stricmp(szArg, option.szName))
			{
				if (!_strnicmp(szRest, "color", 5))
				{
					MapFilterColorSetting(static_cast<MapFilter>(i), szRest);
				}
				else if (option.IsRadius())
				{
					MapFilterRadiusSetting(pChar, static_cast<MapFilter>(i), szRest);
				}
				else
				{
					MapFilterSetting(pChar, static_cast<MapFilter>(i), szRest);
				}

				Found = &option;
			}
		}

		if (!Found)
		{
			SyntaxError("Usage: /mapfilter [option|help]");
		}
		else if (Found->IsRegenerateOnChange())
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

			if (GetIntFromString(size, 9) < 10 || GetIntFromString(size, 201) > 200)
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

			CVector3 targetLoc{ pTarget->X, pTarget->Y, pTarget->Z };

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

	std::stringstream MapLocVars;
	MapLocVars << "MapLoc: ";

	// Init params either from MapLoc with matching tag, or the defaults.
	MapLocParams params;

	MapObjectMapLoc* origLoc = GetMapLocByTag(tag);
	if (origLoc)
	{
		params = origLoc->GetParams();
	}
	else
	{
		params = gDefaultMapLocParams;
	}

	if (size[0] != 0)
	{
		//loc->lineSize = GetIntFromString(size, DefaultMapLoc->lineSize);
		params.lineSize = GetFloatFromString(size, gDefaultMapLocParams.lineSize);
	}

	if (width[0] != 0)
	{
		//loc->width = GetIntFromString(width, DefaultMapLoc->width);
		params.width = GetFloatFromString(width, gDefaultMapLocParams.width);
	}

	if (red[0] != 0)
	{
		//loc->r_color = GetIntFromString(red, DefaultMapLoc->r_color);
		//loc->g_color = GetIntFromString(green, DefaultMapLoc->g_color);
		//loc->b_color = GetIntFromString(blue, DefaultMapLoc->b_color);
		params.color = MQColor{
			(uint8_t)GetIntFromString(red, gDefaultMapLocParams.color.Red),
			(uint8_t)GetIntFromString(green, gDefaultMapLocParams.color.Green),
			(uint8_t)GetIntFromString(blue, gDefaultMapLocParams.color.Blue)
		};
	}

	if (radius[0] != 0)
	{
		//loc->radius = GetIntFromString(radius, DefaultMapLoc->radius);
		params.circleRadius = GetFloatFromString(radius, gDefaultMapLocParams.circleRadius);
	}

	if (radius_red[0] != 0)
	{
		//loc->rr_color = GetIntFromString(radius_red, DefaultMapLoc->rr_color);
		//loc->rg_color = GetIntFromString(radius_green, DefaultMapLoc->rg_color);
		//loc->rb_color = GetIntFromString(radius_blue, DefaultMapLoc->rb_color);
		params.circleColor = MQColor{
			(uint8_t)GetIntFromString(radius_red, gDefaultMapLocParams.circleColor.Red),
			(uint8_t)GetIntFromString(radius_green, gDefaultMapLocParams.circleColor.Green),
			(uint8_t)GetIntFromString(radius_blue, gDefaultMapLocParams.circleColor.Blue)
		};
	}

	// Updating an existing thing
	if (origLoc)
	{
		origLoc->UpdateFromParams(params);
	}

	// not updating an existing thing. and we aren't placing a location, so update the defaults
	else if (!strcmp(yloc, "not set"))
	{
		gDefaultMapLocParams = params;
		MapLocVars << "DefaultLoc";

		// If we aren't placing a loc, then the values are updates to the default. Persist them.
		WritePrivateProfileFloat("MapLoc", "Size", params.lineSize, INIFileName);
		WritePrivateProfileFloat("MapLoc", "Width", params.width, INIFileName);
		WritePrivateProfileInt("MapLoc", "Red", params.color.Red, INIFileName);
		WritePrivateProfileInt("MapLoc", "Green", params.color.Green, INIFileName);
		WritePrivateProfileInt("MapLoc", "Blue", params.color.Blue, INIFileName);
		WritePrivateProfileFloat("MapLoc", "Radius", params.circleRadius, INIFileName);
		WritePrivateProfileInt("MapLoc", "RadiusRed", params.circleColor.Red, INIFileName);
		WritePrivateProfileInt("MapLoc", "RadiusGreen", params.circleColor.Green, INIFileName);
		WritePrivateProfileInt("MapLoc", "RadiusBlue", params.circleColor.Blue, INIFileName);

		UpdateDefaultMapLocInstances();
	}

	// we are placing a new MapLoc.
	else
	{
		// FIXME: exception handling?
		CVector3 pos{ std::stof(xloc), std::stof(yloc), std::stof(zloc) };

		MakeMapLoc(params, label, tag, pos, isDefaultLocSettings);

		MapLocVars
			<< "y:" << pos.Y
			<< " x:" << pos.X
			<< " z:" << pos.Z;

		if (label[0] != 0)
		{
			MapLocVars << ", Label: " << label;
		}
	}

	if (!isDefaultLocSettings)
	{
		MapLocVars
			<< ", Width:" << params.width
			<< ", Size:" << params.lineSize
			<< ", Color:" << std::to_string(params.color.Red) << "," << std::to_string(params.color.Green) << "," << std::to_string(params.color.Blue)
			<< ", Radius:" << params.circleRadius
			<< ", Radius Color:" << std::to_string(params.circleColor.Red) << "," << std::to_string(params.circleColor.Green) << "," << std::to_string(params.circleColor.Blue);
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
		HighlightColor = MQColor(R, G, B);

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
	const char* szRest = GetNextArg(szLine);

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
	const char* szRest = GetNextArg(szLine);

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

char* FormatMarker(const char* szLine, char* szDest, size_t BufferSize)
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

	for (uint32_t i = 0; MapFilterOptions[i].szName != nullptr; i++)
	{
		if (!_stricmp(MarkType, MapFilterOptions[i].szName))
		{
			MarkerType Marker = FindMarker(MarkShape);
			if (Marker == MarkerType::Unknown)
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

			WritePrivateProfileString("Marker Filters", MapFilterOptions[i].szName, szMarkType[static_cast<size_t>(Marker)], INIFileName);
			WritePrivateProfileInt("Marker Filters", fmt::format("{}-Size", MapFilterOptions[i].szName), Size, INIFileName);

			MapFilterOptions[i].Marker = Marker;
			MapFilterOptions[i].MarkerSize = Size;

			sprintf_s(szDest, BufferSize, "'%s' is now set to '%s' with size %d.", MapFilterOptions[i].szName, szMarkType[static_cast<size_t>(Marker)], Size);
			return szDest;
		}
	}

	sprintf_s(szDest, BufferSize, "unchanged, unknown spawn type: %s", MarkType);
	return szDest;
}

static void DrawMapSetting_SingleFilter(MapFilter filter)
{

}

static void DrawMapSettings_Options()
{
	bool regenerate = false;

	MapFilterOption& allOption = GetMapFilterOption(MapFilter::All);
	if (ImGui::Checkbox("Enable MQ2Map Labels", &allOption.Enabled))
		regenerate = true;

	ImGui::NewLine();

	if (ImGui::CollapsingHeader("Object Filters", ImGuiTreeNodeFlags_DefaultOpen))
	{
		ImGui::Indent();

		constexpr MapFilter basicFilters[] = {
			MapFilter::Target,
			MapFilter::PC,
			MapFilter::NPC,
			MapFilter::Pet,
			MapFilter::Group,
			MapFilter::Mercenary,
			MapFilter::Corpse,
			MapFilter::PCCorpse,
			MapFilter::NPCCorpse,
			MapFilter::Ground,
			MapFilter::Mount,
			MapFilter::Chest,
			MapFilter::Banner,
			MapFilter::Campfire,
			MapFilter::Object,
			MapFilter::Trigger,
			MapFilter::Trap,
			MapFilter::Untargetable,
			MapFilter::Timer,
			MapFilter::Aura,
		};

		for (MapFilter filter : basicFilters)
		{
			MapFilterOption& option = GetMapFilterOption(filter);
			ImGui::PushID(&option);

			bool changed = false;

			bool isRequirementMet = RequirementsMet(filter);

			if (!isRequirementMet)
			{
				ImGui::PushStyleColor(ImGuiCol_Text, MQColor(255, 255, 255, 100).ToABGR());
			}

			if (ImGui::Checkbox(option.szName, &option.Enabled))
				changed = true;
			ImGui::SameLine();
			ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 0.5f), "- %s", option.szHelpString);

			if (changed && option.IsRegenerateOnChange())
				regenerate = true;
			if (changed)
				WritePrivateProfileBool("Map Filters", option.szName, option.Enabled, INIFileName);

			if (!isRequirementMet)
			{
				ImGui::PopStyleColor();
			}

			ImGui::PopID();
		}
	}
	ImGui::Unindent();

	ImGui::Separator();

	//MapFilterOption& allOption = GetMapFilterOption(MapFilter::PCConColor);
	//MapFilterOption& allOption = GetMapFilterOption(MapFilter::NPCConColor);
	//MapFilterOption& allOption = GetMapFilterOption(MapFilter::TargetLine);
	//MapFilterOption& allOption = GetMapFilterOption(MapFilter::TargetRadius);
	//MapFilterOption& allOption = GetMapFilterOption(MapFilter::TargetMelee);
	//MapFilterOption& allOption = GetMapFilterOption(MapFilter::TargetPath);
	//MapFilterOption& allOption = GetMapFilterOption(MapFilter::Vector);
	//MapFilterOption& allOption = GetMapFilterOption(MapFilter::Custom);
	//MapFilterOption& allOption = GetMapFilterOption(MapFilter::CastRadius);
	//MapFilterOption& allOption = GetMapFilterOption(MapFilter::NormalLabels);
	//MapFilterOption& allOption = GetMapFilterOption(MapFilter::ContextMenu);
	//MapFilterOption& allOption = GetMapFilterOption(MapFilter::SpellRadius);
	//MapFilterOption& allOption = GetMapFilterOption(MapFilter::Named);
	//MapFilterOption& allOption = GetMapFilterOption(MapFilter::Marker);
	//MapFilterOption& allOption = GetMapFilterOption(MapFilter::CampRadius);
	//MapFilterOption& allOption = GetMapFilterOption(MapFilter::PullRadius);


	//for (int index = 0; MapFilterOptions[index].szName != nullptr; ++index)
	//{
	//	MapFilterOption& option = MapFilterOptions[index];

	//	if (!option.IsToggle() && !option.IsRadius())
	//		continue;

	//	bool changed = false;
	//	ImGui::PushID(&option);

	//	ImGui::Text("%s", option.szName);
	//	if (option.szHelpString)
	//	{
	//		ImGui::SameLine();
	//		ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 0.5f), " - %s", option.szHelpString);
	//	}

	//	bool isRequirementMet = RequirementsMet(static_cast<MapFilter>(index));

	//	if (!isRequirementMet)
	//	{
	//		ImGui::PushStyleColor(ImGuiCol_Text, MQColor(255, 255, 255, 100).ToRGBA8());
	//	}

	//	if (option.IsToggle() || option.IsRadius())
	//	{
	//		if (ImGui::Checkbox("Enabled", &option.Enabled))
	//			changed = true;
	//	}

	//	if (option.IsRadius())
	//	{
	//		ImGui::PushItemWidth(-1);
	//		if (ImGui::DragFloat("Radius", &option.Radius))
	//			changed = true;
	//		ImGui::PopItemWidth();
	//	}

	//	if (!isRequirementMet)
	//	{
	//		ImGui::PopStyleColor();
	//	}

	//	ImGui::PopID();
	//	ImGui::Separator();

	//	if (changed && option.IsRegenerateOnChange())
	//		regenerate = true;
	//}

	if (regenerate)
	{
		MapClear();
		MapGenerate();
	}
}

static void DrawMapSettings_Colors()
{
	bool regenerate = false;

	for (int index = 0; MapFilterOptions[index].szName != nullptr; ++index)
	{
		MapFilterOption& option = MapFilterOptions[index];
		bool changed = false;

		if (!option.HasColor())
			continue;

		ImGui::PushID(&option);

		ImColor color = option.Color.ToImColor();

		if (ImGui::ColorEdit3(option.szName, &color.Value.x))
		{
			option.Color.Blue = static_cast<uint8_t>(color.Value.z * 255);
			option.Color.Green = static_cast<uint8_t>(color.Value.y * 255);
			option.Color.Red = static_cast<uint8_t>(color.Value.x * 255);
			option.Color.Alpha = 255;
			changed = true;
		}

		if (option.Color != option.DefaultColor)
		{
			ImGui::SameLine();
			if (ImGui::Button("Reset"))
			{
				option.Color = option.DefaultColor;
				changed = true;
			}
		}

		ImGui::PopID();
		ImGui::Separator();

		if (changed && option.IsRegenerateOnChange())
			regenerate = true;
	}

	if (regenerate)
	{
		MapClear();
		MapGenerate();
	}
}

void DrawMapSettingsPanel()
{
	if (ImGui::BeginTabBar("MQ2Map TabBar", ImGuiTabBarFlags_NoCloseWithMiddleMouseButton))
	{
		if (ImGui::BeginTabItem("Options"))
		{
			DrawMapSettings_Options();
			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Colors"))
		{
			DrawMapSettings_Colors();
			ImGui::EndTabItem();
		}

		ImGui::EndTabBar();
	}
}
