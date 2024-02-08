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

#include <memory>
#include <vector>

PreSetup("MQ2CustomBinds");

const char* BindsFile = "MQ2CustomBinds.txt";

struct CustomBind
{
	std::string name;
	std::string commandDown;
	std::string commandUp;
};

static std::vector<std::unique_ptr<CustomBind>> sCustomBinds;
static bool gbBindsLoaded = false;

static void ExecuteCustomBind(const char* Name, bool Down);
static void LoadCustomBinds();
static void SaveCustomBinds();
static void CustomBindCmd(SPAWNINFO* pChar, char* szLine);

static int FindCustomBind(const char* Name)
{
	for (int index = 0; index < (int)sCustomBinds.size(); ++index)
	{
		if (CustomBind* pBind = sCustomBinds[index].get())
		{
			if (ci_equals(Name, pBind->name))
				return index;
		}
	}

	return -1;
}

static CustomBind* AddCustomBind(
	const std::string& Name,
	const std::string& CommandDown = {},
	const std::string& CommandUp = {})
{
	if (AddMQ2KeyBind(Name.c_str(), ExecuteCustomBind))
	{
		auto pBind = std::make_unique<CustomBind>();
		pBind->name = Name;
		pBind->commandDown = CommandDown;
		pBind->commandUp = CommandUp;

		// Find unused index.
		int index = -1;
		for (int i = 0; i < (int)sCustomBinds.size(); ++i)
		{
			if (sCustomBinds[i] == nullptr)
			{
				index = i;
				break;
			}
		}

		if (index == -1)
		{
			sCustomBinds.emplace_back();
			index = static_cast<int>(sCustomBinds.size()) - 1;
		}

		sCustomBinds[index] = std::move(pBind);
		return sCustomBinds[index].get();
	}

	return nullptr;
}

static void RemoveCustomBind(size_t index)
{
	if (index >= sCustomBinds.size())
		return;

	if (CustomBind* pBind = sCustomBinds[index].get())
	{
		RemoveMQ2KeyBind(pBind->name.c_str());

		sCustomBinds[index].reset();
	}
}

static void LoadCustomBinds()
{
	std::filesystem::path pathCustomBinds = gPathConfig;
	pathCustomBinds /= BindsFile;
	FILE* file = _fsopen(pathCustomBinds.string().c_str(), "rt", _SH_DENYNO);
	if (file == nullptr)
		return;

	char szLine[MAX_STRING];

	std::string name, down, up;

	while (fgets(szLine, 2048, file))
	{
		char* Next_Token1 = nullptr;
		char* Next_Token2 = nullptr;
		char* Cmd = strtok_s(szLine, "\r\n", &Next_Token1);
		char* Cmd2 = strtok_s(Cmd, "=", &Next_Token2);

		if (ci_equals(Cmd2, "name"))
		{
			name = &szLine[5];
		}
		else if (ci_equals(Cmd2, "up"))
		{
			up = &szLine[3];

			AddCustomBind(name, down, up);
			name.clear();
			down.clear();
			up.clear();
		}
		else if (ci_equals(Cmd2, "down"))
		{
			down = &szLine[5];
		}
	}

	fclose(file);
}

static void SaveCustomBinds()
{
	std::filesystem::path pathCustomBinds = gPathConfig;
	pathCustomBinds /= BindsFile;
	FILE* file = _fsopen(pathCustomBinds.string().c_str(), "wt", _SH_DENYWR);
	if (file == nullptr)
		return;

	for (const auto& pBind : sCustomBinds)
	{
		if (pBind)
		{
			fprintf(file, "name=%s\ndown=%s\nup=%s\n", pBind->name.c_str(), pBind->commandDown.c_str(), pBind->commandUp.c_str());
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

	if (CustomBind* pBind = sCustomBinds[N].get())
	{
		if (Down)
		{
			if (!pBind->commandDown.empty())
			{
				DoCommand(pCharInfo->pSpawn, pBind->commandDown.c_str());
			}
		}
		else if (!pBind->commandUp.empty())
		{
			DoCommand(pCharInfo->pSpawn, pBind->commandUp.c_str());
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
	const char* szRest = GetNextArg(szLine, 2);

	if (!_stricmp(szArg, "list"))
	{
		WriteChatColor("Custom binds");
		WriteChatColor("--------------");

		for (const auto& pBind : sCustomBinds)
		{
			if (pBind)
			{
				WriteChatf("[\ay%s\ax] [Down:\at%s\ax] [Up:\at%s\ax]",
					pBind->name.c_str(), pBind->commandDown.c_str(), pBind->commandUp.c_str());
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
			WriteChatColor("Custom bind added. Use /custombind set to set the custom commands.");
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

		const auto& pBind = sCustomBinds[index];
		if (Down)
			pBind->commandDown = szRest;
		else
			pBind->commandUp = szRest;

		WriteChatf("[\ay%s\ax] [Down:\at%s\ax] [Up:\at%s\ax]",
			pBind->name.c_str(), pBind->commandDown.c_str(), pBind->commandUp.c_str());

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

		const auto& pBind = sCustomBinds[index];
		if (Down)
			pBind->commandDown.clear();
		else
			pBind->commandUp.clear();

		WriteChatf("[\ay%s\ax] [Down:\at%s\ax] [Up:\at%s\ax]",
			pBind->name.c_str(), pBind->commandDown.c_str(), pBind->commandUp.c_str());

		SaveCustomBinds();
		return;
	}
}

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

	for (const auto& pBind : sCustomBinds)
	{
		if (pBind)
		{
			RemoveMQ2KeyBind(pBind->name.c_str());
		}
	}
	sCustomBinds.clear();
}

PLUGIN_API void SetGameState(DWORD GameState)
{
	if (GameState == GAMESTATE_INGAME || GameState == GAMESTATE_CHARSELECT)
	{
		if (!gbBindsLoaded)
		{
			LoadCustomBinds();
			gbBindsLoaded = true;
		}
	}
}
