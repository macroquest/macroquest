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

VOID WriteChatf(PCHAR szFormat, ...)
{
    CHAR szOutput[MAX_STRING] = {0};
    va_list vaList;
    va_start( vaList, szFormat );
    vsprintf(szOutput,szFormat, vaList);
	WriteChatColor(szOutput);
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

VOID StrReplaceSection(PCHAR szInsert,DWORD Length,PCHAR szNewString)
{
	DWORD NewLength=(DWORD)strlen(szNewString);
	memmove(&szInsert[NewLength],&szInsert[Length],strlen(&szInsert[Length])+1);
	strncpy(szInsert,szNewString,NewLength);
}

VOID ConvertCR(PCHAR Text)
{// not super-efficient but this is only being called at initialization currently.
	while (PCHAR Next=strstr(Text,"\\n"))
	{
		StrReplaceSection(Next,2,"\n");
	}
}

VOID Flavorator(PCHAR szLine)
{
	PCHAR pSpot;
	while(pSpot=strstr(szLine,"%e"))
	{
		StrReplaceSection(pSpot,2,szColorExpletive[rand()%nColorExpletive]);
	}
	while(pSpot=strstr(szLine,"%a"))
	{
		StrReplaceSection(pSpot,2,szColorAdjective[rand()%nColorAdjective]);
	}
	while(pSpot=strstr(szLine,"%y"))
	{
		StrReplaceSection(pSpot,2,szColorAdjectiveYou[rand()%nColorAdjectiveYou]);
	}

}

VOID SyntaxError(PCHAR szFormat, ...)
{
	CHAR szOutput[MAX_STRING] = {0};
    va_list vaList;
    va_start( vaList, szFormat );
    vsprintf(szOutput,szFormat, vaList);
	if (bLaxColor)
	{
		CHAR szColor[MAX_STRING]={0};
		strcpy(szColor,szColorSyntaxError[rand()%nColorSyntaxError]);
		if (szColor[0])
		{
			Flavorator(szColor);
			WriteChatColor(szColor);
		}
	}
	WriteChatColor(szOutput,CONCOLOR_YELLOW);
	strcpy(gszLastSyntaxError,szOutput);
}

VOID MacroError(PCHAR szFormat, ...)
{
	CHAR szOutput[MAX_STRING] = {0};
    va_list vaList;
    va_start( vaList, szFormat );
    vsprintf(szOutput,szFormat, vaList);
	if (bLaxColor)
	{
		CHAR szColor[MAX_STRING]={0};
		strcpy(szColor,szColorMacroError[rand()%nColorMacroError]);
		if (szColor[0])
		{
			Flavorator(szColor);
			WriteChatColor(szColor);
		}
	}
	WriteChatColor(szOutput,CONCOLOR_RED);
	strcpy(gszLastNormalError,szOutput);
	if (gMacroBlock)
	{
		if (bAllErrorsDumpStack || bAllErrorsFatal)
			DumpStack(0,0);
		if (bAllErrorsFatal)
			EndMacro((PSPAWNINFO)pCharSpawn,"");
	}
}

VOID FatalError(PCHAR szFormat, ...)
{
	CHAR szOutput[MAX_STRING] = {0};
    va_list vaList;
    va_start( vaList, szFormat );
    vsprintf(szOutput,szFormat, vaList);
	if (bLaxColor)
	{
		CHAR szColor[MAX_STRING]={0};
		strcpy(szColor,szColorFatalError[rand()%nColorFatalError]);
		if (szColor[0])
		{
			Flavorator(szColor);
			WriteChatColor(szColor);
		}
	}
	WriteChatColor(szOutput,CONCOLOR_RED);
	strcpy(gszLastNormalError,szOutput);
	if (gMacroBlock)
	{
		DumpStack(0,0);
		EndMacro((PSPAWNINFO)pCharSpawn,"");
	}
}

VOID MQ2DataError(PCHAR szFormat, ...)
{
	CHAR szOutput[MAX_STRING] = {0};
    va_list vaList;
    va_start( vaList, szFormat );
    vsprintf(szOutput,szFormat, vaList);
	if (gFilterMQ2DataErrors)
		DebugSpew(szOutput);
	else
	{
		if (bLaxColor)
		{
			CHAR szColor[MAX_STRING]={0};
			strcpy(szColor,szColorMQ2DataError[rand()%nColorMQ2DataError]);
			if (szColor[0])
			{
				Flavorator(szColor);
				WriteChatColor(szColor);
			}
		}
		WriteChatColor(szOutput,CONCOLOR_RED);
	}
	strcpy(gszLastMQ2DataError,szOutput);
	if (gMacroBlock)
	{
		if (bAllErrorsDumpStack || bAllErrorsFatal)
			DumpStack(0,0);
		if (bAllErrorsFatal)
			EndMacro((PSPAWNINFO)pCharSpawn,"");
	}
}

VOID FixStringTable()
{
	PEQSTRINGTABLE pTable=(PEQSTRINGTABLE)pStringTable;
	for (DWORD N=0 ; N<pTable->Count ; N++)
	if (PEQSTRING pStr=pTable->StringItems[N])
	if (PCHAR p=pStr->String)
	{
		while(*p)
			p++;
		p--;
		while(*p==' ' && p!=pStr->String)
		{
			*p=0;
			p--;
		}
	}
}

// ***************************************************************************
// Function:    GetNextArg
// Description: Returns a pointer to the next argument
// ***************************************************************************
PSTR GetNextArg(PCSTR szLine, DWORD dwNumber, BOOL CSV, CHAR Separator)
{
   PCSTR szNext = szLine;
   BOOL CustomSep = FALSE;
   BOOL InQuotes = FALSE;
   if (Separator!=0) CustomSep=TRUE;

   while (
         ((!CustomSep) && (szNext[0] == ' '))
      || ((!CustomSep) && (szNext[0] == '\t'))
      || ((CustomSep) && (szNext[0]==Separator))
      || ((!CustomSep) && (CSV) && (szNext[0]==','))
      ) szNext++;

   if ((INT)dwNumber < 1) return (PSTR)szNext;
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
            return (PSTR)szNext;
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
   return (PSTR)szNext;
}

// ***************************************************************************
// Function:    GetArg
// Description: Returns a pointer to the current argument in szDest
// ***************************************************************************
PSTR GetArg(PSTR szDest, PCSTR szSrc, DWORD dwNumber, BOOL LeaveQuotes, BOOL ToParen, BOOL CSV, CHAR Separator, BOOL AnyNonAlphaNum)
{
   DWORD i=0;
   DWORD j=0;
   BOOL CustomSep = FALSE;
   BOOL InQuotes = FALSE;
   PCSTR szTemp = szSrc;
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






PCHAR GetEQPath(PCHAR szBuffer)
{
    GetModuleFileName(NULL, szBuffer, MAX_STRING);
    PCHAR pSearch=0;
    if (pSearch=strstr(strlwr(szBuffer), "\\wineq\\"))
        *pSearch=0;
	else if (pSearch=strstr(strlwr(szBuffer), "\\testeqgame.exe"))
        *pSearch=0;
    else if (pSearch=strstr(szBuffer, "\\eqgame.exe"))
            *pSearch=0;
    return szBuffer;
}

VOID ConvertItemTags(CXStr &cxstr, BOOL Tag)
{
   __asm{
      push ecx;
      push eax;
	  push [Tag];
	   push [cxstr];
	   call [EQADDR_CONVERTITEMTAGS];
	   pop ecx;
	   pop ecx;
	   pop eax;
	   pop ecx;
   };
}

// YES THIS NEEDS TO BE PCXSTR * 
VOID AppendCXStr(PCXSTR *cxstr, PCHAR text) 
{ 
	CXStr *Str=(CXStr*)cxstr;
	(*Str)+=text;
	cxstr=(PCXSTR*)Str;

//	cxstr+=text;

} 

// YES THIS NEEDS TO BE PCXSTR * 
VOID SetCXStr(PCXSTR *cxstr, PCHAR text) 
{ 
//	cxstr=text;
	CXStr *Str=(CXStr*)cxstr;
	(*Str)=text;
	cxstr=(PCXSTR*)Str;
} 

DWORD GetCXStr(PCXSTR pCXStr, PCHAR szBuffer, DWORD maxlen)
{
	if (!szBuffer)
		return 0;
	szBuffer[0]=0;
	if (!pCXStr || !maxlen){return 0;}
	if (pCXStr->Encoding==0)
	{
		if (pCXStr->Length<maxlen)
		{
			strcpy(szBuffer,pCXStr->Text);
			return pCXStr->Length;
		}
		else
		{
			strncpy(szBuffer,pCXStr->Text,maxlen);
			szBuffer[maxlen-1]=0;
			return maxlen;
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
		return o;
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
//	DebugSpew("MQToSTML(%s)",in);
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
    if (!ppWorldData | !pWorldData) return NULL;
    PZONELIST pZone = ((PWORLDDATA)pWorldData)->ZoneArray[ZoneID];

    return pZone->LongName;
}
// ***************************************************************************
// Function:    GetShortZone
// Description: Returns a short zone name from a ZoneID
// ***************************************************************************
PCHAR GetShortZone(DWORD ZoneID)
{
    if (!ppWorldData | !pWorldData) return NULL;
    PZONELIST pZone = ((PWORLDDATA)pWorldData)->ZoneArray[ZoneID];

    return pZone->ShortName; 
}
// ***************************************************************************
// Function:    GetZoneID
// Description: Returns a ZoneID from a short zone name
// ***************************************************************************

DWORD GetZoneID(PCHAR ZoneShortName)
{
    PZONELIST pZone = NULL;
    if (!ppWorldData | !pWorldData) return -1;
    for (int nIndex=0; nIndex < MAX_ZONES+1; nIndex++) {
      pZone = ((PWORLDDATA)pWorldData)->ZoneArray[nIndex];
        if(pZone )
            if (!_stricmp(pZone->ShortName,ZoneShortName)) {
                return nIndex;
            }
    }
    return -1; 
}

// ***************************************************************************
// Function:    GetGameTime
// Description: Returns Current Game Time
// ***************************************************************************
VOID GetGameTime(int* Hour, int* Minute, int* Night)
{
   int eqHour = 0;
   int eqMinute = 0;
   if (!ppWorldData | !pWorldData) return;
   eqHour=((PWORLDDATA)pWorldData)->Hour - 1; // Midnight = 1 in EQ time
   eqMinute=((PWORLDDATA)pWorldData)->Minute;
   if (Hour) *Hour = eqHour;
   if (Minute) *Minute = eqMinute;
   if (Night) *Night = ((eqHour < 7) || (eqHour > 18));//?TRUE:FALSE; // already handled by operators
}

// ***************************************************************************
// Function:    GetGameDate
// Description: Returns Current Game Time
// ***************************************************************************
VOID GetGameDate(int* Month, int* Day, int* Year)
{
   if (!ppWorldData | !pWorldData) return;
   if (Month) *Month=((PWORLDDATA)pWorldData)->Month;
   if (Day) *Day=((PWORLDDATA)pWorldData)->Day;
   if (Year) *Year=((PWORLDDATA)pWorldData)->Year;
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
    PSPELL pSpell = NULL;
    if (ppSpellMgr == NULL) return NULL;
	if (szName[0]>='0' && szName[0]<='9')
	{
		return GetSpellByID(atoi(szName));
	}
    for (DWORD dwSpellID = 0; dwSpellID < TOTAL_SPELL_COUNT; dwSpellID++) {
        pSpell = &(*((PSPELLMGR)pSpellMgr)->Spells[dwSpellID]);
		if ((pSpell->ID > 0) && (pSpell->ID < TOTAL_SPELL_COUNT))
		{
            if (pSpell->Name != NULL) 
			{
                if (!_stricmp(szName, pSpell->Name)) {
                    return pSpell;
                }
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
	if (GuildID>=MAX_GUILDS) return NULL;
	return pGuildList->GuildName[GuildID];
}

DWORD GetGuildIDByName(PCHAR szGuild)
{
	PCHAR szCurrentGuild = NULL;
	DWORD GuildID = 0;
	for (GuildID=0;GuildID<MAX_GUILDS;GuildID++) {
		szCurrentGuild = pGuildList->GuildName[GuildID];
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
// Function:    ConColor
// Description: Returns the con color for a spawn's level
// ***************************************************************************
DWORD ConColor(PSPAWNINFO pSpawn)
{
	PSPAWNINFO pChar=(PSPAWNINFO)pLocalPlayer;
	if (!pChar)
		return CONCOLOR_BLACK; // its you
      int Diff = pSpawn->Level-pChar->Level;
   if (PVPServer!=PVP_NONE && pSpawn->Type==SPAWN_PLAYER)
   {
      // whiny fuckin baby pvp server logic
      if (pChar->Level <= 5)
      {
         if (pSpawn->Level > 5)
            return CONCOLOR_RED;
         return CONCOLOR_GREEN;
      }
      if (pSpawn->Level < 5)
         return CONCOLOR_GREEN;

      if (PVPServer==PVP_TEAM) {
        if (GetDeityTeamByID(pChar->Deity) == GetDeityTeamByID(pSpawn->Deity))
        {
           return CONCOLOR_GREEN; // What should your own teammates be for a color?
        }
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
    int i;
//  DebugSpew("ConColor - Char = %d, Spawn = %d, Diff = %d",CharLevel, SpawnLevel, Diff);
    if (Diff==0) return CONCOLOR_BLACK;
    if (Diff>0) {
        if (Diff<3) return CONCOLOR_YELLOW;
        return CONCOLOR_RED;
    }

    for (i=0;ConLevels[i][0]!=0;i++) {
        if (pChar->Level<=ConLevels[i][0]) {
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
      if (pMgr->pPCContainers[j] && (pMgr->pPCContainers[j]->pContents == pContents))
         return (pMgr->pPCContainers[j]);
   }
   return NULL;
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

VOID ClearSearchItem(SEARCHITEM &SearchItem)
{
	ZeroMemory(&SearchItem,sizeof(SEARCHITEM));
}
#define MaskSet(n) (SearchItem.FlagMask[(SearchItemFlag)n])
#define Flag(n) (SearchItem.Flag[(SearchItemFlag)n])
#define RequireFlag(flag,value) {if (MaskSet(flag) && Flag(flag)!=(CHAR)((value)!=0)) return false;}

BOOL ItemMatchesSearch(SEARCHITEM &SearchItem, PCONTENTS pContents)
{
	if (SearchItem.ID && pContents->Item->ItemNumber!=SearchItem.ID)
		return false;
	RequireFlag(Lore,pContents->Item->Lore);
	RequireFlag(NoRent,pContents->Item->NoRent);
	RequireFlag(NoDrop,pContents->Item->NoDrop);
	RequireFlag(Magic,pContents->Item->Magic);
	RequireFlag(Pack,pContents->Item->Type==ITEMTYPE_PACK);
	RequireFlag(Book,pContents->Item->Type==ITEMTYPE_BOOK);
	RequireFlag(Combinable,pContents->Item->ItemType==17);
	RequireFlag(Summoned,pContents->Item->Summoned);
	RequireFlag(Instrument,pContents->Item->InstrumentType);
	RequireFlag(Weapon,pContents->Item->Damage && pContents->Item->Delay);
	RequireFlag(Normal,pContents->Item->Type==ITEMTYPE_NORMAL);

	CHAR szName[MAX_STRING] = {0};
	if (SearchItem.szName[0] && !strstr(_strlwr(strcpy(szName,pContents->Item->Name)),SearchItem.szName))
		return FALSE;
	

	return true;
}

BOOL SearchThroughItems(SEARCHITEM &SearchItem, PCONTENTS* pResult, DWORD *nResult)
{
	// TODO

#define Result(pcontents,nresult) 	{\
	if (pResult) \
		*pResult=pcontents;\
	if (nResult)\
		*nResult=nresult;\
	return TRUE;}

	PCHARINFO pChar=(PCHARINFO)pCharData;
	if (MaskSet(Worn) && Flag(Worn))
	{
		// iterate through worn items
		for (unsigned long N = 0 ; N < 21 ; N++)
		{
			if (PCONTENTS pContents=pChar->InventoryArray[N])
			if (ItemMatchesSearch(SearchItem,pContents))
				Result(pContents,N);
		}
	}

	if (MaskSet(Inventory) && Flag(Inventory))
	{
		unsigned long nPack;
		// iterate through inventory slots before in-pack slots
		for (nPack = 0 ; nPack<8 ; nPack++)
		{
			if (PCONTENTS pContents=pChar->Inventory.Pack[nPack])
			{
				if (ItemMatchesSearch(SearchItem,pContents))
					Result(pContents,nPack+21);
			}
		}

		for (nPack = 0 ; nPack<8 ; nPack++)
		{
			if (PCONTENTS pContents=pChar->Inventory.Pack[nPack])
			if (pContents->Item->ItemType==ITEMTYPE_PACK)
			{
				for (unsigned long nItem = 0 ; nItem<pContents->Item->Slots ; nItem++)
				{
					if (PCONTENTS pItem=pContents->Contents[nItem])
					if (ItemMatchesSearch(SearchItem,pItem))
						Result(pItem,nPack*100+nItem);
				}
			}
		}
	}
	// TODO
	return 0;
}
#undef TestFlag
#undef Flag
#undef MaskSet


VOID ClearSearchSpawn(PSEARCHSPAWN pSearchSpawn)
{
    if (!pSearchSpawn) return;
	ZeroMemory(pSearchSpawn,sizeof(SEARCHSPAWN));
	// 0? fine. set anything thats NOT zero.
    pSearchSpawn->MaxLevel = 100;
    pSearchSpawn->SpawnType = NONE;
    pSearchSpawn->GuildID = 0xFFFF;
    pSearchSpawn->ZRadius = 10000.0f;
    pSearchSpawn->FRadius = 10000.0f;
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
// Function:    GetSpellEffectName 
// Description: Return spell effect string 
// Usage:       Used by ShowSpellSlotInfo to list limited effect types 
// Author:      Koad [Taken from his MQ2SpellSearch Plugin
// *************************************************************************** 
PCHAR GetSpellEffectName(LONG EffectID, PCHAR szBuffer) 
{ 
   CHAR szBuff[MAX_STRING]={0}; 
   CHAR szTemp[MAX_STRING]={0}; 
   switch(abs(EffectID))
   { 
   case 0: 
      strcat(szBuff,"Hitpoints"); 
      break; 
   case 1: 
      strcat(szBuff,"AC"); 
      break; 
   case 2: 
      strcat(szBuff,"ATK"); 
      break; 
   case 4: 
      strcat(szBuff,"STR"); 
      break; 
   case 5: 
      strcat(szBuff,"DEX"); 
      break; 
   case 32: 
      strcat(szBuff,"Summon Item"); 
      break; 
   case 40: 
      strcat(szBuff,"Invunerability"); 
      break; 
   case 47: 
      strcat(szBuff,"Cold Resist"); 
      break; 
   case 59: 
      strcat(szBuff,"Damage Shield"); 
      break; 
   case 69: 
      strcat(szBuff,"Max Hitpoints"); 
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
      sprintf(szTemp, "UndefinedEffect%03d", EffectID); 
      strcat(szBuff,szTemp); 
      break; 
   } 
   strcpy(szBuffer, szBuff); 
   return szBuffer; 
} 



// *************************************************************************** 
// Function:    ShowSpellSlotInfo
// Author:      Koad (used in his SpellSearch Plugin)
// *************************************************************************** 
PCHAR ShowSpellSlotInfo(PSPELL pSpell, PCHAR szBuffer) 
{ 
   CHAR szTemp[MAX_STRING]={0}; 
   CHAR szBuff[MAX_STRING]={0}; 
   CHAR buf[MAX_STRING]={0};
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
      case 14: //Water Breathing 
         strcat(szBuff, "Water Breathing"); 
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
      case 20: //Blindness 
         strcat(szBuff, "Blindness"); 
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
      case 24: //Stamina Loss 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Stamina Loss by "); 
         SlotValueCalculate(szBuff, pSpell, i, 1); 
         break; 
      case 25: //Bind Affinity 
         strcat(szBuff, "Bind Affinity"); 
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
      case 74: //Feign Death 
         strcat(szBuff, "Feign Death"); 
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
         sprintf(szTemp,"Add Proc: \au%s \axid:\ay%d", GetSpellNameByID(pSpell->Base[i]), pSpell->Base[i]); 
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
      case 94: //Make Fragile 
         strcat(szBuff, "Make Fragile"); 
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
      case 105: //Anti-Gate 
         sprintf(szTemp, "Anti-Gate(%d)",pSpell->Base[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 106: //Summon Warder 
         sprintf(szTemp, "Summon Warder: %s", pSpell->Extra); 
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
      case 113: //Summon Horse 
         sprintf(szTemp, "Summon Horse: %s", pSpell->Extra); 
         strcat(szBuff, szTemp); 
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
      case 117: //Make Weapons Magical 
         strcat(szBuff, "Make Weapons Magical"); 
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
      case 131: //Decrease Chance of Using Reagent 
         strcat(szBuff, "Decrease Chance of Using Reagent by "); 
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
//		 sprintf(buf, "$spell(%d,targettype)", pSpell->TargetType);
//		 parmSpell(buf, szTemp, NULL );		 // <---- wtf.
//		 strcat(szBuff,szTemp);

		 strcat(szBuff,"${Spell[%d].TargetType}"); // weeee!

         //GetTargetType(pSpell->Base[i],szTemp);       strcat(szBuff,szTemp); 
         if ( pSpell->Base[i] > 0 )  strcat(szBuff, " allowed"); 
         if ( pSpell->Base[i] < 0 )  strcat(szBuff, " excluded"); 
         strcat(szBuff, ")"); 
         break; 
      case 137: //limit effect types this affects 
         strcat(szBuff, "Limit: Effect("); 
         GetSpellEffectName(pSpell->Base[i],szTemp);       strcat(szBuff,szTemp); 
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
         // the spell array for the name 
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
      case 142: //Limit: Min Level 
         sprintf(szTemp, "Limit: Min Level(%d)", pSpell->Base[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 143: //limit min casting time of spells this affects (base= seconds in ms) 
         sprintf(szTemp, "Limit: Min Cast Time(%.1f sec)", (float)(pSpell->Base[i] / 1000)); 
         strcat(szBuff, szTemp); 
         break; 
      case 145: //Teleportv2 
         sprintf(szTemp, "Teleportv2 to %d, %d, %d in %s facing %s", 
            pSpell->Base[1], pSpell->Base[2], pSpell->Base[3], pSpell->Extra, szHeading[pSpell->Base[4]]); 
         strcat(szBuff, szTemp); 
         break; 
      case 147: //Hit Points (75% Max) 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         sprintf(szTemp, "Hitpoints by %d (%dpct max)", pSpell->Max[i], pSpell->Base[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 148: //Stacking: Block 
         sprintf(szTemp, "Stacking: Block new spell if slot %d is effect '", pSpell->Calc[i]-200); 
         strcat(szBuff, szTemp); 
         GetSpellEffectName(pSpell->Base[i],szTemp);       strcat(szBuff,szTemp); 
         if ( pSpell->Max[i] > 0) { 
            strcat(szBuff, "' and < "); 
            _itoa(abs(pSpell->Max[i]), szTemp, 10); 
            strcat(szBuff, szTemp); 
         } 
         break; 
      case 149: //Stacking: Overwrite 
         sprintf(szTemp, "Stacking: Overwrite existing spell if slot %d is effect '", pSpell->Calc[i]-200); 
         strcat(szBuff, szTemp); 
         GetSpellEffectName(pSpell->Base[i],szTemp);       strcat(szBuff,szTemp); 
         if ( pSpell->Max[i] > 0) { 
            strcat(szBuff, "' and < "); 
            _itoa(abs(pSpell->Max[i]), szTemp, 10); 
            strcat(szBuff, szTemp); 
         } 
         break; 
      case 150: //Death Save - Restore Full Health 
         sprintf(szTemp, "Death Save - Restore Full Health"); 
         strcat(szBuff, szTemp); 
         break; 
      case 151: //Suspended Minion 
         strcat(szBuff, "Suspended Minion ("); 
         switch(pSpell->Base[i]) 
         { 
         case 0: 
            strcat(szBuff,"Current HP Only"); 
            break; 
         case 1: 
            strcat(szBuff,"Current HP, Buffs, Weapons"); 
            break; 
         default: 
            sprintf(szTemp, "Unknown%03d", pSpell->Base[i]); 
            strcat(szBuff,szTemp); 
            break; 
         } 
         strcat(szBuff, ")"); 
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
      case 156: //Illusion: Target 
         sprintf(szTemp, "Illusion: Target"); 
         strcat(szBuff, szTemp); 
         break; 
      case 157: //Spell-Damage Shield 
         sprintf(szTemp, "Spell-Damage Shield(%d)", pSpell->Base[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 158: //Chance to Reflect Spell 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         strcat(szBuff, "Chance to Reflect Spell by "); 
         _itoa(abs(pSpell->Base[i]), szTemp, 10); strcat(szBuff, szTemp); 
         strcat(szBuff, "%"); 
         break; 
      case 159: //Stats 
         if ( pSpell->Base[i] < 0 ) strcat(szBuff, "Decrease "); 
         if ( pSpell->Base[i] > 0 ) strcat(szBuff, "Increase "); 
         sprintf(szTemp, "Stats by %d", abs(pSpell->Base[i])); 
         strcat(szBuff, szTemp); 
         break; 
      case 161: //Mitigate Spell Damage 
         sprintf(szTemp, "Mitigate Spell Damage by %dpct until %d absorbed", pSpell->Base[i], pSpell->Max[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 162: //Mitigate Melee Damage 
         sprintf(szTemp, "Mitigate Melee Damage by %dpct until %d absorbed", pSpell->Base[i], pSpell->Max[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 163: //Absorb damage 
         sprintf(szTemp, "Absorb Damage (melee or spell, calc unknown)"); 
         strcat(szBuff, szTemp); 
         break; 
      case 164: //Attempt Sense (Cursed) Trap 
         sprintf(szTemp, "Attempt Sense (Cursed) Trap(%d,%d)", pSpell->Base[i], pSpell->Max[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 165: //Attempt Disarm (Cursed) Trap 
         sprintf(szTemp, "Attempt Disarm (Cursed) Trap(%d,%d)", pSpell->Base[i], pSpell->Max[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 166: //Attempt Destroy (Cursed) Lock 
         sprintf(szTemp, "Attempt Destroy (Cursed) Lock(%d,%d)", pSpell->Base[i], pSpell->Max[i]); 
         strcat(szBuff, szTemp); 
         break; 
      case 167: //Increase Pet Power 
         sprintf(szTemp, "Increase Pet Power(%d)", pSpell->Base[i]); 
         strcat(szBuff, szTemp); 
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
// Function:    SlotValueCalculateulate 
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
            sprintf(szTemp, "%d (L%d)", abs(szValue) >= abs(pSpell->Max[i]) ? abs(pSpell->Max[i]) : abs(szValue), level); 
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
            sprintf(szTemp, "%d (L%d)", abs(szValue) >= abs(pSpell->Max[i]) ? abs(pSpell->Max[i]) : abs(szValue), level); 
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
            sprintf(szTemp, "%d (L%d)", abs(szValue) >= abs(pSpell->Max[i]) ? abs(pSpell->Max[i]) : abs(szValue), level); 
            strcat(szBuff, szTemp); 
            break; 
         } 
      } 
      break; 
   case 102: // Level + Base 
      sprintf(szTemp, "%d (L%d) to ", abs(szBase+(minlevel)), minlevel); 
      strcat(szBuff, szTemp); 
      for (level = minlevel; level <= 65; level++) 
      { 
         if ( pSpell->Max[i] ==0 ) level=65;  
         szValue = level + abs(szBase); 
         if ( abs(szValue) >= abs(pSpell->Max[i]) || level==65 ) { 
            sprintf(szTemp, "%d (L%d)", abs(szValue) >= abs(pSpell->Max[i]) ? abs(pSpell->Max[i]) : abs(szValue), level); 
            strcat(szBuff, szTemp); 
            break; 
         } 
      } 
      break; 
   case 103: // Level*2 + Base 
      sprintf(szTemp, "%d (L%d) to ", abs(szBase+(minlevel*2)), minlevel); 
      strcat(szBuff, szTemp); 
      for (level = minlevel; level <= 65; level++) 
      { 
         if ( pSpell->Max[i] ==0 ) level=65;  
         szValue = (level*2) + abs(szBase); 
         if ( abs(szValue) >= abs(pSpell->Max[i]) || level==65 ) { 
            sprintf(szTemp, "%d (L%d)", abs(szValue) >= abs(pSpell->Max[i]) ? abs(pSpell->Max[i]) : abs(szValue), level); 
            strcat(szBuff, szTemp); 
            break; 
         } 
      } 
      break; 
   case 104: // Level*3 + Base 
      sprintf(szTemp, "%d (L%d) to ", abs(szBase+(minlevel*3)), minlevel); 
      strcat(szBuff, szTemp); 
      for (level = minlevel; level <= 65; level++) 
      { 
         if ( pSpell->Max[i]==0 ) level=65; 
         szValue = (level*3) + abs(szBase); 
         if ( abs(szValue) >= abs(pSpell->Max[i]) || level==65 ) { 
            sprintf(szTemp, "%d (L%d)", abs(szValue) >= abs(pSpell->Max[i]) ? abs(pSpell->Max[i]) : abs(szValue), level); 
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
   case 121: // correct?
      sprintf(szTemp, "%d", abs(pSpell->Max[i]));
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

int FindMappableCommand(const char *name)
{
	for (unsigned long i = 0 ; i < nEQMappableCommands ; i++)
	{
		if (!stricmp(name,szEQMappableCommands[i]))
			return i;
	}
	return -1;
}	


void DisplayOverlayText(PCHAR szText, DWORD dwColor, DWORD dwTransparency, DWORD msFadeIn, DWORD msFadeOut, DWORD msHold)
{
   if (!pTextOverlay) {
      WriteChatColor(szText,dwColor);
      return;
   }
   DWORD dwAlpha = (DWORD)(dwTransparency*255/100);
   if (dwAlpha>255) dwAlpha=255;

   pTextOverlay->DisplayText(
      szText,
      dwColor,
      10, // Always 10 in eqgame.exe,
          // Doesn't seem to affect anything
         // (tried 0,1,10,20,100,500)
      dwAlpha,
      msFadeIn,
      msFadeOut,
      msHold);
}

BOOL ParseKeyCombo(PCHAR text, KeyCombo &Dest)
{
	KeyCombo Ret;
	if (!stricmp(text,"clear"))
	{
		Dest=Ret;
		return true;
	}
	CHAR Copy[MAX_STRING];
	strcpy(Copy,text);
	text=strtok(Copy,"+ ");
	while(text)
	{
		if (!stricmp(text,"alt"))
			Ret.Data[0]=1;
		else if (!stricmp(text,"ctrl"))
			Ret.Data[1]=1;
		else if (!stricmp(text,"shift"))
			Ret.Data[2]=1;
		else
		{
			for (unsigned long i=0 ; gDiKeyID[i].Id ; i++)
			{
				if (!stricmp(text,gDiKeyID[i].szName))
				{
					Ret.Data[3]=(char)gDiKeyID[i].Id;
					break;
				}
			}
		}
		text=strtok(NULL,"+ ");
	}
	if (Ret.Data[3])
	{
		Dest=Ret;
		return true;
	}
	return false;
}

PCHAR DescribeKeyCombo(KeyCombo &Combo, PCHAR szDest)
{
	unsigned long pos=0;
	szDest[0]=0;
	if (Combo.Data[2])
	{
		strcpy(&szDest[pos],"shift");
		pos+=5;
	}
	if (Combo.Data[1])
	{
		if (pos)
		{
			szDest[pos]='+';
			pos++;
		}

		strcpy(&szDest[pos],"ctrl");
		pos+=4;
	}

	if (Combo.Data[0])
	{
		if (pos)
		{
			szDest[pos]='+';
			pos++;
		}

		strcpy(&szDest[pos],"alt");
		pos+=3;
	}

	if (pos)
	{
		szDest[pos]='+';
		pos++;
	}
	if (Combo.Data[3])
	{
		strcpy(&szDest[pos],gDiKeyName[Combo.Data[3]]);
	}
	else
	{
		strcpy(&szDest[pos],"clear");
	}

	return &szDest[0];	
}

BOOL LoadCfgFile(PCHAR Filename, BOOL Delayed)
{
	FILE *file;
	CHAR szFilename[MAX_STRING]={0};
	strcpy(szFilename,Filename);
	if (!strchr(szFilename,'.'))
		strcat(szFilename,".cfg");
	CHAR szFull[MAX_STRING]={0};
#define TryFile(name)  \
	{\
		if (file=fopen(name,"rt"))\
			goto havecfgfile;\
	}
	sprintf(szFull,"%s\\Configs\\%s",gszINIPath,szFilename);
	TryFile(szFull);	
	sprintf(szFull,"%s\\%s",gszINIPath,szFilename);
	TryFile(szFull);
	TryFile(szFilename);
	TryFile(Filename);
#undef TryFile
	return false;
havecfgfile:
	CHAR szBuffer[MAX_STRING]={0};
	while(fgets(szBuffer,MAX_STRING,file))
	{
		PCHAR Cmd=strtok(szBuffer,"\r\n");
		if (Cmd && Cmd[0])
			HideDoCommand(((PSPAWNINFO)pLocalPlayer),Cmd,Delayed);
	}
	fclose(file);
	return true;
}


int FindInvSlotForContents(PCONTENTS pContents)
{
	DebugSpew("FindInvSlotForContents(0x%08X) (0x%08X)",pContents,pContents->Item);
	PEQINVSLOTMGR pInvMgr=(PEQINVSLOTMGR)pInvSlotMgr;
	for (unsigned long N = 0 ; N < 0x400 ; N++)
	{
		if (pInvMgr->SlotArray[N] && pInvMgr->SlotArray[N]->ppContents)
		{
//			DebugSpew("pInvSlotMgr->SlotArray[%d]->pContents==0x%08X",N,*pInvMgr->SlotArray[N]->ppContents);
			if (*pInvMgr->SlotArray[N]->ppContents==pContents)
			{
				if (pInvMgr->SlotArray[N]->pInvSlotWnd && pInvMgr->SlotArray[N]->pInvSlotWnd->InvSlot>=0)
					return pInvMgr->SlotArray[N]->pInvSlotWnd->InvSlot; 
				break;
			}
		}
	}

	for (unsigned long nPack=0 ; nPack < 8 ; nPack++)
	{
		PCHARINFO pCharInfo=GetCharInfo();
		if (PCONTENTS pPack=pCharInfo->Inventory.Pack[nPack])
		{
			if (pPack->Item->Type==ITEMTYPE_PACK)
			{
				for (unsigned long nItem=0 ; nItem < pPack->Item->Slots ; nItem++)
				{
//					DebugSpew("Pack[%d]->Contents[%d]==0x%08X",nPack,nItem,pPack->Contents[nItem]);
					if (pPack->Contents[nItem]==pContents)
					{
						return 251+(nPack*10)+nItem;
					}
				}
			}
		}
	}

	for (nPack=0 ; nPack < NUM_BANK_SLOTS ; nPack++)
	{
		PCHARINFO pCharInfo=GetCharInfo();
		if (PCONTENTS pPack=pCharInfo->Bank[nPack])
		{
			if (pPack==pContents)
			{
				if (nPack<0x10)
					return 2000+nPack;
				return 2500+nPack-0x10;
			}
			if (pPack->Item->Type==ITEMTYPE_PACK)
			{
				for (unsigned long nItem=0 ; nItem < pPack->Item->Slots ; nItem++)
				{
					if (pPack->Contents[nItem]==pContents)
					{
						if (nPack<0x10)
							return 2031+(nPack*10)+nItem;
						return 2531-0xa0+(nPack*10)+nItem;
					}
				}
			}
		}		
	}


	return -1;
}

DWORD LastFoundInvSlot=-1;

int FindInvSlot(PCHAR pName, BOOL Exact)
{
	CHAR Name[MAX_STRING]={0};
	strlwr(strcpy(Name,pName));
	CHAR szTemp[MAX_STRING]={0};

	PEQINVSLOTMGR pInvMgr=(PEQINVSLOTMGR)pInvSlotMgr;
	for (unsigned long N = 0 ; N < 0x400 ; N++)
	{
		if (pInvMgr->SlotArray[N])
		{
			if (pInvMgr->SlotArray[N]->ppContents && *pInvMgr->SlotArray[N]->ppContents)
			{
				if (!Exact)
				{
					_strlwr(strcpy(szTemp,(*pInvMgr->SlotArray[N]->ppContents)->Item->Name));
					if (strstr(szTemp,Name))
					{
						if (pInvMgr->SlotArray[N]->pInvSlotWnd)
						{
							LastFoundInvSlot=N;
							return pInvMgr->SlotArray[N]->pInvSlotWnd->InvSlot;
						}
						// let it try to find it in an open slot if this fails
					}
				}
				else if (!stricmp(Name,(*pInvMgr->SlotArray[N]->ppContents)->Item->Name))
				{
					if (pInvMgr->SlotArray[N]->pInvSlotWnd)
					{
						LastFoundInvSlot=N;
						return pInvMgr->SlotArray[N]->pInvSlotWnd->InvSlot;
					}
					// let it try to find it in an open slot if this fails
				}
				
			}
		}
	}

	LastFoundInvSlot=-1;
	return -1;
}

int FindNextInvSlot(PCHAR pName, BOOL Exact)
{
	CHAR szTemp[MAX_STRING]={0};
	CHAR Name[MAX_STRING]={0};
	strlwr(strcpy(Name,pName));

	PEQINVSLOTMGR pInvMgr=(PEQINVSLOTMGR)pInvSlotMgr;
	for (unsigned long N = LastFoundInvSlot+1 ; N < 0x400 ; N++)
	{
		if (pInvMgr->SlotArray[N])
		{
			if (pInvMgr->SlotArray[N]->ppContents && *pInvMgr->SlotArray[N]->ppContents)
			{
				if (!Exact)
				{
					_strlwr(strcpy(szTemp,(*pInvMgr->SlotArray[N]->ppContents)->Item->Name));
					if (strstr(szTemp,Name))
					{
						if (pInvMgr->SlotArray[N]->pInvSlotWnd)
						{
							LastFoundInvSlot=N;
							return pInvMgr->SlotArray[N]->pInvSlotWnd->InvSlot;
						}
						// let it try to find it in an open slot if this fails
					}
				}
				else if (!stricmp(Name,(*pInvMgr->SlotArray[N]->ppContents)->Item->Name))
				{
					if (pInvMgr->SlotArray[N]->pInvSlotWnd)
					{
						LastFoundInvSlot=N;
						return pInvMgr->SlotArray[N]->pInvSlotWnd->InvSlot;
					}
					// let it try to find it in an open slot if this fails
				}
				
			}
		}
	}
	LastFoundInvSlot=-1;
	return -1;
}
/*
BOOL ActualCalculate(PCHAR szFormula, DOUBLE &Result) {
    CHAR Buffer[MAX_STRING] = {0};
    DWORD i = 0, j=0, k=0;
    CHAR Arg[MAX_STRING][100] = {0};
    for (i=0;i<strlen(szFormula);i++) {
		if (szFormula[i] == '(')
		{
			BOOL Quote=false;
			PCHAR pStart=&szFormula[i+1];
			unsigned long nParens=1;
			while(nParens)
			{
				i++;
				if (szFormula[i]==0)
				{
					FatalError("Calculate encountered an unmatched parenthesis");
					return false;
				}
				if (szFormula[i]==')')
				{
					if (!Quote)
						nParens--;
				}
				else if (szFormula[i]=='(')
				{
					if (!Quote)
						nParens++;
				}
				else if (szFormula[i]=='\"')
				{
					Quote=!Quote;
				}
			}
			szFormula[i]=0;
			DOUBLE CalcResult;
			if (ActualCalculate(pStart,CalcResult))
			{
				szFormula[i]=')';
				j+=sprintf(&Buffer[j],"%f",CalcResult);
			}
			else
			{
				// error condition would have been reported by the calculate already, dont give another
				szFormula[i]=')';
				return false;
			}
		}
		else
        if (szFormula[i] != ' ') 
			Buffer[j++]=szFormula[i];
    }
	Buffer[j]=0;
    j=0;
    k=0;
    for (i=0;Buffer[i];i++) {
        switch (Buffer[i]) {
            case '-':
                if (k==0) {
                    Arg[j][k] = Buffer[i];
                    k++;
                    break;
                }
            case '+':
            case '*':
            case '\\':
            case '/':
            case '%':
            case '^':
                Arg[j+1][0]=Buffer[i];
                j+=2;
                k=0;
                break;
			case '&':
				if (Buffer[i+1]=='&')
				{
					Arg[j+1][0]='a';
					j+=2;
					k=0;
					i++;
				}
				else
				{
					Arg[j+1][0]='&';
					j+=2;
					k=0;
				}
				break;
			case '|':
				if (Buffer[i+1]=='|')
				{
					Arg[j+1][0]='o';
					j+=2;
					k=0;
					i++;
				}
				else
				{
					Arg[j+1][0]='|';
					j+=2;
					k=0;
				}
				break;
			case '!':
				if (Buffer[i+1]=='=')
				{
					Arg[j+1][0]='n';
					j+=2;
					k=0;
					i++;
				}
				else
				{
					Arg[j+1][0]='!';
					j+=2;
					k=0;
				}
				break;
			case '=':
				if (Buffer[i+1]=='=')
				{
					Arg[j+1][0]='=';
					j+=2;
					k=0;
					i++;
				}
				else
				{
					FatalError("Calculate encountered a bad = formation");
					return false;
				}
				break;
			case '>':
				if (Buffer[i+1]=='=')
				{
					Arg[j+1][0]=(char)0xf2;
					j+=2;
					k=0;
					i++;
				}
				else
				{
					Arg[j+1][0]='>';
					j+=2;
					k=0;
				}
				break;
			case '<':
				if (Buffer[i+1]=='=')
				{
					Arg[j+1][0]=(char)0xf3;
					j+=2;
					k=0;
					i++;
				}
				else
				{
					Arg[j+1][0]='<';
					j+=2;
					k=0;
				}
				break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '.':
                Arg[j][k] = Buffer[i];
                k++;
                break;
			case ' ':
			case '²':
  //              GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Calculate encountered a unparsed variable '%s'",&(Buffer[i]));
				return false;
            default:
				FatalError("Calculate encountered unparsable text '%s'",&Buffer[i]);
                return false;
        }
    }
    j++;

    //for (i=0;i<j;i++) DebugSpewNoFile("%d. %s",i,Arg[i]);
    for (i=0;i<j;i++) {
        switch (Arg[i][0]) {
            case '!':
                if (i+1==j) {
				    FatalError("Calculate encountered a bad %c formation",Arg[i][0]);
                    return false;
                }
                i--;
				if (atof(Arg[i+2])!=0.0f)
				{
					strcpy(Arg[i],"0");
				}
				else
					strcpy(Arg[i],"1");

				if (i==0)
				{
			        for (k=i+1;k<j;k++) 
						strcpy(Arg[k],Arg[k+2]);
				}
				else
				{
			        for (k=i+1;k<j;k++) 
						strcpy(Arg[k],Arg[k+2]);
				}
				j--;
        }
    }

    for (i=0;i<j;i++) {
        switch (Arg[i][0]) {
            case '^':
                if ((i==0) || (i+1==j)) {
				    FatalError("Calculate encountered a bad %c formation",Arg[i][0]);
                    return false;
                }
                i--;
                sprintf(Buffer,"%f",pow(atof(Arg[i]),atof(Arg[i+2])));
                strcpy(Arg[i],Buffer);
                j-=2;
                for (k=i+1;k<j;k++) strcpy(Arg[k],Arg[k+2]);
        }
    }

    for (i=0;i<j;i++) {
        switch (Arg[i][0]) {
            case '%':
            case '/':
            case '\\':
            case '*':
                if ((i==0) || (i+1==j)) {
				    FatalError("Calculate encountered a bad %c formation",Arg[i][0]);
                    return false;
                }
                i--;
                switch (Arg[i+1][0]) {
                    case '%':
                        if (atof(Arg[i+2])==0) 
						{
							return false;
						}
                        ltoa(atoi(Arg[i])%atol(Arg[i+2]),Buffer,10);
                        break;
                    case '\\':
                        if (atof(Arg[i+2])==0) 
						{
							return false;
						}
                        ltoa((LONG)(atol(Arg[i])/atol(Arg[i+2])),Buffer,10);
                        break;
                    case '/':
                        if (atof(Arg[i+2])==0) 
						{
							return false;
						}
                        sprintf(Buffer,"%f",(atof(Arg[i])/atof(Arg[i+2])));
                        break;
                    case '*':
                        sprintf(Buffer,"%f",(atof(Arg[i])*atof(Arg[i+2])));
                        break;
                }

                strcpy(Arg[i],Buffer);
                j-=2;
                for (k=i+1;k<j;k++) strcpy(Arg[k],Arg[k+2]);
        }
    }

    for (i=0;i<j;i++) {
        switch (Arg[i][0]) {
            case '-':
                if (Arg[i][1] != 0) break;
            case '+':
                if ((i==0) || (i+1==j)) {
				    FatalError("Calculate encountered a bad %c formation",Arg[i][0]);
                    return false;
                }
                i--;
                switch (Arg[i+1][0]) {
                    case '+':
                        sprintf(Buffer,"%f",(atof(Arg[i])+atof(Arg[i+2])));
                        break;
                    case '-':
                        sprintf(Buffer,"%f",(atof(Arg[i])-atof(Arg[i+2])));
                        break;
                }
                strcpy(Arg[i],Buffer);
                j-=2;
                for (k=i+1;k<j;k++) strcpy(Arg[k],Arg[k+2]);
        }
    }

    for (i=0;i<j;i++) {
        switch ((UCHAR)Arg[i][0]) {
			case 'n':
            case '<':
            case '>':
			case '=':
			case 0xf2:
			case 0xf3:
                if ((i==0) || (i+1==j)) {
				    FatalError("Calculate encountered a bad %c formation",Arg[i][0]);
                    return false;
                }
                i--;
                switch ((UCHAR)Arg[i+1][0]) {
					case '<':
						sprintf(Buffer,"%d",atof(Arg[i])<atof(Arg[i+2]));
						break;
					case '>':
						sprintf(Buffer,"%d",atof(Arg[i])>atof(Arg[i+2]));
						break;
					case 'n':
						sprintf(Buffer,"%d",atof(Arg[i])!=atof(Arg[i+2]));
						break;
					case '=':
						sprintf(Buffer,"%d",atof(Arg[i])==atof(Arg[i+2]));
						break;
					case 0xf2:
						sprintf(Buffer,"%d",atof(Arg[i])>=atof(Arg[i+2]));
						break;
					case 0xf3:
						sprintf(Buffer,"%d",atof(Arg[i])<=atof(Arg[i+2]));
						break;

                }
                strcpy(Arg[i],Buffer);
                j-=2;
                for (k=i+1;k<j;k++) strcpy(Arg[k],Arg[k+2]);
        }
    }
	
    for (i=0;i<j;i++) {
        switch (Arg[i][0]) {
            case '&':
            case '|':
                if ((i==0) || (i+1==j)) {
				    FatalError("Calculate encountered a bad %c formation",Arg[i][0]);
					return false;
                }
                i--;
                switch (Arg[i+1][0]) {
                    case '&':
                        sprintf(Buffer,"%d",atol(Arg[i])&atol(Arg[i+2]));
                        break;
                    case '|':
                        sprintf(Buffer,"%d",atol(Arg[i])|atol(Arg[i+2]));
                        break;
                }
                strcpy(Arg[i],Buffer);
                j-=2;
                for (k=i+1;k<j;k++) strcpy(Arg[k],Arg[k+2]);
        }
    }
	
    for (i=0;i<j;i++) {
        switch (Arg[i][0]) {
            case 'a':
            case 'o':
                if ((i==0) || (i+1==j)) {
				    FatalError("Calculate encountered a bad %c formation",Arg[i][0]);
					return false;
                }
                i--;
                switch (Arg[i+1][0]) {
					case 'a':
						{
							FLOAT A=(FLOAT)atof(Arg[i]);
							FLOAT B=(FLOAT)atof(Arg[i+2]);
							if ((A&&B)==0)
							{
								Result=0;
								return true;
							}
							strcpy(Buffer,"1"); // if its not zero ,it must be 1 ;)
	//						sprintf(Buffer,"%d",atof(Arg[i])&&atof(Arg[i+2]));
						}
						break;
					case 'o':
						{
							FLOAT A=(FLOAT)atof(Arg[i]);
							FLOAT B=(FLOAT)atof(Arg[i+2]);
							if ((A||B)==1)
							{
								Result=1;
								return true;
							}
							strcpy(Buffer,"0"); // if its not 1,it must be 0!
//							sprintf(Buffer,"%d",atof(Arg[i])||atof(Arg[i+2]));
						}
						break;
                }
                strcpy(Arg[i],Buffer);
                j-=2;
                for (k=i+1;k<j;k++) strcpy(Arg[k],Arg[k+2]);
        }
    }

	Result=atof(Arg[0]);
	return true;
}
/**/

enum eCalcOp
{
	CO_NUMBER=0,
	CO_OPENPARENS=1,
	CO_CLOSEPARENS=2,
	CO_ADD=3,
	CO_SUBTRACT=4,
	CO_MULTIPLY=5,
	CO_DIVIDE=6,
	CO_IDIVIDE=7,
	CO_LAND=8,
	CO_AND=9,
	CO_LOR=10,
	CO_OR=11,
	CO_XOR=12,
	CO_EQUAL=13,
	CO_NOTEQUAL=14,
	CO_GREATER=15,
	CO_NOTGREATER=16,
	CO_LESS=17,
	CO_NOTLESS=18,
	CO_MODULUS=19,
	CO_POWER=20,
	CO_LNOT=21,
	CO_NOT=22,
	CO_SHL=23,
	CO_SHR=24,
	CO_TOTAL=25,
};

int CalcOpPrecedence[CO_TOTAL]=
{
	0,
	0,
	0,
	9,//add
	9,//subtract
	10,//multiply
	10,//divide
	10,//integer divide
	2,//logical and
	5,//bitwise and
	1,//logical or
	3,//bitwise or
	4,//bitwise xor
	6,//equal
	6,//not equal
	7,//greater
	7,//not greater
	7,//less
	7,//not less
	10,//modulus
	11,//power
	12,//logical not
	12,//bitwise not
	8,//shl
	8,//shr
};

struct _CalcOp
{
	eCalcOp Op;
	DOUBLE Value;
};


BOOL EvaluateRPN(_CalcOp *pList, int Size, DOUBLE &Result)
{
	if (!Size)
		return 0;
	int StackSize=(sizeof(DOUBLE)*(Size/2+2));
	DOUBLE *pStack = (DOUBLE*) malloc(StackSize);
	int nStack=0;
#define StackEmpty() (nStack==0)
#define StackTop() (pStack[nStack])
#define StackSetTop(do_assign) {pStack[nStack]##do_assign;}
#define StackPush(val) {nStack++;pStack[nStack]=val;}
#define StackPop() {if (!nStack) {FatalError("Illegal arithmetic in calculation");free(pStack);return 0;};nStack--;}


#define BinaryIntOp(op) {int RightSide=(int)StackTop();StackPop();StackSetTop(=(DOUBLE)(((int)StackTop())##op##RightSide));}
#define BinaryOp(op) {DOUBLE RightSide=StackTop();StackPop();StackSetTop(=StackTop()##op##RightSide);}
#define BinaryAssign(op) {DOUBLE RightSide=StackTop();StackPop();StackSetTop(##op##=RightSide);}

#define UnaryIntOp(op) {StackSetTop(=op##((int)StackTop()));}

	for (int i = 0 ; i < Size ; i++)
	{
		switch(pList[i].Op)
		{
		case CO_NUMBER:
			StackPush(pList[i].Value);
			break;
		case CO_ADD:
			BinaryAssign(+);
			break;
		case CO_MULTIPLY:
			BinaryAssign(*);
			break;
		case CO_SUBTRACT:
			BinaryAssign(-);
			break;
		case CO_DIVIDE:
			if (StackTop())
			{
				BinaryAssign(/);
			}
			else
			{
//				printf("Divide by zero error\n");
				FatalError("Divide by zero in calculation");
				free(pStack);
				return false;
			}
			break;
		case CO_IDIVIDE://TODO: SPECIAL HANDLING
			{
				int Right=(int)StackTop();
				if (Right)
				{
					StackPop();
					int Left=(int)StackTop();
					Left/=Right;
					StackSetTop(=Left);
				}
				else
				{
//					printf("Integer divide by zero error\n");
					FatalError("Divide by zero in calculation");
					free(pStack);
					return false;
				}
			}
			break;
		case CO_MODULUS://TODO: SPECIAL HANDLING
			{
				int Right=(int)StackTop();
				if (Right)
				{
					StackPop();
					int Left=(int)StackTop();
					Left%=Right;
					StackSetTop(=Left);
				}
				else
				{
//					printf("Modulus by zero error\n");
					FatalError("Modulus by zero in calculation");
					free(pStack);
					return false;
				}
			}
			break;
		case CO_LAND:
			BinaryOp(&&);
			break;
		case CO_LOR:
			BinaryOp(||);
			break;
		case CO_EQUAL:
			BinaryOp(==);
			break;
		case CO_NOTEQUAL:
			BinaryOp(!=);
			break;
		case CO_GREATER:
			BinaryOp(>);
			break;
		case CO_NOTGREATER:
			BinaryOp(<=);
			break;
		case CO_LESS:
			BinaryOp(<);
			break;
		case CO_NOTLESS:
			BinaryOp(>=);
			break;
		case CO_SHL:
			BinaryIntOp(<<);
			break;
		case CO_SHR:
			BinaryIntOp(>>);
			break;
		case CO_AND:
			BinaryIntOp(&);
			break;
		case CO_OR:
			BinaryIntOp(|);
			break;
		case CO_XOR:
			BinaryIntOp(^);
			break;
		case CO_LNOT:
			UnaryIntOp(!);
			break;
		case CO_NOT:
			UnaryIntOp(~);
			break;
		case CO_POWER:
			{
				DOUBLE RightSide=StackTop();
				StackPop();
				StackSetTop(=pow(StackTop(),RightSide));
			}
			break;
		}
	}
	Result=StackTop();

#undef StackEmpty
#undef StackTop
#undef StackPush
#undef StackPop
	free(pStack);
	return true;
}

BOOL FastCalculate(PCHAR szFormula, DOUBLE &Result)
{
	//DebugSpew("FastCalculate(%s)",szFormula);
	if (!szFormula || !szFormula[0])
		return false;
	int Length=(int)strlen(szFormula);
	int MaxOps=(Length+1);
	int ListSize=sizeof(_CalcOp)*MaxOps;
	int StackSize=sizeof(eCalcOp)*MaxOps;
	_CalcOp *pOpList=(_CalcOp *)malloc(ListSize);
	eCalcOp *pStack=(eCalcOp *)malloc(StackSize);
	memset(pOpList,0,ListSize);
	memset(pStack,0,StackSize);
	int nOps=0;
	int nStack=0;

	char *pEnd=szFormula+Length;

	char CurrentToken[MAX_STRING]={0};
	char *pToken=&CurrentToken[0];

#define OpToList(op) {pOpList[nOps].Op=op;nOps++;}
#define ValueToList(val) {pOpList[nOps].Value=val;nOps++;}

#define StackEmpty() (nStack==0)
#define StackTop() (pStack[nStack])
#define StackPush(op) {nStack++;pStack[nStack]=op;}
#define StackPop() {if (!nStack) {FatalError("Illegal arithmetic in calculation");free(pOpList);free(pStack);return 0;} nStack--;}
#define HasPrecedence(a,b) (CalcOpPrecedence[a]>CalcOpPrecedence[b])
#define MoveStack(op)  \
	{ \
		while(!StackEmpty() && StackTop()!=CO_OPENPARENS && HasPrecedence(StackTop(),op)) \
		{ \
			OpToList(StackTop()); \
			StackPop(); \
		} \
	}

#define FinishString() {if (pToken!=&CurrentToken[0]) {*pToken=0;ValueToList(atof(CurrentToken));pToken=&CurrentToken[0];*pToken=0;}}
#define NewOp(op) {FinishString();MoveStack(op);StackPush(op);}
#define NextChar(ch) {*pToken=ch;pToken++;}


	for (char *pCur=szFormula ; pCur<pEnd ; pCur++)
	{
		switch(*pCur)
		{
		case ' ':
			break;
		case '(':
			FinishString();
			StackPush(CO_OPENPARENS);
			break;
		case ')':
			FinishString();
			while(StackTop()!=CO_OPENPARENS)
			{
				OpToList(StackTop());
				StackPop();
			}
			StackPop();
			break;
		case '+':
			NewOp(CO_ADD);
			break;
		case '-':
			if (CurrentToken[0])
			{
				NewOp(CO_SUBTRACT);
			}
			else
				NextChar('-');
			break;
		case '*':
			NewOp(CO_MULTIPLY);
			break;
		case '\\':
			NewOp(CO_IDIVIDE);
			break;
		case '/':
			NewOp(CO_DIVIDE);
			break;
		case '|':
			if (pCur[1]=='|')
			{
				// Logical OR
				++pCur;
				NewOp(CO_LOR);
			}
			else
			{
				// Bitwise OR
				NewOp(CO_OR);
			}
			break;
		case '%':
			NewOp(CO_MODULUS);
			break;
		case '~':
			NewOp(CO_NOT);
			break;
		case '&':
			if (pCur[1]=='&')
			{
				// Logical AND
				++pCur;
				NewOp(CO_LAND);
			}
			else
			{
				// Bitwise AND
				NewOp(CO_AND);
			}
			break;
		case '^':
			if (pCur[1]=='^')
			{
				// XOR
				++pCur;
				NewOp(CO_XOR);
			}
			else
			{
				// POWER
				NewOp(CO_POWER);
			}
			break;
		case '!':
			if (pCur[1]=='=')
			{
				++pCur;
				NewOp(CO_NOTEQUAL);
			}
			else
			{
				NewOp(CO_LNOT);
			}
			break;
		case '=':
			if (pCur[1]=='=')
			{
				++pCur;
				NewOp(CO_EQUAL);
			}
			else
			{
//				printf("Unparsable: '%c'\n",*pCur);
				// error
				free(pOpList);
				free(pStack);
				return false;
			}
			break;
		case '<':
			if (pCur[1]=='=')
			{
				++pCur;
				NewOp(CO_NOTGREATER);
			}
			else if (pCur[1]=='<')
			{
				++pCur;
				NewOp(CO_SHL);
			}
			else
			{
				NewOp(CO_LESS);
			}
			break;
		case '>':
			if (pCur[1]=='=')
			{
				++pCur;
				NewOp(CO_NOTLESS);
			}
			else if (pCur[1]=='>')
			{
				++pCur;
				NewOp(CO_SHR);
			}
			else
			{
				NewOp(CO_GREATER);
			}
			break;
		case '.':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '0':
			NextChar(*pCur);
			break;
		default:
			{
//				printf("Unparsable: '%c'\n",*pCur);
				FatalError("Unparsable in Calculation: '%c'",*pCur);
				// unparsable
				free(pOpList);
				free(pStack);
				return false;
			}
			break;
		}
	}
	FinishString();

	while(!StackEmpty())
	{
		OpToList(StackTop());
		StackPop();
	}
	free(pStack);
/*
	for (int i = 0 ; i < nOps ; i++)
	{
		if (pOpList[i].Op)
			printf("Op: %d\n",pOpList[i].Op);
		else
			printf("Value: %f\n",pOpList[i].Value);
	}
/**/
	BOOL Ret=EvaluateRPN(pOpList,nOps,Result);
	free(pOpList);
	return Ret;
}

BOOL Calculate(PCHAR szFormula, DOUBLE &Result) 
{
	CHAR Buffer[MAX_STRING]={0};
	strcpy(Buffer,szFormula);
	while(PCHAR pNull=strstr(Buffer,"NULL"))
	{
		pNull[0]='0';
		pNull[1]='.';
		pNull[2]='0';
		pNull[3]='0';
	}
	while(PCHAR pTrue=strstr(Buffer,"TRUE"))
	{
		pTrue[0]='1';
		pTrue[1]='.';
		pTrue[2]='0';
		pTrue[3]='0';
	}
	while(PCHAR pFalse=strstr(Buffer,"FALSE"))
	{
		pFalse[0]='0';
		pFalse[1]='.';
		pFalse[2]='0';
		pFalse[3]='0';
		pFalse[4]='0';
	}
	BOOL Ret;
	//Benchmark(bmCalculate,Ret=ActualCalculate(Buffer,Result));
	Benchmark(bmCalculate,Ret=FastCalculate(Buffer,Result));
	return Ret;
}

