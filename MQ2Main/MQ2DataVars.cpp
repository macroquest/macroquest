/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2004 Lax

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

#define DBG_SPEW


#include "MQ2Main.h"

#ifdef USEMQ2DATAVARS



PDATAVAR pGlobalVariables=0;
PDATAVAR pMacroVariables=0;
PMACROSTACK pNewMacroStack=0;

map<string,PDATAVAR> VariableMap;

inline VOID DeleteMQ2DataVariable(PDATAVAR pVar)
{
	VariableMap[pVar->szName]=0;
	if (pVar->pNext)
		pVar->pNext->pPrev=pVar->pPrev;
	if (pVar->pPrev)
		pVar->pPrev->pNext=pVar->pNext;
	else
		*pVar->ppHead=pVar->pNext;
	pVar->Var.Type->FreeVariable(pVar->Var.VarPtr);
	delete pVar;
}

inline PDATAVAR FindMQ2DataVariable(PCHAR Name)
{
	return VariableMap[Name];
}

BOOL AddMQ2DataVariable(PCHAR Name, PCHAR Index, MQ2Type *pType, PDATAVAR *ppHead, PCHAR Default)
{
	if (!ppHead || !Name[0])
		return FALSE;
	if (!Index)
		Index="";
	if (!Default)
		Default="";
	if (FindMQ2DataVariable(Name) || FindMQ2Data(Name) || FindMQ2DataType(Name))
		return FALSE; // name in use
	if (!pType)
		return FALSE;

	// create variable
	PDATAVAR pVar = new DATAVAR;
	pVar->ppHead=ppHead;
	pVar->pNext=*ppHead;
	*ppHead=pVar;
	pVar->pPrev=0;
	if (pVar->pNext)
		pVar->pNext->pPrev=pVar;
	strcpy(pVar->szName,Name);
	if (Index[0])
	{
		CDataArray *pArray=new CDataArray(pType,Index,Default);
		pVar->Var.Ptr=pArray;

	}
	else
	{
		pVar->Var.Type=pType;
		pType->InitVariable(pVar->Var.VarPtr);
		pType->FromString(pVar->Var.VarPtr,Default);
	}
	return TRUE;
}

PDATAVAR *FindVariableScope(PCHAR Name)
{
	if (!stricmp(Name,"global"))
		return &pGlobalVariables;
	if (!stricmp(Name,"outer"))
		return &pMacroVariables;
	if (pNewMacroStack && !stricmp(Name,"local"))
		return &pNewMacroStack->LocalVariables;
	return 0;
}

BOOL DeleteMQ2DataVariable(PCHAR Name)
{
	if (PDATAVAR pVar=FindMQ2DataVariable(Name))
	{
		DeleteMQ2DataVariable(pVar);
		return TRUE;
	}
	return FALSE;
}

VOID ClearMQ2DataVariables(PDATAVAR *ppHead)
{
	PDATAVAR pVar=*ppHead;
	while(pVar)
	{
		DeleteMQ2DataVariable(pVar);
		pVar=pVar->pNext;
	}
	*ppHead=0;
}

VOID NewDeclareVar(PSPAWNINFO pChar, PCHAR szLine)
{
	if (!szLine[0])
	{
		WriteChatColor("Usage: /declare <varname|varname[array extents]> [type] [global|outer|local] [default value]");
		return;
	}
	PDATAVAR *pScope=0;
	MQ2Type *pType=0;
	CHAR szIndex[MAX_STRING]={0};
	CHAR szName[MAX_STRING]={0};
	GetArg(szName,szLine,1);
	CHAR Arg[MAX_STRING]={0};
	GetArg(Arg,szLine,2);
	PCHAR pDefault;
	if (pScope=FindVariableScope(Arg))
	{
		// scope comes AFTER type, so next must be default
		pDefault=GetNextArg(szLine,2);
	}
	else if (pType=FindMQ2DataType(Arg))
	{
		// next is either scope or default
		GetArg(Arg,szLine,3);
		if (pScope=FindVariableScope(Arg))
		{
			// next is default
			pDefault=GetNextArg(szLine,4);
		}
		else
		{
			// this is default
			pDefault=GetNextArg(szLine,3);
		}
	}
	else
	{
		// this is default
		pDefault=GetNextArg(szLine);
	}
	if (!pScope)
	{ 
		if (pNewMacroStack)
			pScope=&pNewMacroStack->LocalVariables;
		else
		{
			WriteChatColor("/declare failed.  No macro in execution and no variable scope given");
			return;
		}
	}
	if (!pType)
		pType=pStringType;
	if (pType==pArrayType)
	{
		WriteChatColor("/declare array failed.  To declare an array use: /declare name[size] <type> <scope> <default element value>");
		WriteChatColor("Example: /declare MyStringArray[25] string local ARRAY-UNDEFINED-ELEMENT");
		return;
	}

	if (PCHAR pBracket=strchr(szName,'['))
	{
		*pBracket=0;
		strcpy(szIndex,&pBracket[1]);
		szIndex[strlen(szIndex)-1]=0;
		*pBracket='[';
	}

	if (!AddMQ2DataVariable(szName,szIndex,pType,pScope,pDefault))
	{
		WriteChatColor("/declare failed.  No macro in execution and no variable scope given");
	}
}

