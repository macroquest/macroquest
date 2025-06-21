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
#include "MQ2Main.h"

#include "CrashHandler.h"
#include "MQCommandAPI.h"

#include "mq/base/ScopeExit.h"

// FIXME
#include "MacroSystem.h"
#include "MQDataAPI.h"

using namespace eqlib;

namespace mq {

struct MQTimedCommand
{
	uint64_t         time;
	std::string      command;
	MQPluginHandle   pluginHandle;

	MQTimedCommand*  pLast;
	MQTimedCommand*  pNext;
};

struct MQCommand
{
	std::string      command;
	MQCommandHandler handler;
	MQPluginHandle   pluginHandle;
	bool             eq;
	bool             parse;
	bool             inGameOnly;

	MQCommand*       pLast = nullptr;
	MQCommand*       pNext = nullptr;
};

MQCommandAPI* pCommandAPI = nullptr;

class CEverQuest_CommandHook
{
public:
	DETOUR_TRAMPOLINE_DEF(void, InterpretCmd_Trampoline, (PlayerClient* pChar, const char* szFullLine))
	void InterpretCmd_Detour(PlayerClient* pChar, const char* szFullLine)
	{
		SPDLOG_DEBUG("CCommandHook::Detour(%s)", szFullLine);

		auto eqHandler = [this](eqlib::PlayerClient* pChar_, const char* szFullLine_) { InterpretCmd_Trampoline(pChar_, szFullLine_); };

		if (pCommandAPI->InterpretCmd(szFullLine, eqHandler))
		{
			return;
		}

		InterpretCmd_Trampoline(pChar, szFullLine);
	}
};

//============================================================================

// TODO: module priority on this has it load early, but we used to pulse it late.
//       re-evaluate if this is a problem because now we pulse it at start of frame instead
//       of end.

DECLARE_MODULE_FACTORY(MQCommandAPI);

MQCommandAPI::MQCommandAPI()
	: MQModule("Commands", static_cast<int>(ModulePriority::Commands))
{
	pCommandAPI = this;
}

MQCommandAPI::~MQCommandAPI()
{
	pCommandAPI = nullptr;
}

void MQCommandAPI::Initialize()
{
	SPDLOG_TRACE("Initializing Commands");

	EzDetour(CEverQuest__InterpretCmd, &CEverQuest_CommandHook::InterpretCmd_Detour, &CEverQuest_CommandHook::InterpretCmd_Trampoline);

	// Import EQ commands
	CMDLIST* pCmdListOrig = EQADDR_CMDLIST;

	struct ExistingCommand {
		const char* cmd;
		fEQCommand& ptr;
	};
	static const std::unordered_map<std::string_view, fEQCommand*> s_builtInCmds = {
#if HAS_ADVANCED_LOOT
		{ "/advloot",           &cmdAdvLoot },
#endif
		{ "/assist",            &cmdAssist },
		{ "/cast",              &cmdCast },
		{ "/charinfo",          &cmdCharInfo },
		{ "/doability",         &cmdDoAbility },
		{ "/filter",            &cmdFilter },
		{ "/help",              &cmdHelp },
		{ "/hotbutton",         &cmdHotbutton },
		{ "/location",          &cmdLocation },
		{ "/mercswitch",        &cmdMercSwitch },
		{ "/pet",               &cmdPet },
		{ "/pickzone",          &cmdPickZone },
		{ "/quit",              &cmdQuit },
		{ "/target",            &cmdTarget },
		{ "/taskquit",          &cmdTaskQuit },
		{ "/useitem",           &cmdUseItem },
		{ "/who",               &cmdWho },
		{ "/whotarget",         &cmdWhoTarget },
	};

	for (int i = 0; pCmdListOrig[i].fAddress != nullptr; ++i)
	{
		auto iter = s_builtInCmds.find(pCmdListOrig[i].szName);
		if (iter != s_builtInCmds.end())
		{
			*iter->second = pCmdListOrig[i].fAddress;
		}

		AddCommand(pCmdListOrig[i].szName, pCmdListOrig[i].fAddress, true, true, true);
	}

	if (cmdWho)
	{
		// make sure / does EQ who by default
		AddCommand("/", cmdWho, true, true, true);
	}

	if (cmdTarget)
	{
		// Allow a method of using the original eq command since we've overloaded target
		AddCommand("/eqtarget", cmdTarget, false, true, true);
	}

	// Add MQ commands...
	struct { const char* szCommand; MQCommandHandler pFunc; bool Parse; bool InGame; } NewCommands[] = {
		{ "/aa",                AltAbility,                 true,  true  },
#if HAS_ADVANCED_LOOT
		{ "/advloot",           AdvLootCmd,                 true,  true  },
#endif
		{ "/alert",             Alert,                      true,  true  },
		{ "/altkey",            DoAltCmd,                   false, false },
		{ "/assist",            AssistCmd,                  true,  true  },
		{ "/banklist",          BankList,                   true,  true  },
		{ "/buyitem",           BuyItem,                    true,  true  },
		{ "/cast",              Cast,                       true,  true  },
		{ "/cecho",             EchoClean,                  true,  false },
		{ "/char",              CharInfo,                   true,  true  },
		{ "/cleanup",           Cleanup,                    true,  false },
		{ "/click",             Click,                      true,  false },
		{ "/combine",           CombineCmd,                 true,  true  },
#if HAS_ITEM_CONVERT_BUTTON
		{ "/convertitem",       ConvertItemCmd,             true,  true  },
#endif
		{ "/ctrlkey",           DoCtrlCmd,                  false, false },
		{ "/delay",             DelayCommand,               false, false },
		{ "/destroy",           EQDestroyHeldItemOrMoney,   true,  true  },
		{ "/doability",         DoAbility,                  true,  true  },
		{ "/doors",             Doors,                      true,  true  },
		{ "/doortarget",        DoorTarget,                 true,  true  },
		{ "/dosocial",          DoSocial,                   true,  true  },
		{ "/drop",              DropCmd,                    true,  true  },
		{ "/echo",              Echo,                       true,  false },
		{ "/exec",              Exec,                       true,  false },
		{ "/executelink",       ExecuteLinkCommand,         true,  true  },
		{ "/face",              Face,                       true,  true  },
		{ "/filter",            Filter,                     true,  false },
		{ "/getwintitle",       GetWinTitle,                true,  false },
		{ "/hotbutton",         DoHotButton,                true,  true  },
		{ "/identify",          Identify,                   true,  true  },
		{ "/ini",               IniOutput,                  true,  false },
		{ "/insertaug",         InsertAugCmd,               true,  true  },
		{ "/items",             Items,                      true,  true  },
		{ "/itemtarget",        ItemTarget,                 true,  true  },
		{ "/keypress",          DoMappable,                 true,  false },
		{ "/loadspells",        LoadSpells,                 true,  true  },
		{ "/location",          Location,                   true,  true  },
		{ "/loginname",         DisplayLoginName,           true,  false },
		{ "/look",              Look,                       true,  true  },
		{ "/lootall",           LootAll,                    true,  false },
		{ "/makemevisible",     MakeMeVisible,              false, true  },
		{ "/memspell",          MemSpell,                   true,  true  },
		{ "/mercswitch",        MercSwitchCmd,              true,  true  },
		{ "/mouseto",           MouseTo,                    true,  false },
		{ "/mqcopylayout",      MQCopyLayout,               true,  false },
		{ "/mqlistmodules",     ListModulesCommand,         false, false },
		{ "/mqlistprocesses",   ListProcessesCommand,       false, false },
		{ "/mqlog",             MacroLogCommand,            true,  false },
		{ "/mqtarget",          Target,                     true,  true  },
		{ "/msgbox",            MQMsgBox,                   true,  false },
		{ "/multiline",         MultilineCommand,           false, false },
		{ "/nomodkey",          NoModKeyCmd,                false, false },
		{ "/pet",               PetCmd,                     true,  true  },
		{ "/pickzone",          PickZoneCmd,                true,  true  },
		{ "/popcustom",         PopupTextCustom,            true,  true  },
		{ "/popup",             PopupText,                  true,  true  },
		{ "/popupecho",         PopupTextEcho,              true,  true  },
		{ "/quit",              QuitCmd,                    true,  false },
		{ "/ranged",            RangedCmd,                  true,  true  },
		{ "/reloadui",          ReloadUICmd,                true,  true  },
		{ "/removeaug",         RemoveAugCmd,               true,  true  },
		{ "/removeaura",        RemoveAura,                 true,  true  },
		{ "/removebuff",        RemoveBuff,                 true,  true  },
		{ "/removelev",         RemoveLevCmd,               true,  false },
		{ "/removepetbuff",     RemovePetBuff,              true,  true  },
		{ "/screenmode",        ScreenModeCmd,              true,  false },
		{ "/selectitem",        SelectItem,                 true,  true  },
		{ "/sellitem",          SellItem,                   true,  true  },
		{ "/setautorun",        SetAutoRun,                 false, true  },
		{ "/setprio",           SetProcessPriority,         true,  false },
		{ "/setwintitle",       SetWinTitle,                true,  false },
		{ "/shiftkey",          DoShiftCmd,                 false, false },
		{ "/skills",            Skills,                     true,  true  },
		{ "/spellslotinfo",     SpellSlotInfo,              true,  true  },
		{ "/squelch",           SquelchCommand,             true,  false },
		{ "/spewfile",          DebugSpewFile,              true,  false },
		{ "/target",            Target,                     true,  true  },  // TODO:  Deprecate /target in favor of /mqtarget so that /target is the actual EQ Command. See #298
		{ "/taskquit",          TaskQuitCmd,                true,  true  },
		{ "/timed",             DoTimedCmd,                 false, false },
		{ "/unload",            Unload,                     true,  false },
		{ "/useitem",           UseItemCmd,                 true,  true  },
		{ "/who",               SuperWho,                   true,  true  },
		{ "/whofilter",         SWhoFilter,                 true,  true  },
		{ "/whotarget",         SuperWhoTarget,             true,  true  },
		{ "/windowstate",       WindowState,                true,  false },

		{ nullptr,              nullptr,                    false, true  },
	};

	// Remove replaced commands first
	for (int i = 0; NewCommands[i].szCommand && NewCommands[i].pFunc; i++)
	{
		RemoveCommand(NewCommands[i].szCommand);
		AddCommand(NewCommands[i].szCommand, NewCommands[i].pFunc, false, NewCommands[i].Parse, NewCommands[i].InGame);
	}

	AddCommand("/alias", [this](PlayerClient*, const char* line) { Cmd_Alias(line); }, false, false, false);
	AddCommand("/help", [this](PlayerClient*, const char* line) { Cmd_Help(line); }, false, true, false);

	LoadAliases();
}

void MQCommandAPI::Shutdown()
{
	RemoveDetour(CEverQuest__InterpretCmd);

	while (m_pCommands)
	{
		MQCommand* pNext = m_pCommands->pNext;
		delete m_pCommands;
		m_pCommands = pNext;
	}

	m_delayedCommands.clear();

	while (m_pTimedCommands)
	{
		MQTimedCommand* pNext = m_pTimedCommands->pNext;
		delete m_pTimedCommands;
		m_pTimedCommands = pNext;
	}

	m_aliases.clear();
}

void MQCommandAPI::OnAfterModuleUnloaded(MQModule* module)
{
	if (module->IsPlugin())
	{
		// Remove any commands that were created by this plugin.
		MQCommand* pCommand = m_pCommands;

		while (pCommand)
		{
			if (pCommand->pluginHandle == module->GetHandle())
			{
				DebugSpew("Removing command left behind by %s: %s", module->GetName().c_str(), pCommand->command.c_str());

				if (pCommand->pNext)
					pCommand->pNext->pLast = pCommand->pLast;
				if (pCommand->pLast)
					pCommand->pLast->pNext = pCommand->pNext;
				else
					m_pCommands = pCommand->pNext;

				MQCommand* thisCmd = pCommand;
				pCommand = pCommand->pNext;

				delete thisCmd;
			}
			else
			{
				pCommand = pCommand->pNext;
			}
		}
	}
}

bool MQCommandAPI::InterpretCmd(const char* szLine, const MQCommandHandler& eqHandler)
{
	if (szLine[0] == 0)
		return false;

	char szOriginalCommand[MAX_STRING] = { 0 };
	strcpy_s(szOriginalCommand, szLine);

	char szCommand[MAX_STRING] = { 0 };
	strcpy_s(szCommand, szLine);

	// Perform alias replacement on the command
	if (SubstituteAlias(szOriginalCommand, szCommand, MAX_STRING))
	{
		strcpy_s(szOriginalCommand, szCommand);
	}

	// We replaced the command, update the first arg.
	GetArg(szCommand, szOriginalCommand, 1);

	if (g_macroSystem
		&& g_macroSystem->IsMacroRunning()
		&& ci_equals(szCommand, "/camp"))
	{
		WriteChatColor("A macro is currently running.  You may wish to /endmacro before you finish camping.", CONCOLOR_YELLOW);
	}

	char szArgs[MAX_STRING] = { 0 };
	strcpy_s(szArgs, GetNextArg(szOriginalCommand));

	if (DispatchCommand(szCommand, szArgs, eqHandler))
	{
		strcpy_s(szLastCommand, szOriginalCommand);
		return true;
	}

	if (g_macroSystem && g_macroSystem->DispatchBind(szCommand, szArgs))
	{
		strcpy_s(szLastCommand, szOriginalCommand);
		return true;
	}

	strcpy_s(szLastCommand, szOriginalCommand);
	return false;
}

bool MQCommandAPI::DispatchCommand(char* szCommand, char* szArgs, const MQCommandHandler& eqHandler)
{
	MQCommand* pCommand = m_pCommands;
	while (pCommand)
	{
		if (pCommand->inGameOnly && gGameState != GAMESTATE_INGAME)
		{
			pCommand = pCommand->pNext;
			continue;
		}

		// Substring search
		int Pos = _strnicmp(szCommand, pCommand->command.c_str(), strlen(szCommand));
		if (Pos < 0)
		{
			// command not found
			break;
		}

		if (Pos == 0)
		{
			// the parser version is 2, or It's not version 2 and we're allowing command parses
			if (pCommand->parse && (gParserVersion == 2 || (gParserVersion != 2 && bAllowCommandParse)))
			{
				ParseMacroParameter(szArgs, MAX_STRING);
			}

			if (pCommand->eq && eqHandler != nullptr)
			{
				strcat_s(szCommand, MAX_STRING, " ");
				strcat_s(szCommand, MAX_STRING, szArgs);

				eqHandler(pLocalPlayer, szCommand);
			}
			else
			{
				pCommand->handler(pLocalPlayer, szArgs);
			}

			return true;
		}
		pCommand = pCommand->pNext;
	}

	return false;
}

bool MQCommandAPI::SubstituteAlias(const char* szOriginal, char* szLine, size_t length)
{
	char szFirstArg[MAX_STRING];
	GetArg(szFirstArg, szOriginal, 1);

	// Perform alias replacement
	auto findIter = m_aliases.find(szFirstArg);
	if (findIter != m_aliases.end())
	{
		const RegisteredAlias& alias = findIter->second;

		sprintf_s(szLine, length, "%s%s", alias.replacement.c_str(), szOriginal + alias.match.size());
		return true;
	}

	return false;
}

bool MQCommandAPI::DoCommandInternal(char* szOriginalLine, char* szArg1, char* szParam)
{
	// Update crash state with last known command in case something goes wrong
	CrashHandler_SetLastCommand(szOriginalLine);
	SCOPE_EXIT(CrashHandler_SetLastCommand(nullptr));

	if (szArg1[0] == 0)
		return true;

	if (szArg1[0] == ';' || szArg1[0] == '[')
	{
		pEverQuest->InterpretCmd(pLocalPlayer, szOriginalLine);
		return true;
	}

	if (DispatchCommand(szArg1, szParam, nullptr))
	{
		strcpy_s(szLastCommand, szOriginalLine);
		return true;
	}

	if (g_macroSystem && g_macroSystem->DispatchBind(szArg1, szParam))
	{
		strcpy_s(szLastCommand, szOriginalLine);
		return true;
	}

	strcpy_s(szLastCommand, szOriginalLine);
	return false;
}

bool MQCommandAPI::DoCommand(const char* szLine, bool delayed,
	const MQPluginHandle& pluginHandle /* = mqplugin::ThisPluginHandle */)
{
	if (delayed)
	{
		m_delayedCommands.emplace_back(szLine, pluginHandle);
		return true;
	}

	WeDidStuff();

	char szOriginalLine[MAX_STRING] = { 0 };
	strcpy_s(szOriginalLine, szLine);

	// The command we are processing. Alias will be applied.
	char szTheCmd[MAX_STRING] = { 0 };
	strcpy_s(szTheCmd, szLine);

	// The first token of the line
	char szArg1[MAX_STRING] = { 0 };
	GetArg(szArg1, szTheCmd, 1);

	// Perform alias replacement on the command
	if (SubstituteAlias(szOriginalLine, szTheCmd, MAX_STRING))
	{
		// We replaced the command, update the first arg.
		GetArg(szArg1, szTheCmd, 1);
	}

	char szParam[MAX_STRING] = { 0 };
	strcpy_s(szParam, GetNextArg(szTheCmd));

	if (!DoCommandInternal(szOriginalLine, szArg1, szParam))
	{
		MacroError("Unrecognized command: '%s'", szLine);
		return false;
	}

	return true;
}

bool MQCommandAPI::AddCommand(std::string_view command, MQCommandHandler handler,
	bool EQ /* = false */, bool Parse /* = true */, bool InGame /* = false */,
	const MQPluginHandle& pluginHandle /* = mqplugin::ThisPluginHandle */)
{
	DebugSpew("AddCommand(%.*s)", command.length(), command.data());

	MQCommand* pCommand = new MQCommand;
	pCommand->command = command;
	pCommand->pluginHandle = pluginHandle;
	pCommand->eq = EQ;
	pCommand->parse = Parse;
	pCommand->handler = std::move(handler);
	pCommand->inGameOnly = InGame;

	// perform insertion sort
	if (!m_pCommands)
	{
		m_pCommands = pCommand;
		return true;
	}

	MQCommand* pSearch = m_pCommands;
	MQCommand* pLast = nullptr;
	while (pSearch)
	{
		int compare = ci_string_compare(pCommand->command, pSearch->command);
		if (compare == 0 && !pSearch->eq)
		{
			// Exact match. This command already exist, do not add it.
			DebugSpew("AddCommand(%.*s): Failed to add command, already exists",
				command.length(), command.data());

			delete pCommand;
			return false;
		}

		// We already filtered out exact matches that we don't want, so the only exact match that we
		// can get now are for eq commands.
		if (compare <= 0)
		{
			// insert here.
			if (pLast)
				pLast->pNext = pCommand;
			else
				m_pCommands = pCommand;

			pCommand->pLast = pLast;
			pSearch->pLast = pCommand;
			pCommand->pNext = pSearch;
			return true;
		}

		pLast = pSearch;
		pSearch = pSearch->pNext;
	}

	// End of list
	pLast->pNext = pCommand;
	pCommand->pLast = pLast;

	return true;
}

bool MQCommandAPI::RemoveCommand(std::string_view command,
	const MQPluginHandle& pluginHandle /* = mqplugin::ThisPluginHandle */)
{
	MQCommand* pCommand = m_pCommands;

	while (pCommand)
	{
		int pos = ci_string_compare(command, pCommand->command);
		if (pos < 0)
		{
			DebugSpew("RemoveCommand: Command not found '%.*s'", command.length(), command.data());
			return false;
		}

		if (pos == 0)
		{
			// Validate that we can remove this command
			if (pCommand->pluginHandle != pluginHandle)
			{
				DebugSpew("RemoveCommand: Cannot remove command '%.*s': Plugin does not own this command",
					command.length(), command.data());
				return false;
			}

			if (pCommand->pNext)
				pCommand->pNext->pLast = pCommand->pLast;
			if (pCommand->pLast)
				pCommand->pLast->pNext = pCommand->pNext;
			else
				m_pCommands = pCommand->pNext;
			delete pCommand;

			return true;
		}

		pCommand = pCommand->pNext;
	}

	return false;
}

MQCommand* MQCommandAPI::FindCommand(std::string_view command) const
{
	MQCommand* pCommand = m_pCommands;
	while (pCommand)
	{
		if (ci_equals(command, pCommand->command))
			return pCommand;

		pCommand = pCommand->pNext;
	}

	return nullptr;
}

bool MQCommandAPI::IsCommand(std::string_view command) const
{
	return FindCommand(command) != nullptr;
}

//============================================================================

bool MQCommandAPI::AddAlias(const std::string& shortCommand, const std::string& longCommand,
	bool writeToIni, const MQPluginHandle& pluginHandle /* = mqplugin::ThisPluginHandle */)
{
	// Check if alias already exists.
	auto iter = m_aliases.find(shortCommand);
	if (iter != m_aliases.end())
	{
		const RegisteredAlias& alias = iter->second;

		DebugSpew("Failed to add alias \"%s\", it already exists", alias.match.c_str());

		return false;
	}

	// Check if command with same name exists
	if (MQCommand* pCommand = FindCommand(shortCommand))
	{
		// Allow overriding of EQ commands
		if (!pCommand->eq)
		{
			DebugSpew("Failed to add alias \"%s\", a command with this name already exists",
				shortCommand.c_str());

			return false;
		}
	}

	DebugSpew("AddAlias(%s,%s)", shortCommand.c_str(), longCommand.c_str());

	auto [iter2, added] = m_aliases.emplace(std::piecewise_construct,
		std::forward_as_tuple(shortCommand),
		std::forward_as_tuple(shortCommand, longCommand, pluginHandle));

	if (writeToIni)
	{
		WriteAliasToIni(iter2->second);
	}

	return true;
}

bool MQCommandAPI::RemoveAlias(const std::string& shortCommand,
	const MQPluginHandle& pluginHandle /* = mqplugin::ThisPluginHandle */)
{
	auto iter = m_aliases.find(shortCommand);
	if (iter == m_aliases.end())
	{
		DebugSpew("Failed to remove alias \"%s\": this alias does not exist",
			shortCommand.c_str());

		return false;
	}

	const RegisteredAlias& alias = iter->second;

	DeletePrivateProfileKey("Aliases", alias.match, mq::internal_paths::MQini);
	
	m_aliases.erase(iter);
	return true;
}

bool MQCommandAPI::IsAlias(const std::string& alias) const
{
	// TODO: Switch to std::string_view when we have c++20 support
	return m_aliases.count(alias) != 0;
}

// better single write them instead...
void MQCommandAPI::WriteAliasToIni(const RegisteredAlias& alias)
{
	WritePrivateProfileString("Aliases", alias.match, alias.replacement, mq::internal_paths::MQini);
}

// this function is SUPER expensive, DO NOT use it unless you absolutely have to.
void MQCommandAPI::RewriteAliases()
{
	WritePrivateProfileSection("Aliases", "", mq::internal_paths::MQini);

	for (const auto& [_, alias] : m_aliases)
	{
		WriteAliasToIni(alias);
	}
}

void MQCommandAPI::LoadAliases()
{
	/* ALIASES FOR OUT OF ORDER SHORTHAND COMMANDS */

	// Add built-in aliases for out-of-order shorthand commands
	struct { const char* match; const char* replacement; } builtInAliases[] = {
		{ "/a",                 "/anonymous" },
		{ "/b",                 "/bazaar" },
		{ "/ba",                "/bazaar" },
		{ "/c",                 "/consider" },
		{ "/cha",               "/channel" },
		{ "/d",                 "/duel" },
		{ "/f",                 "/feedback" },
		{ "/fa",                "/fastdrop" },
		{ "/g",                 "/gsay" },
		{ "/gu",                "/guildsay" },
		{ "/key",               "/keys" },
		{ "/load",              "/loadspells" },
		{ "/m",                 "/msg" },
		{ "/newif",             "/if" },
		{ "/r",                 "/reply" },
		{ "/t",                 "/tell" },
		{ "/ta",                "/tap" },
		{ "/w",                 "/who" },
	};
	for (auto& [match, replacement] : builtInAliases)
	{
		AddAlias(match, replacement, false);
	}

	std::vector<std::string> aliases = GetPrivateProfileKeys<MAX_STRING * 10>("Aliases", mq::internal_paths::MQini);

	// Now, import the user's alias list, their modifications override existing.
	for (const std::string& alias : aliases)
	{
		std::string value = GetPrivateProfileString("Aliases", alias, std::string(), mq::internal_paths::MQini);
		if (!value.empty())
		{
			AddAlias(alias.c_str(), value.c_str(), false);
		}
	}
}

//============================================================================
//============================================================================

void MQCommandAPI::OnProcessFrame()
{
	if (m_delayedCommands.empty() && !m_pTimedCommands)
	{
		return;
	}

	{
		// Swap with empty container to get our delayed commands. Running DoCommand
		// may add something to the container. We don't want to process that, so we
		// work with it from a temporary instead.
		decltype(m_delayedCommands) delayedCommands;
		std::swap(delayedCommands, m_delayedCommands);

		// handle delayed commands
		for (const auto& [delayedCommand, pluginHandle] : delayedCommands)
		{
			DoCommand(delayedCommand.c_str(), false, pluginHandle);
		}
	}

	// handle timed commands
	uint64_t Now = MQGetTickCount64();

	while (m_pTimedCommands && m_pTimedCommands->time <= Now)
	{
		MQTimedCommand* pNext = m_pTimedCommands->pNext;
		DoCommand(m_pTimedCommands->command.c_str(), false, m_pTimedCommands->pluginHandle);

		delete m_pTimedCommands;
		m_pTimedCommands = pNext;
	}
}

void MQCommandAPI::TimedCommand(const char* command, int msDelay, const MQPluginHandle& pluginHandle /* = mqplugin::ThisPluginHandle */)
{
	MQTimedCommand* pNew = new MQTimedCommand;
	pNew->time = msDelay + MQGetTickCount64();
	pNew->command = command;
	pNew->pluginHandle = pluginHandle;

	// insert into list
	if (!m_pTimedCommands || m_pTimedCommands->time >= pNew->time)
	{
		pNew->pNext = m_pTimedCommands;
		pNew->pLast = nullptr;
		m_pTimedCommands = pNew;
		return;
	}

	MQTimedCommand* pLast = m_pTimedCommands;
	MQTimedCommand* pNode = m_pTimedCommands->pNext;

	while (pNode)
	{
		if (pNew->time <= pNode->time)
		{
			break;
		}

		pLast = pNode;
		pNode = pNode->pNext;
	}

	pLast->pNext = pNew;
	pNew->pLast = pLast;
	pNew->pNext = pNode;
}

//============================================================================
// Commands
//============================================================================

// ***************************************************************************
// Function:    Help
// Description: Our '/help' command
//              Adds our help type (7) to the built-in help command
// Usage:       /help macro
// ***************************************************************************
void MQCommandAPI::Cmd_Help(const char* szLine) const
{
	char szCmd[MAX_STRING] = { 0 };
	char szArg[MAX_STRING] = { 0 };

	MQCommand* pCmd = m_pCommands;

	GetArg(szArg, szLine, 1);
	if (szArg[0] == 0)
	{
		if (gGameState == GAMESTATE_INGAME)
			cmdHelp(pLocalPlayer, szArg);

		if (gFilterMacro != FILTERMACRO_NONE)
			WriteChatColor("Macro will display a list of MacroQuest commands.", USERCOLOR_DEFAULT);

		return;
	}

	if (_stricmp("macro", szArg))
	{
		if (gGameState == GAMESTATE_INGAME)
			cmdHelp(pLocalPlayer, szArg);
		return;
	}

	DebugSpew("Help - Displaying MacroQuest help");
	sprintf_s(szCmd, "MacroQuest - %s", gszVersion);
	WriteChatColor(" ", USERCOLOR_DEFAULT);
	WriteChatColor(szCmd, USERCOLOR_DEFAULT);
	WriteChatColor("List of commands", USERCOLOR_DEFAULT);
	WriteChatColor("------------------------------------------", USERCOLOR_DEFAULT);

	while (pCmd)
	{
		if (pCmd->eq == 0)
		{
			WriteChatf("  %s", pCmd->command.c_str());
		}
		pCmd = pCmd->pNext;
	}
}

// ***************************************************************************
// Function:    Alias
// Description: Our '/alias' command
//              Add command aliases
// Usage:       /alias name [delete|command]
// ***************************************************************************

void MQCommandAPI::Cmd_Alias(const char* szLine)
{
	char szName[MAX_STRING] = { 0 };
	GetArg(szName, szLine, 1);

	const char* szCommand = GetNextArg(szLine);

	if (ci_equals(szName, "list"))
	{
		WriteChatColor("Aliases", USERCOLOR_WHO);
		WriteChatColor("--------------------------", USERCOLOR_WHO);

		for (const auto& [_, alias] : m_aliases)
		{
			sprintf_s(szName, "%s: %s", alias.match.c_str(), alias.replacement.c_str());
			WriteChatColor(szName, USERCOLOR_WHO);
		}

		if (m_aliases.empty())
		{
			WriteChatColor("No aliases defined.", USERCOLOR_WHO);
		}
		else
		{
			sprintf_s(szName, "%d alias%s displayed.", static_cast<int>(m_aliases.size()), (m_aliases.size() == 1) ? "" : "es");
			WriteChatColor(szName, USERCOLOR_WHO);
		}

		return;
	}

	if (ci_equals(szName, "reload"))
	{
		m_aliases.clear();

		LoadAliases();
		WriteChatf("%d aliases loaded.", m_aliases.size());
		return;
	}

	if ((szName[0] == 0) || (szCommand[0] == 0))
	{
		SyntaxError("Usage: /alias name [delete|command], /alias list, or /alias reload");
		return;
	}

	if (ci_equals(szCommand, "delete"))
	{
		if (RemoveAlias(szName))
		{
			WriteChatf("Alias '%s' deleted.", szName);
		}
		else
		{
			WriteChatf("Alias '%s' not found.", szName);
		}

		return;
	}

	bool New = !RemoveAlias(szName);
	AddAlias(szName, szCommand, true);

	WriteChatf("Alias '%s' %s.", szName, (New) ? "added" : "updated");
}

//============================================================================
//============================================================================

bool AddCommand(std::string_view command, MQCommandHandler handler, bool eq, bool parse, bool inGame)
{
	return pCommandAPI && pCommandAPI->AddCommand(command, std::move(handler), eq, parse, inGame);
}

bool RemoveCommand(std::string_view command)
{
	return pCommandAPI && pCommandAPI->RemoveCommand(command);
}

void DoCommand(const char* szLine, bool delayed)
{
	if (pCommandAPI)
	{
		pCommandAPI->DoCommand(szLine, delayed);
	}
	else
	{
		SPDLOG_ERROR("Tried to run command without Commands module: {} delayed={}", szLine, delayed);
	}
}

void DoCommandf(const char* szFormat, ...)
{
	va_list vaList;
	va_start(vaList, szFormat);

	int len = _vscprintf(szFormat, vaList) + 1 + 32;
	auto out = std::make_unique<char[]>(len);
	char* szOutput = out.get();

	vsprintf_s(szOutput, len, szFormat, vaList);

	if (pCommandAPI)
	{
		pCommandAPI->DoCommand(szOutput, false);
	}
	else
	{
		SPDLOG_ERROR("Tried to run command without Commands module: {} delayed={}", szOutput, false);
	}
}

fEQCommand FindEQCommand(std::string_view command)
{
	PCMDLIST pCmdListOrig = EQADDR_CMDLIST;

	for (int i = 0; pCmdListOrig[i].fAddress != nullptr; ++i)
	{
		if (ci_equals(pCmdListOrig[i].szName, command))
		{
			return pCmdListOrig[i].fAddress;
		}
	}

	return nullptr;
}

} // namespace mq
