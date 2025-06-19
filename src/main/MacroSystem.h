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

#pragma once

#include "ModuleSystem.h"
#include "mq/api/MacroAPI.h"
#include "mq/base/Common.h"
#include "mq/base/GlobalBuffer.h"
#include "mq/base/String.h"

class Blech;

namespace mq {

// FIXME
void PopMacroLoop();
void FailIf(const char* szCommand, int StartLine, bool All = false);
void Call(eqlib::PlayerClient*, const char* szLine);
char* GetMacroSubFromLine(int Line, char* szSub, size_t Sublen);
void DumpStack(eqlib::PlayerClient*, const char*);
void EndMacro(eqlib::PlayerClient*, const char*);

struct MQMacroLine
{
	std::string Command;

	int LoopStart = 0;
	// used for loops/while if its 0 no action is taken, otherwise it will jump to the line indicated.
	int LoopEnd = 0;

	std::string SourceFile;
	int LineNumber = 0;

#ifdef MQ2_PROFILING
	int ExecutionCount = 0;
	uint64_t ExecutionTime = 0;
#endif

	MQMacroLine(std::string Line, std::string sourceFile, int lineNumber)
		: Command(std::move(Line))
		, SourceFile(std::move(sourceFile))
		, LineNumber(lineNumber)
	{
	}

	MQMacroLine(const MQMacroLine&) = delete;
	MQMacroLine& operator=(const MQMacroLine&) = delete;
};

struct MQMacroBlock
{
	std::string Name;                           // our macro Name
	bool Paused = false;
	int CurrIndex = 0;                          // the current macro line we are on
	int BindStackIndex = -1;                    // where we were at before calling the bind.
	std::string BindCmd;                        // the actual command including parameters
	std::map<int, MQMacroLine> Line;
	bool Removed = false;

	MQMacroBlock(std::string name) : Name(std::move(name)) {}

	MQMacroBlock(const MQMacroBlock&) = delete;
	MQMacroBlock& operator=(const MQMacroBlock&) = delete;
};
using MQMacroBlockPtr = std::shared_ptr<MQMacroBlock>;


struct MQLoop
{
	enum Type { None, For, While };
	Type type = None;
	int	firstLine = 0;
	int lastLine = 0;
	std::string forVariable;
};

struct MQMacroStack
{
	bool bIsBind = false;
	int LocationIndex = 0;
	MQDataVar* Parameters = nullptr;
	MQDataVar* LocalVariables = nullptr;
	std::vector<MQLoop> loopStack;
	std::string Return;

	MQMacroStack* pNext = nullptr;

	MQMacroStack(int locationIndex)
		: LocationIndex(locationIndex)
	{
	}

	MQMacroStack(const MQMacroStack&) = delete;
	MQMacroStack& operator=(const MQMacroStack&) = delete;
};

enum MQEventType
{
	EVENT_CHAT = 0,
	EVENT_TIMER,
	EVENT_CUSTOM,
	EVENT_EVAL,
	EVENT_EXEC,
	EVENT_PULSE,
	EVENT_SHUTDOWN,
	EVENT_BREAK,

	NUM_EVENTS
};

struct MQEventList
{
	char szName[MAX_STRING];
	char szMatch[MAX_STRING];
	int pEventFunc = 0;
	DWORD BlechID = 0;

	MQEventList* pNext = nullptr;
};

struct MQEventQueue
{
	MQEventQueue* pPrev = nullptr;
	MQEventQueue* pNext = nullptr;
	MQEventType   Type = EVENT_CHAT;
	std::string   Name;
	MQEventList* pEventList = nullptr;
	MQDataVar* Parameters = nullptr;
};

struct MQDefine
{
	char szName[MAX_STRING];
	char szReplace[MAX_STRING];

	MQDefine* pNext = nullptr;
};

struct MQBindList
{
	char szName[MAX_STRING];
	char szFuncName[MAX_STRING];
	bool Parse = true;

	MQBindList* pNext = nullptr;
};

MQLIB_VAR MQDataVar* pGlobalVariables;
MQLIB_VAR MQDataVar* pMacroVariables;
MQLIB_VAR bool bAllErrorsFatal;
MQLIB_VAR bool bAllErrorsDumpStack;
MQLIB_VAR bool bAllErrorsLog;

MQLIB_API SGlobalBuffer DataTypeTemp;

MQLIB_VAR MQMacroStack* gMacroStack;
MQLIB_VAR mq::ci_ordered::map<std::string, int> gMacroSubLookupMap;
MQLIB_VAR MQMacroBlockPtr gMacroBlock;
MQLIB_VAR bool gBindInProgress;
MQLIB_VAR int BlockIndex;
MQLIB_VAR std::map<std::string, int> gUndeclaredVars;
MQLIB_VAR MQEventQueue* gEventQueue;
MQLIB_VAR int gEventFunc[NUM_EVENTS];

MQLIB_VAR char gszLastNormalError[MAX_STRING];// QUIT USING THIS DIRECTLY, USE MacroError, FatalError, ETC
MQLIB_VAR char gszLastSyntaxError[MAX_STRING];
MQLIB_VAR char gszLastMQ2DataError[MAX_STRING];

MQLIB_VAR DWORD gEventChat;
MQLIB_VAR uint64_t gRunning;
MQLIB_VAR int gMaxTurbo;
MQLIB_VAR int gTurboLimit;
MQLIB_VAR bool gReturn;
MQLIB_VAR bool gKeepKeys;
MQLIB_VAR MQEventList* pEventList;

enum eFilterMacro
{
	FILTERMACRO_ALL = 0,
	FILTERMACRO_ENHANCED = 1,
	FILTERMACRO_NONE = 2,
	FILTERMACRO_MACROENDED = 3,

	FILTERMACRO_MAX,
};


MQLIB_VAR char gIfDelimiter;
MQLIB_VAR char gIfAltDelimiter;
MQLIB_VAR bool gMQPauseOnChat;

extern Blech* pMQ2Blech;
MQLIB_VAR char EventMsg[MAX_STRING];
MQLIB_VAR Blech* pEventBlech;

struct MQTimer
{
	std::string Name;
	uint32_t Original = 0;
	uint32_t Current = 0;
	MQTimer* pNext = nullptr;
	MQTimer* pPrev = nullptr;
};
MQLIB_VAR MQTimer* gTimer;

MQLIB_VAR int gDelay;
MQLIB_VAR char gDelayCondition[MAX_STRING];
MQLIB_VAR bool bAllowCommandParse;
MQLIB_VAR bool gTurbo;
MQLIB_VAR bool gWarning;
MQLIB_VAR MQDefine* pDefines;
MQLIB_VAR MQBindList* pBindList;

MQLIB_VAR std::map<std::string, MQDataVar*> VariableMap;

const std::string PARSE_PARAM_BEG = "${Parse[";
const std::string PARSE_PARAM_END = "]}";

MQLIB_VAR int gParserVersion;

//============================================================================

class MacroSystem : public MQModuleBase
{
public:
	MacroSystem();
	virtual ~MacroSystem() override;

	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void OnProcessFrame() override;
	virtual void OnGameStateChanged(int newGameState) override;
};

extern MacroSystem* g_macroSystem;

} // namespace mq
