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

namespace MQ2Internal
{
	BOOL AddMQ2Type(MQ2Type &Type)
	{
		return true;
	}

	VOID RemoveMQ2Type(MQ2Type &Type)
	{
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

bool AddMQ2Data(PCHAR szName, fMQData Function)
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

bool RemoveMQ2Data(PCHAR szName)
{
	return false;
}

void InitializeMQ2Data()
{
	AddMQ2Data("Spawn",dataSpawn);
	AddMQ2Data("Target",dataTarget);
	AddMQ2Data("Me",dataCharacter);
}



void ShutdownMQ2Data()
{
	MQ2DataItems.Cleanup();
}





BOOL ParseMacroData(PCHAR szOriginal)
{
	// find each {}
	PCHAR pBrace=strstr(szOriginal,"${");
	if (!pBrace)
		return false;
	
	BOOL Changed=false;
	CHAR szOutput[MAX_STRING]={0};

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
				*pBrace=-0x7E;
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
			continue;
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
		PCHAR pPos=&szCurrent[0];
		PCHAR pStart=pPos;
		PCHAR pIndex="";
		while(1)
		{
			if (*pPos==0)
			{
				// end completely. process
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
					if (!CurrentVar.Type->GetMember(CurrentVar.Ptr,pStart,pIndex,CurrentVar))
					{
						// error
						strcpy(szCurrent,"NULL");
						goto pmdinsert;
					}
				}
				CurrentVar.Type->ToString(CurrentVar.Ptr,szCurrent);

				// done processing
				goto pmdinsert;
			}
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
					while(*pPos!='\"') ++pPos;
					// here's the end of the index, close it off
					*pPos=0;
					// and advance pointer again
					++pPos;
				}
				else
					pIndex=pPos;
				while(*pPos!=']') ++pPos;
				*pPos=0;
				if (pPos[1]!=0 && pPos[1]!='.')
				{
					// broken!
					strcpy(szCurrent,"NULL");
					goto pmdinsert;
				}
			}
			if (*pPos=='.')
			{
				// end of this one, but more to come!
				*pPos=0;
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
					if (!CurrentVar.Type->GetMember(CurrentVar.Ptr,pStart,pIndex,CurrentVar))
					{
						// error
						strcpy(szCurrent,"NULL");
						goto pmdinsert;
					}
				}
				pStart=&pPos[1];
			}
			++pPos;
		}

		// insert szCurrent into current position
pmdinsert:;
		unsigned long NewLength=strlen(szCurrent);

		memmove(&pBrace[NewLength],&pEnd[1],strlen(&pEnd[1])+1);
		strncpy(pBrace,szCurrent,NewLength);
		Changed=true;
pmdbottom:;
	} while (pBrace=strstr(&pBrace[1],"${"));

	PCHAR Rep=&szOriginal[0];
	while(*Rep)
	{
		if (*Rep==-0x7E)
			*Rep='$';
		++Rep;
	}

	return Changed;
}

