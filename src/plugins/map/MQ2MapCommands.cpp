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

#include <mq/Plugin.h>
#include <mq/base/Vector.h>
#include <mq/base/String.h>

#include "MQ2Map.h"
#include "MapObject.h"
#include "imgui/ImGuiUtils.h"

#include <sstream>
#include <algorithm>
#include <iomanip>
#include <tuple>

#include <glm/glm.hpp>
#include <fmt/format.h>

// ***************************************************************************
// Function:    MapFilters
// Description: Our '/mapfilter' command
//              Sets map filters
// Usage:       /mapfilter [options|help]
// ***************************************************************************
void MapFilterSetting(PlayerClient* pChar, MapFilter nMapFilter, const char* szValue /* = nullptr */)
{
	if (!pChar) return;

	char Buff[MAX_STRING] = { 0 };
	DWORD dwValue = 0;

	const char* szFilterMap[] =
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
		else if (pMapFilter->IsRadius())
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

void MapFilters(PlayerClient* pChar, const char* szLine)
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

void MapActiveLayerCmd(PlayerClient* pChar, const char* szLine)
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

void MapSetLocationCmd(PlayerClient* pChar, const char* szLine)
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
			MapRemoveLocation(szLine);
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

			std::stringstream targetLabel;
			targetLabel << "Target [" << pTarget->Name << "] was here";
			sprintf_s(label, "%s", targetLabel.str().c_str());
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

	MapLocTemplate* origLoc = GetMapLocTemplateByTag(tag);
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
		params.lineSize = GetFloatFromString(size, gDefaultMapLocParams.lineSize);
	}

	if (width[0] != 0)
	{
		params.width = GetFloatFromString(width, gDefaultMapLocParams.width);
	}

	if (red[0] != 0)
	{
		params.color = MQColor{
			(uint8_t)GetIntFromString(red, gDefaultMapLocParams.color.Red),
			(uint8_t)GetIntFromString(green, gDefaultMapLocParams.color.Green),
			(uint8_t)GetIntFromString(blue, gDefaultMapLocParams.color.Blue)
		};
	}

	if (radius[0] != 0)
	{
		params.circleRadius = GetFloatFromString(radius, gDefaultMapLocParams.circleRadius);
	}

	if (radius_red[0] != 0)
	{
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
		origLoc->SetLabel(label);
		MapLocVars << "Updating existing loc, Index: " << origLoc->GetIndex();
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
		try {
			CVector3 pos{ std::stof(xloc), std::stof(yloc), std::stof(zloc) };

			std::unique_ptr<MapLocTemplate> newMapLocTemplate = std::make_unique<MapLocTemplate>(params, label, tag, pos, isDefaultLocSettings);
			auto newMapLoc = newMapLocTemplate.get();
			AddMapLoc(std::move(newMapLocTemplate));

			std::string_view labelStr = newMapLoc->GetLabelText();
			MapLocVars
				<< "y:" << pos.Y
				<< " x:" << pos.X
				<< " z:" << pos.Z
				<< ", Index: " << newMapLoc->GetIndex()
				<< ", Label: " << labelStr;
		}
		catch (const std::exception&) {
			WriteChatf("\arFailed to create map loc: invalid arguments");
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

void MapHighlightCmd(PlayerClient* pChar, const char* szLine)
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

		WritePrivateProfileInt("Map Filters", "High-Color", HighlightColor.ARGB, INIFileName);
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

void MapHideCmd(PlayerClient* pChar, const char* szLine)
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

void MapShowCmd(PlayerClient* pChar, const char* szLine)
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

void MapNames(PlayerClient* pChar, const char* szLine)
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

const char* DescribeCombo(DWORD Combo)
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
const char* szMarkType[] =
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

static bool IsMapLocsStyleOverridden()
{
	if (gOverrideMapLocParams.lineSize != gDefaultMapLocParams.lineSize) return true;
	if (gOverrideMapLocParams.width != gDefaultMapLocParams.width) return true;
	if (gOverrideMapLocParams.color.Red != gDefaultMapLocParams.color.Red) return true;
	if (gOverrideMapLocParams.color.Green != gDefaultMapLocParams.color.Green) return true;
	if (gOverrideMapLocParams.color.Blue != gDefaultMapLocParams.color.Blue) return true;
	if (gOverrideMapLocParams.circleRadius != gDefaultMapLocParams.circleRadius) return true;
	if (gOverrideMapLocParams.circleColor.Red != gDefaultMapLocParams.circleColor.Red) return true;
	if (gOverrideMapLocParams.circleColor.Green != gDefaultMapLocParams.circleColor.Green) return true;
	if (gOverrideMapLocParams.circleColor.Blue != gDefaultMapLocParams.circleColor.Blue) return true;

	return false;
}

static void BuildFilteredOptionArray(std::vector<MapFilterOption*> &options)
{
	for (size_t childIndex = 0; childIndex < options.size(); childIndex++)
	{
		MapFilter parentFilter = options[childIndex]->RequiresOption;
		if (parentFilter != MapFilter::Invalid)
		{
			MapFilterOption parentFilterOption = GetMapFilterOption(parentFilter);
			for (size_t parentIndex = 0; parentIndex < options.size(); parentIndex++)
			{
				if (std::strcmp(parentFilterOption.szName, options[parentIndex]->szName) == 0)
				{
					// Find location to move child after parent, including sorting sub children alphabetically
					size_t childNewIndex = parentIndex + 1;
					for (size_t movedChildIndex = childNewIndex;
						movedChildIndex < options.size() - 1 &&
						options[movedChildIndex]->RequiresOption == options[movedChildIndex + 1]->RequiresOption &&
						std::strcmp(options[movedChildIndex]->szName, options[movedChildIndex + 1]->szName) > 0;
						movedChildIndex++)
					{
						childNewIndex = movedChildIndex;
					}

					move_element(options, childIndex, childNewIndex);

					// Adjust iterator for movement
					if (childIndex < parentIndex)
					{
						// Current element was moved later and the next element was put in its place, so recheck current.
						childIndex--;
					} // else current element was moved earlier in the array, and the element that took its place is one we previously checked, so continue

					continue; // we found the parent, move onto next i value and skip the rest of the j's
				}
			}
		}
	}
}

static void BuildOptionArrays()
{
	// Build the lists once, cache them for future use
	if (mapFilterGeneralOptions.size() > 0)
		return;

	// Copy MapFilterOptions
	std::vector<MapFilterOption*> allFilterOptions;
	for (MapFilterOption& option : MapFilterOptions)
	{
		if (option.ThisFilter != MapFilter::Invalid && option.ThisFilter != MapFilter::All)
			allFilterOptions.push_back(&option);
	}

	// Sort copied array alphabetically
	std::sort(allFilterOptions.begin(), allFilterOptions.end(),
		[](MapFilterOption* a, MapFilterOption* b) -> bool
		{
			if (a->szName == nullptr) return false;
			if (b->szName == nullptr) return true;
			return ci_less()(a->szName, b->szName);
		}
	);

	// Build filtered arrays by type
	for (auto option : allFilterOptions)
	{
		if (option->IsToggle() || option->IsRadius())
		{
			if (option->IsObject())
			{
				mapFilterObjectOptions.push_back(option);
			}
			else
			{
				mapFilterGeneralOptions.push_back(option);
			}
		}
	}

	// Put children under parents
	BuildFilteredOptionArray(mapFilterObjectOptions);
	BuildFilteredOptionArray(mapFilterGeneralOptions);
}

/// <summary>
/// Adds ImGui setting object
/// </summary>
/// <returns>true if needs to regenerate</returns>
static bool AddMapFilterOptionAsImGuiSetting(MapFilterOption* option, std::stack<MapFilterOption*> &optionStack)
{
	bool changed = false;
	bool regenerate = false;
	bool isRequirementMet = RequirementsMet(option->ThisFilter);

	ImGui::PushID(option);

	// if this requires previous, indent
	// if this req is equal to previous req, no change
	// if this requires something new, not previous, pop-loop (and unindent) until previous conditions are met or until stack empty
	MapFilterOption* previousOption;
	bool nested = false;
	while (optionStack.size() > 0)
	{
		previousOption = optionStack.top();
		if (previousOption->ThisFilter == option->RequiresOption)
		{
			ImGui::Indent();
			nested = true;
			break;
		}
		else if (previousOption->RequiresOption == option->RequiresOption)
		{
			optionStack.pop();
			nested = true;
			break;
		}
		else
		{
			optionStack.pop();
			if (optionStack.size() < 1)
				break;
			ImGui::Unindent();
		}
	}

	optionStack.push(option);

	if (!isRequirementMet)
		ImGui::BeginDisabled();

	std::string radiusName = "Radius";
	if (option->IsToggle())
	{
		if (ImGui::Checkbox(option->szName, &option->Enabled))
			changed = true;
	}
	if (option->IsRadius())
	{
		if (option->IsToggle())
			ImGui::SameLine();
		else
			radiusName = option->szName;

		ImGui::SetNextItemWidth(40);
		if (ImGui::InputFloat(radiusName.c_str(), &option->Radius, 0.0f, 0.0f, "%.0f"))
		{
			if (option->Radius < 0)
				option->Radius = 0;

			if (!option->IsToggle())
				option->Enabled = option->Radius != 0;

			changed = true;
		}
	}

	// Draw a tooltip (?) if this option has requirements from another option list
	MapFilterOption& requirement = GetMapFilterOption(option->RequiresOption);
	if (!nested && requirement.szName != nullptr && requirement.ThisFilter != MapFilter::All)
	{
		ImGui::SameLine();

		mq::imgui::HelpMarker(
			[&](char* buffer, size_t length)
			{
				strcpy_s(buffer, length, "Requires: ");
				if (requirement.IsObject() != option->IsObject())
					strcat_s(buffer, length, requirement.IsObject() ? "Object Filters -> " : "Options -> ");

				strcat_s(buffer, length, requirement.szName);
			}
		);
	}

	if (option->szHelpString)
	{
		ImGui::SameLine();
		ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 0.5f), " - %s", option->szHelpString);
	}

	if (changed && option->IsRegenerateOnChange())
		regenerate = true;
	if (changed)
	{
		if (option->IsRadius())
			WritePrivateProfileFloat("Map Filters", option->szName, option->Radius, INIFileName);
		if (option->IsToggle())
			WritePrivateProfileBool("Map Filters", option->szName, option->Enabled, INIFileName);
		// option->HasColor() managed via "Colors" tab
	}

	if (!isRequirementMet)
		ImGui::EndDisabled();

	ImGui::PopID();

	return regenerate;
}

