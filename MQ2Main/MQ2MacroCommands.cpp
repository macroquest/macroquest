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
// Function:    Delay
// Description: Our '/delay' command
// Usage:       /delay <time>
// ***************************************************************************
VOID Delay(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szVal[MAX_STRING] = {0};
    LONG VarValue;

    if (szLine[0]==0) {
        WriteChatColor("Usage: /delay <time>",USERCOLOR_DEFAULT);

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
// Function:    VarCalc
// Description: Our '/varcalc' command
// Usage:       /varcalc <variable> <value>
// ***************************************************************************
/*
DOUBLE Calculate(PCHAR szFormula) {
    CHAR Buffer[MAX_STRING] = {0};
    DWORD i = 0, j=0, k=0;
    CHAR Arg[MAX_STRING][100] = {0};
    for (i=0;i<strlen(szFormula);i++) {
        if (szFormula[i] != ' ') Buffer[j++]=szFormula[i];
    }
    j=0;
    k=0;
    for (i=0;i<strlen(Buffer);i++) {
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
					Arg[j+1][0]='!';
					j+=2;
					k=0;
					i++;
				}
				else
				{
					GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Calculate encountered a bad != formation");
					return -1;
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
					GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Calculate encountered a bad = formation");
					return -1;
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
                GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Calculate encountered a unparsed variable '%s'",&(Buffer[i]));
				return -1;
            default:
                GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Calculate encountered unparsable text '%s'",Arg[j]);
                return -1;
        }
    }
    j++;

    //for (i=0;i<j;i++) DebugSpewNoFile("%d. %s",i,Arg[i]);


    for (i=0;i<j;i++) {
        switch (Arg[i][0]) {
            case '^':
                if ((i==0) || (i+1==j)) {
				    GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Calculate encountered a bad %c formation",Arg[i][0]);
                    return -1;
                }
                i--;
                sprintf(Buffer,"%1.2f",pow(atof(Arg[i]),atof(Arg[i+2])));
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
				    GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Calculate encountered a bad %c formation",Arg[i][0]);
                    return -1;
                }
                i--;
                switch (Arg[i+1][0]) {
                    case '%':
                        if (atof(Arg[i+2])==0) return -1.0f;
                        ltoa(atoi(Arg[i])%atol(Arg[i+2]),Buffer,10);
                        break;
                    case '\\':
                        if (atof(Arg[i+2])==0) return -1.0f;
                        ltoa((LONG)(atol(Arg[i])/atol(Arg[i+2])),Buffer,10);
                        break;
                    case '/':
                        if (atof(Arg[i+2])==0) return -1.0f;
                        sprintf(Buffer,"%1.2f",(atof(Arg[i])/atof(Arg[i+2])));
                        break;
                    case '*':
                        sprintf(Buffer,"%1.2f",(atof(Arg[i])*atof(Arg[i+2])));
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
				    GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Calculate encountered a bad %c formation",Arg[i][0]);
                    return -1;
                }
                i--;
                switch (Arg[i+1][0]) {
                    case '+':
                        sprintf(Buffer,"%1.2f",(atof(Arg[i])+atof(Arg[i+2])));
                        break;
                    case '-':
                        sprintf(Buffer,"%1.2f",(atof(Arg[i])-atof(Arg[i+2])));
                        break;
                }
                strcpy(Arg[i],Buffer);
                j-=2;
                for (k=i+1;k<j;k++) strcpy(Arg[k],Arg[k+2]);
        }
    }

    for (i=0;i<j;i++) {
        switch ((UCHAR)Arg[i][0]) {
			case 'a':
			case 'o':
            case '<':
            case '>':
			case '=':
			case 0xf2:
			case 0xf3:
                if ((i==0) || (i+1==j)) {
				    GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Calculate encountered a bad %c formation",Arg[i][0]);
                    return -1;
                }
                i--;
                switch ((UCHAR)Arg[i+1][0]) {
					case '<':
						sprintf(Buffer,"%d",atof(Arg[i])<atof(Arg[i+2]));
						break;
					case '>':
						sprintf(Buffer,"%d",atof(Arg[i])>atof(Arg[i+2]));
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
					case 'a':
						sprintf(Buffer,"%d",atof(Arg[i])&&atof(Arg[i+2]));
						break;
					case 'o':
						sprintf(Buffer,"%d",atof(Arg[i])||atof(Arg[i+2]));
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
				    GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Calculate encountered a bad %c formation",Arg[i][0]);
                    return -1;
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
	
	return atof(Arg[0]);
}
/**/


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
					GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Calculate encountered an unmatched parenthesis");
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
				j+=sprintf(&Buffer[j],"%1.2f",CalcResult);
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
					GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Calculate encountered a bad = formation");
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
    //            GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Calculate encountered unparsable text '%s'",Arg[j]);
                return false;
        }
    }
    j++;

    //for (i=0;i<j;i++) DebugSpewNoFile("%d. %s",i,Arg[i]);
    for (i=0;i<j;i++) {
        switch (Arg[i][0]) {
            case '!':
                if (i+1==j) {
				    GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Calculate encountered a bad %c formation",Arg[i][0]);
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
				    GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Calculate encountered a bad %c formation",Arg[i][0]);
                    return false;
                }
                i--;
                sprintf(Buffer,"%1.2f",pow(atof(Arg[i]),atof(Arg[i+2])));
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
				    GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Calculate encountered a bad %c formation",Arg[i][0]);
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
                        sprintf(Buffer,"%1.2f",(atof(Arg[i])/atof(Arg[i+2])));
                        break;
                    case '*':
                        sprintf(Buffer,"%1.2f",(atof(Arg[i])*atof(Arg[i+2])));
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
				    GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Calculate encountered a bad %c formation",Arg[i][0]);
                    return false;
                }
                i--;
                switch (Arg[i+1][0]) {
                    case '+':
                        sprintf(Buffer,"%1.2f",(atof(Arg[i])+atof(Arg[i+2])));
                        break;
                    case '-':
                        sprintf(Buffer,"%1.2f",(atof(Arg[i])-atof(Arg[i+2])));
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
				    GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Calculate encountered a bad %c formation",Arg[i][0]);
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
				    GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Calculate encountered a bad %c formation",Arg[i][0]);
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
				    GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Calculate encountered a bad %c formation",Arg[i][0]);
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
	return ActualCalculate(Buffer,Result);
}

VOID VarCalc(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szVar[MAX_STRING] = {0};
    CHAR szVal[MAX_STRING] = {0};
    DOUBLE VarValue;
    bRunNextCommand = TRUE;

    GetArg(szVar,szLine,1);
    GetArg(szVal,szLine,2);

    PCHAR szResult = NULL;
    PTIMER pTimer = NULL;
    GetVariable(szVar,&szResult,&pTimer);
    if (!szResult && !pTimer) {
        GracefullyEndBadMacro(pChar,gMacroBlock, "Bad variable in /var function.");
        return;
        }
     Calculate(GetNextArg(szLine,1),VarValue);
    if (szResult) sprintf(szResult,"%1.2f",VarValue);
    if (pTimer) {
        pTimer->Current = (DWORD)VarValue;
        pTimer->Original = pTimer->Current;
    }

}


// ***************************************************************************
// Function:    VarSet
// Description: Our '/varset' command
// Usage:       /varset <variable> <value>
// ***************************************************************************
VOID VarSet(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szVar[MAX_STRING] = {0};
    CHAR szVal[MAX_STRING] = {0};
    DOUBLE VarValue;
    bRunNextCommand = TRUE;

    GetArg(szVar,szLine,1);
    GetArg(szVal,szLine,2);

    PCHAR szResult = NULL;
    PTIMER pTimer = NULL;
    GetVariable(szVar,&szResult,&pTimer);
    if (!szResult && !pTimer) {
        GracefullyEndBadMacro(pChar,gMacroBlock, "Bad variable in /var function.");
        return;
    }
    if (szResult) strcpy(szResult,szVal);
    if (pTimer) {
        VarValue = atof(szVal);
            switch (szVal[strlen(szVal)-1]) {
                case 'm':
                case 'M':
                    VarValue *= 60;
                case 's':
                case 'S':
                    VarValue *= 10;
            }
        pTimer->Current = (DWORD)VarValue;
        pTimer->Original = pTimer->Current;
    }
}


// ***************************************************************************
// Function:    MyVarAdd
// Description: Our '/varadd' command
// Usage:       /varadd <variable> <value>
// ***************************************************************************
VOID MyVarAdd(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szVar[MAX_STRING] = {0};
    CHAR szVal[MAX_STRING] = {0};
    DOUBLE VarValue;
    bRunNextCommand = TRUE;

    GetArg(szVar,szLine,1);
    GetArg(szVal,szLine,2);

    PCHAR szResult = NULL;
    PTIMER pTimer = NULL;
    GetVariable(szVar,&szResult,&pTimer);
    if (!szResult && !pTimer) {
        GracefullyEndBadMacro(pChar,gMacroBlock, "Bad variable in /var function.");
        return;
    }
    if (szResult) {
        VarValue = atof(szResult)+atof(szVal);
        sprintf(szResult,"%1.2f",VarValue);
    }
    if (pTimer) {
    VarValue = atof(szVal);
            switch (szVal[strlen(szVal)-1]) {
                case 'm':
                case 'M':
                    VarValue *= 60;
                case 's':
                case 'S':
                    VarValue *= 10;
            }
        pTimer->Current += (DWORD)VarValue;
    }
}


// ***************************************************************************
// Function:    MyVarCat
// Description: Our '/varcat' command
// Usage:       /varadd <variable> <value>
// ***************************************************************************
VOID MyVarCat(PSPAWNINFO pChar, PCHAR szLine)
{
	CHAR szVar[MAX_STRING] = {0};
	CHAR szVal[MAX_STRING] = {0};
	bRunNextCommand = TRUE;

	GetArg(szVar,szLine,1);
	GetArg(szVal,szLine,2);

	PCHAR szResult = NULL;
	PTIMER pTimer = NULL;
	GetVariable(szVar,&szResult,&pTimer);
	if (!szResult) {
		GracefullyEndBadMacro(pChar,gMacroBlock, "Bad variable in /var function.");
		return;
	}
	strcat(szResult,szVal);
}


// ***************************************************************************
// Function:    MyVarSub
// Description: Our '/varsub' command
// Usage:       /varsub <variable> <value>
// ***************************************************************************
VOID MyVarSub(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szVar[MAX_STRING] = {0};
    CHAR szVal[MAX_STRING] = {0};
    DOUBLE VarValue;
    bRunNextCommand = TRUE;

    GetArg(szVar,szLine,1);
    GetArg(szVal,szLine,2);

    PCHAR szResult = NULL;
    PTIMER pTimer = NULL;
    GetVariable(szVar,&szResult,&pTimer);
    if (!szResult && !pTimer) {
        GracefullyEndBadMacro(pChar,gMacroBlock, "Bad variable in /var function.");
        return;
    }
    if (szResult) {
        VarValue = atof(szResult)-atof(szVal);
        sprintf(szResult,"%1.2f",VarValue);
    }
    if (pTimer) {
    VarValue = atof(szVal);
            switch (szVal[strlen(szVal)-1]) {
                case 'm':
                case 'M':
                    VarValue *= 60;
                case 's':
                case 'S':
                    VarValue *= 10;
            }
        pTimer->Current -= (DWORD)VarValue;
    }
}


// ***************************************************************************
// Function:    MyVarAnd
// Description: Our '/varand' command
// Usage:       /varand <variable> <value>
// ***************************************************************************
VOID MyVarAnd(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szVar[MAX_STRING] = {0};
    CHAR szVal[MAX_STRING] = {0};
    DWORD VarValue;
    bRunNextCommand = TRUE;

    GetArg(szVar,szLine,1);
    GetArg(szVal,szLine,2);

    PCHAR szResult = NULL;
    PTIMER pTimer = NULL;
    GetVariable(szVar,&szResult,&pTimer);
    if (!szResult && !pTimer) {
        GracefullyEndBadMacro(pChar,gMacroBlock, "Bad variable in /var function.");
        return;
    }
    if (szResult) {
        VarValue = atoi(szResult)&atoi(szVal);
        itoa(VarValue,szResult,10);
    }
    if (pTimer) {
    VarValue = atoi(szVal);
        switch (szVal[strlen(szVal)-1]) {
            case 'm':
            case 'M':
                VarValue *= 60;
            case 's':
            case 'S':
                VarValue *= 10;
        }
        pTimer->Current &= VarValue;
    }
}


// ***************************************************************************
// Function:    MyVarOr
// Description: Our '/varor' command
// Usage:       /varor <variable> <value>
// ***************************************************************************
VOID MyVarOr(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szVar[MAX_STRING] = {0};
    CHAR szVal[MAX_STRING] = {0};
    DWORD VarValue;
    bRunNextCommand = TRUE;

    GetArg(szVar,szLine,1);
    GetArg(szVal,szLine,2);

    PCHAR szResult = NULL;
    PTIMER pTimer = NULL;
    GetVariable(szVar,&szResult,&pTimer);
    if (!szResult && !pTimer) {
        GracefullyEndBadMacro(pChar,gMacroBlock, "Bad variable in /var function.");
        return;
    }
    if (szResult) {
        VarValue = atoi(szResult)|atoi(szVal);
        itoa(VarValue,szResult,10);
    }
    if (pTimer) {
    VarValue = atoi(szVal);
        switch (szVal[strlen(szVal)-1]) {
            case 'm':
            case 'M':
                VarValue *= 60;
            case 's':
            case 'S':
                VarValue *= 10;
        }
        pTimer->Current |= VarValue;
    }
}


// ***************************************************************************
// Function:    VarRShift
// Description: Our '/varrshift' command
// Usage:       /varrshift <variable> <value>
// ***************************************************************************
VOID VarRShift(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szVar[MAX_STRING] = {0};
    CHAR szVal[MAX_STRING] = {0};
    DWORD VarValue;
    bRunNextCommand = TRUE;

    GetArg(szVar,szLine,1);
    GetArg(szVal,szLine,2);

    PCHAR szResult = NULL;
    PTIMER pTimer = NULL;
    GetVariable(szVar,&szResult,&pTimer);
    if (!szResult && !pTimer) {
        GracefullyEndBadMacro(pChar,gMacroBlock, "Bad variable in /var function.");
        return;
    }
    if (szResult) {
        VarValue = atoi(szResult)>>atoi(szVal);
        itoa(VarValue,szResult,10);
    }
    if (pTimer) {
    VarValue = atoi(szVal);
        switch (szVal[strlen(szVal)-1]) {
            case 'm':
            case 'M':
                VarValue *= 60;
            case 's':
            case 'S':
                VarValue *= 10;
        }
        pTimer->Current = pTimer->Current>>VarValue;
    }
}


// ***************************************************************************
// Function:    VarLShift
// Description: Our '/varlshift' command
// Usage:       /varlshift <variable> <value>
// ***************************************************************************
VOID VarLShift(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szVar[MAX_STRING] = {0};
    CHAR szVal[MAX_STRING] = {0};
    DWORD VarValue;
    bRunNextCommand = TRUE;

    GetArg(szVar,szLine,1);
    GetArg(szVal,szLine,2);

    PCHAR szResult = NULL;
    PTIMER pTimer = NULL;
    GetVariable(szVar,&szResult,&pTimer);
    if (!szResult && !pTimer) {
        GracefullyEndBadMacro(pChar,gMacroBlock, "Bad variable in /var function.");
        return;
    }
    if (szResult) {
        VarValue = atoi(szResult)<<atoi(szVal);
        itoa(VarValue,szResult,10);
    }
    if (pTimer) {
    VarValue = atoi(szVal);
        switch (szVal[strlen(szVal)-1]) {
            case 'm':
            case 'M':
                VarValue *= 60;
            case 's':
            case 'S':
                VarValue *= 10;
        }
        pTimer->Current = pTimer->Current<<VarValue;
    }
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


// ***************************************************************************
// Function:    EditMacro
// Description: Our '/editmacro' command
// Usage:       /editmacro load <filename>
// Usage:       /editmacro save
// Usage:       /editmacro notes
// ***************************************************************************

/*
VOID LoadNotesWindow(PCHAR szFilename, PCHAR szTitle)
{
    FILE *fMacro = fopen(szFilename,"r");
	if (!fMacro) return;
	DWORD length = _filelength(_fileno(fMacro));
	PCHAR Buffer = (PCHAR)malloc(length+1);
	if (!Buffer) return;
	ZeroMemory(Buffer,length+1);
	fread(Buffer,1,length,fMacro);
	fclose(fMacro);

	SetCXStr(&((PEQNOTESWINDOW)pNoteWnd)->Wnd.WindowText,szTitle);
	SetCXStr(&((PEQNOTESWINDOW)pNoteWnd)->pEditWnd->WindowText,Buffer);
	free(Buffer);
}


VOID SaveNotesWindow(PCHAR szFilename, PCXSTR pCXStr)
{
    FILE *fMacro = fopen(szFilename,"w");
	if (!fMacro) return;
	DWORD i;
	for (i=0;i<pCXStr->Length;i++) {
		fputc(pCXStr->Text[i*(pCXStr->Encoding+1)],fMacro);
	}
	fclose(fMacro);
}

VOID EditMacro(PSPAWNINFO pChar, PCHAR szLine)
{
	if (!ppNoteWnd) return;
	if (!pNoteWnd) return;
	CHAR Arg1[MAX_STRING] = {0};
	CHAR Arg2[MAX_STRING] = {0};
	CHAR szFilename[MAX_STRING] = {0};
	CHAR szFilePath[MAX_STRING] = {0};
	GetArg(Arg1,szLine,1);
	GetArg(Arg2,szLine,2);
	if (!stricmp(Arg1,"notes")) {
		GetEQPath(szFilename);
		strcat(szFilename,"\\notes.txt");
		LoadNotesWindow(szFilename,"Notes Window");
	} else if (!stricmp(Arg1,"load")) {
		strcpy(szFilename,Arg2);
		if (!strstr(szFilename,".")) strcat(szFilename,".mac");
		sprintf(szFilePath,"%s\\%s",gszMacroPath, szFilename);
		LoadNotesWindow(szFilePath,szFilename);
	} else if (!stricmp(Arg1,"save")) {
		if (!stricmp(((PEQNOTESWINDOW)pNoteWnd)->Wnd.WindowText->Text,"notes")) return;
		if (Arg2[0]==0) {
			strcpy(Arg2,((PEQNOTESWINDOW)pNoteWnd)->Wnd.WindowText->Text);
		}
		strcpy(szFilename,Arg2);
		if (!strstr(szFilename,".")) strcat(szFilename,".mac");
		sprintf(szFilePath,"%s\\%s",gszMacroPath, szFilename);
		SaveNotesWindow(szFilePath,((PEQNOTESWINDOW)pNoteWnd)->pEditWnd->WindowText);
		
	} else {
		WriteChatColor("Usage: /editmacro <notes|load filename|save [filename]>",USERCOLOR_DEFAULT);
	}
}
/**/

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
        WriteChatColor("Cannot goto when a macro isn't running.",CONCOLOR_RED);
        return;
    }
    while (gMacroBlock->pPrev) {
        gMacroBlock=gMacroBlock->pPrev;
        if (!strnicmp(gMacroBlock->Line,"Sub ",4)) break;
    }

    while (gMacroBlock->pNext) {
        gMacroBlock=gMacroBlock->pNext;
        if (!strnicmp(gMacroBlock->Line,"Sub ",4)) {
            GracefullyEndBadMacro(pChar,pFromLine,"Couldn't find label %s",szLine);
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
    GracefullyEndBadMacro(pChar,pFromLine,"Couldn't find label %s",szLine);
}


// ***************************************************************************
// Function:    ZapVars
// Description: Our '/zapvars' command
// Usage:       /zapvars
// ***************************************************************************
VOID ZapVars(PSPAWNINFO pChar, PCHAR szLine)
{
    BOOL bTimers = TRUE;
    BOOL bVars = TRUE;
    BOOL bArrays = TRUE;
    CHAR Arg[MAX_STRING] = {0};
    PCHAR pArgs = szLine;
    if (pArgs) {
        while (pArgs[0]) {
            GetArg(Arg,pArgs,1);
            pArgs = GetNextArg(pArgs);
            if (!stricmp(Arg,"notimers")) bTimers = FALSE;
            if (!stricmp(Arg,"novars")) bVars = FALSE;
            if (!stricmp(Arg,"noarrays")) bArrays = FALSE;
        }
    }
    bRunNextCommand = TRUE;
    if (bVars) { FreeVarStrings(gMacroStr); gMacroStr=NULL; }
    if (bArrays) { FreeVarArrays(); gArray=NULL; }
    if (bTimers) FreeTimers();

    if (!bArrays && !bVars && !bTimers) {
        WriteChatColor("Command did nothing.",USERCOLOR_DEFAULT);
    } else {
        CHAR szTemp[MAX_STRING] = {0};
        strcpy(szTemp,"Cleared the following:");
        if (bTimers) strcat(szTemp," Timers");
        if (bVars) strcat(szTemp," Vars");
        if (bArrays) strcat(szTemp," Arrays");
        WriteChatColor(szTemp,USERCOLOR_DEFAULT);
    }
}

// ***************************************************************************
// Function:    SendKey
// Description: Our '/sendkey' command
//              Sends a key up or down
// Usage:       /sendkey <u|d> <key>
// ***************************************************************************
VOID SendKey(PSPAWNINFO pChar, PCHAR szLine)
{
	static bool UpdateSendKeyMessageGiven=false;
 	if (!UpdateSendKeyMessageGiven)
	{
		WriteChatColor("Warning: /sendkey is now obsolete. please use /keypress instead. /sendkey will soon be removed entirely.",CONCOLOR_RED);
		UpdateSendKeyMessageGiven=true;
	}
	
	WORD i;
    CHAR Arg1[MAX_STRING];
    CHAR Arg2[MAX_STRING];
    GetArg(Arg1,szLine,1);
    GetArg(Arg2,szLine,2);

    if ((Arg1[0]==0) || (Arg2[0]==0) || ((!strnicmp(Arg1,"down",strlen(Arg1))) && (!strnicmp(Arg1,"up",strlen(Arg1))))) {
        GracefullyEndBadMacro(pChar,gMacroBlock, "Bad SendKey command");
        return;
    }

    for (i=0;gDiKeyID[i].szName[0];i++) {
        if (!stricmp(gDiKeyID[i].szName,Arg2)) {
            PKEYPRESS pNext = (PKEYPRESS)malloc(sizeof(KEYPRESS));
            pNext->KeyId = i;
            pNext->Pressed = !strnicmp(Arg1,"down",strlen(Arg1));
            pNext->pNext = NULL;

            //DebugSpewNoFile("SendKey - Queuing '%s' as %s",gDiKeyID[i].szName,Arg1);
            if (!gKeyStack) {
                gKeyStack = pNext;
                return;
            } else {
                PKEYPRESS pList = gKeyStack;
                while (pList->pNext) pList = pList->pNext;
                pList->pNext = pNext;
                return;
            }
        }
    }

    //TODO: User Spew
    DebugSpewNoFile("Unknown key: %s",Arg2);
    return;
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
        WriteChatColor("Cannot end a macro when one isn't running.",CONCOLOR_RED);
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
        for (i=0;gDiKeyID[i].szName[0];i++) {
            sprintf(Buffer,"up %s",gDiKeyID[i].szName);
            SendKey(pChar,Buffer);
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
    WriteChatColor("The current macro has ended.",USERCOLOR_DEFAULT);
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
// Function:    If
// Description: Our '/if' command
// Usage:       /if [n] <a>==<b> <command>
// ***************************************************************************

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
                    GracefullyEndBadMacro(pChar,pStartLine,"{} pairing ran into anther subroutine");
                    return;
                }
                if (!gMacroBlock->pNext) {
                    GracefullyEndBadMacro(pChar,pStartLine,"Bad {} block pairing");
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

// Returns a string with matching parens
BOOL MatchParens(PCHAR szLine, PCHAR szOut)
{
    DWORD dwParen=0;
    BOOL bQuote = FALSE;
    do {
        *szOut = *szLine;
        if (!bQuote) {
            if (*szOut == '(') dwParen++;
            if (*szOut == ')') dwParen--;
        }
        if (*szOut == '"') bQuote = !bQuote;
        szOut++;
        szLine++;
    } while (*szLine && dwParen);
    return !dwParen;
}

// Parsing for the [n] <a>==<b> condition type (must return entire condition)
void ParseSingleCondition(PCHAR szLine,PCHAR szCond)
{
    GetArg(szCond,szLine,1,TRUE);
    if (!strcmp(szCond, "n")) {
        szCond[1] = ' ';
        CHAR szCondAppend[MAX_STRING];
        GetArg(szCondAppend,szLine,2,TRUE);
        strncpy(szCond+2,szCondAppend,strlen(szCondAppend));
    }
}

// Parses the full condition and command from a /if line
BOOL ParseIfLine(PCHAR szLine, PCHAR szCond, PCHAR szCommand)
{
    if (*szLine=='(') {
        if (!MatchParens(szLine,szCond))
            *szCond = 0;
    } else ParseSingleCondition(szLine, szCond);

    if (*szCond)
        strcpy(szCommand,szLine+strlen(szCond)+1);

    return (*szCond && *szCommand);
}

// Breaks up a multi-part condition into the left side, right side and operator
BOOL ParseMultiCondition(PCHAR szCondition, PCHAR szLeftCond, PCHAR szRightCond, DWORD* pdwOperator)
{
    if (*szCondition=='(') {
        if (!MatchParens(szCondition,szLeftCond))
            *szLeftCond = 0;
    }
    else ParseSingleCondition(szCondition,szLeftCond);
    if (*szLeftCond == 0)
        return false;

    szCondition += strlen(szLeftCond) + 1;

    if (!strncmp(szCondition,"&&",2)) {
        *pdwOperator = 1;
    } else if (!strncmp(szCondition, "||",2)) {
        *pdwOperator = 0;
    } else return false;

    szCondition += 3;

    if (*szCondition=='(') {
        if (!MatchParens(szCondition,szRightCond))
            *szRightCond = 0;
    } else ParseSingleCondition(szCondition,szRightCond);

    return (*szRightCond != 0);
}

VOID FailIfParsing()
{
    GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Failed to parse /if command");
    WriteChatColor("Usage:",CONCOLOR_RED);
    WriteChatColor("   /if <condition> <command>",CONCOLOR_RED);
    WriteChatColor("   <condition> : (<condition> && <condition>) or [n] <a>==<b>",CONCOLOR_RED);
}

// Returns the result of a comparison.  The condition is in the form [n] <a>==<b>
BOOL CheckCondition(PCHAR szCondition)
{
    CHAR szCond[MAX_STRING] = {0};
    DWORD Comp = COMP_NONE;
    CHAR szVal1[MAX_STRING] =  {0},szVal2[MAX_STRING] =  {0};
    DWORD CompareType = COMP_TYPE_STRING;
    GetArg(szCond,szCondition,1);
    if (!stricmp(szCond,"n")) {
        CompareType = COMP_TYPE_NUMERIC;
        GetArg(szCond,szCondition,2);
    }

    _strlwr(szCond);
    if (strstr(szCond,"==")){
        Comp = COMP_EQ;
        strncpy(szVal1,szCond,strstr(szCond,"==")-szCond);
        strcpy(szVal2,strstr(szCond,"==")+2);
    } else if (strstr(szCond,"!=")){
        Comp = COMP_NE;
        strncpy(szVal1,szCond,strstr(szCond,"!=")-szCond);
        strcpy(szVal2,strstr(szCond,"!=")+2);
    } else if (strstr(szCond,">=")) {
        Comp = COMP_GE;
        strncpy(szVal1,szCond,strstr(szCond,">=")-szCond);
        strcpy(szVal2,strstr(szCond,">=")+2);
    } else if (strstr(szCond,"<=")) {
        Comp = COMP_LE;
        strncpy(szVal1,szCond,strstr(szCond,"<=")-szCond);
        strcpy(szVal2,strstr(szCond,"<=")+2);
    } else if (strstr(szCond,">")) {
        Comp = COMP_GT;
        strncpy(szVal1,szCond,strstr(szCond,">")-szCond);
        strcpy(szVal2,strstr(szCond,">")+1);
    } else if (strstr(szCond,"<")) {
        Comp = COMP_LT;
        strncpy(szVal1,szCond,strstr(szCond,"<")-szCond);
        strcpy(szVal2,strstr(szCond,"<")+1);
    } else if (strstr(szCond,"~~")) {
        Comp = COMP_CONT;
        strncpy(szVal1,szCond,strstr(szCond,"~~")-szCond);
        strcpy(szVal2,strstr(szCond,"~~")+2);
        if (CompareType != COMP_TYPE_STRING) {
            WriteChatColor("You want to compare ~~ numerically, forcing string compare.",CONCOLOR_RED);
            CompareType = COMP_TYPE_STRING;
        }
    } else if (strstr(szCond,"!~")) {
        Comp = COMP_NOTCONT;
        strncpy(szVal1,szCond,strstr(szCond,"!~")-szCond);
        strcpy(szVal2,strstr(szCond,"!~")+2);
        if (CompareType != COMP_TYPE_STRING) {
            WriteChatColor("You want to compare !~ numerically, forcing string compare.",CONCOLOR_RED);
            CompareType = COMP_TYPE_STRING;
        }
    } else if (strstr(szCond,"&")) {
        Comp = COMP_BITAND;
        strncpy(szVal1,szCond,strstr(szCond,"&")-szCond);
        strcpy(szVal2,strstr(szCond,"&")+1);
        CompareType = COMP_TYPE_BIT;
    } else if (strstr(szCond,"|")) {
        Comp = COMP_BITOR;
        strncpy(szVal1,szCond,strstr(szCond,"|")-szCond);
        strcpy(szVal2,strstr(szCond,"|")+1);
        CompareType = COMP_TYPE_BIT;
    } else {
        sprintf(szVal1,"Couldn't find a comparision operator in '%s'",szCond);
        WriteChatColor(szVal1,CONCOLOR_RED);
		FailIfParsing();
        return false;
    }

    switch (CompareType) {
        case COMP_TYPE_STRING:
            switch (Comp) {
                case COMP_EQ:
                    return (stricmp(szVal1, szVal2) == 0);
                case COMP_NE:
                    return (stricmp(szVal1, szVal2) != 0);
                case COMP_GT:
                    return (stricmp(szVal1, szVal2) > 0);
                case COMP_LT:
                    return (stricmp(szVal1, szVal2) < 0);
                case COMP_GE:
                    return (stricmp(szVal1, szVal2) >= 0);
                case COMP_LE:
                    return (stricmp(szVal1, szVal2) <= 0);
                case COMP_CONT:
                    return (strstr(szVal1, szVal2) != NULL);
                case COMP_NOTCONT:
                    return (strstr(szVal1, szVal2) == NULL);
            }
            break;
        case COMP_TYPE_NUMERIC:
            {
                DOUBLE dVal1 = atof(szVal1);
                DOUBLE dVal2 = atof(szVal2);
                switch (Comp) {
                    case COMP_EQ:
                        return (dVal1 == dVal2);
                    case COMP_NE:
                        return (dVal1 != dVal2);
                    case COMP_GT:
                        return (dVal1 > dVal2);
                    case COMP_LT:
                        return (dVal1 < dVal2);
                    case COMP_GE:
                        return (dVal1 >= dVal2);
                    case COMP_LE:
                        return (dVal1 <= dVal2);
                }
            }
            break;
        case COMP_TYPE_BIT:
            {
                DWORD dwVal1 = atoi(szVal1);
                DWORD dwVal2 = atoi(szVal2);
                switch (Comp) {
                    case COMP_BITAND:
                        return (dwVal1 & dwVal2);
                    case COMP_BITOR:
                        return (dwVal1 | dwVal2);
                }
            }
            break;
    }
    return false;
}

// Returns the result of a condition that may have multiple parts
BOOL IfCompare(PCHAR szCondition)
{
    // szCondition is in the form of (<condition> <operator> <condition>) or <condition>
    if (*szCondition=='(')
    {
        CHAR szInternal[MAX_STRING] = {0};
        CHAR szLeftCond[MAX_STRING] = {0};
        CHAR szRightCond[MAX_STRING] = {0};
        DWORD dwOperator;
        strncpy(szInternal,szCondition+1,strlen(szCondition)-2);
        if (!ParseMultiCondition(szInternal,szLeftCond,szRightCond,&dwOperator))
        {
            FailIfParsing();
            return false;
        }
        return (dwOperator ? (IfCompare(szLeftCond) && IfCompare(szRightCond)) : (IfCompare(szLeftCond) || IfCompare(szRightCond)));
    }
    else
    {
        return CheckCondition(szCondition);
    }
}

VOID If(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szCond[MAX_STRING] = {0};
    CHAR szCommand[MAX_STRING] = {0};

    if (!ParseIfLine(szLine, szCond, szCommand)) {
        FailIfParsing();
        return;
    }

    if (IfCompare(szCond)) 
		DoCommand(pChar,szCommand); 
	else 
		FailIf(pChar,szCommand, gMacroBlock);
}

VOID NewIf(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szCond[MAX_STRING] = {0};
    CHAR szCommand[MAX_STRING] = {0};

    if (!ParseIfLine(szLine, szCond, szCommand)) {
	    GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Failed to parse /newif command");
	    WriteChatColor("Usage: /newif <condition> <command>",CONCOLOR_RED);
        FailIfParsing();
        return;
    }

	DOUBLE Result=0;
	if (!Calculate(szCond,Result))
	{
		sprintf(szCommand,"Failed to parse /newif condition '%s', non-numeric encountered",szCond);
		GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, szCommand);
		return;
	}


	if (Result!=0)
		DoCommand(pChar,szCommand); 
	else
		FailIf(pChar,szCommand, gMacroBlock);
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
        WriteChatColor("Usage: /call <subroutine> [param [param...]]",USERCOLOR_DEFAULT);
        return;
    }
    if (!gMacroBlock) {
        WriteChatColor("Cannot call when a macro isn't running.",CONCOLOR_RED);
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
    GracefullyEndBadMacro(pChar,pCallingPoint,"Subroutine %s wasn't found",SubName);
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
        WriteChatColor("Cannot return when a macro isn't running.",CONCOLOR_RED);
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
        GracefullyEndBadMacro(((PCHARINFO)pCharData)->pSpawn,gMacroBlock, "Couldn't open include file: %s",szFile);
        return 0;
    }
    DebugSpewNoFile("Include - Including: %s",szFile);
    while (!feof(fMacro)) {

        fgets(szTemp,MAX_STRING,fMacro);
        LineNumber++;
        while ((strlen(szTemp)>0) && (szTemp[strlen(szTemp)-1] < 32)) szTemp[strlen(szTemp)-1]=0;

        if (!strncmp(szTemp,"|**",3)) {
            InBlockComment=TRUE;
        }
        if (!InBlockComment) {
            if (NULL == (pAddedLine=AddMacroLine(szTemp))) {
            WriteChatColor("Unable to add macro line.",CONCOLOR_RED);
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
// Function:    Press
// Description: Our '/press' command
//              Sends a key up and down
// Usage:       /press <key>
// ***************************************************************************
VOID Press(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szCmd[MAX_STRING] = {0};
    CHAR szKey[MAX_STRING] = {0};
    GetArg(szKey,szLine,1);
    if (szKey[0]==0) {
        WriteChatColor("Usage: /press <key>",USERCOLOR_DEFAULT);
        return;
    }
	static bool UpdatePressMessageGiven=false;
	if (!UpdatePressMessageGiven)
	{
		CHAR szOut[MAX_STRING]={0};
		sprintf(szOut,"Warning: /press is now obsolete. please use '/keypress %s' instead. /press will soon be removed entirely.",szLine);
		WriteChatColor(szOut,CONCOLOR_RED);
		UpdatePressMessageGiven=true;
	}
    sprintf(szCmd,"d %s",szKey);
    SendKey(pChar,szCmd);
    sprintf(szCmd,"u %s",szKey);
    SendKey(pChar,szCmd);
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
	if(ppContainerMgr && pContainerMgr) {
		PEQ_CONTAINERWND_MANAGER ContainerMgr = (PEQ_CONTAINERWND_MANAGER)pContainerMgr;
		DWORD concount=2; //Close inv + clear target
		if (ContainerMgr->pWorldContents && ContainerMgr->pWorldContents->Open==1) concount++;
		for (i=0;i<25;i++) {
			if (ContainerMgr->pPCContainers[i] && ContainerMgr->pPCContainers[i]->Wnd.Show==1) concount++;
		}
		for (i=0;i<concount;i++) Press(pChar,"esc");
		if (!ppInventoryWnd) {
			PCSIDLWND pInvWindow = (PCSIDLWND)pInventoryWnd;
			if (pInvWindow && pInvWindow->Show==0) Press(pChar,"i");
		}
	} else {
    Press(pChar,"i");
		for (i=0;i<10;i++) Press(pChar,"esc");
    Press(pChar,"i");
}
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
        GracefullyEndBadMacro(pChar,gMacroBlock, "/for loops cannot loop on a timer");
        return;
    }
    if ((!szLoop) || (ArgStart[0] == 0) || (ArgDirection[0] == 0) || (ArgEnd[0] == 0) || ((strcmp(ArgDirection,"to")) && (strcmp(ArgDirection,"downto")))) {
        GracefullyEndBadMacro(pChar,gMacroBlock, "Usage: /for <variable> <start> <to|downto> <end> [step x]");
        return;
    }
    if (!gMacroBlock) {
        WriteChatColor("Can only use /for during a macro.",CONCOLOR_RED);
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
        GracefullyEndBadMacro(pChar,gMacroBlock, "/for loops cannot loop on a timer");
        return;
    }
    if (!szLoop) {
        WriteChatColor("Usage: /next <variable>",USERCOLOR_DEFAULT);
        return;
    }
    if (!gMacroBlock) {
        WriteChatColor("Can only use /next during a macro.",CONCOLOR_RED);
        return;
    }
    sprintf(szComp,"/for %s",szNext);
    while (pMacroLine->pPrev) {
        strcpy(ForLine,pMacroLine->Line);
        if (!strnicmp(ForLine,"Sub ",4)) {
            GracefullyEndBadMacro(pChar,gMacroBlock, "/next without matching /for");
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
                GracefullyEndBadMacro(pChar,gMacroBlock, "/next without badly matching /for");
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

    GracefullyEndBadMacro(pChar, gMacroBlock, "/next without matching /for");
}

