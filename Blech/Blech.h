/*****************************************************************************
    Blech.h
	Lax/Blech  
    Copyright (C) 2004 Lax

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/

#pragma once

#define BLECHVERSION "Lax/Blech 1.0.0"

#include <map>

//#ifdef WIN32
#ifdef BLECH_DEBUG
//#pragma message(BLECHVERSION)
//#pragma message("Blech: Debug Mode")
#include <windows.h>
#define BLECHASSERT(x) if (!(x)) {BlechDebug("Blech Assertion failure: %s",#x); __asm{int 3};}
void BlechDebug(char *szFormat, ...)
{
    char szOutput[4096] = {0};
    va_list vaList;

    va_start( vaList, szFormat );
    vsprintf(szOutput,szFormat, vaList);
    OutputDebugString(szOutput);
    OutputDebugString("\n");
}
#define BlechTry(x) BlechDebug("Trying %s",#x);x;BlechDebug("%s complete",#x)
#else
#define BLECHASSERT(x) 
#define BlechTry(x) x
#define BlechDebug //
#endif

#ifdef BLECH_CASE_SENSITIVE
//#pragma message("Blech: Case Sensitive")
#define STRCMP(A,B) strcmp(A,B)
#define STRNCMP(A,B,LENGTH) strncmp(A,B,LENGTH)
#define STRFIND(HAYSTACK,NEEDLE) strstr(HAYSTACK,NEEDLE)
#else
//#pragma message("Blech: Case Insensitive")
#define STRCMP(A,B) stricmp(A,B)
#define STRNCMP(A,B,LENGTH) strnicmp(A,B,LENGTH)
#define STRFIND(HAYSTACK,NEEDLE) stristr(HAYSTACK,NEEDLE)
#endif
//#else
//#error Non-Win32 defines not yet available
//#endif


enum eBlechStringType
{
	BST_NORMAL=0,
	BST_PRINTVAR=1,
	BST_SCANVAR=2,
};


typedef struct _BLECHVALUE {
	char * Name;
	char * Value;
	struct _BLECHVALUE *pNext;
} BLECHVALUE, *PBLECHVALUE;

typedef unsigned long   (__cdecl *fBlechVariableValue)(char * VarName, char * Value);
typedef void (__cdecl *fBlechCallback)(unsigned long ID, void * pData, PBLECHVALUE pValues);

typedef struct _BLECHEVENT {
	unsigned long ID;
	void * pData;
	char * OriginalString;
	fBlechCallback Callback;

	class BlechNode *pBlechNode;
} BLECHEVENT, *PBLECHEVENT;

typedef std::map<unsigned long,PBLECHEVENT> BLECHEVENTMAP; 

typedef struct _BLECHEVENTNODE {
	PBLECHEVENT pEvent;

	struct _BLECHEVENTNODE *pNext;
	struct _BLECHEVENTNODE *pPrev;
} BLECHEVENTNODE, *PBLECHEVENTNODE;

class BlechNode
{
public:
	BlechNode(BlechNode *Parent, BlechNode **Root, char * String, eBlechStringType NewStringType=BST_NORMAL)
	{
		BlechDebug("BlechNode(%X,%X,%s,%d)",Parent,Root,String,NewStringType);
		BLECHASSERT(String && *String);
		BLECHASSERT(Root);
		StringType=NewStringType;
		if (StringType==BST_NORMAL)
			Length=(unsigned long)strlen(String);
		else
			Length=0;
		pString=strdup(String);
		pParent=Parent;
		ppRoot=Root;
		pChildren=0;
		pNext=0;
		pPrev=0;
		pEvents=0;
	}

	~BlechNode()
	{
		BlechDebug("~BlechNode()");
		// clean out chillins
		while(pChildren)
		{
			BlechNode *pNext=pChildren->pNext;
			delete pChildren;
			pChildren=pNext;
		}
		// clean out events
		while(pEvents)
		{
			pEvents->pEvent->pBlechNode=0;
			PBLECHEVENTNODE pNext=pEvents->pNext;
			delete pEvents;
			pEvents=pNext;
		}
		// remove me from my siblings
		if (pPrev)
			pPrev->pNext=pNext;
		else
		{
			// set parent's first child / root
			if (pParent)
				pParent->pChildren=pNext;
			else
				*ppRoot=pNext;
		}
		if (pNext)
			pNext->pPrev=pPrev;

		// free string
		free(pString);
	}

	BlechNode *AddChild(char *NewString, eBlechStringType NewStringType)
	{
		BlechDebug("AddChild(%s,%d)",NewString,NewStringType);
		BLECHASSERT(NewString);
		BlechNode *pNode = new BlechNode(this,ppRoot,NewString,NewStringType);
		BLECHASSERT(pNode);
		pNode->pNext=pChildren;
		if (pChildren)
			pChildren->pPrev=pNode;
		pChildren=pNode;
		return pChildren;
	}

	inline bool IsEmpty()
	{
		return (!pChildren && !pEvents);
	}

	inline void AddEvent(PBLECHEVENT pEvent)
	{
		BlechDebug("AddEvent(%X)",pEvent);
		BLECHASSERT(pEvent);
		
		PBLECHEVENTNODE pNode=new BLECHEVENTNODE;
		pNode->pEvent=pEvent;
		pNode->pNext=pEvents;
		if (pEvents)
			pEvents->pPrev=pNode;
		pNode->pPrev=0;
		pEvent->pBlechNode=this;
		pEvents=pNode;
	}

	void RemoveEvent(PBLECHEVENT pEvent)
	{
		BlechDebug("RemoveEvent(%X)",pEvent);
		BLECHASSERT(pEvent);
		PBLECHEVENTNODE pNode=pEvents;
		while(pNode)
		{
			if (pEvent==pNode->pEvent)
			{
				if (pNode->pNext)
					pNode->pNext->pPrev=pNode->pPrev;
				if (pNode->pPrev)
					pNode->pPrev->pNext=pNode->pNext;
				else
					pEvents=pNode->pNext;
				delete pNode;
				return;
			}
			pNode=pNode->pNext;
		}
	}

	BlechNode *FindChild(char *Find, eBlechStringType FindStringType=BST_NORMAL)
	{
		BlechDebug("FindChild(%s,%d",Find,FindStringType);
		BlechNode *pNode=pChildren;
		while(pNode)
		{
			if (FindStringType==pNode->StringType && !STRCMP(pNode->pString,Find))
				return pNode;
			pNode=pNode->pNext;
		}
		return 0;
	}

	eBlechStringType StringType;
	char * pString;
	unsigned long Length;
	BlechNode *pParent;
	BlechNode **ppRoot;
	BlechNode *pChildren;
	BlechNode *pNext;
	BlechNode *pPrev;

	PBLECHEVENTNODE pEvents;
};

class Blech
{
public:
	Blech(char ScanDelimiter,char PrintDelimiter,fBlechVariableValue PrintRetriever)
	{
		BlechDebug("Blech(%c,%c,%X)",ScanDelimiter,PrintDelimiter,PrintRetriever);
		BLECHASSERT(PrintDelimiter);
		BLECHASSERT(PrintRetriever);
		PrintVarDelimiter=PrintDelimiter;
		ScanVarDelimiter=ScanDelimiter;
		VariableValue=PrintRetriever;
		Initialize();
	}
	Blech(char ScanDelimiter=0)
	{
		BlechDebug("Blech(%c)",ScanDelimiter);
		ScanVarDelimiter=ScanDelimiter;
		PrintVarDelimiter=0;
		VariableValue=0;
		Initialize();
	}

	void Reset()
	{
		Cleanup();
		Event.clear();
		Initialize();
	}

	~Blech(void)
	{
		BlechDebug("~Blech()");
		Cleanup();
	}

	unsigned long Feed(char * Input)
	{
		BlechDebug("Feed(%s)",Input);
		if (!Input || !Input[0])
			return 0;
		unsigned long Root=Input[0];
#ifndef BLECH_CASE_SENSITIVE
				if (Root>='a' && Root<='z')
					Root-=32;
#endif
		return Feed(Tree[Root],Input)+Feed(Tree[0],Input);
	}

	unsigned long AddEvent(char *Text,fBlechCallback Callback,void *pData=0)
	{
		BlechDebug("AddEvent(%s,%X,%X)",Text,Callback,pData);
		BLECHASSERT(Text);
		BLECHASSERT(Callback);
		char *pText=Text;
		char *Part=Text;
		eBlechStringType StringType=BST_NORMAL;
		BlechNode *pNode=0;
		while(*pText)
		{
			if (*pText==ScanVarDelimiter)
			{
				if (Part!=pText)
					pNode=AddNode(pNode,Part,pText,StringType);
				Part=&pText[1];
				if (StringType==BST_SCANVAR)
					StringType=BST_NORMAL;
				else
					StringType=BST_SCANVAR;
			}
			else
			if (*pText==PrintVarDelimiter)
			{
				if (Part!=pText)
					pNode=AddNode(pNode,Part,pText,StringType);
				Part=&pText[1];
				if (StringType==BST_PRINTVAR)
					StringType=BST_NORMAL;
				else
					StringType=BST_PRINTVAR;
			}
			pText++;
		}
		if (*Part)
		{
			pNode=AddNode(pNode,Part,pText,StringType);
		}
		// add event to node
		BLECHASSERT(pNode);
		PBLECHEVENT pEvent = new BLECHEVENT;
		pEvent->Callback=Callback;
		pEvent->pData=pData;
		pEvent->ID=++LastID;
		pEvent->pBlechNode=pNode;
		pEvent->OriginalString=strdup(Text);
		pNode->AddEvent(pEvent);
		Event[pEvent->ID]=pEvent;
		return pEvent->ID;
	}

	bool RemoveEvent(unsigned long ID)
	{
		BlechDebug("RemoveEvent(%d)",ID);
		PBLECHEVENT pEvent = Event[ID];
		if (!pEvent)
			return false;
		Event.erase(ID);
		free(pEvent->OriginalString);
		BLECHASSERT(pEvent->pBlechNode);

		BlechNode *pNode=pEvent->pBlechNode;
		while(pNode && pNode->IsEmpty())
		{
			BlechNode *pNext=pNode->pParent;
			delete pNode;
			pNode=pNext;
		}
		return true;
	}

	char Version[32];

private:
	inline void Cleanup()
	{
		for (unsigned long N = 0 ; N < 256 ; N++)
		{
			delete Tree[N];
		}
		for (BLECHEVENTMAP::iterator i=Event.begin(); i != Event.end(); i++)
		{
			PBLECHEVENT pEvent=i->second;
			BLECHASSERT(pEvent);
			BlechTry(free(pEvent->OriginalString));
			delete pEvent;
		}
	}


	char *stristr(char *haystack,char *needle)
	{
		BlechDebug("stristr(%s,%s)",haystack,needle);
		unsigned long HaystackLength=(unsigned long)strlen(haystack);
		unsigned long NeedleLength=(unsigned long)strlen(needle);
		if (NeedleLength>HaystackLength)
			return 0;//nope
		if (NeedleLength==HaystackLength)
		{
			if (!STRCMP(haystack,needle))
				return haystack;
			return 0;
		}
		HaystackLength++;
		NeedleLength++;
		char *pHaystack=(char*)malloc(HaystackLength);
		char *pNeedle=(char*)malloc(NeedleLength);
		memcpy(pHaystack,haystack,HaystackLength);
		memcpy(pNeedle,needle,NeedleLength);
        strlwr(pHaystack);
		strlwr(pNeedle);
		char *pReturn=strstr(pHaystack,pNeedle);
		if (pReturn)
		{
			pReturn=haystack+(pReturn-pHaystack);
		}
		free(pHaystack);
		free(pNeedle);
		return pReturn;
	}


	unsigned long Feed(BlechNode *pNode,char * Input)
	{
		BlechDebug("Feed(%X,%s)",pNode,Input);
		BLECHASSERT(Input);
		if (!pNode)
			return 0;

		char VarData[4096];
//		unsigned long VarDataLength;

		struct MatchPos
		{
			char *Pos;
//			char *VarData;
			BlechNode *pNode;
		};
		
#define Push() {	MatchStack[PLP]=CurrentPos;	PLP++;	}
#define Pop()  {	PLP--; CurrentPos=MatchStack[PLP];	}
#define Peek() {	CurrentPos=MatchStack[PLP-1];		}

		MatchPos MatchStack[100];
		MatchPos CurrentPos;
		unsigned char PLP=0;
		memset(&MatchStack[0],0,sizeof(MatchStack));

		CurrentPos.Pos=Input;
		CurrentPos.pNode=0;
		Push();

		unsigned long Count=0;
		while(pNode)
		{
			switch(pNode->StringType)
			{
			case BST_NORMAL:
				if (CurrentPos.pNode && CurrentPos.pNode->StringType==BST_SCANVAR)
				{
					if (char *pFound=STRFIND(CurrentPos.Pos,pNode->pString))
					{
						CurrentPos.pNode=pNode;
						CurrentPos.Pos=&pFound[pNode->Length];
						if (!CurrentPos.Pos[0])
						{
							goto feedermatchdoevents;
						}
						goto feedermatchnoevent;
					}
				}
				else
				if (!STRNCMP(pNode->pString,CurrentPos.Pos,pNode->Length))
				{
					// match. do events?
					CurrentPos.pNode=pNode;
					CurrentPos.Pos+=pNode->Length;
					if (!CurrentPos.Pos[0])
					{
						goto feedermatchdoevents;
					}
					goto feedermatchnoevent;
				}
				goto feedernomatch;
			case BST_PRINTVAR:
				// variable data of unknown size
				BlechTry(pNode->Length=VariableValue(pNode->pString,VarData));
				if (!pNode->Length)
					goto feedernomatch;
				BLECHASSERT(VarData[0]);
				if (CurrentPos.pNode && CurrentPos.pNode->StringType==BST_SCANVAR)
				{
					if (char *pFound=STRFIND(CurrentPos.Pos,VarData))
					{
						CurrentPos.pNode=pNode;
						CurrentPos.Pos=&pFound[pNode->Length];
						if (!CurrentPos.Pos[0])
						{
							goto feedermatchdoevents;
						}
						goto feedermatchnoevent;
					}
				}
				else
				if (!STRNCMP(VarData,CurrentPos.Pos,pNode->Length))
				{
					CurrentPos.pNode=pNode;
					CurrentPos.Pos+=pNode->Length;
					if (!CurrentPos.Pos[0])
						goto feedermatchdoevents;
					goto feedermatchnoevent;						
				}
				goto feedernomatch;
			case BST_SCANVAR:
				// implied match
				CurrentPos.pNode=pNode;
				if (!pNode->pChildren || pNode->pEvents)
				{
					Push();
					CurrentPos.pNode=0;
					goto feedermatchdoevents;
				}
				goto feedermatchnoevent;
			}
feedermatchdoevents:
			PBLECHEVENTNODE pEventNode=pNode->pEvents;
			// create values
			Push();
			PBLECHVALUE pValues=0;
			for (unsigned long N = PLP-1 ; N > 0 ; N--)
			{
				if (MatchStack[N].pNode && MatchStack[N].pNode->StringType==BST_SCANVAR)
				{
					PBLECHVALUE pValue = new BLECHVALUE;
					pValue->Name=MatchStack[N].pNode->pString;
					if (MatchStack[N+1].pNode)
					{
						if (MatchStack[N+1].pNode->StringType!=BST_SCANVAR)
						{
			                unsigned long Length=MatchStack[N+1].Pos-MatchStack[N+1].pNode->Length-MatchStack[N].Pos;
							pValue->Value=(char*)malloc(Length+1);
							memcpy(pValue->Value,MatchStack[N].Pos,Length);
							pValue->Value[Length]=0;
						}
						else
						{
							pValue->Value=(char*)malloc(1);
							pValue->Value[0]=0;
						}
					}
					else
					{
						pValue->Value=strdup(MatchStack[N].Pos);
					}
					pValue->pNext=pValues;
					pValues=pValue;
				}
			}
			while(pEventNode)
			{
				pEventNode->pEvent->Callback(pEventNode->pEvent->ID,pEventNode->pEvent->pData,pValues);
				pEventNode=pEventNode->pNext;
			}
			// destroy values
			while(pValues)
			{
				PBLECHVALUE pNext=pValues->pNext;
				free(pValues->Value);
				delete pValues;
				pValues=pNext;
			}
			Pop();
feedermatchnoevent:
			// MATCH, ALREADY EXECUTED ANY NECESSARY EVENTS

			// continue walking tree
			if (pNode->pChildren)
			{
				pNode=pNode->pChildren;
				Push();
			}
			else if (pNode->pNext)
			{
				// restore from stack
				Peek();
				pNode=pNode->pNext;
			}
			else
			{
				Pop();
				while(pNode=pNode->pParent)
				{
					if (pNode->pNext)
					{
						pNode=pNode->pNext;
						break;
					}
					Pop();
				}
			}
			continue;
feedernomatch:
			// NO MATCH

			// continue walking tree
			if (pNode->pNext)
			{
				// position remains the same
				pNode=pNode->pNext;
			}
			else
			{
				// Pos goes down a level - dont reprocess the same child
				Pop();
				while(pNode=pNode->pParent)
				{
					if (pNode->pNext)
					{
						pNode=pNode->pNext;
						break;
					}
					Pop();
				}
			}

		}
		return Count;
#undef Push
#undef Pop
#undef Peek
	}

	inline BlechNode *FindNode(unsigned long nRoot, char *Find, eBlechStringType FindStringType)
	{
		BlechDebug("FindNode(%d,%s,%d)",nRoot,Find,FindStringType);
		BLECHASSERT(nRoot<256);
		BlechNode *pNode=Tree[nRoot];
		while(pNode)
		{
			if (FindStringType==pNode->StringType && !STRCMP(pNode->pString,Find))
				return pNode;
			pNode=pNode->pNext;
		}
		return 0;
	}

	inline BlechNode *AddNode(unsigned long nRoot, char *String, eBlechStringType StringType)
	{
		BlechDebug("AddNode(%d,%s,%d)",nRoot,String,StringType);
		BLECHASSERT(nRoot<256);
		BLECHASSERT(String);
		BlechNode *pNode = new BlechNode(0,&Tree[0],String,StringType);
		BLECHASSERT(pNode);

		pNode->pNext=Tree[nRoot];
		if (Tree[nRoot])
			Tree[nRoot]->pPrev=pNode;
		Tree[nRoot]=pNode;

		return pNode;
	}

	BlechNode *AddNode(BlechNode *pNode, char *StringBegin, char *StringEnd, eBlechStringType StringType)
	{
		BlechDebug("AddNode(%X,%s,%X,%d)",pNode,StringBegin,StringEnd,StringType);
		BLECHASSERT(StringBegin && *StringBegin);
		BLECHASSERT(StringEnd);

		unsigned long Len=(StringEnd-StringBegin);
		char *String=(char*)malloc(Len+1);
		memcpy(String,StringBegin,Len);
		String[Len]=0;

		if (!pNode)
		{
			// find and/or create new root
			unsigned long Root;
			if (StringType!=BST_NORMAL)
				Root=0;
			else
			{
				Root=(unsigned char)*String;
#ifndef BLECH_CASE_SENSITIVE
				if (Root>='a' && Root<='z')
					Root-=32;
#endif
			}
			
			if (BlechNode *pFound=FindNode(Root,String,StringType))
				return pFound;
			return AddNode(Root,String,StringType);
		}
		else
		{
			// attach to this node

			// check for existing..
			if (BlechNode *pFound=pNode->FindChild(String,StringType))
				return pFound;

			// create new
			return pNode->AddChild(String,StringType);
		}
	}

	inline void Initialize()
	{
		BlechDebug("Initialize()");
		strcpy(Version,BLECHVERSION); // store version string always
		BlechDebug(Version);
		LastID=0;
		for (unsigned long N = 0 ; N < 256 ; N++)
		{
			Tree[N]=0;
		}
	}

	BlechNode *Tree[256];

	BLECHEVENTMAP Event;

	unsigned long LastID;

	char PrintVarDelimiter;
	char ScanVarDelimiter;

	fBlechVariableValue VariableValue;
};


