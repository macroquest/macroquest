/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003 Lax

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

PVARSTRINGS NewVarString(PCHAR szName, PCHAR szType)
{
	PVARSTRINGS pVar = (PVARSTRINGS)malloc(sizeof(VARSTRINGS));
	if (!pVar) return NULL;
	strncpy(pVar->szName,szName,MAX_VARNAME-1);
	sprintf(pVar->szVar,"UNDEFINED-%s",szType);
	pVar->pNext = NULL;
	return pVar;
}

PCHAR GetVarString(PVARSTRINGS pVars, PCHAR szName)
{
	for (;pVars;pVars=pVars->pNext) {
		if (!strcmp(pVars->szName,szName)) {
			return (pVars->szVar);
		}
	}
	return NULL;
}



PCHAR GetEventStr(PEVENTSTACK pEvent, PCHAR szName, BOOL Create)
{
	if (!gMacroStack) return NULL;
	PCHAR szLocal = GetVarString(pEvent->EventStr,szName);
	if (szLocal || !Create) return szLocal;
	PVARSTRINGS pVar = NewVarString(szName,"EVENT");
	if (!pVar) return NULL;
	pVar->pNext = pEvent->EventStr;
	pEvent->EventStr = pVar;
	return pVar->szVar;
}

VOID CheckVariableRecursion(PCHAR szVar) {
	PCHAR szAt = NULL;
	while (szAt = strstr(szVar,"@")) szAt[0]='²';
}

// *************************************************************************** 
// Function:    CChatHook::Detour 
// Description: Our Chat Hook 
// *************************************************************************** 
VOID AddEvent(DWORD Event, PCHAR FirstArg, ...)
{ 
	PEVENTSTACK pEvent = NULL; 
	if (!gEventFunc[Event]) {	return; }
	pEvent = (PEVENTSTACK)malloc(sizeof(EVENTSTACK)); 
	if (!pEvent) {	return; }
	ZeroMemory(pEvent,sizeof(EVENTSTACK)); 
	pEvent->Type = Event; 
	pEvent->pEventList = NULL; 
	if (FirstArg) {
		va_list marker;
		DWORD i=0;
		PCHAR CurrentArg = FirstArg;
		va_start(marker, FirstArg);

		while (CurrentArg) {
			CHAR szParamName[MAX_STRING] = {0};
			strcpy(GetEventStr(pEvent,GetFuncParamName(gEventFunc[Event]->Line,i,szParamName),TRUE),CurrentArg); 
			i++;
			CurrentArg = va_arg(marker,PCHAR);
		}
		va_end(marker);
	}

	if (!gEventStack) { 
		gEventStack = pEvent; 
	} else { 
		PEVENTSTACK pTemp = NULL; 
		for (pTemp = gEventStack;pTemp->pNext;pTemp=pTemp->pNext); 
		pTemp->pNext = pEvent; 
	} 
} 

