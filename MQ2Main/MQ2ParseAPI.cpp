/*****************************************************************************
    eqlib.dll: MacroQuest's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic

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

typedef struct _PARM {
	CHAR szName[128];
	DWORD Length;
	fMQParm Function;
	struct _PARM* pLast;
	struct _PARM* pNext;
} PARM, *PPARM;

PPARM pParmList=0;

VOID AddParm(PCHAR Name, fMQParm Function)
{
	// perform insertion sort
	if (!Name || Name[0]==0 || !Function)
		return;

	DWORD NameLen=strlen(Name);
	if (!pParmList)
	{
		PPARM pParm=new PARM;
		memset(pParm,0,sizeof(PARM));
		strcpy(pParm->szName,Name);
		pParm->Length=NameLen;
		pParm->Function=Function;
		pParmList=pParm;
		return;
	}
	PPARM pInsert=pParmList;
	PPARM pLast=0;
	while(pInsert)
	{
		if (NameLen>strlen(pInsert->szName))
		{
			// insert here.
			PPARM pParm=new PARM;
			memset(pParm,0,sizeof(PARM));
			strcpy(pParm->szName,Name);
			pParm->Length=NameLen;
			pParm->Function=Function;
			if (pLast)
				pLast->pNext=pParm;
			else
				pParmList=pParm;
			pParm->pLast=pLast;
			pInsert->pLast=pParm;
			pParm->pNext=pInsert;
			return;
		}
		if (!stricmp(pInsert->szName,Name))
		{
			strcpy(pInsert->szName,Name);
			pInsert->Length=NameLen;
			pInsert->Function=Function;
			return;
		}
		pLast=pInsert;
		pInsert=pInsert->pNext;
	}
	// End of list
	PPARM pParm=new PARM;
	memset(pParm,0,sizeof(PARM));
	pParm->Length=NameLen;
	strcpy(pParm->szName,Name);
	pParm->Function=Function;
	pLast->pNext=pParm;
	pParm->pLast=pLast;
}

VOID RemoveParm(PCHAR Name)
{
	PPARM pParm=pParmList;
	while(pParm)
	{
		if (!stricmp(Name,pParm->szName))
		{
			if (pParm->pNext)
				pParm->pNext->pLast=pParm->pLast;
			if (pParm->pLast)
				pParm->pLast->pNext=pParm->pNext;
			else
				pParmList=pParm->pNext;
			delete pParm;
			return;
		}
		pParm=pParm->pNext;
	}
}

VOID InitializeParser()
{
	struct _PARMLIST Parms[] = {
	{"getlastfindslot",		parmGetLastFindSlot},
	{"cursor",				parmCursor},
	{"item",				parmItem},
	{"equip",				parmEquip},
	{"group",				parmGroup},
	{"target",				parmTarget},
	{"spawn(name,",			parmSpawnName},
	{"searchspawn(",		parmSearchSpawn},
	{"spawn",				parmSpawn},
	{"heading",				parmHeading},
	{"id(",					parmID},
	{"mouse(",				parmMouse},
	{"char(",				parmChar},
	{"spell(item,",			parmSpellItem},
	{"spell(",				parmSpell},
	{"return",				parmReturn},
	{"zone",				parmZone},
	{"finditem(bank,",		parmFinditemBank},
	{"finditem(",			parmFinditem},
	{"find",				parmFind},
	{"alert(",				parmAlert},
	{"gm",					parmGM},
	{"combat",				parmCombat},
	{"freeinv(",			parmFreeInv},
	{"distance(",			parmDistance},
	{"rand(",				parmRand},
	{"getlasterror",		parmGetLastError},
	{"lasttell",			parmLastTell},
	{"lastcommand",			parmLastCommand},
	{"invpanel",			parmInvPanel},
	{"if(n,",				parmIfN},
	{"if(",					parmIf},
	{"merchant(name)",		parmMerchantName},
	{"merchant(",			parmMerchantXXX},
	{"corpse(",				parmCorpse},
	{"merchant",			parmMerchant},
	{"running",				parmRunning},
	{"time(",				parmTime},
	{"date",				parmDate},
	{"pack(",				parmPack},
	{"arg(",				parmArg},
	{"left(",				parmLeft},
	{"mid(",				parmMid},
	{"right(",				parmRight},
	{"strlen(",				parmStrLen},
	{"instr(",				parmInstr},
	{"ucase(",				parmUcase},
	{"lcase",				parmLcase},
	{"count(",				parmCount},
	{"calc(",				parmCalc},
	{"door(",				parmDoor},
	{"ground(",				parmGround},
	{"calc(",				parmCalc},
	{"int(",				parmInt},
	{"abs(",				parmAbs},
	{"sin(",				parmSin},
	{"cos(",				parmCos},
	{"tan(",				parmTan},
	{"asin(",				parmAsin},
	{"acos(",				parmAcos},
	{"atan(",				parmAtan},
	{"sqrt(",		        parmSqrt},
	{"hex(",				parmHex},
	{"dec(",				parmDec},
	{"not(",				parmNot},
	{"ini(",				parmIni},
	{"defined(",			parmDefined},
	{"eqpath",				parmEQPath},
	{"macropath",			parmMacroPath},
	{"mqpath",				parmMQPath},
	{"logpath",				parmLogPath},
	{"envopen",				parmEnvOpen},
	{"giveopen",			parmGiveWnd},
	{"selecteditem",		parmSelectedItem},
	{"servername",			parmServerName},
	{"loginname",			parmLoginName},
	{"gamestate",			parmGameState},

	{NULL,NULL,NULL},
};

	for (int i = 0 ; Parms[i].fAddress && Parms[i].szName[0] ; i++)
	{
		AddParm(Parms[i].szName,Parms[i].fAddress);
	}
}

VOID ShutdownParser()
{
	while(pParmList)
	{
		PPARM pNext=pParmList->pNext;
		delete pParmList;
		pParmList=pNext;
	}
}


// ***************************************************************************
// Function:    ParseMacroParameter
// Description: Parses macro $ parameters ($cursor, etc)
// ***************************************************************************
/*****************************************************************************
 * NOTE: New syntax for adding macro parameters!                             *
 * Coded and converted by Valerian.                                          *
 * 1: Make changes in EQLib_MacroParser.h to reflect new function, and text  *
 *    to call that function.                                                 *
 *    A: PMP funcs: Simply make note of those already there, and make yours  *
 *                  the same.                                                *
 *                                                                           *
 *    B: Parms[] global variable:                                            *
 *       First field is the text that will call the parm func, minus the "$" *
 *       e.g. for $spawn(250,type) this would simply be "spawn". Lowercase.  *
 *                                                                           *
 *       Second field is the function name to call.                          *
 *                                                                           *
 *       Third field is NULL -- This field will be set to the address of the *
 *       function, the first time ParseMacroParameter is run.                *
 *                                                                           *
 * 2: Function definition MUST be:                                           *
 *    DWORD YourFuncName(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)      *
 *    A: Parameters are as follows:                                          *
 *                                                                           *
 *       DWORD return value: Old "i++" value. e.g. number of chars to skip   *
 *                           in original string. Size of your parameter,     *
 *                           without the "$", and minus 1. $spawn(250,type)  *
 *                           should return 14. Returning 10000 indicates an  *
 *                           error return. (Bad macro parameter)             *
 *                                                                           *
 *       szVar:              Text of parameter, up to and including trailing *
 *                           ")". May contain entire line if there are no ")"*
 *                           characters in that parameter.                   *
 *                                                                           *
 *       szOutput:           Output string. You will need to strcat your     *
 *                           output into this string.                        *
 *                                                                           *
 *  **NOTE** The ordering of commands in Parms[] variable may be important!  *
 *           They get checked in the order they are in the variable, and     *
 *           similar names must have the more specific one first! If there   *
 *           are two parms, e.g. "item" and "items", "items" must be first,  *
 *           or else the "item" command will be called and fail for a bad    *
 *           parm. Also note that you should be able to include a "(" at the *
 *           end of your parm name, or any number of chars there.            *
 *           "myparm(thisoption," is acceptable.                             *
 *****************************************************************************/

