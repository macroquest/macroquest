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



map<string,DWORD> MQ2DataTypeMap;
CIndex<MQ2Type*> MQ2DataTypes;

/*inline/**/ MQ2Type *FindMQ2DataType(PCHAR Name)
{
	unsigned long N=MQ2DataTypeMap[Name];
	if (!N)
		return 0;
	N--;
	return MQ2DataTypes[N];
}

namespace MQ2Internal
{
	BOOL AddMQ2Type(MQ2Type &Type)
	{
		if (FindMQ2DataType(Type.GetName()))	
			return false;
		unsigned long N=MQ2DataTypes.GetUnused();
		MQ2DataTypes[N]=&Type;
		MQ2DataTypeMap[Type.GetName()]=N+1;
		return true;
	}

	BOOL RemoveMQ2Type(MQ2Type &Type)
	{
		unsigned long N=MQ2DataTypeMap[Type.GetName()];
		if (!N)
			return 0;
		N--;
		if (MQ2Type *pType=MQ2DataTypes[N])
		{
			MQ2DataTypes[N]=0;
			return false;
		}
		MQ2DataTypeMap[Type.GetName()]=0;
		return true;
	}
};

map<string,DWORD> MQ2DataMap;
CIndex<PMQ2DATAITEM> MQ2DataItems;

inline PMQ2DATAITEM FindMQ2Data(PCHAR szName)
{
	unsigned long N=MQ2DataMap[szName];
	if (!N)
		return 0;
	N--;
	return MQ2DataItems[N];
}

BOOL AddMQ2Data(PCHAR szName, fMQData Function)
{
	if (FindMQ2Data(szName))	
		return false;
	unsigned long N=MQ2DataItems.GetUnused();
	PMQ2DATAITEM pNew=new MQ2DATAITEM;
	strcpy(pNew->Name,szName);
	pNew->Function=Function;
	MQ2DataItems[N]=pNew;
	MQ2DataMap[szName]=N+1;
	return true;
}

BOOL RemoveMQ2Data(PCHAR szName)
{
	unsigned long N=MQ2DataMap[szName];
	if (!N)
		return 0;
	N--;
	if (PMQ2DATAITEM pItem=MQ2DataItems[N])
	{
		MQ2DataItems[N]=0;
		delete pItem;
	}
	MQ2DataMap[szName]=0;
	return true;
}

void InitializeMQ2Data()
{
	AddMQ2Data("Spawn",dataSpawn);
	AddMQ2Data("Target",dataTarget);
	AddMQ2Data("Me",dataCharacter);
	AddMQ2Data("Spell",dataSpell);
	AddMQ2Data("Switch",dataSwitch);
	AddMQ2Data("Ground",dataGroundItem);
	AddMQ2Data("Merchant",dataMerchant);
	AddMQ2Data("Window",dataWindow);
	AddMQ2Data("Macro",dataMacro);
	AddMQ2Data("MacroQuest",dataMacroQuest);
	AddMQ2Data("Math",dataMath);
	AddMQ2Data("Zone",dataZone);
	AddMQ2Data("Group",dataGroup);
	AddMQ2Data("String",dataString);
	AddMQ2Data("Int",dataInt);
	AddMQ2Data("Bool",dataBool);
	AddMQ2Data("Float",dataFloat);
	AddMQ2Data("Corpse",dataCorpse);
	AddMQ2Data("If",dataIf);
	AddMQ2Data("Cursor",dataCursor);
}



void ShutdownMQ2Data()
{
	MQ2DataItems.Cleanup();
}

