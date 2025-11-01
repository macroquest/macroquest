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

 // Cr4zyb4rd patch: 1/7/2005
 // Updated Sep 09 2017 by eqmule to take undeclared macro variables into account

#include <mq/Plugin.h>

#include <mutex>

PreSetup("MQ2HUD");

enum HudType
{
	HUDTYPE_NORMAL     = 0x0001,
	HUDTYPE_FULLSCREEN = 0x0002,
	HUDTYPE_CURSOR     = 0x0004,
	HUDTYPE_CHARSELECT = 0x0008,
	HUDTYPE_MACRO      = 0x0010,
};

struct HUDELEMENT
{
	HudType     Type;
	DWORD       Size;
	int         X;
	int         Y;
	DWORD       Color;
	char        Text[MAX_STRING];
	char        PreParsed[MAX_STRING];

	HUDELEMENT* pNext;
};
HUDELEMENT* pHud = nullptr;

struct _stat LastRead;
char HUDNames[MAX_STRING] = "Elements";
char HUDSection[MAX_STRING] = "MQ2HUD";
int SkipParse = 1;
int CheckINI = 10;
bool bBGUpdate = true;
bool bClassHUD = true;
bool bZoneHUD = true;
bool bUseFontSize = false;
bool bEQHasFocus = true;
std::recursive_mutex s_mutex;

bool Stat(const char* Filename, struct _stat& Dest)
{
	int client = 0;
	errno_t err = _sopen_s(&client, Filename, _O_RDONLY, _SH_DENYNO, _S_IREAD | _S_IWRITE);
	if (err)
		return false;
	_fstat(client, &Dest);
	_close(client);
	return true;
}

void ClearElements()
{
	std::scoped_lock lock(s_mutex);

	while (pHud)
	{
		HUDELEMENT* pNext = pHud->pNext;
		delete pHud;
		pHud = pNext;
	}
}

void AddElement(char* IniString)
{
	std::scoped_lock lock(s_mutex);

	int X = 0;
	int Y = 0;
	int Type = 0;  // FIXME: What is a sane default value for Type?
	ARGBCOLOR Color;
	Color.A = 0xFF;

	// x,y,color,string
	int Size = 0;

	char* pComma = strchr(IniString, ',');
	if (!pComma)
		return;
	*pComma = 0;
	Type = GetIntFromString(IniString, Type);
	IniString = &pComma[1];

	if (bUseFontSize)
	{
		pComma = strchr(IniString, ',');
		if (!pComma)
			return;
		*pComma = 0;
		Size = GetIntFromString(IniString, Size);
		IniString = &pComma[1];
	}
	else
	{
		Size = 2;
	}

	pComma = strchr(IniString, ',');
	if (!pComma)
		return;
	*pComma = 0;
	X = GetIntFromString(IniString, X);
	IniString = &pComma[1];

	// y
	pComma = strchr(IniString, ',');
	if (!pComma)
		return;
	*pComma = 0;
	Y = GetIntFromString(IniString, Y);
	IniString = &pComma[1];

	// color R
	pComma = strchr(IniString, ',');
	if (!pComma)
		return;
	*pComma = 0;
	Color.R = GetIntFromString(IniString, 0);
	IniString = &pComma[1];

	// color G
	pComma = strchr(IniString, ',');
	if (!pComma)
		return;
	*pComma = 0;
	Color.G = GetIntFromString(IniString, 0);
	IniString = &pComma[1];

	// color B
	pComma = strchr(IniString, ',');
	if (!pComma)
		return;
	*pComma = 0;
	Color.B = GetIntFromString(IniString, 0);
	IniString = &pComma[1];

	// string
	if (!IniString[0])
		return;

	HUDELEMENT* pElement = new HUDELEMENT;
	pElement->pNext = pHud;
	pHud = pElement;
	pElement->Type = static_cast<HudType>(Type);
	pElement->Color = Color.ARGB;
	pElement->X = X;
	pElement->Y = Y;
	strcpy_s(pElement->Text, IniString);
	ZeroMemory(pElement->PreParsed, sizeof(pElement->PreParsed));
	pElement->Size = Size;

	DebugSpew("New element '%s' in color %X", pElement->Text, pElement->Color);
}

