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
#define DBG_SPEW

#include "MQ2Main.h"

#ifndef ISXEQ_LEGACY
// ***************************************************************************
// Function:    DebugSpew
// Description: Outputs text to debugger, usage is same as printf ;)
// ***************************************************************************
VOID DebugSpew(PCHAR szFormat, ...)
{
#ifdef DBG_SPEW
    if (gFilterDebug) return;
    va_list vaList;
    va_start( vaList, szFormat );
	int len = _vscprintf( szFormat, vaList )+1;// _vscprintf doesn't count // terminating '\0'
	if(char *szOutput = (char *)LocalAlloc(LPTR,len+32)) {
		vsprintf(szOutput,szFormat, vaList);
		OutputDebugString(DebugHeader);
		OutputDebugString(szOutput);
		OutputDebugString("\n");
		LocalFree(szOutput);
	}
#endif
}

VOID WriteChatf(PCHAR szFormat, ...)
{
	va_list vaList;
    va_start(vaList, szFormat );
	int len = _vscprintf( szFormat, vaList )+1;// _vscprintf doesn't count // terminating '\0'
	if(char *szOutput = (char *)LocalAlloc(LPTR,len+32)) {
		vsprintf(szOutput,szFormat, vaList);
		WriteChatColor(szOutput);
		LocalFree(szOutput);
	}
}

VOID DebugSpewAlways(PCHAR szFormat, ...)
{
    va_list vaList;
    OutputDebugString(DebugHeader);
    va_start( vaList, szFormat );
	int len = _vscprintf( szFormat, vaList )+1;// _vscprintf doesn't count // terminating '\0'
	if(char *szOutput = (char *)LocalAlloc(LPTR,len+32)) {
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
		LocalFree(szOutput);
	}
}

EQLIB_API VOID DebugSpewNoFile(PCHAR szFormat, ...)
{
#ifdef DBG_SPEW
    va_list vaList;
    OutputDebugString(DebugHeader);
    va_start( vaList, szFormat );
    int len = _vscprintf( szFormat, vaList )+1;// _vscprintf doesn't count // terminating '\0'
	if(char *szOutput = (char *)LocalAlloc(LPTR,len+32)) {
		vsprintf(szOutput,szFormat, vaList);
		OutputDebugString(szOutput);
		OutputDebugString("\n");
		LocalFree(szOutput);
	}
#endif
}
#endif

VOID StrReplaceSection(PCHAR szInsert,DWORD Length,PCHAR szNewString)
{
    DWORD NewLength=(DWORD)strlen(szNewString);
    memmove(&szInsert[NewLength],&szInsert[Length],strlen(&szInsert[Length])+1);
    strncpy(szInsert,szNewString,NewLength);
}

#ifndef ISXEQ_LEGACY
VOID ConvertCR(PCHAR Text)
{// not super-efficient but this is only being called at initialization currently.
    while (PCHAR Next=strstr(Text,"\\n"))
    {
        StrReplaceSection(Next,2,"\n");
    }
}
#endif

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

#ifndef ISXEQ
VOID SyntaxError(PCHAR szFormat, ...)
{
    va_list vaList;
    va_start( vaList, szFormat );
	int len = _vscprintf( szFormat, vaList )+1;// _vscprintf doesn't count // terminating '\0'
	if(char *szOutput = (char *)LocalAlloc(LPTR,len+32)) {
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
		strcpy_s(gszLastSyntaxError,szOutput);
		LocalFree(szOutput);
	}
}

VOID MacroError(PCHAR szFormat, ...)
{
    va_list vaList;
    va_start( vaList, szFormat );
	int len = _vscprintf( szFormat, vaList )+1;// _vscprintf doesn't count // terminating '\0'
	if(char *szOutput = (char *)LocalAlloc(LPTR,len+32)) {
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
		if (bAllErrorsLog) MacroLog(NULL, "Macro Error");
		if (bAllErrorsLog) MacroLog(NULL, szOutput);
		strcpy(gszLastNormalError,szOutput);
		LocalFree(szOutput);
	}
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
    va_list vaList;
    va_start( vaList, szFormat );
	int len = _vscprintf( szFormat, vaList )+1;// _vscprintf doesn't count // terminating '\0'
	if(char *szOutput = (char *)LocalAlloc(LPTR,len+32)) {
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
		if (bAllErrorsLog) MacroLog(NULL, "Fatal Error");
		if (bAllErrorsLog) MacroLog(NULL, szOutput);
		LocalFree(szOutput);
	}
    if (gMacroBlock)
    {
        DumpStack(0,0);
        EndMacro((PSPAWNINFO)pCharSpawn,"");
    }
}

VOID MQ2DataError(PCHAR szFormat, ...)
{
    va_list vaList;
    va_start( vaList, szFormat );
	int len = _vscprintf( szFormat, vaList )+1;// _vscprintf doesn't count // terminating '\0'
	if(char *szOutput = (char *)LocalAlloc(LPTR,len+32)) {
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
		if (bAllErrorsLog) MacroLog(NULL, "Data Error");
		if (bAllErrorsLog) MacroLog(NULL, szOutput);
		LocalFree(szOutput);
	}
    if (gMacroBlock)
    {
        if (bAllErrorsDumpStack || bAllErrorsFatal)
            DumpStack(0,0);
        if (bAllErrorsFatal)
            EndMacro((PSPAWNINFO)pCharSpawn,"");
    }
}
#endif

#ifndef ISXEQ_LEGACY
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
#endif

#ifndef ISXEQ
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
#endif



#ifndef ISXEQ_LEGACY
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
    //cxstr+=text;
} 

// YES THIS NEEDS TO BE PCXSTR * 
VOID SetCXStr(PCXSTR *cxstr, PCHAR text) 
{ 
    //cxstr=text;
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
    //DebugSpew("StripMQChat(%s)",in);
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
    //DebugSpew("StripMQChat=>(%s)",out);
}

DWORD MQToSTML(PCHAR in, PCHAR out, DWORD maxlen, DWORD ColorOverride)
{
    //DebugSpew("MQToSTML(%s)",in);
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
                            temp[x]=in[pchar_in_string_position++];
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
    while (Filename && strstr(Filename,"\\"))
		Filename=strstr(Filename,"\\")+1;
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
    AddFilter("You take a bite of",                                                     18, &gFilterFood);
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
    if (!_stricmp(szName,"EQUALSIGN")) strcpy(szName,"=");
    if (!_stricmp(szName,"SEMICOLON")) strcpy(szName,";");
    if (!_stricmp(szName,"LEFTBRACKET")) strcpy(szName,"[");
    return szName;
}

// ***************************************************************************
// Function:    GetFullZone
// Description: Returns a full zone name from a short name
// ***************************************************************************
PCHAR GetFullZone(DWORD ZoneID)
{
    ZoneID &= 0x7FFF;
    if (!ppWorldData || (ppWorldData && !pWorldData))
		return NULL;
    if(ZoneID >= MAX_ZONES)
        return "UNKNOWN_ZONE";
    PZONELIST pZone = ((PWORLDDATA)pWorldData)->ZoneArray[ZoneID];
    if(pZone)
	    return pZone->LongName;
    else
		return "UNKNOWN_ZONE";
}
// ***************************************************************************
// Function:    GetShortZone
// Description: Returns a short zone name from a ZoneID
// ***************************************************************************
PCHAR GetShortZone(DWORD ZoneID)
{
    ZoneID &= 0x7FFF;
    if (!ppWorldData || (ppWorldData && !pWorldData))
		return NULL;
    if(ZoneID >= MAX_ZONES)
        return "UNKNOWN_ZONE";
    PZONELIST pZone = ((PWORLDDATA)pWorldData)->ZoneArray[ZoneID];
	if(pZone)
		return pZone->ShortName;
	else
		return "UNKNOWN_ZONE";
}
// ***************************************************************************
// Function:    GetZoneID
// Description: Returns a ZoneID from a short zone name
// ***************************************************************************