VOID NewDeleteVarCmd(PSPAWNINFO pChar, PCHAR szLine)
{
	if (szLine[0]==0) {
		WriteChatColor("Usage: /deletevar <varname>",USERCOLOR_DEFAULT);
	} 
	else 
	{
		// destroy old variable
		if (!DeleteMQ2DataVariable(szLine))
		{
			CHAR Temp[MAX_STRING];
			sprintf(Temp,"Variable '%s' does not exist",szLine);
			WriteChatColor(Temp,USERCOLOR_DEFAULT);
		}
	}
}

VOID NewVarset(PSPAWNINFO pChar, PCHAR szLine)
{
	if (!szLine[0])
	{
		WriteChatColor("Usage: /varset <varname> <new value>");
		return;
	}
	CHAR szName[MAX_STRING]={0};
	GetArg(szName,szLine,1);
	PCHAR szRest=GetNextArg(szLine);
	if (!szRest || !szRest[0])
	{
		WriteChatColor("Usage: /varset <varname> <new value>");
		return;
	}
	CHAR szIndex[MAX_STRING]={0};
	if (PCHAR pBracket=strchr(szName,'['))
	{
		*pBracket=0;
		strcpy(szIndex,&pBracket[1]);
		*pBracket='[';
	}
	PDATAVAR pVar=FindMQ2DataVariable(szName);
	if (!pVar)
	{
		WriteChatColor("/varset failed, variable not found",CONCOLOR_RED);
		return;
	}
	if (szIndex[0])
	{
		if (pVar->Var.Type!=pArrayType)
		{
			WriteChatColor("/varset failed, array form on non-array",CONCOLOR_RED);
			return;
		}
		CDataArray *pArray=(CDataArray*)pVar->Var.Ptr;
		int N=pArray->GetElement(szIndex);
		if (N==-1)
		{
			WriteChatColor("/varset failed, out of bounds on array",CONCOLOR_RED);
			return;
		}
		if (!pArray->pType->FromString(pArray->pData[N],szRest))
		{
			WriteChatColor("/varset failed, array element type rejected new value",CONCOLOR_RED);
		}
	}
	else
	{
		if (!pVar->Var.Type->FromString(pVar->Var.VarPtr,szRest))
		{
			WriteChatColor("/varset failed, variable type rejected new value",CONCOLOR_RED);
		}
	}
}

VOID NewVardata(PSPAWNINFO pChar, PCHAR szLine)
{
	if (!szLine[0])
	{
		WriteChatColor("Usage: /vardata <varname> <new mq2data value>");
		return;
	}
	CHAR szName[MAX_STRING]={0};
	GetArg(szName,szLine,1);
	PCHAR szRest=GetNextArg(szLine);
	if (!szRest || !szRest[0])
	{
		WriteChatColor("Usage: /vardata <varname> <new mq2data value>");
		return;
	}
	CHAR szIndex[MAX_STRING]={0};
	if (PCHAR pBracket=strchr(szName,'['))
	{
		*pBracket=0;
		strcpy(szIndex,&pBracket[1]);
		*pBracket='[';
	}
	PDATAVAR pVar=FindMQ2DataVariable(szName);
	if (!pVar)
	{
		WriteChatColor("/vardata failed, variable not found",CONCOLOR_RED);
		return;
	}
	MQ2TYPEVAR Result;
	if (!ParseMQ2DataPortion(szRest,Result))
	{
		WriteChatColor("/vardata failed, MQ2Data portion unparsable",CONCOLOR_RED);
		return;
	}

	if (szIndex[0])
	{
		if (pVar->Var.Type!=pArrayType)
		{
			WriteChatColor("/vardata failed, array form on non-array",CONCOLOR_RED);
			return;
		}
		CDataArray *pArray=(CDataArray*)pVar->Var.Ptr;
		int N=pArray->GetElement(szIndex);
		if (N==-1)
		{
			WriteChatColor("/vardata failed, out of bounds on array",CONCOLOR_RED);
			return;
		}
		if (!pVar->Var.Type->FromData(pVar->Var.VarPtr,Result))
		{
			WriteChatColor("/vardata failed, array element type rejected new value",CONCOLOR_RED);
		}
	}
	else
	{
		if (!pVar->Var.Type->FromData(pVar->Var.VarPtr,Result))
		{
			WriteChatColor("/vardata failed, variable type rejected new value",CONCOLOR_RED);
		}
	}
}


VOID DropTimers(VOID)
{
	PTIMER pTimer=gTimer;
	CHAR szOrig[MAX_STRING] = {0};
	while(pTimer)
	{
		if (pTimer->Current)
		{
			pTimer->Current--;
			if (!pTimer->Current)
			{
				itoa(pTimer->Original,szOrig,10);
				// TODO
//				AddEvent(EVENT_TIMER,pTimer->szName,szOrig,NULL);
			}
		}
		pTimer=pTimer->pNext;
	}
}


#else
PDATAVAR FindMQ2DataVariable(PCHAR Name)
{
	return 0;
}
#endif