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
#include "MacroSystem.h"
#include "MacroSystemInternal.h"

#include "MacroQuest.h"
#include "MQCommandAPI.h"
#include "MQDataAPI.h"
#include "MQKeyBinds.h"
#include "MQMain.h"
#include "datatypes/MQDataTypes.h"

#include "mq/api/CommandAPI.h"

#include <regex>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

using namespace eqlib;
using namespace mq::datatypes;

namespace mq {

//=================================================================================================

using DefaultValueType = std::variant<const char*, MQTypeVar>;

bool bRunNextCommand = false;

// TODO: Remove this once the parsing engine is fully backwards compatible.
// Alternatively, move it into the macro block.
int gParserVersion = 1;

bool bInMacroCall = false;

static std::map<std::string, MQMacroBlockPtr> MacroBlockMap;
MQMacroBlockPtr gMacroBlock = nullptr;
decltype(gMacroSubLookupMap) gMacroSubLookupMap;
decltype(gUndeclaredVars) gUndeclaredVars;
MQDataVar* pGlobalVariables = nullptr;
MQDataVar* pMacroVariables = nullptr;

MQTimer* gTimer = nullptr;
bool bAllErrorsFatal = false;
bool bAllErrorsDumpStack = true;
bool bAllErrorsLog = false;
int BlockIndex = 0;
MQMacroStack* gMacroStack = nullptr;
bool gBindInProgress = false;
MQEventQueue* gEventQueue = nullptr;
int gEventFunc[NUM_EVENTS] = { 0 };
char gszLastNormalError[MAX_STRING] = { 0 };
char gszLastSyntaxError[MAX_STRING] = { 0 };
char gszLastMQ2DataError[MAX_STRING] = { 0 };
DWORD gEventChat = 0;
uint64_t gRunning = 0;
int gMaxTurbo = 80;
int gTurboLimit = 240;
bool gReturn = true;
bool gKeepKeys = true;
MQEventList* pEventList = nullptr;
Blech* pEventBlech = nullptr;
bool gMQPauseOnChat = false;
bool gTurbo = false;
bool gWarning = false;
MQBindList* pBindList = nullptr;
MQDefine* pDefines = nullptr;
int gDelay = 0;
char gDelayCondition[MAX_STRING] = { 0 };
bool gFilterMQ2DataErrors = false;

Blech* pMQ2Blech = nullptr;
char EventMsg[MAX_STRING] = { 0 };
char gszMacroName[MAX_STRING] = { 0 };

static uint64_t s_commandCount = 0;

static bool AddMacroLine(const std::string& FileName, char* szLine, size_t Linelen, int* LineNumber, int localLine);
static void EngineCommand(PlayerClient*, const char* szLine);
static void EndMacroCommand(PlayerClient*, const char* szLine);
static void Call(PlayerClient*, const char* szLine);

static void CALLBACK EventBlechCallback(unsigned int ID, void* pData, PBLECHVALUE pValues);

static void format_args(fmt::appender& buffer, const std::vector<std::string>& args)
{
	if (args.empty())
		return;

	fmt::format_to(buffer, "\"{}\"", mq::replace(args[0], "\"", "\"\""));
	for (size_t i = 1; i < args.size(); ++i)
		fmt::format_to(buffer, ",\"{}\"", mq::replace(args[0], "\"", "\"\""));
}

static std::vector<std::string> ArgsToVector(const char* szLine)
{
	std::vector<std::string> args;

	int i = 1;
	while (true)
	{
		char szArg[MAX_STRING] = { 0 };
		GetArg(szArg, szLine, i);

		if (!szArg[0])
			break;

		if (i > 0)
			args.emplace_back(szArg);

		++i;
	}

	return args;
}

static int GetNumArgsFromSub(const std::string& Sub)
{
	if (std::count(Sub.begin(), Sub.end(), '(') != 0)
	{
		size_t n = std::count(Sub.begin(), Sub.end(), ',');
		return static_cast<int>(n) + 1;
	}
	return 0;
}

char* GetMacroSubFromLine(int Line, char* szSub, size_t Sublen)
{
	for (auto ri = std::reverse_iterator(gMacroBlock->Line.find(Line)); ri != gMacroBlock->Line.rend(); ++ri)
	{
		if (!_strnicmp(ri->second.Command.c_str(), "sub ", 4))
		{
			strcpy_s(szSub, Sublen, ri->second.Command.c_str() + 4);
			return szSub;
		}
	}

	strcpy_s(szSub, Sublen, "NULL");
	return szSub;
}

static void PopMacroLoop()
{
	gMacroStack->loopStack.pop_back();
}

static void PushMacroLoop(const MQLoop& loop)
{
	auto size = gMacroStack->loopStack.size();
	if (size > 0 && gMacroStack->loopStack[size - 1].firstLine == loop.firstLine)
		return;

	gMacroStack->loopStack.push_back(loop);
}

static void EndWhile()
{
	gMacroBlock->CurrIndex = gMacroBlock->Line.at(gMacroBlock->CurrIndex).LoopEnd;
	bRunNextCommand = true;
}

static void MarkWhile(const char* szCommand, MQLoop& loop)
{
	if (szCommand[strlen(szCommand) - 1] == '{')
	{
		loop.type = MQLoop::Type::While;

		auto lineIter = gMacroBlock->Line.find(gMacroBlock->CurrIndex);
		if (lineIter->second.LoopStart && lineIter->second.LoopEnd)
		{
			loop.firstLine = lineIter->second.LoopStart;
			loop.lastLine = lineIter->second.LoopEnd;
			return;
		}

		const auto currentLine = lineIter;
		--lineIter;
		currentLine->second.LoopStart = lineIter->first;
		loop.firstLine = lineIter->first;
		++lineIter;
		int Scope = 1;

		while (++lineIter != gMacroBlock->Line.end())
		{
			if (lineIter->second.Command[0] == '}')
			{
				--Scope;
				if (Scope == 0) break;
			}

			if (lineIter->second.Command[lineIter->second.Command.size() - 1] == '{')
			{
				++Scope;
			}
			else if (!_strnicmp(lineIter->second.Command.c_str(), "sub ", 4))
			{
				FatalError("{} pairing ran into anther subroutine");
				return;
			}
		}

		if (Scope != 0)
		{
			FatalError("No } found for /while");
			return;
		}

		lineIter->second.LoopStart = loop.firstLine;
		loop.lastLine = lineIter->first;
		currentLine->second.LoopEnd = lineIter->first;
	}
	else
	{
		FatalError("You have a /while block that's not enclosed in {}");
	}
}

static char* GetFuncParam(const char* szMacroLine, int ParamNum, char* szParamName, size_t ParamNameLen, char* szParamType, size_t ParamTypeLen)
{
	szParamName[0] = 0;
	szParamType[0] = 0;

	if (_strnicmp(szMacroLine, "sub ", 4))
		return nullptr;

	const char* szSubParamNamePointer = szMacroLine + 4;
	while ((szSubParamNamePointer[0] != '(') && (szSubParamNamePointer[0] != 0))
	{
		szSubParamNamePointer++;
	}

	if (szSubParamNamePointer[0] == '(')
		szSubParamNamePointer++;

	if (szSubParamNamePointer[0] != 0)
	{
		char Temp[MAX_STRING] = { 0 };
		GetArg(Temp, szSubParamNamePointer, ParamNum + 1, true, true, true, ',');

		if (*Temp && Temp[strlen(Temp) - 1] == ')')
			Temp[strlen(Temp) - 1] = 0;

		char* pStart = &Temp[0];
		while (*pStart == ' ')
			++pStart;
		if (pStart != &Temp[0])
			memmove(Temp, pStart, MAX_STRING - 1);

		if (char* pSpace = strchr(Temp, ' '))
		{
			*pSpace = 0;
			strcpy_s(szParamType, ParamTypeLen, Temp);
			strcpy_s(szParamName, ParamNameLen, &pSpace[1]);
		}
		else
		{
			strcpy_s(szParamName, ParamNameLen, Temp);
		}
	}

	if (szParamType[0] == 0)
		strcpy_s(szParamType, ParamTypeLen, "string");
	if (szParamName[0] == 0)
		sprintf_s(szParamName, ParamNameLen, "Param%d", ParamNum);

	return szParamName;
}

// in-place cleanup of tabs, leading/trailing space
void CleanMacroLine(char* szLine)
{
	if (!szLine || szLine[0] == 0)
		return;

	char* pChar = szLine;
	while (pChar[0])
	{
		if (pChar[0] == '\t' || pChar[0] == 0x0a || pChar[0] == 0x0d)
			pChar[0] = ' ';
		++pChar;
	}

	// find beginning and end
	char* pStart = szLine;
	size_t Length = strlen(szLine);
	char* pEnd = &szLine[Length - 1];

	while (*pStart == ' ')
		++pStart;
	while (*pEnd == ' ')
		--pEnd;

	if ((pStart && !*pStart) || (pEnd && !*pEnd))
	{
		if (szLine)
			szLine[0] = '\0';
		return;
	}

	// keep only this part.
	size_t NewLength = 1 + pEnd - pStart;
	if (NewLength == Length)
		return; // nothing to do

	memmove(szLine, pStart, NewLength);
	if (szLine && strlen(szLine) >= NewLength)
		szLine[NewLength] = '\0';
}

// ***************************************************************************
// Function:    Include
// Description: Includes another macro file
// Usage:       #include <filename>
// ***************************************************************************
static bool Include(const fs::path& includePath, int* LineNumber)
{
	std::string includePathStr = includePath.string();
	FILE* fMacro = _fsopen(includePathStr.c_str(), "rt", _SH_DENYNO);
	if (fMacro == nullptr)
	{
		FatalError("Couldn't open include file: %s", includePathStr.c_str());
		return false;
	}

	const std::string strMacroName = includePath.filename().string();

	int LocalLine = 0;
	bool InBlockComment = false;
	char szTemp[MAX_STRING] = { 0 };

	while (!feof(fMacro))
	{
		char* tmp = fgets(szTemp, MAX_STRING, fMacro);

		if (!tmp && feof(fMacro))
			break;

		CleanMacroLine(szTemp);
		LocalLine++;
		(*LineNumber)++;

		if (!strncmp(szTemp, "|**", 3))
		{
			InBlockComment = true;
		}

		if (!InBlockComment)
		{
			if (!AddMacroLine(strMacroName, szTemp, MAX_STRING, LineNumber, LocalLine))
			{
				MacroError("Unable to add macro line.");

				fclose(fMacro);
				gszMacroName[0] = 0;
				gRunning = 0;

				return false;
			}
		}
		else
		{
			DebugSpewNoFile("Macro - BlockComment: %s", szTemp);

			if (!strncmp(&szTemp[strlen(szTemp) - 3], "**|", 3))
			{
				InBlockComment = false;
			}
		}
	}

	fclose(fMacro);
	return true;
}

// ***************************************************************************
// Function:    AddMacroLine
// Description: Add a line to the MacroBlock
// ***************************************************************************
static bool AddMacroLine(const std::string& FileName, char* szLine, size_t Linelen, int* LineNumber, int localLine)
{
	// replace all tabs with spaces
	if ((szLine[0] == 0) || (szLine[0] == '|'))
		return true;

	MQDefine* pDef = pDefines;

	if (szLine[0] != '#')
	{
		while (pDef)
		{
			while (strstr(szLine, pDef->szName))
			{
				char szNew[MAX_STRING] = { 0 };
				strncpy_s(szNew, szLine, strstr(szLine, pDef->szName) - szLine);
				strcat_s(szNew, pDef->szReplace);
				strcat_s(szNew, strstr(szLine, pDef->szName) + strlen(pDef->szName));
				strcpy_s(szLine, Linelen, szNew);
			}
			pDef = pDef->pNext;
		}
	}
	else
	{
		if (!_strnicmp(szLine, "#include ", 9) || !_strnicmp(szLine, "#include_optional ", 18))
		{
			bool optional = false;
			szLine += 8;
			// account for include_optional
			if (szLine[0] == '_')
			{
				szLine += 9;
				optional = true;
			}

			while (szLine[0] == ' ')
			{
				szLine++;
			}
			ParseMacroData(szLine, Linelen);

			std::filesystem::path incFilePath = szLine;
			if (incFilePath.is_relative())
			{
				incFilePath = mq::internal_paths::Macros / incFilePath;
			}

			std::error_code ec_exists;
			// If the file exists, use it, but if not try inc, then mac, then settle on inc
			if (!incFilePath.has_extension() && !exists(incFilePath, ec_exists))
			{
				if (!exists(incFilePath.replace_extension("inc"), ec_exists))
				{
					if (!exists(incFilePath.replace_extension("mac"), ec_exists))
					{
						incFilePath.replace_extension("inc");
					}
				}
			}

			if (!optional)
			{
				// Include() contains the error messages, so let it error if it doesn't exist
				return Include(incFilePath, LineNumber);
			}

			// if we're here, it was optional so only include if it exists
			if (exists(incFilePath, ec_exists))
			{
				return Include(incFilePath, LineNumber);
			}
		}
		else if (!_strnicmp(szLine, "#warning", 8))
		{
			gWarning = true;
		}
		else if (!_strnicmp(szLine, "#turbo", 6))
		{
			gTurbo = true;

			char szArg[MAX_STRING] = { 0 };
			GetArg(szArg, szLine, 2);

			gMaxTurbo = GetIntFromString(szArg, 0);
			if (gMaxTurbo == 0)
				gMaxTurbo = 80;
			else if (gMaxTurbo > gTurboLimit)
			{
				MacroError("#turbo %d is too high, setting at %d (maximum)", gMaxTurbo, gTurboLimit);
				gMaxTurbo = gTurboLimit;
			}
		}
		else if (!_strnicmp(szLine, "#define ", 8))
		{
			char szArg1[MAX_STRING] = { 0 };
			char szArg2[MAX_STRING] = { 0 };
			GetArg(szArg1, szLine, 2);
			GetArg(szArg2, szLine, 3);

			if ((szArg1[0] != 0) && (szArg2[0] != 0))
			{
				MQDefine* define = new MQDefine();

				strcpy_s(define->szName, szArg1);
				strcpy_s(define->szReplace, szArg2);
				define->pNext = pDefines;
				pDefines = define;
			}
			else
			{
				MacroError("Bad #define: %s", szLine);
			}
		}
		else if (!_strnicmp(szLine, "#event ", 7))
		{
			char szArg1[MAX_STRING] = { 0 };
			char szArg2[MAX_STRING] = { 0 };
			GetArg(szArg1, szLine, 2);
			GetArg(szArg2, szLine, 3);

			if ((szArg1[0] != 0) && (szArg2[0] != 0))
			{
				MQEventList* pEvent = new MQEventList();

				sprintf_s(pEvent->szName, "Sub Event_%s", szArg1);

				if (char* pDest = strstr(szArg2, "${"))
				{
					// its a variable... so we must "/declare" it for them...
					char szVar[MAX_STRING] = { 0 };
					strcpy_s(szVar, &pDest[2]);

					if (pDest = strchr(szVar, '}'))
					{
						pDest[0] = '\0';

						if (VariableMap.find(szVar) == VariableMap.end())
						{
							// we don't know what the macro will varset this to, so we just
							// default it to the same name as the key...
							// cant set it to "" cause then it triggers on every single line of
							// chat before they /varset it to something... (if they ever)
							AddDataVariable(szVar, "", datatypes::pStringType, &pMacroVariables, "NULL");
						}
					}
				}

				strcpy_s(pEvent->szMatch, szArg2);
				pEvent->BlechID = pEventBlech->AddEvent(pEvent->szMatch, EventBlechCallback, pEvent);
				pEvent->pEventFunc = 0;
				pEvent->pNext = pEventList;
				pEventList = pEvent;
			}
			else
			{
				MacroError("Bad #event: %s", szLine);
			}
		}
		else if (!_strnicmp(szLine, "#bind ", 6) || !_strnicmp(szLine, "#bind_noparse ", 14))
		{
			bool parse = true;
			if (szLine[5] == '_')
				parse = false;

			if (gParserVersion != 2 && parse == false)
			{
				MacroError("#bind_noparse requires enabling Parser Version 2.");
			}
			else
			{
				char szArg1[MAX_STRING] = { 0 };
				char szArg2[MAX_STRING] = { 0 };
				GetArg(szArg1, szLine, 2);
				GetArg(szArg2, szLine, 3);

				if ((szArg1[0] != 0) && (szArg2[0] != 0))
				{
					MQBindList* pBind = new MQBindList();
					// TODO:  Deprecate this so that NoParse_ isn't needed on the sub name
					sprintf_s(pBind->szFuncName, "Bind_%s%s", parse ? "" : "NoParse_", szArg1);
					strcpy_s(pBind->szName, szArg2);
					pBind->Parse = parse;
					pBind->pNext = pBindList;
					pBindList = pBind;
				}
				else
				{
					MacroError("Bad #bind%s: %s", parse ? "" : "_noparse", szLine);
				}
			}
		}
		else if (!_strnicmp(szLine, "#engine ", 8))
		{
			std::string_view lineView{ szLine };
			std::string strLine = std::string{ lineView.substr(8) } + " noauto";

			strcpy_s(szLine, Linelen, strLine.c_str());
			EngineCommand(pLocalPlayer, szLine);
		}
		else if (!_strnicmp(szLine, "#chat ", 6))
		{
			szLine += 5;
			while (szLine[0] == ' ') szLine++;
			if (!_stricmp(szLine, "say"))   gEventChat = gEventChat | CHAT_SAY;
			if (!_stricmp(szLine, "tell"))  gEventChat = gEventChat | CHAT_TELL;
			if (!_stricmp(szLine, "ooc"))   gEventChat = gEventChat | CHAT_OOC;
			if (!_stricmp(szLine, "shout")) gEventChat = gEventChat | CHAT_SHOUT;
			if (!_stricmp(szLine, "auc"))   gEventChat = gEventChat | CHAT_AUC;
			if (!_stricmp(szLine, "guild")) gEventChat = gEventChat | CHAT_GUILD;
			if (!_stricmp(szLine, "group")) gEventChat = gEventChat | CHAT_GROUP;
			if (!_stricmp(szLine, "raid"))  gEventChat = gEventChat | CHAT_RAID;
			if (!_stricmp(szLine, "chat"))  gEventChat = gEventChat | CHAT_CHAT;
		}
		else if (szLine[1] == '!')
		{
			// Like: #!/usr/local/bin/LegacyMQ2
			// ignore.
		}
		else
		{
			MacroError("Unknown # command: %s", szLine);
			return false;
		}
	}

	if ((!_stricmp(szLine, "Sub Event_Chat")) || (!_strnicmp(szLine, "Sub Event_Chat(", 15)))
	{
		gEventFunc[EVENT_CHAT] = *LineNumber;
	}
	else if ((!_stricmp(szLine, "Sub Event_Timer")) || (!_strnicmp(szLine, "Sub Event_Timer(", 16)))
	{
		gEventFunc[EVENT_TIMER] = *LineNumber;
	}
	else
	{
		MQEventList* pEvent = pEventList;
		while (pEvent)
		{
			if (!_stricmp(szLine, pEvent->szName))
			{
				pEvent->pEventFunc = *LineNumber;
			}
			else
			{
				char szNameP[MAX_STRING] = { 0 };
				sprintf_s(szNameP, "%s(", pEvent->szName);

				if (!_strnicmp(szLine, szNameP, strlen(szNameP)))
				{
					pEvent->pEventFunc = *LineNumber;
				}
			}
			pEvent = pEvent->pNext;
		}
	}

	auto [iter, success] = gMacroBlock->Line.emplace(
		std::piecewise_construct,
		std::forward_as_tuple(*LineNumber),
		std::forward_as_tuple(szLine, FileName, localLine));
	if (!success)
	{
		MacroError("Duplicate line number detected! %s@%d", FileName.c_str(), localLine);
	}

#ifdef MQ2_PROFILING
	iter->second.ExecutionCount = 0;
	iter->second.ExecutionTime = 0;
#endif

	static const std::regex subrx("^sub (\\w+)", std::regex_constants::icase);
	std::cmatch submatch;
	if (std::regex_search(szLine, submatch, subrx))
	{
		gMacroSubLookupMap[submatch.str(1)] = *LineNumber;
	}

	return true;
}

static MQMacroBlockPtr AddMacroBlock(std::string Name)
{
	auto macroBlock = std::make_shared<MQMacroBlock>(Name);
	MacroBlockMap.insert_or_assign(std::move(Name), macroBlock);

	return macroBlock;
}

static void RemoveMacroBlock(std::string Name)
{
	auto iter = MacroBlockMap.find(Name);
	if (iter != MacroBlockMap.end())
	{
		iter->second->Removed = true;
		MacroBlockMap.erase(iter);
	}
}

static MQMacroBlockPtr GetMacroBlock(const char* Name)
{
	auto iter = MacroBlockMap.find(Name);
	if (iter != MacroBlockMap.end())
	{
		return iter->second;
	}

	// If there was no match, but there is a macro block, return that.
	if (!MacroBlockMap.empty())
	{
		return MacroBlockMap.begin()->second;
	}

	return nullptr;
}

MQMacroBlockPtr GetCurrentMacroBlock()
{
	if (!gMacroBlock)
		return nullptr;

	if (!MacroBlockMap.empty())
	{
		if (BlockIndex == 0)
		{
			return MacroBlockMap.begin()->second;
		}

		if (MacroBlockMap.size() > (size_t)BlockIndex)
		{
			auto mbm = MacroBlockMap.begin();
			std::advance(mbm, BlockIndex);
			return mbm->second;
		}

		return MacroBlockMap.begin()->second;
	}

	return nullptr;
}

static MQMacroBlockPtr GetNextMacroBlock()
{
	if (!gMacroBlock)
		return nullptr;

	if (!MacroBlockMap.empty())
	{
		if (MacroBlockMap.size() == 1) // no point in checking this any further.
		{
			return MacroBlockMap.begin()->second;
		}

		if (MacroBlockMap.size() > (size_t)BlockIndex)
		{
			auto mbm = MacroBlockMap.begin();
			std::advance(mbm, BlockIndex);
			BlockIndex++;
			return mbm->second;
		}

		BlockIndex = 0; // time to start over we reached the end
		return  MacroBlockMap.begin()->second;
	}

	return nullptr;
}

void EndAllMacros()
{
	if (MacroBlockMap.empty())
		return;

	// make list of names to end
	std::vector<std::string> names;
	names.reserve(MacroBlockMap.size());

	for (const auto& macroBlock : MacroBlockMap)
	{
		names.push_back(macroBlock.first);
	}

	for (const std::string& name : names)
	{
		EndMacroCommand(nullptr, name.c_str());
	}
}

//
// The else part of the /if
//
static void FailIf(const char* szCommand, int StartLine, bool All = false)
{
	int Scope = 1;

	if (szCommand[strlen(szCommand) - 1] == '{')
	{
		if (!gMacroBlock)
		{
			DebugSpewNoFile("FailIf - Macro was ended before we could handle the false if command");
			return;
		}

		auto lineIter = gMacroBlock->Line.find(StartLine);
		if (lineIter == gMacroBlock->Line.end())
		{
			DebugSpewNoFile("FailIf - Macro was ended before we could handle the false if command");
			return;
		}

		lineIter++; // move it forward once...
		gMacroBlock->CurrIndex = lineIter->first;

		for (; lineIter != gMacroBlock->Line.end() && Scope > 0; lineIter++)
		{
			if (lineIter->second.Command[0] == '}')
				Scope--;

			if (All)
			{
				if (lineIter->second.Command[lineIter->second.Command.size() - 1] == '{')
				{
					Scope++;
				}
			}

			if (Scope > 0)
			{
				if (!All)
				{
					if (lineIter->second.Command[lineIter->second.Command.size() - 1] == '{')
						Scope++;
				}

				if (!_strnicmp(lineIter->second.Command.c_str(), "sub ", 4))
				{
					gMacroBlock->CurrIndex = StartLine;
					FatalError("{} pairing ran into anther subroutine");
					return;
				}

				auto forward = lineIter;
				++forward;

				if (forward == gMacroBlock->Line.end())
				{
					gMacroBlock->CurrIndex = StartLine;
					FatalError("Bad {} block pairing");
					return;
				}

				gMacroBlock->CurrIndex = forward->first;
			}
		}

		lineIter = gMacroBlock->Line.find(gMacroBlock->CurrIndex);
		if (lineIter != gMacroBlock->Line.end())
		{
			auto& currLine = lineIter->second;

			if (!All && (!_strnicmp(currLine.Command.c_str(), "} else ", 7)))
			{
				DoCommand(currLine.Command.substr(7).c_str(), false);
			}
			else if (!All && (!_strnicmp(currLine.Command.c_str(), "} else", 6)))
			{
				FatalError("} else lacks command or {");
				return;
			}
			else
			{
				bRunNextCommand = true;
			}
		}
	}
	else
	{
		bRunNextCommand = true;
	}
}

static void ExecuteLine(const char* szLine)
{
	char szOriginalLine[MAX_STRING] = { 0 };
	strcpy_s(szOriginalLine, szLine);

	// The command we are processing. Alias will be applied.
	char szTheCmd[MAX_STRING] = { 0 };
	strcpy_s(szTheCmd, szLine);

	// The first token of the line
	char szArg1[MAX_STRING] = { 0 };
	GetArg(szArg1, szTheCmd, 1);

	// Perform alias replacement on the command
	if (pCommandAPI->SubstituteAlias(szOriginalLine, szTheCmd, MAX_STRING))
	{
		// We replaced the command, update the first arg.
		GetArg(szArg1, szTheCmd, 1);
	}

	if (szArg1[0] == 0)
		return;

	char szParam[MAX_STRING] = { 0 };
	strcpy_s(szParam, GetNextArg(szTheCmd));

	if (szArg1[0] == ':' || szArg1[0] == '{')
	{
		// skip to next line
		bRunNextCommand = true;
		return;
	}

	if (szArg1[0] == '}')
	{
		MQMacroBlockPtr pBlock = GetCurrentMacroBlock();
		if (pBlock)
		{
			const int loopStart = pBlock->Line.at(pBlock->CurrIndex).LoopStart;
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

			if (pBlock)
			{
				FailIf("{", pBlock->CurrIndex, true);
			}
		}
		else
		{
			bRunNextCommand = true;

			// handle this:
			//     /if () {
			//     } else /echo stuff
			GetArg(szArg1, szTheCmd, 2);
			if (!_stricmp(szArg1, "else"))
			{
				// check here to fail this:
				//     /if () {
				//     } else
				//         /echo stuff
				GetArg(szArg1, szTheCmd, 3);
				if (!_stricmp(szArg1, ""))
				{
					FatalError("no command or { following else");
				}
			}
		}
		return;
	}

	if (pCommandAPI->DoCommandInternal(szOriginalLine, szArg1, szParam))
		return;

	// skip this logic for Bind Commands.
	if (!ci_starts_with(szLine, "sub bind_"))
	{
		if (ci_starts_with(szLine, "sub "))
		{
			FatalError("Flow ran into another subroutine. (%s)", szLine);
			return;
		}

		strcpy_s(szLastCommand, szOriginalLine);
		MacroError("Couldn't parse '%s'", szOriginalLine);
	}
}

static bool DoNextCommand(MQMacroBlockPtr pBlock)
{
	if (!pControlledPlayer || !pLocalPC)
		return false;
	if (!pLocalPlayer)
		return false;

	// Don't process commands until current /face is done
	if (((gFaceAngle != 10000.0f) || (gLookAngle != 10000.0f)) && TurnNotDone)
		return false;

	// Don't process command if we're in the middle of a mouse click.
	if (IsMouseWaiting())
		return false;

	// Check delay condition if it still exists
	if (gDelay && gDelayCondition[0])
	{
		char szCond[MAX_STRING];
		strcpy_s(szCond, gDelayCondition);

		ParseMacroData(szCond, MAX_STRING);

		double Result;
		if (!Calculate(szCond, Result))
		{
			FatalError("Failed to parse /delay condition '%s', non-numeric encountered", szCond);
			return false;
		}

		if (Result != 0)
		{
			DebugSpewNoFile("/delay ending early, conditions met");
			gDelay = 0;
		}
	}

	if (!gDelay                                                // not waiting for a delay
		&& pBlock && !pBlock->Paused                           // not paused
		&& (!gMQPauseOnChat || pEverQuestInfo->KeyboardMode)   // not in chat mode
		&& gMacroStack)                                        // have a stack to process
	{
		const MQMacroLine& ml = pBlock->Line.at(pBlock->CurrIndex);

		if (pBlock->BindStackIndex == pBlock->CurrIndex)
		{
			gBindInProgress = false;
			pBlock->BindStackIndex = -1;
		}

		gMacroStack->LocationIndex = pBlock->CurrIndex;
#ifdef MQ2_PROFILING
		LARGE_INTEGER BeforeCommand;
		QueryPerformanceCounter(&BeforeCommand);
		int ThisMacroBlock = pBlock->CurrIndex;
#endif

		if (gbInZone && !gZoning)
		{
			ExecuteLine(ml.Command.c_str());

			MQMacroBlockPtr pCurrentBlock = GetCurrentMacroBlock();

			if (!pCurrentBlock)
				return false;

			if (!pCurrentBlock->BindCmd.empty() && pCurrentBlock->BindStackIndex == -1)
			{
				// Only trigger queued bind on select commands
				if (ci_find_substr(ml.Command, "/varset") == 0
					|| ci_find_substr(ml.Command, "/echo") == 0
					|| ci_find_substr(ml.Command, "Sub") == 0
					|| ci_find_substr(ml.Command, "/call") == 0
					|| ci_find_substr(ml.Command, "/invoke") == 0)
				{
					auto iter = pCurrentBlock->Line.find(pCurrentBlock->CurrIndex);
					if (iter != pCurrentBlock->Line.end())
					{
						if (++iter != pCurrentBlock->Line.end())
						{
							pCurrentBlock->BindStackIndex = iter->first;
						}
						else
						{
							FatalError("Reached end of macro.");
						}
					}

					Call(pLocalPlayer, (char*)pCurrentBlock->BindCmd.c_str());
					pCurrentBlock->BindCmd.clear();
				}
			}

#ifdef MQ2_PROFILING
			LARGE_INTEGER AfterCommand;
			QueryPerformanceCounter(&AfterCommand);
			pCurrentBlock->Line[ThisMacroBlock].ExecutionCount++;
			pCurrentBlock->Line[ThisMacroBlock].ExecutionTime += AfterCommand.QuadPart - BeforeCommand.QuadPart;
#endif

			const int lastindex = pCurrentBlock->Line.rbegin()->first;
			if (pCurrentBlock->CurrIndex > lastindex)
			{
				FatalError("Reached end of macro.");
			}
			else
			{
				auto iter = pCurrentBlock->Line.find(pCurrentBlock->CurrIndex);
				if (iter != pCurrentBlock->Line.end())
				{
					if (++iter != pCurrentBlock->Line.end())
					{
						pCurrentBlock->CurrIndex = iter->first;
					}
				}
				else
				{
					FatalError("Reached end of macro.");
				}
			}

			s_commandCount++;
			return true;
		}
	}

	return false;
}

#pragma region Data Variables

static void DeleteDataVariable(MQDataVar* pVar)
{
	if (pVar->ppHead == &pMacroVariables || pVar->ppHead == &pGlobalVariables)
		VariableMap.erase(pVar->szName);
	if (pVar->pNext)
		pVar->pNext->pPrev = pVar->pPrev;
	if (pVar->pPrev)
		pVar->pPrev->pNext = pVar->pNext;
	else
		*pVar->ppHead = pVar->pNext;
	pVar->Var.Type->FreeVariable(pVar->Var.VarPtr);
	delete pVar;
}

MQDataVar* FindMacroVariable(const char* Name)
{
	MQDataVar* pFind = nullptr;
	auto it = VariableMap.find(Name);
	if (it != VariableMap.end())
		pFind = it->second;

	if (pFind)
		return pFind;

	// local?
	if (gMacroStack)
	{
		MQDataVar* pVar = gMacroStack->Parameters;
		while (pVar)
		{
			if (!strcmp(pVar->szName, Name))
				return pVar;
			pVar = pVar->pNext;
		}

		pVar = gMacroStack->LocalVariables;
		while (pVar)
		{
			if (!strcmp(pVar->szName, Name))
				return pVar;
			pVar = pVar->pNext;
		}
	}

	return nullptr;
}

bool IsMacroVariable(const char* variableName)
{
	return FindMacroVariable(variableName) != nullptr;
}
static bool InitVariableValue(MQTypeVar& TypeVar, const DefaultValueType& defaultValue)
{
	switch (defaultValue.index())
	{
	case 0: { // const char*
		const char* defaultString = std::get<const char*>(defaultValue);
		if (!defaultString)
			defaultString = "";

		return TypeVar.Type->FromString(TypeVar.VarPtr, defaultString);
	}

	case 1: { // MQTypeVar
		const MQTypeVar& sourceVar = std::get<MQTypeVar>(defaultValue);

		// Check if these types are related.
		MQ2Type* sourceType = sourceVar.Type;
		MQ2Type* destType = TypeVar.Type;

		// If we're assigning from a descendent, then we can attempt to downcast to this type.
		if (sourceType != destType && sourceType->InheritsFrom(destType))
		{
			if (sourceType->Downcast(sourceVar, TypeVar, destType))
				return true;
		}

		return destType->FromData(TypeVar.VarPtr, sourceVar);
	}

	default: break;
	}

	return false;
}

static bool InitArrayValue(const std::shared_ptr<CDataArray>& pArray, const DefaultValueType& defaultValue)
{
	switch (defaultValue.index())
	{
	case 0: { // const char*
		const char* defaultString = std::get<const char*>(defaultValue);
		pArray->Initialize(defaultString);
		return true;
	}

	case 1: { // MQTypeVar
		const MQTypeVar& defaultVar = std::get<MQTypeVar>(defaultValue);
		pArray->Initialize(defaultVar);
		return true;
	}

	default: break;
	}

	return false;
}

static bool AddMQ2DataVariableBy(const char* Name, const char* Index, MQ2Type* pType, MQDataVar** ppHead, const DefaultValueType& defaultValue)
{
	if (!ppHead || !Name[0])
		return false;
	if (!Index)
		Index = "";

	if (IsMacroVariable(Name) || pDataAPI->IsReservedName(Name))
		return false; // name in use
	if (!pType)
		return false;

	// create variable
	MQDataVar* pVar = new MQDataVar;
	pVar->ppHead = ppHead;
	pVar->pNext = *ppHead;
	*ppHead = pVar;
	pVar->pPrev = nullptr;
	if (pVar->pNext)
		pVar->pNext->pPrev = pVar;
	strcpy_s(pVar->szName, Name);

	if (Index[0])
	{
		// Allow for creation of size 0 arrays, but not less (functionality in use)
		if (GetIntFromString(Index, -1) >= 0)
		{
			auto pArray = std::make_shared<CDataArray>(pType, Index);
			pVar->Var.Set(pArray);
			pVar->Var.Type = pArrayType;

			InitArrayValue(pArray, defaultValue);
		}
		else
		{
			return false;
		}
	}
	else
	{
		pVar->Var.Type = pType;
		pType->InitVariable(pVar->Var.VarPtr);

		InitVariableValue(pVar->Var, defaultValue);
	}

	if (!(gMacroStack && (ppHead == &gMacroStack->LocalVariables || ppHead == &gMacroStack->Parameters)))
	{
		VariableMap[Name] = pVar;
	}

	return true;
}

bool AddDataVariable(const char* Name, const char* Index, MQ2Type* pType, MQDataVar** ppHead, const char* Default)
{
	DefaultValueType defaultValue = Default;

	return AddMQ2DataVariableBy(Name, Index, pType, ppHead, defaultValue);
}

MQDataVar** FindVariableScope(const char* Name)
{
	if (!_stricmp(Name, "global"))
		return &pGlobalVariables;

	if (!_stricmp(Name, "outer"))
		return &pMacroVariables;

	if (gMacroStack && !_stricmp(Name, "local"))
		return &gMacroStack->LocalVariables;

	return nullptr;
}

bool DeleteDataVariable(const char* Name)
{
	if (MQDataVar* pVar = FindMacroVariable(Name))
	{
		DeleteDataVariable(pVar);
		return true;
	}

	return false;
}

void ClearDataVariables(MQDataVar** ppHead)
{
	MQDataVar* pVar = *ppHead;
	while (pVar)
	{
		MQDataVar* pNext = pVar->pNext;
		DeleteDataVariable(pVar);

		pVar = pNext;
	}

	*ppHead = nullptr;
}

void PrintMacroDataConversionError(const char* fromType, const char* toType)
{
	WriteChatf("Tried to convert unlike types %s and %s", fromType, toType);

	if (gMacroBlock != nullptr && gMacroBlock->Line.find(gMacroBlock->CurrIndex) != gMacroBlock->Line.end())
	{
		WriteChatf("%s: %d", gMacroBlock->Line.at(gMacroBlock->CurrIndex).SourceFile.c_str(), gMacroBlock->Line.at(gMacroBlock->CurrIndex).LineNumber);
	}

	if (gMacroStack != nullptr)
	{
		char buf[MAX_STRING];
		WriteChatf("%s", GetMacroSubFromLine(gMacroStack->LocationIndex, buf, MAX_STRING));
	}
}

#pragma endregion

#pragma region Events

static bool AddEventVariable(const char* Name, const char* Index, MQ2Type* pType, MQDataVar** ppHead, const DefaultValueType& defaultValue)
{
	if (!ppHead || !Name[0])
		return false;
	if (!Index)
		Index = "";

	// Make sure that the name isn't already in use.
	if (pDataAPI->FindTopLevelObject(Name) != nullptr || pDataAPI->FindDataType(Name) != nullptr)
		return false;
	if (!pType)
		return false;

	// create variable
	MQDataVar* pVar = new MQDataVar;
	pVar->ppHead = ppHead;
	pVar->pNext = *ppHead;
	*ppHead = pVar;
	pVar->pPrev = nullptr;
	if (pVar->pNext)
		pVar->pNext->pPrev = pVar;
	strcpy_s(pVar->szName, Name);

	if (Index[0])
	{
		auto pArray = std::make_shared<datatypes::CDataArray>(pType, Index);
		pVar->Var.Set(pArray);
		pVar->Var.Type = datatypes::pArrayType;

		InitArrayValue(pArray, defaultValue);
	}
	else
	{
		pVar->Var.Type = pType;
		pType->InitVariable(pVar->Var.VarPtr);

		InitVariableValue(pVar->Var, defaultValue);
	}

	if (pVar->ppHead == &pMacroVariables || pVar->ppHead == &pGlobalVariables)
	{
		VariableMap[Name] = pVar;
	}

	return true;
}

static void CALLBACK EventBlechCallback(unsigned int ID, void* pData, PBLECHVALUE pValues)
{
	DebugSpew("EventBlechCallback(%d,%X,%X) msg='%s'", ID, pData, pValues, EventMsg);

	MQEventList* pEList = static_cast<MQEventList*>(pData);

	if (!pEList->pEventFunc)
	{
		DebugSpew("EventBlechCallback() -- pEventFunc is NULL, cannot call event sub");
		return;
	}

	MQEventQueue* pEvent = new MQEventQueue();
	if (!pEvent)
		return;

	ZeroMemory(pEvent, sizeof(MQEventQueue));
	pEvent->Type = EVENT_CUSTOM;
	pEvent->pEventList = pEList;
	char szParamName[MAX_STRING] = { 0 };
	char szParamType[MAX_STRING] = { 0 };

	auto eventIter = gMacroBlock->Line.find(pEList->pEventFunc);
	if (eventIter != gMacroBlock->Line.end())
	{
		GetFuncParam(&eventIter->second.Command[0], 0, szParamName, MAX_STRING, szParamType, MAX_STRING);
	}

	MQ2Type* pType = pDataAPI->FindDataType(szParamType);
	if (!pType)
		pType = datatypes::pStringType;

	AddEventVariable(szParamName, "", pType, &pEvent->Parameters, EventMsg);

	while (pValues)
	{
		if (pValues->Name[0] != '*')
		{
			auto eventIter2 = gMacroBlock->Line.find(pEList->pEventFunc);
			if (eventIter2 != gMacroBlock->Line.end())
			{
				GetFuncParam(&eventIter2->second.Command[0], GetIntFromString(pValues->Name, 0), szParamName, MAX_STRING, szParamType, MAX_STRING);
			}

			MQ2Type* pType2 = pDataAPI->FindDataType(szParamType);
			if (!pType2)
				pType2 = datatypes::pStringType;

			AddEventVariable(szParamName, "", pType2, &pEvent->Parameters, pValues->Value.c_str());
		}

		pValues = pValues->pNext;
	}

	if (!gEventQueue)
	{
		gEventQueue = pEvent;
	}
	else
	{
		MQEventQueue* pTemp;
		for (pTemp = gEventQueue; pTemp->pNext; pTemp = pTemp->pNext) {}
		pTemp->pNext = pEvent;
		pEvent->pPrev = pTemp;
	}
}

static void AddEvent(MQEventType Event, const char* FirstArg, ...)
{
	if (!gEventFunc[Event])
		return;

	// this is deleted in 2 locations DoEvents and EndMacro
	DebugSpewNoFile("Adding Event %d %s", Event, FirstArg);

	MQEventQueue* pEvent = new MQEventQueue();
	pEvent->Name = FirstArg;
	pEvent->Type = Event;

	if (FirstArg)
	{
		va_list marker;
		int i = 0;

		const char* CurrentArg = FirstArg;
		va_start(marker, FirstArg);

		while (CurrentArg)
		{
			char szParamName[MAX_STRING] = { 0 };
			char szParamType[MAX_STRING] = { 0 };
			int index = gEventFunc[Event];

			auto iter = gMacroBlock->Line.find(index);
			if (iter != gMacroBlock->Line.end())
			{
				MQMacroLine& line = iter->second;

				GetFuncParam(&line.Command[0], i, szParamName, MAX_STRING, szParamType, MAX_STRING);

				MQ2Type* pType = pDataAPI->FindDataType(szParamType);
				if (!pType)
					pType = datatypes::pStringType;

				AddEventVariable(szParamName, "", pType, &pEvent->Parameters, CurrentArg);
				i++;
				CurrentArg = va_arg(marker, const char*);
			}
		}
		va_end(marker);
	}

	if (!gEventQueue)
	{
		gEventQueue = pEvent;
	}
	else
	{
		MQEventQueue* pTemp;
		for (pTemp = gEventQueue; pTemp->pNext; pTemp = pTemp->pNext) {}
		pTemp->pNext = pEvent;
		pEvent->pPrev = pTemp;
	}
}

static unsigned int CALLBACK MQ2DataVariableLookup(char* VarName, char* Value, size_t ValueLen)
{
	strcpy_s(Value, ValueLen, VarName);

	if (pLocalPlayer)
	{
		return static_cast<uint32_t>(strlen(ParseMacroParameter(Value, ValueLen)));
	}

	return static_cast<uint32_t>(strlen(Value));
}

static void CheckChatForEvent(const char* szClean)
{
	MQMacroBlockPtr pBlock = GetCurrentMacroBlock();
	if ((pBlock && !pBlock->Line.empty()) && (!pBlock->Paused) && (!gbUnload) && (!gZoning))
	{
		char Content[MAX_STRING] = { 0 };
		char Channel[MAX_STRING] = { 0 };
		const char* pDest = nullptr;

		int StartCopyAt = 0;

		if (CHATEVENT(CHAT_GUILD) && ((pDest = strstr(szClean, " tells the guild, "))))
		{
			strcpy_s(Channel, "guild");
		}
		else if (CHATEVENT(CHAT_GROUP) && ((pDest = strstr(szClean, " tells the group, "))))
		{
			strcpy_s(Channel, "group");
		}
		else if (CHATEVENT(CHAT_TELL) && ((pDest = strstr(szClean, " tells you, "))))
		{
			strcpy_s(Channel, "tell");
		}
		else if (CHATEVENT(CHAT_TELL) && ((pDest = strstr(szClean, " told you, "))))
		{
			strcpy_s(Channel, "tell");
		}
		// Cannot be said in another language, so we can match through the single quote here
		else if (CHATEVENT(CHAT_OOC) && ((pDest = strstr(szClean, " says out of character, '"))))
		{
			strcpy_s(Channel, "ooc");
		}
		else if (CHATEVENT(CHAT_SHOUT) && ((pDest = strstr(szClean, " shouts, "))))
		{
			strcpy_s(Channel, "shout");
		}
		else if (CHATEVENT(CHAT_AUC) && ((pDest = strstr(szClean, " auctions, "))))
		{
			strcpy_s(Channel, "auc");
		}
		// What scenario misses the comma?  This is the only reason we require the StartCopyAt check
		else if (CHATEVENT(CHAT_SAY) && ((pDest = strstr(szClean, " says '"))))
		{
			StartCopyAt = 7;
			strcpy_s(Channel, "say");
		}
		else if (CHATEVENT(CHAT_SAY) && ((pDest = strstr(szClean, " says, "))))
		{
			strcpy_s(Channel, "say");
		}
		else if (CHATEVENT(CHAT_RAID) && ((pDest = strstr(szClean, " tells the raid, "))))
		{
			strcpy_s(Channel, "raid");
		}
		else if (CHATEVENT(CHAT_CHAT)
			&& strstr(szClean, "You told ") == nullptr
			&& ((pDest = strstr(szClean, " tells ")))
			&& strstr(szClean, ":")
			&& strstr(szClean, ", '"))
		{
			strcpy_s(Channel, pDest + 7);
			Channel[strlen(Channel) - 1] = 0;

			if (const char* colPos = strstr(Channel, ":"))
			{
				Channel[colPos - Channel] = 0;
			}
		}

		if (pDest != nullptr)
		{
			char SpeakerName[MAX_STRING] = { 0 };
			strncpy_s(SpeakerName, szClean, pDest - szClean);
			if (StartCopyAt == 0)
			{
				// Almost all strings have , ' in them to denote the starting text
				StartCopyAt = find_substr(pDest, ", '");
				if (StartCopyAt != -1)
				{
					StartCopyAt += 3;
				}
				else
				{
					// (SPAM) will not have this, so fall back to comma space
					StartCopyAt = find_substr(pDest, ", ");
					if (StartCopyAt != -1)
					{
						StartCopyAt += 2;
					}
				}
				// If StartCopyAt is still not found, just give the whole thing
				if (StartCopyAt < 0)
				{
					StartCopyAt = 0;
				}
			}
			strcpy_s(Content, pDest + StartCopyAt);
			// Only strip the last character if it is the closing quote that was expected
			const size_t lastChar = strlen(Content) - 1;
			if (Content[lastChar] == '\'')
			{
				Content[lastChar] = 0;
			}
			AddEvent(EVENT_CHAT, Channel, SpeakerName, Content, NULL);
		}

		strncpy_s(EventMsg, szClean, MAX_STRING - 1);
		EventMsg[MAX_STRING - 1] = 0;
		pEventBlech->Feed(EventMsg);
		EventMsg[0] = '\0';
	}
}
#pragma endregion

#pragma region Timers

void DropTimers()
{
	MQTimer* pTimer = gTimer;

	while (pTimer)
	{
		if (pTimer->Current)
		{
			pTimer->Current--;
			if (!pTimer->Current)
			{
				char szOrig[32];
				_itoa_s(pTimer->Original, szOrig, 10);

				AddEvent(EVENT_TIMER, pTimer->Name.c_str(), szOrig, NULL);
			}
		}
		pTimer = pTimer->pNext;
	}
}

#pragma endregion

#pragma region Macro Profiler

ProfileSession* g_pProfile = nullptr;

StackFrame::StackFrame(std::string subroutine, std::vector<std::string> arguments)
	: m_subroutine(std::move(subroutine))
	, m_args(std::move(arguments))
	, m_startTime(std::chrono::high_resolution_clock::now())
	, m_startCommandCount(s_commandCount)
	, m_endCommandCount(0)
{
}

void StackFrame::AddChild(std::unique_ptr<StackFrame> child)
{
	m_children.push_back(std::move(child));
}

void StackFrame::End(std::string returnValue)
{
	m_endTime = std::chrono::high_resolution_clock::now();
	m_endCommandCount = s_commandCount;

	m_returnValue = std::move(returnValue);
	m_returned = true;
}

std::string StackFrame::format_csv(int depth, std::chrono::high_resolution_clock::time_point beginTime) const
{
	fmt::memory_buffer mem;
	fmt::appender buffer(mem);

	format_csv(buffer, depth, beginTime);

	return fmt::to_string(mem);
}

void StackFrame::format_csv(fmt::appender& buffer, int depth, std::chrono::high_resolution_clock::time_point beginTime) const
{
	fmt::format_to(buffer, "{},{},{},{},",
		m_startCommandCount,
		std::chrono::duration_cast<std::chrono::microseconds>(m_startTime - beginTime).count() / 1000000.0,
		depth,
		m_subroutine);

	for (int i = 1; i < depth; i++)
		fmt::format_to(buffer, "  ");

	fmt::format_to(buffer, "{},{},{},{},{},{},\"{}\",",
		m_subroutine,
		GetCommandCountInclusive(),
		GetCommandCountExclusive(),
		GetMicrosecondsInclusive().count() / 1000.0f,
		GetMicrosecondsExclusive().count() / 1000.0f,
		m_children.size(),
		m_returnValue);
	format_args(buffer, m_args);
	fmt::format_to(buffer, "\n");

	for (const std::unique_ptr<StackFrame>& child : m_children)
		child->format_csv(buffer, depth + 1, beginTime);
}

//-------------------------------------------------------------------------------------------------

ProfileSession::ProfileSession(std::string name)
	: m_name(std::move(name))
	, m_startTime(std::chrono::high_resolution_clock::now())
{
}

void ProfileSession::Call(std::string subroutine, std::vector<std::string> args)
{
	m_callStack.emplace_back(new StackFrame(std::move(subroutine), std::move(args)));
}

void ProfileSession::Return(std::string returnValue)
{
	if (m_callStack.empty())
		return;

	// End the current stack frame, and add it to the parent's children.
	std::unique_ptr<StackFrame>& top = m_callStack.back();
	top->End(std::move(returnValue));

	if (m_callStack.size() > 1)
	{
		m_callStack[m_callStack.size() - 2]->AddChild(std::move(top));
		m_callStack.pop_back();
	}
}

void ProfileSession::End()
{
	while (m_callStack.size() > 1)
		Return("#N/A");

	m_callStack.back()->End("#N/A");
}

std::string ProfileSession::to_string() const
{
	fmt::memory_buffer mem;
	fmt::appender buf(mem);

	fmt::format_to(buf, "Command Count,Seconds Since Start,Stack Depth,Subroutine,Subroutine (tabbed),Commands (inc Children),Commands (ex Children),ms inc, ms ex,Called Children,Return Value,Arguments\n");

	if (m_callStack.size() == 1)
		m_callStack.back()->format_csv(buf, 1, m_startTime);

	return fmt::to_string(mem);
}

#pragma endregion

//=================================================================================================

#pragma region Commands

// ***************************************************************************
// Function:    Break
// Description: Our '/break' command
// Usage:       /break
// ***************************************************************************
static void Break(PlayerClient*, const char*)
{
	if (!gMacroBlock)
	{
		MacroError("Can only use /break during a macro.");
		return;
	}

	auto size = gMacroStack->loopStack.size();
	if (size == 0)
	{
		FatalError("/break without matching /for or /while block");
		return;
	}

	auto& loop = gMacroStack->loopStack[size - 1];
	if (loop.lastLine) // takes care of /while and /for after 1st /next encountered
	{
		gMacroBlock->CurrIndex = loop.lastLine;
		PopMacroLoop();
		return;
	}

	auto i = gMacroBlock->Line.find(gMacroBlock->CurrIndex);
	while (++i != gMacroBlock->Line.end())
	{
		const char* line = i->second.Command.c_str();
		if (!_strnicmp(line, "/next", 5))
		{
			char for_var[MAX_STRING];

			GetArg(for_var, line, 2);

			if (_stricmp(for_var, loop.forVariable.c_str()))
				continue;

			gMacroBlock->CurrIndex = i->first;
			loop.lastLine = i->first;;
			PopMacroLoop();

			return;
		}
		if (!_strnicmp(line, "Sub ", 4))
		{
			break;
		}
	}

	FatalError("/break without matching /for ... /next (or while) block");
}

// ***************************************************************************
// Function:    Call
// Description: Our '/call' command
// Usage:       /call <Subroutine>
// ***************************************************************************
static void Call(PlayerClient*, const char* szLine)
{
	if (szLine[0] == 0)
	{
		SyntaxError("Usage: /call <subroutine> [param [param...]]");
		return;
	}

	if (!gMacroBlock || (gMacroBlock && gMacroBlock->Line.empty()))
	{
		MacroError("Cannot call when a macro isn't running.");
		return;
	}

	bRunNextCommand = true;

	char SubName[MAX_STRING];
	GetArg(SubName, szLine, 1);
	const char* SubParam = GetNextArg(szLine);

	// Sub in Map?
	auto iter = gMacroSubLookupMap.find(SubName);
	if (iter == gMacroSubLookupMap.end())
	{
		FatalError("Subroutine %s wasn't found", SubName);
		return;
	}

	int MacroLine = iter->second;

	// Prep to call the Sub
	MQMacroStack* pStack = new MQMacroStack(MacroLine);

	gMacroBlock->CurrIndex = MacroLine;
	if (gMacroStack && gMacroBlock->BindStackIndex != -1)
	{
		// we need to check the stackchain now for the start of the bind
		MQMacroStack* pBindStack = gMacroStack;
		bool bBindStackFound = false;

		while (pBindStack)
		{
			if (pBindStack->bIsBind == true)
			{
				bBindStackFound = true;
				break;
			}

			pBindStack = pBindStack->pNext;
		}

		if (!bBindStackFound)
		{
			pStack->bIsBind = true;
		}
	}

	pStack->pNext = gMacroStack;
	gMacroStack = pStack;

	MQMacroLine& ml = gMacroBlock->Line.at(MacroLine);
	int numsubargs = GetNumArgsFromSub(ml.Command);

	if (SubParam[0] != 0 || numsubargs)
	{
		// FIXME: These don't need to all be 2k bytes long...
		char szParamName[MAX_STRING] = { 0 };
		char szParamType[MAX_STRING] = { 0 };
		char szNewValue[MAX_STRING] = { 0 };
		auto name = &ml.Command[0];

		for (int StackNum = 0; StackNum < numsubargs || SubParam[0] != '\0'; StackNum++)
		{
			GetArg(szNewValue, SubParam, 1);

			GetFuncParam(name, StackNum, szParamName, MAX_STRING, szParamType, MAX_STRING);

			MQ2Type* pType = pDataAPI->FindDataType(szParamType);
			if (!pType)
				pType = datatypes::pStringType;

			AddDataVariable(szParamName, "", pType, &gMacroStack->Parameters, szNewValue);
			SubParam = GetNextArg(SubParam);
		}
	}

	if (g_pProfile)
	{
		std::string subroutine;
		std::vector<std::string> args = ArgsToVector(szLine);

		g_pProfile->Call(SubName, std::move(args));
	}
}

// ***************************************************************************
// Function:    Continue
// Description: Our '/continue' command
// Usage:       /continue
// ***************************************************************************
static void Continue(PlayerClient*, const char*)
{
	if (!gMacroBlock)
	{
		MacroError("Can only use /continue during a macro.");
		return;
	}

	const auto size = gMacroStack->loopStack.size();
	if (size == 0)
	{
		FatalError("/continue without matching /for or /while block");
		return;
	}

	auto& loop = gMacroStack->loopStack[size - 1];
	if (loop.type == MQLoop::Type::While)
	{
		gMacroBlock->CurrIndex = loop.firstLine;
		return;
	}
	else if (loop.lastLine) // /for after 1st /next encountered
	{
		auto i = gMacroBlock->Line.find(loop.lastLine);
		--i;
		gMacroBlock->CurrIndex = i->first;
		return;
	}

	auto i = gMacroBlock->Line.find(gMacroBlock->CurrIndex);
	while (++i != gMacroBlock->Line.end())
	{
		const char* line = i->second.Command.c_str();
		if (!_strnicmp(line, "/next", 5))
		{
			char for_var[MAX_STRING];

			GetArg(for_var, line, 2);

			if (_stricmp(for_var, loop.forVariable.c_str()))
				continue;

			loop.lastLine = i->first;
			--i;

			gMacroBlock->CurrIndex = i->first;
			return;
		}

		if (!_strnicmp(line, "Sub ", 4))
		{
			break;
		}
	}

	FatalError("/continue without matching /for ... /next block");
}

// ***************************************************************************
// Function:    DeclareVar
// Description: Our '/declare' command
// Usage:       /declare <varname|varname[array extents]> [type] [global|outer|local|bind] [default value]
// ***************************************************************************
static void DeclareVar(PlayerClient*, const char* szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /declare <varname|varname[array extents]> [type] [global|outer|local|bind] [default value]");
		return;
	}

