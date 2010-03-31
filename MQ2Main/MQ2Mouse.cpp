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

BOOL MoveMouse(DWORD x, DWORD y) 
{ 
	if (EQADDR_MOUSE) {
		EQADDR_MOUSE->X = x; 
		EQADDR_MOUSE->Y = y; 
		DebugSpew("Moved mouse to: %d,%d", x, y); 
		return TRUE;
	}
	return FALSE;
} 

#ifndef ISXEQ

BOOL ParseMouseLoc(PCHARINFO pCharInfo, PCHAR szMouseLoc) 
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
			DebugSpew("Moving mouse by relative offset");
		} else {
			DebugSpew("Moving mouse to absolute position");
		}
		return MoveMouse(ClickX,ClickY);
		
	}
	MacroError("'%s' mouse click is either invalid or should be done using /notify",szMouseLoc);
	return FALSE;
}
#endif
VOID SendEQMessage(DWORD PacketType, PVOID pData, DWORD Length)
{
	if (!send_message || !EQADDR_GWORLD) 
	{
		return;
	}
	send_message(EQADDR_GWORLD,PacketType,pData,Length,TRUE);
}


// *************************************************************************** 
// Function: Click 
// Description: Our '/click' command 
// Clicks the mouse button (calls EQ's mouse up commands) 
// Usage: /click left|right [<mouseloc>] 
// *************************************************************************** 
BOOL IsMouseWaitingForButton()
{
	return ((EQADDR_MOUSECLICK->RightClick == EQADDR_MOUSECLICK->ConfirmRightClick) 
		&& (EQADDR_MOUSECLICK->LeftClick == EQADDR_MOUSECLICK->ConfirmLeftClick)) ? FALSE : TRUE;
}

BOOL IsMouseWaiting()
{
	BOOL Result = FALSE;

	if (IsMouseWaitingForButton()) Result = TRUE;
	else {
		// Here we basically force the MQ script engine to wait for the button up on mouse clicks

		if (gMouseLeftClickInProgress) {
			//SetMouseButtonUpL();
			if (!((!EQADDR_MOUSECLICK->LeftClick) && (EQADDR_MOUSECLICK->ConfirmLeftClick == 0x80))) EQADDR_MOUSECLICK->LeftClick = 0x0;
			gMouseLeftClickInProgress = FALSE;
			Result = TRUE;
		}
		if (gMouseRightClickInProgress) {
			//SetMouseButtonUpR();
			if (!((!EQADDR_MOUSECLICK->RightClick) && (EQADDR_MOUSECLICK->ConfirmRightClick == 0x80))) EQADDR_MOUSECLICK->RightClick = 0x0;
			gMouseRightClickInProgress = FALSE;
			Result = TRUE;
		}
		
	}
	return Result;
}
#ifndef ISXEQ

VOID Click(PSPAWNINFO pChar, PCHAR szLine) { 
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
         } else if (!strnicmp(szArg1, "right", 5)) { 
          pEverQuest->RightClickedOnPlayer(pTarget); 
         } 
         return; 
	  } else if (!strnicmp(szMouseLoc, "item", 4)) {
			// a right clicked ground spawn does nothing
			if (!strnicmp(szArg1, "left", 4) && EnviroTarget.Name[0]!=0 && DistanceToSpawn(pChar,&EnviroTarget)<20.0f) {
				INTERACTGROUNDITEM Data;
				Data.SpawnID = GetCharInfo()->pSpawn->SpawnID;
				Data.DropID = EnviroTarget.Race;
				SendEQMessage(EQ_INTERACTGROUNDITEM,&Data,sizeof(INTERACTGROUNDITEM));
				EnviroTarget.Name[0]=0;
				if (pTarget==(EQPlayer*)&EnviroTarget) pTarget=NULL;
				return;
			}
      } else if (!ParseMouseLoc(GetCharInfo(), szMouseLoc)) { 
         DebugSpew("Invalid mouse loc to click, aborting: %s",szMouseLoc); 
         return; 
      } 
   } 
    
   if (szArg1[0]!=0) { 
      if (!strnicmp(szArg1, "left", 4)) { 
         mdType = MD_Button0; 
		 if (!((EQADDR_MOUSECLICK->LeftClick == 0x80) && (!EQADDR_MOUSECLICK->ConfirmLeftClick))) EQADDR_MOUSECLICK->LeftClick = 0x80;
         gMouseLeftClickInProgress = TRUE; 
      } else if (!strnicmp(szArg1, "right", 5)) { 
         mdType = MD_Button1;
		 if (!((EQADDR_MOUSECLICK->RightClick == 0x80) && (!EQADDR_MOUSECLICK->ConfirmRightClick))) EQADDR_MOUSECLICK->RightClick = 0x80;
         gMouseRightClickInProgress = TRUE;
        } else { 
           WriteChatColor("Usage: /click <left|right>",USERCOLOR_DEFAULT); 
           DebugSpew("Bad command: %s",szLine); 
           return; 
        } 
        PMOUSESPOOF pData = (PMOUSESPOOF)malloc(sizeof(MOUSESPOOF)); 
        pData->mdType = mdType; 
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
}


// *************************************************************************** 
// Function: MouseTo 
// Description: Our '/mouseto' command 
// Moves the mouse 
// Usage: /mouseto <mouseloc>
// *************************************************************************** 
VOID MouseTo(PSPAWNINFO pChar, PCHAR szLine) 
{
	if (szLine && szLine[0])
		if (ParseMouseLoc(GetCharInfo(), szLine))
			return;

	WriteChatColor("Usage: /mouseto <mouseloc>",USERCOLOR_DEFAULT); 
	DebugSpew("Help invoked or Bad MouseTo command: %s",szLine); 
}
#endif