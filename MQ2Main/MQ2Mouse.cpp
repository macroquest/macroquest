/***************************************************************************** 
MQ2Main.dll: MacroQuest2's extension DLL for EverQuest 
Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

This program is free software; you can redistribute it and/or modify 
it under the terms of the GNU General Public License, version 2, as published by 
the Free Software Foundation. 

This program is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
GNU General Public License for more details. 
******************************************************************************/ 

#if !defined(CINTERFACE) 
#error /DCINTERFACE 
#endif 

#define DBG_SPEW 


#include "MQ2Main.h" 


// *************************************************************************** 
// Function: ParseMouseLoc 
// Description: Parses mouseloc for /click and /mouseto 
// *************************************************************************** 
//Function used by ParseLocationXML to extract parameter
// ExtractValue - gets value between specified start and end markers
// - Parameters:
// szFile - pointer to tring to look in
// szStart - pointer to string to mark start of value
// szEnd - pointer to string to mark end of value
// szValue - pointer to string to contain the value found
// - Return Value:
// if successful, return TRUE, szValue contains the value between the start and end markers
// if unsuccessful, return FALSE
BOOL ExtractValue(PCHAR szFile, PCHAR szStart, PCHAR szEnd, PCHAR szValue)
{
    // verify we have legal pointers passed to us
    if (!szValue)
        return FALSE;

    if (!szFile || !szStart || !szEnd)
    {
        szValue[0] = 0;
        return FALSE;
    }

    PCHAR sub,sub2,fence;
    DWORD lenStart = strlen(szStart);

    fence = strstr(szFile,"ScreenID"); // needed to make sure we don't start into another element

    sub = strstr(szFile, szStart); 
    sub2 = strstr(szFile, szEnd); 
    if (!sub || !sub2 || (fence && (sub > fence))) {
        szValue[0] = 0;
        return FALSE;
    }

    memcpy(szValue,sub + lenStart, (sub2-sub) - lenStart);
    szValue[(sub2-sub) - lenStart] = 0;
    DebugSpew("Value extracted for %s was %s",szStart,szValue);
    return TRUE;
}

#ifndef ISXEQ

// TODO: Expand this to support mouse buttons 3->8
VOID ClickMouse(DWORD button)
{
   if (button > 1)
      return;
   DWORD mdType = (DWORD)MD_Button0 + button;

   if (!((EQADDR_MOUSECLICK->Click[button] == 0x80) && (!EQADDR_MOUSECLICK->Confirm[button])))
      EQADDR_MOUSECLICK->Click[button] = 0x80;

   gMouseClickInProgress[button] = TRUE;

   gMouseEventTime = GetFastTime();
   PMOUSESPOOF pData = (PMOUSESPOOF)malloc(sizeof(MOUSESPOOF));
   pData->mdType = (MOUSE_DATA_TYPES)mdType;
   pData->dwData = 0x00;
   pData->pNext = NULL;
   if (!gMouseData) {
      gMouseData = pData;
   } else {
      PMOUSESPOOF pTemp = gMouseData;
      while (pTemp->pNext) {
         pTemp = pTemp->pNext;
      }
      pTemp->pNext = pData;
   }
}

VOID MouseButtonUp(DWORD x, DWORD y, PCHAR szButton)
{
    float c[3];
    gLClickedObject=false;
    
    if(!strnicmp(szButton,"left",4))
    {
        // click will fail if this isn't set to a time less than TimeStamp minus 750ms
        *((DWORD*)__LMouseHeldTime)=((PCDISPLAY)pDisplay)->TimeStamp-0x45;
        pEverQuest->LMouseUp(x,y);

        if(((CDisplay*)pDisplay)->GetClickedActor(x,y,0,&c,&c))
        {
            gLClickedObject=true;
            EnviroTarget.Name[0]=0;
        }
    }

    /* i don't think there's any use for this currently - ieatacid
    else if(!strnicmp(szButton,"right",5))
    {
        // click will fail if this isn't set to a time less than TimeStamp minus 500ms
        *((DWORD*)__RMouseHeldTime)=((PCDISPLAY)pDisplay)->TimeStamp-0x45;
        pEverQuest->RMouseUp(x,y);
    }*/
}