	MQ2Type* pType = nullptr;

	char szIndex[MAX_STRING] = { 0 };
	char szName[MAX_STRING] = { 0 };
	GetArg(szName, szLine, 1);
	char Arg[MAX_STRING] = { 0 };
	GetArg(Arg, szLine, 2);

	MQDataVar** pScope = FindVariableScope(Arg);
	const char* pDefault;

	if (pScope)
	{
		// scope comes AFTER type, so next must be default
		pDefault = GetNextArg(szLine, 2);
	}
	else if ((pType = pDataAPI->FindDataType(Arg)))
	{
		// next is either scope or default
		GetArg(Arg, szLine, 3);

		if ((pScope = FindVariableScope(Arg)))
		{
			// next is default
			pDefault = GetNextArg(szLine, 3);
		}
		else
		{
			// this is default
			pDefault = GetNextArg(szLine, 2);
		}
	}
	else
	{
		// this is default
		pDefault = GetNextArg(szLine);
	}

	if (!pScope)
	{
		if (gMacroStack)
		{
			pScope = &gMacroStack->LocalVariables;
		}
		else
		{
			MacroError("/declare '%s' failed.  No macro in execution and variable scope invalid: %s", szName, Arg[0] != '\0' ? Arg : "NULL");
			return;
		}
	}