void LoadElements()
{
	ClearElements();

	std::scoped_lock lock(s_mutex);

	char ElementList[MAX_STRING * 10] = { 0 };
	char szBuffer[MAX_STRING] = { 0 };
	char CurrentHUD[MAX_STRING] = { 0 };
	char ClassDesc[MAX_STRING] = { 0 };
	char ZoneName[MAX_STRING] = { 0 };
	int argn = 1;

	GetArg(CurrentHUD, HUDNames, argn, 0, 0, 0, ',');
	while (*CurrentHUD)
	{
		GetPrivateProfileString(CurrentHUD, nullptr, "", ElementList, MAX_STRING * 10, INIFileName);
		char* pElementList = ElementList;
		while (pElementList[0] != 0) {
			GetPrivateProfileString(CurrentHUD, pElementList, "", szBuffer, MAX_STRING, INIFileName);
			if (szBuffer[0] != 0) {
				AddElement(szBuffer);
			}
			pElementList += strlen(pElementList) + 1;
		}
		GetArg(CurrentHUD, HUDNames, ++argn, 0, 0, 0, ',');
	}

	if (gGameState == GAMESTATE_INGAME)
	{
		if (bClassHUD)
		{
			if (PcProfile* pProfile = GetPcProfile())
			{
				strcpy_s(ClassDesc, GetClassDesc(pProfile->Class));
				GetPrivateProfileString(ClassDesc, nullptr, "", ElementList, MAX_STRING * 10, INIFileName);

				char* pElementList = ElementList;
				while (pElementList[0] != 0)
				{
					GetPrivateProfileString(ClassDesc, pElementList, "", szBuffer, MAX_STRING, INIFileName);

					if (szBuffer[0] != 0)
					{
						AddElement(szBuffer);
					}

					pElementList += strlen(pElementList) + 1;
				}
			}
		}

		if (bZoneHUD)
		{
			strcpy_s(ZoneName, pZoneInfo->LongName);
			GetPrivateProfileString(ZoneName, nullptr, "", ElementList, MAX_STRING * 10, INIFileName);

			char* pElementList = ElementList;
			while (pElementList[0] != 0)
			{
				GetPrivateProfileString(ZoneName, pElementList, "", szBuffer, MAX_STRING, INIFileName);

				if (szBuffer[0] != 0)
				{
					AddElement(szBuffer);
				}

				pElementList += strlen(pElementList) + 1;
			}
		}
	}

	if (!Stat(INIFileName, LastRead))
	{
		ZeroMemory(&LastRead, sizeof(struct _stat));
	}
}

void HandleINI()
{
	std::scoped_lock lock(s_mutex);

	char szBuffer[MAX_STRING] = { 0 };
	WritePrivateProfileString(HUDSection, "Last", HUDNames, INIFileName);

	SkipParse = GetPrivateProfileInt(HUDSection, "SkipParse", 1, INIFileName);
	SkipParse = SkipParse < 1 ? 1 : SkipParse;

	CheckINI = GetPrivateProfileInt(HUDSection, "CheckINI", 10, INIFileName);
	CheckINI = CheckINI < 10 ? 10 : CheckINI;

	GetPrivateProfileString(HUDSection, "UpdateInBackground", "on", szBuffer, MAX_STRING, INIFileName);
	bBGUpdate = _strnicmp(szBuffer, "on", 2) ? false : true;

	GetPrivateProfileString(HUDSection, "ClassHUD", "on", szBuffer, MAX_STRING, INIFileName);
	bClassHUD = _strnicmp(szBuffer, "on", 2) ? false : true;

	GetPrivateProfileString(HUDSection, "ZoneHUD", "on", szBuffer, MAX_STRING, INIFileName);
	bZoneHUD = _strnicmp(szBuffer, "on", 2) ? false : true;

	GetPrivateProfileString("MQ2HUD", "UseFontSize", "off", szBuffer, MAX_STRING, INIFileName);
	bUseFontSize = _strnicmp(szBuffer, "on", 2) ? false : true;

	// Write the SkipParse and CheckINI section, in case they didn't have one
	WritePrivateProfileString(HUDSection, "SkipParse", std::to_string(SkipParse), INIFileName);
	WritePrivateProfileString(HUDSection, "CheckINI", std::to_string(CheckINI), INIFileName);
	WritePrivateProfileString(HUDSection, "UpdateInBackground", bBGUpdate ? "on" : "off", INIFileName);
	WritePrivateProfileString(HUDSection, "ClassHUD", bClassHUD ? "on" : "off", INIFileName);
	WritePrivateProfileString(HUDSection, "ZoneHUD", bZoneHUD ? "on" : "off", INIFileName);
	WritePrivateProfileString("MQ2HUD", "UseFontSize", bUseFontSize ? "on" : "off", INIFileName);

	LoadElements();
}