static void DrawMapSettings_Options()
{
	bool regenerate = false;
	BuildOptionArrays();

	MapFilterOption& allOption = GetMapFilterOption(MapFilter::All);
	if (ImGui::Checkbox("Enable MQ2Map Labels", &allOption.Enabled))
	{
		regenerate = true;
		WritePrivateProfileBool("Map Filters", allOption.szName, allOption.Enabled, INIFileName);
	}

	ImGui::Text("Active Layer: ");
	ImGui::SameLine();
	if (ImGui::RadioButton("Base", &activeLayer, 0))
	{
		regenerate = true;
		WritePrivateProfileInt("Map Filters", "ActiveLayer", activeLayer, INIFileName);
	}
	ImGui::SameLine();
	if (ImGui::RadioButton("1", &activeLayer, 1))
	{
		regenerate = true;
		WritePrivateProfileInt("Map Filters", "ActiveLayer", activeLayer, INIFileName);
	}
	ImGui::SameLine();
	if (ImGui::RadioButton("2", &activeLayer, 2))
	{
		regenerate = true;
		WritePrivateProfileInt("Map Filters", "ActiveLayer", activeLayer, INIFileName);
	}
	ImGui::SameLine();
	if (ImGui::RadioButton("3", &activeLayer, 3))
	{
		regenerate = true;
		WritePrivateProfileInt("Map Filters", "ActiveLayer", activeLayer, INIFileName);
	}

	ImGui::NewLine();

	std::stack<MapFilterOption*> optionStack;

	if (ImGui::CollapsingHeader("Object Filters", ImGuiTreeNodeFlags_DefaultOpen))
	{
		ImGui::Indent();

		for (auto option : mapFilterObjectOptions)
		{
			if (option != nullptr && AddMapFilterOptionAsImGuiSetting(option, optionStack))
				regenerate = true;
		}

		ImGui::Unindent();
	}

	if (ImGui::CollapsingHeader("Options", ImGuiTreeNodeFlags_DefaultOpen))
	{
		ImGui::Indent();

		for (auto option : mapFilterGeneralOptions)
		{
			if (AddMapFilterOptionAsImGuiSetting(option, optionStack))
				regenerate = true;
		}

		ImGui::Unindent();
	}

	if (ImGui::CollapsingHeader("Highlight Settings", ImGuiTreeNodeFlags_DefaultOpen))
	{
		ImGui::Indent();

		if (ImGui::Checkbox("Enable HighLight Pulse", &HighlightPulse))
		{
			WritePrivateProfileBool("Map Filters", "HighPulse", HighlightPulse, INIFileName);
		}

		ImGui::SetNextItemWidth(40);
		if (ImGui::DragInt("Size", &HighlightSIDELEN))
		{
			PulseReset();
			WritePrivateProfileInt("Map Filters", "HighSize", HighlightSIDELEN, INIFileName);
		}
		
		ImGui::Unindent();
	}

	if (ImGui::CollapsingHeader("Map Loc Settings", ImGuiTreeNodeFlags_DefaultOpen))
	{
		ImGui::Indent();

		static float mapLocSize = gDefaultMapLocParams.lineSize;

		ImGui::SetNextItemWidth(40);
		if (ImGui::DragFloat("Line Size (10-200, default: 50)", &mapLocSize, 1.0f, 10, 200, "%.0f", ImGuiSliderFlags_None))
		{
			if (!IsMapLocsStyleOverridden())
			{
				gOverrideMapLocParams.lineSize = mapLocSize;
			}
			gDefaultMapLocParams.lineSize = mapLocSize;
			WritePrivateProfileFloat("MapLoc", "Size", gDefaultMapLocParams.lineSize, INIFileName);
			UpdateDefaultMapLocInstances();
			regenerate = true;
		}

		static float mapLocWidth = gDefaultMapLocParams.width;

		ImGui::SetNextItemWidth(40);
		if (ImGui::DragFloat("Line Width (1-10, default: 10)", &mapLocWidth, 1.0f, 1, 10, "%.0f", ImGuiSliderFlags_None))
		{
			if (!IsMapLocsStyleOverridden())
			{
				gOverrideMapLocParams.width = mapLocWidth;
			}
			gDefaultMapLocParams.width = mapLocWidth;
			WritePrivateProfileFloat("MapLoc", "Width", gDefaultMapLocParams.width, INIFileName);
			UpdateDefaultMapLocInstances();
			regenerate = true;
		}

		static float mapLocRadius = gDefaultMapLocParams.circleRadius;

		ImGui::SetNextItemWidth(40);
		if (ImGui::DragFloat("Radius", &mapLocRadius, 1.0f, 0, 1000, "%.0f", ImGuiSliderFlags_None))
		{
			if (!IsMapLocsStyleOverridden())
			{
				gOverrideMapLocParams.circleRadius = mapLocRadius;
			}
			gDefaultMapLocParams.circleRadius = mapLocRadius;
			WritePrivateProfileFloat("MapLoc", "Radius", gDefaultMapLocParams.circleRadius, INIFileName);
			UpdateDefaultMapLocInstances();
			regenerate = true;
		}

		ImGui::Unindent();
	}

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
			option.Color = MQColor(color);
			option.Color.Alpha = 255;

			WritePrivateProfileInt("Map Filters", fmt::format("{}-Color", option.szName), option.Color.ToRGB(), INIFileName);
			changed = true;
		}

		if (option.Color != option.DefaultColor)
		{
			ImGui::SameLine();
			if (ImGui::Button("Reset"))
			{
				option.Color = option.DefaultColor;

				WritePrivateProfileInt("Map Filters", fmt::format("{}-Color", option.szName), option.Color.ToRGB(), INIFileName);
				changed = true;
			}
		}

		ImGui::PopID();
		ImGui::Separator();

		if (changed && option.IsRegenerateOnChange())
			regenerate = true;
	}

	ImColor highColor = HighlightColor.ToImColor();
	if (ImGui::ColorEdit3("Highlight", &highColor.Value.x))
	{
		HighlightColor = MQColor(highColor);
		HighlightColor.Alpha = 255;

		WritePrivateProfileInt("Map Filters", "High-Color", HighlightColor.ToRGB(), INIFileName);
		regenerate = true;
	}

	ImGui::Separator();

	ImColor mapLocColor = gDefaultMapLocParams.color.ToImColor();
	if (ImGui::ColorEdit3("MapLoc", &mapLocColor.Value.x))
	{
		MQColor updatedColor = MQColor(mapLocColor);
		updatedColor.Alpha = 255;

		if (!IsMapLocsStyleOverridden())
		{
			gOverrideMapLocParams.color = updatedColor;
		}

		gDefaultMapLocParams.color = updatedColor;

		WritePrivateProfileInt("MapLoc", "Red", gDefaultMapLocParams.color.Red, INIFileName);
		WritePrivateProfileInt("MapLoc", "Green", gDefaultMapLocParams.color.Green, INIFileName);
		WritePrivateProfileInt("MapLoc", "Blue", gDefaultMapLocParams.color.Blue, INIFileName);
		UpdateDefaultMapLocInstances();
		regenerate = true;
	}

	ImGui::Separator();

	ImColor radiusColor = gDefaultMapLocParams.circleColor.ToImColor();
	if (ImGui::ColorEdit3("MapLoc Radius", &radiusColor.Value.x))
	{
		MQColor updatedColor = MQColor(radiusColor);
		updatedColor.Alpha = 255;

		if (!IsMapLocsStyleOverridden())
		{
			gOverrideMapLocParams.circleColor = updatedColor;
		}

		gDefaultMapLocParams.circleColor = updatedColor;

		WritePrivateProfileInt("MapLoc", "RadiusRed", gDefaultMapLocParams.circleColor.Red, INIFileName);
		WritePrivateProfileInt("MapLoc", "RadiusGreen", gDefaultMapLocParams.circleColor.Green, INIFileName);
		WritePrivateProfileInt("MapLoc", "RadiusBlue", gDefaultMapLocParams.circleColor.Blue, INIFileName);
		UpdateDefaultMapLocInstances();
		regenerate = true;
	}

	ImGui::Separator();

	if (regenerate)
	{
		MapClear();
		MapGenerate();
	}
}