	if (!pType)
		pType = pStringType;
	if (pType == pArrayType)
	{
		MacroError("/declare array failed.  To declare an array use: /declare name[size] <type> <scope> <default element value>");
		MacroError("Example: /declare MyStringArray[25] string local ARRAY-UNDEFINED-ELEMENT");
		return;
	}

	bool hasArrayIndex = false;
	if (char* pBracket = strchr(szName, '['))
	{
		*pBracket = 0;
		strcpy_s(szIndex, &pBracket[1]);
		szIndex[strlen(szIndex) - 1] = 0;
		hasArrayIndex = true;
	}

	if (pType == pTimerType && szIndex[0])
	{
		MacroError("Cannot /declare an array of timers");
		return;
	}

	if (!AddDataVariable(szName, szIndex, pType, pScope, pDefault))
	{
		if (hasArrayIndex)
		{
			MacroError("/declare '%s' failed.  Name already in use or array index invalid: %s", szName, szIndex);
		}
		else
		{
			MacroError("/declare '%s' failed.  Name already in use.", szName);
		}
	}
	else
	{
		if (pType == pTimerType)
		{
			MQTimer* pTimer = static_cast<MQTimer*>((*pScope)->Var.Ptr);
			pTimer->Name = szName;
		}
	}
}

// ***************************************************************************
// Function:    DeleteVarCmd
// Description: Our '/deletevar' command
// Usage:       /deletevar <varname|* global>
// ***************************************************************************
static void DeleteVarCmd(PlayerClient*, const char* szLine)
{
	if (szLine[0] == 0)
	{
		SyntaxError("Usage: /deletevar <varname|* global>");
	}
	else
	{
		// destroy old variable
		if (!DeleteDataVariable(szLine))
		{
			if (!_strnicmp(szLine, "* global", 8))
			{
				ClearDataVariables(&pGlobalVariables);
			}
			else
			{
				MacroError("Variable '%s' does not exist", szLine);
			}
		}
	}
}