void DefaultHUD(SPAWNINFO* pChar, char* szLine)
{
	strcpy_s(HUDNames, "Elements");
	HandleINI();
}

void LoadHUD(SPAWNINFO* pChar, char* szLine)
{
	char HUDTemp[MAX_STRING] = { 0 };
	char CurrentHUD[MAX_STRING];
	int argn = 1;
	GetArg(CurrentHUD, HUDNames, argn, 0, 0, 0, ',');

	while (*CurrentHUD)
	{
		if (!strcmp(CurrentHUD, szLine))
		{
			WriteChatf("Hud \"%s\" already loaded", szLine);
			return;
		}

		if (HUDTemp[0]) strcat_s(HUDTemp, ",");
		strcat_s(HUDTemp, CurrentHUD);
		GetArg(CurrentHUD, HUDNames, ++argn, 0, 0, 0, ',');
	}

	if (HUDTemp[0]) strcat_s(HUDTemp, ",");
	strcat_s(HUDTemp, szLine);
	strcpy_s(HUDNames, HUDTemp);

	HandleINI();
}

void UnLoadHUD(SPAWNINFO* pChar, char* szLine)
{
	char HUDTemp[MAX_STRING] = { 0 };
	char CurrentHUD[MAX_STRING];
	bool found = false;
	int argn = 1;

	GetArg(CurrentHUD, HUDNames, argn, 0, 0, 0, ',');
	while (*CurrentHUD)
	{
		if (!strcmp(CurrentHUD, szLine))
		{
			found = true;
		}
		else
		{
			if (HUDTemp[0]) strcat_s(HUDTemp, ",");
			strcat_s(HUDTemp, CurrentHUD);
		}

		GetArg(CurrentHUD, HUDNames, ++argn, 0, 0, 0, ',');
	}

	strcpy_s(HUDNames, HUDTemp);

	if (!found) WriteChatf("Hud \"%s\" not loaded", szLine);

	HandleINI();
}

void BackgroundHUD(SPAWNINFO* pChar, char* szLine)
{
	if (!_stricmp(szLine, "off"))
	{
		WritePrivateProfileString(HUDSection, "UpdateInBackground", "off", INIFileName);
		WriteChatColor("MQ2HUD::Background updates are OFF");
	}
	else if (!_stricmp(szLine, "on"))
	{
		WritePrivateProfileString(HUDSection, "UpdateInBackground", "on", INIFileName);
		WriteChatColor("MQ2HUD::Background updates are ON");
	}
	else
	{
		WriteChatColor("Usage: /backgroundhud [on|off]");
		return;
	}

	HandleINI();
}

void ClassHUD(SPAWNINFO* pChar, char* szLine)
{
	if (!_stricmp(szLine, "off"))
	{
		WritePrivateProfileString(HUDSection, "ClassHUD", "off", INIFileName);
		WriteChatColor("MQ2HUD::Auto-include HUD per class description is OFF");
	}
	else if (!_stricmp(szLine, "on"))
	{
		WritePrivateProfileString(HUDSection, "ClassHUD", "on", INIFileName);
		WriteChatColor("MQ2HUD::Auto-include HUD per class description is ON");
	}
	else
	{
		WriteChatColor("Usage: /classhud [on|off]");
		return;
	}

	HandleINI();
}

