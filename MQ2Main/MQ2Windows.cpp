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
//#define DEBUG_TRY

#include "MQ2Main.h"
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map<string,unsigned long> WindowMap;



PCHAR szClickNotification[] = { 
    "leftmouse",        //0
    "leftmouseup",      //1
    "leftmouseheld",    //2
    "leftmouseheldup",  //3
    "rightmouse",       //4
    "rightmouseup",     //5
    "rightmouseheld",   //6
    "rightmouseheldup", //7
}; 

struct _WindowInfo
{
    char Name[128];
    CXWnd *pWnd;
    CXWnd **ppWnd;
};

CIndex <_WindowInfo*> WindowList(10);



bool GenerateMQUI();
void DestroyMQUI();

#if 0
class SetScreenHook
{
public:
    void SetScreen_Detour(CXStr *pName)
    {
        CHAR Name[MAX_STRING]={0};
        GetCXStr(pName->Ptr,Name,MAX_STRING);
        string WindowName=Name;
        MakeLower((WindowName));

        unsigned long N=WindowMap[WindowName];
        if (N)
        {
            N--;
            _WindowInfo *pWnd = WindowList[N];
            pWnd->pWnd=(CXWnd*)this;
            pWnd->ppWnd=0;
            //DebugSpew("Updating WndNotification target '%s'",Name);
        }
        else
        {
            _WindowInfo *pWnd = new _WindowInfo;
            strcpy(pWnd->Name,Name);
            pWnd->pWnd=(CXWnd*)this;
            pWnd->ppWnd=0;

            N=WindowList.GetUnused();
            WindowList[N]=pWnd;

            WindowMap[WindowName]=N+1;
            //DebugSpew("Adding WndNotification target '%s'",Name);
        }
        SetScreen_Trampoline(pName);
    }
    void SetScreen_Trampoline(CXStr*);
};
DETOUR_TRAMPOLINE_EMPTY(void SetScreenHook::SetScreen_Trampoline(CXStr*));
#endif

class CSidlInitHook
{
public:
    void Init_Trampoline(class CXStr*pName,int A);
    void Init_Detour(class CXStr*pName,int A)
    {
        CHAR Name[MAX_STRING]={0};
        GetCXStr(pName->Ptr,Name,MAX_STRING);
        string WindowName=Name;
        MakeLower((WindowName));

        unsigned long N=WindowMap[WindowName];
        if (N)
        {
            N--;
            _WindowInfo *pWnd = WindowList[N];
            pWnd->pWnd=(CXWnd*)this;
            pWnd->ppWnd=0;
            DebugSpew("Updating WndNotification target '%s'",Name);
        }
        else
        {
            _WindowInfo *pWnd = new _WindowInfo;
            strcpy(pWnd->Name,Name);
            pWnd->pWnd=(CXWnd*)this;
            pWnd->ppWnd=0;

            N=WindowList.GetUnused();
            WindowList[N]=pWnd;

            WindowMap[WindowName]=N+1;
            DebugSpew("Adding WndNotification target '%s'",Name);
        }
        Init_Trampoline(pName, A);
    }
};
DETOUR_TRAMPOLINE_EMPTY(void CSidlInitHook::Init_Trampoline(class CXStr*,int));


class CXWndManagerHook
{
public:
    int RemoveWnd_Detour(class CXWnd *pWnd)
    {
        if (pWnd)
        {
            for (unsigned long N = 0 ; N < WindowList.Size ; N++)
                if (_WindowInfo* pInfo=WindowList[N])
                {
                    if (pWnd==pInfo->pWnd)
                    {
                        //DebugSpew("Removing WndNotification target '%s'",pInfo->Name);
                        string Name=pInfo->Name;
                        MakeLower(Name);
                        WindowMap[Name]=0;
                        delete pInfo;
                        WindowList[N]=0;
                        break;
                    }
                }
        }
        return RemoveWnd_Trampoline(pWnd);
    }
    int RemoveWnd_Trampoline(class CXWnd *);

};
DETOUR_TRAMPOLINE_EMPTY(int CXWndManagerHook::RemoveWnd_Trampoline(class CXWnd *));


class CXMLSOMDocumentBaseHook
{
public:
    int XMLRead(CXStr *A, CXStr *B, CXStr *C, CXStr *D)
    {
        char Temp[256]={0};
        GetCXStr(C->Ptr,Temp,256);
        DebugSpew("XMLRead(%s)",Temp);
        if (!stricmp("EQUI.xml",Temp))
        {
            if (GenerateMQUI())
            {
                SetCXStr(&C->Ptr,"MQUI.xml");
                int Ret=XMLRead_Trampoline(A,B,C,D);
                DestroyMQUI();
                return Ret;
            }
        }
        return XMLRead_Trampoline(A,B,C,D);
    }
    int XMLRead_Trampoline(CXStr *A, CXStr *B, CXStr *C, CXStr *D);
};
DETOUR_TRAMPOLINE_EMPTY(int CXMLSOMDocumentBaseHook::XMLRead_Trampoline(CXStr *A, CXStr *B, CXStr *C, CXStr *D)); 


#ifndef ISXEQ
VOID ListWindows(PSPAWNINFO pChar, PCHAR szLine);
VOID WndNotify(PSPAWNINFO pChar, PCHAR szLine);
VOID ItemNotify(PSPAWNINFO pChar, PCHAR szLine);
VOID ListItemSlots(PSPAWNINFO pChar, PCHAR szLine);
#else
int ListWindows(int argc, char *argv[]);
int WndNotify(int argc, char *argv[]);
int ItemNotify(int argc, char *argv[]);
int ListItemSlots(int argc, char *argv[]); 
#endif