PCHAR ParseMacroParameter(PSPAWNINFO pChar, PCHAR szOriginal)
{
    BOOL FoundNewCmd=FALSE;
    CHAR szOutput[MAX_STRING] = {0};
    CHAR szVar[MAX_STRING] = {0};
    CHAR szTmp[MAX_STRING] = {0};
    DWORD i,l = 0;
    INT j,j2;
    PCHARINFO pCharInfo = NULL;
    if (NULL == (pCharInfo = GetCharInfo())) return szOriginal;

    while (strstr(szOriginal,"$") || strstr(szOriginal,"@")) {
        DebugSpew("PMP - Current string - '%s'",szOriginal);
        ZeroMemory(szOutput,MAX_STRING);
        ZeroMemory(szVar,MAX_STRING);
        i=0;
        j=-1;
        j2=-1;

        strncpy(szOutput,szOriginal,MAX_STRING);
        for (i=0;i<strlen(szOriginal);i++) {
            if (szOriginal[i] == '$') j=i;
            if (szOriginal[i] == '@') j2=i;
        }
        if (j2>j) { j=j2; } else { j2=-1; }
        for (i=j;i<strlen(szOriginal);i++) {
            szOutput[i]=0;
        };
        for (i=j;i<strlen(szOriginal);i++) {
            if (j2==j) {
                if (szOriginal[i] != '@') {
                    szOutput[j] = szOriginal[i];
                    j++;
                } else {
                    i++;
                    if ((szOriginal[i]==0) || (szOriginal[i]==' ')) {
                        DebugSpew("PMP - Bad @ '%s'",szVar);
                        i--;
                        szOutput[j] = '²';
                        j++;
                    } else {

                        GetArg(szVar,szOriginal+i,1,TRUE,TRUE,TRUE,0,TRUE);
                        if (szVar[strlen(szVar)-1]==')') szVar[strlen(szVar)-1]=0;
                        DebugSpew("PMP - Current variable - '%s'",szVar);
                        FoundNewCmd = FALSE;
						
                        if (gMacroStack) {
                            FoundNewCmd = SearchVariables(szVar,szOutput,gMacroStack->StackStr);
                            if (!FoundNewCmd) FoundNewCmd = SearchVariables(szVar,szOutput,gMacroStack->LocalStr);
                        }
                        if (!FoundNewCmd) FoundNewCmd = SearchVariables(szVar,szOutput,gMacroStr);
                        if (!FoundNewCmd) FoundNewCmd = SearchTimers(szVar,szOutput);
                        if (!FoundNewCmd) {
                            PVARARRAYS pArray = GetArray(szVar);
                            if (pArray) GetArg(szVar,szOriginal+i,1,TRUE,TRUE);
                            FoundNewCmd = SearchArrays(szVar,szOutput);
                        }
/**/
                        if (FoundNewCmd) {
                            i += strlen(szVar)-1;
                            j += (strlen(szOutput)-j);

                        // @unknown
                        } else {
                            DebugSpew("PMP - Bad @variable '%s'",szVar);
                            i--;
                            szOutput[j] = '²';
                            j++;
                        }

                    }
                }
                j2=j;
            } else if (szOriginal[i] != '$') {
                szOutput[j] = szOriginal[i];
                j++;
            } else {
                i++;
                if ((szOriginal[i]==0) || (szOriginal[i]==' ')) {
                    DebugSpew("PMP - Bad $ '%s'",szVar);
                    i--;
                    szOutput[j] = 'ÿ';
                    j++;
                } else {
                    GetArg(szVar,szOriginal+i,1,TRUE,TRUE);
                    DebugSpew("PMP - Current param - '%s'",szVar);
                    FoundNewCmd = FALSE;
					PPARM pParm=pParmList;
					while(pParm)
					{
						if (!strnicmp(szVar,pParm->szName,pParm->Length))
						{
							l = pParm->Function(szVar,szOutput,pChar);
                            if (l==PMP_ERROR_BADPARM) {
                                i--;
                                szOutput[j]='ÿ';
                                j++;
                                FoundNewCmd=TRUE;
                                break;
                            }
                            i += l;
                            j += (strlen(szOutput)-j);
                            FoundNewCmd=TRUE;
                            break;
                        }
						pParm=pParm->pNext;
					}

					// $unknown
                    if (!FoundNewCmd) {
                        DebugSpew("PMP - Bad $command '%s'",szVar);
                        i--;
                        szOutput[j] = 'ÿ';
                        j++;
                    }
                }
            }
        }
        strcpy(szOriginal,szOutput);
    }
    for (DWORD kount=0;szOriginal[kount]!='\0';kount++) {
        if (szOriginal[kount]=='ÿ') szOriginal[kount]='$';
        if (szOriginal[kount]=='²') szOriginal[kount]='@';
    }
    return (szOriginal);
}

