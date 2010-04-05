/*****************************************************************************
    Blech.h
    Lax/Blech  
    Copyright (C) 2004-2006 Lax

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/

/*****************************************************************************
About Blech:
    Blech is a text parser API.  It uses callback system to allow it to retrieve
    current values of variables from your program, and to initiate an event from
    a successful match.  Events are added, text is fed through it, and hopefully
    you get what you want....

    Blech uses a B-Tree implementation where each node can have n nodes.  The
    data stored by each node is a portion of a string.  Nodes are split when a
    sibling is being added that begins with the same data as an existing one.
    Example:
    existing child of a node: "blech"-(possibly existing children)
    insert child to node:     "bleach"
    
    resulting nodes:          "ch"-(possibly existing children)
                        "ble"<
                              "ach"
    The end result using this implementation is a way to compare a given string to
    many strings with possibly variable portions, where a hash/map/binary tree will
    fail.

Using Blech:
    *Initialize the Blech class:
    Blech MyBlech('#'); // Use only a variable "scan"
    Blech MyBlech('#','|',VariableValue); // Use a variable "scan" and a variable "print"

    *Add events:
    MyBlech.AddEvent("Text with #variable# portion",MyEvent,0);
    
    *Create event callback:
    void __stdcall MyEvent(unsigned int ID, void * pData, PBLECHVALUE pValues)
    {
        printf("MyEvent(%d,%X,%X)",ID,pData,pValues);
        while(pValues)
        {
            printf("'%s'=>'%s'",pValues->Name,pValues->Value);
            pValues=pValues->pNext;
        }
    }

    *Feed Blech:
    MyBlech.Feed("Text with some portion");

    *Examine output:
    MyEvent(1,0,(pointer))
    'variable'=>'some'

******************************************************************************/

#pragma once
#pragma warning(disable : 4996)

#define BLECHVERSION "Lax/Blech 1.7.4"

#include <map>
#include <string>

//#ifdef WIN32

#ifdef BLECH_DEBUG_FULL
#define BLECH_DEBUG
#define BlechDebugFull BlechDebug
#else
#define BlechDebugFull
#endif

#ifdef BLECH_DEBUG
//#pragma message(BLECHVERSION)
//#pragma message("Blech: Debug Mode")
#include <windows.h>
#define BLECHASSERT(x) if (!(x)) {BlechDebug("Blech Assertion failure: %s",#x); __asm{int 3};}
static void BlechDebug(const char *szFormat, ...)
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
#define BlechDebug 
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
    char *Name;
    char *Value;
    struct _BLECHVALUE *pNext;
} BLECHVALUE, *PBLECHVALUE;

typedef struct _BLECHLISTNODE {
    class BlechNode *pNode;
    struct _BLECHLISTNODE *pNext;
} BLECHLISTNODE, *PBLECHLISTNODE;


typedef unsigned int   (__stdcall *fBlechVariableValue)(char *VarName, char *Value);
typedef void (__stdcall *fBlechCallback)(unsigned int ID, void * pData, PBLECHVALUE pValues);

typedef struct _BLECHEVENT {
    unsigned int ID;
    void * pData;
    const char *OriginalString;
    fBlechCallback Callback;

    class BlechNode *pBlechNode;
} BLECHEVENT, *PBLECHEVENT;

typedef struct _BLECHEXECUTE {
    unsigned int ID;
    void * pData;

    fBlechCallback Callback;
    struct _BLECHVALUE *pValues;
    struct _BLECHEXECUTE *pNext;
} BLECHEXECUTE, *PBLECHEXECUTE;

typedef std::map<unsigned int,PBLECHEVENT> BLECHEVENTMAP; 

typedef struct _BLECHEVENTNODE {
    PBLECHEVENT pEvent;

    struct _BLECHEVENTNODE *pNext;
    struct _BLECHEVENTNODE *pPrev;
} BLECHEVENTNODE, *PBLECHEVENTNODE;

