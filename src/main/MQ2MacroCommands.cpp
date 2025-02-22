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

#include "MQCommandAPI.h"
#include "MQDataAPI.h"
#include "MQPluginHandler.h"
#include "MQ2KeyBinds.h"

#include <fstream>
#include <regex>

namespace mq {

// Defined in MQ2DataVars.cpp
void CALLBACK EventBlechCallback(unsigned int ID, void* pData, PBLECHVALUE pValues);

static std::map<std::string, MQMacroBlockPtr> MacroBlockMap;
uint64_t s_commandCount = 0;

void format_args(fmt::appender& buffer, const std::vector<std::string>& args)
{
	if (args.empty())
		return;

	fmt::format_to(buffer, "\"{}\"", mq::replace(args[0], "\"", "\"\""));
	for (size_t i = 1; i < args.size(); ++i)
		fmt::format_to(buffer, ",\"{}\"", mq::replace(args[0], "\"", "\"\""));
}

class StackFrame
{
public:
	StackFrame(std::string&& subroutine, std::vector<std::string>&& arguments)
		: m_subroutine(std::move(subroutine))
		, m_args(std::move(arguments))
		, m_startTime(std::chrono::high_resolution_clock::now())
		, m_startCommandCount(s_commandCount)
	{
	}

	void AddChild(std::unique_ptr<StackFrame> child)
	{
		m_children.push_back(std::move(child));
	}

	void End(std::string&& returnValue)
	{
		m_endTime = std::chrono::high_resolution_clock::now();
		m_endCommandCount = s_commandCount;

		m_returnValue = std::move(returnValue);
		m_returned = true;
	}

	std::chrono::microseconds GetMicrosecondsInclusive() const
	{
		return std::chrono::duration_cast<std::chrono::microseconds>(m_endTime - m_startTime);
	}

	std::chrono::microseconds GetMicrosecondsExclusive() const
	{
		std::chrono::microseconds total = GetMicrosecondsInclusive();

		for (const std::unique_ptr<StackFrame>& child : m_children)
			total -= child->GetMicrosecondsInclusive();

		return total;
	}

	uint64_t GetCommandCountInclusive() const
	{
		return m_endCommandCount - m_startCommandCount;
	}

	uint64_t GetCommandCountExclusive() const
	{
		uint64_t total = GetCommandCountInclusive();

		for (const std::unique_ptr<StackFrame>& child : m_children)
			total -= child->GetCommandCountInclusive();

		return total;
	}

	std::string format_csv(int depth, std::chrono::high_resolution_clock::time_point beginTime) const
	{
		fmt::memory_buffer mem;
		fmt::appender buffer(mem);

		format_csv(buffer, depth, beginTime);

		return fmt::to_string(mem);
	}

	void format_csv(fmt::appender& buffer, int depth, std::chrono::high_resolution_clock::time_point beginTime) const
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

private:
	std::string m_subroutine;
	std::vector<std::string> m_args;
	std::string m_returnValue;
	bool m_returned = false;

	uint64_t m_startCommandCount;
	uint64_t m_endCommandCount;
	std::chrono::high_resolution_clock::time_point m_startTime;
	std::chrono::high_resolution_clock::time_point m_endTime;
	std::vector<std::unique_ptr<StackFrame>> m_children;
};

class ProfileSession
{
public:
	ProfileSession(std::string&& name)
		: m_name(std::move(name))
		, m_startTime(std::chrono::high_resolution_clock::now())
	{
	}

	void Call(std::string&& subroutine, std::vector<std::string>&& args)
	{
		m_callStack.emplace_back(new StackFrame(std::move(subroutine), std::move(args)));
	}

	void Return(std::string returnValue)
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

	void End()
	{
		while (m_callStack.size() > 1)
			Return("#N/A");

		m_callStack.back()->End("#N/A");
	}

	const std::string& GetName() const {
		return m_name;
	}

	std::string to_string() const
	{
		fmt::memory_buffer mem;
		fmt::appender buf(mem);

		fmt::format_to(buf, "Command Count,Seconds Since Start,Stack Depth,Subroutine,Subroutine (tabbed),Commands (inc Children),Commands (ex Children),ms inc, ms ex,Called Children,Return Value,Arguments\n");

		if (m_callStack.size() == 1)
			m_callStack.back()->format_csv(buf, 1, m_startTime);

		return fmt::to_string(mem);
	}

private:
	std::string m_name;
	std::deque<std::unique_ptr<StackFrame>> m_callStack;