// ***************************************************************************
// Function:    DoCommandCmd
// Description: Our '/docommand' command
// Usage:       /docommand <command>
// ***************************************************************************
static void DoCommandCmd(PlayerClient*, const char* szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /docommand <command>");
		return;
	}

	DoCommand(szLine, false);
}

// ***************************************************************************
// Function:    DoEvents
// Description: Our '/doevents' command
// Usage:       /doevents [flush] [custom event]
// ***************************************************************************
static void DoEvents(PlayerClient*, const char* szLine)
{
	if (!gEventQueue || !gMacroStack)
		return;

	char Arg1[MAX_STRING] = { 0 };
	GetArg(Arg1, szLine, 1);

	if (!_stricmp(Arg1, "flush"))
	{
		char Arg2[MAX_STRING] = { 0 };
		GetArg(Arg2, szLine, 2);

		if (Arg2[0])
		{
			char szSub[64] = { 0 };
			sprintf_s(szSub, "Sub Event_%s", Arg2);
			MQEventQueue* pEvent = gEventQueue;

			while (pEvent)
			{
				if ((pEvent->Type == EVENT_CHAT && !_stricmp("Sub Event_Chat", szSub))
					|| (pEvent->Type == EVENT_TIMER && !_stricmp("Sub Event_Timer", szSub))
					|| (pEvent->Type == EVENT_CUSTOM && !_stricmp(pEvent->pEventList->szName, szSub)))
				{
					MQEventQueue* pEventNext;
					if (pEventNext = pEvent->pNext)
						pEventNext->pPrev = pEvent->pPrev;
					if (pEvent->pPrev)
						pEvent->pPrev->pNext = pEvent->pNext;
					else
						gEventQueue = pEvent->pNext;

					ClearDataVariables(&pEvent->Parameters);
					DebugSpewNoFile("Doevents: Deleting pEvent %d %s", pEvent->Type, pEvent->Name.c_str());

					delete pEvent;
					pEvent = pEventNext;

					continue;
				}

				pEvent = pEvent->pNext;
			}
		}
		else
		{
			while (gEventQueue)
			{
				MQEventQueue* pEventNext = gEventQueue->pNext;

				ClearDataVariables(&gEventQueue->Parameters);
				DebugSpewNoFile("Doevents: Deleting gEventQueue %d %s", gEventQueue->Type, gEventQueue->Name.c_str());

				delete gEventQueue;
				gEventQueue = pEventNext;
			}
		}
		return;
	}

	if (gMacroBlock->BindStackIndex != -1)
	{
		// we need to return if this happens cause if we run an event
		// while a bind is running we screw up the macro stack... -eqmule
		return;
	}

	MQEventQueue* pEvent = gEventQueue;
	if (Arg1[0])
	{
		char szSub[64] = { 0 };
		sprintf_s(szSub, "Sub Event_%s", Arg1);

		while (pEvent)
		{
			if ((pEvent->Type == EVENT_CHAT && !_stricmp("Sub Event_Chat", szSub))
				|| (pEvent->Type == EVENT_TIMER && !_stricmp("Sub Event_Timer", szSub))
				|| (pEvent->Type == EVENT_CUSTOM && !_stricmp(pEvent->pEventList->szName, szSub)))
			{
				break;
			}

			pEvent = pEvent->pNext;
		}

		if (!pEvent)
			return;// no event found
	}

	if (pEvent->pPrev)
		pEvent->pPrev->pNext = pEvent->pNext;
	else
		gEventQueue = pEvent->pNext;
	if (pEvent->pNext)
		pEvent->pNext->pPrev = pEvent->pPrev;

	DebugSpewNoFile("DoEvents: Running event type %d (%s) = 0x%p", pEvent->Type, (pEvent->pEventList) ? pEvent->pEventList->szName : "NONE", pEvent);

	// back the current location to previous one so we fall into
	// /doevents again.

	int locationIndex = 0;
	auto lineIter = gMacroBlock->Line.find(gMacroBlock->CurrIndex);
	if (lineIter != gMacroBlock->Line.end())
	{
		lineIter--;
		locationIndex = lineIter->first;
	}

	MQMacroStack* pStack = new MQMacroStack(locationIndex);
	pStack->Parameters = pEvent->Parameters;

	MQDataVar* pParam = pStack->Parameters;
	while (pParam) // FIX THE HEAD ON EVERY VAR WE MOVED
	{
		pParam->ppHead = &pStack->Parameters;
		pParam = pParam->pNext;
	}
	pStack->pNext = gMacroStack;
	gMacroStack = pStack;

	if (pEvent->Type == EVENT_CUSTOM && pEvent->pEventList)
	{
		gMacroBlock->CurrIndex = pEvent->pEventList->pEventFunc;
	}
	else
	{
		gMacroBlock->CurrIndex = gEventFunc[pEvent->Type];
	}

	DebugSpewNoFile("DoEvents - Deleted event: %d %s", pEvent->Type, pEvent->Name.c_str());

	delete pEvent;
	bRunNextCommand = true;

	if (g_pProfile)
	{
		std::string eventName;

		switch (pEvent->Type)
		{
		case EVENT_CHAT:
			eventName = "Event_Chat";
			break;
		case EVENT_TIMER:
			eventName = "Event_Timer";
			break;
		case EVENT_CUSTOM:
			if (pEvent->pEventList)
			{
				std::string_view sv = pEvent->pEventList->szName;
				if (ci_starts_with(sv, "Sub "))
				{
					eventName = sv.substr(4);
					break;
				}
			}
			// fallthrough
		default:
			eventName = fmt::format("** Unknown Event ({}) **", locationIndex);
			break;
		}

		MQDataVar* parameters = gMacroStack->Parameters;
		std::vector<std::string> args;
		char szArg[MAX_STRING] = { 0 };

		while (parameters)
		{
			if (parameters->Var.Type->ToString(pParam->Var.VarPtr, szArg))
				args.emplace_back(szArg);
			else
				args.emplace_back("NULL");

			parameters = parameters->pNext;
		}

		g_pProfile->Call(std::move(eventName), std::move(args));
	}
}

