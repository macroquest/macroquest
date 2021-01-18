/*
 * MacroQuest: The extension platform for EverQuest
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

#include "pch.h"
#include "MQ2Main.h"

using namespace mq::datatypes;
namespace mq {

static std::recursive_mutex s_dataVarMutex;

void DeleteMQ2DataVariable(MQDataVar* pVar)
{
	std::scoped_lock lock(s_dataVarMutex);

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

MQDataVar* FindMQ2DataVariable(const char* Name)
{
	std::scoped_lock lock(s_dataVarMutex);

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

static bool AddMQ2DataEventVariable(const char* Name, char* Index, MQ2Type* pType, MQDataVar** ppHead, const char* Default)
{
	std::scoped_lock lock(s_dataVarMutex);

	if (!ppHead || !Name[0])
		return false;
	if (!Index)
		Index = "";
	if (!Default)
		Default = "";
	if (FindMQ2Data(Name) || FindMQ2DataType(Name))
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
		CDataArray* pArray = new CDataArray(pType, Index, Default);
		pVar->Var.Ptr = pArray;

	}
	else
	{
		pVar->Var.Type = pType;
		pType->InitVariable(pVar->Var.VarPtr);

		// FIXME: This should be const char*
		pType->FromString(pVar->Var.VarPtr, Default);
	}

	if (pVar->ppHead == &pMacroVariables || pVar->ppHead == &pGlobalVariables)
	{
		VariableMap[Name] = pVar;
	}

	return true;
}

static bool AddMQ2DataVariableBy(const char* Name, const char* Index, MQ2Type* pType, MQDataVar** ppHead, const char* Default, bool ByData)
{
	std::scoped_lock lock(s_dataVarMutex);

	if (!ppHead || !Name[0])
		return false;
	if (!Index)
		Index = "";
	if (!Default)
		Default = "";
	if (FindMQ2DataVariable(Name) || FindMQ2Data(Name) || FindMQ2DataType(Name))
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
		CDataArray* pArray = new CDataArray(pType, (char*)Index, Default);
		pVar->Var.Ptr = pArray;
		pVar->Var.Type = pArrayType;
	}
	else
	{
		pVar->Var.Type = pType;
		pType->InitVariable(pVar->Var.VarPtr);
		if (ByData)
			pType->FromData(pVar->Var.VarPtr, *(MQTypeVar*)Default);
		else
			pType->FromString(pVar->Var.VarPtr, Default);
	}

	if (!(gMacroStack && (ppHead == &gMacroStack->LocalVariables || ppHead == &gMacroStack->Parameters)))
	{
		VariableMap[Name] = pVar;
	}

	return true;
}

bool AddMQ2DataVariable(const char* Name, const char* Index, MQ2Type* pType, MQDataVar** ppHead, const char* Default)
{
	return AddMQ2DataVariableBy(Name, Index, pType, ppHead, Default, false);
}

bool AddMQ2DataVariableFromData(const char* Name, const char* Index, MQ2Type* pType, MQDataVar** ppHead, MQTypeVar Default)
{
	return AddMQ2DataVariableBy(Name, Index, pType, ppHead, (const char*)&Default, true);
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

bool DeleteMQ2DataVariable(const char* Name)
{
	if (MQDataVar * pVar = FindMQ2DataVariable(Name))
	{
		DeleteMQ2DataVariable(pVar);
		return true;
	}

	return false;
}

void ClearMQ2DataVariables(MQDataVar** ppHead)
{
	MQDataVar* pVar = *ppHead;
	while (pVar)
	{
		MQDataVar* pNext = pVar->pNext;
		DeleteMQ2DataVariable(pVar);

		pVar = pNext;
	}

	*ppHead = nullptr;
}

void NewDeclareVar(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /declare <varname|varname[array extents]> [type] [global|outer|local|bind] [default value]");
		return;
	}

	MQDataVar** pScope = nullptr;
	MQ2Type* pType = nullptr;

	char szIndex[MAX_STRING] = { 0 };
	char szName[MAX_STRING] = { 0 };
	GetArg(szName, szLine, 1);
	char Arg[MAX_STRING] = { 0 };
	GetArg(Arg, szLine, 2);
	const char* pDefault = nullptr;

	if (pScope = FindVariableScope(Arg))
	{
		// scope comes AFTER type, so next must be default
		pDefault = GetNextArg(szLine, 2);
	}
	else if (pType = FindMQ2DataType(Arg))
	{
		// next is either scope or default
		GetArg(Arg, szLine, 3);

		if (pScope = FindVariableScope(Arg))
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
			MacroError("/declare '%s' failed.  No macro in execution and no variable scope given", szName);
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

	if (char* pBracket = strchr(szName, '['))
	{
		*pBracket = 0;
		strcpy_s(szIndex, &pBracket[1]);
		szIndex[strlen(szIndex) - 1] = 0;
	}

	if (pType == pTimerType && szIndex[0])
	{
		MacroError("Cannot /declare an array of timers");
		return;
	}

	if (!AddMQ2DataVariable(szName, szIndex, pType, pScope, pDefault))
	{
		MacroError("/declare '%s' failed.  Name already in use.", szName);
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

void NewDeleteVarCmd(SPAWNINFO* pChar, char* szLine)
{
	if (szLine[0] == 0) {
		SyntaxError("Usage: /deletevar <varname|* global>");
	}
	else
	{
		// destroy old variable
		if (!DeleteMQ2DataVariable(szLine))
		{
			if (!_strnicmp(szLine, "* global", 8))
			{
				ClearMQ2DataVariables(&pGlobalVariables);
			}
			else
				MacroError("Variable '%s' does not exist", szLine);
		}
	}
}

void NewVarset(SPAWNINFO* pChar, char* szLine)
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

	MQDataVar* pVar = FindMQ2DataVariable(szName);
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

		CDataArray* pArray = (CDataArray*)pVar->Var.Ptr;
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

void NewVarcalc(SPAWNINFO* pChar, char* szLine)
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

	MQDataVar* pVar = FindMQ2DataVariable(szName);
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

		CDataArray* pArray = (CDataArray*)pVar->Var.Ptr;

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

void NewVardata(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /vardata <varname> <new mq2data value>");
		return;
	}

	char szName[MAX_STRING] = { 0 };
	GetArg(szName, szLine, 1);

	// FIXME: This is a mutable pointer to szLine. We modify it in ParseMQ2DataPortion below.
	char* szRest = GetNextArg(szLine);
	if (!szRest || !szRest[0])
	{
		SyntaxError("Usage: /vardata <varname> <new mq2data value>");
		return;
	}

	char szIndex[MAX_STRING] = { 0 };
	if (char* pBracket = strchr(szName, '['))
	{
		*pBracket = 0;
		strcpy_s(szIndex, &pBracket[1]);
	}

	MQDataVar* pVar = FindMQ2DataVariable(szName);
	if (!pVar)
	{
		MacroError("/vardata '%s' failed, variable not found", szName);
		return;
	}

	MQTypeVar Result;
	if (!ParseMQ2DataPortion(szRest, Result))
	{
		MacroError("/vardata '%s' failed, MQ2Data portion '%s' unparsable", szName, szRest);
		return;
	}

	if (szIndex[0])
	{
		if (pVar->Var.Type != pArrayType)
		{
			MacroError("/vardata '%s' failed, array form on non-array", szName);
			return;
		}

		CDataArray* pArray = (CDataArray*)pVar->Var.Ptr;
		int num = pArray->GetElement(szIndex);
		if (num == -1)
		{
			MacroError("/vardata '%s[%d]' failed, out of bounds on array", szName, num);
			return;
		}

		if (!pArray->GetType()->FromData(pArray->GetData(num), Result))
		{
			MacroError("/vardata '%s[%d]'failed, array element type rejected new value", szName, num);
		}
	}
	else
	{
		if (!pVar->Var.Type->FromData(pVar->Var.VarPtr, Result))
		{
			MacroError("/vardata '%s' failed, variable type rejected new value", szName);
		}
	}
}

static void AddEvent(int Event, const char* FirstArg, ...)
{
	MQEventQueue* pEvent = nullptr;
	if (!gEventFunc[Event])
		return;

	// this is deleted in 2 locations DoEvents and EndMacro
	DebugSpewNoFile("Adding Event %d %s", Event, FirstArg);

	pEvent = new MQEventQueue();
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

				MQ2Type* pType = FindMQ2DataType(szParamType);
				if (!pType)
					pType = pStringType;

				AddMQ2DataEventVariable(szParamName, "", pType, &pEvent->Parameters, CurrentArg);
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
		MQEventQueue* pTemp = nullptr;
		for (pTemp = gEventQueue; pTemp->pNext; pTemp = pTemp->pNext);
		pTemp->pNext = pEvent;
		pEvent->pPrev = pTemp;
	}
}

void CALLBACK EventBlechCallback(unsigned int ID, void* pData, PBLECHVALUE pValues)
{
	DebugSpew("EventBlechCallback(%d,%X,%X) msg='%s'", ID, pData, pValues, EventMsg);

	MQEventList* pEList = (MQEventList*)pData;
	MQEventQueue* pEvent = nullptr;

	if (!pEList->pEventFunc)
	{
		DebugSpew("EventBlechCallback() -- pEventFunc is NULL, cannot call event sub");
		return;
	}

	pEvent = new MQEventQueue();
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

	MQ2Type* pType = FindMQ2DataType(szParamType);
	if (!pType)
		pType = pStringType;

	AddMQ2DataEventVariable(szParamName, "", pType, &pEvent->Parameters, EventMsg);

	while (pValues)
	{
		if (pValues->Name[0] != '*')
		{
			auto eventIter2 = gMacroBlock->Line.find(pEList->pEventFunc);
			if (eventIter2 != gMacroBlock->Line.end())
			{
				GetFuncParam(&eventIter2->second.Command[0], GetIntFromString(pValues->Name, 0), szParamName, MAX_STRING, szParamType, MAX_STRING);
			}

			MQ2Type* pType2 = FindMQ2DataType(szParamType);
			if (!pType2)
				pType2 = pStringType;

			AddMQ2DataEventVariable(szParamName, "", pType2, &pEvent->Parameters, pValues->Value.c_str());
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
		for (pTemp = gEventQueue; pTemp->pNext; pTemp = pTemp->pNext);
		pTemp->pNext = pEvent;
		pEvent->pPrev = pTemp;
	}
}

static DWORD CALLBACK BeepOnTellThread(void* pData)
{
	Beep(750, 200);
	return 0;
}

static void TellCheck(const char* szClean)
{
	if (!gbFlashOnTells && !gbBeepOnTells)
		return;

	CHARINFO* pChar = GetCharInfo();
	if (!pChar) return;

	char name[2048] = { 0 };
	bool isTell = false;
	if (const char* pDest = strstr(szClean, " tells you, "))
	{
		strncpy_s(name, szClean, (int)(pDest - szClean));
		isTell = true;
	}
	else if (pDest = strstr(szClean, " told you, "))
	{
		strncpy_s(name, szClean, (int)(pDest - szClean));
		isTell = true;
	}

	if (!isTell || strlen(name) >= 64)
		return;

	// don't perform action if its us doing the tell
	if (!_stricmp(pChar->Name, name))
		return;

	// don't perform action if its our pet
	if (pChar->pSpawn->PetID != -1)
	{
		if (SPAWNINFO* pPet = (SPAWNINFO*)GetSpawnByID(pChar->pSpawn->PetID))
		{
			if (!_stricmp(pPet->DisplayedName, name))
				return;
		}
	}

	// only react to player tells
	SPAWNINFO* pNpc = (SPAWNINFO*)GetSpawnByPartialName(name);
	if (!pNpc && pCharSpawn != nullptr)
	{
		// try to use spawn search to find it.
		char szSearch[256] = { 0 };
		sprintf_s(szSearch, "npc %s", name);

		MQSpawnSearch ssSpawn;
		ClearSearchSpawn(&ssSpawn);
		ParseSearchSpawn(szSearch, &ssSpawn);

		pNpc = SearchThroughSpawns(&ssSpawn, (SPAWNINFO*)pCharSpawn);
	}

	if (pNpc)
	{
		// its not a player
		if (pNpc->Type != SPAWN_PLAYER)
		{
			return;
		}

		// its a merchantplayer...
		if (pNpc->Trader || pNpc->Buyer)
		{
			return;
		}
	}

	if (gbFlashOnTells)
	{
		HWND hEQWnd = GetEQWindowHandle();

		if (hEQWnd)
		{
			FLASHWINFO fwi = { sizeof(FLASHWINFO) };
			fwi.dwFlags = FLASHW_ALL;
			fwi.hwnd = hEQWnd;
			fwi.uCount = 3;
			fwi.dwTimeout = 0;
			FlashWindowEx(&fwi);
		}
	}

	if (gbBeepOnTells)
	{
		CreateThread(nullptr, 0, BeepOnTellThread, nullptr, 0, nullptr);
	}
}

void CheckChatForEvent(const char* szMsg)
{
	int len = strlen(szMsg);

	auto pszCleanOrg = std::make_unique<char[]>(len + 64);
	char* szClean = pszCleanOrg.get();

	strcpy_s(szClean, len + 64, szMsg);

	if (strchr(szClean, '\x12'))
	{
		CXStr out = CleanItemTags(szClean, false);
		strcpy_s(szClean, len + 64, out.c_str());
	}

	strncpy_s(EventMsg, szClean, MAX_STRING - 1);
	EventMsg[MAX_STRING - 1] = 0;
	if (pMQ2Blech)
		pMQ2Blech->Feed(EventMsg);
	EventMsg[0] = 0;
	TellCheck(szClean);

	MQMacroBlockPtr pBlock = GetCurrentMacroBlock();
	if ((pBlock && !pBlock->Line.empty()) && (!pBlock->Paused) && (!gbUnload) && (!gZoning))
	{
		char Arg1[MAX_STRING] = { 0 };
		char Arg2[MAX_STRING] = { 0 };
		char Arg3[MAX_STRING] = { 0 };
		char* pDest = nullptr;

		if ((CHATEVENT(CHAT_GUILD)) && (pDest = strstr(szClean, " tells the guild, ")))
		{
			strncpy_s(Arg1, szClean, (DWORD)(pDest - szClean));
			strcpy_s(Arg2, pDest + 19);
			Arg2[strlen(Arg2) - 1] = 0;
			AddEvent(EVENT_CHAT, "guild", Arg1, Arg2, NULL);
		}
		else if ((CHATEVENT(CHAT_GROUP)) && (pDest = strstr(szClean, " tells the group, ")))
		{
			strncpy_s(Arg1, szClean, (DWORD)(pDest - szClean));
			strcpy_s(Arg2, pDest + 19);
			Arg2[strlen(Arg2) - 1] = 0;
			AddEvent(EVENT_CHAT, "group", Arg1, Arg2, NULL);
		}
		else if ((CHATEVENT(CHAT_TELL)) && (pDest = strstr(szClean, " tells you, ")))
		{
			strncpy_s(Arg1, szClean, (DWORD)(pDest - szClean));
			strcpy_s(Arg2, pDest + 13);
			Arg2[strlen(Arg2) - 1] = 0;
			AddEvent(EVENT_CHAT, "tell", Arg1, Arg2, NULL);
		}
		else if ((CHATEVENT(CHAT_TELL)) && (pDest = strstr(szClean, " told you, ")))
		{
			strncpy_s(Arg1, szClean, (DWORD)(pDest - szClean));
			strcpy_s(Arg2, pDest + 12);
			Arg2[strlen(Arg2) - 1] = 0;
			AddEvent(EVENT_CHAT, "tell", Arg1, Arg2, NULL);
		}
		else if ((CHATEVENT(CHAT_OOC)) && (pDest = strstr(szClean, " says out of character, '")))
		{
			strncpy_s(Arg1, szClean, (DWORD)(pDest - szClean));
			strcpy_s(Arg2, pDest + 25);
			Arg2[strlen(Arg2) - 1] = 0;
			AddEvent(EVENT_CHAT, "ooc", Arg1, Arg2, NULL);
		}
		else if ((CHATEVENT(CHAT_SHOUT)) && (pDest = strstr(szClean, " shouts, ")))
		{
			strncpy_s(Arg1, szClean, (DWORD)(pDest - szClean));
			strcpy_s(Arg2, pDest + 10);
			Arg2[strlen(Arg2) - 1] = 0;
			AddEvent(EVENT_CHAT, "shout", Arg1, Arg2, NULL);
		}
		else if ((CHATEVENT(CHAT_AUC)) && (pDest = strstr(szClean, " auctions, ")))
		{
			strncpy_s(Arg1, szClean, (DWORD)(pDest - szClean));
			strcpy_s(Arg2, pDest + 12);
			Arg2[strlen(Arg2) - 1] = 0;
			AddEvent(EVENT_CHAT, "auc", Arg1, Arg2, NULL);
		}
		else if ((CHATEVENT(CHAT_SAY)) && (pDest = strstr(szClean, " says '")))
		{
			strncpy_s(Arg1, szClean, (DWORD)(pDest - szClean));
			strcpy_s(Arg2, pDest + 7);
			Arg2[strlen(Arg2) - 1] = 0;
			AddEvent(EVENT_CHAT, "say", Arg1, Arg2, NULL);
		}
		else if ((CHATEVENT(CHAT_SAY)) && (pDest = strstr(szClean, " says, ")))
		{
			strncpy_s(Arg1, szClean, (DWORD)(pDest - szClean));
			strcpy_s(Arg2, pDest + 8);
			Arg2[strlen(Arg2) - 1] = 0;
			AddEvent(EVENT_CHAT, "say", Arg1, Arg2, NULL);
		}
		else if ((CHATEVENT(CHAT_RAID)) && (pDest = strstr(szClean, " tells the raid, ")))
		{
			strncpy_s(Arg1, szClean, (DWORD)(pDest -szClean));
			strcpy_s(Arg2, pDest + 18);
			Arg2[strlen(Arg2) - 1] = 0;
			AddEvent(EVENT_CHAT, "raid", Arg1, Arg2, NULL);
		}
		else if ((CHATEVENT(CHAT_CHAT)) && (strstr(szClean, "You told ") == nullptr)
			&& (pDest = strstr(szClean, " tells "))
			&& (strstr(szClean, ":"))
			&& (strstr(szClean, ", '")))
		{
			strncpy_s(Arg1, szClean, (DWORD)(pDest - szClean));
			strcpy_s(Arg3, pDest + 7);
			Arg3[strlen(Arg3) - 1] = 0;
			if (pDest = strstr(Arg3, ", '"))
			{
				strcpy_s(Arg2, pDest + 3);
			}
			const char* colPos = strstr(Arg3, ":");

			if (colPos != nullptr)
			{
				Arg3[colPos - Arg3] = 0;
			}

			AddEvent(EVENT_CHAT, Arg3, Arg1, Arg2, NULL);
		}

		strncpy_s(EventMsg, szClean, MAX_STRING - 1);
		EventMsg[MAX_STRING - 1] = 0;
		pEventBlech->Feed(EventMsg);
		EventMsg[0] = '\0';
	}
}

void DropTimers()
{
	MQTimer* pTimer = gTimer;

	char szOrig[MAX_STRING] = { 0 };

	while (pTimer)
	{
		if (pTimer->Current)
		{
			pTimer->Current--;
			if (!pTimer->Current)
			{
				_itoa_s(pTimer->Original, szOrig, 10);
				AddEvent(EVENT_TIMER, pTimer->Name.c_str(), szOrig, NULL);
			}
		}
		pTimer = pTimer->pNext;
	}
}

} // namespace mq