static unsigned int Equalness(const char *StringA, const char *StringB)
{
    BlechDebugFull("Equalness(%s,%s)",StringA,StringB);
    const char *pPos=StringA;
    while(1)
    {
        if (*pPos!=*StringB)
        {
#ifndef BLECH_CASE_SENSITIVE
            if (*pPos>='a' && *pPos<='z')
            {
                if ((*pPos)-32==*StringB)
                {
                    ++pPos;
                    ++StringB;
                    continue;
                }
            }
            else if (*pPos>='A' && *pPos<='Z')
            {
                if ((*pPos)+32==*StringB)
                {
                    ++pPos;
                    ++StringB;
                    continue;
                }
            }
#endif
            unsigned int Ret=(unsigned int)(pPos-StringA);
                BlechDebugFull("Equalness returning %d",Ret);
            return Ret;
        }
        else
        {
            if (!*pPos)
            {
                unsigned int Ret=(unsigned int)(pPos-StringA);
                BlechDebugFull("Equalness returning %d",Ret);
                return Ret;
            }
        }
        ++pPos;
        ++StringB;
    }
}

class BlechNode
{
public:
    BlechNode(BlechNode *Parent, BlechNode **Root, const char *String, eBlechStringType NewStringType=BST_NORMAL)
    {
        BlechDebug("BlechNode(%X,%X,%s,%d)",Parent,Root,String,NewStringType);
        BLECHASSERT(String && *String);
        BLECHASSERT(Root);
        StringType=NewStringType;
        if (StringType==BST_NORMAL)
            Length=(unsigned int)strlen(String);
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
            {
                if (*ppRoot==this)
                    *ppRoot=pNext;
            }
        }
        if (pNext)
            pNext->pPrev=pPrev;