// ***************************************************************************
// Function:    DumpStack
// Description: Our '/dumpstack' command
// Usage:       /dumpstack
// ***************************************************************************
static void DumpStack(PlayerClient*, const char*)
{
	char szSub[MAX_STRING] = { 0 };

	MQMacroStack* pMS = gMacroStack;
	while (pMS != nullptr)
	{
		const MQMacroLine* ml = nullptr;

		auto lineIter = gMacroBlock->Line.find(pMS->LocationIndex);

		if (lineIter != gMacroBlock->Line.end())
		{
			ml = &lineIter->second;
		}

		char szTemp[MAX_STRING] = { 0 };

		if (ml)
		{
			sprintf_s(szTemp, "%s@%d (%s): %s",
				ml->SourceFile.c_str(),
				ml->LineNumber,
				GetMacroSubFromLine(pMS->LocationIndex, szSub, MAX_STRING),
				ml->Command.c_str());
		}
		else
		{
			sprintf_s(szTemp, "??? (%s): ???", GetMacroSubFromLine(pMS->LocationIndex, szSub, MAX_STRING));
		}

		WriteChatColor(szTemp);

		if (bAllErrorsLog)
			MacroLog(szTemp);

		pMS = pMS->pNext;
	}
}

// ***************************************************************************
// Function:    EndMacro
// Description: Our '/endmacro' command
// Usage:       /endmacro
// ***************************************************************************
void EndMacroCommand(PlayerClient*, const char* szLine)
{
	char szArg1[MAX_STRING] = { 0 };
	char MacroName[MAX_STRING] = { 0 };

	// FIXME:  Assuming this is for multiple macros, it wouldn't work for a macro
	// named "keep" -- see "keep keys" below for that argument information.
	GetArg(szArg1, szLine, 1);
	if (szArg1[0] != '\0')
	{
		if (_stricmp(szArg1, "keep"))
		{
			strcpy_s(MacroName, szArg1);
		}
	}

	gWarning = false;
	MQMacroStack* pStack = nullptr;
	MQEventQueue* pEvent = nullptr;
	MQEventList* pEventL = nullptr;
	MQBindList* pBindL = nullptr;

	MQMacroBlockPtr pBlock = GetMacroBlock(MacroName);
	if (!pBlock)
	{
		MacroError("Cannot end a macro when one isn't running.");
		return;
	}

	// Regardless of the passed name, the MacroName we're ending is whatever
	// was returned from the GetMacroBlock
	strcpy_s(MacroName, pBlock->Name.c_str());

	if (!gbUnload)
	{
		// Code allowing for a routine for "OnExit"
		for (auto i = pBlock->Line.begin(); i != pBlock->Line.end(); ++i)
		{
			if (!_strnicmp(i->second.Command.c_str(), ":OnExit", 7))
			{
				pBlock->CurrIndex = i->first;
				// Force unpause to finish processing
				pBlock->Paused = false;
				// Return to the macro the first time around
				if (gReturn)
				{
					// While there are more items in the global macro stack
					while (gMacroStack->pNext)
					{
						if (gMacroStack->LocalVariables)
							ClearDataVariables(&gMacroStack->LocalVariables);
						if (gMacroStack->Parameters)
							ClearDataVariables(&gMacroStack->Parameters);

						// Save the next pointer before deleting the current stack item
						MQMacroStack* pNext = gMacroStack->pNext;

						// Delete the current stack item
						delete gMacroStack;

						// Move to the next item in the stack
						gMacroStack = pNext;
					}

					// We don't want to return the 2nd time
					gReturn = false;
					return;
				}

				break;
			}
		}
	}

	// Set the parser back to whatever the default is
	const int iTemp = GetPrivateProfileInt("MacroQuest", "ParserEngine", 1, mq::internal_paths::MQini);
	if (iTemp != gParserVersion)
	{
		gParserVersion = iTemp;
		WriteChatColor("Parser Version Reset to your default", USERCOLOR_DEFAULT);
	}

	// reset for next time
	gReturn = true;

#ifdef MQ2_PROFILING
	// How many performance counters in 1 second?
	LARGE_INTEGER PerformanceFrequency;
	QueryPerformanceCounter(&PerformanceFrequency);

	char Filename[MAX_STRING] = { 0 };
	FILE* fMacro = NULL;
	for (auto i = pBlock->Line.begin(); i != pBlock->Line.end(); i++) {
		// Is this a different macro file?
		if (strcmp(Filename, i->second.SourceFile.c_str())) {
			// Close existing file
			if (fMacro) {
				fclose(fMacro);
			}
			// Open new profiling log file
			strcpy_s(Filename, i->second.SourceFile.c_str());
			sprintf_s(Buffer, "%s\\%s.mqp", gszMacroPath, Filename);
			fMacro = _fsopen(Buffer, "w", _SH_DENYWR);
			if (fMacro) {
				fprintf(fMacro, " Execute |  Total   | Avg uSec | Line | Macro Source Code\n");
				fprintf(fMacro, " Count   |   uSec   | Per 1000 |\n");
				fprintf(fMacro, "------------------------------------------------------------------------------------------------------------- \n");
			}
		}

		// Log execution/profiling information.  Output format is:
		// Execution Count | Microseconds | Line # | Macro Source
		if (fMacro) {
			DWORD count = i->second.ExecutionCount;
			DWORD total = (DWORD)(i->second.ExecutionTime * 1000000 / PerformanceFrequency.QuadPart);
			DWORD avg = 0;
			if (count > 0) {
				avg = total * 1000 / count;
			}
			fprintf(fMacro, "%8lu | %8lu | %8lu | %4lu | %s\n",
				count,
				total,
				avg,
				i->second.LineNumber,
				i->second.Command.c_str());
		}
	}
	// Close existing file
	if (fMacro) {
		fclose(fMacro);
	}
#endif

	RemoveMacroBlock(pBlock->Name);

	gMacroBlock = nullptr;
	while (gMacroStack)
	{
		pStack = gMacroStack->pNext;

		if (gMacroStack->LocalVariables)
			ClearDataVariables(&gMacroStack->LocalVariables);

		if (gMacroStack->Parameters)
			ClearDataVariables(&gMacroStack->Parameters);

		delete gMacroStack;
		gMacroStack = pStack;
	}

	gMacroSubLookupMap.clear();
	gUndeclaredVars.clear();

	while (gEventQueue)
	{
		pEvent = gEventQueue->pNext;
		delete gEventQueue;

		gEventQueue = pEvent;
	}

	while (pEventList)
	{
		pEventL = pEventList->pNext;
		delete pEventList;

		pEventList = pEventL;
	}

	while (pBindList)
	{
		pBindL = pBindList->pNext;
		delete pBindList;

		pBindList = pBindL;
	}

	pEventBlech->Reset();

	for (int& i : gEventFunc)
	{
		i = 0;
	}

	gEventChat = 0;
	gFaceAngle = 10000.0f;
	gLookAngle = 10000.0f;
	gDelay = 0;
	gTurbo = false;
	SetSwitchTarget(nullptr);
	gszMacroName[0] = 0;
	gRunning = 0;

	// Remove the keypresses unless the user specified to keep them
	if (!(gKeepKeys || ci_find_substr(szLine, "keep keys") != -1))
	{
		KeyCombo TempCombo;
		for (int i = 0; gDiKeyID[i].szName[0]; i++)
		{
			TempCombo.Data[3] = (unsigned char)gDiKeyID[i].Id;
			MQ2HandleKeyUp(TempCombo);
		}
	}

	ClearDataVariables(&pMacroVariables);

	DebugSpewNoFile("EndMacro - Ended");
	if (gFilterMacro != FILTERMACRO_NONE && gFilterMacro != FILTERMACRO_MACROENDED)
		WriteChatColor("The current macro has ended.", USERCOLOR_DEFAULT);

	g_mq->OnMacroStop(MacroName);
	gbGroundDeprecateCount = -1;

	if (g_pProfile)
	{
		g_pProfile->End();

		std::string profileDirectoryPath = fmt::format("{}\\profiles\\", gPathMacros);
		std::error_code ec;

		if (!std::filesystem::exists(profileDirectoryPath, ec))
			std::filesystem::create_directory(profileDirectoryPath, ec);

		std::ofstream logFile(profileDirectoryPath + g_pProfile->GetName() + ".csv");
		logFile << g_pProfile->to_string();

		WriteChatf("\ag[Profiler]\ax Saved profile to: %s", g_pProfile->GetName().c_str());

		delete g_pProfile;
		g_pProfile = nullptr;
	}
}

