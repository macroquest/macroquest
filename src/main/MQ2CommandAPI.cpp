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

namespace mq {

static std::recursive_mutex s_commandMutex;

// Defined in MQ2MacroCommands.cpp
void FailIf(SPAWNINFO* pChar, const char* szCommand, int pStartLine, bool All);

struct MQTimedCommand
{
	uint64_t      Time;
	char          Command[MAX_STRING];

	MQTimedCommand* pLast;
	MQTimedCommand* pNext;
};

struct MQCommand
{
	char                                      Command[64];
	std::function<void(PlayerClient*, const char*)> Function;
	bool                                      EQ;
	bool                                      Parse;
	bool                                      InGameOnly;

	MQCommand* pLast;
	MQCommand* pNext;
};

struct MQSubstitution
{
	char szOrig[MAX_STRING];
	char szSub[MAX_STRING];

	MQSubstitution* pNext;
	MQSubstitution* pLast;
};

static MQCommand* s_pCommands = nullptr;
static MQTimedCommand* s_pTimedCommands = nullptr;
static MQSubstitution* s_pSubstitutions = nullptr;
static std::vector<std::string> s_delayedCommands;
static std::map<std::string, std::string> mAliases;


void PopMacroLoop();

void HideDoCommand(SPAWNINFO* pChar, const char* szLine, bool delayed)
{
	std::unique_lock lock(s_commandMutex);

	if (delayed)
	{
		s_delayedCommands.emplace_back(szLine);
		return;
	}

	char szTheCmd[MAX_STRING] = { 0 };
	strcpy_s(szTheCmd, szLine);

	WeDidStuff();

	char szOriginalLine[MAX_STRING] = { 0 };
	strcpy_s(szOriginalLine, szTheCmd);

	char szArg1[MAX_STRING] = { 0 };
	GetArg(szArg1, szTheCmd, 1);

	std::string sName = szArg1;
	MakeLower(sName);

	if (mAliases.find(sName) != mAliases.end())
	{
		sprintf_s(szTheCmd, "%s%s", mAliases[sName].c_str(), szOriginalLine + sName.size());
	}

	GetArg(szArg1, szTheCmd, 1);
	if (szArg1[0] == 0)
		return;

	char szParam[MAX_STRING] = { 0 };
	strcpy_s(szParam, GetNextArg(szTheCmd));

	if ((szArg1[0] == ':') || (szArg1[0] == '{'))
	{
		bRunNextCommand = true;
		return;
	}

	MQMacroBlockPtr pBlock = GetCurrentMacroBlock();
	if (szArg1[0] == '}')
	{
		if (pBlock)
		{
			const auto loopStart = pBlock->Line.at(pBlock->CurrIndex).LoopStart;
			if (loopStart != 0)
			{
				pBlock->CurrIndex = loopStart;
				PopMacroLoop();
				return;
			}
		}

		if (strstr(szTheCmd, "{"))
		{
			GetArg(szArg1, szTheCmd, 2);
			if (_stricmp(szArg1, "else") != 0)
			{
				FatalError("} and { seen on the same line without an else present");
			}
			//DebugSpew("DoCommand - handing {} off to FailIf");
			if (pBlock)
				FailIf(pChar, "{", pBlock->CurrIndex, true);
		}
		else
		{
			// handle this:
			//            /if () {
			//            } else /echo stuff
			GetArg(szArg1, szTheCmd, 2);
			if (!_stricmp(szArg1, "else"))
			{
				// check here to fail this:
				//            /if () {
				//            } else
				//                /echo stuff
				GetArg(szArg1, szTheCmd, 3);
				if (!_stricmp(szArg1, ""))
				{
					FatalError("no command or { following else");
				}
				bRunNextCommand = true;
			}
			else
			{
				bRunNextCommand = true;
			}
		}
		return;
	}

	if (szArg1[0] == ';' || szArg1[0] == '[')
	{
		pEverQuest->InterpretCmd(pChar, szOriginalLine);
		return;
	}

	MQCommand* pCommand = s_pCommands;
	while (pCommand)
	{
		if (pCommand->InGameOnly && gGameState != GAMESTATE_INGAME)
		{
			pCommand = pCommand->pNext;
			continue;
		}

		int Pos = _strnicmp(szArg1, pCommand->Command, strlen(szArg1));
		if (Pos < 0)
		{
			// command not found
			break;
		}

		if (Pos == 0)
		{
			lock.unlock();

			// the parser version is 2 or It's not version 2 and we're allowing command parses
			if (pCommand->Parse && (gParserVersion == 2 || (gParserVersion != 2 && bAllowCommandParse)))
			{
				pCommand->Function(pChar, ParseMacroParameter(szParam));
			}
			else
			{
				pCommand->Function(pChar, szParam);
			}

			strcpy_s(szLastCommand, szOriginalLine);
			return;
		}

		pCommand = pCommand->pNext;
	}

	MQBindList* pBind = pBindList;
	while (pBind)
	{
		if (gGameState != GAMESTATE_INGAME)
		{
			// Macro Binds only supported in-game
			pBind = pBind->pNext;
			continue;
		}

		int Pos = _strnicmp(szArg1, pBind->szName, strlen(szArg1));
		if (Pos == 0)
		{
			// found it!
			if (pBind->szFuncName)
			{
				if (pLocalPlayer)
				{
					std::string sCallFunc(pBind->szFuncName);
					sCallFunc += " ";
					sCallFunc += szParam;
					char szCallFunc[MAX_STRING] = { 0 };
					strcpy_s(szCallFunc, sCallFunc.c_str());

					if (pBind->Parse)
					{
						ParseMacroData(szCallFunc, MAX_STRING);
					}

					// pBlock may have changed after executing commands
					pBlock = GetCurrentMacroBlock();
					if (pBlock && pBlock->BindCmd.empty())
					{
						if (!gBindInProgress)
						{
							gBindInProgress = true;
							pBlock->BindCmd = szCallFunc;
						}
						else
						{
							WriteChatf("Can't execute bind while another bind is in progress");
						}
					}
				}
			}

			strcpy_s(szLastCommand, szOriginalLine);
			return;
		}

		pBind = pBind->pNext;
	}

	// skip this logic for Bind Commands.
	if (_strnicmp(szOriginalLine, "sub bind_", 9) != 0)
	{
		if (!_strnicmp(szOriginalLine, "sub ", 4))
		{
			FatalError("Flow ran into another subroutine. (%s)", szOriginalLine);
			return;
		}

		strcpy_s(szLastCommand, szOriginalLine);
		MacroError("DoCommand - Couldn't parse '%s'", szOriginalLine);
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
	HideDoCommand(pLocalPlayer, szOutput, false);
}

class CCommandHook
{
public:
	DETOUR_TRAMPOLINE_DEF(void, Trampoline, (SPAWNINFO* pChar, const char* szFullLine))
	void Detour(SPAWNINFO* pChar, const char* szFullLine)
	{
		std::scoped_lock lock(s_commandMutex);
		DebugSpew("CCommandHook::Detour(%s)", szFullLine);

		char szFullCommand[MAX_STRING] = { 0 };
		char szCommand[MAX_STRING] = { 0 };
		char szArgs[MAX_STRING] = { 0 };
		char szOrig[MAX_STRING] = { 0 };
		char szSub[MAX_STRING] = { 0 };

		std::string szSubFullCommand = "";
		unsigned int k = 0;
		bool OneCharacterSub = false;
		MQSubstitution* pSubLoop = s_pSubstitutions;

		if (szFullLine[0] != 0)
		{
			strcpy_s(szFullCommand, szFullLine);
			GetArg(szCommand, szFullCommand, 1);

			if (!_stricmp(szCommand, "/camp"))
			{
				if (GetMacroBlockCount())
				{
					WriteChatColor("A macro is currently running.  You may wish to /endmacro before you finish camping.", CONCOLOR_YELLOW);
				}
			}

			szSubFullCommand = szFullCommand;
			size_t len = strnlen_s(szFullCommand, MAX_STRING);
			for (unsigned int i = 0; i < sizeof(szFullCommand); i++)
			{
				if (szFullCommand[i] == '%' && ((i + 2) < len))
				{
					if (szFullCommand[i + 2] == ' ' || szFullCommand[i + 2] == '\0' ||
						!isalnum(szFullCommand[i + 2]))
					{
						if (szFullCommand[i + 1] == 'm' || szFullCommand[i + 1] == 'M' ||
							szFullCommand[i + 1] == 'o' || szFullCommand[i + 1] == 'O' ||
							szFullCommand[i + 1] == 'p' || szFullCommand[i + 1] == 'P' ||
							szFullCommand[i + 1] == 'r' || szFullCommand[i + 1] == 'R' ||
							szFullCommand[i + 1] == 's' || szFullCommand[i + 1] == 'S' ||
							szFullCommand[i + 1] == 't' || szFullCommand[i + 1] == 'T')
						{
							continue;
						}
						else
						{
							szOrig[0] = szFullCommand[i + 1];
							szOrig[1] = '\0';
							k = 1;
							OneCharacterSub = true;
						}
					}

					if (!OneCharacterSub)
					{
						for (unsigned int j = i + 1; j < sizeof(szFullCommand); j++)
						{
							if (szFullCommand[j] == ' ' || szFullCommand[j] == '\0')
								break;
							if (!isalnum(szFullCommand[j]))
								break;

							szOrig[k] = szFullCommand[j];
							k++;
						}
					}

					while (pSubLoop)
					{
						if (!_stricmp(szOrig, pSubLoop->szOrig))
						{
							sprintf_s(szSub, "%s", pSubLoop->szSub);
							break;
						}
						pSubLoop = pSubLoop->pNext;
					}

					if (szSub[0] != 0)
					{
						szSubFullCommand.replace(i, k + 1, szSub);
						sprintf_s(szFullCommand, "%s", szSubFullCommand.c_str());
					}

					szOrig[0] = 0;
					szSub[0] = 0;
					k = 0;
					OneCharacterSub = false;
					pSubLoop = s_pSubstitutions;
				}
			}

			sprintf_s(szFullCommand, "%s", szSubFullCommand.c_str());
			std::string sName = szCommand;
			MakeLower(sName);

			if (mAliases.find(sName) != mAliases.end())
			{
				sprintf_s(szCommand, "%s%s", mAliases[sName].c_str(), szFullCommand + sName.size());
				strcpy_s(szFullCommand, szCommand);
			}

			GetArg(szCommand, szFullCommand, 1);
			strcpy_s(szArgs, GetNextArg(szFullCommand));

			MQCommand* pCommand = s_pCommands;
			while (pCommand)
			{
				if (pCommand->InGameOnly && gGameState != GAMESTATE_INGAME)
				{
					pCommand = pCommand->pNext;
					continue;
				}

				int Pos = _strnicmp(szCommand, pCommand->Command, strlen(szCommand));
				if (Pos < 0)
				{
					// command not found
					break;
				}

				if (Pos == 0)
				{
					// the parser version is 2 or It's not version 2 and we're allowing command parses
					if (pCommand->Parse && (gParserVersion == 2 || (gParserVersion != 2 && bAllowCommandParse)))
					{
						ParseMacroParameter(szArgs);
					}

					if (pCommand->EQ)
					{
						strcat_s(szCommand, " ");
						strcat_s(szCommand, szArgs);
						Trampoline(pChar, szCommand);
					}
					else
					{
						pCommand->Function(pChar, szArgs);
					}

					strcpy_s(szLastCommand, szFullCommand);
					return;
				}
				pCommand = pCommand->pNext;
			}

			MQBindList* pBind = pBindList;
			MQMacroBlockPtr pBlock = GetCurrentMacroBlock();
			while (pBind)
			{
				if (gGameState != GAMESTATE_INGAME)
				{
					// Macro Binds only supported in-game
					pBind = pBind->pNext;
					continue;
				}

				int Pos = _strnicmp(szCommand, pBind->szName, strlen(szCommand));

				if (Pos == 0)
				{
					// found it!
					if (pBind->szFuncName)
					{
						if (pLocalPlayer)
						{
							std::string sCallFunc = pBind->szFuncName;
							sCallFunc += " ";
							sCallFunc += szArgs;

							char szCallFunc[MAX_STRING] = { 0 };
							strcpy_s(szCallFunc, sCallFunc.c_str());

							if (pBind->Parse)
							{
								ParseMacroData(szCallFunc, MAX_STRING);
							}

							if (pBlock && pBlock->BindCmd.empty())
							{
								if (!gBindInProgress)
								{
									gBindInProgress = true;
									pBlock->BindCmd = szCallFunc;
								}
								else
								{
									WriteChatf("Can't execute bind while another bind is in progress");
								}
							}

						}
					}

					strcpy_s(szLastCommand, szFullCommand);
					return;
				}

				pBind = pBind->pNext;
			}
		}

		Trampoline(pChar, szFullLine);
		strcpy_s(szLastCommand, szFullCommand);
	}
};

void AddCommand(const char* Command, std::function<void(PlayerClient*, const char*)> Function, bool EQ /* = false */, bool Parse /* = true */, bool InGame /* = false */)
{
	DebugSpew("AddCommand(%s)", Command);

	MQCommand* pCommand = new MQCommand;
	memset(pCommand, 0, sizeof(MQCommand));
	strcpy_s(pCommand->Command, Command);
	pCommand->EQ = EQ;
	pCommand->Parse = Parse;
	pCommand->Function = std::move(Function);
	pCommand->InGameOnly = InGame;

	// perform insertion sort
	if (!s_pCommands)
	{
		s_pCommands = pCommand;
		return;
	}

	MQCommand* pInsert = s_pCommands;
	MQCommand* pLast = nullptr;
	while (pInsert)
	{
		if (_stricmp(pCommand->Command, pInsert->Command) <= 0)
		{
			// insert here.
			if (pLast)
				pLast->pNext = pCommand;
			else
				s_pCommands = pCommand;

			pCommand->pLast = pLast;
			pInsert->pLast = pCommand;
			pCommand->pNext = pInsert;
			return;
		}

		pLast = pInsert;
		pInsert = pInsert->pNext;
	}

	// End of list
	pLast->pNext = pCommand;
	pCommand->pLast = pLast;
}

void AddCommand(const char* Command, fEQCommand Function, bool EQ /* = false */, bool Parse /* = true */, bool InGame /* = false */)
{
	AddCommand(Command, (fEQCommandConstChar)Function, EQ, Parse, InGame);
}

bool RemoveCommand(const char* Command)
{
	MQCommand* pCommand = s_pCommands;

	while (pCommand)
	{
		int Pos = _strnicmp(Command, pCommand->Command, 63);
		if (Pos < 0)
		{
			DebugSpew("RemoveCommand: Command not found '%s'", Command);
			return false;
		}

		if (Pos == 0)
		{
			if (pCommand->pNext)
				pCommand->pNext->pLast = pCommand->pLast;
			if (pCommand->pLast)
				pCommand->pLast->pNext = pCommand->pNext;
			else
				s_pCommands = pCommand->pNext;
			delete pCommand;

			return true;
		}

		pCommand = pCommand->pNext;
	}

	return false;
}

bool IsCommand(const char* command)
{
	MQCommand* pCommand = s_pCommands;
	while (pCommand)
	{
		if (_stricmp(command, pCommand->Command) == 0)
			return true;

		pCommand = pCommand->pNext;
	}

	return false;
}

//============================================================================

void AddAlias(const char* ShortCommand, const char* LongCommand)
{
	std::string sName = ShortCommand;
	MakeLower(sName);

	DebugSpew("AddAlias(%s,%s)", sName.c_str(), LongCommand);
	mAliases[sName] = LongCommand;
}

bool RemoveAlias(const char* ShortCommand)
{
	std::string sName = ShortCommand;
	MakeLower(sName);

	DeletePrivateProfileKey("Aliases", sName, mq::internal_paths::MQini);

	auto iter = mAliases.find(sName);
	if (iter != mAliases.end())
	{
		mAliases.erase(iter);
		return true;
	}

	return false;
}

bool IsAlias(const char* alias)
{
	std::string sName = alias;
	MakeLower(sName);

	return mAliases.find(sName) != mAliases.end();
}

// this function is SUPER expensive, DO NOT use it unless you absolutely have to.
void RewriteAliases()
{
	WritePrivateProfileSection("Aliases", "", mq::internal_paths::MQini);

	for (const auto& [key, value] : mAliases)
	{
		WritePrivateProfileString("Aliases", key, value, mq::internal_paths::MQini);
	}
}

// better single write them instead...
void WriteAliasToIni(const char* Name, const char* Command)
{
	WritePrivateProfileString("Aliases", Name, Command, mq::internal_paths::MQini);
}

void LoadAliases()
{
	/* ALIASES FOR OUT OF ORDER SHORTHAND COMMANDS */
	AddAlias("/d", "/duel");
	AddAlias("/t", "/tell");
	AddAlias("/w", "/who");
	AddAlias("/a", "/anonymous");
	AddAlias("/ta", "/tap");
	AddAlias("/c", "/consider");
	AddAlias("/cha", "/channel");
	AddAlias("/f", "/feedback");
	AddAlias("/fa", "/fastdrop");
	AddAlias("/m", "/msg");
	AddAlias("/load", "/loadspells");
	AddAlias("/b", "/bazaar");
	AddAlias("/ba", "/bazaar");
	AddAlias("/g", "/gsay");
	AddAlias("/gu", "/guildsay");
	AddAlias("/key", "/keys");
	AddAlias("/r", "/reply");
	AddAlias("/newif", "/if");

	std::vector<std::string> aliases = GetPrivateProfileKeys<MAX_STRING * 10>("Aliases", mq::internal_paths::MQini);

	// Now, import the user's alias list, their modifications override existing.
	for (const std::string& alias : aliases)
	{
		std::string value = GetPrivateProfileString("Aliases", alias, std::string(), mq::internal_paths::MQini);
		if (!value.empty())
		{
			AddAlias(alias.c_str(), value.c_str());
		}
	}
}

//============================================================================

void AddSubstitute(const char* Original, const char* Substitution)
{
	DebugSpew("AddSubstitute(%s,%s)", Original, Substitution);

	// perform insertion sort
	if (!s_pSubstitutions)
	{
		MQSubstitution* pSub = new MQSubstitution;
		memset(pSub, 0, sizeof(MQSubstitution));
		strcpy_s(pSub->szOrig, Original);
		strcpy_s(pSub->szSub, Substitution);
		s_pSubstitutions = pSub;
		return;
	}

	MQSubstitution* pInsert = s_pSubstitutions;
	MQSubstitution* pLast = nullptr;

	while (pInsert)
	{
		int Pos = _stricmp(Original, pInsert->szOrig);
		if (Pos < 0)
		{
			// insert here.
			MQSubstitution* pSub = new MQSubstitution;
			memset(pSub, 0, sizeof(MQSubstitution));
			strcpy_s(pSub->szOrig, Original);
			strcpy_s(pSub->szSub, Substitution);
			if (pLast)
				pLast->pNext = pSub;
			else
				s_pSubstitutions = pSub;
			pSub->pLast = pLast;
			pInsert->pLast = pSub;
			pSub->pNext = pInsert;
			return;
		}

		if (Pos == 0)
		{
			strcpy_s(pInsert->szOrig, Original);
			strcpy_s(pInsert->szSub, Substitution);
			return;
		}

		pLast = pInsert;
		pInsert = pInsert->pNext;
	}

	// End of list
	MQSubstitution* pSub = new MQSubstitution;
	memset(pSub, 0, sizeof(MQSubstitution));
	strcpy_s(pSub->szOrig, Original);
	strcpy_s(pSub->szSub, Substitution);
	pLast->pNext = pSub;
	pSub->pLast = pLast;
}

bool RemoveSubstitute(const char* Original)
{
	MQSubstitution* pSub = s_pSubstitutions;
	while (pSub)
	{
		if (!_stricmp(Original, pSub->szOrig))
		{
			if (pSub->pNext)
				pSub->pNext->pLast = pSub->pLast;
			if (pSub->pLast)
				pSub->pLast->pNext = pSub->pNext;
			else
				s_pSubstitutions = pSub->pNext;
			delete pSub;
			return true;
		}
		pSub = pSub->pNext;
	}

	return false;
}

void RewriteSubstitutions()
{
	MQSubstitution* pSubLoop = s_pSubstitutions;
	WritePrivateProfileSection("Substitutions", "", mq::internal_paths::MQini);

	while (pSubLoop)
	{
		WritePrivateProfileString("Substitutions", pSubLoop->szOrig, pSubLoop->szSub, mq::internal_paths::MQini);
		pSubLoop = pSubLoop->pNext;
	}
}

void LoadSubstitutions()
{
	// Importing the User's Substitution List from .ini file
	std::vector<std::string> subs = GetPrivateProfileKeys<MAX_STRING * 10>("Substitutions", mq::internal_paths::MQini);

	for (const std::string& sub : subs)
	{
		std::string value = GetPrivateProfileString("Substitutions", sub, std::string(), mq::internal_paths::MQini);

		if (!value.empty())
		{
			AddSubstitute(sub.c_str(), value.c_str());
		}
	}
}

//============================================================================
//============================================================================

void InitializeMQ2Commands()
{
	DebugSpew("Initializing Commands");

	EzDetour(CEverQuest__InterpretCmd, &CCommandHook::Detour, &CCommandHook::Trampoline);

	// Import EQ commands
	CMDLIST* pCmdListOrig = EQADDR_CMDLIST;

	for (int i = 0; pCmdListOrig[i].fAddress != nullptr; i++)
	{
		if (!strcmp(pCmdListOrig[i].szName, "/who"))
		{
			cmdWho = (fEQCommand)pCmdListOrig[i].fAddress;
			AddCommand("/", pCmdListOrig[i].fAddress, true, true, true); // make sure / does EQ who by default
		}
		else if (!strcmp(pCmdListOrig[i].szName, "/whotarget"))
		{
			cmdWhoTarget = (fEQCommand)pCmdListOrig[i].fAddress;
		}
		else if (!strcmp(pCmdListOrig[i].szName, "/location"))
		{
			cmdLocation = (fEQCommand)pCmdListOrig[i].fAddress;
		}
		else if (!strcmp(pCmdListOrig[i].szName, "/help"))
		{
			cmdHelp = (fEQCommand)pCmdListOrig[i].fAddress;
		}
		else if (!strcmp(pCmdListOrig[i].szName, "/target"))
		{
			cmdTarget = (fEQCommand)pCmdListOrig[i].fAddress;
			// Allow a method of using the original eq command since we've overloaded target
			AddCommand("/eqtarget", pCmdListOrig[i].fAddress, false, true, true);
		}
		else if (!strcmp(pCmdListOrig[i].szName, "/charinfo"))
		{
			cmdCharInfo = (fEQCommand)pCmdListOrig[i].fAddress;
		}
		else if (!strcmp(pCmdListOrig[i].szName, "/filter"))
		{
			cmdFilter = (fEQCommand)pCmdListOrig[i].fAddress;
		}
		else if (!strcmp(pCmdListOrig[i].szName, "/doability"))
		{
			cmdDoAbility = (fEQCommand)pCmdListOrig[i].fAddress;
		}
		else if (!strcmp(pCmdListOrig[i].szName, "/cast"))
		{
			cmdCast = (fEQCommand)pCmdListOrig[i].fAddress;
		}
		else if (!strcmp(pCmdListOrig[i].szName, "/hotbutton"))
		{
			cmdHotbutton = (fEQCommand)pCmdListOrig[i].fAddress;
		}
		else if (!strcmp(pCmdListOrig[i].szName, "/useitem"))
		{
			cmdUseItem = (fEQCommand)pCmdListOrig[i].fAddress;
		}
		else if (!strcmp(pCmdListOrig[i].szName, "/taskquit"))
		{
			cmdTaskQuit = (fEQCommand)pCmdListOrig[i].fAddress;
		}
		else if (!strcmp(pCmdListOrig[i].szName, "/pet"))
		{
			cmdPet = (fEQCommand)pCmdListOrig[i].fAddress;
		}
		else if (!strcmp(pCmdListOrig[i].szName, "/mercswitch"))
		{
			cmdMercSwitch = (fEQCommand)pCmdListOrig[i].fAddress;
		}
#if HAS_ADVANCED_LOOT
		else if (!strcmp(pCmdListOrig[i].szName, "/advloot"))
		{
			cmdAdvLoot = (fEQCommand)pCmdListOrig[i].fAddress;
		}
#endif
		else if (!strcmp(pCmdListOrig[i].szName, "/pickzone"))
		{
			cmdPickZone = (fEQCommand)pCmdListOrig[i].fAddress;
		}
		else if (!strcmp(pCmdListOrig[i].szName, "/assist"))
		{
			cmdAssist = (fEQCommand)pCmdListOrig[i].fAddress;
		}
		else if (!strcmp(pCmdListOrig[i].szName, "/quit"))
		{
			cmdQuit = (fEQCommand)pCmdListOrig[i].fAddress;
		}

		AddCommand(pCmdListOrig[i].szName, pCmdListOrig[i].fAddress, true, true, true);
	}

	// Add MQ commands...
	struct { char* szCommand; fEQCommand pFunc; bool Parse; bool InGame; } NewCommands[] = {
		{ "/whotarget",         SuperWhoTarget,             true,  true  },
		{ "/location",          Location,                   true,  true  },
		{ "/help",              Help,                       true,  false },
		// TODO:  Deprecate /target in favor of /mqtarget so that /target is the actual EQ Command.  Issue #298
		{ "/target",            Target,                     true,  true  },
		{ "/mqtarget",          Target,                     true,  true  },
		{ "/alias",             Alias,                      false, false },
		{ "/aa",                AltAbility,                 true,  true  },
		{ "/substitute",        Substitute,                 false, false },
		{ "/filter",            Filter,                     true,  false },
		{ "/whofilter",         SWhoFilter,                 true,  true  },
		{ "/spewfile",          DebugSpewFile,              true,  false },
		{ "/char",              CharInfo,                   true,  true  },
		{ "/face",              Face,                       true,  true  },
		{ "/identify",          Identify,                   true,  true  },
		{ "/where",             Where,                      true,  true  },
		{ "/skills",            Skills,                     true,  true  },
		{ "/unload",            Unload,                     true,  false },
		{ "/selectitem",        SelectItem,                 true,  true  },
		{ "/buyitem",           BuyItem,                    true,  true  },
		{ "/sellitem",          SellItem,                   true,  true  },
		{ "/memspell",          MemSpell,                   true,  true  },
		{ "/loadspells",        LoadSpells,                 true,  true  },
		{ "/loginname",         DisplayLoginName,           true,  false },
		{ "/echo",              Echo,                       true,  false },
		{ "/cecho",             EchoClean,                  true,  false },
		{ "/msgbox",            MQMsgBox,                   true,  false },
		{ "/lootall",           LootAll,                    true,  false },
		{ "/alert",             Alert,                      true,  true  },
		{ "/click",             Click,                      true,  false },
		{ "/mouseto",           MouseTo,                    true,  false },
		{ "/items",             Items,                      true,  true  },
		{ "/itemtarget",        ItemTarget,                 true,  true  },
		{ "/doability",         DoAbility,                  true,  true  },
		{ "/doors",             Doors,                      true,  true  },
		{ "/doortarget",        DoorTarget,                 true,  true  },
		{ "/beep",              MacroBeep,                  true,  false },
		{ "/cast",              Cast,                       true,  true  },
		{ "/mqlog",             MacroLog,                   true,  false },
		{ "/ini",               IniOutput,                  true,  false },
		{ "/setautorun",        SetAutoRun,                 false, true  },
		{ "/banklist",          BankList,                   true,  true  },
		{ "/look",              Look,                       true,  true  },
		{ "/windowstate",       WindowState,                true,  false },
		{ "/destroy",           EQDestroyHeldItemOrMoney,   true,  true  },
		{ "/popup",             PopupText,                  true,  true  },
		{ "/popcustom",         PopupTextCustom,            true,  true  },
		{ "/popupecho",         PopupTextEcho,              true,  true  },
		{ "/exec",              Exec,                       true,  false },
		{ "/keypress",          DoMappable,                 true,  false },
		{ "/multiline",         MultilineCommand,           false, false },
		{ "/ranged",            do_ranged,                  true,  true  },
		{ "/loadcfg",           LoadCfgCommand,             true,  false },
		{ "/squelch",           SquelchCommand,             true,  false },
		{ "/docommand",         DoCommandCmd,               true,  false },
		{ "/ctrlkey",           DoCtrlCmd,                  false, false },
		{ "/altkey",            DoAltCmd,                   false, false },
		{ "/shiftkey",          DoShiftCmd,                 false, false },
		{ "/timed",             DoTimedCmd,                 false, false },
		{ "/bind",              MQ2KeyBindCommand,          true,  false },
		{ "/noparse",           NoParseCmd,                 false, false },
		{ "/nomodkey",          NoModKeyCmd,                false, false },
		{ "/dumpbinds",         DumpBindsCommand,           true,  false },
		{ "/dosocial",          DoSocial,                   true,  true  },
		{ "/combine",           CombineCmd,                 true,  true  },
		{ "/drop",              DropCmd,                    true,  true  },
		{ "/delay",             Delay,                      false, false }, // do not parse
		{ "/hud",               HudCmd,                     true,  false },
		{ "/hotbutton",         DoHotButton,                true,  true  },
		{ "/taskquit",          TaskQuitCmd,                true,  true  },
		{ "/useitem",           UseItemCmd,                 true,  true  },
		{ "/spellslotinfo",     SpellSlotInfo,              true,  true  },
		{ "/getwintitle",       GetWinTitle,                true,  false },
		{ "/setwintitle",       SetWinTitle,                true,  false },
		{ "/removebuff",        RemoveBuff,                 true,  true  },
		{ "/removepetbuff",     RemovePetBuff,              true,  true  },
		{ "/makemevisible",     MakeMeVisible,              false, true  },
		{ "/pet",               PetCmd,                     true,  true  },
		{ "/mercswitch",        MercSwitchCmd,              true,  true  },
		{ "/removeaura",        RemoveAura,                 false, true  },
#if HAS_ADVANCED_LOOT
		{ "/advloot",           AdvLootCmd,                 true,  true  },
#endif
		{ "/pickzone",          PickZoneCmd,                true,  true  },
		{ "/assist",            AssistCmd,                  true,  true  },
		{ "/setprio",           SetProcessPriority,         true,  false },
		{ "/screenmode",        ScreenModeCmd,              true,  false },
		{ "/usercamera",        UserCameraCmd,              true,  false },
		{ "/foreground",        ForeGroundCmd,              true,  false },
		{ "/quit",              QuitCmd,                    true,  false },
		{ "/removelev",         RemoveLevCmd,               true,  false },
		{ "/engine",            EngineCommand,              true,  false },
		{ "/cachedbuffs",       CachedBuffsCommand,         true,  true  },
		{ "/mqcopylayout",      MQCopyLayout,               true,  false },
		{ "/who",               SuperWho,                   true,  true  },
		{ "/macro",             Macro,                      true,  false },
		{ "/endmacro",          EndMacro,                   true,  false },
		{ "/mqpause",           MacroPause,                 true,  false },
		{ "/listmacros",        ListMacros,                 true,  false },
		{ "/seterror",          SetError,                   true,  false },
		{ "/declare",           NewDeclareVar,              true,  false },
		{ "/deletevar",         NewDeleteVarCmd,            true,  false },
		{ "/varcalc",           NewVarcalc,                 true,  false },
		{ "/varset",            NewVarset,                  true,  false },
		{ "/vardata",           NewVardata,                 true,  false },
		{ "/cleanup",           Cleanup,                    true,  false },
		{ "/doevents",          DoEvents,                   true,  false },
		{ "/goto",              Goto,                       true,  false },
		{ "/for",               For,                        true,  false },
		{ "/next",              Next,                       true,  false },
		{ "/call",              Call,                       true,  false },
		{ "/return",            Return,                     true,  false },
		{ "/dumpstack",         DumpStack,                  true,  false },
		{ "/keepkeys",          KeepKeys,                   true,  false },
		{ "/if",                NewIf,                      true,  false },
		{ "/while",             WhileCmd,                   true,  false },
		{ "/break",             Break,                      true,  false },
		{ "/continue",          Continue,                   true,  false },
		{ "/clearerrors",       ClearErrorsCmd,             true,  false },
		{ "/invoke",            InvokeCmd,                  true,  false },
		{ "/mqlistmodules",     ListModulesCommand,         false, false },
		{ "/mqlistprocesses",   ListProcessesCommand,       false, false },
#if HAS_ITEM_CONVERT_BUTTON
		{ "/convertitem",       ConvertItemCmd,             true,  true  },
#endif
		{ "/insertaug",         InsertAugCmd,               true,  true  },
		{ "/removeaug",         RemoveAugCmd,               true,  true  },
		{ "/profile",           ProfileCommand,             true,  false },
		{ "/executelink",       ExecuteLinkCommand,         true,  true  },

		{ nullptr,              nullptr,                    false, true  },
	};

	// Remove replaced commands first
	for (int i = 0; NewCommands[i].szCommand && NewCommands[i].pFunc; i++)
	{
		RemoveCommand(NewCommands[i].szCommand);
		AddCommand(NewCommands[i].szCommand, NewCommands[i].pFunc, false, NewCommands[i].Parse, NewCommands[i].InGame);
	}

	LoadAliases();

	LoadSubstitutions();
}

void ShutdownMQ2Commands()
{
	std::scoped_lock lock(s_commandMutex);

	RemoveDetour(CEverQuest__InterpretCmd);

	while (s_pCommands)
	{
		MQCommand* pNext = s_pCommands->pNext;
		delete s_pCommands;
		s_pCommands = pNext;
	}

	s_delayedCommands.clear();

	while (s_pTimedCommands)
	{
		MQTimedCommand* pNext = s_pTimedCommands->pNext;
		delete s_pTimedCommands;
		s_pTimedCommands = pNext;
	}

	mAliases.clear();
	while (s_pSubstitutions)
	{
		MQSubstitution* pNext = s_pSubstitutions->pNext;
		delete s_pSubstitutions;
		s_pSubstitutions = pNext;
	}
}

void PulseCommands()
{
	if (s_delayedCommands.empty() && !s_pTimedCommands)
	{
		return;
	}

	std::scoped_lock lock(s_commandMutex);

	{
		// Swap with empty container to get our delayed commands. Running DoCommand
		// may add something to the container. We don't want to process that, so we
		// work with it from a temporary instead.
		decltype(s_delayedCommands) delayedCommands;
		std::swap(delayedCommands, s_delayedCommands);

		// handle delayed commands
		for (const std::string& delayedCommand : delayedCommands)
		{
			DoCommand(pLocalPlayer, delayedCommand.c_str());
		}
	}

	// handle timed commands
	uint64_t Now = MQGetTickCount64();

	while (s_pTimedCommands && s_pTimedCommands->Time <= Now)
	{
		MQTimedCommand* pNext = s_pTimedCommands->pNext;
		DoCommand(pLocalPlayer, s_pTimedCommands->Command);

		delete s_pTimedCommands;
		s_pTimedCommands = pNext;
	}
}

void TimedCommand(const char* Command, int msDelay)
{
	std::scoped_lock lock(s_commandMutex);

	MQTimedCommand* pNew = new MQTimedCommand;

	pNew->Time = msDelay + MQGetTickCount64();
	strcpy_s(pNew->Command, Command);

	// insert into list
	if (!s_pTimedCommands || s_pTimedCommands->Time >= pNew->Time)
	{
		pNew->pNext = s_pTimedCommands;
		pNew->pLast = nullptr;
		s_pTimedCommands = pNew;
		return;
	}

	MQTimedCommand* pLast = s_pTimedCommands;
	MQTimedCommand* pNode = s_pTimedCommands->pNext;

	while (pNode)
	{
		if (pNew->Time <= pNode->Time)
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
void Help(SPAWNINFO* pChar, char* szLine)
{
	char szCmd[MAX_STRING] = { 0 };
	char szArg[MAX_STRING] = { 0 };

	MQCommand* pCmd = s_pCommands;

	GetArg(szArg, szLine, 1);
	if (szArg[0] == 0)
	{
		if (gGameState == GAMESTATE_INGAME)
			cmdHelp(pChar, szArg);

		if (gFilterMacro != FILTERMACRO_NONE)
			WriteChatColor("Macro will display a list of MacroQuest commands.", USERCOLOR_DEFAULT);

		return;
	}

	if (_stricmp("macro", szArg))
	{
		if (gGameState == GAMESTATE_INGAME)
			cmdHelp(pChar, szArg);
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
		if (pCmd->EQ == 0)
		{
			WriteChatf("  %s", pCmd->Command);
		}
		pCmd = pCmd->pNext;
	}
}

// ***************************************************************************
// Function:    Substitute
// Description: Our '/substitute' command
//              Add substitutions
// Usage:       /substitution <original> <new>
//              /substitution list
//              /substitition <original> delete
// ***************************************************************************
void Substitute(SPAWNINFO* pChar, char* szLine)
{
	char szBuffer[MAX_STRING] = { 0 };

	char szName[MAX_STRING] = { 0 };
	GetArg(szName, szLine, 1);
	const char* szCommand = GetNextArg(szLine);

	if (!_stricmp(szName, "list"))
	{
		MQSubstitution* pLoop = s_pSubstitutions;

		int Count = 0;
		WriteChatColor("Substitutions", USERCOLOR_WHO);
		WriteChatColor("--------------------------", USERCOLOR_WHO);

		while (pLoop)
		{
			sprintf_s(szName, "%s\t----\t%s", pLoop->szOrig, pLoop->szSub);
			WriteChatColor(szName, USERCOLOR_WHO);
			Count++;

			pLoop = pLoop->pNext;
		}

		if (Count == 0)
		{
			WriteChatColor("No Substitutions defined.", USERCOLOR_WHO);
		}
		else
		{
			sprintf_s(szName, "%d substitution%s displayed.", Count, (Count == 1) ? "" : "s");
			WriteChatColor(szName, USERCOLOR_WHO);
		}

		return;
	}

	if ((szName[0] == 0) || (szCommand[0] == 0))
	{
		SyntaxError("Usage: /substitute <orig> <new>, /substitute <orig> delete, or /substitute list");
		return;
	}

	if (!_stricmp(szCommand, "delete"))
	{
		if (RemoveSubstitute(szName))
		{
			RewriteSubstitutions();

			WriteChatf("Substitution for '%s' deleted.", szName);
		}
		else
		{
			WriteChatf("Substitution for '%s' not found.", szName);
		}
	}
	else
	{
		bool New = !RemoveSubstitute(szName);

		AddSubstitute(szName, szCommand);

		WriteChatf("Substitution for '%s' %s.", szName, New ? "added" : "updated");
		RewriteSubstitutions();
	}
}

// ***************************************************************************
// Function:    Alias
// Description: Our '/alias' command
//              Add command aliases
// Usage:       /alias name [delete|command]
// ***************************************************************************

void Alias(SPAWNINFO* pChar, char* szLine)
{
	char szName[MAX_STRING] = { 0 };
	GetArg(szName, szLine, 1);

	const char* szCommand = GetNextArg(szLine);

	if (ci_equals(szName, "list"))
	{
		int Count = 0;

		WriteChatColor("Aliases", USERCOLOR_WHO);
		WriteChatColor("--------------------------", USERCOLOR_WHO);

		for (const auto& [key, value] : mAliases)
		{
			sprintf_s(szName, "%s: %s", key.c_str(), value.c_str());
			WriteChatColor(szName, USERCOLOR_WHO);
		}

		if (mAliases.empty())
		{
			WriteChatColor("No aliases defined.", USERCOLOR_WHO);
		}
		else
		{
			sprintf_s(szName, "%d alias%s displayed.", static_cast<int>(mAliases.size()), (mAliases.size() == 1) ? "" : "es");
			WriteChatColor(szName, USERCOLOR_WHO);
		}

		return;
	}

	if (ci_equals(szName, "reload"))
	{
		mAliases.clear();

		LoadAliases();
		WriteChatf("%d aliases loaded.", mAliases.size());
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
	AddAlias(szName, szCommand);
	WriteAliasToIni(szName, szCommand);

	WriteChatf("Alias '%s' %s.", szName, (New) ? "added" : "updated");
}

} // namespace mq
