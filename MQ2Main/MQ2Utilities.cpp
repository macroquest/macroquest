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



// ***************************************************************************
// Function:    DebugSpew
// Description: Outputs text to debugger, usage is same as printf ;)
// ***************************************************************************
VOID DebugSpew(PCHAR szFormat, ...)
{
#ifdef DBG_SPEW
    if (gFilterDebug) return;
    CHAR szOutput[MAX_STRING] = {0};
    va_list vaList;
    va_start( vaList, szFormat );
    vsprintf(szOutput,szFormat, vaList);
    DebugSpewAlways(szOutput);
#endif
}

VOID DebugSpewAlways(PCHAR szFormat, ...)
{
    CHAR szOutput[MAX_STRING] = {0};
    va_list vaList;

    OutputDebugString(DebugHeader);
    va_start( vaList, szFormat );
    vsprintf(szOutput,szFormat, vaList);
    OutputDebugString(szOutput);
    OutputDebugString("\n");

#ifdef DBG_SPEW
    if (gSpewToFile) {

    FILE *fOut = NULL;
    CHAR Filename[MAX_STRING] = {0};
    sprintf(Filename,"%s\\DebugSpew.log",gszLogPath);
    fOut = fopen(Filename,"at");
    if (!fOut) return;
#ifdef DBG_CHARNAME
	CHAR Name[256] = "Unknown";
	PCHARINFO pCharInfo = GetCharInfo();
	if (pCharInfo)
	{
		strcpy(Name,pCharInfo->Name);
	}
    fprintf(fOut,"%s - %s\r\n", Name, szOutput);
#else
    fprintf(fOut,"%s\r\n", szOutput);
#endif
    fclose(fOut);
    }
#endif
}

EQLIB_API VOID DebugSpewNoFile(PCHAR szFormat, ...)
{
#ifdef DBG_SPEW
    CHAR szOutput[MAX_STRING] = {0};
    va_list vaList;

    OutputDebugString(DebugHeader);
    va_start( vaList, szFormat );
    vsprintf(szOutput,szFormat, vaList);
    OutputDebugString(szOutput);
    OutputDebugString("\n");
#endif
}


// ***************************************************************************
// Function:    GetNextArg
// Description: Returns a pointer to the next argument
// ***************************************************************************
PCHAR GetNextArg(PCHAR szLine, DWORD dwNumber, BOOL CSV, CHAR Separator)
{
   PCHAR szNext = szLine;
   BOOL CustomSep = FALSE;
   BOOL InQuotes = FALSE;
   if (Separator!=0) CustomSep=TRUE;

   while (
         ((!CustomSep) && (szNext[0] == ' '))
      || ((!CustomSep) && (szNext[0] == '\t'))
      || ((CustomSep) && (szNext[0]==Separator))
      || ((!CustomSep) && (CSV) && (szNext[0]==','))
      ) szNext++;

   if ((INT)dwNumber < 1) return szNext;
   for (dwNumber;dwNumber>0;dwNumber--) {
      while ((
            ((CustomSep) || (szNext[0] != ' '))
         && ((CustomSep) || (szNext[0] != '\t'))
         && ((!CustomSep) || (szNext[0]!=Separator))
         && ((CustomSep) || (!CSV) || (szNext[0]!=','))
         && (szNext[0] != 0)
         )
         || (InQuotes)
         ) {
         if ((szNext[0] == 0) && (InQuotes)) {
            DebugSpew("GetNextArg - No matching quote, returning empty string");
            return szNext;
         }
         if (szNext[0] == '"') InQuotes = !InQuotes;
         szNext++;
      }
      while (
            ((!CustomSep) && (szNext[0] == ' '))
         || ((!CustomSep) && (szNext[0] == '\t'))
         || ((CustomSep) && (szNext[0]==Separator))
         || ((!CustomSep) && (CSV) && (szNext[0]==','))
         ) szNext++;
   }
   return szNext;
}

// ***************************************************************************
// Function:    GetArg
// Description: Returns a pointer to the current argument in szDest
// ***************************************************************************
PCHAR GetArg(PCHAR szDest, PCHAR szSrc, DWORD dwNumber, BOOL LeaveQuotes, BOOL ToParen, BOOL CSV, CHAR Separator, BOOL AnyNonAlphaNum)
{
   DWORD i=0;
   DWORD j=0;
   BOOL CustomSep = FALSE;
   BOOL InQuotes = FALSE;
   PCHAR szTemp = szSrc;
   ZeroMemory(szDest,MAX_STRING);

   if (Separator!=0) CustomSep=TRUE;

   szTemp = GetNextArg(szTemp,dwNumber-1, CSV, Separator);

   while ((
         ((CustomSep) || (szTemp[i] != ' '))
      && ((CustomSep) || (szTemp[i] != '\t'))
      && ((CustomSep) || (!CSV) || (szTemp[i]!=','))
      && ((!CustomSep) || (szTemp[i]!=Separator))
      && ((!AnyNonAlphaNum) || (
            (szTemp[i]>='0' && szTemp[i]<='9') ||
            (szTemp[i]>='a' && szTemp[i]<='z') ||
            (szTemp[i]>='A' && szTemp[i]<='Z') ||
            (szTemp[i]=='_')
            ))
      && (szTemp[i] != 0)
      && ((!ToParen) || (szTemp[i] !=')'))
      )
      || (InQuotes)
      ) {
      if ((szTemp[i] == 0) && (InQuotes)) {
         DebugSpew("GetArg - No matching quote, returning entire string");
         DebugSpew("Source = %s",szSrc);
         DebugSpew("Dest = %s",szDest);
         return szDest;
      }
      if (szTemp[i] == '"') {
         InQuotes = !InQuotes;
         if (LeaveQuotes) {
            szDest[j] = szTemp[i];
            j++;
         }
      } else {
         szDest[j] = szTemp[i];
         j++;
      }
      i++;
   }
   if ((ToParen) && (szTemp[i]==')')) szDest[j]=')';
   //DebugSpew("GetArg - Arg%d from '%s' = '%s'",dwNumber,szTemp,szDest);

   return szDest;
}

PCHARINFO GetCharInfo(VOID) {
    if (!ppCharData) return NULL;
    return (PCHARINFO)pCharData;
}

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

VOID AddCustomEvent(PEVENTLIST pEList, PCHAR szLine)
{
    PEVENTSTACK pEvent = NULL;
    if (!pEList->pEventFunc) return;
    pEvent = (PEVENTSTACK)malloc(sizeof(EVENTSTACK));
    if (!pEvent) return;
    ZeroMemory(pEvent,sizeof(EVENTSTACK));
    pEvent->Type = EVENT_CUSTOM;
    pEvent->pEventList = pEList;
    CHAR szParamName[MAX_STRING] = {0};
    strcpy(GetEventStr(pEvent,GetFuncParamName(pEList->pEventFunc->Line,0,szParamName),TRUE),szLine);

    if (!gEventStack) {
        gEventStack = pEvent;
    } else {
        PEVENTSTACK pTemp = NULL;
        for (pTemp = gEventStack;pTemp->pNext;pTemp=pTemp->pNext);
        pTemp->pNext = pEvent;
    }
}


// ***************************************************************************
// Function:    DistanceToSpawn
// Description: Return the distance between two spawns
// ***************************************************************************
FLOAT DistanceToSpawn(PSPAWNINFO pChar, PSPAWNINFO pSpawn)
{
    FLOAT X = pChar->X - pSpawn->X;
    FLOAT Y = pChar->Y - pSpawn->Y;
    //FLOAT Z = pChar->Z - pSpawn->Z;
    return sqrtf(X*X + Y*Y);// + Z*Z);
}

PCHAR GetEQPath(PCHAR szBuffer)
{
    GetModuleFileName(NULL, szBuffer, MAX_STRING);
    PCHAR pSearch=0;
    if (pSearch=strstr(strlwr(szBuffer), "\\testeqgame.exe"))
        *pSearch=0;
    else if (pSearch=strstr(szBuffer, "\\eqgame.exe"))
            *pSearch=0;
    return szBuffer;
}

VOID ConvertItemTags(CXStr &cxstr)
{
//	PCXSTR *saddr=cxstr;
   __asm{
      push ecx;
      push eax;
	  push 1;
	   push [cxstr];
	   call [EQADDR_CONVERTITEMTAGS];
	   pop ecx;
	   pop ecx;
	   pop eax;
	   pop ecx;
   };
//   *cxstr=*saddr;
}

// YES THIS NEEDS TO BE PCXSTR * 
VOID AppendCXStr(PCXSTR *cxstr, PCHAR text) 
{ 
	CXStr *Str=(CXStr*)cxstr;
	(*Str)+=text;
	cxstr=(PCXSTR*)Str;

//	cxstr+=text;

	/*
   __asm 
   { 
      push eax; 
      push ecx; 
	  push edx;
      mov ecx, cxstr; 
      push text; 
      call [EQADDR_CXSTRAPPEND]; 
	  pop edx;
      pop ecx; 
      pop eax; 
   } 
   */
} 