VOID ClickMouseLoc(PCHAR szMouseLoc, PCHAR szButton) 
{
    CHAR szArg1[MAX_STRING] = {0};
    CHAR szArg2[MAX_STRING] = {0};
    int ClickX; //actual location to click, calculated from ButtonX 
    int ClickY; //actual location to click, calculated from ButtonY 

    // determine mouse location - x and y given
    if ((szMouseLoc[0]=='+') || (szMouseLoc[0]=='-') || ((szMouseLoc[0]>='0') && (szMouseLoc[0]<='9')))
    { // x and y were given so lets convert them and move mouse
        GetArg(szArg1,szMouseLoc,1);
        GetArg(szArg2,szMouseLoc,2);
        ClickX = atoi(szArg1);
        ClickY = atoi(szArg2);
        if ((szArg1[0]=='+') || (szArg1[0]=='-') || (szArg2[0]=='+') || (szArg2[0]=='-'))
        { // relative location was passed so offset from current
            ClickX += EQADDR_MOUSE->X;
            ClickY += EQADDR_MOUSE->Y;
            DebugSpew("Clicking mouse by relative offset");
        } else {
            DebugSpew("Clicking mouse at absolute position");
        }
        MouseButtonUp(ClickX,ClickY,szButton);
    }
    else
    {
        MacroError("'%s' mouse click is either invalid or should be done using /notify",szMouseLoc);
    }
}
#endif

#ifndef ISXEQ_LEGACY

// *************************************************************************** 
// Function: Click 
// Description: Our '/click' command 
// Clicks the mouse button (calls EQ's mouse up commands) 
// Usage: /click left|right [<mouseloc>] 
// *************************************************************************** 
BOOL IsMouseWaitingForButton()
{
    return ((EQADDR_MOUSECLICK->Click[1] == EQADDR_MOUSECLICK->Confirm[1])
        && (EQADDR_MOUSECLICK->Click[0] == EQADDR_MOUSECLICK->Confirm[0])) ? FALSE : TRUE;
}

BOOL IsMouseWaiting()
{
    BOOL Result = FALSE;

    if (IsMouseWaitingForButton()) Result = TRUE;
    else {
        // Here we basically force the MQ script engine to wait for the button up on mouse clicks

        if (gMouseClickInProgress[0]) {
            //SetMouseButtonUpL();
            if (!((!EQADDR_MOUSECLICK->Click[0]) && (EQADDR_MOUSECLICK->Confirm[0] == 0x80))) EQADDR_MOUSECLICK->Click[0] = 0x0;
            gMouseClickInProgress[0] = FALSE;
            Result = TRUE;
        }
        if (gMouseClickInProgress[1]) {
            //SetMouseButtonUpR();
            if (!((!EQADDR_MOUSECLICK->Click[1]) && (EQADDR_MOUSECLICK->Confirm[1] == 0x80))) EQADDR_MOUSECLICK->Click[1] = 0x0;
            gMouseClickInProgress[1] = FALSE;
            Result = TRUE;
        }
    }
    return Result;
}
#endif

#ifndef ISXEQ

VOID Click(PSPAWNINFO pChar, PCHAR szLine) 
{ 
    CHAR szArg1[MAX_STRING] = {0}; 
    PCHAR szMouseLoc; 
    MOUSE_DATA_TYPES mdType = MD_Unknown; 
    DWORD RightOrLeft = 0; 

    GetArg(szArg1, szLine, 1); //left or right 
    szMouseLoc = GetNextArg(szLine, 1); //location to click 

    //parse location for click location (szMouseLoc) here 
    if (szMouseLoc && szMouseLoc[0]!=0) { 
        if (!strnicmp(szMouseLoc, "target", 6)) {
            if (!pTarget) { 
                WriteChatColor("You must have a target selected for /click x target.",CONCOLOR_RED); 
                return; 
            } 
            if (!strnicmp(szArg1, "left", 4)) { 
                pEverQuest->LeftClickedOnPlayer(pTarget); 
                gMouseEventTime = GetFastTime();
            } else if (!strnicmp(szArg1, "right", 5)) { 
                pEverQuest->RightClickedOnPlayer(pTarget, 0); 
                gMouseEventTime = GetFastTime();
            } 
            return;
        }
        else if(!strnicmp(szMouseLoc,"center",6))
        {
            sprintf(szMouseLoc,"%d %d",ScreenXMax/2,ScreenYMax/2);
        }
        ClickMouseLoc(szMouseLoc, szArg1);
        return;
    }

    if (szArg1[0]!=0) { 
        if (!strnicmp(szArg1, "left", 4)) { 
            ClickMouse(0);
        } else if (!strnicmp(szArg1, "right", 5)) { 
            ClickMouse(1);
        } else { 
            WriteChatColor("Usage: /click <left|right>",USERCOLOR_DEFAULT); 
            DebugSpew("Bad command: %s",szLine); 
            return; 
        } 
    } 
}

#endif
