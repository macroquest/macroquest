/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2004 Lax

	Portions Copyright(C) 2004 Zaphod

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
	DebugSpewNoFile("InitializeParser()");

#ifdef	USEMQ2DATATYPES
	InitializeMQ2DataTypes();
	InitializeMQ2Data();
#endif
#if 0
	struct _PARMLIST Parms[] = {
	{"getlastfindslot",		parmGetLastFindSlot},
	{"cursor",				parmCursor},
	{"pet",					parmPet},
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
	{"macro",				parmMacro}, 
	{"event",				parmEvent},
	{"banker(",				parmBanker},

	{NULL,NULL,NULL},
};

	for (int i = 0 ; Parms[i].fAddress && Parms[i].szName[0] ; i++)
	{
		AddParm(Parms[i].szName,Parms[i].fAddress);
	}
#endif
	bmParseMacroParameter=AddMQ2Benchmark("ParseMacroParameter");
}

VOID ShutdownParser()
{
#ifdef	USEMQ2DATATYPES
	ShutdownMQ2Data();
	ShutdownMQ2DataTypes();
#endif
	DebugSpewNoFile("ShutdownParser()");
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

int FindLastParameter(PCSTR szOriginal, PCSTR& szRetCurPos, size_t& len)
{
	PCSTR szCurPos;
	PCSTR szParamPos = NULL;

	// iterate over the entire string
	for (szCurPos = szOriginal; *szCurPos; szCurPos++)
		if ((*szCurPos == '$') || (*szCurPos == '@')) // note parameter position
			szParamPos = szCurPos;

	// calculate the strings length
	len = (size_t)(szCurPos - szOriginal - 1);

	// return the parameters position
	szRetCurPos = szParamPos;

	if (szParamPos) // return offset into string if paramater found
		return (int)(szParamPos - szOriginal);

	return -1; // no parameter found
}



PCHAR ParseMacroParameter(PSPAWNINFO pChar, PCHAR szOriginal)
{
    PCHARINFO pCharInfo = GetCharInfo();
    if (!pCharInfo) 
		return szOriginal;
	EnterMQ2Benchmark(bmParseMacroParameter);

#ifdef USEMQ2PARMS
	bool FoundNewCmd = false;
    CHAR szOutput[MAX_STRING];
    CHAR szVar[MAX_STRING];
    INT outPos, l;
	PSTR szOutputCurPos;
	PCSTR szOriginalCurPos;
	size_t originalLen;
    while ((outPos = FindLastParameter(szOriginal, szOriginalCurPos, originalLen)) != -1) 
	{
        //DebugSpewNoFile("PMP - Current string - '%s'", szOriginal);
		strncpy(szOutput, szOriginal, outPos);
		szOutputCurPos = &szOutput[outPos];
		*szOutputCurPos = 0;

		if (*szOriginalCurPos == '@') 
		{
            szOriginalCurPos++;
            if ((*szOriginalCurPos) && (*szOriginalCurPos != ' ')) 
			{
                GetArg(szVar, szOriginalCurPos, 1, TRUE, TRUE, TRUE, 0, TRUE);
				size_t varLen = strlen(szVar)-1;
                if (szVar[varLen] == ')') szVar[varLen]=0;
                //DebugSpewNoFile("PMP - Current variable - '%s'", szVar);
                FoundNewCmd = true;
				
				do // this is a non-looping loop used purely for control flow
				{
					if (gMacroStack) 
					{
						if (SearchVariables(szVar, szOutputCurPos, gMacroStack->StackStr)) break;
						if (SearchVariables(szVar, szOutputCurPos, gMacroStack->LocalStr)) break;
					}
					if (SearchVariables(szVar, szOutputCurPos, gMacroStr)) break;
					if (SearchTimers(szVar, szOutputCurPos)) break;

					PVARARRAYS pArray = GetArray(szVar);
					if (pArray) GetArg(szVar, szOriginalCurPos, 1, TRUE, TRUE);
					if (SearchArrays(szVar,szOutputCurPos)) break;

					// @unknown
					FoundNewCmd = false;
					DebugSpewNoFile("PMP - Bad @variable '%s'",szVar);
					szOriginalCurPos--;
					*szOutputCurPos++ = '²';
				} while (false);

				if (FoundNewCmd) 
				{
					szOriginalCurPos += strlen(szVar) - 1;
					szOutputCurPos += strlen(szOutputCurPos);
				}
            }
			else 
			{
                DebugSpewNoFile("PMP - Bad @ '%s'", szVar);
				szOriginalCurPos--;
                *szOutputCurPos++ = '²';
			}
        } 
		else /* if (*szOriginalCurPos == '$') */ 
		{
            szOriginalCurPos++;
            if ((*szOriginalCurPos) && (*szOriginalCurPos != ' ')) 
			{
                GetArg(szVar, szOriginalCurPos, 1, TRUE, TRUE);
//                DebugSpewNoFile("PMP - Current param - '%s'", szVar);
                FoundNewCmd = FALSE;
				PPARM pParm = pParmList;
				while(pParm)
				{
					if (!strnicmp(szVar, pParm->szName, pParm->Length))
					{
						l = pParm->Function(szVar, szOutputCurPos, pChar);
                        if (l == PMP_ERROR_BADPARM) {
                            szOriginalCurPos--;
                            *szOutputCurPos++ = 'ÿ';
                            FoundNewCmd = true;
                            break;
                        }
                        szOriginalCurPos += l;
                        szOutputCurPos += strlen(szOutputCurPos);
                        FoundNewCmd = true;
                        break;
                    }
					pParm = pParm->pNext;
				}

				// $unknown
                if (!FoundNewCmd) 
				{
//                    DebugSpewNoFile("PMP - Bad $command '%s'",szVar);
                    szOriginalCurPos--;
                    *szOutputCurPos++ = 'ÿ';
                }
            } 
			else
			{
//                DebugSpewNoFile("PMP - Bad $ '%s'", szVar);
                szOriginalCurPos--;
                *szOutputCurPos++ = 'ÿ';
            }
		}

		outPos = szOutputCurPos - szOutput;
		memmove(&szOriginal[outPos], szOriginalCurPos + 1, 
				originalLen - (szOriginalCurPos - szOriginal) + 1);
		strncpy(szOriginal, szOutput, outPos);
    }

    for (PCHAR szPos = szOriginal; *szPos != '\0'; szPos++) 
	{
        if (*szPos == 'ÿ') 
			*szPos = '$';
        else if (*szPos == '²') 
			*szPos = '@';
    }
#endif
#ifdef USEMQ2DATATYPES
#ifndef USEMQ2DATAVARS
	ParseMacroVariables(szOriginal);
#endif
	ParseMacroData(szOriginal);
#endif
	ExitMQ2Benchmark(bmParseMacroParameter);
    return (szOriginal);
}