// YES THIS NEEDS TO BE PCXSTR * 
VOID SetCXStr(PCXSTR *cxstr, PCHAR text) 
{ 
//	cxstr=text;
//	DebugSpew("SetCXStr(%s)",text);
	CXStr *Str=(CXStr*)cxstr;
	(*Str)=text;
	cxstr=(PCXSTR*)Str;
	/*
	__asm{push esi};
   __asm 
   { 
      push eax; 
      push ecx; 
	  push edx;
      mov ecx, cxstr; 
      push text; 
      call [EQADDR_CXSTRSET]; 
	  pop edx;
      pop ecx; 
      pop eax; 
   } 
	__asm{pop esi};
	*/
} 

VOID GetCXStr(PCXSTR pCXStr, PCHAR szBuffer, DWORD maxlen)
{
	if (!pCXStr || !szBuffer || !maxlen){return;}
	if (pCXStr->Encoding==0)
	{
		if (pCXStr->Length<maxlen)
		{
			strcpy(szBuffer,pCXStr->Text);
		}
		else
		{
			strncpy(szBuffer,pCXStr->Text,maxlen);
			szBuffer[maxlen-1]=0;
		}
	}
	else
	{ // unicode
		// this is kind of ghetto but it works for english
		DWORD i=0;
		DWORD o=0;
		maxlen--;
		while(pCXStr->Text[i] && o<maxlen)
		{
			szBuffer[o++]=pCXStr->Text[i];
			i+=2;
		}
		szBuffer[o]=0;
	}
}
/**/

#define InsertColor(text,color) sprintf(text,"<c \"#%06X\">",color);TotalColors++; 
#define InsertStopColor(text)   sprintf(text,"</c>");TotalColors--; 

VOID StripMQChat(PCHAR in, PCHAR out)
{
//	DebugSpew("StripMQChat(%s)",in);
	int i = 0;
	int o = 0;
	while(in[i])
	{
		if (in[i]=='\a')
		{
			i++;
			if(in[i]=='-')
			{ // skip 1 after -
				i++;
			}
			else if (in[i]=='#')
			{ // skip 6 after #
				i+=6;
			}
		}
		else if (in[i]=='\n')
		{
		}
		else
			out[o++]=in[i];
		i++;
	}
	out[o]=0;
//	DebugSpew("StripMQChat=>(%s)",out);
}

DWORD MQToSTML(PCHAR in, PCHAR out, DWORD maxlen, DWORD ColorOverride)
{
	DebugSpew("MQToSTML(%s)",in);
	// 1234567890123
	// <c "#123456">
	if (maxlen>14)
		maxlen-=14; // huh...
   DWORD pchar_in_string_position = 0;
   DWORD pchar_out_string_position = 0;
   BOOL bFirstColor=false;
   BOOL bNBSpace=false;
   ColorOverride&=0xFFFFFF;
   DWORD CurrentColor=ColorOverride;
   int TotalColors=0; // this MUST be signed.
   pchar_out_string_position+=InsertColor(&out[pchar_out_string_position],CurrentColor);

   while(in[pchar_in_string_position]!=0 && pchar_out_string_position<maxlen)
   {
	  if (in[pchar_in_string_position]==' ')
	  {
         if (bNBSpace) {
            out[pchar_out_string_position++]='&';
            out[pchar_out_string_position++]='N';
            out[pchar_out_string_position++]='B';
            out[pchar_out_string_position++]='S';
            out[pchar_out_string_position++]='P';
            out[pchar_out_string_position++]=';';
         } else {
            out[pchar_out_string_position++]=' ';
         }
         bNBSpace=1;
	  }
	  else
	  {
	    bNBSpace=0;
		switch(in[pchar_in_string_position])
		{
		case '\a':
			// HANDLE COLOR
			bFirstColor=true;
			pchar_in_string_position++;
			if (in[pchar_in_string_position]=='x')
			{
				CurrentColor=-1;
				pchar_out_string_position+=InsertStopColor(&out[pchar_out_string_position]);
			}
			else
			if (in[pchar_in_string_position]=='#')
			{
				pchar_in_string_position++;
				char temp[7];
				for (int x = 0 ; x < 6 ; x++)
				{
					temp[x++]=in[pchar_in_string_position++];
				}
				pchar_in_string_position--;
				temp[6]=0;
				CurrentColor=-1;
				pchar_out_string_position+=sprintf(&out[pchar_out_string_position],"<c \"#%s\">",&temp[0]);
				TotalColors++;
			}
			else
			{
				bool Dark=false;
				if (in[pchar_in_string_position]=='-')
				{
					Dark=true;	
					pchar_in_string_position++;
				}
				int LastColor=CurrentColor;
				switch(in[pchar_in_string_position])
				{
					case 'y': // yellow (green/red)
						if (Dark)
							CurrentColor=0x999900;
						else
							CurrentColor=0xFFFF00;
						break;
					case 'o': // orange (green/red)
						if (Dark)
							CurrentColor=0x996600;
						else
							CurrentColor=0xFF9900;
						break;
					case 'g': // green   (green)
						if (Dark)
							CurrentColor=0x009900;
						else
	  						CurrentColor=0x00FF00;
						break;
					case 'u': // blue   (blue)
						if (Dark)
							CurrentColor=0x000099;
						else
  							CurrentColor=0x0000FF;
						break;
					case 'r': // red     (red)
						if (Dark)
							CurrentColor=0x990000;
						else
	  						CurrentColor=0xFF0000;
						break;
					case 't': // teal (blue/green)
						if (Dark)
  							CurrentColor=0x009999;
						else
  							CurrentColor=0x00FFFF;
						break;
					case 'b': // black   (none)
  						CurrentColor=0x000000;
						break;
					case 'm': // magenta (blue/red)
						if (Dark)
	  						CurrentColor=0x990099;
						else
	  						CurrentColor=0xFF00FF;
						break;
					case 'p': // purple (blue/red)
						if (Dark)
							CurrentColor=0x660099;
						else
	  						CurrentColor=0x9900FF;
						break;
					case 'w': // white   (all)
						if (Dark)
							CurrentColor=0x999999;
						else
	  						CurrentColor=0xFFFFFF;
						break;
					}
					if ((int)CurrentColor!=LastColor)
					{
						pchar_out_string_position+=InsertColor(&out[pchar_out_string_position],CurrentColor);
					}
				}
			break;
		case '&':
			out[pchar_out_string_position++]='&';
			out[pchar_out_string_position++]='A';
			out[pchar_out_string_position++]='M';
			out[pchar_out_string_position++]='P';
			out[pchar_out_string_position++]=';';
			break;
		case '%':
			out[pchar_out_string_position++]='&';
			out[pchar_out_string_position++]='P';
			out[pchar_out_string_position++]='C';
			out[pchar_out_string_position++]='T';
			out[pchar_out_string_position++]=';';
			break;
		case '<':
			out[pchar_out_string_position++]='&';
			out[pchar_out_string_position++]='L';
			out[pchar_out_string_position++]='T';
			out[pchar_out_string_position++]=';';
			break;
		case '>':
			out[pchar_out_string_position++]='&';
			out[pchar_out_string_position++]='G';
			out[pchar_out_string_position++]='T';
			out[pchar_out_string_position++]=';';
			break;
		case '"':
			out[pchar_out_string_position++]='&';
			out[pchar_out_string_position++]='Q';
			out[pchar_out_string_position++]='U';
			out[pchar_out_string_position++]='O';
			out[pchar_out_string_position++]='T';
			out[pchar_out_string_position++]=';';
			break;
		case '\n':
			out[pchar_out_string_position++]='<';
			out[pchar_out_string_position++]='B';
			out[pchar_out_string_position++]='R';
			out[pchar_out_string_position++]='>';
			break;
		default:
			out[pchar_out_string_position++]=in[pchar_in_string_position];
			break;
		}
	  }
      pchar_in_string_position++;
   }
   for (TotalColors ; TotalColors>0 ;)
   {
	  pchar_out_string_position+=InsertStopColor(&out[pchar_out_string_position]);
   }
	out[pchar_out_string_position++]=0;
	return pchar_out_string_position;
}

PCHAR GetFilenameFromFullPath(PCHAR Filename)
{
    while (strstr(Filename,"\\")) Filename=strstr(Filename,"\\")+1;
    return Filename;
}

PCHAR GetSubFromLine(PMACROBLOCK pLine, PCHAR szSub)
{
    while (pLine!=NULL) {
        if (!strnicmp(pLine->Line,"sub ",4)) {
            strcpy(szSub,pLine->Line+4);
            return szSub;
        }
        pLine = pLine->pPrev;
    }
    strcpy(szSub,"NULL");
    return szSub;
}

