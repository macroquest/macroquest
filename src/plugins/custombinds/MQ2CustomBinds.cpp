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

PreSetup("MQ2CustomBinds");

const char* BindsFile = "MQ2CustomBinds.txt";

struct CustomBind
{
	char Name[32];
	char CommandDown[MAX_STRING];
	char CommandUp[MAX_STRING];
};

static CIndex<CustomBind*> s_customBinds(10);

static void ExecuteCustomBind(const char* Name, bool Down);

static int FindCustomBind(const char* Name)
{
	for (unsigned long index = 0; index < s_customBinds.GetSize(); index++)
	{
		if (CustomBind* pBind = s_customBinds[index])
		{
			if (!_stricmp(Name, pBind->Name))
				return index;
		}
	}

	return -1;
}

static CustomBind* AddCustomBind(const char* Name, const char* CommandDown = nullptr, const char* CommandUp = nullptr)
{
	if (AddMQ2KeyBind(Name, ExecuteCustomBind))
	{
		CustomBind* pBind = new CustomBind;
		ZeroMemory(pBind, sizeof(CustomBind));

		strcpy_s(pBind->Name, Name);
		if (CommandDown)
			strcpy_s(pBind->CommandDown, CommandDown);
		if (CommandUp)
			strcpy_s(pBind->CommandUp, CommandUp);
		s_customBinds += pBind;

		return pBind;
	}

	return nullptr;
}

static void RemoveCustomBind(unsigned long index)
{
	if (index >= s_customBinds.GetSize())
		return;

	if (CustomBind* pBind = s_customBinds[index])
	{
		RemoveMQ2KeyBind(pBind->Name);
		delete pBind;

		s_customBinds[index] = nullptr;
	}
}

static void LoadCustomBinds();
static void SaveCustomBinds();

void CustomBindCmd(SPAWNINFO* pChar, char* szLine);

// Called once, when the plugin is to initialize
PLUGIN_API void InitializePlugin()
{
	DebugSpewAlways("Initializing MQ2CustomBinds");

	AddCommand("/custombind", CustomBindCmd, false, true, false);
}

// Called once, when the plugin is to shutdown
PLUGIN_API void ShutdownPlugin()
{
	DebugSpewAlways("Shutting down MQ2CustomBinds");
	RemoveCommand("/custombind");
	//SaveCustomBinds();

	for (unsigned long index = 0; index < s_customBinds.GetSize(); index++)
	{
		if (CustomBind* pBind = s_customBinds[index])
		{
			RemoveMQ2KeyBind(pBind->Name);
		}
	}

	s_customBinds.Cleanup();
}

PLUGIN_API void SetGameState(DWORD GameState)
{
	static bool BindsLoaded = false;

	if (GameState == GAMESTATE_INGAME || GameState == GAMESTATE_CHARSELECT)
	{
		if (!BindsLoaded)
		{
			LoadCustomBinds();
			BindsLoaded = true;
		}
	}
}

static void LoadCustomBinds()
{
	std::filesystem::path pathCustomBinds = gPathConfig;
	pathCustomBinds /= BindsFile;
	FILE* file = nullptr;
	errno_t err = fopen_s(&file, pathCustomBinds.string().c_str(), "rt");
	if (err)
		return;

	CustomBind NewBind;
	ZeroMemory(&NewBind, sizeof(CustomBind));

	char szLine[MAX_STRING];

	while (fgets(szLine, 2048, file))
	{
		char* Next_Token1 = nullptr;
		char* Next_Token2 = nullptr;
		char* Cmd = strtok_s(szLine, "\r\n", &Next_Token1);
		char* Cmd2 = strtok_s(Cmd, "=", &Next_Token2);

		if (!_stricmp(Cmd2, "name"))
		{
			ZeroMemory(&NewBind, sizeof(CustomBind));
			strcpy_s(NewBind.Name, &szLine[5]);
		}
		else if (!_stricmp(Cmd2, "up"))
		{
			strcpy_s(NewBind.CommandUp, &szLine[3]);
			AddCustomBind(NewBind.Name, NewBind.CommandDown, NewBind.CommandUp);
		}
		else if (!_stricmp(Cmd2, "down"))
		{
			strcpy_s(NewBind.CommandDown, &szLine[5]);
		}
	}

	fclose(file);
}