// ***************************************************************************
// Function:      EngineCommand
// Description:   Allows for switching engines.
// Usage:         /engine <type> <version> [noauto]
// ***************************************************************************
static void EngineCommand(PlayerClient*, const char* szLine)
{
	bool bNoAuto = false;

	if (ci_find_substr(szLine, "noauto") != -1)
	{
		bNoAuto = true;
	}

	char szBuffer[MAX_STRING] = { 0 };

	// TODO: Fix GetArg and shorten the length of these. Probably 10 & 3 are good.
	// GetArg crashes if you pass it anything except MAX_STRING due to RtlZeroMemory
	char szEngine[MAX_STRING] = { 0 };
	char szVersion[MAX_STRING] = { 0 };
	GetArg(szEngine, szLine, 1);
	GetArg(szVersion, szLine, 2);

	if (strlen(szEngine) == 0)
	{
		SyntaxError("Usage: /engine parser <version> [noauto]");
		return;
	}

	if (!_stricmp(szEngine, "parser"))
	{
		if (strlen(szVersion) == 0)
		{
			SyntaxError("Usage: /engine parser <version> [noauto]");
			return;
		}

		const int iVersion = GetIntFromString(szVersion, 1);

		switch (iVersion)
		{
		case 2:
		case 1:
			gParserVersion = iVersion;
			if (!bNoAuto)
			{
				WritePrivateProfileInt("MacroQuest", "ParserEngine", gParserVersion, mq::internal_paths::MQini);
			}

			WriteChatf("Parser Version %d Enabled", iVersion);
			break;

		default:
			MacroError("Invalid Parser Version (%d) valid versions are 1 or 2.", iVersion);
			break;
		}

		return;
	}

	SyntaxError("Invalid Engine type (%s). Valid types are: parser", szEngine);
}

// ***************************************************************************
// Function:    For
// Description: Our '/for' command
// Usage:       /for v# <start> <to|downto> <end>
// ***************************************************************************
static void For(PlayerClient*, const char* szLine)
{
	bRunNextCommand = true;
	char ArgLoop[MAX_STRING] = { 0 };
	char ArgStart[MAX_STRING] = { 0 };
	char ArgDirection[MAX_STRING] = { 0 };
	char ArgEnd[MAX_STRING] = { 0 };

	GetArg(ArgLoop, szLine, 1);
	GetArg(ArgStart, szLine, 2);
	GetArg(ArgDirection, szLine, 3);
	GetArg(ArgEnd, szLine, 4);
	_strlwr_s(ArgDirection);

	MQDataVar* pVar = FindMacroVariable(ArgLoop);
	if (!pVar)
	{
		FatalError("/for loop using invalid variable");
		return;
	}

	if (pVar->Var.Type != datatypes::pIntType)
	{
		FatalError("/for loops must use an int variable");
		return;
	}

	if ((ArgStart[0] == 0) || (ArgDirection[0] == 0) || (ArgEnd[0] == 0) || ((strcmp(ArgDirection, "to")) && (strcmp(ArgDirection, "downto"))))
	{
		FatalError("Usage: /for <variable> <start> <to|downto> <end> [step x]");
		return;
	}

	if (!gMacroBlock)
	{
		MacroError("Can only use /for during a macro.");
		return;
	}

	if (!pVar->Var.Type->FromString(pVar->Var.VarPtr, ArgStart))
	{
		FatalError("/for loop could not assign value '%s' to variable", ArgStart);
		return;
	}

	MQLoop loop;
	loop.type = MQLoop::Type::For;
	loop.firstLine = gMacroBlock->CurrIndex;
	loop.lastLine = 0;
	loop.forVariable = ArgLoop;
	PushMacroLoop(loop);
}

// ***************************************************************************
// Function:    Goto
// Description: Our '/goto' command
// Usage:       /goto :label
// ***************************************************************************
static void Goto(PlayerClient*, const char* szLine)
{
	if (!gMacroBlock)
	{
		MacroError("Cannot goto when a macro isn't running.");
		return;
	}

	bRunNextCommand = true;
	int FromIndex = gMacroBlock->CurrIndex;

	const auto goto_line = gMacroBlock->Line.find(FromIndex);
	if (goto_line->second.LoopEnd)
	{
		gMacroBlock->CurrIndex = goto_line->second.LoopEnd;
		return;
	}

	std::map<int, MQMacroLine>::reverse_iterator ri(goto_line);

	// search up first we only search until we find a "Sub "
	for (; ri != gMacroBlock->Line.rend(); ri++)
	{
		if (!_strnicmp(ri->second.Command.c_str(), "Sub ", 4))
		{
			ri--;
			FromIndex = ri->first;
			break;
		}

		if (!_stricmp(szLine, ri->second.Command.c_str()))
		{
			// Label found....
			gMacroBlock->CurrIndex = ri->first;
			goto_line->second.LoopEnd = ri->first;
			return;
		}
	}

	// now that we found our start lets look forward for the goto label:
	for (auto iter = gMacroBlock->Line.find(FromIndex); iter != gMacroBlock->Line.end(); iter++)
	{
		if (!_strnicmp(iter->second.Command.c_str(), "Sub ", 4))
		{
			break;
		}

		if (!_stricmp(szLine, iter->second.Command.c_str()))
		{
			// Label found
			gMacroBlock->CurrIndex = iter->first;
			goto_line->second.LoopEnd = iter->first;
			return;
		}
	}

	FatalError("Couldn't find label %s", szLine);
}

// ***************************************************************************
// Function:    Invoke
// Description: '/invoke' command
// Purpose:     Adds the ability to invoke Methods
// Example      /invoke ${Target.DoAssist}
//              will execute the DoAssist Method of the Spawn TLO
// ***************************************************************************
static void InvokeCmd(PlayerClient*, const char*)
{
	bRunNextCommand = true;
}

// ***************************************************************************
// Function:      KeepKeys
// Description:   Our /keepkeys command. Toggles if /endmacro will keep keys
//                by default.
// 2003-10-08     MacroFiend
// ***************************************************************************
static void KeepKeys(PlayerClient*, const char* szLine)
{
	bRunNextCommand = true;

	char szArg[MAX_STRING] = { 0 };
	GetArg(szArg, szLine, 1);

	const char* szKeepKeys[] = {
		"off",
		"on",
		nullptr
	};

	if (szArg[0] == 0)
	{
		WriteChatf("Auto-Keep Keys: %s", szKeepKeys[gKeepKeys]);
		return;
	}

	for (int Command = 0; szKeepKeys[Command]; Command++)
	{
		if (!_stricmp(szArg, szKeepKeys[Command]))
		{
			gKeepKeys = Command != 0;

			WriteChatf("Auto-Keep Keys changed to: %s", szKeepKeys[gKeepKeys]);

			WritePrivateProfileBool("MacroQuest", "KeepKeys", gKeepKeys, mq::internal_paths::MQini);
			return;
		}
	}

	SyntaxError("Usage: /keepkeys [on|off]");
}

// ***************************************************************************
// Function:    ListMacros
// Description: Our '/listmacros' command
//              Lists macro files
// Usage:       /listmacros <partial filename>
// ***************************************************************************
static void ListMacros(PlayerClient*, const char* szLine)
{
	bRunNextCommand = true;

	WIN32_FIND_DATAA FileData;
	HANDLE hSearch;
	if (szLine[0] != '\0')
	{
		hSearch = ::FindFirstFileA((mq::internal_paths::Macros + "\\*" + szLine + "*.mac").c_str(), &FileData);
	}
	else
	{
		hSearch = ::FindFirstFileA((mq::internal_paths::Macros + "\\*.mac").c_str(), &FileData);
	}

	if (hSearch == INVALID_HANDLE_VALUE)
	{
		WriteChatColor("Couldn't find any macros", USERCOLOR_DEFAULT);
		return;
	}

	std::vector<std::string> files;

	while (true)
	{
		files.emplace_back(FileData.cFileName);

		if (!::FindNextFileA(hSearch, &FileData))
			break;
	}

	::FindClose(hSearch);

	std::sort(std::begin(files), std::end(files));

	WriteChatColor("Macro list", USERCOLOR_WHO);
	WriteChatColor("----------------", USERCOLOR_WHO);

	for (const std::string& file : files)
		WriteChatColor(file.c_str(), USERCOLOR_WHO);
}

// ***************************************************************************
// Function:    MacroBeep
// Description: Our '/beep' command
//              Beeps the system speaker
// Usage:       /beep
// ***************************************************************************
static void MacroBeep(PlayerClient*, const char* szLine)
{
	bRunNextCommand = true;

	char szArg[MAX_STRING] = { 0 };

	GetArg(szArg, szLine, 1);
	if (szArg[0] == '\0')
		Beep(0x500, 250);
	else
		PlaySound(szArg, nullptr, SND_ASYNC);
}

// ***************************************************************************
// Function:    Macro
// Description: Our '/macro' command
// Usage:       /macro <filename>
// ***************************************************************************
static void Macro(PlayerClient*, const char* szLine)
{
	gWarning = false;
	bRunNextCommand = true;

	char* szNext = nullptr;
	bool InBlockComment = false;

	if (szLine[0] == 0)
	{
		SyntaxError("Usage: /macro <filename> [param [param...]]");
		return;
	}

	MQMacroBlockPtr pBlock = GetMacroBlock(szLine);

	if (gMacroBlock && !gMacroBlock->Line.empty())
	{
		gReturn = false;
		EndMacroCommand(nullptr, szLine);
		gReturn = true;
	}

	if (CXWnd* pWnd = FindMQ2Window("RunningMacrosWindow"))
	{
		if (CListWnd* list = (CListWnd*)pWnd->GetChildItem("RMW_RunningMacrosList"))
		{
			list->DeleteAll();
		}
	}

	gBindInProgress = true; // we dont want people to use binds until the macro is read.

	// we get ourself a new block, this will be valid until the macro ends.
	gMacroBlock = AddMacroBlock(szLine);

	gMaxTurbo = 80;
	gTurbo = true;

	char szTemp[MAX_STRING] = { 0 };
	GetArg(szTemp, szLine, 1);
	const char* Params = GetNextArg(szLine);

	strcpy_s(gszMacroName, szTemp);

	if (!strstr(szTemp, ".")) strcat_s(szTemp, ".mac");

	std::filesystem::path macFilePath = szTemp;

	if (macFilePath.is_relative())
	{
		macFilePath = mq::internal_paths::Macros / macFilePath;
	}

	FILE* fMacro = _fsopen(macFilePath.string().c_str(), "rt", _SH_DENYNO);

	if (fMacro == nullptr)
	{
		FatalError("Couldn't open macro file: %s", macFilePath.string().c_str());
		gszMacroName[0] = 0;
		gRunning = 0;
		return;
	}

	gEventChat = 0;
	strcpy_s(gszMacroName, szTemp);
	DebugSpew("Macro - Loading macro: %s", macFilePath.string().c_str());

	int LineIndex = 0;
	int LocalLine = 0;
	gMacroSubLookupMap.clear();

	const std::string strMacroName = macFilePath.filename().string();

	while (!feof(fMacro))
	{
		fgets(szTemp, MAX_STRING, fMacro);
		CleanMacroLine(szTemp);

		LineIndex++;
		LocalLine++;

		if (!strncmp(szTemp, "|**", 3))
		{
			InBlockComment = true;
		}

		if (!InBlockComment)
		{
			if (!AddMacroLine(strMacroName, szTemp, MAX_STRING, &LineIndex, LocalLine))
			{
				MacroError("Unable to add macro line.");
				fclose(fMacro);

				gszMacroName[0] = 0;
				gRunning = 0;
				return;
			}
		}
		else
		{
			DebugSpew("Macro - BlockComment: %s", szTemp);

			if (!strncmp(&szTemp[strlen(szTemp) - 3], "**|", 3))
			{
				InBlockComment = false;
			}
		}
	}

	fclose(fMacro);

	while (pDefines)
	{
		MQDefine* pDef = pDefines->pNext;
		delete pDefines;

		pDefines = pDef;
	}

	strcpy_s(szTemp, "Main");
	if (Params[0] != 0)
	{
		strcat_s(szTemp, " ");
		strcat_s(szTemp, Params);
	}

	DebugSpew("Macro - Starting macro with '/call %s'", szTemp);
	g_mq->OnMacroStart(szLine);
	gbGroundDeprecateCount = 0;
	Call(nullptr, szTemp);

	if (!gMacroBlock)
	{
		MacroError("Not a valid macrofile %s no Sub Main found.", strMacroName.c_str());
		gszMacroName[0] = 0;
		gRunning = 0;
		return;
	}

	auto iter = gMacroBlock->Line.find(gMacroBlock->CurrIndex);
	if (iter != gMacroBlock->Line.end())
	{
		std::advance(iter, 1);
		gMacroBlock->CurrIndex = iter->first;
	}

	if (!gMacroBlock || !gMacroStack)
	{
		gszMacroName[0] = 0;
		gRunning = 0;
	}

	gRunning = MQGetTickCount64();
	gBindInProgress = false;

	if (CXWnd* pWnd = FindMQ2Window("RunningMacrosWindow"))
	{
		pWnd->SetVisible(true);

		if (CListWnd* list = (CListWnd*)pWnd->GetChildItem("RMW_RunningMacrosList"))
		{
			int id = list->AddString("", 0xFF00FF00, 0);
			list->SetItemText(id, 1, strMacroName.c_str());
		}
	}
}