BOOL CompareTimes(PCHAR RealTime, PCHAR ExpectedTime)
{
    //Match everything except seconds
    //Format is: WWW MMM DD hh:mm:ss YYYY
    //           0123456789012345678901234
    //                     1         2
    if (!strnicmp(RealTime,ExpectedTime,17) &&
        !strnicmp(RealTime+19,ExpectedTime+19,5))
        return TRUE;
    return FALSE;

}

VOID AddFilter(PCHAR szFilter, DWORD Length, PBOOL pEnabled)
{
    PFILTER New = (PFILTER)malloc(sizeof(FILTER));
    if (!New) return;
    if (Length==-1) Length=strlen(szFilter);
    strcpy(New->FilterText,szFilter);
    New->Length=Length;
    New->pEnabled=pEnabled;
    New->pNext=gpFilters;
    gpFilters=New;
}

VOID DefaultFilters(VOID)
{
    AddFilter("You have become better at ",                                             26, &gFilterSkillsIncrease);
    AddFilter("You lacked the skills to fashion the items together.",                   -1, &gFilterSkillsAll);
    AddFilter("You have fashioned the items together to create something new!",         -1, &gFilterSkillsAll);
    AddFilter("You have fashioned the items together to create an alternate product.",  -1, &gFilterSkillsAll);
    AddFilter("You can no longer advance your skill from making this item.",            -1, &gFilterSkillsAll);
    AddFilter("You no longer have a target.",                                           -1, &gFilterTarget);
    AddFilter("You give ",                                                              9,  &gFilterMoney);
    AddFilter("You receive ",                                                           12, &gFilterMoney);
    AddFilter("You are encumbered",                                                     17, &gFilterEncumber);
    AddFilter("You are no longer encumbered",                                           27, &gFilterEncumber);
    AddFilter("You are low on drink",                                                   19, &gFilterFood);
    AddFilter("You are low on food",                                                    18, &gFilterFood);
    AddFilter("You are out of drink",                                                   19, &gFilterFood);
    AddFilter("You are out of food",                                                    18, &gFilterFood);
    AddFilter("You and your mount are thirsty.",                                        -1, &gFilterFood);
    AddFilter("You and your mount are hungry.",                                         -1, &gFilterFood);
    AddFilter("You are hungry",                                                         13, &gFilterFood);
    AddFilter("You are thirsty",                                                        14, &gFilterFood);
    AddFilter("You take a bite out of",                                                 22, &gFilterFood);
    AddFilter("You take a drink from",                                                  21, &gFilterFood);
    AddFilter("Ahhh. That was tasty.",                                                  -1, &gFilterFood);
    AddFilter("Ahhh. That was refreshing.",                                             -1, &gFilterFood);
    AddFilter("Chomp, chomp, chomp...",                                                 22, &gFilterFood);
    AddFilter("Glug, glug, glug...",                                                    19, &gFilterFood);
    AddFilter("You could not possibly eat any more, you would explode!",                -1, &gFilterFood);
    AddFilter("You could not possibly drink any more, you would explode!",              -1, &gFilterFood);
    AddFilter("You could not possibly consume more alcohol or become more intoxicated!",-1, &gFilterFood);
}

PCHAR ConvertHotkeyNameToKeyName(PCHAR szName)
{
    if (!stricmp(szName,"EQUALSIGN")) strcpy(szName,"=");
    if (!stricmp(szName,"SEMICOLON")) strcpy(szName,";");
    if (!stricmp(szName,"LEFTBRACKET")) strcpy(szName,"[");
    return szName;
}





















// ***************************************************************************
// Function:    GetFullZone
// Description: Returns a full zone name from a short name
// ***************************************************************************
PCHAR GetFullZone(DWORD ZoneID)
{
    PZONELIST *pZone = NULL;
    if (!ppWorldData | !pWorldData) return NULL;
    pZone = (PZONELIST*) (pWorldData + ZONELIST_STARTOFFSET);

    return (*pZone[ZoneID]).LongName;
}
// ***************************************************************************
// Function:    GetShortZone
// Description: Returns a short zone name from a ZoneID
// ***************************************************************************
PCHAR GetShortZone(DWORD ZoneID)
{
    PZONELIST *pZone = NULL;
    if (!ppWorldData | !pWorldData) return NULL;
    pZone = (PZONELIST*) (pWorldData + ZONELIST_STARTOFFSET);

    return (*pZone[ZoneID]).ShortName;
}
// ***************************************************************************
// Function:    GetZoneID
// Description: Returns a ZoneID from a short zone name
// ***************************************************************************

DWORD GetZoneID(PCHAR ZoneShortName)
{
    PZONELIST *pZone = NULL;
    if (!ppWorldData | !pWorldData) return NULL;
    pZone = (PZONELIST*) (pWorldData + ZONELIST_STARTOFFSET);
    for (int nIndex=0; nIndex < MAX_ZONES+1; nIndex++) {
        if(pZone[nIndex])
            if (!_stricmp((*pZone[nIndex]).ShortName,ZoneShortName)) {
                return nIndex;
            }
    }
    return NULL;
}


//CHAR szUnknownSpell[MAX_STRING] = "Unknown Spell";
// ^^ this shit is unnecessary, static strings are already stored at a location in the
// file itself. Changed the function to return "Unknown Spell". - Lax

PCHAR GetSpellNameByID(DWORD dwSpellID)
{
    PSPELL pSpell = NULL;
    if (ppSpellMgr == NULL) return "Unknown Spell";
    pSpell =  &(*((PSPELLMGR)pSpellMgr)->Spells[dwSpellID]);
    if (pSpell != NULL) {
        if (pSpell->Name != NULL) {
            if (pSpell->Name[0]!='\0') {
                return pSpell->Name;
            }
        }
    }
    return "Unknown Spell";
}

PSPELL GetSpellByName(PCHAR szName)
{
// PSPELL GetSpellByName(PCHAR NameOrID)
// This function now accepts SpellID as an argument as well as SpellName
// (but inefficient for spellID!)
    PSPELL pSpell = NULL;
    if (ppSpellMgr == NULL) return NULL;
    for (DWORD dwSpellID = 0; dwSpellID < TOTAL_SPELL_COUNT; dwSpellID++) {
        pSpell = &(*((PSPELLMGR)pSpellMgr)->Spells[dwSpellID]);
		if ((pSpell->ID > 0) && (pSpell->ID < TOTAL_SPELL_COUNT)) {
            if (pSpell->Name != NULL) {
                if (!_stricmp(szName, pSpell->Name)) {
                    return pSpell;
                }
			if ((int)pSpell->ID == atol(szName) )
				return pSpell;
            }
        }
    }
    return NULL;
}

DWORD GetSpellDuration(PSPELL pSpell, PSPAWNINFO pSpawn)
{
    switch (pSpell->DurationType) {
        case 0:
            return 0;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
            if (pSpell->DurationValue1) {
                return (pSpell->DurationValue1);
            } else {
                return (pSpell->DurationType*10);
            }
        case 7:
            if (pSpell->DurationValue1) {
                return (pSpell->DurationValue1);
            } else {
                return (pSpawn->Level*10);
            }

        case 50:
            return 0xFFFFFFFF;
        case 3600:
            return 6000;
        default:
            return 0xFFFFFFFE;
    }
}

DWORD GetDeityTeamByID(DWORD DeityID) {
    switch (DeityID) {
        case DEITY_ErollisiMarr:
        case DEITY_MithanielMarr:
        case DEITY_RodcetNife:
        case DEITY_Quellious:
        case DEITY_Tunare:
            return 1;
        case DEITY_BrellSerilis:
        case DEITY_Bristlebane:
        case DEITY_Karana:
        case DEITY_Prexus:
        case DEITY_SolusekRo:
        case DEITY_TheTribunal:
        case DEITY_Veeshan:
            return 2;
        case DEITY_Bertoxxulous:
        case DEITY_CazicThule:
        case DEITY_Innoruuk:
        case DEITY_RallosZek:
            return 3;
        default:
            return 0;
    }
}


PCHAR GetGuildByID(DWORD GuildID)
{
    if (GuildID>=0xFFFE) return NULL;
    return (PCHAR)(EQADDR_GUILDLIST + 64 * GuildID);
}

DWORD GetGuildIDByName(PCHAR szGuild)
{
    PCHAR szCurrentGuild = NULL;
    DWORD GuildID = 0;
    for (GuildID=0;GuildID<0xFFFE;GuildID++) {
        szCurrentGuild = (PCHAR)(EQADDR_GUILDLIST + 64 * GuildID);
        if (szCurrentGuild[0]==0) return 0xFFFF;
        if (!strnicmp(szGuild,szCurrentGuild,strlen(szGuild))) return GuildID;
    }
    return 0xFFFF;
}

PCHAR GetLightForSpawn(PSPAWNINFO pSpawn)
{
    BYTE Light = pSpawn->Light;
    if (Light>LIGHT_COUNT) Light=0;
    return szLights[Light];
}