static void SaveCustomBinds()
{
	std::filesystem::path pathCustomBinds = gPathConfig;
	pathCustomBinds /= BindsFile;
	FILE* file = nullptr;
	errno_t err = fopen_s(&file, pathCustomBinds.string().c_str(), "wt");
	if (err)
		return;

	for (unsigned long index = 0; index < s_customBinds.GetSize(); index++)
	{
		if (CustomBind* pBind = s_customBinds[index])
		{
			fprintf(file, "name=%s\ndown=%s\nup=%s\n", pBind->Name, pBind->CommandDown, pBind->CommandUp);
		}
	}

	fclose(file);
}

void ExecuteCustomBind(const char* Name, bool Down)
{
	int N = FindCustomBind(Name);
	if (N < 0)
		return;

	CHARINFO* pCharInfo = GetCharInfo();
	if (!pCharInfo)
		return;

	if (CustomBind* pBind = s_customBinds[N])
	{
		if (Down)
		{
			if (pBind->CommandDown[0])
			{
				DoCommand(pCharInfo->pSpawn, pBind->CommandDown);
			}
		}
		else if (pBind->CommandUp[0])
		{
			DoCommand(pCharInfo->pSpawn, pBind->CommandUp);
		}
	}
}

void CustomBindCmd(SPAWNINFO* pChar, char* szLine)
{
	if (szLine[0] == 0)
	{
		SyntaxError("Usage: /custombind <list|add <name>|delete <name>|clear <name><-down|-up>|set <name><-down|-up> <command>>");
		return;
	}

	char szArg[MAX_STRING] = { 0 };
	char szArg2[MAX_STRING] = { 0 };
	GetArg(szArg, szLine, 1);
	GetArg(szArg2, szLine, 2);
	char* szRest = GetNextArg(szLine, 2);

	if (!_stricmp(szArg, "list"))
	{
		WriteChatColor("Custom binds");
		WriteChatColor("--------------");

		for (unsigned long index = 0; index < s_customBinds.GetSize(); index++)
		{
			if (CustomBind* pBind = s_customBinds[index])
			{
				WriteChatf("[\ay%s\ax] [Down:\at%s\ax] [Up:\at%s\ax]", pBind->Name, pBind->CommandDown, pBind->CommandUp);
			}
		}

		WriteChatColor("--------------");
		WriteChatColor("End custom binds");
		return;
	}

	if (!_stricmp(szArg, "add"))
	{
		if (strchr(szArg2, '-'))
		{
			WriteChatColor("'-' is not allowed in a custom bind name");
		}

		if (CustomBind* pBind = AddCustomBind(szArg2))
		{
			WriteChatColor("Custom bind added.  Use /custombind set to set the custom commands.");
		}
		else
		{
			WriteChatColor("Failed to add custom bind (name in use)");
		}

		return;
	}

	if (!_stricmp(szArg, "delete"))
	{
		int index = FindCustomBind(szArg2);
		if (index >= 0)
		{
			RemoveCustomBind(index);
			WriteChatColor("Custom bind deleted");
		}
		else
		{
			WriteChatColor("Could not find custom bind with that name to delete");
		}

		return;
	}

	if (!_stricmp(szArg, "set"))
	{
		bool Down = true;
		if (char* minus = strchr(szArg2, '-'))
		{
			minus[0] = 0;
			if (!_stricmp(&minus[1], "up"))
				Down = false;
		}

		int index = FindCustomBind(szArg2);
		if (index < 0)
		{
			WriteChatf("Could not find custom bind '%s'", szArg2);
			return;
		}

		CustomBind* pBind = s_customBinds[index];
		if (Down)
			strcpy_s(pBind->CommandDown, szRest);
		else
			strcpy_s(pBind->CommandUp, szRest);

		WriteChatf("[\ay%s\ax] [Down:\at%s\ax] [Up:\at%s\ax]", pBind->Name, pBind->CommandDown, pBind->CommandUp);

		SaveCustomBinds();
		return;
	}

	if (!_stricmp(szArg, "clear"))
	{
		bool Down = true;
		if (char* minus = strchr(szArg2, '-'))
		{
			minus[0] = 0;
			if (!_stricmp(&minus[1], "up"))
				Down = false;
		}

		int index = FindCustomBind(szArg2);
		if (index < 0)
		{
			WriteChatf("Could not find custom bind '%s'", szArg2);
			return;
		}

		CustomBind* pBind = s_customBinds[index];
		if (Down)
			pBind->CommandDown[0] = 0;
		else
			pBind->CommandUp[0] = 0;

		WriteChatf("[\ay%s\ax] [Down:\at%s\ax] [Up:\at%s\ax]", pBind->Name, pBind->CommandDown, pBind->CommandUp);
		SaveCustomBinds();

		return;
	}
}