VOID CheckChatForEvent(PCHAR szMsg)
{
		if ((gMacroBlock) && (!gMacroPause) && (!gbUnload) && (!gZoning)/* && (!gDelayZoning)*/) { 
			CHAR Arg1[MAX_STRING] = {0}; 
			CHAR Arg2[MAX_STRING] = {0}; 
			CHAR Arg3[MAX_STRING] = {0}; 

			if ((strstr(szMsg," tells the guild, '")) && (CHATEVENT(CHAT_GUILD))) { 
				strncpy(Arg1,szMsg,(DWORD)(strstr(szMsg," tells the guild, '")-szMsg)); 
				strcpy(Arg2,strstr(szMsg," tells the guild, '")+19); 
				Arg2[strlen(Arg2)-1]=0; 
				AddEvent(EVENT_CHAT,"guild",Arg1,Arg2,NULL); 
			} else if ((strstr(szMsg," tells the group, '")) && (CHATEVENT(CHAT_GROUP))) { 
				strncpy(Arg1,szMsg,(DWORD)(strstr(szMsg," tells the group, '")-szMsg)); 
				strcpy(Arg2,strstr(szMsg," tells the group, '")+19); 
				Arg2[strlen(Arg2)-1]=0; 
				AddEvent(EVENT_CHAT,"group",Arg1,Arg2,NULL); 
			} else if ((strstr(szMsg," tells you, '")) && (CHATEVENT(CHAT_TELL))) { 
				strncpy(Arg1,szMsg,(DWORD)(strstr(szMsg," tells you, '")-szMsg)); 
				strcpy(Arg2,strstr(szMsg," tells you, '")+13); 
				Arg2[strlen(Arg2)-1]=0; 
				AddEvent(EVENT_CHAT,"tell",Arg1,Arg2,NULL); 
			} else if ((strstr(szMsg," says out of character, '")) && (CHATEVENT(CHAT_OOC))) { 
				strncpy(Arg1,szMsg,(DWORD)(strstr(szMsg," says out of character, '")-szMsg)); 
				strcpy(Arg2,strstr(szMsg," says out of character, '")+25); 
				Arg2[strlen(Arg2)-1]=0; 
				AddEvent(EVENT_CHAT,"ooc",Arg1,Arg2,NULL); 
			} else if ((strstr(szMsg," shouts, '")) && (CHATEVENT(CHAT_SHOUT))) { 
				strncpy(Arg1,szMsg,(DWORD)(strstr(szMsg," shouts, '")-szMsg)); 
				strcpy(Arg2,strstr(szMsg," shouts, '")+10); 
				Arg2[strlen(Arg2)-1]=0; 
				AddEvent(EVENT_CHAT,"shout",Arg1,Arg2,NULL); 
			} else if ((strstr(szMsg," auctions, '")) && (CHATEVENT(CHAT_AUC))) { 
				strncpy(Arg1,szMsg,(DWORD)(strstr(szMsg," auctions, '")-szMsg)); 
				strcpy(Arg2,strstr(szMsg," auctions, '")+12); 
				Arg2[strlen(Arg2)-1]=0; 
				AddEvent(EVENT_CHAT,"auc",Arg1,Arg2,NULL); 
			} else if ((strstr(szMsg," says '")) && (CHATEVENT(CHAT_SAY))) { 
				strncpy(Arg1,szMsg,(DWORD)(strstr(szMsg," says '")-szMsg)); 
				strcpy(Arg2,strstr(szMsg," says '")+7); 
				Arg2[strlen(Arg2)-1]=0; 
				AddEvent(EVENT_CHAT,"say",Arg1,Arg2,NULL); 
			} else if ((strstr(szMsg," says, '")) && (CHATEVENT(CHAT_SAY))) { 
				strncpy(Arg1,szMsg,(DWORD)(strstr(szMsg," says, '")-szMsg)); 
				strcpy(Arg2,strstr(szMsg," says, '")+8); 
				Arg2[strlen(Arg2)-1]=0; 
				AddEvent(EVENT_CHAT,"say",Arg1,Arg2,NULL); 
			} else if ( (strstr(szMsg," tells ")) && (strstr(szMsg,":")) && (strstr(szMsg,", '")) && (CHATEVENT(CHAT_CHAT)) ) {
				strncpy(Arg1,szMsg,(DWORD)(strstr(szMsg," tells ")-szMsg)); 
				strcpy(Arg3,strstr(szMsg," tells ")+7); 
				Arg3[strlen(Arg3)-1]=0; 
				strcpy(Arg2,strstr(Arg3,", '")+3); 
				Arg3[strstr(Arg3,":")-Arg3]=0; 
				AddEvent(EVENT_CHAT,Arg3,Arg1,Arg2,NULL); 
			} else { 
				PEVENTLIST pEvent = pEventList; 
				while (pEvent) { 
					if (strstr(szMsg,pEvent->szMatch)) { 
						AddCustomEvent(pEvent,szMsg); 
					} 
					pEvent = pEvent->pNext; 
				} 
			} 
		} 
}

VOID DropTimers(VOID)
{
	PTIMER pTimer;
	CHAR szOrig[MAX_STRING] = {0};
	for (pTimer=gTimer;pTimer;pTimer=pTimer->pNext) {
		if (pTimer->Current==0) continue;
		pTimer->Current--;
		if (pTimer->Current!=0) continue;
		itoa(pTimer->Original,szOrig,10);
		AddEvent(EVENT_TIMER,pTimer->szName,szOrig,NULL);
	}
}


VOID FreeTimers()
{
	PTIMER pNext;
	while (gTimer) {
		pNext=gTimer->pNext;
		free(gTimer);
		gTimer = pNext;
	}
}

VOID FreeVarStrings(PVARSTRINGS pVarStrings)
{
	PVARSTRINGS pNext;
	while (pVarStrings) {
		pNext = pVarStrings->pNext;
		free(pVarStrings);
		pVarStrings=pNext;
	}
}

VOID FreeVarArrays()
{
	PVARARRAYS pNext;
	while (gArray) {
		pNext = gArray->pNext;
		FreeVarStrings(gArray->pVarStrings);
		free(gArray);
		gArray=pNext;
	}
}