// ***************************************************************************
// Function:    DistanceToSpawn3D
// Description: Return the distance between two spawns, including Z
// ***************************************************************************
FLOAT DistanceToSpawn3D(PSPAWNINFO pChar, PSPAWNINFO pSpawn)
{
    FLOAT X = pChar->X - pSpawn->X;
    FLOAT Y = pChar->Y - pSpawn->Y;
    FLOAT Z = pChar->Z - pSpawn->Z;
    return sqrtf(X*X + Y*Y + Z*Z);
}


// ***************************************************************************
// Function:    DistanceToSpawn
// Description: Return the distance between two spawns
// ***************************************************************************
FLOAT EstimatedDistanceToSpawn(PSPAWNINFO pChar, PSPAWNINFO pSpawn)
{
    FLOAT RDistance = DistanceToSpawn(pChar,pSpawn);
    FLOAT X = pChar->X - (pSpawn->X + pSpawn->SpeedX * RDistance);
    FLOAT Y = pChar->Y - (pSpawn->Y + pSpawn->SpeedY * RDistance);
    return sqrtf(X*X + Y*Y);
}





// ***************************************************************************
// Function:    ConColorToRGB
// Description: Returns the RGB color for a con color
// ***************************************************************************
DWORD ConColorToARGB(DWORD ConColor)
{
    switch (ConColor) {
        case CONCOLOR_GREEN:
            return 0xFF00FF00;
        case CONCOLOR_LIGHTBLUE:
            return 0xFF00FFFF;
        case CONCOLOR_BLUE:
            return 0xFF0000FF;
        case CONCOLOR_BLACK:
            return 0xFFFFFFFF;
        case CONCOLOR_YELLOW:
            return 0xFFFFFF00;
        case CONCOLOR_RED:
        default:
            return 0xFFFF0000;
    }
}


// ***************************************************************************
// Function:    ConColor
// Description: Returns the con color for a spawn's level
// ***************************************************************************
DWORD ConColor(WORD CharLevel, WORD SpawnLevel, BYTE SpawnType)
{
	if (PVPServer!=PVP_NONE && SpawnType==0)
	{
		// whiny fuckin baby pvp server logic
		if (CharLevel <= 5)
		{
			if (SpawnLevel > 5)
				return CONCOLOR_RED;
			return CONCOLOR_GREEN;
		}
		if (SpawnLevel < 5)
			return CONCOLOR_GREEN;
		
      int Diff = SpawnLevel-CharLevel;
      if (PVPServer==PVP_TEAM) {
		  // TODO: consider teams...
		  if (Diff<=8)
		  {
			  if (Diff>=-8) 
				  return CONCOLOR_BLACK;
			  return CONCOLOR_GREEN;
		  }
		  return CONCOLOR_RED;
      } else if (PVPServer==PVP_RALLOS) {
		  if (Diff<=4)
		  {
			  if (Diff>=-4)
				  return CONCOLOR_BLACK;
			  return CONCOLOR_GREEN;
		  }
		  return CONCOLOR_RED;
      } else if (PVPServer==PVP_SULLON) {
		  if (Diff<=5)
		  {
			  if (Diff>=-5)
				  return CONCOLOR_BLACK;
			  return CONCOLOR_GREEN;
		  }
		  return CONCOLOR_RED;
      } 
	}
    int ConLevels[][3] = {
    //  {Lv,Grn,LtB},
        { 7, -4, -4},
        {10, -5, -4},
        {12, -6, -5},
        {22, -7, -5},
        {24, -9, -7},
        {35,-13,-10},
        {40,-14,-11},
        {42,-15,-11},
        {44,-16,-12},
        {48,-17,-13},
        {51,-18,-14},
        {54,-19,-15},
        {57,-20,-16},
        {60,-21,-16},
        {65,-21,-16},
        {0,0,0}
    };
    int Diff = SpawnLevel-CharLevel;
    int i;
//  DebugSpew("ConColor - Char = %d, Spawn = %d, Diff = %d",CharLevel, SpawnLevel, Diff);
    if (Diff==0) return CONCOLOR_BLACK;
    if (Diff>0) {
        if (Diff<3) return CONCOLOR_YELLOW;
        return CONCOLOR_RED;
    }

    for (i=0;ConLevels[i][0]!=0;i++) {
        if (CharLevel<=ConLevels[i][0]) {
//          DebugSpew("ConColor - i = %d",i);
            if (Diff>ConLevels[i][2]) return CONCOLOR_BLUE;
            if (Diff>ConLevels[i][1]) return CONCOLOR_LIGHTBLUE;
            return CONCOLOR_GREEN;
        }
    }

    return COLOR_PURPLE;

}

PCONTENTS GetEnviroContainer()
{
//   PEQ_CONTAINERWND_MANAGER pContainerMgr = 0;
	if (!ppContainerMgr || !pContainerMgr) return NULL;
	PEQ_CONTAINERWND_MANAGER ContainerMgr=(PEQ_CONTAINERWND_MANAGER)pContainerMgr;
   if(!ContainerMgr->pWorldContents) return NULL;
   return ContainerMgr->pWorldContents;
}

PEQCONTAINERWINDOW FindContainerForContents(PCONTENTS pContents)
{
   if (!ppContainerMgr || !pContainerMgr) return NULL;
   PEQ_CONTAINERWND_MANAGER pMgr = (PEQ_CONTAINERWND_MANAGER)pContainerMgr;

   for (int j = 0; j < 25; j++)
   {
      if (pMgr->pPCContainers[j]->pContents == pContents)
         return (pMgr->pPCContainers[j]);
   }
   return NULL;
}

// ***************************************************************************
// FindMount(PSPAWNINFO) - Used to find the mount of a spawn, if one
//                         exists. returns the spawn if one does not.
// ***************************************************************************
PSPAWNINFO FindMount(PSPAWNINFO pSpawn)
{
   if (!ppSpawnList || !pSpawnList) return NULL;
   PSPAWNINFO pChar = NULL;
   PSPAWNINFO pSpawnInfo = (PSPAWNINFO)pSpawnList;
   CHAR szName[MAX_STRING] = {0};
   CHAR szTemp[MAX_STRING] = {0};


   sprintf(szName, "%s`s Mount",pSpawn->Name);

   for (pChar = pSpawnInfo; pChar; pChar=pChar->pNext) {
      strcpy(szTemp,pChar->Name);
      if (strstr(strlwr(szTemp),"'s mount"))
         WriteChatColor(szTemp,USERCOLOR_WHO);

      if (!stricmp(CleanupName(szTemp, FALSE), szName)) {
         return pChar;
      }
   }


   return pSpawn;
}

// ***************************************************************************
// FindSpeed(PSPAWNINFO) - Used to find the speed of a Spawn taking a mount into
//                               consideration.
// ***************************************************************************

FLOAT FindSpeed(PSPAWNINFO pSpawn)
{
   PSPAWNINFO pMount = NULL;
    FLOAT fRunSpeed = 0;

    pMount=FindMount(pSpawn);

   if (pMount)
     if(!fRunSpeed)
         fRunSpeed = pMount->SpeedRun * 10000 / 70;


   return fRunSpeed;
}





VOID GetItemLinkHash(PCONTENTS Item, PCHAR Buffer)
{
	((EQ_Item*)Item)->GetItemLinkHash(Buffer);
}

VOID GetItemLink(PCONTENTS Item, PCHAR Buffer)
{
	char hash[256];
	((EQ_Item*)Item)->GetItemLinkHash(hash);

	sprintf(Buffer,"%c0%s%s%c",0x12,hash,Item->Item->Name,0x12);
	DebugSpew("GetItemLink() returns '%s'",&Buffer[0]);
}

PCHAR GetLoginName() 
{ 
   CHAR equname[MAX_STRING] = {0}; 
   CHAR szTemp[MAX_STRING] = {0}; 
   GetEQPath(gszEQPath);
   sprintf(equname, "%s\\equname.txt", gszEQPath); 
   DebugSpew("equname = %s",equname); 
   FILE *fequname = fopen("equname.txt", "rt"); 
   if(fequname) { 
      while (!feof(fequname)) { 
         fgets(szTemp,MAX_STRING,fequname); 
      }
      fclose(fequname); 
	  return strdup(szTemp);
   }
   return NULL;
}

VOID STMLToPlainText(PCHAR in, PCHAR out)
{
   DWORD pchar_in_string_position = 0;
   DWORD pchar_out_string_position = 0;
   DWORD pchar_amper_string_position = 0;
   CHAR Amper[2048] = {0};
   while(in[pchar_in_string_position]!=0) {
	   switch (in[pchar_in_string_position]) {
		   case '<':
			   while (in[pchar_in_string_position]!='>')
				   pchar_in_string_position++;
			   pchar_in_string_position++;
			   break;
		   case '&':
			   pchar_in_string_position++;
			   pchar_amper_string_position = 0;
			   ZeroMemory(Amper,2048);
			   while (in[pchar_in_string_position]!=';') {
				   Amper[pchar_amper_string_position++] = in[pchar_in_string_position++];
			   }
			   pchar_in_string_position++;
			   if (!stricmp(Amper,"nbsp")) {
				   out[pchar_out_string_position++] = ' ';
			   } else if (!stricmp(Amper,"amp")) {
				   out[pchar_out_string_position++] = '&';
			   } else if (!stricmp(Amper,"gt")) {
				   out[pchar_out_string_position++] = '>';
			   } else if (!stricmp(Amper,"lt")) {
				   out[pchar_out_string_position++] = '<';
			   } else if (!stricmp(Amper,"quot")) {
				   out[pchar_out_string_position++] = '\"';
			   } else if (!stricmp(Amper,"pct")) {
				   out[pchar_out_string_position++] = '%';
			   } else {
				   out[pchar_out_string_position++] = '?';
			   }
			   break;

		   default:
				out[pchar_out_string_position++] = in[pchar_in_string_position++];
	   }
   }
	out[pchar_out_string_position++] = 0;
}


