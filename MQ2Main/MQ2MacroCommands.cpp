/*****************************************************************************
MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License, version 2, as published by
the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
******************************************************************************/

#if !defined(CINTERFACE)
#error /DCINTERFACE
#endif
#ifndef ISXEQ

#define DBG_SPEW

#ifdef ISXEQ_LEGACY
#include "../ISXEQLegacy/ISXEQLegacy.h"
#else
#include "MQ2Main.h"
#endif
#include <regex>

VOID FailIf(PSPAWNINFO pChar, PCHAR szCommand, int StartLine, BOOL All)
{
	DWORD Scope = 1;
	if (szCommand[strlen(szCommand) - 1] == '{') {
		if (!gMacroBlock || gMacroBlock && gMacroBlock->Line.find(StartLine) == gMacroBlock->Line.end()) {
			DebugSpewNoFile("FailIf - Macro was ended before we could handle the false if command");
			return;
		}
		std::map<int, MACROLINE>::iterator i = gMacroBlock->Line.find(StartLine);
		i++;//move it forward once...
		gMacroBlock->CurrIndex = i->first;
		for (; i != gMacroBlock->Line.end() && Scope > 0; i++) {
			if (i->second.Command[0] == '}')
				Scope--;
			if (All) {
				if (i->second.Command[i->second.Command.size() - 1] == '{') {
					Scope++;
				}
			}
			if (Scope > 0) {
				if (!All)
					if (i->second.Command[i->second.Command.size() - 1] == '{')
						Scope++;
				if (!_strnicmp(i->second.Command.c_str(), "sub ", 4)) {
					gMacroBlock->CurrIndex = StartLine;
					FatalError("{} pairing ran into anther subroutine");
					return;
				}
				std::map<int, MACROLINE>::iterator forward = i;
				forward++;
				if (forward == gMacroBlock->Line.end()) {
					gMacroBlock->CurrIndex = StartLine;
					FatalError("Bad {} block pairing");
					return;
				}
				gMacroBlock->CurrIndex = forward->first;
			}
		}
		if (gMacroBlock->Line.find(gMacroBlock->CurrIndex) != gMacroBlock->Line.end()) {
			if ((!All) && (!_strnicmp(gMacroBlock->Line[gMacroBlock->CurrIndex].Command.c_str(), "} else ", 7))) {
				DoCommand(pChar, (PCHAR)gMacroBlock->Line[gMacroBlock->CurrIndex].Command.substr(7).c_str());
			}
			else if ((!All) && (!_strnicmp(gMacroBlock->Line[gMacroBlock->CurrIndex].Command.c_str(), "} else", 6))) {
				FatalError("} else lacks command or {");
				return;
			}
			else {
				bRunNextCommand = TRUE;
			}
		}
	}
	else {
		bRunNextCommand = TRUE;
	}
}
// ***************************************************************************
// Function:    Delay
// Description: Our '/delay' command
// Usage:       /delay <time> [condition to end early]
// ***************************************************************************
VOID Delay(PSPAWNINFO pChar, PCHAR szLine)
{
	CHAR szVal[MAX_STRING] = { 0 };
	LONG VarValue;

	if (szLine[0] == 0) {
		SyntaxError("Usage: /delay <time> [condition to end early]");
		return;
	}
	GetArg(szVal, szLine, 1);
	ParseMacroParameter(GetCharInfo()->pSpawn, szVal);
	strcpy_s(gDelayCondition, GetNextArg(szLine));
	VarValue = atol(szVal);
	switch (szVal[strlen(szVal) - 1]) {
	case 'm':
	case 'M':
		VarValue *= 60;
	case 's':
	case 'S':
		if (strlen(szVal) > 2 && szVal[strlen(szVal) - 2] == 'm' || szVal[strlen(szVal) - 2] == 'M')
		{
			VarValue /= 100;
		}
		else
		{
			VarValue *= 10;
		}
	}
	gDelay = VarValue;
	bRunNextCommand = false;
	if (gDelayCondition[0]) {
		CHAR szCond[MAX_STRING];
		strcpy_s(szCond, gDelayCondition);
		ParseMacroParameter(GetCharInfo()->pSpawn, szCond);
		DOUBLE Result;
		if (!Calculate(szCond, Result)) {
			FatalError("Failed to parse /delay condition '%s', non-numeric encountered", szCond);
			return;
		}
		if (Result != 0) {
			// DebugSpewNoFile("/delay ending early, conditions met");
			gDelay = 0;
			bRunNextCommand = true;
		}
	}
}
PCHAR GetFuncParam(PCHAR szMacroLine, DWORD ParamNum, PCHAR szParamName, size_t ParamNameLen, PCHAR szParamType, size_t ParamTypeLen)
{
	szParamName[0] = 0;
	szParamType[0] = 0;
	if (_strnicmp(szMacroLine, "sub ", 4))
		return NULL;
	PCHAR szSubParamNamePointer = szMacroLine + 4;
	while ((szSubParamNamePointer[0] != '(') && (szSubParamNamePointer[0] != 0))
	{
		szSubParamNamePointer++;
	}
	if (szSubParamNamePointer[0] == '(')
		szSubParamNamePointer++;
	if (szSubParamNamePointer[0] != 0)
	{
		CHAR Temp[MAX_STRING] = { 0 };
		GetArg(Temp, szSubParamNamePointer, ParamNum + 1, TRUE, TRUE, TRUE, ',');
		//DebugSpew("GetFuncParam(%d): '%s'",ParamNum+1,Temp);
		if (*Temp && Temp[strlen(Temp) - 1] == ')')
			Temp[strlen(Temp) - 1] = 0;
		PCHAR pStart = &Temp[0];
		while (*pStart == ' ')
			++pStart;
		if (pStart != &Temp[0])
			memmove(Temp, pStart, MAX_STRING - 1);
		if (PCHAR pSpace = strchr(Temp, ' '))
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
VOID CleanMacroLine(PCHAR szLine)
{
	if (!szLine || szLine[0] == 0)
		return;
	PCHAR pChar = szLine;
	while (pChar[0])
	{
		if (pChar[0] == '\t' || pChar[0] == 0x0a || pChar[0] == 0x0d)
			pChar[0] = ' ';
		++pChar;
	}
	// find beginning and end
	PCHAR pStart = szLine;
	unsigned long Length = strlen(szLine);
	PCHAR pEnd = &szLine[Length - 1];

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
	unsigned long NewLength = 1 + pEnd - pStart;
	if (NewLength == Length)
		return;//nothing to do

	memmove(szLine, pStart, NewLength);
	if (szLine && strlen(szLine) >= NewLength)
		szLine[NewLength] = '\0';
}

// ***************************************************************************
// Function:    Include
// Description: Includes another macro file
// Usage:       #include <filename>					(Sets bIgnoreFileCheck 0)
// Usage:		#include_optional <filename>		(Sets bIgnoreFileCheck 1)
// ***************************************************************************
DWORD Include(PCHAR szFile, int *LineNumber, bool bIgnoreFileCheck)
{
	CHAR szTemp[MAX_STRING] = { 0 };
	FILE *fMacro = 0;
	errno_t err = fopen_s(&fMacro, szFile, "rt");
	BOOL InBlockComment = FALSE;
	char *tmp;
	if (err) {
		if (bIgnoreFileCheck) {
			// Optional include. Return 1 so we don't end macro.
			return 1;
		}
		else {
			FatalError("Couldn't open include file: %s", szFile);
			return 0;
		}
	}
	int LocalLine = 0;
	PCHAR Macroname = GetFilenameFromFullPath(szFile);
	DebugSpewNoFile("Include - Including: %s", szFile);
	while (!feof(fMacro)) {

		tmp = fgets(szTemp, MAX_STRING, fMacro);

		if (!tmp && feof(fMacro)) break;

		CleanMacroLine(szTemp);
		LocalLine++;
		(*LineNumber)++;

		if (!strncmp(szTemp, "|**", 3)) {
			InBlockComment = TRUE;
		}
		if (!InBlockComment) {
			if (!AddMacroLine(Macroname, szTemp, MAX_STRING, LineNumber, LocalLine)) {
				MacroError("Unable to add macro line.");
				fclose(fMacro);
				gszMacroName[0] = 0;
				gRunning = 0;
				return 0;
			}
		}
		else {
			DebugSpewNoFile("Macro - BlockComment: %s", szTemp);
			if (!strncmp(&szTemp[strlen(szTemp) - 3], "**|", 3)) {
				InBlockComment = FALSE;
			}
		}
	}
	fclose(fMacro);
	return 1;
}

// ***************************************************************************
// Function:    AddMacroLine
// Description: Add a line to the MacroBlock
// ***************************************************************************
BOOL AddMacroLine(PCHAR FileName, PCHAR szLine, size_t Linelen, int *LineNumber, int localLine)
{
	// replace all tabs with spaces
	if ((szLine[0] == 0) || (szLine[0] == '|'))
		return TRUE;

	PDEFINE pDef = pDefines;
	if (szLine[0] != '#') while (pDef) {
		while (strstr(szLine, pDef->szName)) {
			CHAR szNew[MAX_STRING] = { 0 };
			strncpy_s(szNew, szLine, strstr(szLine, pDef->szName) - szLine);
			strcat_s(szNew, pDef->szReplace);
			strcat_s(szNew, strstr(szLine, pDef->szName) + strlen(pDef->szName));
			strcpy_s(szLine, Linelen, szNew);
		}
		pDef = pDef->pNext;
	}
	if (szLine[0] == '#') {
		if (!_strnicmp(szLine, "#include ", 9)) {
			CHAR Filename[MAX_STRING] = { 0 };
			szLine += 8;
			while (szLine[0] == ' ') szLine++;
			ParseMacroData(szLine, Linelen);
			if (!strstr(szLine, "."))
				strcat_s(szLine, Linelen, ".mac");
			sprintf_s(Filename, "%s\\%s", gszMacroPath, szLine);

			//DebugSpewNoFile("AddMacroLine - Including file: %s",Filename);
			return (BOOL)Include(Filename, LineNumber, 0);
		} else if (!_strnicmp(szLine, "#include_optional ", 18)) {
			CHAR Filename[MAX_STRING] = { 0 };
			szLine += 18;
			while (szLine[0] == ' ') szLine++;
			ParseMacroData(szLine, Linelen);
			if (!strstr(szLine, "."))
				strcat_s(szLine, Linelen, ".mac");
			sprintf_s(Filename, "%s\\%s", gszMacroPath, szLine);

			//DebugSpewNoFile("AddMacroLine - Including file: %s",Filename);
			return (BOOL)Include(Filename, LineNumber, 1);
		}
		else if (!_strnicmp(szLine, "#warning", 8)) {
			gWarning = TRUE;
		}
		else if (!_strnicmp(szLine, "#turbo", 6)) {
			gTurbo = TRUE;
			CHAR szArg[MAX_STRING] = { 0 };
			GetArg(szArg, szLine, 2);
			gMaxTurbo = atoi(szArg);
			if (gMaxTurbo == 0)
				gMaxTurbo = 80;
			else if (gMaxTurbo>gTurboLimit)
			{
				MacroError("#turbo %d is too high, setting at %d (maximum)", gMaxTurbo, gTurboLimit);
				gMaxTurbo = gTurboLimit;
			}
		}
		else if (!_strnicmp(szLine, "#define ", 8)) {
			CHAR szArg1[MAX_STRING] = { 0 };
			CHAR szArg2[MAX_STRING] = { 0 };
			PDEFINE pDef = (PDEFINE)malloc(sizeof(DEFINE));
			GetArg(szArg1, szLine, 2);
			GetArg(szArg2, szLine, 3);
			if ((szArg1[0] != 0) && (szArg2[0] != 0)) {
				strcpy_s(pDef->szName, szArg1);
				strcpy_s(pDef->szReplace, szArg2);
				pDef->pNext = pDefines;
				pDefines = pDef;
			}
			else {
				MacroError("Bad #define: %s", szLine);
			}
		}
		else if (!_strnicmp(szLine, "#event ", 7)) {
			CHAR szArg1[MAX_STRING] = { 0 };
			CHAR szArg2[MAX_STRING] = { 0 };
			PEVENTLIST pEvent = (PEVENTLIST)malloc(sizeof(EVENTLIST));
			GetArg(szArg1, szLine, 2);
			GetArg(szArg2, szLine, 3);
			if ((szArg1[0] != 0) && (szArg2[0] != 0)) {
				sprintf_s(pEvent->szName, "Sub Event_%s", szArg1);
				if (char*pDest = strstr(szArg2, "${")) {
					//its a variable... so we must "/declare" it for them...
					CHAR szVar[MAX_STRING] = { 0 };
					strcpy_s(szVar, &pDest[2]);
					if (pDest = strchr(szVar, '}')) {
						pDest[0] = '\0';
						if (VariableMap.find(szVar) == VariableMap.end()) {
							//we dont know what the macro will varset this to, so we just
							//default it to the same name as the key...
							//cant set it to "" cause then it triggers on every single line of
							//chat before they /varset it to something... (if they ever)
							AddMQ2DataVariable(szVar, "", pStringType, &pMacroVariables, "NULL");
						}
					}
				}
				strcpy_s(pEvent->szMatch, szArg2);
#ifdef USEBLECHEVENTS
				pEvent->BlechID = pEventBlech->AddEvent(pEvent->szMatch, EventBlechCallback, pEvent);
#endif
				pEvent->pEventFunc = NULL;
				pEvent->pNext = pEventList;
				pEventList = pEvent;
			}
			else {
				MacroError("Bad #event: %s", szLine);
			}
		}
		else if (!_strnicmp(szLine, "#bind ", 6))
		{
			CHAR szArg1[MAX_STRING] = { 0 };
			CHAR szArg2[MAX_STRING] = { 0 };
			PBINDLIST pBind = (PBINDLIST)malloc(sizeof(BINDLIST));
			GetArg(szArg1, szLine, 2);
			GetArg(szArg2, szLine, 3);
			if ((szArg1[0] != 0) && (szArg2[0] != 0)) {
				sprintf_s(pBind->szFuncName, "Bind_%s", szArg1);
				strcpy_s(pBind->szName, szArg2);
				pBind->pNext = pBindList;
				pBindList = pBind;
			}
			else
			{
				MacroError("Bad #bind: %s", szLine);
			}
		}
		else if (!_strnicmp(szLine, "#bind_noparse ", 14)) {
			if (gdwParserEngineVer == 2) {
				CHAR szArg1[MAX_STRING] = { 0 };
				CHAR szArg2[MAX_STRING] = { 0 };
				PBINDLIST pBind = static_cast<PBINDLIST>(malloc(sizeof(BINDLIST)));
				GetArg(szArg1, szLine, 2);
				GetArg(szArg2, szLine, 3);
				if ((szArg1[0] != 0) && (szArg2[0] != 0)) {
					sprintf_s(pBind->szFuncName, "Bind_NoParse_%s", szArg1);
					strcpy_s(pBind->szName, szArg2);
					pBind->Parse = false;
					pBind->pNext = pBindList;
					pBindList = pBind;
				}
				else {
					MacroError(static_cast<char*>("Bad #bind_noparse: %s"), szLine);
				}
			}
			else {
				MacroError(static_cast<char*>("#bind_noparse requires enabling Parser Version 2."));
			}
		}
		else if (!_strnicmp(szLine, "#engine ", 8)) {
			std::string strLine = szLine;
			strLine = strLine.substr(8, strLine.length()) + " noauto";
			strcpy_s(szLine, strLine.length() + 1, strLine.c_str());
			EngineCommand(GetCharInfo()->pSpawn, szLine);
		}
		else if (!_strnicmp(szLine, "#chat ", 6)) {
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
		else if (szLine[1] == '!') {
			// Like: #!/usr/local/bin/LegacyMQ2
			// ignore.
		}
		else {
			MacroError("Unknown # command: %s", szLine);
			return FALSE;
		}
	}

	if ((!_stricmp(szLine, "Sub Event_Chat")) || (!_strnicmp(szLine, "Sub Event_Chat(", 15))) {
		gEventFunc[EVENT_CHAT] = *LineNumber;
	}
	else if ((!_stricmp(szLine, "Sub Event_Timer")) || (!_strnicmp(szLine, "Sub Event_Timer(", 16))) {
		gEventFunc[EVENT_TIMER] = *LineNumber;
	}
	else {
		PEVENTLIST pEvent = pEventList;
		while (pEvent) {
			if (!_stricmp(szLine, pEvent->szName)) {
				pEvent->pEventFunc = *LineNumber;
			}
			else {
				CHAR szNameP[MAX_STRING] = { 0 };
				sprintf_s(szNameP, "%s(", pEvent->szName);
				if (!_strnicmp(szLine, szNameP, strlen(szNameP))) {
					pEvent->pEventFunc = *LineNumber;
				}
			}
			pEvent = pEvent->pNext;
		}
	}

#ifdef MQ2_PROFILING
	gMacroBlock->Line[*LineNumber].ExecutionCount = 0;
	gMacroBlock->Line[*LineNumber].ExecutionTime = 0;
#endif
	auto& MacroLine = gMacroBlock->Line[*LineNumber];
	MacroLine.Command = szLine;
	MacroLine.LineNumber = localLine;
	MacroLine.LoopStart = 0;
	MacroLine.LoopEnd = 0;
	MacroLine.SourceFile = FileName;

	static const std::regex subrx("^sub (\\w+)", std::regex_constants::icase);
	std::cmatch submatch;
	if (std::regex_search(szLine, submatch, subrx))
	{
		gMacroSubLookupMap[submatch.str(1)] = *LineNumber;
	}
	return TRUE;
}

std::map<std::string, PMACROBLOCK> MacroBlockMap;

PMACROBLOCK AddMacroBlock(std::string Name)
{
	auto macroBlock = std::make_shared<MACROBLOCK>();
	macroBlock->CurrIndex = 0;
	macroBlock->BindStackIndex = -1;
	macroBlock->Name = Name;
	macroBlock->Paused = 0;
	macroBlock->Removed = false;
	MacroBlockMap.insert_or_assign(Name, macroBlock);

	return macroBlock;
}

void RemoveMacroBlock(std::string Name)
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

bool GetMacroBlock(char* Name, PMACROBLOCK* pBlock)
{
	auto iter = MacroBlockMap.find(Name);
	if (iter != MacroBlockMap.end())
	{
		*pBlock = iter->second;
		return true;
	}

	// we return the first one if they didnt specify a name.
	if (!MacroBlockMap.empty())
	{
		*pBlock = MacroBlockMap.begin()->second;
	}

	return false;
}

PMACROBLOCK GetNextMacroBlock()
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

PMACROBLOCK GetCurrentMacroBlock()
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
	return MacroBlockMap.size();
}

// ***************************************************************************
// Function:    Macro
// Description: Our '/macro' command
// Usage:       /macro <filename>
// ***************************************************************************
VOID Macro(PSPAWNINFO pChar, PCHAR szLine)
{
	gWarning = FALSE;
	bRunNextCommand = TRUE;
	CHAR szTemp[MAX_STRING] = { 0 };
	CHAR Filename[MAX_STRING] = { 0 };
	PCHAR Params = NULL;
	PCHAR szNext = NULL;
	BOOL InBlockComment = FALSE;
	if (szLine[0] == 0) {
		SyntaxError("Usage: /macro <filename> [param [param...]]");
		return;
	}

	PMACROBLOCK pBlock = 0;
	bool ret = GetMacroBlock(szLine,&pBlock);

	if (gMacroBlock && !gMacroBlock->Line.empty())
	{
		gReturn = false;
		EndMacro(pChar, szLine);
		gReturn = true;
	}

	if (CXWnd*pWnd = FindMQ2Window("RunningMacrosWindow"))
	{
		if (CListWnd*list = (CListWnd*)pWnd->GetChildItem("RMW_RunningMacrosList"))
		{
			list->DeleteAll();
		}
	}

	gBindInProgress = true;//we dont want people to use binds until the macro is read.
	// we get ourself a new block, this will be valid until the macro ends.
	gMacroBlock = AddMacroBlock(szLine);

	gMaxTurbo = 80;
	gTurbo = true;
	GetArg(szTemp, szLine, 1);
	Params = GetNextArg(szLine);

	strcpy_s(gszMacroName, szTemp);

#ifdef ISXEQ_LEGACY
	strcpy_s(Filename, szTemp);
	FILE *fMacro = 0;
	errno_t err = fopen_s(&fMacro, szTemp, "rt");
#else
	if (!strstr(szTemp, ".")) strcat_s(szTemp, ".mac");
	sprintf_s(Filename, "%s\\%s", gszMacroPath, szTemp);

	FILE* fMacro = nullptr;
	errno_t err = fopen_s(&fMacro, Filename, "rt");
#endif

	if (err)
	{
		FatalError("Couldn't open macro file: %s", Filename);
		gszMacroName[0] = 0;
		gRunning = 0;
		return;
	}

	gEventChat = 0;
	strcpy_s(gszMacroName, szTemp);
	DebugSpew("Macro - Loading macro: %s", Filename);
	int LineIndex = 0;
	int LocalLine = 0;
	gMacroSubLookupMap.clear();

	PCHAR Macroname = GetFilenameFromFullPath(Filename);
	while (!feof(fMacro)) {
		fgets(szTemp, MAX_STRING, fMacro);
		CleanMacroLine(szTemp);
		LineIndex++;
		LocalLine++;
		if (!strncmp(szTemp, "|**", 3)) {
			InBlockComment = TRUE;
		}
		if (!InBlockComment) {
			if (!AddMacroLine(Macroname, szTemp, MAX_STRING, &LineIndex, LocalLine)) {
				MacroError("Unable to add macro line.");
				fclose(fMacro);
				gszMacroName[0] = 0;
				gRunning = 0;
				return;
			}
		}
		else {
			DebugSpew("Macro - BlockComment: %s", szTemp);
			if (!strncmp(&szTemp[strlen(szTemp) - 3], "**|", 3)) {
				InBlockComment = FALSE;
			}
		}
	}
	fclose(fMacro);
	PDEFINE pDef;
	while (pDefines) {
		pDef = pDefines->pNext;
		free(pDefines);
		pDefines = pDef;
	}
	strcpy_s(szTemp, "Main");
	if (Params[0] != 0) {
		strcat_s(szTemp, " ");
		strcat_s(szTemp, Params);
	}
	DebugSpew("Macro - Starting macro with '/call %s'", szTemp);
	Call(pChar, szTemp);
	if (!gMacroBlock) {
		MacroError("Not a valid macrofile %s no Sub Main found.",Macroname);
		gszMacroName[0] = 0;
		gRunning = 0;
		return;
	}
	//std::advance(gMacroBlock->CurrIndex, 1);
	std::map<int, MACROLINE>::iterator i = gMacroBlock->Line.find(gMacroBlock->CurrIndex);
	if (i != gMacroBlock->Line.end()) {
		std::advance(i, 1);
		gMacroBlock->CurrIndex = i->first;
	}

	if ((!gMacroBlock) || (!gMacroStack)) {
		gszMacroName[0] = 0;
		gRunning = 0;
	}
#ifdef ISXEQ_LEGACY
	else
	{
		char ShortName[128];
		ShortName[0] = 0;
		_splitpath(Filename, 0, 0, ShortName, 0);
		IS_ScriptEngineScriptBegins(pExtension, pISInterface, hScriptEngineService, &g_LegacyEngine, ShortName);
	}
#endif
	gRunning = MQGetTickCount64();
	gBindInProgress = false;
	if (CXWnd*pWnd = FindMQ2Window("RunningMacrosWindow"))
	{
		pWnd->SetVisible(true);
		if (CListWnd*list = (CListWnd*)pWnd->GetChildItem("RMW_RunningMacrosList"))
		{
			int id = list->AddString("", 0xFF00FF00, 0, 0);
			list->SetItemText(id, 1, &CXStr(Macroname));
		}
	}
}

// ***************************************************************************
// Function:    Cleanup
// Description: Our '/cleanup' command
//              Sends i, esc, esc, esc, esc, i
// Usage:       /cleanup
// ***************************************************************************
VOID Cleanup(PSPAWNINFO pChar, PCHAR szLine)
{
	DebugSpewNoFile("Cleanup - Cleaning up screen");
	DWORD i;
	KeyCombo Escape;
	ParseKeyCombo("Esc", Escape);
	if (ppContainerMgr && pContainerMgr) {
		CContainerMgr *ContainerMgr = (CContainerMgr*)pContainerMgr;
		DWORD concount = 2; //Close inv + clear target
		if (ContainerMgr->pWorldContainer.pObject && ContainerMgr->pWorldContainer.pObject->Open == 1)
			concount++;
		for (i = 0; i < MAX_CONTAINERS; i++) {
			if (ContainerMgr->pContainerWnds[i] && ContainerMgr->pContainerWnds[i]->IsVisible() == 1)
				concount++;
		}
		for (i = 0; i<concount; i++)
		{
			MQ2HandleKeyDown(Escape);
			MQ2HandleKeyUp(Escape);
		}
		if (!ppInventoryWnd) {
			PCSIDLWND pInvWindow = (PCSIDLWND)pInventoryWnd;
			if (pInvWindow && pInvWindow->IsVisible() == 0)
				DoMappable(pChar, "inventory");
		}
	}
	else {
		DoMappable(pChar, "inventory");
		for (i = 0; i<10; i++)
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
VOID Goto(PSPAWNINFO pChar, PCHAR szLine)
{
	if (!gMacroBlock) {
		MacroError("Cannot goto when a macro isn't running.");
		return;
	}
	bRunNextCommand = TRUE;
	int FromIndex = gMacroBlock->CurrIndex;
	const auto goto_line = gMacroBlock->Line.find(FromIndex);
	if (goto_line->second.LoopEnd)
	{
		gMacroBlock->CurrIndex = goto_line->second.LoopEnd;
		return;
	}
	std::map<int, MACROLINE>::reverse_iterator ri(goto_line);
	//search up first we only search until we find a "Sub "
	for (; ri != gMacroBlock->Line.rend(); ri++)
	{
		if (!_strnicmp(ri->second.Command.c_str(), "Sub ", 4)) {
			ri--;
			FromIndex = ri->first;
			break;
		}
		if (!_stricmp(szLine, ri->second.Command.c_str()))
		{
			//Label found....
			gMacroBlock->CurrIndex = ri->first;
			goto_line->second.LoopEnd = ri->first;
			return;
		}
	}
	//now that we found our start lets look forward for the goto label:
	std::map<int, MACROLINE>::iterator i = gMacroBlock->Line.find(FromIndex);
	for (; i != gMacroBlock->Line.end(); i++)
	{
		if (!_strnicmp(i->second.Command.c_str(), "Sub ", 4))
		{
			break;
		}
		if (!_stricmp(szLine, i->second.Command.c_str()))
		{
			//Label found....
			//            DebugSpewNoFile("Goto - went to label %s",szLine);
			gMacroBlock->CurrIndex = i->first;
			goto_line->second.LoopEnd = i->first;
			return;
		}
	}
	FatalError("Couldn't find label %s", szLine);
}

VOID DumpStack(PSPAWNINFO pChar, PCHAR szLine)
{
	CHAR szTemp[MAX_STRING] = { 0 };
	CHAR szSub[MAX_STRING] = { 0 };
	PMACROSTACK pMS = gMacroStack;
	PMACROBLOCK pMB = 0;
	MACROLINE ml;
	while (pMS != NULL) {
		if (gMacroBlock->Line.find(pMS->LocationIndex) != gMacroBlock->Line.end()) {
			ml = gMacroBlock->Line[pMS->LocationIndex];
		}
		//sprintf_s(szTemp, "%s@%d (%s): %s", pMS->Location->SourceFile.c_str(), pMS->Location->LineNumber, GetSubFromLine(pMS->Location, szSub, MAX_STRING), pMS->Location->Line.c_str());
		sprintf_s(szTemp, "%s@%d (%s): %s", ml.SourceFile.c_str(), ml.LineNumber, GetSubFromLine(pMS->LocationIndex, szSub, MAX_STRING), ml.Command.c_str());
		WriteChatColor(szTemp, USERCOLOR_DEFAULT);
		if (bAllErrorsLog) MacroLog(NULL, szTemp);
		pMS = pMS->pNext;
	}
}

// ***************************************************************************
// Function:    EndMacro
// Description: Our '/endmacro' command
// Usage:       /endmacro
// ***************************************************************************
VOID EndMacro(PSPAWNINFO pChar, PCHAR szLine)
{
	CHAR szArg1[MAX_STRING] = { 0 };
	CHAR szArg2[MAX_STRING] = { 0 };
	CHAR szArg3[MAX_STRING] = { 0 };
	CHAR MacroName[MAX_STRING] = { 0 };
	BOOL bKeepKeys = gKeepKeys;
	if (strstr(szLine, "keep keys")) {
		bKeepKeys = TRUE;
	}
	GetArg(szArg1, szLine, 1);
	if (szArg1[0] != '\0') {
		if (_stricmp(szArg1, "keep")) {
			strcpy_s(MacroName, szArg1);
		}
	}
	DWORD i;
	gWarning = FALSE;
	PMACROSTACK pStack;
	PEVENTQUEUE pEvent;
	PEVENTLIST pEventL;
	PBINDLIST pBindL;
	PMACROBLOCK pBlock = 0;

	GetMacroBlock(MacroName,&pBlock);
	if (!pBlock) {
		MacroError("Cannot end a macro when one isn't running.");
		return;
	}
	/////////////// 
	// Code allowing for a routine for "OnExit"
	for (std::map<int, MACROLINE>::iterator i = pBlock->Line.begin(); i != pBlock->Line.end(); i++)
	{
		if (!_stricmp(":OnExit", i->second.Command.c_str()))
		{
			i++;
			pBlock->CurrIndex = i->first;
			if (gReturn)            // return to the macro the first time around
			{
				gReturn = false;    // We don't want to return the 2nd time.
				return;
			}
			else
				break;
		}
	}
	// Set the parser back to whatever the default is
	const DWORD dwTemp = GetPrivateProfileInt("MacroQuest", ("Parser" + ENGINE_SWITCH_CMD).c_str(),1,gszINIFilename);
	if (dwTemp != gdwParserEngineVer) {
		gdwParserEngineVer = dwTemp;
		WriteChatColor(static_cast<char*>("Parser Version Reset to your default."), USERCOLOR_DEFAULT);
	}
	gReturn = true;            // reset for next time
							   //
							   ///////////////
#ifdef MQ2_PROFILING
							   // How many performance counters in 1 second?
	LARGE_INTEGER PerformanceFrequency;
	QueryPerformanceCounter(&PerformanceFrequency);

	CHAR Filename[MAX_STRING] = { 0 };
	FILE *fMacro = NULL;
	for (std::map<int, MACROLINE>::iterator i = pBlock->Line.begin(); i != pBlock->Line.end(); i++) {
		// Is this a different macro file?
		if (strcmp(Filename, i->second.SourceFile.c_str())) {
			// Close existing file
			if (fMacro) {
				fclose(fMacro);
			}
			// Open new profiling log file
			strcpy_s(Filename, i->second.SourceFile.c_str());
			sprintf_s(Buffer, "%s\\%s.mqp", gszMacroPath, Filename);
			errno_t err = fopen_s(&fMacro, Buffer, "w");
			if (!err) {
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
	//delete gMacroBlock;
	gMacroBlock = 0;
	while (gMacroStack) {
		pStack = gMacroStack->pNext;
		if (gMacroStack->LocalVariables)
			ClearMQ2DataVariables(&gMacroStack->LocalVariables);
		if (gMacroStack->Parameters)
			ClearMQ2DataVariables(&gMacroStack->Parameters);
		DebugSpewNoFile("EndMacro: Deleting gMacroStack");
		free(gMacroStack);
		gMacroStack = pStack;
	}
	gMacroSubLookupMap.clear();
	gUndeclaredVars.clear();
	while (gEventQueue) {
		pEvent = gEventQueue->pNext;
		DebugSpewNoFile("EndMacro: Deleting gEventQueue %d %s", gEventQueue->Type, gEventQueue->Name.c_str());
		delete gEventQueue;
		gEventQueue = pEvent;
	}
	while (pEventList) {
		pEventL = pEventList->pNext;
		DebugSpewNoFile("EndMacro: Deleting pEventList %d %s", pEventList->BlechID, pEventList->szName);
		free(pEventList);
		pEventList = pEventL;
	}
	while (pBindList) {
		pBindL = pBindList->pNext;
		DebugSpewNoFile("EndMacro: Deleting pBindList %s", pBindList->szName);
		free(pBindList);
		pBindList = pBindL;
	}
#ifdef USEBLECHEVENTS
	pEventBlech->Reset();
#endif
	for (i = 0; i<NUM_EVENTS; i++) {
		gEventFunc[i] = NULL;
	}
	gEventChat = 0;
	gFaceAngle = 10000.0f;
	gLookAngle = 10000.0f;
	gDelay = 0;
	gTurbo = FALSE;
	pDoorTarget = NULL;
#ifdef ISXEQ_LEGACY
	char ShortName[128];
	ShortName[0] = 0;
	_splitpath(gszMacroName, 0, 0, ShortName, 0);
	IS_ScriptEngineScriptEnds(pExtension, pISInterface, hScriptEngineService, &g_LegacyEngine, ShortName);
#endif

	gszMacroName[0] = 0;
	gRunning = 0;

	if (!bKeepKeys) {
		KeyCombo TempCombo;
		for (i = 0; gDiKeyID[i].szName[0]; i++)
		{
			TempCombo.Data[3] = (unsigned char)gDiKeyID[i].Id;
			MQ2HandleKeyUp(TempCombo);
		}
	}

	ClearMQ2DataVariables(&pMacroVariables);

	DebugSpewNoFile("EndMacro - Ended");
	if (gFilterMacro != FILTERMACRO_NONE && gFilterMacro != FILTERMACRO_MACROENDED)
		WriteChatColor("The current macro has ended.", USERCOLOR_DEFAULT);
}

int GetNumArgsFromSub(std::string &Sub)
{
	if (size_t hasparams = std::count(Sub.begin(), Sub.end(), '(')) {
		size_t n = std::count(Sub.begin(), Sub.end(), ',');
		return n + 1;
	}
	return 0;

}
// ***************************************************************************
// Function:    Call
// Description: Our '/call' command
// Usage:       /call <Subroutine>
// ***************************************************************************
VOID Call(PSPAWNINFO pChar, PCHAR szLine)
{
	if (szLine[0] == 0) {
		SyntaxError("Usage: /call <subroutine> [param [param...]]");
		return;
	}
	if (!gMacroBlock || (gMacroBlock && gMacroBlock->Line.size() == 0)) {
		MacroError("Cannot call when a macro isn't running.");
		return;
	}
	bRunNextCommand = TRUE;
	CHAR SubName[MAX_STRING];
	GetArg(SubName, szLine, 1);
	PCHAR SubParam = GetNextArg(szLine);

	// Sub in Map?
	auto iter = gMacroSubLookupMap.find(SubName);
	if (iter == gMacroSubLookupMap.end()) {
		FatalError("Subroutine %s wasn't found", SubName);
		return;
	}
	int MacroLine = iter->second;

	// Prep to call the Sub
	auto pStack = (PMACROSTACK)calloc(1, sizeof(MACROSTACK));
	if (pStack == nullptr) {
		MacroError("Failed to allocate pStack for /call");
		return;
	}
	gMacroBlock->CurrIndex = MacroLine;
	pStack->LocationIndex = MacroLine;
	pStack->bIsBind = false;
	pStack->Return[0] = '\0';
	pStack->Parameters = NULL;
	pStack->LocalVariables = NULL;
	pStack->pNext = gMacroStack;
	if (gMacroStack && gMacroBlock->BindStackIndex != -1) {
		//we need to check the stackchain now for the start of the bind
		PMACROSTACK pBindStack = gMacroStack;
		bool bBindStackFound = false;
		while (pBindStack) {
			if (pBindStack->bIsBind == true) {
				bBindStackFound = true;
				break;
			}
			pBindStack = pBindStack->pNext;
		}
		if (!bBindStackFound) {
			pStack->bIsBind = true;
		}
	}
	gMacroStack = pStack;

	MACROLINE ml = gMacroBlock->Line[MacroLine];
	int numsubargs = GetNumArgsFromSub(ml.Command);
	if ((SubParam && SubParam[0]!='\0') || numsubargs) {
		CHAR szParamName[MAX_STRING] = { 0 };
		CHAR szParamType[MAX_STRING] = { 0 };
		CHAR szNewValue[MAX_STRING] = { 0 };
		auto name = (PCHAR)ml.Command.c_str();
		for (int StackNum = 0; StackNum < numsubargs || SubParam[0] != '\0'; StackNum++) {
			GetArg(szNewValue, SubParam, 1);
			GetFuncParam(name, StackNum, szParamName, MAX_STRING, szParamType, MAX_STRING);
			MQ2Type *pType = FindMQ2DataType(szParamType);
			if (!pType)
				pType = pStringType;

			AddMQ2DataVariable(szParamName, "", pType, &gMacroStack->Parameters, szNewValue);
			SubParam = GetNextArg(SubParam);
		}
	}
}

VOID NewIf(PSPAWNINFO pChar, PCHAR szLine)
{
	if (szLine[0] != '(')
	{
		FatalError("Failed to parse /if command.  Expected () around conditions.");
		SyntaxError("Usage: /if (<conditions>) <command>");
		return;
	}

	PCHAR pEnd = &szLine[1];
	DWORD nParens = 1;
	while (1)
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

	*pEnd = 0;
	CHAR szCond[MAX_STRING] = { 0 };
	strcpy_s(szCond, szLine);
	*pEnd = ' ';
	++pEnd;

	DOUBLE Result = 0;
	if (!Calculate(szCond, Result))
	{
		FatalError("Failed to parse /if condition '%s', non-numeric encountered", szCond);
		return;
	}

	if (Result != 0) {
		if (gdwParserEngineVer == 2) 
		{
			// Due to the way that MQ2 currently processes the whole line before reaching this point:
			// At this point the command has already passed through the parser once.  We don't want
			// it to be parsed again since the parser already knew how to handle it and has given us
			// the correct output.  So let's wrap this in a ${Parse[0 until we can fix /if to short
			// circuit prior to processing.
			// Cast it as a PCHAR, Modify the command, and run it
			DoCommand(pChar, PCHAR(ModifyMacroString(pEnd, true, 0).c_str()));
		}
		else
		{
			DoCommand(pChar, pEnd);
		}
	}
	else {
		int index = 0;

		if (gMacroBlock && !gMacroBlock->Line.empty())
			index = gMacroBlock->CurrIndex;
		FailIf(pChar, pEnd, index);
	}
}

void pop_loop()
{
	gMacroStack->loop_stack.pop_back();
}

static void push_loop(const Loop& loop)
{
	auto size = gMacroStack->loop_stack.size();
	if (size > 0 && gMacroStack->loop_stack[size - 1].first_line == loop.first_line)
		return;
	gMacroStack->loop_stack.push_back(loop);
}

static void EndWhile()
{
	gMacroBlock->CurrIndex = gMacroBlock->Line[gMacroBlock->CurrIndex].LoopEnd;
	bRunNextCommand = TRUE;
}

static void MarkWhile(PCHAR szCommand, Loop& loop)
{
	if (szCommand[strlen(szCommand) - 1] == '{') {
		loop.type = Loop::Type::While;
		auto i = gMacroBlock->Line.find(gMacroBlock->CurrIndex);
		if (i->second.LoopStart && i->second.LoopEnd)
		{
			loop.first_line = i->second.LoopStart;
			loop.last_line = i->second.LoopEnd;
			return;
		}
		const auto current_line = i;
		--i;
		current_line->second.LoopStart = i->first;
		loop.first_line = i->first;
		++i;
		int Scope = 1;
		while (++i != gMacroBlock->Line.end())
		{
			if (i->second.Command[0] == '}') {
				--Scope;
				if (Scope == 0) break;
			}
			if (i->second.Command[i->second.Command.size() - 1] == '{') {
				++Scope;
			}
			else if (!_strnicmp(i->second.Command.c_str(), "sub ", 4)) {
				FatalError("{} pairing ran into anther subroutine");
				return;
			}
		}
		if (Scope != 0)
		{
			FatalError("No } found for /while");
			return;
		}
		i->second.LoopStart = loop.first_line;
		loop.last_line = i->first;
		current_line->second.LoopEnd = i->first;
	}
	else {
		//its a /while (something) /dosomething
		//we cant support that kind of /while cause I cant figure out how to do it -eqmule
		//feel free to enlighten me.
		//se we loop to same line over and over i guess...
		FatalError("You have a /while block that's not enclosed in {}");
		return;
	}
}

// ***************************************************************************
// Function:    While
// Description: Our '/while' command
// Usage:       /while (cond) {
//                   ....
//              }
// ***************************************************************************
VOID WhileCmd(PSPAWNINFO pChar, PCHAR szLine)
{
	CHAR szCond[MAX_STRING] = { 0 };

	if (szLine[0] != '(')
	{
		FatalError("Failed to parse /while command.  Expected () around conditions.");
		SyntaxError("Usage: /while (<conditions>) <command>");
		return;
	}

	PCHAR pEnd = &szLine[1];
	DWORD nParens = 1;
	while (1)
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

	*pEnd = 0;
	strcpy_s(szCond, szLine);
	*pEnd = ' ';
	++pEnd;

	DOUBLE Result = 0;
	if (!Calculate(szCond, Result))
	{
		FatalError("Failed to parse /while condition '%s', non-numeric encountered", szCond);
		return;
	}

	//lets check all the lines within it
	//and mark the end so the interpreter knows when to exit it
	Loop loop;
	MarkWhile(pEnd, loop);
	if (!gMacroBlock)
		return;
	if (Result != 0)
		push_loop(loop);
	else
		EndWhile();
}

// ***************************************************************************
// Function:    DoEvents
// Description: Our '/doevents' command
// Usage:       /doevents [flush] [custom event]
// ***************************************************************************
VOID DoEvents(PSPAWNINFO pChar, PCHAR szLine)
{
	if (!gEventQueue || !gMacroStack)
		return;
	CHAR Arg1[MAX_STRING] = { 0 };
	CHAR Arg2[MAX_STRING] = { 0 };

	GetArg(Arg1, szLine, 1);

	if (!_stricmp(Arg1, "flush"))
	{
		GetArg(Arg2, szLine, 2);
		if (Arg2[0])
		{
			sprintf_s(Arg1, "Sub Event_%s", Arg2);
			PEVENTQUEUE pEvent = gEventQueue;
			while (pEvent)
			{
				if (
					(pEvent->Type == EVENT_CHAT && !_stricmp("Sub Event_Chat", Arg1)) ||
					(pEvent->Type == EVENT_TIMER && !_stricmp("Sub Event_Timer", Arg1)) ||
					(pEvent->Type == EVENT_CUSTOM && !_stricmp(pEvent->pEventList->szName, Arg1))
					)
				{
					PEVENTQUEUE pEventNext;
					if (pEventNext = pEvent->pNext)
						pEventNext->pPrev = pEvent->pPrev;
					if (pEvent->pPrev)
						pEvent->pPrev->pNext = pEvent->pNext;
					else
						gEventQueue = pEvent->pNext;
					ClearMQ2DataVariables(&pEvent->Parameters);
					DebugSpewNoFile("Doevents: Deleting pEvent %d %s", pEvent->Type, pEvent->Name.c_str());
					//free(pEvent);
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
				PEVENTQUEUE pEventNext = gEventQueue->pNext;
				ClearMQ2DataVariables(&gEventQueue->Parameters);
				DebugSpewNoFile("Doevents: Deleting gEventQueue %d %s", gEventQueue->Type, gEventQueue->Name.c_str());
				delete gEventQueue;
				gEventQueue = pEventNext;
			}
		}
		return;
	}
	if (gMacroBlock->BindStackIndex != -1) {
		//we need to return if this happens cause if we run an event
		//while a bind is running we screw up the macro stack... -eqmule
		return;
	}
	PEVENTQUEUE pEvent = gEventQueue;
	if (Arg1[0])
	{
		sprintf_s(Arg2, "Sub Event_%s", Arg1);
		while (pEvent)
		{
			if (
				(pEvent->Type == EVENT_CHAT && !_stricmp("Sub Event_Chat", Arg2)) ||
				(pEvent->Type == EVENT_TIMER && !_stricmp("Sub Event_Timer", Arg2)) ||
				(pEvent->Type == EVENT_CUSTOM && !_stricmp(pEvent->pEventList->szName, Arg2))
				)
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

	if (PMACROSTACK pStack = (PMACROSTACK)calloc(1,sizeof(MACROSTACK))) {

		// back the current location to previous one so we fall into
		// /doevents again.
		std::map<int, MACROLINE>::iterator i = gMacroBlock->Line.find(gMacroBlock->CurrIndex);
		i--;
		if (i != gMacroBlock->Line.end())
			pStack->LocationIndex = i->first;
		else {
			Sleep(0);//crap... wtf?
		}
		pStack->Return[0] = 0;
		pStack->Parameters = pEvent->Parameters;
		PDATAVAR pParam = pStack->Parameters;
		while (pParam) // FIX THE HEAD ON EVERY VAR WE MOVED
		{
			pParam->ppHead = &pStack->Parameters;
			pParam = pParam->pNext;
		}
		pStack->bIsBind = false;
		pStack->LocalVariables = NULL;
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
		bRunNextCommand = TRUE;
	}
}


// ***************************************************************************
// Function:    Return
// Description: Our '/return' command
// Usage:       /return [value]
// ***************************************************************************
VOID Return(PSPAWNINFO pChar, PCHAR szLine)
{
	bRunNextCommand = TRUE;
	PMACROSTACK pStack = gMacroStack;
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
	if (!pStack->bIsBind)//binds dont return values...
		strcpy_s(pStack->pNext->Return, szLine);
	gMacroBlock->CurrIndex = pStack->pNext->LocationIndex;
	gMacroStack = pStack->pNext;
	free(pStack);
	//DebugSpewNoFile("Return - Returned to %s",gMacroBlock->Line);
}

// ***************************************************************************
// Function:    For
// Description: Our '/for' command
// Usage:       /for v# <start> <to|downto> <end>
// ***************************************************************************
VOID For(PSPAWNINFO pChar, PCHAR szLine)
{
	bRunNextCommand = TRUE;
	CHAR ArgLoop[MAX_STRING] = { 0 };
	CHAR ArgStart[MAX_STRING] = { 0 };
	CHAR ArgDirection[MAX_STRING] = { 0 };
	CHAR ArgEnd[MAX_STRING] = { 0 };

	GetArg(ArgLoop, szLine, 1);
	GetArg(ArgStart, szLine, 2);
	GetArg(ArgDirection, szLine, 3);
	GetArg(ArgEnd, szLine, 4);
	_strlwr_s(ArgDirection);

	PDATAVAR pVar = FindMQ2DataVariable(ArgLoop);
	if (!pVar)
	{
		FatalError("/for loop using invalid variable");
		return;
	}
	if (pVar->Var.Type != pIntType)
	{
		FatalError("/for loops must use an int variable");
		return;
	}
	if ((ArgStart[0] == 0) || (ArgDirection[0] == 0) || (ArgEnd[0] == 0) || ((strcmp(ArgDirection, "to")) && (strcmp(ArgDirection, "downto")))) {
		FatalError("Usage: /for <variable> <start> <to|downto> <end> [step x]");
		return;
	}
	if (!gMacroBlock) {
		MacroError("Can only use /for during a macro.");
		return;
	}

	if (!pVar->Var.Type->FromString(pVar->Var.VarPtr, ArgStart))
	{
		FatalError("/for loop could not assign value '%s' to variable", ArgStart);
		return;
	}
	Loop loop;
	loop.type = Loop::Type::For;
	loop.first_line = gMacroBlock->CurrIndex;
	loop.last_line = 0;
	loop.for_variable = ArgLoop;
	push_loop(loop);
	/*I want to do this, but people have been doing shit like /for i 1 to 1 for years and they count on it to go through once... 
	int iStart = atoi(ArgStart);
	int iEnd = atoi(ArgEnd);
	if (iStart >= iEnd) {
		//nope, not gonna do it, a for loop should only execute when start is less than end
		Break((PSPAWNINFO)pLocalPlayer, NULL);
	}*/
}

// ***************************************************************************
// Function:    Next
// Description: Our '/next' command
// Usage:       /next v#
// ***************************************************************************
VOID Next(PSPAWNINFO pChar, PCHAR szLine)
{
	bRunNextCommand = TRUE;
	CHAR szNext[MAX_STRING];
	GetArg(szNext, szLine, 1);
	PDATAVAR pVar = FindMQ2DataVariable(szNext);
	if (!pVar)
	{
		FatalError("/next using invalid variable");
		return;
	}
	if (pVar->Var.Type != pIntType)
	{
		FatalError("/for loops must use an int variable");
		return;
	}
	if (!gMacroBlock) {
		MacroError("Can only use /next during a macro.");
		return;
	}
	const auto size = gMacroStack->loop_stack.size();
	if (size == 0 || gMacroStack->loop_stack[size-1].type != Loop::Type::For)
	{
		FatalError("/next without matching /for");
		return;
	}
	gMacroStack->loop_stack[size-1].last_line = gMacroBlock->CurrIndex;
	auto MacroLine = gMacroStack->loop_stack[size-1].first_line;
	auto iter = gMacroBlock->Line.find(MacroLine);
	CHAR ForLine[MAX_STRING];
	strcpy_s(ForLine, iter->second.Command.c_str());
	ParseMacroParameter(pChar, ForLine);
	DWORD VarNum = atoi(szLine + 1);
	CHAR szTemp[MAX_STRING];
	strcpy_s(szTemp, ForLine);
	_strlwr_s(szTemp);
	LONG StepSize = 1;
	if (strstr(szTemp, "step")) {
		if (PCHAR pTemp = strstr(szTemp, "step") + 4) {
			while ((pTemp[0] != 0) && (pTemp[0] != ' ') && (pTemp[0] != '\t'))
				pTemp++;
			if (pTemp[0] != 0)
				StepSize = atoi(pTemp);
		}
	}
	pVar = FindMQ2DataVariable(szNext);
	if (!pVar)
	{
		FatalError("/next without badly matching /for");
		return;
	}
	strcpy_s(szTemp, ForLine);
	_strlwr_s(szTemp);
	char *pDest = nullptr;
	if (pDest=strstr(szTemp, "downto"))
	{
		auto Loop = atoi(pDest + 7);
		//DebugSpewNoFile("Next - End of loop %d downto %d", pVar->Var.Int, Loop);
		pVar->Var.Int -= StepSize;
		if (pVar->Var.Int >= Loop) {
			gMacroBlock->CurrIndex = MacroLine;
		}
		else {
			pop_loop();
		}
	}
	else
	{
		auto Loop = 0;
		if (pDest = strstr(szTemp, "to"))
			Loop = atoi(pDest + 3);
		//DebugSpewNoFile("Next - End of loop %d to %d", pVar->Var.Int, Loop);
		pVar->Var.Int += StepSize;
		if (pVar->Var.Int <= Loop) {
			gMacroBlock->CurrIndex = MacroLine;
		}
		else {
			pop_loop();
		}
	}
}

// ***************************************************************************
// Function:    Continue
// Description: Our '/continue' command
// Usage:       /continue
// ***************************************************************************
VOID Continue(PSPAWNINFO pChar, PCHAR szLine)
{
	if (!gMacroBlock)
	{
		MacroError("Can only use /continue during a macro.");
		return;
	}
	const auto size = gMacroStack->loop_stack.size();
	if (size == 0)
	{
		FatalError("/continue without matching /for or /while block");
		return;
	}
	auto& loop = gMacroStack->loop_stack[size-1];
	if (loop.type == Loop::Type::While)
	{
		gMacroBlock->CurrIndex = loop.first_line;
		return;
	}
	else if (loop.last_line) // /for after 1st /next encountered
	{
		auto i = gMacroBlock->Line.find(loop.last_line);
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
			CHAR for_var[MAX_STRING];
			GetArg(for_var, line, 2);
			if (_stricmp(for_var, loop.for_variable.c_str()))
				continue;
			loop.last_line = i->first;
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
VOID Break(PSPAWNINFO pChar, PCHAR szLine)
{
	if (!gMacroBlock)
	{
		MacroError("Can only use /break during a macro.");
		return;
	}
	auto size = gMacroStack->loop_stack.size();
	if (size == 0)
	{
		FatalError("/break without matching /for or /while block");
		return;
	}
	auto& loop = gMacroStack->loop_stack[size-1];
	if (loop.last_line) // takes care of /while and /for after 1st /next encountered
	{
		gMacroBlock->CurrIndex = loop.last_line;
		pop_loop();
		return;
	}
	auto i = gMacroBlock->Line.find(gMacroBlock->CurrIndex);
	while (++i != gMacroBlock->Line.end())
	{
		const char *line = i->second.Command.c_str();
		if (!_strnicmp(line, "/next", 5))
		{
			CHAR for_var[MAX_STRING];
			GetArg(for_var, line, 2);
			if (_stricmp(for_var, loop.for_variable.c_str())) continue;
			gMacroBlock->CurrIndex = i->first;
			loop.last_line = i->first;;
			pop_loop();
			return;
		}
		if (!_strnicmp(line, "Sub ", 4))
		{
			break;
		}
	}
	FatalError("/break without matching /for ... /next (or while) block");
}
#endif