PTIMER GetTimer(PCHAR szName, BOOL Create)
{
	PTIMER pTimer = gTimer;
	for (;pTimer;pTimer=pTimer->pNext) {
		if (!strcmp(pTimer->szName,szName)) return pTimer;
	}
	if (!Create) return NULL;
	PTIMER pVar = (PTIMER)malloc(sizeof(TIMER));
	if (!pVar) return NULL;
	strncpy(pVar->szName,szName,MAX_VARNAME-1);
	pVar->Current = 0;
	pVar->Original= 0;
	pVar->pNext = gTimer;
	gTimer = pVar;
	return pVar;
}

PCHAR GetMacroStr(PCHAR szName, BOOL Create)
{
	PCHAR szLocal = GetVarString(gMacroStr,szName);
	if (szLocal || !Create) return szLocal;
	PVARSTRINGS pVar = NewVarString(szName,"GLOBAL");
	if (!pVar) return NULL;
	pVar->pNext = gMacroStr;
	gMacroStr = pVar;
	return pVar->szVar;
}

PCHAR GetLocalStr(PCHAR szName, BOOL Create)
{
	if (!gMacroStack) return NULL;
	PCHAR szLocal = GetVarString(gMacroStack->LocalStr,szName);
	if (szLocal || !Create) return szLocal;
	PVARSTRINGS pVar = NewVarString(szName,"LOCAL");
	if (!pVar) return NULL;
	pVar->pNext = gMacroStack->LocalStr;
	gMacroStack->LocalStr = pVar;
	return pVar->szVar;
}


PCHAR GetStackStr(PCHAR szName, BOOL Create)
{
	if (!gMacroStack) return NULL;
	PCHAR szLocal = GetVarString(gMacroStack->StackStr,szName);
	if (szLocal || !Create) return szLocal;
	PVARSTRINGS pVar = NewVarString(szName,"PARAM");
	if (!pVar) return NULL;
	pVar->pNext = gMacroStack->StackStr;
	gMacroStack->StackStr = pVar;
	return pVar->szVar;
}

PCHAR GetArrayStr(PVARARRAYS pArray, DWORD Id1, DWORD Id2, BOOL Create)
{
	CHAR szName[MAX_VARNAME] = {0};
	if (pArray->OneDimension) {
		itoa(Id1,szName,10);
	} else {
		sprintf(szName,"%d-%d",Id1,Id2);
	}
	PCHAR szLocal = GetVarString(pArray->pVarStrings,szName);
	if (szLocal || !Create) return szLocal;
	PVARSTRINGS pVar = NewVarString(szName,"ARRAY-ELEMENT");
	if (!pVar) return NULL;
	pVar->pNext = pArray->pVarStrings;
	pArray->pVarStrings = pVar;
	return pVar->szVar;
}

PVARARRAYS GetArray(PCHAR szName, BOOL Create)
{
	PVARARRAYS pArray = gArray;
	for (;pArray;pArray=pArray->pNext) {
		if (!strcmp(pArray->szName,szName)) return pArray;
	}
	if (!Create) return NULL;
	PVARARRAYS pVar = (PVARARRAYS)malloc(sizeof(VARARRAYS));
	if (!pVar) return NULL;
	strncpy(pVar->szName,szName,MAX_VARNAME-1);
	pVar->OneDimension=TRUE;
	pVar->pVarStrings=NULL;
	pVar->pNext = gArray;
	gArray = pVar;
	return pVar;
}


VOID GetVariable(PCHAR szVar, PCHAR *szResult, PTIMER *pTimer)
{
	DWORD Index1 = -1;
	DWORD Index2 = -1;
	if ((strstr(szVar,"(")) && (strstr(szVar,")"))) {
		Index1=atoi(strstr(szVar,"(")+1);
		if (strstr(szVar,",")) Index2=atoi(strstr(szVar,",")+1);
		szVar[strstr(szVar,"(")-szVar]=0;
	}

	if (Index1 != -1) {
		PVARARRAYS pArray= GetArray(szVar);
		if (!pArray) return;
		if (pArray->OneDimension && Index2 != -1) return;
		if (!pArray->OneDimension && Index2 == -1) return;
		*szResult = GetArrayStr(pArray,Index1,Index2,TRUE);
		return;
	}

	if (gMacroStack) {
		if (*szResult = GetStackStr(szVar)) return;
		if (*szResult = GetLocalStr(szVar)) return;
	}
	if (*szResult = GetMacroStr(szVar)) return;
	if (*pTimer = GetTimer(szVar)) return;
	return;
}