VOID ClearSearchSpawn(PSEARCHSPAWN pSearchSpawn)
{
    if (!pSearchSpawn) return;
    pSearchSpawn->MinLevel = 0;
    pSearchSpawn->MaxLevel = 100;
    pSearchSpawn->SpawnType = SPAWN_ANY;
    pSearchSpawn->SpawnID = 0;
    pSearchSpawn->Radius = 0.0f;
    pSearchSpawn->szName[0] = 0;
    pSearchSpawn->szBodyType[0] = 0;
    pSearchSpawn->szClass[0] = 0;
    pSearchSpawn->szRace[0] = 0;
    pSearchSpawn->GuildID = 0xFFFF;
    pSearchSpawn->bNotNearAlert = FALSE;
    pSearchSpawn->bNearAlert = FALSE;
    pSearchSpawn->bNoAlert = FALSE;
    pSearchSpawn->bAlert = FALSE;
    pSearchSpawn->bLight = FALSE;
    pSearchSpawn->bTargInvis = FALSE;
    pSearchSpawn->bTargNext = FALSE;
    pSearchSpawn->bTargPrev = FALSE;
    pSearchSpawn->bLFG = FALSE;
	pSearchSpawn->bGroup = FALSE;
    pSearchSpawn->bTrader = FALSE;
    pSearchSpawn->NotID = 0;
    pSearchSpawn->NotNearAlertList = 0;
    pSearchSpawn->NearAlertList = 0;
    pSearchSpawn->NoAlertList = 0;
    pSearchSpawn->AlertList = 0;
    pSearchSpawn->ZRadius = 10000.0f;
    pSearchSpawn->FRadius = 10000.0f;
    pSearchSpawn->xLoc = 0.0f;
    pSearchSpawn->yLoc = 0.0f;
    pSearchSpawn->bKnownLocation = FALSE;
    pSearchSpawn->FromSpawnID = 0;
    pSearchSpawn->bNoPet = FALSE; 
    pSearchSpawn->SortBy = 0; 
}

// *************************************************************************** 
// Function:    DistanceToPoint 
// Description: Return the distance between a spawn and the specified point 
// *************************************************************************** 
FLOAT DistanceToPoint(PSPAWNINFO pSpawn, FLOAT xLoc, FLOAT yLoc) 
{ 
   FLOAT X = pSpawn->X - xLoc; 
   FLOAT Y = pSpawn->Y - yLoc; 
   return sqrtf(X*X + Y*Y); 
}