// ***************************************************************************
// Function:    MacroPause
// Description: Our '/mqpause' command
//              Pause/resume a macro
// Usage:       /mqpause <off>
//              /mqpause chat [on|off]
// ***************************************************************************
static void MacroPause(PlayerClient*, const char* szLine)
{
	const char* szPause[] = { "off", "on", nullptr };

	bRunNextCommand = true;

	char szArg[MAX_STRING] = { 0 };
	GetArg(szArg, szLine, 1);

	if (!_stricmp(szArg, "chat"))
	{
		char szArg1[MAX_STRING] = { 0 };
		GetArg(szArg1, szLine, 2);
		if (szLine[0] == 0)
		{
			gMQPauseOnChat = !gMQPauseOnChat;
		}
		else
		{
			for (int Command = 0; szPause[Command]; Command++)
			{
				if (!_stricmp(szArg1, szPause[Command]))
				{
					gMQPauseOnChat = Command != 0;
				}
			}
		}

		WritePrivateProfileBool("MacroQuest", "MQPauseOnChat", gMQPauseOnChat, mq::internal_paths::MQini);
		WriteChatf("Macros will %spause while in chat mode.", (gMQPauseOnChat) ? "" : "not ");
		return;
	}

	MQMacroBlockPtr pBlock = GetCurrentMacroBlock();
	if (!pBlock)
	{
		MacroError("You cannot pause or unpause a macro when one isn't running.");
		return;
	}

	bool Pause = true;
	for (int Command = 0; szPause[Command]; Command++)
	{
		if (!_stricmp(szArg, szPause[Command]))
		{
			Pause = Command != 0;
		}
	}

	if (szLine[0] != 0)
	{
		WriteChatColor("Syntax: /mqpause [on|off] [chat [on|off]]", USERCOLOR_DEFAULT);
	}
	else
	{
		Pause = !pBlock->Paused;
	}

	if (pBlock->Paused == Pause)
	{
		WriteChatf("Macro is already %s.", (Pause) ? "paused" : "running");
	}
	else
	{
		WriteChatf("Macro is %s.", (Pause) ? "paused" : "running again");
		pBlock->Paused = Pause;
	}
}

// ***************************************************************************
// Function:    Next
// Description: Our '/next' command
// Usage:       /next v#
// ***************************************************************************
static void Next(PlayerClient*, const char* szLine)
{
	bRunNextCommand = true;

	char szNext[MAX_STRING];
	GetArg(szNext, szLine, 1);

	MQDataVar* pVar = FindMacroVariable(szNext);
	if (!pVar)
	{
		FatalError("/next using invalid variable");
		return;
	}

	if (pVar->Var.Type != datatypes::pIntType)
	{
		FatalError("/for loops must use an int variable");
		return;
	}

	if (!gMacroBlock)
	{
		MacroError("Can only use /next during a macro.");
		return;
	}

	const auto size = gMacroStack->loopStack.size();
	if (size == 0 || gMacroStack->loopStack[size - 1].type != MQLoop::Type::For)
	{
		FatalError("/next without matching /for");
		return;
	}

	gMacroStack->loopStack[size - 1].lastLine = gMacroBlock->CurrIndex;
	auto MacroLine = gMacroStack->loopStack[size - 1].firstLine;
	auto iter = gMacroBlock->Line.find(MacroLine);

	char ForLine[MAX_STRING];
	strcpy_s(ForLine, iter->second.Command.c_str());

	ParseMacroData(ForLine, MAX_STRING);
	int VarNum = GetIntFromString(&szLine[1], 0);
	int StepSize = 1;

	int pos = ci_find_substr(ForLine, "step");
	if (pos != -1)
	{
		char* pTemp = ForLine + pos + 4;

		while ((pTemp[0] != 0) && (pTemp[0] != ' ') && (pTemp[0] != '\t'))
			pTemp++;
		if (pTemp[0] != 0)
			StepSize = GetIntFromString(pTemp, StepSize);
	}

	pVar = FindMacroVariable(szNext);
	if (!pVar)
	{
		FatalError("/next without badly matching /for");
		return;
	}

	pos = ci_find_substr(ForLine, "downto");
	if (pos != -1)
	{
		char* pDest = ForLine + pos;
		// TODO: This is easily broken, should search for the param rather than getting the specific point
		auto Loop = GetIntFromString(&pDest[7], 0);

		//DebugSpewNoFile("Next - End of loop %d downto %d", pVar->Var.Int, Loop);
		pVar->Var.Int -= StepSize;
		if (pVar->Var.Int >= Loop)
		{
			gMacroBlock->CurrIndex = MacroLine;
		}
		else
		{
			PopMacroLoop();
		}
	}
	else
	{
		auto Loop = 0;

		pos = ci_find_substr(ForLine, "to");
		if (pos != -1)
		{
			char* pDest = ForLine + pos + 3;
			Loop = GetIntFromString(pDest, 0);
		}

		//DebugSpewNoFile("Next - End of loop %d to %d", pVar->Var.Int, Loop);
		pVar->Var.Int += StepSize;

		if (pVar->Var.Int <= Loop)
		{
			gMacroBlock->CurrIndex = MacroLine;
		}
		else
		{
			PopMacroLoop();
		}
	}
}

// ***************************************************************************
// Function:    NoParseCmd
// Description: Our '/noparse' command
// Usage:       /noparse <command>
// ***************************************************************************
static void NoParseCmd(PlayerClient*, const char* szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /noparse <command>");
		return;
	}

	if (gParserVersion == 2)
	{
		// To maintain backwards compatibility, but not rely on globals we need to wrap the parameters in a Parse Zero.
		// However, in the future it would be better to just do your command as /echo ${Parse[0,${Me.Name}]} to get the same functionality.
		// Cast it as a char*, Modify the line, and run the command
		std::string macroString = ModifyMacroString(szLine, true, ModifyMacroMode::WrapNoDoubles);

		DoCommand(&macroString[0], false);
	}
	else
	{
		bAllowCommandParse = false;
		DoCommand(szLine, false);
		bAllowCommandParse = true;
	}
}

//
// /if
//
static void IfCmd(PlayerClient*, const char* szLine)
{
	if (szLine[0] != '(')
	{
		FatalError("Failed to parse /if command.  Expected () around conditions.");
		SyntaxError("Usage: /if (<conditions>) <command>");
		return;
	}

	const char* pEnd = &szLine[1];
	int nParens = 1;

	while (true)
	{
		if (*pEnd == '(')
			nParens++;
		else if (*pEnd == ')')
		{
			nParens--;
			if (nParens == 0)
			{
				pEnd++;
				if (*pEnd != ' ')
				{
					FatalError("Failed to parse /if command.  Could not find command to execute.");
					SyntaxError("Usage: /if (<conditions>) <command>");
					return;
				}
				break;
			}
		}
		else if (*pEnd == 0)
		{
			FatalError("Failed to parse /if command.  Could not find command to execute.");
			SyntaxError("Usage: /if (<conditions>) <command>");
			return;
		}
		++pEnd;
	}

	char szCond[MAX_STRING] = { 0 };
	strncpy_s(szCond, szLine, pEnd - szLine);
	szCond[pEnd - szLine] = 0;
	++pEnd;

	double Result = 0;
	if (!Calculate(szCond, Result))
	{
		FatalError("Failed to parse /if condition '%s', non-numeric encountered", szCond);
		return;
	}

	if (Result != 0)
	{
		if (gParserVersion == 2)
		{
			// Due to the way that MQ2 currently processes the whole line before reaching this point:
			// At this point the command has already passed through the parser once.  We don't want
			// it to be parsed again since the parser already knew how to handle it and has given us
			// the correct output.  So let's wrap this in a ${Parse[0 until we can fix /if to short
			// circuit prior to processing.
			// Cast it as a char*, Modify the command, and run it
			std::string str = ModifyMacroString(pEnd, true, ModifyMacroMode::Wrap);

			DoCommand(&str[0], false);
		}
		else
		{
			DoCommand(pEnd, false);
		}
	}
	else
	{
		int index = 0;

		if (gMacroBlock && !gMacroBlock->Line.empty())
			index = gMacroBlock->CurrIndex;

		FailIf(pEnd, index);
	}
}

//
// /profile
//
static void ProfileCmd(PlayerClient*, const char* szLine)
{
	Macro(nullptr, szLine);

	if (g_pProfile)
	{
		WriteChatf("\ar[Profiler]\ax Macro started when a profiling session is already underway!");
		return;
	}

	if (!gMacroBlock)
		return;

	std::vector<std::string> args = ArgsToVector(szLine);

	auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::tm now = {};
	localtime_s(&now, &time);
	char dateTime[32] = { 0 };
	std::strftime(dateTime, 32, "%Y%m%d_%H%M%S", &now);

	s_commandCount = 0;

	// strip directories if any
	char* pMacroName = strrchr(gszMacroName, '\\') + 1;
	if (pMacroName == (char*)1) pMacroName = strrchr(gszMacroName, '//') + 1;
	if (pMacroName == (char*)1) pMacroName = gszMacroName;

	WriteChatf("\ag[Profiler]\ax Profiling session started!");

	g_pProfile = new ProfileSession(fmt::format("{}_{}", pMacroName, dateTime));
	g_pProfile->Call("Main", std::move(args));
}

// ***************************************************************************
// Function:    Return
// Description: Our '/return' command
// Usage:       /return [value]
// ***************************************************************************
static void Return(PlayerClient*, const char* szLine)
{
	bRunNextCommand = true;
	MQMacroStack* pStack = gMacroStack;

	if (!gMacroBlock)
	{
		MacroError("Cannot return when a macro isn't running.");
		return;
	}

	if (!pStack->pNext)
	{
		// Top of stack (ie. returning from Sub Main)
		EndMacroCommand(nullptr, "");
		return;
	}

	if (pStack->LocalVariables)
		ClearDataVariables(&pStack->LocalVariables);

	if (pStack->Parameters)
		ClearDataVariables(&pStack->Parameters);

	if (!pStack->bIsBind) // binds dont return values...
		pStack->pNext->Return = szLine;

	gMacroBlock->CurrIndex = pStack->pNext->LocationIndex;
	gMacroStack = pStack->pNext;

	delete pStack;

	if (g_pProfile)
	{
		g_pProfile->Return(szLine);
	}
}

// ***************************************************************************
// Function:    SetError
// Description: Our '/seterror' command
// Usage:       /seterror <clear|errormsg>
// ***************************************************************************
static void SetError(PlayerClient*, const char* szLine)
{
	bRunNextCommand = true;

	if ((szLine[0] == 0) || (_stricmp(szLine, "clear")))
	{
		gszLastNormalError[0] = 0;
	}
	else
	{
		strcpy_s(gszLastNormalError, szLine);
	}
}

// ***************************************************************************
// Function:    While
// Description: Our '/while' command
// Usage:       /while (cond) {
//                   ....
//              }
// ***************************************************************************
static void MacroWhileCmd(PlayerClient*, const char* szLine)
{
	char szCond[MAX_STRING] = { 0 };

	if (szLine[0] != '(')
	{
		FatalError("Failed to parse /while command.  Expected () around conditions.");
		SyntaxError("Usage: /while (<conditions>) <command>");
		return;
	}

	const char* pEnd = &szLine[1];
	DWORD nParens = 1;
	while (true)
	{
		if (*pEnd == '(')
			nParens++;
		else if (*pEnd == ')')
		{
			nParens--;
			if (nParens == 0)
			{
				pEnd++;
				if (*pEnd != ' ')
				{
					FatalError("Failed to parse /while command.  Could not find command to execute.");
					SyntaxError("Usage: /while (<conditions>) <command>");
					return;
				}
				break;
			}
		}
		else if (*pEnd == 0)
		{
			FatalError("Failed to parse /while command.  Could not find command to execute.");
			SyntaxError("Usage: /while (<conditions>) <command>");
			return;
		}
		++pEnd;
	}

	strcpy_s(szCond, szLine);
	strncpy_s(szCond, szLine, pEnd - szLine);
	szCond[pEnd - szLine] = 0;
	++pEnd;

	double Result = 0;
	if (!Calculate(szCond, Result))
	{
		FatalError("Failed to parse /while condition '%s', non-numeric encountered", szCond);
		return;
	}

	// lets check all the lines within it
	// and mark the end so the interpreter knows when to exit it
	MQLoop loop;
	MarkWhile(pEnd, loop);

	if (!gMacroBlock)
		return;

	if (Result != 0)
		PushMacroLoop(loop);
	else
		EndWhile();
}