BOOL SearchVariables(PCHAR szVar,PCHAR szOutput,PVARSTRINGS pVarStrings)
{
	BOOL Found = FALSE;
	while (pVarStrings && !Found) {
		if (!strcmp(szVar,pVarStrings->szName)) {
			CheckVariableRecursion(pVarStrings->szVar);
			strcat(szOutput,pVarStrings->szVar);
			Found=TRUE;
		}
		pVarStrings = pVarStrings->pNext;
	}
	return Found;
}


BOOL SearchTimers(PCHAR szVar,PCHAR szOutput)
{
	PTIMER pTimer=gTimer;
	BOOL Found = FALSE;
	while (pTimer && !Found) {
		if (!strcmp(szVar,pTimer->szName)) {
			CHAR szTemp[MAX_STRING] = {0};
			itoa(pTimer->Current,szTemp,10);
			strcat(szOutput,szTemp);
			Found=TRUE;
		}
		pTimer = pTimer->pNext;
	}
	return Found;
}


BOOL SearchArrays(PCHAR szVar,PCHAR szOutput)
{
	DWORD Index1 = -1;
	DWORD Index2 = -1;
	CHAR szArray[MAX_STRING] = {0};
	if ((strstr(szVar,"(")) && (strstr(szVar,")"))) {
		Index1=atoi(strstr(szVar,"(")+1);
		if (strstr(szVar,",")) Index2=atoi(strstr(szVar,",")+1);
		strcpy(szArray,szVar);
		szArray[strstr(szArray,"(")-szArray]=0;
	}

	if (Index1 != -1) {
		PVARARRAYS pArray= GetArray(szArray,FALSE);
		PCHAR szResult = NULL;
		if (!pArray) return FALSE;
		if (pArray->OneDimension && Index2 != -1) return FALSE;
		if (!pArray->OneDimension && Index2 == -1) return FALSE;
		szResult = GetArrayStr(pArray,Index1,Index2,TRUE);
		if (szResult) {
			CheckVariableRecursion(szResult);
			strcat(szOutput,szResult);
			return TRUE;
		}
	}
	return FALSE;
}


BOOL IsVariableDefined(PCHAR szVar) {
	PCHAR szCheck = NULL;
	PTIMER pCheck = NULL;

	GetVariable(szVar,&szCheck,&pCheck);
	if (szCheck || pCheck) {
		return TRUE;
	} else {
		PVARARRAYS pArray = gArray;
		BOOL IsArray = FALSE;
		while (pArray && !IsArray) {
			if (!strcmp(pArray->szName,szVar)) IsArray=TRUE;
			pArray = pArray->pNext;
		}
		if (IsArray) {
			return TRUE;
		} else {
			return FALSE;
		}
	}
}


// ***************************************************************************
// Function:    DeclareVar
// Description: Our '/declare' command
// Usage:       /declare varname [global|local|timer|array|array2]
// ***************************************************************************
VOID DeclareVar(PSPAWNINFO pChar, PCHAR szLine)
{
	bRunNextCommand = TRUE;
	CHAR Arg1[MAX_STRING] = {0};
	CHAR Arg2[MAX_STRING] = {0};
	GetArg(Arg1,szLine,1);
	GetArg(Arg2,szLine,2);
	if (Arg1[0]==0 || Arg2[0]==0) {
		WriteChatColor("Usage: /declare <varname> <global|local|timer|array|array2>",USERCOLOR_DEFAULT);
	} else {
		PCHAR szCheck = NULL;
		PTIMER pCheck = NULL;
		GetVariable(Arg1,&szCheck,&pCheck);
		if (szCheck || pCheck) {
			WriteChatColor("Variable name already defined.",USERCOLOR_DEFAULT);
		} else if (!stricmp(Arg2,"global")) {
			GetMacroStr(Arg1,TRUE);
		} else if (!stricmp(Arg2,"local")) {
			if (gMacroStack) {
				GetLocalStr(Arg1,TRUE);
			} else {
				WriteChatColor("Unable to define local variables when a macro is not running.",USERCOLOR_DEFAULT);
			}
		} else if (!stricmp(Arg2,"timer")) {
			GetTimer(Arg1,TRUE);
		} else if (!stricmp(Arg2,"array") || !stricmp(Arg2,"array2")) {
			GetArray(Arg1,TRUE)->OneDimension = (Arg2[5]!='2');
		} else {
			WriteChatColor("Usage: /declare varname [global|local|timer|array|array2]",USERCOLOR_DEFAULT);
		}
	}
}