// *************************************************************************** 
// Function:    ShowSpellSlotInfo
// Author:      Koad (used in his SpellSearch Plugin)
// *************************************************************************** 
PCHAR ShowSpellSlotInfo(PSPELL pSpell, PCHAR szBuffer) 
{ 
   CHAR szTemp[MAX_STRING]={0}; 
   CHAR szBuff[MAX_STRING]={0}; 
   int szBase=0; 
   bool bSlotIsPH=false; 
   PITEMDB ItemDB=gItemDB; 

   for (int i=0; i<=11; i++) 
   { 
      sprintf(szTemp, "Slot %d: ", i+1); 
      strcpy(szBuff, szTemp); 
      bSlotIsPH=false; 
      switch(pSpell->Attrib[i]) 
      { 
      case 0: //hp +/-: heals/regen/dd 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Hitpoints by "); 
         SlotValueCalculate(szBuff, pSpell, i, 1); 
         if ( pSpell->DurationValue1 > 0 ) strcat(szBuff, " per tick"); 
         break; 
      case 1: //ac mod 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "AC by "); 
         SlotValueCalculate(szBuff, pSpell, i, 0.3); 
         break; 
      case 2: //attack mod 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "ATK by "); 
         SlotValueCalculate(szBuff, pSpell, i, 1); 
         break; 
      case 3: //movement speed mod 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Movement by "); 
         if ( pSpell->Max[i] == 0 ) { 
            _itoa(abs(pSpell->Base[i]), szTemp, 10); strcat(szBuff, szTemp); 
         } else { 
            SlotValueCalculate(szBuff, pSpell, i, 1); 
         } 
         strcat(szBuff, "%"); 
         break; 
      case 4: //str mod 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "STR by "); 
         SlotValueCalculate(szBuff, pSpell, i, 1); 
         break; 
      case 5: //dex mod 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "DEX by "); 
         SlotValueCalculate(szBuff, pSpell, i, 1); 
         break; 
      case 6: //agi mod 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "AGI by "); 
         SlotValueCalculate(szBuff, pSpell, i, 1); 
         break; 
      case 7: //sta mod 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "STA by "); 
         SlotValueCalculate(szBuff, pSpell, i, 1); 
         break; 
      case 8: //int mod 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "INT by "); 
         SlotValueCalculate(szBuff, pSpell, i, 1); 
         break; 
      case 9: //wis mod 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "WIS by "); 
         SlotValueCalculate(szBuff, pSpell, i, 1); 
         break; 
      case 10: //old lure slot: leaving this since even though patched, som 
              //spells still have a lure effect slot when base = (-6) 
              //this slot is also charisma 
         if ( (abs(pSpell->Base[i]) > 0) && (pSpell->Base[i] != -6) ) { 
            if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
            if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
            strcat(szBuff, "CHA by "); 
            SlotValueCalculate(szBuff, pSpell, i, 1); 
         } else { 
            if (pSpell->Base[i] == -6 ){ 
               strcat(szBuff, "Lure(6)"); 
            } else { 
               bSlotIsPH=true; 
            } 
         } 
         break; 
      case 11: //haste mod 
         szBase=pSpell->Max[i]-100; 
         if ( szBase < 0 ) strcat(szBuff, "Decrease "); 
         if ( szBase > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Attack Speed by "); 
         _itoa(abs(szBase), szTemp, 10); strcat(szBuff, szTemp); 
         strcat(szBuff, "%"); 
         break; 
      case 12: //Invisibility 
         sprintf(szTemp, "Invisibility(%d)", pSpell->Base[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 13: //See Invisible(c) 
         sprintf(szTemp, "See Invisible(%d)", pSpell->Base[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 15: //mana +/- 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Mana by "); 
         SlotValueCalculate(szBuff, pSpell, i, 1); 
         if ( pSpell->DurationValue1 > 0 ) strcat(szBuff, " per tick"); 
         break; 
      case 18: //Pacify 
         strcat(szBuff, "Pacify"); 
         break; 
      case 19: //faction 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Faction by "); 
         SlotValueCalculate(szBuff, pSpell, i, 1); 
         break; 
      case 21: //stun  time = base in ms 
         sprintf(szTemp, "Stun(%.1f sec/%d)", (float)(pSpell->Base[i] / 1000), pSpell->Max[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 22: //Charm(c/level) 
         sprintf(szTemp, "Charm(%d/%d)", pSpell->Base[i], pSpell->Max[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 23: //Fear(c) 
         sprintf(szTemp, "Fear(%d)", pSpell->Base[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 26: //Gate 
         strcat(szBuff, "Gate"); 
         break; 
      case 27: //Cancel Magic(c) 
         sprintf(szTemp, "Cancel Magic(%d)", pSpell->Base[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 28: //Invisibility versus Undead 
         sprintf(szTemp, "Invisibility versus Undead(%d)", pSpell->Base[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 29: //Invisibility versus Animal 
         sprintf(szTemp, "Invisibility versus Animal(%d)", pSpell->Base[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 30: //Frenzy Radius(c/level) 
         sprintf(szTemp, "Frenzy Radius(%d/%d)", pSpell->Base[i], pSpell->Max[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 31: //Mesmerize(c/level) 
         sprintf(szTemp, "Mesmerize(%d/%d)", pSpell->Base[i], pSpell->Max[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 32: //Summon Item 
         while ((ItemDB) && ((DWORD)pSpell->Base[i] != ItemDB->ID)) { 
            ItemDB = ItemDB->pNext; 
         } 
         if (ItemDB) { 
            strcpy(szTemp,ItemDB->szName); 
         } else { 
            sprintf(szTemp,"Unknown%d",(DWORD)pSpell->Base[i]); 
         } 
         strcat(szBuff, "Summon Item: ");   strcat(szBuff, szTemp); 
         break; 
      case 33: //Summon Pet 
         sprintf(szTemp, "Summon Pet: %s", pSpell->Extra); 
         strcat(szBuff, szTemp); 
         break; 
      case 35: //disease counters 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Disease Counter by "); 
         SlotValueCalculate(szBuff, pSpell, i, 1); 
         break; 
      case 36: //poison counters 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Poison Counter by "); 
         SlotValueCalculate(szBuff, pSpell, i, 1); 
         break; 
      case 40: //Invulnerability 
         strcat(szBuff, "Invulnerability"); 
         break; 
      case 41: //Destroy Target 
         strcat(szBuff, "Destroy Target"); 
         break; 
      case 42: //Shadowstep(c) 
         sprintf(szTemp, "Shadowstep(%d)", pSpell->Base[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 44: //Lycanthropy 
         strcat(szBuff, "Lycanthropy"); 
         break; 
      case 46: //fire resist 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Fire Resist by "); 
         SlotValueCalculate(szBuff, pSpell, i , 1); 
         break; 
      case 47: //cold resist 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Cold Resist by "); 
         SlotValueCalculate(szBuff, pSpell, i , 1); 
         break; 
      case 48: //poison resist 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Poison Resist by "); 
         SlotValueCalculate(szBuff, pSpell, i , 1); 
         break; 
      case 49: //disease resist 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Disease Resist by "); 
         SlotValueCalculate(szBuff, pSpell, i , 1); 
         break; 
      case 50: //magic resist 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Magic Resist by "); 
         SlotValueCalculate(szBuff, pSpell, i , 1); 
         break; 
      case 52: //Sense Undead 
         strcat(szBuff, "Sense Undead"); 
         break; 
      case 53: //Sense Summoned 
         strcat(szBuff, "Sense Summoned"); 
         break; 
      case 54: //Sense Animals 
         strcat(szBuff, "Sense Animals"); 
         break; 
      case 55: //most runes 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Absorb Damage by "); 
         SlotValueCalculate(szBuff, pSpell, i , 1); 
         break; 
      case 56: //True North 
         strcat(szBuff, "True North"); 
         break; 
      case 57: //Levitate(c) 
         sprintf(szTemp, "Levitate(%d)", pSpell->Base[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 58: //Illusion: Base=Race 
         strcat(szBuff, "Illusion: "); strcat(szBuff, pEverQuest->GetRaceDesc(pSpell->Base[i])); 
         break; 
      case 59: //damage shield 
         //base value sign has opposite effect.. 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Damage Shield by "); 
         SlotValueCalculate(szBuff, pSpell, i, 1); 
         break; 
      case 61: //Identify 
         strcat(szBuff, "Identify"); 
         break; 
      case 63: //Memblur e% 
         sprintf(szTemp, "Memblur %d", pSpell->Base[i]); 
         strcat(szBuff, szTemp); 
         strcat(szBuff, "%"); 
         break; 
      case 64: //SpinStun 
         strcat(szBuff, "SpinStun"); 
         break; 
      case 65: //Infravision 
         strcat(szBuff, "Infravision"); 
         break; 
      case 66: //ultravision 
         strcat(szBuff, "Ultravision"); 
         break; 
      case 67: //Eye of Zomm 
         strcat(szBuff, "Eye Of Zomm"); 
         break; 
      case 68: //reclaim 
         strcat(szBuff, "Reclaim Mana"); 
         break; 
      case 69: //max hp mod 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Max Hitpoints by "); 
         SlotValueCalculate(szBuff, pSpell, i , 1); 
         break; 
      case 71: //Summon Skeleton Pet 
         sprintf(szTemp, "Summon Skeleton Pet: %s", pSpell->Extra); 
         strcat(szBuff, szTemp); 
         break; 
      case 73: //Bind Sight 
         strcat(szBuff, "Bind Sight"); 
         break; 
      case 75: //Voice Graft 
         strcat(szBuff, "Voice Graft"); 
         break; 
      case 76: //Sentinel 
         strcat(szBuff, "Sentinel"); 
         break; 
      case 77: //Locate Corpse 
         strcat(szBuff, "Locate Corpse"); 
         break; 
      case 78: //Absorb Magic Damage 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Absorb Magic Damage by "); 
         SlotValueCalculate(szBuff, pSpell, i , 1); 
         break; 
      case 79: //+hp when cast (priest buffs that have heal component, DoTs with DDs) 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "HP when cast by "); 
         SlotValueCalculate(szBuff, pSpell, i , 1); 
         break; 
      case 81: //Resurrection 
         sprintf(szTemp, "Resurrect and restore %d&pct experience", pSpell->Base[i]); 
         strcat(szBuff, szTemp); 
      case 82: //Summon Player 
         strcat(szBuff, "Summon Player"); 
         break; 
      case 83: //zone portal spells 
         sprintf(szTemp, "Teleport to %d, %d, %d in %s facing %s", 
            pSpell->Base[1], pSpell->Base[2], pSpell->Base[3], pSpell->Extra, szHeading[pSpell->Base[4]]); 
         strcat(szBuff, szTemp); 
         break; 
      case 84: //Toss on Z axis 
         //base value sign has opposite effect.. 
         if ( pSpell->Base[i] > 0 ) sprintf(szTemp, "Toss Down(%d)", abs(pSpell->Base[i])); 
         if ( pSpell->Base[i] < 0 ) sprintf(szTemp, "Toss Up(%d)", abs(pSpell->Base[i])); 
         strcat(szBuff, szTemp); 
         break; 
      case 85: //Add Proc 
         sprintf(szTemp,"Add Proc: %s (id: %d)", GetSpellNameByID(pSpell->Base[i]), pSpell->Base[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 86: //Reaction Radius(c/level) 
         sprintf(szTemp, "Reaction Radius(%d/%d)", pSpell->Base[i], pSpell->Max[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 87: //perspective magnification 
         szBase=pSpell->Base[i]-100; 
         if ( szBase < 0 ) strcat(szBuff, "Decrease "); 
         if ( szBase > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Magnification by "); 
         _itoa(abs(szBase), szTemp, 10); strcat(szBuff, szTemp); 
         strcat(szBuff, "%"); 
         break; 
      case 88: //evac portal spells 
         sprintf(szTemp, "Evacuate to %d, %d, %d in %s facing %s", 
            pSpell->Base[1], pSpell->Base[2], pSpell->Base[3], pSpell->Extra, szHeading[pSpell->Base[4]]); 
         strcat(szBuff, szTemp); 
         break; 
      case 89: //player size 
         szBase=pSpell->Base[i]-100; 
         if ( szBase < 0 ) strcat(szBuff, "Decrease "); 
         if ( szBase > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Player Size by "); 
         _itoa(abs(szBase), szTemp, 10); strcat(szBuff, szTemp); 
         strcat(szBuff, "%"); 
         break; 
      case 90: //Cloak 
         strcat(szBuff, "Cloak"); 
         break; 
      case 91: //Summon Corpse 
         strcat(szBuff, "Summon Corpse"); 
         break; 
      case 92: //hate mod 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Hate by "); 
         SlotValueCalculate(szBuff, pSpell, i, 1); 
         break; 
      case 93: //Stop Rain 
         strcat(szBuff, "Stop Rain"); 
         break; 
      case 95: //Sacrifice 
         strcat(szBuff, "Sacrifice"); 
         break; 
      case 96: //Silence 
         strcat(szBuff, "Silence"); 
         break; 
      case 97: //mana pool 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Mana Pool by "); 
         SlotValueCalculate(szBuff, pSpell, i, 1); 
         break; 
      case 98:  //Haste v2 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Haste v2 by "); 
         _itoa(abs(pSpell->Base[i]), szTemp, 10); strcat(szBuff, szTemp); 
         strcat(szBuff, "%"); 
         break; 
      case 99: //Root 
         strcat(szBuff, "Root"); 
         break; 
      case 100: //hp mod: pet heals/regen 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Hitpoints v2 by "); 
         SlotValueCalculate(szBuff, pSpell, i, 1); 
         if ( pSpell->DurationValue1 > 0 ) strcat(szBuff, " per tick"); 
         break; 
      case 101: //Complete Heal (with duration) 
         strcat(szBuff, "Complete Heal (with duration)"); 
         break; 
      case 102: //Fearless 
         strcat(szBuff, "Fearless"); 
         break; 
      case 103: //Call Pet 
         strcat(szBuff, "Call Pet"); 
         break; 
      case 104: //zone translocate spells 
         sprintf(szTemp, "Translocate to %d, %d, %d in %s facing %s", 
            pSpell->Base[1], pSpell->Base[2], pSpell->Base[3], pSpell->Extra, szHeading[pSpell->Base[4]]); 
         strcat(szBuff, szTemp); 
         break; 
      case 108: //Summon Familiar 
         sprintf(szTemp, "Summon Familiar: %s", pSpell->Extra); 
         strcat(szBuff, szTemp); 
         break; 
      case 112: //Effective Casting Level 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Effective Casting Level by "); 
         SlotValueCalculate(szBuff, pSpell, i , 1); 
         break; 
      case 111: //resist all 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "All Resists by "); 
         SlotValueCalculate(szBuff, pSpell, i , 1); 
         break; 
      case 114: //aggro multiplier 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Aggro Multiplier by "); 
         _itoa(abs(pSpell->Base[i]), szTemp, 10); strcat(szBuff, szTemp); 
         strcat(szBuff, "%"); 
         break; 
      case 115: //Food/Water 
         strcat(szBuff, "Food/Water"); 
         break; 
      case 116: //curse counters 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Curse Counter by "); 
         SlotValueCalculate(szBuff, pSpell, i, 1); 
         break; 
      case 118: //Singing Skill 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Singing Skill by "); 
         SlotValueCalculate(szBuff, pSpell, i, 1); 
         break; 
      case 119: //bard overhaste 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Haste v3 by "); 
         _itoa(abs(pSpell->Base[i]), szTemp, 10); strcat(szBuff, szTemp); 
         strcat(szBuff, "%"); 
         break; 
      case 120: //Reduce Healing Effectiveness (%) 
         strcat(szBuff, "Reduce Healing Effectiveness "); 
         _itoa(abs(pSpell->Base[i]), szTemp, 10); strcat(szBuff, szTemp); 
         strcat(szBuff, "%"); 
         break; 
      case 121: //Reverse Damage Shield 
         sprintf(szTemp, "Reverse Damage Shield (%d)", abs(pSpell->Base[i])); 
         strcat(szBuff, szTemp); 
         break; 
      case 124: //spell damage 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Spell Damage by "); 
         _itoa(abs(pSpell->Base[i]), szTemp, 10); strcat(szBuff, szTemp); 
         strcat(szBuff, "%"); 
         break; 
      case 125: //healing 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Healing by "); 
         _itoa(abs(pSpell->Base[i]), szTemp, 10); strcat(szBuff, szTemp); 
         strcat(szBuff, "%"); 
         break; 
      case 127: //spell haste 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Spell Haste by "); 
         _itoa(abs(pSpell->Base[i]), szTemp, 10); strcat(szBuff, szTemp); 
         strcat(szBuff, "%"); 
         break; 
      case 128: //spell duration 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Spell Duration by "); 
         _itoa(abs(pSpell->Base[i]), szTemp, 10); strcat(szBuff, szTemp); 
         strcat(szBuff, "%"); 
         break; 
      case 129: //spell range 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Spell Range by "); 
         _itoa(abs(pSpell->Base[i]), szTemp, 10); strcat(szBuff, szTemp); 
         strcat(szBuff, "%"); 
         break; 
      case 130: //spell/bash hate 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Spell/Bash Hate by "); 
         _itoa(abs(pSpell->Base[i]), szTemp, 10); strcat(szBuff, szTemp); 
         strcat(szBuff, "%"); 
         break; 
      case 132: //Spell Mana Cost - signs reversed 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Spell Mana Cost by "); 
         _itoa(abs(pSpell->Base[i]), szTemp, 10); strcat(szBuff, szTemp); 
         strcat(szBuff, "%"); 
         break; 
      case 134: //limit max level 
         sprintf(szTemp, "Limit: Max Level(%d)", pSpell->Base[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 135: //Limit: Resist Fire Allowed 
         strcat(szBuff, "Limit: Resist Fire allowed"); 
         break; 
      case 136: //limit target types this affects 
         strcat(szBuff, "Limit: Target("); 
         switch(abs(pSpell->Base[i])) 
         { 
         case 0: 
            strcat(szBuff, "Rag`Zhezum Special"); 
            break; 
         case 1: 
            strcat(szBuff, "Line of Sight"); 
            break; 
         case 2: 
            strcat(szBuff, "AE PC v1"); 
            break; 
         case 3: 
            strcat(szBuff, "Group v1"); 
            break; 
         case 4: 
            strcat(szBuff, "PBAE"); 
            break; 
         case 5: 
            strcat(szBuff, "Single"); 
            break; 
         case 6: 
            strcat(szBuff, "Self"); 
            break; 
         case 8: 
            strcat(szBuff, "Targeted AE"); 
            break; 
         case 9: 
            strcat(szBuff, "Animal"); 
            break; 
         case 10: 
            strcat(szBuff, "Undead"); 
            break; 
         case 11: 
            strcat(szBuff, "Summoned"); 
            break; 
         case 13: 
            strcat(szBuff, "Lifetap"); 
            break; 
         case 14: 
            strcat(szBuff, "Pet"); 
            break; 
         case 15: 
            strcat(szBuff, "Corpse"); 
            break; 
         case 16: 
            strcat(szBuff, "Plant"); 
            break; 
         case 17: 
            strcat(szBuff, "Uber Giants"); 
            break; 
         case 18: 
            strcat(szBuff, "Uber Dragons"); 
            break; 
         case 20: 
            strcat(szBuff, "Targeted AE, Tap"); 
            break; 
         case 24: 
            strcat(szBuff, "AE Undead"); 
            break; 
         case 25: 
            strcat(szBuff, "AE Summoned"); 
            break; 
         case 40: 
            strcat(szBuff, "AE PC v2"); 
            break; 
         case 41: 
            strcat(szBuff, "Group v2"); 
            break; 
         default: 
            sprintf(szTemp, "Unknown%03d", pSpell->Base[i]); 
            strcat(szBuff, szTemp); 
            break; 
         } 
         if ( pSpell->Base[i] > 0 )  strcat(szBuff, " allowed"); 
         if ( pSpell->Base[i] < 0 )  strcat(szBuff, " excluded"); 
         strcat(szBuff, ")"); 
         break; 
      case 137: //limit effect types this affects 
         strcat(szBuff, "Limit: Effect("); 
         switch(abs(pSpell->Base[i])) 
         { 
         case 0: 
            strcat(szBuff,"Hitpoints"); 
            break; 
         case 40: 
            strcat(szBuff,"Invunerability"); 
            break; 
         case 86: 
            strcat(szBuff,"Reaction Radius"); 
            break; 
         case 101: 
            strcat(szBuff,"Complete Heal (with duration)"); 
            break; 
         case 147: 
            strcat(szBuff,"Percentage Heal"); 
            break; 
         default: 
            sprintf(szTemp, "Unknown%d", pSpell->Base[i]); 
            strcat(szBuff,szTemp); 
            break; 
         } 
         if ( pSpell->Base[i] > 0 )  strcat(szBuff, " allowed"); 
         if ( pSpell->Base[i] < 0 )  strcat(szBuff, " excluded"); 
         strcat(szBuff, ")"); 
         break; 
      case 138: //limit spelltype this affects 
         strcat(szBuff, "Limit: SpellType("); 
         switch(pSpell->Base[i]) 
         { 
         case 0: 
            strcat(szBuff,"Detrimental only"); 
            break; 
         case 1: 
            strcat(szBuff,"Beneficial only"); 
            break; 
         case 2: 
            strcat(szBuff,"Beneficial - Group Only"); 
            break; 
         default: 
            sprintf(szTemp, "Unknown%03d", pSpell->Base[i]); 
            strcat(szBuff,szTemp); 
            break; 
         } 
         strcat(szBuff, ")"); 
         break; 
      case 139: //limit spell this affects 
         strcat(szBuff, "Limit: Spell("); 
         // changed this case to work for any future changes by referencing 
         // the spell array for the name instead of hardcoded names 
         strcat(szBuff, GetSpellByID(abs(pSpell->Base[i]))->Name); 
         if ( pSpell->Base[i] > 0 )  strcat(szBuff, " allowed"); 
         if ( pSpell->Base[i] < 0 )  strcat(szBuff, " excluded"); 
         strcat(szBuff, ")"); 
         break; 
      case 140: //limit min duration of spells this affects (base= #ticks) 
         sprintf(szTemp, "Limit: Min Duraction(%d sec)", (pSpell->Base[i] *6)); 
         strcat(szBuff, szTemp); 
         break; 
      case 141: //limit to instant spells only 
         strcat(szBuff, "Limit: Instant spells only"); 
         break; 
      case 143: //limit min casting time of spells this affects (base= seconds in ms) 
         sprintf(szTemp, "Limit: Min Cast Time(%.1f sec)", (float)(pSpell->Base[i] / 1000)); 
         strcat(szBuff, szTemp); 
         break; 
      case 147: //Hit Points (75% Max) 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         sprintf(szTemp, "Hitpoints by %d (%dpct max)", pSpell->Max[i], pSpell->Base[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 148: //Stacking 149 is stacking too 
         sprintf(szTemp, "Stacking: Block new spell if slot %d is effect ", pSpell->Calc[i]-200); 
         strcat(szBuff, szTemp); 
         switch(pSpell->Base[i]) 
         { 
         case 1: 
            strcat(szBuff,"'AC'"); 
            break; 
         case 2: 
            strcat(szBuff,"'ATK'"); 
            break; 
         case 59: 
            strcat(szBuff,"'Damage Shield'"); 
            break; 
         case 69: 
            strcat(szBuff,"'Max Hitpoints'"); 
            break; 
         default: 
            sprintf(szTemp, "Unknown%03d", pSpell->Base[i]); 
            strcat(szBuff,szTemp); 
            break; 
         } 
         if ( pSpell->Max[i] > 0) { 
            strcat(szBuff, " and < "); 
            _itoa(abs(pSpell->Max[i]), szTemp, 10); 
            strcat(szBuff, szTemp); 
         } 
         break; 
      case 150: //Death Save - Restore Full Health 
         sprintf(szTemp, "Death Save - Restore Full Health"); 
         strcat(szBuff, szTemp); 
         break; 
      case 152: //Summon Pets (swarm) 
         sprintf(szTemp, "Summon Pets: %s x%d for %dsec", pSpell->Extra, pSpell->Base[i], pSpell->Max[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 153: //Balance Party Health 
         sprintf(szTemp, "Balance Party Health(%dpct penalty)", pSpell->Base[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 154: //Remove Detrimental(c) 
         sprintf(szTemp, "Remove Detrimental(%d)", pSpell->Base[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 158: //Chance to Reflect Spell 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Chance to Reflect Spell by "); 
         _itoa(abs(pSpell->Base[i]), szTemp, 10); strcat(szBuff, szTemp); 
         strcat(szBuff, "%"); 
         break; 
      case 254: //placeholder of some kind 
         bSlotIsPH=true; 
         break; 
      default: //undefined effect 
         sprintf(szTemp, "UnknownEffect%03d", pSpell->Attrib[i]); 
         strcat(szBuff,szTemp); 
         break; 
      } 
	  if ( !bSlotIsPH ) {
		  strcat(szBuffer, szBuff);
		  strcat(szBuffer, "<br>" );
	  }
   } 
   return szBuffer;
} 

// *************************************************************************** 
// Function:    SlotValueCalculate 
// Author:      Koad (used in his SpellSearch Plugin)
// Description: Interpret calc formula for spell slot effect i 
// Usage:       Used by ShowSpellSlotInfo to show scaling values 
//              mp = base multiplier (AC effects = 0.3 etc) 
// *************************************************************************** 
VOID SlotValueCalculate(PCHAR szBuff, PSPELL pSpell, int i, double mp) 
{ 
   CHAR szTemp[MAX_STRING]={0}; 
   long szBase=0; 
   long szValue=0; 
   int level=0; 

   //find min level spell is usable 
   int minlevel=1; 
   for (int j=0; j<=16; j++) 
   { 
      if (pSpell->Level[j]>0 && pSpell->Level[j]<=65) { 
         if ( minlevel==1 )  minlevel=pSpell->Level[j]; 
         if ( pSpell->Level[j]<minlevel )  minlevel=pSpell->Level[j]; 
      } 
   } 
    
   //apply base mod for weird effect calcs.. 
   szBase = (long)(pSpell->Base[i] * mp); 

   switch(pSpell->Calc[i]) 
   { 
   case 000: //only a few spells calc byte is 0, but when 
              //it is its the same as 100 in all testing so far 
   case 100: // no calc just value assignment from base 
      _itoa(abs(szBase), szTemp, 10); 
      strcat(szBuff, szTemp); 
      break; 
   case 5: //   Level*5 + Base 
      sprintf(szTemp, "%d (L%d) to ", abs(szBase), minlevel); 
      strcat(szBuff, szTemp); 
      for (level = minlevel; level <= 65; level++) 
      { 
         if ( pSpell->Max[i]==0 ) level=65;    //problem note: celestial elixir, duration, shouldnt show range calc?! 
         szValue = (level * 5) + abs(szBase); 
         if ( abs(szValue) >= abs(pSpell->Max[i]) || level==65 ) 
         { 
            sprintf(szTemp, "%d (L%d)", abs(szValue), level); 
            strcat(szBuff, szTemp); 
            break; 
         } 
      } 
      break; 
   case 6: //   Level*6 + Base 
      sprintf(szTemp, "%d (L%d) to ", abs(szBase), minlevel); 
      strcat(szBuff, szTemp); 
      for (level = minlevel; level <= 65; level++) 
      { 
         if ( pSpell->Max[i]==0 ) level=65;  
         szValue = (level * 6) + abs(szBase); 
         if ( abs(szValue) >= abs(pSpell->Max[i]) || level==65 ) 
         { 
            sprintf(szTemp, "%d (L%d)", abs(szValue), level); 
            strcat(szBuff, szTemp); 
            break; 
         } 
      } 
      break; 
   case 10: //   Level*10 + Base 
      sprintf(szTemp, "%d (L%d) to ", abs(szBase), minlevel); 
      strcat(szBuff, szTemp); 
      //assume max level for PC to NPC comparison (usually no max for this formula) 
      level = 65; 
      szValue = (level * 10) + abs(szBase); 
      sprintf(szTemp, "%d (L%d)", abs(szValue), level); 
      strcat(szBuff, szTemp); 
      break; 
   case 101: // Level/2 + Base 
      sprintf(szTemp, "%d (L%d) to ", abs(szBase), minlevel); 
      strcat(szBuff, szTemp); 
      for (level = minlevel; level <= 65; level++) 
      { 
         if ( pSpell->Max[i]==0 ) level=65;  
         szValue = (long)(level / 2) + abs(szBase); 
         if ( abs(szValue) >= abs(pSpell->Max[i]) || level==65 ) 
         { 
            sprintf(szTemp, "%d (L%d)", abs(szValue), level); 
            strcat(szBuff, szTemp); 
            break; 
         } 
      } 
      break; 
   case 102: // Level + Base 
      sprintf(szTemp, "%d (L%d) to ", abs(szBase), minlevel); 
      strcat(szBuff, szTemp); 
      for (level = minlevel; level <= 65; level++) 
      { 
         if ( pSpell->Max[i] ==0 ) level=65;  
         szValue = level + abs(szBase); 
         if ( abs(szValue) >= abs(pSpell->Max[i]) || level==65 ) { 
            sprintf(szTemp, "%d (L%d)", abs(szValue), level); 
            strcat(szBuff, szTemp); 
            break; 
         } 
      } 
      break; 
   case 103: // Level*2 + Base 
      sprintf(szTemp, "%d (L%d) to ", abs(szBase), minlevel); 
      strcat(szBuff, szTemp); 
      for (level = minlevel; level <= 65; level++) 
      { 
         if ( pSpell->Max[i] ==0 ) level=65;  
         szValue = (level*2) + abs(szBase); 
         if ( abs(szValue) >= abs(pSpell->Max[i]) || level==65 ) { 
            sprintf(szTemp, "%d (L%d)", abs(szValue), level); 
            strcat(szBuff, szTemp); 
            break; 
         } 
      } 
      break; 
   case 104: // Level*3 + Base 
      sprintf(szTemp, "%d (L%d) to ", abs(szBase), minlevel); 
      strcat(szBuff, szTemp); 
      for (level = minlevel; level <= 65; level++) 
      { 
         if ( pSpell->Max[i]==0 ) level=65; 
         szValue = (level*3) + abs(szBase); 
         if ( abs(szValue) >= abs(pSpell->Max[i]) || level==65 ) { 
            sprintf(szTemp, "%d (L%d)", abs(szValue), level); 
            strcat(szBuff, szTemp); 
            break; 
         } 
      } 
      break; 
   case 105: // Level*4 + Base 
      sprintf(szTemp, "%d (L1) to ", abs(szBase)); 
      strcat(szBuff, szTemp); 
      level = 65; 
      szValue = (level * 4) + abs(szBase); 
      sprintf(szTemp, "%d (L%d)", abs(szValue), level); 
      strcat(szBuff, szTemp); 
      break; 
   case 109: // Skill/16 + Base ?? 
      sprintf(szTemp, "%d (L1) to ", abs(szBase)); 
      strcat(szBuff, szTemp); 
      level=65; 
      szValue = ((long)(235/16)) + abs(szBase); 
      sprintf(szTemp, "%d (L%d)", szValue, level); 
      strcat(szBuff, szTemp); 
      break; 
   case 110: // Skill/8 + Base 
      sprintf(szTemp, "%d (L1) to ", abs(szBase)); 
      strcat(szBuff, szTemp); 
      level=65; 
      szValue = ((long)(235/8)) + abs(szBase); 
      sprintf(szTemp, "%d (L%d)", szValue, level); 
      strcat(szBuff, szTemp); 
      break; 
   case 123: // Base to Max (random) 
      sprintf(szTemp, "%d to %d (random)", abs(szBase), abs(pSpell->Max[i])); 
      strcat(szBuff, szTemp); 
      break; 
   default: //undefined calc 
      sprintf(szTemp, "UnknownCalc%03d", pSpell->Calc[i]); 
      strcat(szBuff, szTemp); 
      break; 
   } 
} 

