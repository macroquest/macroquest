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

#include "stdafx.h"
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
    if (!gSpewToFile) return;

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

DWORD GetGameState(VOID)
{
	if (!ppEverQuest || !pEverQuest) return 0;
	return *(DWORD*)(0x5B4+pEverQuest);
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



// YES THIS NEEDS TO BE PCXSTR * 
VOID AppendCXStr(PCXSTR *cxstr, PCHAR text) 
{ 
	CXStr *Str=(CXStr*)cxstr;
	(*Str)+=text;
	cxstr=(PCXSTR*)Str;

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
			maxlen=pCXStr->Length;
		strncpy(szBuffer,pCXStr->Text,maxlen);
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

CHAR szUnknownSpell[MAX_STRING] = "Unknown Spell";

PCHAR GetSpellByID(DWORD dwSpellID)
{
    PSPELLLIST pSpell = NULL;
    if (ppSpellMgr == NULL) return szUnknownSpell;
    pSpell =  &(*((PSPELLPOINTER)pSpellMgr)->Spells[dwSpellID]);
    if (pSpell != NULL) {
        if (pSpell->Name != NULL) {
            if (pSpell->Name[0]!='\0') {
                return pSpell->Name;
            }
        }
    }
    return szUnknownSpell;
}

PSPELLLIST GetSpellByName(PCHAR szName)
{
    PSPELLLIST pSpell = NULL;
    if (ppSpellMgr == NULL) return NULL;
    for (DWORD dwSpellID = 0; dwSpellID < TOTAL_SPELL_COUNT; dwSpellID++) {
        pSpell = &(*((PSPELLPOINTER)pSpellMgr)->Spells[dwSpellID]);
        if ((pSpell->ID > 0) && (pSpell->ID < TOTAL_SPELL_COUNT)) {
            if (pSpell->Name != NULL) {
                if (!_stricmp(szName, pSpell->Name)) {
                    return pSpell;
                }
            }
        }
    }
    return NULL;
}

DWORD GetSpellDuration(PSPELLLIST pSpell, PSPAWNINFO pSpawn)
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
DWORD ConColor(WORD CharLevel, WORD SpawnLevel)
{

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

DWORD GetMaxMana(VOID)
{
	return pCharData->Max_Mana();
	/*
//	FunctionEntry("GetMaxMana()");
    DWORD MaxMana = 0;
    DWORD CharInfo = NULL;
	if (!EQADDR_CHAR_INFO || !*EQADDR_CHAR_INFO) {	return 0;}
    CharInfo = (DWORD)*EQADDR_CHAR_INFO;
#if defined(_MSC_VER)
    __asm {
        push eax;
        push ecx;
        mov ecx, dword ptr [CharInfo];
        call dword ptr [EQADDR_MAXMANA];
        movsx eax, ax;
        mov [MaxMana], eax;
        pop ecx;
        pop eax;
    }
#else
        __asm__ ("pushl %%eax
                  pushl %%ecx
                  movl %1,%%ecx
                  call %2
                  movsxl %%ax, %0
                  popl %%ecx
                  popl %%eax"
        : "=g"(MaxMana)
        : "g"(CharInfo), "g"(EQADDR_MAXMANA)
        );


#endif
//	FunctionExit("GetMaxMana()");
    return MaxMana;
	*/
}

DWORD GetMaxHPS(VOID)
{
	return pCharData->Max_HP(0);
	/*
    DWORD MaxHPS = 0;
    DWORD CharInfo = NULL;
	if (!EQADDR_CHAR_INFO || !*EQADDR_CHAR_INFO) { return 0;}
    CharInfo = (DWORD)*EQADDR_CHAR_INFO;
    __asm {
        push eax;
        push ecx;
        mov ecx, dword ptr [CharInfo];
		push 0;
        call dword ptr [EQADDR_GETMAXHP];
        mov [MaxHPS], eax;
        pop ecx;
        pop eax;
    }
    return MaxHPS;
	*/
}

DWORD GetCurHPS(VOID)
{
	return pCharData->Cur_HP(0);
	/*
    DWORD CurHPS = 0;
    DWORD CharInfo = NULL;
	if (!EQADDR_CHAR_INFO || !*EQADDR_CHAR_INFO) {return 0;}
    CharInfo = (DWORD)*EQADDR_CHAR_INFO;
    __asm {
        push eax;
        push ecx;
        mov ecx, dword ptr [CharInfo];
		push 0;
        call dword ptr [EQADDR_GETCURHP];
        mov [CurHPS], eax;
        pop ecx;
        pop eax;
    }
    return CurHPS;
	/**/
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
         WriteChatBuffer(szTemp,USERCOLOR_WHO);

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
	/*
	__asm {
		push eax;
		push ecx;
		push Buffer;
		mov ecx, Item;
		call [EQADDR_GETITEMLINKHASH];
		pop ecx;
		pop eax;
	};
	/**/
}

VOID GetItemLink(PCONTENTS Item, PCHAR Buffer)
{
	char hash[256];
	/*
	DWORD haddr=(DWORD)&hash[0];
	__asm {
		push eax;
		push ecx;
		push haddr;
		mov ecx, Item;
		call [EQADDR_GETITEMLINKHASH];
		pop ecx;
		pop eax;
	};
	/**/
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
   CHAR Amper[MAX_STRING] = {0};
   while(in[pchar_in_string_position]!=0 && pchar_in_string_position<MAX_STRING) {
	   switch (in[pchar_in_string_position++]) {
		   case '<':
			   while (in[pchar_in_string_position]!='>' && pchar_in_string_position<MAX_STRING)
				   pchar_in_string_position++;
			   pchar_in_string_position++;
			   break;
		   case '&':
			   pchar_in_string_position++;
			   pchar_amper_string_position = 0;
			   ZeroMemory(Amper,MAX_STRING);
			   while (in[pchar_in_string_position]!=';' && pchar_in_string_position<MAX_STRING) {
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