DWORD GetZoneID(PCHAR ZoneShortName)
{
    PZONELIST pZone = NULL;
    if (!ppWorldData || (ppWorldData && !pWorldData))
		return (DWORD)-1;
    for (int nIndex=0; nIndex < MAX_ZONES; nIndex++) {
        pZone = ((PWORLDDATA)pWorldData)->ZoneArray[nIndex];
        if(pZone) {
            if (!_stricmp(pZone->ShortName,ZoneShortName)) {
                return nIndex;
            }
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
    if (!ppWorldData || (ppWorldData && !pWorldData))
		return;
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
    if (!ppWorldData || (ppWorldData && !pWorldData))
		return;
    if (Month) *Month=((PWORLDDATA)pWorldData)->Month;
    if (Day) *Day=((PWORLDDATA)pWorldData)->Day;
    if (Year) *Year=((PWORLDDATA)pWorldData)->Year;
}

int GetLanguageIDByName( PCHAR SzName )
{
    if (!_stricmp(SzName, "Common")) return 1;
    if (!_stricmp(SzName, "Common Tongue")) return 1;
    if (!_stricmp(SzName, "Barbarian")) return 2;
    if (!_stricmp(SzName, "Erudian")) return 3;
    if (!_stricmp(SzName, "Elvish")) return 4;
    if (!_stricmp(SzName, "Dark Elvish")) return 5;
    if (!_stricmp(SzName, "Dwarvish")) return 6;
    if (!_stricmp(SzName, "Troll")) return 7;
    if (!_stricmp(SzName, "Ogre")) return 8;
    if (!_stricmp(SzName, "Gnomish")) return 9;
    if (!_stricmp(SzName, "Halfling")) return 10;
    if (!_stricmp(SzName, "Thieves Cant")) return 11;
    if (!_stricmp(SzName, "Old Erudian")) return 12;
    if (!_stricmp(SzName, "Elder Elvish")) return 13;
    if (!_stricmp(SzName, "Froglok")) return 14;
    if (!_stricmp(SzName, "Goblin")) return 15;
    if (!_stricmp(SzName, "Gnoll")) return 16;
    if (!_stricmp(SzName, "Combine Tongue")) return 17;
    if (!_stricmp(SzName, "Elder Tier'Dal")) return 18;
    if (!_stricmp(SzName, "Lizardman")) return 19;
    if (!_stricmp(SzName, "Orcish")) return 20;
    if (!_stricmp(SzName, "Faerie")) return 21;
    if (!_stricmp(SzName, "Dragon")) return 22;
    if (!_stricmp(SzName, "Elder Dragon")) return 23;
    if (!_stricmp(SzName, "Dark Speech")) return 24;
    if (!_stricmp(SzName, "Vah Shir")) return 25;
    return -1;
}

int GetCurrencyIDByName(PCHAR szName)
{
	if (!_stricmp(szName, "Doubloons")) return ALTCURRENCY_DOUBLOONS;  // 0XA
	if (!_stricmp(szName, "Orux")) return ALTCURRENCY_ORUX; //0XB
	if (!_stricmp(szName, "Phosphenes")) return ALTCURRENCY_PHOSPHENES; //0XC
	if (!_stricmp(szName, "Phosphites")) return ALTCURRENCY_PHOSPHITES; //0XD
	if (!_stricmp(szName, "Faycitum")) return ALTCURRENCY_FAYCITES; //0XE
	if (!_stricmp(szName, "Chronobines")) return ALTCURRENCY_CHRONOBINES; //0XF
	if (!_stricmp(szName, "Silver Tokens")) return ALTCURRENCY_SILVERTOKENS; //0X10
	if (!_stricmp(szName, "Gold Tokens")) return ALTCURRENCY_GOLDTOKENS; //0X11
	if (!_stricmp(szName, "McKenzie's Special Brew")) return ALTCURRENCY_MCKENZIE; //0X12
	if (!_stricmp(szName, "Bayle Marks")) return ALTCURRENCY_BAYLE; //0X13   
	if (!_stricmp(szName, "Tokens of Reclamation")) return ALTCURRENCY_RECLAMATION; //0X14
	if (!_stricmp(szName, "Brellium Tokens")) return ALTCURRENCY_BRELLIUM; //0X15
	if (!_stricmp(szName, "Dream Motes")) return ALTCURRENCY_MOTES; //0X16
	if (!_stricmp(szName, "Rebellion Chits")) return ALTCURRENCY_REBELLIONCHITS; //0X17
	if (!_stricmp(szName, "Diamond Coins")) return ALTCURRENCY_DIAMONDCOINS; //0X18
	if (!_stricmp(szName, "Bronze Fiats")) return ALTCURRENCY_BRONZEFIATS; //0X19
	if (!_stricmp(szName, "Expedient Delivery Vouchers")) return ALTCURRENCY_VOUCHER; //0x1a
	if (!_stricmp(szName, "Velium Shards")) return ALTCURRENCY_VELIUMSHARDS; //0X1b
	if (!_stricmp(szName, "Crystallized Fear")) return ALTCURRENCY_CRYSTALLIZEDFEAR; //0X1c
	if (!_stricmp(szName, "Shadowstones")) return ALTCURRENCY_SHADOWSTONES; //0X1d
	if (!_stricmp(szName, "Dreadstones")) return ALTCURRENCY_DREADSTONES; //0X1e
	if (!_stricmp(szName, "Marks of Valor")) return ALTCURRENCY_MARKSOFVALOR; //0X1F
	if (!_stricmp(szName, "Medals of Heroism")) return ALTCURRENCY_MEDALSOFHEROISM; //0X20   
	if (!_stricmp(szName, "Commemorative Coins")) return ALTCURRENCY_COMMEMORATIVE_COINS; //0X21 
	if (!_stricmp(szName, "Fists of Bayle")) return ALTCURRENCY_FISTSOFBAYLE; //0X22
	if (!_stricmp(szName, "Nobles")) return ALTCURRENCY_NOBLES; //0X23
	if (!_stricmp(szName, "Arx Energy Crystals")) return ALTCURRENCY_ENERGYCRYSTALS; //0X24
	if (!_stricmp(szName, "Pieces of Eight")) return ALTCURRENCY_PIECESOFEIGHT; //0X25
	return -1;
}

PSPELL GetSpellBySpellGroupID(LONG dwSpellGroupID)
{
    if (ppSpellMgr) {
		for (DWORD dwSpellID = 0; dwSpellID < TOTAL_SPELL_COUNT; dwSpellID++) {
			if (PSPELL pSpell = GetSpellByID(dwSpellID)) {
				if (pSpell->ID > 0) {
					if (pSpell->SpellGroup == dwSpellGroupID) {
						return pSpell;
					}
				}
			}
		}
    }
    return NULL;
}

PCHAR GetSpellNameBySpellGroupID(LONG dwSpellID)
{
	PSPELL pSpell = GetSpellBySpellGroupID(abs(dwSpellID));
	if (pSpell && pSpell->Name && pSpell->Name[0]!='\0') {
		return pSpell->Name;
	}
    return "Unknown Spell";
}

PCHAR GetSpellNameByID(LONG dwSpellID)
{
	long absedspellid = abs(dwSpellID);
    if (ppSpellMgr && absedspellid!=0 && absedspellid!=-1 && absedspellid < TOTAL_SPELL_COUNT) {
		PSPELL pSpell = GetSpellByID(absedspellid);
		if (pSpell && pSpell->Name && pSpell->Name[0]!='\0') {
			return pSpell->Name;
		}
	}
    return "Unknown Spell";
}
typedef struct _SpellCompare
{
	std::map<DWORD,PSPELL>Duplicates;
} SpellCompare,*PSpellCompare;
std::map<std::string,std::map<std::string,SpellCompare>>g_SpellNameMap;

void PopulateSpellMap()
{
	lockit lk(ghLockSpellMap);
	gbSpelldbLoaded = FALSE;
	g_SpellNameMap.clear();
	std::string lowname,threelow;
	for (DWORD dwSpellID = 0; dwSpellID < TOTAL_SPELL_COUNT; dwSpellID++) {
		if(PSPELL pSpell = ((PSPELLMGR)pSpellMgr)->Spells[dwSpellID]) {
			if(pSpell->Name[0]!='\0') {
				lowname = pSpell->Name;
				std::transform(lowname.begin(), lowname.end(), lowname.begin(), tolower);
				threelow = lowname;
				threelow.erase(3);
				g_SpellNameMap[threelow][lowname].Duplicates[dwSpellID] = pSpell;
			}
		}
	}
	gbSpelldbLoaded = TRUE;
}
BOOL IsSpellClassUsable(PSPELL pSpell)
{
	for (int N = Warrior ; N <= Berserker ; N++)
	{
		if(pSpell->ClassLevel[N]==255 || pSpell->ClassLevel[N]==127) {
			continue;
		} else {
			return TRUE;
		}
	}
	return FALSE;
}
PSPELL GetSpellByName(PCHAR szName)
{
    // PSPELL GetSpellByName(PCHAR NameOrID)
    // This function now accepts SpellID as an argument as well as SpellName
	//echo ${Spell[Concussive Burst].Level}
	//echo ${Spell[Nature's Serenity].Level}
	try {
		if (ppSpellMgr == NULL || gbSpelldbLoaded == FALSE || ghLockSpellMap == NULL || szName == NULL) {
			WriteChatColor("Initializing SpellMap from GetSpellByName, this will take a few seconds, please wait", CONCOLOR_YELLOW);
			InitializeMQ2SpellDb(NULL);
			return NULL;
		}
		lockit lk(ghLockSpellMap);
		if (szName[0] >= '0' && szName[0] <= '9')
		{
			return GetSpellByID(abs(atoi(szName)));
		}

		std::string lowname = szName;
		if (lowname.size() < 3 || g_SpellNameMap.size() == 0)
			return NULL;
		std::transform(lowname.begin(), lowname.end(), lowname.begin(), tolower);
		std::string threelow = lowname;
		threelow.erase(3);

		std::map<std::string, std::map<std::string, SpellCompare>>::iterator i = g_SpellNameMap.find(threelow);
		if (i != g_SpellNameMap.end()) {
			std::map<std::string, SpellCompare>::iterator j = i->second.find(lowname);
			if (j != i->second.end()) {
				std::map<DWORD,PSPELL>::iterator mspell = j->second.Duplicates.begin();
				if(mspell!=j->second.Duplicates.end()) {
					PSPELL pSpell = mspell->second;
					if (j->second.Duplicates.size() > 1) {
						if (PCHARINFO2 pChar2 = GetCharInfo2()) {
							DWORD highestclasslevel = 0;
							DWORD classlevel = 0;
							DWORD playerclass = pChar2->Class;
							DWORD currlevel = pChar2->Level;
							if (playerclass && playerclass >= Warrior && playerclass <= Berserker) {
								for (std::map<DWORD, PSPELL>::iterator k = j->second.Duplicates.begin(); k != j->second.Duplicates.end(); k++) {
									if (k->second) {
										classlevel = k->second->ClassLevel[playerclass];
										if (classlevel <= currlevel && highestclasslevel < classlevel) {
											highestclasslevel = classlevel;
											pSpell = k->second;
										}
									}
								}
							}
							if (highestclasslevel == 0) {
								//well if we got here, the spell the user is after isnt one his character can cast, so
								//we will have to roll through it again and see if its usable by any other class
								for (std::map<DWORD, PSPELL>::iterator k = j->second.Duplicates.begin(); k != j->second.Duplicates.end(); k++) {
									if (k->second && IsSpellClassUsable(k->second)) {
										pSpell = k->second;
									}
								}
							}
						}
					}
					return pSpell;
				}
			}
		}
	}
	catch (...)
	{
		DebugSpewAlways("Caught exception in GetSpellByName");
		throw;
	}
    return NULL;
}

PSPELL GetSpellByAAName(PCHAR szName)
{
	try {
		for (unsigned long nAbility=0 ; nAbility<NUM_ALT_ABILITIES ; nAbility++) {
            if (PALTABILITY pAbility=pAltAdvManager->GetAAById(nAbility)) {
				if(pAbility->SpellID!=-1) {
					if(char *pName = pCDBStr->GetString(pAbility->nName, 1, NULL)) {
						if(!_stricmp(szName,pName)) {
							if(PSPELL psp = GetSpellByID(pAbility->SpellID)) {
								return psp;
							}
						}
					}
				}
			}
		}
	} catch (...) {
		DebugSpewAlways("Caught exception in GetSpellByAAName");
		throw;
	}
    return NULL;
}

DWORD GetSpellDuration(PSPELL pSpell, PSPAWNINFO pSpawn) 
{ 
    switch (pSpell->DurationType) { 
                case 0:          
                    return 0;        
                case 1:        
                case 6: 
                    return unsigned long(min(ceil(double(pSpawn->Level) / 2), pSpell->DurationValue1)); 
                case 3: 
                case 4:              
                case 11: 
                case 12:            
                    if (pSpell->DurationValue1) { 
                        return (pSpell->DurationValue1); 
                    } else {        
                        return (pSpell->DurationType*10); 
                    } 
                case 2: 
                    return unsigned long(min(ceil(double(pSpawn->Level) * 0.6), pSpell->DurationValue1)); 
                case 5:                  
                    return 3; 
                case 7:              
                    return min(pSpawn->Level, pSpell->DurationValue1 ? pSpell->DurationValue1 : pSpawn->Level); 
                case 8: 
                    return min(unsigned int(pSpawn->Level) + 10, pSpell->DurationValue1); 
                case 9:          
                    return min(unsigned int(pSpawn->Level) * 2 + 10, pSpell->DurationValue1); 
                case 10:        
                    return min(unsigned int(pSpawn->Level) * 3 + 10, pSpell->DurationValue1); 
                case 13:
                    return pSpell->DurationValue1 * 6 / 10;
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
    if(PGUILD pGuild = pGuildList->GuildList[GuildID % pGuildList->HashValue])
    {
        while(pGuild->ID != GuildID)
        {
            pGuild = pGuild->pNext;

            if(!pGuild)
                return 0;
        }

        if(pGuild->pGuildData->Name[0])
            return pGuild->pGuildData->Name;        
    }

    return 0;
}

DWORD GetGuildIDByName(PCHAR szGuild)
{
    DWORD n;
    for(n = 0; n < pGuildList->HashValue - 1; n++) {
        if(PGUILD pGuild = pGuildList->GuildList[n]) {
            while (pGuild) {
                if(!_stricmp(pGuild->pGuildData->Name, szGuild))
                    return pGuild->ID;

                pGuild = pGuild->pNext;
            }
        }
    }

    for(n = 0; n < pGuildList->HashValue - 1; n++) {
        if(PGUILD pGuild = pGuildList->GuildList[n]) {
            while (pGuild) {
                if(!strnicmp(pGuild->pGuildData->Name, szGuild, strlen(szGuild)))
                    return pGuild->ID;

                pGuild = pGuild->pNext;
            }
        }
    }

    return 0xFFFFFFFF;
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
        return CONCOLOR_WHITE; // its you

    switch(pCharData->GetConLevel((EQPlayer*)pSpawn))
    {
    case 0:
    case 1:
        return CONCOLOR_GREY;
    case 2:
        return CONCOLOR_GREEN;
    case 3:
        return CONCOLOR_LIGHTBLUE;
    case 4:
        return CONCOLOR_BLUE;
    case 5:    
        return CONCOLOR_WHITE;
    case 6:
        return CONCOLOR_YELLOW;
    case 7:
        return CONCOLOR_RED;
    default:
        return COLOR_PURPLE;
    }
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

    for (int j = 0; j < 35; j++)
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
    ((EQ_Item*)Item)->CreateItemTagString(Buffer, 256);
}

BOOL GetItemLink(PCONTENTS Item, PCHAR Buffer, BOOL Clickable)
{
	char hash[512] = {0};
	bool retVal = FALSE;
    ((EQ_Item*)Item)->CreateItemTagString(hash, 512);
	if (hash[0]) {
	    if (Clickable) 
			sprintf(Buffer,"%c0%s%s%c",0x12,hash,GetItemFromContents(Item)->Name,0x12);
		else 
			sprintf(Buffer,"0%s%s",hash,GetItemFromContents(Item)->Name);
		retVal = TRUE;
	}
    DebugSpew("GetItemLink() returns '%s'",&Buffer[0]);
	return retVal;
}

PCHAR GetLoginName() 
{
	if(__LoginName) {
		return (PCHAR)__LoginName;
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
               if (!_stricmp(Amper,"nbsp")) {
                   out[pchar_out_string_position++] = ' ';
               } else if (!_stricmp(Amper,"amp")) {
                   out[pchar_out_string_position++] = '&';
               } else if (!_stricmp(Amper,"gt")) {
                   out[pchar_out_string_position++] = '>';
               } else if (!_stricmp(Amper,"lt")) {
                   out[pchar_out_string_position++] = '<';
               } else if (!_stricmp(Amper,"quot")) {
                   out[pchar_out_string_position++] = '\"';
               } else if (!_stricmp(Amper,"pct")) {
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
    if (SearchItem.ID && GetItemFromContents(pContents)->ItemNumber!=SearchItem.ID)
        return false;
    RequireFlag(Lore,GetItemFromContents(pContents)->Lore);
    RequireFlag(NoRent,GetItemFromContents(pContents)->NoRent);
    RequireFlag(NoDrop,GetItemFromContents(pContents)->NoDrop);
    RequireFlag(Magic,GetItemFromContents(pContents)->Magic);
    RequireFlag(Pack,GetItemFromContents(pContents)->Type==ITEMTYPE_PACK);
    RequireFlag(Book,GetItemFromContents(pContents)->Type==ITEMTYPE_BOOK);
    RequireFlag(Combinable,GetItemFromContents(pContents)->ItemType==17);
    RequireFlag(Summoned,GetItemFromContents(pContents)->Summoned);
    RequireFlag(Instrument,GetItemFromContents(pContents)->InstrumentType);
    RequireFlag(Weapon,GetItemFromContents(pContents)->Damage && GetItemFromContents(pContents)->Delay);
    RequireFlag(Normal,GetItemFromContents(pContents)->Type==ITEMTYPE_NORMAL);

    CHAR szName[MAX_STRING] = {0};
    if (SearchItem.szName[0] && !strstr(_strlwr(strcpy(szName,GetItemFromContents(pContents)->Name)),SearchItem.szName))
        return FALSE;

    return true;
}

BOOL SearchThroughItems(SEARCHITEM &SearchItem, PCONTENTS* pResult, DWORD *nResult)
{
    // TODO
#define Result(pcontents,nresult)     {\
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
            if (PCONTENTS pContents=GetCharInfo2()->pInventoryArray->InventoryArray[N])
                if (ItemMatchesSearch(SearchItem,pContents))
                    Result(pContents,N);
        }
    }

    if (MaskSet(Inventory) && Flag(Inventory))
    {
        unsigned long nPack;
        // iterate through inventory slots before in-pack slots
        for (nPack = 0 ; nPack<10 ; nPack++)
        {
            if (PCONTENTS pContents=GetCharInfo2()->pInventoryArray->Inventory.Pack[nPack])
            {
                if (ItemMatchesSearch(SearchItem,pContents))
                    Result(pContents,nPack+21);
            }
        }
        for (nPack = 0 ; nPack<10 ; nPack++)
        {
            if (PCONTENTS pContents=GetCharInfo2()->pInventoryArray->Inventory.Pack[nPack]) {
                if (GetItemFromContents(pContents)->Type==ITEMTYPE_PACK && pContents->pContentsArray)
                {
                    for (unsigned long nItem = 0 ; nItem<GetItemFromContents(pContents)->Slots ; nItem++)
                    {
                        if (PCONTENTS pItem=pContents->pContentsArray->Contents[nItem])
                            if (ItemMatchesSearch(SearchItem,pItem))
                                Result(pItem,nPack*100+nItem);
                    }
                }
			}
        }
    }
    // TODO
    return 0;
}
#undef RequireFlag
#undef Flag
#undef MaskSet

VOID ClearSearchSpawn(PSEARCHSPAWN pSearchSpawn)
{
    if (!pSearchSpawn) return;
    ZeroMemory(pSearchSpawn,sizeof(SEARCHSPAWN));
    // 0? fine. set anything thats NOT zero.
    pSearchSpawn->MaxLevel = MAX_NPC_LEVEL;
    pSearchSpawn->SpawnType = NONE;
    pSearchSpawn->GuildID = 0xFFFFFFFF;
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
// Function:    IsBardSong
// Description: Return TRUE if the spell is a bard song
// *************************************************************************** 
BOOL IsBardSong(PSPELL pSpell)
{ 
    return (((EQ_Spell*)pSpell)->GetSpellLevelNeeded(Bard)<=MAX_PC_LEVEL)
				&& !(pSpell->DurationWindow);
}

// *************************************************************************** 
// Function:    IsSPAEffect
// Description: Return TRUE if the spell contains the SPAEffect
// *************************************************************************** 
BOOL IsSPAEffect(PSPELL pSpell, LONG EffectID)
{ 
    for (int slot=0; slot<12; slot++) 
		if (pSpell->Attrib[slot]==EffectID)
			return true;
    return false;
}

// *************************************************************************** 
// Function:    GetClassesFromMask
// Description: Return a comma delimited list of player short class names
// *************************************************************************** 
PCHAR GetClassesFromMask(LONG mask, PCHAR szBuffer)
{
	//WriteChatf("GetClassesFromMask:: MASK:%d", mask);
	for (int playerclass=Warrior; playerclass<=Berserker; playerclass++) {
		//WriteChatf("Checking playerclass(%d)", 1 << playerclass);
		if (mask & (1 << playerclass)) {
			if (strlen(szBuffer) > 0)
				strcat(szBuffer, ",");
			strcat(szBuffer, ClassInfo[playerclass].UCShortName);
		}
	}
	return szBuffer;
}

// *************************************************************************** 
// Function:    GetSpellRestrictions 
// Description: Return the restrictions for the spell slot
// *************************************************************************** 
PCHAR GetSpellRestrictions(PSPELL pSpell, unsigned int nIndex, PCHAR szBuffer)
{
	CHAR szTemp[MAX_STRING] = {0};
	if (!szBuffer)
		return NULL;
	if (!pSpell) {
		szBuffer[0] = '\0';
		return(szBuffer);
	}
	switch (pSpell->Base2[nIndex])
	{
	case 0:	strcat(szBuffer, "None"); break;
	case 100: strcat(szBuffer, "Only works on Animal or Humanoid"); break;
	case 101: strcat(szBuffer, "Only works on Dragon"); break;
	case 102: strcat(szBuffer, "Only works on Animal or Insect"); break;
	case 104: strcat(szBuffer, "Only works on Animal"); break;
	case 105: strcat(szBuffer, "Only works on Plant"); break;
	case 106: strcat(szBuffer, "Only works on Giant"); break;
	case 108: strcat(szBuffer, "Doesn't work on Animals or Humanoids"); break;
	case 109: strcat(szBuffer, "Only works on Bixie"); break;
	case 110: strcat(szBuffer, "Only works on Harpy"); break;
	case 111: strcat(szBuffer, "Only works on Gnoll"); break;
	case 112: strcat(szBuffer, "Only works on Sporali"); break;
	case 113: strcat(szBuffer, "Only works on Kobold"); break;
	case 114: strcat(szBuffer, "Only works on Shade"); break;
	case 115: strcat(szBuffer, "Only works on Drakkin"); break;
	case 117: strcat(szBuffer, "Only works on Animals or Plants"); break;
	case 118: strcat(szBuffer, "Only works on Summoned"); break;
	case 119: strcat(szBuffer, "Only works on Fire_Pet"); break;
	case 120: strcat(szBuffer, "Only works on Undead"); break;
	case 121: strcat(szBuffer, "Only works on Living"); break;
	case 122: strcat(szBuffer, "Only works on Fairy"); break;
	case 123: strcat(szBuffer, "Only works on Humanoid"); break;
	case 124: strcat(szBuffer, "Undead HP Less Than 10%"); break;
	case 125: strcat(szBuffer, "Clockwork HP Less Than 45%"); break;
	case 126: strcat(szBuffer, "Wisp HP Less Than 10%"); break;
	case 190: strcat(szBuffer, "Doesn't work on Raid Bosses"); break;
	case 191: strcat(szBuffer, "Only works on Raid Bosses"); break;
	case 201: strcat(szBuffer, "HP Above 75%"); break;
	case 203: strcat(szBuffer, "HP Less Than 20%"); break;
	case 204: strcat(szBuffer, "HP Less Than 50%"); break;
	case 216: strcat(szBuffer, "Not In Combat"); break;
	case 221: strcat(szBuffer, "At Least 1 Pet On Hatelist"); break;
	case 222: strcat(szBuffer, "At Least 2 Pets On Hatelist"); break;
	case 223: strcat(szBuffer, "At Least 3 Pets On Hatelist"); break;
	case 224: strcat(szBuffer, "At Least 4 Pets On Hatelist"); break;
	case 225: strcat(szBuffer, "At Least 5 Pets On Hatelist"); break;
	case 226: strcat(szBuffer, "At Least 6 Pets On Hatelist"); break;
	case 227: strcat(szBuffer, "At Least 7 Pets On Hatelist"); break;
	case 228: strcat(szBuffer, "At Least 8 Pets On Hatelist"); break;
	case 229: strcat(szBuffer, "At Least 9 Pets On Hatelist"); break;
	case 230: strcat(szBuffer, "At Least 10 Pets On Hatelist"); break;
	case 231: strcat(szBuffer, "At Least 11 Pets On Hatelist"); break;
	case 232: strcat(szBuffer, "At Least 12 Pets On Hatelist"); break;
	case 233: strcat(szBuffer, "At Least 13 Pets On Hatelist"); break;
	case 234: strcat(szBuffer, "At Least 14 Pets On Hatelist"); break;
	case 235: strcat(szBuffer, "At Least 15 Pets On Hatelist"); break;
	case 236: strcat(szBuffer, "At Least 16 Pets On Hatelist"); break;
	case 237: strcat(szBuffer, "At Least 17 Pets On Hatelist"); break;
	case 238: strcat(szBuffer, "At Least 18 Pets On Hatelist"); break;
	case 239: strcat(szBuffer, "At Least 19 Pets On Hatelist"); break;
	case 240: strcat(szBuffer, "At Least 20 Pets On Hatelist"); break;
	case 250: strcat(szBuffer, "HP Less Than 35%"); break;
	case 304: strcat(szBuffer, "Chain Plate Classes"); break;
	case 399: strcat(szBuffer, "HP Between 15 and 25%"); break;
	case 400: strcat(szBuffer, "HP Between 1 and 25%"); break;
	case 401: strcat(szBuffer, "HP Between 25 and 35%"); break;
	case 402: strcat(szBuffer, "HP Between 35 and 45%"); break;
	case 403: strcat(szBuffer, "HP Between 45 and 55%"); break;
	case 404: strcat(szBuffer, "HP Between 55 and 65%"); break;
	case 412: strcat(szBuffer, "HP Above 99%"); break;
	case 501: strcat(szBuffer, "HP Below 5%"); break;
	case 502: strcat(szBuffer, "HP Below 10%"); break;
	case 503: strcat(szBuffer, "HP Below 15%"); break;
	case 504: strcat(szBuffer, "HP Below 20%"); break;
	case 505: strcat(szBuffer, "HP Below 25%"); break;
	case 506: strcat(szBuffer, "HP Below 30%"); break;
	case 507: strcat(szBuffer, "HP Below 35%"); break;
	case 508: strcat(szBuffer, "HP Below 40%"); break;
	case 509: strcat(szBuffer, "HP Below 45%"); break;
	case 510: strcat(szBuffer, "HP Below 50%"); break;
	case 511: strcat(szBuffer, "HP Below 55%"); break;
	case 512: strcat(szBuffer, "HP Below 60%"); break;
	case 513: strcat(szBuffer, "HP Below 65%"); break;
	case 514: strcat(szBuffer, "HP Below 70%"); break;
	case 515: strcat(szBuffer, "HP Below 75%"); break;
	case 516: strcat(szBuffer, "HP Below 80%"); break;
	case 517: strcat(szBuffer, "HP Below 85%"); break;
	case 518: strcat(szBuffer, "HP Below 90%"); break;
	case 519: strcat(szBuffer, "HP Below 95%"); break;
	case 521: strcat(szBuffer, "Mana Below X%"); break;
	case 522: strcat(szBuffer, "End Below 40%"); break;
	case 523: strcat(szBuffer, "Mana Below 40%"); break;
	case 603: strcat(szBuffer, "Only works on Undead2"); break;
	case 608: strcat(szBuffer, "Only works on Undead3"); break;
	case 624: strcat(szBuffer, "Only works on Summoned2"); break;
	case 701: strcat(szBuffer, "Doesn't work on Pets"); break;
	case 818: strcat(szBuffer, "Only works on Undead4"); break;
	case 819: strcat(szBuffer, "Doesn't work on Undead4"); break;
	case 825: strcat(szBuffer, "End Below 21%"); break;
	case 826: strcat(szBuffer, "End Below 25%"); break;
	case 827: strcat(szBuffer, "End Below 29%"); break;
	case 836: strcat(szBuffer, "Only works on Regular Servers"); break;
	case 837: strcat(szBuffer, "Doesn't work on Progression Servers"); break;
	case 842: strcat(szBuffer, "Only works on Humanoid Level 84 Max"); break;
	case 843: strcat(szBuffer, "Only works on Humanoid Level 86 Max"); break;
	case 844: strcat(szBuffer, "Only works on Humanoid Level 88 Max"); break;
	case 1000: strcat(szBuffer, "Between Level 1 and 75"); break;
	case 1001: strcat(szBuffer, "Between Level 76 and 85"); break;
	case 1002: strcat(szBuffer, "Between Level 86 and 95"); break;
	case 1003: strcat(szBuffer, "Between Level 96 and 100"); break;
	case 1004: strcat(szBuffer, "HP Less Than 80%"); break;
	case 38311: strcat(szBuffer, "Mana Below 20%"); break;
	case 38312: strcat(szBuffer, "Mana Below 10%"); break;
	default: strcat(szBuffer, "Unknown"); break;
	}
	return szBuffer;
}

// ***************************************************************************
// Function:    GetSpellEffectName, GetSpellEffectNameByID
// Description: Return spell effect string 
// ***************************************************************************
PCHAR GetSpellEffectNameByID(LONG EffectID)
{
	CHAR szTemp[MAX_STRING] = {0};

	return GetSpellEffectName(abs(EffectID), szTemp);
}

PCHAR GetSpellEffectName(LONG EffectID, PCHAR szBuffer) 
{
	//we CAN do an abs here cause IF it is negative, it just means we should display is as "Exclude: "
	LONG absEffectID = abs(EffectID);
	if(absEffectID<=MAX_SPELLEFFECTS) {
		strcat(szBuffer,szSPATypes[absEffectID]);
	} else {
		CHAR szTemp[MAX_STRING]={0};
		sprintf_s(szTemp, "UndefinedEffect%03d", absEffectID);
		strcat(szBuffer,szTemp);
    }
	return szBuffer;
} 

PCHAR GetResistTypeName(LONG ResistType, PCHAR szBuffer)
{
    switch(ResistType)
    { 
    case 1: strcat(szBuffer, "Magic"); break; 
    case 2: strcat(szBuffer, "Fire"); break; 
    case 3: strcat(szBuffer, "Cold/Ice"); break; 
    case 4: strcat(szBuffer, "Poison"); break; 
    case 5: strcat(szBuffer, "Disease"); break; 
    case 6: strcat(szBuffer, "Chromatic"); break; 
    case 7: strcat(szBuffer, "Prismatic"); break; 
    default: strcat(szBuffer, "Unknown"); break; 
    } 
	return szBuffer;
}

PCHAR GetSpellTypeName(LONG SpellType, PCHAR szBuffer)
{
    switch(SpellType) 
    { 
    case 0: strcat(szBuffer,"Detrimental only"); break; 
    case 1: strcat(szBuffer,"Beneficial only"); break; 
    case 2: strcat(szBuffer,"Beneficial - Group Only"); break; 
    default: strcat(szBuffer, "Unknown"); break; 
    } 
	return szBuffer;
}

PCHAR GetTargetTypeLimitsName(LONG TargetLimitsType, PCHAR szBuffer)
{
    switch(abs(TargetLimitsType)) 
    { 
    case 50: strcat(szBuffer,"Target AE No Players Pets"); break; // blanket of forgetfullness. beneficial, AE mem blur, with max targets
    case 47: strcat(szBuffer,"Pet Owner"); break;
    case 46: strcat(szBuffer,"Target of Target"); break;
    case 45: strcat(szBuffer,"Free Target"); break;
    case 44: strcat(szBuffer,"Beam"); break;
    case 43: strcat(szBuffer,"Single in Group"); break;
    case 42: strcat(szBuffer,"Directional AE"); break;
    case 39: strcat(szBuffer,"No Pets"); break;
    case 38: strcat(szBuffer,"Pet2"); break;
    case 37: strcat(szBuffer,"Caster PB NPC"); break;
    case 36: strcat(szBuffer,"Caster PB PC"); break;
    case 35: strcat(szBuffer,"Special Muramites"); break;
    case 34: strcat(szBuffer,"Chest"); break;
    case 33: strcat(szBuffer,"Hatelist2"); break;
    case 32: strcat(szBuffer,"Hatelist"); break;
    case 41: strcat(szBuffer,"Group v2"); break; 
    case 40: strcat(szBuffer,"AE PC v2"); break; 
    case 25: strcat(szBuffer,"AE Summoned"); break; 
    case 24: strcat(szBuffer,"AE Undead"); break; 
    case 20: strcat(szBuffer,"Targeted AE Tap"); break; 
    case 18: strcat(szBuffer,"Uber Dragons"); break; 
    case 17: strcat(szBuffer,"Uber Giants"); break; 
    case 16: strcat(szBuffer,"Plant"); break; 
    case 15: strcat(szBuffer,"Corpse"); break; 
    case 14: strcat(szBuffer,"Pet"); break; 
    case 13: strcat(szBuffer,"LifeTap"); break; 
    case 11: strcat(szBuffer,"Summoned"); break; 
    case 10: strcat(szBuffer,"Undead"); break; 
    case 9: strcat(szBuffer,"Animal"); break; 
    case 8: strcat(szBuffer,"Targeted AE"); break; 
    case 6: strcat(szBuffer,"Self"); break; 
    case 5: strcat(szBuffer,"Single"); break; 
    case 4: strcat(szBuffer,"PB AE"); break; 
    case 3: strcat(szBuffer,"Group v1"); break; 
    case 2: strcat(szBuffer,"AE PC v1"); break; 
    case 1: strcat(szBuffer,"Line of Sight"); break; 
    default: strcat(szBuffer,"Unknown"); break; 
    } 
	return szBuffer;
}

PCHAR GetStatShortName(LONG StatType, PCHAR szBuffer)
{
    switch (StatType)
	{ 
    case 0: strcat (szBuffer, "STR"); break; 
    case 1: strcat (szBuffer, "STA"); break; 
    case 2: strcat (szBuffer, "AGI"); break; 
    case 3: strcat (szBuffer, "DEX"); break; 
    case 4: strcat (szBuffer, "WIS"); break; 
    case 5: strcat (szBuffer, "INT"); break; 
    case 6: strcat (szBuffer, "CHA"); break; 
	case 7: strcat (szBuffer, "MR"); break;
	case 8: strcat (szBuffer, "CR"); break;
	case 9: strcat (szBuffer, "FR"); break;
	case 10: strcat (szBuffer, "PR"); break;  // either PR or DR
	case 11: strcat (szBuffer, "DR"); break;  // either DR or PR
    default: strcat (szBuffer, "Unknown"); break;
    } 
	return szBuffer;
}

PCHAR GetFactionName(LONG FactionType, PCHAR szBuffer)
{
    switch (FactionType)
	{ 
	case 1178: strcat(szBuffer, "(S.H.I.P. Workshop Base Population)"); break;
	case 1150: strcat(szBuffer, "(Jewel of Atiiki Efreetis)"); break;
	case 1229: strcat(szBuffer, "(Sebilisian Empire)"); break;
    default: strcat (szBuffer, "(Unknown)"); break;
    } 
	return szBuffer;
}

LONG CalcDuration(LONG calc, LONG max, LONG level)
{
	LONG value=0;

	switch (calc)
	{
	case 0:  value = 0; break;
	case 1:
	case 12:
		value = level / 2;
		if (value < 1)
			value = 1;
		break;
	case 2:
		value = (level / 2) + 5;
		if (value < 6)
			value = 6;
		break;
	case 3:  value = level * 30; break;
	case 4:  value = 50; break;
	case 5:  value = 2; break;
	case 6:  value = level / 2; break;
	case 7:  value = level; break;
	case 8:  value = level + 10; break;
	case 9:  value = level * 2 + 10; break;
	case 10: value = level * 30 + 10; break;
	case 11: value = (level + 3) * 30; break;
	case 13: value = level * 3 + 10; break;
	case 14: value = (level + 2) * 5; break;
	case 15: value = (level + 10) * 10; break;
	case 50: value = 72000; break;
	case 3600: value = 3600; break;
	default: value = max;
	}

	if (max > 0 && value > max)
		value = max;

	return value;
}

LONG CalcValue(LONG calc, LONG base, LONG max, LONG tick, LONG minlevel, LONG level)
{
	if (calc == 0)
		return base;
	if (calc == 100) {
		if (max > 0 && ((base > max) || (level > minlevel)))
			return max;
		return base;
	}

	LONG change = 0;
	LONG adjustment = 0;

	switch (calc)
	{
	case 100: 
		break;
	case 101: 
		change = level / 2; 
		break;
	case 102:
		change = level;
		break;
	case 103:
		change = level * 2;
		break;
	case 104:
		change = level * 3;
		break;
	case 105:
		change = level * 4;
		break;
	case 106: 
		change = level * 5;
		break;
	case 107:
		change = -1 * tick;
		break;
	case 108: 
		change = -2 * tick; 
		break;
	case 109: 
		change = level / 4; 
		break;
	case 110: 
		change = level / 6; 
		break;
	case 111: 
		//if (level < 16) adjustment = (level - 16) * 6;
		if (level > 16) change = (level - 16) * 6; 
		break;
	case 112: 
		//if (level < 24) adjustment = (level - 24) * 8;
		if (level > 24) change = (level - 24) * 8; 
		break;
	case 113: 
		//if (level < 34) adjustment = (level - 34) * 10;
		if (level > 34) change = (level - 34) * 10; 
		break;
	case 114: 
		//if (level < 44) adjustment = (level - 44) * 15;
		if (level > 44) change = (level - 44) * 15; 
		break;
	case 115: 
		//if (level < 15) adjustment = (level - 15) * 7;
		if (level > 15) change = (level - 15) * 7;
		break;
	case 116: 
		//if (level < 24) adjustment = (level - 24) * 10;
		if (level > 24) change = (level - 24) * 10; 
		break;
	case 117: 
		//if (level < 34) adjustment = (level - 34) * 13;
		if (level > 34) change = (level - 34) * 13; 
		break;
	case 118: 
		//if (level < 44) adjustment = (level - 44) * 20;
		if (level > 44) change = (level - 44) * 20; 
		break;
	case 119: 
		change = level / 8; 
		break;
	case 120: 
		change = -5 * tick; 
		break;
	case 121: 
		change = level / 3; 
		break;
	case 122: 
		change = -12 * tick; 
		break;
	case 123: // random in range
		if (tick > 1) change = abs(max) - abs(base);
		//change = (abs(max) - abs(base)) / 2;
		break;
	case 124: 
		//if (level < 50) adjustment = (level - 50);
		if (level > 50) change = (level - 50);
		break;
	case 125: 
		//if (level < 50) adjustment = (level - 50) * 2;
		if (level > 50) change = (level - 50) * 2;
		break;
	case 126:
		//if (level < 50) adjustment = (level - 50) * 3;
		if (level > 50) change = (level - 50) * 3;
		break;
	case 127:
		//if (level < 50) adjustment = (level - 50) * 4;
		if (level > 50) change = (level - 50) * 4;
		break;
	case 128:
		//if (level < 50) adjustment = (level - 50) * 5;
		if (level > 50) change = (level - 50) * 5;
		break;
	case 129:
		//if (level < 50) adjustment = (level - 50) * 10;
		if (level > 50) change = (level - 50) * 10;
		break;
	case 130:
		//if (level < 50) adjustment = (level - 50) * 15;
		if (level > 50) change = (level - 50) * 15;
		break;
	case 131:
		//if (level < 50) adjustment = (level - 50) * 20;
		if (level > 50) change = (level - 50) * 20;
		break;
	case 132:
		//if (level < 50) adjustment = (level - 50) * 25;
		if (level > 50) change = (level - 50) * 25;
		break;
	case 139:
		//if (level < 30) adjustment = (level - 30) / 2;
		if (level > 30) change = (level - 30) / 2;
		break;
	case 140:
		//if (level < 30) adjustment = (level - 30);
		if (level > 30) change = (level - 30);
		break;
	case 141:
		//if (level < 30) adjustment = 3 * (level - 30) / 2;
		if (level > 30) change = 3 * (level - 30) / 2;
		break;
	case 142:
		//if (level < 30) adjustment = 2 * (level - 30);
		if (level > 30) change = 2 * (level - 30);
		break;
	case 143:
		change = 3 * level / 4;
		break;
	case 3000:
		return base;
	default:
		if (calc > 0 && calc < 1000)
			change = level * calc;
		if (calc >= 1000 && calc < 2000)
			change = tick * (calc - 1000) * -1;
		if (calc >= 2000)
			change = level * (calc - 2000);
	}

	LONG value = abs(base) + adjustment + change;
	//WriteChatf("#1-VALUE:%d", value);

	if (max != 0 && value > abs(max))
		value = abs(max);
	//WriteChatf("#2-VALUE:%d", value);

	if (base < 0)
		value = -value;
	//WriteChatf("#3-BASE: %d, VALUE:%d", base, value);

	return value;
}

LONG CalcMaxSpellLevel(LONG calc, LONG base, LONG max, LONG tick, LONG minlevel, LONG level)
{
	//WriteChatf("CalcMaxSpellLevel(CALC:%d, BASE:%d, MAX:%d, TICK:%d, LEVEL:%d)", calc, base, max, tick, level);
	if (abs(max)>0) {
		//WriteChatf("Inside if (abs(max)>0)");
		for (LONG maxlevel=1; maxlevel<=level; maxlevel++) {
			LONG value=CalcValue(calc, base, max, tick, minlevel, maxlevel);
			//WriteChatf("VALUE:%d, MAX:%d", abs(value), abs(max));
			if (abs(CalcValue(calc, base, max, tick, minlevel, maxlevel)) >= abs(max))
				return maxlevel;
		}
		return level;
	}
	return MAX_PC_LEVEL;
}

LONG CalcMinSpellLevel(PSPELL pSpell)
{
	LONG minspelllvl=((EQ_Spell*)pSpell)->GetSpellLevelNeeded(Warrior);
    for (LONG j=Warrior; j<=Berserker; j++) 
		if ( ((EQ_Spell*)pSpell)->GetSpellLevelNeeded(j)<minspelllvl )  minspelllvl=((EQ_Spell*)pSpell)->GetSpellLevelNeeded(j);
	if (minspelllvl>MAX_PC_LEVEL)
		minspelllvl=1;
	return minspelllvl;
}

PCHAR CalcValueRange(LONG calc, LONG base, LONG max, LONG duration, LONG minlevel, LONG level, PCHAR szBuffer, PCHAR szPercent)
{
	LONG start=CalcValue(calc, base, max, 1, minlevel, minlevel);
	LONG finish=CalcValue(calc, base, max, duration, minlevel, level);
	CHAR type[MAX_STRING]={0};

	sprintf(type, "%s", abs(start) < abs(finish)?"Growing":"Decaying");

	switch (calc)
	{
	case 107:
		sprintf(szBuffer, " (%s to %d @ 1/tick)", type, finish);
		break;
	case 108:
		sprintf(szBuffer, " (%s to %d @ 2/tick)", type, finish);
		break;
	case 120:
		sprintf(szBuffer, " (%s to %d @ 5/tick)", type, finish);
		break;
	case 122:
		sprintf(szBuffer, " (%s to %d @ 12/tick)", type, finish);
		break;
	case 123:
		sprintf(szBuffer, " (Random: %d to %d)", start, finish * ((start >= 0)? 1: -1));
		break;
	default:
		if (calc > 0 && calc < 1000)
			sprintf(szBuffer, " to %d%s", start, szPercent);
		if (calc >= 1000 && calc < 2000)
			sprintf(szBuffer, " (%s to %d @ %d/tick)", type, finish, calc - 1000);
	}
	return szBuffer;
}

PCHAR CalcExtendedRange(LONG calc, LONG start, LONG finish, LONG minlevel, LONG maxlevel, PCHAR szBuffer, PCHAR szPercent, BOOL ACMod=FALSE)
{
	switch (calc)
	{
	case 123:
		sprintf(szBuffer, " (Random: %d to %d)", start, finish * ((start >= 0)? 1: -1));
		break;
	default:
		if (abs(start) < abs(finish))
			sprintf(szBuffer, " by %d%s (L%d) to %d%s (L%d)", ACMod?(LONG)(abs(start) / (10.0f / 3.0f)):abs(start), szPercent, minlevel, ACMod?(LONG)(abs(finish) / (10.0f / 3.0f)):abs(finish), szPercent, maxlevel);
		else
			sprintf(szBuffer, " by %d%s", ACMod?(LONG)(abs(finish) / (10.0f / 3.0f)):abs(finish), szPercent);
	}
	return szBuffer;
}

PCHAR FormatAT(PCHAR szEffectName, LONG value, PCHAR szBuffer, PCHAR preposition="by", PCHAR szPercent="")
{
	sprintf(szBuffer, "%s %s %d%s", szEffectName, preposition, abs(value), szPercent);
	return szBuffer;
}

PCHAR FormatBase(PCHAR szEffectName, LONG base, PCHAR szBuffer)
{
	sprintf(szBuffer, "%s(%d)", szEffectName, base);
	return szBuffer;
}

PCHAR FormatBase(PCHAR szEffectName, LONG base, LONG max, PCHAR szBuffer)
{
	sprintf(szBuffer, "%s(%d,%d)", szEffectName, base, max);
	return szBuffer;
}

PCHAR FormatBase(PCHAR szEffectName, LONG base, PCHAR szOptional, PCHAR szBuffer)
{
	sprintf(szBuffer, "%s %s(%d)", szEffectName, szOptional, base);
	return szBuffer;
}

PCHAR FormatBasePercent(PCHAR szEffectName, LONG base, PCHAR szBuffer)
{
	sprintf(szBuffer, "%s(%d%%)", szEffectName, base);
	return szBuffer;
}

PCHAR FormatCount(PCHAR szEffectName, LONG value, PCHAR szBuffer, PCHAR preposition="by", PCHAR szPercent="")
{
	sprintf(szBuffer, "%s %s %s %d%s", value<0?"Decrease":"Increase", szEffectName, preposition, abs(value), szPercent);
	return szBuffer;
}

PCHAR FormatExtra(PCHAR szEffectName, PCHAR extra, PCHAR szBuffer, PCHAR trigger="")
{
	sprintf(szBuffer, "%s: %s%s", szEffectName, extra, trigger);
	return szBuffer;
}

PCHAR FormatLimits(PCHAR szEffectName, LONG value, PCHAR extra, PCHAR szBuffer)
{
	sprintf(szBuffer, "%s (%s %s)", szEffectName, extra, value<0?"excluded":"allowed");
	return szBuffer;
}

PCHAR FormatMax(PCHAR szEffectName, LONG value, LONG max, PCHAR szBuffer)
{
    sprintf(szBuffer, "%s %s by %d (%d%% max)", max<0?"Decrease":"Increase", szEffectName, abs(max), value); 
	return szBuffer;
}

PCHAR FormatPenaltyChance(PCHAR szEffectName, LONG value, PCHAR szBuffer, PCHAR szPercent, PCHAR penaltychance)
{
	if (value < 100)
		sprintf(szBuffer, "%s (%d%s %s)", szEffectName, value, szPercent, penaltychance); 
	else
		sprintf(szBuffer, "%s", szEffectName);
	return szBuffer;
}

PCHAR FormatPercent(PCHAR szEffectName, LONG value, LONG max, PCHAR szBuffer, BOOL scaling=TRUE, BOOL hundreds=FALSE)
{
	CHAR szPercent[MAX_STRING]="%";
	if (hundreds)
		if (value == max)
			if (scaling)
				sprintf(szBuffer, "%s %s by %.2f%s", max<0?"Decrease":"Increase", szEffectName, abs(max/100.0f), szPercent);
			else
				sprintf(szBuffer, "%s by %.2f%s", szEffectName, abs(max/100.0f), szPercent);
		else
			if (scaling)
				sprintf(szBuffer, "%s %s by %.2f%s to %.2f%s", max<0?"Decrease":"Increase", szEffectName, abs(value/100.0f), szPercent, abs(max/100.0f), szPercent);
			else
				sprintf(szBuffer, "%s by %.2f%s to %.2f%s", szEffectName, abs(value/100.0f), szPercent, abs(max/100.0f), szPercent);
	else
		if (value == max)
			if (scaling)
				sprintf(szBuffer, "%s %s by %d%s", max<0?"Decrease":"Increase", szEffectName, abs(max), szPercent);
			else
				sprintf(szBuffer, "%s by %d%s", szEffectName, abs(max), szPercent);
		else
			if (scaling)
				sprintf(szBuffer, "%s %s by %d%s to %d%s", max<0?"Decrease":"Increase", szEffectName, abs(value), szPercent, abs(max), szPercent);
			else
				sprintf(szBuffer, "%s by %d%s to %d%s", szEffectName, abs(value), szPercent, abs(max), szPercent);
	return szBuffer;
}

PCHAR FormatPercent(PCHAR szEffectName, LONG value, PCHAR szBuffer, BOOL scaling=TRUE, BOOL hundreds=FALSE)
{
	return FormatPercent(szEffectName, value, value, szBuffer, scaling, hundreds);
}

PCHAR FormatRange(PCHAR szEffectName, LONG value, PCHAR range, PCHAR szBuffer)
{
	sprintf(szBuffer, "%s %s%s", value<0?"Decrease":"Increase", szEffectName, range);
	return szBuffer;
}

PCHAR FormatRateMod(PCHAR szEffectName, LONG value, LONG base, PCHAR szBuffer)
{
	if (base > 0)
		sprintf(szBuffer, "%s (rate mod %d)", GetSpellNameByID(value), base);
	else
		strcat(szBuffer, GetSpellNameByID(value));
	return szBuffer;
}

PCHAR FormatRefreshTimer(PCHAR szEffectName, LONG value, LONG max, LONG skill, PCHAR szBuffer, PCHAR preposition="with")
{
	if (value == max)
		sprintf(szBuffer, "%s %s by %d sec %s %s", max<0?"Decrease":"Increase", szEffectName, abs(max), preposition, skill>=0?szSkills[skill]:"All Skills");
	else
		sprintf(szBuffer, "%s %s by %d sec to %d sec %s %s", max<0?"Decrease":"Increase", szEffectName, abs(value), abs(max), preposition, skill>=0?szSkills[skill]:"All Skills");
	return szBuffer;
}

PCHAR FormatRefreshTimer(PCHAR szEffectName, LONG value, LONG skill, PCHAR szBuffer, PCHAR preposition="with")
{
	return FormatRefreshTimer(szEffectName, value, value, skill, szBuffer, preposition);
}

PCHAR FormatResists(PCHAR szEffectName, LONG value, LONG base, PCHAR szBuffer)
{
	if (value < 100)
		sprintf(szBuffer, "%s (%d%% Chance)", GetSpellEffectNameByID(base), value);
	else
		sprintf(szBuffer, "%s", szEffectName);
	return szBuffer;
}

PCHAR FormatSeconds(PCHAR szEffectName, LONG value, PCHAR szBuffer, BOOL tens=FALSE)
{
	if (tens)
		sprintf(szBuffer, "%s (%d0.00 sec)", szEffectName, value);
	else
		sprintf(szBuffer, "%s (%d sec)", szEffectName, value);
	return szBuffer;
}

PCHAR FormatSeconds(PCHAR szEffectName, FLOAT value, PCHAR szBuffer)
{
	sprintf(szBuffer, "%s (%.2f sec)", szEffectName, value);
	return szBuffer;
}

PCHAR FormatSecondsCount(PCHAR szEffectName, FLOAT value, PCHAR szBuffer, PCHAR preposition="by")
{
	sprintf(szBuffer, "%s %s %s %.2f sec", value<0?"Decrease":"Increase", szEffectName, preposition, abs(value));
	return szBuffer;
}

PCHAR FormatSkillAttack(PCHAR szEffectName, LONG value, LONG max, LONG base2, LONG skill, PCHAR szBuffer, PCHAR preposition="with")
{
	sprintf(szBuffer, "%s %s %s for %d damage", FormatPercent(szEffectName, value, max, szBuffer), preposition, skill>=0?szSkills[skill]:"All Skills", base2);
	return szBuffer;
}

PCHAR FormatSkillAttack(PCHAR szEffectName, LONG value, LONG base2, LONG skill, PCHAR szBuffer, PCHAR preposition="with")
{
	return FormatSkillAttack(szEffectName, base2, base2, value, skill, szBuffer, preposition);
}

PCHAR FormatSkills(PCHAR szEffectName, LONG value, LONG max, LONG skill, PCHAR szBuffer, PCHAR preposition="with")
{
	sprintf(szBuffer, "%s %s %s", FormatPercent(szEffectName, value, max, szBuffer), preposition, skill>=0?szSkills[skill]:"All Skills");
	return szBuffer;
}

PCHAR FormatSkills(PCHAR szEffectName, LONG value, LONG skill, PCHAR szBuffer, PCHAR preposition="with")
{
	return FormatSkills(szEffectName, value, value, skill, szBuffer, preposition);
}

PCHAR FormatSpellChance(PCHAR szEffectName, LONG value, LONG base, PCHAR szBuffer)
{
	if (value < 100)
		sprintf(szBuffer, " (%d%% Chance, Spell: %s)", value, GetSpellNameByID(base));
	else
		sprintf(szBuffer, " (Spell: %s)", GetSpellNameByID(base));
	return szBuffer;
}

PCHAR FormatStacking(PCHAR szEffectName, LONG slot, LONG value, LONG max, LONG spa, PCHAR extra, PCHAR szBuffer)
{
	if (max > 0)
	    sprintf(szBuffer, "%s %s spell if slot %d is effect '%s' and < %d", szEffectName, spa==148?"new":"existing", slot, extra, value);
	else
	    sprintf(szBuffer, "%s %s spell if slot %d is effect '%s'", szEffectName, spa==148?"new":"existing", slot, extra);
	return szBuffer;
}

PCHAR FormatStatsCapRange(PCHAR szEffectName, LONG value, PCHAR stat, PCHAR range, PCHAR szBuffer)
{
	sprintf(szBuffer, "%s %s %s%s", value<0?"Decrease":"Increase", stat, szEffectName, range);
	return szBuffer;
}

PCHAR FormatString(PCHAR szEffectName, PCHAR extra, PCHAR szBuffer, PCHAR trigger="")
{
	sprintf(szBuffer, "%s %s%s", szEffectName, extra, trigger);
	return szBuffer;
}

PCHAR FormatTimer(PCHAR szEffectName, LONG value, PCHAR szBuffer)
{
	sprintf(szBuffer, "%s by %d.00 sec", szEffectName, value);
	return szBuffer;
}

PCHAR FormatTimer(PCHAR szEffectName, FLOAT value, PCHAR szBuffer)
{
	sprintf(szBuffer, "%s by %.2f sec", szEffectName, value);
	return szBuffer;
}

PCHAR ParseSpellEffect(PSPELL pSpell, int i, PCHAR szBuffer, LONG level)
{
	CHAR szBuff[MAX_STRING]={0};
	CHAR szTemp[MAX_STRING]={0};
	CHAR szTemp2[MAX_STRING]={0};

	LONG id=pSpell->ID;
	LONG spa=pSpell->Attrib[i];
	LONG base=pSpell->Base[i];
	LONG base2=pSpell->Base2[i];
	LONG max=pSpell->Max[i];
	LONG calc=pSpell->Calc[i];
	LONG spellgroup=pSpell->SpellGroup;
	LONG ticks=pSpell->DurationValue1;
	LONG targets=pSpell->MaxTargets;
	LONG targettype=pSpell->TargetType;
	LONG skill=pSpell->Skill;

	if (spa == SPA_PLACEHOLDER)
		return szBuffer;

	if (spa == SPA_LURE && (base <= 1 || base > 255))
		return szBuffer;

	// Adjust for Base=100
	// Adjust for base/max swapped
	// Adjust for base2 used as max
	// Adjust for base2 used as base
	switch (spa)
	{
	case SPA_HASTE:
	case SPA_PLAYERSIZE:
	case SPA_BARDOVERHASTE:
		base-=100;
		max-=100;
		break;
	case SPA_SUMMONCORPSE:
		max=base;
		base=0;
		break;
	case SPA_SPELLDAMAGE:
	case SPA_HEALING:
	case SPA_SPELLMANACOST:
		max=base2;
		break;
	case SPA_REAGENTCHANCE:
	case SPA_INCSPELLDMG:
		base=base2;
		break;
	}

    PITEMDB ItemDB=gItemDB; 

	CHAR extendedrange[MAX_STRING]={0};
	CHAR range[MAX_STRING]={0};
	CHAR repeating[MAX_STRING]={0};
	CHAR maxlevel[MAX_STRING]={0};
	CHAR spelleffectname[MAX_STRING]={0};
	CHAR extra[MAX_STRING]={0};
	CHAR maxtargets[MAX_STRING]={0};
	CHAR szPercent[MAX_STRING]="%";

	GetSpellEffectName(spa, spelleffectname);
	strcpy(extra, pSpell->Extra);

	LONG minspelllvl=CalcMinSpellLevel(pSpell);
	LONG maxspelllvl=CalcMaxSpellLevel(calc, base, max, ticks, minspelllvl, level);
	LONG value=CalcValue(calc, base, max, 1, minspelllvl, minspelllvl);
	LONG finish=CalcValue(calc, base, max, ticks, minspelllvl, level);

	BOOL usePercent=(spa==SPA_MOVEMENTRATE||spa==SPA_HASTE||spa==SPA_BARDOVERHASTE||spa==SPA_SPELLDAMAGE||spa==SPA_HEALING||spa==SPA_DOUBLEATTACK||spa==SPA_STUNRESIST||spa==SPA_PROCMOD||
					 spa==SPA_DIVINEREZ||spa==SPA_METABOLISM||spa==SPA_TRIPLEBACKSTAB||spa==SPA_DOTCRIT||spa==SPA_HEALCRIT||spa==SPA_MENDCRIT||spa==SPA_FLURRY||spa==SPA_PETFLURRY||
					 spa==SPA_SPELLCRITCHANCE||spa==SPA_SHIELDBLOCKCHANCE||spa==SPA_DAMAGECRITMOD);
	BOOL AEEffect=(targettype==TT_PBAE||targettype==TT_TARGETED_AE||targettype==TT_AE_PC_V2||targettype==TT_DIRECTIONAL);

	strcat(range, CalcValueRange(calc, base, max, ticks, minspelllvl, level, szTemp2, usePercent?szPercent:""));
	strcat(extendedrange, CalcExtendedRange(calc, value, finish, minspelllvl, maxspelllvl, szTemp2, usePercent?szPercent:"", (spa==SPA_AC||spa==SPA_AC2)));
	if (ticks) sprintf(repeating, " per tick ");
	if (max) sprintf(maxlevel, " up to level %d", max);
	if (targets && AEEffect) sprintf(maxtargets, " on up to %d enemies", targets);

#ifdef DEBUGSPELLS
	WriteChatf("SLOT:%d, SPA:%d, BASE:%d, BASE2:%d, MAX:%d, CALC:%d, TICKS:%d, VALUE:%d, FINISH:%d, MINSPELLLVL:%d, MAXSPELLLVL:%d, RANGE:%s, EXTENDEDRANGE:%s, USEPERCENT:%s, REPEATING:%s, MAXLEVEL:%s",
		i+1, spa, base, base2, max, calc, ticks, value, finish, minspelllvl, maxspelllvl, range, extendedrange, usePercent?"TRUE":"FALSE", repeating, maxlevel);
#endif

	sprintf(szBuff, "Slot %d: ", i+1);
	switch (spa)
	{
    case 0: //hp +/-: heals/regen/dd 
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		if (strlen(repeating)) strcat(szBuff, repeating);

		if (strlen(maxtargets)) strcat(szBuff, maxtargets);
        if (base2) {
			GetSpellRestrictions(pSpell, i, szTemp);
			strcat(szBuff, " -- Restrictions: ");
			strcat(szBuff, szTemp);
		}
		break; 
    case 1: //ac mod 
    case 2: //attack mod 
    case 3: //movement speed mod 
    case 4: //str mod 
    case 5: //dex mod 
    case 6: //agi mod 
    case 7: //sta mod 
    case 8: //int mod 
    case 9: //wis mod 
    case 10: //cha mod 
    case 11: //haste mod 
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break; 
    case 12: //Invisibility
		strcat(szBuff, spelleffectname);
		break;
    case 13: //See Invisible(c) 
    case 14: //Water Breathing(c)
		strcat(szBuff, FormatBase(spelleffectname, value, szTemp2));
		break;
    case 15: //mana +/-
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		if (strlen(repeating)) strcat(szBuff, repeating);
		if (strlen(maxtargets)) strcat(szBuff, maxtargets);
		szTemp[0]='\0';
        if (base2) {
			GetSpellRestrictions(pSpell, i, szTemp);
			strcat(szBuff, " -- Restrictions: ");
			strcat(szBuff, szTemp);
		}
		break; 
    case 16: //NPC Frenzy (no spells currently)
    case 17: //NPC Awareness (no spells currently)
    case 18: //NPC Aggro
		strcat(szBuff, spelleffectname);
		break;
    case 19: //NPC Faction
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break; 
    case 20: //Blindness 
		strcat(szBuff, spelleffectname);
		break;
    case 21: //stun  time = base in ms 
		if (base2 != 0 && base != base2)
			sprintf(szTemp, " NPC for %1.fs (PC for %1.fs)%s", base/1000.0f, base2/1000.0f, maxlevel);
		else
			sprintf(szTemp, " for %1.fs%s", base/1000.0f, maxlevel);
		strcat(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		if (strlen(maxtargets)) strcat(szBuff, maxtargets);
		break;
	case 22: //Charm(c/level) 
    case 23: //Fear(c/level) 
		strcat(szBuff, FormatString(spelleffectname, maxlevel, szTemp2));
		if (strlen(maxtargets)) strcat(szBuff, maxtargets);
        break; 
    case 24: //Fatigue 
		strcat(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
    case 25: //Bind Affinity 
		if (base == 2)
	        strcat(szTemp, " (Secondary Bind Point)");
		if (base == 3)
			strcat(szTemp, " (Tertiary Bind Point)");
		strcat(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
        break; 
    case 26: //Gate 
		if (base == 2)
	        strcat(szTemp, " to Secondary Bind Point"); 
		if (base == 3)
			strcat(szTemp, " (Tertiary Bind Point)");
		strcat(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
        break; 
    case 27: //Cancel Magic(c) 
		strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 28: //Invisibility versus Undead 
    case 29: //Invisibility versus Animal 
		strcat(szBuff, spelleffectname);
        break; 
    case 30: //NPC Aggro Radius(c/level) 
		// NPC Aggro Radius' use the reverse sign from normal base values
		strcat(szBuff, FormatCount(spelleffectname, -value, szTemp2));
		strcat(szBuff, maxlevel);
		break;
    case 31: //Mesmerize(c/level) 
		strcat(szBuff, FormatString(spelleffectname, maxlevel, szTemp2));
		if (strlen(maxtargets)) strcat(szBuff, maxtargets);
        break; 
    case 32: //Create Item
        while ((ItemDB) && (base != ItemDB->ID)) { 
            ItemDB = ItemDB->pNext; 
        } 
        if (ItemDB) { 
			sprintf(szTemp,"%s (Qty:%d)", ItemDB->szName, (LONG)ItemDB->StackSize<calc?ItemDB->StackSize:calc); 
        } else { 
            sprintf(szTemp,"[%5d] (Qty:%d)", base, calc); 
        } 
		strcat(szBuff, FormatExtra(spelleffectname, szTemp, szTemp2));
        break;
    case 33: //Summon Pet
		strcat(szBuff, FormatExtra(spelleffectname, extra, szTemp2));
		break;
    case 34: //Confuse
		strcat(szBuff, spelleffectname);
        break; 
    case 35: //disease counters 
    case 36: //poison counters 
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
    case 37: //DetectHostile (no spells currently)
    case 38: //DetectMagic (no spells currently)
    case 39: //DetectPoison (no spells currently)
    case 40: //Invulnerability 
    case 41: //Banish
    case 42: //Shadow Step
    case 43: //Berserk
    case 44: //Lycanthropy 
    case 45: //Vampirism 
		strcat(szBuff, spelleffectname);
        break; 
    case 46: //fire resist 
    case 47: //cold resist 
    case 48: //poison resist 
    case 49: //disease resist 
    case 50: //magic resist 
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		if (strlen(maxtargets)) strcat(szBuff, maxtargets);
		break;
    case 51: //Detect Traps (no spells currently)
    case 52: //Sense Undead 
    case 53: //Sense Summoned 
    case 54: //Sense Animals 
		strcat(szBuff, spelleffectname);
        break; 
    case 55: //most runes 
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
    case 56: //True North 
		strcat(szBuff, spelleffectname);
        break; 
    case 57: //Levitate(c) 
		strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 58: //Illusion: Base=Race 
		strcat(szBuff, FormatExtra(spelleffectname, pEverQuest->GetRaceDesc(base), szTemp2));
		break;
    case 59: //Damage Shield 
		// Damage Shield's use the reverse sign from normal base values
		strcat(szBuff, FormatRange(spelleffectname, -value, extendedrange, szTemp2));
		break;
    case 60: //Transfer Item (no spells currently)
    case 61: //Identify 
    case 62: //Item ID (no spells currently)
		strcat(szBuff, spelleffectname);
        break; 
    case 63: //Memblur e% 
		strcat(szBuff, FormatPenaltyChance(spelleffectname, value+40, szTemp2, szPercent, "Chance"));
		if (strlen(maxtargets)) strcat(szBuff, maxtargets);
		break;
    case 64: //SpinStun 
    case 65: //Infravision 
    case 66: //ultravision 
    case 67: //Eye of Zomm 
    case 68: //Reclaim Energy
		strcat(szBuff, spelleffectname);
        break; 
    case 69: //max hp mod 
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
    case 70: //CorpseBomb (no spells currently)
		strcat(szBuff, spelleffectname);
        break; 
    case 71: //Create Undead Pet
		strcat(szBuff, FormatExtra(spelleffectname, extra, szTemp2));
		break;
    case 72: //Preserve Corpse (no spells currently)
    case 73: //Bind Sight 
		strcat(szBuff, spelleffectname);
        break; 
    case 74: //Feign Death 
		strcat(szBuff, FormatPenaltyChance(spelleffectname, value, szTemp2, szPercent, "Chance"));
		break;
    case 75: //Voice Graft 
    case 76: //Sentinel 
    case 77: //Locate Corpse 
		strcat(szBuff, spelleffectname);
        break; 
    case 78: //Absorb Magic Damage 
    case 79: //+hp when cast (priest buffs that have heal component, DoTs with DDs) 
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		if (strlen(maxtargets)) strcat(szBuff, maxtargets);
		break; 
    case 80: //Enchant:Light (no spells currently)
		strcat(szBuff, spelleffectname);
        break; 
    case 81: //Resurrect
		sprintf(szTemp, " and restore %d%s experience", value, szPercent);
		strcat(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		if (strlen(maxtargets)) strcat(szBuff, maxtargets);
		break;
    case 82: //Summon Player 
		strcat(szBuff, spelleffectname);
        break; 
    case 83: //zone portal spells 
		if (targettype == 6)
			sprintf(szTemp, " Self to %d, %d, %d in %s facing %s", pSpell->Base[0], pSpell->Base[1], pSpell->Base[2], GetFullZone(GetZoneID(extra)), szHeadingNormal[EQHeading(pSpell->Base[3])]);
		else
			sprintf(szTemp, " Group to %d, %d, %d in %s facing %s", pSpell->Base[0], pSpell->Base[1], pSpell->Base[2], GetFullZone(GetZoneID(extra)), szHeadingNormal[EQHeading(pSpell->Base[3])]);
		strcat(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
        break; 
    case 84: //Toss on Z axis 
		strcat(szBuff, FormatBase(spelleffectname, abs(base), base>=0?" Down":" Up", szTemp2));
        break; 
    case 85: //Add Proc 
		strcat(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname, base, base2, szTemp), szTemp2));
		break;
    case 86: //Reaction Radius(c/level) 
		// Reaction Radius' use the reverse sign from normal base values
		strcat(szBuff, FormatCount(spelleffectname, -value, szTemp2));
		strcat(szBuff, maxlevel);
		if (strlen(maxtargets)) strcat(szBuff, maxtargets);
		break;
    case 87: //Perspective Magnification 
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 88: //evac portal spells 
		sprintf(szTemp, " to %d, %d, %d in %s facing %s", pSpell->Base[0], pSpell->Base[1], pSpell->Base[2], extra, szHeadingNormal[EQHeading(pSpell->Base[3])]);
		strcat(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
        break; 
    case 89: //Player Size 
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 90: //Cloak
    case 91: //Summon Corpse 
		strcat(szBuff, FormatString(spelleffectname, maxlevel, szTemp2));
        break; 
    case 92: //hate mod 
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		if (strlen(maxtargets)) strcat(szBuff, maxtargets);
		break; 
    case 93: //Stop Rain 
    case 94: //Make Fragile 
    case 95: //Sacrifice 
		strcat(szBuff, spelleffectname);
        break; 
    case 96: //Silence (no PC spells currently)
		strcat(szBuff, spelleffectname);
		if (strlen(maxtargets)) strcat(szBuff, maxtargets);
        break; 
    case 97: //Mana Pool 
    case 98: //Haste v2 
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break; 
    case 99: //Root 
		strcat(szBuff, spelleffectname);
		break;
    case 100: //hp mod: pet heals/regen
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		strcat(szBuff, repeating);
		break; 
    case 101: //Complete Heal (with duration)
    case 102: //Fearless 
    case 103: //Call Pet 
		strcat(szBuff, spelleffectname);
		break;
    case 104: //zone translocate spells
		if (extra[0])
			if (extra[0] == '0')
				strcat(szTemp, " to Bind Point");
			else
				sprintf(szTemp, " to %d, %d, %d in %s facing %s", pSpell->Base[0], pSpell->Base[1], pSpell->Base[2], GetFullZone(GetZoneID(extra)), szHeadingNormal[EQHeading(pSpell->Base[3])]);
		else
			strcat(szTemp, " to Bind Point");
		strcat(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
        break; 
    case 105: //Anti-Gate 
		strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 106: //Summon Warder 
		strcat(szBuff, FormatExtra(spelleffectname, extra, szTemp2));
		break;
    case 107: //Alter NPC Level (no spells currently)
		strcat(szBuff, spelleffectname);
		break;
    case 108: //Summon Familiar 
		strcat(szBuff, FormatExtra(spelleffectname, extra, szTemp2));
		break;
    case 109: //Summon Into Bag 
        while ((ItemDB) && (base != ItemDB->ID)) { 
            ItemDB = ItemDB->pNext; 
        } 
        if (ItemDB) { 
            sprintf(szTemp,"%s", ItemDB->szName); 
        } else { 
            sprintf(szTemp,"[%5d]", base); 
        } 
		strcat(szBuff, FormatExtra(spelleffectname, szTemp, szTemp2));
        break;
    case 110: //Increase Archery (no spells currently)
		strcat(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
    case 111: //Resistances
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		if (strlen(maxtargets)) strcat(szBuff, maxtargets);
		break; 
    case 112: //Casting Level
		strcat(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
    case 113: //Summon Mount 
		strcat(szBuff, FormatExtra(spelleffectname, extra, szTemp2));
		break;
    case 114: //aggro multiplier 
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 115: //Food/Water 
		strcat(szBuff, spelleffectname);
		break;
    case 116: //curse counters 
		strcat(szBuff, FormatCount(spelleffectname, value, szTemp2));
		if (strlen(maxtargets)) strcat(szBuff, maxtargets);
		break;
    case 117: //Make Weapons Magical 
		strcat(szBuff, spelleffectname);
		break;
    case 118: //Singing Skill 
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
    case 119: //Bard Overhaste 
    case 120: //Reduce Healing Effectiveness (%) 
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 121: //Reverse Damage Shield 
		strcat(szBuff, FormatBase(spelleffectname, -base, szTemp2));
		break;
    case 122: //Reduce Skill (no spells currently)
    case 123: //Immunity
		strcat(szBuff, spelleffectname);
		break;
    case 124: //spell damage 
    case 125: //healing 
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break;
    case 126: //spell resist rate 
    case 127: //spell haste 
		strcat(szBuff, FormatPercent(spelleffectname, -value, -finish, szTemp2));
		break; 
    case 128: //spell duration 
    case 129: //spell range 
    case 130: //spell/bash hate 
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 131: //Decrease Chance of Using Reagent
    case 132: //Spell Mana Cost
    case 133: //Spell Stun Duration (no spells currently)
		strcat(szBuff, FormatPercent(spelleffectname, -value, -finish, szTemp2));
		break; 
    case 134: //limit max level 
		if (base2 > 0)
			sprintf(szTemp, "%s (%d) (lose %d%s per level over cap)", spelleffectname, base, base2, szPercent);
		else
			strcpy(szTemp, FormatBase(spelleffectname, base, szTemp2));
		strcat(szBuff, szTemp);
		break;
    case 135: //Limit: Resist 
		strcat(szBuff, FormatLimits(spelleffectname, value, GetResistTypeName(base, szTemp), szTemp2));
		break;
    case 136: //limit target types this affects 
		strcat(szBuff, FormatLimits(spelleffectname, value, GetTargetTypeLimitsName(base, szTemp), szTemp2));
		break;
    case 137: //limit effect types this affects 
		strcat(szBuff, FormatLimits(spelleffectname, value, GetSpellEffectName(base, szTemp), szTemp2));
		break;
    case 138: //limit spelltype this affects 
		strcat(szBuff, FormatLimits(spelleffectname, value, GetSpellTypeName(base, szTemp), szTemp2));
		break;
    case 139: //limit spell this affects 
		strcat(szBuff, FormatLimits(spelleffectname, value, GetSpellNameByID(base), szTemp2));
		break;
    case 140: //limit min duration of spells this affects (base= #ticks) 
        strcat(szBuff, FormatSeconds(spelleffectname, value*6, szTemp2)); 
        break; 
    case 141: //limit to instant spells only 
		strcat(szBuff, spelleffectname);
		break;
    case 142: //Limit: Min Level 
		strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 143: //limit min casting time of spells this affects (base= seconds in ms) 
    case 144: //limit max casting time of spells this affects (base= seconds in ms) 
        strcat(szBuff, FormatSeconds(spelleffectname, value/1000.0f, szTemp2)); 
        break; 
    case 145: //Teleportv2 
		sprintf(szTemp, " to %d, %d, %d in %s facing %s", pSpell->Base[0], pSpell->Base[1], pSpell->Base[2], GetFullZone(GetZoneID(extra)), szHeadingNormal[EQHeading(pSpell->Base[3])]);
		strcat(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
        break; 
    case 146: //Resist Electricity
		strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 147: //Hit Points (% Max) 
	    strcat(szBuff, FormatMax(spelleffectname, value, max, szTemp2));
        break; 
    case 148: //Stacking: Block 
    case 149: //Stacking: Overwrite 
	    strcat(szBuff, FormatStacking(spelleffectname, calc-200, value, (max>1000?max-1000:max), spa, GetSpellEffectName(base,szTemp), szTemp2));
		break;
    case 150: //Death Save - Restore Full Health 
		sprintf(szTemp, "Restore %s Health", base==1?"Partial":base==2?"Full":"Unknown");
		strcat(szBuff, FormatExtra(spelleffectname, szTemp, szTemp2));
		break;
    case 151: //Suspended Minion (no current spells)
	    sprintf(szTemp, "(%s)", base==0?"Current HP Only":base==1?"Current HP, Buffs, Weapons":"Unknown");
		strcat(szBuff, FormatExtra(spelleffectname, szTemp, szTemp2));
		break;
    case 152: //Summon Pets (swarm) 
        sprintf(szTemp, "%s x%d for %dsec", extra, value, finish); 
        strcat(szBuff, FormatExtra(spelleffectname, szTemp, szTemp2)); 
        break; 
    case 153: //Balance Party Health 
        strcat(szBuff, FormatPenaltyChance(spelleffectname, value, szTemp2, szPercent, "Penalty")); 
        break; 
    case 154: //Remove Detrimental(c) 
		strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 155: //PoP Resurrect
    case 156: //Illusion: Target 
		strcat(szBuff, spelleffectname);
		break;
    case 157: //Spell Damage Shield 
		strcat(szBuff, FormatRange(spelleffectname, -value, extendedrange, szTemp2));
		break;
    case 158: //Chance to Reflect Spell 
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 159: //Stats 
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break; 
    case 160: //Drunk effect 
		strcat(szBuff, FormatAT(spelleffectname, value, szTemp2, "if Alcholol Tolerance is below"));
		break; 
    case 161: //Mitigate Spell Damage 
    case 162: //Mitigate Melee Damage 
		strcat(szBuff, FormatPercent(spelleffectname, value, szTemp2, FALSE));
        if (max > 0)
			sprintf(szTemp, " until %d absorbed", max);
		strcat(szBuff, szTemp);
		break; 
    case 163: //Absorb Damage 
		sprintf(szTemp, " up to %d from the next %d melee strikes or direct damage spells", max, value); 
		strcat(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
    case 164: //Attempt Sense (Cursed) Trap 
    case 165: //Attempt Disarm (Cursed) Trap 
    case 166: //Attempt Destroy (Cursed) Lock 
		strcat(szBuff, spelleffectname);
		break;
    case 167: //Increase Pet Power 
		strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 168: //Mitigation 
		strcat(szBuff, FormatPercent(spelleffectname, -value, -finish, szTemp2));
		break; 
    case 169: //Chance to Critical Hit 
        strcat(szBuff, FormatSkills(spelleffectname, value, finish, base2, szTemp2, "for"));
        break; 
    case 170: //Chance to Critical Cast
    case 171: //Crippling Blow 
    case 172: //Melee Avoidance 
    case 173: //Riposte 
    case 174: //Dodge 
    case 175: //Parry 
    case 176: //Dual Wield 
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 177: //Stat Cap Mod (how do they know which?) 
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
    case 178: //Lifetap Proc 
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		strcat(szBuff, " heal");
		break; 
    case 179: //Puretone 
    case 180: //Spell Resist 
    case 181: //Fearless 
    case 182: //Hundred Hands 
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 183: //Skill Chance Mod
    case 184: //Chance to hit with Backstab (or throwing/archery [http://lucy.allakhazam.com/spellraw.html?id=9616&source=Live])
    case 185: //Damage Mod (how to tell which, rogues get a backstab only, others get an all skills) 
    case 186: //Damage Mod (see above) 
        strcat(szBuff, FormatSkills(spelleffectname, value, finish, base2, szTemp2));
        break; 
    case 187: //Mana Balance
        strcat(szBuff, FormatPenaltyChance(spelleffectname, value, szTemp2, szPercent, "Penalty")); 
        break; 
    case 188: //Block 
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 189: //Endurance DoT/Regen 
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		strcat(szBuff, repeating);
		break;
    case 190: //Max Endurance
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break; 
    case 191: //Amnesia
		strcat(szBuff, spelleffectname);
		break;
    case 192: //Discord Hate 
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		if (strlen(maxtargets)) strcat(szBuff, maxtargets);
		break; 
    case 193: //Skill Attack 
        strcat(szBuff, FormatSkillAttack(spelleffectname, value, base2, skill, szTemp2));
		if (strlen(maxtargets)) strcat(szBuff, maxtargets);
		break;
    case 194: //Fade 
		strcat(szBuff, spelleffectname);
		break;
    case 195: //Stun Resist 
    case 196: //Strikethrough 
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break; 
    case 197: //Skill Damage 
        strcat(szBuff, FormatSkills(spelleffectname, value, finish, base2, szTemp2));
		if (strlen(maxtargets)) strcat(szBuff, maxtargets);
		break;
    case 198: //Endurance Heals 
		strcat(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break; 
    case 199: //Taunt
		strcat(szBuff, spelleffectname);
		break;
    case 200: //Proc Mod 
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
    case 201: //Ranged Proc 
		strcat(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname, base, base2, szTemp), szTemp2));
		break;
    case 202: //Illusion Other
    case 203: //Mass Group Buff
		strcat(szBuff, spelleffectname);
		break;
    case 204: //War Cry 
		strcat(szBuff, FormatSeconds(spelleffectname, value, szTemp2, TRUE));
		break; 
    case 205: //Rampage 
    case 206: //AE Taunt 
    case 207: //Flesh to Bone 
		strcat(szBuff, spelleffectname);
		break;
	case 208: //Purge Poison (no spells currently)
    case 209: //Disspell Beneficial Buffs 
		strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 210: //Pet Shield 
		strcat(szBuff, FormatSeconds(spelleffectname, value*1.0f, szTemp2));
		break; 
    case 211: //AE Melee 
		strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 212: //Frenzied Devastation (no spells currently)
		strcat(szBuff, FormatSeconds(spelleffectname, value, szTemp2, TRUE));
		break; 
    case 213://Pet HP
    case 214: //Change Max HP
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2, FALSE, TRUE));
		break;
    case 215: //Pet Avoidance (no spells currently)
    case 216: //Accuracy 
    case 217: //Headshot (no spells currently)
    case 218: //Pet Crit Melee (no spells currently)
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		if (strlen(maxtargets)) strcat(szBuff, maxtargets);
		break; 
    case 219: //Slay undead (Holyforge) 
		strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 220: //Skill Damage Amt 
        strcat(szBuff, FormatSkills(spelleffectname, value, finish, base2, szTemp2));
		break;
    case 221: //Reduce Weight
    case 222: //Block Behind 
		strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 223: //Double Riposte (no spells currently)
    case 224: //Riposte (no spells currently)
    case 225: //Double Attack 
    case 226: //2H Bash (no spells currently)
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 227: //Base Refresh Timer
        strcat(szBuff, FormatRefreshTimer(spelleffectname, -value, -finish, base2, szTemp2));
		break;
    case 228: //Reduce Fall Dmg (no spells currently)
    case 229: //Cast Through Stun (no spells currently)
    case 230: //Increase Shield Dist (no spells currently)
		strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 231: //Stun Bash Chance (no spells currently)
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 232: //Divine Save
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break;
    case 233: //Metabolism
		strcat(szBuff, FormatRange(spelleffectname, -value, extendedrange, szTemp2));
		break;
    case 234: //Poison Mastery (no spells currently)
    case 235: //Focus Channelling (no spells currently)
    case 236: //Free Pet (no spells currently)
    case 237: //Pet Affinity (no spells currently)
    case 238: //Permanent Illusion (no spells currently)
    case 239: //Stonewall (no spells currently)
    case 240: //String Unbreakable (no spells currently)
    case 241: //Improve Reclaim Energy (no spells currently)
    case 242: //Increase Chance Memwipe (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 243: //NoBreak Charm Chance
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 244: //Root Break Chance
    case 245: //Trap Circumvention (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 246: //Lung Capacity
		strcat(szBuff, FormatRange(spelleffectname, value, range, szTemp2));
        break;
    case 247: //Increase SkillCap (no spells currently)
    case 248: //Extra Specialization (no spells currently)
    case 249: //Offhand Min (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 250: //Spell Proc Chance
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 251: //Endless Quiver (no spells currently)
    case 252: //Backstab Front (no spells currently)
    case 253: //Chaotic Stab (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 254: //placeholder of some kind 
        break;
    case 255: //Shielding Duration (no spells currently)
        strcat(szBuff, FormatBasePercent(spelleffectname, base, szTemp2));
		break;
	case 256: //Shroud Of Stealth (no spells currently)
	case 257: //Give Pet Hold (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 258: //Triple Backstab 
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
        break;
    case 259: //AC Limit
    case 260: //Add Instrument 
    case 261: //Song Cap (no spells currently)
        strcat(szBuff, FormatBasePercent(spelleffectname, base, szTemp2));
		break;
    case 262: //Stats Cap
		strcat(szBuff, FormatStatsCapRange(spelleffectname, value, GetStatShortName(base2, szTemp), extendedrange, szTemp2));
		break;
    case 263: //Tradeskill Masteries (no spells currently)
    case 264: //Reduce AATimer
    case 265: //No Fizzle (no spells currently)
    case 266: //Attack Chance 
    case 267: //Add Pet Commands (no spells currently)
    case 268: //Alc Fail Rate (no spells currently)
    case 269: //Bandage Perc Limit (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 270: //Bard Song Range
		strcat(szBuff, FormatCount(spelleffectname, value, szTemp2, "to"));
		break; 
    case 271: //Base Run Speed (no spells currently)
        strcat(szBuff, FormatBasePercent(spelleffectname, base, szTemp2));
		break;
    case 272: //Casting Level
		strcat(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break; 
    case 273: //DoT Crit
    case 274: //Heal Crit 
    case 275: //Mend Crit (no spells currently)
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
        break;
    case 276: //Dual Wield Amt (no spells currently)
    case 277: //Extra DI Chance (no spells currently)
    case 278: //Finishing Blow (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 279: //Flurry 
    case 280: //Pet Flurry Chance
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
        break;
    case 281: //Give Pet Feign (no spells currently)
    case 282: //Increase Bandage Amt (no spells currently)
    case 283: //Special Attack Chain (no spells currently)
    case 284: //LoH Set Heal (no spells currently)
    case 285: //NoMove Check Sneak (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 286: //DD Bonus
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
        break;
    case 287: //Focus Combat Duration
		strcat(szBuff, FormatCount(spelleffectname, value, szTemp2));
		strcat(szBuff, " tick(s)");
        break;
    case 288: //Add Proc Hit (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 289: //Trigger on Fade 
        strcat(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Fade")); 
        break; 
    case 290://Increase Movement Cap (no spells currently)
    case 291: //Purify
    case 292: //Strikethrough2
    case 293: //StunResist2 (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 294: //Spell Crit Chance
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
        break;
    case 295: //Reduce Timer Special (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 296: //Blight
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 297: //Empathy
		strcat(szBuff, spelleffectname);
		break;
    case 298: //Tiny Companion
		strcat(szBuff, FormatPercent(spelleffectname, -value, -finish, szTemp2));
		break; 
    case 299: //Wake the Dead 
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 300: //Doppleganger
		strcat(szBuff, spelleffectname);
		break;
    case 301: //Increase Range Damage (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 302: //Damage Crit
    case 303: //Damage
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break; 
    case 304: //Secondary Riposte Mod (no spells currently)
        strcat(szBuff, FormatBasePercent(spelleffectname, base, szTemp2));
		break;
    case 305: //Damage Shield Mitigation
		strcat(szBuff, FormatPercent(spelleffectname, -value, -finish, szTemp2));
		break; 
    case 306: //Army of Dead 
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 307: //Appraisal
    case 308: //Suspend Minion 
    case 309: //Teleport Bind
		strcat(szBuff, spelleffectname);
		break;
    case 310: //Reuse Timer 
        strcat(szBuff, FormatTimer(spelleffectname, -base/1000.0f, szTemp2)); 
        break; 
    case 311: //No Combat Skills 
		strcat(szBuff, spelleffectname);
		break;
    case 312: //Sanc 
    case 313: //Forage Master (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 314: //Improved Invisibility
    case 315: //Improved Invisibility Vs Undead
    case 316: //Improved Invisibility Vs Animals (no spells currently)
		strcat(szBuff, spelleffectname);
		break;
    case 317: //Worn Regen Cap
    case 318: //Worn Mana Cap
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 319: //Critical HP Regen
    case 320: //Shield Block Chance
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break; 
    case 321: //Soothing 
        strcat(szBuff, FormatBasePercent(spelleffectname, base, szTemp2));
		break;
    case 322: //Origin 
		strcat(szBuff, spelleffectname);
		break;
    case 323: //Add Defensive Proc 
		strcat(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname, base, base2, szTemp), szTemp2));
        break; 
    case 324: //Spirit Channel
        strcat(szBuff, FormatBasePercent(spelleffectname, base, szTemp2));
		break;
    case 325: //No Break AE Sneak (no spells currently)
    case 326: //Spell Slots (no spells currently)
    case 327: //Buff Slots (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 328: //Negative HP Limit
		strcat(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break; 
    case 329: //Mana Shield
		strcat(szBuff, FormatCount(spelleffectname, value, szTemp2, "up to", szPercent));
		break; 
    case 330: //Crit Damage 
        strcat(szBuff, FormatSkills(spelleffectname, value, finish, base2, szTemp2));
		break;
    case 331: //Item Recovery
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 332: //Summon to Corpse 
		strcat(szBuff, spelleffectname);
		break;
    case 333: //Trigger on fade 
        strcat(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Fade")); 
        break; 
    case 334: //Song DoT 
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		strcat(szBuff, repeating);
		strcat(szBuff, " if target is not moving");
		break; 
    case 335: //Fc_Immunity Focus
		strcat(szBuff, spelleffectname);
		break;
    case 336: //Illusionary Target (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 337: //Experience buff 
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 338: //Expedient Recovery
		strcat(szBuff, spelleffectname);
		break;
    case 339: //Trigger DoT on cast
    case 340: //Trigger DD on cast 
        strcat(szBuff, FormatExtra(spelleffectname, FormatSpellChance(spelleffectname, base, base2, szTemp), szTemp2, " on Cast")); 
		break;
    case 341: //Worn Attack Cap
		strcat(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break; 
    case 342: //Prevent Flee on Low Health
		strcat(szBuff, spelleffectname);
		break;
    case 343: //Spell Interrupt
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		if (strlen(maxtargets)) strcat(szBuff, maxtargets);
		break; 
    case 344: //Item Channeling (no spells currently)
    case 345: //Assassinate Max (no spells currently)
    case 346: //Headshot Max (no spells currently)
    case 347: //Double Ranged Attack (no spells currently)
    case 348: //Limit: Mana Min
    case 349: //Increase Damage With Shield (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 350: //Manaburn
		strcat(szBuff, FormatCount(spelleffectname, value*4, szTemp2, "for"));
		break; 
    case 351: //Persistent Effect
		strcat(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(id+(spellgroup?3:1)), szTemp2));
		break;
    case 352: //Increase Trap Count
    case 353: //Increase SOI Count
    case 354: //Deactivate All Traps
    case 355: //Learn Trap
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 356: //Change Trigger Type (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 357: //Mute
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 358: //Mana/Max Mana
		strcat(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break; 
    case 359: //Passive Sense Trap
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 360: //Killshot Triggers
    case 361: //Proc On Death
        strcat(szBuff, FormatExtra(spelleffectname, FormatSpellChance(spelleffectname, base, base2, szTemp), szTemp2)); 
		break;
    case 362: //Potion Belt (no spells currently)
    case 363: //Bandolier (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 364: //Triple Attack Chance
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 365: //Trigger on Kill Shot 
        strcat(szBuff, FormatExtra(spelleffectname, FormatSpellChance(spelleffectname, base, base2, szTemp), szTemp2)); 
		break;
	case 366: //Group Shielding
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 367: //Change Body Type 
	    sprintf(szTemp, " to %s", base==25?"Plant":base==21?"Animal":base==3?"Undead":"Unknown");
		strcat(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
    case 368: //Modify Faction
		strcat(szBuff, FormatExtra(spelleffectname, GetFactionName(base, szTemp), szTemp2));
		break;
    case 369: //Corruption Counters 
    case 370: //Corruption Resists 
		strcat(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break; 
    case 371: //Slow
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 372: //Grant Foraging (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 373: //Trigger Effect
        strcat(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Fade")); 
        break; 
	case 374: //Trigger Spell
        strcat(szBuff, FormatExtra(spelleffectname, FormatSpellChance(spelleffectname, base, base2, szTemp), szTemp2)); 
        break; 
    case 375: //Critical DoT Damage Mod
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 376: //Fling
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 377: //Trigger Effect
        strcat(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Fade")); 
        break; 
    case 378: //Resist
        strcat(szBuff, FormatExtra(spelleffectname, FormatResists(spelleffectname, base, base2, szTemp), szTemp2));
        break;
    case 379: //Directional Shadowstep
		strcat(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break; 
    case 380: //Knockback Explosive
		sprintf(szTemp, " (%d) and Toss Up (%d)", base, base2); 
		strcat(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
    case 381: //Fling to Self
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 382: //Negate: Effect
		sprintf(szTemp, " %s Effect", GetSpellEffectNameByID(base2));
        strcat(szBuff, FormatExtra(spelleffectname, szTemp, szTemp2));
        break; 
    case 383: //Trigger Spell
        strcat(szBuff, FormatExtra(spelleffectname, FormatSpellChance(spelleffectname, base, base2, szTemp), szTemp2, " on Cast")); 
		break;
    case 384: //Fling to Target
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 385: //Limit: SpellGroup
		strcat(szBuff, FormatExtra(spelleffectname, GetSpellNameBySpellGroupID(base), szTemp2));
		break;
    case 386: //Trigger Effect
        strcat(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Curer")); 
        break; 
    case 387: //Trigger Effect
        strcat(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Fade")); 
        break; 
    case 388: //Summon All Corpses
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 389: //Spell Gem Refresh
		strcat(szBuff, FormatCount(spelleffectname, -value, szTemp2, "to"));
		break; 
    case 390: //Fc_Timer Lockout
    case 391: //Limit: Mana Max
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 392: //Heal Amt
		strcat(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break; 
    case 393: //Incoming Healing Effectiveness
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 394: //Incoming Healing Amt
		strcat(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break; 
    case 395: //Fc_Heal % Crit (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 396: //Heal Amt
		strcat(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break; 
    case 397: //Pet Amt Mitigation (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 398: //Swarm Pet Duration
        strcat(szBuff, FormatSecondsCount(spelleffectname, value/1000.0f, szTemp2)); 
        break; 
    case 399: //Twincast Chance
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 400: //Healburn
        sprintf(szTemp, " use up to %d mana to heal your group", value); 
        strcat(szBuff, FormatString(spelleffectname, szTemp, szTemp2)); 
		break;
    case 401: //Mana/HP
    case 402: //Endurance/HP
		strcat(szBuff, FormatCount(spelleffectname, -value, szTemp2, "by up to"));
		break; 
    case 403: //Limit: SpellClass
    case 404: //Limit: SpellSubclass
    case 405: //Staff Block Chance (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 406: //Trigger Effect
        strcat(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Max Hits")); 
        break; 
    case 407: //Trigger Effect
        strcat(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, " on Focus Used")); 
		break;
    case 408: //Limit HP
    case 409: //Limit Mana
    case 410: //Limit Endurance
		strcat(szBuff, FormatCount(spelleffectname, value, szTemp2, "to"));
		break; 
    case 411: //Limit: PlayerClass
        strcat(szBuff, FormatExtra(spelleffectname, GetClassesFromMask(base, szTemp), szTemp2));
		break;
    case 412: //Limit: Race (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2)); // needs work (base2 bitmask of races)
		break;
    case 413: //Base Dmg
		strcat(szBuff, FormatCount(spelleffectname, value, szTemp2, "by", szPercent));
		break; 
    case 414: //Limit: CastingSkill
    case 415: //Limit: ItemClass (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 416: //AC2
    case 417: //Mana2
		strcat(szBuff, FormatRange(spelleffectname, value, extendedrange, szTemp2));
		break; 
    case 418: //Increased Skill Damage2
        strcat(szBuff, FormatCount(spelleffectname, value, szTemp2));
		break;
    case 419: //Add Proc
		strcat(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname, base, base2, szTemp), szTemp2));
        break; 
    case 420: //Fc_Limit Use (no spells currently)
    case 421: //Fc_Limit Use Amt (no spells currently)
    case 422: //Limit: Use Min (no spells currently)
    case 423: //Limit: Use Type (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 424: //Gravitate
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		if (strlen(maxtargets)) strcat(szBuff, maxtargets);
		break;
    case 425: //Fly
		strcat(szBuff, spelleffectname);
		break;
    case 426: //AddExtTargetSlots (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 427: //Skill Proc
		strcat(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname, base, base2, szTemp), szTemp2));
        break; 
    case 428: //Limit Skill
        strcat(szBuff, FormatExtra(spelleffectname, base>=0?szSkills[base]:"All Skills", szTemp2));
		break;
    case 429: //Skill Proc Success
		strcat(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname, base, base2, szTemp), szTemp2));
        break; 
    case 430: //PostEffect
    case 431: //PostEffectData
    case 432: //ExpandMaxActiveTrophyBenefits (no spells currently)
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 433: //Critical DoT Chance (no spells currently)
    case 434: //Critical Heal Chance
    case 435: //Critical HoT Chance
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 436: //Beneficial Countdown Hold
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 437: //Teleport to Anchor
    case 438: //Translocate to Anchor
	    sprintf(szTemp, " to %s Anchor", base==50874?"Guild Hall":base==52584?"Primary":base==52585?"Secondary":"Unknown");
		strcat(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
    case 439: //Assassinate (no spells currently)
    case 440: //FinishingBlowMax (no spells currently)
    case 441: //Distance Removal
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 442: //Doom Req Target
    case 443: //Doom Req Caster
        strcat(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2)); 
		break;
    case 444: //Improved Taunt
		sprintf(szTemp, " up to L%d and Reduce Ally Hate Generation by %d%s", base, base2, szPercent); 
		strcat(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
    case 445: //Add Merc Slot
    case 446: //A_Stacker
    case 447: //B_Stacker
    case 448: //C_Stacker
    case 449: //D_Stacker
        strcat(szBuff, FormatBase(spelleffectname, base, szTemp2));
		break;
    case 450: //DoT Guard
		sprintf(szTemp, " absorbing %d%s damage to a total of %d", value, szPercent, max); 
		strcat(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break;
    case 451: //Melee Threshold Guard
    case 452: //Spell Threshold Guard
		sprintf(szTemp, " absorbing %d%s of incoming %s damage in excess of %d to a total of %d", value, szPercent, spa==451?"melee":"spell", base2, max); 
		strcat(szBuff, FormatString(spelleffectname, szTemp, szTemp2));
		break; 
    case 453: //Doom Melee Threshold
    case 454: //Doom Spell Threshold
        sprintf(szTemp, " on %d Damage Taken", base2); 
        strcat(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(base), szTemp2, szTemp)); 
        break; 
    case 455: //Add Hate %
    case 456: //Add Hate Over Time %
		strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
    case 457: //Resource Tap
		sprintf(szTemp, "Return %.2f%s of direct damage as %s", value/10.0f, szPercent, base2==0?"hit points":base2==1?"mana":base2==2?"endurance":"unknown");
		strcat(szBuff, szTemp);
		break;
    case 458: //Faction Mod %
        strcat(szBuff, FormatPercent(spelleffectname, value, finish, szTemp2));
		break; 
	default: //undefined effect 
        sprintf(szTemp, "UnknownEffect%03d", spa); 
        strcat(szBuff,szTemp); 
        break; 
	}

#ifdef DEBUGSPELLS
	if (strlen(szBuff)>0) WriteChatf(szBuff);
#endif
	strcat(szBuffer, szBuff);
	return szBuffer;
}

PCHAR ShowSpellSlotInfo(PSPELL pSpell, PCHAR szBuffer) 
{ 
    CHAR szTemp[MAX_STRING]={0}; 
    CHAR szBuff[MAX_STRING]={0}; 

    for (int i=0; i<12; i++) 
    { 
        szBuff[0]=szTemp[0]='\0';
		strcat(szBuff, ParseSpellEffect(pSpell, i, szTemp));
		if (strlen(szBuff)>0) {
			strcat(szBuffer, szBuff);
			strcat(szBuffer, "<br>");
		}
    } 
    return szBuffer; 
} 

VOID SlotValueCalculate(PCHAR szBuff, PSPELL pSpell, int i, double mp)
{
	sprintf_s(szBuff,12, "%d", CalcValue(pSpell->Calc[i], pSpell->Base[i], pSpell->Max[i], pSpell->DurationValue1));
	return;
}

int FindMappableCommand(const char *name)
{
    for (unsigned long i = 0 ; i < nEQMappableCommands ; i++)
    {
        if((DWORD)szEQMappableCommands[i] == 0 || (DWORD)szEQMappableCommands[i] > (DWORD)__AC1_Data)
            continue;
        if (!_stricmp(name,szEQMappableCommands[i]))
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

#ifndef ISXEQ
void CustomPopup(char* szPopText, bool bPopOutput)
{
    int  iArgNum    = 1;
    int  iMsgColor  = CONCOLOR_LIGHTBLUE;
    int  iMsgTime   = 3000;
    char szCurArg[MAX_STRING]    = {0};
    char szPopupMsg[MAX_STRING]  = {0};
    char szErrorCust[MAX_STRING] = "\awUsage: /popcustom [\agcolor\ax] [\agdisplaytime\ax(in seconds)] [\agmessage\ax]";
    char szErrorEcho[MAX_STRING] = "\awUsage: /popupecho [\agcolor\ax] [\agdisplaytime\ax(in seconds)] [\agmessage\ax]";

    GetArg(szCurArg, szPopText, iArgNum++);
    if (!*szCurArg)
    {
        if (bPopOutput)
        {
            WriteChatf(szErrorEcho);
        }
        else
        {
            WriteChatf(szErrorCust);
        }
        return;
    }
    else
    {
        if(isdigit(szCurArg[0]))
        {
            iMsgColor = atoi(szCurArg);
            GetArg(szCurArg, szPopText, iArgNum++);
            if(isdigit(szCurArg[0]))
            {
                iMsgTime = atoi(szCurArg) * 1000;
                sprintf(szPopupMsg, "%s", GetNextArg(szPopText, 2, FALSE, 0));
            }
            else
            {
                sprintf(szPopupMsg, "%s", GetNextArg(szPopText, 1, FALSE, 0));
            }
        }
        else
        {
            strcpy(szPopupMsg, szPopText);
        }
    }
    DisplayOverlayText(szPopupMsg, iMsgColor, 100, 500, 500, iMsgTime);
    if (bPopOutput) WriteChatf("\ayPopup\aw:: %s", szPopupMsg);
}
#endif

BOOL ParseKeyCombo(PCHAR text, KeyCombo &Dest)
{
    KeyCombo Ret;
    if (!_stricmp(text,"clear"))
    {
        Dest=Ret;
        return true;
    }
    CHAR Copy[MAX_STRING];
    strcpy(Copy,text);
    text=strtok(Copy,"+ ");
    while(text)
    {
        if (!_stricmp(text,"alt"))
            Ret.Data[0]=1;
        else if (!_stricmp(text,"ctrl"))
            Ret.Data[1]=1;
        else if (!_stricmp(text,"shift"))
            Ret.Data[2]=1;
        else
        {
            for (unsigned long i=0 ; gDiKeyID[i].Id ; i++)
            {
                if (!_stricmp(text,gDiKeyID[i].szName))
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
#endif

#ifndef ISXEQ
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
        if (Cmd && Cmd[0] && Cmd[0]!=';')
        {
            HideDoCommand(((PSPAWNINFO)pLocalPlayer),Cmd,Delayed);
        }
    }
    fclose(file);
    return true;
}
#endif

#ifndef ISXEQ_LEGACY
int FindInvSlotForContents(PCONTENTS pContents)
{
    int LastMatch = -1;

    // screw the old style InvSlot numbers
    // return the index into the INVSLOTMGR array
    DebugSpew("FindInvSlotForContents(0x%08X) (0x%08X)",pContents,GetItemFromContents(pContents));

#if 1
    PEQINVSLOTMGR pInvMgr=(PEQINVSLOTMGR)pInvSlotMgr;
    for (unsigned long N = 0 ; N < 0x800 ; N++)
    {
        class CInvSlot *pCIS = NULL;
        struct _CONTENTS *pC = NULL;

        if (pInvMgr->SlotArray[N]) {
            pCIS = (class CInvSlot *)pInvMgr->SlotArray[N];

            pCIS->GetItemBase(&pC);

            if (pC) {
                DebugSpew("pInvSlotMgr->SlotArray[%d] Contents==0x%08X",N,pC);
                if (pC==pContents) {

if (pInvMgr->SlotArray[N]->pInvSlotWnd) {
DebugSpew("%d slot %d wnd %d %d %d", N, pInvMgr->SlotArray[N]->InvSlot, 
    pInvMgr->SlotArray[N]->pInvSlotWnd->WindowType,
    pInvMgr->SlotArray[N]->pInvSlotWnd->InvSlot,
    pInvMgr->SlotArray[N]->pInvSlotWnd->BagSlot
    );
}
                    // if it is in the primary inventory,
                    // then pInvSlotWnd->WindowType is 0
                    if (pInvMgr->SlotArray[N]->pInvSlotWnd && pInvMgr->SlotArray[N]->pInvSlotWnd->WindowType == 0) {
                        return pInvMgr->SlotArray[N]->InvSlot; 
                    } else if (pInvMgr->SlotArray[N]->pInvSlotWnd && pInvMgr->SlotArray[N]->pInvSlotWnd->BagSlot!=65535) {
                        return pInvMgr->SlotArray[N]->InvSlot; 
                    } else if (pInvMgr->SlotArray[N]->pInvSlotWnd && pInvMgr->SlotArray[N]->pInvSlotWnd->WindowType==11) {
                        // loot window items should not be anywhere else
                        return pInvMgr->SlotArray[N]->InvSlot; 
                    } else {
                        LastMatch = N;
                    }
                }
            }
        }
    }
    // return specific window type if needed
    if (LastMatch != -1 && pInvMgr->SlotArray[LastMatch]->pInvSlotWnd->WindowType== 9999)
        return  pInvMgr->SlotArray[LastMatch]->InvSlot;
#endif

#if 0
    for(DWORD n = 0; n < NUM_INV_SLOTS; n++)
    {
        if(GetCharInfo2()->pInventoryArray->InventoryArray[n] && GetCharInfo2()->pInventoryArray->InventoryArray[n] == pContents)
        {
            //DebugSpew("Found '%s' at %d", GetCharInfo2()->pInventoryArray->InventoryArray[n]->Item->Name, n);
            return n;
        }
    }

    unsigned long nPack;
    for (nPack=0 ; nPack < 10 ; nPack++)
    {
        PCHARINFO pCharInfo=GetCharInfo();
        if (PCONTENTS pPack=GetCharInfo2()->pInventoryArray->Inventory.Pack[nPack])
        {
            if (pPack->Item->Type==ITEMTYPE_PACK && pContents->pContentsArray)
            {
                for (unsigned long nItem=0 ; nItem < pPack->Item->Slots ; nItem++)
                {
                    //DebugSpew("Pack[%d]->pContentsArray->Contents[%d]==0x%08X",nPack,nItem,pPack->pContentsArray->Contents[nItem]);
                    if (pPack->pContentsArray->Contents[nItem]==pContents)
                    {
                        return 262+(nPack*10)+nItem;
                    }
                }
            }
        }
    }

    for (nPack=0 ; nPack < NUM_BANK_SLOTS ; nPack++)
    {
        PCHARINFO pCharInfo=GetCharInfo();
		PCONTENTS pPack=NULL;
        if (pCharInfo->pBankArray) pPack=pCharInfo->pBankArray->Bank[nPack];
        if (pPack)
        {
            if (pPack==pContents)
            {
                if (nPack<0x18)
                    return 2000+nPack;
                return 2500+nPack-0x10;
            }
            if (pPack->Item->Type==ITEMTYPE_PACK && pContents->pContentsArray)
            {
                for (unsigned long nItem=0 ; nItem < pPack->Item->Slots ; nItem++)
                {
                    if (pPack->pContentsArray->Contents[nItem]==pContents)
                    {
                        if (nPack<0x18)
                            return 2032+(nPack*10)+nItem;
                        return 2532+((nPack-0x18)*10)+nItem;
                    }
                }
            }
        }        
    }
#endif

    return -1;
}

DWORD LastFoundInvSlot=-1;

int FindInvSlot(PCHAR pName, BOOL Exact)
{
    CHAR Name[MAX_STRING]={0};
    strlwr(strcpy(Name,pName));
    CHAR szTemp[MAX_STRING]={0};
    PEQINVSLOTMGR pInvMgr=(PEQINVSLOTMGR)pInvSlotMgr;
    for (unsigned long N = 0 ; N < 0x800 ; N++)
    {
        if (pInvMgr->SlotArray[N])
        {
            class CInvSlot *x = (class CInvSlot *)pInvMgr->SlotArray[N];
            struct _CONTENTS *y = NULL;

            if (x) 
               x->GetItemBase(&y);

            if (y)
            {
                if (!Exact)
                {
                    _strlwr(strcpy(szTemp,GetItemFromContents(y)->Name));
                    if (strstr(szTemp,Name))
                    {
                        if (pInvMgr->SlotArray[N]->pInvSlotWnd)
                        {
                            LastFoundInvSlot=N;
                            return pInvMgr->SlotArray[N]->InvSlot;
                        }
                        // let it try to find it in an open slot if this fails
                    }
                }
                else if (!_stricmp(Name,GetItemFromContents(y)->Name))
                {
                    if (pInvMgr->SlotArray[N]->pInvSlotWnd)
                    {
                        LastFoundInvSlot=N;
                        return pInvMgr->SlotArray[N]->InvSlot;
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

#if 0
    PEQINVSLOTMGR pInvMgr=(PEQINVSLOTMGR)pInvSlotMgr;
    for (unsigned long N = LastFoundInvSlot+1 ; N < 0x800 ; N++)
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
                else if (!_stricmp(Name,(*pInvMgr->SlotArray[N]->ppContents)->Item->Name))
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
#endif
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
        //                        sprintf(Buffer,"%d",atof(Arg[i])&&atof(Arg[i+2]));
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
        //                            sprintf(Buffer,"%d",atof(Arg[i])||atof(Arg[i+2]));
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
#ifndef ISXEQ
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
    CO_NEGATE=25,
    CO_TOTAL=26,
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
    12,//negate
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
#define UnaryOp(op)    {StackSetTop(=op##(StackTop()));}
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
        case CO_NEGATE:
            UnaryOp(-);
            break;
        case CO_DIVIDE:
            if (StackTop())
            {
                BinaryAssign(/);
            }
            else
            {
                //printf("Divide by zero error\n");
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
                    //printf("Integer divide by zero error\n");
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
                    //printf("Modulus by zero error\n");
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
#define HasPrecedence(a,b) (CalcOpPrecedence[a]>=CalcOpPrecedence[b])
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

    bool WasParen=false;
    for (char *pCur=szFormula ; pCur<pEnd ; pCur++)
    {
        switch(*pCur)
        {
        case ' ':
            continue;
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
            WasParen=true;
            continue;
        case '+':
            if (pCur[1]!='+')
                NewOp(CO_ADD);
            break;
        case '-':
            if (pCur[1]=='-')
            {
                pCur++;
                NewOp(CO_ADD);
            }
            else
            {
                if (CurrentToken[0] || WasParen) 
                { 
                    NewOp(CO_SUBTRACT); 
                } 
                else 
                    NewOp(CO_NEGATE);
            }
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
                //printf("Unparsable: '%c'\n",*pCur);
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
                //printf("Unparsable: '%c'\n",*pCur);
                FatalError("Unparsable in Calculation: '%c'",*pCur);
                // unparsable
                free(pOpList);
                free(pStack);
                return false;
            }
            break;
        }
        WasParen=false;
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
    strupr(strcpy(Buffer,szFormula));
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
#endif

bool PlayerHasAAAbility(DWORD AAIndex)
{
    for (int i = 0; i < AA_CHAR_MAX_REAL; i++)
    {
        if ( pPCData->GetAlternateAbilityId(i) == AAIndex )
            return true;
    }
    return false;
}

#if 0
PCHAR GetAANameByIndex(DWORD AAIndex)
{
    for (unsigned long nAbility=0 ; nAbility<NUM_ALT_ABILITIES_ARRAY ; nAbility++)
    {
        if ( ((PALTADVMGR)pAltAdvManager)->AltAbilities->AltAbilityList->Abilities[nAbility])
        {
            if ( PALTABILITY pAbility=((PALTADVMGR)pAltAdvManager)->AltAbilities->AltAbilityList->Abilities[nAbility]->Ability) 
            {
                if (pAbility->Index == AAIndex)
                {
                    return pStringTable->getString(pAbility->nName,0);
                }
            }
        }
    }
    return "AA Not Found";
}
#endif

DWORD GetAAIndexByName(PCHAR AAName)
{
    unsigned long nAbility;
    for (nAbility=0 ; nAbility<AA_CHAR_MAX_REAL ; nAbility++) {
        if ( PALTABILITY pAbility=pAltAdvManager->GetAAById(pPCData->GetAlternateAbilityId(nAbility))) {
            if (PCHAR pName=pCDBStr->GetString(pAbility->nName, 1, NULL)) {
                if (!_stricmp(AAName,pName)) {
                    return pAbility->Index;
                }
            }
        }
    }
#if  0
    for (unsigned long nAbility=0 ; nAbility<NUM_ALT_ABILITIES_ARRAY ; nAbility++)
    {
        if ( ((PALTADVMGR)pAltAdvManager)->AltAbilities->AltAbilityList->Abilities[nAbility])
        {
            if ( PALTABILITY pAbility=((PALTADVMGR)pAltAdvManager)->AltAbilities->AltAbilityList->Abilities[nAbility]->Ability) 
            {
                if (PCHAR pName=pCDBStr->GetString(pAbility->nName, 1, NULL))
                {
                    if (!_stricmp(AAName,pName))
                    {
                        return pAbility->Index;
                    }
                }
            }
        }
    }
#endif
    return 0;
}

DWORD GetAAIndexByID(DWORD ID)
{
    unsigned long nAbility;
    for (nAbility=0 ; nAbility<AA_CHAR_MAX_REAL ; nAbility++) {
        if ( PALTABILITY pAbility=pAltAdvManager->GetAAById(pPCData->GetAlternateAbilityId(nAbility))) {
            if (pAbility->ID == ID ) {
                return pAbility->Index;
            }
        }
    }
#if 0
    for (unsigned long nAbility=0 ; nAbility<NUM_ALT_ABILITIES_ARRAY ; nAbility++)
    {
        if ( ((PALTADVMGR)pAltAdvManager)->AltAbilities->AltAbilityList->Abilities[nAbility])
        {
            if ( PALTABILITY pAbility=((PALTADVMGR)pAltAdvManager)->AltAbilities->AltAbilityList->Abilities[nAbility]->Ability) 
            {
                if (pAbility->ID == ID )
                {
                    return pAbility->Index;
                }
            }
        }
    }
#endif
    return 0;
}

BOOL IsPCNear(PSPAWNINFO pSpawn, FLOAT Radius)
{
    PSPAWNINFO pClose = NULL;
    if (ppSpawnManager && pSpawnList) 
    {
        pClose = (PSPAWNINFO)pSpawnList;
    }
    while (pClose) 
    {
        if (!IsInGroup(pClose) && (pClose->Type == SPAWN_PLAYER))
        {
            if ((pClose != pSpawn) && (DistanceToSpawn(pClose, pSpawn)<Radius)) 
                return TRUE;
        }
        pClose = pClose->pNext;
    }
    return false;
}

BOOL IsInGroup(PSPAWNINFO pSpawn,BOOL bCorpse)
{
    DWORD i;
    PCHARINFO pChar=GetCharInfo();
    if (!pChar->pGroupInfo)
		return FALSE;
    if (pSpawn==pChar->pSpawn)
        return TRUE;
    for (i=1;i<6;i++) {
        if (pChar->pGroupInfo->pMember[i])
        {
            CHAR Name[MAX_STRING]={0};
            GetCXStr(pChar->pGroupInfo->pMember[i]->pName,Name,MAX_STRING);
            if(!bCorpse) {
				if (!_stricmp(Name,pSpawn->Name)) {
					return TRUE;
				}
			} else {
				CHAR szSearch[256] = {0};
				strcpy_s(szSearch,Name);
				strcat_s(szSearch,"'s corpse");
				DWORD l = strlen(szSearch);
				if (!strnicmp(pSpawn->Name,szSearch,l)) {
					return TRUE;
				}
			}
        }
	}
    return FALSE;
}

EQLIB_API BOOL IsInRaid(PSPAWNINFO pSpawn, BOOL bCorpse)
{
    DWORD i;
    if (pSpawn==GetCharInfo()->pSpawn)
        return TRUE;
    DWORD l = strlen(pSpawn->Name);
    for (i=0;i<72;i++)
    {
		if(!bCorpse) {
			if (!strnicmp(pRaid->RaidMember[i].Name,pSpawn->Name,l+1) && pRaid->RaidMember[i].nClass == pSpawn->Class) {
				return TRUE;
			}
		} else {
			CHAR szSearch[256] = {0};
			strcpy_s(szSearch,pRaid->RaidMember[i].Name);
			strcat_s(szSearch,"'s corpse");
			l = strlen(szSearch);
			if (!strnicmp(szSearch,pSpawn->Name,l) && pRaid->RaidMember[i].nClass == pSpawn->Class) {
				return TRUE;
			}
		}
    }
    return FALSE;
} 

BOOL IsNamed(PSPAWNINFO pSpawn)
{
    CHAR szTemp[MAX_STRING]={0};

    if (GetSpawnType(pSpawn) != NPC)
        return false;
    if (!IsTargetable(pSpawn))
        return false;
    if (pSpawn->Class >= 20 && pSpawn->Class <= 35)  // NPC GMs
        return false;
    if (pSpawn->Class == 40)  // NPC bankers
        return false;
    if (pSpawn->Class == 41 || pSpawn->Class == 70)  // NPC/Quest/TBS merchants
        return false;
    if (pSpawn->Class == 60 || pSpawn->Class == 61)  //Ldon Merchants/Recruiters
        return false;
    if (pSpawn->Class == 62)  // Destructible Objects
        return false;
    if (pSpawn->Class == 63 || pSpawn->Class == 64)  // Tribute Master/Guild Tribute Master
        return false;
    if (pSpawn->Class == 66)  // Guild Banker
        return false;
    if (pSpawn->Class == 67 || pSpawn->Class == 68)  //Don Merchants (Norrath's Keepers/Dark Reign)
        return false;
    if (pSpawn->Class == 69)  // Fellowship Registrar
        return false;
    if (pSpawn->Class == 71)  // Mercenary Liason
        return false;

    strcpy(szTemp,pSpawn->Name);
    strtok(szTemp," ");

    // Checking for mobs that have 'A' or 'An' as their first name
    if (szTemp[0] == 'A')
    {
        if (szTemp[1] == '_')
            return false;
        else if (szTemp[1] == 'n')
            if (szTemp[2] == '_')
                return false;
    }
    if ((!strnicmp(szTemp,"Guard",5))          ||
        (!strnicmp(szTemp,"Defender",8))       ||
        (!strnicmp(szTemp,"Soulbinder",10))    ||
        (!strnicmp(szTemp,"Aura",4))           ||
        (!strnicmp(szTemp,"Sage",4))           ||
        //(!strnicmp(szTemp,"High_Priest",11))   ||
        (!strnicmp(szTemp,"Ward",4))           ||
        //(!strnicmp(szTemp,"Shroudkeeper",12))  ||
        (!strnicmp(szTemp,"Eye of",6))         ||
        (!strnicmp(szTemp,"Diaku",5)))
        return false;
    if (isupper(szTemp[0]) || szTemp[0] == '#')
        return true;

    return false;
}

PCHAR FormatSearchSpawn(PCHAR Buffer, PSEARCHSPAWN pSearchSpawn)
{
    CHAR szTemp[MAX_STRING] = {0};
    if (!Buffer) return NULL;
    if (!pSearchSpawn) return strcpy(Buffer,"None");
    PCHAR pszSpawnType;
    switch(pSearchSpawn->SpawnType)
    {
    case NONE:
    default:
        pszSpawnType="any";
        break;
    case PC:
        pszSpawnType="pc";
        break;
    case MOUNT:
        pszSpawnType="mount";
        break;
    case PET:
        pszSpawnType="pet";
        break;
    case PCPET:
        pszSpawnType="pcpet";
        break;
    case NPCPET:
        pszSpawnType="npcpet";
        break;
    case NPC:
        pszSpawnType="npc";
        break;
    case CORPSE:
        pszSpawnType="corpse";
        break;
    case TRIGGER:
        pszSpawnType="trigger";
        break;
    case TRAP:
        pszSpawnType="trap";
        break;
    case CHEST:
        pszSpawnType="chest";
        break;
    case TIMER:
        pszSpawnType="timer";
        break;
    case UNTARGETABLE:
        pszSpawnType="untargetable";
        break;
    case MERCENARY:
        pszSpawnType="mercenary";
        break;
    case FLYER:
        pszSpawnType="flyer";
        break;
    }

    sprintf(Buffer,"(%d-%d) %s",pSearchSpawn->MinLevel,pSearchSpawn->MaxLevel,pszSpawnType);

    if (pSearchSpawn->szName[0]!=0) {
        sprintf(szTemp," %s",pSearchSpawn->szName);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->szRace[0]!=0) {
        sprintf(szTemp," Race:%s",pSearchSpawn->szRace);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->szClass[0]!=0) {
        sprintf(szTemp," Class:%s",pSearchSpawn->szClass);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->szBodyType[0]!=0) {
        sprintf(szTemp," Body:%s",pSearchSpawn->szBodyType);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->GuildID!=0xFFFFFFFF) {
        char *szGuild = GetGuildByID(pSearchSpawn->GuildID);
        sprintf(szTemp," Guild:%s", szGuild ? szGuild : "Unknown");
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->bKnownLocation) {
        sprintf(szTemp," at %1.2f,%1.2f", pSearchSpawn->yLoc, pSearchSpawn->xLoc);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->FRadius<10000.0f) {
        sprintf(szTemp," Radius:%1.2f",pSearchSpawn->FRadius);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->ZRadius<10000.0f) {
        sprintf(szTemp," Z:±%1.2f",pSearchSpawn->ZRadius);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->Radius>0.0f) {
        sprintf(szTemp," NoPC:%1.2f",pSearchSpawn->Radius);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->SpawnID) {
        sprintf(szTemp," ID:%d",pSearchSpawn->SpawnID);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->NotID) {
        sprintf(szTemp," NotID:%d",pSearchSpawn->NotID);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->bAlert) {
        sprintf(szTemp," Alert:%d",pSearchSpawn->AlertList);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->bNoAlert) {
        sprintf(szTemp," NoAlert:%d",pSearchSpawn->NoAlertList);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->bNearAlert) {
        sprintf(szTemp," NearAlert:%d",pSearchSpawn->NearAlertList);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->bNotNearAlert) {
        sprintf(szTemp," NotNearAlert:%d",pSearchSpawn->NotNearAlertList);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->bGM && pSearchSpawn->SpawnType != NPC ) strcat(Buffer," GM");
    if (pSearchSpawn->bTrader) strcat(Buffer," Trader");
    if (pSearchSpawn->bLFG) strcat(Buffer," LFG");
    if (pSearchSpawn->bLight) {
        strcat(Buffer," Light");
        if (pSearchSpawn->szLight[0]) {
            strcat(Buffer,":");
            strcat(Buffer,pSearchSpawn->szLight);
        }
    }
    if (pSearchSpawn->bLoS) strcat(Buffer," LoS");

    return Buffer;
}

PSPAWNINFO NthNearestSpawn(PSEARCHSPAWN pSearchSpawn, DWORD Nth, PSPAWNINFO pOrigin, BOOL IncludeOrigin)
{
    if (!pSearchSpawn || !Nth || !pOrigin)
        return 0;
    CIndex<PMQRANK> SpawnSet;
    PSPAWNINFO pSpawn=(PSPAWNINFO)pSpawnList;
    // create our set    
    DWORD TotalMatching=0;
    if (IncludeOrigin)
    {
        while (pSpawn)
        {
            if (SpawnMatchesSearch(pSearchSpawn,pOrigin,pSpawn))
            {
                // matches search, add to our set
                TotalMatching++;
                PMQRANK pNewRank=new MQRANK;
                pNewRank->VarPtr.Ptr=pSpawn;
                pNewRank->Value.Float=GetDistance(pOrigin->X,pOrigin->Y,pSpawn->X,pSpawn->Y);
                SpawnSet+=pNewRank;
            }
            pSpawn=pSpawn->pNext;
        }
    }
    else
    {
        while (pSpawn)
        {
            if (pSpawn!=pOrigin && SpawnMatchesSearch(pSearchSpawn,pOrigin,pSpawn))
            {
                // matches search, add to our set
                TotalMatching++;
                PMQRANK pNewRank=new MQRANK;
                pNewRank->VarPtr.Ptr=pSpawn;
                pNewRank->Value.Float=GetDistance(pOrigin->X,pOrigin->Y,pSpawn->X,pSpawn->Y);
                SpawnSet+=pNewRank;
            }
            pSpawn=pSpawn->pNext;
        }
    }
    if (TotalMatching<Nth)
    {// CIndex.Cleanup will call "delete" on every valid pointer in our list.
        SpawnSet.Cleanup();
        return 0;
    }
    // sort our list
	std::sort(&SpawnSet.List[0], &SpawnSet.List[0]+TotalMatching, pMQRankFloatCompare);
    // get our Nth nearest
    pSpawn=(PSPAWNINFO)SpawnSet[Nth-1]->VarPtr.Ptr;
    SpawnSet.Cleanup();
    return pSpawn;
}

DWORD CountMatchingSpawns(PSEARCHSPAWN pSearchSpawn, PSPAWNINFO pOrigin, BOOL IncludeOrigin)
{
    if (!pSearchSpawn || !pOrigin)
        return 0;
    DWORD TotalMatching=0;
    PSPAWNINFO pSpawn=(PSPAWNINFO)pSpawnList;
    if (IncludeOrigin)
    {
        while (pSpawn)
        {
            if (SpawnMatchesSearch(pSearchSpawn,pOrigin,pSpawn))
            {
                TotalMatching++;
            }
            pSpawn=pSpawn->pNext;
        }
    }
    else
    {
        while (pSpawn)
        {
            if (pSpawn!=pOrigin && SpawnMatchesSearch(pSearchSpawn,pOrigin,pSpawn))
            {
                // matches search, add to our set
                TotalMatching++;
            }
            pSpawn=pSpawn->pNext;
        }
    }
    return TotalMatching;
}


PSPAWNINFO SearchThroughSpawns(PSEARCHSPAWN pSearchSpawn, PSPAWNINFO pChar)
{
    PSPAWNINFO pFromSpawn = NULL;

    if (pSearchSpawn->FromSpawnID>0 && (pSearchSpawn->bTargNext ||pSearchSpawn->bTargPrev)) 
    {
        pFromSpawn=(PSPAWNINFO)GetSpawnByID(pSearchSpawn->FromSpawnID);
        if (!pFromSpawn) return NULL;
        for ( int N=0 ; N < 3000 ; N++)
        {
            if (EQP_DistArray[N].VarPtr.Ptr==pFromSpawn)
            {
                if (pSearchSpawn->bTargPrev)
                {
                    N--;
                    for (N ; N >= 0 ; N--)
                    {
                        if (EQP_DistArray[N].VarPtr.Ptr && 
                            SpawnMatchesSearch(pSearchSpawn,pFromSpawn,(PSPAWNINFO)EQP_DistArray[N].VarPtr.Ptr))
                            return (PSPAWNINFO)EQP_DistArray[N].VarPtr.Ptr;
                    }
                }
                else
                {
                    N++;
                    for (N ; N < 3000 ; N++)
                    {
                        if (EQP_DistArray[N].VarPtr.Ptr && 
                            SpawnMatchesSearch(pSearchSpawn,pFromSpawn,(PSPAWNINFO)EQP_DistArray[N].VarPtr.Ptr))
                            return (PSPAWNINFO)EQP_DistArray[N].VarPtr.Ptr;
                    }
                }
                return NULL;
            }
        }
    }
    return NthNearestSpawn(pSearchSpawn,1,pChar,TRUE);
}

BOOL SearchSpawnMatchesSearchSpawn(PSEARCHSPAWN pSearchSpawn1, PSEARCHSPAWN pSearchSpawn2)
{
	if(pSearchSpawn1->AlertList!=pSearchSpawn2->AlertList)
		return false;
	if(pSearchSpawn1->SpawnType!=pSearchSpawn2->SpawnType)
		return false;
	if(pSearchSpawn1->FRadius!=pSearchSpawn2->FRadius)
		return false;
	if(pSearchSpawn1->FromSpawnID!=pSearchSpawn2->FromSpawnID)
		return false;
	if(pSearchSpawn1->GuildID!=pSearchSpawn2->GuildID)
		return false;
	if(pSearchSpawn1->MaxLevel!=pSearchSpawn2->MaxLevel)
		return false;
	if(pSearchSpawn1->MinLevel!=pSearchSpawn2->MinLevel)
		return false;
	if(pSearchSpawn1->NearAlertList!=pSearchSpawn2->NearAlertList)
		return false;
	if(pSearchSpawn1->NoAlertList!=pSearchSpawn2->NoAlertList)
		return false;
	if(pSearchSpawn1->NotID!=pSearchSpawn2->NotID)
		return false;
	if(pSearchSpawn1->NotNearAlertList!=pSearchSpawn2->NotNearAlertList)
		return false;
	if(pSearchSpawn1->Radius!=pSearchSpawn2->Radius)
		return false;
	if(pSearchSpawn1->SortBy!=pSearchSpawn2->SortBy)
		return false;
	if(pSearchSpawn1->SpawnID!=pSearchSpawn2->SpawnID)
		return false;
	if(_stricmp(pSearchSpawn1->szBodyType,pSearchSpawn2->szBodyType))
		return false;
	if(_stricmp(pSearchSpawn1->szClass,pSearchSpawn2->szClass))
		return false;
	if(_stricmp(pSearchSpawn1->szLight,pSearchSpawn2->szLight))
		return false;
	if(_stricmp(pSearchSpawn1->szName,pSearchSpawn2->szName))
		return false;
	if(_stricmp(pSearchSpawn1->szRace,pSearchSpawn2->szRace))
		return false;
	if(pSearchSpawn1->xLoc!=pSearchSpawn2->xLoc)
		return false;
	if(pSearchSpawn1->yLoc!=pSearchSpawn2->yLoc)
		return false;
	if(pSearchSpawn1->ZRadius!=pSearchSpawn2->ZRadius)
		return false;	
	if(pSearchSpawn1->bAlert!=pSearchSpawn2->bAlert)
		return false;
	if(pSearchSpawn1->bAura!=pSearchSpawn2->bAura)
		return false;
	if(pSearchSpawn1->bBanner!=pSearchSpawn2->bBanner)
		return false;
	if(pSearchSpawn1->bCampfire!=pSearchSpawn2->bCampfire)
		return false;
	if(pSearchSpawn1->bDps!=pSearchSpawn2->bDps)
		return false;
	if(pSearchSpawn1->bExactName!=pSearchSpawn2->bExactName)
		return false;
	if(pSearchSpawn1->bGM!=pSearchSpawn2->bGM)
		return false;
	if(pSearchSpawn1->bGroup!=pSearchSpawn2->bGroup)
		return false;
	if(pSearchSpawn1->bKnight!=pSearchSpawn2->bKnight)
		return false;
	if(pSearchSpawn1->bKnownLocation!=pSearchSpawn2->bKnownLocation)
		return false;
	if(pSearchSpawn1->bLFG!=pSearchSpawn2->bLFG)
		return false;
	if(pSearchSpawn1->bLight!=pSearchSpawn2->bLight)
		return false;
	if(pSearchSpawn1->bLoS!=pSearchSpawn2->bLoS)
		return false;
	if(pSearchSpawn1->bMerchant!=pSearchSpawn2->bMerchant)
		return false;
	if(pSearchSpawn1->bNamed!=pSearchSpawn2->bNamed)
		return false;
	if(pSearchSpawn1->bNearAlert!=pSearchSpawn2->bNearAlert)
		return false;
	if(pSearchSpawn1->bNoAlert!=pSearchSpawn2->bNoAlert)
		return false;
	if(pSearchSpawn1->bNoGroup!=pSearchSpawn2->bNoGroup)
		return false;
	if(pSearchSpawn1->bNoGuild!=pSearchSpawn2->bNoGuild)
		return false;
	if(pSearchSpawn1->bNoPet!=pSearchSpawn2->bNoPet)
		return false;
	if(pSearchSpawn1->bNotNearAlert!=pSearchSpawn2->bNotNearAlert)
		return false;
	if(pSearchSpawn1->bRaid!=pSearchSpawn2->bRaid)
		return false;
	if(pSearchSpawn1->bSlower!=pSearchSpawn2->bSlower)
		return false;
	if(pSearchSpawn1->bSpawnID!=pSearchSpawn2->bSpawnID)
		return false;
	if(pSearchSpawn1->bTank!=pSearchSpawn2->bTank)
		return false;
	if(pSearchSpawn1->bTargetable!=pSearchSpawn2->bTargetable)
		return false;
	if(pSearchSpawn1->bTargNext!=pSearchSpawn2->bTargNext)
		return false;
	if(pSearchSpawn1->bTargPrev!=pSearchSpawn2->bTargPrev)
		return false;
	if(pSearchSpawn1->bTrader!=pSearchSpawn2->bTrader)
		return false;
	if(pSearchSpawn1->bTributeMaster!=pSearchSpawn2->bTributeMaster)
		return false;
	return true;
}
BOOL SpawnMatchesSearch(PSEARCHSPAWN pSearchSpawn, PSPAWNINFO pChar, PSPAWNINFO pSpawn)
{
    CHAR szName[MAX_STRING] = {0};
    CHAR szSearchName[MAX_STRING] = {0};
    eSpawnType SpawnType = GetSpawnType(pSpawn);
	if(SpawnType==PET && (pSearchSpawn->SpawnType==PCPET || pSearchSpawn->SpawnType==NPCPET)) {
		if(PSPAWNINFO pTheMaster = (PSPAWNINFO)GetSpawnByID(pSpawn->MasterID)) {
			if(pTheMaster->Type==SPAWN_NPC) {
				SpawnType=NPCPET;
			} else if(pTheMaster->Type==SPAWN_PLAYER) {
				SpawnType=PCPET;
			}
		}
	}
    if (pSearchSpawn->SpawnType != SpawnType && pSearchSpawn->SpawnType!=NONE)
    {	
        if (pSearchSpawn->SpawnType==NPCCORPSE) {
            if (SpawnType != CORPSE || pSpawn->Deity) {
                return FALSE;
			}
        } else if (pSearchSpawn->SpawnType==PCCORPSE) {
            if (SpawnType != CORPSE || !pSpawn->Deity) {
                return FALSE;
			}
        } else  if (pSearchSpawn->SpawnType==NPC && SpawnType==UNTARGETABLE) {
			return FALSE;
		} else {

            // if the search type is not npc or the mob type is UNT, continue?
            // stupid /who
           

            if (pSearchSpawn->SpawnType!=NPC || SpawnType!=UNTARGETABLE)
                return FALSE;
        }
    }
    _strlwr(strcpy(szName,pSpawn->Name));
    _strlwr(strcpy(szSearchName,pSearchSpawn->szName));
    if (!strstr(szName,szSearchName) && !strstr(CleanupName(szName,FALSE),szSearchName))
        return FALSE;
    if (pSearchSpawn->bExactName && stricmp(CleanupName(szName,FALSE,!gbExactSearchCleanNames),pSearchSpawn->szName))
        return FALSE;
    if (pSearchSpawn->MinLevel && pSpawn->Level < pSearchSpawn->MinLevel)
        return FALSE;
    if (pSearchSpawn->MaxLevel && pSpawn->Level > pSearchSpawn->MaxLevel)
        return FALSE;
    if (pSearchSpawn->NotID == pSpawn->SpawnID)
        return FALSE;
    if (pSearchSpawn->bSpawnID && pSearchSpawn->SpawnID != pSpawn->SpawnID)
        return FALSE;
    if (pSearchSpawn->GuildID!=0xFFFFFFFF && pSearchSpawn->GuildID!=pSpawn->GuildID)
        return FALSE;
    if (pSearchSpawn->bGM && pSearchSpawn->SpawnType != NPC )
        if (!pSpawn->GM)
            return FALSE;
    if (pSearchSpawn->bGM && pSearchSpawn->SpawnType == NPC )
        if (pSpawn->Class < 20 || pSpawn->Class > 35 )
            return FALSE;
    if (pSearchSpawn->bNamed && !IsNamed(pSpawn))
        return FALSE;
    if (pSearchSpawn->bMerchant && pSpawn->Class != 41 )
        return FALSE;
    if (pSearchSpawn->bTributeMaster && pSpawn->Class != 63 )
        return FALSE;
    if (pSearchSpawn->bNoGuild && (pSpawn->GuildID != 0xFFFFFFFF))
        return FALSE;
    if (pSearchSpawn->bKnight && pSearchSpawn->SpawnType != NPC) 
        if (pSpawn->Class != 3 && pSpawn->Class != 5 )
            return FALSE;
    if (pSearchSpawn->bTank && pSearchSpawn->SpawnType != NPC) 
        if (pSpawn->Class != 3 && pSpawn->Class != 5 && pSpawn->Class != 1 )
            return FALSE;
    if (pSearchSpawn->bHealer && pSearchSpawn->SpawnType != NPC)
        if (pSpawn->Class != 2 && pSpawn->Class != 6)
            return FALSE;
    if (pSearchSpawn->bDps && pSearchSpawn->SpawnType != NPC)
        if (pSpawn->Class != 4 && pSpawn->Class != 9 && pSpawn->Class != 12 )
            return FALSE;
    if (pSearchSpawn->bSlower && pSearchSpawn->SpawnType != NPC)
        if (pSpawn->Class != 10 && pSpawn->Class != 14 && pSpawn->Class != 15)
            return FALSE;
    if (pSearchSpawn->bLFG && !pSpawn->LFG)
        return FALSE;
    if (pSearchSpawn->bTrader && !pSpawn->Trader)
        return FALSE;
    if (pSearchSpawn->bGroup) {
		BOOL ingrp = 0;
		if(pSearchSpawn->SpawnType==PCCORPSE || pSpawn->Type==SPAWN_CORPSE) {
			ingrp = IsInGroup(pSpawn,1);
		} else {
			ingrp = IsInGroup(pSpawn);
		}
        if(!ingrp)
			return FALSE;
	}
    if (pSearchSpawn->bNoGroup && IsInGroup(pSpawn))
        return FALSE;
    if (pSearchSpawn->bRaid) {
		BOOL ingrp = 0;
		if(pSearchSpawn->SpawnType==PCCORPSE || pSpawn->Type==SPAWN_CORPSE) {
			ingrp = IsInRaid(pSpawn,1);
		} else {
			ingrp = IsInRaid(pSpawn);
		}
         if(!ingrp)
			 return FALSE;
	}
    if (pSearchSpawn->bKnownLocation) 
    {
        if ((pSearchSpawn->xLoc!=pSpawn->X || pSearchSpawn->yLoc!=pSpawn->Y))
            if (pSearchSpawn->FRadius<10000.0f && DistanceToPoint(pSpawn,pSearchSpawn->xLoc,pSearchSpawn->yLoc)>pSearchSpawn->FRadius)
                return FALSE;
    }
    else if (pSearchSpawn->FRadius<10000.0f && DistanceToSpawn(pChar, pSpawn)>pSearchSpawn->FRadius)
        return FALSE;

    if (pSearchSpawn->Radius>0.0f && IsPCNear(pSpawn,pSearchSpawn->Radius))
        return FALSE;
    if (gZFilter<10000.0f && ( (pSpawn->Z > pChar->Z + gZFilter) || (pSpawn->Z < pChar->Z - gZFilter)))
        return FALSE;
    if (pSearchSpawn->ZRadius<10000.0f &&  (pSpawn->Z > pChar->Z + pSearchSpawn->ZRadius ||pSpawn->Z < pChar->Z - pSearchSpawn->ZRadius))
        return FALSE;
    if (pSearchSpawn->bLight) 
    {
        PCHAR pLight=GetLightForSpawn(pSpawn);
        if (!_stricmp(pLight,"NONE")) 
            return FALSE;
        if (pSearchSpawn->szLight[0] && stricmp(pLight,pSearchSpawn->szLight)) 
            return FALSE;
    }
    if ((pSearchSpawn->bAlert) && CAlerts.AlertExist(pSearchSpawn->AlertList)) {
        if (!IsAlert(pChar,pSpawn,pSearchSpawn->AlertList)) 
            return FALSE;
    }
    if ((pSearchSpawn->bNoAlert) && CAlerts.AlertExist(pSearchSpawn->NoAlertList)) {
        if (IsAlert(pChar,pSpawn,pSearchSpawn->NoAlertList)) 
            return FALSE;
    }
    if ((pSearchSpawn->bNotNearAlert) && (GetClosestAlert(pSpawn, pSearchSpawn->NotNearAlertList))) 
        return FALSE;
    if ((pSearchSpawn->bNearAlert) && (!GetClosestAlert(pSpawn,pSearchSpawn->NearAlertList))) 
        return FALSE;

    if (pSearchSpawn->szClass[0] && stricmp(pSearchSpawn->szClass,GetClassDesc(pSpawn->Class)))
        return FALSE;
    if (pSearchSpawn->szBodyType[0] && stricmp(pSearchSpawn->szBodyType,GetBodyTypeDesc(GetBodyType(pSpawn))))
        return FALSE;
    if (pSearchSpawn->szRace[0] && stricmp(pSearchSpawn->szRace,pEverQuest->GetRaceDesc(pSpawn->Race)))
        return FALSE;
    //if (pSearchSpawn->bLoS && (!LineOfSight(pChar,pSpawn)))
	if (pSearchSpawn->bLoS && (!pLocalPlayer->CanSee((EQPlayer *)pSpawn)))
        return FALSE;
    if (pSearchSpawn->bTargetable && (!IsTargetable(pSpawn)))
        return FALSE;
	if (pSearchSpawn->PlayerState && !(pSpawn->PlayerState & pSearchSpawn->PlayerState)) // if player state isn't 0 and we have that bit set
		return FALSE;
    return TRUE;
}
#endif

#ifndef ISXEQ
PCHAR ParseSearchSpawnArgs(PCHAR szArg, PCHAR szRest, PSEARCHSPAWN pSearchSpawn)
{
    if (szArg && pSearchSpawn) {
        if (!_stricmp(szArg,"pc")) {
            pSearchSpawn->SpawnType = PC;
        } else if (!_stricmp(szArg,"npc")) {
            pSearchSpawn->SpawnType = NPC;
        } else if (!_stricmp(szArg,"mount")) {
            pSearchSpawn->SpawnType = MOUNT;
        } else if (!_stricmp(szArg,"pet")) {
            pSearchSpawn->SpawnType = PET;
        } else if (!_stricmp(szArg,"pcpet")) {
            pSearchSpawn->SpawnType = PCPET;
        } else if (!_stricmp(szArg,"npcpet")) {
            pSearchSpawn->SpawnType = NPCPET;
        } else if (!_stricmp(szArg,"nopet")) { 
            pSearchSpawn->bNoPet = TRUE; 
        } else if (!_stricmp(szArg,"corpse")) {
            pSearchSpawn->SpawnType = CORPSE;
        } else if (!_stricmp(szArg,"npccorpse")) {
            pSearchSpawn->SpawnType = NPCCORPSE;
        } else if (!_stricmp(szArg,"pccorpse")) {
            pSearchSpawn->SpawnType = PCCORPSE;
        } else if (!_stricmp(szArg,"trigger")) {
            pSearchSpawn->SpawnType = TRIGGER;
        } else if (!_stricmp(szArg,"untargetable")) {
            pSearchSpawn->SpawnType = UNTARGETABLE;
        } else if (!_stricmp(szArg,"trap")) {
            pSearchSpawn->SpawnType = TRAP;
        } else if (!_stricmp(szArg,"chest")) {
            pSearchSpawn->SpawnType = CHEST;
        } else if (!_stricmp(szArg,"timer")) {
            pSearchSpawn->SpawnType = TIMER;
        } else if (!_stricmp(szArg,"aura")) {
            pSearchSpawn->SpawnType = AURA;
        } else if (!_stricmp(szArg,"object")) {
            pSearchSpawn->SpawnType = OBJECT;
        } else if (!_stricmp(szArg,"banner")) {
            pSearchSpawn->SpawnType = BANNER;
        } else if (!_stricmp(szArg,"campfire")) {
            pSearchSpawn->SpawnType = CAMPFIRE;
        } else if (!_stricmp(szArg,"mercenary")) {
            pSearchSpawn->SpawnType = MERCENARY;
        } else if (!_stricmp(szArg,"flyer")) {
            pSearchSpawn->SpawnType = FLYER;
        } else if (!_stricmp(szArg,"any")) {
            pSearchSpawn->SpawnType = NONE;
        } else if (!_stricmp(szArg,"next")) {
            pSearchSpawn->bTargNext = TRUE;
        } else if (!_stricmp(szArg,"prev")) {
            pSearchSpawn->bTargPrev = TRUE;
        } else if (!_stricmp(szArg,"lfg")) {
            pSearchSpawn->bLFG = TRUE;
        } else if (!_stricmp(szArg,"gm")) {
            pSearchSpawn->bGM = TRUE;
        } else if (!_stricmp(szArg,"group")) {
            pSearchSpawn->bGroup = TRUE;
		} else if (!_stricmp(szArg,"nogroup")) {
			pSearchSpawn->bNoGroup = TRUE;
        } else if (!_stricmp(szArg,"raid")) {
            pSearchSpawn->bRaid = TRUE; 
        } else if (!_stricmp(szArg,"noguild")) {
            pSearchSpawn->bNoGuild = TRUE;
        } else if (!_stricmp(szArg,"trader")) {
            pSearchSpawn->bTrader = TRUE;
        } else if (!_stricmp(szArg,"named")) {
            pSearchSpawn->bNamed = TRUE;
        } else if (!_stricmp(szArg,"merchant")) {
            pSearchSpawn->bMerchant = TRUE;
        } else if (!_stricmp(szArg,"tribute")) {
            pSearchSpawn->bTributeMaster = TRUE;
        } else if (!_stricmp(szArg,"knight")) {
            pSearchSpawn->bKnight = TRUE;
        } else if (!_stricmp(szArg,"tank")) {
            pSearchSpawn->bTank = TRUE;
        } else if (!_stricmp(szArg,"healer")) {
            pSearchSpawn->bHealer = TRUE;
        } else if (!_stricmp(szArg,"dps")) {
            pSearchSpawn->bDps = TRUE;
        } else if (!_stricmp(szArg,"slower")) {
            pSearchSpawn->bSlower = TRUE;
        } else if (!_stricmp(szArg,"los")) {
            pSearchSpawn->bLoS = TRUE;
        } else if (!_stricmp(szArg,"targetable")) {
            pSearchSpawn->bTargetable = TRUE;
        } else if (!_stricmp(szArg,"range")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->MinLevel = atoi(szArg);
            GetArg(szArg,szRest,2);
            pSearchSpawn->MaxLevel = atoi(szArg);
            szRest = GetNextArg(szRest,2);
        } else if (!_stricmp(szArg,"loc")) {
            pSearchSpawn->bKnownLocation = TRUE;
            GetArg(szArg,szRest,1);
            pSearchSpawn->xLoc = (FLOAT)atof(szArg);
            GetArg(szArg,szRest,2);
            pSearchSpawn->yLoc = (FLOAT)atof(szArg);
            szRest = GetNextArg(szRest,2);
        } else if (!_stricmp(szArg,"id")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->bSpawnID = TRUE;
            pSearchSpawn->SpawnID = atoi(szArg);
            szRest = GetNextArg(szRest,1);
        } else if (!_stricmp(szArg,"radius")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->FRadius = atof(szArg);
            szRest = GetNextArg(szRest,1);
        } else if (!_stricmp(szArg,"body")) {
            GetArg(szArg,szRest,1);
            strcpy(pSearchSpawn->szBodyType,szArg);
            szRest = GetNextArg(szRest,1);
        } else if (!_stricmp(szArg,"class")) {
            GetArg(szArg,szRest,1);
            strcpy(pSearchSpawn->szClass,szArg);
            szRest = GetNextArg(szRest,1);
        } else if (!_stricmp(szArg,"race")) {
            GetArg(szArg,szRest,1);
            strcpy(pSearchSpawn->szRace,szArg);
            szRest = GetNextArg(szRest,1);
        } else if (!_stricmp(szArg,"light")) {
            DWORD Light = -1;
            DWORD i=0;
            GetArg(szArg,szRest,1);
            if (szArg[0]!=0) for (i=0;i<LIGHT_COUNT;i++) if (!_stricmp(szLights[i],szArg)) Light=i;
            if (Light != -1) {
                strcpy(pSearchSpawn->szLight,szLights[Light]);
                szRest = GetNextArg(szRest,1);
            } else {
                pSearchSpawn->szLight[0]=0;
            }
            pSearchSpawn->bLight=TRUE;
        } else if (!_stricmp(szArg,"guild")) {
            pSearchSpawn->GuildID=GetCharInfo()->pSpawn->GuildID;
        } else if (!_stricmp(szArg,"guildname")) {
            DWORD GuildID = 0xFFFFFFFF;
            GetArg(szArg,szRest,1);
            if (szArg[0]!=0)
				GuildID = GetGuildIDByName(szArg);
            if (GuildID!=0xFFFFFFFF) {
                pSearchSpawn->GuildID = GuildID;
				szRest = GetNextArg(szRest,1);
            }
        } else if (!_stricmp(szArg,"alert")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->AlertList = atoi(szArg);
            szRest = GetNextArg(szRest,1);
            pSearchSpawn->bAlert = TRUE;
        } else if (!_stricmp(szArg,"noalert")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->NoAlertList = atoi(szArg);
            szRest = GetNextArg(szRest,1);
            pSearchSpawn->bNoAlert = TRUE;
        } else if (!_stricmp(szArg,"notnearalert")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->NotNearAlertList = atoi(szArg);
            szRest = GetNextArg(szRest,1);
            pSearchSpawn->bNotNearAlert = TRUE;
        } else if (!_stricmp(szArg,"nearalert")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->NearAlertList = atoi(szArg);
            szRest = GetNextArg(szRest,1);
            pSearchSpawn->bNearAlert = TRUE;
        } else if (!_stricmp(szArg,"zradius")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->ZRadius = atof(szArg);
            szRest = GetNextArg(szRest,1);
        } else if (!_stricmp(szArg,"notid")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->NotID = atoi(szArg);
            szRest = GetNextArg(szRest,1);
        } else if (!_stricmp(szArg,"nopcnear")) {
            GetArg(szArg,szRest,1);
            if ((szArg[0]==0) || (0.0f == (pSearchSpawn->Radius = (FLOAT)atof(szArg)))) {
                pSearchSpawn->Radius = 200.0f;
            } else {
                szRest = GetNextArg(szRest,1);
            }
		} else if (!_stricmp(szArg, "playerstate")) {
			GetArg(szArg, szRest, 1);
			pSearchSpawn->PlayerState |= atoi(szArg); // This allows us to pass multiple playerstate args
			szRest = GetNextArg(szRest, 1);
        } else if (IsNumber(szArg)) {
            pSearchSpawn->MinLevel=atoi(szArg);
            pSearchSpawn->MaxLevel=pSearchSpawn->MinLevel;
        } else {
            for (DWORD N=1;N<17;N++)
            {
                if (!_stricmp(szArg,ClassInfo[N].Name) || !_stricmp(szArg,ClassInfo[N].ShortName))
                {
                    strcpy(pSearchSpawn->szClass,pEverQuest->GetClassDesc(N));
                    return szRest;
                }
            }
            if (pSearchSpawn->szName[0])
            {// multiple word name
                strcat(pSearchSpawn->szName," ");
                strcat(pSearchSpawn->szName,szArg);
            }
            else {
                if (szArg[0]=='=')
                {
                    pSearchSpawn->bExactName=TRUE;
                    szArg++;
                }
                strcpy(pSearchSpawn->szName,szArg);
            }
        }
    }
    return szRest;
}

VOID ParseSearchSpawn(PCHAR Buffer, PSEARCHSPAWN pSearchSpawn)
{
    CHAR szArg[MAX_STRING] = {0};
    CHAR szMsg[MAX_STRING] = {0};
    CHAR szLLine[MAX_STRING] = {0};
    PCHAR szFilter = szLLine;
    BOOL DidTarget = FALSE;
    BOOL bArg = TRUE;

    bRunNextCommand = TRUE;
    _strlwr(strcpy(szLLine,Buffer));
    while (bArg) {
        GetArg(szArg,szFilter,1);
        szFilter = GetNextArg(szFilter,1);
        if (szArg[0]==0) {
            bArg = FALSE;
        } else {
            szFilter = ParseSearchSpawnArgs(szArg,szFilter,pSearchSpawn);
        }
    }
}
#else
VOID ParseSearchSpawn(int BeginInclusive, int EndExclusive,char *argv[], SEARCHSPAWN &SearchSpawn)
{
    for (int arg = BeginInclusive ; arg < EndExclusive ; arg++)
        arg+=ParseSearchSpawnArg(arg,EndExclusive,argv,SearchSpawn);
}
#endif

#ifndef ISXEQ_LEGACY

BOOL GetClosestAlert(PSPAWNINFO pChar, DWORD List)
{
    CHAR szName[MAX_STRING] = {0};
    if (!ppSpawnManager) return FALSE;
    if (!pSpawnList) return FALSE;
    PSPAWNINFO pSpawn, pClosest = FALSE;
    FLOAT ClosestDistance = 50000.0f;
	std::list<SEARCHSPAWN>ss;
    if(CAlerts.GetAlert(List,ss)) {
		for (std::list<SEARCHSPAWN>::iterator i=ss.begin();i!=ss.end();i++) {
			if (pSpawn = SearchThroughSpawns(&(*i),pChar)) {
				if (DistanceToSpawn(pChar,pSpawn)<ClosestDistance) {
					pClosest = pSpawn;
				}
			}
		}
	}
    return (pClosest!=NULL);
}

BOOL IsAlert(PSPAWNINFO pChar, PSPAWNINFO pSpawn, DWORD List)
{
    CHAR szName[MAX_STRING] = {0};
	SEARCHSPAWN SearchSpawn = {0};
	std::list<SEARCHSPAWN>ss;
    if(CAlerts.GetAlert(List,ss)) {
		for (std::list<SEARCHSPAWN>::iterator i=ss.begin();i!=ss.end();i++) {
			CopyMemory(&SearchSpawn,&(*i),sizeof(SEARCHSPAWN));
			if ((SearchSpawn.SpawnID>0) && (SearchSpawn.SpawnID!=pSpawn->SpawnID))
				continue;
        SearchSpawn.SpawnID = pSpawn->SpawnID;
        // if this spawn matches, it's true 
        // this is an implied logical or
        if (SpawnMatchesSearch(&SearchSpawn, pChar, pSpawn))
            return TRUE;
		}
    }
    return FALSE;
}

BOOL CheckAlertForRecursion(PSEARCHSPAWN pSearchSpawn,DWORD List)
{
    if (!pSearchSpawn) return FALSE;
	std::list<SEARCHSPAWN>ss;
	if(CAlerts.GetAlert(List,ss)) {
	for (std::list<SEARCHSPAWN>::iterator i = ss.begin();i!=ss.end();i++) {
        if (pSearchSpawn->bAlert) {
            if (pSearchSpawn->AlertList == List) {
                return TRUE;
            }
			if (CheckAlertForRecursion(pSearchSpawn,pSearchSpawn->AlertList)) {
				return TRUE;
            }
        }
       if (pSearchSpawn->bNoAlert) {
            if (pSearchSpawn->NoAlertList == List) {
                return TRUE;
            }
			if (CheckAlertForRecursion(pSearchSpawn,pSearchSpawn->NoAlertList)) {
				return TRUE;
            }
        }
        if (pSearchSpawn->bNearAlert) {
            if (pSearchSpawn->NearAlertList == List) {
                return TRUE;
            }
            if (CheckAlertForRecursion(pSearchSpawn,pSearchSpawn->NearAlertList)) {
				return TRUE;
            }
        }
        if (pSearchSpawn->bNotNearAlert) {
            if (pSearchSpawn->NotNearAlertList == List) {
                return TRUE;
            }
            if (CheckAlertForRecursion(pSearchSpawn,pSearchSpawn->NotNearAlertList)) {
				return TRUE;
            }
        }
    }
	}
    return FALSE;
}
// ***************************************************************************
// Function:    CleanupName
// Description: Cleans up NPC names
//              an_iksar_marauder23 = iksar marauder, an
// ***************************************************************************
PCHAR CleanupName(PCHAR szName, BOOL Article, BOOL ForWhoList)
{
    DWORD i,j=0;
    CHAR szTemp[MAX_STRING] = {0};
    for (i=0;i<strlen(szName);i++) {
        switch (szName[i]) 
        {
        case '_':
            szTemp[j++]=' ';
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
            break;
        case '#':
            if (!ForWhoList)
                break;
        default:
            szTemp[j++]=szName[i];
        }
    }
    strcpy(szName,szTemp);
    if (!Article) return szName;
    if (!strnicmp(szName,"a ",2)) {
        sprintf(szTemp, "%s, a",szName+2);
        strcpy(szName,szTemp);
    } else if (!strnicmp(szName,"an ",3)) {
        sprintf(szTemp, "%s, an",szName+3);
        strcpy(szName,szTemp);
    } else if (!strnicmp(szName,"the ",4)) {
        sprintf(szTemp, "%s, the",szName+4);
        strcpy(szName,szTemp);
    }
    return szName;
}
#endif

// ***************************************************************************
// Function:    SuperWhoDisplay
// Description: Displays our SuperWho / SuperWhoTarget
// ***************************************************************************
VOID SuperWhoDisplay(PSPAWNINFO pSpawn, DWORD Color)
{
    CHAR szName[MAX_STRING]={0};
    CHAR szMsg[MAX_STRING]={0};
    CHAR szMsgL[MAX_STRING]={0};
    CHAR szTemp[MAX_STRING]={0};
    //strcpy(szName,pSpawn->Name);
    strcpy_s(szName,pSpawn->DisplayedName);
    if (pSpawn->Type == SPAWN_PLAYER) {
        if (gFilterSWho.Lastname && strlen(pSpawn->Lastname)>0) {
            strcat(szName," ");
            strcat(szName,pSpawn->Lastname);
        }
        if (gFilterSWho.Guild && pSpawn->GuildID != 0xFFFFFFFF && pGuildList) {
            strcat(szName," <");
            char *szGuild = GetGuildByID(pSpawn->GuildID);
            strcat(szName, szGuild ? szGuild : "Unknown Guild");
            strcat(szName,">");
        }
    } else {
        //CleanupName(szName);
        if (gFilterSWho.Lastname && strlen(pSpawn->Lastname)>0) {
            strcat(szName," (");
            strcat(szName,pSpawn->Lastname);
            strcat(szName,")");
        }
    }
    CHAR GM[MAX_STRING] = {0};
    if (gFilterSWho.GM && pSpawn->GM) {
        if (pSpawn->Level >= 50) {
            strcpy(GM,"\ay*GM*\ax");
        } else if (pSpawn->Level == 20) {
            strcpy(GM,"\a-y*Guide Applicant*\ax");
        } else {
            strcpy(GM,"\a-y*Guide*\ax");
        }
    }
    szMsg[0]='\a';
    szMsg[2]=0;
    if (Color || gFilterSWho.ConColor)
    {
        switch(ConColor(pSpawn))
        {
        case CONCOLOR_WHITE:
            szMsg[1]='w';
            break;
        case CONCOLOR_YELLOW:
            szMsg[1]='y';
            break;
        case CONCOLOR_RED:
            szMsg[1]='r';
            break;
        case CONCOLOR_BLUE:
            szMsg[1]='u';
            break;
        case CONCOLOR_LIGHTBLUE:
            szMsg[1]='t';
            break;
        case CONCOLOR_GREEN:
            szMsg[1]='g';
            break;
        case CONCOLOR_GREY:
            szMsg[1]='-';
            szMsg[2]='w';
            break;
        default:
            szMsg[1]='m';
            break;
        }
    }
    else
    {
        szMsg[1]='w';
    }
    if (gFilterSWho.GM) strcat(szMsg,GM);
    if (gFilterSWho.Level || gFilterSWho.Race || gFilterSWho.Body || gFilterSWho.Class) {
        strcat(szMsg,"\a-u[\ax");
        if (gFilterSWho.Level) {
            itoa(pSpawn->Level,szTemp,10);
            strcat(szMsg,szTemp);
            strcat(szMsg," ");
        }
        if (gFilterSWho.Race) {
            strcat(szMsg,pEverQuest->GetRaceDesc(pSpawn->Race));
            strcat(szMsg," ");
        }
        if (gFilterSWho.Body) {
            strcat(szMsg,GetBodyTypeDesc(GetBodyType(pSpawn)));
            strcat(szMsg," ");
        }
        if (gFilterSWho.Class) {
            strcat(szMsg,GetClassDesc(pSpawn->Class));
            strcat(szMsg," ");
        }
        szMsg[strlen(szMsg)-1]=0;
        strcat(szMsg,"\a-u]\ax");
    }
    strcat(szMsg," ");
    strcat(szMsg,szName);
    //strcat(szMsg,"\ax");

    if (pSpawn->Type == SPAWN_PLAYER) {
        if (gFilterSWho.Anon && pSpawn->Anon>0) {
            if (pSpawn->Anon==2) {
                strcat(szMsg," \ag*RP*\ax");
            } else {
                strcat(szMsg," \ag*Anon*\ax");
            }
        }
        if (gFilterSWho.LD && pSpawn->Linkdead) strcat(szMsg," \ag<LD>\ax");
        if (gFilterSWho.Sneak && pSpawn->Sneak) strcat(szMsg," \ag<Sneak>\ax"); 
        if (gFilterSWho.AFK && pSpawn->AFK) strcat(szMsg," \ag<AFK>\ax");
        if (gFilterSWho.LFG && pSpawn->LFG) strcat(szMsg," \ag<LFG>\ax");
        if (gFilterSWho.Trader && pSpawn->Trader) strcat(szMsg," \ag<Trader>\ax");
    } else if (gFilterSWho.NPCTag && pSpawn->Type == SPAWN_NPC) {
        if (pSpawn->MasterID != 0) {
            strcat(szMsg," <PET>");
        } else {
            strcat(szMsg," <NPC>");
        }
    }
    if (gFilterSWho.Light) {
        PCHAR szLight = GetLightForSpawn(pSpawn);
        if (stricmp(szLight,"NONE")) {
            strcat(szMsg," (");
            strcat(szMsg,szLight);
            strcat(szMsg,")");
        }
    }
    strcpy(szMsgL,szMsg);
    if (gFilterSWho.Distance) 
    {
        INT Angle = (INT)((atan2f(GetCharInfo()->pSpawn->X - pSpawn->X, GetCharInfo()->pSpawn->Y - pSpawn->Y) * 180.0f / PI + 360.0f) / 22.5f + 0.5f) % 16;
        sprintf(szTemp," \a-u(\ax%1.2f %s\a-u,\ax %1.2fZ\a-u)\ax", GetDistance(GetCharInfo()->pSpawn,pSpawn), szHeadingShort[Angle], pSpawn->Z-GetCharInfo()->pSpawn->Z);
        strcat(szMsg,szTemp);
    }
    if (gFilterSWho.SpawnID) 
    {
        strcat(szMsg," \a-u(\axID:");
        itoa(pSpawn->SpawnID,szTemp,10);
        strcat(szMsg,szTemp);
        strcat(szMsg,"\a-u)\ax");
    }
    if (gFilterSWho.Holding && (pSpawn->Equipment.Primary.ID || pSpawn->Equipment.Offhand.ID )) 
    {
        strcat(szMsg," \a-u(\ax");
        if (pSpawn->Equipment.Primary.ID)
        {
            itoa(pSpawn->Equipment.Primary.ID,szTemp,10);
            strcat(szMsg,"Pri: ");
            strcat(szMsg,szTemp);
            if (pSpawn->Equipment.Offhand.ID)
                strcat(szMsg," ");
        }
        if (pSpawn->Equipment.Offhand.ID)
        {
            itoa(pSpawn->Equipment.Offhand.ID,szTemp,10);
            strcat(szMsg,"Off: ");
            strcat(szMsg,szTemp);
        }
        strcat(szMsg,"\a-u)\ax");
    }

    switch(GetSpawnType(pSpawn))
    {
    case CHEST:
        strcat(szMsg," \ar*CHEST*\ax");
        break;
    case TRAP:
        strcat(szMsg," \ar*TRAP*\ax");
        break;
    case TRIGGER:
        strcat(szMsg," \ar*TRIGGER*\ax");
        break;
    case TIMER:
        strcat(szMsg," \ar*TIMER*\ax");
        break;
    case UNTARGETABLE:
        strcat(szMsg," \ar*UNTARGETABLE*\ax");
        break;
    }

    WriteChatColor(szMsg,USERCOLOR_WHO);
}

DWORD SWhoSortValue=0;
PSPAWNINFO SWhoSortOrigin=0;
static bool pWHOSORTCompare(const PSPAWNINFO SpawnA, const PSPAWNINFO SpawnB)
{
    switch(SWhoSortValue)
    {
        /*
        PCHAR szSortBy[] = { 
        "level",   // Default sort by 
        "name", 
        "race", 
        "class", 
        "distance", 
        "guild", 
        "id", 
        NULL }; 
        /**/
    case 0://level
		return SpawnA->Level < SpawnB->Level;
    //case 1://name   done at the bottom ;)
    case 2://race
		return _stricmp(pEverQuest->GetRaceDesc(SpawnA->Race),pEverQuest->GetRaceDesc(SpawnB->Race)) < 0;
    case 3://class
		return _stricmp(GetClassDesc(SpawnA->Class),GetClassDesc(SpawnB->Class)) < 0;
    case 4://distance
		return GetDistance(SWhoSortOrigin,SpawnA) < GetDistance(SWhoSortOrigin,SpawnB);
    case 5://guild
		{
			CHAR szGuild1[128] = {""};
			CHAR szGuild2[128] = {""};
			char *pDest = 0;
			if(pDest = GetGuildByID(SpawnA->GuildID)) {
				strcpy_s(szGuild1,pDest);
			}
			if(pDest = GetGuildByID(SpawnB->GuildID)) {
				strcpy_s(szGuild2,pDest);
			}
			return _stricmp(szGuild1, szGuild2) < 0;
		}
    case 6://id
        return SpawnA->SpawnID < SpawnB->SpawnID;
    }
	/*
	CHAR szNameA[128] = {0};
	CHAR szNameB[128] = {0};
	strcpy_s(szNameA, SpawnA->Name);
	CleanupName(szNameA);
	strcpy_s(szNameB, SpawnB->Name);
	CleanupName(szNameB);
	return _stricmp(szNameA, szNameB) < 0;
	*/
	return _stricmp(SpawnA->DisplayedName, SpawnB->DisplayedName) < 0;
}

VOID SuperWhoDisplay(PSPAWNINFO pChar, PSEARCHSPAWN pSearchSpawn, DWORD Color)
{
    if (!pSearchSpawn)
        return;
    CIndex<PSPAWNINFO> SpawnSet;
    PSPAWNINFO pSpawn=(PSPAWNINFO)pSpawnList;
    PSPAWNINFO pOrigin=0;
    // create our set
    DWORD TotalMatching=0;
    if (pSearchSpawn->FromSpawnID)
        pOrigin=(PSPAWNINFO)GetSpawnByID(pSearchSpawn->FromSpawnID);
    if (!pOrigin)
        pOrigin=pChar;
    while (pSpawn)
    {
        if (SpawnMatchesSearch(pSearchSpawn,pOrigin,pSpawn))
        {
            // matches search, add to our set
            TotalMatching++;
            SpawnSet+=pSpawn;
        }
        pSpawn=pSpawn->pNext;
    }
    if (TotalMatching)
    {
        if (TotalMatching>1)
        {
            // sort our list
            SWhoSortValue=pSearchSpawn->SortBy;
            SWhoSortOrigin=pOrigin;
			std::sort(&SpawnSet.List[0], &SpawnSet.List[0]+TotalMatching, pWHOSORTCompare);
        }
        WriteChatColor("List of matching spawns",USERCOLOR_WHO);
        WriteChatColor("--------------------------------",USERCOLOR_WHO);
        for (DWORD N=0 ; N < TotalMatching ; N++)
        {
            SuperWhoDisplay(SpawnSet[N],Color);
        }
        PCHAR pszSpawnType;
        switch(pSearchSpawn->SpawnType)
        {
        case NONE:
        default:
            pszSpawnType="any";
            break;
        case PC:
            pszSpawnType="pc";
            break;
        case MOUNT:
            pszSpawnType="mount";
            break;
        case PET:
            pszSpawnType="pet";
            break;
        case PCPET:
            pszSpawnType="pcpet";
            break;
        case NPCPET:
            pszSpawnType="npcpet";
            break;
        case NPC:
            pszSpawnType="npc";
            break;
        case CORPSE:
            pszSpawnType="corpse";
            break;
        case TRIGGER:
            pszSpawnType="trigger";
            break;
        case TRAP:
            pszSpawnType="trap";
            break;
        case CHEST:
            pszSpawnType="chest";
            break;
        case TIMER:
            pszSpawnType="timer";
            break;
        case UNTARGETABLE:
            pszSpawnType="untargetable";
            break;
        case MERCENARY:
            pszSpawnType="mercenary";
            break;
        case FLYER:
            pszSpawnType="flyer";
            break;
        }
        WriteChatf("There %s \ag%d\ax %s%s in %s.",(TotalMatching == 1)?"is":"are",TotalMatching, pszSpawnType, (TotalMatching==1)?"":"s", GetFullZone(GetCharInfo()->zoneId));
    }
    else
    {
        WriteChatColor("List of matching spawns",USERCOLOR_WHO);
        WriteChatColor("--------------------------------",USERCOLOR_WHO);
        CHAR szMsg[MAX_STRING]={0};
        FormatSearchSpawn(szMsg,pSearchSpawn);
        strcat(szMsg," was not found.");
        WriteChatColor(szMsg,USERCOLOR_WHO);
    }
}

#ifndef ISXEQ_LEGACY
DWORD WINAPI thrMsgBox(LPVOID lpParameter)
{
    MessageBox(NULL,(PCHAR)lpParameter,"MacroQuest",MB_OK);
    free(lpParameter);
    return 0;
}

FLOAT StateHeightMultiplier(DWORD StandState) 
{ 
    switch (StandState) { 
case STANDSTATE_BIND: 
case STANDSTATE_DUCK: 
    return 0.5f; 
case STANDSTATE_SIT: 
    return 0.3f; 
case STANDSTATE_FEIGN: 
case STANDSTATE_DEAD: 
    return 0.1f; 
case STANDSTATE_STAND: 
default: 
    return 0.9f; 
    } 
} 
DWORD FindSpellListByName(PCHAR szName)
{
    DWORD Index;
	for (Index=0;Index<NUM_SPELL_SETS;Index++) {
        if (!_stricmp(pSpellSets[Index].Name,szName)) return Index;
    }
    return -1;
}

VOID RewriteAliases(VOID)
{
    PALIAS pLoop = pAliases;
    WritePrivateProfileSection("Aliases","",gszINIFilename);
    while (pLoop) {
        WritePrivateProfileString("Aliases",pLoop->szName,pLoop->szCommand,gszINIFilename);
        pLoop = pLoop->pNext;
    }
}

VOID RewriteSubstitutions(VOID)
{
    PSUB pSubLoop = pSubs;
    WritePrivateProfileSection("Substitutions","",gszINIFilename);
    while (pSubLoop) {
        WritePrivateProfileString("Substitutions",pSubLoop->szOrig,pSubLoop->szSub,gszINIFilename);
        pSubLoop = pSubLoop->pNext;
    }
}

PCHAR GetFriendlyNameForGroundItem(PGROUNDITEM pItem, PCHAR szName)
{
    szName[0]=0;
    DWORD Item = atoi(pItem->Name + 2);
	int zoneID = 0;
	if (PCHARINFO pCharInfo = GetCharInfo())
		zoneID = pCharInfo->zoneId;
    struct _actordefentry *ptr = MQ2Globals::ActorDefList;

    while (ptr->Def) {
		if (ptr->Def == Item && (ptr->ZoneID && (ptr->ZoneID < 0 || ptr->ZoneID == zoneID))) {
            sprintf(szName,"%s",ptr->Name);
            return &szName[0];
        }
        ptr++;
    }
    sprintf(szName,"Drop%05d/%d",Item,pItem->DropID);
	return &szName[0];
}

// deprecated
#if 0
PCHAR GetModel(PSPAWNINFO pSpawn, DWORD Slot)
{
    if (!pSpawn) return NULL;
    if (Slot>20) return NULL;
    PMODELINFO pMod = pSpawn->Model[Slot];
    if (!pMod) return NULL;
    if (!pMod->pModelInfo) return NULL;
    if (pMod->pModelInfo->Type != 0x48) return NULL;
    PMODELINFO_48 pModInfo = (PMODELINFO_48)pMod->pModelInfo;
    if (!pModInfo->pModelName) return NULL;
    PCHAR szModel = pModInfo->pModelName->Name;
    if (!szModel) return szItemName[0];
    return szItemName[atoi(szModel+2)];
}
#endif

VOID SetDisplaySWhoFilter(PBOOL bToggle, PCHAR szFilter, PCHAR szToggle)
{
    CHAR szTemp[MAX_STRING] = {0};
    if (!_stricmp(szToggle,"on")) *bToggle = TRUE;
    else if (!_stricmp(szToggle,"off")) *bToggle = FALSE;
    sprintf(szTemp,"%s is: %s",szFilter,(*bToggle)?"on":"off");
    WriteChatColor(szTemp,USERCOLOR_DEFAULT);
    itoa(*bToggle,szTemp,10);
    WritePrivateProfileString("SWho Filter",szFilter,szTemp,gszINIFilename);
}

VOID WriteFilterNames(VOID)
{
    CHAR szBuffer[MAX_STRING] = {0};
    int filternumber=1;
    PFILTER pFilter = gpFilters;
    WritePrivateProfileSection("Filter Names",szBuffer,gszINIFilename);
    while (pFilter) {
        if (pFilter->pEnabled == &gFilterCustom) {
            sprintf(szBuffer,"Filter%d",filternumber++);
            WritePrivateProfileString("Filter Names",szBuffer,pFilter->FilterText, gszINIFilename);
        }
        pFilter = pFilter->pNext;
    }

}
bool GetShortBuffID(PSPELLBUFF pBuff, DWORD &nID)
{
    PCHARINFO2 pChar=GetCharInfo2();
    unsigned long N=(pBuff-&pChar->ShortBuff[0]);
    if (N<NUM_SHORT_BUFFS)
    {
        nID=N+1;
        return true;
    }
    return false;
}
bool GetBuffID(PSPELLBUFF pBuff, DWORD &nID)
{
    PCHARINFO2 pChar=GetCharInfo2();
    unsigned long N=(pBuff-&pChar->Buff[0]);
    if (N<NUM_LONG_BUFFS)
    {
        nID=N+1;
        return true;
    }
    return false;
}

#define IS_SET(flag, bit)   ((flag) & (bit))
#define LDON_Non    0
#define LDON_DG     1
#define LDON_MIR    2
#define LDON_MIS    4
#define LDON_RUJ    8
#define LDON_TAK    16

PCHAR GetLDoNTheme(DWORD LDTheme)
{
    if (LDTheme == 31) return "All";
    if (IS_SET(LDTheme, LDON_DG )) return "Deepest Guk";
    if (IS_SET(LDTheme, LDON_MIR)) return "Miragul's";
    if (IS_SET(LDTheme, LDON_MIS)) return "Mistmoore";
    if (IS_SET(LDTheme, LDON_RUJ)) return "Rujarkian";
    if (IS_SET(LDTheme, LDON_TAK)) return "Takish";
    return "Unknown";
} 

DWORD GetItemTimer(PCONTENTS pItem)
{
    DWORD Timer=pPCData->GetItemTimerValue((EQ_Item*)&pItem);
    if(Timer<GetFastTime()) return 0;
    return Timer-GetFastTime();
}

PCONTENTS GetItemContentsBySlotID(DWORD dwSlotID)
{
    int InvSlot=-1; 
    int SubSlot=-1; 
    if(dwSlotID>=0 && dwSlotID<NUM_INV_SLOTS) InvSlot=dwSlotID; 
    else if(dwSlotID>=262 && dwSlotID<342) { 
        InvSlot=BAG_SLOT_START+(dwSlotID-262)/10; 
        SubSlot=(dwSlotID-262)%10; 
    } 
    if(InvSlot>=0 && InvSlot<NUM_INV_SLOTS) { 
        if(PCONTENTS iSlot=GetCharInfo2()->pInventoryArray->InventoryArray[InvSlot]) {
            if(SubSlot<0) return iSlot; 
            if(GetCharInfo2()->pInventoryArray->InventoryArray[InvSlot]->pContentsArray)
            if(PCONTENTS sSlot=GetCharInfo2()->pInventoryArray->InventoryArray[InvSlot]->pContentsArray->Contents[SubSlot]) return sSlot; 
        } 
    } 
    return NULL; 
}

PCONTENTS GetItemContentsByName(CHAR *ItemName)
{
    for(unsigned long nSlot=0; nSlot<NUM_INV_SLOTS; nSlot++) {
		PCHARINFO2 pChar2 = GetCharInfo2();
		if(pChar2 && pChar2->pInventoryArray && pChar2->pInventoryArray->InventoryArray) {
			if(PCONTENTS pItem=pChar2->pInventoryArray->InventoryArray[nSlot]) {
				if(!strcmp(ItemName,GetItemFromContents(pItem)->Name)) {
					return pItem;
				}
			}
		}
	}


    for (unsigned long nPack=0 ; nPack < 10 ; nPack++)
        if (PCONTENTS pPack=GetCharInfo2()->pInventoryArray->Inventory.Pack[nPack])
            if (GetItemFromContents(pPack)->Type==ITEMTYPE_PACK && pPack->pContentsArray)
                for (unsigned long nItem=0 ; nItem < GetItemFromContents(pPack)->Slots ; nItem++)
                    if (PCONTENTS pItem=pPack->pContentsArray->Contents[nItem])
                        if (!_stricmp(ItemName,GetItemFromContents(pItem)->Name)) return pItem;

    return NULL; 
}

CXWnd * GetParentWnd(class CXWnd const * pWnd)
{
    CXWnd * tWnd=(CXWnd *)pWnd;
    while (tWnd)
    {
        if (!tWnd->pParentWindow) return tWnd;
        tWnd=(CXWnd *)tWnd->pParentWindow;
    }
    return NULL;
}

bool LoH_HT_Ready() 
{
    DWORD i=((PSPAWNINFO)pLocalPlayer)->InnateETA;
    DWORD j=i-((PCDISPLAY)pDisplay)->TimeStamp;
    if(i<j) return true;
    return false;
}

DWORD GetSkillIDFromName(PCHAR name)
{
    for(DWORD i=0; i<NUM_SKILLS; i++)
        if (PSKILL pSkill=pSkillMgr->pSkill[i])
            if(!_stricmp(name,pStringTable->getString(pSkill->nName,0)))
                return i;
    return 0;
}

bool InHoverState()
{
    if(GetCharInfo() && GetCharInfo()->Stunned==3)
        return true;
    return false;
}

DWORD GetGameState(VOID)
{
    if (!ppEverQuest || !pEverQuest) 
    {
        //DebugSpew("Could not retrieve gamestate in GetGameState()");
        return -1;
    }
    return ((PEVERQUEST)pEverQuest)->GameState;
}

// ***************************************************************************
// Function:    LargerEffectTest
// Description: Return boolean true if the spell effect is to be ignored
//              for stacking purposes
// ***************************************************************************
BOOL LargerEffectTest (PSPELL aSpell, PSPELL bSpell, int i)
{
	if ((aSpell->Attrib[i]==1 && bSpell->Attrib[i]==1)				// Ac Mod
	 || (aSpell->Attrib[i]==55 && bSpell->Attrib[i]==55)			// Add Effect: Absorb Damage
	 ||	(aSpell->Attrib[i]==69 && bSpell->Attrib[i]==69)			// Max HP Mod
	 ||	(aSpell->Attrib[i]==79 && bSpell->Attrib[i]==79)			// HP Mod
	 ||	(aSpell->Attrib[i]==114 && bSpell->Attrib[i]==114)			// Aggro Multiplier
	 ||	(aSpell->Attrib[i]==127 && bSpell->Attrib[i]==127))			// Spell Haste
		return aSpell->Base[i]>=bSpell->Base[i];
	return false;
}

// ***************************************************************************
// Function:    TriggeringEffectSpell
// Description: Return boolean true if the spell effect is to be ignored
//              for stacking purposes
// ***************************************************************************
BOOL TriggeringEffectSpell (PSPELL aSpell, int i)
{
	return ((aSpell->Attrib[i]==85)		// Add Proc
		 || (aSpell->Attrib[i]==374) 	// Trigger Spell
		 || (aSpell->Attrib[i]==419));	// Contact_Ability_2
}

// ***************************************************************************
// Function:    SpellEffectTest
// Description: Return boolean true if the spell effect is to be ignored
//              for stacking purposes
// ***************************************************************************
BOOL SpellEffectTest (PSPELL aSpell, PSPELL bSpell, int i, BOOL bIgnoreTriggeringEffects)
{
	return ((aSpell->Attrib[i]==57 || bSpell->Attrib[i]==57)		// Levitate
		 || (aSpell->Attrib[i]==134 || bSpell->Attrib[i]==134)		// Limit: Max Level
		 || (aSpell->Attrib[i]==135 || bSpell->Attrib[i]==135)		// Limit: Resist
		 || (aSpell->Attrib[i]==136 || bSpell->Attrib[i]==136)		// Limit: Target
		 || (aSpell->Attrib[i]==137 || bSpell->Attrib[i]==137)		// Limit: Effect
		 || (aSpell->Attrib[i]==138 || bSpell->Attrib[i]==138)		// Limit: SpellType
		 || (aSpell->Attrib[i]==139 || bSpell->Attrib[i]==139)		// Limit: Spell
		 || (aSpell->Attrib[i]==140 || bSpell->Attrib[i]==140)		// Limit: Min Duraction
		 || (aSpell->Attrib[i]==141 || bSpell->Attrib[i]==141)		// Limit: Instant
		 || (aSpell->Attrib[i]==142 || bSpell->Attrib[i]==142)		// Limit: Min Level
		 || (aSpell->Attrib[i]==143 || bSpell->Attrib[i]==143)		// Limit: Min Cast Time
		 || (aSpell->Attrib[i]==144 || bSpell->Attrib[i]==144)		// Limit: Max Cast Time
		 || (aSpell->Attrib[i]==254 || bSpell->Attrib[i]==254)		// Placeholder
		 || (aSpell->Attrib[i]==311 || bSpell->Attrib[i]==311)		// Limit: Combat Skills not Allowed
		 || (aSpell->Attrib[i]==339 || bSpell->Attrib[i]==339)		// Trigger DoT on cast
		 || (aSpell->Attrib[i]==340 || bSpell->Attrib[i]==340)		// Trigger DD on cast
		 || (aSpell->Attrib[i]==348 || bSpell->Attrib[i]==348)		// Limit: Min Mana
		 || (aSpell->Attrib[i]==385 || bSpell->Attrib[i]==385)		// Limit: SpellGroup
		 || (aSpell->Attrib[i]==391 || bSpell->Attrib[i]==391)		// Limit: Max Mana
		 || (aSpell->Attrib[i]==403 || bSpell->Attrib[i]==403)		// Limit: SpellClass
		 || (aSpell->Attrib[i]==404 || bSpell->Attrib[i]==404)		// Limit: SpellSubclass
		 || (aSpell->Attrib[i]==411 || bSpell->Attrib[i]==411)		// Limit: PlayerClass
		 || (aSpell->Attrib[i]==412 || bSpell->Attrib[i]==412)		// Limit: Race
		 || (aSpell->Attrib[i]==414 || bSpell->Attrib[i]==414)		// Limit: CastingSkill
		 || (aSpell->Attrib[i]==422 || bSpell->Attrib[i]==422)		// Limit: Use Min
		 || (aSpell->Attrib[i]==423 || bSpell->Attrib[i]==423)		// Limit: Use Type
	     || (aSpell->Attrib[i]==428 || bSpell->Attrib[i]==428)		// Skill_Proc_Modifier
		 || (LargerEffectTest(aSpell, bSpell, i))					// Ignore if the new effect is greater than the old effect
		 || (bIgnoreTriggeringEffects && (TriggeringEffectSpell(aSpell, i) || TriggeringEffectSpell(bSpell, i)))		// Ignore triggering effects validation
		 || ((aSpell->SpellType==1 || aSpell->SpellType==2) && (bSpell->SpellType==1 || bSpell->SpellType==2) && !(aSpell->DurationWindow==bSpell->DurationWindow)));
}

// ***************************************************************************
// Function:    BuffStackTest
// Description: Return boolean true if the two spells will stack
// Usage:       Used by ${Spell[xxx].Stacks}, ${Spell[xxx].StacksPet},
//                ${Spell[xxx].WillStack[yyy]}, ${Spell[xxx].StacksWith[yyy]}
// Author:      Pinkfloydx33
// ***************************************************************************
BOOL BuffStackTest(PSPELL aSpell, PSPELL bSpell, BOOL bIgnoreTriggeringEffects)
{
    if (aSpell->ID==bSpell->ID) return true;

	//WriteChatf("aSpell->Name=%s bSpell->Name= %s", aSpell->Name, bSpell->Name);
    int i;
    for (i=0; i<=11; i++) {
        //Compare 1st Buff to 2nd. If Attrib[i]==254 its a place holder. If it is 10 it
        //can be 1 of 3 things: PH(Base=0), CHA(Base>0), Lure(Base=-6). If it is Lure or
        //Placeholder, exclude it so slots don't match up. Now Check to see if the slots
        //have equal attribute values. If the do, they don't stack.
        //WriteChatf("Slot %d: bSpell->Attrib=%d, bSpell->Base=%d, bSpell->TargetType=%d, aSpell->Attrib=%d, aSpell->Base=%d, aSpell->TargetType=%d", i, bSpell->Attrib[i], bSpell->Base[i], bSpell->TargetType, aSpell->Attrib[i], aSpell->Base[i], aSpell->TargetType);
		if (bSpell->Attrib[i]==aSpell->Attrib[i] && !(SpellEffectTest(aSpell, bSpell, i, bIgnoreTriggeringEffects))) {
			//WriteChatf("Inside IF");
			if (aSpell->Attrib[i]==55 && bSpell->Attrib[i]==55) {
				//WriteChatf("Increase Absorb Damage by %d over %d", aSpell->Base[i], bSpell->Base[i]);
				return (aSpell->Base[i]>=bSpell->Base[i]);
			}
            else if (!((bSpell->Attrib[i]==10 && (bSpell->Base[i]==-6 || bSpell->Base[i]==0)) ||
                     (aSpell->Attrib[i]==10 && (aSpell->Base[i]==-6 || aSpell->Base[i]==0)) ||
                     (bSpell->Attrib[i]==79 && bSpell->Base[i]>0 && bSpell->TargetType==6) ||
                     (aSpell->Attrib[i]==79 && aSpell->Base[i]>0 && aSpell->TargetType==6) ||
                     (bSpell->Attrib[i]==0  && bSpell->Base[i]<0) ||
                     (aSpell->Attrib[i]==0  && aSpell->Base[i]<0) ||
                     (bSpell->Attrib[i]==148 || bSpell->Attrib[i]==149) ||
                     (aSpell->Attrib[i]==148 || aSpell->Attrib[i]==149)))
					  return false;
		}
        //Check to see if second buffs blocks first buff:
        //148: Stacking: Block new spell if slot %d is effect
        //149: Stacking: Overwrite existing spell if slot %d is effect
        if ((bSpell->Attrib[i]==148) || (bSpell->Attrib[i]==149)) {
            int tmpSlot = bSpell->Calc[i]-200;                           
            int tmpAttrib = bSpell->Base[i];
            //WriteChatf("aSpell->Attrib[%d]=%d, aSpell->Base[%d]=%d, tmpAttrib=%d, tmpVal=%d", tmpSlot-1, aSpell->Attrib[tmpSlot-1], tmpSlot-1, aSpell->Base[tmpSlot-1], tmpAttrib, abs(bSpell->Max[i]));
            if (bSpell->Max[i] > 0) {
                int tmpVal = abs(bSpell->Max[i]);
                if ((aSpell->Attrib[tmpSlot-1] == tmpAttrib) && (aSpell->Base[tmpSlot-1] < tmpVal)) return false;
            } else if (aSpell->Attrib[tmpSlot-1] == tmpAttrib) return false;
        }
        //Now Check to see if the first buff blocks second buff. This is necessary 
        //because only some spells carry the Block Slot. Ex. Brells and Spiritual 
        //Vigor don't stack Brells has 1 slot total, for HP. Vigor has 4 slots, 2 
        //of which block Brells.
        if ((aSpell->Attrib[i]==148) || (aSpell->Attrib[i]==149)) {
            int tmpSlot = aSpell->Calc[i]-200;
            int tmpAttrib = aSpell->Base[i];
            //WriteChatf("bSpell->Attrib[%d]=%d, bSpell->Base[%d]=%d, tmpAttrib=%d, tmpVal=%d", tmpSlot-1, bSpell->Attrib[tmpSlot-1], tmpSlot-1, bSpell->Base[tmpSlot-1], tmpAttrib, abs(aSpell->Max[i]));
            if (aSpell->Max[i] > 0) {
                int tmpVal = abs(aSpell->Max[i]);
                if ((bSpell->Attrib[tmpSlot-1] == tmpAttrib) && (bSpell->Base[tmpSlot-1] < tmpVal)) return false;
            } else if (bSpell->Attrib[tmpSlot-1] == tmpAttrib) return false;   
        }
    }      
    return true;
} 

float GetMeleeRange(class EQPlayer *pSpawn1,class EQPlayer *pSpawn2)
{
    float f, g, h;
    if(pSpawn1 && pSpawn2)
    {
        f=((PSPAWNINFO)pSpawn1)->GetMeleeRangeVar1 * ((PSPAWNINFO)pSpawn1)->GetMeleeRangeVar2;
        g=((PSPAWNINFO)pSpawn2)->GetMeleeRangeVar1 * ((PSPAWNINFO)pSpawn2)->GetMeleeRangeVar2;

        h=abs(((PSPAWNINFO)pSpawn1)->AvatarHeight - ((PSPAWNINFO)pSpawn2)->AvatarHeight);

        f=(f+g)*0.75f;

        if(f<14.0f)
            f=14.0f;

        g=f+2+h;

        if(g>75.0f)
            return 75.0f;
        else
            return g;
    }
    return 14.0f;
}

DWORD GetSpellGemTimer(DWORD nGem)
{
    _EQCASTSPELLGEM *g = ((PEQCASTSPELLWINDOW)pCastSpellWnd)->SpellSlots[nGem];
    if(g->TimeStamp) {
        return g->TimeStamp + g->RecastTime - EQGetTime();
	}
    return 0;
}

DWORD GetSpellBuffTimer(DWORD SpellID)
{
    PEQBUFFWINDOW pbuffs = (PEQBUFFWINDOW)pBuffWnd;
	for (unsigned long nBuff=0 ; nBuff < NUM_LONG_BUFFS ; nBuff++) {
		if(pbuffs->BuffId[nBuff]==SpellID) {
			if(pbuffs->BuffTimer[nBuff]) {
				return pbuffs->BuffTimer[nBuff];
			}
		}
	}
	//look, this probably is an oversight by the eqdevs
	//but the struct only have 0x2a BuffTimers so...
	//even though there could be 0x37 shortbuffs
	// we can only check up to 0x2a...
	pbuffs = (PEQBUFFWINDOW)pSongWnd;
	for (unsigned long nBuff=0 ; nBuff < NUM_LONG_BUFFS ; nBuff++) {
		if(pbuffs->BuffId[nBuff]==SpellID) {
			if(pbuffs->BuffTimer[nBuff]) {
				return pbuffs->BuffTimer[nBuff];
			}
		}
	}
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
// Functions that were built into commands and people used DoCommand to execute                  //
void AttackRanged(EQPlayer *pRangedTarget)
{
    if (pRangedTarget && gbRangedAttackReady)
    {
        pLocalPlayer->DoAttack(0x0B,0,pRangedTarget);
        gbRangedAttackReady=0;
    }
}

void UseAbility(char *sAbility) {

    CHAR szBuffer[MAX_STRING] = {0};
    sprintf(szBuffer, "%s",sAbility);

    if (!cmdDoAbility)
    {
        PCMDLIST pCmdListOrig = (PCMDLIST)EQADDR_CMDLIST;
        for (int i=0;pCmdListOrig[i].fAddress != 0;i++) {
            if (!strcmp(pCmdListOrig[i].szName,"/doability")) {
                cmdDoAbility = (fEQCommand)pCmdListOrig[i].fAddress;
            }
        }
    }
    if (!cmdDoAbility) return;

    //if (argc<2 || atoi(argv[1]) || !EQADDR_DOABILITYLIST) {
    if (atoi(szBuffer) || !EQADDR_DOABILITYLIST) {
        cmdDoAbility((PSPAWNINFO)pLocalPlayer,szBuffer);
        return;
    }

    DWORD Index, DoIndex = 0xFFFFFFFF;
    PSPAWNINFO pChar =(PSPAWNINFO)pCharSpawn;

    for (Index=0;Index<10;Index++) {
        if (EQADDR_DOABILITYLIST[Index]!= 0xFFFFFFFF) {
            if (!strnicmp(szBuffer,szSkills[EQADDR_DOABILITYLIST[Index]],strlen(szSkills[EQADDR_DOABILITYLIST[Index]]))) {
                if (Index<4) {
                    DoIndex = Index+7; // 0-3 = Combat abilities (7-10)
                } else {
                    DoIndex = Index-3; // 4-9 = Abilities (1-6)
                }
            }
        }
    }

    if (DoIndex!=0xFFFFFFFF) {
        cmdDoAbility(pChar,itoa(DoIndex,szBuffer,10));
    } else {
        for (Index=0;Index<NUM_COMBAT_ABILITIES;Index++) {
           	if(pCombatSkillsSelectWnd->ShouldDisplayThisSkill(Index)) {
                if(PSPELL pCA = GetSpellByID(GetCharInfo2()->CombatAbilities[Index])) {
					if (!_stricmp(pCA->Name, szBuffer)) {
						//We got the cookie, let's try and do it 
						pCharData->DoCombatAbility(pCA->ID);
						break;
					}
				}
            }
        }
        if (Index >= NUM_COMBAT_ABILITIES)
            WriteChatColor("You do not seem to have that ability available",USERCOLOR_DEFAULT);
    }
    return;
}

// Function to check if the account has a given expansion enabled.
// Pass exansion macros from EQData.h to it -- e.g. HasExpansion(EXPANSION_RoF)
bool HasExpansion(DWORD nExpansion)
{
    return (bool)((GetCharInfo()->ExpansionFlags & nExpansion) != 0);
}
//Just a Function that needs more work
//I use this to test merc aa struct -eqmule
VOID ListMercAltAbilities()
{
	if(pMercAltAbilities) {
		int mercaapoints = ((PCHARINFO)pCharData)->MercAAPoints;
		for(int i=0;i<12;i++) {
			PEQMERCALTABILITIES pinfo = pMercAltAbilities;
			if(pinfo->MercAAInfo[i]) {
				if(pinfo->MercAAInfo[i]->Ptr) {
					int nName = pinfo->MercAAInfo[i]->Ptr->nName;
					int maxpoints = pinfo->MercAAInfo[i]->Max;
					if(nName) {
						CHAR szBuffer[256] = {0};
						sprintf(szBuffer,"%s",pCDBStr->GetString(nName, 37, NULL));
						WriteChatf("You have %d mercaapoints to spend on %s (max is %d)",mercaapoints,szBuffer,maxpoints);
					}
				}
			}
		}
	}
}
PCONTENTS FindItemByName(PCHAR pName, BOOL bExact)
{
	CHAR Name[MAX_STRING]={0};
	CHAR Temp[MAX_STRING]={0};
	strlwr(strcpy(Name, pName));
	PCHARINFO2 pChar2 = GetCharInfo2();
	if(pChar2 && pChar2->pInventoryArray && pChar2->pInventoryArray->InventoryArray) {
		for (unsigned long nSlot=0 ; nSlot < NUM_INV_SLOTS ; nSlot++)
		{
			if (PCONTENTS pItem=pChar2->pInventoryArray->InventoryArray[nSlot])
			{
				if (bExact)
				{
					if (!_stricmp(Name,GetItemFromContents(pItem)->Name))
					{
						return pItem;
					}
				} else {
					if(strstr(strlwr(strcpy(Temp,GetItemFromContents(pItem)->Name)),Name))
					{
						return pItem;
					}
				}
			}
		}
	}
	//check cursor
	if(pChar2 && pChar2->pInventoryArray && pChar2->pInventoryArray->Inventory.Cursor) {
		if (PCONTENTS pItem=pChar2->pInventoryArray->Inventory.Cursor) {
			if (bExact)	{
				if (!_stricmp(Name,GetItemFromContents(pItem)->Name)) {
					return pItem;
				}
			} else {
				if(strstr(strlwr(strcpy(Temp,GetItemFromContents(pItem)->Name)),Name)) {
					return pItem;
				}
			}
		}
	}
	if(pChar2 && pChar2->pInventoryArray) {
		for (unsigned long nPack=0 ; nPack < 10 ; nPack++)
		{
			if (PCONTENTS pPack=pChar2->pInventoryArray->Inventory.Pack[nPack])
			{
				if (GetItemFromContents(pPack)->Type==ITEMTYPE_PACK && pPack->pContentsArray)
				{
					for (unsigned long nItem=0 ; nItem < GetItemFromContents(pPack)->Slots ; nItem++)
					{
						if (PCONTENTS pItem=pPack->pContentsArray->Contents[nItem])
						{
							if (bExact)
							{
								if (!_stricmp(Name,GetItemFromContents(pItem)->Name))
								{
									return pItem;
								}
							} else {
								if(strstr(strlwr(strcpy(Temp,GetItemFromContents(pItem)->Name)),Name))
								{
									return pItem;
								}
							}
						}
					}
				}
			}
		}
	}
	//still not found? fine... check mount keyring
	PCHARINFO pChar = GetCharInfo();
	if(pChar && pChar->pMountArray && pChar->pMountArray->Mount) {
		for (unsigned long nSlot=0 ; nSlot < MAX_MOUNTS ; nSlot++)
		{
			if (PCONTENTS pItem=pChar->pMountArray->Mount[nSlot])
			{
				if (bExact)
				{
					if (!_stricmp(Name,GetItemFromContents(pItem)->Name))
					{
						return pItem;;
					}
				}
				else 
				{
					if(strstr(strlwr(strcpy(Temp,GetItemFromContents(pItem)->Name)),Name))
					{
						return pItem;
					}
				}
			}
		}
	}
    return 0;
}
PCONTENTS FindItemByID(DWORD ItemID)
{
	PCHARINFO2 pChar2 = GetCharInfo2();
	if(pChar2 && pChar2->pInventoryArray && pChar2->pInventoryArray->InventoryArray) {
		for (unsigned long nSlot=0 ; nSlot < NUM_INV_SLOTS ; nSlot++)
		{
			if (PCONTENTS pItem=pChar2->pInventoryArray->InventoryArray[nSlot])
			{
				if (ItemID==GetItemFromContents(pItem)->ItemNumber)
				{
					return pItem;
				}
			}
		}
	}
	//check cursor
	if(pChar2 && pChar2->pInventoryArray && pChar2->pInventoryArray->Inventory.Cursor) {
		if (PCONTENTS pItem=pChar2->pInventoryArray->Inventory.Cursor) {
			if (ItemID==GetItemFromContents(pItem)->ItemNumber)
			{
				return pItem;
			}
		}
	}
	if(pChar2 && pChar2->pInventoryArray) {
		for (unsigned long nPack=0 ; nPack < 10 ; nPack++)
		{
			if (PCONTENTS pPack=pChar2->pInventoryArray->Inventory.Pack[nPack])
			{
				if (GetItemFromContents(pPack)->Type==ITEMTYPE_PACK && pPack->pContentsArray)
				{
					for (unsigned long nItem=0 ; nItem < GetItemFromContents(pPack)->Slots ; nItem++)
					{
						if (PCONTENTS pItem=pPack->pContentsArray->Contents[nItem])
						{
							if (ItemID==GetItemFromContents(pItem)->ItemNumber) {
									return pItem;
							}
						}
					}
				}
			}
		}
	}
	PCHARINFO pChar = GetCharInfo();
	if(pChar && pChar->pMountArray && pChar->pMountArray->Mount) {
		for (unsigned long nSlot=0 ; nSlot < MAX_MOUNTS ; nSlot++)
		{
			if (PCONTENTS pItem=pChar->pMountArray->Mount[nSlot])
			{
				if (ItemID==GetItemFromContents(pItem)->ItemNumber) {
					return pItem;
				}
			}
		}
	}
    return 0;
}
PCONTENTS FindItemBySlot(WORD InvSlot, WORD BagSlot)
{
	PCHARINFO2 pChar2 = GetCharInfo2();
	//check regular inventory
	if(pChar2 && pChar2->pInventoryArray && pChar2->pInventoryArray->InventoryArray) {
		for (unsigned long nSlot=0 ; nSlot < NUM_INV_SLOTS ; nSlot++)
		{
			if (PCONTENTS pItem=pChar2->pInventoryArray->InventoryArray[nSlot])
			{
				if (pItem->ItemSlot==InvSlot && pItem->ItemSlot2==BagSlot)
				{
					return pItem;
				}
			}
		}
	}
	//not found? ok check inside bags
	if(pChar2 && pChar2->pInventoryArray) {
		for (unsigned long nPack=0 ; nPack < 10 ; nPack++)
		{
			if (PCONTENTS pPack=pChar2->pInventoryArray->Inventory.Pack[nPack])
			{
				if (GetItemFromContents(pPack)->Type==ITEMTYPE_PACK && pPack->pContentsArray)
				{
					for (unsigned long nItem=0 ; nItem < GetItemFromContents(pPack)->Slots ; nItem++)
					{
						if (PCONTENTS pItem=pPack->pContentsArray->Contents[nItem])
						{
							if (pItem->ItemSlot==InvSlot && pItem->ItemSlot2==BagSlot)	{
								return pItem;
							}
						}
					}
				}
			}
		}
	}
	//still not found? check bank
	PCHARINFO pChar = GetCharInfo();
	if(pChar && pChar->pBankArray && pChar->pBankArray->Bank) {
		for (unsigned long nSlot=0 ; nSlot < NUM_BANK_SLOTS ; nSlot++)
		{
			if (PCONTENTS pItem=pChar->pBankArray->Bank[nSlot])
			{
				if (pItem->ItemSlot==InvSlot && pItem->ItemSlot2==BagSlot)
				{
					return pItem;
				}
			}
		}
	}
	//not found? ok check inside bank bags
	if(pChar && pChar->pBankArray && pChar->pBankArray->Bank) {
		for (unsigned long nPack=0 ; nPack < NUM_BANK_SLOTS ; nPack++)
		{
			if (PCONTENTS pPack=pChar->pBankArray->Bank[nPack])
			{
				if (GetItemFromContents(pPack)->Type==ITEMTYPE_PACK && pPack->pContentsArray)
				{
					for (unsigned long nItem=0 ; nItem < GetItemFromContents(pPack)->Slots ; nItem++)
					{
						if (PCONTENTS pItem=pPack->pContentsArray->Contents[nItem])
						{
							if (pItem->ItemSlot==InvSlot && pItem->ItemSlot2==BagSlot)	{
								return pItem;
							}
						}
					}
				}
			}
		}
	}
	//what? still not found? ok fine, check shared bank
	if(pChar && pChar->pSharedBankArray && pChar->pSharedBankArray->SharedBank) {
		for (unsigned long nSlot=0 ; nSlot < NUM_SHAREDBANK_SLOTS ; nSlot++)
		{
			if (PCONTENTS pItem=pChar->pSharedBankArray->SharedBank[nSlot])
			{
				if (pItem->ItemSlot==InvSlot && pItem->ItemSlot2==BagSlot)
				{
					return pItem;
				}
			}
		}
	}
    //not found? ok check inside sharedbank bags
	if(pChar && pChar->pSharedBankArray && pChar->pSharedBankArray->SharedBank) {
		for (unsigned long nPack=0 ; nPack < NUM_SHAREDBANK_SLOTS ; nPack++)
		{
			if (PCONTENTS pPack=pChar->pSharedBankArray->SharedBank[nPack])
			{
				if (GetItemFromContents(pPack)->Type==ITEMTYPE_PACK && pPack->pContentsArray)
				{
					for (unsigned long nItem=0 ; nItem < GetItemFromContents(pPack)->Slots ; nItem++)
					{
						if (PCONTENTS pItem=pPack->pContentsArray->Contents[nItem])
						{
							if (pItem->ItemSlot==InvSlot && pItem->ItemSlot2==BagSlot)	{
								return pItem;
							}
						}
					}
				}
			}
		}
	}
    return 0;
}
PEQINVSLOT GetInvSlot(DWORD type,WORD invslot,WORD bagslot)
{
	PEQINVSLOTMGR pInvMgr=(PEQINVSLOTMGR)pInvSlotMgr;
	if(pInvMgr) {
		PEQINVSLOT pSlot = 0;
		for (DWORD i=0;i<pInvMgr->TotalSlots;i++) {
			pSlot = pInvMgr->SlotArray[i];	
			if (pSlot && pSlot->Valid && pSlot->pInvSlotWnd && pSlot->pInvSlotWnd->WindowType == type && pSlot->pInvSlotWnd->InvSlot == invslot && pSlot->pInvSlotWnd->BagSlot == bagslot) {
				CXMLData *pXMLData=((CXWnd*)pSlot->pInvSlotWnd)->GetXMLData();
				if(pXMLData) {
					CHAR szType[256] = {0};
					GetCXStr(pXMLData->ScreenID.Ptr,szType,255);
					if(!_stricmp(szType,"HB_InvSlot")) {//we dont want this, the user specified a container , not a hotbutton...
						continue;
					}
				}
				return pSlot;
			}
		}
	}
	return NULL;
}
//work in progress -eqmule
BOOL IsItemInsideContainer(PCONTENTS pItem)
{
	if(pItem && pItem->ItemSlot>=0 && pItem->ItemSlot<=NUM_INV_SLOTS) {
		PCHARINFO2 pChar2 = GetCharInfo2();
		if(pChar2 && pChar2->pInventoryArray && pChar2->pInventoryArray->InventoryArray[pItem->ItemSlot]) {
			if(PCONTENTS pItemFound = pChar2->pInventoryArray->InventoryArray[pItem->ItemSlot]) {
				if(pItemFound!=pItem) {
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}
BOOL OpenContainer(PCONTENTS pItem,bool hidden,bool flag)
{
	if(!pItem)
		return FALSE;
	if(PCONTENTS pcont = FindItemBySlot(pItem->ItemSlot)) {
		if(pcont->Open)
			return FALSE;
		if(GetItemFromContents(pcont)->Type==ITEMTYPE_PACK) {
			if(PEQINVSLOT pSlot = GetInvSlot(0,pcont->ItemSlot)) {
				if(hidden) {
					//put code to hide bag here
					//until i can figure out how to call moveitemqty
				}
				CMoveItemData To = {0};
				To.InventoryType = 0;To.Unknown0x02 = 0;
				To.InvSlot = pSlot->pInvSlotWnd->InvSlot;
				To.BagSlot = pSlot->pInvSlotWnd->BagSlot;
				To.GlobalSlot = pSlot->pInvSlotWnd->GlobalSlot;
				To.RandomNum = pSlot->pInvSlotWnd->RandomNum;
				To.Selection = (long)pcont;
				pContainerMgr->OpenContainer((EQ_Container*)&pcont,(int)&To,flag);
				//pPCData->AlertInventoryChanged();
				if (pcont->Open) {
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}
BOOL CloseContainer(PCONTENTS pItem)
{
	if(!pItem)
		return FALSE;
	if(PCONTENTS pcont = FindItemBySlot(pItem->ItemSlot)) {
		if (!pcont->Open)
			return FALSE;
		if(GetItemFromContents(pcont)->Type==ITEMTYPE_PACK) {
			pContainerMgr->CloseContainer((EQ_Container*)&pcont,1);
			if (!pcont->Open) {
				return TRUE;
			}
		}
	}
	return FALSE;
}
//WaitForBagToOpen code by eqmule 2014
DWORD __stdcall WaitForBagToOpen(PVOID pData)
{
	PLARGE_INTEGER i64tmp = (PLARGE_INTEGER)pData;
	DWORD type = i64tmp->LowPart;
	PCONTENTS pItem = (PCONTENTS)i64tmp->HighPart;
	int timeout = 0;
	if(PCONTENTS pcont = FindItemBySlot(pItem->ItemSlot)) {
		//((EQ_Item*)pcont)-
		if(CInvSlot * theslot = pInvSlotMgr->FindInvSlot(pItem->ItemSlot)) {
			if(((PEQINVSLOT)theslot)->pInvSlotWnd) {
				while(!((PEQINVSLOT)theslot)->pInvSlotWnd->Wnd.dShow) {
					Sleep(10);
					timeout+=100;
					if(timeout>=1000) {
						break;
					}
				}
			}
		}
		//this is most likely completely useless
		//since the bag will actually always be open at this point
		//how can i check if the item is in the slot?
		//need to look into this further
		//get the texture maybe? -eqmule
		/*while(!pcont->Open) {
			Sleep(10);
			timeout+=100;
			if(timeout>=1000) {
				break;
			}
		}*/
	}
	Sleep(100);
	bool Old=((PCXWNDMGR)pWndMgr)->KeyboardFlags[1];
    ((PCXWNDMGR)pWndMgr)->KeyboardFlags[1]=1;
	PickupOrDropItem(type,pItem);
    ((PCXWNDMGR)pWndMgr)->KeyboardFlags[1]=Old;
	LocalFree(pData);
	//CloseContainer(pItem);
	return 1;
}
BOOL PickupOrDropItem(DWORD type, PCONTENTS pItem)
{
	//check if merchantwindow is open
	//if it is do some magic and open the bag so we can get the pslot
	if(!pItem)
		return FALSE;
	PEQINVSLOTMGR pInvMgr  = (PEQINVSLOTMGR)pInvSlotMgr;
	WORD InvSlot = pItem->ItemSlot,BagSlot = 0xFFFF;
	BOOL itsinsideapack = 0;
	if(IsItemInsideContainer(pItem)) {
		itsinsideapack = 1;
		if (pInvSlotMgr && pMerchantWnd && pMerchantWnd->dShow) {
			OpenContainer(pItem,true);
			if(CInvSlot * theslot = pInvSlotMgr->FindInvSlot(pItem->ItemSlot,pItem->ItemSlot2)) {
				PEQINVSLOT cSlot = (PEQINVSLOT)theslot;
				//ok so here is how this works:
				//we select the slot, and thet will set pSelectedItem correctly
				//we do this cause later on we need that address for the .Selection member
				//
				pInvSlotMgr->SelectSlot(theslot);
				//int imagenum = ((EQ_Item*)pItem)->GetImageNum();
				//CTextureAnimation *TextureAnim = pIconCache->GetIcon(imagenum);
				CMoveItemData To = {0};
				To.InventoryType = 0;To.Unknown0x02 = 0;
				To.InvSlot = cSlot->pInvSlotWnd->InvSlot;
				To.BagSlot = cSlot->pInvSlotWnd->BagSlot;
				To.GlobalSlot = cSlot->pInvSlotWnd->GlobalSlot;
				To.RandomNum = cSlot->pInvSlotWnd->RandomNum;
				To.Selection = (long)((PEQINVSLOTMGR)pInvSlotMgr)->pSelectedItem;
				pMerchantWnd->ActualSelect(&To);
				return TRUE;
			}
			WriteChatf("[PickupOrDropItem]no invslot found");
			return FALSE;
		}
		BagSlot = pItem->ItemSlot2;
	} else {
		if (pInvSlotMgr && pMerchantWnd && pMerchantWnd->dShow) {
			if(CInvSlot * theslot = pInvSlotMgr->FindInvSlot(pItem->ItemSlot)) {
				PEQINVSLOT cSlot = (PEQINVSLOT)theslot;
				pInvSlotMgr->SelectSlot(theslot);
				CMoveItemData To = {0};
				To.InventoryType = 0;To.Unknown0x02 = 0;
				To.InvSlot = cSlot->pInvSlotWnd->InvSlot;
				To.BagSlot = cSlot->pInvSlotWnd->BagSlot;
				To.GlobalSlot = cSlot->pInvSlotWnd->GlobalSlot;
				To.RandomNum = cSlot->pInvSlotWnd->RandomNum;
				To.Selection = (long)((PEQINVSLOTMGR)pInvSlotMgr)->pSelectedItem;
				pMerchantWnd->ActualSelect(&To);
				return TRUE;
			}
			WriteChatf("Invslot %d not found",InvSlot);
			return FALSE;
		}
	}
	BOOL bMoveFromCursor = 0;
	PCHARINFO2 pChar2 = GetCharInfo2();
	if(pChar2 && pChar2->pInventoryArray && pChar2->pInventoryArray->Inventory.Cursor) {
		bMoveFromCursor=1;
	}
	PEQINVSLOT pSlot = GetInvSlot(type,InvSlot);
	if(!pSlot || !pSlot->pInvSlotWnd) {
		//if we got all the way here this really shouldnt happen... but why assume...
		WriteChatf("Could not find an item in slot %d",InvSlot);
		return FALSE;
	}
	if(!bMoveFromCursor) {//user is picking up something
		CMoveItemData From = {0};
		From.InventoryType = (WORD)type;
		From.Unknown0x02 = 0;
		From.InvSlot = InvSlot;
		From.BagSlot = BagSlot;
		From.GlobalSlot = pSlot->pInvSlotWnd->GlobalSlot;
		From.RandomNum = pSlot->pInvSlotWnd->RandomNum;
	
		CMoveItemData To = {0};
		To.InventoryType = 0;
		To.Unknown0x02 = 0;
		To.InvSlot = 33;//cursor
		To.BagSlot = 0xFFFF;
		To.GlobalSlot = 0xFFFF;
		if(((EQ_Item *)pItem)->IsStackable()) {
			To.RandomNum = From.RandomNum-0xc;//I *THINK* this is correct, want to get dkaa to look at assembly and confirm... -eqmule
		} else {
			To.RandomNum = 0;
		}
		//OpenContainer(pItem,0);
		//if(CInvSlot *newslot = pInvSlotMgr->FindInvSlot(InvSlot,BagSlot)) {
		//	pQuantityWnd->Open((CXWnd *)((PEQINVSLOT)newslot)->pInvSlotWnd,3,pItem->StackCount,
		//		0x34F,0x14A,1,0,0);
		//}
		DWORD keybflag = pWndMgr->GetKeyboardFlags();
/*							   shr     eax, 1
.text:0069E9D1                 and     al, 1
.text:0069E9D3                 mov     [esp+1Ch], al
.text:0069E9D7                 mov     ecx, [esp+1Ch]
.text:0069E9DB                 push    ecx
*/
		if(keybflag==2 && To.RandomNum && pItem->StackCount>1) {//ctrl was pressed and it is a stackable item
			//until i figure out how to call moveitemqty
			//I need to open the bag and notify it cause moveitem only picks up full stacks
			BOOL wechangedpackopenstatus = 0;
			if(itsinsideapack) {
				wechangedpackopenstatus = OpenContainer(pItem,true);
				if(wechangedpackopenstatus) {
					if(PLARGE_INTEGER i64tmp = (PLARGE_INTEGER)LocalAlloc(LPTR,sizeof(LARGE_INTEGER))) {
						i64tmp->LowPart = type;
						i64tmp->HighPart = (LONG)pItem;
						DWORD nThreadId = 0;
						CreateThread(NULL,0,WaitForBagToOpen,i64tmp,0,&nThreadId);
						return FALSE;
					}
				}
				pSlot = (PEQINVSLOT)pInvSlotMgr->FindInvSlot(pItem->ItemSlot,pItem->ItemSlot2);
			}
			if (!pSlot || !pSlot->pInvSlotWnd || !SendWndClick2((CXWnd*)pSlot->pInvSlotWnd,"leftmouseup"))
			{
				WriteChatf("[PickupOrDropItem] falied");
				return FALSE;
			}
			//thread this? hmm if i close it before item ends up on cursor, it wont...
			//if(wechangedpackopenstatus)
			//	CloseContainer(pItem);
		} else {
			pInvSlotMgr->MoveItem(&From,&To,1,1,0,0);
			//pPCData->AlertInventoryChanged();
		}
		return TRUE;
	} else {
		//user has something on the cursor, lets drop it
		CMoveItemData From = {0};
		From.InventoryType = 0;
		From.Unknown0x02 = 0;
		From.InvSlot = 33;//cursor
		From.BagSlot = 0xFFFF;
		From.GlobalSlot = 0xFFFF;
		From.RandomNum = 0;

		CMoveItemData To = {0};
		To.InventoryType = (WORD)type;
		To.Unknown0x02 = 0;
		To.InvSlot = InvSlot;
		To.BagSlot = BagSlot;
		To.GlobalSlot = pSlot->pInvSlotWnd->GlobalSlot;
		To.RandomNum = pSlot->pInvSlotWnd->RandomNum;
		pInvSlotMgr->MoveItem(&From,&To,1,1,0,0);
		return TRUE;
		//need to update cursor here
		//pPCData->AlertInventoryChanged();
		/*if(pCharSpawn) {
			DoCommand((PSPAWNINFO)pCharSpawn,"/autoinventory");
			return TRUE;
		}*/
	}
	return FALSE;
}
int GetTargetBuffBySubCat(PCHAR subcat,DWORD classmask)
{
	if(!(((PCTARGETWND)pTargetWnd)->Type > 0))
		return false;
	int buffID = 0;
	for(int i = 0; i < NUM_BUFF_SLOTS; i++)
	{
		buffID = ((PCTARGETWND)pTargetWnd)->BuffSpellID[i];
		if(buffID > 0) {
			if(PSPELL pSpell = GetSpellByID(buffID)) {
				if(DWORD cat = pSpell->Subcategory) {
					if (char *ptr = pCDBStr->GetString(cat, 5, NULL)) {
						if(!_stricmp(ptr,subcat))  
						{
							if(classmask!=Unknown) {
								for (int N = 0 ; N < 16 ; N++)
								{
									if (classmask & (1<<N)) {
										if(pSpell->ClassLevel[N]==255) {
											continue;
										} else {
											return i;
										}
									}
								}	
							} else {
								return i;//Dest.DWord = ((((PCTARGETWND)pTargetWnd)->BuffTimer[i] / 1000) + 6)/6;
							}
						}
					}
				}
			}
		}
	}
	return -1;
}
//Usage: The spa is the spellaffect id, for example 11 for Melee Speed
//       the bIncrease tells the function if we want spells that increase or decrease the SPA
int GetTargetBuffBySPA(int spa,bool bIncrease)
{
	if(!(((PCTARGETWND)pTargetWnd)->Type > 0))
		return false;
	int buffID = 0;
	for(int i = 0; i < NUM_BUFF_SLOTS; i++)
	{
		buffID = ((PCTARGETWND)pTargetWnd)->BuffSpellID[i];
		if(buffID > 0 && buffID!=-1) {
			if(PSPELL pSpell = GetSpellByID(buffID)) {
				if (LONG base = ((EQ_Spell *)pSpell)->GetSpellBaseByAttrib(spa)) {
					//int test = ((CharacterZoneClient*)pCharData1)->CalcAffectChange((EQ_Spell*)pSpell,0,0,NULL,1,1);
					if(spa==11)//Melee Speed
					{
						if(!bIncrease && base<100) {//below 100 means its a slow above its haste...
							return i;
						} else if(bIncrease && base>100) {
							return i;
						}
						return -1;
					} else if(spa==3) { //Movement Rate
						if(!bIncrease && base<0) {//below 0 means its a snare above its runspeed increase...
							return i;
						} else if(bIncrease && base>0) {
							return i;
						}
						return -1;
					} else if(spa==59) { //Damage Shield
						if(!bIncrease && base>0) {//decreased DS
							return i;
						} else if(bIncrease && base<0) {//increased DS
							return i;
						}
						return -1;
					} else if(spa==121) { //Reverse Damage Shield
						if(!bIncrease && base>0) {//decreased DS
							return i;
						} else if(bIncrease && base<0) {//increased DS
							return i;
						}
						return -1;
					}
					return i;
				}
			}
		}
	}
	return -1;
}
int GetSelfBuffBySPA(int spa,bool bIncrease)
{
	for (unsigned long nBuff=0 ; nBuff < NUM_LONG_BUFFS ; nBuff++)
    {
        if (PSPELL pSpell=GetSpellByID(GetCharInfo2()->Buff[nBuff].SpellID))
        {
            if (LONG base = ((EQ_Spell *)pSpell)->GetSpellBaseByAttrib(spa)) {
				if(spa==11)//Melee Speed
				{
					if(!bIncrease && base<100) {//below 100 means its a slow above its haste...
						return nBuff;
					} else if(bIncrease && base>100) {
						return nBuff;
					}
					return -1;
				} else if(spa==3) {//Movement Rate
					if(!bIncrease && base<0) {//below 0 means its a snare above its runspeed increase...
						return nBuff;
					} else if(bIncrease && base>0) {
						return nBuff;
					}
					return -1;
				} else if(spa==59) { //Damage Shield
						if(!bIncrease && base>0) {//decreased DS
							return nBuff;
						} else if(bIncrease && base<0) {//increased DS
							return nBuff;
						}
						return -1;
					} else if(spa==121) { //Reverse Damage Shield
						if(!bIncrease && base>0) {//decreased DS
							return nBuff;
						} else if(bIncrease && base<0) {//increased DS
							return nBuff;
						}
						return -1;
					}
				return nBuff;
			}
        }
    }
	return -1;
}

DWORD GetSpellRankByName(PCHAR SpellName)
{
	char szTemp[256];
	strcpy_s(szTemp, SpellName);
	_strupr(szTemp);
	if (endsWith(szTemp, " II"))
		return 2;
	else if (endsWith(szTemp, " III"))
		return 3;
	else if (endsWith(szTemp, " IV"))
		return 4;
	else if (endsWith(szTemp, " V"))
		return 5;
	else if (endsWith(szTemp, " VI"))
		return 6;
	else if (endsWith(szTemp, " VII"))
		return 7;
	else if (endsWith(szTemp, " VIII"))
		return 8;
	else if (endsWith(szTemp, " IX"))
		return 9;
	else if (endsWith(szTemp, " X"))
		return 10;
	else if (endsWith(szTemp, " XI"))
		return 11;
	else if (endsWith(szTemp, " XII"))
		return 12;
	else if (endsWith(szTemp, " XIII"))
		return 13;
	else if (endsWith(szTemp, " XIV"))
		return 14;
	else if (endsWith(szTemp, " XV"))
		return 15;
	else if (endsWith(szTemp, " XVI"))
		return 16;
	else if (endsWith(szTemp, " XVII"))
		return 17;
	else if (endsWith(szTemp, " XVIII"))
		return 18;
	else if (endsWith(szTemp, " XIX"))
		return 19;
	else if (endsWith(szTemp, " XX"))
		return 20;
	else if (endsWith(szTemp, " XXI"))
		return 21;
	else if (endsWith(szTemp, " XXII"))
		return 22;
	else if (endsWith(szTemp, " XXIII"))
		return 23;
	else if (endsWith(szTemp, " XXIV"))
		return 24;
	else if (endsWith(szTemp, " XXV"))
		return 25;
	else if (endsWith(szTemp, " XXVI"))
		return 26;
	else if (endsWith(szTemp, " XXVII"))
		return 27;
	else if (endsWith(szTemp, " XXVIII"))
		return 28;
	else if (endsWith(szTemp, " XXIX"))
		return 29;
	else if (endsWith(szTemp, " XXX"))
		return 30;
	else if (endsWith(szTemp, ".II"))
		return 2;
	else if (endsWith(szTemp, ".III"))
		return 3;
	return 0;
}

VOID RemoveBuff(PSPAWNINFO pChar, PCHAR szLine)
{
	if(szLine && szLine[0]!='\0') {
		if(PCHARINFO2 pChar2 = GetCharInfo2()) {
			for (unsigned long nBuff=0 ; nBuff<NUM_LONG_BUFFS ; nBuff++)
			{
				if(pChar2->Buff[nBuff].SpellID==0 || pChar2->Buff[nBuff].SpellID==-1)
					continue;
				if(PSPELL pBuffSpell = GetSpellByID(pChar2->Buff[nBuff].SpellID)) {
					if(!strnicmp(pBuffSpell->Name,szLine,strlen(szLine))) {
						pPCData->RemoveMyAffect(nBuff);
						return;
					}
				}
			}
			for (unsigned long nBuff=0 ; nBuff<NUM_SHORT_BUFFS ; nBuff++)
			{
				if(pChar2->ShortBuff[nBuff].SpellID==0 || pChar2->ShortBuff[nBuff].SpellID==-1)
					continue;
				if(PSPELL pBuffSpell = GetSpellByID(pChar2->ShortBuff[nBuff].SpellID)) {
					if(!strnicmp(pBuffSpell->Name,szLine,strlen(szLine))) {
						pPCData->RemoveMyAffect(nBuff+NUM_LONG_BUFFS);
						return;
					}
				}
			}
		}
	}
}

VOID RemovePetBuff(PSPAWNINFO pChar, PCHAR szLine)
{
	if(PEQPETINFOWINDOW pPetInfoWindow = ((PEQPETINFOWINDOW)pPetInfoWnd)) {
		if(szLine && szLine[0]!='\0') {
			for (unsigned long nBuff=0 ; nBuff < NUM_BUFF_SLOTS ; nBuff++) {
				if (PSPELL pBuffSpell=GetSpellByID(pPetInfoWindow->Buff[nBuff])) {
					if(!strnicmp(pBuffSpell->Name,szLine,strlen(szLine))) {
						((PcZoneClient*)pPCData)->RemovePetEffect(nBuff);
						return;
					}
				}
			}
		}
	}
}

DWORD __stdcall RefreshMountKeyRingThread(PVOID pData)
{
	pkrdata kr = (pkrdata)pData;
	if(kr) {
		CXWnd *krwnd = kr->phWnd;
		bool bExact = kr->bExact;
		bool bUseCmd = kr->bUseCmd;
		CHAR szItemName[256] = {0};
		strcpy_s(szItemName,kr->ItemName);
		LocalFree(kr);
		if(krwnd) {
			bool bToggled = 0;
			if(!krwnd->dShow) {
				bToggled = true;
				DWORD ShowWindow = (DWORD)krwnd->pvfTable->ShowWindow;
				__asm {
					push ecx;
					mov ecx, [krwnd];
					call dword ptr [ShowWindow];
					pop ecx;
				}
				((CSidlScreenWnd*)krwnd)->StoreIniVis();
			}
			if(CTabWnd *pTab = (CTabWnd*)((CSidlScreenWnd*)(krwnd))->GetChildItem("IW_Subwindows")) {
				pTab->SetPage(6,true, true);//tab 6 is the mount key ring tab...
				WeDidStuff();
			}
			if(CListWnd *clist = (CListWnd*)krwnd->GetChildItem("IW_Mounts_MountList")) {
				ULONGLONG now = MQGetTickCount64();
				while(!((CSidlScreenWnd*)clist)->Items) {
					Sleep(10);
					if(now+5000 < MQGetTickCount64()) {
						WriteChatColor("Timed out waiting for mount keyring refresh",CONCOLOR_YELLOW);
						break;
					}				
				}
				if(bToggled) {
					((CXWnd*)krwnd)->Show(0,1);
					((CSidlScreenWnd*)krwnd)->StoreIniVis();
				}
#ifndef ISXEQ
				if(bUseCmd && ((CSidlScreenWnd*)clist)->Items) {
					UseItemCmd(GetCharInfo()->pSpawn,szItemName);
				}
#endif
			}
		}
	}
	return 0;
}

void RefreshMountKeyRing(PVOID kr)
{
	DWORD nThread = 0;
	CreateThread(NULL,0,RefreshMountKeyRingThread,kr,NULL,&nThread);
}
int GetMountCount()
{
	int Count = 0;
	PCHARINFO pChar = GetCharInfo();
	if(pChar && pChar->pMountArray && pChar->pMountArray->Mount) {
		for (unsigned long nSlot=0 ; nSlot < MAX_MOUNTS ; nSlot++)
		{
			if (PCONTENTS pItem=pChar->pMountArray->Mount[nSlot])
			{
				Count++;
			}
		}
	}
	return Count;
}
DWORD GetMountKeyRingIndex(char *szItemName, bool bExact, bool usecmd)
{
	DWORD index = 0;
	if(CXWnd *krwnd = FindMQ2Window("InventoryWindow")) {
		if(CListWnd *clist = (CListWnd*)krwnd->GetChildItem("IW_Mounts_MountList")) {
			if(DWORD numitems = ((CSidlScreenWnd*)clist)->Items) {
				for(DWORD i = 0;i<numitems;i++) {
					CXStr Str;
					clist->GetItemText(&Str, i, 2);
					CHAR szOut[255] = {0};
					GetCXStr(Str.Ptr,szOut,254);
					if(szOut[0]!='\0') {
						if(bExact) {
							if(!_stricmp(szItemName,szOut)) {
								index = i+1;
								break;
							}
						} else {
							_strlwr(szItemName);
							_strlwr(szOut);
							if(strstr(szOut,szItemName)) {
								index = i+1;
								break;
							}
						}
					}
				}
			} else {
				if(PCONTENTS pCont = FindItemByName(szItemName,bExact)) {
					if(pCont->IsMountKeyRing==0x1b) {
						//if the mountlist has 0 items in it, we arrive here...
						//its not filled in until you open the mount keyring tab in the inventory window...
						//since numitems was 0, we know the user hasnt opened up his inventory
						//and been on the mount key ring tab...so we start a thread and force that... -eqmule
						if(pkrdata kr = (pkrdata)LocalAlloc(LPTR,sizeof(krdata))) {
							kr->bExact =bExact;
							strcpy_s(kr->ItemName,szItemName);
							kr->phWnd = krwnd;
							kr->bUseCmd = usecmd;
							RefreshMountKeyRing(kr);
						}
					}
				}
			}
		}
	}
	return index;
}

bool StripQuotes(char *str)
{
	bool bRet = false;
	if(strchr(str,'"'))
		bRet = true;
	char *s,*d;
	for (s=d=str;*d=*s;d+=(*s++!='"'));
    return bRet;
}

void InitMountKeyRing()
{
	if(int mountcount = GetMountCount()) {
		//ok it seems like the player has mounts in his keyring
		//lets make sure we initialize it for the Mount TLO
		if(CXWnd *krwnd = FindMQ2Window("InventoryWindow")) {
			if(CListWnd *clist = (CListWnd*)krwnd->GetChildItem("IW_Mounts_MountList")) {
				if(!((CSidlScreenWnd*)clist)->Items) {
					//WriteChatColor("Mount key ring initialized",CONCOLOR_YELLOW);
					if(pkrdata kr = (pkrdata)LocalAlloc(LPTR,sizeof(krdata))) {
						kr->phWnd = krwnd;
						RefreshMountKeyRing(kr);
					}
				}
			}
		}
	}
}
//.text:00638049                 mov     ecx, pinstPCData_x
//.text:0063804F                 push    0
//.text:00638051                 push    0
//.text:00638053                 add     ecx, 1FE0h
//.text:00638059                 call    ?MakeMeVisible@CharacterZoneClient@@QAEXH_N@Z ; CharacterZoneClient::MakeMeVisible(int,bool)
VOID MakeMeVisible(PSPAWNINFO pChar, PCHAR szLine)
{
	((CharacterZoneClient*)pCharData1)->MakeMeVisible(0,0);
}
// ***************************************************************************
// Function:    RemoveAura
// Description: Removes auras
// Usage:       /removeaura <name> or <partial name>
// Author:      EqMule
// ***************************************************************************
VOID RemoveAura(PSPAWNINFO pChar,PCHAR szLine)
{
	if(!pAuraWnd)
		return;
	if(!szLine || (szLine && szLine[0]=='\0')) {
		WriteChatColor("Usage: /removeaura <auraname> or <aurapartialname>",CONCOLOR_LIGHTBLUE);
		return;
	}
	CHAR szOut[255] = {0};
	CHAR szCmp[255] = {0};
	strcpy_s(szCmp,szLine);
	CXStr Str;
	if(CListWnd*clist = (CListWnd*)pAuraWnd->GetChildItem("AuraList")) {
		for(DWORD i=0;i<clist->Items;i++) {
			clist->GetItemText(&Str, i, 1);
			GetCXStr(Str.Ptr,szOut,254);
			if(szOut[0]!='\0') {
				_strlwr_s(szOut);
				_strlwr_s(szCmp);
				if(strstr(szOut,szCmp)) {
					clist->SetCurSel(i);
					((CXWnd*)pAuraWnd)->WndNotification((CXWnd*)clist,XWM_MENUSELECT,(PVOID)1);
				}
			}
		}
	}
}

BOOL GetAllMercDesc(std::map<DWORD,MercDesc>&minfo)
{
	if(!pMercInfo)
		return FALSE;
	if(PMERCSLIST pmlist = pMercInfo->pMercsList) {
		std::string smdesc,Race,Type,Confidence,Proficiency;
		size_t pos = smdesc.npos;
		DWORD mdesc = 0;
		for(DWORD i = 0;i<pMercInfo->MercenaryCount;i++) {
			mdesc = pmlist->mercinfo[i].nMercDesc;
			smdesc = pCDBStr->GetString(mdesc,0x17,NULL);
			if((pos = smdesc.find("Race: "))!=smdesc.npos) {
				Race = smdesc.substr(pos+6);
				if((pos = Race.find("<br>"))!=Race.npos) {
					Race.erase(pos);
				}
			}
			if((pos = smdesc.find("Type: "))!=smdesc.npos) {
				Type = smdesc.substr(pos+6);
				if((pos = Type.find("<br>"))!=Type.npos) {
					Type.erase(pos);
				}
			}
			if((pos = smdesc.find("Confidence: "))!=smdesc.npos) {
				Confidence = smdesc.substr(pos+12);
				if((pos = Confidence.find("<br>"))!=Confidence.npos) {
					Confidence.erase(pos);
				}
			}
			if((pos = smdesc.find("Proficiency: "))!=smdesc.npos) {
				Proficiency = smdesc.substr(pos+13);
				if((pos = Proficiency.find("<br>"))!=Proficiency.npos) {
					Proficiency.erase(pos);
				}
			}
			minfo[i].Confidence = Confidence;
			minfo[i].Proficiency = Proficiency;
			minfo[i].Race = Race;
			minfo[i].Type = Type;
			//WriteChatf("[%d] %s - %s %s",i,Race.c_str(),Type.c_str(),Proficiency.c_str());
		}
	}
	return TRUE;
}
BOOL IsActiveAA(PCHAR pSpellName)
{
	for (DWORD nAbility=0 ; nAbility<AA_CHAR_MAX_REAL ; nAbility++) {
        if (PALTABILITY pAbility=pAltAdvManager->GetAAById(pPCData->GetAlternateAbilityId(nAbility))) {
            if(!_stricmp(pSpellName,pCDBStr->GetString(pAbility->nName, 1, NULL))) {
				if(pAbility->SpellID!=0xFFFFFFFF) {
					return TRUE;
				}
			}
        } 
    }
	return FALSE;
}
CXWnd *GetAdvLootPersonalListItem(DWORD id,DWORD type)
{
	if (CListWnd *clist = (CListWnd *)pAdvancedLootWnd->GetChildItem("ADLW_PLLList")) {
		PCSIDLWND pFirstWnd = clist->pFirstChildWnd;
		PCSIDLWND pNextWnd = pFirstWnd;
		PPersonal_Loot pPAdvLoot = new Personal_Loot;

		for (DWORD i = 0; i < clist->Items; i++) {
			if(pNextWnd) {
				pPAdvLoot->NPC_Name = (CButtonWnd *)pNextWnd->pFirstChildWnd;
				pNextWnd = pNextWnd->pNextSiblingWnd;
				pPAdvLoot->Item = (CButtonWnd *)pNextWnd->pFirstChildWnd;			
				pNextWnd = pNextWnd->pNextSiblingWnd;
				pPAdvLoot->Loot = (CButtonWnd *)pNextWnd->pFirstChildWnd;	
				pNextWnd = pNextWnd->pNextSiblingWnd;
				pPAdvLoot->Leave = (CButtonWnd *)pNextWnd->pFirstChildWnd;
				pNextWnd = pNextWnd->pNextSiblingWnd;
				pPAdvLoot->Never = (CButtonWnd *)pNextWnd->pFirstChildWnd;
				pNextWnd = pNextWnd->pNextSiblingWnd;
				pPAdvLoot->AN = (CButtonWnd *)pNextWnd->pFirstChildWnd;
				pNextWnd = pNextWnd->pNextSiblingWnd;
				pPAdvLoot->AG = (CButtonWnd *)pNextWnd->pFirstChildWnd;
				if (pNextWnd && pNextWnd->pNextSiblingWnd) {
					pNextWnd = pNextWnd->pNextSiblingWnd;
				}
				if(id==clist->GetItemData(i)) {
					CXWnd *ptr = 0;
					switch(type)
					{
					case 0:
						ptr = (CXWnd*)pPAdvLoot->NPC_Name;
						break;
					case 1:
						ptr = (CXWnd*)pPAdvLoot->Item;
						break;
					case 2:
						ptr = (CXWnd*)pPAdvLoot->Loot;
						break;
					case 3:
						ptr = (CXWnd*)pPAdvLoot->Leave;
						break;
					case 4:
						ptr = (CXWnd*)pPAdvLoot->Never;
						break;
					case 5:
						ptr = (CXWnd*)pPAdvLoot->AN;
						break;
					case 6:
						ptr = (CXWnd*)pPAdvLoot->AG;
						break;
					}
					delete pPAdvLoot;
					return ptr;
				}
			}
		}
	}
	return NULL;
}
CXWnd *GetAdvLootSharedListItem(DWORD id,DWORD type)
{
	if (CListWnd *clist = (CListWnd *)pAdvancedLootWnd->GetChildItem("ADLW_CLLList")) {
		PCSIDLWND pFirstWnd = clist->pFirstChildWnd;
		PCSIDLWND pNextWnd = pFirstWnd;
		PShared_Loot pSAdvLoot = new Shared_Loot;

		for (DWORD i = 0; i < clist->Items; i++) {
			if(pNextWnd) {
				pSAdvLoot->NPC_Name = (CButtonWnd *)pNextWnd->pFirstChildWnd;
				pNextWnd = pNextWnd->pNextSiblingWnd;
				pSAdvLoot->Item = (CButtonWnd *)pNextWnd->pFirstChildWnd;	
				pNextWnd = pNextWnd->pNextSiblingWnd;
				pSAdvLoot->Status = (CButtonWnd *)pNextWnd->pFirstChildWnd;
				pNextWnd = pNextWnd->pNextSiblingWnd;
				pSAdvLoot->Action = (CButtonWnd *)pNextWnd->pFirstChildWnd;
				pNextWnd = pNextWnd->pNextSiblingWnd;
				pSAdvLoot->Manage = (CButtonWnd *)pNextWnd->pFirstChildWnd;
				pNextWnd = pNextWnd->pNextSiblingWnd;
				pSAdvLoot->AN = (CButtonWnd *)pNextWnd->pFirstChildWnd;
				pNextWnd = pNextWnd->pNextSiblingWnd;
				pSAdvLoot->AG = (CButtonWnd *)pNextWnd->pFirstChildWnd;
				pNextWnd = pNextWnd->pNextSiblingWnd;
				pSAdvLoot->AutoRoll = (CButtonWnd *)pNextWnd->pFirstChildWnd;
				pNextWnd = pNextWnd->pNextSiblingWnd;
				pSAdvLoot->NV = (CButtonWnd *)pNextWnd->pFirstChildWnd;
				pNextWnd = pNextWnd->pNextSiblingWnd;
				pSAdvLoot->ND = (CButtonWnd *)pNextWnd->pFirstChildWnd;
				pNextWnd = pNextWnd->pNextSiblingWnd;
				pSAdvLoot->GD = (CButtonWnd *)pNextWnd->pFirstChildWnd;
				pNextWnd = pNextWnd->pNextSiblingWnd;
				pSAdvLoot->NO = (CButtonWnd *)pNextWnd->pFirstChildWnd;
				if (pNextWnd && pNextWnd->pNextSiblingWnd) {
					pNextWnd = pNextWnd->pNextSiblingWnd;
				}

				//NPC_Name,Item,Status,Action,Manage,AN,AG,AutoRoll,NV,ND,GD,NO
				if(id==clist->GetItemData(i)) {
					CXWnd *ptr = 0;
					switch(type)
					{
					case 0:
						ptr = (CXWnd*)pSAdvLoot->NPC_Name;
						break;
					case 1:
						ptr = (CXWnd*)pSAdvLoot->Item;
						break;
					case 2:
						ptr = (CXWnd*)pSAdvLoot->Status;
						break;
					case 3:
						ptr = (CXWnd*)pSAdvLoot->Action;
						break;
					case 4:
						ptr = (CXWnd*)pSAdvLoot->Manage;
						break;
					case 5:
						ptr = (CXWnd*)pSAdvLoot->AN;
						break;
					case 6:
						ptr = (CXWnd*)pSAdvLoot->AG;
						break;
					case 7:
						ptr = (CXWnd*)pSAdvLoot->AutoRoll;
						break;
					case 8:
						ptr = (CXWnd*)pSAdvLoot->NV;
						break;
					case 9:
						ptr = (CXWnd*)pSAdvLoot->ND;
						break;
					case 10:
						ptr = (CXWnd*)pSAdvLoot->GD;
						break;
					case 11:
						ptr = (CXWnd*)pSAdvLoot->NO;
						break;
					case 12://root
						ptr = (CXWnd*)pSAdvLoot->Item;
						break;
					}
					delete pSAdvLoot;
					return ptr;
				}
			}
		}
	}
	return NULL;
}
void WeDidStuff()
{
	gbCommandEvent = 1;
	gMouseEventTime = GetFastTime();
}
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////
#endif

namespace EQData 
{

EQLIB_API struct _ITEMINFO *GetItemFromContents(struct _CONTENTS *c)
{
	if (!c)
		return NULL;
    return c->Item1 ? c->Item1 : c->Item2;
}
};
