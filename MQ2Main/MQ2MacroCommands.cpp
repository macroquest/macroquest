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
#define MAXTURBO 120

#ifdef ISXEQ_LEGACY
#include "../ISXEQLegacy/ISXEQLegacy.h"
#else
#include "MQ2Main.h"
#endif

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
    if ((pStart && !*pStart) || (pEnd && !*pEnd))
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
    char *tmp;
    if (!fMacro) {
        FatalError("Couldn't open include file: %s",szFile);
        return 0;
    }
    DebugSpewNoFile("Include - Including: %s",szFile);
    while (!feof(fMacro)) {

        tmp = fgets(szTemp,MAX_STRING,fMacro);

        if (!tmp && feof(fMacro)) break;

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
            else if (gMaxTurbo>MAXTURBO) 
            {
                MacroError("#turbo %d is too high, setting at %d (maximum)",gMaxTurbo, MAXTURBO);
                gMaxTurbo=MAXTURBO;
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
            if (!_stricmp(szLine,"say"))   gEventChat = gEventChat | CHAT_SAY;
            if (!_stricmp(szLine,"tell"))  gEventChat = gEventChat | CHAT_TELL;
            if (!_stricmp(szLine,"ooc"))   gEventChat = gEventChat | CHAT_OOC;
            if (!_stricmp(szLine,"shout")) gEventChat = gEventChat | CHAT_SHOUT;
            if (!_stricmp(szLine,"auc"))   gEventChat = gEventChat | CHAT_AUC;
            if (!_stricmp(szLine,"guild")) gEventChat = gEventChat | CHAT_GUILD;
            if (!_stricmp(szLine,"group")) gEventChat = gEventChat | CHAT_GROUP;
            if (!_stricmp(szLine,"chat"))  gEventChat = gEventChat | CHAT_CHAT;
        } else if (szLine[1]=='!') {
            // Like: #!/usr/local/bin/LegacyMQ2
            // ignore.
        } else {
            MacroError("Unknown # command: %s",szLine);
            return FALSE;
        }
    }

    pBlock = (PMACROBLOCK)calloc(1,sizeof(MACROBLOCK));
    if (!pBlock) return NULL;
    //DebugSpewNoFile("AddMacroLine - Adding: %s",szLine);
    strcpy(pBlock->Line,szLine);
    pBlock->LineNumber = -1;
    pBlock->SourceFile[0]='\0';
    pBlock->pNext=NULL;
    pBlock->pPrev=NULL;

    if ((!_stricmp(szLine,"Sub Event_Chat")) || (!strnicmp(szLine,"Sub Event_Chat(",15))) {
        gEventFunc[EVENT_CHAT] = pBlock;
    } else if ((!_stricmp(szLine,"Sub Event_Timer")) || (!strnicmp(szLine,"Sub Event_Timer(",16))) {
        gEventFunc[EVENT_TIMER] = pBlock;
    } else {
        PEVENTLIST pEvent = pEventList;
        while (pEvent) {
            if (!_stricmp(szLine,pEvent->szName)) {
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
        while (pLoop->pNext)
			pLoop = pLoop->pNext;
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
    if (gMacroBlock) 
    {
        gReturn = false;
        EndMacro(pChar,"");//"keep keys vars arrays timers");
        gReturn = true;
    }
    gMaxTurbo=20;
    gTurbo=true;
    GetArg(szTemp,szLine,1);
    Params = GetNextArg(szLine);

    strcpy(gszMacroName,szTemp);
#ifdef ISXEQ_LEGACY
    strcpy(Filename,szTemp);
    FILE *fMacro = fopen(szTemp,"rt");
#else
    if (!strstr(szTemp,".")) strcat(szTemp,".mac");
    sprintf(Filename,"%s\\%s",gszMacroPath, szTemp);

    FILE *fMacro = fopen(Filename,"rt");
#endif
    if (!fMacro) {
        FatalError("Couldn't open macro file: %s",Filename);
        gszMacroName[0]=0;
        gRunning = 0;
        return;
    }
    gRunning = MQGetTickCount64();
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
    if (gMacroBlock) gMacroBlock->MacroCmd = 1;
    if ((!gMacroBlock) || (!gMacroStack)) {
        gszMacroName[0]=0;
        gRunning = 0;
    }
#ifdef ISXEQ_LEGACY
    else
    {
        char ShortName[128];
        ShortName[0]=0;
        _splitpath(Filename,0,0,ShortName,0);
        IS_ScriptEngineScriptBegins(pExtension,pISInterface,hScriptEngineService,&g_LegacyEngine,ShortName);
    }
#endif
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
    ParseKeyCombo("Esc",Escape);
    if(ppContainerMgr && pContainerMgr) {
        PEQ_CONTAINERWND_MANAGER ContainerMgr = (PEQ_CONTAINERWND_MANAGER)pContainerMgr;
        DWORD concount=2; //Close inv + clear target
        if (ContainerMgr->pWorldContents && ContainerMgr->pWorldContents->Open==1) concount++;
        for (i=0;i<25;i++) {
            if (ContainerMgr->pPCContainers[i] && ContainerMgr->pPCContainers[i]->Wnd.dShow==1) concount++;
        }
        for (i=0;i<concount;i++) 
        {
            MQ2HandleKeyDown(Escape);
            MQ2HandleKeyUp(Escape);
        }
        if (!ppInventoryWnd) {
            PCSIDLWND pInvWindow = (PCSIDLWND)pInventoryWnd;
            if (pInvWindow && pInvWindow->dShow==0) 
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
// Usage:       /delay <time> [condition to end early]
// ***************************************************************************
VOID Delay(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szVal[MAX_STRING] = {0};
    LONG VarValue;

    if (szLine[0]==0) {
        SyntaxError("Usage: /delay <time> [condition to end early]");
        return;
    }
    GetArg(szVal,szLine,1);
    ParseMacroParameter(GetCharInfo()->pSpawn,szVal);
    strcpy(gDelayCondition,GetNextArg(szLine));
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
    bRunNextCommand=false;
    //    DebugSpewNoFile("Delay - %d",gDelay);
}

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
    while (gMacroBlock->pPrev) 
    {
        gMacroBlock=gMacroBlock->pPrev;
        if (!strnicmp(gMacroBlock->Line,"Sub ",4))
			break;
    }

    while (gMacroBlock->pNext) 
    {
        gMacroBlock=gMacroBlock->pNext;
        if (!strnicmp(gMacroBlock->Line,"Sub ",4)) 
        {
            gMacroBlock=pFromLine;
            FatalError("Couldn't find label %s",szLine);
            return;
        }
        if (!_stricmp(szLine,gMacroBlock->Line)) 
        {
            //            DebugSpewNoFile("Goto - went to label %s",szLine);
            return;
        }
    }

    if (!_stricmp(szLine,gMacroBlock->Line)) 
    {
        //        DebugSpewNoFile("Goto - went to label %s",szLine);
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
        if (bAllErrorsLog) MacroLog(NULL, szTemp);
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
    PEVENTQUEUE pEvent;
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
            if (!_stricmp(Buffer,"keys")) bKeepKeys = TRUE;
        }
    }

    if (!gMacroBlock) {
        MacroError("Cannot end a macro when one isn't running.");
        return;
    }

    /////////////// 
    // Code allowing for a routine for "OnExit"
    while (gMacroBlock->pNext) 
    {
        gMacroBlock=gMacroBlock->pNext;
        //DebugSpew("%s",gMacroBlock->Line);
        if (!_stricmp(":OnExit",gMacroBlock->Line)) 
        {
            if (gReturn)            // return to the macro the first time around
            {
                gReturn = false;    // We don't want to return the 2nd time.
                return;
            }
            else
                break;
        }
    }
    gReturn = true;            // reset for next time
    //
    ///////////////

#ifdef MQ2_PROFILING
    // How many performance counters in 1 second?
    LARGE_INTEGER PerformanceFrequency;
    QueryPerformanceCounter(&PerformanceFrequency);

    // Move to first macro line
    while (gMacroBlock->pPrev) gMacroBlock = gMacroBlock->pPrev;

    CHAR Filename[MAX_STRING] = {0};
    FILE *fMacro = NULL;
    while (gMacroBlock) {
        // Is this a different macro file?
        if (strcmp(Filename, gMacroBlock->SourceFile)) {
            // Close existing file
            if (fMacro) {
                fclose(fMacro);
            }
            // Open new profiling log file
            strcpy(Filename, gMacroBlock->SourceFile);
            sprintf(Buffer, "%s\\%s.mqp", gszMacroPath, Filename);
            fMacro = fopen(Buffer, "w");
            if (fMacro) {
                fprintf(fMacro, " Execute |  Total   | Avg uSec | Line | Macro Source Code\n");
                fprintf(fMacro, " Count   |   uSec   | Per 1000 |\n");
                fprintf(fMacro, "------------------------------------------------------------------------------------------------------------- \n");
            }
        }

        // Log execution/profiling information.  Output format is:
        // Execution Count | Microseconds | Line # | Macro Source
        if (fMacro) {
            DWORD count = gMacroBlock->ExecutionCount;
            DWORD total = (DWORD)(gMacroBlock->ExecutionTime * 1000000 / PerformanceFrequency.QuadPart);
            DWORD avg = 0;
            if (count > 0) {
                avg = total * 1000 / count;
            }
            fprintf(fMacro, "%8lu | %8lu | %8lu | %4lu | %s\n",
                count,
                total,
                avg,
                gMacroBlock->LineNumber,
                gMacroBlock->Line);
        }

        // Terminate on last macro line
        if (gMacroBlock->pNext) {
            gMacroBlock = gMacroBlock->pNext;
        } else {
            break;
        }
    }
    // Close existing file
    if (fMacro) {
        fclose(fMacro);
    }
#endif

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
    gMacroSubLookupMap.clear(); 
    while (gEventQueue) {
        pEvent = gEventQueue->pNext;
        free(gEventQueue);
        gEventQueue = pEvent;
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
#ifdef ISXEQ_LEGACY
    char ShortName[128];
    ShortName[0]=0;
    _splitpath(gszMacroName,0,0,ShortName,0);
    IS_ScriptEngineScriptEnds(pExtension,pISInterface,hScriptEngineService,&g_LegacyEngine,ShortName);
#endif

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
    if (gFilterMacro != FILTERMACRO_NONE && gFilterMacro != FILTERMACRO_MACROENDED)
        WriteChatColor("The current macro has ended.",USERCOLOR_DEFAULT);
}


// ***************************************************************************
// Function:    Call
// Description: Our '/call' command
// Usage:       /call <Subroutine>
// ***************************************************************************
VOID Call(PSPAWNINFO pChar, PCHAR szLine)
{
    PMACROSTACK pStack = 0;
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

    GetArg(SubName,szLine,1);
    SubParam = GetNextArg(szLine);

    sprintf(SubLine,"sub %s",SubName);
    sprintf(SubLineP,"sub %s(",SubName);

    // Sub in Map?
    PMACROBLOCK pSubBlock = gMacroSubLookupMap[SubName];

    // If not, find it and add.
    if (!pSubBlock) {
        while (gMacroBlock->pPrev) gMacroBlock = gMacroBlock->pPrev;
        while (gMacroBlock->pNext) {
            if (!_stricmp(gMacroBlock->Line,SubLine) || !strnicmp(gMacroBlock->Line,SubLineP,strlen(SubLineP))) {
                pSubBlock = gMacroBlock;
                break;
            }
            gMacroBlock = gMacroBlock->pNext;
        }
        if (!pSubBlock) {
            gMacroBlock=pCallingPoint;
            FatalError("Subroutine %s wasn't found",SubName);
            return;
        } else {
            gMacroSubLookupMap[SubName] = pSubBlock;
        }
    }

    // Prep to call the Sub
    gMacroBlock = pSubBlock;

	if(SubName && SubName[0]!='\0' && SubParam && SubParam[0]!='\0') {
		DebugSpewNoFile("Call - Calling subroutine %s with params %s",SubName,SubParam);
	} else {
		DebugSpewNoFile("Call - SubName and SubParam was empty");
	}
    pStack = (PMACROSTACK)calloc(1,sizeof(MACROSTACK));
	if( pStack == NULL ) {
		MacroError("Failed to allocate pStack for /call");
        return;
	}
    pStack->Location = gMacroBlock;
    pStack->Return[0] = '\0';
    pStack->Parameters = NULL;
    pStack->LocalVariables = NULL;
    pStack->pNext = gMacroStack;
    gMacroStack = pStack;
    if (SubParam) {
        StackNum = 0;
        while (SubParam[0]!=0) {
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

/*
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
        if (!_stricmp(gMacroBlock->Line,SubLine) || !strnicmp(gMacroBlock->Line,SubLineP,strlen(SubLineP))) {
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
/**/

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
        } else if ((!All) && (!strnicmp(gMacroBlock->Line,"} else",6))) {
            FatalError("} else lacks command or {");
            return;
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

VOID ContinueWhile(PSPAWNINFO pChar, PMACROBLOCK pStartLine)
{
   if (!gMacroBlock) {
      DebugSpewNoFile("ContinueWhile - Macro was ended before we could handle the end of while command");
      return;
   }

   while (1)
   {
      if (!strnicmp(gMacroBlock->Line,"sub ",4))
      {
         gMacroBlock=pStartLine;
         FatalError("/while ran into another subroutine");
            return;
      }
      if (!gMacroBlock->pPrev)
      {
         gMacroBlock=pStartLine;
         FatalError("/while without an end");
            return;
      }
      if (!strnicmp(gMacroBlock->Line,"/while",6))
      {
         gMacroBlock = gMacroBlock->pPrev;
         break;
      }
      gMacroBlock = gMacroBlock->pPrev;
   }
}
VOID EndWhile(PSPAWNINFO pChar, PCHAR szCommand, PMACROBLOCK pStartLine, BOOL All=0)
{
    DWORD Scope = 0;
    if (szCommand[strlen(szCommand)-1]=='{') {
        if (!gMacroBlock) {
            DebugSpewNoFile("EndWhile - Macro was ended before we could handle the false while command");
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
    } else {
		gMacroBlock = gMacroBlock->pNext;
        bRunNextCommand = TRUE;
    }
}
VOID MarkWhile(PSPAWNINFO pChar, PCHAR szCommand, BOOL All=0)
{
	PMACROBLOCK pSaveLine = gMacroBlock;
	BOOL bDelay = 0;
    DWORD Scope = 0;
    if (szCommand[strlen(szCommand)-1]=='{') {
        if (!gMacroBlock) {
            DebugSpewNoFile("MarkWhile - Macro was ended before we could handle the command");
            return;
        }
        Scope++;
        gMacroBlock = gMacroBlock->pNext;
        while ((Scope>0)) {
            if (gMacroBlock->Line[0]=='}') {
				Scope--;
			}
            if (All) {
				if (gMacroBlock->Line[strlen(gMacroBlock->Line)-1]=='{') {
					Scope++;
				}
			}
            if (Scope>0) {
                if (!All) {
					if (gMacroBlock->Line[strlen(gMacroBlock->Line)-1]=='{') {
						Scope++;
					}
				}
                if (!strnicmp(gMacroBlock->Line,"sub ",4)) {
                    gMacroBlock=pSaveLine;
                    FatalError("{} pairing ran into anther subroutine");
                    return;
                }
                if (!gMacroBlock->pNext) {
                    gMacroBlock=pSaveLine;
                    FatalError("Bad {} block pairing");
                    return;
                }
                gMacroBlock = gMacroBlock->pNext;
            }
        }
    } else {
		//its a /while (something) /dosomething
		//but we know, that unless that /dosomething is a /delay ... we WILL fail them...
		Sleep(0);
    }
	gMacroBlock->LoopLine = pSaveLine->LineNumber;
	gMacroBlock = pSaveLine;
}
//yes this is going to work, i just need some more time testing it -eqmule
VOID WhileCmd(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szCond[MAX_STRING] = {0};

    if (szLine[0]!='(')
    {
        FatalError("Failed to parse /while command.  Expected () around conditions.");
        SyntaxError("Usage: /while (<conditions>) <command>");
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
                    FatalError("Failed to parse /while command.  Could not find command to execute.");
                    SyntaxError("Usage: /while (<conditions>) <command>");
                    return;
                }
                break;
            }
        }
        else if (*pEnd==0)
        {
            FatalError("Failed to parse /while command.  Could not find command to execute.");
            SyntaxError("Usage: /while (<conditions>) <command>");
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
        FatalError("Failed to parse /while condition '%s', non-numeric encountered",szCond);
        return;
    }

	//ok so we have a loop...
	//lets check all the lines within it
	//and mark the end so the interpreter knows when to exit it
	MarkWhile(pChar,pEnd);
	
	
    if (Result!=0)
        DoCommand(pChar,pEnd); 
    else 
		EndWhile(pChar,pEnd, gMacroBlock);
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

    CHAR Arg1[MAX_STRING]={0};
    CHAR Arg2[MAX_STRING]={0};

    GetArg(Arg1,szLine,1);

    if (!_stricmp(Arg1,"flush"))
    {
        GetArg(Arg2,szLine,2);
        if (Arg2[0])
        {
            sprintf(Arg1,"Sub Event_%s",Arg2);
            PEVENTQUEUE pEvent=gEventQueue;
            while (pEvent) 
            {
                if (
                    (pEvent->Type == EVENT_CHAT && !_stricmp("Sub Event_Chat",Arg1)) ||
                    (pEvent->Type == EVENT_TIMER && !_stricmp("Sub Event_Timer",Arg1)) ||
                    (pEvent->Type == EVENT_CUSTOM && !_stricmp(pEvent->pEventList->szName,Arg1))
                    ) 
                {
                    PEVENTQUEUE pEventNext;
                    if (pEventNext = pEvent->pNext)
                        pEventNext->pPrev=pEvent->pPrev;
                    if (pEvent->pPrev)
                        pEvent->pPrev->pNext=pEvent->pNext;
                    else
                        gEventQueue=pEvent->pNext;
                    ClearMQ2DataVariables(&pEvent->Parameters);
                    free(pEvent);
                    pEvent=pEventNext;
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
                free(gEventQueue);
                gEventQueue = pEventNext;
            }
        }
        return;
    }
    PEVENTQUEUE pEvent=gEventQueue;
    if (Arg1[0])
    {
        sprintf(Arg2,"Sub Event_%s",Arg1);
        while(pEvent)
        {
            if (
                (pEvent->Type == EVENT_CHAT && !_stricmp("Sub Event_Chat",Arg2)) ||
                (pEvent->Type == EVENT_TIMER && !_stricmp("Sub Event_Timer",Arg2)) ||
                (pEvent->Type == EVENT_CUSTOM && !_stricmp(pEvent->pEventList->szName,Arg2))
                ) 
            {
                break;
            }
            pEvent=pEvent->pNext;
        }
        if (!pEvent)
            return;// no event found
    }

    if (pEvent->pPrev)
        pEvent->pPrev->pNext=pEvent->pNext;
    else
        gEventQueue=pEvent->pNext;
    if (pEvent->pNext)
        pEvent->pNext->pPrev=pEvent->pPrev;

    DebugSpewNoFile("DoEvents: Running event type %d (%s) = 0x%p",pEvent->Type,(pEvent->pEventList)?pEvent->pEventList->szName:"NONE",pEvent);

    if(PMACROSTACK pStack = (PMACROSTACK)malloc(sizeof(MACROSTACK))) {

		// back the current location to previous one so we fall into
		// /doevents again.  This screams for optimization!

		gMacroStack->Location = gMacroStack->Location->pPrev;
		pStack->Location = gMacroBlock;
		pStack->Return[0] = 0;
		pStack->Parameters = pEvent->Parameters;
		PDATAVAR pParam=pStack->Parameters;
		while(pParam) // FIX THE HEAD ON EVERY VAR WE MOVED
		{
			pParam->ppHead=&pStack->Parameters;
			pParam=pParam->pNext;
		}
		pStack->LocalVariables = NULL;
		pStack->pNext = gMacroStack;
		gMacroStack = pStack;
		if (pEvent->Type == EVENT_CUSTOM && pEvent->pEventList)
		{
			gMacroBlock = pEvent->pEventList->pEventFunc;
		}
		else 
		{
			gMacroBlock = gEventFunc[pEvent->Type];
		}
		DebugSpewNoFile("DoEvents - Called event: %s",gMacroBlock->Line);
		free(pEvent);
		bRunNextCommand = FALSE;
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
        EndMacro(pChar,"");
        return;
    }
    if (pStack->LocalVariables) 
        ClearMQ2DataVariables(&pStack->LocalVariables);
    if (pStack->Parameters) 
        ClearMQ2DataVariables(&pStack->Parameters);

    strcpy(pStack->pNext->Return,szLine);
    gMacroBlock = pStack->pNext->Location;
    gMacroStack = pStack->pNext;
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
	char *pDest = 0;
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
    sprintf(szComp,"/for %s ",pVar->szName);
    while (pMacroLine->pPrev) {
        strcpy(ForLine,pMacroLine->Line);
        if (!strnicmp(ForLine,"sub ",4)) {
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
            LONG Loop = 0;
            if (strstr(_strlwr(strcpy(szTemp,ForLine)),"step")) {
                if(PCHAR pTemp = strstr(szTemp,"step")+4) {
					while ( (pTemp[0]!=0) && (pTemp[0]!=' ') && (pTemp[0]!='\t'))
						pTemp++;
					if (pTemp[0]!=0)
						StepSize = atoi(pTemp);
				}
            }

            pVar = FindMQ2DataVariable(szNext);
            if (!pVar)
            {
                FatalError("/next without badly matching /for");
                return;
            }

            if (strstr(_strlwr(strcpy(szTemp,ForLine)),"downto"))
            {
				if(pDest = strstr(szTemp,"downto"))
					Loop = atoi(pDest + 7);
                //DebugSpewNoFile("Next - End of loop %d downto %d", pVar->Var.Int, Loop);
                pVar->Var.Int-=StepSize;
                if (pVar->Var.Int >= Loop) 
                    gMacroBlock = pMacroLine;
            } 
            else 
            {
				if(pDest = strstr(szTemp, "to"))
					Loop = atoi(pDest + 3);
                //DebugSpewNoFile("Next - End of loop %d to %d", pVar->Var.Int, Loop);
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

   while (bRunNextCommand == TRUE) //FIX?
   {   
      if (!strnicmp(gMacroBlock->Line,"Sub ",4) || (!gMacroBlock->pNext))
      {
         FatalError("/continue without matching /for ... /next block");
         return;
      } 
	  if (!strnicmp(gMacroBlock->Line,"/next",5))
      {
         gMacroBlock = gMacroBlock->pPrev;         
         break;
      }
      gMacroBlock = gMacroBlock->pNext;
   }
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

   while (bRunNextCommand == TRUE) //FIX?
   {   
      if (!strnicmp(gMacroBlock->Line,"Sub ",4) || (!gMacroBlock->pNext))
      {
         FatalError("/break without matching /for ... /next block");
         return;
      } 
	  if (!strnicmp(gMacroBlock->Line,"/next",5))
      {
         break;
      }
      gMacroBlock = gMacroBlock->pNext;
   }
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
        DebugSpew("GetFuncParam(%d): '%s'",ParamNum+1,Temp);
        if (*Temp && Temp[strlen(Temp)-1]==')') 
            Temp[strlen(Temp)-1]=0;
        PCHAR pStart=&Temp[0];
        while(*pStart==' ') 
            ++pStart;
        if (pStart!=&Temp[0])
            memmove(Temp,pStart,MAX_STRING-1);
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