void ZoneHUD(SPAWNINFO* pChar, char* szLine)
{
	if (!_stricmp(szLine, "off"))
	{
		WritePrivateProfileString(HUDSection, "ZoneHUD", "off", INIFileName);
		WriteChatColor("MQ2HUD::Auto-include HUD per zone name is OFF");
	}
	else if (!_stricmp(szLine, "on"))
	{
		WritePrivateProfileString(HUDSection, "ZoneHUD", "on", INIFileName);
		WriteChatColor("MQ2HUD::Auto-include HUD per zone name is ON");
	}
	else
	{
		WriteChatColor("Usage: /zonehud [on|off]");
		return;
	}

	HandleINI();
}

bool dataHUD(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Ptr = HUDNames;
	Ret.Type = datatypes::pStringType;
	return true;
}

PLUGIN_API void InitializePlugin()
{
	GetPrivateProfileString(HUDSection, "Last", "Elements", HUDNames, MAX_STRING, INIFileName);
	HandleINI();

	AddCommand("/defaulthud", DefaultHUD);
	AddCommand("/loadhud", LoadHUD);
	AddCommand("/unloadhud", UnLoadHUD);
	AddCommand("/backgroundhud", BackgroundHUD);
	AddCommand("/classhud", ClassHUD);
	AddCommand("/zonehud", ZoneHUD);
	AddMQ2Data("HUD", dataHUD);
}

PLUGIN_API void ShutdownPlugin()
{
	ClearElements();

	RemoveCommand("/loadhud");
	RemoveCommand("/unloadhud");
	RemoveCommand("/defaulthud");
	RemoveCommand("/backgroundhud");
	RemoveCommand("/classhud");
	RemoveCommand("/zonehud");
	RemoveMQ2Data("HUD");
}

PLUGIN_API void SetGameState(DWORD GameState)
{
	if (GameState == GAMESTATE_INGAME)
		sprintf_s(HUDSection, "%s_%s", pLocalPC->Name, GetServerShortName());
	else
		strcpy_s(HUDSection, "MQ2HUD");
	GetPrivateProfileString(HUDSection, "Last", "Elements", HUDNames, MAX_STRING, INIFileName);
	HandleINI();
}

// Called after entering a new zone
PLUGIN_API void OnZoned()
{
	if (bZoneHUD) HandleINI();
}

bool ParseMacroLine(char* szOriginal, size_t BufferSize, std::vector<std::string>& out)
{
	// find each {}
	char* pBrace = strstr(szOriginal, "${");
	if (!pBrace)
		return false;

	size_t NewLength = 0;
	bool Changed = false;
	char szCurrent[MAX_STRING] = { 0 };

	do
	{
		// find this brace's end
		char* pEnd = &pBrace[1];
		bool Quote = false;
		bool BeginParam = false;
		int nBrace = 1;

		while (nBrace)
		{
			++pEnd;
			if (BeginParam)
			{
				BeginParam = false;
				if (*pEnd == '\"')
				{
					Quote = true;
				}
				continue;
			}

			if (*pEnd == 0)
			{
				// unmatched brace or quote
				continue;
			}

			if (Quote)
			{
				if (*pEnd == '\"')
				{
					if (pEnd[1] == ']' || pEnd[1] == ',')
					{
						Quote = false;
					}
				}
			}
			else
			{
				if (*pEnd == '}')
				{
					nBrace--;
				}
				else if (*pEnd == '{')
				{
					nBrace++;
				}
				else if (*pEnd == '[' || *pEnd == ',')
					BeginParam = true;
			}
		}

		*pEnd = 0;
		strcpy_s(szCurrent, &pBrace[2]);
		if (szCurrent[0] == 0)
		{
			continue;
		}

		if (ParseMacroLine(szCurrent, sizeof(szCurrent), out))
		{
			size_t NewLength = strlen(szCurrent);
			memmove(&pBrace[NewLength + 1], &pEnd[1], strlen(&pEnd[1]) + 1);

			int addrlen = (int)(pBrace - szOriginal);
			memcpy_s(pBrace, BufferSize - addrlen, szCurrent, NewLength);

			pEnd = &pBrace[NewLength];
			*pEnd = 0;
		}

		if (!strchr(szCurrent, '[') && !strchr(szCurrent, '.'))
			out.emplace_back(szCurrent);

		NewLength = strlen(szCurrent);
		memmove(&pBrace[NewLength], &pEnd[1], strlen(&pEnd[1]) + 1);

		int addrlen = (int)(pBrace - szOriginal);
		memcpy_s(pBrace, BufferSize - addrlen, szCurrent, NewLength);

		if (!bAllowCommandParse)
		{
			bAllowCommandParse = true;
			Changed = false;
			break;
		}
		else
		{
			Changed = true;
		}
	} while (pBrace = strstr(&pBrace[1], "${"));

	if (Changed)
	{
		while (ParseMacroLine(szOriginal, BufferSize, out))
			;
	}

	return Changed;
}