// ***************************************************************************
// Function:    VarCalcCmd
// Description: Our '/varcalc' command
// Usage:       /varcalc <varname> <formula>
// ***************************************************************************
static void VarCalcCmd(PlayerClient*, const char* szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /varcalc <varname> <formula>");
		return;
	}

	char szName[MAX_STRING] = { 0 };
	GetArg(szName, szLine, 1);
	const char* pRest = GetNextArg(szLine);
	if (!pRest || !pRest[0])
	{
		SyntaxError("Usage: /varcalc <varname> <formula>");
		return;
	}

	char szRest[MAX_STRING] = { 0 };
	strcpy_s(szRest, pRest);
	double Result = 0.0;
	if (!Calculate(szRest, Result))
	{
		MacroError("/varcalc '%s' failed.  Could not calculate '%s'", szName, szRest);
		return;
	}

	sprintf_s(szRest, "%f", Result);

	char szIndex[MAX_STRING] = { 0 };
	if (char* pBracket = strchr(szName, '['))
	{
		*pBracket = 0;
		strcpy_s(szIndex, &pBracket[1]);
	}

	MQDataVar* pVar = FindMacroVariable(szName);
	if (!pVar)
	{
		MacroError("/varcalc failed, variable '%s' not found", szName);
		return;
	}

	if (szIndex[0])
	{
		if (pVar->Var.Type != pArrayType)
		{
			MacroError("/varcalc '%s' failed, array form on non-array", szName);
			return;
		}

		auto pArray = pVar->Var.Get<CDataArray>();
		int index = pArray->GetElement(szIndex);
		if (index == -1)
		{
			MacroError("/varcalc '%s[%d]' failed, out of bounds on array", szName, index);
			return;
		}

		if (!pArray->GetType()->FromString(pArray->GetData(index), szRest))
		{
			MacroError("/varcalc '%s[%d]' failed, array element type rejected new value", szName, index);
		}
	}
	else
	{
		if (!pVar->Var.Type->FromString(pVar->Var.VarPtr, szRest))
		{
			MacroError("/varcalc '%s' failed, variable type rejected new value", szName);
		}
	}
}

// ***************************************************************************
// Function:    VarDataCmd
// Description: Our '/vardata' command
// Usage:       /vardata <varname> <new mq2data value>
// ***************************************************************************
static void VarDataCmd(PlayerClient*, const char* szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /vardata <varname> <new mq2data value>");
		return;
	}

	char szName[MAX_STRING] = { 0 };
	GetArg(szName, szLine, 1);

	const char* nextArg = GetNextArg(szLine);
	if (!nextArg || !nextArg[0])
	{
		SyntaxError("Usage: /vardata <varname> <new mq2data value>");
		return;
	}

	char szRest[MAX_STRING] = { 0 };
	strcpy_s(szRest, nextArg);

	char szIndex[MAX_STRING] = { 0 };
	if (char* pBracket = strchr(szName, '['))
	{
		*pBracket = 0;
		strcpy_s(szIndex, &pBracket[1]);
	}

	MQDataVar* destVar = FindMacroVariable(szName);
	if (!destVar)
	{
		MacroError("/vardata '%s' failed, variable not found", szName);
		return;
	}

	MQTypeVar sourceVar;
	if (!pDataAPI->ParseDataPortion(szRest, sourceVar))
	{
		MacroError("/vardata '%s' failed, MQ2Data portion '%s' unparsable", szName, szRest);
		return;
	}

	MQ2Type* destType;
	MQVarPtr* destData;
	int num = -1;

	if (szIndex[0])
	{
		if (destVar->Var.Type != pArrayType)
		{
			MacroError("/vardata '%s' failed, array form on non-array", szName);
			return;
		}

		auto pArray = destVar->Var.Get<CDataArray>();
		num = pArray->GetElement(szIndex);
		if (num == -1)
		{
			MacroError("/vardata '%s[%d]' failed, out of bounds on array", szName, num);
			return;
		}

		destType = pArray->GetType();
		destData = &pArray->GetData(num);
	}
	else
	{
		destType = destVar->Var.Type;
		destData = &destVar->Var.VarPtr;
	}

	// Check if these types are related.
	MQ2Type* sourceType = sourceVar.Type;

	// If we're assigning from a descendent, then we can attempt to downcast to this type.
	if (sourceType != destType && sourceType->InheritsFrom(destType))
	{
		if (sourceType->Downcast(sourceVar, *destData, destType))
			return;
	}

	if (!destType->FromData(*destData, sourceVar))
	{
		if (num != -1)
		{
			MacroError("/vardata '%s[%d]'failed, array element type rejected new value", szName, num);
		}
		else
		{
			MacroError("/vardata '%s' failed, variable type rejected new value", szName);
		}
	}
}

// ***************************************************************************
// Function:    VarSetCmd
// Description: Our '/varset' command
// Usage:       /varset <varname> <new value>
// ***************************************************************************
static void VarSetCmd(PlayerClient*, const char* szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /varset <varname> <new value>");
		return;
	}

	char szName[MAX_STRING] = { 0 };
	GetArg(szName, szLine, 1);

	const char* szRest = GetNextArg(szLine);
	char szIndex[MAX_STRING] = { 0 };
	if (char* pBracket = strchr(szName, '['))
	{
		*pBracket = 0;
		strcpy_s(szIndex, &pBracket[1]);
	}

	MQDataVar* pVar = FindMacroVariable(szName);
	if (!pVar)
	{
		MacroError("/varset failed, variable '%s' not found", szName);
		return;
	}

	if (szIndex[0])
	{
		if (pVar->Var.Type != pArrayType)
		{
			MacroError("/varset '%s' failed, array form on non-array", szName);
			return;
		}

		auto pArray = pVar->Var.Get<CDataArray>();
		int index = pArray->GetElement(szIndex);
		if (index == -1)
		{
			MacroError("/varset '%s[%d]' failed, out of bounds on array", szName, index);
			return;
		}

		if (!pArray->GetType()->FromString(pArray->GetData(index), szRest))
		{
			MacroError("/varset '%s[%d]' failed, array element type rejected new value", szName, index);
		}
	}
	else
	{
		if (!pVar->Var.Type->FromString(pVar->Var.VarPtr, szRest))
		{
			MacroError("/varset '%s' failed, variable type rejected new value", szName);
		}
	}
}

#pragma endregion

//=================================================================================================

MacroSystem* g_macroSystem = nullptr;

MacroSystem::MacroSystem()
	: MQModule("MacroSystem", static_cast<int>(ModulePriority::Macros))
{
	SetModuleDependencies({ "Commands", "DataTypes" });

	g_macroSystem = this;
}

MacroSystem::~MacroSystem()
{
	g_macroSystem = nullptr;
}

void MacroSystem::Initialize()
{
	struct { const char* szCommand; MQCommandHandler pFunc; bool Parse; bool InGame; } commands[] = {
		{ "/beep",              MacroBeep,                  true,  false },
		{ "/break",             Break,                      true,  false },
		{ "/call",              Call,                       true,  false },
		{ "/clearerrors",       ClearErrorsCmd,             true,  false },
		{ "/continue",          Continue,                   true,  false },
		{ "/declare",           DeclareVar,                 true,  false },
		{ "/deletevar",         DeleteVarCmd,               true,  false },
		{ "/docommand",         DoCommandCmd,               true,  false },
		{ "/doevents",          DoEvents,                   true,  false },
		{ "/dumpstack",         DumpStack,                  true,  false },
		{ "/endmacro",          EndMacroCommand,            true,  false },
		{ "/engine",            EngineCommand,              true,  false },
		{ "/for",               For,                        true,  false },
		{ "/goto",              Goto,                       true,  false },
		{ "/if",                IfCmd,                      true,  false },
		{ "/invoke",            InvokeCmd,                  true,  false },
		{ "/keepkeys",          KeepKeys,                   true,  false },
		{ "/listmacros",        ListMacros,                 true,  false },
		{ "/macro",             Macro,                      true,  false },
		{ "/mqpause",           MacroPause,                 true,  false },
		{ "/next",              Next,                       true,  false },
		{ "/noparse",           NoParseCmd,                 false, false },
		{ "/profile",           ProfileCmd,                 true,  false },
		{ "/return",            Return,                     true,  false },
		{ "/seterror",          SetError,                   true,  false },
		{ "/varcalc",           VarCalcCmd,                 true,  false },
		{ "/vardata",           VarDataCmd,                 true,  false },
		{ "/varset",            VarSetCmd,                  true,  false },
		{ "/where",             Where,                      true,  true  },
		{ "/while",             MacroWhileCmd,              true,  false },
	};

	// Add all of our commands
	for (const auto& reg : commands)
	{
		AddCommand(reg.szCommand, reg.pFunc, false, reg.Parse, reg.InGame);
	}

	// initialize Blech
	pEventBlech = new Blech('#', '|', MQ2DataVariableLookup);
	pMQ2Blech = new Blech('#', '|', MQ2DataVariableLookup);

	const std::string& iniFile = mq::internal_paths::MQini;

	bAllErrorsDumpStack = GetPrivateProfileBool("MacroQuest", "AllErrorsDumpStack", bAllErrorsDumpStack, iniFile);
	bAllErrorsFatal = GetPrivateProfileBool("MacroQuest", "AllErrorsFatal", bAllErrorsFatal, iniFile);
	gKeepKeys = GetPrivateProfileBool("MacroQuest", "KeepKeys", gKeepKeys, iniFile);
	gMQPauseOnChat = GetPrivateProfileBool("MacroQuest", "MQPauseOnChat", gMQPauseOnChat, iniFile);
	gParserVersion = GetPrivateProfileInt("MacroQuest", "ParserEngine", gParserVersion, iniFile); // 2 = new parser, everything else = old parser
	gTurboLimit = GetPrivateProfileInt("MacroQuest", "TurboLimit", gTurboLimit, iniFile);

	if (gbWriteAllConfig)
	{
		WritePrivateProfileBool("MacroQuest", "AllErrorsDumpStack", bAllErrorsDumpStack, iniFile);
		WritePrivateProfileBool("MacroQuest", "AllErrorsFatal", bAllErrorsFatal, iniFile);
		WritePrivateProfileBool("MacroQuest", "KeepKeys", gKeepKeys, iniFile);
		WritePrivateProfileBool("MacroQuest", "MQPauseOnChat", gMQPauseOnChat, iniFile);
		WritePrivateProfileInt("MacroQuest",  "ParserEngine", gParserVersion, iniFile);
		WritePrivateProfileInt("MacroQuest",  "TurboLimit", gTurboLimit, iniFile);
	}
}

void MacroSystem::Shutdown()
{
	delete pEventBlech;
	pEventBlech = nullptr;
	delete pMQ2Blech;
	pMQ2Blech = nullptr;
}

void MacroSystem::OnProcessFrame()
{
	static uint64_t TickDiff = 0;
	uint64_t Tick = ::GetTickCount64();
	static uint64_t LastGetTick = Tick;

	// This accounts for rollover
	TickDiff += (Tick - LastGetTick);
	LastGetTick = Tick;

	while (TickDiff >= 100)
	{
		TickDiff -= 100;
		if (gDelay > 0) gDelay--;
		DropTimers();
	}

	bRunNextCommand = true;

	if (gGameState != -1)
	{
		int CurTurbo = 0;

		bInMacroCall = true;

		MQMacroBlockPtr pBlock = GetNextMacroBlock();
		while (bRunNextCommand)
		{
			if (!pBlock)
				break;
			if (!DoNextCommand(pBlock))
				break;
			if (gbUnload)
				return;
			if (!gTurbo)
				break;
			if (++CurTurbo > gMaxTurbo)
				break;

			// re-fetch current macro block in case one of the previous instructions changed it
			pBlock = GetCurrentMacroBlock();
		}

		bInMacroCall = false;
	}
}

bool MacroSystem::OnIncomingChat(const IncomingChatParams& params)
{
	// don't know why we check for this.
	if (params.color != USERCOLOR_BROADCAST)
	{
		strncpy_s(EventMsg, params.stripped, MAX_STRING - 1);
		EventMsg[MAX_STRING - 1] = 0;
		if (pMQ2Blech)
			pMQ2Blech->Feed(EventMsg);
		EventMsg[0] = 0;

		CheckChatForEvent(params.stripped);
	}

	return false;
}

bool MacroSystem::IsMacroRunning() const
{
	return gMacroBlock != nullptr;
}

bool MacroSystem::IsActiveMacroCall() const
{
	return bInMacroCall;
}

void MacroSystem::HandleMacroError(const char* szError)
{
	if (IsActiveMacroCall())
	{
		if (bAllErrorsDumpStack || bAllErrorsFatal)
			DumpStack(nullptr, nullptr);

		if (bAllErrorsFatal)
			EndMacroCommand(pLocalPlayer, "");
	}
}

void MacroSystem::HandleFatalError(const char* szError)
{
	if (IsActiveMacroCall())
	{
		DumpStack(nullptr, nullptr);
		EndMacroCommand(pLocalPlayer, "");
	}
}

bool MacroSystem::DispatchBind(char* szCommand, char* szArgs)
{
	// Macro Binds only supported in-game
	if (gGameState != GAMESTATE_INGAME)
		return false;

	MQMacroBlockPtr pBlock = GetCurrentMacroBlock();
	if (!pBlock)
		return false;

	MQBindList* pBind = pBindList;
	while (pBind)
	{
		// Substring search for the command
		if (ci_find_substr(pBind->szName, szCommand) == 0)
		{
			if (pBlock->BindCmd.empty())
			{
				if (!gBindInProgress)
				{
					char szCallFunc[MAX_STRING] = { 0 };
					strcpy_s(szCallFunc, pBind->szFuncName);
					strcat_s(szCallFunc, " ");
					strcat_s(szCallFunc, szArgs);

					if (pBind->Parse)
					{
						ParseMacroData(szCallFunc, MAX_STRING);
					}

					gBindInProgress = true;
					pBlock->BindCmd = szCallFunc;
				}
				else
				{
					WriteChatf("Can't execute bind while another bind is in progress");
				}
			}

			return true;
		}

		pBind = pBind->pNext;
	}

	return false;
}

void MacroSystem::MacroCall(const char* line)
{
	Call(nullptr, line);
}

DECLARE_MODULE_FACTORY(MacroSystem)

} // namespace mq