	uint64_t m_startCommandCount;
	std::chrono::high_resolution_clock::time_point m_startTime;
};

ProfileSession* g_pProfile = nullptr;

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

void ProfileCmd(PlayerClient* pChar, const char* szLine)
{
	Macro(pChar, szLine);

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

void FailIf(SPAWNINFO* pChar, const char* szCommand, int StartLine, bool All = false)
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

// ***************************************************************************
// Function:    Delay
// Description: Our '/delay' command
// Usage:       /delay <time> [condition to end early]
// ***************************************************************************
void Delay(PlayerClient* pChar, const char* szLine)
{
	if (szLine[0] == 0)
	{
		SyntaxError("Usage: /delay <time> [condition to end early]");
		return;
	}

	char szVal[MAX_STRING] = { 0 };
	GetArg(szVal, szLine, 1);

	ParseMacroData(szVal, MAX_STRING);
	strcpy_s(gDelayCondition, GetNextArg(szLine));

	int VarValue = GetIntFromString(szVal, 0);
	size_t len = strlen(szVal);

	// Measured in deciseconds...
	if (::tolower(szVal[len - 1]) == 'm')
		VarValue *= 600;
	else if (::tolower(szVal[len - 1]) == 's')
	{
		if (len > 2 && ::tolower(szVal[len - 2]) == 'm')
			VarValue /= 100;
		else
			VarValue *= 10;
	}

	gDelay = VarValue;
	bRunNextCommand = false;

	if (gDelayCondition[0])
	{
		char szCond[MAX_STRING];
		strcpy_s(szCond, gDelayCondition);

		ParseMacroData(szCond, MAX_STRING);

		double Result;
		if (!Calculate(szCond, Result))
		{
			FatalError("Failed to parse /delay condition '%s', non-numeric encountered", szCond);
			return;
		}

		// TODO:  Determine the bounds on what "0" should be here since this is a double.
		if (Result != 0)
		{
			gDelay = 0;
			bRunNextCommand = true;
		}
	}
}

char* GetFuncParam(const char* szMacroLine, int ParamNum, char* szParamName, size_t ParamNameLen, char* szParamType, size_t ParamTypeLen)
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

/* VAR SYSTEM INDEPENDENT */
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

bool AddMacroLine(const char* FileName, char* szLine, size_t Linelen, int* LineNumber, int localLine);

// ***************************************************************************
// Function:    Include
// Description: Includes another macro file
// Usage:       #include <filename>
// ***************************************************************************
// TODO:  Switch this to take input of filesystem::path instead of const char*  Breaking change?
bool Include(const char* szFile, int* LineNumber)
{
	FILE* fMacro = _fsopen(szFile, "rt", _SH_DENYNO);
	if (fMacro == nullptr)
	{
		FatalError("Couldn't open include file: %s", szFile);
		return false;
	}

	DebugSpewNoFile("Include - Including: %s", szFile);

	int LocalLine = 0;
	bool InBlockComment = false;
	const char* Macroname = GetFilenameFromFullPath(szFile);
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
			if (!AddMacroLine(Macroname, szTemp, MAX_STRING, LineNumber, LocalLine))
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
bool AddMacroLine(const char* FileName, char* szLine, size_t Linelen, int* LineNumber, int localLine)
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
				return Include(incFilePath.string().c_str(), LineNumber);
			}

			// if we're here, it was optional so only include if it exists
			if (exists(incFilePath, ec_exists))
			{
				return Include(incFilePath.string().c_str(), LineNumber);
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
							// we dont know what the macro will varset this to, so we just
							// default it to the same name as the key...
							// cant set it to "" cause then it triggers on every single line of
							// chat before they /varset it to something... (if they ever)
							AddMQ2DataVariable(szVar, "", datatypes::pStringType, &pMacroVariables, "NULL");
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
		MacroError("Duplicate line number detected! %s@%d", FileName, localLine);
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

	for (const auto& name : names)
	{
		EndMacro((PSPAWNINFO)pLocalPlayer, (char*)name.c_str());
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

MQMacroBlockPtr GetNextMacroBlock()
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

int GetMacroBlockCount()
{
	return static_cast<int>(MacroBlockMap.size());
}

// ***************************************************************************
// Function:    Macro
// Description: Our '/macro' command
// Usage:       /macro <filename>
// ***************************************************************************
void Macro(PlayerClient* pChar, const char* szLine)
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
		EndMacro(pChar, szLine);
		gReturn = true;
	}

	if (CXWnd* pWnd = FindMQ2Window("RunningMacrosWindow"))
	{
		if (CListWnd * list = (CListWnd*)pWnd->GetChildItem("RMW_RunningMacrosList"))
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
			if (!AddMacroLine(strMacroName.c_str(), szTemp, MAX_STRING, &LineIndex, LocalLine))
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
	PluginsMacroStart(szLine);
	gbGroundDeprecateCount = 0;
	Call(pChar, szTemp);

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
// Function:    Cleanup
// Description: Our '/cleanup' command
//              Sends i, esc, esc, esc, esc, i
// Usage:       /cleanup
// ***************************************************************************
void Cleanup(PlayerClient* pChar, const char* szLine)
{
	KeyCombo Escape;
	ParseKeyCombo("Esc", Escape);

	if (pContainerMgr)
	{
		int concount = 2; // Close inv + clear target

		if (pContainerMgr->pWorldContainer && pContainerMgr->pWorldContainer->Open == 1)
			concount++;

		for (int i = 0; i < MAX_CONTAINERS; i++)
		{
			if (pContainerMgr->pContainerWnds[i] && pContainerMgr->pContainerWnds[i]->IsVisible())
				concount++;
		}

		for (int i = 0; i < concount; i++)
		{
			MQ2HandleKeyDown(Escape);
			MQ2HandleKeyUp(Escape);
		}

		if (pInventoryWnd && pInventoryWnd->IsVisible())
			DoMappable(pChar, "inventory");
	}
	else
	{
		DoMappable(pChar, "inventory");

		for (int i = 0; i < 10; i++)
		{
			MQ2HandleKeyDown(Escape);
			MQ2HandleKeyUp(Escape);
		}

		DoMappable(pChar, "inventory");
	}
}

// ***************************************************************************
// Function:    Goto
// Description: Our '/goto' command
// Usage:       /goto :label
// ***************************************************************************
void Goto(PlayerClient* pChar, const char* szLine)
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

char* GetSubFromLine(int Line, char* szSub, size_t Sublen)
{
	std::map<int, MQMacroLine>::reverse_iterator ri(gMacroBlock->Line.find(Line));

	for (; ri != gMacroBlock->Line.rend(); ri++)
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

void DumpStack(PlayerClient* pChar, const char* szLine)
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
				GetSubFromLine(pMS->LocationIndex, szSub, MAX_STRING),
				ml->Command.c_str());
		}
		else
		{
			sprintf_s(szTemp, "??? (%s): ???", GetSubFromLine(pMS->LocationIndex, szSub, MAX_STRING));
		}

		WriteChatColor(szTemp);
		if (bAllErrorsLog) MacroLog(nullptr, szTemp);
		pMS = pMS->pNext;
	}
}

// ***************************************************************************
// Function:    EndMacro
// Description: Our '/endmacro' command
// Usage:       /endmacro
// ***************************************************************************
void EndMacro(PlayerClient* pChar, const char* szLine)
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
						ClearMQ2DataVariables(&gMacroStack->LocalVariables);
					if (gMacroStack->Parameters)
						ClearMQ2DataVariables(&gMacroStack->Parameters);

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
			ClearMQ2DataVariables(&gMacroStack->LocalVariables);

