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

/* VAR SYSTEM INDEPENDENT */
// in-place cleanup of tabs, leading/trailing space
VOID CleanMacroLine(PCHAR szLine)
{
	if (!szLine || szLine[0]==0)
		return;
	PCHAR pChar=szLine;
	while(pChar[0])
	{
		if (pChar[0]=='\t' || pChar[0]==0x0a || pChar[0]==0x0d)
			pChar[0]=' ';
		++pChar;
	}
	// find beginning and end
	PCHAR pStart=szLine;
	unsigned long Length=strlen(szLine);
	PCHAR pEnd=&szLine[Length-1];

	while(*pStart==' ')
		++pStart;
	while(*pEnd==' ')
		--pEnd;
	if (!*pStart || !*pEnd)
	{
		szLine[0]=0;
		return;
	}
	// keep only this part.
	unsigned long NewLength=1+pEnd-pStart;
	if (NewLength==Length)
		return;//nothing to do
	memmove(szLine,pStart,NewLength);
	szLine[NewLength]=0;
}

// ***************************************************************************
// Function:    Include
// Description: Includes another macro file
// Usage:       #include <filename>
// ***************************************************************************
DWORD Include(PCHAR szFile)
{
    CHAR szTemp[MAX_STRING] = {0};
    FILE *fMacro = fopen(szFile,"rt");
    DWORD LineNumber=0;
    BOOL InBlockComment = FALSE;
    PMACROBLOCK pAddedLine = NULL;
    if (!fMacro) {
        FatalError("Couldn't open include file: %s",szFile);
        return 0;
    }
    DebugSpewNoFile("Include - Including: %s",szFile);
    while (!feof(fMacro)) {

        fgets(szTemp,MAX_STRING,fMacro);
		CleanMacroLine(szTemp);
        LineNumber++;

        if (!strncmp(szTemp,"|**",3)) {
            InBlockComment=TRUE;
        }
        if (!InBlockComment) {
            if (NULL == (pAddedLine=AddMacroLine(szTemp))) {
            MacroError("Unable to add macro line.");
            fclose(fMacro);
                gszMacroName[0]=0;
                gRunning = 0;
                return 0;
            } else if (1 != (DWORD)pAddedLine) {
                pAddedLine->LineNumber = LineNumber;
                strcpy(pAddedLine->SourceFile, GetFilenameFromFullPath(szFile));
            }
        } else {
            DebugSpewNoFile("Macro - BlockComment: %s",szTemp);
            if (!strncmp(&szTemp[strlen(szTemp)-3],"**|",3)) {
                InBlockComment=FALSE;
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
PMACROBLOCK AddMacroLine(PCHAR szLine)
{
    PMACROBLOCK pBlock = NULL;
	// replace all tabs with spaces
    if ((szLine[0]==0) || (szLine[0]=='|')) return (PMACROBLOCK)1;

    PDEFINE pDef = pDefines;
    if (szLine[0]!='#') while (pDef) {
        while (strstr(szLine,pDef->szName)) {
            CHAR szNew[MAX_STRING] = {0};
            strncpy(szNew,szLine,strstr(szLine,pDef->szName)-szLine);
            strcat(szNew,pDef->szReplace);
            strcat(szNew,strstr(szLine,pDef->szName)+strlen(pDef->szName));
            strcpy(szLine,szNew);
        }
        pDef = pDef->pNext;
    }
    if (szLine[0]=='#') {
        if (!strnicmp(szLine,"#include ",9)) {
            CHAR Filename[MAX_STRING] = {0};
            szLine+=8;
            while (szLine[0]==' ') szLine++;

            if (!strstr(szLine,".")) strcat(szLine,".mac");
            sprintf(Filename,"%s\\%s",gszMacroPath, szLine);

            //DebugSpewNoFile("AddMacroLine - Including file: %s",Filename);
            return (PMACROBLOCK)Include(Filename);
        } else if (!strnicmp(szLine,"#turbo",6)) {
            gTurbo = TRUE;
            CHAR szArg[MAX_STRING] = {0};
            GetArg(szArg,szLine,2);
            gMaxTurbo = atoi(szArg);
			if (gMaxTurbo==0)
				gMaxTurbo=20;
			else if (gMaxTurbo>40) 
			{
				MacroError("#turbo %d is too high, setting at 40 (maximum)",gMaxTurbo);
				gMaxTurbo=40;
			}
        } else if (!strnicmp(szLine,"#define ",8)) {
            CHAR szArg1[MAX_STRING] = {0};
            CHAR szArg2[MAX_STRING] = {0};
            PDEFINE pDef = (PDEFINE)malloc(sizeof(DEFINE));
            GetArg(szArg1,szLine,2);
            GetArg(szArg2,szLine,3);
            if ((szArg1[0]!=0) && (szArg2[0]!=0)) {
                strcpy(pDef->szName,szArg1);
                strcpy(pDef->szReplace,szArg2);
                pDef->pNext = pDefines;
                pDefines = pDef;
            } else {
                MacroError("Bad #define: %s",szLine);
            }
        } else if (!strnicmp(szLine,"#event ",7)) {
            CHAR szArg1[MAX_STRING] = {0};
            CHAR szArg2[MAX_STRING] = {0};
            PEVENTLIST pEvent = (PEVENTLIST)malloc(sizeof(EVENTLIST));
            GetArg(szArg1,szLine,2);
            GetArg(szArg2,szLine,3);
            if ((szArg1[0]!=0) && (szArg2[0]!=0)) {
                sprintf(pEvent->szName,"Sub Event_%s",szArg1);
                strcpy(pEvent->szMatch,szArg2);
#ifdef USEBLECHEVENTS
				pEvent->BlechID=pEventBlech->AddEvent(pEvent->szMatch,EventBlechCallback,pEvent);
#endif
                pEvent->pEventFunc = NULL;
                pEvent->pNext = pEventList;
                pEventList = pEvent;
            } else {
                MacroError("Bad #event: %s",szLine);
            }
        } else if (!strnicmp(szLine,"#chat ",6)) {
            szLine+=5;
            while (szLine[0]==' ') szLine++;
            if (!stricmp(szLine,"say"))   gEventChat = gEventChat | CHAT_SAY;
            if (!stricmp(szLine,"tell"))  gEventChat = gEventChat | CHAT_TELL;
            if (!stricmp(szLine,"ooc"))   gEventChat = gEventChat | CHAT_OOC;
            if (!stricmp(szLine,"shout")) gEventChat = gEventChat | CHAT_SHOUT;
            if (!stricmp(szLine,"auc"))   gEventChat = gEventChat | CHAT_AUC;
            if (!stricmp(szLine,"guild")) gEventChat = gEventChat | CHAT_GUILD;
            if (!stricmp(szLine,"group")) gEventChat = gEventChat | CHAT_GROUP;
            if (!stricmp(szLine,"chat"))  gEventChat = gEventChat | CHAT_CHAT;
        } else {
			MacroError("Unknown # command: %s",szLine);
            return FALSE;
        }
    }

    pBlock = (PMACROBLOCK)malloc(sizeof(MACROBLOCK));
    if (!pBlock) return NULL;
    //DebugSpewNoFile("AddMacroLine - Adding: %s",szLine);
    strcpy(pBlock->Line,szLine);
    pBlock->LineNumber = -1;
    pBlock->SourceFile[0]=0;
    pBlock->pNext=NULL;
    pBlock->pPrev=NULL;

    if ((!stricmp(szLine,"Sub Event_Chat")) || (!strnicmp(szLine,"Sub Event_Chat(",15))) {
        gEventFunc[EVENT_CHAT] = pBlock;
    } else if ((!stricmp(szLine,"Sub Event_Timer")) || (!strnicmp(szLine,"Sub Event_Timer(",16))) {
        gEventFunc[EVENT_TIMER] = pBlock;
    } else {
        PEVENTLIST pEvent = pEventList;
        while (pEvent) {
            if (!stricmp(szLine,pEvent->szName)) {
                pEvent->pEventFunc = pBlock;
            } else {
                CHAR szNameP[MAX_STRING] = {0};
                sprintf(szNameP,"%s(",pEvent->szName);
                if (!strnicmp(szLine,szNameP,strlen(szNameP))) {
                    pEvent->pEventFunc = pBlock;
                }
            }
            pEvent = pEvent->pNext;
        }
    }
    if (!gMacroBlock) {
        gMacroBlock=pBlock;
    } else {
        PMACROBLOCK pLoop = gMacroBlock;
        while (pLoop->pNext) pLoop = pLoop->pNext;
        pLoop->pNext = pBlock;
        pBlock->pPrev = pLoop;
    }
    return pBlock;
}


// ***************************************************************************
// Function:    Macro
// Description: Our '/macro' command
// Usage:       /macro <filename>
// ***************************************************************************
VOID Macro(PSPAWNINFO pChar, PCHAR szLine)
{
    bRunNextCommand = TRUE;
    CHAR szTemp[MAX_STRING] = {0};
    CHAR Filename[MAX_STRING] = {0};
    PCHAR Params = NULL;
    PCHAR szNext = NULL;
    BOOL InBlockComment = FALSE;
    if (szLine[0] == 0) {
        SyntaxError("Usage: /macro <filename> [param [param...]]");
        return;
    }
	gMaxTurbo=20;
	gTurbo=true;
    GetArg(szTemp,szLine,1);
    Params = GetNextArg(szLine);

    strcpy(gszMacroName,szTemp);
    if (!strstr(szTemp,".")) strcat(szTemp,".mac");
    sprintf(Filename,"%s\\%s",gszMacroPath, szTemp);

    FILE *fMacro = fopen(Filename,"rt");
    if (!fMacro) {
        MacroError(szTemp,"Couldn't open macro file: %s",Filename);
        gszMacroName[0]=0;
        gRunning = 0;
        return;
    }
    if (gMacroBlock) EndMacro(pChar,"keep keys vars arrays timers");
    gRunning = GetTickCount();
    gEventChat = 0;
    strcpy(gszMacroName,szTemp);
    DebugSpew("Macro - Loading macro: %s",Filename);
    DWORD LineNumber = 0;
    PMACROBLOCK pAddedLine = NULL;
    while (!feof(fMacro)) {
        fgets(szTemp,MAX_STRING,fMacro);
		CleanMacroLine(szTemp);
        LineNumber++;
        if (!strncmp(szTemp,"|**",3)) {
            InBlockComment=TRUE;
        }
        if (!InBlockComment) {
            if (NULL == (pAddedLine=AddMacroLine(szTemp))) {
                MacroError("Unable to add macro line.");
                fclose(fMacro);
                gszMacroName[0]=0;
                gRunning = 0;
                return;
            } else if (1 != (DWORD)pAddedLine) {
                pAddedLine->LineNumber = LineNumber;
                strcpy(pAddedLine->SourceFile, GetFilenameFromFullPath(Filename));
            }
        } else {
            DebugSpew("Macro - BlockComment: %s",szTemp);
            if (!strncmp(&szTemp[strlen(szTemp)-3],"**|",3)) {
                InBlockComment=FALSE;
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
    strcpy(szTemp, "Main");
    if (Params[0] !=0) {
        strcat(szTemp, " ");
        strcat(szTemp, Params);
    }
    DebugSpew("Macro - Starting macro with '/call %s'",szTemp);
    Call(pChar, szTemp);
    if ((gMacroBlock) && (gMacroBlock->pNext)) gMacroBlock = gMacroBlock->pNext;
    if ((!gMacroBlock) || (!gMacroStack)) {
        gszMacroName[0]=0;
        gRunning = 0;
    }
}
// ***************************************************************************
// Function:    GracefullyEndBadMacro
// Description: Used to end a 'bad' macro (parsing issues, etc)
// ***************************************************************************
/*
VOID GracefullyEndBadMacro(PSPAWNINFO pChar, PMACROBLOCK pBadLine, PCHAR szFormat, ...)
{
    CHAR szArgs[MAX_STRING] = {0};
    va_list vaList;
    va_start( vaList, szFormat );
    vsprintf(szArgs,szFormat, vaList);
    if (gMacroBlock && pBadLine) {
		MacroError("Ending macro: %s",szArgs);
        gMacroBlock=pBadLine;
        DumpStack(pChar,"");
        EndMacro(pChar,"");
    } else {
		MacroError("Error: %s",szArgs);
    }
}
/**/

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
	ParseKeyCombo("Esc",Escape);
	if(ppContainerMgr && pContainerMgr) {
		PEQ_CONTAINERWND_MANAGER ContainerMgr = (PEQ_CONTAINERWND_MANAGER)pContainerMgr;
		DWORD concount=2; //Close inv + clear target
		if (ContainerMgr->pWorldContents && ContainerMgr->pWorldContents->Open==1) concount++;
		for (i=0;i<25;i++) {
			if (ContainerMgr->pPCContainers[i] && ContainerMgr->pPCContainers[i]->Wnd.Show==1) concount++;
		}
		for (i=0;i<concount;i++) 
		{
			MQ2HandleKeyDown(Escape);
			MQ2HandleKeyUp(Escape);
		}
			//Press(pChar,"esc");
		if (!ppInventoryWnd) {
			PCSIDLWND pInvWindow = (PCSIDLWND)pInventoryWnd;
			if (pInvWindow && pInvWindow->Show==0) 
				DoMappable(pChar,"inventory");
		}
	} else {
    DoMappable(pChar,"inventory");
		for (i=0;i<10;i++) 
		{
			MQ2HandleKeyDown(Escape);
			MQ2HandleKeyUp(Escape);
		}
    DoMappable(pChar,"inventory");
	}
}

// ***************************************************************************
// Function:    Delay
// Description: Our '/delay' command
// Usage:       /delay <time>
// ***************************************************************************
VOID Delay(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szVal[MAX_STRING] = {0};
    LONG VarValue;

    if (szLine[0]==0) {
        SyntaxError("Usage: /delay <time>");
        return;
    }
    GetArg(szVal,szLine,1);
    VarValue = atol(szVal);
    switch (szVal[strlen(szVal)-1]) {
        case 'm':
        case 'M':
            VarValue *= 60;
        case 's':
        case 'S':
            VarValue *= 10;
    }
    gDelay = VarValue;
    DebugSpewNoFile("Delay - %d",gDelay);
}

// ***************************************************************************
// Function:    Echo
// Description: Our '/echo' command
//              Echos text to the chatbox
// Usage:       /echo <text>
// ***************************************************************************
VOID Echo(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szEcho[MAX_STRING] = {0};
    bRunNextCommand = TRUE;
	strcpy(szEcho,DebugHeader);
    strcat(szEcho," ");
    strcat(szEcho,szLine);
    DebugSpewNoFile("Echo - %s",szEcho);
    WriteChatColor(szEcho,USERCOLOR_CHAT_CHANNEL);

}

#ifndef USEMQ2DATAVARS
/* MQ2USERVARS */
PCHAR GetFuncParamName(PCHAR szMacroLine, DWORD ParamNum, PCHAR szParamName)
{
    if (strnicmp(szMacroLine,"sub ",4)) return NULL;
    PCHAR szSubParamNamePointer = szMacroLine+4;
    while ((szSubParamNamePointer[0]!='(') && (szSubParamNamePointer[0]!=0)) szSubParamNamePointer++;
    if (szSubParamNamePointer[0]=='(') szSubParamNamePointer++;
    if (szSubParamNamePointer[0]!=0) {
        GetArg(szParamName,szSubParamNamePointer,ParamNum+1,TRUE,TRUE,TRUE);
        if (szParamName[strlen(szParamName)-1]==')') szParamName[strlen(szParamName)-1]=0;
    }
    if (szParamName[0]==0) sprintf(szParamName,"Param%d",ParamNum);
    return szParamName;
}

// ***************************************************************************
// Function:    Goto
// Description: Our '/Goto' command
// Usage:       /goto <:label>
// ***************************************************************************
VOID Goto(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szTemp[MAX_STRING] = {0};
    PMACROBLOCK pFromLine = gMacroBlock;
    bRunNextCommand = TRUE;
    if (!gMacroBlock) {
        MacroError("Cannot goto when a macro isn't running.");
        return;
    }
    while (gMacroBlock->pPrev) {
        gMacroBlock=gMacroBlock->pPrev;
        if (!strnicmp(gMacroBlock->Line,"Sub ",4)) break;
    }

    while (gMacroBlock->pNext) {
        gMacroBlock=gMacroBlock->pNext;
        if (!strnicmp(gMacroBlock->Line,"Sub ",4)) {
			gMacroBlock=pFromLine;
            FatalError("Couldn't find label %s",szLine);
            return;
        }
        if (!stricmp(szLine,gMacroBlock->Line)) {
            DebugSpewNoFile("Goto - went to label %s",szLine);
            return;
        }
    }
    if (!stricmp(szLine,gMacroBlock->Line)) {
        DebugSpewNoFile("Goto - went to label %s",szLine);
        return;
    }
	gMacroBlock=pFromLine;
    FatalError("Couldn't find label %s",szLine);
}



VOID DumpStack(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szTemp[MAX_STRING] = {0};
    CHAR szSub[MAX_STRING] = {0};
    PMACROSTACK pMS = gMacroStack;
    while (pMS!=NULL) {
        sprintf(szTemp,"%s@%d (%s): %s",pMS->Location->SourceFile,pMS->Location->LineNumber, GetSubFromLine(pMS->Location,szSub), pMS->Location->Line);
        WriteChatColor(szTemp,USERCOLOR_DEFAULT);
        pMS=pMS->pNext;
    }
}

// ***************************************************************************
// Function:    EndMacro
// Description: Our '/endmacro' command
// Usage:       /endmacro
// ***************************************************************************
VOID EndMacro(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR Buffer[MAX_STRING] = {0};
    DWORD i;
    PMACROBLOCK pPrev;
    PMACROSTACK pStack;
    PEVENTSTACK pEvent;
    PEVENTLIST pEventL;
    BOOL bKeepKeys = gKeepKeys;
    BOOL bKeepVars = TRUE;
    BOOL bKeepTimers = FALSE;
    BOOL bKeepArrays = FALSE;
    if (szLine[0]!=0) {
        GetArg(Buffer,szLine,1);
        szLine = GetNextArg(szLine);
        if (stricmp(Buffer,"keep")) {
            WriteChatColor("Usage: /endmacro [keep [vars] [arrays] [keys] [timers]]",USERCOLOR_DEFAULT);
            return;
        }
        while (szLine[0]!=0) {
            GetArg(Buffer,szLine,1);
            szLine = GetNextArg(szLine);
            if (!stricmp(Buffer,"keys")) bKeepKeys = TRUE;
            if (!stricmp(Buffer,"vars")) bKeepVars = TRUE;
            if (!stricmp(Buffer,"arrays")) bKeepArrays = TRUE;
            if (!stricmp(Buffer,"timers")) bKeepTimers = TRUE;
        }
    }

    if (!gMacroBlock) {
        MacroError("Cannot end a macro when one isn't running.");
        return;
    }
    while (gMacroBlock->pNext) gMacroBlock=gMacroBlock->pNext;
    while (gMacroBlock) {
        pPrev = gMacroBlock->pPrev;
        free(gMacroBlock);
        gMacroBlock = pPrev;
    }
    while (gMacroStack) {
        pStack = gMacroStack->pNext;
        if (gMacroStack->LocalStr) FreeVarStrings(gMacroStack->LocalStr);
        if (gMacroStack->StackStr) FreeVarStrings(gMacroStack->StackStr);
        free(gMacroStack);
        gMacroStack = pStack;
    }
    while (gEventStack) {
        pEvent = gEventStack->pNext;
        free(gEventStack);
        gEventStack = pEvent;
    }
    while (pEventList) {
        pEventL = pEventList->pNext;
        free(pEventList);
        pEventList = pEventL;
    }
    for  (i=0;i<NUM_EVENTS;i++) {
        gEventFunc[i]=NULL;
    }

    gMacroPause = FALSE;
    gEventChat=0;
    gFaceAngle=10000.0f;
    gLookAngle=10000.0f;
    gDelay = 0;
    gTurbo = FALSE;
    pDoorTarget = NULL;
    gszMacroName[0]=0;
    gRunning = 0;

    if (!bKeepKeys) {
		KeyCombo TempCombo;
        for (i=0;gDiKeyID[i].szName[0];i++) 
		{
			TempCombo.Data[3]=(unsigned char)gDiKeyID[i].Id;
			MQ2HandleKeyUp(TempCombo);
        }
    }

    if (!bKeepTimers || !bKeepVars || !bKeepArrays) {
        CHAR szTemp[MAX_STRING] = {0};
        if (bKeepTimers) strcat(szTemp," notimers");
        if (bKeepVars) strcat(szTemp," novars");
        if (bKeepArrays) strcat(szTemp," noarrays");
        ZapVars(pChar,szTemp);
    }

    DebugSpewNoFile("EndMacro - Ended");
	if (gFilterMacro != FILTERMACRO_NONE)
	    WriteChatColor("The current macro has ended.",USERCOLOR_DEFAULT);
}


// ***************************************************************************
// Function:    Call
// Description: Our '/call' command
// Usage:       /call <Subroutine>
// ***************************************************************************
VOID Call(PSPAWNINFO pChar, PCHAR szLine)
{
    PMACROSTACK pStack;
    PMACROBLOCK pCallingPoint = gMacroBlock;
    CHAR SubName[MAX_STRING] = {0};
    PCHAR SubParam = NULL;
    CHAR SubLine[MAX_STRING] = {0};
    CHAR SubLineP[MAX_STRING] = {0};
    DWORD StackNum = 0;
    bRunNextCommand = TRUE;
    if (szLine[0]==0) {
        SyntaxError("Usage: /call <subroutine> [param [param...]]");
        return;
    }
    if (!gMacroBlock) {
        MacroError("Cannot call when a macro isn't running.");
        return;
    }
    while (gMacroBlock->pPrev) gMacroBlock = gMacroBlock->pPrev;

    GetArg(SubName,szLine,1);
    SubParam = GetNextArg(szLine);

        sprintf(SubLine,"sub %s",SubName);
    sprintf(SubLineP,"sub %s(",SubName);
    while (gMacroBlock->pNext) {
        if (!stricmp(gMacroBlock->Line,SubLine) || !strnicmp(gMacroBlock->Line,SubLineP,strlen(SubLineP))) {
            DebugSpewNoFile("Call - Calling subroutine %s with params %s",SubName,SubParam);
            pStack = (PMACROSTACK)malloc(sizeof(MACROSTACK));
            pStack->Location = gMacroBlock;
            pStack->Return[0] = 0;
            pStack->StackStr = NULL;
            pStack->LocalStr = NULL;
            pStack->pNext = gMacroStack;
            gMacroStack = pStack;
        if (SubParam) {
            StackNum = 0;
                while (SubParam[0]!=0) {
                    CHAR szParamName[MAX_STRING] = {0};
                    GetArg(GetStackStr(GetFuncParamName(gMacroBlock->Line,StackNum,szParamName),TRUE),SubParam,1);
                SubParam = GetNextArg(SubParam);
                StackNum++;
            }
            }
        return;
    }
        gMacroBlock = gMacroBlock->pNext;
    }
	gMacroBlock=pCallingPoint;
    FatalError("Subroutine %s wasn't found",SubName);
}

VOID FailIf(PSPAWNINFO pChar, PCHAR szCommand, PMACROBLOCK pStartLine, BOOL All)
{
    DWORD Scope = 0;
    if (szCommand[strlen(szCommand)-1]=='{') {
		if (!gMacroBlock) {
	        DebugSpewNoFile("FailIf - Macro was ended before we could handle the false if command");
			return;
		}
        //DebugSpewNoFile("FailIf - Skipping to end of {}");
        Scope++;
        //DebugSpewNoFile("FailIf - Starting macroblock: %s",gMacroBlock->Line);
        gMacroBlock = gMacroBlock->pNext;
        while ((Scope>0)) {
            if (gMacroBlock->Line[0]=='}') Scope--;
            if (All) if (gMacroBlock->Line[strlen(gMacroBlock->Line)-1]=='{') Scope++;
            if (Scope>0) {
                if (!All) if (gMacroBlock->Line[strlen(gMacroBlock->Line)-1]=='{') Scope++;
                //DebugSpewNoFile("FailIf - Skipping(%d): %s",Scope,gMacroBlock->Line);
                if (!strnicmp(gMacroBlock->Line,"sub ",4)) {
					gMacroBlock=pStartLine;
					FatalError("{} pairing ran into anther subroutine");
                    return;
                }
                if (!gMacroBlock->pNext) {
					gMacroBlock=pStartLine;
                    FatalError("Bad {} block pairing");
                    return;
                }
                gMacroBlock = gMacroBlock->pNext;
            }
        }
        //DebugSpewNoFile("FailIf - End at: %s",gMacroBlock->Line);
        if ((!All) && (!strnicmp(gMacroBlock->Line,"} else ",7))) {
            //DebugSpewNoFile("FailIf - Else seen, running '%s'",gMacroBlock->Line+7);
            DoCommand(pChar,gMacroBlock->Line+7);
        } else {
            //DebugSpewNoFile("FailIf - } seen");
            bRunNextCommand = TRUE;
        }
    } else {
        bRunNextCommand = TRUE;
    }
}

VOID NewIf(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szCond[MAX_STRING] = {0};

	if (szLine[0]!='(')
	{
	    FatalError("Failed to parse /if command.  Expected () around conditions.");
	    SyntaxError("Usage: /if (<conditions>) <command>");
        return;
	}
	
	PCHAR pEnd=&szLine[1];
	DWORD nParens=1;
	while(1)
	{
		if (*pEnd=='(')
			nParens++;
		else if (*pEnd==')')
		{
			nParens--;
			if (nParens==0)
			{
				pEnd++;
				if (*pEnd!=' ')
				{
					FatalError("Failed to parse /if command.  Could not find command to execute.");
					SyntaxError("Usage: /if (<conditions>) <command>");
					return;
				}
				break;
			}
		}
		else if (*pEnd==0)
		{
			FatalError("Failed to parse /if command.  Could not find command to execute.");
			SyntaxError("Usage: /if (<conditions>) <command>");
			return;
		}
		++pEnd;
	}

	*pEnd=0;
	strcpy(szCond,szLine);
	*pEnd=' ';
	++pEnd;



	DOUBLE Result=0;
	if (!Calculate(szCond,Result))
	{
		FatalError("Failed to parse /if condition '%s', non-numeric encountered",szCond);
		return;
	}


	if (Result!=0)
		DoCommand(pChar,pEnd); 
	else
		FailIf(pChar,pEnd, gMacroBlock);
}




// ***************************************************************************
// Function:    DoEvents
// Description: Our '/doevents' command
// Usage:       /doevents [flush] [custom event]
// ***************************************************************************
VOID DoEvents(PSPAWNINFO pChar, PCHAR szLine)
{
    if (!gEventStack) return;
    if (!gMacroStack) return;

    DWORD sNum=0;
    CHAR sEvent[MAX_STRING]={0};
    PEVENTSTACK pEventNext = gEventStack->pNext;
    PEVENTSTACK pEventToRun = gEventStack;
    PEVENTSTACK *ppEventToRun = &gEventStack;
    PEVENTSTACK pEventPrev = NULL;
    PMACROSTACK pStack = NULL;
    PMACROBLOCK pMacro = NULL;
    CHAR SpecificEvent[MAX_STRING] = {0};
    BOOL Flush = FALSE;
    CHAR szTemp[MAX_STRING]= {0};
    DWORD NumEvents = 0;
    BOOL bCustomNum = FALSE;

    GetArg(szTemp,szLine,1);
    for (DWORD i=2;szTemp[0]!='\0';GetArg(szTemp,szLine,i++)) {
        if (szTemp[0]!='\0') {
            if (!stricmp(szTemp,"flush"))
                Flush=TRUE;
            else if (szTemp[0]>='0' && szTemp[0]<='9') {
                NumEvents=atoi(szTemp);
            } else
                sprintf(SpecificEvent,"Sub Event_%s",szTemp);
        }
    }
    if (stricmp(sEvent,SpecificEvent)) {
        strcpy(sEvent,SpecificEvent);
        sNum=NumEvents;
    }

    if (NumEvents)
        bCustomNum = TRUE;
    DebugSpewNoFile("DoEvents: Parms = '%s' Flush = %d -- SpecificEvent = %s -- NumEvents = %d",szLine,Flush,SpecificEvent,NumEvents);
    if (Flush) {
        if (SpecificEvent[0]=='\0') {
            while (gEventStack) {
                pEventNext = gEventStack->pNext;
                FreeVarStrings(gEventStack->EventStr);
                free(gEventStack);
                gEventStack = pEventNext;
            }
        } else {
            PEVENTSTACK pPrev=NULL;
            while (pEventToRun) {
                pEventNext = pEventToRun->pNext;
                DebugSpewNoFile("DoEvents.FlushSpecific: checking '%d\\%s' against '%s'",pEventToRun->Type,(pEventToRun->pEventList)?pEventToRun->pEventList->szName:"NULL",SpecificEvent);
                if (
                    ((pEventToRun->Type == EVENT_CHAT) && (!stricmp("Sub Event_Chat",SpecificEvent))) ||
                    ((pEventToRun->Type == EVENT_TIMER) && (!stricmp("Sub Event_Timer",SpecificEvent))) ||
                    ((pEventToRun->Type == EVENT_CUSTOM) && (!stricmp(pEventToRun->pEventList->szName,SpecificEvent)))
                    ) {
                    DebugSpewNoFile("DoEvents.FlushSpecific: found one");
                    PEVENTSTACK pThis=pEventToRun;
                    pEventToRun = pPrev->pNext = pThis->pNext;
                    FreeVarStrings(pThis->EventStr);
                    free(pThis);
                } else {
                    pPrev = pEventToRun;
                    pEventToRun = pEventToRun->pNext;
                }
            }
        }
        bRunNextCommand = TRUE;
        return;
    }
    BOOL Found = FALSE;
    if (SpecificEvent[0]) {
        DebugSpewNoFile("NumEvents: %d sNum: %d",NumEvents,sNum);
        if ((NumEvents && sNum) || (!NumEvents && !sNum)) {
            while (pEventToRun && !Found) {
                pEventNext = pEventToRun->pNext;
                DebugSpewNoFile("DoEvents.SpecificEvent: checking '%d\\%s' against '%s'",pEventToRun->Type,(pEventToRun->pEventList)?pEventToRun->pEventList->szName:"NULL",SpecificEvent);
                if (
                    ((pEventToRun->Type == EVENT_CHAT) && (!stricmp("Sub Event_Chat",SpecificEvent))) ||
                    ((pEventToRun->Type == EVENT_TIMER) && (!stricmp("Sub Event_Timer",SpecificEvent))) ||
                    ((pEventToRun->Type == EVENT_CUSTOM) && (!stricmp(pEventToRun->pEventList->szName,SpecificEvent)))
                ) {
                    DebugSpewNoFile("DoEvents.SpecificEvent: found one");
                    Found = TRUE;
                    if (sNum) sNum--;
                } else {
                    ppEventToRun = &pEventToRun->pNext;
                    pEventToRun = pEventToRun->pNext;
                }
            }
        }
    }
    if (!pEventToRun || (SpecificEvent[0] && !Found)) return;
    DebugSpewNoFile("DoEvents: Running event %d\\%s = 0x%p",pEventToRun->Type,(pEventToRun->pEventList)?pEventToRun->pEventList->szName:"NULL",pEventToRun);

    pStack = (PMACROSTACK)malloc(sizeof(MACROSTACK));
    gMacroStack->Location = gMacroStack->Location->pPrev;
    pStack->Location = gMacroBlock;
    pStack->Return[0] = 0;
    pStack->StackStr = pEventToRun->EventStr;
    pStack->LocalStr = NULL;
    pStack->pNext = gMacroStack;
    gMacroStack = pStack;
    if (pEventToRun->Type == EVENT_CUSTOM) {
        gMacroBlock = pEventToRun->pEventList->pEventFunc;
    } else {
        gMacroBlock = gEventFunc[pEventToRun->Type];
    }
    DebugSpewNoFile("DoEvents - Called event: %s",gMacroBlock->Line);
    free(pEventToRun);
    *ppEventToRun = pEventNext;
    bRunNextCommand = FALSE;
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
    if (!gMacroBlock) {
        MacroError("Cannot return when a macro isn't running.");
        return;
    }
    if ((!pStack) || (!pStack->pNext)) {
        // Top of stack (ie. returning from Sub Main)
        EndMacro(pChar,"");
        return;
    }

    strcpy(pStack->pNext->Return,szLine);
    gMacroBlock = pStack->pNext->Location;
    gMacroStack = pStack->pNext;
    if (pStack->LocalStr) FreeVarStrings(pStack->LocalStr);
    if (pStack->StackStr) FreeVarStrings(pStack->StackStr);
    free(pStack);
    DebugSpewNoFile("Return - Returned to %s",gMacroBlock->Line);

}



// ***************************************************************************
// Function:    For
// Description: Our '/for' command
// Usage:       /for v# <start> <to|downto> <end>
// ***************************************************************************
VOID For(PSPAWNINFO pChar, PCHAR szLine)
{
    bRunNextCommand = TRUE;
    CHAR ArgLoop[MAX_STRING] = {0};
    CHAR ArgStart[MAX_STRING] = {0};
    CHAR ArgDirection[MAX_STRING] = {0};
    CHAR ArgEnd[MAX_STRING] = {0};

    GetArg(ArgLoop,szLine,1);
    GetArg(ArgStart,szLine,2);
    GetArg(ArgDirection,szLine,3);
    GetArg(ArgEnd,szLine,4);
    _strlwr(ArgDirection);

    PTIMER pDummy = NULL;
    PCHAR szLoop = NULL;
    GetVariable(ArgLoop,&szLoop,&pDummy);
    if (pDummy) {
        FatalError("/for loops cannot loop on a timer");
        return;
    }
    if ((!szLoop) || (ArgStart[0] == 0) || (ArgDirection[0] == 0) || (ArgEnd[0] == 0) || ((strcmp(ArgDirection,"to")) && (strcmp(ArgDirection,"downto")))) {
        FatalError("Usage: /for <variable> <start> <to|downto> <end> [step x]");
        return;
    }
    if (!gMacroBlock) {
        MacroError("Can only use /for during a macro.");
        return;
    }

    strcpy(szLoop, ArgStart);

}

// ***************************************************************************
// Function:    Next
// Description: Our '/next' command
// Usage:       /next v#
// ***************************************************************************
VOID Next(PSPAWNINFO pChar, PCHAR szLine)
{
    bRunNextCommand = TRUE;
    CHAR szComp[MAX_STRING] = {0};
    CHAR ForLine[MAX_STRING] = {0};
    CHAR szNext[MAX_STRING] = {0};
    PMACROBLOCK pMacroLine = gMacroBlock;
    LONG StepSize = 1;
    GetArg(szNext,szLine,1);
    PTIMER pDummy = NULL;
    PCHAR szLoop = NULL;
    GetVariable(szNext,&szLoop,&pDummy);
    if (pDummy) {
        FatalError("/for loops cannot loop on a timer");
        return;
    }
    if (!szLoop) {
        SyntaxError("Usage: /next <variable>");
        return;
    }
    if (!gMacroBlock) {
        MacroError("Can only use /next during a macro.");
        return;
    }
    sprintf(szComp,"/for %s",szNext);
    while (pMacroLine->pPrev) {
        strcpy(ForLine,pMacroLine->Line);
        if (!strnicmp(ForLine,"Sub ",4)) {
            FatalError("/next without matching /for");
            return;
        }
        if (strnicmp(ForLine,"/for ",5)) {
			pMacroLine = pMacroLine->pPrev;
            continue;
        }
        if (!strnicmp(ParseMacroParameter(pChar,ForLine),szComp,strlen(szComp))) {
			if (!gMacroBlock) {
				// PMP bailed on us, we need to exit...
				return;
			}
            CHAR szTemp[MAX_STRING] = {0};
            DWORD VarNum = atoi(szLine+1);
            LONG Loop;
            if (strstr(_strlwr(strcpy(szTemp,ForLine)),"step")) {
                PCHAR pTemp = strstr(szTemp,"step")+4;
                while ( (pTemp[0]!=0) && (pTemp[0]!=' ') && (pTemp[0]!='\t')) pTemp++;
                if (pTemp[0]!=0) StepSize = atoi(pTemp);
            }
            GetVariable(szNext,&szLoop,&pDummy);
            if (!szLoop) {
                FatalError("/next without badly matching /for");
                return;
                }
                if (strstr(_strlwr(strcpy(szTemp,ForLine)),"downto")) {
                    Loop = atoi(strstr(szTemp,"downto")+7);
                DebugSpewNoFile("Next - End of loop %s downto %d", szLoop, Loop);
                itoa(atoi(szLoop)-StepSize,szLoop,10);
                if (atoi(szLoop) >= Loop) gMacroBlock = pMacroLine;
                } else {
                    Loop = atoi(strstr(szTemp,"to")+3);
                DebugSpewNoFile("Next - End of loop %s to %d", szLoop, Loop);
                itoa(atoi(szLoop)+StepSize,szLoop,10);
                if (atoi(szLoop) <= Loop) gMacroBlock = pMacroLine;
            }
            return;
        }
        pMacroLine = pMacroLine->pPrev;
    }

    FatalError("/next without matching /for");
}


#else
/* MQ2DataVars */
VOID Goto(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szTemp[MAX_STRING] = {0};
    PMACROBLOCK pFromLine = gMacroBlock;
    bRunNextCommand = TRUE;
    if (!gMacroBlock) {
        MacroError("Cannot goto when a macro isn't running.");
        return;
    }
    while (gMacroBlock->pPrev) {
        gMacroBlock=gMacroBlock->pPrev;
        if (!strnicmp(gMacroBlock->Line,"Sub ",4)) break;
    }

    while (gMacroBlock->pNext) {
        gMacroBlock=gMacroBlock->pNext;
        if (!strnicmp(gMacroBlock->Line,"Sub ",4)) {
			gMacroBlock=pFromLine;
            FatalError("Couldn't find label %s",szLine);
            return;
        }
        if (!stricmp(szLine,gMacroBlock->Line)) {
            DebugSpewNoFile("Goto - went to label %s",szLine);
            return;
        }
    }
    if (!stricmp(szLine,gMacroBlock->Line)) {
        DebugSpewNoFile("Goto - went to label %s",szLine);
        return;
    }
	gMacroBlock=pFromLine;
    FatalError("Couldn't find label %s",szLine);
}



VOID DumpStack(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szTemp[MAX_STRING] = {0};
    CHAR szSub[MAX_STRING] = {0};
    PMACROSTACK pMS = gMacroStack;
    while (pMS!=NULL) {
        sprintf(szTemp,"%s@%d (%s): %s",pMS->Location->SourceFile,pMS->Location->LineNumber, GetSubFromLine(pMS->Location,szSub), pMS->Location->Line);
        WriteChatColor(szTemp,USERCOLOR_DEFAULT);
        pMS=pMS->pNext;
    }
}

// ***************************************************************************
// Function:    EndMacro
// Description: Our '/endmacro' command
// Usage:       /endmacro
// ***************************************************************************
VOID EndMacro(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR Buffer[MAX_STRING] = {0};
    DWORD i;
    PMACROBLOCK pPrev;
    PMACROSTACK pStack;
    PEVENTSTACK pEvent;
    PEVENTLIST pEventL;
    BOOL bKeepKeys = gKeepKeys;
    if (szLine[0]!=0) {
        GetArg(Buffer,szLine,1);
        szLine = GetNextArg(szLine);
        if (stricmp(Buffer,"keep")) {
            SyntaxError("Usage: /endmacro [keep keys]");
            return;
        }
        while (szLine[0]!=0) {
            GetArg(Buffer,szLine,1);
            szLine = GetNextArg(szLine);
            if (!stricmp(Buffer,"keys")) bKeepKeys = TRUE;
        }
    }

    if (!gMacroBlock) {
        MacroError("Cannot end a macro when one isn't running.");
        return;
    }
    while (gMacroBlock->pNext) gMacroBlock=gMacroBlock->pNext;
    while (gMacroBlock) {
        pPrev = gMacroBlock->pPrev;
        free(gMacroBlock);
        gMacroBlock = pPrev;
    }
    while (gMacroStack) {
        pStack = gMacroStack->pNext;
        if (gMacroStack->LocalVariables) 
			ClearMQ2DataVariables(&gMacroStack->LocalVariables);
        if (gMacroStack->Parameters) 
			ClearMQ2DataVariables(&gMacroStack->Parameters);
        free(gMacroStack);
        gMacroStack = pStack;
    }
    while (gEventStack) {
        pEvent = gEventStack->pNext;
        free(gEventStack);
        gEventStack = pEvent;
    }
    while (pEventList) {
        pEventL = pEventList->pNext;
        free(pEventList);
        pEventList = pEventL;
    }
#ifdef USEBLECHEVENTS
	pEventBlech->Reset();
#endif
    for  (i=0;i<NUM_EVENTS;i++) {
        gEventFunc[i]=NULL;
    }

    gMacroPause = FALSE;
    gEventChat=0;
    gFaceAngle=10000.0f;
    gLookAngle=10000.0f;
    gDelay = 0;
    gTurbo = FALSE;
    pDoorTarget = NULL;
    gszMacroName[0]=0;
    gRunning = 0;

    if (!bKeepKeys) {
		KeyCombo TempCombo;
        for (i=0;gDiKeyID[i].szName[0];i++) 
		{
			TempCombo.Data[3]=(unsigned char)gDiKeyID[i].Id;
			MQ2HandleKeyUp(TempCombo);
        }
    }

    ClearMQ2DataVariables(&pMacroVariables);

    DebugSpewNoFile("EndMacro - Ended");
	if (gFilterMacro != FILTERMACRO_NONE)
	    WriteChatColor("The current macro has ended.",USERCOLOR_DEFAULT);
}


// ***************************************************************************
// Function:    Call
// Description: Our '/call' command
// Usage:       /call <Subroutine>
// ***************************************************************************
VOID Call(PSPAWNINFO pChar, PCHAR szLine)
{
    PMACROSTACK pStack;
    PMACROBLOCK pCallingPoint = gMacroBlock;
    CHAR SubName[MAX_STRING] = {0};
    PCHAR SubParam = NULL;
    CHAR SubLine[MAX_STRING] = {0};
    CHAR SubLineP[MAX_STRING] = {0};
    DWORD StackNum = 0;
    bRunNextCommand = TRUE;
    if (szLine[0]==0) {
        SyntaxError("Usage: /call <subroutine> [param [param...]]");
        return;
    }
    if (!gMacroBlock) {
        MacroError("Cannot call when a macro isn't running.");
        return;
    }
    while (gMacroBlock->pPrev) gMacroBlock = gMacroBlock->pPrev;

    GetArg(SubName,szLine,1);
    SubParam = GetNextArg(szLine);

        sprintf(SubLine,"sub %s",SubName);
    sprintf(SubLineP,"sub %s(",SubName);
    while (gMacroBlock->pNext) {
        if (!stricmp(gMacroBlock->Line,SubLine) || !strnicmp(gMacroBlock->Line,SubLineP,strlen(SubLineP))) {
            DebugSpewNoFile("Call - Calling subroutine %s with params %s",SubName,SubParam);
            pStack = (PMACROSTACK)malloc(sizeof(MACROSTACK));
            pStack->Location = gMacroBlock;
            pStack->Return[0] = 0;
            pStack->Parameters = NULL;
            pStack->LocalVariables = NULL;
            pStack->pNext = gMacroStack;
            gMacroStack = pStack;
        if (SubParam) 
		{
            StackNum = 0;
            while (SubParam[0]!=0) 
			{
				CHAR szParamName[MAX_STRING] = {0};
				CHAR szParamType[MAX_STRING] = {0};
				CHAR szNewValue[MAX_STRING]={0};
				GetArg(szNewValue,SubParam,1);


				GetFuncParam(gMacroBlock->Line,StackNum,szParamName,szParamType);
				MQ2Type *pType = FindMQ2DataType(szParamType);
				if (!pType)
					pType=pStringType;

				AddMQ2DataVariable(szParamName,"",pType,&gMacroStack->Parameters,szNewValue);
                SubParam = GetNextArg(SubParam);
                StackNum++;
            }
        }
        return;
    }
        gMacroBlock = gMacroBlock->pNext;
    }
	gMacroBlock=pCallingPoint;
    FatalError("Subroutine %s wasn't found",SubName);
}

VOID FailIf(PSPAWNINFO pChar, PCHAR szCommand, PMACROBLOCK pStartLine, BOOL All)
{
    DWORD Scope = 0;
    if (szCommand[strlen(szCommand)-1]=='{') {
		if (!gMacroBlock) {
	        DebugSpewNoFile("FailIf - Macro was ended before we could handle the false if command");
			return;
		}
        Scope++;
        gMacroBlock = gMacroBlock->pNext;
        while ((Scope>0)) {
            if (gMacroBlock->Line[0]=='}') Scope--;
            if (All) if (gMacroBlock->Line[strlen(gMacroBlock->Line)-1]=='{') Scope++;
            if (Scope>0) {
                if (!All) if (gMacroBlock->Line[strlen(gMacroBlock->Line)-1]=='{') Scope++;
                if (!strnicmp(gMacroBlock->Line,"sub ",4)) {
					gMacroBlock=pStartLine;
					FatalError("{} pairing ran into anther subroutine");
                    return;
                }
                if (!gMacroBlock->pNext) {
					gMacroBlock=pStartLine;
					FatalError("Bad {} block pairing");
                    return;
                }
                gMacroBlock = gMacroBlock->pNext;
            }
        }
        if ((!All) && (!strnicmp(gMacroBlock->Line,"} else ",7))) {
            DoCommand(pChar,gMacroBlock->Line+7);
        } else {
            bRunNextCommand = TRUE;
        }
    } else {
        bRunNextCommand = TRUE;
    }
}

VOID NewIf(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szCond[MAX_STRING] = {0};

	if (szLine[0]!='(')
	{
	    FatalError("Failed to parse /if command.  Expected () around conditions.");
	    SyntaxError("Usage: /if (<conditions>) <command>");
        return;
	}
	
	PCHAR pEnd=&szLine[1];
	DWORD nParens=1;
	while(1)
	{
		if (*pEnd=='(')
			nParens++;
		else if (*pEnd==')')
		{
			nParens--;
			if (nParens==0)
			{
				pEnd++;
				if (*pEnd!=' ')
				{
					FatalError("Failed to parse /if command.  Could not find command to execute.");
					SyntaxError("Usage: /if (<conditions>) <command>");
					return;
				}
				break;
			}
		}
		else if (*pEnd==0)
		{
			FatalError("Failed to parse /if command.  Could not find command to execute.");
			SyntaxError("Usage: /if (<conditions>) <command>");
			return;
		}
		++pEnd;
	}

	*pEnd=0;
	strcpy(szCond,szLine);
	*pEnd=' ';
	++pEnd;



	DOUBLE Result=0;
	if (!Calculate(szCond,Result))
	{
		FatalError("Failed to parse /if condition '%s', non-numeric encountered",szCond);
		return;
	}


	if (Result!=0)
		DoCommand(pChar,pEnd); 
	else
		FailIf(pChar,pEnd, gMacroBlock);
}




// ***************************************************************************
// Function:    DoEvents
// Description: Our '/doevents' command
// Usage:       /doevents [flush] [custom event]
// ***************************************************************************
VOID DoEvents(PSPAWNINFO pChar, PCHAR szLine)
{
    if (!gEventStack) return;
    if (!gMacroStack) return;

    DWORD sNum=0;
    CHAR sEvent[MAX_STRING]={0};
    PEVENTSTACK pEventNext = gEventStack->pNext;
    PEVENTSTACK pEventToRun = gEventStack;
    PEVENTSTACK *ppEventToRun = &gEventStack;
    PEVENTSTACK pEventPrev = NULL;
    PMACROSTACK pStack = NULL;
    PMACROBLOCK pMacro = NULL;
    CHAR SpecificEvent[MAX_STRING] = {0};
    BOOL Flush = FALSE;
    CHAR szTemp[MAX_STRING]= {0};
    DWORD NumEvents = 0;
    BOOL bCustomNum = FALSE;

    GetArg(szTemp,szLine,1);
    for (DWORD i=2;szTemp[0]!='\0';GetArg(szTemp,szLine,i++)) {
        if (szTemp[0]!='\0') {
            if (!stricmp(szTemp,"flush"))
                Flush=TRUE;
            else if (szTemp[0]>='0' && szTemp[0]<='9') {
                NumEvents=atoi(szTemp);
            } else
                sprintf(SpecificEvent,"Sub Event_%s",szTemp);
        }
    }
    if (stricmp(sEvent,SpecificEvent)) {
        strcpy(sEvent,SpecificEvent);
        sNum=NumEvents;
    }

    if (NumEvents)
        bCustomNum = TRUE;
    DebugSpewNoFile("DoEvents: Parms = '%s' Flush = %d -- SpecificEvent = %s -- NumEvents = %d",szLine,Flush,SpecificEvent,NumEvents);
    if (Flush) {
        if (SpecificEvent[0]=='\0') {
            while (gEventStack) {
                pEventNext = gEventStack->pNext;
				ClearMQ2DataVariables(&gEventStack->Parameters);
                free(gEventStack);
                gEventStack = pEventNext;
            }
        } else {
            PEVENTSTACK pPrev=NULL;
            while (pEventToRun) {
                pEventNext = pEventToRun->pNext;
                DebugSpewNoFile("DoEvents.FlushSpecific: checking '%d\\%s' against '%s'",pEventToRun->Type,(pEventToRun->pEventList)?pEventToRun->pEventList->szName:"NULL",SpecificEvent);
                if (
                    ((pEventToRun->Type == EVENT_CHAT) && (!stricmp("Sub Event_Chat",SpecificEvent))) ||
                    ((pEventToRun->Type == EVENT_TIMER) && (!stricmp("Sub Event_Timer",SpecificEvent))) ||
                    ((pEventToRun->Type == EVENT_CUSTOM) && (!stricmp(pEventToRun->pEventList->szName,SpecificEvent)))
                    ) {
                    DebugSpewNoFile("DoEvents.FlushSpecific: found one");
                    PEVENTSTACK pThis=pEventToRun;
                    pEventToRun = pPrev->pNext = pThis->pNext;
					ClearMQ2DataVariables(&pThis->Parameters);
                    free(pThis);
                } else {
                    pPrev = pEventToRun;
                    pEventToRun = pEventToRun->pNext;
                }
            }
        }
        bRunNextCommand = TRUE;
        return;
    }
    BOOL Found = FALSE;
    if (SpecificEvent[0]) {
        DebugSpewNoFile("NumEvents: %d sNum: %d",NumEvents,sNum);
        if ((NumEvents && sNum) || (!NumEvents && !sNum)) {
            while (pEventToRun && !Found) {
                pEventNext = pEventToRun->pNext;
                DebugSpewNoFile("DoEvents.SpecificEvent: checking '%d\\%s' against '%s'",pEventToRun->Type,(pEventToRun->pEventList)?pEventToRun->pEventList->szName:"NULL",SpecificEvent);
                if (
                    ((pEventToRun->Type == EVENT_CHAT) && (!stricmp("Sub Event_Chat",SpecificEvent))) ||
                    ((pEventToRun->Type == EVENT_TIMER) && (!stricmp("Sub Event_Timer",SpecificEvent))) ||
                    ((pEventToRun->Type == EVENT_CUSTOM) && (!stricmp(pEventToRun->pEventList->szName,SpecificEvent)))
                ) {
                    DebugSpewNoFile("DoEvents.SpecificEvent: found one");
                    Found = TRUE;
                    if (sNum) sNum--;
                } else {
                    ppEventToRun = &pEventToRun->pNext;
                    pEventToRun = pEventToRun->pNext;
                }
            }
        }
    }
    if (!pEventToRun || (SpecificEvent[0] && !Found)) return;
    DebugSpewNoFile("DoEvents: Running event %d\\%s = 0x%p",pEventToRun->Type,(pEventToRun->pEventList)?pEventToRun->pEventList->szName:"NULL",pEventToRun);

    pStack = (PMACROSTACK)malloc(sizeof(MACROSTACK));
    gMacroStack->Location = gMacroStack->Location->pPrev;
    pStack->Location = gMacroBlock;
    pStack->Return[0] = 0;
    pStack->Parameters = pEventToRun->Parameters;
    pStack->LocalVariables = NULL;
    pStack->pNext = gMacroStack;
    gMacroStack = pStack;
    if (pEventToRun->Type == EVENT_CUSTOM) {
        gMacroBlock = pEventToRun->pEventList->pEventFunc;
    } else {
        gMacroBlock = gEventFunc[pEventToRun->Type];
    }
    DebugSpewNoFile("DoEvents - Called event: %s",gMacroBlock->Line);
    free(pEventToRun);
    *ppEventToRun = pEventNext;
    bRunNextCommand = FALSE;
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
    if (!gMacroBlock) {
        MacroError("Cannot return when a macro isn't running.");
        return;
    }
    if ((!pStack) || (!pStack->pNext)) {
        // Top of stack (ie. returning from Sub Main)
        EndMacro(pChar,"");
        return;
    }

    strcpy(pStack->pNext->Return,szLine);
    gMacroBlock = pStack->pNext->Location;
    gMacroStack = pStack->pNext;
    if (pStack->LocalVariables) 
		ClearMQ2DataVariables(&pStack->LocalVariables);
    if (pStack->Parameters) 
		ClearMQ2DataVariables(&pStack->Parameters);
    free(pStack);
    DebugSpewNoFile("Return - Returned to %s",gMacroBlock->Line);

}





// ***************************************************************************
// Function:    For
// Description: Our '/for' command
// Usage:       /for v# <start> <to|downto> <end>
// ***************************************************************************
VOID For(PSPAWNINFO pChar, PCHAR szLine)
{
    bRunNextCommand = TRUE;
    CHAR ArgLoop[MAX_STRING] = {0};
    CHAR ArgStart[MAX_STRING] = {0};
    CHAR ArgDirection[MAX_STRING] = {0};
    CHAR ArgEnd[MAX_STRING] = {0};

    GetArg(ArgLoop,szLine,1);
    GetArg(ArgStart,szLine,2);
    GetArg(ArgDirection,szLine,3);
    GetArg(ArgEnd,szLine,4);
    _strlwr(ArgDirection);

	PDATAVAR pVar = FindMQ2DataVariable(ArgLoop);
	if (!pVar)
	{
        FatalError("/for loop using invalid variable");
        return;
	}
	if (pVar->Var.Type!=pIntType)
	{
        FatalError("/for loops must use an int variable");
        return;
	}
    if ((ArgStart[0] == 0) || (ArgDirection[0] == 0) || (ArgEnd[0] == 0) || ((strcmp(ArgDirection,"to")) && (strcmp(ArgDirection,"downto")))) {
        FatalError("Usage: /for <variable> <start> <to|downto> <end> [step x]");
        return;
    }
    if (!gMacroBlock) {
        MacroError("Can only use /for during a macro.");
        return;
    }

	if (!pVar->Var.Type->FromString(pVar->Var.VarPtr,ArgStart))
	{
        FatalError("/for loop could not assign value '%s' to variable",ArgStart);
        return;
	}

}

// ***************************************************************************
// Function:    Next
// Description: Our '/next' command
// Usage:       /next v#
// ***************************************************************************
VOID Next(PSPAWNINFO pChar, PCHAR szLine)
{
    bRunNextCommand = TRUE;
    CHAR szComp[MAX_STRING] = {0};
    CHAR ForLine[MAX_STRING] = {0};
    CHAR szNext[MAX_STRING] = {0};
    PMACROBLOCK pMacroLine = gMacroBlock;
    LONG StepSize = 1;
    GetArg(szNext,szLine,1);

	PDATAVAR pVar = FindMQ2DataVariable(szNext);
	if (!pVar)
	{
        FatalError("/next using invalid variable");
        return;
	}
	if (pVar->Var.Type!=pIntType)
	{
        FatalError("/for loops must use an int variable");
        return;
	}

    if (!gMacroBlock) {
        MacroError("Can only use /next during a macro.");
        return;
    }
    sprintf(szComp,"/for %s",pVar->szName);
    while (pMacroLine->pPrev) {
        strcpy(ForLine,pMacroLine->Line);
        if (!strnicmp(ForLine,"Sub ",4)) {
            FatalError("/next without matching /for");
            return;
        }
        if (strnicmp(ForLine,"/for ",5)) {
			pMacroLine = pMacroLine->pPrev;
            continue;
        }
        if (!strnicmp(ParseMacroParameter(pChar,ForLine),szComp,strlen(szComp))) {
			if (!gMacroBlock) {
				// PMP bailed on us, we need to exit...
				return;
			}
            CHAR szTemp[MAX_STRING] = {0};
            DWORD VarNum = atoi(szLine+1);
            LONG Loop;
            if (strstr(_strlwr(strcpy(szTemp,ForLine)),"step")) {
                PCHAR pTemp = strstr(szTemp,"step")+4;
                while ( (pTemp[0]!=0) && (pTemp[0]!=' ') && (pTemp[0]!='\t')) pTemp++;
                if (pTemp[0]!=0) StepSize = atoi(pTemp);
            }

			pVar = FindMQ2DataVariable(szNext);
			if (!pVar)
			{
				FatalError("/next without badly matching /for");
				return;
			}

            if (strstr(_strlwr(strcpy(szTemp,ForLine)),"downto")) 
			{
                Loop = atoi(strstr(szTemp,"downto")+7);
				DebugSpewNoFile("Next - End of loop %d downto %d", pVar->Var.Int, Loop);
				pVar->Var.Int-=StepSize;
				if (pVar->Var.Int >= Loop) 
					gMacroBlock = pMacroLine;
            } 
			else 
			{
                Loop = atoi(strstr(szTemp,"to")+3);
				DebugSpewNoFile("Next - End of loop %d to %d", pVar->Var.Int, Loop);
				pVar->Var.Int+=StepSize;
				if (pVar->Var.Int <= Loop) 
					gMacroBlock = pMacroLine;
			}
            return;
        }
        pMacroLine = pMacroLine->pPrev;
    }

    FatalError("/next without matching /for");
}


PCHAR GetFuncParam(PCHAR szMacroLine, DWORD ParamNum, PCHAR szParamName, PCHAR szParamType)
{
	szParamName[0]=0;
	szParamType[0]=0;
    if (strnicmp(szMacroLine,"sub ",4)) 
		return NULL;
    PCHAR szSubParamNamePointer = szMacroLine+4;
    while ((szSubParamNamePointer[0]!='(') && (szSubParamNamePointer[0]!=0)) 
	{
		szSubParamNamePointer++;
	}
    if (szSubParamNamePointer[0]=='(') 
		szSubParamNamePointer++;
    if (szSubParamNamePointer[0]!=0) 
	{
		CHAR Temp[MAX_STRING]={0};
        GetArg(Temp,szSubParamNamePointer,ParamNum+1,TRUE,TRUE,TRUE,',');
        if (Temp[strlen(Temp)-1]==')') 
			Temp[strlen(Temp)-1]=0;
		if (PCHAR pSpace=strchr(Temp,' '))
		{
			*pSpace=0;
			strcpy(szParamType,Temp);
			strcpy(szParamName,&pSpace[1]);
		}
		else
		{
			strcpy(szParamName,Temp);
		}
    }
	if (szParamType[0]==0)
		strcpy(szParamType,"string");
    if (szParamName[0]==0) 
		sprintf(szParamName,"Param%d",ParamNum);
    return szParamName;
}

#endif