const UCHAR EndVariable[256]=
{
/*0x00-0x0F*/1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
/*0x10-0x1F*/1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
/*0x20-0x2F*/1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
/*0x30-0x3F*/0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,
/*0x40-0x4F*/1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
/*0x50-0x5F*/0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,
/*0x60-0x6F*/1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
/*0x70-0x7F*/0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,
/*0x80-0x8F*/1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
/*0x90-0x9F*/1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
/*0xA0-0xAF*/1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
/*0xB0-0xBF*/1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
/*0xC0-0xCF*/1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
/*0xD0-0xDF*/1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
/*0xE0-0xEF*/1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
/*0xF0-0xFF*/1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

inline BOOL NewSearchVariables(PCHAR szString,PVARSTRINGS pVarStrings)
{
	while (pVarStrings) {
		if (!strcmp(szString,pVarStrings->szName)) {
			strcpy(szString,pVarStrings->szVar);
			return TRUE;
		}
		pVarStrings = pVarStrings->pNext;
	}
	return FALSE;
}

BOOL NewSearchTimers(PCHAR szString)
{
	PTIMER pTimer=gTimer;
	while (pTimer) {
		if (!strcmp(szString,pTimer->szName)) {
			itoa(pTimer->Current,szString,10);
			return TRUE;
		}
		pTimer = pTimer->pNext;
	}
	return FALSE;
}

BOOL NewSearchArrays(PCHAR szString)
{
	DWORD Index1 = -1;
	DWORD Index2 = -1;
	CHAR szArray[MAX_STRING] = {0};
	strcpy(szArray,szString);
	PCHAR pLP=strchr(szArray,'(');
	if (pLP && (strchr(szArray,')'))) {
		Index1=atoi(&pLP[1]);
		PCHAR pComma=strchr(szArray,',');
		if (pComma) 
			Index2=atoi(pComma);
		*pLP=0;
	}
	else
		return FALSE;

	if (Index1 != -1) {
		PVARARRAYS pArray= GetArray(szArray,FALSE);
		if (!pArray) return FALSE;
		if (pArray->OneDimension && Index2 != -1) return FALSE;
		if (!pArray->OneDimension && Index2 == -1) return FALSE;
		PCHAR szResult = GetArrayStr(pArray,Index1,Index2,TRUE);
		if (szResult) {
			strcpy(szString,szResult);
			return TRUE;
		}
	}
	return FALSE;
}

BOOL ParseMacroVariables(PCHAR szOriginal)
{
	PCHAR pAt=strchr(szOriginal,'@');
	if (!pAt)
		return false;
	bool Changed=false;

	CHAR szCurrent[MAX_STRING]={0};
		// find this brace's end
	do
	{
		PCHAR pEnd=pAt;
		do
		{
            ++pEnd;
			if (EndVariable[(UCHAR)*pEnd])
			{
				break;
			}
		} while(1);
		unsigned long Len=(pEnd-pAt)-1;
		if (!Len)
			goto pmvbottom;
		strncpy(szCurrent,&pAt[1],Len);
		szCurrent[Len]=0;

		// szCurrent is the variable name
		if (gMacroStack)
		{
			if (NewSearchVariables(szCurrent,gMacroStack->StackStr)) goto pmvinsert;
			if (NewSearchVariables(szCurrent,gMacroStack->LocalStr)) goto pmvinsert;
		}
		if (NewSearchVariables(szCurrent,gMacroStr)) goto pmvinsert;
		if (NewSearchTimers(szCurrent)) goto pmvinsert;

		if (*pEnd=='(')
		{
			PCHAR pStart=pEnd;
			BOOL Quote=false;
			int nParens=1;
			++pEnd;
			while (nParens)
			{
				if (*pEnd==0)
				{// unmatched parenthesis or quote
					goto pmvbottom;
				}
				if (*pEnd==')')
				{
					if (!Quote)
						nParens--;
				}
				else if (*pEnd=='(')
				{
					if (!Quote)
						nParens++;
				}
				else if (*pEnd=='\"')
				{
					Quote=!Quote;
				}
			} 
		}
		
		Len=(pEnd-pAt)-1;
		strncpy(szCurrent,&pAt[1],Len);
		szCurrent[Len]=0;
		ParseMacroVariables(szCurrent);
		ParseMacroData(szCurrent);

		if (NewSearchArrays(szCurrent)) goto pmvinsert;

		goto pmvbottom;
		// insert szCurrent into current position
pmvinsert:;
		{
			unsigned long NewLength=strlen(szCurrent);

			memmove(&pAt[NewLength],&pEnd,strlen(pEnd)+1);
			strncpy(pAt,szCurrent,NewLength);
			Changed=true;
		}
pmvbottom:;
	} while (pAt=strstr(&pAt[1],"${"));
/*
	PCHAR Rep=&szOriginal[0];
	while(*Rep)
	{
		if (*Rep==-0x7E)
			*Rep='$';
		++Rep;
	}
/**/

	return Changed;
}


BOOL ParseMacroData(PCHAR szOriginal)
{
	// find each {}
	PCHAR pBrace=strstr(szOriginal,"${");
	if (!pBrace)
		return false;
	unsigned long NewLength;
	BOOL Changed=false;
	PCHAR pPos;
	PCHAR pStart;
	PCHAR pIndex;
	CHAR szCurrent[MAX_STRING]={0};

	do
	{
		// find this brace's end
		PCHAR pEnd=&pBrace[1];
		BOOL Quote=false;
		int nBrace=1;
		while(nBrace)
		{
			++pEnd;
			if (*pEnd==0)
			{// unmatched brace or quote
				goto pmdbottom;
			}
			if (*pEnd=='}')
			{
				if (!Quote)
					nBrace--;
			}
			else if (*pEnd=='{')
			{
				if (!Quote)
					nBrace++;
			}
			else if (*pEnd=='\"')
			{
				Quote=!Quote;
			}
		}
		*pEnd=0;
		strcpy(szCurrent,&pBrace[2]);
		if (szCurrent[0]==0)
		{
			goto pmdbottom;
		}
		if (ParseMacroData(szCurrent))
		{
			unsigned long NewLength=strlen(szCurrent);
			memmove(&pBrace[NewLength+1],&pEnd[1],strlen(&pEnd[1])+1);
			strncpy(pBrace,szCurrent,NewLength);
			pEnd=&pBrace[NewLength];
			*pEnd=0;
		}

		MQ2TYPEVAR CurrentVar;
		CurrentVar.Type=0;
		CurrentVar.Ptr=0;
		// Find [] before a . or null
		pPos=&szCurrent[0];
		pStart=pPos;
		pIndex="";
		while(1)
		{
			if (*pPos==0)
			{
				// end completely. process
				if (pStart==pPos)
				{
					if (!CurrentVar.Type)
					{
						strcpy(szCurrent,"NULL");
						goto pmdinsert;
					}
					CurrentVar.Type->ToString(CurrentVar.VarPtr,szCurrent);
					goto pmdinsert;
				}
				else
				{
					if (!CurrentVar.Type)
					{
						PMQ2DATAITEM DataItem=FindMQ2Data(pStart);
						if (!DataItem)
						{
							// error
							strcpy(szCurrent,"NULL");
							goto pmdinsert;
						}
						if (!DataItem->Function(pIndex,CurrentVar))
						{
							// error
							strcpy(szCurrent,"NULL");
							goto pmdinsert;
						}
					}
					else
					{
						if (!CurrentVar.Type->GetMember(CurrentVar.VarPtr,pStart,pIndex,CurrentVar))
						{
							// error
							strcpy(szCurrent,"NULL");
							goto pmdinsert;
						}
					}
				}
				CurrentVar.Type->ToString(CurrentVar.VarPtr,szCurrent);

				// done processing
				goto pmdinsert;
			}
			if (*pPos=='(')
			{
				*pPos=0;
				if (pStart==pPos)
				{
					if (!CurrentVar.Type)
					{
						strcpy(szCurrent,"NULL");
						goto pmdinsert;
					}
					CurrentVar.Type->ToString(CurrentVar.VarPtr,szCurrent);
					goto pmdinsert;
				}
				else
				{
					if (!CurrentVar.Type)
					{
						PMQ2DATAITEM DataItem=FindMQ2Data(pStart);
						if (!DataItem)
						{
							// error
							strcpy(szCurrent,"NULL");
							goto pmdinsert;
						}
						if (!DataItem->Function(pIndex,CurrentVar))
						{
							// error
							strcpy(szCurrent,"NULL");
							goto pmdinsert;
						}
						
					}
					else
					{
						if (!CurrentVar.Type->GetMember(CurrentVar.VarPtr,pStart,pIndex,CurrentVar))
						{
							// error
							strcpy(szCurrent,"NULL");
							goto pmdinsert;
						}
					}
				}
				if (!CurrentVar.Type)
				{
					// error
					strcpy(szCurrent,"NULL");
					goto pmdinsert;
				}
				*pPos=0;
				++pPos;
				PCHAR pType=pPos;
				while(*pPos!=')')
				{
					if (!*pPos)
					{
						// error
						strcpy(szCurrent,"NULL");
						goto pmdinsert;
					}
					++pPos;
				}
				*pPos=0;
				CurrentVar.Type=FindMQ2DataType(pType);
				if (!CurrentVar.Type)
				{
					// error
					strcpy(szCurrent,"NULL");
					goto pmdinsert;
				}
				if (pPos[1]=='.')
					pStart=&pPos[1];
				else if (!pPos[1])
				{
					CurrentVar.Type->ToString(CurrentVar.VarPtr,szCurrent);
					goto pmdinsert;
				}
				else
				{
					strcpy(szCurrent,"NULL");
					goto pmdinsert;
				}
			}
			else
			if (*pPos=='[')
			{
				// index
				*pPos=0;
				++pPos;
				// check for quote
				if (*pPos=='\"')
				{
					Quote=true;
					// find matching quote, we know it has one
					++pPos;
					pIndex=pPos;
					while(*pPos!='\"')
					{
						if (*pPos==0)
						{
							// error
							strcpy(szCurrent,"NULL");
							goto pmdinsert;
						}
						++pPos;
					}
					// here's the end of the index, close it off
					*pPos=0;
					// and advance pointer again
					++pPos;
				}
				else
					pIndex=pPos;
				while(*pPos!=']')
				{
					if (!*pPos)
					{
						// error
						strcpy(szCurrent,"NULL");
						goto pmdinsert;
					}
					++pPos;
				}
				*pPos=0;
				if (pPos[1]!=0 && pPos[1]!='.' && pPos[1]!='(')
				{
					// broken!
					strcpy(szCurrent,"NULL");
					goto pmdinsert;
				}
			}
			else
			if (*pPos=='.')
			{
				// end of this one, but more to come!
				*pPos=0;
				if (pStart==pPos)
				{
					if (!CurrentVar.Type)
					{
						strcpy(szCurrent,"NULL");
						goto pmdinsert;
					}
					CurrentVar.Type->ToString(CurrentVar.VarPtr,szCurrent);
					goto pmdinsert;
				}
				else
				{
					if (!CurrentVar.Type)
					{
						PMQ2DATAITEM DataItem=FindMQ2Data(pStart);
						if (!DataItem)
						{
							// error
							strcpy(szCurrent,"NULL");
							goto pmdinsert;
						}
						if (!DataItem->Function(pIndex,CurrentVar))
						{
							// error
							strcpy(szCurrent,"NULL");
							goto pmdinsert;
						}
						
					}
					else
					{
						if (!CurrentVar.Type->GetMember(CurrentVar.VarPtr,pStart,pIndex,CurrentVar))
						{
							// error
							strcpy(szCurrent,"NULL");
							goto pmdinsert;
						}
					}
				}
				pStart=&pPos[1];
			}
			++pPos;
		}

		// insert szCurrent into current position
pmdinsert:;
		  {
			NewLength=strlen(szCurrent);

			memmove(&pBrace[NewLength],&pEnd[1],strlen(&pEnd[1])+1);
			strncpy(pBrace,szCurrent,NewLength);
			Changed=true;
		  }
pmdbottom:;
	} while (pBrace=strstr(&pBrace[1],"${"));

/*
	PCHAR Rep=&szOriginal[0];
	while(*Rep)
	{
		if (*Rep==-0x7E)
			*Rep='$';
		++Rep;
	}
/**/

	return Changed;
}