static bool IsAnyMapLocSelected()
{
	return std::any_of(gMapLocTemplates.begin(), gMapLocTemplates.end(),
		[](auto& maploc) { return maploc->IsSelected(); });
}

static void ResetSelectedMapLocsToDefault()
{
	for (auto& maploc : gMapLocTemplates)
	{
		if (maploc->IsSelected())
		{
			maploc->SetCreatedFromDefaults(true);
			maploc->UpdateFromParams(gDefaultMapLocParams);
		}
	}
}

static void ApplyOverridesToSelected(const MapLocParams& params)
{
	for (auto& maploc : gMapLocTemplates)
	{
		if (maploc->IsSelected())
		{
			maploc->SetCreatedFromDefaults(false);
			maploc->UpdateFromParams(params);
		}
	}
}

static void DrawMapSettings_MapLocs()
{
	bool regenerate = false;

	static MapLocParams editParams;
	static char editLocLabel[256] = "";
	static glm::ivec3 addMapLoc = { 0, 0, 0 };

	//----------------------------------------------------------------------------
	// Maploc table

	ImGui::TextColored(ImVec4(1.0, 1.0, 0, 1.0), "Map Loc List");
	ImGui::Separator();

	if (ImGui::Button("Select All"))
	{
		for (auto& mapLoc : gMapLocTemplates)
		{
			mapLoc->SetSelected(true);
		}
	}
	ImGui::SameLine();
	if (ImGui::Button("Deselect All"))
	{
		for (auto& mapLoc : gMapLocTemplates)
		{
			mapLoc->SetSelected(false);
		}
	}

	if (ImGui::BeginTable("Map Loc Table", 4, ImGuiTableFlags_Resizable | ImGuiTableFlags_NoSavedSettings | ImGuiTableFlags_Borders))
	{
		ImGui::TableSetupColumn("Index", ImGuiTableColumnFlags_WidthFixed, 50);
		ImGui::TableSetupColumn("Loc (y,x,z)", ImGuiTableColumnFlags_WidthFixed, 130);
		ImGui::TableSetupColumn("Label", ImGuiTableColumnFlags_WidthStretch);
		ImGui::TableSetupColumn("Uses Defaults?", ImGuiTableColumnFlags_WidthFixed, 90);
		ImGui::TableHeadersRow();

		for (auto& mapLoc : gMapLocTemplates)
		{
			ImGui::TableNextRow();
			ImGui::TableNextColumn();

			bool selected = mapLoc->IsSelected();
			if (ImGui::Selectable(std::to_string(mapLoc->GetIndex()).c_str(), &selected, ImGuiSelectableFlags_SpanAllColumns))
			{
				mapLoc->SetSelected(selected);
			}

			ImGui::TableNextColumn();
			ImGui::Text("%d, %d, %d", (int)mapLoc->GetPosition().Y, (int)mapLoc->GetPosition().X, (int)mapLoc->GetPosition().Z);

			ImGui::TableNextColumn();
			ImGui::Text("%s", mapLoc->GetLabelText().c_str());

			ImGui::TableNextColumn();
			if (mapLoc->IsCreatedFromDefaults())
				ImGui::Text("Yes");
			else
				ImGui::Text("No");
		}

		ImGui::EndTable();
	}

	bool anySelected = IsAnyMapLocSelected();

	{
		ImGui::BeginDisabled(!anySelected);
		if (ImGui::Button("Delete Selected"))
		{
			DeleteSelectedMapLocs();
		}
		ImGui::EndDisabled();
	}

	{
		ImGui::SameLine();

		ImGui::BeginDisabled(gMapLocTemplates.empty());
		if (ImGui::Button("Clear All Map Locs"))
		{
			ImGui::OpenPopup("Delete?");
		}
		ImGui::EndDisabled();
	}

	{
		ImGui::BeginDisabled(!anySelected);
		if (ImGui::Button("Reset Selected to Defaults"))
		{
			ResetSelectedMapLocsToDefault();
		}
		ImGui::SameLine();
		if (ImGui::Button("Apply Overrides to Selected"))
		{
			ApplyOverridesToSelected(gOverrideMapLocParams);
		}
		ImGui::EndDisabled();
	}

	//----------------------------------------------------------------------------
	// Create new maploc

	ImGui::NewLine();

	ImGui::TextColored(ImVec4(1.0, 1.0, 0, 1.0), "Create New");
	ImGui::Separator();

	ImGui::InputInt3("Pos (YXZ)", &addMapLoc[0], 0);
	ImGui::SameLine();
	if (ImGui::Button("Set Current"))
	{
		if (pControlledPlayer)
		{
			addMapLoc.x = (int)pControlledPlayer->Y;
			addMapLoc.y = (int)pControlledPlayer->X;
			addMapLoc.z = (int)pControlledPlayer->Z;
		}
	}

	ImGui::InputTextWithHint("Map Label", "<optional>", editLocLabel, IM_ARRAYSIZE(editLocLabel));

	//----------------------------------------------------------------------------
	// Add Map Loc / Add Current Target

	if (ImGui::Button("Add Map Loc"))
	{
		fmt::memory_buffer buf;
		fmt::format_to(fmt::appender(buf), "{} {} {}", addMapLoc.x, addMapLoc.y, addMapLoc.z);

		if (IsMapLocsStyleOverridden())
		{
			fmt::format_to(fmt::appender(buf), " {}", gOverrideMapLocParams.MakeCommandString());
		}
		if (editLocLabel[0])
		{
			fmt::format_to(fmt::appender(buf), " label {}", editLocLabel);
		}

		MapSetLocationCmd(nullptr, to_string(buf).c_str());

		// reset after adding
		addMapLoc = {};
		editLocLabel[0] = 0;

		UpdateDefaultMapLocInstances();
	}

	ImGui::SameLine();

	{
		ImGui::BeginDisabled(pTarget == nullptr);

		if (ImGui::Button("Add MapLoc for Target"))
		{
			fmt::memory_buffer membuf; auto buf = fmt::appender(membuf);
			fmt::format_to(buf, "target");

			if (IsMapLocsStyleOverridden())
			{
				fmt::format_to(buf, " {}", gOverrideMapLocParams.MakeCommandString());
			}

			MapSetLocationCmd(nullptr, to_string(membuf).c_str());
		}

		ImGui::EndDisabled();
	}

	//----------------------------------------------------------------------------
	// Overrides collapsing section

	if (ImGui::CollapsingHeader("Map Loc Overrides"))
	{
		ImGui::Indent();

		ImGui::TextWrapped("These options will override the Map Loc Settings defined in the Options Tab for any newly created map locs in this section.");

		{
			ImGui::BeginDisabled(!IsMapLocsStyleOverridden());

			if (ImGui::Button("Reset Overrides to Defaults"))
			{
				ResetMapLocOverrides();
			}

			ImGui::EndDisabled();
		}

		ImGui::SetNextItemWidth(40);
		ImGui::DragFloat(" Line Size (10-200, default: 50)", &gOverrideMapLocParams.lineSize, 1.0f, 10, 200, "%.0f", ImGuiSliderFlags_None);

		ImGui::SetNextItemWidth(40);
		ImGui::DragFloat(" Line Width (1-10, default: 10)", &gOverrideMapLocParams.width, 1.0f, 1, 10, "%.0f", ImGuiSliderFlags_None);

		ImColor mapLocColor = gOverrideMapLocParams.color.ToImColor();
		ImGui::SetNextItemWidth(200);
		if (ImGui::ColorEdit3("MapLoc Override", &mapLocColor.Value.x))
		{
			gOverrideMapLocParams.color = MQColor(mapLocColor);
			gOverrideMapLocParams.color.Alpha = 255;
			regenerate = true;
		}

		ImGui::SetNextItemWidth(40);
		if (ImGui::DragFloat(" Radius", &gOverrideMapLocParams.circleRadius, 1.0f, 0, 1000, "%.0f", ImGuiSliderFlags_None))
		{
			UpdateDefaultMapLocInstances();
		}

		{
			ImGui::BeginDisabled(gOverrideMapLocParams.circleRadius == 0);

			ImGui::SameLine();
			ImColor radiusColor = gOverrideMapLocParams.circleColor.ToImColor();
			ImGui::SetNextItemWidth(200);
			if (ImGui::ColorEdit3("MapLoc Radius Override", &radiusColor.Value.x))
			{
				gOverrideMapLocParams.circleColor = MQColor(radiusColor);
				gOverrideMapLocParams.circleColor.Alpha = 255;
				regenerate = true;
			}

			ImGui::EndDisabled();
		}

		ImGui::Unindent();
	}

	ImVec2 center = ImGui::GetMainViewport()->GetCenter();
	ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
	if (ImGui::BeginPopupModal("Delete?", NULL, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::Text("Are you sure you want to delete all map locs?");
		ImGui::NewLine();
		ImGui::Separator();

		if (ImGui::Button("Yes", ImVec2(120, 0)))
		{
			DeleteAllMapLocs();
			ImGui::CloseCurrentPopup();
		}
		ImGui::SetItemDefaultFocus();
		ImGui::SameLine();
		if (ImGui::Button("Cancel", ImVec2(120, 0)))
		{
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
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
			ImGui::BeginChild("OptionsChild", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y));
			DrawMapSettings_Options();
			ImGui::EndChild();
			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Colors"))
		{
			ImGui::BeginChild("ColorsChild", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y));
			DrawMapSettings_Colors();
			ImGui::EndChild();
			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Map Locs"))
		{
			ImGui::BeginChild("MapLocsChild", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y));
			DrawMapSettings_MapLocs();
			ImGui::EndChild();
			ImGui::EndTabItem();
		}

		ImGui::EndTabBar();
	}
}