		if (gMacroStack->Parameters)
			ClearMQ2DataVariables(&gMacroStack->Parameters);

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

	ClearMQ2DataVariables(&pMacroVariables);

	DebugSpewNoFile("EndMacro - Ended");
	if (gFilterMacro != FILTERMACRO_NONE && gFilterMacro != FILTERMACRO_MACROENDED)
		WriteChatColor("The current macro has ended.", USERCOLOR_DEFAULT);

	PluginsMacroStop(MacroName);
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

static int GetNumArgsFromSub(const std::string& Sub)
{
	if (size_t hasparams = std::count(Sub.begin(), Sub.end(), '('))
	{
		size_t n = std::count(Sub.begin(), Sub.end(), ',');
		return static_cast<int>(n) + 1;
	}
	return 0;
}

// ***************************************************************************
// Function:    Call
// Description: Our '/call' command
// Usage:       /call <Subroutine>
// ***************************************************************************
void Call(PlayerClient*, const char* szLine)
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

			AddMQ2DataVariable(szParamName, "", pType, &gMacroStack->Parameters, szNewValue);
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

void MacroIfCmd(PlayerClient* pChar, const char* szLine)
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

		FailIf(pChar, pEnd, index);
	}
}

void PopMacroLoop()
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

// ***************************************************************************
// Function:    While
// Description: Our '/while' command
// Usage:       /while (cond) {
//                   ....
//              }
// ***************************************************************************
void MacroWhileCmd(PlayerClient* pChar, const char* szLine)
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
// Function:    DoEvents
// Description: Our '/doevents' command
// Usage:       /doevents [flush] [custom event]
// ***************************************************************************
void DoEvents(PlayerClient* pChar, const char* szLine)
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

					ClearMQ2DataVariables(&pEvent->Parameters);
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

				ClearMQ2DataVariables(&gEventQueue->Parameters);
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
// Function:    Return
// Description: Our '/return' command
// Usage:       /return [value]
// ***************************************************************************
void Return(PlayerClient* pChar, const char* szLine)
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
		EndMacro(pChar, "");
		return;
	}

	if (pStack->LocalVariables)
		ClearMQ2DataVariables(&pStack->LocalVariables);

	if (pStack->Parameters)
		ClearMQ2DataVariables(&pStack->Parameters);

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
// Function:    For
// Description: Our '/for' command
// Usage:       /for v# <start> <to|downto> <end>
// ***************************************************************************
void For(PlayerClient* pChar, const char* szLine)
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
// Function:    Next
// Description: Our '/next' command
// Usage:       /next v#
// ***************************************************************************
void Next(PlayerClient* pChar, const char* szLine)
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
// Function:    Continue
// Description: Our '/continue' command
// Usage:       /continue
// ***************************************************************************
void Continue(PlayerClient* pChar, const char* szLine)
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
// Function:    Break
// Description: Our '/break' command
// Usage:       /break
// ***************************************************************************
void Break(PlayerClient* pChar, const char* szLine)
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

} // namespace mq