// ***************************************************************************
// Function:    GracefullyEndBadMacro
// Description: Used to end a 'bad' macro (parsing issues, etc)
// ***************************************************************************
VOID GracefullyEndBadMacro(PSPAWNINFO pChar, PMACROBLOCK pBadLine, PCHAR szFormat, ...)
{
    CHAR szArgs[MAX_STRING] = {0};
    CHAR szMessage[MAX_STRING] = {0};
    va_list vaList;
    va_start( vaList, szFormat );
    vsprintf(szArgs,szFormat, vaList);
    if (gMacroBlock && pBadLine) {
        sprintf(szMessage,"Ending macro: %s",szArgs);
        WriteChatColor(szMessage,CONCOLOR_RED);
        gMacroBlock=pBadLine;
        DumpStack(pChar,"");
        EndMacro(pChar,"");
    } else {
        sprintf(szMessage,"Error: %s",szArgs);
        WriteChatColor(szMessage,CONCOLOR_RED);
    }
}

// ***************************************************************************
// Function:    AddMacroLine
// Description: Add a line to the MacroBlock
// ***************************************************************************
PMACROBLOCK AddMacroLine(PCHAR szLine)
{
    PMACROBLOCK pBlock = NULL;

    while ((szLine[0] == ' ') || (szLine[0] == '\t')) szLine++;

    if ((szLine[0]==0) || (szLine[0]=='|')) return (PMACROBLOCK)1;

    while ((szLine[strlen(szLine)-1] == ' ') || (szLine[strlen(szLine)-1] == '\t')) szLine[strlen(szLine)-1]=0;
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

            //DebugSpew("AddMacroLine - Including file: %s",Filename);
            return (PMACROBLOCK)Include(Filename);
        } else if (!strnicmp(szLine,"#turbo",6)) {
            gTurbo = TRUE;
            CHAR szArg[MAX_STRING] = {0};
            GetArg(szArg,szLine,2);
            gMaxTurbo = atoi(szArg);
            if (gMaxTurbo==0) gMaxTurbo=500;
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
                DebugSpew("Bad #define: %s",szLine);
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
                pEvent->pEventFunc = NULL;
                pEvent->pNext = pEventList;
                pEventList = pEvent;
            } else {
                DebugSpew("Bad #event: %s",szLine);
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
            CHAR szError[MAX_STRING] = {0};
            sprintf(szError,"Unknown # command: %s",szLine);
            WriteChatColor(szError,CONCOLOR_RED);
            return FALSE;
        }
    }

    pBlock = (PMACROBLOCK)malloc(sizeof(MACROBLOCK));
    if (!pBlock) return NULL;
    //DebugSpew("AddMacroLine - Adding: %s",szLine);
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