        // free string
        free(pString);
    }

    BlechNode *AddChild(const char *NewString, eBlechStringType NewStringType)
    {
        BlechDebug("AddChild(%s,%d)",NewString,NewStringType);
        BLECHASSERT(NewString);
        
        BlechNode *pChild = pChildren;
        while(pChild)
        {
            if (pChild->StringType==NewStringType)
            {
                if (NewStringType==BST_NORMAL)
                {
                    if (unsigned int Eq=Equalness(pChild->pString,NewString))
                    {
                        unsigned int Len=(unsigned int)strlen(NewString);
                        if (Len==Eq)
                        {
                            if (Eq==pChild->Length)
                            {
                                return pChild;
                            }
                            // old child needs to be child of new child!
                            
                            // make new child, redo pChild as child of new child...
                            BlechNode *pNode = new BlechNode(this,ppRoot,NewString,NewStringType);
                            BLECHASSERT(pNode);
                            if (pNode->pNext=pChild->pNext)
                                pNode->pNext->pPrev=pNode;
                            if (pNode->pPrev=pChild->pPrev)
                                pNode->pPrev->pNext=pNode;
                            else
                                pChildren=pNode;
                            pChild->pNext=0;
                            pChild->pPrev=0;

                            pChild->pParent=pNode;
                            pNode->pChildren=pChild;
                            memmove(pChild->pString,&pChild->pString[Eq],pChild->Length-Eq+1);
                            pChild->Length-=Eq;

                            return pNode;
                            // and return that new child
                        }
                        else if (Eq==pChild->Length)
                        {
                            // easy one
                            return pChild->AddChild(&NewString[Eq],NewStringType);
                        }
                        // both children (new and old) need to be children of a new child

                        // make new child, redo pChild as child of new child...
                        char Temp=pChild->pString[Eq];
                        pChild->pString[Eq]=0;
                        BlechNode *pNode = new BlechNode(this,ppRoot,pChild->pString,NewStringType);
                        pChild->pString[Eq]=Temp;
                        BLECHASSERT(pNode);
                        if (pNode->pNext=pChild->pNext)
                            pNode->pNext->pPrev=pNode;
                        if (pNode->pPrev=pChild->pPrev)
                            pNode->pPrev->pNext=pNode;
                        else
                            pChildren=pNode;
                        pChild->pNext=0;
                        pChild->pPrev=0;


                        pChild->pParent=pNode;
                        pNode->pChildren=pChild;

                        memmove(pChild->pString,&pChild->pString[Eq],pChild->Length-Eq+1);
                        pChild->Length-=Eq;
                        return pNode->AddChild(&NewString[Eq],NewStringType);
                        // and return a very new child!
                    }
                }
                else
                {
                    if (!strcmp(pChild->pString,NewString))
                        return pChild;
                }
            }
            pChild=pChild->pNext;
        }


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

    eBlechStringType StringType;
    char *pString;
    unsigned int Length;
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


    static const char *stristr(const char *haystack,const char *needle)
    {
        BlechDebugFull("stristr(%s,%s)",haystack,needle);
        BLECHASSERT(haystack!=0);
        BLECHASSERT(needle!=0);
        if (!needle[0])
            return haystack;

        static bool bInitialized=false;
        static char ToUpper[256];
        if (!bInitialized)
        {
            bInitialized=true;
            ToUpper[0]=0;
            for(unsigned int iliketmpvars = 1 ; iliketmpvars < 128 ; iliketmpvars++)
                ToUpper[iliketmpvars]=(char)toupper(iliketmpvars);
            for (unsigned int iliketmpvarsmore = 128 ; iliketmpvarsmore < 256 ; iliketmpvarsmore++)
            {
                ToUpper[iliketmpvarsmore]=(char)iliketmpvarsmore;
            }
        }

        const char *originalneedle=needle;
        do
        {
            char c=*haystack;
            if (!c)
                return 0;
            if (ToUpper[c]==ToUpper[*needle])
            {
                const char *start=haystack;
                do
                {
                    needle++;
                    c=*needle;
                    if (!c)
                        return start;
                    haystack++;
                    char d=*haystack;
                    if (!d)
                    {
                        return 0;
                    }
                    
                    if (ToUpper[c]!=ToUpper[d])
                        break;
                }
                while(1);

                haystack=start+1;
                needle=originalneedle;
                continue;
            }
            haystack++;
        }
        while(1);



        return 0;
    }



    void Reset()
    {
        Cleanup();
        Event.clear();
//        ExactMatch.clear();
        Initialize();
    }

    ~Blech(void)
    {
        BlechDebug("~Blech()");
        Cleanup();
    }

    unsigned int Feed(const char *Input)
    {
        BlechDebug("Feed(%s)",Input);
        if (!Input || !Input[0])
            return 0;
        unsigned int Root=(unsigned char)Input[0];

#ifndef BLECH_CASE_SENSITIVE
                if (Root>='a' && Root<='z')
                    Root-=32;
#endif
        return Chew(Tree[Root],Input)+Chew(Tree[0],Input)/*+Swallow(Input)/**/;
    }

    inline bool IsExact(const char *Text)
    {
        if (!strchr(Text,ScanVarDelimiter) && (!PrintVarDelimiter || !strchr(Text,PrintVarDelimiter)))
            return true;
        return false;
    }

    unsigned int AddEvent(const char *Text,fBlechCallback Callback,void *pData=0)
    {
        BlechDebug("AddEvent(%s,%X,%X)",Text,Callback,pData);
        BLECHASSERT(Text);
        BLECHASSERT(Callback);
        const char *pText=Text;
        const char *Part=Text;
        eBlechStringType StringType=BST_NORMAL;
        BlechNode *pNode=0;
        while(char c=*pText)
        {
            if (c==ScanVarDelimiter)
            {
                if (StringType==BST_NORMAL && pText[1]==ScanVarDelimiter)
                {
                    if (Part!=pText)
                        pNode=AddNode(pNode,Part,pText,StringType);
                    Part=&pText[1];
                    pText++;
                }
                else
                {
                    if (Part!=pText)
                        pNode=AddNode(pNode,Part,pText,StringType);
                    Part=&pText[1];
                    if (StringType==BST_SCANVAR)
                        StringType=BST_NORMAL;
                    else
                        StringType=BST_SCANVAR;
                }
            }
            else
            if (c==PrintVarDelimiter)
            {
                if (StringType==BST_NORMAL && pText[1]==PrintVarDelimiter)
                {
                    if (Part!=pText)
                        pNode=AddNode(pNode,Part,pText,StringType);
                    Part=&pText[1];
                    pText++;
                }
                else
                {
                    if (Part!=pText)
                        pNode=AddNode(pNode,Part,pText,StringType);
                    Part=&pText[1];
                    if (StringType==BST_PRINTVAR)
                        StringType=BST_NORMAL;
                    else
                        StringType=BST_PRINTVAR;
                }
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

    bool RemoveEvent(unsigned int ID)
    {
        BlechDebug("RemoveEvent(%d)",ID);
        PBLECHEVENT pEvent = Event[ID];
        if (!pEvent)
            return false;
        Event.erase(ID);
        {
            free((void*)pEvent->OriginalString);
            

            BlechNode *pNode=pEvent->pBlechNode;
            // find the PBLECHEVENTNODE for this event and remove it
            PBLECHEVENTNODE pEventNode = pNode->pEvents;
            while(pEventNode)
            {
                if (pEvent==pEventNode->pEvent)
                {
                    if (pEventNode->pNext)
                        pEventNode->pNext->pPrev=pEventNode->pPrev;
                    if (pEventNode->pPrev)
                        pEventNode->pPrev->pNext=pEventNode->pNext;
                    else
                        pNode->pEvents=pEventNode->pNext;
                    break;
                }
                pEventNode=pEventNode->pNext;
            }

            while(pNode && pNode->IsEmpty())
            {
                BlechNode *pNext=pNode->pParent;
                delete pNode;
                pNode=pNext;
            }

            delete pEvent;
        }
        return true;
    }

    char Version[32];

private:
    inline void FreeExecution(PBLECHEXECUTE pExecute)
    {
        PBLECHVALUE pValue=pExecute->pValues;
        while (pValue)
        {
            PBLECHVALUE pNext=pValue->pNext;
            free(pValue->Value);
            free(pValue->Name);
            delete pValue;
            pValue=pNext;
        }
        delete pExecute;
    }

    void ClearExecutionList(PBLECHEXECUTE *ppExecuteList)
    {
        PBLECHEXECUTE pExecuteList=*ppExecuteList;
        *ppExecuteList=0;
        while(pExecuteList)
        {
            PBLECHEXECUTE pExecuteNext=pExecuteList->pNext;
            FreeExecution(pExecuteList);
            pExecuteList=pExecuteNext;
        }
    }

    unsigned int ProcessExecutionList(PBLECHEXECUTE *ppExecuteList)
    {
        unsigned int n=0;
        PBLECHEXECUTE pExecuteList=*ppExecuteList;
        *ppExecuteList=0;
        while(pExecuteList)
        {
            n++;
            PBLECHEXECUTE pExecuteNext=pExecuteList->pNext;
            pExecuteList->Callback(pExecuteList->ID,pExecuteList->pData,pExecuteList->pValues);
            FreeExecution(pExecuteList);
            pExecuteList=pExecuteNext;
        }
        return n;
    }

    inline void Cleanup()
    {
        for (unsigned int N = 0 ; N < 256 ; N++)
        {
            delete Tree[N];
            Tree[N]=0;
        }
        for (BLECHEVENTMAP::iterator i=Event.begin(); i != Event.end(); i++)
        {
            if (PBLECHEVENT pEvent=i->second)
            {
                BLECHASSERT(pEvent);
                BlechTry(free((void*)pEvent->OriginalString));
                delete pEvent;
            }
        }
        Event.clear();
    }


    void QueueEvent(PBLECHEXECUTE *ppExecuteList,PBLECHEVENT pEvent, PBLECHVALUE pValues)
    {
        BlechDebug("QueueEvent(%X,%X)",pEvent,pValues);
        BLECHASSERT(pEvent);

        PBLECHEXECUTE pNew=new BLECHEXECUTE;
        pNew->Callback=pEvent->Callback;
        pNew->ID=pEvent->ID;
        pNew->pData=pEvent->pData;
        // make a COPY of values
        if (pValues)
        {
            PBLECHVALUE pNewValueTail=0;
            pNew->pValues=0;
            while(pValues)
            {
                PBLECHVALUE pNewValue=new BLECHVALUE;
                pNewValue->Name=strdup(pValues->Name);
                pNewValue->Value=strdup(pValues->Value);
                pNewValue->pNext=0;
                if (pNew->pValues)
                {
                    pNewValueTail->pNext=pNewValue;
                    pNewValueTail=pNewValue;
                }
                else
                {
                    pNewValueTail=pNew->pValues=pNewValue;

                }
                pValues=pValues->pNext;
            }
        }
        else
            pNew->pValues=0;

        pNew->pNext=*ppExecuteList;
        *ppExecuteList=pNew;
    }

    void QueueEvents(PBLECHEXECUTE *ppExecuteList,BlechNode *pNode, const char *Input, unsigned int InputLength)
    {
        PBLECHEVENTNODE pEventNode;
        BlechDebug("QueueEvents(%X,%s,%d)",pNode,Input,InputLength);
        BLECHASSERT(pNode);
        BLECHASSERT(Input);
        BLECHASSERT(InputLength);
        // ASSUME we have a complete match
        
        // Get forward traversal list (reverse the links, into a new list)
        PBLECHLISTNODE pList=0;
        BlechNode *pCurrent=pNode;
        int nVariableNodes=0;
        while(pCurrent)
        {
            PBLECHLISTNODE pNewHead=new BLECHLISTNODE;
            pNewHead->pNext=pList;
            pNewHead->pNode=pCurrent;
            pList=pNewHead;
            if (pCurrent->StringType==BST_SCANVAR)
                nVariableNodes++;
            pCurrent=pCurrent->pParent;
        }

        if (!nVariableNodes)
        {
            BlechDebugFull("No variable nodes");
            // if there's no variable nodes, just make sure the lengths match
            unsigned int TestLength=0;
            pCurrent=pNode;
            while(pCurrent)
            {
                TestLength+=pCurrent->Length;
                pCurrent=pCurrent->pParent;
            }
            if (TestLength==InputLength)
            {
                PBLECHEVENTNODE pEventNode=pNode->pEvents;
                while(pEventNode)
                {
                    QueueEvent(ppExecuteList,pEventNode->pEvent,0);
                    pEventNode=pEventNode->pNext;
                }
            }

            // cleanup
            while(pList)
            {
                PBLECHLISTNODE pNext=pList->pNext;
                delete pList;
                pList=pNext;
            }
            return;
        }

        // now do it forward, filling in the values. we KNOW they exist.

        char NonVariable[16384];
        char VarData[4096];
        NonVariable[0]=0;
        const char *Pos=Input;

        PBLECHVALUE pValues=0;
        PBLECHVALUE pValuesTail=0;

        BlechNode *pCurrentScanVar=0;
        while(pList)
        {
            pCurrent=pList->pNode;
            switch(pCurrent->StringType)
            {
            case BST_NORMAL:
                strcat(NonVariable,pCurrent->pString);
                break;
            case BST_PRINTVAR:
                VarData[0]=0;
                BlechTry(VariableValue(pCurrent->pString,VarData));
                strcat(NonVariable,VarData);
                break;
            case BST_SCANVAR:
                if (pCurrentScanVar)
                {
                    if (NonVariable[0])
                    {
                        const char *End=STRFIND(Pos,NonVariable);
                        if (End)
                        {
                            PBLECHVALUE pNewValue = new BLECHVALUE;
                            pNewValue->Name=strdup(pCurrentScanVar->pString);

                            unsigned int Length=End-Pos;
                            pNewValue->Value=(char*)malloc(Length+1);
                            memcpy(pNewValue->Value,Pos,Length);
                            pNewValue->Value[Length]=0;
                            pNewValue->pNext=0;
                            if (pValues)
                            {
                                pValuesTail->pNext=pNewValue;
                                pValuesTail=pNewValue;
                            }
                            else
                            {
                                pValuesTail=pValues=pNewValue;
                            }
                            
                            Pos=End+strlen(NonVariable);
                            NonVariable[0]=0;
                        }
                        else
                        {
                            // not a real match. goodbye!
                            // NOTE: this can be relatively normal, it is not a direct indication of an error
                            goto queueeventscleanup;
                        }
                    }
                    else
                    {
                        PBLECHVALUE pNewValue = new BLECHVALUE;
                        pNewValue->Name=strdup(pCurrentScanVar->pString);
                        pNewValue->Value=(char*)malloc(1);
                        pNewValue->Value[0]=0;
                        pNewValue->pNext=0;
                        if (pValues)
                        {
                            pValuesTail->pNext=pNewValue;
                            pValuesTail=pNewValue;
                        }
                        else
                        {
                            pValuesTail=pValues=pNewValue;
                        }
                    }
                }
                else
                {
                    unsigned int NonVariableLength=strlen(NonVariable);
                    if (STRNCMP(NonVariable,Pos,NonVariableLength))
                    {
                        // not a real match. goodbye!
                        // NOTE: this can be relatively normal, it is not a direct indication of an error
                        goto queueeventscleanup;
                    }
                    Pos+=NonVariableLength;
                    NonVariable[0]=0;
                }
                pCurrentScanVar=pCurrent;
                break;
            }
            
            
            PBLECHLISTNODE pNext=pList->pNext;
            delete pList;
            pList=pNext;
        }

        if (pCurrentScanVar)
        {
            if (NonVariable[0])
            {
                const char *End=&Input[InputLength]-strlen(NonVariable);
                unsigned int Length=End-Pos;
                if (STRCMP(&Pos[Length],NonVariable))
                {
                    goto queueeventscleanup;
                }

                PBLECHVALUE pNewValue = new BLECHVALUE;
                pNewValue->Name=strdup(pCurrentScanVar->pString);
                
                pNewValue->Value=(char*)malloc(Length+1);
                memcpy(pNewValue->Value,Pos,Length);
                pNewValue->Value[Length]=0;
                pNewValue->pNext=0;

                if (pValues)
                {
                    pValuesTail->pNext=pNewValue;
                    pValuesTail=pNewValue;
                }
                else
                {
                    pValuesTail=pValues=pNewValue;
                }
                
                Pos=End;
                NonVariable[0]=0;
            }
            else
            {
                PBLECHVALUE pNewValue = new BLECHVALUE;
                pNewValue->Name=strdup(pCurrentScanVar->pString);
                pNewValue->Value=strdup(Pos);
                pNewValue->pNext=0;
                if (pValues)
                {
                    pValuesTail->pNext=pNewValue;
                    pValuesTail=pNewValue;
                }
                else
                {
                    pValuesTail=pValues=pNewValue;
                }
            }
        }
        else if (NonVariable[0])
        {
            if (STRCMP(NonVariable,Pos))
            {
                // not a real match. goodbye!
                // NOTE: this can be relatively normal, it is not a direct indication of an error
                goto queueeventscleanup;
            }
        }

        // add to execution list
        pEventNode=pNode->pEvents;
        while(pEventNode)
        {
            QueueEvent(ppExecuteList,pEventNode->pEvent,pValues);
            pEventNode=pEventNode->pNext;
        }

        // cleanup
queueeventscleanup:
        while(pValues)
        {
            PBLECHVALUE pNext=pValues->pNext;
            free(pValues->Name);
            free(pValues->Value);
            delete pValues;
            pValues=pNext;
        }

        while(pList)
        {
            PBLECHLISTNODE pNext=pList->pNext;
            delete pList;
            pList=pNext;
        }
    }

    struct MatchPos
    {
        const char *Pos;
        BlechNode *pNode;
    };

    unsigned int Chew(BlechNode *pNode,const char *Input)
    {
        BlechDebug("Chew(%X,%s)",pNode,Input);
        BLECHASSERT(Input);
        if (!pNode)
            return 0;
        PBLECHEXECUTE pExecuteList=0;
        unsigned int Length=(unsigned int)strlen(Input);
        const char *pEnd=&Input[Length];
        char VarData[4096];
        
#define Push() {    BLECHASSERT(PLP<99) CurrentPos.pNode=pNode;MatchStack[PLP]=CurrentPos;    PLP++;    }
#define Pop()  {    BLECHASSERT(PLP>0);PLP--; CurrentPos=MatchStack[PLP];pNode=CurrentPos.pNode;    }
#define Peek() {    if (!PLP) goto chewcomplete; CurrentPos=MatchStack[PLP-1];        }

        MatchPos MatchStack[100];
        MatchPos CurrentPos;
        unsigned char PLP=0;
        memset(&MatchStack[0],0,sizeof(MatchStack));

        CurrentPos.Pos=Input;
        Push();
        CurrentPos.pNode=pNode;

        while(pNode)
        {
            BLECHASSERT(PLP>0);
            BlechDebugFull("PLP=%d",PLP);
            BlechDebugFull("CurrentPos='%s', pNode=%X",CurrentPos.Pos,CurrentPos.pNode);
            // determine match
            {
                switch(pNode->StringType)
                {
                case BST_NORMAL:
                    BlechDebugFull("BST_NORMAL");
                    if (CurrentPos.Pos+pNode->Length<pEnd)
                    {
                        if (const char *pFound=STRFIND(CurrentPos.Pos,pNode->pString))
                        { // what if we find this multiple times? need to find the right one, depending on the children
                            CurrentPos.Pos=&pFound[pNode->Length];
                            if (!CurrentPos.Pos[0])
                            {
                                goto feedermatchdoevents;
                            }
                            goto feedermatchnoevent;
                        }
                    }
                    else if (CurrentPos.Pos+pNode->Length==pEnd && !STRNCMP(pNode->pString,CurrentPos.Pos,pNode->Length))
                    {
                        // match. do events?
                        CurrentPos.Pos+=pNode->Length;
                        if (!CurrentPos.Pos[0])
                        {
                            goto feedermatchdoevents;
                        }
                        goto feedermatchnoevent;
                    }
                    BlechDebugFull("BST_NORMAL => NO MATCH");
                    goto feedernomatch;
                case BST_PRINTVAR:
                    BlechDebugFull("BST_PRINTVAR");
                    // variable data of unknown size
                    BlechTry(pNode->Length=VariableValue(pNode->pString,VarData));
                    BlechDebugFull("Variable value '%s' length %d",VarData,pNode->Length);
                    if (!pNode->Length)
                    {
                        // implied match
                        MatchStack[PLP+1].pNode=0;
                        if (!pNode->pChildren || pNode->pEvents)
                        {
                            goto feedermatchdoevents;
                        }
                        goto feedermatchnoevent;
                    }
                    BLECHASSERT(VarData[0]);
                    if (CurrentPos.Pos+pNode->Length<pEnd)
                    {
                            if (const char *pFound=STRFIND(CurrentPos.Pos,VarData))
                            { // what if we find this multiple times? need to find the right one, depending on the children
                                CurrentPos.Pos=&pFound[pNode->Length];
                                if (!CurrentPos.Pos[0])
                                {
                                    goto feedermatchdoevents;
                                }
                                goto feedermatchnoevent;
                            }
                    }
                    else if (CurrentPos.Pos+pNode->Length==pEnd && !STRNCMP(VarData,CurrentPos.Pos,pNode->Length))
                    {
                        // match. do events?
                        CurrentPos.Pos+=pNode->Length;
                        if (!CurrentPos.Pos[0])
                        {
                            goto feedermatchdoevents;
                        }
                        goto feedermatchnoevent;
                    }
                    BlechDebugFull("BST_PRINTVAR => NO MATCH");
                    goto feedernomatch;
                case BST_SCANVAR:
                    BlechDebugFull("BST_SCANVAR");
                    // implied match
                    MatchStack[PLP+1].pNode=0;
                    if (!pNode->pChildren || pNode->pEvents)
                    {
                        goto feedermatchdoevents;
                    }
                    goto feedermatchnoevent;
                }
            }
feedermatchdoevents:
            {
                BlechDebug("feedermatchdoevents");
                QueueEvents(&pExecuteList,pNode,Input,Length);
            }
feedermatchnoevent:
            {
                BlechDebugFull("feedermatchnoevent");
                // MATCH, ALREADY EXECUTED ANY NECESSARY EVENTS
                // continue walking tree
                if (pNode->pChildren)
                {
                    Push();
                    pNode=pNode->pChildren;
                }
                else if (pNode->pNext)
                {
                    // restore from stack
//                    Pop();
                    Peek();
                    pNode=pNode->pNext;
                }
                else
                {
                    Pop();
                    Peek();
                    while(1)
                    {
                        if (pNode->pNext)
                        {
                            pNode=pNode->pNext;
                            break;
                        }

                        if (PLP>1)
                        {
                            Pop();
                            Peek();
                        }
                        else
                        {
                            pNode=0;
                            break;
                        }
                    }

                }
                CurrentPos.pNode=pNode;
                continue;
            }
feedernomatch:
            {
                // NO MATCH

                // continue walking tree
                if (pNode->pNext)
                {
                    BlechDebugFull("SAME LEVEL, NEXT");
                    // position remains the same
//                    Pop();
                    Peek();
                    pNode=pNode->pNext;
                }
                else
                {
                    BlechDebugFull("PREVIOUS LEVEL, NEXT");
                    // Pos goes down a level - dont reprocess the same child
                    Pop();
                    Peek();
                    while(1)
                    {
                        if (pNode->pNext)
                        {
                            pNode=pNode->pNext;
                            break;
                        }
                        if (PLP>1)
                        {
                            Pop();
                            Peek();
                        }
                        else
                        {
                            pNode=0;
                            break;
                        }
                    }
                }
                CurrentPos.pNode=pNode;
            }
        }
chewcomplete:
        // execute any queued events
        unsigned int Count=ProcessExecutionList(&pExecuteList);
        BlechDebug("Chew returns %d",Count);
        return Count;
#undef Push
#undef Pop
#undef Peek
    }

    BlechNode *AddNode(unsigned int nRoot, const char *String, eBlechStringType StringType)
    {
        BlechDebug("AddNode(%d,%s,%d)",nRoot,String,StringType);
        BLECHASSERT(nRoot<256);
        BLECHASSERT(String);


        BlechNode *pChild = Tree[nRoot];
        while(pChild)
        {
            if (pChild->StringType==StringType)
            {
                if (StringType==BST_NORMAL)
                {
                    if (unsigned int Eq=Equalness(pChild->pString,String))
                    {
                        unsigned int Len=(unsigned int)strlen(String);
                        if (Len==Eq)
                        {
                            if (Eq==pChild->Length)
                            {
                                return pChild;
                            }
                            // old child needs to be child of new child!
                            
                            // make new child, redo pChild as child of new child...
                            BlechNode *pNode = new BlechNode(0,&Tree[nRoot],String,StringType);
                            BLECHASSERT(pNode);
                            if (pNode->pNext=pChild->pNext)
                                pNode->pNext->pPrev=pNode;
                            if (pNode->pPrev=pChild->pPrev)
                                pNode->pPrev->pNext=pNode;
                            else
                                Tree[nRoot]=pNode;
                            pChild->pNext=0;
                            pChild->pPrev=0;

                            pChild->pParent=pNode;
                            pNode->pChildren=pChild;
                            memmove(pChild->pString,&pChild->pString[Eq],pChild->Length-Eq+1);
                            pChild->Length-=Eq;

                            return pNode;
                            // and return that new child
                        }
                        else if (Eq==pChild->Length)
                        {
                            // easy one
                            return pChild->AddChild(&String[Eq],StringType);
                        }
                        // both children (new and old) need to be children of a new child

                        // make new child, redo pChild as child of new child...
                        char Temp=pChild->pString[Eq];
                        pChild->pString[Eq]=0;
                        BlechNode *pNode = new BlechNode(0,&Tree[nRoot],pChild->pString,StringType);
                        pChild->pString[Eq]=Temp;
                        BLECHASSERT(pNode);
                        if (pNode->pNext=pChild->pNext)
                            pNode->pNext->pPrev=pNode;
                        if (pNode->pPrev=pChild->pPrev)
                            pNode->pPrev->pNext=pNode;
                        else
                            Tree[nRoot]=pNode;
                        pChild->pNext=0;
                        pChild->pPrev=0;


                        pChild->pParent=pNode;
                        pNode->pChildren=pChild;

                        memmove(pChild->pString,&pChild->pString[Eq],pChild->Length-Eq+1);
                        pChild->Length-=Eq;
                        return pNode->AddChild(&String[Eq],StringType);
                        // and return a very new child!
                    }
                }
                else
                {
                    if (!strcmp(pChild->pString,String))
                        return pChild;
                }
            }
            pChild=pChild->pNext;
        }



        BlechNode *pNode = new BlechNode(0,&Tree[nRoot],String,StringType);
        BLECHASSERT(pNode);

        pNode->pNext=Tree[nRoot];
        if (Tree[nRoot])
            Tree[nRoot]->pPrev=pNode;
        Tree[nRoot]=pNode;

        return pNode;
    }

    BlechNode *AddNode(BlechNode *pNode, const char *StringBegin, const char *StringEnd, eBlechStringType StringType)
    {
        BlechDebug("AddNode(%X,%s,%X,%d)",pNode,StringBegin,StringEnd,StringType);
        BLECHASSERT(StringBegin && *StringBegin);
        BLECHASSERT(StringEnd);

        unsigned int Len=(unsigned int)(StringEnd-StringBegin);
        char *String=(char*)malloc(Len+1);
        memcpy(String,StringBegin,Len);
        String[Len]=0;

        if (!pNode)
        {
            // find and/or create new root
            unsigned int Root;
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
            
//            if (BlechNode *pFound=FindNode(Root,String,StringType))
//                return pFound;
            BlechNode *pNew=AddNode(Root,String,StringType);
            free(String);
            return pNew;
        }
        else
        {
            // attach to this node

            // create new
            BlechNode *pNew=pNode->AddChild(String,StringType);
            free(String);
            return pNew;
        }
    }

    inline void Initialize()
    {
        BlechDebugFull("Initialize()");
        strcpy(Version,BLECHVERSION); // store version string always
        BlechDebug(Version);
        LastID=0;
        for (unsigned int N = 0 ; N < 256 ; N++)
        {
            Tree[N]=0;
        }
    }

    BlechNode *Tree[256];

//    std::map<std::string,PBLECHEVENTNODE> ExactMatch;

    BLECHEVENTMAP Event;

    unsigned int LastID;

    char PrintVarDelimiter;
    char ScanVarDelimiter;

    fBlechVariableValue VariableValue;
};


