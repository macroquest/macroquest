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

#include "pch.h"
#include "ModuleSystem.h"

#include "MQ2Main.h"

using namespace eqlib;

namespace mq {

static bool s_autoExec = false;
static bool s_charSelect = true;
static bool s_doAutoRun = false;

bool LoadCfgFile(const char* Filename, bool Delayed)
{
	std::filesystem::path pathFilename = Filename;

	// The original search order was: Configs\Filename.cfg, root\Filename.cfg, EQ\Filename.cfg, EQ\Filename
	// The new search order is Config\Autoexec\Filename.cfg then Config\Filename.cfg.
	if (!strchr(Filename, '.'))
		pathFilename = std::string(Filename) + ".cfg";

	std::error_code ec_exists;

	if (pathFilename.is_relative())
	{
		const std::filesystem::path tmpPath = "Autoexec";
		if (std::filesystem::exists(mq::internal_paths::Config / tmpPath / pathFilename, ec_exists))
		{
			pathFilename = mq::internal_paths::Config / tmpPath / pathFilename;
		}
		else if (std::filesystem::exists(mq::internal_paths::Config / pathFilename, ec_exists))
		{
			pathFilename = mq::internal_paths::Config / pathFilename;
		}
	}

	if (std::filesystem::exists(pathFilename, ec_exists))
	{
		FILE* file = _fsopen(pathFilename.string().c_str(), "rt", _SH_DENYNO);
		if (file)
		{
			char szBuffer[MAX_STRING] = { 0 };
			while (fgets(szBuffer, MAX_STRING, file))
			{
				char* Next_Token1 = nullptr;
				char* Cmd = strtok_s(szBuffer, "\r\n", &Next_Token1);
				if (Cmd && Cmd[0] && Cmd[0] != ';')
				{
					DoCommand(Cmd, Delayed);
				}
			}

			fclose(file);
			return true;
		}
	}
	return false;
}

// /loadcfg
void LoadCfgCommand(PlayerClient*, const char* szLine)
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

class MQCfgFileHandler : public MQModule
{
public:
	MQCfgFileHandler() : MQModule("CfgFileHandler")
	{
	}

	virtual void Initialize() override
	{
		AddCommand("/loadcfg", LoadCfgCommand);
	}

	virtual void Shutdown() override
	{
		RemoveCommand("/loadcfg");
	}

	virtual void OnGameStateChanged(int gameState) override
	{
		if (gameState == GAMESTATE_INGAME)
		{
			s_doAutoRun = true;

			if (!s_autoExec)
			{
				s_autoExec = true;
				LoadCfgFile("AutoExec", false);
			}

			if (s_charSelect)
			{
				s_charSelect = false;
				char szBuffer[MAX_STRING] = { 0 };

				LoadCfgFile("InGame", false);

				if (pLocalPC)
				{
					sprintf_s(szBuffer, "%s_%s", GetServerShortName(), pLocalPC->Name);
					LoadCfgFile(szBuffer, false);

					strcpy_s(szBuffer, GetClassDesc(pLocalPC->GetClass()));
					LoadCfgFile(szBuffer, false);
				}
			}
		}
		else if (gameState == GAMESTATE_CHARSELECT)
		{
			if (!s_autoExec)
			{
				s_autoExec = true;
				LoadCfgFile("AutoExec", false);
			}
			s_charSelect = true;
			LoadCfgFile("CharSelect", false);
		}
	}

	virtual void OnProcessFrame() override
	{
		if (s_doAutoRun && pLocalPlayer && pLocalPC)
		{
			s_doAutoRun = false;

			// autorun command for everyone
			std::string autoRun = GetPrivateProfileString("AutoRun", "ALL", "", mq::internal_paths::MQini);
			mq::trim(autoRun);

			if (!autoRun.empty())
				DoCommand(autoRun.c_str(), false);

			// autorun command for toon
			char szServerAndName[128] = {};
			sprintf_s(szServerAndName, "%s.%s", GetServerShortName(), pLocalPC->Name);

			autoRun = GetPrivateProfileString("AutoRun", szServerAndName, "", mq::internal_paths::MQini);
			mq::trim(autoRun);

			if (!autoRun.empty())
				DoCommand(autoRun.c_str(), false);
		}
	}

	virtual void OnPostZoneUI() override
	{
		if (GetGameState() == GAMESTATE_INGAME)
		{
			LoadCfgFile("zoned", true);
			LoadCfgFile(pZoneInfo->ShortName, false);
		}
	}

	virtual void OnModuleLoaded(MQModule* module) override
	{
		if (module->IsPlugin())
		{
			// load cfg file if exists
			std::string autoExec = fmt::format("{}-AutoExec", module->GetName());

			LoadCfgFile(autoExec.c_str(), false);
		}
	}
};

DECLARE_MODULE_FACTORY(MQCfgFileHandler);

} // namespace mq
