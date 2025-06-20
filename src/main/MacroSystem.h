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

// Controls NoParse functionality. Parsing is disabled if this is true.
MQLIB_VAR bool bAllowCommandParse;

// Controls active parser version
MQLIB_VAR int gParserVersion;

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

MQLIB_VAR MQMacroStack* gMacroStack;
MQLIB_VAR MQMacroBlockPtr gMacroBlock;

MQLIB_VAR MQDataVar* pGlobalVariables;
MQLIB_VAR MQDataVar* pMacroVariables;
MQLIB_VAR std::map<std::string, MQDataVar*> VariableMap;

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
MQLIB_VAR MQEventList* pEventList;

struct MQEventQueue
{
	MQEventQueue* pPrev = nullptr;
	MQEventQueue* pNext = nullptr;
	MQEventType   Type = EVENT_CHAT;
	std::string   Name;
	MQEventList* pEventList = nullptr;
	MQDataVar* Parameters = nullptr;
};
MQLIB_VAR MQEventQueue* gEventQueue;

struct MQDefine
{
	char szName[MAX_STRING];
	char szReplace[MAX_STRING];

	MQDefine* pNext = nullptr;
};
MQLIB_VAR MQDefine* pDefines;

struct MQBindList
{
	char szName[MAX_STRING];
	char szFuncName[MAX_STRING];
	bool Parse = true;

	MQBindList* pNext = nullptr;
};
MQLIB_VAR MQBindList* pBindList;

struct MQTimer
{
	std::string Name;
	uint32_t Original = 0;
	uint32_t Current = 0;
	MQTimer* pNext = nullptr;
	MQTimer* pPrev = nullptr;
};
MQLIB_VAR MQTimer* gTimer;

constexpr int CHAT_SAY           = 0x0001;
constexpr int CHAT_TELL          = 0x0002;
constexpr int CHAT_OOC           = 0x0004;
constexpr int CHAT_SHOUT         = 0x0008;
constexpr int CHAT_AUC           = 0x0010;
constexpr int CHAT_GUILD         = 0x0020;
constexpr int CHAT_GROUP         = 0x0040;
constexpr int CHAT_RAID          = 0x0080;
constexpr int CHAT_CHAT          = 0x0100;
#define CHATEVENT(x)             (gEventChat & x)

MQLIB_API SGlobalBuffer DataTypeTemp;

MQLIB_VAR bool bAllErrorsFatal;
MQLIB_VAR bool bAllErrorsDumpStack;
MQLIB_VAR bool bAllErrorsLog;
MQLIB_VAR char gszLastNormalError[MAX_STRING];// QUIT USING THIS DIRECTLY, USE MacroError, FatalError, ETC
MQLIB_VAR char gszLastSyntaxError[MAX_STRING];
MQLIB_VAR char gszLastMQ2DataError[MAX_STRING];
MQLIB_VAR bool gWarning;

MQLIB_VAR uint64_t gRunning;
MQLIB_VAR int gMaxTurbo;
MQLIB_VAR int gTurboLimit;
MQLIB_VAR bool gTurbo;

MQLIB_VAR bool gMQPauseOnChat;

MQLIB_VAR int gEventFunc[NUM_EVENTS];
MQLIB_VAR DWORD gEventChat;
extern Blech* pMQ2Blech;
MQLIB_VAR char EventMsg[MAX_STRING];
MQLIB_VAR Blech* pEventBlech;

MQLIB_VAR int gDelay;
MQLIB_VAR char gDelayCondition[MAX_STRING];

MQLIB_API char* GetMacroSubFromLine(int Line, char* szSub, size_t Sublen);

MQLIB_OBJECT MQMacroBlockPtr GetCurrentMacroBlock();

MQLIB_API void EndAllMacros();

//============================================================================

class MacroSystem : public MQModuleBase
{
public:
	MacroSystem();
	virtual ~MacroSystem() override;

	// Returns true if a macro is currently running. We may not be in the middle of a call
	// from a macro, though.
	bool IsMacroRunning() const;

	// Returns true if a macro call is currently active. That is, we're in the middle of parsing
	// a macro. This means that any errors, commands, etc apply to that macro.
	bool IsActiveMacroCall() const;

	void HandleMacroError(const char* szError);
	void HandleFatalError(const char* szError);

	bool DispatchBind(char* szCommand, char* szArgs);
	void MacroCall(const char* line);

private:
	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void OnProcessFrame() override;
	virtual void OnGameStateChanged(int newGameState) override;
};

extern MacroSystem* g_macroSystem;

} // namespace mq