#ifndef ISXEQ_LEGACY

void InitializeMQ2Windows()
{
    int i;
    DebugSpew("Initializing MQ2 Windows");

    extern PCHAR szItemSlot[];

    for(i=0;i<NUM_INV_SLOTS;i++)
        ItemSlotMap[szItemSlot[i]]=i;

    CHAR szOut[MAX_STRING]={0};

#define AddSlotArray(name,count,start)    \
    for (i = 0 ; i < count ; i++)\
    {\
    sprintf(szOut,#name"%d",i+1);\
    ItemSlotMap[szOut]=start+i;\
    }
    AddSlotArray(bank,24,2000);
    AddSlotArray(sharedbank,2,2500);
    AddSlotArray(trade,16,3000);
    AddSlotArray(world,10,4000);
    AddSlotArray(enviro,10,4000);
    AddSlotArray(loot,31,5000);
    AddSlotArray(merchant,80,6000);
    AddSlotArray(bazaar,80,7000);
    AddSlotArray(inspect,31,8000);
#undef AddSlotArray

    EzDetour(CXMLSOMDocumentBase__XMLRead,&CXMLSOMDocumentBaseHook::XMLRead,&CXMLSOMDocumentBaseHook::XMLRead_Trampoline);
    EzDetour(CSidlScreenWnd__Init1,&CSidlInitHook::Init_Detour,&CSidlInitHook::Init_Trampoline);
    EzDetour(CXWndManager__RemoveWnd,&CXWndManagerHook::RemoveWnd_Detour,&CXWndManagerHook::RemoveWnd_Trampoline);

#ifndef ISXEQ
    AddCommand("/windows",ListWindows,false,true,false);
    AddCommand("/notify",WndNotify,false,true,false);
    AddCommand("/itemnotify",ItemNotify,false,true,false);
    AddCommand("/itemslots",ListItemSlots,false,true,false);
#else
    pISInterface->AddCommand("EQWindows",ListWindows);
    pISInterface->AddCommand("EQNotify",WndNotify);
    pISInterface->AddCommand("EQItemNotify",ItemNotify);
    pISInterface->AddCommand("EQItemSlots",ListItemSlots);
#endif 

    if (pWndMgr)
    {
        CHAR Name[MAX_STRING]={0};
        PCSIDLWND *ppWnd=((_CXWNDMGR*)pWndMgr)->pWindows;
        PCSIDLWND pWnd=*ppWnd;
        DWORD count = ((_CXWNDMGR*)pWndMgr)->Count; 

        while(pWnd = *ppWnd)
        {
            if(count-- == 0) 
                break;

            // process window
            if (CXMLData *pXMLData=((CXWnd*)pWnd)->GetXMLData())
            {
                if (pXMLData->Type==UI_Screen)
                {
                    GetCXStr(pXMLData->Name.Ptr,Name,MAX_STRING);
                    string WindowName=Name;
                    MakeLower((WindowName));

                    unsigned long N=WindowMap[WindowName];
                    if (N)
                    {
                        N--;
                        _WindowInfo *pNewWnd = WindowList[N];
                        pNewWnd->pWnd=(CXWnd*)pWnd;
                        pNewWnd->ppWnd=0;
                        //DebugSpew("Updating WndNotification target '%s'",Name);
                    }
                    else
                    {
                        _WindowInfo *pNewWnd = new _WindowInfo;
                        strcpy(pNewWnd->Name,Name);
                        pNewWnd->pWnd=(CXWnd*)pWnd;
                        pNewWnd->ppWnd=0;

                        N=WindowList.GetUnused();
                        WindowList[N]=pNewWnd;

                        WindowMap[WindowName]=N+1;
                        //DebugSpew("Adding WndNotification target '%s'",Name);
                    }
                }
            }
            ppWnd++;
        }
    }
}

void ShutdownMQ2Windows()
{
    DebugSpew("Shutting down MQ2 Windows");
#ifndef ISXEQ
    RemoveCommand("/windows");
    RemoveCommand("/notify");
    RemoveCommand("/itemnotify");
    RemoveCommand("/itemslots");
#else
    pISInterface->RemoveCommand("EQWindows");
    pISInterface->RemoveCommand("EQNotify");
    pISInterface->RemoveCommand("EQItemNotify");
    pISInterface->RemoveCommand("EQItemSlots");
#endif 
    RemoveDetour(CXMLSOMDocumentBase__XMLRead);
    RemoveDetour(CSidlScreenWnd__Init1);
    RemoveDetour(CXWndManager__RemoveWnd);
    WindowList.Cleanup();
}

bool GenerateMQUI()
{
    // create EverQuest\uifiles\default\MQUI.xml
    PCHARINFO       pCharInfo = NULL;
    CHAR            szFilename[MAX_PATH] = { 0 };
    CHAR            szOrgFilename[MAX_PATH] = { 0 };
    CHAR            UISkin[MAX_STRING] = { 0 };
    char            Buffer[2048];
    FILE           *forg,
        *fnew;

    if (!pXMLFiles) {
        DebugSpew
            ("GenerateMQUI::Not Generating MQUI.xml, no files in our list");
        return false;
    }
    sprintf(UISkin, "default");
    sprintf(szOrgFilename, "%s\\uifiles\\%s\\EQUI.xml", gszEQPath, UISkin);
    sprintf(szFilename, "%s\\uifiles\\%s\\MQUI.xml", gszEQPath, UISkin);

    DebugSpew("GenerateMQUI::Generating %s", szFilename);

    forg = fopen(szOrgFilename, "rt");
    if (!forg) {
        DebugSpew("GenerateMQUI::could not open %s", szOrgFilename);
        return false;
    }
    fnew = fopen(szFilename, "wt");
    if (!fnew) {
        DebugSpew("GenerateMQUI::could not open %s", szFilename);
        fclose(forg);
        return false;
    }
    while (fgets(Buffer, 2048, forg)) {
        if (strstr(Buffer, "</Composite>")) {
            DebugSpew("GenerateMQUI::Inserting our xml files");
            PMQXMLFILE      pFile = pXMLFiles;
            while (pFile) {
                DebugSpew("GenerateMQUI::Inserting %s",pFile->szFilename);
                fprintf(fnew, "<Include>%s</Include>\n",
                    pFile->szFilename);
                pFile = pFile->pNext;
            }
        }
        fprintf(fnew, "%s", Buffer);
    }
    fclose(fnew);
    fclose(forg);

    if ((pCharInfo = GetCharInfo()) != NULL) {
        sprintf(szFilename, "%s\\UI_%s_%s.ini", gszEQPath, pCharInfo->Name,
            EQADDR_SERVERNAME);
        GetPrivateProfileString("Main", "UISkin", "default", UISkin,
            MAX_STRING, szFilename);

        if (strcmp(UISkin, "default")) {

            sprintf(szOrgFilename, "%s\\uifiles\\%s\\EQUI.xml",
                gszEQPath, UISkin);
            sprintf(szFilename, "%s\\uifiles\\%s\\MQUI.xml", gszEQPath,
                UISkin);

            DebugSpew("GenerateMQUI::Generating %s", szFilename);

            forg = fopen(szOrgFilename, "rt");
            if (!forg) {
                DebugSpew("GenerateMQUI::could not open %s (non-fatal)", szOrgFilename);
                sprintf(szOrgFilename, "%s\\uifiles\\%s\\EQUI.xml",
                    gszEQPath, "default");
                forg = fopen(szOrgFilename, "rt");
                if (!forg) {
                    DebugSpew("GenerateMQUI::could not open %s", szOrgFilename);
                    DebugSpew("GenerateMQUI::giving up");
                    return false;
                }
            }
            fnew = fopen(szFilename, "wt");
            if (!fnew) {
                DebugSpew("GenerateMQUI::could not open %s", szFilename);
                fclose(forg);
                return false;
            }
            while (fgets(Buffer, 2048, forg)) {
                if (strstr(Buffer, "</Composite>")) {
                    //DebugSpew("GenerateMQUI::Inserting our xml files");
                    PMQXMLFILE      pFile = pXMLFiles;
                    while (pFile) {
                        //DebugSpew("GenerateMQUI::Inserting %s",pFile->szFilename);
                        fprintf(fnew, "<Include>%s</Include>\n",
                            pFile->szFilename);
                        pFile = pFile->pNext;
                    }
                }
                fprintf(fnew, "%s", Buffer);
            }
            fclose(fnew);
            fclose(forg);
        }
    }

    return true;
}

void DestroyMQUI()
{
    // delete MQUI.xml files.
    PCHARINFO       pCharInfo = NULL;
    CHAR            szFilename[MAX_PATH] = { 0 };
    CHAR            UISkin[MAX_STRING] = { 0 };

    sprintf(szFilename, "%s\\uifiles\\%s\\MQUI.xml", gszEQPath, "default");
    DebugSpew("DestroyMQUI: removing file %s", szFilename);
    remove(szFilename);

    if ((pCharInfo = GetCharInfo()) != NULL) {
        sprintf(szFilename, "%s\\UI_%s_%s.ini", gszEQPath, pCharInfo->Name,
            EQADDR_SERVERNAME);
        //DebugSpew("UI File: %s", szFilename);
        GetPrivateProfileString("Main", "UISkin", "default", UISkin,
            MAX_STRING, szFilename);
        //DebugSpew("UISkin=%s", UISkin);

        sprintf(szFilename, "%s\\uifiles\\%s\\MQUI.xml", gszEQPath,
            UISkin);
        DebugSpew("DestroyMQUI: removing file %s", szFilename);
        remove(szFilename);
    }
}

void AddXMLFile(const char *filename)
{
    PMQXMLFILE      pFile = pXMLFiles;
    PMQXMLFILE      pLast = 0;
    while (pFile) {
        if (!stricmp(pFile->szFilename, filename))
            return;        // already there.
        pLast = pFile;
        pFile = pFile->pNext;
    }
    CHAR            szBuffer[MAX_PATH] = { 0 };
    PCHARINFO       pCharInfo = NULL;
    CHAR            szFilename[MAX_PATH] = { 0 };
    CHAR            UISkin[MAX_STRING] = { 0 };
    sprintf(UISkin, "default");

    if ((pCharInfo = GetCharInfo()) != NULL) {
        sprintf(szFilename, "%s\\UI_%s_%s.ini", gszEQPath, pCharInfo->Name,
            EQADDR_SERVERNAME);
        GetPrivateProfileString("Main", "UISkin", "default", UISkin,
            MAX_STRING, szFilename);
    }
    sprintf(szBuffer, "%s\\uifiles\\%s\\%s", gszEQPath, UISkin, filename);

    if (!_FileExists(szBuffer)) {
        sprintf(szBuffer, "%s\\uifiles\\%s\\%s", gszEQPath, "default",
            filename);
        if (!_FileExists(szBuffer)) {
            WriteChatf
                ("UI file %s not found in either uifiles\\%s or uifiles\\default.  Please copy it there, reload the UI, and reload this plugin.",
                filename, UISkin);
            return;
        }
    }

    DebugSpew("Adding XML File %s", filename);
    if (gGameState == GAMESTATE_INGAME) {
        WriteChatf
            ("UI file %s added, you must reload your UI for this to take effect.",
            filename);

    }

    pFile = new MQXMLFILE;
    pFile->pLast = pLast;
    if (pLast)
        pLast->pNext = pFile;
    else
        pXMLFiles = pFile;
    pFile->pNext = 0;
    strcpy(pFile->szFilename, filename);
}

void RemoveXMLFile(const char *filename)
{
    PMQXMLFILE      pFile = pXMLFiles;
    while (pFile) {
        if (!stricmp(pFile->szFilename, filename)) {
            DebugSpew("Removing XML File %s", filename);
            if (pFile->pLast)
                pFile->pLast->pNext = pFile->pNext;
            else
                pXMLFiles = pFile->pNext;
            if (pFile->pNext)
                pFile->pNext->pLast = pFile->pLast;
            delete pFile;
            return;
        }
        pFile = pFile->pNext;
    }
}


CXWnd *FindMQ2Window(PCHAR WindowName)
{
    _WindowInfo *pInfo = NULL;

    string Name=WindowName;
    MakeLower(Name);

    unsigned long N = WindowMap[Name];
    if (!N)
    {
        PCONTENTS pPack=0;
        if (!strnicmp(WindowName,"bank",4))
        {
            unsigned long nPack=atoi(&WindowName[4]);
            if (nPack && nPack<=NUM_BANK_SLOTS)
            {
                pPack=((PCHARINFO)pCharData)->pBankArray->Bank[nPack-1];
            }
        }
        else if (!strnicmp(WindowName,"pack",4))
        {
            unsigned long nPack=atoi(&WindowName[4]);
            if (nPack && nPack<=10)
            {
                pPack=GetCharInfo2()->pInventoryArray->Inventory.Pack[nPack-1];
            }
        }
        else if (!stricmp(WindowName,"enviro"))
        {
            pPack=((PEQ_CONTAINERWND_MANAGER)pContainerMgr)->pWorldContents;
        }
        if (!pPack)
        {
            return 0;
        }
        return (CXWnd*)FindContainerForContents(pPack);

    }
    N--;

    pInfo=WindowList[N];
    if (!pInfo)
    {
        WindowMap[Name]=0;
        return 0;
    }

    if (pInfo->pWnd)
    {
        return pInfo->pWnd;
    }
    else
    {
        if (pInfo->ppWnd)
        {
            return *pInfo->ppWnd;
        }
        else
        {
            WindowMap[Name]=0;
            delete pInfo;
            WindowList[N]=0;
            WindowMap[Name]=0;
            return 0;
        }
    }

    return 0;
}

bool SendWndClick2(CXWnd *pWnd, PCHAR ClickNotification)
{
    if (!pWnd)
        return false;
    for (unsigned long i = 0 ; i < 8 ; i++)
    {
        if (!stricmp(szClickNotification[i],ClickNotification))
        {
            DebugTry(CXRect rect= pWnd->GetScreenRect());
            DebugTry(CXPoint pt=rect.CenterPoint());
            switch(i)
            {
            case 0:
                DebugTry(pWnd->HandleLButtonDown(&pt,0));
                break;
            case 1:
                DebugTry(pWnd->HandleLButtonDown(&pt,0));
                DebugTry(pWnd->HandleLButtonUp(&pt,0));
                break;
            case 2:
                DebugTry(pWnd->HandleLButtonDown(&pt,0));
                DebugTry(pWnd->HandleLButtonHeld(&pt,0));
                break;
            case 3:
                DebugTry(pWnd->HandleLButtonDown(&pt,0));
                DebugTry(pWnd->HandleLButtonHeld(&pt,0));
                DebugTry(pWnd->HandleLButtonUpAfterHeld(&pt,0));
                break;
            case 4:
                DebugTry(pWnd->HandleRButtonDown(&pt,0));
                break;
            case 5:
                DebugTry(pWnd->HandleRButtonDown(&pt,0));
                DebugTry(pWnd->HandleRButtonUp(&pt,0));
                break;
            case 6:
                DebugTry(pWnd->HandleRButtonDown(&pt,0));
                DebugTry(pWnd->HandleRButtonHeld(&pt,0));
                break;
            case 7:
                DebugTry(pWnd->HandleRButtonDown(&pt,0));
                DebugTry(pWnd->HandleRButtonHeld(&pt,0));
                DebugTry(pWnd->HandleRButtonUpAfterHeld(&pt,0));
                break;
            default:
                return false;
            };
            gMouseEventTime = GetFastTime();
            return true;
        }
    }
    return false;
}

#define MacroError printf
bool SendWndClick(PCHAR WindowName, PCHAR ScreenID, PCHAR ClickNotification)
{
    CXWnd *pWnd=FindMQ2Window(WindowName);
    if (!pWnd)
    {
        MacroError("Window '%s' not available.",WindowName);
        return false;
    }
    if (ScreenID && ScreenID[0] && ScreenID[0]!='0')
    {
        CXWnd *pButton=((CSidlScreenWnd*)(pWnd))->GetChildItem(ScreenID);
        if (!pButton)
        {
            MacroError("Window '%s' child '%s' not found.",WindowName,ScreenID);
            return false;
        }
        pWnd=pButton;
    }

    for (unsigned long i = 0 ; i < 8 ; i++)
    {
        if (!stricmp(szClickNotification[i],ClickNotification))
        {
            CXRect rect= pWnd->GetScreenRect();
            CXPoint pt=rect.CenterPoint();
            switch(i)
            {
            case 0:
                pWnd->HandleLButtonDown(&pt,0);
                break;
            case 1:
                pWnd->HandleLButtonDown(&pt,0);
                pWnd->HandleLButtonUp(&pt,0);
                break;
            case 2:
                pWnd->HandleLButtonHeld(&pt,0);
                break;
            case 3:
                pWnd->HandleLButtonDown(&pt,0);
                pWnd->HandleLButtonHeld(&pt,0);
                pWnd->HandleLButtonUpAfterHeld(&pt,0);
                break;
            case 4:
                pWnd->HandleRButtonDown(&pt,0);
                break;
            case 5:
                pWnd->HandleRButtonDown(&pt,0);
                pWnd->HandleRButtonUp(&pt,0);
                break;
            case 6:
                pWnd->HandleRButtonDown(&pt,0);
                pWnd->HandleRButtonHeld(&pt,0);
                break;
            case 7:
                pWnd->HandleRButtonDown(&pt,0);
                pWnd->HandleRButtonHeld(&pt,0);
                pWnd->HandleRButtonUpAfterHeld(&pt,0);
                break;
            default:
                return false;
            };
            gMouseEventTime = GetFastTime();
            return true;
        }
    }
    return false;
}

bool SendListSelect(PCHAR WindowName, PCHAR ScreenID, DWORD Value)
{
    CXWnd *pWnd=FindMQ2Window(WindowName);
    CXWnd *pParentWnd = 0;
    if (!pWnd)
    {
        MacroError("Window '%s' not available.",WindowName);
        return false;
    }
    if (ScreenID && ScreenID[0] && ScreenID[0]!='0')
    {
        CListWnd *pList=(CListWnd*)((CSidlScreenWnd*)(pWnd))->GetChildItem(ScreenID);
        if (!pList)
        {
            MacroError("Window '%s' child '%s' not found.",WindowName,ScreenID);
            return false;
        }
        if (((CXWnd*)pList)->GetType()==UI_Listbox)
        {
            pList->SetCurSel(Value);

            if(pParentWnd = GetParentWnd((CXWnd*)pList))
            {
                pParentWnd->WndNotification((CXWnd*)pList, XWM_LCLICK, (void*)Value);
            }

            gMouseEventTime = GetFastTime();
        }
        else if (((CXWnd*)pList)->GetType()==UI_Combobox)
        {
            ((CComboWnd*)pList)->SetChoice(Value);

            if(pParentWnd = GetParentWnd((CXWnd*)pList))
            {
                pParentWnd->WndNotification((CXWnd*)pList, XWM_LCLICK, (void*)Value);
            }
            
            gMouseEventTime = GetFastTime();
        }
        else
        {
            MacroError("Window '%s' child '%s' cannot accept this notification.",WindowName,ScreenID);
            return false;
        }
        return true;
    }
    return false;
}
bool SendTabSelect(PCHAR WindowName, PCHAR ScreenID, DWORD Value)
{
    CXWnd *pWnd=FindMQ2Window(WindowName);
    if (!pWnd)
    {
        MacroError("Window '%s' not available.",WindowName);
        return false;
    }
    if (ScreenID && ScreenID[0] && ScreenID[0]!='0')
    {
        CTabWnd *pTab = (CTabWnd*)((CSidlScreenWnd*)(pWnd))->GetChildItem(ScreenID);
        if (!pTab)
        {
            MacroError("Window '%s' child '%s' not found.",WindowName,ScreenID);
            return false;
        }
        if (((CXWnd*)pTab)->GetType()==UI_TabBox)
        {
            pTab->SetPage(Value, true);
            gMouseEventTime = GetFastTime();
        }
        else
        {
            MacroError("Window '%s' child '%s' cannot accept this notification.",WindowName,ScreenID);
            return false;
        }
        return true;
    }
    return false;
}
bool SendWndNotification(PCHAR WindowName, PCHAR ScreenID, DWORD Notification, VOID *Data)
{
    CHAR szOut[MAX_STRING] = {0};
    CXWnd *pWnd=FindMQ2Window(WindowName);
    if (!pWnd)
    {
        sprintf(szOut,"Window '%s' not available.",WindowName);
        WriteChatColor(szOut,USERCOLOR_DEFAULT);
        return false;
    }
    CXWnd *pButton=0;
    if (ScreenID && ScreenID[0])
    {
        pButton=((CSidlScreenWnd*)(pWnd))->GetChildItem(ScreenID);
        if (!pButton)
        {
            sprintf(szOut,"Window '%s' child '%s' not found.",WindowName,ScreenID);
            WriteChatColor(szOut,USERCOLOR_DEFAULT);
            return false;
        }
    }

    ((CXWnd*)(pWnd))->WndNotification(pButton,Notification,Data);
    gMouseEventTime = GetFastTime();

    return true;
}

void AddWindow(char *WindowName, CXWnd **ppWindow)
{
    string Name=WindowName;
    MakeLower(Name);

    unsigned long N=WindowMap[Name];
    if (N)
    {
        N--;
        _WindowInfo *pWnd = WindowList[N];
        pWnd->pWnd=0;
        pWnd->ppWnd=ppWindow;
        //DebugSpew("Updating WndNotification target '%s'",WindowName);
    }
    else
    {
        _WindowInfo *pWnd = new _WindowInfo;
        strcpy(pWnd->Name,WindowName);
        pWnd->pWnd=0;
        pWnd->ppWnd=ppWindow;

        N=WindowList.GetUnused();
        WindowList[N]=pWnd;

        WindowMap[WindowName]=N+1;
        //DebugSpew("Adding WndNotification target '%s'",Name);
    }

}

void RemoveWindow(char *WindowName)
{
    string Name=WindowName;
    MakeLower(Name);

    unsigned long N=WindowMap[Name];
    if (N)
    {
        N--;
        WindowMap[Name]=0;
        if (_WindowInfo *pInfo=WindowList[N])
        {
            delete pInfo;
            WindowList[N]=0;
        }
    }
}
#endif

#ifndef ISXEQ
#define RETURN(x) return;
#else
#define RETURN(x) return x;
#endif

CHAR tmpName[MAX_STRING]={0};
CHAR tmpAltName[MAX_STRING]={0};
CHAR tmpType[MAX_STRING]={0};

int RecurseAndListWindows(PCSIDLWND pWnd)
{
    int Count = 0;

    if (CXMLData *pXMLData=((CXWnd*)pWnd)->GetXMLData()) {
        Count++;
        GetCXStr(pXMLData->TypeName.Ptr,tmpType,MAX_STRING);
        GetCXStr(pXMLData->Name.Ptr,tmpName,MAX_STRING);
        GetCXStr(pXMLData->ScreenID.Ptr,tmpAltName,MAX_STRING);
        if (tmpAltName[0] && stricmp(tmpName,tmpAltName))
            WriteChatf("[\ay%s\ax] [\at%s\ax] [Custom UI-specific: \at%s\ax]",tmpType,tmpName,tmpAltName);
        else
            WriteChatf("[\ay%s\ax] [\at%s\ax]",tmpType,tmpName);
    }
    if (pWnd->pFirstChildWnd)
        Count += RecurseAndListWindows(pWnd->pFirstChildWnd);

    if (pWnd->pNextSiblingWnd)
        Count += RecurseAndListWindows(pWnd->pNextSiblingWnd);

    return Count;
}


#ifndef ISXEQ 
VOID ListWindows(PSPAWNINFO pChar, PCHAR szLine)
{
#else
int ListWindows(int argc, char *argv[])
{
    PCHAR szLine = NULL;
    if (argc>0)
        szLine = argv[1];

#endif 
    unsigned long Count=0;
    if (!szLine || !szLine[0])
    {
        WriteChatColor("List of available windows");
        WriteChatColor("-------------------------");
        for (unsigned long N = 0 ; N < WindowList.Size ; N++)
            if (_WindowInfo *pInfo=WindowList[N])
            {
                WriteChatf("%s",pInfo->Name);
                Count++;
            }
            WriteChatf("%d available windows",Count);
    }
    else
    {
        // list children of..
        string WindowName=szLine;
        MakeLower(WindowName);
        unsigned long N = WindowMap[WindowName];
        if (!N)
        {
            WriteChatf("Window '%s' not available",szLine);
            RETURN(0);
        }
        N--;
        WriteChatf("Listing child windows of '%s'",szLine);
        WriteChatColor("-------------------------");
        if (_WindowInfo *pInfo=WindowList[N])
        {
            PCSIDLWND pWnd= pInfo->pWnd->pFirstChildWnd;

            if (pWnd)
                Count = RecurseAndListWindows(pWnd);

            WriteChatf("%d child windows",Count);
        }
    }
    RETURN(0);
}

PCHAR szWndNotification[] = { 
    0,            //0 
    "leftmouse",    //1
    "leftmouseup",    //2
    "rightmouse",        //3
    0,        //4
    0,        //5
    "enter",        //6
    0,        //7
    0,        //8
    "help",        //9
    "close",        //10
    0,        //11
    0,        //12
    0,        //13
    "newvalue",        //14
    0,        //15
    0,        //16
    0,        //17
    0,        //18
    0,        //19
    "contextmenu",        //20
    "mouseover",    //21
    "history",        //22
    "leftmousehold",    //23
    0,        //24
    0,        //25
    0,        //26
    "link",        //27
    0,        //28
    "resetdefaultposition",        //29
}; 

#ifndef ISXEQ
VOID WndNotify(PSPAWNINFO pChar, PCHAR szLine)
{
#else
int WndNotify(int argc, char *argv[])
{
    PSPAWNINFO pChar = (PSPAWNINFO)pLocalPlayer;
#endif
    unsigned long Data=0;
#ifndef ISXEQ 
    CHAR szArg1[MAX_STRING] = {0}; 
    CHAR szArg2[MAX_STRING] = {0}; 
    CHAR szArg3[MAX_STRING] = {0}; 
    CHAR szArg4[MAX_STRING] = {0}; 

    GetArg(szArg1, szLine, 1);
    GetArg(szArg2, szLine, 2);
    GetArg(szArg3, szLine, 3);
    GetArg(szArg4, szLine, 4);

    if (!szArg3[0])
    {
        SyntaxError("Syntax: /notify <window|\"item\"> <control|0> <notification> [notification data]");
        return;
    }
    if (szArg4[0])
        Data=atoi(szArg4);
#else
    if (argc<3)
    {
        printf("%s syntax: %s <window|\"item\"> <control|0> <notification> [notification data]",argv[0],argv[0]);
        RETURN(0);
    }
    if (argc>4)
        Data=atoi(argv[4]);
    CHAR *szArg1=argv[1];
    CHAR *szArg2=argv[2];
    CHAR *szArg3=argv[3];
    CHAR *szArg4=argv[4];
#endif 

    if (!stricmp(szArg3,"link")) {
        DebugSpewAlways("WndNotify: link found, Data = 1");
        Data = 1;
    }

    if (Data==0 && SendWndClick(szArg1,szArg2,szArg3))
        RETURN(0);
    if (!stricmp(szArg3,"listselect"))
    {
        SendListSelect(szArg1,szArg2,Data-1);
        RETURN(0);
    }

    if (!stricmp(szArg3,"tabselect"))
    {
        SendTabSelect(szArg1,szArg2, Data-1);
        RETURN(0);
    } 

    for (unsigned long i = 0 ; i < sizeof(szWndNotification)/sizeof(szWndNotification[0]) ; i++)
    {
        if (szWndNotification[i] && !stricmp(szWndNotification[i],szArg3))
        {
            if (i==XWM_LINK) {
                if (!SendWndNotification(szArg1,szArg2,i,(void*)szArg4))
                {
                    MacroError("Could not send notification to %s %s",szArg1,szArg2);
                }
                RETURN(0);
            }
            if (szArg2[0]=='0')
            {
                if (!SendWndNotification(szArg1,0,i,(void*)Data))
                {
                    MacroError("Could not send notification to %s %s",szArg1,szArg2);
                }
            }
            else if (!SendWndNotification(szArg1,szArg2,i,(void*)Data))
            {
                MacroError("Could not send notification to %s %s",szArg1,szArg2);
            }
            RETURN(0);
        }
    }
    MacroError("Invalid notification '%s'",szArg3);
    RETURN(0);
}

// item slots:
// 2000-2015 bank window
// 2500-2501 shared bank
// 5000-5031 loot window
// 3000-30017 trade window (including npc) 3000-3007 are your slots, 3008-3015 are other character's slots
// 4000-4008 world container window
// 6000-6080 merchant window
// 7000-7080 bazaar window
// 8000-8031 inspect window


#ifndef ISXEQ
VOID ItemNotify(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szArg1[MAX_STRING] = {0}; 
    CHAR szArg2[MAX_STRING] = {0}; 
    CHAR szArg3[MAX_STRING] = {0};
    CHAR szArg4[MAX_STRING] = {0}; 

    GetArg(szArg1, szLine, 1);
    GetArg(szArg2, szLine, 2);
    GetArg(szArg3, szLine, 3);
    GetArg(szArg4, szLine, 4); 
    if (!szArg2[0])
    {
        WriteChatColor("Syntax: /itemnotify <slot|#> <notification>");
        WriteChatColor("     or /itemnotify in <bag slot> <slot # in bag> <notification>");
        RETURN(0);
    }

#else
int ItemNotify(int argc, char *argv[])
{
    if (argc!=3 && argc != 5)
    {
        //WriteChatf("ItemNotify got %d args", argc);
        WriteChatColor("Syntax: /itemnotify <slot|#> <notification>");
        WriteChatColor("     or /itemnotify in <bag slot> <slot # in bag> <notification>");
        RETURN(0);
    }
    char *szArg1=argv[1];
    char *szArg2=argv[2];
    char *szArg3="";
    char *szArg4="";

    if (argc==5)
    {
        szArg3=argv[3];
        szArg4=argv[4];
    }
    PSPAWNINFO pChar = (PSPAWNINFO)pLocalPlayer;
#endif
    PCHAR pNotification=&szArg2[0];
    EQINVSLOT *pSlot=NULL;
    DWORD i;
    PEQINVSLOTMGR pInvMgr=(PEQINVSLOTMGR)pInvSlotMgr;
    int bagslot = -1;
    int invslot = -1;
    int type = -1;

    if (!stricmp(szArg1,"in"))
    { 
        if (!szArg4[0])
        {
            WriteChatColor("Syntax: /itemnotify <slot|#> <notification>");
            WriteChatColor("     or /itemnotify in <bag slot> <slot # in bag> <notification>");
            RETURN(0);
        }

#if 0
        PCONTENTS pPack=0;
        PCONTENTS pItem=0;
        
        if (!strnicmp(szArg2,"bank",4))
        {
            unsigned long nPack=atoi(&szArg2[4]);
            if (nPack && nPack<=NUM_BANK_SLOTS)
            {
                pPack=GetCharInfo()->pBankArray->Bank[nPack-1];
            }
        }
        else if (!strnicmp(szArg2,"sharedbank",10))
        {
            unsigned long nPack=atoi(&szArg2[10]);
            if (nPack && nPack<=2)
            {
                pPack=GetCharInfo()->pSharedBankArray->SharedBank[nPack-1];
            }
        }
        else if (!strnicmp(szArg2,"pack",4))
        {
            unsigned long nPack=atoi(&szArg2[4]);
            if (nPack && nPack<=10)
            {
                pPack=GetCharInfo2()->pInventoryArray->Inventory.Pack[nPack-1];
            }
        }
        else if (!stricmp(szArg2,"enviro"))
        {
            pPack=((PEQ_CONTAINERWND_MANAGER)pContainerMgr)->pWorldContents;
        }

        if (!pPack)
        {
            WriteChatf("No item at '%s'",szArg2);
            RETURN(0);
        }
        if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK) {
            
            unsigned long N = atoi(szArg3)-1;

            if (N<GetItemFromContents(pPack)->Slots && pPack->pContentsArray) {
                pItem =  pPack->pContentsArray->Contents[N];
            }

            if (pItem) {
                unsigned long nSlot=FindInvSlotForContents(pItem);
                PEQINVSLOTMGR pInvMgr=(PEQINVSLOTMGR)pInvSlotMgr;
                pSlot = pInvMgr->SlotArray[nSlot];
            }
        }
#endif
        if (!strnicmp(szArg2,"bank",4)) {
            invslot=atoi(&szArg2[4])-1;
            bagslot=atoi(szArg3)-1;
            type=1;
        } else if (!strnicmp(szArg2,"sharedbank",10)) {
            invslot=atoi(&szArg2[10])-1;
            bagslot=atoi(szArg3)-1;
            type=2;
        } else if (!strnicmp(szArg2,"pack",4)) {
            invslot=atoi(&szArg2[4])-1+23;
            bagslot=atoi(szArg3)-1;
            type=0;
        }
        for (i=0;i<pInvMgr->TotalSlots;i++) {
            pSlot = pInvMgr->SlotArray[i];
            if ((pSlot->Valid) &&
                (pSlot->pInvSlotWnd->WindowType == type) &&
                (pSlot->pInvSlotWnd->InvSlotForBag == invslot) &&
                (pSlot->pInvSlotWnd->BagSlot == bagslot)) {
                break;
            }
        }
        if (i == pInvMgr->TotalSlots) pSlot = NULL;

        pNotification=&szArg4[0];
    } else {
        unsigned long Slot=atoi(szArg1);
        if (Slot==0)
        {
            Slot=ItemSlotMap[strlwr(szArg1)]; 
            if (Slot<NUM_INV_SLOTS) {
                DebugTry(pSlot=(EQINVSLOT *)pInvSlotMgr->FindInvSlot(Slot));
            } else {
                if (!strnicmp(szArg1, "loot", 4)) {
                    invslot = atoi(szArg1+4) - 1;
                    type = 11;
                } else if (!strnicmp(szArg1, "enviro", 6)) {
                    invslot = atoi(szArg1+6) - 1;
                    type = 4;
                } else if (!strnicmp(szArg1, "pack", 4)) {
                    invslot = atoi(szArg1+4) - 1 + 23;
                    type = 0;
                } else if (!strnicmp(szArg1, "bank", 4)) {
                    invslot = atoi(szArg1+4) - 1;
                    type = 1;
                } else if (!strnicmp(szArg1, "sharedbank", 10)) {
                    invslot = atoi(szArg1+10) - 1;
                    type = 2;
                } else if (!strnicmp(szArg1, "trade", 5)) {
                    invslot = atoi(szArg1+5) - 1;
                    type = 3;
                }
                for (i=0;i<pInvMgr->TotalSlots;i++) {
                    pSlot = pInvMgr->SlotArray[i];
                    if ((pSlot->Valid) &&
                        (pSlot->pInvSlotWnd->WindowType == type) &&
                        (pSlot->pInvSlotWnd->InvSlotForBag == invslot)) {
                        Slot = 1;
                        break;
                    }
                }
                if (i == pInvMgr->TotalSlots) Slot = 0;
            }
        }
        if (Slot==0 && szArg1[0]!='0' && stricmp(szArg1,"charm"))
        {
            WriteChatf("Invalid item slot '%s'",szArg1);
            RETURN(0);
        } else if (Slot && !pSlot) {
            pSlot = pInvMgr->SlotArray[Slot];
        }
    }
    if (!pSlot)
    {
        WriteChatf("SLOT IS NULL: Could not send notification to %s %s",szArg1,szArg2);
        RETURN(0);
    }
    DebugSpew("ItemNotify: Calling SendWndClick");
    if (!pSlot->pInvSlotWnd || !SendWndClick2((CXWnd*)pSlot->pInvSlotWnd,pNotification))
    {
        WriteChatf("Could not send notification to %s %s",szArg1,szArg2);
    }
    RETURN(0);
}

#ifndef ISXEQ
VOID ListItemSlots(PSPAWNINFO pChar, PCHAR szLine)
#else
int ListItemSlots(int argc, char *argv[])
#endif
{
    PEQINVSLOTMGR pMgr=(PEQINVSLOTMGR)pInvSlotMgr;
    if (!pMgr)
        RETURN(0);
    //CHAR szOut[MAX_STRING]={0};
    unsigned long Count=0;
    WriteChatColor("List of available item slots");
    WriteChatColor("-------------------------");
    for (unsigned long N = 0 ; N < 0x800 ; N++)
        if (PEQINVSLOT pSlot=pMgr->SlotArray[N])
        {
            if (pSlot->pInvSlotWnd)
            {
                WriteChatf("%d %d %d", N, pSlot->pInvSlotWnd->WindowType, pSlot->InvSlot);
                Count++;
            } else if (pSlot->InvSlot) {
                WriteChatf("%d %d", N, pSlot->InvSlot);
            }
        }
        WriteChatf("%d available item slots",Count);
        RETURN(0)
}