// Called every frame that the "HUD" is drawn -- e.g. net status / packet loss bar
PLUGIN_API void OnDrawHUD()
{
	std::scoped_lock lock(s_mutex);

	static bool bOkToCheck = true;
	static int FrameCount = 0;
	char szBuffer[MAX_STRING] = { 0 };

	if (++FrameCount > CheckINI)
	{
		FrameCount = 0;

		struct _stat now;
		if (Stat(INIFileName, now) && now.st_mtime != LastRead.st_mtime)
			LoadElements();

		// check for EQ in foreground
		if (!bBGUpdate && !gbInForeground)
			bEQHasFocus = false;
		else
			bEQHasFocus = true;
	}
	if (!bEQHasFocus) return;

	DWORD SX = 0;
	DWORD SY = 0;
	if (pScreenX && pScreenY)
	{
		SX = ScreenX;
		SY = ScreenY;
	}

	HUDELEMENT* pElement = pHud;
	bool bCheckParse = !(FrameCount % SkipParse);

	DWORD X, Y;
	while (pElement)
	{
		if ((gGameState == GAMESTATE_CHARSELECT && pElement->Type & HUDTYPE_CHARSELECT)
			|| (gGameState == GAMESTATE_INGAME && (
			(pElement->Type & HUDTYPE_NORMAL && ScreenMode != 3)
				|| (pElement->Type & HUDTYPE_FULLSCREEN && ScreenMode == 3))))
		{
			if (pElement->Type & HUDTYPE_CURSOR)
			{
				X = EQADDR_MOUSE->X + pElement->X;
				Y = EQADDR_MOUSE->Y + pElement->Y;
			}
			else
			{
				X = SX + pElement->X;
				Y = SX + pElement->Y;
			}

			if (bCheckParse)
			{
				bOkToCheck = true;
				strcpy_s(pElement->PreParsed, pElement->Text);

				if (pElement->Type & HUDTYPE_MACRO)
				{
					if (gRunning)
					{
						char szTemp[MAX_STRING] = { 0 };
						strcpy_s(szTemp, pElement->Text);

						std::vector<std::string> out;
						ParseMacroLine(szTemp, MAX_STRING, out);

						for (const std::string& line : out)
						{
							bOkToCheck = false;
							const char* pChar = line.c_str();

							if (FindTopLevelObject(pChar))
							{
								bOkToCheck = true;
								continue;
							}

							if (!bOkToCheck)
							{
								// ok fine we didn't find it in the tlo map...
								// lets check variables
								if (IsMacroVariable(pChar))
								{
									bOkToCheck = true;
									continue;
								}
							}

							if (!bOkToCheck)
							{
								// still not found...
								break;
							}
						}
					}
				}

				if (bOkToCheck)
				{
					ParseMacroParameter(pElement->PreParsed);
				}
				else
				{
					pElement->PreParsed[0] = '\0';
				}
			}

			strcpy_s(szBuffer, pElement->PreParsed);
			if (szBuffer[0] && strcmp(szBuffer, "nullptr"))
			{
				DrawHUDText(szBuffer, X, Y, pElement->Color, pElement->Size);
			}
		}

		pElement = pElement->pNext;
	}
}
